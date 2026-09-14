/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2020. Visteon Corporation owns all rights to           *
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
*  File Name         :  E2EXF_CFG_H                                          *
*  Module Short Name :  E2EXF_CFG_H                                          *
*  Description       :                                                       *
*                                                                            *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  GHS Multi                                              *
* Target Hardware  :  Platform Independent                                   *
*                                                                            *
******************************************************************************/
/*This file contains the sample APIs that perform protect and check functionality*/

#ifndef E2EXF_CFG_H
#define E2EXF_CFG_H
/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "Std_Types.h"
#include "E2E_UserProfile.h"
#include "E2E_P01.h"
#include "E2E_P02.h"
#include "E2E_P04.h"
#include "E2E_P05.h"
#include "E2E_P06.h"
/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/

typedef struct{
        E2E_UserProfile8BitCheckSumProtectStateType *Protect_StatePtr;
        E2E_UserProfile8BitCheckSumCheckStateType *Check_StatePtr;
} E2EXF_StateTypeRef;


#define E2EXF_FUNCTION_COUNT 0

extern E2EXF_StateTypeRef E2EXF_StateRef[E2EXF_FUNCTION_COUNT];

#endif
