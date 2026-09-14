/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  NvM.c
 *        Config:  BMW.dpa
 *     SW-C Type:  NvM
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  C-Code implementation template for SW-C <NvM>
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
 * NvM_BlockIdType
 *   
 *
 * NvM_RequestResultType
 *   
 *
 * NvM_ServiceIdType
 *   
 *
 *********************************************************************************************************************/

#include "Rte_NvM.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_NvM.h"
#include "SchM_NvM.h"
#include "TSC_SchM_NvM.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"

static void NvM_TestDefines(void);

typedef P2FUNC(Std_ReturnType, RTE_CODE, FncPtrType)(void); /* PRQA S 3448 */ /* MD_Rte_TestCode */


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
 * NvM_BlockIdType: Integer in interval [1...32767]
 * boolean: Boolean (standard type)
 * dtRef_VOID: DataReference
 * dtRef_const_VOID: DataReference
 * uint16: Integer in interval [0...65535] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * NvM_RequestResultType: Enumeration of integer in interval [0...8] with enumerators
 *   NVM_REQ_OK (0U)
 *   NVM_REQ_NOT_OK (1U)
 *   NVM_REQ_PENDING (2U)
 *   NVM_REQ_INTEGRITY_FAILED (3U)
 *   NVM_REQ_BLOCK_SKIPPED (4U)
 *   NVM_REQ_NV_INVALIDATED (5U)
 *   NVM_REQ_CANCELED (6U)
 *   NVM_REQ_REDUNDANCY_FAILED (7U)
 *   NVM_REQ_RESTORED_FROM_ROM (8U)
 * NvM_ServiceIdType: Enumeration of integer in interval [6...12] with enumerators
 *   NVM_READ_BLOCK (6U)
 *   NVM_WRITE_BLOCK (7U)
 *   NVM_RESTORE_BLOCK_DEFAULTS (8U)
 *   NVM_ERASE_BLOCK (9U)
 *   NVM_INVALIDATE_NV_BLOCK (11U)
 *   NVM_READ_ALL (12U)
 *
 *********************************************************************************************************************/


#define NvM_START_SEC_CODE
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: EraseBlock
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Audio>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Communication>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_EngOffTimer>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_FuelGauge>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Illumination>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Illumination_Copy1>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Illumination_Copy2>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_OilGauge>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Power>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_PowerGauge>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_RealTimeClock>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_ServiceReminder>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_SpeedoGauge>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TachoGauge>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TempGauge>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TripComputer>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Warning>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsCys_Certicificate>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsDiag_Dtc>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsDiag_ErrorRecord>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Audio>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Communication>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Display>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Gauges>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Illumination>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Odometer>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Personalization>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Power>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_RealTimeClock>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Tripcomputer>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Warning>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_CusDlt>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_FuelGauge>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Illumination>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Odometer>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_OilGauge>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Personalization>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_PowerGauge>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_RealTimeClock>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_SpeedoGauge>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TachoGauge>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TempGauge>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TripComputer>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Warning>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_EcuPartNumber>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaFinPrint>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaMode>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaStatus>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotadecrypt>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdReflash>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_VehicleConfig>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_VisMeet>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_RefCys_Certicificate>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_RefCys_Certicificate1>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType NvM_EraseNvBlock(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_NvMService_AC3_SRBS_DS_Defs_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: EraseBlock_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, NvM_CODE) NvM_EraseNvBlock(NvM_BlockIdType parg0) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NvM_EraseNvBlock (returns application error)
 *********************************************************************************************************************/

  NvM_TestDefines();

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: GetDataIndex
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Audio>
 *   - triggered by server invocation for OperationPrototype <GetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Communication>
 *   - triggered by server invocation for OperationPrototype <GetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_EngOffTimer>
 *   - triggered by server invocation for OperationPrototype <GetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_FuelGauge>
 *   - triggered by server invocation for OperationPrototype <GetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Illumination>
 *   - triggered by server invocation for OperationPrototype <GetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Illumination_Copy1>
 *   - triggered by server invocation for OperationPrototype <GetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Illumination_Copy2>
 *   - triggered by server invocation for OperationPrototype <GetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_OilGauge>
 *   - triggered by server invocation for OperationPrototype <GetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Power>
 *   - triggered by server invocation for OperationPrototype <GetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_PowerGauge>
 *   - triggered by server invocation for OperationPrototype <GetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_RealTimeClock>
 *   - triggered by server invocation for OperationPrototype <GetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_ServiceReminder>
 *   - triggered by server invocation for OperationPrototype <GetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_SpeedoGauge>
 *   - triggered by server invocation for OperationPrototype <GetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TachoGauge>
 *   - triggered by server invocation for OperationPrototype <GetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TempGauge>
 *   - triggered by server invocation for OperationPrototype <GetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TripComputer>
 *   - triggered by server invocation for OperationPrototype <GetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Warning>
 *   - triggered by server invocation for OperationPrototype <GetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsCys_Certicificate>
 *   - triggered by server invocation for OperationPrototype <GetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsDiag_Dtc>
 *   - triggered by server invocation for OperationPrototype <GetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsDiag_ErrorRecord>
 *   - triggered by server invocation for OperationPrototype <GetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Audio>
 *   - triggered by server invocation for OperationPrototype <GetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Communication>
 *   - triggered by server invocation for OperationPrototype <GetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Display>
 *   - triggered by server invocation for OperationPrototype <GetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Gauges>
 *   - triggered by server invocation for OperationPrototype <GetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Illumination>
 *   - triggered by server invocation for OperationPrototype <GetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Odometer>
 *   - triggered by server invocation for OperationPrototype <GetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Personalization>
 *   - triggered by server invocation for OperationPrototype <GetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Power>
 *   - triggered by server invocation for OperationPrototype <GetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_RealTimeClock>
 *   - triggered by server invocation for OperationPrototype <GetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Tripcomputer>
 *   - triggered by server invocation for OperationPrototype <GetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Warning>
 *   - triggered by server invocation for OperationPrototype <GetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_CusDlt>
 *   - triggered by server invocation for OperationPrototype <GetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_FuelGauge>
 *   - triggered by server invocation for OperationPrototype <GetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Illumination>
 *   - triggered by server invocation for OperationPrototype <GetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Odometer>
 *   - triggered by server invocation for OperationPrototype <GetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_OilGauge>
 *   - triggered by server invocation for OperationPrototype <GetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Personalization>
 *   - triggered by server invocation for OperationPrototype <GetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_PowerGauge>
 *   - triggered by server invocation for OperationPrototype <GetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_RealTimeClock>
 *   - triggered by server invocation for OperationPrototype <GetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_SpeedoGauge>
 *   - triggered by server invocation for OperationPrototype <GetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TachoGauge>
 *   - triggered by server invocation for OperationPrototype <GetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TempGauge>
 *   - triggered by server invocation for OperationPrototype <GetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TripComputer>
 *   - triggered by server invocation for OperationPrototype <GetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Warning>
 *   - triggered by server invocation for OperationPrototype <GetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_EcuPartNumber>
 *   - triggered by server invocation for OperationPrototype <GetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaFinPrint>
 *   - triggered by server invocation for OperationPrototype <GetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaMode>
 *   - triggered by server invocation for OperationPrototype <GetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaStatus>
 *   - triggered by server invocation for OperationPrototype <GetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotadecrypt>
 *   - triggered by server invocation for OperationPrototype <GetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdReflash>
 *   - triggered by server invocation for OperationPrototype <GetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_VehicleConfig>
 *   - triggered by server invocation for OperationPrototype <GetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_VisMeet>
 *   - triggered by server invocation for OperationPrototype <GetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_RefCys_Certicificate>
 *   - triggered by server invocation for OperationPrototype <GetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_RefCys_Certicificate1>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType NvM_GetDataIndex(uint8 *DataIndex)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_NvMService_AC3_SRBS_DS_Defs_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: GetDataIndex_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, NvM_CODE) NvM_GetDataIndex(NvM_BlockIdType parg0, P2VAR(uint8, AUTOMATIC, RTE_NVM_APPL_VAR) DataIndex) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NvM_GetDataIndex (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: GetErrorStatus
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Audio>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Communication>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_EngOffTimer>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_FuelGauge>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Illumination>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Illumination_Copy1>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Illumination_Copy2>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_OilGauge>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Power>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_PowerGauge>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_RealTimeClock>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_ServiceReminder>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_SpeedoGauge>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TachoGauge>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TempGauge>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TripComputer>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Warning>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsCys_Certicificate>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsDiag_Dtc>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsDiag_ErrorRecord>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Audio>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Communication>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Display>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Gauges>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Illumination>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Odometer>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Personalization>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Power>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_RealTimeClock>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Tripcomputer>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Warning>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_CusDlt>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_FuelGauge>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Illumination>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Odometer>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_OilGauge>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Personalization>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_PowerGauge>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_RealTimeClock>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_SpeedoGauge>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TachoGauge>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TempGauge>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TripComputer>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Warning>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_EcuPartNumber>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaFinPrint>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaMode>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaStatus>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotadecrypt>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdReflash>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_VehicleConfig>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_VisMeet>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_RefCys_Certicificate>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_RefCys_Certicificate1>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType NvM_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_NvMService_AC3_SRBS_DS_Defs_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: GetErrorStatus_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, NvM_CODE) NvM_GetErrorStatus(NvM_BlockIdType parg0, P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_NVM_APPL_VAR) ErrorStatus) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NvM_GetErrorStatus (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: InvalidateNvBlock
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Audio>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Communication>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_EngOffTimer>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_FuelGauge>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Illumination>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Illumination_Copy1>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Illumination_Copy2>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_OilGauge>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Power>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_PowerGauge>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_RealTimeClock>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_ServiceReminder>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_SpeedoGauge>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TachoGauge>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TempGauge>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TripComputer>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Warning>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsCys_Certicificate>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsDiag_Dtc>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsDiag_ErrorRecord>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Audio>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Communication>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Display>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Gauges>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Illumination>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Odometer>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Personalization>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Power>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_RealTimeClock>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Tripcomputer>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Warning>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_CusDlt>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_FuelGauge>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Illumination>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Odometer>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_OilGauge>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Personalization>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_PowerGauge>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_RealTimeClock>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_SpeedoGauge>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TachoGauge>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TempGauge>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TripComputer>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Warning>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_EcuPartNumber>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaFinPrint>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaMode>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaStatus>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotadecrypt>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdReflash>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_VehicleConfig>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_VisMeet>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_RefCys_Certicificate>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_RefCys_Certicificate1>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType NvM_InvalidateNvBlock(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_NvMService_AC3_SRBS_DS_Defs_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: InvalidateNvBlock_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, NvM_CODE) NvM_InvalidateNvBlock(NvM_BlockIdType parg0) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NvM_InvalidateNvBlock (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NvM_MainFunction
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Audio_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Communication_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_EngOffTimer_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_FuelGauge_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Illumination_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Illumination_Copy1_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Illumination_Copy2_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_OilGauge_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Power_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_PowerGauge_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_RealTimeClock_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_ServiceReminder_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_SpeedoGauge_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TachoGauge_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TempGauge_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TripComputer_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Warning_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsCys_Certicificate_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsDiag_Dtc_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsDiag_ErrorRecord_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Audio_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Communication_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Display_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Gauges_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Illumination_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Odometer_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Personalization_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Power_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_RealTimeClock_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Tripcomputer_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Warning_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_CusDlt_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_FuelGauge_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Illumination_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Odometer_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_OilGauge_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Personalization_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_PowerGauge_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_RealTimeClock_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_SpeedoGauge_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TachoGauge_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TempGauge_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TripComputer_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Warning_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_EcuPartNumber_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaFinPrint_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaMode_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaStatus_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotadecrypt_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdReflash_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_VehicleConfig_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_VisMeet_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_RefCys_Certicificate_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_RefCys_Certicificate1_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: NvM_MainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, NvM_CODE) NvM_MainFunction(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NvM_MainFunction
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  /**********************************************************
  * Direct Function Accesses and Take Addresses of Functions
  **********************************************************/

  {
    FncPtrType NvM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    NvM_FctPtr = (FncPtrType)TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Audio_JobFinished; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Audio_JobFinished(0U, 0U);
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

  {
    FncPtrType NvM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    NvM_FctPtr = (FncPtrType)TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Communication_JobFinished; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Communication_JobFinished(0U, 0U);
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

  {
    FncPtrType NvM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    NvM_FctPtr = (FncPtrType)TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_EngOffTimer_JobFinished; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_EngOffTimer_JobFinished(0U, 0U);
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

  {
    FncPtrType NvM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    NvM_FctPtr = (FncPtrType)TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_FuelGauge_JobFinished; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_FuelGauge_JobFinished(0U, 0U);
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

  {
    FncPtrType NvM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    NvM_FctPtr = (FncPtrType)TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Illumination_JobFinished; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Illumination_JobFinished(0U, 0U);
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

  {
    FncPtrType NvM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    NvM_FctPtr = (FncPtrType)TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Illumination_Copy1_JobFinished; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Illumination_Copy1_JobFinished(0U, 0U);
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

  {
    FncPtrType NvM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    NvM_FctPtr = (FncPtrType)TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Illumination_Copy2_JobFinished; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Illumination_Copy2_JobFinished(0U, 0U);
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

  {
    FncPtrType NvM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    NvM_FctPtr = (FncPtrType)TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_OilGauge_JobFinished; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_OilGauge_JobFinished(0U, 0U);
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

  {
    FncPtrType NvM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    NvM_FctPtr = (FncPtrType)TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Power_JobFinished; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Power_JobFinished(0U, 0U);
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

  {
    FncPtrType NvM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    NvM_FctPtr = (FncPtrType)TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_PowerGauge_JobFinished; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_PowerGauge_JobFinished(0U, 0U);
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

  {
    FncPtrType NvM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    NvM_FctPtr = (FncPtrType)TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_RealTimeClock_JobFinished; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_RealTimeClock_JobFinished(0U, 0U);
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

  {
    FncPtrType NvM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    NvM_FctPtr = (FncPtrType)TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_ServiceReminder_JobFinished; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_ServiceReminder_JobFinished(0U, 0U);
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

  {
    FncPtrType NvM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    NvM_FctPtr = (FncPtrType)TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_SpeedoGauge_JobFinished; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_SpeedoGauge_JobFinished(0U, 0U);
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

  {
    FncPtrType NvM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    NvM_FctPtr = (FncPtrType)TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TachoGauge_JobFinished; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TachoGauge_JobFinished(0U, 0U);
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

  {
    FncPtrType NvM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    NvM_FctPtr = (FncPtrType)TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TempGauge_JobFinished; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TempGauge_JobFinished(0U, 0U);
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

  {
    FncPtrType NvM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    NvM_FctPtr = (FncPtrType)TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TripComputer_JobFinished; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TripComputer_JobFinished(0U, 0U);
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

  {
    FncPtrType NvM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    NvM_FctPtr = (FncPtrType)TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Warning_JobFinished; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Warning_JobFinished(0U, 0U);
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

  {
    FncPtrType NvM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    NvM_FctPtr = (FncPtrType)TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsCys_Certicificate_JobFinished; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsCys_Certicificate_JobFinished(0U, 0U);
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

  {
    FncPtrType NvM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    NvM_FctPtr = (FncPtrType)TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsDiag_Dtc_JobFinished; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsDiag_Dtc_JobFinished(0U, 0U);
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

  {
    FncPtrType NvM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    NvM_FctPtr = (FncPtrType)TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsDiag_ErrorRecord_JobFinished; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsDiag_ErrorRecord_JobFinished(0U, 0U);
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

  {
    FncPtrType NvM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    NvM_FctPtr = (FncPtrType)TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Audio_JobFinished; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Audio_JobFinished(0U, 0U);
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

  {
    FncPtrType NvM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    NvM_FctPtr = (FncPtrType)TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Communication_JobFinished; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Communication_JobFinished(0U, 0U);
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

  {
    FncPtrType NvM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    NvM_FctPtr = (FncPtrType)TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Display_JobFinished; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Display_JobFinished(0U, 0U);
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

  {
    FncPtrType NvM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    NvM_FctPtr = (FncPtrType)TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Gauges_JobFinished; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Gauges_JobFinished(0U, 0U);
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

  {
    FncPtrType NvM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    NvM_FctPtr = (FncPtrType)TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Illumination_JobFinished; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Illumination_JobFinished(0U, 0U);
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

  {
    FncPtrType NvM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    NvM_FctPtr = (FncPtrType)TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Odometer_JobFinished; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Odometer_JobFinished(0U, 0U);
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

  {
    FncPtrType NvM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    NvM_FctPtr = (FncPtrType)TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Personalization_JobFinished; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Personalization_JobFinished(0U, 0U);
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

  {
    FncPtrType NvM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    NvM_FctPtr = (FncPtrType)TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Power_JobFinished; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Power_JobFinished(0U, 0U);
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

  {
    FncPtrType NvM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    NvM_FctPtr = (FncPtrType)TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_RealTimeClock_JobFinished; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_RealTimeClock_JobFinished(0U, 0U);
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

  {
    FncPtrType NvM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    NvM_FctPtr = (FncPtrType)TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Tripcomputer_JobFinished; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Tripcomputer_JobFinished(0U, 0U);
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

  {
    FncPtrType NvM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    NvM_FctPtr = (FncPtrType)TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Warning_JobFinished; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Warning_JobFinished(0U, 0U);
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

  {
    FncPtrType NvM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    NvM_FctPtr = (FncPtrType)TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_CusDlt_JobFinished; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_CusDlt_JobFinished(0U, 0U);
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

  {
    FncPtrType NvM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    NvM_FctPtr = (FncPtrType)TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_FuelGauge_JobFinished; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_FuelGauge_JobFinished(0U, 0U);
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

  {
    FncPtrType NvM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    NvM_FctPtr = (FncPtrType)TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Illumination_JobFinished; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Illumination_JobFinished(0U, 0U);
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

  {
    FncPtrType NvM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    NvM_FctPtr = (FncPtrType)TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Odometer_JobFinished; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Odometer_JobFinished(0U, 0U);
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

  {
    FncPtrType NvM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    NvM_FctPtr = (FncPtrType)TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_OilGauge_JobFinished; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_OilGauge_JobFinished(0U, 0U);
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

  {
    FncPtrType NvM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    NvM_FctPtr = (FncPtrType)TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Personalization_JobFinished; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Personalization_JobFinished(0U, 0U);
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

  {
    FncPtrType NvM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    NvM_FctPtr = (FncPtrType)TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_PowerGauge_JobFinished; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_PowerGauge_JobFinished(0U, 0U);
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

  {
    FncPtrType NvM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    NvM_FctPtr = (FncPtrType)TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_RealTimeClock_JobFinished; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_RealTimeClock_JobFinished(0U, 0U);
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

  {
    FncPtrType NvM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    NvM_FctPtr = (FncPtrType)TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_SpeedoGauge_JobFinished; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_SpeedoGauge_JobFinished(0U, 0U);
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

  {
    FncPtrType NvM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    NvM_FctPtr = (FncPtrType)TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TachoGauge_JobFinished; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TachoGauge_JobFinished(0U, 0U);
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

  {
    FncPtrType NvM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    NvM_FctPtr = (FncPtrType)TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TempGauge_JobFinished; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TempGauge_JobFinished(0U, 0U);
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

  {
    FncPtrType NvM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    NvM_FctPtr = (FncPtrType)TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TripComputer_JobFinished; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TripComputer_JobFinished(0U, 0U);
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

  {
    FncPtrType NvM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    NvM_FctPtr = (FncPtrType)TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Warning_JobFinished; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Warning_JobFinished(0U, 0U);
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

  {
    FncPtrType NvM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    NvM_FctPtr = (FncPtrType)TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_EcuPartNumber_JobFinished; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_EcuPartNumber_JobFinished(0U, 0U);
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

  {
    FncPtrType NvM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    NvM_FctPtr = (FncPtrType)TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaFinPrint_JobFinished; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaFinPrint_JobFinished(0U, 0U);
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

  {
    FncPtrType NvM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    NvM_FctPtr = (FncPtrType)TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaMode_JobFinished; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaMode_JobFinished(0U, 0U);
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

  {
    FncPtrType NvM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    NvM_FctPtr = (FncPtrType)TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaStatus_JobFinished; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaStatus_JobFinished(0U, 0U);
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

  {
    FncPtrType NvM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    NvM_FctPtr = (FncPtrType)TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotadecrypt_JobFinished; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotadecrypt_JobFinished(0U, 0U);
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

  {
    FncPtrType NvM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    NvM_FctPtr = (FncPtrType)TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdReflash_JobFinished; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdReflash_JobFinished(0U, 0U);
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

  {
    FncPtrType NvM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    NvM_FctPtr = (FncPtrType)TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_VehicleConfig_JobFinished; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_VehicleConfig_JobFinished(0U, 0U);
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

  {
    FncPtrType NvM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    NvM_FctPtr = (FncPtrType)TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_VisMeet_JobFinished; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_VisMeet_JobFinished(0U, 0U);
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

  {
    FncPtrType NvM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    NvM_FctPtr = (FncPtrType)TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_RefCys_Certicificate_JobFinished; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_RefCys_Certicificate_JobFinished(0U, 0U);
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

  {
    FncPtrType NvM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    NvM_FctPtr = (FncPtrType)TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_RefCys_Certicificate1_JobFinished; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_NvM_Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_RefCys_Certicificate1_JobFinished(0U, 0U);
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

  TSC_NvM_SchM_Enter_NvM_NVM_EXCLUSIVE_AREA_0();
  TSC_NvM_SchM_Exit_NvM_NVM_EXCLUSIVE_AREA_0();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ReadBlock
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Audio>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Communication>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_EngOffTimer>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_FuelGauge>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Illumination>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Illumination_Copy1>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Illumination_Copy2>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_OilGauge>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Power>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_PowerGauge>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_RealTimeClock>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_ServiceReminder>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_SpeedoGauge>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TachoGauge>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TempGauge>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TripComputer>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Warning>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsCys_Certicificate>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsDiag_Dtc>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsDiag_ErrorRecord>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Audio>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Communication>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Display>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Gauges>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Illumination>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Odometer>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Personalization>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Power>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_RealTimeClock>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Tripcomputer>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Warning>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_CusDlt>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_FuelGauge>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Illumination>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Odometer>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_OilGauge>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Personalization>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_PowerGauge>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_RealTimeClock>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_SpeedoGauge>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TachoGauge>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TempGauge>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TripComputer>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Warning>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_EcuPartNumber>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaFinPrint>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaMode>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaStatus>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotadecrypt>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdReflash>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_VehicleConfig>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_VisMeet>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_RefCys_Certicificate>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_RefCys_Certicificate1>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType NvM_ReadBlock(dtRef_VOID DstPtr)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_NvMService_AC3_SRBS_DS_Defs_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ReadBlock_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, NvM_CODE) NvM_ReadBlock(NvM_BlockIdType parg0, dtRef_VOID DstPtr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NvM_ReadBlock (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RestoreBlockDefaults
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Audio>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Communication>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_EngOffTimer>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_FuelGauge>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Illumination>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Illumination_Copy1>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Illumination_Copy2>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_OilGauge>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Power>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_PowerGauge>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_RealTimeClock>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_ServiceReminder>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_SpeedoGauge>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TachoGauge>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TempGauge>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TripComputer>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Warning>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsCys_Certicificate>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsDiag_Dtc>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsDiag_ErrorRecord>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Audio>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Communication>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Display>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Gauges>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Illumination>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Odometer>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Personalization>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Power>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_RealTimeClock>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Tripcomputer>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Warning>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_CusDlt>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_FuelGauge>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Illumination>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Odometer>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_OilGauge>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Personalization>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_PowerGauge>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_RealTimeClock>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_SpeedoGauge>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TachoGauge>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TempGauge>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TripComputer>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Warning>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_EcuPartNumber>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaFinPrint>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaMode>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaStatus>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotadecrypt>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdReflash>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_VehicleConfig>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_VisMeet>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_RefCys_Certicificate>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_RefCys_Certicificate1>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType NvM_RestoreBlockDefaults(dtRef_VOID DstPtr)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_NvMService_AC3_SRBS_DS_Defs_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RestoreBlockDefaults_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, NvM_CODE) NvM_RestoreBlockDefaults(NvM_BlockIdType parg0, dtRef_VOID DstPtr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NvM_RestoreBlockDefaults (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SetBlockProtection
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdmin_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Audio>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdmin_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Communication>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdmin_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_EngOffTimer>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdmin_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_FuelGauge>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdmin_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Illumination>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdmin_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Illumination_Copy1>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdmin_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Illumination_Copy2>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdmin_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_OilGauge>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdmin_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Power>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdmin_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_PowerGauge>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdmin_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_RealTimeClock>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdmin_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_ServiceReminder>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdmin_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_SpeedoGauge>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdmin_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TachoGauge>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdmin_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TempGauge>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdmin_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TripComputer>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdmin_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Warning>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdmin_NvBlockSwComponentTypeNVBlockDescriptor_BsCys_Certicificate>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdmin_NvBlockSwComponentTypeNVBlockDescriptor_BsDiag_Dtc>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdmin_NvBlockSwComponentTypeNVBlockDescriptor_BsDiag_ErrorRecord>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdmin_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Audio>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdmin_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Communication>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdmin_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Display>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdmin_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Gauges>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdmin_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Illumination>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdmin_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Odometer>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdmin_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Personalization>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdmin_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Power>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdmin_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_RealTimeClock>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdmin_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Tripcomputer>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdmin_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Warning>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdmin_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_CusDlt>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdmin_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_FuelGauge>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdmin_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Illumination>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdmin_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Odometer>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdmin_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_OilGauge>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdmin_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Personalization>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdmin_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_PowerGauge>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdmin_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_RealTimeClock>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdmin_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_SpeedoGauge>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdmin_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TachoGauge>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdmin_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TempGauge>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdmin_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TripComputer>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdmin_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Warning>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdmin_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_EcuPartNumber>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdmin_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaFinPrint>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdmin_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaMode>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdmin_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaStatus>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdmin_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotadecrypt>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdmin_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdReflash>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdmin_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_VehicleConfig>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdmin_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_VisMeet>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdmin_NvBlockSwComponentTypeNVBlockDescriptor_RefCys_Certicificate>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdmin_NvBlockSwComponentTypeNVBlockDescriptor_RefCys_Certicificate1>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType NvM_SetBlockProtection(boolean ProtectionEnabled)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_NvMAdministration_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: SetBlockProtection_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, NvM_CODE) NvM_SetBlockProtection(NvM_BlockIdType parg0, boolean ProtectionEnabled) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NvM_SetBlockProtection (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SetDataIndex
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Audio>
 *   - triggered by server invocation for OperationPrototype <SetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Communication>
 *   - triggered by server invocation for OperationPrototype <SetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_EngOffTimer>
 *   - triggered by server invocation for OperationPrototype <SetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_FuelGauge>
 *   - triggered by server invocation for OperationPrototype <SetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Illumination>
 *   - triggered by server invocation for OperationPrototype <SetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Illumination_Copy1>
 *   - triggered by server invocation for OperationPrototype <SetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Illumination_Copy2>
 *   - triggered by server invocation for OperationPrototype <SetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_OilGauge>
 *   - triggered by server invocation for OperationPrototype <SetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Power>
 *   - triggered by server invocation for OperationPrototype <SetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_PowerGauge>
 *   - triggered by server invocation for OperationPrototype <SetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_RealTimeClock>
 *   - triggered by server invocation for OperationPrototype <SetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_ServiceReminder>
 *   - triggered by server invocation for OperationPrototype <SetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_SpeedoGauge>
 *   - triggered by server invocation for OperationPrototype <SetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TachoGauge>
 *   - triggered by server invocation for OperationPrototype <SetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TempGauge>
 *   - triggered by server invocation for OperationPrototype <SetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TripComputer>
 *   - triggered by server invocation for OperationPrototype <SetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Warning>
 *   - triggered by server invocation for OperationPrototype <SetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsCys_Certicificate>
 *   - triggered by server invocation for OperationPrototype <SetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsDiag_Dtc>
 *   - triggered by server invocation for OperationPrototype <SetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsDiag_ErrorRecord>
 *   - triggered by server invocation for OperationPrototype <SetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Audio>
 *   - triggered by server invocation for OperationPrototype <SetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Communication>
 *   - triggered by server invocation for OperationPrototype <SetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Display>
 *   - triggered by server invocation for OperationPrototype <SetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Gauges>
 *   - triggered by server invocation for OperationPrototype <SetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Illumination>
 *   - triggered by server invocation for OperationPrototype <SetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Odometer>
 *   - triggered by server invocation for OperationPrototype <SetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Personalization>
 *   - triggered by server invocation for OperationPrototype <SetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Power>
 *   - triggered by server invocation for OperationPrototype <SetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_RealTimeClock>
 *   - triggered by server invocation for OperationPrototype <SetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Tripcomputer>
 *   - triggered by server invocation for OperationPrototype <SetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Warning>
 *   - triggered by server invocation for OperationPrototype <SetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_CusDlt>
 *   - triggered by server invocation for OperationPrototype <SetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_FuelGauge>
 *   - triggered by server invocation for OperationPrototype <SetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Illumination>
 *   - triggered by server invocation for OperationPrototype <SetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Odometer>
 *   - triggered by server invocation for OperationPrototype <SetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_OilGauge>
 *   - triggered by server invocation for OperationPrototype <SetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Personalization>
 *   - triggered by server invocation for OperationPrototype <SetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_PowerGauge>
 *   - triggered by server invocation for OperationPrototype <SetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_RealTimeClock>
 *   - triggered by server invocation for OperationPrototype <SetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_SpeedoGauge>
 *   - triggered by server invocation for OperationPrototype <SetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TachoGauge>
 *   - triggered by server invocation for OperationPrototype <SetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TempGauge>
 *   - triggered by server invocation for OperationPrototype <SetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TripComputer>
 *   - triggered by server invocation for OperationPrototype <SetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Warning>
 *   - triggered by server invocation for OperationPrototype <SetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_EcuPartNumber>
 *   - triggered by server invocation for OperationPrototype <SetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaFinPrint>
 *   - triggered by server invocation for OperationPrototype <SetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaMode>
 *   - triggered by server invocation for OperationPrototype <SetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaStatus>
 *   - triggered by server invocation for OperationPrototype <SetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotadecrypt>
 *   - triggered by server invocation for OperationPrototype <SetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdReflash>
 *   - triggered by server invocation for OperationPrototype <SetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_VehicleConfig>
 *   - triggered by server invocation for OperationPrototype <SetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_VisMeet>
 *   - triggered by server invocation for OperationPrototype <SetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_RefCys_Certicificate>
 *   - triggered by server invocation for OperationPrototype <SetDataIndex> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_RefCys_Certicificate1>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType NvM_SetDataIndex(uint8 DataIndex)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_NvMService_AC3_SRBS_DS_Defs_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: SetDataIndex_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, NvM_CODE) NvM_SetDataIndex(NvM_BlockIdType parg0, uint8 DataIndex) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NvM_SetDataIndex (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SetRamBlockStatus
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Audio>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Communication>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_EngOffTimer>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_FuelGauge>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Illumination>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Illumination_Copy1>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Illumination_Copy2>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_OilGauge>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Power>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_PowerGauge>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_RealTimeClock>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_ServiceReminder>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_SpeedoGauge>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TachoGauge>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TempGauge>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TripComputer>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Warning>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsCys_Certicificate>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsDiag_Dtc>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsDiag_ErrorRecord>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Audio>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Communication>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Display>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Gauges>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Illumination>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Odometer>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Personalization>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Power>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_RealTimeClock>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Tripcomputer>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Warning>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_CusDlt>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_FuelGauge>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Illumination>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Odometer>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_OilGauge>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Personalization>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_PowerGauge>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_RealTimeClock>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_SpeedoGauge>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TachoGauge>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TempGauge>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TripComputer>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Warning>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_EcuPartNumber>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaFinPrint>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaMode>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaStatus>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotadecrypt>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdReflash>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_VehicleConfig>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_VisMeet>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_RefCys_Certicificate>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_RefCys_Certicificate1>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType NvM_SetRamBlockStatus(boolean RamBlockStatus)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_NvMService_AC3_SRBS_DS_Defs_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: SetRamBlockStatus_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, NvM_CODE) NvM_SetRamBlockStatus(NvM_BlockIdType parg0, boolean RamBlockStatus) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NvM_SetRamBlockStatus (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: WriteBlock
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Audio>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Communication>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_EngOffTimer>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_FuelGauge>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Illumination>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Illumination_Copy1>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Illumination_Copy2>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_OilGauge>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Power>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_PowerGauge>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_RealTimeClock>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_ServiceReminder>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_SpeedoGauge>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TachoGauge>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TempGauge>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TripComputer>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Warning>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsCys_Certicificate>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsDiag_Dtc>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsDiag_ErrorRecord>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Audio>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Communication>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Display>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Gauges>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Illumination>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Odometer>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Personalization>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Power>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_RealTimeClock>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Tripcomputer>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Warning>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_CusDlt>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_FuelGauge>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Illumination>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Odometer>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_OilGauge>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Personalization>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_PowerGauge>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_RealTimeClock>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_SpeedoGauge>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TachoGauge>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TempGauge>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TripComputer>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Warning>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_EcuPartNumber>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaFinPrint>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaMode>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaStatus>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotadecrypt>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdReflash>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_VehicleConfig>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_VisMeet>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_RefCys_Certicificate>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PS_NvBlockSwComponentTypeNVBlockDescriptor_RefCys_Certicificate1>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType NvM_WriteBlock(dtRef_const_VOID SrcPtr)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_NvMService_AC3_SRBS_DS_Defs_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: WriteBlock_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, NvM_CODE) NvM_WriteBlock(NvM_BlockIdType parg0, dtRef_const_VOID SrcPtr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NvM_WriteBlock (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define NvM_STOP_SEC_CODE
#include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void NvM_TestDefines(void)
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
