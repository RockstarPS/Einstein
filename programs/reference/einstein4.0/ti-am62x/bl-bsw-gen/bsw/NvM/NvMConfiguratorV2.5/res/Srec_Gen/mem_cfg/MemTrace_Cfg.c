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

#ifndef MEM_TRACE_CFG_C
#define MEM_TRACE_CFG_C
/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "MemTrace_Cfg.h"
#include "MemTrace.h"
#include "NvM.h"
// extern void MemTraceCfg_MemAbsJobStartHook (uint16 BlockId);
// extern void MemTraceCfg_MemAbsJobEndHook (uint16 BlockId);
// extern void MemTraceCfg_NvmJobStartHook (uint8 JobId, uint16 BlockId);
// extern void MemTraceCfg_NvmJobEndHook (uint8 JobId, uint16 BlockId);

static volatile boolean fl_useMemAbsForWrite = FALSE;

void MemTraceCfg_MemAbsJobStartHook (uint16 BlockId)
{
    if (fl_useMemAbsForWrite)
    {
        MemTrace_NvmJobStartHook(NVM_WRITE_BLOCK, BlockId);
    }
}
void MemTraceCfg_MemAbsJobEndHook (uint16 BlockId)
{
    if (fl_useMemAbsForWrite)
    {
        MemTrace_NvmJobEndHook(NVM_WRITE_BLOCK, BlockId);
    }
}
void MemTraceCfg_NvmJobStartHook (uint8 JobId, uint16 BlockId)
{
    if ((NVM_WRITE_BLOCK == JobId) && fl_useMemAbsForWrite)
    {
        //Do Nothing
    }
    else
    {
        MemTrace_NvmJobStartHook(JobId, BlockId);
    }

}
void MemTraceCfg_NvmJobEndHook (uint8 JobId, uint16 BlockId)
{
    if ((NVM_WRITE_BLOCK == JobId) && fl_useMemAbsForWrite)
    {
        //Do Nothing
    }
    else
    {
        MemTrace_NvmJobEndHook(JobId, BlockId);
    }
    
}




#endif /* MEM_TRACE_H */