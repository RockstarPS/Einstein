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
 *          File:  Rte_CUpdateCdd.h
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Application header file for SW-C <CUpdateCdd>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CUPDATECDD_H
# define _RTE_CUPDATECDD_H

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

# include "Rte_CUpdateCdd_Type.h"
# include "Rte_DataHandleType.h"


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_CUpdateCdd_rp_SR_UpdateShortServiceResponse_UpdateShortServiceRespData(P2VAR(SUpdateShortServiceResp, AUTOMATIC, RTE_CUPDATECDD_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Send_CUpdateCdd_pp_SR_UpdateLongServiceRequest_UpdateLongServiceReqData(P2CONST(SUpdateLongServiceReq, AUTOMATIC, RTE_CUPDATECDD_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Send_CUpdateCdd_pp_SR_UpdateShortServiceRequest_UpdateShortServiceReqData(P2CONST(SUpdateShortServiceReq, AUTOMATIC, RTE_CUPDATECDD_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Receive_<p>_<d> (explicit S/R communication with isQueued = true)
 *********************************************************************************************************************/
#  define Rte_Receive_rp_SR_UpdateShortServiceResponse_UpdateShortServiceRespData Rte_Receive_CUpdateCdd_rp_SR_UpdateShortServiceResponse_UpdateShortServiceRespData


/**********************************************************************************************************************
 * Rte_Send_<p>_<d> (explicit S/R communication with isQueued = true)
 *********************************************************************************************************************/
#  define Rte_Send_pp_SR_UpdateLongServiceRequest_UpdateLongServiceReqData Rte_Send_CUpdateCdd_pp_SR_UpdateLongServiceRequest_UpdateLongServiceReqData
#  define Rte_Send_pp_SR_UpdateShortServiceRequest_UpdateShortServiceReqData Rte_Send_CUpdateCdd_pp_SR_UpdateShortServiceRequest_UpdateShortServiceReqData


# endif /* !defined(RTE_CORE) */


# define CUpdateCdd_START_SEC_CODE
# include "CUpdateCdd_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CUpdateCdd_Impl_MainFunction CUpdateCdd_Impl_MainFunction
#  define RTE_RUNNABLE_CUpdateCdd_Impl_OnCommand CUpdateCdd_Impl_OnCommand
#  define RTE_RUNNABLE_CUpdateCdd_OnDre_UpdateResponse CUpdateCdd_OnDre_UpdateResponse
#  define RTE_RUNNABLE_CUpdateCdd_UpdateCdd_GenericDIDRequestHandler CUpdateCdd_UpdateCdd_GenericDIDRequestHandler
#  define RTE_RUNNABLE_CUpdateCdd_UpdateCdd_GenericProgSessionRequest CUpdateCdd_UpdateCdd_GenericProgSessionRequest
#  define RTE_RUNNABLE_CUpdateCdd_UpdateCdd_GenericRIDRequestHandler CUpdateCdd_UpdateCdd_GenericRIDRequestHandler
#  define RTE_RUNNABLE_CUpdateCdd_UpdateCdd_GenericRequestDownloadHandler CUpdateCdd_UpdateCdd_GenericRequestDownloadHandler
#  define RTE_RUNNABLE_CUpdateCdd_UpdateCdd_GenericTransferDataHandler CUpdateCdd_UpdateCdd_GenericTransferDataHandler
#  define RTE_RUNNABLE_CUpdateCdd_UpdateCdd_GenericTransferExitHandler CUpdateCdd_UpdateCdd_GenericTransferExitHandler
# endif

FUNC(void, CUpdateCdd_CODE) CUpdateCdd_Impl_MainFunction(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, CUpdateCdd_CODE) CUpdateCdd_Impl_OnCommand(ECmpCmd cmdP); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, CUpdateCdd_CODE) CUpdateCdd_OnDre_UpdateResponse(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, CUpdateCdd_CODE) CUpdateCdd_UpdateCdd_GenericDIDRequestHandler(UInt8 OpStatus, UInt8 DID_Action, UInt16 DID, UInt32 ReqLength, UInt8 Buff, P2VAR(UInt32, AUTOMATIC, RTE_CUPDATECDD_APPL_VAR) ResLength, P2VAR(UInt8, AUTOMATIC, RTE_CUPDATECDD_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, CUpdateCdd_CODE) CUpdateCdd_UpdateCdd_GenericProgSessionRequest(P2VAR(UInt8, AUTOMATIC, RTE_CUPDATECDD_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, CUpdateCdd_CODE) CUpdateCdd_UpdateCdd_GenericRIDRequestHandler(UInt8 OpStatus, UInt8 RID_Action, UInt16 RID, UInt32 ReqLength, P2VAR(UInt8, AUTOMATIC, RTE_CUPDATECDD_APPL_VAR) Buff, P2VAR(UInt32, AUTOMATIC, RTE_CUPDATECDD_APPL_VAR) ResLength, P2VAR(UInt8, AUTOMATIC, RTE_CUPDATECDD_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, CUpdateCdd_CODE) CUpdateCdd_UpdateCdd_GenericRequestDownloadHandler(UInt8 OpStatus, UInt8 DataFormatIdentifier, UInt32 MemoryAddress, UInt32 MemorySize, P2VAR(UInt32, AUTOMATIC, RTE_CUPDATECDD_APPL_VAR) BlockLength, P2VAR(UInt8, AUTOMATIC, RTE_CUPDATECDD_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, CUpdateCdd_CODE) CUpdateCdd_UpdateCdd_GenericTransferDataHandler(UInt8 OpStatus, UInt8 MemoryIdentifier, UInt32 MemoryAddress, UInt32 MemorySize, P2VAR(UInt8, AUTOMATIC, RTE_CUPDATECDD_APPL_VAR) MemoryData, P2VAR(UInt8, AUTOMATIC, RTE_CUPDATECDD_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, CUpdateCdd_CODE) CUpdateCdd_UpdateCdd_GenericTransferExitHandler(UInt8 OpStatus, UInt8 RequestfParameterRecord, UInt32 RequestParameterRecordSize, P2VAR(UInt8, AUTOMATIC, RTE_CUPDATECDD_APPL_VAR) ResponseParameterRecord, P2VAR(UInt32, AUTOMATIC, RTE_CUPDATECDD_APPL_VAR) ResponseParameterRecordSize, P2VAR(UInt8, AUTOMATIC, RTE_CUPDATECDD_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define CUpdateCdd_STOP_SEC_CODE
# include "CUpdateCdd_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_TI_UpdateCdd_GenericDIDRequestHandler_E_NOT_OK (1U)

#  define RTE_E_TI_UpdateCdd_GenericProgSessionRequest_E_NOT_OK (1U)

#  define RTE_E_TI_UpdateCdd_GenericRIDRequestHandler_E_NOT_OK (1U)

#  define RTE_E_TI_UpdateCdd_GenericRequestDownloadHandler_E_NOT_OK (1U)

#  define RTE_E_TI_UpdateCdd_GenericTransferDataHandler_E_NOT_OK (1U)

#  define RTE_E_TI_UpdateCdd_GenericTransferExitHandler_E_NOT_OK (1U)

#  define RTE_E_if_CS_ModeOnCommand_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CUPDATECDD_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
