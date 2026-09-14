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
 * List processing primitives.
 */

#include "lst.h"

#ifndef NULL
#define NULL ((void *)0)
#endif

void lst_add(struct lst_t *list, void *item)
{
	if (!list->first) {
		list->first = item;
		list->last = item;
	} else {
		*list->last = item;
		list->last = item;
	}
	*((void **)item) = NULL;
}

void lst_addhead(struct lst_t *list, void *item)
{
	if (!list->first) {
		list->first = item;
		list->last = item;
		*((void **)item) = NULL;
	} else {
		*((void **)item) = list->first;
		list->first = item;
	}
}

int32 lst_empty(struct lst_t *list)
{
	if (!list->first)
		return 1;
	else
		return 0;
}

void *lst_first(struct lst_t *list)
{
	return list->first;
}

void lst_init(struct lst_t *list)
{
	list->first = NULL;
	list->last = NULL;
}

void *lst_last(struct lst_t *list)
{
	return list->last;
}

void *lst_next(void *item)
{
	return *((void **)item);
}

void *lst_removehead(struct lst_t *list)
{
	void **temp = list->first;

	if (temp) {
		list->first = *temp;
		if (!list->first)
			list->last = NULL;
	}
	return temp;
}

void *lst_remove(struct lst_t *list, void *item)
{
	void **p;
	void **q;

	p = (void **)list;
	q = *p;
	while (q) {
		if (q == item) {
			*p = *q;
			if (list->last == q)
				list->last = p;
			return item;
		}
		p = q;
		q = *p;
	}

	return NULL;
}

int32 lst_check(struct lst_t *list, void *item)
{
	void **p;
	void **q;

	p = (void **)list;
	q = *p;
	while (q) {
		if (q == item)
			return 1;
		p = q;
		q = *p;
	}

	return 0;
}
