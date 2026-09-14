/*
 * Copyright (c) 2019 Samsung Electronics Co., Ltd All Rights Reserved
 *
 * PROPRIETARY/CONFIDENTIAL
 *
 * This software is the confidential and proprietary information of
 * SAMSUNG ELECTRONICS ("Confidential Information").
 *
 * You shall not disclose such Confidential Information and shall use it
 * only in accordance with the terms of the license agreement
 * you entered into with SAMSUNG ELECTRONICS.
 *
 * SAMSUNG make no representations or warranties about the suitability of
 * the software, either express or implied, including but not limited to
 * the implied warranties of merchantability, fitness for a particular
 * purpose, or non-infringement. SAMSUNG shall not be liable for any
 * damages suffered by licensee as a result of using, modifying or
 * distributing this software or its derivatives.
 */

/**
 * @file    CDD_Comapt.h
 * @brief   header file for functions that support CDD compatibility on other
 *          platforms
 * @ingroup Common
 */

#ifndef __CDD_COMPAT_H__
#define __CDD_COMPAT_H__

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string.h>
#include "Std_Types.h"

/*******************************************************************************
 * Typedef Definitions
 ******************************************************************************/
/** @brief variable type for mutex handle */
typedef void                   *Compat_CacheInvalidateType;
typedef uint32                  Compat_IrqNumType;
typedef uint32                  Compat_IrqStsType;

/*******************************************************************************
 * Function Prototypes
 ******************************************************************************/
/** @cond HIDDEN */
extern void Compat_CleanInvalidateCache(Compat_CacheInvalidateType start, Compat_CacheInvalidateType end);
extern void Compat_Isb(void);
extern void Compat_Dmb(void);
extern uint8 Compat_Get_Cpuid(void);
/** @endcond */

/*******************************************************************************
 * Defines / Macros
 ******************************************************************************/
/** @brief unused macro */
#define COMPAT_UNUSED(Arg)          ((void)(Arg))

/*******************************
  Debug Print
********************************/
#if defined(DEBUG_PRINT_SUPPORT)
#include <stdio.h>
#define COMPAT_PRINTF(...)          (void)printf(__VA_ARGS__)
#else
#define COMPAT_PRINTF(...)
#endif

/*******************************
  Memory Operation
********************************/
/**
 * @brief This is the macro of the function that fills the first n bytes
 *        of the memory area pointed to by s with the constant byte c.
 */
#define COMPAT_MEMSET(MemPtr, Val, Num)         (void)memset(((void *)(MemPtr)), ((sint32)(Val)), ((size_t)(Num)))

/**
 * @brief This is the macro of the function that copies Num bytes from memory
 *        area SrcPtr to memory area DstPtr.
 */
#define COMPAT_MEMCPY(DstPtr, SrcPtr, Num)      (void)memcpy(((void *)(DstPtr)), ((const void *)(SrcPtr)), ((size_t)(Num)))

/**
 * @brief This is the macro of the function that compares the first Num bytes
 *        of the memory areas Mem1Ptr and Mem2Ptr.
 */
#define COMPAT_MEMCMP(Mem1Ptr, Mem2Ptr, Num)    (sint32)memcmp(((const void *)(Mem1Ptr)), ((const void *)(Mem2Ptr)), ((size_t)(Num)))

/*******************************
  Cache Operation
********************************/
/**
 * @brief This macro invalide cache for adress range.
 */
#define COMPAT_CLEANINVALIDATECACHE(start,end)   Compat_CleanInvalidateCache(start,end)

/*******************************
  Ethernet PHY Operation
********************************/
/**
 * @brief This macro reset ethernet external PHY
 */
#define COMPAT_RESET_ETH_PHY(ethModule)

/*******************************
  Barrier Operation
********************************/
/**
 * @brief This macro operates isb instruction
 */
#define COMPAT_ISB()      Compat_Isb()

/**
 * @brief This macro operates dmb instruction (ish option)
 */
#define COMPAT_DMB()      Compat_Dmb()

#endif /* __CDD_COMPAT_H__ */
