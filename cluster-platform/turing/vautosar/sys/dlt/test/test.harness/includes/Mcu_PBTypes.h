/*============================================================================*/
/* Project      = AUTOSAR Renesas F1x MCAL Components                         */
/* Module       = Mcu_PBTypes.h                                               */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2012-2017 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains the type definitions of Post-build Time Parameters      */
/*                                                                            */
/*============================================================================*/
/*                                                                            */
/* Unless otherwise agreed upon in writing between your company and           */
/* Renesas Electronics Corporation the following shall apply!                 */
/*                                                                            */
/* Warranty Disclaimer                                                        */
/*                                                                            */
/* There is no warranty of any kind whatsoever granted by Renesas. Any        */
/* warranty is expressly disclaimed and excluded by Renesas, either expressed */
/* or implied, including but not limited to those for non-infringement of     */
/* intellectual property, merchantability and/or fitness for the particular   */
/* purpose.                                                                   */
/*                                                                            */
/* Renesas shall not have any obligation to maintain, service or provide bug  */
/* fixes for the supplied Product(s) and/or the Application.                  */
/*                                                                            */
/* Each User is solely responsible for determining the appropriateness of     */
/* using the Product(s) and assumes all risks associated with its exercise    */
/* of rights under this Agreement, including, but not limited to the risks    */
/* and costs of program errors, compliance with applicable laws, damage to    */
/* or loss of data, programs or equipment, and unavailability or              */
/* interruption of operations.                                                */
/*                                                                            */
/* Limitation of Liability                                                    */
/*                                                                            */
/* In no event shall Renesas be liable to the User for any incidental,        */
/* consequential, indirect, or punitive damage (including but not limited     */
/* to lost profits) regardless of whether such liability is based on breach   */
/* of contract, tort, strict liability, breach of warranties, failure of      */
/* essential purpose or otherwise and even if advised of the possibility of   */
/* such damages. Renesas shall not be liable for any services or products     */
/* provided by third party vendors, developers or consultants identified or   */
/* referred to the User by Renesas in connection with the Product(s) and/or   */
/* the Application.                                                           */
/*                                                                            */
/*============================================================================*/
/* Environment:                                                               */
/*              Devices:        F1x                                           */
/*============================================================================*/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V1.0.0:  28-Sep-2012 : Initial Version
 *
 * V1.0.1:  23-Oct-2012 : As per SCR 031, MCU_LVI_MASK, MCU_LVI_CNT_MASK,
 *                        MCU_STBC0DISTRG_MASK, MCU_STBC0STPTRG_MASK and
 *                        MCU_MAX_MODE_SET macro values are corrected and
 *                        MCU_LVI_RESET_MASK_ENABLE macro is added.
 *
 * V1.0.2:  07-Nov-2012 : As per SCR 038, Following changes are made:
 *                        1.Port status backup functionality related structures
 *                          Mcu_PortGroupAddress and Mcu_PortRegisters,
 *                          variables Mcu_GaaPortGroup and
 *                          Mcu_GaaRamPortGroup are added.
 *                        2.ulPowerDownWakeupType2 element added in
 *                          Mcu_ModeSetting structure.
 *                        3.MCU_IOHOLD_MASK, MCU_MSB_MASK, MCU_CPU_EMGNCY_CLK
 *                          and MCU_CYCLIC_RUN_WAKEUP macros are added.
 *
 * V1.1.0:  23-Jan-2013 : As per SCR 059, Low power sequencer operation related
 *                        functionality is added as part of
 *                        Mcu_SequencerSetting, Mcu_DigitalInputSetting
 *                        structures and related macros are added.
 *
 * V1.2.0:  14-Mar-2013 : As per SCR 088, Mantis #7865 and #9586
 *                        MCU_CLOCK_DEFAULT, MCU_FOUT_CLOCK_ADDRESS
 *                        MCU_FOUT_CLOCK_DISABLE and  MCU_CPU_CLOCK_ADDRESS
 *                        macros are added.
 *
 * V1.3.0:  02-May-2013 : As per SCR 143, for Mantis #8153 and #9729 the
 *                        following changes are made:
 *                        1.blModeTransitionReq element is added as part
 *                          Mcu_ModeSetting structure.
 *                        2.Mcu_SequencerSetting and Mcu_DigitalInputSetting
 *                          structures are updated for supporting sequencer
 *                          functionality as per new cpu manual.
 *                        3.MCU_DIGITAL_NUMDP_MASK , MCU_TJS_MASK,
 *                          MCU_LONG_WORD_EIGHT, MCU_LONG_WORD_SIXTEEN, and
 *                          MCU_LONG_WORD_TWENTY_FOUR macros are added.
 *
 * V1.3.1: 14-Jun-2013 : As per SCR 180 Version check condition is added in
 *                       code.
 *
 * V1.4.0: 09-Jul-2013 : As per SCR 202, for mantis #10991, #11358, #12280 and
 *                       #12215 the following changes are made:
 *                       1. Mcu_SequencerSetting structure is updated with
 *                          pBaseCtlAddress, pImrCntlAddress, pIntrCntlAddress,
 *                          ulTauj0TimerCntVal and usIMRMaskVal elements to
 *                          support TAUJ0 initialization as part of sequencer
 *                          functionality.
 *                       2. Clock domain address related macros are added.
 *                       3. Mcu_ModeSetting structure is updated to add
 *                          blMcuMainOscOperation element to control operation
 *                          of main oscillator and its related functionalities
 *                          depending upon configuration in power down modes.
 *
 * V1.4.1: 12-Aug-2013 : As per CR 225, Copyright information is modified.
 *
 * V1.5.0: 15-Sep-2013 : As per CR 245, following changes are made
 *                       1. Global array for Clock Setting Configuration
 *                          Mcu_GaaClockOffset is added.
 *                       2. Pointer to callback notification is added in
 *                          structure Mcu_SequencerSetting.
 *                       3. Clock domain macro is added.
 *                       4. Copyright information is modified.
 *
 * V1.5.1: 10-Oct-2013 : As per CR 261, Following changes are made
 *                       1. As per mantis #15512 MCU_MAX_MODE_SET value
 *                          modified.
 *
 * V1.5.2: 17-Dec-2013 : As per CR 342, Following changes are made
 *                       1. Structure Mcu_TAUJUnitUserRegs is added with element
 *                          ucTAUJnTT.
 *                       2. Clock domain Macro are moved to the Mcu_Reg.h file
 *                       3. Macro MCU_STPM_NOT_AVAILABLE and MCU_DPDSRH_OFFSET
 *                          is added.
 *
 * V1.6.0: 26-Feb-2014 : As per CR 435, following changes are made:
 *                       1. MCU_PLL1_CLOCK_SELECTED macro is added.
 *                       2. MCU_WDR2 macro is added.
 *                       3. MCU_POR macro is removed.
 *                       3. Mcu_ClockSetting structure is modified for PLL1.
 *
 * V1.6.1: 27-Mar-2014 : As per CR 460, following changes are made:
 *                       1. MASK_WAKE_UP_FACTOR_REGISTERS macro is added.
 *                       2. Mcu_DigitalInputSetting structure pre-compile
 *                          options are update.
 *                       3. Unwanted macros removed.
 * V1.7.0: 09-Jun-2014 : As per CR 521, Following changes are made
 *                       1. As per mantis 20250, value of macro
 *                           MCU_LVI_DELAY_COUNT is updated.
 *                       2. For implementation of read back functionality
 *                          following macros are added MCU_AND_MASK,
 *                          MCU_OR_MASK, MCU_8BIT_SIZE_READBACK,
 *                          MCU_16BIT_SIZE_READBACK, MCU_32BIT_SIZE_READBACK,
 *                          MCU_VALUE_COMPARISON, MCU_READBACK16BIT_MASK,
 *                          MCU_READBACK8BIT_MASK, MCU_READBACK_DISABLE,
 *                          MCU_READBACK_INIT_ONLY, MCU_READBACK_RUNTIME_ONLY,
 *                          MCU_READBACK_INIT_AND_RUNTIME.
 *
 * V1.7.1: 10-Oct-2014: As per CR 637 MISRA C Rule Violation is added .
 *
 * V1.7.2: 05-Dec-2014  : As per Mantis#24187 Added semicolon after
 *                        CRITICAL_SECTION macro.
 * V1.7.3: 23-Feb-2015  : As part of V4.01.06, Added justification for
 *                        Misra violations(4:3412).
 * V1.7.4: 10-Jun-2015  : As part of 26696, updated the usage of macro
 *                        MCU_PLL1_ENABLE
 * V1.7.5: 28-Oct-2015  : As part of JIRA ticket ARDAAAB-1958, macro
 *                        MCU_MULTIPLE is added.
 * V1.8.0: 17-Mar-2016  : Following changes are made:
 *                        1. As per JIRA #ARDAAAC-447, ARDAAAA-525 and
 *                           ARDAAAB-3226, Storage Specifier is updated for
 *                           MCU_CONFIG_DATA from AUTOMATIC to TYPEDEF.
 *                        2. Copyright information is updated.
 *                        3. As per JIRA ARDAAAC-467, ARDAAAA-543, ARDAAAB-3463,
 *                           following changes are made:
 *                           a. ucTAUJnTE is added in STag_Mcu_TAUJUnitUserRegs.
 *                           b. Register Mirror Structure section is added for
 *                              STag_Mcu_32BitRegMirror,STag_Mcu_16BitRegMirror,
 *                              STag_Mcu_8BitRegMirror.
 *                           c. Extern call for Mcu_GaaReg32bitMirror,
 *                              Mcu_GaaReg32bitOriginal, Mcu_GaaReg16bitMirror,
 *                              Mcu_GaaReg16bitOriginal, Mcu_GaaReg8bitMirror,
 *                              Mcu_GaaReg8bitOriginal is added.
 *                           d. Masks used in WRITE_VERIFY are added.
 *                           e. Removed Macros MCU_AND_MASK, MCU_OR_MASK,
 *                              MCU_8BIT_SIZE_READBACK, MCU_16BIT_SIZE_READBACK,
 *                              MCU_32BIT_SIZE_READBACK, MCU_VALUE_COMPARISON,
 *                              MCU_READBACK16BIT_MASK, MCU_READBACK8BIT_MASK,
 *                              MCU_READBACK_DISABLE, MCU_READBACK_INIT_ONLY,
 *                              MCU_READBACK_RUNTIME_ONLY and
 *                              MCU_READBACK_INIT_AND_RUNTIME.
 *                        4. As part of fix for JIRA ARDAAAC-456 and
 *                           ARDAAAA-577, Mcu_ClockSetting has been updated to
 *                           add new element 'ulPLLStabTime' inside mew macro
 *                           'MCU_PLL_MODESELECT_ENABLED'.
 *                        5. As per JIRA ARDAAAC-454, ARDAAAA-529 and
 *                           ARDAAAB-3265, macro MCU_LVIFEIFMSK_MASK is updated
 *                           and MCU_WAKEUP_FACTOR_LVI_NOCLEAR,
 *                           MCU_LVILFEIF_MASK, MCU_LVIHFEIF_MASK,
 *                           MCU_LVILFEIFC_MASK, MCU_LVIHFEIFC_MASK is added.
 *                        6. As part of fix for JIRA ARDAAAC-495, ARDAAAA-578
 *                           and ARDAAAB-3224, Macro value 'MCU_LVIFEIFMSK_MASK'
 *                           has been updated.
 *                        7. As part of fix for JIRA ARDAAAC-569, ARDAAAA-631
 *                           and ARDAAAB-3173,
 *                           a. Variable declaration of 'pTAUJ0CMORRegs' inside
 *                              'STag_Mcu_SequencerSetting' structure has been
 *                              updated with volatile keyword.
 *                           b. Variable declaration of 'ulPSRn' inside
 *                              'STag_Mcu_PortRegisters' structure has been
 *                              updated with volatile keyword.
 *                        8. As per JIRA ARDAAAC-530, ARDAAAA-611 and
 *                           ARDAAAB-3239, MCU_RESFR_CLEAR macro is added.
 *                        9. As per JIRA ARDAAAB-3172,ARDAAAC-580 and
 *                           ARDAAAA-641,
 *                           'Mcu_ClockSetting' structure has been updated to
 *                           add new parameter 'ulSubOscStabCount'. Also the
 *                           parameter 'ulMainOscStabTime' has been renamed to
 *                           'ulMainClockStabCount'.
 *                       10. The software minor version has been updated.
 * V1.8.1: 20-May-2016  : Following changes are made:
 *                        1. As per JIRA ARDAAAC-467, ARDAAAA-543, ARDAAAB-3463,
 *                           MCU_WRITE_VERIFY_MASK14 macro has been updated.
 *                        2. As per JIRA ARDAAAB-3653, END tag for MISRA message
 *                           (4:3684) is corrected.
 * V1.8.2: 19-Sep-2016  : Following changes are made:
 *                        1. As part of JIRA ticket ARDAAAB-3714, mask names for
 *                           write verify and mirror are updated according to
 *                           the associated register.
 *                        2. As part of JIRA ARDAAAB-3680, ARDAAAC-856 and
 *                           ARDAAAA-945,macros are updated to add integer
 *                           literals.
 *                        3. As part of JIRA ARDAAAA-1103, ARDAAAC-975 Hard
 *                           coded numbers are replaced with macro names.
 *                        4. As part of JIRA ARDAAAC-805, ARDAAAA-889 and
 *                           ARDAAAB-3677,
 *                           a. 'CONFIG_DATA_UNSPECIFIED' Memory section is
 *                              updated based on AR version.
 *                           b. Memory Section for Mcu_GaaClockOffset is updated
 *                              to CONFIG_DATA_16.
 *                           c. Memory Section for Mcu_GaaRamPortGroup is
 *                              updated to BURAM_VAR_NOINIT_32.
 *                        5. As part of QAC, following changes are made:
 *                           a. START and END tags for (4:3684) is corrected.
 *                           b. MISRA warning (4:3453) is removed from the
 *                              message list.
 *                        6. As part of JIRA ARDAAAB-3443, ARDAAAC-583 and
 *                           ARDAAAA-643, macro MCU_SHORT_ZERO and
 *                           MCU_SAFETY_LOOP_COUNT is added.
 * V1.8.3: 13-Feb-2017  : Following changes are made:
 *                        1. As part of ARDAABL-481, Pre-compile switch
 *                           MCU_FOUT_ENABLE is added for the element
 *                           'usFoutDivReg' in structure 'Mcu_ClockSetting'.
 *                        2. Copyright information is updated.
 *                        3. As part of JIRA ARDAABL-750, Added trace for
 *                           unmapped requirements.
 */
/******************************************************************************/

#ifndef MCU_PBTYPES_H
#define MCU_PBTYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Included for Mcu type declarations */
/*Implements EAAR_PN0034_NR_0001, MCU108*/
#include "Mcu_Types.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
#if (MCU_AR_VERSION  == MCU_AR_HIGHER_VERSION)
/* AUTOSAR release version information */
#define MCU_PBTYPES_AR_RELEASE_MAJOR_VERSION \
                                        MCU_TYPES_AR_RELEASE_MAJOR_VERSION
#define MCU_PBTYPES_AR_RELEASE_MINOR_VERSION \
                                        MCU_TYPES_AR_RELEASE_MINOR_VERSION
#define MCU_PBTYPES_AR_RELEASE_REVISION_VERSION \
                                     MCU_TYPES_AR_RELEASE_REVISION_VERSION


#elif(MCU_AR_VERSION  == MCU_AR_LOWER_VERSION)
/* AUTOSAR specification version information */
#define MCU_PBTYPES_AR_MAJOR_VERSION       MCU_AR_MAJOR_VERSION_VALUE
#define MCU_PBTYPES_AR_MINOR_VERSION       MCU_AR_MINOR_VERSION_VALUE
#define MCU_PBTYPES_AR_PATCH_VERSION       MCU_AR_PATCH_VERSION_VALUE


#endif

#if (MCU_AR_VERSION  == MCU_AR_HIGHER_VERSION)
/* Module Software version information */
#define MCU_PBTYPES_SW_MAJOR_VERSION  1U
#define MCU_PBTYPES_SW_MINOR_VERSION  8U

#elif(MCU_AR_VERSION  == MCU_AR_LOWER_VERSION)
/* File version information */
#define MCU_PBTYPES_SW_MAJOR_VERSION     1U
#define MCU_PBTYPES_SW_MINOR_VERSION     8U

#endif
/*******************************************************************************
**                       MISRA C Rule Violations                              **
*******************************************************************************/
/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3684) Array declared with unknown size.                 */
/* Rule          : MISRA-C:2004 Rule 8.12                                     */
/* Justification : Arrays used are verified in the file which are only        */
/*                 declarations and size is configuration dependent.          */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3684)-1 and                           */
/*                 END Msg(4:3684)-1 tags in the code.                        */
/******************************************************************************/
/* 2.MISRA C RULE VIOLATION:                                                  */
/* Message       : (4:3412) A function could probably be used instead of this */
/*                function-like macro.                                        */
/* Rule          : MISRA-C:2004 Rule 19.4                                     */
/* Justification : Macro definition as multi-line operation hence multi-line  */
/*                 macro is used                                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3412)-2 and                           */
/*                 END Msg(4:3412)-2 tags in the code.                        */
/******************************************************************************/


/******************************************************************************
**                      SchM Critical Section Protection Macros              **
******************************************************************************/

#if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)

#if (MCU_AR_VERSION == MCU_AR_HIGHER_VERSION)
/* MISRA Violation: START Msg(4:3412)-2 */
#define MCU_ENTER_CRITICAL_SECTION(Exclusive_Area) \
      SchM_Enter_Mcu_##Exclusive_Area();

#define MCU_EXIT_CRITICAL_SECTION(Exclusive_Area) \
      SchM_Exit_Mcu_##Exclusive_Area();
/* END Msg(4:3412)-2 */

#elif (MCU_AR_VERSION == MCU_AR_LOWER_VERSION)
/* MISRA Violation: START Msg(4:3412)-2 */
#define MCU_ENTER_CRITICAL_SECTION(Exclusive_Area) \
      SchM_Enter_Mcu(Exclusive_Area);

#define MCU_EXIT_CRITICAL_SECTION(Exclusive_Area) \
      SchM_Exit_Mcu(Exclusive_Area);
#endif
/* END Msg(4:3412)-2 */
#endif /* MCU_CRITICAL_SECTION_PROTECTION == STD_ON */

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/* Macros to avoid Magic numbers */
#define MCU_DBTOC_VALUE \
                                      ((MCU_VENDOR_ID_VALUE << 22U) | \
                                       (MCU_MODULE_ID_VALUE << 14U) | \
                                       (MCU_SW_MAJOR_VERSION << 8U) | \
                                       (MCU_SW_MINOR_VERSION << 3U))

#define MCU_ZERO                      (uint8)0x00U
#define MCU_SIX                       (uint8)0x06U

#define MCU_SHORT_ZERO                (uint16)0x0000U

#define MCU_LONG_WORD_ZERO            (uint32)0x00000000UL

#define MCU_LONG_WORD_ONE             (uint32)0x00000001UL

#define MCU_LONG_WORD_TWO             (uint32)0x00000002UL

#define MCU_LONG_WORD_FOUR            (uint32)0x00000004UL

#define MCU_LONG_WORD_EIGHT           (uint32)0x00000008UL

#define MCU_LONG_WORD_SIXTEEN         (uint32)0x00000010UL

#define MCU_LONG_WORD_TWENTY_FOUR     (uint32)0x00000018UL

#define MCU_WAKEUP_FACTOR_CLR         (uint32)0xFFFFFFFFUL

#define MCU_STPM_NOT_AVAILABLE        (uint16)0xFFFFU

#define MCU_ONE                       (uint8)0x01U

#define MCU_TWO                       (uint8)0x02U

#define MCU_THREE                     (uint8)0x03U

#define MCU_FOUR                      (uint8)0x04U

#define MCU_INVERTED_ONE              (uint8)0xFEU

#define MCU_INVERTED_ZERO             (uint8)0xFFU

#define MCU_FIVE                      (uint8)0x05U

#define MCU_TEN                       (uint8)0x0AU

#define MCU_THIRTY_TWO                (uint8)0x20U

#define MCU_RESF_CLEAR                (uint32)0x000007FFUL

#define MCU_RESFR_CLEAR               (uint32)0x000007FFUL

#define MCU_INITIALIZED               (boolean)0x01U

#define MCU_UNINITIALIZED             (boolean)0x00U

#define MCU_TRUE                      (boolean)0x01U

#define MCU_FALSE                     (boolean)0x00U

/* Count for Safety Loop */
#define MCU_SAFETY_LOOP_COUNT         (uint16)0x03E8U

/* Value for selection of clock source as MainOSC */
#define MCU_MAIN_OSC_SELECTED         (uint8)0x01U

/* Value for selection of clock source as SubOSC */
#define MCU_SUB_OSC_SELECTED          (uint8)0x02U

/* Value for selection of clock source as PLL */
#define MCU_PLL_CLOCK_SELECTED       (uint8)0x08U

/* Value for selection of clock source as PLL */
#define MCU_PLL1_CLOCK_SELECTED       (uint8)0x10U

/* Definition of uninitialized RESET value */
#define MCU_RESET_UNINIT              (uint32)0xFFFFFFFFUL

/* Definition for Reset source check values */
/*Implements EAAR_PN0075_FR_0005, EAAR_PN0075_FR_0006*/
#define MCU_SWR                       (uint32)0x00000001UL
#define MCU_WDR0                      (uint32)0x00000002UL
#define MCU_WDR1                      (uint32)0x00000004UL
#define MCU_CLM0                      (uint32)0x00000008UL
#define MCU_CLM1                      (uint32)0x00000010UL
#define MCU_CLM2                      (uint32)0x00000020UL
#define MCU_LVI                       (uint32)0x00000040UL
#define MCU_CVM                       (uint32)0x00000080UL
#define MCU_TER                       (uint32)0x00000100UL
#define MCU_PURES                     (uint32)0x00000200UL
#define MCU_ISO                       (uint32)0x00000400UL
#ifdef MCU_WDG2_RESET_ENABLE
#define MCU_WDR2                      (uint32)0x00000800UL
#endif /* MCU_WDG2_RESET_ENABLE */
#define MCU_MULTIPLE                  (uint32)0x000007FFUL

/* Data to be written to the protection command register to enable
 * writing to the write protected register
 */
#define MCU_WRITE_DATA                (uint32)0x000000A5UL

/*
 * Definitions of values to be written to Software reset register
 * to perform reset
 */
#define MCU_RES_CORRECT_VAL           (uint32)0x00000001UL

#define MCU_RES_INVERTED_VAL          (uint32)0xFFFFFFFEUL

#define MCU_LVI_MASK                  (uint32)0x00000004UL

/* Maximum number of Clock setting */
#define MCU_MAX_CLK_SET               (uint8)0x04U

/* Maximum number of Mode setting */
#define MCU_MAX_MODE_SET              (uint8)0x07U

#define MCU_MAIN_OSC_MASKED           (uint8)0x01U

#define MCU_RING_OSC_MASKED           (uint8)0x04U

#define MCU_MAIN_OSC_ON               (uint32)0x00000004UL

#define MCU_SUB_OSC_ON                (uint32)0x00000004UL

#define MCU_PLL_ON                    (uint32)0x00000004UL

#define MCU_LONG_WORD_THREE           (uint32)0x00000003UL

#define MCU_FOUT_DISABLE_MASK         (uint32)0x00000000UL

#define MCU_LVIFEIF_MASK              (uint32)0x00000001UL

#define MCU_LVIFEIFC_MASK             (uint32)0x00000001UL

#define MCU_PLL_CLKSTAB_MASK          (uint32)0x00000004UL

#define MCU_LVIFEIFMSK_MASK           (uint32)0x00008001UL

#define MCU_LVILFEIF_MASK             (uint32)0x00000001UL

#define MCU_LVIHFEIF_MASK             (uint32)0x00008000UL

#define MCU_LVILFEIFC_MASK            (uint32)0x00008000UL

#define MCU_LVIHFEIFC_MASK            (uint32)0x00008000UL

#define MCU_LVI_RESET_MASK            (uint32)0x00000004UL

#define MCU_LVI_RESET_MASK_ENABLE     (uint32)0xFFFFFFF3UL

#define MCU_LVI_CNT_MASK              (uint32)0x00000007UL

#define MCU_STBC0DISTRG_MASK          (uint32)0x00000002UL

#define MCU_STBC0STPTRG_MASK          (uint32)0x00000001UL

#define MCU_LVI_DELAY_COUNT           (uint16)0x04FFU

#define MCU_CLKDOMAIN_SRCSEL          (uint8)0x01U

#define MCU_CLKDOMAIN_DIVSEL          (uint8)0x02U

#define MCU_CLKDOMAIN_STPMASK         (uint8)0x04U

#define MCU_CYCLIC_RUN_WAKEUP         (uint32)0x0000FFFFUL

#define MCU_IOHOLD_MASK               (uint32)0x00000001UL

#define MCU_MSB_MASK                  (uint32)0xFFFF0000UL

#define MCU_DIGITAL_NUMDP_MASK        (uint32)0x00000070UL

#define MCU_TJS_MASK                  (uint32)0x0000000cUL

#define MCU_SEQ_STOP_MASK             (uint32)0x00000003UL

#define MCU_WUTRG_SEQ                 (uint32)0x00080000UL

#define MCU_CLOCK_DEFAULT             (uint32)0x00000001UL

#define MCU_CPU_CLOCK_ADDRESS         (uint32 *)0xFFF8A000UL

#define MCU_CLKBIT_MASK               (uint8)0xCFU

#define MCU_CLKBIT_SETMASK            (uint8)0x30U

#define MCU_DPDSRH_OFFSET      (uint32) (MCU_DATA_SET_REGISTER + MCU_THIRTY_TWO)

#define MASK_WAKE_UP_FACTOR_REGISTERS    (uint32) 0xFFFFFFFFUL

#define MCU_WAKEUP_FACTOR_LVI_NOCLEAR     (uint32)0xFFFFFFFBUL


/* Masks used in WRITE_VERIFY and HW Consistency */
#define MCU_WV_DPIN_0_H_MASK             (uint32)0x00FFFFFFUL
#define MCU_WV_32BIT_NO_MASK             (uint32)0xFFFFFFFFUL
#define MCU_WV_CLMA_MASK                 (uint16)0x0FFFU
#define MCU_WV_TAUJ_CH_EN_MASK           (uint8)0x0FU
#define MCU_WV_16BIT_NO_MASK             (uint16)0xFFFFU
#define MCU_WV_TAUJ_BRS_NO_MASK          (uint8)0xFFU
#define MCU_WV_EVFR_MASK                 (uint32)0x00000001UL
#define MCU_WV_CLMA_CTL_MASK             (uint8)0x01U
#define MCU_WV_FOUTDIV_MASK              (uint32)0x0000003FUL
#define MCU_WV_MOSCC_MASK                (uint32)0x00000007UL
#define MCU_WV_MOSCST_MASK               (uint32)0x0001FFFFUL
#define MCU_WV_SOSCST_MASK               (uint32)0x3FFFFFFFUL
#define MCU_WV_STPM_MASK                 (uint32)0x00000003UL
#define MCU_WV_SCTLR_MASK                (uint32)0x0000007FUL
#if (MCU_PLL_MODESELECT_ENABLED == STD_ON)
#define MCU_WV_PLLC_MASK                 (uint32)0x7F707F7FUL
#else
#define MCU_WV_PLLC_MASK                 (uint32)0x00011F3FUL
#endif
#define MCU_WV_PLL0ST_MASK               (uint32)0x00001FFFUL
#define MCU_WV_PLL1C_MASK                (uint32)0x00011F3FUL
#define MCU_WV_TAUJ_CMOR_MASK            (uint16)0xFFDFU

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/*******************************************************************************
**                Port Control Registers Data Structure                       **
*******************************************************************************/
/* Implements MCU_ESDD_UD_131 */
typedef struct STag_Mcu_PortRegisters
{
  volatile uint32 ulPSRn;
} Mcu_PortRegisters;
/*******************************************************************************
*                        DEM TYPE CASTING                                      *
*******************************************************************************/
/* Macros for DEM */
#if (MCU_AR_VERSION == MCU_AR_LOWER_VERSION)
  #define MCU_DEM_TYPE uint8
#else
  #define MCU_DEM_TYPE Dem_EventStatusType
#endif

/******************************************************************************/
/*******************************************************************************
**                      Clock Setting Data Structure                          **
*******************************************************************************/

typedef struct STag_Mcu_ClockSetting
{
  /* Pointer to CKSC register selection structure */
  P2CONST(void, AUTOMATIC, MCU_CONFIG_CONST) pCkscSel;
  #if (MCU_PLL_ENABLE == STD_ON)
  /* Details of PLL */
  uint32 ulPLLControlValue;
  #if (MCU_PLL_MODESELECT_ENABLED == STD_ON)
  /* PLL stabilization value*/
  /*Implements EAAR_PN0075_FR_0014*/
  uint32 ulPLLStabTime;
  #endif
  #endif
  #if (MCU_PLL1_ENABLE == STD_ON)
  /* Details of PLL1 */
  uint32 ulPLL1ControlValue;
  #endif
  #if (MCU_MAINOSC_ENABLE == STD_ON)
  /*Implements EAAR_PN0075_FR_0014*/
  /* Main Oscillator Stabilization Time */
  uint32 ulMainClockStabCount;
  #endif
  #if (MCU_SUBOSC_ENABLE == STD_ON)
  /* Main Oscillator Stabilization Time */
  uint32 ulSubOscStabCount;
  #endif
  #if (MCU_FOUT_ENABLE == STD_ON)
  /* FOUT Clock Divider register */
  uint16 usFoutDivReg;
  #endif
  /* Details of selected clock sources */
  uint8 ucSelectedSrcClock;
  #if (MCU_MAINOSC_ENABLE == STD_ON)
  /* Value for MOSCC register */
  uint8 ucMosccRegValue;
  #endif
  /* Selection of STPMK bit in all clock sources */
  uint8 ucSelectedSTPMK;
  /* Value of number of clock registers for ISO selected */
  uint8 ucNoOfIsoCkscReg;
  /* Value of number of clock registers for AWO selected */
  uint8 ucNoOfAwoCkscReg;
  /* Value of number of PLL clock registers for ISO selected */
  uint8 ucNoOfPllIsoCkscReg;
  /* Value of number of PLL  clock registers for AWO selected */
  uint8 ucNoOfPllAwoCkscReg;
  /* PLL CKSC Index offset */
  uint8 ucCkscPllIndexOffset;

} Mcu_ClockSetting;


typedef struct STag_Mcu_CkscSetting
{
  /* CKSC source clock selection register address offset */
  uint16 usCkscSourceSelRegOffset;
  /* CKSC source clock divider register address offset */
  uint16 usCkscDividerSelRegOffset;
  /* CKSC source STPMSK  register address offset */
  uint16 usCkscStpmskSelRegOffset;
  /* CKSC source clock selection register Value */
  uint8 ucCkscSourceSelRegValue;
  /* CKSC Divider clock selection register Value */
  uint8 ucCkscDividerSelRegValue;
  /* CKSC Selection control for Source, Divider and  STPMSK selection */
  uint8 ucCkscControlval;

} Mcu_CkscSetting;

/*******************************************************************************
**Structure pointing to the Pn register address of each Port group configured **
*******************************************************************************/

typedef struct STag_Mcu_PortGroupAddress
{
  P2VAR(Mcu_PortRegisters, TYPEDEF, MCU_CONFIG_DATA)pPortGroupAddress;
} Mcu_PortGroupAddress;

/*******************************************************************************
**                  Power Mode Setting Data Structure                         **
*******************************************************************************/

typedef struct STag_Mcu_ModeSetting
{
  /* Value of Power Down Wakeup source 1 */
  uint32 ulPowerDownWakeupType0;
  /* Value of Power Down Wakeup source for ISO */
  uint32 ulPowerDownWakeupTypeISO0;
  /* Value of Power Down Wakeup source for 2 */
  uint32 ulPowerDownWakeupType2;
  /* Power down modes macro types*/
  uint8 ucModeType;
  /* enable/disable the actual transition to the low power modes */
  boolean blModeTransitionReq;
  /* enable/disable the Main oscillator operation in low power modes */
  boolean blMcuMainOscOperation;
} Mcu_ModeSetting;

#if (MCU_LOW_POWER_SEQUENCER == STD_ON)
/*******************************************************************************
**                  Low power sequencer Data Structure                        **
*******************************************************************************/
typedef struct STag_Mcu_SequencerSetting
{
  /*Implements MCU_ESDD_UD_040*/
  #if (MCU_DIGITAL_INPUT_MODE == STD_ON)
  /* Pointer to Digital Input Selection structure */
  P2CONST(void, AUTOMATIC, MCU_CONFIG_CONST) pDigitalInputModeSetting;
  #endif
  #if (MCU_TAUJ0_INIT == STD_ON)
  /* Pointer to TAUJ0 Channel Start Trigger Register */
  P2VAR(void, TYPEDEF, MCU_CONFIG_DATA)pTAUJ0UnitUserRegs;
  /* Pointer to TAUJ0 Prescaler Clock Select Register */
  P2VAR(void, TYPEDEF, MCU_CONFIG_DATA)pTAUJ0UnitOsRegs;
  /* Pointer to TAUJ0 Channel Data Register */
  P2VAR(void, TYPEDEF, MCU_CONFIG_DATA)pTAUJ0UserRegs;
  /* Pointer to TAUJ0 Channel Mode OS Register */
  P2VAR(volatile uint16, TYPEDEF, MCU_CONFIG_DATA)pTAUJ0CMORRegs;
  #endif
  /* Element for sequencer control register for setting both Digital and
   * Analog mode
   */
  uint32 ulSequencerCtlReg;
  #if (MCU_TAUJ0_INIT == STD_ON)
  /* Value for initializing the Timer TAUJ0 channel with CDRn value */
  uint32 ulTauj0TimerCntVal;
  #endif
  /* Element for setting external sensor stabilization time in digital input
   * and Analog input modes.
   */
  uint16 usExternalSensorStabTime;
  #if (MCU_TAUJ0_INIT == STD_ON)
  /* Implements MCU_ESDD_UD_044 */
  #if (MCU_TAUJ0_PRESCALAR == STD_ON)
  /* Prescaler selection for TAUJ0 unit */
  uint16 usPrescaler;
  /* Baud rate selection for TAUJ0 unit */
  uint8 ucBaudRate;
  #endif
  /* Channel mask details of the selected TAUJ0 channel */
  uint8 ucChannelMask;
  #endif
}Mcu_SequencerSetting;


/*******************************************************************************
**                  Low power sequencer Digital Input Pins Data Structure     **
*******************************************************************************/
typedef struct STag_Mcu_DigitalInputSetting
{
  /* Element for selecting Digital Pins for Sequencer supervising in DPSELR0
   * register ie D0EN_0 to D0EN_23.
   */
  uint32 ulDigitalPinSelReg0;
  #if (MCU_DPIN_SEL_REG_M == STD_ON)
  /* Element for selecting Digital Pins for Sequencer supervising in DPSELRM
   * register.
   *    D1EN_0 to D1EN_7
   *    D2EN_0 to D2EN_7
   *    D3EN_0 to D3EN_7
   *    D4EN_0 to D4EN_7
   */
  uint32 ulDigitalPinSelRegM;
  #endif
  #if (MCU_DPIN_SEL_REG_H == STD_ON)
  /* Element for selecting Digital Pins for Sequencer supervising in DPSELH
   * register.
   *    D5EN_0 to D5EN_7
   *    D6EN_0 to D6EN_7
   *    D7EN_0 to D7EN_7
   */
  uint32 ulDigitalPinSelRegH;
  #endif
  /* Initial Data state for selected Digital Pins in Sequencer operation for
   * D0EN_0 to D0EN_23 of DPDSR0 register
   */
  uint32 ulDigitalPinDataSetReg0;
  #if (MCU_DPIN_SEL_REG_M == STD_ON)
  /* Initial Data state for selected Digital Pins in Sequencer operation for
   *  D1EN_0 to D1EN_7
   *  D2EN_0 to D2EN_7
   *  D3EN_0 to D3EN_7
   *  D4EN_0 to D4EN_7 of DPDSRM register
   */
  uint32 ulDigitalPinDataSetRegM;
  #endif

  #if (MCU_DPIN_SEL_REG_H == STD_ON)
  /* Initial Data state for selected Digital Pins in Sequencer operation for
   *  D5EN_0 to D5EN_7
   *  D6EN_0 to D6EN_7
   *  D7EN_0 to D7EN_7 of DPDSRH register
   */
  uint32 ulDigitalPinDataSetRegH;
  #endif

}Mcu_DigitalInputSetting;

#endif

/* Implements MCU_ESDD_UD_135 */
typedef struct STag_Mcu_TAUJUnitUserRegs
{
  uint8  volatile ucTAUJnTE;
  uint8  volatile aaReserved1[MCU_THREE];
  uint8  volatile ucTAUJnTS;
  uint8  volatile aaReserved2[MCU_THREE];
  uint8  volatile ucTAUJnTT;
} Mcu_TAUJUnitUserRegs;

/* Implements MCU_ESDD_UD_136 */
typedef struct STag_Mcu_TAUJUnitOsRegs
{
  uint16 volatile usTAUJnTPS;
  uint16 volatile usReserved1;
  uint8  volatile ucTAUJnBRS;
} Mcu_TAUJUnitOsRegs;

typedef struct STag_Mcu_TAUJUserRegs
{
  uint32 volatile ulTAUJnCDRm;
  uint32 volatile aaReserved1[MCU_LONG_WORD_THREE];
} Mcu_TAUJChannelUserRegs;


/*******************************************************************************
**                Register Mirror Structure                                   **
*******************************************************************************/
typedef struct STag_Mcu_32BitRegMirror
{
  uint32 ulDPDSR0Mirror;
  uint32 ulDPDSRMMirror;
  uint32 ulDPDSRHMirror;
  uint32 ulEVFRMirror;
  uint32 ulMOSCCMirror;
  uint32 ulMOSCSTMirror;
  uint32 ulMOSCSTPMMirror;
  uint32 ulROSCSTPMMirror;
  uint32 ulSOSCSTMirror;
  uint32 ulFOUTDIVMirror;
  uint32 ulWUFMSK0Mirror;
  uint32 ulWUFMSK_ISO0Mirror;
  uint32 ulWUFMSK20Mirror;
  uint32 ulSCTLRMirror;
  uint32 ulDPSELR0Mirror;
  uint32 ulDPSELRMMirror;
  uint32 ulDPSELRHMirror;
  uint32 ulPLLCMirror;
  uint32 ulPLL1CMirror;
  uint32 ulPLL0STMirror;
  uint32 ulTAUJ0CDRmMirror;
}Mcu_32BitRegMirror;

typedef struct STag_Mcu_16BitRegMirror
{
  uint16 usCNTVALMirror;
  uint16 usCLMA0CMPHMirror;
  uint16 usCLMA0CMPLMirror;
  uint16 usCLMA1CMPHMirror;
  uint16 usCLMA1CMPLMirror;
  uint16 usCLMA2CMPHMirror;
  uint16 usCLMA2CMPLMirror;
  uint16 usTAUJ0TPSMirror;
  uint16 usTAUJ0CMORMirror;
}Mcu_16BitRegMirror;

typedef struct STag_Mcu_8BitRegMirror
{
  uint8 ucTAUJ0BRSMirror;
}Mcu_8BitRegMirror;

/*******************************************************************************
**                       Extern declarations for Global Data                  **
*******************************************************************************/
#if (MCU_AR_VERSION  == MCU_AR_HIGHER_VERSION)
#define MCU_START_SEC_CONFIG_DATA_16
#elif(MCU_AR_VERSION  == MCU_AR_LOWER_VERSION)
#define MCU_START_CONFIG_DATA_16BIT
#endif
#include "MemMap.h"

/* Implements MCU_ESDD_UD_062 */
/* MISRA Violation: START Msg(4:3684)-1 */
/* Global array for Clock Setting Configuration */
extern CONST(uint16, MCU_CONST) Mcu_GaaClockOffset[];
/* END Msg(4:3684)-1 */
#if (MCU_AR_VERSION  == MCU_AR_HIGHER_VERSION)
#define MCU_STOP_SEC_CONFIG_DATA_16
#elif(MCU_AR_VERSION  == MCU_AR_LOWER_VERSION)
#define MCU_STOP_CONFIG_DATA_16BIT
#endif
#include "MemMap.h"

#if (MCU_AR_VERSION  == MCU_AR_HIGHER_VERSION)
#define MCU_START_SEC_CONFIG_DATA_UNSPECIFIED
#elif(MCU_AR_VERSION  == MCU_AR_LOWER_VERSION)
#define MCU_START_CONFIG_DATA_UNSPECIFIED
#endif
#include "MemMap.h"

/* Implements MCU_ESDD_UD_061 */
/* MISRA Violation: START Msg(4:3684)-1 */
/* Global array for the configured CKSC registers */
extern CONST(Mcu_CkscSetting, MCU_CONST)Mcu_GstCkscSetting[];

/* Implements MCU_ESDD_UD_059 */
/* Global array for Clock Setting Configuration */
extern CONST(Mcu_ClockSetting, MCU_CONST) Mcu_GstClockSetting[];

/* Implements MCU_ESDD_UD_060 */
/* Global array for Mode Setting Configuration */
extern CONST(Mcu_ModeSetting, MCU_CONST) Mcu_GstModeSetting[];
/* END Msg(4:3684)-1 */
#if (MCU_LOW_POWER_SEQUENCER == STD_ON)
/* Implements MCU_ESDD_UD_064 */
/* MISRA Violation: START Msg(4:3684)-1 */
/* Global array for Low Power Sequencer Setting Configuration */
extern CONST(Mcu_SequencerSetting, MCU_CONST) Mcu_GstSequencerSetting[];

/* Global array for Low Power Sequencer Setting of Digital Input Configuration
 */
extern CONST(Mcu_DigitalInputSetting, MCU_CONST)
                                     Mcu_GstDigitalInputModeSetting[];
/* END Msg(4:3684)-1 */
#endif
/* Implements MCU_ESDD_UD_063 */
/* MISRA Violation: START Msg(4:3684)-1 */
/* Global array of port registers */
extern CONST(Mcu_PortGroupAddress, MCU_CONST) Mcu_GaaPortGroup[];
/* END Msg(4:3684)-1 */

/* MISRA Violation: START Msg(4:3684)-1 */
extern CONSTP2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_DATA)
                                                     Mcu_GaaReg32bitMirror[];
extern CONSTP2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_DATA)
                                                     Mcu_GaaReg32bitOriginal[];

extern CONSTP2VAR(volatile uint16, AUTOMATIC, MCU_CONFIG_DATA)
                                                     Mcu_GaaReg16bitMirror[];
extern CONSTP2VAR(volatile uint16, AUTOMATIC, MCU_CONFIG_DATA)
                                                     Mcu_GaaReg16bitOriginal[];

extern CONSTP2VAR(volatile uint8, AUTOMATIC, MCU_CONFIG_DATA)
                                                     Mcu_GaaReg8bitMirror[];
extern CONSTP2VAR(volatile uint8, AUTOMATIC, MCU_CONFIG_DATA)
                                                     Mcu_GaaReg8bitOriginal[];
/* END Msg(4:3684)-1 */
#if (MCU_AR_VERSION  == MCU_AR_HIGHER_VERSION)
#define MCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#elif(MCU_AR_VERSION  == MCU_AR_LOWER_VERSION)
#define MCU_STOP_CONFIG_DATA_UNSPECIFIED
#endif
#include "MemMap.h"

#if (MCU_AR_VERSION  == MCU_AR_HIGHER_VERSION)
#define MCU_START_SEC_BURAM_VAR_NO_INIT_32
#elif(MCU_AR_VERSION  == MCU_AR_LOWER_VERSION)
#define MCU_START_SEC_BURAM_VAR_NOINIT_32BIT
#endif
#include "MemMap.h"
/* MISRA Violation: START Msg(4:3684)-1 */
/* Global RAM array for back up of Port group registers */
extern VAR(uint32, MCU_CONFIG_DATA) Mcu_GaaRamPortGroup[];
/* END Msg(4:3684)-1 */
#if (MCU_AR_VERSION  == MCU_AR_HIGHER_VERSION)
#define MCU_STOP_SEC_BURAM_VAR_NO_INIT_32
#elif(MCU_AR_VERSION  == MCU_AR_LOWER_VERSION)
#define MCU_STOP_SEC_BURAM_VAR_NOINIT_32BIT
#endif
#include "MemMap.h"

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* MCU_PBTYPES_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
