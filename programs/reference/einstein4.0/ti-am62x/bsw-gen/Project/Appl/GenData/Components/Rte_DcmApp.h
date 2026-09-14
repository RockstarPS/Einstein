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
 *          File:  Rte_DcmApp.h
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Application header file for SW-C <DcmApp>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_DCMAPP_H
# define _RTE_DCMAPP_H

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

# include "Rte_DcmApp_Type.h"
# include "Rte_DataHandleType.h"


# define DcmApp_START_SEC_CODE
# include "DcmApp_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CDcmApp_DID_DiagAction CDcmApp_DID_DiagAction
#  define RTE_RUNNABLE_CDcmApp_Diag_Entry_Status CDcmApp_Diag_Entry_Status
#  define RTE_RUNNABLE_CDcmApp_Impl_MainFunction CDcmApp_Impl_MainFunction
#  define RTE_RUNNABLE_CDcmApp_Impl_OnCommand CDcmApp_Impl_OnCommand
#  define RTE_RUNNABLE_CDcmApp_RID_DiagAction CDcmApp_RID_DiagAction
# endif

FUNC(Std_ReturnType, DcmApp_CODE) CDcmApp_DID_DiagAction(teDiagOpStatus OpStatus, UInt16 DIDNum, P2VAR(UInt8, AUTOMATIC, RTE_DCMAPP_APPL_VAR) Data, P2VAR(UInt8, AUTOMATIC, RTE_DCMAPP_APPL_VAR) pNrc, teDIDOperation eOperation); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, DcmApp_CODE) CDcmApp_Diag_Entry_Status(UInt8 SID, P2VAR(UInt8, AUTOMATIC, RTE_DCMAPP_APPL_VAR) RequestData, UInt16 RequestDataSize, UInt8 ReqType, UInt16 SourceAddress, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCMAPP_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, DcmApp_CODE) CDcmApp_Impl_MainFunction(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, DcmApp_CODE) CDcmApp_Impl_OnCommand(ECmpCmd cmdP); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, DcmApp_CODE) CDcmApp_RID_DiagAction(teDiagOpStatus OpStatus, UInt16 RIDNum, P2VAR(UInt8, AUTOMATIC, RTE_DCMAPP_APPL_VAR) Out_RoutineInfo, P2VAR(UInt8, AUTOMATIC, RTE_DCMAPP_APPL_VAR) Data, P2VAR(UInt16, AUTOMATIC, RTE_DCMAPP_APPL_VAR) DataLength, P2VAR(UInt8, AUTOMATIC, RTE_DCMAPP_APPL_VAR) pNrc, teRoutineOperation eOperation); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define DcmApp_STOP_SEC_CODE
# include "DcmApp_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_TI_DID_App_Diag_Action_E_NOT_OK (1U)

#  define RTE_E_TI_DiagEntrySts_E_NOT_OK (1U)

#  define RTE_E_TI_RID_App_Diag_Action_E_NOT_OK (1U)

#  define RTE_E_if_CS_ModeOnCommand_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_DCMAPP_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
