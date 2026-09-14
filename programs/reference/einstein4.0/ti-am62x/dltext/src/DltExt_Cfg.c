/*****************************************************************************
 *                                                                            *
 *              CONFIDENTIAL VISTEON CORPORATION                              *
 *                                                                            *
 * This is an unpublished work of authorship, which contains trade            *
 * secrets, created in 2017. Visteon Corporation owns all rights to           *
 * this work and intends to maintain it in confidence to preserve             *
 * its trade secret status. Visteon Corporation reserves the right,           *
 * under the copyright laws of the United States or those of any              *
 * other country that may have jurisdiction, to protect this work             *
 * as an unpublished work, in the event of an inadvertent or                  *
 * deliberate unauthorized publication. Visteon Corporation also              *
 * reserves its rights under all copyright laws to protect this               *
 * work as a published work, when appropriate. Those having access            *
 * to this work may not copy it, use it, modify it or disclose the            *
 * information contained in it without the written authorization              *
 * of Visteon Corporation.                                                    *
 *                                                                            *
 ******************************************************************************/
/*****************************************************************************
 *  File Name         :  DltExt_Cfg.c                                             *
 *  Module Short Name :  DltExt_Cfg.c                                               *
 *  Description       :  This file contains implementations of the Diagnostic *
 *                       Log and Trace Extension                              *
 *                                                                            *
 * Organization     :  Driver Information Software Section,                   *
 *                     Visteon Software Operation                             *
 *                     Visteon Corporation                                    *
 *                                                                            *
 * ---------------------------------------------------------------------------*
 * Compiler Name    :  GHS Multi                                              *
 * Target Hardware  :  Platform Independent                                   *
 *                                                                            *
 ******************************************************************************/
#ifndef DLTEXT_CFG_C
#define DLTEXT_CFG_C

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Rte_DltExt.h"
#include "Rte_Dlt_Type.h"
#include "DltExt_Cfg.h"
#include "Mcu.h"
// #include "SNvM.h"
#include "EepDrv.h"
#include "NvM.h"
#include "NvMExt.h"

/**********************************************************************************************************************
 * Externed Functions *
 *********************************************************************************************************************/
#if(DLT_FAULTCOUNTER_ENABLE == STD_ON)
extern uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_HM_Flash_Checksum_Fault_Counter;
extern uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_HM_RAM_Checksum_Fault_Counter;
extern uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_HM_Peripheral_Fault_Counter;
extern uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_HM_Illegal_Opcode_Reset_Counter;
extern uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_HM_Power_ON_Reset_Counter;
extern uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_HM_Data_Range_Failure_Reset_Counter;
#endif

extern void NvmExt_GetNvMReadAllStatus(Boolean *status);
extern void Fls_MainFunction (void);
extern tDltExt_CounterInfo vCounterData;

/**********************************************************************************************************************
 * Type Declarations *
 *********************************************************************************************************************/

/*RAM Buffer for Application Log block and SW Hang block*/
uint8 DltExt_AppInfo[DLTEXT_SIZE_128BYTES];
uint8 DltExt_SWHangInfo[DLTEXT_SWHANG_SIZE];
uint8 DltExt_ResetInfo[DLTEXT_SIZE_256BYTES];
/*ROM Buffer for Application Log block and SW Hang block*/
uint8 DltExt_AppInfo_Init[DLTEXT_SIZE_128BYTES] = {0};
uint8 DltExt_SWHangInfo_Init[DLTEXT_SWHANG_SIZE] = {0};
uint8 DltExt_ResetInfo_Init[DLTEXT_SIZE_256BYTES]= {0};
boolean DltExt_NvM_Completed = FALSE;

const tDltExt_ConfigType DltExt_Config = {NUMCYCLICBUFF, BUFF_LENGTH, FAULTCNT_ENABLE};

#if(DLT_FAULTCOUNTER_ENABLE == STD_ON)
const tDltExt_ErrCodeCounterMap_Cfg vCounterMap_Cfg[DLT_NUM_ERROR_CFG] = {
    {DLT_FORCED_BLANK, NULL, NULL, FALSE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {DLT_POWER_UP_STATE, NULL, NULL, FALSE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {DLT_POWER_DOWN_STATE, NULL, NULL, FALSE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {DLT_ILLUMINATION_VALUE, NULL, NULL, FALSE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {DLT_NVM_STATUS, NULL, NULL, FALSE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {DLT_FEATURE_SLEEP_STATUS, NULL, NULL, FALSE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {DLT_NETWORK_STATUS, NULL, NULL, FALSE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {DLT_WAKEUP_REASON, NULL, NULL, FALSE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {DLT_HMISTATUS, NULL, NULL, FALSE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {DLT_MAGIC_FLAGSTATUS, NULL, NULL, FALSE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {DLT_UNAASIGNED1, NULL, NULL, FALSE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {DLT_UNAASIGNED2, NULL, NULL, FALSE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {DLT_UNAASIGNED3, NULL, NULL, FALSE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {DLT_UNAASIGNED4, NULL, NULL, FALSE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {DLT_UNEXPECTED_ERROR, NULL, NULL, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {DLT_DISPLAY_ERROR, NULL, NULL, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {DLT_TEMP_ERROR, NULL, NULL, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {DLT_VOLTAGE_ERROR, NULL, NULL, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {DLT_SAFETY_ERROR, NULL, NULL, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {DLT_SECURITY_ERROR, NULL, NULL, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {DLT_CPU_UTILISATION_ERROR, NULL, NULL, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {DLT_NETWORK_ERROR, NULL, NULL, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {DLT_PERIPHERAL_ERROR, NULL, NULL, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {DLT_BACKLIGHT_ERROR, NULL, NULL, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {DLT_POWERUP_DOWN_ERROR, NULL, NULL, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {DLT_TIMEOUT_EVENT_MISSING_ERRORS, NULL, NULL, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {DLT_IPCL_VERSION_MISMATCH, NULL, NULL, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {DLT_HEALTH_MON_ERROR, NULL, NULL, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {DLT_UCL_FATAL_ERROR, NULL, NULL, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {DLT_UCL_ERROR_STATUS, NULL, NULL, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {DLT_SOTA_OTA_FOTA_ERROR, NULL, NULL, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {DLT_UNAASIGNED5, NULL, NULL, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {DLT_UNAASIGNED6, NULL, NULL, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {DLT_UNAASIGNED7, NULL, NULL, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {DLT_FOTA_RESET, &vCounterData.DltExt_Generic_Reset_Counter, NULL, FALSE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {DLT_DIAG_RESET, &vCounterData.DltExt_Generic_Reset_Counter, NULL, FALSE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {DLT_RAM_TST_ERROR, &vCounterData.DltExt_Generic_Reset_Counter, NULL, FALSE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {DLT_CAN_LOOP_TEST_ERROR, &vCounterData.DltExt_Generic_Reset_Counter, NULL, FALSE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {DLT_CORE_SYS_TST_ERROR, &vCounterData.DltExt_Generic_Reset_Counter, NULL, FALSE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {DLT_WAKEUP_SEQ_TIMELIMIT_FAULT, &vCounterData.DltExt_Generic_Reset_Counter, NULL, FALSE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {DLT_TFT_RECOVERY_TIMELIMIT_FAULT, &vCounterData.DltExt_Generic_Reset_Counter, NULL, FALSE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {DLT_NVM_WRITE_TIMEOUT_FAULT, &vCounterData.DltExt_Generic_Reset_Counter, NULL, FALSE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {DLT_ADC_TEST, &vCounterData.DltExt_Generic_Reset_Counter, NULL, FALSE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {DLT_WATCHDOG_TIMER_TEST, &vCounterData.DltExt_Generic_Reset_Counter, NULL, FALSE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {DLT_CM_TEST, &vCounterData.DltExt_Generic_Reset_Counter, NULL, FALSE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {DLT_DMA_TEST, &vCounterData.DltExt_Generic_Reset_Counter, NULL, FALSE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {DLT_PPU_TEST, &vCounterData.DltExt_Generic_Reset_Counter, NULL, FALSE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {DLT_POWER_SUPPLY_FAULT, &vCounterData.DltExt_Generic_Reset_Counter, NULL, FALSE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {DLT_ECC_FAULT, &vCounterData.DltExt_Generic_Reset_Counter, NULL, FALSE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE}};
#endif

const tDlt_App_error_Catagory App_error_Catagory[NUM_TYPE_CODES] = {
    {DLT_APPLICATION_INFO,  0, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {DLT_APPLICATION_ERROR, 0, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {DLT_FAULT_FORCED_RESET, 0, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {DLT_FAULT_ARM_ERROR, 0, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {DLT_FAULT_NVM_ERROR, 0, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {DLT_FAULT_HW_RESET, 0, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {DLT_FAULT_OS_ERROR, 0, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE}};

#if (DLTEXT_CFG_KPI_PRESENT == STD_ON)
const tDlt_KPI_Catagory vKPIData_Cfg[DLTEXT_NUM_KPI] = {
    {DLT_KPI_STARTUP_TIME_COLD_BOOT, DLTEXT_KPI1_SIZE, 0U, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE,0x01u,(boolean)TRUE },
    {DLT_KPI_STARTUP_TIME_WARM_BOOT, DLTEXT_KPI2_SIZE, 0U, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE,0x02u, (boolean)TRUE },
    {DLT_KPI_DISPLAY_UP_COLD_BOOT, DLTEXT_KPI3_SIZE, 0U, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE,0x00u,(boolean)TRUE },
    {DLT_KPI_SHUTDOWN_TIME, DLTEXT_KPI4_SIZE, 0U, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE,0x01u,(boolean)TRUE}};

const tDltExt_KPI_Config KPI_Metrix_Cfg[DLTEXT_NUM_KPI_METRIC] = {
    {DLT_KPI_STARTUP_TIME_COLD_BOOT,1,0x1111},
    {DLT_KPI_STARTUP_TIME_COLD_BOOT,2,0X1112},
    {DLT_KPI_STARTUP_TIME_COLD_BOOT,3,0x1113},
    {DLT_KPI_STARTUP_TIME_COLD_BOOT,4,0x1114},
    {DLT_KPI_STARTUP_TIME_COLD_BOOT,5,0x1115},
    {DLT_KPI_STARTUP_TIME_COLD_BOOT,6,0x1111},
    {DLT_KPI_STARTUP_TIME_COLD_BOOT,7,0X1112},
    {DLT_KPI_STARTUP_TIME_COLD_BOOT,8,0x1113},
    {DLT_KPI_STARTUP_TIME_COLD_BOOT,9,0x1114},
    {DLT_KPI_STARTUP_TIME_COLD_BOOT,10,0x1115},
    {DLT_KPI_STARTUP_TIME_WARM_BOOT,1,0xaaaa},
    {DLT_KPI_STARTUP_TIME_WARM_BOOT,2,0xbbbb},
    {DLT_KPI_STARTUP_TIME_WARM_BOOT,3,0xcccc},
    {DLT_KPI_STARTUP_TIME_WARM_BOOT,4,0xdddd},
    {DLT_KPI_STARTUP_TIME_WARM_BOOT,5,0xeeee},
    {DLT_KPI_DISPLAY_UP_COLD_BOOT,1,0xf1f1},
    {DLT_KPI_DISPLAY_UP_COLD_BOOT,2,0x2f2f},
    {DLT_KPI_DISPLAY_UP_COLD_BOOT,3,0x3f3f},
    {DLT_KPI_DISPLAY_UP_COLD_BOOT,4,0x4f4f},
    {DLT_KPI_DISPLAY_UP_COLD_BOOT,5,0x5f5f},
    {DLT_KPI_SHUTDOWN_TIME,1,0x6f6f},
    {DLT_KPI_SHUTDOWN_TIME,2,0x7f7f},
    {DLT_KPI_SHUTDOWN_TIME,3,0x8f8f},
    {DLT_KPI_SHUTDOWN_TIME,4,0x9f9f},
    {DLT_KPI_SHUTDOWN_TIME,5,0xafaf},
    {DLT_KPI_SHUTDOWN_TIME,6,0x6f6f},
    {DLT_KPI_SHUTDOWN_TIME,7,0x7f7f},
    {DLT_KPI_SHUTDOWN_TIME,8,0x8f8f},
    {DLT_KPI_SHUTDOWN_TIME,9,0x9f9f},
    {DLT_KPI_SHUTDOWN_TIME,0xA,0xafaf},
    {DLT_KPI_SHUTDOWN_TIME,0xB,0x6f6f},
    {DLT_KPI_SHUTDOWN_TIME,0xC,0x7f7f},
    {DLT_KPI_SHUTDOWN_TIME,0xD,0x8f8f},
    {DLT_KPI_SHUTDOWN_TIME,0xE,0x9f9f},
    {DLT_KPI_SHUTDOWN_TIME,0xF,0xafaf},
    {DLT_KPI_SHUTDOWN_TIME,0x10,0xafaf}};
#endif /* DLTEXT_CFG_KPI_PRESENT == STD_ON */

#if(HARDWARE_FAULTS_EN == STD_ON)

const ResetTypeTable ResetReasonFault[NUM_HW_FAULTS]=
{
/*	Index 1	*/	{	MCU_RESET_UNDEFINED,			  0xFC01	},
/*	Index 2	*/	{	MCU_POWER_ON_RESET,			      0xFC02	},

    #if(DLTEXT_PLATFORM_IMX8 == STD_ON)
    /*	Index 3	*/  { MCU_JTAG_RESET,                   0xFC02 },   
    /*	Index 4	*/  { MCU_SOFTWARE_RESET,               0xFC03 },
    /*	Index 5	*/  { MCU_WATCHDOG_RESET,               0xFC04 },
    /*	Index 6	*/  { MCU_LOCKUP_RESET,                 0xFC05 },
    /*	Index 7	*/  { MCU_SNVS_RESET,                   0xFC06 },
    /*	Index 8	*/  { MCU_TEMP_RESET,                   0xFC07 },
    /*	Index 9	*/  { MCU_MSI_RESET,                    0xFC08 },
    /*	Index 10*/  { MCU_UECC_RESET,                   0xFC09 },
    /*	Index 11*/  { MCU_SCFW_WDOG_RESET,              0xFC0A },
    /*	Index 12*/  { MCU_ROM_WDOG_RESET,               0xFC0B },
    /*	Index 13*/  { MCU_SECO_RESET,                   0xFC0C },
    /*	Index 14*/  { MCU_SCFW_FAULT_RESET,             0xFC0D }
    #elif(DLTEXT_PLATFORM_TRAVEO2 == STD_ON)
    /*	Index 3	*/	{	MCU_WATCHDOG_RESET,			    0xFC09	},
    /*	Index 4	*/	{	MCU_ACT_FAULT_RESET,			0xFC08	},
    /*	Index 5	*/	{	MCU_DPSLP_FAULT_RESET,			0xFC08	},
    /*	Index 6	*/	{	MCU_TEST_DEBUG_RESET,			0xFC07	},
    /*	Index 7	*/	{	MCU_SW_RESET,			        0		},
    /*	Index 8	*/	{	MCU_MCWDT0_RESET,				0xFC0A	},
    /*	Index 9	*/	{	MCU_MCWDT1_RESET,				0xFC0A	},
    /*	Index 10 */	{	MCU_MCWDT2_RESET,				0xFC0A	},
    /*	Index 11 */	{	MCU_MCWDT3_RESET,				0xFC0A	},
    /*	Index 12 */	{	MCU_XRES_RESET,					0xFC02	},
    /*	Index 13 */	{	MCU_BOD_VDDD_RESET,				0xFC03	},
    /*	Index 14 */	{	MCU_BOD_VDDA_RESET,				0xFC03	},
    /*	Index 15 */	{	MCU_BOD_VCCD_RESET,				0xFC03	},
    /*	Index 16 */	{	MCU_OVD_VDDD_RESET,				0xFC04	},
    /*	Index 17 */	{	MCU_OVD_VDDA_RESET,				0xFC04	},
    /*	Index 18 */	{	MCU_OVD_VCCD_RESET,				0xFC04	},
    /*	Index 19 */	{	MCU_OCD_ACTIVE_REGULATOR_RESET,	0xFC05	},
    /*	Index 20 */	{	MCU_OCD_DEEPSLEEP_REGULATOR_RESET,			0xFC05	},
    /*	Index 21 */	{	MCU_STRUCTURAL_XRES_RESET,					0xFC02	},
    /*	Index 22 */	{	MCU_CSV_HF_RESET,							0xFC0B	},
    /*	Index 23 */	{	MCU_CSV_REF_RESET,							0xFC0C	},
    /*	Index 24 */	{	MCU_WAKEUP_RESET,								0	},
    /*	Index 25 */	{	MCU_REGHC_OCD_RESET,							0	},
    /*	Index 26 */	{	MCU_REGHC_PMIC_RESET,							0	},
    /*	Index 27 */	{	MCU_PXRES_RESET,				0xFC02	}
    #endif 
};

#endif /* HARDWARE_FAULTS_EN */

// PmicCdd reset related FaultID configurations based on the enum PmicCdd_ResetReasonType
const FaultIdListType PmicCddResetFaultIds =
{
    .FaultIds = 
    {
        POWER_ON_RESET,
        EXT_WDG_RESET,
        PMIC_SLEEP_RESET,
        FLTM_E_BUCK1_OVUV,
        FLTM_E_BUCK2_OVUV,
        FLTM_E_BUCK3_OVUV,
        FLTM_E_BUCK4_OVUV,
        FLTM_E_LDO1_OVUV,
        FLTM_E_LDO2_OVUV,
        FLTM_E_LDO3_OVUV,
        FLTM_E_VVCA_OVUV,
        FLTM_E_VMON1_OVUV,
        POWER_SUPPLY_FAULT,
        FLTM_E_PMIC_ABIST_FAIL
    },
    .NumFaults = 14U
};
/* Callback configured for Application log info block*/
Std_ReturnType DltExt_NvM_JobFinished(uint8 ServiceId, NvM_RequestResultType JobResult)
{
    Std_ReturnType flRetVal = E_NOT_OK;

    (void)ServiceId;

    if (JobResult == NVM_REQ_PENDING)
    {
        DltExt_NvM_Completed = FALSE;
        flRetVal = E_NOT_OK;
    }
    else
    {
        DltExt_NvM_Completed = TRUE;
        flRetVal = E_OK;
    }
    return flRetVal;
}
 
/* Callback configured for SW hang info block*/
Std_ReturnType DltExt_NvM_SWHang_JobFinished(uint8 ServiceId, NvM_RequestResultType JobResult)
{
    /* since no idication is required, return E_OK*/
    return E_OK;
}
/*============================================================================
**
** Function Name    :   DltExt_ResetLogDataStatus
**
** Visibility       :   Public
**
** Description      :   The DltExt_ResetLogDataStatus function is called to know if the message is
**                      critical or non-critical.
**
** Invocation       :
**
** Inputs           : Log_Level
**
** Outputs          : boolean ResetLogData_Flag 
**
** Critical Section :
**
**==========================================================================*/
boolean DltExt_ResetLogDataStatus(Dlt_MessageLogLevelType LogLevel)
{
    boolean ResetLogData_Flag = FALSE;
    
    if (LogLevel == DLT_LOG_FATAL)
    {
        ResetLogData_Flag = TRUE; // Critical Fault Codes Store it in the ResetLogData cyclic buffer
    }
    else if (((LogLevel == DLT_LOG_ERROR) ||(LogLevel == DLT_LOG_WARN)) ||(LogLevel == DLT_LOG_INFO))
    {
        ResetLogData_Flag = FALSE;
    }
    else
    {

    }

    return ResetLogData_Flag;
}

#if(DLTEXT_CFG_NVM_BLOCKS_PRESENT == STD_ON)
/*============================================================================
**
** Function Name    :   DltExt_AppInfoGetNvMReadyStatus
**
** Visibility       :   Public
**
** Description      :   The DltExt_AppInfoGetNvMReadyStatus function is called to know if the NvM is
**                      Ready or not to read application log info
**
** Invocation       :
**
** Inputs           : 
**
** Outputs          : Return_NvMReady
**
** Critical Section :
**
**==========================================================================*/
boolean DltExt_AppInfoGetNvMReadyStatus(void)
{
    boolean Return_NvMReady = FALSE;
    boolean NvmReadStatusFlag = FALSE;

    DLTEXT_GETNVMREADALLSTATUS((boolean *)&NvmReadStatusFlag);

    if (TRUE == NvmReadStatusFlag)
    {
        Return_NvMReady = TRUE;
    }

    return Return_NvMReady;
}

/*============================================================================
**
** Function Name    :   DltExt_ResetInfoGetNvMReadyStatus
**
** Visibility       :   Public
**
** Description      :   The DltExt_ResetInfoGetNvMReadyStatus function is called to know if the NvM is
**                      Ready or not to read reset log
**
** Invocation       :
**
** Inputs           : 
**
** Outputs          : Return_NvMReady
**
** Critical Section :
**
**==========================================================================*/
boolean DltExt_ResetInfoGetNvMReadyStatus(void)
{
    boolean Return_NvMReady = FALSE;    
    Return_NvMReady = DLTEXT_GETRESETNVMREADALLSTATUS();

    return Return_NvMReady;
}
void DltExt_AppInfoNvMWriteStarted(void)
{
    DltExt_NvM_Completed = FALSE;
}

//----------------------------------------------------------------------------------------------------------------------
/// @brief Check if NVM Jobs associated with Dlt Module are completed
///
/// @param void
///
/// @return boolean - TRUE if NVM jobs are completed; FALSE if not completed
//----------------------------------------------------------------------------------------------------------------------
boolean DltExt_isNVMJobCompleted_Data(void)
{
    boolean bRetVal;

    bRetVal = DltExt_NvM_Completed;

    return bRetVal;
}
#endif


#if(DLT_FAULTCOUNTER_ENABLE == STD_ON)
//----------------------------------------------------------------------------------------------------------------------
/// @brief Check if NVM Jobs associated with Dlt Module are completed
///
/// @param void
///
/// @return boolean - TRUE if NVM jobs are completed; FALSE if not completed
//----------------------------------------------------------------------------------------------------------------------
boolean DltExt_isNVMJobCompleted_Counter(void)
{
    boolean bRetVal;
    uint8 uOverallJobStatus = 0u;
    /* If NVM Job completes Job Status is 0. Combine all Job status used by DLT
     * to determine the overall result 
     * With bitWise OR, only if all values are zero, result will be zero */
    uOverallJobStatus = (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_HM_Flash_Checksum_Fault_Counter|
                        Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_HM_RAM_Checksum_Fault_Counter|
                        Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_HM_Peripheral_Fault_Counter|
                        Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_HM_Illegal_Opcode_Reset_Counter|
                        Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_HM_Power_ON_Reset_Counter|
                        Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_HM_Data_Range_Failure_Reset_Counter);
    /* Determing result after combining job statuses */
    if (uOverallJobStatus != 0u)
    {
        bRetVal = FALSE;
    }
    else
    {
        bRetVal = TRUE;
    }

    return bRetVal;
}
#endif

/*============================================================================
**
** Function Name    :   NvmExt_BlockWriteOnException
**
** Visibility       :   Public
**
** Description      :   The DltExt_ResetLogDataStatus function is called to know if the message is
**                      critical or non-critical.
**
** Invocation       :
**
** Inputs           : Log_Level
**
** Outputs          : boolean ResetLogData_Flag 
**
** Critical Section :
**
**==========================================================================*/
void NvmExt_BlockWriteOnException(uint16 NvBlockId_u16)
{
    (void)NvMExt_WriteBlock(NvBlockId_u16, NULL_PTR);

    do
    {
        NvM_MainFunction();
        NvMExt_MainFunction();
        EepDrv_MainFunction();
    } while ((MEMIF_IDLE != EepDrv_GetStatus())||(EepDrv_GetJobResult() != MEMIF_JOB_OK));
}

boolean DltExt_ShouldStoreResetHistory(const uint8 *pBuffer, uint16 message_length, Dlt_MessageLogLevelType LogLevel)
{
  boolean RetVal = FALSE;
  uint8 FaultStatusNibble;
 
  if ((pBuffer != NULL_PTR) && (message_length > 0u))
  {
    FaultStatusNibble = (pBuffer[0] & DLTEXT_FAULT_STATUS_MASK) >> DLTEXT_FAULT_STATUS_SHIFT;
 
    if ((LogLevel == DLT_LOG_FATAL) && (FaultStatusNibble == DLTEXT_FAULT_STATUS_ACTIVE_NIBBLE))
    {
      RetVal = TRUE;
    }
  }
 
  return RetVal;
}
#endif /* DLTEXT_CFG_C */
