/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2013. Visteon Corporation owns all rights to           *
* this work and intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right,           *
* under the copyright laws of the United States or those of any              *
* other country that may have jurisdiction, to protect this work             *
* as an unpublished work, in the event of an inadvertent or                  *
* deliberate unauthorized publication. Visteon Corporation also              *
* reserves its rights under all copyright laws to protect this               *
* work as a published work, when appropriate. Those having access            *
* to this work may not copy it, use it, modify it or disclose the            *
* information contained in it without the written authorization              *
* of Visteon Corporation.                                                    *
*                                                                            *
******************************************************************************/
/*****************************************************************************
*  File Name         :  Ea.h                                                 *
*  Module Short Name :  Ea                                                   *
*  Description       :  External API interface for Ea Module                 *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  GHS Multi                                              *
* Target Hardware  :                                                         *
*                                                                            *
******************************************************************************/
#ifndef EA_CBK_H
#define EA_CBK_H
/*****************************************************************************
*                            Include files                                   *
******************************************************************************/

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
#ifndef EA_C
#define EXTERN extern
#else
#define EXTERN
#endif


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

/**************************************************************************
Function name       : void Ea_JobEndNotification(void)
Description         : Service to report to this module the successful end of 
                      an asynchronous operation
Parameters (in)     : None
Parameters (out)    : None
Return value        : None
Design Information  : 
**************************************************************************/
EXTERN void Ea_JobEndNotification(void);

/**************************************************************************
Function name       : void void Ea_JobErrorNotification(void)
Description         : Service to report to this module the failure of an 
                      asynchronous operation.
Parameters (in)     : None
Parameters (out)    : None
Return value        : None
Design Information  : 
**************************************************************************/
EXTERN void Ea_JobErrorNotification(void);


/*****************************************************************************
*                              Limited Scope Prototypes                      *
******************************************************************************/

/*****************************************************************************
*                   Functions                                                *
******************************************************************************/
#undef EXTERN

#endif /* EA_CBK_H */
/*****************************************************************************
*     End of File
*
*******************************************************************************/
/****************************************************************************
*   for each change to this file, be sure to record:                        *
*      1.  who made the change and when the change was made                 *
*      2.  why the change was made and the intended result                  *
*   Following block needs to be repeated for each change                    *
*****************************************************************************/
/**-------------------------------------------------------------------------*/
/*Date              : 22-02-2016                                            */
/*Version           :                                                       */
/*By                : kshaik1                                               */
/*Traceability      : 528464                                                */
/*Change Description: Fixing Coverity Warnings                              */
/*--------------------------------------------------------------------------*/
