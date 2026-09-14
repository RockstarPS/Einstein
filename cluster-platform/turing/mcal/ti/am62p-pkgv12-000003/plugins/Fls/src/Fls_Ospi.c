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
 *  \file   Fls_OSPI.c
 *
 *  \brief  OSPI  specific driver APIs implementation.
 *
 *   This file contains the driver APIs for OSPI controller.
 */


 /* ========================================================================== */
 /*                             Include Files                                  */
 /* ========================================================================== */
 #include "Std_Types.h"
 #include "Std_Types.h"
 #include <hw_include/arch/lld_arch.h>
 #include "Fls_Ospi.h"
 #include "Fls_Brd_Nor.h"
 #include "Fls_Cfg.h"
 #include <SchM_Fls.h>
 #include "Os.h"
 
 
 
 /* ========================================================================== */
 /*                           Macros & Typedefs                                */
 /* ========================================================================== */
 
 
 #define OSPI_DAC_WRITE_TIMEOUT      (500000U)
 #define OSPI_CHECK_IDLE_DELAY       (10U)
 #define OSPI_CALIBRATE_DELAY        (20U)
 #define OSPI_XIP_SETUP_DELAY        (250U)
 
 #define OSPI_PHY_DLL_ELEM_DELAY_PERIOD   (80U)  /* worst delay element periord in ps */
 
 #define SPI_OSPI_PER_CNT (1U)
 #define FLS_WORD_ALIGNMENT                  (4U)
 
 /* ========================================================================== */
 /*                         Structures and Enums                               */
 /* ========================================================================== */
 
 typedef enum OSPI_intrPollMode_s
 {
     SPI_OPER_MODE_POLLING,
     /**< Non interrupt based blocking mode */
     SPI_OPER_MODE_CALLBACK
     /**< Interrupt based call back mode */
 } OSPI_intrPollMode;
 
 /* OSPI objects */
 OSPI_Object OspiObjects[SPI_OSPI_PER_CNT + 1U];

#define FLS_START_SEC_VAR_NO_INIT_8
#include "Fls_MemMap.h"
 uint8 Fls_ReadWriteBuffer[FLS_READ_WRITE_BUF_LEN + 2U];
#define FLS_STOP_SEC_VAR_NO_INIT_8
#include "Fls_MemMap.h"
 
 /* Default SPI parameters structure */
 const SPI_Params SPI_defaultParams = {
     SPI_MODE_CALLBACK,  /* transferMode */
     0U,                 /* transferTimeout */
     SPI_MASTER,         /* mode */
     1000000,            /* bitRate */
     8,                  /* dataSize */
     SPI_POL0_PHA0,      /* frameFormat */
     0               /* custom */
 };
 
 /* SPI configuration structure */
 CSL_PUBLIC_CONST SPI_config_list SPI_config = {
     {
         &OspiObjects[0]
     },
     {
         NULL
     }
 };
 uint32 devDelays[4]={0,0,0,0x2};
 /**< OSPI device delays (CSSOT, CSEOT, CSDADS and CSDA delays) */
 boolean tuneDone;
 /* ========================================================================== */
 /*                 Internal Function Declarations                             */
 /* ========================================================================== */
 
 static Std_ReturnType    OSPI_primeTransfer(SPI_Handle handle,
                                         SPI_Transaction *transaction);
 static Std_ReturnType    OSPI_waitIdle(SPI_Handle handle, uint32 timeOut);
 static Std_ReturnType    OSPI_flashExecCmd(const CSL_ospi_flash_cfgRegs *pRegs);
 static Std_ReturnType    OSPI_read(SPI_Handle handle, SPI_Transaction *transaction);
 static Std_ReturnType    OSPI_cmdRead(const CSL_ospi_flash_cfgRegs *pRegs,
                                uint32                      cmd,
                                uint8                      *rxBuf,
                                uint32                      rxLen);
 static Std_ReturnType    OSPI_cmdExtRead(const CSL_ospi_flash_cfgRegs *pRegs,
                               uint8                      *cmd,
                               uint32                      cmdLen,
                               uint8                      *rxBuf,
                               uint32                      rxLen,
                               uint32                      dummyCycles);
 static Std_ReturnType    OSPI_write(SPI_Handle handle, SPI_Transaction *transaction);
 static Std_ReturnType    OSPI_cmdWrite(const CSL_ospi_flash_cfgRegs *pRegs,
                                 const uint8                *cmdBuf,
                                 uint32                      cmdLen,
                                 uint8                		*txBuf,
                                 uint32                      txLen);
 static Std_ReturnType    OSPI_waitReadSramLvl(const CSL_ospi_flash_cfgRegs *pReg,
                                        uint32 *rdLevel);
 static Std_ReturnType    OSPI_ind_xfer_mode_read(SPI_Handle handle,
                                              SPI_Transaction *transaction);
 static Std_ReturnType    OSPI_waitIndWriteComplete(const CSL_ospi_flash_cfgRegs *pRegs);
 static Std_ReturnType    OSPI_waitWriteSramLvl(const CSL_ospi_flash_cfgRegs *pReg,
                                         uint32 *sramLvl);
 static Std_ReturnType    OSPI_ind_xfer_mode_write(SPI_Handle handle,
                                               SPI_Transaction *transaction);
 static Std_ReturnType    OSPI_dac_xfer_mode_read(SPI_Handle handle,
                                              const SPI_Transaction *transaction);
 static Std_ReturnType    OSPI_dac_xfer_mode_write(SPI_Handle handle,
                                               const SPI_Transaction *transaction);
 static Std_ReturnType    OSPI_cmd_mode_write(SPI_Handle handle,
                                          const SPI_Transaction *transaction);
 static Std_ReturnType    OSPI_cmd_mode_read(SPI_Handle handle,
                                         SPI_Transaction *transaction);
 //static void   OSPI_configPhy(SPI_Handle handle, const void *pDelay);
 static Std_ReturnType OSPI_configDdr(SPI_Handle handle, uint32 cmd, uint32 addr, uint32 data);
 static boolean OSPI_waitDeviceReady(SPI_Handle handle, uint32 timeOut);
 static void Fls_delay(uint32 msecs);

 /* ========================================================================== */
 /*                          Function Definitions                              */
 /* ========================================================================== */
 
 
 #define FLS_START_SEC_CODE
 #include "Fls_MemMap.h"
 
 static void OSPI_delay(uint32 delay);
 static void OSPI_delay(uint32 delay)
 {
     volatile uint32 i = delay;
 
     while (i > 0U)
     {
         i = i - 1U;
     }
 }
 

 /**
* TI_COVERAGE_GAP_START [Branch Coverage] Dynamic coverage for the function is 0%. This is added incase sram
  *level is greater than watermark level and cannot be covered.

* TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed from the inspection review.
*/
 static void Fls_delay(uint32 msecs)
 {
     volatile uint32 tempCount = 1000000U * msecs;

     /* Each unit of MCAL_SW_DELAY() equals ~9 clock cycles,
        so we scale tempCount accordingly */
     if (msecs > 9U) 
     {
         tempCount = msecs / 9U;
     }
 
     /* Wait for the delay to complete */
     do 
     {
         if (tempCount == 0U) 
         {
             /* Timeout reached */
             break;
         }
         MCAL_SW_DELAY(tempCount);
     } while (tempCount > 0U);
 }
 /* TI_COVERAGE_GAP_STOP */

 /*
  *  ======== OSPI_hwi ========
  *  Hwi interrupt handler to service the OSPI peripheral
  *
  *  The handler is a generic handler for a OSPI object.
  */
 void OSPI_hwi(SPI_Handle handle)
 {
     uint32               intrStatus;
     OSPI_Object        *object =(OSPI_Object *)NULL;
     uint32               sramLevel = 0, rdBytes = 0, wrBytes = 0;
 
     if (handle != NULL_PTR)
     {
         /* Get the pointer to the object and hwAttrs */
         object = (OSPI_Object *)(handle->object);
 
         /* Read the interrupt status register */
         intrStatus = CSL_ospiIntrStatus((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR));
 
         if (object->readBufIdx != NULL_PTR)
         {
             /* Indirect read operation */
             if ((intrStatus & CSL_OSPI_INTR_MASK_IND_XFER) != 0U)
             {
                 if(object->readCountIdx != 0U)
                 {
                     do
                     {
                         sramLevel = CSL_ospiGetSramLvl((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR), 1U);
                         if (sramLevel != 0U)
                         {
                             rdBytes = sramLevel * CSL_OSPI_FIFO_WIDTH;
                             rdBytes = (rdBytes > (uint32)object->readCountIdx) ? (uint32)object->readCountIdx : rdBytes;
                             /* Read data from FIFO */
                             CSL_ospiReadFifoData((FLS_BASE_ADDRESS), (uint8 *)object->readBufIdx, rdBytes);
 
                             object->readBufIdx += rdBytes;
                             object->readCountIdx -= rdBytes;
                         }
                     } while(sramLevel != 0U);
 
                     if (((uint32)object->readCountIdx > 0U) &&
                         ((uint32)object->readCountIdx < (CSL_OSPI_SRAM_WARERMARK_RD_LVL * CSL_OSPI_FIFO_WIDTH)))
                     {
 
                         do
                         {
                             sramLevel = CSL_ospiGetSramLvl((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR), 1U);
                             rdBytes = sramLevel * CSL_OSPI_FIFO_WIDTH;
                         } while (rdBytes < object->readCountIdx);
 
                         rdBytes = object->readCountIdx;
                         CSL_ospiReadFifoData((FLS_BASE_ADDRESS), object->readBufIdx, rdBytes);
                         object->readBufIdx += rdBytes;
                         object->readCountIdx -= rdBytes;
                     }
                 }
 
                 if((object->readCountIdx == 0U) || ((intrStatus & CSL_OSPI_INTR_MASK_IND_OP_DONE) != 0U))
                 {
                     /* Clear indirect read operation complete status */
                     CSL_ospiClrIndReadComplete((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR));
 
                     /* disable and clear the interrupts */
                     CSL_ospiIntrEnable((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR),
                                         CSL_OSPI_INTR_MASK_ALL,
                                         FALSE);
                     CSL_ospiIntrClear((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR),
                                     CSL_OSPI_INTR_MASK_ALL);
 
                     object->transaction = (SPI_Transaction *)NULL;
 
                     if (Fls_DrvObj.length != 0U)
                     {
                         processJobs(Fls_DrvObj.jobType);
                     }
                 }
                 else
                 {
                     /* Clear interrupt status */
                     CSL_ospiIntrClear((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR), intrStatus);
                 }
             }
         }
         else
         {
             /* Indirect write operation */
             if ((intrStatus & CSL_OSPI_INTR_MASK_IND_XFER) != 0U)
             {
                 if (object->writeCountIdx != 0U)
                 {
                     sramLevel = CSL_OSPI_SRAM_PARTITION_WR - \
                                 CSL_ospiGetSramLvl((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR), 0U);
 
                     wrBytes = sramLevel * CSL_OSPI_FIFO_WIDTH;
                     wrBytes = (wrBytes > object->writeCountIdx) ? object->writeCountIdx : wrBytes;
 
                     /* Write data to FIFO */
                     CSL_ospiWriteFifoData((FLS_BASE_ADDRESS), object->writeBufIdx, wrBytes);
 
                     object->writeBufIdx += wrBytes;
                     object->writeCountIdx -= wrBytes;
 
                     sramLevel = CSL_OSPI_SRAM_PARTITION_WR - \
                                 CSL_ospiGetSramLvl((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR), 0U);
 
                     if ((object->writeCountIdx > 0U) &&
                         (object->writeCountIdx <= (sramLevel * CSL_OSPI_FIFO_WIDTH)))
                     {
                         wrBytes = object->writeCountIdx;
                         CSL_ospiWriteFifoData((FLS_BASE_ADDRESS), object->writeBufIdx, wrBytes);
                         object->writeBufIdx += wrBytes;
                         object->writeCountIdx -= wrBytes;
                     }
                 }
 
                 if ((intrStatus & CSL_OSPI_INTR_MASK_IND_OP_DONE) != 0U)
                 {
                     /* Clear indirect write operation complete status */
                     CSL_ospiClrIndWriteComplete((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR));
 
                     /* disable and clear the interrupts */
                     CSL_ospiIntrEnable((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR),
                                         CSL_OSPI_INTR_MASK_ALL,
                                         FALSE);
                     CSL_ospiIntrClear((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR),
                                     CSL_OSPI_INTR_MASK_ALL);
                     object->transaction = (SPI_Transaction *)NULL;
 
                     if (Fls_DrvObj.length != 0U)
                     {
                         processJobs(Fls_DrvObj.jobType);
                     }
                 }
                 else
                 {
                     /* Clear interrupt status */
                     CSL_ospiIntrClear((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR), intrStatus);
                 }
             }
         }
     }
     return;
 }
 
 /*
  *  ======== OSPI_close ========
  */
  void Fls_OSPI_close(SPI_Handle handle)
 {
     OSPI_Object        *object = (OSPI_Object *)NULL;
 
     if (handle != NULL)
     {
         /* Get the pointer to the object and hwAttrs */
         object = (OSPI_Object *)handle->object;
 
         /* disable the interrupts */
         CSL_ospiIntrEnable((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR),
                         CSL_OSPI_INTR_MASK_ALL,
                         FALSE);
 
         /* Open flag is set FALSE */
         object->isOpen = FALSE;
     }
 
     return;
 }
 
 /*
  *  ======== OSPI_init ========
  */

 void Fls_OSPI_init(SPI_Handle handle)
 {
     if (handle != NULL_PTR)
     {
         /* Mark the object as available */
         OSPI_Object *ospi_Obj;
         ospi_Obj = (OSPI_Object *)(handle->object);
         ospi_Obj->isOpen = FALSE;
     }
 }
 

 static Std_ReturnType OSPI_waitIdle(SPI_Handle handle, uint32 timeOut)
 {
     uint32               retry = 0U;
     Std_ReturnType     retVal = E_NOT_OK;
     uint32               timeOutVal = timeOut;
 
    /* Get the pointer to the object and hwAttrs */
     while (timeOutVal != 0U)
     {
         if (CSL_ospiIsIdle((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR)) != 0U)
         {
             retry++;
             if (retry == 3U)
             {
                 retVal = E_OK;
                 break;
             }
         }
         else
         /**
        * TI_COVERAGE_GAP_START [Branch Coverage] Dynamic coverage for this condition timeOutVal != 0U
        is not achievable for the false case because he timeout is provided via macro OSPI_DAC_WRITE_TIMEOUT,
        but the function does not decrement or otherwise modify timeOutVal.

        * TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed from the inspection review.
        */
         {
             retry = 0U;
         }
         /* TI_COVERAGE_GAP_STOP */
         OSPI_delay(OSPI_CHECK_IDLE_DELAY);
         timeOutVal--;
     }
 
     return (retVal);
 }

 void OSPI_setsinglemode(void)
{
    const CSL_ospi_flash_cfgRegs *pReg = (CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR);
    /*Setting default cfg and SDR mode*/
    CSL_ospiSetPreScaler(pReg, CSL_OSPI_BAUD_RATE_DIVISOR_DEFAULT);
    /* Disable dual byte opcode. If OSPI boot mode was used, ROM would have set this. This can cause 1s mode applications to fail */
    CSL_ospiSetDualByteOpcodeMode(pReg, FALSE);
    /* Delay Setup */
    LLD_REG32_WR(&pReg->DEV_DELAY_REG, OSPI_DELAY_ZERO);

    /* sampled on rising edge of the ref_clk */
    LLD_REG32_FINS(&pReg->RD_DATA_CAPTURE_REG,
    OSPI_FLASH_CFG_RD_DATA_CAPTURE_REG_SAMPLE_EDGE_SEL_FLD,
    0UL);
    LLD_REG32_FINS(&pReg->RD_DATA_CAPTURE_REG,
    OSPI_FLASH_CFG_RD_DATA_CAPTURE_REG_DELAY_FLD,
    OSPI_RDDATA_CAPDELAY);
    CSL_ospiLoopbackClkEnable((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR),
    FALSE);
    
    return;
}
 
 /*
  *  ======== OSPI_open ========
  */
 SPI_Handle Fls_OSPI_open(SPI_Handle handle, const SPI_Params *params)
 {
     SPI_Handle               retHandle = handle;
     OSPI_Object              *object =(OSPI_Object *)NULL;
     sint32                    retFlag = 0;
     uint32                numAddrBytes;
     const CSL_ospi_flash_cfgRegs *pReg = (CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR);
     uint8 flashIdx = Fls_DrvObj.Fls_flashIndex;
     const FlashConfig *flsNorDevicePtr = &FlsNorDevice.flscfg[flashIdx];
 
     if (NULL == handle)
     {
         retHandle = (SPI_Handle) NULL; /*if SPI handle is NULL, return NULL*/
     }
     else /*if handle != NULL_PTR*/
     {
         /*Setting default cfg and SDR mode*/
         CSL_ospiSetPreScaler(pReg, CSL_OSPI_BAUD_RATE_DIVISOR_DEFAULT);
         /* Disable dual byte opcode. If OSPI boot mode was used, ROM would have set this. This can cause 1s mode applications to fail */
         CSL_ospiSetDualByteOpcodeMode(pReg, FALSE);
         /* Delay Setup */
         LLD_REG32_WR(&pReg->DEV_DELAY_REG, OSPI_DELAY_ZERO);
 
         /* sampled on rising edge of the ref_clk */
         LLD_REG32_FINS(&pReg->RD_DATA_CAPTURE_REG,
                         OSPI_FLASH_CFG_RD_DATA_CAPTURE_REG_SAMPLE_EDGE_SEL_FLD,
                         0UL);
         LLD_REG32_FINS(&pReg->RD_DATA_CAPTURE_REG,
                            OSPI_FLASH_CFG_RD_DATA_CAPTURE_REG_DELAY_FLD,
                            OSPI_RDDATA_CAPDELAY);
         CSL_ospiLoopbackClkEnable((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR),
                                    FALSE);
         /*Set Transfer OpCodes for SDR mode*/
         CSL_ospiConfigRead(pReg, flsNorDevicePtr->NOR_CMD_READ, (uint32)OSPI_XFER_LINES_SINGLE, flsNorDevicePtr->NOR_SINGLE_READ_DUMMY_CYCLE);
         CSL_ospiWriteSetup(pReg, flsNorDevicePtr->NOR_CMD_PAGE_PROG, (uint32)OSPI_XFER_LINES_SINGLE);
 
         /* Get the pointer to the object and hwAttrs */
         object = (OSPI_Object *)handle->object;
         if (object->isOpen == TRUE)
         {
             retHandle = (SPI_Handle) NULL;;
         }
         else
         {
             /* Mark the handle as being used */
             object->isOpen = TRUE;
         }
     }
 
     if (retHandle != NULL)
     {
         SPI_Params_init(&(object->ospiParams)); /*Use default SPI params*/
 
         /* Copy the controller mode from hardware attributes to object */
         object->ospiMode  = (uint32)OSPI_OPER_MODE_CFG;
         object->xferLines = (uint32)Fls_DrvObj.ospixferlines;
         object->hwi       = NULL;
 
         /* Extract OSPI operating mode based on hwAttrs and input parameters */
 #if (STD_ON == FLS_USE_INTERRUPTS)//callback interrupt mode
         object->intrPollMode = (uint32)SPI_OPER_MODE_CALLBACK;
 #else
         object->intrPollMode = (uint32)SPI_OPER_MODE_POLLING;
 #endif
 
         object->transaction = (SPI_Transaction *)NULL;
         /* Disable DAC */
         CSL_ospiDacEnable((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR), FALSE);
 
         /* Disable DTR protocol */
         CSL_ospiDtrEnable((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR), FALSE);
 
         if (Fls_DrvObj.xipEnable == FALSE)
         {
             /* Disable XIP */
             CSL_ospiXipEnable((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR), FALSE);
         }
 
         /* Disable OSPI controller */
         CSL_ospiEnable((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR), FALSE);
 
         /* Wait until Serial Interface and OSPI pipeline is IDLE. */


         /**
        * TI_COVERAGE_GAP_START [Branch Coverage] Dynamic branch coverage for this if cannot be covered because there is
             constant value for OSPI_DAC_WRITE_TIMEOUT macros and OSPI_waitIdle always return E_OK

        * TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed from the inspection review.
        */
         if (OSPI_waitIdle(handle, OSPI_DAC_WRITE_TIMEOUT) != E_OK)
         {
             Fls_OSPI_close(handle);
             retHandle = (SPI_Handle) NULL;
             retFlag = 1;
         }
         /* TI_COVERAGE_GAP_STOP */

         if(retFlag == 0)
         {
             /* Chip select setup */
             CSL_ospiSetChipSelect((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR),
                                   CSL_OSPI_CS0,
                                   CSL_OSPI_DECODER_SELECT4);
 
             /* Set clock mode */
             CSL_ospiSetClkMode((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR),
                                CSL_OSPI_CLK_MODE_0);
 
             /* Set delay in ref_clk cycle for data read capture */
             LLD_REG32_FINS(&pReg->RD_DATA_CAPTURE_REG,
                                OSPI_FLASH_CFG_RD_DATA_CAPTURE_REG_DELAY_FLD,
                                1U);
 
             /* Delay Setup */
             CSL_ospiSetDevDelay((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR),
                                 devDelays);
 
             if (Fls_DrvObj.flsBaudRateDiv != (uint32)0)
             {
                 CSL_ospiSetPreScaler((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR),
                                      CSL_OSPI_BAUD_RATE_DIVISOR(Fls_DrvObj.flsBaudRateDiv));
             }
             else
             {
                /* Set default baud rate divider value */

                /**
                * TI_COVERAGE_GAP_START [Branch Coverage] Dynamic branch coverage for this if cannot be covered because Phy feature is not supported
                   for mpu devices

                * TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed from the inspection review.
                */
                if (Fls_DrvObj.phyEnable == TRUE)
                {
                    CSL_ospiSetPreScaler((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR),
                                         CSL_OSPI_BAUD_RATE_DIVISOR(2U));
                }
                /* TI_COVERAGE_GAP_STOP */
                else
                {
                    /* Disable high speed mode when PHY is disabled */
                    CSL_ospiSetPreScaler((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR),
                                         CSL_OSPI_BAUD_RATE_DIVISOR_DEFAULT);
                }
             }

             /**
             * TI_COVERAGE_GAP_START [Branch Coverage] Dynamic branch coverage for this if cannot be covered because Phy feature is not supported
                for mpu devices

             * TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed from the inspection review.
             */
             if (Fls_DrvObj.phyEnable == TRUE)
             {
                 /* Enable PHY mode */
                 CSL_ospiPhyEnable((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR), TRUE);
 
             }
             /* TI_COVERAGE_GAP_STOP */
             else
             {
                 /* Disable PHY mode */
                 CSL_ospiPhyEnable((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR), FALSE);
             }
 
             /* Disable PHY pipeline mode */
             CSL_ospiPipelinePhyEnable((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR), FALSE);
 
             if (Fls_DrvObj.dtrEnable == TRUE)
             {
                 numAddrBytes = CSL_OSPI_MEM_MAP_NUM_ADDR_BYTES_4;
             }
             else
             {
                 numAddrBytes = CSL_OSPI_MEM_MAP_NUM_ADDR_BYTES_3;
             }
 
             /* Set device size cofigurations */
             CSL_ospiSetDevSize((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR),
                                numAddrBytes,
                                flsNorDevicePtr->NOR_PAGE_SIZE,
                                Fls_DrvObj.blockSize);
 
             /* Set indirect trigger address register */
             if (Fls_DrvObj.dacEnable == TRUE)
             {
                 CSL_ospiSetIndTrigAddr((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR),
                                        0x4000000);
             }
             else
             {
                 CSL_ospiSetIndTrigAddr((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR),
                                        0);
             }
 
             /* Disable write completion auto polling */
             CSL_ospiSetWrCompAutoPolling((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR),
                                          CSL_OSPI_WRITE_COMP_AUTO_POLLING_ENABLE);

             /* Set and invalid opcode in the WRITE_COMPLETION_CTRL_REG due to IP limitation */
             CSL_ospiSetWrCompInvalidOpcode((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR));

             /* Set SRAM partition configuration */
             CSL_ospiSetSramPartition((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR),
                                      CSL_OSPI_SRAM_PARTITION_DEFAULT);
 
             /* disable and clear the interrupts */
             CSL_ospiIntrEnable((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR),
                                 CSL_OSPI_INTR_MASK_ALL,
                                 FALSE);
             CSL_ospiIntrClear((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR),
                               CSL_OSPI_INTR_MASK_ALL);
 
             if (Fls_DrvObj.dacEnable == TRUE)
             {
                 CSL_ospiDacEnable((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR), TRUE);
             }
             else
             {
                 CSL_ospiDacEnable((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR), FALSE);
             }
 
             CSL_ospiSetDataReadCapDelay((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR),
                                         OSPI_RDDATA_CAPDELAY);
             CSL_ospiSetCsSotDelay((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR),
                                   OSPI_CSST_TRASDELAY);
             /* Enable OSPI controller */
             CSL_ospiEnable((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR), TRUE);
         }
     }
 
     return(retHandle);
 }
 
 /*
  *  ======== OSPI_primeTransfer =======
  */

 static Std_ReturnType OSPI_primeTransfer(SPI_Handle handle,
                                      SPI_Transaction *transaction)
 {
     OSPI_Object        *object =(OSPI_Object *)NULL;
     Std_ReturnType      retVal = E_OK;
 
     /* Get the pointer to the object and hwAttrs */
     object = (OSPI_Object *)handle->object;
 
     /* Disable and clear the interrupts */
     CSL_ospiIntrEnable((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR),
                         CSL_OSPI_INTR_MASK_ALL,
                         FALSE);
     CSL_ospiIntrClear((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR),
                       CSL_OSPI_INTR_MASK_ALL);
 
 #if (STD_ON == FLS_USE_INTERRUPTS)
     CSL_ospiIntrEnable((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR),
                    CSL_OSPI_INTR_MASK_ALL,
                    TRUE);
 
 #endif
 
     /* Identify the direction of transfer (whether read/write) */
     if((uint32)SPI_TRANSACTION_TYPE_READ == object->transactionType)
     {
         retVal = (OSPI_read(handle, transaction));
     }
     else if((uint32)SPI_TRANSACTION_TYPE_WRITE == object->transactionType)
     {
         retVal = (OSPI_write(handle, transaction));
     }
     else
     {
         transaction->status = SPI_TRANSFER_CANCELED;
         retVal = E_NOT_OK;
     }
     return(retVal);
 }
 
 static Std_ReturnType OSPI_waitReadSramLvl(const CSL_ospi_flash_cfgRegs *pReg,
                                     uint32 *rdLevel)
 {
     uint32 retry = OSPI_DAC_WRITE_TIMEOUT;
     uint32 sramLevel;
     Std_ReturnType  retVal;
     while(retry != 0U)
     {
         sramLevel = CSL_ospiGetSramLvl(pReg, 1U);

        /**
        * TI_COVERAGE_GAP_START [Branch Coverage] Dynamic branch coverage for this cannot be covered as SRAM level is non zero in the first check itself

        * TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed from the inspection review.
        */
         if (sramLevel != 0U)
         {
             *rdLevel = sramLevel;
             break;
         }
         /* TI_COVERAGE_GAP_STOP */

         /**
         * TI_COVERAGE_GAP_START [Branch Coverage] Dynamic branch coverage for this cannot be covered these are added as part of safety mechanism
             in case of hardware failure and cannot be covered

         * TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed from the inspection review.
         */
         OSPI_delay(OSPI_CHECK_IDLE_DELAY);
         retry--;
         /* TI_COVERAGE_GAP_STOP */
     }
 
     if (retry != 0U)
     {
         retVal = E_OK;
     }
     /**
    * TI_COVERAGE_GAP_START [Branch Coverage] Dynamic Coverage for “else” case cannot be covered as it depends on hadware status register. These are added as part of safety mechanism in case of hardware failure and cannot be covered.

    * TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed from the inspection review.
    */
     else
     {
         retVal = E_NOT_OK;
     }
     /* TI_COVERAGE_GAP_STOP */
     return(retVal);
 }
 

 static Std_ReturnType OSPI_waitIndReadComplete(const CSL_ospi_flash_cfgRegs *pRegs)
 {
     uint32 retry = OSPI_DAC_WRITE_TIMEOUT;
     Std_ReturnType  retVal;
 
     /* Check flash indirect read controller status */
     while (retry != 0U)
     {
         if (CSL_ospiIndReadComplete(pRegs) == TRUE)
         {
             break;
         }

         /**
        * TI_COVERAGE_GAP_START [Branch Coverage] Dynamic branch coverage for this cannot be covered  as these are added as part of safety mechanism
            in case of hardware failure and cannot be covered.

        * TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed from the inspection review.
        */
         OSPI_delay(OSPI_CHECK_IDLE_DELAY);
         retry--;
         /* TI_COVERAGE_GAP_STOP */
     }
     if (retry != 0U)
     {
         /* Clear indirect completion status */
         CSL_ospiClrIndReadComplete(pRegs);
         retVal = E_OK;
     }

     /**
    * TI_COVERAGE_GAP_START [Branch Coverage] Dynamic branch coverage for this cannot be covered  as else” case cannot be covered as it depends on hadware status register.
        These are added as part of safety mechanism in case of hardware failure and cannot be covered.

    * TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed from the inspection review.
    */
     else
     {
         retVal = E_NOT_OK;
     }
     /* TI_COVERAGE_GAP_STOP */
     return(retVal);
 }
 

 static Std_ReturnType OSPI_ind_xfer_mode_read(SPI_Handle handle,
                                             SPI_Transaction *transaction)
{
    OSPI_Object  *object;
    uint8        *pUserDst;
    uint8        *pTmpBuf;
    uint32        offset, count;
    uint32        alignedStart, alignedEnd, alignedLen;
    uint32        remaining, skipBytes;
    uint32        sramLevel = 0U, rdBytes = 0U;
    Std_ReturnType retVal = E_OK;

    object   = (OSPI_Object *)handle->object;
    offset   = (uint32)transaction->arg;
    count    = (uint32)transaction->count;
    pUserDst = (uint8 *)transaction->rxBuf;

    /* -------- Alignment handling -------- */
    alignedStart = offset & ~0x1U;
    alignedEnd   = offset + count;
    if ((alignedEnd & 0x1U) != 0U)
    {
        alignedEnd++;
    }
    alignedLen = alignedEnd - alignedStart;
    skipBytes  = offset - alignedStart;

    pTmpBuf = Fls_ReadWriteBuffer;

    /* Disable DAC mode */
    CSL_ospiDacEnable((CSL_ospi_flash_cfgRegs *)FLS_OSPI_CTRL_BASE_ADDR, FALSE);

    if (Fls_DrvObj.phyEnable == TRUE)
    {
        CSL_ospiPipelinePhyEnable(
            (CSL_ospi_flash_cfgRegs *)FLS_OSPI_CTRL_BASE_ADDR, TRUE);
    }

    CSL_ospiIndSetStartAddr(
        (CSL_ospi_flash_cfgRegs *)FLS_OSPI_CTRL_BASE_ADDR,
        alignedStart,
        TRUE);

    CSL_ospiIndReadExecute(
        (CSL_ospi_flash_cfgRegs *)FLS_OSPI_CTRL_BASE_ADDR,
        alignedLen);

    /* -------- POLLING MODE -------- */
    if ((uint32)SPI_OPER_MODE_POLLING == object->intrPollMode)
    {
        remaining = alignedLen;
        uint8 *pTmp = pTmpBuf;

        while (remaining > 0U)
        {
            if (OSPI_waitReadSramLvl(
                    (CSL_ospi_flash_cfgRegs *)FLS_OSPI_CTRL_BASE_ADDR,
                    &sramLevel) != E_OK)
            {
                retVal = E_NOT_OK;
                transaction->status = SPI_TRANSFER_FAILED;
                break;
            }

            rdBytes = sramLevel * CSL_OSPI_FIFO_WIDTH;
            rdBytes = (rdBytes > remaining) ? remaining : rdBytes;

            CSL_ospiReadFifoData(FLS_BASE_ADDRESS, pTmp, rdBytes);

            pTmp      += rdBytes;
            remaining -= rdBytes;
        }

        if ((retVal == E_OK) &&
            (OSPI_waitIndReadComplete(
                (CSL_ospi_flash_cfgRegs *)FLS_OSPI_CTRL_BASE_ADDR) != E_OK))
        {
            retVal = E_NOT_OK;
            transaction->status = SPI_TRANSFER_FAILED;
        }
    }

#if defined (aarch64) || ((__ARM_ARCH == 7) && (__ARM_ARCH_PROFILE == R))
    CSL_archMemoryFence();
#endif

    /* -------- Copy only requested data -------- */
    if (retVal == E_OK)
    {
        memcpy(pUserDst, pTmpBuf + skipBytes, count);
    }

    return retVal;
}
 
 static uint32 OSPI_getDeviceStatus(SPI_Handle handle);
 static uint32 OSPI_getDeviceStatus(SPI_Handle handle)
 {
     OSPI_Object        *object;  /* OSPI object */
     uint8                status = 0xff;
 
     object = (OSPI_Object *)handle->object;
 
     (void)OSPI_cmdRead((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR),
                        object->rdStatusCmd,
                        &status,
                        1);
 
     return (status);
 }
 
 static boolean OSPI_waitDeviceReady(SPI_Handle handle, uint32 timeOut)
 {
     boolean         retVal = FALSE;
     uint32      status;
     uint32     timeOutVal = timeOut;
 
     while (timeOutVal != 0U)
     {
         status = OSPI_getDeviceStatus(handle);
         if ((status & 1U) == 0U)
         {
             retVal = TRUE;
             break;
         }

         /**
        * TI_COVERAGE_GAP_START [Branch Coverage] Dynamic coverage for this function cannot be covered 
          * delay part is added as a safety measure in case devicestatus!=1 and cannot be covered.

        * TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed from the inspection review.
        */
         timeOutVal--;
         OSPI_delay(OSPI_CHECK_IDLE_DELAY);
         /* TI_COVERAGE_GAP_STOP */
     }
 
     return (retVal);
 }
 

static Std_ReturnType OSPI_dac_xfer_mode_read(SPI_Handle handle,
    const SPI_Transaction *transaction)
{
    uint8               *pSrc;         /* Source address */
    uint8               *pDst;         /* Destination address */
    uint32               offset;       /* OSPI flash offset address */
    uint32               i;
    uint32               remainSize;
    uint32               alignedSize;
    uint32               unalignedSize;
    Std_ReturnType       retVal = E_OK;

    /* Copy flash transaction parameters to local variables */
    offset = (uint32)(transaction->arg); /* OSPI Flash offset address to read */
    pDst = (uint8 *)transaction->rxBuf;

    /* Disable PHY pipeline mode for read since we are not using DMA */
    CSL_ospiPipelinePhyEnable((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR), FALSE);

    pSrc = (uint8 *)((FLS_BASE_ADDRESS) + offset);

    /* Calculate the number of unaligned bytes at the start */
    unalignedSize = (((uint32)pSrc) % FLS_WORD_ALIGNMENT);
    if (unalignedSize != 0U)
    {
        unalignedSize = FLS_WORD_ALIGNMENT - unalignedSize; /* Calculate how many bytes to transfer to align to 4 bytes */
    }

    /* Calculate the remaining size after unaligned bytes */
    remainSize = (uint32)transaction->count;

    /* Take the minimum of unalignedSize and remainSize */
    unalignedSize = (unalignedSize < remainSize) ? unalignedSize : remainSize;

    /* Transfer the unaligned bytes at the start */
    for (i = 0U; i < unalignedSize; i++)
    {
        LLD_REG8_WR(pDst + i, LLD_REG8_RD(pSrc + i));
    #if defined (__aarch64__)
        CSL_archMemoryFence();
    #endif
    }

    /* Update pointers and remaining size */
    pSrc += unalignedSize;
    pDst += unalignedSize;
    remainSize -= unalignedSize;

    alignedSize = (remainSize & ~3U);

    /* Transfer aligned data in 32-bit chunks */
    for (i = 0U; i < alignedSize; i += FLS_WORD_ALIGNMENT)
    {
        LLD_REG32_WR(pDst + i, LLD_REG32_RD(pSrc + i));
    #if defined (__aarch64__)
        CSL_archMemoryFence();
    #endif
    }

    /* Update pointers after aligned transfer */
    pSrc += alignedSize;
    pDst += alignedSize;

    /* Transfer any remaining unaligned bytes at the end */
    for (i = 0U; i < (remainSize & 3U); i++)
    {
        LLD_REG8_WR(pDst + i, LLD_REG8_RD(pSrc + i));
    #if defined (__aarch64__)
        CSL_archMemoryFence();
    #endif
    }

    /* Return the final status */
    return retVal;
}


static Std_ReturnType OSPI_flashExecCmd(const CSL_ospi_flash_cfgRegs *pRegs)
{
    uint32 retry = OSPI_DAC_WRITE_TIMEOUT;
    Std_ReturnType  retVal = E_OK;

    volatile uint32 tempCount = FLS_TIMEOUT_DURATION;

    if (FLS_TIMEOUT_DURATION > 9U)
    {
        /* Each unit of SW_delay equals to 9 clockcycles, so dividing by 9U */
        tempCount = (FLS_TIMEOUT_DURATION / 9U);
    }
    /* Wait for FSM to to come out of reset */
    do
    {
        /**
        * TI_COVERAGE_GAP_START [Branch Coverage]  Dynamic coverage for these lines of code for  OSPI_flashExecCmd()  is not achievable as it depends upon elapsedcount and Hardware register.Some “if ” cases will be called in case of hardware failure and are added as a part of safety mechanism and cannot be covered.

        * TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed from the inspection review.
        */
        if (tempCount == 0U)        
        {
            /* Timeout */
            break;
        }
        MCAL_SW_DELAY(tempCount);
    }while (CSL_ospiIsIdle(pRegs) == FALSE);

    /* Start to execute flash read/write command */
    CSL_ospiFlashExecCmd(pRegs);

    /**
    * TI_COVERAGE_GAP_START [Branch Coverage] Dynamic coverage for these lines of code for  OSPI_flashExecCmd()  is not achievable as it depends upon elapsedcount and Hardware register.Some “if ” cases will be called in case of hardware failure and are added as a part of safety mechanism and cannot be covered.

    * TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed from the inspection review.
    */
    while (retry != 0U)
    /* TI_COVERAGE_GAP_STOP */
    {
        /* Check the command execution status */
        if (CSL_ospiFlashExecCmdComplete(pRegs) == TRUE)
        {
            break;
        }
        OSPI_delay(OSPI_CHECK_IDLE_DELAY);
        retry--;
    }

    if (retry == 0U)
    {
        retVal = E_NOT_OK;
    }

    if (FLS_TIMEOUT_DURATION > 9U)
    {
        /* Each unit of SW_delay equals to 9 clockcycles, so dividing by 9U */
        tempCount = (FLS_TIMEOUT_DURATION / 9U);
    }
    do
    {
        if (tempCount == 0U)        
        {
            /* Timeout */
            break;
        }
        MCAL_SW_DELAY(tempCount);
    }while (CSL_ospiIsIdle(pRegs) == FALSE);

    return (retVal);
 }
 

 static Std_ReturnType OSPI_cmdRead(const CSL_ospi_flash_cfgRegs *pRegs,
                                    uint32                      cmd,
                                    uint8                      *rxBuf,
                                    uint32                      rxLen)
 {
     uint32 regVal;
     uint32 rdLen;
     Std_ReturnType  retVal;
     uint8 *pBuf = rxBuf;
 
     if ((pRegs != NULL_PTR ) && (rxBuf != NULL_PTR ) && (rxLen > 0U))
     {
         (void)CSL_ospiCmdRead(pRegs, cmd, rxLen);
         retVal = OSPI_flashExecCmd(pRegs);
 
 
         if (retVal == E_OK)
         {
             /* Read the lower data register */
             regVal = LLD_REG32_RD(&pRegs->FLASH_RD_DATA_LOWER_REG);
 
 
             /* Put the read value into rxBuf, handle up to 4 bytes initially */
             rdLen = (rxLen > 4U) ? 4U : rxLen;
             (void)memcpy((void *)pBuf, (void *)(&regVal), rdLen);
             if(rdLen > 1U)
             {
                pBuf += rdLen;
             }
 
             /* If more than 4 bytes requested, read from the upper register */
             if (rxLen > 4U)
             {
                 regVal = LLD_REG32_RD(&pRegs->FLASH_RD_DATA_UPPER_REG);
                 rdLen = rxLen - rdLen;
                 (void)memcpy((void *)pBuf, (void *)(&regVal), rdLen);
             }
         }
     }
     else
     /**
    * TI_COVERAGE_GAP_START [Branch Coverage] Dynamic Coverage for “else” case is not covered as it is added as part of safety mechanism and will be covered
            in case of hadware failure.

    * TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed from the inspection review.
    */
     {
         /* Return E_NOT_OK if any of the checks fail */
         retVal = E_NOT_OK;
     }
         /* TI_COVERAGE_GAP_STOP */

         return retVal;
 }
 

 static Std_ReturnType OSPI_cmdExtRead(const CSL_ospi_flash_cfgRegs *pRegs,
                               uint8                      *cmd,
                               uint32                      cmdLen,
                               uint8                      *rxBuf,
                               uint32                      rxLen,
                               uint32                      dummyCycles)
 {
     uint32 regVal;
     uint32 rdLen;
     Std_ReturnType  retVal = E_NOT_OK;
     uint8 *pBuf = rxBuf;
 
     (void)CSL_ospiCmdExtRead(pRegs, cmd, cmdLen, rxLen, dummyCycles);
     retVal = OSPI_flashExecCmd(pRegs);
     /**
      * TI_COVERAGE_GAP_START [Branch Coverage]  Dynamic coverage for false is  not achievable as it depends upon Hardware register .
      *
      * TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed from the inspection review.
      */
     if (retVal == E_OK)
     /* TI_COVERAGE_GAP_STOP */

     {
         regVal = LLD_REG32_RD(&pRegs->FLASH_RD_DATA_LOWER_REG);
 
         /* Put the read value into rxBuf */
         rdLen = (rxLen > 4U) ? 4U :
         rxLen;
         (void)memcpy((void *)pBuf, (void *)(&regVal), rdLen);
         pBuf += rdLen;

         /**
          * TI_COVERAGE_GAP_START [Branch Coverage]    Dynamic branch Coverage for rxlen>4 cannot be covered as current flash device doesnot support command length greater than 4U. This is added to support custom flash devices and user can configure the board file according the flash used in SOC.
          *
          * TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed from the inspection review.
          */
         if (rxLen > 4U) {
             regVal = LLD_REG32_RD(&pRegs->FLASH_RD_DATA_UPPER_REG);
             rdLen = rxLen - rdLen;
             (void)memcpy((void *)pBuf, (void *)(&regVal), rdLen);
         }
         /* TI_COVERAGE_GAP_STOP */
     }
     return (retVal);
 
 }
 

 static Std_ReturnType OSPI_cmd_mode_read(SPI_Handle handle,
                                      SPI_Transaction *transaction)
 {
     uint8               *cmd;
     OSPI_Object *object;
     Std_ReturnType retVal = E_NOT_OK;
 
     cmd = (uint8 *)transaction->txBuf;
     object = (OSPI_Object *)handle->object;
 
     if(CSL_ospiGetDualByteOpcodeMode((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR))!= 0U)
     {
         retVal = OSPI_cmdExtRead((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR),
                                  (uint8 *)cmd,
                                  (uint32)CSL_OSPI_CMD_LEN_EXTENDED,
                                  (uint8 *)transaction->rxBuf,
                                  (uint32)transaction->count - CSL_OSPI_CMD_LEN_EXTENDED,
                                  (uint32)object->extRdDummyClks);
     }
     else
     {
         retVal = OSPI_cmdRead((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR),
                               (uint32)cmd[0],
                               (uint8 *)transaction->rxBuf,
                               (uint32)transaction->count - CSL_OSPI_CMD_LEN_DEFAULT);
     }
 
     return (retVal);
 }
 
 static Std_ReturnType OSPI_read(SPI_Handle handle, SPI_Transaction *transaction)
 {
     OSPI_Object *object = (OSPI_Object *)NULL;
     Std_ReturnType retVal = E_NOT_OK;
 
     if ((handle != NULL_PTR) && (transaction != NULL_PTR) && (transaction->rxBuf != NULL_PTR))
     {
         object = (OSPI_Object *)handle->object;
         /**
        * TI_COVERAGE_GAP_START [Branch Coverage] Dynamic coverage for false case cannot be covered as Object IS gloabal pointer and cannot be null .

        * TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed from the inspection review.
        */
         if (object != NULL)
         /* TI_COVERAGE_GAP_STOP */
         {
             if ((uint32)OSPI_OPER_MODE_IND_XFER == object->ospiMode)
             {
                 retVal = OSPI_ind_xfer_mode_read(handle, transaction);
             }
             else if ((uint32)OSPI_OPER_MODE_DAC_XFER == object->ospiMode)
             {
                 retVal = OSPI_dac_xfer_mode_read(handle, transaction);
             }
             else if ((uint32)OSPI_OPER_MODE_CFG == object->ospiMode)
             {
                 retVal = OSPI_cmd_mode_read(handle, transaction);
             }
             else
             {
                 transaction->status = SPI_TRANSFER_CANCELED;
             }
         }
        /**
        * TI_COVERAGE_GAP_START [Branch Coverage] Dynamic coverage for else cannot be covered as  OSPI mode is always set either of dac, indac or cnfg .

        * TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed from the inspection review.
        */
         else
         {
             transaction->status = SPI_TRANSFER_CANCELED;
         }
         /* TI_COVERAGE_GAP_STOP */
     }
     else
     {
         if (transaction != NULL)
         {
             transaction->status = SPI_TRANSFER_CANCELED;
         }
     }
 
     /* Clear the transaction pointer in object if object is valid */
     if (object != NULL)
     {
         object->transaction = (SPI_Transaction *)NULL;
     }
 
 
     return retVal;
 }
 

 static Std_ReturnType OSPI_waitWriteSramLvl(const CSL_ospi_flash_cfgRegs *pReg,
                                      uint32 *sramLvl)
 {
     uint32 retry = CSL_OSPI_REG_RETRY;
     uint32 sramLevel;
     Std_ReturnType  retVal = E_OK;

     /**
    * TI_COVERAGE_GAP_START [Branch Coverage] Dynamic Coverage for false part depends  on SRAM level which depends on status of hardware registers and cannot be covered.

    * TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed from the inspection review.
    */
     while(retry != 0U)
     /* TI_COVERAGE_GAP_STOP */
     {
         sramLevel = CSL_ospiGetSramLvl(pReg, 0);
         if (sramLevel <= CSL_OSPI_SRAM_WATERMARK_WR_LVL)
         {
             *sramLvl = sramLevel;
             break;
         }
         /**
        * TI_COVERAGE_GAP_START [Branch Coverage] Dynamic Coverage for “Fls_delay” depends on SRAM level which depends on status of hardware registers and cannot be covered.

        * TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed from the inspection review.
        */
         Fls_delay(CSL_OSPI_POLL_IDLE_DELAY);
 
         retry--;
         /* TI_COVERAGE_GAP_STOP */
     }
 
     if (retry != 0U)
     {
         retVal = E_OK;
     }
     /**
    * TI_COVERAGE_GAP_START [Branch Coverage] Dynamic Coverage for “else” case cannot be covered as it depends on hadware status register. These are added as part of safety mechanism and cannot be covered.

    * TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed from the inspection review.
    */
     else
     {
         retVal = E_NOT_OK;
     }
     /* TI_COVERAGE_GAP_STOP */
     return(retVal);
 }
 

 static Std_ReturnType OSPI_waitIndWriteComplete(const CSL_ospi_flash_cfgRegs *pRegs)
 {
     uint32 retry = OSPI_DAC_WRITE_TIMEOUT;
     Std_ReturnType  retVal;
 
     /* Check flash indirect write controller status */
     while (retry != 0U)
     {
         if (CSL_ospiIsIndWriteComplete(pRegs) == TRUE)
         {
             break;
         }
         OSPI_delay(OSPI_CHECK_IDLE_DELAY);
         retry--;
     }
 
     if (retry != 0U)
     {
         /* Clear indirect completion status */
         CSL_ospiClrIndWriteComplete(pRegs);
         retVal = E_OK;
     }
     else
     {
         retVal = E_NOT_OK;
     }
     return(retVal);
 }
 

 static Std_ReturnType OSPI_ind_xfer_mode_write(SPI_Handle handle,
                                            SPI_Transaction *transaction)
 {
     OSPI_Object        *object;       /* OSPI object */
     uint8               *pSrc;         /* Destination address */
     uint32               count;        /* transaction length */
     uint32               offset;       /* OSPI flash offset address */
     uint32               remaining;
     uint32               sramLevel, wrBytes;
     uint32               retFlag = 0;
     Std_ReturnType       retVal = E_OK;
 
     /* Copy flash transaction parameters to local variables */
     offset = (uint32)(transaction->arg); /* NOR Flash offset address to write */
     pSrc = (uint8*)transaction->txBuf;
     count = (uint32)transaction->count;
 
 
     object = (OSPI_Object *)handle->object;
 
     /* Disable DAC mode */
     CSL_ospiDacEnable((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR), FALSE);
 
     /* Set write address in indirect mode */
     CSL_ospiIndSetStartAddr((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR),
                             offset,
                             FALSE);
     CSL_ospiIndWriteExecute((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR), count);
 
     if ((uint32)SPI_OPER_MODE_POLLING == object->intrPollMode)
     {
         /* Wait Indirect Write  SRAM fill level below the threshold */
         if (OSPI_waitWriteSramLvl((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR),
                                   &sramLevel) != E_OK)
         /**
        * TI_COVERAGE_GAP_START [Branch Coverage] Dynamic coverage for this cannot be covered as it depends  on SRAM level which depends on hardware register and cannot be covered.

        * TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed from the inspection review.
        */
         {
             retFlag = 1U;
             retVal = E_NOT_OK;
             transaction->status=SPI_TRANSFER_FAILED;
         }
         /* TI_COVERAGE_GAP_STOP */
         else
         {
             remaining = count;
             while(remaining > 0U)
             {
                 /* Wait indirect write SRAM fifo level below watermark */
                 /**
                * TI_COVERAGE_GAP_START [Branch Coverage] Dynamic coverage for this cannot be covered as it depends  on SRAM level which depends on hardware register and cannot be covered.

                * TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed from the inspection review.
                */
                 if (OSPI_waitWriteSramLvl((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR),
                                           &sramLevel) != E_OK)
                 /* TI_COVERAGE_GAP_STOP */
                 {
                     retFlag = 1U;
                     retVal = E_NOT_OK;
                     break;
                 }
 
                 wrBytes = (CSL_OSPI_SRAM_PARTITION_WR - sramLevel) * CSL_OSPI_FIFO_WIDTH;
                 wrBytes = (wrBytes > remaining) ? remaining : wrBytes;
 
                 /* Write data to FIFO */
                 CSL_ospiWriteFifoData((FLS_BASE_ADDRESS), pSrc, wrBytes);
 
                 pSrc += wrBytes;
                 remaining -= wrBytes;
             }
 
             if(retFlag == 0U)
             {
                 if (OSPI_waitIndWriteComplete((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR)) != E_OK)
                 {
                     retFlag = 1U;
                     retVal = E_NOT_OK;
                 }
             }
         }
     }
 
     if(retFlag == 1U)
     {
         transaction->status=SPI_TRANSFER_FAILED;
         CSL_ospiIndWriteCancel((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR));
     }
     return (retVal);
 }
 

 static Std_ReturnType OSPI_dac_xfer_mode_write(SPI_Handle handle,
                                            const SPI_Transaction *transaction)
 {
 
     uint8               *pSrc;         /* Source address */
     uint32               offset;       /* OSPI flash offset address */
     uint32               i;
     uint8               *pDst;         /* Destination address */
     uint32               size;
     uint32               remainSize;
     Std_ReturnType       retVal = E_OK;
     uint32               wrWord;
     uint32               wrByte;
 
     /* Copy flash transaction parameters to local variables */
     offset = (uint32)(transaction->arg); /* OSPI Flash offset address to write */
     pSrc = (uint8 *)transaction->txBuf;
 
 
 
     /* Disable PHY pipeline mode */
     CSL_ospiPipelinePhyEnable((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR), FALSE);
 
     pDst = (uint8 *)((FLS_BASE_ADDRESS) + offset);
     remainSize = (uint32)transaction->count & 3U;
     size = (uint32)transaction->count - remainSize;
     /* Transfer the data in 32-bit size */
     for (i = 0U; i < size; i += 4U)
     {
         wrWord = LLD_REG32_RD(pSrc + i);
         LLD_REG32_WR(pDst + i, wrWord);
         if (OSPI_waitDeviceReady(handle, OSPI_DAC_WRITE_TIMEOUT) == TRUE)
         {
             retVal = E_OK;
         }
         else
         {
             retVal = E_NOT_OK;
         }
     }
     if (retVal == E_OK)
     {
         /* Transfer the remaining data in 8-bit size */
         for (i = 0; i < remainSize; i++)
         {
             wrByte = LLD_REG8_RD(pSrc + size + i);
             LLD_REG8_WR(pDst + size + i, wrByte);
             if (OSPI_waitDeviceReady(handle, OSPI_DAC_WRITE_TIMEOUT) == TRUE)
             {
                 retVal = E_OK;
             }

             /**
             * TI_COVERAGE_GAP_START [Branch Coverage] Dynamic Coverage for “else” case is not possible as it depends on hardware status register and cannot be covere

             * TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed from the inspection review.
             */
             else
             {
                 retVal = E_NOT_OK;
             }
             /* TI_COVERAGE_GAP_STOP */
         }
     }
 
     return (retVal);
 }
 
 static Std_ReturnType OSPI_cmdWrite(const CSL_ospi_flash_cfgRegs *pRegs,
                              const uint8                *cmdBuf,
                              uint32                      cmdLen,
                              uint8                		*txBuf,
                              uint32                      txLen)
 {
     (void)CSL_ospiCmdWrite(pRegs, cmdBuf, cmdLen, txBuf, txLen);
     return (OSPI_flashExecCmd(pRegs));
 }
 

 static Std_ReturnType OSPI_cmd_mode_write(SPI_Handle handle,
                                       const SPI_Transaction *transaction)
 {
     uint8               *txBuf;
     uint32               dataLen;
     uint32               cmdLen;
     Std_ReturnType       retVal = E_OK;
 
     txBuf = (uint8 *)transaction->txBuf;
     dataLen = (uint32)(transaction->arg);
     /**
     * TI_COVERAGE_GAP_START [Branch Coverage] Dynamic Coverage cannot be covered as  it is already checked in earlier opreation.

    * TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed from the inspection review.
    */
     cmdLen = ((uint32)transaction->count > dataLen) ? ((uint32)transaction->count - dataLen) : 0U;
     /* TI_COVERAGE_GAP_STOP */

     if (dataLen != 0U)
     {
         retVal = (OSPI_cmdWrite((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR),
                                 txBuf,
                                 cmdLen,
                                 &txBuf[cmdLen],
                                 dataLen));
     }
     else
     {
         retVal = (OSPI_cmdWrite((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR),
                                 txBuf,
                                 cmdLen,
                                 (uint8 *) NULL,
                                 0));
     }
     return (retVal);
 }

 static Std_ReturnType OSPI_write(SPI_Handle handle, SPI_Transaction *transaction)
 {
     OSPI_Object  *object;
     Std_ReturnType retVal = E_NOT_OK;
 
 
     /* Check for valid handle and and hwAttrs before proceeding */
     if ((handle != NULL_PTR) && (transaction != NULL_PTR) && (transaction->txBuf != NULL_PTR))
     {
         object = (OSPI_Object *)handle->object;
 
 
         /* Check for the OSPI mode and call the respective write function */
         if((uint32)OSPI_OPER_MODE_IND_XFER == object->ospiMode)
         {
             retVal = (OSPI_ind_xfer_mode_write(handle, transaction));
         }
         else if((uint32)OSPI_OPER_MODE_DAC_XFER == object->ospiMode)
         {
             retVal = (OSPI_dac_xfer_mode_write(handle, transaction));
         }
         else if((uint32)OSPI_OPER_MODE_CFG == object->ospiMode)
         {
             retVal = (OSPI_cmd_mode_write(handle, transaction));
         }
         else
         /**
        * TI_COVERAGE_GAP_START [Branch Coverage] Dynamic Coverage for “else” is added incase mode is not recognised or if the transaction pointer is NULL. The transaction pointer is already checked in the parent function and these checks are added as a part of safety mechanism and cannot be covered.

        * TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed from the inspection review.
        */
         {
             /* If the mode is not recognized, cancel the transaction */
             transaction->status = SPI_TRANSFER_CANCELED;
         }
         /* TI_COVERAGE_GAP_STOP */

         /* Reset the transaction pointer */
         object->transaction = (SPI_Transaction *)NULL;
     }
     else
     /**
    * TI_COVERAGE_GAP_START [Branch Coverage] Dynamic Coverage for “else” is added incase mode is not recognised or if the transaction pointer is NULL. The transaction pointer is already checked in the parent function and these checks are added as a part of safety mechanism and cannot be covered.

    * TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed from the inspection review.
    */
     {
         /* Set the transaction status to canceled in case of invalid inputs */
         if (transaction != NULL)
         {
             transaction->status = SPI_TRANSFER_CANCELED;
         }
     }
     /* TI_COVERAGE_GAP_STOP */

     /* Return the result of the write operation */
     return (retVal);
 }
 /*
  *  ======== OSPI_transfer ========
  */
 
 boolean OSPI_transfer(SPI_Handle handle, SPI_Transaction *transaction_xfer)
 {
     boolean                ret = FALSE; /* return value */
     OSPI_Object        *object;      /* OSPI object */
     Std_ReturnType      xferRet;
 
     /* Check if anything needs to be written or read */
     if ((handle != NULL_PTR) && (transaction_xfer != NULL_PTR) && (0U != (uint32)transaction_xfer->count))
     {
         /* Get the pointer to the object and hwAttrs */
         object = (OSPI_Object *)handle->object;
         /* Check if a transfer is in progress */
         if (object->transaction != NULL_PTR)
         {
             /* Transfer is in progress */
             transaction_xfer->status = SPI_TRANSFER_CANCELED;
         }
         else
         {
             /* Save the pointer to the transaction */
             object->transaction = transaction_xfer;
 
             /* Book keeping of transmit and receive buffers. */
             object->writeBufIdx = (uint8 *)transaction_xfer->txBuf;
             object->writeCountIdx = (uint32)transaction_xfer->count;
             object->readBufIdx =  (uint8 *)transaction_xfer->rxBuf;
             object->readCountIdx = (uint32)transaction_xfer->count;
 
             xferRet = OSPI_primeTransfer(handle, transaction_xfer);
             if (xferRet == E_OK)
             {
                 /* Always return TRUE if in Asynchronous mode */
                 ret = TRUE;
                 transaction_xfer->status = SPI_TRANSFER_COMPLETED;
             }
             else
             {
                 transaction_xfer->status=SPI_TRANSFER_FAILED;
             }
         }
     }
     else
     {
         if (transaction_xfer != NULL)
         {
             transaction_xfer->status = SPI_TRANSFER_CANCELED;
         }
     }
 
     return (ret);
 }
 
 static Std_ReturnType OSPI_configDdr(SPI_Handle handle, uint32 cmd, uint32 addr, uint32 data)
 {
     Std_ReturnType      retVal;
 
     CSL_ospiFlashStig((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR), cmd, addr, data);
     retVal = OSPI_flashExecCmd((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR));
     if (retVal == E_OK)
     {
         if (Fls_DrvObj.dacEnable == TRUE)
         {
             CSL_ospiDacEnable((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR), TRUE);
         }
         else
         {
             CSL_ospiDacEnable((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR), FALSE);
         }
 
         /* Enable DTR protocol */
         if (Fls_DrvObj.dtrEnable == TRUE)
         {
             CSL_ospiDtrEnable((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR), TRUE);
         }
         else
         {
             CSL_ospiDtrEnable((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR), FALSE);
         }
     }
 
     return (retVal);
 }
 
 static Std_ReturnType OSPI_enableXip (SPI_Handle handle, uint32 cmd, uint32 addr, uint32 data)
 {
 
     Std_ReturnType     retVal;
 
 
     /* Disable Direct Access Controller */
     CSL_ospiDacEnable((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR), FALSE);
 
     /* Configure Flash Command Control Register to issue VCR write to FLASH memory to enable/disable XIP mode */
     CSL_ospiFlashStig((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR), cmd, addr, data);
     retVal = OSPI_flashExecCmd((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR));
     if (retVal == E_OK)
     {
         OSPI_delay(OSPI_XIP_SETUP_DELAY);
 
         /* Clear the XIP mode bits in the Mode Bit Configuration Register. */
         CSL_ospiSetModeBits((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR), 0x00);
 
         /* Enable the local controllers XIP mode */
         CSL_ospiXipEnable((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR), TRUE);
     }
 
     /* Re-enable the Direct Access Controller */
     CSL_ospiDacEnable((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR), TRUE);
     return (retVal);
 }
 
 static Std_ReturnType OSPI_configDummyCycle(SPI_Handle handle,
                                                     uint32 cmd, uint32 addr, uint32 data)
 {
     Std_ReturnType         retVal;
 
     CSL_ospiFlashStig((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR), cmd, addr, data);
     retVal = OSPI_flashExecCmd((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR));
 
     return (retVal);
 }
 
 /*
  *  ======== OSPI_control ========
  */
 Std_ReturnType OSPI_control(SPI_Handle handle, uint32 cmd, const void *arg)
 {
     OSPI_Object        *object;  /* OSPI object */
     Std_ReturnType      retVal = E_NOT_OK;
     const uint32        *ctrlData = (const uint32 *)arg;
     uint32               nvcrCmd;
     uint32               addr;
     uint32               data;
     uint32               extOpcodeLo;
     uint32               extOpcodeUp;
     uint8 flashIdx = Fls_DrvObj.Fls_flashIndex;
     const FlashConfig *flsNorDevicePtr = &FlsNorDevice.flscfg[flashIdx];
 
     if (handle != NULL_PTR)
     {
         /* Get the pointer to the object */
         object = (OSPI_Object *)handle->object;
 
         switch (cmd)
         {
             case SPI_V0_CMD_XFER_OPCODE:
             {
                 if (ctrlData != NULL_PTR)
                 {
                     object->transferCmd = *ctrlData;
                     ctrlData++;
                     CSL_ospiConfigRead((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR),
                                        object->transferCmd,
                                        object->xferLines,
                                        object->rdDummyClks);
                     object->transferCmd = *ctrlData;
                     ctrlData++;
                     CSL_ospiWriteSetup((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR),
                                        object->transferCmd,
                                        object->xferLines);
                     object->rdStatusCmd = *ctrlData;
                     retVal = E_OK;
                 }
                 break;
             }
 
             case SPI_V0_CMD_XFER_OPCODE_EXT:
             {
                 if (ctrlData != NULL_PTR)
                 {
                     extOpcodeLo  = *ctrlData; /* EXT_STIG_OPCODE_FLD */
                     ctrlData++;
                     extOpcodeLo |= (*ctrlData << 8); /* EXT_POLL_OPCODE_FLD */
                     ctrlData++;
                     extOpcodeLo |= (*ctrlData << 16); /* EXT_WRITE_OPCODE_FLD */
                     ctrlData++;
                     extOpcodeLo |= (*ctrlData << 24); /* EXT_READ_OPCODE_FLD */
                     ctrlData++;
                     extOpcodeUp  = (*ctrlData << 16); /* EXT_WEL_OPCODE_FLD */
                     ctrlData++;
                     extOpcodeUp |= (*ctrlData << 24); /* WEL_OPCODE_FLD */
 
                     CSL_ospiExtOpcodeSet((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR),
                                  extOpcodeLo,
                                  extOpcodeUp);
                     CSL_ospiSetDualByteOpcodeMode((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR),
                                           TRUE);
                     retVal = E_OK;
                 }
                 break;
             }

             case SPI_V0_CMD_XFER_MODE_RW:
             {
                 if (ctrlData != NULL_PTR)
                 {
                     object->transactionType = *ctrlData;
                     retVal = E_OK;
                 }
                 break;
             }
 
             case SPI_V0_CMD_SET_CFG_MODE:
             {
                 object->ospiMode = (uint32)OSPI_OPER_MODE_CFG;
                 retVal = E_OK;
                 break;
             }
 
             case SPI_V0_CMD_SET_XFER_MODE:
             {
                 if (Fls_DrvObj.dacEnable == TRUE)
                 {
                     object->ospiMode = (uint32)OSPI_OPER_MODE_DAC_XFER;
                 }
                 else
                 {
                     object->ospiMode = (uint32)OSPI_OPER_MODE_IND_XFER;
                 }
                 retVal = E_OK;
                 break;
             }
 
             case SPI_V0_CMD_SET_XFER_LINES:
             {
                 if (ctrlData != NULL_PTR)
                 {
                     uint32 numAddrBytes;
                     object->xferLines = *ctrlData;
                     if(flsNorDevicePtr->FOUR_BYTE_ADDR_ENABLE == 1U)
                     {
                         numAddrBytes = CSL_OSPI_MEM_MAP_NUM_ADDR_BYTES_4;
                     }
                     else
                     {
                         numAddrBytes = CSL_OSPI_MEM_MAP_NUM_ADDR_BYTES_3;
                     }
                     if ((object->xferLines == (uint32)OSPI_XFER_LINES_OCTAL) && (Fls_DrvObj.dtrEnable != 0U))
                     {
                         numAddrBytes = CSL_OSPI_MEM_MAP_NUM_ADDR_BYTES_4;
                     }
                     if (object->xferLines == (uint32)OSPI_XFER_LINES_OCTAL)
                     {
                         /* 8 dummy cycles required for polling status register in octal mode */
                         CSL_ospiSetPollingDummyCycles((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR),
                                                        8U);
                     }
                     else
                     {
                         /* 0 dummy cycles required for polling status register in single mode */
                         CSL_ospiSetPollingDummyCycles((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR),
                                                        0U);
                     }
                     /* Set device size cofigurations */
                     CSL_ospiSetDevSize((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR),
                                        numAddrBytes,
                                        flsNorDevicePtr->NOR_PAGE_SIZE,
                                        Fls_DrvObj.blockSize);
                     retVal = E_OK;
                 }
                 break;
             }

             case SPI_V0_CMD_RD_DUMMY_CLKS:
             {
                 if (ctrlData != NULL_PTR)
                 {
                     object->rdDummyClks = *ctrlData;
                     retVal = E_OK;
                 }
                 break;
             }
 
             case SPI_V0_CMD_EXT_RD_DUMMY_CLKS:
             {
                 if (ctrlData != NULL_PTR)
                 {
                     object->extRdDummyClks = *ctrlData;
                     retVal = E_OK;
                 }
                 break;
             }

             case SPI_V0_CMD_CFG_PHY:
             {
                 if (ctrlData != NULL_PTR)
                 {
                     uint32 phyEnable = *ctrlData++;
                     if (phyEnable == TRUE)
                     {
                         /**
                     * TI_COVERAGE_GAP_START [Branch Coverage] Dynamic coverage for OSPI_control() for the case SPI_V0_CMD_CFG_PHY is not possible,
                     * Phy feature is not currently supported

                     * TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed from the inspection review.
                     */
                         if (Fls_DrvObj.phyEnable == FALSE)
                         {
                             CSL_ospiSetPreScaler((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR), CSL_OSPI_BAUD_RATE_DIVISOR(2U));
                             /* Enable PHY mode */
                             CSL_ospiPhyEnable((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR), TRUE);
                             Fls_DrvObj.phyEnable = TRUE;
                         }
                         /* TI_COVERAGE_GAP_STOP */
                     uint32 txDelay = *ctrlData++;
                         uint32 rxDelay = *ctrlData;
                         CSL_ospiConfigPhyDLL((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR),txDelay, rxDelay);
                     }
                     else
                     {
                         if (Fls_DrvObj.phyEnable == TRUE)
                         {
                             /* Disable high speed mode when PHY is disabled */
                             CSL_ospiSetPreScaler((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR), CSL_OSPI_BAUD_RATE_DIVISOR_DEFAULT);
                             CSL_ospiPhyEnable((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR), FALSE);
                             Fls_DrvObj.phyEnable = FALSE;
                         }
                     }
                 }
                 retVal = E_OK;
                 break;
             }
 
             case SPI_V0_CMD_ENABLE_DDR:
             case SPI_V0_CMD_ENABLE_SDR:
             {
                 if (ctrlData != NULL_PTR)
                 {
                     nvcrCmd = *ctrlData;
                     ctrlData++;
                     addr   = *ctrlData;
                     ctrlData++;
                     data   = *ctrlData;
                     retVal = OSPI_configDdr(handle, nvcrCmd, addr, data);
                 }
                 break;
             }
 

             case SPI_V0_CMD_CFG_XIP:
             {
                 if ((Fls_DrvObj.xipEnable == TRUE) && (ctrlData != NULL_PTR)) {
                     nvcrCmd = *ctrlData;
                     ctrlData++;
                     addr = *ctrlData;
                     ctrlData++;
                     data = *ctrlData;
                     retVal = OSPI_enableXip(handle, nvcrCmd , addr, data);
 
                 }
                 /* Enable PHY pipeline mode for read */
                 CSL_ospiPipelinePhyEnable((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR), TRUE);
                 break;
             }
 
             case SPI_V0_CMD_CFG_RD_DELAY:
             {
                 if (ctrlData != NULL_PTR)
                 {
                     uint32 rdDelay = *ctrlData;
                     CSL_ospiSetDataReadCapDelay((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR), rdDelay);
                     retVal = E_OK;
                 }
                 break;
             }
 
             case SPI_V0_CMD_CFG_DUMMY_CYCLE:
             {
                 if (ctrlData != NULL_PTR)
                 {
                     nvcrCmd = *ctrlData;
                     ctrlData++;
                     addr   = *ctrlData;
                     ctrlData++;
                     data   = *ctrlData;
                     retVal = OSPI_configDummyCycle(handle, nvcrCmd, addr, data);
                 }
                 break;
             }
 
             default:
                 retVal = E_STATUS_UNDEFINED;
             break;
         }
     }
     return retVal;
 }
 
 /*
  *  ======== SPI_Params_init ========
  */
  void SPI_Params_init(SPI_Params *params)
 {
     if (params != NULL)
     {
         *params = SPI_defaultParams;
     }
 }
 
 #if (STD_ON == OSPI_SAFETY_API)
 /*
  * Design: MCAL-7401,MCAL-7388
  */
 FUNC(Std_ReturnType, FLS_CODE)
     Fls_dataOverflowUnderflowIntrEnable(uint32 intrFlag)
 {
     Std_ReturnType retVal = (Std_ReturnType) E_OK;
     if(intrFlag == CSL_OSPI_INTR_MASK_UNDERFLOW_DET)
     {
         CSL_ospiIntrEnable((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR),
                             CSL_OSPI_INTR_MASK_UNDERFLOW_DET, TRUE);
     }
     else if(intrFlag == CSL_OSPI_INTR_MASK_RECV_OVERFLOW_DET)
     {
         CSL_ospiIntrEnable((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR),
                             CSL_OSPI_INTR_MASK_RECV_OVERFLOW_DET, TRUE);
     }


     /*
     * TI_COVERAGE_GAP_START [Branch Coverage] Dynamic coverage for cannot be acieved as the else part is an additional check .
     *TI_COVERAGE_UNIT_EFFECT There is no side - effects on this unit as confirmed from the inspection review.
     */
     else
     {
         retVal = (Std_ReturnType) E_NOT_OK;
     }
     /* TI_COVERAGE_GAP_STOP */
     return (retVal);
 
 }
 /*
  * Design: MCAL-7401,MCAL-7388
  */
 FUNC(Std_ReturnType, FLS_CODE)
     Fls_dataOverflowUnderflowIntrDisable(uint32 intrFlag)
 {
     /* Disable  the interrupts */
     Std_ReturnType retVal = (Std_ReturnType) E_OK;
     if(intrFlag == CSL_OSPI_INTR_MASK_UNDERFLOW_DET)
     {
         CSL_ospiIntrEnable((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR),
                             CSL_OSPI_INTR_MASK_UNDERFLOW_DET, FALSE);
     }
     else if(intrFlag == CSL_OSPI_INTR_MASK_RECV_OVERFLOW_DET)
     {
         CSL_ospiIntrEnable((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR),
                             CSL_OSPI_INTR_MASK_RECV_OVERFLOW_DET, FALSE);
     }
 

     /**
    * TI_COVERAGE_GAP_START [Branch Coverage] Dynamic coverage for cannot be acieved as the else part is an additional check

    * TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed from the inspection review.
    */
     else
     {
         retVal = (Std_ReturnType) E_NOT_OK;
     }
     /* TI_COVERAGE_GAP_STOP */

     return (retVal);
 
 }
 
 
 FUNC(Ospi_IrqStatusType, FLS_CODE)
     Fls_dataOverflowUnderflowIntrGetStatus(uint32 intFlags)
 {
     uint32 intrStatus;
     Ospi_IrqStatusType  ospiIrqstatus    =  OSPI_NO_EVENT;
     if ((intFlags == CSL_OSPI_INTR_STATUS_UNDERFLOW_DET) || (intFlags == CSL_OSPI_INTR_STATUS_RECV_OVERFLOW_DET))
     {
         /* Read the interrupt status register */
         intrStatus = CSL_ospiIntrStatus((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR));
         intrStatus  = intrStatus & intFlags;
         /**
        * TI_COVERAGE_GAP_START [Branch Coverage] Dynamic coverage for the if condition cannot be covered,
          * as it expects a certain status of interrupt from the hardware register

        * TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed from the inspection review.
        */
         if (intrStatus == intFlags)
         {
             ospiIrqstatus = OSPI_EVENT_PENDING;
         }
         else
         {
             ospiIrqstatus = OSPI_NO_EVENT;
         }
     }
     else
     {
         ospiIrqstatus = OSPI_STATUS_READ_FAIL;
     }
 
     return (ospiIrqstatus);
 }
 
 FUNC(Std_ReturnType, FLS_CODE)
     Fls_dataOverflowUnderflowIntrStatusClear(uint32 intrFlag)
 {
   Std_ReturnType retVal = (Std_ReturnType) E_OK;
   if(intrFlag == CSL_OSPI_INTR_MASK_UNDERFLOW_DET)
   {
       CSL_ospiIntrClear((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR),
                           CSL_OSPI_INTR_MASK_UNDERFLOW_DET);
   }
   else if(intrFlag == CSL_OSPI_INTR_MASK_RECV_OVERFLOW_DET)
   {
       CSL_ospiIntrClear((CSL_ospi_flash_cfgRegs *)(FLS_OSPI_CTRL_BASE_ADDR),
                           CSL_OSPI_INTR_MASK_RECV_OVERFLOW_DET);
   }
 

   /**
    * TI_COVERAGE_GAP_START [Branch Coverage] Dynamic coverage for cannot be acieved as the else part is an additional check

    * TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed from the inspection review.
    */
   else
   {
       retVal = (Std_ReturnType) E_NOT_OK;
   }
   /* TI_COVERAGE_GAP_STOP */

   return (retVal);
 
 }
 #endif//#if (STD_ON == OSPI_SAFETY_API)
 
 #define FLS_STOP_SEC_CODE
 #include "Fls_MemMap.h"