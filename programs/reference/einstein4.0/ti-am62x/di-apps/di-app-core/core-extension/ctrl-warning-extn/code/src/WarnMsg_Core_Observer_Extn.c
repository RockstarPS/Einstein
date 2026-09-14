/******************************************************************************

File Name        :  CWarnMsg_Core_Observer_Extn.c                                                
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
#define WARNMSG_CORE_OBSERVER_EXTN_C
 /*****************************************************************************
 *                                 System Includes                            *
 ******************************************************************************/
/*Add the System Includes here*/
/******************************************************************************
 *                                 Project Includes                           *
 ******************************************************************************/
#include "WarnMsg_Core_Observer_Extn.h"
#include "Std_Types.h"
#include "string.h"
#include "MemLib.h"
#include "Rte_CWarnMsg_Core_Observer.h"
#include "WarningConfiguredChime.cfg"
#include "WarnMsg_Core_Observer_GetCurrIgnSts.h"
#include "WarningIntType_Data.cfg"
#include "WarningCANTx.cfg"
#include "WarningCommonLogic_autogen.inc"
#include "Store_Warning_Data.cfg"
/******************************************************************************
 *                                 Type Declarations                          *
 ******************************************************************************/


/******************************************************************************
 *                                 File Scope Prototypes                      *
*******************************************************************************/

/******************************************************************************
 *                                 Constants                              	  *
 *----------------------------------------------------------------------------*
 * Declaration shall be followed by a comment that gives the following info.  *
 * about the constant.                                                        *
 * purpose, unit and resolution                                               *
 ******************************************************************************/
static const uint8 msg_associated_chimes_list[MSG_NUM_MESSAGES] =
{
    MSG_ASSO_CHIMES_CONF_LIST
};
const WARNCANTX_STRUCT l_WarnTxList_A[WARN_CANTX_CFGD] =
{
   //WARN_CANTXCFGD_LIST
};
const uint8 l_RxdBtnToBitwiseConv[8] = {
    0x0U, /*No Button*/ 
    0x1U, /*EButtonIDs_Enter*/ 
    0x2U, /*EButtonIDs_Back*/ 
    0x4U, /*EButtonIDs_Left*/
    0x8U, /*EButtonIDs_Right*/ 
    0x10U, /*EButtonIDs_Up*/
    0x20U, /*EButtonIDs_Down*/
    0x40U, /*EButtonIDs_Last*/
    };
const uint8 l_PayloadInitVal[8] = {0U,0U,0U,0U,0U,0U,0U,0U};     
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
 /*Micelleaneous Macros*/
 #define WRN_FALSE              0U
 #define WRN_TRUE               1U
/*Init Macros*/
 #define NO_INIT_REQUESTED      0U
 #define WARM_INIT_REQUESTED    1U
 #define COLD_INIT_REQUESTED    2U
 #define STRTR_STS_OFF          0U
 /*Warning Disaplyed Info*/
 #define NOACTUIVEWARN          (uint16)0U
 #define WARNING_NOT_DISPLAYED  (uint8)0U
 #define PAYLOAD_SIZE           8U      
 #define FACTORYMODE_DISABLED   0U
 #define FACTORYMODE_ENABLED    1U
 #define EXTN_DISABLE_WARN      0U
 /*High Interrupt Macros*/
 #define FACTORY_INT            1U
 /*Button Macros*/
 #define RXD_BUTTON_DATA        8U
 #define BACK_BUTTON_PRSD       (uint8)32U
 #define RXD_CURSOR_DATA        9U
 #define BTN_EXTRACT            4U
 /*Message Types*/
 #define OLD_MESSAGE            0U
 #define SCREEN_BLANK			0U
 /*Store Warning Macros*/
 #define MESSAGE_HMIINT         9U
 #define DEFAULT_STORE_COUNT    0U
 #define STORE_WRN_QUEUE_SIZE   15U
 #define STORE_INVLD_ORDER      255U
 #define MSG_TAB_ACTIVE         2U
 #define INVLD_STOREWARN        (uint16)TotalNumOfWarnings  
 /*****************************************************************************
 *                                 Globally  accessed Variable Declarations   *
 *----------------------------------------------------------------------------*
 * Declaration shall be followed by a comment that gives the following info.  *
 * about the variable.                                                        *
 * purpose, critical section, unit, resolution, Valid Range and ValidityCheck *
 ******************************************************************************/

/******************************************************************************
 *                                 Locally used Variable Declarations         *
 *----------------------------------------------------------------------------*
 * Declaration shall be followed by a comment that gives the following info.  *
 * about the variable.                                                        *
 * purpose, critical section, unit, resolution, Valid Range and ValidityCheck *
 ******************************************************************************/  
static uint16 l_PrevWarnId_u16;
static uint8 l_MasterChime_u8;
static uint8 l_PrevIgnSts_u8;
static uint8 l_PrevStarterSts_u8;
static uint8 l_TriggrdChime_u8;
static uint8 l_ActiveStoreCnt_u8;
static uint8 l_NextStartIdx_u8;
static uint8 l_ActvStorePayload_A[CFGD_STORE_WARNINGS][PAYLOAD_SIZE];
static uint8 l_FactModeTransChk_u8;
static boolean l_StoreLockFlag_bool;
static boolean l_CustLockFlag_bool;
/*static boolean l_UnlockWarnFlag_bool;*/
/*This l_UnlockWarnFlag_bool will be set only once in Ignition OFF State if any
of the required warnings is set. This is to initiate WarmInit of Message core. 
In Toyota when WRN_DOOR_UNLMOD_02 is changed from some other warning, 
warm_init is required.
*/
/*****************************************************************************
Function Name    : ProgramInitRequest
Description      : Check the conditions to initialize the message core (Warm/Cold init)
                   based on the requirements
Invocation       : WarnMsg_Core_Observer
Parameters       : uint8 *Data
                          - Poniter to varibale, Holds type of Init to be requested in CmpInit
Return Value     : None
Critical Section : None
*****************************************************************************/
void ProgramInitRequest ( uint8 *Data )
{
    /*Declaration*/
    SStoreWarnData  fl_StoreWarnUclData;
    SStoreWarnCountdata fl_StoreWarnCount_u16;
    /*Initialization*/
    *Data = COLD_INIT_REQUESTED;
    /*l_UnlockWarnFlag_bool = FALSE;*/
    l_PrevIgnSts_u8 = IgnOff;
    l_PrevWarnId_u16 = TotalNumOfWarnings;
    l_MasterChime_u8 = (uint8)ChimeRelease;
    l_PrevStarterSts_u8 = STRTR_STS_OFF;
    l_TriggrdChime_u8 = eSnd_NoChimeID;
    l_ActiveStoreCnt_u8 = DEFAULT_STORE_COUNT;
    l_NextStartIdx_u8 = DEFAULT_STORE_COUNT;
    fl_StoreWarnCount_u16.storeWarnCount = DEFAULT_STORE_COUNT;
    l_StoreLockFlag_bool = WRN_FALSE;
    l_CustLockFlag_bool = WRN_FALSE;
    l_FactModeTransChk_u8 = FACTORYMODE_DISABLED;
    (void)Rte_Write_pp_WarnInt_WarningInterrupt_State(WARN_INT_NONE);
    //(void)Rte_Write_pp_WarnIntId_WarningInterrupt_Identifier(TotalNumOfWarnings);
    //(void)Rte_Write_pp_WarnIntDispTyp_WarnInterrupt_DispType(OLD_MESSAGE);
    //(void)Rte_Write_pp_WarnIntHud_HUDWarningInterrupt_State(WARN_INT_NONE);
    //(void)Rte_Write_pp_WarnIntIdHud_HUDWarningInterrupt_Identifier(TotalNumOfWarnings);
    /*Store Warning Initializations*/
    /*Store Warning UCL Struct is initialized in a loop*/
    for(uint8 fl_UclInitIter_u8 = DEFAULT_STORE_COUNT; fl_UclInitIter_u8 < STORE_WRN_QUEUE_SIZE; fl_UclInitIter_u8++)
    {
        fl_StoreWarnUclData.sstoreWarnData[fl_UclInitIter_u8].storewarnid = TotalNumOfWarnings;
        fl_StoreWarnUclData.sstoreWarnData[fl_UclInitIter_u8].order = STORE_INVLD_ORDER;
        MemLib_MemCpy((uint8*)&fl_StoreWarnUclData.sstoreWarnData[fl_UclInitIter_u8].dynData,(uint8*)l_PayloadInitVal,sizeof(l_PayloadInitVal));
    }
    /*Store Warning Initial structure is copied into the actual Store Warning Actual Struct*/
    //(void)Rte_Send_pSR_StoreWarnData_StoreWarnDataData(&fl_StoreWarnUclData);
    //(void)Rte_Write_pSR_StoreWarnCountdata_StoreWarnCountdataData(&fl_StoreWarnCount_u16);
}
/*****************************************************************************
Function Name    : CheckInitCall
Description      : Check the conditions to reinitialize the message core (Warm/Cold init)
                   based on the requirements
Invocation       : WarnMsg_Core_Observer
Parameters       : MSG_VIEWINFO_T *Data
                          - Poniter to varibale, Holds Sequencer Data
Return Value     : fl_RetVal_u8
                    - The init requested status
Critical Section : None
*****************************************************************************/
uint8 CheckInitCall ( MSG_VIEWINFO_T *Data )
{
    IgntionSubstateType fl_CurrIgnSts_u8;
    uint8 fl_clustermode_U8;
    uint8 fl_StarterStatus_u8;
    uint8 fl_RetVal_u8;

    /*Initialization*/
    fl_RetVal_u8 = NO_INIT_REQUESTED;
    fl_CurrIgnSts_u8 = IgnOff;
    fl_clustermode_U8 = CLUSTER_INACTIVE;
    fl_StarterStatus_u8 = STRTR_STS_OFF;  
    
    (void)Rte_Read_rpIgnSubstate_IgnitionSubstate(&fl_CurrIgnSts_u8);
    (void)Rte_Read_rp_ClusterMode_WSSCurrentClusterMode(&fl_clustermode_U8);
    (void)Rte_Read_rp_IllumStartSts_StarterStatus_Out(&fl_StarterStatus_u8);
    if(CLUSTER_INACTIVE != fl_clustermode_U8)
    {
        /*This is temporary to trigger warm init in IgnOff and the logic below will be uncommented once warnings mentioned below are enabled*/
        /*if(IgnOff == fl_currentIgnStatus_U8) 
        {
            if(Data->Id == WRN_DOOR_UNLMOD_02)
            {
                l_UnlockWarnFlag_bool = TRUE;
                fl_RetVal_u8 = NO_INIT_REQUESTED;
            }
            else if(Data->Id == WRN_MFLID_MFLID_01)
            {
                l_UnlockWarnFlag_bool = FALSE;
                fl_RetVal_u8 = NO_INIT_REQUESTED;
            }
            else
            {
                if(l_UnlockWarnFlag_bool == TRUE)
                {
                    l_UnlockWarnFlag_bool = FALSE;
                    fl_RetVal_u8 = WARM_INIT_REQUESTED;*/
                    /*WarmInit is requested to display the warnings other than WRN_DOOR_UNLMOD_02 in IgnOff as new warnings as per requirements*/
                /*}*/
            /*}*/
        /*}*/
        if (((IgnOff == l_PrevIgnSts_u8) && (IgnOff != fl_CurrIgnSts_u8)) || ((STRTR_STS_OFF != l_PrevStarterSts_u8) && (STRTR_STS_OFF == fl_StarterStatus_u8)))
        {
            /*TFDCX32348-28191*/
            fl_RetVal_u8 = WARM_INIT_REQUESTED;
        }
        else
        {
            fl_RetVal_u8 = NO_INIT_REQUESTED;
            /*l_UnlockWarnFlag_bool = FALSE;*/
        }
    }
    else
    {
        fl_RetVal_u8 = NO_INIT_REQUESTED;
        /*l_UnlockWarnFlag_bool = FALSE;*/
    }
   
    l_PrevIgnSts_u8 = fl_CurrIgnSts_u8;
    l_PrevStarterSts_u8 = fl_StarterStatus_u8;

     /*Toyota Specfic end*/
    return(fl_RetVal_u8);
}
/****************************************************************************
Function Name     : WarnMsg_Core_Observer_GetCurrIgnSts
Description       : Function used to get the current IGN status.
Invocation        : Message Core
Parameters        : None
Return Value      : IGN Status
                        - MSGOBS_IGN_ON / MSGOBS_IGN_OFF
Critical Section  : None
 ******************************************************************************/
uint8 WarnMsg_Core_Observer_GetCurrIgnSts(void)
{
   uint8 fl_Ignition_return_status_U8;
    uint8 fl_clustermode_U8;
    uint8 fl_HmiInterruptSts_u8;
    
    /*Initialization*/
    fl_Ignition_return_status_U8 = IgnOff;
    fl_clustermode_U8 = CLUSTER_INACTIVE;
    fl_HmiInterruptSts_u8 = NORMAL;   
    
    /*Invoke the RTE defined in Extension*/
    (void)Rte_Read_rpIgnSubstate_IgnitionSubstate(&fl_Ignition_return_status_U8);
    //(void)Rte_Read_rp_HmiIntTyp_HmiInterruptSts(&fl_HmiInterruptSts_u8);
    (void)Rte_Read_rp_ClusterMode_WSSCurrentClusterMode(&fl_clustermode_U8);

    if(CLUSTER_INACTIVE != fl_clustermode_U8)
    {
        if(IgnOff == fl_Ignition_return_status_U8)
        {
            fl_Ignition_return_status_U8 = LIMITED;
        }
        else if (SCREEN_BLANK == fl_HmiInterruptSts_u8)
        {
            fl_Ignition_return_status_U8 = MSG_FREEZE_IGN_MODE;
        }
        else
        {
            fl_Ignition_return_status_U8 = NORMAL;
        }
    }
    else
    {
        fl_Ignition_return_status_U8 = APPLICATION_INACTIVE;
    }

    return(fl_Ignition_return_status_U8);
}
/*****************************************************************************
Function Name    : CheckMsgCoreTrig
Description      : Used to get the Robin trigger condition status
Invocation       : WarnMsg_Core_Observer
Parameters       : Boolean *Data
                          - Poniter to varibale, Holds RobinTrigger status
Return Value     : None
Critical Section : None
*****************************************************************************/
void CheckMsgCoreTrig ( MSG_VIEWINFO_T *Data, boolean *RetVal )
{
    /* Return TRUE if there are no program specific conditions*/
    SWarningDisplay fl_UclData_S;
    Arr_u8_8 fl_RxdFacPayload_A;
    uint8 fl_FactoryMode_u8;
    uint8 fl_HmiReadySts_u8;

    /*Initialization*/
    *RetVal = WRN_TRUE;
    fl_FactoryMode_u8 = FACTORYMODE_DISABLED;
    fl_HmiReadySts_u8 = eHMI_READY;  
    MemLib_MemSet(&fl_UclData_S, 0U,sizeof(SWarningDisplay));
    MemLib_MemSet(&fl_RxdFacPayload_A[0],0U,sizeof(Arr_u8_8));
    /*RTE Read*/  
    (void)Rte_Read_rp_FactoryMode_FactoryMode(&fl_FactoryMode_u8);
    (void)Rte_Read_rp_HMIReadySts_HMI_ReadyStatus(&fl_HmiReadySts_u8); 

    if(eHMI_NOT_READY == fl_HmiReadySts_u8)
    {
        *RetVal = WRN_FALSE;
    }
    else if(FACTORYMODE_DISABLED != fl_FactoryMode_u8)
    {
        *RetVal = WRN_FALSE;
        //(void)Rte_Read_rp_FactoryModePayload_WarnPayload_Val(&fl_RxdFacPayload_A[0]);
        fl_UclData_S.warningId = WRN_NORM_FACTORY;
        fl_UclData_S.show = EXTN_NEWDISP;
        MemLib_MemCpy((uint8*)&fl_UclData_S.dynData[0],(uint8*)&fl_RxdFacPayload_A[0], sizeof(data_u8_8));
        UpdateWarnStsToUCL(&fl_UclData_S, DEFAULT_INSTANCE, MSG_NEW);
        l_FactModeTransChk_u8 = FACTORYMODE_ENABLED;
    }
    /*To Turn Off the Factory Warning Immediately and remove the Factory Mode screen as UCL is ON Change*/
    else if ((FACTORYMODE_DISABLED != l_FactModeTransChk_u8) && (FACTORYMODE_DISABLED == fl_FactoryMode_u8))
    {
        fl_UclData_S.warningId = WRN_NORM_FACTORY;
        fl_UclData_S.show = EXTN_DISABLE_WARN;
        UpdateWarnStsToUCL(&fl_UclData_S, DEFAULT_INSTANCE, MSG_NEW);
        l_FactModeTransChk_u8 = FACTORYMODE_DISABLED;
    } 
    else
    {
        /*Do Nothing*/
    }
}
/*****************************************************************************
Function Name    : MsgCoreExtnAddlActiveChk
Description      : Conditon checks to perfom any addtional operations apart from
                    triggering KsrRobin in the CmpActive of the Message Core
                    Observer
Invocation       : WarnMsg_Core_Observer
Parameters       : Boolean *AddlChkSts
                          - Poniter to varibale, Holds status to trigger additional 
                            operation
Return Value     : None
Critical Section : None
*****************************************************************************/
void MsgCoreExtnAddlActiveChk (MSG_VIEWINFO_T *Data, boolean *AddlChkSts)
{
    uint8 fl_AddlChkRetVal_u8;

    /*Initialization*/
    fl_AddlChkRetVal_u8 = NO_INIT_REQUESTED;
    *AddlChkSts = WRN_FALSE;

    fl_AddlChkRetVal_u8 = CheckInitCall(Data);
    /*Toyota Specfic Check*/
    if (WARM_INIT_REQUESTED == fl_AddlChkRetVal_u8)
    {
        *AddlChkSts = WRN_TRUE;
    }
}
/****************************************************************************
Function Name     : MsgCoreExtnAddlAction
Description       : Perfom any addtional operations apart from
                    triggering KsrRobin in the CmpActive of the Message Core
                    Observer
Invocation        : WarnMsg_Core_Observer
Parameters        : None
Return Value      : None
Critical Section  : None
 ******************************************************************************/
void MsgCoreExtnAddlAction(void)
{
   
    /*Add Program Specific Logic*/

}
/****************************************************************************
Function Name     : CheckShowConditions
Description       : Function used to check the program specfic conditions of Show.
Invocation        : WarnMsg_Core_Observer
Parameters        : None
Return Value      : Condition Status
Critical Section  : None
 ******************************************************************************/
void CheckShowConditions(boolean *RetVal)
{
    SWarningDisplay fl_warning_data_S;
    uint8 fl_FactoryModeSts_u8;

    /*Initialization*/
    MemLib_MemSet(&fl_warning_data_S, 0U, sizeof(SWarningDisplay));
    fl_FactoryModeSts_u8 = FACTORYMODE_DISABLED;
    *RetVal =  WRN_TRUE;
    
    /*RTE Read*/
    (void)Rte_Read_rp_FactoryMode_FactoryMode(&fl_FactoryModeSts_u8);

    if(FACTORYMODE_DISABLED != fl_FactoryModeSts_u8)
    {
        *RetVal = WRN_FALSE;
    }

}
/****************************************************************************
Function Name     : CheckHideConditions
Description       : Function used to check the program specfic conditions of Show.
Invocation        : WarnMsg_Core_Observer
Parameters        : None
Return Value      : Condition Status
Critical Section  : None
 ******************************************************************************/
void CheckHideConditions(boolean *RetVal)
{
    /*Initialization*/
    *RetVal =  WRN_TRUE;

/*Add Program Specific Logic*/
}
/****************************************************************************
Function Name     : CheckEventHiddenConditions
Description       : Function used to check the program specfic conditions of Hidden.
Invocation        : WarnMsg_Core_Observer
Parameters        : None
Return Value      : Condition Status
Critical Section  : None
 ******************************************************************************/
void CheckEventHiddenConditions ( boolean *RetVal )
{
    /*Initialization*/
    *RetVal =  WRN_TRUE;

/*Add Program Specific Logic*/
}
/****************************************************************************
Function Name     : CheckEventShowConditions
Description       : Function used to check the program specfic conditions of Show.
Invocation        : WarnMsg_Core_Observer
Parameters        : None
Return Value      : Condition Status
Critical Section  : None
 ******************************************************************************/
void CheckEventShowConditions (boolean *RetVal)
{
    /*Initialization*/
    *RetVal =  WRN_TRUE;

    /*Add Program Specific Logic*/
}	
/****************************************************************************
Function Name     : CheckEventTimeoutConditions
Description       : Function used to check the program specfic conditions of Timeout.
Invocation        : WarnMsg_Core_Observer
Parameters        : None
Return Value      : Condition Status
Critical Section  : None
 ******************************************************************************/
void CheckEventTimeoutConditions(boolean *RetVal)
{
    /*Initialization*/
    *RetVal =  WRN_TRUE;

/*Add Program Specific Logic*/
}
/****************************************************************************
Function Name     : CheckEventAckConditions
Description       : Function used to check the program specfic conditions of 
                    Acknowledged.
Invocation        : WarnMsg_Core_Observer
Parameters        : None
Return Value      : Condition Status
Critical Section  : None
 ******************************************************************************/
void CheckEventAckConditions(boolean *RetVal)
{
    /*Initialization*/
    *RetVal =  WRN_TRUE;

/*Add Program Specific Logic*/
}
/****************************************************************************
Function Name     : CheckEventInactiveConditions
Description       : Function used to check the program specfic conditions of 
                    Inactive state.
Invocation        : WarnMsg_Core_Observer
Parameters        : Qualifier - Warning Id
Return Value      : Condition Status
Critical Section  : None
******************************************************************************/
void CheckEventInactiveConditions(WarningId Qualifier, boolean *RetVal)
{
    /*Initialization*/
    *RetVal =  WRN_TRUE;

    /*Program Specific Logic*/
    /*To be uncommented once the configurations are enabled for the below warnings*/
    /* 
    if((Qualifier == WRN_NORM_GPF_MEV01_04) || ( Qualifier == WRN_NORM_VCOPE_03)||( Qualifier == WRN_NORM_SMASTA_52)||( Qualifier == WRN_NORM_SMASTA_53))  
    {
        *RetVal = FALSE;            
    }
    else
    {
        *RetVal = TRUE;
    }
    */
}

 
/*****************************************************************************
Function Name    : CheckPreUclTrigCdn
Description      : Capabilty to have any conditions before sending the warning data
                    to UCL
Invocation       : WarnMsg_Core_Observer
Parameters       : Boolean *Data
                          - Poniter to varibale, Holds Pre UCL condition status
Return Value     : None
Critical Section : None
*****************************************************************************/
void CheckPreUclTrigCdn( boolean *RetVal)
{
    
    *RetVal = WRN_TRUE;
    
}
/*****************************************************************************
Function Name    : UpdateWarnStsToUCL
Description      : Used share warning status to HMI via UCL interface
Invocation       : WarnMsg_Core_Observer
Parameters       : SWarningDisplay *UclDataTx
                          - Poniter to varibale, has the warning data to be 
                          sent to HMI via UCL
Return Value     : None
Critical Section : None
*****************************************************************************/
void UpdateWarnStsToUCL(SWarningDisplay *UclDataTx, uint8 WarnInst, uint8 MsgType)
{
    ExtWarningData fl_WarnSts_S;
    SHudWarningDisplay fl_HudData_S;
    uint8 fl_NvmHnOnOffData_u8;

    /*Initialization*/
    fl_NvmHnOnOffData_u8 = 0U;
    MemLib_MemSet(&fl_HudData_S, 0, sizeof(SHudWarningDisplay));
    MemLib_MemSet(&fl_WarnSts_S, 0, sizeof(ExtWarningData));

    /*Read NvmData*/
    //(void)Rte_Call_rp_NVM_HMOnOff_NVM_Adapter_GetNVM_HM_ONOFF(&fl_NvmHnOnOffData_u8);
    /*Update the InterruptType to Screen Navi Modules*/
    (void)UpdInterruptData(UclDataTx->warningId, WarnInst, fl_NvmHnOnOffData_u8);   
    /*Assign Received UCL data to HUD DataType if both instances/HUD instance invokes UCL*/
    if(DEFAULT_INSTANCE == WarnInst)
    {
        /*Check if the warning is NEW or Redisplay*/
        if (EXTN_DISABLE_WARN != UclDataTx->show) 
        {
            UclDataTx->show = DetUclMsgSts(UclDataTx->warningId, MsgType);
        }
        /*METER related interfaces*/
        (void)Rte_Write_pp_WarningDisplay_WarningDisplayData(UclDataTx);
        //(void)Rte_Write_pp_WarnIntDispTyp_WarnInterrupt_DispType(UclDataTx->show);
        (void)Rte_Call_rpActiveWarningStatus_GetActiveWarningStatus(WRN_CUSTMIZE_PERSET_24,&fl_WarnSts_S);
        if(UI_WARNING_STATUS_OFF == fl_WarnSts_S.ExtWarningCurrentStatus)
        {
            l_CustLockFlag_bool = WRN_FALSE;
        }
    }
    else
    {
        if (0U != fl_NvmHnOnOffData_u8)
        {
            fl_HudData_S.show = UclDataTx->show;
            fl_HudData_S.warningId = UclDataTx->warningId;
            MemLib_MemCpy((uint8*)&fl_HudData_S.dynData[0],(uint8*)&UclDataTx->dynData[0], sizeof(data_u8_8));
        }
        /*Enusure existing displayed warnings are removed on NVM transition to OFF*/
        (void)Rte_Write_pp_HUDWarningDisplay_HudWarningDisplayData(&fl_HudData_S);
    }
    /*Invoke the funtion to send the ONS UCL Data*/
    UpdateONSUCLData();
}
/*****************************************************************************
Function Name    : UpdateWarnDataToUCL
Description      : Used to get the Robin trigger condition status
Invocation       : WarnMsg_Core_Observer
Parameters       : WarningDisplay *Data
                          - Poniter to varibale, Holds RobinTrigger status
Return Value     : None
Critical Section : None
*****************************************************************************/
void UpdateWarnDataToUCL( eMessageIdentity *DispWarnId, uint16 WarningCount, uint8 WarnInst)
{
    /*Declaration*/
    SStoreWarnData  fl_StoreWarnUclData;
    SMessageTabStatusData fl_HmiMessageTab_S;
    SStoreWarnCountdata fl_StoreWarnCount_u16;
    WarningId fl_StoredWarningId_A[CFGD_STORE_WARNINGS];
    uint8 fl_UclRxdData_u8;
    uint8 fl_HmiInterruptSts_u8;
    boolean fl_PayloadChange_bool;
    
    /*Initialization*/
    fl_PayloadChange_bool = WRN_FALSE;
    fl_HmiInterruptSts_u8 = SCREEN_BLANK;
    fl_StoreWarnCount_u16.storeWarnCount = DEFAULT_STORE_COUNT;
    /*memset is used as MemLib_MemSet supports only data of uint8*/
    (void)memset(&fl_StoredWarningId_A[0],TotalNumOfWarnings,sizeof(fl_StoredWarningId_A));

    /*Copying the Active Store Warning List from Core_Observer*/
    MemLib_MemCpy((uint16*)&fl_StoredWarningId_A[0],(uint16*)DispWarnId,sizeof(fl_StoredWarningId_A));
    /*Read Message Tab event from HMI*/
    //(void)Rte_Read_rSR_MessageTabStatusData_MessageTabStatusDataData(&fl_HmiMessageTab_S);
    /*RTE_E_OK is checked to ensure the event is rightly received*/
    fl_UclRxdData_u8 = fl_HmiMessageTab_S.messageTabActvData;
    FUTILITY_UNUSED_VAR(fl_UclRxdData_u8);
    //(void)Rte_Write_pp_WarnMsgTabSts_MessageTab_Status(fl_UclRxdData_u8);
    //(void)Rte_Read_rp_HmiIntTyp_HmiInterruptSts(&fl_HmiInterruptSts_u8);
    /*Chech if the invoked instance is the DEFAULT Instance as HUD does not have stored Warnings*/
    if(DEFAULT_INSTANCE == WarnInst)
    {
        /*Handle the Store Warning Count - Change in count and count is not 0U*/
        if((l_ActiveStoreCnt_u8 != WarningCount) && (DEFAULT_STORE_COUNT != WarningCount)) 
        {
            /*Check if the is no queue pending to be transmitted to HMI*/
            if(WRN_FALSE == l_StoreLockFlag_bool)
            {
                /*Transmit the count value to HMI*/
                l_ActiveStoreCnt_u8 = WarningCount;
                fl_StoreWarnCount_u16.storeWarnCount = l_ActiveStoreCnt_u8;
                //(void)Rte_Write_pSR_StoreWarnCountdata_StoreWarnCountdataData(&fl_StoreWarnCount_u16);        
                /*Lock the Data Tx for the 1st time*/
                l_StoreLockFlag_bool = WRN_TRUE;
            }  
        }
        /*Check if there are no active store warnings - Second check is to ensure data is not continously sent*/
        else if (((DEFAULT_STORE_COUNT == WarningCount) && (DEFAULT_STORE_COUNT != l_ActiveStoreCnt_u8)))
        {
            /*Reset the Active Store Count and release the Tx Lock*/
            l_ActiveStoreCnt_u8 = DEFAULT_STORE_COUNT;
            fl_StoreWarnCount_u16.storeWarnCount = l_ActiveStoreCnt_u8;
            l_StoreLockFlag_bool = WRN_FALSE;
            l_NextStartIdx_u8 = DEFAULT_STORE_COUNT;
            /*Update the data the UCL*/
            for(uint8 fl_InitIdx_u8 = DEFAULT_STORE_COUNT; fl_InitIdx_u8 < STORE_WRN_QUEUE_SIZE; fl_InitIdx_u8++)
            {
                fl_StoreWarnUclData.sstoreWarnData[fl_InitIdx_u8].storewarnid = TotalNumOfWarnings;
                fl_StoreWarnUclData.sstoreWarnData[fl_InitIdx_u8].order = STORE_INVLD_ORDER;
                MemLib_MemCpy((uint8*)&fl_StoreWarnUclData.sstoreWarnData[fl_InitIdx_u8].dynData,(uint8*)l_PayloadInitVal,sizeof(l_PayloadInitVal));
            }
            //(void)Rte_Write_pSR_StoreWarnCountdata_StoreWarnCountdataData(&fl_StoreWarnCount_u16);
            //(void)Rte_Send_pSR_StoreWarnData_StoreWarnDataData(&fl_StoreWarnUclData);
        }
        else
        {
            /*do nothing*/
        }
        /*Check of "Message Tab" active and Lock being released*/
        if((MSG_TAB_ACTIVE == fl_HmiInterruptSts_u8) && (WRN_FALSE == l_StoreLockFlag_bool))
        {
            /*Check for change in payload of the currently active stored warnings*/
            fl_PayloadChange_bool = CheckPayloadChange(fl_StoredWarningId_A);
        }
        /*Function is invoked when the Full UCL Tx is not complete, change in payload */
        if((WRN_FALSE != l_StoreLockFlag_bool) || (WRN_FALSE != fl_PayloadChange_bool))
        {
            StoreDataTx(fl_StoredWarningId_A);
        }
    }
    else
    {
        /*Do Nothing*/
    }
}
/*****************************************************************************
Function Name    : WarningSendChimeInfo
Description      : This function handles meter lcd interrupt chime 
Invocation       : WarnMsg_Core_Observer_Impl_Mainfunction
Parameters       : None
Return Value     : None
Critical Section : None
*****************************************************************************/
void WarningSendChimeInfo(uint8 SeqStatus)
{
  
    SWarningStatus fl_msg_info_S;
    uint16 fl_MsgIdentifier_u16;
    uint8 fl_chime_status_u8;
    uint8 fl_msg_chime_u8;

    /*Initialization*/
    fl_chime_status_u8 = eChimeStat_Idle;
    fl_msg_chime_u8 = MSG_CHIME_INACTIVE;
    fl_MsgIdentifier_u16 = 0U;

    /* Get Current Msg Information from HMI that is received via UCL*/
    (void)Rte_Read_rp_WarningStatus_WarningStatusData ( &fl_msg_info_S );

    /* chime should not come if there is no warning */
    if(fl_msg_info_S.warningId < TotalNumOfWarnings)
    {
        /*The function - DetMessageId is a temporary funtion and will be removed once the number of Messages and the total number of warnings are same*/
        fl_MsgIdentifier_u16 = DetMessageId(fl_msg_info_S.warningId);
        fl_msg_chime_u8 = msg_associated_chimes_list[fl_MsgIdentifier_u16];
        /*Reverse Map the wrning id */
        if( fl_msg_info_S.warningId != l_PrevWarnId_u16)
        {
            //Rte_Call_rpCS_GetChimeStatus_SndCtrl_CheckChimeStatus(warn_chimes_array[fl_MsgIdentifier_u16],&fl_chime_status_u8);
            if (eChimeStat_Completed == fl_chime_status_u8)
            {
                l_MasterChime_u8 = (uint8)ChimeRelease;
            }
            /*This check is to ensure the chime is triggered only once for a warning that has an associated chime i.e. Chime should be played only once 
            when warning appears as a NEW warning. That is the purpose of TESTBIT. The bit will be set for the 1st time when the chime is played and cleared
            only on the Warning is OFF*/            
            else if ((MSG_CHIME_ACTIVE == fl_msg_chime_u8) && (TESTBIT(SeqStatus, MSG_NEW)))
            {
                l_MasterChime_u8 = (uint8)ChimeRequest;
                l_PrevWarnId_u16 = fl_msg_info_S.warningId;
                l_TriggrdChime_u8 = warn_chimes_array[fl_MsgIdentifier_u16];
            }
            else
            {
                l_PrevWarnId_u16 = fl_msg_info_S.warningId;
            }
            //(void)Rte_Call_rpCS_ChimeRequest_Chime_Request(warn_chimes_array[fl_MsgIdentifier_u16], l_MasterChime_u8,eSnd_InterruptType_Tone);
            
        }
        else
        {
            if((uint8)ChimeRequest == l_MasterChime_u8)
            {
                //Rte_Call_rpCS_GetChimeStatus_SndCtrl_CheckChimeStatus(warn_chimes_array[fl_MsgIdentifier_u16],&fl_chime_status_u8);
                if (eChimeStat_Completed == fl_chime_status_u8)
                {
                    l_MasterChime_u8 = (UINT8)ChimeRelease;
                    //Rte_Call_rpCS_ChimeRequest_Chime_Request(warn_chimes_array[fl_MsgIdentifier_u16], l_MasterChime_u8,eSnd_InterruptType_Tone);
                    l_TriggrdChime_u8 = eSnd_NoChimeID;
                }
                else
                {
                    /*Do Nothing*/
                }
            }
            else
            {
            }
        }
    }
    else
    {
        /*Before chime release if warning removed from queue then chime will be released*/
        if((uint8)ChimeRelease != l_MasterChime_u8)
        {
            l_MasterChime_u8 = (uint8)ChimeRelease;
            //Rte_Call_rpCS_ChimeRequest_Chime_Request(l_TriggrdChime_u8, l_MasterChime_u8,eSnd_InterruptType_Tone);
            l_TriggrdChime_u8 = eSnd_NoChimeID;
        }

        l_PrevWarnId_u16 = TotalNumOfWarnings;
    }
}
/*****************************************************************************
Function Name    : DetMessageId
Description      : This function determines the message ID from the warning id 
Invocation       : WarnMsg_Core_Observer_Extn
Parameters       : RxdWarnId
Return Value     : fl_MsgId_u16
Critical Section : None
*****************************************************************************/
uint16 DetMessageId (uint16 RxdWarnId)
{
    uint16 fl_MsgId_u16;
    /*Initialization*/
    fl_MsgId_u16 = (uint16)0U;

    for (uint16 fl_IterVar_u16 = 0; fl_IterVar_u16 < (uint16)miMaximum; fl_IterVar_u16++)
    {
        if (RxdWarnId == messageList[fl_IterVar_u16].ConditionQualifier)
        {
            /*Map the MessageID that is associated with the displayed warning*/
            fl_MsgId_u16 = fl_IterVar_u16;
            break;
        }
    }
    return(fl_MsgId_u16);

}
/*****************************************************************************
Function Name    : SendWarnStsInTask
Description      : This function instructs whether to send the Warning data to 
                    UCL in CmpActive of WarnMsg_Core_Observer
Invocation       : WarnMsg_Core_Observer_Impl_Mainfunction
Parameters       : None
Return Value     : None
Critical Section : None
*****************************************************************************/
void SendWarnStsInTask ( boolean *RetVal)
{
    /*Initialization*/
    /*Set to TRUE to transmit the UCL even in CmpActive to incorporate the change in
    payload of the displayed warning.*/
    *RetVal = WRN_TRUE;
}

/*****************************************************************************
Function Name    : UpdPreAckCdns
Description      : This function performs the actions before the acknowledgement 
                    handling by the message core is triggered.
Invocation       : OnDre_UCL_WarnStatus
Parameters       : None
Return Value     : None
Critical Section : None
*****************************************************************************/
void UpdPreAckCdns ( uint16 SeqMsgId, uint8 WarnInst, EButtonSts* ButtonEvent, boolean* RetVal)
{
    /*Declaration*/
    SWarningStatus fl_CurWarnSts;
    uint16 fl_SequencerWarnId_u16;
    uint8 fl_SendDispPayload_A[8];
    uint8 fl_RcvedBtnExtrct_u8;
    boolean fl_RxdButtonId_bool;
    
    /*Initialzation*/
    MemLib_MemSet(&fl_CurWarnSts, 0U, sizeof(SWarningStatus));
    MemLib_MemSet(&fl_SendDispPayload_A, 0U, sizeof(Arr_u8_8));
    fl_SequencerWarnId_u16 = TotalNumOfWarnings;
    fl_RxdButtonId_bool = WRN_FALSE;
    fl_RcvedBtnExtrct_u8 = EButtonIDs_None;
    *ButtonEvent = EButtonSts_Off;
    *RetVal = WRN_FALSE;

    (void)Rte_Read_rp_WarningStatus_WarningStatusData(&fl_CurWarnSts);
    fl_SequencerWarnId_u16 = messageList[SeqMsgId].ConditionQualifier;
    /*Check if BACK button is pressed*/
    fl_RcvedBtnExtrct_u8 = l_RxdBtnToBitwiseConv[((fl_CurWarnSts.dynData[RXD_BUTTON_DATA]) >> BTN_EXTRACT)];
    fl_RxdButtonId_bool = TESTBIT(fl_RcvedBtnExtrct_u8,BIT1);

    if ((WARNING_NOT_DISPLAYED != fl_CurWarnSts.visible) && (TotalNumOfWarnings > fl_CurWarnSts.warningId))
    {
        for (uint8 fl_IterVal_u8 = 0; fl_IterVal_u8 < PAYLOAD_SIZE; fl_IterVal_u8 ++)
        {
            fl_SendDispPayload_A[fl_IterVal_u8] = fl_CurWarnSts.dynData[fl_IterVal_u8];
        }
        (void)Rte_Call_rp_UpdateDisplayPayload_SetWarningDisplayedPayload(fl_CurWarnSts.warningId, &fl_SendDispPayload_A[0]); 

        if ((fl_CurWarnSts.warningId == fl_SequencerWarnId_u16) && (WRN_FALSE != fl_RxdButtonId_bool))
        {
            if(EButtonSts_Long == (fl_CurWarnSts.dynData[RXD_BUTTON_DATA] & EButtonSts_Long))
            {
                *ButtonEvent = EButtonSts_Long;
            }
            else if (EButtonSts_Short == (fl_CurWarnSts.dynData[RXD_BUTTON_DATA] & EButtonSts_Short))
            {
                *ButtonEvent = EButtonSts_Short;
            }
            else
            {
                /*Do Nothing*/
            }
            *RetVal = WRN_TRUE; 		
        }
        (void)UpdateWarnCanTx();
    }
}

/*****************************************************************************
Function Name    : UpdPostAckCdns
Description      : This function performs the actions post the acknowledgement 
                    handling by the message core is triggered.
Invocation       : OnDre_UCL_WarnStatus
Parameters       : None
Return Value     : None
Critical Section : None
*****************************************************************************/
void UpdPostAckCdns (uint8 WarnInst)
{
    /*Do Nothing*/
}
/*****************************************************************************
Function Name    : UpdInterruptData
Description      : This function send the warning interrupt data to Screen Navi Modules.
Invocation       : UpdateWarnStsToUCL
Parameters       : None
Return Value     : None
Critical Section : None
*****************************************************************************/
void UpdInterruptData (WarningId UclWarnId,uint8 WarnInst,uint8 HudNvmData)
{
    /*Declaration*/
    SWarningStatus fl_CurWarnSts;
    uint16 fl_MsgIdentifier_u16;
    uint8 fl_FactoryModeSts_u8;
    uint8 fl_WarnIntCat_u8;

    /*Initialzation*/
    MemLib_MemSet(&fl_CurWarnSts, 0U, sizeof(SWarningStatus));
    fl_FactoryModeSts_u8 = FACTORYMODE_DISABLED;
    fl_MsgIdentifier_u16 = TotalNumOfWarnings;
    fl_WarnIntCat_u8 = WARN_INT_NONE;

    /*RTE Read*/
    (void)Rte_Read_rp_FactoryMode_FactoryMode(&fl_FactoryModeSts_u8);
    if (DEFAULT_INSTANCE == WarnInst)
    {
        /*If Fatory Mode is enabled, no interrupts are updated*/
        if (FACTORYMODE_ENABLED == fl_FactoryModeSts_u8)
        {
            (void)Rte_Write_pp_WarnInt_WarningInterrupt_State(FACTORY_INT);
            //(void)Rte_Write_pp_WarnIntId_WarningInterrupt_Identifier(TotalNumOfWarnings);
        }
        /*If Fatory Mode is disabled, the interrupts are updated based on the warning displayed*/
        else if(TotalNumOfWarnings > UclWarnId)
        {
            /*Message Id is detected only for Displayed warnings*/ 
            fl_MsgIdentifier_u16 = DetMessageId(UclWarnId);
            fl_WarnIntCat_u8 = UpdateWarnInt(fl_MsgIdentifier_u16);
            (void)Rte_Write_pp_WarnInt_WarningInterrupt_State(fl_WarnIntCat_u8);
            //(void)Rte_Write_pp_WarnIntId_WarningInterrupt_Identifier(UclWarnId);
        }
        else
        {
            /*Factory Mode is disabled -> screen will be blank and no warning will be displayed*/
            (void)Rte_Write_pp_WarnInt_WarningInterrupt_State(WARN_INT_NONE);
            //(void)Rte_Write_pp_WarnIntId_WarningInterrupt_Identifier(TotalNumOfWarnings);
        }
    }
    else
    {     
        /*Message Id is detected only for HUD Displayed warnings*/ 
        if((TotalNumOfWarnings > UclWarnId) && (0U != HudNvmData))
        {
            fl_MsgIdentifier_u16 = DetMessageId(UclWarnId);
            fl_WarnIntCat_u8 = UpdateWarnInt(fl_MsgIdentifier_u16);
            //(void)Rte_Write_pp_WarnIntHud_HUDWarningInterrupt_State(fl_WarnIntCat_u8);
            //(void)Rte_Write_pp_WarnIntIdHud_HUDWarningInterrupt_Identifier(UclWarnId);
        }
        else
        {
            //(void)Rte_Write_pp_WarnIntHud_HUDWarningInterrupt_State(WARN_INT_NONE);
            //(void)Rte_Write_pp_WarnIntIdHud_HUDWarningInterrupt_Identifier(TotalNumOfWarnings);
        }
    }
    FUTILITY_UNUSED_VAR(fl_WarnIntCat_u8);
}
/*****************************************************************************
Function Name    : UpdateWarnInt
Description      : This function performs the actions post the acknowledgement 
                    handling by the message core is triggered.
Invocation       : OnDre_UCL_WarnStatus
Parameters       : None
Return Value     : None
Critical Section : None
*****************************************************************************/
uint8 UpdateWarnInt (WarningId RxdWarnId)
{
    uint8 fl_WarnIntRetVal_u8;

    fl_WarnIntRetVal_u8 = l_WarnIntCfgdType[RxdWarnId];
  
    return(fl_WarnIntRetVal_u8);
}
/*****************************************************************************
Function Name    : TriggerSWNoOperTmrChk
Description      : Check the conditions to initialize the message core (Warm/Cold init)
                   based on the requirements
Invocation       : WarnMsg_Core_Observer
Parameters       : EButtonId pEvent, EButtonSts pEventType
Return Value     : None
Critical Section : None
*****************************************************************************/
boolean TriggerSWNoOperTmrChk (EButtonId pEvent, EButtonSts pEventType )
{
    /*Implements Req: TFDCX32348-29490 based on (2) of TFDCX32348-29231*/
    boolean fl_TrigTmr_bool;
    /*Initialization*/
    fl_TrigTmr_bool = WRN_FALSE;
    
    if((EButtonIDs_Enter == pEvent) || (EButtonIDs_Back == pEvent))
    {
        fl_TrigTmr_bool = WRN_TRUE;
    }
    return(fl_TrigTmr_bool);
}
/*****************************************************************************
Function Name    : UpdateWarnCanTx
Description      : This function performs the actions post the acknowledgement 
                    handling by the message core is triggered.
Invocation       : OnDre_UCL_WarnStatus
Parameters       : None
Return Value     : None
Critical Section : None
*****************************************************************************/
void UpdateWarnCanTx (void)
{
    /*Declaration*/
    SWarningStatus fl_CurWarnSts_S;
    uint16 fl_WarnIdx_u16;
    
    /*Initialzation*/
    MemLib_MemSet(&fl_CurWarnSts_S, 0U, sizeof(SWarningStatus));
    fl_WarnIdx_u16 = WARN_CANTX_CFGD;

    (void)Rte_Read_rp_WarningStatus_WarningStatusData(&fl_CurWarnSts_S);
    /*Extract the Button Data Alone*/
    /*Ensure Displayed warning ID is lesser than the configured CanTx ID*/
    fl_WarnIdx_u16 = CheckCanTxAppl(fl_CurWarnSts_S.warningId);
    
    /*Check if the warning is configured for CAN Transmission*/
    if(WARN_CANTX_CFGD > fl_WarnIdx_u16)
    {
        /*Check if the Received button matches the configured button*/
        if(NULL != l_WarnTxList_A[fl_WarnIdx_u16].ApplFnPtr)
        {
            l_WarnTxList_A[fl_WarnIdx_u16].ApplFnPtr(fl_CurWarnSts_S.warningId, fl_CurWarnSts_S.dynData[RXD_BUTTON_DATA] , fl_CurWarnSts_S.dynData[RXD_CURSOR_DATA]);
        }
    }
    /*Displayed Wanring Id exceed the warnings configured for CanOut*/
    else
    {
        /*Do Nothing*/
    }
}
/****************************************************************************
Function Name     : OnDre_UCL_WarnStatus
Description       : To process the message acknowledgement
Invocation        : UCL adpted
Parameters        : None
Return Value      : None
Critical Section  : None
 ******************************************************************************/
FUNC(void, WarnMsg_Core_Observer_CODE) OnDre_UCL_WarnStatus(void)
{
    (void)OnDre_UCL_MultiZone_WarnStatus(DEFAULT_INSTANCE);
}

/****************************************************************************
Function Name     : OnDre_UCL_HudWarnStatus
Description       : To process the message acknowledgement
Invocation        : UCL adpted
Parameters        : None
Return Value      : None
Critical Section  : None
 ******************************************************************************/
FUNC(void, WarnMsg_Core_Observer_CODE) OnDre_UCL_HudWarnStatus(void)
{
   (void)OnDre_UCL_MultiZone_WarnStatus(HUD_INSTANCE);
}
/*****************************************************************************
Function Name    : CheckCanTxAppl
Description      : This function determines if CANTx is applicable for displayed Warning 
Invocation       : WarnMsg_Core_Observer_Extn
Parameters       : RxdWarnId
Return Value     : fl_WarnIdx_u16
Critical Section : None
*****************************************************************************/
uint16 CheckCanTxAppl (uint16 RxdWarnId)
{
    uint16 fl_WarnIdx_u16;
    /*Initialization*/
    fl_WarnIdx_u16 = (uint16)WARN_CANTX_CFGD;

    for (uint16 fl_IterVar_u16 = 0; fl_IterVar_u16 < WARN_CANTX_CFGD; fl_IterVar_u16++)
    {
        if (RxdWarnId == l_WarnTxList_A[fl_IterVar_u16].Qualifier)
        {
            /*Map the MessageID that is associated with the displayed warning*/
            fl_WarnIdx_u16 = fl_IterVar_u16;
            break;
        }
    }
    return(fl_WarnIdx_u16);
}
/*****************************************************************************
** Function Name    : WarnMsg_Core_Observer_Store_Warning_Check
** Visibility       : 
** Description      : This function is used to return store warning status.
** Invocation       : CmpActive
** Return Value     : boolean
** Critical Section : None
***************************************************************************/
boolean StoreWarnConfigChk(eMessageIdentity p_message_id)
{
    boolean fl_store_status_bool = WRN_FALSE ;
    
    if(p_message_id < MSG_NUM_MESSAGES)
    {
        if(TESTBIT(l_StoreWarnArray[p_message_id],BIT0))
        {
            fl_store_status_bool = WRN_TRUE ;
        }
        else
        {
            fl_store_status_bool = WRN_FALSE ;
        }
    }
    
return(fl_store_status_bool);

}
/*****************************************************************************
** Function Name    : TriggerAlert
** Visibility       : 
** Description      : Dummy function to support the Core Observer.
** Invocation       : CmpActive
** Return Value     : void
** Critical Section : None
***************************************************************************/
void TriggerAlert (uint8 WarnSts,uint8 Inst)
{

    /*Do Nothing*/
}
/*****************************************************************************
** Function Name    : StoreDataTx
** Visibility       : 
** Description      : Dummy function to support the Core Observer.
** Invocation       : CmpActive
** Return Value     : void
** Critical Section : None
***************************************************************************/
void StoreDataTx (WarningId *DispWarnId)
{
    ExtWarningData fl_warning_info_S;
    SStoreWarnData  fl_StoreWarnUclData;
    WarningId fl_StoredWarningId_A[CFGD_STORE_WARNINGS];
    uint16 fl_CurrStoreWarnId_u16;

    /*Initialization*/
    MemLib_MemSet(&fl_warning_info_S, 0U, sizeof(ExtWarningData));
    fl_CurrStoreWarnId_u16 = TotalNumOfWarnings;
    for(uint8 fl_InitIdx =0U; fl_InitIdx < STORE_WRN_QUEUE_SIZE; fl_InitIdx++)
    {
        fl_StoreWarnUclData.sstoreWarnData[fl_InitIdx].storewarnid = TotalNumOfWarnings;
        fl_StoreWarnUclData.sstoreWarnData[fl_InitIdx].order = STORE_INVLD_ORDER;
        MemLib_MemCpy((uint8*)&fl_StoreWarnUclData.sstoreWarnData[fl_InitIdx].dynData,(uint8*)l_PayloadInitVal,sizeof(data_u8_8));
    }

    /*Get the Store Waring List*/
    MemLib_MemCpy((uint16*)&fl_StoredWarningId_A[0],(uint16*)DispWarnId,sizeof(fl_StoredWarningId_A));
    
   /*Check if the active Store Warnings are greater than the queue size and the previous Tx is complete*/
    if((STORE_WRN_QUEUE_SIZE < l_ActiveStoreCnt_u8) && (WRN_FALSE != l_StoreLockFlag_bool))
    {
        for(uint8 fl_StoreLoopVar_u8 = DEFAULT_STORE_COUNT; fl_StoreLoopVar_u8 < STORE_WRN_QUEUE_SIZE; fl_StoreLoopVar_u8++)
        {
            /*To ensure the invalid data in the same queue is correctly set - Used in the removal of warnings*/
            if((l_NextStartIdx_u8 + fl_StoreLoopVar_u8) < l_ActiveStoreCnt_u8)
            {
                /*Detect the warning Id from the message id*/
                fl_CurrStoreWarnId_u16 = messageList[fl_StoredWarningId_A[(l_NextStartIdx_u8 + fl_StoreLoopVar_u8)]].ConditionQualifier;
                /*Update the data compatible to the UCL structure*/
                fl_StoreWarnUclData.sstoreWarnData[fl_StoreLoopVar_u8].storewarnid = fl_CurrStoreWarnId_u16;
                fl_StoreWarnUclData.sstoreWarnData[fl_StoreLoopVar_u8].order  = fl_StoreLoopVar_u8 + l_NextStartIdx_u8;
                /* Check for the Payload applicability of Configured StoreWarning*/ 
                if(WRN_PAYLOAD == l_StoreWarnArray[fl_StoredWarningId_A[l_NextStartIdx_u8 + fl_StoreLoopVar_u8]])
                {
                    /*If Payload is applicable, read it from the Ctrl_warning*/
                    Rte_Call_rpActiveWarningStatus_GetActiveWarningStatus(fl_CurrStoreWarnId_u16, &fl_warning_info_S);
                    MemLib_MemCpy((uint8*)&fl_StoreWarnUclData.sstoreWarnData[fl_StoreLoopVar_u8].dynData[0],(uint8*)&fl_warning_info_S.ExtWarningCurrentPayload[0], sizeof(data_u8_8));
                    /*Copy the Payload to Static Variable to check for change in payload*/
                    MemLib_MemCpy((uint8*)&l_ActvStorePayload_A[fl_StoreLoopVar_u8][0],(uint8*)&fl_warning_info_S.ExtWarningCurrentPayload[0], sizeof(data_u8_8));
                }
            }
            /*No else is required as Payload is assigned with 0U in the initialization itself*/
        }
        /*Increment the start index for the next set of UCL data*/
        l_NextStartIdx_u8 = l_NextStartIdx_u8 + STORE_WRN_QUEUE_SIZE;
        
        if (l_NextStartIdx_u8 < l_ActiveStoreCnt_u8)
        {/*Continue the Queue udpates*/
            l_StoreLockFlag_bool = WRN_TRUE;             
        }
        else
        {
            /*Release the queue for next Tx*/
            l_StoreLockFlag_bool = WRN_FALSE;
            /*Reset the Queue Update index*/
            l_NextStartIdx_u8 = DEFAULT_STORE_COUNT;
        }       
    }
    else
    {
        for(uint8 fl_StoreLoopVar_u8 = 0U; fl_StoreLoopVar_u8 < STORE_WRN_QUEUE_SIZE; fl_StoreLoopVar_u8++)
        {
            /*To ensure the invalid data in the same queue is correctly set - Used in the removal of warnings*/
            if(fl_StoreLoopVar_u8 < l_ActiveStoreCnt_u8)
            {
                fl_CurrStoreWarnId_u16 = messageList[fl_StoredWarningId_A[fl_StoreLoopVar_u8]].ConditionQualifier;
                fl_StoreWarnUclData.sstoreWarnData[fl_StoreLoopVar_u8].storewarnid = fl_CurrStoreWarnId_u16;
                fl_StoreWarnUclData.sstoreWarnData[fl_StoreLoopVar_u8].order  = fl_StoreLoopVar_u8;
                /* Check for the Payload applicability of Configured StoreWarning*/ 
                if(WRN_PAYLOAD == l_StoreWarnArray[fl_StoredWarningId_A[fl_StoreLoopVar_u8]])
                {
                    Rte_Call_rpActiveWarningStatus_GetActiveWarningStatus(fl_CurrStoreWarnId_u16, &fl_warning_info_S);
                    MemLib_MemCpy((uint8*)&fl_StoreWarnUclData.sstoreWarnData[fl_StoreLoopVar_u8].dynData[0],(uint8*)&fl_warning_info_S.ExtWarningCurrentPayload[0], sizeof(data_u8_8));
                    /*Copy the Payload to Static Variable*/
                    MemLib_MemCpy((uint8*)&l_ActvStorePayload_A[fl_StoreLoopVar_u8][0],(uint8*)&fl_warning_info_S.ExtWarningCurrentPayload[0], sizeof(data_u8_8));
                }
                /*No else is required as Payload is assigned with 0U in the initialization itself*/
            }
        }
        /*Reset the Queue Update index*/
        l_NextStartIdx_u8 = DEFAULT_STORE_COUNT;
        /*Release the queue for next Tx*/
        l_StoreLockFlag_bool = WRN_FALSE;
    }
    //(void)Rte_Send_pSR_StoreWarnData_StoreWarnDataData(&fl_StoreWarnUclData);
}
/*****************************************************************************
** Function Name    : CheckPayloadChange
** Visibility       : 
** Description      : Dummy function to support the Core Observer.
** Invocation       : CmpActive
** Return Value     : void
** Critical Section : None
***************************************************************************/
boolean CheckPayloadChange (WarningId *DispWarnId)
{
    uint16 fl_CurrStoreWarnId_u16;
    boolean fl_CmpResult_bool;
    ExtWarningData fl_warning_info_S;
    

    /*Initialization*/
    MemLib_MemSet(&fl_warning_info_S, 0U, sizeof(ExtWarningData)); 
    fl_CmpResult_bool = WRN_FALSE;
    
    for(uint8 fl_StoreLoopVar_u8 = 0U; fl_StoreLoopVar_u8 < l_ActiveStoreCnt_u8; fl_StoreLoopVar_u8++)
    {
        if(WRN_PAYLOAD == l_StoreWarnArray[DispWarnId[fl_StoreLoopVar_u8]])
        {
            fl_CurrStoreWarnId_u16 = messageList[DispWarnId[l_NextStartIdx_u8]].ConditionQualifier;
            Rte_Call_rpActiveWarningStatus_GetActiveWarningStatus(fl_CurrStoreWarnId_u16, &fl_warning_info_S);
            /*Check if the payload of the existing active store warning is changed*/
            fl_CmpResult_bool = MemLib_MemCmp((uint8*)&l_ActvStorePayload_A[fl_StoreLoopVar_u8][0],(uint8*)&fl_warning_info_S.ExtWarningCurrentPayload[0], sizeof(data_u8_8));
            if(WRN_FALSE != fl_CmpResult_bool)
            {
                break;
            }
        }
    }
    
    return(fl_CmpResult_bool);
}
/*****************************************************************************
** Function Name    : UpdateONSUCLData
** Visibility       : 
** Description      : Dummy function to support the Core Observer.
** Invocation       : CmpActive
** Return Value     : void
** Critical Section : None
***************************************************************************/
void UpdateONSUCLData (void)
{
   SWarnOnsData fl_UclOnsData;
   uint8 fl_Adas2OnsData_u8;
   uint8 fl_StoStaOnsData_u8;
   uint8 fl_Adas1OnsData_u8;
   uint8 fl_HmiReadySts_u8;

   /*Initialization*/
   fl_Adas2OnsData_u8 = WRN_FALSE;
   fl_StoStaOnsData_u8 = WRN_FALSE;
   fl_Adas1OnsData_u8 = WRN_FALSE;
   fl_HmiReadySts_u8 = eHMI_NOT_READY;

   //(void)Rte_Read_rp_RccOnsSts_RadarCCONS_Data(&fl_Adas2OnsData_u8);
   //(void)Rte_Read_rp_StoStaOnsUclSts_StoStaOns_Data(&fl_StoStaOnsData_u8);
   (void)Rte_Read_rp_HMIReadySts_HMI_ReadyStatus(&fl_HmiReadySts_u8);
   //(void)Rte_Read_rp_EcoRunModeOns_Sts_EcoRunONS_Data(&fl_Adas1OnsData_u8);

   /*Assign RCC ONS Data*/
   fl_UclOnsData.warnOnsData[0] = fl_Adas2OnsData_u8;
   /*Assign ERM ONS Data*/
   fl_UclOnsData.warnOnsData[1] = fl_Adas1OnsData_u8;
   /*Assign Stop Start ONS Data*/
   fl_UclOnsData.warnOnsData[2] = fl_StoStaOnsData_u8;
   /*Transmit UCL data only when HMI is ready*/ 
   if(eHMI_READY == fl_HmiReadySts_u8)
   {    
        //(void)Rte_Write_pSR_WarnOnsData_WarnOnsDataData(&fl_UclOnsData);
   }

}
/*****************************************************************************
Function Name    : DetUclMsgSts
Description      : This function determines the message status from the warning id 
Invocation       : WarnMsg_Core_Observer_Extn
Parameters       : RxdWarnId, MsgType
Return Value     : fl_ShowTyp_u8
Critical Section : None
*****************************************************************************/
uint8 DetUclMsgSts (uint16 RxdWarnId, uint8 MsgType)
{
    SWarningStatus fl_CurWarnSts;
    uint8 fl_ShowTyp_u8;
    /*Initialization*/
    fl_ShowTyp_u8 = EXTN_NEWDISP;
    MemLib_MemSet(&fl_CurWarnSts, 0U, sizeof(SWarningStatus));

    (void)Rte_Read_rp_WarningStatus_WarningStatusData(&fl_CurWarnSts); 
    if(WRN_CUSTMIZE_PERSET_24 == RxdWarnId)
    {
        if(fl_CurWarnSts.warningId == RxdWarnId)
        {
            fl_ShowTyp_u8 = EXTN_REDISP;
            l_CustLockFlag_bool = WRN_TRUE;
        }
        else if (WRN_FALSE != l_CustLockFlag_bool)
        {
            fl_ShowTyp_u8 = EXTN_REDISP;
        }
        else
        {
            fl_ShowTyp_u8 = EXTN_NEWDISP;
        }
    }
  
    else
    {
        if((TESTBIT(MsgType, MSG_NEW)))
        {
            fl_ShowTyp_u8  = EXTN_NEWDISP;
        }
        else
        {
            fl_ShowTyp_u8  = EXTN_REDISP;
        }
    }
    return(fl_ShowTyp_u8);

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
Date              : 03-09-2024
CDSID             : vrk
Traceability      : TFDCX32348-38611
Change Description: 1. Added ProgramInitRequest, SendWarnStsInTask functions.
                    2. Logic is added for the function - MsgCoreExtnAddlActiveChk
                    3. The logic in function - CheckEventInactiveConditions is commented
                    as the warnings are not configured for the 1st Milestone of Toyota
                    4. UCL RTE is mapped to UpdateWarnStsToUCL
                    5. Added the function - WarningSendChimeInfo, that is responsible
                    for triggering the chime associated with a warning
 ******************************************************************************/
/****************************************************************************
Date              : 19-09-2024
CDSID             : vrk
Traceability      : 
Change Description: 1. Added CheckAckRecd, UpdPreAckCdns, UpdPostAckCdns, UpdateWarnInt functions.
                    2. Logic is updated for CheckInitCall based on Req: TFDCX32348-28191
                    3. The logic related to l_UnlockWarnFlag_bool is commented as the warnings
                    relating to it is not added for arbitration.
                    as the warnings are not configured for the 1st Milestone of Toyota
 ******************************************************************************/
/****************************************************************************
Date              : 27-09-2024
CDSID             : vrk
Traceability      : TFDCX32348-38818
Change Description: 1. Removed MSG_VIEW_INFO from CheckShowConditions as it is MsgCore_Obsever is updated.
                    2. Removed the function  CheckAckRecd as the logic is handled in UpdPreAckCdns
                    3. RTE mappings of the functions - CheckInitCall, WarningSendChimeInfo, UpdPreAckCdns, 
                    UpdPostAckCdns, UpdateWarnInt
 ******************************************************************************/
/****************************************************************************
Date              : 15-10-2024
CDSID             : vrk
Traceability      : 
Change Description: Updated Payload determination logic to map LSB of received payload to the 1st array element.
 ******************************************************************************/
/****************************************************************************
Date              : 17-10-2024
CDSID             : vrk
Traceability      : TFDCX32348-49205
Change Description: Updated HIGH_INT output to support WRN_DOOR_UNLMOD_02.
 ******************************************************************************/
/****************************************************************************
Date              : 08-11-2024
CDSID             : vrk
Traceability      : TFDCX32348-55364
Change Description: Update the Acknowledgement Button Event and Status logic.
 ******************************************************************************/
/****************************************************************************
Date              : 19-11-2024
CDSID             : vrk
Traceability      : DICMBD-395
Change Description: Update to support the latest Ctrl_warning. 
 ******************************************************************************/
/****************************************************************************
Date              : 21-11-2024
CDSID             : vrk
Traceability      : TFDCX32348-57369
Change Description: 1. Updated the logic in CheckMsgCoreTrig, UpdPostAckCdns, CheckShowConditions
                       to support HMIReady and Factory.
                    2. Removed UpdateReceivedPayload Payload is handled in Ctrl_warning
                    3. Added the function - TriggerSWNoOperTmrChk to support redisplay
 ******************************************************************************/ 
/****************************************************************************
Date              : 02-12-2024
CDSID             : vrk
Traceability      : 
Change Description: 1. Added the functions - UpdateWarnCanTx and CanTxReset to support 
                        CANTx of displayed warnings.
                    2. Invoked CanTxReset from CheckMsgCoreTrig to continuosly monitor
                    the TargetSW.
 ******************************************************************************/
/****************************************************************************
Date              : 09-12-2024
CDSID             : vrk
Traceability      : 
Change Description: 1. Updated UpdateWarnCanTx to support the Maximim warings configured
                    2. Updated CanTxReset to support the correct TargetSW from Button_Mdl.
 ******************************************************************************/
/****************************************************************************
Date              : 12-12-2024
CDSID             : vrk
Traceability      : TFDCX32348-61097
Change Description: Updated UpdateWarnStsToUCL to support the Multi-instance UCL updates
 ******************************************************************************/
/****************************************************************************
Date              : 23-01-2025
CDSID             : vrk
Traceability      : TFDCX32348-65161
Change Description: 1. Updated the based on the defect - TFDCX32348-61750 to fix the button mapping. 
                    2. Observation of Master Caution buzzer playing continuosly observation.
 ******************************************************************************/
/****************************************************************************
Date              : 18-03-2025
CDSID             : vrk
Traceability      : TFDCX32348-76051
Change Description: 'Retval' of the funtion - SendWarnStsInTask is set to TRUE. This is done to enable
                    the transmission of UCL message to support the payload change in the displayed warning
                    against the original transmission of UCL message only during show/hide.                     
 ******************************************************************************/
/****************************************************************************
Date              : 26-03-2025
CDSID             : vrk
Traceability      : TFDCX32348-77441
Change Description: Updated the logic for WarningInterrupt_State and added the logic for
                    WarningInterrupt_Identifier                    
 ******************************************************************************/
/****************************************************************************
Date              : 31-03-2025
CDSID             : vrk
Traceability      : TFDCX32348-78378
Change Description: Moved the interrupt update logic. Data to be sent before transmitting to UCL,
                    as the Arbitrations is one of the paramaters to decide the Screen to be displayed in the
                    CScreenInfoMdl.
 ******************************************************************************/
/****************************************************************************
Date              : 04-04-2025
CDSID             : vrk
Traceability      : TFDCX32348-78290
Change Description: Updated the logic for SettingsInterrupt_State, SettingsInterrupt_Identifier
                    and added the logic for WarnInterrupt_DispType 
 ******************************************************************************/
/****************************************************************************
Date              : 08-04-2025
CDSID             : vrk
Traceability      : TFDCX32348-79548
Change Description: Updated the logic with respect to FACTORY MODE in UpdInterruptData.
 ******************************************************************************/
/****************************************************************************
Date              : 15-04-2025
CDSID             : vrk
Traceability      : TFDCX32348-80313
Change Description: 1. Updated to support PROSRV_INT. 
                    2. All interrupts are sent via a single interface based on the
                    internal design decision.
                    3. Update the Button Data Argument for TMR_APPL CanTx.
 ******************************************************************************/
/****************************************************************************
Date              : 21-04-2025
CDSID             : vrk
Traceability      : TFDCX32348-81752
Change Description: 1. Updated to support latest version of WarnMsg_Core_Observer v2.2.1
                    2. Updated the function - UpdateWarnCanTx to meet the latest Structure defenition
                    3. Removed the function - UpdWarnInterruptType as the status is got from Observer.
                    4. Added the funtion - OnDre_UCL_HudWarnStatus - the feedback of HUD.
                    5. Removed the variable - l_TriggeredWarnSts_A as it is not needed at all.
 ******************************************************************************/
/****************************************************************************
Date              : 05-05-2025
CDSID             : vrk
Traceability      : TFDCX32348-83400
Change Description: 1. Updated to UpdInterruptData to support HUD Warning Interrupt Type
                    2. Updated the function - UpdateWarnCanTx to meet the latest Structure defenition
                    and memory optimization
                    3. Added the function - CheckCanTxAppl to support UpdateWarnCanTx
                    4. Added the new interfaces in ProgramInitRequest.
 ******************************************************************************/
/****************************************************************************
Date              : 09-05-2025
CDSID             : vrk
Traceability      : TFDCX32348-79700
Change Description: Updated to fix the priority defect - TFDCX32348-62711
 ******************************************************************************/
 /****************************************************************************
Date              : 17-05-2025
CDSID             : vrk
Traceability      : TFDCX32348-85452
Change Description: 1. Updated the function - UpdateWarnCanTx
                    2. Removed the funtion - CanTxReset.
 ******************************************************************************/
 /****************************************************************************
Date              : 26-05-2025
CDSID             : vrk
Traceability      : TFDCX32348-86429
Change Description: Added the functions - TriggerAlert, StoreWarnConfigChk
 ******************************************************************************/
 /****************************************************************************
Date              : 29-05-2025
CDSID             : vrk
Traceability      : TFDCX32348-86595
Change Description: Updated to support store Warnings
 ******************************************************************************/
  /****************************************************************************
Date              : 02-06-2025
CDSID             : vrk
Traceability      : TFDCX32348-86595
Change Description: Added the RTE write for message tab to share the data to Screen Navi
 ******************************************************************************/
  /****************************************************************************
Date              : 26-06-2025
CDSID             : vrk
Traceability      : TFDCX32348-81093
Change Description: Updated for Factory Mode and ONS UCL
 ******************************************************************************/
  /****************************************************************************
Date              : 07-07-2025
CDSID             : vrk
Traceability      : TFDCX32348-96747
Change Description: Updated to fix the CUSTOMIZE defect. Only WRN_CUSTMIZE_PERSET_24 is handled specially
 ******************************************************************************/
/*End of Revision History*/


