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
#ifndef DCM_INTERNAL_H
#define DCM_INTERNAL_H
/*****************************************************************************
 *  File Name         :  Dcm_Internal.h                                       *
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
/*****************************************************************************
 *                            Include files                                   *
 ******************************************************************************/

/*****************************************************************************
 *                                 Macro Definitions                          *
 *----------------------------------------------------------------------------*
 * Definition of macro shall be followed by a comment that explains the       *
 * purpose of the macro.                                                      *
 ******************************************************************************/
#define DCM_IGNORE_UNREF_PARAM(param)                  ((void)(param))

/* ComM */
#define Dcm_ComM_InActive      (DCM_FALSE)
#define Dcm_ComM_Active        (DCM_TRUE)

/* Timing Flags */
#define DCM_TMR_ID_P2          (uint8)0x01U
#define DCM_TMR_ID_P2STAR      (uint8)0x02U
#define DCM_TMR_ID_S3SERVER    (uint8)0x04U
#define DCM_TMR_ID_3E          (uint8)0x08U

#define DCM_STATE_ONRX         0x01U
#define DCM_STATE_RX_END       0x02U
#define DCM_STATE_PREPTX_NRC   0x04U
#define DCM_STATE_ONTX         0x08U
#define DCM_STATE_ONTX_WAIT    0x10U
#define DCM_STATE_READY        0x20U
#define DCM_SID_PROCESS        0x40U
#define DCM_STATE_BUSY_REPEAT_REQUEST       0x80U
#define DCM_NO_COM             0x00U
#define DCM_DIAG_CANCEL        0x04U

typedef uint8 Dcm_DspDiagCheckLvlType;
#define DSP_DIAG_CHK_LVL_PARAMETER          ((Dcm_DspDiagCheckLvlType)1U)
#define DSP_DIAG_CHK_LVL_SUBFUNC            ((Dcm_DspDiagCheckLvlType)2U)
#define DSP_NUM_DIAG_CHK_LVLS               (DSP_DIAG_CHK_LVL_SUBFUNC + 1U)

#define DCM_FLAG_IDLE          0x00U
#define DCM_FLAG_BUSY          0x01U
#define DCM_FLAG_COPY          0x02U
#define DCM_FLAG_CANCEL        0x03U


#define DCM_BUFFER_IDLE       0x00U
#define DCM_BUFFER_BUSY       0x02U

/*****************************************************************************
 *                                 Type Declarations                          *
 ******************************************************************************/
typedef uint8 Dcm_CurrentOpType;

typedef struct
{
    Dcm_MsgContextType pMsgContext;
    DcmDsl_BufferType *RxData;
    Dcm_MsgItemType *AddBuf;
    Dcm_MsgItemType *BusyRespAddBuf;
	Dcm_CommunicationModeType ComMMode;
	Dcm_OpStatusType OpStatus;
    uint16 Buff_Pos;
    uint8 State;
	uint8 Flag;
} Dcm_DslRequestResponseType;

typedef struct
{
    Dcm_SesCtrlType Session_Index;
    Dcm_SesCtrlType Session_Level;
    Dcm_SecLevelType Security_Level;
    Dcm_OpStatusType OpStatus;
    Dcm_CommunicationModeType ComMMode;
    Dcm_ConfirmationStatusType ConfirmationStatus;
    uint8 RcrRp_Count;
    uint8 FRcRp_Status;
    uint16 MainConnection;
    uint16 SubConnection;
	uint8 SubConnRef;       
	uint8 MainConnRef;      
	uint8 Priority;       //00- Highest Priority    FF- Lowest priority
    Dcm_BooleanType ConcurrentTesterPresent;
    Dcm_BooleanType BusyRepeatRequest;
	Dcm_BooleanType BuffInUse;
    Dcm_BooleanType ComMState;
} Dcm_InternalStatusType;



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
#define DIAGMGR_DATA_SEC_START
#include "MemMap.h"
extern DcmDsl_BufferType DcmDsl_Buffer[DcmDslBufferSize];
extern Dcm_DslRequestResponseType Dcm_DslRequestResponse[DcmNumofClientSupported];
extern Dcm_InternalStatusType Dcm_InternalStatus;
extern Dcm_CurrentOpType Dcm_CurrentOp;
#define DIAGMGR_DATA_SEC_END
#include "MemMap.h"

/*****************************************************************************
 *                   Functions                                                *
 ******************************************************************************/
extern void Dcm_StartTimer(uint8 TmrId);
extern void Dcm_StopTimer(uint8 TmrId);

/**************************************************************************
 Function name   : DslInternal_SetSesCtrlType
 Arguments       : Dcm_SesCtrlType SesCtrlType
 Return type     : void
 Description     : This function sets a new session control type value in the DCM module.
 **************************************************************************/
extern void DslInternal_SetSesCtrlType(Dcm_SesCtrlType SesCtrlType);

/**************************************************************************
 Function name   : DslInternal_SetSecurityLevel
 Arguments       : Dcm_SecLevelType SecurityLevel)
 Return type     : void
 Description     : This function sets a new security level value in the DCM module.
 **************************************************************************/
extern void DslInternal_SetSecurityLevel(Dcm_SecLevelType SecurityLevel);

#if(Dcm_KeepNonDefaultSessionActive == STD_ON)
/**************************************************************************
 Function name   : void KeepSessionActive
 Arguments       : Dcm_SesCtrlType SessionId_Index,Dcm_SecLevelType SecurityLevel_Index
 Return type     : Std_ReturnType
 Description     : To keep non default session active and unlock the supported security.
                   If SecurityLevel = 0, it will not go for unlocking the security.
 **************************************************************************/
extern void KeepNonDefaultSessionActive(Dcm_SesCtrlType SessionId,Dcm_SecLevelType SecurityLevel);
#endif

#endif /* DCM_INTERNAL_H_ */
