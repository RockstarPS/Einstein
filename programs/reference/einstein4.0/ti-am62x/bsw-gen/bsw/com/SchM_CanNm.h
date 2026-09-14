/********************************************************************************************************************
|   File Name   : SchM_CanNm.h
|
|   Description : This header provides the pre-compile time configurable parameters 
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
| EA            Ashok Elavarasu          Visteon Corporation
|--------------------------------------------------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|--------------------------------------------------------------------------------------------------------------------
| Date        Version   Author  Description
| ----------  --------  ------  -------------------------------------------------------------------------------------
| 2020-03-17  00.00.01  EA     Initial Version
|*******************************************************************************************************************/
#ifndef SCHM_CANNM_H
# define SCHM_CANNM_H

# include "Os.h"
# include "Rte_Type.h"

void CanNm_MainFunction(void);
# define SchM_Enter_CanNm_CANNM_EXCLUSIVE_AREA_0() SuspendAllInterrupts()
# define SchM_Exit_CanNm_CANNM_EXCLUSIVE_AREA_0()  ResumeAllInterrupts()
# define SchM_Enter_CanNm_CANNM_EXCLUSIVE_AREA_1() SuspendAllInterrupts()
# define SchM_Exit_CanNm_CANNM_EXCLUSIVE_AREA_1()  ResumeAllInterrupts()
#endif /* SCHM_CANNM_H */
