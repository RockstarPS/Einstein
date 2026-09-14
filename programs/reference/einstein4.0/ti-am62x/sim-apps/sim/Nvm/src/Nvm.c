#include "Rte_Type.h"
#include "Rte_NvM.h"
#include "NvM_Cfg.h"
#include "SchM_NvM.h"
#include "string.h"
#include "NvM.h"

static unsigned char lNVMReadAllRequest;

void NvM_Init(const NvM_ConfigType* ConfigPtr)
{

}

Std_ReturnType NvM_GetErrorStatus( NvM_BlockIdType BlockId, NvM_RequestResultType* RequestResultPtr)
{
	return(E_OK);
}

void NvM_ReadAll(void)
{
    unsigned short int flNvmblockLoop;
	
	for(flNvmblockLoop = 0; flNvmblockLoop<NVM_NUM_OF_BLOCKS;flNvmblockLoop++)
	{
		 if((NvM_BlockConfig[flNvmblockLoop].RamBlockDataAddress != NULL) &&
		    (NvM_BlockConfig[flNvmblockLoop].RomBlockDataAddress != NULL))
		{
			memcpy(NvM_BlockConfig[flNvmblockLoop].RamBlockDataAddress,
		        NvM_BlockConfig[flNvmblockLoop].RomBlockDataAddress,
				NvM_BlockConfig[flNvmblockLoop].NvBlockLength);
		}
	
	}
	lNVMReadAllRequest = 1;
	
}

Std_ReturnType NvM_WriteBlock(NvM_BlockIdType BlockId, const void* NvM_SrcPtr)
{
	Std_ReturnType NvM_RetVal = E_NOT_OK;
	if(BlockId <NVM_NUM_OF_BLOCKS)
	{
		if(NvM_SrcPtr == NULL)

		{
		}
		else{
		memcpy(NvM_BlockConfig[BlockId].RamBlockDataAddress,
					NvM_SrcPtr,
					NvM_BlockConfig[BlockId].NvBlockLength);
		}
		if(NvM_BlockConfig[BlockId].SingleBlockCallback != 0)
		{
			NvM_BlockConfig[BlockId].SingleBlockCallback(NVM_WRITE_BLOCK,NVM_REQ_OK);
		}
		NvM_RetVal = E_OK;
	}
	else{
	}
	return(E_OK);
}

Std_ReturnType NvM_ReadBlock( NvM_BlockIdType BlockId,void* NvM_DstPtr)
{
	Std_ReturnType NvM_RetVal = E_NOT_OK;
	if(BlockId <NVM_NUM_OF_BLOCKS)
	{
		if(NvM_DstPtr != 0)
		{
			memcpy(NvM_DstPtr,
			NvM_BlockConfig[BlockId].RamBlockDataAddress,
			NvM_BlockConfig[BlockId].NvBlockLength);
		}
		NvM_RetVal = E_OK;
	}
	return(E_OK);
}

Std_ReturnType NvM_SetBlockProtection(NvM_BlockIdType BlockId, boolean ProtectionEnabled)
{
	return(E_OK);
}

Std_ReturnType NvM_CancelJobs( NvM_BlockIdType BlockId)
{
	return(E_OK);
}

void NvM_MainFunction(void) 
{
	if(lNVMReadAllRequest ==1)
	{
		NvM_MultiBlockCallbackFunction(NVM_READ_ALL,NVM_REQ_OK);
		NvMExt_ReleaseSpeedup();
		lNVMReadAllRequest=0;
	}
}

void NvM_WriteAll(void)
{
	
}



Std_ReturnType NvM_SetRamBlockStatus( NvM_BlockIdType BlockId, boolean BlockChanged)
{
	return(E_OK);
}

Std_ReturnType NvM_RestoreBlockDefaults( NvM_BlockIdType BlockId, void* NvM_DestPtr)
{
	Std_ReturnType NvM_RetVal = E_NOT_OK;
	if(BlockId <NVM_NUM_OF_BLOCKS)
	{
		if(NvM_DestPtr == NULL)

		{
			memcpy(NvM_BlockConfig[BlockId].RamBlockDataAddress,
		        NvM_BlockConfig[BlockId].RomBlockDataAddress,
				NvM_BlockConfig[BlockId].NvBlockLength);
				
			
		}
		else{
			memcpy(NvM_DestPtr,
					NvM_BlockConfig[BlockId].RomBlockDataAddress,
					NvM_BlockConfig[BlockId].NvBlockLength);
		}
		NvM_BlockConfig[BlockId].SingleBlockCallback(NVM_WRITE_BLOCK,NVM_REQ_OK);
		NvM_RetVal = E_OK;
	}
	else{
	}
	return(NvM_RetVal);
}
