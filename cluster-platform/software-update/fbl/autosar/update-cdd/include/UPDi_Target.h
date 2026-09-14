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

# ifndef UPD_Target_H
# define UPD_Target_H

# include "Std_Types.h"
# include "UPDd.h" // for the Manifest structure
# include <stdint.h>

//=====================================================================================================================
/* MACRO : Construction helper */
//=====================================================================================================================
#define UPD_DECLARE_TARGET(_type_, _name_, _groupArray_) \
		tUPDiTargetRam  _name_##_Ram;\
		tUPDiTargetSlot _name_##_Slots[((_type_)==eTargetTypeAOnly)? 1 : UPD_AB_SLOT_COUNT];\
		tUPDiTarget _name_ = \
		{\
			.Name = #_name_,\
			.pRam = &_name_##_Ram,\
			.Type = _type_,\
			.GroupsCount = sizeof(_groupArray_)/sizeof(tUPDiPartitionGroup),\
			.pGroups =&_groupArray_[0],\
			.pSlots = &_name_##_Slots[0],\
			.SizeOfSlots = sizeof(_name_##_Slots),\
		};

//=====================================================================================================================
/* CONSTANTS & TYPES */
//=====================================================================================================================
struct sUPDIoAdapter;
struct sUPDInstallSession;
struct sUPDiTarget;

#define UPD_AB_SLOT_COUNT (2u)

enum // target types
{
	eTargetTypeAOnly    = 0x1,
	eTargetTypeAB       = 0x2,
	eTargetTypeABExt    = 0x3,
	eTargetTypeRemote   = 0x4,
};

typedef struct sUPDiTargetSlot
{
    tUPDdManifest Manifest;
    tUPDiTargetState State;
} tUPDiTargetSlot;

typedef struct sUPDiTargetRam
{
    // for erase, copy, deploy or crc iterations
    uint16_t nextPartitionIndex;
    // for erase, copy, deploy or crc iterations
    uint32_t nextByte;
    uint32_t lastShortHash;
    uint8_t  eraseCycles;
    uint8_t  hashingCycles;
} tUPDiTargetRam;

typedef const struct sUPDiTarget
{
    tUPDiTargetRam* pRam;
    const char* Name;
    tUPDiPartitionGroup* pGroups;
    tUPDiTargetSlot* pSlots;
    uint16_t GroupsCount;
    uint16_t SizeOfSlots; // for consistency check
    uint8_t  Type;

} tUPDiTarget;


//=====================================================================================================================
//  User functions
//=====================================================================================================================
// User requests
Std_ReturnType UPDTarget_CopyToInactive(tUPDiTarget* this);
Std_ReturnType UPDTarget_Deploy(tUPDiTarget* this);
Std_ReturnType UPDTarget_Verify(tUPDiTarget* this, tUPDiInstallSession* pSession, tUPDHashInfo* pHash);
Std_ReturnType UPDTarget_GetHash(tUPDiTarget* this, tUPDiInstallSession* pSession, tUPDHashInfo* pHash,boolean reHash);
Std_ReturnType UPDTarget_Inspect(tUPDiTarget* this,  tUPDBank Bank);
Std_ReturnType UPDTarget_Invalidate(tUPDiTarget* this,  tUPDBank Bank);

// accesor services
tUPDdManifest*   UPDTarget_GetManifest(tUPDiTarget* this, tUPDBank Bank);
const char*      UPDTarget_GetName(tUPDiTarget* this);
tUPDiPartition*  UPDTarget_GetPartition(tUPDiTarget* this, const char* PartitionName, boolean read);
uint8_t  			 UPDTarget_GetPartitionId(tUPDiTarget* this,tUPDiPartition*);
tUPDiPartition*	 UPDTarget_GetPartitionById(tUPDiTarget* this,uint8_t);
tUPDiTargetState UPDTarget_GetState(tUPDiTarget* this, tUPDBank Bank);

//=====================================================================================================================
//  Triggers functions
//=====================================================================================================================
// Installation triggers
Std_ReturnType  UPDTarget_InstallStart(tUPDiTarget* this, struct sUPDiInstallSession* Session);
Std_ReturnType  UPDTarget_InstallExit(tUPDiTarget* this, struct sUPDiInstallSession* Session);

//=====================================================================================================================
//  Management functions
//=====================================================================================================================
void UPDTarget_Init(tUPDiTarget* this);
void UPDTarget_SetState(tUPDiTarget* this, tUPDiTargetState State);
void UPDTarget_Suspend(tUPDiTarget* This);
Std_ReturnType UPDTarget_Deserialize(tUPDiTarget* This, tUPDStream* pStream);
Std_ReturnType UPDTarget_Serialize(tUPDiTarget* This, tUPDStream* pStream);
Std_ReturnType UPDTarget_ProcessIO(tUPDiTarget* This, tUPDiInstallSession* pSession, tUPDiOpType operation, boolean opStart);
tUPDiOpType    UPDTarget_GetNextOperation(tUPDiTarget* This,tUPDUpdateState UpdateState);
#endif 
