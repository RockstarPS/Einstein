//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2018] Visteon Corporation
// All Rights Reserved.
//
// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
// under all copyright laws to protect this work as a published work, when appropriate.
// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
// without the written authorization of Visteon Corporation.
//
//---------------------------------------------------------------------------------------------------------------------
#ifndef IoHwAb_Gpt_H
#define IoHwAb_Gpt_H

#include "IoHwAb_Cfg.h"

#define IOHWAB_GPT_ENABLE STD_ON
#if (IOHWAB_GPT_ENABLE == STD_ON)
//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================



//=====================================================================================================================
//  FORWARD DECLARATIONS
//=====================================================================================================================

extern void IoHwAb_Gpt_EnableNotification(Gpt_ChannelType channel);
extern void IoHwAb_Gpt_DisableNotification(Gpt_ChannelType channel);
extern void IoHwAb_Gpt_StartTimer(Gpt_ChannelType channel, Gpt_ValueType value);
extern void IoHwAb_Gpt_StopTimer(Gpt_ChannelType channel);



#endif

#endif /* IoHwAb_Gpt_H*/
