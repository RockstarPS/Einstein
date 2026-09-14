/***************************************************************************
 **
 **  \file WD.h
 **
 **  \brief Interface to interact with the RTI watchdog of TI-AM62P
 **
 **  Component Name: WD
 **  Archive:
 **  Date: Jun 17 2025
 **  \author: Krassimire Stoyanov
 **
 **  \copyright 2025 Visteon Corporation.
 **
 ** These materials and the intellectual property rights associated therewith
 ** (“Materials”) are proprietary to Visteon Corporation. Any and all rights in
 ** the Materials are reserved by Visteon Corporation. Nothing contained in
 ** these Materials shall grant or be deemed to grant to you or anyone else, by
 ** implication, estoppel or otherwise, any rights in these Materials.
 **
 **==========================================================================*/


/**********************************************************************************************************************
 *  HEADER FILE GUARD
 *********************************************************************************************************************/
#ifndef WD_H
#define WD_H

/**********************************************************************************************************************
 *  DEFINES
 *********************************************************************************************************************/
#define RTI_WDT_TIMEOUT     (1000U)
#undef RTI_WDT_TEST

/**********************************************************************************************************************
 *  Interface
 *********************************************************************************************************************/
extern void InternalWatchdog_Enable(void); // call after system init, but before any other function listed here
extern void InternalWatchdog_PrintResetStatus(void);// run after the debug UART is configured
extern void InternalWatchdog_Test(void); // run the test after the debug UART is configured
extern void InternalWatchdog_Service(void); // pet the watchdog
extern void InternalWatchdog_DoReset(void); // cause reset
#endif
