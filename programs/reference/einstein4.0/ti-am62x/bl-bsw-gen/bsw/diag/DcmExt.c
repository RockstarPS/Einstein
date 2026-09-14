//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2020] Visteon Corporation
// All Rights Reserved.
//
// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
// under all copyright laws to protect this work as a published work, when appropriate.
// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
// without the written authorization of Visteon Corporation.
/*****************************************************************************
*  File Name         :  DcmExt.c                                             *
*  Module Short Name :  DcmExt                                               *
*  Description       :  This file contains implementations of the Ecu        *
*                       State Manager callouts specified by Autosar          *
*                       This is an intergration code for EcuMgr              *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  GHS Multi                                              *
* Target Hardware  :  Platform Independent                                   *
*                                                                            *
******************************************************************************/
#ifndef DCMEXT_C
#define DCMEXT_C

#include "Dcm.h"
#include "Dcm_Internal.h"
#include "Dcm_Dsp.h"
#include "Dcm_Cfg.h"
#include "Dcm_Types.h"
#include "NvM.h"
#include <string.h>
#include "Csm.h"

//#include "CanCcl.h"

//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================

#define DCM_DSP_DID_READ          0x01u
#define DCM_DSP_DID_WRITE         0x02u
#define DCM_DSP_DID_IO            0x04u

#define DCM_DSP_RID_START         0x01u
#define DCM_DSP_RID_STOP          0x02u
#define DCM_DSP_RID_RESULTS       0x03u

# define DCM_IO_RETCTRL2ECU       0x00u
# define DCM_IO_SHRTTRMADJ        0x03u

/* NVM Related State Machine*/

#define DCM_NVM_IDLE 	            0u
#define DCM_NVM_INIT 	            1u
#define DCM_NVM_PROCESS           2u
#define DCM_NVM_WAIT 	            3u
#define DCM_NVM_COMPLETE 	 	 	 	 	4u

#define RDBI_0xF188_BYTELENGTH 24
#define RDBI_0xF122_BYTELENGTH 31
#define RDBI_0xFD27_BYTELENGTH 3
#define RDBI_0xFD28_BYTELENGTH 3
#define RDBI_0xFD30_BYTELENGTH 1
#define RDBI_0xFE00_BYTELENGTH 3
#define RDBI_0xFE03_BYTELENGTH 16
#define RDBI_0xFEF5_BYTELENGTH 3

#define RDBI_0x1111_BYTELENGTH 3
#define RDBI_0x2222_BYTELENGTH 3
#define RDBI_0x3333_BYTELENGTH 3
#define RDBI_0x4444_BYTELENGTH 8
#define RDBI_0x5555_BYTELENGTH 3
#define RDBI_0x6666_BYTELENGTH 3
#define RDBI_0xDDDD_BYTELENGTH 3
#define RDBI_0xEEEE_BYTELENGTH 3
#define RDBI_0xFFFF_BYTELENGTH 3

#define WriteBI_0x4444_BYTELENGTH 8
#define WriteBI_0x5555_BYTELENGTH 2
#define WriteBI_0x6666_BYTELENGTH 1

#define WriteBI_0xAAAA_BYTELENGTH 54
#define WriteBI_0xBBBB_BYTELENGTH 54
#define WriteBI_0xCCCC_BYTELENGTH 54

#define RDBI_0x7000_BYTELENGTH 54
#define RDBI_0x7010_BYTELENGTH 54
#define RDBI_0x7012_BYTELENGTH 54
#define RDBI_0x7020_BYTELENGTH 54
#define RDBI_0x7021_BYTELENGTH 54
#define RDBI_0x7022_BYTELENGTH 54
#define RDBI_0x7028_BYTELENGTH 54
#define RDBI_0x702A_BYTELENGTH 54
#define RDBI_0x702B_BYTELENGTH 54
#define RDBI_0x7090_BYTELENGTH 54
#define RDBI_0x70C0_BYTELENGTH 54
#define RDBI_0x70C1_BYTELENGTH 54
#define RDBI_0x70C4_BYTELENGTH 54
#define RDBI_0x70D1_BYTELENGTH 54
#define RDBI_0x70F0_BYTELENGTH 54
#define RDBI_0xE600_BYTELENGTH 2
#define RDBI_0xE602_BYTELENGTH 3
#define RDBI_0xF100_BYTELENGTH 2
#define RDBI_0xF110_BYTELENGTH 17
#define RDBI_0xF112_BYTELENGTH 31
#define RDBI_0xF181_BYTELENGTH 16
#define RDBI_0xFEF6_BYTELENGTH 1

#define RESET_NOT_REQUESTED  	(0u)
#define RESET_INITIATED      	(1u)
#define RESET_CONFIRMED      	(2u)
#define RESET_TIMEOUT 			((uint16)10)
#define TIMER_ELAPSED 			(0u)
#define DIAG_TIMEOUT		    (2u)

#define OTA_ERASE_ROUTINE_ID					(0xFF00)
#define OTA_VALIDATE_ROUTINE_ID					(0xFF01)
#define OTA_ACTIVATE_ROUTINE_ID					(0xFE00)
#define OTA_ROLLBACK_ROUTINE_ID					(0xFE01)
#define OTA_ACTIVATION_COMPLETE_ROUTINE_ID		(0xFE02)
#define OTA_SYNC_ROUTINE_ID						(0xFE03)

typedef enum {
  eREAD = 0,
  eWRITE,
  eRCTECU,
  eRTD,
  eFCS,
  eSTA
} eDcmExt_ActionType;



//=====================================================================================================================
//  FORWARD DECLARATIONS
//=====================================================================================================================

//=====================================================================================================================
//  PRIVATE
//=====================================================================================================================

//=====================================================================================================================
//  PUBLIC
//=====================================================================================================================
/* ----------------------------------------------
 ~&&&   Versions
 ---------------------------------------------- */

static uint8 Dcm_NvMDefaultWriteState;
static uint8 Dcm_nvm_BlockWrite_State;

static uint8 DummyRandomNumberArray[16] = {0x1c, 0xd5, 0xf8, 0xe9, 0xb7, 0xe8, 0x09, 0xf3, 0x91, 0x97, 0x0b, 0xe8, 0x91, 0xfa, 0x8e, 0x32};
volatile uint8 RandomNumberArray[16];
volatile uint8 EncryptedDataArray[16];
static uint32 Service_27_01_KeyLength = 16;
static uint8 Service_27_01_Key[16] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF};

static boolean Dcm_NvMError;
static Dcm_NegativeResponseCodeType DcmExt_NvmNrc;
static Std_ReturnType DcmExt_NvmReturn;
static uint8 flagHardReset = RESET_NOT_REQUESTED;
static uint16 SessionReset_Timeout = RESET_TIMEOUT;
static boolean ProgSessionStatus = FALSE;
static boolean SessionChangeRequest = FALSE;

extern Std_ReturnType DcmExt_Service_DataRead_F188(uint8 OpStatus,Dcm_MsgType Data);
extern Std_ReturnType DcmExt_Service_DataRead_F122(uint8 OpStatus,Dcm_MsgType Data);
extern Std_ReturnType DcmExt_Service_DataRead_FEF6(uint8 OpStatus,Dcm_MsgType Data);


#define WriteBI_0xFD27_BYTELENGTH 3
#define WriteBI_0xFD28_BYTELENGTH 2

extern Std_ReturnType DcmExt_Service_DataWrite_FD27(uint8 OpStatus, Dcm_NegativeResponseCodeType *pNegRes, Dcm_MsgType Data);
extern Std_ReturnType DcmExt_Service_DataWrite_FD28(uint8 OpStatus, Dcm_NegativeResponseCodeType *pNegRes, Dcm_MsgType Data);

extern Std_ReturnType CUpdateCdd_UpdateCdd_GenericRIDRequestHandler(Dcm_OpStatusType opStatus, uint8 Rid_action, uint16 Rid, Dcm_MsgLenType ReqLength, Dcm_MsgType Buff,Dcm_MsgLenType* RespLength, Dcm_NegativeResponseCodeType *ErrorCode);
extern Std_ReturnType CUpdateCdd_UpdateCdd_GenericRequestDownloadHandler(Dcm_OpStatusType OpStatus, uint8 DataFormatIdentifier, uint32 MemoryAddress, uint32 MemorySize, uint32* BlockLength, uint8* ErrorCode);
extern Std_ReturnType CUpdateCdd_UpdateCdd_GenericTransferDataHandler(Dcm_OpStatusType OpStatus, uint8 MemoryIdentifier,uint32 MemoryAddress,uint32 MemorySize, uint8* MemoryData,uint8* ErrorCode);
extern Std_ReturnType CUpdateCdd_UpdateCdd_GenericTransferExitHandler(Dcm_OpStatusType opStatus, uint8 RequestfParameterRecord, uint32 RequestParameterRecordSize, uint8* ResponseParameterRecord, uint32* ResponseParameterRecordSize, uint8* ErrorCode);
extern Std_ReturnType CUpdateCdd_UpdateCdd_GenericResetHandler( uint8* ErrorCode);
/**************************************************************************
 Function name       : Std_ReturnType STPCDD_Did_DiagAction(Dcm_MsgContextType *pMsgContext)
 Description         :
 Parameters (in)     : Dcm_MsgContextType *pMsgContext
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
Std_ReturnType Rte_Call_DcmExt_SWC_DID_DiagAction(uint8 OpStatus, Dcm_DspDidIdentifierTableType Did, Dcm_MsgType Data, Dcm_NegativeResponseCodeType *pNrc, uint8 Action)
{
 return E_OK;
}

void DcmExt_Init(void)
{
  DcmExt_NvmNrc = 0x0u;
  DcmExt_NvmReturn = DCM_E_FORCE_RCRRP;
  Dcm_NvMDefaultWriteState = DCM_NVM_IDLE;
  Dcm_nvm_BlockWrite_State = DCM_NVM_IDLE;
  Dcm_NvMError = FALSE;
}

Std_ReturnType DcmExt_PerformReset_001(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *pNegRes)
{
	Std_ReturnType RetVal = E_NOT_OK;

	if(flagHardReset == RESET_NOT_REQUESTED)
	{
		RetVal = CUpdateCdd_UpdateCdd_GenericResetHandler( pNegRes);

		if(RetVal == E_OK)
		{
			flagHardReset = RESET_INITIATED;
		}
	}

	return RetVal;
}

void DcmExt_MainFunction(void)
{
    Std_ReturnType ErrorCode = 0u;

	if(ProgSessionStatus != TRUE)
	{
		// Switch to Programming sesssion after entering into Bootloader to trigger a reset after S3 timeout.
		KeepNonDefaultSessionActive(0x02, 0x01);

		// Set the S3 Server to trigger a reset after the S3 timeout.
		Dcm_StartTimer(0x04);

		ProgSessionStatus = TRUE;
	}

	if(RESET_INITIATED == flagHardReset)
	{
		SessionReset_Timeout--;

		if(SessionReset_Timeout == TIMER_ELAPSED)
		{
			flagHardReset = RESET_NOT_REQUESTED;

			Mcu_PerformReset();
		}
	}
	if(SessionChangeRequest == TRUE)
	{
		if(DcmExt_PerformReset_001(ErrorCode, &ErrorCode) == E_OK)
		{
			SessionChangeRequest = FALSE;
		}
	}
}

/**************************************************************************
 Function name       : DcmExt_60DiagProcess
 Description         :
 Parameters (in)     : Dcm_OpStatusType OpStatus,
 Parameters (out)    : Dcm_NegativeResponseCodeType *pNegRes
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
Std_ReturnType DcmExt_60DiagProcess(Dcm_OpStatusType OpStatus,   Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType *pNegRes)
{
  Std_ReturnType RetVal;
  RetVal = DCM_E_NOT_OK;

  if(FALSE != DCMEXT_DIAG_ENTRY_CONDITION_CHECK(pMsgContext, pNegRes))
  {
    DslInternal_SetSesCtrlType(0x03);
    RetVal = DCM_E_OK;

  }
  return (RetVal);
}


Std_ReturnType DI_Did_Diag_Action(Dcm_OpStatusType OpStatus, uint8 Did_action, Dcm_DspDidIdentifierTableType Did,
                                  const Dcm_MsgLenType ReqLength, Dcm_MsgType Buff,
                                  Dcm_MsgLenType* Length, Dcm_NegativeResponseCodeType *pNegRes)
{

  Std_ReturnType RetVal;
  RetVal = DCM_E_NOT_OK;
  *pNegRes = 0x31;
  if (DCM_DSP_DID_READ == Did_action)
  {
    switch (Did)
    {
	case 0xFEF6:
       RetVal = DcmExt_Service_DataRead_FEF6(OpStatus, Buff);
       *Length = (Dcm_MsgLenType)RDBI_0xFEF6_BYTELENGTH;
       break;
    case 0xF188:
    	RetVal = DcmExt_Service_DataRead_F188(OpStatus, Buff);
    	*Length = (Dcm_MsgLenType)RDBI_0xF188_BYTELENGTH;
    	break;
    case 0xF122:
    	RetVal = DcmExt_Service_DataRead_F122(OpStatus, Buff);
    	*Length = (Dcm_MsgLenType)RDBI_0xF122_BYTELENGTH;
    	break;
    }
  }
  else if (DCM_DSP_DID_WRITE == Did_action)
  {
	  switch (Did)
	  {
		case 0xFD27:
			RetVal = DcmExt_Service_DataWrite_FD27(OpStatus, pNegRes, Buff);
			break;
		case 0xFD28:
			RetVal = DcmExt_Service_DataWrite_FD28(OpStatus, pNegRes, Buff);
			break;
	  }
  }
  else
  {
    /*do nothing*/
  }
  return RetVal;
}

void DcmExt_WdgM_PerformReset(void)
{
  //WDGM_TRIGGER_WATCHDOG(0);
  //Mcu_PerformReset();
}

extern Std_ReturnType DI_Rid_Diag_Action(Dcm_OpStatusType OpStatus, uint8 Rid_action, Dcm_DspRidIdentifierTableType Rid,
                                         const Dcm_MsgLenType ReqLength, Dcm_MsgType Buff,
                                         Dcm_MsgLenType* RespLength, Dcm_NegativeResponseCodeType* pNegRes)
{
  Std_ReturnType Ret_Val = E_NOT_OK;
  uint8 index = 0u;

  switch(Rid)
  {
    case OTA_ERASE_ROUTINE_ID:
	case OTA_VALIDATE_ROUTINE_ID:
	case OTA_ACTIVATE_ROUTINE_ID:
	case OTA_ROLLBACK_ROUTINE_ID:
	case OTA_ACTIVATION_COMPLETE_ROUTINE_ID:
	case OTA_SYNC_ROUTINE_ID:
	{
		Ret_Val = CUpdateCdd_UpdateCdd_GenericRIDRequestHandler(OpStatus, Rid_action, Rid, ReqLength, Buff, RespLength, pNegRes);

		break;
	}
    case 0x0203:
    case 0x0304:
    case 0x0405:
    case 0x0506:
    case 0x0607:
    default:
      *pNegRes = 0x31u;
      * RespLength = 0x0u;
      Ret_Val = E_NOT_OK;
   break;
  }
  return Ret_Val;

}

Std_ReturnType STPCDD_Did_DiagAction(Dcm_OpStatusType OpStatus, uint8 eDcmExt_IOCtrl, Dcm_DspDidIdentifierTableType Did, \
    const Dcm_MsgLenType ReqLength, Dcm_MsgType Buff, Dcm_MsgLenType* Length, Dcm_NegativeResponseCodeType *NegRes)
{
    return E_OK;
}

Std_ReturnType WDGMGR_Did_DiagAction(Dcm_OpStatusType OpStatus, uint8 eDcmExt_IOCtrl, Dcm_DspDidIdentifierTableType Did, \
    const Dcm_MsgLenType ReqLength, Dcm_MsgType Buff, Dcm_MsgLenType* Length, Dcm_NegativeResponseCodeType *NegRes)
{
    return E_OK;
}

Std_ReturnType DcmExt_SecLevel1GetSeed(Dcm_OpStatusType OpStatus, Dcm_MsgType Buff, uint8 SubFunction, Dcm_NegativeResponseCodeType *NegRes,Dcm_SesCtrlType flSession)
{
	Std_ReturnType RetVal = DCM_E_NOT_OK;

	*NegRes = DCM_E_CONDITIONSNOTCORRECT;

	if(Csm_RandomGenerate(CsmJobID_RNG, &RandomNumberArray[0], &Service_27_01_KeyLength) == 0)
	{
		if(Csm_KeyElementSet(CsmKeyID_EcbEncrypt,0, &Service_27_01_Key[0],sizeof(Service_27_01_Key)) == 0)
		{
			if(Csm_KeySetValid(CsmKeyID_EcbEncrypt) == 0)
			{
				/* In our testing enviorment, we cannot encrypt the random number every time. So, we are using the DummyRandomNumberArray as the random number for testing.
				This has to be changed to RandomNumber when we have the testing enviroment to encrypt it every time or any OEM Tool */
				//if(Csm_Encrypt(CsmKeyID_EcbEncrypt, CRYPTO_OPERATIONMODE_SINGLECALL, &RandomNumberArray[0], Service_27_01_KeyLength, &EncryptedDataArray[0], &Service_27_01_KeyLength) == 0)

				if(Csm_Encrypt(CsmKeyID_EcbEncrypt, CRYPTO_OPERATIONMODE_SINGLECALL, &DummyRandomNumberArray[0], Service_27_01_KeyLength, &EncryptedDataArray[0], &Service_27_01_KeyLength) == 0)
				{
					memcpy( Buff, DummyRandomNumberArray, Service_27_01_KeyLength);

					RetVal = DCM_E_OK;

					*NegRes = DCM_E_POSITIVERESPONSE;
				}
			}
		}
	}

  return RetVal;

}

Std_ReturnType DcmExt_SecLevel3GetSeed(Dcm_OpStatusType OpStatus, Dcm_MsgType Buff,  uint8 SubFunction, Dcm_NegativeResponseCodeType *NegRes, Dcm_SesCtrlType Session)
{
  /*Commented code removed - MISRA snaray12*/
	*NegRes = DCM_E_POSITIVERESPONSE;
  return DCM_E_OK;
}

Std_ReturnType DcmExt_SecLevel1CmpKey(Dcm_OpStatusType OpStatus, Dcm_MsgType Buff,   uint8 SubFunction, Dcm_NegativeResponseCodeType *NegRes, Dcm_SesCtrlType Session)
{
	Std_ReturnType RetVal;

	*NegRes = DCM_E_CONDITIONSNOTCORRECT;

	if(memcmp(Buff, EncryptedDataArray, Service_27_01_KeyLength) == 0)
	{
		RetVal = DCM_E_OK;

		*NegRes = DCM_E_POSITIVERESPONSE;
	}
	else
	{
		RetVal = DCM_E_NOT_OK;
	}

	return RetVal;
}
Std_ReturnType DcmExt_SecLevel3CmpKey(Dcm_OpStatusType OpStatus, Dcm_MsgType Buff,   uint8 SubFunction, Dcm_NegativeResponseCodeType *NegRes, Dcm_SesCtrlType Session)
{
  uint32 key;
  Std_ReturnType ret_val;
  static uint32 SecurityLevel3_SeedSend;
  /*key = 0x684307A7 */
  key = (SecurityLevel3_SeedSend + 0x19172015u) ^ (SecurityLevel3_SeedSend + 0x31581972u);
  if ((Buff[0] == (uint8) (key >> 24)) && (Buff[1] == (uint8) (key >> 16)) && (Buff[2] == (uint8) (key >> 8))
      && (Buff[3] == (uint8) (key >> 0)))
  {
    ret_val = DCM_E_OK;
    *NegRes = DCM_E_POSITIVERESPONSE;
  }
  else
  {
    ret_val = DCM_E_NOT_OK;
  }
  SecurityLevel3_SeedSend = 0;
  return ret_val;
}

Std_ReturnType DcmExt_Communication_action(Dcm_OpStatusType OpStatus, uint8 ComM_Type, uint8 ComM_Action)
{

  /* The below code is added for testing the Implementation.
   Once the Inteface functon is avilable which can be called here.

   Ex: Std_ReturnType App_Comm_control(Com_action)
   ret_val = DCM_E_OK;
   *Length = 0;
   */
  Std_ReturnType ret_val;

  (void)ComM_Type;
  switch (ComM_Action)
  {
  case DCM_ENABLE_RX_TX_NORM:
    //Ccl_Dcm_CommCtrl_Sf00(DCM_ENABLE_RX_TX_NORM); /* Not tested added for compilation purpose - msavariy */
    ret_val = DCM_E_OK;
    break;
  case DCM_DISABLE_RX_TX_NORMAL:
    //Ccl_Dcm_CommCtrl_Sf00(DCM_DISABLE_RX_TX_NORMAL);
    ret_val = DCM_E_OK;
    break;
  case DCM_ENABLE_RX_TX_NM:
  case DCM_DISABLE_RX_TX_NM:
  case DCM_ENABLE_RX_TX_NORM_NM:
  case DCM_DISABLE_RX_TX_NORM_NM:
    ret_val = DCM_E_NOT_OK;
    break;
  default:
    ret_val = DCM_E_NOT_OK;
    break;
  }

  return ret_val;
}

#if(DCMEXT_PROG_MAGIC_FLAG_HANDLER == STD_ON)
Std_ReturnType DcmExt_SetProgFlag(Dcm_NegativeResponseCodeType *pNegRes)
{

  return DCM_E_OK;
}
#endif

void DcmExt_Pre_notification_clear (void)
{

}
void DcmExt_End_notification_clear (void)
{

}

Std_ReturnType DcmExt_Mfg_Condition_check (Dcm_NegativeResponseCodeType *NegRes)
{
  Std_ReturnType RetVal;
  RetVal = DCM_E_OK;
  *NegRes = DCM_E_OK;

  return (RetVal);
}

Std_ReturnType DcmExt_Diag_Condition_check(Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType *NegRes)
{
  *NegRes = DCM_E_OK;
  return DCM_E_OK;
}


Std_ReturnType DcmExt_Prog_Condition_check(Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType *NegRes)
{
  *NegRes = DCM_E_OK;
  return DCM_E_OK;
}

Std_ReturnType DcmExt_Vehicle_Condition_check(Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType *NegRes)
{
  Std_ReturnType res = DCM_E_OK;
  *NegRes = DCM_E_OK;
  /*if (RevolutionsPerMinute_Output != 0)
   {
   NegRes = 0x83;
   }
   if (s_Speed_Calculated != 0)
   {
   NegRes = 0x88;
   }

   */
  return res;
}

Std_ReturnType DcmExt_Vehicle_Condition_check_1(Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType *NegRes)
{
  Std_ReturnType res = DCM_E_OK;
  *NegRes = DCM_E_OK;
  /*if (RevolutionsPerMinute_Output != 0)
   {
   NegRes = 0x83;
   }
   if (s_Speed_Calculated != 0)
   {
   NegRes = 0x88;
   }

   */
  return res;
}
Std_ReturnType DcmExt_28SVehicle_Condition_check(Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType *NegRes)
{
//  uint8 s_Clamp_15 = 0;
//  Std_ReturnType res = DcmExt_Vehicle_Condition_check(NegRes);
//  if ((uint8) E_OK == res)/*MISRA CID 18029315*/
//  {
//    if (0u != s_Clamp_15)/*MISRA CID 18059551*/
//    {
//      *NegRes = 0x22;
//      res = DCM_E_NOT_OK;
//    }
//  }
//  return res;
  *NegRes = DCM_E_OK;
  return DCM_E_OK;
}

Std_ReturnType DcmExt_Vehicle_SpeedCondition_check(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType *NegRes)
{
  *NegRes = DCM_E_OK;
  return DCM_E_OK;
}

Std_ReturnType Dcm_ClearDTCCheckFnc(uint32 GoDTC, Dcm_NegativeResponseCodeType* ErrorCode)
{
	return DCM_E_OK;
}

Std_ReturnType DcmExt_3DStatus_Vehicle_Condition_check(Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType *NegRes)
{
  *NegRes = DCM_E_OK;
  return DCM_E_OK;
}



#if((DcmDsdRequestManufacturerNotificationEnabled == STD_ON) || (DcmDsdRequestSupplierNotificationEnabled == STD_ON))
Std_ReturnType DcmExt_RequestIndication_0(uint8 SID, uint8* RequestData, uint16 RequestDataSize, uint8 ReqType, uint16 SourceAddress,
                                          uint8* RespData, uint16* RespDataSize, Dcm_NegativeResponseCodeType* ErrorCode )
{
/*
example how to use
possible responses:
  DCM_E_PROCESSING_DONE -- positive response, but bypass further SID execution, everything is done in XXX_Indication()
  DCM_E_OK              -- positive response, used in case of precondition checks
  DCM_E_NOT_OK          -- negative response, used in case of precondition checks
  DCM_E_REQUEST_NOT_ACCEPTED -- negative response (hide diag response), used in case of precondition checks

  if(SID == 0x10)
  {
    if(RequestData[0] == 0x05)
    {
      *ErrorCode = 0x10;
      return DCM_E_NOT_OK;
    }
    else if(RequestData[0] == 0x04)
    {
      *ErrorCode = 0x10;
      return DCM_E_REQUEST_NOT_ACCEPTED;
    }
  }
*/
  return DCM_E_OK;
}

Std_ReturnType DcmExt_RequestIndication_1(uint8 SID, uint8* RequestData, uint16 RequestDataSize, uint8 ReqType, uint16 SourceAddress,
                                          uint8* RespData, uint16* RespDataSize, Dcm_NegativeResponseCodeType* ErrorCode )
{
  return DCM_E_OK;
}
#endif

#if(S27_FAIL_COUNT_NVM_SUPPORTED == TRUE)
Std_ReturnType SaveFailCounter(uint8 *counter)
{
  S27_Saved_Counter = *counter;
  S27_Saved_Counter_Flag = TRUE;
  return E_OK;
}

Std_ReturnType ReadFailCounter(uint8 *counter)
{
  if(S27_Saved_Counter_Flag == FALSE)
  {
    *counter = S27_Saved_Counter;
    S27_Saved_Counter_Flag = TRUE;
  }
  return E_OK;
}

boolean FailCounterIsReady(void)
{
  if(S27_Saved_Counter_Flag == FALSE)
  {
    return FALSE;
  }
  return TRUE;
}

#endif /* (S27_FAIL_COUNT_NVM_SUPPORTED == TRUE) */

/**************************************************************************
 Function name   : void DcmExt_Confirmation
 Arguments       : Std_ReturnType result
 Return type     : void
 Description     : The result indicates whether the diag response
 transmission was successful or not.
 **************************************************************************/
void DcmExt_Confirmation(Std_ReturnType Result)
{

}

#if(DCM_SVC_34_SUPPORT_ENABLED == STD_ON)
Std_ReturnType DcmExt_ProcessRequestDownload(Dcm_OpStatusType OpStatus, uint8 DataFormatIdentifier, uint32 MemoryAddress, uint32 MemorySize,
    uint32* BlockLength, Dcm_NegativeResponseCodeType* ErrorCode)
{
	Std_ReturnType RetVal= E_OK;

	RetVal = CUpdateCdd_UpdateCdd_GenericRequestDownloadHandler(OpStatus, DataFormatIdentifier, MemoryAddress, MemorySize, BlockLength, ErrorCode);

	return RetVal;
}
#endif

#if(DCM_SVC_35_SUPPORT_ENABLED == STD_ON)
Std_ReturnType DcmExt_ProcessRequestUpload(Dcm_OpStatusType OpStatus, uint8 DataFormatIdentifier, uint32 MemoryAddress, uint32 MemorySize,
    uint32* BlockLength, Dcm_NegativeResponseCodeType* ErrorCode)
{
  Std_ReturnType RetVal= E_OK;

  if(MemorySize<*BlockLength)
  {
    *BlockLength= MemorySize;
  }
  else
  {
    *BlockLength = 0xFF;
  }
	// *ErrorCode needs to update
	 OpStatus= DCM_INITIAL;
   *ErrorCode = DCM_E_POSITIVERESPONSE;
	 return RetVal;
}
#endif

#if(DCM_SVC_36_SUPPORT_ENABLED == STD_ON)
Dcm_ReturnWriteMemoryType DcmExt_WriteMemory (Dcm_OpStatusType OpStatus,uint8 MemoryIdentifier,uint32 MemoryAddress,uint32 MemorySize,
      const uint8* MemoryData,Dcm_NegativeResponseCodeType* ErrorCode)
{
  Std_ReturnType RetVal= E_OK;

  RetVal = CUpdateCdd_UpdateCdd_GenericTransferDataHandler(OpStatus, MemoryIdentifier, MemoryAddress, MemorySize, MemoryData, ErrorCode);

  return RetVal;
}

Dcm_ReturnReadMemoryType DcmExt_ReadMemory(Dcm_OpStatusType OpStatus,uint8 MemoryIdentifier,uint32 MemoryAddress,uint32 MemorySize,
      uint8* MemoryData,Dcm_NegativeResponseCodeType* ErrorCode)
{
  Std_ReturnType RetVal= E_OK;
  OpStatus= DCM_INITIAL;
  // read data from the memory from memory address mentioned & with the size that given
  // Set the response message
  *ErrorCode = DCM_E_POSITIVERESPONSE;
  return RetVal;
}
#endif

#if(DCM_SVC_37_SUPPORT_ENABLED == STD_ON)
Std_ReturnType DcmExt_ProcessRequestTransferExit(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode)
{
  Std_ReturnType RetVal = E_NOT_OK;

  RetVal = CUpdateCdd_UpdateCdd_GenericTransferExitHandler(OpStatus, 0u, 0u, NULL, NULL, ErrorCode);

  return RetVal;
}

#endif

void DcmExt_BroadCast_SessionChangeStatus(uint8 SubFunction, uint8 Source)
{
	if(DIAG_TIMEOUT == Source)
	{
		SessionChangeRequest = TRUE;
	}
}

Std_ReturnType DcmExt_Service_DataRead_F188(uint8 OpStatus,Dcm_MsgType Data)
{
  Std_ReturnType RetVal = E_NOT_OK;
  Dcm_NegativeResponseCodeType pNrc = 0;
  RetVal = Rte_Call_DcmExt_SWC_DID_DiagAction(OpStatus, 0xF188, Data, &pNrc, eREAD);
  if(pNrc != E_OK)
  {
    RetVal = E_NOT_OK;
  }
  return RetVal;
}

Std_ReturnType DcmExt_Service_DataRead_F122(uint8 OpStatus,Dcm_MsgType Data)
{
  Std_ReturnType RetVal = E_NOT_OK;
  Dcm_NegativeResponseCodeType pNrc = 0;
  RetVal = Rte_Call_DcmExt_SWC_DID_DiagAction(OpStatus, 0xF122, Data, &pNrc, eREAD);
  if(pNrc != E_OK)
  {
    RetVal = E_NOT_OK;
  }
  return RetVal;
}

Std_ReturnType DcmExt_Service_DataRead_FEF6(uint8 OpStatus,Dcm_MsgType Data)
{
  Std_ReturnType RetVal = DCM_E_OK;

  uint8 ReadData_value[RDBI_0xFEF6_BYTELENGTH]={1};
  memcpy(Data, &ReadData_value,RDBI_0xFEF6_BYTELENGTH);
  return RetVal;
}

Std_ReturnType DcmExt_Service_DataWrite_FD27(uint8 OpStatus, Dcm_NegativeResponseCodeType *pNegRes, Dcm_MsgType Data)
{
  Std_ReturnType RetVal = E_NOT_OK;
  RetVal = Rte_Call_DcmExt_SWC_DID_DiagAction(OpStatus, 0xFD27, Data, pNegRes, eWRITE);
  return RetVal;
}

Std_ReturnType DcmExt_Service_DataWrite_FD28(uint8 OpStatus, Dcm_NegativeResponseCodeType *pNegRes, Dcm_MsgType Data)
{
  Std_ReturnType RetVal = E_NOT_OK;
  RetVal = Rte_Call_DcmExt_SWC_DID_DiagAction(OpStatus, 0xFD28, Data, pNegRes, eWRITE);
  return RetVal;
}

Std_ReturnType SecLevel5GetSeed(Dcm_MsgType Buff, Dcm_NegativeResponseCodeType *NegRes)
{
  /*Commented code removed - MISRA snaray12*/
  return DCM_E_OK;
}

Std_ReturnType SecLevel5CmpKey(Dcm_MsgType Buff, Dcm_NegativeResponseCodeType *NegRes)
{
  /*Commented code removed - MISRA snaray12*/
  return DCM_E_OK;
}

Std_ReturnType SecLevel5EOLGetSeed(Dcm_MsgType Buff, Dcm_NegativeResponseCodeType *NegRes)
{
  /*Commented code removed - MISRA snaray12*/
  return DCM_E_OK;
}

Std_ReturnType SecLevel5EOLCmpKey(Dcm_MsgType Buff, Dcm_NegativeResponseCodeType *NegRes)
{
  /*Commented code removed - MISRA snaray12*/
  return DCM_E_OK;
}

Std_ReturnType SecLevel4GetSeed(Dcm_MsgType Buff, Dcm_NegativeResponseCodeType *NegRes)
{
  /*Commented code removed - MISRA snaray12*/
  return DCM_E_OK;
}

Std_ReturnType SecLevel4CmpKey(Dcm_MsgType Buff, Dcm_NegativeResponseCodeType *NegRes)
{
  /*Commented code removed - MISRA snaray12*/
  return DCM_E_OK;
}

void DcmExt_BroadCast_SecurityChangeStatus(uint8 SubFunction, uint8 Source)
{
}

void DcmExt_2F_RCTUChange(Dcm_DspDidIdentifierTableType Did, Dcm_NegativeResponseCodeType *NegRes)
{
}

void DcmExt_NotificationOnDTCStatus(uint32 DTC, Dem_UdsStatusByteType DTCStatusOld, Dem_UdsStatusByteType DTCStatusNew)
{
}

#endif

/*****************************************************************************
 Date          : 21-Nov-2019
 By              : snaray12
 Traceability    : RTC #667189
 Change Description  : MISRA Warning fixed
 *****************************************************************************/
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
/*Date              : 18-Jan-2022                                           */
/*Version           :                                                       */
/*By                : iiliev1                                               */
/*Traceability      : Rtc#1560389                                           */
/*Change Description: DCM and DEM Autosar 4.2.2 Migration                   */
/*--------------------------------------------------------------------------*/
