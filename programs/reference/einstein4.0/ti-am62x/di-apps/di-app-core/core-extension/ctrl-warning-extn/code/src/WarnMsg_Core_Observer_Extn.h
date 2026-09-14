/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2010. Visteon Corporation owns all rights to           *
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

File Name        :  WarnMsg_Core_Observer_Extn.h
Module Short Name:  MSG_AP
VOBName          :  sw_hmi_ss
Author           :  vrk
Description      :  VIP msg application and frame work.
Organization     :  Driver Information Software Section,
                    Visteon Corporation
******************************************************************************/

#ifndef WARNMSG_CORE_OBSERVER_EXTN_H
#define WARNMSG_CORE_OBSERVER_EXTN_H

#include "Std_Types.h"
#include "warn_msgDefinition.h"
#include "WarnMsg_Core_Observer.h"

/*****************************************************************************
*                                 Global Constant Declarations               *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the constant.                                                        *
* Purpose, unit and resolution                                               *
******************************************************************************/
#define MSG_CHIME_INACTIVE             0U
#define MSG_CHIME_ACTIVE               1U
#define PAYLOAD_INVALID                65535U
#define NO_PAYLOAD_REQD                0U
#define EXTN_NEWDISP                   1U
#define EXTN_REDISP                    2U
 /*Instance Macros*/
 #define DEFAULT_INSTANCE              0U
 #define HUD_INSTANCE                  1U
/*****************************************************************************
*                                 Global Macro Definitions                   *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
#define WARNCANTX_BTNCHK(X,Y)   (0U != (X & l_WarnTxList_A[Y].CfgdBtn))?TRUE: FALSE;
#define TGSWITCH_CDNCHK(X,Y)    (0U != (X & l_WarnTxList_A[Y].CfgdTrgtSw))?TRUE: FALSE;
/*****************************************************************************
*                                 Type Declaration                           *
*----------------------------------------------------------------------------*
* Declaration of type shall be accompanied by a comment that explains the    *
* purpose and usage of the type.                                             *
******************************************************************************/
typedef struct CanTxStruct
{
   void (*ApplFnPtr) (uint16 DispdWarnId,uint16 RxdBtnEvnt,uint8 RxdCrsrData); 
   uint16 Qualifier;
} WARNCANTX_STRUCT;
/*****************************************************************************
*                                 Global Variable Declarations               *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, resolution, Valid Range and ValidityCheck *
******************************************************************************/
/*****************************************************************************
*                                 Global Function Prototypes                 *
******************************************************************************/
extern void CheckMsgCoreTrig (MSG_VIEWINFO_T *Data, boolean *RetVal);
extern uint8 CheckInitCall (MSG_VIEWINFO_T *Data);
extern void CheckShowConditions(boolean *RetVal);
extern void CheckEventHiddenConditions(boolean *RetVal);
extern void CheckEventShowConditions(boolean *RetVal);
extern void CheckEventTimeoutConditions(boolean *RetVal);
extern void CheckEventAckConditions(boolean *RetVal);
extern void CheckPreUclTrigCdn(boolean *RetVal);
extern void CheckHideConditions(boolean *RetVal);
extern void CheckEventInactiveConditions(WarningId Qualifier, boolean *RetVal);
extern void UpdateWarnStsToUCL(SWarningDisplay *UclDataTx, uint8 WarnInst, uint8 MsgType);
extern void UpdateWarnDataToUCL( eMessageIdentity *DispWarnId, uint16 WarningCount, uint8 WarnInst);
extern void WarningSendChimeInfo(uint8 SeqStatus);
extern void MsgCoreExtnAddlActiveChk (MSG_VIEWINFO_T *Data, boolean *AddlChkSts);
extern void MsgCoreExtnAddlAction(void);
extern void SendWarnStsInTask ( boolean *RetVal);
extern void ProgramInitRequest ( uint8 *Data );
extern uint16 DetMessageId (uint16 RxdWarnId);
void UpdPreAckCdns (uint16 SeqMsgId, uint8 WarnInst, EButtonSts* ButtonEvent, boolean *RetVal);
void UpdPostAckCdns (uint8 WarnInst);
uint8 UpdateWarnInt (WarningId RxdWarnId);
boolean TriggerSWNoOperTmrChk (EButtonId pEvent, EButtonSts pEventType );
void UpdateWarnCanTx (void);
void UpdInterruptData (WarningId UclWarnId,uint8 WarnInst,uint8 HudNvmData);
uint16 CheckCanTxAppl (uint16 RxdWarnId);
boolean StoreWarnConfigChk(eMessageIdentity p_message_id);
void TriggerAlert (uint8 WarnSts,uint8 Inst);
boolean CheckPayloadChange(WarningId *DispWarnId);
void StoreDataTx (WarningId *DispWarnId);
void UpdateONSUCLData (void);
uint8 DetUclMsgSts (uint16 RxdWarnId,uint8 MsgType);

#define FUTILITY_UNUSED_VAR(x) (void)(x)
#endif

/*End of File*/
/*****************************************************************************
*   for each change to this file, be sure to record:                         *
*      1.  who made the change and when the change was made                  *
*      2.  why the change was made and the intended result                   *
*   Following block needs to be repeated for each change
******************************************************************************
*   Note: In the traceability column we need to trace back to the Design Doc.*
*   For the initial version it is traced to the Design Document section.     *
*   For further changes it shall trace to the source of the change which may *
*   be SPSS/SCR/Defect details(Defect may be Testing/validation defect)/Any  *
*   other reason                                                             *
******************************************************************************/
/****************************************************************************
Date              : 19-06-2024
CDSID             : vrk
Traceability      : 
Change Description: Bookshelf component 
 ******************************************************************************/
/****************************************************************************
Date              : 02-09-2024
CDSID             : vrk
Traceability      : TFDCX32348-38611
Change Description: 1. Updated the prototype of CheckInitCall, UpdateWarnStsToUCL
                    2. Added the functions - WarningSendChimeInfo, 
                       MsgCoreExtnAddlActiveChk, MsgCoreExtnAddlAction
                       UpdateReceivedPayload, SendWarnStsInTask, ProgramInitRequest
 ******************************************************************************/
/****************************************************************************
Date              : 27-09-2024
CDSID             : vrk
Traceability      : TFDCX32348-38818
Change Description: 1. Updated the prototype of CheckShowConditions, UpdPreAckCdns
                    2. Removed the function - CheckAckRecd 
 ******************************************************************************/
/****************************************************************************
Date              : 21-11-2024
CDSID             : vrk
Traceability      : TFDCX32348-57369
Change Description: 1. Added the function - TriggerSWNoOperTmrChk
                    2. Removed the function - UpdateReceivedPayload
 ******************************************************************************/
/****************************************************************************
Date              : 02-12-2024
CDSID             : vrk
Traceability      : 
Change Description: 1. Added the struct defenitions - CanTxStruct and TxInfoStruct
                    2. Added the MACRO defenition - WARNCANTX_BTNCHK to check for the 
                     configured button pressed
                    3. Added the functions - UpdateWarnCanTx and CanTxReset to support 
                    CANTx of the displayed warning.
 ******************************************************************************/
/****************************************************************************
Date              : 09-12-2024
CDSID             : vrk
Traceability      : 
Change Description: 1. Added CfgdTrgtSw  in WARNCANTX_STRUCT to support Target Switch from Button_Mdl.
                    2. Added the MACRO defenition - TGSWITCH_CDNCHK to check for the 
                     configured TargetSw pressed.
 ******************************************************************************/
/****************************************************************************
Date              : 12-12-2024
CDSID             : vrk
Traceability      : TFDCX32348-61097
Change Description: Prototypes of UpdateWarnStsToUCL is updated to support
                   multi-instance
 ******************************************************************************/
 /****************************************************************************
Date              : 17-03-2025
CDSID             : vrk
Traceability      : TFDCX32348-74510
Change Description: Compiler Warning Fix for TMR_APPL CANTx
 ******************************************************************************/
 /****************************************************************************
Date              : 29-03-2025
CDSID             : vrk
Traceability      : TFDCX32348-78378
Change Description: Added the function prototype - UpdInterruptData.
 ******************************************************************************/
/****************************************************************************
Date              : 04-04-2025
CDSID             : vrk
Traceability      : TFDCX32348-78290
Change Description: Added the function prototype - UpdWarnInterruptType
 ******************************************************************************/
/****************************************************************************
Date              : 21-04-2025
CDSID             : vrk
Traceability      : TFDCX32348-81752
Change Description: 1. Removed the function prototype - UpdWarnInterruptType
                    2. Updated the function prototypes - UpdateWarnStsToUCL,  UpdateWarnDataToUCL
                    UpdPreAckCdns, UpdPostAckCdns
                    3. Included the header - WarnMsg_Core_Observer to support latest version of WarnMsg_Core_Observer v2.2.1
                    4. Removed TmrConstrnt from the structure - WARNCANTX_STRUCT
 ******************************************************************************/
/****************************************************************************
Date              : 05-05-2025
CDSID             : vrk
Traceability      : TFDCX32348-83400
Change Description: 1. Updated the function prototype - UpdInterruptData
                    2. Added the function prototype - CheckCanTxAppl
                    3. Removed CanTxCfgd and added Qualifier in the structure - WARNCANTX_STRUCT
                    4. Updated the MACROS - WARNCANTX_BTNCHK, TGSWITCH_CDNCHK
 ******************************************************************************/
/****************************************************************************
Date              : 17-05-2025
CDSID             : vrk
Traceability      : TFDCX32348-85452
Change Description: 1. Removed the funtion - CanTxReset.
                    2. Update the structure - WARNCANTX_STRUCT and removed the struct - TxdInfoStruct.
 ******************************************************************************/
/****************************************************************************
Date              : 26-05-2025
CDSID             : vrk
Traceability      : TFDCX32348-86429
Change Description: Added the funtions - TriggerAlert, StoreWarnConfigChk
 ******************************************************************************/
 /****************************************************************************
Date              : 29-05-2025
CDSID             : vrk
Traceability      : TFDCX32348-86595
Change Description: Updated to support store Warnings
 ******************************************************************************/
 /*End of Revision History*/


