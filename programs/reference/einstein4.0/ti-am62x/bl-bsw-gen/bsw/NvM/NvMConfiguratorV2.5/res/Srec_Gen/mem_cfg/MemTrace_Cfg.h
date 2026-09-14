/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2012. Visteon Corporation owns all rights to           *
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
*  File Name         :  MemTrace_Cfg.h                                       *
*  Module Short Name :  MemTrace                                             *
*  VOBName           :                                                       *
*  Author            :                                                       *
*  Description       :                                                       *
*                                                                            *
*  Organization      :  Driver Information Software Section,                 *
*                       Visteon Software Operation                           *
*                       Visteon Corporation                                  *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  GHS                                                    *
* Target Hardware  :                                                         *
*                                                                            *
******************************************************************************/
#ifndef MEM_TRACE_CFG_H
#define MEM_TRACE_CFG_H
/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "Gpt_Cfg.h"
#include "Gpt.h"





#define GET_CURRENT_TIME(Value)                 (*Value = Gpt_GetTimeElapsed(GptConf_GptChannelConfiguration_GptChannelConfiguration_60MHz)/60u)

void MemTraceCfg_MemAbsJobStartHook (uint16 BlockId);
void MemTraceCfg_MemAbsJobEndHook (uint16 BlockId);
void MemTraceCfg_NvmJobStartHook (uint8 JobId, uint16 BlockId);
void MemTraceCfg_NvmJobEndHook (uint8 JobId, uint16 BlockId);




#endif /* MEM_TRACE_H */