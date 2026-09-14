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

# ifndef UPD_UCL_PROXY_H
# define UPD_UCL_PROXY_H
//#include "UPDi_Types.h"
//#include "UclDL_Types.h"
#include "Std_Types.h"
#include "UclSys.h"
#include "UclDLCbk_Types.h"
#include "Rte_Dcm_Type.h"
#include "Dcm_Types.h"

#define UPD_UCL_STATE_IDLE 				(0u)
#define UPD_UCL_STATE_TRANSFER			(1u)
#define UPD_UCL_STATE_LONG_SERVICE 		(2u)
#define UPD_UCL_STATE_SHORT_SERVICE 	(3u)
#define UPD_UCL_STATE_TX_CONFIRM 		(4u)
#define UPD_UCL_STATE_RX_CONFIRM 		(5u)
#define UPD_UCL_STATE_PROGSESSION		(6u)
#define UPD_UCL_STATE_FAILED	 		(7u)

#define SIZE_OF_SHORT_SERVICE_MESSAGE  	(77u)
#define MAX_NO_OF_SHARED_MEMORY_BUFFER 	(2u)
#define MAX_SIZE_OF_SHARED_MEMORY   	(0x100000)
#define UPD_UCL_BANK_FULL 				(1u)
#define INDEX_OF_SID_IN_RESPONSE		(6u)
#define INDEX_OF_RESPONSECODE		   	(9u)
#define LENGTH_OF_ADDRESS				(4u)
#define LENGTH_OF_LENGTH				(4u)
#define SIZE_OF_SIGNATURE				(384)
#define NEGATIVE_RESPONSE_GIP			(DCM_E_GENERALPROGRAMMINGFAILURE)

#define UDS_SERVICE_PROGSESSION			(0x10)
#define UDS_SERVICE_RESET				(0x11)
#define UDS_SERVICE_STARTDOWNLOAD       (0x34)
#define UDS_SERVICE_TRANSFERDATA		(0x36)
#define UDS_SERVICE_TRANSFEREXIT		(0x37)
#define UDS_SERVICE_RID_ERASE			(0x31)
#define UDS_SERVICE_RID_VERIFY			(0xFF)
#define UDS_SERVICE_RID_ACTIVATE		(0xFE)

typedef struct
{
    uint8 compId;
    uint8 msgCnt;
} DKMsgBase;

typedef struct
{
    DKMsgBase base;
    uint16 msgId;
    uint16 msgSize;
    uint8 sid;
    uint16 length;
    uint8 responseCode;
    uint8 NRC;
    uint8 data[64];
} UpdateShortServiceResp;

typedef struct
{
    DKMsgBase base;
    uint16 msgId;
    uint16 msgSize;
    uint8 memoryType;
    uint8 memoryCmd;
    uint8 sid;
    uint32 length;
    uint8 data[64];
} UpdateShortServiceReq;

typedef struct
{
    DKMsgBase base;
    uint16 msgId;
    uint16 msgSize;
    uint8 memoryType;
    uint8 memoryCmd;
    uint8 sid;
    uint32 length;
    uint8 data[2048];
} UpdateLongServiceReq;

typedef struct
{
	uint8* MemoryPtr;
	uint32 AvailableSize;
	uint8  BankFull;
} UPD_UCL_SharedMemoryObjType;

extern Std_ReturnType	UCL_IInstallation_Erase(uint8 opStatus, uint8 Rid_action, uint32 ReqLength, uint8* Buff,uint32* RespLength, uint8 *ErrorCode);
extern Std_ReturnType 	UCL_IInstallation_ProgSessionRequest(uint8* ErrorCode);
extern Std_ReturnType 	UCL_IInstallation_TransferStart(uint8  OpStatus, uint8 DataFormatIdentifier, uint32 MemoryAddress, uint32 MemorySize, uint32* BlockLength, uint8* ErrorCode);
extern Std_ReturnType 	UCL_IInstallation_TransferData(uint8 OpStatus, uint8 MemoryIdentifier,uint32 MemoryAddress,uint32 MemorySize,const uint8* MemoryData,uint8* ErrorCode);
extern Std_ReturnType 	UCL_IInstallation_TransferExit(uint8* ErrorCode);
extern Std_ReturnType  	UCL_IInstallation_ResetRequest(uint8* ErrorCode);
extern Std_ReturnType 	UCL_IInstallation_Verify(uint8 opStatus, uint8 Rid_action, uint32 ReqLength, uint8* Buff,uint32* RespLength, uint8 *ErrorCode);
extern Std_ReturnType 	UCL_IInstallation_ActivationRequest(uint8* ErrorCode);

Std_ReturnType 	UPD_UCL_WriteToSharedMem(uint8 SharedMem_Index,const uint8* MemoryData,uint32 MemorySize);
void 		   	UPD_UCL_SerializeShortServiceReq(UpdateShortServiceReq msg,uint8* Array);
void 		   	UPD_UCL_MainFunction(void);
void 			App_UclFatalError( uint8 DLInst, uint8 Status );
void 			App_UclLinkStatusChangedFunc( uint8 DLInst, EUclDLLinkStatus Status );
void 			App_UclMsgReceivedFunc( uint8 DLInst, EUclDLRxStatus Status, SUclDLMsg *pMsg );
void 			App_UclMsgTransmitStatusFunc( uint8 DLInst, uint16 MsgId, EUclDLAckStatus Status );

#endif