/******************************************************************************
**              CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2012. Visteon Corporation owns all rights to this work and
** intends to maintain it in confidence to preserve its trade secret status.
** Visteon Corporation reserves the right, under the copyright laws of the
** United States or those of any other country that may have  jurisdiction,
** to protect this work as an unpublished work, in the event of an
** inadvertent or deliberate unauthorized publication. Visteon Corporation
** also reserves its rights under all copyright laws to protect this work as
** a published work, when appropriate. Those having access to this work may
** not copy it, use it, modify it or disclose the information contained in
** it without the written authorization of Visteon Corporation
**
******************************************************************************/

/******************************************************************************

File Name        :  MemAbstract.c
Module Short Name:  MemAbstract.c
VOBName          :  
Author           :  
Description      :  Generated File
Organization     :  Driver Information Software Section,
                    Visteon Corporation

******************************************************************************/

#ifndef MEMABSTRACT_C
#define MEMABSTRACT_C
/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "Rte_Type.h"
#include "MemLib.h"
#include "MemAbstract.h"
#include "Rte_MemAbstractStub.h"
#define RTE_CORE

#undef RTE_PTR2ARRAYBASETYPE_PASSING
#include "Rte_MemAbstractMdl.h"

#include "NvM.h"

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/


/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/
/*****************************************************************************
*                                Globally  accessed Variable Declarations    *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/


/*****************************************************************************
*                                 Locally used Variable Declarations         *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/


/*****************************************************************************
*                              Limited Scope Prototypes                      *
******************************************************************************/

/*****************************************************************************
*                   Functions                                                *
******************************************************************************/
typedef enum
{
   WRITE_IDLE,
   WRITE_REQUESTED,
   WRITE_PROGRESS,
   WRITE_PENDING
}MemAbstractWriteStateType;

typedef enum
{
   MEMABS_RESET_IDLE,
   MEMABS_RESET_REQUESTED,
   MEMABS_REQUESTS_COMPLETED,
   MEMABS_PENDING_BSW_BLOCKS,
   MEMABS_RESET_READY
}MemAbs_HardResetType;

typedef struct
{
   MemAbstractWriteStateType WriteState;
   uint8 PrvWriteStatus;
   boolean ValidData;
}MemAbstractManagementType;

#define NUM_OF_MEMABSTRACT_BLOCKS    60U
#define MEMABS_MEET_MODE_INACTIVE    0U

static MemAbstractManagementType MemAbstractManagement[NUM_OF_MEMABSTRACT_BLOCKS];
static boolean ProcessRequest = TRUE;
static MemAbs_HardResetType MemAbsHardResetStatus;
#include "CmpLib.h"
/// @brief  Instance of life-cycle state-machine
CMPLIB_INSTANCE( MemAbstractMdl )

//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================





#ifndef Rte_Read_rp_SR_MeetMode_MeetModeStatus
#  define Rte_Read_rp_SR_MeetMode_MeetModeStatus Rte_Read_MemAbstractMdl_rp_SR_MeetMode_MeetModeStatus
#  define Rte_Read_MemAbstractMdl_rp_SR_MeetMode_MeetModeStatus(data) (*(data) = 0, ((Std_ReturnType)RTE_E_OK))
#endif





extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdReflash_Element;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaMode_Element;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaFinPrint_Element;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaStatus_Element;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotadecrypt_Element;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_EcuPartNumber_Element;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_VisMeet_Element;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_VehicleConfig_Element;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_SpeedoGauge_Element;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_TachoGauge_Element;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_FuelGauge_Element;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_TempGauge_Element;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_PowerGauge_Element;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_OilGauge_Element;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_TripComputer_Element;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Illumination_Element;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Audio_Element;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Warning_Element;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_RealTimeClock_Element;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Communication_Element;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Power_Element;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_ServiceReminder_Element;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_EngOffTimer_Element;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsFuSa_Warning_Element;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsFuSa_Power_Element;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsFuSa_Display_Element;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsFuSa_Audio_Element;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsFuSa_Communication_Element;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsFusa_Fota_Element;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsFuSa_Config_Element;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsCys_Certicificate_Element;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_RefCys_Certicificate_Element;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_RefCys_Certicificate1_Element;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_Odometer_Element;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_SpeedoGauge_Element;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_TachoGauge_Element;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_FuelGauge_Element;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_TempGauge_Element;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_PowerGauge_Element;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_OilGauge_Element;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_TripComputer_Element;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_Warning_Element;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_RealTimeClock_Element;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_Personalization_Element;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_Illumination_Element;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_CusDlt_Element;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Odometer_Element;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Gauges_Element;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Tripcomputer_Element;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Illumination_Element;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Audio_Element;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Warning_Element;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_RealTimeClock_Element;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Communication_Element;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Personalization_Element;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_VisDlt_Element;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Power_Element;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Display_Element;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsDiag_ErrorRecord_Element;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsDiag_Dtc_Element;
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_SwUpdReflash_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdReflash_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdReflash_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdReflash_Element = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaMode_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaMode_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaMode_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaMode_Element = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaFinPrint_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaFinPrint_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaFinPrint_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaFinPrint_Element = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaStatus_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaStatus_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaStatus_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaStatus_Element = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotadecrypt_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotadecrypt_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotadecrypt_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotadecrypt_Element = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_EcuPartNumber_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_EcuPartNumber_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_EcuPartNumber_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_EcuPartNumber_Element = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_VisMeet_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_VisMeet_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_VisMeet_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_VisMeet_Element = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_VehicleConfig_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_VehicleConfig_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_VehicleConfig_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_VehicleConfig_Element = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_SpeedoGauge_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_SpeedoGauge_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_SpeedoGauge_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_SpeedoGauge_Element = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_TachoGauge_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_TachoGauge_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_TachoGauge_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_TachoGauge_Element = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_FuelGauge_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_FuelGauge_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_FuelGauge_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_FuelGauge_Element = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_TempGauge_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_TempGauge_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_TempGauge_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_TempGauge_Element = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_PowerGauge_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_PowerGauge_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_PowerGauge_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_PowerGauge_Element = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_OilGauge_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_OilGauge_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_OilGauge_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_OilGauge_Element = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_TripComputer_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_TripComputer_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_TripComputer_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_TripComputer_Element = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Illumination_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Illumination_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Illumination_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Illumination_Element = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Audio_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Audio_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Audio_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Audio_Element = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Warning_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Warning_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Warning_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Warning_Element = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_RealTimeClock_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_RealTimeClock_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_RealTimeClock_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_RealTimeClock_Element = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Communication_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Communication_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Communication_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Communication_Element = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Power_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Power_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Power_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Power_Element = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_ServiceReminder_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_ServiceReminder_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_ServiceReminder_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_ServiceReminder_Element = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_EngOffTimer_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_EngOffTimer_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_EngOffTimer_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_EngOffTimer_Element = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsFuSa_Warning_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsFuSa_Warning_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsFuSa_Warning_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsFuSa_Warning_Element = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsFuSa_Power_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsFuSa_Power_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsFuSa_Power_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsFuSa_Power_Element = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsFuSa_Display_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsFuSa_Display_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsFuSa_Display_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsFuSa_Display_Element = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsFuSa_Audio_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsFuSa_Audio_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsFuSa_Audio_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsFuSa_Audio_Element = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsFuSa_Communication_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsFuSa_Communication_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsFuSa_Communication_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsFuSa_Communication_Element = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsFusa_Fota_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsFusa_Fota_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsFusa_Fota_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsFusa_Fota_Element = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsFuSa_Config_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsFuSa_Config_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsFuSa_Config_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsFuSa_Config_Element = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsCys_Certicificate_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsCys_Certicificate_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsCys_Certicificate_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsCys_Certicificate_Element = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_pp_SR_JobStatus_JobStatus_RefCys_Certicificate_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_RefCys_Certicificate_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_RefCys_Certicificate_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_RefCys_Certicificate_Element = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_pp_SR_JobStatus_JobStatus_RefCys_Certicificate1_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_RefCys_Certicificate1_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_RefCys_Certicificate1_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_RefCys_Certicificate1_Element = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_Odometer_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_Odometer_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_Odometer_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_Odometer_Element = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_SpeedoGauge_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_SpeedoGauge_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_SpeedoGauge_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_SpeedoGauge_Element = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_TachoGauge_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_TachoGauge_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_TachoGauge_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_TachoGauge_Element = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_FuelGauge_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_FuelGauge_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_FuelGauge_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_FuelGauge_Element = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_TempGauge_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_TempGauge_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_TempGauge_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_TempGauge_Element = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_PowerGauge_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_PowerGauge_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_PowerGauge_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_PowerGauge_Element = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_OilGauge_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_OilGauge_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_OilGauge_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_OilGauge_Element = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_TripComputer_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_TripComputer_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_TripComputer_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_TripComputer_Element = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_Warning_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_Warning_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_Warning_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_Warning_Element = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_RealTimeClock_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_RealTimeClock_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_RealTimeClock_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_RealTimeClock_Element = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_Personalization_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_Personalization_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_Personalization_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_Personalization_Element = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_Illumination_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_Illumination_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_Illumination_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_Illumination_Element = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_CusDlt_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_CusDlt_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_CusDlt_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_CusDlt_Element = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Odometer_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Odometer_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Odometer_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Odometer_Element = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Gauges_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Gauges_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Gauges_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Gauges_Element = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Tripcomputer_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Tripcomputer_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Tripcomputer_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Tripcomputer_Element = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Illumination_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Illumination_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Illumination_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Illumination_Element = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Audio_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Audio_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Audio_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Audio_Element = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Warning_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Warning_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Warning_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Warning_Element = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_RealTimeClock_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_RealTimeClock_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_RealTimeClock_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_RealTimeClock_Element = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Communication_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Communication_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Communication_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Communication_Element = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Personalization_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Personalization_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Personalization_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Personalization_Element = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_VisDlt_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_VisDlt_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_VisDlt_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_VisDlt_Element = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Power_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Power_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Power_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Power_Element = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Display_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Display_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Display_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Display_Element = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsDiag_ErrorRecord_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsDiag_ErrorRecord_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsDiag_ErrorRecord_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsDiag_ErrorRecord_Element = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsDiag_Dtc_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsDiag_Dtc_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsDiag_Dtc_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsDiag_Dtc_Element = (data), ((Std_ReturnType)RTE_E_OK))
//=====================================================================================================================
//  FORWARD DECLARATIONS
//=====================================================================================================================
//=====================================================================================================================
//  PRIVATE
//=====================================================================================================================

static void Memabs_GetMeetModeStatus(uint8* Status)
{
    Rte_Read_rp_SR_MeetMode_MeetModeStatus(Status);
}
//---------------------------------------------------------------------------------------------------------------------
/// @brief  Transitional initialization state
///
/// @param  void
///
/// @return E_OK:           Succeed
///<br>     E_NOT_READY:    In progress. Keeps the component in this state.
///<br>     E_NOT_OK:       Failed
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpInit( void )
{
    uint16 i;
    for(i=0; i< NUM_OF_MEMABSTRACT_BLOCKS; i++)
    {
        MemAbstractManagement[i].PrvWriteStatus = E_OK;
        MemAbstractManagement[i].WriteState = WRITE_IDLE;
    }
    return (E_OK);
}
//---------------------------------------------------------------------------------------------------------------------
/// @brief  Function indicating that the calling Speed View Pointer is going to transit from InActive to Active state.
///
/// @param  void
///
/// @return Std_ReturnType:   E_OK            - Succeed
///<br>                       E_NOT_OK        - Failed
///<br>                       E_INVALID_ARG   - Invalid pointer
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpActivation( void )
{
    return (E_OK);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Transitional de-activation state
///
/// @param  void
///
/// @return E_OK:           Succeed
///<br>     E_NOT_READY:    In progress
///<br>     E_NOT_OK:       Failed
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpDeActivation ( void )
{
    return (E_OK);
}


//---------------------------------------------------------------------------------------------------------------------
/// @brief  Diagnostic state
///
/// @param  void
///
/// @return E_OK:           Diagnostic has completed. Go to DiagReturn state.
///<br>     E_NOT_READY:    Keeps the component in this state.
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpDiag ( void )
{
    return (E_OK);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Transitional state to clean up after diagnostic state. Component behavior to be restored.
///
/// @param  void
///
/// @return E_OK:           Diagnostic clean-up has completed. Return to the previous state (Active or Inactive).
///<br>     E_NOT_READY:    Keeps the component in this state.
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpDiagReturn ( void )
{
    return (E_OK);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Transitional de-initialization state
///
/// @param  void
///
/// @return E_OK:           Succeed
///<br>     E_NOT_READY:    In progress. Keeps the component in this state.
///<br>     E_NOT_OK:       Failed
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpDeInit( void )
{
    return (E_OK);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  State for normal operations
///
/// @param  void
///
/// @return Std_ReturnType:   E_OK      - Succeed
///<br>                       E_NOT_OK  - Failed
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpActive( void )
{
    return (E_OK);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Function to Notify Reset Entry
///
/// @param  void
///
/// @return void
//---------------------------------------------------------------------------------------------------------------------
void MemAbs_NotifyHardResetEntry(void)
{
    ProcessRequest = FALSE;
    MemAbsHardResetStatus = MEMABS_RESET_REQUESTED;
}

extern Std_ReturnType NvMExt_ProtectFurtherWrite(void);
extern Std_ReturnType NvMExt_GetNvMIdleState(uint8* IdleState);


//---------------------------------------------------------------------------------------------------------------------
/// @brief  Function to check for allow write req
///
/// @param  Std_ReturnType:   E_OK      - Succeed
///<br>                       E_NOT_OK  - Failed 
///
/// @return void
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType MemAbs_AllowWriteRequest(uint8 p_SameValuedetected, uint16 p_BlockId)
{
    Std_ReturnType fl_return = E_NOT_OK;
    if(FALSE == p_SameValuedetected)
    {
        fl_return = E_OK;
    }
    else
    {
        if(MemAbstractManagement[p_BlockId].WriteState == WRITE_IDLE)
        {
            if((E_NOT_OK == MemAbstractManagement[p_BlockId].PrvWriteStatus) || (FALSE == MemAbstractManagement[p_BlockId].ValidData))
            {
                fl_return = E_OK;
            }
            else
            {
                fl_return = E_NOT_OK;
            }
        }
        else
        {
            fl_return = E_NOT_OK;
        }
    }

    return fl_return;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Function to check before reset
///
/// @param  Std_ReturnType:   E_OK      - Succeed
///<br>                       E_NOT_OK  - Failed 
///
/// @return void
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType MemAbs_ReadyToHardReset(void)
{
    Std_ReturnType fl_RetVal;
    uint8 BSWBlockPendingStatus;
    fl_RetVal = E_NOT_OK;
    if (MEMABS_RESET_READY == MemAbsHardResetStatus)
    {
        fl_RetVal = E_OK;
    }
    else
    {
        if (MEMABS_RESET_REQUESTED == MemAbsHardResetStatus)
        {
            NvMExt_ProtectFurtherWrite();
            MemAbsHardResetStatus = MEMABS_PENDING_BSW_BLOCKS;
        }
        NvMExt_GetNvMIdleState(&BSWBlockPendingStatus);
        if(TRUE == BSWBlockPendingStatus)
        {
            MemAbsHardResetStatus = MEMABS_RESET_READY;
            fl_RetVal = E_OK;
        }
    }
    return fl_RetVal;
}

void MemAbstractMdl_Set_BsShare_SwUpdReflash_Element(const Arr_u8_8 *Ptr)
{
    Arr_u8_8 ElementVal = {0U};
    /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
    (void)Rte_Read_BsShare_SwUpdReflash_Element_Value( (Arr_u8_8*)ElementVal);
    uint8 Status = 0U;
    uint8 SameValuedetected = FALSE;
    Std_ReturnType AllowWrite = E_NOT_OK;
    Memabs_GetMeetModeStatus(&Status);
    SameValuedetected = (uint8)MemLib_MemCmp(Ptr,(Arr_u8_8*)ElementVal,sizeof(Arr_u8_8));
    AllowWrite = MemAbs_AllowWriteRequest(SameValuedetected,MemAbstract_BsShare_SwUpdReflash_Index_0);
    if((MEMABS_MEET_MODE_INACTIVE == Status) && (FALSE != ProcessRequest))
    {
        if (E_NOT_OK != AllowWrite)
        {
            /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
            (void)Rte_Write_BsShare_SwUpdReflash_Element_Value(Ptr);
            Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_SwUpdReflash_Element(2);
            if(MemAbstractManagement[MemAbstract_BsShare_SwUpdReflash_Index_0].WriteState == WRITE_IDLE)
            {
                MemAbstractManagement[MemAbstract_BsShare_SwUpdReflash_Index_0].WriteState = WRITE_REQUESTED;
            }
            else if(MemAbstractManagement[MemAbstract_BsShare_SwUpdReflash_Index_0].WriteState == WRITE_PROGRESS)
            {
                MemAbstractManagement[MemAbstract_BsShare_SwUpdReflash_Index_0].WriteState = WRITE_PENDING;
            }
            else
            {
                /*Do nothing*/
            }
        }
    }
    else
    {
        Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_SwUpdReflash_Element(1);
    }
}


Std_ReturnType MemAbstractMdl_Get_BsShare_SwUpdReflash_Element(Arr_u8_8* Ptr)
{
     Std_ReturnType status = E_NOT_OK;
     /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
     (void)Rte_Read_BsShare_SwUpdReflash_Element_Value(Ptr);
     if(FALSE != MemAbstractManagement[0].ValidData)
     {
         status = E_OK;
     }
     return (status);
}


void MemAbstractMdl_Set_BsShare_SwUpdFotaMode_Element(const Arr_u8_16 *Ptr)
{
    Arr_u8_16 ElementVal = {0U};
    /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
    (void)Rte_Read_BsShare_SwUpdFotaMode_Element_Value( (Arr_u8_16*)ElementVal);
    uint8 Status = 0U;
    uint8 SameValuedetected = FALSE;
    Std_ReturnType AllowWrite = E_NOT_OK;
    Memabs_GetMeetModeStatus(&Status);
    SameValuedetected = (uint8)MemLib_MemCmp(Ptr,(Arr_u8_16*)ElementVal,sizeof(Arr_u8_16));
    AllowWrite = MemAbs_AllowWriteRequest(SameValuedetected,MemAbstract_BsShare_SwUpdFotaMode_Index_1);
    if((MEMABS_MEET_MODE_INACTIVE == Status) && (FALSE != ProcessRequest))
    {
        if (E_NOT_OK != AllowWrite)
        {
            /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
            (void)Rte_Write_BsShare_SwUpdFotaMode_Element_Value(Ptr);
            Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaMode_Element(2);
            if(MemAbstractManagement[MemAbstract_BsShare_SwUpdFotaMode_Index_1].WriteState == WRITE_IDLE)
            {
                MemAbstractManagement[MemAbstract_BsShare_SwUpdFotaMode_Index_1].WriteState = WRITE_REQUESTED;
            }
            else if(MemAbstractManagement[MemAbstract_BsShare_SwUpdFotaMode_Index_1].WriteState == WRITE_PROGRESS)
            {
                MemAbstractManagement[MemAbstract_BsShare_SwUpdFotaMode_Index_1].WriteState = WRITE_PENDING;
            }
            else
            {
                /*Do nothing*/
            }
        }
    }
    else
    {
        Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaMode_Element(1);
    }
}


Std_ReturnType MemAbstractMdl_Get_BsShare_SwUpdFotaMode_Element(Arr_u8_16* Ptr)
{
     Std_ReturnType status = E_NOT_OK;
     /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
     (void)Rte_Read_BsShare_SwUpdFotaMode_Element_Value(Ptr);
     if(FALSE != MemAbstractManagement[1].ValidData)
     {
         status = E_OK;
     }
     return (status);
}


void MemAbstractMdl_Set_BsShare_SwUpdFotaFinPrint_Element(const Arr_u8_32 *Ptr)
{
    Arr_u8_32 ElementVal = {0U};
    /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
    (void)Rte_Read_BsShare_SwUpdFotaFinPrint_Element_Value( (Arr_u8_32*)ElementVal);
    uint8 Status = 0U;
    uint8 SameValuedetected = FALSE;
    Std_ReturnType AllowWrite = E_NOT_OK;
    Memabs_GetMeetModeStatus(&Status);
    SameValuedetected = (uint8)MemLib_MemCmp(Ptr,(Arr_u8_32*)ElementVal,sizeof(Arr_u8_32));
    AllowWrite = MemAbs_AllowWriteRequest(SameValuedetected,MemAbstract_BsShare_SwUpdFotaFinPrint_Index_2);
    if((MEMABS_MEET_MODE_INACTIVE == Status) && (FALSE != ProcessRequest))
    {
        if (E_NOT_OK != AllowWrite)
        {
            /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
            (void)Rte_Write_BsShare_SwUpdFotaFinPrint_Element_Value(Ptr);
            Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaFinPrint_Element(2);
            if(MemAbstractManagement[MemAbstract_BsShare_SwUpdFotaFinPrint_Index_2].WriteState == WRITE_IDLE)
            {
                MemAbstractManagement[MemAbstract_BsShare_SwUpdFotaFinPrint_Index_2].WriteState = WRITE_REQUESTED;
            }
            else if(MemAbstractManagement[MemAbstract_BsShare_SwUpdFotaFinPrint_Index_2].WriteState == WRITE_PROGRESS)
            {
                MemAbstractManagement[MemAbstract_BsShare_SwUpdFotaFinPrint_Index_2].WriteState = WRITE_PENDING;
            }
            else
            {
                /*Do nothing*/
            }
        }
    }
    else
    {
        Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaFinPrint_Element(1);
    }
}


Std_ReturnType MemAbstractMdl_Get_BsShare_SwUpdFotaFinPrint_Element(Arr_u8_32* Ptr)
{
     Std_ReturnType status = E_NOT_OK;
     /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
     (void)Rte_Read_BsShare_SwUpdFotaFinPrint_Element_Value(Ptr);
     if(FALSE != MemAbstractManagement[2].ValidData)
     {
         status = E_OK;
     }
     return (status);
}


void MemAbstractMdl_Set_BsShare_SwUpdFotaStatus_Element(const Arr_u8_48 *Ptr)
{
    Arr_u8_48 ElementVal = {0U};
    /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
    (void)Rte_Read_BsShare_SwUpdFotaStatus_Element_Value( (Arr_u8_48*)ElementVal);
    uint8 Status = 0U;
    uint8 SameValuedetected = FALSE;
    Std_ReturnType AllowWrite = E_NOT_OK;
    Memabs_GetMeetModeStatus(&Status);
    SameValuedetected = (uint8)MemLib_MemCmp(Ptr,(Arr_u8_48*)ElementVal,sizeof(Arr_u8_48));
    AllowWrite = MemAbs_AllowWriteRequest(SameValuedetected,MemAbstract_BsShare_SwUpdFotaStatus_Index_3);
    if((MEMABS_MEET_MODE_INACTIVE == Status) && (FALSE != ProcessRequest))
    {
        if (E_NOT_OK != AllowWrite)
        {
            /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
            (void)Rte_Write_BsShare_SwUpdFotaStatus_Element_Value(Ptr);
            Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaStatus_Element(2);
            if(MemAbstractManagement[MemAbstract_BsShare_SwUpdFotaStatus_Index_3].WriteState == WRITE_IDLE)
            {
                MemAbstractManagement[MemAbstract_BsShare_SwUpdFotaStatus_Index_3].WriteState = WRITE_REQUESTED;
            }
            else if(MemAbstractManagement[MemAbstract_BsShare_SwUpdFotaStatus_Index_3].WriteState == WRITE_PROGRESS)
            {
                MemAbstractManagement[MemAbstract_BsShare_SwUpdFotaStatus_Index_3].WriteState = WRITE_PENDING;
            }
            else
            {
                /*Do nothing*/
            }
        }
    }
    else
    {
        Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaStatus_Element(1);
    }
}


Std_ReturnType MemAbstractMdl_Get_BsShare_SwUpdFotaStatus_Element(Arr_u8_48* Ptr)
{
     Std_ReturnType status = E_NOT_OK;
     /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
     (void)Rte_Read_BsShare_SwUpdFotaStatus_Element_Value(Ptr);
     if(FALSE != MemAbstractManagement[3].ValidData)
     {
         status = E_OK;
     }
     return (status);
}


void MemAbstractMdl_Set_BsShare_SwUpdFotadecrypt_Element(const Arr_u8_64 *Ptr)
{
    Arr_u8_64 ElementVal = {0U};
    /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
    (void)Rte_Read_BsShare_SwUpdFotadecrypt_Element_Value( (Arr_u8_64*)ElementVal);
    uint8 Status = 0U;
    uint8 SameValuedetected = FALSE;
    Std_ReturnType AllowWrite = E_NOT_OK;
    Memabs_GetMeetModeStatus(&Status);
    SameValuedetected = (uint8)MemLib_MemCmp(Ptr,(Arr_u8_64*)ElementVal,sizeof(Arr_u8_64));
    AllowWrite = MemAbs_AllowWriteRequest(SameValuedetected,MemAbstract_BsShare_SwUpdFotadecrypt_Index_4);
    if((MEMABS_MEET_MODE_INACTIVE == Status) && (FALSE != ProcessRequest))
    {
        if (E_NOT_OK != AllowWrite)
        {
            /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
            (void)Rte_Write_BsShare_SwUpdFotadecrypt_Element_Value(Ptr);
            Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotadecrypt_Element(2);
            if(MemAbstractManagement[MemAbstract_BsShare_SwUpdFotadecrypt_Index_4].WriteState == WRITE_IDLE)
            {
                MemAbstractManagement[MemAbstract_BsShare_SwUpdFotadecrypt_Index_4].WriteState = WRITE_REQUESTED;
            }
            else if(MemAbstractManagement[MemAbstract_BsShare_SwUpdFotadecrypt_Index_4].WriteState == WRITE_PROGRESS)
            {
                MemAbstractManagement[MemAbstract_BsShare_SwUpdFotadecrypt_Index_4].WriteState = WRITE_PENDING;
            }
            else
            {
                /*Do nothing*/
            }
        }
    }
    else
    {
        Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotadecrypt_Element(1);
    }
}


Std_ReturnType MemAbstractMdl_Get_BsShare_SwUpdFotadecrypt_Element(Arr_u8_64* Ptr)
{
     Std_ReturnType status = E_NOT_OK;
     /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
     (void)Rte_Read_BsShare_SwUpdFotadecrypt_Element_Value(Ptr);
     if(FALSE != MemAbstractManagement[4].ValidData)
     {
         status = E_OK;
     }
     return (status);
}


void MemAbstractMdl_Set_BsShare_EcuPartNumber_Element(const Arr_u8_128 *Ptr)
{
    Arr_u8_128 ElementVal = {0U};
    /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
    (void)Rte_Read_BsShare_EcuPartNumber_Element_Value( (Arr_u8_128*)ElementVal);
    uint8 Status = 0U;
    uint8 SameValuedetected = FALSE;
    Std_ReturnType AllowWrite = E_NOT_OK;
    Memabs_GetMeetModeStatus(&Status);
    SameValuedetected = (uint8)MemLib_MemCmp(Ptr,(Arr_u8_128*)ElementVal,sizeof(Arr_u8_128));
    AllowWrite = MemAbs_AllowWriteRequest(SameValuedetected,MemAbstract_BsShare_EcuPartNumber_Index_5);
    if((MEMABS_MEET_MODE_INACTIVE == Status) && (FALSE != ProcessRequest))
    {
        if (E_NOT_OK != AllowWrite)
        {
            /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
            (void)Rte_Write_BsShare_EcuPartNumber_Element_Value(Ptr);
            Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_EcuPartNumber_Element(2);
            if(MemAbstractManagement[MemAbstract_BsShare_EcuPartNumber_Index_5].WriteState == WRITE_IDLE)
            {
                MemAbstractManagement[MemAbstract_BsShare_EcuPartNumber_Index_5].WriteState = WRITE_REQUESTED;
            }
            else if(MemAbstractManagement[MemAbstract_BsShare_EcuPartNumber_Index_5].WriteState == WRITE_PROGRESS)
            {
                MemAbstractManagement[MemAbstract_BsShare_EcuPartNumber_Index_5].WriteState = WRITE_PENDING;
            }
            else
            {
                /*Do nothing*/
            }
        }
    }
    else
    {
        Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_EcuPartNumber_Element(1);
    }
}


Std_ReturnType MemAbstractMdl_Get_BsShare_EcuPartNumber_Element(Arr_u8_128* Ptr)
{
     Std_ReturnType status = E_NOT_OK;
     /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
     (void)Rte_Read_BsShare_EcuPartNumber_Element_Value(Ptr);
     if(FALSE != MemAbstractManagement[5].ValidData)
     {
         status = E_OK;
     }
     return (status);
}


void MemAbstractMdl_Set_BsShare_VisMeet_Element(const Arr_u8_48 *Ptr)
{
    Arr_u8_48 ElementVal = {0U};
    /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
    (void)Rte_Read_BsShare_VisMeet_Element_Value( (Arr_u8_48*)ElementVal);
    uint8 Status = 0U;
    uint8 SameValuedetected = FALSE;
    Std_ReturnType AllowWrite = E_NOT_OK;
    Memabs_GetMeetModeStatus(&Status);
    SameValuedetected = (uint8)MemLib_MemCmp(Ptr,(Arr_u8_48*)ElementVal,sizeof(Arr_u8_48));
    AllowWrite = MemAbs_AllowWriteRequest(SameValuedetected,MemAbstract_BsShare_VisMeet_Index_6);
    if((MEMABS_MEET_MODE_INACTIVE == Status) && (FALSE != ProcessRequest))
    {
        if (E_NOT_OK != AllowWrite)
        {
            /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
            (void)Rte_Write_BsShare_VisMeet_Element_Value(Ptr);
            Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_VisMeet_Element(2);
            if(MemAbstractManagement[MemAbstract_BsShare_VisMeet_Index_6].WriteState == WRITE_IDLE)
            {
                MemAbstractManagement[MemAbstract_BsShare_VisMeet_Index_6].WriteState = WRITE_REQUESTED;
            }
            else if(MemAbstractManagement[MemAbstract_BsShare_VisMeet_Index_6].WriteState == WRITE_PROGRESS)
            {
                MemAbstractManagement[MemAbstract_BsShare_VisMeet_Index_6].WriteState = WRITE_PENDING;
            }
            else
            {
                /*Do nothing*/
            }
        }
    }
    else
    {
        Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_VisMeet_Element(1);
    }
}


Std_ReturnType MemAbstractMdl_Get_BsShare_VisMeet_Element(Arr_u8_48* Ptr)
{
     Std_ReturnType status = E_NOT_OK;
     /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
     (void)Rte_Read_BsShare_VisMeet_Element_Value(Ptr);
     if(FALSE != MemAbstractManagement[6].ValidData)
     {
         status = E_OK;
     }
     return (status);
}


void MemAbstractMdl_Set_BsShare_VehicleConfig_Element(const Arr_u8_256 *Ptr)
{
    Arr_u8_256 ElementVal = {0U};
    /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
    (void)Rte_Read_BsShare_VehicleConfig_Element_Value( (Arr_u8_256*)ElementVal);
    uint8 Status = 0U;
    uint8 SameValuedetected = FALSE;
    Std_ReturnType AllowWrite = E_NOT_OK;
    Memabs_GetMeetModeStatus(&Status);
    SameValuedetected = (uint8)MemLib_MemCmp(Ptr,(Arr_u8_256*)ElementVal,sizeof(Arr_u8_256));
    AllowWrite = MemAbs_AllowWriteRequest(SameValuedetected,MemAbstract_BsShare_VehicleConfig_Index_7);
    if((MEMABS_MEET_MODE_INACTIVE == Status) && (FALSE != ProcessRequest))
    {
        if (E_NOT_OK != AllowWrite)
        {
            /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
            (void)Rte_Write_BsShare_VehicleConfig_Element_Value(Ptr);
            Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_VehicleConfig_Element(2);
            if(MemAbstractManagement[MemAbstract_BsShare_VehicleConfig_Index_7].WriteState == WRITE_IDLE)
            {
                MemAbstractManagement[MemAbstract_BsShare_VehicleConfig_Index_7].WriteState = WRITE_REQUESTED;
            }
            else if(MemAbstractManagement[MemAbstract_BsShare_VehicleConfig_Index_7].WriteState == WRITE_PROGRESS)
            {
                MemAbstractManagement[MemAbstract_BsShare_VehicleConfig_Index_7].WriteState = WRITE_PENDING;
            }
            else
            {
                /*Do nothing*/
            }
        }
    }
    else
    {
        Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_VehicleConfig_Element(1);
    }
}


Std_ReturnType MemAbstractMdl_Get_BsShare_VehicleConfig_Element(Arr_u8_256* Ptr)
{
     Std_ReturnType status = E_NOT_OK;
     /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
     (void)Rte_Read_BsShare_VehicleConfig_Element_Value(Ptr);
     if(FALSE != MemAbstractManagement[7].ValidData)
     {
         status = E_OK;
     }
     return (status);
}


void MemAbstractMdl_Set_BsConst_SpeedoGauge_Element(const Arr_u8_64 *Ptr)
{
    Arr_u8_64 ElementVal = {0U};
    /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
    (void)Rte_Read_BsConst_SpeedoGauge_Element_Value( (Arr_u8_64*)ElementVal);
    uint8 Status = 0U;
    uint8 SameValuedetected = FALSE;
    Std_ReturnType AllowWrite = E_NOT_OK;
    Memabs_GetMeetModeStatus(&Status);
    SameValuedetected = (uint8)MemLib_MemCmp(Ptr,(Arr_u8_64*)ElementVal,sizeof(Arr_u8_64));
    AllowWrite = MemAbs_AllowWriteRequest(SameValuedetected,MemAbstract_BsConst_SpeedoGauge_Index_8);
    if((MEMABS_MEET_MODE_INACTIVE == Status) && (FALSE != ProcessRequest))
    {
        if (E_NOT_OK != AllowWrite)
        {
            /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
            (void)Rte_Write_BsConst_SpeedoGauge_Element_Value(Ptr);
            Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_SpeedoGauge_Element(2);
            if(MemAbstractManagement[MemAbstract_BsConst_SpeedoGauge_Index_8].WriteState == WRITE_IDLE)
            {
                MemAbstractManagement[MemAbstract_BsConst_SpeedoGauge_Index_8].WriteState = WRITE_REQUESTED;
            }
            else if(MemAbstractManagement[MemAbstract_BsConst_SpeedoGauge_Index_8].WriteState == WRITE_PROGRESS)
            {
                MemAbstractManagement[MemAbstract_BsConst_SpeedoGauge_Index_8].WriteState = WRITE_PENDING;
            }
            else
            {
                /*Do nothing*/
            }
        }
    }
    else
    {
        Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_SpeedoGauge_Element(1);
    }
}


Std_ReturnType MemAbstractMdl_Get_BsConst_SpeedoGauge_Element(Arr_u8_64* Ptr)
{
     Std_ReturnType status = E_NOT_OK;
     /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
     (void)Rte_Read_BsConst_SpeedoGauge_Element_Value(Ptr);
     if(FALSE != MemAbstractManagement[8].ValidData)
     {
         status = E_OK;
     }
     return (status);
}


void MemAbstractMdl_Set_BsConst_TachoGauge_Element(const Arr_u8_64 *Ptr)
{
    Arr_u8_64 ElementVal = {0U};
    /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
    (void)Rte_Read_BsConst_TachoGauge_Element_Value( (Arr_u8_64*)ElementVal);
    uint8 Status = 0U;
    uint8 SameValuedetected = FALSE;
    Std_ReturnType AllowWrite = E_NOT_OK;
    Memabs_GetMeetModeStatus(&Status);
    SameValuedetected = (uint8)MemLib_MemCmp(Ptr,(Arr_u8_64*)ElementVal,sizeof(Arr_u8_64));
    AllowWrite = MemAbs_AllowWriteRequest(SameValuedetected,MemAbstract_BsConst_TachoGauge_Index_9);
    if((MEMABS_MEET_MODE_INACTIVE == Status) && (FALSE != ProcessRequest))
    {
        if (E_NOT_OK != AllowWrite)
        {
            /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
            (void)Rte_Write_BsConst_TachoGauge_Element_Value(Ptr);
            Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_TachoGauge_Element(2);
            if(MemAbstractManagement[MemAbstract_BsConst_TachoGauge_Index_9].WriteState == WRITE_IDLE)
            {
                MemAbstractManagement[MemAbstract_BsConst_TachoGauge_Index_9].WriteState = WRITE_REQUESTED;
            }
            else if(MemAbstractManagement[MemAbstract_BsConst_TachoGauge_Index_9].WriteState == WRITE_PROGRESS)
            {
                MemAbstractManagement[MemAbstract_BsConst_TachoGauge_Index_9].WriteState = WRITE_PENDING;
            }
            else
            {
                /*Do nothing*/
            }
        }
    }
    else
    {
        Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_TachoGauge_Element(1);
    }
}


Std_ReturnType MemAbstractMdl_Get_BsConst_TachoGauge_Element(Arr_u8_64* Ptr)
{
     Std_ReturnType status = E_NOT_OK;
     /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
     (void)Rte_Read_BsConst_TachoGauge_Element_Value(Ptr);
     if(FALSE != MemAbstractManagement[9].ValidData)
     {
         status = E_OK;
     }
     return (status);
}


void MemAbstractMdl_Set_BsConst_FuelGauge_Element(const Arr_u8_128 *Ptr)
{
    Arr_u8_128 ElementVal = {0U};
    /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
    (void)Rte_Read_BsConst_FuelGauge_Element_Value( (Arr_u8_128*)ElementVal);
    uint8 Status = 0U;
    uint8 SameValuedetected = FALSE;
    Std_ReturnType AllowWrite = E_NOT_OK;
    Memabs_GetMeetModeStatus(&Status);
    SameValuedetected = (uint8)MemLib_MemCmp(Ptr,(Arr_u8_128*)ElementVal,sizeof(Arr_u8_128));
    AllowWrite = MemAbs_AllowWriteRequest(SameValuedetected,MemAbstract_BsConst_FuelGauge_Index_10);
    if((MEMABS_MEET_MODE_INACTIVE == Status) && (FALSE != ProcessRequest))
    {
        if (E_NOT_OK != AllowWrite)
        {
            /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
            (void)Rte_Write_BsConst_FuelGauge_Element_Value(Ptr);
            Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_FuelGauge_Element(2);
            if(MemAbstractManagement[MemAbstract_BsConst_FuelGauge_Index_10].WriteState == WRITE_IDLE)
            {
                MemAbstractManagement[MemAbstract_BsConst_FuelGauge_Index_10].WriteState = WRITE_REQUESTED;
            }
            else if(MemAbstractManagement[MemAbstract_BsConst_FuelGauge_Index_10].WriteState == WRITE_PROGRESS)
            {
                MemAbstractManagement[MemAbstract_BsConst_FuelGauge_Index_10].WriteState = WRITE_PENDING;
            }
            else
            {
                /*Do nothing*/
            }
        }
    }
    else
    {
        Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_FuelGauge_Element(1);
    }
}


Std_ReturnType MemAbstractMdl_Get_BsConst_FuelGauge_Element(Arr_u8_128* Ptr)
{
     Std_ReturnType status = E_NOT_OK;
     /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
     (void)Rte_Read_BsConst_FuelGauge_Element_Value(Ptr);
     if(FALSE != MemAbstractManagement[10].ValidData)
     {
         status = E_OK;
     }
     return (status);
}


void MemAbstractMdl_Set_BsConst_TempGauge_Element(const Arr_u8_64 *Ptr)
{
    Arr_u8_64 ElementVal = {0U};
    /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
    (void)Rte_Read_BsConst_TempGauge_Element_Value( (Arr_u8_64*)ElementVal);
    uint8 Status = 0U;
    uint8 SameValuedetected = FALSE;
    Std_ReturnType AllowWrite = E_NOT_OK;
    Memabs_GetMeetModeStatus(&Status);
    SameValuedetected = (uint8)MemLib_MemCmp(Ptr,(Arr_u8_64*)ElementVal,sizeof(Arr_u8_64));
    AllowWrite = MemAbs_AllowWriteRequest(SameValuedetected,MemAbstract_BsConst_TempGauge_Index_11);
    if((MEMABS_MEET_MODE_INACTIVE == Status) && (FALSE != ProcessRequest))
    {
        if (E_NOT_OK != AllowWrite)
        {
            /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
            (void)Rte_Write_BsConst_TempGauge_Element_Value(Ptr);
            Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_TempGauge_Element(2);
            if(MemAbstractManagement[MemAbstract_BsConst_TempGauge_Index_11].WriteState == WRITE_IDLE)
            {
                MemAbstractManagement[MemAbstract_BsConst_TempGauge_Index_11].WriteState = WRITE_REQUESTED;
            }
            else if(MemAbstractManagement[MemAbstract_BsConst_TempGauge_Index_11].WriteState == WRITE_PROGRESS)
            {
                MemAbstractManagement[MemAbstract_BsConst_TempGauge_Index_11].WriteState = WRITE_PENDING;
            }
            else
            {
                /*Do nothing*/
            }
        }
    }
    else
    {
        Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_TempGauge_Element(1);
    }
}


Std_ReturnType MemAbstractMdl_Get_BsConst_TempGauge_Element(Arr_u8_64* Ptr)
{
     Std_ReturnType status = E_NOT_OK;
     /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
     (void)Rte_Read_BsConst_TempGauge_Element_Value(Ptr);
     if(FALSE != MemAbstractManagement[11].ValidData)
     {
         status = E_OK;
     }
     return (status);
}


void MemAbstractMdl_Set_BsConst_PowerGauge_Element(const Arr_u8_64 *Ptr)
{
    Arr_u8_64 ElementVal = {0U};
    /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
    (void)Rte_Read_BsConst_PowerGauge_Element_Value( (Arr_u8_64*)ElementVal);
    uint8 Status = 0U;
    uint8 SameValuedetected = FALSE;
    Std_ReturnType AllowWrite = E_NOT_OK;
    Memabs_GetMeetModeStatus(&Status);
    SameValuedetected = (uint8)MemLib_MemCmp(Ptr,(Arr_u8_64*)ElementVal,sizeof(Arr_u8_64));
    AllowWrite = MemAbs_AllowWriteRequest(SameValuedetected,MemAbstract_BsConst_PowerGauge_Index_12);
    if((MEMABS_MEET_MODE_INACTIVE == Status) && (FALSE != ProcessRequest))
    {
        if (E_NOT_OK != AllowWrite)
        {
            /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
            (void)Rte_Write_BsConst_PowerGauge_Element_Value(Ptr);
            Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_PowerGauge_Element(2);
            if(MemAbstractManagement[MemAbstract_BsConst_PowerGauge_Index_12].WriteState == WRITE_IDLE)
            {
                MemAbstractManagement[MemAbstract_BsConst_PowerGauge_Index_12].WriteState = WRITE_REQUESTED;
            }
            else if(MemAbstractManagement[MemAbstract_BsConst_PowerGauge_Index_12].WriteState == WRITE_PROGRESS)
            {
                MemAbstractManagement[MemAbstract_BsConst_PowerGauge_Index_12].WriteState = WRITE_PENDING;
            }
            else
            {
                /*Do nothing*/
            }
        }
    }
    else
    {
        Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_PowerGauge_Element(1);
    }
}


Std_ReturnType MemAbstractMdl_Get_BsConst_PowerGauge_Element(Arr_u8_64* Ptr)
{
     Std_ReturnType status = E_NOT_OK;
     /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
     (void)Rte_Read_BsConst_PowerGauge_Element_Value(Ptr);
     if(FALSE != MemAbstractManagement[12].ValidData)
     {
         status = E_OK;
     }
     return (status);
}


void MemAbstractMdl_Set_BsConst_OilGauge_Element(const Arr_u8_64 *Ptr)
{
    Arr_u8_64 ElementVal = {0U};
    /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
    (void)Rte_Read_BsConst_OilGauge_Element_Value( (Arr_u8_64*)ElementVal);
    uint8 Status = 0U;
    uint8 SameValuedetected = FALSE;
    Std_ReturnType AllowWrite = E_NOT_OK;
    Memabs_GetMeetModeStatus(&Status);
    SameValuedetected = (uint8)MemLib_MemCmp(Ptr,(Arr_u8_64*)ElementVal,sizeof(Arr_u8_64));
    AllowWrite = MemAbs_AllowWriteRequest(SameValuedetected,MemAbstract_BsConst_OilGauge_Index_13);
    if((MEMABS_MEET_MODE_INACTIVE == Status) && (FALSE != ProcessRequest))
    {
        if (E_NOT_OK != AllowWrite)
        {
            /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
            (void)Rte_Write_BsConst_OilGauge_Element_Value(Ptr);
            Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_OilGauge_Element(2);
            if(MemAbstractManagement[MemAbstract_BsConst_OilGauge_Index_13].WriteState == WRITE_IDLE)
            {
                MemAbstractManagement[MemAbstract_BsConst_OilGauge_Index_13].WriteState = WRITE_REQUESTED;
            }
            else if(MemAbstractManagement[MemAbstract_BsConst_OilGauge_Index_13].WriteState == WRITE_PROGRESS)
            {
                MemAbstractManagement[MemAbstract_BsConst_OilGauge_Index_13].WriteState = WRITE_PENDING;
            }
            else
            {
                /*Do nothing*/
            }
        }
    }
    else
    {
        Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_OilGauge_Element(1);
    }
}


Std_ReturnType MemAbstractMdl_Get_BsConst_OilGauge_Element(Arr_u8_64* Ptr)
{
     Std_ReturnType status = E_NOT_OK;
     /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
     (void)Rte_Read_BsConst_OilGauge_Element_Value(Ptr);
     if(FALSE != MemAbstractManagement[13].ValidData)
     {
         status = E_OK;
     }
     return (status);
}


void MemAbstractMdl_Set_BsConst_TripComputer_Element(const Arr_u8_64 *Ptr)
{
    Arr_u8_64 ElementVal = {0U};
    /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
    (void)Rte_Read_BsConst_TripComputer_Element_Value( (Arr_u8_64*)ElementVal);
    uint8 Status = 0U;
    uint8 SameValuedetected = FALSE;
    Std_ReturnType AllowWrite = E_NOT_OK;
    Memabs_GetMeetModeStatus(&Status);
    SameValuedetected = (uint8)MemLib_MemCmp(Ptr,(Arr_u8_64*)ElementVal,sizeof(Arr_u8_64));
    AllowWrite = MemAbs_AllowWriteRequest(SameValuedetected,MemAbstract_BsConst_TripComputer_Index_14);
    if((MEMABS_MEET_MODE_INACTIVE == Status) && (FALSE != ProcessRequest))
    {
        if (E_NOT_OK != AllowWrite)
        {
            /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
            (void)Rte_Write_BsConst_TripComputer_Element_Value(Ptr);
            Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_TripComputer_Element(2);
            if(MemAbstractManagement[MemAbstract_BsConst_TripComputer_Index_14].WriteState == WRITE_IDLE)
            {
                MemAbstractManagement[MemAbstract_BsConst_TripComputer_Index_14].WriteState = WRITE_REQUESTED;
            }
            else if(MemAbstractManagement[MemAbstract_BsConst_TripComputer_Index_14].WriteState == WRITE_PROGRESS)
            {
                MemAbstractManagement[MemAbstract_BsConst_TripComputer_Index_14].WriteState = WRITE_PENDING;
            }
            else
            {
                /*Do nothing*/
            }
        }
    }
    else
    {
        Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_TripComputer_Element(1);
    }
}


Std_ReturnType MemAbstractMdl_Get_BsConst_TripComputer_Element(Arr_u8_64* Ptr)
{
     Std_ReturnType status = E_NOT_OK;
     /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
     (void)Rte_Read_BsConst_TripComputer_Element_Value(Ptr);
     if(FALSE != MemAbstractManagement[14].ValidData)
     {
         status = E_OK;
     }
     return (status);
}


void MemAbstractMdl_Set_BsConst_Illumination_Element(const Arr_u8_128 *Ptr)
{
    Arr_u8_128 ElementVal = {0U};
    /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
    (void)Rte_Read_BsConst_Illumination_Element_Value( (Arr_u8_128*)ElementVal);
    uint8 Status = 0U;
    uint8 SameValuedetected = FALSE;
    Std_ReturnType AllowWrite = E_NOT_OK;
    Memabs_GetMeetModeStatus(&Status);
    SameValuedetected = (uint8)MemLib_MemCmp(Ptr,(Arr_u8_128*)ElementVal,sizeof(Arr_u8_128));
    AllowWrite = MemAbs_AllowWriteRequest(SameValuedetected,MemAbstract_BsConst_Illumination_Index_15);
    if((MEMABS_MEET_MODE_INACTIVE == Status) && (FALSE != ProcessRequest))
    {
        if (E_NOT_OK != AllowWrite)
        {
            /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
            (void)Rte_Write_BsConst_Illumination_Element_Value(Ptr);
            Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Illumination_Element(2);
            if(MemAbstractManagement[MemAbstract_BsConst_Illumination_Index_15].WriteState == WRITE_IDLE)
            {
                MemAbstractManagement[MemAbstract_BsConst_Illumination_Index_15].WriteState = WRITE_REQUESTED;
            }
            else if(MemAbstractManagement[MemAbstract_BsConst_Illumination_Index_15].WriteState == WRITE_PROGRESS)
            {
                MemAbstractManagement[MemAbstract_BsConst_Illumination_Index_15].WriteState = WRITE_PENDING;
            }
            else
            {
                /*Do nothing*/
            }
        }
    }
    else
    {
        Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Illumination_Element(1);
    }
}


Std_ReturnType MemAbstractMdl_Get_BsConst_Illumination_Element(Arr_u8_128* Ptr)
{
     Std_ReturnType status = E_NOT_OK;
     /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
     (void)Rte_Read_BsConst_Illumination_Element_Value(Ptr);
     if(FALSE != MemAbstractManagement[15].ValidData)
     {
         status = E_OK;
     }
     return (status);
}


void MemAbstractMdl_Set_BsConst_Audio_Element(const Arr_u8_128 *Ptr)
{
    Arr_u8_128 ElementVal = {0U};
    /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
    (void)Rte_Read_BsConst_Audio_Element_Value( (Arr_u8_128*)ElementVal);
    uint8 Status = 0U;
    uint8 SameValuedetected = FALSE;
    Std_ReturnType AllowWrite = E_NOT_OK;
    Memabs_GetMeetModeStatus(&Status);
    SameValuedetected = (uint8)MemLib_MemCmp(Ptr,(Arr_u8_128*)ElementVal,sizeof(Arr_u8_128));
    AllowWrite = MemAbs_AllowWriteRequest(SameValuedetected,MemAbstract_BsConst_Audio_Index_16);
    if((MEMABS_MEET_MODE_INACTIVE == Status) && (FALSE != ProcessRequest))
    {
        if (E_NOT_OK != AllowWrite)
        {
            /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
            (void)Rte_Write_BsConst_Audio_Element_Value(Ptr);
            Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Audio_Element(2);
            if(MemAbstractManagement[MemAbstract_BsConst_Audio_Index_16].WriteState == WRITE_IDLE)
            {
                MemAbstractManagement[MemAbstract_BsConst_Audio_Index_16].WriteState = WRITE_REQUESTED;
            }
            else if(MemAbstractManagement[MemAbstract_BsConst_Audio_Index_16].WriteState == WRITE_PROGRESS)
            {
                MemAbstractManagement[MemAbstract_BsConst_Audio_Index_16].WriteState = WRITE_PENDING;
            }
            else
            {
                /*Do nothing*/
            }
        }
    }
    else
    {
        Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Audio_Element(1);
    }
}


Std_ReturnType MemAbstractMdl_Get_BsConst_Audio_Element(Arr_u8_128* Ptr)
{
     Std_ReturnType status = E_NOT_OK;
     /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
     (void)Rte_Read_BsConst_Audio_Element_Value(Ptr);
     if(FALSE != MemAbstractManagement[16].ValidData)
     {
         status = E_OK;
     }
     return (status);
}


void MemAbstractMdl_Set_BsConst_Warning_Element(const Arr_u8_64 *Ptr)
{
    Arr_u8_64 ElementVal = {0U};
    /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
    (void)Rte_Read_BsConst_Warning_Element_Value( (Arr_u8_64*)ElementVal);
    uint8 Status = 0U;
    uint8 SameValuedetected = FALSE;
    Std_ReturnType AllowWrite = E_NOT_OK;
    Memabs_GetMeetModeStatus(&Status);
    SameValuedetected = (uint8)MemLib_MemCmp(Ptr,(Arr_u8_64*)ElementVal,sizeof(Arr_u8_64));
    AllowWrite = MemAbs_AllowWriteRequest(SameValuedetected,MemAbstract_BsConst_Warning_Index_17);
    if((MEMABS_MEET_MODE_INACTIVE == Status) && (FALSE != ProcessRequest))
    {
        if (E_NOT_OK != AllowWrite)
        {
            /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
            (void)Rte_Write_BsConst_Warning_Element_Value(Ptr);
            Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Warning_Element(2);
            if(MemAbstractManagement[MemAbstract_BsConst_Warning_Index_17].WriteState == WRITE_IDLE)
            {
                MemAbstractManagement[MemAbstract_BsConst_Warning_Index_17].WriteState = WRITE_REQUESTED;
            }
            else if(MemAbstractManagement[MemAbstract_BsConst_Warning_Index_17].WriteState == WRITE_PROGRESS)
            {
                MemAbstractManagement[MemAbstract_BsConst_Warning_Index_17].WriteState = WRITE_PENDING;
            }
            else
            {
                /*Do nothing*/
            }
        }
    }
    else
    {
        Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Warning_Element(1);
    }
}


Std_ReturnType MemAbstractMdl_Get_BsConst_Warning_Element(Arr_u8_64* Ptr)
{
     Std_ReturnType status = E_NOT_OK;
     /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
     (void)Rte_Read_BsConst_Warning_Element_Value(Ptr);
     if(FALSE != MemAbstractManagement[17].ValidData)
     {
         status = E_OK;
     }
     return (status);
}


void MemAbstractMdl_Set_BsConst_RealTimeClock_Element(const Arr_u8_48 *Ptr)
{
    Arr_u8_48 ElementVal = {0U};
    /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
    (void)Rte_Read_BsConst_RealTimeClock_Element_Value( (Arr_u8_48*)ElementVal);
    uint8 Status = 0U;
    uint8 SameValuedetected = FALSE;
    Std_ReturnType AllowWrite = E_NOT_OK;
    Memabs_GetMeetModeStatus(&Status);
    SameValuedetected = (uint8)MemLib_MemCmp(Ptr,(Arr_u8_48*)ElementVal,sizeof(Arr_u8_48));
    AllowWrite = MemAbs_AllowWriteRequest(SameValuedetected,MemAbstract_BsConst_RealTimeClock_Index_18);
    if((MEMABS_MEET_MODE_INACTIVE == Status) && (FALSE != ProcessRequest))
    {
        if (E_NOT_OK != AllowWrite)
        {
            /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
            (void)Rte_Write_BsConst_RealTimeClock_Element_Value(Ptr);
            Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_RealTimeClock_Element(2);
            if(MemAbstractManagement[MemAbstract_BsConst_RealTimeClock_Index_18].WriteState == WRITE_IDLE)
            {
                MemAbstractManagement[MemAbstract_BsConst_RealTimeClock_Index_18].WriteState = WRITE_REQUESTED;
            }
            else if(MemAbstractManagement[MemAbstract_BsConst_RealTimeClock_Index_18].WriteState == WRITE_PROGRESS)
            {
                MemAbstractManagement[MemAbstract_BsConst_RealTimeClock_Index_18].WriteState = WRITE_PENDING;
            }
            else
            {
                /*Do nothing*/
            }
        }
    }
    else
    {
        Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_RealTimeClock_Element(1);
    }
}


Std_ReturnType MemAbstractMdl_Get_BsConst_RealTimeClock_Element(Arr_u8_48* Ptr)
{
     Std_ReturnType status = E_NOT_OK;
     /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
     (void)Rte_Read_BsConst_RealTimeClock_Element_Value(Ptr);
     if(FALSE != MemAbstractManagement[18].ValidData)
     {
         status = E_OK;
     }
     return (status);
}


void MemAbstractMdl_Set_BsConst_Communication_Element(const Arr_u8_64 *Ptr)
{
    Arr_u8_64 ElementVal = {0U};
    /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
    (void)Rte_Read_BsConst_Communication_Element_Value( (Arr_u8_64*)ElementVal);
    uint8 Status = 0U;
    uint8 SameValuedetected = FALSE;
    Std_ReturnType AllowWrite = E_NOT_OK;
    Memabs_GetMeetModeStatus(&Status);
    SameValuedetected = (uint8)MemLib_MemCmp(Ptr,(Arr_u8_64*)ElementVal,sizeof(Arr_u8_64));
    AllowWrite = MemAbs_AllowWriteRequest(SameValuedetected,MemAbstract_BsConst_Communication_Index_19);
    if((MEMABS_MEET_MODE_INACTIVE == Status) && (FALSE != ProcessRequest))
    {
        if (E_NOT_OK != AllowWrite)
        {
            /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
            (void)Rte_Write_BsConst_Communication_Element_Value(Ptr);
            Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Communication_Element(2);
            if(MemAbstractManagement[MemAbstract_BsConst_Communication_Index_19].WriteState == WRITE_IDLE)
            {
                MemAbstractManagement[MemAbstract_BsConst_Communication_Index_19].WriteState = WRITE_REQUESTED;
            }
            else if(MemAbstractManagement[MemAbstract_BsConst_Communication_Index_19].WriteState == WRITE_PROGRESS)
            {
                MemAbstractManagement[MemAbstract_BsConst_Communication_Index_19].WriteState = WRITE_PENDING;
            }
            else
            {
                /*Do nothing*/
            }
        }
    }
    else
    {
        Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Communication_Element(1);
    }
}


Std_ReturnType MemAbstractMdl_Get_BsConst_Communication_Element(Arr_u8_64* Ptr)
{
     Std_ReturnType status = E_NOT_OK;
     /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
     (void)Rte_Read_BsConst_Communication_Element_Value(Ptr);
     if(FALSE != MemAbstractManagement[19].ValidData)
     {
         status = E_OK;
     }
     return (status);
}


void MemAbstractMdl_Set_BsConst_Power_Element(const Arr_u8_32 *Ptr)
{
    Arr_u8_32 ElementVal = {0U};
    /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
    (void)Rte_Read_BsConst_Power_Element_Value( (Arr_u8_32*)ElementVal);
    uint8 Status = 0U;
    uint8 SameValuedetected = FALSE;
    Std_ReturnType AllowWrite = E_NOT_OK;
    Memabs_GetMeetModeStatus(&Status);
    SameValuedetected = (uint8)MemLib_MemCmp(Ptr,(Arr_u8_32*)ElementVal,sizeof(Arr_u8_32));
    AllowWrite = MemAbs_AllowWriteRequest(SameValuedetected,MemAbstract_BsConst_Power_Index_20);
    if((MEMABS_MEET_MODE_INACTIVE == Status) && (FALSE != ProcessRequest))
    {
        if (E_NOT_OK != AllowWrite)
        {
            /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
            (void)Rte_Write_BsConst_Power_Element_Value(Ptr);
            Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Power_Element(2);
            if(MemAbstractManagement[MemAbstract_BsConst_Power_Index_20].WriteState == WRITE_IDLE)
            {
                MemAbstractManagement[MemAbstract_BsConst_Power_Index_20].WriteState = WRITE_REQUESTED;
            }
            else if(MemAbstractManagement[MemAbstract_BsConst_Power_Index_20].WriteState == WRITE_PROGRESS)
            {
                MemAbstractManagement[MemAbstract_BsConst_Power_Index_20].WriteState = WRITE_PENDING;
            }
            else
            {
                /*Do nothing*/
            }
        }
    }
    else
    {
        Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Power_Element(1);
    }
}


Std_ReturnType MemAbstractMdl_Get_BsConst_Power_Element(Arr_u8_32* Ptr)
{
     Std_ReturnType status = E_NOT_OK;
     /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
     (void)Rte_Read_BsConst_Power_Element_Value(Ptr);
     if(FALSE != MemAbstractManagement[20].ValidData)
     {
         status = E_OK;
     }
     return (status);
}


void MemAbstractMdl_Set_BsConst_ServiceReminder_Element(const Arr_u8_48 *Ptr)
{
    Arr_u8_48 ElementVal = {0U};
    /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
    (void)Rte_Read_BsConst_ServiceReminder_Element_Value( (Arr_u8_48*)ElementVal);
    uint8 Status = 0U;
    uint8 SameValuedetected = FALSE;
    Std_ReturnType AllowWrite = E_NOT_OK;
    Memabs_GetMeetModeStatus(&Status);
    SameValuedetected = (uint8)MemLib_MemCmp(Ptr,(Arr_u8_48*)ElementVal,sizeof(Arr_u8_48));
    AllowWrite = MemAbs_AllowWriteRequest(SameValuedetected,MemAbstract_BsConst_ServiceReminder_Index_21);
    if((MEMABS_MEET_MODE_INACTIVE == Status) && (FALSE != ProcessRequest))
    {
        if (E_NOT_OK != AllowWrite)
        {
            /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
            (void)Rte_Write_BsConst_ServiceReminder_Element_Value(Ptr);
            Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_ServiceReminder_Element(2);
            if(MemAbstractManagement[MemAbstract_BsConst_ServiceReminder_Index_21].WriteState == WRITE_IDLE)
            {
                MemAbstractManagement[MemAbstract_BsConst_ServiceReminder_Index_21].WriteState = WRITE_REQUESTED;
            }
            else if(MemAbstractManagement[MemAbstract_BsConst_ServiceReminder_Index_21].WriteState == WRITE_PROGRESS)
            {
                MemAbstractManagement[MemAbstract_BsConst_ServiceReminder_Index_21].WriteState = WRITE_PENDING;
            }
            else
            {
                /*Do nothing*/
            }
        }
    }
    else
    {
        Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_ServiceReminder_Element(1);
    }
}


Std_ReturnType MemAbstractMdl_Get_BsConst_ServiceReminder_Element(Arr_u8_48* Ptr)
{
     Std_ReturnType status = E_NOT_OK;
     /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
     (void)Rte_Read_BsConst_ServiceReminder_Element_Value(Ptr);
     if(FALSE != MemAbstractManagement[21].ValidData)
     {
         status = E_OK;
     }
     return (status);
}


void MemAbstractMdl_Set_BsConst_EngOffTimer_Element(const Arr_u8_32 *Ptr)
{
    Arr_u8_32 ElementVal = {0U};
    /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
    (void)Rte_Read_BsConst_EngOffTimer_Element_Value( (Arr_u8_32*)ElementVal);
    uint8 Status = 0U;
    uint8 SameValuedetected = FALSE;
    Std_ReturnType AllowWrite = E_NOT_OK;
    Memabs_GetMeetModeStatus(&Status);
    SameValuedetected = (uint8)MemLib_MemCmp(Ptr,(Arr_u8_32*)ElementVal,sizeof(Arr_u8_32));
    AllowWrite = MemAbs_AllowWriteRequest(SameValuedetected,MemAbstract_BsConst_EngOffTimer_Index_22);
    if((MEMABS_MEET_MODE_INACTIVE == Status) && (FALSE != ProcessRequest))
    {
        if (E_NOT_OK != AllowWrite)
        {
            /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
            (void)Rte_Write_BsConst_EngOffTimer_Element_Value(Ptr);
            Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_EngOffTimer_Element(2);
            if(MemAbstractManagement[MemAbstract_BsConst_EngOffTimer_Index_22].WriteState == WRITE_IDLE)
            {
                MemAbstractManagement[MemAbstract_BsConst_EngOffTimer_Index_22].WriteState = WRITE_REQUESTED;
            }
            else if(MemAbstractManagement[MemAbstract_BsConst_EngOffTimer_Index_22].WriteState == WRITE_PROGRESS)
            {
                MemAbstractManagement[MemAbstract_BsConst_EngOffTimer_Index_22].WriteState = WRITE_PENDING;
            }
            else
            {
                /*Do nothing*/
            }
        }
    }
    else
    {
        Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_EngOffTimer_Element(1);
    }
}


Std_ReturnType MemAbstractMdl_Get_BsConst_EngOffTimer_Element(Arr_u8_32* Ptr)
{
     Std_ReturnType status = E_NOT_OK;
     /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
     (void)Rte_Read_BsConst_EngOffTimer_Element_Value(Ptr);
     if(FALSE != MemAbstractManagement[22].ValidData)
     {
         status = E_OK;
     }
     return (status);
}


void MemAbstractMdl_Set_BsFuSa_Warning_Element(const Arr_u8_32 *Ptr)
{
    Arr_u8_32 ElementVal = {0U};
    /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
    (void)Rte_Read_BsFuSa_Warning_Element_Value( (Arr_u8_32*)ElementVal);
    uint8 Status = 0U;
    uint8 SameValuedetected = FALSE;
    Std_ReturnType AllowWrite = E_NOT_OK;
    Memabs_GetMeetModeStatus(&Status);
    SameValuedetected = (uint8)MemLib_MemCmp(Ptr,(Arr_u8_32*)ElementVal,sizeof(Arr_u8_32));
    AllowWrite = MemAbs_AllowWriteRequest(SameValuedetected,MemAbstract_BsFuSa_Warning_Index_23);
    if((MEMABS_MEET_MODE_INACTIVE == Status) && (FALSE != ProcessRequest))
    {
        if (E_NOT_OK != AllowWrite)
        {
            /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
            (void)Rte_Write_BsFuSa_Warning_Element_Value(Ptr);
            Rte_Write_pp_SR_JobStatus_JobStatus_BsFuSa_Warning_Element(2);
            if(MemAbstractManagement[MemAbstract_BsFuSa_Warning_Index_23].WriteState == WRITE_IDLE)
            {
                MemAbstractManagement[MemAbstract_BsFuSa_Warning_Index_23].WriteState = WRITE_REQUESTED;
            }
            else if(MemAbstractManagement[MemAbstract_BsFuSa_Warning_Index_23].WriteState == WRITE_PROGRESS)
            {
                MemAbstractManagement[MemAbstract_BsFuSa_Warning_Index_23].WriteState = WRITE_PENDING;
            }
            else
            {
                /*Do nothing*/
            }
        }
    }
    else
    {
        Rte_Write_pp_SR_JobStatus_JobStatus_BsFuSa_Warning_Element(1);
    }
}


Std_ReturnType MemAbstractMdl_Get_BsFuSa_Warning_Element(Arr_u8_32* Ptr)
{
     Std_ReturnType status = E_NOT_OK;
     /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
     (void)Rte_Read_BsFuSa_Warning_Element_Value(Ptr);
     if(FALSE != MemAbstractManagement[23].ValidData)
     {
         status = E_OK;
     }
     return (status);
}


void MemAbstractMdl_Set_BsFuSa_Power_Element(const Arr_u8_48 *Ptr)
{
    Arr_u8_48 ElementVal = {0U};
    /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
    (void)Rte_Read_BsFuSa_Power_Element_Value( (Arr_u8_48*)ElementVal);
    uint8 Status = 0U;
    uint8 SameValuedetected = FALSE;
    Std_ReturnType AllowWrite = E_NOT_OK;
    Memabs_GetMeetModeStatus(&Status);
    SameValuedetected = (uint8)MemLib_MemCmp(Ptr,(Arr_u8_48*)ElementVal,sizeof(Arr_u8_48));
    AllowWrite = MemAbs_AllowWriteRequest(SameValuedetected,MemAbstract_BsFuSa_Power_Index_24);
    if((MEMABS_MEET_MODE_INACTIVE == Status) && (FALSE != ProcessRequest))
    {
        if (E_NOT_OK != AllowWrite)
        {
            /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
            (void)Rte_Write_BsFuSa_Power_Element_Value(Ptr);
            Rte_Write_pp_SR_JobStatus_JobStatus_BsFuSa_Power_Element(2);
            if(MemAbstractManagement[MemAbstract_BsFuSa_Power_Index_24].WriteState == WRITE_IDLE)
            {
                MemAbstractManagement[MemAbstract_BsFuSa_Power_Index_24].WriteState = WRITE_REQUESTED;
            }
            else if(MemAbstractManagement[MemAbstract_BsFuSa_Power_Index_24].WriteState == WRITE_PROGRESS)
            {
                MemAbstractManagement[MemAbstract_BsFuSa_Power_Index_24].WriteState = WRITE_PENDING;
            }
            else
            {
                /*Do nothing*/
            }
        }
    }
    else
    {
        Rte_Write_pp_SR_JobStatus_JobStatus_BsFuSa_Power_Element(1);
    }
}


Std_ReturnType MemAbstractMdl_Get_BsFuSa_Power_Element(Arr_u8_48* Ptr)
{
     Std_ReturnType status = E_NOT_OK;
     /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
     (void)Rte_Read_BsFuSa_Power_Element_Value(Ptr);
     if(FALSE != MemAbstractManagement[24].ValidData)
     {
         status = E_OK;
     }
     return (status);
}


void MemAbstractMdl_Set_BsFuSa_Display_Element(const Arr_u8_64 *Ptr)
{
    Arr_u8_64 ElementVal = {0U};
    /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
    (void)Rte_Read_BsFuSa_Display_Element_Value( (Arr_u8_64*)ElementVal);
    uint8 Status = 0U;
    uint8 SameValuedetected = FALSE;
    Std_ReturnType AllowWrite = E_NOT_OK;
    Memabs_GetMeetModeStatus(&Status);
    SameValuedetected = (uint8)MemLib_MemCmp(Ptr,(Arr_u8_64*)ElementVal,sizeof(Arr_u8_64));
    AllowWrite = MemAbs_AllowWriteRequest(SameValuedetected,MemAbstract_BsFuSa_Display_Index_25);
    if((MEMABS_MEET_MODE_INACTIVE == Status) && (FALSE != ProcessRequest))
    {
        if (E_NOT_OK != AllowWrite)
        {
            /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
            (void)Rte_Write_BsFuSa_Display_Element_Value(Ptr);
            Rte_Write_pp_SR_JobStatus_JobStatus_BsFuSa_Display_Element(2);
            if(MemAbstractManagement[MemAbstract_BsFuSa_Display_Index_25].WriteState == WRITE_IDLE)
            {
                MemAbstractManagement[MemAbstract_BsFuSa_Display_Index_25].WriteState = WRITE_REQUESTED;
            }
            else if(MemAbstractManagement[MemAbstract_BsFuSa_Display_Index_25].WriteState == WRITE_PROGRESS)
            {
                MemAbstractManagement[MemAbstract_BsFuSa_Display_Index_25].WriteState = WRITE_PENDING;
            }
            else
            {
                /*Do nothing*/
            }
        }
    }
    else
    {
        Rte_Write_pp_SR_JobStatus_JobStatus_BsFuSa_Display_Element(1);
    }
}


Std_ReturnType MemAbstractMdl_Get_BsFuSa_Display_Element(Arr_u8_64* Ptr)
{
     Std_ReturnType status = E_NOT_OK;
     /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
     (void)Rte_Read_BsFuSa_Display_Element_Value(Ptr);
     if(FALSE != MemAbstractManagement[25].ValidData)
     {
         status = E_OK;
     }
     return (status);
}


void MemAbstractMdl_Set_BsFuSa_Audio_Element(const Arr_u8_32 *Ptr)
{
    Arr_u8_32 ElementVal = {0U};
    /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
    (void)Rte_Read_BsFuSa_Audio_Element_Value( (Arr_u8_32*)ElementVal);
    uint8 Status = 0U;
    uint8 SameValuedetected = FALSE;
    Std_ReturnType AllowWrite = E_NOT_OK;
    Memabs_GetMeetModeStatus(&Status);
    SameValuedetected = (uint8)MemLib_MemCmp(Ptr,(Arr_u8_32*)ElementVal,sizeof(Arr_u8_32));
    AllowWrite = MemAbs_AllowWriteRequest(SameValuedetected,MemAbstract_BsFuSa_Audio_Index_26);
    if((MEMABS_MEET_MODE_INACTIVE == Status) && (FALSE != ProcessRequest))
    {
        if (E_NOT_OK != AllowWrite)
        {
            /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
            (void)Rte_Write_BsFuSa_Audio_Element_Value(Ptr);
            Rte_Write_pp_SR_JobStatus_JobStatus_BsFuSa_Audio_Element(2);
            if(MemAbstractManagement[MemAbstract_BsFuSa_Audio_Index_26].WriteState == WRITE_IDLE)
            {
                MemAbstractManagement[MemAbstract_BsFuSa_Audio_Index_26].WriteState = WRITE_REQUESTED;
            }
            else if(MemAbstractManagement[MemAbstract_BsFuSa_Audio_Index_26].WriteState == WRITE_PROGRESS)
            {
                MemAbstractManagement[MemAbstract_BsFuSa_Audio_Index_26].WriteState = WRITE_PENDING;
            }
            else
            {
                /*Do nothing*/
            }
        }
    }
    else
    {
        Rte_Write_pp_SR_JobStatus_JobStatus_BsFuSa_Audio_Element(1);
    }
}


Std_ReturnType MemAbstractMdl_Get_BsFuSa_Audio_Element(Arr_u8_32* Ptr)
{
     Std_ReturnType status = E_NOT_OK;
     /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
     (void)Rte_Read_BsFuSa_Audio_Element_Value(Ptr);
     if(FALSE != MemAbstractManagement[26].ValidData)
     {
         status = E_OK;
     }
     return (status);
}


void MemAbstractMdl_Set_BsFuSa_Communication_Element(const Arr_u8_16 *Ptr)
{
    Arr_u8_16 ElementVal = {0U};
    /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
    (void)Rte_Read_BsFuSa_Communication_Element_Value( (Arr_u8_16*)ElementVal);
    uint8 Status = 0U;
    uint8 SameValuedetected = FALSE;
    Std_ReturnType AllowWrite = E_NOT_OK;
    Memabs_GetMeetModeStatus(&Status);
    SameValuedetected = (uint8)MemLib_MemCmp(Ptr,(Arr_u8_16*)ElementVal,sizeof(Arr_u8_16));
    AllowWrite = MemAbs_AllowWriteRequest(SameValuedetected,MemAbstract_BsFuSa_Communication_Index_27);
    if((MEMABS_MEET_MODE_INACTIVE == Status) && (FALSE != ProcessRequest))
    {
        if (E_NOT_OK != AllowWrite)
        {
            /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
            (void)Rte_Write_BsFuSa_Communication_Element_Value(Ptr);
            Rte_Write_pp_SR_JobStatus_JobStatus_BsFuSa_Communication_Element(2);
            if(MemAbstractManagement[MemAbstract_BsFuSa_Communication_Index_27].WriteState == WRITE_IDLE)
            {
                MemAbstractManagement[MemAbstract_BsFuSa_Communication_Index_27].WriteState = WRITE_REQUESTED;
            }
            else if(MemAbstractManagement[MemAbstract_BsFuSa_Communication_Index_27].WriteState == WRITE_PROGRESS)
            {
                MemAbstractManagement[MemAbstract_BsFuSa_Communication_Index_27].WriteState = WRITE_PENDING;
            }
            else
            {
                /*Do nothing*/
            }
        }
    }
    else
    {
        Rte_Write_pp_SR_JobStatus_JobStatus_BsFuSa_Communication_Element(1);
    }
}


Std_ReturnType MemAbstractMdl_Get_BsFuSa_Communication_Element(Arr_u8_16* Ptr)
{
     Std_ReturnType status = E_NOT_OK;
     /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
     (void)Rte_Read_BsFuSa_Communication_Element_Value(Ptr);
     if(FALSE != MemAbstractManagement[27].ValidData)
     {
         status = E_OK;
     }
     return (status);
}


void MemAbstractMdl_Set_BsFusa_Fota_Element(const Arr_u8_32 *Ptr)
{
    Arr_u8_32 ElementVal = {0U};
    /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
    (void)Rte_Read_BsFusa_Fota_Element_Value( (Arr_u8_32*)ElementVal);
    uint8 Status = 0U;
    uint8 SameValuedetected = FALSE;
    Std_ReturnType AllowWrite = E_NOT_OK;
    Memabs_GetMeetModeStatus(&Status);
    SameValuedetected = (uint8)MemLib_MemCmp(Ptr,(Arr_u8_32*)ElementVal,sizeof(Arr_u8_32));
    AllowWrite = MemAbs_AllowWriteRequest(SameValuedetected,MemAbstract_BsFusa_Fota_Index_28);
    if((MEMABS_MEET_MODE_INACTIVE == Status) && (FALSE != ProcessRequest))
    {
        if (E_NOT_OK != AllowWrite)
        {
            /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
            (void)Rte_Write_BsFusa_Fota_Element_Value(Ptr);
            Rte_Write_pp_SR_JobStatus_JobStatus_BsFusa_Fota_Element(2);
            if(MemAbstractManagement[MemAbstract_BsFusa_Fota_Index_28].WriteState == WRITE_IDLE)
            {
                MemAbstractManagement[MemAbstract_BsFusa_Fota_Index_28].WriteState = WRITE_REQUESTED;
            }
            else if(MemAbstractManagement[MemAbstract_BsFusa_Fota_Index_28].WriteState == WRITE_PROGRESS)
            {
                MemAbstractManagement[MemAbstract_BsFusa_Fota_Index_28].WriteState = WRITE_PENDING;
            }
            else
            {
                /*Do nothing*/
            }
        }
    }
    else
    {
        Rte_Write_pp_SR_JobStatus_JobStatus_BsFusa_Fota_Element(1);
    }
}


Std_ReturnType MemAbstractMdl_Get_BsFusa_Fota_Element(Arr_u8_32* Ptr)
{
     Std_ReturnType status = E_NOT_OK;
     /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
     (void)Rte_Read_BsFusa_Fota_Element_Value(Ptr);
     if(FALSE != MemAbstractManagement[28].ValidData)
     {
         status = E_OK;
     }
     return (status);
}


void MemAbstractMdl_Set_BsFuSa_Config_Element(const Arr_u8_16 *Ptr)
{
    Arr_u8_16 ElementVal = {0U};
    /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
    (void)Rte_Read_BsFuSa_Config_Element_Value( (Arr_u8_16*)ElementVal);
    uint8 Status = 0U;
    uint8 SameValuedetected = FALSE;
    Std_ReturnType AllowWrite = E_NOT_OK;
    Memabs_GetMeetModeStatus(&Status);
    SameValuedetected = (uint8)MemLib_MemCmp(Ptr,(Arr_u8_16*)ElementVal,sizeof(Arr_u8_16));
    AllowWrite = MemAbs_AllowWriteRequest(SameValuedetected,MemAbstract_BsFuSa_Config_Index_29);
    if((MEMABS_MEET_MODE_INACTIVE == Status) && (FALSE != ProcessRequest))
    {
        if (E_NOT_OK != AllowWrite)
        {
            /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
            (void)Rte_Write_BsFuSa_Config_Element_Value(Ptr);
            Rte_Write_pp_SR_JobStatus_JobStatus_BsFuSa_Config_Element(2);
            if(MemAbstractManagement[MemAbstract_BsFuSa_Config_Index_29].WriteState == WRITE_IDLE)
            {
                MemAbstractManagement[MemAbstract_BsFuSa_Config_Index_29].WriteState = WRITE_REQUESTED;
            }
            else if(MemAbstractManagement[MemAbstract_BsFuSa_Config_Index_29].WriteState == WRITE_PROGRESS)
            {
                MemAbstractManagement[MemAbstract_BsFuSa_Config_Index_29].WriteState = WRITE_PENDING;
            }
            else
            {
                /*Do nothing*/
            }
        }
    }
    else
    {
        Rte_Write_pp_SR_JobStatus_JobStatus_BsFuSa_Config_Element(1);
    }
}


Std_ReturnType MemAbstractMdl_Get_BsFuSa_Config_Element(Arr_u8_16* Ptr)
{
     Std_ReturnType status = E_NOT_OK;
     /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
     (void)Rte_Read_BsFuSa_Config_Element_Value(Ptr);
     if(FALSE != MemAbstractManagement[29].ValidData)
     {
         status = E_OK;
     }
     return (status);
}


void MemAbstractMdl_Set_BsCys_Certicificate_Element(const Arr_u8_64 *Ptr)
{
    Arr_u8_64 ElementVal = {0U};
    /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
    (void)Rte_Read_BsCys_Certicificate_Element_Value( (Arr_u8_64*)ElementVal);
    uint8 Status = 0U;
    uint8 SameValuedetected = FALSE;
    Std_ReturnType AllowWrite = E_NOT_OK;
    Memabs_GetMeetModeStatus(&Status);
    SameValuedetected = (uint8)MemLib_MemCmp(Ptr,(Arr_u8_64*)ElementVal,sizeof(Arr_u8_64));
    AllowWrite = MemAbs_AllowWriteRequest(SameValuedetected,MemAbstract_BsCys_Certicificate_Index_30);
    if((MEMABS_MEET_MODE_INACTIVE == Status) && (FALSE != ProcessRequest))
    {
        if (E_NOT_OK != AllowWrite)
        {
            /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
            (void)Rte_Write_BsCys_Certicificate_Element_Value(Ptr);
            Rte_Write_pp_SR_JobStatus_JobStatus_BsCys_Certicificate_Element(2);
            if(MemAbstractManagement[MemAbstract_BsCys_Certicificate_Index_30].WriteState == WRITE_IDLE)
            {
                MemAbstractManagement[MemAbstract_BsCys_Certicificate_Index_30].WriteState = WRITE_REQUESTED;
            }
            else if(MemAbstractManagement[MemAbstract_BsCys_Certicificate_Index_30].WriteState == WRITE_PROGRESS)
            {
                MemAbstractManagement[MemAbstract_BsCys_Certicificate_Index_30].WriteState = WRITE_PENDING;
            }
            else
            {
                /*Do nothing*/
            }
        }
    }
    else
    {
        Rte_Write_pp_SR_JobStatus_JobStatus_BsCys_Certicificate_Element(1);
    }
}


Std_ReturnType MemAbstractMdl_Get_BsCys_Certicificate_Element(Arr_u8_64* Ptr)
{
     Std_ReturnType status = E_NOT_OK;
     /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
     (void)Rte_Read_BsCys_Certicificate_Element_Value(Ptr);
     if(FALSE != MemAbstractManagement[30].ValidData)
     {
         status = E_OK;
     }
     return (status);
}


void MemAbstractMdl_Set_RefCys_Certicificate_Element(const Arr_u8_64 *Ptr)
{
    Arr_u8_64 ElementVal = {0U};
    /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
    (void)Rte_Read_RefCys_Certicificate_Element_Value( (Arr_u8_64*)ElementVal);
    uint8 Status = 0U;
    uint8 SameValuedetected = FALSE;
    Std_ReturnType AllowWrite = E_NOT_OK;
    Memabs_GetMeetModeStatus(&Status);
    SameValuedetected = (uint8)MemLib_MemCmp(Ptr,(Arr_u8_64*)ElementVal,sizeof(Arr_u8_64));
    AllowWrite = MemAbs_AllowWriteRequest(SameValuedetected,MemAbstract_RefCys_Certicificate_Index_31);
    if((MEMABS_MEET_MODE_INACTIVE == Status) && (FALSE != ProcessRequest))
    {
        if (E_NOT_OK != AllowWrite)
        {
            /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
            (void)Rte_Write_RefCys_Certicificate_Element_Value(Ptr);
            Rte_Write_pp_SR_JobStatus_JobStatus_RefCys_Certicificate_Element(2);
            if(MemAbstractManagement[MemAbstract_RefCys_Certicificate_Index_31].WriteState == WRITE_IDLE)
            {
                MemAbstractManagement[MemAbstract_RefCys_Certicificate_Index_31].WriteState = WRITE_REQUESTED;
            }
            else if(MemAbstractManagement[MemAbstract_RefCys_Certicificate_Index_31].WriteState == WRITE_PROGRESS)
            {
                MemAbstractManagement[MemAbstract_RefCys_Certicificate_Index_31].WriteState = WRITE_PENDING;
            }
            else
            {
                /*Do nothing*/
            }
        }
    }
    else
    {
        Rte_Write_pp_SR_JobStatus_JobStatus_RefCys_Certicificate_Element(1);
    }
}


Std_ReturnType MemAbstractMdl_Get_RefCys_Certicificate_Element(Arr_u8_64* Ptr)
{
     Std_ReturnType status = E_NOT_OK;
     /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
     (void)Rte_Read_RefCys_Certicificate_Element_Value(Ptr);
     if(FALSE != MemAbstractManagement[31].ValidData)
     {
         status = E_OK;
     }
     return (status);
}


void MemAbstractMdl_Set_RefCys_Certicificate1_Element(const Arr_u8_64 *Ptr)
{
    Arr_u8_64 ElementVal = {0U};
    /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
    (void)Rte_Read_RefCys_Certicificate1_Element_Value( (Arr_u8_64*)ElementVal);
    uint8 Status = 0U;
    uint8 SameValuedetected = FALSE;
    Std_ReturnType AllowWrite = E_NOT_OK;
    Memabs_GetMeetModeStatus(&Status);
    SameValuedetected = (uint8)MemLib_MemCmp(Ptr,(Arr_u8_64*)ElementVal,sizeof(Arr_u8_64));
    AllowWrite = MemAbs_AllowWriteRequest(SameValuedetected,MemAbstract_RefCys_Certicificate1_Index_32);
    if((MEMABS_MEET_MODE_INACTIVE == Status) && (FALSE != ProcessRequest))
    {
        if (E_NOT_OK != AllowWrite)
        {
            /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
            (void)Rte_Write_RefCys_Certicificate1_Element_Value(Ptr);
            Rte_Write_pp_SR_JobStatus_JobStatus_RefCys_Certicificate1_Element(2);
            if(MemAbstractManagement[MemAbstract_RefCys_Certicificate1_Index_32].WriteState == WRITE_IDLE)
            {
                MemAbstractManagement[MemAbstract_RefCys_Certicificate1_Index_32].WriteState = WRITE_REQUESTED;
            }
            else if(MemAbstractManagement[MemAbstract_RefCys_Certicificate1_Index_32].WriteState == WRITE_PROGRESS)
            {
                MemAbstractManagement[MemAbstract_RefCys_Certicificate1_Index_32].WriteState = WRITE_PENDING;
            }
            else
            {
                /*Do nothing*/
            }
        }
    }
    else
    {
        Rte_Write_pp_SR_JobStatus_JobStatus_RefCys_Certicificate1_Element(1);
    }
}


Std_ReturnType MemAbstractMdl_Get_RefCys_Certicificate1_Element(Arr_u8_64* Ptr)
{
     Std_ReturnType status = E_NOT_OK;
     /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
     (void)Rte_Read_RefCys_Certicificate1_Element_Value(Ptr);
     if(FALSE != MemAbstractManagement[32].ValidData)
     {
         status = E_OK;
     }
     return (status);
}


void MemAbstractMdl_Set_BsRt_Odometer_Element(const Arr_u8_128 *Ptr)
{
    Arr_u8_128 ElementVal = {0U};
    /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
    (void)Rte_Read_BsRt_Odometer_Element_Value( (Arr_u8_128*)ElementVal);
    uint8 Status = 0U;
    uint8 SameValuedetected = FALSE;
    Std_ReturnType AllowWrite = E_NOT_OK;
    Memabs_GetMeetModeStatus(&Status);
    SameValuedetected = (uint8)MemLib_MemCmp(Ptr,(Arr_u8_128*)ElementVal,sizeof(Arr_u8_128));
    AllowWrite = MemAbs_AllowWriteRequest(SameValuedetected,MemAbstract_BsRt_Odometer_Index_33);
    if((MEMABS_MEET_MODE_INACTIVE == Status) && (FALSE != ProcessRequest))
    {
        if (E_NOT_OK != AllowWrite)
        {
            /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
            (void)Rte_Write_BsRt_Odometer_Element_Value(Ptr);
            Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_Odometer_Element(2);
            if(MemAbstractManagement[MemAbstract_BsRt_Odometer_Index_33].WriteState == WRITE_IDLE)
            {
                MemAbstractManagement[MemAbstract_BsRt_Odometer_Index_33].WriteState = WRITE_REQUESTED;
            }
            else if(MemAbstractManagement[MemAbstract_BsRt_Odometer_Index_33].WriteState == WRITE_PROGRESS)
            {
                MemAbstractManagement[MemAbstract_BsRt_Odometer_Index_33].WriteState = WRITE_PENDING;
            }
            else
            {
                /*Do nothing*/
            }
        }
    }
    else
    {
        Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_Odometer_Element(1);
    }
}


Std_ReturnType MemAbstractMdl_Get_BsRt_Odometer_Element(Arr_u8_128* Ptr)
{
     Std_ReturnType status = E_NOT_OK;
     /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
     (void)Rte_Read_BsRt_Odometer_Element_Value(Ptr);
     if(FALSE != MemAbstractManagement[33].ValidData)
     {
         status = E_OK;
     }
     return (status);
}


void MemAbstractMdl_Set_BsRt_SpeedoGauge_Element(const Arr_u8_8 *Ptr)
{
    Arr_u8_8 ElementVal = {0U};
    /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
    (void)Rte_Read_BsRt_SpeedoGauge_Element_Value( (Arr_u8_8*)ElementVal);
    uint8 Status = 0U;
    uint8 SameValuedetected = FALSE;
    Std_ReturnType AllowWrite = E_NOT_OK;
    Memabs_GetMeetModeStatus(&Status);
    SameValuedetected = (uint8)MemLib_MemCmp(Ptr,(Arr_u8_8*)ElementVal,sizeof(Arr_u8_8));
    AllowWrite = MemAbs_AllowWriteRequest(SameValuedetected,MemAbstract_BsRt_SpeedoGauge_Index_34);
    if((MEMABS_MEET_MODE_INACTIVE == Status) && (FALSE != ProcessRequest))
    {
        if (E_NOT_OK != AllowWrite)
        {
            /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
            (void)Rte_Write_BsRt_SpeedoGauge_Element_Value(Ptr);
            Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_SpeedoGauge_Element(2);
            if(MemAbstractManagement[MemAbstract_BsRt_SpeedoGauge_Index_34].WriteState == WRITE_IDLE)
            {
                MemAbstractManagement[MemAbstract_BsRt_SpeedoGauge_Index_34].WriteState = WRITE_REQUESTED;
            }
            else if(MemAbstractManagement[MemAbstract_BsRt_SpeedoGauge_Index_34].WriteState == WRITE_PROGRESS)
            {
                MemAbstractManagement[MemAbstract_BsRt_SpeedoGauge_Index_34].WriteState = WRITE_PENDING;
            }
            else
            {
                /*Do nothing*/
            }
        }
    }
    else
    {
        Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_SpeedoGauge_Element(1);
    }
}


Std_ReturnType MemAbstractMdl_Get_BsRt_SpeedoGauge_Element(Arr_u8_8* Ptr)
{
     Std_ReturnType status = E_NOT_OK;
     /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
     (void)Rte_Read_BsRt_SpeedoGauge_Element_Value(Ptr);
     if(FALSE != MemAbstractManagement[34].ValidData)
     {
         status = E_OK;
     }
     return (status);
}


void MemAbstractMdl_Set_BsRt_TachoGauge_Element(const Arr_u8_16 *Ptr)
{
    Arr_u8_16 ElementVal = {0U};
    /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
    (void)Rte_Read_BsRt_TachoGauge_Element_Value( (Arr_u8_16*)ElementVal);
    uint8 Status = 0U;
    uint8 SameValuedetected = FALSE;
    Std_ReturnType AllowWrite = E_NOT_OK;
    Memabs_GetMeetModeStatus(&Status);
    SameValuedetected = (uint8)MemLib_MemCmp(Ptr,(Arr_u8_16*)ElementVal,sizeof(Arr_u8_16));
    AllowWrite = MemAbs_AllowWriteRequest(SameValuedetected,MemAbstract_BsRt_TachoGauge_Index_35);
    if((MEMABS_MEET_MODE_INACTIVE == Status) && (FALSE != ProcessRequest))
    {
        if (E_NOT_OK != AllowWrite)
        {
            /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
            (void)Rte_Write_BsRt_TachoGauge_Element_Value(Ptr);
            Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_TachoGauge_Element(2);
            if(MemAbstractManagement[MemAbstract_BsRt_TachoGauge_Index_35].WriteState == WRITE_IDLE)
            {
                MemAbstractManagement[MemAbstract_BsRt_TachoGauge_Index_35].WriteState = WRITE_REQUESTED;
            }
            else if(MemAbstractManagement[MemAbstract_BsRt_TachoGauge_Index_35].WriteState == WRITE_PROGRESS)
            {
                MemAbstractManagement[MemAbstract_BsRt_TachoGauge_Index_35].WriteState = WRITE_PENDING;
            }
            else
            {
                /*Do nothing*/
            }
        }
    }
    else
    {
        Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_TachoGauge_Element(1);
    }
}


Std_ReturnType MemAbstractMdl_Get_BsRt_TachoGauge_Element(Arr_u8_16* Ptr)
{
     Std_ReturnType status = E_NOT_OK;
     /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
     (void)Rte_Read_BsRt_TachoGauge_Element_Value(Ptr);
     if(FALSE != MemAbstractManagement[35].ValidData)
     {
         status = E_OK;
     }
     return (status);
}


void MemAbstractMdl_Set_BsRt_FuelGauge_Element(const Arr_u8_32 *Ptr)
{
    Arr_u8_32 ElementVal = {0U};
    /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
    (void)Rte_Read_BsRt_FuelGauge_Element_Value( (Arr_u8_32*)ElementVal);
    uint8 Status = 0U;
    uint8 SameValuedetected = FALSE;
    Std_ReturnType AllowWrite = E_NOT_OK;
    Memabs_GetMeetModeStatus(&Status);
    SameValuedetected = (uint8)MemLib_MemCmp(Ptr,(Arr_u8_32*)ElementVal,sizeof(Arr_u8_32));
    AllowWrite = MemAbs_AllowWriteRequest(SameValuedetected,MemAbstract_BsRt_FuelGauge_Index_36);
    if((MEMABS_MEET_MODE_INACTIVE == Status) && (FALSE != ProcessRequest))
    {
        if (E_NOT_OK != AllowWrite)
        {
            /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
            (void)Rte_Write_BsRt_FuelGauge_Element_Value(Ptr);
            Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_FuelGauge_Element(2);
            if(MemAbstractManagement[MemAbstract_BsRt_FuelGauge_Index_36].WriteState == WRITE_IDLE)
            {
                MemAbstractManagement[MemAbstract_BsRt_FuelGauge_Index_36].WriteState = WRITE_REQUESTED;
            }
            else if(MemAbstractManagement[MemAbstract_BsRt_FuelGauge_Index_36].WriteState == WRITE_PROGRESS)
            {
                MemAbstractManagement[MemAbstract_BsRt_FuelGauge_Index_36].WriteState = WRITE_PENDING;
            }
            else
            {
                /*Do nothing*/
            }
        }
    }
    else
    {
        Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_FuelGauge_Element(1);
    }
}


Std_ReturnType MemAbstractMdl_Get_BsRt_FuelGauge_Element(Arr_u8_32* Ptr)
{
     Std_ReturnType status = E_NOT_OK;
     /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
     (void)Rte_Read_BsRt_FuelGauge_Element_Value(Ptr);
     if(FALSE != MemAbstractManagement[36].ValidData)
     {
         status = E_OK;
     }
     return (status);
}


void MemAbstractMdl_Set_BsRt_TempGauge_Element(const Arr_u8_32 *Ptr)
{
    Arr_u8_32 ElementVal = {0U};
    /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
    (void)Rte_Read_BsRt_TempGauge_Element_Value( (Arr_u8_32*)ElementVal);
    uint8 Status = 0U;
    uint8 SameValuedetected = FALSE;
    Std_ReturnType AllowWrite = E_NOT_OK;
    Memabs_GetMeetModeStatus(&Status);
    SameValuedetected = (uint8)MemLib_MemCmp(Ptr,(Arr_u8_32*)ElementVal,sizeof(Arr_u8_32));
    AllowWrite = MemAbs_AllowWriteRequest(SameValuedetected,MemAbstract_BsRt_TempGauge_Index_37);
    if((MEMABS_MEET_MODE_INACTIVE == Status) && (FALSE != ProcessRequest))
    {
        if (E_NOT_OK != AllowWrite)
        {
            /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
            (void)Rte_Write_BsRt_TempGauge_Element_Value(Ptr);
            Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_TempGauge_Element(2);
            if(MemAbstractManagement[MemAbstract_BsRt_TempGauge_Index_37].WriteState == WRITE_IDLE)
            {
                MemAbstractManagement[MemAbstract_BsRt_TempGauge_Index_37].WriteState = WRITE_REQUESTED;
            }
            else if(MemAbstractManagement[MemAbstract_BsRt_TempGauge_Index_37].WriteState == WRITE_PROGRESS)
            {
                MemAbstractManagement[MemAbstract_BsRt_TempGauge_Index_37].WriteState = WRITE_PENDING;
            }
            else
            {
                /*Do nothing*/
            }
        }
    }
    else
    {
        Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_TempGauge_Element(1);
    }
}


Std_ReturnType MemAbstractMdl_Get_BsRt_TempGauge_Element(Arr_u8_32* Ptr)
{
     Std_ReturnType status = E_NOT_OK;
     /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
     (void)Rte_Read_BsRt_TempGauge_Element_Value(Ptr);
     if(FALSE != MemAbstractManagement[37].ValidData)
     {
         status = E_OK;
     }
     return (status);
}


void MemAbstractMdl_Set_BsRt_PowerGauge_Element(const Arr_u8_32 *Ptr)
{
    Arr_u8_32 ElementVal = {0U};
    /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
    (void)Rte_Read_BsRt_PowerGauge_Element_Value( (Arr_u8_32*)ElementVal);
    uint8 Status = 0U;
    uint8 SameValuedetected = FALSE;
    Std_ReturnType AllowWrite = E_NOT_OK;
    Memabs_GetMeetModeStatus(&Status);
    SameValuedetected = (uint8)MemLib_MemCmp(Ptr,(Arr_u8_32*)ElementVal,sizeof(Arr_u8_32));
    AllowWrite = MemAbs_AllowWriteRequest(SameValuedetected,MemAbstract_BsRt_PowerGauge_Index_38);
    if((MEMABS_MEET_MODE_INACTIVE == Status) && (FALSE != ProcessRequest))
    {
        if (E_NOT_OK != AllowWrite)
        {
            /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
            (void)Rte_Write_BsRt_PowerGauge_Element_Value(Ptr);
            Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_PowerGauge_Element(2);
            if(MemAbstractManagement[MemAbstract_BsRt_PowerGauge_Index_38].WriteState == WRITE_IDLE)
            {
                MemAbstractManagement[MemAbstract_BsRt_PowerGauge_Index_38].WriteState = WRITE_REQUESTED;
            }
            else if(MemAbstractManagement[MemAbstract_BsRt_PowerGauge_Index_38].WriteState == WRITE_PROGRESS)
            {
                MemAbstractManagement[MemAbstract_BsRt_PowerGauge_Index_38].WriteState = WRITE_PENDING;
            }
            else
            {
                /*Do nothing*/
            }
        }
    }
    else
    {
        Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_PowerGauge_Element(1);
    }
}


Std_ReturnType MemAbstractMdl_Get_BsRt_PowerGauge_Element(Arr_u8_32* Ptr)
{
     Std_ReturnType status = E_NOT_OK;
     /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
     (void)Rte_Read_BsRt_PowerGauge_Element_Value(Ptr);
     if(FALSE != MemAbstractManagement[38].ValidData)
     {
         status = E_OK;
     }
     return (status);
}


void MemAbstractMdl_Set_BsRt_OilGauge_Element(const Arr_u8_8 *Ptr)
{
    Arr_u8_8 ElementVal = {0U};
    /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
    (void)Rte_Read_BsRt_OilGauge_Element_Value( (Arr_u8_8*)ElementVal);
    uint8 Status = 0U;
    uint8 SameValuedetected = FALSE;
    Std_ReturnType AllowWrite = E_NOT_OK;
    Memabs_GetMeetModeStatus(&Status);
    SameValuedetected = (uint8)MemLib_MemCmp(Ptr,(Arr_u8_8*)ElementVal,sizeof(Arr_u8_8));
    AllowWrite = MemAbs_AllowWriteRequest(SameValuedetected,MemAbstract_BsRt_OilGauge_Index_39);
    if((MEMABS_MEET_MODE_INACTIVE == Status) && (FALSE != ProcessRequest))
    {
        if (E_NOT_OK != AllowWrite)
        {
            /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
            (void)Rte_Write_BsRt_OilGauge_Element_Value(Ptr);
            Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_OilGauge_Element(2);
            if(MemAbstractManagement[MemAbstract_BsRt_OilGauge_Index_39].WriteState == WRITE_IDLE)
            {
                MemAbstractManagement[MemAbstract_BsRt_OilGauge_Index_39].WriteState = WRITE_REQUESTED;
            }
            else if(MemAbstractManagement[MemAbstract_BsRt_OilGauge_Index_39].WriteState == WRITE_PROGRESS)
            {
                MemAbstractManagement[MemAbstract_BsRt_OilGauge_Index_39].WriteState = WRITE_PENDING;
            }
            else
            {
                /*Do nothing*/
            }
        }
    }
    else
    {
        Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_OilGauge_Element(1);
    }
}


Std_ReturnType MemAbstractMdl_Get_BsRt_OilGauge_Element(Arr_u8_8* Ptr)
{
     Std_ReturnType status = E_NOT_OK;
     /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
     (void)Rte_Read_BsRt_OilGauge_Element_Value(Ptr);
     if(FALSE != MemAbstractManagement[39].ValidData)
     {
         status = E_OK;
     }
     return (status);
}


void MemAbstractMdl_Set_BsRt_TripComputer_Element(const Arr_u8_64 *Ptr)
{
    Arr_u8_64 ElementVal = {0U};
    /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
    (void)Rte_Read_BsRt_TripComputer_Element_Value( (Arr_u8_64*)ElementVal);
    uint8 Status = 0U;
    uint8 SameValuedetected = FALSE;
    Std_ReturnType AllowWrite = E_NOT_OK;
    Memabs_GetMeetModeStatus(&Status);
    SameValuedetected = (uint8)MemLib_MemCmp(Ptr,(Arr_u8_64*)ElementVal,sizeof(Arr_u8_64));
    AllowWrite = MemAbs_AllowWriteRequest(SameValuedetected,MemAbstract_BsRt_TripComputer_Index_40);
    if((MEMABS_MEET_MODE_INACTIVE == Status) && (FALSE != ProcessRequest))
    {
        if (E_NOT_OK != AllowWrite)
        {
            /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
            (void)Rte_Write_BsRt_TripComputer_Element_Value(Ptr);
            Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_TripComputer_Element(2);
            if(MemAbstractManagement[MemAbstract_BsRt_TripComputer_Index_40].WriteState == WRITE_IDLE)
            {
                MemAbstractManagement[MemAbstract_BsRt_TripComputer_Index_40].WriteState = WRITE_REQUESTED;
            }
            else if(MemAbstractManagement[MemAbstract_BsRt_TripComputer_Index_40].WriteState == WRITE_PROGRESS)
            {
                MemAbstractManagement[MemAbstract_BsRt_TripComputer_Index_40].WriteState = WRITE_PENDING;
            }
            else
            {
                /*Do nothing*/
            }
        }
    }
    else
    {
        Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_TripComputer_Element(1);
    }
}


Std_ReturnType MemAbstractMdl_Get_BsRt_TripComputer_Element(Arr_u8_64* Ptr)
{
     Std_ReturnType status = E_NOT_OK;
     /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
     (void)Rte_Read_BsRt_TripComputer_Element_Value(Ptr);
     if(FALSE != MemAbstractManagement[40].ValidData)
     {
         status = E_OK;
     }
     return (status);
}


void MemAbstractMdl_Set_BsRt_Warning_Element(const Arr_u8_32 *Ptr)
{
    Arr_u8_32 ElementVal = {0U};
    /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
    (void)Rte_Read_BsRt_Warning_Element_Value( (Arr_u8_32*)ElementVal);
    uint8 Status = 0U;
    uint8 SameValuedetected = FALSE;
    Std_ReturnType AllowWrite = E_NOT_OK;
    Memabs_GetMeetModeStatus(&Status);
    SameValuedetected = (uint8)MemLib_MemCmp(Ptr,(Arr_u8_32*)ElementVal,sizeof(Arr_u8_32));
    AllowWrite = MemAbs_AllowWriteRequest(SameValuedetected,MemAbstract_BsRt_Warning_Index_41);
    if((MEMABS_MEET_MODE_INACTIVE == Status) && (FALSE != ProcessRequest))
    {
        if (E_NOT_OK != AllowWrite)
        {
            /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
            (void)Rte_Write_BsRt_Warning_Element_Value(Ptr);
            Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_Warning_Element(2);
            if(MemAbstractManagement[MemAbstract_BsRt_Warning_Index_41].WriteState == WRITE_IDLE)
            {
                MemAbstractManagement[MemAbstract_BsRt_Warning_Index_41].WriteState = WRITE_REQUESTED;
            }
            else if(MemAbstractManagement[MemAbstract_BsRt_Warning_Index_41].WriteState == WRITE_PROGRESS)
            {
                MemAbstractManagement[MemAbstract_BsRt_Warning_Index_41].WriteState = WRITE_PENDING;
            }
            else
            {
                /*Do nothing*/
            }
        }
    }
    else
    {
        Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_Warning_Element(1);
    }
}


Std_ReturnType MemAbstractMdl_Get_BsRt_Warning_Element(Arr_u8_32* Ptr)
{
     Std_ReturnType status = E_NOT_OK;
     /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
     (void)Rte_Read_BsRt_Warning_Element_Value(Ptr);
     if(FALSE != MemAbstractManagement[41].ValidData)
     {
         status = E_OK;
     }
     return (status);
}


void MemAbstractMdl_Set_BsRt_RealTimeClock_Element(const Arr_u8_48 *Ptr)
{
    Arr_u8_48 ElementVal = {0U};
    /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
    (void)Rte_Read_BsRt_RealTimeClock_Element_Value( (Arr_u8_48*)ElementVal);
    uint8 Status = 0U;
    uint8 SameValuedetected = FALSE;
    Std_ReturnType AllowWrite = E_NOT_OK;
    Memabs_GetMeetModeStatus(&Status);
    SameValuedetected = (uint8)MemLib_MemCmp(Ptr,(Arr_u8_48*)ElementVal,sizeof(Arr_u8_48));
    AllowWrite = MemAbs_AllowWriteRequest(SameValuedetected,MemAbstract_BsRt_RealTimeClock_Index_42);
    if((MEMABS_MEET_MODE_INACTIVE == Status) && (FALSE != ProcessRequest))
    {
        if (E_NOT_OK != AllowWrite)
        {
            /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
            (void)Rte_Write_BsRt_RealTimeClock_Element_Value(Ptr);
            Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_RealTimeClock_Element(2);
            if(MemAbstractManagement[MemAbstract_BsRt_RealTimeClock_Index_42].WriteState == WRITE_IDLE)
            {
                MemAbstractManagement[MemAbstract_BsRt_RealTimeClock_Index_42].WriteState = WRITE_REQUESTED;
            }
            else if(MemAbstractManagement[MemAbstract_BsRt_RealTimeClock_Index_42].WriteState == WRITE_PROGRESS)
            {
                MemAbstractManagement[MemAbstract_BsRt_RealTimeClock_Index_42].WriteState = WRITE_PENDING;
            }
            else
            {
                /*Do nothing*/
            }
        }
    }
    else
    {
        Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_RealTimeClock_Element(1);
    }
}


Std_ReturnType MemAbstractMdl_Get_BsRt_RealTimeClock_Element(Arr_u8_48* Ptr)
{
     Std_ReturnType status = E_NOT_OK;
     /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
     (void)Rte_Read_BsRt_RealTimeClock_Element_Value(Ptr);
     if(FALSE != MemAbstractManagement[42].ValidData)
     {
         status = E_OK;
     }
     return (status);
}


void MemAbstractMdl_Set_BsRt_Personalization_Element(const Arr_u8_128 *Ptr)
{
    Arr_u8_128 ElementVal = {0U};
    /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
    (void)Rte_Read_BsRt_Personalization_Element_Value( (Arr_u8_128*)ElementVal);
    uint8 Status = 0U;
    uint8 SameValuedetected = FALSE;
    Std_ReturnType AllowWrite = E_NOT_OK;
    Memabs_GetMeetModeStatus(&Status);
    SameValuedetected = (uint8)MemLib_MemCmp(Ptr,(Arr_u8_128*)ElementVal,sizeof(Arr_u8_128));
    AllowWrite = MemAbs_AllowWriteRequest(SameValuedetected,MemAbstract_BsRt_Personalization_Index_43);
    if((MEMABS_MEET_MODE_INACTIVE == Status) && (FALSE != ProcessRequest))
    {
        if (E_NOT_OK != AllowWrite)
        {
            /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
            (void)Rte_Write_BsRt_Personalization_Element_Value(Ptr);
            Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_Personalization_Element(2);
            if(MemAbstractManagement[MemAbstract_BsRt_Personalization_Index_43].WriteState == WRITE_IDLE)
            {
                MemAbstractManagement[MemAbstract_BsRt_Personalization_Index_43].WriteState = WRITE_REQUESTED;
            }
            else if(MemAbstractManagement[MemAbstract_BsRt_Personalization_Index_43].WriteState == WRITE_PROGRESS)
            {
                MemAbstractManagement[MemAbstract_BsRt_Personalization_Index_43].WriteState = WRITE_PENDING;
            }
            else
            {
                /*Do nothing*/
            }
        }
    }
    else
    {
        Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_Personalization_Element(1);
    }
}


Std_ReturnType MemAbstractMdl_Get_BsRt_Personalization_Element(Arr_u8_128* Ptr)
{
     Std_ReturnType status = E_NOT_OK;
     /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
     (void)Rte_Read_BsRt_Personalization_Element_Value(Ptr);
     if(FALSE != MemAbstractManagement[43].ValidData)
     {
         status = E_OK;
     }
     return (status);
}


void MemAbstractMdl_Set_BsRt_Illumination_Element(const Arr_u8_100 *Ptr)
{
    Arr_u8_100 ElementVal = {0U};
    /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
    (void)Rte_Read_BsRt_Illumination_Element_Value( (Arr_u8_100*)ElementVal);
    uint8 Status = 0U;
    uint8 SameValuedetected = FALSE;
    Std_ReturnType AllowWrite = E_NOT_OK;
    Memabs_GetMeetModeStatus(&Status);
    SameValuedetected = (uint8)MemLib_MemCmp(Ptr,(Arr_u8_100*)ElementVal,sizeof(Arr_u8_100));
    AllowWrite = MemAbs_AllowWriteRequest(SameValuedetected,MemAbstract_BsRt_Illumination_Index_44);
    if((MEMABS_MEET_MODE_INACTIVE == Status) && (FALSE != ProcessRequest))
    {
        if (E_NOT_OK != AllowWrite)
        {
            /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
            (void)Rte_Write_BsRt_Illumination_Element_Value(Ptr);
            Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_Illumination_Element(2);
            if(MemAbstractManagement[MemAbstract_BsRt_Illumination_Index_44].WriteState == WRITE_IDLE)
            {
                MemAbstractManagement[MemAbstract_BsRt_Illumination_Index_44].WriteState = WRITE_REQUESTED;
            }
            else if(MemAbstractManagement[MemAbstract_BsRt_Illumination_Index_44].WriteState == WRITE_PROGRESS)
            {
                MemAbstractManagement[MemAbstract_BsRt_Illumination_Index_44].WriteState = WRITE_PENDING;
            }
            else
            {
                /*Do nothing*/
            }
        }
    }
    else
    {
        Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_Illumination_Element(1);
    }
}


Std_ReturnType MemAbstractMdl_Get_BsRt_Illumination_Element(Arr_u8_100* Ptr)
{
     Std_ReturnType status = E_NOT_OK;
     /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
     (void)Rte_Read_BsRt_Illumination_Element_Value(Ptr);
     if(FALSE != MemAbstractManagement[44].ValidData)
     {
         status = E_OK;
     }
     return (status);
}


void MemAbstractMdl_Set_BsRt_CusDlt_Element(const Arr_u8_128 *Ptr)
{
    Arr_u8_128 ElementVal = {0U};
    /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
    (void)Rte_Read_BsRt_CusDlt_Element_Value( (Arr_u8_128*)ElementVal);
    uint8 Status = 0U;
    uint8 SameValuedetected = FALSE;
    Std_ReturnType AllowWrite = E_NOT_OK;
    Memabs_GetMeetModeStatus(&Status);
    SameValuedetected = (uint8)MemLib_MemCmp(Ptr,(Arr_u8_128*)ElementVal,sizeof(Arr_u8_128));
    AllowWrite = MemAbs_AllowWriteRequest(SameValuedetected,MemAbstract_BsRt_CusDlt_Index_45);
    if((MEMABS_MEET_MODE_INACTIVE == Status) && (FALSE != ProcessRequest))
    {
        if (E_NOT_OK != AllowWrite)
        {
            /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
            (void)Rte_Write_BsRt_CusDlt_Element_Value(Ptr);
            Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_CusDlt_Element(2);
            if(MemAbstractManagement[MemAbstract_BsRt_CusDlt_Index_45].WriteState == WRITE_IDLE)
            {
                MemAbstractManagement[MemAbstract_BsRt_CusDlt_Index_45].WriteState = WRITE_REQUESTED;
            }
            else if(MemAbstractManagement[MemAbstract_BsRt_CusDlt_Index_45].WriteState == WRITE_PROGRESS)
            {
                MemAbstractManagement[MemAbstract_BsRt_CusDlt_Index_45].WriteState = WRITE_PENDING;
            }
            else
            {
                /*Do nothing*/
            }
        }
    }
    else
    {
        Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_CusDlt_Element(1);
    }
}


Std_ReturnType MemAbstractMdl_Get_BsRt_CusDlt_Element(Arr_u8_128* Ptr)
{
     Std_ReturnType status = E_NOT_OK;
     /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
     (void)Rte_Read_BsRt_CusDlt_Element_Value(Ptr);
     if(FALSE != MemAbstractManagement[45].ValidData)
     {
         status = E_OK;
     }
     return (status);
}


void MemAbstractMdl_Set_BsReten_Odometer_Element(const Arr_u8_100 *Ptr)
{
    Arr_u8_100 ElementVal = {0U};
    /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
    (void)Rte_Read_BsReten_Odometer_Element_Value( (Arr_u8_100*)ElementVal);
    uint8 Status = 0U;
    uint8 SameValuedetected = FALSE;
    Std_ReturnType AllowWrite = E_NOT_OK;
    Memabs_GetMeetModeStatus(&Status);
    SameValuedetected = (uint8)MemLib_MemCmp(Ptr,(Arr_u8_100*)ElementVal,sizeof(Arr_u8_100));
    AllowWrite = MemAbs_AllowWriteRequest(SameValuedetected,MemAbstract_BsReten_Odometer_Index_46);
    if((MEMABS_MEET_MODE_INACTIVE == Status) && (FALSE != ProcessRequest))
    {
        if (E_NOT_OK != AllowWrite)
        {
            /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
            (void)Rte_Write_BsReten_Odometer_Element_Value(Ptr);
            Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Odometer_Element(2);
            if(MemAbstractManagement[MemAbstract_BsReten_Odometer_Index_46].WriteState == WRITE_IDLE)
            {
                MemAbstractManagement[MemAbstract_BsReten_Odometer_Index_46].WriteState = WRITE_REQUESTED;
            }
            else if(MemAbstractManagement[MemAbstract_BsReten_Odometer_Index_46].WriteState == WRITE_PROGRESS)
            {
                MemAbstractManagement[MemAbstract_BsReten_Odometer_Index_46].WriteState = WRITE_PENDING;
            }
            else
            {
                /*Do nothing*/
            }
        }
    }
    else
    {
        Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Odometer_Element(1);
    }
}


Std_ReturnType MemAbstractMdl_Get_BsReten_Odometer_Element(Arr_u8_100* Ptr)
{
     Std_ReturnType status = E_NOT_OK;
     /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
     (void)Rte_Read_BsReten_Odometer_Element_Value(Ptr);
     if(FALSE != MemAbstractManagement[46].ValidData)
     {
         status = E_OK;
     }
     return (status);
}


void MemAbstractMdl_Set_BsReten_Gauges_Element(const Arr_u8_100 *Ptr)
{
    Arr_u8_100 ElementVal = {0U};
    /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
    (void)Rte_Read_BsReten_Gauges_Element_Value( (Arr_u8_100*)ElementVal);
    uint8 Status = 0U;
    uint8 SameValuedetected = FALSE;
    Std_ReturnType AllowWrite = E_NOT_OK;
    Memabs_GetMeetModeStatus(&Status);
    SameValuedetected = (uint8)MemLib_MemCmp(Ptr,(Arr_u8_100*)ElementVal,sizeof(Arr_u8_100));
    AllowWrite = MemAbs_AllowWriteRequest(SameValuedetected,MemAbstract_BsReten_Gauges_Index_47);
    if((MEMABS_MEET_MODE_INACTIVE == Status) && (FALSE != ProcessRequest))
    {
        if (E_NOT_OK != AllowWrite)
        {
            /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
            (void)Rte_Write_BsReten_Gauges_Element_Value(Ptr);
            Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Gauges_Element(2);
            if(MemAbstractManagement[MemAbstract_BsReten_Gauges_Index_47].WriteState == WRITE_IDLE)
            {
                MemAbstractManagement[MemAbstract_BsReten_Gauges_Index_47].WriteState = WRITE_REQUESTED;
            }
            else if(MemAbstractManagement[MemAbstract_BsReten_Gauges_Index_47].WriteState == WRITE_PROGRESS)
            {
                MemAbstractManagement[MemAbstract_BsReten_Gauges_Index_47].WriteState = WRITE_PENDING;
            }
            else
            {
                /*Do nothing*/
            }
        }
    }
    else
    {
        Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Gauges_Element(1);
    }
}


Std_ReturnType MemAbstractMdl_Get_BsReten_Gauges_Element(Arr_u8_100* Ptr)
{
     Std_ReturnType status = E_NOT_OK;
     /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
     (void)Rte_Read_BsReten_Gauges_Element_Value(Ptr);
     if(FALSE != MemAbstractManagement[47].ValidData)
     {
         status = E_OK;
     }
     return (status);
}


void MemAbstractMdl_Set_BsReten_Tripcomputer_Element(const Arr_u8_100 *Ptr)
{
    Arr_u8_100 ElementVal = {0U};
    /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
    (void)Rte_Read_BsReten_Tripcomputer_Element_Value( (Arr_u8_100*)ElementVal);
    uint8 Status = 0U;
    uint8 SameValuedetected = FALSE;
    Std_ReturnType AllowWrite = E_NOT_OK;
    Memabs_GetMeetModeStatus(&Status);
    SameValuedetected = (uint8)MemLib_MemCmp(Ptr,(Arr_u8_100*)ElementVal,sizeof(Arr_u8_100));
    AllowWrite = MemAbs_AllowWriteRequest(SameValuedetected,MemAbstract_BsReten_Tripcomputer_Index_48);
    if((MEMABS_MEET_MODE_INACTIVE == Status) && (FALSE != ProcessRequest))
    {
        if (E_NOT_OK != AllowWrite)
        {
            /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
            (void)Rte_Write_BsReten_Tripcomputer_Element_Value(Ptr);
            Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Tripcomputer_Element(2);
            if(MemAbstractManagement[MemAbstract_BsReten_Tripcomputer_Index_48].WriteState == WRITE_IDLE)
            {
                MemAbstractManagement[MemAbstract_BsReten_Tripcomputer_Index_48].WriteState = WRITE_REQUESTED;
            }
            else if(MemAbstractManagement[MemAbstract_BsReten_Tripcomputer_Index_48].WriteState == WRITE_PROGRESS)
            {
                MemAbstractManagement[MemAbstract_BsReten_Tripcomputer_Index_48].WriteState = WRITE_PENDING;
            }
            else
            {
                /*Do nothing*/
            }
        }
    }
    else
    {
        Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Tripcomputer_Element(1);
    }
}


Std_ReturnType MemAbstractMdl_Get_BsReten_Tripcomputer_Element(Arr_u8_100* Ptr)
{
     Std_ReturnType status = E_NOT_OK;
     /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
     (void)Rte_Read_BsReten_Tripcomputer_Element_Value(Ptr);
     if(FALSE != MemAbstractManagement[48].ValidData)
     {
         status = E_OK;
     }
     return (status);
}


void MemAbstractMdl_Set_BsReten_Illumination_Element(const Arr_u8_100 *Ptr)
{
    Arr_u8_100 ElementVal = {0U};
    /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
    (void)Rte_Read_BsReten_Illumination_Element_Value( (Arr_u8_100*)ElementVal);
    uint8 Status = 0U;
    uint8 SameValuedetected = FALSE;
    Std_ReturnType AllowWrite = E_NOT_OK;
    Memabs_GetMeetModeStatus(&Status);
    SameValuedetected = (uint8)MemLib_MemCmp(Ptr,(Arr_u8_100*)ElementVal,sizeof(Arr_u8_100));
    AllowWrite = MemAbs_AllowWriteRequest(SameValuedetected,MemAbstract_BsReten_Illumination_Index_49);
    if((MEMABS_MEET_MODE_INACTIVE == Status) && (FALSE != ProcessRequest))
    {
        if (E_NOT_OK != AllowWrite)
        {
            /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
            (void)Rte_Write_BsReten_Illumination_Element_Value(Ptr);
            Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Illumination_Element(2);
            if(MemAbstractManagement[MemAbstract_BsReten_Illumination_Index_49].WriteState == WRITE_IDLE)
            {
                MemAbstractManagement[MemAbstract_BsReten_Illumination_Index_49].WriteState = WRITE_REQUESTED;
            }
            else if(MemAbstractManagement[MemAbstract_BsReten_Illumination_Index_49].WriteState == WRITE_PROGRESS)
            {
                MemAbstractManagement[MemAbstract_BsReten_Illumination_Index_49].WriteState = WRITE_PENDING;
            }
            else
            {
                /*Do nothing*/
            }
        }
    }
    else
    {
        Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Illumination_Element(1);
    }
}


Std_ReturnType MemAbstractMdl_Get_BsReten_Illumination_Element(Arr_u8_100* Ptr)
{
     Std_ReturnType status = E_NOT_OK;
     /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
     (void)Rte_Read_BsReten_Illumination_Element_Value(Ptr);
     if(FALSE != MemAbstractManagement[49].ValidData)
     {
         status = E_OK;
     }
     return (status);
}


void MemAbstractMdl_Set_BsReten_Audio_Element(const Arr_u8_100 *Ptr)
{
    Arr_u8_100 ElementVal = {0U};
    /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
    (void)Rte_Read_BsReten_Audio_Element_Value( (Arr_u8_100*)ElementVal);
    uint8 Status = 0U;
    uint8 SameValuedetected = FALSE;
    Std_ReturnType AllowWrite = E_NOT_OK;
    Memabs_GetMeetModeStatus(&Status);
    SameValuedetected = (uint8)MemLib_MemCmp(Ptr,(Arr_u8_100*)ElementVal,sizeof(Arr_u8_100));
    AllowWrite = MemAbs_AllowWriteRequest(SameValuedetected,MemAbstract_BsReten_Audio_Index_50);
    if((MEMABS_MEET_MODE_INACTIVE == Status) && (FALSE != ProcessRequest))
    {
        if (E_NOT_OK != AllowWrite)
        {
            /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
            (void)Rte_Write_BsReten_Audio_Element_Value(Ptr);
            Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Audio_Element(2);
            if(MemAbstractManagement[MemAbstract_BsReten_Audio_Index_50].WriteState == WRITE_IDLE)
            {
                MemAbstractManagement[MemAbstract_BsReten_Audio_Index_50].WriteState = WRITE_REQUESTED;
            }
            else if(MemAbstractManagement[MemAbstract_BsReten_Audio_Index_50].WriteState == WRITE_PROGRESS)
            {
                MemAbstractManagement[MemAbstract_BsReten_Audio_Index_50].WriteState = WRITE_PENDING;
            }
            else
            {
                /*Do nothing*/
            }
        }
    }
    else
    {
        Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Audio_Element(1);
    }
}


Std_ReturnType MemAbstractMdl_Get_BsReten_Audio_Element(Arr_u8_100* Ptr)
{
     Std_ReturnType status = E_NOT_OK;
     /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
     (void)Rte_Read_BsReten_Audio_Element_Value(Ptr);
     if(FALSE != MemAbstractManagement[50].ValidData)
     {
         status = E_OK;
     }
     return (status);
}


void MemAbstractMdl_Set_BsReten_Warning_Element(const Arr_u8_100 *Ptr)
{
    Arr_u8_100 ElementVal = {0U};
    /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
    (void)Rte_Read_BsReten_Warning_Element_Value( (Arr_u8_100*)ElementVal);
    uint8 Status = 0U;
    uint8 SameValuedetected = FALSE;
    Std_ReturnType AllowWrite = E_NOT_OK;
    Memabs_GetMeetModeStatus(&Status);
    SameValuedetected = (uint8)MemLib_MemCmp(Ptr,(Arr_u8_100*)ElementVal,sizeof(Arr_u8_100));
    AllowWrite = MemAbs_AllowWriteRequest(SameValuedetected,MemAbstract_BsReten_Warning_Index_51);
    if((MEMABS_MEET_MODE_INACTIVE == Status) && (FALSE != ProcessRequest))
    {
        if (E_NOT_OK != AllowWrite)
        {
            /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
            (void)Rte_Write_BsReten_Warning_Element_Value(Ptr);
            Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Warning_Element(2);
            if(MemAbstractManagement[MemAbstract_BsReten_Warning_Index_51].WriteState == WRITE_IDLE)
            {
                MemAbstractManagement[MemAbstract_BsReten_Warning_Index_51].WriteState = WRITE_REQUESTED;
            }
            else if(MemAbstractManagement[MemAbstract_BsReten_Warning_Index_51].WriteState == WRITE_PROGRESS)
            {
                MemAbstractManagement[MemAbstract_BsReten_Warning_Index_51].WriteState = WRITE_PENDING;
            }
            else
            {
                /*Do nothing*/
            }
        }
    }
    else
    {
        Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Warning_Element(1);
    }
}


Std_ReturnType MemAbstractMdl_Get_BsReten_Warning_Element(Arr_u8_100* Ptr)
{
     Std_ReturnType status = E_NOT_OK;
     /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
     (void)Rte_Read_BsReten_Warning_Element_Value(Ptr);
     if(FALSE != MemAbstractManagement[51].ValidData)
     {
         status = E_OK;
     }
     return (status);
}


void MemAbstractMdl_Set_BsReten_RealTimeClock_Element(const Arr_u8_100 *Ptr)
{
    Arr_u8_100 ElementVal = {0U};
    /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
    (void)Rte_Read_BsReten_RealTimeClock_Element_Value( (Arr_u8_100*)ElementVal);
    uint8 Status = 0U;
    uint8 SameValuedetected = FALSE;
    Std_ReturnType AllowWrite = E_NOT_OK;
    Memabs_GetMeetModeStatus(&Status);
    SameValuedetected = (uint8)MemLib_MemCmp(Ptr,(Arr_u8_100*)ElementVal,sizeof(Arr_u8_100));
    AllowWrite = MemAbs_AllowWriteRequest(SameValuedetected,MemAbstract_BsReten_RealTimeClock_Index_52);
    if((MEMABS_MEET_MODE_INACTIVE == Status) && (FALSE != ProcessRequest))
    {
        if (E_NOT_OK != AllowWrite)
        {
            /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
            (void)Rte_Write_BsReten_RealTimeClock_Element_Value(Ptr);
            Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_RealTimeClock_Element(2);
            if(MemAbstractManagement[MemAbstract_BsReten_RealTimeClock_Index_52].WriteState == WRITE_IDLE)
            {
                MemAbstractManagement[MemAbstract_BsReten_RealTimeClock_Index_52].WriteState = WRITE_REQUESTED;
            }
            else if(MemAbstractManagement[MemAbstract_BsReten_RealTimeClock_Index_52].WriteState == WRITE_PROGRESS)
            {
                MemAbstractManagement[MemAbstract_BsReten_RealTimeClock_Index_52].WriteState = WRITE_PENDING;
            }
            else
            {
                /*Do nothing*/
            }
        }
    }
    else
    {
        Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_RealTimeClock_Element(1);
    }
}


Std_ReturnType MemAbstractMdl_Get_BsReten_RealTimeClock_Element(Arr_u8_100* Ptr)
{
     Std_ReturnType status = E_NOT_OK;
     /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
     (void)Rte_Read_BsReten_RealTimeClock_Element_Value(Ptr);
     if(FALSE != MemAbstractManagement[52].ValidData)
     {
         status = E_OK;
     }
     return (status);
}


void MemAbstractMdl_Set_BsReten_Communication_Element(const Arr_u8_100 *Ptr)
{
    Arr_u8_100 ElementVal = {0U};
    /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
    (void)Rte_Read_BsReten_Communication_Element_Value( (Arr_u8_100*)ElementVal);
    uint8 Status = 0U;
    uint8 SameValuedetected = FALSE;
    Std_ReturnType AllowWrite = E_NOT_OK;
    Memabs_GetMeetModeStatus(&Status);
    SameValuedetected = (uint8)MemLib_MemCmp(Ptr,(Arr_u8_100*)ElementVal,sizeof(Arr_u8_100));
    AllowWrite = MemAbs_AllowWriteRequest(SameValuedetected,MemAbstract_BsReten_Communication_Index_53);
    if((MEMABS_MEET_MODE_INACTIVE == Status) && (FALSE != ProcessRequest))
    {
        if (E_NOT_OK != AllowWrite)
        {
            /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
            (void)Rte_Write_BsReten_Communication_Element_Value(Ptr);
            Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Communication_Element(2);
            if(MemAbstractManagement[MemAbstract_BsReten_Communication_Index_53].WriteState == WRITE_IDLE)
            {
                MemAbstractManagement[MemAbstract_BsReten_Communication_Index_53].WriteState = WRITE_REQUESTED;
            }
            else if(MemAbstractManagement[MemAbstract_BsReten_Communication_Index_53].WriteState == WRITE_PROGRESS)
            {
                MemAbstractManagement[MemAbstract_BsReten_Communication_Index_53].WriteState = WRITE_PENDING;
            }
            else
            {
                /*Do nothing*/
            }
        }
    }
    else
    {
        Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Communication_Element(1);
    }
}


Std_ReturnType MemAbstractMdl_Get_BsReten_Communication_Element(Arr_u8_100* Ptr)
{
     Std_ReturnType status = E_NOT_OK;
     /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
     (void)Rte_Read_BsReten_Communication_Element_Value(Ptr);
     if(FALSE != MemAbstractManagement[53].ValidData)
     {
         status = E_OK;
     }
     return (status);
}


void MemAbstractMdl_Set_BsReten_Personalization_Element(const Arr_u8_100 *Ptr)
{
    Arr_u8_100 ElementVal = {0U};
    /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
    (void)Rte_Read_BsReten_Personalization_Element_Value( (Arr_u8_100*)ElementVal);
    uint8 Status = 0U;
    uint8 SameValuedetected = FALSE;
    Std_ReturnType AllowWrite = E_NOT_OK;
    Memabs_GetMeetModeStatus(&Status);
    SameValuedetected = (uint8)MemLib_MemCmp(Ptr,(Arr_u8_100*)ElementVal,sizeof(Arr_u8_100));
    AllowWrite = MemAbs_AllowWriteRequest(SameValuedetected,MemAbstract_BsReten_Personalization_Index_54);
    if((MEMABS_MEET_MODE_INACTIVE == Status) && (FALSE != ProcessRequest))
    {
        if (E_NOT_OK != AllowWrite)
        {
            /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
            (void)Rte_Write_BsReten_Personalization_Element_Value(Ptr);
            Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Personalization_Element(2);
            if(MemAbstractManagement[MemAbstract_BsReten_Personalization_Index_54].WriteState == WRITE_IDLE)
            {
                MemAbstractManagement[MemAbstract_BsReten_Personalization_Index_54].WriteState = WRITE_REQUESTED;
            }
            else if(MemAbstractManagement[MemAbstract_BsReten_Personalization_Index_54].WriteState == WRITE_PROGRESS)
            {
                MemAbstractManagement[MemAbstract_BsReten_Personalization_Index_54].WriteState = WRITE_PENDING;
            }
            else
            {
                /*Do nothing*/
            }
        }
    }
    else
    {
        Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Personalization_Element(1);
    }
}


Std_ReturnType MemAbstractMdl_Get_BsReten_Personalization_Element(Arr_u8_100* Ptr)
{
     Std_ReturnType status = E_NOT_OK;
     /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
     (void)Rte_Read_BsReten_Personalization_Element_Value(Ptr);
     if(FALSE != MemAbstractManagement[54].ValidData)
     {
         status = E_OK;
     }
     return (status);
}


void MemAbstractMdl_Set_BsReten_VisDlt_Element(const Arr_u8_256 *Ptr)
{
    Arr_u8_256 ElementVal = {0U};
    /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
    (void)Rte_Read_BsReten_VisDlt_Element_Value( (Arr_u8_256*)ElementVal);
    uint8 Status = 0U;
    uint8 SameValuedetected = FALSE;
    Std_ReturnType AllowWrite = E_NOT_OK;
    Memabs_GetMeetModeStatus(&Status);
    SameValuedetected = (uint8)MemLib_MemCmp(Ptr,(Arr_u8_256*)ElementVal,sizeof(Arr_u8_256));
    AllowWrite = MemAbs_AllowWriteRequest(SameValuedetected,MemAbstract_BsReten_VisDlt_Index_55);
    if((MEMABS_MEET_MODE_INACTIVE == Status) && (FALSE != ProcessRequest))
    {
        if (E_NOT_OK != AllowWrite)
        {
            /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
            (void)Rte_Write_BsReten_VisDlt_Element_Value(Ptr);
            Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_VisDlt_Element(2);
            if(MemAbstractManagement[MemAbstract_BsReten_VisDlt_Index_55].WriteState == WRITE_IDLE)
            {
                MemAbstractManagement[MemAbstract_BsReten_VisDlt_Index_55].WriteState = WRITE_REQUESTED;
            }
            else if(MemAbstractManagement[MemAbstract_BsReten_VisDlt_Index_55].WriteState == WRITE_PROGRESS)
            {
                MemAbstractManagement[MemAbstract_BsReten_VisDlt_Index_55].WriteState = WRITE_PENDING;
            }
            else
            {
                /*Do nothing*/
            }
        }
    }
    else
    {
        Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_VisDlt_Element(1);
    }
}


Std_ReturnType MemAbstractMdl_Get_BsReten_VisDlt_Element(Arr_u8_256* Ptr)
{
     Std_ReturnType status = E_NOT_OK;
     /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
     (void)Rte_Read_BsReten_VisDlt_Element_Value(Ptr);
     if(FALSE != MemAbstractManagement[55].ValidData)
     {
         status = E_OK;
     }
     return (status);
}


void MemAbstractMdl_Set_BsReten_Power_Element(const Arr_u8_100 *Ptr)
{
    Arr_u8_100 ElementVal = {0U};
    /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
    (void)Rte_Read_BsReten_Power_Element_Value( (Arr_u8_100*)ElementVal);
    uint8 Status = 0U;
    uint8 SameValuedetected = FALSE;
    Std_ReturnType AllowWrite = E_NOT_OK;
    Memabs_GetMeetModeStatus(&Status);
    SameValuedetected = (uint8)MemLib_MemCmp(Ptr,(Arr_u8_100*)ElementVal,sizeof(Arr_u8_100));
    AllowWrite = MemAbs_AllowWriteRequest(SameValuedetected,MemAbstract_BsReten_Power_Index_56);
    if((MEMABS_MEET_MODE_INACTIVE == Status) && (FALSE != ProcessRequest))
    {
        if (E_NOT_OK != AllowWrite)
        {
            /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
            (void)Rte_Write_BsReten_Power_Element_Value(Ptr);
            Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Power_Element(2);
            if(MemAbstractManagement[MemAbstract_BsReten_Power_Index_56].WriteState == WRITE_IDLE)
            {
                MemAbstractManagement[MemAbstract_BsReten_Power_Index_56].WriteState = WRITE_REQUESTED;
            }
            else if(MemAbstractManagement[MemAbstract_BsReten_Power_Index_56].WriteState == WRITE_PROGRESS)
            {
                MemAbstractManagement[MemAbstract_BsReten_Power_Index_56].WriteState = WRITE_PENDING;
            }
            else
            {
                /*Do nothing*/
            }
        }
    }
    else
    {
        Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Power_Element(1);
    }
}


Std_ReturnType MemAbstractMdl_Get_BsReten_Power_Element(Arr_u8_100* Ptr)
{
     Std_ReturnType status = E_NOT_OK;
     /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
     (void)Rte_Read_BsReten_Power_Element_Value(Ptr);
     if(FALSE != MemAbstractManagement[56].ValidData)
     {
         status = E_OK;
     }
     return (status);
}


void MemAbstractMdl_Set_BsReten_Display_Element(const Arr_u8_100 *Ptr)
{
    Arr_u8_100 ElementVal = {0U};
    /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
    (void)Rte_Read_BsReten_Display_Element_Value( (Arr_u8_100*)ElementVal);
    uint8 Status = 0U;
    uint8 SameValuedetected = FALSE;
    Std_ReturnType AllowWrite = E_NOT_OK;
    Memabs_GetMeetModeStatus(&Status);
    SameValuedetected = (uint8)MemLib_MemCmp(Ptr,(Arr_u8_100*)ElementVal,sizeof(Arr_u8_100));
    AllowWrite = MemAbs_AllowWriteRequest(SameValuedetected,MemAbstract_BsReten_Display_Index_57);
    if((MEMABS_MEET_MODE_INACTIVE == Status) && (FALSE != ProcessRequest))
    {
        if (E_NOT_OK != AllowWrite)
        {
            /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
            (void)Rte_Write_BsReten_Display_Element_Value(Ptr);
            Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Display_Element(2);
            if(MemAbstractManagement[MemAbstract_BsReten_Display_Index_57].WriteState == WRITE_IDLE)
            {
                MemAbstractManagement[MemAbstract_BsReten_Display_Index_57].WriteState = WRITE_REQUESTED;
            }
            else if(MemAbstractManagement[MemAbstract_BsReten_Display_Index_57].WriteState == WRITE_PROGRESS)
            {
                MemAbstractManagement[MemAbstract_BsReten_Display_Index_57].WriteState = WRITE_PENDING;
            }
            else
            {
                /*Do nothing*/
            }
        }
    }
    else
    {
        Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Display_Element(1);
    }
}


Std_ReturnType MemAbstractMdl_Get_BsReten_Display_Element(Arr_u8_100* Ptr)
{
     Std_ReturnType status = E_NOT_OK;
     /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
     (void)Rte_Read_BsReten_Display_Element_Value(Ptr);
     if(FALSE != MemAbstractManagement[57].ValidData)
     {
         status = E_OK;
     }
     return (status);
}


void MemAbstractMdl_Set_BsDiag_ErrorRecord_Element(const Arr_u8_1024 *Ptr)
{
    Arr_u8_1024 ElementVal = {0U};
    /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
    (void)Rte_Read_BsDiag_ErrorRecord_Element_Value( (Arr_u8_1024*)ElementVal);
    uint8 Status = 0U;
    uint8 SameValuedetected = FALSE;
    Std_ReturnType AllowWrite = E_NOT_OK;
    Memabs_GetMeetModeStatus(&Status);
    SameValuedetected = (uint8)MemLib_MemCmp(Ptr,(Arr_u8_1024*)ElementVal,sizeof(Arr_u8_1024));
    AllowWrite = MemAbs_AllowWriteRequest(SameValuedetected,MemAbstract_BsDiag_ErrorRecord_Index_58);
    if((MEMABS_MEET_MODE_INACTIVE == Status) && (FALSE != ProcessRequest))
    {
        if (E_NOT_OK != AllowWrite)
        {
            /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
            (void)Rte_Write_BsDiag_ErrorRecord_Element_Value(Ptr);
            Rte_Write_pp_SR_JobStatus_JobStatus_BsDiag_ErrorRecord_Element(2);
            if(MemAbstractManagement[MemAbstract_BsDiag_ErrorRecord_Index_58].WriteState == WRITE_IDLE)
            {
                MemAbstractManagement[MemAbstract_BsDiag_ErrorRecord_Index_58].WriteState = WRITE_REQUESTED;
            }
            else if(MemAbstractManagement[MemAbstract_BsDiag_ErrorRecord_Index_58].WriteState == WRITE_PROGRESS)
            {
                MemAbstractManagement[MemAbstract_BsDiag_ErrorRecord_Index_58].WriteState = WRITE_PENDING;
            }
            else
            {
                /*Do nothing*/
            }
        }
    }
    else
    {
        Rte_Write_pp_SR_JobStatus_JobStatus_BsDiag_ErrorRecord_Element(1);
    }
}


Std_ReturnType MemAbstractMdl_Get_BsDiag_ErrorRecord_Element(Arr_u8_1024* Ptr)
{
     Std_ReturnType status = E_NOT_OK;
     /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
     (void)Rte_Read_BsDiag_ErrorRecord_Element_Value(Ptr);
     if(FALSE != MemAbstractManagement[58].ValidData)
     {
         status = E_OK;
     }
     return (status);
}


void MemAbstractMdl_Set_BsDiag_Dtc_Element(const Arr_u8_2048 *Ptr)
{
    Arr_u8_2048 ElementVal = {0U};
    /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
    (void)Rte_Read_BsDiag_Dtc_Element_Value( (Arr_u8_2048*)ElementVal);
    uint8 Status = 0U;
    uint8 SameValuedetected = FALSE;
    Std_ReturnType AllowWrite = E_NOT_OK;
    Memabs_GetMeetModeStatus(&Status);
    SameValuedetected = (uint8)MemLib_MemCmp(Ptr,(Arr_u8_2048*)ElementVal,sizeof(Arr_u8_2048));
    AllowWrite = MemAbs_AllowWriteRequest(SameValuedetected,MemAbstract_BsDiag_Dtc_Index_59);
    if((MEMABS_MEET_MODE_INACTIVE == Status) && (FALSE != ProcessRequest))
    {
        if (E_NOT_OK != AllowWrite)
        {
            /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
            (void)Rte_Write_BsDiag_Dtc_Element_Value(Ptr);
            Rte_Write_pp_SR_JobStatus_JobStatus_BsDiag_Dtc_Element(2);
            if(MemAbstractManagement[MemAbstract_BsDiag_Dtc_Index_59].WriteState == WRITE_IDLE)
            {
                MemAbstractManagement[MemAbstract_BsDiag_Dtc_Index_59].WriteState = WRITE_REQUESTED;
            }
            else if(MemAbstractManagement[MemAbstract_BsDiag_Dtc_Index_59].WriteState == WRITE_PROGRESS)
            {
                MemAbstractManagement[MemAbstract_BsDiag_Dtc_Index_59].WriteState = WRITE_PENDING;
            }
            else
            {
                /*Do nothing*/
            }
        }
    }
    else
    {
        Rte_Write_pp_SR_JobStatus_JobStatus_BsDiag_Dtc_Element(1);
    }
}


Std_ReturnType MemAbstractMdl_Get_BsDiag_Dtc_Element(Arr_u8_2048* Ptr)
{
     Std_ReturnType status = E_NOT_OK;
     /* to justify the MISRA C-2012 Rule 17.7: void is added before the Rte call,there won't be any impact as it will always return as E_OK*/
     (void)Rte_Read_BsDiag_Dtc_Element_Value(Ptr);
     if(FALSE != MemAbstractManagement[59].ValidData)
     {
         status = E_OK;
     }
     return (status);
}


void MemAbstractMdl_NotifyJobEnd_BsShare_SwUpdReflash(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
    Arr_u8_8 Val;

    if((ServiceId == NVM_READ_BLOCK) ||(ServiceId == NVM_READ_ALL))
    {
        if(NVM_REQ_OK == JobResult)
        {
            MemAbstractManagement[0].ValidData = TRUE;
        }
        else
        {
            MemAbstractManagement[0].ValidData = FALSE;
        }
    }
    if(ServiceId == NVM_WRITE_BLOCK)
    {
        if(MemAbstractManagement[0].WriteState == WRITE_PENDING)
        {
            Rte_Read_BsShare_SwUpdReflash_Element_Value((Arr_u8_8*)Val);
            Rte_Write_BsShare_SwUpdReflash_Element_Value((Arr_u8_8*)Val);
            MemAbstractManagement[0].WriteState = WRITE_REQUESTED;
        }
        else if(MemAbstractManagement[0].WriteState == WRITE_REQUESTED)
        {
            if (NVM_REQ_PENDING == JobResult)
            {
                MemAbstractManagement[0].WriteState = WRITE_PROGRESS;
            }
            else
            {
                //Do Nothing
            }
        }
        else if(MemAbstractManagement[0].WriteState == WRITE_PROGRESS)
        {
            MemAbstractManagement[0].WriteState = WRITE_IDLE;
            if(NVM_REQ_OK == JobResult)
            {
                MemAbstractManagement[0].ValidData = TRUE;
                MemAbstractManagement[0].PrvWriteStatus = E_OK;     
            }
            else
            {
                MemAbstractManagement[0].PrvWriteStatus = E_NOT_OK; 
            }
            Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_SwUpdReflash_Element(MemAbstractManagement[0].PrvWriteStatus);
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }
}
void MemAbstractMdl_NotifyJobEnd_BsShare_SwUpdFotaMode(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
    Arr_u8_16 Val;

    if((ServiceId == NVM_READ_BLOCK) ||(ServiceId == NVM_READ_ALL))
    {
        if(NVM_REQ_OK == JobResult)
        {
            MemAbstractManagement[1].ValidData = TRUE;
        }
        else
        {
            MemAbstractManagement[1].ValidData = FALSE;
        }
    }
    if(ServiceId == NVM_WRITE_BLOCK)
    {
        if(MemAbstractManagement[1].WriteState == WRITE_PENDING)
        {
            Rte_Read_BsShare_SwUpdFotaMode_Element_Value((Arr_u8_16*)Val);
            Rte_Write_BsShare_SwUpdFotaMode_Element_Value((Arr_u8_16*)Val);
            MemAbstractManagement[1].WriteState = WRITE_REQUESTED;
        }
        else if(MemAbstractManagement[1].WriteState == WRITE_REQUESTED)
        {
            if (NVM_REQ_PENDING == JobResult)
            {
                MemAbstractManagement[1].WriteState = WRITE_PROGRESS;
            }
            else
            {
                //Do Nothing
            }
        }
        else if(MemAbstractManagement[1].WriteState == WRITE_PROGRESS)
        {
            MemAbstractManagement[1].WriteState = WRITE_IDLE;
            if(NVM_REQ_OK == JobResult)
            {
                MemAbstractManagement[1].ValidData = TRUE;
                MemAbstractManagement[1].PrvWriteStatus = E_OK;     
            }
            else
            {
                MemAbstractManagement[1].PrvWriteStatus = E_NOT_OK; 
            }
            Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaMode_Element(MemAbstractManagement[1].PrvWriteStatus);
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }
}
void MemAbstractMdl_NotifyJobEnd_BsShare_SwUpdFotaFinPrint(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
    Arr_u8_32 Val;

    if((ServiceId == NVM_READ_BLOCK) ||(ServiceId == NVM_READ_ALL))
    {
        if(NVM_REQ_OK == JobResult)
        {
            MemAbstractManagement[2].ValidData = TRUE;
        }
        else
        {
            MemAbstractManagement[2].ValidData = FALSE;
        }
    }
    if(ServiceId == NVM_WRITE_BLOCK)
    {
        if(MemAbstractManagement[2].WriteState == WRITE_PENDING)
        {
            Rte_Read_BsShare_SwUpdFotaFinPrint_Element_Value((Arr_u8_32*)Val);
            Rte_Write_BsShare_SwUpdFotaFinPrint_Element_Value((Arr_u8_32*)Val);
            MemAbstractManagement[2].WriteState = WRITE_REQUESTED;
        }
        else if(MemAbstractManagement[2].WriteState == WRITE_REQUESTED)
        {
            if (NVM_REQ_PENDING == JobResult)
            {
                MemAbstractManagement[2].WriteState = WRITE_PROGRESS;
            }
            else
            {
                //Do Nothing
            }
        }
        else if(MemAbstractManagement[2].WriteState == WRITE_PROGRESS)
        {
            MemAbstractManagement[2].WriteState = WRITE_IDLE;
            if(NVM_REQ_OK == JobResult)
            {
                MemAbstractManagement[2].ValidData = TRUE;
                MemAbstractManagement[2].PrvWriteStatus = E_OK;     
            }
            else
            {
                MemAbstractManagement[2].PrvWriteStatus = E_NOT_OK; 
            }
            Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaFinPrint_Element(MemAbstractManagement[2].PrvWriteStatus);
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }
}
void MemAbstractMdl_NotifyJobEnd_BsShare_SwUpdFotaStatus(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
    Arr_u8_48 Val;

    if((ServiceId == NVM_READ_BLOCK) ||(ServiceId == NVM_READ_ALL))
    {
        if(NVM_REQ_OK == JobResult)
        {
            MemAbstractManagement[3].ValidData = TRUE;
        }
        else
        {
            MemAbstractManagement[3].ValidData = FALSE;
        }
    }
    if(ServiceId == NVM_WRITE_BLOCK)
    {
        if(MemAbstractManagement[3].WriteState == WRITE_PENDING)
        {
            Rte_Read_BsShare_SwUpdFotaStatus_Element_Value((Arr_u8_48*)Val);
            Rte_Write_BsShare_SwUpdFotaStatus_Element_Value((Arr_u8_48*)Val);
            MemAbstractManagement[3].WriteState = WRITE_REQUESTED;
        }
        else if(MemAbstractManagement[3].WriteState == WRITE_REQUESTED)
        {
            if (NVM_REQ_PENDING == JobResult)
            {
                MemAbstractManagement[3].WriteState = WRITE_PROGRESS;
            }
            else
            {
                //Do Nothing
            }
        }
        else if(MemAbstractManagement[3].WriteState == WRITE_PROGRESS)
        {
            MemAbstractManagement[3].WriteState = WRITE_IDLE;
            if(NVM_REQ_OK == JobResult)
            {
                MemAbstractManagement[3].ValidData = TRUE;
                MemAbstractManagement[3].PrvWriteStatus = E_OK;     
            }
            else
            {
                MemAbstractManagement[3].PrvWriteStatus = E_NOT_OK; 
            }
            Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaStatus_Element(MemAbstractManagement[3].PrvWriteStatus);
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }
}
void MemAbstractMdl_NotifyJobEnd_BsShare_SwUpdFotadecrypt(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
    Arr_u8_64 Val;

    if((ServiceId == NVM_READ_BLOCK) ||(ServiceId == NVM_READ_ALL))
    {
        if(NVM_REQ_OK == JobResult)
        {
            MemAbstractManagement[4].ValidData = TRUE;
        }
        else
        {
            MemAbstractManagement[4].ValidData = FALSE;
        }
    }
    if(ServiceId == NVM_WRITE_BLOCK)
    {
        if(MemAbstractManagement[4].WriteState == WRITE_PENDING)
        {
            Rte_Read_BsShare_SwUpdFotadecrypt_Element_Value((Arr_u8_64*)Val);
            Rte_Write_BsShare_SwUpdFotadecrypt_Element_Value((Arr_u8_64*)Val);
            MemAbstractManagement[4].WriteState = WRITE_REQUESTED;
        }
        else if(MemAbstractManagement[4].WriteState == WRITE_REQUESTED)
        {
            if (NVM_REQ_PENDING == JobResult)
            {
                MemAbstractManagement[4].WriteState = WRITE_PROGRESS;
            }
            else
            {
                //Do Nothing
            }
        }
        else if(MemAbstractManagement[4].WriteState == WRITE_PROGRESS)
        {
            MemAbstractManagement[4].WriteState = WRITE_IDLE;
            if(NVM_REQ_OK == JobResult)
            {
                MemAbstractManagement[4].ValidData = TRUE;
                MemAbstractManagement[4].PrvWriteStatus = E_OK;     
            }
            else
            {
                MemAbstractManagement[4].PrvWriteStatus = E_NOT_OK; 
            }
            Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotadecrypt_Element(MemAbstractManagement[4].PrvWriteStatus);
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }
}
void MemAbstractMdl_NotifyJobEnd_BsShare_EcuPartNumber(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
    Arr_u8_128 Val;

    if((ServiceId == NVM_READ_BLOCK) ||(ServiceId == NVM_READ_ALL))
    {
        if(NVM_REQ_OK == JobResult)
        {
            MemAbstractManagement[5].ValidData = TRUE;
        }
        else
        {
            MemAbstractManagement[5].ValidData = FALSE;
        }
    }
    if(ServiceId == NVM_WRITE_BLOCK)
    {
        if(MemAbstractManagement[5].WriteState == WRITE_PENDING)
        {
            Rte_Read_BsShare_EcuPartNumber_Element_Value((Arr_u8_128*)Val);
            Rte_Write_BsShare_EcuPartNumber_Element_Value((Arr_u8_128*)Val);
            MemAbstractManagement[5].WriteState = WRITE_REQUESTED;
        }
        else if(MemAbstractManagement[5].WriteState == WRITE_REQUESTED)
        {
            if (NVM_REQ_PENDING == JobResult)
            {
                MemAbstractManagement[5].WriteState = WRITE_PROGRESS;
            }
            else
            {
                //Do Nothing
            }
        }
        else if(MemAbstractManagement[5].WriteState == WRITE_PROGRESS)
        {
            MemAbstractManagement[5].WriteState = WRITE_IDLE;
            if(NVM_REQ_OK == JobResult)
            {
                MemAbstractManagement[5].ValidData = TRUE;
                MemAbstractManagement[5].PrvWriteStatus = E_OK;     
            }
            else
            {
                MemAbstractManagement[5].PrvWriteStatus = E_NOT_OK; 
            }
            Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_EcuPartNumber_Element(MemAbstractManagement[5].PrvWriteStatus);
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }
}
void MemAbstractMdl_NotifyJobEnd_BsShare_VisMeet(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
    Arr_u8_48 Val;

    if((ServiceId == NVM_READ_BLOCK) ||(ServiceId == NVM_READ_ALL))
    {
        if(NVM_REQ_OK == JobResult)
        {
            MemAbstractManagement[6].ValidData = TRUE;
        }
        else
        {
            MemAbstractManagement[6].ValidData = FALSE;
        }
    }
    if(ServiceId == NVM_WRITE_BLOCK)
    {
        if(MemAbstractManagement[6].WriteState == WRITE_PENDING)
        {
            Rte_Read_BsShare_VisMeet_Element_Value((Arr_u8_48*)Val);
            Rte_Write_BsShare_VisMeet_Element_Value((Arr_u8_48*)Val);
            MemAbstractManagement[6].WriteState = WRITE_REQUESTED;
        }
        else if(MemAbstractManagement[6].WriteState == WRITE_REQUESTED)
        {
            if (NVM_REQ_PENDING == JobResult)
            {
                MemAbstractManagement[6].WriteState = WRITE_PROGRESS;
            }
            else
            {
                //Do Nothing
            }
        }
        else if(MemAbstractManagement[6].WriteState == WRITE_PROGRESS)
        {
            MemAbstractManagement[6].WriteState = WRITE_IDLE;
            if(NVM_REQ_OK == JobResult)
            {
                MemAbstractManagement[6].ValidData = TRUE;
                MemAbstractManagement[6].PrvWriteStatus = E_OK;     
            }
            else
            {
                MemAbstractManagement[6].PrvWriteStatus = E_NOT_OK; 
            }
            Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_VisMeet_Element(MemAbstractManagement[6].PrvWriteStatus);
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }
}
void MemAbstractMdl_NotifyJobEnd_BsShare_VehicleConfig(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
    Arr_u8_256 Val;

    if((ServiceId == NVM_READ_BLOCK) ||(ServiceId == NVM_READ_ALL))
    {
        if(NVM_REQ_OK == JobResult)
        {
            MemAbstractManagement[7].ValidData = TRUE;
        }
        else
        {
            MemAbstractManagement[7].ValidData = FALSE;
        }
    }
    if(ServiceId == NVM_WRITE_BLOCK)
    {
        if(MemAbstractManagement[7].WriteState == WRITE_PENDING)
        {
            Rte_Read_BsShare_VehicleConfig_Element_Value((Arr_u8_256*)Val);
            Rte_Write_BsShare_VehicleConfig_Element_Value((Arr_u8_256*)Val);
            MemAbstractManagement[7].WriteState = WRITE_REQUESTED;
        }
        else if(MemAbstractManagement[7].WriteState == WRITE_REQUESTED)
        {
            if (NVM_REQ_PENDING == JobResult)
            {
                MemAbstractManagement[7].WriteState = WRITE_PROGRESS;
            }
            else
            {
                //Do Nothing
            }
        }
        else if(MemAbstractManagement[7].WriteState == WRITE_PROGRESS)
        {
            MemAbstractManagement[7].WriteState = WRITE_IDLE;
            if(NVM_REQ_OK == JobResult)
            {
                MemAbstractManagement[7].ValidData = TRUE;
                MemAbstractManagement[7].PrvWriteStatus = E_OK;     
            }
            else
            {
                MemAbstractManagement[7].PrvWriteStatus = E_NOT_OK; 
            }
            Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_VehicleConfig_Element(MemAbstractManagement[7].PrvWriteStatus);
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }
}
void MemAbstractMdl_NotifyJobEnd_BsConst_SpeedoGauge(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
    Arr_u8_64 Val;

    if((ServiceId == NVM_READ_BLOCK) ||(ServiceId == NVM_READ_ALL))
    {
        if(NVM_REQ_OK == JobResult)
        {
            MemAbstractManagement[8].ValidData = TRUE;
        }
        else
        {
            MemAbstractManagement[8].ValidData = FALSE;
        }
    }
    if(ServiceId == NVM_WRITE_BLOCK)
    {
        if(MemAbstractManagement[8].WriteState == WRITE_PENDING)
        {
            Rte_Read_BsConst_SpeedoGauge_Element_Value((Arr_u8_64*)Val);
            Rte_Write_BsConst_SpeedoGauge_Element_Value((Arr_u8_64*)Val);
            MemAbstractManagement[8].WriteState = WRITE_REQUESTED;
        }
        else if(MemAbstractManagement[8].WriteState == WRITE_REQUESTED)
        {
            if (NVM_REQ_PENDING == JobResult)
            {
                MemAbstractManagement[8].WriteState = WRITE_PROGRESS;
            }
            else
            {
                //Do Nothing
            }
        }
        else if(MemAbstractManagement[8].WriteState == WRITE_PROGRESS)
        {
            MemAbstractManagement[8].WriteState = WRITE_IDLE;
            if(NVM_REQ_OK == JobResult)
            {
                MemAbstractManagement[8].ValidData = TRUE;
                MemAbstractManagement[8].PrvWriteStatus = E_OK;     
            }
            else
            {
                MemAbstractManagement[8].PrvWriteStatus = E_NOT_OK; 
            }
            Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_SpeedoGauge_Element(MemAbstractManagement[8].PrvWriteStatus);
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }
}
void MemAbstractMdl_NotifyJobEnd_BsConst_TachoGauge(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
    Arr_u8_64 Val;

    if((ServiceId == NVM_READ_BLOCK) ||(ServiceId == NVM_READ_ALL))
    {
        if(NVM_REQ_OK == JobResult)
        {
            MemAbstractManagement[9].ValidData = TRUE;
        }
        else
        {
            MemAbstractManagement[9].ValidData = FALSE;
        }
    }
    if(ServiceId == NVM_WRITE_BLOCK)
    {
        if(MemAbstractManagement[9].WriteState == WRITE_PENDING)
        {
            Rte_Read_BsConst_TachoGauge_Element_Value((Arr_u8_64*)Val);
            Rte_Write_BsConst_TachoGauge_Element_Value((Arr_u8_64*)Val);
            MemAbstractManagement[9].WriteState = WRITE_REQUESTED;
        }
        else if(MemAbstractManagement[9].WriteState == WRITE_REQUESTED)
        {
            if (NVM_REQ_PENDING == JobResult)
            {
                MemAbstractManagement[9].WriteState = WRITE_PROGRESS;
            }
            else
            {
                //Do Nothing
            }
        }
        else if(MemAbstractManagement[9].WriteState == WRITE_PROGRESS)
        {
            MemAbstractManagement[9].WriteState = WRITE_IDLE;
            if(NVM_REQ_OK == JobResult)
            {
                MemAbstractManagement[9].ValidData = TRUE;
                MemAbstractManagement[9].PrvWriteStatus = E_OK;     
            }
            else
            {
                MemAbstractManagement[9].PrvWriteStatus = E_NOT_OK; 
            }
            Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_TachoGauge_Element(MemAbstractManagement[9].PrvWriteStatus);
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }
}
void MemAbstractMdl_NotifyJobEnd_BsConst_FuelGauge(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
    Arr_u8_128 Val;

    if((ServiceId == NVM_READ_BLOCK) ||(ServiceId == NVM_READ_ALL))
    {
        if(NVM_REQ_OK == JobResult)
        {
            MemAbstractManagement[10].ValidData = TRUE;
        }
        else
        {
            MemAbstractManagement[10].ValidData = FALSE;
        }
    }
    if(ServiceId == NVM_WRITE_BLOCK)
    {
        if(MemAbstractManagement[10].WriteState == WRITE_PENDING)
        {
            Rte_Read_BsConst_FuelGauge_Element_Value((Arr_u8_128*)Val);
            Rte_Write_BsConst_FuelGauge_Element_Value((Arr_u8_128*)Val);
            MemAbstractManagement[10].WriteState = WRITE_REQUESTED;
        }
        else if(MemAbstractManagement[10].WriteState == WRITE_REQUESTED)
        {
            if (NVM_REQ_PENDING == JobResult)
            {
                MemAbstractManagement[10].WriteState = WRITE_PROGRESS;
            }
            else
            {
                //Do Nothing
            }
        }
        else if(MemAbstractManagement[10].WriteState == WRITE_PROGRESS)
        {
            MemAbstractManagement[10].WriteState = WRITE_IDLE;
            if(NVM_REQ_OK == JobResult)
            {
                MemAbstractManagement[10].ValidData = TRUE;
                MemAbstractManagement[10].PrvWriteStatus = E_OK;     
            }
            else
            {
                MemAbstractManagement[10].PrvWriteStatus = E_NOT_OK; 
            }
            Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_FuelGauge_Element(MemAbstractManagement[10].PrvWriteStatus);
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }
}
void MemAbstractMdl_NotifyJobEnd_BsConst_TempGauge(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
    Arr_u8_64 Val;

    if((ServiceId == NVM_READ_BLOCK) ||(ServiceId == NVM_READ_ALL))
    {
        if(NVM_REQ_OK == JobResult)
        {
            MemAbstractManagement[11].ValidData = TRUE;
        }
        else
        {
            MemAbstractManagement[11].ValidData = FALSE;
        }
    }
    if(ServiceId == NVM_WRITE_BLOCK)
    {
        if(MemAbstractManagement[11].WriteState == WRITE_PENDING)
        {
            Rte_Read_BsConst_TempGauge_Element_Value((Arr_u8_64*)Val);
            Rte_Write_BsConst_TempGauge_Element_Value((Arr_u8_64*)Val);
            MemAbstractManagement[11].WriteState = WRITE_REQUESTED;
        }
        else if(MemAbstractManagement[11].WriteState == WRITE_REQUESTED)
        {
            if (NVM_REQ_PENDING == JobResult)
            {
                MemAbstractManagement[11].WriteState = WRITE_PROGRESS;
            }
            else
            {
                //Do Nothing
            }
        }
        else if(MemAbstractManagement[11].WriteState == WRITE_PROGRESS)
        {
            MemAbstractManagement[11].WriteState = WRITE_IDLE;
            if(NVM_REQ_OK == JobResult)
            {
                MemAbstractManagement[11].ValidData = TRUE;
                MemAbstractManagement[11].PrvWriteStatus = E_OK;     
            }
            else
            {
                MemAbstractManagement[11].PrvWriteStatus = E_NOT_OK; 
            }
            Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_TempGauge_Element(MemAbstractManagement[11].PrvWriteStatus);
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }
}
void MemAbstractMdl_NotifyJobEnd_BsConst_PowerGauge(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
    Arr_u8_64 Val;

    if((ServiceId == NVM_READ_BLOCK) ||(ServiceId == NVM_READ_ALL))
    {
        if(NVM_REQ_OK == JobResult)
        {
            MemAbstractManagement[12].ValidData = TRUE;
        }
        else
        {
            MemAbstractManagement[12].ValidData = FALSE;
        }
    }
    if(ServiceId == NVM_WRITE_BLOCK)
    {
        if(MemAbstractManagement[12].WriteState == WRITE_PENDING)
        {
            Rte_Read_BsConst_PowerGauge_Element_Value((Arr_u8_64*)Val);
            Rte_Write_BsConst_PowerGauge_Element_Value((Arr_u8_64*)Val);
            MemAbstractManagement[12].WriteState = WRITE_REQUESTED;
        }
        else if(MemAbstractManagement[12].WriteState == WRITE_REQUESTED)
        {
            if (NVM_REQ_PENDING == JobResult)
            {
                MemAbstractManagement[12].WriteState = WRITE_PROGRESS;
            }
            else
            {
                //Do Nothing
            }
        }
        else if(MemAbstractManagement[12].WriteState == WRITE_PROGRESS)
        {
            MemAbstractManagement[12].WriteState = WRITE_IDLE;
            if(NVM_REQ_OK == JobResult)
            {
                MemAbstractManagement[12].ValidData = TRUE;
                MemAbstractManagement[12].PrvWriteStatus = E_OK;     
            }
            else
            {
                MemAbstractManagement[12].PrvWriteStatus = E_NOT_OK; 
            }
            Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_PowerGauge_Element(MemAbstractManagement[12].PrvWriteStatus);
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }
}
void MemAbstractMdl_NotifyJobEnd_BsConst_OilGauge(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
    Arr_u8_64 Val;

    if((ServiceId == NVM_READ_BLOCK) ||(ServiceId == NVM_READ_ALL))
    {
        if(NVM_REQ_OK == JobResult)
        {
            MemAbstractManagement[13].ValidData = TRUE;
        }
        else
        {
            MemAbstractManagement[13].ValidData = FALSE;
        }
    }
    if(ServiceId == NVM_WRITE_BLOCK)
    {
        if(MemAbstractManagement[13].WriteState == WRITE_PENDING)
        {
            Rte_Read_BsConst_OilGauge_Element_Value((Arr_u8_64*)Val);
            Rte_Write_BsConst_OilGauge_Element_Value((Arr_u8_64*)Val);
            MemAbstractManagement[13].WriteState = WRITE_REQUESTED;
        }
        else if(MemAbstractManagement[13].WriteState == WRITE_REQUESTED)
        {
            if (NVM_REQ_PENDING == JobResult)
            {
                MemAbstractManagement[13].WriteState = WRITE_PROGRESS;
            }
            else
            {
                //Do Nothing
            }
        }
        else if(MemAbstractManagement[13].WriteState == WRITE_PROGRESS)
        {
            MemAbstractManagement[13].WriteState = WRITE_IDLE;
            if(NVM_REQ_OK == JobResult)
            {
                MemAbstractManagement[13].ValidData = TRUE;
                MemAbstractManagement[13].PrvWriteStatus = E_OK;     
            }
            else
            {
                MemAbstractManagement[13].PrvWriteStatus = E_NOT_OK; 
            }
            Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_OilGauge_Element(MemAbstractManagement[13].PrvWriteStatus);
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }
}
void MemAbstractMdl_NotifyJobEnd_BsConst_TripComputer(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
    Arr_u8_64 Val;

    if((ServiceId == NVM_READ_BLOCK) ||(ServiceId == NVM_READ_ALL))
    {
        if(NVM_REQ_OK == JobResult)
        {
            MemAbstractManagement[14].ValidData = TRUE;
        }
        else
        {
            MemAbstractManagement[14].ValidData = FALSE;
        }
    }
    if(ServiceId == NVM_WRITE_BLOCK)
    {
        if(MemAbstractManagement[14].WriteState == WRITE_PENDING)
        {
            Rte_Read_BsConst_TripComputer_Element_Value((Arr_u8_64*)Val);
            Rte_Write_BsConst_TripComputer_Element_Value((Arr_u8_64*)Val);
            MemAbstractManagement[14].WriteState = WRITE_REQUESTED;
        }
        else if(MemAbstractManagement[14].WriteState == WRITE_REQUESTED)
        {
            if (NVM_REQ_PENDING == JobResult)
            {
                MemAbstractManagement[14].WriteState = WRITE_PROGRESS;
            }
            else
            {
                //Do Nothing
            }
        }
        else if(MemAbstractManagement[14].WriteState == WRITE_PROGRESS)
        {
            MemAbstractManagement[14].WriteState = WRITE_IDLE;
            if(NVM_REQ_OK == JobResult)
            {
                MemAbstractManagement[14].ValidData = TRUE;
                MemAbstractManagement[14].PrvWriteStatus = E_OK;     
            }
            else
            {
                MemAbstractManagement[14].PrvWriteStatus = E_NOT_OK; 
            }
            Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_TripComputer_Element(MemAbstractManagement[14].PrvWriteStatus);
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }
}
void MemAbstractMdl_NotifyJobEnd_BsConst_Illumination(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
    Arr_u8_128 Val;

    if((ServiceId == NVM_READ_BLOCK) ||(ServiceId == NVM_READ_ALL))
    {
        if(NVM_REQ_OK == JobResult)
        {
            MemAbstractManagement[15].ValidData = TRUE;
        }
        else
        {
            MemAbstractManagement[15].ValidData = FALSE;
        }
    }
    if(ServiceId == NVM_WRITE_BLOCK)
    {
        if(MemAbstractManagement[15].WriteState == WRITE_PENDING)
        {
            Rte_Read_BsConst_Illumination_Element_Value((Arr_u8_128*)Val);
            Rte_Write_BsConst_Illumination_Element_Value((Arr_u8_128*)Val);
            MemAbstractManagement[15].WriteState = WRITE_REQUESTED;
        }
        else if(MemAbstractManagement[15].WriteState == WRITE_REQUESTED)
        {
            if (NVM_REQ_PENDING == JobResult)
            {
                MemAbstractManagement[15].WriteState = WRITE_PROGRESS;
            }
            else
            {
                //Do Nothing
            }
        }
        else if(MemAbstractManagement[15].WriteState == WRITE_PROGRESS)
        {
            MemAbstractManagement[15].WriteState = WRITE_IDLE;
            if(NVM_REQ_OK == JobResult)
            {
                MemAbstractManagement[15].ValidData = TRUE;
                MemAbstractManagement[15].PrvWriteStatus = E_OK;     
            }
            else
            {
                MemAbstractManagement[15].PrvWriteStatus = E_NOT_OK; 
            }
            Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Illumination_Element(MemAbstractManagement[15].PrvWriteStatus);
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }
}
void MemAbstractMdl_NotifyJobEnd_BsConst_Audio(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
    Arr_u8_128 Val;

    if((ServiceId == NVM_READ_BLOCK) ||(ServiceId == NVM_READ_ALL))
    {
        if(NVM_REQ_OK == JobResult)
        {
            MemAbstractManagement[16].ValidData = TRUE;
        }
        else
        {
            MemAbstractManagement[16].ValidData = FALSE;
        }
    }
    if(ServiceId == NVM_WRITE_BLOCK)
    {
        if(MemAbstractManagement[16].WriteState == WRITE_PENDING)
        {
            Rte_Read_BsConst_Audio_Element_Value((Arr_u8_128*)Val);
            Rte_Write_BsConst_Audio_Element_Value((Arr_u8_128*)Val);
            MemAbstractManagement[16].WriteState = WRITE_REQUESTED;
        }
        else if(MemAbstractManagement[16].WriteState == WRITE_REQUESTED)
        {
            if (NVM_REQ_PENDING == JobResult)
            {
                MemAbstractManagement[16].WriteState = WRITE_PROGRESS;
            }
            else
            {
                //Do Nothing
            }
        }
        else if(MemAbstractManagement[16].WriteState == WRITE_PROGRESS)
        {
            MemAbstractManagement[16].WriteState = WRITE_IDLE;
            if(NVM_REQ_OK == JobResult)
            {
                MemAbstractManagement[16].ValidData = TRUE;
                MemAbstractManagement[16].PrvWriteStatus = E_OK;     
            }
            else
            {
                MemAbstractManagement[16].PrvWriteStatus = E_NOT_OK; 
            }
            Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Audio_Element(MemAbstractManagement[16].PrvWriteStatus);
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }
}
void MemAbstractMdl_NotifyJobEnd_BsConst_Warning(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
    Arr_u8_64 Val;

    if((ServiceId == NVM_READ_BLOCK) ||(ServiceId == NVM_READ_ALL))
    {
        if(NVM_REQ_OK == JobResult)
        {
            MemAbstractManagement[17].ValidData = TRUE;
        }
        else
        {
            MemAbstractManagement[17].ValidData = FALSE;
        }
    }
    if(ServiceId == NVM_WRITE_BLOCK)
    {
        if(MemAbstractManagement[17].WriteState == WRITE_PENDING)
        {
            Rte_Read_BsConst_Warning_Element_Value((Arr_u8_64*)Val);
            Rte_Write_BsConst_Warning_Element_Value((Arr_u8_64*)Val);
            MemAbstractManagement[17].WriteState = WRITE_REQUESTED;
        }
        else if(MemAbstractManagement[17].WriteState == WRITE_REQUESTED)
        {
            if (NVM_REQ_PENDING == JobResult)
            {
                MemAbstractManagement[17].WriteState = WRITE_PROGRESS;
            }
            else
            {
                //Do Nothing
            }
        }
        else if(MemAbstractManagement[17].WriteState == WRITE_PROGRESS)
        {
            MemAbstractManagement[17].WriteState = WRITE_IDLE;
            if(NVM_REQ_OK == JobResult)
            {
                MemAbstractManagement[17].ValidData = TRUE;
                MemAbstractManagement[17].PrvWriteStatus = E_OK;     
            }
            else
            {
                MemAbstractManagement[17].PrvWriteStatus = E_NOT_OK; 
            }
            Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Warning_Element(MemAbstractManagement[17].PrvWriteStatus);
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }
}
void MemAbstractMdl_NotifyJobEnd_BsConst_RealTimeClock(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
    Arr_u8_48 Val;

    if((ServiceId == NVM_READ_BLOCK) ||(ServiceId == NVM_READ_ALL))
    {
        if(NVM_REQ_OK == JobResult)
        {
            MemAbstractManagement[18].ValidData = TRUE;
        }
        else
        {
            MemAbstractManagement[18].ValidData = FALSE;
        }
    }
    if(ServiceId == NVM_WRITE_BLOCK)
    {
        if(MemAbstractManagement[18].WriteState == WRITE_PENDING)
        {
            Rte_Read_BsConst_RealTimeClock_Element_Value((Arr_u8_48*)Val);
            Rte_Write_BsConst_RealTimeClock_Element_Value((Arr_u8_48*)Val);
            MemAbstractManagement[18].WriteState = WRITE_REQUESTED;
        }
        else if(MemAbstractManagement[18].WriteState == WRITE_REQUESTED)
        {
            if (NVM_REQ_PENDING == JobResult)
            {
                MemAbstractManagement[18].WriteState = WRITE_PROGRESS;
            }
            else
            {
                //Do Nothing
            }
        }
        else if(MemAbstractManagement[18].WriteState == WRITE_PROGRESS)
        {
            MemAbstractManagement[18].WriteState = WRITE_IDLE;
            if(NVM_REQ_OK == JobResult)
            {
                MemAbstractManagement[18].ValidData = TRUE;
                MemAbstractManagement[18].PrvWriteStatus = E_OK;     
            }
            else
            {
                MemAbstractManagement[18].PrvWriteStatus = E_NOT_OK; 
            }
            Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_RealTimeClock_Element(MemAbstractManagement[18].PrvWriteStatus);
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }
}
void MemAbstractMdl_NotifyJobEnd_BsConst_Communication(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
    Arr_u8_64 Val;

    if((ServiceId == NVM_READ_BLOCK) ||(ServiceId == NVM_READ_ALL))
    {
        if(NVM_REQ_OK == JobResult)
        {
            MemAbstractManagement[19].ValidData = TRUE;
        }
        else
        {
            MemAbstractManagement[19].ValidData = FALSE;
        }
    }
    if(ServiceId == NVM_WRITE_BLOCK)
    {
        if(MemAbstractManagement[19].WriteState == WRITE_PENDING)
        {
            Rte_Read_BsConst_Communication_Element_Value((Arr_u8_64*)Val);
            Rte_Write_BsConst_Communication_Element_Value((Arr_u8_64*)Val);
            MemAbstractManagement[19].WriteState = WRITE_REQUESTED;
        }
        else if(MemAbstractManagement[19].WriteState == WRITE_REQUESTED)
        {
            if (NVM_REQ_PENDING == JobResult)
            {
                MemAbstractManagement[19].WriteState = WRITE_PROGRESS;
            }
            else
            {
                //Do Nothing
            }
        }
        else if(MemAbstractManagement[19].WriteState == WRITE_PROGRESS)
        {
            MemAbstractManagement[19].WriteState = WRITE_IDLE;
            if(NVM_REQ_OK == JobResult)
            {
                MemAbstractManagement[19].ValidData = TRUE;
                MemAbstractManagement[19].PrvWriteStatus = E_OK;     
            }
            else
            {
                MemAbstractManagement[19].PrvWriteStatus = E_NOT_OK; 
            }
            Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Communication_Element(MemAbstractManagement[19].PrvWriteStatus);
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }
}
void MemAbstractMdl_NotifyJobEnd_BsConst_Power(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
    Arr_u8_32 Val;

    if((ServiceId == NVM_READ_BLOCK) ||(ServiceId == NVM_READ_ALL))
    {
        if(NVM_REQ_OK == JobResult)
        {
            MemAbstractManagement[20].ValidData = TRUE;
        }
        else
        {
            MemAbstractManagement[20].ValidData = FALSE;
        }
    }
    if(ServiceId == NVM_WRITE_BLOCK)
    {
        if(MemAbstractManagement[20].WriteState == WRITE_PENDING)
        {
            Rte_Read_BsConst_Power_Element_Value((Arr_u8_32*)Val);
            Rte_Write_BsConst_Power_Element_Value((Arr_u8_32*)Val);
            MemAbstractManagement[20].WriteState = WRITE_REQUESTED;
        }
        else if(MemAbstractManagement[20].WriteState == WRITE_REQUESTED)
        {
            if (NVM_REQ_PENDING == JobResult)
            {
                MemAbstractManagement[20].WriteState = WRITE_PROGRESS;
            }
            else
            {
                //Do Nothing
            }
        }
        else if(MemAbstractManagement[20].WriteState == WRITE_PROGRESS)
        {
            MemAbstractManagement[20].WriteState = WRITE_IDLE;
            if(NVM_REQ_OK == JobResult)
            {
                MemAbstractManagement[20].ValidData = TRUE;
                MemAbstractManagement[20].PrvWriteStatus = E_OK;     
            }
            else
            {
                MemAbstractManagement[20].PrvWriteStatus = E_NOT_OK; 
            }
            Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Power_Element(MemAbstractManagement[20].PrvWriteStatus);
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }
}
void MemAbstractMdl_NotifyJobEnd_BsConst_ServiceReminder(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
    Arr_u8_48 Val;

    if((ServiceId == NVM_READ_BLOCK) ||(ServiceId == NVM_READ_ALL))
    {
        if(NVM_REQ_OK == JobResult)
        {
            MemAbstractManagement[21].ValidData = TRUE;
        }
        else
        {
            MemAbstractManagement[21].ValidData = FALSE;
        }
    }
    if(ServiceId == NVM_WRITE_BLOCK)
    {
        if(MemAbstractManagement[21].WriteState == WRITE_PENDING)
        {
            Rte_Read_BsConst_ServiceReminder_Element_Value((Arr_u8_48*)Val);
            Rte_Write_BsConst_ServiceReminder_Element_Value((Arr_u8_48*)Val);
            MemAbstractManagement[21].WriteState = WRITE_REQUESTED;
        }
        else if(MemAbstractManagement[21].WriteState == WRITE_REQUESTED)
        {
            if (NVM_REQ_PENDING == JobResult)
            {
                MemAbstractManagement[21].WriteState = WRITE_PROGRESS;
            }
            else
            {
                //Do Nothing
            }
        }
        else if(MemAbstractManagement[21].WriteState == WRITE_PROGRESS)
        {
            MemAbstractManagement[21].WriteState = WRITE_IDLE;
            if(NVM_REQ_OK == JobResult)
            {
                MemAbstractManagement[21].ValidData = TRUE;
                MemAbstractManagement[21].PrvWriteStatus = E_OK;     
            }
            else
            {
                MemAbstractManagement[21].PrvWriteStatus = E_NOT_OK; 
            }
            Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_ServiceReminder_Element(MemAbstractManagement[21].PrvWriteStatus);
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }
}
void MemAbstractMdl_NotifyJobEnd_BsConst_EngOffTimer(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
    Arr_u8_32 Val;

    if((ServiceId == NVM_READ_BLOCK) ||(ServiceId == NVM_READ_ALL))
    {
        if(NVM_REQ_OK == JobResult)
        {
            MemAbstractManagement[22].ValidData = TRUE;
        }
        else
        {
            MemAbstractManagement[22].ValidData = FALSE;
        }
    }
    if(ServiceId == NVM_WRITE_BLOCK)
    {
        if(MemAbstractManagement[22].WriteState == WRITE_PENDING)
        {
            Rte_Read_BsConst_EngOffTimer_Element_Value((Arr_u8_32*)Val);
            Rte_Write_BsConst_EngOffTimer_Element_Value((Arr_u8_32*)Val);
            MemAbstractManagement[22].WriteState = WRITE_REQUESTED;
        }
        else if(MemAbstractManagement[22].WriteState == WRITE_REQUESTED)
        {
            if (NVM_REQ_PENDING == JobResult)
            {
                MemAbstractManagement[22].WriteState = WRITE_PROGRESS;
            }
            else
            {
                //Do Nothing
            }
        }
        else if(MemAbstractManagement[22].WriteState == WRITE_PROGRESS)
        {
            MemAbstractManagement[22].WriteState = WRITE_IDLE;
            if(NVM_REQ_OK == JobResult)
            {
                MemAbstractManagement[22].ValidData = TRUE;
                MemAbstractManagement[22].PrvWriteStatus = E_OK;     
            }
            else
            {
                MemAbstractManagement[22].PrvWriteStatus = E_NOT_OK; 
            }
            Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_EngOffTimer_Element(MemAbstractManagement[22].PrvWriteStatus);
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }
}
void MemAbstractMdl_NotifyJobEnd_BsFuSa_Warning(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
    Arr_u8_32 Val;

    if((ServiceId == NVM_READ_BLOCK) ||(ServiceId == NVM_READ_ALL))
    {
        if(NVM_REQ_OK == JobResult)
        {
            MemAbstractManagement[23].ValidData = TRUE;
        }
        else
        {
            MemAbstractManagement[23].ValidData = FALSE;
        }
    }
    if(ServiceId == NVM_WRITE_BLOCK)
    {
        if(MemAbstractManagement[23].WriteState == WRITE_PENDING)
        {
            Rte_Read_BsFuSa_Warning_Element_Value((Arr_u8_32*)Val);
            Rte_Write_BsFuSa_Warning_Element_Value((Arr_u8_32*)Val);
            MemAbstractManagement[23].WriteState = WRITE_REQUESTED;
        }
        else if(MemAbstractManagement[23].WriteState == WRITE_REQUESTED)
        {
            if (NVM_REQ_PENDING == JobResult)
            {
                MemAbstractManagement[23].WriteState = WRITE_PROGRESS;
            }
            else
            {
                //Do Nothing
            }
        }
        else if(MemAbstractManagement[23].WriteState == WRITE_PROGRESS)
        {
            MemAbstractManagement[23].WriteState = WRITE_IDLE;
            if(NVM_REQ_OK == JobResult)
            {
                MemAbstractManagement[23].ValidData = TRUE;
                MemAbstractManagement[23].PrvWriteStatus = E_OK;     
            }
            else
            {
                MemAbstractManagement[23].PrvWriteStatus = E_NOT_OK; 
            }
            Rte_Write_pp_SR_JobStatus_JobStatus_BsFuSa_Warning_Element(MemAbstractManagement[23].PrvWriteStatus);
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }
}
void MemAbstractMdl_NotifyJobEnd_BsFuSa_Power(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
    Arr_u8_48 Val;

    if((ServiceId == NVM_READ_BLOCK) ||(ServiceId == NVM_READ_ALL))
    {
        if(NVM_REQ_OK == JobResult)
        {
            MemAbstractManagement[24].ValidData = TRUE;
        }
        else
        {
            MemAbstractManagement[24].ValidData = FALSE;
        }
    }
    if(ServiceId == NVM_WRITE_BLOCK)
    {
        if(MemAbstractManagement[24].WriteState == WRITE_PENDING)
        {
            Rte_Read_BsFuSa_Power_Element_Value((Arr_u8_48*)Val);
            Rte_Write_BsFuSa_Power_Element_Value((Arr_u8_48*)Val);
            MemAbstractManagement[24].WriteState = WRITE_REQUESTED;
        }
        else if(MemAbstractManagement[24].WriteState == WRITE_REQUESTED)
        {
            if (NVM_REQ_PENDING == JobResult)
            {
                MemAbstractManagement[24].WriteState = WRITE_PROGRESS;
            }
            else
            {
                //Do Nothing
            }
        }
        else if(MemAbstractManagement[24].WriteState == WRITE_PROGRESS)
        {
            MemAbstractManagement[24].WriteState = WRITE_IDLE;
            if(NVM_REQ_OK == JobResult)
            {
                MemAbstractManagement[24].ValidData = TRUE;
                MemAbstractManagement[24].PrvWriteStatus = E_OK;     
            }
            else
            {
                MemAbstractManagement[24].PrvWriteStatus = E_NOT_OK; 
            }
            Rte_Write_pp_SR_JobStatus_JobStatus_BsFuSa_Power_Element(MemAbstractManagement[24].PrvWriteStatus);
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }
}
void MemAbstractMdl_NotifyJobEnd_BsFuSa_Display(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
    Arr_u8_64 Val;

    if((ServiceId == NVM_READ_BLOCK) ||(ServiceId == NVM_READ_ALL))
    {
        if(NVM_REQ_OK == JobResult)
        {
            MemAbstractManagement[25].ValidData = TRUE;
        }
        else
        {
            MemAbstractManagement[25].ValidData = FALSE;
        }
    }
    if(ServiceId == NVM_WRITE_BLOCK)
    {
        if(MemAbstractManagement[25].WriteState == WRITE_PENDING)
        {
            Rte_Read_BsFuSa_Display_Element_Value((Arr_u8_64*)Val);
            Rte_Write_BsFuSa_Display_Element_Value((Arr_u8_64*)Val);
            MemAbstractManagement[25].WriteState = WRITE_REQUESTED;
        }
        else if(MemAbstractManagement[25].WriteState == WRITE_REQUESTED)
        {
            if (NVM_REQ_PENDING == JobResult)
            {
                MemAbstractManagement[25].WriteState = WRITE_PROGRESS;
            }
            else
            {
                //Do Nothing
            }
        }
        else if(MemAbstractManagement[25].WriteState == WRITE_PROGRESS)
        {
            MemAbstractManagement[25].WriteState = WRITE_IDLE;
            if(NVM_REQ_OK == JobResult)
            {
                MemAbstractManagement[25].ValidData = TRUE;
                MemAbstractManagement[25].PrvWriteStatus = E_OK;     
            }
            else
            {
                MemAbstractManagement[25].PrvWriteStatus = E_NOT_OK; 
            }
            Rte_Write_pp_SR_JobStatus_JobStatus_BsFuSa_Display_Element(MemAbstractManagement[25].PrvWriteStatus);
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }
}
void MemAbstractMdl_NotifyJobEnd_BsFuSa_Audio(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
    Arr_u8_32 Val;

    if((ServiceId == NVM_READ_BLOCK) ||(ServiceId == NVM_READ_ALL))
    {
        if(NVM_REQ_OK == JobResult)
        {
            MemAbstractManagement[26].ValidData = TRUE;
        }
        else
        {
            MemAbstractManagement[26].ValidData = FALSE;
        }
    }
    if(ServiceId == NVM_WRITE_BLOCK)
    {
        if(MemAbstractManagement[26].WriteState == WRITE_PENDING)
        {
            Rte_Read_BsFuSa_Audio_Element_Value((Arr_u8_32*)Val);
            Rte_Write_BsFuSa_Audio_Element_Value((Arr_u8_32*)Val);
            MemAbstractManagement[26].WriteState = WRITE_REQUESTED;
        }
        else if(MemAbstractManagement[26].WriteState == WRITE_REQUESTED)
        {
            if (NVM_REQ_PENDING == JobResult)
            {
                MemAbstractManagement[26].WriteState = WRITE_PROGRESS;
            }
            else
            {
                //Do Nothing
            }
        }
        else if(MemAbstractManagement[26].WriteState == WRITE_PROGRESS)
        {
            MemAbstractManagement[26].WriteState = WRITE_IDLE;
            if(NVM_REQ_OK == JobResult)
            {
                MemAbstractManagement[26].ValidData = TRUE;
                MemAbstractManagement[26].PrvWriteStatus = E_OK;     
            }
            else
            {
                MemAbstractManagement[26].PrvWriteStatus = E_NOT_OK; 
            }
            Rte_Write_pp_SR_JobStatus_JobStatus_BsFuSa_Audio_Element(MemAbstractManagement[26].PrvWriteStatus);
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }
}
void MemAbstractMdl_NotifyJobEnd_BsFuSa_Communication(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
    Arr_u8_16 Val;

    if((ServiceId == NVM_READ_BLOCK) ||(ServiceId == NVM_READ_ALL))
    {
        if(NVM_REQ_OK == JobResult)
        {
            MemAbstractManagement[27].ValidData = TRUE;
        }
        else
        {
            MemAbstractManagement[27].ValidData = FALSE;
        }
    }
    if(ServiceId == NVM_WRITE_BLOCK)
    {
        if(MemAbstractManagement[27].WriteState == WRITE_PENDING)
        {
            Rte_Read_BsFuSa_Communication_Element_Value((Arr_u8_16*)Val);
            Rte_Write_BsFuSa_Communication_Element_Value((Arr_u8_16*)Val);
            MemAbstractManagement[27].WriteState = WRITE_REQUESTED;
        }
        else if(MemAbstractManagement[27].WriteState == WRITE_REQUESTED)
        {
            if (NVM_REQ_PENDING == JobResult)
            {
                MemAbstractManagement[27].WriteState = WRITE_PROGRESS;
            }
            else
            {
                //Do Nothing
            }
        }
        else if(MemAbstractManagement[27].WriteState == WRITE_PROGRESS)
        {
            MemAbstractManagement[27].WriteState = WRITE_IDLE;
            if(NVM_REQ_OK == JobResult)
            {
                MemAbstractManagement[27].ValidData = TRUE;
                MemAbstractManagement[27].PrvWriteStatus = E_OK;     
            }
            else
            {
                MemAbstractManagement[27].PrvWriteStatus = E_NOT_OK; 
            }
            Rte_Write_pp_SR_JobStatus_JobStatus_BsFuSa_Communication_Element(MemAbstractManagement[27].PrvWriteStatus);
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }
}
void MemAbstractMdl_NotifyJobEnd_BsFusa_Fota(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
    Arr_u8_32 Val;

    if((ServiceId == NVM_READ_BLOCK) ||(ServiceId == NVM_READ_ALL))
    {
        if(NVM_REQ_OK == JobResult)
        {
            MemAbstractManagement[28].ValidData = TRUE;
        }
        else
        {
            MemAbstractManagement[28].ValidData = FALSE;
        }
    }
    if(ServiceId == NVM_WRITE_BLOCK)
    {
        if(MemAbstractManagement[28].WriteState == WRITE_PENDING)
        {
            Rte_Read_BsFusa_Fota_Element_Value((Arr_u8_32*)Val);
            Rte_Write_BsFusa_Fota_Element_Value((Arr_u8_32*)Val);
            MemAbstractManagement[28].WriteState = WRITE_REQUESTED;
        }
        else if(MemAbstractManagement[28].WriteState == WRITE_REQUESTED)
        {
            if (NVM_REQ_PENDING == JobResult)
            {
                MemAbstractManagement[28].WriteState = WRITE_PROGRESS;
            }
            else
            {
                //Do Nothing
            }
        }
        else if(MemAbstractManagement[28].WriteState == WRITE_PROGRESS)
        {
            MemAbstractManagement[28].WriteState = WRITE_IDLE;
            if(NVM_REQ_OK == JobResult)
            {
                MemAbstractManagement[28].ValidData = TRUE;
                MemAbstractManagement[28].PrvWriteStatus = E_OK;     
            }
            else
            {
                MemAbstractManagement[28].PrvWriteStatus = E_NOT_OK; 
            }
            Rte_Write_pp_SR_JobStatus_JobStatus_BsFusa_Fota_Element(MemAbstractManagement[28].PrvWriteStatus);
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }
}
void MemAbstractMdl_NotifyJobEnd_BsFuSa_Config(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
    Arr_u8_16 Val;

    if((ServiceId == NVM_READ_BLOCK) ||(ServiceId == NVM_READ_ALL))
    {
        if(NVM_REQ_OK == JobResult)
        {
            MemAbstractManagement[29].ValidData = TRUE;
        }
        else
        {
            MemAbstractManagement[29].ValidData = FALSE;
        }
    }
    if(ServiceId == NVM_WRITE_BLOCK)
    {
        if(MemAbstractManagement[29].WriteState == WRITE_PENDING)
        {
            Rte_Read_BsFuSa_Config_Element_Value((Arr_u8_16*)Val);
            Rte_Write_BsFuSa_Config_Element_Value((Arr_u8_16*)Val);
            MemAbstractManagement[29].WriteState = WRITE_REQUESTED;
        }
        else if(MemAbstractManagement[29].WriteState == WRITE_REQUESTED)
        {
            if (NVM_REQ_PENDING == JobResult)
            {
                MemAbstractManagement[29].WriteState = WRITE_PROGRESS;
            }
            else
            {
                //Do Nothing
            }
        }
        else if(MemAbstractManagement[29].WriteState == WRITE_PROGRESS)
        {
            MemAbstractManagement[29].WriteState = WRITE_IDLE;
            if(NVM_REQ_OK == JobResult)
            {
                MemAbstractManagement[29].ValidData = TRUE;
                MemAbstractManagement[29].PrvWriteStatus = E_OK;     
            }
            else
            {
                MemAbstractManagement[29].PrvWriteStatus = E_NOT_OK; 
            }
            Rte_Write_pp_SR_JobStatus_JobStatus_BsFuSa_Config_Element(MemAbstractManagement[29].PrvWriteStatus);
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }
}
void MemAbstractMdl_NotifyJobEnd_BsCys_Certicificate(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
    Arr_u8_64 Val;

    if((ServiceId == NVM_READ_BLOCK) ||(ServiceId == NVM_READ_ALL))
    {
        if(NVM_REQ_OK == JobResult)
        {
            MemAbstractManagement[30].ValidData = TRUE;
        }
        else
        {
            MemAbstractManagement[30].ValidData = FALSE;
        }
    }
    if(ServiceId == NVM_WRITE_BLOCK)
    {
        if(MemAbstractManagement[30].WriteState == WRITE_PENDING)
        {
            Rte_Read_BsCys_Certicificate_Element_Value((Arr_u8_64*)Val);
            Rte_Write_BsCys_Certicificate_Element_Value((Arr_u8_64*)Val);
            MemAbstractManagement[30].WriteState = WRITE_REQUESTED;
        }
        else if(MemAbstractManagement[30].WriteState == WRITE_REQUESTED)
        {
            if (NVM_REQ_PENDING == JobResult)
            {
                MemAbstractManagement[30].WriteState = WRITE_PROGRESS;
            }
            else
            {
                //Do Nothing
            }
        }
        else if(MemAbstractManagement[30].WriteState == WRITE_PROGRESS)
        {
            MemAbstractManagement[30].WriteState = WRITE_IDLE;
            if(NVM_REQ_OK == JobResult)
            {
                MemAbstractManagement[30].ValidData = TRUE;
                MemAbstractManagement[30].PrvWriteStatus = E_OK;     
            }
            else
            {
                MemAbstractManagement[30].PrvWriteStatus = E_NOT_OK; 
            }
            Rte_Write_pp_SR_JobStatus_JobStatus_BsCys_Certicificate_Element(MemAbstractManagement[30].PrvWriteStatus);
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }
}
void MemAbstractMdl_NotifyJobEnd_RefCys_Certicificate(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
    Arr_u8_64 Val;

    if((ServiceId == NVM_READ_BLOCK) ||(ServiceId == NVM_READ_ALL))
    {
        if(NVM_REQ_OK == JobResult)
        {
            MemAbstractManagement[31].ValidData = TRUE;
        }
        else
        {
            MemAbstractManagement[31].ValidData = FALSE;
        }
    }
    if(ServiceId == NVM_WRITE_BLOCK)
    {
        if(MemAbstractManagement[31].WriteState == WRITE_PENDING)
        {
            Rte_Read_RefCys_Certicificate_Element_Value((Arr_u8_64*)Val);
            Rte_Write_RefCys_Certicificate_Element_Value((Arr_u8_64*)Val);
            MemAbstractManagement[31].WriteState = WRITE_REQUESTED;
        }
        else if(MemAbstractManagement[31].WriteState == WRITE_REQUESTED)
        {
            if (NVM_REQ_PENDING == JobResult)
            {
                MemAbstractManagement[31].WriteState = WRITE_PROGRESS;
            }
            else
            {
                //Do Nothing
            }
        }
        else if(MemAbstractManagement[31].WriteState == WRITE_PROGRESS)
        {
            MemAbstractManagement[31].WriteState = WRITE_IDLE;
            if(NVM_REQ_OK == JobResult)
            {
                MemAbstractManagement[31].ValidData = TRUE;
                MemAbstractManagement[31].PrvWriteStatus = E_OK;     
            }
            else
            {
                MemAbstractManagement[31].PrvWriteStatus = E_NOT_OK; 
            }
            Rte_Write_pp_SR_JobStatus_JobStatus_RefCys_Certicificate_Element(MemAbstractManagement[31].PrvWriteStatus);
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }
}
void MemAbstractMdl_NotifyJobEnd_RefCys_Certicificate1(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
    Arr_u8_64 Val;

    if((ServiceId == NVM_READ_BLOCK) ||(ServiceId == NVM_READ_ALL))
    {
        if(NVM_REQ_OK == JobResult)
        {
            MemAbstractManagement[32].ValidData = TRUE;
        }
        else
        {
            MemAbstractManagement[32].ValidData = FALSE;
        }
    }
    if(ServiceId == NVM_WRITE_BLOCK)
    {
        if(MemAbstractManagement[32].WriteState == WRITE_PENDING)
        {
            Rte_Read_RefCys_Certicificate1_Element_Value((Arr_u8_64*)Val);
            Rte_Write_RefCys_Certicificate1_Element_Value((Arr_u8_64*)Val);
            MemAbstractManagement[32].WriteState = WRITE_REQUESTED;
        }
        else if(MemAbstractManagement[32].WriteState == WRITE_REQUESTED)
        {
            if (NVM_REQ_PENDING == JobResult)
            {
                MemAbstractManagement[32].WriteState = WRITE_PROGRESS;
            }
            else
            {
                //Do Nothing
            }
        }
        else if(MemAbstractManagement[32].WriteState == WRITE_PROGRESS)
        {
            MemAbstractManagement[32].WriteState = WRITE_IDLE;
            if(NVM_REQ_OK == JobResult)
            {
                MemAbstractManagement[32].ValidData = TRUE;
                MemAbstractManagement[32].PrvWriteStatus = E_OK;     
            }
            else
            {
                MemAbstractManagement[32].PrvWriteStatus = E_NOT_OK; 
            }
            Rte_Write_pp_SR_JobStatus_JobStatus_RefCys_Certicificate1_Element(MemAbstractManagement[32].PrvWriteStatus);
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }
}
void MemAbstractMdl_NotifyJobEnd_BsRt_Odometer(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
    Arr_u8_128 Val;

    if((ServiceId == NVM_READ_BLOCK) ||(ServiceId == NVM_READ_ALL))
    {
        if(NVM_REQ_OK == JobResult)
        {
            MemAbstractManagement[33].ValidData = TRUE;
        }
        else
        {
            MemAbstractManagement[33].ValidData = FALSE;
        }
    }
    if(ServiceId == NVM_WRITE_BLOCK)
    {
        if(MemAbstractManagement[33].WriteState == WRITE_PENDING)
        {
            Rte_Read_BsRt_Odometer_Element_Value((Arr_u8_128*)Val);
            Rte_Write_BsRt_Odometer_Element_Value((Arr_u8_128*)Val);
            MemAbstractManagement[33].WriteState = WRITE_REQUESTED;
        }
        else if(MemAbstractManagement[33].WriteState == WRITE_REQUESTED)
        {
            if (NVM_REQ_PENDING == JobResult)
            {
                MemAbstractManagement[33].WriteState = WRITE_PROGRESS;
            }
            else
            {
                //Do Nothing
            }
        }
        else if(MemAbstractManagement[33].WriteState == WRITE_PROGRESS)
        {
            MemAbstractManagement[33].WriteState = WRITE_IDLE;
            if(NVM_REQ_OK == JobResult)
            {
                MemAbstractManagement[33].ValidData = TRUE;
                MemAbstractManagement[33].PrvWriteStatus = E_OK;     
            }
            else
            {
                MemAbstractManagement[33].PrvWriteStatus = E_NOT_OK; 
            }
            Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_Odometer_Element(MemAbstractManagement[33].PrvWriteStatus);
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }
}
void MemAbstractMdl_NotifyJobEnd_BsRt_SpeedoGauge(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
    Arr_u8_8 Val;

    if((ServiceId == NVM_READ_BLOCK) ||(ServiceId == NVM_READ_ALL))
    {
        if(NVM_REQ_OK == JobResult)
        {
            MemAbstractManagement[34].ValidData = TRUE;
        }
        else
        {
            MemAbstractManagement[34].ValidData = FALSE;
        }
    }
    if(ServiceId == NVM_WRITE_BLOCK)
    {
        if(MemAbstractManagement[34].WriteState == WRITE_PENDING)
        {
            Rte_Read_BsRt_SpeedoGauge_Element_Value((Arr_u8_8*)Val);
            Rte_Write_BsRt_SpeedoGauge_Element_Value((Arr_u8_8*)Val);
            MemAbstractManagement[34].WriteState = WRITE_REQUESTED;
        }
        else if(MemAbstractManagement[34].WriteState == WRITE_REQUESTED)
        {
            if (NVM_REQ_PENDING == JobResult)
            {
                MemAbstractManagement[34].WriteState = WRITE_PROGRESS;
            }
            else
            {
                //Do Nothing
            }
        }
        else if(MemAbstractManagement[34].WriteState == WRITE_PROGRESS)
        {
            MemAbstractManagement[34].WriteState = WRITE_IDLE;
            if(NVM_REQ_OK == JobResult)
            {
                MemAbstractManagement[34].ValidData = TRUE;
                MemAbstractManagement[34].PrvWriteStatus = E_OK;     
            }
            else
            {
                MemAbstractManagement[34].PrvWriteStatus = E_NOT_OK; 
            }
            Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_SpeedoGauge_Element(MemAbstractManagement[34].PrvWriteStatus);
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }
}
void MemAbstractMdl_NotifyJobEnd_BsRt_TachoGauge(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
    Arr_u8_16 Val;

    if((ServiceId == NVM_READ_BLOCK) ||(ServiceId == NVM_READ_ALL))
    {
        if(NVM_REQ_OK == JobResult)
        {
            MemAbstractManagement[35].ValidData = TRUE;
        }
        else
        {
            MemAbstractManagement[35].ValidData = FALSE;
        }
    }
    if(ServiceId == NVM_WRITE_BLOCK)
    {
        if(MemAbstractManagement[35].WriteState == WRITE_PENDING)
        {
            Rte_Read_BsRt_TachoGauge_Element_Value((Arr_u8_16*)Val);
            Rte_Write_BsRt_TachoGauge_Element_Value((Arr_u8_16*)Val);
            MemAbstractManagement[35].WriteState = WRITE_REQUESTED;
        }
        else if(MemAbstractManagement[35].WriteState == WRITE_REQUESTED)
        {
            if (NVM_REQ_PENDING == JobResult)
            {
                MemAbstractManagement[35].WriteState = WRITE_PROGRESS;
            }
            else
            {
                //Do Nothing
            }
        }
        else if(MemAbstractManagement[35].WriteState == WRITE_PROGRESS)
        {
            MemAbstractManagement[35].WriteState = WRITE_IDLE;
            if(NVM_REQ_OK == JobResult)
            {
                MemAbstractManagement[35].ValidData = TRUE;
                MemAbstractManagement[35].PrvWriteStatus = E_OK;     
            }
            else
            {
                MemAbstractManagement[35].PrvWriteStatus = E_NOT_OK; 
            }
            Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_TachoGauge_Element(MemAbstractManagement[35].PrvWriteStatus);
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }
}
void MemAbstractMdl_NotifyJobEnd_BsRt_FuelGauge(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
    Arr_u8_32 Val;

    if((ServiceId == NVM_READ_BLOCK) ||(ServiceId == NVM_READ_ALL))
    {
        if(NVM_REQ_OK == JobResult)
        {
            MemAbstractManagement[36].ValidData = TRUE;
        }
        else
        {
            MemAbstractManagement[36].ValidData = FALSE;
        }
    }
    if(ServiceId == NVM_WRITE_BLOCK)
    {
        if(MemAbstractManagement[36].WriteState == WRITE_PENDING)
        {
            Rte_Read_BsRt_FuelGauge_Element_Value((Arr_u8_32*)Val);
            Rte_Write_BsRt_FuelGauge_Element_Value((Arr_u8_32*)Val);
            MemAbstractManagement[36].WriteState = WRITE_REQUESTED;
        }
        else if(MemAbstractManagement[36].WriteState == WRITE_REQUESTED)
        {
            if (NVM_REQ_PENDING == JobResult)
            {
                MemAbstractManagement[36].WriteState = WRITE_PROGRESS;
            }
            else
            {
                //Do Nothing
            }
        }
        else if(MemAbstractManagement[36].WriteState == WRITE_PROGRESS)
        {
            MemAbstractManagement[36].WriteState = WRITE_IDLE;
            if(NVM_REQ_OK == JobResult)
            {
                MemAbstractManagement[36].ValidData = TRUE;
                MemAbstractManagement[36].PrvWriteStatus = E_OK;     
            }
            else
            {
                MemAbstractManagement[36].PrvWriteStatus = E_NOT_OK; 
            }
            Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_FuelGauge_Element(MemAbstractManagement[36].PrvWriteStatus);
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }
}
void MemAbstractMdl_NotifyJobEnd_BsRt_TempGauge(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
    Arr_u8_32 Val;

    if((ServiceId == NVM_READ_BLOCK) ||(ServiceId == NVM_READ_ALL))
    {
        if(NVM_REQ_OK == JobResult)
        {
            MemAbstractManagement[37].ValidData = TRUE;
        }
        else
        {
            MemAbstractManagement[37].ValidData = FALSE;
        }
    }
    if(ServiceId == NVM_WRITE_BLOCK)
    {
        if(MemAbstractManagement[37].WriteState == WRITE_PENDING)
        {
            Rte_Read_BsRt_TempGauge_Element_Value((Arr_u8_32*)Val);
            Rte_Write_BsRt_TempGauge_Element_Value((Arr_u8_32*)Val);
            MemAbstractManagement[37].WriteState = WRITE_REQUESTED;
        }
        else if(MemAbstractManagement[37].WriteState == WRITE_REQUESTED)
        {
            if (NVM_REQ_PENDING == JobResult)
            {
                MemAbstractManagement[37].WriteState = WRITE_PROGRESS;
            }
            else
            {
                //Do Nothing
            }
        }
        else if(MemAbstractManagement[37].WriteState == WRITE_PROGRESS)
        {
            MemAbstractManagement[37].WriteState = WRITE_IDLE;
            if(NVM_REQ_OK == JobResult)
            {
                MemAbstractManagement[37].ValidData = TRUE;
                MemAbstractManagement[37].PrvWriteStatus = E_OK;     
            }
            else
            {
                MemAbstractManagement[37].PrvWriteStatus = E_NOT_OK; 
            }
            Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_TempGauge_Element(MemAbstractManagement[37].PrvWriteStatus);
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }
}
void MemAbstractMdl_NotifyJobEnd_BsRt_PowerGauge(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
    Arr_u8_32 Val;

    if((ServiceId == NVM_READ_BLOCK) ||(ServiceId == NVM_READ_ALL))
    {
        if(NVM_REQ_OK == JobResult)
        {
            MemAbstractManagement[38].ValidData = TRUE;
        }
        else
        {
            MemAbstractManagement[38].ValidData = FALSE;
        }
    }
    if(ServiceId == NVM_WRITE_BLOCK)
    {
        if(MemAbstractManagement[38].WriteState == WRITE_PENDING)
        {
            Rte_Read_BsRt_PowerGauge_Element_Value((Arr_u8_32*)Val);
            Rte_Write_BsRt_PowerGauge_Element_Value((Arr_u8_32*)Val);
            MemAbstractManagement[38].WriteState = WRITE_REQUESTED;
        }
        else if(MemAbstractManagement[38].WriteState == WRITE_REQUESTED)
        {
            if (NVM_REQ_PENDING == JobResult)
            {
                MemAbstractManagement[38].WriteState = WRITE_PROGRESS;
            }
            else
            {
                //Do Nothing
            }
        }
        else if(MemAbstractManagement[38].WriteState == WRITE_PROGRESS)
        {
            MemAbstractManagement[38].WriteState = WRITE_IDLE;
            if(NVM_REQ_OK == JobResult)
            {
                MemAbstractManagement[38].ValidData = TRUE;
                MemAbstractManagement[38].PrvWriteStatus = E_OK;     
            }
            else
            {
                MemAbstractManagement[38].PrvWriteStatus = E_NOT_OK; 
            }
            Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_PowerGauge_Element(MemAbstractManagement[38].PrvWriteStatus);
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }
}
void MemAbstractMdl_NotifyJobEnd_BsRt_OilGauge(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
    Arr_u8_8 Val;

    if((ServiceId == NVM_READ_BLOCK) ||(ServiceId == NVM_READ_ALL))
    {
        if(NVM_REQ_OK == JobResult)
        {
            MemAbstractManagement[39].ValidData = TRUE;
        }
        else
        {
            MemAbstractManagement[39].ValidData = FALSE;
        }
    }
    if(ServiceId == NVM_WRITE_BLOCK)
    {
        if(MemAbstractManagement[39].WriteState == WRITE_PENDING)
        {
            Rte_Read_BsRt_OilGauge_Element_Value((Arr_u8_8*)Val);
            Rte_Write_BsRt_OilGauge_Element_Value((Arr_u8_8*)Val);
            MemAbstractManagement[39].WriteState = WRITE_REQUESTED;
        }
        else if(MemAbstractManagement[39].WriteState == WRITE_REQUESTED)
        {
            if (NVM_REQ_PENDING == JobResult)
            {
                MemAbstractManagement[39].WriteState = WRITE_PROGRESS;
            }
            else
            {
                //Do Nothing
            }
        }
        else if(MemAbstractManagement[39].WriteState == WRITE_PROGRESS)
        {
            MemAbstractManagement[39].WriteState = WRITE_IDLE;
            if(NVM_REQ_OK == JobResult)
            {
                MemAbstractManagement[39].ValidData = TRUE;
                MemAbstractManagement[39].PrvWriteStatus = E_OK;     
            }
            else
            {
                MemAbstractManagement[39].PrvWriteStatus = E_NOT_OK; 
            }
            Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_OilGauge_Element(MemAbstractManagement[39].PrvWriteStatus);
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }
}
void MemAbstractMdl_NotifyJobEnd_BsRt_TripComputer(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
    Arr_u8_64 Val;

    if((ServiceId == NVM_READ_BLOCK) ||(ServiceId == NVM_READ_ALL))
    {
        if(NVM_REQ_OK == JobResult)
        {
            MemAbstractManagement[40].ValidData = TRUE;
        }
        else
        {
            MemAbstractManagement[40].ValidData = FALSE;
        }
    }
    if(ServiceId == NVM_WRITE_BLOCK)
    {
        if(MemAbstractManagement[40].WriteState == WRITE_PENDING)
        {
            Rte_Read_BsRt_TripComputer_Element_Value((Arr_u8_64*)Val);
            Rte_Write_BsRt_TripComputer_Element_Value((Arr_u8_64*)Val);
            MemAbstractManagement[40].WriteState = WRITE_REQUESTED;
        }
        else if(MemAbstractManagement[40].WriteState == WRITE_REQUESTED)
        {
            if (NVM_REQ_PENDING == JobResult)
            {
                MemAbstractManagement[40].WriteState = WRITE_PROGRESS;
            }
            else
            {
                //Do Nothing
            }
        }
        else if(MemAbstractManagement[40].WriteState == WRITE_PROGRESS)
        {
            MemAbstractManagement[40].WriteState = WRITE_IDLE;
            if(NVM_REQ_OK == JobResult)
            {
                MemAbstractManagement[40].ValidData = TRUE;
                MemAbstractManagement[40].PrvWriteStatus = E_OK;     
            }
            else
            {
                MemAbstractManagement[40].PrvWriteStatus = E_NOT_OK; 
            }
            Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_TripComputer_Element(MemAbstractManagement[40].PrvWriteStatus);
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }
}
void MemAbstractMdl_NotifyJobEnd_BsRt_Warning(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
    Arr_u8_32 Val;

    if((ServiceId == NVM_READ_BLOCK) ||(ServiceId == NVM_READ_ALL))
    {
        if(NVM_REQ_OK == JobResult)
        {
            MemAbstractManagement[41].ValidData = TRUE;
        }
        else
        {
            MemAbstractManagement[41].ValidData = FALSE;
        }
    }
    if(ServiceId == NVM_WRITE_BLOCK)
    {
        if(MemAbstractManagement[41].WriteState == WRITE_PENDING)
        {
            Rte_Read_BsRt_Warning_Element_Value((Arr_u8_32*)Val);
            Rte_Write_BsRt_Warning_Element_Value((Arr_u8_32*)Val);
            MemAbstractManagement[41].WriteState = WRITE_REQUESTED;
        }
        else if(MemAbstractManagement[41].WriteState == WRITE_REQUESTED)
        {
            if (NVM_REQ_PENDING == JobResult)
            {
                MemAbstractManagement[41].WriteState = WRITE_PROGRESS;
            }
            else
            {
                //Do Nothing
            }
        }
        else if(MemAbstractManagement[41].WriteState == WRITE_PROGRESS)
        {
            MemAbstractManagement[41].WriteState = WRITE_IDLE;
            if(NVM_REQ_OK == JobResult)
            {
                MemAbstractManagement[41].ValidData = TRUE;
                MemAbstractManagement[41].PrvWriteStatus = E_OK;     
            }
            else
            {
                MemAbstractManagement[41].PrvWriteStatus = E_NOT_OK; 
            }
            Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_Warning_Element(MemAbstractManagement[41].PrvWriteStatus);
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }
}
void MemAbstractMdl_NotifyJobEnd_BsRt_RealTimeClock(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
    Arr_u8_48 Val;

    if((ServiceId == NVM_READ_BLOCK) ||(ServiceId == NVM_READ_ALL))
    {
        if(NVM_REQ_OK == JobResult)
        {
            MemAbstractManagement[42].ValidData = TRUE;
        }
        else
        {
            MemAbstractManagement[42].ValidData = FALSE;
        }
    }
    if(ServiceId == NVM_WRITE_BLOCK)
    {
        if(MemAbstractManagement[42].WriteState == WRITE_PENDING)
        {
            Rte_Read_BsRt_RealTimeClock_Element_Value((Arr_u8_48*)Val);
            Rte_Write_BsRt_RealTimeClock_Element_Value((Arr_u8_48*)Val);
            MemAbstractManagement[42].WriteState = WRITE_REQUESTED;
        }
        else if(MemAbstractManagement[42].WriteState == WRITE_REQUESTED)
        {
            if (NVM_REQ_PENDING == JobResult)
            {
                MemAbstractManagement[42].WriteState = WRITE_PROGRESS;
            }
            else
            {
                //Do Nothing
            }
        }
        else if(MemAbstractManagement[42].WriteState == WRITE_PROGRESS)
        {
            MemAbstractManagement[42].WriteState = WRITE_IDLE;
            if(NVM_REQ_OK == JobResult)
            {
                MemAbstractManagement[42].ValidData = TRUE;
                MemAbstractManagement[42].PrvWriteStatus = E_OK;     
            }
            else
            {
                MemAbstractManagement[42].PrvWriteStatus = E_NOT_OK; 
            }
            Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_RealTimeClock_Element(MemAbstractManagement[42].PrvWriteStatus);
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }
}
void MemAbstractMdl_NotifyJobEnd_BsRt_Personalization(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
    Arr_u8_128 Val;

    if((ServiceId == NVM_READ_BLOCK) ||(ServiceId == NVM_READ_ALL))
    {
        if(NVM_REQ_OK == JobResult)
        {
            MemAbstractManagement[43].ValidData = TRUE;
        }
        else
        {
            MemAbstractManagement[43].ValidData = FALSE;
        }
    }
    if(ServiceId == NVM_WRITE_BLOCK)
    {
        if(MemAbstractManagement[43].WriteState == WRITE_PENDING)
        {
            Rte_Read_BsRt_Personalization_Element_Value((Arr_u8_128*)Val);
            Rte_Write_BsRt_Personalization_Element_Value((Arr_u8_128*)Val);
            MemAbstractManagement[43].WriteState = WRITE_REQUESTED;
        }
        else if(MemAbstractManagement[43].WriteState == WRITE_REQUESTED)
        {
            if (NVM_REQ_PENDING == JobResult)
            {
                MemAbstractManagement[43].WriteState = WRITE_PROGRESS;
            }
            else
            {
                //Do Nothing
            }
        }
        else if(MemAbstractManagement[43].WriteState == WRITE_PROGRESS)
        {
            MemAbstractManagement[43].WriteState = WRITE_IDLE;
            if(NVM_REQ_OK == JobResult)
            {
                MemAbstractManagement[43].ValidData = TRUE;
                MemAbstractManagement[43].PrvWriteStatus = E_OK;     
            }
            else
            {
                MemAbstractManagement[43].PrvWriteStatus = E_NOT_OK; 
            }
            Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_Personalization_Element(MemAbstractManagement[43].PrvWriteStatus);
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }
}
void MemAbstractMdl_NotifyJobEnd_BsRt_Illumination(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
    Arr_u8_100 Val;

    if((ServiceId == NVM_READ_BLOCK) ||(ServiceId == NVM_READ_ALL))
    {
        if(NVM_REQ_OK == JobResult)
        {
            MemAbstractManagement[44].ValidData = TRUE;
        }
        else
        {
            MemAbstractManagement[44].ValidData = FALSE;
        }
    }
    if(ServiceId == NVM_WRITE_BLOCK)
    {
        if(MemAbstractManagement[44].WriteState == WRITE_PENDING)
        {
            Rte_Read_BsRt_Illumination_Element_Value((Arr_u8_100*)Val);
            Rte_Write_BsRt_Illumination_Element_Value((Arr_u8_100*)Val);
            MemAbstractManagement[44].WriteState = WRITE_REQUESTED;
        }
        else if(MemAbstractManagement[44].WriteState == WRITE_REQUESTED)
        {
            if (NVM_REQ_PENDING == JobResult)
            {
                MemAbstractManagement[44].WriteState = WRITE_PROGRESS;
            }
            else
            {
                //Do Nothing
            }
        }
        else if(MemAbstractManagement[44].WriteState == WRITE_PROGRESS)
        {
            MemAbstractManagement[44].WriteState = WRITE_IDLE;
            if(NVM_REQ_OK == JobResult)
            {
                MemAbstractManagement[44].ValidData = TRUE;
                MemAbstractManagement[44].PrvWriteStatus = E_OK;     
            }
            else
            {
                MemAbstractManagement[44].PrvWriteStatus = E_NOT_OK; 
            }
            Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_Illumination_Element(MemAbstractManagement[44].PrvWriteStatus);
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }
}
void MemAbstractMdl_NotifyJobEnd_BsRt_CusDlt(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
    Arr_u8_128 Val;

    if((ServiceId == NVM_READ_BLOCK) ||(ServiceId == NVM_READ_ALL))
    {
        if(NVM_REQ_OK == JobResult)
        {
            MemAbstractManagement[45].ValidData = TRUE;
        }
        else
        {
            MemAbstractManagement[45].ValidData = FALSE;
        }
    }
    if(ServiceId == NVM_WRITE_BLOCK)
    {
        if(MemAbstractManagement[45].WriteState == WRITE_PENDING)
        {
            Rte_Read_BsRt_CusDlt_Element_Value((Arr_u8_128*)Val);
            Rte_Write_BsRt_CusDlt_Element_Value((Arr_u8_128*)Val);
            MemAbstractManagement[45].WriteState = WRITE_REQUESTED;
        }
        else if(MemAbstractManagement[45].WriteState == WRITE_REQUESTED)
        {
            if (NVM_REQ_PENDING == JobResult)
            {
                MemAbstractManagement[45].WriteState = WRITE_PROGRESS;
            }
            else
            {
                //Do Nothing
            }
        }
        else if(MemAbstractManagement[45].WriteState == WRITE_PROGRESS)
        {
            MemAbstractManagement[45].WriteState = WRITE_IDLE;
            if(NVM_REQ_OK == JobResult)
            {
                MemAbstractManagement[45].ValidData = TRUE;
                MemAbstractManagement[45].PrvWriteStatus = E_OK;     
            }
            else
            {
                MemAbstractManagement[45].PrvWriteStatus = E_NOT_OK; 
            }
            Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_CusDlt_Element(MemAbstractManagement[45].PrvWriteStatus);
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }
}
void MemAbstractMdl_NotifyJobEnd_BsReten_Odometer(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
    Arr_u8_100 Val;

    if((ServiceId == NVM_READ_BLOCK) ||(ServiceId == NVM_READ_ALL))
    {
        if(NVM_REQ_OK == JobResult)
        {
            MemAbstractManagement[46].ValidData = TRUE;
        }
        else
        {
            MemAbstractManagement[46].ValidData = FALSE;
        }
    }
    if(ServiceId == NVM_WRITE_BLOCK)
    {
        if(MemAbstractManagement[46].WriteState == WRITE_PENDING)
        {
            Rte_Read_BsReten_Odometer_Element_Value((Arr_u8_100*)Val);
            Rte_Write_BsReten_Odometer_Element_Value((Arr_u8_100*)Val);
            MemAbstractManagement[46].WriteState = WRITE_REQUESTED;
        }
        else if(MemAbstractManagement[46].WriteState == WRITE_REQUESTED)
        {
            if (NVM_REQ_PENDING == JobResult)
            {
                MemAbstractManagement[46].WriteState = WRITE_PROGRESS;
            }
            else
            {
                //Do Nothing
            }
        }
        else if(MemAbstractManagement[46].WriteState == WRITE_PROGRESS)
        {
            MemAbstractManagement[46].WriteState = WRITE_IDLE;
            if(NVM_REQ_OK == JobResult)
            {
                MemAbstractManagement[46].ValidData = TRUE;
                MemAbstractManagement[46].PrvWriteStatus = E_OK;     
            }
            else
            {
                MemAbstractManagement[46].PrvWriteStatus = E_NOT_OK; 
            }
            Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Odometer_Element(MemAbstractManagement[46].PrvWriteStatus);
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }
}
void MemAbstractMdl_NotifyJobEnd_BsReten_Gauges(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
    Arr_u8_100 Val;

    if((ServiceId == NVM_READ_BLOCK) ||(ServiceId == NVM_READ_ALL))
    {
        if(NVM_REQ_OK == JobResult)
        {
            MemAbstractManagement[47].ValidData = TRUE;
        }
        else
        {
            MemAbstractManagement[47].ValidData = FALSE;
        }
    }
    if(ServiceId == NVM_WRITE_BLOCK)
    {
        if(MemAbstractManagement[47].WriteState == WRITE_PENDING)
        {
            Rte_Read_BsReten_Gauges_Element_Value((Arr_u8_100*)Val);
            Rte_Write_BsReten_Gauges_Element_Value((Arr_u8_100*)Val);
            MemAbstractManagement[47].WriteState = WRITE_REQUESTED;
        }
        else if(MemAbstractManagement[47].WriteState == WRITE_REQUESTED)
        {
            if (NVM_REQ_PENDING == JobResult)
            {
                MemAbstractManagement[47].WriteState = WRITE_PROGRESS;
            }
            else
            {
                //Do Nothing
            }
        }
        else if(MemAbstractManagement[47].WriteState == WRITE_PROGRESS)
        {
            MemAbstractManagement[47].WriteState = WRITE_IDLE;
            if(NVM_REQ_OK == JobResult)
            {
                MemAbstractManagement[47].ValidData = TRUE;
                MemAbstractManagement[47].PrvWriteStatus = E_OK;     
            }
            else
            {
                MemAbstractManagement[47].PrvWriteStatus = E_NOT_OK; 
            }
            Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Gauges_Element(MemAbstractManagement[47].PrvWriteStatus);
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }
}
void MemAbstractMdl_NotifyJobEnd_BsReten_Tripcomputer(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
    Arr_u8_100 Val;

    if((ServiceId == NVM_READ_BLOCK) ||(ServiceId == NVM_READ_ALL))
    {
        if(NVM_REQ_OK == JobResult)
        {
            MemAbstractManagement[48].ValidData = TRUE;
        }
        else
        {
            MemAbstractManagement[48].ValidData = FALSE;
        }
    }
    if(ServiceId == NVM_WRITE_BLOCK)
    {
        if(MemAbstractManagement[48].WriteState == WRITE_PENDING)
        {
            Rte_Read_BsReten_Tripcomputer_Element_Value((Arr_u8_100*)Val);
            Rte_Write_BsReten_Tripcomputer_Element_Value((Arr_u8_100*)Val);
            MemAbstractManagement[48].WriteState = WRITE_REQUESTED;
        }
        else if(MemAbstractManagement[48].WriteState == WRITE_REQUESTED)
        {
            if (NVM_REQ_PENDING == JobResult)
            {
                MemAbstractManagement[48].WriteState = WRITE_PROGRESS;
            }
            else
            {
                //Do Nothing
            }
        }
        else if(MemAbstractManagement[48].WriteState == WRITE_PROGRESS)
        {
            MemAbstractManagement[48].WriteState = WRITE_IDLE;
            if(NVM_REQ_OK == JobResult)
            {
                MemAbstractManagement[48].ValidData = TRUE;
                MemAbstractManagement[48].PrvWriteStatus = E_OK;     
            }
            else
            {
                MemAbstractManagement[48].PrvWriteStatus = E_NOT_OK; 
            }
            Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Tripcomputer_Element(MemAbstractManagement[48].PrvWriteStatus);
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }
}
void MemAbstractMdl_NotifyJobEnd_BsReten_Illumination(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
    Arr_u8_100 Val;

    if((ServiceId == NVM_READ_BLOCK) ||(ServiceId == NVM_READ_ALL))
    {
        if(NVM_REQ_OK == JobResult)
        {
            MemAbstractManagement[49].ValidData = TRUE;
        }
        else
        {
            MemAbstractManagement[49].ValidData = FALSE;
        }
    }
    if(ServiceId == NVM_WRITE_BLOCK)
    {
        if(MemAbstractManagement[49].WriteState == WRITE_PENDING)
        {
            Rte_Read_BsReten_Illumination_Element_Value((Arr_u8_100*)Val);
            Rte_Write_BsReten_Illumination_Element_Value((Arr_u8_100*)Val);
            MemAbstractManagement[49].WriteState = WRITE_REQUESTED;
        }
        else if(MemAbstractManagement[49].WriteState == WRITE_REQUESTED)
        {
            if (NVM_REQ_PENDING == JobResult)
            {
                MemAbstractManagement[49].WriteState = WRITE_PROGRESS;
            }
            else
            {
                //Do Nothing
            }
        }
        else if(MemAbstractManagement[49].WriteState == WRITE_PROGRESS)
        {
            MemAbstractManagement[49].WriteState = WRITE_IDLE;
            if(NVM_REQ_OK == JobResult)
            {
                MemAbstractManagement[49].ValidData = TRUE;
                MemAbstractManagement[49].PrvWriteStatus = E_OK;     
            }
            else
            {
                MemAbstractManagement[49].PrvWriteStatus = E_NOT_OK; 
            }
            Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Illumination_Element(MemAbstractManagement[49].PrvWriteStatus);
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }
}
void MemAbstractMdl_NotifyJobEnd_BsReten_Audio(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
    Arr_u8_100 Val;

    if((ServiceId == NVM_READ_BLOCK) ||(ServiceId == NVM_READ_ALL))
    {
        if(NVM_REQ_OK == JobResult)
        {
            MemAbstractManagement[50].ValidData = TRUE;
        }
        else
        {
            MemAbstractManagement[50].ValidData = FALSE;
        }
    }
    if(ServiceId == NVM_WRITE_BLOCK)
    {
        if(MemAbstractManagement[50].WriteState == WRITE_PENDING)
        {
            Rte_Read_BsReten_Audio_Element_Value((Arr_u8_100*)Val);
            Rte_Write_BsReten_Audio_Element_Value((Arr_u8_100*)Val);
            MemAbstractManagement[50].WriteState = WRITE_REQUESTED;
        }
        else if(MemAbstractManagement[50].WriteState == WRITE_REQUESTED)
        {
            if (NVM_REQ_PENDING == JobResult)
            {
                MemAbstractManagement[50].WriteState = WRITE_PROGRESS;
            }
            else
            {
                //Do Nothing
            }
        }
        else if(MemAbstractManagement[50].WriteState == WRITE_PROGRESS)
        {
            MemAbstractManagement[50].WriteState = WRITE_IDLE;
            if(NVM_REQ_OK == JobResult)
            {
                MemAbstractManagement[50].ValidData = TRUE;
                MemAbstractManagement[50].PrvWriteStatus = E_OK;     
            }
            else
            {
                MemAbstractManagement[50].PrvWriteStatus = E_NOT_OK; 
            }
            Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Audio_Element(MemAbstractManagement[50].PrvWriteStatus);
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }
}
void MemAbstractMdl_NotifyJobEnd_BsReten_Warning(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
    Arr_u8_100 Val;

    if((ServiceId == NVM_READ_BLOCK) ||(ServiceId == NVM_READ_ALL))
    {
        if(NVM_REQ_OK == JobResult)
        {
            MemAbstractManagement[51].ValidData = TRUE;
        }
        else
        {
            MemAbstractManagement[51].ValidData = FALSE;
        }
    }
    if(ServiceId == NVM_WRITE_BLOCK)
    {
        if(MemAbstractManagement[51].WriteState == WRITE_PENDING)
        {
            Rte_Read_BsReten_Warning_Element_Value((Arr_u8_100*)Val);
            Rte_Write_BsReten_Warning_Element_Value((Arr_u8_100*)Val);
            MemAbstractManagement[51].WriteState = WRITE_REQUESTED;
        }
        else if(MemAbstractManagement[51].WriteState == WRITE_REQUESTED)
        {
            if (NVM_REQ_PENDING == JobResult)
            {
                MemAbstractManagement[51].WriteState = WRITE_PROGRESS;
            }
            else
            {
                //Do Nothing
            }
        }
        else if(MemAbstractManagement[51].WriteState == WRITE_PROGRESS)
        {
            MemAbstractManagement[51].WriteState = WRITE_IDLE;
            if(NVM_REQ_OK == JobResult)
            {
                MemAbstractManagement[51].ValidData = TRUE;
                MemAbstractManagement[51].PrvWriteStatus = E_OK;     
            }
            else
            {
                MemAbstractManagement[51].PrvWriteStatus = E_NOT_OK; 
            }
            Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Warning_Element(MemAbstractManagement[51].PrvWriteStatus);
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }
}
void MemAbstractMdl_NotifyJobEnd_BsReten_RealTimeClock(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
    Arr_u8_100 Val;

    if((ServiceId == NVM_READ_BLOCK) ||(ServiceId == NVM_READ_ALL))
    {
        if(NVM_REQ_OK == JobResult)
        {
            MemAbstractManagement[52].ValidData = TRUE;
        }
        else
        {
            MemAbstractManagement[52].ValidData = FALSE;
        }
    }
    if(ServiceId == NVM_WRITE_BLOCK)
    {
        if(MemAbstractManagement[52].WriteState == WRITE_PENDING)
        {
            Rte_Read_BsReten_RealTimeClock_Element_Value((Arr_u8_100*)Val);
            Rte_Write_BsReten_RealTimeClock_Element_Value((Arr_u8_100*)Val);
            MemAbstractManagement[52].WriteState = WRITE_REQUESTED;
        }
        else if(MemAbstractManagement[52].WriteState == WRITE_REQUESTED)
        {
            if (NVM_REQ_PENDING == JobResult)
            {
                MemAbstractManagement[52].WriteState = WRITE_PROGRESS;
            }
            else
            {
                //Do Nothing
            }
        }
        else if(MemAbstractManagement[52].WriteState == WRITE_PROGRESS)
        {
            MemAbstractManagement[52].WriteState = WRITE_IDLE;
            if(NVM_REQ_OK == JobResult)
            {
                MemAbstractManagement[52].ValidData = TRUE;
                MemAbstractManagement[52].PrvWriteStatus = E_OK;     
            }
            else
            {
                MemAbstractManagement[52].PrvWriteStatus = E_NOT_OK; 
            }
            Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_RealTimeClock_Element(MemAbstractManagement[52].PrvWriteStatus);
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }
}
void MemAbstractMdl_NotifyJobEnd_BsReten_Communication(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
    Arr_u8_100 Val;

    if((ServiceId == NVM_READ_BLOCK) ||(ServiceId == NVM_READ_ALL))
    {
        if(NVM_REQ_OK == JobResult)
        {
            MemAbstractManagement[53].ValidData = TRUE;
        }
        else
        {
            MemAbstractManagement[53].ValidData = FALSE;
        }
    }
    if(ServiceId == NVM_WRITE_BLOCK)
    {
        if(MemAbstractManagement[53].WriteState == WRITE_PENDING)
        {
            Rte_Read_BsReten_Communication_Element_Value((Arr_u8_100*)Val);
            Rte_Write_BsReten_Communication_Element_Value((Arr_u8_100*)Val);
            MemAbstractManagement[53].WriteState = WRITE_REQUESTED;
        }
        else if(MemAbstractManagement[53].WriteState == WRITE_REQUESTED)
        {
            if (NVM_REQ_PENDING == JobResult)
            {
                MemAbstractManagement[53].WriteState = WRITE_PROGRESS;
            }
            else
            {
                //Do Nothing
            }
        }
        else if(MemAbstractManagement[53].WriteState == WRITE_PROGRESS)
        {
            MemAbstractManagement[53].WriteState = WRITE_IDLE;
            if(NVM_REQ_OK == JobResult)
            {
                MemAbstractManagement[53].ValidData = TRUE;
                MemAbstractManagement[53].PrvWriteStatus = E_OK;     
            }
            else
            {
                MemAbstractManagement[53].PrvWriteStatus = E_NOT_OK; 
            }
            Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Communication_Element(MemAbstractManagement[53].PrvWriteStatus);
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }
}
void MemAbstractMdl_NotifyJobEnd_BsReten_Personalization(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
    Arr_u8_100 Val;

    if((ServiceId == NVM_READ_BLOCK) ||(ServiceId == NVM_READ_ALL))
    {
        if(NVM_REQ_OK == JobResult)
        {
            MemAbstractManagement[54].ValidData = TRUE;
        }
        else
        {
            MemAbstractManagement[54].ValidData = FALSE;
        }
    }
    if(ServiceId == NVM_WRITE_BLOCK)
    {
        if(MemAbstractManagement[54].WriteState == WRITE_PENDING)
        {
            Rte_Read_BsReten_Personalization_Element_Value((Arr_u8_100*)Val);
            Rte_Write_BsReten_Personalization_Element_Value((Arr_u8_100*)Val);
            MemAbstractManagement[54].WriteState = WRITE_REQUESTED;
        }
        else if(MemAbstractManagement[54].WriteState == WRITE_REQUESTED)
        {
            if (NVM_REQ_PENDING == JobResult)
            {
                MemAbstractManagement[54].WriteState = WRITE_PROGRESS;
            }
            else
            {
                //Do Nothing
            }
        }
        else if(MemAbstractManagement[54].WriteState == WRITE_PROGRESS)
        {
            MemAbstractManagement[54].WriteState = WRITE_IDLE;
            if(NVM_REQ_OK == JobResult)
            {
                MemAbstractManagement[54].ValidData = TRUE;
                MemAbstractManagement[54].PrvWriteStatus = E_OK;     
            }
            else
            {
                MemAbstractManagement[54].PrvWriteStatus = E_NOT_OK; 
            }
            Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Personalization_Element(MemAbstractManagement[54].PrvWriteStatus);
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }
}
void MemAbstractMdl_NotifyJobEnd_BsReten_VisDlt(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
    Arr_u8_256 Val;

    if((ServiceId == NVM_READ_BLOCK) ||(ServiceId == NVM_READ_ALL))
    {
        if(NVM_REQ_OK == JobResult)
        {
            MemAbstractManagement[55].ValidData = TRUE;
        }
        else
        {
            MemAbstractManagement[55].ValidData = FALSE;
        }
    }
    if(ServiceId == NVM_WRITE_BLOCK)
    {
        if(MemAbstractManagement[55].WriteState == WRITE_PENDING)
        {
            Rte_Read_BsReten_VisDlt_Element_Value((Arr_u8_256*)Val);
            Rte_Write_BsReten_VisDlt_Element_Value((Arr_u8_256*)Val);
            MemAbstractManagement[55].WriteState = WRITE_REQUESTED;
        }
        else if(MemAbstractManagement[55].WriteState == WRITE_REQUESTED)
        {
            if (NVM_REQ_PENDING == JobResult)
            {
                MemAbstractManagement[55].WriteState = WRITE_PROGRESS;
            }
            else
            {
                //Do Nothing
            }
        }
        else if(MemAbstractManagement[55].WriteState == WRITE_PROGRESS)
        {
            MemAbstractManagement[55].WriteState = WRITE_IDLE;
            if(NVM_REQ_OK == JobResult)
            {
                MemAbstractManagement[55].ValidData = TRUE;
                MemAbstractManagement[55].PrvWriteStatus = E_OK;     
            }
            else
            {
                MemAbstractManagement[55].PrvWriteStatus = E_NOT_OK; 
            }
            Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_VisDlt_Element(MemAbstractManagement[55].PrvWriteStatus);
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }
}
void MemAbstractMdl_NotifyJobEnd_BsReten_Power(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
    Arr_u8_100 Val;

    if((ServiceId == NVM_READ_BLOCK) ||(ServiceId == NVM_READ_ALL))
    {
        if(NVM_REQ_OK == JobResult)
        {
            MemAbstractManagement[56].ValidData = TRUE;
        }
        else
        {
            MemAbstractManagement[56].ValidData = FALSE;
        }
    }
    if(ServiceId == NVM_WRITE_BLOCK)
    {
        if(MemAbstractManagement[56].WriteState == WRITE_PENDING)
        {
            Rte_Read_BsReten_Power_Element_Value((Arr_u8_100*)Val);
            Rte_Write_BsReten_Power_Element_Value((Arr_u8_100*)Val);
            MemAbstractManagement[56].WriteState = WRITE_REQUESTED;
        }
        else if(MemAbstractManagement[56].WriteState == WRITE_REQUESTED)
        {
            if (NVM_REQ_PENDING == JobResult)
            {
                MemAbstractManagement[56].WriteState = WRITE_PROGRESS;
            }
            else
            {
                //Do Nothing
            }
        }
        else if(MemAbstractManagement[56].WriteState == WRITE_PROGRESS)
        {
            MemAbstractManagement[56].WriteState = WRITE_IDLE;
            if(NVM_REQ_OK == JobResult)
            {
                MemAbstractManagement[56].ValidData = TRUE;
                MemAbstractManagement[56].PrvWriteStatus = E_OK;     
            }
            else
            {
                MemAbstractManagement[56].PrvWriteStatus = E_NOT_OK; 
            }
            Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Power_Element(MemAbstractManagement[56].PrvWriteStatus);
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }
}
void MemAbstractMdl_NotifyJobEnd_BsReten_Display(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
    Arr_u8_100 Val;

    if((ServiceId == NVM_READ_BLOCK) ||(ServiceId == NVM_READ_ALL))
    {
        if(NVM_REQ_OK == JobResult)
        {
            MemAbstractManagement[57].ValidData = TRUE;
        }
        else
        {
            MemAbstractManagement[57].ValidData = FALSE;
        }
    }
    if(ServiceId == NVM_WRITE_BLOCK)
    {
        if(MemAbstractManagement[57].WriteState == WRITE_PENDING)
        {
            Rte_Read_BsReten_Display_Element_Value((Arr_u8_100*)Val);
            Rte_Write_BsReten_Display_Element_Value((Arr_u8_100*)Val);
            MemAbstractManagement[57].WriteState = WRITE_REQUESTED;
        }
        else if(MemAbstractManagement[57].WriteState == WRITE_REQUESTED)
        {
            if (NVM_REQ_PENDING == JobResult)
            {
                MemAbstractManagement[57].WriteState = WRITE_PROGRESS;
            }
            else
            {
                //Do Nothing
            }
        }
        else if(MemAbstractManagement[57].WriteState == WRITE_PROGRESS)
        {
            MemAbstractManagement[57].WriteState = WRITE_IDLE;
            if(NVM_REQ_OK == JobResult)
            {
                MemAbstractManagement[57].ValidData = TRUE;
                MemAbstractManagement[57].PrvWriteStatus = E_OK;     
            }
            else
            {
                MemAbstractManagement[57].PrvWriteStatus = E_NOT_OK; 
            }
            Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Display_Element(MemAbstractManagement[57].PrvWriteStatus);
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }
}
void MemAbstractMdl_NotifyJobEnd_BsDiag_ErrorRecord(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
    Arr_u8_1024 Val;

    if((ServiceId == NVM_READ_BLOCK) ||(ServiceId == NVM_READ_ALL))
    {
        if(NVM_REQ_OK == JobResult)
        {
            MemAbstractManagement[58].ValidData = TRUE;
        }
        else
        {
            MemAbstractManagement[58].ValidData = FALSE;
        }
    }
    if(ServiceId == NVM_WRITE_BLOCK)
    {
        if(MemAbstractManagement[58].WriteState == WRITE_PENDING)
        {
            Rte_Read_BsDiag_ErrorRecord_Element_Value((Arr_u8_1024*)Val);
            Rte_Write_BsDiag_ErrorRecord_Element_Value((Arr_u8_1024*)Val);
            MemAbstractManagement[58].WriteState = WRITE_REQUESTED;
        }
        else if(MemAbstractManagement[58].WriteState == WRITE_REQUESTED)
        {
            if (NVM_REQ_PENDING == JobResult)
            {
                MemAbstractManagement[58].WriteState = WRITE_PROGRESS;
            }
            else
            {
                //Do Nothing
            }
        }
        else if(MemAbstractManagement[58].WriteState == WRITE_PROGRESS)
        {
            MemAbstractManagement[58].WriteState = WRITE_IDLE;
            if(NVM_REQ_OK == JobResult)
            {
                MemAbstractManagement[58].ValidData = TRUE;
                MemAbstractManagement[58].PrvWriteStatus = E_OK;     
            }
            else
            {
                MemAbstractManagement[58].PrvWriteStatus = E_NOT_OK; 
            }
            Rte_Write_pp_SR_JobStatus_JobStatus_BsDiag_ErrorRecord_Element(MemAbstractManagement[58].PrvWriteStatus);
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }
}
void MemAbstractMdl_NotifyJobEnd_BsDiag_Dtc(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
    Arr_u8_2048 Val;

    if((ServiceId == NVM_READ_BLOCK) ||(ServiceId == NVM_READ_ALL))
    {
        if(NVM_REQ_OK == JobResult)
        {
            MemAbstractManagement[59].ValidData = TRUE;
        }
        else
        {
            MemAbstractManagement[59].ValidData = FALSE;
        }
    }
    if(ServiceId == NVM_WRITE_BLOCK)
    {
        if(MemAbstractManagement[59].WriteState == WRITE_PENDING)
        {
            Rte_Read_BsDiag_Dtc_Element_Value((Arr_u8_2048*)Val);
            Rte_Write_BsDiag_Dtc_Element_Value((Arr_u8_2048*)Val);
            MemAbstractManagement[59].WriteState = WRITE_REQUESTED;
        }
        else if(MemAbstractManagement[59].WriteState == WRITE_REQUESTED)
        {
            if (NVM_REQ_PENDING == JobResult)
            {
                MemAbstractManagement[59].WriteState = WRITE_PROGRESS;
            }
            else
            {
                //Do Nothing
            }
        }
        else if(MemAbstractManagement[59].WriteState == WRITE_PROGRESS)
        {
            MemAbstractManagement[59].WriteState = WRITE_IDLE;
            if(NVM_REQ_OK == JobResult)
            {
                MemAbstractManagement[59].ValidData = TRUE;
                MemAbstractManagement[59].PrvWriteStatus = E_OK;     
            }
            else
            {
                MemAbstractManagement[59].PrvWriteStatus = E_NOT_OK; 
            }
            Rte_Write_pp_SR_JobStatus_JobStatus_BsDiag_Dtc_Element(MemAbstractManagement[59].PrvWriteStatus);
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }
}
Std_ReturnType MemAbstractMdl_NvmWriteStatus( void )
{
    uint16 i;
    Std_ReturnType status = E_OK;
    for(i=0; i< NUM_OF_MEMABSTRACT_BLOCKS; i++)
    {
        if(MemAbstractManagement[i].WriteState != WRITE_IDLE)
        {
            status = E_NOT_OK;
            break;
        }
    }
    return (status);
}

#endif    /* */
/* end of file */
/*Tool Version Information*/
/* Tool Version - v2.2.17 */
/****************************************************************
Created Time: 11-04-2024 19:36:22
****************************************************************/
