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
 * ID generation manager API.
 */

#include "osal/inc/osa_mem.h"
#include "osal/inc/osa_define.h"
#include "idgen_api.h"
#include "lst.h"

/*
 * This structure contains ID context.
 */
struct idgen_context {
	/* List of handle block structures */
	struct lst_t hdlblklst;
	/* Max ID - set by IDGEN_CreateContext(). */
	uint32 maxid;
	/*
	 * The number of handle per block. In case of
	 * incrementing ids, size of the Hash table.
	 */
	uint32 blksize;
	/* Next free slot. */
	uint32 freeslot;
	/* Max slot+1 for which we have allocated blocks. */
	uint32 maxslotplus1;
	/* Incrementing ID's */
	/* API needed to return incrementing IDs */
	int32 incids;
	/* Latest ID given back */
	uint32 latestincnumb;
	/* Array of list to hold IDGEN_sHdlId */
	struct lst_t *incidlist;
};

/*
 * This structure represents internal representation of an Incrementing ID.
 */
struct idgen_id {
	void **link; /* to be part of single linked list */
	/* Incrementing ID returned */
	uint32 incid;
	void *hid;
};

/*
 * Structure contains the ID context.
 */
struct idgen_hdblk {
	void **link; /* to be part of single linked list */
	/* Array of handles in this block. */
	void *ahhandles[1];
};

/*
 * A hashing function could go here. Currently just makes a circular list of
 * max number of concurrent Ids (idgen_context->blksize) in the system.
 */
static uint32 idgen_func(struct idgen_context *idcontext, uint32 id)
{
	return ((id - 1) % idcontext->blksize);
}

int32 idgen_createcontext(uint32 maxid, uint32 blksize,
			int32 incid, void **idgenhandle)
{
	struct idgen_context *idcontext;

	/* Create context structure */
	idcontext = osa_zalloc(sizeof(*idcontext), OSA_GFP_KERNEL);
	if (!idcontext)
		return IMG_ERROR_OUT_OF_MEMORY;

	/* InitIalise the context */
	lst_init(&idcontext->hdlblklst);
	idcontext->maxid   = maxid;
	idcontext->blksize = blksize;

	/* If we need incrementing Ids */
	idcontext->incids = incid;
	idcontext->latestincnumb = 0;
	idcontext->incidlist  = NULL;
	if (idcontext->incids) {
		uint32 i = 0;
		/* Initialise the hash table of lists of length ui32BlkSize */
		idcontext->incidlist = osa_zalloc((sizeof(*idcontext->incidlist) *
				idcontext->blksize), OSA_GFP_KERNEL);
		if (!idcontext->incidlist) {
			osa_free(idcontext);
			return IMG_ERROR_OUT_OF_MEMORY;
		}

		/* Initialise all the lists in the hash table */
		for (i = 0; i < idcontext->blksize; i++)
			lst_init(&idcontext->incidlist[i]);
	}

	/* Return context structure as handle */
	*idgenhandle = idcontext;

	return IMG_SUCCESS;
}

int32 idgen_destroycontext(void *idgenhandle)
{
	struct idgen_context *idcontext = (struct idgen_context *)idgenhandle;
	struct idgen_hdblk *hdblk;

	if (!idcontext)
		return IMG_ERROR_INVALID_PARAMETERS;

	/* If incrementing Ids, free the List of Incrementing Ids */
	if (idcontext->incids) {
		struct idgen_id *id;
		uint32 i = 0;

		for (i = 0; i < idcontext->blksize; i++) {
			id = lst_removehead(&idcontext->incidlist[i]);
			while (id) {
				osa_free(id);
				id = lst_removehead(&idcontext->incidlist[i]);
			}
		}
		osa_free(idcontext->incidlist);
	}

	/* Remove and free all handle blocks */
	hdblk = (struct idgen_hdblk *)lst_removehead(&idcontext->hdlblklst);
	while (hdblk) {
		osa_free(hdblk);
		hdblk = (struct idgen_hdblk *)
				lst_removehead(&idcontext->hdlblklst);
	}

	/* Free context structure */
	osa_free(idcontext);

	return IMG_SUCCESS;
}

static int32 idgen_findnextfreeslot(void *idgenhandle, uint32 prevfreeslot)
{
	struct idgen_context *idcontext = (struct idgen_context *)idgenhandle;
	struct idgen_hdblk *hdblk;
	uint32 freslotblk;
	uint32 freeslot;

	if (!idcontext)
		return IMG_ERROR_INVALID_PARAMETERS;

	/* Find the block containing the current free slot */
	freeslot	= prevfreeslot;
	freslotblk = prevfreeslot;
	hdblk = (struct idgen_hdblk *)lst_first(&idcontext->hdlblklst);
	if (!hdblk)
		return IMG_ERROR_FATAL;

	while (freslotblk >= idcontext->blksize) {
		freslotblk -= idcontext->blksize;
		hdblk = (struct idgen_hdblk *)lst_next(hdblk);
	}

	/* Locate the next free slot */
	while (hdblk) {
		while (freslotblk < idcontext->blksize) {
			if (!hdblk->ahhandles[freslotblk]) {
				/* Found */
				idcontext->freeslot = freeslot;
				return IMG_SUCCESS;
			}
			freeslot++;
			freslotblk++;
		}
		freslotblk = 0;
		hdblk = (struct idgen_hdblk *)lst_next(hdblk);
	}

	/* Beyond the last block */
	idcontext->freeslot = freeslot;
	return IMG_SUCCESS;
}

/*
 * This function returns ID structure (
 */
static struct idgen_id *idgen_getid(struct lst_t *idlist, uint32 id)
{
	struct idgen_id *idstruct;

	idstruct = lst_first(idlist);
	while (idstruct) {
		if (idstruct->incid == id)
			break;

		idstruct = lst_next(idstruct);
	}
	return idstruct;
}

/*
 * This function does IDGEN allocation.
 */
int32 idgen_allocid(void *idgenhandle, void *handle, uint32 *id)
{
	struct idgen_context *idcontext = (struct idgen_context *)idgenhandle;
	struct idgen_hdblk *hdblk;
	uint32 size = 0;
	uint32 freeslot = 0;
	uint32 result = 0;

	if (!idcontext || !handle)
		return IMG_ERROR_INVALID_PARAMETERS;

	if (!idcontext->incids) {
		/* If the free slot is >= to the max id */
		if (idcontext->freeslot >= idcontext->maxid) {
			result = IMG_ERROR_INVALID_ID;
			goto error;
		}

		/* If all of the allocated Ids have been used */
		if (idcontext->freeslot >= idcontext->maxslotplus1) {
			/* Allocate a stream context */
			size = sizeof(*hdblk) + (sizeof(void *) *
				(idcontext->blksize - 1));
			hdblk = osa_zalloc(size, OSA_GFP_KERNEL);
			if (!hdblk) {
				result = IMG_ERROR_OUT_OF_MEMORY;
				goto error;
			}

			lst_add(&idcontext->hdlblklst, hdblk);
			idcontext->maxslotplus1 += idcontext->blksize;
		}

		/* Find the block containing the next free slot */
		freeslot = idcontext->freeslot;
		hdblk = (struct idgen_hdblk *)lst_first(&idcontext->hdlblklst);
		if (!hdblk) {
			result = IMG_ERROR_FATAL;
			goto error;
		}
		while (freeslot >= idcontext->blksize) {
			freeslot -= idcontext->blksize;
			hdblk = (struct idgen_hdblk *)lst_next(hdblk);
			if (!hdblk) {
				result = IMG_ERROR_FATAL;
				goto error;
			}
		}

		/* Put handle in the next free slot */
		hdblk->ahhandles[freeslot] = handle;

		*id = idcontext->freeslot + 1;

		/* Find a new free slot */
		result = idgen_findnextfreeslot(idcontext, idcontext->freeslot);
		if (result != 0)
			goto error;
	/*
	 * If incrementing IDs, just add the ID node to the correct hash table
	 * list.
	 */
	} else {
		struct idgen_id *psid;
		uint32 currentincnum, funcid;
		/*
		 * If incrementing IDs, increment the id for returning back,and
		 * save the ID node in the list of ids, indexed by hash function
		 * (idgen_func). We might want to use a better hashing function
		 */
		currentincnum = (idcontext->latestincnumb + 1) %
				idcontext->maxid;

		/* Increment the id. Wraps if greater then Max Id */
		if (currentincnum == 0)
			currentincnum++;

		idcontext->latestincnumb = currentincnum;

		result = IMG_ERROR_INVALID_ID;
		do {
			/* Add to list in the correct hash table entry */
			funcid = idgen_func(idcontext, idcontext->latestincnumb);
			if (idgen_getid(&idcontext->incidlist[funcid],
					idcontext->latestincnumb) == NULL) {
				psid = osa_malloc(sizeof(*psid), OSA_GFP_KERNEL);
				if (!psid) {
					result = IMG_ERROR_OUT_OF_MEMORY;
					goto error;
				}

				psid->incid = idcontext->latestincnumb;
				psid->hid = handle;

				funcid = idgen_func(idcontext,
						    idcontext->latestincnumb);
				lst_add(&idcontext->incidlist[funcid],
					psid);

				result = IMG_SUCCESS;
			} else {
				idcontext->latestincnumb =
					(idcontext->latestincnumb + 1) %
						idcontext->maxid;
				if (idcontext->latestincnumb == 0) {
					/* Do not want to have zero as pic id */
					idcontext->latestincnumb++;
				}
				/*
				 * We have reached a point where we have wrapped
				 * allowed Ids (MaxId) and we want to overwrite
				 * ID still not released
				 */
				if (idcontext->latestincnumb == currentincnum)
					goto error;
			}
		} while (result != IMG_SUCCESS);

		*id = psid->incid;
	}
	return IMG_SUCCESS;
error:
	return result;
}

int32 idgen_freeid(void *idgenhandle, uint32 id)
{
	struct idgen_context *idcontext = (struct idgen_context *)idgenhandle;
	struct idgen_hdblk *hdblk;
	uint32 origslot;
	uint32 slot;

	if (idcontext->incids) {
		/*
		 * Find the slot in the correct hash table entry, and
		 * remove the ID.
		 */
		struct idgen_id *psid;

		psid = idgen_getid(&idcontext->incidlist
				[idgen_func(idcontext, id)], id);
		if (psid) {
			lst_remove(&idcontext->incidlist
					[idgen_func(idcontext, id)], psid);
			osa_free(psid);
		} else {
			return IMG_ERROR_INVALID_ID;
		}
	} else {
		/* If not incrementing id */
		slot = id - 1;
		origslot = slot;

		if (slot >= idcontext->maxslotplus1)
			return IMG_ERROR_INVALID_ID;

		/* Find the block containing the id */
		hdblk = (struct idgen_hdblk *)lst_first(&idcontext->hdlblklst);
		if (!hdblk)
			return IMG_ERROR_FATAL;

		while (slot >= idcontext->blksize) {
			slot -= idcontext->blksize;
			hdblk = (struct idgen_hdblk *)lst_next(hdblk);
			if (!hdblk)
				return IMG_ERROR_FATAL;
		}

		/* Slot should be occupied */
		if (!hdblk->ahhandles[slot])
			return IMG_ERROR_INVALID_ID;

		/* Free slot */
		hdblk->ahhandles[slot] = NULL;

		/* If this slot is before the previous free slot */
		if ((origslot) < idcontext->freeslot)
			idcontext->freeslot = origslot;
	}
	return IMG_SUCCESS;
}

int32 idgen_gethandle(void *idgenhandle, uint32 id, void **handle)
{
	struct idgen_context *idcontext = (struct idgen_context *)idgenhandle;
	struct idgen_hdblk *hdblk;
	uint32 slot;

	if (!idcontext)
		return IMG_ERROR_INVALID_PARAMETERS;

	if (idcontext->incids) {
		/*
		 * Find the slot in the correct hash table entry, and return
		 * the handles.
		 */
		struct idgen_id *psid;

		psid = idgen_getid(&idcontext->incidlist
				[idgen_func(idcontext, id)], id);
		if (psid)
			*handle = psid->hid;

		else
			return IMG_ERROR_INVALID_ID;
	} else {
		/* If not incrementing IDs */
		slot = id - 1;
		if (slot >= idcontext->maxslotplus1)
			return IMG_ERROR_INVALID_ID;

		/* Find the block containing the id */
		hdblk = (struct idgen_hdblk *)lst_first(&idcontext->hdlblklst);
		if (!hdblk)
			return IMG_ERROR_INVALID_PARAMETERS;

		while (slot >= idcontext->blksize) {
			slot -= idcontext->blksize;
			hdblk = (struct idgen_hdblk *)lst_next(hdblk);
			if (!hdblk)
				return IMG_ERROR_INVALID_PARAMETERS;
		}

		/* Slot should be occupied */
		if (!hdblk->ahhandles[slot])
			return IMG_ERROR_INVALID_ID;

		/* Return the handle */
		*handle = hdblk->ahhandles[slot];
		}

	return IMG_SUCCESS;
}
