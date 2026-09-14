/********************************************************************************************************************
*                                   C O P Y R I G H T                                                               *
*********************************************************************************************************************
* Copyright (c) 2019 by Visteon Corporation.       All rights reserved.                                             *
*                                                                                                                   *
* NOTICE: This is an unpublished work of authorship, which contains trade secrets.                                  *
* Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States    *
* or those of any other country that may have jurisdiction, to protect this work as an unpublished work,            *
* in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its      *
* rights under all copyright laws to protect this work as a published work, when appropriate.                       *
* Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it  *
* without the written authorization of Visteon Corporation.                                                         *
********************************************************************************************************************/
/*!******************************************************************************************************************
*   @file ComXf_Int.h
*   @ingroup ComXf
*   @brief This file provides the declaration of the ComXf Internal API. This header file should be included by 
*   files in ComXf.
********************************************************************************************************************/
#ifndef COMXF_INT_H
#define COMXF_INT_H
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "ComXf_Types.h"       
#include "ComXf.h"       
#if (COMXF_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif    
#include "SchM_ComXf.h"
/********************************************************************************************************************
*  PUBLIC MACRO DEFINITIONS                                                                                         *
********************************************************************************************************************/
#if (COMXF_DEV_ERROR_DETECT == STD_ON)
#define ComXf_DetReportError(ApiId,ErrId) (void) \
    Det_ReportError(COMXF_MODULE_ID,COMXF_INSTANCE_ID,(ApiId),(ErrId))
#else
#define ComXf_DetReportError(ApiId,ErrId)    
#endif

/********************************************************************************************************************
*  PUBLIC FUNCTION PROTOTYPES                                                                                       *
********************************************************************************************************************/
#define COMXF_START_SEC_CODE
#include "MemMap.h"
/*!******************************************************************************************************************
*   @brief  This function is used to read signal from the provided input buffer.
*   @param[in]  SignalId Idx of signal which used to access ComXf_SignalConfig
*   @param[out] pSignalData pointer to signal buffer where data will be copied 
*   @param[in]  pSrcBuffer pointer to signal group array data buffer containing the signal data
*   @param[in]  BufferLength length of the signal group array data buffer
*   @param[in]  BufferOffset Offset in the pdu where the signal group array data buffer starts
********************************************************************************************************************/
extern FUNC(void,COMXF_CODE) ComXf_ReadSignalFromBuffer
(
    ComXf_SignalId SignalId,
    P2VAR(void,AUTOMATIC,COMXF_APPL_CONST) pSignalData,
    P2CONST(uint8,AUTOMATIC,COMXF_APPL_DATA) pSrcBuffer,
    uint32 BufferLength,
    uint32 BufferOffset
);
/*!******************************************************************************************************************
*   @brief  This function is used to write signal to the provided buffer.
*   @param[in]  SignalId Idx of signal which used to access ComXf_SignalConfig
*   @param[in]  pSignalData pointer to signal buffer where data will be copied 
*   @param[out] pDestBuffer pointer to signal group array data buffer where data to be copied
*   @param[in,out]  pDestBufferLength length of the signal group array data buffer
*   @param[in]  BufferOffset Offset in the pdu where the signal group array data buffer starts
********************************************************************************************************************/
extern FUNC(void,COMXF_CODE) ComXf_WriteSignalToBuffer
(
    ComXf_SignalId SignalId,
    P2CONST(void,AUTOMATIC,COMXF_APPL_CONST) pSignalData,
    P2VAR(uint8,AUTOMATIC,COMXF_APPL_DATA) pDestBuffer,
    P2CONST(uint32,AUTOMATIC,COMXF_APPL_DATA) pDestBufferLength,
    uint32 BufferOffset
);
#define COMXF_STOP_SEC_CODE
#include "MemMap.h"

#endif /* COMXF_INT_H */
/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/
