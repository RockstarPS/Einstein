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
 * Self scaling hash tables.
 */

#include "osal/inc/osa_mem.h"
#include "osal/inc/osa_define.h"
#include "hash.h"
#include "img_errors.h"
#include "pool.h"

#define FALSE 0
#define TRUE 1

/* pool of struct hash objects */
static struct pool *global_hashpool = NULL;

/* pool of struct bucket objects */
static struct pool *global_bucketpool = NULL;

static int32 global_initialized = FALSE;

/* Each entry in a hash table is placed into a bucket */
struct bucket {
	struct bucket *next;
	uint64 key;
	uint64 value;
};

struct hash {
	struct bucket **table;
	uint32 size;
	uint32 count;
	uint32 minimum_size;
};

/*
 * @Function	hash_func
 * @Description
 * Hash function intended for hashing addresses.
 * @Input	Vale : The key to hash.
 * @Input	size : The size of the hash table
 * @Return	hash : The hash value.
 */
static uint32 hash_func(uint64 vale,
		     uint32 size)
{
	uint32 hash = (uint32)(vale);

	hash += (hash << 12);
	hash ^= (hash >> 22);
	hash += (hash << 4);
	hash ^= (hash >> 9);
	hash += (hash << 10);
	hash ^= (hash >> 2);
	hash += (hash << 7);
	hash ^= (hash >> 12);
	hash &= (size - 1);
	return hash;
}

/*
 * @Function	hash_chain_insert
 * @Description
 * Hash function intended for hashing addresses.
 * @Input	bucket : The bucket
 * @Input	table : The hash table
 * @Input	size : The size of the hash table
 * @Return	IMG_SUCCESS or an error code.
 */
static int32 hash_chain_insert(struct bucket *bucket,
			     struct bucket **table,
			     uint32 size)
{
	uint32 idx;
	uint32 result = IMG_ERROR_FATAL;

	if (!bucket || !table || !size) {
		result = IMG_ERROR_INVALID_PARAMETERS;
		return result;
	}

	idx = hash_func(bucket->key, size);

	if (idx < size) {
		result = IMG_SUCCESS;
		bucket->next = table[idx];
		table[idx] = bucket;
	}

	return result;
}

/*
 * @Function	hash_rehash
 * @Description
 * Iterate over every entry in an old hash table and rehash into the new table.
 * @Input	old_table : The old hash table
 * @Input	old_size : The size of the old hash table
 * @Input	new_table : The new hash table
 * @Input	new_sz : The size of the new hash table
 * @Return	IMG_SUCCESS or an error code.
 */
static int32 hash_rehash(struct bucket **old_table,
		       uint32 old_size,
		       struct bucket **new_table,
		       uint32 new_sz)
{
	uint32 idx;
	uint32 result = IMG_ERROR_FATAL;

	if (!old_table || !new_table) {
		result = IMG_ERROR_INVALID_PARAMETERS;
		return result;
	}

	for (idx = 0; idx < old_size; idx++) {
		struct bucket *bucket;
		struct bucket *nex_bucket;

		bucket = old_table[idx];
		while (bucket) {
			nex_bucket = bucket->next;
			result = hash_chain_insert(bucket, new_table, new_sz);
			if (result != IMG_SUCCESS) {
				result = IMG_ERROR_UNEXPECTED_STATE;
				return result;
			}
			bucket = nex_bucket;
		}
	}
	result = IMG_SUCCESS;

	return result;
}

/*
 * @Function	hash_resize
 * @Description
 * Attempt to resize a hash table, failure to allocate a new larger hash table
 * is not considered a hard failure. We simply continue and allow the table to
 * fill up, the effect is to allow hash chains to become longer.
 * @Input	hash_arg : Pointer to the hash table
 * @Input	new_sz : The size of the new hash table
 * @Return	IMG_SUCCESS or an error code.
 */
static int32 hash_resize(struct hash *hash_arg,
		       uint32 new_sz)
{
	uint32 malloc_sz = 0;
	uint32 result = IMG_ERROR_FATAL;
	uint32 idx;

	if (!hash_arg) {
		result = IMG_ERROR_INVALID_PARAMETERS;
		return result;
	}

	if (new_sz != hash_arg->size) {
		struct bucket **new_bkt_table;

		malloc_sz = (sizeof(struct bucket *) * new_sz);
		new_bkt_table = osa_malloc(malloc_sz, OSA_GFP_KERNEL);

		if (!new_bkt_table) {
			result = IMG_ERROR_MALLOC_FAILED;
			return result;
		}

		for (idx = 0; idx < new_sz; idx++)
			new_bkt_table[idx] = NULL;

		result = hash_rehash(hash_arg->table,
				     hash_arg->size,
				     new_bkt_table,
				     new_sz);

		if (result != IMG_SUCCESS) {
			osa_free(new_bkt_table);
			new_bkt_table = NULL;
			result = IMG_ERROR_UNEXPECTED_STATE;
			return result;
		}

		if (hash_arg->table)
			osa_free(hash_arg->table);
		hash_arg->table = new_bkt_table;
		hash_arg->size = new_sz;
	}
	result = IMG_SUCCESS;

	return result;
}

static uint32 private_max(uint32 a, uint32 b)
{
	uint32 ret = (a > b) ? a : b;
	return ret;
}

/*
 * @Function	vid_hash_initialise
 * @Description
 * To initialise the hash module.
 * @Input	None
 * @Return	IMG_SUCCESS or an error code.
 */
int32 vid_hash_initialise(void)
{
	uint32 result = IMG_ERROR_ALREADY_COMPLETE;

	if (!global_initialized) {
		if (global_hashpool || global_bucketpool) {
			result = IMG_ERROR_UNEXPECTED_STATE;
			return result;
		}

		result = pool_create((const uint8 * const)"img-hash",
				     sizeof(struct hash),
				     &global_hashpool);

		if (result != IMG_SUCCESS) {
			result = IMG_ERROR_UNEXPECTED_STATE;
			return result;
		}

		result = pool_create((const uint8 * const)"img-sBucket",
				     sizeof(struct bucket),
				     &global_bucketpool);
		if (result != IMG_SUCCESS) {
			if (global_bucketpool) {
				result = pool_delete(global_bucketpool);
				global_bucketpool = NULL;
			}
			result = IMG_ERROR_UNEXPECTED_STATE;
			return result;
		}
		global_initialized = TRUE;
		result = IMG_SUCCESS;
	}
	return result;
}

/*
 * @Function	vid_hash_finalise
 * @Description
 * To finalise the hash module. All allocated hash tables should
 * be deleted before calling this function.
 * @Input	None
 * @Return	IMG_SUCCESS or an error code.
 */
int32 vid_hash_finalise(void)
{
	uint32 result = IMG_ERROR_FATAL;

	if (global_initialized) {
		if (global_hashpool) {
			result = pool_delete(global_hashpool);
			if (result != IMG_SUCCESS)
				return result;

			global_hashpool = NULL;
		}

		if (global_bucketpool) {
			result = pool_delete(global_bucketpool);
			if (result != IMG_SUCCESS)
				return result;

			global_bucketpool = NULL;
		}
		global_initialized = FALSE;
		result = IMG_SUCCESS;
	}

	return result;
}

/*
 * @Function	vid_hash_create
 * @Description
 * Create a self scaling hash table.
 * @Input	initial_size : Initial and minimum size of the hash table.
 * @Output	hash_arg : Will countin the hash table handle or NULL.
 * @Return	IMG_SUCCESS or an error code.
 */
int32 vid_hash_create(uint32 initial_size,
		    struct hash ** const hash_arg)
{
	uint32 idx;
	uint32 tbl_sz = 0;
	uint32 result = IMG_ERROR_FATAL;
	struct hash *local_hash = NULL;

	if (!hash_arg) {
		result = IMG_ERROR_INVALID_PARAMETERS;
		return result;
	}

	if (global_initialized) {
		pool_alloc(global_hashpool, ((void **)&local_hash));
		if (!local_hash) {
			result = IMG_ERROR_UNEXPECTED_STATE;
			*hash_arg = NULL;
			return result;
		}

		local_hash->count = 0;
		local_hash->size = initial_size;
		local_hash->minimum_size = initial_size;

		tbl_sz = (sizeof(struct bucket *) * local_hash->size);
		local_hash->table = osa_malloc(tbl_sz, OSA_GFP_KERNEL);
		if (!local_hash->table) {
			result = pool_free(global_hashpool, local_hash);
			if (result != IMG_SUCCESS)
				result = IMG_ERROR_UNEXPECTED_STATE;
			result |= IMG_ERROR_MALLOC_FAILED;
			*hash_arg = NULL;
			return result;
		}

		for (idx = 0; idx < local_hash->size; idx++)
			local_hash->table[idx] = NULL;

		*hash_arg = local_hash;
		result = IMG_SUCCESS;
	}
	return result;
}

/*
 * @Function	vid_hash_delete
 * @Description
 * To delete a hash table, all entries in the table should be
 * removed before calling this function.
 * @Input	hash_arg : Hash table pointer
 * @Return	IMG_SUCCESS or an error code.
 */
int32 vid_hash_delete(struct hash * const hash_arg)
{
	uint32 result = IMG_ERROR_FATAL;

	if (!hash_arg) {
		result = IMG_ERROR_INVALID_PARAMETERS;
		return result;
	}

	if (global_initialized) {
		if (hash_arg->count != 0) {
			result = IMG_ERROR_UNEXPECTED_STATE;
			return result;
		}

		osa_free(hash_arg->table);
		hash_arg->table = NULL;

		result = pool_free(global_hashpool, hash_arg);
		if (result != IMG_SUCCESS) {
			result = IMG_ERROR_UNEXPECTED_STATE;
			return result;
		}
	}
	return result;
}

/*
 * @Function	vid_hash_insert
 * @Description
 * To insert a key value pair into a hash table.
 * @Input	hash_arg : Hash table pointer
 * @Input	key : Key value
 * @Input	value : The value associated with the key.
 * @Return	IMG_SUCCESS or an error code.
 */
int32 vid_hash_insert(struct hash * const hash_arg,
		    uint64 key,
		    uint64 value)
{
	struct bucket *ps_bucket = NULL;
	uint32 result = IMG_ERROR_FATAL;

	if (!hash_arg) {
		result = IMG_ERROR_INVALID_PARAMETERS;
		return result;
	}

	if (global_initialized) {
		result = pool_alloc(global_bucketpool, ((void **)&ps_bucket));
		if (result != IMG_SUCCESS || !ps_bucket) {
			result = IMG_ERROR_UNEXPECTED_STATE;
			return result;
		}
		ps_bucket->next = NULL;
		ps_bucket->key = key;
		ps_bucket->value = value;

		result = hash_chain_insert(ps_bucket,
					   hash_arg->table,
					   hash_arg->size);

		if (result != IMG_SUCCESS) {
			pool_free(global_bucketpool, ((void **)&ps_bucket));
			result = IMG_ERROR_UNEXPECTED_STATE;
			return result;
		}

		hash_arg->count++;

		/* check if we need to think about re-balancing */
		if ((hash_arg->count << 1) > hash_arg->size) {
			result = hash_resize(hash_arg, (hash_arg->size << 1));
			if (result != IMG_SUCCESS) {
				result = IMG_ERROR_UNEXPECTED_STATE;
				return result;
			}
		}
		result = IMG_SUCCESS;
	}
	return result;
}

/*
 * @Function	vid_hash_remove
 * @Description
 * To remove a key value pair from a hash table
 * @Input	hash_arg : Hash table pointer
 * @Input	key : Key value
 * @Input	ret_result : 0 if the key is missing or the value
 *		associated with the key.
 * @Return	IMG_SUCCESS or an error code.
 */
int32 vid_hash_remove(struct hash * const hash_arg,
		    uint64 key,
		    ulong * const ret_result)
{
	uint32 idx;
	uint32 tmp1 = 0;
	uint32 tmp2 = 0;
	uint32 result = IMG_ERROR_FATAL;
	struct bucket **bucket = NULL;

	if (!hash_arg) {
		result = IMG_ERROR_INVALID_PARAMETERS;
		return result;
	}

	idx = hash_func(key, hash_arg->size);

	for (bucket = &hash_arg->table[idx]; (*bucket) != NULL;
		bucket = &((*bucket)->next)) {
		if ((*bucket)->key == key) {
			struct bucket *ps_bucket = (*bucket);

			uint64 value = ps_bucket->value;

			*bucket = ps_bucket->next;
			result = pool_free(global_bucketpool, ps_bucket);

			hash_arg->count--;

			/* check if we need to think about re-balencing */
			if (hash_arg->size > (hash_arg->count << 2) &&
			    hash_arg->size > hash_arg->minimum_size) {
				tmp1 = (hash_arg->size >> 1);
				tmp2 = hash_arg->minimum_size;
				result = hash_resize(hash_arg,
						     private_max(tmp1, tmp2));
			}
			*ret_result = value;
			result = IMG_SUCCESS;
			break;
		}
	}
	return result;
}
