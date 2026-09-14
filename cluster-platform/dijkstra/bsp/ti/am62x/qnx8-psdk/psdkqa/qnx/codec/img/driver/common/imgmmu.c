/*****************************************************************************
*
* Copyright (c) Imagination Technologies Ltd.
* Copyright (c) 2018-22 Texas Instruments Incorporated - http://www.ti.com/
*
* The contents of this file are subject to the MIT license as set out below.
*
* Permission is hereby granted, free of charge, to any person obtaining a
* copy of this software and associated documentation files (the "Software"),
* to deal in the Software without restriction, including without limitation
* the rights to use, copy, modify, merge, publish, distribute, sublicense,
* and/or sell copies of the Software, and to permit persons to whom the
* Software is furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHERa
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*
* Alternatively, the contents of this file may be used under the terms of the
* GNU General Public License Version 2 ("GPL")in which case the provisions of
* GPL are applicable instead of those above.
*
* If you wish to allow use of your version of this file only under the terms
* of GPL, and not to allow others to use your version of this file under the
* terms of the MIT license, indicate your decision by deleting the provisions
* above and replace them with the notice and other provisions required by GPL
* as set out in the file called "GPLHEADER" included in this distribution. If
* you do not delete the provisions above, a recipient may use your version of
* this file under the terms of either the MIT license or GPL.
*
* This License is also included in this distribution in the file called
* "MIT_COPYING".
*
*****************************************************************************/
/*
 * IMG DEC MMU function implementations
 */

#include "osal/inc/osa_mem.h"
#include "osal/inc/osa_err.h"
#include "osal/inc/osa_page.h"
#include "osal/inc/osa_define.h"
#include "imgmmu.h"


/*
 * struct mmu_directory - the MMU directory information
 * @dir_page: pointer to the mmu_page_cfg_table (physical table used) which
 *	      this mmu_directory belongs to
 * @dir_page_table: All the page table structures in a static array of pointers
 * @mmu_info_cfg: Functions to use to manage pages allocation, liberation and
 *		  writing
 * @num_mapping: number of mapping using this directory
 */
struct mmu_directory {
	struct mmu_page_cfg *dir_page;
	struct mmu_page_cfg_table **dir_page_table;
	struct mmu_info mmu_info_cfg;
	uint32 num_mapping;
};

/*
 * struct mmu_map - the MMU mapping information
 * @mmu_dir: pointer to the mmu_directory which this mmu_map belongs to
 * @dev_virt_addr: device virtual address root associated with this mapping
 * @used_flag: flag used when allocating
 * @n_entries: number of entries mapped
 */
struct mmu_map {
	struct mmu_directory *mmu_dir;
	struct mmu_heap_alloc dev_virt_addr;
	uint32 used_flag;
	uint32 n_entries;
};

/*
 * struct mmu_page_cfg_table - the MMU page table information.
 *			       One page table of the directory.
 * @mmu_dir: pointer to the mmu_directory which this mmu_page_cfg_table
 *	     belongs to
 * @page: page used to store this mapping in the MMU
 * @valid_entries: number of valid entries in this page
 */
struct mmu_page_cfg_table {
	struct mmu_directory *mmu_dir;
	struct mmu_page_cfg *page;
	uint32 valid_entries;
};

/*
 * mmu_pgt_destroy() - Destruction of a page table (does not follow the
 *                     child pointer)
 * @pgt: pointer to the MMU page table information
 *
 * Warning: Does not verify if pages are still valid or not
 */
static void mmu_pgt_destroy(struct mmu_page_cfg_table *pgt)
{
	if (!pgt->mmu_dir ||
	    !pgt->mmu_dir->mmu_info_cfg.pfn_page_free ||
	    !pgt->page) {
		return;
	}

	OSA_PR_DEBUG("%s:%d Destroy page table (phys addr %llu)\n",
		 __func__, __LINE__, pgt->page->phys_addr);

	pgt->mmu_dir->mmu_info_cfg.pfn_page_free(pgt->page);
	pgt->page = NULL;

	osa_free(pgt);
}

/*
 * mmu_dir_entry() - Extact the directory index from a virtual address
 * @vaddr: virtual address
 */
static inline uint32 mmu_dir_entry(uintptr_t vaddr)
{
	return (uint32)((vaddr & VIRT_DIR_IDX_MASK) >> MMU_DIR_SHIFT);
}

/*
 * mmu_pg_entry() - Extract the page table index from a virtual address
 * @vaddr: virtual address
 */
static inline uint32 mmu_pg_entry(uintptr_t vaddr)
{
	return (uint32)((vaddr & VIRT_PAGE_TBL_MASK) >> MMU_PAGE_SHIFT);
}

/*
 * mmu_pg_wr() - Default function used when a mmu_info structure has an empty
 *		 pfn_page_write pointer
 * @mmu_page: pointer to the mmu_page to update
 * @offset: offset into the directory
 * @pa_to_write: physical address value to add to the entr
 * @mmu_flag: mmu flag(s) to set
 */
static void mmu_pg_wr(struct mmu_page_cfg *mmu_page, uint32 offset,
		      uint64 pa_to_write, uint32 mmu_flag)
{
	uint32 *dir_mem = NULL;
	uint64 cur_pa = pa_to_write;

	if (!mmu_page)
		return;

	dir_mem = (uint32 *)mmu_page->cpu_virt_addr;
	/*
	 * assumes that the MMU HW has the extra-bits enabled (this default
	 * function has no way of knowing)
	 */
	if ((MMU_PHYS_SIZE - MMU_VIRT_SIZE) > 0)
		cur_pa >>= (MMU_PHYS_SIZE - MMU_VIRT_SIZE);
	/*
	 * The MMU_PAGE_SHIFT bottom bits should be masked because page
	 * allocation.
	 * MMU_PAGE_SHIFT-(MMU_PHYS_SIZE-MMU_VIRT_SIZE) are used for
	 * flags so it's ok
	 */
	dir_mem[offset] = (uint32)cur_pa | (mmu_flag);
}

/*
 * mmu_page_cfg_table() - Create a page table
 * @mmu_dir: pointer to the mmu_directory in which to create the new page table
 *	     structure
 *
 * Return: A pointer to the new page table structure in case of success.
 *	   OSA_ERR_PTR in case of error
 */
static struct mmu_page_cfg_table *mmu_pgt_create(struct mmu_directory *mmu_dir)
{
	struct mmu_page_cfg_table *neo = NULL;
	uint32 i;

	if (!mmu_dir || !mmu_dir->mmu_info_cfg.pfn_page_alloc ||
	    !mmu_dir->mmu_info_cfg.pfn_page_write)
		return OSA_ERR_PTR(-OSA_EINVAL);

	neo = osa_malloc(sizeof(*neo), OSA_GFP_KERNEL);
	if (!neo)
		return OSA_ERR_PTR(-OSA_ENOMEM);

	neo->mmu_dir = mmu_dir;

	neo->page =
		mmu_dir->mmu_info_cfg.pfn_page_alloc(mmu_dir->mmu_info_cfg.alloc_ctx);
	if (!neo->page) {
		OSA_PR_ERR("%s:%d failed to allocate Page Table physical page\n",
		       __func__, __LINE__);
		osa_free(neo);
		return OSA_ERR_PTR(-OSA_ENOMEM);
	}
	OSA_PR_DEBUG("%s:%d Create page table (phys addr 0x%llx CPU Virt 0x%lx)\n",
		 __func__, __LINE__, neo->page->phys_addr,
		 neo->page->cpu_virt_addr);

	/* invalidate all pages */
	for (i = 0; i < MMU_N_PAGE; i++) {
		mmu_dir->mmu_info_cfg.pfn_page_write(neo->page, i, 0,
							MMU_FLAG_INVALID);
	}

	/*
	 * When non-UMA need to update the device memory after setting
	 * it to 0
	 */
	if (mmu_dir->mmu_info_cfg.pfn_page_update)
		mmu_dir->mmu_info_cfg.pfn_page_update(neo->page);

	return neo;
}

/*
 * mmu_create_directory - Create a directory entry based on a given directory
 *			  configuration
 * @mmu_info_ops: contains the functions to use to manage page table memory.
 *		  Is copied and not modified.
 *
 * @warning Obviously creation of the directory allocates memory - do not call
 * while interrupts are disabled
 *
 * @return The opaque handle to the mmu_directory object and result to 0
 * @return OSA_ERR_PTR in case of an error and result has the value:
 * @li -OSA_EINVAL if mmu_info configuration is NULL or does not
 * contain function pointers
 * @li -OSA_ENOMEM if an internal allocation failed
 * @li -OSA_ENOMEM if the given mmu_pfn_page_alloc returned NULL
 */
struct mmu_directory *mmu_create_directory(const struct mmu_info *mmu_info_ops)
{
	struct mmu_directory *neo = NULL;
	uint32 i;

	/*
	 * invalid information in the directory config:
	 * - invalid page allocator and dealloc (page write can be NULL)
	 * - invalid virtual address representation
	 * - invalid page size
	 * - invalid MMU size
	 */
	if (!mmu_info_ops || !mmu_info_ops->pfn_page_alloc ||
	    !mmu_info_ops->pfn_page_free) {
		OSA_PR_ERR("%s:%d invalid MMU configuration\n", __func__, __LINE__);
		return OSA_ERR_PTR(-OSA_EINVAL);
	}

	neo = osa_zalloc(sizeof(*neo), OSA_GFP_KERNEL);
	if (!neo)
		return OSA_ERR_PTR(-OSA_ENOMEM);

	neo->dir_page_table = osa_calloc(MMU_N_TABLE,
				      sizeof(struct mmu_page_cfg_table *),
				      OSA_GFP_KERNEL);
	if (!neo->dir_page_table) {
		osa_free(neo);
		return OSA_ERR_PTR(-OSA_ENOMEM);
	}

	memcpy(&neo->mmu_info_cfg, mmu_info_ops, sizeof(struct mmu_info));
	if (!mmu_info_ops->pfn_page_write) {
		OSA_PR_DEBUG("%s:%d using default MMU write\n", __func__, __LINE__);
		/* use internal function */
		neo->mmu_info_cfg.pfn_page_write = &mmu_pg_wr;
	}

	neo->dir_page = mmu_info_ops->pfn_page_alloc(mmu_info_ops->alloc_ctx);
	if (!neo->dir_page) {
		osa_free(neo->dir_page_table);
		osa_free(neo);
		return OSA_ERR_PTR(-OSA_ENOMEM);
	}

	OSA_PR_DEBUG("%s:%d (phys page 0x%llx; CPU virt 0x%lx)\n", __func__,
		 __LINE__, neo->dir_page->phys_addr,
		 neo->dir_page->cpu_virt_addr);
	/* now we have a valid mmu_directory structure */

	/* invalidate all entries */
	for (i = 0; i < MMU_N_TABLE; i++) {
		neo->mmu_info_cfg.pfn_page_write(neo->dir_page, i, 0,
						  MMU_FLAG_INVALID);
	}

	/* when non-UMA need to update the device memory */
	if (neo->mmu_info_cfg.pfn_page_update)
		neo->mmu_info_cfg.pfn_page_update(neo->dir_page);

	return neo;
}

/*
 * mmu_destroy_directory - Destroy the mmu_directory - assumes that the HW is
 *			   not going to access the memory any-more
 * @mmu_dir: pointer to the mmu directory to destroy
 *
 * Does not invalidate any memory because it assumes that everything is not
 * used any-more
 */
int32 mmu_destroy_directory(struct mmu_directory *mmu_dir)
{
	uint32 i;

	if (!mmu_dir) {
		/* could be an assert */
		OSA_PR_ERR("%s:%d mmu_dir is NULL\n", __func__, __LINE__);
		return -OSA_EINVAL;
	}

	if (mmu_dir->num_mapping > 0)
		/* mappings should have been destroyed! */
		OSA_PR_ERR("%s:%d directory still has %u mapping attached to it\n",
		       __func__, __LINE__, mmu_dir->num_mapping);
		/*
		 * not exiting because clearing the page table map is more
		 * important than losing a few structures
		 */

	if (!mmu_dir->mmu_info_cfg.pfn_page_free || !mmu_dir->dir_page_table)
		return -OSA_EINVAL;

	OSA_PR_DEBUG("%s:%d destroy MMU dir (phys page 0x%llx)\n",
		 __func__, __LINE__, mmu_dir->dir_page->phys_addr);

	/* first we destroy the directory entry */
	mmu_dir->mmu_info_cfg.pfn_page_free(mmu_dir->dir_page);
	mmu_dir->dir_page = NULL;

	/* destroy every mapping that still exists */
	for (i = 0; i < MMU_N_TABLE; i++) {
		if (mmu_dir->dir_page_table[i]) {
			mmu_pgt_destroy(mmu_dir->dir_page_table[i]);
			mmu_dir->dir_page_table[i] = NULL;
		}
	}

	osa_free(mmu_dir->dir_page_table);
	osa_free(mmu_dir);
	return 0;
}

/*
 * mmu_directory_get_page - Get access to the page table structure used in the
 *			    directory (to be able to write it to registers)
 * @mmu_dir: pointer to the mmu directory. asserts if mmu_dir is NULL
 *
 * @return the page table structure used
 */
struct mmu_page_cfg *mmu_directory_get_page(struct mmu_directory *mmu_dir)
{
	if (!mmu_dir)
		return NULL;

	return mmu_dir->dir_page;
}

static struct mmu_map *mmu_directory_map(struct mmu_directory *mmu_dir,
					 const struct mmu_heap_alloc *dev_va,
					 uint32 uiMapFlags,
					 int32 (*phys_iter_next)(void *arg,
							       uint64 *next),
					 void *phys_iter_arg)
{
	uint32 first_dir = 0;
	uint32 first_pg = 0;
	uint32 dir_off = 0;
	uint32 pg_off = 0;
	uint32 n_entries = 0;
	uint32 i;
	uint32 d;
	const uint32 duplicate = OSA_PAGE_SIZE / mmu_get_page_size();
	int32 res = 0;
	struct mmu_map *neo = NULL;
	struct mmu_page_cfg_table **dir_pgtbl = NULL;

	/*
	 * in non UMA updates on pages needs to be done - store index of
	 * directory entry pages to update
	 */
	uint32 *to_update;
	/*
	 * number of pages in to_update (will be at least 1 for the first_pg to
	 * update)
	 */
	uint32 n_pgs_to_update = 0;
	/*
	 * to know if we also need to update the directory page (creation of new
	 * page)
	 */
	uint8 dir_modified = osa_false;

	if (!mmu_dir || !dev_va || duplicate < 1)
		return OSA_ERR_PTR(-OSA_EINVAL);

	dir_pgtbl = mmu_dir->dir_page_table;

	n_entries = dev_va->alloc_size / OSA_PAGE_SIZE;
	if (dev_va->alloc_size % MMU_PAGE_SIZE != 0 || n_entries == 0) {
		OSA_PR_ERR("%s:%d invalid allocation size\n", __func__, __LINE__);
		return OSA_ERR_PTR(-OSA_EINVAL);
	}

	if ((uiMapFlags & MMU_FLAG_VALID) != 0) {
		OSA_PR_ERR("%s:%d valid flag (0x%x) is set in the falgs 0x%x\n",
		       __func__, __LINE__, MMU_FLAG_VALID, uiMapFlags);
		return OSA_ERR_PTR(-OSA_EINVAL);
	}

	/*
	 * has to be dynamically allocated because it is bigger than 1k (max
	 * stack in the kernel)
	 * MMU_N_TABLE is 1024 for 4096B pages, that's a 4k allocation (1 page)
	 *  - if it gets bigger may IMG_BIGALLOC should be used
	 */
	to_update = osa_calloc(MMU_N_TABLE, sizeof(uint32), OSA_GFP_KERNEL);
	if (!to_update)
		return OSA_ERR_PTR(-OSA_ENOMEM);

	/* manage multiple page table mapping */

	first_dir = mmu_dir_entry(dev_va->virt_addr);
	first_pg = mmu_pg_entry(dev_va->virt_addr);

	if (first_dir >= MMU_N_TABLE || first_pg >= MMU_N_PAGE) {
		osa_free(to_update);
		return OSA_ERR_PTR(-OSA_EINVAL);
	}

	/* verify that the pages that should be used are available */
	dir_off = first_dir;
	pg_off = first_pg;

	/*
	 * loop over the number of entries given by CPU allocator but CPU page
	 * size can be > than MMU page size therefore it may need to "duplicate"
	 * entries by creating a fake physical address
	 */
	for (i = 0; i < n_entries * duplicate; i++) {
		if (pg_off >= MMU_N_PAGE) {
			dir_off++; /* move to next directory */
			if (dir_off >= MMU_N_TABLE) {
				res = -OSA_EINVAL;
				break;
			}
			pg_off = 0; /* using its first page */
		}

		/*
		 * if dir_pgtbl[dir_off] == NULL not yet
		 * allocated it means all entries are available
		 */
		if (dir_pgtbl[dir_off]) {
			/*
			 * inside a pagetable - verify that the required offset
			 * is invalid
			 */
			struct mmu_page_cfg_table *tbl = dir_pgtbl[dir_off];
			uint32 *page_mem = (uint32 *)tbl->page->cpu_virt_addr;

			if ((page_mem[pg_off] & MMU_FLAG_VALID) != 0) {
				OSA_PR_ERR("%s:%d one of the required page is currently in use\n",
				       __func__, __LINE__);
				res = -OSA_EPERM;
				break;
			}
		}
		/* PageTable struct exists */
		pg_off++;
	} /* for all needed entries */

	/* it means one entry was not invalid or not enough page were given */
	if (res != 0) {
		/*
		 * message already printed
		 * IMG_ERROR_MEMORY_IN_USE when an entry is not invalid
		 * IMG_ERROR_INVALID_PARAMETERS when not enough pages are given
		 *  (or too much)
		 */
		osa_free(to_update);
		return OSA_ERR_PTR(res);
	}

	neo = osa_malloc(sizeof(*neo), OSA_GFP_KERNEL);
	if (!neo) {
		osa_free(to_update);
		return OSA_ERR_PTR(-OSA_ENOMEM);
	}
	neo->mmu_dir = mmu_dir;
	neo->dev_virt_addr = *dev_va;
	memcpy(&neo->dev_virt_addr, dev_va, sizeof(struct mmu_heap_alloc));
	neo->used_flag = uiMapFlags;

	/* we now know that all pages are available */
	dir_off = first_dir;
	pg_off = first_pg;

	to_update[n_pgs_to_update] = first_dir;
	n_pgs_to_update++;

	for (i = 0; i < n_entries; i++) {
		uint64 curPhysAddr;

		if (phys_iter_next(phys_iter_arg, &curPhysAddr) != 0) {
			OSA_PR_ERR("%s:%d not enough entries in physical address array\n",
			       __func__, __LINE__);
			osa_free(neo);
			osa_free(to_update);
			return OSA_ERR_PTR(-OSA_EBUSY);
		}
		for (d = 0; d < duplicate; d++) {
			if (pg_off >= MMU_N_PAGE) {
				dir_off++;	/* move to next directory */
				pg_off = 0;	/* using its first page */

				to_update[n_pgs_to_update] = dir_off;
				n_pgs_to_update++;
			}

			/* this page table object does not exists, create it */
			if (!dir_pgtbl[dir_off]) {
				dir_pgtbl[dir_off] = mmu_pgt_create(mmu_dir);
				if (OSA_IS_ERR(dir_pgtbl[dir_off])) {
					dir_pgtbl[dir_off] = NULL;
					goto cleanup_fail;
				}

				/*
				 * make this page table valid
				 * should be dir_off
				 */
				mmu_dir->mmu_info_cfg.pfn_page_write(mmu_dir->dir_page,
								     dir_off,
								     dir_pgtbl[dir_off]->page->phys_addr,
								     MMU_FLAG_VALID);
				dir_modified = osa_true;
			}

			/*
			 * map this particular page in the page table
			 * use d*(MMU page size) to add additional entries from
			 * the given physical address with the correct offset
			 * for the MMU
			 */
			mmu_dir->mmu_info_cfg.pfn_page_write(dir_pgtbl[dir_off]->page,
							     pg_off,
							     curPhysAddr + d *
							     mmu_get_page_size(),
							     neo->used_flag |
							     MMU_FLAG_VALID);
			dir_pgtbl[dir_off]->valid_entries++;

			pg_off++;
		} /* for duplicate */
	} /* for entries */

	neo->n_entries = n_entries * duplicate;
	/* one more mapping is related to this directory */
	mmu_dir->num_mapping++;

	/* if non UMA we need to update device memory */
	if (mmu_dir->mmu_info_cfg.pfn_page_update) {
		while (n_pgs_to_update > 0) {
			uint32 idx = to_update[n_pgs_to_update - 1];
			struct mmu_page_cfg_table *tbl = dir_pgtbl[idx];

			mmu_dir->mmu_info_cfg.pfn_page_update(tbl->page);
			n_pgs_to_update--;
		}
		if (dir_modified)
			mmu_dir->mmu_info_cfg.pfn_page_update(mmu_dir->dir_page);
	}

	osa_free(to_update);
	return neo;

cleanup_fail:
	OSA_PR_ERR("%s:%d failed to create a non-existing page table\n",
	       __func__, __LINE__);

	/*
	 * invalidate all already mapped pages -
	 * do not destroy the created pages
	 */
	while (i > 1) {
		if (d == 0) {
			i--;
			d = duplicate;
		}
		d--;

		if (pg_off == 0) {
			pg_off = MMU_N_PAGE;
			if (!dir_off)
				continue;
			dir_off--;
		}

		pg_off--;

		/* it should have been used before */
		if (!dir_pgtbl[dir_off])
			continue;

		mmu_dir->mmu_info_cfg.pfn_page_write(dir_pgtbl[dir_off]->page,
						     pg_off, 0,
						     MMU_FLAG_INVALID);
		dir_pgtbl[dir_off]->valid_entries--;
	}

	osa_free(neo);
	osa_free(to_update);
	return OSA_ERR_PTR(-OSA_ENOMEM);
}

/*
 * with sg
 */
struct sg_phys_iter {
	void *sgl;
    uint32 offset;
};

static int32 sg_phys_iter_next(void *arg, uint64 *next)
{
	struct sg_phys_iter *iter = arg;

	if (!iter->sgl)
		return -OSA_ENOENT;

	*next = osa_sg_phys(iter->sgl) + iter->offset; /* phys_addr to dma_addr? */
	iter->offset += OSA_PAGE_SIZE;

	if (iter->offset == osa_get_sgl_length(iter->sgl)) {
		iter->sgl = osa_sg_next(iter->sgl);
		iter->offset = 0;
	}

	return 0;
}

/*
 * mmu_directory_map_sg - Create a page table mapping for a list of physical
 *			  pages and device virtual address
 *
 * @mmu_dir: directory to use for the mapping
 * @phys_page_sg: sorted array of physical addresses (ascending order). The
 *		  number of elements is dev_va->alloc_size/MMU_PAGE_SIZE
 * @note This array can potentially be big, the caller may need to use vmalloc
 * if running the linux kernel (e.g. mapping a 1080p NV12 is 760 entries, 6080
 * Bytes - 2 CPU pages needed, fine with osa_malloc; 4k NV12 is 3038 entries,
 * 24304 Bytes - 6 CPU pages needed, osa_malloc would try to find 8 contiguous
 * pages which may be problematic if memory is fragmented)
 * @dev_va: associated device virtual address. Given structure is copied
 * @map_flag: flags to apply on the page (typically 0x2 for Write Only,
 *	      0x4 for Read Only) - the flag should not set bit 1 as 0x1 is the
 *	      valid flag.
 *
 * @warning Mapping can cause memory allocation (missing pages) - do not call
 * while interrupts are disabled
 *
 * @return The opaque handle to the mmu_map object and result to 0
 * @return OSA_ERR_PTR in case of an error with the following values:
 * @li -OSA_EINVAL if the allocation size is not a multiple of MMU_PAGE_SIZE,
 *     if the given list of page table is too long or not long enough for the
 *     mapping or if the give flags set the invalid bit
 * @li -OSA_EPERM if the virtual memory is already mapped
 * @li -OSA_ENOMEM if an internal allocation failed
 * @li -OSA_ENOMEM if a page creation failed
 */
struct mmu_map *mmu_directory_map_sg(struct mmu_directory *mmu_dir,
				     void *phys_page_sg,
				     const struct mmu_heap_alloc *dev_va,
				     uint32 map_flag)
{
	struct sg_phys_iter arg = { phys_page_sg };
	return mmu_directory_map(mmu_dir, dev_va, map_flag,
				 sg_phys_iter_next, &arg);
}

/*
 * mmu_directory_unmap - Un-map the mapped pages (invalidate their entries) and
 *			 destroy the mapping object
 * @map: pointer to the pages to un-map
 *
 * This does not destroy the created Page Table (even if they are becoming
 * un-used) and does not change the Directory valid bits.
 *
 * @return 0
 */
int32 mmu_directory_unmap(struct mmu_map *map)
{
	uint32 first_dir = 0;
	uint32 first_pg = 0;
	uint32 dir_offset = 0;
	uint32 pg_offset = 0;
	uint32 i;
	struct mmu_directory *mmu_dir = NULL;

	/*
	 * in non UMA updates on pages needs to be done - store index of
	 * directory entry pages to update
	 */
	uint32 *to_update;
	uint32 n_pgs_to_update = 0;

	if (!map || map->n_entries <= 0 || !map->mmu_dir)
		return -OSA_EINVAL;

	mmu_dir = map->mmu_dir;

	/*
	 * has to be dynamically allocated because it is bigger than 1k (max
	 * stack in the kernel)
	 */
	to_update = osa_calloc(MMU_N_TABLE, sizeof(uint32), OSA_GFP_KERNEL);
	if (!to_update)
		return -OSA_ENOMEM;

	first_dir = mmu_dir_entry(map->dev_virt_addr.virt_addr);
	first_pg = mmu_pg_entry(map->dev_virt_addr.virt_addr);

	/* verify that the pages that should be used are available */
	dir_offset = first_dir;
	pg_offset = first_pg;

	to_update[n_pgs_to_update] = first_dir;
	n_pgs_to_update++;

	for (i = 0; i < map->n_entries; i++) {
		if (pg_offset >= MMU_N_PAGE) {
			dir_offset++;	/* move to next directory */
			pg_offset = 0;	/* using its first page */

			to_update[n_pgs_to_update] = dir_offset;
			n_pgs_to_update++;
		}

		/*
		 * this page table object does not exist, something destroyed
		 * it while the mapping was supposed to use it
		 */
		if (mmu_dir->dir_page_table[dir_offset]) {
			mmu_dir->mmu_info_cfg.pfn_page_write(mmu_dir->dir_page_table[dir_offset]->page,
							     pg_offset, 0,
							     MMU_FLAG_INVALID);
			mmu_dir->dir_page_table[dir_offset]->valid_entries--;
		}

		pg_offset++;
	}

	mmu_dir->num_mapping--;

	if (mmu_dir->mmu_info_cfg.pfn_page_update)
		while (n_pgs_to_update > 0) {
			uint32 idx = to_update[n_pgs_to_update - 1];
			struct mmu_page_cfg_table *tbl =
					mmu_dir->dir_page_table[idx];

			mmu_dir->mmu_info_cfg.pfn_page_update(tbl->page);
			n_pgs_to_update--;
		}

	/* mapping does not own the given virtual address */
	osa_free(map);
	osa_free(to_update);
	return 0;
}

uint32 mmu_directory_get_pagetable_entry(struct mmu_directory *mmu_dir,
					     uintptr_t dev_virt_addr)
{
	uint32 dir_entry = 0;
	uint32 table_entry = 0;
	struct mmu_page_cfg_table *tbl;
	struct mmu_page_cfg_table **dir_pgtbl = NULL;
	uint32 *page_mem;

	if (!mmu_dir) {
		OSA_PR_ERR("mmu directory table is NULL\n");
		return 0xFFFFFF;
	}

	dir_pgtbl = mmu_dir->dir_page_table;

	dir_entry = mmu_dir_entry(dev_virt_addr);
	table_entry = mmu_pg_entry(dev_virt_addr);

	tbl = dir_pgtbl[dir_entry];
	if (!tbl) {
		OSA_PR_ERR("page table entry is NULL\n");
		return 0xFFFFFF;
	}

	page_mem = (uint32 *)tbl->page->cpu_virt_addr;

	OSA_PR_INFO("Page table value@dir_entry:table_entry[%d : %d] = %x\n", dir_entry, table_entry, page_mem[table_entry]);

	return page_mem[table_entry];

}
