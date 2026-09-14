//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2023] Visteon Corporation
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
#ifndef ECUWAKEUPM_TYPES_H
#define ECUWAKEUPM_TYPES_H


//----------------------------------------------------------------------------------------------------------------------
// Included files
//----------------------------------------------------------------------------------------------------------------------
#include <Std_Types.h>        /* AUTOSAR standard types */

//----------------------------------------------------------------------------------------------------------------------
// Constant data
//----------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------
// Type definitions
//----------------------------------------------------------------------------------------------------------------------

/** \brief MCU wakeup port mode . */
typedef uint8 EcuWakeupM_WakeupPortModeType;
/** \brief Operating mode . */
typedef uint8 EcuWakeupM_ModeType;
/** \brief Notification status . */
typedef uint8 EcuWakeupM_NotifyStatusType;
/** \brief Wakeup status. */
typedef uint8 EcuWakeupM_WakeupStatusType;
/** \brief  Wakeup Pin mode  */
typedef uint8 EcuWakeupM_WakeupPinModeType;
/** \brief  Wakeup report status  */
typedef uint8 EcuWakeupM_WakeupReportStatusType;


/** \brief underlying low level driver channel identifier. */
typedef uint16 EcuWakeupM_LowlevelDrvChannelType;
/** \brief underlying low level driver channel identifier. */
typedef uint16 EcuWakeupM_ChannelType;
/** \brief MCU wakeup port identifier. */
typedef uint16 EcuWakeupM_WakeupPortIdType;
/** \brief EcuAppM wakeup identifier. */
typedef uint32 EcuWakeupM_EcuAppMWakeupSourceType;

/** \brief ECUM wakeup identifier. */
typedef uint32 EcuWakeupM_EcuMWakeupSourceType;

/** \brief Holds EcuWakeupM init status. */
typedef enum
{
  /* Illegal initialization value. */
  ECUWAKEUPM_S_ILLEGAL = 0,
  /* EcuWakeupM was not initialized. */
  ECUWAKEUPM_S_UNINITIALIZED,
  /* EcuWakeupM successfully initialized. */
  ECUWAKEUPM_S_INITIALIZED

} EcuWakeupM_InitStatusType;
/** \brief channel wakeup modes. */
typedef enum
{
  ECUWAKEUPM_WAKEUP_EXTERNAL = 0,
  ECUWAKEUPM_WAKEUP_INTERNAL
} EcuWakeupM_WakeupType;

/** \brief Definition of the functional pointer to register low level driver functions. */
typedef P2FUNC(void, ECUWAKEUPM_CODE, EcuWakeupM_LowlevelDrvFct_t) (VAR(EcuWakeupM_ModeType, AUTOMATIC) mode);
typedef P2FUNC(void, ECUWAKEUPM_CODE, EcuWakeupM_LowlevelDrvFct1_t)(VAR(EcuWakeupM_ChannelType, AUTOMATIC) channel);
typedef P2FUNC(void, ECUWAKEUPM_CODE, EcuWakeupM_LowlevelDrvFct2_t)(VAR(EcuWakeupM_WakeupPortIdType, AUTOMATIC) portId);
typedef P2FUNC(EcuWakeupM_WakeupStatusType, ECUWAKEUPM_CODE, EcuWakeupM_LowlevelDrvFct3_t)(VAR(EcuWakeupM_ChannelType, AUTOMATIC) channel);
typedef P2FUNC(void, ECUWAKEUPM_CODE, EcuWakeupM_LowlevelDrvFct4_t)(VAR(EcuWakeupM_EcuMWakeupSourceType, AUTOMATIC) WakeupSource);
typedef P2FUNC(void, ECUWAKEUPM_CODE, EcuWakeupM_FuncPtrVoidType_t)(void);
typedef P2FUNC(void, ECUWAKEUPM_CODE, EcuWakeupM_FuncPtrType_t)(VAR(EcuWakeupM_EcuAppMWakeupSourceType, AUTOMATIC) WakeupSource);
typedef P2FUNC(void, ECUWAKEUPM_CODE, EcuWakeupM_FuncPtrType1_t)(VAR(EcuWakeupM_EcuMWakeupSourceType, AUTOMATIC)   WakeupSource);
typedef P2FUNC(EcuWakeupM_EcuMWakeupSourceType, ECUWAKEUPM_CODE, EcuWakeupM_FuncPtrType2_t)(void);

typedef P2FUNC(void, ECUWAKEUPM_CODE, EcuWakeupM_PortFuncPtrType_t)(
	VAR(EcuWakeupM_WakeupPortIdType, AUTOMATIC)  WakeupPort,
	VAR(EcuWakeupM_WakeupPinModeType, AUTOMATIC) WakeupPortMode
);


typedef struct EcuWakeupM_LowlevelPortDrvFuncTbl_s
{
	
	EcuWakeupM_LowlevelDrvFct2_t    PortModeToGpioFunc;               /* Change port mode to GPIO */
	EcuWakeupM_LowlevelDrvFct2_t    PortModeToAlternateFunc;          /* Change port mode to peripheral function  */
	EcuWakeupM_PortFuncPtrType_t    Port_SetPinModeFunc;			  /* Set port pin mode */

} EcuWakeupM_LowlevelPortDrvFuncTbl_t;															  


/** \brief Typedef definition for low level driver functions . */

typedef struct EcuWakeupM_LowlevelDrvFuncTbl_s
{
    EcuWakeupM_LowlevelDrvFct_t     SetModeFunc;  			          /* Mode change API */
	EcuWakeupM_LowlevelDrvFct1_t    EnableWakeupIsrFunc;			  /* Enable wakeup ISR API */
	EcuWakeupM_LowlevelDrvFct1_t    DisableWakeupIsrFunc;			  /* Disable wakeup ISR API */
	EcuWakeupM_LowlevelDrvFct3_t    CheckWakeupIsrFunc;               /* Check edge detection */ 
	EcuWakeupM_LowlevelDrvFct1_t    EnableWakeupFunc;				  /* Enable wakeup  API */
	EcuWakeupM_LowlevelDrvFct1_t    DisableWakeupFunc;				  /* Disable wakeup  API */
	EcuWakeupM_LowlevelDrvFct4_t    CheckWakeupFunc;				  /* Check wakeup status of the corresponding wakeup source */
	EcuWakeupM_LowlevelDrvFct1_t    EnableNotificationCbk;		      /* Enable notification  API */
	EcuWakeupM_LowlevelDrvFct1_t    DisableNotificationCbk;		      /* Disable notification  API */
} EcuWakeupM_LowlevelDrvFuncTbl_t;

typedef P2CONST(EcuWakeupM_LowlevelDrvFuncTbl_t, AUTOMATIC, ECUWAKEUPM_APPL_CONST)   EcuWakeupM_LowlevelDrvFuncTblType;

/** \brief Typedef definition for low level driver function table . */

typedef struct EcuWakeupM_LowlevelDrvFunc_s
{
	EcuWakeupM_ModeType                    NormalMode;				   /* Normal Operating mode */
	EcuWakeupM_ModeType                    SleepMode;                  /* Sleep Operating mode */
	EcuWakeupM_LowlevelDrvFuncTblType      LowlevelDrvFunc;		       /*  Low level driver service table  */

} EcuWakeupM_LowlevelDrvFunc_t;

/** \brief Typedef definition for driver function table . */
typedef P2FUNC(P2CONST(EcuWakeupM_LowlevelDrvFunc_t, AUTOMATIC, ECUWAKEUPM_APPL_CONST), ECUWAKEUPM_CODE, EcuWakeupM_GetDrvTblType)(void);
/** \brief Typedef definition for Port driver function table . */
typedef P2FUNC(P2CONST(EcuWakeupM_LowlevelPortDrvFuncTbl_t, AUTOMATIC, ECUWAKEUPM_APPL_CONST), ECUWAKEUPM_CODE, EcuWakeupM_GetPortDrvTblType)(void);

/** \brief Typedef definition for EcuWakeupM General config data . */
typedef struct
{
	EcuWakeupM_EcuMWakeupSourceType      EcuMWakeupsourcePower;				/* 	ECUM Power wakeup source                               */
	EcuWakeupM_GetPortDrvTblType         GetPortDrvFuncTable;			    /* 	Port driver API's funtion pointer table */
	EcuWakeupM_FuncPtrType_t             EcuAppMCbk;					    /* 	Wakeup source notification to Application mode manager */ 
	EcuWakeupM_FuncPtrType1_t            NotifyWakeupToServiceLayer;        /* 	Wakeup source notification to BSW (ECUM)Service layer */
	EcuWakeupM_FuncPtrType2_t            ReadWakeupFromServiceLayer;		/* 	Validated Wakeup sources fron BSW (ECUM)Service layer */
} EcuWakeupM_GenericConfigDataType;



/** \brief Typedef definition for EcuWakeupM channel config data . */
typedef struct
{
    EcuWakeupM_WakeupType                WakeupType;						/* 	Wakeup type  */
    EcuWakeupM_LowlevelDrvChannelType    WakeupChannel;                     /* 	low level driver channel  */
    EcuWakeupM_EcuMWakeupSourceType      EcuMWakeupSource;				 	/* 	EcuM Wakeup source identifier */
	EcuWakeupM_WakeupPortIdType          WakeupPortId;                      /* 	MCU Wakeup port identifier */ 
	EcuWakeupM_WakeupPortModeType        WakeupPortAlternateMode;           /* 	Alternate function of wkaeup port mode */ 
    EcuWakeupM_GetDrvTblType             GetDrvFuncTable;                   /* 	Low leverl driver API's funtion pointer table */
	EcuWakeupM_FuncPtrVoidType_t         UserCbk;                           /* 	User callback for program specific processing */
} EcuWakeupM_ChannelConfigDataType;

/** \brief Typedef definition for EcuWakeupM config data . */

typedef struct
{
	P2CONST(EcuWakeupM_GenericConfigDataType, AUTOMATIC, ECUWAKEUPM_APPL_CONST) GenericPtr;
	P2CONST(EcuWakeupM_ChannelConfigDataType, AUTOMATIC, ECUWAKEUPM_APPL_CONST) ChannelPtr;

} EcuWakeupM_ConfigDataType;


/** \brief Typedef definition for EcuWakeupM channel state data . */
typedef struct 
{
	EcuWakeupM_WakeupStatusType   WakeupStatus; 
	EcuWakeupM_NotifyStatusType   NotifyStatus;
} EcuWakeupM_ChannelStateType;


//----------------------------------------------------------------------------------------------------------------------
// Exported data
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
// Constant exported data
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
// Exported Macros
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
// Exported functions
//----------------------------------------------------------------------------------------------------------------------


#endif  // ECUWAKEUPM_TYPES_H

/*==============================================================================================================================================
Date              	: 13-11-23
CDSID             	: skiranku
Traceability      	:
Change Description	: Initial Version.
================================================================================================================================================*/
