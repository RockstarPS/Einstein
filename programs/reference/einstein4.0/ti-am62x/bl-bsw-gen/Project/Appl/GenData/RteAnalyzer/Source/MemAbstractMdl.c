/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  MemAbstractMdl.c
 *        Config:  BMW.dpa"
 *     SW-C Type:  MemAbstractMdl
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  C-Code implementation template for SW-C <MemAbstractMdl>
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

#include "Rte_MemAbstractMdl.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_MemAbstractMdl.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"


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
 * Rte_DT_Arr_u8_100_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_1024_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_128_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_16_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_2048_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_256_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_32_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_48_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_64_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_8_0: Integer in interval [0...255]
 * UInt8: Integer in interval [0...255]
 *
 * Array Types:
 * ============
 * Arr_u8_100: Array with 100 element(s) of type Rte_DT_Arr_u8_100_0
 * Arr_u8_1024: Array with 1024 element(s) of type Rte_DT_Arr_u8_1024_0
 * Arr_u8_128: Array with 128 element(s) of type Rte_DT_Arr_u8_128_0
 * Arr_u8_16: Array with 16 element(s) of type Rte_DT_Arr_u8_16_0
 * Arr_u8_2048: Array with 2048 element(s) of type Rte_DT_Arr_u8_2048_0
 * Arr_u8_256: Array with 256 element(s) of type Rte_DT_Arr_u8_256_0
 * Arr_u8_32: Array with 32 element(s) of type Rte_DT_Arr_u8_32_0
 * Arr_u8_48: Array with 48 element(s) of type Rte_DT_Arr_u8_48_0
 * Arr_u8_64: Array with 64 element(s) of type Rte_DT_Arr_u8_64_0
 * Arr_u8_8: Array with 8 element(s) of type Rte_DT_Arr_u8_8_0
 *
 *********************************************************************************************************************/


#define MemAbstractMdl_START_SEC_CODE
#include "MemAbstractMdl_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsConst_Audio_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsConst_Audio_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsConst_Audio_Element(Rte_DT_Arr_u8_128_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_128_0* is of type Arr_u8_128
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_Audio_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Audio_Element(P2VAR(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_Audio_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsConst_Communication_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsConst_Communication_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsConst_Communication_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_Communication_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Communication_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_Communication_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsConst_EngOffTimer_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsConst_EngOffTimer_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsConst_EngOffTimer_Element(Rte_DT_Arr_u8_32_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_EngOffTimer_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_EngOffTimer_Element(P2VAR(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_EngOffTimer_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsConst_FuelGauge_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsConst_FuelGauge_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsConst_FuelGauge_Element(Rte_DT_Arr_u8_128_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_128_0* is of type Arr_u8_128
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_FuelGauge_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_FuelGauge_Element(P2VAR(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_FuelGauge_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsConst_Illumination_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsConst_Illumination_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsConst_Illumination_Element(Rte_DT_Arr_u8_128_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_128_0* is of type Arr_u8_128
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_Illumination_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Illumination_Element(P2VAR(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_Illumination_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsConst_OilGauge_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsConst_OilGauge_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsConst_OilGauge_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_OilGauge_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_OilGauge_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_OilGauge_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsConst_PowerGauge_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsConst_PowerGauge_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsConst_PowerGauge_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_PowerGauge_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_PowerGauge_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_PowerGauge_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsConst_Power_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsConst_Power_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsConst_Power_Element(Rte_DT_Arr_u8_32_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_Power_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Power_Element(P2VAR(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_Power_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsConst_RealTimeClock_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsConst_RealTimeClock_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsConst_RealTimeClock_Element(Rte_DT_Arr_u8_48_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_48_0* is of type Arr_u8_48
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_RealTimeClock_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_RealTimeClock_Element(P2VAR(Rte_DT_Arr_u8_48_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_RealTimeClock_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsConst_ServiceReminder_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsConst_ServiceReminder_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsConst_ServiceReminder_Element(Rte_DT_Arr_u8_48_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_48_0* is of type Arr_u8_48
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_ServiceReminder_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_ServiceReminder_Element(P2VAR(Rte_DT_Arr_u8_48_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_ServiceReminder_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsConst_SpeedoGauge_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsConst_SpeedoGauge_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsConst_SpeedoGauge_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_SpeedoGauge_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_SpeedoGauge_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_SpeedoGauge_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsConst_TachoGauge_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsConst_TachoGauge_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsConst_TachoGauge_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_TachoGauge_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_TachoGauge_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_TachoGauge_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsConst_TempGauge_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsConst_TempGauge_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsConst_TempGauge_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_TempGauge_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_TempGauge_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_TempGauge_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsConst_TripComputer_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsConst_TripComputer_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsConst_TripComputer_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_TripComputer_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_TripComputer_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_TripComputer_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsConst_Warning_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsConst_Warning_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsConst_Warning_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_Warning_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Warning_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_Warning_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsCys_Certicificate_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsCys_Certicificate_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsCys_Certicificate_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsCys_Certicificate_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsCys_Certicificate_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsCys_Certicificate_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsDiag_Dtc_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsDiag_Dtc_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsDiag_Dtc_Element(Rte_DT_Arr_u8_2048_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_2048_0* is of type Arr_u8_2048
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsDiag_Dtc_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsDiag_Dtc_Element(P2VAR(Rte_DT_Arr_u8_2048_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsDiag_Dtc_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsDiag_ErrorRecord_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsDiag_ErrorRecord_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsDiag_ErrorRecord_Element(Rte_DT_Arr_u8_1024_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_1024_0* is of type Arr_u8_1024
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsDiag_ErrorRecord_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsDiag_ErrorRecord_Element(P2VAR(Rte_DT_Arr_u8_1024_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsDiag_ErrorRecord_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsFuSa_Audio_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsFuSa_Audio_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsFuSa_Audio_Element(Rte_DT_Arr_u8_32_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsFuSa_Audio_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsFuSa_Audio_Element(P2VAR(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsFuSa_Audio_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsFuSa_Communication_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsFuSa_Communication_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsFuSa_Communication_Element(Rte_DT_Arr_u8_16_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_16_0* is of type Arr_u8_16
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsFuSa_Communication_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsFuSa_Communication_Element(P2VAR(Rte_DT_Arr_u8_16_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsFuSa_Communication_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsFuSa_Config_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsFuSa_Config_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsFuSa_Config_Element(Rte_DT_Arr_u8_16_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_16_0* is of type Arr_u8_16
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsFuSa_Config_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsFuSa_Config_Element(P2VAR(Rte_DT_Arr_u8_16_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsFuSa_Config_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsFuSa_Display_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsFuSa_Display_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsFuSa_Display_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsFuSa_Display_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsFuSa_Display_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsFuSa_Display_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsFuSa_Power_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsFuSa_Power_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsFuSa_Power_Element(Rte_DT_Arr_u8_48_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_48_0* is of type Arr_u8_48
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsFuSa_Power_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsFuSa_Power_Element(P2VAR(Rte_DT_Arr_u8_48_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsFuSa_Power_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsFuSa_Warning_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsFuSa_Warning_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsFuSa_Warning_Element(Rte_DT_Arr_u8_32_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsFuSa_Warning_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsFuSa_Warning_Element(P2VAR(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsFuSa_Warning_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsFusa_Fota_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsFusa_Fota_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsFusa_Fota_Element(Rte_DT_Arr_u8_32_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsFusa_Fota_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsFusa_Fota_Element(P2VAR(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsFusa_Fota_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsReten_Audio_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsReten_Audio_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsReten_Audio_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsReten_Audio_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsReten_Audio_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsReten_Audio_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsReten_Communication_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsReten_Communication_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsReten_Communication_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsReten_Communication_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsReten_Communication_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsReten_Communication_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsReten_Display_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsReten_Display_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsReten_Display_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsReten_Display_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsReten_Display_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsReten_Display_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsReten_Gauges_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsReten_Gauges_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsReten_Gauges_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsReten_Gauges_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsReten_Gauges_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsReten_Gauges_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsReten_Illumination_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsReten_Illumination_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsReten_Illumination_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsReten_Illumination_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsReten_Illumination_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsReten_Illumination_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsReten_Odometer_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsReten_Odometer_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsReten_Odometer_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsReten_Odometer_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsReten_Odometer_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsReten_Odometer_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsReten_Personalization_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsReten_Personalization_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsReten_Personalization_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsReten_Personalization_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsReten_Personalization_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsReten_Personalization_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsReten_Power_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsReten_Power_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsReten_Power_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsReten_Power_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsReten_Power_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsReten_Power_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsReten_RealTimeClock_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsReten_RealTimeClock_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsReten_RealTimeClock_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsReten_RealTimeClock_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsReten_RealTimeClock_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsReten_RealTimeClock_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsReten_Tripcomputer_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsReten_Tripcomputer_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsReten_Tripcomputer_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsReten_Tripcomputer_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsReten_Tripcomputer_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsReten_Tripcomputer_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsReten_VisDlt_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsReten_VisDlt_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsReten_VisDlt_Element(Rte_DT_Arr_u8_256_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_256_0* is of type Arr_u8_256
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsReten_VisDlt_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsReten_VisDlt_Element(P2VAR(Rte_DT_Arr_u8_256_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsReten_VisDlt_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsReten_Warning_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsReten_Warning_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsReten_Warning_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsReten_Warning_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsReten_Warning_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsReten_Warning_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsRt_CusDlt_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsRt_CusDlt_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsRt_CusDlt_Element(Rte_DT_Arr_u8_128_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_128_0* is of type Arr_u8_128
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsRt_CusDlt_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsRt_CusDlt_Element(P2VAR(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsRt_CusDlt_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsRt_FuelGauge_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsRt_FuelGauge_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsRt_FuelGauge_Element(Rte_DT_Arr_u8_32_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsRt_FuelGauge_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsRt_FuelGauge_Element(P2VAR(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsRt_FuelGauge_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsRt_Illumination_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsRt_Illumination_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsRt_Illumination_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsRt_Illumination_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsRt_Illumination_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsRt_Illumination_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsRt_Odometer_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsRt_Odometer_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsRt_Odometer_Element(Rte_DT_Arr_u8_128_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_128_0* is of type Arr_u8_128
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsRt_Odometer_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsRt_Odometer_Element(P2VAR(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsRt_Odometer_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsRt_OilGauge_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsRt_OilGauge_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsRt_OilGauge_Element(Rte_DT_Arr_u8_8_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_8_0* is of type Arr_u8_8
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsRt_OilGauge_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsRt_OilGauge_Element(P2VAR(Rte_DT_Arr_u8_8_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsRt_OilGauge_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsRt_Personalization_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsRt_Personalization_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsRt_Personalization_Element(Rte_DT_Arr_u8_128_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_128_0* is of type Arr_u8_128
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsRt_Personalization_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsRt_Personalization_Element(P2VAR(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsRt_Personalization_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsRt_PowerGauge_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsRt_PowerGauge_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsRt_PowerGauge_Element(Rte_DT_Arr_u8_32_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsRt_PowerGauge_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsRt_PowerGauge_Element(P2VAR(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsRt_PowerGauge_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsRt_RealTimeClock_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsRt_RealTimeClock_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsRt_RealTimeClock_Element(Rte_DT_Arr_u8_48_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_48_0* is of type Arr_u8_48
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsRt_RealTimeClock_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsRt_RealTimeClock_Element(P2VAR(Rte_DT_Arr_u8_48_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsRt_RealTimeClock_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsRt_SpeedoGauge_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsRt_SpeedoGauge_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsRt_SpeedoGauge_Element(Rte_DT_Arr_u8_8_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_8_0* is of type Arr_u8_8
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsRt_SpeedoGauge_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsRt_SpeedoGauge_Element(P2VAR(Rte_DT_Arr_u8_8_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsRt_SpeedoGauge_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsRt_TachoGauge_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsRt_TachoGauge_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsRt_TachoGauge_Element(Rte_DT_Arr_u8_16_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_16_0* is of type Arr_u8_16
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsRt_TachoGauge_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsRt_TachoGauge_Element(P2VAR(Rte_DT_Arr_u8_16_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsRt_TachoGauge_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsRt_TempGauge_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsRt_TempGauge_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsRt_TempGauge_Element(Rte_DT_Arr_u8_32_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsRt_TempGauge_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsRt_TempGauge_Element(P2VAR(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsRt_TempGauge_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsRt_TripComputer_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsRt_TripComputer_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsRt_TripComputer_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsRt_TripComputer_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsRt_TripComputer_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsRt_TripComputer_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsRt_Warning_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsRt_Warning_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsRt_Warning_Element(Rte_DT_Arr_u8_32_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsRt_Warning_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsRt_Warning_Element(P2VAR(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsRt_Warning_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsShare_EcuPartNumber_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsShare_EcuPartNumber_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsShare_EcuPartNumber_Element(Rte_DT_Arr_u8_128_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_128_0* is of type Arr_u8_128
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsShare_EcuPartNumber_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsShare_EcuPartNumber_Element(P2VAR(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsShare_EcuPartNumber_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsShare_SwUpdFotaFinPrint_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsShare_SwUpdFotaFinPrint_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsShare_SwUpdFotaFinPrint_Element(Rte_DT_Arr_u8_32_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsShare_SwUpdFotaFinPrint_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsShare_SwUpdFotaFinPrint_Element(P2VAR(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsShare_SwUpdFotaFinPrint_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsShare_SwUpdFotaMode_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsShare_SwUpdFotaMode_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsShare_SwUpdFotaMode_Element(Rte_DT_Arr_u8_16_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_16_0* is of type Arr_u8_16
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsShare_SwUpdFotaMode_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsShare_SwUpdFotaMode_Element(P2VAR(Rte_DT_Arr_u8_16_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsShare_SwUpdFotaMode_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsShare_SwUpdFotaStatus_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsShare_SwUpdFotaStatus_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsShare_SwUpdFotaStatus_Element(Rte_DT_Arr_u8_48_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_48_0* is of type Arr_u8_48
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsShare_SwUpdFotaStatus_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsShare_SwUpdFotaStatus_Element(P2VAR(Rte_DT_Arr_u8_48_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsShare_SwUpdFotaStatus_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsShare_SwUpdFotadecrypt_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsShare_SwUpdFotadecrypt_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsShare_SwUpdFotadecrypt_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsShare_SwUpdFotadecrypt_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsShare_SwUpdFotadecrypt_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsShare_SwUpdFotadecrypt_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsShare_SwUpdReflash_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsShare_SwUpdReflash_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsShare_SwUpdReflash_Element(Rte_DT_Arr_u8_8_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_8_0* is of type Arr_u8_8
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsShare_SwUpdReflash_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsShare_SwUpdReflash_Element(P2VAR(Rte_DT_Arr_u8_8_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsShare_SwUpdReflash_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsShare_VehicleConfig_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsShare_VehicleConfig_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsShare_VehicleConfig_Element(Rte_DT_Arr_u8_256_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_256_0* is of type Arr_u8_256
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsShare_VehicleConfig_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsShare_VehicleConfig_Element(P2VAR(Rte_DT_Arr_u8_256_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsShare_VehicleConfig_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsShare_VisMeet_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsShare_VisMeet_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsShare_VisMeet_Element(Rte_DT_Arr_u8_48_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_48_0* is of type Arr_u8_48
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsShare_VisMeet_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsShare_VisMeet_Element(P2VAR(Rte_DT_Arr_u8_48_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsShare_VisMeet_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_RefCys_Certicificate1_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_RefCys_Certicificate1_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_RefCys_Certicificate1_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_RefCys_Certicificate1_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_RefCys_Certicificate1_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_RefCys_Certicificate1_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_RefCys_Certicificate_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_RefCys_Certicificate_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_RefCys_Certicificate_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_RefCys_Certicificate_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_RefCys_Certicificate_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_RefCys_Certicificate_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_MainFunction
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Audio_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Communication_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_EngOffTimer_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_FuelGauge_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Illumination_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_OilGauge_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_PowerGauge_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Power_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_RealTimeClock_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_ServiceReminder_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_SpeedoGauge_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_TachoGauge_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_TempGauge_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_TripComputer_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Warning_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsCys_Certicificate_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsDiag_Dtc_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsDiag_ErrorRecord_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsFuSa_Audio_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsFuSa_Communication_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsFuSa_Config_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsFuSa_Display_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsFuSa_Power_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsFuSa_Warning_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsFusa_Fota_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Audio_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Communication_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Display_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Gauges_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Illumination_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Odometer_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Personalization_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Power_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_RealTimeClock_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Tripcomputer_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_VisDlt_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Warning_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_CusDlt_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_FuelGauge_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_Illumination_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_Odometer_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_OilGauge_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_Personalization_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_PowerGauge_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_RealTimeClock_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_SpeedoGauge_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_TachoGauge_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_TempGauge_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_TripComputer_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_Warning_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_EcuPartNumber_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaFinPrint_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaMode_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaStatus_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotadecrypt_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_SwUpdReflash_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_VehicleConfig_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_VisMeet_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_RefCys_Certicificate1_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_RefCys_Certicificate_Element(UInt8 data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_MainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_MainFunction(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_MainFunction
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Audio_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_Audio_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Communication_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_Communication_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_EngOffTimer_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_EngOffTimer_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_FuelGauge_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_FuelGauge_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Illumination_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_Illumination_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_OilGauge_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_OilGauge_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_PowerGauge_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_PowerGauge_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Power_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_Power_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_RealTimeClock_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_RealTimeClock_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_ServiceReminder_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_ServiceReminder_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_SpeedoGauge_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_SpeedoGauge_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_TachoGauge_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_TachoGauge_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_TempGauge_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_TempGauge_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_TripComputer_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_TripComputer_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Warning_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_Warning_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsCys_Certicificate_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsCys_Certicificate_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsDiag_Dtc_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsDiag_Dtc_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsDiag_ErrorRecord_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsDiag_ErrorRecord_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsFuSa_Audio_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsFuSa_Audio_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsFuSa_Communication_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsFuSa_Communication_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsFuSa_Config_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsFuSa_Config_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsFuSa_Display_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsFuSa_Display_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsFuSa_Power_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsFuSa_Power_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsFuSa_Warning_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsFuSa_Warning_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsFusa_Fota_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsFusa_Fota_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Audio_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsReten_Audio_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Communication_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsReten_Communication_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Display_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsReten_Display_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Gauges_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsReten_Gauges_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Illumination_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsReten_Illumination_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Odometer_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsReten_Odometer_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Personalization_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsReten_Personalization_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Power_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsReten_Power_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_RealTimeClock_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsReten_RealTimeClock_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Tripcomputer_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsReten_Tripcomputer_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_VisDlt_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsReten_VisDlt_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Warning_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsReten_Warning_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_CusDlt_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsRt_CusDlt_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_FuelGauge_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsRt_FuelGauge_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_Illumination_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsRt_Illumination_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_Odometer_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsRt_Odometer_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_OilGauge_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsRt_OilGauge_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_Personalization_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsRt_Personalization_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_PowerGauge_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsRt_PowerGauge_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_RealTimeClock_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsRt_RealTimeClock_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_SpeedoGauge_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsRt_SpeedoGauge_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_TachoGauge_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsRt_TachoGauge_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_TempGauge_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsRt_TempGauge_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_TripComputer_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsRt_TripComputer_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_Warning_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsRt_Warning_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_EcuPartNumber_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsShare_EcuPartNumber_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaFinPrint_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaFinPrint_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaMode_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaMode_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaStatus_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaStatus_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotadecrypt_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotadecrypt_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_SwUpdReflash_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsShare_SwUpdReflash_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_VehicleConfig_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsShare_VehicleConfig_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_VisMeet_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsShare_VisMeet_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_RefCys_Certicificate1_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_RefCys_Certicificate1_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_RefCys_Certicificate_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_RefCys_Certicificate_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_NvmWriteStatus
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <NvmWriteStatus> of PortPrototype <pp_CS_MemAbs_NvMWriteStatus>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_NvmWriteStatus(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbs_NvMWriteStatus_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NvmWriteStatus_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_NvmWriteStatus(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NvmWriteStatus (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsConst_Audio_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsConst_Audio_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsConst_Audio_Element(const Rte_DT_Arr_u8_128_0 *BsConst_Audio_Element)
 *     Argument BsConst_Audio_Element: Rte_DT_Arr_u8_128_0* is of type Arr_u8_128
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_Audio_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Audio_Element(P2CONST(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_Audio_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_Audio_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsConst_Communication_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsConst_Communication_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsConst_Communication_Element(const Rte_DT_Arr_u8_64_0 *BsConst_Communication_Element)
 *     Argument BsConst_Communication_Element: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_Communication_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Communication_Element(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_Communication_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_Communication_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsConst_EngOffTimer_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsConst_EngOffTimer_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsConst_EngOffTimer_Element(const Rte_DT_Arr_u8_32_0 *BsConst_EngOffTimer_Element)
 *     Argument BsConst_EngOffTimer_Element: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_EngOffTimer_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_EngOffTimer_Element(P2CONST(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_EngOffTimer_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_EngOffTimer_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsConst_FuelGauge_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsConst_FuelGauge_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsConst_FuelGauge_Element(const Rte_DT_Arr_u8_128_0 *BsConst_FuelGauge_Element)
 *     Argument BsConst_FuelGauge_Element: Rte_DT_Arr_u8_128_0* is of type Arr_u8_128
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_FuelGauge_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_FuelGauge_Element(P2CONST(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_FuelGauge_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_FuelGauge_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsConst_Illumination_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsConst_Illumination_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsConst_Illumination_Element(const Rte_DT_Arr_u8_128_0 *BsConst_Illumination_Element)
 *     Argument BsConst_Illumination_Element: Rte_DT_Arr_u8_128_0* is of type Arr_u8_128
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_Illumination_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Illumination_Element(P2CONST(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_Illumination_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_Illumination_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsConst_OilGauge_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsConst_OilGauge_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsConst_OilGauge_Element(const Rte_DT_Arr_u8_64_0 *BsConst_OilGauge_Element)
 *     Argument BsConst_OilGauge_Element: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_OilGauge_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_OilGauge_Element(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_OilGauge_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_OilGauge_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsConst_PowerGauge_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsConst_PowerGauge_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsConst_PowerGauge_Element(const Rte_DT_Arr_u8_64_0 *BsConst_PowerGauge_Element)
 *     Argument BsConst_PowerGauge_Element: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_PowerGauge_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_PowerGauge_Element(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_PowerGauge_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_PowerGauge_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsConst_Power_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsConst_Power_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsConst_Power_Element(const Rte_DT_Arr_u8_32_0 *BsConst_Power_Element)
 *     Argument BsConst_Power_Element: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_Power_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Power_Element(P2CONST(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_Power_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_Power_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsConst_RealTimeClock_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsConst_RealTimeClock_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsConst_RealTimeClock_Element(const Rte_DT_Arr_u8_48_0 *BsConst_RealTimeClock_Element)
 *     Argument BsConst_RealTimeClock_Element: Rte_DT_Arr_u8_48_0* is of type Arr_u8_48
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_RealTimeClock_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_RealTimeClock_Element(P2CONST(Rte_DT_Arr_u8_48_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_RealTimeClock_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_RealTimeClock_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsConst_ServiceReminder_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsConst_ServiceReminder_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsConst_ServiceReminder_Element(const Rte_DT_Arr_u8_48_0 *BsConst_ServiceReminder_Element)
 *     Argument BsConst_ServiceReminder_Element: Rte_DT_Arr_u8_48_0* is of type Arr_u8_48
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_ServiceReminder_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_ServiceReminder_Element(P2CONST(Rte_DT_Arr_u8_48_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_ServiceReminder_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_ServiceReminder_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsConst_SpeedoGauge_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsConst_SpeedoGauge_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsConst_SpeedoGauge_Element(const Rte_DT_Arr_u8_64_0 *BsConst_SpeedoGauge_Element)
 *     Argument BsConst_SpeedoGauge_Element: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_SpeedoGauge_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_SpeedoGauge_Element(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_SpeedoGauge_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_SpeedoGauge_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsConst_TachoGauge_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsConst_TachoGauge_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsConst_TachoGauge_Element(const Rte_DT_Arr_u8_64_0 *BsConst_TachoGauge_Element)
 *     Argument BsConst_TachoGauge_Element: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_TachoGauge_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_TachoGauge_Element(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_TachoGauge_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_TachoGauge_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsConst_TempGauge_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsConst_TempGauge_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsConst_TempGauge_Element(const Rte_DT_Arr_u8_64_0 *BsConst_TempGauge_Element)
 *     Argument BsConst_TempGauge_Element: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_TempGauge_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_TempGauge_Element(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_TempGauge_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_TempGauge_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsConst_TripComputer_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsConst_TripComputer_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsConst_TripComputer_Element(const Rte_DT_Arr_u8_64_0 *BsConst_TripComputer_Element)
 *     Argument BsConst_TripComputer_Element: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_TripComputer_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_TripComputer_Element(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_TripComputer_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_TripComputer_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsConst_Warning_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsConst_Warning_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsConst_Warning_Element(const Rte_DT_Arr_u8_64_0 *BsConst_Warning_Element)
 *     Argument BsConst_Warning_Element: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_Warning_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Warning_Element(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_Warning_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_Warning_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsCys_Certicificate_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsCys_Certicificate_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsCys_Certicificate_Element(const Rte_DT_Arr_u8_64_0 *BsCys_Certicificate_Element)
 *     Argument BsCys_Certicificate_Element: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsCys_Certicificate_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsCys_Certicificate_Element(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsCys_Certicificate_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsCys_Certicificate_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsDiag_Dtc_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsDiag_Dtc_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsDiag_Dtc_Element(const Rte_DT_Arr_u8_2048_0 *BsDiag_Dtc_Element)
 *     Argument BsDiag_Dtc_Element: Rte_DT_Arr_u8_2048_0* is of type Arr_u8_2048
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsDiag_Dtc_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsDiag_Dtc_Element(P2CONST(Rte_DT_Arr_u8_2048_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsDiag_Dtc_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsDiag_Dtc_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsDiag_ErrorRecord_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsDiag_ErrorRecord_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsDiag_ErrorRecord_Element(const Rte_DT_Arr_u8_1024_0 *BsDiag_ErrorRecord_Element)
 *     Argument BsDiag_ErrorRecord_Element: Rte_DT_Arr_u8_1024_0* is of type Arr_u8_1024
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsDiag_ErrorRecord_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsDiag_ErrorRecord_Element(P2CONST(Rte_DT_Arr_u8_1024_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsDiag_ErrorRecord_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsDiag_ErrorRecord_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsFuSa_Audio_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsFuSa_Audio_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsFuSa_Audio_Element(const Rte_DT_Arr_u8_32_0 *BsFuSa_Audio_Element)
 *     Argument BsFuSa_Audio_Element: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsFuSa_Audio_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsFuSa_Audio_Element(P2CONST(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsFuSa_Audio_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsFuSa_Audio_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsFuSa_Communication_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsFuSa_Communication_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsFuSa_Communication_Element(const Rte_DT_Arr_u8_16_0 *BsFuSa_Communication_Element)
 *     Argument BsFuSa_Communication_Element: Rte_DT_Arr_u8_16_0* is of type Arr_u8_16
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsFuSa_Communication_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsFuSa_Communication_Element(P2CONST(Rte_DT_Arr_u8_16_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsFuSa_Communication_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsFuSa_Communication_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsFuSa_Config_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsFuSa_Config_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsFuSa_Config_Element(const Rte_DT_Arr_u8_16_0 *BsFuSa_Config_Element)
 *     Argument BsFuSa_Config_Element: Rte_DT_Arr_u8_16_0* is of type Arr_u8_16
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsFuSa_Config_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsFuSa_Config_Element(P2CONST(Rte_DT_Arr_u8_16_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsFuSa_Config_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsFuSa_Config_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsFuSa_Display_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsFuSa_Display_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsFuSa_Display_Element(const Rte_DT_Arr_u8_64_0 *BsFuSa_Display_Element)
 *     Argument BsFuSa_Display_Element: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsFuSa_Display_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsFuSa_Display_Element(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsFuSa_Display_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsFuSa_Display_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsFuSa_Power_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsFuSa_Power_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsFuSa_Power_Element(const Rte_DT_Arr_u8_48_0 *BsFuSa_Power_Element)
 *     Argument BsFuSa_Power_Element: Rte_DT_Arr_u8_48_0* is of type Arr_u8_48
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsFuSa_Power_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsFuSa_Power_Element(P2CONST(Rte_DT_Arr_u8_48_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsFuSa_Power_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsFuSa_Power_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsFuSa_Warning_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsFuSa_Warning_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsFuSa_Warning_Element(const Rte_DT_Arr_u8_32_0 *BsFuSa_Warning_Element)
 *     Argument BsFuSa_Warning_Element: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsFuSa_Warning_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsFuSa_Warning_Element(P2CONST(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsFuSa_Warning_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsFuSa_Warning_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsFusa_Fota_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsFusa_Fota_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsFusa_Fota_Element(const Rte_DT_Arr_u8_32_0 *BsFusa_Fota_Element)
 *     Argument BsFusa_Fota_Element: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsFusa_Fota_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsFusa_Fota_Element(P2CONST(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsFusa_Fota_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsFusa_Fota_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsReten_Audio_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsReten_Audio_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsReten_Audio_Element(const Rte_DT_Arr_u8_100_0 *BsReten_Audio_Element)
 *     Argument BsReten_Audio_Element: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsReten_Audio_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsReten_Audio_Element(P2CONST(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_Audio_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsReten_Audio_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsReten_Communication_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsReten_Communication_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsReten_Communication_Element(const Rte_DT_Arr_u8_100_0 *BsReten_Communication_Element)
 *     Argument BsReten_Communication_Element: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsReten_Communication_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsReten_Communication_Element(P2CONST(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_Communication_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsReten_Communication_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsReten_Display_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsReten_Display_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsReten_Display_Element(const Rte_DT_Arr_u8_100_0 *BsReten_Display_Element)
 *     Argument BsReten_Display_Element: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsReten_Display_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsReten_Display_Element(P2CONST(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_Display_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsReten_Display_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsReten_Gauges_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsReten_Gauges_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsReten_Gauges_Element(const Rte_DT_Arr_u8_100_0 *BsReten_Gauges_Element)
 *     Argument BsReten_Gauges_Element: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsReten_Gauges_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsReten_Gauges_Element(P2CONST(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_Gauges_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsReten_Gauges_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsReten_Illumination_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsReten_Illumination_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsReten_Illumination_Element(const Rte_DT_Arr_u8_100_0 *BsReten_Illumination_Element)
 *     Argument BsReten_Illumination_Element: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsReten_Illumination_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsReten_Illumination_Element(P2CONST(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_Illumination_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsReten_Illumination_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsReten_Odometer_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsReten_Odometer_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsReten_Odometer_Element(const Rte_DT_Arr_u8_100_0 *BsReten_Odometer_Element)
 *     Argument BsReten_Odometer_Element: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsReten_Odometer_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsReten_Odometer_Element(P2CONST(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_Odometer_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsReten_Odometer_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsReten_Personalization_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsReten_Personalization_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsReten_Personalization_Element(const Rte_DT_Arr_u8_100_0 *BsReten_Personalization_Element)
 *     Argument BsReten_Personalization_Element: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsReten_Personalization_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsReten_Personalization_Element(P2CONST(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_Personalization_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsReten_Personalization_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsReten_Power_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsReten_Power_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsReten_Power_Element(const Rte_DT_Arr_u8_100_0 *BsReten_Power_Element)
 *     Argument BsReten_Power_Element: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsReten_Power_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsReten_Power_Element(P2CONST(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_Power_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsReten_Power_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsReten_RealTimeClock_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsReten_RealTimeClock_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsReten_RealTimeClock_Element(const Rte_DT_Arr_u8_100_0 *BsReten_RealTimeClock_Element)
 *     Argument BsReten_RealTimeClock_Element: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsReten_RealTimeClock_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsReten_RealTimeClock_Element(P2CONST(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_RealTimeClock_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsReten_RealTimeClock_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsReten_Tripcomputer_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsReten_Tripcomputer_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsReten_Tripcomputer_Element(const Rte_DT_Arr_u8_100_0 *BsReten_Tripcomputer_Element)
 *     Argument BsReten_Tripcomputer_Element: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsReten_Tripcomputer_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsReten_Tripcomputer_Element(P2CONST(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_Tripcomputer_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsReten_Tripcomputer_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsReten_VisDlt_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsReten_VisDlt_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsReten_VisDlt_Element(const Rte_DT_Arr_u8_256_0 *BsReten_VisDlt_Element)
 *     Argument BsReten_VisDlt_Element: Rte_DT_Arr_u8_256_0* is of type Arr_u8_256
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsReten_VisDlt_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsReten_VisDlt_Element(P2CONST(Rte_DT_Arr_u8_256_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_VisDlt_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsReten_VisDlt_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsReten_Warning_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsReten_Warning_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsReten_Warning_Element(const Rte_DT_Arr_u8_100_0 *BsReten_Warning_Element)
 *     Argument BsReten_Warning_Element: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsReten_Warning_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsReten_Warning_Element(P2CONST(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_Warning_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsReten_Warning_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsRt_CusDlt_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsRt_CusDlt_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsRt_CusDlt_Element(const Rte_DT_Arr_u8_128_0 *BsRt_CusDlt_Element)
 *     Argument BsRt_CusDlt_Element: Rte_DT_Arr_u8_128_0* is of type Arr_u8_128
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsRt_CusDlt_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsRt_CusDlt_Element(P2CONST(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_CusDlt_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsRt_CusDlt_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsRt_FuelGauge_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsRt_FuelGauge_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsRt_FuelGauge_Element(const Rte_DT_Arr_u8_32_0 *BsRt_FuelGauge_Element)
 *     Argument BsRt_FuelGauge_Element: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsRt_FuelGauge_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsRt_FuelGauge_Element(P2CONST(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_FuelGauge_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsRt_FuelGauge_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsRt_Illumination_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsRt_Illumination_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsRt_Illumination_Element(const Rte_DT_Arr_u8_100_0 *BsRt_Illumination_Element)
 *     Argument BsRt_Illumination_Element: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsRt_Illumination_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsRt_Illumination_Element(P2CONST(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_Illumination_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsRt_Illumination_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsRt_Odometer_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsRt_Odometer_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsRt_Odometer_Element(const Rte_DT_Arr_u8_128_0 *BsRt_Odometer_Element)
 *     Argument BsRt_Odometer_Element: Rte_DT_Arr_u8_128_0* is of type Arr_u8_128
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsRt_Odometer_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsRt_Odometer_Element(P2CONST(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_Odometer_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsRt_Odometer_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsRt_OilGauge_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsRt_OilGauge_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsRt_OilGauge_Element(const Rte_DT_Arr_u8_8_0 *BsRt_OilGauge_Element)
 *     Argument BsRt_OilGauge_Element: Rte_DT_Arr_u8_8_0* is of type Arr_u8_8
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsRt_OilGauge_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsRt_OilGauge_Element(P2CONST(Rte_DT_Arr_u8_8_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_OilGauge_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsRt_OilGauge_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsRt_Personalization_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsRt_Personalization_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsRt_Personalization_Element(const Rte_DT_Arr_u8_128_0 *BsRt_Personalization_Element)
 *     Argument BsRt_Personalization_Element: Rte_DT_Arr_u8_128_0* is of type Arr_u8_128
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsRt_Personalization_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsRt_Personalization_Element(P2CONST(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_Personalization_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsRt_Personalization_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsRt_PowerGauge_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsRt_PowerGauge_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsRt_PowerGauge_Element(const Rte_DT_Arr_u8_32_0 *BsRt_PowerGauge_Element)
 *     Argument BsRt_PowerGauge_Element: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsRt_PowerGauge_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsRt_PowerGauge_Element(P2CONST(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_PowerGauge_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsRt_PowerGauge_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsRt_RealTimeClock_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsRt_RealTimeClock_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsRt_RealTimeClock_Element(const Rte_DT_Arr_u8_48_0 *BsRt_RealTimeClock_Element)
 *     Argument BsRt_RealTimeClock_Element: Rte_DT_Arr_u8_48_0* is of type Arr_u8_48
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsRt_RealTimeClock_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsRt_RealTimeClock_Element(P2CONST(Rte_DT_Arr_u8_48_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_RealTimeClock_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsRt_RealTimeClock_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsRt_SpeedoGauge_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsRt_SpeedoGauge_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsRt_SpeedoGauge_Element(const Rte_DT_Arr_u8_8_0 *BsRt_SpeedoGauge_Element)
 *     Argument BsRt_SpeedoGauge_Element: Rte_DT_Arr_u8_8_0* is of type Arr_u8_8
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsRt_SpeedoGauge_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsRt_SpeedoGauge_Element(P2CONST(Rte_DT_Arr_u8_8_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_SpeedoGauge_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsRt_SpeedoGauge_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsRt_TachoGauge_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsRt_TachoGauge_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsRt_TachoGauge_Element(const Rte_DT_Arr_u8_16_0 *BsRt_TachoGauge_Element)
 *     Argument BsRt_TachoGauge_Element: Rte_DT_Arr_u8_16_0* is of type Arr_u8_16
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsRt_TachoGauge_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsRt_TachoGauge_Element(P2CONST(Rte_DT_Arr_u8_16_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_TachoGauge_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsRt_TachoGauge_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsRt_TempGauge_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsRt_TempGauge_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsRt_TempGauge_Element(const Rte_DT_Arr_u8_32_0 *BsRt_TempGauge_Element)
 *     Argument BsRt_TempGauge_Element: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsRt_TempGauge_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsRt_TempGauge_Element(P2CONST(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_TempGauge_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsRt_TempGauge_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsRt_TripComputer_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsRt_TripComputer_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsRt_TripComputer_Element(const Rte_DT_Arr_u8_64_0 *BsRt_TripComputer_Element)
 *     Argument BsRt_TripComputer_Element: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsRt_TripComputer_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsRt_TripComputer_Element(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_TripComputer_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsRt_TripComputer_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsRt_Warning_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsRt_Warning_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsRt_Warning_Element(const Rte_DT_Arr_u8_32_0 *BsRt_Warning_Element)
 *     Argument BsRt_Warning_Element: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsRt_Warning_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsRt_Warning_Element(P2CONST(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_Warning_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsRt_Warning_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsShare_EcuPartNumber_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsShare_EcuPartNumber_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsShare_EcuPartNumber_Element(const Rte_DT_Arr_u8_128_0 *BsShare_EcuPartNumber_Element)
 *     Argument BsShare_EcuPartNumber_Element: Rte_DT_Arr_u8_128_0* is of type Arr_u8_128
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsShare_EcuPartNumber_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsShare_EcuPartNumber_Element(P2CONST(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_EcuPartNumber_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsShare_EcuPartNumber_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsShare_SwUpdFotaFinPrint_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsShare_SwUpdFotaFinPrint_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsShare_SwUpdFotaFinPrint_Element(const Rte_DT_Arr_u8_32_0 *BsShare_SwUpdFotaFinPrint_Element)
 *     Argument BsShare_SwUpdFotaFinPrint_Element: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsShare_SwUpdFotaFinPrint_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsShare_SwUpdFotaFinPrint_Element(P2CONST(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_SwUpdFotaFinPrint_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsShare_SwUpdFotaFinPrint_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsShare_SwUpdFotaMode_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsShare_SwUpdFotaMode_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsShare_SwUpdFotaMode_Element(const Rte_DT_Arr_u8_16_0 *BsShare_SwUpdFotaMode_Element)
 *     Argument BsShare_SwUpdFotaMode_Element: Rte_DT_Arr_u8_16_0* is of type Arr_u8_16
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsShare_SwUpdFotaMode_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsShare_SwUpdFotaMode_Element(P2CONST(Rte_DT_Arr_u8_16_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_SwUpdFotaMode_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsShare_SwUpdFotaMode_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsShare_SwUpdFotaStatus_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsShare_SwUpdFotaStatus_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsShare_SwUpdFotaStatus_Element(const Rte_DT_Arr_u8_48_0 *BsShare_SwUpdFotaStatus_Element)
 *     Argument BsShare_SwUpdFotaStatus_Element: Rte_DT_Arr_u8_48_0* is of type Arr_u8_48
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsShare_SwUpdFotaStatus_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsShare_SwUpdFotaStatus_Element(P2CONST(Rte_DT_Arr_u8_48_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_SwUpdFotaStatus_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsShare_SwUpdFotaStatus_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsShare_SwUpdFotadecrypt_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsShare_SwUpdFotadecrypt_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsShare_SwUpdFotadecrypt_Element(const Rte_DT_Arr_u8_64_0 *BsShare_SwUpdFotadecrypt_Element)
 *     Argument BsShare_SwUpdFotadecrypt_Element: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsShare_SwUpdFotadecrypt_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsShare_SwUpdFotadecrypt_Element(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_SwUpdFotadecrypt_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsShare_SwUpdFotadecrypt_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsShare_SwUpdReflash_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsShare_SwUpdReflash_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsShare_SwUpdReflash_Element(const Rte_DT_Arr_u8_8_0 *BsShare_SwUpdReflash_Element)
 *     Argument BsShare_SwUpdReflash_Element: Rte_DT_Arr_u8_8_0* is of type Arr_u8_8
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsShare_SwUpdReflash_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsShare_SwUpdReflash_Element(P2CONST(Rte_DT_Arr_u8_8_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_SwUpdReflash_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsShare_SwUpdReflash_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsShare_VehicleConfig_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsShare_VehicleConfig_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsShare_VehicleConfig_Element(const Rte_DT_Arr_u8_256_0 *BsShare_VehicleConfig_Element)
 *     Argument BsShare_VehicleConfig_Element: Rte_DT_Arr_u8_256_0* is of type Arr_u8_256
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsShare_VehicleConfig_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsShare_VehicleConfig_Element(P2CONST(Rte_DT_Arr_u8_256_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_VehicleConfig_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsShare_VehicleConfig_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsShare_VisMeet_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsShare_VisMeet_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsShare_VisMeet_Element(const Rte_DT_Arr_u8_48_0 *BsShare_VisMeet_Element)
 *     Argument BsShare_VisMeet_Element: Rte_DT_Arr_u8_48_0* is of type Arr_u8_48
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsShare_VisMeet_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsShare_VisMeet_Element(P2CONST(Rte_DT_Arr_u8_48_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_VisMeet_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsShare_VisMeet_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_RefCys_Certicificate1_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_RefCys_Certicificate1_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_RefCys_Certicificate1_Element(const Rte_DT_Arr_u8_64_0 *RefCys_Certicificate1_Element)
 *     Argument RefCys_Certicificate1_Element: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_RefCys_Certicificate1_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_RefCys_Certicificate1_Element(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) RefCys_Certicificate1_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_RefCys_Certicificate1_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_RefCys_Certicificate_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_RefCys_Certicificate_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_RefCys_Certicificate_Element(const Rte_DT_Arr_u8_64_0 *RefCys_Certicificate_Element)
 *     Argument RefCys_Certicificate_Element: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_RefCys_Certicificate_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_RefCys_Certicificate_Element(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) RefCys_Certicificate_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_RefCys_Certicificate_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define MemAbstractMdl_STOP_SEC_CODE
#include "MemAbstractMdl_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


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
