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
** Name:           Tracediagcdd_cfg.h
**
** Description:    
**                
**
**====================================================================================================================*/
#ifndef TRACEDIAGCDD_CFG_H
#define TRACEDIAGCDD_CFG_H

/*====================================================================================================================
** INCLUDE FILES
**===================================================================================================================*/
#include "Std_Types.h"
#include "MemLib.h"
#include "Mgrdiagcdd_cfg.h"
//#include "Tracediagcommon_cfg.h"
/*====================================================================================================================
**   M A C R O   D E F I N I T I O N S
**===================================================================================================================*/
#define TRACEDIAG_NVM_WRITE_SERVICE_REQUIRED
#define TRACEDIAG_BCD_ASCII_FORMATMASK

//Enable below station macros based on requirements
#define TRACE_STATION_1  0xA1
#define TRACE_STATION_2  0xA2
#define TRACE_STATION_3  0xA3
//#define TRACE_STATION_4  0xA4
//#define TRACE_STATION_5  0xA5
//#define TRACE_STATION_6  0xA6

#define STATION_STATE 	 1					//STATION_STATE can be DATA_BYTE_1 or DATA_BYTE_0
#define MEET_INDEX_0     ((uint8)0)
#define TRACEABILITY_OVERFLOW_VALUE 1U

#ifdef TRACEDIAG_BCD_ASCII_FORMATMASK
#define TRACEDIAG_cStrVal_AnyAscii    ((uint8) 0x01)
#define TRACEDIAG_cStrVal_Bcd         ((uint8) 0x10)
#define TRACEDIAG_cNullAscii          ((uint8) 0x20)
#define TRACEDIAG_cSpaceAscii         ((uint8) 0x20)
#define TRACEDIAG_cDelAscii           ((uint8) 0x7F)
#define TRACEDIAG_cLowBits            ((uint8) 0x0F)
#define TRACEDIAG_cHighBits           ((uint8) 0xF0)
#define TRACEDIAG_cLowDigitMax        ((uint32) 0x09)
#define TRACEDIAG_cHighDigitMax       ((uint32) 0x90)

#endif
/* Define the actual expected length of the VisteonPartNumber buffer */
#define TRACEDIAG_PART_NUMBER_LEN  10U  /* Example value, adjust to actual size */
/* Define the actual expected length of the VisteonPCBPartNumber buffer */
#define TRACEDIAG_PCB_PART_NUMBER_LEN  10U  /* Adjust to actual project size */
/*======================================================================================================================
** T Y P E  D E F I N I T I O N S
**======================================================================================================================*/
 typedef struct
 {
   uint8 (*Tracediagservice_SetNVM) (uint8* data);
   uint8 (*Tracediagservice_GetNVM) (uint8* data);
   #ifndef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
   void (*Tracediagservice_GetJobStatus) (uint8* data);
   #endif
 }Tracediag_Service;

 typedef struct
{
	void (*Tracediagservice_NVMJob_Write) (uint8 JobStatus);
	void (*Tracediagservice_NVMJob_Read) (uint8 *JobStatus);
}NVM_ReadWrite;

#ifdef TRACEDIAG_TRACEABILITY_BYTES
typedef struct
{
    #ifdef TRACE_STATION_1
    uint8 (*Tracediagservice_SetNVM_TRACE_STATION_1)(uint8 *data);
    uint8 (*Tracediagservice_GetNVM_TRACE_STATION_1)(uint8 *data);
    #endif
    #ifdef TRACE_STATION_2
    uint8 (*Tracediagservice_SetNVM_TRACE_STATION_2)(uint8 *data);
    uint8 (*Tracediagservice_GetNVM_TRACE_STATION_2)(uint8 *data);
    #endif
    #ifdef TRACE_STATION_3
    uint8 (*Tracediagservice_SetNVM_TRACE_STATION_3)(uint8 *data);
    uint8 (*Tracediagservice_GetNVM_TRACE_STATION_3)(uint8 *data);
    #endif
    #ifdef TRACE_STATION_4
    uint8 (*Tracediagservice_SetNVM_TRACE_STATION_4)(uint8 *data);
    uint8 (*Tracediagservice_GetNVM_TRACE_STATION_4)(uint8 *data);
    #endif
    #ifdef TRACE_STATION_5
    uint8 (*Tracediagservice_SetNVM_TRACE_STATION_5)(uint8 *data);
    uint8 (*Tracediagservice_GetNVM_TRACE_STATION_5)(uint8 *data);
    #endif
    #ifdef TRACE_STATION_6
    uint8 (*Tracediagservice_SetNVM_TRACE_STATION_6)(uint8 *data);
    uint8 (*Tracediagservice_GetNVM_TRACE_STATION_6)(uint8 *data);
    #endif
} Tracediag_Service_Trace_Bytes;
#endif

/*=====================================================================================================================
*  C O N S T A N T    A N D   V A R I A B L E S    D E C L A R A T I O N S
**===================================================================================================================*/
#ifdef TRACEDIAG_SERVICE_17			//nvm and soft version read
//referred on releasecfg.cfg

#define ECUSOFTWARENUMBERUPPER_1  '0'
#define ECUSOFTWARENUMBERUPPER_2  '0'

#define ECUSOFTWARENUMBERMIDDLE_1 '2'
#define ECUSOFTWARENUMBERMIDDLE_2 '1'

#define ECUSOFTWARENUMBERLOWER_1 '0'
#define ECUSOFTWARENUMBERLOWER_2 '1'

#define FBL_VERSION_UPPER_1  '0'			//JUST RANDOM VALUE IS ASSIGNED - TEMPORARY
#define FBL_VERSION_UPPER_2  '0'			//NEED TO BE CHANGED 

#define FBL_VERSION_MIDDLE_1 '2'
#define FBL_VERSION_MIDDLE_2 '1'

#define FBL_VERSION_LOWER_1 '0'
#define FBL_VERSION_LOWER_2 '1'

#define MFG_SW_MAJOR_VERSION                ((uint8)0x01)
#define MFG_SW_MINOR_VERSION               ((uint8)0x01)
#define MFG_SW_REVISION              ((uint8)0x21)		

#ifdef MEET_GIP_ENABLED
#define cREAD_GIP_VERSION ((uint32)0xFD03)
#define Cust_FlashSW_Length 6u
#endif
#endif

#define DIDRUNPWRMODE     (DIDBIT3MASK)

#ifdef READ_INTERFACE_FOR_APPL_COMPONENTS
#define ECU_SW2_PART_NUM_DID_ID			0xF120u
#define ECU_SW2_PART_NUM_LENGTH			24U
#endif


#ifdef TRACEDIAG_SERVICE_1
extern const Tracediag_Service  Tracediag_Service_1;
#endif
#ifdef TRACEDIAG_SERVICE_2
extern const Tracediag_Service  Tracediag_Service_2;
#endif
#ifdef TRACEDIAG_SERVICE_3
extern const Tracediag_Service  Tracediag_Service_3;
#endif
#ifdef TRACEDIAG_SERVICE_4
extern const Tracediag_Service  Tracediag_Service_4;
#endif
#ifdef TRACEDIAG_SERVICE_5
extern const Tracediag_Service  Tracediag_Service_5;
#endif
#ifdef TRACEDIAG_SERVICE_6
extern const Tracediag_Service  Tracediag_Service_6;
#endif
#ifdef TRACEDIAG_SERVICE_7
extern const Tracediag_Service  Tracediag_Service_7;
#endif
#ifdef TRACEDIAG_SERVICE_8
extern const Tracediag_Service  Tracediag_Service_8;
#endif
#ifdef TRACEDIAG_SERVICE_9
extern const Tracediag_Service  Tracediag_Service_9;
#endif
#ifdef TRACEDIAG_SERVICE_10
extern const Tracediag_Service  Tracediag_Service_10;
#endif
#ifdef TRACEDIAG_SERVICE_11
extern const Tracediag_Service  Tracediag_Service_11;
#endif
#ifdef TRACEDIAG_SERVICE_12
extern const Tracediag_Service  Tracediag_Service_12;
#endif
#ifdef TRACEDIAG_SERVICE_13
extern const Tracediag_Service  Tracediag_Service_13;
#endif
#ifdef TRACEDIAG_SERVICE_14
extern const Tracediag_Service  Tracediag_Service_14;
#endif
#ifdef TRACEDIAG_SERVICE_15
extern const Tracediag_Service  Tracediag_Service_15;
#endif
#ifdef TRACEDIAG_SERVICE_16
extern const Tracediag_Service  Tracediag_Service_16;
#endif
#ifdef TRACEDIAG_SERVICE_17
extern const Tracediag_Service  Tracediag_Service_17;
#endif
#ifdef TRACEDIAG_SERVICE_18
extern const Tracediag_Service  Tracediag_Service_18;
#endif
#ifdef TRACEDIAG_SERVICE_19
extern const Tracediag_Service  Tracediag_Service_19;
#endif
#ifdef TRACEDIAG_SERVICE_20
extern const Tracediag_Service  Tracediag_Service_20;
#endif
#ifdef TRACEDIAG_SERVICE_24
extern const Tracediag_Service  Tracediag_Service_24;
#endif

#ifdef TRACEDIAG_SERVICE_25
typedef struct
{
	Std_ReturnType (*TraceDiag_Start) (uint8 *Data, uint8 *ErrorCode);
	Std_ReturnType (*TraceDiag_Results) (uint8 *Data, uint8 *ErrorCode);
}TraceDiag_TPFirmware;
extern const TraceDiag_TPFirmware TPFirmwareUpdate;
#endif

#ifdef TRACEDIAG_TRACEBYTES_STATION_1
extern const Tracediag_Service  Tracediag_Service_TraceBytesTRACE_STATION_1;
#endif
#ifdef TRACEDIAG_TRACEBYTES_STATION_2
extern const Tracediag_Service  Tracediag_Service_TraceBytesTRACE_STATION_2;
#endif
#ifdef TRACEDIAG_TRACEBYTES_STATION_3
extern const Tracediag_Service  Tracediag_Service_TraceBytesTRACE_STATION_3;
#endif
#ifdef TRACEDIAG_TRACEBYTES_STATION_4
extern const Tracediag_Service  Tracediag_Service_TraceBytesTRACE_STATION_4;
#endif
#ifdef TRACEDIAG_TRACEBYTES_STATION_5
extern const Tracediag_Service  Tracediag_Service_TraceBytesTRACE_STATION_5;
#endif
#ifdef TRACEDIAG_RESERVEDBYTES
extern const Tracediag_Service  Tracediag_Service_Reservedytes;
#endif
#ifdef TRACEDIAG_TRACEABILITY_BYTES
extern const Tracediag_Service_Trace_Bytes  Tracediag_Service_Station_Traceability_Bytes;
#endif

//NVM Job Status
extern const NVM_ReadWrite Tracediag_NvmJobResult;

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
** Date              :  13/Mar/2023
** CDSID             :  tsubrama
** Traceability      :  RTC-1934747
** Change Description:  Added start and stop routine for TFT FW update, compiler warning fixed
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  03/Aug/2022
** CDSID             :  ddanecha
** Traceability      :  RTC-1707104
** Change Description:  MeetCdd Coverity-MISRA fix
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 6/May/2021
** CDSID             : razhakes
** Traceability      : RTC-1291863
** Change Description: COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM introduced
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  03/march/2019
** CDSID             :  razhakes
** Traceability      :  RTC 1296903
** Change Description:  Tracediagservice_NVMJob_Write and Tracediagservice_NVMJob_Read function position is interchanged in structure defnition and vip-gip communication added
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 10/Oct/2018
** CDSID             : gdhilipr
** Traceability      : RTC 1215565  
** Change Description: Precondition check for product visteon part number
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 01/Oct/2018
** CDSID             : gdhilipr
** Traceability      : RTC 1208270
** Change Description: Traceability services update(FD4D )� For the station WS2 & Generalizing the Station names(ICT - Station1,FCT- Station2,AC  - Station3,FC  -    Station4,WS2 - Station5,AMS to Station6)
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  11/July/2018
** CDSID             :  dkasiman
** Traceability      :  RTC-1148605/RTC-1148623
** Change Description:  Traceability bytes implementation
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  10/Jul/2018  
** CDSID             :  gnataraj
** Traceability      :  RTC-1152264, RTC-1153689
** Change Description:  Peer review comment fixed
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  09/Jul/2018  
** CDSID             :  gnataraj
** Traceability      :  RTC-1152264
** Change Description:  Generalized the function for Read and Write Services
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  06/Jun/2018  
** CDSID             :  dkasiman
** Traceability      :  RTC-1098594
** Change Description:  Review comments fix
**====================================================================================================================*/
/*======================================================================================================================
** Date              : 20/May/2018   
** CDSID             : dkasiman
** Traceability      : RTC-1098594
** Change Description: Initial version for MeetCdd bookshelf  - Traceability services
**=======================================================================================================================*/
#endif


