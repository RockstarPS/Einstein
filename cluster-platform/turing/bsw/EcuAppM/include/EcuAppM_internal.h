/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2023. Visteon Corporation owns all rights to           *
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
#ifndef __ECUAPPM_INTERNAL_H_
#define __ECUAPPM_INTERNAL_H_


/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "EcuAppM_Callouts.h"
#include "EcuAppM_Types.h"
#include "EcuMExt.h"
#include "Std_Types.h"

/*****************************************************************************
*                           Type Declarations                          		 *
******************************************************************************/


#define	ECUAPPM_START_SEC_VAR_INIT_8
#include "MemMap.h"
static uint8 ApplicationSleepState;
#define	ECUAPPM_STOP_SEC_VAR_INIT_8
#include "MemMap.h"

#define	ECUAPPM_START_SEC_VAR_INIT_8
#include "MemMap.h"
static uint32 WakeupEvent;
#define	ECUAPPM_STOP_SEC_VAR_INIT_8
#include "MemMap.h"

#define	ECUAPPM_START_SEC_VAR_INIT_16
#include "MemMap.h"
static uint32 EcuAppM_WakeupSource;
#define	ECUAPPM_STOP_SEC_VAR_INIT_16
#include "MemMap.h"

#define	ECUAPPM_START_SEC_VAR_INIT_16
#include "MemMap.h"
uint32 EcuAppM_BufferedWakeupSource;
#define	ECUAPPM_STOP_SEC_VAR_INIT_16
#include "MemMap.h"

#define	ECUAPPM_START_SEC_VAR_INIT_16
#include "MemMap.h"
static uint16 EcuAppM_WakeupValidationTime;
#define	ECUAPPM_STOP_SEC_VAR_INIT_16
#include "MemMap.h"

#define	ECUAPPM_START_SEC_VAR_INIT_8
#include "MemMap.h"
static uint16 EcuAppM_WakeupValidationTimer;
#define	ECUAPPM_STOP_SEC_VAR_INIT_8
#include "MemMap.h"

#define	ECUAPPM_START_SEC_VAR_INIT_16
#include "MemMap.h"
static uint16 EcuAppM_CurrentWakeupValidationTime;
#define	ECUAPPM_STOP_SEC_VAR_INIT_16
#include "MemMap.h"

#define	ECUAPPM_START_SEC_VAR_INIT_16
#include "MemMap.h"
static uint16 EcuAppM_Index;
#define	ECUAPPM_STOP_SEC_VAR_INIT_16
#include "MemMap.h"

#define	ECUAPPM_START_SEC_VAR_INIT_16
#include "MemMap.h"
static uint32 wakeupMask;
#define	ECUAPPM_STOP_SEC_VAR_INIT_16
#include "MemMap.h"

#define	ECUAPPM_START_SEC_VAR_INIT_16
#include "MemMap.h"
static uint32 PrevwakeupMask;
#define	ECUAPPM_STOP_SEC_VAR_INIT_16
#include "MemMap.h"

#define	ECUAPPM_START_SEC_VAR_INIT_16
#include "MemMap.h"
static uint16 validationTime;
#define	ECUAPPM_STOP_SEC_VAR_INIT_16
#include "MemMap.h"

#define	ECUAPPM_START_SEC_VAR_INIT_16
#include "MemMap.h"
static uint16 PrevvalidationTime;
#define	ECUAPPM_STOP_SEC_VAR_INIT_16
#include "MemMap.h"

#define	ECUAPPM_START_SEC_VAR_INIT_16
#include "MemMap.h"
static uint16 wakeupReaction;
#define	ECUAPPM_STOP_SEC_VAR_INIT_16
#include "MemMap.h"

#define	ECUAPPM_START_SEC_VAR_INIT_16
#include "MemMap.h"
static uint16 PrevwakeupReaction;
#define	ECUAPPM_STOP_SEC_VAR_INIT_16
#include "MemMap.h"

static EcuAppMType PrevEcuAppMCurrentState;

static EcuAppMType EcuAppMCurrentState;

static EcuAppMType EcuAppMStateOp;

static EcuAppMInfoType EcuAppMInfo;

static EcuAppM_GroupsInfoType EcuAppM_GroupsInfo;

static EcuAppM_WakeupSourcesType EcuAppM_BufferedWakeupData;

#define EcuAppM_WakeupSourceType uint16;

#endif
/*****************************************************************************
Date              : 18-09-23
CDSID             : akappa
Traceability      :
Change Description: Initial Version of EcuAppM_internal.
*****************************************************************************/
/* End Of File */
