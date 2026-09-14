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
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
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
 * Utility module for doubly linked queues.
 */

#include "osal/inc/osa_mem.h"
#include "osal/inc/osa_types.h"
#include "osal/inc/osa_mutex.h"
#include "osal/inc/osa_define.h"

#include "dq.h"
#include "img_errors.h"

void dq_init(struct dq_linkage_t *queue)
{
	queue->fwd = (struct dq_linkage_t *)queue;
	queue->back = (struct dq_linkage_t *)queue;
}

void dq_addhead(struct dq_linkage_t *queue, void *item)
{
	IMG_DBG_ASSERT(((struct dq_linkage_t *)queue)->back);
	IMG_DBG_ASSERT(((struct dq_linkage_t *)queue)->fwd);

	if (!((struct dq_linkage_t *)queue)->back ||
	    !((struct dq_linkage_t *)queue)->fwd)
		return;

	((struct dq_linkage_t *)item)->back = (struct dq_linkage_t *)queue;
	((struct dq_linkage_t *)item)->fwd =
					((struct dq_linkage_t *)queue)->fwd;
	((struct dq_linkage_t *)queue)->fwd->back = (struct dq_linkage_t *)item;
	((struct dq_linkage_t *)queue)->fwd = (struct dq_linkage_t *)item;
}

void dq_addtail(struct dq_linkage_t *queue, void *item)
{
	IMG_DBG_ASSERT(((struct dq_linkage_t *)queue)->back);
	IMG_DBG_ASSERT(((struct dq_linkage_t *)queue)->fwd);

	if (!((struct dq_linkage_t *)queue)->back ||
	    !((struct dq_linkage_t *)queue)->fwd)
		return;

	((struct dq_linkage_t *)item)->fwd = (struct dq_linkage_t *)queue;
	((struct dq_linkage_t *)item)->back =
					((struct dq_linkage_t *)queue)->back;
	((struct dq_linkage_t *)queue)->back->fwd = (struct dq_linkage_t *)item;
	((struct dq_linkage_t *)queue)->back = (struct dq_linkage_t *)item;
}

int32 dq_empty(struct dq_linkage_t *queue)
{
	IMG_DBG_ASSERT(((struct dq_linkage_t *)queue)->back);
	IMG_DBG_ASSERT(((struct dq_linkage_t *)queue)->fwd);

	if (!((struct dq_linkage_t *)queue)->back ||
	    !((struct dq_linkage_t *)queue)->fwd)
		return 1;

	return ((queue)->fwd == (struct dq_linkage_t *)(queue));
}

void *dq_first(struct dq_linkage_t *queue)
{
	struct dq_linkage_t *temp = queue->fwd;

	IMG_DBG_ASSERT(((struct dq_linkage_t *)queue)->back);
	IMG_DBG_ASSERT(((struct dq_linkage_t *)queue)->fwd);

	if (!((struct dq_linkage_t *)queue)->back ||
	    !((struct dq_linkage_t *)queue)->fwd)
		return NULL;

	return temp == (struct dq_linkage_t *)queue ? NULL : temp;
}

void *dq_last(struct dq_linkage_t *queue)
{
	struct dq_linkage_t *temp = queue->back;

	IMG_DBG_ASSERT(((struct dq_linkage_t *)queue)->back);
	IMG_DBG_ASSERT(((struct dq_linkage_t *)queue)->fwd);

	if (!((struct dq_linkage_t *)queue)->back ||
	    !((struct dq_linkage_t *)queue)->fwd)
		return NULL;

	return temp == (struct dq_linkage_t *)queue ? NULL : temp;
}

void *dq_next(void *item)
{
	IMG_DBG_ASSERT(((struct dq_linkage_t *)item)->back);
	IMG_DBG_ASSERT(((struct dq_linkage_t *)item)->fwd);

	if (!((struct dq_linkage_t *)item)->back ||
	    !((struct dq_linkage_t *)item)->fwd)
		return NULL;

	return ((struct dq_linkage_t *)item)->fwd;
}

void *dq_previous(void *item)
{
	IMG_DBG_ASSERT(((struct dq_linkage_t *)item)->back);
	IMG_DBG_ASSERT(((struct dq_linkage_t *)item)->fwd);

	if (!((struct dq_linkage_t *)item)->back ||
	    !((struct dq_linkage_t *)item)->fwd)
		return NULL;

	return ((struct dq_linkage_t *)item)->back;
}

void dq_remove(void *item)
{
	IMG_DBG_ASSERT(((struct dq_linkage_t *)item)->back);
	IMG_DBG_ASSERT(((struct dq_linkage_t *)item)->fwd);

	if (!((struct dq_linkage_t *)item)->back ||
	    !((struct dq_linkage_t *)item)->fwd)
		return;

	((struct dq_linkage_t *)item)->fwd->back =
					((struct dq_linkage_t *)item)->back;
	((struct dq_linkage_t *)item)->back->fwd =
					((struct dq_linkage_t *)item)->fwd;

	/* make item linkages safe for "orphan" removes */
	((struct dq_linkage_t *)item)->fwd = item;
	((struct dq_linkage_t *)item)->back = item;
}

void *dq_removehead(struct dq_linkage_t *queue)
{
	struct dq_linkage_t *temp;

	IMG_DBG_ASSERT(((struct dq_linkage_t *)queue)->back);
	IMG_DBG_ASSERT(((struct dq_linkage_t *)queue)->fwd);

	if (!((struct dq_linkage_t *)queue)->back ||
	    !((struct dq_linkage_t *)queue)->fwd)
		return NULL;

	if ((queue)->fwd == (struct dq_linkage_t *)(queue))
		return NULL;

	temp = ((struct dq_linkage_t *)queue)->fwd;
	temp->fwd->back = temp->back;
	temp->back->fwd = temp->fwd;

	/* make item linkages safe for "orphan" removes */
	temp->fwd = temp;
	temp->back = temp;
	return temp;
}

void *dq_removetail(struct dq_linkage_t *queue)
{
	struct dq_linkage_t *temp;

	IMG_DBG_ASSERT(((struct dq_linkage_t *)queue)->back);
	IMG_DBG_ASSERT(((struct dq_linkage_t *)queue)->fwd);

	if (!((struct dq_linkage_t *)queue)->back ||
	    !((struct dq_linkage_t *)queue)->fwd)
		return NULL;

	if ((queue)->fwd == (struct dq_linkage_t *)(queue))
		return NULL;

	temp = ((struct dq_linkage_t *)queue)->back;
	temp->fwd->back = temp->back;
	temp->back->fwd = temp->fwd;

	/* make item linkages safe for "orphan" removes */
	temp->fwd = temp;
	temp->back = temp;

	return temp;
}

void dq_addbefore(void *successor, void *item)
{
	IMG_DBG_ASSERT(((struct dq_linkage_t *)successor)->back);
	IMG_DBG_ASSERT(((struct dq_linkage_t *)successor)->fwd);

	if (!((struct dq_linkage_t *)successor)->back ||
	    !((struct dq_linkage_t *)successor)->fwd)
		return;

	((struct dq_linkage_t *)item)->fwd = (struct dq_linkage_t *)successor;
	((struct dq_linkage_t *)item)->back =
				((struct dq_linkage_t *)successor)->back;
	((struct dq_linkage_t *)item)->back->fwd = (struct dq_linkage_t *)item;
	((struct dq_linkage_t *)successor)->back = (struct dq_linkage_t *)item;
}

void dq_addafter(void *predecessor, void *item)
{
	IMG_DBG_ASSERT(((struct dq_linkage_t *)predecessor)->back);
	IMG_DBG_ASSERT(((struct dq_linkage_t *)predecessor)->fwd);

	if (!((struct dq_linkage_t *)predecessor)->back ||
	    !((struct dq_linkage_t *)predecessor)->fwd)
		return;

	((struct dq_linkage_t *)item)->fwd =
				((struct dq_linkage_t *)predecessor)->fwd;
	((struct dq_linkage_t *)item)->back =
					(struct dq_linkage_t *)predecessor;
	((struct dq_linkage_t *)item)->fwd->back = (struct dq_linkage_t *)item;
	((struct dq_linkage_t *)predecessor)->fwd = (struct dq_linkage_t *)item;
}

void dq_move(struct dq_linkage_t *from, struct dq_linkage_t *to)
{
	IMG_DBG_ASSERT(((struct dq_linkage_t *)from)->back);
	IMG_DBG_ASSERT(((struct dq_linkage_t *)from)->fwd);
	IMG_DBG_ASSERT(((struct dq_linkage_t *)to)->back);
	IMG_DBG_ASSERT(((struct dq_linkage_t *)to)->fwd);

	if (!((struct dq_linkage_t *)from)->back ||
	    !((struct dq_linkage_t *)from)->fwd ||
	    !((struct dq_linkage_t *)to)->back ||
	    !((struct dq_linkage_t *)to)->fwd)
		return;

	if ((from)->fwd == (struct dq_linkage_t *)(from)) {
		dq_init(to);
	} else {
		*to = *from;
		to->fwd->back = (struct dq_linkage_t *)to;
		to->back->fwd = (struct dq_linkage_t *)to;
		dq_init(from);
	}
}
