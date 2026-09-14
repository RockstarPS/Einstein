/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2020. Visteon Corporation owns all rights to           *
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
* File Name         :  DisplayCdd_Types.h                                      *
* Module Short Name :  DisplayCdd_Types                                        *
* Description       :  Header file for DisplayCdd component                    *
*                                                                            *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  GHS Multi                                              *
* Target Hardware  :  Turing Platform                                        *
*                                                                            *
******************************************************************************/
#ifndef DISPLAYCDDTYPES_H
#define DISPLAYCDDTYPES_H

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "Std_Types.h"

/********************************************************************************************
*  Compiler Switches                                                   
**********************************************************************************************/

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/

/*
Description: To hold the details related to PreInit condition Check
*/
typedef enum
{
    DisplayInitNotStarted = 0u,
    DisplayStartInit,
    DisplayInitCompleted
}EDisplayInit;

typedef struct 
{
    Std_ReturnType (*displayPrecheck_ptr)(void);                    /*PreInit Condition Check Callback*/
    Std_ReturnType  (*displayReadNVMDisplayType) (uint8 deviceId);
    uint8           DisplayDetectMethod; /*Auto detection either by I2C or Bootstrap*/
    Std_ReturnType  (*displayWriteNVMDisplayType) (uint8 deviceId); 
}sDisplayPreInitConfigInfo;


typedef enum
{
    SEND_COMMAND,
    WAIT_ACKNOWLEDGE
} DetectionStates;

typedef struct 
{
    EDisplayInit               DisplayCddInitState;
    boolean                    DisplayAutoDetectionEnabled; /*TRUE- System entered into AutoDetection*/
    boolean                    IdentifiedDeviceStatus;      /*TRUE- Once Successful Identification of Device*/
    uint8                      IdentifiedDeviceID;          /*FF- If device not identified, else (0 to <maxdevice)*/
}sDisplayAutoDetect;

typedef struct
{       
    uint8		   DeviceStatus;		        	/* Hold the repective device status as ready , NotReady , Busy*/
	uint8		   DevicePowerState;				/*Hold the repective device power state as POWERON , NORMAL , FAULT , POWEROFF */
    uint8         DisplayNotifiedState;            /*Hole the requested notified state in different stages of statemachine*/
}SDisplayInfo;


typedef void (* TDrv_Call_Init)(uint8 DevInd);
typedef struct 
{
    TDrv_Call_Init Drv_Init;
}CDisplayDrvCddInitCall;


typedef void (* TDrv_Call_DeInit)(uint8 DevInd);
typedef struct 
{
    TDrv_Call_DeInit Drv_DeInit;
}CDisplayDrvCddDeInitCall;


typedef void (* TDrv_Call_Main)(uint8 DevInd);
typedef struct 
{
    TDrv_Call_Main Drv_Main;
}CDisplayDrvCddMainCall;



/*============================================================================
**
**============================================================================
** C M S    R E V I S I O N    N O T E S
**============================================================================
**
** For each change to this file, be sure to record:
** 1.  Who made the change and when the change was made.
** 2.  Why the change was made and the intended result.
**
** CMS Rev #        Date         By
** CMS Rev X.X      mm/dd/yy     CDSID
**
**============================================================================*/
/*------------------------------------------------------------------------------
Date              : 4th Jan 2023
By                : agopi
Traceability      : RTC #
Change Description: Initial Version
-------------------------------------------------------------------------------*/
#endif

/* end of file =============================================================*/

