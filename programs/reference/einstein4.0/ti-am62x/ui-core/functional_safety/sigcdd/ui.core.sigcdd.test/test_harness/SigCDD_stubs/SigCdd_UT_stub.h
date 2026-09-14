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
 ** Name:           SigCdd_UT_stub.h
 **
 ** Description:    
 **                 
 **                 
 **
 ** Organization:   GUI Software Section, Visteon
 **
 **============================================================================
 **
 **==========================================================================*/

#ifndef SIGCDD_UT_STUB_H
#define SIGCDD_UT_STUB_H

#include "system.h"
#include "Rte_Type.h"

#ifdef SIGCDD_UT_STUB_C
	#define EXTERN_SIGCDD_UT_STUB
#else
	#define EXTERN_SIGCDD_UT_STUB extern
#endif


//=====================================================================================================================
// SigCDD_UT_stub
//=====================================================================================================================

/* Stub macro's */

#define Os32msSafetyTask 0	/* use it as a index value */
#define Rte_Ev_Sig_NewConfigReady 1   /* use it as value */

#define E_OK 1
#define E_NOT_OK 0
#define NULL 0

#define CMPLIB_INSTANCE(dummy)

typedef UINT16 Std_ReturnType;
typedef UINT16 EventMaskType;


/* RTE read Signature unit-0 interface to be configured */
EXTERN_SIGCDD_UT_STUB void Rte_Read_rpSigData0_sig0_Port0(SIG_WIN_SETUP_T *rte_read_data);
EXTERN_SIGCDD_UT_STUB void Rte_Read_rpSigData0_sig0_Port1(SIG_WIN_SETUP_T *rte_read_data);
EXTERN_SIGCDD_UT_STUB void Rte_Read_rpSigData0_sig0_Port2(SIG_WIN_SETUP_T *rte_read_data);
EXTERN_SIGCDD_UT_STUB void Rte_Read_rpSigData0_sig0_Port3(SIG_WIN_SETUP_T *rte_read_data);
EXTERN_SIGCDD_UT_STUB void Rte_Read_rpSigData0_sig0_Port4(SIG_WIN_SETUP_T *rte_read_data);
EXTERN_SIGCDD_UT_STUB void Rte_Read_rpSigData0_sig0_Port5(SIG_WIN_SETUP_T *rte_read_data);
EXTERN_SIGCDD_UT_STUB void Rte_Read_rpSigData0_sig0_Port6(SIG_WIN_SETUP_T *rte_read_data);
EXTERN_SIGCDD_UT_STUB void Rte_Read_rpSigData0_sig0_Port7(SIG_WIN_SETUP_T *rte_read_data);

/* RTE read Signature unit-1 interface to be configured */
EXTERN_SIGCDD_UT_STUB void Rte_Read_rpSigData1_sig1_Port0(SIG_WIN_SETUP_T *rte_read_data);
EXTERN_SIGCDD_UT_STUB void Rte_Read_rpSigData1_sig1_Port1(SIG_WIN_SETUP_T *rte_read_data);
EXTERN_SIGCDD_UT_STUB void Rte_Read_rpSigData1_sig1_Port2(SIG_WIN_SETUP_T *rte_read_data);
EXTERN_SIGCDD_UT_STUB void Rte_Read_rpSigData1_sig1_Port3(SIG_WIN_SETUP_T *rte_read_data);
EXTERN_SIGCDD_UT_STUB void Rte_Read_rpSigData1_sig1_Port4(SIG_WIN_SETUP_T *rte_read_data);
EXTERN_SIGCDD_UT_STUB void Rte_Read_rpSigData1_sig1_Port5(SIG_WIN_SETUP_T *rte_read_data);
EXTERN_SIGCDD_UT_STUB void Rte_Read_rpSigData1_sig1_Port6(SIG_WIN_SETUP_T *rte_read_data);
EXTERN_SIGCDD_UT_STUB void Rte_Read_rpSigData1_sig1_Port7(SIG_WIN_SETUP_T *rte_read_data);

EXTERN_SIGCDD_UT_STUB void GetEvent(UINT8 p_task_index, UINT8 *p_event_out_val);
EXTERN_SIGCDD_UT_STUB void ClearEvent(UINT8 p_event_out_val);



//---------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------
// C M S    R E V I S I O N    N O T E S
//---------------------------------------------------------------------------------------------------------------------
//
// For each change to this file, be sure to record:
// 1.  Who made the change and when the change was made.
// 2.  Why the change was made and the intended result.
//
// CMS Rev #        Date            By
// CMS Rev X.X      dd-mmm-yyyy     CDSID
//
//---------------------------------------------------------------------------------------------------------------------
// 
//---------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------
#endif  //SIGCDD_UT_STUB_H
