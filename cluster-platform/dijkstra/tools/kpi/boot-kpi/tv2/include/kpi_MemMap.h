/***************************************************************************/
/**
 * \copyright
 *       VISTEON CORPORATION CONFIDENTIAL
 *       ________________________________
 *       [2024] Visteon Corporation
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
 * \file kpi_MemMap.h
 *
 * \brief
 * Visteon KPI Memory Map Header File
 *
 ******************************************************************************/

/* Memmap Files shall not have a guard */

/* Throw error in case last time we did not find the needed section */
#if (defined MEMMAP_ERROR) /* to prevent double definition */
    #error MEMMAP_ERROR defined, wrong MemMap.h usage
#endif /* defined(MEMMAP_ERROR) */

/* This macro is used for multiple section inclusion tracking. */
#define MEMMAP_ERROR

/*========================[DATA CLEARED UNSPECIFIED]========================*/

#ifdef KPI_START_SEC_VAR_UNSPECIFIED
    /* coverity[misra_c_2012_rule_20_5_violation] : FALSE */
    #undef KPI_START_SEC_VAR_UNSPECIFIED

    #ifndef MEMMAP_ERROR
        #error "MemMap error: Multiple sections selected."
    #endif /* !defined(MEMMAP_ERROR) */

    /* coverity[misra_c_2012_rule_20_5_violation] : FALSE */
    #undef MEMMAP_ERROR

    #ifdef MEMMAP_STARTED
        #error "MemMap error: Section started without stopping of previous section."
    #else /* !defined(MEMMAP_STARTED) */
        #define MEMMAP_STARTED

        #pragma ghs         startdata
        #pragma ghs section bss = ".bss_kpi_shared_memory"

    #endif /* defined(MEMMAP_STARTED) */

    #define KPI_START_SEC_VAR_UNSPECIFIED_STARTED

#endif /* defined(KPI_START_SEC_VAR_UNSPECIFIED) */

#ifdef KPI_STOP_SEC_VAR_UNSPECIFIED
    /* coverity[misra_c_2012_rule_20_5_violation] : FALSE */
    #undef KPI_STOP_SEC_VAR_UNSPECIFIED

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
        #pragma ghs         enddata

    #endif /* !defined(MEMMAP_STARTED) */

    #ifndef KPI_START_SEC_VAR_UNSPECIFIED_STARTED
        #error "MemMap error: Stop section does not match start section."
    #else /* defined(KPI_START_SEC_VAR_UNSPECIFIED_STARTED)                                                            \
           */
        /* coverity[misra_c_2012_rule_20_5_violation] : FALSE */
        #undef KPI_START_SEC_VAR_UNSPECIFIED_STARTED
    #endif /* !defined(KPI_START_SEC_VAR_UNSPECIFIED_STARTED)                                                          \
            */

#endif /* defined(KPI_STOP_SEC_VAR_UNSPECIFIED) */

/*========================[MemMap error checking]========================*/

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
