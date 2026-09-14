/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  MemAbstractStub.c
 *        Config:  BMW.dpa
 *     SW-C Type:  MemAbstractStub
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  C-Code implementation template for SW-C <MemAbstractStub>
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

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************
 *
 * Data Types:
 * ===========
 * NvM_RequestResultType
 *   
 *
 * NvM_ServiceIdType
 *   
 *
 *********************************************************************************************************************/

#include "Rte_MemAbstractStub.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_MemAbstractStub.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"

static void MemAbstractStub_TestDefines(void);


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
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * NvM_RequestResultType: Enumeration of integer in interval [0...255] with enumerators
 *   NVM_REQ_OK (0U)
 *   NVM_REQ_NOT_OK (1U)
 *   NVM_REQ_PENDING (2U)
 *   NVM_REQ_INTEGRITY_FAILED (3U)
 *   NVM_REQ_BLOCK_SKIPPED (4U)
 *   NVM_REQ_NV_INVALIDATED (5U)
 *   NVM_REQ_CANCELED (6U)
 *   NVM_REQ_REDUNDANCY_FAILED (7U)
 *   NVM_REQ_RESTORED_FROM_ROM (8U)
 * NvM_ServiceIdType: Enumeration of integer in interval [0...255] with enumerators
 *   NVM_READ_BLOCK (6U)
 *   NVM_WRITE_BLOCK (7U)
 *   NVM_RESTORE_BLOCK_DEFAULTS (8U)
 *   NVM_ERASE_BLOCK (9U)
 *   NVM_INVALIDATE_NV_BLOCK (11U)
 *   NVM_READ_ALL (12U)
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


#define MemAbstractStub_START_SEC_CODE
#include "MemAbstractStub_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_NotifyJobEnd_BsConst_Audio
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <BsConst_Audio_NvMNotifyJobFinished>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_NotifyJobEnd_BsConst_Audio(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsConst_Audio_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsConst_Audio(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsConst_Audio
 *********************************************************************************************************************/

  MemAbstractStub_TestDefines();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_NotifyJobEnd_BsConst_Communication
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <BsConst_Communication_NvMNotifyJobFinished>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_NotifyJobEnd_BsConst_Communication(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsConst_Communication_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsConst_Communication(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsConst_Communication
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_NotifyJobEnd_BsConst_EngOffTimer
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <BsConst_EngOffTimer_NvMNotifyJobFinished>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_NotifyJobEnd_BsConst_EngOffTimer(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsConst_EngOffTimer_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsConst_EngOffTimer(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsConst_EngOffTimer
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_NotifyJobEnd_BsConst_FuelGauge
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <BsConst_FuelGauge_NvMNotifyJobFinished>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_NotifyJobEnd_BsConst_FuelGauge(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsConst_FuelGauge_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsConst_FuelGauge(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsConst_FuelGauge
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_NotifyJobEnd_BsConst_OilGauge
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <BsConst_OilGauge_NvMNotifyJobFinished>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_NotifyJobEnd_BsConst_OilGauge(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsConst_OilGauge_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsConst_OilGauge(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsConst_OilGauge
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_NotifyJobEnd_BsConst_Power
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <BsConst_Power_NvMNotifyJobFinished>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_NotifyJobEnd_BsConst_Power(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsConst_Power_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsConst_Power(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsConst_Power
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_NotifyJobEnd_BsConst_PowerGauge
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <BsConst_PowerGauge_NvMNotifyJobFinished>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_NotifyJobEnd_BsConst_PowerGauge(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsConst_PowerGauge_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsConst_PowerGauge(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsConst_PowerGauge
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_NotifyJobEnd_BsConst_RealTimeClock
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <BsConst_RealTimeClock_NvMNotifyJobFinished>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_NotifyJobEnd_BsConst_RealTimeClock(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsConst_RealTimeClock_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsConst_RealTimeClock(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsConst_RealTimeClock
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_NotifyJobEnd_BsConst_ServiceReminder
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <BsConst_ServiceReminder_NvMNotifyJobFinished>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_NotifyJobEnd_BsConst_ServiceReminder(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsConst_ServiceReminder_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsConst_ServiceReminder(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsConst_ServiceReminder
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_NotifyJobEnd_BsConst_SpeedoGauge
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <BsConst_SpeedoGauge_NvMNotifyJobFinished>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_NotifyJobEnd_BsConst_SpeedoGauge(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsConst_SpeedoGauge_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsConst_SpeedoGauge(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsConst_SpeedoGauge
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_NotifyJobEnd_BsConst_TachoGauge
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <BsConst_TachoGauge_NvMNotifyJobFinished>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_NotifyJobEnd_BsConst_TachoGauge(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsConst_TachoGauge_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsConst_TachoGauge(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsConst_TachoGauge
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_NotifyJobEnd_BsConst_TempGauge
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <BsConst_TempGauge_NvMNotifyJobFinished>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_NotifyJobEnd_BsConst_TempGauge(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsConst_TempGauge_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsConst_TempGauge(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsConst_TempGauge
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_NotifyJobEnd_BsConst_TripComputer
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <BsConst_TripComputer_NvMNotifyJobFinished>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_NotifyJobEnd_BsConst_TripComputer(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsConst_TripComputer_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsConst_TripComputer(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsConst_TripComputer
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_NotifyJobEnd_BsConst_Warning
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <BsConst_Warning_NvMNotifyJobFinished>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_NotifyJobEnd_BsConst_Warning(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsConst_Warning_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsConst_Warning(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsConst_Warning
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_NotifyJobEnd_BsCys_Certicificate
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <BsCys_Certicificate_NvMNotifyJobFinished>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_NotifyJobEnd_BsCys_Certicificate(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsCys_Certicificate_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsCys_Certicificate(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsCys_Certicificate
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_NotifyJobEnd_BsDiag_Dtc
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <BsDiag_Dtc_NvMNotifyJobFinished>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_NotifyJobEnd_BsDiag_Dtc(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsDiag_Dtc_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsDiag_Dtc(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsDiag_Dtc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_NotifyJobEnd_BsDiag_ErrorRecord
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <BsDiag_ErrorRecord_NvMNotifyJobFinished>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_NotifyJobEnd_BsDiag_ErrorRecord(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsDiag_ErrorRecord_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsDiag_ErrorRecord(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsDiag_ErrorRecord
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_NotifyJobEnd_BsReten_Audio
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <BsReten_Audio_NvMNotifyJobFinished>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_NotifyJobEnd_BsReten_Audio(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsReten_Audio_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsReten_Audio(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsReten_Audio
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_NotifyJobEnd_BsReten_Communication
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <BsReten_Communication_NvMNotifyJobFinished>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_NotifyJobEnd_BsReten_Communication(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsReten_Communication_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsReten_Communication(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsReten_Communication
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_NotifyJobEnd_BsReten_Display
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <BsReten_Display_NvMNotifyJobFinished>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_NotifyJobEnd_BsReten_Display(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsReten_Display_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsReten_Display(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsReten_Display
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_NotifyJobEnd_BsReten_Gauges
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <BsReten_Gauges_NvMNotifyJobFinished>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_NotifyJobEnd_BsReten_Gauges(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsReten_Gauges_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsReten_Gauges(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsReten_Gauges
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_NotifyJobEnd_BsReten_Illumination
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <BsReten_Illumination_NvMNotifyJobFinished>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_NotifyJobEnd_BsReten_Illumination(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsReten_Illumination_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsReten_Illumination(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsReten_Illumination
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_NotifyJobEnd_BsReten_Odometer
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <BsReten_Odometer_NvMNotifyJobFinished>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_NotifyJobEnd_BsReten_Odometer(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsReten_Odometer_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsReten_Odometer(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsReten_Odometer
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_NotifyJobEnd_BsReten_Personalization
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <BsReten_Personalization_NvMNotifyJobFinished>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_NotifyJobEnd_BsReten_Personalization(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsReten_Personalization_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsReten_Personalization(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsReten_Personalization
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_NotifyJobEnd_BsReten_Power
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <BsReten_Power_NvMNotifyJobFinished>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_NotifyJobEnd_BsReten_Power(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsReten_Power_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsReten_Power(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsReten_Power
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_NotifyJobEnd_BsReten_RealTimeClock
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <BsReten_RealTimeClock_NvMNotifyJobFinished>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_NotifyJobEnd_BsReten_RealTimeClock(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsReten_RealTimeClock_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsReten_RealTimeClock(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsReten_RealTimeClock
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_NotifyJobEnd_BsReten_Tripcomputer
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <BsReten_Tripcomputer_NvMNotifyJobFinished>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_NotifyJobEnd_BsReten_Tripcomputer(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsReten_Tripcomputer_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsReten_Tripcomputer(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsReten_Tripcomputer
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_NotifyJobEnd_BsReten_Warning
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <BsReten_Warning_NvMNotifyJobFinished>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_NotifyJobEnd_BsReten_Warning(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsReten_Warning_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsReten_Warning(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsReten_Warning
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_NotifyJobEnd_BsRt_CusDlt
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <BsRt_CusDlt_NvMNotifyJobFinished>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_NotifyJobEnd_BsRt_CusDlt(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsRt_CusDlt_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsRt_CusDlt(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsRt_CusDlt
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_NotifyJobEnd_BsRt_FuelGauge
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <BsRt_FuelGauge_NvMNotifyJobFinished>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_NotifyJobEnd_BsRt_FuelGauge(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsRt_FuelGauge_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsRt_FuelGauge(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsRt_FuelGauge
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_NotifyJobEnd_BsRt_Illumination
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <BsRt_Illumination_NvMNotifyJobFinished>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_NotifyJobEnd_BsRt_Illumination(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsRt_Illumination_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsRt_Illumination(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsRt_Illumination
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_NotifyJobEnd_BsRt_Odometer
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <BsRt_Odometer_NvMNotifyJobFinished>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_NotifyJobEnd_BsRt_Odometer(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsRt_Odometer_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsRt_Odometer(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsRt_Odometer
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_NotifyJobEnd_BsRt_OilGauge
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <BsRt_OilGauge_NvMNotifyJobFinished>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_NotifyJobEnd_BsRt_OilGauge(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsRt_OilGauge_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsRt_OilGauge(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsRt_OilGauge
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_NotifyJobEnd_BsRt_Personalization
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <BsRt_Personalization_NvMNotifyJobFinished>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_NotifyJobEnd_BsRt_Personalization(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsRt_Personalization_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsRt_Personalization(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsRt_Personalization
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_NotifyJobEnd_BsRt_PowerGauge
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <BsRt_PowerGauge_NvMNotifyJobFinished>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_NotifyJobEnd_BsRt_PowerGauge(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsRt_PowerGauge_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsRt_PowerGauge(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsRt_PowerGauge
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_NotifyJobEnd_BsRt_RealTimeClock
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <BsRt_RealTimeClock_NvMNotifyJobFinished>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_NotifyJobEnd_BsRt_RealTimeClock(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsRt_RealTimeClock_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsRt_RealTimeClock(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsRt_RealTimeClock
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_NotifyJobEnd_BsRt_SpeedoGauge
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <BsRt_SpeedoGauge_NvMNotifyJobFinished>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_NotifyJobEnd_BsRt_SpeedoGauge(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsRt_SpeedoGauge_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsRt_SpeedoGauge(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsRt_SpeedoGauge
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_NotifyJobEnd_BsRt_TachoGauge
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <BsRt_TachoGauge_NvMNotifyJobFinished>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_NotifyJobEnd_BsRt_TachoGauge(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsRt_TachoGauge_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsRt_TachoGauge(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsRt_TachoGauge
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_NotifyJobEnd_BsRt_TempGauge
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <BsRt_TempGauge_NvMNotifyJobFinished>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_NotifyJobEnd_BsRt_TempGauge(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsRt_TempGauge_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsRt_TempGauge(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsRt_TempGauge
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_NotifyJobEnd_BsRt_TripComputer
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <BsRt_TripComputer_NvMNotifyJobFinished>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_NotifyJobEnd_BsRt_TripComputer(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsRt_TripComputer_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsRt_TripComputer(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsRt_TripComputer
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_NotifyJobEnd_BsRt_Warning
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <BsRt_Warning_NvMNotifyJobFinished>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_NotifyJobEnd_BsRt_Warning(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsRt_Warning_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsRt_Warning(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsRt_Warning
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_NotifyJobEnd_BsShare_EcuPartNumber
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <BsShare_EcuPartNumber_NvMNotifyJobFinished>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_NotifyJobEnd_BsShare_EcuPartNumber(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsShare_EcuPartNumber_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsShare_EcuPartNumber(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsShare_EcuPartNumber
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_NotifyJobEnd_BsShare_SwUpdFotaFinPrint
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <BsShare_SwUpdFotaFinPrint_NvMNotifyJobFinished>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_NotifyJobEnd_BsShare_SwUpdFotaFinPrint(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsShare_SwUpdFotaFinPrint_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsShare_SwUpdFotaFinPrint(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsShare_SwUpdFotaFinPrint
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_NotifyJobEnd_BsShare_SwUpdFotaMode
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <BsShare_SwUpdFotaMode_NvMNotifyJobFinished>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_NotifyJobEnd_BsShare_SwUpdFotaMode(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsShare_SwUpdFotaMode_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsShare_SwUpdFotaMode(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsShare_SwUpdFotaMode
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_NotifyJobEnd_BsShare_SwUpdFotaStatus
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <BsShare_SwUpdFotaStatus_NvMNotifyJobFinished>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_NotifyJobEnd_BsShare_SwUpdFotaStatus(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsShare_SwUpdFotaStatus_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsShare_SwUpdFotaStatus(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsShare_SwUpdFotaStatus
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_NotifyJobEnd_BsShare_SwUpdFotadecrypt
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <BsShare_SwUpdFotadecrypt_NvMNotifyJobFinished>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_NotifyJobEnd_BsShare_SwUpdFotadecrypt(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsShare_SwUpdFotadecrypt_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsShare_SwUpdFotadecrypt(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsShare_SwUpdFotadecrypt
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_NotifyJobEnd_BsShare_SwUpdReflash
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <BsShare_SwUpdReflash_NvMNotifyJobFinished>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_NotifyJobEnd_BsShare_SwUpdReflash(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsShare_SwUpdReflash_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsShare_SwUpdReflash(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsShare_SwUpdReflash
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_NotifyJobEnd_BsShare_VehicleConfig
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <BsShare_VehicleConfig_NvMNotifyJobFinished>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_NotifyJobEnd_BsShare_VehicleConfig(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsShare_VehicleConfig_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsShare_VehicleConfig(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsShare_VehicleConfig
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_NotifyJobEnd_BsShare_VisMeet
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <BsShare_VisMeet_NvMNotifyJobFinished>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_NotifyJobEnd_BsShare_VisMeet(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsShare_VisMeet_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsShare_VisMeet(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_BsShare_VisMeet
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_NotifyJobEnd_RefCys_Certicificate
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <RefCys_Certicificate_NvMNotifyJobFinished>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_NotifyJobEnd_RefCys_Certicificate(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_RefCys_Certicificate_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_RefCys_Certicificate(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_RefCys_Certicificate
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_NotifyJobEnd_RefCys_Certicificate1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <RefCys_Certicificate1_NvMNotifyJobFinished>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_NotifyJobEnd_RefCys_Certicificate1(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_RefCys_Certicificate1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_RefCys_Certicificate1(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NotifyJobEnd_RefCys_Certicificate1
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstract_MainFunction
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_BsConst_Audio_Element_Value(Rte_DT_Arr_u8_128_0 *data)
 *     Argument data: Rte_DT_Arr_u8_128_0* is of type Arr_u8_128
 *   Std_ReturnType Rte_Read_BsConst_BsConst_Illumination_ReservedByte_Value(Rte_DT_Arr_u8_28_0 *data)
 *     Argument data: Rte_DT_Arr_u8_28_0* is of type Arr_u8_28
 *   Std_ReturnType Rte_Read_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1_Value(Rte_DT_Arr_u8_28_0 *data)
 *     Argument data: Rte_DT_Arr_u8_28_0* is of type Arr_u8_28
 *   Std_ReturnType Rte_Read_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2_Value(Rte_DT_Arr_u8_28_0 *data)
 *     Argument data: Rte_DT_Arr_u8_28_0* is of type Arr_u8_28
 *   Std_ReturnType Rte_Read_BsConst_Communication_Element_Value(Rte_DT_Arr_u8_64_0 *data)
 *     Argument data: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *   Std_ReturnType Rte_Read_BsConst_Compensation_Line_Shift_b_Value(uint32 *data)
 *   Std_ReturnType Rte_Read_BsConst_Compensation_Line_Shift_b_SafeCopy1_Value(uint32 *data)
 *   Std_ReturnType Rte_Read_BsConst_Compensation_Line_Shift_b_SafeCopy2_Value(uint32 *data)
 *   Std_ReturnType Rte_Read_BsConst_Compensation_Line_Slope_m_Value(uint32 *data)
 *   Std_ReturnType Rte_Read_BsConst_Compensation_Line_Slope_m_SafeCopy1_Value(uint32 *data)
 *   Std_ReturnType Rte_Read_BsConst_Compensation_Line_Slope_m_SafeCopy2_Value(uint32 *data)
 *   Std_ReturnType Rte_Read_BsConst_Derating_Backlight_Disable_Value(uint8 *data)
 *   Std_ReturnType Rte_Read_BsConst_Derating_Backlight_Disable_SafeCopy1_Value(uint8 *data)
 *   Std_ReturnType Rte_Read_BsConst_Derating_Backlight_Disable_SafeCopy2_Value(uint8 *data)
 *   Std_ReturnType Rte_Read_BsConst_Display_Illum_Max_Level_Value(uint16 *data)
 *   Std_ReturnType Rte_Read_BsConst_Display_Illum_Max_Level_SafeCopy1_Value(uint16 *data)
 *   Std_ReturnType Rte_Read_BsConst_Display_Illum_Max_Level_SafeCopy2_Value(uint16 *data)
 *   Std_ReturnType Rte_Read_BsConst_EngOffTimer_Element_Value(Rte_DT_Arr_u8_32_0 *data)
 *     Argument data: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *   Std_ReturnType Rte_Read_BsConst_FuelGauge_Element_Value(Rte_DT_Arr_u8_128_0 *data)
 *     Argument data: Rte_DT_Arr_u8_128_0* is of type Arr_u8_128
 *   Std_ReturnType Rte_Read_BsConst_Lookup_Curve_HotSpot_Coef_X_Value(Rte_DT_Arr_u16_7_0 *data)
 *     Argument data: Rte_DT_Arr_u16_7_0* is of type Arr_u16_7
 *   Std_ReturnType Rte_Read_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1_Value(Rte_DT_Arr_u16_7_0 *data)
 *     Argument data: Rte_DT_Arr_u16_7_0* is of type Arr_u16_7
 *   Std_ReturnType Rte_Read_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2_Value(Rte_DT_Arr_u16_7_0 *data)
 *     Argument data: Rte_DT_Arr_u16_7_0* is of type Arr_u16_7
 *   Std_ReturnType Rte_Read_BsConst_Lookup_Curve_HotSpot_Coef_Y_Value(Rte_DT_Arr_u16_7_0 *data)
 *     Argument data: Rte_DT_Arr_u16_7_0* is of type Arr_u16_7
 *   Std_ReturnType Rte_Read_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1_Value(Rte_DT_Arr_u16_7_0 *data)
 *     Argument data: Rte_DT_Arr_u16_7_0* is of type Arr_u16_7
 *   Std_ReturnType Rte_Read_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2_Value(Rte_DT_Arr_u16_7_0 *data)
 *     Argument data: Rte_DT_Arr_u16_7_0* is of type Arr_u16_7
 *   Std_ReturnType Rte_Read_BsConst_OilGauge_Element_Value(Rte_DT_Arr_u8_64_0 *data)
 *     Argument data: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *   Std_ReturnType Rte_Read_BsConst_PCB_Temperature_Sensor_Conv_Value(Rte_DT_T_NV_Temperature_Conversion_0 *data)
 *     Argument data: Rte_DT_T_NV_Temperature_Conversion_0* is of type T_NV_Temperature_Conversion
 *   Std_ReturnType Rte_Read_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1_Value(Rte_DT_T_NV_Temperature_Conversion_0 *data)
 *     Argument data: Rte_DT_T_NV_Temperature_Conversion_0* is of type T_NV_Temperature_Conversion
 *   Std_ReturnType Rte_Read_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2_Value(Rte_DT_T_NV_Temperature_Conversion_0 *data)
 *     Argument data: Rte_DT_T_NV_Temperature_Conversion_0* is of type T_NV_Temperature_Conversion
 *   Std_ReturnType Rte_Read_BsConst_PWM_boost_bypass_duty_Value(uint8 *data)
 *   Std_ReturnType Rte_Read_BsConst_PWM_boost_bypass_duty_SafeCopy1_Value(uint8 *data)
 *   Std_ReturnType Rte_Read_BsConst_PWM_boost_bypass_duty_SafeCopy2_Value(uint8 *data)
 *   Std_ReturnType Rte_Read_BsConst_PowerGauge_Element_Value(Rte_DT_Arr_u8_64_0 *data)
 *     Argument data: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *   Std_ReturnType Rte_Read_BsConst_Power_Element_Value(Rte_DT_Arr_u8_32_0 *data)
 *     Argument data: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *   Std_ReturnType Rte_Read_BsConst_RealTimeClock_Element_Value(Rte_DT_Arr_u8_48_0 *data)
 *     Argument data: Rte_DT_Arr_u8_48_0* is of type Arr_u8_48
 *   Std_ReturnType Rte_Read_BsConst_ServiceReminder_Element_Value(Rte_DT_Arr_u8_48_0 *data)
 *     Argument data: Rte_DT_Arr_u8_48_0* is of type Arr_u8_48
 *   Std_ReturnType Rte_Read_BsConst_SpeedoGauge_Element_Value(Rte_DT_Arr_u8_64_0 *data)
 *     Argument data: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *   Std_ReturnType Rte_Read_BsConst_TachoGauge_Element_Value(Rte_DT_Arr_u8_64_0 *data)
 *     Argument data: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *   Std_ReturnType Rte_Read_BsConst_TempGauge_Element_Value(Rte_DT_Arr_u8_64_0 *data)
 *     Argument data: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *   Std_ReturnType Rte_Read_BsConst_Temp_Threshold_Hysteresis_Derating_Value(uint8 *data)
 *   Std_ReturnType Rte_Read_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1_Value(uint8 *data)
 *   Std_ReturnType Rte_Read_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2_Value(uint8 *data)
 *   Std_ReturnType Rte_Read_BsConst_Temperature_Sensor_Conv_Value(Rte_DT_T_NV_Temperature_Conversion_0 *data)
 *     Argument data: Rte_DT_T_NV_Temperature_Conversion_0* is of type T_NV_Temperature_Conversion
 *   Std_ReturnType Rte_Read_BsConst_Temperature_Sensor_Conv_SafeCopy1_Value(Rte_DT_T_NV_Temperature_Conversion_0 *data)
 *     Argument data: Rte_DT_T_NV_Temperature_Conversion_0* is of type T_NV_Temperature_Conversion
 *   Std_ReturnType Rte_Read_BsConst_Temperature_Sensor_Conv_SafeCopy2_Value(Rte_DT_T_NV_Temperature_Conversion_0 *data)
 *     Argument data: Rte_DT_T_NV_Temperature_Conversion_0* is of type T_NV_Temperature_Conversion
 *   Std_ReturnType Rte_Read_BsConst_TripComputer_Element_Value(Rte_DT_Arr_u8_64_0 *data)
 *     Argument data: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *   Std_ReturnType Rte_Read_BsConst_Warning_Element_Value(Rte_DT_Arr_u8_64_0 *data)
 *     Argument data: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *   Std_ReturnType Rte_Read_BsCys_Certicificate_Element_Value(Rte_DT_Arr_u8_64_0 *data)
 *     Argument data: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *   Std_ReturnType Rte_Read_BsDiag_Dtc_Element_Value(Rte_DT_Arr_u8_2048_0 *data)
 *     Argument data: Rte_DT_Arr_u8_2048_0* is of type Arr_u8_2048
 *   Std_ReturnType Rte_Read_BsDiag_ErrorRecord_Element_Value(Rte_DT_Arr_u8_1024_0 *data)
 *     Argument data: Rte_DT_Arr_u8_1024_0* is of type Arr_u8_1024
 *   Std_ReturnType Rte_Read_BsReten_Audio_Element_Value(Rte_DT_Arr_u8_100_0 *data)
 *     Argument data: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *   Std_ReturnType Rte_Read_BsReten_Communication_Element_Value(Rte_DT_Arr_u8_100_0 *data)
 *     Argument data: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *   Std_ReturnType Rte_Read_BsReten_Display_Element_Value(Rte_DT_Arr_u8_100_0 *data)
 *     Argument data: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *   Std_ReturnType Rte_Read_BsReten_Gauges_Element_Value(Rte_DT_Arr_u8_100_0 *data)
 *     Argument data: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *   Std_ReturnType Rte_Read_BsReten_Illumination_Element_Value(Rte_DT_Arr_u8_100_0 *data)
 *     Argument data: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *   Std_ReturnType Rte_Read_BsReten_Odometer_Element_Value(Rte_DT_Arr_u8_100_0 *data)
 *     Argument data: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *   Std_ReturnType Rte_Read_BsReten_Personalization_Element_Value(Rte_DT_Arr_u8_100_0 *data)
 *     Argument data: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *   Std_ReturnType Rte_Read_BsReten_Power_Element_Value(Rte_DT_Arr_u8_100_0 *data)
 *     Argument data: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *   Std_ReturnType Rte_Read_BsReten_RealTimeClock_Element_Value(Rte_DT_Arr_u8_100_0 *data)
 *     Argument data: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *   Std_ReturnType Rte_Read_BsReten_Tripcomputer_Element_Value(Rte_DT_Arr_u8_100_0 *data)
 *     Argument data: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *   Std_ReturnType Rte_Read_BsReten_Warning_Element_Value(Rte_DT_Arr_u8_100_0 *data)
 *     Argument data: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *   Std_ReturnType Rte_Read_BsRt_CusDlt_Element_Value(Rte_DT_Arr_u8_128_0 *data)
 *     Argument data: Rte_DT_Arr_u8_128_0* is of type Arr_u8_128
 *   Std_ReturnType Rte_Read_BsRt_FuelGauge_Element_Value(Rte_DT_Arr_u8_32_0 *data)
 *     Argument data: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *   Std_ReturnType Rte_Read_BsRt_Illumination_Element_Value(Rte_DT_Arr_u8_100_0 *data)
 *     Argument data: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *   Std_ReturnType Rte_Read_BsRt_Odometer_Element_Value(Rte_DT_Arr_u8_128_0 *data)
 *     Argument data: Rte_DT_Arr_u8_128_0* is of type Arr_u8_128
 *   Std_ReturnType Rte_Read_BsRt_OilGauge_Element_Value(Rte_DT_Arr_u8_8_0 *data)
 *     Argument data: Rte_DT_Arr_u8_8_0* is of type Arr_u8_8
 *   Std_ReturnType Rte_Read_BsRt_Personalization_Element_Value(Rte_DT_Arr_u8_128_0 *data)
 *     Argument data: Rte_DT_Arr_u8_128_0* is of type Arr_u8_128
 *   Std_ReturnType Rte_Read_BsRt_PowerGauge_Element_Value(Rte_DT_Arr_u8_32_0 *data)
 *     Argument data: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *   Std_ReturnType Rte_Read_BsRt_RealTimeClock_Element_Value(Rte_DT_Arr_u8_48_0 *data)
 *     Argument data: Rte_DT_Arr_u8_48_0* is of type Arr_u8_48
 *   Std_ReturnType Rte_Read_BsRt_SpeedoGauge_Element_Value(Rte_DT_Arr_u8_8_0 *data)
 *     Argument data: Rte_DT_Arr_u8_8_0* is of type Arr_u8_8
 *   Std_ReturnType Rte_Read_BsRt_TachoGauge_Element_Value(Rte_DT_Arr_u8_16_0 *data)
 *     Argument data: Rte_DT_Arr_u8_16_0* is of type Arr_u8_16
 *   Std_ReturnType Rte_Read_BsRt_TempGauge_Element_Value(Rte_DT_Arr_u8_32_0 *data)
 *     Argument data: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *   Std_ReturnType Rte_Read_BsRt_TripComputer_Element_Value(Rte_DT_Arr_u8_64_0 *data)
 *     Argument data: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *   Std_ReturnType Rte_Read_BsRt_Warning_Element_Value(Rte_DT_Arr_u8_32_0 *data)
 *     Argument data: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *   Std_ReturnType Rte_Read_BsShare_AssemblyManufacturingDate_Value(Rte_DT_Arr_u8_3_0 *data)
 *     Argument data: Rte_DT_Arr_u8_3_0* is of type Arr_u8_3
 *   Std_ReturnType Rte_Read_BsShare_AssemblyPlantNumber_Value(Rte_DT_Arr_u8_3_0 *data)
 *     Argument data: Rte_DT_Arr_u8_3_0* is of type Arr_u8_3
 *   Std_ReturnType Rte_Read_BsShare_EcuPartNumber_Element_Value(Rte_DT_Arr_u8_61_0 *data)
 *     Argument data: Rte_DT_Arr_u8_61_0* is of type Arr_u8_61
 *   Std_ReturnType Rte_Read_BsShare_HWModification_Value(uint16 *data)
 *   Std_ReturnType Rte_Read_BsShare_PCBSerialNumber_Value(Rte_DT_Arr_u8_9_0 *data)
 *     Argument data: Rte_DT_Arr_u8_9_0* is of type Arr_u8_9
 *   Std_ReturnType Rte_Read_BsShare_ProductSerialNumber_Value(Rte_DT_Arr_u8_10_0 *data)
 *     Argument data: Rte_DT_Arr_u8_10_0* is of type Arr_u8_10
 *   Std_ReturnType Rte_Read_BsShare_SMTManufacturingDate_Value(Rte_DT_Arr_u8_3_0 *data)
 *     Argument data: Rte_DT_Arr_u8_3_0* is of type Arr_u8_3
 *   Std_ReturnType Rte_Read_BsShare_SMTPlantNumber_Value(Rte_DT_Arr_u8_3_0 *data)
 *     Argument data: Rte_DT_Arr_u8_3_0* is of type Arr_u8_3
 *   Std_ReturnType Rte_Read_BsShare_SwUpdFotaFinPrint_Element_Value(Rte_DT_Arr_u8_32_0 *data)
 *     Argument data: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *   Std_ReturnType Rte_Read_BsShare_SwUpdFotaMode_Element_Value(Rte_DT_Arr_u8_16_0 *data)
 *     Argument data: Rte_DT_Arr_u8_16_0* is of type Arr_u8_16
 *   Std_ReturnType Rte_Read_BsShare_SwUpdFotaStatus_Element_Value(Rte_DT_Arr_u8_48_0 *data)
 *     Argument data: Rte_DT_Arr_u8_48_0* is of type Arr_u8_48
 *   Std_ReturnType Rte_Read_BsShare_SwUpdFotadecrypt_Element_Value(Rte_DT_Arr_u8_64_0 *data)
 *     Argument data: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *   Std_ReturnType Rte_Read_BsShare_SwUpdReflash_Element_Value(Rte_DT_Arr_u8_8_0 *data)
 *     Argument data: Rte_DT_Arr_u8_8_0* is of type Arr_u8_8
 *   Std_ReturnType Rte_Read_BsShare_VehicleConfig_Element_Value(Rte_DT_Arr_u8_256_0 *data)
 *     Argument data: Rte_DT_Arr_u8_256_0* is of type Arr_u8_256
 *   Std_ReturnType Rte_Read_BsShare_VisMeet_EOLEntry_Element_Value(uint16 *data)
 *   Std_ReturnType Rte_Read_BsShare_VisMeet_Element_Value(Rte_DT_Arr_u8_46_0 *data)
 *     Argument data: Rte_DT_Arr_u8_46_0* is of type Arr_u8_46
 *   Std_ReturnType Rte_Read_BsShare_VisteonPCBPartNumber_Value(Rte_DT_Arr_u8_17_0 *data)
 *     Argument data: Rte_DT_Arr_u8_17_0* is of type Arr_u8_17
 *   Std_ReturnType Rte_Read_BsShare_VisteonPartNumber_Value(Rte_DT_Arr_u8_17_0 *data)
 *     Argument data: Rte_DT_Arr_u8_17_0* is of type Arr_u8_17
 *   Std_ReturnType Rte_Read_RefCys_Certicificate1_Element_Value(Rte_DT_Arr_u8_64_0 *data)
 *     Argument data: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *   Std_ReturnType Rte_Read_RefCys_Certicificate_Element_Value(Rte_DT_Arr_u8_64_0 *data)
 *     Argument data: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_BsConst_Audio_Element_Value(const Rte_DT_Arr_u8_128_0 *data)
 *     Argument data: Rte_DT_Arr_u8_128_0* is of type Arr_u8_128
 *   Std_ReturnType Rte_Write_BsConst_BsConst_Illumination_ReservedByte_Value(const Rte_DT_Arr_u8_28_0 *data)
 *     Argument data: Rte_DT_Arr_u8_28_0* is of type Arr_u8_28
 *   Std_ReturnType Rte_Write_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1_Value(const Rte_DT_Arr_u8_28_0 *data)
 *     Argument data: Rte_DT_Arr_u8_28_0* is of type Arr_u8_28
 *   Std_ReturnType Rte_Write_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2_Value(const Rte_DT_Arr_u8_28_0 *data)
 *     Argument data: Rte_DT_Arr_u8_28_0* is of type Arr_u8_28
 *   Std_ReturnType Rte_Write_BsConst_Communication_Element_Value(const Rte_DT_Arr_u8_64_0 *data)
 *     Argument data: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *   Std_ReturnType Rte_Write_BsConst_Compensation_Line_Shift_b_Value(uint32 data)
 *   Std_ReturnType Rte_Write_BsConst_Compensation_Line_Shift_b_SafeCopy1_Value(uint32 data)
 *   Std_ReturnType Rte_Write_BsConst_Compensation_Line_Shift_b_SafeCopy2_Value(uint32 data)
 *   Std_ReturnType Rte_Write_BsConst_Compensation_Line_Slope_m_Value(uint32 data)
 *   Std_ReturnType Rte_Write_BsConst_Compensation_Line_Slope_m_SafeCopy1_Value(uint32 data)
 *   Std_ReturnType Rte_Write_BsConst_Compensation_Line_Slope_m_SafeCopy2_Value(uint32 data)
 *   Std_ReturnType Rte_Write_BsConst_Derating_Backlight_Disable_Value(uint8 data)
 *   Std_ReturnType Rte_Write_BsConst_Derating_Backlight_Disable_SafeCopy1_Value(uint8 data)
 *   Std_ReturnType Rte_Write_BsConst_Derating_Backlight_Disable_SafeCopy2_Value(uint8 data)
 *   Std_ReturnType Rte_Write_BsConst_Display_Illum_Max_Level_Value(uint16 data)
 *   Std_ReturnType Rte_Write_BsConst_Display_Illum_Max_Level_SafeCopy1_Value(uint16 data)
 *   Std_ReturnType Rte_Write_BsConst_Display_Illum_Max_Level_SafeCopy2_Value(uint16 data)
 *   Std_ReturnType Rte_Write_BsConst_EngOffTimer_Element_Value(const Rte_DT_Arr_u8_32_0 *data)
 *     Argument data: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *   Std_ReturnType Rte_Write_BsConst_FuelGauge_Element_Value(const Rte_DT_Arr_u8_128_0 *data)
 *     Argument data: Rte_DT_Arr_u8_128_0* is of type Arr_u8_128
 *   Std_ReturnType Rte_Write_BsConst_Lookup_Curve_HotSpot_Coef_X_Value(const Rte_DT_Arr_u16_7_0 *data)
 *     Argument data: Rte_DT_Arr_u16_7_0* is of type Arr_u16_7
 *   Std_ReturnType Rte_Write_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1_Value(const Rte_DT_Arr_u16_7_0 *data)
 *     Argument data: Rte_DT_Arr_u16_7_0* is of type Arr_u16_7
 *   Std_ReturnType Rte_Write_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2_Value(const Rte_DT_Arr_u16_7_0 *data)
 *     Argument data: Rte_DT_Arr_u16_7_0* is of type Arr_u16_7
 *   Std_ReturnType Rte_Write_BsConst_Lookup_Curve_HotSpot_Coef_Y_Value(const Rte_DT_Arr_u16_7_0 *data)
 *     Argument data: Rte_DT_Arr_u16_7_0* is of type Arr_u16_7
 *   Std_ReturnType Rte_Write_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1_Value(const Rte_DT_Arr_u16_7_0 *data)
 *     Argument data: Rte_DT_Arr_u16_7_0* is of type Arr_u16_7
 *   Std_ReturnType Rte_Write_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2_Value(const Rte_DT_Arr_u16_7_0 *data)
 *     Argument data: Rte_DT_Arr_u16_7_0* is of type Arr_u16_7
 *   Std_ReturnType Rte_Write_BsConst_OilGauge_Element_Value(const Rte_DT_Arr_u8_64_0 *data)
 *     Argument data: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *   Std_ReturnType Rte_Write_BsConst_PCB_Temperature_Sensor_Conv_Value(const Rte_DT_T_NV_Temperature_Conversion_0 *data)
 *     Argument data: Rte_DT_T_NV_Temperature_Conversion_0* is of type T_NV_Temperature_Conversion
 *   Std_ReturnType Rte_Write_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1_Value(const Rte_DT_T_NV_Temperature_Conversion_0 *data)
 *     Argument data: Rte_DT_T_NV_Temperature_Conversion_0* is of type T_NV_Temperature_Conversion
 *   Std_ReturnType Rte_Write_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2_Value(const Rte_DT_T_NV_Temperature_Conversion_0 *data)
 *     Argument data: Rte_DT_T_NV_Temperature_Conversion_0* is of type T_NV_Temperature_Conversion
 *   Std_ReturnType Rte_Write_BsConst_PWM_boost_bypass_duty_Value(uint8 data)
 *   Std_ReturnType Rte_Write_BsConst_PWM_boost_bypass_duty_SafeCopy1_Value(uint8 data)
 *   Std_ReturnType Rte_Write_BsConst_PWM_boost_bypass_duty_SafeCopy2_Value(uint8 data)
 *   Std_ReturnType Rte_Write_BsConst_PowerGauge_Element_Value(const Rte_DT_Arr_u8_64_0 *data)
 *     Argument data: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *   Std_ReturnType Rte_Write_BsConst_Power_Element_Value(const Rte_DT_Arr_u8_32_0 *data)
 *     Argument data: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *   Std_ReturnType Rte_Write_BsConst_RealTimeClock_Element_Value(const Rte_DT_Arr_u8_48_0 *data)
 *     Argument data: Rte_DT_Arr_u8_48_0* is of type Arr_u8_48
 *   Std_ReturnType Rte_Write_BsConst_ServiceReminder_Element_Value(const Rte_DT_Arr_u8_48_0 *data)
 *     Argument data: Rte_DT_Arr_u8_48_0* is of type Arr_u8_48
 *   Std_ReturnType Rte_Write_BsConst_SpeedoGauge_Element_Value(const Rte_DT_Arr_u8_64_0 *data)
 *     Argument data: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *   Std_ReturnType Rte_Write_BsConst_TachoGauge_Element_Value(const Rte_DT_Arr_u8_64_0 *data)
 *     Argument data: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *   Std_ReturnType Rte_Write_BsConst_TempGauge_Element_Value(const Rte_DT_Arr_u8_64_0 *data)
 *     Argument data: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *   Std_ReturnType Rte_Write_BsConst_Temp_Threshold_Hysteresis_Derating_Value(uint8 data)
 *   Std_ReturnType Rte_Write_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1_Value(uint8 data)
 *   Std_ReturnType Rte_Write_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2_Value(uint8 data)
 *   Std_ReturnType Rte_Write_BsConst_Temperature_Sensor_Conv_Value(const Rte_DT_T_NV_Temperature_Conversion_0 *data)
 *     Argument data: Rte_DT_T_NV_Temperature_Conversion_0* is of type T_NV_Temperature_Conversion
 *   Std_ReturnType Rte_Write_BsConst_Temperature_Sensor_Conv_SafeCopy1_Value(const Rte_DT_T_NV_Temperature_Conversion_0 *data)
 *     Argument data: Rte_DT_T_NV_Temperature_Conversion_0* is of type T_NV_Temperature_Conversion
 *   Std_ReturnType Rte_Write_BsConst_Temperature_Sensor_Conv_SafeCopy2_Value(const Rte_DT_T_NV_Temperature_Conversion_0 *data)
 *     Argument data: Rte_DT_T_NV_Temperature_Conversion_0* is of type T_NV_Temperature_Conversion
 *   Std_ReturnType Rte_Write_BsConst_TripComputer_Element_Value(const Rte_DT_Arr_u8_64_0 *data)
 *     Argument data: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *   Std_ReturnType Rte_Write_BsConst_Warning_Element_Value(const Rte_DT_Arr_u8_64_0 *data)
 *     Argument data: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *   Std_ReturnType Rte_Write_BsCys_Certicificate_Element_Value(const Rte_DT_Arr_u8_64_0 *data)
 *     Argument data: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *   Std_ReturnType Rte_Write_BsDiag_Dtc_Element_Value(const Rte_DT_Arr_u8_2048_0 *data)
 *     Argument data: Rte_DT_Arr_u8_2048_0* is of type Arr_u8_2048
 *   Std_ReturnType Rte_Write_BsDiag_ErrorRecord_Element_Value(const Rte_DT_Arr_u8_1024_0 *data)
 *     Argument data: Rte_DT_Arr_u8_1024_0* is of type Arr_u8_1024
 *   Std_ReturnType Rte_Write_BsReten_Audio_Element_Value(const Rte_DT_Arr_u8_100_0 *data)
 *     Argument data: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *   Std_ReturnType Rte_Write_BsReten_Communication_Element_Value(const Rte_DT_Arr_u8_100_0 *data)
 *     Argument data: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *   Std_ReturnType Rte_Write_BsReten_Display_Element_Value(const Rte_DT_Arr_u8_100_0 *data)
 *     Argument data: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *   Std_ReturnType Rte_Write_BsReten_Gauges_Element_Value(const Rte_DT_Arr_u8_100_0 *data)
 *     Argument data: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *   Std_ReturnType Rte_Write_BsReten_Illumination_Element_Value(const Rte_DT_Arr_u8_100_0 *data)
 *     Argument data: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *   Std_ReturnType Rte_Write_BsReten_Odometer_Element_Value(const Rte_DT_Arr_u8_100_0 *data)
 *     Argument data: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *   Std_ReturnType Rte_Write_BsReten_Personalization_Element_Value(const Rte_DT_Arr_u8_100_0 *data)
 *     Argument data: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *   Std_ReturnType Rte_Write_BsReten_Power_Element_Value(const Rte_DT_Arr_u8_100_0 *data)
 *     Argument data: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *   Std_ReturnType Rte_Write_BsReten_RealTimeClock_Element_Value(const Rte_DT_Arr_u8_100_0 *data)
 *     Argument data: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *   Std_ReturnType Rte_Write_BsReten_Tripcomputer_Element_Value(const Rte_DT_Arr_u8_100_0 *data)
 *     Argument data: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *   Std_ReturnType Rte_Write_BsReten_Warning_Element_Value(const Rte_DT_Arr_u8_100_0 *data)
 *     Argument data: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *   Std_ReturnType Rte_Write_BsRt_CusDlt_Element_Value(const Rte_DT_Arr_u8_128_0 *data)
 *     Argument data: Rte_DT_Arr_u8_128_0* is of type Arr_u8_128
 *   Std_ReturnType Rte_Write_BsRt_FuelGauge_Element_Value(const Rte_DT_Arr_u8_32_0 *data)
 *     Argument data: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *   Std_ReturnType Rte_Write_BsRt_Illumination_Element_Value(const Rte_DT_Arr_u8_100_0 *data)
 *     Argument data: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *   Std_ReturnType Rte_Write_BsRt_Odometer_Element_Value(const Rte_DT_Arr_u8_128_0 *data)
 *     Argument data: Rte_DT_Arr_u8_128_0* is of type Arr_u8_128
 *   Std_ReturnType Rte_Write_BsRt_OilGauge_Element_Value(const Rte_DT_Arr_u8_8_0 *data)
 *     Argument data: Rte_DT_Arr_u8_8_0* is of type Arr_u8_8
 *   Std_ReturnType Rte_Write_BsRt_Personalization_Element_Value(const Rte_DT_Arr_u8_128_0 *data)
 *     Argument data: Rte_DT_Arr_u8_128_0* is of type Arr_u8_128
 *   Std_ReturnType Rte_Write_BsRt_PowerGauge_Element_Value(const Rte_DT_Arr_u8_32_0 *data)
 *     Argument data: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *   Std_ReturnType Rte_Write_BsRt_RealTimeClock_Element_Value(const Rte_DT_Arr_u8_48_0 *data)
 *     Argument data: Rte_DT_Arr_u8_48_0* is of type Arr_u8_48
 *   Std_ReturnType Rte_Write_BsRt_SpeedoGauge_Element_Value(const Rte_DT_Arr_u8_8_0 *data)
 *     Argument data: Rte_DT_Arr_u8_8_0* is of type Arr_u8_8
 *   Std_ReturnType Rte_Write_BsRt_TachoGauge_Element_Value(const Rte_DT_Arr_u8_16_0 *data)
 *     Argument data: Rte_DT_Arr_u8_16_0* is of type Arr_u8_16
 *   Std_ReturnType Rte_Write_BsRt_TempGauge_Element_Value(const Rte_DT_Arr_u8_32_0 *data)
 *     Argument data: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *   Std_ReturnType Rte_Write_BsRt_TripComputer_Element_Value(const Rte_DT_Arr_u8_64_0 *data)
 *     Argument data: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *   Std_ReturnType Rte_Write_BsRt_Warning_Element_Value(const Rte_DT_Arr_u8_32_0 *data)
 *     Argument data: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *   Std_ReturnType Rte_Write_BsShare_AssemblyManufacturingDate_Value(const Rte_DT_Arr_u8_3_0 *data)
 *     Argument data: Rte_DT_Arr_u8_3_0* is of type Arr_u8_3
 *   Std_ReturnType Rte_Write_BsShare_AssemblyPlantNumber_Value(const Rte_DT_Arr_u8_3_0 *data)
 *     Argument data: Rte_DT_Arr_u8_3_0* is of type Arr_u8_3
 *   Std_ReturnType Rte_Write_BsShare_EcuPartNumber_Element_Value(const Rte_DT_Arr_u8_61_0 *data)
 *     Argument data: Rte_DT_Arr_u8_61_0* is of type Arr_u8_61
 *   Std_ReturnType Rte_Write_BsShare_HWModification_Value(uint16 data)
 *   Std_ReturnType Rte_Write_BsShare_PCBSerialNumber_Value(const Rte_DT_Arr_u8_9_0 *data)
 *     Argument data: Rte_DT_Arr_u8_9_0* is of type Arr_u8_9
 *   Std_ReturnType Rte_Write_BsShare_ProductSerialNumber_Value(const Rte_DT_Arr_u8_10_0 *data)
 *     Argument data: Rte_DT_Arr_u8_10_0* is of type Arr_u8_10
 *   Std_ReturnType Rte_Write_BsShare_SMTManufacturingDate_Value(const Rte_DT_Arr_u8_3_0 *data)
 *     Argument data: Rte_DT_Arr_u8_3_0* is of type Arr_u8_3
 *   Std_ReturnType Rte_Write_BsShare_SMTPlantNumber_Value(const Rte_DT_Arr_u8_3_0 *data)
 *     Argument data: Rte_DT_Arr_u8_3_0* is of type Arr_u8_3
 *   Std_ReturnType Rte_Write_BsShare_SwUpdFotaFinPrint_Element_Value(const Rte_DT_Arr_u8_32_0 *data)
 *     Argument data: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *   Std_ReturnType Rte_Write_BsShare_SwUpdFotaMode_Element_Value(const Rte_DT_Arr_u8_16_0 *data)
 *     Argument data: Rte_DT_Arr_u8_16_0* is of type Arr_u8_16
 *   Std_ReturnType Rte_Write_BsShare_SwUpdFotaStatus_Element_Value(const Rte_DT_Arr_u8_48_0 *data)
 *     Argument data: Rte_DT_Arr_u8_48_0* is of type Arr_u8_48
 *   Std_ReturnType Rte_Write_BsShare_SwUpdFotadecrypt_Element_Value(const Rte_DT_Arr_u8_64_0 *data)
 *     Argument data: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *   Std_ReturnType Rte_Write_BsShare_SwUpdReflash_Element_Value(const Rte_DT_Arr_u8_8_0 *data)
 *     Argument data: Rte_DT_Arr_u8_8_0* is of type Arr_u8_8
 *   Std_ReturnType Rte_Write_BsShare_VehicleConfig_Element_Value(const Rte_DT_Arr_u8_256_0 *data)
 *     Argument data: Rte_DT_Arr_u8_256_0* is of type Arr_u8_256
 *   Std_ReturnType Rte_Write_BsShare_VisMeet_EOLEntry_Element_Value(uint16 data)
 *   Std_ReturnType Rte_Write_BsShare_VisMeet_Element_Value(const Rte_DT_Arr_u8_46_0 *data)
 *     Argument data: Rte_DT_Arr_u8_46_0* is of type Arr_u8_46
 *   Std_ReturnType Rte_Write_BsShare_VisteonPCBPartNumber_Value(const Rte_DT_Arr_u8_17_0 *data)
 *     Argument data: Rte_DT_Arr_u8_17_0* is of type Arr_u8_17
 *   Std_ReturnType Rte_Write_BsShare_VisteonPartNumber_Value(const Rte_DT_Arr_u8_17_0 *data)
 *     Argument data: Rte_DT_Arr_u8_17_0* is of type Arr_u8_17
 *   Std_ReturnType Rte_Write_RefCys_Certicificate1_Element_Value(const Rte_DT_Arr_u8_64_0 *data)
 *     Argument data: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *   Std_ReturnType Rte_Write_RefCys_Certicificate_Element_Value(const Rte_DT_Arr_u8_64_0 *data)
 *     Argument data: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstract_MainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractStub_CODE) MemAbstract_MainFunction(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstract_MainFunction
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  Arr_u8_128 Read_BsConst_Audio_Element_Value;
  Arr_u8_28 Read_BsConst_BsConst_Illumination_ReservedByte_Value;
  Arr_u8_28 Read_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1_Value;
  Arr_u8_28 Read_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2_Value;
  Arr_u8_64 Read_BsConst_Communication_Element_Value;
  uint32 Read_BsConst_Compensation_Line_Shift_b_Value;
  uint32 Read_BsConst_Compensation_Line_Shift_b_SafeCopy1_Value;
  uint32 Read_BsConst_Compensation_Line_Shift_b_SafeCopy2_Value;
  uint32 Read_BsConst_Compensation_Line_Slope_m_Value;
  uint32 Read_BsConst_Compensation_Line_Slope_m_SafeCopy1_Value;
  uint32 Read_BsConst_Compensation_Line_Slope_m_SafeCopy2_Value;
  uint8 Read_BsConst_Derating_Backlight_Disable_Value;
  uint8 Read_BsConst_Derating_Backlight_Disable_SafeCopy1_Value;
  uint8 Read_BsConst_Derating_Backlight_Disable_SafeCopy2_Value;
  uint16 Read_BsConst_Display_Illum_Max_Level_Value;
  uint16 Read_BsConst_Display_Illum_Max_Level_SafeCopy1_Value;
  uint16 Read_BsConst_Display_Illum_Max_Level_SafeCopy2_Value;
  Arr_u8_32 Read_BsConst_EngOffTimer_Element_Value;
  Arr_u8_128 Read_BsConst_FuelGauge_Element_Value;
  Arr_u16_7 Read_BsConst_Lookup_Curve_HotSpot_Coef_X_Value;
  Arr_u16_7 Read_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1_Value;
  Arr_u16_7 Read_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2_Value;
  Arr_u16_7 Read_BsConst_Lookup_Curve_HotSpot_Coef_Y_Value;
  Arr_u16_7 Read_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1_Value;
  Arr_u16_7 Read_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2_Value;
  Arr_u8_64 Read_BsConst_OilGauge_Element_Value;
  T_NV_Temperature_Conversion Read_BsConst_PCB_Temperature_Sensor_Conv_Value;
  T_NV_Temperature_Conversion Read_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1_Value;
  T_NV_Temperature_Conversion Read_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2_Value;
  uint8 Read_BsConst_PWM_boost_bypass_duty_Value;
  uint8 Read_BsConst_PWM_boost_bypass_duty_SafeCopy1_Value;
  uint8 Read_BsConst_PWM_boost_bypass_duty_SafeCopy2_Value;
  Arr_u8_64 Read_BsConst_PowerGauge_Element_Value;
  Arr_u8_32 Read_BsConst_Power_Element_Value;
  Arr_u8_48 Read_BsConst_RealTimeClock_Element_Value;
  Arr_u8_48 Read_BsConst_ServiceReminder_Element_Value;
  Arr_u8_64 Read_BsConst_SpeedoGauge_Element_Value;
  Arr_u8_64 Read_BsConst_TachoGauge_Element_Value;
  Arr_u8_64 Read_BsConst_TempGauge_Element_Value;
  uint8 Read_BsConst_Temp_Threshold_Hysteresis_Derating_Value;
  uint8 Read_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1_Value;
  uint8 Read_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2_Value;
  T_NV_Temperature_Conversion Read_BsConst_Temperature_Sensor_Conv_Value;
  T_NV_Temperature_Conversion Read_BsConst_Temperature_Sensor_Conv_SafeCopy1_Value;
  T_NV_Temperature_Conversion Read_BsConst_Temperature_Sensor_Conv_SafeCopy2_Value;
  Arr_u8_64 Read_BsConst_TripComputer_Element_Value;
  Arr_u8_64 Read_BsConst_Warning_Element_Value;
  Arr_u8_64 Read_BsCys_Certicificate_Element_Value;
  Arr_u8_2048 Read_BsDiag_Dtc_Element_Value;
  Arr_u8_1024 Read_BsDiag_ErrorRecord_Element_Value;
  Arr_u8_100 Read_BsReten_Audio_Element_Value;
  Arr_u8_100 Read_BsReten_Communication_Element_Value;
  Arr_u8_100 Read_BsReten_Display_Element_Value;
  Arr_u8_100 Read_BsReten_Gauges_Element_Value;
  Arr_u8_100 Read_BsReten_Illumination_Element_Value;
  Arr_u8_100 Read_BsReten_Odometer_Element_Value;
  Arr_u8_100 Read_BsReten_Personalization_Element_Value;
  Arr_u8_100 Read_BsReten_Power_Element_Value;
  Arr_u8_100 Read_BsReten_RealTimeClock_Element_Value;
  Arr_u8_100 Read_BsReten_Tripcomputer_Element_Value;
  Arr_u8_100 Read_BsReten_Warning_Element_Value;
  Arr_u8_128 Read_BsRt_CusDlt_Element_Value;
  Arr_u8_32 Read_BsRt_FuelGauge_Element_Value;
  Arr_u8_100 Read_BsRt_Illumination_Element_Value;
  Arr_u8_128 Read_BsRt_Odometer_Element_Value;
  Arr_u8_8 Read_BsRt_OilGauge_Element_Value;
  Arr_u8_128 Read_BsRt_Personalization_Element_Value;
  Arr_u8_32 Read_BsRt_PowerGauge_Element_Value;
  Arr_u8_48 Read_BsRt_RealTimeClock_Element_Value;
  Arr_u8_8 Read_BsRt_SpeedoGauge_Element_Value;
  Arr_u8_16 Read_BsRt_TachoGauge_Element_Value;
  Arr_u8_32 Read_BsRt_TempGauge_Element_Value;
  Arr_u8_64 Read_BsRt_TripComputer_Element_Value;
  Arr_u8_32 Read_BsRt_Warning_Element_Value;
  Arr_u8_3 Read_BsShare_AssemblyManufacturingDate_Value;
  Arr_u8_3 Read_BsShare_AssemblyPlantNumber_Value;
  Arr_u8_61 Read_BsShare_EcuPartNumber_Element_Value;
  uint16 Read_BsShare_HWModification_Value;
  Arr_u8_9 Read_BsShare_PCBSerialNumber_Value;
  Arr_u8_10 Read_BsShare_ProductSerialNumber_Value;
  Arr_u8_3 Read_BsShare_SMTManufacturingDate_Value;
  Arr_u8_3 Read_BsShare_SMTPlantNumber_Value;
  Arr_u8_32 Read_BsShare_SwUpdFotaFinPrint_Element_Value;
  Arr_u8_16 Read_BsShare_SwUpdFotaMode_Element_Value;
  Arr_u8_48 Read_BsShare_SwUpdFotaStatus_Element_Value;
  Arr_u8_64 Read_BsShare_SwUpdFotadecrypt_Element_Value;
  Arr_u8_8 Read_BsShare_SwUpdReflash_Element_Value;
  Arr_u8_256 Read_BsShare_VehicleConfig_Element_Value;
  uint16 Read_BsShare_VisMeet_EOLEntry_Element_Value;
  Arr_u8_46 Read_BsShare_VisMeet_Element_Value;
  Arr_u8_17 Read_BsShare_VisteonPCBPartNumber_Value;
  Arr_u8_17 Read_BsShare_VisteonPartNumber_Value;
  Arr_u8_64 Read_RefCys_Certicificate1_Element_Value;
  Arr_u8_64 Read_RefCys_Certicificate_Element_Value;

  Arr_u8_128 Write_BsConst_Audio_Element_Value;
  Arr_u8_28 Write_BsConst_BsConst_Illumination_ReservedByte_Value;
  Arr_u8_28 Write_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1_Value;
  Arr_u8_28 Write_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2_Value;
  Arr_u8_64 Write_BsConst_Communication_Element_Value;
  Arr_u8_32 Write_BsConst_EngOffTimer_Element_Value;
  Arr_u8_128 Write_BsConst_FuelGauge_Element_Value;
  Arr_u16_7 Write_BsConst_Lookup_Curve_HotSpot_Coef_X_Value;
  Arr_u16_7 Write_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1_Value;
  Arr_u16_7 Write_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2_Value;
  Arr_u16_7 Write_BsConst_Lookup_Curve_HotSpot_Coef_Y_Value;
  Arr_u16_7 Write_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1_Value;
  Arr_u16_7 Write_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2_Value;
  Arr_u8_64 Write_BsConst_OilGauge_Element_Value;
  T_NV_Temperature_Conversion Write_BsConst_PCB_Temperature_Sensor_Conv_Value;
  T_NV_Temperature_Conversion Write_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1_Value;
  T_NV_Temperature_Conversion Write_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2_Value;
  Arr_u8_64 Write_BsConst_PowerGauge_Element_Value;
  Arr_u8_32 Write_BsConst_Power_Element_Value;
  Arr_u8_48 Write_BsConst_RealTimeClock_Element_Value;
  Arr_u8_48 Write_BsConst_ServiceReminder_Element_Value;
  Arr_u8_64 Write_BsConst_SpeedoGauge_Element_Value;
  Arr_u8_64 Write_BsConst_TachoGauge_Element_Value;
  Arr_u8_64 Write_BsConst_TempGauge_Element_Value;
  T_NV_Temperature_Conversion Write_BsConst_Temperature_Sensor_Conv_Value;
  T_NV_Temperature_Conversion Write_BsConst_Temperature_Sensor_Conv_SafeCopy1_Value;
  T_NV_Temperature_Conversion Write_BsConst_Temperature_Sensor_Conv_SafeCopy2_Value;
  Arr_u8_64 Write_BsConst_TripComputer_Element_Value;
  Arr_u8_64 Write_BsConst_Warning_Element_Value;
  Arr_u8_64 Write_BsCys_Certicificate_Element_Value;
  Arr_u8_2048 Write_BsDiag_Dtc_Element_Value;
  Arr_u8_1024 Write_BsDiag_ErrorRecord_Element_Value;
  Arr_u8_100 Write_BsReten_Audio_Element_Value;
  Arr_u8_100 Write_BsReten_Communication_Element_Value;
  Arr_u8_100 Write_BsReten_Display_Element_Value;
  Arr_u8_100 Write_BsReten_Gauges_Element_Value;
  Arr_u8_100 Write_BsReten_Illumination_Element_Value;
  Arr_u8_100 Write_BsReten_Odometer_Element_Value;
  Arr_u8_100 Write_BsReten_Personalization_Element_Value;
  Arr_u8_100 Write_BsReten_Power_Element_Value;
  Arr_u8_100 Write_BsReten_RealTimeClock_Element_Value;
  Arr_u8_100 Write_BsReten_Tripcomputer_Element_Value;
  Arr_u8_100 Write_BsReten_Warning_Element_Value;
  Arr_u8_128 Write_BsRt_CusDlt_Element_Value;
  Arr_u8_32 Write_BsRt_FuelGauge_Element_Value;
  Arr_u8_100 Write_BsRt_Illumination_Element_Value;
  Arr_u8_128 Write_BsRt_Odometer_Element_Value;
  Arr_u8_8 Write_BsRt_OilGauge_Element_Value;
  Arr_u8_128 Write_BsRt_Personalization_Element_Value;
  Arr_u8_32 Write_BsRt_PowerGauge_Element_Value;
  Arr_u8_48 Write_BsRt_RealTimeClock_Element_Value;
  Arr_u8_8 Write_BsRt_SpeedoGauge_Element_Value;
  Arr_u8_16 Write_BsRt_TachoGauge_Element_Value;
  Arr_u8_32 Write_BsRt_TempGauge_Element_Value;
  Arr_u8_64 Write_BsRt_TripComputer_Element_Value;
  Arr_u8_32 Write_BsRt_Warning_Element_Value;
  Arr_u8_3 Write_BsShare_AssemblyManufacturingDate_Value;
  Arr_u8_3 Write_BsShare_AssemblyPlantNumber_Value;
  Arr_u8_61 Write_BsShare_EcuPartNumber_Element_Value;
  Arr_u8_9 Write_BsShare_PCBSerialNumber_Value;
  Arr_u8_10 Write_BsShare_ProductSerialNumber_Value;
  Arr_u8_3 Write_BsShare_SMTManufacturingDate_Value;
  Arr_u8_3 Write_BsShare_SMTPlantNumber_Value;
  Arr_u8_32 Write_BsShare_SwUpdFotaFinPrint_Element_Value;
  Arr_u8_16 Write_BsShare_SwUpdFotaMode_Element_Value;
  Arr_u8_48 Write_BsShare_SwUpdFotaStatus_Element_Value;
  Arr_u8_64 Write_BsShare_SwUpdFotadecrypt_Element_Value;
  Arr_u8_8 Write_BsShare_SwUpdReflash_Element_Value;
  Arr_u8_256 Write_BsShare_VehicleConfig_Element_Value;
  Arr_u8_46 Write_BsShare_VisMeet_Element_Value;
  Arr_u8_17 Write_BsShare_VisteonPCBPartNumber_Value;
  Arr_u8_17 Write_BsShare_VisteonPartNumber_Value;
  Arr_u8_64 Write_RefCys_Certicificate1_Element_Value;
  Arr_u8_64 Write_RefCys_Certicificate_Element_Value;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_MemAbstractStub_Rte_Read_BsConst_Audio_Element_Value(Read_BsConst_Audio_Element_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsConst_BsConst_Illumination_ReservedByte_Value(Read_BsConst_BsConst_Illumination_ReservedByte_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1_Value(Read_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2_Value(Read_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsConst_Communication_Element_Value(Read_BsConst_Communication_Element_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsConst_Compensation_Line_Shift_b_Value(&Read_BsConst_Compensation_Line_Shift_b_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsConst_Compensation_Line_Shift_b_SafeCopy1_Value(&Read_BsConst_Compensation_Line_Shift_b_SafeCopy1_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsConst_Compensation_Line_Shift_b_SafeCopy2_Value(&Read_BsConst_Compensation_Line_Shift_b_SafeCopy2_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsConst_Compensation_Line_Slope_m_Value(&Read_BsConst_Compensation_Line_Slope_m_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsConst_Compensation_Line_Slope_m_SafeCopy1_Value(&Read_BsConst_Compensation_Line_Slope_m_SafeCopy1_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsConst_Compensation_Line_Slope_m_SafeCopy2_Value(&Read_BsConst_Compensation_Line_Slope_m_SafeCopy2_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsConst_Derating_Backlight_Disable_Value(&Read_BsConst_Derating_Backlight_Disable_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsConst_Derating_Backlight_Disable_SafeCopy1_Value(&Read_BsConst_Derating_Backlight_Disable_SafeCopy1_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsConst_Derating_Backlight_Disable_SafeCopy2_Value(&Read_BsConst_Derating_Backlight_Disable_SafeCopy2_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsConst_Display_Illum_Max_Level_Value(&Read_BsConst_Display_Illum_Max_Level_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsConst_Display_Illum_Max_Level_SafeCopy1_Value(&Read_BsConst_Display_Illum_Max_Level_SafeCopy1_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsConst_Display_Illum_Max_Level_SafeCopy2_Value(&Read_BsConst_Display_Illum_Max_Level_SafeCopy2_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsConst_EngOffTimer_Element_Value(Read_BsConst_EngOffTimer_Element_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsConst_FuelGauge_Element_Value(Read_BsConst_FuelGauge_Element_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsConst_Lookup_Curve_HotSpot_Coef_X_Value(Read_BsConst_Lookup_Curve_HotSpot_Coef_X_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1_Value(Read_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2_Value(Read_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsConst_Lookup_Curve_HotSpot_Coef_Y_Value(Read_BsConst_Lookup_Curve_HotSpot_Coef_Y_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1_Value(Read_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2_Value(Read_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsConst_OilGauge_Element_Value(Read_BsConst_OilGauge_Element_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsConst_PCB_Temperature_Sensor_Conv_Value(Read_BsConst_PCB_Temperature_Sensor_Conv_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1_Value(Read_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2_Value(Read_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsConst_PWM_boost_bypass_duty_Value(&Read_BsConst_PWM_boost_bypass_duty_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsConst_PWM_boost_bypass_duty_SafeCopy1_Value(&Read_BsConst_PWM_boost_bypass_duty_SafeCopy1_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsConst_PWM_boost_bypass_duty_SafeCopy2_Value(&Read_BsConst_PWM_boost_bypass_duty_SafeCopy2_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsConst_PowerGauge_Element_Value(Read_BsConst_PowerGauge_Element_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsConst_Power_Element_Value(Read_BsConst_Power_Element_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsConst_RealTimeClock_Element_Value(Read_BsConst_RealTimeClock_Element_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsConst_ServiceReminder_Element_Value(Read_BsConst_ServiceReminder_Element_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsConst_SpeedoGauge_Element_Value(Read_BsConst_SpeedoGauge_Element_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsConst_TachoGauge_Element_Value(Read_BsConst_TachoGauge_Element_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsConst_TempGauge_Element_Value(Read_BsConst_TempGauge_Element_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsConst_Temp_Threshold_Hysteresis_Derating_Value(&Read_BsConst_Temp_Threshold_Hysteresis_Derating_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1_Value(&Read_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2_Value(&Read_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsConst_Temperature_Sensor_Conv_Value(Read_BsConst_Temperature_Sensor_Conv_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsConst_Temperature_Sensor_Conv_SafeCopy1_Value(Read_BsConst_Temperature_Sensor_Conv_SafeCopy1_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsConst_Temperature_Sensor_Conv_SafeCopy2_Value(Read_BsConst_Temperature_Sensor_Conv_SafeCopy2_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsConst_TripComputer_Element_Value(Read_BsConst_TripComputer_Element_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsConst_Warning_Element_Value(Read_BsConst_Warning_Element_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsCys_Certicificate_Element_Value(Read_BsCys_Certicificate_Element_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsDiag_Dtc_Element_Value(Read_BsDiag_Dtc_Element_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsDiag_ErrorRecord_Element_Value(Read_BsDiag_ErrorRecord_Element_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsReten_Audio_Element_Value(Read_BsReten_Audio_Element_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsReten_Communication_Element_Value(Read_BsReten_Communication_Element_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsReten_Display_Element_Value(Read_BsReten_Display_Element_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsReten_Gauges_Element_Value(Read_BsReten_Gauges_Element_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsReten_Illumination_Element_Value(Read_BsReten_Illumination_Element_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsReten_Odometer_Element_Value(Read_BsReten_Odometer_Element_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsReten_Personalization_Element_Value(Read_BsReten_Personalization_Element_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsReten_Power_Element_Value(Read_BsReten_Power_Element_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsReten_RealTimeClock_Element_Value(Read_BsReten_RealTimeClock_Element_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsReten_Tripcomputer_Element_Value(Read_BsReten_Tripcomputer_Element_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsReten_Warning_Element_Value(Read_BsReten_Warning_Element_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsRt_CusDlt_Element_Value(Read_BsRt_CusDlt_Element_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsRt_FuelGauge_Element_Value(Read_BsRt_FuelGauge_Element_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsRt_Illumination_Element_Value(Read_BsRt_Illumination_Element_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsRt_Odometer_Element_Value(Read_BsRt_Odometer_Element_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsRt_OilGauge_Element_Value(Read_BsRt_OilGauge_Element_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsRt_Personalization_Element_Value(Read_BsRt_Personalization_Element_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsRt_PowerGauge_Element_Value(Read_BsRt_PowerGauge_Element_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsRt_RealTimeClock_Element_Value(Read_BsRt_RealTimeClock_Element_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsRt_SpeedoGauge_Element_Value(Read_BsRt_SpeedoGauge_Element_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsRt_TachoGauge_Element_Value(Read_BsRt_TachoGauge_Element_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsRt_TempGauge_Element_Value(Read_BsRt_TempGauge_Element_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsRt_TripComputer_Element_Value(Read_BsRt_TripComputer_Element_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsRt_Warning_Element_Value(Read_BsRt_Warning_Element_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsShare_AssemblyManufacturingDate_Value(Read_BsShare_AssemblyManufacturingDate_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsShare_AssemblyPlantNumber_Value(Read_BsShare_AssemblyPlantNumber_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsShare_EcuPartNumber_Element_Value(Read_BsShare_EcuPartNumber_Element_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsShare_HWModification_Value(&Read_BsShare_HWModification_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsShare_PCBSerialNumber_Value(Read_BsShare_PCBSerialNumber_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsShare_ProductSerialNumber_Value(Read_BsShare_ProductSerialNumber_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsShare_SMTManufacturingDate_Value(Read_BsShare_SMTManufacturingDate_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsShare_SMTPlantNumber_Value(Read_BsShare_SMTPlantNumber_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsShare_SwUpdFotaFinPrint_Element_Value(Read_BsShare_SwUpdFotaFinPrint_Element_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsShare_SwUpdFotaMode_Element_Value(Read_BsShare_SwUpdFotaMode_Element_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsShare_SwUpdFotaStatus_Element_Value(Read_BsShare_SwUpdFotaStatus_Element_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsShare_SwUpdFotadecrypt_Element_Value(Read_BsShare_SwUpdFotadecrypt_Element_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsShare_SwUpdReflash_Element_Value(Read_BsShare_SwUpdReflash_Element_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsShare_VehicleConfig_Element_Value(Read_BsShare_VehicleConfig_Element_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsShare_VisMeet_EOLEntry_Element_Value(&Read_BsShare_VisMeet_EOLEntry_Element_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsShare_VisMeet_Element_Value(Read_BsShare_VisMeet_Element_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsShare_VisteonPCBPartNumber_Value(Read_BsShare_VisteonPCBPartNumber_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_BsShare_VisteonPartNumber_Value(Read_BsShare_VisteonPartNumber_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_RefCys_Certicificate1_Element_Value(Read_RefCys_Certicificate1_Element_Value);
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

  fct_status = TSC_MemAbstractStub_Rte_Read_RefCys_Certicificate_Element_Value(Read_RefCys_Certicificate_Element_Value);
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

  (void)memset(&Write_BsConst_Audio_Element_Value, 0, sizeof(Write_BsConst_Audio_Element_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsConst_Audio_Element_Value(Write_BsConst_Audio_Element_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsConst_BsConst_Illumination_ReservedByte_Value, 0, sizeof(Write_BsConst_BsConst_Illumination_ReservedByte_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsConst_BsConst_Illumination_ReservedByte_Value(Write_BsConst_BsConst_Illumination_ReservedByte_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1_Value, 0, sizeof(Write_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1_Value(Write_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2_Value, 0, sizeof(Write_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2_Value(Write_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsConst_Communication_Element_Value, 0, sizeof(Write_BsConst_Communication_Element_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsConst_Communication_Element_Value(Write_BsConst_Communication_Element_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractStub_Rte_Write_BsConst_Compensation_Line_Shift_b_Value(Rte_InitValue_BsConst_Compensation_Line_Shift_b_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractStub_Rte_Write_BsConst_Compensation_Line_Shift_b_SafeCopy1_Value(Rte_InitValue_BsConst_Compensation_Line_Shift_b_SafeCopy1_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractStub_Rte_Write_BsConst_Compensation_Line_Shift_b_SafeCopy2_Value(Rte_InitValue_BsConst_Compensation_Line_Shift_b_SafeCopy2_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractStub_Rte_Write_BsConst_Compensation_Line_Slope_m_Value(Rte_InitValue_BsConst_Compensation_Line_Slope_m_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractStub_Rte_Write_BsConst_Compensation_Line_Slope_m_SafeCopy1_Value(Rte_InitValue_BsConst_Compensation_Line_Slope_m_SafeCopy1_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractStub_Rte_Write_BsConst_Compensation_Line_Slope_m_SafeCopy2_Value(Rte_InitValue_BsConst_Compensation_Line_Slope_m_SafeCopy2_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractStub_Rte_Write_BsConst_Derating_Backlight_Disable_Value(Rte_InitValue_BsConst_Derating_Backlight_Disable_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractStub_Rte_Write_BsConst_Derating_Backlight_Disable_SafeCopy1_Value(Rte_InitValue_BsConst_Derating_Backlight_Disable_SafeCopy1_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractStub_Rte_Write_BsConst_Derating_Backlight_Disable_SafeCopy2_Value(Rte_InitValue_BsConst_Derating_Backlight_Disable_SafeCopy2_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractStub_Rte_Write_BsConst_Display_Illum_Max_Level_Value(Rte_InitValue_BsConst_Display_Illum_Max_Level_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractStub_Rte_Write_BsConst_Display_Illum_Max_Level_SafeCopy1_Value(Rte_InitValue_BsConst_Display_Illum_Max_Level_SafeCopy1_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractStub_Rte_Write_BsConst_Display_Illum_Max_Level_SafeCopy2_Value(Rte_InitValue_BsConst_Display_Illum_Max_Level_SafeCopy2_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsConst_EngOffTimer_Element_Value, 0, sizeof(Write_BsConst_EngOffTimer_Element_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsConst_EngOffTimer_Element_Value(Write_BsConst_EngOffTimer_Element_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsConst_FuelGauge_Element_Value, 0, sizeof(Write_BsConst_FuelGauge_Element_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsConst_FuelGauge_Element_Value(Write_BsConst_FuelGauge_Element_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsConst_Lookup_Curve_HotSpot_Coef_X_Value, 0, sizeof(Write_BsConst_Lookup_Curve_HotSpot_Coef_X_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsConst_Lookup_Curve_HotSpot_Coef_X_Value(Write_BsConst_Lookup_Curve_HotSpot_Coef_X_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1_Value, 0, sizeof(Write_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1_Value(Write_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2_Value, 0, sizeof(Write_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2_Value(Write_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsConst_Lookup_Curve_HotSpot_Coef_Y_Value, 0, sizeof(Write_BsConst_Lookup_Curve_HotSpot_Coef_Y_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsConst_Lookup_Curve_HotSpot_Coef_Y_Value(Write_BsConst_Lookup_Curve_HotSpot_Coef_Y_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1_Value, 0, sizeof(Write_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1_Value(Write_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2_Value, 0, sizeof(Write_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2_Value(Write_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsConst_OilGauge_Element_Value, 0, sizeof(Write_BsConst_OilGauge_Element_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsConst_OilGauge_Element_Value(Write_BsConst_OilGauge_Element_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsConst_PCB_Temperature_Sensor_Conv_Value, 0, sizeof(Write_BsConst_PCB_Temperature_Sensor_Conv_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsConst_PCB_Temperature_Sensor_Conv_Value(Write_BsConst_PCB_Temperature_Sensor_Conv_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1_Value, 0, sizeof(Write_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1_Value(Write_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2_Value, 0, sizeof(Write_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2_Value(Write_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractStub_Rte_Write_BsConst_PWM_boost_bypass_duty_Value(Rte_InitValue_BsConst_PWM_boost_bypass_duty_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractStub_Rte_Write_BsConst_PWM_boost_bypass_duty_SafeCopy1_Value(Rte_InitValue_BsConst_PWM_boost_bypass_duty_SafeCopy1_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractStub_Rte_Write_BsConst_PWM_boost_bypass_duty_SafeCopy2_Value(Rte_InitValue_BsConst_PWM_boost_bypass_duty_SafeCopy2_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsConst_PowerGauge_Element_Value, 0, sizeof(Write_BsConst_PowerGauge_Element_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsConst_PowerGauge_Element_Value(Write_BsConst_PowerGauge_Element_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsConst_Power_Element_Value, 0, sizeof(Write_BsConst_Power_Element_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsConst_Power_Element_Value(Write_BsConst_Power_Element_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsConst_RealTimeClock_Element_Value, 0, sizeof(Write_BsConst_RealTimeClock_Element_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsConst_RealTimeClock_Element_Value(Write_BsConst_RealTimeClock_Element_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsConst_ServiceReminder_Element_Value, 0, sizeof(Write_BsConst_ServiceReminder_Element_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsConst_ServiceReminder_Element_Value(Write_BsConst_ServiceReminder_Element_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsConst_SpeedoGauge_Element_Value, 0, sizeof(Write_BsConst_SpeedoGauge_Element_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsConst_SpeedoGauge_Element_Value(Write_BsConst_SpeedoGauge_Element_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsConst_TachoGauge_Element_Value, 0, sizeof(Write_BsConst_TachoGauge_Element_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsConst_TachoGauge_Element_Value(Write_BsConst_TachoGauge_Element_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsConst_TempGauge_Element_Value, 0, sizeof(Write_BsConst_TempGauge_Element_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsConst_TempGauge_Element_Value(Write_BsConst_TempGauge_Element_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractStub_Rte_Write_BsConst_Temp_Threshold_Hysteresis_Derating_Value(Rte_InitValue_BsConst_Temp_Threshold_Hysteresis_Derating_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractStub_Rte_Write_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1_Value(Rte_InitValue_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractStub_Rte_Write_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2_Value(Rte_InitValue_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsConst_Temperature_Sensor_Conv_Value, 0, sizeof(Write_BsConst_Temperature_Sensor_Conv_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsConst_Temperature_Sensor_Conv_Value(Write_BsConst_Temperature_Sensor_Conv_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsConst_Temperature_Sensor_Conv_SafeCopy1_Value, 0, sizeof(Write_BsConst_Temperature_Sensor_Conv_SafeCopy1_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsConst_Temperature_Sensor_Conv_SafeCopy1_Value(Write_BsConst_Temperature_Sensor_Conv_SafeCopy1_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsConst_Temperature_Sensor_Conv_SafeCopy2_Value, 0, sizeof(Write_BsConst_Temperature_Sensor_Conv_SafeCopy2_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsConst_Temperature_Sensor_Conv_SafeCopy2_Value(Write_BsConst_Temperature_Sensor_Conv_SafeCopy2_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsConst_TripComputer_Element_Value, 0, sizeof(Write_BsConst_TripComputer_Element_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsConst_TripComputer_Element_Value(Write_BsConst_TripComputer_Element_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsConst_Warning_Element_Value, 0, sizeof(Write_BsConst_Warning_Element_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsConst_Warning_Element_Value(Write_BsConst_Warning_Element_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsCys_Certicificate_Element_Value, 0, sizeof(Write_BsCys_Certicificate_Element_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsCys_Certicificate_Element_Value(Write_BsCys_Certicificate_Element_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsDiag_Dtc_Element_Value, 0, sizeof(Write_BsDiag_Dtc_Element_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsDiag_Dtc_Element_Value(Write_BsDiag_Dtc_Element_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsDiag_ErrorRecord_Element_Value, 0, sizeof(Write_BsDiag_ErrorRecord_Element_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsDiag_ErrorRecord_Element_Value(Write_BsDiag_ErrorRecord_Element_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsReten_Audio_Element_Value, 0, sizeof(Write_BsReten_Audio_Element_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsReten_Audio_Element_Value(Write_BsReten_Audio_Element_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsReten_Communication_Element_Value, 0, sizeof(Write_BsReten_Communication_Element_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsReten_Communication_Element_Value(Write_BsReten_Communication_Element_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsReten_Display_Element_Value, 0, sizeof(Write_BsReten_Display_Element_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsReten_Display_Element_Value(Write_BsReten_Display_Element_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsReten_Gauges_Element_Value, 0, sizeof(Write_BsReten_Gauges_Element_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsReten_Gauges_Element_Value(Write_BsReten_Gauges_Element_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsReten_Illumination_Element_Value, 0, sizeof(Write_BsReten_Illumination_Element_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsReten_Illumination_Element_Value(Write_BsReten_Illumination_Element_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsReten_Odometer_Element_Value, 0, sizeof(Write_BsReten_Odometer_Element_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsReten_Odometer_Element_Value(Write_BsReten_Odometer_Element_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsReten_Personalization_Element_Value, 0, sizeof(Write_BsReten_Personalization_Element_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsReten_Personalization_Element_Value(Write_BsReten_Personalization_Element_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsReten_Power_Element_Value, 0, sizeof(Write_BsReten_Power_Element_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsReten_Power_Element_Value(Write_BsReten_Power_Element_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsReten_RealTimeClock_Element_Value, 0, sizeof(Write_BsReten_RealTimeClock_Element_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsReten_RealTimeClock_Element_Value(Write_BsReten_RealTimeClock_Element_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsReten_Tripcomputer_Element_Value, 0, sizeof(Write_BsReten_Tripcomputer_Element_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsReten_Tripcomputer_Element_Value(Write_BsReten_Tripcomputer_Element_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsReten_Warning_Element_Value, 0, sizeof(Write_BsReten_Warning_Element_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsReten_Warning_Element_Value(Write_BsReten_Warning_Element_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsRt_CusDlt_Element_Value, 0, sizeof(Write_BsRt_CusDlt_Element_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsRt_CusDlt_Element_Value(Write_BsRt_CusDlt_Element_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsRt_FuelGauge_Element_Value, 0, sizeof(Write_BsRt_FuelGauge_Element_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsRt_FuelGauge_Element_Value(Write_BsRt_FuelGauge_Element_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsRt_Illumination_Element_Value, 0, sizeof(Write_BsRt_Illumination_Element_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsRt_Illumination_Element_Value(Write_BsRt_Illumination_Element_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsRt_Odometer_Element_Value, 0, sizeof(Write_BsRt_Odometer_Element_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsRt_Odometer_Element_Value(Write_BsRt_Odometer_Element_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsRt_OilGauge_Element_Value, 0, sizeof(Write_BsRt_OilGauge_Element_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsRt_OilGauge_Element_Value(Write_BsRt_OilGauge_Element_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsRt_Personalization_Element_Value, 0, sizeof(Write_BsRt_Personalization_Element_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsRt_Personalization_Element_Value(Write_BsRt_Personalization_Element_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsRt_PowerGauge_Element_Value, 0, sizeof(Write_BsRt_PowerGauge_Element_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsRt_PowerGauge_Element_Value(Write_BsRt_PowerGauge_Element_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsRt_RealTimeClock_Element_Value, 0, sizeof(Write_BsRt_RealTimeClock_Element_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsRt_RealTimeClock_Element_Value(Write_BsRt_RealTimeClock_Element_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsRt_SpeedoGauge_Element_Value, 0, sizeof(Write_BsRt_SpeedoGauge_Element_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsRt_SpeedoGauge_Element_Value(Write_BsRt_SpeedoGauge_Element_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsRt_TachoGauge_Element_Value, 0, sizeof(Write_BsRt_TachoGauge_Element_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsRt_TachoGauge_Element_Value(Write_BsRt_TachoGauge_Element_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsRt_TempGauge_Element_Value, 0, sizeof(Write_BsRt_TempGauge_Element_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsRt_TempGauge_Element_Value(Write_BsRt_TempGauge_Element_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsRt_TripComputer_Element_Value, 0, sizeof(Write_BsRt_TripComputer_Element_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsRt_TripComputer_Element_Value(Write_BsRt_TripComputer_Element_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsRt_Warning_Element_Value, 0, sizeof(Write_BsRt_Warning_Element_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsRt_Warning_Element_Value(Write_BsRt_Warning_Element_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsShare_AssemblyManufacturingDate_Value, 0, sizeof(Write_BsShare_AssemblyManufacturingDate_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsShare_AssemblyManufacturingDate_Value(Write_BsShare_AssemblyManufacturingDate_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsShare_AssemblyPlantNumber_Value, 0, sizeof(Write_BsShare_AssemblyPlantNumber_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsShare_AssemblyPlantNumber_Value(Write_BsShare_AssemblyPlantNumber_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsShare_EcuPartNumber_Element_Value, 0, sizeof(Write_BsShare_EcuPartNumber_Element_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsShare_EcuPartNumber_Element_Value(Write_BsShare_EcuPartNumber_Element_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractStub_Rte_Write_BsShare_HWModification_Value(Rte_InitValue_BsShare_HWModification_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsShare_PCBSerialNumber_Value, 0, sizeof(Write_BsShare_PCBSerialNumber_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsShare_PCBSerialNumber_Value(Write_BsShare_PCBSerialNumber_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsShare_ProductSerialNumber_Value, 0, sizeof(Write_BsShare_ProductSerialNumber_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsShare_ProductSerialNumber_Value(Write_BsShare_ProductSerialNumber_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsShare_SMTManufacturingDate_Value, 0, sizeof(Write_BsShare_SMTManufacturingDate_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsShare_SMTManufacturingDate_Value(Write_BsShare_SMTManufacturingDate_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsShare_SMTPlantNumber_Value, 0, sizeof(Write_BsShare_SMTPlantNumber_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsShare_SMTPlantNumber_Value(Write_BsShare_SMTPlantNumber_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsShare_SwUpdFotaFinPrint_Element_Value, 0, sizeof(Write_BsShare_SwUpdFotaFinPrint_Element_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsShare_SwUpdFotaFinPrint_Element_Value(Write_BsShare_SwUpdFotaFinPrint_Element_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsShare_SwUpdFotaMode_Element_Value, 0, sizeof(Write_BsShare_SwUpdFotaMode_Element_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsShare_SwUpdFotaMode_Element_Value(Write_BsShare_SwUpdFotaMode_Element_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsShare_SwUpdFotaStatus_Element_Value, 0, sizeof(Write_BsShare_SwUpdFotaStatus_Element_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsShare_SwUpdFotaStatus_Element_Value(Write_BsShare_SwUpdFotaStatus_Element_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsShare_SwUpdFotadecrypt_Element_Value, 0, sizeof(Write_BsShare_SwUpdFotadecrypt_Element_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsShare_SwUpdFotadecrypt_Element_Value(Write_BsShare_SwUpdFotadecrypt_Element_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsShare_SwUpdReflash_Element_Value, 0, sizeof(Write_BsShare_SwUpdReflash_Element_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsShare_SwUpdReflash_Element_Value(Write_BsShare_SwUpdReflash_Element_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsShare_VehicleConfig_Element_Value, 0, sizeof(Write_BsShare_VehicleConfig_Element_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsShare_VehicleConfig_Element_Value(Write_BsShare_VehicleConfig_Element_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractStub_Rte_Write_BsShare_VisMeet_EOLEntry_Element_Value(Rte_InitValue_BsShare_VisMeet_EOLEntry_Element_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsShare_VisMeet_Element_Value, 0, sizeof(Write_BsShare_VisMeet_Element_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsShare_VisMeet_Element_Value(Write_BsShare_VisMeet_Element_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsShare_VisteonPCBPartNumber_Value, 0, sizeof(Write_BsShare_VisteonPCBPartNumber_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsShare_VisteonPCBPartNumber_Value(Write_BsShare_VisteonPCBPartNumber_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsShare_VisteonPartNumber_Value, 0, sizeof(Write_BsShare_VisteonPartNumber_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_BsShare_VisteonPartNumber_Value(Write_BsShare_VisteonPartNumber_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_RefCys_Certicificate1_Element_Value, 0, sizeof(Write_RefCys_Certicificate1_Element_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_RefCys_Certicificate1_Element_Value(Write_RefCys_Certicificate1_Element_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_RefCys_Certicificate_Element_Value, 0, sizeof(Write_RefCys_Certicificate_Element_Value));
  fct_status = TSC_MemAbstractStub_Rte_Write_RefCys_Certicificate_Element_Value(Write_RefCys_Certicificate_Element_Value);
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


#define MemAbstractStub_STOP_SEC_CODE
#include "MemAbstractStub_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void MemAbstractStub_TestDefines(void)
{
  /* Enumeration Data Types */

  NvM_RequestResultType Test_NvM_RequestResultType_V_1 = NVM_REQ_OK;
  NvM_RequestResultType Test_NvM_RequestResultType_V_2 = NVM_REQ_NOT_OK;
  NvM_RequestResultType Test_NvM_RequestResultType_V_3 = NVM_REQ_PENDING;
  NvM_RequestResultType Test_NvM_RequestResultType_V_4 = NVM_REQ_INTEGRITY_FAILED;
  NvM_RequestResultType Test_NvM_RequestResultType_V_5 = NVM_REQ_BLOCK_SKIPPED;
  NvM_RequestResultType Test_NvM_RequestResultType_V_6 = NVM_REQ_NV_INVALIDATED;
  NvM_RequestResultType Test_NvM_RequestResultType_V_7 = NVM_REQ_CANCELED;
  NvM_RequestResultType Test_NvM_RequestResultType_V_8 = NVM_REQ_REDUNDANCY_FAILED;
  NvM_RequestResultType Test_NvM_RequestResultType_V_9 = NVM_REQ_RESTORED_FROM_ROM;

  NvM_ServiceIdType Test_NvM_ServiceIdType_V_1 = NVM_READ_BLOCK;
  NvM_ServiceIdType Test_NvM_ServiceIdType_V_2 = NVM_WRITE_BLOCK;
  NvM_ServiceIdType Test_NvM_ServiceIdType_V_3 = NVM_RESTORE_BLOCK_DEFAULTS;
  NvM_ServiceIdType Test_NvM_ServiceIdType_V_4 = NVM_ERASE_BLOCK;
  NvM_ServiceIdType Test_NvM_ServiceIdType_V_5 = NVM_INVALIDATE_NV_BLOCK;
  NvM_ServiceIdType Test_NvM_ServiceIdType_V_6 = NVM_READ_ALL;
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
