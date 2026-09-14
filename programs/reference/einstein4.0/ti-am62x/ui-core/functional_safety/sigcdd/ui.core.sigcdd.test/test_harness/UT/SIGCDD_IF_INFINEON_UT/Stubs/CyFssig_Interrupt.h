/*******************************************************************************
* Product: SW_TVII_SIG_DRV
*
* (c) 2017-2021,, Cypress Semiconductor Corporation. All rights reserved.
*
* Warranty and Disclaimer
*
* This software product is property of Cypress Semiconductor Corporation or
* its subsidiaries.
* Any use and/or distribution rights for this software product are provided
* only under the Cypress Software License Agreement.
* Any use and/or distribution of this software product not in accordance with
* the terms of the Cypress Software License Agreement are unauthorized and
* shall constitute an infringement of Cypress intellectual property rights.
*
*******************************************************************************/
/*******************************************************************************
 ** \file CyFssig_Interrupt.h
 **
 ** \date       03-Nov-2017 11:21:34
 ** \addtogroup Interface CyFssig_Interrupt
 **
*******************************************************************************/
#ifndef CYFSSIG_INTERRUPT_H
#define CYFSSIG_INTERRUPT_H


/*****************************************************************************/
/* Include files                                                             */
/*****************************************************************************/
#include "CyFssig_Compiler_Cfg.h"

/*****************************************************************************
 ** Global pre-processor symbols/macros ('#define')
 *****************************************************************************/


/*****************************************************************************
 ** Global type definitions ('typedef')
 *****************************************************************************/

/*****************************************************************************
 ** Global variable declarations ('extern', definition in C source)
 *****************************************************************************/

/*****************************************************************************
 ** CyFssig_Interrupt Global function prototypes ('extern', definition in C source)
 *****************************************************************************/
/**
 *
 * TraveoIIFsSigDrv interrupt function.
 *
 * The function does not have a return value.
 *
 * In the case of an error, the function reports one of the following error codes
 * via the error callout:
 * - CYFSSIG_E_UNINIT
 * - CYFSSIG_E_PARAM_DISPID
 *
 */
extern FUNC(void, CYFSSIG_CODE) CyFssig_Display_Isr_Cat2(
    void);


#endif /*!defined(CYFSSIG_INTERRUPT_H)*/
