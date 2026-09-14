/*===================================================================================================================
**
**                     CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2001. Visteon Corporation owns all rights to this work and
** intends to maintain it in confidence to preserve its trade secret status.
** Visteon Corporation reserves the right, under the copyright laws of the
** United States or those of any other country that may have jurisdiction,
** to protect this work as an unpublished work, in the event of an
** inadvertent or deliberate unauthorized publication. Visteon Corporation
** also reserves its rights under all copyright laws to protect this work as
** a published work, when appropriate. Those having access to this work may
** not copy it, use it, modify it or disclose the information contained in
** it without the written authorization of Visteon Corporation.
**
**===================================================================================================================
**
** Name:           Mgrdiagcdd_Cfg.h
**
** Description:    
**                
**
**====================================================================================================================*/
#ifndef MGRDIAGCDD_CFG_H
#define MGRDIAGCDD_CFG_H

#include "Std_Types.h"
#include "Rte_CMeetCdd.h"
#include "Dcm.h"
#include "Rte_NvM_Type.h"
#include "MemLib.h"	
#include "NvM_Cfg.h"
#include "NvM.h"
#include "Rte_Type.h"
#define BCDMANIPUTATION_ENABLE_DIMMING_CTRL      (0x01U)
#define DECIMALMANIPUTATION_ENABLE_DIMMING_CTRL  (0x00U)

#define BCDMANIPUTATION_ENABLE_ANALOG_DIAG      (0x00U)		/*if 'DUTY_COTROL_WITH_ONE_CHANNEL' is enabled this macro should be made zero*/
#define DECIMALMANIPUTATION_ENABLE_ANALOG_DIAG  (0x01U)		/*if 'DUTY_COTROL_WITH_ONE_CHANNEL' is enabled this macro should be made zero*/
//#define CMEETCDD_APPL_STUBS
//#define CMEETCDD_STUBS_CHIMES
//#define CMEETCDD_STUBS_ILLUM

#define MEETMODE_CHECK_FOR_ALL_SERVICES
//#define MEETMODE_ENTRY_DISABLE
/*====================================================================================================================
** INCLUDE FILES
**===================================================================================================================*/

/*====================================================================================================================
**   M A C R O   D E F I N I T I O N S
**===================================================================================================================*/

#define MGRDIAG_INVALID_MODE (DCM_E_CONDITIONSNOTCORRECT)
#define MGRDIG_REQUEST_OUT_OF_RANGE (DCM_E_REQUESTOUTOFRANGE)
#define INVALID_MODE (MGRDIAG_INVALID_MODE)
// Bit Manipulation Macros
static inline void SETBIT(uint32 *operand, uint32 bit_mask)
{
    if (operand != NULL_PTR)
    {
        *operand |= bit_mask;
    }
}
static inline void CLEARBIT(uint32 *operand, uint32 bit_mask)
{
    if (operand != NULL_PTR)
    {
        *operand &= (uint32)(~bit_mask);
    }
}
// Masking Macros
static inline uint8 HI_BYTE(uint8 b)
{
    uint32 intermediate = ((uint32)b >> 4U) & 0x0FU;
    return (uint8)intermediate;
}

static inline uint8 LO_BYTE(uint8 b)
{
    uint32 intermediate = (uint32)b & 0x0FU;
    return (uint8)intermediate;
}
#define MEET_SESSION    0x01U
#define NORMAL_SESSION	0x00U
#define CUST_SESSION    (CustomerSession)

void Manuf_SessionCheck(uint8 *SessionValue);

static inline void MGRDIAG_GET_SESSION(uint8 *x)
{
	if(x != NULL_PTR)
	{
    	Manuf_SessionCheck(x);
	}
}
#define CONTROL_OPTION_STA		((uint8)0x03U)
#define CONTROL_OPTION_RCTE		((uint8)0x00U)

/*Different Diag type counts*/
#define  MGRDIAGCDD_READ_DID_COUNT      	((uint8)11U)
#define  MGRDIAGCDD_WRITE_DID_COUNT      	((uint8)11U)

#define  MGRDIAGCDD_IOCTL_STA_DID_COUNT  	((uint8)3U)
#define  MGRDIAGCDD_IOCTL_RCTE_DID_COUNT 	((uint8)3U)

#define  MGRDIAGCDD_RC_START_DID_COUNT  	((uint8)3U)
#define  MGRDIAGCDD_RC_STOP_DID_COUNT    	((uint8)2U)
#define  MGRDIAGCDD_RC_RESULTS_DID_COUNT 	((uint8)2U)

//#define DUTY_COTROL_WITH_ONE_CHANNEL   1
#define	 IOCTRLRD_SINGLE_CHANNEL_DIM_CTRL  

/* The below macro will do binary search of the DID instead of searching in the complete for loop*/

#define MGRDIAGCDD_BINARY_SEARCH

static inline void MGRDIAGCDD_AAPPL_SPEC_INIT(void)
{
#ifdef MGRDIAGCDD_ENABLE_SPEC_INIT /* Example toggle */
    (void)Rte_Write_MeetCdd_ppMfgAppctrlSleepSts_MfgSleepSts(SLEEP_NOT_READY);
    (void)Rte_Call_rpIoHwAbSet_Impl_SetDuty(eIODutyOutId_GREEN_TT_PWM, 1000U);
    (void)Rte_Call_rpIoHwAbSet_Impl_SetPin(eIOPinOutId_BLUE_TT_PWM, STD_HIGH);
    (void)Rte_Call_rpIoHwAbSet_Impl_SetPin(eIOPinOutId_AMBER_TT_PWM, STD_HIGH);
    (void)Rte_Call_rpIoHwAbSet_Impl_SetPin(eIOPinOutId_YELLOW_TT_PWM, STD_HIGH);
#else
#endif
}

extern void App_spec_One_Sec_Timer(void);
extern void App_Timer_Set_Status(uint8 p_timer_status_U8);
extern uint8 App_Timer_Get_Status(void);

static inline void APP_SPEC_10MS_TIMER_USAGE(void)
{
    App_spec_One_Sec_Timer();
}
static inline void APP_SPEC_SET_TIMER_STATUS(uint8 status)
{
    App_Timer_Set_Status(status);
}
static inline uint8 APP_SPEC_GET_TIMER_STATUS(void)
{
    return App_Timer_Get_Status();
}
#define MEET_NVM_FLAG 						(uint16)(0x52AEU)
#define CUST_NVM_FLAG 						(uint16)(0xFFFFU)
#define CANWK_NVM_FLAG 						(uint16)(0xCA68U)
#define MEET_ENTRY_DISABLE_NVM_FLAG 		(uint16)(0x7E5AU)

#define MEET_GIP_ENABLED	(1U)		//enable if any gip service available and implemented
#ifdef MEET_GIP_ENABLED
#define EVENT_TRIGGERED_GIP_DIAG_RESPONSE     (1U)
#define MEET_GIP_SEPERATE_REQ_FOR_DID_DR_IO			/*enable if VIP to GIP ucl request is seperate for DID,IoCtrl and routine*/
#endif
#define UNUSED(x)               ((void)(x))
#define DIDZERO  	    (uint16) (0x00u)
#define DIDONE   	    (uint8) (0x01u)
#define DIDTWO   	    (uint8) (0x02u)
#define DIDBYTE0        (uint8) (0x00u)
#define DIDBYTE1        (uint8) (0x01u)
#define DIDBYTE2        (uint8) (0x02u)
#define DIDBYTE3        (uint8) (0x03u)
#define DIDBYTE4        (uint8) (0x04u)
#define DIDBYTE5        (uint8) (0x05u)
#define DIDBYTE6        (uint8) (0x06u)
#define DIDBYTE7        (uint8) (0x07u)
#define DIDBYTE8        (uint8) (0x08u)
#define DIDBYTE9        (uint8) (0x09u)
#define DIDBYTE10       (uint8) (0x0Au)
#define DIDBYTE14       (uint8) (0x0Eu)
#define DIDBIT0MASK 	(uint8) (0x01u)
#define DIDBIT1MASK 	(uint8) (0x02u)
#define DIDBIT2MASK 	(uint8) (0x04u)
#define DIDBIT3MASK		(uint8) (0x08u)
#define DIDBYTE0MASK    (uint8) (0x01u)
#define DIDBYTE1MASK    (uint8) (0x02u)
#define DIDBYTE2MASK    (uint8) (0x04u)
#define DIDBYTE3MASK    (uint8) (0x08u)
#define DIDBYTE4MASK    (uint8) (0x10u)
#define DIDBYTE5MASK    (uint8) (0x20u)
#define DIDBYTE6MASK    (uint8) (0x40u)
#define DIDBYTE7MASK    (uint8) (0x80u)
#define DIDBYTEMASK     (uint8) (0xFFu)
#define DIDSHIFT1BYTE   (uint8) (0x08u)
#define DIDSHIFT2BYTE   (uint8) (0x10u)
#define DIDSHIFT3BYTE   (uint8) (0x18u)
#define DIDSHIFT4BYTE   (uint8) (0x40u)

#define DID_U16_2LSBMASK    (uint16) (0x0003)
#define DID_U16_U8_MASK     (uint16) (0x00FF)
//#define MEET_GIP_ENABLED_CRYPTO	(1U)		//enable if any Cryptography Key management gip service available
static uint8 Channel_ID;
#define RC_RSP_SHORT_LENGTH  3U
#define RC_RESULTS_ALL_ADC_RSP_LENGTH 14U
#define RC_RESULTS_ONE_ADC_RSP_LENGTH 4U
/*Configuration of required services*/

//#define CRYPTO_KEY_MANAGEMENT							(1U)
//#define CYBERSECDIAG_CRYPTO_KEY_VERIFICATION 			(1U)
//#define CYBERSECDIAG_SYMMETRIC_KEY_PROGRAMMING
//#define CYBERSECDIAG_ENCRYPT_DECRYPT_NOTIFYHANDLER
//#define CYBERSECDIAG_WRITTENKEY_READ
//#define CYBERSECDIAG_KEY_STORE_AND_LOCK
#define CRYPTO_KEY_MANAGEMENT_IMX8

/*#define IOCALIB_MODULE_ENABLE*/
#ifdef IOCALIB_MODULE_ENABLE
// #define IOCALIBDIAG_RTC_CALIBRATION
// #define IOCALIB_MODULE_ENABLE_JOBRESULT
// #define IOCALIBSERVICESENABLE   				1
// #define LEFTSWTBACKLIGHTENABLE 				0
// #define RIGHTSWTBACKLIGHTENABLE				0
// #define TACHOSCALEILLUMNENABLE				0
// #define TACHOPTRILLUMNENABLE					0
// #define FUELTEMPSCALEILLUMNENABLE			0
// #define FUELPTRILLUMNENABLE					0
// #define TEMPPTRILLUMNENABLE					0
// #define ANALOGMEASCALIBFUELLVLENABLE
// #define ANALOGMEASCALIB3POINTFUELLVLENABLE	1
// #define IOCALIBSOUNDCHANNELVOLUME 			1
// #define IOCALIBSOUNDMIXEROUTPUTVOLUME 		1
// #define ANALOGMEASCALIBOILLVLENABLE			0
// #define FUEL_SENDER_CALIBRATION_TABLE 		1
#endif

#define DISPLAY_MODULE_ENABLE
# define TFTPATTERNCTRLENABLE
#define VALIDATETDMINTERFACE
//#define MDIO_BRODCOM_SWITCH_INTERFACE
/*Display Control*/
#ifdef DISPLAY_MODULE_ENABLE
#define DISPLAYCONTROLDIAG_I2CTEST_ROUTINE
/*
#define DISPLAYCONTROLDIAG_TSW_I2CREAD_ROUTINE
# define TFTPATTERNCTRLENABLE
# define TFT_VIDEOCHECK_ENABLE
#define IOCONTOLRD_ALL_LIT_LED_ENABLE
#define IOCONTOLRD_TELLTALE_CONTROL_ENABLE
#define DISPLAY_TOUCH_VERIFICATION_CHECK
# define DISPLAY_TOUCH_TEST_CHECK
# define TFTFULLCOLORCTRLENABLE				0
# define TFTONEDOTCTRLENABLE				0
# define TFTXYSHIFTCTRLENABLE				0
# define TFTADJCHESSPTRNCTRLENABLE			0
# define DISPLAYXYPARAMETERENABLE			0
# define DISPLAYSPLSEQEXEENABLE				0  
# define DISPLAY_LCD_SEGMENT_CTRL_ENABLE    1
# define TFT_CONTROL_WITH_DUTY 				1
# define LCD_CONTROL_WITH_DUTY				1
# define LCD_LED_ALL_LIT  					1
# define TT_TOTAL_NUM_OF_TELLTALES			23u
#define DISPLAY_CONTENT_INTEGRITY_CHECK
#ifdef	LCD_LED_ALL_LIT
#define LCD_CONTROL_ALL_LIT_SEGMENT_ENABLE
#define TFT_CONTROL_ALL_LIT_COLOR_ENABLE
#define IOCONTOLRD_ALL_LIT_ILLUMINATION_ENABLE
#endif
#define DISPLAY_CONTENT_INTEGRITY_CHECK
*/
#endif
#ifdef READ_INTERFACE_FOR_APPL_COMPONENTS

#define NO_OF_NON_DCM_DIDS    5
#endif

/*Configuration of required services*/

//#define CYBERSECDIAG_CSM_SAFE_KEY_NUMBER
//#define CYBERSECDIAG_JTAG_PASSWORD_WRITE_LOCK_ENABLE
//#define CYBERSECDIAG_SECURE_SYMMETRIC_KEY_PROGRAMMING
//#define CYBERSECDIAG_SYMMETRIC_KEY_VERIFICATION

#define RESETDIAG_MODULE_ENABLE
/*Reset Sleep*/
#ifdef RESETDIAG_MODULE_ENABLE
//#define LOWQCURRENTENABLE                   1
// #define SLEEPMODEENABLE					1
#define WDRSTENABLE						1
//#define RSTCNTRREADINGENABLE				1
//#define RESET_BY_PASS_ENABLE				1
//#define RESETSLEEPDIAG_ODOMETER_RESET		1
//#define SWRSTENABLE   					1
//#define LOWQCURRENTENABLE_CONTROL
#define eLowQCmdOFF (0U)
#define eLowQCmdON  (1U)
typedef uint8 ELowQCurrentSleepStatus;
#endif

#define MEMDIAG_MODULE_ENABLE
/*Memory services*/
#ifdef MEMDIAG_MODULE_ENABLE
# define MFGMODEREQENABLE						
# define MFGMODESTATUS
# define HYPER_FLASH_CHKSUM_TEST_FOR_ALL
# define PROGRAM_NVM_FROM_ROM_BLOCKWISE
# define COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
# define MFG_MODE_NVM
//# define NVMACCESSBYADDRESSRCENABLE	
/*
# define PROGRAM_NVM_FROM_ROM
# define HYPERFLASHCHKSUMTSTENABLE
# define MEMDIAG_ODOMETER_NVM_ROUTINE
# define MEMDIAG_VIP_GIP_MEMORY_CHECKSUM_TEST
# define EXTNVMACCESSBYBLOCKIDREADWRITEENABLE
# define AUTO_CONFIGURE_OR_VERIFY
# define MEMDIAG_MEMORY_READ_WRITE_BY_ADDRESS
# define MEMWRITETESTENABLE
# define MEMDIAG_ODOMETER_NVM_READWRITE
# define NVMVALIDITYCHKENABLE
# define NVMACCESSBYBLOCKIDREADWRITEENABLE
# define MEMDIAG_MEMORY_VALIDITY_CHECK
*/
#endif

/* Enable for Sharedboot.diagcdd module */
//#define SHAREDIAG_MODULE_ENABLE
#ifdef SHAREDIAG_MODULE_ENABLE
/* ShareDiag macros */
#define SHAREDIAG_SERVICE_ENABLE_1          /* Define this if the service is enabled */
#define SHAREDIAG_SERVICE_ENABLE_2          /* Define this if the service is enabled */
#define SHAREDIAG_SERVICE_ENABLE_3          /* Define this if the service is enabled */
#define SHAREDIAG_SERVICE_BOOT_READ	        /* Define this macro o read the boot version*/
#endif

/*Enable if PreConditional Flag check required in your project*/
//#define PRECONDITION_CHECK_REQUIRED
#ifdef PRECONDITION_CHECK_REQUIRED
#define FLAGZERO_B (boolean) (0x00u)
#define FLAGONE_B  (boolean) (0x01u)
#define ALLPWRMODE   (uint8) (0x0Fu)
#define RUNPWRMODE     DIDBIT3MASK

#define MGRDIAGCDD_OFFPWRMODE        ePwrMode_Off
#define MGRDIAGCDD_ACCPWRMODE        ePwrMode_Acc
#define MGRDIAGCDD_STARTPWRMODE      ePwrMode_Start
#define MGRDIAGCDD_RUNPWRMODE        ePwrMode_Run

#define MGRDIAGCDD_GET_LVSD0_FLAG(x) 	Rte_Read_rp_SR_PowerCdd_AVP_LVSD0Flag(x)
#define MGRDIAGCDD_GET_HVSD0_FLAG(data) Rte_Read_rp_SR_PowerCdd_AVP_HVSD0Flag(data)
#define MGRDIAGCDD_GET_POWER_MODE(x) 	Rte_Read_rp_SR_PowerData_PwrMode(x)

#define MGRDIAGCDD_DIDs_COUNT 24
#define MGRDIAGCDD_RIDs_COUNT 5
#endif

/*Enable only required services*/
#define SEPERATE_DCMEXT_INTERFACE_FOR_DID_RID
/*
#define PwmConf_PwmChannel_TTDRV  				((uint8)1u)
#define PwmConf_PwmChannel_RIGHT_LCD_BL  		((uint8)2u)
#define PwmConf_PwmChannel_LEFT_LCD_BL  		((uint8)(3u))
#define PwmConf_PwmChannel_ILL_PWM1  			((uint8)(4u))
#define PwmConf_PwmChannel_BKL_DRV_DIM 			((uint8)(0x5U))
*/
#ifdef SEPERATE_DCMEXT_INTERFACE_FOR_DID_RID
/*Can be removed once enums are generated via RTE*/
#  ifndef eRead
#   define eRead (0U)
#  endif

#  ifndef eWrite
#   define eWrite (1U)
#  endif

#  ifndef eSTA
#   define eSTA (2U)
#  endif

#  ifndef eRTCtrl
#   define eRTCtrl (3U)
#  endif

#  ifndef eCheckConditions
#   define eCheckConditions (4U)
#  endif

#  ifndef eRoutineStart
#   define eRoutineStart (0U)
#  endif

#  ifndef eRoutineStop
#   define eRoutineStop (1U)
#  endif

#  ifndef eRoutineResults
#   define eRoutineResults (2U)
#  endif

#endif
/* Tracediag Macros*/
#define TRACEDIAG_MODULE_ENABLE
#ifdef TRACEDIAG_MODULE_ENABLE
#define TRACEDIAG_SERVICE_1   
#define TRACEDIAG_SERVICE_2
#define TRACEDIAG_SERVICE_3
#define TRACEDIAG_SERVICE_4
#define TRACEDIAG_SERVICE_5
#define TRACEDIAG_SERVICE_6
#define TRACEDIAG_SERVICE_7
#define TRACEDIAG_SERVICE_8
#define TRACEDIAG_SERVICE_9 

/*
#define TRACEDIAG_SERVICE_10
#define TRACEDIAG_SERVICE_11
#define TRACEDIAG_SERVICE_12
#define TRACEDIAG_SERVICE_13
#define TRACEDIAG_SERVICE_14
#define TRACEDIAG_SERVICE_15
#define TRACEDIAG_SERVICE_16
#define TRACEDIAG_SERVICE_18
#define TRACEDIAG_SERVICE_19

#define TRACEDIAG_SERVICE_20
#define TRACEDIAG_SERVICE_17
#define TRACEDIAG_TRACEBYTES_STATION_1
#define TRACEDIAG_TRACEBYTES_STATION_2
#define TRACEDIAG_TRACEBYTES_STATION_3
#define TRACEDIAG_TRACEBYTES_STATION_4
#define TRACEDIAG_TRACEBYTES_STATION_5
#define TRACEDIAG_RESERVEDBYTES
#define TRACEDIAG_TRACEABILITY_BYTES
*/
#endif

//#define SECUREDIAG_MODULE_ENABLE

#define OSCDIAG_MODULE_ENABLE
#ifdef OSCDIAG_MODULE_ENABLE
//#define OSCDIAG_QUARTZ_CORRECTION
//#define OSCDIAG_QUARTZ_CONTROL
//#define OSCDIAG_CLOCKVALUE_ENABLE
#endif

#define IOCTRLDIAG_MODULE_ENABLE
#ifdef IOCTRLDIAG_MODULE_ENABLE
#define IOCONTOLRD_ADC_READ_GROUP 1
#define IO_BUTTON_READ_ENABLE
#define IOCTRLRD_ANALOG_DIAG
//#define IOCONTOLRD_DOUT_CONTROL_ENABLE
#define IOCONTOLRD_DOUT_CONTROL_PORT_ENABLE
#define IOCONTROlRD_PWM_FREQUENCY_CONTROL_ENABLE 1
// #define IOCONTOLRD_TFT_CONTINUITY_LOOP_CHECK
// #define IOCONTROlRD_PWM_DIMMING_ENABLE

// #define IOCTRLRD_ANALOG_DIAG_BY_UNIT
// #define IOCONTOLRD_INTERNAL_DIGITAL_SIGNAL_CONTROL_ENABLE
// #define IOCONTOLRD_LED_CONTROL_DUTY_ENABLE

/*
#define IO_SELFCHECK_ENABLE
#define IOCONTOLRD_SPEAKER_TEST_ENABLE
#define IOCONTROlRD_PWM_OUTPUTCONTROL_ENABLE
#define IOCTRL_ANALOG_READ_ALL_ADC

#define IOCONTOLRD_ECTLED_CONTROL_DUTY_ENABLE
#define IOCONTOLRD_FUELLED_CONTROL_DUTY_ENABLE
#define IOCONTOLRD_TACHOLED_CONTROL_DUTY_ENABLE
#define IOCONTROlRD_TACHO_ILLUMINATION_ENABLE
#define IOCONTROlRD_FUELECT_ILLUMINATION_ENABLE
#define IOCONTROlRD_DISPLAY_ILLUMINATION_ENABLE
#define IO_DOUT_WRITE_ENABLE
#define IOCTRLRD_PWM_INPUT_CHECK
#define IOCTRL_FUEL_LEVEL_SENDER_READ_ENABLE
#define IOCTRL_FUEL_SENDER_READ_ENABLE
#define IOCTRL_FILTER_BYPASS_MODE_ENABLE
#define IOCONTOLRD_DOUT_CONTROL_ENABLE
#define IOCTRL_ANALOG_READ_ADC_SINGLE_CH

#define DUTY_COTROL_WITH_ONE_CHANNEL   1
#define	IOCTRLRD_SINGLE_CHANNEL_DIM_CTRL  
#define IOCONTROlRD_PWM_FREQUENCY_CONTROL_ENABLE 1
#define IOCONTOLRD_DOUT_CONTROL_ENABLE 1
#define IO_INTERNAL_DIGITAL_SIGNAL_READ_ENABLE  1
#define IOCONTOLRD_BUZZER_TET_ENABLE 1
#define IOCTRLRD_FUEL_INPUT_READING_BY_UNIT_WCalib
#define IOCTRLRD_FUEL_INPUT_READING_THREE_POINT_CALIB 1
#define IOCTRlRD_ALALOGIC_SIGNAL_CTRL 1
#define IOCONTOLRD_ADC_READ_SAFE_ENABLE 1
#define LED_CONTROl_WITH_DUTY   1
*/
#endif
#define ETHERNET_DIAG_MODULE_ENABLE
#define ETHERNET_TEST_MODE_IOCTRL
#define FAULTINJECTIONSAFETY

/*# define MOTORDIAG_SERVICE	*/
# ifdef MOTORDIAG_SERVICE
# define ORDER_IN_USTEPS_OR_DEG
# define ORDER_IN_VEHICLE_UNIT
# define HIGH_CALIBRATION_CONTROL
# define HIGH_IMPEDANCE
# define LOW_TORQUE
# define JUMP_IN_USTEPS
# define READ_MOTOR_POSITION
# define POINTER_PLACEMENT_ROUTINE
# define POINTER_POSITION_READ
# define POINTER_AUTHOMODE_READ
# define SFD_ROC_ROUTINE
# define MMOS_CALIB_READ
# define ZERO_POINT_POSITION_READ
# define SWZERO_SCALE_PARAMETERS
# define SPEEDO_MAPTABLE_X
# define SPEEDO_MAPTABLE_Y
# define SPEEDO_CRTNTABLE_Y
# define SPEEDO_CRTNTABLE_X
# define TACHO_MAPTABLE_X
# define TACHO_MAPTABLE_Y
# define TACHO_CRTNTABLE_X
# define TACHO_CRTNTABLE_Y
# define FUEL_MAPTABLE_X
# define FUEL_MAPTABLE_Y
# define FUEL_CRTNTABLE_X
# define FUEL_CRTNTABLE_Y
# define ENGTEMP_MAPTABLE_X
# define ENGTEMP_MAPTABLE_Y
# define ENGTEMP_CRTNTABLE_X
# define ENGTEMP_CRTNTABLE_Y
# define OILPRS_MAPTABLE_Y
# define OILPRS_MAPTABLE_X
# define OILPRS_CRTNTABLE_Y
# define OILPRS_CRTNTABLE_X
# define TRANSTEMP_MAPTABLE_Y
# define TRANSTEMP_MAPTABLE_X 
# define TRANSTEMP_CRTNTABLE_Y
# define TRANSTEMP_CRTNTABLE_X
# define CONTINOUS_POINTER_MOVEMENT
# define SELFTEST_GAUGES
#endif
//#define COMDIAG_MODULE_ENABLE
//#define COMM_BUS_VERIFICATION_TEST
//#ifndef COMMCONTROLDIAG_MCANTEST_ROUTINE
//#define COMMCONTROLDIAG_MCANTEST_ROUTINE
//#endif

//#ifndef COMMCONTROLDIAG_CXPITEST_ROUTINE
//#define COMMCONTROLDIAG_CXPITEST_ROUTINE
//#endif

/*======================================================================================================================
** T Y P E  D E F I N I T I O N S
**======================================================================================================================*/
# define Rte_TypeDef_tGenMdlDiagResp
typedef uint8 tGenMdlDiagResp;

#ifdef MEET_GIP_ENABLED
typedef enum 
{
    eGIP_InitiateRequest,
    eGIP_WaitForResponse
}GIPDataRquestState;
#ifdef MEET_GIP_SEPERATE_REQ_FOR_DID_DR_IO

typedef uint8 MeetDiagReqBufferType[255];
typedef struct
{
  uint16 ServiceId;
  uint8 ActionP;
  uint8 LengthP;
  MeetDiagReqBufferType DataP;
} DiagReqType;

typedef uint8 DiagResultType;
typedef uint8 DiagRespBufferType[255];

typedef struct
{
  UInt8 Length;
  DiagRespBufferType DiagRespBuffer;
} DiagRespType;

#define DiagActionType_ReadWrite		1U
#define DiagActionType_RoutineCtrl		2U
#define DiagActionType_IOCtrl			3U

#define UCL_Diag_Data_Buffer_Size 			255u
#endif
#endif

#ifdef PRECONDITION_CHECK_REQUIRED
typedef struct
{
    uint16             ID;
    boolean            LVSDf                : 1; /* 1 = check, != N/A */
    boolean            HVSDf                : 1; /* 1 = check, != N/A */
    uint8              pwrMode              : 4;
	boolean 		   bMeetmode_flag;			/*TRUE - DID/DR supports only in MeetMode; FALSE - DID/DR supports outside MeetMode too*/
}tsPreCheckStruct;
#endif

/*Should be removed once enum is generated via RTE*/
#  ifndef eDcmExtAction_Read
#   define eDcmExtAction_Read (0U)
#  endif

#  ifndef eDcmExtAction_Write
#   define eDcmExtAction_Write (1U)
#  endif

#  ifndef eDcmExtAction_IOCtrl
#   define eDcmExtAction_IOCtrl (2U)
#  endif

#  ifndef eDcmExtAction_RetCtrlEcu
#   define eDcmExtAction_RetCtrlEcu (3U)
#  endif

#  ifndef eDcmExtAction_RoutineStart
#   define eDcmExtAction_RoutineStart (4U)
#  endif

#  ifndef eDcmExtAction_RoutineStop
#   define eDcmExtAction_RoutineStop (5U)
#  endif

#  ifndef eDcmExtAction_RoutineResult
#   define eDcmExtAction_RoutineResult (6U)
#  endif

#  ifndef eDcmExtAction_CheckConditions
#   define eDcmExtAction_CheckConditions (7U)
#  endif

#  ifndef eDcmExtAction_Reset
#   define eDcmExtAction_Reset (8U)
#  endif


#define MGRDIAGCDD_READ_ACTION 		  	    (eDcmExtAction_Read)
#define MGRDIAGCDD_WRITE_ACTION 	 		(eDcmExtAction_Write)

#define MGRDIAGCDD_IOC_STA_ACTION	  	    (eDcmExtAction_IOCtrl)
#define MGRDIAGCDD_IOC_RCTE_ACTION	   	 	(eDcmExtAction_RetCtrlEcu)

#define MGRDIAGCDD_ROC_START_ACTION	   		(eDcmExtAction_RoutineStart) 
#define MGRDIAGCDD_ROC_STOP_ACTION	   	 	(eDcmExtAction_RoutineStop) 
#define MGRDIAGCDD_ROC_RESULTS_ACTION		(eDcmExtAction_RoutineResult) 
#define MGRDIAGCDD_RESET_ACTION	       		(eDcmExtAction_Reset) 
#define MGRDIAGCDD_CHECKCONDITIONS_ACTION 	(eDcmExtAction_CheckConditions)	
/*=====================================================================================================================
*  C O N S T A N T    A N D   V A R I A B L E S    D E C L A R A T I O N S
**===================================================================================================================*/
/* Read DID table*/

 #define MGRDIAGCDD_READ_DID_LIST \
static const MGRDIAGCDD_DID_bundle_t Meet_Cdd_Read_DID_Table[MGRDIAGCDD_READ_DID_COUNT]= \
{                             \
	{0xFD00, &Read_Diag_F100},\
	{0xFD01, &Read_Diag_F181},\
	{0xFD02, &Read_Diag_F18E},\
	{0xFD04, &Read_Diag_F187},\
	{0xFD05, &Read_Diag_F18C},\
	{0xFD07, &Read_Diag_F188},\
	{0xFD08, &Read_Diag_F18B},\
	{0xFD45, &Read_Diag_F182},\
	{0xFD60, &Read_Diag_FA4C},\
	{0xFD6B, &Read_Diag_F190},\
	{0xFE30, &Read_Diag_FA16},\
};

/* Write DID table*/
#define MGRDIAGCDD_WRITE_DID_LIST \
static const MGRDIAGCDD_DID_bundle_t Meet_Cdd_Write_DID_Table[MGRDIAGCDD_WRITE_DID_COUNT]= \
{							   \
	{0xF781, &Write_Diag_F781},\
	{0xFD00, &Write_Diag_F100},\
	{0xFD01, &Write_Diag_F181},\
	{0xFD02, &Write_Diag_F18E},\
	{0xFD04, &Write_Diag_F187},\
	{0xFD05, &Write_Diag_F18C},\
	{0xFD07, &Write_Diag_F188},\
	{0xFD08, &Write_Diag_F18B},\
	{0xFD45, &Write_Diag_F182},\
	{0xFD60, &Write_Diag_FA4C},\
	{0xFD6B, &Write_Diag_F190},\
};

/* IoCtrl STA DID table*/
 #define MGRDIAGCDD_IOCTL_STA_DID_LIST \
static const MGRDIAGCDD_DID_bundle_t Meet_Cdd_IOC_STA_DID_Table[MGRDIAGCDD_IOCTL_STA_DID_COUNT]= \
{                              		\
	{0xFE31, &IOCTL_STA_Diag_FE31},\
	{0xFE32 ,&IOCTL_STA_Diag_FD17},\
	{0xFE35, &IOCTL_STA_Diag_FD0D},\
};


 #define MGRDIAGCDD_IOCTL_RCTE_DID_LIST \
static const MGRDIAGCDD_DID_bundle_t Meet_Cdd_IOC_RCTE_DID_Table[MGRDIAGCDD_IOCTL_RCTE_DID_COUNT]= \
{                               	 \
	{0xFE31, &IOCTL_RCTE_Diag_FE31},\
	{0xFE32 ,&IOCTL_RCTE_Diag_FD17},\
	{0xFE35, &IOCTL_RCTE_Diag_FD0D},\
};

/* Routine Control Start DID table */
 #define MGRDIAGCDD_RC_START_DID_LIST \
static const MGRDIAGCDD_DID_bundle_t Meet_Cdd_ROC_START_DID_Table[MGRDIAGCDD_RC_START_DID_COUNT]= \
{                             	   \
	{0xFE34, &RC_START_Diag_F11F},\
	{0xFE3B, &RC_START_Diag_FE3B},\
	{0xFE42, &RC_START_Diag_FE42},\
};



/* Routine Control Stop DID table */
 #define MGRDIAGCDD_RC_STOP_DID_LIST \
static const MGRDIAGCDD_DID_bundle_t Meet_Cdd_ROC_STOP_DID_Table[MGRDIAGCDD_RC_STOP_DID_COUNT]= \
{								  \
	{0xFE3B, &RC_STOP_Diag_FE3B},\
	{0xFE34, &RC_STOP_Diag_F11F},\
};


/* Routine Control Results DID table */
 #define MGRDIAGCDD_RC_RESULTS_DID_LIST \
static const MGRDIAGCDD_DID_bundle_t Meet_Cdd_ROC_RESULTS_DID_Table[MGRDIAGCDD_RC_RESULTS_DID_COUNT]= \
{									 \
	{0xFE34, &RC_RESULTS_Diag_F11F},\
	{0xFE42, &RC_RESULTS_Diag_FE42},\
};


#ifdef PRECONDITION_CHECK_REQUIRED
/*configure all DIDs(read/write/ioctrl) under DidPreCheckTable without repeating*/
static const tsPreCheckStruct DidPreCheckTable[MGRDIAGCDD_DIDs_COUNT] =
{
	/*To Do: once confirm this flag w.r.t to S2.8 DNG. since currently mapped by p702 req*/
	/*  ID,    , LVSDf    , HVSDf    , pwrMode   , MeetMode    */
    {0xD100, FLAGZERO_B , FLAGZERO_B , ALLPWRMODE, FALSE},
	{0x61B7, FLAGONE_B , FLAGONE_B , RUNPWRMODE, FALSE},
	{0x4190, FLAGONE_B , FLAGONE_B , RUNPWRMODE, FALSE},
	{0xF113, FLAGONE_B , FLAGONE_B , RUNPWRMODE, FALSE},
	{0xF120, FLAGONE_B , FLAGONE_B , RUNPWRMODE, FALSE},
	{0xF163, FLAGONE_B , FLAGONE_B , RUNPWRMODE, FALSE},
	{0xF188, FLAGONE_B , FLAGONE_B , RUNPWRMODE, FALSE},
	{0xF18C, FLAGONE_B , FLAGONE_B , RUNPWRMODE, FALSE},
	{0xF442, FLAGZERO_B , FLAGZERO_B , RUNPWRMODE, FALSE},
	{0xFD27, FLAGONE_B , FLAGONE_B , RUNPWRMODE, FALSE},
	{0xFE00, FLAGONE_B , FLAGONE_B , RUNPWRMODE, FALSE},
	{0xFE03, FLAGONE_B , FLAGONE_B , RUNPWRMODE, FALSE},
	{0xFE0A, FLAGONE_B , FLAGONE_B , RUNPWRMODE, FALSE},
	{0xFE0E, FLAGONE_B , FLAGONE_B , RUNPWRMODE, FALSE},
	{0xFE40, FLAGONE_B , FLAGONE_B , RUNPWRMODE, TRUE},
	{0xFE70, FLAGONE_B , FLAGONE_B , RUNPWRMODE, TRUE},
	{0xFEF3, FLAGONE_B , FLAGONE_B , RUNPWRMODE, TRUE},
	{0xFEF4, FLAGONE_B , FLAGONE_B , RUNPWRMODE, TRUE},
	{0xFD44, FLAGONE_B , FLAGONE_B , RUNPWRMODE, TRUE},
	{0xFD45, FLAGONE_B , FLAGONE_B , RUNPWRMODE, FALSE},
	{0xFD46, FLAGONE_B , FLAGONE_B , RUNPWRMODE, TRUE},
	{0xF17F, FLAGZERO_B , FLAGZERO_B , ALLPWRMODE, FALSE},
	{0xD03D, FLAGONE_B , FLAGONE_B , RUNPWRMODE, FALSE},
	{0xFE3A, FLAGONE_B , FLAGONE_B , RUNPWRMODE, FALSE},
};
/*configure all routine alone under RidPreCheckTable */
static const tsPreCheckStruct RidPreCheckTable[MGRDIAGCDD_RIDs_COUNT] =
{
	/*  ID,    , LVSDf    , HVSDf    , pwrMode      */
    {0xFE22, FLAGONE_B , FLAGONE_B , RUNPWRMODE, TRUE},
	{0xFE30, FLAGONE_B , FLAGONE_B , RUNPWRMODE, TRUE},
	{0xFE42, FLAGONE_B , FLAGONE_B , RUNPWRMODE, FALSE},
	{0xFE68, FLAGONE_B , FLAGONE_B , RUNPWRMODE, FALSE},
	{0xFD87, FLAGONE_B , FLAGONE_B , RUNPWRMODE, FALSE},	
	{0xFE0B, FLAGONE_B , FLAGONE_B , ALLPWRMODE, TRUE},
	{0xFE0C, FLAGONE_B , FLAGONE_B , ALLPWRMODE, TRUE},
};
#endif
/*=====================================================================================================================
*   P U B L I C
**=====================================================================================================================*/

#ifdef SEPERATE_DCMEXT_INTERFACE_FOR_DID_RID
Std_ReturnType Mgrdiagcdd_MapDID_DcmExtAction(EDcmExtAction *Action, teDIDOperation eOperation);
Std_ReturnType Mgrdiagcdd_MapRID_DcmExtAction(EDcmExtAction *Action, teDIDOperation eOperation);
#endif

#ifdef READ_INTERFACE_FOR_APPL_COMPONENTS
void Meet_Mgrdiagcdd_Update_GIP_DID_Data(uint8* UpdateStatus);
FUNC(Std_ReturnType, MeetCdd_CODE) CMeet_Mgrdiagcdd_Update_GIP_DID_Data(P2VAR(UInt8, AUTOMATIC, RTE_MEETCDD_APPL_VAR) Data, P2VAR(UInt32, AUTOMATIC, RTE_MEETCDD_APPL_VAR) DID);
Std_ReturnType Meet_Mgrdiagcdd_Get_GIP_DID_Data(uint8* Data, uint32* DID);
boolean IsGIPReadDID(uint32 *DID);
#endif

#ifdef PRECONDITION_CHECK_REQUIRED
///@brief   Validation of High and Low voltage flags if available for the selected DID.
boolean Mgrdiagcdd_VoltFlagValidation(boolean fp_bXVSDf, boolean fp_bCVSDf);
boolean Mgrdiagcdd_DID_PreConditionCheck(uint16 DIDNum, uint8 *pNrc);
boolean Mgrdiagcdd_RID_PreConditionCheck(uint16 RIDNum,uint8 *pNrc);
uint8 Mgrdiagcdd_PwrModeMod(tPwrModeState fp_tCurrentState);
uint8 Mgrdiagcdd_MapDcmExtAction(tPwrModeState fp_tCurrentState);
boolean Mgrdiagcdd_ConfigMEET(void);
#endif

#ifdef NVMACCESSBYADDRESSRCENABLE
Std_ReturnType RC_START_Diag_F0FA(uint8 * Data,uint8* Length);
Std_ReturnType RC_RESULTS_Diag_F0FA(uint8 * Data,uint8* Length);
Std_ReturnType RC_START_Diag_F0FB(uint8 * Data,uint8* Length);
Std_ReturnType RC_RESULTS_Diag_F0FB(uint8 * Data,uint8* Length);
#endif

#ifdef FAULTINJECTIONSAFETY
Std_ReturnType Write_Diag_F781(uint8* Data,const uint8* Length);
Std_ReturnType FITDID_FaultInjectionAction(uint8 *Data, uint8 *ErrorCode);
#endif
// Read and Write Services
#ifdef TRACEDIAG_SERVICE_1
Std_ReturnType Read_Diag_F100(uint8* Data,const uint8* Length);
Std_ReturnType Write_Diag_F100(uint8* Data,uint8* Length);
#endif

#ifdef TRACEDIAG_SERVICE_2
Std_ReturnType Read_Diag_F181(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_F181(uint8* Data,uint8* Length);
#endif

#ifdef TRACEDIAG_SERVICE_3
Std_ReturnType Read_Diag_F182(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_F182(uint8* Data,uint8* Length);
#endif

#ifdef TRACEDIAG_SERVICE_4
Std_ReturnType Read_Diag_F187(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_F187(uint8* Data,uint8* Length);
#endif

#ifdef TRACEDIAG_SERVICE_5
Std_ReturnType Read_Diag_F188(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_F188(uint8* Data,uint8* Length);
#endif

#ifdef TRACEDIAG_SERVICE_6
Std_ReturnType Read_Diag_F18B(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_F18B(uint8* Data,uint8* Length);
#endif

#ifdef TRACEDIAG_SERVICE_7
Std_ReturnType Read_Diag_F18C(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_F18C(uint8* Data,uint8* Length);
#endif

#ifdef TRACEDIAG_SERVICE_8
Std_ReturnType Read_Diag_F18E(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_F18E(uint8* Data,uint8* Length);
#endif

#ifdef TRACEDIAG_SERVICE_9
Std_ReturnType Read_Diag_F190(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_F190(uint8* Data,uint8* Length);
#endif

#ifdef TRACEDIAG_SERVICE_10
Std_ReturnType Read_Diag_F191(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_F191(uint8* Data,uint8* Length);
#endif

#ifdef TRACEDIAG_SERVICE_11
Std_ReturnType Read_Diag_F199(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_F199(uint8* Data,uint8* Length);
#endif

#ifdef TRACEDIAG_SERVICE_12
Std_ReturnType Read_Diag_F19B(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_F19B(uint8* Data,uint8* Length);
#endif

#ifdef TRACEDIAG_SERVICE_13
Std_ReturnType Read_Diag_FA03(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_FA03(uint8* Data,uint8* Length);
#endif

#ifdef TRACEDIAG_SERVICE_14
Std_ReturnType Read_Diag_FDBB(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_FDBB(uint8* Data,uint8* Length);
#endif

#ifdef TRACEDIAG_SERVICE_15
Std_ReturnType Read_Diag_FE47(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_FE47(uint8* Data,uint8* Length);
#endif

#ifdef TRACEDIAG_SERVICE_16
Std_ReturnType Read_Diag_F195(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_F195(uint8* Data,uint8* Length);
#endif

#ifdef TRACEDIAG_SERVICE_19
Std_ReturnType Read_Diag_FE4D(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_FE4D(uint8* Data,uint8* Length);
#endif

#ifdef TRACEDIAG_SERVICE_18
Std_ReturnType Read_Diag_FE61(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_FE61(uint8* Data,uint8* Length);
#endif

#ifdef TRACEDIAG_SERVICE_17
Std_ReturnType Read_Diag_F195(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_F195(uint8* Data,uint8* Length);
#endif

#ifdef TRACEDIAG_SERVICE_20
Std_ReturnType Read_Diag_F17F(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_F17F(uint8* Data,uint8* Length);
#endif

#ifdef TRACEDIAG_SERVICE_21
Std_ReturnType Read_Diag_FD08(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_FD08(uint8* Data,uint8* Length);
#endif

#ifdef TRACEDIAG_SERVICE_22
Std_ReturnType Read_Diag_FD06(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_FD06(uint8* Data,uint8* Length);
#endif

#ifdef TRACEDIAG_SERVICE_23
Std_ReturnType Read_Diag_FD0A(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_FD0A(uint8* Data,uint8* Length);
#endif

#ifdef IOCTRL_FUEL_LEVEL_SENDER_READ_ENABLE
Std_ReturnType Read_Diag_4190(uint8* Data,uint8* Length);
#endif

#ifdef IOCTRL_FUEL_SENDER_READ_ENABLE
Std_ReturnType Read_Diag_61B7(uint8* Data,uint8* Length);
#endif

#ifdef IOCTRL_FILTER_BYPASS_MODE_ENABLE
Std_ReturnType Read_Diag_FE70(uint8* Data,uint8* Length);
Std_ReturnType IOCTL_STA_Diag_FE70(uint8* Data,uint8* Length);
Std_ReturnType IOCTL_RCTE_Diag_FE70(uint8* Data,uint8* Length);
#endif

#ifdef LOWQCURRENTENABLE
Std_ReturnType IOCTL_STA_Diag_FE3A(uint8* Data,uint8* Length);
Std_ReturnType IOCTL_RCTE_Diag_FE3A(uint8* Data,uint8* Length);
#endif

#ifdef TRACEDIAG_RESERVEDBYTES
Std_ReturnType Read_Diag_FA09(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_FA09(uint8* Data,uint8* Length);
#endif

#ifdef TRACEDIAG_TRACEBYTES_STATION_1
Std_ReturnType Read_Diag_FA1B(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_FA1B(uint8* Data,uint8* Length);
#endif

#ifdef TRACEDIAG_TRACEBYTES_STATION_2
Std_ReturnType Read_Diag_FA1C(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_FA1C(uint8* Data,uint8* Length);
#endif

#ifdef TRACEDIAG_TRACEBYTES_STATION_3
Std_ReturnType Read_Diag_FA1D(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_FA1D(uint8* Data,uint8* Length);
#endif

#ifdef TRACEDIAG_TRACEBYTES_STATION_4
Std_ReturnType Read_Diag_FA1E(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_FA1E(uint8* Data,uint8* Length);
#endif

#ifdef TRACEDIAG_TRACEBYTES_STATION_5
Std_ReturnType Read_Diag_FD4D(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_FD4D(uint8* Data,uint8* Length);
#endif
#ifdef TRACEDIAG_PCB_VISTEON_PART_NO_PCB_ID1
Std_ReturnType Read_Diag_FA80(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_FA80(uint8* Data,uint8* Length);
#endif

#ifdef TRACEDIAG_PCB_VISTEON_PART_NO_PCB_ID2
Std_ReturnType Read_Diag_FA81(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_FA81(uint8* Data,uint8* Length);
#endif

#ifdef TRACEDIAG_PCB_VISTEON_PART_NO_PCB_ID3
Std_ReturnType Read_Diag_FA82(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_FA82(uint8* Data,uint8* Length);
#endif

#ifdef TRACEDIAG_PCB_VISTEON_PART_NO_PCB_ID4
Std_ReturnType Read_Diag_FA83(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_FA83(uint8* Data,uint8* Length);
#endif

#ifdef TRACEDIAG_SERIAL_NO_PCB_ID1
Std_ReturnType Read_Diag_FA84(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_FA84(uint8* Data,uint8* Length);
#endif

#ifdef TRACEDIAG_SERIAL_NO_PCB_ID1
Std_ReturnType Read_Diag_FA85(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_FA85(uint8* Data,uint8* Length);
#endif

#ifdef TRACEDIAG_SERIAL_NO_PCB_ID3
Std_ReturnType Read_Diag_FA86(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_FA86(uint8* Data,uint8* Length);
#endif

#ifdef TRACEDIAG_SERIAL_NO_PCB_ID4
Std_ReturnType Read_Diag_FA87(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_FA87(uint8* Data,uint8* Length);
#endif

#ifdef TRACEDIAG_CUSTOMER_HW_REFERENCE
Std_ReturnType Read_Diag_FA49(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_FA49(uint8* Data,uint8* Length);
#endif

#ifdef TRACEDIAG_TRACEABILITY_BYTES
Std_ReturnType Read_Diag_FD01(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_FD01(uint8* Data,uint8* Length);
#endif

// OSC diag services
#ifdef OSCDIAG_QUARTZ_CORRECTION
Std_ReturnType Read_Diag_FA10(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_FA10(uint8* Data,uint8* Length);
#endif

#ifdef OSCDIAG_QUARTZ_CONTROL
Std_ReturnType IOCTL_STA_Diag_FD06(uint8 * Data,uint8* Length);
Std_ReturnType IOCTL_RCTE_Diag_FD06(uint8 * Data,uint8* Length);
#endif

// IOCalib services
#ifdef IOCALIBDIAG_RTC_CALIBRATION
Std_ReturnType IOCTL_STA_Diag_FD0F(uint8 * Data,uint8* Length);
Std_ReturnType IOCTL_RCTE_Diag_FD0F(uint8 * Data,uint8* Length);
#endif

#ifdef ANALOGMEASCALIBFUELLVLENABLE
Std_ReturnType Read_Diag_FA30(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_FA30(uint8* Data,uint8* Length);
#endif

#ifdef ANALOGMEASCALIBOILLVLENABLE
Std_ReturnType Read_Diag_FA31(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_FA31(uint8* Data,uint8* Length);
#endif

#ifdef LEFTSWTBACKLIGHTENABLE
Std_ReturnType Read_Diag_FA51(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_FA51(uint8* Data,uint8* Length);
#endif

#ifdef RIGHTSWTBACKLIGHTENABLE
Std_ReturnType Read_Diag_FA52(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_FA52(uint8* Data,uint8* Length);
#endif

// #ifdef TACHOSCALEILLUMNENABLE
// Std_ReturnType Read_Diag_FA53(uint8* Data,uint8* Length);
// Std_ReturnType Write_Diag_FA53(uint8* Data,uint8* Length);
// #endif

#ifdef FUELTEMPSCALEILLUMNENABLE
Std_ReturnType Read_Diag_FA54(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_FA54(uint8* Data,uint8* Length);
#endif

#ifdef TACHOPTRILLUMNENABLE
Std_ReturnType Read_Diag_FA55(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_FA55(uint8* Data,uint8* Length);
#endif

#ifdef TEMPPTRILLUMNENABLE
Std_ReturnType Read_Diag_FA56(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_FA56(uint8* Data,uint8* Length);
#endif

#ifdef FUELPTRILLUMNENABLE
Std_ReturnType Read_Diag_FA57(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_FA57(uint8* Data,uint8* Length);
#endif

#ifdef FUEL_SENDER_CALIBRATION_TABLE
Std_ReturnType Read_Diag_FD09(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_FD09(uint8* Data,uint8* Length);
#endif

#ifdef IOCALIBSOUNDCHANNELVOLUME
Std_ReturnType Read_Diag_FE04(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_FE04(uint8* Data,uint8* Length);
#endif

#ifdef SOUNDCHANNELVOLUMECONTROL
Std_ReturnType Write_Diag_FE04(uint8* Data,uint8* Length);
#endif

#ifdef IOCONTOLRD_PLAY_TONE_CONTROL
Std_ReturnType RC_START_Diag_FE05(uint8 * Data,uint8* Length);
#endif

#ifdef IOCALIBSOUNDMIXEROUTPUTVOLUME
Std_ReturnType Read_Diag_FE09(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_FE09(uint8* Data,uint8* Length);
#endif

// Display services

#ifdef DISPLAYXYPARAMETERENABLE
Std_ReturnType Read_Diag_FA50(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_FA50(uint8* Data,uint8* Length);
#endif

#ifdef TFTFULLCOLORCTRLENABLE
Std_ReturnType IOCTL_STA_Diag_FD0E(uint8 * Data,uint8* Length);
Std_ReturnType IOCTL_RCTE_Diag_FD0E(uint8 * Data,uint8* Length);
#endif

#ifdef TFTONEDOTCTRLENABLE
Std_ReturnType IOCTL_STA_Diag_FD0F(uint8 * Data,uint8* Length);
Std_ReturnType IOCTL_RCTE_Diag_FD0F(uint8 * Data,uint8* Length);
#endif

#ifdef TFTXYSHIFTCTRLENABLE
Std_ReturnType IOCTL_STA_Diag_FD10(uint8 * Data,uint8* Length);
Std_ReturnType IOCTL_RCTE_Diag_FD10(uint8 * Data,uint8* Length);
#endif

#ifdef TFTADJCHESSPTRNCTRLENABLE
Std_ReturnType IOCTL_STA_Diag_FD11(uint8 * Data,uint8* Length);
Std_ReturnType IOCTL_RCTE_Diag_FD11(uint8 * Data,uint8* Length);
#endif

#ifdef DISPLAYSPLSEQEXEENABLE
Std_ReturnType RC_START_Diag_F116(uint8 * Data,uint8* Length);
Std_ReturnType RC_STOP_Diag_F116(uint8 * Data,uint8* Length);
Std_ReturnType RC_RESULTS_Diag_F116(uint8 * Data,uint8* Length);
#endif

#ifdef DISPLAY_LCD_SEGMENT_CTRL_ENABLE
Std_ReturnType IOCTL_STA_Diag_FD15(uint8 * Data,uint8* Length);
Std_ReturnType IOCTL_RCTE_Diag_FD15(uint8 * Data,uint8* Length);
#endif

#ifdef	LCD_LED_ALL_LIT
Std_ReturnType RC_START_Diag_F001(uint8 * Data,uint8* Length);
Std_ReturnType RC_STOP_Diag_F001(uint8 * Data,uint8* Length);
#endif

#ifdef IOCONTOLRD_LED_CONTROL_DUTY_ENABLE
Std_ReturnType IOCTL_STA_Diag_FE0D(uint8 * Data,uint8* Length);
Std_ReturnType IOCTL_RCTE_Diag_FE0D(uint8 * Data,uint8* Length);
#endif

#ifdef IOCONTOLRD_ECTLED_CONTROL_DUTY_ENABLE
Std_ReturnType IOCTL_STA_Diag_FEF4(uint8 * Data,uint8* Length);
Std_ReturnType IOCTL_RCTE_Diag_FEF4(uint8 * Data,uint8* Length);
#endif

#ifdef IOCONTOLRD_FUELLED_CONTROL_DUTY_ENABLE
Std_ReturnType IOCTL_STA_Diag_FEF5(uint8 * Data,uint8* Length);
Std_ReturnType IOCTL_RCTE_Diag_FEF5(uint8 * Data,uint8* Length);
#endif

#ifdef IOCONTOLRD_TACHOLED_CONTROL_DUTY_ENABLE
Std_ReturnType IOCTL_STA_Diag_FEF6(uint8 * Data,uint8* Length);
Std_ReturnType IOCTL_RCTE_Diag_FEF6(uint8 * Data,uint8* Length);
#endif

#ifdef IOCONTROlRD_FUELECT_ILLUMINATION_ENABLE
Std_ReturnType IOCTL_STA_Diag_FE70(uint8 * Data,uint8* Length);
Std_ReturnType IOCTL_RCTE_Diag_FE70(uint8 * Data,uint8* Length);
#endif

#ifdef IOCONTROlRD_TACHO_ILLUMINATION_ENABLE
Std_ReturnType IOCTL_STA_Diag_FD26(uint8 * Data,uint8* Length);
Std_ReturnType IOCTL_RCTE_Diag_FD26(uint8 * Data,uint8* Length);
#endif

#ifdef IOCONTROlRD_DISPLAY_ILLUMINATION_ENABLE
Std_ReturnType IOCTL_STA_Diag_FD27(uint8 * Data,uint8* Length);
Std_ReturnType IOCTL_RCTE_Diag_FD27(uint8 * Data,uint8* Length);
#endif


#ifdef OSCDIAG_CLOCK_MONITORING
Std_ReturnType RC_START_Diag_FE0B(uint8 * Data,uint8* Length);
#endif

#ifdef DISPLAY_CONTENT_CHECK
Std_ReturnType RC_START_Diag_FE0C(uint8 * Data,uint8* Length);
#endif

#ifdef LOWQCURRENTENABLE
Std_ReturnType IOCTL_STA_Diag_FD5F(uint8 * Data,uint8* Length);
Std_ReturnType IOCTL_RCTE_Diag_FD5F(uint8 * Data,uint8* Length);
#endif

#ifdef TFTPATTERNCTRLENABLE
Std_ReturnType IOCTL_STA_Diag_FD0D(uint8 * Data,uint8* Length);
Std_ReturnType IOCTL_RCTE_Diag_FD0D(uint8 * Data,uint8* Length);
#endif

#ifdef TFT_VIDEOCHECK_ENABLE
Std_ReturnType IOCTL_STA_Diag_FD60(uint8 * Data,uint8* Length);
Std_ReturnType IOCTL_RCTE_Diag_FD60(uint8 * Data,uint8* Length);
#endif

#ifdef OSCDIAG_CLOCKVALUE_ENABLE
Std_ReturnType Read_Diag_FE07(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_FE07(uint8* Data,uint8* Length);
#endif

#ifdef IO_SELFCHECK_ENABLE
Std_ReturnType Read_Diag_FA37(uint8* Data,uint8* Length);
Std_ReturnType Read_Diag_FD15(uint8* Data,uint8* Length);
#endif

#ifdef DISPLAY_CONTENT_INTEGRITY_CHECK
Std_ReturnType RC_START_Diag_F109(uint8 * Data,uint8* Length);
Std_ReturnType RC_STOP_Diag_F109(uint8 * Data,uint8* Length);
Std_ReturnType RC_RESULTS_Diag_F109(uint8 * Data,uint8* Length);
#endif
// IOCntrlRd services
#ifdef IOCTRLRD_BKRND_BUTTON_CHECK
Std_ReturnType Read_Diag_FA11(uint8* Data,uint8* Length);
#endif

#ifdef IO_BUTTON_READ_ENABLE
Std_ReturnType Read_Diag_FA16(uint8* Data,const uint8* Length);
#endif

#ifdef IO_INTERNAL_DIGITAL_SIGNAL_READ_ENABLE
Std_ReturnType Read_Diag_FA39(uint8* Data,uint8* Length);
#endif

#ifdef IOCTRLRD_INTERANL_ANALOGIC_SIG_READ
Std_ReturnType Read_Diag_FA3A(uint8* Data,uint8* Length);
#endif

#ifdef IOCONTOLRD_INTERNAL_DIGITAL_SIGNAL_CONTROL_ENABLE
Std_ReturnType IOCTL_STA_Diag_FD10(uint8 * Data,uint8* Length);
Std_ReturnType IOCTL_RCTE_Diag_FD10(uint8 * Data,uint8* Length);
#endif
// IO Control Short term adjust	 and   IO control Return control ECU
#ifdef IOCONTOLRD_LED_CONTROL_DUTY_ENABLE
Std_ReturnType IOCTL_STA_Diag_FD11(uint8 * Data,uint8* Length);
Std_ReturnType IOCTL_RCTE_Diag_FD11(uint8 * Data,uint8* Length);
#endif

#ifdef IOCTRLRD_PWM_INPUT_CHECK
Std_ReturnType Read_Diag_FE04(uint8* Data,uint8* Length);
#endif

#ifdef IOCTRlRD_ALALOGIC_SIGNAL_CTRL
Std_ReturnType IOCTL_STA_Diag_FD12(uint8 * Data,uint8* Length);
Std_ReturnType IOCTL_RCTE_Diag_FD12(uint8 * Data,uint8* Length);
#endif

#ifdef IOCONTOLRD_DOUT_CONTROL_PORT_ENABLE
Std_ReturnType IOCTL_STA_Diag_FE31(uint8 * Data,uint8* Length);
Std_ReturnType IOCTL_RCTE_Diag_FE31(uint8 * Data,uint8* Length);
#endif
#ifdef IOCONTOLRD_DOUT_CONTROL_ENABLE
Std_ReturnType IOCTL_STA_Diag_FD14(uint8 * Data,uint8* Length);
Std_ReturnType IOCTL_RCTE_Diag_FD14(uint8 * Data,uint8* Length);
#endif

#ifdef IO_DOUT_WRITE_ENABLE
Std_ReturnType Write_Diag_FE10(uint8* Data,uint8* Length);
#endif

#ifdef IOCONTROlRD_PWM_OUTPUTCONTROL_ENABLE
Std_ReturnType IOCTL_STA_Diag_FD28(uint8 * Data,uint8* Length);
Std_ReturnType IOCTL_RCTE_Diag_FD28(uint8 * Data,uint8* Length);
#endif

#ifdef IOCONTROlRD_PWM_DIMMING_ENABLE  //This macro enabled for cfg file access only
Std_ReturnType IOCTL_STA_Diag_FD03(uint8 * Data,uint8* Length);
Std_ReturnType IOCTL_RCTE_Diag_FD03(uint8 * Data,uint8* Length);
#endif

#ifdef IOCONTROlRD_PWM_FREQUENCY_CONTROL_ENABLE
Std_ReturnType IOCTL_STA_Diag_FD17(uint8 * Data,const uint8* Length);
Std_ReturnType IOCTL_RCTE_Diag_FD17(const uint8 *Data, const uint8 *Length);
#endif

#ifdef IOCONTOLRD_SPEAKER_TEST_ENABLE
Std_ReturnType IOCTL_STA_Diag_FEF3(uint8 * Data,uint8* Length);
Std_ReturnType IOCTL_RCTE_Diag_FEF3(uint8 * Data,uint8* Length);
#endif

#ifdef IOCTRLRD_ANALOG_DIAG
Std_ReturnType RC_START_Diag_F11F(uint8 * Data, uint8* Length);
Std_ReturnType RC_STOP_Diag_F11F(uint8 * Data,const uint8* Length);
Std_ReturnType RC_RESULTS_Diag_F11F(uint8 * Data,uint8* Length);
#endif

#ifdef IOCTRLRD_ANALOG_DIAG_BY_UNIT
Std_ReturnType RC_START_Diag_F105(uint8 * Data,uint8* Length);
Std_ReturnType RC_STOP_Diag_F105(uint8 * Data,uint8* Length);
Std_ReturnType RC_RESULTS_Diag_F105(uint8 * Data,uint8* Length);
#endif

#ifdef AUTO_CONFIGURE_OR_VERIFY
Std_ReturnType RC_START_Diag_FE30(uint8 * Data,uint8* Length);
Std_ReturnType RC_STOP_Diag_FE30(uint8 * Data,uint8* Length);
Std_ReturnType RC_RESULTS_Diag_FE30(uint8 * Data,uint8* Length);
#endif

#ifdef IOCTRLRD_FUEL_INPUT_READING_BY_UNIT_WCalib
Std_ReturnType RC_START_Diag_F106(uint8 * Data,uint8* Length);
Std_ReturnType RC_RESULTS_Diag_F106(uint8 * Data,uint8* Length);
#endif 

#ifdef VALIDATETDMINTERFACE
Std_ReturnType RC_START_Diag_FE3B(uint8 * Data,uint8* Length);
Std_ReturnType RC_STOP_Diag_FE3B(uint8 * Data, const uint8* Length);
#endif 

#ifdef IOCONTOLRD_ADC_READ_GROUP
#if IOCONTOLRD_ADC_READ_GROUP > 0U
Std_ReturnType Read_Diag_FD02(uint8* Data,const uint8* Length);
#endif
#if IOCONTOLRD_ADC_READ_GROUP > 1U
Std_ReturnType Read_Diag_FD05(uint8* Data,uint8* Length);
#endif
#if IOCONTOLRD_ADC_READ_GROUP > 2U
Std_ReturnType Read_Diag_FD07(uint8* Data,uint8* Length);
#endif
#if IOCONTOLRD_ADC_READ_GROUP > 3U
Std_ReturnType Read_Diag_FD08(uint8* Data,uint8* Length);
#endif
#endif

#ifdef IOCONTOLRD_TFT_CONTINUITY_LOOP_CHECK
Std_ReturnType Read_Diag_FE02(uint8* Data,uint8* Length);
#endif

#ifdef IOCTRL_ANALOG_READ_ALL_ADC
Std_ReturnType Read_Diag_FE03(uint8* Data,uint8* Length);
#endif

#if defined (IOCTRL_ANALOG_READ_ADC_SINGLE_CH) || defined(IOCTRL_ANALOG_READ_ALL_ADC)
Std_ReturnType Read_Diag_F442(uint8* Data,uint8* Length);
/* DIDF442 */
#define BATTVOLT_IN_SCALE                           ((uint16) 49u)
/* Battery voltage in Offset value */
#define BATTVOLT_IN_OFFSET                          ((uint16) 0u)
/* IPC voltage DID Scale value 0.1 (or) 6554/65536 */
#define IPCVOLTAGE_DID_SCALE_NMR                    ((uint16) 6554u)
#define IPCVOLTAGE_DID_SCALE_DNR                    ((uint32) 65536u)
/* IPC voltage DID offset value */
#define IPCVOLTAGE_DID_OFFSET                       ((uint16) 0u)
#define F442_BIT_SHIFTER                            ((uint8) 8u)
#endif
// Memdiag services
#ifdef NVMVALIDITYCHKENABLE
Std_ReturnType Read_Diag_FA38(uint8* Data,uint8* Length);
#endif

#ifdef NVMACCESSBYBLOCKIDREADWRITEENABLE
Std_ReturnType Write_Diag_FA5E(uint8* Data,uint8* Length);
#endif

#ifdef MFGMODEREQENABLE	
Std_ReturnType Read_Diag_FA4C(uint8* Data,const uint8* Length);
Std_ReturnType Write_Diag_FA4C(uint8* Data,const uint8* Length);
#endif

#ifdef CYBERSECDIAG_CSM_SAFE_KEY_NUMBER	
Std_ReturnType Read_Diag_010B(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_010B(uint8* Data,uint8* Length);
#endif

#ifdef CYBERSECDIAG_JTAG_PASSWORD_WRITE_LOCK_ENABLE	
Std_ReturnType Read_Diag_FD0D(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_FEF3(uint8* Data,uint8* Length);
#endif

#if defined(CYBERSECDIAG_UART_UNLOCK_ENABLE) 
Std_ReturnType RC_START_Diag_FEE3(uint8* Data,uint8* Length);
#endif

// Routine Control Stop,stop and  Status
#ifdef MEMDIAG_UNLOCK_SECURE_ACCESS
Std_ReturnType RC_START_Diag_F0FC(uint8 * Data,uint8* Length);
Std_ReturnType RC_STOP_Diag_F0FC(uint8 * Data,uint8* Length);
Std_ReturnType RC_RESULTS_Diag_F0FC(uint8 * Data,uint8* Length);
#endif

#ifdef MEMWRITETESTENABLE
Std_ReturnType RC_START_Diag_F115(uint8 * Data,uint8* Length);
Std_ReturnType RC_STOP_Diag_F115(uint8 * Data,uint8* Length);
Std_ReturnType RC_RESULTS_Diag_F115(uint8 * Data,uint8* Length);
#endif

#ifdef PROGRAM_NVM_FROM_ROM
Std_ReturnType RC_START_Diag_FE20(uint8 * Data,uint8* Length);
Std_ReturnType RC_STOP_Diag_FE20(uint8 * Data,uint8* Length);
Std_ReturnType RC_RESULTS_Diag_FE20(uint8 * Data,uint8* Length);
#endif

#ifdef NVMACCESSBYBLOCKIDRCENABLE
Std_ReturnType RC_START_Diag_F20F(uint8 * Data,uint8* Length);
Std_ReturnType RC_STOP_Diag_F20F(uint8 * Data,uint8* Length);
Std_ReturnType RC_RESULTS_Diag_F20F(uint8 * Data,uint8* Length);
#endif

#ifdef DISPLAY_TOUCH_TEST_CHECK
Std_ReturnType RC_START_Diag_FE02(uint8 * Data,uint8* Length);
Std_ReturnType RC_STOP_Diag_FE02(uint8 * Data,uint8* Length);
Std_ReturnType RC_RESULTS_Diag_FE02(uint8 * Data,uint8* Length);
#endif

#ifdef MEMDIAG_MEMORY_VALIDITY_CHECK
Std_ReturnType RC_START_Diag_FA38(uint8 * Data,uint8* Length);
Std_ReturnType RC_STOP_Diag_FA38(uint8 * Data,uint8* Length);
Std_ReturnType RC_RESULTS_Diag_FA38(uint8 * Data,uint8* Length);
#endif

#ifdef MEMDIAG_MEMORY_VALIDITY_CHECK
Std_ReturnType RC_START_Diag_FA37(uint8 * Data,uint8* Length);
Std_ReturnType RC_STOP_Diag_FA37(uint8 * Data,uint8* Length);
Std_ReturnType RC_RESULTS_Diag_FA37(uint8 * Data,uint8* Length);
#endif

#ifdef MEMDIAG_ODOMETER_NVM_ROUTINE
Std_ReturnType RC_START_Diag_FE3C(uint8 * Data,uint8* Length);
Std_ReturnType RC_STOP_Diag_FE3C(uint8 * Data,uint8* Length);
Std_ReturnType RC_RESULTS_Diag_FE3C(uint8 * Data,uint8* Length);
#endif

#ifdef HYPERFLASHCHKSUMTSTENABLE
Std_ReturnType RC_START_Diag_F11E(uint8 * Data,uint8* Length);
Std_ReturnType RC_STOP_Diag_F11E(uint8 * Data,uint8* Length);
Std_ReturnType RC_RESULTS_Diag_F11E(uint8 * Data,uint8* Length);
#endif

#ifdef MEMDIAG_VIP_GIP_MEMORY_CHECKSUM_TEST
Std_ReturnType RC_START_Diag_F11E(uint8 * Data,uint8* Length);
Std_ReturnType RC_STOP_Diag_F11E(uint8 * Data,uint8* Length);
Std_ReturnType RC_RESULTS_Diag_F11E(uint8 * Data,uint8* Length);

Std_ReturnType RC_START_Diag_FE44(uint8 * Data,uint8* Length);
Std_ReturnType RC_STOP_Diag_FE44(uint8 * Data,uint8* Length);
Std_ReturnType RC_RESULTS_Diag_FE44(uint8 * Data,uint8* Length);
#endif
#ifdef DISPLAYCONTROLDIAG_I2CTEST_ROUTINE
Std_ReturnType RC_START_Diag_FE42(uint8 * Data,uint8* Length);
Std_ReturnType RC_STOP_Diag_FE42(uint8 * Data,uint8* Length);
Std_ReturnType RC_RESULTS_Diag_FE42(uint8 * Data,uint8* Length);
#endif

#ifdef MEMDIAG_MEMORY_READ_WRITE_BY_ADDRESS
extern Std_ReturnType Memdiag_Memory_Read_By_Address(uint8 *Data,uint8 *ErrorCode);
extern Std_ReturnType Memdiag_Memory_Write_By_Address(uint8 *Data,uint8 *ErrorCode);
#endif

// Reset and sleep diag services
#ifdef SLEEPMODEENABLE
Std_ReturnType RC_START_Diag_F103(uint8 * Data,uint8* Length);
Std_ReturnType RC_STOP_Diag_F103(uint8 * Data,uint8* Length);
Std_ReturnType RC_RESULTS_Diag_F103(uint8 * Data,uint8* Length);
#endif

#ifdef COMMCONTROLDIAG_CXPITEST_ROUTINE
Std_ReturnType RC_START_Diag_FA40(uint8 * Data,uint8* Length);
Std_ReturnType RC_STOP_Diag_FA40(uint8 * Data,uint8* Length);
Std_ReturnType RC_RESULTS_Diag_FA40(uint8 * Data,uint8* Length);
#endif

#ifdef COMMCONTROLDIAG_MCANTEST_ROUTINE
Std_ReturnType RC_START_Diag_FA41(uint8 * Data,uint8* Length);
Std_ReturnType RC_STOP_Diag_FA41(uint8 * Data,uint8* Length);
Std_ReturnType RC_RESULTS_Diag_FA41(uint8 * Data,uint8* Length);
#endif

#ifdef WDRSTENABLE
Std_ReturnType RC_START_Diag_F000(uint8 * Data,const uint8* Length);
Std_ReturnType RC_RESULTS_Diag_F000(uint8 * Data,const uint8* Length);
Std_ReturnType RC_STOP_Diag_F000(uint8 * Data, const uint8* Length);
#endif

#ifdef RSTCNTRREADINGENABLE
Std_ReturnType Read_Diag_FD03(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_FD03(uint8* Data,uint8* Length);
#endif

#ifdef RESETSLEEPDIAG_ODOMETER_RESET
Std_ReturnType Write_Diag_FEDC(uint8* Data,uint8* Length);
#endif

//Com diag services
#ifdef COMM_BUS_VERIFICATION_TEST
Std_ReturnType RC_START_Diag_F108(uint8* Data,uint8* Length);
Std_ReturnType RC_STOP_Diag_F108(uint8 * Data,uint8* Length);
Std_ReturnType RC_RESULTS_Diag_F108(uint8* Data,uint8* Length);
#endif

#ifdef COM_BUS_GATEWAY
Std_ReturnType RC_START_Diag_F110(uint8 * Data,uint8* Length);
Std_ReturnType RC_STOP_Diag_F110(uint8 * Data,uint8* Length);
Std_ReturnType RC_RESULTS_Diag_F110(uint8 * Data,uint8* Length);
#endif

#ifdef COM_AUTO_TEST_INT_COM_BUS
Std_ReturnType RC_START_Diag_F10F(uint8 * Data,uint8* Length);
Std_ReturnType RC_STOP_Diag_F10F(uint8 * Data,uint8* Length);
Std_ReturnType RC_RESULTS_Diag_F10F(uint8 * Data,uint8* Length);
#endif

#ifdef COM_TEMP_DEACTIVATE_MAIN_COM_BUS
Std_ReturnType RC_START_Diag_F117(uint8 * Data,uint8* Length);
Std_ReturnType RC_STOP_Diag_F117(uint8 * Data,uint8* Length);
Std_ReturnType RC_RESULTS_Diag_F117(uint8 * Data,uint8* Length);
#endif

/* Stepper services */
#ifdef MOTORDIAG_SERVICE
#ifdef MMOS_CALIB_READ
Std_ReturnType Read_Diag_FA0F(uint8* Data,uint8* Length);//magnetic offsets
Std_ReturnType Write_Diag_FA0F(uint8* Data,uint8* Length);
#endif
#ifdef READ_MOTOR_POSITION
Std_ReturnType Read_Diag_FA17(uint8* Data,uint8* Length);//Read motor position reached
#endif
Std_ReturnType Read_Diag_FA18(uint8* Data,uint8* Length);// Read service for motor speed
#ifdef POINTER_POSITION_READ
Std_ReturnType Read_Diag_FA19(uint8* Data,uint8* Length);//pointer placement position reading
Std_ReturnType Write_Diag_FA19(uint8* Data,uint8* Length);
#endif
#ifdef POINTER_AUTHOMODE_READ
Std_ReturnType Read_Diag_FA1A(uint8* Data,uint8* Length);// pointer placement authorisation
Std_ReturnType Write_Diag_FA1A(uint8* Data,uint8* Length);
#endif
#ifdef SPEEDO_MAPTABLE_X
Std_ReturnType Read_Diag_FA20(uint8* Data,uint8* Length); //Speedo mapping table x
Std_ReturnType Write_Diag_FA20(uint8* Data,uint8* Length);
#endif
#ifdef TACHO_MAPTABLE_X 
Std_ReturnType Read_Diag_FA21(uint8* Data,uint8* Length);// Tacho mapping table x
Std_ReturnType Write_Diag_FA21(uint8* Data,uint8* Length);
#endif
#ifdef FUEL_MAPTABLE_X
Std_ReturnType Read_Diag_FA22(uint8* Data,uint8* Length);// Fuel mapping table x
Std_ReturnType Write_Diag_FA22(uint8* Data,uint8* Length);
#endif
#ifdef ENGTEMP_MAPTABLE_X
Std_ReturnType Read_Diag_FA23(uint8* Data,uint8* Length);// Engine temperature mapping table x
Std_ReturnType Write_Diag_FA23(uint8* Data,uint8* Length);
#endif
#ifdef SPEEDO_MAPTABLE_Y
Std_ReturnType Read_Diag_FA24(uint8* Data,uint8* Length);//Speedo mapping table y
Std_ReturnType Write_Diag_FA24(uint8* Data,uint8* Length);
#endif
#ifdef TACHO_MAPTABLE_Y
Std_ReturnType Read_Diag_FA25(uint8* Data,uint8* Length);// Tacho mapping table y
Std_ReturnType Write_Diag_FA25(uint8* Data,uint8* Length);
#endif
#ifdef FUEL_MAPTABLE_Y
Std_ReturnType Read_Diag_FA26(uint8* Data,uint8* Length);// Fuel mapping table y
Std_ReturnType Write_Diag_FA26(uint8* Data,uint8* Length);
#endif
#ifdef ZERO_POINT_POSITION_READ
Std_ReturnType Read_Diag_FA27(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_FA27(uint8* Data,uint8* Length);
#endif
#ifdef SPEEDO_CRTNTABLE_Y
Std_ReturnType Read_Diag_FA28(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_FA28(uint8* Data,uint8* Length);
#endif
#ifdef TACHO_CRTNTABLE_Y
Std_ReturnType Read_Diag_FA29(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_FA29(uint8* Data,uint8* Length);
#endif
#ifdef FUEL_CRTNTABLE_Y
Std_ReturnType Read_Diag_FA2A(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_FA2A(uint8* Data,uint8* Length);
#endif
#ifdef ENGTEMP_CRTNTABLE_Y
Std_ReturnType Read_Diag_FA2B(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_FA2B(uint8* Data,uint8* Length);
#endif
#ifdef SPEEDO_CRTNTABLE_X
Std_ReturnType Read_Diag_FA2C(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_FA2C(uint8* Data,uint8* Length);
#endif
#ifdef TACHO_CRTNTABLE_X
Std_ReturnType Read_Diag_FA2D(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_FA2D(uint8* Data,uint8* Length);
#endif
#ifdef FUEL_CRTNTABLE_X
Std_ReturnType Read_Diag_FA2E(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_FA2E(uint8* Data,uint8* Length);
#endif
#ifdef SWZERO_SCALE_PARAMETERS
Std_ReturnType Read_Diag_FA2F(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_FA2F(uint8* Data,uint8* Length);
#endif
#ifdef ENGTEMP_MAPTABLE_Y
Std_ReturnType Read_Diag_FA4A(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_FA4A(uint8* Data,uint8* Length);
#endif
#ifdef ENGTEMP_CRTNTABLE_X
Std_ReturnType Read_Diag_FA4B(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_FA4B(uint8* Data,uint8* Length);
#endif
#ifdef TRANSTEMP_MAPTABLE_Y
Std_ReturnType Read_Diag_FA5C(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_FA5C(uint8* Data,uint8* Length);
#endif
#ifdef TRANSTEMP_MAPTABLE_X
Std_ReturnType Read_Diag_FA5B(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_FA5B(uint8* Data,uint8* Length);
#endif
#ifdef TRANSTEMP_CRTNTABLE_Y
Std_ReturnType Read_Diag_FA61(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_FA61(uint8* Data,uint8* Length);
#endif
#ifdef OILPRS_MAPTABLE_Y
Std_ReturnType Read_Diag_FA42(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_FA42(uint8* Data,uint8* Length);
#endif
#ifdef OILPRS_MAPTABLE_X
Std_ReturnType Read_Diag_FA4E(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_FA4E(uint8* Data,uint8* Length);
#endif
#ifdef OILPRS_CRTNTABLE_Y
Std_ReturnType Read_Diag_FA4F(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_FA4F(uint8* Data,uint8* Length);
#endif
#ifdef OILPRS_CRTNTABLE_X
Std_ReturnType Read_Diag_FA4D(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_FA4D(uint8* Data,uint8* Length);
#endif
#ifdef TRANSTEMP_CRTNTABLE_X
Std_ReturnType Read_Diag_FA60(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_FA60(uint8* Data,uint8* Length);
#endif
#ifdef ORDER_IN_USTEPS_OR_DEG
Std_ReturnType IOCTL_STA_Diag_FD07(uint8 * Data,uint8* Length); // stepper
Std_ReturnType IOCTL_RCTE_Diag_FD07(uint8 * Data,uint8* Length);
#endif
#ifdef ORDER_IN_VEHICLE_UNIT
Std_ReturnType IOCTL_STA_Diag_FD08(uint8 * Data,uint8* Length); //stepper
Std_ReturnType IOCTL_RCTE_Diag_FD08(uint8 * Data,uint8* Length);
#endif
#ifdef HIGH_IMPEDANCE
Std_ReturnType IOCTL_STA_Diag_FD09(uint8 * Data,uint8* Length); //stepper
Std_ReturnType IOCTL_RCTE_Diag_FD09(uint8 * Data,uint8* Length);
#endif
#ifdef LOW_TORQUE
Std_ReturnType IOCTL_STA_Diag_FD0A(uint8 * Data,uint8* Length); //stepper
Std_ReturnType IOCTL_RCTE_Diag_FD0A(uint8 * Data,uint8* Length);
#endif
#ifdef JUMP_IN_USTEPS
Std_ReturnType IOCTL_STA_Diag_FD0C(uint8 * Data,uint8* Length); //Jump in microsteps
Std_ReturnType IOCTL_RCTE_Diag_FD0C(uint8 * Data,uint8* Length);
#endif

Std_ReturnType RC_START_Diag_F102(uint8 * Data,uint8* Length); //Continuous motor movement
Std_ReturnType RC_STOP_Diag_F102(uint8 * Data,uint8* Length);
Std_ReturnType RC_RESULTS_Diag_F102(uint8 * Data,uint8* Length);

#ifdef HIGH_CALIBRATION_CONTROL
Std_ReturnType RC_START_Diag_F104(uint8 * Data,uint8* Length); //high calibration routine
Std_ReturnType RC_STOP_Diag_F104(uint8 * Data,uint8* Length);
Std_ReturnType RC_RESULTS_Diag_F104(uint8 * Data,uint8* Length);
#endif
#ifdef CONTINOUS_POINTER_MOVEMENT
Std_ReturnType RC_START_Diag_F112(uint8 * Data,uint8* Length); //Continuous pointer movement
Std_ReturnType RC_STOP_Diag_F112(uint8 * Data,uint8* Length);
Std_ReturnType RC_RESULTS_Diag_F112(uint8 * Data,uint8* Length);
#endif
#ifdef POINTER_PLACEMENT_ROUTINE
Std_ReturnType RC_START_Diag_F121(uint8 * Data,uint8* Length); //pointer placement routine
Std_ReturnType RC_STOP_Diag_F121(uint8 * Data,uint8* Length);
Std_ReturnType RC_RESULTS_Diag_F121(uint8 * Data,uint8* Length);
#endif
#ifdef SFD_ROC_ROUTINE
Std_ReturnType RC_START_Diag_F122(uint8 * Data,uint8* Length); // SFD for ROC routine
Std_ReturnType RC_STOP_Diag_F122(uint8 * Data,uint8* Length);
Std_ReturnType RC_RESULTS_Diag_F122(uint8 * Data,uint8* Length);
#endif

#ifdef SELFTEST_GAUGES
Std_ReturnType RC_START_Diag_F123(uint8 * Data,uint8* Length); //Self-test stepper stall detection routine
Std_ReturnType RC_STOP_Diag_F123(uint8 * Data,uint8* Length);
Std_ReturnType RC_RESULTS_Diag_F123(uint8 * Data,uint8* Length);
#endif

#endif

#ifdef MEMDIAG_ODOMETER_NVM_READWRITE
Std_ReturnType Read_Diag_FF00(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_FF00(uint8* Data,uint8* Length);
#endif

#ifdef CYBERSECDIAG_SECURE_KEY_PROGRAMMING_AES_IV
Std_ReturnType RC_START_Diag_FEF1(uint8 * Data,uint8* Length);		 
Std_ReturnType RC_RESULTS_Diag_FEF1(uint8 * Data,uint8* Length);
#endif

#ifdef CYBERSECDIAG_SECURE_KEY_PROGRAMMING_AES
Std_ReturnType RC_START_Diag_FEF0(uint8 * Data,uint8* Length);		 
Std_ReturnType RC_RESULTS_Diag_FEF0(uint8 * Data,uint8* Length);
#endif

#ifdef CYBERSECDIAG_SECURE_KEY_PROGRAMMING_RSA
Std_ReturnType RC_START_Diag_FEF2(uint8 * Data,uint8* Length);		 
Std_ReturnType RC_RESULTS_Diag_FEF2(uint8 * Data,uint8* Length);
#endif

#ifdef CYBERSECDIAG_SECURE_FUSE_PROGRAMMING
Std_ReturnType RC_START_Diag_FEF6(uint8 * Data,uint8* Length);
Std_ReturnType RC_START_Diag_FEF9(uint8 * Data,uint8* Length);
Std_ReturnType RC_START_Diag_FEF8(uint8 * Data,uint8* Length);
Std_ReturnType RC_START_Diag_FEFA(uint8 * Data,uint8* Length);
#endif

#ifdef CYBERSECDIAG_SECURE_SYMMETRIC_KEY_PROGRAMMING
Std_ReturnType RC_START_Diag_FEF0(uint8 * Data,uint8* Length);		 
Std_ReturnType RC_RESULTS_Diag_FEF0(uint8 * Data,uint8* Length);
#endif

#ifdef CYBERSECDIAG_DATA_LOCK_AES_IV
Std_ReturnType Read_Diag_FEF4(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_FEF4(uint8* Data,uint8* Length);
#endif

#ifdef CYBERSECDIAG_DATA_LOCK_RSA
Std_ReturnType Read_Diag_FEF5(uint8* Data,uint8* Length);
Std_ReturnType Write_Diag_FEF5(uint8* Data,uint8* Length);
#endif

#if (defined(CYBERSECDIAG_BACKUPBANK_VERIFICATION_ONLY_CMAC) || defined(CYBERSECDIAG_BACKUPBANK_VERIFICATION))
Std_ReturnType RC_START_Diag_FEFB(uint8 * Data,uint8* Length);		 
Std_ReturnType RC_RESULTS_Diag_FEFB(uint8 * Data,uint8* Length);
#endif

#ifdef CYBERSECDIAG_SYMMETRIC_KEY_VERIFICATION
Std_ReturnType RC_START_Diag_FEFC(uint8 * Data,uint8* Length);		 
Std_ReturnType RC_RESULTS_Diag_FEFC(uint8 * Data,uint8* Length);
#endif

#ifdef CYBERSECDIAG_KEY_STORE_AND_LOCK
Std_ReturnType RC_START_Diag_FD87(uint8 * Data,uint8* Length);
#endif

#ifdef CYBERSECDIAG_SHESLOTS_READ
Std_ReturnType Read_Diag_FEE1(uint8 * Data,uint8* Length);
Std_ReturnType Read_Diag_FEE4(uint8 * Data,uint8* Length);
Std_ReturnType Read_Diag_FEE5(uint8 * Data,uint8* Length);
Std_ReturnType Read_Diag_FEE6(uint8 * Data,uint8* Length);
#endif

#ifdef MEET_GIP_ENABLED
Std_ReturnType Meet_Process_Gip_Diag_Request(GIPDataRquestState DcmStatus,P2VAR(DiagReqType, AUTOMATIC, DCM_VAR_NOINIT) pDiagReq,uint8 *pErrorCode);

#define DCM_RESPONSE_TIMEOUT            (DCM_E_NORESPONSEFROMSUBNETCOMPONENT)
typedef struct
{
  uint8 Length;
  DiagRespBufferType DiagRespBuffer;
} SDiagResponse_t;	

typedef struct  {
    SDiagResponse_t   DiagRespData;
    boolean        bResponseReceived;
    uint16         u16ResponseTimeout;
    DiagResultType DiagResult;
} DiagResponse_t;

void Diag_TIGIP_SendDiagRequest(P2CONST(DiagReqType, AUTOMATIC, DCM_VAR_NOINIT) pDiagReq);
boolean Diag_TIGIP_IsResponseReceived(void);
DiagResultType Diag_TIGIP_GetDiagResult(void);
SDiagResponse_t* Diag_TIGIP_GetDiagResponse(void);
void Diag_TIGIP_MainFunction(void);
boolean Diag_TIGIP_IsResponseTimedOut(void);
#define DIAGIOC_SHORTTERMADJUSTMENT 0x03
#define DiagIOC_returnControlToECU 0x00

#ifdef MEET_GIP_ENABLED_CRYPTO
Std_ReturnType Meet_Process_Gip_Diag_Request_Crypto(GIPDataRquestState DcmStatus,P2VAR(MeetDiagReqType, AUTOMATIC, DCM_VAR_NOINIT) pDiagReq,uint8 *pErrorCode);
void Diag_TIGIP_SendDiagRequest_Crypto(P2VAR(MeetDiagReqType, AUTOMATIC, DCM_VAR_NOINIT) pDiagReq);
#endif

#ifdef CMEETCDD_STUBS_CHIMES
void Stub_SetDiagToneCtrlStart(const tGenMdlDiagToneCtrlData * pChimeToneCtrlData, tGenMdlDiagResp * DiagRespStatus);
void Stub_SetDiagToneCtrlStop(void);
#endif

#ifdef CMEETCDD_STUBS_ILLUM
extern FUNC(Std_ReturnType, CBacklightCdd_CODE) CBacklightCdd_SetBrightnessValue(EDisplayType DeviceName, UInt16 BrightnessPercentValue);
void Stub_SetDisplayBrightness(uint16 DutyVal);
#endif

#ifdef DISPLAYCONTROLDIAG_TSW_I2CREAD_ROUTINE
Std_ReturnType RC_START_Diag_FE0B   (uint8 * Data,uint8* Length);
Std_ReturnType RC_RESULTS_Diag_FE0B (uint8 * Data,uint8* Length);
#endif

#ifdef NVMACCESSBYADDRESSRCENABLE
extern Std_ReturnType NvMExt_ReadAddress(uint32 EepromAddress, uint8* DataBufferPtr,uint16 Length);
extern Std_ReturnType NvMExt_WriteAddress(uint32 EepromAddress,const uint8* DataBufferPtr,uint16 Length);
#endif

#ifdef DISPLAY_TOUCH_VERIFICATION_CHECK
Std_ReturnType RC_START_Diag_FE0C(uint8 * Data,uint8* Length);
Std_ReturnType RC_STOP_Diag_FE0C(uint8 * Data,uint8* Length);
Std_ReturnType RC_RESULTS_Diag_FE0C(uint8 * Data,uint8* Length);
#endif
#endif
/*======================================================================================================================
**  for each change to this file, be sure to record:
**  1.who made the change and when the change was made
**  2.why the change was made and the intended result
**  following block needs to be repeated for each change
**======================================================================================================================*/
/*   Note: In the traceability column we need to trace back to the Design Doc.
**   For the initial version it is traced to the Design Document section.     
**   For further changes it shall trace to the source of the change which may
**   be SPSS/SCR/Defect details(Defect may be Testing/validation defect)/Any  
**   other reason                                                             
**======================================================================================================================*/
/*=====================================================================================================================
** Date              :  26/May/2023
** CDSID             :  spalan11
** Traceability      :  RTC - 2021383
** Change Description:  New feature implemented UART UNLOCK
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  17/April/2023
** CDSID             :  mprajapa
** Traceability      :  RTC-1985454
** Change Description:  Touch Screen Verification Routine Services are added.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  17/03/2023
** CDSID             :  rsubra13
** Traceability      :  RTC 1951466
** Change Description:  EEPROM Read/Write by address Response updated.
**====================================================================================================================*/ 
/*=====================================================================================================================
** Date              :  15/Mar/2023
** CDSID             :  mprajapa
** Traceability      :  RTC-1951989
** Change Description:  I2C-Read Related Configuration is added.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  07/Sept/2022
** CDSID             :  razhakes
** Traceability      :  RTC-1759758
** Change Description:  READ_INTERFACE_FOR_APPL_COMPONENTS updated
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  24/Aug/2022
** CDSID             :  ddanecha
** Traceability      :  RTC-1744046
** Change Description:  Redundant interfaces are removed and minor code clean up
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  03/Aug/2022
** CDSID             :  ddanecha
** Traceability      :  RTC-1707104
** Change Description:  MeetCdd Coverity-MISRA fix
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  23/05/2022
** CDSID             :  ddanecha
** Traceability      :  RTC 1634375
** Change Description:  Coverity/MISRA Fix and Minor update.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  16/05/2022
** CDSID             :  ddanecha
** Traceability      :  RTC 1632871, 1655512, 1660171
** Change Description:  Macros and configurations are updated as per TATAGEN2 related DIDs and DRs.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  05/Aug/2020
** CDSID             :  razhakes
** Traceability      :  RTC-880214,RTC-880217
** Change Description: Cybersecurity Key Verification and Backup Bank Verification service addition
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  13/05/2020
** CDSID             :  dkasiman
** Traceability      :  RTC 880204
** Change Description:  Communication bus verification test service addition.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  10/March/2020
** CDSID             :  razhakes and dkasiman
** Traceability      :  RTC -760543
** Change Description:  Support for security DID implementation
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 12/Dec/2019
** CDSID             : dkasiman
** Traceability      : RTC-1393187 
** Change Description: TFT connection check service added.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  9/11/2019
** CDSID             :  razhakes
** Traceability      :  RTC 1368184
** Change Description:  For GIP service few more MACROS added.
						For SDiagResponse_t -> Length is changed from uint16 to uint8.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  9/11/2019
** CDSID             :  razhakes
** Traceability      :  RTC 1365920
** Change Description:  Odometer NVM read write service implemented
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  10/09/2019
** CDSID             :  vsupraja
** Traceability      :  RTC 1367486
** Change Description:  P33 : DCIC result routine update in VIP
**====================================================================================================================*/
/**====================================================================================================================
** Date              :  10/09/2019
** CDSID             :  vsupraja
** Traceability      :  RTC 1367817
** Change Description:  Updated DCIC routine status - VIP
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  16/07/2019
** CDSID             :  vsupraja
** Traceability      :  RTC - 1348007
** Change Description:  Added Read and Write services for Sound Channel volume and Sound mixer volume
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  10/06/2019
** CDSID             :  razhakes
** Traceability      :  RTC-1334319
** Change Description:  program NVM from ROM service added.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  31/05/2019
** CDSID             :  razhakes
** Traceability      :  RTC-1331232
** Change Description:  Auto configure/verify service added.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  17/05/2019
** CDSID             :  dkasiman
** Traceability      :  RTC 1310404,1310400,1297825 and 1321988
** Change Description:  Display content integrity check(SIG unit check) service added.
                        Three point fuel calibration added
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  26/Mar/2019
** CDSID             :  dkasiman
** Traceability      :  RTC 1303833
** Change Description:  GIPDataRquestState definition added in Mgrdiagcdd_cfg.h, BCD and Decimal manipulation macros for 
                        analogic signal control and dimming control defined before the inclusion of Mgrdiagcddd_cfg.h file. 
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  18/march/2019
** CDSID             :  razhakes
** Traceability      :  RTC 1297724
** Change Description:  BCD manipulation and Decimal manipulation of analog and pwm modules seperated to 2 different macros
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  12/march/2019
** CDSID             :  razhakes
** Traceability      :  RTC 1262819
** Change Description:  MeetGipEnabled macro and vip - gip communication related functions are added
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  11/1/2019
** CDSID             :  athiyag2
** Traceability      :  RTC 1265368
** Change Description:  added missing endif statement
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  02/11/2018
** CDSID             :  gdhilipr	
** Traceability      :  RTC 1227921   
** Change Description:  Added the Analog Measurement Reading - FD30
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  01/11/2018
** CDSID             :  gdhilipr
** Traceability      :  RTC 1229036 
** Change Description:  Implementation : Fuel Input Reading - F106
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 10/05/2018
** CDSID             : gdhilipr
** Traceability      : RTC 1208270
** Change Description: Traceability services update(FD4D) ï¿½ For the station WS2 & Generalizing the Station names(ICT - Station1,FCT- Station2,AC  - Station3,FC  -  Station4,WS2 - Station5,AMS to Station6)
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 10/01/2018
** CDSID             : gdhilipr
** Traceability      : RTC 1208270
** Change Description: Traceability services update(FD4D) ï¿½ For the station WS2 & Generalizing the Station names(ICT - Station1,FCT- Station2,AC  - Station3,FC  -  Station4,WS2 - Station5,AMS to Station6)
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 10/01/2018
** CDSID             : gdhilipr
** Traceability      : RTC 1208215
** Change Description: Dimming control updated with Control Type1(customer calibrated level)
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  11/8/2018
** CDSID             :  dkasiman
** Traceability      :  RTC-1175981
** Change Description:  Read/Write memory by address support for TCRAM and Hyper RAM 
**====================================================================================================================*/ 
/*======================================================================================================================
** Date              : 10/Aug/2018 
** CDSID             : dkasiman
** Traceability      : RTC: 1148618/1148619 
** Change Description: Timer added for security algorithm. 
**=======================================================================================================================*/
/*======================================================================================================================
** Date              : 17/July/2018 
** CDSID             : gnataraj
** Traceability      : RTC-1144520, RTC-1145376
** Change Description: Added Continuous Pointer Movement Service ($F112)
**=======================================================================================================================*/
/*======================================================================================================================
** Date              : 11/July/2018 
** CDSID             : dkasiman
** Traceability      : RTC-1148640/RTC-1148605/RTC-1148623 
** Change Description: Traceability bytes status and Check program dependencies check routine are update. 
**                     All stepper services are moved to the end.
**=======================================================================================================================*/
/*======================================================================================================================
** Date              :  10/Jul/2018  
** CDSID             :  gnataraj
** Traceability      :  RTC-1152264, RTC-1153689
** Change Description:  The read and write functions are generalized in Tracediag module
**=======================================================================================================================*/
/*======================================================================================================================
** Date              : 02/Jun/2018 
** CDSID             : dkasiman
** Traceability      : RTC-1112314
** Change Description: Review comments fix. 
**=======================================================================================================================*/
/*======================================================================================================================
** Date              : 20/May/2018 
** CDSID             : dkasiman
** Traceability      : RTC-1112314
** Change Description: Initial version for MeetCdd bookshelf. 
**=======================================================================================================================*/
/*======================================================================================================================
** Date              : 12/Feb/2021
** CDSID             : razhakes
** Traceability      : RTC-1173442
** Change Description: New DID FESN added. 
**=======================================================================================================================*/
#endif

