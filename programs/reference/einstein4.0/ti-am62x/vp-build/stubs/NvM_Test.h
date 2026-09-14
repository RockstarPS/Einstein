/******************************************************************************
**              CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2012. Visteon Corporation owns all rights to this work and
** intends to maintain it in confidence to preserve its trade secret status.
** Visteon Corporation reserves the right, under the copyright laws of the
** United States or those of any other country that may have  jurisdiction,
** to protect this work as an unpublished work, in the event of an
** inadvertent or deliberate unauthorized publication. Visteon Corporation
** also reserves its rights under all copyright laws to protect this work as
** a published work, when appropriate. Those having access to this work may
** not copy it, use it, modify it or disclose the information contained in
** it without the written authorization of Visteon Corporation
**
******************************************************************************/

/******************************************************************************

File Name        :  NvM_Test.h
Module Short Name:  NvM
VOBName          :  
Author           :  
Description      :  Generated File
Organization     :  Driver Information Software Section,
                    Visteon Corporation

******************************************************************************/

#ifndef NVM_TEST_H
#define NVM_TEST_H

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/

/*****************************************************************************
*                                Globally  accessed Variable Declarations    *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/

/*****************************************************************************
 *                                 Locally used Variable Declarations         *
 *----------------------------------------------------------------------------*
 * Declaration shall be followed by a comment that gives the following info.  *
 * about the variable.                                                        *
 * purpose, critical section, unit, and resolution                            *
 ******************************************************************************/

/*****************************************************************************
 *                              Limited Scope Prototypes                      *
 ******************************************************************************/

/*****************************************************************************
 *                   Functions                                                *
 ******************************************************************************/
/*============================================================================
**
** Function Name    :   NvM_TestFunction
**
** Visibility       :   Public
**
** Description      :   Periodic function to test NvM
**
** Invocation       :   In any runnbale
**
** Inputs           :   None
**
** Outputs          :	None
**
** Critical Section :
**
**==========================================================================*/
extern void NvM_MainFunctionTest(void);
void NvM_TestFunction(void);
void NvM_MetricsCaptureTimeStamp(uint8 TimeStampID, uint8 Status);

#endif    /* */
/* end of file */
