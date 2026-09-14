/*
 *  Copyright (C) 2018-2021 Texas Instruments Incorporated
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


#include <kernel/dpl/QueueP.h>
#include <kernel/dpl/HwiP.h>
#include <drivers/hw_include/csl_types.h>

/*!
 *  @brief    QueueP_nortos structure
 */
typedef struct QueueP_nortos_s
{
    QueueP_Elem          queueHndl;
} QueueP_nortos;

/*
 *  ======== QueueP_create ========
 */
QueueP_Handle QueueP_create(QueueP_Object *obj)
{
    QueueP_Handle       ret_handle = 0;

    return ret_handle;
}

/*
 *  ======== QueueP_delete ========
 */
int32_t QueueP_delete(QueueP_Handle handle)
{


    return SystemP_SUCCESS;
}

/*
 *  ======== QueueP_get ========
 */
void * QueueP_get(QueueP_Handle handle)
{

    QueueP_Elem      *pElem = NULL;


    return (pElem);
}

/*
 *  ======== QueueP_put ========
 */
int32_t QueueP_put(QueueP_Handle handle, void *elem)
{

    int32_t   ret_val = SystemP_SUCCESS;


    return ret_val;
}

/*
 *  ======== QueueP_isEmpty ========
 */
uint32_t QueueP_isEmpty(QueueP_Handle handle)
{

    uint32_t        ret_val;


    return (ret_val);
}

/* Nothing past this point */
