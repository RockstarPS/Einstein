/*****************************************************************************
 *                                                                            *
 *              CONFIDENTIAL VISTEON CORPORATION                              *
 *                                                                            *
 * This is an unpublished work of authorship, which contains trade            *
 * secrets, created in 2022. Visteon Corporation owns all rights to           *
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
/******************************************************************************/
/**
 * @file            Dcm_App.h
 * @brief           Dcm_App
 * @details         Implements Diagnostic services - application layer
 * @author          mmenon
 * Organization     Driver Information Software Section,
 *                  Visteon Corporation
 */
/******************************************************************************
 * Compiler Name    : GHS 2017.1.4
 * Target Processor : Traveo II
 *****************************************************************************/

//#include "Rte_DcmApp.h"
//#include "NvM_Cfg.h"
//#include "NvM.h"
#include "Rte_Dcm_Type.h"

#define eRTFREEZ                   0x02u
#define eRTDef                     0x01u

#  ifndef eRead
#   define eRead (0U)
#  endif

#  ifndef eWrite
#   define eWrite (1U)
#  endif

#  ifndef eRTCtrlToEcu
#   define eRTCtrlToEcu (2U)
#  endif

#  ifndef eRstToDefault
#   define eRstToDefault (3U)
#  endif

#  ifndef eFCS
#   define eFCS (4U)
#  endif

#  ifndef eSTA
#   define eSTA (5U)
#  endif

#  ifndef eRoutineStart
#   define eRoutineStart (0U)
#  endif

#  ifndef eRoutineStop
#   define eRoutineStop (1U)
#  endif

#  ifndef eRoutineResults
#   define eRoutineResults (2U)
#  endif

# define APP_DCM_DEM_IGNORE_UNREF_PARAM(param)    ((void)(param))

extern Std_ReturnType Dcm_App_RID_FD90_handler( teDiagOpStatus pOpStatus,
     P2VAR(UInt8, AUTOMATIC, RTE_DCM_APP_APPL_VAR) pData,
     P2VAR(UInt16, AUTOMATIC, RTE_DCM_APP_APPL_VAR) DataLength,
     P2VAR(UInt8, AUTOMATIC, RTE_DCM_APP_APPL_VAR) pNrc,
     teRoutineOperation eOperation
     );
	 
#define PROGRAM_NVM_FROM_ROM_NONE			   (uint8)0
#define PROGRAM_NVM_STAGE1_ROM_TO_RAM_RESTORE  (uint8)1
#define PROGRAM_NVM_STAGE2_RAM_TO_NVM_WRITE	   (uint8)2
#define DATA_BYTE_0 			     		   (uint8)0
#define MEMDIAG_PROGRAM_NVM_FROM_ROM_RCTYPE    (uint8)2

typedef struct
{
   Std_ReturnType (*DCM_App_Diag_RestoreNVM_MappingBlkIDtoRTE) (uint8 BlockID);
}Dcm_App_Diag_ProgramNvmFromRomtype;

typedef struct
{
Std_ReturnType (*DCM_App_Diag_WriteNVM_MappingBlkIDtoRTE) (uint8 BlockID);
}Dcm_App_Diag_ProgramNVMFromRamtype;


typedef struct
{
	Std_ReturnType (*DCM_App_Diag_JobResultRead_byBlkID) (uint16 BlkID, uint8 *JobResult);
}Dcm_App_Diag_ReadJobResultbyBlkID;


typedef enum{
    eROUTINE_INACTIVE,
    eROUTINE_INPROGRESS,
    eROUTINE_FINISH_OK,
    eROUTINE_FINISH_NOK,
}eRoutineStatus;	 

/* End of File */
/****************************************************************************
*   for each change to this file, be sure to record:                        *
*      1.  who made the change and when the change was made                 *
*      2.  why the change was made and the intended result                  *
*   Following block needs to be repeated for each change                    *
*****************************************************************************/



