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
#ifndef UCLVMFMSGQUEUE_H
#define UCLVMFMSGQUEUE_H

#ifdef __cplusplus
extern "C"
{
#endif

//---------------------------------------------------------------------------------------
// Configuration of message queues
//---------------------------------------------------------------------------------------
typedef struct SUclVmfMsgQueueConfig_t
{
	uint8 *pBuffer;
	uint16 msgSize;
	uint16 maxMessages;
} SUclVmfMsgQueueConfig;

//---------------------------------------------------------------------------------------
// Runtime queue data
//---------------------------------------------------------------------------------------
typedef struct SUclVmfMsgQueueRuntime_t
{
	uint16 readMsgIdx;
	uint16 writeMsgIdx;
	uint16 msgCnt;
} SUclVmfMsgQueueRuntime;


//---------------------------------------------------------------------------------------------------------------------
/// @brief  Add new message to the queue.
///
/// @param  qIndex:     Queue index
/// @param  pData:      Buffer that contains the latest data, received from the VMF
/// @param  Size:       Size of the message buffers
///
/// @return TRUE:  		Message successfully added to the queue
///         FALSE: 		Failed mutex locking
///                		Input size does not match configured one
///                		Queue is overloaded. Data is lost
//---------------------------------------------------------------------------------------------------------------------
Ucl_ReturnType UclVmfMsgQueue_Put(uint32 qIndex, uint8 *pData, uint16 Size);


//---------------------------------------------------------------------------------------------------------------------
/// @brief  Get oldest message from the queue.
///
/// @param  qIndex:      Queue index
/// @param  pData:       Buffer to hold the message
/// @param  Size:        Room available in pData
///
/// @return TRUE:  		 Message is retrieved successfully
///         FALSE: 		 Failed mutex locking
///                		 Input size does not match configured one
///                		 Queue is empty. No data o retrieve.
//---------------------------------------------------------------------------------------------------------------------
Ucl_ReturnType UclVmfMsgQueue_Get(uint32 qIndex, uint8 *pData, uint16 Size);

#ifdef __cplusplus
}
#endif

extern const SUclVmfMsgQueueConfig UclVmfMsgQueueConfig[];
extern SUclVmfMsgQueueRuntime UclVmfMsgQueueRuntime[];

#endif //UCLVMFMSGQUEUE_H
