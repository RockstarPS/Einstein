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
 *          File:  Rte_Test_Comp.h
 *        Config:  BMW.dpa
 *   ECU-Project:  EcuInstance
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Application header file for SW-C <Test_Comp>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_TEST_COMP_H
# define _RTE_TEST_COMP_H

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

# include "Rte_Test_Comp_Type.h"
# include "Rte_DataHandleType.h"


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Test_Comp_pSR_PowerSystemState_PowerSystemStateData(P2VAR(SPowerSystemState, AUTOMATIC, RTE_TEST_COMP_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_pSR_DisplayCurrentState_DisplayCurrentStateData Rte_Read_Test_Comp_pSR_DisplayCurrentState_DisplayCurrentStateData
#  define Rte_Read_Test_Comp_pSR_DisplayCurrentState_DisplayCurrentStateData(data) (*(data) = Rte_C_SDisplayCurrentState_0, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_pSR_EnetRegResp_EnetRegRespData Rte_Read_Test_Comp_pSR_EnetRegResp_EnetRegRespData
#  define Rte_Read_Test_Comp_pSR_EnetRegResp_EnetRegRespData(data) (*(data) = Rte_C_SEnetRegResp_0, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_pSR_PowerSystemState_PowerSystemStateData Rte_Read_Test_Comp_pSR_PowerSystemState_PowerSystemStateData


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_rSR_EnetRegReq_EnetRegReqData Rte_Write_Test_Comp_rSR_EnetRegReq_EnetRegReqData
#  define Rte_Write_Test_Comp_rSR_EnetRegReq_EnetRegReqData(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define Rte_Call_ppCS_UclCmplibCmd_OnCommand(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_ppCS_UclInitShutdown_Initialize() (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_ppCS_UclInitShutdown_Shutdown() (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define Test_Comp_START_SEC_CODE
# include "Test_Comp_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_AppTaskStubRunnable AppTaskStubRunnable
#  define RTE_RUNNABLE_AudioTaskStubRunnable AudioTaskStubRunnable
#  define RTE_RUNNABLE_CanSM_MainFunction CanSM_MainFunction
#  define RTE_RUNNABLE_CddTaskStubRunnable CddTaskStubRunnable
#  define RTE_RUNNABLE_Com_MainFunctionRx Com_MainFunctionRx
#  define RTE_RUNNABLE_Com_MainFunctionTx Com_MainFunctionTx
#  define RTE_RUNNABLE_EepDrv_MainFunction EepDrv_MainFunction
#  define RTE_RUNNABLE_EthIf_MainFunctionState EthIf_MainFunctionState
#  define RTE_RUNNABLE_EthSM_MainFunction EthSM_MainFunction
#  define RTE_RUNNABLE_FotaTaskStubRunnable FotaTaskStubRunnable
#  define RTE_RUNNABLE_GaugeTaskStubRunnable GaugeTaskStubRunnable
#  define RTE_RUNNABLE_GraphicsTaskStubRunnable GraphicsTaskStubRunnable
#  define RTE_RUNNABLE_I2c_MainFunction I2c_MainFunction
#  define RTE_RUNNABLE_IndTaskStubRunnable IndTaskStubRunnable
#  define RTE_RUNNABLE_IoExp_MainFunction IoExp_MainFunction
#  define RTE_RUNNABLE_LinTaskStubRunnable LinTaskStubRunnable
#  define RTE_RUNNABLE_SoAd_MainFunction SoAd_MainFunction
#  define RTE_RUNNABLE_Spi_MainFunction_Handling Spi_MainFunction_Handling
#  define RTE_RUNNABLE_TcpIp_MainFunction TcpIp_MainFunction
#  define RTE_RUNNABLE_Test_Comp_MainFunction Test_Comp_MainFunction
#  define RTE_RUNNABLE_TripTaskStubRunnable TripTaskStubRunnable
#  define RTE_RUNNABLE_TxRxIpcMessage TxRxIpcMessage
#  define RTE_RUNNABLE_WarnTaskStubRunnable WarnTaskStubRunnable
#  define RTE_RUNNABLE_WdgMgntTaskStubRunnable WdgMgntTaskStubRunnable
#  define RTE_RUNNABLE_rCS_UclSystemCallbacks_ErrorNotification rCS_UclSystemCallbacks_ErrorNotification
#  define RTE_RUNNABLE_rCS_UclSystemCallbacks_LinkStatusChanged rCS_UclSystemCallbacks_LinkStatusChanged
# endif

FUNC(void, Test_Comp_CODE) AppTaskStubRunnable(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, Test_Comp_CODE) AudioTaskStubRunnable(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, Test_Comp_CODE) CanSM_MainFunction(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, Test_Comp_CODE) CddTaskStubRunnable(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, Test_Comp_CODE) Com_MainFunctionRx(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, Test_Comp_CODE) Com_MainFunctionTx(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, Test_Comp_CODE) EepDrv_MainFunction(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, Test_Comp_CODE) EthIf_MainFunctionState(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, Test_Comp_CODE) EthSM_MainFunction(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, Test_Comp_CODE) FotaTaskStubRunnable(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, Test_Comp_CODE) GaugeTaskStubRunnable(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, Test_Comp_CODE) GraphicsTaskStubRunnable(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, Test_Comp_CODE) I2c_MainFunction(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, Test_Comp_CODE) IndTaskStubRunnable(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, Test_Comp_CODE) IoExp_MainFunction(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, Test_Comp_CODE) LinTaskStubRunnable(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, Test_Comp_CODE) SoAd_MainFunction(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, Test_Comp_CODE) Spi_MainFunction_Handling(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, Test_Comp_CODE) TcpIp_MainFunction(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, Test_Comp_CODE) Test_Comp_MainFunction(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, Test_Comp_CODE) TripTaskStubRunnable(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, Test_Comp_CODE) TxRxIpcMessage(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, Test_Comp_CODE) WarnTaskStubRunnable(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, Test_Comp_CODE) WdgMgntTaskStubRunnable(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, Test_Comp_CODE) rCS_UclSystemCallbacks_ErrorNotification(uint8 DLInst, sint32 ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, Test_Comp_CODE) rCS_UclSystemCallbacks_LinkStatusChanged(uint8 DLInst, sint32 Status); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define Test_Comp_STOP_SEC_CODE
# include "Test_Comp_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_UclCmplibCmd_E_OK (0U)

#  define RTE_E_UclInitShutdown_E_OK (0U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_TEST_COMP_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
