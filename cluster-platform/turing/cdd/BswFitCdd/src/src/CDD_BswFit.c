/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2020. Visteon Corporation owns all rights to           *
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
/*!*****************************************************************************************************************
 *    @file Cdd_BswFit.c
 *    @defgroup Cdd_BswFit
 *    @ingroup Cdd_BswFit
 *    @brief
 ********************************************************************************************************************/

#ifdef _FS_FAULT_INJECTION_TEST_ENABLE_

#ifndef CDD_BSWFIT_C
#define CDD_BSWFIT_C

/*****************************************************************************
 * System Includes                                                            *
 *****************************************************************************/
#include "CDD_BswFit.h"

#if defined(BSWFIT_SYSTEM_STACK) && (BSWFIT_SYSTEM_STACK == BSWFIT_VECTOR_STACK) /* VECTOR_STACK */
/* OS inclusions for stack monitoring related implementation */
#include "Os_Task_Lcfg.h"
#include "Os_Task_Types.h"
#include "Os_Thread_Types.h"
#include "Os_Stack_Types.h"
#include "Os_TaskInt.h"
#include "Os_ThreadInt.h"
#include "Os_StackInt.h"

#include "NvM.h"
#include "MemIf.h"
#include "Os.h"
#include "Wdg.h"
#include "NvM_PrivateCfg.h"
#include "MemLib.h"

#elif defined(BSWFIT_SYSTEM_STACK) && (BSWFIT_SYSTEM_STACK == BSWFIT_VAUTOSAR_STACK) /* AUTOSAR_STACK */
#include "NvM.h"
#include "MemLib.h"
#include "Wdg.h"
#include "OsMain.h"
#ifdef TV2_Specific
#include "Fls_InternalLib.h"
#include "Fls.h"
#endif /*TV2_Specific*/

#endif

/*****************************************************************************
 * Project Includes                                                           *
 *****************************************************************************/

/*****************************************************************************
 * File Scope Prototypes                                                      *
 *****************************************************************************/

/*****************************************************************************
 * Constants                                                                  *
 *----------------------------------------------------------------------------*
 * Declaration shall be followed by a comment that gives the following info.  *
 * about the constant.                                                        *
 * purpose, unit and resolution                                               *
 *****************************************************************************/

/*****************************************************************************
 * Manifest Constants                                                         *
 *----------------------------------------------------------------------------*
 * Definition of Manifest constant shall be followed by a comment that        *
 * explains the purpose of the constant.                                      *
 *****************************************************************************/

/*****************************************************************************
 * Macro Definitions                                                          *
 *----------------------------------------------------------------------------*
 * Definition of macro shall be followed by a comment that explains the       *
 * purpose of the macro.                                                      *
 *****************************************************************************/

/*****************************************************************************
 * Globally  accessed Variable Declarations                                   *
 *----------------------------------------------------------------------------*
 * Declaration shall be followed by a comment that gives the following info.  *
 * about the variable.                                                        *
 * purpose, critical section, unit, resolution, Valid Range and ValidityCheck *
 *****************************************************************************/

/*****************************************************************************
 * Locally used Variable Declarations                                         *
 *----------------------------------------------------------------------------*
 * Declaration shall be followed by a comment that gives the following info.  *
 * about the variable.                                                        *
 * purpose, critical section, unit, resolution, Valid Range and ValidityCheck *
 *****************************************************************************/

#ifdef cCDD_BSWFIT_ENABLE_MEMORYMAP
#define CDD_BSWFIT_START_SEC_VAR
#include "MemMap.h"
#endif


/* Macro to index 0 of Data array */
#define CDD_BSWFIT_DATAINDEX_ZERO         (uint8)0x00U
/* Macro to write data for injecting stack fault */
#define CDD_BSWFIT_WRITE_DATA             (uint16)0x1234u
/* Memory hardware configuration index to get the Memory functions */
#define BSWFIT_MEOMORYHWCONFIG_INDEX      (uint8)0x00
/* Maximum value of memory buffer size */
#define BSWFIT_MEOMORYBUFFER_SIZE         (uint8)500u
/* Maximum value of memory buffer size */
#define BSWFIT_INVALID_NVM_BLOCKID        (uint16)0xFFFF
/* Maximum value of memory buffer size */
#define BSWFIT_NVM_BLOCK_COUNT            (uint8)0x02
/* Ea/Fee Write block data */
#define BSWFIT_NV_BLOCK_DATA              (uint8)0x0A
/* Ea/Fee Write redunatant block data */
#define BSWFIT_NV_REDUNATANTBLOCK_DATA    (uint8)0x0C
/* Initial value of NvM block data */
#define BSWFIT_NVM_BLOCK_INIT_DATA        (uint8)0xFF

/* Ea/Fee write buffer declaration */
static uint8 Nv_WriteBuffer[BSWFIT_MEOMORYBUFFER_SIZE];

/* Ea/Fee reduntant write buffer declaration */
static uint8 Nv_ReduntantWriteBuffer[BSWFIT_MEOMORYBUFFER_SIZE];

/* NvM read buffer declaration */
static uint8 NvM_ReadBuffer[BSWFIT_MEOMORYBUFFER_SIZE];
/* Static variable to store the NvM block ID */
static uint16 BswFit_NvMBlockID;
/* Static variable to store the NvM fault injection state */
static uint8 BswFitCdd_NvM_IntegrityFaultInjection_State;
/* Static variable to store the NvM block ID */
static boolean BswFit_Nv_Write_Triggered;

/* Static function to start the NvM Integrity fault injection  */
static void BswFit_NvMIntegrityFaultInjection(uint16 NvMBlockID);

#ifdef cCDD_BSWFIT_ENABLE_MEMORYMAP
#define CDD_BSWFIT_STOP_SEC_VAR
#include "MemMap.h"
#endif

#ifdef cCDD_BSWFIT_ENABLE_MEMORYMAP
#define CDD_BSWFIT_START_SEC_CODE
#include "MemMap.h"
#endif

/*!*****************************************************************************************************************
 *   @brief         To trigger BSW fault injections based on the test id which needs to be executed
 *   @param[in]     StartStopData - Start and stop data from the FIT details
 *                  TestListID - Test ID from the FIT details
 *                  *Data - Data in which we receive FIT details(xx yy- fit data)
 *   @return        E_OK:
 *                  E_NOT_OK:
 *
 *                  2E 4F 09- 20 1 1 xx xx
 *                  Data[0]- 20 - module ID
 *                  Data[1]- 1  - fit test id
 *                  Data[2]- 1 - start/stop access
 *                  Data[3] -xx,
 *                  Data[4] -yy - fit data
 ********************************************************************************************************************/

FUNC(Std_ReturnType, CDD_BswFit_CODE) CDD_BswFit_FaultInjectionHandler(uint8 StartStopData, uint8 TestListID, uint8 *Data)
{
    /* local variable to store the return type */
    uint8 ReturnType = E_NOT_OK;
    /* local variable to store the safe alarm index which needs to be canceled based on FIT data */
    uint8 SafeAlarmIndex;
    /* local variable to store the alarm ID to be canceled based on FIT data */
    AlarmType CancelAlarmID;
    /* Local variable to store task reference index */
    uint8 TaskRefIndex;
    /* Local variable to store NvM block ID */
    uint16 NvMBlockID;
    /* Local varaibale to store the address in which the stack fault to be injected */
    uint32 Address;
    /* Pointer to store the address value */
    uint32 * Address_ptr;
    #if defined(BSWFIT_SYSTEM_STACK) && (BSWFIT_SYSTEM_STACK == BSWFIT_VECTOR_STACK) /* VECTOR_STACK */
    /* Stack low and high address pointers */
    P2VAR(Os_Hal_StackType, TYPEDEF, OS_VAR_NOINIT) StackLowAddress;
    P2VAR(Os_Hal_StackType, TYPEDEF, OS_VAR_NOINIT) StackHighAddress;
    #elif defined(BSWFIT_SYSTEM_STACK) && (BSWFIT_SYSTEM_STACK == BSWFIT_VAUTOSAR_STACK) /* AUTOSAR_STACK */
    /* Stack low address pointers */
    osStackPtrType   StackLowAddress;
    /* variable to store stack size */
    osStackSizeType  StackSize;
    /* variable to store task low address */
    uint32   TaskStackLowAddress;
    #endif /* STACK */

    /* Switch to Fault injection test based on the Test ID */
    switch(TestListID)
    {
        /* Watchdog Manager execution delay test */
        case CDD_FITMANAGER_CDD_BSWFIT_WDGM_ALIVE_TEST_ID:
            /* WGM_ALIVE_TEST works based on the alrams configured in BswFitCdd_ASIL_AlarmRefs[]. */
            /* Data[0U] of FIT data corresponds to the Alarm index which is used to get the alarm ID that needs to be canceled */
            /* Update the Safe Alarm index value with the Data[0U] value */
            SafeAlarmIndex = Data[CDD_BSWFIT_DATAINDEX_ZERO];
            /* Check whether the safe alarm index is less than the maximum number of ASIL Alarms */
            if(SafeAlarmIndex < (CDD_BSWFIT_CFG_ASILALARM_MAX_COUNT))
            {
                /* Get the cancel alarm ID corresponding to the indexed safe alarm */
                CancelAlarmID = BswFitCdd_ASIL_AlarmRefs[SafeAlarmIndex];
                /* Cancel the Safe alarm */
                /* Cancel alarm needs to be executed in Supervisory mode only */
                (void)CancelAlarm(CancelAlarmID);
                /* Return E_NOT_OK to notify the Dcm module regarding the fault */
                ReturnType = E_NOT_OK;
            }
            else
            {
                /* Do nothing */
            }
            ReturnType = E_OK;
        break;

        case CDD_FITMANAGER_CDD_BSWFIT_MPU_TEST_ID:
            /* Write data to the variable defined in safe memory area */
			//OsTrustedCall_CDD_BswFit_SafeMemUpdate();
             *(mpu_fit[Data[0]])= CDD_BSWFIT_WRITE_DATA;
            /* TO DO */
            ReturnType = E_OK;
        break;

        case CDD_FITMANAGER_CDD_BSWFIT_STACK_OVERFLOW_TEST_ID:
            /* Data[0U] of FIT data corresponds to the Task index which is used to get the stack high/low address of that particular task */
            /* Update the Task reference index value with the Data[0U] value */
            TaskRefIndex = Data[CDD_BSWFIT_DATAINDEX_ZERO];
            /* Check whether the task ID passed by diagnostics is a valid one */
            if(TaskRefIndex < BSWFIT_OS_TASKID_COUNT)
            {
            #if defined(BSWFIT_SYSTEM_STACK) && (BSWFIT_SYSTEM_STACK == BSWFIT_VECTOR_STACK) /* VECTOR_STACK */
                /* Get the High address of the particular task's stack in a pointer */
                StackHighAddress = ((OsCfg_TaskRefs[TaskRefIndex]->Thread).Stack)->HighAddress;
                /* Get the High Address of the stack */
                Address = *StackHighAddress;
            #elif defined(BSWFIT_SYSTEM_STACK) && (BSWFIT_SYSTEM_STACK == BSWFIT_VAUTOSAR_STACK) /* AUTOSAR_STACK */
                /* Get the Start address of the particular task's stack in a pointer */
                StackLowAddress = TcbTaskRefConfig[TaskRefIndex]->TaskStackStartAddress;
                StackSize = TcbTaskRefConfig[TaskRefIndex]->TaskStackSize;
                /* Get the High Address of the stack */
                TaskStackLowAddress = (uint32)StackLowAddress;
                Address = TaskStackLowAddress + StackSize;
            #endif /* STACK */
                /* Pass the Low Address to another pointer to inject fault */
                Address_ptr = (uint32 *)Address;
                /* Try to modify the address location */
                *Address_ptr = CDD_BSWFIT_WRITE_DATA;
                /* TO DO: Further update needs to be done */
                /* Return E_NOT_OK to notify the Dcm module regarding the fault */
                ReturnType = E_NOT_OK;
            }
        break;

        case CDD_FITMANAGER_CDD_BSWFIT_STACK_UNDERFLOW_TEST_ID:
            /* Data[0U] of FIT data corresponds to the Task index which is used to get the stack high/low address of that particular task */
            /* Update the Task reference index value with the Data[0U] value */
            TaskRefIndex = Data[CDD_BSWFIT_DATAINDEX_ZERO];
            /* Check whether the task ID passed by diagnostics is a valid one */
            if(TaskRefIndex < BSWFIT_OS_TASKID_COUNT)
            {
            #if defined(BSWFIT_SYSTEM_STACK) && (BSWFIT_SYSTEM_STACK == BSWFIT_VECTOR_STACK) /* VECTOR_STACK */
                /* Get the Low address of the particular task's stack in a pointer */
                StackLowAddress = ((OsCfg_TaskRefs[TaskRefIndex]->Thread).Stack)->LowAddress;
            #elif defined(BSWFIT_SYSTEM_STACK) && (BSWFIT_SYSTEM_STACK == BSWFIT_VAUTOSAR_STACK) /* AUTOSAR_STACK */
                /* Get the Start address of the particular task's stack in a pointer */
                StackLowAddress = TcbTaskRefConfig[TaskRefIndex]->TaskStackStartAddress;
            #endif /* STACK */
                /* Get the Low Address of the stack */
                Address = (uint32)(StackLowAddress);
                /* Pass the Low Address to another pointer to inject fault */
                Address_ptr = (uint32 *)Address;
                /* Try to modify the address location */
                *Address_ptr = CDD_BSWFIT_WRITE_DATA;
                /* TO DO: Further update needs to be done */
                /* Return E_NOT_OK to notify the Dcm module regarding the fault */
                ReturnType = E_NOT_OK;
            }
        break;

        case CDD_FITMANAGER_CDD_BSWFIT_NVM_INTEGRITY_ID:
            /* Data[0U] of FIT data corresponds to the NvM Block ID for which NvM Integrity fault needs to be triggered */
            /* Update the NvM block ID with the Data[0U] value */
            NvMBlockID = Data[CDD_BSWFIT_DATAINDEX_ZERO];
            /* Trigger NvM integrity fault injection of specific NvM block ID */
            /* Invoke function to update NvM integrity fault injection static variables*/
            BswFit_NvMIntegrityFaultInjection(NvMBlockID);
            /* TBD: Return E_NOT_OK to notify the Dcm module regarding the fault */
            ReturnType = E_OK;
        break;

        default:
        break;
    }
    return ReturnType;
}


//---------------------------------------------------------------------------------------------------------------------
/// @brief  BswFitCdd initialization state
///
/// @return void
//---------------------------------------------------------------------------------------------------------------------
void BswFitCdd_Init(void)
{
    /* Initialize the NvM Block ID */
    BswFit_NvMBlockID = BSWFIT_INVALID_NVM_BLOCKID;
    /* Initialize static variable to trigger the NvM integrity fault injection as FALSE */
    BswFit_Nv_Write_Triggered = FALSE;
    /* Initialize NvM integrity fault injection state as IDLE */
    BswFitCdd_NvM_IntegrityFaultInjection_State = BSWFIT_NVM_IDLE_STATE;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  BswFitCdd de-initialization state
///
/// @return void
//---------------------------------------------------------------------------------------------------------------------
void BswFitCdd_DeInit(void)
{
    /* De-Initialize the NvM Block ID */
    BswFit_NvMBlockID = BSWFIT_INVALID_NVM_BLOCKID;
    /* De-Initialize static variable to trigger the NvM integrity fault injection as FALSE */
    BswFit_Nv_Write_Triggered = FALSE;
    /* De-Initialize NvM integrity fault injection state as IDLE */
    BswFitCdd_NvM_IntegrityFaultInjection_State = BSWFIT_NVM_IDLE_STATE;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  BswFitCdd main function
///
/// @return void
//---------------------------------------------------------------------------------------------------------------------
void CCDD_BswFit_Impl_MainFunction(void)
{
    /* Local variable to store the return value */
    Std_ReturnType ReturnValue = E_NOT_OK;
    /* TBD: Since this variable is set but not used anywhere, compiler warning is reported. In order to resolve the warning, comments this varaiable for now.  */
    //boolean NvMFaultInjection = FALSE;
    /* Static variable to store Ea/Fee block number */
    static uint16 NvBlockNumber = BSWFIT_INVALID_NVM_BLOCKID;
    /* Static variable to store Ea/Fee block count */
    static uint8 NvBlockCount;
    /* Static variable to store NvM block length */
    static uint16 NvmBlockLength;
    /* Static variable to store Nvm block status */
    static NvM_RequestResultType  NvmBlockStatus = NVM_REQ_PENDING;
    #if defined(BSWFIT_SYSTEM_STACK) && (BSWFIT_SYSTEM_STACK == BSWFIT_VAUTOSAR_STACK) /* AUTOSAR_STACK */
    /* Static variable to store NvM block management type */
    static NvM_BlockType NvmBlockManagementType;
    #endif
    /* Check whether NvM fault injection is triggered */
    if(BswFit_Nv_Write_Triggered == TRUE)
    {
        /* If the NvM fault injection is triggered, check whether the NvM block ID is valid */
        if(BswFit_NvMBlockID < BSWFIT_NVM_TOTAL_NUM_OF_NVRAM_BLOCKS)
        {
            #if defined(BSWFIT_SYSTEM_STACK) && (BSWFIT_SYSTEM_STACK == BSWFIT_VECTOR_STACK) /* VECTOR_STACK */
                /* Get the Ea/Fee block number from the VECTOR NvM configuration */
                NvBlockNumber = NvM_BlockDescriptorTable_at[BswFit_NvMBlockID].NvIdentifier_u16;
                /* Get the Ea/Fee block count from the VECTOR NvM configuration */
                NvBlockCount = NvM_BlockDescriptorTable_at[BswFit_NvMBlockID].NvBlockCount_u8;
                /* Get the NvM block length from the VECTOR NvM configuration */
                NvmBlockLength = NvM_BlockDescriptorTable_at[BswFit_NvMBlockID].NvBlockLength_u16;
            #elif defined(BSWFIT_SYSTEM_STACK) && (BSWFIT_SYSTEM_STACK == BSWFIT_VAUTOSAR_STACK) /* AUTOSAR_STACK */
                /* Get the Ea/Fee block number from the VAUTOSAR NvM configuration */
                NvBlockNumber = NvM_BlockConfig[BswFit_NvMBlockID].NvBlockBaseNumber;
                /* Get the NvM block management type from the VAUTOSAR NvM configuration */
                NvmBlockManagementType = NvM_BlockConfig[BswFit_NvMBlockID].BlockManagementType;
                /* Check whether the NvM block is a Reduntant */
                if(NvmBlockManagementType == NVM_REDUNDANT_BLOCK)
                {
                    /* Set the NvM Block count to 2 */
                    NvBlockCount = BSWFIT_NVM_BLOCK_COUNT;
                }
                /* Get the NvM block length from the VAUTOSAR NvM configuration */
                NvmBlockLength = NvM_BlockConfig[BswFit_NvMBlockID].NvBlockLength;
            #endif
            /* Set the NvM integrity fault injection to Ea/Fee write State*/
            BswFitCdd_NvM_IntegrityFaultInjection_State = BSWFIT_NVM_NV_WRITE_STATE;
        }
    }

    switch(BswFitCdd_NvM_IntegrityFaultInjection_State)
    {
        case BSWFIT_NVM_IDLE_STATE:
            /* TO DO */
        break;

        case BSWFIT_NVM_NV_WRITE_STATE:
            /* Set the Ea/Fee write buffer with the data using MemSet function */
            MemLib_MemSet((uint8*)(&(Nv_WriteBuffer[0U])), BSWFIT_NV_BLOCK_DATA, NvmBlockLength);
            /* Ea/Fee write of NvM block with data to inject NvM integrity fault */
            ReturnValue = (CDD_BswFit_MemoryHwConfigFunc[BSWFIT_MEOMORYHWCONFIG_INDEX].MemoryHwWrite)(NvBlockNumber, &Nv_WriteBuffer[0U]);
            if(ReturnValue == E_OK)
            {
                /* Reset the NvM Integrity fault injection varaiable to FALSE */
                BswFit_Nv_Write_Triggered = FALSE;
                /* Set the NvM integrity fault injection to wait state after Ea/Fee write */
                BswFitCdd_NvM_IntegrityFaultInjection_State = BSWFIT_NVM_NV_WRITE_WAIT_STATE;
            }
        break;

        case BSWFIT_NVM_NV_WRITE_WAIT_STATE:
            /* Check whether the Ea/Fee write has finished but checking the Ea/Fee status */
            if((CDD_BswFit_MemoryHwConfigFunc[BSWFIT_MEOMORYHWCONFIG_INDEX].MemoryHwStatus)()== MEMIF_IDLE)
            {
                /* Set the NvM integrity fault injection to read corrupted NvM read state */
                BswFitCdd_NvM_IntegrityFaultInjection_State = BSWFIT_NVM_READ_BLOCK_STATE;
                /* Check whether block count is 2 */
                if(NvBlockCount == BSWFIT_NVM_BLOCK_COUNT)
                {
                    /* Increment the Ea/fee block number for reduntant block write */
                    NvBlockNumber++;
                    /* Set the NvM integrity fault injection to Ea/Fee reduntant write State*/
                    BswFitCdd_NvM_IntegrityFaultInjection_State = BSWFIT_NVM_NV_REDUNTANT_WRITE_STATE;
                }
            }
        break;

        case BSWFIT_NVM_NV_REDUNTANT_WRITE_STATE:
            /* Set the Ea/Fee reduntant write buffer with the data using MemSet function */
            MemLib_MemSet((uint8*)(&(Nv_ReduntantWriteBuffer[0U])), BSWFIT_NV_REDUNATANTBLOCK_DATA, NvmBlockLength);
            /* Ea/Fee write of NvM reduntanat block with data to inject NvM integrity fault */
            ReturnValue = (CDD_BswFit_MemoryHwConfigFunc[BSWFIT_MEOMORYHWCONFIG_INDEX].MemoryHwWrite)(NvBlockNumber, &Nv_ReduntantWriteBuffer[0U]);
            if(ReturnValue == E_OK)
            {
                /* Set the NvM integrity fault injection to wait state after Ea/Fee reduntant write */
                BswFitCdd_NvM_IntegrityFaultInjection_State = BSWFIT_NVM_NV_REDUNTANT_WRITE_WAIT_STATE;
            }
        break;

        case BSWFIT_NVM_NV_REDUNTANT_WRITE_WAIT_STATE:
            /* Check whether the Ea/Fee reduntant write has finished but checking the Ea/Fee status */
            if((CDD_BswFit_MemoryHwConfigFunc[BSWFIT_MEOMORYHWCONFIG_INDEX].MemoryHwStatus)()== MEMIF_IDLE)
            {
                /* Set the NvM integrity fault injection to read corrupted NvM read state */
                BswFitCdd_NvM_IntegrityFaultInjection_State = BSWFIT_NVM_READ_BLOCK_STATE;
            }
        break;

        case BSWFIT_NVM_READ_BLOCK_STATE:
            /* Initialize the NvM read buffer with the data using MemSet function */
            MemLib_MemSet((uint8*)(&(NvM_ReadBuffer[0U])), BSWFIT_NVM_BLOCK_INIT_DATA, NvmBlockLength);
            /* Read the data from NvM block */
            ReturnValue = NvM_ReadBlock(BswFit_NvMBlockID, &NvM_ReadBuffer[0U]);
            if(ReturnValue == E_OK)
            {
                /* NvM integrity state transition to wait after NvM read trigger */
                BswFitCdd_NvM_IntegrityFaultInjection_State = BSWFIT_NVM_READ_BLOCK_WAIT_STATE;
            }
        break;

        case BSWFIT_NVM_READ_BLOCK_WAIT_STATE:
            /* Obtain the overall status of the NvM Blocks */
            NvM_GetErrorStatus(BswFit_NvMBlockID, &NvmBlockStatus);
            /* Since the Ea/Fee write was done with some data, NvM CRC mismatch will be observed and NvM block
            status will be either NVM_REQ_INTEGRITY_FAILED or NVM_REQ_RESTORED_FROM_ROM */
            if((NvmBlockStatus == NVM_REQ_INTEGRITY_FAILED)||(NvmBlockStatus == NVM_REQ_RESTORED_FROM_ROM))
            {
                //NvMFaultInjection = TRUE;
            }
        break;

        default:
        break;
    }
}

//======================================================================================================================
// LOCAL FUNCTIONS
//======================================================================================================================
//----------------------------------------------------------------------------------------------------------------------
/// @brief    Function to trigger the NvM integrity fault injection of specified NvM Block ID.
///
/// @param    uint16 NvMBlockID - NvM Block ID to inject the fault
///
/// @return   void
//----------------------------------------------------------------------------------------------------------------------
static void BswFit_NvMIntegrityFaultInjection(uint16 NvMBlockID)
{
    /* Update the static variable to trigger the NvM integrity fault injection */
    BswFit_Nv_Write_Triggered = TRUE;
    /* Store the NvM block ID to a static variable,
    so that it can be used in the CDD_BswFit_Impl_MainFunction */
    BswFit_NvMBlockID = NvMBlockID;
}

//======================================================================================================================
// LOCAL FUNCTIONS
//======================================================================================================================
//----------------------------------------------------------------------------------------------------------------------
/// @brief    Function to update the safety memory.
///
/// @param   void
///
/// @return   void
//----------------------------------------------------------------------------------------------------------------------
void CDD_BswFit_SafeMemUpdate(void)
{
    /* Update the safety memory Variable */
    Safe_asil_data = CDD_BSWFIT_WRITE_DATA;
}

#ifdef cCDD_MUCFIT_ENABLE_MEMORYMAP
#define CDD_BSWFIT_STOP_SEC_CODE
#include "MemMap.h"
#endif

#endif /*CDD_BSWFIT_C*/

#endif /* _FS_FAULT_INJECTION_TEST_ENABLE_ */

/*----------------------------------------------------------------------------------------
REVISION HISTORY
-----------------------------------------------------------------------------------------*/
/*============================================================================
**
**============================================================================
** C M S    R E V I S I O N    N O T E S
**============================================================================
**
** For each change to this file, be sure to record:
** 1.  Who made the change and when the change was made.
** 2.  Why the change was made and the intended result.
**
** CMS Rev #        Date         By
** CMS Rev 1.0      01/09/24     rswamyga
**
**============================================================================
**============================================================================
Date              : 09/Jan/2024
By                : rswamyga
Traceability      : PK3T229419-1428
Change Description: Initial Version
**============================================================================
**==========================================================================*/


