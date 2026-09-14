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
 *  File Name         :  DltExt_Cfg.h                                             *
 *  Module Short Name :  DltExt_Cfg.h                                               *
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
#ifndef DLTEXT_CFG_H
#define DLTEXT_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Dlt_Cfg.h"
#include "DltExt_Types.h"
#include "NvMExt.h"

/*****************************************************************************
 *                                 Macro Definitions                          *
 *----------------------------------------------------------------------------*
 * Definition of macro shall be followed by a comment that explains the       *
 * purpose of the macro.                                                      *
 ******************************************************************************/
#  ifndef EUclLinkState_Down
#   define EUclLinkState_Down (1U)
#  endif

#  ifndef EUclLinkState_Up
#   define EUclLinkState_Up (2U)
#  endif

#define UclLinkStateL_Down                                  EUclLinkState_Down
#define UclLinkStateL_Up                                    EUclLinkState_Up

/***************************Enable the DLT BURAM Storage*************************************/
#define BURAM_ENABLE                                STD_OFF

/*Below macros confirm and remove*/
#define NUMCYCLICBUFF       2u
#define BUFF_LENGTH         0xffu
#define FAULTCNT_ENABLE     1u
#define FAULTCNT_DISABLE    0u

/* Fault categoty types*/
#define DLT_KPI_CATEGORY                  0xFD
#define DLT_APPLICATION_INFO              0xF1
#define DLT_APPLICATION_ERROR             0xF2
#define DLT_FAULT_FORCED_RESET            0xF3
#define DLT_FAULT_ARM_ERROR               0xF4
#define DLT_FAULT_NVM_ERROR               0xF5
#define DLT_FAULT_HW_RESET                0xF6
#define DLT_FAULT_OS_ERROR                0xF7

/* Filter Category */
#define CAT_FILTER_EN         0x00000001u
#define CAT_F6                0x00000002u
#define CAT_F7                0x00000004u
#define CAT_F9                0x00000008u
#define CAT_FA                0x00000010u
#define CAT_FB                0x00000020u
#define CAT_FC                0x00000040u
#define CAT_FD                0x00000080u
#define CAT_FF                0x00000100u

#define DLTEXT_FILER_CATEGORIES   (CAT_FILTER_EN |CAT_F6 | CAT_F7 | CAT_F9 | CAT_FA | CAT_FB | CAT_FC | CAT_FD | CAT_FF)

#define DLTEXT_USE_NVM              STD_ON
#define DLTEXT_USE_UCL              STD_OFF
#define DLTEXT_PLATFORM_IMX8        STD_OFF
#define DLTEXT_PLATFORM_TRAVEO2     STD_OFF
#define DLTEXT_USE_ERROR_CFG        STD_OFF
#define DLT_WRITE_GIPCONSOL_ENABLE  STD_OFF
     
/*************************************************/

#define DLT_MAKE_FAULT_CODE(fault_type, fault_code) ((((uint16)(fault_type)) << DLT_FAULT_TYPE_OFST) | (fault_code))
#define DLT_FORCED_BLANK (DLT_MAKE_FAULT_CODE(DLT_APPLICATION_INFO, (0x01u)))
#define DLT_POWER_UP_STATE (DLT_MAKE_FAULT_CODE(DLT_APPLICATION_INFO, (0x02u)))
#define DLT_POWER_DOWN_STATE (DLT_MAKE_FAULT_CODE(DLT_APPLICATION_INFO, (0x03u)))
#define DLT_ILLUMINATION_VALUE (DLT_MAKE_FAULT_CODE(DLT_APPLICATION_INFO, (0x04u)))
#define DLT_NVM_STATUS (DLT_MAKE_FAULT_CODE(DLT_APPLICATION_INFO, (0x05u)))
#define DLT_FEATURE_SLEEP_STATUS (DLT_MAKE_FAULT_CODE(DLT_APPLICATION_INFO, (0x06u)))
#define DLT_NETWORK_STATUS (DLT_MAKE_FAULT_CODE(DLT_APPLICATION_INFO, (0x07u)))
#define DLT_WAKEUP_REASON (DLT_MAKE_FAULT_CODE(DLT_APPLICATION_INFO, (0x08u)))
#define DLT_HMISTATUS (DLT_MAKE_FAULT_CODE(DLT_APPLICATION_INFO, (0x09u)))
#define DLT_MAGIC_FLAGSTATUS (DLT_MAKE_FAULT_CODE(DLT_APPLICATION_INFO, (0x0Au)))
#define DLT_UNAASIGNED1 (DLT_MAKE_FAULT_CODE(DLT_APPLICATION_INFO, (0x0Cu)))
#define DLT_UNAASIGNED2 (DLT_MAKE_FAULT_CODE(DLT_APPLICATION_INFO, (0x0Du)))
#define DLT_UNAASIGNED3 (DLT_MAKE_FAULT_CODE(DLT_APPLICATION_INFO, (0x0Eu)))
#define DLT_UNAASIGNED4 (DLT_MAKE_FAULT_CODE(DLT_APPLICATION_INFO, (0x0Fu)))
#define DLT_UNEXPECTED_ERROR (DLT_MAKE_FAULT_CODE(DLT_APPLICATION_ERROR, (0x01u)))
#define DLT_DISPLAY_ERROR (DLT_MAKE_FAULT_CODE(DLT_APPLICATION_ERROR, (0x02u)))
#define DLT_TEMP_ERROR (DLT_MAKE_FAULT_CODE(DLT_APPLICATION_ERROR, (0x03u)))
#define DLT_VOLTAGE_ERROR (DLT_MAKE_FAULT_CODE(DLT_APPLICATION_ERROR, (0x04u)))
#define DLT_SAFETY_ERROR (DLT_MAKE_FAULT_CODE(DLT_APPLICATION_ERROR, (0x05u)))
#define DLT_SECURITY_ERROR (DLT_MAKE_FAULT_CODE(DLT_APPLICATION_ERROR, (0x06u)))
#define DLT_CPU_UTILISATION_ERROR (DLT_MAKE_FAULT_CODE(DLT_APPLICATION_ERROR, (0x07u)))
#define DLT_NETWORK_ERROR (DLT_MAKE_FAULT_CODE(DLT_APPLICATION_ERROR, (0x08u)))
#define DLT_PERIPHERAL_ERROR (DLT_MAKE_FAULT_CODE(DLT_APPLICATION_ERROR, (0x09u)))
#define DLT_BACKLIGHT_ERROR (DLT_MAKE_FAULT_CODE(DLT_APPLICATION_ERROR, (0x0Au)))
#define DLT_POWERUP_DOWN_ERROR (DLT_MAKE_FAULT_CODE(DLT_APPLICATION_ERROR, (0x0Bu)))
#define DLT_TIMEOUT_EVENT_MISSING_ERRORS (DLT_MAKE_FAULT_CODE(DLT_APPLICATION_ERROR, (0x0Cu)))
#define DLT_IPCL_VERSION_MISMATCH (DLT_MAKE_FAULT_CODE(DLT_APPLICATION_ERROR, (0x0Du)))
#define DLT_HEALTH_MON_ERROR (DLT_MAKE_FAULT_CODE(DLT_APPLICATION_ERROR, (0x0Fu)))
#define DLT_UCL_FATAL_ERROR (DLT_MAKE_FAULT_CODE(DLT_APPLICATION_ERROR, (0x10u)))
#define DLT_UCL_ERROR_STATUS (DLT_MAKE_FAULT_CODE(DLT_APPLICATION_ERROR, (0x11u)))
#define DLT_SOTA_OTA_FOTA_ERROR (DLT_MAKE_FAULT_CODE(DLT_APPLICATION_ERROR, (0x12u)))
#define DLT_UNAASIGNED5 (DLT_MAKE_FAULT_CODE(DLT_APPLICATION_ERROR, (0x13u)))
#define DLT_UNAASIGNED6 (DLT_MAKE_FAULT_CODE(DLT_APPLICATION_ERROR, (0x14u)))
#define DLT_UNAASIGNED7 (DLT_MAKE_FAULT_CODE(DLT_APPLICATION_ERROR, (0x15u)))
#define DLT_FOTA_RESET (DLT_MAKE_FAULT_CODE(DLT_FAULT_FORCED_RESET, (0x03u)))
#define DLT_DIAG_RESET (DLT_MAKE_FAULT_CODE(DLT_FAULT_FORCED_RESET, (0x04u)))
#define DLT_RAM_TST_ERROR (DLT_MAKE_FAULT_CODE(DLT_FAULT_FORCED_RESET, (0x05u)))
#define DLT_CAN_LOOP_TEST_ERROR (DLT_MAKE_FAULT_CODE(DLT_FAULT_FORCED_RESET, (0x06u)))
#define DLT_CORE_SYS_TST_ERROR (DLT_MAKE_FAULT_CODE(DLT_FAULT_FORCED_RESET, (0x09u)))
#define DLT_WAKEUP_SEQ_TIMELIMIT_FAULT (DLT_MAKE_FAULT_CODE(DLT_FAULT_FORCED_RESET, (0x0Au)))
#define DLT_TFT_RECOVERY_TIMELIMIT_FAULT (DLT_MAKE_FAULT_CODE(DLT_FAULT_FORCED_RESET, (0x0Bu)))
#define DLT_NVM_WRITE_TIMEOUT_FAULT (DLT_MAKE_FAULT_CODE(DLT_FAULT_FORCED_RESET, (0x0Cu)))
#define DLT_ADC_TEST (DLT_MAKE_FAULT_CODE(DLT_FAULT_FORCED_RESET, (0x0Du)))
#define DLT_WATCHDOG_TIMER_TEST (DLT_MAKE_FAULT_CODE(DLT_FAULT_FORCED_RESET, (0x0Eu)))
#define DLT_CM_TEST (DLT_MAKE_FAULT_CODE(DLT_FAULT_FORCED_RESET, (0x0Fu)))
#define DLT_DMA_TEST (DLT_MAKE_FAULT_CODE(DLT_FAULT_FORCED_RESET, (0x10u)))
#define DLT_PPU_TEST (DLT_MAKE_FAULT_CODE(DLT_FAULT_FORCED_RESET, (0x11u)))
#define DLT_POWER_SUPPLY_FAULT (DLT_MAKE_FAULT_CODE(DLT_FAULT_FORCED_RESET, (0x12u)))
#define DLT_ECC_FAULT (DLT_MAKE_FAULT_CODE(DLT_FAULT_FORCED_RESET, (0x13u)))
#define DLT_KPI_STARTUP_TIME_COLD_BOOT (DLT_MAKE_FAULT_CODE(DLT_KPI_CATEGORY, (0x01u)))
#define DLT_KPI_STARTUP_TIME_WARM_BOOT (DLT_MAKE_FAULT_CODE(DLT_KPI_CATEGORY, (0x02u)))
#define DLT_KPI_DISPLAY_UP_COLD_BOOT (DLT_MAKE_FAULT_CODE(DLT_KPI_CATEGORY, (0x03u)))
#define DLT_KPI_SHUTDOWN_TIME (DLT_MAKE_FAULT_CODE(DLT_KPI_CATEGORY, (0x04u)))

/*****************************************************************************
 *                                 Type Declarations                          *
 *****************************************************************************/
extern Std_ReturnType NvMExt_WriteBlock(NvM_BlockIdType BlockId, uint8* NvM_SrcPtr);
extern VAR(NV_Data_BsReten_VisDlt, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_VisDlt;
extern const tDltExt_ConfigType DltExt_Config;

/*****************************************************************************
 *                                 Exported data                          *
 *****************************************************************************/

#if(DLT_WRITE_GIPCONSOL_ENABLE == STD_ON)
extern void McuExt_SetLogs(uint32_t *ResetReason);
#endif

extern void NvmExt_BlockWriteOnException(uint16 NvBlockId_u16);

extern const tDltExt_ErrCodeCounterMap_Cfg vCounterMap_Cfg[DLT_NUM_ERROR_CFG];
extern const tDlt_KPI_Catagory vKPIData_Cfg[DLTEXT_NUM_KPI];
extern const tDltExt_KPI_Config KPI_Metrix_Cfg[DLTEXT_NUM_KPI_METRIC];
extern const tDlt_App_error_Catagory App_error_Catagory[NUM_TYPE_CODES];
/*****************************************************************************
 *                                 Function Declarations                     *
 *****************************************************************************/

boolean DltExt_ResetLogDataStatus(Dlt_MessageLogLevelType LogLevel);
boolean DltExt_InitGetNvMReadyStatus(void);
boolean DltExt_isNVMJobCompleted_Data(void);
boolean DltExt_isNVMJobCompleted_Counter(void);

/*****************************************************************************
 *                  External Functions Mapping                                *
 ******************************************************************************/

//TODO: Remove once RTE is available
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_VisDlt_Element; 

#if(DLTEXT_PLATFORM_IMX8 == STD_ON)
#define DLTEXT_SET_DLT_MAIN_STORAGE             Rte_Call_rp_CS_MemAbsSet_Set_NVM_Dlt_Main_Storage
#define DLTEXT_GET_DLT_MAIN_STORAGE             Rte_Call_rp_CS_MemAbsGet_Get_NVM_Dlt_Main_Storage
#define DLTEXT_JOBSTATUS_DLT_MAIN_STORAGE       Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Dlt_Main_Storage

#elif(DLTEXT_PLATFORM_TRAVEO2 == STD_ON)
#define DLTEXT_SET_DLT_MAIN_STORAGE             Rte_Call_rp_CS_MemAbsSet_Set_NVM_Dlt_Main_Storage
#define DLTEXT_GET_DLT_MAIN_STORAGE             Rte_Call_rp_CS_MemAbsGet_Get_NVM_Dlt_Main_Storage
#define DLTEXT_JOBSTATUS_DLT_MAIN_STORAGE       Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Dlt_Main_Storage

#else
#define DLTEXT_SET_DLT_MAIN_STORAGE             Rte_Call_rp_CS_MemAbsSet_Set_BsReten_VisDlt_Element
#define DLTEXT_GET_DLT_MAIN_STORAGE             Rte_Call_rp_CS_MemAbsGet_Get_BsReten_VisDlt_Element
#define DLTEXT_JOBSTATUS_DLT_MAIN_STORAGE       Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_VisDlt_Element

// #define DLTEXT_SET_DLT_FETAL_STORAGE            Rte_Call_rp_CS_MemAbsSet_Set_NVM_Dlt_Fetal_Storage
// #define DLTEXT_GET_DLT_FETAL_STORAGE            Rte_Call_rp_CS_MemAbsGet_Get_NVM_Dlt_Fetal_Storage
// #define DLTEXT_JOBSTATUS_DLT_FETAL_STORAGE      Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Dlt_Fetal_Storage
#endif

#define DLTEXT_GETNVMREADALLSTATUS                  NvmExt_GetNvMReadAllStatus
#define DLTEXT_NVBLOCKDESCRIPTOR_DLT_FETAL_STORAGE  NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_VisDlt
#define DLTEXT_MEMABS_NVMSAVE_CALLOUT               Rte_Call_rp_CS_MemAbsSet_Set_BsReten_VisDlt_Element((uint8 *)&DltExt_vNVMData)
#define DLTEXT_ONEXEPTIONWRITE_DATACOPY_CALLOUT \
    MemLib_MemCpy((uint8 *)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_VisDlt.BsReten_VisDlt_Element, (uint8 *)&DltExt_vNVMData.ResetLogDataBuffer, DLTEXT_MAX_RESETCODE_SIZE)

#if(defined(DLT_FAULTCOUNTER_ENABLE) && (DLT_FAULTCOUNTER_ENABLE == STD_ON))
/* MemAbsSet and MemAbsGet calls mapping for Fault Counters */
#define DltExt_MemAbsSet_Set_NVM_HM_Data_Generic_Reset_Counter Rte_Call_rp_CS_MemAbsSet_Set_NVM_HM_Flash_Checksum_Fault_Counter
#define DltExt_MemAbsSet_Set_NVM_HM_Data_Illegal_Memory_Address_Reset_Counter Rte_Call_rp_CS_MemAbsSet_Set_NVM_HM_RAM_Checksum_Fault_Counter
#define DltExt_MemAbsSet_Set_NVM_HM_Stack_Overflow_Reset_Counter Rte_Call_rp_CS_MemAbsSet_Set_NVM_HM_Peripheral_Fault_Counter
#define DltExt_MemAbsSet_Set_NVM_HM_Illegal_Opcode_Reset_Counter Rte_Call_rp_CS_MemAbsSet_Set_NVM_HM_Illegal_Opcode_Reset_Counter
#define DltExt_MemAbsSet_Set_NVM_HM_Power_ON_Reset_Counter Rte_Call_rp_CS_MemAbsSet_Set_NVM_HM_Power_ON_Reset_Counter
#define DltExt_MemAbsSet_Set_NVM_HM_Watchdog_timer_Reset_Counter Rte_Call_rp_CS_MemAbsSet_Set_NVM_HM_Data_Range_Failure_Reset_Counter

#define DltExt_MemAbsGet_Get_NVM_HM_Data_Generic_Reset_Counter Rte_Call_rp_CS_MemAbsGet_Get_NVM_HM_Flash_Checksum_Fault_Counter
#define DltExt_MemAbsGet_Get_NVM_HM_Data_Illegal_Memory_Address_Reset_Counter Rte_Call_rp_CS_MemAbsGet_Get_NVM_HM_RAM_Checksum_Fault_Counter
#define DltExt_MemAbsGet_Get_NVM_HM_Stack_Overflow_Reset_Counter Rte_Call_rp_CS_MemAbsGet_Get_NVM_HM_Peripheral_Fault_Counter
#define DltExt_MemAbsGet_Get_NVM_HM_Illegal_Opcode_Reset_Counter Rte_Call_rp_CS_MemAbsGet_Get_NVM_HM_Illegal_Opcode_Reset_Counter
#define DltExt_MemAbsGet_Get_NVM_HM_Power_ON_Reset_Counter Rte_Call_rp_CS_MemAbsGet_Get_NVM_HM_Power_ON_Reset_Counter
#define DltExt_MemAbsGet_Get_NVM_HM_Watchdog_timer_Reset_Counter Rte_Call_rp_CS_MemAbsGet_Get_NVM_HM_Data_Range_Failure_Reset_Counter
#endif

#if(DLTEXT_USE_UCL == STD_ON)
#define DltExt_DmnMgr_SDmnStatus                                Rte_Read_DltExt_rpSRDmnInfo_SDmnStatus
#define DltExt_Ucl_LogDataBasedOnLogEventData                   Rte_Write_pSR_LogDataBasedOnLogEvent_LogDataBasedOnLogEventData
#endif

#endif /* DLTEXT_CFG_H */
