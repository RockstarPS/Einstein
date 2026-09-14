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
*  File Name         :  DltExt_Types.h                                          *
*  Module Short Name :  DltExt_Types                                            *
*  Description       :  Types header file of the AUTOSAR Diagnostic Log and  *
*                                                    Trace, according to:    *
*                      AUTOSAR Diagnostic Log and Trace, AUTOSAR Release 4.0 *
*                                                                            *
* Organization     :                                                         *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  GHS Multi                                              *
* Target Hardware  :  Platform Indpendent                                    *
*                                                                            *
******************************************************************************/
/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#ifndef DLTEXT_TYPES_H
# define DLTEXT_TYPES_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "Std_Types.h"

#ifdef DLT_RTE_CORE 
//#include "Rte_Dlt_Type.h"
#endif 

#include "DltExt_MemCfg.h"
#include "Mcu.h"
//#include "typedefs.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/

#define DLTEXT_BUFFER_RESERVED_LEN      (uint8)(DLTEXT_MAX_NVM_SIZE - (DLTEXT_LAST_REST_HISTORY_NUM*DLTEXT_MAX_RESETCODE_SIZE + 3) - (DLTEXT_LAST_APP_HISTORY_NUM*DLTEXT_MAX_RESETCODE_SIZE))
#define DLTEXT_RESETLOGDATA_MAX_LEN     (uint8)(DLTEXT_LAST_REST_HISTORY_NUM*DLTEXT_MAX_RESETCODE_SIZE + 3 + DLTEXT_BUFFER_RESERVED_LEN)
#define DLTEXT_APPLOGDATA_MAX_LEN       (uint8)(DLTEXT_LAST_APP_HISTORY_NUM*DLTEXT_MAX_RESETCODE_SIZE)

typedef uint8 tTypeCode;

/*misra_c_2012_rule_2_3_violation:	Type "tDltExt_LocalConfigDataType" is defined but never used.
This is retained because code is commented,*/
/*typedef struct
{
    uint8      No_of_CyclicBuffer;  
    uint8      Buffer_Length;
    boolean    FaultCounter_EN;
}tDltExt_LocalConfigDataType;*/ /* MISRA C-2012 Rule 2.5, will be used in future implementation*/

typedef struct
{ // DLT Extension Reset Log Data Buffer for Critical Faults
    uint8 code[DLTEXT_LAST_REST_HISTORY_NUM][DLTEXT_MAX_RESETCODE_SIZE];
    uint8 unexpectedResetCode[3];               /* Unexpected Reset reason code that is to be stored immeadiately */
    uint8 reserved[DLTEXT_BUFFER_RESERVED_LEN]; /* Additional bytes available in Reserved Health Management */
} tDltExt_ResetLogDataBuffer;

// 78 bytes of AppLogDataBuffer with 16byts Reserved
typedef struct
{ // DLT Extension Application Log Data Buffer for Non-critical Faults
    uint8 code[DLTEXT_LAST_APP_HISTORY_NUM][DLTEXT_MAX_RESETCODE_SIZE];
} tDltExt_AppLogDataBuffer;

// 160byts NvMData
typedef struct
{
    uint8 ResetLogDataBuffer[DLTEXT_RESETLOGDATA_MAX_LEN]; // 78 bytes of ResetLogDataBuffer including 16bytes reserved
    uint8 AppLogDataBuffer[DLTEXT_APPLOGDATA_MAX_LEN];     // 78 bytes of AppLogDataBuffer with 16byts Reserved
} tDltExt_NVMData;

typedef struct
{ // DltExt Logger Counter Map
    uint16 errorCode;
    uint8 *first_counter;
    uint8 *second_counter;
} tDltExt_ErrCodeCounterMap;

typedef struct
{
    uint8 DltExt_Generic_Reset_Counter;
    uint8 DltExt_Illegal_Memory_Address_Reset_Counter;
    uint8 DltExt_StackOverflowReset_Counter;
    uint8 DltExt_IllegalOpCodeReset_Counter;
    uint8 DltExt_PowerON_Counter;
    uint8 DltExt_WatchdogTimerReset_Counter;
} tDltExt_CounterInfo;

typedef struct
{
    uint8 NumCyclicBuffers;
    uint8 BufferLength;
    boolean FaultCounterEN;
} tDltExt_ConfigType;

typedef struct
{
uint16 Message_ID;
uint32 Time_Stamp;
uint8 Addon_LogData[6];
boolean Valid_Flag;
}tDltExt_UclDataBuffer; /*Fault Data cyclic buffer*/

typedef struct 
{
    uint16 KPI_MessageID;
    uint32 KPI_Timestamp;
    uint8 KPI_Varible;
    uint8 Faultstatus;
    uint8 KPI_Snapshot[5];
    uint32 DeltaKPI;
}tDltExt_KpiMsg;  /*KPI message format*/

typedef struct
{
    tDltExt_KpiMsg KPIMessage;
    boolean ValidFlag;
}tDltExt_KpiCyclicBuffer;

typedef struct
{
    uint16 Kpi_FaultCode;
    uint8 Kpi_Buffer_Size;                      /*Cyclic Buffer Size Configuration*/
    uint8 NvMThreshold;                         /*VIP NVM Write Threshold*/
    boolean Dwnld_NvM_CyclicBuffer;             /*Download from NVM into cyclic buffer*/
    boolean Ucl_ConfigEn;                       /*UCL Transport Configuration*/
    boolean SerialInterface_ConfigEn;           /*Serial Interface  Transport Configuration*/              
    uint8 tDltExt_DiffOrMetricsEn;              /*Configuration mode*/
    boolean SocNvmStrge_Appl;                   /*SoC Nvm Storage applicablity*/
}tDlt_KPI_Catagory;  

/* Misra line 183 , same name used line 171*/

typedef struct
{   uint16 errorCode;
    uint8 *first_counter;
    uint8 *second_counter;
    boolean CBSC;/*Cyclic Buffer Size Configuration*/
    boolean Threshold; /*VIP NVM Write Threshold*/
    boolean NVM_Sup_Sdwn;/*Download from NVM Startup Shutdown*/
    boolean UCL_TC; /*UCL  Transport Configuration*/
    boolean SITC; /*Serial Interface  Transport Configuration*/
    boolean Soc_Nvm_storage_Appl; /*SoC Nvm Storage applicablity*/
}tDltExt_ErrCodeCounterMap_Cfg;

typedef struct
{ 
    uint8 Fault_Category;                     /*Fault code category*/
    uint8 VIP_NvM_Threshold;               /*VIP NVM Write Threshold*/
    boolean NVM_to_CyclicBuff;               /*Download from NVM into cyclic buffer*/
    boolean UCL_Transport_Configuration;     /*UCL  Transport Configuration*/
    boolean Serial_Interface_Config;         /*Serial Interface  Transport Configuration*/
    boolean Time_Diff_Config;                /*Time Difference Configuration */
    boolean KPI_Metrics_Config;              /*KPI Metrics Configuration*/
    boolean Soc_Nvm_storage_Appl;            /*SoC Nvm Storage applicablity*/
}tDlt_App_error_Catagory;  

typedef struct
{
    uint16 Message_Kpi;
    uint8 Variable_Kpi;
    uint16 Expected_Kpi;
}tDltExt_KPI_Config;

typedef struct 
{
	Mcu_ResetType ResetCode;
	uint16 Dlt_FaultCode;
}ResetTypeTable;


#endif /* DLTEXT_TYPES_H_ */

