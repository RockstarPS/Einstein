/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2013. Visteon Corporation owns all rights to           *
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
#ifndef EepDrv_C
#define EepDrv_C
/*****************************************************************************
*  File Name         :  EepDrv.c                                             *
*  Module Short Name :  EepDrv                                               *
*  Description       :  This file contains implementations of the External   *
*                       EEPROM Device based on I2C                           *
*                       Only Following Devices are supported:                *
*                       24C04, 24C08, 24C16 and 24C32                        *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  GHS Multi                                              *
* Target Hardware  :  I2c Based External EEPROM device with                  *
* 						CAT24C04/08/16/32 series
*                                                                            *
******************************************************************************/

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "EepDrv.h"
#include "EepDrv_Cbk.h"
#include "EepDrv_PrivateCfg.h"
#include "AssertLib.h"

#define EEPDRV_CODE_SEC_START
#include "MemMap.h"

#define EEPDRV_CONST_SEC_START
#include "MemMap.h"

#ifdef I2C_EEPROM_USED
static Std_ReturnType Eep24xx_StartRead (void);
static Std_ReturnType Eep24xx_StartWrite (void);
static Std_ReturnType Eep24xx_StartErase (void);
static Std_ReturnType Eep24xx_StartCompare (void);
#endif /* I2C_EEPROM_USED */

#ifdef SPI_EEPROM_USED
static Std_ReturnType Eep25xx_StartRead (void);
static Std_ReturnType Eep25xx_StartWrite (void);
static Std_ReturnType Eep25xx_StartErase (void);
static Std_ReturnType Eep25xx_StartCompare (void);
#endif /* SPI_EEPROM_USED */

static void EepDrv_StateMachine (void);
static void EepDrv_InitInternalParam (void);
/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
/*----------------- Range of EepDrv_JobStateType  ------------------------- */
//todo: arrive at the Job States
#define EEPDRV_JOB_STATE_IDLE              (uint8)0
#define EEPDRV_JOB_STATE_START             (uint8)1
#define EEPDRV_JOB_STATE_CBK_WAIT          (uint8)2
#define EEPDRV_JOB_STATE_VALIDATE          (uint8)3
#define EEPDRV_JOB_STATE_END_NOTIFY        (uint8)4
#define EEPDRV_JOB_STATE_ERROR_NOTIFY      (uint8)5
#define EEPDRV_JOB_WAIT_FOR_DEVICE_TIMEOUT (uint8)6

/*------------------- Range of EepDrv_JobType    ------------------------- */
#define EEPDRV_JOB_TYPE_READ               (uint8)0
#define EEPDRV_JOB_TYPE_WRITE              (uint8)1
#define EEPDRV_JOB_TYPE_ERASE              (uint8)2
#define EEPDRV_JOB_TYPE_COMPARE            (uint8)3
#define EEPDRV_JOB_TYPE_MAX                (uint8)4

/*------------------- Range of EepDrv status ------------------------------ */
#define EEPDRV_TIMER_STARTED               (uint8)0
#define EEPDRV_TIMER_STOPPED               (uint8)1
#define EEPDRV_TIMER_ELAPSED               (uint8)2
#define EEPDRV_TIMER_IDLE                  (uint8)0xFF

#define EEP_SHIFT_BY_8      8
#define EEP_SHIFT_BY_1      1
#define EEP_8BIT_MAX_VAL    0x00FF
#define EEP_HEX_VALUE_7     0x0007
#define EEP_HEX_VALUE_2     0x02
#define EEP_HEX_VALUE_3     0x03
#define EEP_HEX_VALUE_6     0x06
#define EEP_VALUE_1         1
#define EEP_VALUE_2         2
#define EEP_VALUE_3         3
#define EEP_HEX_VALUE_3U    0x03u
#define EEP_8BIT_MAX_VAL_U  0x00FFU
#define EEP_DEC_BY_1U       1u

#ifdef I2C_EEPROM_USED
/* List of Eep24xx DRV JOB HANDLERS  */
#define EEP24XX_JOB_START_HANDLERS \
                &Eep24xx_StartRead,  \
                &Eep24xx_StartWrite, \
                &Eep24xx_StartErase, \
                &Eep24xx_StartCompare

#endif /* I2C_EEPROM_USED */


#ifdef SPI_EEPROM_USED
/* List of Eep25xx DRV JOB HANDLERS  */
#define EEP25XX_JOB_START_HANDLERS \
                &Eep25xx_StartRead,  \
                &Eep25xx_StartWrite, \
                &Eep25xx_StartErase, \
                &Eep25xx_StartCompare
#endif /* SPI_EEPROM_USED */

/* Used to prevent warnings about unused parameters */
#define EEPDRV_UNUSED_PARAMETER(x) (void)(x)

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/
typedef uint8 EepDrv_JobStateType;

typedef uint8 EepDrv_JobType;

typedef uint8 EepDrv_EepromIdType;


typedef struct
{
    uint8*                  ClientAddress;          /* Address of external buffer from EA */
    EepDrv_AddressType     ChipAddress;            /* Eeprom Physical Address */
    EepDrv_LengthType      RemainingBytes;         /* Remaining Bytes to be transferred */
    EepDrv_JobType         JobActiveId;            /* Current Job Type */
    EepDrv_JobStateType    JobState;               /* Current State of the Job */
    MemIf_JobResultType     JobResult;              /* Result of the current Job */
    EepDrv_SeqResultType    PendingSeqResult;    /* Result of the last I2c sequence */
    EepDrv_LengthType      ChunkSize;              /* Read/Write Size per sequence */
#ifdef SPI_EEPROM_USED
    Spi_SequenceType        PendingSpiSeqId;
    uint8 WriteEnableSpiChip;
    uint8 SpiWriteCommnad;
#endif /* SPI_EEPROM_USED */
#ifdef I2C_EEPROM_USED
    I2c_SequenceType        PendingI2cSeqId;        /* Sequence ID of the current I2 Sequence */
#endif /* I2C_EEPROM_USED */
    EepDrv_EepromIdType     EepromId;               /* Eeprom device id */
    boolean                 ProcessState;           /* Flag to check the state machine needs to be processed continously*/
    boolean                 CbkServiced;            /* Flag to intimate the StateMachine that the
                                                      Callback has been serviced by I2c */
} EepDrv_JobParamType;

typedef struct
{
    TickType                  StartTime;
    TickType                  EndTime;
    uint8                     Status;
} EepDrv_TimerType;
/*****************************************************************************
*                                Globally  accessed Variable Declarations    *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/

/*****************************************************************************
*                                 Locally used Variable Declarations         *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/

#define EEPDRV_DATA_SEC_START
#include "MemMap.h"
//todo: revisit if this can be made as local variable
__attribute__((aligned(4)))
static Eep_DataType EepDrv_Buffer[EEPDRV_MAX_BUFFER_SIZE];

__attribute__((aligned(4)))
static Eep_DataType EepDrv_AddressBuffer[EEPDRV_ADDRESS_BUFFER_MAX_SIZE];

static EepDrv_TimerType EepDrv_Timer = {0,0,EEPDRV_TIMER_IDLE};

static EepDrv_JobParamType EepDrv_JobParam;

#ifdef SPI_EEPROM_USED
__attribute__((aligned(4)))
static uint8 Spi_RxBuff[128];
#endif



/*****************************************************************************
*                              Limited Scope Prototypes                      *
******************************************************************************/


#ifdef I2C_EEPROM_USED
static Std_ReturnType (* const Eep24xx_JobStartHandler[EEPDRV_JOB_TYPE_MAX])(void) = {EEP24XX_JOB_START_HANDLERS};
#endif /* I2C_EEPROM_USED */

#ifdef SPI_EEPROM_USED
static Std_ReturnType (* const Eep25xx_JobStartHandler[EEPDRV_JOB_TYPE_MAX])(void) = {EEP25XX_JOB_START_HANDLERS};
#endif /* SPI_EEPROM_USED */

static uint8 Eepdrv_PrvWaitForDeviceTimeout(void);
#define EEPDRV_DATA_SEC_END
#include "MemMap.h"


/*****************************************************************************
*                   Functions                                                *
******************************************************************************/

/*============================================================================
**
** Function Name    :   EepDrv_Init
**
** Visibility       :   Public
**
** Description      :   Service for EEPROM initialization
**
** Invocation       :   Function is called in EcuM context
**
** Inputs           :   ConfigPtr
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
void EepDrv_Init(const EepDrv_ConfigType* ConfigPtr)
{
    EEPDRV_UNUSED_PARAMETER(ConfigPtr);
    EepDrv_InitInternalParam();
}

/*============================================================================
**
** Function Name    :   EepDrv_SetMode
**
** Visibility       :   Public
**
** Description      :   Service used to switch between normal and fast Eep acces
**
** Invocation       :   Function is called in task context
**
** Inputs           :   Mode - The EEPROM Opearation Mode that has to be set
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
void EepDrv_SetMode(MemIf_ModeType Mode)
{
    EEPDRV_UNUSED_PARAMETER(Mode);
}

/*============================================================================
**
** Function Name    :   EepDrv_Read
**
** Visibility       :   Public
**
** Description      :   Service reads a data block from the Eeprom
**
** Invocation       :   Function is called in task context
**
** Inputs           :   EepAddress    Address offset in Eeprom
**                      Length        Number of bytes to read
**
** Outputs          :   DataBufferPtr Pointer to destination data buffer in ram
**
** Critical Section :
**
**==========================================================================*/
Std_ReturnType EepDrv_Read(EepDrv_AddressType EepromAddress, uint8* DataBufferPtr,EepDrv_LengthType Length)
{
    Std_ReturnType retVal = E_NOT_OK;
    uint8 DeviceIndex = 0u;

    if(EepromAddress >= EEPDRV_TOTAL_MEM_SIZE)
    {
        EEPDRV_REPORT_ERROR(EEPDRV_READ_API, EEPDRV_E_PARAM_ADDRESS);
    }
    else if((Length == 0U) || ((uint32)(EepromAddress + Length) > EEPDRV_TOTAL_MEM_SIZE))
    {
        EEPDRV_REPORT_ERROR(EEPDRV_READ_API, EEPDRV_E_PARAM_LENGTH);
    }
    else if(DataBufferPtr == NULL_PTR)
    {
        EEPDRV_REPORT_ERROR(EEPDRV_READ_API, EEPDRV_E_PARAM_DATA);
    }
    else if (EepDrv_JobParam.JobState == EEPDRV_JOB_STATE_IDLE)

    {
        //todo: determine the DET stuffs for validating the Write API and params

        //clear all info about last Job
        EepDrv_InitInternalParam();

        for (DeviceIndex = 0U; DeviceIndex < (uint8)EEP_NUMBER_OF_DEVICES_SUPPORTED; DeviceIndex ++)
        {
            if ( EepromAddress <= Eep_DeviceConfig[DeviceIndex].MemorySize )
            {
                EepDrv_JobParam.EepromId = DeviceIndex;
                break;
            }
        }

        if (EepDrv_JobParam.EepromId < EEP_NUMBER_OF_DEVICES_SUPPORTED)
        {
            EepDrv_JobParam.ChipAddress = EepromAddress - Eep_DeviceConfig[EepDrv_JobParam.EepromId].BaseAddress;

            EepDrv_JobParam.ChunkSize = Eep_DeviceConfig[EepDrv_JobParam.EepromId].ReadBlockSize;
        }
        else
        {
            DEBUG_ASSERT( FALSE );
        }
        EepDrv_JobParam.ClientAddress = DataBufferPtr;
        EepDrv_JobParam.RemainingBytes = Length;


        EepDrv_JobParam.JobActiveId = EEPDRV_JOB_TYPE_READ;

        EepDrv_JobParam.JobResult = MEMIF_JOB_PENDING;

        EepDrv_JobParam.JobState = EEPDRV_JOB_STATE_START;

        retVal = E_OK;
    }
    else
    {
        EEPDRV_REPORT_ERROR(EEPDRV_READ_API, EEPDRV_E_BUSY);
    }

    return retVal;
}

/*============================================================================
**
** Function Name    :   EepDrv_Write
**
** Visibility       :   Public
**
** Description      :   Service writes a data block to the Eeprom
**
** Invocation       :   Function is called in task context
**
** Inputs           :   EepAddress    Address offset in Eeprom
**                      DataBufferPtr Pointer to destination data buffer in ram
**                      Length        Number of bytes to write
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
Std_ReturnType EepDrv_Write(EepDrv_AddressType EepromAddress,const uint8* DataBufferPtr,EepDrv_LengthType Length)
{
    Std_ReturnType retVal = E_NOT_OK;
    uint8 DeviceIndex = 0u;

    if(EepromAddress >= EEPDRV_TOTAL_MEM_SIZE)
    {
        EEPDRV_REPORT_ERROR(EEPDRV_WRITE_API, EEPDRV_E_PARAM_ADDRESS);
    }
    else if((Length == 0U) || ((uint32)(EepromAddress + Length) > EEPDRV_TOTAL_MEM_SIZE))
    {
        EEPDRV_REPORT_ERROR(EEPDRV_WRITE_API, EEPDRV_E_PARAM_LENGTH);
    }
    else if(DataBufferPtr == NULL_PTR)
    {
        EEPDRV_REPORT_ERROR(EEPDRV_WRITE_API, EEPDRV_E_PARAM_DATA);
    }
    else if (EepDrv_JobParam.JobState == EEPDRV_JOB_STATE_IDLE)
    {
        //todo: determine the DET stuffs for validating the Write API and params

        //clear all info about last Job
        EepDrv_InitInternalParam();

        for (DeviceIndex = 0U; DeviceIndex < (uint8)EEP_NUMBER_OF_DEVICES_SUPPORTED; DeviceIndex ++)
        {
            if ( EepromAddress <= Eep_DeviceConfig[DeviceIndex].MemorySize )
            {
                EepDrv_JobParam.EepromId = DeviceIndex;
                break;
            }
        }

        if (EepDrv_JobParam.EepromId < EEP_NUMBER_OF_DEVICES_SUPPORTED)
        {
            EepDrv_JobParam.ChipAddress = EepromAddress - Eep_DeviceConfig[EepDrv_JobParam.EepromId].BaseAddress;

            EepDrv_JobParam.ChunkSize =  Eep_DeviceConfig[EepDrv_JobParam.EepromId].WriteBlockSize;
        }
        else
        {
            DEBUG_ASSERT( FALSE );
        }

        EepDrv_JobParam.ClientAddress = (uint8 *)DataBufferPtr;
        EepDrv_JobParam.RemainingBytes = Length;


        EepDrv_JobParam.JobActiveId = EEPDRV_JOB_TYPE_WRITE;

        EepDrv_JobParam.JobResult = MEMIF_JOB_PENDING;

        EepDrv_JobParam.JobState = EEPDRV_JOB_STATE_START;

        retVal = E_OK;
    }
    else
    {
        EEPDRV_REPORT_ERROR(EEPDRV_WRITE_API, EEPDRV_E_BUSY);
    }

    return retVal;
}

/*============================================================================
**
** Function Name    :   EepDrv_Erase
**
** Visibility       :   Public
**
** Description      :   Service erases a data block of the Eep
**
** Invocation       :   Function is called in task context
**
** Inputs           :   EepAddress    Address offset in Eeprom
**                      Length        Number of bytes to write
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
Std_ReturnType EepDrv_Erase(EepDrv_AddressType EepromAddress, EepDrv_LengthType Length)
{
    Std_ReturnType retVal = E_NOT_OK;
    uint8 DeviceIndex = 0u;

    if(EepromAddress >= EEPDRV_TOTAL_MEM_SIZE)
    {
        EEPDRV_REPORT_ERROR(EEPDRV_ERASE_API, EEPDRV_E_PARAM_ADDRESS);
    }
    else if((Length == 0U) || ((uint32)(EepromAddress + Length) > EEPDRV_TOTAL_MEM_SIZE))
    {
        EEPDRV_REPORT_ERROR(EEPDRV_ERASE_API, EEPDRV_E_PARAM_LENGTH);
    }
    else if (EepDrv_JobParam.JobState == EEPDRV_JOB_STATE_IDLE)
    {
        //todo: determine the DET stuffs for validating the Write API and params

        //clear all info about last Job
        EepDrv_InitInternalParam();

        for (DeviceIndex = 0U; DeviceIndex < (uint8)EEP_NUMBER_OF_DEVICES_SUPPORTED; DeviceIndex ++)
        {
            if ( EepromAddress <= Eep_DeviceConfig[DeviceIndex].MemorySize )
            {
                EepDrv_JobParam.EepromId = DeviceIndex;
                break;
            }
        }

        if (EEP_NUMBER_OF_DEVICES_SUPPORTED > EepDrv_JobParam.EepromId)
        {
            EepDrv_JobParam.ChipAddress = EepromAddress - Eep_DeviceConfig[EepDrv_JobParam.EepromId].BaseAddress;

            EepDrv_JobParam.ChunkSize =  Eep_DeviceConfig[EepDrv_JobParam.EepromId].WriteBlockSize;
        }
        else
        {
            DEBUG_ASSERT( FALSE );
        }

        EepDrv_JobParam.RemainingBytes = Length;

        EepDrv_JobParam.JobActiveId = EEPDRV_JOB_TYPE_ERASE;

        EepDrv_JobParam.JobResult = MEMIF_JOB_PENDING;

        EepDrv_JobParam.JobState = EEPDRV_JOB_STATE_START;

        retVal = E_OK;
    }
    else
    {
        EEPDRV_REPORT_ERROR(EEPDRV_ERASE_API, EEPDRV_E_BUSY);
    }

    return retVal;
}

/*============================================================================
**
** Function Name    :   EepDrv_Compare
**
** Visibility       :   Public
**
** Description      :   Service compares an Eep data block with a data block in the ram
**
** Invocation       :   Function is called in task context
**
** Inputs           :   EepAddress    Address offset in Eeprom
**                      DataBufferPtr Pointer to destination data buffer in ram
**                      Length        Number of bytes to read
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
Std_ReturnType EepDrv_Compare(EepDrv_AddressType EepromAddress,const uint8* DataBufferPtr,EepDrv_LengthType Length)
{
    Std_ReturnType retVal = E_NOT_OK;
    uint8 DeviceIndex = 0u;

    if(EepromAddress >= EEPDRV_TOTAL_MEM_SIZE)
    {
        EEPDRV_REPORT_ERROR(EEPDRV_COMPARE_API, EEPDRV_E_PARAM_ADDRESS);
    }
    else if((Length == 0U) || ((uint32)(EepromAddress + Length) > EEPDRV_TOTAL_MEM_SIZE))
    {
        EEPDRV_REPORT_ERROR(EEPDRV_COMPARE_API, EEPDRV_E_PARAM_LENGTH);
    }
    else if(DataBufferPtr == NULL_PTR)
    {
        EEPDRV_REPORT_ERROR(EEPDRV_COMPARE_API, EEPDRV_E_PARAM_DATA);
    }
    else if (EepDrv_JobParam.JobState == EEPDRV_JOB_STATE_IDLE)
    {

        //todo: determine the DET stuffs for validating the Write API and params

        //clear all info about last Job
        EepDrv_InitInternalParam();

        for (DeviceIndex = 0U; DeviceIndex < (uint8)EEP_NUMBER_OF_DEVICES_SUPPORTED; DeviceIndex ++)
        {
            if ( EepromAddress <= Eep_DeviceConfig[DeviceIndex].MemorySize )
            {
                EepDrv_JobParam.EepromId = DeviceIndex;
                break;
            }
        }

        if (EEP_NUMBER_OF_DEVICES_SUPPORTED > EepDrv_JobParam.EepromId)
        {
            EepDrv_JobParam.ChipAddress = EepromAddress - Eep_DeviceConfig[EepDrv_JobParam.EepromId].BaseAddress;
			EepDrv_JobParam.ChunkSize = Eep_DeviceConfig[EepDrv_JobParam.EepromId].ReadBlockSize;

        }
        else
        {
            DEBUG_ASSERT( FALSE );
        }

        EepDrv_JobParam.ClientAddress = (uint8 *)DataBufferPtr;
        EepDrv_JobParam.RemainingBytes = Length;

        EepDrv_JobParam.JobActiveId = EEPDRV_JOB_TYPE_COMPARE;

        EepDrv_JobParam.JobResult = MEMIF_JOB_PENDING;

        EepDrv_JobParam.JobState = EEPDRV_JOB_STATE_START;

        retVal = E_OK;
    }
    else
    {
        EEPDRV_REPORT_ERROR(EEPDRV_COMPARE_API, EEPDRV_E_BUSY);
    }

    return retVal;
}

/*============================================================================
**
** Function Name    :   EepDrv_Cancel
**
** Visibility       :   Public
**
** Description      :   Dummy API to comply with mandatory interfaces of EepDriver
**                      Autosar4.2.1
**
** Invocation       :   Should not be invoked as this functionality is not supported
**
** Inputs           :
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
void EepDrv_Cancel (void)
{
    return;
}

/*============================================================================
**
** Function Name    :   EepDrv_GetStatus
**
** Visibility       :   Public
**
** Description      :   Service returns the status of the Eeprom driver
**
** Invocation       :   Function is called in task context
**
** Inputs           :   None
**
** Outputs          :   MemIf_StatusType:   status of the driver
**
** Critical Section :
**
**==========================================================================*/
MemIf_StatusType EepDrv_GetStatus(void)
{
    MemIf_StatusType retVal = MEMIF_BUSY;

    if (EepDrv_JobParam.JobState == EEPDRV_JOB_STATE_IDLE)
    {
        /* EEPROM driver is idle */
        retVal = MEMIF_IDLE;
    }
    return retVal;
}

/*============================================================================
**
** Function Name    :   EepDrv_GetJobResult
**
** Visibility       :   Public
**
** Description      :   Service returns the result of the last accepted job,
**                      as long as no new job is accepted.
**
** Invocation       :   Function is called in task context
**
** Inputs           :   None
**
** Outputs          :   MemIf_JobResultType:    result of the last accepted Eeprom Job
**
** Critical Section :
**
**==========================================================================*/
MemIf_JobResultType EepDrv_GetJobResult(void)
{
    return (EepDrv_JobParam.JobResult);
}

/*============================================================================
**
** Function Name    :   EepDrv_MainFunction
**
** Visibility       :   Public
**
** Description      :   Service to perform the processing of the
**                      EEPROM jobs (read/write/erase/compare).
**
** Invocation       :   Function is called cyclically
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   Yes
**
**==========================================================================*/
void EepDrv_MainFunction(void)
{
    if (EepDrv_JobParam.JobState != EEPDRV_JOB_STATE_IDLE)
    {
        do
        {
            EepDrv_StateMachine();
        }
        while(FALSE != EepDrv_JobParam.ProcessState);
    }
}
#ifdef I2C_EEPROM_USED
/*============================================================================
**
** Function Name    :   Eep24xx_I2cSequenceEndCbk
**
** Visibility       :   Public
**
** Description      :   EEPROM driver callback called on communication
**                      completion of EEPROM jobs (read/write/erase/compare).
**
** Invocation       :   Function is called by I2cDriver
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
void Eep24xx_I2cSequenceEndCbk (void)
{
    I2c_SeqResultType JobResult = 0u;
    //Copy the I2c sequence result
    JobResult = I2c_GetSequenceResult(EepDrv_JobParam.PendingI2cSeqId);

    if(I2C_SEQ_OK == JobResult)
    {
        EepDrv_JobParam.PendingSeqResult = EEPDRV_SEQ_OK;
    }
    else
    {
        EepDrv_JobParam.PendingSeqResult = EEPDRV_SEQ_FAILED;
    }

    //Set the CbkServiced flag as TRUE for the state machine processing
    EepDrv_JobParam.CbkServiced = TRUE;
}

/*============================================================================
**
** Function Name    :   Eep24xx_StartRead
**
** Visibility       :   Private
**
** Description      :   Routine to perform read job
**
** Invocation       :   State Machine
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
static Std_ReturnType Eep24xx_StartRead (void)
{
    I2c_DataType *SrcDataBufferPtr = NULL_PTR;
    I2c_DataType *DesDataBufferPtr = NULL_PTR;
    EepDrv_AddressType PhysicalAddress = EepDrv_JobParam.ChipAddress;
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 TxLength = 0U;
    uint8 RxLength = 0U;
    uint8 SlaveAddress = 0u;
    uint8 SequenceId = 0u;

    SlaveAddress   = Eep_DeviceConfig[EepDrv_JobParam.EepromId].SlaveAddress;

    if ( EepDrv_JobParam.RemainingBytes > Eep_DeviceConfig[EepDrv_JobParam.EepromId].ReadBlockSize )
    {
        EepDrv_JobParam.ChunkSize = Eep_DeviceConfig[EepDrv_JobParam.EepromId].ReadBlockSize;
    }
    else
    {
        EepDrv_JobParam.ChunkSize = EepDrv_JobParam.RemainingBytes;
    }

    if ( Eep_DeviceConfig[EepDrv_JobParam.EepromId].ChipType == BIG_EEPROM )
    {
        EepDrv_AddressBuffer[0]   =   ((I2c_DataType)((PhysicalAddress >> EEP_SHIFT_BY_8) & EEP_8BIT_MAX_VAL));
        EepDrv_AddressBuffer[EEP_VALUE_1]   =   ((I2c_DataType)(PhysicalAddress & EEP_8BIT_MAX_VAL));
    }
    else
    {
        EepDrv_AddressBuffer[0]   =   ((I2c_DataType)(PhysicalAddress & EEP_8BIT_MAX_VAL));
        PhysicalAddress            =   ((PhysicalAddress >> EEP_SHIFT_BY_8) & EEP_HEX_VALUE_7);    //To extract the last 3 address bits
        PhysicalAddress            =   (PhysicalAddress << EEP_SHIFT_BY_1);               //To form the I2C frame address format(SlaveAddress(7bits) + 1(read/write bit)
        SlaveAddress               |=  ((uint8)PhysicalAddress);             //For CAT24C04,24C08,24C16 EEPROM, the address bits of (a8), (a9,a8), (a10,a9,a8) respectively needs to be appended with slave address
    }

    //todo: Need to check if the below step is really reqd
    //MemLib_MemSet((uint8*)(&(EepDrv_Buffer[2])), 0xFF, (sizeof(uint8) * EepDrv_JobParam.ChunkSize));

    SrcDataBufferPtr = &EepDrv_AddressBuffer[0];
    TxLength = Eep_DeviceConfig[EepDrv_JobParam.EepromId].AddressBufferSize;

    DesDataBufferPtr = (I2c_DataType*)EepDrv_JobParam.ClientAddress;
    RxLength         = (uint8)EepDrv_JobParam.ChunkSize;
    SequenceId       = Eep_DeviceConfig[EepDrv_JobParam.EepromId].ReadSequenceId;

    if (E_OK == I2c_SetupEB(SequenceId, SrcDataBufferPtr, DesDataBufferPtr, TxLength, RxLength, SlaveAddress))
    {
        EepDrv_JobParam.PendingI2cSeqId = SequenceId;
        RetVal = I2c_AsyncTransmit(EepDrv_JobParam.PendingI2cSeqId);
    }

    return (RetVal);
}

/*============================================================================
**
** Function Name    :   Eep24xx_StartErase
**
** Visibility       :   Private
**
** Description      :   Routine to perform erase job
**
** Invocation       :   State Machine
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
static Std_ReturnType Eep24xx_StartErase (void)
{
    EepDrv_AddressType PhysicalAddress = EepDrv_JobParam.ChipAddress;
    I2c_DataType *SrcDataBufferPtr = NULL_PTR;
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 TxLength = 0U;
    uint8 RxLength = 0U;
    uint8 SlaveAddress = 0u;
    uint8 SequenceId = 0u;
    uint8 DataStartIndex = 0u;

    SlaveAddress               = Eep_DeviceConfig[EepDrv_JobParam.EepromId].SlaveAddress;
    EepDrv_JobParam.ChunkSize = (Eep_DeviceConfig[EepDrv_JobParam.EepromId].ChipPageSize - (EepDrv_JobParam.ChipAddress & (Eep_DeviceConfig[EepDrv_JobParam.EepromId].ChipPageSize -1)));

    if (EepDrv_JobParam.ChunkSize > EepDrv_JobParam.RemainingBytes)
    {
        EepDrv_JobParam.ChunkSize = EepDrv_JobParam.RemainingBytes;
    }

    if ( Eep_DeviceConfig[EepDrv_JobParam.EepromId].ChipType == BIG_EEPROM)
    {
        EepDrv_Buffer[0]   =   ((I2c_DataType)((PhysicalAddress >> EEP_SHIFT_BY_8) & EEP_8BIT_MAX_VAL));
        EepDrv_Buffer[EEP_VALUE_1]   =   ((I2c_DataType)(PhysicalAddress & EEP_8BIT_MAX_VAL));
    }
    else
    {
        EepDrv_Buffer[0]   =   ((I2c_DataType)(PhysicalAddress & EEP_8BIT_MAX_VAL));
        PhysicalAddress     =   ((PhysicalAddress >> EEP_SHIFT_BY_8) & EEP_HEX_VALUE_7);  //To extract the last 3 address bits
        PhysicalAddress     =   (PhysicalAddress << EEP_SHIFT_BY_1);             //To form the I2C frame address format(SlaveAddress(7bits) + 1(read/write bit)
        SlaveAddress        |=  ((uint8)PhysicalAddress);           //For CAT24C04,24C08,24C16 EEPROM, the address bits of (a8), (a9,a8), (a10,a9,a8) respectively needs to be appended with slave address
    }

    DataStartIndex = Eep_DeviceConfig[EepDrv_JobParam.EepromId].BuffStartDataIndex;
    MemLib_MemSet((uint8*)(&(EepDrv_Buffer[DataStartIndex])), \
                  Eep_DeviceConfig[EepDrv_JobParam.EepromId].EraseValue, (sizeof(uint8) * EepDrv_JobParam.ChunkSize));

    SrcDataBufferPtr = &EepDrv_Buffer[0];

    TxLength   = (uint8)(EepDrv_JobParam.ChunkSize + Eep_DeviceConfig[EepDrv_JobParam.EepromId].AddressBufferSize);
    RxLength   = 0U;
    SequenceId = Eep_DeviceConfig[EepDrv_JobParam.EepromId].WriteSequenceId;

    if (E_OK == I2c_SetupEB(SequenceId, SrcDataBufferPtr, NULL_PTR, TxLength, RxLength, SlaveAddress))
    {
        EepDrv_JobParam.PendingI2cSeqId = SequenceId;
        RetVal = I2c_AsyncTransmit(EepDrv_JobParam.PendingI2cSeqId);
    }

    return (RetVal);
}

/*============================================================================
**
** Function Name    :   Eep24xx_StartWrite
**
** Visibility       :   Private
**
** Description      :   Routine to perform write job
**
** Invocation       :   State Machine
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
static Std_ReturnType Eep24xx_StartWrite (void)
{
    EepDrv_AddressType PhysicalAddress = EepDrv_JobParam.ChipAddress;
    I2c_DataType *SrcDataBufferPtr = NULL_PTR;
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 TxLength = 0U;
    uint8 RxLength = 0U;
    uint8 SlaveAddress = 0U;
    uint8 SequenceId = 0U;
    uint8 DataStartIndex = 0U;

    SlaveAddress   = Eep_DeviceConfig[EepDrv_JobParam.EepromId].SlaveAddress;
    EepDrv_JobParam.ChunkSize = (Eep_DeviceConfig[EepDrv_JobParam.EepromId].ChipPageSize - (EepDrv_JobParam.ChipAddress & (Eep_DeviceConfig[EepDrv_JobParam.EepromId].ChipPageSize -1)));

    if (EepDrv_JobParam.ChunkSize > EepDrv_JobParam.RemainingBytes)
    {
        EepDrv_JobParam.ChunkSize = EepDrv_JobParam.RemainingBytes;
    }

    if(Eep_DeviceConfig[EepDrv_JobParam.EepromId].ChipType == BIG_EEPROM)
    {
        EepDrv_Buffer[0]   =   ((I2c_DataType)((PhysicalAddress >> EEP_SHIFT_BY_8) & EEP_8BIT_MAX_VAL));
        EepDrv_Buffer[EEP_VALUE_1]   =   ((I2c_DataType)(PhysicalAddress & EEP_8BIT_MAX_VAL));
    }
    else
    {
        EepDrv_Buffer[0]   =   ((I2c_DataType)(PhysicalAddress & EEP_8BIT_MAX_VAL));
        PhysicalAddress     =   ((PhysicalAddress >> EEP_SHIFT_BY_8) & EEP_HEX_VALUE_7);  //To extract the last 3 address bits
        PhysicalAddress     =   (PhysicalAddress << EEP_SHIFT_BY_1);             //To form the I2C frame address format(SlaveAddress(7bits) + 1(read/write bit)
        SlaveAddress       |=   ((uint8)PhysicalAddress);           //For CAT24C04,24C08,24C16 EEPROM, the address bits of (a8), (a9,a8), (a10,a9,a8) respectively needs to be appended with slave address
    }

    DataStartIndex = Eep_DeviceConfig[EepDrv_JobParam.EepromId].BuffStartDataIndex;
    MemLib_MemCpy((uint8*)(&EepDrv_Buffer[DataStartIndex]), \
                  EepDrv_JobParam.ClientAddress, (sizeof(uint8) * EepDrv_JobParam.ChunkSize));

    SrcDataBufferPtr = &EepDrv_Buffer[0];
    TxLength         = (uint8)(EepDrv_JobParam.ChunkSize + Eep_DeviceConfig[EepDrv_JobParam.EepromId].AddressBufferSize);
    RxLength         = 0U;
    SequenceId       = Eep_DeviceConfig[EepDrv_JobParam.EepromId].WriteSequenceId;

    if (E_OK == I2c_SetupEB(SequenceId, SrcDataBufferPtr, NULL_PTR, TxLength, RxLength, SlaveAddress))
    {
        EepDrv_JobParam.PendingI2cSeqId = SequenceId;
        RetVal = I2c_AsyncTransmit(EepDrv_JobParam.PendingI2cSeqId);
    }

    return (RetVal);
}

/*============================================================================
**
** Function Name    :   Eep24xx_StartCompare
**
** Visibility       :   Private
**
** Description      :   Routine to start compare job
**
** Invocation       :   State Machine
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
static Std_ReturnType Eep24xx_StartCompare (void)
{
    EepDrv_AddressType PhysicalAddress = EepDrv_JobParam.ChipAddress;
    I2c_DataType *SrcDataBufferPtr = NULL_PTR;
    I2c_DataType *DesDataBufferPtr = NULL_PTR;

    Std_ReturnType RetVal = E_NOT_OK;
    uint8 TxLength = 0U;
    uint8 RxLength = 0U;
    uint8 SlaveAddress = 0U;
    uint8 SequenceId = 0U;

    SlaveAddress   = Eep_DeviceConfig[EepDrv_JobParam.EepromId].SlaveAddress;

    if (EepDrv_JobParam.RemainingBytes > Eep_DeviceConfig[EepDrv_JobParam.EepromId].ReadBlockSize)
    {
        EepDrv_JobParam.ChunkSize = Eep_DeviceConfig[EepDrv_JobParam.EepromId].ReadBlockSize;
    }
    else
    {
        EepDrv_JobParam.ChunkSize = EepDrv_JobParam.RemainingBytes;
    }

    if (Eep_DeviceConfig[EepDrv_JobParam.EepromId].ChipType == BIG_EEPROM)
    {
        EepDrv_AddressBuffer[0]   =   ((I2c_DataType)((PhysicalAddress >> EEP_SHIFT_BY_8) & EEP_8BIT_MAX_VAL));
        EepDrv_AddressBuffer[EEP_VALUE_1]   =   ((I2c_DataType)(PhysicalAddress & EEP_8BIT_MAX_VAL));
    }
    else
    {
        EepDrv_AddressBuffer[0]   =   ((I2c_DataType)(PhysicalAddress & EEP_8BIT_MAX_VAL));
        PhysicalAddress            =   ((PhysicalAddress >> EEP_SHIFT_BY_8) & EEP_HEX_VALUE_7);    //To extract the last 3 address bits
        PhysicalAddress            =   (PhysicalAddress << EEP_SHIFT_BY_1);               //To form the I2C frame address byte format(SlaveAddress(7bits) + 1(read/write bit)
        SlaveAddress               |=  ((uint8)PhysicalAddress);             //For CAT24C04,24C08,24C16 EEPROM, the address bits of (a8), (a9,a8), (a10,a9,a8) respectively needs to be appended with slave address
    }

    SrcDataBufferPtr = &EepDrv_AddressBuffer[0];
    TxLength = Eep_DeviceConfig[EepDrv_JobParam.EepromId].AddressBufferSize;

    DesDataBufferPtr = &EepDrv_Buffer[0];
    RxLength         = (uint8)EepDrv_JobParam.ChunkSize;
    SequenceId       = Eep_DeviceConfig[EepDrv_JobParam.EepromId].ReadSequenceId;

    if (E_OK == I2c_SetupEB(SequenceId, SrcDataBufferPtr, DesDataBufferPtr, TxLength, RxLength, SlaveAddress))
    {
        EepDrv_JobParam.PendingI2cSeqId = SequenceId;
        RetVal = I2c_AsyncTransmit(EepDrv_JobParam.PendingI2cSeqId);
    }

    return (RetVal);
}
#endif /* I2C_EEPROM_USED */


#ifdef SPI_EEPROM_USED
/*============================================================================
**
** Function Name    :   SpiEEJobEndNotification
**
** Visibility       :   Public
**
** Description      :
**
** Invocation       :
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
void SpiEEJobEndNotification(void)
{
    //Set the CbkServiced flag as TRUE for the state machine processing
    EepDrv_JobParam.CbkServiced = TRUE;
}

/*============================================================================
**
** Function Name    :   Eep25xx_StartRead
**
** Visibility       :   Private
**
** Description      :   Routine to perform read job
**
** Invocation       :   State Machine
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
static Std_ReturnType Eep25xx_StartRead (void)
{
    Eep_DataType *SrcDataBufferPtr = NULL_PTR;
    Eep_DataType *DesDataBufferPtr = NULL_PTR;
    EepDrv_AddressType PhysicalAddress = EepDrv_JobParam.ChipAddress;
    Std_ReturnType RetVal = E_NOT_OK;
    uint16 Length = 0U;
    uint8 SequenceId = 0U;

    if (EepDrv_JobParam.EepromId < EEP_NUMBER_OF_DEVICES_SUPPORTED)
    {
        if ( EepDrv_JobParam.RemainingBytes > Eep_DeviceConfig[EepDrv_JobParam.EepromId].ReadBlockSize )
        {
            EepDrv_JobParam.ChunkSize = Eep_DeviceConfig[EepDrv_JobParam.EepromId].ReadBlockSize;
        }
        else
        {
            EepDrv_JobParam.ChunkSize = EepDrv_JobParam.RemainingBytes;
        }
    }
    else
    {
        DEBUG_ASSERT( FALSE );
    }
    //todo: Need to check if the below step is really reqd
    //MemLib_MemSet((uint8*)(&(EepDrv_Buffer[2])), 0xFF, (sizeof(uint8) * EepDrv_JobParam.ChunkSize));

    EepDrv_AddressBuffer[0] = EEP_HEX_VALUE_3;
    EepDrv_AddressBuffer[EEP_VALUE_1] =  (PhysicalAddress >> EEP_SHIFT_BY_8) & EEP_8BIT_MAX_VAL_U;
    EepDrv_AddressBuffer[EEP_VALUE_2] =  (uint8)PhysicalAddress & EEP_8BIT_MAX_VAL_U;


    SrcDataBufferPtr = &EepDrv_AddressBuffer[0];
    DesDataBufferPtr = (uint8*)&Spi_RxBuff[0];
    Length = EepDrv_JobParam.ChunkSize + EEP_HEX_VALUE_3U;

    if (EepDrv_JobParam.EepromId < EEP_NUMBER_OF_DEVICES_SUPPORTED)
    {
        SequenceId = Eep_DeviceConfig[EepDrv_JobParam.EepromId].ReadSequenceId;

    }
    else
    {
        DEBUG_ASSERT( FALSE );
    }
    if ((uint8)E_OK == Spi_SetupEB(SequenceId, SrcDataBufferPtr,DesDataBufferPtr, Length))
    {
        EepDrv_JobParam.PendingSpiSeqId = SequenceId;
        RetVal = Spi_AsyncTransmit(EepDrv_JobParam.PendingSpiSeqId);
    }

    return (RetVal);
}

/*============================================================================
**
** Function Name    :   Eep25xx_StartErase
**
** Visibility       :   Private
**
** Description      :   Routine to perform erase job
**
** Invocation       :   State Machine
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
static Std_ReturnType Eep25xx_StartErase (void)
{
    return E_NOT_OK;
}

/*============================================================================
**
** Function Name    :   Eep25xx_StartWrite
**
** Visibility       :   Private
**
** Description      :   Routine to perform write job
**
** Invocation       :   State Machine
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
static Std_ReturnType Eep25xx_StartWrite (void)
{
    EepDrv_AddressType PhysicalAddress = EepDrv_JobParam.ChipAddress;
    Eep_DataType *SrcDataBufferPtr = NULL_PTR;
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 Length = 0U;
    uint8 SequenceId = 0U;
    if(EepDrv_JobParam.SpiWriteCommnad == (uint8)FALSE)
    {
        EepDrv_Buffer[0] = EEP_HEX_VALUE_6;
        if (EEP_NUMBER_OF_DEVICES_SUPPORTED > EepDrv_JobParam.EepromId)
        {
            SequenceId = Eep_DeviceConfig[EepDrv_JobParam.EepromId].WriteSequenceId;
        }
        else
        {
            DEBUG_ASSERT( FALSE );
        }
        if (E_OK == Spi_SetupEB(SequenceId, &EepDrv_Buffer[0],NULL, EEP_VALUE_1))
        {
            EepDrv_JobParam.PendingSpiSeqId = SequenceId;
            RetVal = Spi_AsyncTransmit(EepDrv_JobParam.PendingSpiSeqId);
            EepDrv_JobParam.SpiWriteCommnad = TRUE;
        }
    }
    else
    {
        if (EEP_NUMBER_OF_DEVICES_SUPPORTED > EepDrv_JobParam.EepromId)
        {
            EepDrv_JobParam.ChunkSize = (Eep_DeviceConfig[EepDrv_JobParam.EepromId].ChipPageSize - (EepDrv_JobParam.ChipAddress & (uint16)(Eep_DeviceConfig[EepDrv_JobParam.EepromId].ChipPageSize -EEP_DEC_BY_1U)));
        }
        else
        {
            DEBUG_ASSERT( FALSE );
        }

        if (EepDrv_JobParam.ChunkSize > EepDrv_JobParam.RemainingBytes)
        {
            EepDrv_JobParam.ChunkSize = EepDrv_JobParam.RemainingBytes;
        }

        EepDrv_Buffer[0]   =  EEP_HEX_VALUE_2;
        EepDrv_Buffer[EEP_VALUE_1]   =   (PhysicalAddress >> EEP_SHIFT_BY_8) & EEP_8BIT_MAX_VAL_U;
        EepDrv_Buffer[EEP_VALUE_2]   =   PhysicalAddress & EEP_8BIT_MAX_VAL_U;

        MemLib_MemCpy((uint8*)(&EepDrv_Buffer[EEP_VALUE_3]), \
                      EepDrv_JobParam.ClientAddress, (sizeof(uint8) * EepDrv_JobParam.ChunkSize));

        SrcDataBufferPtr = &EepDrv_Buffer[0];
        Length         = (uint8)(EepDrv_JobParam.ChunkSize + EEP_HEX_VALUE_3U);

        if (EEP_NUMBER_OF_DEVICES_SUPPORTED > EepDrv_JobParam.EepromId)
        {
            SequenceId = Eep_DeviceConfig[EepDrv_JobParam.EepromId].WriteSequenceId;
        }
        else
        {
            DEBUG_ASSERT( FALSE );
        }

        if ((uint8)E_OK == Spi_SetupEB(SequenceId, SrcDataBufferPtr,NULL, Length))
        {
            EepDrv_JobParam.PendingSpiSeqId = SequenceId;
            RetVal = Spi_AsyncTransmit(EepDrv_JobParam.PendingSpiSeqId);
            EepDrv_JobParam.SpiWriteCommnad = FALSE;
        }
    }
    return (RetVal);
}

/*============================================================================
**
** Function Name    :   Eep25xx_StartCompare
**
** Visibility       :   Private
**
** Description      :   Routine to start compare job
**
** Invocation       :   State Machine
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
static Std_ReturnType Eep25xx_StartCompare (void)
{
    return E_NOT_OK;
}
#endif /* SPI_EEPROM_USED */

/*============================================================================
**
** Function Name    :   EepDrv_PrvWaitForDeviceTimeout
**
** Visibility       :   Private
**
** Description      :   Routine to perform Device Timeout jobs
**
** Invocation       :   State Machine
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
static uint8 EepDrv_PrvWaitForDeviceTimeout(void)
{
    uint8 RetVal = FALSE;
    EepDrv_TimerType* const pEepTimer = &EepDrv_Timer;
    uint32 Delay = 0;

    if((EepDrv_JobParam.JobActiveId == EEPDRV_JOB_TYPE_WRITE) || (EepDrv_JobParam.JobActiveId == EEPDRV_JOB_TYPE_ERASE))
    {
        switch (pEepTimer->Status)
        {
        case EEPDRV_TIMER_IDLE:
        {
            EEP_DRV_GET_SYSTEM_TIMER(&pEepTimer->StartTime);
            pEepTimer->Status = EEPDRV_TIMER_STARTED;
            break;
        }
        case EEPDRV_TIMER_STARTED:
        {
            EEP_DRV_GET_SYSTEM_TIMER(&pEepTimer->EndTime);

            Delay = (uint32)( pEepTimer->EndTime - pEepTimer->StartTime );

            if( pEepTimer->EndTime < pEepTimer->StartTime )
            {
                // The 0 value has been passed, decrement the delay.
                Delay--;
            }

            if (EepDrv_JobParam.EepromId < EEP_NUMBER_OF_DEVICES_SUPPORTED)
            {
                if(Delay >= Eep_DeviceConfig[EepDrv_JobParam.EepromId].DevTimeOut_ms)
                {
                    pEepTimer->Status = EEPDRV_TIMER_ELAPSED;
                }

                if ((pEepTimer->StartTime + Eep_DeviceConfig[EepDrv_JobParam.EepromId].DevTimeOut_ms) < pEepTimer->EndTime)
                {
                    pEepTimer->Status = EEPDRV_TIMER_ELAPSED;
                }
            }
            else
            {
                DEBUG_ASSERT( FALSE );
            }
            break;
        }
        default:
            /* do nothing */
            break;
        }

        if(pEepTimer->Status != EEPDRV_TIMER_STARTED)
        {
            //move the timer state to IDLE here as the Timer is either STOPPED or ELAPSED
            pEepTimer->Status = EEPDRV_TIMER_IDLE;
            //Update the return status as TRUE as We Now Allow the Write to be started
            RetVal = TRUE;
        }
    }
    else
    {
        RetVal = TRUE;
    }
    return RetVal;
}
/*============================================================================
**
** Function Name    :   EepDrv_StateMachine
**
** Visibility       :   Private
**
** Description      :   Routine to perform Eep Driver jobs
**
** Invocation       :   Invoked by EepDrv_MainFunction
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   Yes
**
**==========================================================================*/
static void EepDrv_StateMachine (void)
{
    EepDrv_LengthType Counter = 0u;
    Std_ReturnType RetVal = E_NOT_OK;

    switch (EepDrv_JobParam.JobState)
    {
    case EEPDRV_JOB_STATE_IDLE:
    {
        /* do nothing here, simply return as we are waiting for existing job *
         * to get complete or new job to get commenced                       */
        break;
    }
    case EEPDRV_JOB_STATE_START:
    {
#ifdef I2C_EEPROM_USED
        if (EEP_NUMBER_OF_DEVICES_SUPPORTED > EepDrv_JobParam.EepromId)
        {
            if(Eep_DeviceConfig[EepDrv_JobParam.EepromId].ChipInterfaceType == I2C_EEPROM)
            {
                if(EEPDRV_JOB_TYPE_MAX > EepDrv_JobParam.JobActiveId)
                {
                    if (Eep24xx_JobStartHandler[EepDrv_JobParam.JobActiveId] != NULL)
                    {
                        RetVal = (*Eep24xx_JobStartHandler[EepDrv_JobParam.JobActiveId])();
                    }
                }
                else
                {
                    DEBUG_ASSERT( FALSE );
                }
            }
        }
        else
        {
            DEBUG_ASSERT( FALSE );
        }
#endif /* I2C_EEPROM_USED */

#ifdef SPI_EEPROM_USED
        if (EEP_NUMBER_OF_DEVICES_SUPPORTED > EepDrv_JobParam.EepromId)
        {
            if(Eep_DeviceConfig[EepDrv_JobParam.EepromId].ChipInterfaceType == (uint8)SPI_EEPROM)
            {
                if(EEPDRV_JOB_TYPE_MAX > EepDrv_JobParam.JobActiveId)
                {
                    if (Eep25xx_JobStartHandler[EepDrv_JobParam.JobActiveId] != NULL)
                    {
                        RetVal = (*Eep25xx_JobStartHandler[EepDrv_JobParam.JobActiveId])();
                    }
                }
                else
                {
                    DEBUG_ASSERT( FALSE );
                }
            }
        }
        else
        {
            DEBUG_ASSERT( FALSE );
        }
#endif
        if ((uint8)E_OK != RetVal)
        {
            EepDrv_JobParam.JobState = EEPDRV_JOB_STATE_ERROR_NOTIFY;
            EepDrv_JobParam.ProcessState = TRUE;
            EepDrv_JobParam.JobResult = MEMIF_JOB_FAILED;
        }
        else
        {
            EepDrv_JobParam.JobState = EEPDRV_JOB_STATE_CBK_WAIT;
            EepDrv_JobParam.ProcessState = FALSE;
        }
        break;
    }
    case EEPDRV_JOB_STATE_CBK_WAIT:
    {
        //wait for callback for previous I2c transfer
        EEPDRV_ENTER_CRITICAL_SECTION();

        if (EepDrv_JobParam.CbkServiced != FALSE)
        {
#ifdef SPI_EEPROM_USED
            if((uint8)TRUE == EepDrv_JobParam.SpiWriteCommnad)
            {
                EepDrv_JobParam.JobState = EEPDRV_JOB_STATE_START;
            }
            else
#endif
            {
                EepDrv_JobParam.JobState = EEPDRV_JOB_WAIT_FOR_DEVICE_TIMEOUT;
            }
            EepDrv_JobParam.ProcessState = TRUE;
            /* Reset the CbkServiced flag */
            EepDrv_JobParam.CbkServiced = FALSE;
        }

        EEPDRV_EXIT_CRITICAL_SECTION();
        break;
    }
    case EEPDRV_JOB_WAIT_FOR_DEVICE_TIMEOUT:
    {
        if(EepDrv_PrvWaitForDeviceTimeout() != (uint8)FALSE)
        {
            EepDrv_JobParam.JobState = EEPDRV_JOB_STATE_VALIDATE;
            EepDrv_JobParam.ProcessState = TRUE;
        }
        else
        {
            EepDrv_JobParam.ProcessState = FALSE;
        }
        break;
    }
    case EEPDRV_JOB_STATE_VALIDATE:
    {
        EEPDRV_ENTER_CRITICAL_SECTION();
        if (EepDrv_JobParam.PendingSeqResult != EEPDRV_SEQ_OK)
        {
            EepDrv_JobParam.JobState = EEPDRV_JOB_STATE_ERROR_NOTIFY;
            EepDrv_JobParam.ProcessState = TRUE;
            EepDrv_JobParam.JobResult = MEMIF_JOB_FAILED;
        }
        else
        {
            /* Pending Sequence is Successful */
            /* Initially assume that current job is no pending job */

            EepDrv_JobParam.JobState = EEPDRV_JOB_STATE_END_NOTIFY;
            EepDrv_JobParam.ProcessState = TRUE;

            switch (EepDrv_JobParam.JobActiveId)
            {
            case EEPDRV_JOB_TYPE_READ:
            {
#ifdef SPI_EEPROM_USED
                MemLib_MemCpy(EepDrv_JobParam.ClientAddress, \
                              (uint8*)(&Spi_RxBuff[3]), (sizeof(uint8) * EepDrv_JobParam.ChunkSize));
#endif
                EepDrv_JobParam.ChipAddress += EepDrv_JobParam.ChunkSize;
                EepDrv_JobParam.ClientAddress += EepDrv_JobParam.ChunkSize;
                EepDrv_JobParam.RemainingBytes -= EepDrv_JobParam.ChunkSize;

                //check if still job is pending
                if (EepDrv_JobParam.RemainingBytes > 0U)
                {
                    EepDrv_JobParam.JobState = EEPDRV_JOB_STATE_START;
                    EepDrv_JobParam.ProcessState = TRUE;
                }
                break;
            }
            case EEPDRV_JOB_TYPE_WRITE:
            {
                EepDrv_JobParam.ChipAddress += EepDrv_JobParam.ChunkSize;
                EepDrv_JobParam.ClientAddress += EepDrv_JobParam.ChunkSize;
                EepDrv_JobParam.RemainingBytes -= EepDrv_JobParam.ChunkSize;

                //check if still job is pending
                if (EepDrv_JobParam.RemainingBytes > 0U)
                {
                    EepDrv_JobParam.JobState = EEPDRV_JOB_STATE_START;
                    EepDrv_JobParam.ProcessState = TRUE;
                }
                break;
            }
            case EEPDRV_JOB_TYPE_ERASE:
            {
                EepDrv_JobParam.ChipAddress += EepDrv_JobParam.ChunkSize;
                EepDrv_JobParam.ClientAddress += EepDrv_JobParam.ChunkSize;
                EepDrv_JobParam.RemainingBytes -= EepDrv_JobParam.ChunkSize;

                //check if still job is pending
                if (EepDrv_JobParam.RemainingBytes > 0U)
                {
                    EepDrv_JobParam.JobState = EEPDRV_JOB_STATE_START;
                    EepDrv_JobParam.ProcessState = TRUE;
                }
                break;
            }
            case EEPDRV_JOB_TYPE_COMPARE:
            {
                //do comparision for data consistency check
                for (Counter=0; Counter<EepDrv_JobParam.ChunkSize; Counter++)
                {
                    if (EepDrv_Buffer[Counter] != EepDrv_JobParam.ClientAddress[Counter])
                    {
                        /* mismatch, set the job result as MEMIF_BLOCK_INCONSISTENT */
                        EepDrv_JobParam.JobResult = MEMIF_BLOCK_INCONSISTENT;
                        EepDrv_JobParam.JobState = EEPDRV_JOB_STATE_ERROR_NOTIFY;
                        EepDrv_JobParam.ProcessState = TRUE;
                        break;
                    }
                }
                if(EepDrv_JobParam.JobState != EEPDRV_JOB_STATE_ERROR_NOTIFY)
                {
                    EepDrv_JobParam.ChipAddress += EepDrv_JobParam.ChunkSize;
                    EepDrv_JobParam.ClientAddress += EepDrv_JobParam.ChunkSize; //Client Address used for comparision only
                    EepDrv_JobParam.RemainingBytes -= EepDrv_JobParam.ChunkSize;

                    //check if still job is pending
                    if (EepDrv_JobParam.RemainingBytes > 0U)
                    {
                        EepDrv_JobParam.JobState = EEPDRV_JOB_STATE_START;
                        EepDrv_JobParam.ProcessState = TRUE;
                    }
                }

                break;
            }
            default:
            {
                /* todo: Dem handling */
                break;
            }
            }
        }
        EEPDRV_EXIT_CRITICAL_SECTION();

        break;
    }
    case EEPDRV_JOB_STATE_END_NOTIFY:
    {
        EepDrv_JobParam.JobResult = MEMIF_JOB_OK;
        EepDrv_JobParam.JobState  = EEPDRV_JOB_STATE_IDLE;
        EepDrv_JobParam.ProcessState = FALSE;
        EEPDRV_JOB_END_NOTIFICATION();
        break;
    }
    case EEPDRV_JOB_STATE_ERROR_NOTIFY:
    {
        /* Job Result will be updated during failures */
        EepDrv_JobParam.JobState  = EEPDRV_JOB_STATE_IDLE;
        EepDrv_JobParam.ProcessState = FALSE;
        EEPDRV_JOB_ERROR_NOTIFICATION();
        break;
    }
    default:
    {
        //todo: DET implementation for invalid state management
        break;
    }
    }
}


/*============================================================================
**
** Function Name    :   EepDrv_InitInternalParam
**
** Visibility       :   Private
**
** Description      :   Routine to perform Eep Driver variable initializations
**
** Invocation       :   Invoked by EepDrv_Init and Eep Job APIs
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
static void EepDrv_InitInternalParam (void)
{
    MemLib_MemSet(EepDrv_Buffer, 0, (sizeof(Eep_DataType) * EEPDRV_MAX_BUFFER_SIZE));
    MemLib_MemSet(&EepDrv_JobParam, 0, sizeof(EepDrv_JobParamType));
}

#define EEPDRV_CONST_SEC_END
#include "MemMap.h"


#define EEPDRV_CODE_SEC_END
#include "MemMap.h"
#endif /* EepDrv_C endif */
/*============================================================================
**============================================================================
** R E V I S I O N    N O T E S
**============================================================================
**
** For each change to this file, be sure to record:
** 1.  Who made the change and when the change was made.
** 2.  Why the change was made and the intended result.
**
**===========================================================================*/
/*---------------------------------------------------------------------------
Date               : 23-Nov-2015
CDSID              : ssukuma1
Traceability       : RTC #464657 EepDrv - framework for external EEPROM
Change Description : Initial Framework version of EepDrv
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 15-Feb-2016
CDSID              : ssukuma1
Traceability       : RTC #514278 EepDrv - Ea Payload data read error (defect)
Change Description : EepDrv Page Write changes for page boundary management
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 25-Feb-2016
CDSID              : ssukuma1
Traceability       : RTC #531049 PR Defect
Change Description : use a different buffer for address handling.This buffer can
                     be used for Read and Compare operation
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 21-Mar-2017
CDSID              : asivalin
Traceability       : RTC #823813 (EepDrv support for 24xx series I2c based EEPROM)
Change Description : Update the EepDrv to support CAT24C04/24C08/24C16/24C32 EEPROM.
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 09-July-2020
CDSID              : lthanga1
Traceability       : RTC #878613
Change Description : Update the EepDrv to support multiple EEPROM.
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 07-Jun-2022
CDSID              : dbalasub
Traceability       : RTC #1679453
Change Description : 1. Audit Fix
                     2. Coverity & MISRA warning analysis and fix
-----------------------------------------------------------------------------*/
/* end of file =============================================================*/

