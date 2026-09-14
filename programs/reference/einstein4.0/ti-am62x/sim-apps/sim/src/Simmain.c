#ifndef MAIN_C
#define MAIN_C

// #define NVM_TRIPLE_BUFFER_TEST
#include "Stubs.h"
#include "Dio.h"
#include "Os.h"
#include "Spi.h"
#include "NvM.h"
#include "CddIpcAppRProcLinux.h"
#include "Ea.h"
#include "EepDrv.h"
#include "EcuM.h"
#include "I2c.h"
#include "Apm.h"
#include "EcuMExt.h"
#include "IoHwAb.h"
#include "LedDrv.h"
#include "sdl_esm.h"
#include "EccTest.h"
#include "NvMExt.h"
#include "SciDrv.h"
#include "sdl_esm_core.h"

#include "SemaphoreP.h"

#ifdef BOOT_KPI_LOG_EN
#include "boot_kpi_r5_asr.h"
#endif   /*BOOT_KPI_LOG_EN*/

// #ifdef NVM_TRIPLE_BUFFER_TEST
//   #include "Rte_MemAbstract_Stub_Safe.h"
// #endif

int main();

int main()
{
	printf("I am here \n");
	WindowsInitCriticalSection();
#ifdef GDT_INCLUDED	
	CreateHMIThread();
#endif	
#ifdef BOOT_KPI_LOG_EN
    BOOT_KPI_LOG(KPI_ID_VIP_MAIN, "VIP_MAIN");
#endif   /*BOOT_KPI_LOG_EN*/
#if defined(ECC_ICACHE_TEST) || defined(ECC_DCACHE_TEST)
    /* This part is the FIT test code for ICACHE and DCACHE test for ECC */
	/* Shall be enabled only for testing */
	while(BrkFlag == 1);
	if(TestEcc == 1)
	{
		EccTest_CacheTest();
	}
#endif 
    EcuM_Init();
    return 0;
}

/* Os Idle Task */
TASK(OsTask_IdleTask)
{
    while(1)
    {
		WindowsSetLowPriority();
    }
}

void CCDD_FitManager_Impl_MainFunction(void){}
void CCDD_McuFit_Impl_MainFunction(void){}
void Ctrl_Illumination_Task(void){}
void View_Illumination_Task(void){}
void TrustedSwc_MainFunction (void){}
void RstM_Impl_MainFunction (void){}
//Below stubs functions to be removed once the respective component integrated
// FUNC(Std_ReturnType, CWarnMsg_Core_Observer_CODE) CWarnMsg_Core_Observer_Impl_OnCommand(ECmpCmd cmdP)
// {

// }
// FUNC(Std_ReturnType, Ctrl_Illumination_CODE) Ctrl_Illumination_Impl_OnCommand(ECmpCmd cmdP)
// {

// }
// FUNC(Std_ReturnType, View_Illumination_CODE) View_Illumination_Impl_OnCommand(ECmpCmd cmdP)
// {

// }
Std_ReturnType  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CEcuWakeupM_Impl_OnCommand( uint8 Cmd )
{
	return E_OK;
}
Std_ReturnType  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CCmicCdd_Impl_OnCommand(uint8 Cmd )
{
	return E_OK;
}
Std_ReturnType  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CEsmCdd_Impl_OnCommand(  uint8 Cmd )
{
	return E_OK;
}
Std_ReturnType  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CCddIpc_Impl_OnCommand(  uint8 Cmd )
{
	return E_OK;
}
Std_ReturnType  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CDisplayCddExt_Impl_OnCommand(  uint8 Cmd )
{
	return E_OK;
}
Std_ReturnType  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CFaldDrv_Impl_OnCommand(  uint8 Cmd )
{
	return E_OK;
}
Std_ReturnType  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CDwaTT_Impl_OnCommand(  uint8 Cmd )
{
	return E_OK;
}
Std_ReturnType  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CSensorCdd_Impl_OnCommand(  uint8 Cmd )
{
	return E_OK;
}
Std_ReturnType  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CSwcIllum_Impl_OnCommand(  uint8 Cmd )
{
	return E_OK;
}
Std_ReturnType  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CAbsTT_Impl_OnCommand(  uint8 Cmd )
{
	return E_OK;
}
Std_ReturnType  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CBacklightDerating_Impl_OnCommand(  uint8 Cmd )
{
	return E_OK;
}
Std_ReturnType  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CBAC_Impl_OnCommand(  uint8 Cmd )
{
	return E_OK;
}
Std_ReturnType  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CSafeHmi_Impl_OnCommand(  uint8 Cmd )
{
	return E_OK;
}
Std_ReturnType  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CSafeHmiApp_Impl_OnCommand( uint8 Cmd )
{
	return E_OK;
}
Std_ReturnType  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CSwcDataAdapter_Impl_OnCommand( uint8 Cmd )
{
	return E_OK;
}
Std_ReturnType  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CFaldDrvCdd_Impl_OnCommand( uint8 Cmd )
{
	return E_OK;
}
Std_ReturnType  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CGdtCtrl_Impl_OnCommand( uint8 Cmd )
{
	return E_OK;
}
Std_ReturnType  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CEarlyHmi_Impl_OnCommand( uint8 Cmd )
{
	return E_OK;
}
Std_ReturnType  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CSwcDiag_Impl_OnCommand( uint8 Cmd )
{
	return E_OK;
}
Std_ReturnType  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CAppSlpIM_Impl_OnCommand( uint8 Cmd )
{
	return E_OK;
}
Std_ReturnType Rte_Call_rp_Init_rp_Init_Ctrl_Dim_Init(uint8 Cmd)
{
    return E_OK;
}

#ifndef RTCCDD_ENABLE
void CRtcCdd_Impl_MainFunction (void)
{

}
Std_ReturnType CRtcCdd_Impl_OnCommand(uint8 Cmd)
{
    return E_OK;
}
#endif


void DemExt_MainFunction (void){}

//EcuWakeupM Icu Stubs : will be removed once Icu integrated - bmalgeka
void Icu_SetMode(void){}
void Icu_EnableEdgeDetection(void){}
void Icu_DisableEdgeDetection(void){}
void Icu_GetInputState(void){}
void Icu_EnableWakeup(void){}
void Icu_DisableWakeup(void){}
void Icu_CheckWakeup(void){}
//void Icu_EnableNotification(void){}
//void Icu_DisableNotification(void){}
void Port_SetToDioMode(void){}
void Port_SetToAlternateMode(void){}
void Port_SetPinMode(void){}
//void OsTask_ModeMgtfunc(void){}
//void Ctrl_WSS_Impl_MainFunction(void){}
//void CCtrl_Telltale_Adapter_Task(void){}
//void CCtrl_Telltale_Impl_MainFunction(void){}                    
//void CView_Telltale_Impl_MainFunction(void){}                    
//void CWarnMsg_Core_Observer_Impl_MainFunction(void){}         
void CanIf_EnterCriticalSection(void){}                                               
void CanIf_ExitCriticalSection (void){}                                               
void CanSM_EnterCriticalSection(void){}                                               
void CanSM_ExitCriticalSection (void){}                                               
void ComM_EnterCriticalSection           (void){}                                      
void ComM_ExitCriticalSection     (void){}                                            
void Ctrl_Dim_Task   (void){}                                 
//void Ctrl_warning_Task  (void){}                              
void Det_MainFunction   (void){}                              
//void FastGaugeAdapter_Task  (void){}                          
//void Mdl_Airbag_Task     (void){}                                
//void Mdl_Dim_Task    (void){}                                 
//void Mdl_Gear_Task   (void){}                                 
void Mdl_Linear_Interpolation_Task (void){}                   
// void Mdl_SafetyAdapter_OnDataRx_B_EBW2     (void){}              
// void Mdl_SafetyAdapter_OnDataRx_B_PKBLP  (void){}                
// void Mdl_SafetyAdapter_OnDataRx_SCSBZR  (void){}                 
// void Mdl_SafetyAdapter_OnDataRx_VSCOFF (void){}                  
//void Mdl_SafetyAdapter_Task     (void){}                         
//void Mdl_Speed_Task   (void){}                                
//void Mdl_Tacho_Task (void){}                                  
void Mdl_TurnHazard_Task  (void){}                            
//void Mdl_wAirbag_Task   (void){}                              
//void Mdl_wFuelLidOpen_Task  (void){}                          
// void OnDre_UCL_HudWarnStatus  (void){}                        
// void OnDre_UCL_WarnStatus   (void){}                          
void SlowGaugeAdapter_Task  (void){}                          
//void View_Speed_Task      (void){}                            
//void WarnMsg_Core_TmrSupport_Task    (void){}   
void Com_IpduGroupControl (void){}
void Com_SetIpduGroup(void){}
void UserPreTaskHook(void)
{}
void UserPostTaskHook(void)
{
}
void UserPreISRHook(ISRType x)
{

}

void UserPostISRHook(ISRType x)
{

}
void CGdtCdd_Impl_MainFunction(void){}
void SchM_Enter_Cdd_Ipc_IPC_EXCLUSIVE_AREA_0(void){}
/**
 * \brief Used to exit interrupt protected area
 */
void SchM_Exit_Cdd_Ipc_IPC_EXCLUSIVE_AREA_0(void){}
Std_ReturnType DltExt_ResetInfo_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult ){}
int32_t SemaphoreP_pend(SemaphoreP_Object *obj, uint32_t timeout)
{
    return E_OK;;
}

void SemaphoreP_post(SemaphoreP_Object *obj)
{
    (void)obj;
    //ResumeAllInterrupts();
}



#endif
