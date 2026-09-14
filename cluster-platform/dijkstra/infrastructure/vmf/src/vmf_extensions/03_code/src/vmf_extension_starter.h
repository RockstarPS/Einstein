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

  Module:               vmf_exension_starter.h
  Description:          header file of vmf  extension starter

  Project Scope:        vmf

  Organization:         Visteon Deutschland GmbH, Infotainment Software
  Author:               Jochen Becker

  Compiler/Assembler:   gcc
  Target Hardware:      Any

  *****************************************************************************/

#ifndef __VMF_EXTENSION_STARTER_H
#define __VMF_EXTENSION_STARTER_H


#define VMF_TRACE_EXTS_SCOPE        "vmf_ext_starter"

#define VMF_TRACE_EXTS              "vmf_ext_starter"
#define VMF_EXTS_STACK_SIZE         VMF_NW_STACK_SIZE

#define INI_SECTION_EXTS			"EXTENSIONS"
#define INI_KEYS_EXTS               "ext"
#define VMF_EXTS_MAX_KEYS           (10)

/* function prototypes */
void vmf_start_extensions(bool verbose);




#endif

