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
/// @defgroup UclALOs
/// @brief UCL Operating System Abstraction Layer provides OS APIs support for UCL Components
/// @file
/// @ingroup UclALOs
/// UCL Operating System Abstraction Interface APIs.
///
///---------------------------------------------------------------------------------------------------------------------
#ifndef UCLALOS_H
#define UCLALOS_H

#include "UclALOs_Types.h" //MISRA C++-2008 Rule 16-0-1

#ifdef __cplusplus
extern "C"
{
#endif

///
/// @brief This method is used to initialize the UclALOs Instance
///
/// @param InstId Instance Id to initialize
///
/// @return UCL_E_OK 	Initialization Success
///	@return	UCL_E_NOK 	Initialization Failed
///
Ucl_ReturnType UclALOs_Initialize( uint8 InstId );

///
/// @brief This method is used to shutdown the UclALOs Instance
///
/// @param InstId Instance Id to shutdown
///
/// @return UCL_E_OK 	Shutdown Success
///	@return	UCL_E_NOK 	Shutdown Failed
///
Ucl_ReturnType UclALOs_Shutdown( uint8 InstId );

///
/// @brief This method is a wrapper to the Memset function
///
/// @param InstId Instance Id of the OSAL
/// @param pBuffer Pointer to the buffer
/// @param Val Value to set
/// @param Size Size of the buffer
///
/// @return UCL_E_OK 	Memset Success
///	@return	UCL_E_NOK 	Memset Failed
///
Ucl_ReturnType UclALOs_Memset( uint8 InstId, void *pBuffer, uint8 Val, uint32 Size );

///
/// @brief This method is a wrapper to the Memcpy function
///
/// @param InstId Instance Id of the OSAL
/// @param pDst Pointer to the destination buffer
/// @param pSrc Pointer to the source buffer
/// @param Size Size of the buffer
///
/// @return UCL_E_OK 	Memset Success
///	@return	UCL_E_NOK 	Memset Failed
///
Ucl_ReturnType UclALOs_Memcpy( uint8 InstId, void *pDst, void *pSrc, uint32 Size );

///
/// @brief This method is a wrapper to the Memcmp function
///
/// @param InstId Instance Id of the OSAL
/// @param pDst Pointer to the destination buffer
/// @param pSrc Pointer to the source buffer
/// @param Size Size of the buffer
///
/// @return UCL_E_OK    No change Observed
/// @return UCL_E_NOK   Change observed
///
Ucl_ReturnType UclALOs_Memcmp( uint8 InstId, void *pDst, void *pSrc, uint32 Size );

///
/// @brief This method disables all system interrupts (only for RTOS implementations)
///
/// @param InstId Instance Id of the OSAL
///
/// @return UCL_E_OK 	Success
///	@return	UCL_E_NOK 	Failed
///
Ucl_ReturnType UclALOs_DisableAllInterrupts( uint8 InstId );

///
/// @brief This method enables all system interrupts (only for RTOS implementations)
///
/// @param InstId Instance Id of the OSAL
///
/// @return UCL_E_OK 	Success
///	@return	UCL_E_NOK 	Failed
///
Ucl_ReturnType UclALOs_EnableAllInterrupts( uint8 InstId );

///
/// @brief This method is used to create a mutex
///
/// @param InstId Instance Id of the OSAL
/// @param pMutexId [out] Mutex Id
///
/// @return UCL_E_OK 	Mutex creation success
///	@return	UCL_E_NOK 	Mutex creation Failed
///
Ucl_ReturnType UclALOs_MutexCreate( uint8 InstId, uint32 *pMutexId );

///
/// @brief This method is used to destroy a mutex
///
/// @param InstId Instance Id of the OSAL
/// @param MutexId Mutex Id
///
/// @return UCL_E_OK 	Mutex destroy success
///	@return	UCL_E_NOK 	Mutex destroy Failed
///
Ucl_ReturnType UclALOs_MutexDestroy( uint8 InstId, uint32 MutexId );

///
/// @brief This method is used to create a task
///
/// @param InstId Instance Id of the OSAL
/// @param pThreadId [out] Task Id
/// @param pFunc Task entry function
/// @param pData Task argument
///
/// @return UCL_E_OK 	Task creation success
///	@return	UCL_E_NOK 	Task creation Failed
///
Ucl_ReturnType UclALOs_TaskCreate( uint8 InstId, uint32 *pThreadId, TUclOsTaskEntryFunc pFunc, void *pData );

///
/// @brief This method is used to destroy a task
///
/// @param InstId Instance Id of the OSAL
/// @param ThreadId Task Id
///
/// @return UCL_E_OK 	Task destroy success
///	@return	UCL_E_NOK 	Task destroy Failed
///
Ucl_ReturnType UclALOs_TaskDestroy( uint8 InstId, uint32 ThreadId );

///
/// @brief This method is used to lock a mutex. This is a blocking call until the mutex is available to lock.
///
/// @param InstId Instance Id of the OSAL
/// @param MutexId Mutex Id
///
/// @return UCL_E_OK 	Mutex lock success
///	@return	UCL_E_NOK 	Mutex lock Failed
///
Ucl_ReturnType UclALOs_MutexLock( uint8 InstId, uint32 MutexId );

///
/// @brief This method is used to try lock a mutex. If the mutex object referenced by mutex is currently locked (by any thread, including the current thread), the call shall return immediately.
///
/// @param InstId Instance Id of the OSAL
/// @param MutexId Mutex Id
///
/// @return UCL_E_OK 	Mutex lock success
///	@return	UCL_E_NOK 	Mutex lock Failed
///
Ucl_ReturnType UclALOs_MutexTryLock(uint8 InstId, uint32 MutexId);

///
/// @brief This method is used to unlock a mutex.
///
/// @param InstId Instance Id of the OSAL
/// @param MutexId Mutex Id
///
/// @return UCL_E_OK 	Mutex unlock success
///	@return	UCL_E_NOK 	Mutex unlock Failed
///
Ucl_ReturnType UclALOs_MutexUnlock( uint8 InstId, uint32 MutexId );

///
/// @brief This method is used to create a timer
///
/// @param InstId Instance Id of the OSAL
/// @param pTimerId [out] Timer Id
/// @param pFunc Callback function to call upon timer expiry
/// @param pData Callback function argument
/// @param TimerType Type of the timer
///
/// @return UCL_E_OK 	Task creation success
///	@return	UCL_E_NOK 	Task creation Failed
///
Ucl_ReturnType UclALOs_TimerCreate( uint8 InstId, uint32 *pTimerId, TUclOsTaskEntryFunc pFunc, void *pData,
                EUclOsTimerType TimerType );

///
/// @brief This method is used to start a timer.
///
/// @param InstId Instance Id of the OSAL
/// @param TimerId Timer Id
/// @param Timeout Timout for the timer
///
/// @return UCL_E_OK 	Timer successfully started
///	@return	UCL_E_NOK 	Timer start Failed
///
Ucl_ReturnType UclALOs_TimerStart( uint8 InstId, uint32 TimerId, uint32 Timeout );

///
/// @brief This method is used to stop a timer.
///
/// @param InstId Instance Id of the OSAL
/// @param TimerId Timer Id
///
/// @return UCL_E_OK 	Timer successfully stopped
///	@return	UCL_E_NOK 	Timer stop Failed
///
Ucl_ReturnType UclALOs_TimerStop( uint8 InstId, uint32 TimerId );

///
/// @brief This method is used to destroy a timer
///
/// @param InstId Instance Id of the OSAL
/// @param TimerId Timer Id
///
/// @return UCL_E_OK 	Timer destroy success
///	@return	UCL_E_NOK 	Timer destroy Failed
///
Ucl_ReturnType UclALOs_TimerDestroy( uint8 InstId, uint32 TimerId );

///
/// @brief This method is used to create a semaphore
///
/// @param InstId Instance Id of the OSAL
/// @param pSemId [out] Semaphore Id
/// @param Val Initial value for the semaphore
///
/// @return UCL_E_OK 	Semaphore creation success
///	@return	UCL_E_NOK 	Semaphore creation Failed
///
Ucl_ReturnType UclALOs_SemCreate( uint8 InstId, uint32 *pSemId, uint8 Val );

///
/// @brief This method is used to destroy a semaphore
///
/// @param InstId Instance Id of the OSAL
/// @param SemId Semaphore Id
///
/// @return UCL_E_OK 	Semaphore destroy success
///	@return	UCL_E_NOK 	Semaphore destroy Failed
///
Ucl_ReturnType UclALOs_SemDestroy( uint8 InstId, uint32 SemId );

///
/// @brief This method is used to decrement the value for the semaphore.
///		   This is a blocking call until the semaphore is available.
///
/// @param InstId Instance Id of the OSAL
/// @param SemId Semaphore Id
///
/// @return UCL_E_OK 	Semaphore wait success
///	@return	UCL_E_NOK 	Semaphore wait Failed
///
Ucl_ReturnType UclALOs_SemWait( uint8 InstId, uint32 SemId );

///
/// @brief This method is used to increment the value for the semaphore.
///
/// @param InstId Instance Id of the OSAL
/// @param SemId Semaphore Id
///
/// @return UCL_E_OK 	Semaphore post success
///	@return	UCL_E_NOK 	Semaphore post Failed
///
Ucl_ReturnType UclALOs_SemPost( uint8 InstId, uint32 SemId );

///
/// @brief This method is used to get the system time in milliseconds
///
/// @param InstId Instance Id of the OSAL
/// @param TimerId Timer Id
///
/// @return uint64 	System time in milliseconds
///
uint64 UclALOs_GetSystemTimeMs( uint8 InstId );

///
/// @brief This method is used to get the resolution of the system time in milliseconds
///
/// @param InstId Instance Id of the OSAL
/// @param TimerId Timer Id
///
/// @return uint32 	Resolution of the system time in milliseconds
///
uint32 UclALOs_GetSystemTimeResolutionMs( uint8 InstId );

///
/// @brief This method is used to increment the system tick (only for RTOS implementations)
///
/// @param InstId Instance Id of the OSAL
///
///
void UclALOs_Tick( uint8 InstId );

#ifdef __cplusplus
}
#endif
#endif //UCLALOS_H
