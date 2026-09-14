#ifndef Rte_DmnMgr_stubs_h
#define Rte_DmnMgr_stubs_h "Rte_DmnMgr_stubs.h"

#include "Std_Types.h"
#include "DmnMgr_Cfg.h"


#define DMNMGR_START_SEC_CONST_8
#include "MemMap.h"

#  ifndef eSIGNAL_OK
#   define eSIGNAL_OK (0U)
#  endif

#  ifndef eSIGNAL_MISSING
#   define eSIGNAL_MISSING (1U)
#  endif

#  ifndef eSIGNAL_NEVER_RECEIVED
#   define eSIGNAL_NEVER_RECEIVED (2U)
#  endif

#  ifndef eSIGNAL_INVALID
#   define eSIGNAL_INVALID (4U)
#  endif

#  ifndef EDomainId_DM
#   define EDomainId_DM (3u)
#  endif

#  ifndef EDomainId_HSM
#   define EDomainId_HSM (4u)
#  endif

#define DMNMGR_STOP_SEC_CONST_8
#include "MemMap.h"

///
/// @brief 
///
/// The SDmnCtrlRTCInfo structure is used to get the RTC Data from ComVNim and Notify it to all connected Domains
///
typedef struct
{
    uint16 DmnRTCYear;	///< Year
    uint8 DmnRTCMonth;	///< Month Of the Year
    uint8 DmnRTCDay;	///< Day of the Month
    uint8 DmnRTCHour;	///< Hour Of the Day
    uint8 DmnRTCMin;	///< Minute
	uint8 DmnRTCSec;	///< Second
}SDmnCtrlRTCInfo;

#define DMNMGR_START_SEC_CODE_ASIL_B
#include "MemMap.h"


/*from UCL*/
#ifndef DMNMGR_RTE_INTERFACES_AVAILABLE
#ifndef Rte_Read_rSR_PowerSystemState_PowerSystemStateData
#warning "interface Rte_Read_rSR_PowerSystemState_PowerSystemStateData is not available, use the stub value"
#define Rte_Read_rSR_PowerSystemState_PowerSystemStateData(data)    ((data)->domainId = 1u, (data)->state = ESystemState_FullRun,((Std_ReturnType)E_OK))
#endif
#endif

#ifndef DMNMGR_RTE_INTERFACES_AVAILABLE
#ifndef Rte_Receive_rSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData
#warning "interface Rte_Receive_rSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData is not available, use the stub value"
#define Rte_Receive_rSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(data)   ((data)->domainId = 1u, (data)->timeoutMs = 0u, ((Std_ReturnType)E_OK))
#endif
#endif

#ifndef DMNMGR_RTE_INTERFACES_AVAILABLE
#ifndef Rte_Receive_rSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData
#warning "interface Rte_Receive_rSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData is not available, use the stub value"
#define Rte_Receive_rSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData(data) ((data)->domainId = 1u, (data)->timeoutMs = 0u, ((Std_ReturnType)E_OK))
#endif
#endif

#ifndef DMNMGR_RTE_INTERFACES_AVAILABLE
#ifndef Rte_Receive_rSR_HealthDomainHeartbeat_HealthDomainHeartbeatData
#warning "interface Rte_Receive_rSR_HealthDomainHeartbeat_HealthDomainHeartbeatData is not available, use the stub value"
#define Rte_Receive_rSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(data)   ((data)->domainId = 1u, (data)->seqCnt = 0u, ((Std_ReturnType)E_OK))
#endif
#endif

#ifndef DMNMGR_RTE_INTERFACES_AVAILABLE
#ifndef Rte_Receive_rSR_HealthDomainFatalError_HealthDomainFatalErrorData
#warning "interface Rte_Receive_rSR_HealthDomainFatalError_HealthDomainFatalErrorData is not available, use the stub value"
#define Rte_Receive_rSR_HealthDomainFatalError_HealthDomainFatalErrorData(data) ((data)->domainId = 1u, (data)->compldx = 0, ((Std_ReturnType)E_OK))
#endif
#endif

#ifndef DMNMGR_RTE_INTERFACES_AVAILABLE
#ifndef Rte_Write_pSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData
#warning "interface Rte_Write_pSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData is not available, use the stub value"
#define Rte_Write_pSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(data) ((Std_ReturnType)E_OK)
#endif
#endif

#ifndef DMNMGR_RTE_INTERFACES_NOT_USED
#ifndef Rte_Call_ppCS_UclInitShutdown_CUclProxyCdd_Impl_Shutdown
//#warning "interface Rte_Call_ppCS_UclInitShutdown_CUclProxyCdd_Impl_Shutdown is not available, use the stub value"
#define Rte_Call_ppCS_UclInitShutdown_CUclProxyCdd_Impl_Shutdown()  ((Std_ReturnType)E_OK)
#endif
#endif

#ifndef DMNMGR_RTE_INTERFACES_NOT_USED
#ifndef Rte_Call_ppCS_UclInitShutdown_CUclProxyCdd_Impl_Initialize
//#warning "interface Rte_Call_ppCS_UclInitShutdown_CUclProxyCdd_Impl_Initialize is not available, use the stub value"
#define Rte_Call_ppCS_UclInitShutdown_CUclProxyCdd_Impl_Initialize()    ((Std_ReturnType)E_OK)
#endif
#endif

#ifndef DMNMGR_RTE_INTERFACES_NOT_USED
#ifndef Rte_Read_pSR_UclTxStatuses_PowerSystemStateReqChange_TxStatus
//#warning "interface Rte_Read_pSR_UclTxStatuses_PowerSystemStateReqChange_TxStatus is not available, use the stub value"
#define Rte_Read_pSR_UclTxStatuses_PowerSystemStateReqChange_TxStatus(data) ((Std_ReturnType)E_OK)
#endif
#endif

#ifndef DMNMGR_RTE_INTERFACES_AVAILABLE
#ifndef Rte_Call_rpCSRxCanMdl_RxCan_GetSignalValue
//#warning "interface Rte_Call_rpCSRxCanMdl_RxCan_GetSignalValue is not available, use the stub value"
#define Rte_Call_rpCSRxCanMdl_RxCan_GetSignalValue(RxSignalId,pDestination1P,pDestination2P)  (*(pDestination1P) = 0, *(pDestination2P) = eSIGNAL_OK, ((Std_ReturnType)E_OK))
#endif    
#endif              

#ifndef DMNMGR_RTE_INTERFACES_NOT_USED
#ifndef Rte_Call_ppCSHLService_GetLogData
//#warning "interface Rte_Call_ppCSHLService_GetLogData is not available, use the stub value"
#define Rte_Call_ppCSHLService_GetLogData(eLogId,pBuffer,uBufferSize,pDataSize) ((Std_ReturnType)E_OK)
#endif
#endif

#ifndef DMNMGR_RTE_INTERFACES_NOT_USED
#ifndef Rte_Call_ppCSHLService_ManageDataLog
//#warning "interface Rte_Call_ppCSHLService_ManageDataLog is not available, use the stub value"
#define Rte_Call_ppCSHLService_ManageDataLog(eLogOp) ((Std_ReturnType)E_OK)
#endif
#endif

#ifndef DMNMGR_RTE_INTERFACES_NOT_USED
#ifndef Rte_Call_ppCSHLService_StopStartHL
//#warning "interface Rte_Call_ppCSHLService_StopStartHL is not available, use the stub value"
#define Rte_Call_ppCSHLService_StopStartHL(bIsStopHL)   ((Std_ReturnType)E_OK)
#endif
#endif

#ifndef DMNMGR_RTE_INTERFACES_NOT_USED
#ifndef Rte_Call_ppCSHLReport_Report
//#warning "interface Rte_Call_ppCSHLReport_Report is not available, use the stub value"
#define Rte_Call_ppCSHLReport_Report(eSwcId,eErrorCode,pBuffer,uBufferSize,pDataSize)   ((Std_ReturnType)E_OK)
#endif
#endif

#define DMNMGR_STOP_SEC_CODE_ASIL_B
#include "MemMap.h"

#endif //Rte_DmnMgr_stubs_h
