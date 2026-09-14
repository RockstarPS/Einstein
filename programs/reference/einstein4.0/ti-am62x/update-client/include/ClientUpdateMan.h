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

# ifndef CLIENT_UP_MAN_H
# define CLIENT_UP_MAN_H

#define ERASE_ROUTINE_ID 						(0xFF00)
#define VERIFY_ROUTINE_ID 						(0xFF01)
#define ACTIVATION_ROUTINE_ID 					(0xFE00)
#define ROLLBACK_ROUTINE_ID						(0xFE01)
#define ACTIVATION_COMPLETE_ROUTINE_ID			(0xFE02)

typedef enum{
    TgtLoc_None,
    TgtLoc_NativeTv2Tgt,
    TgtLoc_RemoteUclTgt,
}tUPD_TgtLocality;
extern tUPD_TgtLocality clientLocality;
// typedef struct sUpdMan_tergets
// {
    

// }tUpdMan_tergets;
Std_ReturnType UpdateMan_ClientInit(void);
Std_ReturnType ClientMan_IsValidRequest(uint32 startaddress,uint32 size);
Std_ReturnType CUpdtMan_IInstallation_RIDHandler(Dcm_OpStatusType opStatus, uint8 Rid_action, uint16 Rid, Dcm_MsgLenType ReqLength, Dcm_MsgType Buff,Dcm_MsgLenType* RespLength, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType CUpdtMan_IInstallation_ProgSessionRequest(uint8* ErrorCode);
Std_ReturnType CUpdtMan_IInstallation_TransferStart(Dcm_OpStatusType OpStatus, uint8 DataFormatIdentifier, uint32 MemoryAddress, uint32 MemorySize, uint32* BlockLength, uint8* ErrorCode);
Std_ReturnType CUpdtMan_IInstallation_TransferData(Dcm_OpStatusType OpStatus, uint8 MemoryIdentifier,uint32 MemoryAddress,uint32 MemorySize,const uint8* MemoryData,uint8* ErrorCode);
Std_ReturnType CUpdtMan_IInstallation_TransferExit(uint8 *ErrorCode);
#endif