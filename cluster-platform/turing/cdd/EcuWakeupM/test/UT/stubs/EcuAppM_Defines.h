/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2023. Visteon Corporation owns all rights to           *
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
*  File Name         :  EcuAppM_Defines.h                                    *
*  Module Short Name :  EcuAppM_Defines                                      *
*  Description       :  This file contains declations of the Autosar ECUAPP  *
*                       Manager types and macros                       		 *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  GHS Multi                                              *
* Target Hardware  :  Platform Indpendent                                    *
*                                                                            *
******************************************************************************/
#ifndef __ECUAPPM_DEFINES_H_
#define __ECUAPPM_DEFINES_H_
/*****************************************************************************
*                            Include files                                   *
******************************************************************************/

/*****************************************************************************
*                         Function Declarations                              *
******************************************************************************/


/*****************************************************************************
*                           Type Declarations                          		 *
******************************************************************************/

/*  Api's macro definations   */
#define ECUAPPM_API_INIT 						0x00u
#define ECUAPPM_API_MAIN_FUNC 					0x01u
#define ECUAPPM_API_GET_APPSLEEPSTATUS_FUNC   	0x02u
#define ECUAPPM_API_GET_WAKEUPEVENT_FUNC		0x03u
#define ECUAPPM_API_SET_ECUAPPMSTATE_FUNC		0x04u
#define ECUAPPM_API_GET_WAKEUPSOURCES_FUNC		0x05u
#define ECUAPPM_API_SET_WAKEUPSOURCES_FUNC		0x06u
#define ECUAPPM_API_CLEAR_WAKEUPSOURCES_FUNC	0x07u

/*  error macro definations   */
#define ECUAPPM_S_UNINITIALIZED				0x00u
#define ECUAPPM_S_INITIALIZED   			0x01u


#define ECUAPPM_E_ALREADYINITIALIZED 		0x02u
#define ECUAPPM_E_UNINT						0x03u

#endif
/*****************************************************************************
	Date              	: 20-11-23
	CDSID             	: akappa
    Traceability      	:
    Change Description	: Initial Version.
******************************************************************************/
/* End Of File */
