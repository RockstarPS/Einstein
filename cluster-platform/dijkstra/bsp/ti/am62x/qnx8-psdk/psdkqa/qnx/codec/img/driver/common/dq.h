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
 * Utility module for doubly linked queues.
 */
#ifndef DQ_H
#define DQ_H

/* dq structure */
struct dq_linkage_t {
	struct dq_linkage_t *fwd;
	struct dq_linkage_t *back;
};

/* Function Prototypes */
void dq_addafter(void *predecessor, void *item);
void dq_addbefore(void *successor, void *item);
void dq_addhead(struct dq_linkage_t *queue, void *item);
void dq_addtail(struct dq_linkage_t *queue, void *item);
int32 dq_empty(struct dq_linkage_t *queue);
void *dq_first(struct dq_linkage_t *queue);
void *dq_last(struct dq_linkage_t *queue);
void dq_init(struct dq_linkage_t *queue);
void dq_move(struct dq_linkage_t *from, struct dq_linkage_t *to);
void *dq_next(void *item);
void *dq_previous(void *item);
void dq_remove(void *item);
void *dq_removehead(struct dq_linkage_t *queue);
void *dq_removetail(struct dq_linkage_t *queue);

#endif /* #define DQ_H */
