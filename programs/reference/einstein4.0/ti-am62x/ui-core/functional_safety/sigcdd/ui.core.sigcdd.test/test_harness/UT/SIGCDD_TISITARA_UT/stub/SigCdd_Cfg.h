/*============================================================================
 **
 **                     CONFIDENTIAL VISTEON CORPORATION
 **
 ** This is an unpublished work of authorship, which contains trade secrets,
 ** created in 2018. Visteon Corporation owns all rights to this work and
 ** intends to maintain it in confidence to preserve its trade secret status.
 ** Visteon Corporation reserves the right, under the copyright laws of the
 ** United States or those of any other country that may have jurisdiction,
 ** to protect this work as an unpublished work, in the event of an
 ** inadvertent or deliberate unauthorized publication. Visteon Corporation
 ** also reserves its rights under all copyright laws to protect this work as
 ** a published work, when appropriate. Those having access to this work may
 ** not copy it, use it, modify it or disclose the information contained in
 ** it without the written authorization of Visteon Corporation.
 **
 **============================================================================
 **
 ** Name:           SigCdd_cfg.h
 **
 ** Description:     This hardware abstraction layer of the Signature CDD.
 **
 ** Organization:   GUI Software Section, Visteon
 **
 **============================================================================
 **
 **==========================================================================*/

#ifndef SIGCDD_CFG_H
#define SIGCDD_CFG_H

#include "Rte_CSigCdd.h"
#include "CmpLib.h"
#include "Os.h"
#include "system.h"

/*
The OS Events raised by SWC to indicate the new dynamic configurations will be monitored.
So provide the name of the Task.
*/

#define SIG_OS_TASK             Os32msSafetyTask

#define SIGUNIT_INIT_ON_CMP_ACTIVATION

/* RTE read Signature unit-0 interface to be configured */

#define GET_SIG0_VP_WIN0_CONFIG_INPUT(rte_read_data)         (void)Rte_Read_rp_SigData_sig0_vp_win0(rte_read_data)
#define GET_SIG0_VP_WIN1_CONFIG_INPUT(rte_read_data)         (void)Rte_Read_rp_SigData_sig0_vp_win1(rte_read_data)
#define GET_SIG0_VP_WIN2_CONFIG_INPUT(rte_read_data)         (void)Rte_Read_rp_SigData_sig0_vp_win2(rte_read_data)
#define GET_SIG0_VP_WIN3_CONFIG_INPUT(rte_read_data)         (void)Rte_Read_rp_SigData_sig0_vp_win3(rte_read_data)
#define GET_SIG0_VIDL_WIN0_CONFIG_INPUT(rte_read_data)        
#define GET_SIG0_VID_WIN0_CONFIG_INPUT(rte_read_data)     

//---------------------------------------------------------------------------------------------------------------------
///                                        R E V I S I O N    N O T E S
//---------------------------------------------------------------------------------------------------------------------
///
///   For each change to this file, be sure to record:
///       1.  Who made the change and when the change was made
///       2.  Why the change was made and the intended result
///       3.  Document version referenced
///
///       refer to comments below for rev #.
///
///
///   PVCS Revision           Date            By
///       Reason for Change
///
//    Initial Version.
//---------------------------------------------------------------------------------------------------------------------
#endif
