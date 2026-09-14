/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Mdl_Speed.c
 *        Config:  BMW.dpa
 *     SW-C Type:  Mdl_Speed
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  C-Code implementation template for SW-C <Mdl_Speed>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_5.1_777, MD_MSR_5.1_779 */
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
/* PRQA S 0614 EOF */ /* MD_Rte_TestCode */

/* PRQA S 3109 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3112 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3197 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3198 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3199 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3201 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3203 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3205 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3206 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3218 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3229 EOF */ /* MD_Rte_TestCode */
/* PRQA S 2002 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3334 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3417 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3426 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3453 EOF */ /* MD_Rte_TestCode */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_Mdl_Speed.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_Mdl_Speed.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"

static void Mdl_Speed_TestDefines(void);


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * Boolean: Boolean
 * Rte_DT_Arr_u16_7_0: Integer in interval [0...65535]
 * Rte_DT_Arr_u8_100_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_1024_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_10_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_128_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_16_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_17_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_2048_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_256_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_28_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_32_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_3_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_46_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_48_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_61_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_64_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_8_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_9_0: Integer in interval [0...255]
 * Rte_DT_T_NV_Temperature_Conversion_0: Integer in interval [0...4294967295]
 * SInt16: Integer in interval [-32768...32767]
 * SInt32: Integer in interval [-2147483648...2147483647]
 * SInt8: Integer in interval [-128...127]
 * UInt16: Integer in interval [0...65535]
 * UInt32: Integer in interval [0...4294967295]
 * UInt8: Integer in interval [0...255]
 *
 * Enumeration Types:
 * ==================
 * ClusterModes: Enumeration of integer in interval [0...1] with enumerators
 *   CLUSTER_INACTIVE (0U)
 *   CLUSTER_ACTIVE (1U)
 * CountryCode_FuncType: Enumeration of integer in interval [0...14] with enumerators
 *   eFUNC_CANADA (0U)
 *   eFUNC_NORTH_AMERICA (1U)
 *   eFUNC_MEXICO (2U)
 *   eFUNC_GENERAL_EXPORT (3U)
 *   eFUNC_UK (4U)
 *   eFUNC_EUROPE (5U)
 *   eFUNC_SOUTH_AFRICA (6U)
 *   eFUNC_MIDDLE_EAST_ASIA (7U)
 *   eFUNC_JAPAN (8U)
 *   eFUNC_INDIA (9U)
 *   eFUNC_KOREA (10U)
 *   eFUNC_TAIWAN (11U)
 *   eFUNC_CHINA (12U)
 *   eFUNC_HONG_KONG (13U)
 *   eFUNC_AUSTRALIA (14U)
 * IOCtrl_Type: Enumeration of integer in interval [1...64] with enumerators
 *   eSPEEDO (1U)
 *   eTACHO (2U)
 *   eHVSYS_INDICATOR (4U)
 *   eSPEAKER (8U)
 *   eTELLTALE (16U)
 *   eBUTTONEVENT (32U)
 *   eMIDDISPALY (64U)
 * IgntionSubstateType: Enumeration of integer in interval [0...1] with enumerators
 *   IgnOff (0U)
 *   IgnOn (1U)
 * IoHwAb_AdcSignalIdType: Enumeration of integer in interval [0...17] with enumerators
 *   eIO_ADC_ADC_FUEL_5V_MON (16U)
 *   eIO_ADC_ADC_FUEL_MAIN (17U)
 *   eIO_ADC_IGN_AD (2U)
 *   eIO_ADC_FUEL_SEND_SUB_MICRO_AD (3U)
 *   eIO_ADC_AI_BATTERY (4U)
 *   eIO_ADC_AI_LCD_NTC (5U)
 *   eIO_ADC_AI_TEMP_RTC (6U)
 *   eIO_ADC_Flasher_Diag_sense_1 (7U)
 *   eIO_ADC_STR_SW2_ADIN (8U)
 *   eIO_ADC_STR_SW1_ADIN (9U)
 *   eIO_ADC_RHEO_SW_IN_ADIN (10U)
 *   eIO_ADC_ADC_RHEO_5V_MON_ADIN (11U)
 *   eIO_ADC_Flasher_Diag_sense_2 (12U)
 *   eIO_ADC_AdcChannel_Vdb (13U)
 *   eIO_ADC_AdcChannel_Vtemp (14U)
 *   eIO_ADC_MAX (15U)
 *   eIO_ADC_AI_SAMPLE_1 (0U)
 *   eIO_ADC_AI_SAMPLE_2 (1U)
 * IoHwAb_ErrorType: Enumeration of integer in interval [2...13] with enumerators
 *   E_NO_ERROR (2U)
 *   E_ERROR (3U)
 *   E_ADC_ERROR (4U)
 *   E_DOUT_ID_INVALID (5U)
 *   E_DIN_ID_INVALID (6U)
 *   E_ADC_ID_INVALID (7U)
 *   IOHWAB_E_ADC_ERROR (8U)
 *   IOHWAB_E_ADC_ID_INVALID (9U)
 *   IOHWAB_E_ERROR (10U)
 *   IOHWAB_E_DOUT_ID_INVALID (11U)
 *   IOHWAB_E_NO_ERROR (12U)
 *   IOHWAB_E_DIN_ID_INVALID (13U)
 * tSafeRxSignalId: Enumeration of integer in interval [0...4] with enumerators
 *   eVehicleSpeedABSIn (0U)
 *   eAirbagIn (1U)
 *   eAlive_101In (2U)
 *   eCRC_101In (3U)
 *   eEndOfSafeRxSignal (4U)
 * tSafeRxSignalJustRcvdStatus: Enumeration of integer in interval [0...1] with enumerators
 *   eJust_Received (0U)
 *   eNot_Just_Received (1U)
 * tSafeRxSignalStatus: Enumeration of integer in interval [0...6] with enumerators
 *   eSIGNAL_OK (0U)
 *   eSIGNAL_MISSING (1U)
 *   eSIGNAL_NEVER_RECEIVED (2U)
 *   eSIGNAL_INVALID (3U)
 *   eSIGNAL_INVALID_CRC (4U)
 *   eSIGNAL_INVALID_ALIVE_COUNTER (5U)
 *   eSIGNAL_REPEATED (6U)
 *
 * Array Types:
 * ============
 * Arr_u16_7: Array with 7 element(s) of type Rte_DT_Arr_u16_7_0
 * Arr_u8_10: Array with 10 element(s) of type Rte_DT_Arr_u8_10_0
 * Arr_u8_100: Array with 100 element(s) of type Rte_DT_Arr_u8_100_0
 * Arr_u8_1024: Array with 1024 element(s) of type Rte_DT_Arr_u8_1024_0
 * Arr_u8_128: Array with 128 element(s) of type Rte_DT_Arr_u8_128_0
 * Arr_u8_16: Array with 16 element(s) of type Rte_DT_Arr_u8_16_0
 * Arr_u8_17: Array with 17 element(s) of type Rte_DT_Arr_u8_17_0
 * Arr_u8_2048: Array with 2048 element(s) of type Rte_DT_Arr_u8_2048_0
 * Arr_u8_256: Array with 256 element(s) of type Rte_DT_Arr_u8_256_0
 * Arr_u8_28: Array with 28 element(s) of type Rte_DT_Arr_u8_28_0
 * Arr_u8_3: Array with 3 element(s) of type Rte_DT_Arr_u8_3_0
 * Arr_u8_32: Array with 32 element(s) of type Rte_DT_Arr_u8_32_0
 * Arr_u8_46: Array with 46 element(s) of type Rte_DT_Arr_u8_46_0
 * Arr_u8_48: Array with 48 element(s) of type Rte_DT_Arr_u8_48_0
 * Arr_u8_61: Array with 61 element(s) of type Rte_DT_Arr_u8_61_0
 * Arr_u8_64: Array with 64 element(s) of type Rte_DT_Arr_u8_64_0
 * Arr_u8_8: Array with 8 element(s) of type Rte_DT_Arr_u8_8_0
 * Arr_u8_9: Array with 9 element(s) of type Rte_DT_Arr_u8_9_0
 * T_NV_Temperature_Conversion: Array with 2 element(s) of type Rte_DT_T_NV_Temperature_Conversion_0
 *
 *********************************************************************************************************************/


#define Mdl_Speed_START_SEC_CODE
#include "Mdl_Speed_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Mdl_Speed_Init
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Init> of PortPrototype <pp_Init>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void Mdl_Speed_Init(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_Speed_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Mdl_Speed_CODE) Mdl_Speed_Init(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_Speed_Init
 *********************************************************************************************************************/

  Mdl_Speed_TestDefines();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Mdl_Speed_Task
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 20ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_rpIgnSubstate_IgnitionSubstate(IgntionSubstateType *data)
 *   Std_ReturnType Rte_Read_rp_ClusterMode_WSSCurrentClusterMode(ClusterModes *data)
 *   Std_ReturnType Rte_Read_rp_Countrycode_Func_CountryCode_Func(CountryCode_FuncType *data)
 *   Std_ReturnType Rte_Read_rp_Dcm_appStop_AppId(IOCtrl_Type *data)
 *   Std_ReturnType Rte_Read_rp_Diag_Digitalspeed_Diag_Digital_Speed_Value(UInt16 *data)
 *   Std_ReturnType Rte_Read_rp_DispDistanceUnit_DisplayUnit(UInt8 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_pp_SPD_SP1_In_Status_SP1_In_Status(UInt16 data)
 *   Std_ReturnType Rte_Write_pp_SPD_Selection_Table_Speed_Selection_Table(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SPD_Target2_Status_Spd_Target2_Status(UInt16 data)
 *   Std_ReturnType Rte_Write_pp_SPD_Target_Status_Spd_Target_Status(UInt16 data)
 *   Std_ReturnType Rte_Write_pp_SPD_Trim2_Status_Spd_Trim2_Status(UInt16 data)
 *   Std_ReturnType Rte_Write_pp_SPD_Trim_Status_Spd_Trim_Status(UInt16 data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_rpIoHwAb_ADC_GetAsyncRawAdc(IoHwAb_AdcSignalIdType AdcId, UInt16 *AsyncRawAdc, IoHwAb_ErrorType *ErrorStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_IOHWAB_GetAdc_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpIoHwAb_ADC_GetProcessedAdc(IoHwAb_AdcSignalIdType AdcId, SInt32 *ProcessedAdc, IoHwAb_ErrorType *ErrorStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_IOHWAB_GetAdc_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpIoHwAb_ADC_GetSyncRawAdc(IoHwAb_AdcSignalIdType AdcId, UInt16 *SyncRawAdc, IoHwAb_ErrorType *ErrorStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_IOHWAB_GetAdc_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_CanRx_RxCan_GetSignalValue(tSafeRxSignalId SignalId, UInt8 *pSignalValue, tSafeRxSignalStatus *pSignalStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_ComAbsRxSafe_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_CanRx_RxCan_GetSignalValueU8Arr(tSafeRxSignalId SignalId, UInt8 *pSignalValue, tSafeRxSignalStatus *pSignalStatus, UInt32 *pSignalLength)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_ComAbsRxSafe_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_CanRx_RxCan_SetSignalInitValue(tSafeRxSignalId SignalId, UInt8 *pSignalValue)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_ComAbsRxSafe_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_CanRx_RxCan_SetSignalInitValueU8Arr(tSafeRxSignalId SignalId, UInt8 *pSignaValue, UInt32 *pSignalLength)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_ComAbsRxSafe_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_CanRx_RxCan_SignalClearJustRcvdStatus(tSafeRxSignalId SignalId)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_CanRx_RxCan_SignalGetJustRcvdStatus(tSafeRxSignalId SignalId, tSafeRxSignalJustRcvdStatus *pJustRcvdStatus)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_CanRx_RxCan_SignalInvalidProcessingControl(tSafeRxSignalId SignalId, Boolean Status)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_CanRx_RxCan_SignalMissingProcessingControl(tSafeRxSignalId SignalId, Boolean Status)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_CanRx_RxCan_SignalNRProcessingControl(tSafeRxSignalId SignalId, Boolean Status)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_LinerInterpolation_Get_LinearInterpolateByte(UInt8 *ptr_table, UInt8 lookupvalue, UInt8 *Ptr_Lin_Return)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_LinerInterpolation_Get_LinearInterpolateSByte(SInt8 *ptr_table, SInt8 lookupvalue, SInt8 *Ptr_Lin_Return)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_LinerInterpolation_Get_LinearInterpolateSWord(SInt16 *ptr_table, SInt16 lookupvalue, SInt16 *Ptr_Lin_Return)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_LinerInterpolation_Get_LinearInterpolateWord(UInt16 *ptr_table, UInt16 lookupvalue, UInt16 *Ptr_Lin_Return)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Audio_Element(Rte_DT_Arr_u8_128_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_128_0* is of type Arr_u8_128
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_BsConst_Illumination_ReservedByte(Rte_DT_Arr_u8_28_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_28_0* is of type Arr_u8_28
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1(Rte_DT_Arr_u8_28_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_28_0* is of type Arr_u8_28
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2(Rte_DT_Arr_u8_28_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_28_0* is of type Arr_u8_28
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Communication_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Shift_b(UInt32 *Ptr)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Shift_b_SafeCopy1(UInt32 *Ptr)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Shift_b_SafeCopy2(UInt32 *Ptr)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Slope_m(UInt32 *Ptr)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Slope_m_SafeCopy1(UInt32 *Ptr)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Slope_m_SafeCopy2(UInt32 *Ptr)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Derating_Backlight_Disable(UInt8 *Ptr)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Derating_Backlight_Disable_SafeCopy1(UInt8 *Ptr)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Derating_Backlight_Disable_SafeCopy2(UInt8 *Ptr)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Display_Illum_Max_Level(UInt16 *Ptr)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Display_Illum_Max_Level_SafeCopy1(UInt16 *Ptr)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Display_Illum_Max_Level_SafeCopy2(UInt16 *Ptr)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_EngOffTimer_Element(Rte_DT_Arr_u8_32_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_FuelGauge_Element(Rte_DT_Arr_u8_128_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_128_0* is of type Arr_u8_128
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_X(Rte_DT_Arr_u16_7_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u16_7_0* is of type Arr_u16_7
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1(Rte_DT_Arr_u16_7_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u16_7_0* is of type Arr_u16_7
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2(Rte_DT_Arr_u16_7_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u16_7_0* is of type Arr_u16_7
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y(Rte_DT_Arr_u16_7_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u16_7_0* is of type Arr_u16_7
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1(Rte_DT_Arr_u16_7_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u16_7_0* is of type Arr_u16_7
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2(Rte_DT_Arr_u16_7_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u16_7_0* is of type Arr_u16_7
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_OilGauge_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PCB_Temperature_Sensor_Conv(Rte_DT_T_NV_Temperature_Conversion_0 *Ptr)
 *     Argument Ptr: Rte_DT_T_NV_Temperature_Conversion_0* is of type T_NV_Temperature_Conversion
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1(Rte_DT_T_NV_Temperature_Conversion_0 *Ptr)
 *     Argument Ptr: Rte_DT_T_NV_Temperature_Conversion_0* is of type T_NV_Temperature_Conversion
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2(Rte_DT_T_NV_Temperature_Conversion_0 *Ptr)
 *     Argument Ptr: Rte_DT_T_NV_Temperature_Conversion_0* is of type T_NV_Temperature_Conversion
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PWM_boost_bypass_duty(UInt8 *Ptr)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PWM_boost_bypass_duty_SafeCopy1(UInt8 *Ptr)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PWM_boost_bypass_duty_SafeCopy2(UInt8 *Ptr)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PowerGauge_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Power_Element(Rte_DT_Arr_u8_32_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_RealTimeClock_Element(Rte_DT_Arr_u8_48_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_48_0* is of type Arr_u8_48
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_ServiceReminder_Element(Rte_DT_Arr_u8_48_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_48_0* is of type Arr_u8_48
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_SpeedoGauge_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_TachoGauge_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_TempGauge_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temp_Threshold_Hysteresis_Derating(UInt8 *Ptr)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1(UInt8 *Ptr)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2(UInt8 *Ptr)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temperature_Sensor_Conv(Rte_DT_T_NV_Temperature_Conversion_0 *Ptr)
 *     Argument Ptr: Rte_DT_T_NV_Temperature_Conversion_0* is of type T_NV_Temperature_Conversion
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temperature_Sensor_Conv_SafeCopy1(Rte_DT_T_NV_Temperature_Conversion_0 *Ptr)
 *     Argument Ptr: Rte_DT_T_NV_Temperature_Conversion_0* is of type T_NV_Temperature_Conversion
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temperature_Sensor_Conv_SafeCopy2(Rte_DT_T_NV_Temperature_Conversion_0 *Ptr)
 *     Argument Ptr: Rte_DT_T_NV_Temperature_Conversion_0* is of type T_NV_Temperature_Conversion
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_TripComputer_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Warning_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsCys_Certicificate_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsDiag_Dtc_Element(Rte_DT_Arr_u8_2048_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_2048_0* is of type Arr_u8_2048
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsDiag_ErrorRecord_Element(Rte_DT_Arr_u8_1024_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_1024_0* is of type Arr_u8_1024
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Audio_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Communication_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Display_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Gauges_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Illumination_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Odometer_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Personalization_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Power_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsReten_RealTimeClock_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Tripcomputer_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Warning_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsRt_CusDlt_Element(Rte_DT_Arr_u8_128_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_128_0* is of type Arr_u8_128
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsRt_FuelGauge_Element(Rte_DT_Arr_u8_32_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsRt_Illumination_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsRt_Odometer_Element(Rte_DT_Arr_u8_128_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_128_0* is of type Arr_u8_128
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsRt_OilGauge_Element(Rte_DT_Arr_u8_8_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_8_0* is of type Arr_u8_8
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsRt_Personalization_Element(Rte_DT_Arr_u8_128_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_128_0* is of type Arr_u8_128
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsRt_PowerGauge_Element(Rte_DT_Arr_u8_32_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsRt_RealTimeClock_Element(Rte_DT_Arr_u8_48_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_48_0* is of type Arr_u8_48
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsRt_SpeedoGauge_Element(Rte_DT_Arr_u8_8_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_8_0* is of type Arr_u8_8
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsRt_TachoGauge_Element(Rte_DT_Arr_u8_16_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_16_0* is of type Arr_u8_16
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsRt_TempGauge_Element(Rte_DT_Arr_u8_32_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsRt_TripComputer_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsRt_Warning_Element(Rte_DT_Arr_u8_32_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsShare_AssemblyManufacturingDate(Rte_DT_Arr_u8_3_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_3_0* is of type Arr_u8_3
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsShare_AssemblyPlantNumber(Rte_DT_Arr_u8_3_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_3_0* is of type Arr_u8_3
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsShare_EcuPartNumber_Element(Rte_DT_Arr_u8_61_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_61_0* is of type Arr_u8_61
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsShare_HWModification(UInt16 *Ptr)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsShare_PCBSerialNumber(Rte_DT_Arr_u8_9_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_9_0* is of type Arr_u8_9
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsShare_ProductSerialNumber(Rte_DT_Arr_u8_10_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_10_0* is of type Arr_u8_10
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SMTManufacturingDate(Rte_DT_Arr_u8_3_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_3_0* is of type Arr_u8_3
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SMTPlantNumber(Rte_DT_Arr_u8_3_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_3_0* is of type Arr_u8_3
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotaFinPrint_Element(Rte_DT_Arr_u8_32_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotaMode_Element(Rte_DT_Arr_u8_16_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_16_0* is of type Arr_u8_16
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotaStatus_Element(Rte_DT_Arr_u8_48_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_48_0* is of type Arr_u8_48
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotadecrypt_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdReflash_Element(Rte_DT_Arr_u8_8_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_8_0* is of type Arr_u8_8
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VehicleConfig_Element(Rte_DT_Arr_u8_256_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_256_0* is of type Arr_u8_256
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VisMeet_EOLEntry_Element(UInt16 *Ptr)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VisMeet_Element(Rte_DT_Arr_u8_46_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_46_0* is of type Arr_u8_46
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VisteonPCBPartNumber(Rte_DT_Arr_u8_17_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_17_0* is of type Arr_u8_17
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VisteonPartNumber(Rte_DT_Arr_u8_17_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_17_0* is of type Arr_u8_17
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_RefCys_Certicificate1_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_RefCys_Certicificate_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_Speed_Task_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Mdl_Speed_CODE) Mdl_Speed_Task(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_Speed_Task
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  IgntionSubstateType Read_rpIgnSubstate_IgnitionSubstate;
  ClusterModes Read_rp_ClusterMode_WSSCurrentClusterMode;
  CountryCode_FuncType Read_rp_Countrycode_Func_CountryCode_Func;
  IOCtrl_Type Read_rp_Dcm_appStop_AppId;
  UInt16 Read_rp_Diag_Digitalspeed_Diag_Digital_Speed_Value;
  UInt8 Read_rp_DispDistanceUnit_DisplayUnit;

  UInt16 Call_rpIoHwAb_ADC_GetAsyncRawAdc_AsyncRawAdc = 0U;
  IoHwAb_ErrorType Call_rpIoHwAb_ADC_GetAsyncRawAdc_ErrorStatus = 0U;
  SInt32 Call_rpIoHwAb_ADC_GetProcessedAdc_ProcessedAdc = 0;
  IoHwAb_ErrorType Call_rpIoHwAb_ADC_GetProcessedAdc_ErrorStatus = 0U;
  UInt16 Call_rpIoHwAb_ADC_GetSyncRawAdc_SyncRawAdc = 0U;
  IoHwAb_ErrorType Call_rpIoHwAb_ADC_GetSyncRawAdc_ErrorStatus = 0U;
  UInt8 Call_rp_CS_CanRx_RxCan_GetSignalValue_pSignalValue = 0U;
  tSafeRxSignalStatus Call_rp_CS_CanRx_RxCan_GetSignalValue_pSignalStatus = 0U;
  UInt8 Call_rp_CS_CanRx_RxCan_GetSignalValueU8Arr_pSignalValue = 0U;
  tSafeRxSignalStatus Call_rp_CS_CanRx_RxCan_GetSignalValueU8Arr_pSignalStatus = 0U;
  UInt32 Call_rp_CS_CanRx_RxCan_GetSignalValueU8Arr_pSignalLength = 0U;
  UInt8 Call_rp_CS_CanRx_RxCan_SetSignalInitValue_pSignalValue = 0U;
  UInt8 Call_rp_CS_CanRx_RxCan_SetSignalInitValueU8Arr_pSignaValue = 0U;
  UInt32 Call_rp_CS_CanRx_RxCan_SetSignalInitValueU8Arr_pSignalLength = 0U;
  tSafeRxSignalJustRcvdStatus Call_rp_CS_CanRx_RxCan_SignalGetJustRcvdStatus_pJustRcvdStatus = 0U;
  UInt8 Call_rp_CS_LinerInterpolation_Get_LinearInterpolateByte_ptr_table = 0U;
  UInt8 Call_rp_CS_LinerInterpolation_Get_LinearInterpolateByte_Ptr_Lin_Return = 0U;
  SInt8 Call_rp_CS_LinerInterpolation_Get_LinearInterpolateSByte_ptr_table = 0;
  SInt8 Call_rp_CS_LinerInterpolation_Get_LinearInterpolateSByte_Ptr_Lin_Return = 0;
  SInt16 Call_rp_CS_LinerInterpolation_Get_LinearInterpolateSWord_ptr_table = 0;
  SInt16 Call_rp_CS_LinerInterpolation_Get_LinearInterpolateSWord_Ptr_Lin_Return = 0;
  UInt16 Call_rp_CS_LinerInterpolation_Get_LinearInterpolateWord_ptr_table = 0U;
  UInt16 Call_rp_CS_LinerInterpolation_Get_LinearInterpolateWord_Ptr_Lin_Return = 0U;
  Arr_u8_128 Call_rp_CS_MemAbsGet_Get_BsConst_Audio_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_28 Call_rp_CS_MemAbsGet_Get_BsConst_BsConst_Illumination_ReservedByte_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_28 Call_rp_CS_MemAbsGet_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_28 Call_rp_CS_MemAbsGet_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_64 Call_rp_CS_MemAbsGet_Get_BsConst_Communication_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
  UInt32 Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Shift_b_Ptr = 0U;
  UInt32 Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Shift_b_SafeCopy1_Ptr = 0U;
  UInt32 Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Shift_b_SafeCopy2_Ptr = 0U;
  UInt32 Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Slope_m_Ptr = 0U;
  UInt32 Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Slope_m_SafeCopy1_Ptr = 0U;
  UInt32 Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Slope_m_SafeCopy2_Ptr = 0U;
  UInt8 Call_rp_CS_MemAbsGet_Get_BsConst_Derating_Backlight_Disable_Ptr = 0U;
  UInt8 Call_rp_CS_MemAbsGet_Get_BsConst_Derating_Backlight_Disable_SafeCopy1_Ptr = 0U;
  UInt8 Call_rp_CS_MemAbsGet_Get_BsConst_Derating_Backlight_Disable_SafeCopy2_Ptr = 0U;
  UInt16 Call_rp_CS_MemAbsGet_Get_BsConst_Display_Illum_Max_Level_Ptr = 0U;
  UInt16 Call_rp_CS_MemAbsGet_Get_BsConst_Display_Illum_Max_Level_SafeCopy1_Ptr = 0U;
  UInt16 Call_rp_CS_MemAbsGet_Get_BsConst_Display_Illum_Max_Level_SafeCopy2_Ptr = 0U;
  Arr_u8_32 Call_rp_CS_MemAbsGet_Get_BsConst_EngOffTimer_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U
};
  Arr_u8_128 Call_rp_CS_MemAbsGet_Get_BsConst_FuelGauge_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u16_7 Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u16_7 Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u16_7 Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u16_7 Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u16_7 Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u16_7 Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_64 Call_rp_CS_MemAbsGet_Get_BsConst_OilGauge_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
  T_NV_Temperature_Conversion Call_rp_CS_MemAbsGet_Get_BsConst_PCB_Temperature_Sensor_Conv_Ptr = {
  0U, 0U
};
  T_NV_Temperature_Conversion Call_rp_CS_MemAbsGet_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1_Ptr = {
  0U, 0U
};
  T_NV_Temperature_Conversion Call_rp_CS_MemAbsGet_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2_Ptr = {
  0U, 0U
};
  UInt8 Call_rp_CS_MemAbsGet_Get_BsConst_PWM_boost_bypass_duty_Ptr = 0U;
  UInt8 Call_rp_CS_MemAbsGet_Get_BsConst_PWM_boost_bypass_duty_SafeCopy1_Ptr = 0U;
  UInt8 Call_rp_CS_MemAbsGet_Get_BsConst_PWM_boost_bypass_duty_SafeCopy2_Ptr = 0U;
  Arr_u8_64 Call_rp_CS_MemAbsGet_Get_BsConst_PowerGauge_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_32 Call_rp_CS_MemAbsGet_Get_BsConst_Power_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U
};
  Arr_u8_48 Call_rp_CS_MemAbsGet_Get_BsConst_RealTimeClock_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_48 Call_rp_CS_MemAbsGet_Get_BsConst_ServiceReminder_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_64 Call_rp_CS_MemAbsGet_Get_BsConst_SpeedoGauge_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_64 Call_rp_CS_MemAbsGet_Get_BsConst_TachoGauge_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_64 Call_rp_CS_MemAbsGet_Get_BsConst_TempGauge_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
  UInt8 Call_rp_CS_MemAbsGet_Get_BsConst_Temp_Threshold_Hysteresis_Derating_Ptr = 0U;
  UInt8 Call_rp_CS_MemAbsGet_Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1_Ptr = 0U;
  UInt8 Call_rp_CS_MemAbsGet_Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2_Ptr = 0U;
  T_NV_Temperature_Conversion Call_rp_CS_MemAbsGet_Get_BsConst_Temperature_Sensor_Conv_Ptr = {
  0U, 0U
};
  T_NV_Temperature_Conversion Call_rp_CS_MemAbsGet_Get_BsConst_Temperature_Sensor_Conv_SafeCopy1_Ptr = {
  0U, 0U
};
  T_NV_Temperature_Conversion Call_rp_CS_MemAbsGet_Get_BsConst_Temperature_Sensor_Conv_SafeCopy2_Ptr = {
  0U, 0U
};
  Arr_u8_64 Call_rp_CS_MemAbsGet_Get_BsConst_TripComputer_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_64 Call_rp_CS_MemAbsGet_Get_BsConst_Warning_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_64 Call_rp_CS_MemAbsGet_Get_BsCys_Certicificate_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_2048 Call_rp_CS_MemAbsGet_Get_BsDiag_Dtc_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_1024 Call_rp_CS_MemAbsGet_Get_BsDiag_ErrorRecord_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_100 Call_rp_CS_MemAbsGet_Get_BsReten_Audio_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_100 Call_rp_CS_MemAbsGet_Get_BsReten_Communication_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_100 Call_rp_CS_MemAbsGet_Get_BsReten_Display_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_100 Call_rp_CS_MemAbsGet_Get_BsReten_Gauges_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_100 Call_rp_CS_MemAbsGet_Get_BsReten_Illumination_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_100 Call_rp_CS_MemAbsGet_Get_BsReten_Odometer_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_100 Call_rp_CS_MemAbsGet_Get_BsReten_Personalization_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_100 Call_rp_CS_MemAbsGet_Get_BsReten_Power_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_100 Call_rp_CS_MemAbsGet_Get_BsReten_RealTimeClock_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_100 Call_rp_CS_MemAbsGet_Get_BsReten_Tripcomputer_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_100 Call_rp_CS_MemAbsGet_Get_BsReten_Warning_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_128 Call_rp_CS_MemAbsGet_Get_BsRt_CusDlt_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_32 Call_rp_CS_MemAbsGet_Get_BsRt_FuelGauge_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U
};
  Arr_u8_100 Call_rp_CS_MemAbsGet_Get_BsRt_Illumination_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_128 Call_rp_CS_MemAbsGet_Get_BsRt_Odometer_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_8 Call_rp_CS_MemAbsGet_Get_BsRt_OilGauge_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_128 Call_rp_CS_MemAbsGet_Get_BsRt_Personalization_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_32 Call_rp_CS_MemAbsGet_Get_BsRt_PowerGauge_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U
};
  Arr_u8_48 Call_rp_CS_MemAbsGet_Get_BsRt_RealTimeClock_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_8 Call_rp_CS_MemAbsGet_Get_BsRt_SpeedoGauge_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_16 Call_rp_CS_MemAbsGet_Get_BsRt_TachoGauge_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_32 Call_rp_CS_MemAbsGet_Get_BsRt_TempGauge_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U
};
  Arr_u8_64 Call_rp_CS_MemAbsGet_Get_BsRt_TripComputer_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_32 Call_rp_CS_MemAbsGet_Get_BsRt_Warning_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U
};
  Arr_u8_3 Call_rp_CS_MemAbsGet_Get_BsShare_AssemblyManufacturingDate_Ptr = {
  0U, 0U, 0U
};
  Arr_u8_3 Call_rp_CS_MemAbsGet_Get_BsShare_AssemblyPlantNumber_Ptr = {
  0U, 0U, 0U
};
  Arr_u8_61 Call_rp_CS_MemAbsGet_Get_BsShare_EcuPartNumber_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U
};
  UInt16 Call_rp_CS_MemAbsGet_Get_BsShare_HWModification_Ptr = 0U;
  Arr_u8_9 Call_rp_CS_MemAbsGet_Get_BsShare_PCBSerialNumber_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_10 Call_rp_CS_MemAbsGet_Get_BsShare_ProductSerialNumber_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_3 Call_rp_CS_MemAbsGet_Get_BsShare_SMTManufacturingDate_Ptr = {
  0U, 0U, 0U
};
  Arr_u8_3 Call_rp_CS_MemAbsGet_Get_BsShare_SMTPlantNumber_Ptr = {
  0U, 0U, 0U
};
  Arr_u8_32 Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotaFinPrint_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U
};
  Arr_u8_16 Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotaMode_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_48 Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotaStatus_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_64 Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotadecrypt_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_8 Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdReflash_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_256 Call_rp_CS_MemAbsGet_Get_BsShare_VehicleConfig_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  UInt16 Call_rp_CS_MemAbsGet_Get_BsShare_VisMeet_EOLEntry_Element_Ptr = 0U;
  Arr_u8_46 Call_rp_CS_MemAbsGet_Get_BsShare_VisMeet_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_17 Call_rp_CS_MemAbsGet_Get_BsShare_VisteonPCBPartNumber_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_17 Call_rp_CS_MemAbsGet_Get_BsShare_VisteonPartNumber_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_64 Call_rp_CS_MemAbsGet_Get_RefCys_Certicificate1_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_64 Call_rp_CS_MemAbsGet_Get_RefCys_Certicificate_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_Mdl_Speed_Rte_Read_rpIgnSubstate_IgnitionSubstate(&Read_rpIgnSubstate_IgnitionSubstate);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Read_rp_ClusterMode_WSSCurrentClusterMode(&Read_rp_ClusterMode_WSSCurrentClusterMode);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Read_rp_Countrycode_Func_CountryCode_Func(&Read_rp_Countrycode_Func_CountryCode_Func);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Read_rp_Dcm_appStop_AppId(&Read_rp_Dcm_appStop_AppId);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Read_rp_Diag_Digitalspeed_Diag_Digital_Speed_Value(&Read_rp_Diag_Digitalspeed_Diag_Digital_Speed_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Read_rp_DispDistanceUnit_DisplayUnit(&Read_rp_DispDistanceUnit_DisplayUnit);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Write_pp_SPD_SP1_In_Status_SP1_In_Status(Rte_InitValue_pp_SPD_SP1_In_Status_SP1_In_Status);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Write_pp_SPD_Selection_Table_Speed_Selection_Table(Rte_InitValue_pp_SPD_Selection_Table_Speed_Selection_Table);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Write_pp_SPD_Target2_Status_Spd_Target2_Status(Rte_InitValue_pp_SPD_Target2_Status_Spd_Target2_Status);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Write_pp_SPD_Target_Status_Spd_Target_Status(Rte_InitValue_pp_SPD_Target_Status_Spd_Target_Status);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Write_pp_SPD_Trim2_Status_Spd_Trim2_Status(Rte_InitValue_pp_SPD_Trim2_Status_Spd_Trim2_Status);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Write_pp_SPD_Trim_Status_Spd_Trim_Status(Rte_InitValue_pp_SPD_Trim_Status_Spd_Trim_Status);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rpIoHwAb_ADC_GetAsyncRawAdc(0U, &Call_rpIoHwAb_ADC_GetAsyncRawAdc_AsyncRawAdc, &Call_rpIoHwAb_ADC_GetAsyncRawAdc_ErrorStatus);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_TI_IOHWAB_GetAdc_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rpIoHwAb_ADC_GetProcessedAdc(0U, &Call_rpIoHwAb_ADC_GetProcessedAdc_ProcessedAdc, &Call_rpIoHwAb_ADC_GetProcessedAdc_ErrorStatus);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_TI_IOHWAB_GetAdc_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rpIoHwAb_ADC_GetSyncRawAdc(0U, &Call_rpIoHwAb_ADC_GetSyncRawAdc_SyncRawAdc, &Call_rpIoHwAb_ADC_GetSyncRawAdc_ErrorStatus);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_TI_IOHWAB_GetAdc_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_CanRx_RxCan_GetSignalValue(0U, &Call_rp_CS_CanRx_RxCan_GetSignalValue_pSignalValue, &Call_rp_CS_CanRx_RxCan_GetSignalValue_pSignalStatus);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_ComAbsRxSafe_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_CanRx_RxCan_GetSignalValueU8Arr(0U, &Call_rp_CS_CanRx_RxCan_GetSignalValueU8Arr_pSignalValue, &Call_rp_CS_CanRx_RxCan_GetSignalValueU8Arr_pSignalStatus, &Call_rp_CS_CanRx_RxCan_GetSignalValueU8Arr_pSignalLength);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_ComAbsRxSafe_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_CanRx_RxCan_SetSignalInitValue(0U, &Call_rp_CS_CanRx_RxCan_SetSignalInitValue_pSignalValue);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_ComAbsRxSafe_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_CanRx_RxCan_SetSignalInitValueU8Arr(0U, &Call_rp_CS_CanRx_RxCan_SetSignalInitValueU8Arr_pSignaValue, &Call_rp_CS_CanRx_RxCan_SetSignalInitValueU8Arr_pSignalLength);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_ComAbsRxSafe_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_CanRx_RxCan_SignalClearJustRcvdStatus(0U);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_CanRx_RxCan_SignalGetJustRcvdStatus(0U, &Call_rp_CS_CanRx_RxCan_SignalGetJustRcvdStatus_pJustRcvdStatus);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_CanRx_RxCan_SignalInvalidProcessingControl(0U, FALSE);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_CanRx_RxCan_SignalMissingProcessingControl(0U, FALSE);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_CanRx_RxCan_SignalNRProcessingControl(0U, FALSE);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_LinerInterpolation_Get_LinearInterpolateByte(&Call_rp_CS_LinerInterpolation_Get_LinearInterpolateByte_ptr_table, 0U, &Call_rp_CS_LinerInterpolation_Get_LinearInterpolateByte_Ptr_Lin_Return);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_LinerInterpolation_Get_LinearInterpolateSByte(&Call_rp_CS_LinerInterpolation_Get_LinearInterpolateSByte_ptr_table, 0, &Call_rp_CS_LinerInterpolation_Get_LinearInterpolateSByte_Ptr_Lin_Return);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_LinerInterpolation_Get_LinearInterpolateSWord(&Call_rp_CS_LinerInterpolation_Get_LinearInterpolateSWord_ptr_table, 0, &Call_rp_CS_LinerInterpolation_Get_LinearInterpolateSWord_Ptr_Lin_Return);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_LinerInterpolation_Get_LinearInterpolateWord(&Call_rp_CS_LinerInterpolation_Get_LinearInterpolateWord_ptr_table, 0U, &Call_rp_CS_LinerInterpolation_Get_LinearInterpolateWord_Ptr_Lin_Return);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Audio_Element(Call_rp_CS_MemAbsGet_Get_BsConst_Audio_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_BsConst_Illumination_ReservedByte(Call_rp_CS_MemAbsGet_Get_BsConst_BsConst_Illumination_ReservedByte_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1(Call_rp_CS_MemAbsGet_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2(Call_rp_CS_MemAbsGet_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Communication_Element(Call_rp_CS_MemAbsGet_Get_BsConst_Communication_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Shift_b(&Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Shift_b_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Shift_b_SafeCopy1(&Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Shift_b_SafeCopy1_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Shift_b_SafeCopy2(&Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Shift_b_SafeCopy2_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Slope_m(&Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Slope_m_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Slope_m_SafeCopy1(&Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Slope_m_SafeCopy1_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Slope_m_SafeCopy2(&Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Slope_m_SafeCopy2_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Derating_Backlight_Disable(&Call_rp_CS_MemAbsGet_Get_BsConst_Derating_Backlight_Disable_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Derating_Backlight_Disable_SafeCopy1(&Call_rp_CS_MemAbsGet_Get_BsConst_Derating_Backlight_Disable_SafeCopy1_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Derating_Backlight_Disable_SafeCopy2(&Call_rp_CS_MemAbsGet_Get_BsConst_Derating_Backlight_Disable_SafeCopy2_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Display_Illum_Max_Level(&Call_rp_CS_MemAbsGet_Get_BsConst_Display_Illum_Max_Level_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Display_Illum_Max_Level_SafeCopy1(&Call_rp_CS_MemAbsGet_Get_BsConst_Display_Illum_Max_Level_SafeCopy1_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Display_Illum_Max_Level_SafeCopy2(&Call_rp_CS_MemAbsGet_Get_BsConst_Display_Illum_Max_Level_SafeCopy2_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_EngOffTimer_Element(Call_rp_CS_MemAbsGet_Get_BsConst_EngOffTimer_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_FuelGauge_Element(Call_rp_CS_MemAbsGet_Get_BsConst_FuelGauge_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_X(Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1(Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2(Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y(Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1(Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2(Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_OilGauge_Element(Call_rp_CS_MemAbsGet_Get_BsConst_OilGauge_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PCB_Temperature_Sensor_Conv(Call_rp_CS_MemAbsGet_Get_BsConst_PCB_Temperature_Sensor_Conv_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1(Call_rp_CS_MemAbsGet_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2(Call_rp_CS_MemAbsGet_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PWM_boost_bypass_duty(&Call_rp_CS_MemAbsGet_Get_BsConst_PWM_boost_bypass_duty_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PWM_boost_bypass_duty_SafeCopy1(&Call_rp_CS_MemAbsGet_Get_BsConst_PWM_boost_bypass_duty_SafeCopy1_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PWM_boost_bypass_duty_SafeCopy2(&Call_rp_CS_MemAbsGet_Get_BsConst_PWM_boost_bypass_duty_SafeCopy2_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PowerGauge_Element(Call_rp_CS_MemAbsGet_Get_BsConst_PowerGauge_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Power_Element(Call_rp_CS_MemAbsGet_Get_BsConst_Power_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_RealTimeClock_Element(Call_rp_CS_MemAbsGet_Get_BsConst_RealTimeClock_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_ServiceReminder_Element(Call_rp_CS_MemAbsGet_Get_BsConst_ServiceReminder_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_SpeedoGauge_Element(Call_rp_CS_MemAbsGet_Get_BsConst_SpeedoGauge_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_TachoGauge_Element(Call_rp_CS_MemAbsGet_Get_BsConst_TachoGauge_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_TempGauge_Element(Call_rp_CS_MemAbsGet_Get_BsConst_TempGauge_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temp_Threshold_Hysteresis_Derating(&Call_rp_CS_MemAbsGet_Get_BsConst_Temp_Threshold_Hysteresis_Derating_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1(&Call_rp_CS_MemAbsGet_Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2(&Call_rp_CS_MemAbsGet_Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temperature_Sensor_Conv(Call_rp_CS_MemAbsGet_Get_BsConst_Temperature_Sensor_Conv_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temperature_Sensor_Conv_SafeCopy1(Call_rp_CS_MemAbsGet_Get_BsConst_Temperature_Sensor_Conv_SafeCopy1_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temperature_Sensor_Conv_SafeCopy2(Call_rp_CS_MemAbsGet_Get_BsConst_Temperature_Sensor_Conv_SafeCopy2_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_TripComputer_Element(Call_rp_CS_MemAbsGet_Get_BsConst_TripComputer_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Warning_Element(Call_rp_CS_MemAbsGet_Get_BsConst_Warning_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsCys_Certicificate_Element(Call_rp_CS_MemAbsGet_Get_BsCys_Certicificate_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsDiag_Dtc_Element(Call_rp_CS_MemAbsGet_Get_BsDiag_Dtc_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsDiag_ErrorRecord_Element(Call_rp_CS_MemAbsGet_Get_BsDiag_ErrorRecord_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Audio_Element(Call_rp_CS_MemAbsGet_Get_BsReten_Audio_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Communication_Element(Call_rp_CS_MemAbsGet_Get_BsReten_Communication_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Display_Element(Call_rp_CS_MemAbsGet_Get_BsReten_Display_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Gauges_Element(Call_rp_CS_MemAbsGet_Get_BsReten_Gauges_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Illumination_Element(Call_rp_CS_MemAbsGet_Get_BsReten_Illumination_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Odometer_Element(Call_rp_CS_MemAbsGet_Get_BsReten_Odometer_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Personalization_Element(Call_rp_CS_MemAbsGet_Get_BsReten_Personalization_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Power_Element(Call_rp_CS_MemAbsGet_Get_BsReten_Power_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsReten_RealTimeClock_Element(Call_rp_CS_MemAbsGet_Get_BsReten_RealTimeClock_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Tripcomputer_Element(Call_rp_CS_MemAbsGet_Get_BsReten_Tripcomputer_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Warning_Element(Call_rp_CS_MemAbsGet_Get_BsReten_Warning_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_CusDlt_Element(Call_rp_CS_MemAbsGet_Get_BsRt_CusDlt_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_FuelGauge_Element(Call_rp_CS_MemAbsGet_Get_BsRt_FuelGauge_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_Illumination_Element(Call_rp_CS_MemAbsGet_Get_BsRt_Illumination_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_Odometer_Element(Call_rp_CS_MemAbsGet_Get_BsRt_Odometer_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_OilGauge_Element(Call_rp_CS_MemAbsGet_Get_BsRt_OilGauge_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_Personalization_Element(Call_rp_CS_MemAbsGet_Get_BsRt_Personalization_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_PowerGauge_Element(Call_rp_CS_MemAbsGet_Get_BsRt_PowerGauge_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_RealTimeClock_Element(Call_rp_CS_MemAbsGet_Get_BsRt_RealTimeClock_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_SpeedoGauge_Element(Call_rp_CS_MemAbsGet_Get_BsRt_SpeedoGauge_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_TachoGauge_Element(Call_rp_CS_MemAbsGet_Get_BsRt_TachoGauge_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_TempGauge_Element(Call_rp_CS_MemAbsGet_Get_BsRt_TempGauge_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_TripComputer_Element(Call_rp_CS_MemAbsGet_Get_BsRt_TripComputer_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_Warning_Element(Call_rp_CS_MemAbsGet_Get_BsRt_Warning_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_AssemblyManufacturingDate(Call_rp_CS_MemAbsGet_Get_BsShare_AssemblyManufacturingDate_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_AssemblyPlantNumber(Call_rp_CS_MemAbsGet_Get_BsShare_AssemblyPlantNumber_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_EcuPartNumber_Element(Call_rp_CS_MemAbsGet_Get_BsShare_EcuPartNumber_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_HWModification(&Call_rp_CS_MemAbsGet_Get_BsShare_HWModification_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_PCBSerialNumber(Call_rp_CS_MemAbsGet_Get_BsShare_PCBSerialNumber_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_ProductSerialNumber(Call_rp_CS_MemAbsGet_Get_BsShare_ProductSerialNumber_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SMTManufacturingDate(Call_rp_CS_MemAbsGet_Get_BsShare_SMTManufacturingDate_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SMTPlantNumber(Call_rp_CS_MemAbsGet_Get_BsShare_SMTPlantNumber_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotaFinPrint_Element(Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotaFinPrint_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotaMode_Element(Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotaMode_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotaStatus_Element(Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotaStatus_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotadecrypt_Element(Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotadecrypt_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdReflash_Element(Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdReflash_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VehicleConfig_Element(Call_rp_CS_MemAbsGet_Get_BsShare_VehicleConfig_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VisMeet_EOLEntry_Element(&Call_rp_CS_MemAbsGet_Get_BsShare_VisMeet_EOLEntry_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VisMeet_Element(Call_rp_CS_MemAbsGet_Get_BsShare_VisMeet_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VisteonPCBPartNumber(Call_rp_CS_MemAbsGet_Get_BsShare_VisteonPCBPartNumber_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VisteonPartNumber(Call_rp_CS_MemAbsGet_Get_BsShare_VisteonPartNumber_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_RefCys_Certicificate1_Element(Call_rp_CS_MemAbsGet_Get_RefCys_Certicificate1_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_RefCys_Certicificate_Element(Call_rp_CS_MemAbsGet_Get_RefCys_Certicificate_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define Mdl_Speed_STOP_SEC_CODE
#include "Mdl_Speed_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void Mdl_Speed_TestDefines(void)
{
  /* Enumeration Data Types */

  ClusterModes Test_ClusterModes_V_1 = CLUSTER_INACTIVE;
  ClusterModes Test_ClusterModes_V_2 = CLUSTER_ACTIVE;

  CountryCode_FuncType Test_CountryCode_FuncType_V_1 = eFUNC_CANADA;
  CountryCode_FuncType Test_CountryCode_FuncType_V_2 = eFUNC_NORTH_AMERICA;
  CountryCode_FuncType Test_CountryCode_FuncType_V_3 = eFUNC_MEXICO;
  CountryCode_FuncType Test_CountryCode_FuncType_V_4 = eFUNC_GENERAL_EXPORT;
  CountryCode_FuncType Test_CountryCode_FuncType_V_5 = eFUNC_UK;
  CountryCode_FuncType Test_CountryCode_FuncType_V_6 = eFUNC_EUROPE;
  CountryCode_FuncType Test_CountryCode_FuncType_V_7 = eFUNC_SOUTH_AFRICA;
  CountryCode_FuncType Test_CountryCode_FuncType_V_8 = eFUNC_MIDDLE_EAST_ASIA;
  CountryCode_FuncType Test_CountryCode_FuncType_V_9 = eFUNC_JAPAN;
  CountryCode_FuncType Test_CountryCode_FuncType_V_10 = eFUNC_INDIA;
  CountryCode_FuncType Test_CountryCode_FuncType_V_11 = eFUNC_KOREA;
  CountryCode_FuncType Test_CountryCode_FuncType_V_12 = eFUNC_TAIWAN;
  CountryCode_FuncType Test_CountryCode_FuncType_V_13 = eFUNC_CHINA;
  CountryCode_FuncType Test_CountryCode_FuncType_V_14 = eFUNC_HONG_KONG;
  CountryCode_FuncType Test_CountryCode_FuncType_V_15 = eFUNC_AUSTRALIA;

  IOCtrl_Type Test_IOCtrl_Type_V_1 = eSPEEDO;
  IOCtrl_Type Test_IOCtrl_Type_V_2 = eTACHO;
  IOCtrl_Type Test_IOCtrl_Type_V_3 = eHVSYS_INDICATOR;
  IOCtrl_Type Test_IOCtrl_Type_V_4 = eSPEAKER;
  IOCtrl_Type Test_IOCtrl_Type_V_5 = eTELLTALE;
  IOCtrl_Type Test_IOCtrl_Type_V_6 = eBUTTONEVENT;
  IOCtrl_Type Test_IOCtrl_Type_V_7 = eMIDDISPALY;

  IgntionSubstateType Test_IgntionSubstateType_V_1 = IgnOff;
  IgntionSubstateType Test_IgntionSubstateType_V_2 = IgnOn;

  IoHwAb_AdcSignalIdType Test_IoHwAb_AdcSignalIdType_V_1 = eIO_ADC_ADC_FUEL_5V_MON;
  IoHwAb_AdcSignalIdType Test_IoHwAb_AdcSignalIdType_V_2 = eIO_ADC_ADC_FUEL_MAIN;
  IoHwAb_AdcSignalIdType Test_IoHwAb_AdcSignalIdType_V_3 = eIO_ADC_IGN_AD;
  IoHwAb_AdcSignalIdType Test_IoHwAb_AdcSignalIdType_V_4 = eIO_ADC_FUEL_SEND_SUB_MICRO_AD;
  IoHwAb_AdcSignalIdType Test_IoHwAb_AdcSignalIdType_V_5 = eIO_ADC_AI_BATTERY;
  IoHwAb_AdcSignalIdType Test_IoHwAb_AdcSignalIdType_V_6 = eIO_ADC_AI_LCD_NTC;
  IoHwAb_AdcSignalIdType Test_IoHwAb_AdcSignalIdType_V_7 = eIO_ADC_AI_TEMP_RTC;
  IoHwAb_AdcSignalIdType Test_IoHwAb_AdcSignalIdType_V_8 = eIO_ADC_Flasher_Diag_sense_1;
  IoHwAb_AdcSignalIdType Test_IoHwAb_AdcSignalIdType_V_9 = eIO_ADC_STR_SW2_ADIN;
  IoHwAb_AdcSignalIdType Test_IoHwAb_AdcSignalIdType_V_10 = eIO_ADC_STR_SW1_ADIN;
  IoHwAb_AdcSignalIdType Test_IoHwAb_AdcSignalIdType_V_11 = eIO_ADC_RHEO_SW_IN_ADIN;
  IoHwAb_AdcSignalIdType Test_IoHwAb_AdcSignalIdType_V_12 = eIO_ADC_ADC_RHEO_5V_MON_ADIN;
  IoHwAb_AdcSignalIdType Test_IoHwAb_AdcSignalIdType_V_13 = eIO_ADC_Flasher_Diag_sense_2;
  IoHwAb_AdcSignalIdType Test_IoHwAb_AdcSignalIdType_V_14 = eIO_ADC_AdcChannel_Vdb;
  IoHwAb_AdcSignalIdType Test_IoHwAb_AdcSignalIdType_V_15 = eIO_ADC_AdcChannel_Vtemp;
  IoHwAb_AdcSignalIdType Test_IoHwAb_AdcSignalIdType_V_16 = eIO_ADC_MAX;
  IoHwAb_AdcSignalIdType Test_IoHwAb_AdcSignalIdType_V_17 = eIO_ADC_AI_SAMPLE_1;
  IoHwAb_AdcSignalIdType Test_IoHwAb_AdcSignalIdType_V_18 = eIO_ADC_AI_SAMPLE_2;

  IoHwAb_ErrorType Test_IoHwAb_ErrorType_V_1 = E_NO_ERROR;
  IoHwAb_ErrorType Test_IoHwAb_ErrorType_V_2 = E_ERROR;
  IoHwAb_ErrorType Test_IoHwAb_ErrorType_V_3 = E_ADC_ERROR;
  IoHwAb_ErrorType Test_IoHwAb_ErrorType_V_4 = E_DOUT_ID_INVALID;
  IoHwAb_ErrorType Test_IoHwAb_ErrorType_V_5 = E_DIN_ID_INVALID;
  IoHwAb_ErrorType Test_IoHwAb_ErrorType_V_6 = E_ADC_ID_INVALID;
  IoHwAb_ErrorType Test_IoHwAb_ErrorType_V_7 = IOHWAB_E_ADC_ERROR;
  IoHwAb_ErrorType Test_IoHwAb_ErrorType_V_8 = IOHWAB_E_ADC_ID_INVALID;
  IoHwAb_ErrorType Test_IoHwAb_ErrorType_V_9 = IOHWAB_E_ERROR;
  IoHwAb_ErrorType Test_IoHwAb_ErrorType_V_10 = IOHWAB_E_DOUT_ID_INVALID;
  IoHwAb_ErrorType Test_IoHwAb_ErrorType_V_11 = IOHWAB_E_NO_ERROR;
  IoHwAb_ErrorType Test_IoHwAb_ErrorType_V_12 = IOHWAB_E_DIN_ID_INVALID;

  tSafeRxSignalId Test_tSafeRxSignalId_V_1 = eVehicleSpeedABSIn;
  tSafeRxSignalId Test_tSafeRxSignalId_V_2 = eAirbagIn;
  tSafeRxSignalId Test_tSafeRxSignalId_V_3 = eAlive_101In;
  tSafeRxSignalId Test_tSafeRxSignalId_V_4 = eCRC_101In;
  tSafeRxSignalId Test_tSafeRxSignalId_V_5 = eEndOfSafeRxSignal;

  tSafeRxSignalJustRcvdStatus Test_tSafeRxSignalJustRcvdStatus_V_1 = eJust_Received;
  tSafeRxSignalJustRcvdStatus Test_tSafeRxSignalJustRcvdStatus_V_2 = eNot_Just_Received;

  tSafeRxSignalStatus Test_tSafeRxSignalStatus_V_1 = eSIGNAL_OK;
  tSafeRxSignalStatus Test_tSafeRxSignalStatus_V_2 = eSIGNAL_MISSING;
  tSafeRxSignalStatus Test_tSafeRxSignalStatus_V_3 = eSIGNAL_NEVER_RECEIVED;
  tSafeRxSignalStatus Test_tSafeRxSignalStatus_V_4 = eSIGNAL_INVALID;
  tSafeRxSignalStatus Test_tSafeRxSignalStatus_V_5 = eSIGNAL_INVALID_CRC;
  tSafeRxSignalStatus Test_tSafeRxSignalStatus_V_6 = eSIGNAL_INVALID_ALIVE_COUNTER;
  tSafeRxSignalStatus Test_tSafeRxSignalStatus_V_7 = eSIGNAL_REPEATED;
}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_TestCode:
     Reason:     This justification is used within the generated test code by the Rte Analyzer.
     Risk:       No functional risk.
     Prevention: Not required.

*/
