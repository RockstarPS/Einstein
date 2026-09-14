/*****************************************************************************
 *                                                                            *
 *              CONFIDENTIAL VISTEON CORPORATION                              *
 *                                                                            *
 * This is an unpublished work of authorship, which contains trade            *
 * secrets, created in 2018. Visteon Corporation owns all rights to           *
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
#ifndef FLSTST_C
#define FLSTST_C
/*!***************************************************************************
 * @ingroup
 * @file FlsTst.c
 * @brief FlsTst main layer which handles the Init, Mainfunctions and APIs for SWCs
 * ****************************************************************************/
/*****************************************************************************
*  Include Files                                                             *
******************************************************************************/
#include "FlsTst.h"
#include "FlsTst_Fgnd.h"
#include "FlsTst_Bgnd.h"
/*****************************************************************************
*  Private Macros Definitions                                                *
******************************************************************************/
#define FLSTSTJOBSTATE_IDLE           (boolean)0
#define FLSTSTJOBSTATE_BUSY           (boolean)1

/******************************************************************************
*  Private Variable Definitions                                               *
*******************************************************************************/
#define FLSTST_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
/**<  Initialize the status variable*/
static FlsTst_StateType FlsTst_State = FLSTST_UNINIT;
static FlsTst_StateType FlsTst_WaitingState = FLSTST_UNINIT;
#define FLSTST_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define FLSTST_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"
Flstst_StateInfotype FlsTst_Infoptr;
#define FLSTST_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

#define VALUE_ONE_UL      1UL
/******************************************************************************
*  Public Function Definitions                                                *
*******************************************************************************/
#define FLSTST_START_SEC_CODE
#include "MemMap.h"

/**
 * This method initialize the FlsTst module
 * @param     none
 * @return    void
 */
void FlsTst_Init(const FlsTst_ConfigType *ConfigPtr)
{
   
}

#if (NO_OF_BNG_BLOCK > 0)
/**
 * This method is the main function for FlsTst module
 * @param     none
 * @return    void
 */
void FlsTst_MainFunction(void)
{

}
#endif /* #if(NO_OF_BNG_BLOCK > 0) */

/**
 * This method De-initialize the FlsTst module
 * @param     none
 * @return    void
 */
void FlsTst_DeInit(void)
{
   
}

#if (FLSTST_STARTFGND_API == STD_ON)
/**
 * This Service for executing foreground Flash Test.
 * @param     FgndBlockId: Number of the foreground test to be executed.
 * @return    E_OK: Foreground test processed
 *            E_NOT_OK: Foreground test not accepted
 */
Std_ReturnType FlsTst_StartFgnd(FlsTst_BlockIdFgndType FgndBlockId)
{
    Std_ReturnType ret = E_NOT_OK;
    return ret;
}
#endif /* #if(FLSTST_STARTFGND_API == STD_ON) */

#if (FLSTST_ABORT_API == STD_ON)
/**
 * This Service for aborting the Flash Test.
 * @param     none
 * @return    void
 */
void FlsTst_Abort(void)
{

}
#endif /* #if(FLSTST_ABORT_API == STD_ON) */

#if (FLSTST_SUSPEND_API == STD_ON)
/**
 * This Service for suspending current operation of the Flash Test, until FlsTst_Resume is called.
 * @param     none
 * @return    void
 */
void FlsTst_Suspend(void)
{

}
#endif/* #if(FLSTST_SUSPEND_API == STD_ON) */

#if (FLSTST_RESUME_API == STD_ON)
/**
 * This Service for continuing the Flash Test at the point it was suspended.
 * @param     none
 * @return    void
 */
void FlsTst_Resume(void)
{

}
#endif /* #if(FLSTST_RESUME_API == STD_ON) */

#if (FLSTST_GETCURRENTSTATE_API == STD_ON)
/**
 * This Service returns the current Flash Test exection state.
 * @param     none
 * @return    FLSTST_UNINIT :The Flash Test is not initialized or not usable.
 *            FLSTST_INIT   :The Flash Test is initialized and ready to be started.
 *            FLSTST_RUNNING:The Flash Test is currently running.
 *            FLSTST_ABORTED:The Flash Test is aborted.
 *            FLSTST_SUSPENDED :The Flash Test is waiting to be resumed or is waiting to start forground mode test
 */
FlsTst_StateType FlsTst_GetCurrentState(void)
{
    return FlsTst_State;
}
#endif /* #if(FLSTST_GETCURRENTSTATE_API == STD_ON) */

#if (FLSTST_GETTESTRESULTBGND_API == STD_ON)
/**
 * Service returns the Background Flash Test result.
 * @param     none
 * @return    FLSTST_NOT_TESTED :There is no result available.
 *            FLSTST_OK :The last Flash Test has been tested with OK result.
 *            FLSTST_NOT_OK:The last Flash Test has been tested with NOT_OK result.
 */
FlsTst_TestResultBgndType FlsTst_GetTestResultBgnd(void)
{
    FlsTst_TestResultBgndType FlsTstStatus;

    return FlsTstStatus;
}
#endif /* #if(FLSTST_GETTESTRESULTBGND_API == STD_ON) */

#if (FLSTST_GETTESTRESULTFGND_API == STD_ON)
/**
 * Service returns the Foreground Flash Test result.
 * @param     none
 * @return    void
 */
FlsTst_TestResultFgndType FlsTst_GetTestResultFgnd(void)
{
    FlsTst_TestResultFgndType FlsTstStatus;

    return FlsTstStatus;
}
#endif /* #if (FLSTST_GETTESTRESULTBGND_API == STD_ON) */

#if (FLSTST_GETVERSIONINFO_API == STD_ON)
/**
 * Service returns the version information of this module.
 * @param     versioninfo :Pointer to where to store the version information of this module.
 * @return    void
 */
void FlsTst_GetVersionInfo(Std_VersionInfoType *versioninfo)
{
    (void)versioninfo;
}
#endif /* #if (FLSTST_GETVERSIONINFO_API == STD_ON) */

/**
 * This method De-initialize the FlsTst module
 * @param     none
 * @return    void
 */
/*FlsTst_TestSignatureBgndType FlsTst_GetTestSignatureBgnd( void )
{
}*/

/**
 * This method De-initialize the FlsTst module
 * @param     none
 * @return    void
 */
/*FlsTst_TestSignatureFgndType FlsTst_GetTestSignatureFgnd( void )
{
}*/

/**
 * Service returns error details monitored from the Flash module.
 * @param     none
 * @return    result:FLSTST_RESULT_NOT_TESTED = 0x0, FLSTST_RESULT_OK, FLSTST_RESULT_NOT_OK
 *            BitError: Error bit number
 *            blockID: block Id number
 */
#if (FLSTST_GETERRORDETAILS_API == STD_ON)
FlsTst_ErrorDetailsType FlsTst_GetErrorDetails(void)
{
    return FlsTst_Infoptr.BgndErrorInfo;
}
#endif /* #if(FLSTST_GETERRORDETAILS_API == STD_ON) */

#if (FLSTST_TESTECC_API == STD_ON)
/**
 * Service executes a test of ECC hardware.
 * @param     none
 * @return    Std_ReturnType
 */
Std_ReturnType FlsTst_TestEcc(void)
{
    /* register details are need to check error status */
    return 0;
}
#endif /* #if (FLSTST_TESTECC_API == STD_ON) */

#define FLSTST_STOP_SEC_CODE
#include "MemMap.h"


#endif /* FLSTST_C */
/*End of File*/
/*****************************************************************************
 *  for each change to this file, be sure to record:                         *
 *     1.  who made the change and when the change was made                  *
 *     2.  why the change was made and the intended result                   *
 *  Following block needs to be repeated for each change
 ******************************************************************************
 *  Note: In the trace-ability column we need to trace back to the Design Doc.*
 *  For the initial version it is traced to the Design Document section.     *
 *  For further changes it shall trace to the source of the change which may *
 *  be SPSS/SCR/Defect details(Defect may be Testing/validation defect)/Any  *
 *  other reason                                                            *
 ******************************************************************************/
/*****************************************************************************
 Date              :16-Jul-2020
 By                :bbaskara
 Traceability      :RTC
 Change Description:Initial Version for FlsTst implementation
 ******************************************************************************/
 /*****************************************************************************
 Date              :28-Mar-2022
 By                :gthanapp
 Traceability      :RTC#1564070
 Change Description:Cert-C warning analysis and fix 
 ******************************************************************************/
 /*****************************************************************************
 Date              :05-MaY-2022
 By                :nchellap
 Traceability      :RTC#1654166
 Change Description:Coverity Misra Analyse and Fix
 ******************************************************************************/
 /*****************************************************************************
 Date              :06-Jun-2022
 By                :jkanikal
 Traceability      :RTC#1654166
 Change Description:FlsTst implementation
 ******************************************************************************/
