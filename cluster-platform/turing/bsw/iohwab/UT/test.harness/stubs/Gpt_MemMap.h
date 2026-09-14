/**
*   @file           Gpt_MemMap.h
*   @implements     MemMap.h_Artifact
*   @version 4.0.0
*
*   @brief   AUTOSAR Base - Memory mapping specification.
*   @details This document specifies mechanisms for the mapping of code and data to specific
*            memory sections via memory mapping file. For many ECUs and microcontroller platforms
*            it is of utmost necessity to be able to map code, variables and constants module
*            wise to specific memory sections.
*            This file contains sample code only. It is not part of the production code deliverables
*   @addtogroup BASE_COMPONENT
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : IMX8
*   Dependencies         : none
*
*   Autosar Version      : 4.2.2
*   Autosar Revision     : ASR_REL_4_2_REV_0002
*   Autosar Conf.Variant :
*   SW Version           : 4.0.0
*   Build Version        : IMX8_MCAL_4_0_0_RTM_ASR_REL_4_2_REV_0002_20201231
*
*   Copyright 2006-2016 Freescale Semiconductor, Inc. 
*   Copyright 2017 - 2020 NXP
*   NXP Confidential. This software is owned or controlled by NXP and may only be 
*   used strictly in accordance with the applicable license terms.  By expressly 
*   accepting such terms or by downloading, installing, activating and/or otherwise 
*   using the software, you are agreeing that you have read, and that you agree to 
*   comply with and are bound by, such license terms.  If you do not agree to be 
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/
#ifdef __cplusplus
extern "C"{
#endif
/**
* @page misra_violations MISRA-C:2004 violations
* @section Gpt_MemMap_h_REF_1
* Violates MISRA 2004 Required Rule 19.6, #undef shall not be used.
* This is due to #undef MEMMAP_ERROR and #undef <section_type> and cannot be removed as it is
* required by Autosar Specification - Specification of Memory Mapping.
* @section Gpt_MemMap_h_REF_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header being included twice.
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
* @section Gpt_MemMap_h_REF_3
* Violates MISRA 2004 Advisory Rule 19.1, #include statements in a file should only be preceded by
* other preprocessor directives or comments.
* This comes from the order of includes in the .c. MemMap is required by AutoSAR to be included in
* the middle of the source file(s).
* @section [global] 
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely  on the significance of more than 31 characters. All compilers used support more than 31 chars for identifiers.
* @section [global] 
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that 31 character significance and case  sensitivity are supported for external identifiers. This violation is due to the naming convention for the memory ssections.
* @section [global] 
* Violates MISRA 2004 Required Rule 3.4, All uses of the pragma directive shall be documented and explained. The pragma directives are used MemMap.h file to define memory sections.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/*
* @violates @ref Gpt_MemMap_h_REF_2 Precautions shall be taken in order
* to prevent the contents of a header being included twice.
*/
/* @violates @ref Gpt_MemMap_h_REF_3 #include statements in a file should
* only be preceded by other preprocessor directives or comments.
*/
#include "CompilerDefinition.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @{
* @brief Parameters that shall be published within the memory map header file and also in the
*       module's description file
*/
#define GPT_MEMMAP_VENDOR_ID                    43
#define GPT_MEMMAP_AR_RELEASE_MAJOR_VERSION     4
#define GPT_MEMMAP_AR_RELEASE_MINOR_VERSION     2
#define GPT_MEMMAP_AR_RELEASE_REVISION_VERSION  2
#define GPT_MEMMAP_SW_MAJOR_VERSION             4
#define GPT_MEMMAP_SW_MINOR_VERSION             0
#define GPT_MEMMAP_SW_PATCH_VERSION             0
/**@}*/
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/


/**
* @brief Symbol used for checking correctness of the includes
* @implements Module_MemMap_h_Artifact
*/
#define MEMMAP_ERROR

#ifndef AUTOSAR_OS_NOT_USED
        #include "Os_memmap.h"
#endif
/**************************************************************************************************/
/********************************************* GREENHILLS *****************************************/
/**************************************************************************************************/
#ifdef _GREENHILLS_C_IMX8_
/**************************************** GPT *******************************/
#ifdef GPT_START_SEC_CONFIG_DATA_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma ghs section rodata=".mcal_const_cfg"
    #else
        #ifndef GPT_STOP_SEC_CONFIG_DATA_8
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONFIG_DATA_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONFIG_DATA_8
        #undef GPT_START_SEC_CONFIG_DATA_8
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma ghs section
    #endif
    #undef GPT_STOP_SEC_CONFIG_DATA_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CONFIG_DATA_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma ghs section rodata=".mcal_const_cfg"
    #else
        #ifndef GPT_STOP_SEC_CONFIG_DATA_16
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONFIG_DATA_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONFIG_DATA_16
        #undef GPT_START_SEC_CONFIG_DATA_16
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma ghs section
    #endif
    #undef GPT_STOP_SEC_CONFIG_DATA_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CONFIG_DATA_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma ghs section rodata=".mcal_const_cfg"
    #else
        #ifndef GPT_STOP_SEC_CONFIG_DATA_32
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONFIG_DATA_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONFIG_DATA_32
        #undef GPT_START_SEC_CONFIG_DATA_32
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma ghs section
    #endif
    #undef GPT_STOP_SEC_CONFIG_DATA_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma ghs section rodata=".mcal_const_cfg"
    #else
        #ifndef GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
        #undef GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma ghs section
    #endif
    #undef GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CONST_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma ghs section rodata=".mcal_const"
    #else
        #ifndef GPT_STOP_SEC_CONST_BOOLEAN
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONST_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONST_BOOLEAN
        #undef GPT_START_SEC_CONST_BOOLEAN
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma ghs section
    #endif
    #undef GPT_STOP_SEC_CONST_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CONST_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma ghs section rodata=".mcal_const"
    #else
        #ifndef GPT_STOP_SEC_CONST_8
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONST_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONST_8
        #undef GPT_START_SEC_CONST_8
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma ghs section
    #endif
    #undef GPT_STOP_SEC_CONST_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CONST_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma ghs section rodata=".mcal_const"
    #else
        #ifndef GPT_STOP_SEC_CONST_16
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONST_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONST_16
        #undef GPT_START_SEC_CONST_16
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma ghs section
    #endif
    #undef GPT_STOP_SEC_CONST_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CONST_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma ghs section rodata=".mcal_const"
    #else
        #ifndef GPT_STOP_SEC_CONST_32
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONST_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONST_32
        #undef GPT_START_SEC_CONST_32
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma ghs section
    #endif
    #undef GPT_STOP_SEC_CONST_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CONST_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma ghs section rodata=".mcal_const"
    #else
        #ifndef GPT_STOP_SEC_CONST_UNSPECIFIED
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONST_UNSPECIFIED
        #undef GPT_START_SEC_CONST_UNSPECIFIED
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma ghs section
    #endif
    #undef GPT_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CODE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma ghs section text=".mcal_text"
    #else
        #ifndef GPT_STOP_SEC_CODE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CODE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CODE
        #undef GPT_START_SEC_CODE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma ghs section
    #endif
    #undef GPT_STOP_SEC_CODE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_RAMCODE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma ghs section text=".ramcode"
        #pragma ghs inlineprologue
        #pragma ghs callmode=far
    #else
        #ifndef GPT_STOP_SEC_RAMCODE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_RAMCODE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_RAMCODE
        #undef GPT_START_SEC_RAMCODE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma ghs section
        #pragma ghs noinlineprologue
        #pragma ghs callmode=default
    #endif
    #undef GPT_STOP_SEC_RAMCODE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CODE_AC
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma ghs section text=".acgpt_code_rom"
        #pragma ghs inlineprologue
    #else
        #ifndef GPT_STOP_SEC_CODE_AC
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CODE_AC
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CODE_AC
        #undef GPT_START_SEC_CODE_AC
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma ghs section
        #pragma ghs noinlineprologue
    #endif
    #undef GPT_STOP_SEC_CODE_AC
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma ghs section bss=".mcal_bss"
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_BOOLEAN
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_BOOLEAN
        #undef GPT_START_SEC_VAR_NO_INIT_BOOLEAN
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma ghs section
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma ghs section bss=".mcal_bss"
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_8
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_8
        #undef GPT_START_SEC_VAR_NO_INIT_8
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma ghs section
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma ghs section bss=".mcal_bss"
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_16
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_16
        #undef GPT_START_SEC_VAR_NO_INIT_16
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma ghs section
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma ghs section bss=".mcal_bss"
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_32
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_32
        #undef GPT_START_SEC_VAR_NO_INIT_32
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma ghs section
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma ghs section bss=".mcal_bss"
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED
        #undef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma ghs section
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma ghs section data=".mcal_data"
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_BOOLEAN
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_BOOLEAN
        #undef GPT_START_SEC_VAR_INIT_BOOLEAN
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma ghs section
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma ghs section data=".mcal_data"
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_8
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_8
        #undef GPT_START_SEC_VAR_INIT_8
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma ghs section
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma ghs section data=".mcal_data"
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_16
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_16
        #undef GPT_START_SEC_VAR_INIT_16
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma ghs section
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma ghs section data=".mcal_data"
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_32
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_32
        #undef GPT_START_SEC_VAR_INIT_32
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma ghs section
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma ghs section data=".mcal_data"
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_UNSPECIFIED
        #undef GPT_START_SEC_VAR_INIT_UNSPECIFIED
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma ghs section
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma ghs section bss=".mcal_bss_no_cacheable"
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma ghs section
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma ghs section bss=".mcal_bss_no_cacheable"
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma ghs section
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma ghs section bss=".mcal_bss_no_cacheable"
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma ghs section
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma ghs section bss=".mcal_bss_no_cacheable"
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma ghs section
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma ghs section bss=".mcal_bss_no_cacheable"
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma ghs section
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma ghs section data=".mcal_data_no_cacheable"
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma ghs section
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma ghs section data=".mcal_data_no_cacheable"
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_8_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_INIT_8_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma ghs section
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma ghs section data=".mcal_data_no_cacheable"
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_16_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_INIT_16_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma ghs section
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma ghs section data=".mcal_data_no_cacheable"
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_32_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_INIT_32_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma ghs section
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma ghs section data=".mcal_data_no_cacheable"
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma ghs section
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma ghs section bss=".dma_dest_buffer_bss" data=".dma_dest_buffer"
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_AE_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED_AE_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma ghs section
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma ghs section bss=".dma_dest_buffer_bss" data=".dma_dest_buffer"
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma ghs section
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif
/**************************************************************************************************/
/********************************************* DIAB ***********************************************/
/**************************************************************************************************/
#elif defined(_DIABDATA_C_IMX8_)
/**************************************** GPT *******************************/
#ifdef GPT_START_SEC_CONFIG_DATA_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #ifdef __clang__
            #pragma clang section bss="" data="" rodata=".mcal_const_cfg"
        #else
            #pragma section CONST ".mcal_const_cfg"
        #endif
    #else
        #ifndef GPT_STOP_SEC_CONFIG_DATA_8
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONFIG_DATA_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONFIG_DATA_8
        #undef GPT_START_SEC_CONFIG_DATA_8
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #ifdef __clang__
            #pragma clang section bss="" data="" rodata=""
        #else
            #pragma section CONST
        #endif
    #endif
    #undef GPT_STOP_SEC_CONFIG_DATA_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CONFIG_DATA_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #ifdef __clang__
            #pragma clang section bss="" data="" rodata=".mcal_const_cfg"
        #else
            #pragma section CONST ".mcal_const_cfg"
        #endif
    #else
        #ifndef GPT_STOP_SEC_CONFIG_DATA_16
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONFIG_DATA_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONFIG_DATA_16
        #undef GPT_START_SEC_CONFIG_DATA_16
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #ifdef __clang__
            #pragma clang section bss="" data="" rodata=""
        #else
            #pragma section CONST
        #endif
    #endif
    #undef GPT_STOP_SEC_CONFIG_DATA_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CONFIG_DATA_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #ifdef __clang__
            #pragma clang section bss="" data="" rodata=".mcal_const_cfg"
        #else
            #pragma section CONST ".mcal_const_cfg"
        #endif
    #else
        #ifndef GPT_STOP_SEC_CONFIG_DATA_32
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONFIG_DATA_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONFIG_DATA_32
        #undef GPT_START_SEC_CONFIG_DATA_32
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #ifdef __clang__
            #pragma clang section bss="" data="" rodata=""
        #else
            #pragma section CONST
        #endif
    #endif
    #undef GPT_STOP_SEC_CONFIG_DATA_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #ifdef __clang__
            #pragma clang section bss="" data="" rodata=".mcal_const_cfg"
        #else
            #pragma section CONST ".mcal_const_cfg"
        #endif
    #else
        #ifndef GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
        #undef GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #ifdef __clang__
            #pragma clang section bss="" data="" rodata=""
        #else
            #pragma section CONST
        #endif
    #endif
    #undef GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CONST_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #ifdef __clang__
            #pragma clang section bss="" data="" rodata=".mcal_const"
        #else
            #pragma section CONST ".mcal_const"
        #endif
    #else
        #ifndef GPT_STOP_SEC_CONST_BOOLEAN
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONST_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONST_BOOLEAN
        #undef GPT_START_SEC_CONST_BOOLEAN
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #ifdef __clang__
            #pragma clang section bss="" data="" rodata=""
        #else
            #pragma section CONST
        #endif
    #endif
    #undef GPT_STOP_SEC_CONST_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CONST_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #ifdef __clang__
            #pragma clang section bss="" data="" rodata=".mcal_const"
        #else
            #pragma section CONST ".mcal_const"
        #endif
    #else
        #ifndef GPT_STOP_SEC_CONST_8
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONST_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONST_8
        #undef GPT_START_SEC_CONST_8
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #ifdef __clang__
            #pragma clang section bss="" data="" rodata=""
        #else
            #pragma section CONST
        #endif
    #endif
    #undef GPT_STOP_SEC_CONST_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CONST_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #ifdef __clang__
            #pragma clang section bss="" data="" rodata=".mcal_const"
        #else
            #pragma section CONST ".mcal_const"
        #endif
    #else
        #ifndef GPT_STOP_SEC_CONST_16
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONST_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONST_16
        #undef GPT_START_SEC_CONST_16
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #ifdef __clang__
            #pragma clang section bss="" data="" rodata=""
        #else
            #pragma section CONST
        #endif
    #endif
    #undef GPT_STOP_SEC_CONST_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CONST_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #ifdef __clang__
            #pragma clang section bss="" data="" rodata=".mcal_const"
        #else
            #pragma section CONST ".mcal_const"
        #endif
    #else
        #ifndef GPT_STOP_SEC_CONST_32
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONST_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONST_32
        #undef GPT_START_SEC_CONST_32
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #ifdef __clang__
            #pragma clang section bss="" data="" rodata=""
        #else
            #pragma section CONST
        #endif
    #endif
    #undef GPT_STOP_SEC_CONST_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CONST_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #ifdef __clang__
            #pragma clang section bss="" data="" rodata=".mcal_const"
        #else
            #pragma section CONST ".mcal_const"
        #endif
    #else
        #ifndef GPT_STOP_SEC_CONST_UNSPECIFIED
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONST_UNSPECIFIED
        #undef GPT_START_SEC_CONST_UNSPECIFIED
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #ifdef __clang__
            #pragma clang section bss="" data="" rodata=""
        #else
            #pragma section CONST
        #endif
    #endif
    #undef GPT_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CODE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #ifdef __clang__
            #pragma clang section bss="" data="" rodata="" text=".mcal_text"
        #else
        /* no definition -> default compiler settings are used */
        #endif
    #else
        #ifndef GPT_STOP_SEC_CODE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CODE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CODE
        #undef GPT_START_SEC_CODE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #ifdef __clang__
            #pragma clang section bss="" data="" rodata="" text=""
        #else
            /* no definition -> default compiler settings are used */
        #endif
    #endif
    #undef GPT_STOP_SEC_CODE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_RAMCODE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #ifdef __clang__
            #pragma clang section bss="" data="" rodata="" text=".ramcode"
        #else
            #pragma section CODE ".ramcode" far-absolute
        #endif
    #else
        #ifndef GPT_STOP_SEC_RAMCODE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_RAMCODE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_RAMCODE
        #undef GPT_START_SEC_RAMCODE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        /* default section for CODE */
        #ifdef __clang__
            #pragma clang section bss="" data="" rodata="" text=""
        #else
            #pragma section CODE
        #endif
    #endif
    #undef GPT_STOP_SEC_RAMCODE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CODE_AC
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        /* use code relative addressing mode to ensure Position-independent Code (PIC) */
        #ifdef __clang__
            #pragma clang section bss="" data="" rodata="" text=".acgpt_code_rom"
        #else
            #pragma section CODE ".acgpt_code_rom" far-code
        #endif
    #else
        #ifndef GPT_STOP_SEC_CODE_AC
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CODE_AC
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CODE_AC
        #undef GPT_START_SEC_CODE_AC
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        /* default section for CODE */
        #ifdef __clang__
            #pragma clang section bss="" data="" rodata="" text=""
        #else
            #pragma section CODE
        #endif
    #endif
    #undef GPT_STOP_SEC_CODE_AC
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #ifdef __clang__
            #pragma clang section bss=".mcal_bss" data=".mcal_data" rodata=""
        #else
            #pragma section DATA ".mcal_data" ".mcal_bss"
        #endif
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_BOOLEAN
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_BOOLEAN
        #undef GPT_START_SEC_VAR_NO_INIT_BOOLEAN
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #ifdef __clang__
            #pragma clang section bss="" data="" rodata=""
        #else
            #pragma section DATA
        #endif
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #ifdef __clang__
            #pragma clang section bss=".mcal_bss" data=".mcal_data" rodata=""
        #else
            #pragma section DATA ".mcal_data" ".mcal_bss"
        #endif
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_8
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_8
        #undef GPT_START_SEC_VAR_NO_INIT_8
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #ifdef __clang__
            #pragma clang section bss="" data="" rodata=""
        #else
            #pragma section DATA
        #endif
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #ifdef __clang__
            #pragma clang section bss=".mcal_bss" data=".mcal_data" rodata=""
        #else
            #pragma section DATA ".mcal_data" ".mcal_bss"
        #endif
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_16
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_16
        #undef GPT_START_SEC_VAR_NO_INIT_16
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #ifdef __clang__
            #pragma clang section bss="" data="" rodata=""
        #else
            #pragma section DATA
        #endif
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #ifdef __clang__
            #pragma clang section bss=".mcal_bss" data=".mcal_data" rodata=""
        #else
            #pragma section DATA ".mcal_data" ".mcal_bss"
        #endif
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_32
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_32
        #undef GPT_START_SEC_VAR_NO_INIT_32
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #ifdef __clang__
            #pragma clang section bss="" data="" rodata=""
        #else
            #pragma section DATA
        #endif
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #ifdef __clang__
            #pragma clang section bss=".mcal_bss" data=".mcal_data" rodata=""
        #else
            #pragma section DATA ".mcal_data" ".mcal_bss"
        #endif
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED
        #undef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #ifdef __clang__
            #pragma clang section bss="" data="" rodata=""
        #else
            #pragma section DATA
        #endif
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #ifdef __clang__
            #pragma clang section bss=".mcal_bss" data=".mcal_data" rodata=""
        #else
            #pragma section DATA ".mcal_data" ".mcal_bss"
        #endif
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_BOOLEAN
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_BOOLEAN
        #undef GPT_START_SEC_VAR_INIT_BOOLEAN
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #ifdef __clang__
            #pragma clang section bss="" data="" rodata=""
        #else
            #pragma section DATA
        #endif
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #ifdef __clang__
            #pragma clang section bss=".mcal_bss" data=".mcal_data" rodata=""
        #else
            #pragma section DATA ".mcal_data" ".mcal_bss"
        #endif
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_8
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_8
        #undef GPT_START_SEC_VAR_INIT_8
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #ifdef __clang__
            #pragma clang section bss="" data="" rodata=""
        #else
            #pragma section DATA
        #endif
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif


#ifdef GPT_START_SEC_VAR_INIT_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #ifdef __clang__
            #pragma clang section bss=".mcal_bss" data=".mcal_data" rodata=""
        #else
            #pragma section DATA ".mcal_data" ".mcal_bss"
        #endif
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_16
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_16
        #undef GPT_START_SEC_VAR_INIT_16
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #ifdef __clang__
            #pragma clang section bss="" data="" rodata=""
        #else
            #pragma section DATA
        #endif
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #ifdef __clang__
            #pragma clang section bss=".mcal_bss" data=".mcal_data" rodata=""
        #else
            #pragma section DATA ".mcal_data" ".mcal_bss"
        #endif
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_32
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_32
        #undef GPT_START_SEC_VAR_INIT_32
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #ifdef __clang__
            #pragma clang section bss="" data="" rodata=""
        #else
            #pragma section DATA
        #endif
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #ifdef __clang__
            #pragma clang section bss=".mcal_bss" data=".mcal_data" rodata=""
        #else
            #pragma section DATA ".mcal_data" ".mcal_bss"
        #endif
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_UNSPECIFIED
        #undef GPT_START_SEC_VAR_INIT_UNSPECIFIED
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #ifdef __clang__
            #pragma clang section bss="" data="" rodata=""
        #else
            #pragma section DATA
        #endif
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif


#ifdef GPT_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #ifdef __clang__
            #pragma clang section bss=".mcal_bss_no_cacheable" data=".mcal_data_no_cacheable" rodata=""
        #else
            #pragma section DATA ".mcal_data_no_cacheable" ".mcal_bss_no_cacheable"
        #endif
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #ifdef __clang__
            #pragma clang section bss="" data="" rodata=""
        #else
            #pragma section DATA
        #endif
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #ifdef __clang__
            #pragma clang section bss=".mcal_bss_no_cacheable" data=".mcal_data_no_cacheable" rodata=""
        #else
            #pragma section DATA ".mcal_data_no_cacheable" ".mcal_bss_no_cacheable"
        #endif
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #ifdef __clang__
            #pragma clang section bss="" data="" rodata=""
        #else
            #pragma section DATA
        #endif
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #ifdef __clang__
            #pragma clang section bss=".mcal_bss_no_cacheable" data=".mcal_data_no_cacheable" rodata=""
        #else
            #pragma section DATA ".mcal_data_no_cacheable" ".mcal_bss_no_cacheable"
        #endif
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #ifdef __clang__
            #pragma clang section bss="" data="" rodata=""
        #else
            #pragma section DATA
        #endif
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #ifdef __clang__
            #pragma clang section bss=".mcal_bss_no_cacheable" data=".mcal_data_no_cacheable" rodata=""
        #else
            #pragma section DATA ".mcal_data_no_cacheable" ".mcal_bss_no_cacheable"
        #endif
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #ifdef __clang__
            #pragma clang section bss="" data="" rodata=""
        #else
            #pragma section DATA
        #endif
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #ifdef __clang__
            #pragma clang section bss=".mcal_bss_no_cacheable" data=".mcal_data_no_cacheable" rodata=""
        #else
            #pragma section DATA ".mcal_data_no_cacheable" ".mcal_bss_no_cacheable"
        #endif
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #ifdef __clang__
            #pragma clang section bss="" data="" rodata=""
        #else
            #pragma section DATA
        #endif
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #ifdef __clang__
            #pragma clang section bss=".mcal_bss_no_cacheable" data=".mcal_data_no_cacheable" rodata=""
        #else
            #pragma section DATA ".mcal_data_no_cacheable" ".mcal_bss_no_cacheable"
        #endif
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #ifdef __clang__
            #pragma clang section bss="" data="" rodata=""
        #else
            #pragma section DATA
        #endif
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #ifdef __clang__
            #pragma clang section bss=".mcal_bss_no_cacheable" data=".mcal_data_no_cacheable" rodata=""
        #else
            #pragma section DATA ".mcal_data_no_cacheable" ".mcal_bss_no_cacheable"
        #endif
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_8_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_INIT_8_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #ifdef __clang__
            #pragma clang section bss="" data="" rodata=""
        #else
            #pragma section DATA
        #endif
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif


#ifdef GPT_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #ifdef __clang__
            #pragma clang section bss=".mcal_bss_no_cacheable" data=".mcal_data_no_cacheable" rodata=""
        #else
            #pragma section DATA ".mcal_data_no_cacheable" ".mcal_bss_no_cacheable"
        #endif
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_16_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_INIT_16_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #ifdef __clang__
            #pragma clang section bss="" data="" rodata=""
        #else
            #pragma section DATA
        #endif
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #ifdef __clang__
            #pragma clang section bss=".mcal_bss_no_cacheable" data=".mcal_data_no_cacheable" rodata=""
        #else
            #pragma section DATA ".mcal_data_no_cacheable" ".mcal_bss_no_cacheable"
        #endif
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_32_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_INIT_32_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #ifdef __clang__
            #pragma clang section bss="" data="" rodata=""
        #else
            #pragma section DATA
        #endif
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #ifdef __clang__
            #pragma clang section bss=".mcal_bss_no_cacheable" data=".mcal_data_no_cacheable" rodata=""
        #else
            #pragma section DATA ".mcal_data_no_cacheable" ".mcal_bss_no_cacheable"
        #endif
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #ifdef __clang__
            #pragma clang section bss="" data="" rodata=""
        #else
            #pragma section DATA
        #endif
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #ifdef __clang__
            #pragma clang section bss=".dma_dest_buffer_bss" data=".dma_dest_buffer" rodata=""
        #else
            #pragma section DATA ".dma_dest_buffer" ".dma_dest_buffer_bss"
        #endif
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_AE_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED_AE_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #ifdef __clang__
            #pragma clang section bss="" data="" rodata=""
        #else
            #pragma section DATA
        #endif
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #ifdef __clang__
            #pragma clang section bss=".dma_dest_buffer_bss" data=".dma_dest_buffer" rodata=""
        #else
            #pragma section DATA ".dma_dest_buffer" ".dma_dest_buffer_bss"
        #endif
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #ifdef __clang__
            #pragma clang section bss="" data="" rodata=""
        #else
            #pragma section DATA
        #endif
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif
/**************************************************************************************************/
/********************************************* CODEWARRIOR ****************************************/
/**************************************************************************************************/
#elif defined(_CODEWARRIOR_C_IMX8_)
/**************************************** GPT *******************************/
#ifdef GPT_START_SEC_CONFIG_DATA_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma CONST_SEG mcal_const_cfg
    #else
        #ifndef GPT_STOP_SEC_CONFIG_DATA_8
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONFIG_DATA_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONFIG_DATA_8
        #undef GPT_START_SEC_CONFIG_DATA_8
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma CONST_SEG DEFAULT
    #endif
    #undef GPT_STOP_SEC_CONFIG_DATA_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CONFIG_DATA_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma CONST_SEG mcal_const_cfg
    #else
        #ifndef GPT_STOP_SEC_CONFIG_DATA_16
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONFIG_DATA_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONFIG_DATA_16
        #undef GPT_START_SEC_CONFIG_DATA_16
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma CONST_SEG DEFAULT
    #endif
    #undef GPT_STOP_SEC_CONFIG_DATA_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CONFIG_DATA_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma CONST_SEG mcal_const_cfg
    #else
        #ifndef GPT_STOP_SEC_CONFIG_DATA_32
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONFIG_DATA_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONFIG_DATA_32
        #undef GPT_START_SEC_CONFIG_DATA_32
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma CONST_SEG DEFAULT
    #endif
    #undef GPT_STOP_SEC_CONFIG_DATA_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma CONST_SEG mcal_const_cfg
    #else
        #ifndef GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
        #undef GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma CONST_SEG DEFAULT
    #endif
    #undef GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CONST_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma CONST_SEG mcal_const
    #else
        #ifndef GPT_STOP_SEC_CONST_BOOLEAN
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONST_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONST_BOOLEAN
        #undef GPT_START_SEC_CONST_BOOLEAN
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma CONST_SEG DEFAULT
    #endif
    #undef GPT_STOP_SEC_CONST_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CONST_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma CONST_SEG mcal_const
    #else
        #ifndef GPT_STOP_SEC_CONST_8
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONST_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONST_8
        #undef GPT_START_SEC_CONST_8
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma CONST_SEG DEFAULT
    #endif
    #undef GPT_STOP_SEC_CONST_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CONST_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma CONST_SEG mcal_const
    #else
        #ifndef GPT_STOP_SEC_CONST_16
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONST_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONST_16
        #undef GPT_START_SEC_CONST_16
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma CONST_SEG DEFAULT
    #endif
    #undef GPT_STOP_SEC_CONST_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CONST_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma CONST_SEG mcal_const
    #else
        #ifndef GPT_STOP_SEC_CONST_32
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONST_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONST_32
        #undef GPT_START_SEC_CONST_32
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma CONST_SEG DEFAULT
    #endif
    #undef GPT_STOP_SEC_CONST_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CONST_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma CONST_SEG mcal_const
    #else
        #ifndef GPT_STOP_SEC_CONST_UNSPECIFIED
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONST_UNSPECIFIED
        #undef GPT_START_SEC_CONST_UNSPECIFIED
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma CONST_SEG DEFAULT
    #endif
    #undef GPT_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CODE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma CODE_SEG mcal_text
    #else
        #ifndef GPT_STOP_SEC_CODE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CODE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CODE
        #undef GPT_START_SEC_CODE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma CODE_SEG DEFAULT
    #endif
    #undef GPT_STOP_SEC_CODE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_RAMCODE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma CODE_SEG ramcode
    #else
        #ifndef GPT_STOP_SEC_RAMCODE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_RAMCODE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_RAMCODE
        #undef GPT_START_SEC_RAMCODE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma CODE_SEG DEFAULT
    #endif
    #undef GPT_STOP_SEC_RAMCODE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CODE_AC
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma CODE_SEG acgpt_code_rom
    #else
        #ifndef GPT_STOP_SEC_CODE_AC
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CODE_AC
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CODE_AC
        #undef GPT_START_SEC_CODE_AC
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma CODE_SEG DEFAULT
    #endif
    #undef GPT_STOP_SEC_CODE_AC
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma DATA_SEG mcal_bss
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_BOOLEAN
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_BOOLEAN
        #undef GPT_START_SEC_VAR_NO_INIT_BOOLEAN
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma DATA_SEG DEFAULT
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma DATA_SEG mcal_bss
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_8
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_8
        #undef GPT_START_SEC_VAR_NO_INIT_8
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma DATA_SEG DEFAULT
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma DATA_SEG mcal_bss
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_16
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_16
        #undef GPT_START_SEC_VAR_NO_INIT_16
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma DATA_SEG DEFAULT
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma DATA_SEG mcal_bss
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_32
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_32
        #undef GPT_START_SEC_VAR_NO_INIT_32
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma DATA_SEG DEFAULT
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma DATA_SEG mcal_bss
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED
        #undef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma DATA_SEG DEFAULT
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma DATA_SEG mcal_data
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_BOOLEAN
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_BOOLEAN
        #undef GPT_START_SEC_VAR_INIT_BOOLEAN
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma DATA_SEG DEFAULT
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma DATA_SEG mcal_data
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_8
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_8
        #undef GPT_START_SEC_VAR_INIT_8
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma DATA_SEG DEFAULT
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma DATA_SEG mcal_data
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_16
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_16
        #undef GPT_START_SEC_VAR_INIT_16
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma DATA_SEG DEFAULT
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma DATA_SEG mcal_data
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_32
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_32
        #undef GPT_START_SEC_VAR_INIT_32
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma DATA_SEG DEFAULT
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma DATA_SEG mcal_data
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_UNSPECIFIED
        #undef GPT_START_SEC_VAR_INIT_UNSPECIFIED
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma DATA_SEG DEFAULT
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma DATA_SEG mcal_bss
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma DATA_SEG DEFAULT
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma DATA_SEG mcal_bss
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma DATA_SEG DEFAULT
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma DATA_SEG mcal_bss
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma DATA_SEG DEFAULT
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma DATA_SEG mcal_bss
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma DATA_SEG DEFAULT
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma DATA_SEG mcal_bss
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma DATA_SEG DEFAULT
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma DATA_SEG mcal_data
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma DATA_SEG DEFAULT
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma DATA_SEG mcal_data
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_8_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_INIT_8_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma DATA_SEG DEFAULT
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma DATA_SEG mcal_data
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_16_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_INIT_16_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma DATA_SEG DEFAULT
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma DATA_SEG mcal_data
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_32_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_INIT_32_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma DATA_SEG DEFAULT
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma DATA_SEG mcal_data
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma DATA_SEG DEFAULT
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma DATA_SEG dma_dest_buffer_bss
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_AE_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED_AE_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma DATA_SEG DEFAULT
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma DATA_SEG dma_dest_buffer
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma DATA_SEG DEFAULT
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif
/**************************************************************************************************/
/********************************************* COSMIC *********************************************/
/**************************************************************************************************/
#elif defined(_COSMIC_C_IMX8_)
/**************************************** GPT *******************************/
#ifdef GPT_START_SEC_CONFIG_DATA_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma section const {mcalconstcfg}
    #else
        #ifndef GPT_STOP_SEC_CONFIG_DATA_8
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONFIG_DATA_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONFIG_DATA_8
        #undef GPT_START_SEC_CONFIG_DATA_8
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma section const {}
    #endif
    #undef GPT_STOP_SEC_CONFIG_DATA_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CONFIG_DATA_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma section const {mcalconstcfg}
    #else
        #ifndef GPT_STOP_SEC_CONFIG_DATA_16
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONFIG_DATA_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONFIG_DATA_16
        #undef GPT_START_SEC_CONFIG_DATA_16
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma section const {}
    #endif
    #undef GPT_STOP_SEC_CONFIG_DATA_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CONFIG_DATA_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma section const {mcalconstcfg}
    #else
        #ifndef GPT_STOP_SEC_CONFIG_DATA_32
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONFIG_DATA_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONFIG_DATA_32
        #undef GPT_START_SEC_CONFIG_DATA_32
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma section const {}
    #endif
    #undef GPT_STOP_SEC_CONFIG_DATA_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma section const {mcalconstcfg}
    #else
        #ifndef GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
        #undef GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma section const {}
    #endif
    #undef GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CONST_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma section const {mcal_const}
    #else
        #ifndef GPT_STOP_SEC_CONST_BOOLEAN
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONST_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONST_BOOLEAN
        #undef GPT_START_SEC_CONST_BOOLEAN
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma section const {}
    #endif
    #undef GPT_STOP_SEC_CONST_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CONST_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma section const {mcal_const}
    #else
        #ifndef GPT_STOP_SEC_CONST_8
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONST_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONST_8
        #undef GPT_START_SEC_CONST_8
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma section const {}
    #endif
    #undef GPT_STOP_SEC_CONST_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CONST_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma section const {mcal_const}
    #else
        #ifndef GPT_STOP_SEC_CONST_16
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONST_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONST_16
        #undef GPT_START_SEC_CONST_16
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma section const {}
    #endif
    #undef GPT_STOP_SEC_CONST_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CONST_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma section const {mcal_const}
    #else
        #ifndef GPT_STOP_SEC_CONST_32
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONST_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONST_32
        #undef GPT_START_SEC_CONST_32
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma section const {}
    #endif
    #undef GPT_STOP_SEC_CONST_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CONST_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma section const {mcal_const}
    #else
        #ifndef GPT_STOP_SEC_CONST_UNSPECIFIED
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONST_UNSPECIFIED
        #undef GPT_START_SEC_CONST_UNSPECIFIED
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma section const {}
    #endif
    #undef GPT_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CODE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma section (mcal_text)
    #else
        #ifndef GPT_STOP_SEC_CODE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CODE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CODE
        #undef GPT_START_SEC_CODE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma section ()
    #endif
    #undef GPT_STOP_SEC_CODE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_RAMCODE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma section (ramcode)
    #else
        #ifndef GPT_STOP_SEC_RAMCODE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_RAMCODE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_RAMCODE
        #undef GPT_START_SEC_RAMCODE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma section ()
    #endif
    #undef GPT_STOP_SEC_RAMCODE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CODE_AC
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma section (acgptcode)
    #else
        #ifndef GPT_STOP_SEC_CODE_AC
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CODE_AC
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CODE_AC
        #undef GPT_START_SEC_CODE_AC
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma section ()
    #endif
    #undef GPT_STOP_SEC_CODE_AC
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma section [mcal_bss]
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_BOOLEAN
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_BOOLEAN
        #undef GPT_START_SEC_VAR_NO_INIT_BOOLEAN
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma section []
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma section [mcal_bss]
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_8
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_8
        #undef GPT_START_SEC_VAR_NO_INIT_8
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma section []
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma section [mcal_bss]
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_16
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_16
        #undef GPT_START_SEC_VAR_NO_INIT_16
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma section []
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma section [mcal_bss]
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_32
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_32
        #undef GPT_START_SEC_VAR_NO_INIT_32
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma section []
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma section [mcal_bss]
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED
        #undef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma section []
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma section {mcal_data}
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_BOOLEAN
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_BOOLEAN
        #undef GPT_START_SEC_VAR_INIT_BOOLEAN
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma section {}
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma section {mcal_data}
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_8
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_8
        #undef GPT_START_SEC_VAR_INIT_8
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma section {}
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma section {mcal_data}
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_16
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_16
        #undef GPT_START_SEC_VAR_INIT_16
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma section {}
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma section {mcal_data}
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_32
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_32
        #undef GPT_START_SEC_VAR_INIT_32
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma section {}
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma section {mcal_data}
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_UNSPECIFIED
        #undef GPT_START_SEC_VAR_INIT_UNSPECIFIED
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma section {}
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma section [mcal_bss]
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma section []
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma section [mcal_bss]
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma section []
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma section [mcal_bss]
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma section []
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma section [mcal_bss]
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma section []
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma section [mcal_bss]
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma section []
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma section {mcal_data}
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma section {}
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma section {mcal_data}
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_8_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_INIT_8_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma section {}
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma section {mcal_data}
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_16_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_INIT_16_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma section {}
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma section {mcal_data}
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_32_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_INIT_32_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma section {}
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma section {mcal_data}
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma section {}
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma section [dma_dest_buffer_bss]
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_AE_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED_AE_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma section []
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma section {dma_dest_buffer}
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma section {}
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif
/**************************************************************************************************/
/********************************************* HighTec *********************************************/
/**************************************************************************************************/
#elif defined(_HITECH_C_IMX8_)
/**************************************** GPT *******************************/
#ifdef GPT_START_SEC_CONFIG_DATA_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma section ".mcal_const_cfg" a
    #else
        #ifndef GPT_STOP_SEC_CONFIG_DATA_8
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONFIG_DATA_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONFIG_DATA_8
        #undef GPT_START_SEC_CONFIG_DATA_8
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma section
    #endif
    #undef GPT_STOP_SEC_CONFIG_DATA_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CONFIG_DATA_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma section ".mcal_const_cfg" a
    #else
        #ifndef GPT_STOP_SEC_CONFIG_DATA_16
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONFIG_DATA_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONFIG_DATA_16
        #undef GPT_START_SEC_CONFIG_DATA_16
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma section
    #endif
    #undef GPT_STOP_SEC_CONFIG_DATA_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CONFIG_DATA_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma section ".mcal_const_cfg" a
    #else
        #ifndef GPT_STOP_SEC_CONFIG_DATA_32
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONFIG_DATA_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONFIG_DATA_32
        #undef GPT_START_SEC_CONFIG_DATA_32
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma section
    #endif
    #undef GPT_STOP_SEC_CONFIG_DATA_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma section ".mcal_const_cfg" a
    #else
        #ifndef GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
        #undef GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma section
    #endif
    #undef GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CONST_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma section ".mcal_const" a
    #else
        #ifndef GPT_STOP_SEC_CONST_BOOLEAN
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONST_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONST_BOOLEAN
        #undef GPT_START_SEC_CONST_BOOLEAN
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma section
    #endif
    #undef GPT_STOP_SEC_CONST_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CONST_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma section ".mcal_const" a
    #else
        #ifndef GPT_STOP_SEC_CONST_8
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONST_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONST_8
        #undef GPT_START_SEC_CONST_8
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma section
    #endif
    #undef GPT_STOP_SEC_CONST_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CONST_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma section ".mcal_const" a
    #else
        #ifndef GPT_STOP_SEC_CONST_16
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONST_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONST_16
        #undef GPT_START_SEC_CONST_16
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma section
    #endif
    #undef GPT_STOP_SEC_CONST_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CONST_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma section ".mcal_const" a
    #else
        #ifndef GPT_STOP_SEC_CONST_32
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONST_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONST_32
        #undef GPT_START_SEC_CONST_32
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma section
    #endif
    #undef GPT_STOP_SEC_CONST_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CONST_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma section ".mcal_const" a
    #else
        #ifndef GPT_STOP_SEC_CONST_UNSPECIFIED
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONST_UNSPECIFIED
        #undef GPT_START_SEC_CONST_UNSPECIFIED
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma section
    #endif
    #undef GPT_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CODE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma section ".mcal_text" avx
    #else
        #ifndef GPT_STOP_SEC_CODE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CODE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CODE
        #undef GPT_START_SEC_CODE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma section
    #endif
    #undef GPT_STOP_SEC_CODE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_RAMCODE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma section ".ramcode" avx
    #else
        #ifndef GPT_STOP_SEC_RAMCODE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_RAMCODE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_RAMCODE
        #undef GPT_START_SEC_RAMCODE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma  section
    #endif
    #undef GPT_STOP_SEC_RAMCODE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CODE_AC
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma section ".acgpt_code_rom" avx
    #else
        #ifndef GPT_STOP_SEC_CODE_AC
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CODE_AC
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CODE_AC
        #undef GPT_START_SEC_CODE_AC
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma  section
    #endif
    #undef GPT_STOP_SEC_CODE_AC
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma section ".mcal_bss" awsB
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_BOOLEAN
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_BOOLEAN
        #undef GPT_START_SEC_VAR_NO_INIT_BOOLEAN
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma section
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma section ".mcal_bss" awsB
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_8
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_8
        #undef GPT_START_SEC_VAR_NO_INIT_8
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma section
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma section ".mcal_bss" awsB
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_16
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_16
        #undef GPT_START_SEC_VAR_NO_INIT_16
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma section
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma section ".mcal_bss" awsB
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_32
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_32
        #undef GPT_START_SEC_VAR_NO_INIT_32
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma section
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma section ".mcal_bss" awsB
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED
        #undef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma section
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma section ".mcal_bss_no_cacheable" awsB
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        /* no definition -> default compiler settings are used */
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma section ".mcal_data" aws
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_BOOLEAN
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_BOOLEAN
        #undef GPT_START_SEC_VAR_INIT_BOOLEAN
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma section
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma section ".mcal_data" aws
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_8
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_8
        #undef GPT_START_SEC_VAR_INIT_8
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma section
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma section ".mcal_data" aws
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_16
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_16
        #undef GPT_START_SEC_VAR_INIT_16
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma section
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma section ".mcal_data" aws
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_32
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_32
        #undef GPT_START_SEC_VAR_INIT_32
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma section
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma section ".mcal_data" aws
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_UNSPECIFIED
        #undef GPT_START_SEC_VAR_INIT_UNSPECIFIED
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma section
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma section ".dma_dest_buffer_bss" aws
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_AE_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED_AE_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma section
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma section ".dma_dest_buffer" aws
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma section
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif
/**************************************************************************************************/
/*********************************************** Gcc **********************************************/
/**************************************************************************************************/
#elif defined(_GCC_C_IMX8_)
/**************************************** GPT *******************************/
#ifdef GPT_START_SEC_CONFIG_DATA_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        /* no definition -> default compiler settings are used */
    #else
        #ifndef GPT_STOP_SEC_CONFIG_DATA_8
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONFIG_DATA_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONFIG_DATA_8
        #undef GPT_START_SEC_CONFIG_DATA_8
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        /* no definition -> default compiler settings are used */
    #endif
    #undef GPT_STOP_SEC_CONFIG_DATA_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CONFIG_DATA_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        /* no definition -> default compiler settings are used */
    #else
        #ifndef GPT_STOP_SEC_CONFIG_DATA_16
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONFIG_DATA_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONFIG_DATA_16
        #undef GPT_START_SEC_CONFIG_DATA_16
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        /* no definition -> default compiler settings are used */
    #endif
    #undef GPT_STOP_SEC_CONFIG_DATA_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CONFIG_DATA_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        /* no definition -> default compiler settings are used */
    #else
        #ifndef GPT_STOP_SEC_CONFIG_DATA_32
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONFIG_DATA_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONFIG_DATA_32
        #undef GPT_START_SEC_CONFIG_DATA_32
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        /* no definition -> default compiler settings are used */
    #endif
    #undef GPT_STOP_SEC_CONFIG_DATA_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        /* no definition -> default compiler settings are used */
    #else
        #ifndef GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
        #undef GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        /* no definition -> default compiler settings are used */
    #endif
    #undef GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CONST_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        /* no definition -> default compiler settings are used */
    #else
        #ifndef GPT_STOP_SEC_CONST_BOOLEAN
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONST_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONST_BOOLEAN
        #undef GPT_START_SEC_CONST_BOOLEAN
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        /* no definition -> default compiler settings are used */
    #endif
    #undef GPT_STOP_SEC_CONST_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CONST_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        /* no definition -> default compiler settings are used */
    #else
        #ifndef GPT_STOP_SEC_CONST_8
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONST_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONST_8
        #undef GPT_START_SEC_CONST_8
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        /* no definition -> default compiler settings are used */
    #endif
    #undef GPT_STOP_SEC_CONST_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CONST_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        /* no definition -> default compiler settings are used */
    #else
        #ifndef GPT_STOP_SEC_CONST_16
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONST_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONST_16
        #undef GPT_START_SEC_CONST_16
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        /* no definition -> default compiler settings are used */
    #endif
    #undef GPT_STOP_SEC_CONST_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CONST_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        /* no definition -> default compiler settings are used */
    #else
        #ifndef GPT_STOP_SEC_CONST_32
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONST_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONST_32
        #undef GPT_START_SEC_CONST_32
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        /* no definition -> default compiler settings are used */
    #endif
    #undef GPT_STOP_SEC_CONST_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CONST_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        /* no definition -> default compiler settings are used */
    #else
        #ifndef GPT_STOP_SEC_CONST_UNSPECIFIED
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONST_UNSPECIFIED
        #undef GPT_START_SEC_CONST_UNSPECIFIED
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        /* no definition -> default compiler settings are used */
    #endif
    #undef GPT_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CODE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        /* no definition -> default compiler settings are used */
    #else
        #ifndef GPT_STOP_SEC_CODE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CODE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CODE
        #undef GPT_START_SEC_CODE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        /* no definition -> default compiler settings are used */
    #endif
    #undef GPT_STOP_SEC_CODE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_RAMCODE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        /* no definition -> default compiler settings are used */
    #else
        #ifndef GPT_STOP_SEC_RAMCODE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_RAMCODE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_RAMCODE
        #undef GPT_START_SEC_RAMCODE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        /* no definition -> default compiler settings are used */
    #endif
    #undef GPT_STOP_SEC_RAMCODE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CODE_AC
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        /* no definition -> default compiler settings are used */
    #else
        #ifndef GPT_STOP_SEC_CODE_AC
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CODE_AC
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CODE_AC
        #undef GPT_START_SEC_CODE_AC
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        /* no definition -> default compiler settings are used */
    #endif
    #undef GPT_STOP_SEC_CODE_AC
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        /* no definition -> default compiler settings are used */
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_BOOLEAN
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_BOOLEAN
        #undef GPT_START_SEC_VAR_NO_INIT_BOOLEAN
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        /* no definition -> default compiler settings are used */
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        /* no definition -> default compiler settings are used */
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_8
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_8
        #undef GPT_START_SEC_VAR_NO_INIT_8
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        /* no definition -> default compiler settings are used */
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        /* no definition -> default compiler settings are used */
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_16
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_16
        #undef GPT_START_SEC_VAR_NO_INIT_16
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        /* no definition -> default compiler settings are used */
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        /* no definition -> default compiler settings are used */
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_32
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_32
        #undef GPT_START_SEC_VAR_NO_INIT_32
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        /* no definition -> default compiler settings are used */
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        /* no definition -> default compiler settings are used */
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED
        #undef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        /* no definition -> default compiler settings are used */
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        /* no definition -> default compiler settings are used */
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_BOOLEAN
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_BOOLEAN
        #undef GPT_START_SEC_VAR_INIT_BOOLEAN
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        /* no definition -> default compiler settings are used */
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        /* no definition -> default compiler settings are used */
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_8
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_8
        #undef GPT_START_SEC_VAR_INIT_8
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        /* no definition -> default compiler settings are used */
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        /* no definition -> default compiler settings are used */
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_16
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_16
        #undef GPT_START_SEC_VAR_INIT_16
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        /* no definition -> default compiler settings are used */
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        /* no definition -> default compiler settings are used */
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_32
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_32
        #undef GPT_START_SEC_VAR_INIT_32
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        /* no definition -> default compiler settings are used */
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        /* no definition -> default compiler settings are used */
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_UNSPECIFIED
        #undef GPT_START_SEC_VAR_INIT_UNSPECIFIED
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        /* no definition -> default compiler settings are used */
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        __attribute__((section(".mcal_bss_no_cacheable")))
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        /* no definition -> default compiler settings are used */
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        __attribute__((section(".mcal_bss_no_cacheable")))
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        /* no definition -> default compiler settings are used */
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        __attribute__((section(".mcal_bss_no_cacheable")))
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        /* no definition -> default compiler settings are used */
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        __attribute__((section(".mcal_bss_no_cacheable")))
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        /* no definition -> default compiler settings are used */
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        __attribute__((section(".mcal_bss_no_cacheable")))
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        /* no definition -> default compiler settings are used */
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        __attribute__((section(".mcal_data_no_cacheable")))
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        /* no definition -> default compiler settings are used */
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        __attribute__((section(".mcal_data_no_cacheable")))
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_8_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_INIT_8_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        /* no definition -> default compiler settings are used */
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        __attribute__((section(".mcal_data_no_cacheable")))
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_16_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_INIT_16_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        /* no definition -> default compiler settings are used */
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        __attribute__((section(".mcal_data_no_cacheable")))
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_32_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_INIT_32_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        /* no definition -> default compiler settings are used */
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        __attribute__((section(".mcal_data_no_cacheable")))
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        /* no definition -> default compiler settings are used */
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        __attribute__((section(".dma_dest_buffer_bss")))
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_AE_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED_AE_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        /* no definition -> default compiler settings are used */
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        __attribute__((section(".dma_dest_buffer")))
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        /* no definition -> default compiler settings are used */
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif
/**************************************************************************************************/
/********************************************* DS5 ************************************************/
/**************************************************************************************************/
#elif defined(_ARM_DS5_C_IMX8_)
/**************************************** GPT *******************************/
#ifdef GPT_START_SEC_CONFIG_DATA_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma arm section code="", rodata=".mcal_const_cfg", rwdata="", zidata=""
    #else
        #ifndef GPT_STOP_SEC_CONFIG_DATA_8
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONFIG_DATA_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONFIG_DATA_8
        #undef GPT_START_SEC_CONFIG_DATA_8
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma arm section
    #endif
    #undef GPT_STOP_SEC_CONFIG_DATA_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CONFIG_DATA_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma arm section code="", rodata=".mcal_const_cfg", rwdata="", zidata=""
    #else
        #ifndef GPT_STOP_SEC_CONFIG_DATA_16
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONFIG_DATA_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONFIG_DATA_16
        #undef GPT_START_SEC_CONFIG_DATA_16
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma arm section
    #endif
    #undef GPT_STOP_SEC_CONFIG_DATA_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CONFIG_DATA_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma arm section code="", rodata=".mcal_const_cfg", rwdata="", zidata=""
    #else
        #ifndef GPT_STOP_SEC_CONFIG_DATA_32
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONFIG_DATA_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONFIG_DATA_32
        #undef GPT_START_SEC_CONFIG_DATA_32
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma arm section
    #endif
    #undef GPT_STOP_SEC_CONFIG_DATA_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma arm section code="", rodata=".mcal_const_cfg", rwdata="", zidata=""
    #else
        #ifndef GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
        #undef GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma arm section
    #endif
    #undef GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CONST_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma arm section code="", rodata=".mcal_const", rwdata="", zidata=""
    #else
        #ifndef GPT_STOP_SEC_CONST_BOOLEAN
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONST_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONST_BOOLEAN
        #undef GPT_START_SEC_CONST_BOOLEAN
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma arm section
    #endif
    #undef GPT_STOP_SEC_CONST_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CONST_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma arm section code="", rodata=".mcal_const", rwdata="", zidata=""
    #else
        #ifndef GPT_STOP_SEC_CONST_8
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONST_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONST_8
        #undef GPT_START_SEC_CONST_8
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma arm section
    #endif
    #undef GPT_STOP_SEC_CONST_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CONST_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma arm section code="", rodata=".mcal_const", rwdata="", zidata=""
    #else
        #ifndef GPT_STOP_SEC_CONST_16
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONST_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONST_16
        #undef GPT_START_SEC_CONST_16
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma arm section
    #endif
    #undef GPT_STOP_SEC_CONST_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CONST_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma arm section code="", rodata=".mcal_const", rwdata="", zidata=""
    #else
        #ifndef GPT_STOP_SEC_CONST_32
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONST_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONST_32
        #undef GPT_START_SEC_CONST_32
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma arm section
    #endif
    #undef GPT_STOP_SEC_CONST_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CONST_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma arm section code="", rodata=".mcal_const", rwdata="", zidata=""
    #else
        #ifndef GPT_STOP_SEC_CONST_UNSPECIFIED
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONST_UNSPECIFIED
        #undef GPT_START_SEC_CONST_UNSPECIFIED
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma arm section
    #endif
    #undef GPT_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CODE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma arm section code=".mcal_text", rodata="", rwdata="", zidata=""
    #else
        #ifndef GPT_STOP_SEC_CODE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CODE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CODE
        #undef GPT_START_SEC_CODE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma arm section
    #endif
    #undef GPT_STOP_SEC_CODE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_RAMCODE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma arm section code=".ramcode", rodata="", rwdata="", zidata=""
    #else
        #ifndef GPT_STOP_SEC_RAMCODE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_RAMCODE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_RAMCODE
        #undef GPT_START_SEC_RAMCODE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma arm section
    #endif
    #undef GPT_STOP_SEC_RAMCODE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CODE_AC
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma arm section code=".acgpt_code_rom", rodata="", rwdata="", zidata=""
    #else
        #ifndef GPT_STOP_SEC_CODE_AC
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CODE_AC
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CODE_AC
        #undef GPT_START_SEC_CODE_AC
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma arm section
    #endif
    #undef GPT_STOP_SEC_CODE_AC
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma arm section code="", rodata="", rwdata="", zidata=".mcal_bss"
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_BOOLEAN
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_BOOLEAN
        #undef GPT_START_SEC_VAR_NO_INIT_BOOLEAN
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma arm section
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma arm section code="", rodata="", rwdata="", zidata=".mcal_bss"
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_8
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_8
        #undef GPT_START_SEC_VAR_NO_INIT_8
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma arm section
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma arm section code="", rodata="", rwdata="", zidata=".mcal_bss"
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_16
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_16
        #undef GPT_START_SEC_VAR_NO_INIT_16
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma arm section
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma arm section code="", rodata="", rwdata="", zidata=".mcal_bss"
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_32
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_32
        #undef GPT_START_SEC_VAR_NO_INIT_32
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma arm section
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma arm section code="", rodata="", rwdata="", zidata=".mcal_bss"
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED
        #undef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma arm section
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma arm section code="", rodata="", rwdata=".mcal_data", zidata=""
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_BOOLEAN
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_BOOLEAN
        #undef GPT_START_SEC_VAR_INIT_BOOLEAN
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma arm section
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma arm section code="", rodata="", rwdata=".mcal_data", zidata=""
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_8
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_8
        #undef GPT_START_SEC_VAR_INIT_8
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma arm section
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma arm section code="", rodata="", rwdata=".mcal_data", zidata=""
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_16
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_16
        #undef GPT_START_SEC_VAR_INIT_16
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma arm section
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma arm section code="", rodata="", rwdata=".mcal_data", zidata=""
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_32
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_32
        #undef GPT_START_SEC_VAR_INIT_32
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma arm section
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma arm section code="", rodata="", rwdata=".mcal_data", zidata=""
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_UNSPECIFIED
        #undef GPT_START_SEC_VAR_INIT_UNSPECIFIED
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma arm section
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma arm section code="", rodata="", rwdata="", zidata=".mcal_bss_no_cacheable"
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma arm section
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma arm section code="", rodata="", rwdata="", zidata=".mcal_bss_no_cacheable"
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma arm section
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma arm section code="", rodata="", rwdata="", zidata=".mcal_bss_no_cacheable"
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma arm section
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma arm section code="", rodata="", rwdata="", zidata=".mcal_bss_no_cacheable"
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma arm section
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma arm section code="", rodata="", rwdata="", zidata=".mcal_bss_no_cacheable"
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma arm section
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma arm section code="", rodata="", rwdata=".mcal_data_no_cacheable", zidata=""
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma arm section
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma arm section code="", rodata="", rwdata=".mcal_data_no_cacheable", zidata=""
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_8_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_INIT_8_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma arm section
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma arm section code="", rodata="", rwdata=".mcal_data_no_cacheable", zidata=""
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_16_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_INIT_16_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma arm section
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma arm section code="", rodata="", rwdata=".mcal_data_no_cacheable", zidata=""
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_32_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_INIT_32_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma arm section
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma arm section code="", rodata="", rwdata=".mcal_data_no_cacheable", zidata=""
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma arm section
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma arm section code="", rodata="", rwdata="", zidata=".dma_dest_buffer_bss"
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_AE_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED_AE_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma arm section
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma arm section code="", rodata="", rwdata=".dma_dest_buffer", zidata=""
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma arm section
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif
/**************************************************************************************************/
/********************************************* IAR ************************************************/
/**************************************************************************************************/
#elif defined(_IAR_C_IMX8_)
/**************************************** GPT *******************************/
#ifdef GPT_START_SEC_CONFIG_DATA_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma default_variable_attributes = @ ".mcal_const_cfg"
    #else
        #ifndef GPT_STOP_SEC_CONFIG_DATA_8
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONFIG_DATA_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONFIG_DATA_8
        #undef GPT_START_SEC_CONFIG_DATA_8
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma default_variable_attributes = 
    #endif
    #undef GPT_STOP_SEC_CONFIG_DATA_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CONFIG_DATA_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma default_variable_attributes = @ ".mcal_const_cfg"
    #else
        #ifndef GPT_STOP_SEC_CONFIG_DATA_16
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONFIG_DATA_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONFIG_DATA_16
        #undef GPT_START_SEC_CONFIG_DATA_16
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma default_variable_attributes = 
    #endif
    #undef GPT_STOP_SEC_CONFIG_DATA_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CONFIG_DATA_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma default_variable_attributes = @ ".mcal_const_cfg"
    #else
        #ifndef GPT_STOP_SEC_CONFIG_DATA_32
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONFIG_DATA_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONFIG_DATA_32
        #undef GPT_START_SEC_CONFIG_DATA_32
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma default_variable_attributes = 
    #endif
    #undef GPT_STOP_SEC_CONFIG_DATA_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma default_variable_attributes = @ ".mcal_const_cfg"
    #else
        #ifndef GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
        #undef GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma default_variable_attributes = 
    #endif
    #undef GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CONST_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma default_variable_attributes = @ ".mcal_const"
    #else
        #ifndef GPT_STOP_SEC_CONST_BOOLEAN
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONST_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONST_BOOLEAN
        #undef GPT_START_SEC_CONST_BOOLEAN
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma default_variable_attributes = 
    #endif
    #undef GPT_STOP_SEC_CONST_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CONST_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma default_variable_attributes = @ ".mcal_const"
    #else
        #ifndef GPT_STOP_SEC_CONST_8
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONST_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONST_8
        #undef GPT_START_SEC_CONST_8
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma default_variable_attributes = 
    #endif
    #undef GPT_STOP_SEC_CONST_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CONST_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma default_variable_attributes = @ ".mcal_const"
    #else
        #ifndef GPT_STOP_SEC_CONST_16
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONST_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONST_16
        #undef GPT_START_SEC_CONST_16
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma default_variable_attributes = 
    #endif
    #undef GPT_STOP_SEC_CONST_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CONST_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma default_variable_attributes = @ ".mcal_const"
    #else
        #ifndef GPT_STOP_SEC_CONST_32
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONST_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONST_32
        #undef GPT_START_SEC_CONST_32
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma default_variable_attributes = 
    #endif
    #undef GPT_STOP_SEC_CONST_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CONST_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma default_variable_attributes = @ ".mcal_const"
    #else
        #ifndef GPT_STOP_SEC_CONST_UNSPECIFIED
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CONST_UNSPECIFIED
        #undef GPT_START_SEC_CONST_UNSPECIFIED
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma default_variable_attributes = 
    #endif
    #undef GPT_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CODE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma default_function_attributes = @ ".mcal_text"
    #else
        #ifndef GPT_STOP_SEC_CODE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CODE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CODE
        #undef GPT_START_SEC_CODE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma default_function_attributes =
    #endif
    #undef GPT_STOP_SEC_CODE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_RAMCODE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma default_function_attributes = @ ".ramcode"
    #else
        #ifndef GPT_STOP_SEC_RAMCODE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_RAMCODE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_RAMCODE
        #undef GPT_START_SEC_RAMCODE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma default_function_attributes =
    #endif
    #undef GPT_STOP_SEC_RAMCODE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CODE_AC
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma default_function_attributes = @ ".acgpt_code_rom"
    #else
        #ifndef GPT_STOP_SEC_CODE_AC
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_CODE_AC
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_CODE_AC
        #undef GPT_START_SEC_CODE_AC
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma default_function_attributes = 
    #endif
    #undef GPT_STOP_SEC_CODE_AC
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma default_variable_attributes = @ ".mcal_bss"
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_BOOLEAN
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_BOOLEAN
        #undef GPT_START_SEC_VAR_NO_INIT_BOOLEAN
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma default_variable_attributes =
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma default_variable_attributes = @ ".mcal_bss"
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_8
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_8
        #undef GPT_START_SEC_VAR_NO_INIT_8
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma default_variable_attributes =
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma default_variable_attributes = @ ".mcal_bss"
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_16
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_16
        #undef GPT_START_SEC_VAR_NO_INIT_16
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma default_variable_attributes =
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma default_variable_attributes = @ ".mcal_bss"
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_32
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_32
        #undef GPT_START_SEC_VAR_NO_INIT_32
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma default_variable_attributes =
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma default_variable_attributes = @ ".mcal_bss"
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED
        #undef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma default_variable_attributes =
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma default_variable_attributes = @ ".mcal_data"
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_BOOLEAN
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_BOOLEAN
        #undef GPT_START_SEC_VAR_INIT_BOOLEAN
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma default_variable_attributes =
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma default_variable_attributes = @ ".mcal_data"
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_8
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_8
        #undef GPT_START_SEC_VAR_INIT_8
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma default_variable_attributes =
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_8
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma default_variable_attributes = @ ".mcal_data"
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_16
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_16
        #undef GPT_START_SEC_VAR_INIT_16
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma default_variable_attributes =
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_16
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma default_variable_attributes = @ ".mcal_data"
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_32
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_32
        #undef GPT_START_SEC_VAR_INIT_32
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma default_variable_attributes =
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_32
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma default_variable_attributes = @ ".mcal_data"
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_UNSPECIFIED
        #undef GPT_START_SEC_VAR_INIT_UNSPECIFIED
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma default_variable_attributes =
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma default_variable_attributes = @ ".mcal_bss_no_cacheable"
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma default_variable_attributes =
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma default_variable_attributes = @ ".mcal_bss_no_cacheable"
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma default_variable_attributes =
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma default_variable_attributes = @ ".mcal_bss_no_cacheable"
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma default_variable_attributes =
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma default_variable_attributes = @ ".mcal_bss_no_cacheable"
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma default_variable_attributes =
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma default_variable_attributes = @ ".mcal_bss_no_cacheable"
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma default_variable_attributes =
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma default_variable_attributes = @ ".mcal_data_no_cacheable"
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma default_variable_attributes =
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma default_variable_attributes = @ ".mcal_data_no_cacheable"
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_8_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_INIT_8_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma default_variable_attributes =
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma default_variable_attributes = @ ".mcal_data_no_cacheable"
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_16_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_INIT_16_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma default_variable_attributes =
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma default_variable_attributes = @ ".mcal_data_no_cacheable"
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_32_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_INIT_32_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma default_variable_attributes =
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma default_variable_attributes = @ ".mcal_data_no_cacheable"
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma default_variable_attributes = 
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma default_variable_attributes = @ ".dma_dest_buffer_bss"
    #else
        #ifndef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_AE_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED_AE_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma default_variable_attributes = 
    #endif
    #undef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
        #pragma default_variable_attributes = @ ".dma_dest_buffer"
    #else
        #ifndef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #ifdef GPT_START_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
        #undef GPT_START_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    #else
        #error "Gpt_MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
        #pragma default_variable_attributes = 
    #endif
    #undef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Gpt_MemMap.h
    * @violates @ref Gpt_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
#endif
#endif 
/**************************************************************************************************/
/****************************************** Report error ******************************************/
/**************************************************************************************************/
#ifdef MEMMAP_ERROR
    #error "MemMap.h, no valid memory mapping symbol defined."
#endif
                                                                                                     
/*================================================================================================== 
*                                            ENUMS                                                   
==================================================================================================*/ 
                                                                                                     
/*================================================================================================== 
*                                 STRUCTURES AND OTHER TYPEDEFS                                      
==================================================================================================*/ 
                                                                                                     
/*================================================================================================== 
*                                 GLOBAL VARIABLE DECLARATIONS                                       
==================================================================================================*/ 
                                                                                                     
/*================================================================================================== 
*                                     FUNCTION PROTOTYPES                                            
==================================================================================================*/ 
                                                                                                     
#ifdef __cplusplus                                                                                   
}                                                                                                    
#endif                                                                                               
