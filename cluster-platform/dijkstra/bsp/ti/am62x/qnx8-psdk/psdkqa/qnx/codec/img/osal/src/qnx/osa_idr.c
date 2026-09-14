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
 * osa idr list handling implementation for QNX
 */

#include <stdio.h>

#include "../../inc/osa_idr.h"
#include "../../inc/osa_err.h"
#include "../../inc/osa_mem.h"
#include "../../inc/osa_define.h"

struct idr {
    void            **idr_array;
    uint32          idr_start;
    uint32          idr_end;
    uint32          idr_current;
    osa_bool        init_completion;
};

int32 osa_idr_alloc(void *idr, void *ptr, int32 start, int32 end)
{
    struct idr *idr_new = (struct idr *)idr;
    int i = 0;

    if(NULL == idr_new->idr_array && !(idr_new->init_completion))
    {
        idr_new->idr_array = osa_calloc(end + 1, sizeof(void *), 0);
        if (NULL == idr_new->idr_array)
        {
            OSA_PR_ERR("Memory allocation failed in %s\n", __func__);
            return -OSA_ENOMEM;
        }
        idr_new->idr_start = start;
        idr_new->idr_end = end;
        idr_new->idr_current = start;
        idr_new->init_completion = 1;
    }

    for (i = idr_new->idr_current; i <= end; i++)
    {
        if(0 != idr_new->idr_array)
        {
            if(0 == idr_new->idr_array[i])
            {
                idr_new->idr_current = i;
                idr_new->idr_array[i] = ptr;
                return i;
            }
        }
        else
        {
            OSA_PR_ERR("Memory deference failed in %s\n", __func__);
        }
    }
    for (i = start; i < idr_new->idr_current; i++)
    {
        if(0 != idr_new->idr_array)
        {
            if(0 == idr_new->idr_array[i])
            {
                idr_new->idr_current = i;
                idr_new->idr_array[i] = ptr;
                return i;
            }
        }
        else
        {
            OSA_PR_ERR("Memory deference failed in %s\n", __func__);
        }
    }

    return -OSA_ENOMEM;
}

int32 osa_idr_alloc_cyclic(void *idr, void *ptr, int32 start, int32 end)
{
    return osa_idr_alloc(idr, ptr, start, end);
}

void *osa_idr_remove(void *idr, int32 id)
{
    struct idr *idr_new = (struct idr *)idr;
    void *temp = idr_new->idr_array[id];
    idr_new->idr_array[id] = 0;
    return temp;
}

void *osa_idr_find(void *idr, int32 id)
{
    struct idr *idr_new = (struct idr *)idr;
    return idr_new->idr_array[id];
}

void *osa_idr_get_next(void *idr, int32 *nextid)
{
    struct idr *idr_new = (struct idr *)idr;
    int32 i = 0;

    if(idr_new)
    {
        for(i = *nextid + 1; i <= idr_new->idr_end; i++)
        {
            if(0 != idr_new->idr_array[i])
            {
                *nextid = i;
                return idr_new->idr_array[i];
            }
        }

        if(0 != idr_new->idr_array[*nextid])
        {
            return idr_new->idr_array[*nextid];
        }
    }
    return NULL;
}

void osa_idr_destroy(void *idr)
{
    struct idr *idr_new = (struct idr *)idr;
    if(NULL != idr)
    {
        idr_new->init_completion = 0;
        osa_free(idr_new->idr_array);
        osa_free(idr);
    }
}

void osa_idr_init(void **idr_args)
{
    struct idr **idr = (struct idr **)idr_args;
    *idr = osa_calloc(1, sizeof(struct idr), 0);
    if (NULL == *idr)
    {
        OSA_PR_ERR("Memory allocation failed in %s\n", __func__);
        return;
    }
}
