/****************************************************************************

                      CONFIDENTIAL - Visteon

  This is unpublished work, which is a trade secret, created in 2000.
  Visteon owns all rights to this work and intends to
  maintain it in confidence to preserve its trade secret status.
  Visteon reserves the right to protect this work as an unpublished
  copyrighted work in the event of an inadvertent or deliberate
  unauthorized publication.  Visteon also reserves its right
  under the copyright laws to protect this work as a published work.
  Those having access to this work may not copy it, use it, or disclose
  the information contained in it without the written authorization of
  Visteon.

                   Copyright 2000 - 2004 Visteon

****************************************************************************/
/****************************************************************************

NAME:         swtmr.h

DESCRIPTION:  This file specifies the public interface to software timers as
              provided by the kernel.

              Software timers allow intervals to be timed.  Three services
              are provided to control timers: KernelStart13BitTimer,
              KernelCheck13BitTimer, and KernelClear13BitTimer.

              The time interval begins when the KernelStart13BitTimer service is
              called (which puts the timer in the TIMER_RUNNING state).  The
              KernelCheck13BitTimer service is then used to determine when the timer
              has expired.  Before the timer expires, KernelCheck13BitTimer will
              return TIMER_RUNNING each time it is called.  The first time
              KernelCheck13BitTimer is called after expiration of the timer,
              TIMER_EXPIRED is returned.  As a side effect of returning
              TIMER_EXPIRED, KernelCheck13BitTimer sets the state of the timer to
              TIMER_CLEAR.  A timer in the TIMER_CLEAR state will remain so
              until the KernelStart13BitTimer is used to start the timer.  When
              in the TIMER_CLEAR state, KernelCheck13BitTimer will return
              TIMER_CLEAR.  The KernelClear13BitTimer service can be used at any
              time to immediately set the timer state to TIMER_CLEAR.

              Timers are explicitly initialized to the TIMER_CLEAR state during
              cold initialization (this is the only time the kernel initializes
              software timers).

   NOTE:      Proper operation of the KernelStart13BitTimer and KernelCheck13BitTimer
              services requires strict adherance to the following rules (FAILURE
              TO ADHERE TO THESE RULES WILL RESULT IN UNDEFINED BEHAVIOR):

              1. The interval to be timed CANNOT exceed (2 power(13)*timer_base).
              For example, when using TIMER_13BIT_BASE_4MS, the interval cannot
              exceed 32768 milliseconds.

              2.  Consecutive calls to the Check13BitTimerService CANNOT exceed
              (2 power(13)*timer_base).  For example, when using TIMER_13BIT_BASE_4MS,
              the interval cannot exceed 32768 milliseconds.

              The expiration time of a software timers is always within the
              following range.

              [timer_base * (timeout_time-1)] < [expiration time]
              [expiration time]               < [timer_base * (timeout_time]

              Thus, if a TIMER_13BIT_BASE_4MS timer is started with timeout_time=100,
              the expiration time will be between 396 and 400 milliseconds.


   EXAMPLE:   Turn on a warning LED for 256 milliseconds using a 4 millisecond
              timer when a warning condition is detected.  If an over voltage
              condition is detected, the LED must be immediately turned off.  The
              software timer must be allocated by placing "led_timer_KSWTIMER" in the
              "PROD_SPEC_SW_TIMERS" configuration item in the "swtmr.cfg" file.

              #include "swtmr.h"

              #define  LED_ON_TIME        64      ; 64*4=256ms


              if (Warning_Condition_Detected() == TRUE)
              {
                Turn_ON_Warning_LED();
                KernelStart13BitTimer(TIMER_13BIT_BASE_4MS, LED_ON_TIME, led_timer_KSWTIMER);
              }

              if (Over_Voltage_Shutdown() == TRUE)
              {
                Turn_OFF_Warning_LED();
                KernelClear13BitTimer(led_timer_KSWTIMER);
              }

              if (KernelCheck13BitTimer(led_timer_KSWTIMER) == TIMER_EXPIRED)
              {
                Turn_OFF_Warning_LED();
              }


ORGANIZATION: Driver Information Software Section,

DOCUMENTATION: See bottom of file.


$Revision:   1.32  $

*******************************************************************************/
#ifndef SWTMR_H
#define SWTMR_H

/***************************************************************************
                I N C L U D E   F I L E S
***************************************************************************/
#include "system.h"
#include "swtmr.cfg"

#ifndef SWTMR_C
    #define EXTERN_pfx extern
#else
    #define EXTERN_pfx
#endif
/***************************************************************************
   P U B L I C   M A C R O   A N D   T Y P E   D E F I N I T I O N S
***************************************************************************/
typedef UWORD TIMER;

typedef enum
{
    PROD_SPEC_SW_TIMERS,
    MAX_SW_TIMER_ID
} SWTIMERS;


/*
** Values returned from KernelCheck13BitTimer().
*/
#define   TIMER_CLEAR           0x00
#define   TIMER_EXPIRED         0x02
#define   TIMER_RUNNING         0x80

/*
** Valid values for timer base for the KernelStart13BitTimer() service.
*/
#define TIMER_13BIT_BASE_4MS    ((UWORD)0x0000u)
#define TIMER_13BIT_BASE_512MS  ((UWORD)0x8000u)

/*
**  Determine most significant byte position which is different for
**  little endian versus big endian storage schemes.   Needed so that
**  the TIMER_STATE_RUNNING_BIT we can be cleared with a single byte
**  write in the KernelClear13BitTimer service.
*/
EXTERN_pfx const UINT16 c_endian_flag_u16;
#define MSB_OFFSET (*(UINT8*)&c_endian_flag_u16)

EXTERN_pfx FAR TIMER kernel_sw_timers[ MAX_SW_TIMER_ID ] ;

/***************************************************************************
   P U B L I C   D A T A   A N D   A C C E S S   M A C R O S
***************************************************************************/

/*----------------------------------------------------------------------------*/
/* NAME: KernelStart13Timer                                                   */
/*----------------------------------------------------------------------------*/
/* DESCRITION:  Starts a software timer.                                      */
/*                                                                            */
/* INPUTS:      timer_base - the base resolution for the timer (must be       */
/*                           either TIMER_13BIT_BASE_4MS or                   */
/*                           TIMER_13BIT_BASE_512MS).                         */
/*              timeout - 13-bit value indicating amount of time before timer */
/*                        is to expire.                                       */
/*              timer_id - the id of the timer to start.  The id must be      */
/*                         the name of a software timer configured in the     */
/*                         PROD_SPEC_SW_TIMERS configuration item in the      */
/*                         swtmr.cfg file.                                    */
/* OUTPUTS:     NONE.                                                         */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#define  KernelStart13BitTimer(timer_base, timeout, timer_id) \
        _KernelStart13BitTimer(((timer_base) | (timeout)), timer_id)


/*----------------------------------------------------------------------------*/
/* NAME: KernelCheck13BitTimer                                                */
/*----------------------------------------------------------------------------*/
/* DESCRITION:  Checks then returns the state of the specified timer          */
/*              state.                                                        */
/*                                                                            */
/* INPUTS:      timer_id - the id of the timer to check.  The id must be      */
/*                         the name of a software timer configured in the     */
/*                         PROD_SPEC_SW_TIMERS configuration item in the      */
/*                         swtmr.cfg file.                                    */
/*                                                                            */
/* OUTPUTS:     NONE.                                                         */
/*                                                                            */
/* RETURNS:     One of the following values:                                  */
/*                                                                            */
/*              TIMER_CLEAR - timer is not running.                           */
/*                                                                            */
/*              TIMER_RUNNING - timer has been started but has not yet        */
/*                              expired.                                      */
/*                                                                            */
/*              TIMER_EXPIRED - timer has expired.                            */
/*                                                                            */
/* NOTE:        When 'EXPIRED' is returned, the timer is automatically        */
/*              cleared, so that subsequent calls to KernelCheckTimer         */
/*              (without calling KernelStartTimer first) will return          */
/*              TIMER_CLEAR.                                                  */
/*                                                                            */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#define  KernelCheck13BitTimer(timer_id) \
        _KernelCheck13BitTimer(timer_id)


/*----------------------------------------------------------------------------*/
/* NAME: KernelClear13BitTimer                                                */
/*----------------------------------------------------------------------------*/
/* DESCRITION:  Clears (stops) a timer by putting it in the TIMER_CLEAR       */
/*              state.                                                        */
/*                                                                            */
/* INPUTS:      timer_id - the id of the timer to clear.  The id must be      */
/*                         the name of a software timer configured in the     */
/*                         PROD_SPEC_SW_TIMERS configuration item in the      */
/*                         swtmr.cfg file.                                    */
/*                                                                            */
/* OUTPUTS:     NONE.                                                         */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*
#define  KernelClear13BitTimer(timer_id) \
           *(&((UBYTE *)(void *) &kernel_sw_timers[0])[(timer_id*2)+ MSB_OFFSET]) = 0

*/
#define  KernelClear13BitTimer(timer_id) \
            kernel_sw_timers[timer_id] = 0

/*
**  Set the timer to the TIMER_CLEAR state by clearing the TIMER_STATE_RUNNING
**  bit (which is stored in the MSByte  of the timer).  Clearing only the MSByte is
**  done for two reasons: (1) Less ROM/faster execution time to write to a
**  single byte instead of two bytes, and (2) no critical section protocol is
**  needed when writing to a single byte (if two bytes are written can't assume
**  order they are written so need critical section protocol).
**
*/

/***************************************************************************
   P U B L I C   F U N C T I O N   P R O T O T Y P E S
***************************************************************************/

EXTERN_pfx FARFUNC void  _KernelStart13BitTimer(UWORD timeout_time, UBYTE timer_id);
EXTERN_pfx FARFUNC UBYTE _KernelCheck13BitTimer(UBYTE timer_id);

/*******************************************************************************

============================================================================
 P V C S     R E V I S I O N     N O T E S
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
For each change to this file, be sure to record:
1.   Who made the change and when the change was made.
2.   Why the change was made and the intended result.

Date       By     Reason For Change
mmm/dd/yy  XXX    -----------------

----------------------------------------------------------------------------
PVCS Rev 1.0

May/12/97   GEP   Initial Revision

PVCS Rev 1.1

May/20/97   GEP   Added support for 2048ms software timer.

                  to UBYTE (for portability).

PVCS Rev 1.2

Sep/10/97   GEP   Added support for new software timers...after analysis put

PVCS Rev 1.3

Mar/09/98   GEP   Changed return type for KernelCheck13BitTimer from TIMER_STATE
                  conditional compile statements...may implement later.

PVCS Rev 1.4

Mar/28/98   GEP   Changes for coding standards.

PVCS Rev 1.5

Jun/17/98   GEP   Removed "Automotive Components Division" from file comment block.

PVCS Rev 1.6

Aug/18/98   GEP   Complete re-write for 13-bit timer services.

PVCS Rev 1.7

Aug/25/98   GEP   Added "buss_off_timer_KSWTIMER" for the CAN NOS.


PVCS Rev 1.8

Aug/26/98   GEP   Removed type casts for TIMER_13BIT_BASE_4MS and TIMER_13_BIT_BASE512MS
                  (this was causing a compiler error for TMS370 in diagmain.c).

PVCS Rev 1.9

Aug/28/98   GEP   Changed KernelClear13BitTimer to clear only the byte of the timer
                  which has the "running" bit.

PVCS Rev 1.10

Feb/11/99  WFD    Added support for combined can/scp NOS

PVCS Rev 1.11

Mar/05/99  GEP    Use PROD_SPEC_BIG_ENDIAN_FORMAT to determine if system is big
                  or little endian instead of decoding TARGET_ID.

PVCS Rev 1.12

Mar/20/99  WFD    Revised support for combined can/scp NOS

PVCS Rev 1.13

Apr/24/99  GEP    Added conditional compilation to support for
                  "diag_secured_access_KSWTIMER" for Jaguar diagnostics sub-system.

PVCS Rev 1.14

Jun/07/99  WFD    Added support for SCP/UBP NOS

PVCS Rev 1.15

Jun/23/99  GEP    Removed semi-colon from the KernelClear13BitTimer macro (which
                  was extraneous since the application provides a semi-colon).

PVCS Rev 1.16

Jun/26/99  WFD    Revised support for SCP/UBP NOS

PVCS Rev 1.17

Sep/24/99   GEP   Updated for banking...added FARFUNC qualifier.

PVCS Rev 1.18

Feb/18/00   GEP   Added "cantpe_wait_fc_frame_KSWTIMER" via conditional compile for
                  CAN diagnostics support.
Mar/03/00   GEP   Added "diag_dtc_aging_KSWTIMER" via conditional compile for Fiat
                  diagnostics support.
Mar/06/00   GEP   Added "ioctl_abort_KSWTIMER" via conditional compile for Fiat
                  diagnostics support.

PVCS Rev 1.19

Jul/31/00  LSX    Added "PROD_SPEC_ENABLE_DIAGNOSTICS_SUBSYSTEM == 7" to condition
                  check of "diag_secured_access_KSWTIMER" for jaguar diagnotics
                  procotol over CAN (segmented).

PVCS Rev 1.20

Jan/22/2001  WFD    Added support for the CAN/UBP NOS

PVCS Rev 1.21

Jun/08/2001  LSX  Added support for the Ford Generic CAN Diag Subsystem.

PVCS Rev 1.22

Aug/02/2001  WFD  Added support for CAN only version of CAN/UBP NOS

PVCS Rev 1.23

Aug/06/2001  LSX  Added self_test_busy_timer_KSWTIMER for supporting the Ford
                 Generic CAN Diag Subsystem.

PVCS Rev 1.24

Sep/27/2001  LSX  Added support for GM Class2 Diagnostics.

PVCS Rev 1.25

Dec/03/2001  LSX  Removed timers for KDS-04 (FORK).

PVCS Rev 1.26

Aug/29/2002  GEP  Minor modifications to remove QAC warnings (changes cause no s-record change).

PVCS Rev 1.27

Oct/14/2002  GEP  Minor modifications to remove QAC warnings (add type casts).

PVCS Rev 1.28

Apr/22/03    WFD  Added support for the CAN/CAN NOS (PROD_SPEC_ENABLE_NOS_SUBSYSTEM = 12)


PVCS Rev 1.29
SEP/02/2003  SKHAN17   Added declaration for timer 'IOCtl_timer_KSWTIMER'
                       for Nissan Consult II Diagnostics Subsystem
                       (IO Control By LID Service).

PVCS Rev 1.30
Oct/09/2003  SKHAN17   Added declaration for timers 'diag_iolid_KSWTIMER' &
                      'daig_ecureset_KSWTIMER' for Honda Diagnostic Subsystem.

PVCS Rev 1.31
Nov/13/2003  SKHAN17   Removed the timer declaration for 'IOCtl_timer_KSWTIMER'
                       as 'IO Control by LID' service is not supported for
                       Nissan Consult-II Diagnostics any more.

PVCS Rev 1.32
Nov/19/2003  GPALARSK  Changed the definition of "KernelClear13BitTimer" to fix
                       a defect (this defect was present only on little endian
                       processors).

CCASE Rev main/34
Apr/22/2004  SKHAN17   Added the time declaration for "diag_stmin_KSWTIMER" to
                       support handling of STMin timeout for the flow control
                       frames in NISSAN CONSULT-II Diagnostics.

CCASE Rev main/35
Jun/22/2004  SKHAN17   Added declaration for 'daig_ecureset_KSWTIMER' for
                       Ford GGDS Diagnostic Subsystem.

CCASE Rev main/36
Aug/11/2004 BVISWANA  Added declaration for 'reset_ecu_on_serv11_KSWTIMER' for
                      Ford CAN Generic Diagnostic specification V2003.0

CC rev main/40
aug/27/2004 mraisky  added conditional include for "diagmain.h". Included only
                     when diagnostic system is enabled.

**--------------------------------------------------------------
** CC Rev mraisky_DI-KERNEL-01_07.09_BASELINE_2.dev.   09/29/04 MRAISKY
** 1. moved reset_ecu_on_serv11_KSWTIMER to subsystem 14 only, because that is where
**    it is used.
**
****************************************************************************/
#endif





