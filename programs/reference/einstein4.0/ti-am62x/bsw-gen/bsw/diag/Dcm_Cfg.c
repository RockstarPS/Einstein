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
*  File Name         :  Dcm_Cfg.c                                            *
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
#ifndef DCM_CFG_C_
#define DCM_CFG_C_

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "Dcm.h"
#include "Dcm_Cfg.h"
#include "Dcm_Dsp.h"
#include "Dem.h"
#include "PduR_Cfg.h"
#include "ComM_Cfg.h"



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
const Dcm_DsdSidTabServiceIdType Dcm_DsdSidTabServiceId[DcmNumOfSIDSupported+1] =
{
  DcmNumOfSIDSupported,
  0x10, /* DiagnosticSessionControl service                           */
  0x11, /* EcuReset service                                           */
  0x14, /* Clear DiagnosticInformation Service                        */
  0x19, /* ReadDTCInformation service                                 */
  0x22, /* ReadDataByIdentifier service                               */
  0x23, /* ReadMemoryByAddress service                                */
  0x27, /* SecurityAccess service                                     */
  0x28, /* Communication Control service                              */
  0x2E, /* WriteDataByIdentifier service                              */
  0x2F, /* InputOutputControlByIdentifier service                     */
  0x31, /* RoutineControl service                                     */
  0x34, /* Request Download service                                   */
  0x36, /* Transfer Data service                                      */
  0x37, /* Request Transfer Exit                                      */
  0x3D, /* WriteMemoryByAddress service                               */
  0x3E, /* TesterPresent service                                      */
  0x85  /* ControlDTCSetting Service                                  */
  };

const Dcm_DsdSidTabServiceInfoType Dcm_DsdSidTabServiceInfo[DcmNumOfSIDSupported] =
{
  /*DcmDsdSidTabFnc, Props, Length, State_Ref */
  {Dcm_10ServiceProcess ,0x03 ,0x02 ,0x00},
  {Dcm_11ServiceProcess ,0x03 ,0x02 ,0x01},
  {Dcm_14ServiceProcess ,0x00 ,0x00 ,0x02},
  {Dcm_19ServiceProcess ,0x03 ,0x02 ,0x02},
  {Dcm_22ServiceProcess ,0x00 ,0x03 ,0x03},
  {Dcm_23ServiceProcess ,0x02 ,0x0A ,0x04},
  {Dcm_27ServiceProcess ,0x01 ,0x02 ,0x0C},
  {Dcm_28ServiceProcess ,0x03 ,0x02 ,0x06},
  {Dcm_2EServiceProcess ,0x00 ,0x03 ,0x07},
  {Dcm_2FServiceProcess ,0x02 ,0x04 ,0x07},
  {Dcm_31ServiceProcess ,0x00 ,0x04 ,0x00},
  {Dcm_34ServiceProcess ,0x00 ,0x02 ,0x15},
  {Dcm_36ServiceProcess ,0x00 ,0x00 ,0x15},
  {Dcm_37ServiceProcess ,0x00 ,0x00 ,0x15},
  {Dcm_3DServiceProcess ,0x00 ,0x02 ,0x04},
  {Dcm_3EServiceProcess ,0x03 ,0x02 ,0x0A},
  {Dcm_85ServiceProcess ,0x03 ,0x02 ,0x0B},
};

const Dcm_DsdStateRefType Dcm_DsdStateRef[DcmDsdNumOfStateRef] =
{
  /* Session bits: 
      0 - Default 
      1 - Progr
      2 - Extended
      3 - Factory 0x60 
  */
  /* Security bits:
      0 - No security
      1 - Level 2
      2 - Level 5
      3 - EOL
  */
  /* Session , Security*/
		{0x1F, 0x01},  /*0 All session and no security */
		{0x09, 0x01},  /*1 Default and FOTA session with no security */
		{0x0D, 0x01}, /*2 Default, Extended FOTA and no security */
		{0x1D, 0x01}, /*3 All session except prog & No security */
		{0x04, 0x02}, /*4 Exten with L1 security */
		{0x15, 0x07}, /*5 Default,Ext and MEET with all security */
		{0x05, 0x01}, /*6 Default,Ext with no security */
		{0x1C, 0x01}, /*7 Ext, FOTA and MEET with no sec */
		{0x14, 0x07}, /*8 Ext and MEET with all security */
		{0x08, 0x01}, /*9 FOTA with no security */
		{0x1F, 0x07}, /*A All sessions with all security*/
		{0x04, 0x01}, /*B Ext with no security */
		{0x05, 0x03}, /*C Default and Ext with no and L1 security */
		{0x17, 0x01}, /*D All session except FOTA with no security */
		{0x15, 0x05}, /*E Default Ext and MEET with no security and L61 */
		{0x06, 0x03}, /*F Prog and Ext with no security and L1 */
		{0x01, 0x01}, /*10 Default with no security */
		{0x11, 0x01}, /*11 Default and MEET with no security */
		{0x14, 0x06}, /*12 Ext and MEET with L1 and L61 security */
		{0x10, 0x04}, /*13 MEET with L61 security */
		{0x11, 0x04}, /*14 MEET with L61 security */
		{0x01, 0x02}  /*15 Default Session with L1 Security - FOTA */
};

#if((DcmDsdRequestManufacturerNotificationEnabled == STD_ON) || (DcmDsdRequestSupplierNotificationEnabled == STD_ON))
/* Functions shall return only DCM_E_OK, DCM_E_NOT_OK(with corresponded ErrorCode), DCM_E_REQUEST_NOT_ACCEPTED */
const XXX_IndicationType ServiceRequestIndicationTable[NO_OF_REQUEST_NOTIFICATION] =
{
	{RequestIndication_0_Indication}
};

const XXX_ConfirmationType ServiceRequestConfirmationTable[NO_OF_CONFIRMATION_NOTIFICATION] =
{
	{RespConfirmation_0}
};
#endif

const Dcm_DsdSubService10Type Dcm_DsdSubService10[NO_OF_SUPPORTTED_SESSIONS] =
{
  /* SubServiceFnc         SubServiceId, State_Ref */
  {Dcm_01DefaultProcess,     0x01, 0x00},
  {Dcm_02PgmProcess,         0x02, 0x00},
  {Dcm_03ExtnDiagProcess,    0x03, 0x0D},
  {DcmExt_42DiagProcess,     0x42, 0x01},
  {DcmExt_60DiagProcess,     0x60, 0x0E}
};

const Dcm_DsdSubService28Type Dcm_DsdSubService28[NO_OF_SUPPORTTED_COM_CONTROL] =
{
    /* ControlType   CommunicationType */
    {0x03, 0x03},
    {0x01, 0x00}
};

const Dcm_DsdSubService11Type Dcm_DsdSubService11[Svc11NumOfSubFunc] =
{
  /* SubServiceFnc          State_Ref    SubServiceId */
  {DcmExt_PerformReset_001, 0x0A,        0x01},
};


const Dcm_DsdSubService27Type Dcm_DsdSubService27[No_of_security_level*2] =
{
    /* SubServiceFnc, SubServiceId, Req_Length, Resp_Length, State_Ref */
		{DcmExt_SecLevel1GetSeed, 0x01, 1, 16, 0x0C},
		{DcmExt_SecLevel1CmpKey,  0x02, 17, 2, 0x0C},
		{DcmExt_SecLevel61GetSeed, 0x61, 1, 4, 0x0E},
		{DcmExt_SecLevel61CmpKey,  0x62, 5, 2, 0x0E}
};

const Dcm_DsdSubService85Type Dcm_DsdSubService85[Svc85NumOfsubFunc] =
{
  { Dem_EnableDTCSetting , 1, 0},
  { Dem_DisableDTCSetting, 2, 0}
};

const Dcm_DsdSubService19Type Dcm_DsdSubService19[Svc19NumOfsubFunc] =
{
  {Dcm_DspService19_01Processor,0x01,2,0x02},
  {Dcm_DspService19_02Processor,0x02,2,0x02},
#if (DCM_SVC_19_03_SUPPORT_ENABLED == STD_ON)
  {Dcm_DspService19_03Processor,0x03,2,0x06},
#endif
#if (DCM_SVC_19_04_SUPPORT_ENABLED == STD_ON)
  {Dcm_DspService19_04Processor,0x04,2,0x06},
#endif
#if (DCM_SVC_19_06_SUPPORT_ENABLED == STD_ON)
  {Dcm_DspService19_06Processor,0x06,6,0x06},
#endif
#if (DCM_SVC_19_07_SUPPORT_ENABLED == STD_ON)
  {Dcm_DspService19_07Processor,0x07,4,0x06},
#endif
#if (DCM_SVC_19_08_SUPPORT_ENABLED == STD_ON)
  {Dcm_DspService19_08Processor,0x08,4,0x06},
#endif
#if (DCM_SVC_19_09_SUPPORT_ENABLED == STD_ON)
  {Dcm_DspService19_09Processor,0x09,5,0x06},
#endif
#if (DCM_SVC_19_0A_SUPPORT_ENABLED == STD_ON)
  {Dcm_DspService19_0AProcessor,0x0A,2,0x02},
#endif
#if (DCM_SVC_19_0C_SUPPORT_ENABLED == STD_ON)
  {Dcm_DspService19_0CProcessor,0x0C,2,0x06},
#endif
#if (DCM_SVC_19_0E_SUPPORT_ENABLED == STD_ON)
  {Dcm_DspService19_0EProcessor,0x0E,2,0x06},
#endif
#if (DCM_SVC_19_14_SUPPORT_ENABLED == STD_ON)
  {Dcm_DspService19_14Processor,0x14,2,0x06}
#endif
};

#if(DCM_SVC_86_SUPPORT_ENABLED == STD_ON)
const Dcm_DsdSubService86Type Dcm_DsdSubService86[Svc86NumOfsubFunc] =
{
  /*(*SubServiceFnc),  SubServiceId, Length*/
  {Dcm_DspService0x86_0x00Processor, 0x00 /* stopResponseOnEvent */      , 0x2u },
  {Dcm_DspService0x86_0x01Processor, 0x01 /* onDTCStatusChange */        , 0x4u },
  {Dcm_DspService0x86_0x05Processor, 0x05 /* startResponseOnEvent */     , 0x2u },
  {Dcm_DspService0x86_0x06Processor, 0x06 /* clearResponseOnEvent */     , 0x2u }
};

const DcmDspRoeEventType DcmDspRoeEvent[Svc86NumOfROE] =
{
  /* Id, InitStatus, Prop, WindowTime, StorageState */
    {0x0, DCM_ROE_CLEARED, DCM_ROE_ONDTCSTATUSCHANGE, DCM_ROE_EVENT_WINDOW_CURRENT_CYCLE, FALSE}
};

const Dcm_DspRoeOnDTCStatusChangeType Dcm_DspRoeOnDTCStatusChange =
{
    /* Strtrd */
    {0x19, 0x0E}
};

const Dcm_DspRoeType Dcm_DspRoe =
{
    /* InterMessageTime */
    1000u
};

#if(DCM_SVC_86_EMULATION_ENABLED == STD_ON)
boolean IsEventOccurred;
#endif
#endif /* (DCM_SVC_86_SUPPORT_ENABLED == STD_ON) */

#if(DCM_SVC_87_SUPPORT_ENABLED == STD_ON)
#ifndef VCAST_UNIT_TEST_DCM
const
#endif
Dcm_LinkControlTypeInfo Dcm_LinkControlTypeEnable[NO_OF_LINK_CTRL_TYPES] = 
{
/* CtrlType, Length, State_Ref, IsEnabled */
  {LC_VMTWFP, 2, 0x0E, TRUE},
  {LC_VMTWSP, 4, 0x0E, FALSE},
  {LC_TM,     1, 0x0E, TRUE}
};

#ifndef VCAST_UNIT_TEST_DCM
const
#endif
Dcm_LinkControlModeIdentifierInfo Dcm_LinkControlModeEnable[NO_OF_LINK_CTRL_MODES] = 
{
/* used for Mode LC_VMTWFP */

/* CtrlMode, IsEnabled, SubServiceFnc_VMTWFP */
  { 0x01, FALSE, NULL}, /* PC9600Baud       */
  { 0x02, FALSE, NULL}, /* PC19200Baud      */
  { 0x03, FALSE, NULL}, /* PC38400Baud      */
  { 0x04, FALSE, NULL}, /* PC57600Baud      */
  { 0x05, FALSE, NULL}, /* PC115200Baud     */
  { 0x10, FALSE, NULL}, /* CAN125000Baud    */
  { 0x11, FALSE, NULL}, /* CAN250000Baud    */
  { 0x12, TRUE,  NULL}, /* CAN500000Baud    */
  { 0x13, FALSE, NULL}, /* CAN1000000Baud   */
  { 0x20, FALSE, NULL}  /* ProgrammingSetup */
};

#ifndef VCAST_UNIT_TEST_DCM
const
#endif
Dcm_LinkRecordIdentifierInfo Dcm_LinkRecordEnable[NO_OF_LINK_REC_MODES] = 
{
/* used for Mode LC_VMTWSP */

/* LinkRecord, SubServiceFnc_VMTWSP */
  { 125000uL, NULL}, /* 125 k */
  { 250000uL, NULL}, /* 250 k */
  { 500000uL, NULL}  /* 500 k */
};

#ifndef VCAST_UNIT_TEST_DCM
const
#endif
Dcm_LinkTransitionModeInfo Dcm_LinkTransitionMode = 
{
/* used for Mode LC_TM */

/* SubServiceFnc_TM */
  NULL
};

#ifdef VCAST_UNIT_TEST_DCM
Std_ReturnType Fnc87_VMTWFP(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *Buff, Dcm_NegativeResponseCodeType *NegRes)
{
  return DCM_E_OK;
}

Std_ReturnType Fnc87_VMTWSP(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *Buff, Dcm_NegativeResponseCodeType *NegRes)
{
  return DCM_E_OK;
}

Std_ReturnType Fnc87_TM(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *Buff, Dcm_NegativeResponseCodeType *NegRes)
{
  return DCM_E_OK;
}

Std_ReturnType Fnc87_VMTWFP2(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *Buff, Dcm_NegativeResponseCodeType *NegRes)
{
  return DCM_E_NOT_OK;
}

Std_ReturnType Fnc87_VMTWSP2(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *Buff, Dcm_NegativeResponseCodeType *NegRes)
{
  return DCM_E_NOT_OK;
}

Std_ReturnType Fnc87_TM2(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *Buff, Dcm_NegativeResponseCodeType *NegRes)
{
  return DCM_E_NOT_OK;
}
#endif /* VCAST_UNIT_TEST_DCM */

#endif /* (DCM_SVC_87_SUPPORT_ENABLED == STD_ON) */


#if((DCM_SVC_23_SUPPORT_ENABLED == STD_ON) ||(DCM_SVC_35_SUPPORT_ENABLED == STD_ON))
const Dcm_DspReadMemoryRangeInfoType Dcm_DspReadMemoryRange[NumOfReadMemoryByAddressRanges] =
{
    /* MemRangeHigh, MemRangeLow, State_Ref */
    {0x8FFFFFFF, 0x80000000, 0x0},
};
#endif

#if((DCM_SVC_3D_SUPPORT_ENABLED == STD_ON) || (DCM_SVC_34_SUPPORT_ENABLED == STD_ON))
const Dcm_DspWriteMemoryRangeInfoType Dcm_DspWriteMemoryRange[NumOfWriteMemoryByAddressRanges] =
{
    /* MemRangeHigh, MemRangeLow, State_Ref */
    {0x4F67FFFF, 0x00000000, 0x15},
};
#endif

const Dcm_DspService34Type Dcm_DspService34 =
{
    /* SubServiceFnc, Req_Length, Resp_Length */
    Dcm_34ServiceCallout, 1, 3
};

const Dcm_DspService34Type Dcm_DspService36 =
{
    /* SubServiceFnc, Req_Length, Resp_Length */
    Dcm_36ServiceCallout, 1, 3
};

const Dcm_DspService34Type Dcm_DspService37 =
{
    /* SubServiceFnc, Req_Length, Resp_Length */
    Dcm_37ServiceCallout, 1, 3
};

const DidOpFuncType DidOpFunc[DidNumOfOpFunc] =
{
  DI_Did_Diag_Action
};

const Dcm_DsdSessionInfoType Dcm_DsdSessionInfo[NO_OF_SUPPORTTED_SESSIONS] =
{
  /*P2 (in mS), P2STAR (in mS), SESSION VALUE*/
  {50, 5000, 0x01},
  {50, 5000, 0x02},
  {50, 5000, 0x03},
  {50, 5000, 0x42},
  {50, 5000, 0x60}
};

const Dcm_DspDidIdentifierTableType Dcm_DspDidIdentifierTable[DcmNumOfDIDSupported+1] =
{
  DcmNumOfDIDSupported,
  0x1111,
  0x2222,
  0x3333,
  0x4444,
  0x5555,
  0x6666,
  0x7777,
  0x8888,
  0x9999,
  0xAAAA,
  0xDEFA,
  0xFD00,
  0XFD01,
  0XFD02,
  0XFD04,
  0XFD05,
  0XFD07,
  0XFD08,
  0XFD45,
  0xFD60,
  0XFD6B,
  0xF781,
  0xFE30,
  0xFE31,
  0xFE32,
  0xFE35,
  0xFE36,
  0x4F09
};

const Dcm_DspDidInfoType Dcm_DspDidInfo[DcmNumOfDIDSupported] =
{
  /* OpInfoRef, Operations  DcmDspDidUsed */
  {0, 0x03, TRUE}, //0x1111 - Read & Write
  {2, 0x02, TRUE}, //0x2222 - Write
  {3, 0x01, FALSE}, //0x3333 - Read
  {4, 0x02, TRUE}, //0x4444 - Write
  {5, 0x03, TRUE}, //0x5555 - Read & Write
  {7, 0x05, TRUE}, //0x6666 - Read & IOControl
  {9,0x04, TRUE}, //0x7777 - Control
  {10,0x01, TRUE}, //0x8888-  Read
  {11,0x03, TRUE},//0x9999 - Read & Write
  {13,0x03, TRUE}, //0xAAAA - Read & Write
  {15, 0x03, TRUE}, //0xDEFA - Write
  {17,0x03, TRUE},//0xFD00- Read & Write
  {19,0x03, TRUE}, //0xFD01 - Read & Write
  {21,0x03, TRUE}, //0xFD02 - Read & Write
  {23,0x03, TRUE}, //0xFD04 - Read & write
  {25, 0x03, TRUE}, //0xFD05 - Read & Write
  {27, 0x03, TRUE}, //0xFD07 - Read & Write
  {29, 0x03, TRUE}, //0xFD08- Read & Write
  {31, 0x03, TRUE}, //0xFD45 - Read & Write
  {33, 0x03, TRUE}, //0xFD60 - Read & Write
  {35,0x03, TRUE}, //0xFD6B - Read & Write
  {37, 0x02, TRUE},  //0xF781 - write(safety FIT)
  {38, 0x01, TRUE}, //0xFE30 - Read
  {39, 0x04, TRUE}, //0xFE32 - IO Control
  {40, 0x04, TRUE}, //0xFE35 - IO Control
  {41, 0x04, TRUE}, //0xFE35 - IO Control
  {42, 0x01, TRUE}, //0xFE35 - IO Control
  {43, 0x02, TRUE}, //0x4F09 - Write
};

const Dcm_DspDidOpInfoType Dcm_DspDidOpInfo[DcmDspNumOfDidOpInfo] =
{
  /*Min_ReqLength, Max_ReqLength, State_Ref, SignalInfo_Ref, CallTypes */
  {0x02, 0x02, 0x06, 0x0, 0x01}, //0x1111 - Read
  {0x02, 0x02, 0x04, 0x0, 0x01}, //0x1111 - Write
  {0x04, 0x0A, 0x04, 0x0, 0x01}, //0x2222 - Write
  {0x02, 0x20, 0x10, 0x0, 0x01}, //0x3333 - Read
  {0x05, 0x05, 0x0C, 0x0, 0x01}, //0x4444 - Write
  {0x08, 0x08, 0x11, 0x0, 0x01}, //0x5555 - Read
  {0x08, 0x08, 0x12, 0x0, 0x01}, //0x5555 - Write
  {0x04, 0x04, 0x11, 0x0, 0x01}, //0x6666 - Read 
  {0x00, 0x03, 0x13, 0x0, 0x0F}, //0x6666 - Control all
  {0x00, 0x07, 0x13, 0x0, 0x09}, //0x7777 - Control STAdjutment & RCTEcu
  {0x00, 0x06, 0x01, 0x0, 0x01}, //0x8888 - Read
  {0x03, 0x03, 0x01, 0x0, 0x01}, //0x9999 - Read
  {0x03, 0x03, 0x09, 0x0, 0x01}, //0x9999 - Write
  {0x03, 0x04, 0x01, 0x0, 0x01}, //0xAAAA - Read
  {0x04, 0x04, 0x09, 0x0, 0x01}, //0xAAAA - Read
  {0x01, 0x01, 0x00, 0x0, 0x01}, //0xDEFA-  Read
  {0x01, 0x01, 0x00, 0x0, 0x01}, //0xDEFA-  Write
  {0x03, 0x03, 0x09, 0x0, 0x01}, //0xFD00 - Read
  {0x17, 0x17, 0x09, 0x0, 0x01}, //0xFD00 - write
  {0x03, 0x03, 0x09, 0x0, 0x01}, //0xFD01 - Read
  {0x17, 0x17, 0x09, 0x0, 0x01}, //0xFD01 - write
  {0x03, 0x03, 0x09, 0x0, 0x01}, //0xFD02 - Read
  {0x10, 0x10, 0x09, 0x0, 0x01}, //0xFD02 - write
  {0x03, 0x03, 0x09, 0x0, 0x01}, //0xFD04 - Read
  {0x03, 0x03, 0x09, 0x0, 0x01}, //0xFD04 - write
  {0x03, 0x03, 0x09, 0x0, 0x01}, //0xFD05 - Read
  {0x03, 0x03, 0x09, 0x0, 0x01}, //0xFD05 - write
  {0x03, 0x03, 0x09, 0x0, 0x01}, //0xFD07 - Read
  {0x03, 0x03, 0x09, 0x0, 0x01}, //0xFD07 - write
  {0x03, 0x03, 0x09, 0x0, 0x01}, //0xFD08 - Read
  {0x03, 0x03, 0x09, 0x0, 0x01}, //0xFD08 - write
  {0x03, 0x03, 0x09, 0x0, 0x01}, //0xFD45 - Read
  {0x09, 0x09, 0x09, 0x0, 0x01}, //0xFD45 - write
  {0x03, 0x03, 0x09, 0x0, 0x01}, //0xFD60 - Read 
  {0x01, 0x01, 0x09, 0x0, 0x01}, //0xFD60 - Write 
  {0x03, 0x03, 0x09, 0x0, 0x01}, //0xFE6B - Read
  {0x01, 0x01, 0x09, 0x0, 0x01}, //0xFD6B-  Write
  {0x01, 0x05, 0x09, 0x0, 0x01}, //0xF781 - Write
  {0x03, 0x03, 0x09, 0x0, 0x01}, //0xFE30 - Read
  {0x00, 0x03, 0x09, 0x0, 0x09}, //0xFE31 - IO Control STAdjutment & RCTEcu 
  {0x00, 0x05, 0x09, 0x0, 0x09}, //0xFE32 - IO Control
  {0x00, 0x02, 0x09, 0x0, 0x09}, //0xFE35 - IO Control STAdjutment & RCTEcu
  {0x00, 0x03, 0x00, 0x0, 0x01}, //0xFE35 - IO Control STAdjutment & RCTEcu
  {0x05, 0x05, 0x00, 0x0, 0x01} // 0x4F09 - Write
};

const Dcm_DspDidSignalInfoType Dcm_DspDidSignalInfo[DcmDspNumOfDidSignalInfo] =
{
  /*  OpFunc, FunClass;*/
  {0, 0x01}
};

const Dcm_DspRidIdentifierTableType Dcm_DspRidIdentifierTable[DcmNumOfRIDSupported+1] =
{
  DcmNumOfRIDSupported,
  0x5001,
  0x5002,
  0x5003,
  0x5004,
  0x5005,
  0xFE34,
  0xFE3B,
  0xFE42,
  0xFF00,
  0xFF01,
  0xFE00
};

const Dcm_DspRidInfoType Dcm_DspRidInfo[DcmNumOfRIDSupported] =
{
  /* SignalInfo_Ref, State_Ref, Operation, RID used */
  { 0, 0x0C, 0x01, TRUE}, // RID 0x5001
  { 1, 0x10, 0x01, TRUE}, // RID 0x5002
  { 2, 0x09, 0x03,TRUE}, // RID 0x5003
  { 4, 0x04, 0x05,TRUE}, // RID 0x5004
  { 6, 0x14, 0x07,TRUE}, // RID 0x5005
  { 9, 0x09, 0x07,TRUE}, // RID 0xFE34
  { 12,0x09, 0x03,TRUE}, // RID 0xFE3B
  { 14,0x09, 0x05,TRUE}, // RID 0xFE42 
  { 16, 0x15, 0x01, TRUE}, // RID 0xFF00
  { 17, 0x15, 0x05, TRUE}, // RID 0xFF01
  { 18, 0x15, 0x05, TRUE}, // RID 0xFE00
};

const Dcm_DspRidSignalInfoType Dcm_DspRidSignalInfo[DcmDspNumOfRidSignalInfo] =
{
  /* RidOpFunc_Ref, Min_ReqLength, Max_ReqLength, Min_RespLength, Max_RespLength, OpType */
  { 0, 0x0, 0x1, 0x0, 0x1, 0x01},// start 0x5001
  { 0, 0x0, 0x1, 0x0, 0x1, 0x01},// start 0x5002
  { 0, 0x0, 0x0, 0x4, 0x7E,0x01},// start 0x5003
  { 0, 0x0, 0x0, 0x0, 0x0, 0x02},// stop 0x5003
  { 0, 0x0, 0x0, 0x6, 0x6, 0x01},// start 0x5004
  { 0, 0x0, 0x0, 0x6, 0x6, 0x04},// request result 0x5004
  { 0, 0x0, 0x0, 0x6, 0x6, 0x01},// start 0x5005
  { 0, 0x0, 0x0, 0x6, 0x6, 0x02},// stop 0x5005
  { 0, 0x0, 0x0, 0x6, 0x6, 0x04},// request result 0x5005
  { 0, 0x2, 0x2, 0x1, 0x1, 0x01},// start 0xFE34
  { 0, 0x0, 0x0, 0x0, 0x0, 0x02},// stop 0xFE34
  { 0, 0x0, 0x1, 0x3, 0x3, 0x04},// request result 0xFE34
  { 0, 0x1, 0x1, 0x2, 0x2, 0x01},// start 0xFE3B
  { 0, 0x0, 0x0, 0x0, 0x0, 0x02},// Stop 0xFE3B 
  { 0, 0x2, 0x2, 0x1, 0x1, 0x01},// start 0xFE42
  { 0, 0x0, 0x0, 0x0, 0x0, 0x02},// Stop 0xFE42
  { 0, 0x8, 0x8, 0x1, 0x1, 0x01},// Start 0xFF00
  { 0, 0x188, 0x188, 0x1, 0x1, 0x01}, // Start 0xFF01
  { 0, 0x0, 0x0, 0x1, 0x1, 0x01},// Start 0xFE00
};

const RidOpFuncType RidOpFunc[RidNumOfOpFunc] =
{
  DI_Rid_Diag_Action
};

const Dcm_SessionCommEnableInfo Dcm_SessionCommEnable[NO_OF_SUPPORTTED_SESSIONS] =
{
  /* Subfunction,Comm_support */
  {1, FALSE},
  {2, TRUE},
  {3, TRUE}
};

#if (DCM_ALFID_EXIST == STD_ON)
const uint8 Dcm_AlfidList[DCM_NUM_ALFID]=
{
  0x44,
  0x22,
  0x11
};
#endif

#if ((DCM_SVC_34_SUPPORT_ENABLED == STD_ON) || (DCM_SVC_35_SUPPORT_ENABLED == STD_ON))
const uint8 Dcm_DfidList[DCM_NUM_DFID]=
{
0x00,
0x01,
0x10,
0x30,
0x11,
0x31
};
#endif

void Dcm_EnterCriticalSection()
{

}

void Dcm_ExitCriticalSection()
{

}


const Dcm_RxPduIdType Dcm_RxPduId[DcmNumofClientSupported] = 
{
  /*{PhyReqId, FuncReqId, PduIdChannelRef},*/
  {DCM_PDU_E4_DIAG_PHY_REQ, DCM_PDU_E4_DIAG_FUNC_REQ, 0},
  {2, 3, 1}
};

const Dcm_PduIdChannelType Dcm_PduIdChannel[DcmNumofClientSupported] =
{
  /*{PhyRespId, ConfRespId, ComMChannelIdRef, ClientPriority, DcmDemClientRef},*/

  {PDUR_SRC_DIAG_RESP_USDT , DCM_PDU_DIAG_RESP_USDT ,0, 14, DEM_DCM_CLIENT},
  {1 , DCM_PDU_OBDC_KOMBI_RESP ,0, 2, DEM_DCM_CLIENT}
};

const Dcm_ComMChannelIDType Dcm_ComMChannelId[ComMChannelSupported] =
{
  /*ComMChannelId*/
    {0}
};


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
/*Date              : 23-Jun-2016                                           */
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
/*Date              : 20-Jan-2017                                           */
/*Version           :                                                       */
/*By                : akalarim                                              */
/*Traceability      : RTC 765864,765855,765852.                             */
/*Change Description: Service 0x14,0x85 and sercice 19 with subfunction 0x01*/
/*                    0x02 and 0x0A Implementation.                         */
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
