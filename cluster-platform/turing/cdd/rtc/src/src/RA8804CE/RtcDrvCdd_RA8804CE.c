/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2024. Visteon Corporation owns all rights to           *
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
*  File Name         :  RtcDrvCdd_RA8804CE.c                                 *
*  Module Short Name :  RTC                                                  *
*  Description       :  This file contains implementations of the Rtc Driver *
*                       for AM62PX series microcontrollers.                  *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  Clang Compiler                                         *
* Target Hardware  :  AM62PX micro based Hardware Platform                   *
*                                                                            *
******************************************************************************/

#ifndef RTCDRVCDD_RA8804CE_C
#define RTCDRVCDD_RA8804CE_C

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/

#include "RtcDrvCdd.h"

#define RTCCCDD_SEC_CODE_START
#define RTCCDD_CORE_CONST_SEC_START
#define RTCCDD_CORE_DATA_SEC_START
#define RTCCDD_CORE_BSS_SEC_START

#include "MemMap.h"

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

// RX-8804CE Basic Time and Calendar Register definitions
#define RA8804CE_BTC_SEC				(0x00)
#define RA8804CE_BTC_MIN				(0x01)
#define RA8804CE_BTC_HOUR				(0x02)
#define RA8804CE_BTC_WEEK				(0x03)
#define RA8804CE_BTC_DAY				(0x04)
#define RA8804CE_BTC_MONTH				(0x05)
#define RA8804CE_BTC_YEAR				(0x06)
#define RA8804CE_BTC_RAM				(0x07)
#define RA8804CE_BTC_ALARM_MIN			(0x08)
#define RA8804CE_BTC_ALARM_HOUR			(0x09)
#define RA8804CE_BTC_ALARM_WEEK_OR_DAY	(0x0A)
#define RA8804CE_BTC_TIMER_CNT_0		(0x0B)
#define RA8804CE_BTC_TIMER_CNT_1		(0x0C)
#define RA8804CE_BTC_EXT				(0x0D)
#define RA8804CE_BTC_FLAG				(0x0E)
#define RA8804CE_BTC_CTRL				(0x0F)

// Alarms AE bit position (registers RA8804CE_BTC_ALARM_MIN, RA8804CE_BTC_ALARM_HOUR, RA8804CE_BTC_ALARM_WEEK_OR_DAY)
#define RA8804CE_BTC_ALARM_AE	(1U << 7)

// Flag RA8804CE_BTC_EXT Register bit positions
#define RA8804CE_BTC_EXT_TSEL0		    (1U << 0)
#define RA8804CE_BTC_EXT_TSEL1		    (1U << 1)
#define RA8804CE_BTC_EXT_FSEL0		    (1U << 2)
#define RA8804CE_BTC_EXT_FSEL1		    (1U << 3)
#define RA8804CE_BTC_EXT_TE 			(1U << 4)
#define RA8804CE_BTC_EXT_USEL			(1U << 5)
#define RA8804CE_BTC_EXT_WADA			(1U << 6)
#define RA8804CE_BTC_EXT_TEST			(1U << 7)

// Flag RA8804CE_BTC_FLAG Register bit positions
#define RA8804CE_BTC_FLAG_VDET 		    (1U << 0)
#define RA8804CE_BTC_FLAG_VLF 		    (1U << 1)
#define RA8804CE_BTC_FLAG_AF 			(1U << 3)
#define RA8804CE_BTC_FLAG_TF 			(1U << 4)
#define RA8804CE_BTC_FLAG_UF 			(1U << 5)

// Flag RA8804CE_BTC_CTRL Register bit positions
#define RA8804CE_BTC_CTRL_RESET 	    (1U << 0)
#define RA8804CE_BTC_CTRL_AIE 		    (1U << 3)
#define RA8804CE_BTC_CTRL_TIE 		    (1U << 4)
#define RA8804CE_BTC_CTRL_UIE 		    (1U << 5)
#define RA8804CE_BTC_CTRL_CSEL0 	    (1U << 6)
#define RA8804CE_BTC_CTRL_CSEL1		    (1U << 7)

#define RA8804CE_BTC_REGISTERS_LENGTH	(0x10)
#define TIME_DATE_LENGTH                (7U)
#define ALARM_LENGTH 				    (3U)

#define HEX2BCD(v)	(((v) % 10U) + (((v) / 10U) * 16U))
#define BCD2HEX(v)	(((v) % 16U) + (((v) / 16U) * 10U))

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/

typedef enum
{
    eRtcCddNotInited,
    eRtcCddInited,
    eRtcCddMainRoutine,
    eRtcCddInterruptsHandling,
    eRtcCddApplySettings,
}ERtcCddMainState;
typedef enum
{
	eInvalidWeekDay = 0,
	eSunday,
	eMonday,
	eTuesday,
	eWednesday,
	eThursday,
	eFriday,
	eSaturday,
}ERtcCddWeekDays;

/*****************************************************************************
*                                 Locally used Variable Declarations         *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/

static  uint8 aTxBuffer [RA8804CE_BTC_REGISTERS_LENGTH];
static  ERtcCddMainState RtcState = eRtcCddNotInited;
I2c_CircularBuffer_t I2c_CircularBuffer;

/* This flag will be hold the status of read status after power initialization of device */

static boolean bRTCInitReadFinishedFlag = FALSE;

/*****************************************************************************
*                              Limited Scope Prototypes                      *
******************************************************************************/

static void RtcDrvCdd_InitRegs(void);
static Std_ReturnType RtcDrvCdd_SetResetState(void);
static uint8 RtcDrvCdd_GetWeek(uint8 RxWeek);
static void RtcDrvCdd_AlarmInterruptHandler(void);

/*****************************************************************************
*                            Functions Implementation                         *
******************************************************************************/

/*============================================================================
** Function Name    :   RtcDrvCdd_Init
**
** Visibility       :   Public
**
** Description      :   Initializes the RTC driver.
**
** Invocation       :   RtcIfCdd
**
** Inputs           :   None
**
** Outputs          :   Std_ReturnType - E_OK if initialization is successful
**
** Critical Section :   No
**==========================================================================*/

Std_ReturnType RtcDrvCdd_Init(void)
{
    RtcState = eRtcCddInited;
    RtcDrvCdd_i2cCbInit(&I2c_CircularBuffer);
    return E_OK;
}

/*============================================================================
** Function Name    :   RtcDrvCdd_DeInit
**
** Visibility       :   Public
**
** Description      :   De-initializes the RTC driver.
**
** Invocation       :   RtcIfCdd
**
** Inputs           :   None
**
** Outputs          :   Std_ReturnType - E_OK if de-initialization is successful
**
** Critical Section :   No
**==========================================================================*/

Std_ReturnType RtcDrvCdd_DeInit(void)
{
    RtcState = eRtcCddNotInited;
    return E_OK;
}

/*============================================================================
** Function Name    :   RtcDrvCdd_SetTime
**
** Visibility       :   Public
**
** Description      :   Sets the current time in the RA8804CE registers from
**                      the provided time/date structure.
**
** Invocation       :   RtcIfCdd
**
** Inputs           :   None
**
** Outputs          :   Std_ReturnType - E_OK if  successful
**
** Critical Section :   No
**==========================================================================*/

Std_ReturnType RtcDrvCdd_SetTime(const cRTCCDD_TIME_TYPE* pTimeDate)
{
    Std_ReturnType RetVal = E_NOT_OK;
 
    aTxBuffer[RA8804CE_BTC_SEC]   = (uint8)HEX2BCD( pTimeDate->second );
    aTxBuffer[RA8804CE_BTC_MIN]   = (uint8)HEX2BCD( pTimeDate->minute );
    aTxBuffer[RA8804CE_BTC_HOUR]  = (uint8)HEX2BCD( pTimeDate->hour );
    aTxBuffer[RA8804CE_BTC_WEEK]  = (uint8)(1 << ((uint8)pTimeDate->week - 1U));
    aTxBuffer[RA8804CE_BTC_DAY]   = (uint8)HEX2BCD( pTimeDate->day) ;
    aTxBuffer[RA8804CE_BTC_MONTH] = (uint8)HEX2BCD( pTimeDate->month );
    aTxBuffer[RA8804CE_BTC_YEAR]  = (uint8)HEX2BCD( pTimeDate->year );
 
    // Stop clock and calendar to synchronize with newly applied values. Will resume after next I2C command STOP condition
 
    RetVal =  RtcDrvCdd_SetResetState();
    if (E_OK == RetVal)
    {
        RetVal =  RtcDrvCdd_i2cWriteRegisters(RA8804CE_BTC_SEC, aTxBuffer, TIME_DATE_LENGTH, &I2c_CircularBuffer);
        if (E_OK == RetVal)
        {
            // clear VLF
            aTxBuffer[RA8804CE_BTC_FLAG] =
                I2c_CircularBuffer.I2c_RxBufferBTC[RA8804CE_BTC_FLAG] & (~RA8804CE_BTC_FLAG_VLF);
            RetVal = RtcDrvCdd_i2cWriteRegisters(
                RA8804CE_BTC_FLAG, &aTxBuffer[RA8804CE_BTC_FLAG], REGISTER_LENGTH, &I2c_CircularBuffer);
        }
    }
   
    return RetVal;
}

/*============================================================================
** Function Name    :   RtcDrvCddGetTime
**
** Visibility       :   Public
**
** Description      :   Gets the current time from the RA8804CE registers from
**                      the provided time/date structure.
**
** Invocation       :   RtcIfCdd
**
** Inputs           :   None
**
** Outputs          :   Std_ReturnType - E_OK if successful
**
** Critical Section :   No
**==========================================================================*/

Std_ReturnType RtcDrvCdd_GetTime(cRTCCDD_TIME_TYPE* pTimeDate)
{
    Std_ReturnType RetVal;
 
    if ( NULL == pTimeDate )
    {
        RetVal = E_INVALID_ARG;
    }
    else if ((I2c_CircularBuffer.I2c_RxBufferBTC[RA8804CE_BTC_FLAG] & RA8804CE_BTC_FLAG_VLF) != 0u)
    {
        RetVal = E_NOT_OK;
    }
    else if (bRTCInitReadFinishedFlag == FALSE)
    {
        RetVal = E_NOT_OK;
    }
    else
    {
        pTimeDate->second       = BCD2HEX( I2c_CircularBuffer.I2c_RxBufferBTC[RA8804CE_BTC_SEC] & 0x7FU );
        pTimeDate->minute       = BCD2HEX( I2c_CircularBuffer.I2c_RxBufferBTC[RA8804CE_BTC_MIN] & 0x7FU );
        pTimeDate->hour         = BCD2HEX( I2c_CircularBuffer.I2c_RxBufferBTC[RA8804CE_BTC_HOUR] & 0x3FU );
        pTimeDate->week         = RtcDrvCdd_GetWeek(I2c_CircularBuffer.I2c_RxBufferBTC[RA8804CE_BTC_WEEK]);
        pTimeDate->day          = BCD2HEX( I2c_CircularBuffer.I2c_RxBufferBTC[RA8804CE_BTC_DAY] & 0x3FU );
        pTimeDate->month        = BCD2HEX( I2c_CircularBuffer.I2c_RxBufferBTC[RA8804CE_BTC_MONTH] & 0x1FU );
        pTimeDate->year         = BCD2HEX( I2c_CircularBuffer.I2c_RxBufferBTC[RA8804CE_BTC_YEAR] );
        RetVal = E_OK;
    }
 
    return RetVal;
}

/*============================================================================
** Function Name    :   RtcDrvCdd_MainFunction
**
** Visibility       :   Public
**
** Description      :   Main function for RTC driver, to be called periodically
**
** Invocation       :   RtcIfCdd
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   No
**==========================================================================*/

void RtcDrvCdd_MainFunction(void)
{
    // While Circular buffer is not empty - nothing to do before processed
    if ( E_OK != RtcDrvCdd_i2cCheckIfBufferEmpty(&I2c_CircularBuffer) )
    {
        (void)RtcDrvCdd_i2cProcessCircularBuffer(&I2c_CircularBuffer);
        return;
    }
 
    switch(RtcState)
    {
    case eRtcCddNotInited:
        break;
 
    case eRtcCddInited:
        if(I2c_CircularBuffer.I2c_RxBufferBTC[RA8804CE_BTC_FLAG] != 0)
        {
            RtcState = eRtcCddApplySettings;
        }
        else
        {
            (void)RtcDrvCdd_i2cReadRegisters(RA8804CE_BTC_SEC, &I2c_CircularBuffer);
        }
        break;
 
    case eRtcCddApplySettings:
        RtcState = eRtcCddMainRoutine;
        RtcDrvCdd_InitRegs();
        break;
 
    case eRtcCddMainRoutine:
        RtcState = eRtcCddInterruptsHandling;
        (void)RtcDrvCdd_i2cReadRegisters(RA8804CE_BTC_SEC, &I2c_CircularBuffer);
        break;
 
    case eRtcCddInterruptsHandling:
        RtcState = eRtcCddMainRoutine;
        bRTCInitReadFinishedFlag = TRUE; // Set the Init read flag as true, on this stage data will available in the Buffer to read.
        RtcDrvCdd_AlarmInterruptHandler();
        break;
 
    default:
        RtcState = eRtcCddNotInited;
        break;
    }
}

/*============================================================================
** Function Name    :   RtcDrvCdd_InitRegs
**
** Visibility       :   Public
**
** Description      :   Init the Registers Control, Flag, Extension regs
**
** Invocation       :   RtcDrvCdd_MainFunction
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   No
**==========================================================================*/

static void RtcDrvCdd_InitRegs(void)
{
    aTxBuffer[RA8804CE_BTC_EXT] = (I2c_CircularBuffer.I2c_RxBufferBTC[RA8804CE_BTC_EXT] | RA8804CE_BTC_EXT_WADA) & (~RA8804CE_BTC_EXT_TE);
    aTxBuffer[RA8804CE_BTC_FLAG] = RA8804CE_BTC_FLAG_VLF; // retain VLF state
    aTxBuffer[RA8804CE_BTC_CTRL] = RA8804CE_BTC_CTRL_CSEL0 | RA8804CE_BTC_CTRL_AIE;
 
    (void)RtcDrvCdd_i2cWriteRegisters(RA8804CE_BTC_EXT, &aTxBuffer[RA8804CE_BTC_EXT], REGISTER_LENGTH*3, &I2c_CircularBuffer);
}

/*============================================================================
** Function Name    :   RtcDrvCdd_SetResetState
**
** Visibility       :   Public
**
** Description      :   Activate RESET state. Clock, Calendar and Timer stops
**                        till the next I2C command STOP condition will be reached.
**
** Invocation       :   RtcDrvCdd_MainFunction
**
** Inputs           :   None
**
** Outputs          :   Std_ReturnType - E_OK if successful
**                                       E_NOT_OK if operation failed
**
** Critical Section :   No
**==========================================================================*/

static  Std_ReturnType RtcDrvCdd_SetResetState(void)
{
    Std_ReturnType RetVal = E_NOT_OK;
 
    // Update current CTRL register value with setting "RESET" bit
    aTxBuffer[RA8804CE_BTC_CTRL] = I2c_CircularBuffer.I2c_RxBufferBTC[RA8804CE_BTC_CTRL] | RA8804CE_BTC_CTRL_RESET;                             // RA8804CE_BTC_CTRL_RESET = 1
 
    RetVal = RtcDrvCdd_i2cWriteRegisters(RA8804CE_BTC_CTRL, &aTxBuffer[RA8804CE_BTC_CTRL], REGISTER_LENGTH, &I2c_CircularBuffer);
 
    return RetVal;
}

/*============================================================================
** Function Name    :   RtcDrvCdd_AlarmInterruptHandler
**
** Visibility       :   Public
**
** Description      :   Process active interrupts flags(AF,TF,UF)
**
** Invocation       :   RtcDrvCdd_MainFunction
**
** Inputs           :   None
**
** Outputs          :   Std_ReturnType - E_OK if successful
**                                       E_INVALID_ARG if invalid argument
**                                       E_NOT_OK if operation failed
**
** Critical Section :   No
**==========================================================================*/


static void RtcDrvCdd_AlarmInterruptHandler(void)
{
    if ( I2c_CircularBuffer.I2c_RxBufferBTC[RA8804CE_BTC_FLAG] & RA8804CE_BTC_FLAG_AF )
    {
        RtcIfCdd_AlarmNotification();  //send Alarm Notification to RtcIfCdd to be forwarded to RtcCdd
        RtcDrvCdd_ClearAlarm();
    }
 
    if ( I2c_CircularBuffer.I2c_RxBufferBTC[RA8804CE_BTC_FLAG] & RA8804CE_BTC_FLAG_TF )
    {
        // Fixed-cycle timer interrupt handling routines
 
        // Clear TF bit
        aTxBuffer[RA8804CE_BTC_FLAG] = I2c_CircularBuffer.I2c_RxBufferBTC[RA8804CE_BTC_FLAG] & (~RA8804CE_BTC_FLAG_TF);
        (void)RtcDrvCdd_i2cWriteRegisters(RA8804CE_BTC_FLAG, &aTxBuffer[RA8804CE_BTC_FLAG], REGISTER_LENGTH, &I2c_CircularBuffer);
    }
 
    if ( I2c_CircularBuffer.I2c_RxBufferBTC[RA8804CE_BTC_FLAG] & RA8804CE_BTC_FLAG_UF )
    {
        // Update ("second" or "minute") interrupt handling routines
 
        // Clear UF bit
        aTxBuffer[RA8804CE_BTC_FLAG] = I2c_CircularBuffer.I2c_RxBufferBTC[RA8804CE_BTC_FLAG] & (~RA8804CE_BTC_FLAG_UF);
        (void)RtcDrvCdd_i2cWriteRegisters(RA8804CE_BTC_FLAG, &aTxBuffer[RA8804CE_BTC_FLAG], REGISTER_LENGTH, &I2c_CircularBuffer);
    }
}

/*============================================================================
** Function Name    :   RtcDrvCdd_GetWeek
**
** Visibility       :   Private
**
** Description      :   Parses the read week value from RTC register to 
**                      standardized week day enumeration
**
** Invocation       :   RtcIfCdd
**
** Inputs           :   RxWeek - Raw week value from RTC register
**
** Outputs          :   Parsed week day value
**
** Critical Section :   No
**==========================================================================*/

static uint8 RtcDrvCdd_GetWeek(uint8 RxWeek)
{
    uint8 parsedWeek = eInvalidWeekDay;
    switch (RxWeek)
    {
    case 1:
        parsedWeek = eSunday;
        break;
    case 2:
        parsedWeek = eMonday;
        break;
    case 4:
        parsedWeek = eTuesday;
        break;
    case 8:
        parsedWeek = eWednesday;
        break;
    case 16:
        parsedWeek = eThursday;
        break;
    case 32:
        parsedWeek = eFriday;
        break;
    case 64:
        parsedWeek = eSaturday;
        break;
    default:
        break;
    }
    return parsedWeek;
}

/*============================================================================
** Function Name    :   RtcDrvCdd_Activate
**
** Visibility       :   Public
**
** Description      :   Activation for RTC driver
**
** Invocation       :   RtcIfCdd
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   No
**==========================================================================*/

Std_ReturnType RtcDrvCdd_Activate(void)
{
    Std_ReturnType retval = E_OK;
    return retval;
}


#ifdef RTC_ALARM_FUNCTIONALITY_ENABLED
/*============================================================================
** Function Name    :   RtcDrvCdd_SetAlarm
**
** Visibility       :   Public
**
** Description      :   Sets the alarm settings provided in the alarm structure
**
** Invocation       :   RtcIfCdd
**
** Inputs           :   Pointer to alarm configuration structure
**
** Outputs          :   Std_ReturnType E_OK if successful, E_NOT_OK otherwise
**
** Critical Section :   No
**==========================================================================*/

Std_ReturnType RtcDrvCdd_SetAlarm(const cRTCCDD_ALARM_TIME_TYPE* Alarm)
{
    Std_ReturnType RetVal = E_NOT_OK;

	// Hardware alarm precision is 1 minute
	if(Alarm->minute == 255U)
	{
		aTxBuffer[RA8804CE_BTC_ALARM_MIN] = RA8804CE_BTC_ALARM_AE;
	}
	else
	{
		aTxBuffer[RA8804CE_BTC_ALARM_MIN] = (uint8)HEX2BCD( Alarm->minute );
	}

	if(Alarm->hour == 255U)
	{
		aTxBuffer[RA8804CE_BTC_ALARM_HOUR] = RA8804CE_BTC_ALARM_AE;
	}
	else
	{
		aTxBuffer[RA8804CE_BTC_ALARM_HOUR] = (uint8)HEX2BCD( Alarm->hour );
	}

	if(Alarm->day == 255U)
	{
		aTxBuffer[RA8804CE_BTC_ALARM_WEEK_OR_DAY] = RA8804CE_BTC_ALARM_AE;
	}
	else
	{
		aTxBuffer[RA8804CE_BTC_ALARM_WEEK_OR_DAY] = HEX2BCD( Alarm->day );
	}

	// Clear AIE bit to disable interrupts from occurring while changing settings
	aTxBuffer[RA8804CE_BTC_CTRL] = I2c_CircularBuffer.I2c_RxBufferBTC[RA8804CE_BTC_CTRL] & (~RA8804CE_BTC_CTRL_AIE);
	RetVal = RtcDrvCdd_i2cWriteRegisters(RA8804CE_BTC_CTRL, &aTxBuffer[RA8804CE_BTC_CTRL], REGISTER_LENGTH, &I2c_CircularBuffer);

	if(E_OK == RetVal)
	{
		// Set current minute, hour, day alarm values
		RetVal =  RtcDrvCdd_i2cWriteRegisters(RA8804CE_BTC_ALARM_MIN, &aTxBuffer[RA8804CE_BTC_ALARM_MIN], ALARM_LENGTH, &I2c_CircularBuffer);
		if(E_OK == RetVal)
		{
			// Set AIE bit to make sure /INT pin gets pulled low when alarm triggers
			aTxBuffer[RA8804CE_BTC_CTRL] = I2c_CircularBuffer.I2c_RxBufferBTC[RA8804CE_BTC_CTRL] | RA8804CE_BTC_CTRL_AIE;
			RetVal = RtcDrvCdd_i2cWriteRegisters(RA8804CE_BTC_CTRL, &aTxBuffer[RA8804CE_BTC_CTRL], REGISTER_LENGTH, &I2c_CircularBuffer);
		}
	}

	return RetVal;
}

/*============================================================================
** Function Name    :   RtcDrvCdd_ClearAlarm
**
** Visibility       :   Public
**
** Description      :    Disables alarm interrupt function
**
** Invocation       :   RtcIfCdd
**
** Inputs           :   Pointer to alarm configuration structure
**
** Outputs          :   Std_ReturnType - E_OK if successful, E_NOT_OK otherwise
**
** Critical Section :   No
**==========================================================================*/

Std_ReturnType RtcDrvCdd_ClearAlarm(void)
{
    Std_ReturnType RetVal = E_NOT_OK;

	// Clear AIE bit in order to prevent /INT pin going low
	aTxBuffer[RA8804CE_BTC_CTRL] = I2c_CircularBuffer.I2c_RxBufferBTC[RA8804CE_BTC_CTRL] & (~RA8804CE_BTC_CTRL_AIE);
	RetVal = RtcDrvCdd_i2cWriteRegisters(RA8804CE_BTC_CTRL, &aTxBuffer[RA8804CE_BTC_CTRL], REGISTER_LENGTH, &I2c_CircularBuffer);

	if(E_OK == RetVal)
	{
		// Clear AF bit
		aTxBuffer[RA8804CE_BTC_FLAG] = I2c_CircularBuffer.I2c_RxBufferBTC[RA8804CE_BTC_FLAG] & (~RA8804CE_BTC_FLAG_AF);
		RetVal = RtcDrvCdd_i2cWriteRegisters(RA8804CE_BTC_FLAG, &aTxBuffer[RA8804CE_BTC_FLAG], REGISTER_LENGTH, &I2c_CircularBuffer);
	}

	return RetVal;
}

/*============================================================================
** Function Name    :   RtcDrvCdd_SetPeriodicAlarm
**
** Visibility       :   Public
**
** Description      :   Sets Fixed-cycle Timer for provided amount of time.
**
** Invocation       :   RtcIfCdd
**
** Inputs           :   Pointer to alarm configuration structure
**
** Outputs          :   Std_ReturnType - E_OK if successful, E_NOT_OK otherwise
**
** Critical Section :   No
**==========================================================================*/

Std_ReturnType RtcDrvCdd_SetPeriodicAlarm(const cRTCCDD_PERIODIC_ALARM_TIME_TYPE* p_alarm)
{
	Std_ReturnType ret = E_OK;
    return ret;
}

/*============================================================================
** Function Name    :   RtcDrvCdd_ClearPeriodicAlarm
**
** Visibility       :   Public
**
** Description      :   Stops fixed-cycle timer interrupt function.
**
** Invocation       :   RtcIfCdd
**
** Inputs           :   Pointer to alarm configuration structure
**
** Outputs          :   Std_ReturnType - E_OK if successful, E_NOT_OK otherwise
**
** Critical Section :   No
**==========================================================================*/

Std_ReturnType RtcDrvCdd_ClearPeriodicAlarm(void)
{
	Std_ReturnType ret = E_OK;
    return ret;
}

/*============================================================================
** Function Name    :   RtcDrvCdd_EnableAlarmNotification
**
** Visibility       :   Public
**
** Description      :   Enables alarm notifications.
**
** Invocation       :   RtcIfCdd
**
** Inputs           :   None
**
** Outputs          :   Std_ReturnType - E_OK if successful, E_NOT_OK otherwise
**
** Critical Section :   No
**==========================================================================*/

Std_ReturnType RtcDrvCdd_EnableAlarmNotification(void)
{
	Std_ReturnType ret = E_OK;
    return ret;
}

/*============================================================================
** Function Name    :   RtcDrvCdd_DisableAlarmNotification
**
** Visibility       :   Public
**
** Description      :   Disables alarm notifications.
**
** Invocation       :   RtcIfCdd
**
** Inputs           :   None
**
** Outputs          :   Std_ReturnType - E_OK if successful, E_NOT_OK otherwise
**
** Critical Section :   No
**==========================================================================*/

Std_ReturnType RtcDrvCdd_DisableAlarmNotification(void)
{
	Std_ReturnType ret = E_OK;
    return ret;
}

#endif

/*============================================================================
**
** Function Name    :   RtcCdd_I2cEndNotification
**
** Visibility       :   Public
**
** Description      :   Callback function for I2C sequence end.
**
** Invocation       :   I2C
**
** Inputs           :   uint8 sequence - Sequence ID
**                      uint8 busstate - Bus State
**                      uint8 sequencestate - Sequence State
**
** Outputs          :   None
**
** Critical Section :   Yes
**
**==========================================================================*/

void RtcCdd_I2cEndNotification(uint8 sequence, uint8 busstate, uint8 sequencestate)
{

}

#define RTCCCDD_SEC_CODE_START
#define RTCCDD_CORE_CONST_SEC_START
#define RTCCDD_CORE_DATA_SEC_START
#define RTCCDD_CORE_BSS_SEC_START

#include "MemMap.h"

#endif /* RTCDRVCDD_RA8804CE_C */

/*****************************************************************************
*     End of File
*
*******************************************************************************/
/****************************************************************************
*   for each change to this file, be sure to record:                        *
*      1.  who made the change and when the change was made                 *
*      2.  why the change was made and the intended result                  *
*   Following block needs to be repeated for each change                    *
*****************************************************************************/
/**-------------------------------------------------------------------------*/
/*Date              : 20-05-2025                                            */
/*Version           :                                                       */
/*By                : kporkodi                                              */
/*Traceability      :                                                       */
/*Change Description: Proveout, Initial Version                             */
/*--------------------------------------------------------------------------*/

