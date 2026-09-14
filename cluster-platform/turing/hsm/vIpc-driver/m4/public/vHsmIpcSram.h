/***************************************************************************/
/**
 * \copyright
 *       VISTEON CORPORATION CONFIDENTIAL
 *       ________________________________
 *       [2024] Visteon Corporation
 *       All Rights Reserved.
 *       NOTICE: This is an unpublished work of authorship, which contains trade
 *               secrets. Visteon Corporation owns all rights to this work and
 *               intends to maintain it in confidence to preserve its trade
 *               secret status. Visteon Corporation reserves the right, under
 *               the copyright laws of the United States or those of any other
 *               country that may have jurisdiction, to protect this work as an
 *               unpublished work, in the event of an inadvertent or deliberate
 *               unauthorized publication. Visteon Corporation also reserves
 *               its rights under all copyright laws to protect this work as a
 *               published work, when appropriate. Those having access to this
 *               work may not copy it, use it, modify it, or disclose the
 *               information contained in it without the written authorization
 *               of Visteon Corporation.
 *
 * \file vHsmIpcSram.h
 *
 * \brief
 * IPC Host Manager Shared SRAM header file for IPC communication between cores.
 *
 * \version 1.00.00
 * |Version | Date       | Author   | Task Id | Description                           |
 * |--------|------------|----------|---------|---------------------------------------|
 * |1.00.00 | 30/Jul/'24 | kjohn    | xxxxxx  | Initial version                       |
 * \authors
 *          Name                     | CDSID     | Location
 *          ------------------------ | --------- | --------
 *          Akshay Krishna Upendran  | akrish10  | VTSC, Chennai, India
 *          Banumathi Jayaraman      | bjayara2  | VTSC, Chennai, India
 *          krithik B John           | kjohn     | VTSC, Bengaluru, India
 *          Shanmugam Karthik        | kshanmu4  | VTSC, Chennai, India
 ******************************************************************************/
#ifndef V_HSM_IPC_SRAM_H
#define V_HSM_IPC_SRAM_H
/******************************************************************************
 *  INCLUDES
 *****************************************************************************/
#include "vHsmIpcMesFuncM0P.h"
#include "Std_Types.h"


/******************************************************************************
 *  MACROS
 *****************************************************************************/
#define IPC_SRAMADDR_START        0x00030000U
#define IPC_SRAMADDR_END          0x00032000U
#define IPC_SRAM_MAXSEGMENTSIZE    4
#define IPC_MAX_NUMBER_OF_BUFFERS  4
#define IPC_BYTES_PER_KB           1024

/* Shared RAM size for each IPC section M0P to M7 and M7 to M0P
 * Default size is kept as 2KB
 * The sizes can be 1KB, 2KB and 4KB */
#define IPC_SIZE_SHAREDRAM_SEGMENT          0x4

#if IPC_SIZE_SHAREDRAM_SEGMENT > IPC_SRAM_MAXSEGMENTSIZE
#error IPC SRAM Segment size cannot be greater than 4KB
#elif (IPC_SIZE_SHAREDRAM_SEGMENT == 3)
#error IPC SRAM Segment size cannot be 3KB
#endif

/* The number of buffers for each IPC Segment
 * Default number of buffers are kept as 4
 * The number of buffers can be 1, 2 or 4 */
#define IPC_NUMBER_OF_BUFFERS                     0x4

#if IPC_NUMBER_OF_BUFFERS > IPC_MAX_NUMBER_OF_BUFFERS
#error IPC number of buffers cannot be greater than 4
#elif (IPC_NUMBER_OF_BUFFERS == 3)
#error IPC number of buffers cannot be 3
#endif

#define IPC_SRAMADDR_M7_M0P_START      IPC_SRAMADDR_START
#define IPC_SRAMADDR_M7_M0P_END        (IPC_SRAMADDR_M7_M0P_START + (IPC_SIZE_SHAREDRAM_SEGMENT * IPC_BYTES_PER_KB))
#define IPC_SRAMADDR_M0P_M7_START      IPC_SRAMADDR_M7_M0P_END
#define IPC_SRAMADDR_M0P_M7_END        (IPC_SRAMADDR_M0P_M7_START + (IPC_SIZE_SHAREDRAM_SEGMENT * IPC_BYTES_PER_KB))

#if IPC_SRAMADDR_M0P_M7_END > IPC_SRAMADDR_END
#error The parameters mentioned in IPC is wrong, We have exceeded the SRAM size allocated
#endif

/*****************************************************************************
Date              :26/Nov/2020
By                :kgeethaa
Traceability      :
Change Description: Initial version
******************************************************************************/
#endif /* V_HSM_IPC_SRAM_H */
/* EOF */
