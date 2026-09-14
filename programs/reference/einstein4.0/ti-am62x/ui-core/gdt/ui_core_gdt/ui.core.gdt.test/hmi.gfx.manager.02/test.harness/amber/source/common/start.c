/******************************************************************************
 * $Revision: 10552 $
 * $Date: 2014-10-17 13:52:06 +0200 (Fri, 17 Oct 2014) $
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
/** \file start.c
 **
 ** \brief Device independent, tool-chain independent C-like code for 
 ** clock and cache initialization.
 **
 ** This file implements functions that are called from the startup script.
 **
 ** \note Some of the functions may be called prior to global variable
 ** initialization.
 **
 ** History:
 **   - 2013-12-09  0.01    FTo Initial version for Traveo
 **   - 2014-01-28  0.02    FTo Fixed some bugs in the system controller init.
 **   - 2014-02-14  0.04    FTo Added reference to Main_stcClearEccMemories.
 **   - 2014-02-17  0.05    FTo Added TcmRam to Start_stcClearEccMemories
 **                             Updated range for VCO (400..800) MHz
 **                             Fixed error on assigning DIVN to register.
 **   - 2014-08-06  0.06    FTo Added SSCG0
 **                             Added register SYSC1_RUNCKER0
 **                             Enabled VDP3 GPIO Ports
 **   - 2014-08-11  0.07    FTo Added HSSPI clock divider
 **   - 2014-08-12  0.08    FTo Added ClearWatchdog() in all loops.
 **   - 2014-08-15  0.09    FTo Change order of calls in Start_PreInit(void)
 **                             ClearEccRamWaitCompletion() before
 **                             ConfigureClocks();
 **                             Removed ClearWatchdog() workaround.
 **   - 2014-09-03  0.10    CEy Add comment to Start_PreInit(void),
 **                             Move and fixed I/O-reset release code,
 **                             PLL0 VCO max frequency in formula corrected,
 **                             Changed order of calls again so that DMA init
 **                             runs after clock config with fast clocks,
 **                             Fixed clock setup (some bitfields would have
 **                             been written to 0 unintentionally, MCU would
 **                             have run out-of spec due to some other settings
 **                             added further clock selection and dividers),
 **                             Fixed Flash waitstates, some cosmetic changes
 **   - 2014-09-15  0.12    CEy Replaced clock dividers with more comprehensible
 **                             defines.
 **   - 2014-10-07  0.14    CEy Improved ConfigureClocks(), keep some default
 **                             values in DMA registers
 *****************************************************************************/

// File version 0xYYXX = vYY.XX
#define START_C_VERSION     0x0014

#ifndef __FILE_VERSION_CHECK__

/*****************************************************************************/
/* Include files                                                             */
/*****************************************************************************/
#include "start.h"
#include "base_types.h"
#include "exceptions.h"
#include "interrupts.h"
#include "abstract.h"
#include "mcu_settings.h"

/*****************************************************************************/
/* Local pre-processor symbols/macros ('#define')                            */
/*****************************************************************************/

//------------------------------------------------------------------
//  Macros for ECC memory initialization
//------------------------------------------------------------------

/** DMA transfer width setting for 32-bit access (register DMACB0:TW) */
#define DMA_TRANSFER_WIDTH_32BIT    2
/** DMA transfer width setting for 64-bit access (register DMACB0:TW) */
#define DMA_TRANSFER_WIDTH_64BIT    3

/** DMA block size in byte (valid range: 1...16) */
#define DMA_BLOCK_SIZE         16

/** Start address of TCM RAM setting in startup file (asm) where the start-up stack is located (for validation purposes only). */
#define STARTUP_TCMRAM_START_ADDRESS    0x00000000

/** TCMRAM maximal supported access width (set DMA_TRANSFER_WIDTH_???) */
#define TCMRAM_MAX_ACCESS_WIDTH     DMA_TRANSFER_WIDTH_64BIT
/** Key to unlock the TCMRAM configuration registers by writing to TRCFGn_TCMUNLOCK register */
#define TCMRAM_KEY_UNLOCK           0xACC55ECC
/** Key to lock the TCMRAM configuration registers by writing to TRCFGn_TCMUNLOCK register */
#define TCMRAM_KEY_LOCK             0x5ECCB10C

/** System RAM maximal supported access width (set DMA_TRANSFER_WIDTH_???) */
#define SYSRAM_MAX_ACCESS_WIDTH     DMA_TRANSFER_WIDTH_64BIT
/** Key to unlock the System RAM configuration registers by writing to SRCFG_KEY register */
#define SYSRAM_KEY_UNLOCK           0x5ECC551F
/** Key to lock the System RAM configuration registers by writing to SRCFG_KEY register */
#define SYSRAM_KEY_LOCK             0x551FB10C

/** Backup RAM maximal supported access width (set DMA_TRANSFER_WIDTH_???) */
#define BURAM_MAX_ACCESS_WIDTH      DMA_TRANSFER_WIDTH_32BIT
/** Key to unlock the Backup RAM configuration registers by writing to BURIF_UNLOCK register */
#define BURAM_KEY_UNLOCK            0xACC55ECC
/** Key to lock the Backup RAM configuration registers by writing to BURIF_UNLOCK register */
#define BURAM_KEY_LOCK              0x5ECCB10C

/** Key to unlock the TCFLASH configuration registers by writing to TCFCFG_FCPROTKEY register */
#define TCFLASH_KEY_UNLOCK          0xCF61F1A5

/** Key to unlock the WorkFlash configuration registers by writing to WFCFG_CPR register */
#define WFLASH_KEY_UNLOCK           0xCF6DF1A5

//------------------------------------------------------------------
//  Macros for clock selection, division and PLL settings
//------------------------------------------------------------------

/** Key to unlock one access to a System Controller configuration register by writing to SYSC0_PROTKEYR/SYSC1_PROTKEYR register */
#define SYSC_KEY_UNLOCK                     0x5CACCE55

/** Trigger to start state transition to RUN profile settings by writing to SYSC0_TRGRUNCNTR register */
#define SYSC_TRIGGER_APPLY_RUN_PROFILE      0xAB

/** Minimum PLL frequency supported for PLL0 (this is only for calculation,
 ** please refer to the appropriate device datasheet) */
#define SYSC_PLL0_FREQUENCY_MIN_HZ            8000000UL
/** Maximum PLL frequency supported for PLL0 (this is only for calculation,
 ** please refer to the appropriate device datasheet)
 ** Actually, frequency can be much higher but it is assumed that SYSDIV will be 1
 */
#define SYSC_PLL0_FREQUENCY_MAX_HZ          190000000UL
/** Maximum PLL input frequency (after DIVL input divider, refer to device datasheet) */
#define SYSC_PLL0_INPUT_FREQUENCY_MAX_HZ     25000000UL
/** Minimum PLL0 multiplication factor */
#define SYSC_PLL0_DIVN_MIN                  13      //DIVN : valid values : 13 .. 200
/** Maximum PLL0 multiplication factor */
#define SYSC_PLL0_DIVN_MAX                  200     //DIVN : valid values : 13 .. 200
/** Minimum PLL0 output divider 
 ** The register value is: INTEGER(value / 2). */
#define SYSC_PLL0_DIVM_MIN                  2       //DIVM always must be an even number
/** Maximum PLL0 output divider 
 ** The register value is: INTEGER(value / 2). */
#define SYSC_PLL0_DIVM_MAX                  30      //DIVM always must be an even number

/** When using a crystal oscillator or opposite phase external clock, always try
 ** to use smallest divider as possible to divide the PLL input clock to achieve
 ** the smallest clock jitter. But it must be ensured that input clock frequency
 ** is less than or equal to 16 MHz, since PLL does not support input clock frequency more
 ** than that.
 ** The register value is: INTEGER(value / 2). */
#if(MCU_FREQ_CLK_MAIN_HZ <= SYSC_PLL0_INPUT_FREQUENCY_MAX_HZ)
    #define SYSC_PLL0_DIVL                  1       //DIVL : valid values : 1,2,4,6
#else   
    #define SYSC_PLL0_DIVL                  2       //DIVL : valid values : 1,2,4,6
#endif

/** PLL0 output divider. Starting with max. VCO output frequency of 800 MHz.
 ** DIVM must be multiple of 2. Range 2 ... 30. 
 ** The register value is: INTEGER(value / 2). */
#define SYSC_PLL0_DIVM          (((800000000UL / (MCU_FREQ_CLK_PLL0_HZ)) / 2) * 2)
    
/** Calculated PLL0 input multiplication factor. The register value is: value - 1. */
#define SYSC_PLL0_DIVN          (((MCU_FREQ_CLK_PLL0_HZ) * (SYSC_PLL0_DIVM) * (SYSC_PLL0_DIVL)) / (MCU_FREQ_CLK_MAIN_HZ))

/** Minimum PLL frequency supported for SSCG PLL (this is only for calculation,
 ** please refer to the appropriate device datasheet) */
#define SYSC_SSCG0_FREQUENCY_MIN_HZ          8000000UL
/** Maximum PLL frequency supported for SSCG PLL (this is only for calculation,
 ** please refer to the appropriate device datasheet) */
#define SYSC_SSCG0_FREQUENCY_MAX_HZ        400000000UL
/** Maximum PLL input frequency (after DIVL input divider, refer to device datasheet) */
#define SYSC_SSCG0_INPUT_FREQUENCY_MAX_HZ   25000000UL
/** Minimum SSCG PLL multiplication factor */
#define SYSC_SSCG0_DIVN_MIN                  13      //DIVN : valid values : 13 .. 200
/** Maximum SSCG PLL multiplication factor */
#define SYSC_SSCG0_DIVN_MAX                  200     //DIVN : valid values : 13 .. 200
/** Minimum SSCG PLL output divider 
 ** The register value is: INTEGER(value / 2). */
#define SYSC_SSCG0_DIVM_MIN                  2       //DIVM always must be an even number
/** Maximum SSCG PLL output divider 
 ** The register value is: INTEGER(value / 2). */
#define SYSC_SSCG0_DIVM_MAX                  30      //DIVM always must be an even number

/** When using a crystal oscillator or opposite phase external clock, always try
 ** to use smallest divider as possible to divide the PLL input clock to achieve
 ** the smallest clock jitter. But it must be ensured that input clock frequency
 ** is less than or equal to 16 MHz, since PLL does not support input clock frequency more
 ** than that.
 ** The register value is: INTEGER(value / 2). */
#if(MCU_FREQ_CLK_MAIN_HZ <= SYSC_SSCG0_INPUT_FREQUENCY_MAX_HZ)
    #define SYSC_SSCG0_DIVL                  1       //DIVL : valid values : 1,2,4,6
#else   
    #define SYSC_SSCG0_DIVL                  2       //DIVL : valid values : 1,2,4,6
#endif

/** SSCG0 output divider. Starting with max. VCO output frequency of 480 MHz.
 ** DIVM must be multiple of 2. Range 2 ... 30. 
 ** The register value is: INTEGER(value / 2). */
#define SYSC_SSCG0_DIVM         (((800000000UL / (MCU_FREQ_CLK_SSCG0_HZ)) / 2) * 2)
    
/** Calculated SSCG PLL input multiplication factor. The register value is: value - 1. */
#define SYSC_SSCG0_DIVN          (((MCU_FREQ_CLK_SSCG0_HZ) * (SYSC_SSCG0_DIVM) * (SYSC_SSCG0_DIVL)) / (MCU_FREQ_CLK_MAIN_HZ))

/** Main source clock timer pre-scaler for main osc. stabilization time.
 ** Effective value: 2^SYSC_MAIN_SCT_PRESCALER */
#define SYSC_MAINSCT_PRESCALER      6

/** Calculate main oscillation stabilization time setting */
#define SYSC_MAINSCT_CMPR          (((MCU_FREQ_CLK_MAIN_HZ / (1 << (SYSC_MAINSCT_PRESCALER))) * MCU_STAB_TIME_CLK_MAIN_MS + 500UL) / 1000UL)

/** Clock divider defines for registers where "register bit-field value" = (divider - 1), like the RUNCKDIVRx registers */
#define DIV_BY_1      0
#define DIV_BY_2      1
#define DIV_BY_3      2
#define DIV_BY_4      3
#define DIV_BY_5      4
#define DIV_BY_6      5
#define DIV_BY_7      6
#define DIV_BY_8      7
#define DIV_BY_9      8
#define DIV_BY_10     9
#define DIV_BY_11     10
#define DIV_BY_12     11
#define DIV_BY_13     12
#define DIV_BY_14     13
#define DIV_BY_15     14
#define DIV_BY_16     15
#define DIV_BY_17     16
#define DIV_BY_18     17
#define DIV_BY_19     18
#define DIV_BY_20     19
#define DIV_BY_21     20
#define DIV_BY_22     21
#define DIV_BY_23     22
#define DIV_BY_24     23
#define DIV_BY_25     24
#define DIV_BY_26     25
#define DIV_BY_27     26
#define DIV_BY_28     27
#define DIV_BY_29     28
#define DIV_BY_30     29
#define DIV_BY_31     30
#define DIV_BY_32     31


//------------------------------------------------------------------
//  Macros for Watchdog configuration
//------------------------------------------------------------------

#define WDG_KEY_UNLOCK              0xEDACCE55     // Write this key to unlock the Watchdog registers for writing
//------------------------------------------------------------------
//  Macros for ECC configuration of the I-cache and the D-cache
//------------------------------------------------------------------
/* C1 Auxiliary Control Register CEC bit setting */
#if MCU_CACHE_ECC_ENABLE == MCU_ENABLE
    #if MCU_CACHE_ECC_ABORT_ENABLE == MCU_ENABLE
        #if MCU_CACHE_ECC_FORCE_WRITE_THROUGH == MCU_ENABLE
            #define	CACHE_CEC_SETTING   0x2 /* enable ECC, force write through, enable ABORT generation */
        #else
            #define	CACHE_CEC_SETTING   0x0 /* enable ECC, enable ABORT generation */
        #endif
    #else
        #if MCU_CACHE_ECC_FORCE_WRITE_THROUGH == MCU_ENABLE
            #define	CACHE_CEC_SETTING   0x6 /* enable ECC, force write through, disable ABORT generation */
        #else
            #define	CACHE_CEC_SETTING   0x5 /* enable ECC, disable ABORT generation */
        #endif
    #endif
    #define CACHE_DBWR_SETTING  0x1 /* ACTLR.DBWR = 1 */
#else
    #define	CACHE_CEC_SETTING   0x4 /* disable ECC */
    #define CACHE_DBWR_SETTING  0x0 /* ACTLR.DBWR = 0 */
#endif

//------------------------------------------------------------------
//  Check macro values
//------------------------------------------------------------------

// Check DMA block size settings
#if (((DMA_BLOCK_SIZE) < 1) || ((DMA_BLOCK_SIZE) > 16))
    #error DMA_BLOCK_SIZE invalid (valid range: 1...16)
#endif

// Check memory start addresses
#if (((SYSRAM_START_ADDRESS) % (1 << (SYSRAM_MAX_ACCESS_WIDTH))) != 0)
    #error SYSRAM_START_ADDRESS invalid (multiple of DMA transfer width required)
#endif
#if (((BURAM_START_ADDRESS) % (1 << (BURAM_MAX_ACCESS_WIDTH))) != 0)
    #error BURAM_START_ADDRESS invalid (multiple of DMA transfer width required)
#endif

// Check memory sizes
#if (((MCU_TCMRAM_SIZE_BYTE) % ((1 << (TCMRAM_MAX_ACCESS_WIDTH)) * (DMA_BLOCK_SIZE))) != 0)
    #error MCU_TCMRAM_SIZE_BYTE invalid (multiple of (DMA_BLOCK_SIZE * DMA transfer width) required)
#endif
#if (((SYSRAM_SIZE_BYTE) % ((1 << (SYSRAM_MAX_ACCESS_WIDTH)) * (DMA_BLOCK_SIZE))) != 0)
    #error SYSRAM_SIZE_BYTE invalid (multiple of (DMA_BLOCK_SIZE * DMA transfer width) required)
#endif
#if (((BURAM_SIZE_BYTE) % ((1 << (BURAM_MAX_ACCESS_WIDTH)) * (DMA_BLOCK_SIZE))) != 0)
    #error BURAM_SIZE_BYTE invalid (multiple of (DMA_BLOCK_SIZE * DMA transfer width) required)
#endif

// Check consistency of ASM and C pre-processor macros
#if ((STARTUP_TCMRAM_START_ADDRESS) != (MCU_TCMRAM_TCM_INTERFACE_BASE_ADDRESS))
    #error Value mismatch (STARTUP_TCMRAM_START_ADDRESS != MCU_TCMRAM_TCM_INTERFACE_BASE_ADDRESS)!
#endif

// Check for main osc. stabilization time minimum value (to prevent 0-setting)
#if ((MCU_STAB_TIME_CLK_MAIN_MS) < 5UL)
  #error MCU_STAB_TIME_CLK_MAIN_MS invalid (below minimum value)!
#endif
// Check for main osc. stabilization time maximum value (16-bit counter)
#if (((65535UL * 1000UL) / (MCU_FREQ_CLK_MAIN_HZ / (1 << (SYSC_MAINSCT_PRESCALER)))) < (MCU_STAB_TIME_CLK_MAIN_MS))
  #error MCU_STAB_TIME_CLK_MAIN_MS invalid (exceeds maximum value for current MCU_FREQ_CLK_MAIN_HZ and SYSC_MAINSCT_PRESCALER)!
#endif



// Check PLL0 frequency minimum value
#if ((MCU_FREQ_CLK_PLL0_HZ) < (SYSC_PLL0_FREQUENCY_MIN_HZ))
    #error MCU_FREQ_CLK_PLL0_HZ invalid (below minimum value)!
#endif
// Check PLL0 frequency maximum value
#if ((MCU_FREQ_CLK_PLL0_HZ) > (SYSC_PLL0_FREQUENCY_MAX_HZ))
    #error MCU_FREQ_CLK_PLL0_HZ invalid (exceeds maximum value)!
#endif
// Check PLL0 settings (target PLL frequency vs. resulting PLL frequency)
#if ((MCU_FREQ_CLK_PLL0_HZ) != ((((MCU_FREQ_CLK_MAIN_HZ) / (SYSC_PLL0_DIVL)) * (SYSC_PLL0_DIVN)) / (SYSC_PLL0_DIVM)))
    #error No PLL0 settings found for current MCU_FREQ_CLK_MAIN_HZ and MCU_FREQ_CLK_PLL0_HZ (DIVN no integer)!
#endif
// Check for correct VCO output frequency range (400 ... 800 MHz)
#if ((((MCU_FREQ_CLK_PLL0_HZ) * (SYSC_PLL0_DIVM)) < 400000000UL) || (((MCU_FREQ_CLK_PLL0_HZ) * (SYSC_PLL0_DIVM)) > 800000000UL))
    #error PLL0 settings wrong - VCO output frequency out of range (400 MHz .. 800 MHz)!
#endif
// Check PLL0 input divider for valid values (1, 2, 4, 6)
#if (((SYSC_PLL0_DIVL) != 1) && ((SYSC_PLL0_DIVL) != 2) && ((SYSC_PLL0_DIVL) != 4) && ((SYSC_PLL0_DIVL) != 6))
    #error No PLL0 settings found for current MCU_FREQ_CLK_MAIN_HZ and MCU_FREQ_CLK_PLL0_HZ (DIVL outside valid range)!
#endif
// Check PLL0 multiplication factor for minimum/maximum value
#if (((SYSC_PLL0_DIVN) < (SYSC_PLL0_DIVN_MIN)) || ((SYSC_PLL0_DIVN) > (SYSC_PLL0_DIVN_MAX)))
    #error No PLL0 settings found for current MCU_FREQ_CLK_MAIN_HZ and MCU_FREQ_CLK_PLL0_HZ (DIVN outside valid range)!
#endif
// Check PLL0 output divider for minimum/maximum value
#if ((((SYSC_PLL0_DIVM) < (SYSC_PLL0_DIVM_MIN)) || ((SYSC_PLL0_DIVM) > (SYSC_PLL0_DIVM_MAX))) || ((((SYSC_PLL0_DIVM) & 0x1) == 1) && ((SYSC_PLL0_DIVM) != 1)))
    #error No PLL0 settings found for current MCU_FREQ_CLK_MAIN_HZ and MCU_FREQ_CLK_PLL0_HZ (DIVM outside valid range)!
#endif



// Check SSCG0 frequency minimum value
#if ((MCU_FREQ_CLK_SSCG0_HZ) < (SYSC_SSCG0_FREQUENCY_MIN_HZ))
    #error MCU_FREQ_CLK_SSCG0_HZ invalid (below minimum value)!
#endif
// Check SSCG0 frequency maximum value
#if ((MCU_FREQ_CLK_SSCG0_HZ) > (SYSC_SSCG0_FREQUENCY_MAX_HZ))
    #error MCU_FREQ_CLK_SSCG0_HZ invalid (exceeds maximum value)!
#endif
// Check SSCG0 settings (target PLL frequency vs. resulting PLL frequency)
#if ((MCU_FREQ_CLK_SSCG0_HZ) != ((((MCU_FREQ_CLK_MAIN_HZ) / (SYSC_SSCG0_DIVL)) * (SYSC_SSCG0_DIVN)) / (SYSC_SSCG0_DIVM)))
    #error No SSCG0 settings found for current MCU_FREQ_CLK_MAIN_HZ and MCU_FREQ_CLK_SSCG0_HZ (DIVN no integer)!
#endif
// Check for correct VCO output frequency range (400 ... 800 MHz)
#if ((((MCU_FREQ_CLK_SSCG0_HZ) * (SYSC_SSCG0_DIVM)) < 400000000UL) || (((MCU_FREQ_CLK_SSCG0_HZ) * (SYSC_SSCG0_DIVM)) > 800000000UL))
    #error SSCG0 settings wrong - VCO output frequency out of range (400 MHz .. 800 MHz)!
#endif
// Check SSCG0 input divider for valid values (1, 2, 4, 6)
#if (((SYSC_SSCG0_DIVL) != 1) && ((SYSC_SSCG0_DIVL) != 2) && ((SYSC_SSCG0_DIVL) != 4) && ((SYSC_SSCG0_DIVL) != 6))
    #error No SSCG0 settings found for current MCU_FREQ_CLK_MAIN_HZ and MCU_FREQ_CLK_SSCG0_HZ (DIVL outside valid range)!
#endif
// Check SSCG0 multiplication factor for minimum/maximum value
#if (((SYSC_SSCG0_DIVN) < (SYSC_SSCG0_DIVN_MIN)) || ((SYSC_SSCG0_DIVN) > (SYSC_SSCG0_DIVN_MAX)))
    #error No SSCG0 settings found for current MCU_FREQ_CLK_MAIN_HZ and MCU_FREQ_CLK_SSCG0_HZ (DIVN outside valid range)!
#endif
// Check SSCG0 output divider for minimum/maximum value
#if ((((SYSC_SSCG0_DIVM) < (SYSC_SSCG0_DIVM_MIN)) || ((SYSC_SSCG0_DIVM) > (SYSC_SSCG0_DIVM_MAX))) || ((((SYSC_SSCG0_DIVM) & 0x1) == 1) && ((SYSC_SSCG0_DIVM) != 1)))
    #error No SSCG0 settings found for current MCU_FREQ_CLK_MAIN_HZ and MCU_FREQ_CLK_SSCG0_HZ (DIVM outside valid range)!
#endif

/*****************************************************************************/
/* Global variable definitions (declared in header file with 'extern')       */
/*****************************************************************************/
extern  const   uint32_t    ADDRESS_BOOT_USR_STACK_END;

/*****************************************************************************/
/* Local type definitions ('typedef')                                        */
/*****************************************************************************/

/*****************************************************************************/
/* Local function prototypes ('static')                                      */
/*****************************************************************************/
static void ConfigureClocks(void);
static void ConfigureMemories(void);
static void ClearEccRamStart(void);
static void ClearEccRamWaitCompletion(void);
static void ConfigureCaches(void);
static void EnableInstructionCache(void);
static void EnableDataCache(void);
static void EnableCacheECC(void);

/*****************************************************************************/
/* Local variable definitions ('static')                                     */
/*****************************************************************************/

/*****************************************************************************/
/* Function implementation - global ('extern') and local ('static')          */
/*****************************************************************************/

/******************************************************************************
 ** \brief Speed-up the system before initialization
 ** 
 ** \e Purpose: Start_PreInit shall make all the settings that should be made 
 ** before start of the system library initialization. These settings are 
 ** concerning execution speed-up like clock settings and caching.
 **
 ** \pre C-like code can be executed. I.e. no global variables/Objects are 
 ** initialized and no calls to standard lib may be done.
 ** Interrupts are disabled.
 **
 ** \post The system is in a state where the initialization of the system 
 ** library can be performed.
 **
 ** \e Side \e effects: There may be clocks (e.g. PLL) that do not take effect 
 ** immediately, but need some time to stabilize. Hence the clock frequency is 
 ** not guaranteed after return from Start_PreInit and may change at some 
 ** point in the future.
 **
 ** \note Waiting for clock stabilization could optionally be done before 
 ** returning. Depending on the clock configuration waiting for clock 
 ** stabilization within Start_PreInit can probably take a lot of time. 
 ** Therefore the system start-up time can be reduced by doing tasks in the 
 ** meantime that are not clock-dependent. In general the initialization of 
 ** the system library is such a task. Wait for clock stabilization can also 
 ** be done after initialization of the system library.
 *****************************************************************************/
void Start_PreInit(void)
{
    // Now we are running on RC
    
    // Release I/O-resets (3V, 3/5V domains)
    SYSC0_PROTKEYR = SYSC_KEY_UNLOCK;
    SYSC0_SPECFGR_IO35RSTC = 0;
    SYSC0_PROTKEYR = SYSC_KEY_UNLOCK;
    SYSC0_SPECFGR_IO3RSTC = 0;
    
    // Re-map exception vectors of BootROM's vector table to
    // application specific exception handlers
    Exceptions_Init();
    
    // Configure internal memories
    ConfigureMemories();
    
    // Configure clocks
    ConfigureClocks();
    
    // Start to clear all RAM areas that have ECC logic enabled
    ClearEccRamStart();
       
    // Wait for completion of ECC RAM clearing
    // Order of calls of ClearEccRamWaitCompletion() and ConfigureClocks() changed:
    // Write accesses to Backup-RAM by DMA are considered as write accesses to MCU_CONFIG_BUS
    // which reset the protection key write state for System Controller hence leading to
    // sporadic Data Aborts in ConfigureClocks() if this function is executed simultaneously
    // to Backup-RAM initialization.
    // --> This will be fixed on future devices, order should then be changed again.
    ClearEccRamWaitCompletion();    

    // Configure cache
    ConfigureCaches();

    /* 
    Now everything is ready to initialize the memories i.e.
    copy initial values from flash to RAM.
    
    The zero sections can be skipped (if the toolchain allows)
    as all ECC RAMs are set to '0' via DMA already.
    */
}

/******************************************************************************
 ** \brief Finalize system initialization
 **
 ** \e Purpose: Start_Init shall make all the settings that should be made 
 ** after initialization of the system library but before application 
 ** execution. This will initialize the interrupts (IRQ and NMI) and enable
 ** them globally.
 **
 ** \pre System library initialization is finished, i.e. all global and static  
 ** variables/objects are initialized and all C/C++ library functionality is 
 ** available.
 **
 ** \post The system is in a defined state, depending on the configuration.
 *****************************************************************************/
void Start_Init(void)
{
    // Now we are running on PLL0
    
    // Initialize interrupts (NMIs)
    Interrupts_InitNmi();

    // Globally enable NMIs (cannot be disabled anymore)
    NMI_ENABLE();

    // Initialize interrupts (IRQs)
    Interrupts_InitIrq();

    // Globally enable IRQs
    IRQ_ENABLE();
}

/******************************************************************************
 ** \brief Configures clocks
 **
 ** The function will configure a RUN profile according to the settings
 ** below. It will synchronously wait for the completion of the state
 ** transition to the new RUN profile.
 **
 ** RUN profile settings:
 ** - all Power Domains enabled (PD2,PD3,PD4,PD5,PD6)
 ** - Source oscillation:
 **   > Main Oscillation:           enabled
 **   > Sub Oscillation:            disabled
 **   > Fast RC Oscillation:        enabled
 **   > Slow RC Oscillation:        enabled
 ** - PLLs:
 **   > PLL0:       enabled, configured for MCU_FREQ_CLK_PLL0_HZ
 **   > SSCG PLL:   enabled, configured for MCU_FREQ_CLK_SSCG0_HZ
 ** - Clock selection:
 **   > See comment below in the code
 ** - Oscillation stabilization wait time (default)
 ** - Low Voltage Detection (default settings, will cause reset in case of LV)
 ** - Clock Supervisors (all disabled)   
 **
 ** \note The sub-oscillator will be disabled in this function, to speed up
 **       the start-up process. Otherwise the time for switching system
 **       clock to PLL would be prolonged by the sub-oscillator stabilization
 **       time, typically about 300 ms (default 2 s).
 **       It is recommended to enable the sub-oscillator after this function
 **       and without synchronously waiting for RUN-2-RUN completion.
 *****************************************************************************/
static void ConfigureClocks(void)
{
    //------------------------------------------------------------------
    //  Set main oscillator and PLL stabilization times
    //------------------------------------------------------------------

    // Main Clock settings
    SYSC0_PROTKEYR                  =   SYSC_KEY_UNLOCK;    
    SYSC_7.unMOSCCNTR.stcField      =   (stc_sysc_7_mosccntr_field_t){      .u1DIV2SEL      =  0,    // Main clock not divided by 2
                                                                            .u2MCGAIN       =  0,    // Main clock gain characteristic for 4MHz
                                                                            .u1MCMODE       =  0,    // Main clock amplifier oscillation mdoe
                                                                            .u1FCIMEN       =  0 };  // Fast clock input mode is disabled
  
    // Set new main oscillation stabilization time
    SYSC0_PROTKEYR                  =   SYSC_KEY_UNLOCK;    
    SYSC_6.unMOCTCPR.stcField       =   (stc_sysc_6_moctcpr_field_t){       .u4PSCL         =  SYSC_MAINSCT_PRESCALER,   // pre-scaler
                                                                            .u16CMPR        =  SYSC_MAINSCT_CMPR };      // compare value
    // Trigger configuration capture
    SYSC0_PROTKEYR                  =   SYSC_KEY_UNLOCK;    
    SYSC_6.unMOCTTRGR.stcField      =   (stc_sysc_6_mocttrgr_field_t)  {    .u1CGCPT        =  1 };      
  
    // Reduce PLL stabilization times to 2^12 main clock cycles
    SYSC0_PROTKEYR                  =   SYSC_KEY_UNLOCK;    
    SYSC_7.unPLLSSCGSTCNTR.stcField =   (stc_sysc_7_pllsscgstcntr_field_t) {.u4SSCGSTABS    =  0xB,
                                                                            .u4PLLSTABS     =  0xB };
    
    //------------------------------------------------------------------
    //  Configure run profile
    //------------------------------------------------------------------
    // Enable power domains
    SYSC0_PROTKEYR                  =   SYSC_KEY_UNLOCK;    
    SYSC0_1.unRUNPDCFGR.stcField    =   (stc_sysc0_1_runpdcfgr_field_t){    .u1PD6_1EN      =  1,      // switch on PD6_1 ()
                                                                            .u1PD6_0EN      =  1,      // switch on PD6_0 ()
                                                                            .u1PD5_3EN      =  1,      // switch on PD5_3 ()
                                                                            .u1PD5_2EN      =  1,      // switch on PD5_2 ()
                                                                            .u1PD5_1EN      =  1,      // switch on PD5_1 ()
                                                                            .u1PD5_0EN      =  1,      // switch on PD5_0 ()
                                                                            .u1PD4_1EN      =  1,      // switch on PD4_1 (Backup RAM1)
                                                                            .u1PD4_0EN      =  1,      // switch on PD4_0 (Backup RAM0)
                                                                            .u1PD3EN        =  1,      // always on (Core)
                                                                            .u1PD2EN        =  1 };    // always on (Peripheral)
    
    // Enable oscillators    
    SYSC0_PROTKEYR                  =   SYSC_KEY_UNLOCK;        
    SYSC0_1.unRUNCKSRER.stcField    =   (stc_sysc0_1_runcksrer_field_t) {   .u1CROSCEN      =  1,      // RC Osc. (always on in RUN state)
                                                                            .u1SCROSCEN     =  1,      // enable Slow RC Osc.
                                                                            .u1MOSCEN       =  1,      // enable Main Oscillation
                                                                            .u1SOSCEN       =  0,      // disable Sub Oscillation
                                                                            .u1PLL0EN       =  1,      // enable PLL0
                                                                            .u1PLL1EN       =  0,      // disable PLL1
                                                                            .u1PLL2EN       =  0,      // disable PLL2
                                                                            .u1PLL3EN       =  0,      // disable PLL3
                                                                            .u1SSCG0EN      =  1,      // enable SSCG0
                                                                            .u1SSCG1EN      =  0,      // disable SSCG1
                                                                            .u1SSCG2EN      =  0,      // disable SSCG2
                                                                            .u1SSCG3EN      =  0 };    // disable SSCG3
    
    //------------------------------------------------------------------    
    // Write PLL0 settings    
    SYSC0_PROTKEYR                  =   SYSC_KEY_UNLOCK;        
    SYSC0_1.unRUNPLL0CNTR.stcField  =   (stc_sysc0_1_runpll0cntr_field_t){  .u1PLL0ISEL     =  0,                        // use Main Clock as PLL input clock
                                                                            .u8PLL0DIVN     =  (SYSC_PLL0_DIVN),         // set PLL input multiplication value
                                                                            .u4PLL0DIVM     =  (SYSC_PLL0_DIVM) / 2,     // set PLL output divider
                                                                            .u2PLL0DIVL     =  (SYSC_PLL0_DIVL) / 2 };   // set PLL input divider
    // Clock gear 
    SYSC0_PROTKEYR                  =   SYSC_KEY_UNLOCK;    
    SYSC_7.unPLL0CGCNTR.stcField    =   (stc_sysc_7_pllncgcntr_field_t){    .u8PLLCGLP      =  4,      // Loops per step
                                                                            .u2PLLCGSTP     =  1,      // 2 steps
                                                                            .u6PLLCGSSN     =  8,      // Start step = 8
                                                                            .u1PLLCGSTR     =  0,      // Do not start gear operation
                                                                            .u1PLLCGEN      =  1 };    // Enable
    
    //------------------------------------------------------------------    
    // Write SSCG0 settings    
    SYSC0_PROTKEYR                  =   SYSC_KEY_UNLOCK;        
    SYSC0_1.unRUNSSCG0CNTR0.stcField=   (stc_sysc0_1_runsscg0cntr0_field_t){.u1SSCG0ISEL    =  0,                        // use Main Clock as PLL input clock
                                                                            .u8SSCG0DIVN    =  (SYSC_SSCG0_DIVN),        // set PLL input multiplication value
                                                                            .u4SSCG0DIVM    =  (SYSC_SSCG0_DIVM) / 2,    // set PLL output divider
                                                                            .u2SSCG0DIVL    =  (SYSC_SSCG0_DIVL) / 2 };  // set PLL input divider
    SYSC0_PROTKEYR                  =   SYSC_KEY_UNLOCK;        
    SYSC0_1.unRUNSSCG0CNTR1.stcField=   (stc_sysc0_1_runsscg0cntr1_field_t){.u10SSCG0RATE   =  0x29,   // set clock modulation ratio to 0.5%
                                                                            .u1SSCG0MODE    =  0,      // set modulation mode to Down Spread Mode
                                                                            .u2SSCG0FREQ    =  0,      // set modulation frequency to (1/1024) x Fin
                                                                            .u1SSCG0SSEN    =  1 };    // Enable modulation
    // Clock gear 
    SYSC0_PROTKEYR                  =   SYSC_KEY_UNLOCK;    
    SYSC_7.unSSCG0CGCNTR.stcField   =   (stc_sysc_7_sscgncgcntr_field_t){   .u8SSCGCGLP     =  4,      // Loops per step
                                                                            .u2SSCGCGSTP    =  1,      // 2 steps
                                                                            .u6SSCGCGSSN    =  8,      // Start step = 8
                                                                            .u1SSCGCGSTR    =  0,      // Do not start gear operation
                                                                            .u1SSCGCGEN     =  1 };    // Enable
    
    //------------------------------------------------------------------
    // Select clock sources
    SYSC0_PROTKEYR                  =   SYSC_KEY_UNLOCK;     
    SYSC0_1.unRUNCKSELR.stcField    =   (stc_sysc0_1_runckselr_field_t){    .u3CDMCUCCSL    =  4 };    // MCUC clock domain = PLL0
    
    SYSC1_PROTKEYR                  =   SYSC_KEY_UNLOCK;    
    SYSC1.unRUNCKSELR0.stcField     =   (stc_sysc1_runckselr0_field_t){     .u4HSSPICSL     =  4,      // Hsspi clock domain = PLL0
                                                                            .u1LAPP1ACSL    =  0,      // LAPP1A clock = CD0
                                                                            .u1LAPP0ACSL    =  0,      // LAPP0A clock = CD0
                                                                            .u1LCP1ACSL     =  0,      // LCP1A clock = CD0
                                                                            .u1LCP0ACSL     =  0,      // LCP0A clock = CD0
                                                                            .u3CD0CSL       =  4 };    // Clock Domain 0 = PLL0
                                                                            
    SYSC1_PROTKEYR                  =   SYSC_KEY_UNLOCK;    
    SYSC1.unRUNCKSELR1.stcField     =   (stc_sysc1_runckselr1_field_t){     .u4CD1CSL       = 15,      // Clock domain 1 = tied low (nothing connected)
                                                                            .u4CD2CSL       =  8,      // Clock domain 2 = SSCG0
                                                                            .u4CD3CSL       =  8,      // Clock domain 3 = SSCG0
                                                                            .u4CD4CSL       =  4 };    // Clock domain 4 = PLL0
                                                                   
    SYSC1_PROTKEYR                  =   SYSC_KEY_UNLOCK;    
    SYSC1.unRUNCKSELR2.stcField     =   (stc_sysc1_runckselr2_field_t){     .u4CD5CSL       =  4,      // Clock domain 5 = PLL0
                                                                            .u3TRCCSL       =  4 };    // Trace clock domain = PLL0
                                                                            
                                                                   
                                                                            

    //------------------------------------------------------------------
    // Enable clocks
    SYSC1_PROTKEYR                  =   SYSC_KEY_UNLOCK;    
    SYSC1.unRUNCKER0.stcField       =   (stc_sysc1_runcker0_field_t) {      .u1ENCLKCPU0    =  1,      // Enable CPU0
                                                                            .u1ENCLKATB     =  1,      // Enable ATB
                                                                            .u1ENCLKDBG     =  1,      // Enable DBG
                                                                            .u1ENCLKTRC     =  1,      // Enable TRC
                                                                            .u1ENCLKHPM2    =  1,      // Enable HPM2
                                                                            .u1ENCLKHPM     =  1,      // Enable HPM
                                                                            .u1ENCLKDMA     =  1,      // Enable DMA
                                                                            .u1ENCLKMEMC    =  1,      // Enable MEMC
                                                                            .u1ENCLKEXTBUS  =  0,      // Disable EXTBUS (not available)
                                                                            .u1ENCLKSYSC1   =  1,      // Enable SYSC1
                                                                            .u1ENCLKHAPP0A0 =  1,      // Enable HAPP0A0
                                                                            .u1ENCLKHAPP0A1 =  1,      // Enable HAPP0A1
                                                                            .u1ENCLKHAPP1B0 =  1,      // Enable HAPP1B0
                                                                            .u1ENCLKHAPP1B1 =  1,      // Enable HAPP1B1
                                                                            .u1ENCLKLLPBM   =  1,      // Enable LLPBM
                                                                            .u1ENCLKLLPBM2  =  1,      // Enable LLPBM2
                                                                            .u1ENCLKLCP     =  1,      // Enable LCP
                                                                            .u1ENCLKLCP0    =  1,      // Enable LCP0
                                                                            .u1ENCLKLCP1    =  1,      // Enable LCP1
                                                                            .u1ENCLKLAPP0   =  1,      // Enable LAPP0
                                                                            .u1ENCLKLAPP1   =  1,      // Enable LAPP1
                                                                            .u1ENCLKLCP0A   =  1,      // Enable LCP0A
                                                                            .u1ENCLKLCP1A   =  1,      // Enable LCP1A
                                                                            .u1ENCLKLAPP0A  =  1,      // Enable LAPP0A
                                                                            .u1ENCLKLAPP1A  =  1 };    // Enable LAPP1A

    SYSC1_PROTKEYR                  =   SYSC_KEY_UNLOCK;    
    SYSC1.unRUNCKER1.stcField       =   (stc_sysc1_runcker1_field_t) {      .u1ENCLKCD3B1   =  1,      // Enable CD3B1
                                                                            .u1ENCLKCD3B0   =  1,      // Enable CD3B0
                                                                            .u1ENCLKCD3A1   =  1,      // Enable CD3A1
                                                                            .u1ENCLKCD3A0   =  1,      // Enable CD3A0 (IRIS axi_clk)
                                                                            .u1ENCLKCD3     =  1,      // Enable CD3
                                                                            .u1ENCLKCD2B1   =  1,      // Enable CD2B1
                                                                            .u1ENCLKCD2B0   =  1,      // Enable CD2B0
                                                                            .u1ENCLKCD2A1   =  1,      // Enable CD2A1
                                                                            .u1ENCLKCD2A0   =  1,      // Enable CD2A0 (IRIS ref_clk)
                                                                            .u1ENCLKCD2     =  1,      // Enable CD2
                                                                            .u1ENCLKCD1B1   =  0,      // Disable CD1B1 (nothing connected)
                                                                            .u1ENCLKCD1B0   =  0,      // Disable CD1B0 (nothing connected)
                                                                            .u1ENCLKCD1A1   =  0,      // Disable CD1A1 (nothing connected)
                                                                            .u1ENCLKCD1A0   =  0,      // Disable CD1A0 (nothing connected)
                                                                            .u1ENCLKCD1     =  0,      // Disable CD1   (nothing connected)
                                                                            .u1ENCLKHSSPI   =  1 };    // Enable HSSPI

    SYSC1_PROTKEYR                  =   SYSC_KEY_UNLOCK;    
    SYSC1.unRUNCKER2.stcField       =   (stc_sysc1_runcker2_field_t) {      .u1ENCLKCD5B1   =  1,      // Enable CD5B1
                                                                            .u1ENCLKCD5B0   =  1,      // Enable CD5B0
                                                                            .u1ENCLKCD5A1   =  1,      // Enable CD5A1
                                                                            .u1ENCLKCD5A0   =  1,      // Enable CD5A0
                                                                            .u1ENCLKCD5     =  1,      // Enable CD5
                                                                            .u1ENCLKCD4B1   =  1,      // Enable CD4B1
                                                                            .u1ENCLKCD4B0   =  1,      // Enable CD4B0
                                                                            .u1ENCLKCD4A1   =  1,      // Enable CD4A1
                                                                            .u1ENCLKCD4A0   =  1,      // Enable CD4A0
                                                                            .u1ENCLKCD4     =  1 };    // Enable CD4

    //------------------------------------------------------------------
    // Set clock dividers                                                                              // [max MHz] | [Source clock domain]: [Divider Chain]
    
    SYSC0_PROTKEYR                  =   SYSC_KEY_UNLOCK;    
    SYSC0_1.unRUNCKDIVR.stcField    =   (stc_sysc0_1_runckdivr_field_t){    .u5MCUCHDIV     =  DIV_BY_2,      //  95  | MCUC: -none-
                                                                            .u4MCUCPDIV     =  DIV_BY_1 };    //  95  | MCUC: MCUCHDIV

    SYSC1_PROTKEYR                  =   SYSC_KEY_UNLOCK;    
    SYSC1.unRUNCKDIVR0.stcField     =   (stc_sysc1_runckdivr0_field_t){     .u5TRCDIV       =  DIV_BY_2,      // 200  | Trace: -none-
                                                                            .u5SYSDIV       =  DIV_BY_1,      // 190  | CD0: -none-
                                                                            .u2ATBDIV       =  DIV_BY_2,      //  95  | CD0: SYSDIV
                                                                            .u2DBGDIV       =  DIV_BY_1,      //  95  | CD0: SYSDIV -> ATBDIV
                                                                            .u3HPMDIV       =  DIV_BY_1 };    // 190  | CD0: SYSDIV

    SYSC1_PROTKEYR                  =   SYSC_KEY_UNLOCK;    
    SYSC1.unRUNCKDIVR1.stcField     =   (stc_sysc1_runckdivr1_field_t) {    .u4SYSC1DIV     =  DIV_BY_2,      //  95  | CD0: SYSDIV -> HPMDIV
                                                                            .u4HAPP0A0DIV   =  DIV_BY_2,      //  95  | CD0: SYSDIV -> HPMDIV
                                                                            .u4HAPP0A1DIV   =  DIV_BY_2,      //  47.5| CD0: SYSDIV -> HPMDIV -> HAPP0A0DIV
                                                                            .u4HAPP1B0DIV   =  DIV_BY_2,      //  95  | CD0: SYSDIV -> HPMDIV
                                                                            .u4HAPP1B1DIV   =  DIV_BY_2,      //  47.5| CD0: SYSDIV -> HPMDIV -> HAPP1B0DIV                                                                            
                                                                            .u3EXTBUSDIV    =  DIV_BY_1 };    //  not available

    SYSC1_PROTKEYR                  =   SYSC_KEY_UNLOCK;    
    SYSC1.unRUNCKDIVR2.stcField     =   (stc_sysc1_runckdivr2_field_t){     .u2LCPDIV       =  DIV_BY_2,      //  95  | CD0: SYSDIV
                                                                            .u4LCP0DIV      =  DIV_BY_2,      //  95  | CD0: SYSDIV
                                                                            .u4LCP1DIV      =  DIV_BY_2,      //  95  | CD0: SYSDIV
                                                                            .u4LAPP0DIV     =  DIV_BY_2,      //  95  | CD0: SYSDIV
                                                                            .u4LAPP1DIV     =  DIV_BY_2 };    //  95  | CD0: SYSDIV
                                                                            

    SYSC1_PROTKEYR                  =   SYSC_KEY_UNLOCK;    
    SYSC1.unRUNCKDIVR3.stcField     =   (stc_sysc1_runckdivr3_field_t){     .u5LCP0ADIV     =  DIV_BY_2,      //  95  | CD0: SYSDIV
                                                                            .u5LCP1ADIV     =  DIV_BY_4,      //  47.5| CD0: SYSDIV
                                                                            .u5LAPP0ADIV    =  DIV_BY_2,      //  95  | CD0: SYSDIV
                                                                            .u5LAPP1ADIV    =  DIV_BY_2  };   //  95  | CD0: SYSDIV

    SYSC1_PROTKEYR                  =   SYSC_KEY_UNLOCK;    
    SYSC1.unRUNCKDIVR4.stcField     =   (stc_sysc1_runckdivr4_field_t){     .u5HSSPIDIV     =  DIV_BY_1 };    //  190 | HSSPI: -none-
                                                                            
    SYSC1_PROTKEYR                  =   SYSC_KEY_UNLOCK;    
    SYSC1.unRUNCKDIVR6.stcField     =   (stc_sysc1_runckdivr6_field_t){     .u5CD2DIV       =  DIV_BY_1,      // 380  | CD2: -none-
                                                                            .u4CD2A0DIV     =  DIV_BY_1,      // 380  | CD2: CD2DIV
                                                                            .u4CD2A1DIV     =  DIV_BY_6,      //  60  | CD2: CD2DIV -> CD2A0DIV
                                                                            .u4CD2B0DIV     =  DIV_BY_3,      // 120  | CD2: CD2DIV
                                                                            .u4CD2B1DIV     =  DIV_BY_2, };   //  60  | CD2: CD2DIV -> CD2B0DIV
                                                                            
    SYSC1_PROTKEYR                  =   SYSC_KEY_UNLOCK;    
    SYSC1.unRUNCKDIVR7.stcField     =   (stc_sysc1_runckdivr7_field_t){     .u5CD3DIV       =  DIV_BY_2,      // 200  | CD3: -none-
                                                                            .u4CD3A0DIV     =  DIV_BY_1,      // 180  | CD3: CD3DIV
                                                                            .u4CD3A1DIV     =  DIV_BY_3,      //  60  | CD3: CD3DIV -> CD3A0DIV
                                                                            .u4CD3B0DIV     =  DIV_BY_2,      // 120  | CD3: CD3DIV
                                                                            .u4CD3B1DIV     =  DIV_BY_2, };   //  60  | CD3: CD3DIV -> CD3B0DIV
                                                                            
    SYSC1_PROTKEYR                  =   SYSC_KEY_UNLOCK;    
    SYSC1.unRUNCKDIVR8.stcField     =   (stc_sysc1_runckdivr8_field_t){     .u5CD4DIV       =  DIV_BY_2,      //  98.4| CD4: -none-
                                                                            .u4CD4A0DIV     =  DIV_BY_1,      // 120  | CD4: CD4DIV
                                                                            .u4CD4A1DIV     =  DIV_BY_2,      //  60  | CD4: CD4DIV -> CD4A0DIV
                                                                            .u4CD4B0DIV     =  DIV_BY_1,      // 120  | CD4: CD4DIV
                                                                            .u4CD4B1DIV     =  DIV_BY_2, };   //  60  | CD4: CD4DIV -> CD4B0DIV
                                                                            
    SYSC1_PROTKEYR                  =   SYSC_KEY_UNLOCK;    
    SYSC1.unRUNCKDIVR9.stcField     =   (stc_sysc1_runckdivr9_field_t){     .u5CD5DIV       =  DIV_BY_2,      // 108  | CD5: -none-
                                                                            .u4CD5A0DIV     =  DIV_BY_1,      // 120  | CD5: CD5DIV
                                                                            .u4CD5A1DIV     =  DIV_BY_2,      //  60  | CD5: CD5DIV -> CD5A0DIV
                                                                            .u4CD5B0DIV     =  DIV_BY_1,      // 120  | CD5: CD5DIV
                                                                            .u4CD5B1DIV     =  DIV_BY_2, };   //  60  | CD5: CD5DIV -> CD5B0DIV

 
 
    //------------------------------------------------------------------
    // RUN Profile update enable
    SYSC1_PROTKEYR                  =   SYSC_KEY_UNLOCK;    
    SYSC1_RUNENR_RUNEN1             =   SYSC_TRIGGER_APPLY_RUN_PROFILE;    

    // Write the trigger value to apply the RUN profile
    SYSC0_PROTKEYR                  =   SYSC_KEY_UNLOCK;    
    SYSC0_TRGRUNCNTR                =   SYSC_TRIGGER_APPLY_RUN_PROFILE;    // trigger RUN-->RUN transition
    

    //------------------------------------------------------------------
    // Trigger (SSCG) PLL Clock gearing if it is not already geared up
    if (SYSC_PLL0CGCNTR_PLLCGSTS == 0)  // Gear up status: 0 - stop gear at min freq
    {
        SYSC0_PROTKEYR              =   SYSC_KEY_UNLOCK;    
        SYSC_PLL0CGCNTR_PLLCGSTR    =   1;
    }
    if (SYSC_SSCG0CGCNTR_SSCGCGSTS == 0)  // Gear up status: 0 - stop gear at min freq
    {
        SYSC0_PROTKEYR              =   SYSC_KEY_UNLOCK;    
        SYSC_SSCG0CGCNTR_SSCGCGSTR  =   1;
    }
    
    //------------------------------------------------------------------
    // Wait until the RUN profile is applied
    while (SYSC0_SYSSTSR_RUNSTS0 == 1)
    {
    }
    
    // Clear RUN Profile Done flag (SYSC0_SYSSTSR_RUNDF0)
    SYSC0_PROTKEYR                  =   SYSC_KEY_UNLOCK;    
    SYSC0_SYSICLR_RUNDFCLR0         =   1;
    
    // Ensure that PLL clock gearing has also finished
    while (SYSC_PLL0CGCNTR_PLLCGSTS   != 2)  // Gear up status: 2 - stop gear at max freq
    {
    }    
    
    while (SYSC_SSCG0CGCNTR_SSCGCGSTS != 2)  // Gear up status: 2 - stop gear at max freq
    {
    }
}

/******************************************************************************
 ** \brief Configures internal memories
 **
 ** This function will set TCMRAM, System RAM and Backup RAM
 ** to 0 wait states as all these RAMs support maximum clock without
 ** wait states). Additionally, the appropriate ECC logic will be enabled
 ** disabled according to the settings in start.h.
 **
 ** \note Some registers written here are write-once registers. Ensure to
 **       call this function only one time during system start-up, otherwise
 **       an exception will be generated.
 **
 *****************************************************************************/
static void ConfigureMemories(void)
{
    //------------------------------------------------------------------
    //  TCFLASH
    //------------------------------------------------------------------
    
    // Unlock configuration registers for next write access
    TCFCFG_FCPROTKEY        =   TCFLASH_KEY_UNLOCK;
    // Set 2 wait states (safe configuration for all CPU clocks)
    TCFCFG_FCFGR_FAWC       =   2;

    // Unlock configuration registers for next write access
    TCFCFG_FCPROTKEY        =   TCFLASH_KEY_UNLOCK;
    // Enable/disable ECC logic (write-once register)
    TCFCFG_FECCCTRL_ECCOFF  =   (MCU_TCFLASH_ECC_ENABLE == MCU_ENABLE) ? 0 : 1;

    //------------------------------------------------------------------
    //  WorkFlash
    //------------------------------------------------------------------

    // Unlock configuration registers for next write access
    WFCFG_CPR               =   WFLASH_KEY_UNLOCK;
    // Enable/disable ECC logic (write-once register)
    WFCFG_ECR_ECCOFF        =   (MCU_WORKFLASH_ECC_ENABLE == MCU_ENABLE) ? 0 : 1;

    //------------------------------------------------------------------
    //  TCMRAM
    //------------------------------------------------------------------
    
    // Unlock configuration registers
    TRCFG0_TCMUNLOCK        =   TCMRAM_KEY_UNLOCK;
    TRCFG0_TCMCFG0_DWAIT    =   0;                      // Set 0 wait states
    TRCFG0_TCMUNLOCK        =   TCMRAM_KEY_LOCK;        // Lock configuration registers    

    //------------------------------------------------------------------
    //  System RAM
    //------------------------------------------------------------------

    // Unlock configuration registers
    SRCFG_KEY           =   SYSRAM_KEY_UNLOCK;
    
    // Set 0 wait states for read and write access
    SRCFG_CFG0_RDWAIT   =   0;
    SRCFG_CFG0_WRWAIT   =   0;
    // Enable/disable ECC logic
    SRCFG_ECCE_ECCEN    =   (MCU_SYSRAM_ECC_ENABLE == MCU_ENABLE) ? 1 : 0;

    // Lock configuration registers
    SRCFG_KEY           =   SYSRAM_KEY_LOCK;
    
    //------------------------------------------------------------------
    //  Backup RAM
    //------------------------------------------------------------------

    // Unlock configuration registers
    BURIF_UNLOCK        =   BURAM_KEY_UNLOCK;
    
    // Enable/disable ECC logic
    BURIF_EPDCR_SKPG    =   (MCU_BURAM_ECC_ENABLE == MCU_ENABLE) ? 0 : 1;
    
    // Lock configuration registers
    BURIF_UNLOCK        =   BURAM_KEY_LOCK;

}

/******************************************************************************
 ** \brief Starts DMA operation(s) to clear all RAM areas that have ECC logic enabled
 **
 ** One ore more DMA channels are configured to clear all RAM areas to '0'
 ** to force initial calculation of ECC bits.
 **
 ** \note No interrupts are used
 **
 ** \post One or more DMA channels may be operating. Use ClearEccRamWaitCompletion()
 **       to wait for completion of all DMA operations.
 *****************************************************************************/
static void ClearEccRamStart(void)
{
    un_dma0_an_t    unDmaA0;
    un_dma0_bn_t    unDmaB0;
    un_dma0_cn_t    unDmaC0;
    un_dma0_dn_1_t  unDmaD0_Byte1;
    un_dma0_dn_3_t  unDmaD0_Byte3;
    uint32_t        u32ClearValueFlashAxiAddress ;
    
    // Set source address within public BootROM area (must be 128-byte-aligned and contain 128 '0'-bytes)
    u32ClearValueFlashAxiAddress    =   0xFFFF3F00;

    // Generate common DMA settings
    unDmaA0.stcField        =   (stc_dma0_an_field_t)   {   .u2BL   =   3,                      // Beat limit = INCR16
                                                            .u4BC   =   DMA_BLOCK_SIZE - 1,     // Block count
                                                            .u4TO   =   0xf,                    // Timeout (reserved in this product, keep default)
                                                        };
                                                                
    unDmaB0.stcField        =   (stc_dma0_bn_field_t)   {   .u2MS   =   1,                      // Burst transfer mode
                                                            .u4SP   =   3,                      // Source protection (keep default value) = priv. data access, not cacheable/bufferable
                                                            .u4DP   =   3,                      // Destination protection (keep default value) = priv. data access, not cacheable/bufferable
                                                            .u7PN   =   0x7f,                   // Priority (keep default value) = 127 
                                                        };
    unDmaC0.stcField        =   (stc_dma0_cn_field_t)   {   .u1CD   =   1 };                    // Clear DMA0_DMACB0_DQ flag
    unDmaD0_Byte1.stcField  =   (stc_dma0_dn_1_field_t) {   .u1FD   =   0,                      // Increment destination address                                                                    
                                                        };
    unDmaD0_Byte3.stcField  =   (stc_dma0_dn_3_field_t) {   .u1FS   =   0,                      // increment source address (within one block)
                                                            .u1FBS  =   1,                      // source address for each block is fixed (SA)
                                                        };
    // Globally enable DMA operations
    DMA0.unR.stcField       =   (stc_dma0_r_field_t)    {   .u1DE   =   1,                      // Enable all DMA channels
                                                            .u2PR   =   0,                      // Priority type (keep default value) = fixed
                                                        };

    if (Start_stcClearEccMemories.u32TcmRamSizeByte > 0) 
    {
        // Set memory specific transfer count and width
        unDmaA0.stcField.u16TC  =   ((Start_stcClearEccMemories.u32TcmRamSizeByte - ADDRESS_BOOT_USR_STACK_END) / (DMA_BLOCK_SIZE * (1 << TCMRAM_MAX_ACCESS_WIDTH))) - 1;
        unDmaB0.stcField.u2TW   =   TCMRAM_MAX_ACCESS_WIDTH;
        // Set (fixed) source and destination addresses
        // - source:      "0"-bytes in BootROM address space
        // - destination: TCMRAM (via AXI bus slave interface, no DMA access via TCM port)
        DMA0_SA0                =   u32ClearValueFlashAxiAddress;
        DMA0_DA0                =   Start_stcClearEccMemories.u32TcmRamStartAddress + ADDRESS_BOOT_USR_STACK_END;
        // Configure DMA channel 0
        DMA0_A0                 =   unDmaA0.u32Register;
        DMA0_B0                 =   unDmaB0.u32Register;    
        DMA0_C0                 =   unDmaC0.u32Register;
        DMA0_D0_1               =   unDmaD0_Byte1.u8Register;
        DMA0_D0_3               =   unDmaD0_Byte3.u8Register;
        // Enable DMA channel 0
        DMA0_A0_EB              =   1;
        // Start DMA channel 0 (Software trigger)
        DMA0_A0_ST              =   1;
    }

    if (Start_stcClearEccMemories.u32SysRamSizeByte > 0) 
    {
        // Set memory specific transfer count and width
        unDmaA0.stcField.u16TC  =   (Start_stcClearEccMemories.u32SysRamSizeByte / (DMA_BLOCK_SIZE * (1 << SYSRAM_MAX_ACCESS_WIDTH))) - 1;
        unDmaB0.stcField.u2TW   =   SYSRAM_MAX_ACCESS_WIDTH;
        // Set (fixed) source and destination addresses
        // - source:      "0"-bytes in BootROM address space
        // - destination: System RAM
        DMA0_SA1                =   u32ClearValueFlashAxiAddress;
        DMA0_DA1                =   Start_stcClearEccMemories.u32SysRamStartAddress;
        // Configure DMA channel 1
        DMA0_A1                 =   unDmaA0.u32Register;
        DMA0_B1                 =   unDmaB0.u32Register;    
        DMA0_C1                 =   unDmaC0.u32Register;
        DMA0_D1_1               =   unDmaD0_Byte1.u8Register;
        DMA0_D1_3               =   unDmaD0_Byte3.u8Register;
        // Enable DMA channel 1
        DMA0_A1_EB              =   1;
        // Start DMA channel 1 (Software trigger)
        DMA0_A1_ST              =   1;
    }
    
    if (Start_stcClearEccMemories.u32BuRamSizeByte > 0) 
    {
        // Set memory specific transfer count and width
        unDmaA0.stcField.u16TC  =   (Start_stcClearEccMemories.u32BuRamSizeByte / (DMA_BLOCK_SIZE * (1 << BURAM_MAX_ACCESS_WIDTH))) - 1;
        unDmaB0.stcField.u2TW   =   BURAM_MAX_ACCESS_WIDTH;
        // Set (fixed) source and destination addresses
        // - source:      "0"-bytes in BootROM address space
        // - destination: Backup RAM
        DMA0_SA2                =   u32ClearValueFlashAxiAddress;
        DMA0_DA2                =   Start_stcClearEccMemories.u32BuRamStartAddress;
        // Configure DMA channel 2
        DMA0_A2                 =   unDmaA0.u32Register;
        DMA0_B2                 =   unDmaB0.u32Register;    
        DMA0_C2                 =   unDmaC0.u32Register;
        DMA0_D2_1               =   unDmaD0_Byte1.u8Register;
        DMA0_D2_3               =   unDmaD0_Byte3.u8Register;
        // Enable DMA channel 2
        DMA0_A2_EB              =   1;
        // Start DMA channel 2 (Software trigger)
        DMA0_A2_ST              =   1;
    }
}

/******************************************************************************
 ** \brief Waits until all DMA operations for clearing the ECC RAM areas are completed.
 **
 ** \pre ClearEccRamStart() must be called otherwise this function will never return.
 **
 ** \post All DMA operations are completed, DMA channels 0...3 are disabled,
 **       DMA registers for channel 0...3 may be different from reset state
 *****************************************************************************/
static void ClearEccRamWaitCompletion(void)
{
    if (Start_stcClearEccMemories.u32TcmRamSizeByte > 0) 
    {
        // Check DMA channel 2 completion status
        while (DMA0_B0_DQ == 0)
        {
        }
        // Disable channel 0
        DMA0_A0_EB = 0;
    }

    if (Start_stcClearEccMemories.u32SysRamSizeByte > 0) 
    {
        // Check DMA channel 1 completion status
        while (DMA0_B1_DQ == 0)
        {
        }
        // Disable channel 1
        DMA0_A1_EB = 0;
    }

    if (Start_stcClearEccMemories.u32BuRamSizeByte > 0) 
    {
        // Check DMA channel 2 completion status
        while (DMA0_B2_DQ == 0)
        {
        }
        // Disable channel 2
        DMA0_A2_EB = 0;
    }

    // Globally disable DMA operations
    DMA0_R = 0;
}

/******************************************************************************
 ** \brief Enable Cache ECC
 **
 ** \note
 **
 ** \post
 **
 *****************************************************************************/
static void EnableCacheECC(void)
{
    uint32_t u32CtrlReg ;

    // The I-cache and the D-cache are disabled yet,
    // so disabling the caches and cleaning the D-cache are omitted.
    // Disable the caches and clean entire D-cache if the caches are already enabled.

    // Procedure according to ARM DDI 0460D chapter 8.5.5

    // To avoid ARM CR-5 erratum, Set ACTLR.DBWR((bit [14]) to 1.)
    // This workaround reduces the performance of the processor.
    // For more information, see
    //  Cortex-R5 and Cortex-R5F Software Developers Errata Notice
    //  780125: Processor might deadlock or lose data when configured with cache-ECC

    // Read Auxiliary Control Register
    u32CtrlReg = MRC(15, 0, 1, 0, 1);    // get C1 Auxiliary Control Register  ;
    // Set CEC bit and DBWR bit setting
    u32CtrlReg = (u32CtrlReg & 0xFFFFFFC7) | (CACHE_CEC_SETTING << 3) | (CACHE_DBWR_SETTING << 14);
    // Write Auxiliary Control Register
    MCR(15, 0, u32CtrlReg, 1, 0, 1);    // set C1 Auxiliary Control Register ;
}

/******************************************************************************
 ** \brief Enable L1 Instruction Cache
 **
 ** \note
 **
 ** \post
 **
 *****************************************************************************/
static void EnableInstructionCache(void)
{
    uint32_t u32CtrlReg ;

    // Procedure according to ARM DDI 0460D chapter 8.5.5

    // Read System Control Register configuration data
    u32CtrlReg = MRC(15, 0, 1, 0, 0);       // get CP15 System Control Register ;
    // Set data cache enable bit (I-bit)
    u32CtrlReg |= (1 << 12);                // ORR R1, R1, #0x1  <<12 ;
    // Invalidate entire instruction cache
    MCR( 15, 0, 0, 7, 5, 0 );               // MCR p15, 0, r0, c7, c5, 0 ;
    // Enable entire instruction cache
    MCR(15, 0, u32CtrlReg, 1, 0, 0);        // set CP15 System Control Register ;
    // Flush processor pipeline
    ISB();                                  // ISB ;
} // EnableInstructionCache(void)

/******************************************************************************
 ** \brief Enable L1 Data Cache
 **
 ** \note
 **
 ** \post
 **
 *****************************************************************************/
static void EnableDataCache(void)
{
    uint32_t u32CtrlReg ;

    // Procedure according to ARM DDI 0460D chapter 8.5.5

    // Read System Control Register configuration data
    u32CtrlReg = MRC(15, 0, 1, 0, 0);       // get CP15 System Control Register  ;
    // Set data cache enable bit
    u32CtrlReg |= (1 << 2);                 // ORR R1, R1, #0x1 <<2 ;
    // Ensure completion of memory accesses
    DSB();                                  // DSB ;
    // Invalidate entire data cache
    MCR( 15, 0, 0, 15, 5, 0 );              // MCR p15, 0, r0, c15, c5, 0 ;
    // Enable data cache
    MCR(15, 0, u32CtrlReg, 1, 0, 0);        // set CP15 System Control Register ;
} // EnableDataCache(void)

/******************************************************************************
 ** \brief L1 Data cache and instruction cache configuration
 **
 ** \note
 **
 ** \post
 **
 *****************************************************************************/
static void ConfigureCaches(void)
{
    if (MCU_CACHE_ECC_ENABLE == MCU_ENABLE)
    {
        EnableCacheECC();
    }
    if (MCU_I_CACHE_ENABLE == MCU_ENABLE)
    {
        EnableInstructionCache();
    }
    if (MCU_D_CACHE_ENABLE == MCU_ENABLE)
    {
        EnableDataCache();
    }

} // ConfigureCaches(void)

#endif /* __FILE_VERSION_CHECK__ */
