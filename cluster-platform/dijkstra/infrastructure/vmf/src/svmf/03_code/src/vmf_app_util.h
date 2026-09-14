/*****************************************************************************/
/* Copyright Statement                                                       */
/* CONFIDENTIAL - VISTEON CORPORATION                                        */
/* This is an unpublished work, which contains trade secrets, created in     */
/* 2008. Visteon Corporation owns all rights to this work and intends        */
/* to maintain it in confidence to preserve its trade secret status. Visteon */
/* Corporation reserves the right, under the copyright laws of the United    */
/* States or those of any other country that may have jurisdiction, to       */
/* protect this work as an unpublished copyright work in the event of an     */
/* inadvertent or deliberate unauthorized publication. Visteon Corporation   */
/* also reserves its rights under the copyright laws to protect this work    */
/* as a published work, when appropriate. Those having access to this work   */
/* may not copy it, use it or disclose the information contained in it       */
/* without the written authorization of Visteon Corporation.                 */
/*****************************************************************************/

/***************************************************************************

  Module:               vmf_app_util.h
  Description:          header file for vmf_app util functions 
  Project Scope:        leopard-e

  Organization:         Visteon Deutschland GmbH, Infotainment Software
  Author:               Joachim Becker

  Compiler/Assembler:   iar
  Target Hardware:      leopard-e

  *****************************************************************************/

  
#ifndef __VMF_APP_UTIL_H__
#define __VMF_APP_UTIL_H__

#include "vmf_os_config.h"

#define VMF_CORE		VS_MICRO_CORE_A5

#ifndef VMF_CORE
#define VMF_CORE		VS_MICRO_CORE_M4
#endif


void vmf_util_tad_stack_usage(void);
void vmf_util_tad_lightweight_memory_blocks(void); 
void nw_con_HexDump(char * name,unsigned8 *buffer,int len);



#endif

