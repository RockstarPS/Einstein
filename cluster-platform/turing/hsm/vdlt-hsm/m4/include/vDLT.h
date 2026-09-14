/***************************************************************************/
/**
 * \copyright
 *       VISTEON CORPORATION CONFIDENTIAL
 *       ________________________________
 *       [2026] Visteon Corporation
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
 * \file vDLT.h
 *
 * \brief
 * Visteon DLT Logger for HSM
 *
 ******************************************************************************/
#ifndef VDLT_H
#define VDLT_H

#include "Std_Types.h"
#include "vDLTHSM_Cfg.h"
#include "config.h"

#ifdef VDLT_ENABLE   /*Enable DLT*/
/******************************************************************************
 *  INTERNAL TYPES
 *****************************************************************************/
#pragma pack ( push, 1 )
typedef struct
{
    uint8   HTYP_U8;
    uint8   MsgCounter_U8;
    uint16  Length_U16;
    uint32  EcuId_U32;
    uint32  TimeStamp_U32;
} ts_DLT_sheader_t;
#pragma pack ( pop )

#pragma pack ( push, 1 )
typedef struct
{
    uint8  MsgType_U8;
    uint8  Arguments_U8;
    uint32 AppId_U32;
    uint32 ContextId_U32;
} ts_DLT_Extheader_t;
#pragma pack ( pop )
#pragma pack ( push, 1)
typedef struct
{
    uint32 TypeInfo_U32;
    uint8 data_U8A[ADDONDATALENGTH];
} ts_DLT_Payload_t;
#pragma pack ( pop )
#pragma pack ( push, 1 )
typedef struct
{
    ts_DLT_sheader_t   StdHeader;
    ts_DLT_Extheader_t ExtHeader;
    ts_DLT_Payload_t   Payload;
} ts_DLT_Frame_t;
#pragma pack ( pop )

/******************************************************************************
 *  PUBLIC DEFINITIONS
 *****************************************************************************/
/**
 * @brief vDLT_Init
 * Initializes the HSM DLT 
 * 
 */
void vDLT_Init(void);
/**
 * @brief DLT log function
 * 
 * @param[in] typeInfo_pU8 typeinfo of the message
 * @param[in] appId        ApplicationID of the message
 * @param[in] ContextId    Context ID of the message
 * @param[in] data_pU8     Data to be logges
 */
void vDLT_LogMsg(uint8 typeInfo_pU8, uint32 appId, uint32 ContextId,const uint8 * data_pU8);
/**
 * @brief De init DLT
 * 
 */
void vDLT_deInit(void);
/**
 * @brief helper Function to asynchnously Notify the DLTExt and to clear the buffer 
 *        upon acknowledgement 
 * 
 */
void vDLT_mainFunction(void);

#define DLT_LOGFATAL(appid,contid,fmt) vDLT_LogMsg(DLT_LOG_FATAL,appid,contid,fmt)
#define DLT_LOGERROR(appid,contid,fmt) vDLT_LogMsg(DLT_LOG_VERBOSE,appid,contid,fmt)
#else
#define DLT_LOGFATAL(appid,contid,fmt)
#define DLT_LOGERROR(appid,contid,fmt)
#endif
#endif
