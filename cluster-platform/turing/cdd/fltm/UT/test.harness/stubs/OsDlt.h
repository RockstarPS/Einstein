/**
 * @verbatim
               CONFIDENTIAL VISTEON CORPORATION

 This is an unpublished work of authorship, which contains trade
 secrets, created in 2013. Visteon Corporation owns all rights to
 this work and intends to maintain it in confidence to preserve
 its trade secret status. Visteon Corporation reserves the right,
 under the copyright laws of the United States or those of any
 other country that may have jurisdiction, to protect this work
 as an unpublished work, in the event of an inadvertent or
 deliberate unauthorized publication. Visteon Corporation also
 reserves its rights under all copyright laws to protect this
 work as a published work, when appropriate. Those having access
 to this work may not copy it, use it, modify it or disclose the
 information contained in it without the written authorization
 of Visteon Corporation.
 * @endverbatim
 * @file        OsDlt.h
 * @details     <b> OS DLT Support Header </b>
 * @note
 *              Compiler    : GHS \n
 *              Target Hw   : Independent
 *
 * @copyright   Visteon (c) 2021
 *
 */

#ifndef TURING_BSW_MOS_SRC_OSDLT_H_
#define TURING_BSW_MOS_SRC_OSDLT_H_

/* API IDs */
/* Service IDs 0x00 to 0x27 are defined by Autosar for OS Services */
#define OsDlt_OsInvalidService              0xFFU

#define OsDlt_OsInternalService             0xF0U

#define OsDlt_OsStartScheduleTableRel       0x07U
#define OsDlt_OsStartScheduleTableAbs       0x08U
#define OsDlt_OsStopScheduleTable           0x09U
#define OsDlt_OsGetScheduleTableStatus      0x0EU
/*Counter*/
#define OsDlt_OsIncrementCounter            0x0FU
#define OsDlt_OsGetCounterValue             0x10U
#define OsDlt_OsGetElapsedValue             0x11U
#define OsDlt_osResetCounter                0x40U

/*OsApplication*/
#define OsDlt_OsGetApplicationState         0x14U
#define OsDlt_OsCallTrustedFunction         0x02U

/* Implementation specific - OSEK Service Ids */
#define OsDlt_OsActivateTask                0x30U
#define OsDlt_OsTerminateTask               0x31U
#define OsDlt_OsChainTask                   0x32U /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
#define OsDlt_OsSchedule                    0x33U
#define OsDlt_OsGetTaskID                   0x34U /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
#define OsDlt_OsGetTaskState                0x35U

#define OsDlt_OsSetEvent                    0x36U
#define OsDlt_OsClearEvent                  0x37U
#define OsDlt_OsGetEvent                    0x38U
#define OsDlt_OsWaitEvent                   0x39U

#define OsDlt_OsGetResource                 0x3AU
#define OsDlt_OsReleaseResource             0x3BU
#define OsDlt_OsGetAppParam                 0x3CU  //todo: assign value for this


#define OsDlt_osSetRelAlarm                 0x40U
#define OsDlt_osCancelAlarm                 0x41U
#define OsDlt_osGetAlarm                    0x42U
#define OsDlt_osSetAbsAlarm                 0x43U

#define OsDlt_DisableInterruptSource        0x50U
#define OsDlt_EnableInterruptSource         0x51U


#define OsDlt_osShutdownOS                  0xEFU
#define OsDlt_OsTickTimer                   0x44U

#define OsDlt_LogMessage(x,y)

#endif /* TURING_BSW_MOS_SRC_OSDLT_H_ */
