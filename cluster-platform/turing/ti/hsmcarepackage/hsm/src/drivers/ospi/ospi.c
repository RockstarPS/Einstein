/*
 *  Copyright (C) 2021-2023 Texas Instruments Incorporated
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 *  \file ospi.c
 *
 *  \brief File containing OSPI Driver APIs implementation for version V0.
 *
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <string.h>
#include <osal_clock.h>
#include <arch/interrupt.h>
#include "ospi.h"
#include "Std_Types.h"
#include "trace.h"
#include "config.h"


/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

#define OSPI_DIV_ROUND_UP(n, d)     (((n) + (d) - 1) / (d))

/** \brief    OSPI Command default Length */
#define CSL_OSPI_CMD_LEN_DEFAULT            (1U)            /*In bytes */
#define CSL_OSPI_CMD_LEN_EXTENDED           (5U)            /*In bytes */

/** \brief    OSPI operation timeout value */
#define CSL_OSPI_POLL_IDLE_TIMEOUT          (5000U)         /* in millisecond */
#define CSL_OSPI_POLL_IDLE_DELAY            (1U)            /* in millisecond */
#define CSL_OSPI_POLL_IDLE_RETRY            (3U)
#define CSL_OSPI_REG_RETRY                  (10U)
#define CSL_OSPI_FIFO_WIDTH                 (4U)

/** \brief OSPI Chip select macro */
#define CSL_OSPI_CHIP_SELECT(x)   ((~((1U) << (x))) & 0xFU)

/**
 * \brief   OSPI controller master mode baud rate divisor.
 *          OSPI baud rate = master_ref_clk/BD, where BD is:
 *          0000 = /2
 *          0001 = /4
 *          0010 = /6
 *          ...
 *          1111 = /32
 */
#define CSL_OSPI_BAUD_RATE_DIVISOR(x)        (((x) - 2U) >> 1U)
#define CSL_OSPI_BAUD_RATE_DIVISOR_DEFAULT   (CSL_OSPI_BAUD_RATE_DIVISOR(32U))

/**
 *  \brief   OSPI device delay parameter array size.
 */
#define CSL_OSPI_DEV_DELAY_ARRAY_SIZE  (4U)

/**
 *  \brief   OSPI ref clock generates max frequency of 200MHz, OSPI
 *           max operating frequency 200/8 equals 25MHz
 */
#define OSPI_MAX_OPERATING_FREQUENCY      (25000000U)

/** \brief   OSPI device delays in cycles of OSPI master ref clock */
#define CSL_OSPI_DEV_DELAY_CSSOT_NS     (60U)  /* Chip Select Start of Transfer Delay */
#define CSL_OSPI_DEV_DELAY_CSEOT_NS     (60U)  /* Chip Select End of Transfer Delay */
#define CSL_OSPI_DEV_DELAY_CSDADS_NS    (60U) /* Chip Select De-Assert Different Slaves Delay */
#define CSL_OSPI_DEV_DELAY_CSDA_NS      (60U) /* Chip Select De-Assert Delay */

/** \brief  SRAM partition configuration definitions */
/** size of the indirect read/write partition in the SRAM,
    in units of SRAM locations */
#define CSL_OSPI_SRAM_SIZE_WORDS        (128U)
#define CSL_OSPI_SRAM_PARTITION_RD      (64U)
#define CSL_OSPI_SRAM_PARTITION_WR      (CSL_OSPI_SRAM_SIZE_WORDS - \
                                         CSL_OSPI_SRAM_PARTITION_RD)
/* Default value for SRAM PARTITION register */
#define CSL_OSPI_SRAM_PARTITION_DEFAULT (CSL_OSPI_SRAM_PARTITION_RD -  1U)

#define OSPI_READ_WRITE_TIMEOUT (500000U)
#define OSPI_CHECK_IDLE_DELAY       (10U)
#define OSPI_CALIBRATE_DELAY        (20U)
#define OSPI_XIP_SETUP_DELAY        (250U)

/**  \brief  SRAM fill level watermark */
/* Read watermark fill level in words, will generate DMA request or
   interrupt when the SRAM fill level is above the watermark */
#define CSL_OSPI_SRAM_WARERMARK_RD_LVL  (CSL_OSPI_SRAM_PARTITION_RD / 4U)
/* Write watermark fill level in words, will generate DMA request or
   interrupt when the SRAM fill level is below the watermark */
#define CSL_OSPI_SRAM_WATERMARK_WR_LVL  (CSL_OSPI_SRAM_PARTITION_WR / 4U)

#define CSL_OSPI_INTR_MASK_ALL  (CSL_OSPI_FLASH_CFG_IRQ_STATUS_REG_MODE_M_FAIL_FLD_MASK         | \
                                 CSL_OSPI_FLASH_CFG_IRQ_STATUS_REG_UNDERFLOW_DET_FLD_MASK       | \
                                 CSL_OSPI_FLASH_CFG_IRQ_STATUS_REG_INDIRECT_OP_DONE_FLD_MASK         | \
                                 CSL_OSPI_FLASH_CFG_IRQ_STATUS_REG_INDIRECT_READ_REJECT_FLD_MASK       | \
                                 CSL_OSPI_FLASH_CFG_IRQ_STATUS_REG_PROT_WR_ATTEMPT_FLD_MASK     | \
                                 CSL_OSPI_FLASH_CFG_IRQ_STATUS_REG_ILLEGAL_ACCESS_DET_FLD_MASK  | \
                                 CSL_OSPI_FLASH_CFG_IRQ_STATUS_REG_INDIRECT_XFER_LEVEL_BREACH_FLD_MASK | \
                                 CSL_OSPI_FLASH_CFG_IRQ_STATUS_REG_INDRD_SRAM_FULL_FLD_MASK    | \
                                 CSL_OSPI_FLASH_CFG_IRQ_STATUS_REG_POLL_EXP_INT_FLD_MASK)

/* Some common NOR XSPI flash commands */
#define OSPI_NOR_CMD_RDID           (0x9FU)
#define OSPI_NOR_CMD_RSTEN          (0x66U)
#define OSPI_NOR_CMD_RST            (0x99U)
#define OSPI_NOR_CMD_WREN           (0x06U)
#define OSPI_NOR_CMD_RDSR           (0x05U)
#define OSPI_NOR_CMD_RDSFDP         (0x5AU)

/* Macronix Specific*/
#define OSPI_NOR_CMD_SECTORERASE    (0x20u)

#define OSPI_NOR_SR_WIP             (1U << 0U)

#define OSPI_NOR_SFDP_DC            (8U)

#define OSPI_NOR_WRR_WRITE_TIMEOUT  (600U*1000U)

#define PTR_COPY_SRC_ALIGNMENT   sizeof(uintptr_t)

static uint8_t gNorRdCmd = 0x03;
static uint8_t gNorWrCmd = 0x02;
static uint8_t gNorErCmd = 0x20; /*Block erase*/

/* OSPI attributes */
static OSPI_Attrs gOspiAttrs[CONFIG_OSPI_NUM_INSTANCES] =
{
    {
        .baseAddr             = CSL_FSS0_OSPI0_CTRL_BASE,
        .dataBaseAddr         = CSL_FSS0_DAT_REG1_BASE,
        .inputClkFreq         = OSPI_INPUT_CLKFRQ,
        .intrNum              = OSPI_INTERNUMBER,
        .intrEnable           = FALSE,
        .intrPriority         = OSPI_INTERPRIORITY,
        .dacEnable            = OSPI_DACENABLE,
        .chipSelect           = OSPI_CS0, /*done*/
        .frmFmt               = OSPI_FF_POL0_PHA0, /*done*/
        .decChipSelect        = OSPI_DECODER_SELECT4, /*done*/
        .baudRateDiv          = OSPI_BAUDRATEDIV,
        .phaseDelayElement    = OSPI_PHASEDELELE,
    },
};

/* OSPI objects */
static OSPI_Object gOspiObjects[CONFIG_OSPI_NUM_INSTANCES];
/* OSPI driver configuration */
OSPI_Config gOspiConfig[CONFIG_OSPI_NUM_INSTANCES] =
{
    {
        &gOspiAttrs[CONFIG_OSPI0],
        &gOspiObjects[CONFIG_OSPI0],
    },
};

uint32_t gOspiConfigNum = CONFIG_OSPI_NUM_INSTANCES;

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/* Internal functions */

static int32_t OSPI_waitWriteSRAMLevel(const CSL_ospi_flash_cfgRegs *pReg,
                                     uint32_t *sramLvl);
static int32_t OSPI_waitIndWriteComplete(const CSL_ospi_flash_cfgRegs *pReg);
static int32_t OSPI_waitIdle(OSPI_Handle handle, uint32_t timeOut);

static int32_t OSPI_flashExecCmd(const CSL_ospi_flash_cfgRegs *pReg);
static void OSPI_writeFifoData(uintptr_t indAddr, const uint8_t *src, uint32_t wrLen);
static void Ospi_memcpyWord(uint8_t *source, uint8_t *destination, uint32_t length);
static uint32_t OSPI_calculateTicksForns(const uint32_t refClkhz, const uint32_t nsVal);
static int32_t OSPI_programInstance(OSPI_Config *config);
static uint32_t OSPI_utilLog2(uint32_t num);
static uint8_t OSPI_getCmdExt(OSPI_Handle handle, uint8_t cmd);
static void OSPI_EnableDAC(OSPI_Handle handle);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/** \brief LUT table for log2 calculation using DeBruijn sequence */
static const uint8_t gTable[32] =
{
    0, 9, 1, 10, 13, 21, 2, 29, 11, 14, 16, 18, 22, 25, 3, 30,
    8, 12, 20, 28, 15, 17, 24, 7, 19, 27, 23, 6, 26, 5, 4, 31
};

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

void OSPI_init(void)
{
    uint32_t count;
    OSPI_Object *obj;

    /* Init each driver instance object */
    for(count = 0U; count < gOspiConfigNum; count++)
    {
        /* Init object variables */
        obj = gOspiConfig[count].object;

        memset(obj, 0, sizeof(OSPI_Object));
    }

    return;
}

OSPI_Handle OSPI_open(uint32_t index)
{
    int32_t status = SystemP_SUCCESS;
    OSPI_Handle handle = NULL;
    OSPI_Config *config = NULL;
    OSPI_Object *obj = NULL;

    mask_interrupts();
    /* Check for valid index */
    if(index >= gOspiConfigNum)
    {
        status = SystemP_FAILURE;
    }
    else
    {
        config = &gOspiConfig[index];
    }

    if(SystemP_SUCCESS == status)
    {
        obj = config->object;

        if(TRUE == obj->isOpen)
        {
            /* Handle already opened */
            status = SystemP_FAILURE;
        }
    }

    if(SystemP_SUCCESS == status)
    {
        obj->handle = (OSPI_Handle)config;

        status = OSPI_programInstance(config);
    }

    if(SystemP_SUCCESS == status)
    {
        obj->isOpen = 1;
        handle = (OSPI_Handle) config;
    }

    /* Free up resources in case of error */
    if(SystemP_SUCCESS != status)
    {
        if(NULL != config)
        {
            OSPI_close((OSPI_Handle) config);
        }
    }
    unmask_interrupts();
    return handle;
}

void OSPI_close(OSPI_Handle handle)
{
    if(handle != NULL)
    {
        OSPI_Object *obj = ((OSPI_Config *)handle)->object;

        obj->isOpen = 0;
    }

    return;
}

OSPI_Handle OSPI_getHandle(uint32_t driverInstanceIndex)
{
    OSPI_Handle         handle = NULL;
    /* Check index */
    if(driverInstanceIndex < gOspiConfigNum)
    {
        OSPI_Object *obj;
        obj = gOspiConfig[driverInstanceIndex].object;

        if(obj && (TRUE == obj->isOpen))
        {
            /* valid handle */
            handle = obj->handle;
        }
    }
    return handle;
}

void OSPI_Transaction_init(OSPI_Transaction *trans)
{
    trans->count = 0U;
    trans->buf = NULL;
    trans->addrOffset = 0U;
    trans->transferTimeout = SystemP_WAIT_FOREVER;
    trans->status = OSPI_TRANSFER_STARTED;
}

void OSPI_ReadCmdParams_init(OSPI_ReadCmdParams *rdParams)
{
    rdParams->cmd = OSPI_CMD_INVALID_OPCODE;
    rdParams->cmdAddr = OSPI_CMD_INVALID_ADDR;
    rdParams->numAddrBytes = 3;
    rdParams->rxDataBuf = NULL;
    rdParams->rxDataLen = 0;    
    rdParams->dummyBits = 0;
}

void OSPI_WriteCmdParams_init(OSPI_WriteCmdParams *wrParams)
{
    wrParams->cmd = OSPI_CMD_INVALID_OPCODE;
    wrParams->cmdAddr = OSPI_CMD_INVALID_ADDR;
    wrParams->numAddrBytes = 3;
    wrParams->txDataBuf = NULL;
    wrParams->txDataLen = 0;
}

uint32_t OSPI_getInputClk(OSPI_Handle handle)
{
    uint32_t retVal = 0U;

    if(handle != NULL)
    {
        const OSPI_Attrs* attrs = ((OSPI_Config *)handle)->attrs;
        retVal = attrs->inputClkFreq;
    }
    return retVal;
}

int32_t OSPI_enableDDR(OSPI_Handle handle)
{
    int32_t status = SystemP_SUCCESS;

    if(handle != NULL)
    {
        const OSPI_Attrs *attrs = ((OSPI_Config *)handle)->attrs;
        const CSL_ospi_flash_cfgRegs *pReg = (const CSL_ospi_flash_cfgRegs *)(attrs->baseAddr);

        /* Enable DTR protocol */
        CSL_REG32_FINS(&pReg->CONFIG_REG,
                   OSPI_FLASH_CFG_CONFIG_REG_ENABLE_DTR_PROTOCOL_FLD,
                   TRUE);
    }
    else
    {
        status = SystemP_FAILURE;
    }
    return status;
}

int32_t OSPI_enableSDR(OSPI_Handle handle)
{
    int32_t status = SystemP_SUCCESS;

    if(handle != NULL)
    {
        const OSPI_Attrs *attrs = ((OSPI_Config *)handle)->attrs;
        const CSL_ospi_flash_cfgRegs *pReg = (const CSL_ospi_flash_cfgRegs *)(attrs->baseAddr);

        /* Disable DTR protocol */
        CSL_REG32_FINS(&pReg->CONFIG_REG,
                   OSPI_FLASH_CFG_CONFIG_REG_ENABLE_DTR_PROTOCOL_FLD,
                   FALSE);
    }
    else
    {
        status = SystemP_FAILURE;
    }
    return status;
}

int32_t OSPI_enableDdrRdCmds(OSPI_Handle handle)
{
    int32_t status = SystemP_SUCCESS;

    if(handle != NULL)
    {
        const OSPI_Attrs *attrs = ((OSPI_Config *)handle)->attrs;
        const CSL_ospi_flash_cfgRegs *pReg = (const CSL_ospi_flash_cfgRegs *)(attrs->baseAddr);

        /* Enable DDR EN commands */
        CSL_REG32_FINS(&pReg->DEV_INSTR_RD_CONFIG_REG,
                   OSPI_FLASH_CFG_DEV_INSTR_RD_CONFIG_REG_DDR_EN_FLD,
                   1);
    }
    else
    {
        status = SystemP_FAILURE;
    }
    return status;
}

void OSPI_setNumAddrBytes(OSPI_Handle handle, uint32_t numAddrBytes)
{

    if(handle != NULL)
    {
        const OSPI_Attrs *attrs = ((OSPI_Config *)handle)->attrs;
        const CSL_ospi_flash_cfgRegs *pReg = (const CSL_ospi_flash_cfgRegs *)(attrs->baseAddr);
        OSPI_Object *obj = ((OSPI_Config *)handle)->object;

        uint32_t addrByteCode = 0;

        if(numAddrBytes > 0)
        {
            addrByteCode = numAddrBytes - 1;
        }
        else
        {
            addrByteCode = 0;
        }

        CSL_REG32_FINS(&pReg->DEV_SIZE_CONFIG_REG, OSPI_FLASH_CFG_DEV_SIZE_CONFIG_REG_NUM_ADDR_BYTES_FLD, addrByteCode);

        /* Update book-keeping variable in OSPI object */
        obj->numAddrBytes = numAddrBytes;
    }
    else
    {
        /* do nothing */
    }
}

void OSPI_setDeviceSize(OSPI_Handle handle, uint32_t pageSize, uint32_t blkSize)
{

    if(handle != NULL)
    {
        const OSPI_Attrs *attrs = ((OSPI_Config *)handle)->attrs;
        const CSL_ospi_flash_cfgRegs *pReg = (const CSL_ospi_flash_cfgRegs *)(attrs->baseAddr);

        CSL_REG32_FINS(&pReg->DEV_SIZE_CONFIG_REG, OSPI_FLASH_CFG_DEV_SIZE_CONFIG_REG_BYTES_PER_DEVICE_PAGE_FLD, pageSize);
        CSL_REG32_FINS(&pReg->DEV_SIZE_CONFIG_REG, OSPI_FLASH_CFG_DEV_SIZE_CONFIG_REG_BYTES_PER_SUBSECTOR_FLD, OSPI_utilLog2(blkSize));
    }
    else
    {
        /* do nothing */
    }
}

void OSPI_setModeBits(OSPI_Handle handle, uint32_t modeBits)
{

    if(NULL != handle)
    {
        const OSPI_Attrs *attrs = ((OSPI_Config *)handle)->attrs;
        const CSL_ospi_flash_cfgRegs *pReg;

        pReg = (const CSL_ospi_flash_cfgRegs *)(attrs->baseAddr);

        CSL_REG32_FINS(&pReg->MODE_BIT_CONFIG_REG,
                    OSPI_FLASH_CFG_MODE_BIT_CONFIG_REG_MODE_FLD,
                    (uint8_t)modeBits);
    }
}

void OSPI_enableModeBitsCmd(OSPI_Handle handle)
{

    if(NULL != handle)
    {
        const OSPI_Attrs *attrs = ((OSPI_Config *)handle)->attrs;
        const CSL_ospi_flash_cfgRegs *pReg;

        pReg = (const CSL_ospi_flash_cfgRegs *)(attrs->baseAddr);

        CSL_REG32_FINS(&pReg->FLASH_CMD_CTRL_REG,
                    OSPI_FLASH_CFG_FLASH_CMD_CTRL_REG_ENB_MODE_BIT_FLD,
                    1);
    }
}

void OSPI_enableModeBitsRead(OSPI_Handle handle)
{

    if(NULL != handle)
    {
        const OSPI_Attrs *attrs = ((OSPI_Config *)handle)->attrs;
        const CSL_ospi_flash_cfgRegs *pReg;

        pReg = (const CSL_ospi_flash_cfgRegs *)(attrs->baseAddr);

        CSL_REG32_FINS(&pReg->DEV_INSTR_RD_CONFIG_REG,
                    OSPI_FLASH_CFG_DEV_INSTR_RD_CONFIG_REG_MODE_BIT_ENABLE_FLD,
                    1);
    }
}

static uint32_t OSPI_isProtocolValid(uint32_t cmd, uint32_t addr, uint32_t data, uint32_t strDtr)
{
    uint32_t isValid = TRUE;

    uint32_t lineArr[] = {1,2,4,8};
    uint32_t varArr[] = {cmd, addr, data};

    uint32_t i, j;

    for(i = 0; i < 3; i++)
    {
        uint32_t flag = 0;
        for(j = 0; j < 4; j++)
        {
            if(varArr[i] == lineArr[j])
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            /* Error in one of the lines. Abort */
            isValid = FALSE;
            break;
        }
    }

    if((isValid == TRUE) && (strDtr > 1))
    {
        isValid = FALSE;
    }
    return isValid;
}

void OSPI_setDualOpCodeMode(OSPI_Handle handle)
{
    if(handle != NULL)
    {
        const OSPI_Attrs *attrs = ((OSPI_Config *)handle)->attrs;
        const CSL_ospi_flash_cfgRegs *pReg = (const CSL_ospi_flash_cfgRegs *)(attrs->baseAddr);

        /* Enable dual byte opcode */
        CSL_REG32_FINS(&pReg->CONFIG_REG, OSPI_FLASH_CFG_CONFIG_REG_DUAL_BYTE_OPCODE_EN_FLD, TRUE);
    }
    else
    {
        /* do nothing */
    }
}

void OSPI_setProtocol(OSPI_Handle handle, uint32_t protocol)
{

    if(handle != NULL)
    {
        /* First set the transfer lines */
        const OSPI_Attrs *attrs = ((OSPI_Config *)handle)->attrs;
        const CSL_ospi_flash_cfgRegs *pReg = (const CSL_ospi_flash_cfgRegs *)(attrs->baseAddr);
        OSPI_Object *obj = ((OSPI_Config *)handle)->object;

        uint32_t dtr  = ((protocol >> 24) & 0xFF);
        uint32_t cmd  = ((protocol >> 16) & 0xFF);
        uint32_t addr = ((protocol >> 8) & 0xFF);
        uint32_t data = (protocol & 0xFF);

        /* Validate requested protocol */
        if(OSPI_isProtocolValid(cmd, addr, data, dtr) == TRUE)
        {
            /* Take log2 of each line value to set register */
            cmd = OSPI_utilLog2(cmd);
            addr = OSPI_utilLog2(addr);
            data = OSPI_utilLog2(data);

            /* Transfer lines for Read */
            /* Set transfer lines for sending command */
            CSL_REG32_FINS(&pReg->DEV_INSTR_RD_CONFIG_REG, OSPI_FLASH_CFG_DEV_INSTR_RD_CONFIG_REG_INSTR_TYPE_FLD, cmd);
            /* Set transfer lines for sending address */
            CSL_REG32_FINS(&pReg->DEV_INSTR_RD_CONFIG_REG, OSPI_FLASH_CFG_DEV_INSTR_RD_CONFIG_REG_ADDR_XFER_TYPE_STD_MODE_FLD, addr);
            /* Set transfer lines for sending data */
            CSL_REG32_FINS(&pReg->DEV_INSTR_RD_CONFIG_REG, OSPI_FLASH_CFG_DEV_INSTR_RD_CONFIG_REG_DATA_XFER_TYPE_EXT_MODE_FLD, data);

            /* Transfer lines for Write */
            /* Set transfer lines for sending address */
            CSL_REG32_FINS(&pReg->DEV_INSTR_WR_CONFIG_REG, OSPI_FLASH_CFG_DEV_INSTR_WR_CONFIG_REG_ADDR_XFER_TYPE_STD_MODE_FLD, addr);
            /* Set transfer lines for sending data */
            CSL_REG32_FINS(&pReg->DEV_INSTR_WR_CONFIG_REG, OSPI_FLASH_CFG_DEV_INSTR_WR_CONFIG_REG_DATA_XFER_TYPE_EXT_MODE_FLD, data);

            if(dtr)
            {
                if(protocol == OSPI_FLASH_PROTOCOL(8,8,8,1))
                {
                    OSPI_enableDDR(handle);
                    OSPI_setDualOpCodeMode(handle);
                }
                if(protocol == OSPI_FLASH_PROTOCOL(4,4,4,1))
                {
                    OSPI_enableDdrRdCmds(handle);
                }
            }

            /* Update book-keeping variable in OSPI object */
            obj->protocol = protocol;
        }
    }
    else
    {
        /* do nothing */
    }
}

void OSPI_setReadDummyCycles(OSPI_Handle handle, uint32_t dummyCycles)
{

    if(handle != NULL)
    {
        const OSPI_Attrs *attrs = ((OSPI_Config *)handle)->attrs;
        const CSL_ospi_flash_cfgRegs *pReg = (const CSL_ospi_flash_cfgRegs *)(attrs->baseAddr);
        OSPI_Object *obj = ((OSPI_Config *)handle)->object;

        /* Set read dummy cycles */
        CSL_REG32_FINS(&pReg->DEV_INSTR_RD_CONFIG_REG, OSPI_FLASH_CFG_DEV_INSTR_RD_CONFIG_REG_DUMMY_RD_CLK_CYCLES_FLD, dummyCycles);

        /* Update book-keeping variable in OSPI object */
        obj->rdDummyCycles = dummyCycles;
    }
    else
    {
        /* do nothing */
    }
}

void OSPI_setCmdDummyCycles(OSPI_Handle handle, uint32_t dummyCycles)
{

    if(handle != NULL)
    {
        const OSPI_Attrs *attrs = ((OSPI_Config *)handle)->attrs;
        const CSL_ospi_flash_cfgRegs *pReg = (const CSL_ospi_flash_cfgRegs *)(attrs->baseAddr);
        OSPI_Object *obj = ((OSPI_Config *)handle)->object;

        /* Set command dummy cycles */
        CSL_REG32_FINS(&pReg->FLASH_CMD_CTRL_REG, OSPI_FLASH_CFG_FLASH_CMD_CTRL_REG_NUM_DUMMY_CYCLES_FLD, dummyCycles);

        /* Update book-keeping variable in OSPI object */
        obj->cmdDummyCycles = dummyCycles;
    }
    else
    {
        /* do nothing */
    }
}

void OSPI_setCmdExtType(OSPI_Handle handle, uint32_t cmdExtType)
{

    if(NULL != handle)
    {
        OSPI_Object *obj = ((OSPI_Config *)handle)->object;
        obj->cmdExtType = cmdExtType;
    }
    else
    {
        /* do nothing */
    }
}

void OSPI_setXferOpCodes(OSPI_Handle handle, uint8_t readCmd, uint8_t pageProgCmd)
{

    if(handle != NULL)
    {
        const OSPI_Attrs *attrs = ((OSPI_Config *)handle)->attrs;
        const CSL_ospi_flash_cfgRegs *pReg = (const CSL_ospi_flash_cfgRegs *)(attrs->baseAddr);
        uint8_t cmdExt = OSPI_CMD_INVALID_OPCODE;

        /* Set opcode for read */
        CSL_REG32_FINS(&pReg->DEV_INSTR_RD_CONFIG_REG, OSPI_FLASH_CFG_DEV_INSTR_RD_CONFIG_REG_RD_OPCODE_NON_XIP_FLD, readCmd);

        /* Set the extended opcode for read */
        cmdExt = OSPI_getCmdExt(handle, readCmd);

        if(cmdExt != OSPI_CMD_INVALID_OPCODE)
        {
            CSL_REG32_FINS(&pReg->OPCODE_EXT_LOWER_REG, OSPI_FLASH_CFG_OPCODE_EXT_LOWER_REG_EXT_READ_OPCODE_FLD, cmdExt);
        }

        /* Set opcode for write */
        CSL_REG32_FINS(&pReg->DEV_INSTR_WR_CONFIG_REG, OSPI_FLASH_CFG_DEV_INSTR_WR_CONFIG_REG_WR_OPCODE_FLD, pageProgCmd);

        /* Set the extended opcode for read */
        cmdExt = OSPI_getCmdExt(handle, pageProgCmd);

        if(cmdExt != OSPI_CMD_INVALID_OPCODE)
        {
            CSL_REG32_FINS(&pReg->OPCODE_EXT_LOWER_REG, OSPI_FLASH_CFG_OPCODE_EXT_LOWER_REG_EXT_WRITE_OPCODE_FLD, cmdExt);
        }
    }
    else
    {
        /* do nothing */
    }
}

static uint32_t OSPI_calculateTicksForns(const uint32_t refClkhz, const uint32_t nsVal)
{
	uint32_t ticks = 0;
	ticks = refClkhz / 1000;	/* kHz */
	ticks = OSPI_DIV_ROUND_UP(ticks * nsVal, 1000000);
	return ticks;
}

/* Different OSPI Read functions */
int32_t OSPI_readCmd(OSPI_Handle handle, OSPI_ReadCmdParams *rdParams)
{
    int32_t status = SystemP_SUCCESS;

    const OSPI_Attrs *attrs = ((OSPI_Config *)handle)->attrs;
    const CSL_ospi_flash_cfgRegs *pReg = (const CSL_ospi_flash_cfgRegs *)(attrs->baseAddr);
    OSPI_Object *obj = ((OSPI_Config *)handle)->object;
    uint8_t *pBuf = (uint8_t *) rdParams->rxDataBuf;
    uint32_t rxLen = rdParams->rxDataLen;
    uint32_t dualOpCode;

    /* Clear flash command control register */
    CSL_REG32_WR(&pReg->FLASH_CMD_CTRL_REG, 0U);

    /* Set command opcode */
    CSL_REG32_FINS(&pReg->FLASH_CMD_CTRL_REG, OSPI_FLASH_CFG_FLASH_CMD_CTRL_REG_CMD_OPCODE_FLD, rdParams->cmd);

    /* Enable read data in command control register */
    CSL_REG32_FINS(&pReg->FLASH_CMD_CTRL_REG, OSPI_FLASH_CFG_FLASH_CMD_CTRL_REG_ENB_READ_DATA_FLD, TRUE);

    /* Set number of read data bytes */
    CSL_REG32_FINS(&pReg->FLASH_CMD_CTRL_REG, OSPI_FLASH_CFG_FLASH_CMD_CTRL_REG_NUM_RD_DATA_BYTES_FLD, rxLen - 1);

    /* Set dummyCycles for the command */
    if(rdParams->dummyBits != OSPI_CMD_INVALID_DUMMY)
    {
        CSL_REG32_FINS(&pReg->FLASH_CMD_CTRL_REG, OSPI_FLASH_CFG_FLASH_CMD_CTRL_REG_NUM_DUMMY_CYCLES_FLD, rdParams->dummyBits);
    }
    else
    {
        CSL_REG32_FINS(&pReg->FLASH_CMD_CTRL_REG, OSPI_FLASH_CFG_FLASH_CMD_CTRL_REG_NUM_DUMMY_CYCLES_FLD, obj->cmdDummyCycles);
    }

    dualOpCode = CSL_REG32_FEXT(&pReg->CONFIG_REG,
                                OSPI_FLASH_CFG_CONFIG_REG_DUAL_BYTE_OPCODE_EN_FLD);

    if(dualOpCode == 1)
    {
        uint8_t cmdExt = OSPI_getCmdExt(handle, rdParams->cmd);
        /* Set extended STIG opcode */
        CSL_REG32_FINS(&pReg->OPCODE_EXT_LOWER_REG, OSPI_FLASH_CFG_OPCODE_EXT_LOWER_REG_EXT_STIG_OPCODE_FLD, cmdExt);
    }
    else
    {
        /* do nothing */
    }

    if(rdParams->cmdAddr != OSPI_CMD_INVALID_ADDR)
    {
        /* Enable Command address in command control register */
        CSL_REG32_FINS(&pReg->FLASH_CMD_CTRL_REG, OSPI_FLASH_CFG_FLASH_CMD_CTRL_REG_ENB_COMD_ADDR_FLD, TRUE);

        /* Set number of address bytes */
        CSL_REG32_FINS(&pReg->FLASH_CMD_CTRL_REG, OSPI_FLASH_CFG_FLASH_CMD_CTRL_REG_NUM_ADDR_BYTES_FLD, rdParams->numAddrBytes - 1);

        /* Update the flash cmd address register */
        CSL_REG32_WR(&pReg->FLASH_CMD_ADDR_REG, rdParams->cmdAddr);
    }
    else
    {
        /* do nothing */
    }

    status = OSPI_flashExecCmd(pReg);

    if(status == 0)
    {
        uint32_t regVal = CSL_REG32_RD(&pReg->FLASH_RD_DATA_LOWER_REG);
        uint32_t rdLen = (rxLen > 4U) ? 4U : rxLen;
        (void)memcpy((void *)pBuf, (void *)(&regVal), rdLen); 
        pBuf += rdLen;

        if(rxLen > 4U)
        {
            regVal = CSL_REG32_RD(&pReg->FLASH_RD_DATA_UPPER_REG);
            rdLen = rxLen - rdLen;
            (void)memcpy((void *)pBuf, (void *)(&regVal), rdLen); 
        }
    }
    return status;
}

/* Different OSPI write functions */
int32_t OSPI_writeCmd(OSPI_Handle handle, OSPI_WriteCmdParams *wrParams)
{
    int32_t status = SystemP_SUCCESS;

    const OSPI_Attrs *attrs = ((OSPI_Config *)handle)->attrs;
    const CSL_ospi_flash_cfgRegs *pReg = (const CSL_ospi_flash_cfgRegs *)(attrs->baseAddr);
    
    uint8_t *txBuf = (uint8_t *) wrParams->txDataBuf;
    uint32_t txLen = wrParams->txDataLen;
    uint32_t dualOpCode;
    
    /* Clear the flash command control register */
    CSL_REG32_WR(&pReg->FLASH_CMD_CTRL_REG, 0U);

    /* Set command opcode */
    CSL_REG32_FINS(&pReg->FLASH_CMD_CTRL_REG, OSPI_FLASH_CFG_FLASH_CMD_CTRL_REG_CMD_OPCODE_FLD, wrParams->cmd);

    /* Set command address if needed */
    if(wrParams->cmdAddr != OSPI_CMD_INVALID_ADDR)
    {
        /* Enable Command address in command control register */
        CSL_REG32_FINS(&pReg->FLASH_CMD_CTRL_REG, OSPI_FLASH_CFG_FLASH_CMD_CTRL_REG_ENB_COMD_ADDR_FLD, TRUE);

        /* Set number of address bytes */
        CSL_REG32_FINS(&pReg->FLASH_CMD_CTRL_REG, OSPI_FLASH_CFG_FLASH_CMD_CTRL_REG_NUM_ADDR_BYTES_FLD, wrParams->numAddrBytes - 1);

        /* Update the flash cmd address register */
        CSL_REG32_WR(&pReg->FLASH_CMD_ADDR_REG, wrParams->cmdAddr);
    }
    else
    {
        /* do nothing */
    }

    dualOpCode = CSL_REG32_FEXT(&pReg->CONFIG_REG,
                                OSPI_FLASH_CFG_CONFIG_REG_DUAL_BYTE_OPCODE_EN_FLD);

    if(dualOpCode == 1)
    {
        uint8_t cmdExt = OSPI_getCmdExt(handle, wrParams->cmd);
        /* Set extended STIG opcode */
        CSL_REG32_FINS(&pReg->OPCODE_EXT_LOWER_REG, OSPI_FLASH_CFG_OPCODE_EXT_LOWER_REG_EXT_STIG_OPCODE_FLD, cmdExt);
    }
    else
    {
        /* do nothing */
    }

    if (txLen != 0U)
    {
        uint32_t wrLen = 0;
        uint32_t wrData = 0;

        /* Enable write data in command control register */
        CSL_REG32_FINS(&pReg->FLASH_CMD_CTRL_REG, OSPI_FLASH_CFG_FLASH_CMD_CTRL_REG_ENB_WRITE_DATA_FLD, TRUE);

        /* Set number of data bytes to write */
        CSL_REG32_FINS(&pReg->FLASH_CMD_CTRL_REG, OSPI_FLASH_CFG_FLASH_CMD_CTRL_REG_NUM_WR_DATA_BYTES_FLD, txLen-1);

        wrLen = txLen > 4U ? 4U : txLen;
        memcpy(&wrData, txBuf, wrLen); 
        CSL_REG32_WR(&pReg->FLASH_WR_DATA_LOWER_REG, wrData);

        if (txLen > 4U)
        {
            txBuf += wrLen;
            wrLen = txLen - wrLen;
            memcpy(&wrData, txBuf, wrLen); 
            CSL_REG32_WR(&pReg->FLASH_WR_DATA_UPPER_REG, wrData);
        }
    }
    else
    {
        /* do nothing */
    }

    status = OSPI_flashExecCmd(pReg);
    return status;
}

static void OSPI_EnableDAC(OSPI_Handle handle)
{
    const OSPI_Attrs *attrs = ((OSPI_Config *)handle)->attrs;
    const CSL_ospi_flash_cfgRegs *pReg = (const CSL_ospi_flash_cfgRegs *)(attrs->baseAddr);
    if(attrs->dacEnable != FALSE)
    {
        CSL_REG32_FINS(&pReg->CONFIG_REG,
                   OSPI_FLASH_CFG_CONFIG_REG_ENB_DIR_ACC_CTLR_FLD,
                   1);
        CSL_REG32_WR(&pReg->IND_AHB_ADDR_TRIGGER_REG, 0x04000000);
    }
}

int32_t OSPI_readDirect(OSPI_Handle handle, OSPI_Transaction *trans)
{
    int32_t status = SystemP_SUCCESS;

    const OSPI_Attrs *attrs = ((OSPI_Config *)handle)->attrs;
    const CSL_ospi_flash_cfgRegs *pReg = (const CSL_ospi_flash_cfgRegs *)(attrs->baseAddr);

    uint8_t *pSrc;
    uint8_t *pDst;
    uint32_t addrOffset;

    addrOffset = trans->addrOffset;
    pDst = (uint8_t *) trans->buf;

    /* Enable Direct Access Mode */
    CSL_REG32_FINS(&pReg->CONFIG_REG,
                   OSPI_FLASH_CFG_CONFIG_REG_ENB_DIR_ACC_CTLR_FLD,
                   1);
    CSL_REG32_WR(&pReg->IND_AHB_ADDR_TRIGGER_REG, 0x04000000);

    pSrc = (uint8_t *)(attrs->dataBaseAddr + addrOffset);

    Ospi_memcpyWord(pSrc, pDst, trans->count); 
    return status;
}

int32_t OSPI_writeDirect(OSPI_Handle handle, OSPI_Transaction *trans)
{
    int32_t status = SystemP_SUCCESS;

    const OSPI_Attrs *attrs = ((OSPI_Config *)handle)->attrs;

    /* Enable DAC Mode */
   // OSPI_enableDacMode(handle); /* already enabled */
    const CSL_ospi_flash_cfgRegs *pReg = (const CSL_ospi_flash_cfgRegs *)attrs->baseAddr;
    /* Disable PHY pipeline mode */
    CSL_REG32_FINS(&pReg->CONFIG_REG,
                   OSPI_FLASH_CFG_CONFIG_REG_PIPELINE_PHY_FLD,
                   FALSE);

    uint32_t offset;
    uint8_t *src, *dst;
    uint32_t wrWord;
    uint8_t wrByte;
    uint32_t size, remainingSize;
    {
        offset = trans->addrOffset;
        dst = (uint8_t *)(attrs->dataBaseAddr + offset);
        src = trans->buf;
        remainingSize = trans->count & 3U;
        size = trans->count - remainingSize;

        for(int i = 0; i < size; i+=4)
        {
            wrWord = CSL_REG32_RD(src + i);
            CSL_REG32_WR(dst + i, wrWord);
            OSPI_waitIdle(handle, OSPI_READ_WRITE_TIMEOUT);
        }

        for(int i = 0; i < remainingSize; i++)
        {
            wrByte = CSL_REG8_RD(src + size + i);
            CSL_REG8_WR(dst + size + i, wrByte);
            OSPI_waitIdle(handle, OSPI_READ_WRITE_TIMEOUT);
        }
    }

    //CacheP_wbInv((void*)(attrs->dataBaseAddr + offset), trans->count, CacheP_TYPE_ALL);
    return status;
}

int32_t OSPI_writeIndirect(OSPI_Handle handle, OSPI_Transaction *trans)
{
    int32_t status = SystemP_SUCCESS;

    const OSPI_Attrs *attrs = ((OSPI_Config *)handle)->attrs;
    OSPI_Object *obj = ((OSPI_Config *)handle)->object;
    const CSL_ospi_flash_cfgRegs *pReg = (const CSL_ospi_flash_cfgRegs *)attrs->baseAddr;

    uint8_t *pSrc;
    uint32_t addrOffset, remainingSize, sramLevel, wrBytes, wrFlag = 0;

    addrOffset = trans->addrOffset;
    pSrc = (uint8_t *) trans->buf;

    /* Disable DAC Mode */
    CSL_REG32_FINS(&pReg->CONFIG_REG,
                   OSPI_FLASH_CFG_CONFIG_REG_ENB_DIR_ACC_CTLR_FLD,
                   0U);

    CSL_REG32_WR(&pReg->IND_AHB_ADDR_TRIGGER_REG, 0);

    /* Set write address in indirect mode */
    CSL_REG32_WR(&pReg->INDIRECT_WRITE_XFER_START_REG, addrOffset);

    /* Set the Indirect Write Transfer Start Address Register */
    CSL_REG32_WR(&pReg->INDIRECT_WRITE_XFER_NUM_BYTES_REG, trans->count);

    /* Reset watermark register */
    CSL_REG32_WR(&pReg->INDIRECT_WRITE_XFER_WATERMARK_REG, 0);

    /* Set the Indirect Write Transfer Watermark Register */
    CSL_REG32_WR(&pReg->INDIRECT_WRITE_XFER_WATERMARK_REG,
                 CSL_OSPI_SRAM_WATERMARK_WR_LVL);

    /* Start the indirect write transfer */
    CSL_REG32_FINS(&pReg->INDIRECT_WRITE_XFER_CTRL_REG,
                   OSPI_FLASH_CFG_INDIRECT_WRITE_XFER_CTRL_REG_START_FLD,
                   1);

    if(OSPI_TRANSFER_MODE_POLLING == obj->transferMode)
    {
        if(OSPI_waitWriteSRAMLevel(pReg, &sramLevel) != 0)
        {
            wrFlag = 1U;
            status = SystemP_FAILURE;
            trans->status = OSPI_TRANSFER_FAILED;
        }
        else
        {
            remainingSize = trans->count;
            while(remainingSize > 0U)
            {
                if(OSPI_waitWriteSRAMLevel(pReg, &sramLevel) != 0)
                {
                    wrFlag = 1U;
                    status = SystemP_FAILURE;
                    break;
                }

                wrBytes = (CSL_OSPI_SRAM_PARTITION_WR - sramLevel) * CSL_OSPI_FIFO_WIDTH;
                wrBytes = (wrBytes > remainingSize) ? remainingSize : wrBytes;
                OSPI_writeFifoData(attrs->dataBaseAddr, pSrc, wrBytes);

                pSrc += wrBytes;
                remainingSize -= wrBytes;
            }
            if(wrFlag == 0U && OSPI_waitIndWriteComplete(pReg) != 0)
            {
                wrFlag = 1U;
                status = -1;
            }
        }
    }

    if(wrFlag == 1U)
    {
        trans->status = OSPI_TRANSFER_FAILED;
        /* Cancel the indirect write */
        CSL_REG32_FINS(&pReg->INDIRECT_WRITE_XFER_CTRL_REG,
                   OSPI_FLASH_CFG_INDIRECT_WRITE_XFER_CTRL_REG_CANCEL_FLD,
                   1);
    }
    /* Enable Direct Access Mode */
   /* CSL_REG32_FINS(&pReg->CONFIG_REG,
                   OSPI_FLASH_CFG_CONFIG_REG_ENB_DIR_ACC_CTLR_FLD,
                   1);*/
    //CSL_REG32_WR(&pReg->IND_AHB_ADDR_TRIGGER_REG, 0x04000000);
    return status;
}

int32_t OSPI_norFlashCmdRead(OSPI_Handle handle, uint8_t cmd, uint8_t *rxBuf, uint32_t rxLen)
{
    int32_t status = SystemP_SUCCESS;

    OSPI_ReadCmdParams rdParams;
    OSPI_ReadCmdParams_init(&rdParams);
    rdParams.cmd       = cmd;
    rdParams.rxDataBuf = rxBuf;
    rdParams.rxDataLen = rxLen;

    status += OSPI_readCmd(handle, &rdParams);
    return status;
}

int32_t OSPI_norFlashCmdWrite(OSPI_Handle handle, uint8_t cmd, uint32_t cmdAddr, uint8_t *txBuf, uint32_t txLen)
{
    int32_t status = SystemP_SUCCESS;
    OSPI_WriteCmdParams wrParams;
    OSPI_WriteCmdParams_init(&wrParams);
    wrParams.cmd        = cmd;
    wrParams.cmdAddr    = cmdAddr;
    wrParams.txDataBuf  = txBuf;
    wrParams.txDataLen  = txLen;
    status += OSPI_writeCmd(handle, &wrParams);
    return status;
}

void OSPI_norFlashSetCmds(uint8_t rdCmd, uint8_t wrCmd, uint8_t eraseCmd)
{

    if(rdCmd !=0 && rdCmd != 0xFF)
    {
        gNorRdCmd = rdCmd;
    }
    if(wrCmd !=0 && wrCmd != 0xFF)
    {
        gNorWrCmd = wrCmd;
    }
    if(eraseCmd !=0 && eraseCmd != 0xFF)
    {
        gNorErCmd = eraseCmd;
    }
}

int32_t OSPI_setRdDataCaptureDelay(OSPI_Handle handle, uint32_t rdDataCapDelay)
{
    int32_t status = SystemP_SUCCESS;

    if(handle != NULL)
    {
        OSPI_Object *obj = ((OSPI_Config *)handle)->object;
        const OSPI_Attrs *attrs = ((OSPI_Config *)handle)->attrs;
        const CSL_ospi_flash_cfgRegs *pReg = (const CSL_ospi_flash_cfgRegs *)(attrs->baseAddr);

        /* Set read capture delay */
        CSL_REG32_FINS(&pReg->RD_DATA_CAPTURE_REG,
                   OSPI_FLASH_CFG_RD_DATA_CAPTURE_REG_DELAY_FLD,
                   rdDataCapDelay);

        /* Update book keeping */
        obj->rdDataCapDelay = rdDataCapDelay;
    }
    else
    {
        status = SystemP_FAILURE;
    }
    return status;
}

int32_t OSPI_norFlashInit1s1s1s(OSPI_Handle handle)
{
    int32_t status = SystemP_SUCCESS;

    const OSPI_Attrs *attrs = ((OSPI_Config *)handle)->attrs;
    const CSL_ospi_flash_cfgRegs *pReg = (const CSL_ospi_flash_cfgRegs *)(attrs->baseAddr);
    uint32_t regVal = 0U;
    uint8_t cmd;

    /* Wait for a while */
    uint32_t waitMicro = 500U * 1000U;

    /* SDR will be enabled in flash by default, set OSPI controller to 1S-1S-1S mode */
    uint32_t xferLines = 0;

    /* Reset the Flash */
    cmd = OSPI_NOR_CMD_RSTEN;
    OSPI_norFlashCmdWrite(handle, cmd, 0xFFFFFFFF, NULL, 0);

    cmd = OSPI_NOR_CMD_RST;
    OSPI_norFlashCmdWrite(handle, cmd, 0xFFFFFFFF, NULL, 0);
    
    osal_sleep_us(waitMicro);

    /* Set lowest bus clock */
   /* CSL_REG32_FINS(&pReg->CONFIG_REG,
                   OSPI_FLASH_CFG_CONFIG_REG_MSTR_BAUD_DIV_FLD,
                   0xF);*/

    /* Set number of address bytes as 3 to support legacy flash devices also
        00 = 1 addr byte
        01 = 2 addr byte
        10 = 3 addr byte
        11 = 4 addr byte
    */
    CSL_REG32_FINS(&pReg->DEV_SIZE_CONFIG_REG, OSPI_FLASH_CFG_DEV_SIZE_CONFIG_REG_NUM_ADDR_BYTES_FLD, 0x02);

    /* Set RD and WR Config register */
    regVal = CSL_REG32_RD(&pReg->DEV_INSTR_RD_CONFIG_REG);
    /* Configure the Device Read Instruction Configuration Register */
    regVal &= ~(CSL_OSPI_FLASH_CFG_DEV_INSTR_RD_CONFIG_REG_INSTR_TYPE_FLD_MASK              | \
                CSL_OSPI_FLASH_CFG_DEV_INSTR_RD_CONFIG_REG_RD_OPCODE_NON_XIP_FLD_MASK       | \
                CSL_OSPI_FLASH_CFG_DEV_INSTR_RD_CONFIG_REG_ADDR_XFER_TYPE_STD_MODE_FLD_MASK | \
                CSL_OSPI_FLASH_CFG_DEV_INSTR_RD_CONFIG_REG_DATA_XFER_TYPE_EXT_MODE_FLD_MASK | \
                CSL_OSPI_FLASH_CFG_DEV_INSTR_RD_CONFIG_REG_DDR_EN_FLD_MASK                  | \
                CSL_OSPI_FLASH_CFG_DEV_INSTR_RD_CONFIG_REG_DUMMY_RD_CLK_CYCLES_FLD_MASK);
    regVal |= ((uint32_t)gNorRdCmd << CSL_OSPI_FLASH_CFG_DEV_INSTR_RD_CONFIG_REG_RD_OPCODE_NON_XIP_FLD_SHIFT)        | \
              (xferLines << CSL_OSPI_FLASH_CFG_DEV_INSTR_RD_CONFIG_REG_DATA_XFER_TYPE_EXT_MODE_FLD_SHIFT) | \
              (xferLines << CSL_OSPI_FLASH_CFG_DEV_INSTR_RD_CONFIG_REG_ADDR_XFER_TYPE_STD_MODE_FLD_SHIFT) | \
              (xferLines << CSL_OSPI_FLASH_CFG_DEV_INSTR_RD_CONFIG_REG_INSTR_TYPE_FLD_SHIFT)          | \
              (0U << CSL_OSPI_FLASH_CFG_DEV_INSTR_RD_CONFIG_REG_DUMMY_RD_CLK_CYCLES_FLD_SHIFT);
    CSL_REG32_WR(&pReg->DEV_INSTR_RD_CONFIG_REG, regVal);

    regVal = CSL_REG32_RD(&pReg->DEV_INSTR_WR_CONFIG_REG);

    /* Configure the Device Write Instruction Configuration Register */
    regVal &= ~(CSL_OSPI_FLASH_CFG_DEV_INSTR_WR_CONFIG_REG_WR_OPCODE_FLD_MASK               | \
                CSL_OSPI_FLASH_CFG_DEV_INSTR_WR_CONFIG_REG_DATA_XFER_TYPE_EXT_MODE_FLD_MASK | \
                CSL_OSPI_FLASH_CFG_DEV_INSTR_WR_CONFIG_REG_ADDR_XFER_TYPE_STD_MODE_FLD_MASK | \
                CSL_OSPI_FLASH_CFG_DEV_INSTR_WR_CONFIG_REG_DUMMY_WR_CLK_CYCLES_FLD_MASK);
    regVal |= ((uint32_t)gNorWrCmd << CSL_OSPI_FLASH_CFG_DEV_INSTR_WR_CONFIG_REG_WR_OPCODE_FLD_SHIFT) | \
              (xferLines << CSL_OSPI_FLASH_CFG_DEV_INSTR_WR_CONFIG_REG_ADDR_XFER_TYPE_STD_MODE_FLD_SHIFT) | \
              (xferLines << CSL_OSPI_FLASH_CFG_DEV_INSTR_WR_CONFIG_REG_DATA_XFER_TYPE_EXT_MODE_FLD_SHIFT);
    CSL_REG32_WR(&pReg->DEV_INSTR_WR_CONFIG_REG, regVal);

    /* Set read capture delay */
    status += OSPI_setRdDataCaptureDelay(handle, 0);
    return status;
}

int32_t OSPI_norFlashWaitReady(OSPI_Handle handle, uint32_t timeOut)
{
    int32_t status = SystemP_SUCCESS;

    uint8_t readStatus = 0U;
    uint8_t cmd;

    cmd = OSPI_NOR_CMD_RDSR;

    status = OSPI_norFlashCmdRead(handle, cmd, &readStatus, 1);

    while((status != SystemP_SUCCESS) || timeOut > 0)
    {
        status = OSPI_norFlashCmdRead(handle, cmd, &readStatus, 1);

        if((status == SystemP_SUCCESS) && ((readStatus & OSPI_NOR_SR_WIP) == 0))
        {
            break;
        }

        timeOut--;
    }

    if((readStatus & OSPI_NOR_SR_WIP)==0)
    {
        status = SystemP_SUCCESS;
    }
    else
    {
        status = SystemP_FAILURE;
    }
    return status;
}

int32_t OSPI_norFlashWaitReadyAsync(OSPI_Handle handle, uint32_t timeOut)
{
    int32_t status = SystemP_SUCCESS;

    uint8_t readStatus = 0U;
    uint8_t cmd;

    cmd = OSPI_NOR_CMD_RDSR;

    status = OSPI_norFlashCmdRead(handle, cmd, &readStatus, 1);
    if((status == SystemP_SUCCESS) && ((readStatus & OSPI_NOR_SR_WIP) == 0))
    {
        status = SystemP_SUCCESS;
    }
    else
    {
        timeOut--;
        if(timeOut == 0)
        {
            status = SystemP_FAILURE;
        }
    }
    return status;
}

int32_t OSPI_norFlashReadId(OSPI_Handle handle, uint32_t *manufacturerId, uint32_t *deviceId)
{
    int32_t status = SystemP_SUCCESS;

    uint8_t cmd = OSPI_NOR_CMD_RDID;
    uint8_t idCode[3] = { 0 };

    status += OSPI_norFlashCmdRead(handle, cmd, idCode, 3);

    if(status == SystemP_SUCCESS)
    {
        *manufacturerId = (uint32_t)idCode[0];
        *deviceId = ((uint32_t)idCode[1] << 8) | ((uint32_t)idCode[2]);
    }
    return status;
}

int32_t OSPI_norFlashWrite(OSPI_Handle handle, uint32_t offset, uint8_t *buf, uint32_t len)
{
    int32_t status = 0;

    /* Check offset alignment */
    if(0 != (offset % 256))
    {
        status = SystemP_FAILURE;
    }
    if(status == SystemP_SUCCESS)
    {
        uint32_t pageSize, chunkLen, actual;
        OSPI_Transaction transaction;

        pageSize = 256;
        chunkLen = pageSize;

        for (actual = 0; actual < len; actual += chunkLen)
        {
            status = OSPI_norFlashCmdWrite(handle, OSPI_NOR_CMD_WREN, 0xFFFFFFFF, NULL, 0);

            if(status == SystemP_SUCCESS)
            {
                status = OSPI_norFlashWaitReady(handle, OSPI_NOR_WRR_WRITE_TIMEOUT);
            }

            if(status == SystemP_SUCCESS)
            {
                /* Send Page Program command */
                if((len - actual) < (pageSize))
                {
                    chunkLen = (len - actual);
                }
                else
                {
                    chunkLen = pageSize;
                }

                OSPI_Transaction_init(&transaction);
                transaction.addrOffset = offset;
                transaction.buf = (void *)(buf + actual);
                transaction.count = chunkLen;
                status = OSPI_writeIndirect(handle, &transaction);
            }

            if(status == SystemP_SUCCESS)
            {
                status = OSPI_norFlashWaitReady(handle, OSPI_NOR_WRR_WRITE_TIMEOUT);
            }

            if(status == SystemP_SUCCESS)
            {
                offset += chunkLen;
            }
            else
            {
                break;
            }
        }
        if(status == SystemP_SUCCESS)
        {
            OSPI_EnableDAC(handle); /*enabled dac after write*/
        }
    }
    return status;
}

int32_t OSPI_norFlashRead(OSPI_Handle handle, uint32_t offset, uint8_t *buf, uint32_t len)
{
    int32_t status = SystemP_SUCCESS;

    OSPI_Transaction transaction;

    OSPI_Transaction_init(&transaction);
    transaction.addrOffset = offset;
    transaction.buf = (void *)buf;
    transaction.count = len;
    status = OSPI_readDirect(handle, &transaction);
    return status;
}

int32_t OSPI_norFlashErase(OSPI_Handle handle, uint32_t address)
{
    int32_t status = SystemP_SUCCESS;

    status = OSPI_norFlashWaitReady(handle, OSPI_NOR_WRR_WRITE_TIMEOUT);
    
    if(status == SystemP_SUCCESS)
    {
        status = OSPI_norFlashCmdWrite(handle, OSPI_NOR_CMD_WREN, 0xFFFFFFFF, NULL, 0);
    }
    if(status == SystemP_SUCCESS)
    {
        status = OSPI_norFlashWaitReady(handle, OSPI_NOR_WRR_WRITE_TIMEOUT);
    }
    if(status == SystemP_SUCCESS)
    {
        status = OSPI_norFlashCmdWrite(handle, gNorErCmd, address, NULL, 0);
    }
    if(status == SystemP_SUCCESS)
    {
        status = OSPI_norFlashWaitReady(handle, OSPI_NOR_WRR_WRITE_TIMEOUT);
    }
    return status;
}

/* Internal function definitions */
static int32_t OSPI_programInstance(OSPI_Config *config)
{
    int32_t status = SystemP_SUCCESS;

    uint32_t regVal, chipSelect, decSelect, devDelay;
    OSPI_Handle handle = (OSPI_Handle)config;
    const OSPI_Attrs *attrs = config->attrs;
    OSPI_Object *obj = config->object;
    const CSL_ospi_flash_cfgRegs *pReg = (const CSL_ospi_flash_cfgRegs *)attrs->baseAddr;
    uint32_t tsclk, cssot, csset, csdads, csda;
    
    /* Do the register programming to set the modes from the config */
    /* Optimal programming setup */
    /* Disable DAC */
    CSL_REG32_FINS(&pReg->CONFIG_REG,
                   OSPI_FLASH_CFG_CONFIG_REG_ENB_DIR_ACC_CTLR_FLD,
                   0);
                   /* Disable DTR */
                   CSL_REG32_FINS(&pReg->CONFIG_REG,
                    OSPI_FLASH_CFG_CONFIG_REG_ENABLE_DTR_PROTOCOL_FLD,
                    0);
                    CSL_REG32_FINS(&pReg->DEV_INSTR_RD_CONFIG_REG,
                        OSPI_FLASH_CFG_DEV_INSTR_RD_CONFIG_REG_DDR_EN_FLD,
                        0);
                        /* Disable XIP */
                        CSL_REG32_FINS(&pReg->CONFIG_REG,
                            OSPI_FLASH_CFG_CONFIG_REG_ENTER_XIP_MODE_FLD,
                            0);
                            /* Disable OSPI Controller */
                            CSL_REG32_FINS(&pReg->CONFIG_REG,
                                OSPI_FLASH_CFG_CONFIG_REG_ENB_SPI_FLD,
                                0);
                                /* Wait until Serial Interface and OSPI pipeline is IDLE. */
    if (OSPI_waitIdle(handle, OSPI_READ_WRITE_TIMEOUT) != (int32_t)0U)
    {
        OSPI_close(handle);
        status = SystemP_FAILURE;
    }
    
    if(SystemP_SUCCESS == status)
    {
        /* User config */
        if(TRUE == attrs->intrEnable)
        {
            /* When callback is supported, add logic */
        }
        else
        {
            obj->transferMode = OSPI_TRANSFER_MODE_POLLING;
        }
        /* Chip Select */
        regVal = CSL_REG32_RD(&pReg->CONFIG_REG);
        chipSelect = OSPI_CHIP_SELECT(attrs->chipSelect);
        decSelect = attrs->decChipSelect;

        regVal &= ~(CSL_OSPI_FLASH_CFG_CONFIG_REG_PERIPH_SEL_DEC_FLD_MASK | \
                    CSL_OSPI_FLASH_CFG_CONFIG_REG_PERIPH_CS_LINES_FLD_MASK);
        regVal |= (decSelect << CSL_OSPI_FLASH_CFG_CONFIG_REG_PERIPH_SEL_DEC_FLD_SHIFT) | \
                  (chipSelect << CSL_OSPI_FLASH_CFG_CONFIG_REG_PERIPH_CS_LINES_FLD_SHIFT);
        CSL_REG32_WR(&pReg->CONFIG_REG, regVal);
        /* Frame format */
        regVal = CSL_REG32_RD(&pReg->CONFIG_REG);
        regVal &= ~(CSL_OSPI_FLASH_CFG_CONFIG_REG_SEL_CLK_PHASE_FLD_MASK | \
                    CSL_OSPI_FLASH_CFG_CONFIG_REG_SEL_CLK_POL_FLD_MASK);
        regVal |= (attrs->frmFmt);
        CSL_REG32_WR(&pReg->CONFIG_REG, regVal);
        /* Disable the adapted loop-back clock circuit */
        CSL_REG32_FINS(&pReg->RD_DATA_CAPTURE_REG,
                   OSPI_FLASH_CFG_RD_DATA_CAPTURE_REG_BYPASS_FLD,
                   1);
        /* Delay Setup */
        tsclk = OSPI_DIV_ROUND_UP(attrs->inputClkFreq, OSPI_MAX_OPERATING_FREQUENCY);
        cssot = OSPI_calculateTicksForns(attrs->inputClkFreq, CSL_OSPI_DEV_DELAY_CSSOT_NS);

        if(cssot < tsclk)
        {
            cssot = tsclk;
        }
        cssot = 0;
        csset = 0;//OSPI_calculateTicksForns(attrs->inputClkFreq, CSL_OSPI_DEV_DELAY_CSEOT_NS);
        csdads = 0;//OSPI_calculateTicksForns(attrs->inputClkFreq, CSL_OSPI_DEV_DELAY_CSDADS_NS);
        csda = 3;//OSPI_calculateTicksForns(attrs->inputClkFreq, CSL_OSPI_DEV_DELAY_CSDA_NS);

        devDelay = ((cssot << CSL_OSPI_FLASH_CFG_DEV_DELAY_REG_D_INIT_FLD_SHIFT)  | \
                      (csset << CSL_OSPI_FLASH_CFG_DEV_DELAY_REG_D_AFTER_FLD_SHIFT) | \
                      (csdads << CSL_OSPI_FLASH_CFG_DEV_DELAY_REG_D_BTWN_FLD_SHIFT)  | \
                      (csda << CSL_OSPI_FLASH_CFG_DEV_DELAY_REG_D_NSS_FLD_SHIFT));
        CSL_REG32_WR(&pReg->DEV_DELAY_REG, devDelay);

        if(attrs->baudRateDiv != 0u)
        {
            CSL_REG32_FINS(&pReg->CONFIG_REG,
                   OSPI_FLASH_CFG_CONFIG_REG_MSTR_BAUD_DIV_FLD,
                   CSL_OSPI_BAUD_RATE_DIVISOR(attrs->baudRateDiv));
        }
        else
        {

            CSL_REG32_FINS(&pReg->CONFIG_REG,
                   OSPI_FLASH_CFG_CONFIG_REG_MSTR_BAUD_DIV_FLD,
                   CSL_OSPI_BAUD_RATE_DIVISOR_DEFAULT);
        }

        /* Disable PHY pipeline mode */
        CSL_REG32_FINS(&pReg->CONFIG_REG,
                   OSPI_FLASH_CFG_CONFIG_REG_PIPELINE_PHY_FLD,
                   FALSE);

        /* Disable PHY mode by default. This will be later enabled from flash driver */
        CSL_REG32_FINS(&pReg->CONFIG_REG,
                   OSPI_FLASH_CFG_CONFIG_REG_PHY_MODE_ENABLE_FLD,
                   FALSE);
        /*device size*/
        /* Set indirect trigger address register */
        if(attrs->dacEnable)
        {
            CSL_REG32_WR(&pReg->IND_AHB_ADDR_TRIGGER_REG, 0x4000000);
        }
        else
        {
            CSL_REG32_WR(&pReg->IND_AHB_ADDR_TRIGGER_REG, 0);
        }

        /* Disable write completion auto polling */
        CSL_REG32_FINS(&pReg->WRITE_COMPLETION_CTRL_REG,
                       OSPI_FLASH_CFG_WRITE_COMPLETION_CTRL_REG_DISABLE_POLLING_FLD,
                       1);
        /* Set and invalid opcode in the WRITE_COMPLETION_CTRL_REG due to IP limitation */
        CSL_REG32_FINS(&pReg->WRITE_COMPLETION_CTRL_REG,
                       OSPI_FLASH_CFG_WRITE_COMPLETION_CTRL_REG_OPCODE_FLD,
                       OSPI_CMD_INVALID_OPCODE);
        CSL_REG32_FINS(&pReg->WRITE_COMPLETION_CTRL_REG,
                       OSPI_FLASH_CFG_WRITE_COMPLETION_CTRL_REG_POLL_COUNT_FLD,
                       3U);

        /* Disable dual byte opcode. If OSPI boot mode was used, ROM would have set this. This can cause 1s mode applications to fail */
        CSL_REG32_FINS(&pReg->CONFIG_REG, OSPI_FLASH_CFG_CONFIG_REG_DUAL_BYTE_OPCODE_EN_FLD, FALSE);

        /* Set SRAM partition configuration */
        CSL_REG32_WR(&pReg->SRAM_PARTITION_CFG_REG, CSL_OSPI_SRAM_PARTITION_DEFAULT);

        /* Disable and clear the interrupts */
        regVal = CSL_REG32_RD(&pReg->IRQ_MASK_REG);  
        regVal &= ~(CSL_OSPI_INTR_MASK_ALL);
        CSL_REG32_WR(&pReg->IRQ_MASK_REG, regVal);
        CSL_REG32_WR(&pReg->IRQ_STATUS_REG, CSL_OSPI_INTR_MASK_ALL);

        /* Enable/Disable DAC */
        CSL_REG32_FINS(&pReg->CONFIG_REG,
               OSPI_FLASH_CFG_CONFIG_REG_ENB_DIR_ACC_CTLR_FLD,
               attrs->dacEnable);

        /* Initialize read delay and related book-keeping variables */
        OSPI_setRdDataCaptureDelay(config, 0);

        /* Initialise controller to 1s1s1s mode to override any ROM settings */

        /* Set initial protocol to be 1s1s1s */
        OSPI_setProtocol(config, OSPI_FLASH_PROTOCOL(1,1,1,0));
        OSPI_setXferOpCodes(config, 0x03, 0x02);

        /* Set address bytes to 3 */
        OSPI_setNumAddrBytes(config, 3);

        CSL_REG32_FINS(&pReg->DEV_DELAY_REG,
                   OSPI_FLASH_CFG_DEV_DELAY_REG_D_INIT_FLD,
                   10);
        /* Enable OSPI Controller */
        CSL_REG32_FINS(&pReg->CONFIG_REG,
                       OSPI_FLASH_CFG_CONFIG_REG_ENB_SPI_FLD,
                       1);
    }
    return status;
}

static int32_t OSPI_waitIdle(OSPI_Handle handle, uint32_t timeOut)
{
    int32_t status = SystemP_SUCCESS;

    const OSPI_Attrs *attrs = ((OSPI_Config *)handle)->attrs;
    const CSL_ospi_flash_cfgRegs *pReg;
    uint32_t baseAddr = attrs->baseAddr;
    uint32_t               retry = 0U;
    uint32_t               timeOutVal = timeOut;
    uint32_t               delay;

    pReg = (const CSL_ospi_flash_cfgRegs *)baseAddr;

    while (timeOutVal != 0U)
    {
        if (CSL_REG32_FEXT(&pReg->CONFIG_REG,OSPI_FLASH_CFG_CONFIG_REG_IDLE_FLD) != 0U)
        {
            retry++;
            if (retry == 3U)
            {
                status = SystemP_SUCCESS;
                break;
            }
        }
        else
        {
            retry = 0U;
        }
        delay = OSPI_CHECK_IDLE_DELAY;
        while(delay--);
        timeOutVal--;
    }
    return status;
}

static uint8_t OSPI_getCmdExt(OSPI_Handle handle, uint8_t cmd)
{
    uint8_t cmdExt = OSPI_CMD_INVALID_OPCODE;

    if(NULL != handle)
    {
        OSPI_Object *obj = ((OSPI_Config *)handle)->object;

        switch(obj->cmdExtType)
        {
            case OSPI_CMD_EXT_TYPE_REPEAT:
                cmdExt = cmd;
                break;
            case OSPI_CMD_EXT_TYPE_INVERSE:
                cmdExt = ~cmd;
                break;
            case OSPI_CMD_EXT_TYPE_NONE:
                cmdExt = OSPI_CMD_INVALID_OPCODE;
                break;
            default:
                cmdExt = OSPI_CMD_INVALID_OPCODE;
                break;
        }
    }
    return cmdExt;
}

static uint32_t OSPI_utilLog2(uint32_t num)
{
    /* LUT based bit scan method using deBruijn(2, 5) sequence to avoid the loop */
    uint32_t ret = 0U;

    uint32_t temp = num;

    if(num != 0)
    {
        /* Assume num is not power of 2, fill 1's after the most significant 1 */
        temp |= (temp >> 1U);
        temp |= (temp >> 2U);
        temp |= (temp >> 4U);
        temp |= (temp >> 8U);
        temp |= (temp >> 16U);

        /* 0x07C4ACDD is a modified deBruijn sequence */
        ret = (uint32_t)gTable[(uint32_t)((temp * 0x07C4ACDD) >> 27U)];
    }
    return ret;
}


static int32_t OSPI_flashExecCmd(const CSL_ospi_flash_cfgRegs *pReg)
{
    int32_t  retVal = 0;

    uint32_t retry = OSPI_READ_WRITE_TIMEOUT;
    uint32_t idleFlag = 0;
    uint32_t  delay;

    while (idleFlag == 0)
    {
        idleFlag = CSL_REG32_FEXT(&pReg->CONFIG_REG,
                                  OSPI_FLASH_CFG_CONFIG_REG_IDLE_FLD);
    }

    /* Start to execute flash read/write command */
    CSL_REG32_FINS(&pReg->FLASH_CMD_CTRL_REG,
                   OSPI_FLASH_CFG_FLASH_CMD_CTRL_REG_CMD_EXEC_FLD,
                   1);


    while (retry != 0U)
    {
        /* Check the command execution status
         * If the execution is complete, this bit field will be zero
         */
        uint32_t execCompleteFlag = CSL_REG32_FEXT(&pReg->FLASH_CMD_CTRL_REG,
                       OSPI_FLASH_CFG_FLASH_CMD_CTRL_REG_CMD_EXEC_STATUS_FLD);

        if (execCompleteFlag == 0)
        {
            break;
        }
        delay = OSPI_CHECK_IDLE_DELAY;
        while(delay--);
        retry--;
    }

    if (retry == 0U)
    {
        retVal = -1;
    }

    idleFlag = 0;
    while (idleFlag == 0)
    {
        idleFlag = CSL_REG32_FEXT(&pReg->CONFIG_REG,
                                  OSPI_FLASH_CFG_CONFIG_REG_IDLE_FLD);
    }
    return (retVal);
}

static int32_t OSPI_waitWriteSRAMLevel(const CSL_ospi_flash_cfgRegs *pReg,
                                     uint32_t *sramLvl)
{
    int32_t  retVal = 0;

    uint32_t retry = CSL_OSPI_REG_RETRY;
    uint32_t sramLevel;
    uint32_t delay;

    while(retry != 0U)
    {
        sramLevel = CSL_REG32_RD(&pReg->SRAM_FILL_REG) >> \
            CSL_OSPI_FLASH_CFG_SRAM_FILL_REG_SRAM_FILL_INDAC_WRITE_FLD_SHIFT;
        if (sramLevel <= CSL_OSPI_SRAM_WATERMARK_WR_LVL)
        {
            *sramLvl = sramLevel;
            break;
        }
        delay = CSL_OSPI_POLL_IDLE_DELAY;
        while(delay--);
        retry--;
    }

    if (retry != 0U)
    {
        retVal = 0;
    }
    else
    {
        retVal = (int32_t)(-1);
    }
    return(retVal);
}

static int32_t OSPI_waitIndWriteComplete(const CSL_ospi_flash_cfgRegs *pReg)
{
    int32_t  retVal = 0;

    uint32_t retry = OSPI_READ_WRITE_TIMEOUT;
    uint32_t regVal = 0U;
    uint32_t delay;

    /* Check flash indirect write controller status */
    while (retry != 0U)
    {
        regVal = CSL_REG32_FEXT(&pReg->INDIRECT_WRITE_XFER_CTRL_REG,
                         OSPI_FLASH_CFG_INDIRECT_WRITE_XFER_CTRL_REG_IND_OPS_DONE_STATUS_FLD);
        if (regVal == 1)
        {
            break;
        }
        delay = OSPI_CHECK_IDLE_DELAY;
        while(delay--);
        retry--;
    }

    if (retry != 0U)
    {
        /* Clear indirect completion status */
        CSL_REG32_FINS(&pReg->INDIRECT_WRITE_XFER_CTRL_REG,
                   OSPI_FLASH_CFG_INDIRECT_WRITE_XFER_CTRL_REG_IND_OPS_DONE_STATUS_FLD,
                   1);
        retVal = 0;
    }
    else
    {
        retVal = -1;
    }
    return(retVal);
}

static void OSPI_writeFifoData(uintptr_t indAddr, const uint8_t *src, uint32_t wrLen)
{

    uint32_t temp = 0;
    uint32_t remaining = wrLen;
    uint32_t *srcPtr = (uint32_t *)src;

    while (remaining > 0)
    {
        if (remaining >= CSL_OSPI_FIFO_WIDTH)
        {
            CSL_REG32_WR(indAddr, *srcPtr);
            remaining -= CSL_OSPI_FIFO_WIDTH;
        }
        else
        {
            /* dangling bytes */
            memcpy(&temp, srcPtr, remaining);
            CSL_REG32_WR(indAddr, temp);
            break;
        }
        srcPtr++;
    }
}


static void Ospi_memcpyWord(uint8_t *source, uint8_t *destination, uint32_t length)
{

    if((((uintptr_t)source % PTR_COPY_SRC_ALIGNMENT) == ((uintptr_t)destination % PTR_COPY_SRC_ALIGNMENT)) ||
       ((length % PTR_COPY_SRC_ALIGNMENT) != 0))
    {
        uint8_t *temp8Src = source;
        uint8_t *temp8Dst = destination;
        uintptr_t *tempSrc = (uintptr_t *)source;
        uintptr_t *tempDst = (uintptr_t *)destination;
        uint32_t remainingBytes = length, i;
        uint32_t unalignedBytes;

        /* Check for Byte alignment of source address */
        if(((uintptr_t)source % PTR_COPY_SRC_ALIGNMENT) != 0)
        {
            uint32_t initResidualBytes = PTR_COPY_SRC_ALIGNMENT - (((uintptr_t)source) % PTR_COPY_SRC_ALIGNMENT);
            i = initResidualBytes;

            /* Do 8-bit pointer copy for initial unaligned bytes*/
            while(i != 0)
            {
                *temp8Dst = *temp8Src;
                temp8Src++;
                temp8Dst++;
                i--;
            }

            tempDst = (uintptr_t *)((uintptr_t)destination + initResidualBytes);
            tempSrc = (uintptr_t *)((uintptr_t)source + initResidualBytes);
            remainingBytes -= initResidualBytes;
        }

        /* Do pointer copy for aligned bytes */
        unalignedBytes = remainingBytes % PTR_COPY_SRC_ALIGNMENT;
        i = (remainingBytes - unalignedBytes) / PTR_COPY_SRC_ALIGNMENT ;

        while(i != 0)
        {
            *tempDst = *tempSrc;
            tempSrc++;
            tempDst++;
            i--;
        }

        /* Do 8-bit pointer copy for unaligned bytes if any */
        if(unalignedBytes > 0)
        {
            temp8Dst = (uint8_t *)tempDst;
            temp8Src = (uint8_t *)tempSrc;
            i = unalignedBytes;
            while(i != 0)
            {
                *temp8Dst = *temp8Src;
                temp8Src++;
                temp8Dst++;
                i--;
            }
        }
    }
    else
    {
        memcpy(destination, source, length);
    }
}
