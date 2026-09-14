/*******************************************************************************
* Warranty and Disclaimer
*
* This software product is property of Cypress Semiconductor Corporation or
* its subsidiaries.
* Any use and/or distribution rights for this software product are provided
* only under the Cypress Software License Agreement.
* Any use and/or distribution of this software product not in accordance with
* the terms of the Cypress Software License Agreement are unauthorized and
* shall constitute an infringement of Cypress intellectual property rights.
*/
/******************************************************************************/

/**
 * \file        mm_defines.h
 * \ingroup     bg_interface
 * \brief       Common general macro definitions
 * Implements Building Block: Sysinit
 *
 */

#ifndef MM_DEFINES_H
#define MM_DEFINES_H

/*****************************************************************************/
/*** INCLUDES ****************************************************************/
/*****************************************************************************/

#ifdef __cplusplus
extern "C"
{
#endif

/**
 \defgroup mm_defines Macro Definition
 \brief Generic definitions for the driver 
*/
/** @{ */   /* PRQA S 292 */    /* <msr id=2> */

/*****************************************************************************/
/*** DEFINITIONS *************************************************************/
/*****************************************************************************/
/* PRQA S 3453 2 */ /* <msr id=1> */
#define MM_ERRCODE(err)                 ((MM_ERROR)(err))         /**< Macro to define the returned Error Code of the driver function */
#define MM_MODULEID(moduleId)           ((MM_MODULE)(moduleId))   /**< Macro to define the IDs of the driver modules */


#define MML_ERR       (MM_ERRCODE(0x3FFFFFFF))    /**< Abnormal termination (user space)   */
#define MMD_ERR       (MM_ERRCODE(0x7FFFFFFF))    /**< Abnormal termination (kernel space) */

#define MML_OK        (MM_ERRCODE(0x0))           /**< Normal termination (user space)   */
#define MMD_OK        (MM_ERRCODE(0x0))           /**< Normal termination (kernel space) */

#define MM_FALSE      ((MM_BOOL) 0)             /**< Definition of FALSE for bool types */
#define MM_TRUE       ((MM_BOOL) 1)             /**< Definition of TRUE for bool types */

#ifndef NULL
/* PRQA S 4600 1 */     /* <msr id=0 message="This is a define for new compilers (just in case of)."> */
#define NULL ((void *)0)  /**< Definition of NULL pointer */
#endif

/*
	Macros for bit manipulation in register
*/
/* PRQA S 3453 1 */ /* <msr id=1> */
#define MM_BIT(x)     (1u << (x))               /**< Set bit */

/*
	Macros for address translation
*/
 /* PRQA S 3453 11 */   /* <msr id=1> */
#define MM_PTR_TO_ADDR(x)           ((MM_ADDR)(x))    /**< Conversion: void* to MM_ADDR */
#define MM_ADDR_TO_PTR(x)           ((void*)(x))      /**< Conversion: "MM_ADDR" to "void*" */

#define MM_ADDR_TO_UINT32(x)        ((MM_U32)(x))     /**< Conversion: 'MM_ADDR' to 'MM_U32' */
#define MM_UINT32_TO_ADDR(x)        ((MM_ADDR)(x))    /**< Conversion: 'MM_U32' to 'MM_ADDR' */

#define MM_PTR_TO_UINT32(x)         ((MM_U32)(x))     /**< Conversion: 'void*' to 'MM_U32' */
#define MM_UINT32_TO_PTR(x)         ((void*)(x))      /**< Conversion: 'MM_U32' to 'void*' */

#define MM_ADDR_TO_UINT32PTR(x)    ((MM_U32*)(x))     /**< Conversion: 'MM_ADDR' to 'MM_U32*' */
#define MM_ADDR_TO_SINT32PTR(x)    ((MM_S32*)(x))     /**< Conversion: 'MM_ADDR' to 'MM_S32*' */

/*
	Memory map (physical address)
*/

#define MM_IO_IRIS_SUBSYSTEM        0x50200000u     /**< IRIS-SGP Subsystem Base Address */
#define MM_IO_IRIS_CORE             0x50200400u     /**< IRIS-MGP Core Base Address */

#define MM_VRAM_BASE                0x50000000u     /**< VRAM Base Address (see MCU_VRAM_BASE_ADDRESS in mcu_settings.h) */

/*
	Macro to handle differences between PRODUCTION and RELEASE&DEBUG configuration
*/
#ifndef PRQA
#define NULL_FUNCTION     ((void) 0)  /**< Helper macro for deactivated functions */
#endif

/*
	Mark parameter as unused 
*/
#ifndef PRQA
#define UNUSED_PARAMETER(x) ((void)(x))      /**< Helper macro for unused parameters */ 
#else
#define UNUSED_PARAMETER(x) NULL_FUNCTION  /**< Helper macro MISRA */
#endif

/** @} end defgroup */


#ifndef MIN
/* PRQA S 3453 1 */ /* <msr id=1> */
#define MIN(a,b) ( ((a)<(b)) ? (a) : (b) )      /**< Macro to evaluate the minimum value */
#endif /* MIN */

#ifndef MAX
/* PRQA S 3453 1 */ /* <msr id=1> */
#define MAX(a,b) ( ((a)>(b)) ? (a) : (b) )      /**< Macro to evaluate the maximum value */
#endif /* MAX */

#define MM_GDC_EXTERN extern                    /**< Macro for export changes */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MM_DEFINES_H */
