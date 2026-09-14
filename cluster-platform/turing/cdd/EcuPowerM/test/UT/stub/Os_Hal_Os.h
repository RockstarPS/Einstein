/***********************************************************************************************************************
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2018 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  --------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/**
 *  \addtogroup Os_Hal_Os
 *  \{
 *
 *  \file
 *  \brief      HAL interfaces which are visible to the user.
 *
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  --------------------------------------------------------------------------------------------------------------------
 *  Andreas Jehl                  virjas        Vector Informatik GmbH
 *  Anton Schmukel                visasl        Vector Informatik GmbH
 *  Benjamin Seifert              virbse        Vector Informatik GmbH
 *  Bilal Parvez                  visbpz        Vector Informatik GmbH
 *  Da He                         visdhe        Vector Informatik GmbH
 *  David Feuerstein              visdfe        Vector Informatik GmbH
 *  Hendrik Stoffers              visshk        Vector Informatik GmbH
 *  Ivan Begert                   virbiv        Vector Informatik GmbH
 *  Martin Schultheiss            virsmn        Vector Informatik GmbH
 *  Michael Kock                  vismkk        Vector Informatik GmbH
 *  Stefano Simoncelli            virsso        Vector Informatik GmbH
 *  Senol Cendere                 visces        Vector Informatik GmbH
 *  Torsten Schmidt               visto         Vector Informatik GmbH
 *  --------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2016-01-05  virbiv  -             Initial version
 *  01.00.01  2016-05-14  virbiv  -             Developer version
 *  01.00.02  2016-06-10  virbiv  -             Update according to last core interface changes
 *  01.00.03  2016-08-08  virbiv  -             Added support for Zynq UltraScale+ derivatives
 *  01.00.04  2016-09-08  visdhe  FEAT-1931     Provide access to interrupt control register (Step2)
 *                        visasl  WORKITEM6031  #HAL:CortexR: As a customer I want the MICROSAR OS to support the
 *                                              CortexR devices as QM quality (Single Core, Traveo).
 *  01.01.00  2016-10-04  virbiv  -             Generator update
 *  01.02.00  2016-10-18  virbiv  -             Partially support for Cortex-M devices.
 *  01.03.00  2016-10-26  virbiv  -             Cortex-M support.
 *  01.04.00  2016-11-14  virbse  -             Updated Generator to latest BSWMD version
 *                        virbiv  -             S6J311x, S6J312x, S6J33xx derivative groups added
 *  01.05.00  2016-11-17  virsso  WORKITEM9700  CortexR Hardware Software Interface
 *  01.06.00  2016-12-06  virsso  WORKITEM9692  Refactoring of documentation
 *                        virsso  WORKITEM11476 Added ReviewHelper Justifications and Countermeasures
 *  01.07.00  2016-12-15  virjas  -             Internal improvements
 *  01.08.00  2017-01-12  -       -             Internal improvements
 *  02.00.00  2017-02-01  -       -             Internal improvements
 *  02.01.00  2017-02-17  virbiv  ESCAN00093961 Nested interrupt may cause an exception loop
 *                        virbiv  ESCAN00093930 Possible MemoryProtection violation
 *  02.02.00  2017-02-23  virsso  WORKITEM15109 Added support for RCAR_H3 derivative
 *            2017-03-02  virbiv  ESCAN00094082 UsageFault exception during startup
 *            2017-03-13  visces  ESCAN00093389 Writing IRQPLM causes an exception after an nondeterministic time
 *            2017-03-14  virbse  ESCAN00093962 The OS does not correctly handle the unhandled exceptions
 *                        virbiv  ESCAN00094579 A reset will lead to an unhandled Exception
 *  02.03.00  2017-03-28  visto   WORKITEM14883 Support for CortexR UltraScale
 *                                ESCAN00094582 Linker Error because of missing Symbol
 *                                              OsCfg_Hal_Core_OsCore0_InterruptVectorTable
 *                        virbiv  ESCAN00094641 Incorrect context switch restoration on Cortex-R core.
 *  02.04.00  2017-04-06  virbse  WORKITEM15149 Split Cortex-M into separate platform
 *                        virbiv  ESCAN00094022 Compiler error: Function definition not found
 *                        visdfe  ESCAN00093400 Compiler error: A Wrong pre-config leads to compile error in VTT dual
 *                                              target
 *                        visdfe  WORKITEM15150 Split Cortex-A Context from Cortex-R
 *                        vismkk  ESCAN00092881 Prescaler initialization for RTT (Real-Time Timer) module does not
 *                                              match the requirement in the hardware manual if HRT is configured.
 *                        visdhe  WORKITEM14013 Support for AR16xx derivatives
 *                        virbiv  WORKITEM14014 Support for compiler Texas Instruments
 *  02.05.00  2017-05-04  virbse  WORKITEM6746  The core generator shall provide a common core entry symbol for each
 *                                              core.
 *            2017-05-09  visces  WORKITEM15708 RCar-H3: Support Cortex-A cluster in 32Bit mode (not selectable by
 *                                              customer)
 *                                ESCAN00094886 R-Car H3: Interrupts are not working properly
 *                                ESCAN00094890 R-Car H3: MPU initialization leads to exception
 *            2017-05-10  visces  WORKITEM15653 RCar-H3 Support of Interrupt controller
 *                                ESCAN00094607 TMU PIT does not function properly on Rcar-H3
 *            2017-05-11  virsmn  ESCAN00095116 Core local interrupts are not correctly initialized.
 *  2.06.00   2017-06-01  visdfe  ESCAN00094046 Wrong validation of the maximum available MPU regions
 *                        visces  STORYC-1084   Internal improvements
 *  2.07.00   2017-06-23  visshk  ESCAN00095624 ProtectionHook is called unexpectedly during a context switch
 *                        visces  STORY-1038    Added interrupts of CATEGORY_0
 *                        visces  ESCAN00095103 Endless loop during Category 1 ISR processing
 *  2.08.00   2017-07-06  virjas  WORKITEM15088 Internal improvements
 *  2.09.00   2017-08-15  virsmn  ESCAN00094867 Compiler warning: warning #1514-D: incorrect GHS #pragma: small data
 *                                              area is not supported in this configuration
 *                        virbiv  ESCAN00095532 Compiler Warning  #32-D: expression must have arithmetic type in
 *                                              Os_Hal_Context_Lcfg.c
 *  02.10.00  2017-09-11  virsso  STORYC-1840   Internal improvements
 *  02.11.00  2017-10-10  visces  ESCAN00095552 Free Running Timers configured as non High Resolution Counters do not
 *                                              work properly.
 *  02.12.00  2017-10-18  virbse  FEAT-2816     Support shared stack for non-preemptive Basic tasks
 *                                FEAT-2815     Support shared stack for tasks with same internal resource
 *                        virsso  ESCAN00095337 The pre-config of MPU region for non-trusted application contains the
 *                                              wrong accessing rights
 *  02.13.00  2017-11-02  virsmn  ESCAN00096854 Usage of High Resolution Timer and Master Protection Mechanism of INTC
 *                                              could lead to protection violation.
 *                        visdhe  STORYC-2762   Support OS SC1/SC2 with GCC Compiler Production QM
 *  02.14.00  2017-11-22  visshk  STORYC-1751   Performance improvements on some platforms
 *                        visbpz  STORY-2769    OS Interrupt API optimization by replacement of a call sequence for
 *                                              modification of the global interrupt flag.
 *                        virsso  ESCAN00097603 ProtectionHook wrongly called on spourious interrupt
 *                        virsso  ESCAN00097486 Interruption possible in OS code which should not be interrupted
 *                        visces  ESCAN00097317 Compiler error: identifier "OS_HAL_MP_ACCESS_TYPE_NON_CACHEABLE"
 *                                              is undefined
 *  02.15.00  2017-01-10  virsso  STORYC-3218   Support for user configurable FPU cotext saving
 *                        virsso  ESCAN00098050 Undefined behavior of OS after context switchUndefined behavior of
 *                                              OS after context switch
 *  02.16.00  2017-01-25  virsso  ESCAN00098044 Category 1 interrupts may not be correctly disabled.
 *                                ESCAN00097444 Big endian support missing.
 *                                STORYC-3959   Support for TMS570LS21x_31x derivatives.
 *                                ESCAN00098298 Compiler error: bad parameter vstm and vldm {d0-d31}
 *                        virsmn  STORYC-3600   Update according to CDK coding guidelines.
 *                                STORYC-3282   Support for user Msr settings.
 *  02.17.00  2018-02-22  virsso  STORYC-4341   Support for Linaro GCC 6.2.1.
 *                        virsmn  STORYC-3042   Support for OS internal exception detection.
 *  02.18.00  2018-03-23  visbpz  STORYC-4068   Performance improvment by avoiding traps
 *                        visces  STORYC-4469   Support for ARM compiler version >= 6.6.1
 **********************************************************************************************************************/

#if !defined (OS_HAL_OS_H)                                                                                              /* PRQA S 0883 */ /* MD_Os_Hal_0883 */
# define OS_HAL_OS_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Hal_OsInt.h"

/* Os kernel module dependencies */
# include "Os_Lcfg.h"

/* Os hal dependencies */


/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/
/* ----- Component version information ----- */
# define OS_HAL_SW_MAJOR_VERSION                     (2u)
# define OS_HAL_SW_MINOR_VERSION                     (18u)
# define OS_HAL_SW_PATCH_VERSION                     (0u)

/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#endif /* OS_HAL_OS_H */


/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_Os.h
 **********************************************************************************************************************/
