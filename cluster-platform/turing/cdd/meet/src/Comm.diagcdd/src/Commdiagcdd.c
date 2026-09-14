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
** Name:           Commdiagcdd
**
** Description:    Contains Communication related services
**
**
**===================================================================================================================*/

#ifndef COMMDIAGCDD_C
#define COMMDIAGCDD_C

/*====================================================================================================================
**                 I N C L U D E   F I L E S
**===================================================================================================================*/
#include "Mgrdiagcdd.h"
#include "Mgrdiagcdd_cfg.h"
#include "Commdiagcdd.h"
#include "Commdiagcdd_cfg.h"

#ifdef COMMDIAGCDD_I2C_TEST_ENABLE
static eRoutineStatus Commdiag_I2Ctest_RCStatus =  eROUTINE_INACTIVE;
#endif

#ifdef COMDIAG_MODULE_ENABLE

/*====================================================================================================================
**   I N T E R N A L   M A C R O   D E F I N I T I O N S
**===================================================================================================================*/

/*=====================================================================================================================
**  T Y P E    D E C L A R A T I O N S
**====================================================================================================================*/

/*=====================================================================================================================
**  C O N S T A N T    A N D   V A R I A B L E S    D E C L A R A T I O N S
**====================================================================================================================*/
#ifdef COMM_BUS_VERIFICATION_TEST
#define COMM_MSG_TX_NOT_STARTED         ((uint8)0U)
#define COMM_MSG_TX_STARTED             ((uint8)1U)

#define COMM_TIME_ELAPSED               ((uint8)1U)
#define COMM_TIME_NOT_ELAPSED           ((uint8)0U)

#define COMM_START_TEST                 ((uint8)1U)
#define COMM_STOP_TEST                  ((uint8)0U)
#endif

#ifdef COMM_BUS_VERIFICATION_TEST
static uint8 l_Comm_test_start_status_U8;
static uint8 l_timer_elapsed_U8;
static uint8 l_Comm_Msg_Rcvd_U8;
static uint8 l_comm_counter_U8;
static uint8 l_Comm_msg_Status_U8 = COMM_MSG_TX_NOT_STARTED;
#endif
/*=====================================================================================================================
**  PRIVATE
**====================================================================================================================*/

#ifdef COMM_BUS_VERIFICATION_TEST
/*=====================================================================================================================
**
** Function Name    :  Comm_Bus_Verification_Test_RCStart
**
** Visibility       :  Public
**
** Description      :  Communication bus verifcation start routine
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data[In]:Communication bus ID
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Comm_Bus_Verification_Test_RCStart(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;
    Comm_config_ID fl_Comm_TxConfig_ID_U8;
    Comm_Signal_info fl_Comm_TxSig_Info;
    uint8 fl_TransmitMsg_U8A[COMM_DATA_TX_LENGTH];

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        if (Data[0] == COMM_BUS_ID)
        {

            l_comm_counter_U8 = 0U;                        // Start counter
            l_timer_elapsed_U8 = COMM_TIME_NOT_ELAPSED;    // reset timer elapse
            l_Comm_test_start_status_U8 = COMM_START_TEST; // start comm test
            fl_Comm_TxConfig_ID_U8 = COMM_TX_CONFIG_ID;
            fl_TransmitMsg_U8A[DATA_BYTE_0] = COMM_DATA_TX;
            fl_Comm_TxSig_Info.SduDataPtr = &fl_TransmitMsg_U8A[DATA_BYTE_0];
            fl_Comm_TxSig_Info.SduLength = COMM_DATA_TX_LENGTH;
            CommDiag_Bus_Msg_Config.CommDiag_ClrRxTxInfo();
            (void)CommDiag_Bus_Msg_Config.CommDiag_TxMsg(fl_Comm_TxConfig_ID_U8, &fl_Comm_TxSig_Info);
            l_Comm_msg_Status_U8 = COMM_MSG_TX_STARTED;
            Data[DATA_BYTE_0] = (uint8)RoutineCtrlStatusUpdate(COMMBUSRCTYPE, eROUTINE_INPROGRESS);
            ret = E_OK;
        }
        else
        {
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
        }
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}
/*=====================================================================================================================
**
** Function Name    :  Comm_Bus_Verification_Test_RCStatus
**
** Visibility       :  Public
**
** Description      :  Communication bus verifcation result routine
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data[In]:Communication bus ID
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Comm_Bus_Verification_Test_RCStatus(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        if (Data[0] == COMM_BUS_ID)
        {
            if (l_Comm_msg_Status_U8 == COMM_MSG_TX_NOT_STARTED)
            {
                Data[DATA_BYTE_0] = (uint8)RoutineCtrlStatusUpdate(COMMBUSRCTYPE, eROUTINE_INACTIVE); // Routine inactive
            }
            else if (l_Comm_Msg_Rcvd_U8 == MSG_RCVD)
            {
                if (l_timer_elapsed_U8 == COMM_TIME_NOT_ELAPSED)
                {
                    Data[DATA_BYTE_0] = (uint8)RoutineCtrlStatusUpdate(COMMBUSRCTYPE, eROUTINE_FINISH_OK); // Routine completed ok
                    l_Comm_msg_Status_U8 = COMM_MSG_TX_NOT_STARTED;
                }
                else
                {
                    Data[DATA_BYTE_0] = (uint8)RoutineCtrlStatusUpdate(COMMBUSRCTYPE, eROUTINE_FINISH_NOK); // Routine completed Nok
                    l_Comm_msg_Status_U8 = COMM_MSG_TX_NOT_STARTED;
                }
            }
            else /* if message is not received --> msg_rcvd == MSG_NOT_RCVD */
            {
                if (l_timer_elapsed_U8 == COMM_TIME_NOT_ELAPSED)
                {
                    Data[DATA_BYTE_0] = (uint8)RoutineCtrlStatusUpdate(COMMBUSRCTYPE, eROUTINE_INPROGRESS); // Routine Inprogress
                    l_Comm_msg_Status_U8 = COMM_MSG_TX_STARTED;
                }
                else
                {
                    Data[DATA_BYTE_0] = (uint8)RoutineCtrlStatusUpdate(COMMBUSRCTYPE, eROUTINE_FINISH_NOK); // Routine completed Nok
                    l_Comm_msg_Status_U8 = COMM_MSG_TX_NOT_STARTED;
                }
            }

            ret = E_OK;
        }
        else
        {
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
        }
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}
/*=====================================================================================================================
**
** Function Name    :  Comm_Bus_Periodic_Function
**
** Visibility       :  Public
**
** Description      :  Periodic function to check the communication timeout
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  None
**
** Outputs          :  None
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
void Comm_Bus_Periodic_Function(void)
{
    l_Comm_Msg_Rcvd_U8 = CommDiag_Bus_Msg_Config.CommDiag_RxCbk();
    if ((l_Comm_test_start_status_U8 == COMM_START_TEST) && (l_Comm_Msg_Rcvd_U8 == MSG_NOT_RCVD))
    {
        l_comm_counter_U8++;

        if (l_comm_counter_U8 >= COMM_TIMER_ELAPSE_VAL)
        {
            l_timer_elapsed_U8 = COMM_TIME_ELAPSED;
            l_comm_counter_U8 = 0;
            l_Comm_test_start_status_U8 = COMM_STOP_TEST;
        }
        else
        {
            ;
        }
    }
    else
    {
        ;
    }
}
#endif
#endif
#ifdef COMMCONTROLDIAG_CXPITEST_ROUTINE
/*=====================================================================================================================
**
** Function Name    :  Commdiag_CxpiCddcontroldiag_RCStart
**
** Visibility       :  Public
**
** Description      :  Cxpi Diag RC Start
**
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data[In]: NA
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Commdiag_CxpiCddcontroldiag_RCStart(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = CxpiVerificationTestConfig.ComMVerificationDiag_Start(Data, ErrorCode);
    }
    else
    {
        /*Invalid Mode*/
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}

/*=====================================================================================================================
**
** Function Name    :  Commdiag_CxpiCddcontroldiag_RCStop
**
** Visibility       :  Public
**
** Description      :  Cxpi Diag RC Stop
**
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/

Std_ReturnType Commdiag_CxpiCddcontroldiag_RCStop(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = CxpiVerificationTestConfig.ComMVerificationDiag_Stop(Data, ErrorCode);
    }
    else
    {
        /*Invalid Mode*/
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}

/*=====================================================================================================================
**
** Function Name    :  Commdiag_CxpiCddcontroldiag_RCStatus
**
** Visibility       :  Public
**
** Description      :  Cxpi Diag RC Status
**
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/

Std_ReturnType Commdiag_CxpiCddcontroldiag_RCStatus(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = CxpiVerificationTestConfig.ComMVerificationDiag_Result(Data, ErrorCode);
    }
    else
    {
        /*Invalid Mode*/
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
#endif

#ifdef COMMCONTROLDIAG_MCANTEST_ROUTINE
/*=====================================================================================================================
**
** Function Name    :  Commdiag_Mcancontroldiag_RCStart
**
** Visibility       :  Public
**
** Description      :  MCanCtrl Diag RC Start
**
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data[In]: NA
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Commdiag_Mcancontroldiag_RCStart(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = MCanCtrlVerificationTestConfig.ComMVerificationDiag_Start(Data, ErrorCode);
    }
    else
    {
        /*Invalid Mode*/
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}

/*=====================================================================================================================
**
** Function Name    :  Commdiag_Mcancontroldiag_RCStop
**
** Visibility       :  Public
**
** Description      :  MCanCtrl Diag RC Stop
**
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/

Std_ReturnType Commdiag_Mcancontroldiag_RCStop(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = MCanCtrlVerificationTestConfig.ComMVerificationDiag_Stop(Data, ErrorCode);
    }
    else
    {
        /*Invalid Mode*/
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}

/*=====================================================================================================================
**
** Function Name    :  Commdiag_Mcancontroldiag_RCStatus
**
** Visibility       :  Public
**
** Description      :  MCanCtrl Diag RC Status
**
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/

Std_ReturnType Commdiag_Mcancontroldiag_RCStatus(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = MCanCtrlVerificationTestConfig.ComMVerificationDiag_Result(Data, ErrorCode);
    }
    else
    {
        /*Invalid Mode*/
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
#endif
#ifdef MM_CAN_TEST_ENABLE
Std_ReturnType Commdiag_Mmcan_Read(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        (void)MMCanCtrlVerificationReadConfig.MMCANvericationRx(Data, ErrorCode);
        if (Data[0] == RX_VERIFICATION_SUCCESSFUL)
        {
            ret = MMCanCtrlVerificationReadConfig.MMCANvericationTx(Data, ErrorCode);
        }
        else
        {
            ret = E_OK;
        }
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}
#endif
#ifdef COMMDIAGCDD_I2C_TEST_ENABLE
/*=====================================================================================================================
**
** Function Name    :  Commdiag_I2C_Test_RCStart
**
** Visibility       :  Public
**
** Description      :  This function starts routine to test all the touch points on the display
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data[In] : Channel Id and Slave Address
**					   Errorcode : To be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK : Fail
**
** Critical Section :  No
**
**====================================================================================================================*/
Std_ReturnType Commdiag_I2C_Test_RCStart(uint8 *Data, uint8 *ErrorCode)
{
	Std_ReturnType ret = E_NOT_OK;
	uint8 MfgModeActive = 0U;

	MGRDIAG_GET_SESSION(&MfgModeActive);

	if(MfgModeActive == MEET_SESSION)
	{
        if(eROUTINE_INPROGRESS == Commdiag_I2Ctest_RCStatus)
		{
			 /*Already Routine in progress*/
              *ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
		}
		else
		{
			ret = Commdiag_I2CTestConfig.Commdiag_I2CTest_Start(Data);

			if(ret == (uint8)E_OK)
			{
				Commdiag_I2Ctest_RCStatus = eROUTINE_INPROGRESS;
			}
			else
			{
				*ErrorCode = DCM_E_REQUESTOUTOFRANGE;
			}
		}
	}
	else
	{
		/*invalid mode*/
		*ErrorCode = INVALID_MODE;
	}

	return ret;
}

/*=====================================================================================================================
**
** Function Name    :  Commdiag_I2C_Test_RCStop
**
** Visibility       :  Public
**
** Description      :  This function stops routine to test all the touch points on the display
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data[In] :
** 					   Errorcode : To be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK : Fail
**
** Critical Section :  No
**
**====================================================================================================================*/
Std_ReturnType Commdiag_I2C_Test_RCStop(uint8 *Data, uint8 *ErrorCode)
{
	Std_ReturnType ret = E_NOT_OK;
	uint8 MfgModeActive = 0U;

	MGRDIAG_GET_SESSION(&MfgModeActive);

	if(MfgModeActive == MEET_SESSION)
	{
		if(eROUTINE_INACTIVE != Commdiag_I2Ctest_RCStatus)
    	{
			ret = Commdiag_I2CTestConfig.Commdiag_I2CTest_Stop(Data);
			
			if(ret == (uint8)E_OK)
			{
				Commdiag_I2Ctest_RCStatus = eROUTINE_STOPPED;
				Data[DATA_BYTE_0] = (uint8)RoutineCtrlStatusUpdate(COMMDIAGI2CRCTYPE, (uint8)Commdiag_I2Ctest_RCStatus);
			}
			else
			{
				*ErrorCode = DCM_E_REQUESTOUTOFRANGE;
			}
		}
		else
    	{
    		/*Routine not started*/
    		*ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
    	}
	}
	else
	{
		/*invalid mode*/
		*ErrorCode = INVALID_MODE;
	}

	return ret;
}

/*=====================================================================================================================
**
** Function Name    :  Commdiag_I2C_Test_RCStatus
**
** Visibility       :  Public
**
** Description      :  This function provides result of routine to test all the touch points on the display
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data[In]
** 					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK : Fail
**
** Critical Section :  No
**
**====================================================================================================================*/
Std_ReturnType Commdiag_I2C_Test_RCStatus(uint8 *Data,uint8 *ErrorCode)
{
	Std_ReturnType ret = E_NOT_OK;
	uint8 MfgModeActive = 0U;

	MGRDIAG_GET_SESSION(&MfgModeActive);

	if(MfgModeActive == MEET_SESSION)
	{
    	if(eROUTINE_INACTIVE != Commdiag_I2Ctest_RCStatus)
    	{
			ret = Commdiag_I2CTestConfig.Commdiag_I2CTest_Result(Data);
			
			if(ret == (uint8)E_OK)
			{
				Commdiag_I2Ctest_RCStatus = eROUTINE_FINISH_OK;
				Data[DATA_BYTE_0] = (uint8)RoutineCtrlStatusUpdate(COMMDIAGI2CRCTYPE, (uint8)Commdiag_I2Ctest_RCStatus);
			}
			else
			{
				ret = E_OK;
				Commdiag_I2Ctest_RCStatus = eROUTINE_FINISH_NOK;
				Data[DATA_BYTE_0] = (uint8)RoutineCtrlStatusUpdate(COMMDIAGI2CRCTYPE, (uint8)Commdiag_I2Ctest_RCStatus);				
			}

    	}
    	else
    	{
    		/*Routine not started*/
    		*ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
    	}
	}
	else
	{
		/*invalid mode*/
		*ErrorCode = INVALID_MODE;
	}

	return ret;
}
#endif

#ifdef COMMCONTROLDIAG_GIPTEST_ROUTINE
/*=====================================================================================================================
**
** Function Name    :  Commdiag_GIPcontroldiag_RCStart
**
** Visibility       :  Public
**
** Description      :  GIP Diag RC Start
**
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data[In]: NA
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Commdiag_GIPcontroldiag_RCStart(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = GIPVerificationTestConfig.GIPVerificationDiag_Start(Data, ErrorCode);
    }
    else
    {
        /*Invalid Mode*/
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}

/*=====================================================================================================================
**
** Function Name    :  Commdiag_GIPcontroldiag_RCStop
**
** Visibility       :  Public
**
** Description      :  GIP Diag RC Stop
**
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/

Std_ReturnType Commdiag_GIPcontroldiag_RCStop(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = GIPVerificationTestConfig.GIPVerificationDiag_Stop(Data, ErrorCode);
    }
    else
    {
        /*Invalid Mode*/
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}

/*=====================================================================================================================
**
** Function Name    :  Commdiag_GIPcontroldiag_RCStatus
**
** Visibility       :  Public
**
** Description      :  GIP Diag RC Status
**
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/

Std_ReturnType Commdiag_GIPcontroldiag_RCStatus(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = GIPVerificationTestConfig.GIPVerificationDiag_Result(Data, ErrorCode);
    }
    else
    {
        /*Invalid Mode*/
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
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
** Date              :  23/05/2022
** CDSID             :  ddanecha
** Traceability      :  RTC 1634375
** Change Description:  Coverity/MISRA Fix.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  13/05/2020
** CDSID             :  dkasiman
** Traceability      :  RTC 880204
** Change Description:  Communication bus verification test service addition.
**====================================================================================================================*/
#endif
