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
 * osa definitions header
 */

#ifndef OSA_QUEUE_H_
#define OSA_QUEUE_H_

#include "osa_types.h"

/* @{ */

/**
 *******************************************************************************
 * \brief Queue Flag: Do not block on que get and que put,
 *******************************************************************************
 */
#define OSA_UTILS_QUE_FLAG_NO_BLOCK_QUE    (0x00000000U)

/**
 *******************************************************************************
 * \brief Queue Flag: Block on que put if que is full
 *******************************************************************************
 */
#define OSA_UTILS_QUE_FLAG_BLOCK_QUE_PUT   (0x00000001U)

/**
 *******************************************************************************
 * \brief Queue Flag: Block on que get if que is empty
 *******************************************************************************
 */
#define OSA_UTILS_QUE_FLAG_BLOCK_QUE_GET   (0x00000002U)

/**
 *******************************************************************************
 * \brief Queue Flag: Block on que put if que is full, Block on que get if que
 *                    is empty
 *******************************************************************************
 */
#define OSA_UTILS_QUE_FLAG_BLOCK_QUE       (0x00000003U)

/* @} */

/*******************************************************************************
 *  Enum's
 *******************************************************************************
 */
typedef enum
{
  OSA_STATUS_SOK = 0x0,
  OSA_STATUS_EFAIL = -(int32)1,
  OSA_STATUS_ETIMEOUT = -(int32)2,
  OSA_STATUS_FORCE32BITS = 0x7FFFFFFFU
}Osa_ApiReturnCodes;


/**
 *******************************************************************************
 * \brief Queue Handle
 *
 *        Typically user does not need to know internals of queue handle
 *        data structure
 *******************************************************************************
*/
typedef struct {

  uint32 curRd;
  /**< Current read index */

  uint32 curWr;
  /**< Current write index  */

  uint32 count;
  /**< Count of element in queue  */

  uint32 maxElements;
  /**< Max elements that be present in the queue  */

  void **queue;
  /**< Address of data area of the queue elements */

  void *semRd;
  /**< Read semaphore */

  void  *semWr;
  /**< Write semaphore  */

  uint32 flags;
  /**< Controls how APIs behave internally, i.e blocking wait or non-blocking */

  volatile osa_bool blockedOnGet;
  /**< Flag indicating queue is blocked on get operation */

  volatile osa_bool blockedOnPut;
  /**< Flag indicating queue is blocked on put operation */

  volatile osa_bool forceUnblockGet;
  /**< Flag indicating forced unblock of queueGet */

  volatile osa_bool forceUnblockPut;
  /**< Flag indicating forced unblock of queuePut */

} osa_utils_quehandle;


/*******************************************************************************
 *  Functions
 *******************************************************************************
 */

/**
 *******************************************************************************
 *
 * \brief Create a queue handle
 *
 *        The size of queueMem allocated by the user should be
 *        maxElements*sizeof(Ptr)
 *
 * \param handle        [OUT] Initialized queue handle
 * \param maxElements   [IN]  Maximum elements that can reside in the queue
 *                             at any given point of time
 * \param queueMem      [IN]  Address of queue element data area
 * \param flags         [IN]  #UTILS_QUE_FLAG_NO_BLOCK_QUE or
 *                            #UTILS_QUE_FLAG_BLOCK_QUE_PUT or
 *                            #UTILS_QUE_FLAG_BLOCK_QUE_GET or
 *                            #OSA_UTILS_QUE_FLAG_BLOCK_QUE
 *
 * \return 0 on success, else failure
 *
 *******************************************************************************
 */
void osa_utils_quecreate(osa_utils_quehandle *handle,
                      uint32 maxElements, void *queueMem, uint32 flags);

/**
 *******************************************************************************
 *
 * \brief Delete queue handle
 *
 *        Releases all resources allocated during queue create
 *
 * \param handle        [IN] Queue handle
 *
 * \return 0 on success, else failure
 *
 *******************************************************************************
*/
int32 osa_utils_quedelete(osa_utils_quehandle *handle);


/**
 *******************************************************************************
 *
 * \brief Add a element into the queue
 *
 * \param handle   [IN] Queue Handle
 * \param data     [IN] data element to insert
 * \param timeout  [IN] osa_semaphore_no_wait: non-blocking,
 *                         if queue is full, error is returned\n
 *                      osa_semaphore_wait_forever: Blocking forever,
 *                         if queue is full function blocks until
 *                         atleast one element in the queue is free \n
 *                      Amount of time in units of OS ticks that
 *                         it should block: Error is returned if time
 *                          elaspes and no space is available in the queue
 *
 * \return 0 on success, else failure
 *
 *******************************************************************************
*/
int32 osa_utils_queput(osa_utils_quehandle *handle, void *data, uint32 timeout);

/**
 *******************************************************************************
 *
 * \brief Get a element from the queue
 *
 * \param handle   [IN]  Queue Handle
 * \param data     [OUT] Extracted data element from the queue
 * \param minCount [IN ] Data will be extracted only if
 *                       atleast 'minCount' elements are present in the queue
 * \param timeout  [IN] osa_semaphore_no_wait: non-blocking,
 *                         if queue is empty, error is returned\n
 *                      osa_semaphore_wait_forever: Blocking forever,
 *                         if queue is empty function blocks until
 *                         atleast one element in the queue is available \n
 *                      Amount of time in units of OS ticks that
 *                         it should block: Error is returned if time
 *                          elaspes and no element is available in the queue
 *
 * \return 0 on success, else failure
 *
 *******************************************************************************
 */
int32 osa_utils_queget(osa_utils_quehandle *handle, void **data,
                   uint32 minCount, uint32 timeout);

/**
 *******************************************************************************
 *
 * \brief Reset the Queue
 *
 * \param handle   [IN] Queue Handle
 *
 * \return 0 on success, else failure
 *
 *******************************************************************************
 */
int32 osa_utils_quereset(osa_utils_quehandle *handle);

/**
 *******************************************************************************
 *
 * \brief Returns TRUE if queue is empty else return false
 *
 * \param handle   [IN] Queue Handle
 *
 * \return Returns TRUE is queue is empty else return FALSE
 *
 *******************************************************************************
 */
uint32 osa_utils_queisempty(const osa_utils_quehandle * handle);

#endif /* OSA_QUEUE_H_ */
