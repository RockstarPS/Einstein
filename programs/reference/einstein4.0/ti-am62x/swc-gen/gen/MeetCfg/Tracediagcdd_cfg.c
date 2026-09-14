/*=================================================================================================================
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
**==================================================================================================================
**
** Name:           Tracediagcdd_cfg.c
**
** Description:    
**                 
**
**===================================================================================================================*/

#ifndef TRACEDIAGCDD_CFG_C
#define TRACEDIAGCDD_CFG_C

/*====================================================================================================================
**                 I N C L U D E   F I L E S
**===================================================================================================================*/
#include "Std_Types.h"
#include "Tracediagcdd_cfg.h"
#include "Mgrdiagcdd.h"
#ifdef TRACEDIAG_SERVICE_17
#include "Releasecfg.cfg"		//include for mfg_SW_version/vip version read
#endif
/*====================================================================================================================
**   I N T E R N A L   M A C R O   D E F I N I T I O N S
**===================================================================================================================*/
#define TRACE_STATION_ICT_POS 	0u
#define TRACE_STATION_FCT_POS 	1u
#define TRACE_STATION_ASM_POS 	2u
#define TRACE_STATION_AC_POS 	3u
#define TRACE_STATION_FC_POS 	4u

/*=====================================================================================================================
**  T Y P E    D E C L A R A T I O N S 
**====================================================================================================================*/
#ifdef TRACEDIAG_SERVICE_17
#ifdef MEET_GIP_ENABLED
static GIPDataRquestState Tracediag_CurrentGIPState = eGIP_InitiateRequest;
#endif
#endif

/*=====================================================================================================================
**  C O N S T A N T    A N D   V A R I A B L E S    D E C L A R A T I O N S
**====================================================================================================================*/
#ifdef TRACEDIAG_SERVICE_17
static const char VIP_SW_MAJOR_VERSION[] = {ECUSOFTWARENUMBERUPPER_1,ECUSOFTWARENUMBERUPPER_2};
static const char VIP_SW_MINOR_VERSION[] = {ECUSOFTWARENUMBERMIDDLE_1,ECUSOFTWARENUMBERMIDDLE_2};
static const char VIP_SW_REVISION[] = {ECUSOFTWARENUMBERLOWER_1,ECUSOFTWARENUMBERLOWER_2};

static const char BOOT_SW_MAJOR_VERSION[] = {FBL_VERSION_UPPER_1,FBL_VERSION_UPPER_2};
static const char BOOT_SW_MINOR_VERSION[] = {FBL_VERSION_MIDDLE_1,FBL_VERSION_MIDDLE_2};
static const char BOOT_SW_REVISION[] = {FBL_VERSION_LOWER_1,FBL_VERSION_LOWER_2};
#endif

#ifdef TRACEDIAG_SERVICE_20
static boolean JTAG_PASS_WRITE_STATUS = FALSE;
#endif
/*=====================================================================================================================
**  PUBLIC
**====================================================================================================================*/

/*=====================================================================================================================
**  PRIVATE
**====================================================================================================================*/
static boolean Tracediag_Service_checkASCIIRange(const uint8 *data, uint8 didLength);

#ifdef TRACEDIAG_SERVICE_1
static uint8 Tracediag_Service_1_Set_NVMData(const uint8 *data);
static Std_ReturnType Tracediag_Service_1_Get_NVMData(uint8 *data);
#ifndef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
static void Tracediag_Service_1_Get_NVMJobStatus(uint8 *data);
#endif

#ifdef TRACEDIAG_RANGECHECK
static Std_ReturnType Tracediag_IsStringInRange(P2CONST(uint8, AUTOMATIC, RTE_STPCDD_APPL_VAR) Data,uint8 u8SizeP,uint8 u8FormatMaskP );
static Std_ReturnType Tracediag_IsByteInRange( uint8 u8ByteP, uint8 u8FormatMaskP );
#endif
#endif

#ifdef TRACEDIAG_SERVICE_2
static uint8 Tracediag_Service_2_Set_NVMData(const uint8 *data);
static uint8 Tracediag_Service_2_Get_NVMData(uint8 *data);
#ifndef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
static void Tracediag_Service_2_Get_NVMJobStatus(uint8 *data);
#endif
#endif

#ifdef TRACEDIAG_SERVICE_3
static uint8 Tracediag_Service_3_Set_NVMData(const uint8 *data);
static uint8 Tracediag_Service_3_Get_NVMData(uint8 *data);
#ifndef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
static void Tracediag_Service_3_Get_NVMJobStatus(uint8 *data);
#endif


#ifdef TRACEDIAG_RANGECHECK
static Std_ReturnType Tracediag_IsStringInRange_1(P2CONST(uint8, AUTOMATIC, RTE_STPCDD_APPL_VAR) Data,uint8 u8SizeP,uint8 u8FormatMaskP );
static Std_ReturnType Tracediag_IsByteInRange_1( uint8 u8ByteP, uint8 u8FormatMaskP );
#endif
#endif

#ifdef TRACEDIAG_SERVICE_4
static uint8 Tracediag_Service_4_Set_NVMData(const uint8 *data);
static uint8 Tracediag_Service_4_Get_NVMData(uint8 *data);
#ifndef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
static void Tracediag_Service_4_Get_NVMJobStatus(uint8 *data);
#endif
#endif

#ifdef TRACEDIAG_SERVICE_5
static uint8 Tracediag_Service_5_Set_NVMData(const uint8 *data);
static uint8 Tracediag_Service_5_Get_NVMData(uint8 *data);
#ifndef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
static void Tracediag_Service_5_Get_NVMJobStatus(uint8 *data);
#endif
#endif

#ifdef TRACEDIAG_SERVICE_6
static uint8 Tracediag_Service_6_Set_NVMData(const uint8 *data);
static uint8 Tracediag_Service_6_Get_NVMData(uint8 *data);
#ifndef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
static void Tracediag_Service_6_Get_NVMJobStatus(uint8 *data);
#endif
#endif

#ifdef TRACEDIAG_SERVICE_7
static uint8 Tracediag_Service_7_Set_NVMData(const uint8 *data);
static uint8 Tracediag_Service_7_Get_NVMData(uint8 *data);
#ifndef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
static void Tracediag_Service_7_Get_NVMJobStatus(uint8 *data);
#endif
#endif

#ifdef TRACEDIAG_SERVICE_8
static uint8 Tracediag_Service_8_Set_NVMData(const uint8 *data);
static uint8 Tracediag_Service_8_Get_NVMData(uint8 *data);
#ifndef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
static void Tracediag_Service_8_Get_NVMJobStatus(uint8 *data);
#endif
#endif

#ifdef TRACEDIAG_SERVICE_9
static uint16 Tracediag_Service_9_Set_NVMData(uint16 data);
static uint16 Tracediag_Service_9_Get_NVMData(uint16 *data);
#ifndef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
static void Tracediag_Service_9_Get_NVMJobStatus(uint8 *data);
#endif
#endif

#ifdef TRACEDIAG_SERVICE_10
static uint8 Tracediag_Service_10_Set_NVMData(uint8 *data);
static uint8 Tracediag_Service_10_Get_NVMData(uint8 *data);
#ifndef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
static void Tracediag_Service_10_Get_NVMJobStatus(uint8 *data);
#endif
#endif


#ifdef TRACEDIAG_SERVICE_11
static uint8 Tracediag_Service_11_Set_NVMData(uint8 *data);
static uint8 Tracediag_Service_11_Get_NVMData(uint8 *data);
#ifndef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
static void Tracediag_Service_11_Get_NVMJobStatus(uint8 *data);
#endif
#endif

#ifdef TRACEDIAG_SERVICE_12
static uint8 Tracediag_Service_12_Set_NVMData(uint8 *data);
static uint8 Tracediag_Service_12_Get_NVMData(uint8 *data);
#ifndef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
static void Tracediag_Service_12_Get_NVMJobStatus(uint8 *data);
#endif
#endif

#ifdef TRACEDIAG_SERVICE_13
static uint8 Tracediag_Service_13_Set_NVMData(uint8 *data);
static uint8 Tracediag_Service_13_Get_NVMData(uint8 *data);
#ifndef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
static void Tracediag_Service_13_Get_NVMJobStatus(uint8 *data);
#endif
#endif

#ifdef TRACEDIAG_SERVICE_14
static uint8 Tracediag_Service_14_Set_NVMData(uint8 *data);
static uint8 Tracediag_Service_14_Get_NVMData(uint8 *data);
#ifndef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
static void Tracediag_Service_14_Get_NVMJobStatus(uint8 *data);
#endif
#endif

#ifdef TRACEDIAG_SERVICE_15
static uint8 Tracediag_Service_15_Set_NVMData(uint8 *data);
static uint8 Tracediag_Service_15_Get_NVMData(uint8 *data);
#ifndef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
static void Tracediag_Service_15_Get_NVMJobStatus(uint8 *data);
#endif
#endif

#ifdef TRACEDIAG_SERVICE_16
static uint8 Tracediag_Service_16_Set_NVMData(uint8 *data);
static uint8 Tracediag_Service_16_Get_NVMData(uint8 *data);
#ifndef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
static void Tracediag_Service_16_Get_NVMJobStatus(uint8 *data);
#endif
#endif

#ifdef TRACEDIAG_SERVICE_17
static uint8 Tracediag_Service_17_Set_NVMData(uint8 *data);
static uint8 Tracediag_Service_17_Get_NVMData(uint8 *data);
#ifndef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
static void Tracediag_Service_17_Get_NVMJobStatus(uint8 *data);
#endif
#endif

#ifdef TRACEDIAG_SERVICE_18
static uint8 Tracediag_Service_18_Set_NVMData(uint8 *data);
static uint8 Tracediag_Service_18_Get_NVMData(uint8 *data);
#ifndef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
static void Tracediag_Service_18_Get_NVMJobStatus(uint8 *data);
#endif
#endif

#ifdef TRACEDIAG_SERVICE_19
static uint8 Tracediag_Service_19_Set_NVMData(uint8 *data);
static uint8 Tracediag_Service_19_Get_NVMData(uint8 *data);
#ifndef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
static void Tracediag_Service_19_Get_NVMJobStatus(uint8 *data);
#endif
#endif

#ifdef TRACEDIAG_SERVICE_20
static uint8 Tracediag_Service_20_Set_NVMData(uint8 *data);
static uint8 Tracediag_Service_20_Get_NVMData(uint8 *data);
#ifndef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
static void Tracediag_Service_20_Get_NVMJobStatus(uint8 *data);
#endif
#endif

#ifdef TRACEDIAG_SERVICE_24
static uint8 Tracediag_Service_24_Set_NVMData(uint8 *data);
static uint8 Tracediag_Service_24_Get_NVMData(uint8 *data);
#ifndef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
static void Tracediag_Service_24_Get_NVMJobStatus(uint8 *data);
#endif
#endif

#ifdef TRACEDIAG_TRACEBYTES_STATION_1
//Traceability_Bytes_TRACE_STATION_1
static uint8 Tracediagservice_SetNVM_TraceBytesTRACE_STATION_1(uint8 *data);
static uint8 Tracediagservice_GetNVM_TraceBytesTRACE_STATION_1(uint8 *data);
#endif

#ifdef TRACEDIAG_TRACEBYTES_STATION_2
//Traceability_Bytes_TRACE_STATION_2
static uint8 Tracediagservice_SetNVM_TraceBytesTRACE_STATION_2(uint8 *data);
static uint8 Tracediagservice_GetNVM_TraceBytesTRACE_STATION_2(uint8 *data);
#endif

#ifdef TRACEDIAG_TRACEBYTES_STATION_3
//Traceability_Bytes_TRACE_STATION_3
static uint8 Tracediagservice_SetNVM_TraceBytesTRACE_STATION_3(uint8 *data);
static uint8 Tracediagservice_GetNVM_TraceBytesTRACE_STATION_3(uint8 *data);
#endif

#ifdef TRACEDIAG_TRACEBYTES_STATION_4
//Traceability_Bytes_TRACE_STATION_4
static uint8 Tracediagservice_SetNVM_TraceBytesTRACE_STATION_4(uint8 *data);
static uint8 Tracediagservice_GetNVM_TraceBytesTRACE_STATION_4(uint8 *data);
#endif

#ifdef TRACEDIAG_TRACEBYTES_STATION_5
//Traceability_Bytes_TRACE_STATION_5
static uint8 Tracediagservice_SetNVM_TraceBytesTRACE_STATION_5(uint8 *data);
static uint8 Tracediagservice_GetNVM_TraceBytesTRACE_STATION_5(uint8 *data);
#endif

#ifdef TRACEDIAG_RESERVEDBYTES
//Reserved_Bytes
static uint8 Tracediagservice_SetNVM_ReservedBytes(uint8 *data);
static uint8 Tracediagservice_GetNVM_ReservedBytes(uint8 *data);
#endif

#ifdef TRACEDIAG_TRACEABILITY_BYTES
#ifdef TRACE_STATION_1
static uint8 Tracediagservice_SetNVM_Station_TRACE_STATION_1(uint8 *data);
static uint8 Tracediagservice_GetNVM_Station_TRACE_STATION_1(uint8 *data);
#endif
#ifdef TRACE_STATION_2
static uint8 Tracediagservice_SetNVM_Station_TRACE_STATION_2(uint8 *data);
static uint8 Tracediagservice_GetNVM_Station_TRACE_STATION_2(uint8 *data);
#endif
#ifdef TRACE_STATION_3
static uint8 Tracediagservice_SetNVM_Station_TRACE_STATION_3(uint8 *data);
static uint8 Tracediagservice_GetNVM_Station_TRACE_STATION_3(uint8 *data);
#endif
#ifdef TRACE_STATION_4
static uint8 Tracediagservice_SetNVM_Station_TRACE_STATION_4(uint8 *data);
static uint8 Tracediagservice_GetNVM_Station_TRACE_STATION_4(uint8 *data);
#endif
#ifdef TRACE_STATION_5
static uint8 Tracediagservice_SetNVM_Station_TRACE_STATION_5(uint8 *data);
static uint8 Tracediagservice_GetNVM_Station_TRACE_STATION_5(uint8 *data);
#endif
#ifdef TRACE_STATION_6
static uint8 Tracediagservice_SetNVM_Station_TRACE_STATION_6(uint8 *data);
static uint8 Tracediagservice_GetNVM_Station_TRACE_STATION_6(uint8 *data);
#endif
#endif
//Read_Write_Nvm_JobStatus
static void Tracediagservice_Set_NVM_JobStatus(uint8 data);
static void Tracediagservice_Get_NVM_JobStatus(uint8 *data);

#ifdef TRACEDIAG_SERVICE_25
static Std_ReturnType TraceDiag_TPFirmware_Start(uint8 *Data, uint8 *ErrorCode);
static Std_ReturnType TraceDiag_TPFirmware_Results(uint8 *Data, uint8 *ErrorCode);
#endif

/*=====================================================================================================================
**  C O N S T A N T    A N D   V A R I A B L E S    D E C L A R A T I O N S
**====================================================================================================================*/
#ifdef TRACEDIAG_SERVICE_1
const Tracediag_Service  Tracediag_Service_1 =
{ 
    &Tracediag_Service_1_Set_NVMData, &Tracediag_Service_1_Get_NVMData,
	#ifndef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
	&Tracediag_Service_1_Get_NVMJobStatus
	#endif
};
#endif

#ifdef TRACEDIAG_SERVICE_2
const Tracediag_Service  Tracediag_Service_2 =
{ 
    &Tracediag_Service_2_Set_NVMData, &Tracediag_Service_2_Get_NVMData,
	#ifndef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
	&Tracediag_Service_2_Get_NVMJobStatus
	#endif
};
#endif

#ifdef TRACEDIAG_SERVICE_3
const Tracediag_Service  Tracediag_Service_3 =
{ 
    &Tracediag_Service_3_Set_NVMData, &Tracediag_Service_3_Get_NVMData,
	#ifndef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
	&Tracediag_Service_3_Get_NVMJobStatus
	#endif
};
#endif

#ifdef TRACEDIAG_SERVICE_4
const Tracediag_Service  Tracediag_Service_4 =
{ 
    &Tracediag_Service_4_Set_NVMData, &Tracediag_Service_4_Get_NVMData,
	#ifndef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
	&Tracediag_Service_4_Get_NVMJobStatus
	#endif
};
#endif

#ifdef TRACEDIAG_SERVICE_5
const Tracediag_Service  Tracediag_Service_5 =
{ 
    &Tracediag_Service_5_Set_NVMData, &Tracediag_Service_5_Get_NVMData,
	#ifndef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
	&Tracediag_Service_5_Get_NVMJobStatus
	#endif
};
#endif

#ifdef TRACEDIAG_SERVICE_6
const Tracediag_Service  Tracediag_Service_6 =
{ 
    &Tracediag_Service_6_Set_NVMData, &Tracediag_Service_6_Get_NVMData,
	#ifndef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
	&Tracediag_Service_6_Get_NVMJobStatus
	#endif
};
#endif

#ifdef TRACEDIAG_SERVICE_7
const Tracediag_Service  Tracediag_Service_7 =
{ 
    &Tracediag_Service_7_Set_NVMData, &Tracediag_Service_7_Get_NVMData,
	#ifndef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
	&Tracediag_Service_7_Get_NVMJobStatus
	#endif
};
#endif

#ifdef TRACEDIAG_SERVICE_8
const Tracediag_Service  Tracediag_Service_8 =
{ 
    &Tracediag_Service_8_Set_NVMData, &Tracediag_Service_8_Get_NVMData,
	#ifndef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
	&Tracediag_Service_8_Get_NVMJobStatus
	#endif
};
#endif

#ifdef TRACEDIAG_SERVICE_9
const Tracediag_Service  Tracediag_Service_9 =
{ 
    &Tracediag_Service_9_Set_NVMData, &Tracediag_Service_9_Get_NVMData,
	#ifndef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
	&Tracediag_Service_9_Get_NVMJobStatus
	#endif
};
#endif

#ifdef TRACEDIAG_SERVICE_10
const Tracediag_Service  Tracediag_Service_10 =
{ 
    &Tracediag_Service_10_Set_NVMData, &Tracediag_Service_10_Get_NVMData,
	#ifndef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
	&Tracediag_Service_10_Get_NVMJobStatus
	#endif
};
#endif

#ifdef TRACEDIAG_SERVICE_11
const Tracediag_Service  Tracediag_Service_11 =
{ 
    &Tracediag_Service_11_Set_NVMData, &Tracediag_Service_11_Get_NVMData,
	#ifndef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
	&Tracediag_Service_11_Get_NVMJobStatus
	#endif
};
#endif

#ifdef TRACEDIAG_SERVICE_12
const Tracediag_Service  Tracediag_Service_12 =
{ 
    &Tracediag_Service_12_Set_NVMData, &Tracediag_Service_12_Get_NVMData,
	#ifndef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
	&Tracediag_Service_12_Get_NVMJobStatus
	#endif
};
#endif

#ifdef TRACEDIAG_SERVICE_13
const Tracediag_Service  Tracediag_Service_13 =
{ 
    &Tracediag_Service_13_Set_NVMData, &Tracediag_Service_13_Get_NVMData,
	#ifndef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
	&Tracediag_Service_13_Get_NVMJobStatus
	#endif
};
#endif

#ifdef TRACEDIAG_SERVICE_14
const Tracediag_Service  Tracediag_Service_14 =
{ 
    &Tracediag_Service_14_Set_NVMData, &Tracediag_Service_14_Get_NVMData,
	#ifndef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
	&Tracediag_Service_14_Get_NVMJobStatus
	#endif
};
#endif

#ifdef TRACEDIAG_SERVICE_15
const Tracediag_Service  Tracediag_Service_15 =
{ 
    &Tracediag_Service_15_Set_NVMData, &Tracediag_Service_15_Get_NVMData,
	#ifndef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
	&Tracediag_Service_15_Get_NVMJobStatus
	#endif
};
#endif

#ifdef TRACEDIAG_SERVICE_16
const Tracediag_Service  Tracediag_Service_16 =
{ 
    &Tracediag_Service_16_Set_NVMData, &Tracediag_Service_16_Get_NVMData,
	#ifndef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
	&Tracediag_Service_16_Get_NVMJobStatus
	#endif
};
#endif

#ifdef TRACEDIAG_SERVICE_17
const Tracediag_Service  Tracediag_Service_17 =
{ 
    &Tracediag_Service_17_Set_NVMData, &Tracediag_Service_17_Get_NVMData,
	#ifndef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
	&Tracediag_Service_17_Get_NVMJobStatus
	#endif
};
#endif

#ifdef TRACEDIAG_SERVICE_18
const Tracediag_Service  Tracediag_Service_18 =
{ 
    &Tracediag_Service_18_Set_NVMData, &Tracediag_Service_18_Get_NVMData,
	#ifndef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
	&Tracediag_Service_18_Get_NVMJobStatus
	#endif
};
#endif

#ifdef TRACEDIAG_SERVICE_19
const Tracediag_Service  Tracediag_Service_19 =
{
    &Tracediag_Service_19_Set_NVMData, &Tracediag_Service_19_Get_NVMData,
	#ifndef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
	&Tracediag_Service_19_Get_NVMJobStatus
	#endif
};
#endif

#ifdef TRACEDIAG_SERVICE_20
const Tracediag_Service  Tracediag_Service_20 =
{
    &Tracediag_Service_20_Set_NVMData, &Tracediag_Service_20_Get_NVMData,
	#ifndef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
	&Tracediag_Service_20_Get_NVMJobStatus
	#endif
};
#endif

#ifdef TRACEDIAG_SERVICE_24
const Tracediag_Service  Tracediag_Service_24 =
{ 
    &Tracediag_Service_24_Set_NVMData, &Tracediag_Service_24_Get_NVMData,
	#ifndef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
	&Tracediag_Service_24_Get_NVMJobStatus
	#endif
};
#endif

#ifdef TRACEDIAG_SERVICE_25
const TraceDiag_TPFirmware TPFirmwareUpdate =
{
    &TraceDiag_TPFirmware_Start,&TraceDiag_TPFirmware_Results,
};
#endif

#ifdef TRACEDIAG_TRACEBYTES_STATION_1
const Tracediag_Service  Tracediag_Service_TraceBytesTRACE_STATION_1 =
{ 
    &Tracediagservice_SetNVM_TraceBytesTRACE_STATION_1, &Tracediagservice_GetNVM_TraceBytesTRACE_STATION_1,
};
#endif

#ifdef TRACEDIAG_TRACEBYTES_STATION_2
const Tracediag_Service  Tracediag_Service_TraceBytesTRACE_STATION_2 =
{ 
    &Tracediagservice_SetNVM_TraceBytesTRACE_STATION_2, &Tracediagservice_GetNVM_TraceBytesTRACE_STATION_2,
};
#endif

#ifdef TRACEDIAG_TRACEBYTES_STATION_3
const Tracediag_Service  Tracediag_Service_TraceBytesTRACE_STATION_3 =
{ 
    &Tracediagservice_SetNVM_TraceBytesTRACE_STATION_3, &Tracediagservice_GetNVM_TraceBytesTRACE_STATION_3,
};
#endif

#ifdef TRACEDIAG_TRACEBYTES_STATION_4
const Tracediag_Service  Tracediag_Service_TraceBytesTRACE_STATION_4 =
{ 
    &Tracediagservice_SetNVM_TraceBytesTRACE_STATION_4, &Tracediagservice_GetNVM_TraceBytesTRACE_STATION_4,
};
#endif

#ifdef TRACEDIAG_TRACEBYTES_STATION_5
const Tracediag_Service  Tracediag_Service_TraceBytesTRACE_STATION_5 =
{ 
    &Tracediagservice_SetNVM_TraceBytesTRACE_STATION_5, &Tracediagservice_GetNVM_TraceBytesTRACE_STATION_5,
};
#endif

#ifdef TRACEDIAG_RESERVEDBYTES
const Tracediag_Service  Tracediag_Service_Reservedytes =
{ 
    &Tracediagservice_SetNVM_ReservedBytes, &Tracediagservice_GetNVM_ReservedBytes,
};
#endif

#ifdef TRACEDIAG_TRACEABILITY_BYTES
const Tracediag_Service_Trace_Bytes Tracediag_Service_Station_Traceability_Bytes =
{
    #ifdef TRACE_STATION_1
    &Tracediagservice_SetNVM_Station_TRACE_STATION_1,
    &Tracediagservice_GetNVM_Station_TRACE_STATION_1,
    #endif
    #ifdef TRACE_STATION_2
    &Tracediagservice_SetNVM_Station_TRACE_STATION_2,
    &Tracediagservice_GetNVM_Station_TRACE_STATION_2,
    #endif
    #ifdef TRACE_STATION_3
    &Tracediagservice_SetNVM_Station_TRACE_STATION_3,
    &Tracediagservice_GetNVM_Station_TRACE_STATION_3,
    #endif
    #ifdef TRACE_STATION_4
    &Tracediagservice_SetNVM_Station_TRACE_STATION_4,
    &Tracediagservice_GetNVM_Station_TRACE_STATION_4,
    #endif
    #ifdef TRACE_STATION_5
    &Tracediagservice_SetNVM_Station_TRACE_STATION_5,
    &Tracediagservice_GetNVM_Station_TRACE_STATION_5,
    #endif
    #ifdef TRACE_STATION_6   
    &Tracediagservice_SetNVM_Station_TRACE_STATION_6,
    &Tracediagservice_GetNVM_Station_TRACE_STATION_6,
    #endif
};
#endif
const NVM_ReadWrite  Tracediag_NvmJobResult =
{
    &Tracediagservice_Set_NVM_JobStatus, &Tracediagservice_Get_NVM_JobStatus,
};

/*=====================================================================================================================
**  PRIVATE
**====================================================================================================================*/

/*=====================================================================================================================
** Function Name    :  Tracediag_Service_checkASCIIRange
**
** Visibility       :  Private 
**
** Description      :  Used to check bytes are within range of ASCII or not
**
** Inputs           :  data, didLength
**
** Outputs          :  TRUE/FALSE
**
** Critical Section :  No
**====================================================================================================================*/
static boolean Tracediag_Service_checkASCIIRange(const uint8 *data, uint8 didLength)
{
    uint8 idx;
    boolean isRangeValid = FALSE;
    const uint8 *pData = data;

    if (pData != NULL_PTR)
    {
        /* Default to TRUE for valid length; loop will invalidate if needed */
        isRangeValid = TRUE; 

        for (idx = 0U; idx < didLength; idx++)
        {
            /* 
             * FIX (90592): Use pointer dereferencing instead of array indexing 
             * to satisfy strict pointer arithmetic rules.
             */
            const uint8 currentVal = *pData;

            /* 
             * FIX (90595/90596/NA): Removed explicit (uint8) casts to resolve 
             * "potentially different size" and "always yields same result" warnings.
             * Implicit promotion handles the comparison safely.
             */
            if (((currentVal >= TRACEDIAG_cSpaceAscii) && 
                 (currentVal <= TRACEDIAG_cDelAscii)) || 
                 (currentVal == TRACEDIAG_cNullAscii))
            {
                /* Character is within valid range */
            }
            else
            {
                isRangeValid = FALSE;
                break;
            }
            
            /* Increment pointer to avoid index-based arithmetic */
            pData++;
        }
        
        /* Handle case where length is 0 */
        if (0U == didLength)
        {
            isRangeValid = FALSE;
        }
    }

    return isRangeValid;
}

#ifdef TRACEDIAG_RANGECHECK
/**
 *  @brief DESCRIPTION:    - Checks all bytes consecutively to see if they match the subset defined by the format mask
 *  @param pu8BufferP      - Pointer to the beginning of the string
 *  @param u8SizeP         - Size in bytes of the passed string
 *  @param u8FormatMaskP   - Bit mask defining the required format of the string
 *  @return  Std_ReturnType: MANUF_OK operation successful/MANUF_FAIL - operation failed
 */
static Std_ReturnType Tracediag_IsStringInRange(P2CONST(uint8, AUTOMATIC, RTE_STPCDD_APPL_VAR) Data,uint8 u8SizeP,uint8 u8FormatMaskP )
{
	uint8 u8IndexL;
	Std_ReturnType ret = E_NOT_OK;

	for( u8IndexL = MEET_INDEX_0; u8IndexL < u8SizeP; u8IndexL++ )
	{
		if((0x56 == *(Data + 0)) && (0x50 == *(Data + 1)) && (0x46 == *(Data + 5)) &&(0x2D == *(Data + 6)) && (0x2D == *(Data + 12)))
		{
			
			//QACJ 0506: aspasom: This is an internal function, the pointer is checked by the caller
			ret = Tracediag_IsByteInRange( Data[u8IndexL], u8FormatMaskP );
			if(ret == (uint8)E_NOT_OK)
			{
				ret = E_NOT_OK;
				break;
			}
		}
		else
		{
		   //	u8IndexL = 0;
			ret = E_NOT_OK;
			break;
		}
	}

	return ret;
}

/**
 *  @brief DESCRIPTION: Checks a byte to see if it matches the subset defined by the format mask
 *
 *  @param u8ByteP         - The byte to be checked
 *  @param u8FormatMaskP   - Bit mask defining the required format of the byte
 *  @return  Std_ReturnType: MANUF_OK operation successful/MANUF_FAIL - operation failed
 */

static Std_ReturnType Tracediag_IsByteInRange( uint8 u8ByteP, uint8 u8FormatMaskP )
{
	Std_ReturnType ret = E_NOT_OK;

	// Add here other validation options if you need them
	if( ((0u != (u8FormatMaskP & TRACEDIAG_cStrVal_AnyAscii)) && (TRACEDIAG_cSpaceAscii <= u8ByteP) && (TRACEDIAG_cDelAscii > u8ByteP)) ||
		((0u != (u8FormatMaskP & TRACEDIAG_cStrVal_Bcd)) && ((u8ByteP & TRACEDIAG_cLowBits) <= TRACEDIAG_cLowDigitMax) && ((u8ByteP & TRACEDIAG_cHighBits) <= TRACEDIAG_cHighDigitMax))
		)
	{
		ret = E_OK;
	}
	
	return ret;
}

/**
 *  @brief DESCRIPTION: Checks a byte to see if it matches the subset defined by the format mask
 *
 *  @param u8ByteP         - The byte to be checked
 *  @param u8FormatMaskP   - Bit mask defining the required format of the byte
 *  @return  Std_ReturnType: MANUF_OK operation successful/MANUF_FAIL - operation failed
 */

static Std_ReturnType Tracediag_IsByteInRange_1( uint8 u8ByteP, uint8 u8FormatMaskP )
{
	Std_ReturnType ret = E_NOT_OK;

	// Add here other validation options if you need them
	//if( ((0 != (u8FormatMaskP & TRACEDIAG_cStrVal_AnyAscii)) && (TRACEDIAG_cSpaceAscii <= u8ByteP) && (TRACEDIAG_cDelAscii > u8ByteP)))
	if( ((0 != (u8FormatMaskP & TRACEDIAG_cStrVal_AnyAscii)) && (TRACEDIAG_cSpaceAscii <= u8ByteP) && (TRACEDIAG_cDelAscii > u8ByteP)) ||
		((0 != (u8FormatMaskP & TRACEDIAG_cStrVal_Bcd)) && ((u8ByteP & TRACEDIAG_cLowBits) <= TRACEDIAG_cLowDigitMax) && ((u8ByteP & TRACEDIAG_cHighBits) <= TRACEDIAG_cHighDigitMax))
		)
	{
		ret = E_OK;
	}

	return ret;
}

/**
 *  @brief DESCRIPTION:    - Checks all bytes consecutively to see if they match the subset defined by the format mask
 *  @param pu8BufferP      - Pointer to the beginning of the string
 *  @param u8SizeP         - Size in bytes of the passed string
 *  @param u8FormatMaskP   - Bit mask defining the required format of the string
 *  @return  Std_ReturnType: MANUF_OK operation successful/MANUF_FAIL - operation failed
 */
static Std_ReturnType Tracediag_IsStringInRange_1(P2CONST(uint8, AUTOMATIC, RTE_STPCDD_APPL_VAR) Data,uint8 u8SizeP,uint8 u8FormatMaskP )
{
	uint8 u8IndexL;
	Std_ReturnType ret = E_NOT_OK;
	uint16 ASSY_Year;
	uint16 ASSY_Month;
	uint16 ASSY_Day;
   //	uint16 Zero_Value_Comparision = 0;
	ASSY_Year = ((Data[0]<<8) | (Data[1]));
	ASSY_Month= ((Data[3]<<8) | (Data[4]));
	ASSY_Day  = ((Data[6]<<8) | (Data[7]));
	
	for( u8IndexL = MEET_INDEX_0; u8IndexL < u8SizeP; u8IndexL++ )
	{
		//if((ASSY_Year >= Zero_Value_Comparision && ASSY_Year < 0x64) && (ASSY_Month >= 0x01 && ASSY_Month < 0x0D) && (ASSY_Day >= 0x01 && ASSY_Day < 0x20)
		//	&& (0x5F == Data[2]) && (0x5F == Data[5]) && (0x5F == Data[8]) && (0x5F == Data[9]))							//(0x2D == *(Data + 6)) && (0x2D == *(Data + 12)))
		if((ASSY_Year >= 0x30 && ASSY_Year < 0x3939) && (ASSY_Month >= 0x31 && ASSY_Month < 0x3132) && (ASSY_Day >= 0x31 && ASSY_Day < 0x3331)
			&& (0x5F == Data[2]) && (0x5F == Data[5]) && (0x5F == Data[8]) && (0x5F == Data[9]))
		{
			
			//QACJ 0506: aspasom: This is an internal function, the pointer is checked by the caller
			ret = Tracediag_IsByteInRange_1( Data[u8IndexL+10], u8FormatMaskP );
		}
		else
		{
			//u8IndexL = 0; // coverity fix
			ret = E_NOT_OK;
			break;
		}
	}
	
	return ret;
}
#endif

#ifdef TRACEDIAG_SERVICE_1
/*=====================================================================================================================
** Function Name    :  Tracediag_Service_1_Set_NVMData
**
** Visibility       :  Private 
**
** Description      :  Used to write the data in NVM(Application has to map the RTE call for the same)
**                      
** Invocation       :  Tracediag_Write_Service_1
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**====================================================================================================================*/
static uint8 Tracediag_Service_1_Set_NVMData(const uint8 *data)
{
   Std_ReturnType ret = E_NOT_OK;
   boolean flag = FALSE;
   flag = Tracediag_Service_checkASCIIRange(data, (uint8)TRACEDIAG_PART_NUMBER_LEN);
   if(TRUE == flag)
   {
       ret = Rte_Call_rp_CS_MemAbsSet_Set_BsShare_VisteonPartNumber(data);
   }
   return ret;
}
/*=====================================================================================================================
** Function Name    :  Tracediag_Service_1_Get_NVMData
**
** Visibility       :  Private 
**
** Description      :  Used to Read the data from NVM(Application has to map the RTE call for the same)
**                      
** Invocation       :  Tracediag_Read_Service_1
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**====================================================================================================================*/
static Std_ReturnType Tracediag_Service_1_Get_NVMData(uint8 *data)
{
    Std_ReturnType ret = E_OK;
    boolean flag = FALSE;
    (void)Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VisteonPartNumber(data);
    flag = Tracediag_Service_checkASCIIRange(data, (uint8)TRACEDIAG_PART_NUMBER_LEN);
    if(FALSE == flag)
    {
        ret = E_NOT_OK;
    }
    return ret;
}
#ifndef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
/*=====================================================================================================================
** Function Name    :  Tracediag_Service_1_Get_NVMJobStatus
**
** Visibility       :  Private 
**
** Description      :  Used to Read the JobStatus of NVM 
**                      
** Invocation       :  Tracediag_Read_Service_1
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**====================================================================================================================*/
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_VisteonPartNumber; /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_BsShare_VisteonPartNumber Rte_Read_CMeetCdd_rp_SR_JobStatus_JobStatus_BsShare_VisteonPartNumber
#  define Rte_Read_CMeetCdd_rp_SR_JobStatus_JobStatus_BsShare_VisteonPartNumber(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_VisteonPartNumber, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */

static void Tracediag_Service_1_Get_NVMJobStatus(uint8 *data)
{
	(void)Rte_Read_rp_SR_JobStatus_JobStatus_BsShare_VisteonPartNumber (data);
}
#endif
#endif

#ifdef TRACEDIAG_SERVICE_2
/*=====================================================================================================================
** Function Name    :  Tracediag_Service_2_Set_NVMData
**
** Visibility       :  Private 
**
** Description      :  Used to write the data in NVM(Application has to map the RTE call for the same)
**                      
** Invocation       :  Tracediag_Write_Service_2
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**====================================================================================================================*/
static uint8 Tracediag_Service_2_Set_NVMData(const uint8 *data)
{
    Std_ReturnType ret = E_NOT_OK;
    boolean flag = FALSE;
    flag = Tracediag_Service_checkASCIIRange(data, (uint8)TRACEDIAG_PCB_PART_NUMBER_LEN);
    if(TRUE == flag)
    {
    	ret = Rte_Call_rp_CS_MemAbsSet_Set_BsShare_VisteonPCBPartNumber(data);
    }
    return ret;
}
/*=====================================================================================================================
** Function Name    :  Tracediag_Service_2_Get_NVMData
**
** Visibility       :  Private 
**
** Description      :  Used to Read the data from NVM(Application has to map the RTE call for the same)
**                      
** Invocation       :  Tracediag_Read_Service_2
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**====================================================================================================================*/
static uint8 Tracediag_Service_2_Get_NVMData(uint8 *data)
{
    Std_ReturnType ret = E_OK;
    boolean flag = FALSE;

    (void)Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VisteonPCBPartNumber(data);
    flag = Tracediag_Service_checkASCIIRange(data, (uint8)TRACEDIAG_PCB_PART_NUMBER_LEN);
    if(FALSE == flag)
    {
    	ret = E_NOT_OK;
    }
    return ret;
}
#ifndef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
/*=====================================================================================================================
** Function Name    :  Tracediag_Service_2_Get_NVMJobStatus
**
** Visibility       :  Private 
**
** Description      :  Used to Read the JobStatus of NVM 
**                      
** Invocation       :  Tracediag_Read_Service_2
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**====================================================================================================================*/
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_VisteonPCBPartNumber; /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_BsShare_VisteonPCBPartNumber Rte_Read_CMeetCdd_rp_SR_JobStatus_JobStatus_BsShare_VisteonPCBPartNumber
#  define Rte_Read_CMeetCdd_rp_SR_JobStatus_JobStatus_BsShare_VisteonPCBPartNumber(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_VisteonPCBPartNumber, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */

static void Tracediag_Service_2_Get_NVMJobStatus(uint8 *data)
{
	(void) Rte_Read_rp_SR_JobStatus_JobStatus_BsShare_VisteonPCBPartNumber(data);
}
#endif
#endif

#ifdef TRACEDIAG_SERVICE_3
/*=====================================================================================================================
** Function Name    :  Tracediag_Service_3_Set_NVMData
**
** Visibility       :  Private 
**
** Description      :  Used to write the data in NVM(Application has to map the RTE call for the same)
**                      
** Invocation       :  Tracediag_Write_Service_3
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**====================================================================================================================*/
static uint8 Tracediag_Service_3_Set_NVMData(const uint8 *data)
{
	Std_ReturnType ret = E_NOT_OK;

	ret = Rte_Call_rp_CS_MemAbsSet_Set_BsShare_PCBSerialNumber(data);
	
	return ret;
}
/*=====================================================================================================================
** Function Name    :  Tracediag_Service_3_Get_NVMData
**
** Visibility       :  Private 
**
** Description      :  Used to Read the data from NVM(Application has to map the RTE call for the same)
**                      
** Invocation       :  Tracediag_Read_Service_3
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**====================================================================================================================*/
static uint8 Tracediag_Service_3_Get_NVMData(uint8 *data)
{
	Std_ReturnType ret = E_OK;

	(void) Rte_Call_rp_CS_MemAbsGet_Get_BsShare_PCBSerialNumber(data);

	return ret;
}
#ifndef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
/*=====================================================================================================================
** Function Name    :  Tracediag_Service_3_Get_NVMJobStatus
**
** Visibility       :  Private 
**
** Description      :  Used to Read the JobStatus of NVM 
**                      
** Invocation       :  Tracediag_Read_Service_3
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**====================================================================================================================*/
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_PCBSerialNumber; /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_BsShare_PCBSerialNumber Rte_Read_CMeetCdd_rp_SR_JobStatus_JobStatus_BsShare_PCBSerialNumber
#  define Rte_Read_CMeetCdd_rp_SR_JobStatus_JobStatus_BsShare_PCBSerialNumber(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_PCBSerialNumber, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */

static void Tracediag_Service_3_Get_NVMJobStatus(uint8 *data)
{
	(void) Rte_Read_rp_SR_JobStatus_JobStatus_BsShare_PCBSerialNumber(data);
}


#endif
#endif

#ifdef TRACEDIAG_SERVICE_4
/*=====================================================================================================================
** Function Name    :  Tracediag_Service_4_Set_NVMData
**
** Visibility       :  Private 
**
** Description      :  Used to write the data in NVM(Application has to map the RTE call for the same)
**                      
** Invocation       :  Tracediag_Write_Service_4
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**====================================================================================================================*/
static uint8 Tracediag_Service_4_Set_NVMData(const uint8 *data)
{
	Std_ReturnType ret = E_NOT_OK;

	ret = Rte_Call_rp_CS_MemAbsSet_Set_BsShare_SMTManufacturingDate(data);
	
	return ret;
}
/*=====================================================================================================================
** Function Name    :  Tracediag_Service_4_Get_NVMData
**
** Visibility       :  Private 
**
** Description      :  Used to Read the data from NVM(Application has to map the RTE call for the same)
**                      
** Invocation       :  Tracediag_Read_Service_4
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**====================================================================================================================*/
static uint8 Tracediag_Service_4_Get_NVMData(uint8 *data)
{
	Std_ReturnType ret = E_OK;

	(void) Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SMTManufacturingDate(data);

	return ret;
}
#ifndef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
/*=====================================================================================================================
** Function Name    :  Tracediag_Service_4_Get_NVMJobStatus
**
** Visibility       :  Private 
**
** Description      :  Used to Read the JobStatus of NVM 
**                      
** Invocation       :  Tracediag_Read_Service_4
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**====================================================================================================================*/
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SMTManufacturingDate; /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_BsShare_SMTManufacturingDate Rte_Read_CMeetCdd_rp_SR_JobStatus_JobStatus_BsShare_SMTManufacturingDate
#  define Rte_Read_CMeetCdd_rp_SR_JobStatus_JobStatus_BsShare_SMTManufacturingDate(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SMTManufacturingDate, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */

static void Tracediag_Service_3_Get_NVMJobStatus(uint8 *data)
{
	(void) Rte_Read_rp_SR_JobStatus_JobStatus_BsShare_SMTManufacturingDate(data);
}

#endif
#endif

#ifdef TRACEDIAG_SERVICE_5
/*=====================================================================================================================
** Function Name    :  Tracediag_Service_5_Set_NVMData
**
** Visibility       :  Private 
**
** Description      :  Used to write the data in NVM(Application has to map the RTE call for the same)
**                      
** Invocation       :  Tracediag_Write_Service_5
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**====================================================================================================================*/
static uint8 Tracediag_Service_5_Set_NVMData(const uint8 *data)
{
	Std_ReturnType ret = E_NOT_OK;
	
	ret = Rte_Call_rp_CS_MemAbsSet_Set_BsShare_SMTPlantNumber(data);

	return ret;
}
/*=====================================================================================================================
** Function Name    :  Tracediag_Service_5_Get_NVMData
**
** Visibility       :  Private 
**
** Description      :  Used to Read the data from NVM(Application has to map the RTE call for the same)
**                      
** Invocation       :  Tracediag_Read_Service_5
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**====================================================================================================================*/
static uint8 Tracediag_Service_5_Get_NVMData(uint8 *data)
{
	Std_ReturnType ret = E_OK;

	(void) Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SMTPlantNumber(data);

	return ret;
}
#ifndef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
/*=====================================================================================================================
** Function Name    :  Tracediag_Service_5_Get_NVMJobStatus
**
** Visibility       :  Private 
**
** Description      :  Used to Read the JobStatus of NVM 
**                      
** Invocation       :  Tracediag_Read_Service_5
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**====================================================================================================================*/
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SMTPlantNumber; /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_BsShare_SMTPlantNumber Rte_Read_CMeetCdd_rp_SR_JobStatus_JobStatus_BsShare_SMTPlantNumber
#  define Rte_Read_CMeetCdd_rp_SR_JobStatus_JobStatus_BsShare_SMTPlantNumber(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SMTPlantNumber, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */

static void Tracediag_Service_3_Get_NVMJobStatus(uint8 *data)
{
	(void) Rte_Read_rp_SR_JobStatus_JobStatus_BsShare_SMTPlantNumber(data);
}

#endif
#endif

#ifdef TRACEDIAG_SERVICE_6
/*=====================================================================================================================
** Function Name    :  Tracediag_Service_6_Set_NVMData
**
** Visibility       :  Private 
**
** Description      :  Used to write the data in NVM(Application has to map the RTE call for the same)
**                      
** Invocation       :  Tracediag_Write_Service_6
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**====================================================================================================================*/
static uint8 Tracediag_Service_6_Set_NVMData(const uint8 *data)
{
	Std_ReturnType ret = E_NOT_OK;

	ret = Rte_Call_rp_CS_MemAbsSet_Set_BsShare_AssemblyPlantNumber(data);
	
	return ret;
}
/*=====================================================================================================================
** Function Name    :  Tracediag_Service_6_Get_NVMData
**
** Visibility       :  Private 
**
** Description      :  Used to Read the data from NVM(Application has to map the RTE call for the same)
**                      
** Invocation       :  Tracediag_Read_Service_6
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**====================================================================================================================*/
static uint8 Tracediag_Service_6_Get_NVMData(uint8 *data)
{
	Std_ReturnType ret = E_OK;

	(void) Rte_Call_rp_CS_MemAbsGet_Get_BsShare_AssemblyPlantNumber(data);

	return ret;
}
#ifndef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
/*=====================================================================================================================
** Function Name    :  Tracediag_Service_6_Get_NVMJobStatus
**
** Visibility       :  Private 
**
** Description      :  Used to Read the JobStatus of NVM 
**                      
** Invocation       :  Tracediag_Read_Service_6
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**====================================================================================================================*/
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_AssemblyPlantNumber; /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_BsShare_AssemblyPlantNumber Rte_Read_CMeetCdd_rp_SR_JobStatus_JobStatus_BsShare_AssemblyPlantNumber
#  define Rte_Read_CMeetCdd_rp_SR_JobStatus_JobStatus_BsShare_AssemblyPlantNumber(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_AssemblyPlantNumber, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */

static void Tracediag_Service_3_Get_NVMJobStatus(uint8 *data)
{
	(void) Rte_Read_rp_SR_JobStatus_JobStatus_BsShare_AssemblyPlantNumber(data);
}

#endif
#endif

#ifdef TRACEDIAG_SERVICE_7
/*=====================================================================================================================
** Function Name    :  Tracediag_Service_7_Set_NVMData
**
** Visibility       :  Private 
**
** Description      :  Used to write the data in NVM(Application has to map the RTE call for the same)
**                      
** Invocation       :  NVM and software version
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**====================================================================================================================*/
static uint8 Tracediag_Service_7_Set_NVMData(const uint8 *data)
{
	Std_ReturnType ret = E_NOT_OK;
	
	ret = Rte_Call_rp_CS_MemAbsSet_Set_BsShare_AssemblyManufacturingDate(data);

	return ret;

}
/*=====================================================================================================================
** Function Name    :  Tracediag_Service_7_Get_NVMData
**
** Visibility       :  Private 
**
** Description      :  Used to Read the data from NVM(Application has to map the RTE call for the same)
**                      
** Invocation       :  Tracediag_Read_Service_7
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**====================================================================================================================*/
static uint8 Tracediag_Service_7_Get_NVMData(uint8 *data)
{
	Std_ReturnType ret = E_OK;

	(void) Rte_Call_rp_CS_MemAbsGet_Get_BsShare_AssemblyManufacturingDate(data);

	return ret;
}
#ifndef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
/*=====================================================================================================================
** Function Name    :  Tracediag_Service_7_Get_NVMJobStatus
**
** Visibility       :  Private 
**
** Description      :  Used to Read the JobStatus of NVM 
**                      
** Invocation       :  Tracediag_Read_Service_7
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**====================================================================================================================*/
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_AssemblyManufacturingDate; /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_BsShare_AssemblyManufacturingDate Rte_Read_CMeetCdd_rp_SR_JobStatus_JobStatus_BsShare_AssemblyManufacturingDate
#  define Rte_Read_CMeetCdd_rp_SR_JobStatus_JobStatus_BsShare_AssemblyManufacturingDate(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_AssemblyManufacturingDate, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */

static void Tracediag_Service_3_Get_NVMJobStatus(uint8 *data)
{
	(void) Rte_Read_rp_SR_JobStatus_JobStatus_BsShare_AssemblyManufacturingDate(data);
}

#endif
#endif

#ifdef TRACEDIAG_SERVICE_8
/*=====================================================================================================================
** Function Name    :  Tracediag_Service_8_Set_NVMData
**
** Visibility       :  Private 
**
** Description      :  Used to write the data in NVM(Application has to map the RTE call for the same)
**                      
** Invocation       :  Tracediag_Write_Service_8
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**====================================================================================================================*/
static uint8 Tracediag_Service_8_Set_NVMData(const uint8 *data)
{
    Std_ReturnType ret = E_NOT_OK;

    ret = Rte_Call_rp_CS_MemAbsSet_Set_BsShare_ProductSerialNumber(data);

    return ret;
}
/*=====================================================================================================================
** Function Name    :  Tracediag_Service_8_Get_NVMData
**
** Visibility       :  Private 
**
** Description      :  Used to Read the data from NVM(Application has to map the RTE call for the same)
**                      
** Invocation       :  Tracediag_Read_Service_8
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**====================================================================================================================*/
static uint8 Tracediag_Service_8_Get_NVMData(uint8 *data)
{
	Std_ReturnType ret = E_OK;

	(void) Rte_Call_rp_CS_MemAbsGet_Get_BsShare_ProductSerialNumber(data);

	return ret;
}
#ifndef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
/*=====================================================================================================================
** Function Name    :  Tracediag_Service_8_Get_NVMJobStatus
**
** Visibility       :  Private 
**
** Description      :  Used to Read the JobStatus of NVM 
**                      
** Invocation       :  Tracediag_Read_Service_8
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**====================================================================================================================*/
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_ProductSerialNumber; /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_BsShare_ProductSerialNumber Rte_Read_CMeetCdd_rp_SR_JobStatus_JobStatus_BsShare_ProductSerialNumber
#  define Rte_Read_CMeetCdd_rp_SR_JobStatus_JobStatus_BsShare_ProductSerialNumber(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_ProductSerialNumber, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */

static void Tracediag_Service_3_Get_NVMJobStatus(uint8 *data)
{
	(void) Rte_Read_rp_SR_JobStatus_JobStatus_BsShare_ProductSerialNumber(data);
}

#endif
#endif
 
#ifdef TRACEDIAG_SERVICE_9
/*=====================================================================================================================
** Function Name    :  Tracediag_Service_9_Set_NVMData
**
** Visibility       :  Private 
**
** Description      :  Used to write the data in NVM(Application has to map the RTE call for the same)
**                      
** Invocation       :  Tracediag_Write_Service_9
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**====================================================================================================================*/
static uint16 Tracediag_Service_9_Set_NVMData(uint16 data)
{
    Std_ReturnType ret = E_NOT_OK;

    ret = Rte_Call_rp_CS_MemAbsSet_Set_BsShare_HWModification(data);

    return ret;
}
/*=====================================================================================================================
** Function Name    :  Tracediag_Service_9_Get_NVMData
**
** Visibility       :  Private 
**
** Description      :  Used to read the data from NVM(Application has to map the RTE call for the same)
**                      
** Invocation       :  Tracediag_Read_Service_9
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**====================================================================================================================*/
static uint16 Tracediag_Service_9_Get_NVMData(uint16 *data)
{
    Std_ReturnType ret = Rte_Call_rp_CS_MemAbsGet_Get_BsShare_HWModification(data);


    return ret;
}
#ifndef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
/*=====================================================================================================================
** Function Name    :  Tracediag_Service_9_Get_NVMJobStatus
**
** Visibility       :  Private 
**
** Description      :  Used to Read the JobStatus of NVM 
**                      
** Invocation       :  Tracediag_Read_Service_9
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**====================================================================================================================*/
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_HWModification; /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_BsShare_HWModification Rte_Read_CMeetCdd_rp_SR_JobStatus_JobStatus_BsShare_HWModification
#  define Rte_Read_CMeetCdd_rp_SR_JobStatus_JobStatus_BsShare_HWModification(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_HWModification, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */

static void Tracediag_Service_3_Get_NVMJobStatus(uint8 *data)
{
	(void) Rte_Read_rp_SR_JobStatus_JobStatus_BsShare_HWModification(data);
}

#endif
#endif

#ifdef TRACEDIAG_SERVICE_10
/*=====================================================================================================================
** Function Name    :  Tracediag_Service_10_Set_NVMData
**
** Visibility       :  Private 
**
** Description      :  Used to write the data in NVM(Application has to map the RTE call for the same)
**                      
** Invocation       :  Tracediag_Write_Service_10
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**====================================================================================================================*/
static uint8 Tracediag_Service_10_Set_NVMData(uint8 *data)
{
    Std_ReturnType ret = E_NOT_OK;

    //ret = Rte_Call_rp_CS_MemAbsSet_Set_NV_Vehicle_Hardware_Number(data);

	return ret;
}
/*=====================================================================================================================
** Function Name    :  Tracediag_Service_10_Get_NVMData
**
** Visibility       :  Private 
**
** Description      :  Used to Read the data from NVM(Application has to map the RTE call for the same)
**
** Invocation       :  Tracediag_Read_Service_10
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**====================================================================================================================*/
static uint8 Tracediag_Service_10_Get_NVMData(uint8 *data)
{
	Std_ReturnType ret = E_OK;

	//(void) Rte_Call_rp_CS_MemAbsGet_Get_NV_Vehicle_Hardware_Number(data);

    return ret;
}
#ifndef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
/*=====================================================================================================================
** Function Name    :  Tracediag_Service_10_Get_NVMJobStatus
**
** Visibility       :  Private 
**
** Description      :  Used to Read the JobStatus of NVM 
**                      
** Invocation       :  Tracediag_Read_Service_10
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**====================================================================================================================*/
static void Tracediag_Service_10_Get_NVMJobStatus(uint8 *data)
{
	//(void) Rte_Read_rp_SR_MemAbsJobStatus_JobStatus_NV_Vehicle_Hardware_Number(data);
}
#endif
#endif

#ifdef TRACEDIAG_SERVICE_11
/*=====================================================================================================================
** Function Name    :  Tracediag_Service_11_Set_NVMData
**
** Visibility       :  Private 
**
** Description      :  Used to write the data in NVM(Application has to map the RTE call for the same)
**                      
** Invocation       :  Tracediag_Write_Service_11
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**====================================================================================================================*/
static uint8 Tracediag_Service_11_Set_NVMData(uint8 *data)
{
    Std_ReturnType ret = E_NOT_OK;

    //ret = Rte_Call_rp_CS_MemAbsSet_Set_NV_ECU_Software_Date(data);

	return ret;
}
/*=====================================================================================================================
** Function Name    :  Tracediag_Service_11_Get_NVMData
**
** Visibility       :  Private 
**
** Description      :  Used to read the data from NVM(Application has to map the RTE call for the same)
**                      
** Invocation       :  Tracediag_Read_Service_11
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**====================================================================================================================*/
static uint8 Tracediag_Service_11_Get_NVMData(uint8 *data)
{
	Std_ReturnType ret = E_OK;

	//(void) Rte_Call_rp_CS_MemAbsGet_Get_NV_ECU_Software_Date(data);

    return ret;
}
#ifndef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
/*=====================================================================================================================
** Function Name    :  Tracediag_Service_11_Get_NVMJobStatus
**
** Visibility       :  Private 
**
** Description      :  Used to Read the JobStatus of NVM 
**                      
** Invocation       :  Tracediag_Read_Service_11
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**====================================================================================================================*/
static void Tracediag_Service_11_Get_NVMJobStatus(uint8 *data)
{
	//(void) Rte_Read_rp_SR_MemAbsJobStatus_JobStatus_NV_ECU_Software_Date(data);
}
#endif
#endif

#ifdef TRACEDIAG_SERVICE_12
/*=====================================================================================================================
** Function Name    :  Tracediag_Service_12_Set_NVMData
**
** Visibility       :  Private 
**
** Description      :  Used to write the data in NVM(Application has to map the RTE call for the same)
**                      
** Invocation       :  Tracediag_Write_Service_12
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**====================================================================================================================*/
static uint8 Tracediag_Service_12_Set_NVMData(uint8 *data)
{
    Std_ReturnType ret = E_NOT_OK;

    //ret = Rte_Call_rp_CS_MemAbsSet_Set_NV_Calibration_Date(data);

	return ret;
}
/*=====================================================================================================================
** Function Name    :  Tracediag_Service_12_Get_NVMData
**
** Visibility       :  Private 
**
** Description      :  Used to Read the data from NVM(Application has to map the RTE call for the same)
**                      
** Invocation       :  Tracediag_Read_Service_12
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**====================================================================================================================*/
static uint8 Tracediag_Service_12_Get_NVMData(uint8 *data)
{
	Std_ReturnType ret = E_OK;

	//(void) Rte_Call_rp_CS_MemAbsGet_Get_NV_Calibration_Date(data);

    return ret;
}
#ifndef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
/*=====================================================================================================================
** Function Name    :  Tracediag_Service_12_Get_NVMJobStatus
**
** Visibility       :  Private 
**
** Description      :  Used to Read the JobStatus of NVM 
**                      
** Invocation       :  Tracediag_Read_Service_12
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**====================================================================================================================*/
static void Tracediag_Service_12_Get_NVMJobStatus(uint8 *data)
{
	//(void) Rte_Read_rp_SR_MemAbsJobStatus_JobStatus_NV_Calibration_Date(data);
}
#endif
#endif

#ifdef TRACEDIAG_SERVICE_13
/*=====================================================================================================================
** Function Name    :  Tracediag_Service_13_Set_NVMData
**
** Visibility       :  Private 
**
** Description      :  Used to write the data in NVM(Application has to map the RTE call for the same)
**                      
** Invocation       :  Tracediag_Write_Service_13
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**====================================================================================================================*/
static uint8 Tracediag_Service_13_Set_NVMData(uint8 *data)
{
    Std_ReturnType ret = E_NOT_OK;

    //ret = Rte_Call_rp_CS_MemAbsSet_Set_NV_NvM_Version(data);

	return ret;
}
/*=====================================================================================================================
** Function Name    :  Tracediag_Service_13_Get_NVMData
**
** Visibility       :  Private 
**
** Description      :  Used to read the data from NVM(Application has to map the RTE call for the same)
**                      
** Invocation       :  Tracediag_Read_Service_13
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**====================================================================================================================*/
static uint8 Tracediag_Service_13_Get_NVMData(uint8 *data)
{
	Std_ReturnType ret = E_OK;

	//(void) Rte_Call_rp_CS_MemAbsGet_Get_NV_NvM_Version(data);

    return ret;
}
#ifndef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
/*=====================================================================================================================
** Function Name    :  Tracediag_Service_13_Get_NVMJobStatus
**
** Visibility       :  Private 
**
** Description      :  Used to Read the JobStatus of NVM 
**                      
** Invocation       :  Tracediag_Read_Service_13
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**====================================================================================================================*/
static void Tracediag_Service_13_Get_NVMJobStatus(uint8 *data)
{
	//(void) Rte_Read_rp_SR_MemAbsJobStatus_JobStatus_NV_NvM_Version(data);
}
#endif
#endif

#ifdef TRACEDIAG_SERVICE_14
/*=====================================================================================================================
** Function Name    :  Tracediag_Service_14_Set_NVMData
**
** Visibility       :  Private 
**
** Description      :  Used to write the data in NVM(Application has to map the RTE call for the same)
**                      
** Invocation       :  Tracediag_Write_Service_14
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**====================================================================================================================*/
static uint8 Tracediag_Service_14_Set_NVMData(uint8 *data)
{
    Std_ReturnType ret = E_NOT_OK;

    //ret = Rte_Call_rp_CS_MemAbsSet_Set_NV_Wifi_MAC_Address(data);

	return ret;
}
/*=====================================================================================================================
** Function Name    :  Tracediag_Service_14_Get_NVMData
**
** Visibility       :  Private 
**
** Description      :  Used to read the data from NVM(Application has to map the RTE call for the same)
**                      
** Invocation       :  Tracediag_Read_Service_14
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**====================================================================================================================*/
static uint8 Tracediag_Service_14_Get_NVMData(uint8 *data)
{
	Std_ReturnType ret = E_OK;

	//(void) Rte_Call_rp_CS_MemAbsGet_Get_NV_Wifi_MAC_Address(data);

    return ret;
}
#ifndef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
/*=====================================================================================================================
** Function Name    :  Tracediag_Service_14_Get_NVMJobStatus
**
** Visibility       :  Private 
**
** Description      :  Used to Read the JobStatus of NVM 
**                      
** Invocation       :  Tracediag_Read_Service_14
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**====================================================================================================================*/
static void Tracediag_Service_14_Get_NVMJobStatus(uint8 *data)
{
	//(void) Rte_Read_rp_SR_MemAbsJobStatus_JobStatus_NV_Wifi_MAC_Address(data);
}
#endif
#endif

#ifdef TRACEDIAG_SERVICE_15
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Service_15_Set_NVMData
**
** Visibility       :  Private 
**
** Description      :  Used to write the data in NVM(Application has to map the RTE call for the same)
**                      
**
** Invocation       :  Tracediag_Write_Service_15
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**
**====================================================================================================================*/

static uint8 Tracediag_Service_15_Set_NVMData(uint8 *data)
{
    Std_ReturnType ret = E_NOT_OK;
	Dcm_NegativeResponseCodeType ErrorCode[2] = {0};
	ErrorCode[0] = DCM_E_OK;
	//ret = Need to be replaced by RTE
	
	//If there is any error code need to be updated here
	/*if(ret == E_NOT_OK)
	{
		ret = E_NOT_OK;
		ErrorCode[0] = DCM_E_CONDITIONSNOTCORRECT;
		data[0] = ErrorCode[0];
	}
	else
	{
		ret = E_OK;
	}
	#endif*/
	return ret;

}
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Service_15_Get_NVMData
**
** Visibility       :  Private 
**
** Description      :  Used to read the data from NVM(Application has to map the RTE call for the same)
**                      
**
** Invocation       :  Tracediag_Read_Service_15
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**
**====================================================================================================================*/
static uint8 Tracediag_Service_15_Get_NVMData(uint8 *data)
{
    return E_OK;
}
#ifndef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Service_15_Get_NVMJobStatus
**
** Visibility       :  Private 
**
** Description      :  Used to Read the JobStatus of NVM 
**                      
**
** Invocation       :  Tracediag_Read_Service_15
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**
**====================================================================================================================*/
static void Tracediag_Service_15_Get_NVMJobStatus(uint8 *data)
{
	UNUSED(data);
}
#endif
#endif

#ifdef TRACEDIAG_SERVICE_16
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Service_16_Set_NVMData
**
** Visibility       :  Private 
**
** Description      :  Used to write the data in NVM(Application has to map the RTE call for the same)
**                      
**
** Invocation       :  Tracediag_Write_Service_16
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**
**====================================================================================================================*/

static uint8 Tracediag_Service_16_Set_NVMData(uint8 *data)
{
    Std_ReturnType ret = E_NOT_OK;
	Dcm_NegativeResponseCodeType ErrorCode[2] = {0};
	ErrorCode[0] = DCM_E_OK;
	//ret = Need to be replaced by RTE
	
	//If there is any error code need to be updated here
	/*if(ret == E_NOT_OK)
	{
		ret = E_NOT_OK;
		ErrorCode[0] = DCM_E_CONDITIONSNOTCORRECT;
		data[0] = ErrorCode[0];
	}
	else
	{
		ret = E_OK;
	}
	#endif*/
	return ret;

}
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Service_16_Get_NVMData
**
** Visibility       :  Private 
**
** Description      :  Used to read the data from NVM(Application has to map the RTE call for the same)
**                      
**
** Invocation       :  Tracediag_Read_Service_16
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**
**====================================================================================================================*/
static uint8 Tracediag_Service_16_Get_NVMData(uint8 *data)
{
    return E_OK;
}
#ifndef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Service_16_Get_NVMJobStatus
**
** Visibility       :  Private 
**
** Description      :  Used to Read the JobStatus of NVM 
**                      
**
** Invocation       :  Tracediag_Read_Service_16
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**
**====================================================================================================================*/
static void Tracediag_Service_16_Get_NVMJobStatus(uint8 *data)
{
	UNUSED(data);
}
#endif
#endif

#ifdef TRACEDIAG_SERVICE_17
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Service_17_Set_NVMData
**
** Visibility       :  Private 
**
** Description      :  Used to write the data in NVM(Application has to map the RTE call for the same)
**                      
**
** Invocation       :  Tracediag_Write_Service_17
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**
**====================================================================================================================*/
static uint8 Tracediag_Service_17_Set_NVMData(uint8 *data)
{
    Std_ReturnType ret = E_NOT_OK;
	Dcm_NegativeResponseCodeType ErrorCode[2] = {0};
	ErrorCode[0] = DCM_E_OK;
	//ret = Need to be replaced by RTE
	
	//If there is any error code need to be updated here
	/*if(ret == E_NOT_OK)
	{
		ret = E_NOT_OK;
		ErrorCode[0] = DCM_E_CONDITIONSNOTCORRECT;
		data[0] = ErrorCode[0];
	}
	else
	{
		ret = E_OK;
	}
	#endif*/
	return ret;

}
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Service_17_Get_NVMData
**
** Visibility       :  Private 
**
** Description      :  NVM and SOFTWARE version reading
**                      
**
** Invocation       :  Tracediag_Read_Service_17
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**
**====================================================================================================================*/
static uint8 Tracediag_Service_17_Get_NVMData(uint8 *data)
{
    Std_ReturnType ret = E_NOT_OK;
    boolean MfgModeActive;
	#ifdef MEET_GIP_ENABLED
	Dcm_NegativeResponseCodeType ErrorCode[2] = {0};
	ErrorCode[0] = DCM_E_OK;
	SDiagResponse_t DiagResp;
	MeetDiagReqType DiagReq; 
	#endif

	uint8 NVMVersion = 0;
    uint8 NVMRevision = 0;
	
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if(MfgModeActive == MEET_SESSION)
    {
		//Rte_Read_NV_NvM_Revision_Value(&NVMRevision);			//RTE need to be replaced as per project 
		//Rte_Read_NV_NvM_Version_Value(&NVMVersion);			//RTE need to be replaced as per project 
		data[DATA_BYTE_0] = NVMVersion;
		data[DATA_BYTE_1] = NVMRevision;
		
		data[DATA_BYTE_2] = MFG_SW_MAJOR_VERSION;		//bookshelf version 1.1.21
		data[DATA_BYTE_3] = MFG_SW_MINOR_VERSION;   
		data[DATA_BYTE_4] = MFG_SW_REVISION;		

	    data[DATA_BYTE_5] = BOOT_SW_MAJOR_VERSION[0]; 	// FBL_VERSION
		data[DATA_BYTE_6] = BOOT_SW_MAJOR_VERSION[1];	//JUST RANDOM VALUE IS ASSIGNED
		data[DATA_BYTE_7] = BOOT_SW_MINOR_VERSION[0]; 	//values need to be changed 
		data[DATA_BYTE_8] = BOOT_SW_MINOR_VERSION[1];
		data[DATA_BYTE_9] = BOOT_SW_REVISION[0];	
		data[DATA_BYTE_10] = BOOT_SW_REVISION[1];
		
		data[DATA_BYTE_11] = VIP_SW_MAJOR_VERSION[0];  //SW_VERSION
		data[DATA_BYTE_12] = VIP_SW_MAJOR_VERSION[1];	//as per Releasecfg.cfg
		data[DATA_BYTE_13] = VIP_SW_MINOR_VERSION[0];  
		data[DATA_BYTE_14] = VIP_SW_MINOR_VERSION[1];
		data[DATA_BYTE_15] = VIP_SW_REVISION[0];		
		data[DATA_BYTE_16] = VIP_SW_REVISION[1];	
		
		#ifdef MEET_GIP_ENABLED	
	
			DiagReq.ActionP = DiagActionType_Read;		//01
			DiagReq.ServiceId = cREAD_GIP_VERSION;
			DiagReq.LengthP = Cust_FlashSW_Length;
		//	DiagReq.LengthP = Cust_FlashSW_Length+1;
		//	DiagReq.DataP[0] = MGRDIAGCDD_READ_ACTION;		//0x22
		
			switch(Tracediag_CurrentGIPState)
			{
				case eGIP_InitiateRequest:
				  ret = Meet_Process_Gip_Diag_Request(Tracediag_CurrentGIPState, &DiagReq, ErrorCode);
				  Tracediag_CurrentGIPState = eGIP_WaitForResponse;
					break;
				case eGIP_WaitForResponse:
					ret = Meet_Process_Gip_Diag_Request(Tracediag_CurrentGIPState, &DiagReq, ErrorCode);
					if(ret != DCM_E_PENDING)
					{
					Tracediag_CurrentGIPState = eGIP_InitiateRequest;
					}
					break;
				default:
					/*No action required in default case*/
					break;
			}
			
		if(DCM_E_OK == ret)
		{
			DiagResp = *Diag_TIGIP_GetDiagResponse();
			if(Cust_FlashSW_Length == DiagResp.Length)
			{
				data[DATA_BYTE_17] = DiagResp.DiagRespBuffer[0];
				data[DATA_BYTE_18] = DiagResp.DiagRespBuffer[1];
				data[DATA_BYTE_19] = DiagResp.DiagRespBuffer[2];
				data[DATA_BYTE_20] = DiagResp.DiagRespBuffer[3];
				data[DATA_BYTE_21] = DiagResp.DiagRespBuffer[4];
				data[DATA_BYTE_22] = DiagResp.DiagRespBuffer[5];


			}
			else
			{
				//Size mismatch
				ret = DCM_E_NOT_OK;
			}
		}
		#endif
		
    }
    return ret;
}
#ifndef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Service_17_Get_NVMJobStatus
**
** Visibility       :  Private 
**
** Description      :  Used to Read the JobStatus of NVM 
**                      
**
** Invocation       :  Tracediag_Read_Service_17
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**
**====================================================================================================================*/
static void Tracediag_Service_17_Get_NVMJobStatus(uint8 *data)
{
	UNUSED(data);
}
#endif
#endif

#ifdef TRACEDIAG_SERVICE_18
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Service_18_Set_NVMData
**
** Visibility       :  Private 
**
** Description      :  Used to write the data in NVM(Application has to map the RTE call for the same)
**                      
**
** Invocation       :  Tracediag_Write_Service_18
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**
**====================================================================================================================*/
static uint8 Tracediag_Service_18_Set_NVMData(uint8 *data)
{
    Std_ReturnType ret = E_NOT_OK;
	Dcm_NegativeResponseCodeType ErrorCode[2] = {0};
	ErrorCode[0] = DCM_E_OK;
	//ret = Need to be replaced by RTE
	
	//If there is any error code need to be updated here
	/*if(ret == E_NOT_OK)
	{
		ret = E_NOT_OK;
		ErrorCode[0] = DCM_E_CONDITIONSNOTCORRECT;
		data[0] = ErrorCode[0];
	}
	else
	{
		ret = E_OK;
	}
	#endif*/
	return ret;

}
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Service_18_Get_NVMData
**
** Visibility       :  Private 
**
** Description      :  Used to read the data from NVM(Application has to map the RTE call for the same)
**                      
**
** Invocation       :  Tracediag_Read_Service_18
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**
**====================================================================================================================*/
static uint8 Tracediag_Service_18_Get_NVMData(uint8 *data)
{
    return E_OK;

}
#ifndef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Service_18_Get_NVMJobStatus
**
** Visibility       :  Private 
**
** Description      :  Used to Read the JobStatus of NVM 
**                      
**
** Invocation       :  Tracediag_Read_Service_18
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**
**====================================================================================================================*/
static void Tracediag_Service_18_Get_NVMJobStatus(uint8 *data)
{
	UNUSED(data);
}
#endif
#endif

#ifdef TRACEDIAG_SERVICE_19
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Service_19_Set_NVMData
**
** Visibility       :  Private 
**
** Description      :  Used to write the data in NVM(Application has to map the RTE call for the same)
**                      
**
** Invocation       :  Tracediag_Write_Service_19
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**
**====================================================================================================================*/
static uint8 Tracediag_Service_19_Set_NVMData(uint8 *data)
{
    Std_ReturnType ret = E_NOT_OK;
	Dcm_NegativeResponseCodeType ErrorCode[2] = {0};
	ErrorCode[0] = DCM_E_OK;
	//ret = Need to be replaced by RTE
	
	//If there is any error code need to be updated here
	/*if(ret == E_NOT_OK)
	{
		ret = E_NOT_OK;
		ErrorCode[0] = DCM_E_CONDITIONSNOTCORRECT;
		data[0] = ErrorCode[0];
	}
	else
	{
		ret = E_OK;
	}
	#endif*/
	return ret;

}
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Service_19_Get_NVMData
**
** Visibility       :  Private 
**
** Description      :  Used to read the data from NVM(Application has to map the RTE call for the same)
**                      
**
** Invocation       :  Tracediag_Read_Service_19
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**
**====================================================================================================================*/
static uint8 Tracediag_Service_19_Get_NVMData(uint8 *data)
{
    return E_OK;

}
#ifndef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Service_19_Get_NVMJobStatus
**
** Visibility       :  Private 
**
** Description      :  Used to Read the JobStatus of NVM 
**                      
**
** Invocation       :  Tracediag_Read_Service_19
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**
**====================================================================================================================*/
static void Tracediag_Service_19_Get_NVMJobStatus(uint8 *data)
{
	UNUSED(data);
}
#endif
#endif

#ifdef TRACEDIAG_SERVICE_20
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Service_20_Set_NVMData
**
** Visibility       :  Private 
**
** Description      :  Used to write the data in NVM(Application has to map the RTE call for the same)
**                      
**
** Invocation       :  Tracediag_Write_Service_19
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**
**====================================================================================================================*/
static uint8 Tracediag_Service_20_Set_NVMData(uint8 *data)
{
    Std_ReturnType ret = E_NOT_OK;
	Dcm_NegativeResponseCodeType ErrorCode[2] = {0};
	ErrorCode[0] = DCM_E_OK;
	//ret = Need to be replaced by RTE
	
	//If there is any error code need to be updated here
	/*if(ret == E_NOT_OK)
	{
		ret = E_NOT_OK;
		ErrorCode[0] = DCM_E_CONDITIONSNOTCORRECT;
		data[0] = ErrorCode[0];
	}
	else
	{
		ret = E_OK;
	}
	#endif*/
	return ret;

}
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Service_20_Get_NVMData
**
** Visibility       :  Private 
**
** Description      :  Used to read the data from NVM(Application has to map the RTE call for the same)
**                      
**
** Invocation       :  Tracediag_Read_Service_19
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**
**====================================================================================================================*/
static uint8 Tracediag_Service_20_Get_NVMData(uint8 *data)
{
    return E_OK;

}
#ifndef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Service_20_Get_NVMJobStatus
**
** Visibility       :  Private 
**
** Description      :  Used to Read the JobStatus of NVM 
**                      
**
** Invocation       :  Tracediag_Read_Service_20
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**
**====================================================================================================================*/
static void Tracediag_Service_20_Get_NVMJobStatus(uint8 *data)
{
	UNUSED(data);
}
#endif
#endif

//#ifdef TRACEDIAG_SERVICE_24
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Service_24_Get_NVMData
**
** Visibility       :  Private 
**
** Description      :  Used to read the data from NVM(Application has to map the RTE call for the same)
**                      
**
** Invocation       :  Tracediag_Read_Service_19
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**
**====================================================================================================================*/
#ifdef TRACEDIAG_SERVICE_24
static uint8 Tracediag_Service_24_Set_NVMData(uint8 *data)
{
    Std_ReturnType ret = E_NOT_OK;
	
    //ret = Rte_Call_rp_CS_MemAbsSet_Set_NVM_CAN_Database_Version(data);

	return ret;
}
/*=====================================================================================================================
** Function Name    :  Tracediag_Service_24_Get_NVMData
**
** Visibility       :  Private 
**
** Description      :  Used to Read the data from NVM(Application has to map the RTE call for the same)
**                      
** Invocation       :  Tracediag_Read_Service_24
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**====================================================================================================================*/
static uint8 Tracediag_Service_24_Get_NVMData(uint8 *data)
{
	//Rte_Call_rp_CS_TPFirmware_ReflashStatus_TPFirmware_ReflashStatus(&data[0], &data[1], &data[2]);
	return E_OK;
}
#ifndef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
/*=====================================================================================================================
** Function Name    :  Tracediag_Service_24_Get_NVMJobStatus
**
** Visibility       :  Private 
**
** Description      :  Used to Read the JobStatus of NVM 
**                      
** Invocation       :  Tracediag_Read_Service_24
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**====================================================================================================================*/
static void Tracediag_Service_24_Get_NVMJobStatus(uint8 *data)
{
	//(void) Rte_Read_rp_SR_JobStatus_JobStatus_VisteonPartNumber(data);
}
#endif
#endif

#ifdef TRACEDIAG_SERVICE_25
/*=====================================================================================================================
** Function Name    :  TraceDiag_TPFirmware_Start
**
** Visibility       :  Private 
**
** Description      :  calls the API to do TFT Pattern control STA (Short Term Adjustment)
**                      
** Invocation       :  Displaycontrol.diagcdd, Function:Displaycontroldiag_TFTPatternControl_Duty_STA
**
** Inputs           :  Data[In]:TFT Pattern Parameter
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section :  Yes/No
**====================================================================================================================*/
static Std_ReturnType TraceDiag_TPFirmware_Start(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;

	//Rte_Call_rp_CS_TPFirmware_Update_Start_Status_TPFirmware_Update_Start_Status(TRUE);

    return ret;
}

/*=====================================================================================================================
** Function Name    :  TraceDiag_TPFirmware_Results
**
** Visibility       :  Private 
**
** Description      :  calls the API to do TFT Pattern control RCTE(Return control to ECU)
**                      
** Invocation       :  Displaycontrol.diagcdd, Displaycontroldiag_TFTPatternControl_Duty_RCTE
**
** Inputs           :  Errorcode:to be updated with error code if any
**					   
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section :  Yes/No
**====================================================================================================================*/
static Std_ReturnType TraceDiag_TPFirmware_Results(uint8 *Data)
{
    Std_ReturnType ret = E_NOT_OK;
    //Rte_Call_rp_CS_TPFirmware_RoutineStatus_TPFirmware_RoutineStatus(Data);
    return ret;
}
#endif

#ifdef TRACEDIAG_TRACEBYTES_STATION_1
/*=====================================================================================================================
**
** Function Name    :  Tracediagservice_SetNVM_TraceBytesTRACE_STATION_1
**
** Visibility       :  Private 
**
** Description      :  Used to write Traceability bytes TRACE_STATION_1 in NVM(Application has to map the RTE call for the same)
**                      
**
** Invocation       :  Tracediag_Traceability_Bytes_TRACE_STATION_1_Write
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**
**====================================================================================================================*/
static uint8 Tracediagservice_SetNVM_TraceBytesTRACE_STATION_1(uint8 *data)
{
    return E_OK;
}
/*=====================================================================================================================
**
** Function Name    :  Tracediagservice_GetNVM_TraceBytesTRACE_STATION_1
**
** Visibility       :  Private 
**
** Description      :  Used to Read Traceability bytes TRACE_STATION_1 in NVM(Application has to map the RTE call for the same)
**                      
**
** Invocation       :  Tracediag_Traceability_Bytes_TRACE_STATION_1_Read
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**
**====================================================================================================================*/
static uint8 Tracediagservice_GetNVM_TraceBytesTRACE_STATION_1(uint8 *data)
{
    return E_OK;
}
#endif

#ifdef TRACEDIAG_TRACEBYTES_STATION_2
/*=====================================================================================================================
**
** Function Name    :  Tracediagservice_SetNVM_TraceBytesTRACE_STATION_2
**
** Visibility       :  Private 
**
** Description      :  Used to write Traceability bytes TRACE_STATION_2 in NVM(Application has to map the RTE call for the same)
**                      
**
** Invocation       :  Tracediag_Traceability_Bytes_TRACE_STATION_2_Write
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**
**====================================================================================================================*/
static uint8 Tracediagservice_SetNVM_TraceBytesTRACE_STATION_2(uint8 *data)
{
    return E_OK;
}
/*=====================================================================================================================
**
** Function Name    :  Tracediagservice_GetNVM_TraceBytesTRACE_STATION_2
**
** Visibility       :  Private 
**
** Description      :  Used to Read Traceability bytes TRACE_STATION_2 in NVM(Application has to map the RTE call for the same)
**                      
**
** Invocation       :  Tracediag_Traceability_Bytes_TRACE_STATION_2_Read
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**
**====================================================================================================================*/
static uint8 Tracediagservice_GetNVM_TraceBytesTRACE_STATION_2(uint8 *data)
{
    return E_OK;
}

#endif

#ifdef TRACEDIAG_TRACEBYTES_STATION_3
/*=====================================================================================================================
**
** Function Name    :  Tracediagservice_SetNVM_TraceBytesTRACE_STATION_3
**
** Visibility       :  Private 
**
** Description      :  Used to write Traceability bytes TRACE_STATION_3 in NVM(Application has to map the RTE call for the same)
**                      
**
** Invocation       :  Tracediag_Traceability_Bytes_TRACE_STATION_3_Write
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**
**====================================================================================================================*/
static uint8 Tracediagservice_SetNVM_TraceBytesTRACE_STATION_3(uint8 *data)
{
    return E_OK;
}
/*=====================================================================================================================
**
** Function Name    :  Tracediagservice_GetNVM_TraceBytesTRACE_STATION_3
**
** Visibility       :  Private 
**
** Description      :  Used to Read Traceability bytes TRACE_STATION_3 in NVM(Application has to map the RTE call for the same)
**                      
**
** Invocation       :  Tracediag_Traceability_Bytes_TRACE_STATION_3_Read
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**
**====================================================================================================================*/
static uint8 Tracediagservice_GetNVM_TraceBytesTRACE_STATION_3(uint8 *data)
{
    return E_OK;
}
#endif

#ifdef TRACEDIAG_TRACEBYTES_STATION_4
/*=====================================================================================================================
**
** Function Name    :  Tracediagservice_SetNVM_TraceBytesTRACE_STATION_4
**
** Visibility       :  Private 
**
** Description      :  Used to write Traceability bytes TRACE_STATION_4 in NVM(Application has to map the RTE call for the same)
**                      
**
** Invocation       :  Tracediag_Traceability_Bytes_TRACE_STATION_4_Write
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**
**====================================================================================================================*/
static uint8 Tracediagservice_SetNVM_TraceBytesTRACE_STATION_4(uint8 *data)
{
    return E_OK;
}
/*=====================================================================================================================
**
** Function Name    :  Tracediagservice_GetNVM_TraceBytesTRACE_STATION_4
**
** Visibility       :  Private 
**
** Description      :  Used to Read Traceability bytes TRACE_STATION_4 in NVM(Application has to map the RTE call for the same)
**                      
**
** Invocation       :  Tracediag_Traceability_Bytes_TRACE_STATION_4_Read
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**
**====================================================================================================================*/
static uint8 Tracediagservice_GetNVM_TraceBytesTRACE_STATION_4(uint8 *data)
{
    return E_OK;
}
#endif

#ifdef TRACEDIAG_TRACEBYTES_STATION_5
/*=====================================================================================================================
**
** Function Name    :  Tracediagservice_SetNVM_TraceBytesTRACE_STATION_5
**
** Visibility       :  Private 
**
** Description      :  Used to write Traceability bytes TRACE_STATION_5 in NVM(Application has to map the RTE call for the same)
**                      
**
** Invocation       :  Tracediag_Traceability_Bytes_TRACE_STATION_5_Write
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**
**====================================================================================================================*/
static uint8 Tracediagservice_SetNVM_TraceBytesTRACE_STATION_5(uint8 *data)
{
    return E_OK;
}
/*=====================================================================================================================
**
** Function Name    :  Tracediagservice_GetNVM_TraceBytesTRACE_STATION_5
**
** Visibility       :  Private 
**
** Description      :  Used to Read Traceability bytes TRACE_STATION_5 in NVM(Application has to map the RTE call for the same)
**                      
**
** Invocation       :  Tracediag_Traceability_Bytes_TRACE_STATION_5_Read
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**
**====================================================================================================================*/
static uint8 Tracediagservice_GetNVM_TraceBytesTRACE_STATION_5(uint8 *data)
{
    return E_OK;
}
#endif

#ifdef TRACEDIAG_RESERVEDBYTES
/*=====================================================================================================================
**
** Function Name    :  Tracediagservice_SetNVM_ReservedBytes
**
** Visibility       :  Private 
**
** Description      :  Used to write reserved bytes in NVM(Application has to map the RTE call for the same)
**                      
**
** Invocation       :  Tracediag_Reserved_Bytes_Write
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**
**====================================================================================================================*/
static uint8 Tracediagservice_SetNVM_ReservedBytes(uint8 *data)
{
    return E_OK;

}
/*=====================================================================================================================
**
** Function Name    :  Tracediagservice_GetNVM_ReservedBytes
**
** Visibility       :  Private 
**
** Description      :  Used to read reserved bytes in NVM(Application has to map the RTE call for the same)
**                      
**
** Invocation       :  Tracediag_Reserved_Bytes_Read
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**
**====================================================================================================================*/

static uint8 Tracediagservice_GetNVM_ReservedBytes(uint8 *data)
{
    return E_OK;

}
#endif

#ifdef TRACEDIAG_TRACEABILITY_BYTES
#ifdef TRACE_STATION_1
/*=====================================================================================================================
**
** Function Name    :  Tracediagservice_SetNVM_Station_TRACE_STATION_1
**
** Visibility       :  Private
**
** Description      :  Used to write TRACE_STATION_1 station status(Application has to map the RTE call for the same)
**
**
** Invocation       :  Tracediag_Traceability_Bytes_Write
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**
**====================================================================================================================*/
static uint8 Tracediagservice_SetNVM_Station_TRACE_STATION_1(uint8 *data)
{
  return E_OK;
}
#endif
#ifdef TRACE_STATION_2
/*=====================================================================================================================
**
** Function Name    :  Tracediagservice_SetNVM_Station_TRACE_STATION_2
**
** Visibility       :  Private
**
** Description      :  Used to write TRACE_STATION_2 station status(Application has to map the RTE call for the same)
**
**
** Invocation       :  Tracediag_Traceability_Bytes_Write
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**
**====================================================================================================================*/
static uint8 Tracediagservice_SetNVM_Station_TRACE_STATION_2(uint8 *data)
{
  return E_OK;
}
#endif
#ifdef TRACE_STATION_3
/*=====================================================================================================================
**
** Function Name    :  Tracediagservice_SetNVM_Station_TRACE_STATION_3
**
** Visibility       :  Private
**
** Description      :  Used to write TRACE_STATION_3 station status(Application has to map the RTE call for the same)
**
**
** Invocation       :  Tracediag_Traceability_Bytes_Write
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**
**====================================================================================================================*/
static uint8 Tracediagservice_SetNVM_Station_TRACE_STATION_3(uint8 *data)
{
  return E_OK;
}
#endif
#ifdef TRACE_STATION_4
/*=====================================================================================================================
**
** Function Name    :  Tracediagservice_SetNVM_Station_TRACE_STATION_4
**
** Visibility       :  Private
**
** Description      :  Used to write TRACE_STATION_4 station status(Application has to map the RTE call for the same)
**
**
** Invocation       :  Tracediag_Traceability_Bytes_Write
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**
**====================================================================================================================*/
static uint8 Tracediagservice_SetNVM_Station_TRACE_STATION_4(uint8 *data)
{
  return E_OK;
}
#endif
#ifdef TRACE_STATION_5
/*=====================================================================================================================
**
** Function Name    :  Tracediagservice_SetNVM_Station_TRACE_STATION_5
**
** Visibility       :  Private
**
** Description      :  Used to write TRACE_STATION_5 station status(Application has to map the RTE call for the same)
**
**
** Invocation       :  Tracediag_Traceability_Bytes_Write
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**
**====================================================================================================================*/
static uint8 Tracediagservice_SetNVM_Station_TRACE_STATION_5(uint8 *data)
{
  return E_OK;
}
#endif
#ifdef TRACE_STATION_6
/*=====================================================================================================================
**
** Function Name    :  Tracediagservice_SetNVM_Station_TRACE_STATION_6
**
** Visibility       :  Private
**
** Description      :  Used to write TRACE_STATION_6 station status(Application has to map the RTE call for the same)
**
**
** Invocation       :  Tracediag_Traceability_Bytes_Write
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**
**====================================================================================================================*/
static uint8 Tracediagservice_SetNVM_Station_TRACE_STATION_6(uint8 *data)
{
  return E_OK;
}
#endif
#ifdef TRACE_STATION_1
/*=====================================================================================================================
**
** Function Name    :  Tracediagservice_GetNVM_Station_TRACE_STATION_1
**
** Visibility       :  Private
**
** Description      :  Used to read TRACE_STATION_1 station status in NVM(Application has to map the RTE call for the same)
**
**
** Invocation       :  Tracediag_Traceability_Bytes_Read
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**
**====================================================================================================================*/
static uint8 Tracediagservice_GetNVM_Station_TRACE_STATION_1(uint8 *data)
{
   return E_OK;
}
#endif
#ifdef TRACE_STATION_2
/*=====================================================================================================================
**
** Function Name    :  Tracediagservice_GetNVM_Station_TRACE_STATION_2
**
** Visibility       :  Private
**
** Description      :  Used to read TRACE_STATION_2 station status in NVM(Application has to map the RTE call for the same)
**
**
** Invocation       :  Tracediag_Traceability_Bytes_Read
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**
**====================================================================================================================*/
static uint8 Tracediagservice_GetNVM_Station_TRACE_STATION_2(uint8 *data)
{
   return E_OK;
}
#endif
#ifdef TRACE_STATION_3
/*=====================================================================================================================
**
** Function Name    :  Tracediagservice_GetNVM_Station_TRACE_STATION_3
**
** Visibility       :  Private
**
** Description      :  Used to read TRACE_STATION_3 station status in NVM(Application has to map the RTE call for the same)
**
**
** Invocation       :  Tracediag_Traceability_Bytes_Read
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**
**====================================================================================================================*/
static uint8 Tracediagservice_GetNVM_Station_TRACE_STATION_3(uint8 *data)
{
   return E_OK;
}
#endif
#ifdef TRACE_STATION_4
/*=====================================================================================================================
**
** Function Name    :  Tracediagservice_GetNVM_Station_TRACE_STATION_4
**
** Visibility       :  Private
**
** Description      :  Used to read TRACE_STATION_4 station status in NVM(Application has to map the RTE call for the same)
**
**
** Invocation       :  Tracediag_Traceability_Bytes_Read
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**
**====================================================================================================================*/
static uint8 Tracediagservice_GetNVM_Station_TRACE_STATION_4(uint8 *data)
{
   return E_OK;
}
#endif
#ifdef TRACE_STATION_5
/*=====================================================================================================================
**
** Function Name    :  Tracediagservice_GetNVM_Station_TRACE_STATION_5
**
** Visibility       :  Private
**
** Description      :  Used to read TRACE_STATION_5 station status in NVM(Application has to map the RTE call for the same)
**
**
** Invocation       :  Tracediag_Traceability_Bytes_Read
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**
**====================================================================================================================*/
static uint8 Tracediagservice_GetNVM_Station_TRACE_STATION_5(uint8 *data)
{
   return E_OK;
}
#endif
#ifdef TRACE_STATION_6
/*=====================================================================================================================
**
** Function Name    :  Tracediagservice_GetNVM_Station_TRACE_STATION_6
**
** Visibility       :  Private
**
** Description      :  Used to read TRACE_STATION_6 station status in NVM(Application has to map the RTE call for the same)
**
**
** Invocation       :  Tracediag_Traceability_Bytes_Read
**
** Inputs           :  Data.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**
**====================================================================================================================*/
static uint8 Tracediagservice_GetNVM_Station_TRACE_STATION_6(uint8 *data)
{
   return E_OK;
}
#endif
#endif
/*=====================================================================================================================
**
** Function Name    :  Tracediagservice_Set_NVM_JobStatus
**
** Visibility       :  Private
**
** Description      :  Used to set NVM job status as 0 for the previous request
**
** Invocation       :
**
** Inputs           :  data
**
** Outputs          :
**
** Critical Section :  No
**
**====================================================================================================================*/
static void Tracediagservice_Set_NVM_JobStatus(uint8 data)
{
    UNUSED(data);
}

/*=====================================================================================================================
**
** Function Name    :  Tracediagservice_Get_NVM_JobStatus
**
** Visibility       :  Private
**
** Description      :  Used to get NVM job status of current request
**
** Invocation       :
**
** Inputs           :  data
**
** Outputs          :
**
** Critical Section :  No
**
**====================================================================================================================*/
static void Tracediagservice_Get_NVM_JobStatus(uint8 *data)
{
    if (data != NULL_PTR)
    {
        *data = NVM_REQ_OK;
    }
}

/*=====================================================================================================================
**  for each change to this file, be sure to record:                     
**  1.  who made the change and when the change was made                 
**  2.  why the change was made and the intended result                
**  Following block needs to be repeated for each change
**====================================================================================================================*/
/*=====================================================================================================================
**   Note: In the traceability column we need to trace back to the Design Doc.
**   For the initial version it is traced to the Design Document section.     
**   For further changes it shall trace to the source of the change which may
**   be SPSS/SCR/Defect details(Defect may be Testing/validation defect)/Any  
**   other reason                                                             
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  24/Aug/2022
** CDSID             :  ddanecha
** Traceability      :  RTC-1744046
** Change Description:  In Get funtion, RTE calls return type is updated as void.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  03/Aug/2022
** CDSID             :  ddanecha
** Traceability      :  RTC-1707104
** Change Description:  MeetCdd Coverity-MISRA fix
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  23/05/2022
** CDSID             :  ddanecha
** Traceability      :  RTC 1634375
** Change Description:  Coverity/MISRA Fix and Minor update.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  16/05/2022
** CDSID             :  ddanecha
** Traceability      :  RTC 1632871, 1655512, 1660171
** Change Description:  - Tracediag_IsStringInRange, Tracediag_IsByteInRange, Tracediag_IsStringInRange_1 and
** 						Tracediag_IsByteInRange_1 interfaces are now binded with the configurable macro.
** 						- Configurations are updated to support tracediag interfaces.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 6/May/2021
** CDSID             : razhakes
** Traceability      : RTC-1291863
** Change Description: COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM introduced
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  12/march/2019
** CDSID             :  razhakes
** Traceability      :  RTC 1296903
** Change Description:  vip - gip communication and nvm soft version read related functions are declared
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 22/Dec/2018
** CDSID             : dkasiman
** Traceability      : RTC-1258974  
** Change Description: Prototype changed for Get_NVM and Set_NVM job status.
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
/*=====================================================================================================================
** Date              :  20/May/2018  
** CDSID             :  dkasiman
** Traceability      :  RTC-1098594
** Change Description:  Initial version for MeetCdd bookshelf - Traceability services
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  02/March/2021  
** CDSID             :  razhakes
** Traceability      :  RTC-1252782
** Change Description:  FESN impl
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  12/April/2023  
** CDSID             :  spalan11
** Traceability      :  RTC-1977277
** Change Description:  Update Tracediag_Service_24_Set_NVMData function
**====================================================================================================================*/
#endif
