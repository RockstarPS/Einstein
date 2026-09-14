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

File Name        :  Fee_Cfg.c
Module Short Name:  Fee_Cfg.c
VOBName          :  
Author           :  
Description      :  Generated File
Organization     :  Driver Information Software Section,
                    Visteon Corporation

******************************************************************************/

#ifndef FEE_CFG_C
#define FEE_CFG_C
/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "Fee_Cfg.h"

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/


/*****************************************************************************
*                                Globally  accessed Variable Declarations    *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/
const Fee_BlockConfigType Fee_BlockConfig[FEE_NUM_BLOCKS]=
{
    {
        0,            /*   uint16 BlockNumber;    */
        0,            /*   uint16 BlockSize;      */
        0,            /*   uint8  PartitionNo;    */
        0             /*   boolean ImmediateData; */
    },
    {
        1,            /*   uint16 BlockNumber;    */
        8,            /*   uint16 BlockSize;      */
        0,            /*   uint8  PartitionNo;    */
        0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Com_Cfg_VAR*/
    {
          2,            /*   uint16 BlockNumber;    */
          104,           /*   uint16 BlockSize;      */
          0,            /*   uint8  PartitionNo;     Partition cfg  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Com_Cfg_VAR*/
    {
          3,            /*   uint16 BlockNumber;    */
          104,           /*   uint16 BlockSize;      */
          0,            /*   uint8  PartitionNo;     Partition cfg  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Gamma_Adjustment_VAR*/
    {
          4,            /*   uint16 BlockNumber;    */
          248,           /*   uint16 BlockSize;      */
          0,            /*   uint8  PartitionNo;     Partition cfg  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Gamma_Adjustment_VAR*/
    {
          5,            /*   uint16 BlockNumber;    */
          248,           /*   uint16 BlockSize;      */
          0,            /*   uint8  PartitionNo;     Partition cfg  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_RGB_Calibration_VAR*/
    {
          6,            /*   uint16 BlockNumber;    */
          384,           /*   uint16 BlockSize;      */
          0,            /*   uint8  PartitionNo;     Partition cfg  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_RGB_Calibration_VAR*/
    {
          7,            /*   uint16 BlockNumber;    */
          384,           /*   uint16 BlockSize;      */
          0,            /*   uint8  PartitionNo;     Partition cfg  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_Adjustment_VAR*/
    {
          8,            /*   uint16 BlockNumber;    */
          228,           /*   uint16 BlockSize;      */
          0,            /*   uint8  PartitionNo;     Partition cfg  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_Adjustment_VAR*/
    {
          9,            /*   uint16 BlockNumber;    */
          228,           /*   uint16 BlockSize;      */
          0,            /*   uint8  PartitionNo;     Partition cfg  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Nvm_Block_Reserved_4*/
    {
          10,            /*   uint16 BlockNumber;    */
          168,           /*   uint16 BlockSize;      */
          6,            /*   uint8  PartitionNo;     Partitions Const 2  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Nvm_Block_Reserved_4*/
    {
          11,            /*   uint16 BlockNumber;    */
          168,           /*   uint16 BlockSize;      */
          6,            /*   uint8  PartitionNo;     Partitions Const 2  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_RPM_Gauge_FIR_Coefficients*/
    {
          12,            /*   uint16 BlockNumber;    */
          68,           /*   uint16 BlockSize;      */
          0,            /*   uint8  PartitionNo;     Partition cfg  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_RPM_Gauge_FIR_Coefficients*/
    {
          13,            /*   uint16 BlockNumber;    */
          68,           /*   uint16 BlockSize;      */
          0,            /*   uint8  PartitionNo;     Partition cfg  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Bcct_Cfg_VAR_1*/
    {
          14,            /*   uint16 BlockNumber;    */
          128,           /*   uint16 BlockSize;      */
          0,            /*   uint8  PartitionNo;     Partition cfg  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Bcct_Cfg_VAR_1*/
    {
          15,            /*   uint16 BlockNumber;    */
          128,           /*   uint16 BlockSize;      */
          0,            /*   uint8  PartitionNo;     Partition cfg  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Bcct_Cfg_VAR_2*/
    {
          16,            /*   uint16 BlockNumber;    */
          144,           /*   uint16 BlockSize;      */
          0,            /*   uint8  PartitionNo;     Partition cfg  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Bcct_Cfg_VAR_2*/
    {
          17,            /*   uint16 BlockNumber;    */
          144,           /*   uint16 BlockSize;      */
          0,            /*   uint8  PartitionNo;     Partition cfg  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Bcct_Cfg_VAR_3*/
    {
          18,            /*   uint16 BlockNumber;    */
          124,           /*   uint16 BlockSize;      */
          0,            /*   uint8  PartitionNo;     Partition cfg  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Bcct_Cfg_VAR_3*/
    {
          19,            /*   uint16 BlockNumber;    */
          124,           /*   uint16 BlockSize;      */
          0,            /*   uint8  PartitionNo;     Partition cfg  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Bargraph_VAR*/
    {
          20,            /*   uint16 BlockNumber;    */
          24,           /*   uint16 BlockSize;      */
          0,            /*   uint8  PartitionNo;     Partition cfg  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Bargraph_VAR*/
    {
          21,            /*   uint16 BlockNumber;    */
          24,           /*   uint16 BlockSize;      */
          0,            /*   uint8  PartitionNo;     Partition cfg  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Nvm_Block_Reserved_1*/
    {
          22,            /*   uint16 BlockNumber;    */
          68,           /*   uint16 BlockSize;      */
          5,            /*   uint8  PartitionNo;     Partitions Const 1  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Nvm_Block_Reserved_1*/
    {
          23,            /*   uint16 BlockNumber;    */
          68,           /*   uint16 BlockSize;      */
          5,            /*   uint8  PartitionNo;     Partitions Const 1  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Nvm_Block_Reserved_2*/
    {
          24,            /*   uint16 BlockNumber;    */
          36,           /*   uint16 BlockSize;      */
          6,            /*   uint8  PartitionNo;     Partitions Const 2  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Nvm_Block_Reserved_2*/
    {
          25,            /*   uint16 BlockNumber;    */
          36,           /*   uint16 BlockSize;      */
          6,            /*   uint8  PartitionNo;     Partitions Const 2  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Bargraph_Hysteresis_Coolant*/
    {
          26,            /*   uint16 BlockNumber;    */
          20,           /*   uint16 BlockSize;      */
          6,            /*   uint8  PartitionNo;     Partitions Const 2  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Bargraph_Hysteresis_Coolant*/
    {
          27,            /*   uint16 BlockNumber;    */
          20,           /*   uint16 BlockSize;      */
          6,            /*   uint8  PartitionNo;     Partitions Const 2  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Bargraph_Treshold_Switch_Coolant*/
    {
          28,            /*   uint16 BlockNumber;    */
          20,           /*   uint16 BlockSize;      */
          6,            /*   uint8  PartitionNo;     Partitions Const 2  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Bargraph_Treshold_Switch_Coolant*/
    {
          29,            /*   uint16 BlockNumber;    */
          20,           /*   uint16 BlockSize;      */
          6,            /*   uint8  PartitionNo;     Partitions Const 2  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_EEPVersionInfo_CONST*/
    {
          30,            /*   uint16 BlockNumber;    */
          12,           /*   uint16 BlockSize;      */
          6,            /*   uint8  PartitionNo;     Partitions Const 2  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_EEPVersionInfo_CONST*/
    {
          31,            /*   uint16 BlockNumber;    */
          12,           /*   uint16 BlockSize;      */
          6,            /*   uint8  PartitionNo;     Partitions Const 2  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Odometer_0*/
    {
          32,            /*   uint16 BlockNumber;    */
          16,           /*   uint16 BlockSize;      */
          3,            /*   uint8  PartitionNo;     Partition Odo  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Odometer_1*/
    {
          33,            /*   uint16 BlockNumber;    */
          16,           /*   uint16 BlockSize;      */
          3,            /*   uint8  PartitionNo;     Partition Odo  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Odometer_2*/
    {
          34,            /*   uint16 BlockNumber;    */
          16,           /*   uint16 BlockSize;      */
          3,            /*   uint8  PartitionNo;     Partition Odo  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_EOL_VAR*/
    {
          35,            /*   uint16 BlockNumber;    */
          40,           /*   uint16 BlockSize;      */
          6,            /*   uint8  PartitionNo;     Partitions Const 2  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_EOL_VAR*/
    {
          36,            /*   uint16 BlockNumber;    */
          40,           /*   uint16 BlockSize;      */
          6,            /*   uint8  PartitionNo;     Partitions Const 2  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_EOL_DiagCfg_CONST*/
    {
          37,            /*   uint16 BlockNumber;    */
          64,           /*   uint16 BlockSize;      */
          6,            /*   uint8  PartitionNo;     Partitions Const 2  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_EOL_DiagCfg_CONST*/
    {
          38,            /*   uint16 BlockNumber;    */
          64,           /*   uint16 BlockSize;      */
          6,            /*   uint8  PartitionNo;     Partitions Const 2  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_EOL_HWCalib_CONST*/
    {
          39,            /*   uint16 BlockNumber;    */
          56,           /*   uint16 BlockSize;      */
          0,            /*   uint8  PartitionNo;     Partition cfg  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_EOL_HWCalib_CONST*/
    {
          40,            /*   uint16 BlockNumber;    */
          56,           /*   uint16 BlockSize;      */
          0,            /*   uint8  PartitionNo;     Partition cfg  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_EOL_PartNumber_CONST*/
    {
          41,            /*   uint16 BlockNumber;    */
          40,           /*   uint16 BlockSize;      */
          0,            /*   uint8  PartitionNo;     Partition cfg  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_EOL_PartNumber_CONST*/
    {
          42,            /*   uint16 BlockNumber;    */
          40,           /*   uint16 BlockSize;      */
          0,            /*   uint8  PartitionNo;     Partition cfg  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_USER_PROFILE1*/
    {
          43,            /*   uint16 BlockNumber;    */
          64,           /*   uint16 BlockSize;      */
          1,            /*   uint8  PartitionNo;     Partition Profile  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_USER_PROFILE1*/
    {
          44,            /*   uint16 BlockNumber;    */
          64,           /*   uint16 BlockSize;      */
          1,            /*   uint8  PartitionNo;     Partition Profile  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_USER_PROFILE2*/
    {
          45,            /*   uint16 BlockNumber;    */
          64,           /*   uint16 BlockSize;      */
          1,            /*   uint8  PartitionNo;     Partition Profile  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_USER_PROFILE2*/
    {
          46,            /*   uint16 BlockNumber;    */
          64,           /*   uint16 BlockSize;      */
          1,            /*   uint8  PartitionNo;     Partition Profile  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_USER_PROFILE3*/
    {
          47,            /*   uint16 BlockNumber;    */
          64,           /*   uint16 BlockSize;      */
          1,            /*   uint8  PartitionNo;     Partition Profile  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_USER_PROFILE3*/
    {
          48,            /*   uint16 BlockNumber;    */
          64,           /*   uint16 BlockSize;      */
          1,            /*   uint8  PartitionNo;     Partition Profile  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_USER_PROFILE4*/
    {
          49,            /*   uint16 BlockNumber;    */
          64,           /*   uint16 BlockSize;      */
          1,            /*   uint8  PartitionNo;     Partition Profile  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_USER_PROFILE4*/
    {
          50,            /*   uint16 BlockNumber;    */
          64,           /*   uint16 BlockSize;      */
          1,            /*   uint8  PartitionNo;     Partition Profile  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_USER_PROFILE5*/
    {
          51,            /*   uint16 BlockNumber;    */
          64,           /*   uint16 BlockSize;      */
          1,            /*   uint8  PartitionNo;     Partition Profile  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_USER_PROFILE5*/
    {
          52,            /*   uint16 BlockNumber;    */
          64,           /*   uint16 BlockSize;      */
          1,            /*   uint8  PartitionNo;     Partition Profile  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_USER_PROFILE6*/
    {
          53,            /*   uint16 BlockNumber;    */
          64,           /*   uint16 BlockSize;      */
          1,            /*   uint8  PartitionNo;     Partition Profile  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_USER_PROFILE6*/
    {
          54,            /*   uint16 BlockNumber;    */
          64,           /*   uint16 BlockSize;      */
          1,            /*   uint8  PartitionNo;     Partition Profile  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_USER_PROFILE7*/
    {
          55,            /*   uint16 BlockNumber;    */
          64,           /*   uint16 BlockSize;      */
          1,            /*   uint8  PartitionNo;     Partition Profile  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_USER_PROFILE7*/
    {
          56,            /*   uint16 BlockNumber;    */
          64,           /*   uint16 BlockSize;      */
          1,            /*   uint8  PartitionNo;     Partition Profile  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_USER_PROFILE0*/
    {
          57,            /*   uint16 BlockNumber;    */
          64,           /*   uint16 BlockSize;      */
          1,            /*   uint8  PartitionNo;     Partition Profile  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_USER_PROFILE0*/
    {
          58,            /*   uint16 BlockNumber;    */
          64,           /*   uint16 BlockSize;      */
          1,            /*   uint8  PartitionNo;     Partition Profile  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_EOL_HWCalib_CONST_1*/
    {
          59,            /*   uint16 BlockNumber;    */
          56,           /*   uint16 BlockSize;      */
          6,            /*   uint8  PartitionNo;     Partitions Const 2  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_EOL_HWCalib_CONST_1*/
    {
          60,            /*   uint16 BlockNumber;    */
          56,           /*   uint16 BlockSize;      */
          6,            /*   uint8  PartitionNo;     Partitions Const 2  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Cluster_Settings*/
    {
          61,            /*   uint16 BlockNumber;    */
          64,           /*   uint16 BlockSize;      */
          5,            /*   uint8  PartitionNo;     Partitions Const 1  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Cluster_Settings*/
    {
          62,            /*   uint16 BlockNumber;    */
          64,           /*   uint16 BlockSize;      */
          5,            /*   uint8  PartitionNo;     Partitions Const 1  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_VariantCoding_CONST*/
    {
          63,            /*   uint16 BlockNumber;    */
          144,           /*   uint16 BlockSize;      */
          6,            /*   uint8  PartitionNo;     Partitions Const 2  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_VariantCoding_CONST*/
    {
          64,            /*   uint16 BlockNumber;    */
          144,           /*   uint16 BlockSize;      */
          6,            /*   uint8  PartitionNo;     Partitions Const 2  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_COMPONENTS_Cfg_VAR*/
    {
          65,            /*   uint16 BlockNumber;    */
          56,           /*   uint16 BlockSize;      */
          2,            /*   uint8  PartitionNo;     Partition Variable  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_COMPONENTS_Cfg_VAR*/
    {
          66,            /*   uint16 BlockNumber;    */
          56,           /*   uint16 BlockSize;      */
          2,            /*   uint8  PartitionNo;     Partition Variable  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Service_History_Data*/
    {
          67,            /*   uint16 BlockNumber;    */
          260,           /*   uint16 BlockSize;      */
          6,            /*   uint8  PartitionNo;     Partitions Const 2  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Service_History_Data*/
    {
          68,            /*   uint16 BlockNumber;    */
          260,           /*   uint16 BlockSize;      */
          6,            /*   uint8  PartitionNo;     Partitions Const 2  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DtcAgingAdminDataBlock*/
    {
          69,            /*   uint16 BlockNumber;    */
          8,           /*   uint16 BlockSize;      */
          5,            /*   uint8  PartitionNo;     Partitions Const 1  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DtcAgingAdminDataBlock*/
    {
          70,            /*   uint16 BlockNumber;    */
          8,           /*   uint16 BlockSize;      */
          5,            /*   uint8  PartitionNo;     Partitions Const 1  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_VariantCodingCheck_CONST*/
    {
          71,            /*   uint16 BlockNumber;    */
          180,           /*   uint16 BlockSize;      */
          6,            /*   uint8  PartitionNo;     Partitions Const 2  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_VariantCodingCheck_CONST*/
    {
          72,            /*   uint16 BlockNumber;    */
          180,           /*   uint16 BlockSize;      */
          6,            /*   uint8  PartitionNo;     Partitions Const 2  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_ServiceKey_VAR*/
    {
          73,            /*   uint16 BlockNumber;    */
          32,           /*   uint16 BlockSize;      */
          2,            /*   uint8  PartitionNo;     Partition Variable  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_ServiceKey_VAR*/
    {
          74,            /*   uint16 BlockNumber;    */
          32,           /*   uint16 BlockSize;      */
          2,            /*   uint8  PartitionNo;     Partition Variable  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_AC_ServiceCfg_VAR*/
    {
          75,            /*   uint16 BlockNumber;    */
          56,           /*   uint16 BlockSize;      */
          2,            /*   uint8  PartitionNo;     Partition Variable  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_AC_ServiceCfg_VAR*/
    {
          76,            /*   uint16 BlockNumber;    */
          56,           /*   uint16 BlockSize;      */
          2,            /*   uint8  PartitionNo;     Partition Variable  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_AdaptationChannel_VAR_1*/
    {
          77,            /*   uint16 BlockNumber;    */
          56,           /*   uint16 BlockSize;      */
          2,            /*   uint8  PartitionNo;     Partition Variable  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_AdaptationChannel_VAR_1*/
    {
          78,            /*   uint16 BlockNumber;    */
          56,           /*   uint16 BlockSize;      */
          2,            /*   uint8  PartitionNo;     Partition Variable  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DATE_VAR*/
    {
          79,            /*   uint16 BlockNumber;    */
          8,           /*   uint16 BlockSize;      */
          1,            /*   uint8  PartitionNo;     Partition Profile  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DATE_VAR*/
    {
          80,            /*   uint16 BlockNumber;    */
          8,           /*   uint16 BlockSize;      */
          1,            /*   uint8  PartitionNo;     Partition Profile  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_AdaptationChannel_VAR_0*/
    {
          81,            /*   uint16 BlockNumber;    */
          64,           /*   uint16 BlockSize;      */
          2,            /*   uint8  PartitionNo;     Partition Variable  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_AdaptationChannel_VAR_0*/
    {
          82,            /*   uint16 BlockNumber;    */
          64,           /*   uint16 BlockSize;      */
          2,            /*   uint8  PartitionNo;     Partition Variable  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_REFUEL_Logger_VAR*/
    {
          83,            /*   uint16 BlockNumber;    */
          56,           /*   uint16 BlockSize;      */
          6,            /*   uint8  PartitionNo;     Partitions Const 2  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_REFUEL_Logger_VAR*/
    {
          84,            /*   uint16 BlockNumber;    */
          56,           /*   uint16 BlockSize;      */
          6,            /*   uint8  PartitionNo;     Partitions Const 2  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_COMPONENTS_Cfg_CONST*/
    {
          85,            /*   uint16 BlockNumber;    */
          120,           /*   uint16 BlockSize;      */
          6,            /*   uint8  PartitionNo;     Partitions Const 2  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_COMPONENTS_Cfg_CONST*/
    {
          86,            /*   uint16 BlockNumber;    */
          120,           /*   uint16 BlockSize;      */
          6,            /*   uint8  PartitionNo;     Partitions Const 2  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_TANK_Variant_CONST*/
    {
          87,            /*   uint16 BlockNumber;    */
          20,           /*   uint16 BlockSize;      */
          6,            /*   uint8  PartitionNo;     Partitions Const 2  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_TANK_Variant_CONST*/
    {
          88,            /*   uint16 BlockNumber;    */
          20,           /*   uint16 BlockSize;      */
          6,            /*   uint8  PartitionNo;     Partitions Const 2  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Dev_Messages*/
    {
          89,            /*   uint16 BlockNumber;    */
          32,           /*   uint16 BlockSize;      */
          6,            /*   uint8  PartitionNo;     Partitions Const 2  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Dev_Messages*/
    {
          90,            /*   uint16 BlockNumber;    */
          32,           /*   uint16 BlockSize;      */
          6,            /*   uint8  PartitionNo;     Partitions Const 2  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Recorder_VAR*/
    {
          91,            /*   uint16 BlockNumber;    */
          108,           /*   uint16 BlockSize;      */
          6,            /*   uint8  PartitionNo;     Partitions Const 2  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Recorder_VAR*/
    {
          92,            /*   uint16 BlockNumber;    */
          108,           /*   uint16 BlockSize;      */
          6,            /*   uint8  PartitionNo;     Partitions Const 2  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_OperatingTime_VAR*/
    {
          93,            /*   uint16 BlockNumber;    */
          16,           /*   uint16 BlockSize;      */
          2,            /*   uint8  PartitionNo;     Partition Variable  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_OperatingTime_VAR*/
    {
          94,            /*   uint16 BlockNumber;    */
          16,           /*   uint16 BlockSize;      */
          2,            /*   uint8  PartitionNo;     Partition Variable  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_AC_Curve_Scales_VAR*/
    {
          95,            /*   uint16 BlockNumber;    */
          64,           /*   uint16 BlockSize;      */
          6,            /*   uint8  PartitionNo;     Partitions Const 2  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_AC_Curve_Scales_VAR*/
    {
          96,            /*   uint16 BlockNumber;    */
          64,           /*   uint16 BlockSize;      */
          6,            /*   uint8  PartitionNo;     Partitions Const 2  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_AC_IlluminationCfg_VAR_0*/
    {
          97,            /*   uint16 BlockNumber;    */
          64,           /*   uint16 BlockSize;      */
          6,            /*   uint8  PartitionNo;     Partitions Const 2  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_AC_IlluminationCfg_VAR_0*/
    {
          98,            /*   uint16 BlockNumber;    */
          64,           /*   uint16 BlockSize;      */
          6,            /*   uint8  PartitionNo;     Partitions Const 2  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_AC_IlluminationCfg_VAR_1*/
    {
          99,            /*   uint16 BlockNumber;    */
          56,           /*   uint16 BlockSize;      */
          6,            /*   uint8  PartitionNo;     Partitions Const 2  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_AC_IlluminationCfg_VAR_1*/
    {
          100,            /*   uint16 BlockNumber;    */
          56,           /*   uint16 BlockSize;      */
          6,            /*   uint8  PartitionNo;     Partitions Const 2  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_AC_IlluminationCfg_VAR_3*/
    {
          101,            /*   uint16 BlockNumber;    */
          64,           /*   uint16 BlockSize;      */
          6,            /*   uint8  PartitionNo;     Partitions Const 2  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_AC_IlluminationCfg_VAR_3*/
    {
          102,            /*   uint16 BlockNumber;    */
          64,           /*   uint16 BlockSize;      */
          6,            /*   uint8  PartitionNo;     Partitions Const 2  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_SRV_TKM_ZvCrH_TKM_ZvCrHPimTkKeyInCarNeed*/
    {
          103,            /*   uint16 BlockNumber;    */
          20,           /*   uint16 BlockSize;      */
          6,            /*   uint8  PartitionNo;     Partitions Const 2  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_SRV_TKM_ZvCrH_TKM_ZvCrHPimTkKeyInCarNeed*/
    {
          104,            /*   uint16 BlockNumber;    */
          20,           /*   uint16 BlockSize;      */
          6,            /*   uint8  PartitionNo;     Partitions Const 2  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_SAFETY_RECORD_VAR*/
    {
          105,            /*   uint16 BlockNumber;    */
          32,           /*   uint16 BlockSize;      */
          1,            /*   uint8  PartitionNo;     Partition Profile  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_SAFETY_RECORD_VAR*/
    {
          106,            /*   uint16 BlockNumber;    */
          32,           /*   uint16 BlockSize;      */
          1,            /*   uint8  PartitionNo;     Partition Profile  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_KsNvmBlockGfaKey_0*/
    {
          107,            /*   uint16 BlockNumber;    */
          68,           /*   uint16 BlockSize;      */
          6,            /*   uint8  PartitionNo;     Partitions Const 2  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_KsNvmBlockGfaKey_1*/
    {
          108,            /*   uint16 BlockNumber;    */
          68,           /*   uint16 BlockSize;      */
          6,            /*   uint8  PartitionNo;     Partitions Const 2  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_KsNvmBlockMisc_0*/
    {
          109,            /*   uint16 BlockNumber;    */
          20,           /*   uint16 BlockSize;      */
          2,            /*   uint8  PartitionNo;     Partition Variable  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_KsNvmBlockMisc_1*/
    {
          110,            /*   uint16 BlockNumber;    */
          20,           /*   uint16 BlockSize;      */
          2,            /*   uint8  PartitionNo;     Partition Variable  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_CAN_VAR*/
    {
          111,            /*   uint16 BlockNumber;    */
          8,           /*   uint16 BlockSize;      */
          2,            /*   uint8  PartitionNo;     Partition Variable  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_CAN_VAR*/
    {
          112,            /*   uint16 BlockNumber;    */
          8,           /*   uint16 BlockSize;      */
          2,            /*   uint8  PartitionNo;     Partition Variable  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Recorder_VAR_2*/
    {
          113,            /*   uint16 BlockNumber;    */
          52,           /*   uint16 BlockSize;      */
          5,            /*   uint8  PartitionNo;     Partitions Const 1  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Recorder_VAR_2*/
    {
          114,            /*   uint16 BlockNumber;    */
          52,           /*   uint16 BlockSize;      */
          5,            /*   uint8  PartitionNo;     Partitions Const 1  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NvM_VKMS*/
    {
          115,            /*   uint16 BlockNumber;    */
          4,           /*   uint16 BlockSize;      */
          6,            /*   uint8  PartitionNo;     Partitions Const 2  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NvM_VKMS*/
    {
          116,            /*   uint16 BlockNumber;    */
          4,           /*   uint16 BlockSize;      */
          6,            /*   uint8  PartitionNo;     Partitions Const 2  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_PersistentData*/
    {
          117,            /*   uint16 BlockNumber;    */
          36,           /*   uint16 BlockSize;      */
          4,            /*   uint8  PartitionNo;     Partition SFD  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_ConfigurationFingerprint_Data*/
    {
          118,            /*   uint16 BlockNumber;    */
          520,           /*   uint16 BlockSize;      */
          4,            /*   uint8  PartitionNo;     Partition SFD  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemAdmin*/
    {
          119,            /*   uint16 BlockNumber;    */
          12,           /*   uint16 BlockSize;      */
          5,            /*   uint8  PartitionNo;     Partitions Const 1  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemStatus*/
    {
          120,            /*   uint16 BlockNumber;    */
          184,           /*   uint16 BlockSize;      */
          5,            /*   uint8  PartitionNo;     Partitions Const 1  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_000*/
    {
          121,            /*   uint16 BlockNumber;    */
          40,           /*   uint16 BlockSize;      */
          5,            /*   uint8  PartitionNo;     Partitions Const 1  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_001*/
    {
          122,            /*   uint16 BlockNumber;    */
          40,           /*   uint16 BlockSize;      */
          5,            /*   uint8  PartitionNo;     Partitions Const 1  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_002*/
    {
          123,            /*   uint16 BlockNumber;    */
          40,           /*   uint16 BlockSize;      */
          5,            /*   uint8  PartitionNo;     Partitions Const 1  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_003*/
    {
          124,            /*   uint16 BlockNumber;    */
          40,           /*   uint16 BlockSize;      */
          5,            /*   uint8  PartitionNo;     Partitions Const 1  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_004*/
    {
          125,            /*   uint16 BlockNumber;    */
          40,           /*   uint16 BlockSize;      */
          5,            /*   uint8  PartitionNo;     Partitions Const 1  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_005*/
    {
          126,            /*   uint16 BlockNumber;    */
          40,           /*   uint16 BlockSize;      */
          5,            /*   uint8  PartitionNo;     Partitions Const 1  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_006*/
    {
          127,            /*   uint16 BlockNumber;    */
          40,           /*   uint16 BlockSize;      */
          5,            /*   uint8  PartitionNo;     Partitions Const 1  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_007*/
    {
          128,            /*   uint16 BlockNumber;    */
          40,           /*   uint16 BlockSize;      */
          5,            /*   uint8  PartitionNo;     Partitions Const 1  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_008*/
    {
          129,            /*   uint16 BlockNumber;    */
          40,           /*   uint16 BlockSize;      */
          5,            /*   uint8  PartitionNo;     Partitions Const 1  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_009*/
    {
          130,            /*   uint16 BlockNumber;    */
          40,           /*   uint16 BlockSize;      */
          5,            /*   uint8  PartitionNo;     Partitions Const 1  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_010*/
    {
          131,            /*   uint16 BlockNumber;    */
          40,           /*   uint16 BlockSize;      */
          5,            /*   uint8  PartitionNo;     Partitions Const 1  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_011*/
    {
          132,            /*   uint16 BlockNumber;    */
          40,           /*   uint16 BlockSize;      */
          5,            /*   uint8  PartitionNo;     Partitions Const 1  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_012*/
    {
          133,            /*   uint16 BlockNumber;    */
          40,           /*   uint16 BlockSize;      */
          5,            /*   uint8  PartitionNo;     Partitions Const 1  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_013*/
    {
          134,            /*   uint16 BlockNumber;    */
          40,           /*   uint16 BlockSize;      */
          5,            /*   uint8  PartitionNo;     Partitions Const 1  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_014*/
    {
          135,            /*   uint16 BlockNumber;    */
          40,           /*   uint16 BlockSize;      */
          5,            /*   uint8  PartitionNo;     Partitions Const 1  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_015*/
    {
          136,            /*   uint16 BlockNumber;    */
          40,           /*   uint16 BlockSize;      */
          5,            /*   uint8  PartitionNo;     Partitions Const 1  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_016*/
    {
          137,            /*   uint16 BlockNumber;    */
          40,           /*   uint16 BlockSize;      */
          5,            /*   uint8  PartitionNo;     Partitions Const 1  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_017*/
    {
          138,            /*   uint16 BlockNumber;    */
          40,           /*   uint16 BlockSize;      */
          5,            /*   uint8  PartitionNo;     Partitions Const 1  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_018*/
    {
          139,            /*   uint16 BlockNumber;    */
          40,           /*   uint16 BlockSize;      */
          5,            /*   uint8  PartitionNo;     Partitions Const 1  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_019*/
    {
          140,            /*   uint16 BlockNumber;    */
          40,           /*   uint16 BlockSize;      */
          5,            /*   uint8  PartitionNo;     Partitions Const 1  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_020*/
    {
          141,            /*   uint16 BlockNumber;    */
          40,           /*   uint16 BlockSize;      */
          5,            /*   uint8  PartitionNo;     Partitions Const 1  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_021*/
    {
          142,            /*   uint16 BlockNumber;    */
          40,           /*   uint16 BlockSize;      */
          5,            /*   uint8  PartitionNo;     Partitions Const 1  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_022*/
    {
          143,            /*   uint16 BlockNumber;    */
          40,           /*   uint16 BlockSize;      */
          5,            /*   uint8  PartitionNo;     Partitions Const 1  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_023*/
    {
          144,            /*   uint16 BlockNumber;    */
          40,           /*   uint16 BlockSize;      */
          5,            /*   uint8  PartitionNo;     Partitions Const 1  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_024*/
    {
          145,            /*   uint16 BlockNumber;    */
          40,           /*   uint16 BlockSize;      */
          5,            /*   uint8  PartitionNo;     Partitions Const 1  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_025*/
    {
          146,            /*   uint16 BlockNumber;    */
          40,           /*   uint16 BlockSize;      */
          5,            /*   uint8  PartitionNo;     Partitions Const 1  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_026*/
    {
          147,            /*   uint16 BlockNumber;    */
          40,           /*   uint16 BlockSize;      */
          5,            /*   uint8  PartitionNo;     Partitions Const 1  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_027*/
    {
          148,            /*   uint16 BlockNumber;    */
          40,           /*   uint16 BlockSize;      */
          5,            /*   uint8  PartitionNo;     Partitions Const 1  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_028*/
    {
          149,            /*   uint16 BlockNumber;    */
          40,           /*   uint16 BlockSize;      */
          5,            /*   uint8  PartitionNo;     Partitions Const 1  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_029*/
    {
          150,            /*   uint16 BlockNumber;    */
          40,           /*   uint16 BlockSize;      */
          5,            /*   uint8  PartitionNo;     Partitions Const 1  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Dcm_86Infinitewindowtimestatus*/
    {
          151,            /*   uint16 BlockNumber;    */
          4,           /*   uint16 BlockSize;      */
          5,            /*   uint8  PartitionNo;     Partitions Const 1  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_LogData*/
    {
          152,            /*   uint16 BlockNumber;    */
          24,           /*   uint16 BlockSize;      */
          4,            /*   uint8  PartitionNo;     Partition SFD  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_LogData*/
    {
          153,            /*   uint16 BlockNumber;    */
          24,           /*   uint16 BlockSize;      */
          4,            /*   uint8  PartitionNo;     Partition SFD  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_LogData*/
    {
          154,            /*   uint16 BlockNumber;    */
          24,           /*   uint16 BlockSize;      */
          4,            /*   uint8  PartitionNo;     Partition SFD  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_LogData*/
    {
          155,            /*   uint16 BlockNumber;    */
          24,           /*   uint16 BlockSize;      */
          4,            /*   uint8  PartitionNo;     Partition SFD  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_LogData*/
    {
          156,            /*   uint16 BlockNumber;    */
          24,           /*   uint16 BlockSize;      */
          4,            /*   uint8  PartitionNo;     Partition SFD  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_LogData*/
    {
          157,            /*   uint16 BlockNumber;    */
          24,           /*   uint16 BlockSize;      */
          4,            /*   uint8  PartitionNo;     Partition SFD  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_LogData*/
    {
          158,            /*   uint16 BlockNumber;    */
          24,           /*   uint16 BlockSize;      */
          4,            /*   uint8  PartitionNo;     Partition SFD  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_LogData*/
    {
          159,            /*   uint16 BlockNumber;    */
          24,           /*   uint16 BlockSize;      */
          4,            /*   uint8  PartitionNo;     Partition SFD  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_LogData*/
    {
          160,            /*   uint16 BlockNumber;    */
          24,           /*   uint16 BlockSize;      */
          4,            /*   uint8  PartitionNo;     Partition SFD  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_LogData*/
    {
          161,            /*   uint16 BlockNumber;    */
          24,           /*   uint16 BlockSize;      */
          4,            /*   uint8  PartitionNo;     Partition SFD  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_LogData*/
    {
          162,            /*   uint16 BlockNumber;    */
          24,           /*   uint16 BlockSize;      */
          4,            /*   uint8  PartitionNo;     Partition SFD  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_LogData*/
    {
          163,            /*   uint16 BlockNumber;    */
          24,           /*   uint16 BlockSize;      */
          4,            /*   uint8  PartitionNo;     Partition SFD  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_LogData*/
    {
          164,            /*   uint16 BlockNumber;    */
          24,           /*   uint16 BlockSize;      */
          4,            /*   uint8  PartitionNo;     Partition SFD  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_LogData*/
    {
          165,            /*   uint16 BlockNumber;    */
          24,           /*   uint16 BlockSize;      */
          4,            /*   uint8  PartitionNo;     Partition SFD  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_LogData*/
    {
          166,            /*   uint16 BlockNumber;    */
          24,           /*   uint16 BlockSize;      */
          4,            /*   uint8  PartitionNo;     Partition SFD  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_LogData*/
    {
          167,            /*   uint16 BlockNumber;    */
          24,           /*   uint16 BlockSize;      */
          4,            /*   uint8  PartitionNo;     Partition SFD  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_LogData*/
    {
          168,            /*   uint16 BlockNumber;    */
          24,           /*   uint16 BlockSize;      */
          4,            /*   uint8  PartitionNo;     Partition SFD  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_LogData*/
    {
          169,            /*   uint16 BlockNumber;    */
          24,           /*   uint16 BlockSize;      */
          4,            /*   uint8  PartitionNo;     Partition SFD  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_LogData*/
    {
          170,            /*   uint16 BlockNumber;    */
          24,           /*   uint16 BlockSize;      */
          4,            /*   uint8  PartitionNo;     Partition SFD  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_LogData*/
    {
          171,            /*   uint16 BlockNumber;    */
          24,           /*   uint16 BlockSize;      */
          4,            /*   uint8  PartitionNo;     Partition SFD  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_LogData*/
    {
          172,            /*   uint16 BlockNumber;    */
          24,           /*   uint16 BlockSize;      */
          4,            /*   uint8  PartitionNo;     Partition SFD  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_LogData*/
    {
          173,            /*   uint16 BlockNumber;    */
          24,           /*   uint16 BlockSize;      */
          4,            /*   uint8  PartitionNo;     Partition SFD  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_LogData*/
    {
          174,            /*   uint16 BlockNumber;    */
          24,           /*   uint16 BlockSize;      */
          4,            /*   uint8  PartitionNo;     Partition SFD  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_LogData*/
    {
          175,            /*   uint16 BlockNumber;    */
          24,           /*   uint16 BlockSize;      */
          4,            /*   uint8  PartitionNo;     Partition SFD  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_LogData*/
    {
          176,            /*   uint16 BlockNumber;    */
          24,           /*   uint16 BlockSize;      */
          4,            /*   uint8  PartitionNo;     Partition SFD  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_LogData*/
    {
          177,            /*   uint16 BlockNumber;    */
          24,           /*   uint16 BlockSize;      */
          4,            /*   uint8  PartitionNo;     Partition SFD  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_LogData*/
    {
          178,            /*   uint16 BlockNumber;    */
          24,           /*   uint16 BlockSize;      */
          4,            /*   uint8  PartitionNo;     Partition SFD  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_LogData*/
    {
          179,            /*   uint16 BlockNumber;    */
          24,           /*   uint16 BlockSize;      */
          4,            /*   uint8  PartitionNo;     Partition SFD  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_LogData*/
    {
          180,            /*   uint16 BlockNumber;    */
          24,           /*   uint16 BlockSize;      */
          4,            /*   uint8  PartitionNo;     Partition SFD  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_LogData*/
    {
          181,            /*   uint16 BlockNumber;    */
          24,           /*   uint16 BlockSize;      */
          4,            /*   uint8  PartitionNo;     Partition SFD  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_LogData*/
    {
          182,            /*   uint16 BlockNumber;    */
          24,           /*   uint16 BlockSize;      */
          4,            /*   uint8  PartitionNo;     Partition SFD  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_LogData*/
    {
          183,            /*   uint16 BlockNumber;    */
          24,           /*   uint16 BlockSize;      */
          4,            /*   uint8  PartitionNo;     Partition SFD  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_LogData*/
    {
          184,            /*   uint16 BlockNumber;    */
          24,           /*   uint16 BlockSize;      */
          4,            /*   uint8  PartitionNo;     Partition SFD  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_LogData*/
    {
          185,            /*   uint16 BlockNumber;    */
          24,           /*   uint16 BlockSize;      */
          4,            /*   uint8  PartitionNo;     Partition SFD  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_LogData*/
    {
          186,            /*   uint16 BlockNumber;    */
          24,           /*   uint16 BlockSize;      */
          4,            /*   uint8  PartitionNo;     Partition SFD  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_LogData*/
    {
          187,            /*   uint16 BlockNumber;    */
          24,           /*   uint16 BlockSize;      */
          4,            /*   uint8  PartitionNo;     Partition SFD  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_LogData*/
    {
          188,            /*   uint16 BlockNumber;    */
          24,           /*   uint16 BlockSize;      */
          4,            /*   uint8  PartitionNo;     Partition SFD  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_LogData*/
    {
          189,            /*   uint16 BlockNumber;    */
          24,           /*   uint16 BlockSize;      */
          4,            /*   uint8  PartitionNo;     Partition SFD  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_LogData*/
    {
          190,            /*   uint16 BlockNumber;    */
          24,           /*   uint16 BlockSize;      */
          4,            /*   uint8  PartitionNo;     Partition SFD  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_LogData*/
    {
          191,            /*   uint16 BlockNumber;    */
          24,           /*   uint16 BlockSize;      */
          4,            /*   uint8  PartitionNo;     Partition SFD  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_LogData*/
    {
          192,            /*   uint16 BlockNumber;    */
          24,           /*   uint16 BlockSize;      */
          4,            /*   uint8  PartitionNo;     Partition SFD  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_LogData*/
    {
          193,            /*   uint16 BlockNumber;    */
          24,           /*   uint16 BlockSize;      */
          4,            /*   uint8  PartitionNo;     Partition SFD  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_LogData*/
    {
          194,            /*   uint16 BlockNumber;    */
          24,           /*   uint16 BlockSize;      */
          4,            /*   uint8  PartitionNo;     Partition SFD  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_LogData*/
    {
          195,            /*   uint16 BlockNumber;    */
          24,           /*   uint16 BlockSize;      */
          4,            /*   uint8  PartitionNo;     Partition SFD  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_LogData*/
    {
          196,            /*   uint16 BlockNumber;    */
          24,           /*   uint16 BlockSize;      */
          4,            /*   uint8  PartitionNo;     Partition SFD  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_LogData*/
    {
          197,            /*   uint16 BlockNumber;    */
          24,           /*   uint16 BlockSize;      */
          4,            /*   uint8  PartitionNo;     Partition SFD  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_LogData*/
    {
          198,            /*   uint16 BlockNumber;    */
          24,           /*   uint16 BlockSize;      */
          4,            /*   uint8  PartitionNo;     Partition SFD  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_LogData*/
    {
          199,            /*   uint16 BlockNumber;    */
          24,           /*   uint16 BlockSize;      */
          4,            /*   uint8  PartitionNo;     Partition SFD  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_LogData*/
    {
          200,            /*   uint16 BlockNumber;    */
          24,           /*   uint16 BlockSize;      */
          4,            /*   uint8  PartitionNo;     Partition SFD  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_LogData*/
    {
          201,            /*   uint16 BlockNumber;    */
          24,           /*   uint16 BlockSize;      */
          4,            /*   uint8  PartitionNo;     Partition SFD  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_LogData*/
    {
          202,            /*   uint16 BlockNumber;    */
          24,           /*   uint16 BlockSize;      */
          4,            /*   uint8  PartitionNo;     Partition SFD  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_LogData*/
    {
          203,            /*   uint16 BlockNumber;    */
          24,           /*   uint16 BlockSize;      */
          4,            /*   uint8  PartitionNo;     Partition SFD  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_LogData*/
    {
          204,            /*   uint16 BlockNumber;    */
          24,           /*   uint16 BlockSize;      */
          4,            /*   uint8  PartitionNo;     Partition SFD  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_LogData*/
    {
          205,            /*   uint16 BlockNumber;    */
          24,           /*   uint16 BlockSize;      */
          4,            /*   uint8  PartitionNo;     Partition SFD  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_PublicKey*/
    {
          206,            /*   uint16 BlockNumber;    */
          68,           /*   uint16 BlockSize;      */
          4,            /*   uint8  PartitionNo;     Partition SFD  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_SecDiag*/
    {
          207,            /*   uint16 BlockNumber;    */
          156,           /*   uint16 BlockSize;      */
          6,            /*   uint8  PartitionNo;     Partitions Const 2  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_AdaptationChannel_VAR_2*/
    {
          208,            /*   uint16 BlockNumber;    */
          20,           /*   uint16 BlockSize;      */
          2,            /*   uint8  PartitionNo;     Partition Variable  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_AdaptationChannel_VAR_2*/
    {
          209,            /*   uint16 BlockNumber;    */
          20,           /*   uint16 BlockSize;      */
          2,            /*   uint8  PartitionNo;     Partition Variable  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_WLTP_Odo_VAR*/
    {
          210,            /*   uint16 BlockNumber;    */
          128,           /*   uint16 BlockSize;      */
          3,            /*   uint8  PartitionNo;     Partition Odo  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_WLTP_Odo_VAR*/
    {
          211,            /*   uint16 BlockNumber;    */
          128,           /*   uint16 BlockSize;      */
          3,            /*   uint8  PartitionNo;     Partition Odo  */
          0             /*   boolean ImmediateData; */
    },
                  /*NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_SecDiag_1*/
    {
          212,            /*   uint16 BlockNumber;    */
          76,           /*   uint16 BlockSize;      */
          6,            /*   uint8  PartitionNo;     Partitions Const 2  */
          0             /*   boolean ImmediateData; */
    },
};
const Fee_SectorConfigType Fee_SectorConfig[FEE_NUM_OF_SECTORS] =
{
     {
          0,   /*SectorStartAddress*/
          6144,   /*SectorSize*/
     },
     {
          6144,   /*SectorStartAddress*/
          6144,   /*SectorSize*/
     },
     {
          12288,   /*SectorStartAddress*/
          4096,   /*SectorSize*/
     },
     {
          16384,   /*SectorStartAddress*/
          4096,   /*SectorSize*/
     },
     {
          20480,   /*SectorStartAddress*/
          4096,   /*SectorSize*/
     },
     {
          24576,   /*SectorStartAddress*/
          4096,   /*SectorSize*/
     },
     {
          28672,   /*SectorStartAddress*/
          4096,   /*SectorSize*/
     },
     {
          32768,   /*SectorStartAddress*/
          4096,   /*SectorSize*/
     },
     {
          36864,   /*SectorStartAddress*/
          4096,   /*SectorSize*/
     },
     {
          40960,   /*SectorStartAddress*/
          4096,   /*SectorSize*/
     },
     {
          45056,   /*SectorStartAddress*/
          4096,   /*SectorSize*/
     },
     {
          49152,   /*SectorStartAddress*/
          4096,   /*SectorSize*/
     },
     {
          53248,   /*SectorStartAddress*/
          6144,   /*SectorSize*/
     },
     {
          59392,   /*SectorStartAddress*/
          6144,   /*SectorSize*/
     },

};


const Fee_PartitionConfigType Fee_PartitionConfig[FEE_NUM_PARTITIONS]=
{
  {
    0,            /*   uint8  StartSectorID;              */
    2,            /*   uint8  NumberOfSectors;            */
    TRUE,         /*   boolean  BackgroundSectorSwitch;   */
    800              /*   uint16  MaxLength;                 */
  },
  {
    2,            /*   uint8  StartSectorID;              */
    2,            /*   uint8  NumberOfSectors;            */
    TRUE,         /*   boolean  BackgroundSectorSwitch;   */
    160              /*   uint16  MaxLength;                 */
  },
  {
    4,            /*   uint8  StartSectorID;              */
    2,            /*   uint8  NumberOfSectors;            */
    TRUE,         /*   boolean  BackgroundSectorSwitch;   */
    160              /*   uint16  MaxLength;                 */
  },
  {
    6,            /*   uint8  StartSectorID;              */
    2,            /*   uint8  NumberOfSectors;            */
    TRUE,         /*   boolean  BackgroundSectorSwitch;   */
    288              /*   uint16  MaxLength;                 */
  },
  {
    8,            /*   uint8  StartSectorID;              */
    2,            /*   uint8  NumberOfSectors;            */
    TRUE,         /*   boolean  BackgroundSectorSwitch;   */
    536              /*   uint16  MaxLength;                 */
  },
  {
    10,            /*   uint8  StartSectorID;              */
    2,            /*   uint8  NumberOfSectors;            */
    TRUE,         /*   boolean  BackgroundSectorSwitch;   */
    200              /*   uint16  MaxLength;                 */
  },
  {
    12,            /*   uint8  StartSectorID;              */
    2,            /*   uint8  NumberOfSectors;            */
    TRUE,         /*   boolean  BackgroundSectorSwitch;   */
    552              /*   uint16  MaxLength;                 */
  },
};

#endif    /* */
/* end of file */
/*Tool Version Information*/
/* Tool Version - v2.2.11 */
/****************************************************************
Created Time: 6/28/2022 10:03:28 AM
****************************************************************/
