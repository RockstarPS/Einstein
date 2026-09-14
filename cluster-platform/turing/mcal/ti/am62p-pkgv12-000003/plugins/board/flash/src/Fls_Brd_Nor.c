/*
*
* Copyright (C) 2024 Texas Instruments Incorporated
*
* All rights reserved not granted herein.
*
* Limited License.
*
* Texas Instruments Incorporated grants a world-wide, royalty-free, non-exclusive
* license under copyrights and patents it now or hereafter owns or controls to make,
* have made, use, import, offer to sell and sell ("Utilize") this software subject to the
* terms herein.  With respect to the foregoing patent license, such license is granted
* solely to the extent that any such patent is necessary to Utilize the software alone.
* The patent license shall not apply to any combinations which include this software,
* other than combinations with devices manufactured by or for TI ("TI Devices").
* No hardware patent is licensed hereunder.
*
* Redistributions must preserve existing copyright notices and reproduce this license
* (including the above copyright notice and the disclaimer and (if applicable) source
* code license limitations below) in the documentation and/or other materials provided
* with the distribution
*
* Redistribution and use in binary form, without modification, are permitted provided
* that the following conditions are met:
*
* *       No reverse engineering, decompilation, or disassembly of this software is
* permitted with respect to any software provided in binary form.
*
* *       any redistribution and use are licensed by TI for use only with TI Devices.
*
* *       Nothing shall obligate TI to provide you with source code for the software
* licensed and provided to you in object code.
*
* If software source code is provided to you, modification and redistribution of the
* source code are permitted provided that the following conditions are met:
*
* *       any redistribution and use of the source code, including any resulting derivative
* works, are licensed by TI for use only with TI Devices.
*
* *       any redistribution and use of any object code compiled from the source code
* and any resulting derivative works, are licensed by TI for use only with TI Devices.
*
* Neither the name of Texas Instruments Incorporated nor the names of its suppliers
*
* may be used to endorse or promote products derived from this software without
* specific prior written permission.
*
* DISCLAIMER.
*
* THIS SOFTWARE IS PROVIDED BY TI AND TI'S LICENSORS "AS IS" AND ANY EXPRESS
* OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
* OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL TI AND TI'S LICENSORS BE LIABLE FOR ANY DIRECT, INDIRECT,
* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
* DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
* OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
* OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
* OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/
/**
 *  \file     Fls_Brd_Nor.c
 *
 *  \brief    This file contains FLS MCAL driver internal functions for Board Nor OSPI
 *
 */
/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "Fls_Cfg.h"
#include "Fls.h"
#include "Std_Types.h"
#include "string.h"
#include "Fee_Cbk.h"
#include <hw_include/soc.h>
#include <hw_include/hw_types.h>
#if defined (FLS_NOR)
#include "Fls_Brd_Nor.h"
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */
static Std_ReturnType Fls_norRead(uint32 actualChunkSize);
static Std_ReturnType Fls_norWrite(uint32 actualChunkSize);
static Std_ReturnType Fls_norCompare(uint32 actualChunkSize);
static Std_ReturnType Fls_norBlankCheck(uint32 actualChunkSize);
static Std_ReturnType Fls_norValidateAddress(uint32 actualChunkSize);
static Std_ReturnType Fls_norAsyncErase(uint32 actualChunkSize);


/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
/*Initial erase stage*/
volatile VAR(uint8, FLS_VAR_INIT) FlsEraseStage = FLS_S_DEFAULT;
boolean gPhyEnable;
boolean gDtrEnable;

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"

/*
 * Design : MCAL-7289
 */
Std_ReturnType Fls_hwUnitInit(void)
{
    Std_ReturnType retVal;
    SPI_Handle handle = NULL;

    (void)Fls_OSPI_init(((SPI_Handle)&(SPI_config[0])));

    handle = (SPI_Handle)&(SPI_config[0]);

    if (handle != NULL)
    {
        Fls_DrvObj.spiHandle = handle;
        retVal = Fls_norOpen();
    }
    else
    {
        retVal = E_NOT_OK; /*Handle is NULL */
    }
    return retVal;
}

static sint32 Flash_norSetRdDataCaptureDelay(SPI_Handle handle)
{
    Std_ReturnType retVal;
    uint32 maxReadDataCapDelay = 0U, minReadDataCapDelay = 0U;

    /* Set RD Capture Delay by reading ID */
    uint32 readDataCapDelay = 15U;

    while(readDataCapDelay > 0U)
    {
        CSL_ospiSetDataReadCapDelay((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR),
                                         readDataCapDelay);
        retVal = Nor_ReadId(handle);  // Using Nor_ReadId instead of Nor_xspiReadId
        if(retVal == E_OK)
        {
            if(maxReadDataCapDelay == 0U)
            {
                maxReadDataCapDelay = readDataCapDelay;
            }
            minReadDataCapDelay = readDataCapDelay;
        }
        readDataCapDelay--;
    }

    if(maxReadDataCapDelay == 0U)
    {
        retVal = E_NOT_OK;
    }
    else
    {
        /* Picking the middle value from a region of passing read data capture delay */
        readDataCapDelay = (minReadDataCapDelay + maxReadDataCapDelay) / 2U;
        CSL_ospiSetDataReadCapDelay((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR),
                                         readDataCapDelay);
        retVal = E_OK;
    }

    return retVal;
}

static sint32 Flash_SetRdDataCaptureDelay(SPI_Handle handle, uint8 protocol)
{
    Std_ReturnType retVal;
    uint32 maxReadDataCapDelay = 0U, minReadDataCapDelay = 0U;
    uint32 readDataCapDelay = 15U;

    while(readDataCapDelay > 0U)
    {
        CSL_ospiSetDataReadCapDelay((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR),
                                         readDataCapDelay);
        
        /* Call appropriate ReadId based on protocol */
        if(protocol == (uint8)FLS_XSPI)
        {
            retVal = Nor_xspiReadId(handle);
        }
        else if(protocol == (uint8)FLS_OSPI)
        {
            retVal = Nor_ospiReadId(handle);
        }
        else if(protocol == (uint8)FLS_QSPI)
        {
            retVal = Nor_qspiReadId(handle);
        }
        else
        {
            retVal = E_NOT_OK;
        }
        
        if(retVal == E_OK)
        {
            if(maxReadDataCapDelay == 0U)
            {
                maxReadDataCapDelay = readDataCapDelay;
            }
            minReadDataCapDelay = readDataCapDelay;
        }
        readDataCapDelay--;
    }

    if(maxReadDataCapDelay == 0U)
    {
        retVal = E_NOT_OK;
    }
    else
    {
        /* Picking the middle value from a region of passing read data capture delay */
        readDataCapDelay = (minReadDataCapDelay + maxReadDataCapDelay) / 2U;
        CSL_ospiSetDataReadCapDelay((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR),
                                         readDataCapDelay);
        retVal = E_OK;
    }

    return retVal;
}

/**
 *  \Function Name: Fls_norValidateAddress
 *
 *  This function Perform Address validation operation.
 *  Write function is divided into multiple functions to avoid klocwork warnings
 *
 */
static Std_ReturnType Fls_norValidateAddress(uint32 actualChunkSize)
{
    Std_ReturnType retVal = (Std_ReturnType) E_OK;
    uint32 offset = Fls_DrvObj.flashAddr;
    uint32 sectorSize;
    uint32 sectorPageSize;
    uint32 numberOfSectors;
    uint32 sectorstartaddress;
    uint32 block;
    uint32 sectorcfg_index = 0;
    boolean valid_address = FALSE;
    uint8 flashIdx = Fls_DrvObj.Fls_flashIndex;
    const FlashConfig *flsNorDevicePtr = &FlsNorDevice.flscfg[flashIdx];

    do
    {
        sectorSize = Fls_DrvObj.sectorList[sectorcfg_index].sectorSize;
        sectorPageSize = Fls_DrvObj.sectorList[sectorcfg_index].sectorPageSize;
        numberOfSectors = Fls_DrvObj.sectorList[sectorcfg_index].numberOfSectors;
        sectorstartaddress = Fls_DrvObj.sectorList[sectorcfg_index].sectorStartaddress;
        block = sectorSize/sectorPageSize;

    /* Validate address input 
           Note: The 'OR' condition is put to skip page allignment check for Reading */

		
        if (
            (offset >= sectorstartaddress) &&
            (( offset + actualChunkSize) <= (sectorstartaddress + (numberOfSectors*block*sectorPageSize))) && 
			((Fls_DrvObj.jobType == FLS_JOB_READ) ||
            ((uint32)(offset % flsNorDevicePtr->NOR_PAGE_SIZE) == 0U))
           )
        {
            valid_address = TRUE;
        }

        sectorcfg_index++;
    }while(sectorcfg_index < FLS_NUMBER_OF_SECTOR_CFG);
    
    if(valid_address == FALSE)
    {
        retVal = E_NOT_OK;
    }
    return retVal;

}

/*
 * Design : MCAL-7436,MCAL-4341,MCAL-7436,MCAL-7292,MCAL-7325,MCAL-7296
 */
static Std_ReturnType Fls_norRead(uint32 actualChunkSize)
{
    SPI_Handle handle;
    uint32 addr     = Fls_DrvObj.flashAddr;
    uint8 *buf      = Fls_DrvObj.ramAddr;
    boolean ret;
    uint32 transferType = (uint32)SPI_TRANSACTION_TYPE_READ;
    handle          = Fls_DrvObj.spiHandle;
    Std_ReturnType retVal = E_OK;
    SPI_Transaction transaction;
    uint8 flashIdx = Fls_DrvObj.Fls_flashIndex;
    const FlashConfig *flsNorDevicePtr = &FlsNorDevice.flscfg[flashIdx];

    if (handle != NULL)
    {

        retVal = Fls_norValidateAddress(actualChunkSize);
        if((flsNorDevicePtr->FLS_PROTOCOL == FLS_XSPI) || (flsNorDevicePtr->FLS_PROTOCOL == FLS_OSPI))
        {
            if ((gPhyEnable == TRUE) && (tuneDone == FALSE))
            {
            #if defined (SOC_J721E) || defined (SOC_J7200) || defined (SOC_J721S2) || defined (SOC_J784S4) || defined (SOC_J742S2)
                retVal = Nor_spiPhyTune(handle, NOR_TUNING_DATA_OFFSET);
            #endif
                tuneDone = TRUE;
            }
        }

        if (E_OK == retVal)
        {
            /* Set transfer mode and read type */
            if (E_OK == OSPI_control(handle, SPI_V0_CMD_SET_XFER_MODE, NULL))
            {
                if (E_OK == OSPI_control(handle, SPI_V0_CMD_XFER_MODE_RW, (void *)&transferType))
                {
                    retVal = E_OK;
                }
                else
                {
                    retVal = E_NOT_OK;
                }
            }
            else
            {
                retVal = E_NOT_OK;
            }

            if (E_OK == retVal)
            {
                transaction.arg   = (void *)(uint32)addr;
                transaction.txBuf = NULL;
                transaction.rxBuf = (void *)buf;
                transaction.count = actualChunkSize;

                ret = OSPI_transfer(handle, &transaction);
                if (ret != TRUE)
                {
                    retVal = E_NOT_OK; /*HW error occured*/
                }
            }
        }
        else
        {
            retVal = E_NOT_OK; /*Nor_spiPhyTune Failed */
        }
    }
    else
    {
        retVal = E_NOT_OK; /*Handle is NULL*/
    }
    return retVal;
}
/*
 * Design : MCAL-7303,MCAL-7315
 */
static Std_ReturnType Fls_norWrite(uint32 actualChunkSize)
{
    SPI_Handle       handle;
    uint32 addr = Fls_DrvObj.flashAddr;
    uint32 len = actualChunkSize;
    uint8 *buf = Fls_DrvObj.ramAddr;
    boolean        ret;
    uint32         byteAddr;
    uint32         wrSize = len ;
    uint32         chunkLen;
    uint32         actual;
    uint32         transferType = (uint32)SPI_TRANSACTION_TYPE_WRITE;
	Std_ReturnType retVal = E_OK;
    uint32         pageSize;
    SPI_Transaction transaction;
    uint8 flashIdx = Fls_DrvObj.Fls_flashIndex;
    const FlashConfig *flsNorDevicePtr = &FlsNorDevice.flscfg[flashIdx];  

	handle = Fls_DrvObj.spiHandle;

    if(handle != NULL)
    {
        pageSize = Fls_DrvObj.sectorList[Fls_DrvObj.currentSectorIndex].sectorPageSize;

        retVal = Fls_norValidateAddress(actualChunkSize);
        if (E_OK == retVal)
        {
            if (Fls_DrvObj.dacEnable == FALSE)
            {
                /* indirect access transfer mode */
                if(actualChunkSize > 256U)
				{
					wrSize = pageSize; /*if len > 256 wrSize will be page size of flash device.*/
				}
            }

            byteAddr = addr & (wrSize - 1U);
            actual = 0U;
            while (actual < len)
            {
                if (E_OK == retVal)
                {

                    if(flsNorDevicePtr->FLS_PROTOCOL == FLS_XSPI)
                    {
                        uint8          cmdWren[2];
                        cmdWren[0] = flsNorDevicePtr->NOR_CMD_WREN;
                        if ((Std_ReturnType)E_NOT_OK == Nor_xspiCmdWrite(handle, cmdWren, 1, 0))
                        {
                            retVal = E_NOT_OK;
                        }

                        if ((Std_ReturnType)E_NOT_OK == Nor_xspiWaitReady(handle, flsNorDevicePtr->NOR_WRR_WRITE_TIMEOUT))
                        {
                            retVal = E_NOT_OK;
                        }
                    }

                    if(retVal == E_OK)
                    {
                        /* Send Page Program command */
                        chunkLen = (((len - actual) < (wrSize - byteAddr)) ?
                                    (len - actual) : (wrSize - byteAddr));

                        transaction.arg   = (void *)(uint32)addr;
                        transaction.txBuf = (void *)(buf + actual);
                        transaction.rxBuf = NULL;
                        transaction.count = chunkLen;
                        /* Set the transfer mode, write op code and tx lines */
                        if (E_OK == OSPI_control(handle, SPI_V0_CMD_SET_XFER_MODE, NULL))
                        {
                            if (E_OK == OSPI_control(handle, SPI_V0_CMD_XFER_MODE_RW, (void *)&transferType))
                            {
                                retVal = E_OK;
                            }
                            else
                            {
                                retVal = E_NOT_OK;
                            }
                        }
                        else
                        {
                            retVal = E_NOT_OK;
                        }
                        ret = OSPI_transfer(handle, &transaction);
                        if (ret == TRUE)
                        {
                            addr += chunkLen;
                            byteAddr = 0U;
                            actual += chunkLen;
                            retVal = E_OK;
                        }
                        else
                        {
                            retVal = E_NOT_OK;
                        }
                        if ((flsNorDevicePtr->FLS_PROTOCOL == FLS_XSPI) && (STD_OFF == FLS_USE_INTERRUPTS))
                        {
                            /* Wait till the write operation completes */
                            if (Nor_xspiWaitReady(handle, flsNorDevicePtr->NOR_PAGE_PROG_TIMEOUT) == E_NOT_OK)
                            {
                                retVal = E_NOT_OK;
                            }
                        }
                    }
                }
                else
                {
                    retVal = E_NOT_OK;
                    break; /*error occured while writing, exit loop */
                }
            }
        }
        else
        {
            retVal = E_NOT_OK;
        }
    }
    else
    {
        retVal = E_NOT_OK; /*handle is NULL */
    }

    return retVal;
}

/*
 * Design : MCAL-15384
 * Each call only completes one stage instead of all 5 (wait, cmdWrite, wait, CmdWrite, wait)
 */
static Std_ReturnType Fls_norAsyncErase(uint32 actualChunkSize)
{
	uint32          cmdLen;
	uint32          address = 0;
	SPI_Handle      handle;
	uint32          sector;
    uint32          page;
	uint32          leftover, page_size, page_count;
	Std_ReturnType retVal = E_OK;
    handle = Fls_DrvObj.spiHandle;
    uint8 flashIdx = Fls_DrvObj.Fls_flashIndex;
    const FlashConfig *flsNorDevicePtr = &FlsNorDevice.flscfg[flashIdx];

    Fls_InternalStateType   waitStatus;
    Std_ReturnType          writeStatus;
    
    sector = Fls_DrvObj.flashAddr / (Fls_DrvObj.sectorList[Fls_DrvObj.currentSectorIndex].sectorSize);
    if (handle != NULL)
    {
        /*Calculate sector number based on flashAddr, erase one sector at a time*/
        page_size       = Fls_DrvObj.sectorList[Fls_DrvObj.currentSectorIndex].sectorPageSize;
        page_count  	= flsNorDevicePtr->NOR_NUM_PAGES_PER_BLOCK;
        leftover        = Fls_DrvObj.flashAddr % (Fls_DrvObj.sectorList[Fls_DrvObj.currentSectorIndex].sectorSize);
        page 	        = leftover / page_size;

        if ((((leftover % page_size)!=0U)) ||
            (page > page_count))
        {
            retVal = E_NOT_OK;
        }

        if (E_OK == retVal)
        {
            address   = sector * Fls_DrvObj.sectorList[Fls_DrvObj.currentSectorIndex].sectorSize;

        switch (FlsEraseStage)
            {
                case FLS_S_DELAY_0_STAGE:
                {
                    if(flsNorDevicePtr->FLS_PROTOCOL == FLS_XSPI)
                    {
                        waitStatus = Nor_xspiAsyncWaitReady(handle, flsNorDevicePtr->NOR_WRR_WRITE_TIMEOUT);
                        if (waitStatus == FLS_INTERNAL_JOB_DONE)
                        {
                            retVal = E_OK;
                            FlsEraseStage = FLS_S_INVALID_ADDRESS;
                        }
                        else if (waitStatus == FLS_INTERNAL_JOB_FAIL)
                        {
                            retVal = E_NOT_OK;
                            FlsEraseStage = FLS_S_DEFAULT;
                        }
                        else
                        {
                            /*Do Nothing*/
                        }
                    }
                    break;
                }
                case FLS_S_INVALID_ADDRESS:
                {
                    if(flsNorDevicePtr->FLS_PROTOCOL == FLS_OSPI)
                    {
                        uint8 cmdWren  = flsNorDevicePtr->NOR_CMD_WREN;
                        writeStatus = Nor_ospiCmdWrite(handle, &cmdWren, 1, 0);
                    }
                    else if(flsNorDevicePtr->FLS_PROTOCOL == FLS_XSPI)
                    {
                        uint8 cmdWren[2];
                        cmdWren[0]  = flsNorDevicePtr->NOR_CMD_WREN;
                        writeStatus = Nor_xspiCmdWrite(handle, cmdWren, 1, 0);
                    }
                    else /*if(flsNorDevicePtr->FLS_PROTOCOL == FLS_QSPI) */
                    {
                        uint8 cmdWren  = flsNorDevicePtr->NOR_CMD_WREN;
                        writeStatus = Nor_qspiCmdWrite(handle, &cmdWren, 1, 0);
                    }

                    if (writeStatus == E_OK)
                    {
                        retVal = E_OK;
                        FlsEraseStage = FLS_S_DELAY_1_STAGE;
                        Fls_DrvObj.timeOutVal = flsNorDevicePtr->NOR_WRR_WRITE_TIMEOUT;
                    }
                    else
                    {
                        retVal = E_NOT_OK;
                        FlsEraseStage = FLS_S_DEFAULT;
                    }
                    break;
                }
                case FLS_S_DELAY_1_STAGE:
                {
                    if(flsNorDevicePtr->FLS_PROTOCOL == FLS_OSPI)
                    {
                        waitStatus = Nor_ospiAsyncWaitReady(handle, flsNorDevicePtr->NOR_WRR_WRITE_TIMEOUT);
                    }
                    else if(flsNorDevicePtr->FLS_PROTOCOL == FLS_XSPI)
                    {
                        waitStatus = Nor_xspiAsyncWaitReady(handle, flsNorDevicePtr->NOR_WRR_WRITE_TIMEOUT);
                    }
                    else /* if(flsNorDevicePtr->FLS_PROTOCOL == FLS_QSPI) */
                    {
                        waitStatus = Nor_qspiAsyncWaitReady(handle, flsNorDevicePtr->NOR_WRR_WRITE_TIMEOUT);
                    }
                    if (waitStatus == FLS_INTERNAL_JOB_DONE)
                    {
                        retVal = E_OK;
                        FlsEraseStage = FLS_S_CMD_STAGE;
                    }
                    else if (waitStatus == FLS_INTERNAL_JOB_FAIL)
                    {
                        retVal = E_NOT_OK;
                        FlsEraseStage = FLS_S_DEFAULT;
                    }
                    else
                    {
                        /* Do Nothing. */
                    }
                    break;
                }
                case FLS_S_CMD_STAGE:
                {
                    if(flsNorDevicePtr->FLS_PROTOCOL == FLS_XSPI)
                    {
                        uint8 cmdxspi[10];
                        cmdxspi[0] = flsNorDevicePtr->NOR_CMD_BLOCK_ERASE;
                        cmdxspi[1] = (uint8)(address >> 24U) & 0xffU; /* 4 address bytes */
                        cmdxspi[2] = (uint8)(address >> 16U) & 0xffU;
                        cmdxspi[3] = (uint8)(address >>  8U) & 0xffU;
                        cmdxspi[4] = (uint8)(address >>  0U) & 0xffU;
                        cmdLen = 5U;
                        writeStatus = Nor_xspiCmdWrite(handle, cmdxspi, cmdLen, 0);
                    }
                    else
                    {
                        uint8           cmd[5];
                        cmd[0] = flsNorDevicePtr->NOR_CMD_SECTOR_ERASE;
                        if (gDtrEnable == TRUE)
                        {
                            cmd[1] = (uint8)(address >> 24U) & 0xffU; /* 4 address bytes */
                            cmd[2] = (uint8)(address >> 16U) & 0xffU;
                            cmd[3] = (uint8)(address >>  8U) & 0xffU;
                            cmd[4] = (uint8)(address >>  0U) & 0xffU;
                            cmdLen = 5U;
                        }
                        else /* SDR MODE*/
                        {
                            if (flsNorDevicePtr->FOUR_BYTE_ADDR_ENABLE == 1U)
                            {
                                cmd[1] = (uint8)(address >> 24U) & 0xffU; /* 4 address bytes */
                                cmd[2] = (uint8)(address >> 16U) & 0xffU;
                                cmd[3] = (uint8)(address >>  8U) & 0xffU;
                                cmd[4] = (uint8)(address >>  0U) & 0xffU;
                                cmdLen = 5U;
                            }
                            else
                            {
                                cmd[1] = (uint8)(address >> 16U) & 0xffU; /* 3 address bytes */
                                cmd[2] = (uint8)(address >>  8U) & 0xffU;
                                cmd[3] = (uint8)(address >>  0U) & 0xffU;
                                cmdLen = 4U;
                            }
                        }
                        if(flsNorDevicePtr->FLS_PROTOCOL == FLS_OSPI)
                        {
                            writeStatus = Nor_ospiCmdWrite(handle, cmd, cmdLen, 0);
                        }
                        else /*if(flsNorDevicePtr->FLS_PROTOCOL == FLS_QSPI) */
                        {
                            writeStatus = Nor_qspiCmdWrite(handle, cmd, cmdLen, 0);
                        }
                    }
                    
                    if (writeStatus == E_OK)
                    {
                        retVal = E_OK;
                        FlsEraseStage = FLS_S_DELAY_2_STAGE;
                        Fls_DrvObj.timeOutVal = flsNorDevicePtr->NOR_BULK_ERASE_TIMEOUT;
                    }
                    else
                    {
                        retVal = E_NOT_OK;
                        FlsEraseStage = FLS_S_DEFAULT;
                    }
                    break;
                }
                case FLS_S_DELAY_2_STAGE:
                default:
                {
                    if(flsNorDevicePtr->FLS_PROTOCOL == FLS_OSPI)
                    {
                        waitStatus = Nor_ospiAsyncWaitReady(handle, flsNorDevicePtr->NOR_BULK_ERASE_TIMEOUT);
                    }
                    else if(flsNorDevicePtr->FLS_PROTOCOL == FLS_XSPI)
                    {
                        waitStatus = Nor_xspiAsyncWaitReady(handle, flsNorDevicePtr->NOR_BULK_ERASE_TIMEOUT);
                    }
                    else /* if(flsNorDevicePtr->FLS_PROTOCOL == FLS_QSPI) */
                    {
                        waitStatus = Nor_qspiAsyncWaitReady(handle, flsNorDevicePtr->NOR_WRR_WRITE_TIMEOUT);
                    }
                    
                    if (waitStatus == FLS_INTERNAL_JOB_DONE)
                    {
                        retVal = E_OK;
                        FlsEraseStage = FLS_S_DEFAULT;
                    }
                    else if (waitStatus == FLS_INTERNAL_JOB_FAIL)
                    {
                        retVal = E_NOT_OK;
                        FlsEraseStage = FLS_S_DEFAULT;
                    }
                    else
                    {
                        /* Do Nothing */
                    }
                    break;
                }
            }        
        }
    }
    else
    {
        retVal = E_NOT_OK;
    }

    if ((retVal == E_NOT_OK) || (FlsEraseStage == FLS_S_DEFAULT))
    {
        Fls_DrvObj.flashAddr = (sector + 1U) * Fls_DrvObj.sectorList[Fls_DrvObj.currentSectorIndex].sectorSize;
    }

    return retVal;
}

/*
 * Design : MCAL-7406,MCAL-7281
 */
static Std_ReturnType Fls_norCompare(uint32 actualChunkSize)
{
    SPI_Handle handle;
    uint32 addr             = Fls_DrvObj.flashAddr;
    uint8 readData_buf[FLS_READ_WRITE_BUF_LEN];
    uint8 *expData_Buf      = Fls_DrvObj.ramAddr;
    boolean  ret;
    uint32 transferType     = (uint32) SPI_TRANSACTION_TYPE_READ;
    Std_ReturnType retVal;
    SPI_Transaction transaction;

    handle = Fls_DrvObj.spiHandle;

    if (handle != NULL)
    {
        /* Set transfer mode and read type */
        if (E_OK == OSPI_control(handle, SPI_V0_CMD_SET_XFER_MODE, NULL))
        {
            if (E_OK == OSPI_control(handle, SPI_V0_CMD_XFER_MODE_RW, (void *)&transferType))
            {
                retVal = E_OK;
            }
            else
            {
                retVal = E_NOT_OK;
            }
        }
        else
        {
            retVal = E_NOT_OK;
        }

        if(E_OK == retVal)
        {
            transaction.arg   = (void *)(uint32)addr;
            transaction.txBuf = NULL;
            transaction.rxBuf = (void *)readData_buf;
            transaction.count = actualChunkSize;

            ret = OSPI_transfer(handle, &transaction);
            if (TRUE == ret)
            {
                if (Fls_VerifyData_priv(expData_Buf, (const uint8*)transaction.rxBuf, actualChunkSize) == TRUE)
                {
                    retVal = E_OK;
                }
                else
                {
                    retVal = E_COMPARE_MISMATCH;
                }
            }
            else
            {
                retVal = E_NOT_OK;
            }

            transaction.rxBuf = NULL;
        }
    }
    else
    {
        retVal = E_NOT_OK; /* Handle is NULL*/
    }
    return retVal;
};

/*
 * Design : MCAL-7279,MCAL-7437,MCAL-7310,MCAL-7419
 */
static Std_ReturnType Fls_norBlankCheck(uint32 actualChunkSize)
{
    SPI_Handle handle;
    uint32 addr             = Fls_DrvObj.flashAddr;
    boolean  ret;
    uint32         transferType = (uint32)SPI_TRANSACTION_TYPE_READ;
    Std_ReturnType retVal;
    SPI_Transaction transaction;
    uint8 flashIdx = Fls_DrvObj.Fls_flashIndex;
    const FlashConfig *flsNorDevicePtr = &FlsNorDevice.flscfg[flashIdx];

    handle = Fls_DrvObj.spiHandle;

    if (handle != NULL)
    {
        uint8 expData_Buf[FLS_ERASE_BUF_LEN];
        uint8 readData_buf[FLS_ERASE_BUF_LEN];

        uint32 idx;
        volatile uint8 *expData_ptr = expData_Buf;

        for(idx = 0; idx < actualChunkSize; idx++)
        {
            *expData_ptr = flsNorDevicePtr->NOR_ERASED_DATA;
            expData_ptr++;
        }

        /* Set transfer mode and read type */
        if (E_OK == OSPI_control(handle, SPI_V0_CMD_SET_XFER_MODE, NULL))
        {
            if (E_OK == OSPI_control(handle, SPI_V0_CMD_XFER_MODE_RW, (void *)&transferType))
            {
                retVal = E_OK;
            }
            else
            {
                retVal = E_NOT_OK;
            }
        }
        else
        {
            retVal = E_NOT_OK;
        }

        if(E_OK == retVal)
        {
            transaction.arg   = (void *)(uint32)addr;
            transaction.txBuf = NULL;
            transaction.rxBuf = (void *)readData_buf;
            transaction.count = actualChunkSize;

            ret = OSPI_transfer(handle, &transaction);
            if (TRUE == ret)
            {
                if (Fls_VerifyData_priv(expData_Buf, (const uint8*)transaction.rxBuf, actualChunkSize) == TRUE)
                {
                    retVal = E_OK;
                }
                else
                {
                    retVal = E_BLANKCHECK_MISMATCH;
                }
            }
            else
            {
                retVal = E_NOT_OK;
            }

            transaction.rxBuf = NULL;
        }
    }
    else
    {
        retVal = E_NOT_OK; /*Handle is NULL*/
    }
    return retVal;
}


static void ReportFlsError(Fls_JobType job)
{
    switch(job) {
        case FLS_JOB_COMPARE:
			(void) Det_ReportTransientFault(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_COMPARE, FLS_E_COMPARE_FAILED);
            break;
        case FLS_JOB_ERASE:
			(void) Det_ReportTransientFault(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_ERASE, FLS_E_ERASE_FAILED);
            break;
        case FLS_JOB_READ:
			(void) Det_ReportTransientFault(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_READ, FLS_E_READ_FAILED);
            break;
        case FLS_JOB_WRITE:
			(void) Det_ReportTransientFault(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_WRITE, FLS_E_WRITE_FAILED);
            break;
        default:
            break;
    }
	Fls_DrvObj.jobResultType = MEMIF_JOB_FAILED;
	Fls_DrvObj.status = MEMIF_IDLE;
}

/*
 * Design : MCAL-7278,MCAL-7409,MCAL-7448,MCAL-7269,MCAL-7266,MCAL-7441,MCAL-7255,MCAL-7313,MCAL-7278,MCAL-7284,MCAL-7313,MCAL-7334,MCAL-7367,MCAL-7379,MCAL-7409,MCAL-7441
 */
void processJobs(Fls_JobType job)
{
    uint32 chunkSize;
    Std_ReturnType retVal = E_NOT_OK;
    uint8 flashIdx = Fls_DrvObj.Fls_flashIndex;
    const FlashConfig *flsNorDevicePtr = &FlsNorDevice.flscfg[flashIdx];
    /*Get the MIN of two*/
    if (Fls_DrvObj.length < Fls_DrvObj.jobChunkSize)
    {
        chunkSize = Fls_DrvObj.length;
    }
    else
    {
        chunkSize = Fls_DrvObj.jobChunkSize;
    }

    SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_0();

    switch(job) {
        case FLS_JOB_COMPARE:
            retVal = Fls_norCompare(chunkSize);
            break;
        case FLS_JOB_ERASE:

    if(flsNorDevicePtr->FLS_PROTOCOL == FLS_OSPI)
    {
        #if ((STD_ON == FLS_TIMEOUT_SUPERVISION_ENABLED && (STD_OFF == FLS_USE_INTERRUPTS)))
                if (FlsEraseStage == FLS_S_DEFAULT)
                {
                    Fls_DrvObj.prevFlashaddr = Fls_DrvObj.flashAddr;
                }
        #endif
    }
            if (FlsEraseStage == FLS_S_DEFAULT)
            {
                if((flsNorDevicePtr->FLS_PROTOCOL == FLS_OSPI) || (flsNorDevicePtr->FLS_PROTOCOL == FLS_QSPI))
                {
                    FlsEraseStage = FLS_S_INVALID_ADDRESS;
                }
                else if(flsNorDevicePtr->FLS_PROTOCOL == FLS_XSPI)
                {
                    FlsEraseStage = FLS_S_DELAY_0_STAGE;
                    Fls_DrvObj.timeOutVal = flsNorDevicePtr->NOR_WRR_WRITE_TIMEOUT;
                }
                else
                {
                    /*Do Nothing*/
                }
            }

            retVal = Fls_norAsyncErase(chunkSize);
            
            if(flsNorDevicePtr->FLS_PROTOCOL == FLS_OSPI)
            {
                #if ((STD_ON == FLS_TIMEOUT_SUPERVISION_ENABLED) && (STD_OFF == FLS_USE_INTERRUPTS))
                    if ((retVal == E_OK) && (FlsEraseStage == FLS_S_DEFAULT))
                    {
                    Fls_DrvObj.flashAddr =  Fls_DrvObj.prevFlashaddr;
                    retVal = Fls_norBlankCheck(chunkSize);
                    uint32 sector;      
                    sector = Fls_DrvObj.prevFlashaddr / Fls_DrvObj.sectorList[Fls_DrvObj.currentSectorIndex].sectorSize;
                    Fls_DrvObj.flashAddr = (sector + 1U) * Fls_DrvObj.sectorList[Fls_DrvObj.currentSectorIndex].sectorSize;
                    }
                    else{
                        /* Do Nothing */
                    }
                #endif
            }
            break;
        case FLS_JOB_READ:
            retVal = Fls_norRead(chunkSize);
            break;
        case FLS_JOB_WRITE:
            if(flsNorDevicePtr->FLS_PROTOCOL == FLS_OSPI)
            {
                #if ((STD_ON == FLS_TIMEOUT_SUPERVISION_ENABLED) && (STD_OFF == FLS_USE_INTERRUPTS))
                    retVal = Fls_norBlankCheck(chunkSize);
                    if (retVal != E_OK)
                    {
                        break;
                    }
                    else{
                        /* Do Nothing */
                    }
                #endif
            }
            retVal = Fls_norWrite(chunkSize);
            if(flsNorDevicePtr->FLS_PROTOCOL == FLS_OSPI)
            {
                #if ((STD_ON == FLS_TIMEOUT_SUPERVISION_ENABLED) && (STD_OFF == FLS_USE_INTERRUPTS))
                    if (retVal == E_OK)
                    {
                        retVal = Fls_norCompare(chunkSize);
                    }
                    else{
                        /* Do Nothing */
                    }
                #endif
            }
            break;
        case FLS_JOB_BLANKCHECK:
            retVal = Fls_norBlankCheck(chunkSize);
            break;
        default:
            retVal = E_NOT_OK;
            break;
    }

    if ((retVal == E_OK) && ((job != FLS_JOB_ERASE) || ((job == FLS_JOB_ERASE) && (FlsEraseStage == FLS_S_DEFAULT))))
    {
        Fls_DrvObj.ramAddr = &Fls_DrvObj.ramAddr[chunkSize];
        if (job != FLS_JOB_ERASE)
        {
            Fls_DrvObj.flashAddr += chunkSize;
            /*Erase FlashAddr updated in Fls_norErase*/
        }
        Fls_DrvObj.length -= chunkSize;
        Fls_DrvObj.transferred += chunkSize;

        if( 0U == Fls_DrvObj.length )
        {
            Fls_DrvObj.jobResultType = MEMIF_JOB_OK;
            Fls_DrvObj.status = MEMIF_IDLE;
            Fls_DrvObj.jobType = FLS_JOB_NONE;
            Fls_DrvObj.transferred = 0;
            if( Fls_DrvObj.Fls_JobEndNotification != NULL )
            {
                Fls_DrvObj.Fls_JobEndNotification();
            }
        }
        else
        {
            /* Do Nothing */
        }
    }
    else if (retVal != E_OK) /*if retval == E_NOT_OK or E_COMPARE_MISMATCH*/
    {
        if ((E_BLANKCHECK_MISMATCH == retVal) || (E_COMPARE_MISMATCH == retVal))
        {
            Fls_DrvObj.status = MEMIF_IDLE;
            Fls_DrvObj.jobType = FLS_JOB_NONE;
            Fls_DrvObj.transferred = 0;

            if (FLS_JOB_BLANKCHECK == job)
            {
				Det_ReportRuntimeError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_BLANK_CHECK, FLS_E_VERIFY_ERASE_FAILED);
            }
            else /*if (FLS_JOB_COMPARE == job)*/
            {
                Fls_DrvObj.jobResultType = MEMIF_BLOCK_INCONSISTENT;
				Det_ReportRuntimeError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_COMPARE, FLS_E_VERIFY_WRITE_FAILED);
            }

            if( Fls_DrvObj.Fls_JobErrorNotification != NULL )
            {
                Fls_DrvObj.Fls_JobErrorNotification();
            }
        }
        else /*if retVal == E_NOT_OK*/
        {
            /*Hardware/driver internal error occured*/
            ReportFlsError(job);
            if( Fls_DrvObj.Fls_JobErrorNotification != NULL )
            {
                   Fls_DrvObj.Fls_JobErrorNotification();
            }
        }
    }
    else
    {
        /*Do Nothing*/
    }
    SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_0();

    return;
}


/*
 * Design : MCAL-7327,MCAL-7249,MCAL-7400
 */
boolean Fls_VerifyData_priv(const uint8 *expData,
                const uint8 *rxData,
                uint32 length)
{
    uint32 idx = 0U;
    uint32 match = 1U;
    boolean retVal = FALSE;
    uint8 *expData_local = (uint8 *)expData;
    uint8 *rxData_local = (uint8 *)rxData;

    for(idx = 0; ((idx < length) && (match != 0U)); idx++)
    {
        if(*expData_local != *rxData_local)
        {
            match = 0U;
        }
        expData_local++;
        rxData_local++;
    }
    if(match == 1U)
    {
        retVal = TRUE;
    }
    return retVal;
}

Std_ReturnType Nor_ReadId(SPI_Handle handle)
{
    Std_ReturnType       retVal = E_NOT_OK;
    uint8     idCode[3U];
    uint8     flashidx;
    uint32    manfID, devID;
    const FlashConfig *flsNorDevicePtr;

    for (flashidx = 0U; flashidx < NOR_NUMBER_FLASH; flashidx++)
    {
        flsNorDevicePtr = &FlsNorDevice.flscfg[flashidx];
         /* Read the ID code of the flash */
        if(flsNorDevicePtr->FLS_PROTOCOL == FLS_XSPI)
        {   
            OSPI_Object        *object;  /* OSPI object */       
            uint32 cmdLen;

            /* Get the pointer to the object */
            object = (OSPI_Object *)handle->object;
                
            uint8     cmd[6];
            cmd[0] = flsNorDevicePtr->NOR_CMD_RDID;
            cmd[1] = 0;  /* Address Bytes */
            cmd[2] = 0;
            cmd[3] = 0;
            cmd[4] = 0;

            if (object->xferLines == (uint32)OSPI_XFER_LINES_OCTAL)
            {
                cmdLen = flsNorDevicePtr->NOR_RDID_CMD_LENGTH_OCTAL;
            }
            else
            {
                cmdLen = flsNorDevicePtr->NOR_RDID_CMD_LENGTH_SINGLE;
            }
            retVal = Nor_xspiCmdRead(handle, cmd, cmdLen, idCode, flsNorDevicePtr->NOR_RDID_NUM_BYTES);
        }
        else
        {
            uint8 cmd;
            cmd = flsNorDevicePtr->NOR_CMD_RDID;
            if(flsNorDevicePtr->FLS_PROTOCOL == FLS_OSPI)
            {
                retVal = Nor_ospiCmdRead(handle, &cmd, 1, idCode, flsNorDevicePtr->NOR_RDID_NUM_BYTES);
            }
            else
            {
                retVal = Nor_qspiCmdRead(handle, &cmd, 1, idCode, flsNorDevicePtr->NOR_RDID_NUM_BYTES);
            }
        }
        
        if (retVal == E_OK)
        {
            manfID = (uint32)idCode[0];
            devID = ((uint32)idCode[1] << 8) | ((uint32)idCode[2]);
            if ((manfID == flsNorDevicePtr->NOR_MANF_ID) && (devID == flsNorDevicePtr->NOR_DEVICE_ID))
            {
                Fls_DrvObj.Fls_flashIndex = flashidx;
                Fls_DrvObj.Fls_initialised = 1U;
                retVal = E_OK;
                break;
            }
            else
            {
                retVal = E_NOT_OK;
            }
        }
    }
    return retVal;
}

Std_ReturnType Fls_norOpen(void)
{
    SPI_Params      spiParams;  /* SPI params structure */
    SPI_Handle      hwHandle;  /* SPI handle */
    Std_ReturnType             retVal = E_OK;
    uint8 flashIdx;
    const FlashConfig *flsNorDevicePtr;

    /*Set the flash in 1s mode before reading device id */
    if(Fls_DrvObj.Fls_initialised == 0U)
    {
        OSPI_setsinglemode();
        (void)Flash_norSetRdDataCaptureDelay(Fls_DrvObj.spiHandle);
    }

    flashIdx = Fls_DrvObj.Fls_flashIndex;
    flsNorDevicePtr = &FlsNorDevice.flscfg[flashIdx];
    /*Save the DTR enable flag*/
    gDtrEnable = Fls_DrvObj.dtrEnable;

    if((flsNorDevicePtr->FLS_PROTOCOL == FLS_XSPI) || (flsNorDevicePtr->FLS_PROTOCOL == FLS_OSPI))
    {
        if (Fls_DrvObj.dacEnable == TRUE)
        {
            /*enable PHY for DAC mode*/
        #if defined (SOC_J721E) || defined (SOC_J7200) || defined (SOC_J721S2) || defined (SOC_J784S4) || defined (SOC_J742S2)
            Nor_spiPhyTuneReset(gDtrEnable);
        #endif
        }
        else
        {
            Fls_DrvObj.phyEnable = FALSE;
            /*Check to ensure that phy mode should be disabled for INDAC mode*/
        }

        /* Save the PHY enable flag */
        gPhyEnable = Fls_DrvObj.phyEnable;
        if (gPhyEnable == TRUE)
        {
            /*
            * phyEnable is turned on only for DAC read,
            * it turned off for open/erase/write operation
            */
            Fls_DrvObj.phyEnable = FALSE; /*keep phyEnable off for all and only enable for reads */
            /*Set the TuneDone variable to false in open */
            tuneDone = FALSE;
        }
    }

    if(Fls_DrvObj.clkSpeed == 133333333U)
    {
        devDelays[3] = OSPI_DEV_DELAY_CSDA;
    }
    else
    {
        devDelays[3] = OSPI_DEV_DELAY_CSDA_3;
    }

if(flsNorDevicePtr->FLS_PROTOCOL == FLS_XSPI)
{
    Fls_DrvObj.flsBaudRateDiv = BOARD_XSPI_BAUDRATE_DIV_133M;
}

    /* Use default SPI config params if no params provided */
    SPI_Params_init(&spiParams);
    hwHandle = (SPI_Handle)Fls_OSPI_open(Fls_DrvObj.spiHandle, &spiParams);

    if (hwHandle != NULL)
    {

        if (gDtrEnable == TRUE)
        {
            if(flsNorDevicePtr->FLS_PROTOCOL == FLS_OSPI)
            {
                if (Nor_ospiEnableDDR(hwHandle) != E_OK)
                {
                        retVal = E_NOT_OK;
                }
            }
            else if(flsNorDevicePtr->FLS_PROTOCOL == FLS_XSPI)
            {
                if (Fls_DrvObj.ospixferlines == OSPI_XFER_LINES_OCTAL)
                {
                        if (Nor_xspiEnableDDR(hwHandle) != E_OK)
                        {
                                retVal = E_NOT_OK;
                        }
                }
            }
            else if(flsNorDevicePtr->FLS_PROTOCOL == FLS_QSPI)
            {
                if (Nor_qspiEnableDDR(hwHandle) != E_OK)
                {
                        retVal = E_NOT_OK;
                }
            }
            else
            {
                /*Do Nothing*/
            }
        }
        else
        {
            if(flsNorDevicePtr->FLS_PROTOCOL == FLS_OSPI)
            {
                if (Nor_ospiEnableSDR(hwHandle) != E_OK)
                {
                        retVal = E_NOT_OK;
                }
            }
            else if(flsNorDevicePtr->FLS_PROTOCOL == FLS_XSPI)
            {
                if (Fls_DrvObj.ospixferlines == OSPI_XFER_LINES_OCTAL)
                {
                        if (Nor_xspiEnableSDR(hwHandle) != E_OK)
                        {
                                retVal = E_NOT_OK;
                        }
                }
            }
            else if(flsNorDevicePtr->FLS_PROTOCOL == FLS_QSPI)
            {
                if (Nor_qspiEnableSDR(hwHandle) != E_OK)
                {
                        retVal = E_NOT_OK;
                }
            }
            else
            {
                /*Do Nothing*/
            }
        }
        if (E_OK == retVal)
        {
            if(flsNorDevicePtr->FLS_PROTOCOL == FLS_OSPI)
            {
                /* Set read/write opcode and read dummy cycles */
                if (Nor_ospiSetOpcode(hwHandle) == E_OK)
                {
                    if (Flash_SetRdDataCaptureDelay(hwHandle, (uint8)FLS_OSPI) != (sint32)E_OK)
                    {
                        Fls_OSPI_close(hwHandle);

                        retVal = E_NOT_OK;
                    }

                    if (E_OK == retVal)
                    {
                        if (Fls_DrvObj.xipEnable == TRUE)
                        {
                            /* Activate XIP mode in Flash*/
                            retVal = Nor_ospiXipEnable(hwHandle, 0U);
                        }
                    }
                    else /*NorOspiReadID returned E_NO_OK*/
                    {
                        /*
                        * Design : MCAL-7257,MCAL-7308
                        */
                        (void) Det_ReportTransientFault(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_INIT, FLS_E_UNEXPECTED_FLASH_ID);
                    }
                }
                else
                {
                    Fls_OSPI_close(hwHandle);
                    retVal = E_NOT_OK;
                }
            }   
            else if(flsNorDevicePtr->FLS_PROTOCOL == FLS_XSPI)
            {
                if (Fls_DrvObj.ospixferlines == OSPI_XFER_LINES_OCTAL)
                {
                    if (TRUE == gPhyEnable)
                    {
                        Nor_xspiResetMemory(hwHandle);
                    }
                    retVal = Nor_xspiSetOpcode(hwHandle);
                    if (retVal == E_OK)
                    {
                        if (Flash_SetRdDataCaptureDelay(hwHandle, (uint8)FLS_XSPI) != (sint32)E_OK)
                        {
                            Fls_OSPI_close(hwHandle);

                            /*
                            * Design : MCAL-7257,MCAL-7308
                            */
                            (void) Det_ReportTransientFault(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_INIT, FLS_E_UNEXPECTED_FLASH_ID);
                            retVal = E_NOT_OK;
                        }

                    }
                }
                else
                {
                    CSL_ospiSetDualByteOpcodeMode((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR),
                                                FALSE);
                    Nor_xspiResetMemory(hwHandle);
                    /* Set read/write opcode and read dummy cycles */
                    retVal = Nor_xspiSetOpcode(hwHandle);
                    if (retVal == E_OK)
                    {
                        Nor_xspiWaitReady(hwHandle, flsNorDevicePtr->NOR_WRR_WRITE_TIMEOUT);
                        if (Flash_SetRdDataCaptureDelay(hwHandle, (uint8)FLS_XSPI) != (sint32)E_OK)
                        {
                            Fls_OSPI_close(hwHandle);

                            /*
                            * Design : MCAL-7257,MCAL-7308
                            */
                            (void) Det_ReportTransientFault(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_INIT, FLS_E_UNEXPECTED_FLASH_ID);
                            retVal = E_NOT_OK;
                        }

                    }
                }
                if (E_OK == retVal)
                {
                    if (Fls_DrvObj.ospixferlines == OSPI_XFER_LINES_OCTAL)
                    {
                        /* Disable hybrid sector configuration */
                        retVal = Nor_xspiHybridSectCfg(hwHandle, 0U, 0U);
                    }
                }
                else
                {
                    Fls_OSPI_close(hwHandle);
                    retVal = E_NOT_OK;
                }
            }
            else if(flsNorDevicePtr->FLS_PROTOCOL == FLS_QSPI)
            {
                uint32 readCnt = 0;
                uint32 readStart = 0;
                uint32 readCntPrv = 0;
                uint32 readStartPrv = 0;
                if (Fls_DrvObj.phyEnable == TRUE)
                {
                    /* set initial PHY DLL delay */
                    uint32 delay = 0U;
                    (void)OSPI_control(hwHandle, SPI_V0_CMD_CFG_PHY, (void *)(&delay));

                    /* calibrate PHY */
                    for (uint32 i = 0; i < 128U; i++)
                    {
                        if (Flash_SetRdDataCaptureDelay(hwHandle, (uint8)FLS_QSPI) == (sint32)E_OK)
                        {
                            /* Iterate flash reads, find the start index and successful read ID count */
                            if (readCnt == 0U)
                            {
                                readStart = i;
                            }
                            readCnt++;
                        }
                        else
                        {
                            if ((readCnt != 0U) && (readCnt > readCntPrv))
                            {
                                /* save the start index and most successful read ID count */
                                readCntPrv = readCnt;
                                readStartPrv = readStart;
                                readCnt = 0;
                                readStart = 0;
                            }
                        }

                        /* Increment DLL delay */
                        (void)OSPI_control(hwHandle, SPI_V0_CMD_CFG_PHY, NULL);
                    }

                    if (readCnt > readCntPrv)
                    {
                        readCntPrv = readCnt;
                        readStartPrv = readStart;
                    }

                    if (readCntPrv != 0U)
                    {
                        /* Find the delay in the middle working position */
                        delay = readStartPrv + (readCntPrv / 2U);
                        (void)OSPI_control(hwHandle, SPI_V0_CMD_CFG_PHY, (void *)(&delay));
                    }
                    else
                    {
                        Fls_OSPI_close(hwHandle);
                        retVal = E_NOT_OK;
                    }
                }
                else if (Flash_SetRdDataCaptureDelay(hwHandle, (uint8)FLS_QSPI) != (sint32)E_OK)
                {
                    Fls_OSPI_close(hwHandle);

                    /*
                        * Design : MCAL-7257,MCAL-7308
                        */
                    (void) Det_ReportTransientFault(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_INIT, FLS_E_UNEXPECTED_FLASH_ID);
                    retVal = E_NOT_OK;
                }
                else
                {
                    /*Do Nothing*/
                }

                if (E_OK == retVal)
                {
                    if (Fls_DrvObj.xipEnable == TRUE)
                    {
                        /* Activate XIP mode in Flash*/
                        retVal = Nor_qspiXipEnable(hwHandle, 0U);
                    }
                }
                else
                {
                    Fls_OSPI_close(hwHandle);
                    retVal = E_NOT_OK;
                }
                
            }
            else
            {
                /*Do Nothing*/
            }
        }
   }
   else
   {
       retVal = E_NOT_OK;
   }
   return (retVal);
}


void Fls_NorOspiClose(void)
{
    SPI_Handle   spiHandle;
    spiHandle = Fls_DrvObj.spiHandle;
    if (spiHandle != NULL)
    {
        Fls_OSPI_close(spiHandle);
    }
}




#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"