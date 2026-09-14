/*****************************************************************************
 * $Revision: 10544 $
 * $Date: 2014-09-16 10:22:04 +0200 (Tue, 16 Sep 2014) $
 *****************************************************************************/
/* __DISCLAIMER_START__                                                      */
/******************************************************************************
* Copyright (C) 2013 Spansion LLC. All Rights Reserved. 
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
/** \file timer_ids.h
 **
 ** Definition of timer IDs for timer module.
 **
 ** History:
 ** - 2011-09-08  1.00  JWa  First version
 ** - 2013-12-18  1.00s MKoe Changed to Spansion disclaimer (no code modified)
 ** - 2014-03-07  1.01  MKoe Added version check 
 *****************************************************************************/

#ifndef __TIMER_IDS_H__
#define __TIMER_IDS_H__

// File version 0xYYXX = vYY.XX
#define TIMER_IDS_H_VERSION          0x0101

#ifndef __FILE_VERSION_CHECK__

/*****************************************************************************/
/* Include files                                                             */
/*****************************************************************************/
#include "base_types.h"
#include "mcu_settings.h"
#include "timer_ids.h"

/*****************************************************************************/
/* Global pre-processor symbols/macros ('define')                            */
/*****************************************************************************/
// Timer IDs (must start at 0 and be incremented by 1)

#define TIMER_ID_MAIN         0
#define TIMER_ID_BUTTON       1
#define TIMER_ID_GP1          2
#define TIMER_ID_GP2          3
#define TIMER_ID_GP3          4

#define TIMER_ID_PRESENTATION_TASK	5
#define TIMER_ID_KSTIMED_TASK		6
// Number of timer IDs (= last timer ID +1 +number of user defined counters)
//#define TIMER_COUNT         (TIMER_ID_GP3 + 1)
#define TIMER_COUNT         (TIMER_ID_KSTIMED_TASK + 1)

/*****************************************************************************/
/* Global type definitions ('typedef')                                       */
/*****************************************************************************/

/*****************************************************************************/
/* Global variable declarations ('extern', definition in C source)           */
/*****************************************************************************/

/*****************************************************************************/
/* Global function prototypes ('extern', definition in C source)             */
/*****************************************************************************/

#endif /* __FILE_VERSION_CHECK__ */
#endif /* __TIMER_IDS_H__ */
/*****************************************************************************/
/* EOF (not truncated)                                                       */
/*****************************************************************************/
