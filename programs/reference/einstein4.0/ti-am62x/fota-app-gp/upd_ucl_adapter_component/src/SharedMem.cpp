//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2021] Visteon Corporation
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
//
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>

#include "SharedMem.h"

#define INVALID_INDEX 0xFFu

LOG_IMPORT_CONTEXT(BlAppGpLogContext);

static const SharedMemObjConfigS SharedMemObjCfg[EMemCtrlShMem_BankMax] ={
		EMemCtrlShMem_Bank1,
		DDR_SHAREDMEMORY_STARTADDRESS1,
		MAX_SIZE_OF_SHARED_MEMORY,

		EMemCtrlShMem_Bank2,
		DDR_SHAREDMEMORY_STARTADDRESS2,
		MAX_SIZE_OF_SHARED_MEMORY
};

static SharedMemObjInsS    SharedMemObj[EMemCtrlShMem_BankMax];

/// Start of user code : Footer user code for file bl_vip_installer_component.cpp

void CSharedMemCtrl::CreateSharedMemInstance(void)
{
	EMemCtrlShMem_t i;
	EMemCtrlShMem_t LBank;
	/* Initialize the Shared memory instance */

	printf("Creating Sharememory instance ..! \n");
	for(i=0; i< EMemCtrlShMem_BankMax; i++)
	{
		SharedMemObj[i].State = ESharedMemObjState_NotActive;
		SharedMemObj[i].ptrSharedMemObj = NULL;
		SharedMemObj[i].SharedMemObjSize = 0;
		SharedMemObj[i].ptrShmMemDataCopy = NULL;
		SharedMemObj[i].Mutex = PTHREAD_MUTEX_INITIALIZER;
	}

	/* Create the Shared memory instance diffrent banck */

	for(i=0; i< EMemCtrlShMem_BankMax; i++)
	{
		LBank = SharedMemObjCfg[i].InstanceId;
		if(LBank < EMemCtrlShMem_BankMax)
		{
			if (SharedMemObj[LBank].State == ESharedMemObjState_NotActive)
			{
				SharedMemObj[LBank].State = ESharedMemObjState_Create;
				SharedMemObjState_Create(LBank);
			}
		}
	}
}

void CSharedMemCtrl::ReleaseSharedMemInstance(void)
{
	uint8 i;
	EMemCtrlShMem_t LBank;
	for(i=0; i< EMemCtrlShMem_BankMax; i++)
	{
		LBank = SharedMemObjCfg[i].InstanceId;
		if(SharedMemObj[LBank].ptrSharedMemObj != NULL)
		{
			(void)munmap(SharedMemObj[LBank].ptrSharedMemObj, SharedMemObjCfg[i].size);
		}
		if (SharedMemObj[LBank].ptrShmMemDataCopy != NULL)
		{
			free(SharedMemObj[LBank].ptrShmMemDataCopy);
			SharedMemObj[LBank].ptrShmMemDataCopy = NULL;
		}

	}
}

void CSharedMemCtrl::SharedMemObjState_Create(uint8 BankIndex)
{
	int fd;
	SharedMemObj[BankIndex].ptrSharedMemObj = (uint8 *)MAP_FAILED;

	if(BankIndex != INVALID_INDEX)
	{
		fd = open("/dev/mem", O_RDWR|O_SYNC );

		if ( fd == -1 )
		{
			LOGE ( &BlAppGpLogContext, "UclALPhyMuLinux_Impl", "%s", "Hw_MuOpen open Failed\n" );
			printf(" FILE OPEN FAILED%d ..! \n", BankIndex);
		}
    	else
    	{

			SharedMemObj[BankIndex].ptrSharedMemObj = (uint8 *) mmap(NULL, SharedMemObjCfg[BankIndex].size, PROT_READ|PROT_WRITE, MAP_SHARED, fd, SharedMemObjCfg[BankIndex].SharedMemPhyAddress);
		}

		if (MAP_FAILED == SharedMemObj[BankIndex].ptrSharedMemObj)
		{
			SharedMemObj[BankIndex].State = ESharedMemObjState_CreateFailed;
			LOGE ( &BlAppGpLogContext, "SharedMemObjStateCtrl ", " faild" );
			printf("Mapping FAILED for bank %d ..! \n", BankIndex);
		}
		else
		{
			LOGI ( &BlAppGpLogContext, "SharedMemObjStateCtrl:mmap_device_memory"," Returnadress ", SharedMemObj[BankIndex].ptrSharedMemObj,  ", totsl Size = ", SharedMemObjCfg[BankIndex].size, ", adress ", SharedMemObjCfg[BankIndex].SharedMemPhyAddress);
			CreateSharedMemInsMutex(BankIndex);
			SharedMemObj[BankIndex].ptrShmMemDataCopy = (uint8 *) malloc(SharedMemObjCfg[BankIndex].size);
		}
		close(fd);
	}
	else
	{
		printf("Invalid memory Bank index..\n");
	}
}


/*Write and read state*/
uint8 * CSharedMemCtrl::GetShmMemDataPtr(EMemCtrlShMem_t LBankId, uint32 size, uint8 cmd)
{
	if(LBankId < EMemCtrlShMem_BankMax )
	{
		LockMutex(SharedMemObjCfg[LBankId].InstanceId);

		if(SharedMemObj[LBankId].ptrShmMemDataCopy != NULL)
		{
			for(uint32 i = 0; i < size ;i++)
			{
				SharedMemObj[LBankId].ptrShmMemDataCopy[i] = SharedMemObj[LBankId].ptrSharedMemObj[i];
			}
        }

		UnlockMutex(SharedMemObjCfg[LBankId].InstanceId);
	}
	else
	{
		LOGE ( &BlAppGpLogContext, "GetShmMemDataPtr ",  " No ReadReady ");
	}

	return SharedMemObj[LBankId].ptrShmMemDataCopy;
}


uint8 CSharedMemCtrl::SetShmMemDataPtr(EMemCtrlShMem_t LBankId, uint32 size, uint8* Buff)
{
	for(uint32 i = 0; i < size ;i++)
	{
		SharedMemObj[LBankId].ptrSharedMemObj[i] = Buff[i];
	}

	return 0;
}

/* Recived Banck number */
uint8 CSharedMemCtrl::GetShmMemObjIndex(EMemCtrlShMem_t  LBank)
{
	uint8 i;
	uint8 RetIndex = INVALID_INDEX;
	for(i=0; i< EMemCtrlShMem_BankMax; i++)
	{
		if(SharedMemObjCfg[i].InstanceId == LBank)
		{
			RetIndex = i;
		}
	}

	return RetIndex;

}
/* Recived Banck number */
void CSharedMemCtrl::CreateSharedMemInsMutex (EMemCtrlShMem_t LBank)
{
  pthread_mutexattr_t attr;

	if(LBank < EMemCtrlShMem_BankMax)
	{
  		pthread_mutexattr_init(&attr);
  		if (0 != pthread_mutexattr_settype(&attr,PTHREAD_MUTEX_RECURSIVE ))
  		{
    		pthread_mutexattr_destroy(&attr);
  		}
  		if (0 != pthread_mutex_init( &SharedMemObj[LBank].Mutex, &attr ))
  		{
  		}
  		pthread_mutexattr_destroy(&attr);
  	}
}


int CSharedMemCtrl::LockMutex(EMemCtrlShMem_t LBank)
{
	int ret = EOK ;
	if(LBank < EMemCtrlShMem_BankMax)
	{
		if(pthread_mutex_lock(&SharedMemObj[LBank].Mutex)!= EOK)
		{
			ret = -1;
		}
	}

	return ret;
}


int CSharedMemCtrl::UnlockMutex(EMemCtrlShMem_t LBank)
{
	int ret = EOK ;
	if(LBank < EMemCtrlShMem_BankMax)
	{
		if(pthread_mutex_unlock(&SharedMemObj[LBank].Mutex)!= EOK)
		{
			ret = -1;
		}
	}

	return ret;

}

