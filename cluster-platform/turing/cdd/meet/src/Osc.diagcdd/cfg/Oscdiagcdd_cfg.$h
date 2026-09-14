/*===================================================================================================================
**
**                     CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2001. Visteon Corporation owns all rights to this work and
** intends to maintain it in confidence to preserve its trade secret status.
** Visteon Corporation reserves the right, under the copyright laws of the
** United States or those of any other country that may have jurisdiction,
** to protect this work as an unpublished work, in the event of an
** inadvertent or deliberate unauthorized publication. Visteon Corporation
** also reserves its rights under all copyright laws to protect this work as
** a published work, when appropriate. Those having access to this work may
** not copy it, use it, modify it or disclose the information contained in
** it without the written authorization of Visteon Corporation.
**
**===================================================================================================================
**
** Name:           Oscdiagcdd_cfg.h
**
** Description:    
**                
**
**====================================================================================================================*/
#ifndef OSCDIAGCDD_CFG_H
#define OSCDIAGCDD_CFG_H

/*====================================================================================================================
** INCLUDE FILES
**===================================================================================================================*/
#include "Std_Types.h"
#include "Mgrdiagcdd_cfg.h"
#ifdef OSCDIAG_QUARTZ_CONTROL
#include "Port.h"
#include "Mcu_Types.h"
#include "Mcu_Regs.h"
#endif
/*====================================================================================================================
**   M A C R O   D E F I N I T I O N S
**===================================================================================================================*/
#ifdef OSCDIAG_QUARTZ_CONTROL
#define MAX_NUMBER_OF_QUARTZ_SIGNAL 	3
#define MIN_NUMBER_OF_QUARTZ_SIGNAL		1
#endif

#ifdef OSCDIAG_QUARTZ_CORRECTION

/*======================================================================================================================
** T Y P E  D E F I N I T I O N S
**======================================================================================================================*/

typedef struct
{
   uint8 (*Oscdiagservice_SetNVM) (uint8* data);
   uint8 (*Oscdiagservice_GetNVM) (uint8* data);
   void (*Oscdiagservice_SetJobStatus) (uint8 JobStatus);
   void (*Oscdiagservice_GetJobStatus) (uint8* JobStatus);
}Oscdiag_Service;
#endif

#ifdef OSCDIAG_QUARTZ_CONTROL
typedef struct
{
	Std_ReturnType (*Oscdiagservice_quartz_control_STA)(uint8 *ErrorCode);
}Oscdiagservice_quartz_ctrl_STA;


typedef struct
{
	Std_ReturnType (*Oscdiagservice_quartz_control_RCTE)(uint8 *ErrorCode);
}Oscdiagservice_quartz_ctrl_RCTE;
#endif

#ifdef OSCDIAG_CLOCKVALUE_ENABLE
typedef struct
{
	Std_ReturnType (*ClockValueReadFunction) (uint8 *Data);
	Std_ReturnType (*ClockValueWriteFunction) (uint8 *Data);
}Meet_ClockValueConfigType;


//extern Std_ReturnType RtcCdd_SetTimeDate(const Rtc_TimeDateType* TimeDate);
//extern Std_ReturnType RtcCdd_GetTimeDate(Rtc_TimeDateType* pTimeDate);

#endif
/*=====================================================================================================================
*  C O N S T A N T    A N D   V A R I A B L E S    D E C L A R A T I O N S
**===================================================================================================================*/
#ifdef OSCDIAG_QUARTZ_CORRECTION
extern const Oscdiag_Service Oscdiag_Service_Map;
#endif
#ifdef OSCDIAG_QUARTZ_CONTROL
extern const Oscdiagservice_quartz_ctrl_STA OscdiagService_quartz_control_STA_Map[3];
extern const Oscdiagservice_quartz_ctrl_RCTE OscdiagService_quartz_control_RCTE_Map[1];
void Meet_SetRegClockOutput(uint8 Cksel, uint8 Ckoutdiv, boolean Enclko);
#endif

#ifdef OSCDIAG_CLOCKVALUE_ENABLE
extern const Meet_ClockValueConfigType Meet_ClockConfig;
#endif

#ifdef OSCDIAG_CLOCK_MONITORING
Std_ReturnType Oscdiag_ClockMonitoring_start(uint8 *Data);
#endif
/*=====================================================================================================================
*   P U B L I C
**=====================================================================================================================*/

/*======================================================================================================================
**  for each change to this file, be sure to record:
**  1.who made the change and when the change was made
**  2.why the change was made and the intended result
**  following block needs to be repeated for each change
**======================================================================================================================*/
/*   Note: In the traceability column we need to trace back to the Design Doc.
**   For the initial version it is traced to the Design Document section.     
**   For further changes it shall trace to the source of the change which may
**   be SPSS/SCR/Defect details(Defect may be Testing/validation defect)/Any  
**   other reason                                                             
**======================================================================================================================*/ 
/*=====================================================================================================================
** Date              :  20/Jun/2022
** CDSID             :  kkarupp1
** Traceability      :  RTC-1670983
** Change Description: Clock monitoring DR newly added
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  16/05/2022
** CDSID             :  ddanecha
** Traceability      :  RTC 1632871, 1655512, 1660171
** Change Description:  Typedefs and macros are added to support clock value read and write interfaces.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  12/march/2019
** CDSID             :  razhakes
** Traceability      :  RTC 1268470
** Change Description:  vip - gip communication communication for quartz control is added
**====================================================================================================================*/
/*======================================================================================================================
** Date              : 23/May/2018    
** CDSID             : dkasiman
** Traceability      : RTC-1111915
** Change Description: Initial verion for MeetCdd bookshelf - Osc diag services
**=======================================================================================================================*/
/*======================================================================================================================
** Date              : 5/Jun/2018
** CDSID             : dkasiman
** Traceability      : RTC-1111915
** Change Description: Review comments fix - Osc diag services
**=======================================================================================================================*/
#endif


