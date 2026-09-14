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
** Name:           Tracediagcdd.h
**
** Description:
**
**
**====================================================================================================================*/
#ifndef TRACEDIAGCDD_H
#define TRACEDIAGCDD_H

/*====================================================================================================================
** INCLUDE FILES
**===================================================================================================================*/
#include "Std_Types.h"
#include "Tracediagcdd_cfg.h"
/*====================================================================================================================
**   M A C R O   D E F I N I T I O N S
**===================================================================================================================*/

/*======================================================================================================================
** T Y P E  D E F I N I T I O N S
**======================================================================================================================*/
typedef enum
{
    eROUTINE_TFT_NOTACTIVE,
    eROUTINE_TFT_INPROGRESS,
    eROUTINE_TFT_SUCCESS,
    eROUTINE_TFT_FAILURE,
} eRoutineStatusTFT;

/*=====================================================================================================================
 *  C O N S T A N T    A N D   V A R I A B L E S    D E C L A R A T I O N S
 **===================================================================================================================*/

/*=====================================================================================================================
 *   P U B L I C
 **=====================================================================================================================*/

#ifdef TRACEDIAG_SERVICE_1
Std_ReturnType Tracediag_Read_Service_1(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Tracediag_Write_Service_1(uint8 *Data, uint8 *ErrorCode);
#endif
#ifdef TRACEDIAG_SERVICE_2
Std_ReturnType Tracediag_Read_Service_2(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Tracediag_Write_Service_2(uint8 *Data, uint8 *ErrorCode);
#endif
#ifdef TRACEDIAG_SERVICE_3
Std_ReturnType Tracediag_Read_Service_3(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Tracediag_Write_Service_3(uint8 *Data, uint8 *ErrorCode);
#endif
#ifdef TRACEDIAG_SERVICE_4
Std_ReturnType Tracediag_Read_Service_4(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Tracediag_Write_Service_4(uint8 *Data, uint8 *ErrorCode);
#endif
#ifdef TRACEDIAG_SERVICE_5
Std_ReturnType Tracediag_Read_Service_5(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Tracediag_Write_Service_5(uint8 *Data, uint8 *ErrorCode);
#endif
#ifdef TRACEDIAG_SERVICE_6
Std_ReturnType Tracediag_Read_Service_6(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Tracediag_Write_Service_6(uint8 *Data, uint8 *ErrorCode);
#endif
#ifdef TRACEDIAG_SERVICE_7
Std_ReturnType Tracediag_Read_Service_7(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Tracediag_Write_Service_7(uint8 *Data, uint8 *ErrorCode);
#endif
#ifdef TRACEDIAG_SERVICE_8
Std_ReturnType Tracediag_Read_Service_8(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Tracediag_Write_Service_8(uint8 *Data, uint8 *ErrorCode);
#endif
#ifdef TRACEDIAG_SERVICE_9
Std_ReturnType Tracediag_Read_Service_9(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Tracediag_Write_Service_9(uint8 *Data, uint8 *ErrorCode);
#endif
#ifdef TRACEDIAG_SERVICE_10
Std_ReturnType Tracediag_Read_Service_10(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Tracediag_Write_Service_10(uint8 *Data, uint8 *ErrorCode);
#endif
#ifdef TRACEDIAG_SERVICE_11
Std_ReturnType Tracediag_Read_Service_11(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Tracediag_Write_Service_11(uint8 *Data, uint8 *ErrorCode);
#endif
#ifdef TRACEDIAG_SERVICE_12
Std_ReturnType Tracediag_Read_Service_12(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Tracediag_Write_Service_12(uint8 *Data, uint8 *ErrorCode);
#endif
#ifdef TRACEDIAG_SERVICE_13
Std_ReturnType Tracediag_Read_Service_13(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Tracediag_Write_Service_13(uint8 *Data, uint8 *ErrorCode);
#endif
#ifdef TRACEDIAG_SERVICE_14
Std_ReturnType Tracediag_Read_Service_14(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Tracediag_Write_Service_14(uint8 *Data, uint8 *ErrorCode);
#endif
#ifdef TRACEDIAG_SERVICE_15
Std_ReturnType Tracediag_Read_Service_15(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Tracediag_Write_Service_15(uint8 *Data, uint8 *ErrorCode);
#endif
#ifdef TRACEDIAG_SERVICE_16
Std_ReturnType Tracediag_Read_Service_16(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Tracediag_Write_Service_16(uint8 *Data, uint8 *ErrorCode);
#endif
#ifdef TRACEDIAG_SERVICE_17
Std_ReturnType Tracediag_Read_Service_17(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Tracediag_Write_Service_17(uint8 *Data, uint8 *ErrorCode);
#endif
#ifdef TRACEDIAG_SERVICE_18
Std_ReturnType Tracediag_Read_Service_18(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Tracediag_Write_Service_18(uint8 *Data, uint8 *ErrorCode);
#endif
#ifdef TRACEDIAG_SERVICE_19
Std_ReturnType Tracediag_Read_Service_19(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Tracediag_Write_Service_19(uint8 *Data, uint8 *ErrorCode);
#endif
#ifdef TRACEDIAG_SERVICE_20
Std_ReturnType Tracediag_Read_Service_20(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Tracediag_Write_Service_20(uint8 *Data, uint8 *ErrorCode);
#endif
#ifdef TRACEDIAG_SERVICE_21
Std_ReturnType Tracediag_Read_Service_21(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Tracediag_Write_Service_21(uint8 *Data, uint8 *ErrorCode);
#endif

#ifdef TRACEDIAG_SERVICE_22
Std_ReturnType Tracediag_Read_Service_22(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Tracediag_Write_Service_22(uint8 *Data, uint8 *ErrorCode);
#endif

#ifdef TRACEDIAG_SERVICE_23
Std_ReturnType Tracediag_Read_Service_23(uint8 *Data, uint8 *ErrorCode);
#endif

#ifdef TRACEDIAG_SERVICE_24
Std_ReturnType Tracediag_Read_Service_24(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Tracediag_Write_Service_24(uint8 *Data, uint8 *ErrorCode);
#endif

#ifdef TRACEDIAG_SERVICE_25
Std_ReturnType Tracediag_TPFirmware_Update_RCStart(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Tracediag_TPFirmware_Update_RCStatus(uint8 *Data, uint8 *ErrorCode);
#endif

#ifdef TRACEDIAG_TRACEBYTES_STATION_1
Std_ReturnType Tracediag_Traceability_Bytes_TRACE_STATION_1_Read(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Tracediag_Traceability_Bytes_TRACE_STATION_1_Write(uint8 *Data, uint8 *ErrorCode);
#endif
#ifdef TRACEDIAG_TRACEBYTES_STATION_2
Std_ReturnType Tracediag_Traceability_Bytes_TRACE_STATION_2_Read(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Tracediag_Traceability_Bytes_TRACE_STATION_2_Write(uint8 *Data, uint8 *ErrorCode);
#endif
#ifdef TRACEDIAG_TRACEBYTES_STATION_3
Std_ReturnType Tracediag_Traceability_Bytes_TRACE_STATION_3_Read(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Tracediag_Traceability_Bytes_TRACE_STATION_3_Write(uint8 *Data, uint8 *ErrorCode);
#endif
#ifdef TRACEDIAG_TRACEBYTES_STATION_4
Std_ReturnType Tracediag_Traceability_Bytes_TRACE_STATION_4_Read(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Tracediag_Traceability_Bytes_TRACE_STATION_4_Write(uint8 *Data, uint8 *ErrorCode);
#endif
#ifdef TRACEDIAG_TRACEBYTES_STATION_5
Std_ReturnType Tracediag_Traceability_Bytes_TRACE_STATION_5_Read(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Tracediag_Traceability_Bytes_TRACE_STATION_5_Write(uint8 *Data, uint8 *ErrorCode);
#endif
#ifdef TRACEDIAG_RESERVEDBYTES
Std_ReturnType Tracediag_Reserved_Bytes_Read(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Tracediag_Reserved_Bytes_Write(uint8 *Data, uint8 *ErrorCode);
#endif

#ifdef TRACEDIAG_TRACEABILITY_BYTES
Std_ReturnType Tracediag_Traceability_Bytes_Read(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Tracediag_Traceability_Bytes_Write(uint8 *Data, uint8 *ErrorCode);
#endif
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
** Date              :  13/09/2023
** CDSID             :  mprajapa
** Traceability      :  JIRA 3839
** Change Description:  Upddated identation.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  12/Apr/2023
** CDSID             :  spalan11
** Traceability      :  RTC-1977277
** Change Description:  Added Tracediag_Write_Service_24() and removed Tracediag_Read_Status_24()
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  13/Mar/2023
** CDSID             :  tsubrama
** Traceability      :  RTC-1934747
** Change Description:  Added start and stop routine for TFT FW update
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 01/Oct/2018
** CDSID             : gdhilipr
** Traceability      : RTC 1208270
** Change Description: Traceability services update(FD4D )– For the station WS2 & Generalizing the Station names(ICT - Station1,FCT- Station2,AC  - Station3,FC  -  Station4,WS2 - Station5,AMS to Station6)
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
** Change Description:  Peer review comments fixed
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
** Change Description: Initial verion for MeetCdd bookshelf - Traceability services
**=======================================================================================================================*/
#endif /* TRACEDIAGCDD_H */
