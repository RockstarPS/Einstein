#ifndef RTE_STUBS_C
#define RTE_STUBS_C

#include "Std_Types.h"
#include "SciDrv.h"
#include "Dio.h"
#include "LinIf.h"
#include "LinNm.h"
#include "LinSm.h"
#include "LinStub.h"
#include "CanTp.h"
#include "Xcp.h"

void TmExt_MainFunction(void)
{
    
}

void Test_Comp_MainFunction(void)
{

}

void Dem_MasterMainFunction(void)
{
    
}

void Dem_SatelliteMainFunction(void)
{
    
}

void MemAbstract_MainFunction(void)
{
    
}


void OnDre_EnetRegReq(void)
{
    
}

void OnDre_IgnState(void)
{
    
}

void AppTaskStubRunnable(void)
{
    
}

void AudioTaskStubRunnable(void)
{
    
}

void CddTaskStubRunnable(void)
{
    
}

void FotaTaskStubRunnable(void)
{
    
}

void GaugeTaskStubRunnable(void)
{
    
}

#ifdef DSS_TEST_ENABLED
void DssDisplayTest(void);
#endif
void GraphicsTaskStubRunnable(void)
{
#ifdef DSS_TEST_ENABLED
    DssDisplayTest();
#endif
}

void IndTaskStubRunnable(void)
{

}

void LinTaskStubRunnable(void)
{
    Lin_DrvTest();
    LinIf_MainFunction();
    LinNm_MainFunction();
    LinSM_MainFunction();
    /* added CanTp here, should be moved to Rte */
    CanTp_MainFunction();
    Xcp_MainFunction();
}

void TripTaskStubRunnable(void)
{
    
}

void WarnTaskStubRunnable(void)
{
    
}

uint16 PmicAdcResult = 0;

void WdgMgntTaskStubRunnable(void)
{

    WdgM_MainFunction();
    WdgM_CheckpointReached(0,0);
    SciDrv_MainFunction(); 
    PmicCdd_MainFunction();

    /* test code for ADC */
    if(E_OK == PmicCdd_Adc_GetGroupStatus())
    {
        PmicCdd_Adc_ReadGroup(&PmicAdcResult);
    }
    PmicCdd_Adc_StartGroupConversion();
}

void Eep24xx_MainFunction(void);

void EepDrv_MainFunction(void)
{
    Eep24xx_MainFunction();
}

void MemAbstractMdl_MainFunction(void)
{
    
}

void NvMExt_Phase1ReadCompletionNotification(uint8 Status)
{
    
}

void NvMExt_Phase2ReadCompletionNotification(uint8 Status)
{
    
}

void NvMExt_Phase3ReadCompletionNotification(uint8 Status)
{
    
}

uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Audio_Element;
uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Communication_Element;
uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_EngOffTimer_Element;
uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_FuelGauge_Element;
uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Illumination_Element;
uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_OilGauge_Element;
uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_PowerGauge_Element;
uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Power_Element;
uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_RealTimeClock_Element;
uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_ServiceReminder_Element;
uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_SpeedoGauge_Element;
uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_TachoGauge_Element;
uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_TempGauge_Element;
uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_TripComputer_Element;
uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Warning_Element;
uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsCys_Certicificate_Element;
uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsDiag_Dtc_Element;
uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsDiag_ErrorRecord_Element;
uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsFuSa_Audio_Element;
uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsFuSa_Communication_Element;
uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsFuSa_Config_Element;
uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsFuSa_Display_Element;
uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsFuSa_Power_Element;
uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsFuSa_Warning_Element;
uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsFusa_Fota_Element;
uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Audio_Element;
uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Communication_Element;
uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Display_Element;
uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Gauges_Element;
uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Illumination_Element;
uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Odometer_Element;
uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Personalization_Element;
uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Power_Element;
uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_RealTimeClock_Element;
uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Tripcomputer_Element;
uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_VisDlt_Element;
uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Warning_Element;
uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_CusDlt_Element;
uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_FuelGauge_Element;
uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_Illumination_Element;
uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_Odometer_Element;
uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_OilGauge_Element;
uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_Personalization_Element;
uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_PowerGauge_Element;
uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_RealTimeClock_Element;
uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_SpeedoGauge_Element;
uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_TachoGauge_Element;
uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_TempGauge_Element;
uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_TripComputer_Element;
uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_Warning_Element;
uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_EcuPartNumber_Element;
uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaFinPrint_Element;
uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaMode_Element;
uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaStatus_Element;
uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotadecrypt_Element;
uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdReflash_Element;
uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_VehicleConfig_Element;
uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_VisMeet_Element;
uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_RefCys_Certicificate1_Element;
uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_RefCys_Certicificate_Element;







#endif /* RTE_STUBS_C */

