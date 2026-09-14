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
/******************************************************************************

File Name        :  WarnMsg_Core_Observer.c                                                
Module Short Name:  VIP Warnings application                                                          
Author           :  vrk
VOBName          :  Warning Bookshelf
Description      :  VIP msg application and frame work.                                
Organization     :  Driver Information Software Section,                              
                    Visteon Corporation                                               
 ******************************************************************************/
/******************************************************************************
Compiler Name    :  
Target Processor :
 ******************************************************************************/
 #define WARNMSG_CORE_OBSERVER_C
 /*****************************************************************************
 *                                 System Includes                            *
 ******************************************************************************/
/*Add the System Includes here*/
/******************************************************************************
 *                                 Project Includes                           *
 ******************************************************************************/
/*RTE Includes*/
#include "Rte_CWarnMsg_Core_Observer.h"
/*Local Includes*/
#include "WarnMsg_Core_Observer.h"
/*Feature Includes*/
#include "WarnMsg_Core_Observer_Notify_Status_Cb.h"
#include "WarnMsg_Core_Observer_ShowNewMsgNotification.h"
#include "WarnMsg_Core_Observer_HideMsgNotification.h"
#include "WarnMsg_Core_Observer_StoreRemoveNotification.h"
#ifndef WARNMSG_CORE_OBSERVER_REDISPAPPL
#include "WarnMsg_Core_Observer_SW_NoOperationTimer.h"
#endif
/*Message Core Includes*/
#include "warn_msgTask.h"
#include "warn_msgDefinition.cfg"
/*Global includes*/
#include "string.h"
#include "CmpLib.h"
#include "MemLib.h"

/*Configuration MACRO Defenition Failsafe Checks*/
#ifndef WARNMSG_CORE_OBSERVER_INITCHK
#error "WarnMsg_Core_Observer_Cfg.h: WARNMSG_CORE_OBSERVER_INITCHK function macro definition is missing. Configure the respective interface in Cfg file"
#endif

#ifndef CHECK_MSGCORE_TRIG_CDN
#error "WarnMsg_Core_Observer_Cfg.h: CHECK_MSGCORE_TRIG_CDN function macro definition is missing. Configure the respective interface in Cfg file"
#endif

#ifndef WARNMSG_CORE_OBSERVER_GETWARNSTS
#error "WarnMsg_Core_Observer_Cfg.h: WARNMSG_CORE_OBSERVER_GETWARNSTS function macro definition is missing. Configure the respective interface in Cfg file"
#endif

#ifndef WARNMSG_CORE_OBSERVER_SETWARNDISPSTS
#error "WarnMsg_Core_Observer_Cfg.h: WARNMSG_CORE_OBSERVER_SETWARNDISPSTS function macro definition is missing. Configure the respective interface in Cfg file"
#endif

#ifndef WARNMSG_CORE_OBSERVER_SENDTOUCL
#error "WarnMsg_Core_Observer_Cfg.h: WARNMSG_CORE_OBSERVER_SENDTOUCL function macro definition is missing. Configure the respective interface in Cfg file"
#endif

#ifndef WARNMSG_CORE_OBSERVER_SHOWEXTNCHK
#error "WarnMsg_Core_Observer_Cfg.h: WARNMSG_CORE_OBSERVER_SHOWEXTNCHK function macro definition is missing. Configure the respective interface in Cfg file"
#endif

#ifndef WARNMSG_CORE_OBSERVER_HIDEEXTNCHK
#error "WarnMsg_Core_Observer_Cfg.h: WARNMSG_CORE_OBSERVER_HIDEEXTNCHK function macro definition is missing. Configure the respective interface in Cfg file"
#endif

#ifndef WARNMSG_CORE_OBSERVER_EVENTHIDDENCHK
#error "WarnMsg_Core_Observer_Cfg.h: WARNMSG_CORE_OBSERVER_EVENTHIDDENCHK function macro definition is missing. Configure the respective interface in Cfg file"
#endif

#ifndef WARNMSG_CORE_OBSERVER_EVENTSHOWCHK
#error "WarnMsg_Core_Observer_Cfg.h: WARNMSG_CORE_OBSERVER_EVENTSHOWCHK function macro definition is missing. Configure the respective interface in Cfg file"
#endif

#ifndef WARNMSG_CORE_OBSERVER_EVENTTIMEOUTCHK
#error "WarnMsg_Core_Observer_Cfg.h: WARNMSG_CORE_OBSERVER_EVENTTIMEOUTCHK function macro definition is missing. Configure the respective interface in Cfg file"
#endif

#ifndef WARNMSG_CORE_OBSERVER_EVENTACKCHK
#error "WarnMsg_Core_Observer_Cfg.h: WARNMSG_CORE_OBSERVER_EVENTACKCHK function macro definition is missing. Configure the respective interface in Cfg file"
#endif

#ifndef ADDL_ACTIVE_CHK
#error "WarnMsg_Core_Observer_Cfg.h: ADDL_ACTIVE_CHK function macro definition is missing. Configure the respective interface in Cfg file"
#endif

#ifndef WARNMSG_CORE_OBSERVER_ADDLACTION
#error "WarnMsg_Core_Observer_Cfg.h: WARNMSG_CORE_OBSERVER_ADDLACTION function macro definition is missing. Configure the respective interface in Cfg file"
#endif

#ifndef WARNMSG_CORE_OBSERVER_SENDSTOREDATATOUCL
#error "WarnMsg_Core_Observer_Cfg.h: WARNMSG_CORE_OBSERVER_SENDSTOREDATATOUCL function macro definition is missing. Configure the respective interface in Cfg file"
#endif

#ifndef CHECK_PREUCL_TRIG_CDN
#error "WarnMsg_Core_Observer_Cfg.h: CHECK_PREUCL_TRIG_CDN function macro definition is missing. Configure the respective interface in Cfg file"
#endif

#ifndef TRIGGER_WARNING_CHIME
#error "WarnMsg_Core_Observer_Cfg.h: TRIGGER_WARNING_CHIME function macro definition is missing. Configure the respective interface in Cfg file"
#endif

#ifndef UPDATEWARNINTASKCHK
#error "WarnMsg_Core_Observer_Cfg.h: UPDATEWARNINTASKCHK function macro definition is missing. Configure the respective interface in Cfg file"
#endif

#ifndef MAX_WARNINGS_CONFIGURED
#error "WarnMsg_Core_Observer_Cfg.h: MAX_WARNINGS_CONFIGURED function macro definition is missing. Configure the respective interface in Cfg file"
#endif

#ifndef WARNMSG_CORE_OBSERVER_PREACKACTION
#error "WarnMsg_Core_Observer_Cfg.h: WARNMSG_CORE_OBSERVER_PREACKACTION function macro definition is missing. Configure the respective interface in Cfg file"
#endif

#ifndef WARNMSG_CORE_OBSERVER_POSTACKCFG
#error "WarnMsg_Core_Observer_Cfg.h: WARNMSG_CORE_OBSERVER_POSTACKCFG function macro definition is missing. Configure the respective interface in Cfg file"
#endif

#ifndef WARNMSG_CORE_OBSERVER_POSTACKACTION
#error "WarnMsg_Core_Observer_Cfg.h: WARNMSG_CORE_OBSERVER_POSTACKACTION function macro definition is missing. Configure the respective interface in Cfg file"
#endif

#ifndef WARNMSG_CORE_OBSERVER_REDISPAPPL
#error "WarnMsg_Core_Observer_Cfg.h: WARNMSG_CORE_OBSERVER_REDISPAPPL function macro definition is missing. Configure the respective interface in Cfg file"
#endif

#ifndef WARNMSG_CORE_OBSERVER_BUTTONACTION
#error "WarnMsg_Core_Observer_Cfg.h: WARNMSG_CORE_OBSERVER_BUTTONACTION function macro definition is missing. Configure the respective interface in Cfg file"
#endif

#ifndef WARNMSG_CORE_OBSERVER_CFGD_INSTANCES
#error "WarnMsg_Core_Observer_Cfg.h: WARNMSG_CORE_OBSERVER_CFGD_INSTANCES function macro definition is missing. Configure the respective interface in Cfg file"
#endif

#ifndef TRIGGER_WARNING_ALERT
#error "WarnMsg_Core_Observer_Cfg.h: TRIGGER_WARNING_ALERT function macro definition is missing. Configure the respective interface in Cfg file"
#endif

#ifndef WARNMSG_CORE_OBSERVER_STOREWARNCONFIGCHK
#error "WarnMsg_Core_Observer_Cfg.h: WARNMSG_CORE_OBSERVER_STOREWARNCONFIGCHK function macro definition is missing. Configure the respective interface in Cfg file"
#endif

CMPLIB_INSTANCE(WarnMsg_Core_Observer)
/******************************************************************************
 *                                 Type Declarations                          *
 ******************************************************************************/

/******************************************************************************
 *                                 File Scope Prototypes                      *
 ******************************************************************************/

/******************************************************************************
 *                                 Constants                              	  *
 *----------------------------------------------------------------------------*
 * Declaration shall be followed by a comment that gives the following info.  *
 * about the constant.                                                        *
 * purpose, unit and resolution                                               *
 ******************************************************************************/
 #define INIT_VAL				0U
 #define UNDEF_WARN				255U
 #define DISABLE_WARN			0U
 #define ENABLE_WARN			1U
 #define INIT_NOT_REQUESTED		0U
 #define TRIGGER_COLD_INIT		1U
 #define TRIGGER_WARM_INIT		2U
 #define WARN_DEFAULT_INSTANCE  0U
 /*****************************************************************************
 *                                 Manifest Constants                         *
 *----------------------------------------------------------------------------*
 * Definition of Manifest constant shall be followed by a comment that        *
 * explains the purpose of the constant.                                      *
 ******************************************************************************/

/******************************************************************************
 *                                 Macro Definitions                          *
 *----------------------------------------------------------------------------*
 * Definition of macro shall be followed by a comment that explains the       *
 * purpose of the macro.                                                      *
 ******************************************************************************/
 
 /*****************************************************************************
 *                                 Globally  accessed Variable Declarations   *
 *----------------------------------------------------------------------------*
 * Declaration shall be followed by a comment that gives the following info.  *
 * about the variable.                                                        *
 * purpose, critical section, unit, resolution, Valid Range and ValidityCheck *
 ******************************************************************************/
 eMessageIdentity l_ActiveStoreWarnData[PGM_CFGD_STORE_WARNINGS];

/******************************************************************************
 *                                 Locally used Variable Declarations         *
 *----------------------------------------------------------------------------*
 * Declaration shall be followed by a comment that gives the following info.  *
 * about the variable.                                                        *
 * purpose, critical section, unit, resolution, Valid Range and ValidityCheck *
 ******************************************************************************/ 

/*********************************************************************************************************************
 @brief  Transitional initialization state

 @return E_OK:           Succeed
<br>     E_NOT_READY:    In progress. Keeps the component in this state.
<br>     E_NOT_OK:       Failed
*********************************************************************************************************************/
static Std_ReturnType CmpInit( void )
{
    Std_ReturnType fl_RetVal_enum;
    uint8 fl_ReqdInit_u8;
    eMessageIdentity fl_InitWarnVal_enum;

    /*Initialization*/
    fl_RetVal_enum = E_OK;
    fl_ReqdInit_u8 = INIT_NOT_REQUESTED;
    fl_InitWarnVal_enum = miUndefined;

    WARNMSG_CORE_OBSERVER_INITCHK(&fl_ReqdInit_u8);
    
    if(TRIGGER_WARM_INIT == fl_ReqdInit_u8)
    {
        hm_msg_KSWarmInit();
    }
    else if(TRIGGER_COLD_INIT == fl_ReqdInit_u8)
    {
        hm_msg_KSColdInit();
    }
    else
    {
        /*Do Nothing*/
    }
    /*Initialize the Store Warn Array*/
    MemLib_MemSet(&l_ActiveStoreWarnData[0],fl_InitWarnVal_enum,sizeof(l_ActiveStoreWarnData));

    return fl_RetVal_enum;
}
/*********************************************************************************************************************
 @brief  Transitional de*initialization state

 @return E_OK:           Succeed
<br>     E_NOT_READY:    In progress. Keeps the component in this state.
<br>     E_NOT_OK:       Failed
*********************************************************************************************************************/
static Std_ReturnType CmpDeInit( void )
{
    Std_ReturnType fl_RetVal_enum;

    fl_RetVal_enum = E_OK;

    return fl_RetVal_enum;
}
/*********************************************************************************************************************
 @brief  Transitional activation state
 @return E_OK:           Succeed
<br>     E_NOT_READY:    In progress. Keeps the component in this state.
<br>     E_NOT_OK:       Failed
*********************************************************************************************************************/
static Std_ReturnType CmpActivation( void )
{	
    Std_ReturnType fl_RetVal_enum;

    fl_RetVal_enum = E_OK;

    return fl_RetVal_enum;
}
/*********************************************************************************************************************
 @brief  Transitional de-activation state

 @return E_OK:           Succeed
<br>     E_NOT_READY:    In progress
<br>     E_NOT_OK:       Failed
*********************************************************************************************************************/
static Std_ReturnType CmpDeActivation( void )
{
    Std_ReturnType fl_RetVal_enum;

    fl_RetVal_enum = E_OK;

    return fl_RetVal_enum;
}
/*********************************************************************************************************************
 @brief  Diagnostic state

 @return E_OK:           Diagnostic has completed. Go to DiagReturn state.
<br>     E_NOT_READY:    Keeps the component in this state.
*********************************************************************************************************************/
static Std_ReturnType CmpDiag( void )
{
    Std_ReturnType fl_RetVal_enum;

    fl_RetVal_enum = E_OK;

    return fl_RetVal_enum;
}
/*********************************************************************************************************************
 @brief  Transitional state to clean up after diagnostic state. Component behaviour to be restored.

 @return E_OK:           Diagnostic clean-up has completed. Return to the previous state (Active or Inactive).
<br>     E_NOT_READY:    Keeps the component in this state.
*********************************************************************************************************************/
static Std_ReturnType CmpDiagReturn( void )
{
    Std_ReturnType fl_RetVal_enum;

    fl_RetVal_enum = E_OK;

    return fl_RetVal_enum;
}
/*********************************************************************************************************************
 @brief  State for normal operations

 @return The return value is disregarded. Say E_OK
*********************************************************************************************************************/
static Std_ReturnType CmpActive( void )
{
    MSG_VIEWINFO_T fl_msg_info_S;
    Std_ReturnType fl_RetVal_enum;
    boolean fl_MsgCoreTrigCdn_bool;
    boolean fl_AddlActiveAct_bool;
    boolean fl_WrnCmpActive_bool;
    
    /*Initialization*/
    fl_MsgCoreTrigCdn_bool = FALSE;
    fl_RetVal_enum = E_OK;
    fl_AddlActiveAct_bool = FALSE;
    fl_WrnCmpActive_bool = FALSE;

    /*Program Specfic shall be invoked here*/
    CHECK_MSGCORE_TRIG_CDN(&fl_msg_info_S, &fl_MsgCoreTrigCdn_bool);

    if (FALSE != fl_MsgCoreTrigCdn_bool)
    {
        /*Message core RR */
        hm_msg_KSRRobin();
    }
    #if WARNMSG_CORE_OBSERVER_CFGD_INSTANCES > 1
    for (uint8 fl_iterval_u8 = INIT_VAL; fl_iterval_u8 < WARNMSG_CORE_OBSERVER_CFGD_INSTANCES; fl_iterval_u8 ++)
    {
        (void)msg_SequencerGetAlertInfo ( &fl_msg_info_S, fl_iterval_u8 );
        ADDL_ACTIVE_CHK(&fl_msg_info_S, &fl_AddlActiveAct_bool);
        if (FALSE != fl_AddlActiveAct_bool)
        {
            WARNMSG_CORE_OBSERVER_ADDLACTION();
        }
        TRIGGER_WARNING_ALERT(fl_msg_info_S.Status,fl_msg_info_S.InstanceID);
        /*Status will be set on NEW warnings. This value will be used to trigger the chime*/
        TRIGGER_WARNING_CHIME(fl_msg_info_S.Status);
        /*This Variable will be set when Warning Status has to be updated to UCL in CmpActive apart from Sequencer Invocation*/
        UPDATEWARNINTASKCHK(&fl_WrnCmpActive_bool);
        if ((FALSE != fl_WrnCmpActive_bool) && (miUndefined != fl_msg_info_S.Id))
        {
            WarnMsg_Core_Observer_UpdateToUCL(fl_msg_info_S.Id,ENABLE_WARN ,fl_msg_info_S.Status);
        }	
        /*Store warning function is invoked here and Store Array is passed to HMI via UCL*/
        (void)WarnMsg_Core_Observer_SendStoreWarnToUCL();
    }
    #else
    (void)msg_SequencerGetAlertInfo ( &fl_msg_info_S );
    ADDL_ACTIVE_CHK(&fl_msg_info_S, &fl_AddlActiveAct_bool);
    if (FALSE != fl_AddlActiveAct_bool)
    {
        WARNMSG_CORE_OBSERVER_ADDLACTION();
    }
    TRIGGER_WARNING_ALERT(fl_msg_info_S.Status,fl_msg_info_S.InstanceID);
    /*Status will be set on NEW warnings. This value will be used to trigger the chime*/
    TRIGGER_WARNING_CHIME(fl_msg_info_S.Status);
    /*This Variable will be set when Warning Status has to be updated to UCL in CmpActive apart from Sequencer Invocation*/
    UPDATEWARNINTASKCHK(&fl_WrnCmpActive_bool);
    if ((FALSE != fl_WrnCmpActive_bool) && (miUndefined != fl_msg_info_S.Id))
    {
        WarnMsg_Core_Observer_UpdateToUCL(fl_msg_info_S.Id,ENABLE_WARN ,fl_msg_info_S.Status);
    }	
    /*Store warning function is invoked here and Store Array is passed to HMI via UCL*/
    (void)WarnMsg_Core_Observer_SendStoreWarnToUCL();
    #endif
    return fl_RetVal_enum;
}
/****************************************************************************
Function Name     : WarnMsg_Core_Observer_ShowNewMsgNotification
Description       : This function shall be called whenever a new Msg needs to
                    be displayed. This receives a High priority Alert info
                    from Msg Core and Activates respective Pop-up.
Invocation        : MSG core
Parameters        : MSG_VIEWINFO_T * p_msg_info_S
                        - Holds current active msg information
Return Value      : None
Critical Section  : None
 ******************************************************************************/
void WarnMsg_Core_Observer_ShowNewMsgNotification (const MSG_VIEWINFO_T * p_msg_info_S )
{
    MSG_VIEWINFO_T fl_ShowNotifyData_S;
    boolean fl_ShowExtnCdnChk_bool;
    
    /*Initialization*/
    fl_ShowExtnCdnChk_bool = FALSE;
    MemLib_MemCpy(&fl_ShowNotifyData_S,p_msg_info_S,sizeof(MSG_VIEWINFO_T));
    
    /*Program Specfic shall be invoked here*/
    WARNMSG_CORE_OBSERVER_SHOWEXTNCHK (&fl_ShowExtnCdnChk_bool);
    if(FALSE != fl_ShowExtnCdnChk_bool)
    {
        /*UCL Function Invocation*/
        WarnMsg_Core_Observer_UpdateToUCL(p_msg_info_S->Id,ENABLE_WARN , fl_ShowNotifyData_S.Status);
        #if WARNMSG_CORE_OBSERVER_CFGD_INSTANCES > 1
        (void)msg_SequencerShow ( p_msg_info_S-> InstanceID );
        #else
        (void)msg_SequencerShow();
        #endif
    }
    else
    {
        /*Do Nothing*/
    }
}
/****************************************************************************
Function Name     : WarnMsg_Core_Observer_HideMsgNotification
Description       : To process the Message core request to remove/hide message
Invocation        : MSG core
Parameters        : eMessageIdentity p_MsgId_E
                        - Current active msg
Return Value      : None
Critical Section  : None
 ******************************************************************************/
void WarnMsg_Core_Observer_HideMsgNotification ( eMessageIdentity p_MsgId_E )
{
    uint8 fl_WarningInst_u8;
    boolean fl_HideExtnCdnChk_bool;

    /*Initialization*/
    fl_WarningInst_u8 = WARN_DEFAULT_INSTANCE;
    fl_HideExtnCdnChk_bool = FALSE;
    
    /*Program Specfic shall be invoked here*/
    WARNMSG_CORE_OBSERVER_HIDEEXTNCHK (&fl_HideExtnCdnChk_bool);
    if(FALSE != fl_HideExtnCdnChk_bool)
    {
        /*UCL Function Invocation*/	
        WarnMsg_Core_Observer_UpdateToUCL(p_MsgId_E,DISABLE_WARN , MSG_OLD);
        fl_WarningInst_u8 = messageList[p_MsgId_E].InstanceID;
        /*Program Specfic shall be invoked here*/
        #if WARNMSG_CORE_OBSERVER_CFGD_INSTANCES > 1
        (void)msg_SequencerHide ( fl_WarningInst_u8 );
        #else
        (void)msg_SequencerHide();
        #endif
    }
    else
    {
        /*Do Nothing*/
    }
}
/****************************************************************************
Function Name     : CWarnMsg_Core_Observer_Notify_Status_Cb
Description       : This fucntions used to get the msg status from App's.
                    UI_MSG_UNIT_TESTING macro shall be used to bypass application
                    So that we can perform unit testing of warning by changing
                    the warning status
Invocation        : MSG core
Parameters        : None
Return Value      : True/False
Critical Section  : None
******************************************************************************/
#if MSG_NUM_INSTANCES > 1 
SIF_STATUS WarnMsg_Core_Observer_Notify_Status_Cb(uint16 *Data, WarningId Qualifier, uint8 inst)
#else 
SIF_STATUS WarnMsg_Core_Observer_Notify_Status_Cb(uint16 *Data, WarningId Qualifier)
#endif
{
    WarningDisplayedStatus fl_notify_action_U8;
    SIF_STATUS fl_RetVal_enum;
    boolean fl_notify_status_BOOL;
        
    /*Initialization*/
    fl_notify_status_BOOL = FALSE;
    fl_notify_action_U8 = WRNG_NOTIFIED_NONE;
    fl_RetVal_enum = sif_OK;

    switch (*Data)
    {
        case MSG_EVENT_HIDDEN:
            WARNMSG_CORE_OBSERVER_EVENTHIDDENCHK (&fl_notify_status_BOOL);
            fl_notify_action_U8 = WRNG_NOTIFIED_HIDDEN;
            break;
        case MSG_EVENT_SHOW:
            WARNMSG_CORE_OBSERVER_EVENTSHOWCHK (&fl_notify_status_BOOL);
            fl_notify_action_U8 = WRNG_NOTIFIED_SHOW;
            break;
        case MSG_EVENT_TIMEOUT:
        case MSG_EVENT_NEW_MSGQ_TIMEOUT: 	/* Notify warning status as timeout when warning is removed because of sequence timeout */
            /* Notify warning status to application */
            WARNMSG_CORE_OBSERVER_EVENTTIMEOUTCHK (&fl_notify_status_BOOL);
            fl_notify_action_U8 = WRNG_NOTIFIED_TIMEOUT;
            break;
        case MSG_EVENT_ACKNOWLEDGED:
            /* Notify warning status to application */
            WARNMSG_CORE_OBSERVER_EVENTACKCHK (&fl_notify_status_BOOL);
            fl_notify_action_U8 = WRNG_NOTIFIED_ACKNOWLEDGED;
            break;
        case MSG_EVENT_INACTIVE:
            WARNMSG_CORE_OBSERVER_EVENTINACTIVECHK (Qualifier, &fl_notify_status_BOOL);
            fl_notify_action_U8 = WRNG_NOTIFIED_INACTIVE;
            break;
        default:
            break;
    }
    
    /*Program Specfic shall be invoked here*/
    
    if (FALSE != fl_notify_status_BOOL) 
    {
        WARNMSG_CORE_OBSERVER_SETWARNDISPSTS(Qualifier, fl_notify_action_U8);
    }    
    
    return (fl_RetVal_enum);
}	
/*****************************************************************************
Function Name    : WarnMsg_Core_Observer_SendStoreWarnToUCL
Description      : Since redisplay warnings are added with store option ,
                   this function will be used to get actual store warning position and count.
Invocation       : 
Parameters       : MSG_VIEWINFO_T
Return Value     : None
Critical Section : None
***************************************************************************/
void WarnMsg_Core_Observer_SendStoreWarnToUCL(void)
{
    MSG_VIEWINFO_T fl_msg_info_S ;
    uint16 fl_StoreWarnCount_u16;
 
   MemLib_MemSet(&fl_msg_info_S, 0, sizeof(MSG_VIEWINFO_T)); 

    #if WARNMSG_CORE_OBSERVER_CFGD_INSTANCES > 1
    for(uint8 flInst = 0U ; flInst < WARNMSG_CORE_OBSERVER_CFGD_INSTANCES ; flInst++)
    {
        /*Initialization*/
        fl_StoreWarnCount_u16 = INIT_VAL;

        /*Get the Latest Store Warning data from Message Core*/
        (void)msg_StoreGetCurrent ( &fl_msg_info_S, flInst );

        if (INIT_VAL != fl_msg_info_S.Count)
        {
            for(uint16 flIndex = INIT_VAL ; flIndex < fl_msg_info_S.Count ;flIndex++)
            {
                /*To check whether the index is the configured for stored warning*/
                if(FALSE != WARNMSG_CORE_OBSERVER_STOREWARNCONFIGCHK(stor_MessageList[fl_msg_info_S.InstanceID][flIndex]))
                {                          
                    l_ActiveStoreWarnData[fl_StoreWarnCount_u16] = stor_MessageList[fl_msg_info_S.InstanceID][flIndex];
                    fl_StoreWarnCount_u16 ++;
                }
            }
        }
        /*Update Array with count, Position, warning list and send to UCL*/
        WARNMSG_CORE_OBSERVER_SENDSTOREDATATOUCL(l_ActiveStoreWarnData,fl_StoreWarnCount_u16,fl_msg_info_S.InstanceID);
    }

    #else
    (void)msg_StoreGetCurrent (&fl_msg_info_S);
    
    /*Initialization*/
    fl_StoreWarnCount_u16 = INIT_VAL;

    if (INIT_VAL != fl_msg_info_S.Count)
    {
        for(uint16 flIndex = INIT_VAL ; flIndex < fl_msg_info_S.Count ;flIndex++)
        {
            /*To check whether the index is the configured for stored warning*/
           if(FALSE != WARNMSG_CORE_OBSERVER_STOREWARNCONFIGCHK(stor_MessageList[0][flIndex]))
           {                          
                l_ActiveStoreWarnData[fl_StoreWarnCount_u16] = stor_MessageList[0][flIndex];
                fl_StoreWarnCount_u16 ++;
           }
        }
    }

    /*Update Array with count, Position, warning list and send to UCL*/
    WARNMSG_CORE_OBSERVER_SENDSTOREDATATOUCL(l_ActiveStoreWarnData,fl_StoreWarnCount_u16);
    #endif    
}
/*****************************************************************************
Function Name    : WarnMsg_Core_Observer_Store_Remove_Notification
Description      : This interface will get invoked when a warning is getting removed
                    from store queue
Invocation       : Message Core
Parameters       : WarningId
Return Value     : None
Critical Section : None
***************************************************************************/
void WarnMsg_Core_Observer_StoreRemoveNotification(eMessageIdentity p_message_id)
{
    WarnMsg_Core_Observer_SendStoreWarnToUCL();
}
/****************************************************************************
Function Name     : WarnMsg_Core_Observer_UpdateToUCL
Description       : To Sent the Current Message data to UCL
Invocation        : Local
Parameters        : eMessageIdentity p_MsgId_E
                        - Current active msg
Return Value      : None
Critical Section  : None
 ******************************************************************************/
static void WarnMsg_Core_Observer_UpdateToUCL(eMessageIdentity p_cur_warn_id, uint8 Status , uint8 MsgStatus)
{
    SWarningDisplay fl_warning_data_S;
    ExtWarningData fl_warning_info_S;
    uint8 fl_WarningInst_u8;
    boolean fl_UclPreTrigChecks_bool;

    /*Initialization*/
    fl_UclPreTrigChecks_bool = FALSE;
    fl_warning_data_S.show = UNDEF_WARN;
    fl_warning_data_S.warningId = miMaximum;
    fl_WarningInst_u8 = WARN_DEFAULT_INSTANCE;
    MemLib_MemSet(&fl_warning_info_S, 0U, sizeof(ExtWarningData));

    /*Program Specific*/
    CHECK_PREUCL_TRIG_CDN (&fl_UclPreTrigChecks_bool);
    
    if((ENABLE_WARN == Status) && (miMaximum > p_cur_warn_id))
    {
        fl_warning_data_S.show = ENABLE_WARN;
        fl_warning_data_S.warningId = messageList[p_cur_warn_id].ConditionQualifier;
        fl_WarningInst_u8 = messageList[p_cur_warn_id].InstanceID;
        WARNMSG_CORE_OBSERVER_GETWARNSTS(fl_warning_data_S.warningId, &fl_warning_info_S);
        /*DataType updated from (void*) to (uint8*)*/
        MemLib_MemCpy((uint8*)&fl_warning_data_S.dynData[0],(uint8*)&fl_warning_info_S.ExtWarningCurrentPayload[0], sizeof(data_u8_8));
    }
    if(DISABLE_WARN == Status)
    {
        fl_warning_data_S.show = DISABLE_WARN;
        fl_warning_data_S.warningId = MAX_WARNINGS_CONFIGURED;
        fl_WarningInst_u8 = messageList[p_cur_warn_id].InstanceID;
        MemLib_MemSet(&(fl_warning_data_S.dynData),NO_PAYLOAD_REQD, sizeof(data_u8_8));	
    }

    if((UNDEF_WARN != Status) && (FALSE != fl_UclPreTrigChecks_bool))
    {
        WARNMSG_CORE_OBSERVER_SENDTOUCL(&fl_warning_data_S, fl_WarningInst_u8 , MsgStatus);
    }
}

#if WARNMSG_CORE_OBSERVER_CFGD_INSTANCES > 1
/****************************************************************************
Function Name     : OnDre_UCL_MultiZone_WarnStatus
Description       : To process the message acknowledgement
Invocation        : UCL adpted
Parameters        : None
Return Value      : void
Critical Section  : None
 ******************************************************************************/
void OnDre_UCL_MultiZone_WarnStatus(uint8 inst)
{
    MSG_VIEWINFO_T fl_msg_info_S;
    EButtonSts fl_RxdButtonEvent_u8;
    boolean fl_ActionToBeContd_bool;
    
    /*Initialzation*/
    MemLib_MemSet(&fl_msg_info_S, 0U, sizeof(MSG_VIEWINFO_T));
    fl_RxdButtonEvent_u8 = EButtonSts_Off;
    fl_ActionToBeContd_bool= FALSE;

    /*Get the Sequencer Data*/

    (void)msg_SequencerGetAlertInfo (&fl_msg_info_S, inst);
    WARNMSG_CORE_OBSERVER_PREACKACTION ((WarningId)fl_msg_info_S.Id, inst, &fl_RxdButtonEvent_u8,&fl_ActionToBeContd_bool);
    
    if (FALSE != fl_ActionToBeContd_bool)
    {
        (void)msg_SequencerAction(fl_RxdButtonEvent_u8, inst);
    }

    /*To Check if any Program/OEM specific actions are applicable after Acknowledgement handling*/
    if(FALSE != WARNMSG_CORE_OBSERVER_POSTACKCFG)
    {
       (void)WARNMSG_CORE_OBSERVER_POSTACKACTION(inst);
    }

}

#else
/****************************************************************************
Function Name     : OnDre_UCL_SingleZone_WarnStatus
Description       : To process the message acknowledgement
Invocation        : UCL adpted
Parameters        : None
Return Value      : void
Critical Section  : None
 ******************************************************************************/
void OnDre_UCL_SingleZone_WarnStatus(void)
{
    MSG_VIEWINFO_T fl_msg_info_S;
    EButtonSts fl_RxdButtonEvent_u8;
    boolean fl_ActionToBeContd_bool;
    
    /*Initialzation*/
    MemLib_MemSet(&fl_msg_info_S, 0U, sizeof(MSG_VIEWINFO_T));
    fl_RxdButtonEvent_u8 = EButtonSts_Off;
    fl_ActionToBeContd_bool= FALSE;

    /*Get the Sequencer Data*/
    (void)msg_SequencerGetAlertInfo (&fl_msg_info_S);
    WARNMSG_CORE_OBSERVER_PREACKACTION ((WarningId)fl_msg_info_S.Id, (uint8)0, &fl_RxdButtonEvent_u8,&fl_ActionToBeContd_bool);
    if(FALSE != fl_ActionToBeContd_bool)
    {
        (void)msg_SequencerAction(fl_RxdButtonEvent_u8);
    }

    /*To Check if any Program/OEM specific actions are applicable after Acknowledgement handling*/
    if(FALSE != WARNMSG_CORE_OBSERVER_POSTACKCFG)
    {
        (void)WARNMSG_CORE_OBSERVER_POSTACKACTION((uint8)0);
    }

}
#endif
/****************************************************************************
Function Name     : Redisplay Button Handle
Description       : To handle the redisplay warning timer invocation
Invocation        : Mdl_CButton
Parameters        : None
Return Value      : None
Critical Section  : None
 ******************************************************************************/
FUNC(void, WarnMsg_Core_Observer_CODE) WarnMsg_Core_Observer_SW_NoOperationTimer(EButtonId pEvent, EButtonSts pEventType)
{
    boolean fl_TmrTrigDet_bool;

    /*Initialization*/
    fl_TmrTrigDet_bool = FALSE;
    
    /*To Check if any Program/OEM specific actions are applicable after Acknowledgement handling*/
    fl_TmrTrigDet_bool = WARNMSG_CORE_OBSERVER_BUTTONACTION(pEvent, pEventType);
    if(FALSE != fl_TmrTrigDet_bool)
    {
        #if WARNMSG_CORE_OBSERVER_CFGD_INSTANCES > 1
        for (uint8 fl_iterval_u8 = INIT_VAL; fl_iterval_u8 < WARNMSG_CORE_OBSERVER_CFGD_INSTANCES; fl_iterval_u8 ++)
        {
            msg_StorAckWrngRepTimerControl(ACK_WRNG_REP_TIMER_RESTART, fl_iterval_u8);
        }
        #else
        msg_StorAckWrngRepTimerControl(ACK_WRNG_REP_TIMER_RESTART);
        #endif
    }
}
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
Date              : 30-08-2024
CDSID             : vrk
Traceability      : TFDCX32348-38610
Change Description: 1. Updated CmpInit and the WarmInit check is moved to CmpActive 
                        to meet the requirements.
                    2. Added Chime trigger function invocation
                    3. Added the OnDre_UCL_WarnStatus and will be uncommented on the 
                       RTE is added in UCL side.
                    4. Store Warning variable name is updated based on cfg update.
                    5. Data type of UCL variable is updated based on RTE Type.
                    6. Payload functionality invocation is added
                    7. Updating Warning Status is configurable based on Program Requirements
 ******************************************************************************/
/****************************************************************************
Date              : 13-09-2024
CDSID             : vrk
Traceability      : TFDCX32348-38610
Change Description: Uncommented OnDre_UCL_WarnStatus and added relevant content for feedback
                        from GIP.
 ******************************************************************************/ 
/****************************************************************************
Date              : 24-09-2024
CDSID             : vrk
Traceability      : TFDCX32348-38818
Change Description: Updated the funtion OnDre_UCL_WarnStatus to handle different events of 
                    Acknowledgements
 ******************************************************************************/ 
/****************************************************************************
Date              : 19-11-2024
CDSID             : vrk
Traceability      : DICMBD-395
Change Description: Updated the datatype to support Actvive warning status
                    WarningDataS is now ExtWarningData
 ******************************************************************************/ 
/****************************************************************************
Date              : 21-11-2024
CDSID             : vrk
Traceability      : TFDCX32348-57493
Change Description: Updated to support SW_NoOperationTimer to enable redisplay functionality
 ******************************************************************************/ 
/****************************************************************************
Date              : 12-12-2024
CDSID             : vrk
Traceability      : TFDCX32348-61095
Change Description: Updated to support Multi-instance
 ******************************************************************************/ 
/****************************************************************************
Date              : 08-01-2025
CDSID             : vrk
Traceability      : TFDCX32348-63128
Change Description: Updated the acknowledgement action for multi-instance 
                    to resolve the acknowledgement issue
 ******************************************************************************/ 
/****************************************************************************
Date              : 31-01-2025
CDSID             : ashenoy1
Traceability      : --
Change Description: Added Func for MultiInstance and SingleInstance for WarnStatus Event
 ******************************************************************************/
/****************************************************************************
Date              : 18-04-2025
CDSID             : vrk
Traceability      : TFDCX32348-81727
Change Description: Removed the initiaization of l_ActiveStoreWarnData to resolve the compiler
                    warnings in Toyota
 ******************************************************************************/
 /****************************************************************************
Date              : 22-05-2025
CDSID             : vrk
Traceability      : TFDCX32348-86429
Change Description: Moved the function - WarnMsg_Core_Observer_StoreWarnConfigChk to Extn and
                    added the MACRO WARNMSG_CORE_OBSERVER_STOREWARNCONFIGCHK to same 
 ******************************************************************************/
  /****************************************************************************
Date              : 04-06-2025
CDSID             : vrk
Traceability      : TFDCX32348-89892
Change Description: Fixed a bug with respect to MULTI-Instances
 ******************************************************************************/       
/*End of Revision History*/
