//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2022] Visteon Corporation
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
//
//---------------------------------------------------------------------------------------------------------------------

#ifndef UPD_Session_H
#define UPD_Session_H

#include "UPDi_IoAdapter.h"


//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================

typedef struct sUPDiInstallSession
{
    const struct sUPDiAbstractInstaller* RootInstaller;
    const struct sUPDiTarget* Target;

    tUPDiPartition* pReadPartition;
    tUPDiPartition* pWritePartition;
    tUPDiIoAdapter* pHashingAdapter;

    uint32_t InitialWritePos;
    uint32_t WritePos;

    tUPDWorkload Load;
    uint32_t EraseUntil;
    boolean TargetWasErased;

    // Write buffer - for delta composition without B-Bank, composition is prepared in RAM
    uint8_t nextCompBufferPos;
    uint8_t lastCompBufferPos;
    uint8_t CompBuffer[UPDd_COMPOSE_BUFFER_SIZE];  // required for delta update with A-Only
} tUPDiInstallSession;

struct sUPDiAbstractInstaller;

//=====================================================================================================================
//  Public Interface
//=====================================================================================================================

void  UPDiSession_Init(tUPDiInstallSession* This);
Std_ReturnType  UPDiSession_Suspend(tUPDiInstallSession* This);
void  UPDiSession_Serialize(tUPDiInstallSession* This,tUPDStream *pStream);
void  UPDiSession_Deserialize(tUPDiInstallSession* This,tUPDStream *pStream);

// Update Session
Std_ReturnType UPDiSession_Resume( tUPDiInstallSession* This, const struct sUPDiTarget* pTarget, const struct sUPDiAbstractInstaller* RootInstaller, uint32_t PackageSize );
const struct sUPDiTarget* UPDiSession_GetActiveTarget(tUPDiInstallSession* This);

Std_ReturnType UPDiSession_StartUpdate( tUPDiInstallSession* This, const struct sUPDiTarget* pTarget, const struct sUPDiAbstractInstaller* RootInstaller, uint32_t PackageSize );
Std_ReturnType UPDiSession_StartPartitionUpdate(tUPDiInstallSession* This, const char* PartitionName, uint32_t Size, boolean Compose);
Std_ReturnType UPDiSession_FinishPartitionUpdate(tUPDiInstallSession* This);// Finish pending operations
Std_ReturnType UPDiSession_ExitUpdate( tUPDiInstallSession* This );

boolean        UPDiSession_IsBusy(tUPDiInstallSession* This);
uint8_t          UPDiSession_GetQueueSize(tUPDiInstallSession* This);


// Hashing - part of Update Session
Std_ReturnType UPDiSession_StartHashing(tUPDiInstallSession* This, const struct sUPDiTarget* pTarget, tUPDiIoAdapter* pIoAdapter);
Std_ReturnType UPDiSession_Hash(tUPDiInstallSession* This, tUPDiPartition* pPartition, uint32_t Offset, uint32_t Size);
Std_ReturnType UPDiSession_ExitHashing(tUPDiInstallSession* This, const struct sUPDiTarget* pTarget, tUPDHashInfo* Hash);

// PartitionUpdate - - part of Update Session

Std_ReturnType UPDiSession_WriteNext(tUPDiInstallSession* This, uint8_t* Data, uint32_t Size);
Std_ReturnType UPDiSession_CopyNext(tUPDiInstallSession* This, uint32_t ReadOffset, uint32_t Size);
Std_ReturnType UPDiSession_ComposeNext(tUPDiInstallSession* This, uint32_t ReadOffset, uint8_t* Data, uint32_t Size);

Std_ReturnType UPDiSession_ErasePartition(tUPDiInstallSession* This, tUPDiPartition* pPartition);




void UPDiSession_Task(tUPDiInstallSession* This);
#endif
