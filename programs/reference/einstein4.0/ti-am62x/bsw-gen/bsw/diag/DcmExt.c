//---------------------------------------------------------------------------------------------------------------------
// 
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2015] Visteon Corporation
// All Rights Reserved.
//
// NOTICE: This is an unpubliHed work of authorship, which contains trade secrets.
// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
// or those of any othis country that may have jurisdiction, to protect this work as an unpubliHed work,
// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
// under all copyright laws to protect this work as a publiHed work, when appropriate.
// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
// without the written authorization of Visteon Corporation.
//
//---------------------------------------------------------------------------------------------------------------------
/* PRQA S 0857, 0828 EOF *//* MD_MSR_1.1_857, MD_MSR_1.1_828 */
#include "Dcm.h"
#include "Dcm_Types.h"
#include "NvM.h"
#include "Dcm_Internal.h"
#include "Dcm_Cfg.h"
#include "Dem_Cfg.h"
#include <string.h>
#include "Rte_DcmExt.h"
#include "NvM_Cfg.h"
#include "RstM.h"
#include "Csm.h"
//#include "CanCcl.h"
//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================

//=====================================================================================================================
//  FORWARD DECLARATIONS
//=====================================================================================================================
extern Std_ReturnType DcmExt_Services_DataRead (Dcm_OpStatusType OpStatus, uint8* pDataPointer, Dcm_DspDidIdentifierTableType did, Dcm_NegativeResponseCodeType* pNrc, uint16 index);
extern Std_ReturnType DcmExt_Services_LenChk (Dcm_OpStatusType OpStatus,Dcm_NegativeResponseCodeType* pNrc, Dcm_MsgLenType* Length, Dcm_DspDidIdentifierTableType did);
extern Std_ReturnType DcmExt_Services_DataWrite (Dcm_OpStatusType OpStatus, uint8* DataPointer, Dcm_NegativeResponseCodeType* pNrc, Dcm_DspDidIdentifierTableType did, uint16 index);
extern Std_ReturnType DcmExt_Services_CndChk (Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode, 
                                              Dcm_DspDidIdentifierTableType did);
extern Std_ReturnType DcmExt_Service_Iocontrol(Dcm_OpStatusType OpStatus, uint8 *DataPointer, uint8 *pNrc, 
                                               Dcm_DspDidIdentifierTableType did);

extern Std_ReturnType DcmExt_Services_RoutineStart (
    Dcm_OpStatusType OpStatus, uint8 *pOut_RoutineInfo, Dcm_MsgLenType *RespLength,
    Dcm_NegativeResponseCodeType *pNrc, Dcm_DspRidIdentifierTableType Rid);
extern Std_ReturnType DcmExt_Services_RoutineStop (
    Dcm_OpStatusType OpStatus, uint8 *pOut_RoutineInfo, Dcm_MsgLenType *RespLength,
    Dcm_NegativeResponseCodeType *pNrc, Dcm_DspRidIdentifierTableType Rid);
extern Std_ReturnType DcmExt_Services_RoutineResults (
    Dcm_OpStatusType OpStatus, uint8 *pOut_RoutineInfo,
    uint8 *Out_Results_Response, Dcm_MsgLenType *DataLength, Dcm_NegativeResponseCodeType *pNrc,
    Dcm_DspRidIdentifierTableType Rid);

static Std_ReturnType DcmExt_GetDefaultWriteStatus_DiagAction(Dcm_OpStatusType OpStatus, uint8 *Data , uint8 *pNrc, uint8 eOperation);
static void  DcmExt_NvMTestFunction(void);


//=====================================================================================================================
//  PRIVATE
//=====================================================================================================================

//=====================================================================================================================
//  PUBLIC
//=====================================================================================================================
/* ----------------------------------------------
 ~&&&   Versions
 ---------------------------------------------- */

/**************************************************************************
 Function name       : Std_ReturnType STPCDD_Did_DiagAction(Dcm_MsgContextType *pMsgContext)
 Description         :
 Parameters (in)     : Dcm_MsgContextType *pMsgContext
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
#define DCM_DSP_DID_READ          0x01u
#define DCM_DSP_DID_WRITE         0x02u
#define DCM_DSP_DID_IO            0x04u
#define IOC_OPTION_BYTE_SIZE      0x01u

#define DCM_DSP_RID_START          0x01
#define DCM_DSP_RID_STOP           0x02
#define DCM_DSP_RID_RESULTS        0x03

# define DCM_IO_RETCTRL2ECU        0x00u
# define DCM_IO_RST2DEFAULT        0x01u
# define DCM_IO_FREEZECURRENTSTATE 0x02u
# define DCM_IO_SHRTTRMADJ         0x03u

typedef enum
{
  eDcmExt_CondCheck_Opstatus,
  eDcmExt_LenCheck_Opstatus,
  eDcmExt_Read_Opstatus
} DcmExt_Opstatustype;

static DcmExt_Opstatustype DcmExt_IntOpstatus = eDcmExt_CondCheck_Opstatus;
static volatile Dcm_OpStatusType DcmExt_OpStatus = DCM_INITIAL;
static uint8 DummyRandomNumberArray[16] = {0x1c, 0xd5, 0xf8, 0xe9, 0xb7, 0xe8, 0x09, 0xf3, 0x91, 0x97, 0x0b, 0xe8, 0x91, 0xfa, 0x8e, 0x32};
static uint8 RandomNumberArray[16];
static uint8 EncryptedDataArray[16];
static uint32 Service_27_01_KeyLength = 16;
static uint8 Service_27_01_Key[16] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF};


//uint16 DcmExt_Didinfo_Size = DcmNumOfDIDSupported;
#define DcmExt_Didinfo_Size  DcmNumOfDIDSupported /*MISRA CID 10596371*/
#define DcmExt_Ridinfo_Size  DcmNumOfRIDSupported
#define DCM_EXT_PENDING (uint8)0x0A /* MISRA CID 19648709*/

#define NVM_BLOCK_WRITE
#define NVM_WRITE_DID                       0x01U
#define NVM_DEFAULT_WRITE_DID 0xDEFA
#define RESET_HISTORY_DID 0xFE36
#define APP_HANDLER                    			0x00u
#define MEET_HANDLER                   			0x01u
#define JUMPTOBOOTMAXTIME						(10u)
// #define FIT_DID 0x4F09

#define OTA_ERASE_ROUTINE_ID					(0xFF00)
#define OTA_VALIDATE_ROUTINE_ID					(0xFF01)
#define OTA_ACTIVATE_ROUTINE_ID					(0xFE00)

#ifdef NVM_BLOCK_WRITE
typedef enum
{
    NVM_TEST_IDLE,
    NVM_TEST_INITIATE,
    NVM_TEST_ENABLE_WRITE_PROTECT_ALL_BLOCKS,
    NVM_TEST_WAIT_EXISTING_BLOCKS_COMPLETE,
    NVM_TEST_WRITE_BLOCK_INITATE,
    NVM_TEST_WRITE_BLOCK_WAIT,
    NVM_TEST_READ_BLOCK_INITIATE,
    NVM_TEST_READ_BLOCK_WAIT,
    NVM_TEST_VALIDATE_WRITE_AND_READ,
    NVM_TEST_COMPLETE,
    NVM_TEST_DISABLE_WRITE_PROTECT_ALL_BLOCKS
}NvM_StateMachineType;

typedef enum
{
    NVM_BLOCK_TEST_NOT_INITIATED,
    NVM_BLOCK_TEST_INITAITED,
    NVM_BLOCK_TEST_WRITE_REQUEST_NOT_ACCEPTED,
    NVM_BLOCK_TEST_WRITE_REQUEST_ACCEPTED_RESULT_PENDING,
    NVM_BLOCK_TEST_WRITE_REQUEST_FAILED,
    NVM_BLOCK_TEST_WRITE_REQUEST_COMPLETED,
    NVM_BLOCK_TEST_READ_REQUEST_NOT_ACCEPTED,
    NVM_BLOCK_TEST_READ_REQUEST_ACCEPTED_RESULT_PENDING,
    NVM_BLOCK_TEST_READ_REQUEST_FAILED,
    NVM_BLOCK_TEST_READ_REQUEST_COMPLETED,
    NVM_BLOCK_TEST_COMPLETED_VALIDATION_FAILED,
    NVM_BLOCK_TEST_COMPLETED_SUCCESSFULLY,
}NvM_BlockResultType;


typedef enum
{
    NVM_TEST_INITAITED,
    NVM_TEST_PROGRESS,
    NVM_TEST_FAILED,
    NVM_TEST_SUCCESS
}NvM_ResultType;


typedef struct
{
  uint16                      CurrentTestBlockId;
  NvM_BlockResultType         NvMBlockTestResult[NVM_NUM_OF_BLOCKS];
  NvM_ResultType              TestStatus;
  uint16                      NvMTestFailiureCount;
}NvM_TestDataStructType;


NvM_StateMachineType NvM_StateMachine;

NvM_TestDataStructType NvM_DataStruct;

uint8 NvM_TWriteBuffer[NVM_WRITE_VERIFICATION_DATASIZE];
uint8 NvM_ReadBuffer[NVM_WRITE_VERIFICATION_DATASIZE];
uint16 Block_Id;


volatile uint8 NvM_InitiateNvMTesting = 0;
uint8 status;
uint8  flashconstantsValidStarttest[16];
static void DcmExt_NvM_BlockTest(void);
volatile uint8 L_state_u8 = 0;
uint8 L_blockStatus_u8 = 0;
volatile uint16 L_blockId_u16 = 0xFFFF;
#endif
/*Did info type for dcmext*/
typedef struct
{
  uint16 Did_Id;
  uint16 Did_Length;
  uint8 Condition_Type;
  uint8 CallType; 
} DcmExt_Didinfo_Type;

/*Did info for dcmext*/
/*const static DcmExt_Didinfo_Type DcmExt_Didinfo[DcmExt_Didinfo_Size] = */

uint32 NvM_WriteBuffer =  0xAA55AA55;  //magic flag value for bootloader
// static boolean Magic_WriteFlag = FALSE;

static DcmExt_Didinfo_Type DcmExt_Didinfo[DcmExt_Didinfo_Size] =
{
    { 0x1111, 2u, 0u ,MEET_HANDLER},
    { 0x2222, 10u, 0u,MEET_HANDLER},
    { 0x3333, 32u, 0u,MEET_HANDLER},
    { 0x4444, 5u, 0u, MEET_HANDLER},
    { 0x5555, 8u, 1u, MEET_HANDLER},
    { 0x6666, 4u, 0u, MEET_HANDLER},
    { 0x7777, 7u, 0u, MEET_HANDLER},
    { 0x8888, 6u, 0u, MEET_HANDLER},
    { 0x9999, 3u, 0u, MEET_HANDLER},
    { 0xAAAA, 4u, 0u, MEET_HANDLER},
    { 0XDEFA, 2u, 0u, APP_HANDLER},
    { 0xFD00, 17u, 0u,MEET_HANDLER},
    { 0XFD01, 17u, 0u,MEET_HANDLER},
    { 0XFD02, 10u, 0u,MEET_HANDLER},
    { 0XFD04, 3u, 0u, MEET_HANDLER},
    { 0XFD05, 3u, 0u, MEET_HANDLER},
    { 0XFD07, 3u, 0u, MEET_HANDLER},
    { 0XFD08, 3u, 0u, MEET_HANDLER},
    { 0XFD45, 9u, 0u, MEET_HANDLER},
    { 0xFD60, 1u, 0u, MEET_HANDLER},
    { 0XFD6B, 2u, 0u, MEET_HANDLER},
    { 0xF781, 5u, 0u, MEET_HANDLER},
    { 0xFE30, 33u, 0u,MEET_HANDLER},
    { 0xFE31, 1u, 0u, MEET_HANDLER},
    { 0xFE32, 1u, 0u, MEET_HANDLER},
    { 0xFE35, 2u, 0u, MEET_HANDLER},
    { 0xFE36, 60u, 0u, APP_HANDLER},
};
static const uint16 DcmExt_DspRidIdentifierTable[DcmExt_Ridinfo_Size ] =
  {/*MISRA 19648482*/
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

boolean Jump_to_BootFlag = FALSE;
uint32 Jump_to_BootTimer = 0u;

Std_ReturnType DcmExt_Services_DataRead (Dcm_OpStatusType OpStatus, uint8* pDataPointer, Dcm_DspDidIdentifierTableType did, Dcm_NegativeResponseCodeType* pNrc, uint16 index) /*MISRA CID 19649046*/
{
	//need RTE call
  Std_ReturnType flRetVal = E_NOT_OK;
  if(MEET_HANDLER == DcmExt_Didinfo[index].CallType)
  {
    flRetVal = Rte_Call_rp_CS_DID_DiagAction_DID_DiagAction (OpStatus, did,pDataPointer, pNrc,eRead);
  }
  else if (APP_HANDLER == DcmExt_Didinfo[index].CallType)  
  {
    if(RESET_HISTORY_DID ==DcmExt_Didinfo[index].Did_Id)
    {
      flRetVal = DcmExt_ResetHistory_DiagAction(DcmExt_OpStatus,(uint8*)pDataPointer, &pNrc, eRead);
    }
    else if(NVM_DEFAULT_WRITE_DID ==DcmExt_Didinfo[index].Did_Id)
    {
      flRetVal = DcmExt_GetDefaultWriteStatus_DiagAction(DcmExt_OpStatus,(uint8*)pDataPointer, &pNrc, eRead);
    }

  }
  return flRetVal;
}

Std_ReturnType DcmExt_Services_LenChk(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType* pNrc, Dcm_MsgLenType* Length, Dcm_DspDidIdentifierTableType did)/*MISRA  CID 19648159*/
{
	//need RTE call
  Std_ReturnType flRetVal = E_NOT_OK;
  uint16 DataPointer = 0u;
  flRetVal = Rte_Call_rp_CS_DID_DiagAction_DID_DiagAction (OpStatus, did, (uint8*)&DataPointer, 
                                                                        &pNrc, eLengthCheck);
  *Length = DataPointer;
  return flRetVal;
}

Std_ReturnType DcmExt_Services_DataWrite (Dcm_OpStatusType OpStatus, uint8* DataPointer, Dcm_NegativeResponseCodeType* pNrc, Dcm_DspDidIdentifierTableType did, uint16 index )/*MISRA CID 19647753*/
{
  Std_ReturnType flRetVal = E_NOT_OK;
  if(MEET_HANDLER == DcmExt_Didinfo[index].CallType)  /*For Meet related DIDs*/
  {
    //need RTE call
    flRetVal = Rte_Call_rp_CS_DID_DiagAction_DID_DiagAction (OpStatus, did, (uint8*) DataPointer,
                                                                              &pNrc, eWrite);
  }
  else if (APP_HANDLER == DcmExt_Didinfo[index].CallType)
  {
    #ifdef NVM_BLOCK_WRITE
    if(NVM_DEFAULT_WRITE_DID ==DcmExt_Didinfo[index].Did_Id)
    {
      flRetVal = DcmExt_NVMWRITEDID_DiagAction(DcmExt_OpStatus,(uint8*)DataPointer, &pNrc, eWrite);
    }
    #endif
  }
  else
  {
    /*invaild call type*/
  }
  return flRetVal;
}

Std_ReturnType DcmExt_Services_CndChk (Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *pNrc, 
                                              Dcm_DspDidIdentifierTableType did)/*MISRA CID 19648214*/
{
  Std_ReturnType flRetVal;
  uint8 DataPointer[1]={0u};
  //need RTE call
  flRetVal = Rte_Call_rp_CS_DID_DiagAction_DID_DiagAction (OpStatus, did,
                                                          DataPointer,
                                                          pNrc,
                                                          eCheckConditions);
  return flRetVal;
}

Std_ReturnType DcmExt_Service_Iocontrol(Dcm_OpStatusType OpStatus, uint8 *DataPointer, uint8 *pNrc, 
                                               Dcm_DspDidIdentifierTableType did)/*MISRA CID 19647916, 19648997*/
{
  Std_ReturnType RetVal = E_NOT_OK;
//need RTE call
  if (DataPointer[0] == DCM_IO_RETCTRL2ECU)
  {
    RetVal = Rte_Call_rp_CS_DID_DiagAction_DID_DiagAction (OpStatus, did, &DataPointer[1],
                                                          pNrc, eRCTECU);
  }
  else if (DataPointer[0] == DCM_IO_RST2DEFAULT)
  {
    RetVal = Rte_Call_rp_CS_DID_DiagAction_DID_DiagAction (OpStatus, did, &DataPointer[1],
                                                         pNrc, eRST2DEFAULT);
  }
  else if (DataPointer[0] == DCM_IO_FREEZECURRENTSTATE)
  {
    RetVal = Rte_Call_rp_CS_DID_DiagAction_DID_DiagAction (OpStatus, did, &DataPointer[1],
                                                          pNrc, eFCS);
  }
  else if (DataPointer[0] == DCM_IO_SHRTTRMADJ)
  {
    RetVal = Rte_Call_rp_CS_DID_DiagAction_DID_DiagAction (OpStatus, did, &DataPointer[1],
                                                          pNrc, eSTA);
  }
  else
  {
    /*Do nothing - MISRA snaray12*/
  }
  return RetVal;
}

/*Routine*/
/*Routine start*/
Std_ReturnType DcmExt_Services_RoutineStart (
    Dcm_OpStatusType OpStatus, uint8 *pOut_RoutineInfo, Dcm_MsgLenType *RespLength,
    Dcm_NegativeResponseCodeType *pNrc, Dcm_DspRidIdentifierTableType Rid)/*MISRA CID 19648746, 19648808*/
{
  NvM_RequestResultType NvM_Result;
  Std_ReturnType flReturnVal = E_OK;
    //need to update RTE call
  if((Rid == OTA_ERASE_ROUTINE_ID)||(Rid == OTA_VALIDATE_ROUTINE_ID)||(Rid == OTA_ACTIVATE_ROUTINE_ID))
  {
	  // OTA request.

	  flReturnVal = Rte_Call_rp_CS_UpdateCdd_RID_DiagAction_UpdateCdd_GenericRIDRequestHandler(OpStatus, eRoutineStart, Rid, *RespLength, pOut_RoutineInfo, RespLength, pNrc);

	  if((flReturnVal == E_OK)&&(Rid == OTA_ACTIVATE_ROUTINE_ID))
	  {
		  //Activation is requested. Trigger a reset to do the Switch.

		  Jump_to_BootFlag = TRUE;
	  }
  }
	else if(Rid == 0x5001)
	{
		flReturnVal = DCM_EXT_PENDING;
		if(OpStatus == DCM_INITIAL)
		{
			NvM_WriteBlock(pOut_RoutineInfo[0], NvM_BlockConfig[pOut_RoutineInfo[0]].RomBlockDataAddress);
		}
		else
		{
			NvM_GetErrorStatus(pOut_RoutineInfo[0], &NvM_Result);
			if(NVM_REQ_PENDING != NvM_Result)
			{
				flReturnVal = E_NOT_OK;
				if(NvM_Result == NVM_REQ_OK)
				{
					flReturnVal = E_OK;

				}
			}
		}
	}
 
  else
  {
	flReturnVal = Rte_Call_rp_CS_RID_DiagAction_RID_DiagAction (OpStatus, Rid, pOut_RoutineInfo, pOut_RoutineInfo, (uint16 *)RespLength, pNrc, eRoutineStart);
  }
  
  return flReturnVal;
}

/*Stop*/
Std_ReturnType DcmExt_Services_RoutineStop (
    Dcm_OpStatusType OpStatus, uint8 *pOut_RoutineInfo, Dcm_MsgLenType *RespLength,
    Dcm_NegativeResponseCodeType *pNrc, Dcm_DspRidIdentifierTableType Rid)/*19648714, 19647969*/
{
  Std_ReturnType flReturnVal;
  //need to update RTE call
  if((Rid == OTA_ERASE_ROUTINE_ID)||(Rid == OTA_VALIDATE_ROUTINE_ID)||(Rid == OTA_ACTIVATE_ROUTINE_ID))
  {
	  // OTA Erase request. 

	  flReturnVal = Rte_Call_rp_CS_UpdateCdd_RID_DiagAction_UpdateCdd_GenericRIDRequestHandler(OpStatus, eRoutineStop, Rid, *RespLength, pOut_RoutineInfo, RespLength, pNrc);
  }
  else
  {
	flReturnVal = Rte_Call_rp_CS_RID_DiagAction_RID_DiagAction (OpStatus, Rid, pOut_RoutineInfo, pOut_RoutineInfo, (uint16 *)RespLength, pNrc, eRoutineStop);
  }
  return flReturnVal;
}

/*Routine Results*/
Std_ReturnType DcmExt_Services_RoutineResults (
    Dcm_OpStatusType OpStatus, uint8 *pOut_RoutineInfo,
    uint8 *Out_Results_Response, Dcm_MsgLenType *DataLength, Dcm_NegativeResponseCodeType *pNrc,
    Dcm_DspRidIdentifierTableType Rid)/*MISRA CID 19648036, 19648698*/
{
 Std_ReturnType flRetVal = E_NOT_OK;
  //need to update RTE call
  
  if((Rid == OTA_ERASE_ROUTINE_ID)||(Rid == OTA_VALIDATE_ROUTINE_ID)||(Rid == OTA_ACTIVATE_ROUTINE_ID))
  {
	  // OTA Erase request. 

	  flRetVal = Rte_Call_rp_CS_UpdateCdd_RID_DiagAction_UpdateCdd_GenericRIDRequestHandler(OpStatus, eRoutineResult, Rid, *DataLength, pOut_RoutineInfo, DataLength, pNrc);
  }
  else
  {
	  flRetVal = Rte_Call_rp_CS_RID_DiagAction_RID_DiagAction (OpStatus, Rid, pOut_RoutineInfo, Out_Results_Response, (uint16 *)DataLength, pNrc, eRoutineResult);
  }
  return flRetVal;
}

void DcmExt_Init (void)
{

}

/**************************************************************************
 Function name       : Std_ReturnType DcmExt_42DiagProcess(void)
 Description         :
 Parameters (in)     :
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
Std_ReturnType DcmExt_42DiagProcess (Dcm_OpStatusType OpStatus,  Dcm_MsgContextType *pMsgContext,
    Dcm_NegativeResponseCodeType *NegRes)
{
  Std_ReturnType RetVal = DCM_E_NOT_OK;

  if (E_OK == DCMEXT_DIAG_ENTRY_CONDITION_CHECK(pMsgContext, NegRes))
  {
    RetVal = DCM_E_OK;
  }
  return (RetVal);
}

/**************************************************************************
 Function name       : Std_ReturnType DcmExt_60DiagProcess(void)
 Description         :
 Parameters (in)     :
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
Std_ReturnType DcmExt_60DiagProcess (Dcm_OpStatusType OpStatus,  Dcm_MsgContextType *pMsgContext,
    Dcm_NegativeResponseCodeType *NegRes)
{
  Std_ReturnType RetVal = DCM_E_NOT_OK;

  if (E_OK == DCMEXT_DIAG_ENTRY_CONDITION_CHECK(pMsgContext, NegRes))
  {
    RetVal = DCM_E_OK;
  }
  return (RetVal);
}

Std_ReturnType DcmExt_PerformReset_001 (Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *NegRes)
{
  *NegRes = DCM_E_POSITIVERESPONSE;
  return E_OK;
}

void DcmExt_MainFunction (void)
{
	if(Jump_to_BootFlag == TRUE)
	{
		Jump_to_BootTimer++;
	}

	if(Jump_to_BootTimer >= JUMPTOBOOTMAXTIME)  // Add additional preconditions to be completed beflore jumping into bootloader.
	{
		Mcu_PerformReset();
	}
  DcmExt_NvMTestFunction();
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

Std_ReturnType DcmExt_SecLevel61GetSeed(Dcm_OpStatusType OpStatus, Dcm_MsgType Buff,  uint8 SubFunction, Dcm_NegativeResponseCodeType *NegRes, Dcm_SesCtrlType Session)
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
Std_ReturnType DcmExt_SecLevel61CmpKey(Dcm_OpStatusType OpStatus, Dcm_MsgType Buff,   uint8 SubFunction, Dcm_NegativeResponseCodeType *NegRes, Dcm_SesCtrlType Session)
{
  /*Commented code removed - MISRA snaray12*/
	*NegRes = DCM_E_POSITIVERESPONSE;
  return DCM_E_OK;
}

Std_ReturnType DI_Did_Diag_Action(Dcm_OpStatusType OpStatus, uint8 Did_action, Dcm_DspDidIdentifierTableType Did, 
                                         const Dcm_MsgLenType ReqLength, Dcm_MsgType Buff, Dcm_MsgLenType* Length, Dcm_NegativeResponseCodeType* NegRes)
{
  Std_ReturnType RetVal;
  uint16 flIndex;

  boolean flMatchDid = FALSE;

  RetVal = DCM_E_NOT_OK;
  *NegRes = DCM_E_REQUESTOUTOFRANGE;
  if(DcmExt_OpStatus == DCM_INITIAL)
  {
    *Length = 0x0u;
  }

  for (flIndex = 0u; flIndex < DcmExt_Didinfo_Size; flIndex++)/*MISRA CID 10596371*/
  {
    if (DcmExt_Didinfo[flIndex].Did_Id == Did)
    {
      flMatchDid = TRUE;
      break;
    }
  }

  if (flMatchDid != FALSE) /* 19648185*/
  {
    /*Based on NVM notification negres should be updates*/
    switch (Did_action)
    {
      case DCM_DSP_DID_READ:
        if ((boolean) 0 != DcmExt_Didinfo[flIndex].Condition_Type)/*MISRA CID 19647915*/
        {
            switch(DcmExt_IntOpstatus)
            { 
              case eDcmExt_CondCheck_Opstatus:
              {
                  RetVal = DcmExt_Services_CndChk (OpStatus, NegRes, Did);
                  if(RetVal == E_OK)
                  {
                    DcmExt_IntOpstatus = eDcmExt_LenCheck_Opstatus;
                    DcmExt_OpStatus = DCM_INITIAL;
                  }
                  else
                  {
                    break;
                  }
                  /* no break here, go to next func execution */
              }
              case eDcmExt_LenCheck_Opstatus:
              {
                  if (0u != DcmExt_Didinfo[flIndex].Did_Length) /*MISRA CID 19648383*/
                  {
                    *Length = DcmExt_Didinfo[flIndex].Did_Length;
                     RetVal = E_OK;
                  }
                  else
                  {
                    RetVal = DcmExt_Services_LenChk ( OpStatus,NegRes, Length, Did);
                  }
                  if(RetVal == E_OK)
                  {
                    DcmExt_IntOpstatus = eDcmExt_Read_Opstatus;
                    DcmExt_OpStatus = DCM_INITIAL;
                  }
                  else
                  {
                    break;
                  }
                  /* no break here, go to next func execution */
              }
              case eDcmExt_Read_Opstatus:
              {                
                  RetVal = DcmExt_Services_DataRead(OpStatus, Buff, Did, NegRes, flIndex);
                  if(RetVal == E_OK)
                  {
                    DcmExt_IntOpstatus = eDcmExt_CondCheck_Opstatus;
                  }
                  break;
              }
            } /* switch */
            if(DCM_E_NOT_OK == RetVal)
            {
              DcmExt_IntOpstatus = eDcmExt_CondCheck_Opstatus;
            }
        } 
        else
        {
          RetVal = DcmExt_Services_DataRead(OpStatus, Buff, Did, NegRes,flIndex);
          if(DCM_E_NOT_OK == RetVal)
          {
            /* NRC 22 is maintained for the DIDs FDC5, FDB2 since NRC is not sent from application implementation */            
            if((*NegRes != DCM_E_BUSYREPEATREQUEST) && (*NegRes != DCM_E_GENERALREJECT) && (*NegRes != DCM_E_REQUESTOUTOFRANGE))
            {
              *NegRes = DCM_E_CONDITIONSNOTCORRECT; 
            }
          }
          else if(DCM_E_OK == RetVal)
          {
            if (0u != DcmExt_Didinfo[flIndex].Did_Length)/*MISRA CID 19648383*/
            {
              *Length = DcmExt_Didinfo[flIndex].Did_Length;
            }
            else
            {
              RetVal = DcmExt_Services_LenChk ( OpStatus, NegRes, Length, Did);
              if(DCM_E_NOT_OK == RetVal)
              {
                 /* NRC 22 is maintained for the DIDs FDC5, FDB2 since NRC is not sent from application implementation */
			          if((*NegRes != DCM_E_BUSYREPEATREQUEST) && (*NegRes != DCM_E_GENERALREJECT) && (*NegRes != DCM_E_REQUESTOUTOFRANGE))
			          {
                  *NegRes = DCM_E_CONDITIONSNOTCORRECT; 
				        }
              }
            }              
          }
          else
          {
            /*do nothing*/
          }
        }
        break;

      case DCM_DSP_DID_WRITE:
        RetVal = DcmExt_Services_DataWrite (OpStatus, Buff, NegRes, Did,flIndex);
        break;

        /* Do IO operations hise, The below is the example to implement IO operations */
      case DCM_DSP_DID_IO:
      if ((DCM_E_OK == RetVal) || (FALSE == DcmExt_Didinfo[flIndex].Condition_Type))
      {
        uint8 ioc_control_option = Buff[0];
        RetVal = DcmExt_Service_Iocontrol (OpStatus, Buff,NegRes, Did);
        if (DCM_E_OK == RetVal)
        {
          *Length = (uint32)((uint8)(((DcmExt_Didinfo[flIndex].Did_Length >> (ioc_control_option * 4)) & 0x0F) + IOC_OPTION_BYTE_SIZE));
        }
      }
        /*do nothing*/
        break;

      default:
        /*do nothing*/
        break;
    } /* switch */
    /* If any of the request placed from the DcmExt is pending for response
     In the next periodic cycle the request should be placed with Pending status
     to the Diag control.So the pending request information is kept in bufer here to
     place in the next cycle*/

    if (DCM_EXT_PENDING == RetVal) /*MISRA CID 19648652*/
    {
      DcmExt_OpStatus = DCM_PENDING;
    }
    else
    {
      DcmExt_OpStatus = DCM_INITIAL;
    }
  }
  else
  {
    /*do nothing*/
  }
  return RetVal;
}

void DcmExt_WdgM_PerformReset (void)
{

}

Std_ReturnType DI_Rid_Diag_Action(Dcm_OpStatusType OpStatus, uint8 Rid_action, Dcm_DspRidIdentifierTableType Rid, 
                                         const Dcm_MsgLenType ReqLength, Dcm_MsgType Buff, Dcm_MsgLenType* Length, Dcm_NegativeResponseCodeType* NegRes)
{
  Std_ReturnType RetVal;
  uint8 index = 0u;
  RetVal = E_NOT_OK;
  *NegRes = DCM_E_REQUESTOUTOFRANGE;

  for (index = 0; index < DcmExt_Ridinfo_Size ; index++)
  {
    if (DcmExt_DspRidIdentifierTable[index] == Rid)
    {
      break;
    }
  }
  if (DcmExt_Ridinfo_Size != index)
  {
    switch (Rid_action)
    {
      case DCM_DSP_RID_START:
        RetVal = DcmExt_Services_RoutineStart (OpStatus, Buff, Length, NegRes, Rid);
        break;
      case DCM_DSP_RID_STOP:
        RetVal = DcmExt_Services_RoutineStop (OpStatus, Buff, Length, NegRes, Rid);
        break;
      case DCM_DSP_RID_RESULTS:
        RetVal = DcmExt_Services_RoutineResults(OpStatus, Buff, Buff, Length, NegRes, Rid);
        break;
      default:
        /* do nothing*//*CID 18131526*/
        break;
    }
    if (DCM_EXT_PENDING == RetVal)
    {
      DcmExt_OpStatus = DCM_PENDING;
    }
    else
    {
      DcmExt_OpStatus = DCM_INITIAL;
    }
  }
  else
  {
    *NegRes = 0x31u;
    *Length = 0x0u;
    RetVal = E_NOT_OK;

  }
  return RetVal;
}

Std_ReturnType DcmExt_Communication_action(Dcm_OpStatusType OpStatus, uint8 ComM_Type, uint8 ComM_Action)
{
  Std_ReturnType ret_val = DCM_E_OK;
  return ret_val;
}

void DcmExt_2F_RCTUChange(Dcm_DspDidIdentifierTableType Did, Dcm_NegativeResponseCodeType *NegRes)
{
}

#if (DCMEXT_PROG_MAGIC_FLAG_HANDLER == STD_ON)
Std_ReturnType DcmExt_SetProgFlag (Dcm_NegativeResponseCodeType *NegRes)
{
  Std_ReturnType RetVal = E_OK;

  RetVal = Rte_Call_rp_CS_UpdateCdd_Service_0x10_Handler_UpdateCdd_GenericProgSessionRequest(NegRes);

  if(RetVal == E_OK)
  {
	  Jump_to_BootFlag = TRUE;
  }

  return (RetVal);
}
#endif

void DcmExt_NotificationOnDTCStatus(uint32 DTC, Dem_UdsStatusByteType DTCStatusOld,
                                                Dem_UdsStatusByteType DTCStatusNew)
{
 
}

void DcmExt_Pre_notification_clear (void)
{

}
void DcmExt_End_notification_clear (void)
{

}

void DcmExt_SessionChangeNotification(Dcm_SesCtrlType OldSessionP, Dcm_SesCtrlType NewSessionP)
{

}

Std_ReturnType DcmExt_Diag_Condition_check(Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType *NegRes)
{
 Std_ReturnType RetVal;
  RetVal = DCM_E_OK;
  *NegRes = DCM_E_OK;

  return (RetVal);
}

Std_ReturnType DcmExt_Prog_Condition_check(Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType *NegRes)
{
 Std_ReturnType RetVal;
  RetVal = DCM_E_OK;
  *NegRes = DCM_E_OK;

  return (RetVal);
}
Std_ReturnType DcmExt_Mfg_Condition_check (Dcm_NegativeResponseCodeType *NegRes)
{
  Std_ReturnType RetVal;
  RetVal = DCM_E_OK;
  *NegRes = DCM_E_OK;

  return (RetVal);
}
Std_ReturnType DcmExt_11Vehicle_Condition_check (Dcm_NegativeResponseCodeType *NegRes)
{
   Std_ReturnType RetVal = E_OK;
  *NegRes = DCM_E_POSITIVERESPONSE;
    
  return RetVal;
}
Std_ReturnType DcmExt_Vehicle_Condition_check(Dcm_MsgContextType *pMsgContext,Dcm_NegativeResponseCodeType *NegRes)
{
  return E_OK;
}

Std_ReturnType DcmExt_28SVehicle_Condition_check (Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType *NegRes)
{
  Std_ReturnType RetVal = E_OK;

  return RetVal;
}

Std_ReturnType DcmExt_3DStatus_Vehicle_Condition_check (Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType *NegRes)
{

  Std_ReturnType RetVal = E_OK;

  return RetVal;
}

Std_ReturnType DcmExt_Vehicle_SpeedCondition_check (Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType *NegRes)
{
  Std_ReturnType RetVal = E_OK;
  /*
   if (s_Speed_Calculated != 0)
   {
   RetVal = 0x88;
   }
   */
  return RetVal;
}

/**************************************************************************
 Function name   : void DcmExt_Confirmation
 Arguments       : Std_ReturnType result
 Return type     : void
 Description     : The result indicates whethis the diag response
 transmission was successful or not.
 **************************************************************************/
void DcmExt_Confirmation (Std_ReturnType Result)
{

}

#if(DCM_SVC_23_SUPPORT_ENABLED == STD_ON)
/**************************************************************************
 Function name       : Std_ReturnType DcmExt_ReadMemory(uint32 MemoryAddress, uint32 MemorySize,
 Dcm_MsgType Buff, Dcm_MsgLenType* Length, Dcm_NegativeResponseCodeType* NegRes
 Description         : Read Memory By address
 Parameters (in)     : uint32 MemoryAddress, uint32 MemorySize,
 Dcm_MsgType Buff, Dcm_MsgLenType* Length, Dcm_NegativeResponseCodeType* NegRes
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
Dcm_ReturnReadMemoryType DcmExt_ReadMemory(Dcm_OpStatusType OpStatus, uint8 MemoryIdentifier,
        uint32 MemoryAddress, uint32 MemorySize, uint8* MemoryData, Dcm_NegativeResponseCodeType* ErrorCode)
{
  Std_ReturnType RetVal;

  RetVal = DCM_E_OK;

  return RetVal;
}
#endif

#if (DCM_SVC_3D_SUPPORT_ENABLED == STD_ON)
/**************************************************************************
 Function name       : Std_ReturnType DcmExt_WriteMemory(uint32 MemoryAddress, uint32 MemorySize,
 Dcm_MsgType Buff, Dcm_MsgLenType* Length, Dcm_NegativeResponseCodeType* NegRes
 Description         : Read Memory By address
 Parameters (in)     : uint32 MemoryAddress, uint32 MemorySize,
 Dcm_MsgType Buff, Dcm_MsgLenType* Length, Dcm_NegativeResponseCodeType* NegRes
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
Dcm_ReturnWriteMemoryType DcmExt_WriteMemory (Dcm_OpStatusType OpStatus,uint8 MemoryIdentifier,uint32 MemoryAddress,uint32 MemorySize,
      const uint8* MemoryData,Dcm_NegativeResponseCodeType* ErrorCode)
{
  Std_ReturnType RetVal = DCM_E_NOT_OK;

  RetVal = Rte_Call_rp_CS_UpdateCdd_Service_0x36_Handler_UpdateCdd_GenericTransferDataHandler(OpStatus, MemoryIdentifier, MemoryAddress, MemorySize, MemoryData, ErrorCode);

  return RetVal;
}
#endif

Std_ReturnType Dcm_ClearDTCCheckFnc(uint32 GoDTC, Dcm_NegativeResponseCodeType* ErrorCode)
{
	return E_OK;
}

Std_ReturnType DcmExt_ProcessRequestDownload(Dcm_OpStatusType OpStatus, uint8 DataFormatIdentifier, uint32 MemoryAddress, uint32 MemorySize,
    uint32* BlockLength, Dcm_NegativeResponseCodeType* ErrorCode)
{
	Std_ReturnType RetVal = DCM_E_NOT_OK;

	RetVal = Rte_Call_rp_CS_UpdateCdd_Service_0x34_Handler_UpdateCdd_GenericRequestDownloadHandler(OpStatus, DataFormatIdentifier, MemoryAddress, MemorySize, BlockLength, ErrorCode);

	return RetVal;
}

Std_ReturnType DcmExt_ProcessRequestTransferExit(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode)
{
	Std_ReturnType RetVal = DCM_E_NOT_OK;

	RetVal = Rte_Call_rp_CS_UpdateCdd_Service_0x37_Handler_UpdateCdd_GenericTransferExitHandler(OpStatus, 0u, 0u, NULL, NULL, ErrorCode);

	return RetVal;
}

void DcmExt_BroadCast_SessionChangeStatus (uint8 SubFunction, uint8 Source)
{
}

void DcmExt_BroadCast_SecurityChangeStatus(uint8 SubFunction, uint8 Source)
{
}

/* SFD */
#if((DcmDsdRequestManufacturerNotificationEnabled == STD_ON) || (DcmDsdRequestSupplierNotificationEnabled == STD_ON))
Std_ReturnType DcmExt_ServReqNotif_Manufacture_Indication(uint8 SID, uint8* RequestData, uint16 RequestDataSize, uint8 ReqType, uint16 SourceAddress,
                                          uint8* RespData, uint16* RespDataSize, Dcm_NegativeResponseCodeType* ErrorCode )
{
  //RTE call needed  
  return E_OK;
}
	
Std_ReturnType DcmExt_ServReqNotif_Manufacture_Confirmation(uint8 SID, uint8 ReqType, uint16 SourceAddress, Dcm_ConfirmationStatusType ConfirmationStatus )
{
  //RTE call needed  
  return E_OK;
}
#endif
#ifdef NVM_BLOCK_WRITE

static void  DcmExt_NvMTestFunction(void)
{
	  DcmExt_NvM_BlockTest();
    Std_ReturnType RetValue;
    uint16 fl_TempBlockId;
    uint16 fl_BlockIdIteration;
    uint16 BlockLength;
    NvM_RequestResultType NvM_Result;
    Std_ReturnType RetVal = DCM_E_PENDING;

    switch(NvM_StateMachine)
    {
        case NVM_TEST_IDLE:
            if(FALSE != NvM_InitiateNvMTesting)
            {
                NvM_StateMachine = NVM_TEST_INITIATE;
                for(fl_BlockIdIteration = 2; fl_BlockIdIteration < NVM_NUM_OF_BLOCKS; fl_BlockIdIteration++)
                {
                    NvM_DataStruct.NvMBlockTestResult[fl_BlockIdIteration] = NVM_BLOCK_TEST_NOT_INITIATED;
                }
                NvM_DataStruct.TestStatus = NVM_TEST_INITAITED;
            }
            RetVal = DCM_E_PENDING;
        break;
        case NVM_TEST_INITIATE:
            NvM_DataStruct.CurrentTestBlockId = 2;
            MemLib_MemSet((uint8*)(&(NvM_TWriteBuffer[0])), 0x28, NVM_WRITE_VERIFICATION_DATASIZE);
            MemLib_MemSet((uint8*)(&(NvM_ReadBuffer[0])), 0xFF, NVM_WRITE_VERIFICATION_DATASIZE);
            NvM_StateMachine = NVM_TEST_ENABLE_WRITE_PROTECT_ALL_BLOCKS;
            Block_Id = 2;
            RetVal = DCM_E_PENDING;
        break;

        case NVM_TEST_ENABLE_WRITE_PROTECT_ALL_BLOCKS:
            for(fl_BlockIdIteration = 2; fl_BlockIdIteration <= NVM_NUM_OF_BLOCKS; fl_BlockIdIteration++)
            {
                NvM_SetBlockProtection(fl_BlockIdIteration, TRUE);
            }
            NvM_StateMachine = NVM_TEST_WAIT_EXISTING_BLOCKS_COMPLETE;
            RetVal = DCM_E_PENDING;
        break;

        case NVM_TEST_WAIT_EXISTING_BLOCKS_COMPLETE:
            fl_TempBlockId = 0xFFFF;
            for(fl_BlockIdIteration = 2; fl_BlockIdIteration <= NVM_NUM_OF_BLOCKS; fl_BlockIdIteration++)
            {
                NvM_GetErrorStatus(fl_BlockIdIteration, &NvM_Result);
                if(NVM_REQ_PENDING == NvM_Result)
                {
                    fl_TempBlockId = fl_BlockIdIteration;
                    break;
                }
            }
            if(fl_TempBlockId == 0xFFFF)
            {
                NvM_StateMachine = NVM_TEST_WRITE_BLOCK_INITATE;
                NvM_DataStruct.CurrentTestBlockId = 2;
            }
            RetVal = DCM_E_PENDING;
        break;

        case NVM_TEST_WRITE_BLOCK_INITATE:
         NvM_DataStruct.TestStatus = NVM_TEST_PROGRESS;
        	NvM_SetBlockProtection(NvM_DataStruct.CurrentTestBlockId, FALSE);
        	RetValue = NvM_WriteBlock(NvM_DataStruct.CurrentTestBlockId,&NvM_TWriteBuffer[0]);
        	NvM_SetBlockProtection(NvM_DataStruct.CurrentTestBlockId, TRUE);
            if(RetValue == E_OK)
            {
                NvM_StateMachine = NVM_TEST_WRITE_BLOCK_WAIT;
                NvM_DataStruct.NvMBlockTestResult[NvM_DataStruct.CurrentTestBlockId] = NVM_BLOCK_TEST_WRITE_REQUEST_ACCEPTED_RESULT_PENDING;
            }
            else
            {
                NvM_DataStruct.NvMBlockTestResult[NvM_DataStruct.CurrentTestBlockId] = NVM_BLOCK_TEST_WRITE_REQUEST_NOT_ACCEPTED;
                NvM_DataStruct.CurrentTestBlockId++;
                if(NvM_DataStruct.CurrentTestBlockId > NVM_NUM_OF_BLOCKS)
                {
                    NvM_StateMachine = NVM_TEST_COMPLETE;
                }
                else
                {
                    /* Stay in this state and initate Next write */
                }
            }
            RetVal = DCM_E_PENDING;
        break;

        case NVM_TEST_WRITE_BLOCK_WAIT:
            (void)NvM_GetErrorStatus(NvM_DataStruct.CurrentTestBlockId, &NvM_Result);
            if(NVM_REQ_PENDING != NvM_Result)
            {
                if(NvM_Result == NVM_REQ_OK)
                {
                    NvM_DataStruct.NvMBlockTestResult[NvM_DataStruct.CurrentTestBlockId] = NVM_BLOCK_TEST_WRITE_REQUEST_COMPLETED;
                    NvM_StateMachine = NVM_TEST_READ_BLOCK_INITIATE;
                }
                else
                {
                    NvM_DataStruct.NvMBlockTestResult[NvM_DataStruct.CurrentTestBlockId] = NVM_BLOCK_TEST_WRITE_REQUEST_FAILED;
                    NvM_DataStruct.CurrentTestBlockId++;
                    if(NvM_DataStruct.CurrentTestBlockId > NVM_NUM_OF_BLOCKS)
                    {
                        NvM_StateMachine = NVM_TEST_COMPLETE;
                    }
                    else
                    {
                        NvM_StateMachine = NVM_TEST_WRITE_BLOCK_INITATE;
                    }
                }
            }
            RetVal = DCM_E_PENDING;
        break;

        case NVM_TEST_READ_BLOCK_INITIATE:
            MemLib_MemSet((uint8*)(&(NvM_ReadBuffer[0])), 0xFF, NVM_WRITE_VERIFICATION_DATASIZE);
            RetValue = NvM_ReadBlock(NvM_DataStruct.CurrentTestBlockId, &NvM_ReadBuffer[0]);
            if(E_OK == RetValue)
            {
                NvM_DataStruct.NvMBlockTestResult[NvM_DataStruct.CurrentTestBlockId] = NVM_BLOCK_TEST_READ_REQUEST_ACCEPTED_RESULT_PENDING;
                NvM_StateMachine = NVM_TEST_READ_BLOCK_WAIT;
            }
            else
            {
                NvM_DataStruct.NvMBlockTestResult[NvM_DataStruct.CurrentTestBlockId] = NVM_BLOCK_TEST_READ_REQUEST_NOT_ACCEPTED;
                NvM_DataStruct.CurrentTestBlockId++;
                if(NvM_DataStruct.CurrentTestBlockId > NVM_NUM_OF_BLOCKS)
                {
                    NvM_StateMachine = NVM_TEST_COMPLETE;
                }
                else
                {
                    NvM_StateMachine = NVM_TEST_WRITE_BLOCK_INITATE;
                }
            }
            RetVal = DCM_E_PENDING;
        break;

        case NVM_TEST_READ_BLOCK_WAIT:
            (void)NvM_GetErrorStatus(NvM_DataStruct.CurrentTestBlockId, &NvM_Result);
            if(NVM_REQ_PENDING != NvM_Result)
            {
                if(NvM_Result == NVM_REQ_OK)
                {
                    NvM_DataStruct.NvMBlockTestResult[NvM_DataStruct.CurrentTestBlockId] = NVM_BLOCK_TEST_READ_REQUEST_COMPLETED;
                    NvM_StateMachine = NVM_TEST_VALIDATE_WRITE_AND_READ;
                }
                else
                {
                    NvM_DataStruct.NvMBlockTestResult[NvM_DataStruct.CurrentTestBlockId] = NVM_BLOCK_TEST_READ_REQUEST_FAILED;
                    NvM_DataStruct.CurrentTestBlockId++;
                    if(NvM_DataStruct.CurrentTestBlockId > NVM_NUM_OF_BLOCKS)
                    {
                        NvM_StateMachine = NVM_TEST_COMPLETE;
                    }
                    else
                    {
                        NvM_StateMachine = NVM_TEST_WRITE_BLOCK_INITATE;
                    }
                }
            }
            RetVal = DCM_E_PENDING;
        break;

        case NVM_TEST_VALIDATE_WRITE_AND_READ:
            BlockLength = NvM_BlockConfig[NvM_DataStruct.CurrentTestBlockId].NvBlockLength;
            if(FALSE != MemLib_MemCmp(&NvM_TWriteBuffer[0],&NvM_ReadBuffer[0],BlockLength))
            {
                NvM_DataStruct.NvMBlockTestResult[NvM_DataStruct.CurrentTestBlockId] = NVM_BLOCK_TEST_COMPLETED_SUCCESSFULLY;
            }
            else
            {
                NvM_DataStruct.NvMBlockTestResult[NvM_DataStruct.CurrentTestBlockId] = NVM_BLOCK_TEST_COMPLETED_VALIDATION_FAILED;
            }
            NvM_DataStruct.CurrentTestBlockId++;
            if(NvM_DataStruct.CurrentTestBlockId > NVM_NUM_OF_BLOCKS)
            {
                NvM_StateMachine = NVM_TEST_COMPLETE;
            }
            else
            {
                NvM_StateMachine = NVM_TEST_WRITE_BLOCK_INITATE;
            }
            RetVal = DCM_E_PENDING;
        break;

        case NVM_TEST_COMPLETE:
            NvM_DataStruct.NvMTestFailiureCount = 0;
            for(fl_BlockIdIteration = 2; fl_BlockIdIteration < NVM_NUM_OF_BLOCKS; fl_BlockIdIteration++)
            {
                if(NvM_DataStruct.NvMBlockTestResult[fl_BlockIdIteration] != NVM_BLOCK_TEST_COMPLETED_SUCCESSFULLY)
                {
                    NvM_DataStruct.NvMTestFailiureCount++;
                }
            }
            if(NvM_DataStruct.NvMTestFailiureCount > 0)
            {
                NvM_DataStruct.TestStatus = NVM_TEST_FAILED;
                RetVal = E_NOT_OK;
            }
            else
            {
                NvM_DataStruct.TestStatus = NVM_TEST_SUCCESS;
                RetVal = E_OK;
            }
            NvM_StateMachine = NVM_TEST_DISABLE_WRITE_PROTECT_ALL_BLOCKS;
            NvM_InitiateNvMTesting = FALSE;
        break;

        case NVM_TEST_DISABLE_WRITE_PROTECT_ALL_BLOCKS:
            for(fl_BlockIdIteration = 2; fl_BlockIdIteration <= NVM_NUM_OF_BLOCKS; fl_BlockIdIteration++)
            {
                NvM_SetBlockProtection(fl_BlockIdIteration, FALSE);
            }
            NvM_StateMachine = NVM_TEST_IDLE;
            RetVal = E_OK;
        break;
        default:
          RetVal = DCM_E_PENDING;
          break;
    }
	// Added to remove compiler warning
    (void)RetVal;
}

void DcmExt_NvM_BlockTest()
{
  switch (L_state_u8)
  {
      case 1:
        L_state_u8 =3;
        NvM_WriteBlock(L_blockId_u16, NULL);
        break;
      case 2:
        L_state_u8 =3;
        NvM_ReadBlock(L_blockId_u16, NULL);
        break;
      case 3:
        if (E_OK == NvM_GetErrorStatus(L_blockId_u16, &L_blockStatus_u8))
        {
            if (NVM_REQ_PENDING!= L_blockStatus_u8)
            {
                L_state_u8 = 0;
            }
        }
        break;
      case 4:
        L_state_u8 =3;
        NvM_WriteBlock(L_blockId_u16,&NvM_TWriteBuffer[0]);
        break;
      case 5:
        L_state_u8 =3;
        NvM_ReadBlock(L_blockId_u16, &NvM_ReadBuffer[0]);
        break;
      default:
        break;
  }

}

Std_ReturnType NvM_TriggerDefaultWrite(uint8 *Data, uint8 OpStatus, uint8 *pNrc)
{
	Std_ReturnType RetVal = DCM_E_PENDING;

	if((NULL!= Data) &&(*Data == NVM_WRITE_DID))
	{
    if(OpStatus == DCM_INITIAL)
    {
      NvM_InitiateNvMTesting = TRUE;
      NvM_StateMachine = NVM_TEST_IDLE;
    }
    RetVal = DCM_E_OK;
  }
  return RetVal;
}
/*************************************************************************//**
 * \brief          DcmExt_NVMWRITEDID_DiagAction()
 *
 * \details        Implements Diagnostics - write operation for NvM Write DID
 * \n            
 *
 * \param[in]      : Dcm_OpStatusType OpStatus,
 *                   uint8 *Data,
 *                   uint8 *pNrc,
 *                   uint8 eOperation.
 *
 * \retval         :Standard return type (E_OK, E_NOT_OK)
 *
 * \note           Critical Section:  None.
 ****************************************************************************/
Std_ReturnType DcmExt_NVMWRITEDID_DiagAction(Dcm_OpStatusType OpStatus, uint8 *Data , uint8 *pNrc, uint8 eOperation)
{
  UInt8 fl_Ret_Type_U8 = E_OK;

	if(eOperation == eWrite )
	{
		/* Function routing to Write DID */
		/* below interface has to be updated with proper RTE interface  MANUAL*/
		fl_Ret_Type_U8 = NvM_TriggerDefaultWrite(Data, OpStatus, pNrc);
	}
	else
	{
		/* Do Nothing*/
	}
	return(fl_Ret_Type_U8);

}

Std_ReturnType DcmExt_RestHistory(uint8 *Data, uint8 OpStatus, uint8 *pNrc)
{
	Std_ReturnType RetVal= E_NOT_OK;

  if(Data != NULL_PTR)
  {
    RetVal = RstM_GetResetHistory(Data);
    if(RetVal!= E_OK)
    {
      *pNrc = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
    }

  }
  else
  {
    *pNrc = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }

  return RetVal;
}

static Std_ReturnType DcmExt_GetDefaultWriteStatus_DiagAction(Dcm_OpStatusType OpStatus, uint8 *Data , uint8 *pNrc, uint8 eOperation)
{
  UInt8 fl_Ret_Type_U8 = E_OK;

  if(eOperation == eRead )
  {
    if(Data != NULL_PTR)
    {
      Data[0] = NvM_DataStruct.TestStatus;
      Data[1] = NvM_DataStruct.CurrentTestBlockId;
    }
  }
  else
  {
    /* Do Nothing*/
  }
  return(fl_Ret_Type_U8);
}


/*************************************************************************//**
 * \brief          DcmExt_ResetHistory_DiagAction()
 *
 * \details        Implements Diagnostics - write operation for NvM Write DID
 * \n            
 *
 * \param[in]      : Dcm_OpStatusType OpStatus,
 *                   uint8 *Data,
 *                   uint8 *pNrc,
 *                   uint8 eOperation.
 *
 * \retval         :Standard return type (E_OK, E_NOT_OK)
 *
 * \note           Critical Section:  None.
 ****************************************************************************/
Std_ReturnType DcmExt_ResetHistory_DiagAction(Dcm_OpStatusType OpStatus, uint8 *Data , uint8 *pNrc, uint8 eOperation)
{
  UInt8 fl_Ret_Type_U8 = E_OK;

  if(eOperation == eRead )
  {
    /* Function routing to Write DID */
    /* below interface has to be updated with proper RTE interface  MANUAL*/
    fl_Ret_Type_U8 = DcmExt_RestHistory(Data, OpStatus, pNrc);
  }
  else
  {
    /* Do Nothing*/
  }
  return(fl_Ret_Type_U8);
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
/*                    EstabliHed in TuringC stream                         */
/*                    channel support                                       */
/*                   ii) 818468: [Diagnostic][A12]28 service NRC is wrong   */
/*                   iii) 817372 :- Service 0x86 basic frame Work           */
/*Change Description: Multi Read DID support and design optimization        */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 18-Oct-2020                                           */
/*Version           :                                                       */
/*By                : gpetkov1                                              */
/*Traceability      : 1490663: PSF.22.14 [Basic8 MP23] Routines_Diag Inc1   */
/*                    (SW Development) - fix issues and deploy              */
/*Change Description: Add Routine 0x065E to DcmExt_DspRidIdentifierTable    */
/*--------------------------------------------------------------------------*/
