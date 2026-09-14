// ===========================================================================
//
//                     CONFIDENTIAL VISTEON CORPORATION
//
//  This is an unpublished work of authorship, which contains trade secrets,
//  created in 2006.  Visteon Corporation owns all rights to this work and
//  intends to maintain it in confidence to preserve its trade secret status.
//  Visteon Corporation reserves the right, under the copyright laws of the
//  United States or those of any other country that may have jurisdiction, to
//  protect this work as an unpublished work, in the event of an inadvertent
//  or deliberate unauthorized publication.  Visteon Corporation also reserves
//  its rights under all copyright laws to protect this work as a published
//  work, when appropriate.  Those having access to this work may not copy it,
//  use it, modify it or disclose the information contained in it without the
//  written authorization of Visteon Corporation.
//
// ===========================================================================
// ===========================================================================
//
//  Name:           LinTrcv_Types.h
//
//  Description:    
//
//  Organization:       Driver Information Core Software,
//                      Visteon Automotive Systems
// ===========================================================================
#ifndef LINTRCVCDD_TYPES_H
#define LINTRCVCDD_TYPES_H

#include "LinTrcv_Cfg.h"

// ===========================================================================
//  P U B L I C   M A C R O S
// ==========================================================================
#define LINTRCV_OP_MODE_NORMAL   1U
#define LINTRCV_OP_MODE_SLEEP    0U

// ===========================================================================
//  P U B L I C   T Y P E S
// ===========================================================================
typedef boolean LinTrcv_ChannelUsedType;
typedef boolean LinTrcv_IcuChannelSetOfChannelType;
typedef boolean LinTrcv_WakeupByBusUsedType;
typedef boolean LinTrcv_WakeupByPinUsedType;
typedef uint32 LinTrcv_WakeSourceIdType;

typedef struct LinTrcv_DioConfigurationType_st
{    
  uint16 PinENOfDioConfiguration;
  uint16 PinTXDOfDioConfiguration;
  uint16 PinRXDOfDioConfiguration;
}LinTrcv_DioConfigurationType;

typedef uint8 LinTrcv_TrcvModeType;

typedef enum LinTrcv_TrcvWakeupModeTypeTag
{
  LINTRCV_WUMODE_ENABLE = 0u,
  LINTRCV_WUMODE_CLEAR,
  LINTRCV_WUMODE_DISABLE
} LinTrcv_TrcvWakeupModeType_enum;

typedef enum LinTrcv_TrcvWakeupReasonTypeTag
{
  LINTRCV_WU_ERROR = 0u,
  LINTRCV_WU_BY_BUS,
  LINTRCV_WU_BY_PIN,
  LINTRCV_WU_INTERNALLY,
  LINTRCV_WU_NOT_SUPPORTED,
  LINTRCV_WU_POWER_ON,
  LINTRCV_WU_RESET,
  LINTRCV_WU_BY_SYSERR
} LinTrcv_TrcvWakeupReasonType_enum;

typedef struct sLinTrcv_ChannelType
{
  LinTrcv_IcuChannelSetOfChannelType IcuChannelSetOfChannel;
  uint8 IcuChannelOfChannel;
} LinTrcv_Icu_ChannelType;

#endif

/*============================================================================
**Date               : 22-Jul-2019
**CDSID              : ABAVALAT
**Traceability       : 
**Change Description : Initial Version.
**============================================================================*/
