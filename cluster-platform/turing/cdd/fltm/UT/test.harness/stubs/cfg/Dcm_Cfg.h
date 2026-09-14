/*****************************************************************************
 *                                                                            *
 *              CONFIDENTIAL VISTEON CORPORATION                              *
 *                                                                            *
 * This is an unpublished work of authorship, which contains trade            *
 * secrets, created in 2016. Visteon Corporation owns all rights to           *
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
 *  File Name         :  Dcm_Cfg.h                                            *
 *  Module Short Name :  DiagMgr                                              *
 *  VOBName           :                                                       *
 *  Author            : msavariy                                              *
 *  Description       : This file contains the Diagnostics request and        *
 *                       response handling functionlities.                    *
 *                                                                            *
 * Organization     :  Driver Information Software Section,                   *
 *                     Visteon Software Operation                             *
 *                     Visteon Corporation                                    *
 *                                                                            *
 * ---------------------------------------------------------------------------*
 * Compiler Name    :  GHS                                                    *
 * Target Hardware  :                                                         *
 *                                                                            *
 ******************************************************************************/
#ifndef DCM_CFG_H_
#define DCM_CFG_H_

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "Dcm_Types.h"

#ifdef TRUE
  #undef TRUE
  #define TRUE        (1U)
#endif
 
#ifdef FALSE
  #undef FALSE
  #define FALSE       (0U)
#endif


/*****************************************************************************
 *                                 Macro Definitions                          *
 *----------------------------------------------------------------------------*
 * Definition of macro shall be followed by a comment that explains the       *
 * purpose of the macro.                                                      *
 ******************************************************************************/

#define DCM_PDU_DIAG_REQ_PHYSICAL 0U
#define DCM_PDU_ISO_KOMBI_RESP    45U
#define DCM_PDU_OBDC_KOMBI_RESP   59U

#define DCMEXT_PROG_MAGIC_FLAG_HANDLER                STD_ON
#define DcmDsdRequestManufacturerNotificationEnabled  STD_ON
#define DcmDsdRequestSupplierNotificationEnabled      STD_OFF
#define Dcm_KeepNonDefaultSessionActive               STD_OFF

#define DCMEXT_DIAG_ENTRY_CONDITION_CHECK       DcmExt_Diag_Condition_check
#define DCMEXT_PROG_ENTRY_CONDITION_CHECK       DcmExt_Prog_Condition_check
#define DCMEXT_INIT                             DcmExt_Init
#define DCMEXT_MAINFUNCTION                     DcmExt_Main
#define DCMEXT_BROADCAST_SECURITY_STATE_CHANGES  DcmExt_BroadCast_SecurityChangeStatus
#define DCMEXT_BROADCAST_SESSION_STATE_CHANGES  DcmExt_BroadCast_SessionChangeStatus
#define DCMEXT_COMM_ACTION                      DcmExt_Communication_action
#define DCMEXT_PERFORM_HARD_RESET               DcmExt_WdgM_PerformReset
#define DCMEXT_SET_PROGRAM_FLAG                 DcmExt_SetProgFlag
#define DCMEXT_CLEAR_DTC_NOTIFY()
#define DCM_PRE_CONDITION_CHECK                 DcmExt_Vehicle_Condition_check
#define DCM_11S_PRE_CONDITION_CHECK             DcmExt_Vehicle_Condition_check
#define DCM_28S_PRE_CONDITION_CHECK             DcmExt_28SVehicle_Condition_check
#define DCM_85S_PRE_CONDITION_CHECK             DcmExt_Vehicle_Condition_check
#define DCM_23S_PRE_CONDITION_CHECK             DcmExt_3DStatus_Vehicle_Condition_check
#define DCM_3DS_PRE_CONDITION_CHECK             DcmExt_Vehicle_SpeedCondition_check
#define DCM_2FS_PRE_CONDITION_CHECK             DcmExt_Vehicle_Condition_check
#define DCM_34S_PRE_CONDITION_CHECK             DcmExt_Vehicle_SpeedCondition_check
#define DCM_35S_PRE_CONDITION_CHECK             DcmExt_Vehicle_SpeedCondition_check
#define DCM_14S_PRE_NOTIFICATION                DcmExt_Pre_notification_clear
#define DCM_14S_END_NOTIFICATION                DcmExt_End_notification_clear
#define DCM_14S_MFG_CHECK                       DcmExt_Mfg_Condition_check

#define STPCDD_DID_DIAGACTION                   STPCDD_Did_DiagAction
#define WDGMGR_DID_DIAGACTION                   WDGMGR_Did_DiagAction
#define WRNCTRL_DID_DIAGACTION                  WRNCTRL_Did_DiagAction
#define STPMGR_DID_DIAGACTION                   STPMGR_Did_DiagAction
#define SPDMDL_DID_DIAGACTION                   SPDMDL_Did_DiagAction
#define AIRBAG_DID_DIAGACTION                   AIRBAG_Did_DiagAction

#define RequestIndication_0_Indication          DcmExt_ServReqNotif_Manufacture_Indication

#define RespConfirmation_0          DcmExt_ServReqNotif_Manufacture_Confirmation

#define DCM_2FS_STATE_CHANGE(arg1, arg2)        DcmExt_2F_RCTUChange(arg1,arg2)
#define DCMEXT_NOTIFICATIONONDTCSTATUSCHANGE    DcmExt_NotificationOnDTCStatus

#define DcmDslDiagRespMaxNumRespPend            0x03u
#define DcmDslDiagRespOnSecondDeclinedRequest   TRUE

#define DcmDevAdditionalCoverityChecks          TRUE
/*
 * DcmDslProtocol
 */
#define DcmDslBufferSize                        (uint16)512
#define DcmTimStrP2ServerAdjust                 (uint16)10  /* in mS - Should be less than P2 Server*/
#define DcmTimStrP2StarServerAdjust             (uint16)500 /* in mS - Should be less than P2Star Server*/


#define DcmDslAddBufferSize                     (uint8)3
#define DcmNumOfSIDSupported                    (uint8)18
#define DcmNumOfRIDSupported                    (uint8)8
#define DcmNumOfDIDSupported                    (uint16)24
#define DCM_NO_IODIDS          (uint8)8

#define RID_CHIMES_ACTION                       DI_Rid_Diag_Action

/* in Milli Seconds - v*/
#define DCM_TASK_PERIODICITY                    (10u)
#define DCM_S3_SERVER_TIME                      (5000u)
#define No_of_security_level                    2U
#define NO_OF_SUPPORTTED_SESSIONS               5U

#define NO_OF_SUPPORTTED_COM_CONTROL            2U

#define TIMER_KeepNonDefaultSession             300u

/* Define the macro S27_DELAY_SUPPORTED if delay need to be added for security failure */
#define S27_DELAY_SUPPORTED                     TRUE /* msavariy - maserati*/
#define S27_STATIC_SEED_SUPPORTED               FALSE
#define S27_RESET_DELAY_SUPPORTED               FALSE
#define S27_KEY_SEND_MAX_LIMIT_SUPPORTED        FALSE
#define S27_FAIL_COUNT_NVM_SUPPORTED            FALSE

#define NO_OF_CONFIRMATION_NOTIFICATION         1U
#define DCM_ZERO                                0U
#if(S27_STATIC_SEED_SUPPORTED == TRUE)
#define S27_STATIC_SEED_BUFFER_SIZE             4
#endif

#if(S27_DELAY_SUPPORTED == TRUE)
/* Value of 30000 makes 30 Seconds on Turing B */
#define S27_FAIL_COUNT_TIME_MS                  10000U
#define S27_FAIL_COUNT                          2U
#define S27_REATTEMPT_COUNT                     1U
#if(S27_RESET_DELAY_SUPPORTED == STD_ON)
#define S27_RSTDELAY_TIME_MS                    (10000)
#endif

#if(S27_KEY_SEND_MAX_LIMIT_SUPPORTED == STD_ON)
#define S27_KEY_SEND_MAX_LIMIT_MS               (20000)
#endif
#endif /* (S27_DELAY_SUPPORTED == TRUE) */


#define DcmDspNumOfDidOpInfo                     39U
#define DcmDsdNumOfStateRef                      21U
#define DcmDspNumOfDidSignalInfo                 1U
#define DcmDspNumOfRidSignalInfo                 15U
#define DidNumOfOpFunc                           1U
#define RidNumOfOpFunc                           1
#define Svc11NumOfSubFunc                        1U

#define Svc85NumOfsubFunc                        2U
#define DCM_SVC_85_DTC_GRP_ENABLED               TRUE
#define DCM_FUNC_ADDR_SUPPRESS_NRC               FALSE

#define ComMChannelSupported                    0x01u
#define DcmNumofClientSupported                 0x02u

#define DCM_TMR_DEFSESS                        0

#define DCM_PDU_E4_DIAG_RES         0U
#define DCM_PDU_E4_DIAG_PHY_REQ     0U
#define DCM_PDU_E4_DIAG_FUNC_REQ    1U
#define DCM_PDU_DIAG_RESP_UUDT      1U 
#define DCM_PDU_DIAG_RESP_USDT      0U    
   

#define DCM_SVC_10_SUPPORT_ENABLED              STD_ON
#define DCM_SVC_11_SUPPORT_ENABLED              STD_ON
#define DCM_SVC_14_SUPPORT_ENABLED              STD_ON
#define DCM_SVC_22_SUPPORT_ENABLED              STD_ON
#define DCM_SVC_23_SUPPORT_ENABLED              STD_ON
#define DCM_SVC_27_SUPPORT_ENABLED              STD_ON
#define DCM_SVC_28_SUPPORT_ENABLED              STD_ON
#define DCM_SVC_2E_SUPPORT_ENABLED              STD_ON
#define DCM_SVC_2F_SUPPORT_ENABLED              STD_ON
#define DCM_SVC_31_SUPPORT_ENABLED              STD_ON
#define DCM_SVC_34_SUPPORT_ENABLED              STD_ON
#define DCM_SVC_35_SUPPORT_ENABLED              STD_OFF
#define DCM_SVC_36_SUPPORT_ENABLED              STD_ON
#define DCM_SVC_37_SUPPORT_ENABLED              STD_ON
#define DCM_SVC_3D_SUPPORT_ENABLED              STD_ON
#define DCM_SVC_3E_SUPPORT_ENABLED              STD_ON
#define DCM_SVC_85_SUPPORT_ENABLED              STD_ON
#define DCM_SVC_86_SUPPORT_ENABLED              STD_OFF
#define DCM_SVC_87_SUPPORT_ENABLED              STD_OFF

#define DCM_SVC_86_EMULATION_ENABLED            STD_OFF

#define DCM_SVC_19_SUPPORT_ENABLED              STD_ON

#define DCM_SVC_19_03_SUPPORT_ENABLED           STD_ON
#define DCM_SVC_19_04_SUPPORT_ENABLED           STD_ON
#define DCM_SVC_19_06_SUPPORT_ENABLED           STD_ON
#define DCM_SVC_19_07_SUPPORT_ENABLED           STD_ON
#define DCM_SVC_19_08_SUPPORT_ENABLED           STD_ON
#define DCM_SVC_19_09_SUPPORT_ENABLED           STD_ON
#define DCM_SVC_19_0A_SUPPORT_ENABLED           STD_ON
#define DCM_SVC_19_0C_SUPPORT_ENABLED           STD_ON
#define DCM_SVC_19_0E_SUPPORT_ENABLED           STD_ON
#define DCM_SVC_19_14_SUPPORT_ENABLED           STD_ON

#define DCM_FOTA_SUPPORT_ENABLED                STD_OFF

#define SVC_19_01_COUNT     1
#define SVC_19_02_COUNT     1
#if(DCM_SVC_19_03_SUPPORT_ENABLED == STD_ON)
  #define SVC_19_03_COUNT     1
#else
  #define SVC_19_03_COUNT     0
#endif
#if(DCM_SVC_19_04_SUPPORT_ENABLED == STD_ON)
  #define SVC_19_04_COUNT     1
#else
  #define SVC_19_04_COUNT     0
#endif
#if(DCM_SVC_19_06_SUPPORT_ENABLED == STD_ON)
  #define SVC_19_06_COUNT     1
#else
  #define SVC_19_06_COUNT     0
#endif
#if(DCM_SVC_19_07_SUPPORT_ENABLED == STD_ON)
  #define SVC_19_07_COUNT     1
#else
  #define SVC_19_07_COUNT     0
#endif
#if(DCM_SVC_19_08_SUPPORT_ENABLED == STD_ON)
  #define SVC_19_08_COUNT     1
#else
  #define SVC_19_08_COUNT     0
#endif
#if(DCM_SVC_19_09_SUPPORT_ENABLED == STD_ON)
  #define SVC_19_09_COUNT     1
#else
  #define SVC_19_09_COUNT     0
#endif
#if(DCM_SVC_19_0A_SUPPORT_ENABLED == STD_ON)
  #define SVC_19_0A_COUNT     1
#else
  #define SVC_19_0A_COUNT     0
#endif
#if(DCM_SVC_19_0C_SUPPORT_ENABLED == STD_ON)
  #define SVC_19_0C_COUNT     1
#else
  #define SVC_19_0C_COUNT     0
#endif
#if(DCM_SVC_19_0E_SUPPORT_ENABLED == STD_ON)
  #define SVC_19_0E_COUNT     1
#else
  #define SVC_19_0E_COUNT     0
#endif
#if(DCM_SVC_19_14_SUPPORT_ENABLED == STD_ON)
  #define SVC_19_14_COUNT     1
#else
  #define SVC_19_14_COUNT     0
#endif

#define Svc19NumOfsubFunc     (SVC_19_01_COUNT+SVC_19_02_COUNT+SVC_19_03_COUNT+ \
                               SVC_19_04_COUNT+SVC_19_06_COUNT+SVC_19_07_COUNT+ \
                               SVC_19_08_COUNT+SVC_19_09_COUNT+SVC_19_0A_COUNT+ \
                               SVC_19_0C_COUNT+SVC_19_0E_COUNT+SVC_19_14_COUNT)


#if(DCM_SVC_86_SUPPORT_ENABLED == STD_ON)
#define Svc86NumOfsubFunc                       4
#define Svc86NumOfROE                           1
#define Svc86NumOfStrtrdParameters              2

#if(DCM_SVC_86_EMULATION_ENABLED == STD_ON)
extern boolean IsEventOccurred;
#endif
#endif /* (DCM_SVC_86_SUPPORT_ENABLED == STD_ON) */

#if(DCM_SVC_87_SUPPORT_ENABLED == STD_ON)
// Service 0x87
#define LINKCONTROL_MODETRANSITIONWITHFIXEDPARAMETER     ((uint8)0x01)
#define LINKCONTROL_MODETRANSITIONWITHSPECIFICPARAMETER  ((uint8)0x02)
#define LINKCONTROL_TRANSITIONMODE                       ((uint8)0x03)

#define NO_OF_LINK_CTRL_TYPES  (  (  sizeof(LINKCONTROL_MODETRANSITIONWITHFIXEDPARAMETER) \
                                   + sizeof(LINKCONTROL_MODETRANSITIONWITHSPECIFICPARAMETER) \
                                   + sizeof(LINKCONTROL_TRANSITIONMODE)) \
                                / sizeof(LINKCONTROL_MODETRANSITIONWITHFIXEDPARAMETER)) 
/* short names */
#define LC_VMTWFP               LINKCONTROL_MODETRANSITIONWITHFIXEDPARAMETER
#define LC_VMTWSP               LINKCONTROL_MODETRANSITIONWITHSPECIFICPARAMETER
#define LC_TM                   LINKCONTROL_TRANSITIONMODE

#define NO_OF_LINK_CTRL_MODES   ((uint8)10)
#define NO_OF_LINK_REC_MODES    ((uint8)3)
#endif /* (DCM_SVC_87_SUPPORT_ENABLED == STD_ON) */

#if((DcmDsdRequestManufacturerNotificationEnabled == STD_ON) || (DcmDsdRequestSupplierNotificationEnabled == STD_ON))
#define NO_OF_REQUEST_NOTIFICATION              1U
#endif

#define S22_MAX_SUPPORTED_DID_READ              0x01u

#if(DCM_SVC_34_SUPPORT_ENABLED == STD_ON) || (DCM_SVC_35_SUPPORT_ENABLED == STD_ON)
#define DCM_ALFID_EXIST                          STD_ON
#define DCM_NUM_ALFID                            0x03u
#define DCM_NUM_DFID                             0x02u
#endif

#if(DCM_SVC_23_SUPPORT_ENABLED == STD_ON)
#define NumOfReadMemoryByAddressRanges          0x01u
#endif

#if(DCM_SVC_3D_SUPPORT_ENABLED == STD_ON)
#define NumOfWriteMemoryByAddressRanges         0x01u
#endif

typedef struct
{
  Std_ReturnType (*DcmDsdSidTabFnc)(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode);
  uint8 Props;
  uint8 Length;
  uint8 State_Ref;
} Dcm_DsdSidTabServiceInfoType;

typedef struct
{
  uint8 Session;
  uint8 Security;
} Dcm_DsdStateRefType;

#if((DcmDsdRequestManufacturerNotificationEnabled == STD_ON) || (DcmDsdRequestSupplierNotificationEnabled == STD_ON))
typedef Std_ReturnType (*XXX_Indication)(uint8 SID, uint8* RequestData, uint16 RequestDataSize, uint8 ReqType, uint16 SourceAddress, 
                                         uint8* RespData, uint16* RespDataSize, Dcm_NegativeResponseCodeType* ErrorCode );
typedef Std_ReturnType (*XXX_Confirmation)(uint8 SID, uint8 ReqType, uint16 SourceAddress, Dcm_ConfirmationStatusType ConfirmationStatus);                                        

typedef struct
{
  XXX_Indication XXX_IndicationFunc;
} XXX_IndicationType;

typedef struct
{
  XXX_Confirmation XXX_ConfirmationFunc;
} XXX_ConfirmationType;
#endif

typedef struct
{
  Std_ReturnType (*SubServiceFnc)(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *Buff, Dcm_NegativeResponseCodeType *NegRes);
  uint8 SubServiceId;
  uint8 Length;
  uint8 State_Ref;
} Dcm_DsdSubService19Type;

typedef struct
{
  Std_ReturnType (*SubServiceFnc)(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *NegRes);
  uint8 SubServiceId;
  uint8 State_Ref;
} Dcm_DsdSubService10Type;

typedef struct
{
  uint8 ControlType;
  uint8 CommunicationType;
} Dcm_DsdSubService28Type;

typedef Std_ReturnType (*SubService11)(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *NegRes);
typedef struct
{
  SubService11 SubServiceFnc;
  uint8 State_Ref;
  uint8 SubServiceId;
} Dcm_DsdSubService11Type;

#if(S27_DIAG_HARDENING == STD_ON)
typedef Std_ReturnType (*SubService27)(Dcm_OpStatusType OpStatus, Dcm_MsgType Buff, uint8 SubFunction, Dcm_NegativeResponseCodeType *NegRes);
#else
typedef Std_ReturnType (*SubService27)(Dcm_OpStatusType OpStatus, Dcm_MsgType Buff, uint8 SubFunction, Dcm_NegativeResponseCodeType *NegRes,Dcm_SesCtrlType flSession);
#endif
typedef struct
{
  SubService27 SubServiceFnc;
  uint8 SubServiceId;
  uint16 Req_Length;
  uint16 Resp_Length;
  uint8 State_Ref;
} Dcm_DsdSubService27Type;

typedef Std_ReturnType (*SubService85)(uint8 ClientId);
typedef struct
{
  SubService85 SubServiceFnc;
  uint8 SubServiceId;
  uint8 State_Ref;
} Dcm_DsdSubService85Type;

#if(DCM_SVC_86_SUPPORT_ENABLED == STD_ON)
typedef Std_ReturnType (*SubService86)(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *Buff, Dcm_NegativeResponseCodeType *NegRes);
typedef struct
{
  SubService86 SubServiceFnc;
  uint8 SubServiceId;
  uint8 Length;
} Dcm_DsdSubService86Type;

typedef struct
{
  uint8 Id;
  uint8 InitStatus;
  uint8 Prop;
  uint8 WindowTime;
  boolean StorageState;
}DcmDspRoeEventType;

typedef struct
{
  uint16 InterMessageTime;
}Dcm_DspRoeType;

typedef struct
{
  uint8 Strtrd[Svc86NumOfStrtrdParameters];
}Dcm_DspRoeOnDTCStatusChangeType;
#endif

typedef Std_ReturnType (*Service34Func)(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *NegRes);
typedef struct
{
  Service34Func ServiceFnc;
  uint16 Req_Length;
  uint16 Resp_Length;
} Dcm_DspService34Type;

typedef struct
{
  uint32 MemRangeHigh;
  uint32 MemRangeLow;
  uint8 State_Ref;
} Dcm_DspReadMemoryRangeInfoType;

typedef struct
{
  uint32 MemRangeHigh;
  uint32 MemRangeLow;
  uint8 State_Ref;
} Dcm_DspWriteMemoryRangeInfoType;

typedef struct
{
  uint16 P2;
  uint16 P2Star;
  uint8 Session_Value;
} Dcm_DsdSessionInfoType;

typedef struct
{
  uint16 OpInfoRef;
  uint8 Operations;
  boolean DcmDspDidUsed;
} Dcm_DspDidInfoType;

typedef struct
{
  uint16 Min_ReqLength;  /* For Static DID fixed length, For Dynamic DID configure Minimum request length. does not include SID + DID Size / IO Control Option #1 */
  uint16 Max_ReqLength;  /* For Static DID fixed length, For Dynamic DID configure Minimum request length. does not include SID + DID Size / IO Control Option #1 */
  uint8 State_Ref;
  uint8 SignalInfo_Ref;
  uint8 CallTypes;
} Dcm_DspDidOpInfoType;

typedef struct
{
  uint8 DidOpFunc_Ref;
  uint8 FunClass;
} Dcm_DspDidSignalInfoType;

typedef struct
{
  uint8 SignalInfo_Ref;
  uint8 State_Ref;
  uint8 Operation;
  boolean DcmDspRidUsed;
} Dcm_DspRidInfoType;

typedef struct
{
  uint8 RidOpFunc_Ref;
  uint16 Min_ReqLength;  /* For Static RID fixed length, For Dynamic RID configure Minimum request length. does not include SID + RID + SF */
  uint16 Max_ReqLength;  /* For Static RID fixed length, For Dynamic RID configure Minimum request length. does not include SID + RID + SF */
  uint16 Min_RespLength;  /* does not include RID + SF */
  uint16 Max_RespLength;  /* does not include RID + SF */
  uint8 OpType;
} Dcm_DspRidSignalInfoType;

typedef struct
{
  uint8 RxPduID;
  uint8 TxPduID;
} Dcm_UDSProtocolType;

typedef struct
{
  uint8 ReqLength; /* for seed: SF + ADR_size, for key: SF + key_size*/
  uint8 ResLength; /* for seed: SF + seed_size, for key: SF */
} Dcm_DspSecurityInfoType;

typedef struct
{
  uint8 Subfunction; /* for seed: SF + ADR_size, for key: SF + key_size*/
  uint8 Comm_support; /* for seed: SF + seed_size, for key: SF */
} Dcm_SessionCommEnableInfo;

typedef struct
{
  PduIdType PhyReqId;     //will be defined in lower modules
  PduIdType FuncReqId;    //will be defined in lower modules
  uint8     PduIdChannelRef;      //points to PduIdChannelType
} Dcm_RxPduIdType;

typedef struct
{
  PduIdType PhyRespId;           //Indicates Id to be sent during PduR_DcmTransmit
  PduIdType ConfRespId;           //Defined in Dcm will be called from lower module
  uint8     ComMChannelIdRef; // Points to ComM channed Id table
  uint8     ClientPriority;    //0-Highest Priority   FF-Lowest Priority
  Dcm_DemClientIdType DcmDemClientRef;   //Indicates the client used for Dem 
} Dcm_PduIdChannelType;

typedef struct
{
  uint8     ComMChannelId; // TBD
} Dcm_ComMChannelIDType;


/*****************************************************************************
 *                                Globally  accessed Variable Declarations    *
 *----------------------------------------------------------------------------*
 * Declaration shall be followed by a comment that gives the following info.  *
 * about the variable.                                                        *
 * purpose, critical section, unit, and resolution                            *
 ******************************************************************************/

typedef uint8 Dcm_DsdSidTabServiceIdType;
typedef uint16 Dcm_DspDidIdentifierTableType;
typedef uint16 Dcm_DspRidIdentifierTableType;
typedef uint8 Dcm_DspSvc27SubFuncTableType;
typedef Std_ReturnType (*DidOpFuncType)(Dcm_OpStatusType OpStatus, uint8 Did_action, Dcm_DspDidIdentifierTableType Did, const Dcm_MsgLenType ReqLength, Dcm_MsgType Buff,
                                  Dcm_MsgLenType* Length, Dcm_NegativeResponseCodeType *pNegRes);
typedef Std_ReturnType (*RidOpFuncType)(Dcm_OpStatusType OpStatus, uint8 eDcmExt_IOCtrl, Dcm_DspRidIdentifierTableType Rid, const Dcm_MsgLenType ReqLength,
                                        Dcm_MsgType Buff, Dcm_MsgLenType* RespLength, Dcm_NegativeResponseCodeType* NegRes);
extern const Dcm_DsdSidTabServiceIdType Dcm_DsdSidTabServiceId[DcmNumOfSIDSupported + 1];
extern const Dcm_DsdSidTabServiceInfoType Dcm_DsdSidTabServiceInfo[DcmNumOfSIDSupported ];
extern const Dcm_DsdStateRefType Dcm_DsdStateRef[DcmDsdNumOfStateRef];

extern const Dcm_DsdSubService10Type Dcm_DsdSubService10[NO_OF_SUPPORTTED_SESSIONS];
extern const Dcm_DsdSubService28Type Dcm_DsdSubService28[NO_OF_SUPPORTTED_COM_CONTROL];
extern const Dcm_DsdSubService11Type Dcm_DsdSubService11[Svc11NumOfSubFunc];
extern const Dcm_DsdSubService19Type Dcm_DsdSubService19[Svc19NumOfsubFunc];
extern const Dcm_DsdSubService27Type Dcm_DsdSubService27[No_of_security_level * 2];
extern const Dcm_DsdSubService85Type Dcm_DsdSubService85[Svc85NumOfsubFunc];

extern Std_ReturnType Dcm_ClearDTCCheckFnc(uint32 GoDTC, Dcm_NegativeResponseCodeType* ErrorCode);

#if((DcmDsdRequestManufacturerNotificationEnabled == STD_ON) || (DcmDsdRequestSupplierNotificationEnabled == STD_ON))
extern const XXX_IndicationType ServiceRequestIndicationTable[NO_OF_REQUEST_NOTIFICATION];
extern const XXX_ConfirmationType ServiceRequestConfirmationTable[NO_OF_CONFIRMATION_NOTIFICATION];
#endif

#if(DCM_SVC_86_SUPPORT_ENABLED == STD_ON)
extern const Dcm_DsdSubService86Type Dcm_DsdSubService86[Svc86NumOfsubFunc];
extern const DcmDspRoeEventType DcmDspRoeEvent[Svc86NumOfROE];
extern const Dcm_DspRoeType Dcm_DspRoe;
extern const Dcm_DspRoeOnDTCStatusChangeType Dcm_DspRoeOnDTCStatusChange;
#endif

#if(DCM_SVC_23_SUPPORT_ENABLED == STD_ON)
extern const Dcm_DspReadMemoryRangeInfoType Dcm_DspReadMemoryRange[NumOfReadMemoryByAddressRanges];
#endif

#if(DCM_SVC_3D_SUPPORT_ENABLED == STD_ON)
extern const Dcm_DspWriteMemoryRangeInfoType Dcm_DspWriteMemoryRange[NumOfWriteMemoryByAddressRanges];
#endif

#if (DCM_ALFID_EXIST == STD_ON)
extern const uint8 Dcm_AlfidList[DCM_NUM_ALFID];
#endif

#if ((DCM_SVC_34_SUPPORT_ENABLED == STD_ON) || (DCM_SVC_35_SUPPORT_ENABLED == STD_ON))
extern const uint8 Dcm_DfidList[DCM_NUM_DFID];
#endif

extern const Dcm_DsdSessionInfoType Dcm_DsdSessionInfo[NO_OF_SUPPORTTED_SESSIONS];

extern const Dcm_DspDidIdentifierTableType Dcm_DspDidIdentifierTable[DcmNumOfDIDSupported + 1];
extern const Dcm_DspDidInfoType Dcm_DspDidInfo[DcmNumOfDIDSupported ];
extern const Dcm_DspDidOpInfoType Dcm_DspDidOpInfo[DcmDspNumOfDidOpInfo];
extern const Dcm_DspDidSignalInfoType Dcm_DspDidSignalInfo[DcmDspNumOfDidSignalInfo];
extern const DidOpFuncType DidOpFunc[DidNumOfOpFunc];

extern const Dcm_DspRidIdentifierTableType Dcm_DspRidIdentifierTable[DcmNumOfRIDSupported + 1];
extern const Dcm_DspRidInfoType Dcm_DspRidInfo[DcmNumOfRIDSupported ];
extern const Dcm_DspRidSignalInfoType Dcm_DspRidSignalInfo[DcmDspNumOfRidSignalInfo];
extern const Dcm_RxPduIdType Dcm_RxPduId[DcmNumofClientSupported];
extern const Dcm_PduIdChannelType Dcm_PduIdChannel[DcmNumofClientSupported];
extern const Dcm_ComMChannelIDType Dcm_ComMChannelId[ComMChannelSupported];
extern const RidOpFuncType RidOpFunc[RidNumOfOpFunc];
extern const Dcm_SessionCommEnableInfo Dcm_SessionCommEnable[NO_OF_SUPPORTTED_SESSIONS];

/*****************************************************************************
 *                               Extern Functions                                    *
 ******************************************************************************/

extern void DcmExt_Main(void);
extern void DcmExt_Init(void);

extern void Dcm_EnterCriticalSection(void);
extern void Dcm_ExitCriticalSection(void);

#if(DCM_SVC_34_SUPPORT_ENABLED == STD_ON)
/**************************************************************************
Function name       : Std_ReturnType Dcm_ProcessRequestDownload(Dcm_OpStatusType OpStatus, uint8 DataFormatIdentifier, uint32 MemoryAddress, uint32 MemorySize,
    uint32* BlockLength, Dcm_NegativeResponseCodeType* ErrorCode)
Description         : Write Memory By address
Parameters (in)     : uint32 MemoryAddress, uint32 MemorySize,
                                   Dcm_MsgType Buff, Dcm_MsgLenType* Length, Dcm_NegativeResponseCodeType* NegRes
Parameters (out)    : none
Return value        : Std_ReturnType
Design Information  :
**************************************************************************/
extern Std_ReturnType Dcm_ProcessRequestDownload(Dcm_OpStatusType OpStatus, uint8 DataFormatIdentifier, uint32 MemoryAddress, uint32 MemorySize,
    uint32* BlockLength, Dcm_NegativeResponseCodeType* ErrorCode);
    
/**************************************************************************
Function name   : Dcm_ReturnWriteMemoryType Dcm_WriteMemory
Arguments       : Dcm_OpStatusType OpStatus, uint8 MemoryIdentifier, uint32 MemoryAddress,
                  uint32 MemorySize, uint8* MemoryData, Dcm_NegativeResponseCodeType* ErrorCode
Return type     : Dcm_ReturnWriteMemoryType
Description     : The Dcm_WriteMemory callout is used to write memory data identified by the
                  parameter memoryAddress and memorySize.
**************************************************************************/

extern Dcm_ReturnWriteMemoryType Dcm_WriteMemory (Dcm_OpStatusType OpStatus,uint8 MemoryIdentifier,uint32 MemoryAddress,uint32 MemorySize,
      const uint8* MemoryData,Dcm_NegativeResponseCodeType* ErrorCode);

#endif

#if(DCM_SVC_35_SUPPORT_ENABLED == STD_ON)
/**************************************************************************
Function name       : Std_ReturnType Dcm_ProcessRequestUpload(Dcm_OpStatusType OpStatus, uint8 DataFormatIdentifier, uint32 MemoryAddress, uint32 MemorySize,
    uint32* BlockLength, Dcm_NegativeResponseCodeType* ErrorCode)
Description         : Write Memory By address
Parameters (in)     : uint32 MemoryAddress, uint32 MemorySize,
                                   Dcm_MsgType Buff, Dcm_MsgLenType* Length, Dcm_NegativeResponseCodeType* NegRes
Parameters (out)    : none
Return value        : Std_ReturnType
Design Information  :
**************************************************************************/
extern Std_ReturnType Dcm_ProcessRequestUpload(Dcm_OpStatusType OpStatus, uint8 DataFormatIdentifier, uint32 MemoryAddress, uint32 MemorySize,
    uint32* BlockLength, Dcm_NegativeResponseCodeType* ErrorCode);

/**************************************************************************
Function name   : Dcm_ReturnReadMemoryType Dcm_ReadMemory
Arguments       : Dcm_OpStatusType OpStatus, uint8 MemoryIdentifier, uint32 MemoryAddress,
                  uint32 MemorySize, uint8* MemoryData, Dcm_NegativeResponseCodeType* ErrorCode
Return type     : Dcm_ReturnReadMemoryType
Description     : The Dcm_ReadMemory callout is used to request memory data identified by the
                  parameter memoryAddress and memorySize from the UDS request message.
**************************************************************************/
extern Dcm_ReturnReadMemoryType Dcm_ReadMemory(Dcm_OpStatusType OpStatus, uint8 MemoryIdentifier,
        uint32 MemoryAddress, uint32 MemorySize, uint8* MemoryData, Dcm_NegativeResponseCodeType* ErrorCode);
#endif	

#if(DCM_SVC_37_SUPPORT_ENABLED == STD_ON)
/**************************************************************************
Function name   : Dcm_ProcessRequestTransferExit 
Arguments       : Dcm_OpStatusType OpStatus,const uint8* transferRequestParameterRecord,uint32 transferRequestParameterRecordSize,
                  uint8* transferResponseParameterRecord,uint32* transferResponseParameterRecordSize,Dcm_NegativeResponseCodeType* ErrorCode
Return type     : Std_ReturnType
Description     : Callout function.
                  DCM shall call this callout function to terminate a download or upload
                  process
**************************************************************************/
extern Std_ReturnType Dcm_ProcessRequestTransferExit(Dcm_OpStatusType OpStatus,const uint8* transferRequestParameterRecord,uint32 transferRequestParameterRecordSize,uint8* transferResponseParameterRecord,uint32* transferResponseParameterRecordSize,Dcm_NegativeResponseCodeType* ErrorCode);
#endif

extern Std_ReturnType Dcm_PerformHWReset(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *NegRes);
extern Std_ReturnType Dcm_PerformSoftReset(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *NegRes);
extern Std_ReturnType DcmExt_42DiagProcess(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *NegRes);
extern Std_ReturnType DcmExt_60DiagProcess(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *NegRes);

extern Std_ReturnType DcmExt_SecLevel1GetSeed(Dcm_OpStatusType OpStatus, Dcm_MsgType Buff,  uint8 SubFunction, Dcm_NegativeResponseCodeType *NegRes, Dcm_SesCtrlType Session);
extern Std_ReturnType DcmExt_SecLevel1CmpKey(Dcm_OpStatusType OpStatus, Dcm_MsgType Buff,   uint8 SubFunction, Dcm_NegativeResponseCodeType *NegRes, Dcm_SesCtrlType Session);
extern Std_ReturnType DcmExt_SecLevel61GetSeed(Dcm_OpStatusType OpStatus, Dcm_MsgType Buff,  uint8 SubFunction, Dcm_NegativeResponseCodeType *NegRes, Dcm_SesCtrlType Session);
extern Std_ReturnType DcmExt_SecLevel61CmpKey(Dcm_OpStatusType OpStatus, Dcm_MsgType Buff,   uint8 SubFunction, Dcm_NegativeResponseCodeType *NegRes, Dcm_SesCtrlType Session);

extern Std_ReturnType DI_Did_Diag_Action(Dcm_OpStatusType OpStatus, uint8 Did_action, Dcm_DspDidIdentifierTableType Did, \
                                         const Dcm_MsgLenType ReqLength, Dcm_MsgType Buff, Dcm_MsgLenType* Length, Dcm_NegativeResponseCodeType* NegRes);

extern Std_ReturnType DI_Rid_Diag_Action(Dcm_OpStatusType OpStatus, uint8 Rid_action, Dcm_DspRidIdentifierTableType Rid, \
                                         const Dcm_MsgLenType ReqLength, Dcm_MsgType Buff, Dcm_MsgLenType* Length, Dcm_NegativeResponseCodeType* NegRes);

extern void DcmExt_BroadCast_SecurityChangeStatus(uint8 SubFunction, uint8 Source);

extern void DcmExt_2F_RCTUChange(Dcm_DspDidIdentifierTableType Did, Dcm_NegativeResponseCodeType *NegRes);


extern void DcmExt_WdgM_PerformReset(void);
extern Std_ReturnType DcmExt_Communication_action(Dcm_OpStatusType OpStatus, uint8 ComM_Type, uint8 ComM_Action);
#if(DCMEXT_PROG_MAGIC_FLAG_HANDLER == STD_ON)
extern Std_ReturnType DcmExt_SetProgFlag(Dcm_NegativeResponseCodeType *NegRes);
#endif
extern void DcmExt_Confirmation(Std_ReturnType Result);
extern void DcmExt_BroadCast_SessionChangeStatus(uint8 SubFunction, uint8 Source);
#endif

extern Std_ReturnType DcmExt_ReadMemory(Dcm_OpStatusType OpStatus, uint32 MemoryAddress, uint32 MemorySize,
                                   Dcm_MsgType Buff, Dcm_MsgLenType* Length, Dcm_NegativeResponseCodeType* NegRes);
extern Std_ReturnType DcmExt_WriteMemory(Dcm_OpStatusType OpStatus, uint32 MemoryAddress, uint32 MemorySize,
                                   Dcm_MsgType Buff, Dcm_MsgLenType* Length, Dcm_NegativeResponseCodeType* NegRes);

#if(DCM_SVC_87_SUPPORT_ENABLED == STD_ON)
#ifndef VCAST_UNIT_TEST_DCM
extern const Dcm_LinkControlTypeInfo Dcm_LinkControlTypeEnable[NO_OF_LINK_CTRL_TYPES];
extern const Dcm_LinkControlModeIdentifierInfo Dcm_LinkControlModeEnable[NO_OF_LINK_CTRL_MODES]; 
extern const Dcm_LinkRecordIdentifierInfo Dcm_LinkRecordEnable[NO_OF_LINK_REC_MODES];
extern const Dcm_LinkTransitionModeInfo Dcm_LinkTransitionMode;
#else
extern Dcm_LinkControlTypeInfo Dcm_LinkControlTypeEnable[NO_OF_LINK_CTRL_TYPES];
extern Dcm_LinkControlModeIdentifierInfo Dcm_LinkControlModeEnable[NO_OF_LINK_CTRL_MODES]; 
extern Dcm_LinkRecordIdentifierInfo Dcm_LinkRecordEnable[NO_OF_LINK_REC_MODES];
extern Dcm_LinkTransitionModeInfo Dcm_LinkTransitionMode;
#endif

#ifdef VCAST_UNIT_TEST_DCM
/* VectorCast test cases */
extern Std_ReturnType Fnc87_VMTWFP(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *Buff, Dcm_NegativeResponseCodeType *NegRes);
extern Std_ReturnType Fnc87_VMTWSP(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *Buff, Dcm_NegativeResponseCodeType *NegRes);
extern Std_ReturnType Fnc87_TM(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *Buff, Dcm_NegativeResponseCodeType *NegRes);
extern Std_ReturnType Fnc87_VMTWFP2(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *Buff, Dcm_NegativeResponseCodeType *NegRes);
extern Std_ReturnType Fnc87_VMTWSP3(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *Buff, Dcm_NegativeResponseCodeType *NegRes);
extern Std_ReturnType Fnc87_TM3(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *Buff, Dcm_NegativeResponseCodeType *NegRes);
#endif

#endif /* (DCM_SVC_87_SUPPORT_ENABLED == STD_ON) */

#if(S27_FAIL_COUNT_NVM_SUPPORTED == TRUE)
extern Std_ReturnType SaveFailCounter(uint8 *counter);
extern Std_ReturnType ReadFailCounter(uint8 *counter);
extern boolean FailCounterIsReady(void);
#endif

extern const Dcm_DspService34Type Dcm_DspService34;
extern const Dcm_DspService34Type Dcm_DspService35;
extern const Dcm_DspService34Type Dcm_DspService36;
extern const Dcm_DspService34Type Dcm_DspService37;

// extern Std_ReturnType Dcm_34ServiceProcess(Dcm_MsgContextType *pMsgContext);
// extern Std_ReturnType Dcm_36ServiceProcess(Dcm_MsgContextType *pMsgContext);
// extern Std_ReturnType Dcm_37ServiceProcess(Dcm_MsgContextType *pMsgContext);

extern Std_ReturnType Dcm_34ServiceCallout(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *Buff, Dcm_NegativeResponseCodeType *NegRes);
extern Std_ReturnType Dcm_35ServiceCallout(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *Buff, Dcm_NegativeResponseCodeType *NegRes);
extern Std_ReturnType Dcm_36ServiceCallout(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *Buff, Dcm_NegativeResponseCodeType *NegRes);
extern Std_ReturnType Dcm_37ServiceCallout(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *Buff, Dcm_NegativeResponseCodeType *NegRes);

extern Std_ReturnType DcmExt_Diag_Condition_check(Dcm_NegativeResponseCodeType *NegRes);
extern Std_ReturnType DcmExt_Prog_Condition_check(Dcm_NegativeResponseCodeType *NegRes);
extern Std_ReturnType DcmExt_Vehicle_Condition_check(Dcm_MsgContextType *pMsgContext,Dcm_NegativeResponseCodeType *NegRes);
extern Std_ReturnType DcmExt_Vehicle_SpeedCondition_check(Dcm_NegativeResponseCodeType *NegRes);
extern Std_ReturnType DcmExt_3DStatus_Vehicle_Condition_check(Dcm_NegativeResponseCodeType *NegRes);
extern Std_ReturnType DcmExt_28SVehicle_Condition_check(Dcm_NegativeResponseCodeType *NegRes);
extern void DcmExt_Pre_notification_clear(void);
extern void DcmExt_End_notification_clear(void);
extern Std_ReturnType DcmExt_Mfg_Condition_check(Dcm_NegativeResponseCodeType *NegRes);
extern Std_ReturnType DcmExt_PerformReset_001(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *pNegRes);

extern void DcmExt_NotificationOnDTCStatus(uint32 DTC, Dem_UdsStatusByteType DTCStatusOld,
                                                Dem_UdsStatusByteType DTCStatusNew);

#if((DcmDsdRequestManufacturerNotificationEnabled == STD_ON) || (DcmDsdRequestSupplierNotificationEnabled == STD_ON))
extern Std_ReturnType DcmExt_ServReqNotif_Manufacture_Indication(uint8 SID, uint8* RequestData, uint16 RequestDataSize, uint8 ReqType, uint16 SourceAddress,
                                                 uint8* RespData, uint16* RespDataSize, Dcm_NegativeResponseCodeType* ErrorCode );
extern Std_ReturnType DcmExt_ServReqNotif_Manufacture_Confirmation(uint8 SID, uint8 ReqType, uint16 SourceAddress, Dcm_ConfirmationStatusType ConfirmationStatus );
#endif

/*****************************************************************************
 *     End of File
 *
 *******************************************************************************/
/****************************************************************************
 *   for each change to this file, be sure to record:                        *
 *      1.  who made the change and when the change was made                 *
 *      2.  why the change was made and the intended result                  *
 *   Following block needs to be repeated for each change                    *
 *****************************************************************************/
/**-------------------------------------------------------------------------*/
/*Date              : 17-Jun-2016                                           */
/*Version           :                                                       */
/*By                : msavariy                                              */
/*Traceability      :                                                       */
/*Change Description: Datadesign And Framework implemented, Initial Version */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 21-Sep-2016                                           */
/*Version           :                                                       */
/*By                : akalarim                                              */
/*Traceability      :                                                       */
/*Change Description: service 10,11,22 implementation                       */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 17-Oct-2016                                           */
/*Version           :                                                       */
/*By                : akalarim                                              */
/*Traceability      :                                                       */
/*Change Description: service 2E,2F,31 implementation                       */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 21-Oct-2016                                           */
/*Version           :                                                       */
/*By                : akalarim                                              */
/*Traceability      :                                                       */
/*Change Description: service 3E,27 implementation                          */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 22-Nov-2016                                           */
/*Version           :                                                       */
/*By                : akalarim                                              */
/*Traceability      : RTC 746031,RTC 746018                                 */
/*Change Description: service 28 and 27 timing implementation               */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 14-Mar-2020                                           */
/*Version           :                                                       */
/*By                : msavariy                                              */
/*Traceability      : 794563: Multi DID support for 0x22 service Multi      */
/*                    channel support                                       */
/*Change Description: Multi Read DID support and design optimization        */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 20-Mar-2020                                           */
/*Version           :                                                       */
/*By                : msavariy                                              */
/*Traceability      :i) 818177: Reception Diagnostic Tool Connection Not    */
/*                    Established in TuringC stream                         */
/*                    channel support                                       */
/*                   ii) 818468: [Diagnostic][A12]28 service NRC is wrong   */
/*                   iii) 817372 :- Service 0x86 basic frame Work           */
/*Change Description: Multi Read DID support and design optimization        */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 16-Apr-2020                                           */
/*Version           :                                                       */
/*By                : msavariy                                              */
/*Traceability      : Service 0x23 & 0x3D implementation                    */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 19-Sep-2020                                           */
/*Version           :                                                       */
/*By                : msavariy                                              */
/*Traceability      : Rtc#1046434                                           */
/*Change Description: 0x19 0x04 service design changes and defect fixes     */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 25-Feb-2021                                           */
/*Version           :                                                       */
/*By                : iiliev1                                               */
/*Traceability      :                                                       */
/*Change Description: Implement 0x87 and 0x27 services                      */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 17-Jun-2021                                           */
/*Version           :                                                       */
/*By                : iiliev1                                               */
/*Traceability      : Rtc#1376136                                           */
/*Change Description: Implement RequestIndication()                         */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 18-Jan-2022                                           */
/*Version           :                                                       */
/*By                : iiliev1                                               */
/*Traceability      : Rtc#1560389                                           */
/*Change Description: DCM and DEM Autosar 4.2.2 Migration                   */
/*--------------------------------------------------------------------------*/
