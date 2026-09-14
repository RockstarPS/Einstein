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
#ifndef ECUPOWERM_TYPES_H
#define ECUPOWERM_TYPES_H
//------------------------------------------------------------------------------------------------------------------------
// Included files
//------------------------------------------------------------------------------------------------------------------------
#include <Std_Types.h> 
#include "Stubs.h"

/** \brief Holds EcuPowerM init status. */
typedef enum
{
  	/* Illegal initialization value. */
  	ECUPOWERM_S_ILLEGAL = 0,
  	/* EcuPowerM was not initialized. */
	ECUPOWERM_S_UNINITIALIZED,
  	/* EcuPowerM successfully initialized. */
  	ECUPOWERM_S_INITIALIZED

} EcuPowerM_InitStatusType;

/** \brief device power request. */
typedef enum
{
  	/* Device idle state. */
	ECUPOWERM_RQST_DEVICE_IDLE = 0,
  	/* Device power up request. */
  	ECUPOWERM_RQST_DEVICE_POWERUP,
  	/* Device power down. */
  	ECUPOWERM_RQST_DEVICE_POWERDOWN,
  	/* Device power invalid request. */
  	ECUPOWERM_RQST_DEVICE_POWER_MAX

} EcuPowerM_DevicePwrRqstType;

/** \brief device power request. */
typedef enum
{
  	/* Device idle state. */
	ECUPOWERM_DEVICE_STATE_IDLE = 0,
  	/* Device power up request. */
  	ECUPOWERM_DEVICE_STATE_BUSY,
  	/* Device power completed. */
  	ECUPOWERM_DEVICE_STATE_COMPLETED,
  	/* Device power invalid request. */
  	ECUPOWERM_DEVICE_STATE_INVALID

} EcuPowerM_DeviceStateType;


/** \brief device power status. */
typedef enum
{
  	/* Device idle state. */
	ECUPOWERM_DEV_PWR_STATUS_IDLE = 0,
  	/* Device power request pending. */
  	ECUPOWERM_DEV_PWR_STATUS_PENDING,
  	/* Device power completed. */
  	ECUPOWERM_DEV_PWR_STATUS_COMPLETED
} EcuPowerM_DevicePwrStatusType;



/** \brief Holds EcuPowerM init status. */
typedef enum
{
  	/* read command. */
  	ECUPOWERM_COMMAND_READ_CHANNEL = 0,
  	/* write command. */
  	ECUPOWERM_COMMAND_WRITE_CHANNEL,
	/* wait for channel command. */
  	ECUPOWERM_COMMAND_WAITON_CHANNEL,
    /* wait for a given time command. */
    ECUPOWERM_COMMAND_WAIT_TIME,
    /* set duty command. */
    ECUPOWERM_COMMAND_SET_DUTY,
    /* set period and duty command. */
    ECUPOWERM_COMMAND_SET_PERIOD_AND_DUTY,
    /* CUSTOM channel command. */
    ECUPOWERM_COMMAND_CUSTOM,
    /* INVALID channel command. */
	ECUPOWERM_COMMAND_INVALID

} EcuPowerM_CommandType;

/** \brief Holds EcuPowerM init status. */
typedef enum
{
 	/* command state IDLE. */
 	ECUPOWERM_COMMAND_STATE_IN_IDLE = 0,
 	/* command state WAIT. */
 	ECUPOWERM_COMMAND_STATE_IN_WAIT,
 	/* command state in EXECUTION. */
 	ECUPOWERM_COMMAND_STATE_IN_EXECUTION,
 	/* command state INVALID. */
 	ECUPOWERM_COMMAND_STATE_INVALID

} EcuPowerM_CommandStateType;

/** \brief channel driver API type. */
typedef enum
{
 	/* driver api type IOHWABS. */
 	ECUPOWERM_DRIVER_API_TYPE_IOHWABS = 0,
 	/* driver api type DIO. */
 	ECUPOWERM_DRIVER_API_TYPE_DIO,
 	/* driver api type ADC. */
 	ECUPOWERM_DRIVER_API_TYPE_ADC,
 	/* driver api type PWM. */
 	ECUPOWERM_DRIVER_API_TYPE_PWM,
 	/* driver api type INVALID. */
 	ECUPOWERM_DRIVER_API_TYPE_INVALID

} EcuPowerM_LowLevelDriverApiType;

/** \brief channel category API type. */
typedef enum
{
 	/* channel type DIO. */
 	ECUPOWERM_CHANNEL_TYPE_DIGITAL = 0,
 	/* channel type Analog. */
 	ECUPOWERM_CHANNEL_TYPE_ANALOG,
 	/* channel type INVALID. */
 	ECUPOWERM_CHANNEL_TYPE_INVALID

} EcuPowerM_ChannelCategoryType;


/** \brief channel criteria type. */
typedef enum
{
 	/* channel evaluation criteria == */
 	ECUPOWERM_CRITERIA_NULL = 0,
 	/* channel evaluation criteria == */
 	ECUPOWERM_CRITERIA_EQUAL,
 	/* channel evaluation criteria < */
 	ECUPOWERM_CRITERIA_LESSER,
 	/* channel evaluation criteria <= */
 	ECUPOWERM_CRITERIA_LESSER_THAN_EQUAL,
 	/* channel evaluation criteria > */
 	ECUPOWERM_CRITERIA_GREATER,
 	/* channel evaluation criteria >= */
 	ECUPOWERM_CRITERIA_GREATER_THAN_EQUAL,
 	/* channel evaluation criteria Invalid */
 	ECUPOWERM_CRITERIA_TYPE_INVALID

} EcuPowerM_ChannelCriteriaType;


/** \brief sequence type. */
typedef enum
{
 	/* non interruptible sequence. */
 	ECUPOWERM_SEQ_POWERUP = 0,
 	/* interruptible sequence. */
 	ECUPOWERM_SEQ_POWERDOWN
} EcuPowerM_SeqType;


/** \brief sequence interruptible type. */
typedef enum
{
 	/* non interruptible sequence. */
 	ECUPOWERM_SEQ_NOT_INTERRUPTIBLE = 0,
 	/* interruptible sequence. */
 	ECUPOWERM_SEQ_INTERRUPTIBLE
} EcuPowerM_SeqInterruptType;



/** \brief Channel type. */
//typedef uint8 EcuPowerM_ChannelCategoryType; 
/** \brief Channel Command. */
//typedef uint8 EcuPowerM_CommandType;
/** \brief Channel value. */
typedef uint8 EcuPowerM_ChannelValueType;
/** \brief Device request type. */
typedef uint8 EcuPowerM_RequestType;

/** \brief IoHwAbs channel type. */
typedef uint8 EcuPowerM_IoHwAbsChannelType;




/** \brief Virtual Channel ID type. */
typedef uint16 EcuPowerM_ChannelIdType;
/** \brief Hardware Channel ID. */
typedef uint16 EcuPowerM_HardwareIdType;
/** \brief Channel Range. */
typedef uint16 EcuPowerM_RangeType;
/** \brief Wait timer. */
typedef uint16 EcuPowerM_TimerType;







/** \brief Definition of the functional pointer to register low level driver functions. */
typedef P2FUNC(uint8, ECUPOWERM_CODE, EcuPowerM_LowlevelDrvFct_t) ( VAR(EcuPowerM_ChannelIdType, AUTOMATIC) channel);

typedef P2FUNC(void, ECUPOWERM_CODE, EcuPowerM_LowlevelDrvFct1_t)( 	VAR(EcuPowerM_ChannelIdType, AUTOMATIC) channel,
																  	VAR(EcuPowerM_ChannelValueType, AUTOMATIC)value);

typedef P2FUNC(void, ECUPOWERM_CODE, EcuPowerM_LowlevelDrvFct2_t)( 	VAR(EcuPowerM_ChannelIdType, AUTOMATIC) channel,
																  	P2VAR(uint16, AUTOMATIC, ECUPOWERM_APPL_DATA)buffer);

typedef P2FUNC(Std_ReturnType, ECUPOWERM_CODE, EcuPowerM_LowlevelDrvFct3_t)(	VAR(EcuPowerM_IoHwAbsChannelType, AUTOMATIC) channel,
																   				P2VAR(uint8, AUTOMATIC, ECUPOWERM_APPL_DATA)value,
																   				P2VAR(uint8, AUTOMATIC, ECUPOWERM_APPL_DATA)error);

typedef P2FUNC(Std_ReturnType, ECUPOWERM_CODE, EcuPowerM_LowlevelDrvFct4_t)(	VAR(EcuPowerM_IoHwAbsChannelType, AUTOMATIC) channel,
																   				VAR(EcuPowerM_ChannelValueType, AUTOMATIC)value,
																   				P2VAR(uint8, AUTOMATIC, ECUPOWERM_APPL_DATA)error);

typedef P2FUNC(Std_ReturnType, ECUPOWERM_CODE, EcuPowerM_LowlevelDrvFct5_t)(	VAR(EcuPowerM_IoHwAbsChannelType, AUTOMATIC) channel,
																   				P2VAR(uint16, AUTOMATIC, ECUPOWERM_APPL_DATA)value,
																   				P2VAR(uint8, AUTOMATIC, ECUPOWERM_APPL_DATA)error);

typedef P2FUNC(Std_ReturnType, ECUPOWERM_CODE, EcuPowerM_LowlevelDrvFct6_t)( 	VAR(EcuPowerM_IoHwAbsChannelType, AUTOMATIC) channel,
																   				VAR(uint16, AUTOMATIC)duty,
																   				P2VAR(uint8, AUTOMATIC, ECUPOWERM_APPL_DATA)error);

typedef P2FUNC(Std_ReturnType, ECUPOWERM_CODE, EcuPowerM_LowlevelDrvFct7_t)( 	VAR(EcuPowerM_IoHwAbsChannelType, AUTOMATIC) channel,
																   				VAR(uint32, AUTOMATIC)period,
																   				VAR(uint16, AUTOMATIC)duty,
																   				P2VAR(uint8, AUTOMATIC, ECUPOWERM_APPL_DATA)error);

typedef P2FUNC(void, ECUPOWERM_CODE, EcuPowerM_LowlevelDrvFct8_t)( 	VAR(EcuPowerM_ChannelIdType, AUTOMATIC) channel,
																   	VAR(uint16, AUTOMATIC)duty);

typedef P2FUNC(void, ECUPOWERM_CODE, EcuPowerM_LowlevelDrvFct9_t)( 	VAR(EcuPowerM_ChannelIdType, AUTOMATIC) channel,
																	VAR(uint32, AUTOMATIC)period,
																   	VAR(uint16, AUTOMATIC)duty);



/** \brief Typedef definition for low level driver functions . */
typedef struct EcuWakeupM_LowlevelDrvFuncTbl_s
{
    EcuPowerM_LowlevelDrvFct_t	    DioReadChannel;  			          /* Read DIO channel API */
    EcuPowerM_LowlevelDrvFct1_t     DioWriteChannel;  			          /* Write DIO channel API */
    EcuPowerM_LowlevelDrvFct2_t     AdcReadChannel;  			          /* Read ADC channel API */
	EcuPowerM_LowlevelDrvFct3_t     IohwAbsReadChannel;					  /* Read IOHWABS channel API */
	EcuPowerM_LowlevelDrvFct4_t     IohwAbsWriteChannel;				  /* Write IOHWABS channel API */
	EcuPowerM_LowlevelDrvFct5_t     IohwAbsAdcReadChannel;				  /* Read Analog IOHWABS channel API */
	EcuPowerM_LowlevelDrvFct6_t    	IohwAbsSetDuty;						  /* Set Duty IOHWABS channel API */
	EcuPowerM_LowlevelDrvFct7_t    	IohwAbsSetDutyAndPeriod;			  /* Set Duty and period IOHWABS channel API */
	EcuPowerM_LowlevelDrvFct8_t		PwmSetDuty;							  /* Set Duty PWM channel API */
	EcuPowerM_LowlevelDrvFct9_t		PwmSetDutyAndPeriod;				  /* Set Duty and period PWM channel API */

} EcuPowerM_LowlevelDrvFuncTbl_t;


typedef P2CONST(EcuPowerM_LowlevelDrvFuncTbl_t, AUTOMATIC, ECUPOWERM_APPL_CONST)   EcuPowerM_DrvFuncTblType;



/** \brief Channel information. */
typedef struct EcuPowerM_ChannelInfo_s
{
	EcuPowerM_ChannelIdType 	    	channelId;
	EcuPowerM_ChannelCategoryType 		channelType;
	EcuPowerM_HardwareIdType        	hwid;
	EcuPowerM_RangeType  	      		minValue;
	EcuPowerM_RangeType  		    	maxValue;
	EcuPowerM_LowLevelDriverApiType		driverApiType;
} EcuPowerM_ChannelInfo_t;


typedef P2CONST(EcuPowerM_ChannelInfo_t, AUTOMATIC, ECUPOWERM_APPL_CONST) EcuPowerM_ChannelInfoptrType;


typedef struct EcuPowerM_ChannelRef_s
{
	EcuPowerM_ChannelInfoptrType  	    channelptr;
	EcuPowerM_ChannelCriteriaType       criteria;
	uint16                               value;
} EcuPowerM_ChannelRef_t;

typedef P2CONST(EcuPowerM_ChannelRef_t, AUTOMATIC, ECUPOWERM_APPL_CONST) EcuPowerM_ChannelRefptrType;
typedef P2CONST(EcuPowerM_ChannelRefptrType, AUTOMATIC, ECUPOWERM_APPL_CONST) EcuPowerM_ChannelRefListptrType;


/** \brief Command information. */
typedef struct EcuPowerM_CommandInfo_s
{
	EcuPowerM_ChannelIdType   		    numOfChannels;
	EcuPowerM_CommandType  	 			commandType;
	EcuPowerM_TimerType  	 			timeout;
	EcuPowerM_ChannelRefListptrType     channelRef;

} EcuPowerM_CommandInfo_t;

typedef P2CONST(EcuPowerM_CommandInfo_t, AUTOMATIC, ECUPOWERM_APPL_CONST) EcuPowerM_CommandInfoptrType;
typedef P2CONST(EcuPowerM_CommandInfoptrType, AUTOMATIC, ECUPOWERM_APPL_CONST) EcuPowerM_CommandListptrType;


/** \brief Job information. */
typedef struct EcuPowerM_JobInfo_s
{
	uint8 							numOfCommands;
	EcuPowerM_CommandListptrType 	commandptr;
} EcuPowerM_JobInfo_t;

typedef P2CONST(EcuPowerM_JobInfo_t, AUTOMATIC, ECUPOWERM_APPL_CONST) EcuPowerM_JobInfoptrType;
typedef P2CONST(EcuPowerM_JobInfoptrType, AUTOMATIC, ECUPOWERM_APPL_CONST) EcuPowerM_JobListptrType;


/** \brief Sequence information. */
typedef struct EcuPowerM_SequenceInfo_s
{
	uint8 						numOfJobs;
	EcuPowerM_SeqType			sequenceType;
	EcuPowerM_SeqInterruptType	interruptible;
	EcuPowerM_JobListptrType  	jobptr;
} EcuPowerM_SequenceInfo_t;

typedef P2CONST(EcuPowerM_SequenceInfo_t, AUTOMATIC, ECUPOWERM_APPL_CONST)      EcuPowerM_SequenceInfoptrType;
typedef P2CONST(EcuPowerM_SequenceInfoptrType, AUTOMATIC, ECUPOWERM_APPL_CONST) EcuPowerM_SeqListptrType;


/** \brief Device sequence information. */

/** \brief Device information. */
typedef struct EcuPowerM_DeviceInfo_s
{
	uint8							numOfSequences;
	EcuPowerM_SeqListptrType		sequenceptr;
} EcuPowerM_DeviceInfo_t;

typedef EcuPowerM_DeviceInfo_t EcuPowerM_DeviceConfigType;
typedef P2CONST(EcuPowerM_DeviceInfo_t, AUTOMATIC, ECUPOWERM_APPL_CONST) EcuPowerM_DeviceConfigptrType; 

/** \brief Device information. */
typedef struct EcuPowerM_CurrentState_s
{
	EcuPowerM_DeviceStateType 		devState;
	EcuPowerM_DevicePwrRqstType		devPendingRqst;
	EcuPowerM_DevicePwrRqstType     devCurrentRqst;
	uint8 							device;
	uint8                       	sequence;
	uint8                       	jobCnt;
	uint8                       	commandCnt;
	EcuPowerM_CommandStateType     	commandState;
	uint16                          waitTimer;

}EcuPowerM_CurrentState_t;

typedef EcuPowerM_CurrentState_t EcuPowerM_CurrentStateType;

   


#endif/*End of File */

/*==============================================================================================================================================
Date              	: 27-12-23
CDSID             	: skiranku
Traceability      	:
Change Description	: Initial Version.
================================================================================================================================================*/

