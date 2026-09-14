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
*    @file CanSM_Types.h
*    @ingroup CanSM
*    @brief This file provides the types for the CanSM module.
********************************************************************************************************************/
#ifndef CANSM_TYPES_H
#define CANSM_TYPES_H
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "ComStack_Types.h"
#include "ComM.h"
/********************************************************************************************************************
*   MACRO AND DATA TYPES                                                                                            *
********************************************************************************************************************/
/********************************************************************************************************************
*                                 #! memory and pointer classes.                                                    *
********************************************************************************************************************/
#ifndef AUTOMATIC
#define AUTOMATIC
#endif

#ifndef CANSM_CODE
#define CANSM_CODE
#endif 

#ifndef CANSM_CONST
#define CANSM_CONST
#endif  

#ifndef CANSM_APPL_DATA
#define CANSM_APPL_DATA
#endif

#ifndef CANSM_APPL_CONST
#define CANSM_APPL_CODE
#endif

#ifndef CANSM_CALLOUT_CODE
#define CANSM_CALLOUT_CODE
#endif

#ifndef CANSM_VAR
#define CANSM_VAR
#endif

#ifndef CANSM_VAR_INIT
#define CANSM_VAR_INIT
#endif

#ifndef CANSM_VAR_NOINIT
#define CANSM_VAR_NOINIT
#endif

#ifndef CANSM_VAR_POWER_ON_INIT
#define CANSM_VAR_POWER_ON_INIT
#endif

#ifndef CANSM_VAR_FAST
#define CANSM_VAR_FAST
#endif

#ifndef CANSM_VAR_SLOW
#define CANSM_VAR_SLOW
#endif

#ifndef CANSM_CONFIG_DATA
#define CANSM_CONFIG_DATA
#endif


/*! @brief Defines the values of the internal states of the CanSM module */
typedef enum
{
    CANSM_INITED=0U,    /*! @brief Defines the internal state CANSM_INITED */
    CANSM_UNINITED      /*! @brief Defines the internal state CANSM_UNINITED */
}CanSM_StateType;

/*! @brief  This type contains the implementation-specific post build configuration structure of CanSM .
            Dummy config is used as post build not supported*/
typedef struct
{
    uint8 Dummy;
}CanSM_ConfigType;

/*! @brief Defines the CAN specific communication modes / states notified to the BswM module */
typedef enum
{
    CANSM_BSWM_NO_COMMUNICATION=0U,     /*! @brief State representing CAN No communication */
    CANSM_BSWM_SILENT_COMMUNICATION,    /*! @brief State representing CAN silent communication */
    CANSM_BSWM_FULL_COMMUNICATION,      /*! @brief State representing CAN full communication */
    CANSM_BSWM_BUS_OFF,                 /*! @brief State representing CAN bus off */
    CANSM_BSWM_CHANGE_BAUDRATE          /*! @brief State representing CAN baud rate change */
}CanSM_BswMCurrentStateType;

/*******************************************************************************************************************
*  #! CanSM Internal Types                                                                                   *
*******************************************************************************************************************/
/*! @brief Defines the type for BusoffRecoveryState */
typedef enum
{
    /*! @brief Bus off Recovery No Busoff */
    CANSM_BOR_NO_BUS_OFF = 0,
    /*! @brief Bus off Recovery L1 Wait State */
    CANSM_BOR_TXOFF_L1,
    /*! @brief Bus off Recovery L1 Check State */
    CANSM_BOR_CHECK_L1,
    /*! @brief Bus off Recovery L2 Wait State */
    CANSM_BOR_TXOFF_L2,
    /*! @brief Bus off Recovery L2 Check State */
    CANSM_BOR_CHECK_L2
}CanSM_BusoffRecoveryType;

/*! @brief Defines the type for  CANSM Network Info */
typedef struct
{
    /*! @brief Current Network State */
    ComM_ModeType CurrentComMode;
    /*! @brief Requested Network State */
    ComM_ModeType RequestedComMode;
    /*! @brief Indicated Com Mode */
    ComM_ModeType IndicatedComMode;
    /*! @brief Bus off Recovery State */
    CanSM_BusoffRecoveryType BusoffRecoveryState;
    /*! @brief Current State */
    uint8 CurrentState;
    /*! @brief Busoff Recovery timer */
    uint32 NetworkTimer;
    /*! @brief Busoff Counter to manage L1 to L2 switch */
    uint8 L1ToL2Counter;
    /*! @brief Timeout Counter */
    uint8 ModeReqRepetitionCounter;
    /*! @brief Mode Repeat Count */
    uint8 ModeReqRepetitionTimer;
    /*! @brief Bus off Event report status */
    boolean BusOffEventReported;
}CanSM_NetworkInfoType;

#endif /* CANSM_TYPES_H */

/********************************************************************************************************************
*                                 END OF FILE                                                                       *
********************************************************************************************************************/

