/***************************************************************************
 * \copyright
 *       VISTEON CORPORATION CONFIDENTIAL
 *       ________________________________
 *       [2025] Visteon Corporation
 *       All Rights Reserved.
 *       NOTICE: This is an unpublished work of authorship, which contains trade
 *               secrets. Visteon Corporation owns all rights to this work and
 *               intends to maintain it in confidence to preserve its trade
 *               secret status. Visteon Corporation reserves the right, under
 *               the copyright laws of the United States or those of any other
 *               country that may have jurisdiction, to protect this work as an
 *               unpublished work, in the event of an inadvertent or deliberate
 *               unauthorized publication. Visteon Corporation also reserves
 *               its rights under all copyright laws to protect this work as a
 *               published work, when appropriate. Those having access to this
 *               work may not copy it, use it, modify it, or disclose the
 *               information contained in it without the written authorization
 *               of Visteon Corporation.
 *
 * \file Fls.h
 *
 * \brief
 * HSM FLS driver file for AM62PX
 *
 * \version 1.00.00
 * |Version | Date       | Author   | Task Id | Description                           |
 * |--------|------------|----------|---------|---------------------------------------|
 * |1.00.00 |            | kjohn    | xxxxxx  | Initial version                       |
 * \authors
 *          Name                     | CDSID     | Location
 *          ------------------------ | --------- | --------
 *          Akshay Krishna Upendran  | akrish10  | VTSC, Chennai, India
 *          Banumathi Jayaraman      | bjayara2  | VTSC, Chennai, India
 *          krithik B John           | kjohn     | VTSC, Bengaluru, India
 *          Shanmugam Karthik        | kshanmu4  | VTSC, Chennai, India
 ******************************************************************************/

/******************************************************************************
 *  INCLUDES
 *****************************************************************************/
#include "Std_Types.h"
#include "Fls.h"
#include "ospi.h"
#include "trace.h"

#define OSPI_NOR_CMD_WREN                   (0x06U)
#define NOR_SIZE                            (16777216U)
#define NOR_SECTOR_SIZE                     (4096U)
#define NOR_PAGE_SIZE                       (256U)
#define NOR_SECTOR_ERASE_TIMEOUT            (600000U)
#define NOR_WRR_WRITE_TIMEOUT               (600000U)
#define NOR_ERASE_SECTOR_CMD                (0x20)

/**
 *********************************************************************************************
 ** \enum      vHsmFls_StateType
 **
 ** \brief     Internal state of the Fls Driver.
 **
 *********************************************************************************************
 */
typedef enum {
	FLS_WRITE = 0,  /**< Fls write operation */
	FLS_READ = 1,   /**< Fls Read  operation */
	FLS_ERASE = 2,  /**< Fls Erase operation */
    FLS_IDLE = 3,   /**< No Fls operation */
} vHsmFls_StateType;

/**
 *********************************************************************************************
 ** \enum      vHsmFls_EraseState
 **
 ** \brief     Internal state of the Fls Erase Operation.
 **
 *********************************************************************************************
 */
typedef enum{
    ERASE_IDLE = 0,            /**< Erase Idle */
    ERASE_DELAY1 = 1,          /**< Erase wait one */
    ERASE_DELAY2 = 2,          /**< Erase wait two */
    ERASE_DELAY3 = 3,          /**< Erase wait three */
    ERASE_CMD_INVALID = 4,     /**< Erase Invalid CMD send */
    ERASE_CMD_WRITE = 5,       /**< Erase CMD send */
}vHsmFls_EraseState;

/**
 *********************************************************************************************
 ** \struct    vHsmFlsState_st
 **
 ** \brief     Internal Structure for FLS sructure.
 **
 *********************************************************************************************
 */
typedef struct 
{
    vHsmFls_StatusType status;        /**< Fls status */
    uint8 * Buff;                     /**< Input Buffer */
    uint32 Length;                    /**< Input Length */
    uint32 TargetOff;                 /**< Target address offset */
    vHsmFls_StateType JobType;        /**< Job type */
    vHsmFls_EraseState Erasestate;    /**< Erase State */
    uint32 cmdTimeout;                /**< Delay counter for CMD execution */
    uint32 faultcounter;              /**< Fault Counter incase of Error */
}vHsmFlsState_st;

/**< OSPI Handle for the OSPI driver */
OSPI_Handle gOspiHandle;

/**< State of the Fls driver */
static vHsmFlsState_st vHsmFlsDrvState_st;

static Std_ReturnType checkValidAddress(uint32 SourceAddress);
static Std_ReturnType OSPI_norFlashEraseasync(void);
static void vHsmFls_ProcessJob(vHsmFls_StateType Jobreq);
static void vHsmFlsResetDrv(vHsmFlsState_st * flsdrvobj);

/**
 *********************************************************************************************
 ** \fn        vHsmFlsResetDrv
 **
 ** \brief     Resets the Fls Driver State to default.
 **
 ** \details   This function sets up internal variables and prepares
 **            the Fls driver for operation.
 **
 ** \param[in] flsdrvobj pointer to Fls State obj
 **
 ** \return    void
 **
 *********************************************************************************************
 */
static void vHsmFlsResetDrv(vHsmFlsState_st * flsdrvobj)
{
    flsdrvobj->status = vHSMFLS_UNINIT;
    flsdrvobj->Buff = NULL;
    flsdrvobj->Length = 0u;
    flsdrvobj->TargetOff = 0u;
    flsdrvobj->Erasestate = ERASE_IDLE;
    flsdrvobj->JobType = FLS_IDLE;
    flsdrvobj->cmdTimeout = 0u;
    flsdrvobj->faultcounter = 0u;
}

/**
 *********************************************************************************************
 ** \fn        checkValidAddress
 **
 ** \brief     Valid address check.
 **
 ** \details   This function checks the given address is valid or not for NOR Chip.
 **
 ** \param[in] SourceAddress Address to check validity.
 **
 ** \return    void
 **
 *********************************************************************************************
 */
static Std_ReturnType checkValidAddress(uint32 SourceAddress)
{
    Std_ReturnType retVal = E_NOT_OK;
    uint32 startAddr = 0U;
    if(SourceAddress <= (startAddr + NOR_SIZE))
    {
        retVal = E_OK;
    }
    return retVal;
}

/**
 *********************************************************************************************
 ** \copydoc Fls_Init
 *********************************************************************************************
 */
void Fls_Init(void)
{
    int32_t retVal = 1;
    vHsmFlsResetDrv(&vHsmFlsDrvState_st);
    gOspiHandle = OSPI_open(0);
    if(NULL != gOspiHandle)
    {
        retVal = OSPI_norFlashInit1s1s1s(gOspiHandle);
        if(SystemP_SUCCESS == retVal)
        {
            vHsmFlsDrvState_st.status = vHSMFLS_IDLE;
            TRACE_info("\r\n FLS_INIT done");
        }
    }
}

/**
 *********************************************************************************************
 ** \copydoc Fls_Write
 *********************************************************************************************
 */
Std_ReturnType Fls_Write(uint32 flsaddressoff, uint8 * dataPtr, uint32 Length)
{
    Std_ReturnType retVal = E_OK;
    int32_t ospiret = SystemP_SUCCESS;
    if(vHsmFlsDrvState_st.status != vHSMFLS_IDLE)
    {
        retVal = E_NOT_OK;
    }
    else if(NULL == dataPtr)
    {
        retVal = E_NOT_OK;
    }
    else if(((flsaddressoff % NOR_PAGE_SIZE) != 0u)  || (E_NOT_OK == checkValidAddress(flsaddressoff)))
    {
        retVal = E_NOT_OK;
    }
    else if((Length == 0u) || (((flsaddressoff + Length)% NOR_PAGE_SIZE) != 0u) || (E_NOT_OK == checkValidAddress(flsaddressoff + Length)))
    {
        retVal = E_NOT_OK;
    }
    else
    {
        ospiret = OSPI_norFlashWrite(gOspiHandle,flsaddressoff,dataPtr,Length); /*sync wr*/
        if(SystemP_SUCCESS != ospiret)
        {
            retVal = E_NOT_OK;
        }
    }
    return retVal;
}

/**
 *********************************************************************************************
 ** \copydoc Fls_Erase
 *********************************************************************************************
 */
Std_ReturnType Fls_Erase(uint32 flsaddressoff,uint32 Length)
{
    Std_ReturnType retVal = E_OK;
#ifdef CONFIG_ERASESYNC
    int32_t ospiret = SystemP_SUCCESS;
#endif
    if(vHsmFlsDrvState_st.status != vHSMFLS_IDLE)
    {
        retVal = E_NOT_OK;
    }
    else if(((flsaddressoff % NOR_PAGE_SIZE) != 0u)  || (E_NOT_OK == checkValidAddress(flsaddressoff)))
    {
        retVal = E_NOT_OK;
    }
    else if((Length == 0u) || (((flsaddressoff + Length)% NOR_PAGE_SIZE) != 0u) || (E_NOT_OK == checkValidAddress(flsaddressoff + Length)))
    {
        retVal = E_NOT_OK;
    }
    else
    {
#ifndef CONFIG_ERASESYNC
        vHsmFlsDrvState_st.status = vHSMFLS_BUSY;
        vHsmFlsDrvState_st.Buff = NULL;
        vHsmFlsDrvState_st.Length = Length;
        vHsmFlsDrvState_st.JobType = FLS_ERASE;
        vHsmFlsDrvState_st.TargetOff = flsaddressoff;
#else
        ospiret = OSPI_norFlashErase(gOspiHandle,flsaddressoff);  /*sync wr*/
        if(SystemP_SUCCESS != ospiret)
        {
            retVal = E_NOT_OK;
        }
#endif
    }
    return retVal;
}

/**
 *********************************************************************************************
 ** \copydoc Fls_Read
 *********************************************************************************************
 */
Std_ReturnType Fls_Read(uint32 flsaddressoff, uint8 * dataPtr, uint32 Length)
{
    Std_ReturnType retVal = E_OK;
    int32_t ospiret = SystemP_SUCCESS;
    if(vHsmFlsDrvState_st.status != vHSMFLS_IDLE)
    {
        
        retVal = E_NOT_OK;
    }
    else if(NULL == dataPtr)
    {
        retVal = E_NOT_OK;
    }
    else if((E_NOT_OK == checkValidAddress(flsaddressoff)))
    {
        retVal = E_NOT_OK;
    }
    else if((Length > NOR_SECTOR_SIZE) || (Length == 0u) || (E_NOT_OK == checkValidAddress(flsaddressoff + Length)))
    {
        retVal = E_NOT_OK;
    }
    else
    {
        ospiret = OSPI_norFlashRead(gOspiHandle,flsaddressoff,dataPtr,Length);
        if(SystemP_SUCCESS != ospiret)
        {
            retVal = E_NOT_OK;
        }
    }
    return retVal;
}

#ifndef CONFIG_ERASESYNC
/**
 *********************************************************************************************
 ** \fn        OSPI_norFlashEraseasync
 **
 ** \brief     Performs Async Erase.
 **
 ** \details   This function performs async erase of a sector in given NOR chip.
 **
 ** \param[in] void 
 **
 ** \return    Std_ReturnType
 **            E_OK      - Read job accepted.
 **            E_NOT_OK  - Read job failed.
 **
 *********************************************************************************************
 */
static Std_ReturnType OSPI_norFlashEraseasync(void)
{
    Std_ReturnType retVal = E_NOT_OK;
    int32_t asynretval = SystemP_SUCCESS;
    switch (vHsmFlsDrvState_st.Erasestate)
    {
    case ERASE_DELAY1:
        asynretval = OSPI_norFlashWaitReadyAsync(gOspiHandle,vHsmFlsDrvState_st.cmdTimeout);
        if(SystemP_SUCCESS == asynretval)
        {
            retVal = E_OK;
            vHsmFlsDrvState_st.Erasestate = ERASE_CMD_INVALID;
        }
        else
        {
            retVal = E_NOT_OK;
            vHsmFlsDrvState_st.Erasestate = ERASE_IDLE;
        }
        break;
    case ERASE_CMD_INVALID:
        asynretval = OSPI_norFlashCmdWrite(gOspiHandle, OSPI_NOR_CMD_WREN, 0xFFFFFFFFU, NULL, 0);
        if(SystemP_SUCCESS == asynretval)
        {
            retVal = E_OK;
            vHsmFlsDrvState_st.cmdTimeout = NOR_WRR_WRITE_TIMEOUT;
            vHsmFlsDrvState_st.Erasestate = ERASE_DELAY2;
        }
        else
        {
            retVal = E_NOT_OK;
            vHsmFlsDrvState_st.Erasestate = ERASE_IDLE;
        }
        break;
    case ERASE_DELAY2:
        asynretval = OSPI_norFlashWaitReadyAsync(gOspiHandle,vHsmFlsDrvState_st.cmdTimeout);
        if(SystemP_SUCCESS == asynretval)
        {
            retVal = E_OK;
            vHsmFlsDrvState_st.Erasestate = ERASE_CMD_WRITE;
        }
        else
        {
            retVal = E_NOT_OK;
            vHsmFlsDrvState_st.Erasestate = ERASE_IDLE;
        }
        break;
    case ERASE_CMD_WRITE:
        asynretval = OSPI_norFlashCmdWrite(gOspiHandle, NOR_ERASE_SECTOR_CMD, vHsmFlsDrvState_st.TargetOff, NULL, 0);
        if(SystemP_SUCCESS == asynretval)
        {
            retVal = E_OK;
            vHsmFlsDrvState_st.cmdTimeout = NOR_WRR_WRITE_TIMEOUT;
            vHsmFlsDrvState_st.Erasestate = ERASE_DELAY3;
        }
        else
        {
            retVal = E_NOT_OK;
            vHsmFlsDrvState_st.Erasestate = ERASE_IDLE;
        }
        break;
    case ERASE_DELAY3:
        asynretval = OSPI_norFlashWaitReadyAsync(gOspiHandle,vHsmFlsDrvState_st.cmdTimeout);
        if(SystemP_SUCCESS == asynretval)
        {
            retVal = E_OK;
            vHsmFlsDrvState_st.Erasestate = ERASE_IDLE;
        }
        else
        {
            retVal = E_NOT_OK;
            vHsmFlsDrvState_st.Erasestate = ERASE_IDLE;
        }
        break;
    default:
        break;
    }
    return retVal;
}

/**
 *********************************************************************************************
 ** \fn        vHsmFls_ProcessJob
 **
 ** \brief     Performs Async Erase.
 **
 ** \details   This function performs async erase of a sector in given NOR chip.
 **
 ** \param[in] Jobreq current process job state
 **
 ** \return    void 
 **
 *********************************************************************************************
 */
static void vHsmFls_ProcessJob(vHsmFls_StateType Jobreq)
{
    Std_ReturnType retVal = E_NOT_OK;
    switch (Jobreq)
    {
    case FLS_ERASE:
        if(vHsmFlsDrvState_st.Erasestate == ERASE_IDLE)
        {
            vHsmFlsDrvState_st.Erasestate = ERASE_DELAY1;
            vHsmFlsDrvState_st.cmdTimeout = NOR_SECTOR_ERASE_TIMEOUT;
        }
        retVal = OSPI_norFlashEraseasync();
        break;
    default:
        break;
    }
    if((Jobreq == FLS_ERASE) && (vHsmFlsDrvState_st.Erasestate == ERASE_IDLE))
    {
        if(E_OK != retVal)
        {
            vHsmFlsDrvState_st.faultcounter++; /*log fault-- fault hadnling in future*/
        }
        vHsmFlsDrvState_st.JobType = FLS_IDLE;
        vHsmFlsDrvState_st.status = vHSMFLS_IDLE;
        vHsmFlsDrvState_st.TargetOff = 0u;
        vHsmFlsDrvState_st.Length = 0u;
    }
}
#endif

/**
 *********************************************************************************************
 ** \copydoc Fls_GetStatus
 *********************************************************************************************
 */
vHsmFls_StatusType Fls_GetStatus(void)
{
    return (vHsmFlsDrvState_st.status);
}

/**
 *********************************************************************************************
 ** \copydoc Fls_MainFunction
 *********************************************************************************************
 */
void Fls_MainFunction(void)
{
    switch (vHsmFlsDrvState_st.JobType)
    {
#ifndef CONFIG_ERASESYNC
    case FLS_ERASE:  /*only Erase configured as async*/
        vHsmFls_ProcessJob(FLS_ERASE);
        break;
#endif    
    default:
        break;
    }
}
/*EOF*/
