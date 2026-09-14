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
/*                                                                            *
*******************************************************************************
*  PROJECT NAME :          VMF_TRACE_SERVER                                   *
*******************************************************************************
*  MODULE NAME  :          nw_vmf_target_log.c                                *
*  AUTHOR NAME  :          Joerg Merkle -- jmerkle                            *
*******************************************************************************
*  MODULE DATE  :          February 2015                                      *
*******************************************************************************
*  MODULE DESCRIPTION  :   VMF_TRACE                                          *
*******************************************************************************
* Compiler/Assembler:      gcc                                                *
* Target Hardware:         Any                                                *
******************************************************************************/
#ifndef _VMF_TARGET_LOG_H_
#define _VMF_TARGET_LOG_H_


/* function prototypes */
vmf_ret_t vmf_target_log_init_trace(void);
vmf_ret_t vmf_target_log_write_trace(unsigned8 *payload);



#endif
