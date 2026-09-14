/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2013. Visteon Corporation owns all rights to           *
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
*  File Name         :  OsSysCall.c                                          *
*  Module Short Name :  mOS system calls                                     *
*  Description       :  This file externs the private APIs of the OS         *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  GHS Multi                                              *
* Target Hardware  :  RH850 D1x                                              *
*                                                                            *
******************************************************************************/

#ifndef OSSYSCALL_C
#define OSSYSCALL_C

#include "OsPrivate.h"

#pragma ghs section bss=".os_bss"
#pragma ghs section data=".os_data"
#pragma ghs section sbss=".os_sbss"
#pragma ghs section sdata=".os_sdata"
#pragma ghs section text=".oscode"
#pragma ghs section rodata=".os_rodata"
#pragma ghs section rosdata=".os_rosdata"
/* KB end osekStartOfCModule */

/*****************************************************************************/
/* Wrapper for osSysCallError                                                */
/*****************************************************************************/
#pragma asm
   .section ".oscode", "ax"
   .align  4   
   .globl  _osSysCallError
_osSysCallError:
   jr      _osSysCallError                  -- branch to _osEnterSafeState


.align 4
.globl    _osDispatchAsm
_osDispatchAsm:
    nop
    syscall osdSysCallDispatcher
    jmp [lp]
    
.align 4
.globl osCommonTrapHandler
osCommonTrapHandler:
    pushsp  lp-lp                 -- push lp onto stack 
    jarl    _osDispatchApi, lp     -- call  os<FuncName> 
    popsp   lp-lp                 -- restore lp from stack 
    jmp [lp]                      -- return from exception 

    
#pragma endasm


uint32 mOS_GetTaskParam_Task(void)
{
    return OffsetOf(TaskParamType,State);
}

uint32 mOS_GetTaskParam_Stackaddress(void)
{
    return OffsetOf(TaskParamType,StackAddress);
}



extern osuint32 osSysCallOffset00_c0[];
extern osuint32 osSysCallOffset01_c0[];

#if 0
osuint32 osSysCallOffset00_c0[]=        (osuint32)(&osSysCallError - &osSysCallTable_c0);
osuint32 osSysCallOffset01_c0[]=        (osuint32)(&osCommonTrapHandler - &osSysCallTable_c0);
osuint32 osSysCallOffset02_c0[];
osuint32 osSysCallOffset03_c0[];
osuint32 osSysCallOffset04_c0[];
osuint32 osSysCallOffset05_c0[];
osuint32 osSysCallOffset06_c0[];
osuint32 osSysCallOffset07_c0[];
osuint32 osSysCallOffset08_c0[];
osuint32 osSysCallOffset09_c0[];

osuint32 osSysCallOffset10_c0[];
osuint32 osSysCallOffset11_c0[];
osuint32 osSysCallOffset12_c0[];
osuint32 osSysCallOffset13_c0[];
osuint32 osSysCallOffset14_c0[];
osuint32 osSysCallOffset15_c0[];
osuint32 osSysCallOffset16_c0[];
osuint32 osSysCallOffset17_c0[];
osuint32 osSysCallOffset18_c0[];
osuint32 osSysCallOffset19_c0[];

osuint32 osSysCallOffset20_c0[];
osuint32 osSysCallOffset21_c0[];
osuint32 osSysCallOffset22_c0[];
osuint32 osSysCallOffset23_c0[];
osuint32 osSysCallOffset24_c0[];
osuint32 osSysCallOffset25_c0[];
osuint32 osSysCallOffset26_c0[];
osuint32 osSysCallOffset27_c0[];
osuint32 osSysCallOffset28_c0[];
osuint32 osSysCallOffset29_c0[];

osuint32 osSysCallOffset30_c0[];
osuint32 osSysCallOffset31_c0[];
osuint32 osSysCallOffset32_c0[];
osuint32 osSysCallOffset33_c0[];
osuint32 osSysCallOffset34_c0[];
osuint32 osSysCallOffset35_c0[];
osuint32 osSysCallOffset36_c0[];
osuint32 osSysCallOffset37_c0[];
osuint32 osSysCallOffset38_c0[];
osuint32 osSysCallOffset39_c0[];
#endif


#pragma ghs startdata
#pragma ghs section rodata=".osSysCallTable_c0"
#pragma alignvar(16)

const osuint32 osSysCallTable_c0[osdSysCallTableMax] =
{
   (osuint32)osSysCallOffset00_c0,
   (osuint32)osSysCallOffset01_c0
};
#pragma ghs enddata
#pragma ghs section rodata=".os_rodata"


#endif

