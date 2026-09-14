/********************************************************************************************************************
*                                   C O P Y R I G H T                                                               *
*********************************************************************************************************************
* Copyright (c) 2026 by Visteon Corporation.       All rights reserved.
*
* NOTICE: This is an unpublished work of authorship, which contains trade secrets.
* Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
* its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
* or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
* in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its
* rights under all copyright laws to protect this work as a published work, when appropriate.
* Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
* without the written authorization of Visteon Corporation.
********************************************************************************************************************/

/*******************************************************************************************************************
*    @file Crc_Cfg.h
*    @ingroup Crc Configuration
*    @brief This is Crc Pre-compile time configuration header file. It contains definitions of pre-compile time
*    configuration parameters for the Crc module.
*    Auto generated code in vAUTOSAR TOOL by ABASAVAR at 2026-08-12 12:03:55.122015100
********************************************************************************************************************/

#ifndef CRC_CFG_H
#define CRC_CFG_H
/*****************************************************************************
*                            Include files                                   *
*****************************************************************************/

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
*****************************************************************************/

/*******************************************************************************************************************/
/*  Version Information                                                                                            */
/*******************************************************************************************************************/
#define CRC_CFG_SW_MAJOR_VERSION                               1U
#define CRC_CFG_SW_MINOR_VERSION                               0U
#define CRC_CFG_SW_PATCH_VERSION                               23U
#define CRC_CFG_AR_RELEASE_MAJOR_VERSION                       4U
#define CRC_CFG_AR_RELEASE_MINOR_VERSION                       3U
#define CRC_CFG_AR_RELEASE_REVISION_VERSION                    1U

#define CRC_8H2F_TABLE                          STD_OFF
#define CRC_8H2F_RUNTIME                        STD_ON
#define CRC_8_TABLE                             STD_OFF
#define CRC_8_RUNTIME                           STD_ON
#define CRC_16_TABLE                            STD_OFF
#define CRC_16_RUNTIME                          STD_ON
#define CRC_32_TABLE                            STD_OFF
#define CRC_32_RUNTIME                          STD_ON
#define CRC_32P4_TABLE                          STD_ON
#define CRC_32P4_RUNTIME                        STD_OFF
#define CRC_64_TABLE                            STD_OFF
#define CRC_64_RUNTIME                          STD_ON
#define CRC_CALCULATE_CRC8H2F_ENABLE            STD_ON
#define CRC_CALCULATE_CRC8_ENABLE               STD_ON
#define CRC_CALCULATE_CRC16_ENABLE              STD_ON
#define CRC_CALCULATE_CRC32_ENABLE              STD_ON
#define CRC_CALCULATE_CRC32P4_ENABLE            STD_ON
#define CRC_CALCULATE_CRC64_ENABLE              STD_ON

#define CRC_8H2F_MODE                           CRC_8H2F_RUNTIME
#define CRC_8_MODE                              CRC_8_RUNTIME
#define CRC_16_MODE                             CRC_16_RUNTIME
#define CRC_32_MODE                             CRC_32_RUNTIME
#define CRC_32P4_MODE                           CRC_32P4_TABLE
#define CRC_64_MODE                             CRC_64_RUNTIME

#endif     /* CRC_CFG_H */

/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

