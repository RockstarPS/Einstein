/***************************************************************************/
/**
 * \copyright
 *       VISTEON CORPORATION CONFIDENTIAL
 *       ________________________________
 *       [2021] Visteon Corporation
 *       All Rights Reserved.
 *       NOTICE: This is an unpublished work of authorship, which contains trade
 *               secrets. Visteon Corporation owns all rights to this work and
 *               intends to maintain it in confidence to preserve its trade
 *               secret status. Visteon Corporation reserves the right, under
 *               the copyright laws of the United States or those of any other
 *               country that may have jurisdiction, to protect this work as an
 *               unpublished work, in the event of an inadvertent or deliberate
 *               unauthorized publication. Visteon Corporation also reserves
 *               its rights under all copyright laws to protect this work as a
 *               published work, when appropriate. Those having access to this
 *               work may not copy it, use it, modify it, or disclose the
 *               information contained in it without the written authorization
 *               of Visteon Corporation.
 *
 * \file CryptoCdd_MemMap.h
 *
 * \brief
 * Crypto CDD Memory Map Header File
 *
 * \authors
 *          Name                     | CDSID     | Location
 *          ------------------------ | --------- | --------
 *          Akshay Krishna Upendran  | akrish10  | VTSC, Chennai, India
 *          James, Sneha (S.)        | sjames4   | VTSC, Bengaluru, India
 *          Geetha A Krishna         | kgeethaa  | VTSC, Bengaluru, India
 *          Shanmugam Karthik        | kshanmu4  | VTSC, Chennai, India
 ******************************************************************************/

/* Memmap Files shall not have a guard */

/* Throw error in case last time we did not find the needed section */
#if (defined MEMMAP_ERROR) /* to prevent double definition */
#error MEMMAP_ERROR defined, wrong MemMap.h usage
#endif /* defined(MEMMAP_ERROR) */

/* This macro is used for multiple section inclusion tracking. */
#define MEMMAP_ERROR

/*===============================[CODE LOCAL]===============================*/
/**
 * \def CRYPTOCDD_START_SEC_CODE_QM_LOCAL
 * Starts the CRYPTOCDD Code Section.
 */
#ifdef CRYPTOCDD_START_SEC_CODE_QM_LOCAL
/* coverity[misra_c_2012_rule_20_5_violation] : FALSE */
#undef CRYPTOCDD_START_SEC_CODE_QM_LOCAL

#ifndef MEMMAP_ERROR
#error "MemMap error: Multiple sections selected."
#endif /* !defined(MEMMAP_ERROR) */

/* coverity[misra_c_2012_rule_20_5_violation] : FALSE */
#undef MEMMAP_ERROR

#ifdef MEMMAP_STARTED
#error "MemMap error: Section started without stopping of previous section."
#else /* !defined(MEMMAP_STARTED) */
#define MEMMAP_STARTED

#pragma ghs section text   = ".text_cryptocdd"
#pragma ghs section rodata = ".rodata_cryptocdd"

#endif /* defined(MEMMAP_STARTED) */

#define CRYPTOCDD_START_SEC_CODE_QM_LOCAL_STARTED

#endif /* defined(CRYPTOCDD_START_SEC_CODE_QM_LOCAL) */

#ifdef CRYPTOCDD_STOP_SEC_CODE_QM_LOCAL
/* coverity[misra_c_2012_rule_20_5_violation] : FALSE */
#undef CRYPTOCDD_STOP_SEC_CODE_QM_LOCAL

#ifndef MEMMAP_ERROR
#error "MemMap error: Multiple sections selected."
#endif /* !defined(MEMMAP_ERROR) */

/* coverity[misra_c_2012_rule_20_5_violation] : FALSE */
#undef MEMMAP_ERROR

#ifndef MEMMAP_STARTED
#error "MemMap error: Section must be started before stopping."
#else /* defined(MEMMAP_STARTED) */
/* coverity[misra_c_2012_rule_20_5_violation] : FALSE */
#undef MEMMAP_STARTED

#pragma ghs section text   = default
#pragma ghs section rodata = default

#endif /* !defined(MEMMAP_STARTED) */

#ifndef CRYPTOCDD_START_SEC_CODE_QM_LOCAL_STARTED
#error "MemMap error: Stop section does not match start section."
#else /* defined(CRYPTOCDD_START_SEC_CODE_QM_LOCAL_STARTED) */
/* coverity[misra_c_2012_rule_20_5_violation] : FALSE */
#undef CRYPTOCDD_START_SEC_CODE_QM_LOCAL_STARTED
#endif /* !defined(CRYPTOCDD_START_SEC_CODE_QM_LOCAL_STARTED) */

#endif /* defined(CRYPTOCDD_STOP_SEC_CODE_QM_LOCAL) */

/*========================[DATA CLEARED UNSPECIFIED]========================*/

#ifdef CRYPTOCDD_START_SEC_VAR_CLEARED_QM_LOCAL_UNSPECIFIED
/* coverity[misra_c_2012_rule_20_5_violation] : FALSE */
#undef CRYPTOCDD_START_SEC_VAR_CLEARED_QM_LOCAL_UNSPECIFIED

#ifndef MEMMAP_ERROR
#error "MemMap error: Multiple sections selected."
#endif /* !defined(MEMMAP_ERROR) */

/* coverity[misra_c_2012_rule_20_5_violation] : FALSE */
#undef MEMMAP_ERROR

#ifdef MEMMAP_STARTED
#error "MemMap error: Section started without stopping of previous section."
#else /* !defined(MEMMAP_STARTED) */
#define MEMMAP_STARTED

#pragma ghs section bss = ".bss_cryptocdd"

#endif /* defined(MEMMAP_STARTED) */

#define CRYPTOCDD_START_SEC_VAR_CLEARED_QM_LOCAL_UNSPECIFIED_STARTED

#endif /* defined(CRYPTOCDD_START_SEC_VAR_CLEARED_QM_LOCAL_UNSPECIFIED) */

#ifdef CRYPTOCDD_STOP_SEC_VAR_CLEARED_QM_LOCAL_UNSPECIFIED
/* coverity[misra_c_2012_rule_20_5_violation] : FALSE */
#undef CRYPTOCDD_STOP_SEC_VAR_CLEARED_QM_LOCAL_UNSPECIFIED

#ifndef MEMMAP_ERROR
#error "MemMap error: Multiple sections selected."
#endif /* !defined(MEMMAP_ERROR) */

/* coverity[misra_c_2012_rule_20_5_violation] : FALSE */
#undef MEMMAP_ERROR

#ifndef MEMMAP_STARTED
#error "MemMap error: Section must be started before stopping."
#else /* defined(MEMMAP_STARTED) */
/* coverity[misra_c_2012_rule_20_5_violation] : FALSE */
#undef MEMMAP_STARTED

#pragma ghs section bss = default

#endif /* !defined(MEMMAP_STARTED) */

#ifndef CRYPTOCDD_START_SEC_VAR_CLEARED_QM_LOCAL_UNSPECIFIED_STARTED
#error "MemMap error: Stop section does not match start section."
#else /* defined(CRYPTOCDD_START_SEC_VAR_CLEARED_QM_LOCAL_UNSPECIFIED_STARTED)                                         \
       */
/* coverity[misra_c_2012_rule_20_5_violation] : FALSE */
#undef CRYPTOCDD_START_SEC_VAR_CLEARED_QM_LOCAL_UNSPECIFIED_STARTED
#endif /* !defined(CRYPTOCDD_START_SEC_VAR_CLEARED_QM_LOCAL_UNSPECIFIED_STARTED)                                       \
        */

#endif /* defined(CRYPTOCDD_STOP_SEC_VAR_CLEARED_QM_LOCAL_UNSPECIFIED) */

/*==========================[DATA CLEARED UINT32]===========================*/

#ifdef CRYPTOCDD_START_SEC_VAR_CLEARED_QM_LOCAL_UINT32
/* coverity[misra_c_2012_rule_20_5_violation] : FALSE */
#undef CRYPTOCDD_START_SEC_VAR_CLEARED_QM_LOCAL_UINT32

#ifndef MEMMAP_ERROR
#error "MemMap error: Multiple sections selected."
#endif /* !defined(MEMMAP_ERROR) */

/* coverity[misra_c_2012_rule_20_5_violation] : FALSE */
#undef MEMMAP_ERROR

#ifdef MEMMAP_STARTED
#error "MemMap error: Section started without stopping of previous section."
#else /* !defined(MEMMAP_STARTED) */
#define MEMMAP_STARTED

#pragma ghs section bss = ".bss_cryptocdd"

#endif /* defined(MEMMAP_STARTED) */

#define CRYPTOCDD_START_SEC_VAR_CLEARED_QM_LOCAL_UINT32_STARTED

#endif /* defined(CRYPTOCDD_START_SEC_VAR_CLEARED_QM_LOCAL_UINT32) */

#ifdef CRYPTOCDD_STOP_SEC_VAR_CLEARED_QM_LOCAL_UINT32
/* coverity[misra_c_2012_rule_20_5_violation] : FALSE */
#undef CRYPTOCDD_STOP_SEC_VAR_CLEARED_QM_LOCAL_UINT32

#ifndef MEMMAP_ERROR
#error "MemMap error: Multiple sections selected."
#endif /* !defined(MEMMAP_ERROR) */

/* coverity[misra_c_2012_rule_20_5_violation] : FALSE */
#undef MEMMAP_ERROR

#ifndef MEMMAP_STARTED
#error "MemMap error: Section must be started before stopping."
#else /* defined(MEMMAP_STARTED) */
/* coverity[misra_c_2012_rule_20_5_violation] : FALSE */
#undef MEMMAP_STARTED

#pragma ghs section bss = default

#endif /* !defined(MEMMAP_STARTED) */

#ifndef CRYPTOCDD_START_SEC_VAR_CLEARED_QM_LOCAL_UINT32_STARTED
#error "MemMap error: Stop section does not match start section."
#else /* defined(CRYPTOCDD_START_SEC_VAR_CLEARED_QM_LOCAL_UINT32_STARTED) */
/* coverity[misra_c_2012_rule_20_5_violation] : FALSE */
#undef CRYPTOCDD_START_SEC_VAR_CLEARED_QM_LOCAL_UINT32_STARTED
#endif /* !defined(CRYPTOCDD_START_SEC_VAR_CLEARED_QM_LOCAL_UINT32_STARTED) */

#endif /* defined(CRYPTOCDD_STOP_SEC_VAR_CLEARED_QM_LOCAL_UINT32) */

/*------------------[MemMap error checking]----------------------------------*/

#if (defined MEMMAP_ERROR) /* to prevent double definition */
#error MEMMAP_ERROR defined, wrong MemMap.h usage
#endif /* defined(MEMMAP_ERROR) */

/*****************************************************************************
 MISRA violations and justifications
 *****************************************************************************/
/* module specific MISRA deviations:
 * 1. misra_c_2012_rule_20_5_violation: Using "#undef".
 * Reason:     Undef is needed in MemMap.
 * Risk:       No functional risk.
 * Prevention: Not required.
 */

/******************************************************************************
 *  REVISION HISTORY
 *  ---------------------------------------------------------------------------
 *  Refer to the module's public header file.
 *
 *  MODULE VERSION
 *  ---------------------------------------------------------------------------
 *  Refer to the VERSION INFORMATION SECTION in module's internal header file.
 ******************************************************************************/

/* EOF */
