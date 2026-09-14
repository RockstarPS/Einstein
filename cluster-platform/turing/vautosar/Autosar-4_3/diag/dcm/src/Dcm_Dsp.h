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
#ifndef DCM_DSP_H
#define DCM_DSP_H
/*****************************************************************************
 *  File Name         :  Dcm_Dsp.h                                            *
 *  Module Short Name :  DiagMgr                                              *
 *  VOBName           :                                                       *
 *  Author            : msavariy                                              *
 *  Description       : This file contains the Diagnostics request and        *
 *                       response Service processing functionalities          *
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
/*****************************************************************************
 *                            Include files                                   *
 ******************************************************************************/
#include "Dcm_Types.h"
#include "Dcm_Cfg.h"

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
/**************************************************************************
 Function name       : void Dsp_Init(void)
 Description         : Initializes the Diag Service Processing
 Parameters (in)     : None.
 Parameters (out)    : None
 Return value        : None
 Design Information  :
 **************************************************************************/
extern void Dsp_Init(void);

/**************************************************************************
 Function name       : void Dsp_Main(void)
 Description         : Diag Service Processing Main function
 Parameters (in)     : None.
 Parameters (out)    : None
 Return value        : None
 Design Information  :
 **************************************************************************/
extern void Dsp_Main(void);

#if(DCM_SVC_10_SUPPORT_ENABLED == STD_ON)
/**************************************************************************
 Function name       : Std_ReturnType Dcm_10ServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode)
 Description         : DiagnosticSessionControl 0x10 service
 Parameters (in)     : Dcm_MsgContextType *pMsgContext
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
extern Std_ReturnType Dcm_10ServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode);

/**************************************************************************
 Function name       : Std_ReturnType Dcm_01DefaultProcess(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *NegRes)
 Description         :
 Parameters (in)     :
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
extern Std_ReturnType Dcm_01DefaultProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType *NegRes);

/**************************************************************************
 Function name       : Std_ReturnType Dcm_02PgmProcess(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *NegRes)
 Description         :
 Parameters (in)     :
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
extern Std_ReturnType Dcm_02PgmProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType *NegRes);

/**************************************************************************
 Function name       : Std_ReturnType Dcm_03ExtnDiagProcess(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *NegRes)
 Description         :
 Parameters (in)     :
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
extern Std_ReturnType Dcm_03ExtnDiagProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType *NegRes);
#endif

#if(DCM_SVC_11_SUPPORT_ENABLED == STD_ON)
/**************************************************************************
 Function name       : Std_ReturnType Dcm_11ServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode)
 Description         : ECUReset
 Parameters (in)     : Dcm_MsgContextType *pMsgContext
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
extern Std_ReturnType Dcm_11ServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode);
#endif

#if(DCM_SVC_22_SUPPORT_ENABLED == STD_ON)
/**************************************************************************
 Function name       : Std_ReturnType Dcm_22ServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode)
 Description         : ReadDataByIdentifier Service
 Parameters (in)     : Dcm_MsgContextType *pMsgContext
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
extern Std_ReturnType Dcm_22ServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode);
#endif

#if(DCM_SVC_23_SUPPORT_ENABLED == STD_ON)
/**************************************************************************
 Function name       : Std_ReturnType Dcm_23ServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode)
 Description         : ReadMemoryByAddress Service
 Parameters (in)     : Dcm_MsgContextType *pMsgContext
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
extern Std_ReturnType Dcm_23ServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode);
#endif

#if(DCM_SVC_2E_SUPPORT_ENABLED == STD_ON)
/**************************************************************************
 Function name       : Std_ReturnType Dcm_2EServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode)
 Description         : WriteDataByIdentifier Service
 Parameters (in)     : Dcm_MsgContextType *pMsgContext
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
extern Std_ReturnType Dcm_2EServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode);
#endif

#if(DCM_SVC_2F_SUPPORT_ENABLED == STD_ON)
/**************************************************************************
 Function name       : Std_ReturnType Dcm_2FServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode)
 Description         : ReadDataByIdentifier Service
 Parameters (in)     : Dcm_MsgContextType *pMsgContext
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
extern Std_ReturnType Dcm_2FServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode);
#endif

#if(DCM_SVC_31_SUPPORT_ENABLED == STD_ON)
/**************************************************************************
 Function name       : Std_ReturnType Dcm_31ServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode)
 Description         : InputOutputControlByIdentifier
 Parameters (in)     : Dcm_MsgContextType *pMsgContext
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
extern Std_ReturnType Dcm_31ServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode);
#endif

#if(DCM_SVC_3D_SUPPORT_ENABLED == STD_ON)
/**************************************************************************
 Function name       : Std_ReturnType Dcm_3DServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode)
 Description         : RoutineControl Service
 Parameters (in)     : Dcm_MsgContextType *pMsgContext
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
extern Std_ReturnType Dcm_3DServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode);
#endif

#if(DCM_SVC_34_SUPPORT_ENABLED == STD_ON)
/**************************************************************************
 Function name       : Std_ReturnType Dcm_34ServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode)
 Description         : RoutineControl Service
 Parameters (in)     : Dcm_MsgContextType *pMsgContext
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  : NRC_NOTSUPPORTEDINACTIVESESSION provided by Dcm_Dsd
 **************************************************************************/
extern Std_ReturnType Dcm_34ServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode);
#endif

#if(DCM_SVC_35_SUPPORT_ENABLED == STD_ON)
/**************************************************************************
 Function name       : Std_ReturnType Dcm_35ServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode)
 Description         : RoutineControl Service
 Parameters (in)     : Dcm_MsgContextType *pMsgContext
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  : NRC_NOTSUPPORTEDINACTIVESESSION provided by Dcm_Dsd
 **************************************************************************/
extern Std_ReturnType Dcm_35ServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode);
#endif

#if(DCM_SVC_36_SUPPORT_ENABLED == STD_ON)
/**************************************************************************
 Function name       : Std_ReturnType Dcm_36ServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode)
 Description         : RoutineControl Service
 Parameters (in)     : Dcm_MsgContextType *pMsgContext
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  : NRC_NOTSUPPORTEDINACTIVESESSION provided by Dcm_Dsd
 **************************************************************************/
extern Std_ReturnType Dcm_36ServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode);
#endif

#if(DCM_SVC_37_SUPPORT_ENABLED == STD_ON)
/**************************************************************************
 Function name       : Std_ReturnType Dcm_37ServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode)
 Description         : RoutineControl Service
 Parameters (in)     : Dcm_MsgContextType *pMsgContext
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  : NRC_NOTSUPPORTEDINACTIVESESSION provided by Dcm_Dsd
 **************************************************************************/
extern Std_ReturnType Dcm_37ServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode);
#endif

#if(DCM_SVC_3E_SUPPORT_ENABLED == STD_ON)
/**************************************************************************
 Function name       : Std_ReturnType Dcm_3EServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode)
 Description         : Tester Present Service
 Parameters (in)     : Dcm_MsgContextType *pMsgContext
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
extern Std_ReturnType Dcm_3EServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode);
#endif

#if(DCM_SVC_27_SUPPORT_ENABLED == STD_ON)
/**************************************************************************
 Function name       : Std_ReturnType Dcm_27ServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode)
 Description         : SecurityAccess Service
 Parameters (in)     : Dcm_MsgContextType *pMsgContext
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
extern Std_ReturnType Dcm_27ServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode);
#endif

#if(DCM_SVC_28_SUPPORT_ENABLED == STD_ON)
/**************************************************************************
 Function name       : Std_ReturnType Dcm_28ServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode)
 Description         : Communication Control Service
 Parameters (in)     : Dcm_MsgContextType *pMsgContext
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
extern Std_ReturnType Dcm_28ServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode);
#endif

#if((DCM_SVC_19_SUPPORT_ENABLED == STD_ON) || (DCM_SVC_86_SUPPORT_ENABLED == STD_ON))
/**************************************************************************
 Function name       : Std_ReturnType Dcm_19ServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode)
 Description         : ReadDTCInformation Service
 Parameters (in)     : Dcm_MsgContextType *pMsgContext
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
extern Std_ReturnType Dcm_19ServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode);
#endif

#if(DCM_SVC_14_SUPPORT_ENABLED == STD_ON)
/**************************************************************************
 Function name       : Std_ReturnType Dcm_14ServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode)
 Description         : Clear DiagnosticInformation Service
 Parameters (in)     : Dcm_MsgContextType *pMsgContext
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
extern Std_ReturnType Dcm_14ServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode);
#endif

#if(DCM_SVC_85_SUPPORT_ENABLED == STD_ON)
/**************************************************************************
 Function name       : Std_ReturnType Dcm_85ServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode)
 Description         : ControlDTCSetting service
 Parameters (in)     : Dcm_MsgContextType *pMsgContext
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
extern Std_ReturnType Dcm_85ServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode);
#endif

#if(DCM_SVC_86_SUPPORT_ENABLED == STD_ON)
/**************************************************************************
 Function name       : Std_ReturnType Dcm_86ServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode)
 Description         : Response On Event service
 Parameters (in)     : Dcm_MsgContextType *pMsgContext
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
extern Std_ReturnType Dcm_86ServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode);
#endif

#if(DCM_SVC_87_SUPPORT_ENABLED == STD_ON)
/**************************************************************************
 Function name       : Std_ReturnType Dcm_87ServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode)
 Description         : Link Control service
 Parameters (in)     : Dcm_MsgContextType *pMsgContext
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
extern Std_ReturnType Dcm_87ServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode);
#endif

/**************************************************************************
 Function name   : void Dsp_DslConfirmation
 Arguments       : PduIdType DcmRxPduId, Std_ReturnType result
 Return type     : void
 Description     : Dcm Confirmation.
 **************************************************************************/
extern void Dsp_DslConfirmation(PduIdType DcmRxPduId, Std_ReturnType result);

/**************************************************************************
 Function name       : void Dcm_SessionChangeAction(Dcm_OpStatusType OpStatus, uint8 SubFunction)
 Description         : Action required on session change.
 Parameters (in)     : uint8 SubFunction
 Parameters (out)    : none
 Return value        : none
 Design Information  :
 **************************************************************************/
extern void Dcm_SessionChangeAction(Dcm_OpStatusType OpStatus, uint8 SubFunction, uint8 Source);

/**************************************************************************
 Function name   : Dcm_DspCheckSessionSecurity
 Arguments       : uint8 StateRef, Dcm_DspDiagCheckLvlType LevelRef
 Return type     : Dcm_NegativeResponseCodeType
 Description     :
 **************************************************************************/
extern Dcm_NegativeResponseCodeType Dcm_DspCheckSessionSecurity(uint8 StateRef, uint8 LevelRef);

#if((DCM_SVC_19_SUPPORT_ENABLED == STD_ON) && (DCM_SVC_19_01_SUPPORT_ENABLED == STD_ON))
/**************************************************************************
 Function name       : Dcm_DspService19_01Processor
 Description         : Service 19 subfunction 1.
 Parameters (in)     : Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext,
                       Dcm_NegativeResponseCodeType *NegRes
 Parameters (out)    : Dcm_MsgContextType *pMsgContext,
                       Dcm_NegativeResponseCodeType *NegRes
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
extern Std_ReturnType Dcm_DspService19_01Processor(Dcm_OpStatusType OpStatus,
        Dcm_MsgContextType *pMsgContext,
        Dcm_NegativeResponseCodeType *NegRes);
#endif

#if((DCM_SVC_19_SUPPORT_ENABLED == STD_ON) && (DCM_SVC_19_02_SUPPORT_ENABLED == STD_ON))
/**************************************************************************
 Function name       : Dcm_DspService19_02Processor
 Description         : Service 19 subfunction 2.
 Parameters (in)     : Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext,
                       Dcm_NegativeResponseCodeType *NegRes
 Parameters (out)    : Dcm_MsgContextType *pMsgContext,
                       Dcm_NegativeResponseCodeType *NegRes
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
extern Std_ReturnType Dcm_DspService19_02Processor(Dcm_OpStatusType OpStatus,
        Dcm_MsgContextType *pMsgContext,
        Dcm_NegativeResponseCodeType *NegRes);
#endif		

#if((DCM_SVC_19_SUPPORT_ENABLED == STD_ON) && (DCM_SVC_19_03_SUPPORT_ENABLED == STD_ON))
/**************************************************************************
 Function name       : Dcm_DspService19_03Processor
 Description         : Service 19 subfunction 03.
 Parameters (in)     : Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext,
                       Dcm_NegativeResponseCodeType *NegRes
 Parameters (out)    : Dcm_MsgContextType *pMsgContext,
                       Dcm_NegativeResponseCodeType *NegRes
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
extern Std_ReturnType Dcm_DspService19_03Processor(Dcm_OpStatusType OpStatus,
        Dcm_MsgContextType *pMsgContext,
        Dcm_NegativeResponseCodeType *NegRes);
#endif

#if((DCM_SVC_19_SUPPORT_ENABLED == STD_ON) && (DCM_SVC_19_04_SUPPORT_ENABLED == STD_ON))
/**************************************************************************
 Function name       : Dcm_DspService19_04Processor
 Description         : Service 19 subfunction 04.
 Parameters (in)     : Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext,
                       Dcm_NegativeResponseCodeType *NegRes
 Parameters (out)    : Dcm_MsgContextType *pMsgContext,
                       Dcm_NegativeResponseCodeType *NegRes
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
extern Std_ReturnType Dcm_DspService19_04Processor(Dcm_OpStatusType OpStatus,
        Dcm_MsgContextType *pMsgContext,
        Dcm_NegativeResponseCodeType *NegRes);
#endif

#if((DCM_SVC_19_SUPPORT_ENABLED == STD_ON) && (DCM_SVC_19_06_SUPPORT_ENABLED == STD_ON))
/**************************************************************************
 Function name       : Dcm_DspService19_06Processor
 Description         : Service 19 subfunction 6.
 Parameters (in)     : Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext,
                       Dcm_NegativeResponseCodeType *NegRes
 Parameters (out)    : Dcm_MsgContextType *pMsgContext,
                       Dcm_NegativeResponseCodeType *NegRes
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
extern Std_ReturnType Dcm_DspService19_06Processor(Dcm_OpStatusType OpStatus,
        Dcm_MsgContextType *pMsgContext,
        Dcm_NegativeResponseCodeType *NegRes);
#endif

#if((DCM_SVC_19_SUPPORT_ENABLED == STD_ON) && (DCM_SVC_19_07_SUPPORT_ENABLED == STD_ON))
/**************************************************************************
Function name       : Dcm_DspService19_07Processor
Description         : Service 19 subfunction 7.
Parameters (in)     : Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext,
                      Dcm_NegativeResponseCodeType *NegRes
Parameters (out)    : Dcm_MsgContextType *pMsgContext,
                      Dcm_NegativeResponseCodeType *NegRes
Return value        : Std_ReturnType
Design Information  :
**************************************************************************/
extern Std_ReturnType Dcm_DspService19_07Processor(Dcm_OpStatusType OpStatus,
        Dcm_MsgContextType *pMsgContext,
        Dcm_NegativeResponseCodeType *NegRes);
#endif

#if((DCM_SVC_19_SUPPORT_ENABLED == STD_ON) && (DCM_SVC_19_08_SUPPORT_ENABLED == STD_ON))
/**************************************************************************
 Function name       : Dcm_DspService19_08Processor
 Description         : Service 19 subfunction 8.
 Parameters (in)     : Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext,
                       Dcm_NegativeResponseCodeType *NegRes
 Parameters (out)    : Dcm_MsgContextType *pMsgContext,
                       Dcm_NegativeResponseCodeType *NegRes
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
extern Std_ReturnType Dcm_DspService19_08Processor(Dcm_OpStatusType OpStatus,
        Dcm_MsgContextType *pMsgContext,
        Dcm_NegativeResponseCodeType *NegRes);
#endif

#if((DCM_SVC_19_SUPPORT_ENABLED == STD_ON) && (DCM_SVC_19_09_SUPPORT_ENABLED == STD_ON))
/**************************************************************************
 Function name       : Dcm_DspService19_09Processor
 Description         : Service 19 subfunction 9.
 Parameters (in)     : Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext,
                       Dcm_NegativeResponseCodeType *NegRes
 Parameters (out)    : Dcm_MsgContextType *pMsgContext,
                       Dcm_NegativeResponseCodeType *NegRes
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
extern Std_ReturnType Dcm_DspService19_09Processor(Dcm_OpStatusType OpStatus,
        Dcm_MsgContextType *pMsgContext,
        Dcm_NegativeResponseCodeType *NegRes);
#endif

#if((DCM_SVC_19_SUPPORT_ENABLED == STD_ON) && (DCM_SVC_19_0C_SUPPORT_ENABLED == STD_ON))
/**************************************************************************
 Function name       : Dcm_DspService19_0CProcessor
 Description         : Service 19 subfunction C.
 Parameters (in)     : Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext,
                       Dcm_NegativeResponseCodeType *NegRes
 Parameters (out)    : Dcm_MsgContextType *pMsgContext,
                       Dcm_NegativeResponseCodeType *NegRes
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
extern Std_ReturnType Dcm_DspService19_0CProcessor(Dcm_OpStatusType OpStatus,
        Dcm_MsgContextType *pMsgContext,
        Dcm_NegativeResponseCodeType *NegRes);
#endif

#if((DCM_SVC_19_SUPPORT_ENABLED == STD_ON) && (DCM_SVC_19_0A_SUPPORT_ENABLED == STD_ON))
/**************************************************************************
 Function name       : Dcm_DspService19_0AProcessor
 Description         : Service 19 subfunction A.
 Parameters (in)     : Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext,
                       Dcm_NegativeResponseCodeType *NegRes
 Parameters (out)    : Dcm_MsgContextType *pMsgContext,
                       Dcm_NegativeResponseCodeType *NegRes
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
extern Std_ReturnType Dcm_DspService19_0AProcessor(Dcm_OpStatusType OpStatus,
        Dcm_MsgContextType *pMsgContext,
        Dcm_NegativeResponseCodeType *NegRes);
#endif

#if((DCM_SVC_19_SUPPORT_ENABLED == STD_ON) && (DCM_SVC_19_14_SUPPORT_ENABLED == STD_ON))
/**************************************************************************
 Function name       : Dcm_DspService19_14Processor
 Description         : Service 19 subfunction 0x14.
 Parameters (in)     : Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext,
                       Dcm_NegativeResponseCodeType *NegRes
 Parameters (out)    : Dcm_MsgContextType *pMsgContext,
                       Dcm_NegativeResponseCodeType *NegRes
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
extern Std_ReturnType Dcm_DspService19_14Processor(Dcm_OpStatusType OpStatus,
        Dcm_MsgContextType *pMsgContext,
        Dcm_NegativeResponseCodeType *NegRes);
#endif

#if(((DCM_SVC_19_SUPPORT_ENABLED == STD_ON) && (DCM_SVC_19_0E_SUPPORT_ENABLED == STD_ON)) || (DCM_SVC_86_SUPPORT_ENABLED == STD_ON))
/**************************************************************************
 Function name       : Dcm_DspService19_0EProcessor
 Description         : Service 19 subfunction 0x0E.
 Parameters (in)     : Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext,
                       Dcm_NegativeResponseCodeType *NegRes
 Parameters (out)    : Dcm_MsgContextType *pMsgContext,
                       Dcm_NegativeResponseCodeType *NegRes
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
extern Std_ReturnType Dcm_DspService19_0EProcessor(Dcm_OpStatusType OpStatus,
        Dcm_MsgContextType *pMsgContext,
        Dcm_NegativeResponseCodeType *NegRes);
#endif

#if((DCM_SVC_19_SUPPORT_ENABLED == STD_ON) && (DCM_SVC_19_17_SUPPORT_ENABLED == STD_ON))
/**************************************************************************
 Function name       : Dcm_DspService19_17Processor
 Description         : Service 19 subfunction 0x14.
 Parameters (in)     : Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext,
                       Dcm_NegativeResponseCodeType *NegRes
 Parameters (out)    : Dcm_MsgContextType *pMsgContext,
                       Dcm_NegativeResponseCodeType *NegRes
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
extern Std_ReturnType Dcm_DspService19_17Processor(Dcm_OpStatusType OpStatus,
        Dcm_MsgContextType *pMsgContext,
        Dcm_NegativeResponseCodeType *NegRes);
#endif

#if((DCM_SVC_19_SUPPORT_ENABLED == STD_ON) && (DCM_SVC_19_18_SUPPORT_ENABLED == STD_ON))
/**************************************************************************
 Function name       : Dcm_DspService19_18Processor
 Description         : Service 19 subfunction 0x14.
 Parameters (in)     : Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext,
                       Dcm_NegativeResponseCodeType *NegRes
 Parameters (out)    : Dcm_MsgContextType *pMsgContext,
                       Dcm_NegativeResponseCodeType *NegRes
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
extern Std_ReturnType Dcm_DspService19_18Processor(Dcm_OpStatusType OpStatus,
        Dcm_MsgContextType *pMsgContext,
        Dcm_NegativeResponseCodeType *NegRes);
#endif

#if((DCM_SVC_19_SUPPORT_ENABLED == STD_ON) && (DCM_SVC_19_19_SUPPORT_ENABLED == STD_ON))
/**************************************************************************
 Function name       : Dcm_DspService19_19Processor
 Description         : Service 19 subfunction 0x14.
 Parameters (in)     : Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext,
                       Dcm_NegativeResponseCodeType *NegRes
 Parameters (out)    : Dcm_MsgContextType *pMsgContext,
                       Dcm_NegativeResponseCodeType *NegRes
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
extern Std_ReturnType Dcm_DspService19_19Processor(Dcm_OpStatusType OpStatus,
        Dcm_MsgContextType *pMsgContext,
        Dcm_NegativeResponseCodeType *NegRes);
#endif

#if(DCM_SVC_86_SUPPORT_ENABLED == STD_ON)
/**************************************************************************
Function name       : Dcm_DspService0x86_0x00Processor
Description         : Service 86 subfunction 0.
Parameters (in)     : Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext,
                      Dcm_NegativeResponseCodeType *NegRes
Parameters (out)    : Dcm_MsgContextType *pMsgContext,
                      Dcm_NegativeResponseCodeType *NegRes
Return value        : Std_ReturnType
Design Information  :
**************************************************************************/
extern Std_ReturnType Dcm_DspService0x86_0x00Processor(Dcm_OpStatusType OpStatus,
        Dcm_MsgContextType *pMsgContext,
        Dcm_NegativeResponseCodeType *NegRes);

/**************************************************************************
Function name       : Dcm_DspService0x86_0x01Processor
Description         : Service86 subfunction 01.
Parameters (in)     : Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext,
                      Dcm_NegativeResponseCodeType *NegRes
Parameters (out)    : Dcm_MsgContextType *pMsgContext,
                      Dcm_NegativeResponseCodeType *NegRes
Return value        : Std_ReturnType
Design Information  :
**************************************************************************/
extern Std_ReturnType Dcm_DspService0x86_0x01Processor(Dcm_OpStatusType OpStatus,
        Dcm_MsgContextType *pMsgContext,
        Dcm_NegativeResponseCodeType *NegRes);

/**************************************************************************
Function name       : Dcm_DspService0x86_0x03Processor
Description         : Service 86 subfunction 03.
Parameters (in)     : Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext,
                      Dcm_NegativeResponseCodeType *NegRes
Parameters (out)    : Dcm_MsgContextType *pMsgContext,
                      Dcm_NegativeResponseCodeType *NegRes
Return value        : Std_ReturnType
Design Information  :
**************************************************************************/
extern Std_ReturnType Dcm_DspService0x86_0x03Processor(Dcm_OpStatusType OpStatus,
        Dcm_MsgContextType *pMsgContext,
        Dcm_NegativeResponseCodeType *NegRes);

/**************************************************************************
Function name       : Dcm_DspService0x86_0x05Processor
Description         : Service 86 subfunction 05.
Parameters (in)     : Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext,
                      Dcm_NegativeResponseCodeType *NegRes
Parameters (out)    : Dcm_MsgContextType *pMsgContext,
                      Dcm_NegativeResponseCodeType *NegRes
Return value        : Std_ReturnType
Design Information  :
**************************************************************************/
extern Std_ReturnType Dcm_DspService0x86_0x05Processor(Dcm_OpStatusType OpStatus,
        Dcm_MsgContextType *pMsgContext,
        Dcm_NegativeResponseCodeType *NegRes);

/**************************************************************************
Function name       : Dcm_DspService0x86_0x06Processor
Description         : Service 86 subfunction 06.
Parameters (in)     : Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext,
                      Dcm_NegativeResponseCodeType *NegRes
Parameters (out)    : Dcm_MsgContextType *pMsgContext,
                      Dcm_NegativeResponseCodeType *NegRes
Return value        : Std_ReturnType
Design Information  :
**************************************************************************/
extern Std_ReturnType Dcm_DspService0x86_0x06Processor(Dcm_OpStatusType OpStatus,
        Dcm_MsgContextType *pMsgContext,
        Dcm_NegativeResponseCodeType *NegRes);
#endif

/**************************************************************************
 Function name       : Dcm_DspDemTriggerOnDTCStatus(uint32 DTC,
                       Dem_UdsStatusByteType DTCStatusOld,
                       Dem_UdsStatusByteType DTCStatusNew)
 Description         :
 Parameters (in)     : uint32 DTC,
                       Dem_UdsStatusByteType DTCStatusOld,
                       Dem_UdsStatusByteType DTCStatusNew
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
extern Std_ReturnType Dcm_DspDemTriggerOnDTCStatus(uint32 DTC, Dem_UdsStatusByteType DTCStatusOld, Dem_UdsStatusByteType DTCStatusNew);

#if(DCM_SVC_22_SUPPORT_ENABLED == STD_ON)
/**************************************************************************
 Function name       : void ClearDcm_svc22Info(void)
 Description         : set svc22Info to initial state
 Parameters (in)     : none
 Parameters (out)    : none
 Return value        : none
 Design Information  :
 **************************************************************************/
extern void ClearDcm_svc22Info(void);
#endif

#if(DCM_SVC_2F_SUPPORT_ENABLED == STD_ON)
/**************************************************************************
 Function name       : void ClearDcm_svc2FInfo(void)
 Description         : set svc2FInfo to initial state
 Parameters (in)     : none
 Parameters (out)    : none
 Return value        : none
 Design Information  :
 **************************************************************************/
extern void ClearDcm_svc2FInfo(void);
#endif

/**************************************************************************
 Function name   : Dcm_SecurityChangeAction
 Arguments       : uint8 SubFunction, uint8 Source
 Return type     : void
 Description     :
 **************************************************************************/
extern void Dcm_SecurityChangeAction(uint8 SubFunction, uint8 Source);

/**************************************************************************
 Function name   : Dcm_ClearDTCCheckFnc
 Arguments       : uint32 GoDTC, Dcm_NegativeResponseCodeType* ErrorCode
 Return type     : Std_ReturnType
 Description     :
 **************************************************************************/
extern Std_ReturnType Dcm_ClearDTCCheckFnc(uint32 GoDTC, Dcm_NegativeResponseCodeType* ErrorCode);

/*****************************************************************************
 *                              Limited Scope Prototypes                      *
 ******************************************************************************/

/*****************************************************************************
 *                   Functions                                                *
 ******************************************************************************/

#endif /* DCM_DSP_H */

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
/*Date              : 17-Jun-2016                                            */
/*Version           :                                                       */
/*By                : msavariy                                               */
/*Traceability      :                                                       */
/*Change Description: Datadesign And Framework implemented, Initial Version */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 21-Sep-2016                                           */
/*Version           :                                                       */
/*By                : akalarim                                              */
/*Traceability      :                                                       */
/*Change Description: service 10,11,22 implementation						*/
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 17-Oct-2016                                           */
/*Version           :                                                       */
/*By                : akalarim                                              */
/*Traceability      :                                                       */
/*Change Description: service 2E,2F,31 implementation						*/
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 21-Oct-2016                                           */
/*Version           :                                                       */
/*By                : akalarim                                              */
/*Traceability      :                                                       */
/*Change Description: service 3E,27 implementation						    */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 22-Nov-2016                                           */
/*Version           :                                                       */
/*By                : akalarim                                              */
/*Traceability      : RTC 746031                                            */
/*Change Description: service 28 implementation						        */
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
/*Date              : 3-April-2017                                          */
/*Version           :                                                       */
/*By                : akalarim                                              */
/*Traceability      : RTC 838240                                            */
/*Change Description: Fixed the compiler warnings.                          */
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
/*Date              : 25-Feb-2021                                           */
/*Version           :                                                       */
/*By                : iiliev1                                               */
/*Traceability      :                                                       */
/*Change Description: Implement 0x87 and 0x27 services                      */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 18-Jan-2022                                           */
/*Version           :                                                       */
/*By                : iiliev1                                               */
/*Traceability      : Rtc#1560389                                           */
/*Change Description: DCM and DEM Autosar 4.2.2 Migration                   */
/*--------------------------------------------------------------------------*/
