/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* File name    = rh850_Types.h                                               */
/* Version      = V1.0.7                                                      */
/* Date         = 08-Jul-2016                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2012-2016 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provision for platform dependent types                                     */
/*                                                                            */
/*============================================================================*/
/*                                                                            */
/* Unless otherwise agreed upon in writing between your company and           */
/* Renesas Electronics Corporation the following shall apply!                 */
/*                                                                            */
/* Warranty Disclaimer                                                        */
/*                                                                            */
/* There is no warranty of any kind whatsoever granted by Renesas. Any        */
/* warranty is expressly disclaimed and excluded by Renesas, either expressed */
/* or implied, including but not limited to those for non-infringement of     */
/* intellectual property, merchantability and/or fitness for the particular   */
/* purpose.                                                                   */
/*                                                                            */
/* Renesas shall not have any obligation to maintain, service or provide bug  */
/* fixes for the supplied Product(s) and/or the Application.                  */
/*                                                                            */
/* Each User is solely responsible for determining the appropriateness of     */
/* using the Product(s) and assumes all risks associated with its exercise    */
/* of rights under this Agreement, including, but not limited to the risks    */
/* and costs of program errors, compliance with applicable laws, damage to    */
/* or loss of data, programs or equipment, and unavailability or              */
/* interruption of operations.                                                */
/*                                                                            */
/* Limitation of Liability                                                    */
/*                                                                            */
/* In no event shall Renesas be liable to the User for any incidental,        */
/* consequential, indirect, or punitive damage (including but not limited     */
/* to lost profits) regardless of whether such liability is based on breach   */
/* of contract, tort, strict liability, breach of warranties, failure of      */
/* essential purpose or otherwise and even if advised of the possibility of   */
/* such damages. Renesas shall not be liable for any services or products     */
/* provided by third party vendors, developers or consultants identified or   */
/* referred to the User by Renesas in connection with the Product(s) and/or   */
/* the Application.                                                           */
/*                                                                            */
/*============================================================================*/
/* Environment:                                                               */
/*              Devices:        X1x                                           */
/*============================================================================*/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V1.0.0:  03-Sep-2012  : Initial Version
 * V1.0.1:  05-Dec-2013  : As per Mantis #17424 note 0110082,Macro definition
 *                         added for supervisor mode(SV) write enabled
 *                         Registers IMR & ICxxx access.
 * V1.0.2:  06-Jan-2014  : As per Mantis #17424,Macro definition
 *                         added for supervisor mode(SV) write enabled
 *                         Registers IMR & ICxxx direct write.
 * V1.0.3:  22-Apr-2014  : As per Mantis #17424:0134318,replaced the Macros
 *                         corresponds to write operation of supervisor
 *                         mode(SV) write enabled registers IMR & ICxxx.
 * V1.0.4:  22-Jun-2014  : As per Mantis #22157, Macro definitions corresponding
 *                         to supervisor mode(SV) write enabled registers IMR &
 *                         ICxxx direct write are modified to avoid compilation
 *                         issues due to concatenation operator "##".
 * V1.0.5:  05-Aug-2015  : As per Mantis #28499, macro
 *                         RH850_SV_MODE_REG_READ_ONLY is added
 * V1.0.6:  05-Nov-2015  : As per Mantis #30896, macro
 *                         RH850_SV_MODE_REG_WRITE_ONLY, RH850_SV_MODE_REG_OR,
 *                         RH850_SV_MODE_REG_AND are added
 * V1.0.7:  08-Jul-2016  : As QAC activity, add new QAC warning message:
 *                         Msg(4:0881)
 */
/******************************************************************************/

#ifndef RH850_TYPES_H
#define RH850_TYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/*
 * File version information
 */
#define V850_TYPES_SW_MAJOR_VERSION  4
#define V850_TYPES_SW_MINOR_VERSION  0
#define V850_TYPES_SW_PATCH_VERSION  0

/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : Msg(4:0881) Using multiple ## operators in the same macro  */
/*                 definition.                                                */
/* Rule          : MISRA-C:2004 Rule 19.12                                    */
/* Justification : Multiple ## operators are used to define macros of register*/
/*                 accessing.                                                 */
/* Verification  : However, only single ## operator is used in each identifier*/
/* Reference     : Look for START Msg(4:0881)-1 and                           */
/*                 END Msg(4:0881)-1 tags in the code.                        */
/******************************************************************************/

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

typedef unsigned int        uinteger;       /*           0 .. 65535           */

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
/*******************************************************************************
**                      Macro                                                 **
*******************************************************************************/

/*  Macro definition for supervisor mode(SV) write enabled Registers
 *  IMR & ICxxx .
 */
/*******************************************************************************
** Macro Name            : RH850_SV_MODE_ICR_OR
**
** Description           : This Macro performs supervisor mode(SV)
**                         write enabled Register ICxxx register
**                         writing which involves an OR operation.
**
** Input Parameters      : SIZE, ADDR, VAL
**                         SIZE : Register Access Size.
**                         ADDR : Register address.
**                         VAL  : Value to be written to the register.
*******************************************************************************/
/* MISRA Violation: START Msg(4:0881)-1 */
#define RH850_SV_MODE_ICR_OR(SIZE, ADDR, VAL) \
                                    (*((volatile uint##SIZE*)(ADDR)) = \
                                    ((*((volatile uint##SIZE*)(ADDR)))|(VAL)))
/* END Msg(4:0881)-1 */
/*******************************************************************************
** Macro Name            : RH850_SV_MODE_ICR_AND
**
** Description           : This Macro performs supervisor mode(SV)
**                         write enabled Register ICxxx register
**                         writing which involves an AND operation.
**
** Input Parameters      : SIZE, ADDR, VAL
**                         SIZE : Register Access Size.
**                         ADDR : Register address
**                         VAL  : Value to be written to the register.
*******************************************************************************/
/* MISRA Violation: START Msg(4:0881)-1 */
#define RH850_SV_MODE_ICR_AND(SIZE, ADDR, VAL) \
                                    (*((volatile uint##SIZE*)(ADDR)) = \
                                    ((*((volatile uint##SIZE*)(ADDR)))&(VAL)))
/* END Msg(4:0881)-1 */
/*******************************************************************************
** Macro Name            : RH850_SV_MODE_ICR_WRITE_ONLY
**
** Description           : This Macro performs supervisor mode(SV)
**                         write enabled Register ICxxx register
**                         direct writing operation.
**
** Input Parameters      : SIZE, ADDR, VAL
**                         SIZE : Register Access Size.
**                         ADDR : Register address
**                         VAL  : Value to be written to the register.
*******************************************************************************/

#define RH850_SV_MODE_ICR_WRITE_ONLY(SIZE, ADDR, VAL) \
                                 (*((volatile uint##SIZE*)(ADDR)) = \
                                 (VAL))
/*******************************************************************************
** Macro Name            : RH850_SV_MODE_IMR_OR
**
** Description           : This Macro performs supervisor mode(SV)
**                         write enabled Register IMR register
**                         writing which involves an OR operation.
**
** Input Parameters      : SIZE, ADDR, VAL
**                         SIZE : Register Access Size.
**                         ADDR : Register address.
**                         VAL  : Value to be written to the register.
*******************************************************************************/
/* MISRA Violation: START Msg(4:0881)-1 */
#define RH850_SV_MODE_IMR_OR(SIZE, ADDR, VAL) \
                                    (*((volatile uint##SIZE*)(ADDR)) = \
                                    ((*((volatile uint##SIZE*)(ADDR)))|(VAL)))
/* END Msg(4:0881)-1 */
/*******************************************************************************
** Macro Name            : RH850_SV_MODE_IMR_AND
**
** Description           : This Macro performs supervisor mode(SV)
**                         write enabled Register IMR register
**                         writing which involves an AND operation.
**
** Input Parameters      : SIZE, ADDR, VAL
**                         SIZE : Register Access Size.
**                         ADDR : Register address
**                         VAL  : Value to be written to the register.
*******************************************************************************/
/* MISRA Violation: START Msg(4:0881)-1 */
#define RH850_SV_MODE_IMR_AND(SIZE, ADDR, VAL) \
                                    (*((volatile uint##SIZE*)(ADDR)) = \
                                    ((*((volatile uint##SIZE*)(ADDR)))&(VAL)))
/* END Msg(4:0881)-1 */
/*******************************************************************************
** Macro Name            : RH850_SV_MODE_IMR_WRITE_ONLY
**
** Description           : This Macro performs supervisor mode(SV)
**                         write enabled Register IMR register
**                         direct writing operation.
**
** Input Parameters      : SIZE, ADDR, VAL
**                         SIZE : Register Access Size.
**                         ADDR : Register address
**                         VAL  : Value to be written to the register.
*******************************************************************************/

#define RH850_SV_MODE_IMR_WRITE_ONLY(SIZE, ADDR, VAL) \
                                 (*((volatile uint##SIZE*)(ADDR)) = \
                                 (VAL))

/*******************************************************************************
** Macro Name            : RH850_SV_MODE_REG_READ_ONLY
**
** Description           : This Macro performs a dummy reading a register
**
** Input Parameters      : SIZE, ADDR
**                         SIZE : Register Access Size.
**                         ADDR : Register address
*******************************************************************************/
#define RH850_SV_MODE_REG_READ_ONLY(SIZE, ADDR) \
                                    (*((volatile uint##SIZE*)(ADDR)))

/*******************************************************************************
** Macro Name            : RH850_SV_MODE_REG_WRITE_ONLY
**
** Description           : This Macro performs supervisor mode(SV)
**                         write register.
**
** Input Parameters      : SIZE, ADDR, VAL
**                         SIZE : Register Access Size.
**                         ADDR : Register address
**                         VAL  : Value to be written to the register.
*******************************************************************************/

#define RH850_SV_MODE_REG_WRITE_ONLY(SIZE, ADDR, VAL) \
                                 (*((volatile uint##SIZE*)(ADDR)) = \
                                 (VAL))

/*******************************************************************************
** Macro Name            : RH850_SV_MODE_REG_OR
**
** Description           : This Macro performs supervisor mode(SV)
**                         write enabled Register writing which
**                         involves an OR operation.
**
** Input Parameters      : SIZE, ADDR, VAL
**                         SIZE : Register Access Size.
**                         ADDR : Register address.
**                         VAL  : Value to be written to the register.
*******************************************************************************/
/* MISRA Violation: START Msg(4:0881)-1 */
#define RH850_SV_MODE_REG_OR(SIZE, ADDR, VAL) \
                                    (*((volatile uint##SIZE*)(ADDR)) = \
                                    ((*((volatile uint##SIZE*)(ADDR)))|(VAL)))
/* END Msg(4:0881)-1 */
/*******************************************************************************
** Macro Name            : RH850_SV_MODE_REG_AND
**
** Description           : This Macro performs supervisor mode(SV)
**                         write enabled Register writing which
**                         involves an AND operation.
**
** Input Parameters      : SIZE, ADDR, VAL
**                         SIZE : Register Access Size.
**                         ADDR : Register address
**                         VAL  : Value to be written to the register.
*******************************************************************************/
/* MISRA Violation: START Msg(4:0881)-1 */
#define RH850_SV_MODE_REG_AND(SIZE, ADDR, VAL) \
                                    (*((volatile uint##SIZE*)(ADDR)) = \
                                    ((*((volatile uint##SIZE*)(ADDR)))&(VAL)))
/* END Msg(4:0881)-1 */
#endif /* RH850_TYPES_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
