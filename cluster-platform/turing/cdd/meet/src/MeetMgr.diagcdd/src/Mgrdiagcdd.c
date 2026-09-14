/*=================================================================================================================
**
**                     CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2001. Visteon Corporation owns all rights to this work and
** intends to maintain it in confidence to preserve its trade secret status.
** Visteon Corporation reserves the right, under the copyright laws of the
** United States or those of any other country that may have jurisdiction,
** to protect this work as an unpublished work, in the event of an
** inadvertent or deliberate unauthorized publication. Visteon Corporation
** also reserves its rights under all copyright laws to protect this work as
** a published work, when appropriate. Those having access to this work may
** not copy it, use it, modify it or disclose the information contained in
** it without the written authorization of Visteon Corporation.
**
**==================================================================================================================
**
** Name:           Mgrdiagcdd
**
** Description:
**
**
**===================================================================================================================*/

#ifndef MGRDIAGCDD_C
#define MGRDIAGCDD_C

/*====================================================================================================================
**                 I N C L U D E   F I L E S
**===================================================================================================================*/
#include "Std_Types.h"
#include "Mgrdiagcdd_cfg.h"
#include "Mgrdiagcdd.h"
#include "Memdiagcdd.h"
#include "Ioctrlrd_analog_diagcdd.h"
#include "Rte_Type.h"
#include "CmpLib.h"

#ifdef DISPLAY_MODULE_ENABLE
#include "Displaycontroldiagcdd.h"
#include "Displaycontroldiagcdd_cfg.h"
#endif

#ifdef NOR_CHECKSUM_ENABLE
#include "Memdiagcdd_cfg.h"
#endif

#ifdef RESETDIAG_MODULE_ENABLE
#include "Resetsleepdiagcdd.h"
#include "Resetsleepdiagcdd_cfg.h"
#endif

#ifdef IOCTRLRD_PMIC_CONFIGURATION_CHECK
#include "Ioctrlrd_dio_diagcdd_cfg.h"
#endif

#ifdef MOTORDIAG_SERVICE
#include "Motordiagcdd.h"
#endif

#ifdef SHAREDIAG_MODULE_ENABLE
#include "SharedBootDiagcdd.h"
#include "SharedBootDiagcdd_cfg.h"
#endif

#ifdef CYBERSECDIAG_MODULE_ENABLE
#include "Cybersecdiagcdd.h"
#endif

#ifdef COMDIAG_MODULE_ENABLE
#include "Commdiagcdd.h"
#endif

/*====================================================================================================================
**   I N T E R N A L   M A C R O   D E F I N I T I O N S
**===================================================================================================================*/

/*=====================================================================================================================
**  T Y P E    D E C L A R A T I O N S
**====================================================================================================================*/
/*Meet Diag Function Pointer*/
typedef Std_ReturnType (*diagFunctionPtr)(uint8 *Data, uint8 *Length);

typedef struct
{
    uint32 l_did_number;
    diagFunctionPtr Meet_Diag_Func;
} MGRDIAGCDD_DID_bundle_t;

/*=====================================================================================================================
**  C O N S T A N T    A N D   V A R I A B L E S    D E C L A R A T I O N S
**====================================================================================================================*/
/*DID list definition*/
MGRDIAGCDD_READ_DID_LIST
MGRDIAGCDD_WRITE_DID_LIST
MGRDIAGCDD_IOCTL_STA_DID_LIST
#ifdef MGRDIAGCDD_IOCTL_FCS_DID_LIST
MGRDIAGCDD_IOCTL_FCS_DID_LIST
#endif
MGRDIAGCDD_IOCTL_RCTE_DID_LIST
MGRDIAGCDD_RC_START_DID_LIST
MGRDIAGCDD_RC_STOP_DID_LIST
MGRDIAGCDD_RC_RESULTS_DID_LIST

/*=====================================================================================================================
**  PRIVATE
**====================================================================================================================*/
/*Functions for processing the different types of DIDs*/
static Std_ReturnType Mgrdiag_Read_DID(uint8 *Data, uint8 *Length, const uint32 *DID);
static Std_ReturnType Mgrdiag_Write_DID(uint8 *Data, uint8 *Length, const uint32 *DID);
static Std_ReturnType Mgrdiag_Ioc_Sta_DID(uint8 *Data, uint8 *Length, const uint32 *DID);
#ifdef MGRDIAGCDD_IOCTL_FCS_DID_LIST
static Std_ReturnType Mgrdiag_Ioc_Fcs_DID(uint8 *Data, uint8 *Length, uint32 *DID);
#endif
static Std_ReturnType Mgrdiag_Ioc_Rcte_DID(uint8 *Data, uint8 *Length, const uint32 *DID);
static Std_ReturnType Mgrdiag_Roc_Start_DID(uint8 *Data, uint8 *Length, const uint32 *DID);
static Std_ReturnType Mgrdiag_Roc_Stop_DID(uint8 *Data, uint8 *Length, const uint32 *DID);
static Std_ReturnType Mgrdiag_Roc_Results_DID(uint8 *Data, uint8 *Length, const uint32 *DID);

#ifdef MGRDIAGCDD_BINARY_SEARCH
static Std_ReturnType Mgrdiagcdd_Service_Identification_Exec(const MGRDIAGCDD_DID_bundle_t DID_list[], uint8 *Data, uint8 *Length, const uint32 *DID, uint8 Max_service_count);
#endif

#if (BCDMANIPUTATION_ENABLE_ANALOG_DIAG > 0) || (BCDMANIPUTATION_ENABLE_DIMMING_CTRL > 0)
static uint8 bcd2dec(uint8 bcd);
#endif

CMPLIB_INSTANCE(MeetCdd)

/*=====================================================================================================================
**
** Function Name    :  Transitional activation state
**
** Visibility       :  Public/private
**
** Description      :
**
**
** Invocation       :
**
** Inputs           :
**
** Outputs          :  E_OK - Succeed
**
** Critical Section : No
**
**====================================================================================================================*/

static Std_ReturnType CmpActivation(void)
{
	#if defined(IOCONTOLRD_PULSE_INPUT_CH1) || defined (IOCONTOLRD_PULSE_INPUT_CH2)
	(void)PWM_pulse_channels_initialization();
	#endif		
    return E_OK;
}

/*=====================================================================================================================
**
** Function Name    :  CmpDeActivation
**
** Visibility       :  Public/private
**
** Description      :  Transitional de-activation state
**
**
** Invocation       :
**
** Inputs           :
**
** Outputs          :  E_OK: Succeed
**
** Critical Section : No
**
**====================================================================================================================*/

static Std_ReturnType CmpDeActivation(void)
{
    return E_OK;
}

/*=====================================================================================================================
**
** Function Name    :  CmpDiag
**
** Visibility       :  Public/private
**
** Description      : Diagnostic state
**
**
** Invocation       :
**
** Inputs           :
**
** Outputs          :  E_OK : Diagnostic has completed. Go to DiagReturn state.
**
**
** Critical Section : No
**
**====================================================================================================================*/

static Std_ReturnType CmpDiag(void)
{
    return E_OK;
}

/*=====================================================================================================================
**
** Function Name    :  CmpDiagReturn
**
** Visibility       :  Public/private
**
** Description      : Transitional state to clean up after diagnostic state. Component behaviour to be restored.
**
**
** Invocation       :
**
** Inputs           :
**
** Outputs          :  E_OK : Diagnostic clean-up has completed. Return to the previous state (Active or Inactive).
**                     E_NOT_READY : Keeps the component in this state.
**
** Critical Section : No
**
**====================================================================================================================*/

static Std_ReturnType CmpDiagReturn(void)
{
    return E_OK;
}
/*=====================================================================================================================
**
** Function Name    :  CmpDeInit
**
** Visibility       :  Public/private
**
** Description      : Transitional de-initialization state
**
**
** Invocation       :
**
** Inputs           :
**
** Outputs          :  E_OK : Succeed / E_NOT_READY : In progress. Keeps the component in this state / E_NOT_OK: Failed
**
**
** Critical Section : No
**
**====================================================================================================================*/

static Std_ReturnType CmpDeInit(void)
{
    return E_OK;
}
#ifdef MGRDIAGCDD_WAKEUP_REQUIRED
/*=====================================================================================================================
**
** Function Name    :  CmpWakeUp
**
** Visibility       :  Public/private
**
** Description      :  Transitional wakeup state
**
**
** Invocation       :
**
** Inputs           :
**
** Outputs          :  E_OK : Success
**
** Critical Section : No
**
**====================================================================================================================*/

static Std_ReturnType CmpWakeUp(void)
{
    return E_OK;
}
#endif
/*=====================================================================================================================
**
** Function Name    :  CmpInit
**
** Visibility       :  Public/private
**
** Description      :  Transitional initialization state
**
**
** Invocation       :
**
** Inputs           :
**
** Outputs          :  E_OK : Succeed / E_NOT_READY : In progress. Keeps the component in this state / E_NOT_OK: Failed
**
** Critical Section : No
**
**====================================================================================================================*/

static Std_ReturnType CmpInit(void)
{
    #ifdef RSTCNTRREADINGENABLE
    #ifdef SET_RST_CNT_ENABLE
    Set_Rst_Cnt();
    #endif
    #endif

    MGRDIAGCDD_AAPPL_SPEC_INIT();

    #ifdef IOCONTOLRD_ADC_READ_SAFE_ENABLE
    Ioctrlrd_analog_diag_IoHwSafe_ADC_Init();
    #endif

    #ifdef SHAREDIAG_MODULE_ENABLE
    ShareDiag_PreInit();
    ShareDiag_Init();
    #endif

    #ifdef CRYPTO_KEY_MANAGEMENT
    #ifdef CYBERSECDIAG_FLS_ENABLE
    Cybersecdiag_Fls_Init();
    #endif
    #endif

    #ifdef RESETDIAG_MODULE_ENABLE
    #ifdef LOWQCURRENTENABLE
    ResetSleepdiag_Init();
    #endif
    #endif

    return E_OK;
}

/*=====================================================================================================================
**
** Function Name    :  CmpActive
**
** Visibility       :  Public/private
**
** Description      :  State for normal operations
**
**
** Invocation       :
**
** Inputs           :
**
** Outputs          :  E_OK
**
** Critical Section : Yes/No
**
**====================================================================================================================*/

static Std_ReturnType CmpActive(void)
{

    #ifdef IOCONTOLRD_ADC_READ_SAFE_ENABLE
    Ioctrlrd_analog_diag_IoHwSafe_ADC_Perioc_Task();
    #endif

    #ifdef SLEEPMODEENABLE
    Manuf_Sleep_Task();
    #endif

    #ifdef IOCTRLRD_ANALOG_DIAG
    Manuf_ANA_AnalogValue_Update();
    #endif

    #if defined(SWRSTENABLE) || defined(WDRSTENABLE)
    ResetDiag_Periodic();
    #endif

    #ifdef MEMWRITETESTENABLE
    MemDiag_Main_Task();
    #endif

    #if defined(NVMVALIDITYCHKENABLE) || defined(MEMDIAG_MEMORY_VALIDITY_CHECK)
    MemDiag_NVMReadAllBlocks();
    #endif

    #ifdef NVMACCESSBYBLOCKIDRCENABLE
    MemDiag_NVMReadbyBlockIDStatus();
    #endif

    #ifdef CONTINOUS_POINTER_MOVEMENT
    Stpr_Periodic_Function();
    #endif

    #ifdef SHAREDIAG_MODULE_ENABLE
    MeetCdd_process();
    #endif

    #ifdef AUTO_CONFIGURE_OR_VERIFY
    MemDiag_NVMConfigureorVerify();
    #endif

    #ifdef PROGRAM_NVM_FROM_ROM
    MemDiag_Restoring_NVM_defaultValues();
    #endif

    #ifdef CRYPTO_KEY_MANAGEMENT
    #ifdef CYBERSECDIAG_FLS_ENABLE
    Cybersecdiag_Fls_MainFunction();
    #endif

    #ifdef CYBERSECDIAG_BACKUPBANK_VERIFICATION_ONLY_CMAC
    Cybersecdiag_backUpbankVerification();
    CybersecDiag_AES_Key_Verification_Process();
    #endif
    #endif

    #ifdef IOCTRLRD_PMIC_CONFIGURATION_CHECK
    PMIC_Read_Regs();
    #endif

    #ifdef COMM_BUS_VERIFICATION_TEST
    Comm_Bus_Periodic_Function();
    #endif

    #ifdef NOR_CHECKSUM_ENABLE
    NOR_CHECKSUM_CALCULATION();
    #endif

    #ifdef MFGMODEREQENABLE
    MemDiag_Manuf_Flag_Write_Status();
    #endif

    #ifdef DISPLAYCONTROLDIAG_I2CTEST_ROUTINE
    Displaycontroldiag_I2CTest_Task(); // This function is from cfg file
    #endif

    #ifdef DISPLAY_TOUCH_TEST_CHECK
    Displaycontroldiag_TouchTest_Task();
    #endif

    #ifdef DISPLAYCONTROLDIAG_TSW_I2CREAD_ROUTINE
    Displaycontroldiag_TswI2CRead_Task(); // This function is from cfg file
    #endif

    #ifdef CYBERSECDIAG_JTAG_PASSWORD_ROUTINE_LOCK_ENABLE
    Cybersecdiag_JtagPswdLockRoutine_Task();
    #endif

    #ifdef CYBERSECDIAG_SECURE_KEY_PROGRAMMING_SHE
    Cybersecdiag_She_MainFunction();
    #endif

    APP_SPEC_10MS_TIMER_USAGE();

    #ifdef READ_INTERFACE_FOR_APPL_COMPONENTS
    /*Read interface for application components*/
    if (IsUpdateCompletedForThisInit == E_NOT_OK)
    {
        Meet_Mgrdiagcdd_Update_GIP_DID_Data(&IsUpdateCompletedForThisInit);
    }
    #endif

    return E_OK;
}

/*=====================================================================================================================
**
** Function Name    :  Meet_Mgrdiagcdd_Action
**
** Visibility       :  Public
**
** Description      :
**
**
** Invocation       :
**
** Inputs           :  Action,Data, Length, DID
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/
FUNC(Std_ReturnType, CMeetCdd_CODE) CMeetCdd_Meet_Mgrdiagcdd_Action(P2VAR(EDcmExtAction, AUTOMATIC, RTE_MEETCDD_APPL_VAR) Action, P2VAR(UInt8, AUTOMATIC, RTE_MEETCDD_APPL_VAR) Data, P2VAR(UInt8, AUTOMATIC, RTE_MEETCDD_APPL_VAR) Length, P2VAR(UInt32, AUTOMATIC, RTE_MEETCDD_APPL_VAR) DID)
{
    #ifdef READ_INTERFACE_FOR_APPL_COMPONENTS
    boolean IsGIPDID = FALSE;
    #endif

    Std_ReturnType Ret = E_NOT_OK;

    if (Action[0] == MGRDIAGCDD_READ_ACTION)
    {
        #ifdef READ_INTERFACE_FOR_APPL_COMPONENTS

        IsGIPDID = IsGIPReadDID(DID);
        if (FALSE != IsGIPDID)
        {
            if (E_OK == IsUpdateCompletedForThisInit)
            {
                /* Startup GIP partNumber read is complete.
                   Function routing to Read DID Table*/
                Ret = Mgrdiag_Read_DID(Data, Length, DID);
            }
            else
            {
                /*startup GIP part number read is in progress. Wait till it completes.*/
                Ret = DCM_E_PENDING;
            }
        }
        else
        {
            /*VIP read DIDs can be read immediately on request*/
            Ret = Mgrdiag_Read_DID(Data, Length, DID);
        }
        #else
        /* Function routing to Read DID Table*/
        Ret = Mgrdiag_Read_DID(Data, Length, DID);
        #endif
    }
    else if (Action[0] == MGRDIAGCDD_WRITE_ACTION)
    {
        /* Function routing to Write DID Table*/
        Ret = Mgrdiag_Write_DID(Data, Length, DID);
    }
    else if (Action[0] == MGRDIAGCDD_IOC_STA_ACTION)
    {
        /* Function routing to IoCtrl STA DID Table*/
        Ret = Mgrdiag_Ioc_Sta_DID(Data, Length, DID);
    }
    #if defined(MGRDIAGCDD_IOC_FCS_ACTION) && defined(MGRDIAGCDD_IOCTL_FCS_DID_LIST)
    else if (Action[0] == MGRDIAGCDD_IOC_FCS_ACTION)
    {
        /* Function routing to IoCtrl FCS DID Table*/
        Ret = Mgrdiag_Ioc_Fcs_DID(Data, Length, DID);
    }
    #endif
    else if (Action[0] == MGRDIAGCDD_IOC_RCTE_ACTION)
    {
        /* Function routing to IoCtrl RCTE DID Table*/
        Ret = Mgrdiag_Ioc_Rcte_DID(Data, Length, DID);
    }
    else if (Action[0] == MGRDIAGCDD_ROC_START_ACTION)
    {
        /* Function routing to Routine Start DID Table*/
        Ret = Mgrdiag_Roc_Start_DID(Data, Length, DID);
    }
    else if (Action[0] == MGRDIAGCDD_ROC_STOP_ACTION)
    {
        /* Function routing to Routine Stop DID Table*/
        Ret = Mgrdiag_Roc_Stop_DID(Data, Length, DID);
    }
    else if (Action[0] == MGRDIAGCDD_ROC_RESULTS_ACTION)
    {
        /* Function routing to Routine Stop DID Table*/
        Ret = Mgrdiag_Roc_Results_DID(Data, Length, DID);
    }
    else
    {
        /* Do Nothing*/
    }

    return Ret;
}
#ifdef READ_INTERFACE_FOR_APPL_COMPONENTS
/*=====================================================================================================================
**
** Function Name    :  CMeetCdd_Mgrdiagcdd_ReadAction
**
** Visibility       :  Public/Private
**
** Description      :
**
**
** Invocation       :
**
** Inputs           :  DIDNum, Data
**
** Outputs          :  E_OK/E_NOT_OK/
**
** Critical Section : No
**
**====================================================================================================================*/

FUNC(Std_ReturnType, CMeetCdd_CODE) CMeetCdd_Mgrdiagcdd_ReadAction(P2VAR(UInt8, AUTOMATIC, RTE_CMEETCDD_APPL_VAR) Data, P2VAR(UInt32, AUTOMATIC, RTE_CMEETCDD_APPL_VAR) DID)
{
    Std_ReturnType Ret = E_NOT_OK;
    uint8 Length[2] = {0, 0};
    boolean IsGIPDID = FALSE;

    IsGIPDID = IsGIPReadDID(DID);
    if (FALSE != IsGIPDID)
    {
        /*For GIP DIDs, read from localbuffer stored*/
        Ret = Meet_Mgrdiagcdd_Get_GIP_DID_Data(Data, DID);
    }
    else
    {
        /* For VIP DID, function routing to Read DID Table*/
        Ret = Mgrdiag_Read_DID(Data, Length, DID);
    }

    return Ret;
}

FUNC(Std_ReturnType, CMeetCdd_CODE) CMeet_Mgrdiagcdd_Update_GIP_DID_Data(P2VAR(UInt8, AUTOMATIC, RTE_MEETCDD_APPL_VAR) Data, P2VAR(UInt32, AUTOMATIC, RTE_MEETCDD_APPL_VAR) DID)
{

    Std_ReturnType Ret = E_NOT_OK;
    uint8 Length[2] = {0, 0};

    Ret = Mgrdiag_Read_DID(Data, Length, DID);

    return Ret;
}

#endif

#ifdef SEPERATE_DCMEXT_INTERFACE_FOR_DID_RID
/*=====================================================================================================================
**
** Function Name    :  DID_DiagAction
**
** Visibility       :  Public/Private
**
** Description      :
**
**
** Invocation       :
**
** Inputs           :  OpStatus,DIDNum, Data, pNrc, eOperation
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/
FUNC(Std_ReturnType, CMeetCdd_CODE) CMeetCdd_DID_DiagAction(teDiagOpStatus OpStatus, UInt16 DIDNum, P2VAR(UInt8, AUTOMATIC, RTE_CMEETCDD_APPL_VAR) Data, P2VAR(UInt8, AUTOMATIC, RTE_CMEETCDD_APPL_VAR) pNrc, teDIDOperation eOperation)
{
    Std_ReturnType Ret = E_NOT_OK;
    uint8 Length[2] = {0, 0};
    boolean fl_bRtn = (boolean)TRUE;
    EDcmExtAction Action = 0U;
    uint32 DID_ID[1];
    ((void)(OpStatus));

    Ret = Mgrdiagcdd_MapDID_DcmExtAction(&Action, eOperation);
    if ((uint8)E_NOT_OK == Ret)
    {
        fl_bRtn = FALSE; /*to prevent from further actions*/
        *pNrc = DCM_E_CONDITIONSNOTCORRECT;
    }
    else
    {
        #ifdef PRECONDITION_CHECK_REQUIRED
        if (MGRDIAGCDD_READ_ACTION != Action)
        {
            fl_bRtn = Mgrdiagcdd_DID_PreConditionCheck(DIDNum, pNrc); /*Nrc will be updated here, if returns NOT OK*/
        }
        else
        {
            /* Read operation does not check any conditions as the eCheckConditions call out is executed before by DCM */
        }
        #endif
    }
    DID_ID[0] = (uint32)DIDNum;
    if (FALSE != fl_bRtn)
    {
        if (MGRDIAGCDD_CHECKCONDITIONS_ACTION != Action)
        {
            Ret = CMeetCdd_Meet_Mgrdiagcdd_Action(&Action, Data, Length, &DID_ID[0]);
            /*assign Nrc arg */
            if ((uint8)E_NOT_OK == Ret)
            {
                *pNrc = Data[0];
            }
        }
    }
    else
    {
        Ret = E_NOT_OK;
    }
    return Ret;
}
/*=====================================================================================================================
**
** Function Name    :  RID_DiagAction
**
** Visibility       :  Public/Private
**
** Description      :
**
**
** Invocation       :
**
** Inputs           :  OpStatus,RIDNum, Out_RoutineInfo, Data, DataLength, pNrc, eOperation
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/
FUNC(Std_ReturnType, CMeetCdd_CODE) CMeetCdd_RID_DiagAction(teDiagOpStatus OpStatus, UInt16 RIDNum, P2VAR(UInt8, AUTOMATIC, RTE_CMEETCDD_APPL_VAR) Out_RoutineInfo, P2VAR(UInt8, AUTOMATIC, RTE_CMEETCDD_APPL_VAR) Data, P2VAR(uint16, AUTOMATIC, RTE_CMEETCDD_APPL_VAR) DataLength, P2VAR(UInt8, AUTOMATIC, RTE_CMEETCDD_APPL_VAR) pNrc, teRoutineOperation eOperation)
{
    Std_ReturnType Ret = E_NOT_OK;
    boolean fl_bRtn = (boolean)TRUE;
    EDcmExtAction Action = 0U;
    uint32 RID[1];
    ((void)(OpStatus));
    uint16 index = DATA_BYTE_0;
    uint16 len_u8[2];
    uint8 pdata_len_u8[2] = {0U};

    Ret = Mgrdiagcdd_MapRID_DcmExtAction(&Action, eOperation);
    if ((uint8)E_NOT_OK == Ret)
    {
        fl_bRtn = FALSE; /*to prevent from further actions*/
        *pNrc = DCM_E_CONDITIONSNOTCORRECT;
    }
    else
    {
        #ifdef PRECONDITION_CHECK_REQUIRED
        fl_bRtn = Mgrdiagcdd_RID_PreConditionCheck(RIDNum, pNrc); /*Nrc will be updated here, if returns NOT OK*/
        #endif
    }
    RID[0] = (uint32)RIDNum;
    if (FALSE != fl_bRtn)
    {
        Ret = CMeetCdd_Meet_Mgrdiagcdd_Action(&Action, Data, pdata_len_u8, RID);

        if ((uint8)E_NOT_OK == Ret)
        {
            *pNrc = Data[0];
        }
        else
        {
            len_u8[0] = (uint16)pdata_len_u8[0];
            len_u8[1] = (uint16)pdata_len_u8[1];

            DataLength[0] = ((uint16)((len_u8[0] & 0x00FFU) << 8U) | len_u8[1]);

            for (index = 0; index < DataLength[0]; index++)
            {
                Out_RoutineInfo[index] = Data[index];
            }
        }
    }
    else
    {
        Ret = E_NOT_OK;
    }
    return Ret;
}
#endif

#ifdef CMEETCDD_APPL_STUBS
FUNC(Std_ReturnType, RTE_CMEETCDD_DIAGNOSTICS_APPL_CODE) CMeetCdd_Diagnostics_DID_DiagAction(teDiagOpStatus OpStatus, UInt16 DIDNum, P2VAR(UInt8, AUTOMATIC, RTE_CMEETCDD_DIAGNOSTICS_APPL_VAR) Data, P2VAR(UInt8, AUTOMATIC, RTE_CMEETCDD_DIAGNOSTICS_APPL_VAR) pNrc, teDIDOperation eOperation)
{
    Std_ReturnType ret = E_NOT_OK;
    ret = CMeetCdd_DID_DiagAction(OpStatus, DIDNum, Data, pNrc, eOperation);
    return ret;
}
void CMeetCdd_Diagnostics_MainFunction(void)
{
}
#endif

#if !defined(MGRDIAGCDD_BINARY_SEARCH)
/*=====================================================================================================================
**
** Function Name    :  Mgrdiag_Read_DID
**
** Visibility       :  private
**
** Description      : This function is used to call the Read DID function in the table.
**
**
** Invocation       :  Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,length,DID.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/
static Std_ReturnType Mgrdiag_Read_DID(uint8 *Data, uint8 *Length, const uint32 *DID)
{

    Std_ReturnType Ret = E_NOT_OK;
    static uint8 fl_loop_count_U8;

    for (fl_loop_count_U8 = 0; fl_loop_count_U8 < MGRDIAGCDD_READ_DID_COUNT; fl_loop_count_U8++)
    {
        if (Meet_Cdd_Read_DID_Table[fl_loop_count_U8].l_did_number == *DID)
        {
            Ret = Meet_Cdd_Read_DID_Table[fl_loop_count_U8].Meet_Diag_Func(Data, Length);
            break;
        }

    } /* End of Command traverse for loop */

    return Ret;
}
/*=====================================================================================================================
**
** Function Name    :  Mgrdiag_Write_DID
**
** Visibility       :  private
**
** Description      : This function is used to call the Write DID function in the table.
**
**
** Invocation       :  Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,length,DID.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/

static Std_ReturnType Mgrdiag_Write_DID(uint8 *Data, uint8 *Length, const uint32 *DID)
{

    Std_ReturnType Ret = E_NOT_OK;
    uint8 fl_loop_count_U8;

    for (fl_loop_count_U8 = 0; fl_loop_count_U8 < MGRDIAGCDD_WRITE_DID_COUNT; fl_loop_count_U8++)
    {
        if (Meet_Cdd_Write_DID_Table[fl_loop_count_U8].l_did_number == *DID)
        {
            Ret = Meet_Cdd_Write_DID_Table[fl_loop_count_U8].Meet_Diag_Func(Data, Length);
            break;
        }

    } /* End of Command traverse for loop */

    return Ret;
}
/*=====================================================================================================================
**
** Function Name    :  Mgrdiag_Ioc_Sta_DID
**
** Visibility       :  private
**
** Description      :  This function is used to call the Ioctrl STA DID function in the table.
**
**
** Invocation       :  Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,length,DID.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/

static Std_ReturnType Mgrdiag_Ioc_Sta_DID(uint8 *Data, uint8 *Length, const uint32 *DID)
{

    Std_ReturnType Ret = E_NOT_OK;
    uint8 fl_loop_count_U8;

    for (fl_loop_count_U8 = 0U; fl_loop_count_U8 < MGRDIAGCDD_IOCTL_STA_DID_COUNT; fl_loop_count_U8++)
    {
        if (Meet_Cdd_IOC_STA_DID_Table[fl_loop_count_U8].l_did_number == *DID)
        {
            Ret = Meet_Cdd_IOC_STA_DID_Table[fl_loop_count_U8].Meet_Diag_Func(Data, Length);
            break;
        }

    } /* End of Command traverse for loop */

    return Ret;
}
/*=====================================================================================================================
**
** Function Name    :  Mgrdiag_Ioc_Rcte_DID
**
** Visibility       :  private
**
** Description      :  This function is used to call the Ioctrl Rcte DID function in the table.
**
**
** Invocation       :  Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,length,DID.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/

static Std_ReturnType Mgrdiag_Ioc_Rcte_DID(uint8 *Data, uint8 *Length, const uint32 *DID)
{

    Std_ReturnType Ret = E_NOT_OK;
    uint8 fl_loop_count_U8;

    for (fl_loop_count_U8 = 0U; fl_loop_count_U8 < MGRDIAGCDD_IOCTL_RCTE_DID_COUNT; fl_loop_count_U8++)
    {
        if (Meet_Cdd_IOC_RCTE_DID_Table[fl_loop_count_U8].l_did_number == *DID)
        {
            Ret = Meet_Cdd_IOC_RCTE_DID_Table[fl_loop_count_U8].Meet_Diag_Func(Data, Length);
            break;
        }

    } /* End of Command traverse for loop */

    return Ret;
}
/*=====================================================================================================================
**
** Function Name    :  Mgrdiag_Roc_Start_DID
**
** Visibility       :  private
**
** Description      :  This function is used to call the Routine Start DID function in the table.
**
**
** Invocation       :  Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,length,DID.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/

static Std_ReturnType Mgrdiag_Roc_Start_DID(uint8 *Data, uint8 *Length, const uint32 *DID)
{

    Std_ReturnType Ret = E_NOT_OK;
    uint8 fl_loop_count_U8;

    for (fl_loop_count_U8 = 0U; fl_loop_count_U8 < MGRDIAGCDD_RC_START_DID_COUNT; fl_loop_count_U8++)
    {
        if (Meet_Cdd_ROC_START_DID_Table[fl_loop_count_U8].l_did_number == *DID)
        {
            Ret = Meet_Cdd_ROC_START_DID_Table[fl_loop_count_U8].Meet_Diag_Func(Data, Length);
            break;
        }

    } /* End of Command traverse for loop */

    return Ret;
}
/*=====================================================================================================================
**
** Function Name    :  Mgrdiag_Roc_Stop_DID
**
** Visibility       :  private
**
** Description      :  This function is used to call the ROutine Stop DID function in the table.
**
**
** Invocation       :  Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,length,DID.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/

static Std_ReturnType Mgrdiag_Roc_Stop_DID(uint8 *Data, uint8 *Length, const uint32 *DID)
{

    Std_ReturnType Ret = E_NOT_OK;
    uint8 fl_loop_count_U8;

    for (fl_loop_count_U8 = 0U; fl_loop_count_U8 < MGRDIAGCDD_RC_STOP_DID_COUNT; fl_loop_count_U8++)
    {
        if (Meet_Cdd_ROC_STOP_DID_Table[fl_loop_count_U8].l_did_number == *DID)
        {
            Ret = Meet_Cdd_ROC_STOP_DID_Table[fl_loop_count_U8].Meet_Diag_Func(Data, Length);
            break;
        }

    } /* End of Command traverse for loop */

    return Ret;
}
/*=====================================================================================================================
**
** Function Name    :  Mgrdiag_Roc_Results_DID
**
** Visibility       :  private
**
** Description      :  This function is used to call the Routine Result DID function in the table.
**
**
** Invocation       :  Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,length,DID.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/
static Std_ReturnType Mgrdiag_Roc_Results_DID(uint8 *Data, uint8 *Length, const uint32 *DID)
{

    Std_ReturnType Ret = E_NOT_OK;
    uint8 fl_loop_count_U8;

    for (fl_loop_count_U8 = 0U; fl_loop_count_U8 < MGRDIAGCDD_RC_RESULTS_DID_COUNT; fl_loop_count_U8++)
    {
        if (Meet_Cdd_ROC_RESULTS_DID_Table[fl_loop_count_U8].l_did_number == *DID)
        {
            Ret = Meet_Cdd_ROC_RESULTS_DID_Table[fl_loop_count_U8].Meet_Diag_Func(Data, Length);
            break;
        }

    } /* End of Command traverse for loop */

    return Ret;
}
#else
/*=====================================================================================================================
**
** Function Name    :  Mgrdiag_Read_DID
**
** Visibility       :  private
**
** Description      :  This function is used to call the Read DID function in the table.
**
**
** Invocation       :  Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,length,DID.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/

static Std_ReturnType Mgrdiag_Read_DID(uint8 *Data, uint8 *Length, const uint32 *DID)
{

    Std_ReturnType Ret = E_NOT_OK;
    Ret = Mgrdiagcdd_Service_Identification_Exec(Meet_Cdd_Read_DID_Table, Data, Length, DID, MGRDIAGCDD_READ_DID_COUNT);
    return Ret;
}
/*=====================================================================================================================
**
** Function Name    :  Mgrdiag_Write_DID
**
** Visibility       :  private
**
** Description      :  This function is used to call the Write DID function in the table.
**
**
** Invocation       :  Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,length,DID.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/

static Std_ReturnType Mgrdiag_Write_DID(uint8 *Data, uint8 *Length, const uint32 *DID)
{

    Std_ReturnType Ret = E_NOT_OK;
    Ret = Mgrdiagcdd_Service_Identification_Exec(Meet_Cdd_Write_DID_Table, Data, Length, DID, MGRDIAGCDD_WRITE_DID_COUNT);
    return Ret;
}
/*=====================================================================================================================
**
** Function Name    :  Mgrdiag_Ioc_Sta_DID
**
** Visibility       :  private
**
** Description      :  This function is used to call the Ioctrl STA DID function in the table.
**
**
** Invocation       :  Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data, Length, DID.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/

static Std_ReturnType Mgrdiag_Ioc_Sta_DID(uint8 *Data, uint8 *Length, const uint32 *DID)
{

    Std_ReturnType Ret = E_NOT_OK;
    uint8 fl_loop_count_U8;

    for (fl_loop_count_U8 = 0U; fl_loop_count_U8 < MGRDIAGCDD_IOCTL_STA_DID_COUNT; fl_loop_count_U8++)
    {
        if (Meet_Cdd_IOC_STA_DID_Table[fl_loop_count_U8].l_did_number == *DID)
        {
            Ret = Meet_Cdd_IOC_STA_DID_Table[fl_loop_count_U8].Meet_Diag_Func(Data, Length);
            break;
        }

    } /* End of Command traverse for loop */

    return Ret;
}

/*=====================================================================================================================
**
** Function Name    :  Mgrdiag_Ioc_Fcs_DID
**
** Visibility       :  private
**
** Description      :  This function is used to call the Ioctrl FCS DID function in the table.
**
**
** Invocation       :  Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data, Length, DID.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/
#ifdef MGRDIAGCDD_IOCTL_FCS_DID_LIST
static Std_ReturnType Mgrdiag_Ioc_Fcs_DID(uint8 *Data, uint8 *Length, uint32 *DID)
{
    Std_ReturnType Ret = E_NOT_OK;
    uint8 fl_loop_count_U8;

    for (fl_loop_count_U8 = 0; fl_loop_count_U8 < MGRDIAGCDD_IOCTL_FCS_DID_COUNT; fl_loop_count_U8++)
    {
        if (Meet_Cdd_IOC_FCS_DID_Table[fl_loop_count_U8].l_did_number == *DID)
        {
            Ret = Meet_Cdd_IOC_FCS_DID_Table[fl_loop_count_U8].Meet_Diag_Func(Data, Length);
            break;
        }

    } /* End of Command traverse for loop */
}
#endif
/*=====================================================================================================================
**
** Function Name    :  Mgrdiag_Ioc_Rcte_DID
**
** Visibility       :  private
**
** Description      :  This function is used to call the Ioctrl Rcte DID function in the table.
**
**
** Invocation       :  Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data, Length, DID.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/

static Std_ReturnType Mgrdiag_Ioc_Rcte_DID(uint8 *Data, uint8 *Length, const uint32 *DID)
{

    Std_ReturnType Ret = E_NOT_OK;
    uint8 fl_loop_count_U8;

    for (fl_loop_count_U8 = 0U; fl_loop_count_U8 < MGRDIAGCDD_IOCTL_RCTE_DID_COUNT; fl_loop_count_U8++)
    {
        if (Meet_Cdd_IOC_RCTE_DID_Table[fl_loop_count_U8].l_did_number == *DID)
        {
            Ret = Meet_Cdd_IOC_RCTE_DID_Table[fl_loop_count_U8].Meet_Diag_Func(Data, Length);
            break;
        }

    } /* End of Command traverse for loop */

    return Ret;
}
/*=====================================================================================================================
**
** Function Name    :  Mgrdiag_Roc_Start_DID
**
** Visibility       :  private
**
** Description      :  This function is used to call the Routine Start DID function in the table.
**
**
** Invocation       :  Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data, Length, DID.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/

static Std_ReturnType Mgrdiag_Roc_Start_DID(uint8 *Data, uint8 *Length, const uint32 *DID)
{

    Std_ReturnType Ret = E_NOT_OK;
    uint8 fl_loop_count_U8;

    for (fl_loop_count_U8 = 0U; fl_loop_count_U8 < MGRDIAGCDD_RC_START_DID_COUNT; fl_loop_count_U8++)
    {
        if (Meet_Cdd_ROC_START_DID_Table[fl_loop_count_U8].l_did_number == *DID)
        {
            Ret = Meet_Cdd_ROC_START_DID_Table[fl_loop_count_U8].Meet_Diag_Func(Data, Length);
            break;
        }

    } /* End of Command traverse for loop */

    return Ret;
}
/*=====================================================================================================================
**
** Function Name    :  Mgrdiag_Roc_Stop_DID
**
** Visibility       :  private
**
** Description      :  This function is used to call the ROutine Stop DID function in the table.
**
**
** Invocation       :  Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data, Length, DID.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/

static Std_ReturnType Mgrdiag_Roc_Stop_DID(uint8 *Data, uint8 *Length, const uint32 *DID)
{

    Std_ReturnType Ret = E_NOT_OK;
    uint8 fl_loop_count_U8;

    for (fl_loop_count_U8 = 0U; fl_loop_count_U8 < MGRDIAGCDD_RC_STOP_DID_COUNT; fl_loop_count_U8++)
    {
        if (Meet_Cdd_ROC_STOP_DID_Table[fl_loop_count_U8].l_did_number == *DID)
        {
            Ret = Meet_Cdd_ROC_STOP_DID_Table[fl_loop_count_U8].Meet_Diag_Func(Data, Length);
            break;
        }

    } /* End of Command traverse for loop */

    return Ret;
}
/*=====================================================================================================================
**
** Function Name    :  Mgrdiag_Roc_Results_DID
**
** Visibility       :  private
**
** Description      :  This function is used to call the Routine Result DID function in the table.
**
**
** Invocation       :  Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data, Length, DID.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/

static Std_ReturnType Mgrdiag_Roc_Results_DID(uint8 *Data, uint8 *Length, const uint32 *DID)
{

    Std_ReturnType Ret = E_NOT_OK;
    uint8 fl_loop_count_U8;

    for (fl_loop_count_U8 = 0U; fl_loop_count_U8 < MGRDIAGCDD_RC_RESULTS_DID_COUNT; fl_loop_count_U8++)
    {
        if (Meet_Cdd_ROC_RESULTS_DID_Table[fl_loop_count_U8].l_did_number == *DID)
        {
            Ret = Meet_Cdd_ROC_RESULTS_DID_Table[fl_loop_count_U8].Meet_Diag_Func(Data, Length);
            break;
        }

    } /* End of Command traverse for loop */

    return Ret;
}

/*=====================================================================================================================
**
** Function Name    :  Mgrdiagcdd_Service_Identification_Exec
**
** Visibility       :  private
**
** Description      :  Identify the service ID and Execute the respective service
**
**
** Invocation       :  Mgrdiag_Write_DID/Mgrdiag_Read_DID
**
** Inputs           :  Service/DID list,Data,length, DID ID to be identified,Max service count.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/
static Std_ReturnType Mgrdiagcdd_Service_Identification_Exec(const MGRDIAGCDD_DID_bundle_t DID_list[], uint8 *Data, uint8 *Length, const uint32 *DID, uint8 Max_service_count)
{

    Std_ReturnType Ret = E_NOT_OK;
    uint8 fl_loop_count_U8 = 0U;
    uint8 fl_no_of_ranges_U8 = 0U;
    uint8 fl_remainder_U8 = 0U;
    uint8 fl_start_range_U8 = 0U;
    uint8 fl_stop_range_U8 = 0U;

    if (MGRDIAGCDD_MAX_ALLOWED_SERVICE > 0U)
    {
        fl_no_of_ranges_U8 = Max_service_count / MGRDIAGCDD_MAX_ALLOWED_SERVICE;
        fl_remainder_U8 = Max_service_count % MGRDIAGCDD_MAX_ALLOWED_SERVICE;

        for (fl_loop_count_U8 = 0; fl_loop_count_U8 < fl_no_of_ranges_U8; fl_loop_count_U8++)
        {
            if (*DID <= DID_list[((fl_loop_count_U8 + 1U) * MGRDIAGCDD_MAX_ALLOWED_SERVICE) - 1U].l_did_number)
            {
                fl_start_range_U8 = ((fl_loop_count_U8)*MGRDIAGCDD_MAX_ALLOWED_SERVICE);
                fl_stop_range_U8 = ((fl_loop_count_U8 + 1U) * MGRDIAGCDD_MAX_ALLOWED_SERVICE);
                fl_remainder_U8 = 0U;
                break;
            }
        }
        if (fl_remainder_U8 > 0U)
        {
            fl_start_range_U8 = (fl_loop_count_U8)*MGRDIAGCDD_MAX_ALLOWED_SERVICE;
            fl_stop_range_U8 = Max_service_count;
        }

        for (fl_loop_count_U8 = fl_start_range_U8; fl_loop_count_U8 < fl_stop_range_U8; fl_loop_count_U8++)
        {
            if (DID_list[fl_loop_count_U8].l_did_number == *DID)
            {
                Ret = DID_list[fl_loop_count_U8].Meet_Diag_Func(Data, Length);
                break;
            }
        }
    }
    return Ret;
}

#endif
/*=====================================================================================================================
**
** Function Name    :  RoutineCtrlStatusUpdate
**
** Visibility       :  Public
**
** Description      :
**
**
** Invocation       :
**
** Inputs           :  Routine type and Routine status.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/

uint8 RoutineCtrlStatusUpdate(uint8 RCType, uint8 RCState)
{
    uint8 Status = INVALID_RCTYPE;
    switch (RCType)
    {
    /*Routine type 1*/
    case 1:
        Status = ROUTINETYPE1 | ((uint8)eROUTINE_COMPLETED);
        break;

    /*Routine type 2*/
    case 2:
        switch (RCState)
        {
        case (uint8)eROUTINE_INACTIVE:
        case (uint8)eROUTINE_FINISH_OK:
            Status = ROUTINETYPE2 | ((uint8)eROUTINE_COMPLETED);
            break;
        case (uint8)eROUTINE_INPROGRESS:
            Status = ROUTINETYPE2 | ((uint8)eROUTINE_ACTIVE);
            break;
        case (uint8)eROUTINE_FINISH_NOK:
            Status = ROUTINETYPE2 | ((uint8)eROUTINE_ABORTED);
            break;
        default:
            Status = INVALID_RCTYPE;
            break;
        }
        break;
    /*Routine type 3*/
    case 3:
        Status = RCState;
        break;
    /*Routine type 4*/
    case 4:
        switch (RCState)
        {
        case (uint8)eROUTINE_INACTIVE:
            Status = (uint8)eROUTINE_CHECKSUM_DEFAULT;
            break; // Coverity fix CID : 1827618,1827619
        case (uint8)eROUTINE_FINISH_OK:
            Status = (uint8)eROUTINE_CHECKSUM_OK;
            break;
        case (uint8)eROUTINE_INPROGRESS:
            Status = (uint8)eROUTINE_CHECKSUM_DEFAULT;
            break;
        case (uint8)eROUTINE_FINISH_NOK:
            Status = (uint8)eROUTINE_CHECKSUM_NOK;
            break;
        default:
            Status = INVALID_RCTYPE;
            break;
        }
        break;
    default:
        Status = INVALID_RCTYPE;
        break;
    }
    return Status;
}
#if (DECIMALMANIPUTATION_ENABLE_ANALOG_DIAG > 0) || (DECIMALMANIPUTATION_ENABLE_DIMMING_CTRL > 0)
/*=====================================================================================================================
**
** Function Name    :  DutyManipulateWitDecimal
**
** Visibility       :  Private
**
** Description      :  Manipulate data to Duty conversion
**
**
** Invocation       :
**
** Inputs           :  BCD values
**
** Outputs          :  Std_ReturnType
**
** Critical Section : Yes
**
**====================================================================================================================*/
uint16 DutyManipulateWitDecimal(uint16 Data_msb, uint16 Data_lsb)
{
    uint16 duty_data;

    duty_data = (uint16)((Data_msb & 0x00FFU) << 8U);
    duty_data |= (uint16)Data_lsb;

    return (duty_data);
}
#endif
#if (BCDMANIPUTATION_ENABLE_ANALOG_DIAG > 0) || (BCDMANIPUTATION_ENABLE_DIMMING_CTRL > 0)
/*=====================================================================================================================
**
** Function Name    :  DutyManipulateWithBCD
**
** Visibility       :  Private
**
** Description      :  Manipulate data to Duty conversion
**
**
** Invocation       :
**
** Inputs           :  BCD values
**
** Outputs          :  Std_ReturnType
**
** Critical Section : Yes
**
**====================================================================================================================*/
uint16 DutyManipulateWithBCD(uint16 Data_msb, uint16 Data_lsb)
{
    uint16 duty_data;
    uint16 loc_Data_msb = Data_msb;
    uint16 loc_Data_lsb = Data_lsb;

    loc_Data_msb = bcd2dec((uint8)loc_Data_msb);

    loc_Data_msb = loc_Data_msb * 100U;

    loc_Data_lsb = bcd2dec((uint8)loc_Data_lsb);

    duty_data = loc_Data_msb + loc_Data_lsb;

    duty_data = (uint16)((duty_data * DUTY_ACCURACY) / 1000U); // u16Scale varies from 0 to 10000
    return (duty_data);
}
/*=====================================================================================================================
**
** Function Name    :  bcd2dec
**
** Visibility       :  Private
**
** Description      :  BCD TO DECIMAL CONVERSION
**
**
** Invocation       :
**
** Inputs           :  BCD values
**
** Outputs          :  Std_ReturnType
**
** Critical Section : Yes
**
**====================================================================================================================*/
static uint8 bcd2dec(uint8 bcd)
{
    uint8 dec = 0U;
    uint8 mult;
    for (mult = 1U; bcd; mult *= 10U)
    {
        dec += ((bcd & 0x0FU) * mult);
        bcd = bcd >> 4U;
    }
    return dec;
}
#endif
#ifdef IOCTRLRD_FUEL_INPUT_READING_BY_UNIT_WCalib
#ifndef IOCTRLRD_FUEL_INPUT_READING_THREE_POINT_CALIB
FUNC(void, CMeetCdd_CODE) CMeetCdd_Task(void)
{
    Ioctrlrd_analog_fuel_level_periodic_func();
}
#endif
#endif

#ifdef MFGMODEREQENABLE
Std_ReturnType CMeetCdd_Write_Mfg_Flag(uint16 *Data)
{
    Std_ReturnType ret = E_NOT_OK;
    ret = Memdiag_Write_Mfg_Flag(Data);
    return ret;
}
#ifdef MFGMODESTATUS
Std_ReturnType CMeetCdd_Read_ManufModeStatus(EMeetModeStatus *currentstate)
{
    Std_ReturnType ret = E_NOT_OK;
    ret = Memdiag_Read_ManufModeStatus(currentstate);
    return ret;
}
#endif
#endif

#ifdef RESETDIAG_MODULE_ENABLE
#ifdef LOWQCURRENTENABLE
Std_ReturnType CMeetCdd_Get_LowQCurrent_Sleep_Status(ELowQCurrentSleepStatus *LowQCmdState)
{
    Std_ReturnType ret = E_NOT_OK;

    ret = ResetSleepdiag_Get_LowQCurrent_Sleep_Status(LowQCmdState);

    return ret;
}
#endif
#endif
/*=====================================================================================================================
**  for each change to this file, be sure to record:
**  1.  who made the change and when the change was made
**  2.  why the change was made and the intended result
**  Following block needs to be repeated for each change
**====================================================================================================================*/
/*=====================================================================================================================
**   Note: In the traceability column we need to trace back to the Design Doc.
**   For the initial version it is traced to the Design Document section.
**   For further changes it shall trace to the source of the change which may
**   be SPSS/SCR/Defect details(Defect may be Testing/validation defect)/Any
**   other reason
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  13/09/2023
** CDSID             :  mprajapa
** Traceability      :  JIRA 3839
** Change Description:  Upddated identation.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  14/Dec/2022
** CDSID             :  ddanecha
** Traceability      :  RTC - 1855833
** Change Description:  Cybersecdiagcdd related interface macro changed.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  27/Oct/2022
** CDSID             :  ddanecha
** Traceability      :  RTC-1811312
** Change Description:  I2C test runnable added and Coverity/MISRA fix
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  07/Sep/2022
** CDSID             :  razhakes
** Traceability      :  RTC-1759758
** Change Description:  For programs supporting startup read for GIP DIDs(READ_INTERFACE_FOR_APPL_COMPONENTS), conditional check added before Read service in CMeetCdd_Meet_Mgrdiagcdd_Action().
 Also generalised the API CMeetCdd_Mgrdiagcdd_ReadAction()
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  24/Aug/2022
** CDSID             :  ddanecha
** Traceability      :  RTC-1744046
** Change Description:  Runnable for display touch test added.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  03/Aug/2022
** CDSID             :  ddanecha
** Traceability      :  RTC-1707104
** Change Description:  MeetCdd Coverity-MISRA fix
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  23/05/2022
** CDSID             :  ddanecha
** Traceability      :  RTC 1634375
** Change Description:  Coverity/MISRA Fix.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 15/March/2021
** CDSID             : razhakes
** Traceability      : RTC-1272178
** Change Description: MeetModeReadStatus API added for external components ref
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  08/Aug/2020
** CDSID             :  razhakes
** Traceability      :  RTC -880214, RTC-880217, RTC-880207
** Change Description:  Periodic fn of backup bank verification and Cybersecurity Key verification added,Meetcdd_process() called directly instead of Trusted function
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  10/March/2020
** CDSID             :  razhakes and dkasiman
** Traceability      :  RTC -760543
** Change Description:  Support for security DID implementation
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  24/01/2020
** CDSID             :  dkasiman
** Traceability      :  RTC 1380314
** Change Description:  Coverity/Misra fix.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  18/Sept/2019
** CDSID             :  razhakes
** Traceability      :  RTC-1370043
** Change Description:  Call_MeetcddProcess() redefined as a MACRO MEETCDD_PROCESS_FUNC_CALL()
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  11/Sept/2019
** CDSID             :  razhakes
** Traceability      :  RTC-1368191
** Change Description:  MGRDIAGCDD_XXX_ACTION MACROS declared in both src.c&.h. Hence removed from .c
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  10/06/2019
** CDSID             :  razhakes
** Traceability      :  RTC-1334319
** Change Description:  Background task added for program NVM from ROM service
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  31/05/2019
** CDSID             :  razhakes
** Traceability      :  RTC-1331232
** Change Description:  For Auto configure/verify service, added MemDiag_NVMConfigureorVerify() in CmpActive().
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 24/May/2019
** CDSID             : dkasiman
** Traceability      : RTC 1310400
** Change Description: CMeetCdd_Task() retricted for three point fuel measurement.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  17/05/2019
** CDSID             :  dkasiman
** Traceability      :  RTC
** Change Description:  Three point fuel calibration added.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 05/Apr/2019
** CDSID             : dkasiman
** Traceability      : RTC 1308973
** Change Description: fl_remainder_U8 variable is cleared in DID ID is identified in the function
                       Mgrdiagcdd_Service_Identification_Exec().
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  18/march/2019
** CDSID             :  razhakes
** Traceability      :  RTC 1297724
** Change Description:  DutyManipulateWithBCD and DutyManipulateWitDecimal defined
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  02/March/2019
** CDSID             :  razhakes
** Traceability      :  RTC 1262819
** Change Description:  Meet_Process_Gip_Diag_Request function moved from src to cfg file
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  01/02/2019
** CDSID             :  razhakes
** Traceability      :  RTC 1262819
** Change Description:  Meet_Process_Gip_Diag_Request function added
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  11/1/2019
** CDSID             :  athiyag2
** Traceability      :  RTC 1265368
** Change Description:  compiler warning fix
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  16/10/2018
** CDSID             :  gdhilipr
** Traceability      :  RTC 1217469
** Change Description:  Memory checksum test(F11E) � VIP,GIP,NAND and NOR
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 01/Oct/2018
** CDSID             : dkasiman
** Traceability      : RTC-1208647
** Change Description: Meet manager binary search is corrected to check whether the DID is equal.
**=======================================================================================================================*/
/*=====================================================================================================================
** Date              :  05/09/2018
** CDSID             :  rkathir1
** Traceability      :  RTC 1190004
** Change Description:  New implementation for handling and read ADC values for safe implementation
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 10/Aug/2018
** CDSID             : dkasiman
** Traceability      : RTC-1148479
** Change Description: Variable update in periodic task to detect timeout if keys are not valid while doing security unlock.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 12/July/2018
** CDSID             : dkasiman
** Traceability      : RTC-1146978
** Change Description: Meet manager binary search is corrected to aviod overflow.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 02/Jun/2018
** CDSID             : dkasiman
** Traceability      : RTC-1112314
** Change Description: Review comments fix.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 20/May/2018
** CDSID             : dkasiman
** Traceability      : RTC-1112314
** Change Description: Initial version for MeetCdd bookshelf
**====================================================================================================================*/
#endif /* MGRDIAGCDD_C */
