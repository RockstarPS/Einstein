/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_CComAbsMdl_stubs.h
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Application header file for SW-C <CComAbsMdl_stubs>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CCOMABSMDL_STUBS_H
# define _RTE_CCOMABSMDL_STUBS_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
#  ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#   define RTE_PTR2ARRAYBASETYPE_PASSING
#  endif
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_CComAbsMdl_stubs_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

#  include "Com.h"


# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_pp_SR_TxCurrentStateIC_CurrentStateIC (FALSE)
#  define Rte_InitValue_pp_SR_TxDebug1_Byte0_Debug1_Byte0 (0U)
#  define Rte_InitValue_pp_SR_TxDebug1_Byte1_Debug1_Byte1 (0U)
#  define Rte_InitValue_pp_SR_TxDebug1_Byte2_Debug1_Byte2 (0U)
#  define Rte_InitValue_pp_SR_TxDebug1_Byte3_Debug1_Byte3 (0U)
#  define Rte_InitValue_pp_SR_TxDebug1_Byte4_Debug1_Byte4 (0U)
#  define Rte_InitValue_pp_SR_TxDebug1_Byte5_Debug1_Byte5 (0U)
#  define Rte_InitValue_pp_SR_TxDebug1_Byte6_Debug1_Byte6 (0U)
#  define Rte_InitValue_pp_SR_TxDebug1_Byte7_Debug1_Byte7 (0U)
#  define Rte_InitValue_pp_SR_TxDebug2_Byte0_Debug2_Byte0 (0U)
#  define Rte_InitValue_pp_SR_TxDebug2_Byte1_Debug2_Byte1 (0U)
#  define Rte_InitValue_pp_SR_TxDebug2_Byte2_Debug2_Byte2 (0U)
#  define Rte_InitValue_pp_SR_TxDebug2_Byte3_Debug2_Byte3 (0U)
#  define Rte_InitValue_pp_SR_TxDebug2_Byte4_Debug2_Byte4 (0U)
#  define Rte_InitValue_pp_SR_TxDebug2_Byte5_Debug2_Byte5 (0U)
#  define Rte_InitValue_pp_SR_TxDebug2_Byte6_Debug2_Byte6 (0U)
#  define Rte_InitValue_pp_SR_TxDebug2_Byte7_Debug2_Byte7 (0U)
#  define Rte_InitValue_pp_SR_TxDebug3_Byte0_Debug3_Byte0 (0U)
#  define Rte_InitValue_pp_SR_TxDebug3_Byte1_Debug3_Byte1 (0U)
#  define Rte_InitValue_pp_SR_TxDebug3_Byte2_Debug3_Byte2 (0U)
#  define Rte_InitValue_pp_SR_TxDebug3_Byte3_Debug3_Byte3 (0U)
#  define Rte_InitValue_pp_SR_TxDebug3_Byte4_Debug3_Byte4 (0U)
#  define Rte_InitValue_pp_SR_TxDebug3_Byte5_Debug3_Byte5 (0U)
#  define Rte_InitValue_pp_SR_TxDebug3_Byte6_Debug3_Byte6 (0U)
#  define Rte_InitValue_pp_SR_TxDebug3_Byte7_Debug3_Byte7 (0U)
#  define Rte_InitValue_pp_SR_TxDebug4_Byte0_Debug4_Byte0 (0U)
#  define Rte_InitValue_pp_SR_TxDebug4_Byte1_Debug4_Byte1 (0U)
#  define Rte_InitValue_pp_SR_TxDebug4_Byte2_Debug4_Byte2 (0U)
#  define Rte_InitValue_pp_SR_TxDebug4_Byte3_Debug4_Byte3 (0U)
#  define Rte_InitValue_pp_SR_TxDebug4_Byte4_Debug4_Byte4 (0U)
#  define Rte_InitValue_pp_SR_TxDebug4_Byte5_Debug4_Byte5 (0U)
#  define Rte_InitValue_pp_SR_TxDebug4_Byte6_Debug4_Byte6 (0U)
#  define Rte_InitValue_pp_SR_TxDebug4_Byte7_Debug4_Byte7 (0U)
#  define Rte_InitValue_pp_SR_TxDebug5_Byte0_Debug5_Byte0 (0U)
#  define Rte_InitValue_pp_SR_TxDebug5_Byte1_Debug5_Byte1 (0U)
#  define Rte_InitValue_pp_SR_TxDebug5_Byte2_Debug5_Byte2 (0U)
#  define Rte_InitValue_pp_SR_TxDebug5_Byte3_Debug5_Byte3 (0U)
#  define Rte_InitValue_pp_SR_TxDebug5_Byte4_Debug5_Byte4 (0U)
#  define Rte_InitValue_pp_SR_TxDebug5_Byte5_Debug5_Byte5 (0U)
#  define Rte_InitValue_pp_SR_TxDebug5_Byte6_Debug5_Byte6 (0U)
#  define Rte_InitValue_pp_SR_TxDebug5_Byte7_Debug5_Byte7 (0U)
#  define Rte_InitValue_pp_SR_TxFV_Tx_FV_Tx (0U)
#  define Rte_InitValue_pp_SR_TxIllumination_PWM_Illumination_PWM (0U)
#  define Rte_InitValue_pp_SR_TxMAC_Tx_MAC_Tx (0U)
#  define Rte_InitValue_pp_SR_TxOdometer_Odometer (0U)
#  define Rte_InitValue_pp_SR_TxPreviousStateIC_PreviousStateIC (0)
#  define Rte_InitValue_pp_SR_TxSecureTxByte0_SecureTxByte0 (0U)
#  define Rte_InitValue_pp_SR_TxSecureTxByte1_SecureTxByte1 (0U)
#  define Rte_InitValue_pp_SR_TxSecureTxByte2_SecureTxByte2 (0U)
#  define Rte_InitValue_pp_SR_TxSecureTxByte3_SecureTxByte3 (0U)
#  define Rte_InitValue_pp_SR_TxUserData1_IC_UserData1_IC (0U)
#  define Rte_InitValue_pp_SR_TxUserData2_IC_UserData2_IC (0U)
#  define Rte_InitValue_pp_SR_TxUserData3_IC_UserData3_IC (0U)
#  define Rte_InitValue_pp_SR_TxUserData4_IC_UserData4_IC (0U)
#  define Rte_InitValue_pp_SR_TxUserData5_IC_UserData5_IC (0U)
#  define Rte_InitValue_pp_SR_TxVehicleSpeedIC_VehicleSpeedIC (0U)
#  define Rte_InitValue_rpSR_RxAirbag_Airbag (0U)
#  define Rte_InitValue_rp_SR_RxAirbag_Airbag (0U)
#  define Rte_InitValue_rp_SR_RxAlive_101_Alive_101 (0U)
#  define Rte_InitValue_rp_SR_RxAmbient_Light_level_Ambient_Light_level (0U)
#  define Rte_InitValue_rp_SR_RxCRC_101_CRC_101 (0U)
#  define Rte_InitValue_rp_SR_RxCurrentStateIC_CurrentStateIC (FALSE)
#  define Rte_InitValue_rp_SR_RxDayNightMode_DayNightMode (FALSE)
#  define Rte_InitValue_rp_SR_RxEngineSpeed_EngineSpeed (0U)
#  define Rte_InitValue_rp_SR_RxEngineSpeed_1_EngineSpeed (0U)
#  define Rte_InitValue_rp_SR_RxGear_Gear (0U)
#  define Rte_InitValue_rp_SR_RxGearMode_GearMode (FALSE)
#  define Rte_InitValue_rp_SR_RxGearRecommendation_GearRecommendation (0U)
#  define Rte_InitValue_rp_SR_RxGearStatus_GearStatus (0U)
#  define Rte_InitValue_rp_SR_RxIllumination_level_Illumination_level (0U)
#  define Rte_InitValue_rp_SR_RxPowerMode_PowerMode (0U)
#  define Rte_InitValue_rp_SR_RxTransportMode_TransportMode (FALSE)
#  define Rte_InitValue_rp_SR_RxTurn_Indicator_Control_Turn_Indicator_Control (0U)
#  define Rte_InitValue_rp_SR_RxTurn_Indicator_Control_1_Turn_Indicator_Control (0U)
#  define Rte_InitValue_rp_SR_RxVehicleSpeedABS_VehicleSpeedABS (0U)
#  define Rte_InitValue_rp_SR_RxWarning_Warning (0U)
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxCurrentStateIC_CurrentStateIC(CurrentStateIC data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug1_Byte0_Debug1_Byte0(Debug1_Byte0 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug1_Byte1_Debug1_Byte1(Debug1_Byte1 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug1_Byte2_Debug1_Byte2(Debug1_Byte2 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug1_Byte3_Debug1_Byte3(Debug1_Byte3 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug1_Byte4_Debug1_Byte4(Debug1_Byte4 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug1_Byte5_Debug1_Byte5(Debug1_Byte5 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug1_Byte6_Debug1_Byte6(Debug1_Byte6 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug1_Byte7_Debug1_Byte7(Debug1_Byte7 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug2_Byte0_Debug2_Byte0(Debug2_Byte0 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug2_Byte1_Debug2_Byte1(Debug2_Byte1 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug2_Byte2_Debug2_Byte2(Debug2_Byte2 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug2_Byte3_Debug2_Byte3(Debug2_Byte3 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug2_Byte4_Debug2_Byte4(Debug2_Byte4 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug2_Byte5_Debug2_Byte5(Debug2_Byte5 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug2_Byte6_Debug2_Byte6(Debug2_Byte6 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug2_Byte7_Debug2_Byte7(Debug2_Byte7 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug3_Byte0_Debug3_Byte0(Debug3_Byte0 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug3_Byte1_Debug3_Byte1(Debug3_Byte1 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug3_Byte2_Debug3_Byte2(Debug3_Byte2 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug3_Byte3_Debug3_Byte3(Debug3_Byte3 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug3_Byte4_Debug3_Byte4(Debug3_Byte4 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug3_Byte5_Debug3_Byte5(Debug3_Byte5 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug3_Byte6_Debug3_Byte6(Debug3_Byte6 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug3_Byte7_Debug3_Byte7(Debug3_Byte7 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug4_Byte0_Debug4_Byte0(Debug4_Byte0 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug4_Byte1_Debug4_Byte1(Debug4_Byte1 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug4_Byte2_Debug4_Byte2(Debug4_Byte2 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug4_Byte3_Debug4_Byte3(Debug4_Byte3 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug4_Byte4_Debug4_Byte4(Debug4_Byte4 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug4_Byte5_Debug4_Byte5(Debug4_Byte5 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug4_Byte6_Debug4_Byte6(Debug4_Byte6 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug4_Byte7_Debug4_Byte7(Debug4_Byte7 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug5_Byte0_Debug5_Byte0(Debug5_Byte0 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug5_Byte1_Debug5_Byte1(Debug5_Byte1 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug5_Byte2_Debug5_Byte2(Debug5_Byte2 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug5_Byte3_Debug5_Byte3(Debug5_Byte3 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug5_Byte4_Debug5_Byte4(Debug5_Byte4 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug5_Byte5_Debug5_Byte5(Debug5_Byte5 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug5_Byte6_Debug5_Byte6(Debug5_Byte6 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug5_Byte7_Debug5_Byte7(Debug5_Byte7 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDiag_Buffer_Tx_USDT_Diag_Buffer_Tx_USDT(P2CONST(UInt8, AUTOMATIC, RTE_CCOMABSMDL_STUBS_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDiag_Buffer_Tx_USDT_Diag_Buffer_Tx_USDT(P2CONST(Diag_Buffer_Tx_USDT, AUTOMATIC, RTE_CCOMABSMDL_STUBS_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDiag_Buffer_Tx_UUDT_Diag_Buffer_Tx_UUDT(P2CONST(UInt8, AUTOMATIC, RTE_CCOMABSMDL_STUBS_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDiag_Buffer_Tx_UUDT_Diag_Buffer_Tx_UUDT(P2CONST(Diag_Buffer_Tx_UUDT, AUTOMATIC, RTE_CCOMABSMDL_STUBS_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxFV_Tx_FV_Tx(FV_Tx data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxIllumination_PWM_Illumination_PWM(Illumination_PWM data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxMAC_Tx_MAC_Tx(MAC_Tx data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxOdometer_Odometer(Odometer data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxPreviousStateIC_PreviousStateIC(PreviousStateIC data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxSecureTxByte0_SecureTxByte0(SecureTxByte0 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxSecureTxByte1_SecureTxByte1(SecureTxByte1 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxSecureTxByte2_SecureTxByte2(SecureTxByte2 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxSecureTxByte3_SecureTxByte3(SecureTxByte3 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxUserData1_IC_UserData1_IC(UserData1_IC data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxUserData2_IC_UserData2_IC(UserData2_IC data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxUserData3_IC_UserData3_IC(UserData3_IC data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxUserData4_IC_UserData4_IC(UserData4_IC data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxUserData5_IC_UserData5_IC(UserData5_IC data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxVehicleSpeedIC_VehicleSpeedIC(VehicleSpeedIC data); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_RP_SR_RX_SG_ABS_RP_SR_TX_SG_ABS Rte_Read_CComAbsMdl_stubs_RP_SR_RX_SG_ABS_RP_SR_TX_SG_ABS
#  define Rte_Read_CComAbsMdl_stubs_RP_SR_RX_SG_ABS_RP_SR_TX_SG_ABS(data) (*(data) = Rte_C_SG_ABS_0, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_RxAlive_101_Alive_101 Rte_Read_CComAbsMdl_stubs_rp_SR_RxAlive_101_Alive_101
#  define Rte_Read_CComAbsMdl_stubs_rp_SR_RxAlive_101_Alive_101(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_RxAmbient_Light_level_Ambient_Light_level Rte_Read_CComAbsMdl_stubs_rp_SR_RxAmbient_Light_level_Ambient_Light_level
#  define Rte_Read_CComAbsMdl_stubs_rp_SR_RxAmbient_Light_level_Ambient_Light_level(data) (Com_ReceiveSignal(ComConf_ComSignal_Ambient_Light_level_oIllum_control_oCAN00_888fcfad_Rx, (data))) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_RxCRC_101_CRC_101 Rte_Read_CComAbsMdl_stubs_rp_SR_RxCRC_101_CRC_101
#  define Rte_Read_CComAbsMdl_stubs_rp_SR_RxCRC_101_CRC_101(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_RxDayNightMode_DayNightMode Rte_Read_CComAbsMdl_stubs_rp_SR_RxDayNightMode_DayNightMode
#  define Rte_Read_CComAbsMdl_stubs_rp_SR_RxDayNightMode_DayNightMode(data) (Com_ReceiveSignal(ComConf_ComSignal_DayNightMode_oIllum_control_oCAN00_6d11bd91_Rx, (data))) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_RxEngineSpeed_EngineSpeed Rte_Read_CComAbsMdl_stubs_rp_SR_RxEngineSpeed_EngineSpeed
#  define Rte_Read_CComAbsMdl_stubs_rp_SR_RxEngineSpeed_EngineSpeed(data) (Com_ReceiveSignal(ComConf_ComSignal_EngineSpeed_oVehicleControl_oCAN00_7eb3f445_Rx, (data))) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_RxGear_Gear Rte_Read_CComAbsMdl_stubs_rp_SR_RxGear_Gear
#  define Rte_Read_CComAbsMdl_stubs_rp_SR_RxGear_Gear(data) (Com_ReceiveSignal(ComConf_ComSignal_Gear_oVehicleControl_oCAN00_45630abd_Rx, (data))) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_RxGearMode_GearMode Rte_Read_CComAbsMdl_stubs_rp_SR_RxGearMode_GearMode
#  define Rte_Read_CComAbsMdl_stubs_rp_SR_RxGearMode_GearMode(data) (Com_ReceiveSignal(ComConf_ComSignal_GearMode_oVehicleControl_oCAN00_c0b273e8_Rx, (data))) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_RxGearRecommendation_GearRecommendation Rte_Read_CComAbsMdl_stubs_rp_SR_RxGearRecommendation_GearRecommendation
#  define Rte_Read_CComAbsMdl_stubs_rp_SR_RxGearRecommendation_GearRecommendation(data) (Com_ReceiveSignal(ComConf_ComSignal_GearRecommendation_oVehicleControl_oCAN00_f980c505_Rx, (data))) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_RxGearStatus_GearStatus Rte_Read_CComAbsMdl_stubs_rp_SR_RxGearStatus_GearStatus
#  define Rte_Read_CComAbsMdl_stubs_rp_SR_RxGearStatus_GearStatus(data) (Com_ReceiveSignal(ComConf_ComSignal_GearStatus_oVehicleControl_oCAN00_db10bc53_Rx, (data))) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_RxIllumination_level_Illumination_level Rte_Read_CComAbsMdl_stubs_rp_SR_RxIllumination_level_Illumination_level
#  define Rte_Read_CComAbsMdl_stubs_rp_SR_RxIllumination_level_Illumination_level(data) (Com_ReceiveSignal(ComConf_ComSignal_Illumination_level_oIllum_control_oCAN00_f3b042f8_Rx, (data))) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_RxPowerMode_PowerMode Rte_Read_CComAbsMdl_stubs_rp_SR_RxPowerMode_PowerMode
#  define Rte_Read_CComAbsMdl_stubs_rp_SR_RxPowerMode_PowerMode(data) (Com_ReceiveSignal(ComConf_ComSignal_PowerMode_oVehicleControl_oCAN00_4caafc19_Rx, (data))) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_RxTransportMode_TransportMode Rte_Read_CComAbsMdl_stubs_rp_SR_RxTransportMode_TransportMode
#  define Rte_Read_CComAbsMdl_stubs_rp_SR_RxTransportMode_TransportMode(data) (Com_ReceiveSignal(ComConf_ComSignal_TransportMode_oVehicleControl_oCAN00_b498f884_Rx, (data))) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_RxTurn_Indicator_Control_Turn_Indicator_Control Rte_Read_CComAbsMdl_stubs_rp_SR_RxTurn_Indicator_Control_Turn_Indicator_Control
#  define Rte_Read_CComAbsMdl_stubs_rp_SR_RxTurn_Indicator_Control_Turn_Indicator_Control(data) (Com_ReceiveSignal(ComConf_ComSignal_Turn_Indicator_Control_oVehicleControl_oCAN00_b06608e9_Rx, (data))) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_RxVehicleSpeedABS_VehicleSpeedABS Rte_Read_CComAbsMdl_stubs_rp_SR_RxVehicleSpeedABS_VehicleSpeedABS
#  define Rte_Read_CComAbsMdl_stubs_rp_SR_RxVehicleSpeedABS_VehicleSpeedABS(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_RxWarning_Warning Rte_Read_CComAbsMdl_stubs_rp_SR_RxWarning_Warning
#  define Rte_Read_CComAbsMdl_stubs_rp_SR_RxWarning_Warning(data) (Com_ReceiveSignal(ComConf_ComSignal_Warning_oVehicleControl_oCAN00_ee369686_Rx, (data))) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_IsUpdated_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_IsUpdated_RP_SR_RX_SG_ABS_RP_SR_TX_SG_ABS Rte_IsUpdated_CComAbsMdl_stubs_RP_SR_RX_SG_ABS_RP_SR_TX_SG_ABS
#  define Rte_IsUpdated_CComAbsMdl_stubs_RP_SR_RX_SG_ABS_RP_SR_TX_SG_ABS() (FALSE) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_pp_SR_TxCurrentStateIC_CurrentStateIC Rte_Write_CComAbsMdl_stubs_pp_SR_TxCurrentStateIC_CurrentStateIC
#  define Rte_Write_pp_SR_TxDebug1_Byte0_Debug1_Byte0 Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug1_Byte0_Debug1_Byte0
#  define Rte_Write_pp_SR_TxDebug1_Byte1_Debug1_Byte1 Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug1_Byte1_Debug1_Byte1
#  define Rte_Write_pp_SR_TxDebug1_Byte2_Debug1_Byte2 Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug1_Byte2_Debug1_Byte2
#  define Rte_Write_pp_SR_TxDebug1_Byte3_Debug1_Byte3 Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug1_Byte3_Debug1_Byte3
#  define Rte_Write_pp_SR_TxDebug1_Byte4_Debug1_Byte4 Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug1_Byte4_Debug1_Byte4
#  define Rte_Write_pp_SR_TxDebug1_Byte5_Debug1_Byte5 Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug1_Byte5_Debug1_Byte5
#  define Rte_Write_pp_SR_TxDebug1_Byte6_Debug1_Byte6 Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug1_Byte6_Debug1_Byte6
#  define Rte_Write_pp_SR_TxDebug1_Byte7_Debug1_Byte7 Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug1_Byte7_Debug1_Byte7
#  define Rte_Write_pp_SR_TxDebug2_Byte0_Debug2_Byte0 Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug2_Byte0_Debug2_Byte0
#  define Rte_Write_pp_SR_TxDebug2_Byte1_Debug2_Byte1 Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug2_Byte1_Debug2_Byte1
#  define Rte_Write_pp_SR_TxDebug2_Byte2_Debug2_Byte2 Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug2_Byte2_Debug2_Byte2
#  define Rte_Write_pp_SR_TxDebug2_Byte3_Debug2_Byte3 Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug2_Byte3_Debug2_Byte3
#  define Rte_Write_pp_SR_TxDebug2_Byte4_Debug2_Byte4 Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug2_Byte4_Debug2_Byte4
#  define Rte_Write_pp_SR_TxDebug2_Byte5_Debug2_Byte5 Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug2_Byte5_Debug2_Byte5
#  define Rte_Write_pp_SR_TxDebug2_Byte6_Debug2_Byte6 Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug2_Byte6_Debug2_Byte6
#  define Rte_Write_pp_SR_TxDebug2_Byte7_Debug2_Byte7 Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug2_Byte7_Debug2_Byte7
#  define Rte_Write_pp_SR_TxDebug3_Byte0_Debug3_Byte0 Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug3_Byte0_Debug3_Byte0
#  define Rte_Write_pp_SR_TxDebug3_Byte1_Debug3_Byte1 Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug3_Byte1_Debug3_Byte1
#  define Rte_Write_pp_SR_TxDebug3_Byte2_Debug3_Byte2 Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug3_Byte2_Debug3_Byte2
#  define Rte_Write_pp_SR_TxDebug3_Byte3_Debug3_Byte3 Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug3_Byte3_Debug3_Byte3
#  define Rte_Write_pp_SR_TxDebug3_Byte4_Debug3_Byte4 Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug3_Byte4_Debug3_Byte4
#  define Rte_Write_pp_SR_TxDebug3_Byte5_Debug3_Byte5 Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug3_Byte5_Debug3_Byte5
#  define Rte_Write_pp_SR_TxDebug3_Byte6_Debug3_Byte6 Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug3_Byte6_Debug3_Byte6
#  define Rte_Write_pp_SR_TxDebug3_Byte7_Debug3_Byte7 Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug3_Byte7_Debug3_Byte7
#  define Rte_Write_pp_SR_TxDebug4_Byte0_Debug4_Byte0 Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug4_Byte0_Debug4_Byte0
#  define Rte_Write_pp_SR_TxDebug4_Byte1_Debug4_Byte1 Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug4_Byte1_Debug4_Byte1
#  define Rte_Write_pp_SR_TxDebug4_Byte2_Debug4_Byte2 Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug4_Byte2_Debug4_Byte2
#  define Rte_Write_pp_SR_TxDebug4_Byte3_Debug4_Byte3 Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug4_Byte3_Debug4_Byte3
#  define Rte_Write_pp_SR_TxDebug4_Byte4_Debug4_Byte4 Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug4_Byte4_Debug4_Byte4
#  define Rte_Write_pp_SR_TxDebug4_Byte5_Debug4_Byte5 Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug4_Byte5_Debug4_Byte5
#  define Rte_Write_pp_SR_TxDebug4_Byte6_Debug4_Byte6 Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug4_Byte6_Debug4_Byte6
#  define Rte_Write_pp_SR_TxDebug4_Byte7_Debug4_Byte7 Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug4_Byte7_Debug4_Byte7
#  define Rte_Write_pp_SR_TxDebug5_Byte0_Debug5_Byte0 Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug5_Byte0_Debug5_Byte0
#  define Rte_Write_pp_SR_TxDebug5_Byte1_Debug5_Byte1 Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug5_Byte1_Debug5_Byte1
#  define Rte_Write_pp_SR_TxDebug5_Byte2_Debug5_Byte2 Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug5_Byte2_Debug5_Byte2
#  define Rte_Write_pp_SR_TxDebug5_Byte3_Debug5_Byte3 Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug5_Byte3_Debug5_Byte3
#  define Rte_Write_pp_SR_TxDebug5_Byte4_Debug5_Byte4 Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug5_Byte4_Debug5_Byte4
#  define Rte_Write_pp_SR_TxDebug5_Byte5_Debug5_Byte5 Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug5_Byte5_Debug5_Byte5
#  define Rte_Write_pp_SR_TxDebug5_Byte6_Debug5_Byte6 Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug5_Byte6_Debug5_Byte6
#  define Rte_Write_pp_SR_TxDebug5_Byte7_Debug5_Byte7 Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug5_Byte7_Debug5_Byte7
#  define Rte_Write_pp_SR_TxDiag_Buffer_Tx_USDT_Diag_Buffer_Tx_USDT Rte_Write_CComAbsMdl_stubs_pp_SR_TxDiag_Buffer_Tx_USDT_Diag_Buffer_Tx_USDT
#  define Rte_Write_pp_SR_TxDiag_Buffer_Tx_UUDT_Diag_Buffer_Tx_UUDT Rte_Write_CComAbsMdl_stubs_pp_SR_TxDiag_Buffer_Tx_UUDT_Diag_Buffer_Tx_UUDT
#  define Rte_Write_pp_SR_TxFV_Tx_FV_Tx Rte_Write_CComAbsMdl_stubs_pp_SR_TxFV_Tx_FV_Tx
#  define Rte_Write_pp_SR_TxIllumination_PWM_Illumination_PWM Rte_Write_CComAbsMdl_stubs_pp_SR_TxIllumination_PWM_Illumination_PWM
#  define Rte_Write_pp_SR_TxMAC_Tx_MAC_Tx Rte_Write_CComAbsMdl_stubs_pp_SR_TxMAC_Tx_MAC_Tx
#  define Rte_Write_pp_SR_TxOdometer_Odometer Rte_Write_CComAbsMdl_stubs_pp_SR_TxOdometer_Odometer
#  define Rte_Write_pp_SR_TxPreviousStateIC_PreviousStateIC Rte_Write_CComAbsMdl_stubs_pp_SR_TxPreviousStateIC_PreviousStateIC
#  define Rte_Write_pp_SR_TxSecureTxByte0_SecureTxByte0 Rte_Write_CComAbsMdl_stubs_pp_SR_TxSecureTxByte0_SecureTxByte0
#  define Rte_Write_pp_SR_TxSecureTxByte1_SecureTxByte1 Rte_Write_CComAbsMdl_stubs_pp_SR_TxSecureTxByte1_SecureTxByte1
#  define Rte_Write_pp_SR_TxSecureTxByte2_SecureTxByte2 Rte_Write_CComAbsMdl_stubs_pp_SR_TxSecureTxByte2_SecureTxByte2
#  define Rte_Write_pp_SR_TxSecureTxByte3_SecureTxByte3 Rte_Write_CComAbsMdl_stubs_pp_SR_TxSecureTxByte3_SecureTxByte3
#  define Rte_Write_pp_SR_TxUserData1_IC_UserData1_IC Rte_Write_CComAbsMdl_stubs_pp_SR_TxUserData1_IC_UserData1_IC
#  define Rte_Write_pp_SR_TxUserData2_IC_UserData2_IC Rte_Write_CComAbsMdl_stubs_pp_SR_TxUserData2_IC_UserData2_IC
#  define Rte_Write_pp_SR_TxUserData3_IC_UserData3_IC Rte_Write_CComAbsMdl_stubs_pp_SR_TxUserData3_IC_UserData3_IC
#  define Rte_Write_pp_SR_TxUserData4_IC_UserData4_IC Rte_Write_CComAbsMdl_stubs_pp_SR_TxUserData4_IC_UserData4_IC
#  define Rte_Write_pp_SR_TxUserData5_IC_UserData5_IC Rte_Write_CComAbsMdl_stubs_pp_SR_TxUserData5_IC_UserData5_IC
#  define Rte_Write_pp_SR_TxVehicleSpeedIC_VehicleSpeedIC Rte_Write_CComAbsMdl_stubs_pp_SR_TxVehicleSpeedIC_VehicleSpeedIC


# endif /* !defined(RTE_CORE) */


# define CComAbsMdl_stubs_START_SEC_CODE
# include "CComAbsMdl_stubs_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CComAbsMdl_stubs_MainFunction CComAbsMdl_stubs_MainFunction
# endif

FUNC(void, CComAbsMdl_stubs_CODE) CComAbsMdl_stubs_MainFunction(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define CComAbsMdl_stubs_STOP_SEC_CODE
# include "CComAbsMdl_stubs_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CCOMABSMDL_STUBS_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
