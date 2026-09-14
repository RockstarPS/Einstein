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
*    @file CanTrcv_Cfg.h
*    @ingroup CanTrcvConfiguration
*    @brief This is CanTrcv Pre-compile time configuration header file. It contains definitions of pre-compile time
*    configuration parameters for the CanTrcv module.
*    @defgroup CanTrcvConfiguration
*    @brief This contains the configuration files for the CanTrcv module.
********************************************************************************************************************/
#ifndef CANTRCV_CFG_H
#define CANTRCV_CFG_H
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "CanTrcv_GeneralTypes.h"
#include "SchM_CanTrcv.h"
/********************************************************************************************************************
*  PUBLIC MACRO DEFINITIONS                                                                                         *
********************************************************************************************************************/
/* Software Version */
#define CANTRCV_CFG_SW_MAJOR_VERSION                0u
#define CANTRCV_CFG_SW_MINOR_VERSION                0u
#define CANTRCV_CFG_SW_PATCH_VERSION                1u
/* Autosar Release */
#define CANTRCV_CFG_AR_RELEASE_MAJOR_VERSION        4u
#define CANTRCV_CFG_AR_RELEASE_MINOR_VERSION        3u
#define CANTRCV_CFG_AR_RELEASE_REVISION_VERSION     1u
/*! @brief Switches the Default Error Tracer (Det) detection ON or OFF.*/
#define CANTRCV_DEV_ERROR_DETECT            		STD_ON
/*! @brief Switches the Default Error Tracer (Det) notification ON or OFF.*/
#define CANTRCV_DEV_ERROR_REPORT					STD_ON
/*! @brief Switches version information API on and off. If switched off, function need not be
    present in compiled code. */
#define CANTRCV_GET_VERSION_INFO            		STD_ON
/*! @brief Defines the wakeup by polling support value .*/
#define CANTRCV_WAKEUP_BY_POLLING       			0U
/*! @brief Defines the wakeup not supported value .*/
#define CANTRCV_WAKEUP_NOT_SUPPORTED    			1U
/*! @brief Defines type of wakup feature support.
    CANTRCV_WAKEUP_NOT_SUPPORTED - No support
    CANTRCV_WAKEUP_BY_POLLING - wakup by polling support */
#define CANTRCV_GENERAL_WAKEUP_SUPPORT				CANTRCV_WAKEUP_BY_POLLING
/*! @brief Defines whether wakup by bus is supported or Not .*/
#define CANTRCV_WAKEUP_BY_BUS_SUPPORT				STD_ON
/*! @brief Defines whether wakup by polling is supported or Not .*/
#define CANTRCV_TRCV_WAIT_STATE_SUPPORT				STD_OFF
/*! @brief Defines whether transceiver SPI handling is supported or Not .*/
#define CANTRCV_TRCV_SPI_INTERFACE_SUPPORT			STD_OFF
/*! @brief Defines whether ICU notification is supported or Not .*/
#define CANTRCV_ICU_SUPPORT							STD_OFF
/*! @brief Defines whether EcuM wakup source is supported or Not .*/
#define CANTRCV_ECUM_WAKEUPSOURCE_SUPPORT			STD_ON
/*! @brief Defines whether PN feature is supported or Not .*/
#define CANTRCV_HW_PN_SUPPORT						STD_ON
/*! @brief This parameter describes the period for cyclic call to CanTrcv_MainFunctionDiagnostics.
    Unit is milliseconds. */
#define CANTRCV_MAIN_FUNCTION_DIAGNOSTICS_PERIOD    10U

/*@brief This parameter describes the period for cyclic call to CanTrcv_MainFunction. Unit is milliseconds. */
#define CANTRCV_MAIN_FUNCTION_PERIOD        		10U

/* Defines the HW id of the transceiver Tja1040 */
#define CAN_TRCV_HW_TJA1040             			0U
/* Defines the number of transceiver HW supported */
#define CANTRCV_NUM_OF_HW_SUPPORTED    				2U
/* Defines the number of transceiver channels supported */
#define CANTRCV_NUM_OF_TRCV_CHANNELS   				2U

#define CanTrcv_EnterCriticalSection()              SchM_Enter_CanTrcv_CANTRCV_EXCLUSIVE_AREA_0()
#define CanTrcv_ExitCriticalSection()               SchM_Exit_CanTrcv_CANTRCV_EXCLUSIVE_AREA_0()

#ifndef CANTRCV_IGNORE_UNUSED_PARAM
#define CANTRCV_IGNORE_UNUSED_PARAM(param)                  ((void)(param))
#endif

#if (CANTRCV_TRCV_WAIT_STATE_SUPPORT == STD_ON)
/* No timer used */
#define CanTrcv_TimerTypeNone           			0U
/* 16 bit 1us timer */
#define CanTrcv_TimerType1us16bit       			1U
/* Type of the Time Service Predefined Timer.  */
typedef uint8 CanTrcv_TimerType;

/*! @brief Wait time for transceiver state changes in millliseconds. */
#define CANTRCV_WAIT_TIME               			0U
#endif

#if (CANTRCV_TRCV_SPI_INTERFACE_SUPPORT == STD_ON)
/*! @brief Indicates the maximum number of communication retries in case of a failed SPI communication
    (applies both to timed out communication and to errors/ NACK in the response data).
    If configured value is '0', no retry is allowed (communication is expected to succeed at first try). */
#define CANTRCV_SPI_COMM_RETRIES    				0U

/*! @brief Indicates the maximum time allowed to the CanTrcv for replying (either positively or negatively) to a
    SPI command. Timeout is configured in milliseconds. Timeout value of '0' means that no specific timeout is
    to be used by CanTrcv and the communication is exe-cuted at the best of the SPI HW capacity. */
#define CANTRCV_SPI_COMM_TIMEOUT    				0U
#endif

#if(CANTRCV_HW_PN_SUPPORT == STD_ON)
#define CANTRCV_NUM_OF_PN_CFG_ID					1U
#endif

#if (CANTRCV_ICU_SUPPORT == STD_ON)
#include "Icu.h"
#endif

#if (CANTRCV_ECUM_WAKEUPSOURCE_SUPPORT == STD_ON)
#include "EcuM.h"
#endif

/********************************************************************************************************************
*  PUBLIC TYPE DEFINITIONS                                                                                         *
********************************************************************************************************************/
/*! @brief  This is the type of the external data structure containing the overall initialization data for the CAN
    transceiver driver and settings affecting all transceivers. Fur-thermore it contains pointers to transceiver
    configuration structures. The contents of the initialization data structure are CAN transceiver hardware specific.*/
typedef struct
{
    uint8 Dummy;
}CanTrcv_ConfigType;

/*! @brief State of CAN transceiver after call to CanTrcv_Init. */
typedef enum
{
    CANTRCV_OP_MODE_NORMAL = 0, /* Normal operation mode */
    CANTRCV_OP_MODE_SLEEP ,     /* Sleep operation mode */
    CANTRCV_OP_MODE_STANDBY     /* Standby operation mode */
}CanTrcv_InitStateType;

/*! @brief It defines the  configuration of supported HW transceiver */
typedef struct
{
    /*! @brief Defines whether the tcv channel is used or not */
	boolean                     CanTrcv_IsChannelUsed;
    /*! @brief Defines the channel id of the specific transceiver HW driver . This id is used by the specific
        transceiver HW driver to access the configuration of that channel */
	uint8						CanTrcv_TrcvChannelId;
    /*! @brief Defines the index of the transceiver HW driver function list configuration */
	uint8						CanTrcv_HwFunctCfgId;
	/*! @brief Defines the state of the transceiver after CanTrcv_Init */
	CanTrcv_TrcvModeType        CanTrcv_InitMode;
#if(CANTRCV_ICU_SUPPORT == STD_ON)
	boolean						CanTrcv_IsIcuSupportEnabled;
    /*! @brief It defines Reference to the IcuChannel to enable/disable the interrupts for wakeups. */
    Icu_ChannelType             CanTrcv_IcuchannelId;
#endif
#if (CANTRCV_GENERAL_WAKEUP_SUPPORT == CANTRCV_WAKEUP_BY_POLLING)
	/*! @brief Defines whether the wakeup by bus is supported or not . If CAN transceiver hardware does not support
		wake up by bus value is always FALSE. If CAN transceiver hardware supports wake up by bus value is
		TRUE or FALSE depending whether it is used or not.
		TRUE = Is used. FALSE = Is not used */
	boolean                     CanTrcv_WakeupByBusUsed;
#if (CANTRCV_ECUM_WAKEUPSOURCE_SUPPORT == STD_ON)
	boolean						CanTrcv_IsWakeupSourceSupported;
	/*! @brief It defines the wakeup sources that should be used in the calls to EcuM_SetWakeupEvent */
	EcuM_WakeupSourceType       CanTrcv_WakeupSource;
#endif
#endif
#if(CANTRCV_HW_PN_SUPPORT == STD_ON)
    /*! @brief Defines the index of the transceiver PN configuration */
    uint8						CanTrcv_PnCfgId;
#endif
}CanTrcv_ChannelCfgType;

#if(CANTRCV_HW_PN_SUPPORT == STD_ON)
/*! @brief Provides the state of a flag in the transceiver hardware. */
typedef enum
{
	CANTRCV_FLAG_SET=0U, /* The flag is set in the transceiver hardware. */
	CANTRCV_FLAG_CLEARED /* The flag is cleared in the transceiver hardware. */
}CanTrcv_TrcvFlagStateType;

/*! @brief It defines the PN configuration of supported HW transceiver */
typedef struct
{
	/*! @brief Indicates if the Bus Error (BUSERR) flag is managed by the BSW. This flag is set if a bus failure
	        is detected by the transceiver.
	        TRUE = Supported by transceiver and managed by BSW. FALSE = Not managed by BSW. */
	boolean CanTrcv_BusErrFlagSupport;
	/*! @brief Indicates if the Power On Reset (POR) flag is available and is managed by the transceiver.
	        TRUE = Supported by Hardware. FALSE = Not supported by Hardware */
	boolean CanTrcv_PowerOnFlag;
	/*! @brief Indicates whether extended or standard ID is used.
	            TRUE = Extended Can identifier is used. FALSE = Standard Can identifier is used */
	boolean CanTrcv_PnCanIdIsExtended;
    /*! @brief Indicates whether the selective wake-up function is enabled or disabled in HW.
        TRUE = Selective wakeup feature is enabled in the transceiver hardware
        FALSE = Selective wakeup feature is disabled in the transceiver hardware */
    boolean CanTrcv_PnEnabled;
    /*! @brief Data Length of the Wake-up Frame (WUF). */
#if (CANTRCV_ECUM_WAKEUPSOURCE_SUPPORT == STD_ON)
	boolean						CanTrcv_IsSysErrOrPorSupported;
	/*! @brief It defines the wakeup sources that should be used in the calls to EcuM_SetWakeupEvent
	 if the HW supports POR or SYSERR flags */
	EcuM_WakeupSourceType       CanTrcv_SyserrWakeupSource;
#endif
	uint8 CanTrcvPnFrameDlc;
    /*! @brief Indicates the CAN Bus communication baud rate in kbps. */
	uint32 CanTrcv_BaudRateValue;
    /*! @brief CAN ID of the Wake-up Frame (WUF). */
    uint32 CanTrcv_PnFrameCanId;
    /*! @breif ID Mask for the selective activation of the transceiver. It is used to enable-Frame
        Wake-up (WUF) on a group of IDs */
    uint32 CanTrcv_PnFrameCanIdMask;
}CanTrcv_PartialNetworkCfgType;

/*! @brief Datatype used for describing whether PN wakeup functionality in CanTrcv is ena-bled or disabled.*/
typedef enum
{
	CANTRCV_PN_DISABLED=0U,   /*! @brief PN wakeup functionality in CanTrcv is disabled */
    CANTRCV_PN_ENABLED     /*! @brief PN wakeup functionality in CanTrcv is enabled */
}CanTrcv_PNActivationType;

#endif


/*! @brief It defines the type for Init function of the HW specific transceiver driver  */
typedef void (*CanTrcv_InitFnType)(void);
/*! @brief It defines the type for set operation mode function of the HW specific transceiver driver  */
typedef Std_ReturnType (*CanTrcv_SetOpModeFnType)(uint8 TrcvIdx, CanTrcv_TrcvModeType OpMode);
/*! @brief It defines the type for get operation mode function of the HW specific transceiver driver  */
typedef Std_ReturnType (*CanTrcv_GetOpModeFnType)(uint8 TrcvIdx, CanTrcv_TrcvModeType* OpModePtr);
/*! @brief It defines the type for wakeup reason function of the HW specific transceiver driver  */
typedef Std_ReturnType (*CanTrcv_GetBusWuReasonFnType)(uint8 TrcvIdx, CanTrcv_TrcvWakeupReasonType* WuReasonPtr);
#if(CANTRCV_HW_PN_SUPPORT == STD_ON)
/*! @brief It defines the type for get system data function of the HW specific transceiver driver  */
typedef Std_ReturnType (*CanTrcv_GetTrcvSystemDataFnType)(uint8 TrcvIdx, const uint32* SysDataPtr);
/*! @brief It defines the type for clear wakeup function of the HW specific transceiver driver  */
typedef Std_ReturnType (*CanTrcv_ClearTrcvWufFlagFnType)(uint8 TrcvIdx);
/*! @brief It defines the type for read timeout flag function of the HW specific transceiver driver  */
typedef Std_ReturnType (*CanTrcv_ReadTrcvTimeoutFlagFnType)(uint8 TrcvIdx, CanTrcv_TrcvFlagStateType* FlagStatePtr);
/*! @brief It defines the type for clear timeout flag function of the HW specific transceiver driver  */
typedef Std_ReturnType (*CanTrcv_ClearTrcvTimeoutFlagFnType)(uint8 TrcvIdx);
/*! @brief It defines the type for read silence flag function of the HW specific transceiver driver  */
typedef Std_ReturnType (*CanTrcv_ReadTrcvSilenceFlagFnType)(uint8 TrcvIdx, CanTrcv_TrcvFlagStateType* FlagStatePtr);
/*! @brief It defines the type for check wakeup function of the HW specific transceiver driver  */
typedef Std_ReturnType (*CanTrcv_CheckWakeupFnType)(uint8 TrcvIdx, CanTrcv_TrcvWakeupReasonType* WuReasonPtr);
/*! @brief It defines the type for check wakeup flag function of the HW specific transceiver driver  */
typedef Std_ReturnType (*CanTrcv_CheckWakeFlagFnType)(uint8 TrcvIdx);
#endif

/*! @brief This defies the type of function list supported by the HW specific transceiver driver */
typedef struct
{
    /*! @brief It defines the Init function of the HW specific transceiver driver  */
    CanTrcv_InitFnType                          CanTrcv_InitFn;
    /*! @brief It defines the set operation mode function of the HW specific transceiver driver  */
    CanTrcv_SetOpModeFnType                     CanTrcv_SetOpModeFn;
    /*! @brief It defines the get operation mode function of the HW specific transceiver driver  */
    CanTrcv_GetOpModeFnType                     CanTrcv_GetOpModeFn;
    /*! @brief It defines the wakeup reason function of the HW specific transceiver driver  */
    CanTrcv_GetBusWuReasonFnType                CanTrcv_GetBusWuReasonFn;
#if(CANTRCV_HW_PN_SUPPORT == STD_ON)
    /*! @brief It defines the get system data function of the HW specific transceiver driver  */
    CanTrcv_GetTrcvSystemDataFnType             CanTrcv_GetTrcvSystemDataFn;
    /*! @brief It defines the clear wakeup function of the HW specific transceiver driver  */
    CanTrcv_ClearTrcvWufFlagFnType              CanTrcv_ClearTrcvWufFlagFn;
    /*! @brief It defines the read timeout flag function of the HW specific transceiver driver  */
    CanTrcv_ReadTrcvTimeoutFlagFnType           CanTrcv_ReadTrcvTimeoutFlagFn;
    /*! @brief It defines the clear timeout flag function of the HW specific transceiver driver  */
    CanTrcv_ClearTrcvTimeoutFlagFnType          CanTrcv_ClearTrcvTimeoutFlagFn;
    /*! @brief It defines the read silence flag function of the HW specific transceiver driver  */
    CanTrcv_ReadTrcvSilenceFlagFnType           CanTrcv_ReadTrcvSilenceFlagFn;
    /*! @brief It defines the check wakeup function of the HW specific transceiver driver  */
    CanTrcv_CheckWakeupFnType                   CanTrcv_CheckWakeupFn;
    /*! @brief It defines the check wakeup flag function of the HW specific transceiver driver  */
    CanTrcv_CheckWakeFlagFnType                 CanTrcv_CheckWakeFlagFn;
#endif
}CanTrcv_HWFunctCfgType;

/********************************************************************************************************************
*  PUBLIC VARIABLE AND CONSTANT DECLARATION                                                                        *
********************************************************************************************************************/
/*! @brief This is the type of the external data structure containing the overall initialization data for the CAN
    transceiver driver and settings affecting all transceivers. */
extern const CanTrcv_ConfigType * CanTrcv_ConfigPtr;
/*! @brief This defines the Can Transciver channel configuration */
extern const CanTrcv_ChannelCfgType CanTrcv_ChannelCfg[CANTRCV_NUM_OF_TRCV_CHANNELS];
/*! @brief This defines the Can Transciver HW functions configuration */
extern const CanTrcv_HWFunctCfgType CanTrcv_HWFunctCfg[CANTRCV_NUM_OF_HW_SUPPORTED];

#endif /* CANTRCV_CFG_H */
