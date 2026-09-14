/******************************************************************************
 * $Revision: 10544 $
 * $Date: 2014-09-16 10:22:04 +0200 (Tue, 16 Sep 2014) $
 *****************************************************************************/
/* __DISCLAIMER_START__                                                      */
/******************************************************************************
* Copyright (C) 2014 Spansion LLC. All Rights Reserved. 
*
* This software is owned and published by: 
* Spansion LLC, 915 DeGuigne Dr. Sunnyvale, CA  94088-3453 ("Spansion").
*
* BY DOWNLOADING, INSTALLING OR USING THIS SOFTWARE, YOU AGREE TO BE BOUND 
* BY ALL THE TERMS AND CONDITIONS OF THIS AGREEMENT.
*
* This software contains source code for use with Spansion 
* components. This software is licensed by Spansion to be adapted only 
* for use in systems utilizing Spansion components. Spansion shall not be 
* responsible for misuse or illegal use of this software for devices not 
* supported herein.  Spansion is providing this software "AS IS" and will 
* not be responsible for issues arising from incorrect user implementation 
* of the software.  
*
* SPANSION MAKES NO WARRANTY, EXPRESS OR IMPLIED, ARISING BY LAW OR OTHERWISE,
* REGARDING THE SOFTWARE (INCLUDING ANY ACOOMPANYING WRITTEN MATERIALS), 
* ITS PERFORMANCE OR SUITABILITY FOR YOUR INTENDED USE, INCLUDING, 
* WITHOUT LIMITATION, THE IMPLIED WARRANTY OF MERCHANTABILITY, THE IMPLIED 
* WARRANTY OF FITNESS FOR A PARTICULAR PURPOSE OR USE, AND THE IMPLIED 
* WARRANTY OF NONINFRINGEMENT.  
* SPANSION SHALL HAVE NO LIABILITY (WHETHER IN CONTRACT, WARRANTY, TORT, 
* NEGLIGENCE OR OTHERWISE) FOR ANY DAMAGES WHATSOEVER (INCLUDING, WITHOUT 
* LIMITATION, DAMAGES FOR LOSS OF BUSINESS PROFITS, BUSINESS INTERRUPTION, 
* LOSS OF BUSINESS INFORMATION, OR OTHER PECUNIARY LOSS) ARISING FROM USE OR 
* INABILITY TO USE THE SOFTWARE, INCLUDING, WITHOUT LIMITATION, ANY DIRECT, 
* INDIRECT, INCIDENTAL, SPECIAL OR CONSEQUENTIAL DAMAGES OR LOSS OF DATA, 
* SAVINGS OR PROFITS, 
* EVEN IF SPANSION HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES. 
* YOU ASSUME ALL RESPONSIBILITIES FOR SELECTION OF THE SOFTWARE TO ACHIEVE YOUR
* INTENDED RESULTS, AND FOR THE INSTALLATION OF, USE OF, AND RESULTS OBTAINED 
* FROM, THE SOFTWARE.  
*
* This software may be replicated in part or whole for the licensed use, 
* with the restriction that this Disclaimer and Copyright notice must be 
* included with each copy of this software, whether used in part or whole, 
* at all times.
******************************************************************************/
/* __DISCLAIMER_END__                                                        */
/*****************************************************************************/
/** \file start.h
 **
 ** \brief Device dependent, tool-chain independent C header for device initialization
 **
 ** This file allows to configure device settings and declares functions that
 ** are called from the startup script. All items marked by "<<<" can be
 ** configured to influence the device initialization.
 **
 ** \note Function Start_PreInit() will be called prior to global variable
 ** initialization.
 **
 ** History:
 **   - 2013-12-09  0.01    FTo Initial version for Traveo
 **   - 2014-02-14  0.04    FTo Added reference to Main_stcClearEccMemories.
 **   - 2014-02-17  0.05    FTo Rename Main_stcClearEccMemories to Start_stcClearEccMemories.
 **                             Added TcmRam/BuRAM to Start_stcClearEccMemories.
 *****************************************************************************/

#ifndef __START_H__
#define __START_H__

// File version YYXX = vYY.XX
#define START_H_VERSION          0x0005

#ifndef __FILE_VERSION_CHECK__

/*****************************************************************************/
/* Include files                                                             */
/*****************************************************************************/
#include "base_types.h"

/*****************************************************************************/
/* Global pre-processor symbols/macros ('#define')                           */
/*****************************************************************************/
/** System RAM start address */
#define SYSRAM_START_ADDRESS        MCU_SYSRAM_BASE_ADDRESS
/** System RAM size in byte */
#define SYSRAM_SIZE_BYTE            MCU_SYSRAM_SIZE_BYTE
/** Retention RAM start address */
#define BURAM_START_ADDRESS         MCU_BURAM_BASE_ADDRESS
/** Retention RAM size in byte */
#define BURAM_SIZE_BYTE             MCU_BURAM_SIZE_BYTE
/** TCMRAM start address (TCMRAM AXI slave interface - no DMA access via TCM port)
 ** The start stack (located at the beginning of TCM RAM) must be excluded. It is
 ** defined and ECC initialized in the start assembly file. */
#define TCMRAM_AXI_START_ADDRESS    MCU_TCMRAM_ADDRESS_TCM2AXI(0)
/** TCMRAM size in byte */
#define TCMRAM_SIZE_BYTE            MCU_TCMRAM_SIZE_BYTE

/*****************************************************************************/
/* Global type definitions ('typedef')                                       */
/*****************************************************************************/
typedef struct stc_clear_ecc_memories
{
    uint32_t    u32TcmRamStartAddress;  ///< TCMRAM memory to ECC clean : Begin
    uint32_t    u32TcmRamSizeByte;      ///< TCMRAM memory to ECC clean : Size in bytes
    uint32_t    u32SysRamStartAddress;  ///< SYSRAM memory to ECC clean : Begin
    uint32_t    u32SysRamSizeByte;      ///< SYSRAM memory to ECC clean : Size in bytes
    uint32_t    u32BuRamStartAddress;   ///< BURAM  memory to ECC clean : Begin
    uint32_t    u32BuRamSizeByte;       ///< BURAM  memory to ECC clean : Size in bytes
    uint32_t    u32EthRamStartAddress;  ///< ETHRAM memory to ECC clean : Begin
    uint32_t    u32EthRamSizeByte;      ///< ETHRAM memory to ECC clean : Size in bytes
    uint32_t    u32VRamStartAddress;    ///< VRAM   memory to ECC clean : Begin
    uint32_t    u32VRamSizeByte;        ///< VRAM   memory to ECC clean : Size in bytes
}   stc_clear_ecc_memories_t;

/*****************************************************************************/
/* Global variable declarations ('extern', definition in C source)           */
/*****************************************************************************/
extern  const   stc_clear_ecc_memories_t    Start_stcClearEccMemories;

/*****************************************************************************/
/* Global function prototypes ('extern', definition in C source)             */
/*****************************************************************************/

extern void Start_PreInit(void);
extern void Start_Init(void);

#endif /* __FILE_VERSION_CHECK__ */
#endif /* __START_H__ */

