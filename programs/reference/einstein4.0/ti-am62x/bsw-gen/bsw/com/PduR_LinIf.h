/********************************************************************************************************************
|  File Name    : PduR_LinIf.h
|
|  Description  : Implementation of the AUTOSAR PduR Configurations.
|--------------------------------------------------------------------------------------------------------------------
|               C O P Y R I G H T
|--------------------------------------------------------------------------------------------------------------------
| Copyright (c) 2019 by Visteon Corporation.       All rights reserved.
|
| NOTICE: This is an unpublished work of authorship, which contains trade secrets.
| Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
| its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
| or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
| in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
| under all copyright laws to protect this work as a published work, when appropriate.
| Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
| without the written authorization of Visteon Corporation.
|--------------------------------------------------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|--------------------------------------------------------------------------------------------------------------------
| Initials     Name                      Company
| --------     ---------------------     -------------------------------------
| MA            Muthu Alexander          Visteon Corporation
|--------------------------------------------------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|--------------------------------------------------------------------------------------------------------------------
| Date        Version   Author  Description
| ----------  --------  ------  -------------------------------------------------------------------------------------
| 2020-03-19  00.00.03  MA     Can TP implementation Added
| 2020-01-30  00.00.02  MA     Review Comments fixed (Task 1394508)
| 2019-12-16  00.00.01  MA     Initial Version
|*******************************************************************************************************************/
#ifndef PDUR_LINIF_H
#define PDUR_LINIF_H
#include"ComStack_Cfg.h"
/*******************************************************************************************************************/
/*  PduR and CanIf Interface APIs                                                                                  */
/*******************************************************************************************************************/
extern FUNC(void, PDUR_CODE)
PduR_LinIfRxIndication(
    PduIdType RxPduId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_CONST) PduInfoPtr);

extern FUNC(Std_ReturnType, PDUR_CODE)
PduR_LinIfTriggerTransmit(
    PduIdType TxPduId,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr);
/* Within this API, the upper layer module (called module) shall check whether the available
data fits into the buffer size reported by PduInfoPtr->SduLength. If it fits, it shall
copy its data into the buffer provided by PduInfoPtr->SduDataPtr and update the length
of the actual copied data in PduInfoPtr->SduLength. If not, it returns E_NOT_OK without
changing PduInfoPtr. */
#endif /* PDUR_LINIF_H */
