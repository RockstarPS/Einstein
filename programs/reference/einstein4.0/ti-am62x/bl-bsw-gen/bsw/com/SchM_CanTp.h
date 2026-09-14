/********************************************************************************************************************
*                                   C O P Y R I G H T                                                               *
*********************************************************************************************************************
* Copyright (c) 2019 by Visteon Corporation.       All rights reserved.                                             *
*                                                                                                                   *
* NOTICE: This is an unpublished work of authorship, which contains trade secrets.                                  *
* Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States    *
* or those of any other country that may have jurisdiction, to protect this work as an unpublished work,            *
* in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its      *
* rights under all copyright laws to protect this work as a published work, when appropriate.                       *
* Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it  *
* without the written authorization of Visteon Corporation.                                                         *
********************************************************************************************************************/
/*!*****************************************************************************************************************
*    @file SchM_CanTp.h
*    @ingroup CanTpConfiguration
*    @brief This files contains the functions to be included by the schedule Manager.It contains the Main function
*    and the exclusive section API for CanTp.
*    @defgroup CanTpConfiguration
*    @brief This files contains the functions to be included by the schedule Manager.
********************************************************************************************************************/
#ifndef SCHM_CANTP_H
#define SCHM_CANTP_H

#include "Os.h"
#include "SchM_CanTp_Type.h"

#define SchM_Enter_CanTp_CANTP_EXCLUSIVE_AREA_0 SuspendAllInterrupts
#define SchM_Exit_CanTp_CANTP_EXCLUSIVE_AREA_0 ResumeAllInterrupts

/*! @brief Defines the enter critical function mapping */
#define CanTp_EnterCriticalSection()    SuspendAllInterrupts()
/*! @brief Defines the enter critical function mapping */
#define CanTp_ExitCriticalSection()     ResumeAllInterrupts()

void CanTp_MainFunction(void); 

#endif /* SCHM_CANTP_H */

/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

