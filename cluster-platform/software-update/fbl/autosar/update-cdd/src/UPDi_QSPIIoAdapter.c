/***************************************************************************** 
* * 
* CONFIDENTIAL VISTEON CORPORATION * 
* * 
* This is an unpublished work of authorship, which contains trade * 
* secrets, created in 2023. Visteon Corporation owns all rights to * 
* this work and intends to maintain it in confidence to preserve * 
* its trade secret status. Visteon Corporation reserves the right, * 
* under the copyright laws of the United States or those of any * 
* other country that may have jurisdiction, to protect this work * 
* as an unpublished work, in the event of an inadvertent or * 
* deliberate unauthorized publication. Visteon Corporation also * 
* reserves its rights under all copyright laws to protect this * 
* work as a published work, when appropriate. Those having access * 
* to this work may not copy it, use it, modify it or disclose the * 
* information contained in it without the written authorization * 
* of Visteon Corporation. * 
* * 
******************************************************************************/ 
#include "UPDi_QSPIIoAdapter.h" 
#include "UPDd.h" 
#include <string.h> // memcpy 
#include "UPD_ICry.h" 

//===================================================================================================================== 
/* CONSTANTS & TYPES */ 
//===================================================================================================================== 
tUPDiIoAdapterVtbl UPDiQSPIIoAdapterVtbl = 
{ 
    (tUPDiIoAdapter_Task)UPDiQSPIIoAdapter_Task, 
    (tUPDiIoAdapter_StartWriting)UPDiQSPIIoAdapter_StartWriting, 
    (tUPDiIoAdapter_FinishWriting)UPDiQSPIIoAdapter_FinishWriting, 
    (tUPDiIoAdapter_Write)UPDiLocalIoAdapter_Write, 
    (tUPDiIoAdapter_Copy)UPDiLocalIoAdapter_Copy, 
    (tUPDiIoAdapter_Compose)UPDiLocalIoAdapter_Compose, 
    (tUPDiIoAdapter_Read)UPDiQSPIIoAdapter_Read, 
    (tUPDiIoAdapter_Erase)UPDiQSPIIoAdapter_Erase, 
    (tUPDiIoAdapter_StartHashing)UPDiLocalIoAdapter_StartHashing, 
    (tUPDiIoAdapter_Hash)UPDiLocalIoAdapter_Hash, 
    (tUPDiIoAdapter_FinishHashing)UPDiLocalIoAdapter_FinishHashing 
}; 

//===================================================================================================================== 
// Debug helper functions 
//===================================================================================================================== 
#if 0 // for debug purpose only, do not activate in production 
    #include "UPDi_Session.h" 
    extern tUPDiInstallSession Session; 
    extern void TestingStub_QSPIFlashDriver_IsBlank(uint32_t DestAddress, uint32_t Length); 
    #define CHECK_SESSIONS_ADDRESS(This) checkSessionAddress(This) 
    #define CHECK_ERASE_LIMIT(This) checkEraseLimit(This) 
    static void checkSessionAddress(tUPDiQSPIIoAdapter* This) 
    { 
        tUPDiQSPIIoAdapter_Ram* pRam = This->pRam; 
        uint32_t SessionAddress = Session.WritePos + pRam->pDestPartition->Address + pRam->SizeProcessed; 
        uint32_t FilledSize = UPDiLocalIoAdapter_FilledSize((tUPDiLocalIoAdapter*)This); 
        uint32_t AdapterAddress = pRam->CurentAddress + FilledSize; 
        if (pRam->WriteState == UPDi_QSPIIOADAPTER_COMPARING) 
        { 
            AdapterAddress = pRam->SectorAddress + FilledSize; 
        } 
        if (SessionAddress != AdapterAddress) 
        { 
            UPDd_WARNING("SessionAddress & AdapterAddress gap detected"); 
        } 
    } 
    static void checkEraseLimit(tUPDiQSPIIoAdapter* This) 
    { 
        tUPDiQSPIIoAdapter_Ram* pRam = This->pRam; 
        uint32_t EraseLimit = max((pRam->CurentAddress), (pRam->EraseUntilAddress)); 
        uint32_t PartEnd = pRam->pDestPartition->Address + pRam->pDestPartition->Size; 
        if ((EraseLimit != 0xFFFFFFFF) && (PartEnd - EraseLimit)) 
        { 
            TestingStub_QSPIFlashDriver_IsBlank(EraseLimit, PartEnd - EraseLimit); 
        } 
    } 
#else 
    #define CHECK_SESSIONS_ADDRESS(This) 
    #define CHECK_ERASE_LIMIT(This) 
#endif 

//===================================================================================================================== 
// Static Functions 
//===================================================================================================================== 
inline static boolean IsInvalid(tUPDiQSPIIoAdapter* This) 
{ 
    boolean ret = TRUE; 
    #ifndef UPDd_POINTER_TEST_DISABLED 
    if (This != NULL) 
    { 
        ret = (This->pVtbl == NULL) || (This->pRam == NULL); 
    } 
    #else 
    ret = FALSE; 
    #endif 
    return ret; 
} 

inline static uint32_t getSector(tUPDiQSPIIoAdapter* This, uint32_t Address, uint32_t* pSectorAddress) 
{ 
    uint8_t iArea; 
    for (iArea = 0; iArea < This->AreaCount; iArea++) 
    { 
        tUPDiQSPIArea* pAreas = &(This->pAreas[iArea]); 
        if (Address >= pAreas->AreaAddress) 
        { 
            uint32_t Offset = Address - pAreas->AreaAddress; 
            if (Offset < (pAreas->SectorCount * pAreas->SectorSize)) 
            { 
                if (pSectorAddress) 
                { 
                    *pSectorAddress = Address - (Offset % pAreas->SectorSize); 
                } 
                return pAreas->SectorSize; 
            } 
        } 
    } 
    return 0; 
} 

inline static boolean isPageBlank(tUPDiQSPIIoAdapter* This, uint32_t PageOffset) 
{ 
    boolean isBlank = TRUE; 
    tUPDiQSPIIoAdapter_Ram* pRam = This->pRam; 
    uint32_t i = (pRam->GetPos + PageOffset) % This->BufferSize; 
    uint32_t iMax = i + This->PageSize; 
    while (i < iMax) 
    { 
        if (This->pBuffer[i++] != This->BlankPattern) 
        { 
            isBlank = FALSE; 
            break; 
        } 
    } 
    return isBlank; 
} 

static void ProcessEraseResult(tUPDiQSPIIoAdapter* This, QSPIIf_JobResultType JobStatus) 
{ 
    tUPDiQSPIIoAdapter_Ram* pRam = This->pRam; 
    if (JobStatus != QSPIIF_JOB_OK) 
    { 
        pRam->WriteState = UPDi_QSPIIOADAPTER_ERASEERROR; 
    } 
    else 
    { 
        pRam->WriteState = UPDi_QSPIIOADAPTER_BUFFERING_PAGE; 
    } 
} 

static void MoveToNextSector(tUPDiQSPIIoAdapter* This) 
{ 
    tUPDiQSPIIoAdapter_Ram* pRam = This->pRam; 
    uint32_t SectorEndAddress = pRam->SectorAddress + pRam->SectorSize; 
    uint32_t PartitionEndAddress = pRam->pDestPartition->Address + pRam->pDestPartition->Size; 
    if (pRam->CurentAddress < PartitionEndAddress) 
    { 
        pRam->SectorSize = getSector(This, SectorEndAddress, &(pRam->SectorAddress)); 
        if (pRam->SectorSize == 0) 
        { 
            UPDd_ERROR("UPDiQSPIIoAdapter, The partition is not made of contiguous sectors."); 
            pRam->WriteState = UPDi_QSPIIOADAPTER_WRITEFAILED_UNCONTIGOUS_SECTOR; 
        } 
        else if ((pRam->CurentAddress + pRam->SectorSize) > PartitionEndAddress) 
        { 
            pRam->WriteState = UPDi_QSPIIOADAPTER_WRITEFAILED_INVALID_PARTITION_END; 
        } 
        else 
        { 
            pRam->WriteState = UPDi_QSPIIOADAPTER_SECTOR_START; 
            CHECK_ERASE_LIMIT(This); 
        } 
    } 
    else 
    { 
        pRam->WriteState = UPDi_QSPIIOADAPTER_PARTITION_ENDED; 
        pRam->CurentAddress = PartitionEndAddress; 
        pRam->SectorAddress = PartitionEndAddress; 
        pRam->SectorSize = 0; 
        CHECK_SESSIONS_ADDRESS(This); 
    } 
} 

static void ProcessComparisonResult(tUPDiQSPIIoAdapter* This, QSPIIf_JobResultType JobStatus) 
{ 
    tUPDiQSPIIoAdapter_Ram* pRam = This->pRam; 
    if (JobStatus == QSPIIF_JOB_OK) 
    { 
        uint32_t SectorEndAddress = pRam->SectorAddress + pRam->SectorSize; 
        if (pRam->CurentAddress < SectorEndAddress) 
        { 
            pRam->WriteState = UPDi_QSPIIOADAPTER_BUFFERING_SECTOR; 
        } 
        else 
        { 
            UPDiLocalIoAdapter_Consume((tUPDiLocalIoAdapter*)This, pRam->SectorSize); 
            MoveToNextSector(This); 
        } 
    } 
    else 
    { 
        pRam->WriteState = UPDi_QSPIIOADAPTER_SECTOR_START; 
        pRam->CurentAddress = pRam->SectorAddress; 
    } 
} 

static void ProcessWriteResult(tUPDiQSPIIoAdapter* This, QSPIIf_JobResultType JobStatus) 
{ 
    tUPDiQSPIIoAdapter_Ram* pRam = This->pRam; 
    if (JobStatus != QSPIIF_JOB_OK) 
    { 
        pRam->WriteState = UPDi_QSPIIOADAPTER_WRITEERROR; 
    } 
    else 
    { 
        UPDiLocalIoAdapter_Consume((tUPDiLocalIoAdapter*)This, pRam->CurentSize); 
        pRam->CurentAddress += pRam->CurentSize; 
        if (pRam->CurentAddress >= (pRam->SectorSize + pRam->SectorAddress)) 
        { 
            MoveToNextSector(This); 
        } 
        else 
        { 
            pRam->WriteState = UPDi_QSPIIOADAPTER_BUFFERING_PAGE; 
        } 
    } 
} 

static void FetchSectorData(tUPDiQSPIIoAdapter* This) 
{ 
    tUPDiQSPIIoAdapter_Ram* pRam = This->pRam; 
    uint32_t ComparedInSector = pRam->CurentAddress - pRam->SectorAddress; 
    uint32_t AvailableDataSize = UPDiLocalIoAdapter_FilledSize((tUPDiLocalIoAdapter*)This); 
    if (AvailableDataSize > ComparedInSector) 
    { 
        uint8_t* pNewData = UPDiLocalIoAdapter_GetFilledData((tUPDiLocalIoAdapter*)This, pRam->CurentAddress - pRam->SectorAddress, &AvailableDataSize); 
        uint32_t RemainsInSector = pRam->SectorSize - ComparedInSector; 
        uint32_t Size = min(RemainsInSector, AvailableDataSize); 
        if (This->QSPIFlashDriver->Compare(pRam->CurentAddress, pNewData, Size) == E_OK) 
        { 
            pRam->CurentAddress += Size; 
            pRam->WriteState = UPDi_QSPIIOADAPTER_COMPARING; 
        } 
        else 
        { 
            pRam->WriteState = UPDi_QSPIIOADAPTER_WRITEERROR; 
        } 
    } 
} 

static void FetchPageData(tUPDiQSPIIoAdapter* This) 
{ 
    tUPDiQSPIIoAdapter_Ram* pRam = This->pRam; 
    uint32_t RemainsInSector = pRam->SectorSize + pRam->SectorAddress - pRam->CurentAddress; 
    uint32_t PendingSize = min(RemainsInSector, UPDiLocalIoAdapter_ConsecutiveFilledSize((tUPDiLocalIoAdapter*)This)); 
    PendingSize = PendingSize - (PendingSize % This->PageSize); 
    if (This->EnableBlankDetection) 
    { 
        while (PendingSize) 
        { 
            if (isPageBlank(This, 0)) 
            { 
                UPDiLocalIoAdapter_Consume((tUPDiLocalIoAdapter*)This, This->PageSize); 
                pRam->CurentSize = This->PageSize; 
                pRam->CurentAddress += This->PageSize; 
                PendingSize -= This->PageSize; 
            } 
            else 
            { 
                break; 
            } 
        } 
        uint32_t FirstBlankPageOffset = This->PageSize; 
        while ((FirstBlankPageOffset + This->PageSize) <= PendingSize) 
        { 
            if (isPageBlank(This, FirstBlankPageOffset)) 
            { 
                PendingSize = FirstBlankPageOffset; 
                break; 
            } 
            else 
            { 
                FirstBlankPageOffset += This->PageSize; 
            } 
        } 
    } 
    if (PendingSize) 
    { 
        if (This->QSPIFlashDriver->Write(0u, pRam->CurentAddress, &This->pBuffer[pRam->GetPos], PendingSize) == E_OK) 
        { 
            pRam->CurentSize = PendingSize; 
            pRam->WriteState = UPDi_QSPIIOADAPTER_WRITING; 
        } 
        else 
        { 
            pRam->WriteState = UPDi_QSPIIOADAPTER_WRITEERROR; 
        } 
    } 
    else if (pRam->CurentAddress >= (pRam->SectorSize + pRam->SectorAddress)) 
    { 
        MoveToNextSector(This); 
    } 
} 

static void StartSector(tUPDiQSPIIoAdapter* This, boolean UnkownSectorContent) 
{ 
    tUPDiQSPIIoAdapter_Ram* pRam = This->pRam; 
    pRam->CurentAddress = pRam->SectorAddress; 
    if (pRam->SectorAddress >= pRam->EraseUntilAddress) 
    { 
        CHECK_ERASE_LIMIT(This); 
        pRam->WriteState = UPDi_QSPIIOADAPTER_BUFFERING_PAGE; 
        FetchPageData(This); 
    } 
    else if ((This->EnableSectorBufferring == TRUE) && UnkownSectorContent) 
    { 
        if (This->BufferSize > pRam->SectorSize) 
        { 
            pRam->WriteState = UPDi_QSPIIOADAPTER_BUFFERING_SECTOR; 
            FetchSectorData(This); 
        } 
        else 
        { 
            UPDd_WARNING("Sector Buffering is enabled but BufferSize is too small to hold a sector of %d", pRam->SectorSize); 
        } 
    } 
    if (pRam->WriteState == UPDi_QSPIIOADAPTER_SECTOR_START) 
    { 
        if (This->QSPIFlashDriver->Erase(0u, pRam->SectorAddress, pRam->SectorSize, FALSE) == E_OK) 
        { 
            pRam->WriteState = UPDi_QSPIIOADAPTER_ERASING; 
        } 
        else 
        { 
            pRam->WriteState = UPDi_QSPIIOADAPTER_WRITEERROR; 
        } 
    } 
} 

static void ProcessRequest(tUPDiQSPIIoAdapter* This) 
{ 
    tUPDiQSPIIoAdapter_Ram* pRam = This->pRam; 
    if (pRam->WriteState & UPDi_QSPIIOADAPTER_PROCESSING_MASK) 
    { 
    } 
    else if ((pRam->RequestState == UPDi_QSPIREQ_READ_PENDING)) 
    { 
        if (This->QSPIFlashDriver->Read(pRam->ReqPartition->Address + pRam->ReqOffset, pRam->ReqData, pRam->ReqSize) == E_OK) 
        { 
            pRam->RequestState = UPDi_QSPIREQ_READING; 
            pRam->ReqStatus = This->QSPIFlashDriver->GetJobResult(0); 
        } 
    } 
    else if ((pRam->RequestState == UPDi_QSPIREQ_ERASE_PENDING)) 
    { 
        pRam->SectorSize = getSector(This, pRam->ReqPartition->Address, &pRam->SectorAddress); 
        if (This->QSPIFlashDriver->Erase(0u, pRam->SectorAddress, pRam->SectorSize, FALSE) == E_OK) 
        { 
            pRam->RequestState = UPDi_QSPIREQ_ERASING; 
        } 
    } 
    else if ((pRam->RequestState != UPDi_QSPIREQ_NONE) && (pRam->ReqStatus == E_PENDING)) 
    { 
        pRam->ReqStatus = This->QSPIFlashDriver->GetJobResult(0); 
        if ((pRam->RequestState == UPDi_QSPIREQ_ERASING) && (pRam->ReqStatus == MEMIF_JOB_OK)) 
        { 
            uint32_t SectorEndAddress = pRam->SectorAddress + pRam->SectorSize; 
            if (SectorEndAddress < (pRam->ReqPartition->Address + pRam->ReqPartition->Size)) 
            { 
                pRam->SectorSize = getSector(This, SectorEndAddress, &pRam->SectorAddress); 
                if (This->QSPIFlashDriver->Erase(0u, pRam->SectorAddress, pRam->SectorSize, FALSE) == E_OK) 
                { 
                    pRam->ReqStatus = E_PENDING; 
                } 
            } 
        } 
    } 
} 

//===================================================================================================================== 
// Public functions 
//===================================================================================================================== 
void UPDiQSPIIoAdapter_Init(tUPDiQSPIIoAdapter* This) 
{ 
    if (!IsInvalid(This)) 
    { 
        tUPDiQSPIIoAdapter_Ram* pRam = This->pRam; 
        memset(pRam, 0, sizeof(*pRam)); 
    } 
} 

Std_ReturnType UPDiQSPIIoAdapter_StartWriting(tUPDiQSPIIoAdapter* This, tUPDiPartition* pDestPartition, uint32_t DestOffset, uint32_t EraseUntil) 
{ 
    Std_ReturnType Status = E_NOT_OK; 
    if (!IsInvalid(This)) 
    { 
        tUPDiQSPIIoAdapter_Ram* pRam = This->pRam; 
        pRam->SectorSize = getSector(This, pDestPartition->Address + DestOffset, &pRam->SectorAddress); 
        if (!pDestPartition) 
        { 
        } 
        else if (DestOffset >= pDestPartition->Size) 
        { 
            UPDd_ERROR("UPDiQSPIIoAdapter_StartWriting(): attempting to write after partition end."); 
        } 
        else if (pRam->SectorAddress != pDestPartition->Address + DestOffset) 
        { 
            UPDd_ERROR("UPDiQSPIIoAdapter_StartWriting(): DestOffset shall be a sector start."); 
        } 
        else if ((This->BufferSize % This->PageSize) != 0) 
        { 
            UPDd_ERROR("UPDiQSPIIoAdapter_StartWriting(): BufferSize shall be multiple of PageSize."); 
        } 
        else if (This->BufferSize < This->PageSize) 
        { 
            UPDd_ERROR("UPDiQSPIIoAdapter_StartWriting(): BufferSize shall be higher than PageSize."); 
        } 
        else if (pRam->RequestState != UPDi_QSPIREQ_NONE) 
        { 
            Status = E_PENDING; 
            if (This->QSPIFlashDriver->GetJobResult(0) != MEMIF_JOB_PENDING) 
            { 
                pRam->RequestState = UPDi_QSPIREQ_NONE; 
            } 
        } 
        else 
        { 
            if (pRam->pDestPartition) 
            { 
                UPDd_WARNING("UPDiLocalIoAdapter, a writing session has started before finalizing the previous writing session."); 
            } 
            if (pRam->Hash.HashType != eUPDiHash_Invalid) 
            { 
                UPDd_WARNING("UPDiLocalIoAdapter, a writing session has started before finalizing the previous hashing session."); 
            } 
            pRam->PutPos = 0; 
            pRam->GetPos = 0; 
            pRam->pDestPartition = pDestPartition; 
            pRam->SizeProcessed = 0; 
            pRam->ReadSize = 0; 
            if (EraseUntil != UPDi_ERASEALL) 
            { 
                pRam->EraseUntilAddress = EraseUntil + pDestPartition->Address; 
                pRam->CurentAddress = pRam->SectorAddress; 
                CHECK_ERASE_LIMIT(This); 
            } 
            else 
            { 
                pRam->EraseUntilAddress = UPDi_ERASEALL; 
            } 
            pRam->Hash.HashType = eUPDiHash_Invalid; 
            pRam->Hash.HashSize = 0; 
            pRam->Hash.pHash = NULL; 
            pRam->WriteState = UPDi_QSPIIOADAPTER_SECTOR_START; 
            pRam->CurentAddress = pRam->pDestPartition->Address + DestOffset; 
            pRam->SectorSize = 0; 
            MoveToNextSector(This); 
            CHECK_SESSIONS_ADDRESS(This); 
            Status = E_OK; 
        } 
    } 
    return Status; 
} 

Std_ReturnType UPDiQSPIIoAdapter_FinishWriting(tUPDiQSPIIoAdapter* This, boolean ProcessQueue, uint32_t* pResumeAt, uint32_t* pEraseUntil) 
{ 
    Std_ReturnType Status = E_NOT_OK; 
    UPDiQSPIIoAdapter_Task(This); 
    if (!IsInvalid(This)) 
    { 
        tUPDiQSPIIoAdapter_Ram* pRam = This->pRam; 
        if (pRam->pDestPartition == NULL) 
        { 
            Status = E_NOT_OK; 
        } 
        else if (pRam->WriteState & UPDi_QSPIIOADAPTER_WRITEFAILURE_MASK) 
        { 
            Status = E_NOT_OK; 
        } 
        else if ((pRam->WriteState & UPDi_QSPIIOADAPTER_PROCESSING_MASK) || (ProcessQueue && (UPDiLocalIoAdapter_FilledSize((tUPDiLocalIoAdapter*)This) != 0))) 
        { 
            Status = E_PENDING; 
        } 
        else 
        { 
            if (pResumeAt) 
            { 
                *pResumeAt = pRam->SectorAddress - pRam->pDestPartition->Address; 
            } 
            if (pEraseUntil) 
            { 
                if (pRam->EraseUntilAddress != UPDi_ERASEALL) 
                { 
                    *pEraseUntil = max(pRam->CurentAddress - pRam->pDestPartition->Address, pRam->EraseUntilAddress - pRam->pDestPartition->Address); 
                } 
                else 
                { 
                    *pEraseUntil = pRam->EraseUntilAddress - pRam->pDestPartition->Address; 
                } 
            } 
            pRam->pDestPartition = NULL; 
            pRam->WriteState = UPDi_QSPIIOADAPTER_IDLE; 
            pRam->SectorSize = 0; 
            Status = E_OK; 
        } 
    } 
    return Status; 
} 

tUPDWorkload UPDiQSPIIoAdapter_Task(tUPDiQSPIIoAdapter* This) 
{ 
    tUPDWorkload load = eUPD_eWlLow; 
    if (!IsInvalid(This)) 
    { 
        tUPDiQSPIIoAdapter_Ram* pRam = This->pRam; 
        boolean UnkownSectorContent = TRUE; 
        uint32_t FilledSize; 
        CHECK_ERASE_LIMIT(This); 
        CHECK_SESSIONS_ADDRESS(This); 
        if (pRam->WriteState & UPDi_QSPIIOADAPTER_PROCESSING_MASK) 
        { 
            QSPIIf_JobResultType JobStatus = This->QSPIFlashDriver->GetJobResult(0); 
            if (JobStatus == MEMIF_JOB_PENDING) 
            { 
            } 
            else if (pRam->WriteState == UPDi_QSPIIOADAPTER_COMPARING) 
            { 
                ProcessComparisonResult(This, JobStatus); 
                UnkownSectorContent = FALSE; 
            } 
            else if (pRam->WriteState == UPDi_QSPIIOADAPTER_ERASING) 
            { 
                ProcessEraseResult(This, JobStatus); 
            } 
            else if (pRam->WriteState == UPDi_QSPIIOADAPTER_WRITING) 
            { 
                ProcessWriteResult(This, JobStatus); 
            } 
            else 
            { 
                UPDd_ERROR("Unknown job result received"); 
            } 
        } 
        FilledSize = UPDiLocalIoAdapter_FilledSize((tUPDiLocalIoAdapter*)This); 
        if (pRam->WriteState & UPDi_QSPIIOADAPTER_PROCESSING_MASK) 
        { 
        } 
        else if ((pRam->RequestState != UPDi_QSPIREQ_NONE) && (pRam->ReqStatus == E_PENDING)) 
        { 
            ProcessRequest(This); 
        } 
        else if (FilledSize == 0) 
        { 
        } 
        else if (pRam->WriteState == UPDi_QSPIIOADAPTER_SECTOR_START) 
        { 
            StartSector(This, UnkownSectorContent); 
        } 
        else if (pRam->WriteState == UPDi_QSPIIOADAPTER_BUFFERING_SECTOR) 
        { 
            FetchSectorData(This); 
        } 
        else if (pRam->WriteState == UPDi_QSPIIOADAPTER_BUFFERING_PAGE) 
        { 
            FetchPageData(This); 
        } 
        else if (pRam->WriteState & UPDi_QSPIIOADAPTER_WRITEFAILURE_MASK) 
        { 
            UPDiLocalIoAdapter_ConsumeAll((tUPDiLocalIoAdapter*)This); 
        } 
        else 
        { 
            UPDd_WARNING("UPDiQSPIIoAdapter: unexpected data received"); 
            pRam->WriteState = UPDi_QSPIIOADAPTER_WRITEFAILED_UNEXPECTED_DATA; 
        } 
        CHECK_ERASE_LIMIT(This); 
        if ((FilledSize == 0) && (pRam->WriteState == UPDi_QSPIIOADAPTER_IDLE) && (pRam->RequestState == UPDi_QSPIREQ_NONE)) 
        { 
            load = eUPD_eWlIdle; 
        } 
        else if ((FilledSize < This->LowBufferThreshold)) 
        { 
            load = eUPD_eWlLow; 
        } 
        else if (FilledSize > (This->BufferSize - This->PageSize)) 
        { 
            load = eUPD_eWlFull; 
        } 
        else 
        { 
            load = eUPD_eWlHigh; 
        } 
    } 
    return load; 
} 

Std_ReturnType UPDiQSPIIoAdapter_Read(tUPDiQSPIIoAdapter* This, tUPDiPartition* Partition, uint32_t Offset, uint32_t Size, uint8_t* Data) 
{ 
    Std_ReturnType Status = E_NOT_OK; 
    if (!IsInvalid(This)) 
    { 
        tUPDiQSPIIoAdapter_Ram* pRam = This->pRam; 
        if (This->QSPIFlashDriver->Read == NULL) 
        { 
            #if (UINTPTR_MAX == 0xffffffff) 
            void* pSrc = Partition->Address + Offset; 
            memcpy(Data, pSrc, Size); 
            pRam->ReqStatus = MEMIF_JOB_OK; 
            #else 
            UPDd_ERROR("UPDiQSPIIoAdapter_Read(), cannot read flash by pointer if the address space is not 32Bits"); 
            #endif 
        } 
        else 
        { 
            if (pRam->RequestState == UPDi_QSPIREQ_NONE) 
            { 
                pRam->ReqOffset = Offset; 
                pRam->ReqSize = Size; 
                pRam->ReqData = Data; 
                pRam->ReqPartition = Partition; 
                pRam->RequestState = UPDi_QSPIREQ_READ_PENDING; 
                pRam->ReqStatus = MEMIF_JOB_PENDING; 
            } 
            ProcessRequest(This); 
        } 
        if (pRam->ReqStatus == MEMIF_JOB_PENDING) 
        { 
            Status = E_PENDING; 
        } 
        else if (pRam->ReqStatus == MEMIF_JOB_OK) 
        { 
            Status = E_OK; 
            pRam->RequestState = UPDi_QSPIREQ_NONE; 
            pRam->ReqPartition = NULL; 
        } 
        else 
        { 
            pRam->ReqStatus = E_NOT_OK; 
            pRam->RequestState = UPDi_QSPIREQ_NONE; 
            pRam->ReqPartition = NULL; 
        } 
    } 
    return Status; 
} 

Std_ReturnType UPDiQSPIIoAdapter_Erase(tUPDiQSPIIoAdapter* This, tUPDiPartition* Partition) 
{ 
    Std_ReturnType Status = E_NOT_OK; 
    if (!IsInvalid(This)) 
    { 
        tUPDiQSPIIoAdapter_Ram* pRam = This->pRam; 
        if (pRam->RequestState == UPDi_QSPIREQ_NONE) 
        { 
            pRam->ReqOffset = 0; 
            pRam->ReqSize = 0; 
            pRam->ReqData = 0; 
            pRam->ReqPartition = Partition; 
            pRam->RequestState = UPDi_QSPIREQ_ERASE_PENDING; 
            pRam->ReqStatus = MEMIF_JOB_PENDING; 
        } 
        ProcessRequest(This); 
        if (pRam->ReqStatus == MEMIF_JOB_PENDING) 
        { 
            Status = E_PENDING; 
        } 
        else if (pRam->ReqStatus == MEMIF_JOB_OK) 
        { 
            Status = E_OK; 
            pRam->RequestState = UPDi_QSPIREQ_NONE; 
            pRam->ReqPartition = NULL; 
        } 
        else 
        { 
            pRam->ReqStatus = E_NOT_OK; 
            pRam->RequestState = UPDi_QSPIREQ_NONE; 
            pRam->ReqPartition = NULL; 
        } 
    } 
    return Status; 
} 
