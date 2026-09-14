/******************************************************************************
**              CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2012. Visteon Corporation owns all rights to this work and
** intends to maintain it in confidence to preserve its trade secret status.
** Visteon Corporation reserves the right, under the copyright laws of the
** United States or those of any other country that may have  jurisdiction,
** to protect this work as an unpublished work, in the event of an
** inadvertent or deliberate unauthorized publication. Visteon Corporation
** also reserves its rights under all copyright laws to protect this work as
** a published work, when appropriate. Those having access to this work may
** not copy it, use it, modify it or disclose the information contained in
** it without the written authorization of Visteon Corporation
**
******************************************************************************/

/******************************************************************************

File Name        :  NvM_Cfg.c
Module Short Name:  NvM_Cfg.c
VOBName          :  
Author           :  
Description      :  Generated File
Organization     :  Driver Information Software Section,
                    Visteon Corporation

******************************************************************************/

#ifndef NVM_CFG_C
#define NVM_CFG_C
#define RTE_MICROSAR_PIM_EXPORT

#include "Rte_Type.h"
#include "Rte_NvM.h"
#include "NvM_Cfg.h"
#include "SchM_NvM.h"
#include "EcuMExt.h"
#include "Dem.h"
#include "Dem_Cbk.h"
#include "NvMDefaults.h"


#define NVM_CODE_SEC_START
 #include "MemMap.h"

#define NVM_DATA_SEC_START
 #include "MemMap.h"

#define NVM_CONST_SEC_START
 #include "MemMap.h"

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/
#ifdef __ghs__
#pragma alignvar (8)
#endif
uint8 NvMConfigBlock_RamBlock_au8[8];
extern NV_Data_NVM_BLOCK_SFD_PersistentData Rte_NvBlockSwComponentType_NVBlockDescriptor_NVM_BLOCK_SFD_PersistentData;

extern NV_Data_NVM_BLOCK_SFD_ConfigurationFingerprint_Data Rte_NvBlockSwComponentType_NVBlockDescriptor_NVM_BLOCK_SFD_ConfigurationFingerprint_Data;

extern NV_Data_NVM_BLOCK_IVD_0X0250 Rte_NvBlockSwComponentType_NVBlockDescriptor_NVM_BLOCK_IVD_0X0250;


extern NV_Data_NvMFblMetaData Rte_NvBlockSwComponentType_NVBlockDescriptor_NvMFblMetaData;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NvMFblMetaData - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_NvMFblMetaData_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_NvMFblGeneral Rte_NvBlockSwComponentType_NVBlockDescriptor_NvMFblGeneral;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NvMFblGeneral - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_NvMFblGeneral_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_NvMFblShareDataPartOne Rte_NvBlockSwComponentType_NVBlockDescriptor_NvMFblShareDataPartOne;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NvMFblShareDataPartOne - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_NvMFblShareDataPartOne_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_NvMFblShareDataPartTwo Rte_NvBlockSwComponentType_NVBlockDescriptor_NvMFblShareDataPartTwo;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NvMFblShareDataPartTwo - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_NvMFblShareDataPartTwo_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_NvMFblShareDataPartThree Rte_NvBlockSwComponentType_NVBlockDescriptor_NvMFblShareDataPartThree;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NvMFblShareDataPartThree - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_NvMFblShareDataPartThree_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern uint32 Ram_Magic_Flag;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Magic_Flag - CallBack  */
extern Std_ReturnType Magic_Flag_NvM_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern uint32 _NvMExt_Retention_RAM_Gp_0_START;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Retention_RAM_Gp_0 - CallBack  */
extern Std_ReturnType NvMExt_NotfyJobEnd_Retention_RAM_Gp_0( uint8 ServiceId, NvM_RequestResultType JobResult );

extern uint16 RetentionBlockStatus;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_RetentionBlockStatus - CallBack  */
extern Std_ReturnType NvMExt_NotfyJobEnd_RetentionBlockStatus( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_I5CM_ID_NVM_BlockSTS_2 Rte_NvBlockSwComponentType_NVBlockDescriptor_I5CM_ID_NVM_BlockSTS_2;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockSTS_2 - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockSTS_2_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_I5CM_ID_NVM_BlockSTATE_1 Rte_NvBlockSwComponentType_NVBlockDescriptor_I5CM_ID_NVM_BlockSTATE_1;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockSTATE_1 - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockSTATE_1_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_I5CM_ID_NVM_BlockSRM_2 Rte_NvBlockSwComponentType_NVBlockDescriptor_I5CM_ID_NVM_BlockSRM_2;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockSRM_2 - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockSRM_2_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_I5CM_ID_NVM_BlockSTS_0 Rte_NvBlockSwComponentType_NVBlockDescriptor_I5CM_ID_NVM_BlockSTS_0;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockSTS_0 - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockSTS_0_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_I5CM_ID_NVM_BlockPARAM_2 Rte_NvBlockSwComponentType_NVBlockDescriptor_I5CM_ID_NVM_BlockPARAM_2;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockPARAM_2 - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockPARAM_2_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_I5CM_ID_NVM_BlockSTATE_0 Rte_NvBlockSwComponentType_NVBlockDescriptor_I5CM_ID_NVM_BlockSTATE_0;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockSTATE_0 - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockSTATE_0_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_I5CM_ID_NVM_BlockLEARN_2 Rte_NvBlockSwComponentType_NVBlockDescriptor_I5CM_ID_NVM_BlockLEARN_2;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockLEARN_2 - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockLEARN_2_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_I5CM_ID_NVM_BlockSTS_1 Rte_NvBlockSwComponentType_NVBlockDescriptor_I5CM_ID_NVM_BlockSTS_1;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockSTS_1 - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockSTS_1_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_I5CM_ID_NVM_BlockSRM_0 Rte_NvBlockSwComponentType_NVBlockDescriptor_I5CM_ID_NVM_BlockSRM_0;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockSRM_0 - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockSRM_0_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_I5CM_ID_NVM_BlockSTATE_2 Rte_NvBlockSwComponentType_NVBlockDescriptor_I5CM_ID_NVM_BlockSTATE_2;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockSTATE_2 - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockSTATE_2_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_I5CM_ID_NVM_BlockSRM_1 Rte_NvBlockSwComponentType_NVBlockDescriptor_I5CM_ID_NVM_BlockSRM_1;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockSRM_1 - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockSRM_1_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_I5CM_ID_NVM_BlockPARAM_0 Rte_NvBlockSwComponentType_NVBlockDescriptor_I5CM_ID_NVM_BlockPARAM_0;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockPARAM_0 - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockPARAM_0_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_I5CM_ID_NVM_BlockKEYLC Rte_NvBlockSwComponentType_NVBlockDescriptor_I5CM_ID_NVM_BlockKEYLC;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockKEYLC - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockKEYLC_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_I5CM_ID_NVM_BlockLEARN_0 Rte_NvBlockSwComponentType_NVBlockDescriptor_I5CM_ID_NVM_BlockLEARN_0;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockLEARN_0 - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockLEARN_0_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_I5CM_ID_NVM_BlockPARAM_1 Rte_NvBlockSwComponentType_NVBlockDescriptor_I5CM_ID_NVM_BlockPARAM_1;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockPARAM_1 - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockPARAM_1_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_I5CM_ID_NVM_BlockKEY_0 Rte_NvBlockSwComponentType_NVBlockDescriptor_I5CM_ID_NVM_BlockKEY_0;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockKEY_0 - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockKEY_0_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_I5CM_ID_NVM_BlockLEARN_1 Rte_NvBlockSwComponentType_NVBlockDescriptor_I5CM_ID_NVM_BlockLEARN_1;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockLEARN_1 - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockLEARN_1_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_I5CM_ID_NVM_BlockKEY_2 Rte_NvBlockSwComponentType_NVBlockDescriptor_I5CM_ID_NVM_BlockKEY_2;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockKEY_2 - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockKEY_2_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_I5CM_ID_NVM_BlockDL Rte_NvBlockSwComponentType_NVBlockDescriptor_I5CM_ID_NVM_BlockDL;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockDL - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockDL_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_I5CM_ID_NVM_BlockKEY_1 Rte_NvBlockSwComponentType_NVBlockDescriptor_I5CM_ID_NVM_BlockKEY_1;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockKEY_1 - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockKEY_1_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_I5CM_ID_NVM_BlockDET Rte_NvBlockSwComponentType_NVBlockDescriptor_I5CM_ID_NVM_BlockDET;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockDET - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockDET_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_IVD_0X0250 - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_IVD_0X0250_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_Com_Cfg_VAR Rte_NvBlockSwComponentType_NVBlockDescriptor_Com_Cfg_VAR;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Com_Cfg_VAR - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_Com_Cfg_VAR_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_Gamma_Adjustment_VAR Rte_NvBlockSwComponentType_NVBlockDescriptor_Gamma_Adjustment_VAR;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Gamma_Adjustment_VAR - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_Gamma_Adjustment_VAR_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_RGB_Calibration_VAR Rte_NvBlockSwComponentType_NVBlockDescriptor_RGB_Calibration_VAR;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_RGB_Calibration_VAR - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_RGB_Calibration_VAR_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_DIAG_Adjustment_VAR Rte_NvBlockSwComponentType_NVBlockDescriptor_DIAG_Adjustment_VAR;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_Adjustment_VAR - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_Adjustment_VAR_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_Nvm_Block_Reserved_4 Rte_NvBlockSwComponentType_NVBlockDescriptor_Nvm_Block_Reserved_4;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Nvm_Block_Reserved_4 - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_Nvm_Block_Reserved_4_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_RPM_Gauge_FIR_Coefficients Rte_NvBlockSwComponentType_NVBlockDescriptor_RPM_Gauge_FIR_Coefficients;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_RPM_Gauge_FIR_Coefficients - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_RPM_Gauge_FIR_Coefficients_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_Bcct_Cfg_VAR_1 Rte_NvBlockSwComponentType_NVBlockDescriptor_Bcct_Cfg_VAR_1;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Bcct_Cfg_VAR_1 - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_Bcct_Cfg_VAR_1_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_Bcct_Cfg_VAR_2 Rte_NvBlockSwComponentType_NVBlockDescriptor_Bcct_Cfg_VAR_2;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Bcct_Cfg_VAR_2 - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_Bcct_Cfg_VAR_2_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_Bcct_Cfg_VAR_3 Rte_NvBlockSwComponentType_NVBlockDescriptor_Bcct_Cfg_VAR_3;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Bcct_Cfg_VAR_3 - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_Bcct_Cfg_VAR_3_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_Bargraph_VAR Rte_NvBlockSwComponentType_NVBlockDescriptor_Bargraph_VAR;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Bargraph_VAR - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_Bargraph_VAR_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_Nvm_Block_Reserved_1 Rte_NvBlockSwComponentType_NVBlockDescriptor_Nvm_Block_Reserved_1;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Nvm_Block_Reserved_1 - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_Nvm_Block_Reserved_1_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_Nvm_Block_Reserved_2 Rte_NvBlockSwComponentType_NVBlockDescriptor_Nvm_Block_Reserved_2;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Nvm_Block_Reserved_2 - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_Nvm_Block_Reserved_2_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_Bargraph_Hysteresis_Coolant Rte_NvBlockSwComponentType_NVBlockDescriptor_Bargraph_Hysteresis_Coolant;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Bargraph_Hysteresis_Coolant - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_Bargraph_Hysteresis_Coolant_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_Bargraph_Treshold_Switch_Coolant Rte_NvBlockSwComponentType_NVBlockDescriptor_Bargraph_Treshold_Switch_Coolant;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Bargraph_Treshold_Switch_Coolant - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_Bargraph_Treshold_Switch_Coolant_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_EEPVersionInfo_CONST Rte_NvBlockSwComponentType_NVBlockDescriptor_EEPVersionInfo_CONST;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_EEPVersionInfo_CONST - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_EEPVersionInfo_CONST_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_Odometer_0 Rte_NvBlockSwComponentType_NVBlockDescriptor_Odometer_0;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Odometer_0 - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_Odometer_0_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_Odometer_1 Rte_NvBlockSwComponentType_NVBlockDescriptor_Odometer_1;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Odometer_1 - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_Odometer_1_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_Odometer_2 Rte_NvBlockSwComponentType_NVBlockDescriptor_Odometer_2;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Odometer_2 - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_Odometer_2_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_DIAG_EOL_VAR Rte_NvBlockSwComponentType_NVBlockDescriptor_DIAG_EOL_VAR;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_EOL_VAR - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_EOL_VAR_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_DIAG_EOL_DiagCfg_CONST Rte_NvBlockSwComponentType_NVBlockDescriptor_DIAG_EOL_DiagCfg_CONST;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_EOL_DiagCfg_CONST - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_EOL_DiagCfg_CONST_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_DIAG_EOL_HWCalib_CONST Rte_NvBlockSwComponentType_NVBlockDescriptor_DIAG_EOL_HWCalib_CONST;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_EOL_HWCalib_CONST - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_EOL_HWCalib_CONST_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_DIAG_EOL_PartNumber_CONST Rte_NvBlockSwComponentType_NVBlockDescriptor_DIAG_EOL_PartNumber_CONST;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_EOL_PartNumber_CONST - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_EOL_PartNumber_CONST_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_USER_PROFILE1 Rte_NvBlockSwComponentType_NVBlockDescriptor_USER_PROFILE1;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_USER_PROFILE1 - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_USER_PROFILE1_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_USER_PROFILE2 Rte_NvBlockSwComponentType_NVBlockDescriptor_USER_PROFILE2;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_USER_PROFILE2 - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_USER_PROFILE2_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_USER_PROFILE3 Rte_NvBlockSwComponentType_NVBlockDescriptor_USER_PROFILE3;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_USER_PROFILE3 - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_USER_PROFILE3_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_USER_PROFILE4 Rte_NvBlockSwComponentType_NVBlockDescriptor_USER_PROFILE4;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_USER_PROFILE4 - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_USER_PROFILE4_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_USER_PROFILE5 Rte_NvBlockSwComponentType_NVBlockDescriptor_USER_PROFILE5;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_USER_PROFILE5 - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_USER_PROFILE5_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_USER_PROFILE6 Rte_NvBlockSwComponentType_NVBlockDescriptor_USER_PROFILE6;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_USER_PROFILE6 - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_USER_PROFILE6_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_USER_PROFILE7 Rte_NvBlockSwComponentType_NVBlockDescriptor_USER_PROFILE7;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_USER_PROFILE7 - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_USER_PROFILE7_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_USER_PROFILE0 Rte_NvBlockSwComponentType_NVBlockDescriptor_USER_PROFILE0;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_USER_PROFILE0 - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_USER_PROFILE0_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_DIAG_EOL_HWCalib_CONST_1 Rte_NvBlockSwComponentType_NVBlockDescriptor_DIAG_EOL_HWCalib_CONST_1;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_EOL_HWCalib_CONST_1 - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_EOL_HWCalib_CONST_1_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_Cluster_Settings Rte_NvBlockSwComponentType_NVBlockDescriptor_Cluster_Settings;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Cluster_Settings - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_Cluster_Settings_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_DIAG_VariantCoding_CONST Rte_NvBlockSwComponentType_NVBlockDescriptor_DIAG_VariantCoding_CONST;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_VariantCoding_CONST - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_VariantCoding_CONST_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_COMPONENTS_Cfg_VAR Rte_NvBlockSwComponentType_NVBlockDescriptor_COMPONENTS_Cfg_VAR;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_COMPONENTS_Cfg_VAR - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_COMPONENTS_Cfg_VAR_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_Service_History_Data Rte_NvBlockSwComponentType_NVBlockDescriptor_Service_History_Data;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Service_History_Data - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_Service_History_Data_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_DtcAgingAdminDataBlock Rte_NvBlockSwComponentType_NVBlockDescriptor_DtcAgingAdminDataBlock;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DtcAgingAdminDataBlock - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_DtcAgingAdminDataBlock_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_DIAG_VariantCodingCheck_CONST Rte_NvBlockSwComponentType_NVBlockDescriptor_DIAG_VariantCodingCheck_CONST;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_VariantCodingCheck_CONST - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_VariantCodingCheck_CONST_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_ServiceKey_VAR Rte_NvBlockSwComponentType_NVBlockDescriptor_ServiceKey_VAR;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_ServiceKey_VAR - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_ServiceKey_VAR_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_DIAG_AC_ServiceCfg_VAR Rte_NvBlockSwComponentType_NVBlockDescriptor_DIAG_AC_ServiceCfg_VAR;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_AC_ServiceCfg_VAR - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_AC_ServiceCfg_VAR_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_DIAG_AdaptationChannel_VAR_1 Rte_NvBlockSwComponentType_NVBlockDescriptor_DIAG_AdaptationChannel_VAR_1;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_AdaptationChannel_VAR_1 - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_AdaptationChannel_VAR_1_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_DATE_VAR Rte_NvBlockSwComponentType_NVBlockDescriptor_DATE_VAR;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DATE_VAR - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_DATE_VAR_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_DIAG_AdaptationChannel_VAR_0 Rte_NvBlockSwComponentType_NVBlockDescriptor_DIAG_AdaptationChannel_VAR_0;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_AdaptationChannel_VAR_0 - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_AdaptationChannel_VAR_0_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_REFUEL_Logger_VAR Rte_NvBlockSwComponentType_NVBlockDescriptor_REFUEL_Logger_VAR;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_REFUEL_Logger_VAR - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_REFUEL_Logger_VAR_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_COMPONENTS_Cfg_CONST Rte_NvBlockSwComponentType_NVBlockDescriptor_COMPONENTS_Cfg_CONST;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_COMPONENTS_Cfg_CONST - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_COMPONENTS_Cfg_CONST_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_TANK_Variant_CONST Rte_NvBlockSwComponentType_NVBlockDescriptor_TANK_Variant_CONST;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_TANK_Variant_CONST - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_TANK_Variant_CONST_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_Dev_Messages Rte_NvBlockSwComponentType_NVBlockDescriptor_Dev_Messages;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Dev_Messages - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_Dev_Messages_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_Recorder_VAR Rte_NvBlockSwComponentType_NVBlockDescriptor_Recorder_VAR;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Recorder_VAR - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_Recorder_VAR_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_OperatingTime_VAR Rte_NvBlockSwComponentType_NVBlockDescriptor_OperatingTime_VAR;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_OperatingTime_VAR - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_OperatingTime_VAR_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_DIAG_AC_Curve_Scales_VAR Rte_NvBlockSwComponentType_NVBlockDescriptor_DIAG_AC_Curve_Scales_VAR;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_AC_Curve_Scales_VAR - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_AC_Curve_Scales_VAR_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_DIAG_AC_IlluminationCfg_VAR_0 Rte_NvBlockSwComponentType_NVBlockDescriptor_DIAG_AC_IlluminationCfg_VAR_0;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_AC_IlluminationCfg_VAR_0 - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_AC_IlluminationCfg_VAR_0_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_DIAG_AC_IlluminationCfg_VAR_1 Rte_NvBlockSwComponentType_NVBlockDescriptor_DIAG_AC_IlluminationCfg_VAR_1;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_AC_IlluminationCfg_VAR_1 - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_AC_IlluminationCfg_VAR_1_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_DIAG_AC_IlluminationCfg_VAR_3 Rte_NvBlockSwComponentType_NVBlockDescriptor_DIAG_AC_IlluminationCfg_VAR_3;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_AC_IlluminationCfg_VAR_3 - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_AC_IlluminationCfg_VAR_3_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_SRV_TKM_ZvCrH_TKM_ZvCrHPimTkKeyInCarNeed Rte_NvBlockSwComponentType_NVBlockDescriptor_SRV_TKM_ZvCrH_TKM_ZvCrHPimTkKeyInCarNeed;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_SRV_TKM_ZvCrH_TKM_ZvCrHPimTkKeyInCarNeed - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_SRV_TKM_ZvCrH_TKM_ZvCrHPimTkKeyInCarNeed_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_SAFETY_RECORD_VAR Rte_NvBlockSwComponentType_NVBlockDescriptor_SAFETY_RECORD_VAR;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_SAFETY_RECORD_VAR - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_SAFETY_RECORD_VAR_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_KsNvmBlockGfaKey_0 Rte_NvBlockSwComponentType_NVBlockDescriptor_KsNvmBlockGfaKey_0;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_KsNvmBlockGfaKey_0 - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_KsNvmBlockGfaKey_0_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_KsNvmBlockGfaKey_1 Rte_NvBlockSwComponentType_NVBlockDescriptor_KsNvmBlockGfaKey_1;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_KsNvmBlockGfaKey_1 - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_KsNvmBlockGfaKey_1_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_KsNvmBlockMisc_0 Rte_NvBlockSwComponentType_NVBlockDescriptor_KsNvmBlockMisc_0;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_KsNvmBlockMisc_0 - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_KsNvmBlockMisc_0_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_KsNvmBlockMisc_1 Rte_NvBlockSwComponentType_NVBlockDescriptor_KsNvmBlockMisc_1;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_KsNvmBlockMisc_1 - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_KsNvmBlockMisc_1_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_CAN_VAR Rte_NvBlockSwComponentType_NVBlockDescriptor_CAN_VAR;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_CAN_VAR - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_CAN_VAR_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_Recorder_VAR_2 Rte_NvBlockSwComponentType_NVBlockDescriptor_Recorder_VAR_2;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Recorder_VAR_2 - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_Recorder_VAR_2_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_NvM_VKMS VKMS_NvRamBlock;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NvM_VKMS - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_NvM_VKMS_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_PersistentData - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_PersistentData_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_ConfigurationFingerprint_Data - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_ConfigurationFingerprint_Data_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern Dem_Cfg_OpCycleType Dem_Cfg_OpCycle;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemAdmin - CallBack  */
extern Std_ReturnType Dem_NvM_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern Dem_Cfg_UdsStatusDataType Dem_Cfg_StatusData;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemStatus - CallBack  */
extern Std_ReturnType Dem_NvM_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_0;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_000 - CallBack  */
extern Std_ReturnType Dem_NvM_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_1;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_001 - CallBack  */
extern Std_ReturnType Dem_NvM_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_2;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_002 - CallBack  */
extern Std_ReturnType Dem_NvM_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_3;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_003 - CallBack  */
extern Std_ReturnType Dem_NvM_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_4;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_004 - CallBack  */
extern Std_ReturnType Dem_NvM_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_5;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_005 - CallBack  */
extern Std_ReturnType Dem_NvM_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_6;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_006 - CallBack  */
extern Std_ReturnType Dem_NvM_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_7;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_007 - CallBack  */
extern Std_ReturnType Dem_NvM_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_8;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_008 - CallBack  */
extern Std_ReturnType Dem_NvM_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_9;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_009 - CallBack  */
extern Std_ReturnType Dem_NvM_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_10;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_010 - CallBack  */
extern Std_ReturnType Dem_NvM_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_11;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_011 - CallBack  */
extern Std_ReturnType Dem_NvM_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_12;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_012 - CallBack  */
extern Std_ReturnType Dem_NvM_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_13;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_013 - CallBack  */
extern Std_ReturnType Dem_NvM_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_14;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_014 - CallBack  */
extern Std_ReturnType Dem_NvM_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_15;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_015 - CallBack  */
extern Std_ReturnType Dem_NvM_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_16;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_016 - CallBack  */
extern Std_ReturnType Dem_NvM_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_17;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_017 - CallBack  */
extern Std_ReturnType Dem_NvM_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_18;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_018 - CallBack  */
extern Std_ReturnType Dem_NvM_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_19;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_019 - CallBack  */
extern Std_ReturnType Dem_NvM_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_20;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_020 - CallBack  */
extern Std_ReturnType Dem_NvM_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_21;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_021 - CallBack  */
extern Std_ReturnType Dem_NvM_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_22;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_022 - CallBack  */
extern Std_ReturnType Dem_NvM_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_23;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_023 - CallBack  */
extern Std_ReturnType Dem_NvM_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_24;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_024 - CallBack  */
extern Std_ReturnType Dem_NvM_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_25;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_025 - CallBack  */
extern Std_ReturnType Dem_NvM_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_26;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_026 - CallBack  */
extern Std_ReturnType Dem_NvM_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_27;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_027 - CallBack  */
extern Std_ReturnType Dem_NvM_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_28;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_028 - CallBack  */
extern Std_ReturnType Dem_NvM_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_29;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_029 - CallBack  */
extern Std_ReturnType Dem_NvM_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern uint8 Dcm_RAM86Infinitewindowtimestatus;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Dcm_86Infinitewindowtimestatus - CallBack  */
extern Std_ReturnType Dem_NvM_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_NVM_BLOCK_SFD_PublicKey SfdKey;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_PublicKey - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_PublicKey_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_SecDiag Rte_NvBlockSwComponentType_NVBlockDescriptor_SecDiag;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_SecDiag - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_SecDiag_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_DIAG_AdaptationChannel_VAR_2 Rte_NvBlockSwComponentType_NVBlockDescriptor_DIAG_AdaptationChannel_VAR_2;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_AdaptationChannel_VAR_2 - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_AdaptationChannel_VAR_2_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_WLTP_Odo_VAR Rte_NvBlockSwComponentType_NVBlockDescriptor_WLTP_Odo_VAR;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_WLTP_Odo_VAR - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_WLTP_Odo_VAR_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern NV_Data_SecDiag_1 Rte_NvBlockSwComponentType_NVBlockDescriptor_SecDiag_1;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_SecDiag_1 - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_SecDiag_1_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );
/*****************************************************************************
*                                Globally  accessed Variable Declarations    *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/
const NvM_BlockDescriptorType NvM_BlockConfig[NVM_NUM_OF_BLOCKS+1]=
{
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);                                  */                   
        NULL,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */                   
        NULL,        /*   uint8*    RamBlockDataAddress;        */                   
        NULL,        /*   uint8*    RomBlockDataAddress;        */                   
        0,           /*   uint16    NvBlockBaseNumber;          */                   
        0,           /*   uint16    NvBlockLength;              */                   
        0,           /*   uint16    NvRamBlockIdentifier;       */                   
        1,           /*   uint8     BlockJobPriority;           */                   
        0,           /*   uint8     MaxNumReadRetries;          */                   
        0,           /*   uint8     MaxNumWriteRetries;         */                   
        0,           /*   uint8     NvBlockNum;                 */                   
        0,           /*   uint8     NvRamDeviceId;              */                   
        0,           /*   uint8     RomBlockNum;                */                   
        CRC_8,       /*   NvM_CrcEnumeration BlockCrcType;      */                   
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */    
        0,           /*   boolean   BlockUseCrc;                */                   
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */                   
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        0,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);                                */                                
        NULL,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);   */                                
        (uint8*)&NvMConfigBlock_RamBlock_au8,        /*   uint8*    RamBlockDataAddress;        */                                
        NULL,        /*   uint8*    RomBlockDataAddress;        */                                
        0,           /*   uint16    NvBlockBaseNumber;          */                                
        8,          /*   uint16    NvBlockLength;              */                                
        0,           /*   uint16    NvRamBlockIdentifier;       */                                
        1,           /*   uint8     BlockJobPriority;           */                                
        0,           /*   uint8     MaxNumReadRetries;          */                                
        0,           /*   uint8     MaxNumWriteRetries;         */                                
        0,           /*   uint8     NvBlockNum;                 */                                
        0,           /*   uint8     NvRamDeviceId;              */                                
        0,           /*   uint8     RomBlockNum;                */                                
        CRC_8,       /*   NvM_CrcEnumeration BlockCrcType;      */                                
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */                 
        0,           /*   boolean   BlockUseCrc;                */                                
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */                                
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        0,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NvMFblMetaData   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_NvMFblMetaData_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_NvMFblMetaData,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_NvMFblMetaData,        /*   uint8*    RomBlockDataAddress;        */
        0,           /*   uint16    NvBlockBaseNumber;          */
        196,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_SNVM,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        0,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NvMFblGeneral   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_NvMFblGeneral_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_NvMFblGeneral,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_NvMFblGeneral,        /*   uint8*    RomBlockDataAddress;        */
        2,           /*   uint16    NvBlockBaseNumber;          */
        12,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_SNVM,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        0,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NvMFblShareDataPartOne   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_NvMFblShareDataPartOne_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_NvMFblShareDataPartOne,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_NvMFblShareDataPartOne,        /*   uint8*    RomBlockDataAddress;        */
        4,           /*   uint16    NvBlockBaseNumber;          */
        128,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_SNVM,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        0,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NvMFblShareDataPartTwo   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_NvMFblShareDataPartTwo_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_NvMFblShareDataPartTwo,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_NvMFblShareDataPartTwo,        /*   uint8*    RomBlockDataAddress;        */
        6,           /*   uint16    NvBlockBaseNumber;          */
        128,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_SNVM,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        0,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NvMFblShareDataPartThree   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_NvMFblShareDataPartThree_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_NvMFblShareDataPartThree,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_NvMFblShareDataPartThree,        /*   uint8*    RomBlockDataAddress;        */
        8,           /*   uint16    NvBlockBaseNumber;          */
        128,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_SNVM,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        0,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Magic_Flag   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Magic_Flag_NvM_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Ram_Magic_Flag,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&ROM_Magic_Flag,        /*   uint8*    RomBlockDataAddress;        */
        10,           /*   uint16    NvBlockBaseNumber;          */
        4,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_SNVM,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_8,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        0,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Retention_RAM_Gp_0   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        NvMExt_NotfyJobEnd_Retention_RAM_Gp_0,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&_NvMExt_Retention_RAM_Gp_0_START,        /*   uint8*    RamBlockDataAddress;        */
        NULL,        /*   uint8*    RomBlockDataAddress;        */
        11,           /*   uint16    NvBlockBaseNumber;          */
        6144,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_SNVM,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        0,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_RetentionBlockStatus   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        NvMExt_NotfyJobEnd_RetentionBlockStatus,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&RetentionBlockStatus,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&RetentionBlockStatusDefault,        /*   uint8*    RomBlockDataAddress;        */
        12,           /*   uint16    NvBlockBaseNumber;          */
        2,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_SNVM,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_8,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockSTS_2   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockSTS_2_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_I5CM_ID_NVM_BlockSTS_2,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_I5CM_ID_NVM_BlockSTS_2,        /*   uint8*    RomBlockDataAddress;        */
        13,           /*   uint16    NvBlockBaseNumber;          */
        16,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        0,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_SNVM,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockSTATE_1   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockSTATE_1_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_I5CM_ID_NVM_BlockSTATE_1,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_I5CM_ID_NVM_BlockSTATE_1,        /*   uint8*    RomBlockDataAddress;        */
        14,           /*   uint16    NvBlockBaseNumber;          */
        16,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        0,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_SNVM,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockSRM_2   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockSRM_2_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_I5CM_ID_NVM_BlockSRM_2,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_I5CM_ID_NVM_BlockSRM_2,        /*   uint8*    RomBlockDataAddress;        */
        15,           /*   uint16    NvBlockBaseNumber;          */
        32,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        0,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_SNVM,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockSTS_0   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockSTS_0_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_I5CM_ID_NVM_BlockSTS_0,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_I5CM_ID_NVM_BlockSTS_0,        /*   uint8*    RomBlockDataAddress;        */
        16,           /*   uint16    NvBlockBaseNumber;          */
        16,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        0,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_SNVM,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockPARAM_2   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockPARAM_2_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_I5CM_ID_NVM_BlockPARAM_2,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_I5CM_ID_NVM_BlockPARAM_2,        /*   uint8*    RomBlockDataAddress;        */
        17,           /*   uint16    NvBlockBaseNumber;          */
        32,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        0,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_SNVM,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockSTATE_0   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockSTATE_0_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_I5CM_ID_NVM_BlockSTATE_0,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_I5CM_ID_NVM_BlockSTATE_0,        /*   uint8*    RomBlockDataAddress;        */
        18,           /*   uint16    NvBlockBaseNumber;          */
        16,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        0,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_SNVM,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockLEARN_2   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockLEARN_2_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_I5CM_ID_NVM_BlockLEARN_2,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_I5CM_ID_NVM_BlockLEARN_2,        /*   uint8*    RomBlockDataAddress;        */
        19,           /*   uint16    NvBlockBaseNumber;          */
        80,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        0,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_SNVM,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockSTS_1   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockSTS_1_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_I5CM_ID_NVM_BlockSTS_1,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_I5CM_ID_NVM_BlockSTS_1,        /*   uint8*    RomBlockDataAddress;        */
        20,           /*   uint16    NvBlockBaseNumber;          */
        16,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        0,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_SNVM,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockSRM_0   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockSRM_0_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_I5CM_ID_NVM_BlockSRM_0,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_I5CM_ID_NVM_BlockSRM_0,        /*   uint8*    RomBlockDataAddress;        */
        21,           /*   uint16    NvBlockBaseNumber;          */
        32,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        0,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_SNVM,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockSTATE_2   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockSTATE_2_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_I5CM_ID_NVM_BlockSTATE_2,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_I5CM_ID_NVM_BlockSTATE_2,        /*   uint8*    RomBlockDataAddress;        */
        22,           /*   uint16    NvBlockBaseNumber;          */
        16,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        0,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_SNVM,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockSRM_1   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockSRM_1_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_I5CM_ID_NVM_BlockSRM_1,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_I5CM_ID_NVM_BlockSRM_1,        /*   uint8*    RomBlockDataAddress;        */
        23,           /*   uint16    NvBlockBaseNumber;          */
        32,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        0,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_SNVM,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockPARAM_0   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockPARAM_0_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_I5CM_ID_NVM_BlockPARAM_0,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_I5CM_ID_NVM_BlockPARAM_0,        /*   uint8*    RomBlockDataAddress;        */
        24,           /*   uint16    NvBlockBaseNumber;          */
        32,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        0,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_SNVM,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockKEYLC   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockKEYLC_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_I5CM_ID_NVM_BlockKEYLC,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_I5CM_ID_NVM_BlockKEYLC,        /*   uint8*    RomBlockDataAddress;        */
        25,           /*   uint16    NvBlockBaseNumber;          */
        128,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        0,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_SNVM,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockLEARN_0   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockLEARN_0_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_I5CM_ID_NVM_BlockLEARN_0,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_I5CM_ID_NVM_BlockLEARN_0,        /*   uint8*    RomBlockDataAddress;        */
        26,           /*   uint16    NvBlockBaseNumber;          */
        80,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        0,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_SNVM,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockPARAM_1   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockPARAM_1_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_I5CM_ID_NVM_BlockPARAM_1,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_I5CM_ID_NVM_BlockPARAM_1,        /*   uint8*    RomBlockDataAddress;        */
        27,           /*   uint16    NvBlockBaseNumber;          */
        32,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        0,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_SNVM,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockKEY_0   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockKEY_0_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_I5CM_ID_NVM_BlockKEY_0,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_I5CM_ID_NVM_BlockKEY_0,        /*   uint8*    RomBlockDataAddress;        */
        28,           /*   uint16    NvBlockBaseNumber;          */
        64,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        0,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_SNVM,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockLEARN_1   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockLEARN_1_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_I5CM_ID_NVM_BlockLEARN_1,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_I5CM_ID_NVM_BlockLEARN_1,        /*   uint8*    RomBlockDataAddress;        */
        29,           /*   uint16    NvBlockBaseNumber;          */
        80,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        0,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_SNVM,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockKEY_2   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockKEY_2_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_I5CM_ID_NVM_BlockKEY_2,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_I5CM_ID_NVM_BlockKEY_2,        /*   uint8*    RomBlockDataAddress;        */
        30,           /*   uint16    NvBlockBaseNumber;          */
        64,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        0,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_SNVM,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockDL   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockDL_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_I5CM_ID_NVM_BlockDL,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_I5CM_ID_NVM_BlockDL,        /*   uint8*    RomBlockDataAddress;        */
        31,           /*   uint16    NvBlockBaseNumber;          */
        176,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        0,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_SNVM,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockKEY_1   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockKEY_1_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_I5CM_ID_NVM_BlockKEY_1,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_I5CM_ID_NVM_BlockKEY_1,        /*   uint8*    RomBlockDataAddress;        */
        32,           /*   uint16    NvBlockBaseNumber;          */
        64,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        0,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_SNVM,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockDET   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockDET_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_I5CM_ID_NVM_BlockDET,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_I5CM_ID_NVM_BlockDET,        /*   uint8*    RomBlockDataAddress;        */
        33,           /*   uint16    NvBlockBaseNumber;          */
        64,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        0,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_SNVM,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_IVD_0X0250   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_IVD_0X0250_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        NULL,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Ivd_Nvm_0x0250_InitVal_cu8,        /*   uint8*    RomBlockDataAddress;        */
        34,           /*   uint16    NvBlockBaseNumber;          */
        202,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_SNVM,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        0,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Com_Cfg_VAR   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_Com_Cfg_VAR_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_Com_Cfg_VAR,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_Com_Cfg_VAR,        /*   uint8*    RomBlockDataAddress;        */
        2,           /*   uint16    NvBlockBaseNumber;          */
        100,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Gamma_Adjustment_VAR   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_Gamma_Adjustment_VAR_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_Gamma_Adjustment_VAR,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_Gamma_Adjustment_VAR,        /*   uint8*    RomBlockDataAddress;        */
        4,           /*   uint16    NvBlockBaseNumber;          */
        244,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_RGB_Calibration_VAR   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_RGB_Calibration_VAR_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_RGB_Calibration_VAR,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_RGB_Calibration_VAR,        /*   uint8*    RomBlockDataAddress;        */
        6,           /*   uint16    NvBlockBaseNumber;          */
        380,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_Adjustment_VAR   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_Adjustment_VAR_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_DIAG_Adjustment_VAR,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_DIAG_Adjustment_VAR,        /*   uint8*    RomBlockDataAddress;        */
        8,           /*   uint16    NvBlockBaseNumber;          */
        224,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Nvm_Block_Reserved_4   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_Nvm_Block_Reserved_4_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_Nvm_Block_Reserved_4,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_Nvm_Block_Reserved_4,        /*   uint8*    RomBlockDataAddress;        */
        10,           /*   uint16    NvBlockBaseNumber;          */
        164,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_RPM_Gauge_FIR_Coefficients   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_RPM_Gauge_FIR_Coefficients_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_RPM_Gauge_FIR_Coefficients,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_RPM_Gauge_FIR_Coefficients,        /*   uint8*    RomBlockDataAddress;        */
        12,           /*   uint16    NvBlockBaseNumber;          */
        64,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Bcct_Cfg_VAR_1   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_Bcct_Cfg_VAR_1_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_Bcct_Cfg_VAR_1,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_Bcct_Cfg_VAR_1,        /*   uint8*    RomBlockDataAddress;        */
        14,           /*   uint16    NvBlockBaseNumber;          */
        124,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Bcct_Cfg_VAR_2   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_Bcct_Cfg_VAR_2_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_Bcct_Cfg_VAR_2,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_Bcct_Cfg_VAR_2,        /*   uint8*    RomBlockDataAddress;        */
        16,           /*   uint16    NvBlockBaseNumber;          */
        140,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Bcct_Cfg_VAR_3   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_Bcct_Cfg_VAR_3_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_Bcct_Cfg_VAR_3,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_Bcct_Cfg_VAR_3,        /*   uint8*    RomBlockDataAddress;        */
        18,           /*   uint16    NvBlockBaseNumber;          */
        120,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Bargraph_VAR   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_Bargraph_VAR_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_Bargraph_VAR,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_Bargraph_VAR,        /*   uint8*    RomBlockDataAddress;        */
        20,           /*   uint16    NvBlockBaseNumber;          */
        20,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Nvm_Block_Reserved_1   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_Nvm_Block_Reserved_1_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_Nvm_Block_Reserved_1,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_Nvm_Block_Reserved_1,        /*   uint8*    RomBlockDataAddress;        */
        22,           /*   uint16    NvBlockBaseNumber;          */
        64,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Nvm_Block_Reserved_2   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_Nvm_Block_Reserved_2_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_Nvm_Block_Reserved_2,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_Nvm_Block_Reserved_2,        /*   uint8*    RomBlockDataAddress;        */
        24,           /*   uint16    NvBlockBaseNumber;          */
        32,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Bargraph_Hysteresis_Coolant   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_Bargraph_Hysteresis_Coolant_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_Bargraph_Hysteresis_Coolant,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_Bargraph_Hysteresis_Coolant,        /*   uint8*    RomBlockDataAddress;        */
        26,           /*   uint16    NvBlockBaseNumber;          */
        15,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Bargraph_Treshold_Switch_Coolant   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_Bargraph_Treshold_Switch_Coolant_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_Bargraph_Treshold_Switch_Coolant,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_Bargraph_Treshold_Switch_Coolant,        /*   uint8*    RomBlockDataAddress;        */
        28,           /*   uint16    NvBlockBaseNumber;          */
        15,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_EEPVersionInfo_CONST   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_EEPVersionInfo_CONST_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_EEPVersionInfo_CONST,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_EEPVersionInfo_CONST,        /*   uint8*    RomBlockDataAddress;        */
        30,           /*   uint16    NvBlockBaseNumber;          */
        8,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Odometer_0   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_Odometer_0_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_Odometer_0,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_Odometer_0,        /*   uint8*    RomBlockDataAddress;        */
        32,           /*   uint16    NvBlockBaseNumber;          */
        16,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        0,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Odometer_1   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_Odometer_1_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_Odometer_1,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_Odometer_1,        /*   uint8*    RomBlockDataAddress;        */
        33,           /*   uint16    NvBlockBaseNumber;          */
        16,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        0,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Odometer_2   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_Odometer_2_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_Odometer_2,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_Odometer_2,        /*   uint8*    RomBlockDataAddress;        */
        34,           /*   uint16    NvBlockBaseNumber;          */
        16,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        0,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_EOL_VAR   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_EOL_VAR_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_DIAG_EOL_VAR,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_DIAG_EOL_VAR,        /*   uint8*    RomBlockDataAddress;        */
        35,           /*   uint16    NvBlockBaseNumber;          */
        36,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_EOL_DiagCfg_CONST   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_EOL_DiagCfg_CONST_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_DIAG_EOL_DiagCfg_CONST,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_DIAG_EOL_DiagCfg_CONST,        /*   uint8*    RomBlockDataAddress;        */
        37,           /*   uint16    NvBlockBaseNumber;          */
        60,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_EOL_HWCalib_CONST   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_EOL_HWCalib_CONST_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_DIAG_EOL_HWCalib_CONST,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_DIAG_EOL_HWCalib_CONST,        /*   uint8*    RomBlockDataAddress;        */
        39,           /*   uint16    NvBlockBaseNumber;          */
        52,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_EOL_PartNumber_CONST   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_EOL_PartNumber_CONST_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_DIAG_EOL_PartNumber_CONST,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_DIAG_EOL_PartNumber_CONST,        /*   uint8*    RomBlockDataAddress;        */
        41,           /*   uint16    NvBlockBaseNumber;          */
        36,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_USER_PROFILE1   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_USER_PROFILE1_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_USER_PROFILE1,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_USER_PROFILE1,        /*   uint8*    RomBlockDataAddress;        */
        43,           /*   uint16    NvBlockBaseNumber;          */
        60,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_USER_PROFILE2   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_USER_PROFILE2_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_USER_PROFILE2,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_USER_PROFILE2,        /*   uint8*    RomBlockDataAddress;        */
        45,           /*   uint16    NvBlockBaseNumber;          */
        60,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_USER_PROFILE3   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_USER_PROFILE3_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_USER_PROFILE3,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_USER_PROFILE3,        /*   uint8*    RomBlockDataAddress;        */
        47,           /*   uint16    NvBlockBaseNumber;          */
        60,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_USER_PROFILE4   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_USER_PROFILE4_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_USER_PROFILE4,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_USER_PROFILE4,        /*   uint8*    RomBlockDataAddress;        */
        49,           /*   uint16    NvBlockBaseNumber;          */
        60,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_USER_PROFILE5   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_USER_PROFILE5_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_USER_PROFILE5,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_USER_PROFILE5,        /*   uint8*    RomBlockDataAddress;        */
        51,           /*   uint16    NvBlockBaseNumber;          */
        60,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_USER_PROFILE6   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_USER_PROFILE6_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_USER_PROFILE6,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_USER_PROFILE6,        /*   uint8*    RomBlockDataAddress;        */
        53,           /*   uint16    NvBlockBaseNumber;          */
        60,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_USER_PROFILE7   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_USER_PROFILE7_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_USER_PROFILE7,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_USER_PROFILE7,        /*   uint8*    RomBlockDataAddress;        */
        55,           /*   uint16    NvBlockBaseNumber;          */
        60,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_USER_PROFILE0   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_USER_PROFILE0_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_USER_PROFILE0,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_USER_PROFILE0,        /*   uint8*    RomBlockDataAddress;        */
        57,           /*   uint16    NvBlockBaseNumber;          */
        60,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_EOL_HWCalib_CONST_1   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_EOL_HWCalib_CONST_1_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_DIAG_EOL_HWCalib_CONST_1,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_DIAG_EOL_HWCalib_CONST_1,        /*   uint8*    RomBlockDataAddress;        */
        59,           /*   uint16    NvBlockBaseNumber;          */
        52,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Cluster_Settings   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_Cluster_Settings_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_Cluster_Settings,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_Cluster_Settings,        /*   uint8*    RomBlockDataAddress;        */
        61,           /*   uint16    NvBlockBaseNumber;          */
        60,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_VariantCoding_CONST   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_VariantCoding_CONST_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_DIAG_VariantCoding_CONST,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_DIAG_VariantCoding_CONST,        /*   uint8*    RomBlockDataAddress;        */
        63,           /*   uint16    NvBlockBaseNumber;          */
        140,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_COMPONENTS_Cfg_VAR   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_COMPONENTS_Cfg_VAR_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_COMPONENTS_Cfg_VAR,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_COMPONENTS_Cfg_VAR,        /*   uint8*    RomBlockDataAddress;        */
        65,           /*   uint16    NvBlockBaseNumber;          */
        52,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Service_History_Data   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_Service_History_Data_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_Service_History_Data,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_Service_History_Data,        /*   uint8*    RomBlockDataAddress;        */
        67,           /*   uint16    NvBlockBaseNumber;          */
        256,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DtcAgingAdminDataBlock   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_DtcAgingAdminDataBlock_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_DtcAgingAdminDataBlock,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_DtcAgingAdminDataBlock,        /*   uint8*    RomBlockDataAddress;        */
        69,           /*   uint16    NvBlockBaseNumber;          */
        4,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_VariantCodingCheck_CONST   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_VariantCodingCheck_CONST_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_DIAG_VariantCodingCheck_CONST,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_DIAG_VariantCodingCheck_CONST,        /*   uint8*    RomBlockDataAddress;        */
        71,           /*   uint16    NvBlockBaseNumber;          */
        176,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_ServiceKey_VAR   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_ServiceKey_VAR_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_ServiceKey_VAR,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_ServiceKey_VAR,        /*   uint8*    RomBlockDataAddress;        */
        73,           /*   uint16    NvBlockBaseNumber;          */
        28,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_AC_ServiceCfg_VAR   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_AC_ServiceCfg_VAR_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_DIAG_AC_ServiceCfg_VAR,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_DIAG_AC_ServiceCfg_VAR,        /*   uint8*    RomBlockDataAddress;        */
        75,           /*   uint16    NvBlockBaseNumber;          */
        52,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_AdaptationChannel_VAR_1   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_AdaptationChannel_VAR_1_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_DIAG_AdaptationChannel_VAR_1,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_1,        /*   uint8*    RomBlockDataAddress;        */
        77,           /*   uint16    NvBlockBaseNumber;          */
        52,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DATE_VAR   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_DATE_VAR_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_DATE_VAR,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_DATE_VAR,        /*   uint8*    RomBlockDataAddress;        */
        79,           /*   uint16    NvBlockBaseNumber;          */
        4,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_AdaptationChannel_VAR_0   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_AdaptationChannel_VAR_0_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_DIAG_AdaptationChannel_VAR_0,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_0,        /*   uint8*    RomBlockDataAddress;        */
        81,           /*   uint16    NvBlockBaseNumber;          */
        60,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_REFUEL_Logger_VAR   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_REFUEL_Logger_VAR_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_REFUEL_Logger_VAR,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_REFUEL_Logger_VAR,        /*   uint8*    RomBlockDataAddress;        */
        83,           /*   uint16    NvBlockBaseNumber;          */
        52,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_COMPONENTS_Cfg_CONST   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_COMPONENTS_Cfg_CONST_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_COMPONENTS_Cfg_CONST,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_COMPONENTS_Cfg_CONST,        /*   uint8*    RomBlockDataAddress;        */
        85,           /*   uint16    NvBlockBaseNumber;          */
        116,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_TANK_Variant_CONST   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_TANK_Variant_CONST_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_TANK_Variant_CONST,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_TANK_Variant_CONST,        /*   uint8*    RomBlockDataAddress;        */
        87,           /*   uint16    NvBlockBaseNumber;          */
        18,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Dev_Messages   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_Dev_Messages_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_Dev_Messages,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_Dev_Messages,        /*   uint8*    RomBlockDataAddress;        */
        89,           /*   uint16    NvBlockBaseNumber;          */
        28,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Recorder_VAR   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_Recorder_VAR_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_Recorder_VAR,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_Recorder_VAR,        /*   uint8*    RomBlockDataAddress;        */
        91,           /*   uint16    NvBlockBaseNumber;          */
        104,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_OperatingTime_VAR   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_OperatingTime_VAR_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_OperatingTime_VAR,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_OperatingTime_VAR,        /*   uint8*    RomBlockDataAddress;        */
        93,           /*   uint16    NvBlockBaseNumber;          */
        12,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_AC_Curve_Scales_VAR   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_AC_Curve_Scales_VAR_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_DIAG_AC_Curve_Scales_VAR,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_DIAG_AC_Curve_Scales_VAR,        /*   uint8*    RomBlockDataAddress;        */
        95,           /*   uint16    NvBlockBaseNumber;          */
        60,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_AC_IlluminationCfg_VAR_0   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_AC_IlluminationCfg_VAR_0_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_DIAG_AC_IlluminationCfg_VAR_0,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_DIAG_AC_IlluminationCfg_VAR_0,        /*   uint8*    RomBlockDataAddress;        */
        97,           /*   uint16    NvBlockBaseNumber;          */
        60,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_AC_IlluminationCfg_VAR_1   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_AC_IlluminationCfg_VAR_1_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_DIAG_AC_IlluminationCfg_VAR_1,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_DIAG_AC_IlluminationCfg_VAR_1,        /*   uint8*    RomBlockDataAddress;        */
        99,           /*   uint16    NvBlockBaseNumber;          */
        52,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_AC_IlluminationCfg_VAR_3   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_AC_IlluminationCfg_VAR_3_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_DIAG_AC_IlluminationCfg_VAR_3,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_DIAG_AC_IlluminationCfg_VAR_3,        /*   uint8*    RomBlockDataAddress;        */
        101,           /*   uint16    NvBlockBaseNumber;          */
        60,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_SRV_TKM_ZvCrH_TKM_ZvCrHPimTkKeyInCarNeed   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_SRV_TKM_ZvCrH_TKM_ZvCrHPimTkKeyInCarNeed_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_SRV_TKM_ZvCrH_TKM_ZvCrHPimTkKeyInCarNeed,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_SRV_TKM_ZvCrH_TKM_ZvCrHPimTkKeyInCarNeed,        /*   uint8*    RomBlockDataAddress;        */
        103,           /*   uint16    NvBlockBaseNumber;          */
        16,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_SAFETY_RECORD_VAR   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_SAFETY_RECORD_VAR_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_SAFETY_RECORD_VAR,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_SAFETY_RECORD_VAR,        /*   uint8*    RomBlockDataAddress;        */
        105,           /*   uint16    NvBlockBaseNumber;          */
        28,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_KsNvmBlockGfaKey_0   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_KsNvmBlockGfaKey_0_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_KsNvmBlockGfaKey_0,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_KsNvmBlockGfaKey_0,        /*   uint8*    RomBlockDataAddress;        */
        107,           /*   uint16    NvBlockBaseNumber;          */
        64,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_KsNvmBlockGfaKey_1   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_KsNvmBlockGfaKey_1_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_KsNvmBlockGfaKey_1,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_KsNvmBlockGfaKey_1,        /*   uint8*    RomBlockDataAddress;        */
        108,           /*   uint16    NvBlockBaseNumber;          */
        64,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_KsNvmBlockMisc_0   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_KsNvmBlockMisc_0_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_KsNvmBlockMisc_0,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_KsNvmBlockMisc_0,        /*   uint8*    RomBlockDataAddress;        */
        109,           /*   uint16    NvBlockBaseNumber;          */
        16,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_KsNvmBlockMisc_1   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_KsNvmBlockMisc_1_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_KsNvmBlockMisc_1,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_KsNvmBlockMisc_1,        /*   uint8*    RomBlockDataAddress;        */
        110,           /*   uint16    NvBlockBaseNumber;          */
        16,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_CAN_VAR   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_CAN_VAR_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_CAN_VAR,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_CAN_VAR,        /*   uint8*    RomBlockDataAddress;        */
        111,           /*   uint16    NvBlockBaseNumber;          */
        4,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Recorder_VAR_2   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_Recorder_VAR_2_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_Recorder_VAR_2,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_Recorder_VAR_2,        /*   uint8*    RomBlockDataAddress;        */
        113,           /*   uint16    NvBlockBaseNumber;          */
        50,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NvM_VKMS   */
    {
        VKMS_NvM_InitBlockCallback,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_NvM_VKMS_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&VKMS_NvRamBlock,        /*   uint8*    RamBlockDataAddress;        */
        NULL,        /*   uint8*    RomBlockDataAddress;        */
        115,           /*   uint16    NvBlockBaseNumber;          */
        2,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        9,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        1,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_PersistentData   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_PersistentData_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        NULL,        /*   uint8*    RamBlockDataAddress;        */
        NULL,        /*   uint8*    RomBlockDataAddress;        */
        117,           /*   uint16    NvBlockBaseNumber;          */
        30,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        9,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_32,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        0,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_ConfigurationFingerprint_Data   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_ConfigurationFingerprint_Data_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        NULL,        /*   uint8*    RamBlockDataAddress;        */
        NULL,        /*   uint8*    RomBlockDataAddress;        */
        118,           /*   uint16    NvBlockBaseNumber;          */
        514,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        9,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_32,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        0,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemAdmin   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Dem_NvM_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Dem_Cfg_OpCycle,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Dem_Cfg_OpCycleInit,        /*   uint8*    RomBlockDataAddress;        */
        119,           /*   uint16    NvBlockBaseNumber;          */
        10,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_8,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemStatus   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Dem_NvM_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Dem_Cfg_StatusData,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Dem_Cfg_StatusDataInit,        /*   uint8*    RomBlockDataAddress;        */
        120,           /*   uint16    NvBlockBaseNumber;          */
        182,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_8,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_000   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Dem_NvM_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Dem_PrimaryEntry_0,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Dem_MemoryEntryInit,        /*   uint8*    RomBlockDataAddress;        */
        121,           /*   uint16    NvBlockBaseNumber;          */
        36,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_8,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_001   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Dem_NvM_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Dem_PrimaryEntry_1,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Dem_MemoryEntryInit,        /*   uint8*    RomBlockDataAddress;        */
        122,           /*   uint16    NvBlockBaseNumber;          */
        36,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_8,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_002   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Dem_NvM_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Dem_PrimaryEntry_2,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Dem_MemoryEntryInit,        /*   uint8*    RomBlockDataAddress;        */
        123,           /*   uint16    NvBlockBaseNumber;          */
        36,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_8,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_003   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Dem_NvM_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Dem_PrimaryEntry_3,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Dem_MemoryEntryInit,        /*   uint8*    RomBlockDataAddress;        */
        124,           /*   uint16    NvBlockBaseNumber;          */
        36,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_8,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_004   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Dem_NvM_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Dem_PrimaryEntry_4,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Dem_MemoryEntryInit,        /*   uint8*    RomBlockDataAddress;        */
        125,           /*   uint16    NvBlockBaseNumber;          */
        36,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_8,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_005   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Dem_NvM_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Dem_PrimaryEntry_5,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Dem_MemoryEntryInit,        /*   uint8*    RomBlockDataAddress;        */
        126,           /*   uint16    NvBlockBaseNumber;          */
        36,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_8,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_006   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Dem_NvM_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Dem_PrimaryEntry_6,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Dem_MemoryEntryInit,        /*   uint8*    RomBlockDataAddress;        */
        127,           /*   uint16    NvBlockBaseNumber;          */
        36,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_8,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_007   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Dem_NvM_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Dem_PrimaryEntry_7,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Dem_MemoryEntryInit,        /*   uint8*    RomBlockDataAddress;        */
        128,           /*   uint16    NvBlockBaseNumber;          */
        36,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_8,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_008   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Dem_NvM_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Dem_PrimaryEntry_8,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Dem_MemoryEntryInit,        /*   uint8*    RomBlockDataAddress;        */
        129,           /*   uint16    NvBlockBaseNumber;          */
        36,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_8,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_009   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Dem_NvM_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Dem_PrimaryEntry_9,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Dem_MemoryEntryInit,        /*   uint8*    RomBlockDataAddress;        */
        130,           /*   uint16    NvBlockBaseNumber;          */
        36,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_8,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_010   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Dem_NvM_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Dem_PrimaryEntry_10,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Dem_MemoryEntryInit,        /*   uint8*    RomBlockDataAddress;        */
        131,           /*   uint16    NvBlockBaseNumber;          */
        36,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_8,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_011   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Dem_NvM_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Dem_PrimaryEntry_11,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Dem_MemoryEntryInit,        /*   uint8*    RomBlockDataAddress;        */
        132,           /*   uint16    NvBlockBaseNumber;          */
        36,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_8,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_012   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Dem_NvM_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Dem_PrimaryEntry_12,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Dem_MemoryEntryInit,        /*   uint8*    RomBlockDataAddress;        */
        133,           /*   uint16    NvBlockBaseNumber;          */
        36,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_8,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_013   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Dem_NvM_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Dem_PrimaryEntry_13,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Dem_MemoryEntryInit,        /*   uint8*    RomBlockDataAddress;        */
        134,           /*   uint16    NvBlockBaseNumber;          */
        36,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_8,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_014   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Dem_NvM_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Dem_PrimaryEntry_14,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Dem_MemoryEntryInit,        /*   uint8*    RomBlockDataAddress;        */
        135,           /*   uint16    NvBlockBaseNumber;          */
        36,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_8,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_015   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Dem_NvM_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Dem_PrimaryEntry_15,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Dem_MemoryEntryInit,        /*   uint8*    RomBlockDataAddress;        */
        136,           /*   uint16    NvBlockBaseNumber;          */
        36,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_8,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_016   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Dem_NvM_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Dem_PrimaryEntry_16,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Dem_MemoryEntryInit,        /*   uint8*    RomBlockDataAddress;        */
        137,           /*   uint16    NvBlockBaseNumber;          */
        36,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_8,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_017   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Dem_NvM_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Dem_PrimaryEntry_17,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Dem_MemoryEntryInit,        /*   uint8*    RomBlockDataAddress;        */
        138,           /*   uint16    NvBlockBaseNumber;          */
        36,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_8,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_018   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Dem_NvM_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Dem_PrimaryEntry_18,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Dem_MemoryEntryInit,        /*   uint8*    RomBlockDataAddress;        */
        139,           /*   uint16    NvBlockBaseNumber;          */
        36,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_8,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_019   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Dem_NvM_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Dem_PrimaryEntry_19,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Dem_MemoryEntryInit,        /*   uint8*    RomBlockDataAddress;        */
        140,           /*   uint16    NvBlockBaseNumber;          */
        36,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_8,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_020   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Dem_NvM_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Dem_PrimaryEntry_20,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Dem_MemoryEntryInit,        /*   uint8*    RomBlockDataAddress;        */
        141,           /*   uint16    NvBlockBaseNumber;          */
        36,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_8,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_021   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Dem_NvM_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Dem_PrimaryEntry_21,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Dem_MemoryEntryInit,        /*   uint8*    RomBlockDataAddress;        */
        142,           /*   uint16    NvBlockBaseNumber;          */
        36,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_8,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_022   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Dem_NvM_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Dem_PrimaryEntry_22,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Dem_MemoryEntryInit,        /*   uint8*    RomBlockDataAddress;        */
        143,           /*   uint16    NvBlockBaseNumber;          */
        36,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_8,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_023   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Dem_NvM_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Dem_PrimaryEntry_23,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Dem_MemoryEntryInit,        /*   uint8*    RomBlockDataAddress;        */
        144,           /*   uint16    NvBlockBaseNumber;          */
        36,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_8,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_024   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Dem_NvM_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Dem_PrimaryEntry_24,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Dem_MemoryEntryInit,        /*   uint8*    RomBlockDataAddress;        */
        145,           /*   uint16    NvBlockBaseNumber;          */
        36,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_8,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_025   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Dem_NvM_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Dem_PrimaryEntry_25,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Dem_MemoryEntryInit,        /*   uint8*    RomBlockDataAddress;        */
        146,           /*   uint16    NvBlockBaseNumber;          */
        36,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_8,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_026   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Dem_NvM_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Dem_PrimaryEntry_26,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Dem_MemoryEntryInit,        /*   uint8*    RomBlockDataAddress;        */
        147,           /*   uint16    NvBlockBaseNumber;          */
        36,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_8,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_027   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Dem_NvM_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Dem_PrimaryEntry_27,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Dem_MemoryEntryInit,        /*   uint8*    RomBlockDataAddress;        */
        148,           /*   uint16    NvBlockBaseNumber;          */
        36,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_8,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_028   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Dem_NvM_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Dem_PrimaryEntry_28,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Dem_MemoryEntryInit,        /*   uint8*    RomBlockDataAddress;        */
        149,           /*   uint16    NvBlockBaseNumber;          */
        36,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_8,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_029   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Dem_NvM_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Dem_PrimaryEntry_29,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Dem_MemoryEntryInit,        /*   uint8*    RomBlockDataAddress;        */
        150,           /*   uint16    NvBlockBaseNumber;          */
        36,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_8,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Dcm_86Infinitewindowtimestatus   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Dem_NvM_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Dcm_RAM86Infinitewindowtimestatus,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Dcm_ROM86Infinitewindowtimestatus,        /*   uint8*    RomBlockDataAddress;        */
        151,           /*   uint16    NvBlockBaseNumber;          */
        1,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_8,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_LogData   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        NULL,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        NULL,        /*   uint8*    RamBlockDataAddress;        */
        NULL,        /*   uint8*    RomBlockDataAddress;        */
        152,           /*   uint16    NvBlockBaseNumber;          */
        19,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        8,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        54,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        0,           /*   uint8     RomBlockNum;                */
        CRC_32,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_DATASET_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        0,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_PublicKey   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_PublicKey_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&SfdKey,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&SfdKey_Default,        /*   uint8*    RomBlockDataAddress;        */
        206,           /*   uint16    NvBlockBaseNumber;          */
        64,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_32,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_SecDiag   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_SecDiag_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_SecDiag,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_SecDiag,        /*   uint8*    RomBlockDataAddress;        */
        207,           /*   uint16    NvBlockBaseNumber;          */
        152,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_32,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        0,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_AdaptationChannel_VAR_2   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_AdaptationChannel_VAR_2_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_DIAG_AdaptationChannel_VAR_2,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_DIAG_AdaptationChannel_VAR_2,        /*   uint8*    RomBlockDataAddress;        */
        208,           /*   uint16    NvBlockBaseNumber;          */
        16,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_WLTP_Odo_VAR   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_WLTP_Odo_VAR_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_WLTP_Odo_VAR,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&NvM_Manager_ROM_Default_WLTP_Odo_VAR,        /*   uint8*    RomBlockDataAddress;        */
        210,           /*   uint16    NvBlockBaseNumber;          */
        124,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_SecDiag_1   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_SecDiag_1_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_SecDiag_1,        /*   uint8*    RamBlockDataAddress;        */
        NULL,        /*   uint8*    RomBlockDataAddress;        */
        212,           /*   uint16    NvBlockBaseNumber;          */
        72,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        0,           /*   uint8     MaxNumReadRetries;          */
        0,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_32,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        0,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
};
const NvM_JobQueueManagementType NvM_JobQueueManagementTable[NVM_MAX_JOB_PRIORITY] = 
{
    {
        0,                                  /*JobPriority*/
        0,                                  /*Index*/
        &NvM_JobQueuePriority0,              /*JobQueueAddress*/
        NUM_OF_PRIO_0_BLOCKS                /*JobQueueLength*/
    },
    {
        1,                                  /*JobPriority*/
        255,                                  /*Index*/
        NULL,                               /*JobQueueAddress*/
        0                                   /*JobQueueLength*/
    },
    {
        2,                                  /*JobPriority*/
        255,                                  /*Index*/
        NULL,                               /*JobQueueAddress*/
        0                                   /*JobQueueLength*/
    },
    {
        3,                                  /*JobPriority*/
        255,                                  /*Index*/
        NULL,                               /*JobQueueAddress*/
        0                                   /*JobQueueLength*/
    },
    {
        4,                                  /*JobPriority*/
        255,                                  /*Index*/
        NULL,                               /*JobQueueAddress*/
        0                                   /*JobQueueLength*/
    },
    {
        5,                                  /*JobPriority*/
        255,                                  /*Index*/
        NULL,                               /*JobQueueAddress*/
        0                                   /*JobQueueLength*/
    },
    {
        6,                                  /*JobPriority*/
        255,                                  /*Index*/
        NULL,                               /*JobQueueAddress*/
        0                                   /*JobQueueLength*/
    },
    {
        7,                                  /*JobPriority*/
        255,                                  /*Index*/
        NULL,                               /*JobQueueAddress*/
        0                                   /*JobQueueLength*/
    },
    {
        8,                                  /*JobPriority*/
        1,                                  /*Index*/
        &NvM_JobQueuePriority8,              /*JobQueueAddress*/
        NUM_OF_PRIO_8_BLOCKS                /*JobQueueLength*/
    },
    {
        9,                                  /*JobPriority*/
        2,                                  /*Index*/
        &NvM_JobQueuePriority9,              /*JobQueueAddress*/
        NUM_OF_PRIO_9_BLOCKS                /*JobQueueLength*/
    },
    {
        10,                                  /*JobPriority*/
        255,                                  /*Index*/
        NULL,                               /*JobQueueAddress*/
        0                                   /*JobQueueLength*/
    },
    {
        11,                                  /*JobPriority*/
        255,                                  /*Index*/
        NULL,                               /*JobQueueAddress*/
        0                                   /*JobQueueLength*/
    },
    {
        12,                                  /*JobPriority*/
        255,                                  /*Index*/
        NULL,                               /*JobQueueAddress*/
        0                                   /*JobQueueLength*/
    },
    {
        13,                                  /*JobPriority*/
        255,                                  /*Index*/
        NULL,                               /*JobQueueAddress*/
        0                                   /*JobQueueLength*/
    },
    {
        14,                                  /*JobPriority*/
        255,                                  /*Index*/
        NULL,                               /*JobQueueAddress*/
        0                                   /*JobQueueLength*/
    },
    {
        15,                                  /*JobPriority*/
        255,                                  /*Index*/
        NULL,                               /*JobQueueAddress*/
        0                                   /*JobQueueLength*/
    },
    {
        16,                                  /*JobPriority*/
        3,                                  /*Index*/
        &NvM_JobQueuePriority16,              /*JobQueueAddress*/
        NUM_OF_PRIO_16_BLOCKS                /*JobQueueLength*/
    },
    {
        17,                                  /*JobPriority*/
        255,                                  /*Index*/
        NULL,                               /*JobQueueAddress*/
        0                                   /*JobQueueLength*/
    },
    {
        18,                                  /*JobPriority*/
        255,                                  /*Index*/
        NULL,                               /*JobQueueAddress*/
        0                                   /*JobQueueLength*/
    },
    {
        19,                                  /*JobPriority*/
        255,                                  /*Index*/
        NULL,                               /*JobQueueAddress*/
        0                                   /*JobQueueLength*/
    },
    {
        20,                                  /*JobPriority*/
        255,                                  /*Index*/
        NULL,                               /*JobQueueAddress*/
        0                                   /*JobQueueLength*/
    },
    {
        21,                                  /*JobPriority*/
        255,                                  /*Index*/
        NULL,                               /*JobQueueAddress*/
        0                                   /*JobQueueLength*/
    },
    {
        22,                                  /*JobPriority*/
        255,                                  /*Index*/
        NULL,                               /*JobQueueAddress*/
        0                                   /*JobQueueLength*/
    },
    {
        23,                                  /*JobPriority*/
        255,                                  /*Index*/
        NULL,                               /*JobQueueAddress*/
        0                                   /*JobQueueLength*/
    },
    {
        24,                                  /*JobPriority*/
        255,                                  /*Index*/
        NULL,                               /*JobQueueAddress*/
        0                                   /*JobQueueLength*/
    },
    {
        25,                                  /*JobPriority*/
        255,                                  /*Index*/
        NULL,                               /*JobQueueAddress*/
        0                                   /*JobQueueLength*/
    },
    {
        26,                                  /*JobPriority*/
        255,                                  /*Index*/
        NULL,                               /*JobQueueAddress*/
        0                                   /*JobQueueLength*/
    },
    {
        27,                                  /*JobPriority*/
        255,                                  /*Index*/
        NULL,                               /*JobQueueAddress*/
        0                                   /*JobQueueLength*/
    },
    {
        28,                                  /*JobPriority*/
        255,                                  /*Index*/
        NULL,                               /*JobQueueAddress*/
        0                                   /*JobQueueLength*/
    },
    {
        29,                                  /*JobPriority*/
        255,                                  /*Index*/
        NULL,                               /*JobQueueAddress*/
        0                                   /*JobQueueLength*/
    },
    {
        30,                                  /*JobPriority*/
        255,                                  /*Index*/
        NULL,                               /*JobQueueAddress*/
        0                                   /*JobQueueLength*/
    },
    {
        31,                                  /*JobPriority*/
        255,                                  /*Index*/
        NULL,                               /*JobQueueAddress*/
        0                                   /*JobQueueLength*/
    },
};
/*****************************************************************************
 *                                 Locally used Variable Declarations         *
 *----------------------------------------------------------------------------*
 * Declaration shall be followed by a comment that gives the following info.  *
 * about the variable.                                                        *
 * purpose, critical section, unit, and resolution                            *
 ******************************************************************************/

/*****************************************************************************
 *                              Limited Scope Prototypes                      *
 ******************************************************************************/

/*****************************************************************************
 *                   Functions                                                *
 ******************************************************************************/

extern void NvMExt_MultipleJobEndNotification(uint8 ServiceId, NvM_RequestResultType JobResult);
void NvM_MultiBlockCallbackFunction(uint8 ServiceId, NvM_RequestResultType JobResult)
{
    NvMExt_MultipleJobEndNotification(ServiceId, JobResult);
}

void NvM_EnterCriticalSection(void)
{
  SchM_Enter_NvM_NVM_EXCLUSIVE_AREA_0();
}

void NvM_ExitCriticalSection(void)
{
  SchM_Exit_NvM_NVM_EXCLUSIVE_AREA_0();
}


#define NVM_CONST_SEC_END
 #include "MemMap.h"

#define NVM_DATA_SEC_END
 #include "MemMap.h"

#define NVM_CODE_SEC_END
 #include "MemMap.h"

#endif    /* */
/* end of file */
/*Tool Version Information*/
/* Tool Version - v2.2.11 */
/****************************************************************
Created Time: 6/28/2022 10:03:27 AM
****************************************************************/
