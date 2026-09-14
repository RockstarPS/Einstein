//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2015] Visteon Corporation
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
#ifndef DCM_APP_WDBID_H
#define DCM_APP_WDBID_H


extern uint8 WDBID_WriteData_FD00(P2CONST(UInt8, AUTOMATIC, RTE_DCM_APP_APPL_VAR) Data, teDiagOpStatus OpStatus, P2VAR(UInt8, AUTOMATIC, RTE_DCM_APP_APPL_VAR) ErrorCode, teDIDOperation eOperation);
extern uint8 WDBID_WriteData_FD01(P2CONST(UInt8, AUTOMATIC, RTE_DCM_APP_APPL_VAR) Data, teDiagOpStatus OpStatus, P2VAR(UInt8, AUTOMATIC, RTE_DCM_APP_APPL_VAR) ErrorCode, teDIDOperation eOperation);
uint8 WDBID_IOCTL_FD31(P2CONST(UInt8, AUTOMATIC, RTE_DCM_APP_APPL_VAR) Data, teDiagOpStatus OpStatus, P2VAR(UInt8, AUTOMATIC, RTE_DCM_APP_APPL_VAR) ErrorCode, teDIDOperation eOperation);

#endif /* DCM_APP_WDBID_H */

/* End of File */
/****************************************************************************
*   for each change to this file, be sure to record:                        *
*      1.  who made the change and when the change was made                 *
*      2.  why the change was made and the intended result                  *
*   Following block needs to be repeated for each change                    *
*****************************************************************************/

