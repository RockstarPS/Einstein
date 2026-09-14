//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2015] Visteon Corporation
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

/*!********************************************************************************************************************
* @file TmExt_Timer.c
* @brief Implementation of Timer Start, Stop, ElapsedTime & Restart related functionalities.
* ********************************************************************************************************************/

/**********************************************************************************************************************
*  Include Files                                                                                                      *
*********************************************************************************************************************/
#include "Rte_TmExt.h"
#include "TmExt_Cfg.h"
#include "TmExt_Timer.h"
#include "TmExt_Cfg.h"
#include "Gpt.h"
#include "AssertLib.h"
#include "MemLib.h"


/**********************************************************************************************************************
*  Private Macros Definitions                                                                                         *                                                                                       *
**********************************************************************************************************************/
#define cTIMER16_COUNT      (eMaxNumof16BitTimers)
#define cTIMER32_OFFSET		((uint32)(cTIMER16_COUNT+(uint32)1))
#define cTIMER32_COUNT      ((uint32)eTimerMax - (uint32)cTIMER32_OFFSET)
#define cMAX_NUM_OF_TIMERS  250 /* lthanga1 - Increased for bx755 and s2dot8 program */

#define cU16_MAX             0xFFFFU
#define cU32_MAX             0xFFFFFFFFUL

#define cTIMER32_STOPPED     0UL
#define cTIMER16_STOPPED     0U

#define cSET_BIT             ((uint8)1)
#define BITS_IN_A_BYTE       ((uint8)8)
#define BITS_MASK_TO_7       ((uint8)7)
#define SIZE_OF_UINT8         255u
/*The maximum timeout mainly depends on "eTimerMax". Currently maximum of 200timers 
are allowed to achieve the maximum period support of 62535ms for 16bit timers and 4294965295ms for 32bit timers */
/* Below calculations are done for preventing the timer overflow and the max number of timers supported */
/* 16 bit timer max = 65535ms, residual time that cannot be achieved is 2000ms = eTimerMax * (uint16)TMEXT_MAINFUNCTION_PERIODICITY*/
/* so max timer that can be configured with 16-bit timer = 65535ms - 2000ms =  62535ms */
/* 32 bit timer max = 65535ms, residual time that cannot be achieved is 2000ms = eTimerMax * (uint16)TMEXT_MAINFUNCTION_PERIODICITY*/
/* so max timer that can be configured with 32-bit timer = 4294967295ms - 2000ms =  4294965295ms */
#define cTIMER16_MAX_PERIOD (cU16_MAX - ((uint16)eTimerMax * (uint16)TMEXT_MAINFUNCTION_PERIODICITY))
#define cTIMER32_MAX_PERIOD (cU32_MAX - ((uint32)eTimerMax * (uint32)TMEXT_MAINFUNCTION_PERIODICITY))

#ifndef cMAX_NUM_OF_TIMERS
#error cMAX_NUM_OF_TIMERS is not defined in TmExt_Cfg.h
#endif

#if (eTimerMax > cMAX_NUM_OF_TIMERS)
#error Number of timers configured exceed the maximum limit.
#endif

/**********************************************************************************************************************
*  Private Variable Definitions                                                                                       *
**********************************************************************************************************************/
#define TMEXT_DATA_SEC_START
#include "MemMap.h"
static uint16 Timer16[cTIMER16_COUNT];
static uint32 Timer32[cTIMER32_COUNT];
static HTimer CurrTimerId;
static uint8 Timer_Expiry_Status[((uint16)((eTimerMax) + (8 - ((uint16) ((eTimerMax-1)) & (uint16) 7))) >> 3)];
#define TMEXT_DATA_SEC_END
#include "MemMap.h"


#define TMEXT_CODE_SEC_START
#include "MemMap.h"
/*!********************************************************************************************************************

 @fn        TmExt_Timer32_Start

 @brief     Start a 32-bit Timer

 @param[in] TimerPtr - Pointer to store the timer starting position

 @return    None

**********************************************************************************************************************/
static void TmExt_Timer32_Start( uint32 * const TimerPtr )
{
    GET_SYSTEM_TIMER(TimerPtr);

    if( cTIMER32_STOPPED == *TimerPtr )
    {
        *TimerPtr = cU32_MAX;
    }
}

/*!********************************************************************************************************************

 @fn        TmExt_Timer32_Stop

 @brief     Stop a running 32-bit Timer

 @param[in] TimerPtr - Pointer to store the timer stopped status

 @return    None

**********************************************************************************************************************/
static void TmExt_Timer32_Stop( uint32 * const TimerPtr )
{
    *TimerPtr = cTIMER32_STOPPED;
}

/*!********************************************************************************************************************

 @fn        TmExt_Timer32_IsStarted

 @brief     To Check whether a 32-bit Timer has already started

 @param[in] Timer - Timer Id

 @return    boolean TRUE - Timer has started, FALSE - Timer has not started

**********************************************************************************************************************/
static boolean TmExt_Timer32_IsStarted( const uint32 Timer )
{
    boolean IsStarted = (boolean)FALSE;

    if( cTIMER32_STOPPED != Timer )
    {
    	IsStarted = (boolean)TRUE;
    }

    return IsStarted;
}

/*!********************************************************************************************************************

 @fn        TmExt_Timer32_IsElapsed

 @brief     To Check whether a 32-bit Timer has elapsed by the specified timeout period

 @param[in] Timer - Timer Id

 @param[in] Timer - Timeout - Timeout in ms

 @return    boolean TRUE - Timer is elapsed, FALSE - Timer is not elapsed

**********************************************************************************************************************/
static boolean TmExt_Timer32_IsElapsed( const uint32 Timer, const uint32 Timeout )
{
    uint32 Delay = 0U;
    uint32 SysTimer;
    boolean IsElapsed = (boolean)FALSE;

    GET_SYSTEM_TIMER(&SysTimer);

    if( cTIMER32_STOPPED != Timer )
    {
		if( SysTimer > Timer ) 
		{         
			Delay = (uint32)( SysTimer - Timer );
		}

        if( SysTimer < Timer )
        {
			if(Delay != 0u)
			{
            // The 0 value has been passed, decrement the delay.
			Delay = Delay - 1U;
			}			
        }

        if(Delay >= Timeout)
        {
        	IsElapsed = (boolean)TRUE;
        }
    }

    return IsElapsed;
}

/*!********************************************************************************************************************

 @fn        TmExt_Timer32_GetElapsedTime

 @brief     To get the elapsed timeout period in milliseconds from the timer starting period

 @param[in] Timer - Timer Id

 @return    uint32 Elapsed Timeout period in milliseconds

**********************************************************************************************************************/
static uint32 TmExt_Timer32_GetElapsedTime( const uint32 Timer )
{
    uint32 ElapsedTime = cTIMER32_STOPPED;
    uint32 SysTimer;

    GET_SYSTEM_TIMER(&SysTimer);

    if( cTIMER32_STOPPED != Timer )
    {
		if(SysTimer > Timer) 
		{
			ElapsedTime = (uint32)( SysTimer - Timer );
		}
		else 
		{
			DEBUG_ASSERT(FALSE);
		}			

        if( SysTimer < Timer )
        {
            // The 0 value has been passed, decrement the elapsed value.
			if( ElapsedTime > 0u) 
			{          
				ElapsedTime--;
			}
			else
			{
				DEBUG_ASSERT(FALSE);
			}
        }
    }

    return ElapsedTime;
}

/*!********************************************************************************************************************

 @fn        TmExt_Timer16_Start

 @brief     Start a 16-bit Timer

 @param[in] TimerPtr - Pointer to store the timer starting position

 @return    None

**********************************************************************************************************************/
static void TmExt_Timer16_Start( uint16 * const TimerPtr )
{
    uint32 TimerPtr32;
    GET_SYSTEM_TIMER(&TimerPtr32);
    *TimerPtr = (uint16)TimerPtr32;

    if( cTIMER16_STOPPED == *TimerPtr )
    {
        *TimerPtr = cU16_MAX;
    }
}

/*!********************************************************************************************************************

 @fn        TmExt_Timer16_Stop

 @brief     Stop a 16-bit Timer

 @param[in] TimerPtr - Pointer to store the timer stopped status

 @return    None

**********************************************************************************************************************/
static void TmExt_Timer16_Stop( uint16 * const TimerPtr )
{
    *TimerPtr = cTIMER16_STOPPED;
}

/*!********************************************************************************************************************

 @fn        TmExt_Timer16_IsStarted

 @brief     To Check whether a 16-bit Timer has already started

 @param[in] Timer - Timer Id

 @return    boolean TRUE - Timer has started, FALSE - Timer has not started

**********************************************************************************************************************/
static boolean TmExt_Timer16_IsStarted( const uint16 Timer )
{
    boolean IsStarted= (boolean)FALSE;

    if( cTIMER16_STOPPED != Timer )
    {
    	IsStarted = (boolean)TRUE;
    }

    return IsStarted;
}

/*!********************************************************************************************************************

 @fn        TmExt_Timer16_IsElapsed

 @brief     To Check whether a 16-bit Timer has elapsed by the specified timeout period

 @param[in] Timer - Timer Id

 @param[in] Timer - Timeout - Timeout in ms

 @return    boolean TRUE - Timer is elapsed, FALSE - Timer is not elapsed

**********************************************************************************************************************/
static boolean TmExt_Timer16_IsElapsed( const uint16 Timer, const uint16 Timeout )
{
    uint16 Delay;
    boolean IsElapsed = (boolean)FALSE;

    uint16 SysTimer;
    uint32 TimerPtr32;
    GET_SYSTEM_TIMER(&TimerPtr32);
    SysTimer = (uint16)TimerPtr32;

    if( cTIMER16_STOPPED != Timer )
    {
        Delay = ( SysTimer - Timer );

        if( SysTimer < Timer )
        {
            // The 0 value has been passed, decrement the delay.
			Delay = Delay -1U;  
        }

        if( Delay >= Timeout )
        {
        	IsElapsed = (boolean)TRUE;
        }
    }

    return IsElapsed;
}

/*!********************************************************************************************************************

 @fn        TmExt_Timer16_GetElapsedTime

 @brief     To get the elapsed timeout period in milliseconds from the timer starting period

 @param[in] Timer - Timer Id

 @return    uint16 Elapsed Timeout period in milliseconds

**********************************************************************************************************************/
static uint16 TmExt_Timer16_GetElapsedTime( const uint16 Timer )
{
    uint16 ElapsedTime = cTIMER16_STOPPED;

    uint16 SysTimer;
    uint32 TimerPtr32;
    GET_SYSTEM_TIMER(&TimerPtr32);
    SysTimer = (uint16)TimerPtr32;

    if( cTIMER16_STOPPED != Timer )
    {
        ElapsedTime = (uint16)( SysTimer - Timer );

        if( SysTimer < Timer )
        {
            // The 0 value has been passed, decrement the elapsed value.
			ElapsedTime = ElapsedTime - 1U;   
        }
    }

    return ElapsedTime;
}


/*!********************************************************************************************************************

 @fn        TmExt_Timer_IsExpired

 @brief     To check whether the specified timer has expired by its maximum period

 @param[in] hTimer - Timer Id

 @return    boolean TRUE-Timer has expired, FALSE-Timer has not expired

**********************************************************************************************************************/
static boolean TmExt_Timer_IsExpired(const HTimer hTimer)
{
	boolean IsExpired = (boolean)FALSE;
	boolean IsTimerStarted = (boolean)FALSE;
	uint8 Timerexpstatus = 0;
	uint16 TimerPos;
	uint16 htimerIndex;
	
	htimerIndex = (hTimer/BITS_IN_A_BYTE);

    TmExt_Timer_IsStarted(hTimer, &IsTimerStarted);
    if(IsTimerStarted != (boolean)FALSE)
    {
        TimerPos = (hTimer - (uint16)(htimerIndex * BITS_IN_A_BYTE));
		if(htimerIndex < ((uint16)((eTimerMax) + (8u - ((uint16) ((eTimerMax-1U)) & (uint16) 7U))) >> 3U))
		{
        Timerexpstatus = Timer_Expiry_Status[htimerIndex];
        }
		if(Timerexpstatus < SIZE_OF_UINT8)
		{
		Timerexpstatus = Timerexpstatus >> TimerPos;
		}
        if((Timerexpstatus & cSET_BIT) ==  cSET_BIT)
        {
        	IsExpired = (boolean)TRUE;
        }
    }
    return IsExpired;
}

/*!********************************************************************************************************************

 @fn        TmExt_Timer_UpdateTimerExpiredStatus

 @brief     Check and update the timer expired status for the given timer

 @param[in] hTimer - Timer Id

 @return    None

**********************************************************************************************************************/
static void TmExt_Timer_UpdateTimerExpiredStatus(const HTimer hTimer)
{
	boolean IsTimerStarted = (boolean)FALSE;
	boolean IsElapsed = (boolean)FALSE;

    //check whether timer has not yet expired and then find the expired status
    if((TmExt_Timer_IsExpired(hTimer)) == (boolean)FALSE)
    {
        TmExt_Timer_IsStarted(hTimer, &IsTimerStarted);
        if(IsTimerStarted != (boolean)FALSE)
        {
            if( hTimer < cTIMER16_COUNT )
            {
                IsElapsed = TmExt_Timer16_IsElapsed( Timer16[hTimer], (uint16)cTIMER16_MAX_PERIOD );
            }
            else if((hTimer > cTIMER16_COUNT) && ( hTimer < (uint32)eTimerMax ))
            {
            	IsElapsed = TmExt_Timer32_IsElapsed( Timer32[hTimer - (uint32)cTIMER32_OFFSET], (uint32)cTIMER32_MAX_PERIOD );
            }
			else
			{
				//Else condition is added to solve Misra warning 10447248 MISRA C-2012 Rule 15.7
			}
        }
        if(IsElapsed != (boolean)FALSE)
        {
        	Timer_Expiry_Status[(hTimer/8U)] |= ((uint8)(cSET_BIT << (((uint8)hTimer) & BITS_MASK_TO_7)));/* Set timer expiry status */
        }
    }
}



/*!********************************************************************************************************************

 @fn        TmExt_Timer_Init

 @brief     This method Initialize TmExt module

 @param[in] None

 @return    None

**********************************************************************************************************************/
void TmExt_Timer_Init( void )
{
    uint32 Ix;

    Gpt_StartTimer( cGPT_TIMER, cTIMER_ROLLOVER_VALUE);

    for( Ix = 0UL; Ix < cTIMER16_COUNT; Ix++)
    {
        Timer16[Ix] = cTIMER16_STOPPED;
    }

    for( Ix = 0UL; Ix < cTIMER32_COUNT; Ix++)
    {
        Timer32[Ix] = cTIMER32_STOPPED;
    }
    CurrTimerId = 0U;
    /* Clear timer expiry status of all the timers */
    (void)MemLib_MemSet(&Timer_Expiry_Status,(uint8)0x00,(uint8)sizeof(Timer_Expiry_Status));
}

/*!********************************************************************************************************************

 @fn        TmExt_Timer_Start

 @brief     This method is used to start a timer

 @param[in] hTimer - Timer Id

 @return    None

**********************************************************************************************************************/
void TmExt_Timer_Start( const HTimer hTimer )
{
    if( hTimer < cTIMER16_COUNT )
    {
        /* Clear timer expire status before start */
    	Timer_Expiry_Status[(hTimer/8U)] &= ((uint8)(~((uint8)(cSET_BIT << (((uint8)hTimer) & BITS_MASK_TO_7)))));
        TmExt_Timer16_Start( &Timer16[hTimer] );
    }
    else if((hTimer > cTIMER16_COUNT) && ( hTimer < (uint32)eTimerMax ))
    {
    	/* Clear timer expire status before start */
    	Timer_Expiry_Status[(hTimer/8U)] &= ((uint8)(~((uint8)(cSET_BIT << (((uint8)hTimer) & BITS_MASK_TO_7)))));
        TmExt_Timer32_Start( &Timer32[hTimer - cTIMER32_OFFSET] );
    }
    else
    {
        DEBUG_ASSERT(FALSE);
    }
}

/*!********************************************************************************************************************

 @fn        TmExt_Timer_Stop

 @brief     This method is used to stop a timer

 @param[in] hTimer - Timer Id

 @return    None

**********************************************************************************************************************/
void TmExt_Timer_Stop( const HTimer hTimer )
{
    if( hTimer < cTIMER16_COUNT )
    {
        TmExt_Timer16_Stop( &Timer16[hTimer] );
        /* Clear timer expire status */
        Timer_Expiry_Status[(hTimer/8U)] &= ((uint8)(~((uint8)(cSET_BIT << (((uint8)hTimer) & BITS_MASK_TO_7)))));
    }
    else if((hTimer > cTIMER16_COUNT) && ( hTimer < (uint32)eTimerMax ))
    {
        TmExt_Timer32_Stop( &Timer32[hTimer - cTIMER32_OFFSET] );
        /* Clear timer expire status */
        Timer_Expiry_Status[(hTimer/8U)] &= ((uint8)(~((uint8)(cSET_BIT << (((uint8)hTimer) & BITS_MASK_TO_7)))));
    }
    else
    {
        DEBUG_ASSERT(FALSE);
    }
}

/*!********************************************************************************************************************

 @fn        TmExt_Timer_IsStarted

 @brief     This method is used to check whether Timer has already started

 @param[in] Timer - Timer Id

 @param[in] *IsStarted - Pointer to get the timer started status

 @return    None

**********************************************************************************************************************/
void TmExt_Timer_IsStarted(const HTimer hTimer, boolean* IsStarted)
{
    if( hTimer < cTIMER16_COUNT )
    {
    	*IsStarted = TmExt_Timer16_IsStarted( Timer16[hTimer] );
    }
    else if((hTimer > cTIMER16_COUNT) && ( hTimer < (uint32)eTimerMax ))
    {
    	*IsStarted = TmExt_Timer32_IsStarted( Timer32[hTimer - cTIMER32_OFFSET] );
    }
    else
    {
        DEBUG_ASSERT(FALSE);
    }

}

/*!********************************************************************************************************************

 @fn        TmExt_Timer_IsElapsed

 @brief     This method is used to check whether a Timer has elapsed by the specified timeout period

 @param[in] hTimer - Timer Id

 @param[in] Timeout - Timeout in ms

 @param[in] *IsElapsed - Pointer to get the timer elapsed status

 @return    None

**********************************************************************************************************************/
void TmExt_Timer_IsElapsed( const HTimer hTimer, const uint32 Timeout, boolean* IsElapsed )
{
    //check whether timer has not yet expired. If timer has expired, then its maximum period is elapsed
    if((TmExt_Timer_IsExpired(hTimer)) != (boolean)FALSE)
    {
    	*IsElapsed = (boolean)TRUE;
    }
    else
    {
        if( hTimer < cTIMER16_COUNT )
        {
            *IsElapsed = TmExt_Timer16_IsElapsed( Timer16[hTimer], (uint16)Timeout );
        }
        else if((hTimer > cTIMER16_COUNT) && ( hTimer < (uint32)eTimerMax ))
        {
        	*IsElapsed = TmExt_Timer32_IsElapsed( Timer32[hTimer - cTIMER32_OFFSET], Timeout );
        }
        else
        {
            DEBUG_ASSERT(FALSE);
        }
    }

}

/*!********************************************************************************************************************

 @fn        TmExt_Timer_IsElapsedRestart

 @brief     This method is used to check whether a Timer has restarted after the specified timeout elapsed

 @param[in] hTimer - Timer Id

 @param[in] Timer - Timeout - Timeout in ms

 @param[in] *IsElapsed - Pointer to get the timer elapsed restart status

 @return    None

**********************************************************************************************************************/
void TmExt_Timer_IsElapsedRestart ( const HTimer hTimer, const uint32 Timeout, boolean* IsElapsed )
{
    //check whether timer has not yet expired. If timer has expired, then its maximum period is elapsed
    if((TmExt_Timer_IsExpired(hTimer)) != (boolean)FALSE)
    {
    	*IsElapsed = (boolean)TRUE;
    	if( hTimer < cTIMER16_COUNT )
    	{
				Timer16[hTimer] = Timer16[hTimer] + (uint16)Timeout;    
    		/* Clear timer expire status */
    		Timer_Expiry_Status[(hTimer/8U)] &= ((uint8)(~((uint8)(cSET_BIT << (((uint8)hTimer) & BITS_MASK_TO_7)))));
    	}
    	else if((hTimer > cTIMER16_COUNT) && ( hTimer < (uint32)eTimerMax ))
    	{
			Timer32[hTimer - cTIMER32_OFFSET] = Timer32[hTimer - cTIMER32_OFFSET] + Timeout;   
    		/* Clear timer expire status */
    		Timer_Expiry_Status[(hTimer/8U)] &= ((uint8)(~((uint8)(cSET_BIT << (((uint8)hTimer) & BITS_MASK_TO_7)))));
    	}
    	else
    	{
    	    DEBUG_ASSERT(FALSE);
    	}
    }
    else
    {
        if( hTimer < cTIMER16_COUNT )
        {
            *IsElapsed = TmExt_Timer16_IsElapsed( Timer16[hTimer], (uint16)Timeout );
            // Time is passed so restarts the timer from the point of expiration.
            if ( (boolean)FALSE != *IsElapsed )
            {
				Timer16[hTimer] = Timer16[hTimer] + (uint16)Timeout;   
            }
        }
        else if((hTimer > cTIMER16_COUNT) && ( hTimer < (uint32)eTimerMax ))
        {
            *IsElapsed = TmExt_Timer32_IsElapsed( Timer32[hTimer - cTIMER32_OFFSET], Timeout );
            // Time is passed so restarts the timer from the point of expiration.
            if ( (boolean)FALSE != *IsElapsed )
            {
                Timer32[hTimer - cTIMER32_OFFSET] += Timeout;
            }
        }
        else
        {
            DEBUG_ASSERT(FALSE);
        }
    }


}

/*!********************************************************************************************************************

 @fn        TmExt_Timer_GetElapsedTime

 @brief     This method is used to get the elapsed timeout period in milliseconds from the timer starting period

 @param[in] hTimer - Timer Id

 @param[in] *ElapsedTime - Pointer to get the Elapsed Timeout period in milliseconds

 @return    None

**********************************************************************************************************************/
void TmExt_Timer_GetElapsedTime( const HTimer hTimer, uint32* ElapsedTime )
{
    if( hTimer < cTIMER16_COUNT )
    {
        //check whether timer has not yet expired. If timer has expired, then its maximum period is elapsed
    	if((TmExt_Timer_IsExpired(hTimer)) != (boolean)FALSE)
        {
        	*ElapsedTime = (uint32)cTIMER16_MAX_PERIOD;
        }
        else
        {
            *ElapsedTime = TmExt_Timer16_GetElapsedTime( Timer16[hTimer] );
        }
    }
    else if((hTimer > cTIMER16_COUNT) && ( hTimer < (uint32)eTimerMax ))
    {
        //check whether timer has not yet expired. If timer has expired, then its maximum period is elapsed
    	if((TmExt_Timer_IsExpired(hTimer)) != (boolean)FALSE)
        {
        	*ElapsedTime = (uint32)cTIMER32_MAX_PERIOD;
        }
        else
        {
            *ElapsedTime = TmExt_Timer32_GetElapsedTime( Timer32[hTimer - cTIMER32_OFFSET] );
        }
    }
    else
    {
        DEBUG_ASSERT(FALSE);
    }
}

/*!********************************************************************************************************************

 @fn        TmExt_Timer_UpdateExpiredStatus

 @brief     This method checks and update the timer expired status periodically for all the running timers.

 @param[in] None

 @return    None

**********************************************************************************************************************/
void TmExt_Timer_UpdateExpiredStatus(void)
{
	CurrTimerId = CurrTimerId + 1U;  
    if(CurrTimerId >= eTimerMax)
    {
        CurrTimerId = 0U;
    }
    else if(CurrTimerId == cTIMER16_COUNT)
    {
    	CurrTimerId++;
    }
	else
	{
		//Else condition is added in order to solve Misra warning 10449052 MISRA C-2012 Rule 15.7
	}
    TmExt_Timer_UpdateTimerExpiredStatus(CurrTimerId);

}

#define TMEXT_CODE_SEC_END
#include "MemMap.h"

/*---------------------------------------------------------------------------
Date              : 11-May-2018
CDSID             : asivalin
Traceability      : RTC-1109220, 1199221, 1116707, 1116694
Change Description: Timer Elapsed Defectes Fix & QAC, Coverity Warnings Fix and doxygen documentation.
Version           : 3:turing_bsw_tmext_0.2
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 12-Jun-2018
CDSID             : gnataraj
Traceability      : RTC-1133830
Change Description: Coverity and MISRA Warnings Fix and removed cCLEAR_BIT from the file.
Version           : 3:turing_bsw_tmext_0.2
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 25-Oct-2018
CDSID             : bjayara2
Traceability      : RTC-1225014
Change Description: Increased the maximum number of timers to be supported from 100 to 200
Version           : turing_bsw_tmext_0.2.3
-----------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------
Date              : 27-03-2022                                              
Version           :                                                       
By                : gthanapp                                              
Traceability      : RTC#1564070                                           
Change Description: Cert-C warning analysis and fix                       
----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 1-Mar-2023
CDSID             : gthanapp
Traceability      : RTC-1928662
Change Description: Misra and certc warning fix
Version           : turing_bsw_tmext_0.12
-----------------------------------------------------------------------------*/
