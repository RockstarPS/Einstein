/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2023. Visteon Corporation owns all rights to           *
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
#include "Client.h"
//#include "UPD_IInstallation.h"
//#include "UPDd.h"
//#include "UPDi_Types.h"
//#include "UPDi_IoAdapter.h"
//#include "UPD_ITargets.h"
//#include "PduR_Dcm.h"
//#include "Rte_CUpdateCdd.h"
//#include "UPDi_InstallMan.h"
#include "Dcm.h"
#include "ClientUpdateMan.h"
#include "UPD_UCL_proxy.h"
//=======================================================================================================================

#define TARGETS_COUNT 2
// # define DNLD_ADDR_LENGTH_BYTE	                      	(0x44u)
// # define DNLD_REQ_DATA_LENGTH	                      	(0x0Au)
// # define DNLD_REQ_MIN_DATA_LENGTH					  	(0x05u)
// # define DNLD_TRANSFER_MIN_DATA_LENGTH				  	(0x03u)

// # define DNLD_TRANSFER_DATA_SEQ_OK						(0x00u)
// # define DNLD_TRANSFER_DATA_SEQ_SAME					(0x01u)
// # define DNLD_TRANSFER_DATA_SEQ_NOT_OK					(0x02u)
// # define APP_START_ADDRESS               0x10088000uL
// # define APP_END_ADDRESS                 0x103FFFFFuL
// # define HSM_START_ADDRESS               0x10000000uL
// # define HSM_END_ADDRESS                 0x1003FFFFuL
// # define BL_UPDATER_START_ADDRESS        0x10048000uL
// # define BL_UPDATER_END_ADDRESS          0x10087FFFuL
// # define SBL_STARTADDRESS                0x28034000uL
// # define SBL_ENDADDRESS                  0x28037FFFuL
// # define HYPERFLASH_STARTADDRESS         0x60000000uL
// # define HYPERFLASH_ENDADDRESS           0x63FFFFFFuL
// uint32 ProgrammedDataLength_U32;
// uint8 Processed_RID;
// uint32 DownloadLength_U32;
// uint8 gCurrentSequenceCount;
// uint8 gPendingRes;
// uint32 StartAddress = 0uL;
// uint32 EndAddress = 0uL;
// uint32 Size = 0uL;
// static char* l_TargetName_ptr;
// static char l_PackageName[PackageNameLength]="";
// uint32 l_downloadsize_u32 = 0UL;
// static uint8 gPendingResErase;
// static uint8 EraseFlag;
// static uint32 Dnld_Resp_Blk_Len;

char* l_TargetName_ptr;

static uint8 UpdateCdd_TransferDataSequenceCheck(uint8 pExptdSeqCount, uint8 pRcvdSeqCount);
static Std_ReturnType Client_CheckForDataCompressionAndEncryption(uint8 messageData);
tUPD_TgtLocality clientLocality= TgtLoc_RemoteUclTgt;
// static Std_ReturnType SecurityLevelCheck(void);
// static Std_ReturnType NonceSecurityCheck(void);
// static Std_ReturnType TesterSignatureCheck(void);
//=====================================================================================================================
// Global Variables
// uint8 l_InitialIV_Buffer1_U8[16] ;
// const uint8 Default_IVBuffer[16] = {0xFF, 0xEE, 0xDD, 0xCC, 0xBB, 0xAA, 0x99, 0x88, 0x77, 0x66, 0x55, 0x44, 0x33, 0x22, 0x11, 0x00};
//=====================================================================================================================

/*===========================================================================================================================================
* Std_ReturnType UpdateCdd_ClientInit(void)
* Function description : This function shall initialize the static variables
* Input arguments : void
* Return type : E_OK 	  - Initialzation done by client module
*            	E_NOT_OK  - Initialzation not done by client module
* Function scope : Public function
*============================================================================================================================================*/
Std_ReturnType UpdateMan_ClientInit(void)
{
	// memset(l_PackageName,0,PackageNameLength);
	// ProgrammedDataLength_U32 = 0uL;
	// Dnld_Resp_Blk_Len = 0uL;
	// Processed_RID = SID_IDLE;
	// DownloadLength_U32 = 0uL;
	// gCurrentSequenceCount = 0U;
	// gPendingRes = (uint8)FALSE;
	// gPendingResErase = (uint8)FALSE;
	// EraseFlag = 0u;

	return E_OK;
}
/*===========================================================================================================================================
*  Std_ReturnType ClientMan_IsValidRequest(uint32 startaddress,uint32 endaddress)
* Function description : This function shall find the target name and check if request is valid or not
* Input arguments : target start address and end address
* Return type : E_OK 	  - target present in Update Cdd configuration
*            	E_NOT_OK  - target not present in Update Cdd configuration
* Function scope : Private function
*============================================================================================================================================*/

//Std_ReturnType ClientMan_IsValidRequest(uint32 startaddress,uint32 size)
//{
//	Std_ReturnType ret = E_NOT_OK;
//	tUPDiTarget*  target = NULL;
//	tUPDiPartition* pPartitionA =NULL;
//	tUPDiPartition* pPartitionB =NULL;
//	uint8 i=0,j=0;
//
//
//	for(i=0; i<TARGETS_COUNT ; i++)
//	{
//		for(j = 0u ;j < oUPDCdd.Targets[i]->GroupsCount ;j++)
//		{
//			/*get target*/
//			target = (tUPDiTarget*)oUPDCdd.Targets[i];
//			/*get  partition a and b */
//			pPartitionA = (target->pGroups[j].BankA);
//			pPartitionB = (target->pGroups[j].BankB);
//
//			if(NULL != pPartitionA)
//			{
//				if((startaddress == pPartitionA->Address) && (size == ((pPartitionA->Address + pPartitionA->Size) - 1uL)))
//				{
//					// memcpy(gPackageName,target->Name,strlen(target->Name));
//					l_TargetName_ptr = (char*)target->Name;
//          			//if (target->Type ==eTargetTypeRemote)
//					{
//						clientLocality=TgtLoc_RemoteUclTgt;
//					}
//					ret = E_OK;
//				}
//			}
//			if(NULL != pPartitionB)
//			{
//				if((startaddress == pPartitionB->Address) && (size == ((pPartitionB->Address + pPartitionB->Size) - 1uL)))
//				{
//					// memcpy(gPackageName,target->Name,strlen(target->Name));
//					l_TargetName_ptr = (char*)target->Name;
//					//if (target->Type ==eTargetTypeRemote)
//					{
//						clientLocality=TgtLoc_RemoteUclTgt;
//					}
//					ret = E_OK;
//				}
//			}
//
//		}
//	}
//
//	return ret;
//}

/*===========================================================================================================================================
* Std_ReturnType CUpdtMan_IInstallation_RIDHandler(uint8 opStatus, uint8 Rid_action, uint16 Rid, Dcm_MsgLenType ReqLength, Dcm_MsgType Buff,Dcm_MsgLenType* RespLength, Dcm_NegativeResponseCodeType *ErrorCode)
* Function description : This function shall perform erase operation on target
* Return : E_OK -  erase request for target accepted
*          E_NOT_OK - erase request not accrpted by target
*============================================================================================================================================*/
Std_ReturnType CUpdtMan_IInstallation_RIDHandler(uint8 opStatus, uint8 Rid_action, uint16 Rid, Dcm_MsgLenType ReqLength, Dcm_MsgType Buff,Dcm_MsgLenType* RespLength, Dcm_NegativeResponseCodeType *ErrorCode)
{
    Std_ReturnType status = E_NOT_OK;

	//status = (clientLocality!=TgtLoc_RemoteUclTgt )? UPDInstallMan_Erase((char*)PackageName,PackageSize): UCL_IInstallation_Erase((char*)PackageName,PackageSize);

	if(Rid == ERASE_ROUTINE_ID)
	{
		status = UCL_IInstallation_Erase(opStatus, Rid_action, ReqLength, Buff, RespLength, ErrorCode);
	}
	else if(Rid == VERIFY_ROUTINE_ID)
	{
		status = UCL_IInstallation_Verify(opStatus, Rid_action, ReqLength, Buff, RespLength, ErrorCode);
	}
	else if(Rid == ACTIVATION_ROUTINE_ID)
	{
		status = UCL_IInstallation_ActivationRequest(ErrorCode);
	}

	else
	{
		// do nothing.
	}

	return status;
}
Std_ReturnType CUpdtMan_IInstallation_ProgSessionRequest(uint8* ErrorCode)
{
    Std_ReturnType status;

	status = UCL_IInstallation_ProgSessionRequest(ErrorCode);

	return status;
}

Std_ReturnType CUpdtMan_IInstallation_TransferStart(uint8 OpStatus, uint8 DataFormatIdentifier, uint32 MemoryAddress, uint32 MemorySize, uint32* BlockLength, uint8* ErrorCode)
{
    Std_ReturnType status = 0u;

	//status = (clientLocality!=TgtLoc_RemoteUclTgt )? UPD_IInstallation_TransferStart((const char *)PackageName, PackageSize) : UCL_IInstallation_TransferStart((const char *)PackageName, PackageSize);

	status = UCL_IInstallation_TransferStart(OpStatus, DataFormatIdentifier, MemoryAddress, MemorySize, BlockLength, ErrorCode);

	return status;
}
Std_ReturnType CUpdtMan_IInstallation_TransferData(uint8 OpStatus, uint8 MemoryIdentifier,uint32 MemoryAddress,uint32 MemorySize,const uint8* MemoryData,uint8* ErrorCode)
{
    Std_ReturnType status = 0u;

    //status = (clientLocality!=TgtLoc_RemoteUclTgt )? UPD_IInstallation_TransferData((uint32)Size, data) : UCL_IInstallation_TransferData((uint32)Size, data);

	status = UCL_IInstallation_TransferData(OpStatus, MemoryIdentifier, MemoryAddress, MemorySize, MemoryData, ErrorCode);

	return status;
}
Std_ReturnType CUpdtMan_IInstallation_TransferExit(uint8 *ErrorCode)
{
    Std_ReturnType status;

    status =  UCL_IInstallation_TransferExit(ErrorCode);

    return status;
}

Std_ReturnType CUpdtMan_IInstallation_ResetRequest(uint8 *ErrorCode)
{
    Std_ReturnType status;

    status =  UCL_IInstallation_ResetRequest(ErrorCode);

    return status;
}