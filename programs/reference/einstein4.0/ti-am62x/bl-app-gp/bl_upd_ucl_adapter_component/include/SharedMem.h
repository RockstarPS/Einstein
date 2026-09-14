///---------------------------------------------------------------------------------------------------------------------
///
/// VISTEON CORPORATION CONFIDENTIAL
/// ________________________________
///
/// [2017] Visteon Corporation
/// All Rights Reserved.
///
/// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
/// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
/// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
/// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
/// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
/// under all copyright laws to protect this work as a published work, when appropriate.
/// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
/// without the written authorization of Visteon Corporation.
///
///---------------------------------------------------------------------------------------------------------------------
#ifndef __SharedMemCtrl_H__
#define __SharedMemCtrl_H__

#include <thread>
#include <map>
#include "dk_logger.h"
#include "dk_runtime_bl_upd_ucl_adapter_component.h"

//=======================================================================================================================
// Class implementing  shared memory instance
//=======================================================================================================================
using namespace dk::runtime;

typedef uint8_t EMemCtrlShMem_t;
#define EMemCtrlShMem_Bank1        ((EMemCtrlShMem_t)0)
#define EMemCtrlShMem_Bank2        ((EMemCtrlShMem_t)1)
#define EMemCtrlShMem_BankMax        ((EMemCtrlShMem_t)2)
#define MAX_SIZE_OF_SHARED_MEMORY   	(0x100000)
#define DDR_SHAREDMEMORY_STARTADDRESS1	(0x82400000)
#define DDR_SHAREDMEMORY_STARTADDRESS2	(DDR_SHAREDMEMORY_STARTADDRESS1 + MAX_SIZE_OF_SHARED_MEMORY)

typedef enum ESharedMemObjState_t
{
	ESharedMemObjState_NotActive,
	ESharedMemObjState_Create,
	ESharedMemObjState_CreateFailed,
	ESharedMemObjState_Idle,
	ESharedMemObjState_Busy,
	ESharedMemObjState_PendigRead,
	ESharedMemObjState_Invalid,
    ESharedMemObjState_Count
} ESharedMemObjState;
/* Possible Values for Shared memory instance state*/
typedef enum EMemmoryObjState_t
{
	EMemmoryObjState_NotActive,
	EMemmoryObjState_FileOpenFail,
	EMemmoryObjState_ReadReady,
	EMemmoryObjState_Write,
	EMemmoryObjState_Idle,
    EMemmoryObjState_Count
} EMemmoryObjState;

/* Possible commands  to perfrom action on Shared memory instance */
typedef enum ESharedMemObjCmd_t
{
	ESharedMemObjCmd_Idle,
	ESharedMemObjCmd_Create,
	ESharedMemObjCmd_CreateFailed,
	ESharedMemObjCmd_CopyData,
	ESharedMemObjCmd_CopyComplete,
	ESharedMemObjCmd_Invalidate,
    ESharedMemObjCmd_Count
} ESharedMemObjCmd;

/* Data structure for managing shared memory instance*/
typedef struct SharedMemObjInsS_t
{
    ESharedMemObjState State;               /* Instance ID */
    uint8 *ptrSharedMemObj;    /* Shared memory physical address */
    uint32 SharedMemObjSize;
    pthread_mutex_t Mutex;
    uint8 *ptrShmMemDataCopy;    /* Shared memory physical address */
} SharedMemObjInsS;

/* Data structure for managing shared memory instance*/
typedef struct MemmoryObjInsS_t
{
    EMemmoryObjState LState;               /* Instance ID */
    uint32 MemObjSize;
} MemmoryObjInsS;


/* Data structure for configuring shared memory instance*/

typedef struct SharedMemObjConfigS_t
{
    EMemCtrlShMem_t InstanceId;                     /* Instance ID */
	uint32 SharedMemPhyAddress;
	uint32 size;
} SharedMemObjConfigS;

class CSharedMemCtrl
{

public:

	/* Constructor */
	CSharedMemCtrl()
	{
	}

	/* Shared memory control API's */
	void CreateSharedMemInstance(void);
	void SharedMemObjState_Create(uint8 BankIndex);
	uint8  * GetShmMemDataPtr(EMemCtrlShMem_t LBankId, uint32 size, uint8 cmd);
	uint8    SetShmMemDataPtr(EMemCtrlShMem_t LBankId, uint32 size, uint8 *Buff);
	//void SharedMemObjStateCtrl(FotaMemCtrlReqData* PtrResShmMemObj);
	void CreateSharedMemInsMutex (EMemCtrlShMem_t LBank);
	void ReleaseSharedMemInstance(void);

	int LockMutex(EMemCtrlShMem_t LBank);
	int UnlockMutex(EMemCtrlShMem_t LBank);


private:
    uint8 GetShmMemObjIndex(EMemCtrlShMem_t LBank);
	void MemObjStateCtrl(EMemmoryObjState state,uint8 i);
};





#endif