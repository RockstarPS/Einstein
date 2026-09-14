#ifndef STUBS_H
#define STUBS_H

#include "Std_Types.h"
//typedef uint16       PduIdType;
#include "Rte_Type.h"
#include "OsTypes.h"
#include "OsPrvTypes.h"
#define NO_OF_BNG_BLOCK                               2
#define GptConf_GptChannelConfiguration_GptChannelConfiguration_TmExt_80Mhz 0
#define TMEXT_GET_CURRENT_TIME_IN_US 0U
//#define IOHWAB_FIRST_MUX_GROUP_ID 0u
//#define IOHWAB_MUX_DELAY_TIMER 10u
//#define IOHWAB_MUX_DELAY_TIME_USEC 100u
//#define IOHWAB_MUX_TIMER_FREQ_MHZ 15u
#define OS_CORE_0_OS_ACCESS_ID		0x00u
#define TASK_EXTENDED         1
#define Rte_Al_TE_UclProxyCdd_CUclProxyCdd_Impl_MainFunction (20U)
#define BUS_MEM_USAGE_FAULT_ENABLE   0x70000uL


typedef uint8 SfdA_RequestRoleType;
typedef uint8 BswM_MDG_Sfd_NvmBlockStatus;
extern void CDD_GetApmTimerCount(uint32* Timer);
typedef uint8 TPulseClientId;
#define APM_SYSTEM_ISR_ID     0U
/**< Mode for the Watchdog Interface */
#if 0
typedef enum {
    WDGIF_OFF_MODE  = 0u  /**< Watchdog disabled */
  , WDGIF_SLOW_MODE = 1u  /**< Long timeout period (slow triggering) */
  , WDGIF_FAST_MODE = 2u  /**< Short timeout period (fast triggering) */
} WdgIf_ModeType; /* PRQA S 3205 */
#endif

extern void PreTaskHook( void );
extern void PostTaskHook( void );
extern void UserPreISRHook(uint32 x);
extern void UserPostISRHook(uint32 x);
extern void SafeBswHook_OsApplicationErrorHook(osErrParamType x);
extern uint8 SafeBswHook_OsProtectionErrorHook(ProtectionErrType x);
extern Std_ReturnType Rte_Switch_Switch_BswM_SfdaMode_MG_SfdAMode(uint8 mode);
extern Std_ReturnType Rte_Read_Request_SwcModeRequest_MG_SfdARole_Role(SfdA_RequestRoleType *data);
extern Std_ReturnType Rte_Switch_Switch_BswM_SfdaRole_MG_SfdARole(SfdA_RequestRoleType mode);
extern Std_ReturnType Rte_Read_Request_SwcModeRequest_BswM_MDGP_MDG_Sfd_NvmBlockStatus_requestedMode(BswM_MDG_Sfd_NvmBlockStatus *data);
extern uint8 Rte_Mode_Notification_currentMode_currentMode(void);
extern Std_ReturnType OsTrustedCall_IoHwAb_SetOutputPin(IoHwAb_DOutSignalIdType Arg1,boolean Arg2,IoHwAb_ErrorType* Arg3);
extern void osExitPrivilegeModeAsm(void);
extern osuint32 osGetCONTROL(void);
#endif

