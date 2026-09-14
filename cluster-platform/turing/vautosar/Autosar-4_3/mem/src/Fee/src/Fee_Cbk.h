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
#ifndef FEE_CBK_H
#define FEE_CBK_H
/*****************************************************************************
*  File Name         :  Fee_Cbk.h                                            *
*  Module Short Name :  Fee                                                  *
*  Description       :  External API interface for Fee Module                *
*                                                                            *
*  Organization      :  Driver Information Software Section,                 *
*                       Visteon Software Operation                           *
*                       Visteon Corporation                                  *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  GHS Multi                                              *
* Target Hardware  :                                                         *
*                                                                            *
******************************************************************************/
/********************************************************************************************
Function name   : void Fee_JobErrorNotification(void)
Arguments       : void
Return type     : void
Description     : Service to report to this module the failure of an asynchronous operation.
*********************************************************************************************/
extern void Fee_JobErrorNotification(void);

/***************************************************************************************************
Function name   : void Fee_JobEndNotification(void)
Arguments       : void
Return type     : void
Description     : Service to report to this module the successful end of an asynchronous operation.
****************************************************************************************************/
extern void Fee_JobEndNotification(void);


#endif /* FEE_CBK_H */
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
/*Date              :                                            			*/
/*Version           :                                                       */
/*By                :                                               		*/
/*Traceability      :                                                       */
/*Change Description:  														*/
/*--------------------------------------------------------------------------*/



