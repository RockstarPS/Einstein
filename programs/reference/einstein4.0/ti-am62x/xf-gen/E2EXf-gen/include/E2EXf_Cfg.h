/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2020. Visteon Corporation owns all rights to           *
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
*  File Name         :  E2EXF_CFG_H                                          *
*  Module Short Name :  E2EXF_CFG_H                                          *
*  Description       :                                                       *
*                                                                            *
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
/*This file contains the sample APIs that perform protect and check functionality*/

#ifndef E2EXF_CFG_H
#define E2EXF_CFG_H
/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "Std_Types.h"
#include "E2E_P01.h"
#include "Can_GeneralTypes.h"
#define E2EXF_SEC_CODE_START
#define E2EXF_CORE_CONST_SEC_START
#define E2EXF_CORE_DATA_SEC_START
#define E2EXF_CORE_BSS_SEC_START
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
typedef void (*E2Exf_RxMsgRTEType) (boolean);

#define NUM_CAN_MSG_TX 1u
#define NUM_CAN_MSG_RX 1u
#define E2E_P01_MOD_BY_8U               8u
#define E2E_P01_VAL_0x0fu               0x0fu
#define E2E_P01_SHIFT_BY_4U             4U
#define E2E_P01_SHIFT_BY_3U             3U


#define E2EXF_FUNCTION_COUNT 0
#define E_SAFETY_HARD_RUNTIMEERROR 0xFF
void E2EXf_init(void);
extern Std_ReturnType E2EXf_Inv_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS(uint8 *buffer, uint16 *bufferLength, uint16 inputBufferLength);
extern Std_ReturnType E2EXf_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS (uint8 *buffer, uint16 *bufferLength, uint16 inputBufferLength);
#define E2EXF_SEC_CODE_STOP
#define E2EXF_CORE_CONST_SEC_END
#define E2EXF_CORE_DATA_SEC_END
#define E2EXF_CORE_BSS_SEC_END

#include "MemMap.h"
#endif
/*****************************************************************************
*                                 END OF FILE                                *
******************************************************************************/