/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: Dcm
 *           Program: MSR_Ford_SLP1 (MSR_Ford_SLP1)
 *          Customer: Visteon Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: i.MX8 DualX5
 *    License Scope : The usage is restricted to CBD2000484_D03
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Dcm_PBcfg.h
 *   Generation Time: 2022-06-13 12:18:05
 *           Project: Ford_S2dot8 - Version 1.0
 *          Delivery: CBD2000484_D03
 *      Tool Version: DaVinci Configurator  5.21.46 SP3
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * WARNING: This code has been generated with reduced-severity errors. 
 * The created output files contain errors that have been ignored. Usage of the created files can lead to unpredictable behavior of the embedded code.
 * Usage of the created files happens at own risk!
 * 
 * [Warning] DCM06013 - Invalid data identifier (DID) configuration - DcmDspDataConditionCheckReadFncUsed must be FALSE. 
 * - [Reduced Severity due to User-Defined Parameter] IO control DID /ActiveEcuC/Dcm/DcmConfigSet/DcmDsp/DID_61A4_Warning_Lamp_Status_1 does not support ConditionCheckReadFnc. Therefore all parameters with definition DefinitionRef: /MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFncUsed must exist and be equal to false.
 * Erroneous configuration elements:
 * /ActiveEcuC/Dcm/DcmConfigSet/DcmDsp/DID_61A4_Warning_Lamp_Status_1_CombinedDataElement[0:DcmDspDataConditionCheckReadFncUsed](value=true) (DefRef: /MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFncUsed)
 * 
 * [Warning] DCM06013 - Invalid data identifier (DID) configuration - DcmDspDataConditionCheckReadFncUsed must be FALSE. 
 * - [Reduced Severity due to User-Defined Parameter] IO control DID /ActiveEcuC/Dcm/DcmConfigSet/DcmDsp/Did_DID_61A5_Warning_Lamp_Status_2 does not support ConditionCheckReadFnc. Therefore all parameters with definition DefinitionRef: /MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFncUsed must exist and be equal to false.
 * Erroneous configuration elements:
 * /ActiveEcuC/Dcm/DcmConfigSet/DcmDsp/DID_61A5_BITMAP_Warning_Lamp_Status_2[0:DcmDspDataConditionCheckReadFncUsed](value=true) (DefRef: /MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFncUsed)
 * 
 * [Warning] DCM06013 - Invalid data identifier (DID) configuration - DcmDspDataConditionCheckReadFncUsed must be FALSE. 
 * - [Reduced Severity due to User-Defined Parameter] IO control DID /ActiveEcuC/Dcm/DcmConfigSet/DcmDsp/Did_SUPPLIER_USE_GenIllum_DID does not support ConditionCheckReadFnc. Therefore all parameters with definition DefinitionRef: /MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFncUsed must exist and be equal to false.
 * Erroneous configuration elements:
 * /ActiveEcuC/Dcm/DcmConfigSet/DcmDsp/SUPPLIER_USE_GenIllum_DID[0:DcmDspDataConditionCheckReadFncUsed](value=true) (DefRef: /MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFncUsed)
 * 
 * [Warning] DCM06013 - Invalid data identifier (DID) configuration - DcmDspDataConditionCheckReadFncUsed must be FALSE. 
 * - [Reduced Severity due to User-Defined Parameter] IO control DID /ActiveEcuC/Dcm/DcmConfigSet/DcmDsp/Did_SUPPLIER_USE_PointerIllum_DID does not support ConditionCheckReadFnc. Therefore all parameters with definition DefinitionRef: /MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFncUsed must exist and be equal to false.
 * Erroneous configuration elements:
 * /ActiveEcuC/Dcm/DcmConfigSet/DcmDsp/SUPPLIER_USE_PointerIllum_DID[0:DcmDspDataConditionCheckReadFncUsed](value=true) (DefRef: /MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFncUsed)
 * 
 * [Warning] DCM06013 - Invalid data identifier (DID) configuration - DcmDspDataConditionCheckReadFncUsed must be FALSE. 
 * - [Reduced Severity due to User-Defined Parameter] IO control DID /ActiveEcuC/Dcm/DcmConfigSet/DcmDsp/Did_SUPPLIER_USE_SetDisplayPWM does not support ConditionCheckReadFnc. Therefore all parameters with definition DefinitionRef: /MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFncUsed must exist and be equal to false.
 * Erroneous configuration elements:
 * /ActiveEcuC/Dcm/DcmConfigSet/DcmDsp/SUPPLIER_USE_SetDisplayPWM[0:DcmDspDataConditionCheckReadFncUsed](value=true) (DefRef: /MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataConditionCheckReadFncUsed)
 *********************************************************************************************************************/


#if !defined(DCM_PBCFG_H)
# define DCM_PBCFG_H
/* ----------------------------------------------
 ~&&&   Versions
---------------------------------------------- */

/*! Implementation version */
# define DCM_PBCFG_MAJOR_VERSION                                               13u
# define DCM_PBCFG_MINOR_VERSION                                                5u
# define DCM_PBCFG_PATCH_VERSION                                                0u
#endif /* !defined(DCM_PBCFG_H) */
/* ********************************************************************************************************************
 * END OF FILE: Dcm_PBcfg.h
 * ******************************************************************************************************************** */

