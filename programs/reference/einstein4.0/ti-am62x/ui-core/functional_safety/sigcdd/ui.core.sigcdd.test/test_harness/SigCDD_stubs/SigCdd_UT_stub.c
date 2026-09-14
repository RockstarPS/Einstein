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
 ** Name:           SigCdd_UT_stub.c
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
#define SIGCDD_UT_STUB_C

#include "SigCdd_UT_stub.h"

static UINT16 l_current_active_os_index=0;
static UINT16 l_os_task[2] = {0,0};
static SIG_WIN_SETUP_T l_sig_win_setup[] = 
{
  {
    0x10003,         //(SIG_ENABLE_EVWIN|SIG_ENABLE_CRC|SIG_ENABLE_LOCALPANIC),   /* sing 0 controls */
	350,			   /* winsx*/
	200,			   /* winsy*/
	450,		       /* winex*/
	300,		       /* winey*/
	0xA,			   /* ref r crc*/
	0xB,			   /* ref g crc*/
	0xC,			   /* ref b crc*/ 
  }
};


/* RTE read Signature unit-0 interface to be configured */
void Rte_Read_rpSigData0_sig0_Port0(SIG_WIN_SETUP_T *rte_read_data)
{
  rte_read_data = &l_sig_win_setup[0];
}
void Rte_Read_rpSigData0_sig0_Port1(SIG_WIN_SETUP_T *rte_read_data)
{
  rte_read_data = &l_sig_win_setup[0];
}
void Rte_Read_rpSigData0_sig0_Port2(SIG_WIN_SETUP_T *rte_read_data)
{
  rte_read_data = &l_sig_win_setup[0];
}
void Rte_Read_rpSigData0_sig0_Port3(SIG_WIN_SETUP_T *rte_read_data)
{
  rte_read_data = &l_sig_win_setup[0];
}
void Rte_Read_rpSigData0_sig0_Port4(SIG_WIN_SETUP_T *rte_read_data)
{
  rte_read_data = &l_sig_win_setup[0];
}
void Rte_Read_rpSigData0_sig0_Port5(SIG_WIN_SETUP_T *rte_read_data)
{
  rte_read_data = &l_sig_win_setup[0];
}
void Rte_Read_rpSigData0_sig0_Port6(SIG_WIN_SETUP_T *rte_read_data)
{
  rte_read_data = &l_sig_win_setup[0];
}
void Rte_Read_rpSigData0_sig0_Port7(SIG_WIN_SETUP_T *rte_read_data)
{
  rte_read_data = &l_sig_win_setup[0];
}

/* RTE read Signature unit-1 interface to be configured */
void Rte_Read_rpSigData1_sig1_Port0(SIG_WIN_SETUP_T *rte_read_data)
{
  rte_read_data = &l_sig_win_setup[0];
}
void Rte_Read_rpSigData1_sig1_Port1(SIG_WIN_SETUP_T *rte_read_data)
{
  rte_read_data = &l_sig_win_setup[0];
}
void Rte_Read_rpSigData1_sig1_Port2(SIG_WIN_SETUP_T *rte_read_data)
{
  rte_read_data = &l_sig_win_setup[0];
}
void Rte_Read_rpSigData1_sig1_Port3(SIG_WIN_SETUP_T *rte_read_data)
{
  rte_read_data = &l_sig_win_setup[0];
}
void Rte_Read_rpSigData1_sig1_Port4(SIG_WIN_SETUP_T *rte_read_data)
{
  rte_read_data = &l_sig_win_setup[0];
}
void Rte_Read_rpSigData1_sig1_Port5(SIG_WIN_SETUP_T *rte_read_data)
{
  rte_read_data = &l_sig_win_setup[0];
}
void Rte_Read_rpSigData1_sig1_Port6(SIG_WIN_SETUP_T *rte_read_data)
{
  rte_read_data = &l_sig_win_setup[0];
}
void Rte_Read_rpSigData1_sig1_Port7(SIG_WIN_SETUP_T *rte_read_data)
{
  rte_read_data = &l_sig_win_setup[0];
}


void GetEvent(UINT8 p_task_index, UINT8 *p_event_out_val)
{
  p_event_out_val = &l_os_task[p_task_index]; 
  l_current_active_os_index = p_task_index;
}

void ClearEvent(UINT8 p_event_out_val)
{
  l_os_task[l_current_active_os_index] = 0; 
}

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
