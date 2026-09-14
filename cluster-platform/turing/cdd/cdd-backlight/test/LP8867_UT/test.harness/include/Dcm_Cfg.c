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
  0x10, /* DiagnosticSessionControl service         */
  0x11, /* EcuReset service                         */
  0x22, /* ReadDataByIdentifier service             */
  0x23, /* ReadMemoryByAddress service              */
  0x2E, /* WriteDataByIdentifier service            */
  0x31, /* RoutineControl service                   */
  0x34, /* Request Download                         */
  0x36, /* Transfer Data                            */
  0x37, /* Request Transfer Exit                    */
  0x3E, /* TesterPresent service                    */
  0x27, /* SecurityAccess service                   */
  0x14, /* Clear DiagnosticInformation Service      */
  0x19, /* ReadDTCInformation service               */
  0x2F  /* InputOutputControlByIdentifier Service   */
};

const Dcm_DsdSidTabServiceInfoType Dcm_DsdSidTabServiceInfo[DcmNumOfSIDSupported] =
{
  /*DcmDsdSidTabFnc, Props, Length, State_Ref */
  {Dcm_10ServiceProcess, 0x03, 0x02,  0x11},
  {Dcm_11ServiceProcess, 0x03, 0x02,  0x00},
  {Dcm_22ServiceProcess, 0x02, 0x03,  0x11},
  {Dcm_23ServiceProcess, 0x02, 0x0A,  0x04},
  {Dcm_2EServiceProcess, 0x02, 0x03,  0x11},
  {Dcm_31ServiceProcess, 0x03, 0x04,  0x10},
  {Dcm_34ServiceProcess, 0x02, 0x05, 0x08},
  {Dcm_36ServiceProcess, 0x02, 0x03, 0x08},
  {Dcm_37ServiceProcess, 0x00, 0x01, 0x08},
  {Dcm_3EServiceProcess, 0x03, 0x02,  0x11},
  {Dcm_27ServiceProcess, 0x03, 0x02,  0x19},
  {Dcm_14ServiceProcess, 0x02, 0x00,  0x04},
  {Dcm_19ServiceProcess, 0x03, 0x02,  0x01},
  {Dcm_2FServiceProcess, 0x02, 0x04,  0x0F}
};

const Dcm_DsdStateRefType Dcm_DsdStateRef[DcmDsdNumOfStateRef] =
{
  /* Session , Security*/
  {0x09, 0x1F}, //level1 -  0 0 0  1 Note Bit 0 for security is no security
  {0x0F, 0x1F}, //level 5level2 - 0 0 1 0
  {0x05, 0x1F}, // level 5 EOL 0 1 0 0
  {0x0B, 0x1F}, // level4
  {0x07, 0x1F}, // F188,
  {0x0C, 0x1F},
  {0x0A, 0x1F},
  {0x0E, 0x1F},
  {0x08, 0x1F},
  {0x0D, 0x1F},
  {0x14, 0x0C}, // MEET and extended with MEET security
  {0x04, 0x1F},
  {0x06, 0x1F},
  {0x04, 0x02},
  {0x06, 0x02},
  {0x10, 0x1F},  //MEET session with no security
  {0x1D, 0x1F},
  {0x1F, 0x1F},   //All session with no security
  {0x10, 0x0C}, //MEET session with MEET security
  {0x15, 0x1F},
  {0x14, 0x1F},
  {0x0A, 0x02},
  {0x1E, 0x1F},
  {0x17, 0x1F},
  {0x01, 0x1F},
  {0x16, 0x1F}
};

#if((DcmDsdRequestManufacturerNotificationEnabled == STD_ON) || (DcmDsdRequestSupplierNotificationEnabled == STD_ON))
/* Functions shall return only DCM_E_OK, DCM_E_NOT_OK(with corresponded ErrorCode), DCM_E_REQUEST_NOT_ACCEPTED */
const XXX_IndicationType ServiceRequestIndicationTable[NO_OF_REQUEST_NOTIFICATION] =
{
  DcmExt_ServReqNotif_FOTA_Manufacture_Indication,
  DcmExt_RequestIndication_1,
  DcmExt_RequestIndication_2
};
#endif

const Dcm_DsdSubService10Type Dcm_DsdSubService10[NO_OF_SUPPORTTED_SESSIONS] =
{
  /*SubServiceFnc   SubServiceId State_Ref*/
  {Dcm_01DefaultProcess,  0x01, 0x11},
  {Dcm_02PgmProcess,      0x02, 0x0E},
  {Dcm_03ExtnDiagProcess, 0x03, 0x04},
  {DcmExt_42DiagProcess,  0x42, 0x00},
  {DcmExt_60DiagProcess, 0x60, 0x0A} //extended and meet with meet security
};

#if(DCM_SVC_28_SUPPORT_ENABLED == STD_ON)
const Dcm_DsdSubService28Type Dcm_DsdSubService28[NO_OF_SUPPORTTED_COM_CONTROL] =
{
    /* ControlType   CommunicationType */
    {0x03, 0x03},
};
#endif

const Dcm_DsdSubService11Type Dcm_DsdSubService11[Svc11NumOfSubFunc] =
{
  /*SubServiceFnc            State_Ref  SubServiceId*/
  {DcmExt_PerformReset_001, 0x00,        0x01}   //Default&FOTA with no security - state ref updated as discussion with FOTA team
};
const Dcm_DsdSubService27Type Dcm_DsdSubService27[No_of_security_level*2] =
{
  /* SubServiceFnc, SubServiceId, Req_Length, Resp_Length, State_Ref */
   {SecLevel1GetSeed, 0x01, 1, 256, 0x0C},
   {SecLevel1CmpKey,  0x02, 257, 2, 0x0C},
   {SecLevel61GetSeed,0x61, 1, 256, 0x14},//extended and meet
   {SecLevel62CmpKey, 0x62, 257, 2, 0x14}//extended and meet
};

const Dcm_DsdSubService85Type Dcm_DsdSubService85[Svc85NumOfsubFunc] =
{
    { Dem_DcmEnableDTCSetting , 1,0},
    { Dem_DcmDisableDTCSetting, 2,0}
};

const Dcm_DsdSubService19Type Dcm_DsdSubService19[Svc19NumOfsubFunc] =
{
    {Dcm_DspService19_01Processor,0x01,2,0x02},
    {Dcm_DspService19_02Processor,0x02,2,0x09},
#if (DCM_SVC_19_03_SUPPORT_ENABLED == STD_ON)
    {Dcm_DspService19_03Processor,0x03,1,0x02},
#endif
#if (DCM_SVC_19_04_SUPPORT_ENABLED == STD_ON)
    {Dcm_DspService19_04Processor,0x04,5,0x02},
#endif
#if (DCM_SVC_19_06_SUPPORT_ENABLED == STD_ON)
    {Dcm_DspService19_06Processor,0x06,5,0},
#endif
#if (DCM_SVC_19_07_SUPPORT_ENABLED == STD_ON)
    {Dcm_DspService19_07Processor,0x07,3,0},
#endif
#if (DCM_SVC_19_08_SUPPORT_ENABLED == STD_ON)
    {Dcm_DspService19_08Processor,0x08,3,0},
#endif
#if (DCM_SVC_19_09_SUPPORT_ENABLED == STD_ON)
    {Dcm_DspService19_09Processor,0x09,4,0},
#endif
#if (DCM_SVC_19_0A_SUPPORT_ENABLED == STD_ON)
  {Dcm_DspService19_0AProcessor,0x0A,1,0x08},
#endif
#if (DCM_SVC_19_0C_SUPPORT_ENABLED == STD_ON)
    {Dcm_DspService19_0CProcessor,0x0C,1,0},
#endif
#if (DCM_SVC_19_0E_SUPPORT_ENABLED == STD_ON)
    {Dcm_DspService19_0EProcessor,0x0E,1,0},
#endif
    {Dcm_DspService19_14Processor,0x14,1,0x08}
};

#if(DCM_SVC_86_SUPPORT_ENABLED == STD_ON)
const Dcm_DsdSubService86Type Dcm_DsdSubService86[Svc86NumOfsubFunc] =
{
  /*(*SubServiceFnc),  SubServiceId, Length*/
  {Dcm_DspService0x86_0x00Processor, 0x00/*stopResponseOnEvent*/      , 0x2u },
  {Dcm_DspService0x86_0x01Processor, 0x01/*onDTCStatusChange*/        , 0x4u },
  {Dcm_DspService0x86_0x05Processor, 0x05/*startResponseOnEvent*/     , 0x2u },
  {Dcm_DspService0x86_0x06Processor, 0x06/*clearResponseOnEvent*/     , 0x2u }
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
Std_ReturnType Fnc87_VMTWFP(Dcm_MsgContextType *Buff, Dcm_NegativeResponseCodeType *NegRes)
{
  return DCM_E_OK;
}

Std_ReturnType Fnc87_VMTWSP(Dcm_MsgContextType *Buff, Dcm_NegativeResponseCodeType *NegRes)
{
  return DCM_E_OK;
}

Std_ReturnType Fnc87_TM(Dcm_MsgContextType *Buff, Dcm_NegativeResponseCodeType *NegRes)
{
  return DCM_E_OK;
}

Std_ReturnType Fnc87_VMTWFP2(Dcm_MsgContextType *Buff, Dcm_NegativeResponseCodeType *NegRes)
{
  return DCM_E_NOT_OK;
}

Std_ReturnType Fnc87_VMTWSP2(Dcm_MsgContextType *Buff, Dcm_NegativeResponseCodeType *NegRes)
{
  return DCM_E_NOT_OK;
}

Std_ReturnType Fnc87_TM2(Dcm_MsgContextType *Buff, Dcm_NegativeResponseCodeType *NegRes)
{
  return DCM_E_NOT_OK;
}
#endif /* VCAST_UNIT_TEST_DCM */

#endif /* (DCM_SVC_87_SUPPORT_ENABLED == STD_ON) */


#if(DCM_SVC_23_SUPPORT_ENABLED == STD_ON)
const Dcm_DspReadMemoryRangeInfoType Dcm_DspReadMemoryRange[NumOfReadMemoryByAddressRanges] =
{
    /* MemRangeHigh, MemRangeLow, State_Ref */
    {0x8FFFFFFF, 0x80000000, 0x0},
    {0x9FFFFFFF, 0x90000000, 0x0},
};
#endif

#if(DCM_SVC_3D_SUPPORT_ENABLED == STD_ON)
const Dcm_DspWriteMemoryRangeInfoType Dcm_DspWriteMemoryRange[NumOfWriteMemoryByAddressRanges] =
{
    /* MemRangeHigh, MemRangeLow, State_Ref */
    {0x8FFFFFFF, 0x80000000, 0x0},
    {0x9FFFFFFF, 0x90000000, 0x0},
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
  {50, 5000, 0x42},  //FOTA
  {50, 5000, 0x60}  //MEET
};

const Dcm_DspDidIdentifierTableType Dcm_DspDidIdentifierTable[DcmNumOfDIDSupported+1] =
{
  DcmNumOfDIDSupported,
  0xF0A1,
  0xF0B0,
  0xF0B1,
  0xF0B2,
  0xF0B3,
  0xF0B4,
  0xF0B5,
  0xF0B6,
  0xF0B7,
  0xF0B8,
  0xF0B9,
  0xF0BA,
  0xF0BB,
  0xF1A2,
  0xF188,
  0x0E24,
  0x0E29,
  0x0E2C,
  0x0E12,
  0x0E2B,
  0x0E14,
  0x0E15,
  0x0E16,
  0x0E17,
  0x0E18,
  0x0E10,
  0x0E22,
  0x0E1A,
  0x0E1B,
  0x0E1D,
  0x0E1C,
  0x0E1E,
  0x0E1F,
  0x0E20,
  0x0E21,
  0x0E08,
  0x0E09,
  0x0E0A,
  0x0E19,
  0x0E07,
  0x0E0B,
  0x0E0C,
  0xF40D,
  0x0E00,
  0x0E01,
  0x0E02,
  0x0E03,
  0x0E04,
  0x0E05,
  0x0E0D,
  0x0E2A,
  0x0E80,
  0x0E13,
  0x0E0E,
  0x0E25,
  0x0E26,
  0x0E27,
  0x0E28,
  0x0E0F,
  0x0E11,
  0xFD00,
  0xF18C,
  0xF010,
  0xF011,
  0xF012,    //App & MEET
  0xF0A0,
  0xF0A5,
  0xF013,    //App & MEET
  0xF194,
  0xF195,
  0xF18A,
  0xF1A0,
  0xDA00,
  0xDA01,
  0xDA02,
  0xDA03,
  0xDA10,
  0xDA11,
  0xDA12,
  0xDA13,
  0xDA14,
  0xDA15,
  0xDA16,
  0xDA17,
  0xDA18,
  0xDA19,
  0xDA1A,
  0xDA1B,
  0xDA1C,
  0xDA1D,
  0xDA1E,
  0xDA1F,
  0xF191,    //App & MEET
  0xF187,
  0xF1A1,
  0xF190,
  0x0E90,
  0xDA70,
  0xF080,
  0xF081,
  0xF082,
  0xF083,
  0xF084,
  0xF085,
  0xF086,
  0xF087,
  0xF088,
  0xF089,
  0xF08A,
  0xF08B,
  0xF08C,
  0xF062,
  0xFE4C,   //MEET
  0xFE45,   //MEET
  0xFE38,   //MEET
  0xFE30,   //MEET
  0xFE14,   //MEET
  0xFE13,   //MEET
  0xFE03,   //MEET
  0xFE00,   //MEET
  0xFE01,   //MEET
  0xFE02,   //MEET
  0xFE07,   //MEET
  0xFE08,   //MEET
  0xFEF3,   //MEET
  0xFEF4,   //MEET
  0xFEF5,   //MEET
  0xFE5E,   //MEET
  0xFE51,   //MEET
  0xFE4D,   //MEET
  0xFE47,   //MEET
  0xFE1B,   //MEET
  0xFE1C,   //MEET
  0xFE1D,   //MEET
  0xFE1E,   //MEET
  0xFE1F,   //MEET
  0xFE15,   //MEET
  0xFE16,   //MEET
  0xFE0E,   //MEET
  0xFE0D,   //MEET
  0xFE09,   //MEET
  0xFE04,   //MEET
  0xFE05,   //MEET
  0xFE06,   //MEET
  0xFE50,   //MEET
  0xFE52,   //MEET
  0xF0A7,
  0xF0AC,
  0xF0BC,
  0xF0AB,
  0xFD01,
  0xF000,   //MEET
  0xF001,   //MEET
  0xF002,   //MEET
  0xFE10,   //MEET
  0xFEFD    //MEET
};

const Dcm_DspDidInfoType Dcm_DspDidInfo[DcmNumOfDIDSupported] =
{
  /* OpInfoRef, Operations */
  {0,   0x01}, //0xF0A1 - Read
  {1,   0x02}, //0xF0B0 - Write
  {2,   0x02}, //0xF0B1 - Write
  {3,   0x02}, //0xF0B2 - Write
  {4,   0x02}, //0xF0B3 - Write
  {5,   0x02}, //0xF0B4 - Write
  {6,   0x02}, //0xF0B5 - Write
  {7,   0x02}, //0xF0B6 - Write
  {8,   0x02}, //0xF0B7 - Write
  {9,   0x02}, //0xF0B8 - Write
  {10,  0x02}, //0xF0B9 - Write
  {11,  0x02}, //0xF0BA - Write
  {12,  0x02}, //0xF0BB - Write
  {13,  0x01}, //0xF1A2 - Read
  {14,  0x01}, //0xF188 - Read
  {15,  0x01}, //0x0E24 - Read
  {16,  0x01}, //0x0E29 - Read
  {17,  0x01}, //0x0E2C - Read
  {18,  0x01}, //0x0E12 - Read
  {19,  0x01}, //0x0E2B - Read
  {20,  0x01}, //0x0E14 - Read
  {21,  0x01}, //0x0E15 - Read
  {22,  0x01}, //0x0E16 - Read
  {23,  0x01}, //0x0E17 - Read
  {24,  0x01}, //0x0E18 - Read
  {25,  0x01}, //0x0E10 - Read
  {26,  0x01}, //0x0E22 - Read
  {27,  0x01}, //0x0E1A - Read
  {28,  0x01}, //0x0E1B - Read
  {29,  0x01}, //0x0E1D - Read
  {30,  0x01}, //0x0E1C - Read
  {31,  0x01}, //0x0E1E - Read
  {32,  0x01}, //0x0E1F - Read
  {33,  0x01}, //0x0E20 - Read
  {34,  0x01}, //0x0E21 - Read
  {35,  0x01}, //0x0E08 - Read
  {36,  0x01}, //0x0E09 - Read
  {37,  0x01}, //0x0E0A - Read
  {38,  0x01}, //0x0E19 - Read
  {39,  0x01}, //0x0E07 - Read
  {40,  0x01}, //0x0E0B - Read
  {41,  0x01}, //0x0E0C - Read
  {42,  0x01}, //0xF40D - Read
  {43,  0x01}, //0x0E00 - Read
  {44,  0x01}, //0x0E01 - Read
  {45,  0x01}, //0x0E02 - Read
  {46,  0x01}, //0x0E03 - Read
  {47,  0x01}, //0x0E04 - Read
  {48,  0x01}, //0x0E05 - Read
  {49,  0x01}, //0x0E0D - Read
  {50,  0x01}, //0x0E2A - Read
  {51,  0x01}, //0x0E80 - Read
  {52,  0x01}, //0x0E13 - Read
  {53,  0x01}, //0x0E0E - Read
  {54,  0x01}, //0x0E25 - Read
  {55,  0x01}, //0x0E26 - Read
  {56,  0x01}, //0x0E27 - Read
  {57,  0x01}, //0x0E28 - Read
  {58,  0x01}, //0x0E0F - Read
  {59,  0x01}, //0x0E11 - Read
  {60,  0x03}, //0xFD00 - Read and Write
  {62,  0x01}, //0xF18C - Read
  {63,  0x01}, //0xF010 - Read
  {64,  0x01}, //0xF011 - Read
  {65,  0x03}, //0xF012 - Read and Write
  {67,  0x01}, //0xF0A0 - Read
  {68,  0x03}, //0xF0A5 - Read and Write
  {70,  0x03}, //0xF013 - Read and Write
  {72,  0x01}, //0xF194 - Read
  {73,  0x01}, //0xF195 - Read
  {74,  0x01}, //0xF18A - Read
  {75,  0x01}, //0xF1A0 - Read
  {76,  0x01}, //0xDA00 - Read
  {77,  0x01}, //0xDA01 - Read
  {78,  0x01}, //0xDA02 - Read
  {79,  0x01}, //0xDA03 - Read
  {80,  0x01}, //0xDA10 - Read
  {81,  0x01}, //0xDA11 - Read
  {82,  0x01}, //0xDA12 - Read
  {83,  0x01}, //0xDA13 - Read
  {84,  0x01}, //0xDA14 - Read
  {85,  0x01}, //0xDA15 - Read
  {86,  0x01}, //0xDA16 - Read
  {87,  0x01}, //0xDA17 - Read
  {88,  0x01}, //0xDA18 - Read
  {89,  0x01}, //0xDA19 - Read
  {90,  0x01}, //0xDA1A - Read
  {91,  0x01}, //0xDA1B - Read
  {92,  0x01}, //0xDA1C - Read
  {93,  0x01}, //0xDA1D - Read
  {94,  0x01}, //0xDA1E - Read
  {95,  0x01}, //0xDA1F - Read
  {96,  0x03}, //0xF191 - Read & Write MEET
  {98,  0x01}, //0xF187 - Read
  {99,  0x01}, //0xF1A1 - Read
  {100, 0x03}, //0xF190 - Read & Write
  {102, 0x01}, //0x0E90 - Read
  {103, 0x01}, //0xDA70 - Read
  {104, 0x03}, //0xF080 - Read & Write
  {106, 0x03}, //0xF081 - Read & Write
  {108, 0x03}, //0xF082 - Read & Write
  {110, 0x03}, //0xF083 - Read & Write
  {112, 0x03}, //0xF084 - Read & Write
  {114, 0x03}, //0xF085 - Read & Write
  {116, 0x03}, //0xF086 - Read & Write
  {118, 0x03}, //0xF087 - Read & Write
  {120, 0x03}, //0xF088 - Read & Write
  {122, 0x03}, //0xF089 - Read & Write
  {124, 0x03}, //0xF08A - Read & Write
  {126, 0x03}, //0xF08B - Read & Write
  {128, 0x03}, //0xF08C - Read & Write
  {130, 0x03}, //0xF062 - Read & Write
  {132, 0x03}, //0xFE4C - Read & Write MEET
  {134, 0x03}, //0xFE45 - Read & Write MEET
  {136, 0x01}, //0xFE38 - Read MEET
  {137, 0x03}, //0xFE30 - Read & Write MEET
  {139, 0x03}, //0xFE14 - Read & Write MEET
  {141, 0x03}, //0xFE13 - Read & Write MEET
  {143, 0x01}, //0xFE03 - Read MEET
  {144, 0x03}, //0xFE00 - Read & Write MEET
  {146, 0x03}, //0xFE01 - Read & Write MEET
  {148, 0x03}, //0xFE02 - Read & Write MEET
  {150, 0x03}, //0xFE07 - Read & Write MEET
  {152, 0x03}, //0xFE08 - Read & Write MEET
  {154, 0x02}, //0xFEF3 - Write MEET
  {155, 0x03}, //0xFEF4 - Read & Write MEET
  {157, 0x03}, //0xFEF5 - Read & Write MEET
  {159, 0x03}, //0xFE5E - Read & Write MEET
  {161, 0x04}, //0xFE51 - IOControl MEET
  {162, 0x03}, //0xFE4D - Read & Write MEET
  {164, 0x03}, //0xFE47 - Read & Write MEET
  {166, 0x03}, //0xFE1B - Read & Write MEET
  {168, 0x03}, //0xFE1C - Read & Write MEET
  {170, 0x03}, //0xFE1D - Read & Write MEET
  {172, 0x03}, //0xFE1E - Read & Write MEET
  {174, 0x03}, //0xFE1F - Read & Write MEET
  {176, 0x04}, //0xFE15 - IOControl MEET
  {177, 0x01}, //0xFE16 - Read MEET
  {178, 0x04}, //0xFE0E - IOControl MEET
  {179, 0x04}, //0xFE0D - IOControl MEET
  {180, 0x03}, //0xFE09 - Read & Write MEET
  {182, 0x03}, //0xFE04 - Read & Write MEET
  {184, 0x04}, //0xFE05 - IOControl MEET
  {185, 0x04}, //0xFE06 - IOControl MEET
  {186, 0x01}, //0xFE50 - Read MEET
  {187, 0x04}, //0xFE52 - IOControl MEET
  {188, 0x02}, //0xF0A7 - Write
  {189, 0x02}, //0xF0AC - Write
  {190, 0x02}, //0xF0BC - Write
  {191, 0x01}, //0xF0AB - Read
  {192, 0x01}, //0xFD01 - Read
  {193, 0x03}, //0xF000 - Read & Write MEET
  {195, 0x03}, //0xF001 - Read & Write MEET
  {197, 0x03}, //0xF002 - Read & Write MEET
  {199, 0x01}, //0xFE10 - Read
  {200, 0x01}, //0xFEFD - Read
};
const Dcm_DspDidOpInfoType Dcm_DspDidOpInfo[DcmDspNumOfDidOpInfo] =
{
  /*Min_ReqLength, Max_ReqLength, State_Ref, SignalInfo_Ref, CallTypes */
  {0x00,  0x00,  0x00, 0x0, 0x01}, //0xF0A1  - Read
  {0x10,  0x10,  0x08, 0x0, 0x01}, //0xF0B0  - Write
  {0x10,  0x10,  0x08, 0x0, 0x01}, //0xF0B1  - Write
  {0x04,  0x04,  0x08, 0x0, 0x01}, //0xF0B2  - Write
  {0x01,  0x01,  0x08, 0x0, 0x01}, //0xF0B3  - Write
  {0x02,  0x02,  0x08, 0x0, 0x01}, //0xF0B4  - Write
  {0x02,  0x02,  0x08, 0x0, 0x01}, //0xF0B5  - Write
  {0x01,  0x01,  0x08, 0x0, 0x01}, //0xF0B6  - Write
  {0x01,  0x01,  0x08, 0x0, 0x01}, //0xF0B7  - Write
  {0x01,  0x01,  0x08, 0x0, 0x01}, //0xF0B8  - Write
  {0x01,  0x01,  0x08, 0x0, 0x01}, //0xF0B9  - Write
  {0x01,  0x01,  0x08, 0x0, 0x01}, //0xF0BA  - Write
  {0x01,  0x01,  0x08, 0x0, 0x01}, //0xF0BB  - Write
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0xF1A2  - Read
  {0x00,  0x00,  0x09, 0x0, 0x01}, //0xF188  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0x0E24  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0x0E29  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0x0E2C  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0x0E12  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0x0E2B  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0x0E14  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0x0E15  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0x0E16  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0x0E17  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0x0E18  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0x0E10  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0x0E22  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0x0E1A  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0x0E1B  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0x0E1D  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0x0E1C  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0x0E1E  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0x0E1F  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0x0E20  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0x0E21  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0x0E08  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0x0E09  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0x0E0A  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0x0E19  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0x0E07  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0x0E0B  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0x0E0C  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0xF40D  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0x0E00  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0x0E01  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0x0E02  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0x0E03  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0x0E04  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0x0E05  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0x0E0D  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0x0E2A  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0x0E80  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0x0E13  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0x0E0E  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0x0E25  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0x0E26  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0x0E27  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0x0E28  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0x0E0F  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0x0E11  - Read
  {0x00,  0x00,  0x01, 0x0, 0x01}, //0xFD00  - Read
  {0x100, 0x100, 0x08, 0x0, 0x01}, //0xFD00  - Write only in FOTA without security
  {0x00,  0x00,  0x01, 0x0, 0x01}, //0xF18C  - Read
  {0x00,  0x00,  0x04, 0x0, 0x01}, //0xF010  - Read
  {0x00,  0x00,  0x04, 0x0, 0x01}, //0xF011  - Read
  {0x00,  0x00,  0x17, 0x0, 0x01}, //0xF012  - Read
  {0x0A,  0x0A,  0x0F, 0x0, 0x01}, //0xF012  - Write only in MEET
  {0x00,  0x00,  0x00, 0x0, 0x01}, //0xF0A0  - Read
  {0x00,  0x00,  0x18, 0x0, 0x01}, //0xF0A5  - Read
  {0x01,  0x01,  0x0D, 0x0, 0x01}, //0xF0A5  - Write only ext with security
  {0x00,  0x00,  0x11, 0x0, 0x01}, //0xF013  - Read
  {0x0A,  0x0A,  0x0F, 0x0, 0x01}, //0xF013  - Write only in MEET
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0xF194  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0xF195  - Read
  {0x00,  0x00,  0x04, 0x0, 0x01}, //0xF18A  - Read
  {0x00,  0x00,  0x01, 0x0, 0x01}, //0xF1A0  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0xDA00  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0xDA01  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0xDA02  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0xDA03  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0xDA10  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0xDA11  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0xDA12  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0xDA13  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0xDA14  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0xDA15  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0xDA16  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0xDA17  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0xDA18  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0xDA19  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0xDA1A  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0xDA1B  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0xDA1C  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0xDA1D  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0xDA1E  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0xDA1F  - Read
  {0x00,  0x00,  0x13, 0x0, 0x01}, //0xF191  - Read
  {0x0A,  0x0A,  0x0F, 0x0, 0x01}, //0xF191  - Write only in MEET
  {0x00,  0x00,  0x01, 0x0, 0x01}, //0xF187  - Read
  {0x00,  0x00,  0x01, 0x0, 0x01}, //0xF1A1  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0xF190  - Read
  {0x11,  0x11,  0x0D, 0x0, 0x01}, //0xF190  - Write only ext with security
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0x0E90  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0xDA70  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0xF080  - Read
  {0x10,  0x10,  0x0D, 0x0, 0x01}, //0xF080  - Write
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0xF081  - Read
  {0x10,  0x10,  0x0D, 0x0, 0x01}, //0xF081  - Write
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0xF082  - Read
  {0x04,  0x04,  0x0D, 0x0, 0x01}, //0xF082  - Write
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0xF083  - Read
  {0x01,  0x01,  0x0D, 0x0, 0x01}, //0xF083  - Write
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0xF084  - Read
  {0x02,  0x02,  0x0D, 0x0, 0x01}, //0xF084  - Write
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0xF085  - Read
  {0x02,  0x02,  0x0D, 0x0, 0x01}, //0xF085  - Write
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0xF086  - Read
  {0x01,  0x01,  0x0D, 0x0, 0x01}, //0xF086  - Write
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0xF087  - Read
  {0x01,  0x01,  0x0D, 0x0, 0x01}, //0xF087  - Write
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0xF088  - Read
  {0x01,  0x01,  0x0D, 0x0, 0x01}, //0xF088  - Write
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0xF089  - Read
  {0x01,  0x01,  0x0D, 0x0, 0x01}, //0xF089  - Write
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0xF08A  - Read
  {0x01,  0x01,  0x0D, 0x0, 0x01}, //0xF08A  - Write
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0xF08B  - Read
  {0x01,  0x01,  0x0D, 0x0, 0x01}, //0xF08B  - Write
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0xF08C  - Read
  {0x0A,  0x0A,  0x0D, 0x0, 0x01}, //0xF08C  - Write
  {0x00,  0x00,  0x04, 0x0, 0x01}, //0xF062  - Read
  {0x01,  0x01,  0x0E, 0x0, 0x01}, //0xF062  - Write
  {0x00,  0x00,  0x0F, 0x0, 0x01}, //0xFE4C  - Read
  {0x01,  0x01,  0x12, 0x0, 0x01}, //0xFE4C  - Write
  {0x00,  0x00,  0x0F, 0x0, 0x01}, //0xFE45  - Read
  {0x05,  0x05,  0x0F, 0x0, 0x01}, //0xFE45  - Write
  {0x00,  0x00,  0x0F, 0x0, 0x01}, //0xFE38  - Read
  {0x00,  0x00,  0x0F, 0x0, 0x01}, //0xFE30  - Read
  {0x0C,  0x0C,  0x0F, 0x0, 0x01}, //0xFE30  - Write
  {0x00,  0x00,  0x0F, 0x0, 0x01}, //0xFE14  - Read
  {0x1E,  0x1E,  0x0F, 0x0, 0x01}, //0xFE14  - Write
  {0x00,  0x00,  0x0F, 0x0, 0x01}, //0xFE13  - Read
  {0x32,  0x32,  0x0F, 0x0, 0x01}, //0xFE13  - Write
  {0x00,  0x00,  0x0F, 0x0, 0x01}, //0xFE03  - Read
  {0x00,  0x00,  0x0F, 0x0, 0x01}, //0xFE00  - Read
  {0x10,  0x10,  0x0F, 0x0, 0x01}, //0xFE00  - Write
  {0x00,  0x00,  0x0F, 0x0, 0x01}, //0xFE01  - Read
  {0x11,  0x11,  0x0F, 0x0, 0x01}, //0xFE01  - Write
  {0x00,  0x00,  0x0F, 0x0, 0x01}, //0xFE02  - Read
  {0x14,  0x14,  0x0F, 0x0, 0x01}, //0xFE02  - Write
  {0x00,  0x00,  0x0F, 0x0, 0x01}, //0xFE07  - Read
  {0x03,  0x03,  0x0F, 0x0, 0x01}, //0xFE07  - Write
  {0x00,  0x00,  0x0F, 0x0, 0x01}, //0xFE08  - Read
  {0x04,  0x04,  0x0F, 0x0, 0x01}, //0xFE08  - Write
  {0x32,  0x32,  0x0F, 0x0, 0x01}, //0xFEF3  - Write
  {0x00,  0x00,  0x0F, 0x0, 0x01}, //0xFEF4  - Read
  {0x01,  0x01,  0x0F, 0x0, 0x01}, //0xFEF4  - Write
  {0x00,  0x00,  0x0F, 0x0, 0x01}, //0xFEF5  - Read
  {0x01,  0x01,  0x0F, 0x0, 0x01}, //0xFEF5  - Write
  {0x00,  0x00,  0x0F, 0x0, 0x01}, //0xFE5E  - Read
  {0x03,  0x03,  0x0F, 0x0, 0x01}, //0xFE5E  - Write
  {0x00,  0x04,  0x0F, 0x0, 0x09}, //0xFE51  - IOControl
  {0x00,  0x00,  0x0F, 0x0, 0x01}, //0xFE4D  - Read
  {0x01,  0x01,  0x0F, 0x0, 0x01}, //0xFE4D  - Write
  {0x00,  0x00,  0x0F, 0x0, 0x01}, //0xFE47  - Read
  {0x08,  0x08,  0x0F, 0x0, 0x01}, //0xFE47  - Write
  {0x00,  0x00,  0x0F, 0x0, 0x01}, //0xFE1B  - Read
  {0x01,  0x01,  0x0F, 0x0, 0x01}, //0xFE1B - Write
  {0x00,  0x00,  0x0F, 0x0, 0x01}, //0xFE1C  - Read
  {0x01,  0x01,  0x0F, 0x0, 0x01}, //0xFE1C  - Write
  {0x00,  0x00,  0x0F, 0x0, 0x01}, //0xFE1D  - Read
  {0x01,  0x01,  0x0F, 0x0, 0x01}, //0xFE1D  - Write
  {0x00,  0x00,  0x0F, 0x0, 0x01}, //0xFE1E  - Read
  {0x01,  0x01,  0x0F, 0x0, 0x01}, //0xFE1E  - Write
  {0x00,  0x00,  0x0F, 0x0, 0x01}, //0xFE1F  - Read
  {0x04,  0x04,  0x0F, 0x0, 0x01}, //0xFE1F  - Write
  {0x00,  0x04,  0x0F, 0x0, 0x09}, //0xFE15  - IOControl
  {0x00,  0x00,  0x0F, 0x0, 0x01}, //0xFE16  - Read
  {0x00,  0x03,  0x0F, 0x0, 0x09}, //0xFE0E  - IOControl
  {0x00,  0x01,  0x0F, 0x0, 0x09}, //0xFE0D  - IOControl
  {0x00,  0x00,  0x0F, 0x0, 0x01}, //0xFE09  - Read
  {0x02,  0x02,  0x0F, 0x0, 0x01}, //0xFE09  - Write
  {0x00,  0x00,  0x0F, 0x0, 0x01}, //0xFE04  - Read
  {0x02,  0x02,  0x0F, 0x0, 0x01}, //0xFE04  - Write
  {0x00,  0x01,  0x0F, 0x0, 0x09}, //0xFE05  - IOControl
  {0x00,  0x01,  0x0F, 0x0, 0x09}, //0xFE06  - IOControl
  {0x00,  0x00,  0x0F, 0x0, 0x01}, //0xFE50  - Read
  {0x00,  0x02,  0x0F, 0x0, 0x09}, //0xFE52  - IOControl
  {0x20,  0x20,  0x08, 0x0, 0x01}, //0xF0A7  - Write
  {0x100, 0x100, 0x08, 0x0, 0x01}, //0xF0AC  - Write
  {0x0A,  0x0A,  0x08, 0x0, 0x01}, //0xF0BC  - Write
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0xF0AB  - Read
  {0x00,  0x00,  0x02, 0x0, 0x01}, //0xFD01  - Read
  {0x00,  0x00,  0x0F, 0x0, 0x01}, //0xF000  - Read in MEET
  {0x42,  0x42,  0x0F, 0x0, 0x01}, //0xF000  - Write in MEET
  {0x00,  0x00,  0x0F, 0x0, 0x01}, //0xF001  - Read in MEET
  {0x0A,  0x0A,  0x0F, 0x0, 0x01}, //0xF001  - Write in MEET
  {0x00,  0x00,  0x0F, 0x0, 0x01}, //0xF002  - Read in MEET
  {0x0A,  0x0A,  0x0F, 0x0, 0x01}, //0xF002  - Write in MEET
  {0x00,  0x01,  0x0F, 0x0, 0x01}, //0xFE10  - Read in MEET
  {0x00,  0x36,  0x0F, 0x0, 0x01}, //0xFEFD  - Read in MEET
};

const Dcm_DspDidSignalInfoType Dcm_DspDidSignalInfo[DcmDspNumOfDidSignalInfo] =
{
  /*  OpFunc, FunClass;*/
  {0, 0x01},
  {0, 0x01},
  {1, 0x01},
  {0, 0x01},
  {0, 0x01},
  {0, 0x01},
  {0, 0x01}
};

const Dcm_DspRidIdentifierTableType Dcm_DspRidIdentifierTable[DcmNumOfRIDSupported+1] =
{
  DcmNumOfRIDSupported,

  0x0221,
  0x02A4,
  0x02A2,
  0x02A0,
  0xF103,
  0xF106,
  0xF11E,
  0xFEF0,
  0xFEF1,
  0xFEF2,
  0xFEF6,
  0xFEF7,
  0xFEF8,
  0xFEF9,
  0xFEFA,
  0xFEFB,
  0xFEFC,
  0xFE5F,
  0xFE0A,
  0xF108,
  0xF109,
  0xF105,
  0xF100,
  0xFF06,
  0xFEFE,   //MEET
};

const Dcm_DspRidInfoType Dcm_DspRidInfo[DcmNumOfRIDSupported] =
{
  /* SignalInfo_Ref, State_Ref, Operation */
  { 0,  0x0D, 0x05}, //0x0221, only ext and with security, req result and start
  { 2,  0x08, 0x05}, //0x02A4, FOTA only, req result and start
  { 4,  0x00, 0x05}, //0x02A2, FOTA and Default session and no security, req result and start
  { 6,  0x00, 0x05}, //0x02A0, FOTA and Default session and no security, req result and start
  { 8,  0x0F, 0x01}, //0xF103, MEET session and no security, req start
  { 9,  0x0F, 0x05}, //0xF106, MEET session and no security, req result and start
  { 11, 0x0F, 0x05}, //0xF11E, MEET session and no security, req result and start
  { 13, 0x0F, 0x05}, //0xFEF0, MEET session and no security, req result and start
  { 15, 0x0F, 0x05}, //0xFEF1, MEET session and no security, req result and start
  { 17, 0x0F, 0x05}, //0xFEF2, MEET session and no security, req result and start
  { 19, 0x0F, 0x01}, //0xFEF6, MEET session and no security, start
  { 20, 0x0F, 0x05}, //0xFEF7, MEET session and no security, req result and start
  { 22, 0x0F, 0x01}, //0xFEF8, MEET session and no security, start
  { 23, 0x0F, 0x01}, //0xFEF9, MEET session and no security, start
  { 24, 0x0F, 0x01}, //0xFEFA, MEET session and no security, start
  { 25, 0x0F, 0x05}, //0xFEFB, MEET session and no security, req result and start
  { 27, 0x0F, 0x05}, //0xFEFC, MEET session and no security, req result and start
  { 29, 0x0F, 0x07}, //0xFE5F, MEET session and no security, req result,start and stop
  { 32, 0x0F, 0x05}, //0xFE0A, MEET session and no security, req result and start
  { 34, 0x0F, 0x05}, //0xF108, MEET session and no security, req result and start
  { 36, 0x0F, 0x05}, //0xF109, MEET session and no security, req result and start
  { 38, 0x0F, 0x07}, //0xF105, MEET session and no security, req result, start and stop
  { 41, 0x0F, 0x07}, //0xF100, MEET session and no security, req result, start and stop
  { 44, 0x08, 0x01}, //0xFF06, FOTA only, start
  { 45, 0x0F, 0x01}, //0xFEFE, MEET session and no security, start
};

const Dcm_DspRidSignalInfoType Dcm_DspRidSignalInfo[DcmDspNumOfRidSignalInfo] =
{
  /* RidOpFunc_Ref, Min_ReqLength, Max_ReqLength, Min_RespLength, Max_RespLength, OpType */
  { 0, 0x0,   0x0,   0x1,   0x1,   0x01}, // start 0x0221
  { 0, 0x0,   0x0,   0x1,   0x1,   0x04}, // request result 0x0221
  { 0, 0x0,   0x0,   0x1,   0x1,   0x01}, // start 0x02A4
  { 0, 0x0,   0x0,   0x1,   0x1,   0x04}, // request result 0x02A4
  { 0, 0x1,   0x1,   0x2,   0x2,   0x01}, // start 0x02A2
  { 0, 0x0,   0x0,   0x2,   0x2,   0x04}, // request result 0x02A2
  { 0, 0x1,   0x1,   0x2,   0x2,   0x01}, // start 0x02A0
  { 0, 0x0,   0x0,   0x2,   0x2,   0x04}, // request result 0x02A0
  { 0, 0x0,   0x0,   0x0,   0x0,   0x01}, // start 0xF103
  { 0, 0x0,   0x0,   0x3,   0x3,   0x01}, // start 0xF106
  { 0, 0x0,   0x0,   0x3,   0x3,   0x04}, // request result 0xF106
  { 0, 0x1,   0x1,   0x1,   0x1,   0x01}, // start 0xF11E
  { 0, 0x0,   0x0,   0x1,   0x1,   0x04}, // request result 0xF11E
  { 0, 0x74,  0x74,  0x1,   0x1,   0x01}, // start 0xFEF0
  { 0, 0x0,   0x0,   0x1,   0x1,   0x04}, // request result 0xFEF0
  { 0, 0x14,  0x14,  0x1,   0x1,   0x01}, // start 0xFEF1
  { 0, 0x0,   0x0,   0x1,   0x1,   0x04}, // request result 0xFEF1
  { 0, 0x108, 0x108, 0x1,   0x1,   0x01}, // start 0xFEF2
  { 0, 0x1,   0x1,   0x1,   0x1,   0x04}, // request result 0xFEF2
  { 0, 0x45,  0x45,  0x1,   0x1,   0x01}, // start 0xFEF6
  { 0, 0x23,  0x23,  0x1,   0x1,   0x01}, // start 0xFEF7
  { 0, 0x0,   0x1,   0x1,   0x1,   0x04}, // request result 0xFEF7
  { 0, 0x6,   0x6,   0x1,   0x1,   0x01}, // start 0xFEF8
  { 0, 0x2,   0x2,   0x5,   0x5,   0x01}, // start 0xFEF9
  { 0, 0x2,   0x2,   0x5,   0x5,   0x01}, // start 0xFEFA
  { 0, 0x0,   0x0,   0x1,   0x1,   0x01}, // start 0xFEFB
  { 0, 0x0,   0x0,   0x2,   0x2,   0x04}, // request result 0xFEFB
  { 0, 0x0,   0x0,   0x1,   0x1,   0x01}, // start 0xFEFC
  { 0, 0x0,   0x0,   0x2,   0x2,   0x04}, // request result 0xFEFC
  { 0, 0x2,   0x2,   0x1,   0x1,   0x01}, // start 0xFE5F
  { 0, 0x0,   0x0,   0x1,   0x1,   0x02}, // stop 0xFE5F
  { 0, 0x0,   0x0,   0x101, 0x101, 0x04}, // request result 0xFE5F
  { 0, 0x0,   0x0,   0x0,   0x1,   0x01}, // start 0xFE0A
  { 0, 0x0,   0x0,   0x0,   0x1,   0x04}, // request result 0xFE0A
  { 0, 0x1,   0x1,   0x1,   0x1,   0x01}, // start 0xF108
  { 0, 0x0,   0x0,   0x1,   0x1,   0x04}, // request result 0xF108
  { 0, 0x1,   0x1,   0x1,   0x1,   0x01}, // start 0xF109
  { 0, 0x1,   0x1,   0x2,   0x2,   0x04}, // request result 0xF109
  { 0, 0x2,   0x2,   0x0,   0x2,   0x01}, // start 0xF105
  { 0, 0x0,   0x0,   0x0,   0x0,   0x02}, // stop 0xF105
  { 0, 0x1,   0x1,   0x6,   0x6,   0x04}, // request result 0xF105
  { 0, 0x2,   0x2,   0x1,   0x1,   0x01}, // start 0xF100
  { 0, 0x0,   0x0,   0x0,   0x0,   0x02}, // stop 0xF100
  { 0, 0x1,   0x1,   0x6,   0x6,   0x04}, // request result 0xF100
  { 0, 0x3,   0x3,   0x2,   0x2,   0x01}, // start 0xFF06
  { 0, 0x0,   0x0,   0x0,   0x0,   0x01}  // start 0xFEFE
};

const RidOpFuncType RidOpFunc[RidNumOfOpFunc] =
{
    DI_Rid_Diag_Action
};

#if(DCM_SVC_28_SUPPORT_ENABLED == STD_ON)
const Dcm_SessionCommEnableInfo Dcm_SessionCommEnable[NO_OF_SUPPORTTED_SESSIONS] =
{
  /* Subfunction,Comm_support */
  {1, FALSE},
  {2, TRUE},
  {3, TRUE}
};
#endif

void Dcm_EnterCriticalSection(void)
{

}

void Dcm_ExitCriticalSection(void)
{
}

boolean Dcm_Timer_IsElapsed(const HTimer hTimer, const uint32 Timeout)
{
  boolean RetVal;
  RetVal = E_OK;
  //msavariy - maserati
  //RetVal = TmExt_Timer_IsElapsed(hTimer,Timeout);
  return RetVal;
}

const Dcm_PduIdChannelType Dcm_PduIdChannel[DcmPdurNumOfChannelSupported] =
{
  /*{DCM_PDU_TP_DIAG_REQUEST, 2, PDUR_PDU_TP_DIAG_RESPONSE, COMM_CHANNEL_FCAN},*/

  {0, 1, PDUR_PDU_METER_TO_DTOOL, 0},
  {2, 3, PDUR_PDU_FTOOLS_METERTOCGW,0}

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
