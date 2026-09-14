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

#include <UclALOs.h>
#include <UclALDebug.h>
#include <UclVmfMsgQueue.h>

/* Mutex for UclVmfMsgQDb & UclVmfMsgQInfoDb */
uint32 VmfUclMsgQMutexId;
#define RCVQ_THRESHOLD			(80u)

Ucl_ReturnType UclVmfMsgQueue_Put(uint32 qIndex, uint8 *pData, uint16 Size)
{
	const SUclVmfMsgQueueConfig *pMsgQ = &UclVmfMsgQueueConfig[qIndex];
	SUclVmfMsgQueueRuntime *pMsgQInfo = &UclVmfMsgQueueRuntime[qIndex];
	uint16 writeMsgIdx;
	Ucl_ReturnType Ret = UCL_E_NOK;

	Ret = UclALOs_MutexLock(0, VmfUclMsgQMutexId);
	if(UCL_E_OK == Ret)
	{
		Ret = UCL_E_BUSY;
		if(pMsgQ->msgSize == Size)
		{
			if(pMsgQInfo->msgCnt < pMsgQ->maxMessages)
			{
				writeMsgIdx  = pMsgQInfo->writeMsgIdx;
				if (writeMsgIdx < (pMsgQ->maxMessages - 1U))
				{
				  ++writeMsgIdx;
				}
				else
				{
				  writeMsgIdx= 0U;
				}

				pMsgQInfo->writeMsgIdx = writeMsgIdx;
				if(pMsgQInfo->msgCnt == 0U)
				{
					Ret = UCL_E_OK;
				}
				pMsgQInfo->msgCnt++;
				(void)UclALOs_Memcpy(0, &(pMsgQ->pBuffer[writeMsgIdx * pMsgQ->msgSize]), pData, pMsgQ->msgSize);
				if( pMsgQInfo->msgCnt >= (( pMsgQ->maxMessages * RCVQ_THRESHOLD )/100u) )
				{
					LOGW(0, "UclVmfMsgQ_Put", "Queue %d Reached 80%% 0f Max limit %d(%d)", qIndex, pMsgQ->maxMessages, pMsgQInfo->msgCnt);
				}
			}
			else
			{
				LOGE(0, "UclVmfMsgQ_Put", "Reached Queue %d Max limit %d(%d), flushing queue !!!!DATA LOSS!!!", qIndex, pMsgQ->maxMessages, pMsgQInfo->msgCnt);
				pMsgQInfo->msgCnt = 0U;
				pMsgQInfo->writeMsgIdx = 0U;
				pMsgQInfo->readMsgIdx = 0U;
				Ret = UCL_E_NOK;
			}
		}
		else
		{
			LOGE(0, "UclVmfMsgQ_Put", "Invalid Payload Size %d %d rcvd for Queue %d", pMsgQ->msgSize, Size, qIndex);
			Ret = UCL_E_NOK;
		}

		(void)UclALOs_MutexUnlock(0, VmfUclMsgQMutexId);
	}
	else
	{
		LOGE(0, "UclVmfMsgQ_Put", "%s", "Mutex Lock Failed");
		Ret = UCL_E_NOK;
	}

	return Ret;
}

Ucl_ReturnType UclVmfMsgQueue_Get(uint32 qIndex, uint8 *pData, uint16 Size)
{
	const SUclVmfMsgQueueConfig *pMsgQ = &UclVmfMsgQueueConfig[qIndex];
	SUclVmfMsgQueueRuntime *pMsgQInfo = &UclVmfMsgQueueRuntime[qIndex];
	uint16 readMsgIdx;
	Ucl_ReturnType Ret = UCL_E_NOK;

	Ret = UclALOs_MutexLock(0, VmfUclMsgQMutexId);
	if(UCL_E_OK == Ret)
	{
		if(pMsgQ->msgSize == Size)
		{
			if(0u < pMsgQInfo->msgCnt)
			{
				readMsgIdx = pMsgQInfo->readMsgIdx;
				if (readMsgIdx < (pMsgQ->maxMessages - 1U))
				{
					++readMsgIdx;
				}
				else
				{
					readMsgIdx = 0U;
				}

				pMsgQInfo->readMsgIdx = readMsgIdx;
				pMsgQInfo->msgCnt--;
				(void)UclALOs_Memcpy(0, pData, &(pMsgQ->pBuffer[readMsgIdx * pMsgQ->msgSize]), pMsgQ->msgSize);
			}
			else
			{				
				Ret = UCL_E_NOK;
			}
		}
		else
		{
			LOGE(0, "UclVmfMsgQ_Get", "Invalid Payload Size %d %d Requested", pMsgQ->msgSize, Size);
			Ret = UCL_E_NOK;
		}
		(void)UclALOs_MutexUnlock(0, VmfUclMsgQMutexId);
	}	
	else
	{
		LOGE(0, "UclVmfMsgQ_Get", "%s", "Mutex Lock Failed");
		Ret = UCL_E_NOK;
	}

  return Ret;
}
