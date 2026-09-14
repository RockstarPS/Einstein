/*******************************************************************************
*
* This file contains the implementation of the Autosar
* memory mapping.
* See document "Specification of Memory Mapping"
*
* Any change might compromise the safety integrity level of
* the software partition it is contained in.
*
*******************************************************************************/
/*******************************************************************************
* Product: SW_TVII_SIG_DRV
*
* (c) 2017-2021, Cypress Semiconductor Corporation. All rights reserved.
*
* Warranty and Disclaimer
*
* This software product is property of Cypress Semiconductor Corporation or
* its subsidiaries.
* Any use and/or distribution rights for this software product are provided
* only under the Cypress Software License Agreement.
* Any use and/or distribution of this software product not in accordance with
* the terms of the Cypress Software License Agreement are unauthorized and
* shall constitute an infringement of Cypress intellectual property rights.
*
*******************************************************************************/
/*******************************************************************************
 ** \file CyFssig_MemMap.h
 **
 ** \date       09-Okt-2017 14:06:09
 ** \addtogroup Interface CyFssig
 **
*******************************************************************************/
/* Autosar, C Implementation Rules, deviation report:
 * - This file violates PROG_044.
 *   Reason:
 *      This file needs to be included more than once in a compilation unit
 */

/* qac-8.1.2: M3CM Rule-20.5 */
/* Justification: #undef to clear the macro definition of error detection necessary.
 */
/* PRQA S 841 EOF    */

/* qac-8.1.2: Rule-2.23 */
/* Justification: #ifdef to a macro previously #undef. This is necessary for error
 *                detection and due to multiple include of this file. Multiple include
 *                is required by AUTOSAR.
 */
/* PRQA S 890 EOF    */

/* qac-8.1.2: Rule-2.23 and M3CM Dir-1.1 */
/* Justification: #pragma needed to use to set specific linker sections.
 */
/* PRQA S  3116 EOF */

/*****************************************************************************/
/* Include files                                                             */
/*****************************************************************************/

/*****************************************************************************
 ** Global pre-processor symbols/macros ('#define')
 *****************************************************************************/

/*------------------[MemMap error checking]----------------------------------*/

/* qac-8.1.2: Rule-2.23 and M3CM Dir-4.10 */
/* Justification: File is not prevented against multiple include. This file must be
 *                included multiple times in a file. Required by AUTOSAR.
 */
/* PRQA S 883 1 */
#if (defined CYFSSIG_MEMMAP_ERROR) /* to prevent double definition */
    #error CYFSSIG_MEMMAP_ERROR defined, wrong MemMap.h usage
#endif /* if (defined CYFSSIG_MEMMAP_ERROR) */

/** \brief Checks if this file has been correctly used
 **
 ** This definition checks if this file has been correctly included
 ** the last time.
 */
#define CYFSSIG_MEMMAP_ERROR
/*      CYFSSIG_MEMMAP_TEST
        CYFSSIG_MEMMAP_TEST -----------[Changed default sections ]------------------
        CYFSSIG_MEMMAP_TEST Use the following sections to identify unmapped sections
        CYFSSIG_MEMMAP_TEST in CYFSSIG real default sections.
        CYFSSIG_MEMMAP_TEST Use key words "CYFSSIG_MEMMAP_TEST", "Unexpected" and ".CyFsSig"
        CYFSSIG_MEMMAP_TEST in order to find lines which have been added to the AUTOSAR
        CYFSSIG_MEMMAP_TEST version of the MemMap.h file.
        CYFSSIG_MEMMAP_TEST */
#ifndef CYFSSIG_MEMMAP_TEST
#define CYFSSIG_MEMMAP_TEST
    #pragma ghs section text=".cyfssigTextUnexpected"
    #pragma ghs section bss=".cyfssigBssUnexpected"
    #pragma ghs section data=".cyfssigDataUnexpected"
    #pragma ghs section rodata=".cyfssigRodataUnexpected"
#endif /* CYFSSIG_MEMMAP_TEST */


/*------------------[Start of module CYFSSIG ]--------------------------------------*/

#ifdef CYFSSIG_START_SEC_CODE_ASIL_B
    #undef CYFSSIG_START_SEC_CODE_ASIL_B
    #ifndef CYFSSIG_MEMMAP_ERROR
        #error "MemMap error: Multiple sections selected."
    #endif
    #undef CYFSSIG_MEMMAP_ERROR
    #ifdef CYFSSIG_MEMMAP_STARTED
        #error "MemMap error: Section started without stopping the previous section."
    #else
#define CYFSSIG_MEMMAP_STARTED
        #pragma ghs section text=".cyfssigText"
        #pragma ghs section bss=".cyfssigBssUnexpected"
        #pragma ghs section data=".cyfssigDataUnexpected"
        #pragma ghs section rodata=".cyfssigRodata"
    #endif
#define CYFSSIG_START_SEC_CODE_ASIL_B_STARTED
#endif

#ifdef CYFSSIG_STOP_SEC_CODE_ASIL_B
    #undef CYFSSIG_STOP_SEC_CODE_ASIL_B
    #ifndef CYFSSIG_MEMMAP_ERROR
        #error "MemMap error: Multiple sections selected."
    #endif
    #undef CYFSSIG_MEMMAP_ERROR
    #ifndef CYFSSIG_MEMMAP_STARTED
        #error "MemMap error: Section must be started before stopping."
    #else
        #undef CYFSSIG_MEMMAP_STARTED
        #pragma ghs section text=".cyfssigTextUnexpected"
        #pragma ghs section bss=".cyfssigBssUnexpected"
        #pragma ghs section data=".cyfssigDataUnexpected"
        #pragma ghs section rodata=".cyfssigRodataUnexpected"
    #endif
    #ifndef CYFSSIG_START_SEC_CODE_ASIL_B_STARTED
        #error "MemMap error: Stop section does not match the start section."
    #else
        #undef CYFSSIG_START_SEC_CODE_ASIL_B_STARTED
    #endif
#endif

#ifdef CYFSSIG_START_SEC_VAR_NO_INIT_ASIL_B_8
    #undef CYFSSIG_START_SEC_VAR_NO_INIT_ASIL_B_8
    #ifndef CYFSSIG_MEMMAP_ERROR
        #error "MemMap error: Multiple sections selected."
    #endif
    #undef CYFSSIG_MEMMAP_ERROR
    #ifdef CYFSSIG_MEMMAP_STARTED
        #error "MemMap error: Section started without stopping of the previous section."
    #else
#define CYFSSIG_MEMMAP_STARTED
        #pragma ghs section text=".cyfssigTextUnexpected"
        #pragma ghs section bss=".cyfssigBss"
        #pragma ghs section data=".cyfssigDataUnexpected"
        #pragma ghs section rodata=".cyfssigRodataUnexpected"
    #endif
#define CYFSSIG_START_SEC_VAR_NO_INIT_ASIL_B_8_STARTED
#endif

#ifdef CYFSSIG_STOP_SEC_VAR_NO_INIT_ASIL_B_8
    #undef CYFSSIG_STOP_SEC_VAR_NO_INIT_ASIL_B_8
    #ifndef CYFSSIG_MEMMAP_ERROR
        #error "MemMap error: Multiple sections selected."
    #endif
    #undef CYFSSIG_MEMMAP_ERROR
    #ifndef CYFSSIG_MEMMAP_STARTED
        #error "MemMap error: Section must be started before stopping."
    #else
        #undef CYFSSIG_MEMMAP_STARTED
        #pragma ghs section text=".cyfssigTextUnexpected"
        #pragma ghs section bss=".cyfssigBssUnexpected"
        #pragma ghs section data=".cyfssigDataUnexpected"
        #pragma ghs section rodata=".cyfssigRodataUnexpected"
    #endif
    #ifndef CYFSSIG_START_SEC_VAR_NO_INIT_ASIL_B_8_STARTED
        #error "MemMap error: Stop section does not match the start section."
    #else
        #undef CYFSSIG_START_SEC_VAR_NO_INIT_ASIL_B_8_STARTED
    #endif
#endif

#ifdef CYFSSIG_START_SEC_VAR_NO_INIT_ASIL_B_32
    #undef CYFSSIG_START_SEC_VAR_NO_INIT_ASIL_B_32
    #ifndef CYFSSIG_MEMMAP_ERROR
        #error "MemMap error: Multiple sections selected."
    #endif
    #undef CYFSSIG_MEMMAP_ERROR
    #ifdef CYFSSIG_MEMMAP_STARTED
        #error "MemMap error: Section started without stopping the previous section."
    #else
#define CYFSSIG_MEMMAP_STARTED
        #pragma ghs section text=".cyfssigTextUnexpected"
        #pragma ghs section bss=".cyfssigBss"
        #pragma ghs section data=".cyfssigDataUnexpected"
        #pragma ghs section rodata=".cyfssigRodataUnexpected"
    #endif
#define CYFSSIG_START_SEC_VAR_NO_INIT_ASIL_B_32_STARTED
#endif

#ifdef CYFSSIG_STOP_SEC_VAR_NO_INIT_ASIL_B_32
    #undef CYFSSIG_STOP_SEC_VAR_NO_INIT_ASIL_B_32
    #ifndef CYFSSIG_MEMMAP_ERROR
        #error "MemMap error: Multiple sections selected."
    #endif
    #undef CYFSSIG_MEMMAP_ERROR
    #ifndef CYFSSIG_MEMMAP_STARTED
        #error "MemMap error: Section must be started before stopping."
    #else
        #undef CYFSSIG_MEMMAP_STARTED
        #pragma ghs section text=".cyfssigTextUnexpected"
        #pragma ghs section bss=".cyfssigBssUnexpected"
        #pragma ghs section data=".cyfssigDataUnexpected"
        #pragma ghs section rodata=".cyfssigRodataUnexpected"
    #endif
    #ifndef CYFSSIG_START_SEC_VAR_NO_INIT_ASIL_B_32_STARTED
        #error "MemMap error: Stop section does not match the start section."
    #else
        #undef CYFSSIG_START_SEC_VAR_NO_INIT_ASIL_B_32_STARTED
    #endif
#endif

#ifdef CYFSSIG_START_SEC_CONST_ASIL_B_8
    #undef CYFSSIG_START_SEC_CONST_ASIL_B_8
    #ifndef CYFSSIG_MEMMAP_ERROR
        #error "MemMap error: Multiple sections selected."
    #endif
    #undef CYFSSIG_MEMMAP_ERROR
    #ifdef CYFSSIG_MEMMAP_STARTED
        #error "MemMap error: Section started without stopping the previous section."
    #else
#define CYFSSIG_MEMMAP_STARTED
        #pragma ghs section text=".cyfssigTextUnexpected"
        #pragma ghs section bss=".cyfssigBssUnexpected"
        #pragma ghs section data=".cyfssigDataUnexpected"
        #pragma ghs section rodata=".cyfssigRodata"
    #endif
#define CYFSSIG_START_SEC_CONST_ASIL_B_8_STARTED
#endif

#ifdef CYFSSIG_STOP_SEC_CONST_ASIL_B_8
    #undef CYFSSIG_STOP_SEC_CONST_ASIL_B_8
    #ifndef CYFSSIG_MEMMAP_ERROR
        #error "MemMap error: Multiple sections selected."
    #endif
    #undef CYFSSIG_MEMMAP_ERROR
    #ifndef CYFSSIG_MEMMAP_STARTED
        #error "MemMap error: Section must be started before stopping."
    #else
        #undef CYFSSIG_MEMMAP_STARTED
        #pragma ghs section text=".cyfssigTextUnexpected"
        #pragma ghs section bss=".cyfssigBssUnexpected"
        #pragma ghs section data=".cyfssigDataUnexpected"
        #pragma ghs section rodata=".cyfssigRodataUnexpected"
    #endif
    #ifndef CYFSSIG_START_SEC_CONST_ASIL_B_8_STARTED
        #error "MemMap error: Stop section does not match the start section."
    #else
        #undef CYFSSIG_START_SEC_CONST_ASIL_B_8_STARTED
    #endif
#endif

#ifdef CYFSSIG_START_SEC_CONST_ASIL_B_16
    #undef CYFSSIG_START_SEC_CONST_ASIL_B_16
    #ifndef CYFSSIG_MEMMAP_ERROR
        #error "MemMap error: Multiple sections selected."
    #endif
    #undef CYFSSIG_MEMMAP_ERROR
    #ifdef CYFSSIG_MEMMAP_STARTED
        #error "MemMap error: Section started without stopping the previous section."
    #else
#define CYFSSIG_MEMMAP_STARTED
        #pragma ghs section text=".cyfssigTextUnexpected"
        #pragma ghs section bss=".cyfssigBssUnexpected"
        #pragma ghs section data=".cyfssigDataUnexpected"
        #pragma ghs section rodata=".cyfssigRodata"
    #endif
#define CYFSSIG_START_SEC_CONST_ASIL_B_16_STARTED
#endif

#ifdef CYFSSIG_STOP_SEC_CONST_ASIL_B_16
    #undef CYFSSIG_STOP_SEC_CONST_ASIL_B_16
    #ifndef CYFSSIG_MEMMAP_ERROR
        #error "MemMap error: Multiple sections selected."
    #endif
    #undef CYFSSIG_MEMMAP_ERROR
    #ifndef CYFSSIG_MEMMAP_STARTED
        #error "MemMap error: Section must be started before stopping."
    #else
        #undef CYFSSIG_MEMMAP_STARTED
        #pragma ghs section text=".cyfssigTextUnexpected"
        #pragma ghs section bss=".cyfssigBssUnexpected"
        #pragma ghs section data=".cyfssigDataUnexpected"
        #pragma ghs section rodata=".cyfssigRodataUnexpected"
    #endif
    #ifndef CYFSSIG_START_SEC_CONST_ASIL_B_16_STARTED
        #error "MemMap error: Stop section does not match the start section."
    #else
        #undef CYFSSIG_START_SEC_CONST_ASIL_B_16_STARTED
    #endif
#endif

#ifdef CYFSSIG_START_SEC_CONST_ASIL_B_32
    #undef CYFSSIG_START_SEC_CONST_ASIL_B_32
    #ifndef CYFSSIG_MEMMAP_ERROR
        #error "MemMap error: Multiple sections selected."
    #endif
    #undef CYFSSIG_MEMMAP_ERROR
    #ifdef CYFSSIG_MEMMAP_STARTED
        #error "MemMap error: Section started without stopping the previous section."
    #else
#define CYFSSIG_MEMMAP_STARTED
        #pragma ghs section text=".cyfssigTextUnexpected"
        #pragma ghs section bss=".cyfssigBssUnexpected"
        #pragma ghs section data=".cyfssigDataUnexpected"
        #pragma ghs section rodata=".cyfssigRodata"
    #endif
#define CYFSSIG_START_SEC_CONST_ASIL_B_32_STARTED
#endif

#ifdef CYFSSIG_STOP_SEC_CONST_ASIL_B_32
    #undef CYFSSIG_STOP_SEC_CONST_ASIL_B_32
    #ifndef CYFSSIG_MEMMAP_ERROR
        #error "MemMap error: Multiple sections selected."
    #endif
    #undef CYFSSIG_MEMMAP_ERROR
    #ifndef CYFSSIG_MEMMAP_STARTED
        #error "MemMap error: Section must be started before stopping."
    #else
        #undef CYFSSIG_MEMMAP_STARTED
        #pragma ghs section text=".cyfssigTextUnexpected"
        #pragma ghs section bss=".cyfssigBssUnexpected"
        #pragma ghs section data=".cyfssigDataUnexpected"
        #pragma ghs section rodata=".cyfssigRodataUnexpected"
    #endif
    #ifndef CYFSSIG_START_SEC_CONST_ASIL_B_32_STARTED
        #error "MemMap error: Stop section does not match the start section."
    #else
        #undef CYFSSIG_START_SEC_CONST_ASIL_B_32_STARTED
    #endif
#endif

#ifdef CYFSSIG_START_SEC_VAR_INIT_ASIL_B_32
    #undef CYFSSIG_START_SEC_VAR_INIT_ASIL_B_32
    #ifndef CYFSSIG_MEMMAP_ERROR
        #error "MemMap error: Multiple sections selected."
    #endif
    #undef CYFSSIG_MEMMAP_ERROR
    #ifdef CYFSSIG_MEMMAP_STARTED
        #error "MemMap error: Section started without stopping the previous section."
    #else
#define CYFSSIG_MEMMAP_STARTED
        #pragma ghs section text=".cyfssigTextUnexpected"
        #pragma ghs section bss=".cyfssigBssUnexpected"
        #pragma ghs section data=".cyfssigData"
        #pragma ghs section rodata=".cyfssigRodataUnexpected"
    #endif
#define CYFSSIG_START_SEC_VAR_INIT_ASIL_B_32_STARTED
#endif

#ifdef CYFSSIG_STOP_SEC_VAR_INIT_ASIL_B_32
    #undef CYFSSIG_STOP_SEC_VAR_INIT_ASIL_B_32
    #ifndef CYFSSIG_MEMMAP_ERROR
        #error "MemMap error: Multiple sections selected."
    #endif
    #undef CYFSSIG_MEMMAP_ERROR
    #ifndef CYFSSIG_MEMMAP_STARTED
        #error "MemMap error: Section must be started before stopping."
    #else
        #undef CYFSSIG_MEMMAP_STARTED
        #pragma ghs section text=".cyfssigTextUnexpected"
        #pragma ghs section bss=".cyfssigBssUnexpected"
        #pragma ghs section data=".cyfssigDataUnexpected"
        #pragma ghs section rodata=".cyfssigRodataUnexpected"
    #endif
    #ifndef CYFSSIG_START_SEC_VAR_INIT_ASIL_B_32_STARTED
        #error "MemMap error: Stop section does not match the start section."
    #else
        #undef CYFSSIG_START_SEC_VAR_INIT_ASIL_B_32_STARTED
    #endif
#endif

/*------------------[MemMap error checking]----------------------------------*/

#if (defined CYFSSIG_MEMMAP_ERROR) /* To prevent double definition */
    #error CYFSSIG_MEMMAP_ERROR defined, wrong CyFsSig_MemMap.h usage
#endif /* If (defined CYFSSIG_MEMMAP_ERROR) */

/*****************************************************************************
 ** Global type definitions ('typedef')
 *****************************************************************************/

/*****************************************************************************
 ** Global variable declarations ('extern', definition in C source)
 *****************************************************************************/
