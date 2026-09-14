/**
    @file    typedefs.h
    @version 0.9.0

    @brief   AUTOSAR Sample_app - typedefs for platform reg file.
    @details .
    
    Project      : AUTOSAR 4.2 MCAL
    Platform     : ARM
    Peripheral   : 
    Dependencies : Mcu Base Dem Det Port Dio Rte EcuM Spi Can CanIf Gpt Icu Pwm Fls Fee MemIf Adc Wdg WdgIf

    Autosar Version       : 4.2.2
    Autosar Revision      : ASR_REL_4_2_REV_0002
    Autosar Conf. Variant :
    SW Version            : 0.9.0
    Build Version         : IMX8_MCAL_0_9_0_BETA_ASR_REL_4_2_REV_0002_20171130

    (c) Copyright 2017 NXP USA Inc
    All Rights Reserved.
*/
/*==================================================================================================
==================================================================================================*/

#ifndef _TYPEDEFS_H_
#define _TYPEDEFS_H_

#ifdef __MWERKS__    /*Metrowerk CodeWarrior */
    #include <stdint.h>

    /* Standard typedefs used by header files, based on ISO C standard */
    typedef volatile int8_t vint8_t;
    typedef volatile uint8_t vuint8_t;

    typedef volatile int16_t vint16_t;
    typedef volatile uint16_t vuint16_t;

    typedef volatile int32_t vint32_t;
    typedef volatile uint32_t vuint32_t;

#else
#ifdef __ghs__    /*GreenHills */
    #include <stdint.h>

    /* Standard typedefs used by header files, based on ISO C standard */
    typedef volatile int8_t vint8_t;
    typedef volatile uint8_t vuint8_t;

    typedef volatile int16_t vint16_t;
    typedef volatile uint16_t vuint16_t;

    typedef volatile int32_t vint32_t;
    typedef volatile uint32_t vuint32_t;

#else

    /* This is needed for compilers that don't have a stdint.h file */

    typedef signed char int8_t;
    typedef unsigned char uint8_t;
    typedef volatile signed char vint8_t;
    typedef volatile unsigned char vuint8_t;

    typedef signed short int16_t;
    typedef unsigned short uint16_t;
    typedef volatile signed short vint16_t;
    typedef volatile unsigned short vuint16_t;

    typedef signed int int32_t;
    typedef unsigned int uint32_t;
    typedef volatile signed int vint32_t;
    typedef volatile unsigned int vuint32_t;

#endif
#endif
#endif

/*********************************************************************
 *
 * Copyright:
 *	NXP USA Inc. All Rights Reserved.
 *  You are hereby granted a copyright license to use, modify, and
 *  distribute the SOFTWARE so long as this entire notice is
 *  retained without alteration in any modified and/or redistributed
 *  versions, and that such modified versions are clearly identified
 *  as such. No licenses are granted by implication, estoppel or
 *  otherwise under any patents or trademarks of NXP USA Inc.
 *  This software is provided on an "AS IS"
 *  basis and without warranty.
 *
 *  To the maximum extent permitted by applicable law, NXP USA Inc
 *  DISCLAIMS ALL WARRANTIES WHETHER EXPRESS OR IMPLIED,
 *  INCLUDING IMPLIED WARRANTIES OF MERCHANTABILITY OR FITNESS FOR A
 *  PARTICULAR PURPOSE AND ANY WARRANTY AGAINST INFRINGEMENT WITH
 *  REGARD TO THE SOFTWARE (INCLUDING ANY MODIFIED VERSIONS THEREOF)
 *  AND ANY ACCOMPANYING WRITTEN MATERIALS.
 *
 *  To the maximum extent permitted by applicable law, IN NO EVENT
 *  SHALL NXP USA Inc BE LIABLE FOR ANY DAMAGES WHATSOEVER
 *  (INCLUDING WITHOUT LIMITATION, DAMAGES FOR LOSS OF BUSINESS PROFITS,
 *  BUSINESS INTERRUPTION, LOSS OF BUSINESS INFORMATION, OR OTHER
 *  PECUNIARY LOSS) ARISING OF THE USE OR INABILITY TO USE THE SOFTWARE.
 *
 *  NXP USA Inc assumes no responsibility for the
 *  maintenance and support of this software
 *
 ********************************************************************/


