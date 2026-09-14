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
 * \file        mml_gdc_sysinit.h
 * \brief       Driver Initialization Module
 *
 */

#ifndef MML_GDC_MML_GDC_SYSINIT_H
#define MML_GDC_MML_GDC_SYSINIT_H

/**
 * @defgroup sysinit Driver Initialization API
 * The Driver Initialization API exposes functions to initialize and uninitialize the driver.
 * @{
 **/

/*****************************************************************************/
/*** INCLUDES ****************************************************************/
/*****************************************************************************/

/*****************************************************************************/
/*** DEFINITIONS *************************************************************/
/*****************************************************************************/

#define MML_ERR_GDC_SYS_OUT_OF_SPACE            MM_ERRCODE(0xC00C0001)/*!< The system runs out of memory to perform this operation */
#define MML_ERR_GDC_SYS_INVALID_ADDRESS         MM_ERRCODE(0xC00C0002) /*!< Wrong address (For instance not aligned) */
#define MML_ERR_GDC_SYS_HARDWARE_ACCESS_ERROR   MM_ERRCODE(0xC00C0003) /*!< The underlaying HW driver reports an error */
#define MML_ERR_GDC_SYS_INVALID_CONFIGURATION   MM_ERRCODE(0xC00C0004) /*!< Try to use one hardware block in several pathes */
#define MML_ERR_GDC_SYS_COMMAND_QUEUE_FULL      MM_ERRCODE(0xC00C0005) /*!< Command queue full, no timeout set */
#define MML_ERR_GDC_SYS_COMMAND_QUEUE_TIMEOUT   MM_ERRCODE(0xC00C0006) /*!< Command queue full, timeout expired */
#define MML_ERR_GDC_SYS_WAIT_TIMEOUT            MM_ERRCODE(0xC00C0007) /*!< A synchronization instruction timed out */
#define MML_ERR_GDC_SYS_DEVICE_BUSY             MM_ERRCODE(0xC00C0008) /*!< Operation not possible, because the device is busy */
#define MML_ERR_GDC_SYS_DL_NO_FIFO              MM_ERRCODE(0xC00C0009) /*!< Cannot execute a display list if no FIFO is set */
#define MML_ERR_GDC_SYS_DL_NO_CLOSE             MM_ERRCODE(0xC00C000A) /*!< Tied to execute a list before closing it */
#define MML_ERR_GDC_SYS_INVALID_BUFFER_SIZE     MM_ERRCODE(0xC00C000B) /*!< Instruction buffer does not fit in memory or is not multiple of 4 bytes */
#define MML_ERR_GDC_SYS_INVALID_VALUE           MM_ERRCODE(0xC00C000C) /*!< Wrong parameter for this function */
#define MML_ERR_GDC_SYS_INVALID_OPERATION_MODE  MM_ERRCODE(0xC00C000D) /*!< Neither operation timeout nor instruction buffer set */
#define MML_ERR_GDC_SYS_INVALID_MATRIX          MM_ERRCODE(0xC00C000E) /*!< A matrix operation cannot performed */

/*****************************************************************************/
/*** TYPES / STRUCTURES ******************************************************/
/*****************************************************************************/


/*****************************************************************************/
/*** FUNCTIONS ***************************************************************/
/*****************************************************************************/
#ifdef __cplusplus
    extern "C"
    {
#endif

/**
 * [SWDD2010] Initialize the driver
 * \cond Related to SWAD000, SWAD201 \endcond
 *
 * Used to initialize the driver at startup. Applications must initialize the
 * driver before they can call other driver functions. This function must be
 * called by only one thread and is not guaranteed to be thread safe.
 * @param driverInitInfo (reserved for future use) Can be \e NULL or a pointer
 *                        to a GPU specific driver initialization structure.
 *  @return MML_OK on success. Otherwise the related error code.
 **/
IRIS_API MM_S32 mmlGdcSysInitializeDriver( void* driverInitInfo );

/**
 * [SWDD2030] Close the driver
 * \cond Related to SWAD000 \endcond

 * Used to shutdown the driver. Applications must uninitialize the
 * driver after calling ::mmlGdcSysInitializeDriver.
 * @return MML_OK on success. Otherwise the related error code.
 **/
IRIS_API MM_S32 mmlGdcSysUninitializeDriver( void );

/** @}*/

#ifdef __cplusplus
    }
#endif

#endif /* MML_GDC_MML_GDC_SYSINIT_H */
