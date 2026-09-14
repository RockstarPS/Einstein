//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2022] Visteon Corporation
// All Rights Reserved.
//
// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
// under all copyright laws to protect this work as a published work, when appropriate.
// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
// without the written authorization of Visteon Corporation.
//
//---------------------------------------------------------------------------------------------------------------------
//
// File generated automatically using Visteon VMF & Dijkstra Runtime configuration generator 1.2.0
// Date: Thu Nov 03 17:03:48 IST 2022
// User: GDIMPLEM
// System: GIP
// Configuration: Platform
// Project: NISSAN_J32V_IC
// Message Catalogue version : 1.0.35
//
//---------------------------------------------------------------------------------------------------------------------
#ifndef DK_RUNTIME_TYPES_H
#define DK_RUNTIME_TYPES_H

#include <bits/stl_algo.h>
#include <stdint.h>
#include <stdbool.h>
#include <float.h>
#include <sys/wait.h>
#include "dk_runtime_primitive_types.h"

typedef uint8_t EnetReqCmd_t;
#define EnetReqType_Reset        ((EnetReqCmd_t)1)
#define EnetReqType_linkStatus        ((EnetReqCmd_t)2)
#define EnetReqType_SqiVal        ((EnetReqCmd_t)3)
#define EnetReqType_WorstSqiVal        ((EnetReqCmd_t)4)
#define EnetReqType_BestSqiVal        ((EnetReqCmd_t)5)
#define EnetReqType_FaultStatus        ((EnetReqCmd_t)6)
#define EnetReqType_CableStatus        ((EnetReqCmd_t)7)
#define EnetReqType_masterSlaveStatus        ((EnetReqCmd_t)8)
#define EnetReqType_Last        ((EnetReqCmd_t)9)

typedef uint8_t EnetReqMode_t;
#define EnetReqMode_Read        ((EnetReqMode_t)0)
#define EnetReqMode_Write        ((EnetReqMode_t)1)
#define EnetReqMode_Last        ((EnetReqMode_t)2)

typedef uint16_t uint16;
typedef uint8_t uint8;

typedef uint8_t ELinkStatus_t;
#define ELinkStatus_Up        ((ELinkStatus_t)0)
#define ELinkStatus_Down        ((ELinkStatus_t)1)

typedef struct
{
    uint8_t compId;
    uint8_t msgCnt;
} DKMsgBase_t;

typedef struct
{
    DKMsgBase_t base;
    EnetReqCmd_t cmd;
    EnetReqMode_t mode;
    uint8_t dataLen;
    uint8_t data[32];
} EnetRegReq;

typedef struct
{
    DKMsgBase_t base;
    uint8 ethernetLinkStatus;
} EthlinkDownStatus;

typedef struct
{
    DKMsgBase_t base;
    uint8 FaultStatus;
    uint8 Fault;
    uint16 ETH_SQIValue;
} NotifyNetworkEthStatus;

#ifdef __cplusplus
namespace dk
{
namespace runtime
{
#endif

//< Message Data Types
typedef uint8_t uint8;

typedef uint16_t uint16;

typedef uint8 data_u8_4[4];

typedef uint8 data_u8_70[70];

typedef uint32_t uint32;

typedef uint8_t EDomainId_t;
#define EDomainId_VP        ((EDomainId_t)0)
#define EDomainId_Cluster        ((EDomainId_t)1)
#define EDomainId_IVI        ((EDomainId_t)2)
#define EDomainId_Last        ((EDomainId_t)3)

typedef uint8_t ESystemState_t;
#define ESystemState_Off        ((ESystemState_t)0)
#define ESystemState_Startup        ((ESystemState_t)1)
#define ESystemState_Up        ((ESystemState_t)2)
#define ESystemState_FullRun        ((ESystemState_t)3)
#define ESystemState_PrepareShutdown        ((ESystemState_t)4)
#define ESystemState_Minimal        ((ESystemState_t)5)
#define ESystemState_Shutdown        ((ESystemState_t)6)
#define ESystemState_Last        ((ESystemState_t)7)

typedef uint8 data_u8_32[32];

typedef uint8 data_u8_15[15];

typedef uint8_t ECompState_t;
#define ECompState_Init        ((ECompState_t)0)
#define ECompState_Start        ((ECompState_t)1)
#define ECompState_Run        ((ECompState_t)2)
#define ECompState_Stop        ((ECompState_t)3)
#define ECompState_Shutdown        ((ECompState_t)4)
#define ECompState_Last        ((ECompState_t)5)

typedef int32_t sint32;

typedef uint8_t EGaugeUnit_t;
#define EGaugeUnit_Mph        ((EGaugeUnit_t)0)
#define EGaugeUnit_Kmph        ((EGaugeUnit_t)1)
#define EGaugeUnit_Centigrade        ((EGaugeUnit_t)2)
#define EGaugeUnit_Farenheit        ((EGaugeUnit_t)3)
#define EGaugeUnit_Psi        ((EGaugeUnit_t)4)
#define EGaugeUnit_Pa        ((EGaugeUnit_t)5)
#define EGaugeUnit_Bar        ((EGaugeUnit_t)6)
#define EGaugeUnit_Last        ((EGaugeUnit_t)7)

typedef uint8 data_u8_8[8];

typedef uint8_t EDisplayPower_t;
#define EDisplayPower_Off        ((EDisplayPower_t)0)
#define EDisplayPower_On        ((EDisplayPower_t)1)
#define EDisplayPower_Last        ((EDisplayPower_t)2)

typedef uint8_t EOdoStatus_t;
#define EOdoStatus_Ok        ((EOdoStatus_t)0)
#define EOdoStatus_NVMError        ((EOdoStatus_t)1)
#define EOdoStatus_Missing        ((EOdoStatus_t)2)
#define EOdoStatus_Invalid        ((EOdoStatus_t)4)
#define EOdoStatus_DispDashes        ((EOdoStatus_t)8)
#define EOdoStatus_DispError        ((EOdoStatus_t)16)

typedef uint8_t ECompassValue_t;
#define ECompassValue_Off        ((ECompassValue_t)0)
#define ECompassValue_N        ((ECompassValue_t)1)
#define ECompassValue_NE        ((ECompassValue_t)2)
#define ECompassValue_E        ((ECompassValue_t)3)
#define ECompassValue_SE        ((ECompassValue_t)4)
#define ECompassValue_S        ((ECompassValue_t)5)
#define ECompassValue_SW        ((ECompassValue_t)6)
#define ECompassValue_W        ((ECompassValue_t)7)
#define ECompassValue_NW        ((ECompassValue_t)8)
#define ECompassValue_Last        ((ECompassValue_t)9)

typedef struct
{
    uint8 key;
    uint8 value;
} SKeyVal1;

typedef struct
{
    uint8 key;
    data_u8_4 value;
} SKeyVal4;

typedef uint8_t EDisplayStatus_t;
#define EDisplayState_Off        ((EDisplayStatus_t)0)
#define EDisplayState_On        ((EDisplayStatus_t)1)
#define EDisplayState_Error        ((EDisplayStatus_t)2)
#define EDisplayState_Disconnected        ((EDisplayStatus_t)3)
#define EDisplayState_Last        ((EDisplayStatus_t)4)

typedef struct
{
    uint16 year;
    uint8 month;
    uint8 day;
    uint8 hour;
    uint8 min;
    uint8 sec;
} SDateTime;

typedef uint8 data_u8_256[256];

typedef uint8_t ERoutineType_t;
#define ERoutineType_Start        ((ERoutineType_t)0)
#define ERoutineType_Stop        ((ERoutineType_t)1)
#define ERoutineType_QueryResults        ((ERoutineType_t)2)
#define ERoutineType_Last        ((ERoutineType_t)3)

typedef uint8 data_u8_320[320];

typedef uint8_t EIOCtrlOptType_t;
#define EIOCtrlOptType_returnControlToECU        ((EIOCtrlOptType_t)0)
#define EIOCtrlOptType_resetToDefault        ((EIOCtrlOptType_t)1)
#define EIOCtrlOptType_freezeCurrentState        ((EIOCtrlOptType_t)2)
#define EIOCtrlOptType_shortTermAdjustment        ((EIOCtrlOptType_t)3)
#define EIOCtrlOptType_Last        ((EIOCtrlOptType_t)4)

typedef uint8_t ETripCmd_t;
#define ETripCmd_AFE_A        ((ETripCmd_t)0)
#define ETripCmd_AFE_B        ((ETripCmd_t)1)
#define ETripCmd_TCAFE_B        ((ETripCmd_t)2)
#define ETripCmd_TCT_A        ((ETripCmd_t)3)
#define ETripCmd_TCT_B        ((ETripCmd_t)4)
#define ETripCmd_TCO_A        ((ETripCmd_t)5)
#define ETripCmd_TCO_B        ((ETripCmd_t)6)
#define ETripCmd_TCAFE_A        ((ETripCmd_t)7)
#define ETripCmd_LS        ((ETripCmd_t)8)
#define ETripCmd_TCAS_A        ((ETripCmd_t)9)
#define ETripCmd_TCAS_B        ((ETripCmd_t)10)
#define ETripCmd_FEH        ((ETripCmd_t)11)
#define ETripCmd_Last        ((ETripCmd_t)12)

typedef uint8_t ETrip_t;
#define ETrip_A        ((ETrip_t)0)
#define ETrip_B        ((ETrip_t)1)
#define ETrip_DC        ((ETrip_t)2)
#define ETrip_Last        ((ETrip_t)3)

typedef uint8_t EFuelEconomy_t;
#define EFuelEconomy_None        ((EFuelEconomy_t)0)
#define EFuelEconomy_DTE        ((EFuelEconomy_t)1)
#define EFuelEconomy_IFE        ((EFuelEconomy_t)2)
#define EFuelEconomy_IFETBS        ((EFuelEconomy_t)3)
#define EFuelEconomy_AFE_A        ((EFuelEconomy_t)4)
#define EFuelEconomy_AFE_B        ((EFuelEconomy_t)5)
#define EFuelEconomy_FEH        ((EFuelEconomy_t)6)
#define EFuelEconomy_DCFE        ((EFuelEconomy_t)7)
#define EFuelEconomy_LTFE        ((EFuelEconomy_t)8)
#define EFuelEconomy_RAFE        ((EFuelEconomy_t)9)
#define EFuelEconomy_Last        ((EFuelEconomy_t)10)

typedef uint8 data_u8_5[5];

typedef uint8_t EPhoneCmd_t;
#define EPhoneCmd_Accept        ((EPhoneCmd_t)0)
#define EPhoneCmd_Reject        ((EPhoneCmd_t)1)
#define EPhoneCmd_End        ((EPhoneCmd_t)2)
#define EPhoneCmd_SwapCalls        ((EPhoneCmd_t)3)
#define EPhoneCmd_ConferenceCalls        ((EPhoneCmd_t)4)
#define EPhoneCmd_Privacy        ((EPhoneCmd_t)5)
#define EPhoneCmd_Mute        ((EPhoneCmd_t)6)
#define EPhoneCmd_NoResponse        ((EPhoneCmd_t)7)
#define EPhoneCmd_Last        ((EPhoneCmd_t)8)

typedef uint8_t EPhoneStatus_t;
#define EPhoneStatus_Inactive        ((EPhoneStatus_t)0)
#define EPhoneStatus_Normal        ((EPhoneStatus_t)1)
#define EPhoneStatus_CallWaiting        ((EPhoneStatus_t)2)
#define EPhoneStatus_Hold        ((EPhoneStatus_t)3)
#define EPhoneStatus_Conference        ((EPhoneStatus_t)4)
#define EPhoneStatus_Last        ((EPhoneStatus_t)5)

typedef uint8 data_u8_36[36];

typedef uint8_t EStringEncoding_t;
#define EStringEncoding_Latin1        ((EStringEncoding_t)0)
#define EStringEncoding_UTF8        ((EStringEncoding_t)1)
#define EStringEncoding_UTF16        ((EStringEncoding_t)2)
#define EStringEncoding_Last        ((EStringEncoding_t)3)

typedef uint8 data_u8_25[25];

typedef uint8 data_u8_2[2];

typedef uint16 data_u16_10[10];

typedef uint8_t EIgnitionStatus_t;
#define EIgnitionStatus_Off        ((EIgnitionStatus_t)0)
#define EIgnitionStatus_Acc        ((EIgnitionStatus_t)1)
#define EIgnitionStatus_Start        ((EIgnitionStatus_t)2)
#define EIgnitionStatus_Run        ((EIgnitionStatus_t)3)
#define EIgnitionStatus_Last        ((EIgnitionStatus_t)4)

typedef uint8 data_u8_50[50];

typedef uint8_t EButtonId_t;
#define EButtonId_None        ((EButtonId_t)0)
#define EButtonId_Ok        ((EButtonId_t)1)
#define EButtonId_Up        ((EButtonId_t)2)
#define EButtonId_Down        ((EButtonId_t)3)
#define EButtonId_Back        ((EButtonId_t)4)
#define EButtonId_Menu        ((EButtonId_t)5)
#define EButtonId_Phone        ((EButtonId_t)6)
#define EButtonId_Hud        ((EButtonId_t)7)
#define EButtonId_Last        ((EButtonId_t)8)

typedef uint8_t EButtonState_t;
#define EButtonState_Release        ((EButtonState_t)0)
#define EButtonState_Pressed        ((EButtonState_t)1)
#define EButtonState_Hold        ((EButtonState_t)2)
#define EButtonState_Last        ((EButtonState_t)3)

typedef uint8 data_u8_6[6];

typedef uint8 data_u8_9[9];

typedef uint8_t EOatStatus_t;
#define EOatStatus_Ok        ((EOatStatus_t)0)
#define EOatStatus_Off        ((EOatStatus_t)1)
#define EOatStatus_DispDashes        ((EOatStatus_t)2)
#define EOatStatus_Last        ((EOatStatus_t)3)

typedef uint8_t EMediaText_t;
#define EMediaText_None        ((EMediaText_t)0)
#define EMediaText_CDFileName        ((EMediaText_t)1)
#define EMediaText_CDTrackName        ((EMediaText_t)2)
#define EMediaText_DABBlockNumber        ((EMediaText_t)3)
#define EMediaText_HDRadioSongTitle        ((EMediaText_t)4)
#define EMediaText_SyncSongTitle        ((EMediaText_t)5)
#define EMediaText_Last        ((EMediaText_t)6)

typedef uint8 data_u8_40[40];

typedef uint8 data_u8_130[130];

typedef uint8 data_u8_42[42];

typedef uint8_t EDisplayHMIStatus_t;
#define EDisplayHMIStatus_Ok        ((EDisplayHMIStatus_t)0)
#define EDisplayHMIStatus_Off        ((EDisplayHMIStatus_t)1)
#define EDisplayHMIStatus_Missing        ((EDisplayHMIStatus_t)2)
#define EDisplayHMIStatus_Dashes        ((EDisplayHMIStatus_t)3)
#define EDisplayHMIStatus_Error        ((EDisplayHMIStatus_t)4)
#define EDisplayHMIStatus_Last        ((EDisplayHMIStatus_t)5)

typedef uint8 data_u8_3[3];

typedef uint8_t EUdsTimeout_t;
#define EUdsTimeout_Session        ((EUdsTimeout_t)0)
#define EUdsTimeout_Service        ((EUdsTimeout_t)1)

typedef uint8 data_u8_7168[7168];

typedef uint8 data_u8_17[17];

typedef struct
{
    uint8 ipAddressNetwork1;
    uint8 ipAddressNetwork2;
    uint8 ipAddressHost1;
    uint8 ipAddressHost2;
    uint16 portNum;
} SDoIPSetNetworkInformation;

typedef uint8_t EPWUSCurrentVehicleState_t;
#define EPWUSCurrentVehicleState_Inactive        ((EPWUSCurrentVehicleState_t)0)
#define EPWUSCurrentVehicleState_Normal        ((EPWUSCurrentVehicleState_t)1)
#define EPWUSCurrentVehicleState_Limited        ((EPWUSCurrentVehicleState_t)2)
#define EPWUSCurrentVehicleState_Abnormal        ((EPWUSCurrentVehicleState_t)3)
#define EPWUSCurrentVehicleState_Last        ((EPWUSCurrentVehicleState_t)4)

typedef uint8_t EWUSCurrentAccState_t;
#define EWUSCurrentAccState_NotInACC        ((EWUSCurrentAccState_t)0)
#define EWUSCurrentAccState_InACC        ((EWUSCurrentAccState_t)1)

typedef uint8 data_u8_3584[3584];

typedef uint8_t EOpeningMovieAnimStatus_t;
#define EOpeningMovieAnimStatus_NotStarted        ((EOpeningMovieAnimStatus_t)0)
#define EOpeningMovieAnimStatus_InProgress        ((EOpeningMovieAnimStatus_t)1)
#define EOpeningMovieAnimStatus_Completed        ((EOpeningMovieAnimStatus_t)2)
#define EOpeningMovieAnimStatus_Last        ((EOpeningMovieAnimStatus_t)3)

typedef uint8_t EITSOpngMovieOnDisplay_t;
#define EITSOpngMovieOnDisplay_NotInDisplay        ((EITSOpngMovieOnDisplay_t)0)
#define EITSOpngMovieOnDisplay_InDisplay        ((EITSOpngMovieOnDisplay_t)1)
#define EITSOpngMovieOnDisplay_Last        ((EITSOpngMovieOnDisplay_t)2)

typedef uint8 data_u8_65[65];

typedef uint8 data_u8_60[60];

typedef uint32 data_u32_3[3];

typedef uint8 data_u8_1024[1024];

typedef uint8_t EUIMcanFeatureAvailability_t;
#define EUIMcanFeatureAvailability_NotAvailable        ((EUIMcanFeatureAvailability_t)0)
#define EUIMcanFeatureAvailability_Available        ((EUIMcanFeatureAvailability_t)1)
#define EUIMcanFeatureAvailability_Last        ((EUIMcanFeatureAvailability_t)2)

typedef uint8_t EPOpeningMovieStatus_t;
#define EPOpeningMovieStatus_Off1        ((EPOpeningMovieStatus_t)0)
#define EPOpeningMovieStatus_Off2        ((EPOpeningMovieStatus_t)1)
#define EPOpeningMovieStatus_On        ((EPOpeningMovieStatus_t)2)
#define EPOpeningMovieStatus_Last        ((EPOpeningMovieStatus_t)3)

typedef uint8_t EPITSOpngMovieStatus_t;
#define EPITSOpngMovieStatus_Off1        ((EPITSOpngMovieStatus_t)0)
#define EPITSOpngMovieStatus_On        ((EPITSOpngMovieStatus_t)1)
#define EPITSOpngMovieStatus_Off2        ((EPITSOpngMovieStatus_t)2)
#define EPITSOpngMovieStatus_Last        ((EPITSOpngMovieStatus_t)3)

typedef uint8_t EPButtonId_t;
#define EPButtonId_Back        ((EPButtonId_t)0)
#define EPButtonId_Up        ((EPButtonId_t)1)
#define EPButtonId_Down        ((EPButtonId_t)2)
#define EPButtonId_Ok        ((EPButtonId_t)3)
#define EPButtonId_Left        ((EPButtonId_t)4)
#define EPButtonId_Right        ((EPButtonId_t)5)
#define EPButtonId_Vol_Up        ((EPButtonId_t)6)
#define EPButtonId_Vol_Down        ((EPButtonId_t)7)
#define EPButtonId_Tel        ((EPButtonId_t)8)
#define EPButtonId_Vr        ((EPButtonId_t)9)
#define EPButtonId_Seek_Up        ((EPButtonId_t)10)
#define EPButtonId_Seek_Down        ((EPButtonId_t)11)
#define EPButtonId_Illum_Down        ((EPButtonId_t)12)
#define EPButtonId_Illum_Up        ((EPButtonId_t)13)
#define EPButtonId_Trip_Reset        ((EPButtonId_t)14)
#define EPButtonId_Last        ((EPButtonId_t)15)

typedef uint8_t EPButtonState_t;
#define EPButtonState_Out        ((EPButtonState_t)0)
#define EPButtonState_In        ((EPButtonState_t)1)
#define EPButtonState_Short        ((EPButtonState_t)2)
#define EPButtonState_Long_In        ((EPButtonState_t)3)
#define EPButtonState_Long_Out        ((EPButtonState_t)4)
#define EPButtonState_Super_Long_In        ((EPButtonState_t)5)
#define EPButtonState_Super_Long_Out        ((EPButtonState_t)6)
#define EPButtonState_Stuck        ((EPButtonState_t)7)
#define EPButtonState_Repeat        ((EPButtonState_t)8)
#define EPButtonState_Held        ((EPButtonState_t)9)
#define EPButtonState_Dtc_Btn_Stuck        ((EPButtonState_t)10)
#define EPButtonState_Last        ((EPButtonState_t)11)

typedef uint8_t EPIllumButtonEvent_t;
#define EPIllumButtonEvent_OutEvent        ((EPIllumButtonEvent_t)0)
#define EPIllumButtonEvent_InEvent        ((EPIllumButtonEvent_t)1)
#define EPIllumButtonEvent_IncrEvent        ((EPIllumButtonEvent_t)2)
#define EPIllumButtonEvent_DecrEvent        ((EPIllumButtonEvent_t)3)
#define EPIllumButtonEvent_IncrRptEvent        ((EPIllumButtonEvent_t)4)
#define EPIllumButtonEvent_DecrRptEvent        ((EPIllumButtonEvent_t)5)
#define EPIllumButtonEvent_Last        ((EPIllumButtonEvent_t)6)

typedef uint8_t EVidioPlayerStatusType_t;
#define EVidioPlayerStatusType_EPlayStop        ((EVidioPlayerStatusType_t)0)
#define EVidioPlayerStatusType_EPlayStart        ((EVidioPlayerStatusType_t)1)
#define EVidioPlayerStatusType_Last        ((EVidioPlayerStatusType_t)2)

typedef uint8_t EPictureCopyStatusType_t;
#define EPictureCopyStatusType_NotDone        ((EPictureCopyStatusType_t)0)
#define EPictureCopyStatusType_Done        ((EPictureCopyStatusType_t)1)
#define EPictureCopyStatusType_Last        ((EPictureCopyStatusType_t)2)

typedef uint8_t EFotaSlaveResponse_t;
#define EFotaSlaveResponse_SlaveOk        ((EFotaSlaveResponse_t)0)
#define EFotaSlaveResponse_SlaveNotOk        ((EFotaSlaveResponse_t)1)

typedef uint8_t EInstallerFotaState_t;
#define EInstallerFotaState_Idle        ((EInstallerFotaState_t)0)
#define EInstallerFotaState_InstallationInProgress        ((EInstallerFotaState_t)1)
#define EInstallerFotaState_CopyingInProgress        ((EInstallerFotaState_t)2)
#define EInstallerFotaState_ReadyForSlaveDistribution        ((EInstallerFotaState_t)3)
#define EInstallerFotaState_SlaveDistributionInProgress        ((EInstallerFotaState_t)4)
#define EInstallerFotaState_SlaveIntegrityCheckInProgress        ((EInstallerFotaState_t)5)
#define EInstallerFotaState_SlaveDistributionComplete        ((EInstallerFotaState_t)6)
#define EInstallerFotaState_SlaveInstallationInProgress        ((EInstallerFotaState_t)7)
#define EInstallerFotaState_SlaveCopyingInProgress        ((EInstallerFotaState_t)8)
#define EInstallerFotaState_SlaveInstallationComplete        ((EInstallerFotaState_t)9)
#define EInstallerFotaState_VehicleConditionCheckInProgress        ((EInstallerFotaState_t)10)
#define EInstallerFotaState_ReadyForActivation        ((EInstallerFotaState_t)11)
#define EInstallerFotaState_SwitchInProgress        ((EInstallerFotaState_t)12)
#define EInstallerFotaState_RebootInProgress        ((EInstallerFotaState_t)13)
#define EInstallerFotaState_ComponentVersionCheckInProgress        ((EInstallerFotaState_t)14)
#define EInstallerFotaState_ConfigurationInstallInProgress        ((EInstallerFotaState_t)15)
#define EInstallerFotaState_ActivationComplete        ((EInstallerFotaState_t)16)
#define EInstallerFotaState_CancelInProgress        ((EInstallerFotaState_t)17)
#define EInstallerFotaState_ErrorDetected        ((EInstallerFotaState_t)18)
#define EInstallerFotaState_UpdateErrorDetected        ((EInstallerFotaState_t)19)
#define EInstallerFotaState_RollbackInProgress        ((EInstallerFotaState_t)20)
#define EInstallerFotaState_RollbackComplete        ((EInstallerFotaState_t)21)

typedef uint8_t EInstallerReq_t;
#define EInstallerReq_VlanOpen        ((EInstallerReq_t)0)
#define EInstallerReq_VlanPortClose        ((EInstallerReq_t)1)
#define EInstallerReq_Switch        ((EInstallerReq_t)2)
#define EInstallerReq_Reboot        ((EInstallerReq_t)3)
#define EInstallerReq_RollbackReq        ((EInstallerReq_t)4)
#define EInstallerReq_Reset        ((EInstallerReq_t)5)
#define EInstallerReq_Cancel        ((EInstallerReq_t)6)
#define EInstallerReq_Last        ((EInstallerReq_t)7)

typedef uint8_t EInstallerNotif_t;
#define EInstallerNotif_DistributionStart        ((EInstallerNotif_t)0)
#define EInstallerNotif_DistributionComplete        ((EInstallerNotif_t)1)
#define EInstallerNotif_IntegrityCheckComplete        ((EInstallerNotif_t)2)
#define EInstallerNotif_InstallStart        ((EInstallerNotif_t)3)
#define EInstallerNotif_CompleteToCopy        ((EInstallerNotif_t)4)
#define EInstallerNotif_InstallComplete        ((EInstallerNotif_t)5)
#define EInstallerNotif_Rebootcomplete        ((EInstallerNotif_t)6)
#define EInstallerNotif_Rollbackcomplete        ((EInstallerNotif_t)7)
#define EInstallerNotif_RebootCompleteForRollback        ((EInstallerNotif_t)8)
#define EInstallerNotif_VlanOpenConfirmation        ((EInstallerNotif_t)9)
#define EInstallerNotif_Errordetected        ((EInstallerNotif_t)10)
#define EInstallerNotif_UpdateErrordetected        ((EInstallerNotif_t)11)
#define EInstallerNotif_CancelComplete        ((EInstallerNotif_t)12)
#define EInstallerNotif_ModeChange        ((EInstallerNotif_t)13)
#define EInstallerNotif_GipInitComplete        ((EInstallerNotif_t)14)

typedef uint8_t ELinkStatus_t;
#define ELinkStatus_Up        ((ELinkStatus_t)0)
#define ELinkStatus_Down        ((ELinkStatus_t)1)

typedef uint8_t EVlanRequestType_t;
#define EVlanRequestType_Create        ((EVlanRequestType_t)0)
#define EVlanRequestType_Destroy        ((EVlanRequestType_t)1)

typedef uint8_t EModifyInterfaceReqType_t;
#define EModifyInterfaceReqType_Set        ((EModifyInterfaceReqType_t)0)
#define EModifyInterfaceReqType_Clear        ((EModifyInterfaceReqType_t)1)

typedef uint8_t EMemCtrlShMem_t;
#define EMemCtrlShMem_Bank1        ((EMemCtrlShMem_t)0)
#define EMemCtrlShMem_Bank2        ((EMemCtrlShMem_t)1)
#define EMemCtrlShMem_BankMax        ((EMemCtrlShMem_t)2)

typedef uint8_t EMemCtrlCmd_t;
#define EMemCtrlCmd_Idle        ((EMemCtrlCmd_t)0)
#define EMemCtrlCmd_WriteCompleted        ((EMemCtrlCmd_t)1)
#define EMemCtrlCmd_ReadOkay        ((EMemCtrlCmd_t)2)
#define EMemCtrlCmd_ReadInProgress        ((EMemCtrlCmd_t)3)
#define EMemCtrlCmd_ReadFail        ((EMemCtrlCmd_t)4)
#define EMemCtrlCmd_Readinvlied        ((EMemCtrlCmd_t)5)
#define EMemCtrlCmd_Offsetinvlied        ((EMemCtrlCmd_t)6)
#define EMemCtrlCmd_Max        ((EMemCtrlCmd_t)7)

typedef struct
{
    uint32 key;
    uint32 value;
    uint32 id;
} SKeyVal;

typedef uint8_t EAudioSourceList_t;
#define EAvailableSourceFM        ((EAudioSourceList_t)0)
#define EAvailableSourceFM1        ((EAudioSourceList_t)1)
#define EAvailableSourceFM2        ((EAudioSourceList_t)2)
#define EAvailableSourceFMAP        ((EAudioSourceList_t)3)
#define EAvailableSourceAM        ((EAudioSourceList_t)4)
#define EAvailableSourceAMAP        ((EAudioSourceList_t)5)
#define EAvailableSourceXM1        ((EAudioSourceList_t)6)
#define EAvailableSourceXM2        ((EAudioSourceList_t)7)
#define EAvailableSourceXM3        ((EAudioSourceList_t)8)
#define EAvailableSourceSXM        ((EAudioSourceList_t)9)
#define EAvailableSourceSXM1        ((EAudioSourceList_t)10)
#define EAvailableSourceSXM2        ((EAudioSourceList_t)11)
#define EAvailableSourceSXM3        ((EAudioSourceList_t)12)
#define EAvailableSourceTAJPN        ((EAudioSourceList_t)13)
#define EAvailableSourceDAB        ((EAudioSourceList_t)14)
#define EAvailableSourceTV        ((EAudioSourceList_t)15)
#define EAvailableSourceTV1        ((EAudioSourceList_t)16)
#define EAvailableSourceTV2        ((EAudioSourceList_t)17)
#define EAvailableSourceMusicBox        ((EAudioSourceList_t)18)
#define EAvailableSourceCD        ((EAudioSourceList_t)19)
#define EAvailableSourceDVD        ((EAudioSourceList_t)20)
#define EAvailableSourceUSB        ((EAudioSourceList_t)21)
#define EAvailableSourceUSB1        ((EAudioSourceList_t)22)
#define EAvailableSourceUSB2        ((EAudioSourceList_t)23)
#define EAvailableSourceiPod        ((EAudioSourceList_t)24)
#define EAvailableSourceiPod1        ((EAudioSourceList_t)25)
#define EAvailableSourceiPod2        ((EAudioSourceList_t)26)
#define EAvailableSourceAUX        ((EAudioSourceList_t)27)
#define EAvailableSourceAPPS        ((EAudioSourceList_t)28)
#define EAvailableSourceRSE        ((EAudioSourceList_t)29)
#define EAvailableSourceBTAudio        ((EAudioSourceList_t)30)
#define EAvailableSourceBluray        ((EAudioSourceList_t)31)
#define EAvailableSourceDRM        ((EAudioSourceList_t)32)
#define EAvailableSourceSD        ((EAudioSourceList_t)33)
#define EAvailableSourceCarPlay        ((EAudioSourceList_t)34)
#define EAvailableSourceAndroidAuto        ((EAudioSourceList_t)35)
#define EAvailableSourcemySPIN        ((EAudioSourceList_t)36)
#define EAvailableSourceCarLife        ((EAudioSourceList_t)37)
#define EAvailableSourceSmartPhoneContents        ((EAudioSourceList_t)38)
#define EAvailableSourceHDMI        ((EAudioSourceList_t)39)
#define EMAXAvailableSourceList        ((EAudioSourceList_t)40)

typedef uint8_t EUiSmsMenuItem_t;
#define ESmsMenuRead        ((EUiSmsMenuItem_t)0)
#define ESmsMenuIgnore        ((EUiSmsMenuItem_t)1)
#define ESmsMenuSImDrive        ((EUiSmsMenuItem_t)2)
#define ESmsMenuReply        ((EUiSmsMenuItem_t)3)
#define ESmsMenuCallBack        ((EUiSmsMenuItem_t)4)
#define ESmsMenuExit        ((EUiSmsMenuItem_t)5)
#define ESmsMenuImDrive        ((EUiSmsMenuItem_t)6)
#define ESmsMenuCallMe        ((EUiSmsMenuItem_t)7)
#define ESmsMenuOnMyWay        ((EUiSmsMenuItem_t)8)
#define ESmsMenuRunLate        ((EUiSmsMenuItem_t)9)
#define ESmsMenuOkay        ((EUiSmsMenuItem_t)10)
#define ESmsMenuYes        ((EUiSmsMenuItem_t)11)
#define ESmsMenuNo        ((EUiSmsMenuItem_t)12)
#define ESmsMenuWrAreYou        ((EUiSmsMenuItem_t)13)
#define ESmsMenuMcanWhen        ((EUiSmsMenuItem_t)14)

typedef uint8_t ETelMenuItem_t;
#define ETelNone        ((ETelMenuItem_t)0)
#define ETelAnswer        ((ETelMenuItem_t)1)
#define ETelDecline        ((ETelMenuItem_t)2)
#define ETelEndCall        ((ETelMenuItem_t)3)
#define ETelUseHandset        ((ETelMenuItem_t)4)
#define ETelEnterDigit        ((ETelMenuItem_t)5)
#define ETelMute        ((ETelMenuItem_t)6)
#define ETelSwitchCall        ((ETelMenuItem_t)7)
#define ETelHold        ((ETelMenuItem_t)8)

typedef uint8 data_u8_75[75];

typedef uint8_t EPhoneIndCbEnum_t;
#define ESmsRxIndicationCb        ((EPhoneIndCbEnum_t)0)
#define EVRRxIndicationCb        ((EPhoneIndCbEnum_t)1)
#define ETelRxIndicationCb        ((EPhoneIndCbEnum_t)2)

typedef uint8_t EMcanChannelState_t;
#define EWaitForChanOpen        ((EMcanChannelState_t)0)
#define EWaitingConfig        ((EMcanChannelState_t)1)
#define EConnOpen        ((EMcanChannelState_t)2)

typedef uint16 data_u16_3[3];

typedef uint16 data_u16_6[6];

typedef uint16 data_u16_15[15];

typedef uint8 data_u8_280[280];

typedef uint8_t EAudioIndCbEnum_t;
#define EAudioSourceAvailableRxIndication        ((EAudioIndCbEnum_t)0)
#define EAudioSourceSelRxIndicationCb        ((EAudioIndCbEnum_t)1)
#define EAudioWarningRxIndicationCb        ((EAudioIndCbEnum_t)2)
#define EAuxRxIndicationCb        ((EAudioIndCbEnum_t)3)
#define EDiscRxIndicationCb        ((EAudioIndCbEnum_t)4)
#define EHDRadioRxIndicationCb        ((EAudioIndCbEnum_t)5)
#define EInternetRxIndicationCb        ((EAudioIndCbEnum_t)6)
#define ERadioRxIndicationCb        ((EAudioIndCbEnum_t)7)

typedef uint8_t ENaviIndCbEnum_t;
#define ENaviStreetNameRxIndicationCb        ((ENaviIndCbEnum_t)0)
#define ENaviGuidanceWithHighWayCb        ((ENaviIndCbEnum_t)1)
#define ENaviRAExitNumber        ((ENaviIndCbEnum_t)2)
#define ENaviArrivalInfo        ((ENaviIndCbEnum_t)3)
#define ENaviLane        ((ENaviIndCbEnum_t)4)
#define ENaviSpeedLimit        ((ENaviIndCbEnum_t)5)
#define ENaviWeather        ((ENaviIndCbEnum_t)6)
#define ENaviSourceAvailable        ((ENaviIndCbEnum_t)7)
#define ENaviSwipe        ((ENaviIndCbEnum_t)8)
#define ENaviCurrentStreetNameRxIndicationCb        ((ENaviIndCbEnum_t)9)
#define ENaviLink        ((ENaviIndCbEnum_t)10)
#define ENaviRoadIcon        ((ENaviIndCbEnum_t)11)

typedef uint8_t EPictureStatusType_t;
#define EPictureStatusType_Unavailable        ((EPictureStatusType_t)0)
#define EPictureStatusType_Available        ((EPictureStatusType_t)1)

typedef uint8_t ESubcriptionServiceAckStatus_t;
#define ESubcriptionServiceAckStatus_ServiceNotDone        ((ESubcriptionServiceAckStatus_t)0)
#define ESubcriptionServiceAckStatus_ServiceDone        ((ESubcriptionServiceAckStatus_t)1)

typedef uint8_t EStreamStatusType_t;
#define EStreamStatusType_Unavailable        ((EStreamStatusType_t)0)
#define EStreamStatusType_Available        ((EStreamStatusType_t)1)
#define EStreamStatusType_LayoutSwitching        ((EStreamStatusType_t)2)
#define EStreamStatusType_OtherSources        ((EStreamStatusType_t)3)
#define EStreamStatusType_NoGuidanceOngoing        ((EStreamStatusType_t)4)
#define EStreamStatusType_Count        ((EStreamStatusType_t)5)

typedef uint8 data_u8_128[128];

typedef uint32 data_u32_50[50];

typedef uint16 data_u16_50[50];

typedef uint8_t EUdsMode_t;
#define EUdsMode_FotaMode        ((EUdsMode_t)0)
#define EUdsMode_DiagMode        ((EUdsMode_t)1)

typedef uint8_t EUdsSession_t;
#define EUdsSession_DefaultSession        ((EUdsSession_t)0)
#define EUdsSession_FotaSession        ((EUdsSession_t)1)

typedef uint8_t EFileModeOfOperation_t;
#define EFileModeOfOperation_AddFile        ((EFileModeOfOperation_t)0)
#define EFileModeOfOperation_DeleteFile        ((EFileModeOfOperation_t)1)
#define EFileModeOfOperation_ReplaceFile        ((EFileModeOfOperation_t)2)
#define EFileModeOfOperation_ReadFile        ((EFileModeOfOperation_t)3)
#define EFileModeOfOperation_ReadDir        ((EFileModeOfOperation_t)4)
#define EFileModeOfOperation_Last        ((EFileModeOfOperation_t)5)

typedef uint8 dataBuffer256[256];

typedef uint8_t EDidAccessType_t;
#define EDidAccessType_DidRead        ((EDidAccessType_t)0)
#define EDidAccessType_DidWrite        ((EDidAccessType_t)1)

typedef uint8_t EGeneralResponseCode_t;
#define EGeneralResponseCode_Success        ((EGeneralResponseCode_t)0)
#define EGeneralResponseCode_Failure        ((EGeneralResponseCode_t)1)

typedef uint8_t EMemDiagRequestCmd_t;
#define EMemDiagRequestCmd_Idle        ((EMemDiagRequestCmd_t)0)
#define EMemDiagRequestCmd_EraseReqSent        ((EMemDiagRequestCmd_t)1)
#define EMemDiagRequestCmd_EraseResRcvd        ((EMemDiagRequestCmd_t)2)
#define EMemDiagRequestCmd_StartDwnReqSent        ((EMemDiagRequestCmd_t)3)
#define EMemDiagRequestCmd_StartDwnResRcvd        ((EMemDiagRequestCmd_t)4)
#define EMemDiagRequestCmd_DwnReqSent        ((EMemDiagRequestCmd_t)5)
#define EMemDiagRequestCmd_DwnResRcvd        ((EMemDiagRequestCmd_t)6)
#define EMemDiagRequestCmd_TfrExitReqSent        ((EMemDiagRequestCmd_t)7)
#define EMemDiagRequestCmd_TfrExitResRcvd        ((EMemDiagRequestCmd_t)8)
#define EMemDiagRequestCmd_DwnStatusReqSent        ((EMemDiagRequestCmd_t)9)
#define EMemDiagRequestCmd_DwnStatusResRcvd        ((EMemDiagRequestCmd_t)10)
#define EMemDiagRequestCmd_ChecksumReqSent        ((EMemDiagRequestCmd_t)11)
#define EMemDiagRequestCmd_ChecksumResRcvd        ((EMemDiagRequestCmd_t)12)
#define EMemDiagRequestCmd_SwitchReqSent        ((EMemDiagRequestCmd_t)13)
#define EMemDiagRequestCmd_SwitchResRcvd        ((EMemDiagRequestCmd_t)14)
#define EMemDiagRequestCmd_RoolbackReqSent        ((EMemDiagRequestCmd_t)15)
#define EMemDiagRequestCmd_RoolbackResRcvd        ((EMemDiagRequestCmd_t)16)
#define EMemDiagRequestCmd_VersionCheckSent        ((EMemDiagRequestCmd_t)17)
#define EMemDiagRequestCmd_VersionCheckRcvd        ((EMemDiagRequestCmd_t)18)

typedef uint8_t EReflashStatus_t;
#define EReflashStatus_Idle        ((EReflashStatus_t)0)
#define EReflashStatus_EraseStart        ((EReflashStatus_t)1)
#define EReflashStatus_EraseDone        ((EReflashStatus_t)2)
#define EReflashStatus_TransferStarted        ((EReflashStatus_t)3)
#define EReflashStatus_TransferInProgress        ((EReflashStatus_t)4)
#define EReflashStatus_FlashStarted        ((EReflashStatus_t)5)
#define EReflashStatus_FlashInProgress        ((EReflashStatus_t)6)
#define EReflashStatus_FlashSucess        ((EReflashStatus_t)7)
#define EReflashStatus_FlashFailed        ((EReflashStatus_t)8)
#define EReflashStatus_ChecksumSucess        ((EReflashStatus_t)9)
#define EReflashStatus_ChecksumFailed        ((EReflashStatus_t)10)
#define EReflashStatus_ReadMetaSucess        ((EReflashStatus_t)11)
#define EReflashStatus_ReadMetaFailed        ((EReflashStatus_t)12)
#define EReflashStatus_SwitchSucess        ((EReflashStatus_t)13)
#define EReflashStatus_SwitchFailed        ((EReflashStatus_t)14)
#define EReflashStatus_RollbackSucess        ((EReflashStatus_t)15)
#define EReflashStatus_RollbackFailed        ((EReflashStatus_t)16)
#define EReflashStatus_WriteMetaSucess        ((EReflashStatus_t)17)
#define EReflashStatus_WriteMetaFailed        ((EReflashStatus_t)18)
#define EReflashStatus_MapAddrFailed        ((EReflashStatus_t)19)
#define EReflashStatus_FileOpenFailed        ((EReflashStatus_t)20)

typedef uint8_t EMemTypeCmd_t;
#define EMemTypeCmd_Nor        ((EMemTypeCmd_t)0)
#define EMemTypeCmd_Emmc        ((EMemTypeCmd_t)1)
#define EMemTypeCmd_Max        ((EMemTypeCmd_t)2)

typedef uint8_t EDidType_t;
#define EDidType_Read        ((EDidType_t)0)
#define EDidType_Write        ((EDidType_t)1)
#define EDidType_Last        ((EDidType_t)2)

typedef uint8 data_u8_300[300];

typedef struct
{
    uint32 storedMainMenuItem;
    uint8 currrentLanguage;
    uint8 currentMode;
    uint8 batteryConnectChk;
    uint8 homeScreenSts;
} SMenuBackUpData_t;

typedef uint32 data_u32_6[6];

typedef struct
{
    uint8 errorCodeInit;
    uint8 illumButtonSts;
    uint8 tripButtonSts;
    uint8 illumButtonStuckSts;
    uint8 tripButtonStuckSts;
} SSelfDiagBackUpData_t;

typedef uint16 data_u16_16[16];

typedef uint8_t ESwipeStates_t;
#define ESwipeStates_Initial        ((ESwipeStates_t)0)
#define ESwipeStates_Sync1Audio        ((ESwipeStates_t)1)
#define ESwipeStates_Sync1Navi        ((ESwipeStates_t)2)
#define ESwipeStates_Sync2Audio        ((ESwipeStates_t)3)
#define ESwipeStates_Sync2Navi        ((ESwipeStates_t)4)
#define ESwipeStates_Sync3Audio        ((ESwipeStates_t)5)
#define ESwipeStates_Sync3Navi        ((ESwipeStates_t)6)
#define ESwipeStates_EndAudio        ((ESwipeStates_t)7)
#define ESwipeStates_EndNavi        ((ESwipeStates_t)8)

typedef uint8 data_u8_35[35];

typedef uint8 data_u8_12[12];

typedef uint8_t EnetReqCmd_t;
#define EnetReqType_Reset        ((EnetReqCmd_t)1)
#define EnetReqType_linkStatus        ((EnetReqCmd_t)2)
#define EnetReqType_SqiVal        ((EnetReqCmd_t)3)
#define EnetReqType_WorstSqiVal        ((EnetReqCmd_t)4)
#define EnetReqType_BestSqiVal        ((EnetReqCmd_t)5)
#define EnetReqType_FaultStatus        ((EnetReqCmd_t)6)
#define EnetReqType_CableStatus        ((EnetReqCmd_t)7)
#define EnetReqType_masterSlaveStatus        ((EnetReqCmd_t)8)
#define EnetReqType_Last        ((EnetReqCmd_t)9)

typedef uint8_t EnetReqMode_t;
#define EnetReqMode_Read        ((EnetReqMode_t)0)
#define EnetReqMode_Write        ((EnetReqMode_t)1)
#define EnetReqMode_Last        ((EnetReqMode_t)2)

typedef uint8_t ELayoutErrorState_t;
#define ENoLayoutTimeout        ((ELayoutErrorState_t)0)
#define ELayoutTimeout        ((ELayoutErrorState_t)1)

typedef struct
{
    uint8_t compId;
    uint8_t msgCnt;
} DKMsgBase_t;

typedef struct
{
    DKMsgBase_t base;
    uint8 visible;
    uint16 warningId;
} WarningStatus;

typedef struct
{
    DKMsgBase_t base;
    uint8 status;
} WarningDisplayAvailable;

typedef struct
{
    DKMsgBase_t base;
    uint8 show;
    uint16 warningId;
    data_u8_4 dynData;
} WarningDisplay;

typedef struct
{
    DKMsgBase_t base;
    uint8 show;
    uint16 warningId;
    data_u8_70 dynData;
} WarningExtDisplay;

typedef struct
{
    DKMsgBase_t base;
    uint8 domainId;
    uint32 compIdx;
} HealthDomainFatalError;

typedef struct
{
    DKMsgBase_t base;
    uint8 domainId;
    uint32 seqCnt;
} HealthDomainHeartbeat;

typedef struct
{
    DKMsgBase_t base;
    EDomainId_t domainId;
    ESystemState_t state;
} PowerSystemState;

typedef struct
{
    DKMsgBase_t base;
    EDomainId_t domainId;
    uint32 timeoutMs;
} PowerExtendShutdownTime;

typedef struct
{
    DKMsgBase_t base;
    EDomainId_t domainId;
    uint32 timeoutMs;
} PowerKeepSystemAwake;

typedef struct
{
    DKMsgBase_t base;
    EDomainId_t domainId;
    ESystemState_t state;
} PowerSystemStateReqChange;

typedef struct
{
    DKMsgBase_t base;
    data_u8_32 mask;
} RTT_Status;

typedef struct
{
    DKMsgBase_t base;
    data_u8_15 VIPTTStsMsg;
} TT_statusVIP;

typedef struct
{
    DKMsgBase_t base;
    ECompState_t state;
} PowerReportCompState;

typedef struct
{
    DKMsgBase_t base;
    sint32 errorCode;
} UCL_ERROR_NOTIFY;

typedef struct
{
    DKMsgBase_t base;
    sint32 status;
} UCL_LINK_STATUS;

typedef struct
{
    DKMsgBase_t base;
    uint8 enable;
    uint32 requiredTimeMs;
} PowerSystemStateReqWakeLock;

typedef struct
{
    DKMsgBase_t base;
    uint8 positions;
    uint8 display;
} RTT_Toggle;

typedef struct
{
    DKMsgBase_t base;
    data_u8_32 mask;
} FRTT_Status;

typedef struct
{
    DKMsgBase_t base;
    uint32 displayId;
} DisplayGetState;

typedef struct
{
    DKMsgBase_t base;
    uint32 displayId;
    EDisplayPower_t state;
} DisplaySetPower;

typedef struct
{
    DKMsgBase_t base;
    EOdoStatus_t status;
    uint32 value;
    uint8 unit;
} Odometer;

typedef struct
{
    DKMsgBase_t base;
    ECompassValue_t value;
} CompassInfo;

typedef struct
{
    DKMsgBase_t base;
    uint32 displayId;
    EDisplayStatus_t state;
} DisplayCurrentState;

typedef struct
{
    DKMsgBase_t base;
    SDateTime dateTime;
} RTC;

typedef struct
{
    DKMsgBase_t base;
    uint32 chunkSize;
    data_u8_32 data;
} HealthDumpData;

typedef struct
{
    DKMsgBase_t base;
    uint32 fileSize;
} HealthDumpHdrInfo;

typedef struct
{
    DKMsgBase_t base;
    uint8 encrypt;
} HealthDumpGetHdr;

typedef struct
{
    DKMsgBase_t base;
    uint8 reserved;
} HealthDumpGetData;

typedef struct
{
    DKMsgBase_t base;
    uint8 responseCode;
    uint16 dataLen;
    data_u8_256 data;
} DiagResponse;

typedef struct
{
    DKMsgBase_t base;
    uint16 routineId;
    ERoutineType_t routineType;
    uint16 dataLen;
    data_u8_320 data;
} DiagRoutineRequest;

typedef struct
{
    DKMsgBase_t base;
    uint16 did;
    EIOCtrlOptType_t optionCtrl;
    uint16 dataLen;
    data_u8_256 data;
} DiagIOCtrlRequest;

typedef struct
{
    DKMsgBase_t base;
    ETripCmd_t tripCmdId;
} TripResetCmd;

typedef struct
{
    DKMsgBase_t base;
    ETrip_t tripId;
    uint8 hour;
    uint8 minute;
    uint8 second;
    uint32 distance;
    uint32 distanceEV;
    uint8 distanceUnit;
    uint16 avgFuel;
    uint16 avgFuelEV;
    uint16 avgSpeed;
    uint8 valid;
} TripComputer;

typedef struct
{
    DKMsgBase_t base;
    EFuelEconomy_t feType;
    uint16 value;
    uint8 valid;
    data_u8_5 dynData;
} FuelEconomy;

typedef struct
{
    DKMsgBase_t base;
    EPhoneCmd_t callCmd;
} PhoneCmd;

typedef struct
{
    DKMsgBase_t base;
    uint8 muteStatus;
    EPhoneStatus_t phoneStatus;
    data_u8_36 callerName;
    EStringEncoding_t callerNameEncodingType;
    data_u8_25 callerNumber;
    uint16 callDuration;
    EPhoneCmd_t callCmd;
} PhoneData;

typedef struct
{
    DKMsgBase_t base;
    uint8 eprndl;
    uint8 manual;
    uint8 sst;
    data_u16_10 sstRange;
    uint8 dynData;
} GearStatus;

typedef struct
{
    DKMsgBase_t base;
    EIgnitionStatus_t state;
} IgnState;

typedef struct
{
    DKMsgBase_t base;
    uint32 timestamp;
    uint16 dataLen;
    data_u8_256 data;
} HealthStatusReport;

typedef struct
{
    DKMsgBase_t base;
    uint8 compIdx;
} HealthGetStatus;

typedef struct
{
    DKMsgBase_t base;
    uint8 status;
} HMIStatus;

typedef struct
{
    DKMsgBase_t base;
    uint8 type;
    uint8 level;
    uint8 status;
} ControlPopup;

typedef struct
{
    DKMsgBase_t base;
    data_u8_5 data;
} ETMStatus;

typedef struct
{
    DKMsgBase_t base;
    uint8 id;
    data_u8_50 data;
} ETMData;

typedef struct
{
    DKMsgBase_t base;
    uint8 status;
} WelcomeResponse;

typedef struct
{
    DKMsgBase_t base;
    uint8 SUSDState;
    uint8 WelcomeScreenState;
    uint8 FarewellScreenState;
} WelcomeFarewallData;

typedef struct
{
    DKMsgBase_t base;
    EButtonId_t buttonId;
    EButtonState_t buttonStatus;
    uint8 holdTime;
} SWC;

typedef struct
{
    DKMsgBase_t base;
    uint8 id;
    uint8 position;
    uint8 mask;
} SSTM;

typedef struct
{
    DKMsgBase_t base;
    uint8 id;
    uint8 mode;
    uint16 mask;
} SDM;

typedef struct
{
    DKMsgBase_t base;
    uint8 id;
    uint8 position;
    uint8 mask;
} SSM;

typedef struct
{
    DKMsgBase_t base;
    uint8 status;
    uint8 backupAssist;
    uint8 reverseGuidance;
    uint8 blindSpot;
    data_u8_8 accumulatedDistanceStr;
    data_u8_6 fuleEconomyStr;
    data_u8_32 trailerName;
} TrailerInfo;

typedef struct
{
    DKMsgBase_t base;
    uint8 value;
} EngineAirFilterState;

typedef struct
{
    DKMsgBase_t base;
    uint8 activeDispayMask;
    uint8 reqPowerPercent;
    uint8 evModeThesholdPowerPercent;
    uint8 regenModeThesholdPowerPercent;
} EVCoachState;

typedef struct
{
    DKMsgBase_t base;
    uint16 mask;
} TrailerLighting;

typedef struct
{
    DKMsgBase_t base;
    uint8 active;
    uint8 PFS;
} DieselPRTCFilterState;

typedef struct
{
    DKMsgBase_t base;
    uint8 activeStartStopDisplay;
} AutoStartStopState;

typedef struct
{
    DKMsgBase_t base;
    uint8 defActive;
    uint16 defRange;
    uint8 defMask;
    uint8 defSpeedLimit;
} DieselExhaustState;

typedef struct
{
    DKMsgBase_t base;
    uint16 hours;
    uint16 idleHours;
    uint8 value;
} EngineInfo;

typedef struct
{
    DKMsgBase_t base;
    uint8 status;
    uint8 thresholdStatus;
    uint8 tireCntStatus;
    uint8 tirePressureNumColor;
    uint8 tireTemperatureNumColor;
    uint8 warningStatus;
    uint8 tireTempPressColor;
} TrailerTPMSState;

typedef struct
{
    DKMsgBase_t base;
    uint8 text1;
    uint8 text2;
    uint16 value1;
    uint16 value2;
    uint16 value3;
} DieselAdBlueState;

typedef struct
{
    DKMsgBase_t base;
    uint8 steeringWheelAngle;
    uint8 pitchAngle;
    uint8 rollAngle;
} SPRStatus;

typedef struct
{
    DKMsgBase_t base;
    uint16 value;
} AirFuelRatioState;

typedef struct
{
    DKMsgBase_t base;
    uint8 frontPercentFill;
    uint8 backPercentFill;
    uint8 displayAnimation;
} PowerDisState;

typedef struct
{
    DKMsgBase_t base;
    uint8 id;
    uint8 RTTStatus;
    uint8 dynData;
} DASGenData;

typedef struct
{
    DKMsgBase_t base;
    uint8 id;
    uint8 speedLimitIndication1;
    uint8 speedLimitValue;
    uint8 speedLimitIndication2;
    data_u8_2 dynData;
} TrafficSignRecognition;

typedef struct
{
    DKMsgBase_t base;
    uint8 assistStatus;
    uint8 RTTStatus;
    uint8 markerStatus;
} LaneKeepAssist;

typedef struct
{
    DKMsgBase_t base;
    uint8 reasonIcon;
    uint8 adviceIcon;
    uint8 adviceIconColor;
    uint8 speedLimit;
} EcoAdvice;

typedef struct
{
    DKMsgBase_t base;
    uint8 tjaStatus;
    uint8 DAStatus;
    uint8 laneBias;
} TrafficJamAssist;

typedef struct
{
    DKMsgBase_t base;
    uint8 id;
    uint8 mode;
    data_u8_9 dynData;
} DriverAssistData;

typedef struct
{
    DKMsgBase_t base;
    uint16 value;
    EGaugeUnit_t unit;
    EOatStatus_t status;
} OAT;

typedef struct
{
    DKMsgBase_t base;
    uint8 status;
} GearAnimStatus;

typedef struct
{
    DKMsgBase_t base;
    uint8 accelScore;
    uint8 decelScore;
    uint8 cruiseScore;
    uint8 shiftScore;
    uint16 currentTrip;
    uint8 currentTripUnits;
    uint16 lastTrip;
    uint8 lastTripUnits;
    uint8 msgTextId;
    uint8 validMask;
} EVCoachTripState;

typedef struct
{
    DKMsgBase_t base;
    uint8 tireTempUnit;
    uint8 tireTempStat;
    uint16 lfTireTemp;
    uint16 rfTireTemp;
    uint16 lrTireTemp;
    uint16 rrTireTemp;
} TireTempState;

typedef struct
{
    DKMsgBase_t base;
    uint8 steeringWheelAngle;
    uint8 pitchAngle;
    uint8 rollAngle;
} OffRoadState;

typedef struct
{
    DKMsgBase_t base;
    uint8 id;
    uint8 status;
    uint8 unit;
    uint16 value;
} IODGaugeData;

typedef struct
{
    DKMsgBase_t base;
    uint8 display;
    uint8 counter;
} DriverAssistDisplay;

typedef struct
{
    DKMsgBase_t base;
    uint8 value;
} ExtETMStatus;

typedef struct
{
    DKMsgBase_t base;
    data_u8_2 dynData;
} IODSettings;

typedef struct
{
    DKMsgBase_t base;
    uint8 active;
} LHIStatus;

typedef struct
{
    DKMsgBase_t base;
    uint8 value;
} MaintStatus;

typedef struct
{
    DKMsgBase_t base;
    EMediaText_t id;
    data_u8_40 text;
    EStringEncoding_t type;
} MediaText;

typedef struct
{
    DKMsgBase_t base;
    uint16 AMFreq;
    uint16 FMFreq;
    uint8 valid;
} RadioData;

typedef struct
{
    DKMsgBase_t base;
    uint16 channelNumber;
    data_u8_130 title;
    EStringEncoding_t titleType;
    uint8 valid;
} SDARSData;

typedef struct
{
    DKMsgBase_t base;
    EMediaText_t id;
    data_u8_130 text;
    EStringEncoding_t type;
} MediaTextExt;

typedef struct
{
    DKMsgBase_t base;
    uint8 naviCmd;
} NaviCmd;

typedef struct
{
    DKMsgBase_t base;
    data_u8_42 streetName;
    EStringEncoding_t streetNameType;
    uint8 active;
    uint8 turnIconId;
    uint8 speedLimitValue;
    uint8 navBarGraphSteps;
    uint16 naviDistanceWhole;
    uint16 naviDistanceTenth;
    uint8 naviDistanceUnit;
} NaviData;

typedef struct
{
    DKMsgBase_t base;
    uint8 speedlockstatus;
} SpeedLockStatus;

typedef struct
{
    DKMsgBase_t base;
    uint8 speedstatus;
} SetupSpeed;

typedef struct
{
    DKMsgBase_t base;
    uint8 dtehistoryused;
} DTEHistory;

typedef struct
{
    DKMsgBase_t base;
    EFuelEconomy_t feType;
    uint16 value;
    uint8 unit;
    uint8 valid;
    data_u8_5 dynData;
} DistanceToEmpty;

typedef struct
{
    DKMsgBase_t base;
    uint8 count;
    uint8 seatselection;
    uint8 seatselectionvalue;
} RearBeltMonitor;

typedef struct
{
    DKMsgBase_t base;
    uint8 mode;
    uint8 unit;
    EDisplayHMIStatus_t status;
    uint8 value;
} RangeDisplay;

typedef struct
{
    DKMsgBase_t base;
    data_u8_3 dynData;
} GALCarPlayData;

typedef struct
{
    DKMsgBase_t base;
    uint8 listCmd;
} ListCmd;

typedef struct
{
    DKMsgBase_t base;
    uint8 timeout;
} ListTimeout;

typedef struct
{
    DKMsgBase_t base;
    uint8 AWDGauge_FrontLeftPixelFill;
    uint8 AWDGauge_FrontRightPixelFill;
    uint8 AWDGauge_RearLeftPixelFill;
    uint8 AWDGauge_RearRightPixelFill;
} AWDGaugeData;

typedef struct
{
    DKMsgBase_t base;
    uint16 efficiency;
    uint8 efficiencyStatus;
    uint8 range;
    uint8 rangeStatus;
} ElectricEfficiencyFunction;

typedef struct
{
    DKMsgBase_t base;
    EUdsTimeout_t timeoutType;
    uint16 clientAddress;
} UdsTimeout;

typedef struct
{
    DKMsgBase_t base;
    uint8 serviceId;
    uint8 responseType;
    uint16 clientAddress;
} UdsServiceResponseTransmitConfirmation;

typedef struct
{
    DKMsgBase_t base;
    uint16 sourceAddress;
    uint16 targetAddress;
    uint8 targetAddressType;
    uint16 dataLen;
    data_u8_7168 data;
    uint8 result;
} DoipDiagDataTransferRequest;

typedef struct
{
    DKMsgBase_t base;
    uint16 sourceAddress;
    uint16 targetAddress;
    uint8 targetAddressType;
    uint16 dataLen;
    data_u8_7168 data;
    uint8 result;
} DoipDiagDataIndication;

typedef struct
{
    DKMsgBase_t base;
    uint8 serviceId;
    uint8 responseType;
    uint16 clientAddress;
    uint16 dataLen;
    data_u8_7168 data;
} UdsServiceResponseTransmitRequest;

typedef struct
{
    DKMsgBase_t base;
    uint16 sourceAddress;
    uint16 targetAddress;
    uint8 targetAddressType;
    uint8 result;
} DoipDiagDataConfirmation;

typedef struct
{
    DKMsgBase_t base;
    uint32 p2TimeMs;
    uint32 p2StarTimeMs;
    uint32 p4TimeMs;
} UdsServiceSetTimings;

typedef struct
{
    DKMsgBase_t base;
    data_u8_17 vinNumber;
    data_u8_6 eidNumber;
    data_u8_6 gidNumber;
    uint8 isVinNumValid;
    uint8 isGidNumValid;
    uint8 isEidNumValid;
    SDoIPSetNetworkInformation ipConfig;
    uint8 isNetWorkConfigValid;
    uint8 gidSyncStatus;
    uint8 isGidSyncStatusValid;
} DoipSetParams;

typedef struct
{
    DKMsgBase_t base;
    uint8 serviceId;
    uint8 requestType;
    uint16 clientAddress;
    uint16 dataLen;
    data_u8_7168 data;
} UdsServiceReqIndication;

typedef struct
{
    DKMsgBase_t base;
    uint8 powerMode;
} DoipDiagPowerModeStatus;

typedef struct
{
    DKMsgBase_t base;
    EIgnitionStatus_t ignStatus;
    EPWUSCurrentVehicleState_t vehicleStatus;
    EWUSCurrentAccState_t ACCStatus;
} IgnStateStatus;

typedef struct
{
    DKMsgBase_t base;
    data_u8_3584 cmdData;
} HmiCmdData;

typedef struct
{
    DKMsgBase_t base;
    data_u16_10 warnAckStatus;
} WarningAckStatus;

typedef struct
{
    DKMsgBase_t base;
    data_u8_130 warnNotifyStatus;
} WarningNotifyStatus;

typedef struct
{
    DKMsgBase_t base;
    uint8 clearIllumPopupRetrigger;
    uint8 cruiseSlPopupEvt;
    uint8 cancelReasonPopUpEvt;
    uint8 rearSeatbeltDisplayStatus;
    uint8 rearSeatBeltAckEvent;
    uint16 buttonEventsToMCAN;
    uint8 BFEUpdateEvent;
    uint8 ZoneP2ActiveStatus;
} PopupAckResponse;

typedef struct
{
    DKMsgBase_t base;
    uint8 odoResetEvt;
} TripOdoResetEvent;

typedef struct
{
    DKMsgBase_t base;
    uint8 rearSeatBeltStatus;
} RearSeatBeltStatus;

typedef struct
{
    DKMsgBase_t base;
    uint8 currentScreenID;
    uint32 currentMainMenu;
} GFXScreenID;

typedef struct
{
    DKMsgBase_t base;
    EOpeningMovieAnimStatus_t openingMovieRunningStatus;
    EITSOpngMovieOnDisplay_t ITS_ScreenDisplayStatus;
    uint8 keyPressEventDuringOpngMoive;
} OpeningMovieResponse;

typedef struct
{
    DKMsgBase_t base;
    data_u8_65 warnStatus;
    data_u8_60 warnPayload;
} WarningDisplayStatus;

typedef struct
{
    DKMsgBase_t base;
    uint32 value;
    uint32 tripAvalue;
    uint32 tripBvalue;
    data_u32_3 tripDistance;
} OdometerStatus;

typedef struct
{
    DKMsgBase_t base;
    uint32 totalSystemMemory;
} TotalSystemMemoryStatus;

typedef struct
{
    DKMsgBase_t base;
    data_u8_1024 animationStatus;
} HmiAnimationStatus;

typedef struct
{
    DKMsgBase_t base;
    uint8 gfxCmdStatus;
} HmiGfxCmdQueueRcvd;

typedef struct
{
    DKMsgBase_t base;
    uint32 rendrerStatus;
} HmiRendrerStatus;

typedef struct
{
    DKMsgBase_t base;
    data_u8_5 popupStatus;
    data_u8_5 popupRetriggerStatus;
    data_u8_5 popupPayload;
} PopupStatusData;

typedef struct
{
    DKMsgBase_t base;
    uint8 hour;
    uint8 minute;
    uint8 mode;
    uint8 currentClockMenuType;
    uint8 clockDisplaySts;
} CurrentTimeDisplay;

typedef struct
{
    DKMsgBase_t base;
    uint8 OATvalue;
} OutsideAirTemperature;

typedef struct
{
    DKMsgBase_t base;
    uint8 currentTempUnit;
    uint8 currentDistanceUnit;
    uint8 currentFuelUnit;
    uint8 currentTPMSUnit;
    uint8 currentLanguage;
} UnitLanguageSettings;

typedef struct
{
    DKMsgBase_t base;
    data_u8_60 telltaleStatus;
    data_u8_60 indicatorStatus;
    data_u8_25 indicatorPayload;
} TTIndicatorStatus;

typedef struct
{
    DKMsgBase_t base;
    data_u8_25 featureConfigSts;
} ModuleConfigStatus;

typedef struct
{
    DKMsgBase_t base;
    EPOpeningMovieStatus_t openingMovieStatus;
    EPITSOpngMovieStatus_t ITSstatus;
} OpeningMovieData;

typedef struct
{
    DKMsgBase_t base;
    EPButtonId_t buttonId;
    EPButtonState_t buttonStatus;
} StrButtonStatus;

typedef struct
{
    DKMsgBase_t base;
    EPButtonId_t buttonId;
    EPButtonState_t buttonStatus;
    EPButtonState_t switchStatus;
} ButtonStatusETM;

typedef struct
{
    DKMsgBase_t base;
    EPButtonId_t buttonId;
    EPButtonState_t buttonStatus;
} StrButtonEvents;

typedef struct
{
    DKMsgBase_t base;
    EPButtonId_t buttonId;
    EButtonState_t buttonStatus;
} TripButtonEvents;

typedef struct
{
    DKMsgBase_t base;
    EPButtonId_t buttonId;
    EPIllumButtonEvent_t buttonStatus;
} IllumButtonEvents;

typedef struct
{
    DKMsgBase_t base;
    uint16 DTEValue;
    uint8 DTEWarningStatus;
} DistanceToEmptyStatus;

typedef struct
{
    DKMsgBase_t base;
    uint8 gaugeSceneRendered;
} GaugeSceneStatus;

typedef struct
{
    DKMsgBase_t base;
    EVidioPlayerStatusType_t videoPlayerStatus;
} VideoPlayerStatus;

typedef struct
{
    DKMsgBase_t base;
    EPictureCopyStatusType_t pictureCopyStatus;
} PictureCopyStatus;

typedef struct
{
    DKMsgBase_t base;
    uint32 SystemMemoryFreeStatus;
} SystemMemoryTotal;

typedef struct
{
    DKMsgBase_t base;
    uint8 serviceId;
    uint32 Data;
    uint8 status;
} SwUpdateResponse;

typedef struct
{
    DKMsgBase_t base;
    EFotaSlaveResponse_t fotaSlaveResponse;
    EInstallerFotaState_t installerState;
} FotaChangeResponse;

typedef struct
{
    DKMsgBase_t base;
    uint8 gipDowngradeCheckSts;
    uint8 majVer;
    uint8 minVer;
    uint8 nvmVer;
} FotaVersionNotify;

typedef struct
{
    DKMsgBase_t base;
    EFotaSlaveResponse_t fotaSlaveResponse;
    EInstallerReq_t requestType;
} FotaCommandResponse;

typedef struct
{
    DKMsgBase_t base;
    uint8 vinreq;
} FotaVinRequest;

typedef struct
{
    DKMsgBase_t base;
    uint8 statereq;
} FotaStateRequest;

typedef struct
{
    DKMsgBase_t base;
    EInstallerNotif_t notifType;
} FotaStateNotify;

typedef struct
{
    DKMsgBase_t base;
    ELinkStatus_t interfaceRequestType;
    uint8 interfaceNameLength;
    data_u8_256 interfaceName;
} NetworkModifyLinkStatus;

typedef struct
{
    DKMsgBase_t base;
    EVlanRequestType_t requestType;
    uint8 vlanNameLength;
    data_u8_256 vlanName;
    uint16 vlanTag;
    uint8 interfaceNameLength;
    data_u8_256 interfaceName;
    uint8 vlanPriority;
} NetworkModifyVlanInterface;

typedef struct
{
    DKMsgBase_t base;
    EModifyInterfaceReqType_t requestType;
    uint8 interfaceNameLength;
    data_u8_256 interfaceName;
    ELinkStatus_t linkStatus;
    uint8 ipAddressLength;
    data_u8_256 ipAddress;
    uint8 netMaskLength;
    data_u8_256 netMask;
    uint8 broadcastAddressLength;
    data_u8_256 broadcastAddress;
} NetworkModifyInterface;

typedef struct
{
    DKMsgBase_t base;
    uint8 swPartId;
    uint8 serviceId;
} SwUpdateEraseSwPartReq;

typedef struct
{
    DKMsgBase_t base;
    uint32 bufferId;
    uint32 startAddress;
    uint32 dataLen;
    uint8 serviceId;
} SwUpdateDataTransferReq;

typedef struct
{
    DKMsgBase_t base;
    uint8 swPartId;
    uint32 startAddress;
    uint32 length;
    uint8 serviceId;
} SwUpdateDownloadSwPartReq;

typedef struct
{
    DKMsgBase_t base;
    uint8 swPartId;
    uint32 startAddress;
    uint32 bufferId;
    uint32 dataLen;
    uint32 length;
    uint8 serviceId;
} SwUpdateUploadSwPartReq;

typedef struct
{
    DKMsgBase_t base;
    EInstallerFotaState_t state;
} FotaStateResponse;

typedef struct
{
    DKMsgBase_t base;
    EInstallerFotaState_t state;
} FotaChangeRequest;

typedef struct
{
    DKMsgBase_t base;
    data_u8_17 vin;
} FotaVinResponse;

typedef struct
{
    DKMsgBase_t base;
    EInstallerReq_t reqType;
} FotaCommandRequest;

typedef struct
{
    DKMsgBase_t base;
    uint8 interfaceNameLength;
    data_u8_256 interfaceName;
    ELinkStatus_t linkStatus;
    uint8 ipAddressLength;
    data_u8_256 ipAddress;
} NetworkInterfaceStatus;

typedef struct
{
    DKMsgBase_t base;
    EMemCtrlShMem_t bankId;
    uint32 size;
    EMemCtrlCmd_t resp;
} FotaMemCtrlRespData;

typedef struct
{
    DKMsgBase_t base;
    EMemCtrlShMem_t bankId;
    uint32 offset;
    uint32 size;
    EMemCtrlCmd_t cmd;
} FotaMemCtrlReqData;

typedef struct
{
    DKMsgBase_t base;
    uint8 resetTripDistance;
} TripDistResetCmd;

typedef struct
{
    DKMsgBase_t base;
    uint8 resetAVS;
} AVSResetCmd;

typedef struct
{
    DKMsgBase_t base;
    uint8 resetIdleStop;
} IdleStopResetCmd;

typedef struct
{
    DKMsgBase_t base;
    uint8 resetAFE;
} AFEResetCmd;

typedef struct
{
    DKMsgBase_t base;
    uint8 resetTripTime;
} TripTimeResetCmd;

typedef struct
{
    DKMsgBase_t base;
    uint8 ignOffPersonalMenuEvent;
} IgnOffPersonalMenuAnimEvent;

typedef struct
{
    DKMsgBase_t base;
    uint8 opngMovieEvent;
} OpngMovieAnimEvent;

typedef struct
{
    DKMsgBase_t base;
    uint16 currentBulbTestStatus;
} CurrentBulbCheckStatus;

typedef struct
{
    DKMsgBase_t base;
    uint8 modeChangeEvent;
} ModeChangeAnimEvent;

typedef struct
{
    DKMsgBase_t base;
    uint8 ignOnPersonalMenuEvent;
} IgnOnPersonalMenuAnimEvent;

typedef struct
{
    DKMsgBase_t base;
    uint16 currentETMState;
} CurrentETMStatus;

typedef struct
{
    DKMsgBase_t base;
    uint8 sleepStatus;
    uint8 HMIReady;
} HMISleepStatus;

typedef struct
{
    DKMsgBase_t base;
    uint8 HMIDoorAjarMenuStatus;
} IGNOffMenuTimeoutStatus;

typedef struct
{
    DKMsgBase_t base;
    uint8 powerONStatus;
} HMIPowerONStatus;

typedef struct
{
    DKMsgBase_t base;
    SKeyVal data;
} PersRecordCmd;

typedef struct
{
    DKMsgBase_t base;
    EAudioSourceList_t audioSourceSelect;
} AudioSourceSelData;

typedef struct
{
    DKMsgBase_t base;
    uint8 smsAckevent;
    EUiSmsMenuItem_t smsSelEvent;
    ETelMenuItem_t telSelEvent;
    uint8 phoneRspData;
} PhoneDataResponse;

typedef struct
{
    DKMsgBase_t base;
    uint16 rcvdDataLength;
    data_u8_75 rcvdData;
    EPhoneIndCbEnum_t phoneIndCbEnum;
} PhoneIndData;

typedef struct
{
    DKMsgBase_t base;
    EMcanChannelState_t audioChannelStatus;
} AudioChannelData;

typedef struct
{
    DKMsgBase_t base;
    data_u8_3 tripTimeMinsOrHours;
    data_u8_3 tripTimeSecsOrMins;
    data_u16_3 averageSpeed;
    data_u8_3 vehicleMovedStatus;
    uint8 isVehicleIdling;
} TripComputerData;

typedef struct
{
    DKMsgBase_t base;
    uint16 IFEValue;
    uint16 BFEValue;
    uint16 rechargeMileValue;
    data_u16_3 AFEValue;
    data_u16_6 HFEValue;
    data_u16_15 HFE2MinValue;
} FuelEconomyData;

typedef struct
{
    DKMsgBase_t base;
    uint8 defaultSpeedUnit;
    uint16 digiSpeedValueInKMPH;
    uint16 digiSpeedValueInMPH;
    uint16 speedValueInKMPH;
    uint16 speedValueInMPH;
    uint16 vehicleSpeedDisplayedinkmh_Value;
    uint8 vehicleSpeedDisplayedinkmh_Status;
    uint16 vehicleSpeedDisplayedinmph_Value;
    uint8 vehicleSpeedDisplayedinmph_Status;
} SpeedData;

typedef struct
{
    DKMsgBase_t base;
    uint16 engineRPMValue;
} TachoData;

typedef struct
{
    DKMsgBase_t base;
    uint8 engineTempValue;
} EctData;

typedef struct
{
    DKMsgBase_t base;
    uint16 fuelFLPSValue;
    uint8 currentFuelSensorStatus;
} FuelData;

typedef struct
{
    DKMsgBase_t base;
    uint8 currentEMSStatus;
} EMSStatus;

typedef struct
{
    DKMsgBase_t base;
    uint8 personalizedAvgSpeedStatus;
    uint8 personalizedFuelEconomyStatus;
    uint8 personalizedListSettingStatus;
    uint8 personalizedTripStatus;
    uint8 currentIkeyS;
    uint16 TPMSResetTimeoutEvt;
} PersonalizedAverageSpeedStatus;

typedef struct
{
    DKMsgBase_t base;
    uint8 currentAccelMenuAvailability;
    uint8 currentEcoRankMenuAvailability;
    uint8 ecoNonEcoThershold;
    uint8 ecoSuperEcoThershold;
    uint8 accelGuideRatio;
    uint16 hysteresisVehicleSpeed;
    uint8 ecoRankNumberOfStars;
    uint8 ecoIndicatorCurrentValue;
    uint8 TPMSEcoAdviceStatus;
    uint8 ecoIndicatorSettingsVal;
    uint8 accelEcoAvailability;
} AccelGuideValue;

typedef struct
{
    DKMsgBase_t base;
    uint8 boostPressure;
    uint8 VCRCompressionRatio;
} VCRStatus;

typedef struct
{
    DKMsgBase_t base;
    uint8 ICCSwipeEvent;
} ICCDynamicMenuStatus;

typedef struct
{
    DKMsgBase_t base;
    uint8 enterOrExitClockMenu;
} ClockMenuEnterExitEvent;

typedef struct
{
    DKMsgBase_t base;
    uint8 TPMSResetSuccessEvt;
} TpmsSettingsResetSuccessEvt;

typedef struct
{
    DKMsgBase_t base;
    data_u8_3 cumulativeIdleStopTime;
    data_u8_3 tripIdleStopTime;
    data_u16_3 vehicleLifeTime;
    uint32 idleStopCo2CLTSavedVolume;
    uint32 idleStopCo2VLTSavedVolume;
    uint32 idleStopFuelConsumption;
    uint8 idleStopActivationStatus;
} IdleStopData;

typedef struct
{
    DKMsgBase_t base;
    data_u8_50 menuPayload;
} MenuPayloadData;

typedef struct
{
    DKMsgBase_t base;
    uint16 nvmEEPROMVersion;
    uint16 mfgModeReq;
} NvmData;

typedef struct
{
    DKMsgBase_t base;
    uint16 rcvdDataLength;
    data_u8_280 rcvdData;
    EAudioIndCbEnum_t audioIndCbEnum;
} AudioIndData;

typedef struct
{
    DKMsgBase_t base;
    uint8 audioInitStatus;
} AudioInitData;

typedef struct
{
    DKMsgBase_t base;
    uint16 rcvdDataLength;
    data_u8_75 rcvdData;
    ENaviIndCbEnum_t naviIndCbEnum;
} NaviIndData;

typedef struct
{
    DKMsgBase_t base;
    uint8 naviInitStatus;
} NaviInitData;

typedef struct
{
    DKMsgBase_t base;
    EMcanChannelState_t naviChannelStatus;
} NaviChannelData;

typedef struct
{
    DKMsgBase_t base;
    EPButtonId_t buttonId;
    EPButtonState_t buttonStatus;
} TelButtonEvents;

typedef struct
{
    DKMsgBase_t base;
    EPictureStatusType_t pictureStatus;
} PictureDisplayStatus;

typedef struct
{
    DKMsgBase_t base;
    ESubcriptionServiceAckStatus_t subscriptionStatus;
} MapSubscriptionStatus;

typedef struct
{
    DKMsgBase_t base;
    EStreamStatusType_t streamStatus;
} StreamStatusType;

typedef struct
{
    DKMsgBase_t base;
    data_u8_128 pictureFilenameType;
    EPictureStatusType_t pictureStatusType;
} PictureInfoType;

typedef struct
{
    DKMsgBase_t base;
    EPictureStatusType_t pictureServiceAvailStatus;
} PictureServiceStatus;

typedef struct
{
    DKMsgBase_t base;
    ESubcriptionServiceAckStatus_t subscriptionStatus;
} AudioSubscriptionStatus;

typedef struct
{
    DKMsgBase_t base;
    uint8 processStatus;
} HMIProcessStatus;

typedef struct
{
    DKMsgBase_t base;
    data_u8_50 settingAvailabilityStatus;
    data_u32_50 currentSettingValue;
    uint8 currentSettingIdx;
    data_u16_50 currMdlSettingsId;
} PersRecordMsg;

typedef struct
{
    DKMsgBase_t base;
    EUdsMode_t currentMode;
} UdsCurrentMode;

typedef struct
{
    DKMsgBase_t base;
    EUdsSession_t currentSession;
} UdsCurrentSession;

typedef struct
{
    DKMsgBase_t base;
    EFileModeOfOperation_t modeOfOperation;
    uint8 requestedFilenameWithPathLen;
    dataBuffer256 requestedFilenameWithPath;
    uint8 tempFilenameWithPathLen;
    dataBuffer256 tempFilenameWithPath;
    uint8 downloadComplete;
} UdsInstallerFileDownloadStatus;

typedef struct
{
    DKMsgBase_t base;
    EDidAccessType_t didAccessType;
    uint16 didId;
    uint8 dataLen;
    dataBuffer256 data;
} UdsInstallerDidRequest;

typedef struct
{
    DKMsgBase_t base;
    uint8 flag;
} UdsDidPostResponseIndication;

typedef struct
{
    DKMsgBase_t base;
    EGeneralResponseCode_t responseCode;
    EDidAccessType_t didAccessType;
    uint16 didId;
    uint16 dataLen;
    dataBuffer256 data;
} UdsInstallerDidResponse;

typedef struct
{
    DKMsgBase_t base;
    EMemDiagRequestCmd_t respCmd;
    EReflashStatus_t resResult;
    data_u8_4 data;
} MemDiagRespData;

typedef struct
{
    DKMsgBase_t base;
    EMemTypeCmd_t memoryType;
    uint32 address;
    uint32 size;
    EMemDiagRequestCmd_t reqCmd;
} MemDiagReqData;

typedef struct
{
    DKMsgBase_t base;
    uint8 rcvdSettingIdx;
} PersRecordMsgResp;

typedef struct
{
    DKMsgBase_t base;
    uint8 telTriggerEvent;
} PhoneIndEvt;

typedef struct
{
    DKMsgBase_t base;
    data_u8_50 customSettingsData;
} CustSettingsMsg;

typedef struct
{
    DKMsgBase_t base;
    uint16 did;
    EDidType_t didType;
    uint16 dataLen;
    data_u8_300 data;
} GipDiagDIDRequest;

typedef struct
{
    DKMsgBase_t base;
    uint16 routineId;
    ERoutineType_t routineType;
    uint16 dataLen;
    data_u8_256 data;
} GipDiagRoutineRequest;

typedef struct
{
    DKMsgBase_t base;
    uint16 did;
    EIOCtrlOptType_t optionCtrl;
    uint16 dataLen;
    data_u8_256 data;
} GipDiagIOCtrlRequest;

typedef struct
{
    DKMsgBase_t base;
    uint8 responseCode;
    uint16 dataLen;
    data_u8_300 data;
} GipDiagResponse;

typedef struct
{
    DKMsgBase_t base;
    uint16 currSettingsId;
    uint32 currSettingsVal;
    uint8 curSettingsAction;
} CurrentSettingsData;

typedef struct
{
    DKMsgBase_t base;
    uint8 odoDisplayChangeFactoryResetEvt;
} SettingsResetData;

typedef struct
{
    DKMsgBase_t base;
    uint8 currOdoTripReq;
    uint8 hmiCtrlInitReq;
    SMenuBackUpData_t menuBackupDataReq;
    data_u32_6 recordMainMenuItem;
    data_u8_8 errorData;
    uint8 personalSubWidgetReq;
    SSelfDiagBackUpData_t selfDiagBackupDataReq;
} SaveBackUpRamData;

typedef struct
{
    DKMsgBase_t base;
    uint8 backUpDataRxAck;
} BackUpRamDataRxAck;

typedef struct
{
    DKMsgBase_t base;
    uint8 currOdoTripRes;
    uint8 hmiCtrlInitRes;
    SMenuBackUpData_t menuBackupDataRes;
    data_u32_6 recordMainMenuItem;
    data_u8_8 errorData;
    uint8 personalSubWidgetRes;
    SSelfDiagBackUpData_t selfDiagBackupDataRes;
} RestoreBackUpRamData;

typedef struct
{
    DKMsgBase_t base;
    data_u16_16 etmConfig;
    uint8 etmConfigIndex;
} EtmConfigData;

typedef struct
{
    DKMsgBase_t base;
    uint8 enterClockSettingsMenu;
} EnterorExitClockMenu;

typedef struct
{
    DKMsgBase_t base;
    uint32 dimmingLevel;
} DimmingData;

typedef struct
{
    DKMsgBase_t base;
    uint16 responseContent;
} EthSwipeResponse;

typedef struct
{
    DKMsgBase_t base;
    ESwipeStates_t swipeState;
} EthSwipeState;

typedef struct
{
    DKMsgBase_t base;
    uint16 requestContent;
} EthSwipeRequest;

typedef struct
{
    DKMsgBase_t base;
    uint16 did;
    EDidType_t didType;
    uint16 dataLen;
    data_u8_256 data;
} DiagDIDRequest;

typedef struct
{
    DKMsgBase_t base;
    EInstallerFotaState_t state;
} UdsFotaState;

typedef struct
{
    DKMsgBase_t base;
    uint8 size;
} TrngReq;

typedef struct
{
    DKMsgBase_t base;
    data_u8_32 rndNum;
} TrngResp;

typedef struct
{
    DKMsgBase_t base;
    uint16 powerGaugeValue;
} PowerData;

typedef struct
{
    DKMsgBase_t base;
    data_u8_32 correlationData;
} FotaCorrelationID;

typedef struct
{
    DKMsgBase_t base;
    uint8 vehicleTypeCF;
    uint8 variantTypeCF;
} VariantConfigData;

typedef struct
{
    DKMsgBase_t base;
    uint8 PersMenuEvent;
} PersMenuAnimEvent;

typedef struct
{
    DKMsgBase_t base;
    uint8 RemoteEngineStartWarningstatus;
} RemoteEngineStartWarningstatus;

typedef struct
{
    DKMsgBase_t base;
    uint8 BlankWarning_status;
} BlankWarning_status;

typedef struct
{
    DKMsgBase_t base;
    uint8 WarningDisplaySts;
} LSHDisplay_Warning_Screen;

typedef struct
{
    DKMsgBase_t base;
    uint8 AD2DisplaySts;
} LSHDisplay_AD2_Screen;

typedef struct
{
    DKMsgBase_t base;
    uint8 ShortcutMenuDisplaySts;
} LSHDisplay_Shortcut_Screen;

typedef struct
{
    DKMsgBase_t base;
    uint8 ScreenAnimUpdateButtonSts;
} ScreenAnimUpdateButtonSts;

typedef struct
{
    DKMsgBase_t base;
    uint8 HmiModeSts;
} HmimodeSts;

typedef struct
{
    DKMsgBase_t base;
    uint8 InPersonnalMenu;
} InPersonnalMenu;

typedef struct
{
    DKMsgBase_t base;
    data_u8_35 TTChecksumSts;
} TTChecksumSts;

typedef struct
{
    DKMsgBase_t base;
    data_u8_12 PeripheralVehSts;
} AD2VehSts;

typedef struct
{
    DKMsgBase_t base;
    data_u8_4 AD2ScreenSts;
} AD2ScreenSts;

typedef struct
{
    DKMsgBase_t base;
    data_u8_8 AD2PeripheralVehSts;
} AD2PeripharlVehSts;

typedef struct
{
    DKMsgBase_t base;
    data_u8_8 TTVisSts;
} TTVisablitySts;

typedef struct
{
    DKMsgBase_t base;
    data_u8_40 AD2menuPayload;
} AD2MenuPayloadData;

typedef struct
{
    DKMsgBase_t base;
    uint8 diagMode;
} GIPUdsDiagMode;

typedef struct
{
    DKMsgBase_t base;
    EnetReqCmd_t cmd;
    uint8 respLen;
    data_u8_32 response;
} EnetRegResp;

typedef struct
{
    DKMsgBase_t base;
    EnetReqCmd_t cmd;
    EnetReqMode_t mode;
    uint8 dataLen;
    data_u8_32 data;
} EnetRegReq;

typedef struct
{
    DKMsgBase_t base;
    uint16 VIPcurrentETMState;
} VIPCurrentETMStatus;

typedef struct
{
    DKMsgBase_t base;
    uint16 VIPcurrentBulbCheckStatus;
} VIPCurrentBulbCheckStatus;

typedef struct
{
    DKMsgBase_t base;
    uint8 responseCode;
    uint16 dataLen;
    data_u8_300 data;
} VipDiagResponse;

typedef struct
{
    DKMsgBase_t base;
    uint16 did;
    EDidType_t didType;
    uint16 dataLen;
    data_u8_300 data;
} VipDiagDIDRequest;

typedef struct
{
    DKMsgBase_t base;
    ELayoutErrorState_t LayoutStatus;
} LayoutStatus;

typedef struct
{
    DKMsgBase_t base;
    uint8 modeScreenStatus;
} HmiModeScreenStatus;

typedef struct
{
    DKMsgBase_t base;
    uint8 openinigMovieStatus;
} HmiOpeningMovieStatus;

typedef struct
{
    DKMsgBase_t base;
    uint8 TTopStatus;
} TickTokValue;

typedef struct
{
    DKMsgBase_t base;
    uint8 recordType;
    uint8 recordLen;
    data_u8_8 recordData;
} HealthEventRecord;

typedef struct
{
    uint8 id;
    uint16 position;
    sint32 digitalData;
    EGaugeUnit_t unit;
    uint16 dynData;
} SGaugeInfo;

typedef SGaugeInfo SGaugeInfo_4[4];

typedef struct
{
    uint8 key;
    data_u8_8 value;
} SKeyVal8;

typedef SKeyVal8 SKeyVal8_2[2];

typedef SKeyVal1 SKeyVal1_10[10];

typedef SKeyVal4 SKeyVal4_5[5];

typedef struct
{
    uint8 key;
    data_u8_2 value;
} SKeyVal2;

typedef SKeyVal2 SKeyVal2_50[50];

typedef struct
{
    EUIMcanFeatureAvailability_t MCANClockAvailability;
    EUIMcanFeatureAvailability_t AudioFeatureAvailability;
    EUIMcanFeatureAvailability_t HFFeatureAvailability;
    EUIMcanFeatureAvailability_t SMSFeatureAvailability;
    EUIMcanFeatureAvailability_t VRFeatureAvailability;
    EUIMcanFeatureAvailability_t NaviSourceAvailability;
} SMcanFeatureInfo;

typedef struct
{
    DKMsgBase_t base;
    SGaugeInfo gaugeInfo;
} SlowGuageInfo;

typedef struct
{
    DKMsgBase_t base;
    SGaugeInfo_4 gaugeInfo_4;
} FastGuageInfo;

typedef struct
{
    DKMsgBase_t base;
    SKeyVal8 data;
} PersRecord;

typedef struct
{
    DKMsgBase_t base;
    SKeyVal8_2 data_2;
} PersRecord8byte;

typedef struct
{
    DKMsgBase_t base;
    SKeyVal1_10 data_10;
} PersRecord1byte;

typedef struct
{
    DKMsgBase_t base;
    SKeyVal4_5 data_5;
} PersRecord4byte;

typedef struct
{
    DKMsgBase_t base;
    SKeyVal2 data;
} ConfigRecord;

typedef struct
{
    DKMsgBase_t base;
    SKeyVal2_50 data_50;
} ConfigRecordExt;

typedef struct
{
    DKMsgBase_t base;
    SMcanFeatureInfo mcanAvailability;
} McanAvailabilityInfo;

typedef struct
{
    DKMsgBase_t base;
    uint8 ethernetLinkStatus;
} EthlinkDownStatus;

//#include <sys/wait.h>

#define FaultStatusType_OK   0U
#define FaultStatusType_NOK  1U


#define FaultType_NoFaultDetected      0U
#define FaultType_BEthConnLoss_BusOff  1U
#define FaultType_BEthConnLoss_OC      2U



#ifdef __cplusplus
} // runtime
} // dk
#endif
#endif //DK_RUNTIME_TYPES_H

