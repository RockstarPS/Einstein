/********************************************************************/
/*          (c) 2011 Fujitsu Semiconductor Europe GmbH              */
/*                                                                  */
/* ALL RIGHTS RESERVED. No part of this publication may be copied   */
/* and provided to any third party in any form or by any means      */
/* without the written permission of Fujitsu, unless expressly      */
/* agreed to in written form by Fujitsu.                            */
/* All trademarks used in this document are the property of their   */
/* respective owners.                                               */
/*                                                                  */
/* For further provisions please refer to the respective License    */
/* Agreement.                                                       */
/* (V1.3)                                                           */
/********************************************************************/

/*!
 * \author      Fujitsu GCC Neuried
 * \version     0.01
 * \date        2011
 * \file        mml_gdc_sync.h
 * \brief       Synchronization interface
 *
 */

#ifndef MML_GDC_SYNC_H
#define MML_GDC_SYNC_H

/*****************************************************************************/
/*** INCLUDES ****************************************************************/
/*****************************************************************************/

/*****************************************************************************/
/*** DEFINITIONS *************************************************************/
/*****************************************************************************/

/**
 * \defgroup sync_api Synchronization API
 *  The Synchronization API provides mechanisms to synchronize:\n
 *  - Blit operations
 *  - Display
 *
 * @{
 */

#define MML_ERR_GDC_SYNC_INVALID_PARAMETER  MM_ERRCODE(0xC00C0801) /*!< Invalid parameter */
#define MML_ERR_GDC_SYNC_OUT_OF_MEMORY      MM_ERRCODE(0xC00C0802) /*!< Out of memory */
#define MML_ERR_GDC_SYNC_TIMEOUT            MM_ERRCODE(0xC00C0803) /*!< Timeout expired */
#define MML_ERR_GDC_SYNC_INVALID            MM_ERRCODE(0xC00C0804) /*!< Invalid sync object */
#define MML_ERR_GDC_SYNC_INVALID_TIMEOUT    MM_ERRCODE(0xC00C0805) /*!< The timeout parameter is invalid */

/*****************************************************************************/
/*** TYPES / STRUCTURES ******************************************************/
/*****************************************************************************/

/*! Sync object.
 */
typedef MM_U32 *MML_GDC_SYNC;
typedef MM_U32 MML_GDC_SYNC_CONTAINER;


/*****************************************************************************/
/*** FUNCTIONS ***************************************************************/
/*****************************************************************************/
#ifdef __cplusplus
    extern "C"
    {
#endif

/**
 * [SWDD2210] Display completed send frame synchronization
 *
 * \cond Related to SWAD000, SWAD202 \endcond
 *
 * mmlGdcSyncForDispFrameEnd adds an instruction to the command list
 * to disturb the command list execution until the current frame
 * reads the last visible pixel for the current frame.
 * It can be used to start rendering with a single render buffer solution.
 **/
IRIS_API MM_S32 mmlGdcSyncForDispFrameEnd(void);

/**
 * [SWDD2211] Add sync to finish all display updates
 *
 * \cond Related to SWAD000, SWAD202 \endcond
 *
 * mmlGdcSyncForDispReady adds an instruction to the command list
 * to disturb the command list execution until all display
 * related updates are compleate. It can be used in a
 * multi render buffer solution to start
 * further drawing functions without impact to the current view.
 * \note mmlGdcSyncForDispReady does has no effect if the
 * display attribut MML_GDC_DISP_ATTR_ENABLE_VSYNC is set to
 * MM_FALSE.
 **/
IRIS_API MM_S32 mmlGdcSyncForDispReady(void);


/**
 * [SWDD2230] Waits for a sync object to be signaled.\n
 * \cond Related to SWAD000, SWAD202 \endcond
 *
 * @param sync       Sync object to wait for getting signaled
 * @param timeout    reserved: This parameter must be 0\n
 *
 * @return MML_OK if success, #MML_ERR_GDC_SYNC_TIMEOUT
 *    indicates that the sync item was not yet passed,
 *    MML_ERR_GDC_SYNC_INVALID is returned if the sync item is invalid.
 */
MM_S32 mmlGdcSyncWait(const MML_GDC_SYNC sync, MM_S32 timeout);

/** @}*/

#ifdef __cplusplus
    }
#endif

#endif /* MML_GDC_SYNC_H */
