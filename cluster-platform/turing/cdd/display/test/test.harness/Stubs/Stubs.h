#ifndef STUBS_H
#define STUBS_H

#include "Std_Types.h"
#include "Rte_Type.h"
#include "Os_Types_Lcfg.h"
#include "Dcm_Types.h"
#include "Fee_30_FlexNor_Types.h"

/*==[Macros]===========================================*/
#define MAC_GEN_TEST               STD_OFF
#define MAC_VERIFY_TEST            STD_OFF
#define KEYELEMENT_SET_GET_TEST    STD_OFF
#define ECB_ENCRYPT_TEST           STD_OFF
#define CBC_ENCRYPT_TEST           STD_OFF
#define ECB_DECRYPT_TEST           STD_OFF
#define CBC_DECRYPT_TEST           STD_OFF
#define CRYPTO_RANDOM_GEN_TEST     STD_OFF
#define CSM_RANDOM_GEN_TEST        STD_OFF
#define SMPU_ENABLE_TEST           STD_ON
#define RSA_SIGN_VERIFY_TEST       STD_OFF
#define REFLASH_TEST               STD_OFF
#define FWPU_TEST                  STD_OFF

extern void PreTaskHook( void );
extern void PostTaskHook( void );
#ifdef EN_CPULOAD_MEASUREMENT
extern void UserPreISRHook(ISRType x);
extern void UserPostISRHook(ISRType x);
#endif

extern void IcuSignalNotification_DI_LCD_BL_PWR_FAULT(void);
extern void  IcuSignalNotification_TT_SHIFT_ERR(void);

void CDD_GetApmTimerCount(uint32* time1);

# define Rte_TypeDef_eEcuMExt_PwrModeType
typedef uint8 eEcuMExt_PwrModeType;

# define Rte_TypeDef_EcuMExt_BootModeType
typedef uint8 EcuMExt_BootModeType;


extern void Csm_mac_gen_callback_test (void);
extern void Csm_mac_ver_callback_test(void);
extern void Csm_ecb_enc_callback_test(void);
extern void Csm_cbc_dec_callback_test(void);
extern void Csm_ecb_dec_callback_test(void);
//Audi stubs
extern void CComAbsCtrl_CmpMain(void);
extern void CGdtCtrl_Impl_MainFunction(void);
extern void CDcm_App_Impl_MainFunction(void);
extern void CComAbsMdl_OnDataTx_CF_Clu_Odometer(void);
extern void CComAbsMdl_OnDataTx_CF_Clu_FitData(void);
extern void CComAbsMdl_OnDataRx_VehicleStates(void);
extern void CComAbsMdl_Impl_TxCanMdlMainFunction(void);
extern void CComAbsMdl_Impl_RxCanMdlMainFunction(void);
extern void CComAbsCtrl_Impl_MainFunction(void);

extern void ComMExt_Impl_MainFunction (void);
extern void DcmExt_MainFunction (void);
extern void DemExt_MainFunction (void);
extern void DltExt_MainFunction (void);
extern void McuExt_MainFunction (void);
extern void MemAbstractMdl_Impl_MainFunction (void);
//extern void NvMExt_MainFunction (void);
extern void NvMExt_SpeedupRunnable (void);
extern void OsTask_SafeBsw_0_Wdgm_Checkpoint_10ms (void);
//extern void TmExt_MainFunction (void);
extern void CCDD_BswFit_Impl_MainFunction (void);
extern void CCDD_FitManager_Impl_MainFunction (void);
extern void CCDD_McuFit_Impl_MainFunction (void);
extern void CGdtCdd_Impl_MainFunction (void);
extern void CMeetCdd_Impl_MainFunction (void);
extern void CMeetCdd_Task (void);
extern void CBacklightCdd_Impl_MainFunction (void);
extern void CDisplayCdd_Impl_MainFunction (void);
extern void Dlt_MainFunction (void);
extern Std_ReturnType CDisplayCdd_Impl_OnCommand (ECmpCmd cmp);
extern Std_ReturnType CMeetCdd_Impl_OnCommand (ECmpCmd cmp);
extern Std_ReturnType CBacklightCdd_Impl_OnCommand (ECmpCmd cmp);
extern void NvmExt_GetNvMReadAllStatus (Boolean *status);

#  define Rte_TypeDef_tHL_ErrorCode
typedef uint8 tHL_ErrorCode;

#  define Rte_TypeDef_tHL_SwcId
typedef uint8 tHL_SwcId;

#if 0
# define Rte_TypeDef_ESystemState
typedef uint8 ESystemState;

# define Rte_TypeDef_EDomainId
typedef uint8 EDomainId;


# define Rte_TypeDef_EUclLinkState_t
typedef uint8 EUclLinkState_t;

# define Rte_TypeDef_EDmnOverallState_t
typedef uint8 EDmnOverallState_t;

 # define Rte_TypeDef_EDmnHealthState_t
typedef uint8 EDmnHealthState_t;

# define Rte_TypeDef_EDmnChangeReqStatus_t
typedef uint8 EDmnChangeReqStatus_t;
#endif

#  ifndef eCanState_WakeupTransient
#   define eCanState_WakeupTransient (1U)
#  endif

// # define Rte_TypeDef_SDmnStatus
// typedef struct
// {
  // EDomainId dmnId;
  // EUclLinkState_t linkStatus;
  // SInt32 uclErrCode;
  // EDmnHealthState_t dmnHealthState;
  // ESystemState state;
  // EDmnOverallState_t dmnStatus;
// } SDmnStatus;

typedef enum
{
   CSM_E_OK,
   CSM_E_NOT_OK,
   CSM_E_BUSY,
   CSM_E_SMALL_BUFFER,
   CSM_E_ENTROPY_EXHAUSTION,
   CSM_E_KEY_NOT_AVAILABLE
}
Csm_ReturnType;

void RamTst_TestCompletedNotification(void);
void RamTst_TestErrorNotification(void);
//void ErrorCalloutHandler(void);

#  ifndef ePwrMode_ALL_CONTEXT
#   define ePwrMode_ALL_CONTEXT (4095U)
#  endif

#define PDUR_PDU_IPC_DIAGREQUEST_CAN2_DIAG                                                37U
#define PDUR_PDU_IPC_DIAGRESPONSE_USDT_CAN2_DIAG                                          21U
#define PDUR_PDU_HU6_CAN1                                                                 168U
#define PDUR_PDU_IPC13                                                                    81U
#define CANIF_PDU_IPC_DIAGRESPONSE_USDT_CAN2_DIAG            21U
#define CANIF_PDU_IPC13                                       62U
#ifndef ComConf_ComSignal_PowerModeStateStatus_oBCM_HUICTrailer_RC1_oIPC_7TFT_Digital_Common_5ea9aaa0_Rx
#define ComConf_ComSignal_PowerModeStateStatus_oBCM_HUICTrailer_RC1_oIPC_7TFT_Digital_Common_5ea9aaa0_Rx 825U
#endif

#  define Rte_Read_Request_SwcModeRequest_BswM_MDGP_MDG_Sfd_NvmBlockStatus_requestedMode Rte_Read_BswM_Request_SwcModeRequest_BswM_MDGP_MDG_Sfd_NvmBlockStatus_requestedMode
#  define Rte_Read_Request_SwcModeRequest_MG_SfdARole_Role Rte_Read_BswM_Request_SwcModeRequest_MG_SfdARole_Role

FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_EcuM_currentMode_currentMode(uint8 nextMode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define Rte_Switch_currentMode_currentMode Rte_Switch_EcuM_currentMode_currentMode

extern void MsgCntMaxNotifyStubs(uint16 CANID);
extern void RamTst_TestCompletedNotification(void);
extern void RamTst_TestErrorNotification(void);

extern void Spi_Seq0_End_Notification(void);
extern void Spi_Job0_End_Notification(void);
//extern void TmExt_UpdateFreeRunningCounter(void);

extern void ErrorCalloutHandler(
   uint16 ModuleId,
   uint8  InstanceId,
   uint8  ApiId,
   uint8  ErrorId);
   

extern void Appl_CanSM_BusOffEnd( NetworkHandleType  NetworkHandle );

extern FUNC(void, CDD_CODE) CDD_RxIndication(PduIdType RxPduId, P2CONST(PduInfoType, AUTOMATIC, CDD_APPL_DATA) PduInfoPtr);
extern void Dcm_Confirmation(Dcm_IdContextType ID, PduIdType PduID, Dcm_ConfirmationStatusType Confirmation);
extern Dcm_EcuStartModeType Dcm_GetProgConditions(Dcm_ProgConditionsPtrType progConditions);
extern Std_ReturnType Dcm_SetProgConditions(Dcm_ProgConditionsPtrType progConditions);
extern FUNC(void, GPT_CODE) WdgMExt_Wdg_66_IA_Cbk_GptNotificationTimeout(void);
extern FUNC(void, GPT_CODE) Wdg_66_IA_Cbk_GptNotificationTrigger(void);
extern FUNC(void, GPT_CODE) McuExt_StartupObs_Cbk_GptNotificationTimeout(void);


#endif

