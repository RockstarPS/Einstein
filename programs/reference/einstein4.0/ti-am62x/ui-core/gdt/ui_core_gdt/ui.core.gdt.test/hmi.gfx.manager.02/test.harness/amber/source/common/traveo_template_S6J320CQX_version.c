/******************************************************************************
 * $Revision: 10552 $
 * $Date: 2014-10-17 13:52:06 +0200 (Fri, 17 Oct 2014) $
 *****************************************************************************/
/* __DISCLAIMER_START__                                                      */
/******************************************************************************
* Copyright (C) 2014 Spansion LLC. All Rights Reserved. 
*
* This software is owned and published by: 
* Spansion LLC, 915 DeGuigne Dr. Sunnyvale, CA  94088-3453 ("Spansion").
*
* BY DOWNLOADING, INSTALLING OR USING THIS SOFTWARE, YOU AGREE TO BE BOUND 
* BY ALL THE TERMS AND CONDITIONS OF THIS AGREEMENT.
*
* This software contains source code for use with Spansion 
* components. This software is licensed by Spansion to be adapted only 
* for use in systems utilizing Spansion components. Spansion shall not be 
* responsible for misuse or illegal use of this software for devices not 
* supported herein.  Spansion is providing this software "AS IS" and will 
* not be responsible for issues arising from incorrect user implementation 
* of the software.  
*
* SPANSION MAKES NO WARRANTY, EXPRESS OR IMPLIED, ARISING BY LAW OR OTHERWISE,
* REGARDING THE SOFTWARE (INCLUDING ANY ACOOMPANYING WRITTEN MATERIALS), 
* ITS PERFORMANCE OR SUITABILITY FOR YOUR INTENDED USE, INCLUDING, 
* WITHOUT LIMITATION, THE IMPLIED WARRANTY OF MERCHANTABILITY, THE IMPLIED 
* WARRANTY OF FITNESS FOR A PARTICULAR PURPOSE OR USE, AND THE IMPLIED 
* WARRANTY OF NONINFRINGEMENT.  
* SPANSION SHALL HAVE NO LIABILITY (WHETHER IN CONTRACT, WARRANTY, TORT, 
* NEGLIGENCE OR OTHERWISE) FOR ANY DAMAGES WHATSOEVER (INCLUDING, WITHOUT 
* LIMITATION, DAMAGES FOR LOSS OF BUSINESS PROFITS, BUSINESS INTERRUPTION, 
* LOSS OF BUSINESS INFORMATION, OR OTHER PECUNIARY LOSS) ARISING FROM USE OR 
* INABILITY TO USE THE SOFTWARE, INCLUDING, WITHOUT LIMITATION, ANY DIRECT, 
* INDIRECT, INCIDENTAL, SPECIAL OR CONSEQUENTIAL DAMAGES OR LOSS OF DATA, 
* SAVINGS OR PROFITS, 
* EVEN IF SPANSION HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES. 
* YOU ASSUME ALL RESPONSIBILITIES FOR SELECTION OF THE SOFTWARE TO ACHIEVE YOUR
* INTENDED RESULTS, AND FOR THE INSTALLATION OF, USE OF, AND RESULTS OBTAINED 
* FROM, THE SOFTWARE.  
*
* This software may be replicated in part or whole for the licensed use, 
* with the restriction that this Disclaimer and Copyright notice must be 
* included with each copy of this software, whether used in part or whole, 
* at all times.
******************************************************************************/
/* __DISCLAIMER_END__                                                        */
/*****************************************************************************/
/** \file traveo_template_S6J320CQX_version.c
 **
 ** SW template version check file for S6J320CQX series. This will check
 ** whether all SW template files are available with the corresponding version
 ** of this template version.
 **
 ** History:
 **   - 2013-12-09  0.01    FTo Initial version for Traveo
 **   - 2014-01-28  0.02    FTo Updated to header files version V01L01R02
 **   - 2014-02-14  0.04    FTo Added main.h
 **   - 2014-02-17  0.05    FTo Added TcmRam/BuRAM to Start_stcClearEccMemories
 **                             Updated range for VCO (400..800) MHz
 **                             Fixed error on assigning DIVN to register.
 **   - 2014-08-06  0.06    FTo Added SSCG0
 **                             Added register SYSC1_RUNCKER0
 **                             Enabled VDP3 GPIO Ports
 **   - 2014-08-11  0.07    FTo Added HSSPI clock divider (start.c)
 **   - 2014-08-12  0.08    FTo Added ClearWatchdog() in all loops (start.c)
 **   - 2014-09-03  0.10    CEy updated template
 **   - 2014-09-15  0.12    CEy updated template, added check of mcu_settings.h
 **   - 2014-10-07  0.14    CEy updated template
 *****************************************************************************/

// File version 0xYYXX = vYY.XX
#define TRAVEO_TEMPLATE_VERSION    0x0014

#ifndef __FILE_VERSION_CHECK__

/*****************************************************************************/
/* Include files                                                             */
/*****************************************************************************/

#define __FILE_VERSION_CHECK__

    #include "main.h"
    #include "mcu_settings.h"
    #include "abstract.h"
    #include "base_types.h"
    #include "s6j320cqxio.h"		
    #include "start.h"
    #include "start.c"
    #include "exceptions.h"
    #include "exceptions.c"
    #include "interrupts.h"
    #include "interrupts.c"

#undef __FILE_VERSION_CHECK__

/*****************************************************************************/
/* Local pre-processor symbols/macros ('#define')                            */
/*****************************************************************************/

// List of required file versions

#define FILE_VERSION_REQUIRED_ABSTRACT_H                0x0012
#define FILE_VERSION_REQUIRED_BASE_TYPES_H              0x0001
#define FILE_VERSION_REQUIRED_MAIN_H                    0x0004
#define FILE_VERSION_REQUIRED_START_H                   0x0005
#define FILE_VERSION_REQUIRED_START_C                   0x0014
#define FILE_VERSION_REQUIRED_EXCEPTIONS_H              0x0010
#define FILE_VERSION_REQUIRED_EXCEPTIONS_C              0x0012
#define FILE_VERSION_REQUIRED_INTERRUPTS_H              0x0012
#define FILE_VERSION_REQUIRED_INTERRUPTS_C              0x0010
#define FILE_VERSION_REQUIRED_MCU_SETTINGS_H_VERSION    0x0012

// Check all file versions of the current SW template

#if (MAIN_H_VERSION != FILE_VERSION_REQUIRED_MAIN_H)
    #warning "Traveo template: file version mismatch (MAIN_H)"
#endif
#if (ABSTRACT_H_VERSION != FILE_VERSION_REQUIRED_ABSTRACT_H)
    #warning "Traveo template: file version mismatch (ABSTRACT_H)"
#endif
#if (BASE_TYPES_H_VERSION != FILE_VERSION_REQUIRED_BASE_TYPES_H)
    #warning "Traveo template: file version mismatch (BASE_TYPES_H)"
#endif
#if (START_H_VERSION != FILE_VERSION_REQUIRED_START_H)
    #warning "Traveo template: file version mismatch (START_H)"
#endif
#if (START_C_VERSION != FILE_VERSION_REQUIRED_START_C)
    #warning "Traveo template: file version mismatch (START_C)"
#endif
#if (EXCEPTIONS_H_VERSION != FILE_VERSION_REQUIRED_EXCEPTIONS_H)
    #warning "Traveo template: file version mismatch (EXCEPTIONS_H)"
#endif
#if (EXCEPTIONS_C_VERSION != FILE_VERSION_REQUIRED_EXCEPTIONS_C)
    #warning "Traveo template: file version mismatch (EXCEPTIONS_C)"
#endif
#if (INTERRUPTS_H_VERSION != FILE_VERSION_REQUIRED_INTERRUPTS_H)
    #warning "Traveo template: file version mismatch (INTERRUPTS_H)"
#endif
#if (INTERRUPTS_C_VERSION != FILE_VERSION_REQUIRED_INTERRUPTS_C)
    #warning "Traveo template: file version mismatch (INTERRUPTS_C)"
#endif
#if (MCU_SETTINGS_H_VERSION != FILE_VERSION_REQUIRED_MCU_SETTINGS_H_VERSION)
    #warning "Traveo template: file version mismatch (MCU_SETTINGS_H)"
#endif

/*****************************************************************************/
/* Global variable definitions (declared in header file with 'extern')       */
/*****************************************************************************/

/*****************************************************************************/
/* Local type definitions ('typedef')                                        */
/*****************************************************************************/

// dummy to prevent compiler error for missing at least one declaration
typedef void dummy_t;

/*****************************************************************************/
/* Local function prototypes ('static')                                      */
/*****************************************************************************/

/*****************************************************************************/
/* Local variable definitions ('static')                                     */
/*****************************************************************************/

/*****************************************************************************/
/* Function implementation - global ('extern') and local ('static')          */
/*****************************************************************************/

#endif /* __FILE_VERSION_CHECK__ */
