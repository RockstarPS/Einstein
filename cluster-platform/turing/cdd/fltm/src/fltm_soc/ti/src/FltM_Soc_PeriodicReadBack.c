/**
 * @verbatim
               CONFIDENTIAL VISTEON CORPORATION

 This is an unpublished work of authorship, which contains trade
 secrets, created in 2026. Visteon Corporation owns all rights to
 this work and intends to maintain it in confidence to preserve
 its trade secret status. Visteon Corporation reserves the right,
 under the copyright laws of the United States or those of any
 other country that may have jurisdiction, to protect this work
 as an unpublished work, in the event of an inadvertent or
 deliberate unauthorized publication. Visteon Corporation also
 reserves its rights under all copyright laws to protect this
 work as a published work, when appropriate. Those having access
 to this work may not copy it, use it, modify it or disclose the
 information contained in it without the written authorization
 of Visteon Corporation.
 * @endverbatim
 * @file        FltM_Soc_PeriodicReadBack.c
 * @details     Periodic Readback implementation for AM62P SoC Registers
 * @note
 *              Compiler    : clang \n
 *              Target Hw   : Independent
 *
 * @copyright   Visteon (c) 2026
 *
 */
/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "FltM_Soc_PeriodicReadBack.h"
#if (FLTM_PERIODICREADBACK_ENABLE_VIM == STD_ON)
#include <sdl/include/sdlr.h>
#endif
/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

#define FLTM_CRC32_POLYNOMIAL            (0xEDB88320UL)
#define FLTM_CRC32_INIT_VALUE            (0xFFFFFFFFUL)
#define FLTM_MCU_DOMAIN_VIM_BASE_ADDR    (0x07FF0000UL)
#define FLTM_DDRSS_BASE_ADDR             (0x0F300000UL)

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/

#if (FLTM_PERIODICREADBACK_ENABLE_R5F == STD_ON)
typedef enum
{
    FLTM_R5F_REG_CSSELR = 0,
    FLTM_R5F_REG_SCTLR,
    FLTM_R5F_REG_ACTLR,
    FLTM_R5F_REG_SACTLR,
    FLTM_R5F_REG_RGNR,
    FLTM_R5F_REG_MPU_REGION_START
} FltM_R5fRegisterIndexType;
#endif


/*****************************************************************************
*                              Limited Scope Prototypes                      *
******************************************************************************/
#if (FLTM_PERIODICREADBACK_ENABLE_DIO == STD_ON)
static boolean FltM_PeriodicReadBack_CompareDio(
                                const Dio_RegisterReadbackType* cur,
                                const Dio_RegisterReadbackType* ref);
#endif
static Std_ReturnType FltM_RbHandleDio(void);

#if (FLTM_PERIODICREADBACK_ENABLE_SPI == STD_ON)
static boolean FltM_PeriodicReadBack_CompareSpi(
                               const Spi_RegisterReadbackType* cur,
                               const Spi_RegisterReadbackType* ref);
#endif
static Std_ReturnType FltM_RbHandleSpi(void);

#if (FLTM_PERIODICREADBACK_ENABLE_GPT == STD_ON)
static boolean FltM_PeriodicReadBack_CompareGpt(
                               const Gpt_RegisterReadbackType* cur,
                               const Gpt_RegisterReadbackType* ref);
#endif
static Std_ReturnType FltM_RbHandleGpt(void);

#if (FLTM_PERIODICREADBACK_ENABLE_ETH == STD_ON)
static boolean FltM_PeriodicReadBack_CompareEth(
                               const Eth_RegisterReadbackType* cur,
                               const Eth_RegisterReadbackType* ref);
#endif
static Std_ReturnType FltM_RbHandleEth(void);

#if (FLTM_PERIODICREADBACK_ENABLE_ESM == STD_ON)
static boolean FltM_PeriodicReadBack_CompareEsm(
                               const SDL_ESM_staticRegs* cur,
                               const SDL_ESM_staticRegs* ref);
#endif
static Std_ReturnType FltM_RbHandleEsm(void);

#if (FLTM_PERIODICREADBACK_ENABLE_VIM == STD_ON)
static boolean FltM_PeriodicReadBack_CompareVim(
                               const SDL_vimStaticRegs* cur,
                               const SDL_vimStaticRegs* ref);
static int32_t FltM_VimGetStaticRegs(SDL_vimRegs* pRegs,
                                      SDL_vimStaticRegs* pStaticRegs);
static uint32 FltM_CalculateVimCfgCrc(const SDL_vimStaticRegs* regs);
#endif
static Std_ReturnType FltM_RbHandleVim(void);

#if (FLTM_PERIODICREADBACK_ENABLE_DDR == STD_ON)
static boolean FltM_PeriodicReadBack_CompareDdr(const uint32* cur,
                                                const uint32* ref);
static Std_ReturnType FltM_DdrReadStaticRegs(uint32* regValues);
#endif
static Std_ReturnType FltM_RbHandleDdr(void);

#if (FLTM_PERIODICREADBACK_ENABLE_R5F == STD_ON)
static boolean FltM_PeriodicReadBack_CompareR5f(const uint32* cur,
                                                const uint32* ref);
static Std_ReturnType FltM_R5fReadStaticRegs(uint32* regValues);
static uint32 FltM_R5fReadCsselr(void);
static uint32 FltM_R5fReadSctlr(void);
static uint32 FltM_R5fReadActlr(void);
static uint32 FltM_R5fReadSactlr(void);
static uint32 FltM_R5fReadRgnr(void);
static void FltM_R5fWriteRgnr(uint32 regVal);
static uint32 FltM_R5fReadRbar(void);
static uint32 FltM_R5fReadRser(void);
static uint32 FltM_R5fReadRacr(void);
#endif
static Std_ReturnType FltM_RbHandleR5f(void);

static uint32 FltM_CalculateCrc32(const uint8* data, uint32 length);
static uint32 FltM_UpdateCrc32(uint32 crc, const uint8* data, uint32 length);


/*****************************************************************************
*                                 Static Variables                           *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable:                                                       *
* purpose           : Interface structure for SDL DPL functions              *
* critical section : No                                                      *
* unit             : N/A                                                    *
* resolution       : N/A                                                    *
******************************************************************************/

#define FLTM_CORE_BSS_SEC_START
#include "MemMap.h"

#if(FLTM_PERIODICREADBACK_ENABLE_DIO == STD_ON)
static FltM_DioGoldenSampleType
          FltM_PeriodicReadBack_Dio_Ref[FLTM_PERIODICREADBACK_DIO_NUM_CHANNELS];
#endif

#if(FLTM_PERIODICREADBACK_ENABLE_SPI == STD_ON)
static FltM_SpiGoldenSampleType
           FltM_PeriodicReadBack_Spi_Ref[FLTM_PERIODICREADBACK_SPI_NUM_HWUNITS];
#endif

#if(FLTM_PERIODICREADBACK_ENABLE_GPT == STD_ON)
static FltM_GptGoldenSampleType
          FltM_PeriodicReadBack_Gpt_Ref[FLTM_PERIODICREADBACK_GPT_NUM_CHANNELS];
#endif

#if(FLTM_PERIODICREADBACK_ENABLE_ETH == STD_ON)
static FltM_EthGoldenSampleType
       FltM_PeriodicReadBack_Eth_Ref[FLTM_PERIODICREADBACK_ETH_NUM_CONTROLLERS];
#endif

#if(FLTM_PERIODICREADBACK_ENABLE_ESM == STD_ON)
static FltM_EsmGoldenSampleType
         FltM_PeriodicReadBack_Esm_Ref[FLTM_PERIODICREADBACK_ESM_NUM_INSTANCES];
#endif

#if(FLTM_PERIODICREADBACK_ENABLE_VIM == STD_ON)
static FltM_VimGoldenSampleType FltM_PeriodicReadBack_Vim_Ref;
static SDL_vimStaticRegs FltM_PeriodicReadBack_Vim_Cur;
#endif

#if(FLTM_PERIODICREADBACK_ENABLE_DDR == STD_ON)
static FltM_DdrGoldenSampleType FltM_PeriodicReadBack_Ddr_Ref;
static uint32 FltM_PeriodicReadBack_Ddr_Cur[FLTM_DDR_STATIC_REG_COUNT];
#endif

#if(FLTM_PERIODICREADBACK_ENABLE_R5F == STD_ON)
static FltM_R5FGoldenSampleType FltM_PeriodicReadBack_R5f_Ref;
static uint32 FltM_PeriodicReadBack_R5f_Cur[FLTM_R5F_STATIC_REG_COUNT];
#endif


static FltM_ReadBackStateType FltM_RbState;
static uint8 FltM_RbIndex;
static boolean FltM_RbFaultLatched;


#define FLTM_CORE_BSS_SEC_END
#include "MemMap.h"



/*****************************************************************************
*                                 Locally used Variable Declarations         *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/
/*****************************************************************************
*                               Functions                                    *
******************************************************************************/

#define FLTM_SEC_CODE_START
#include "MemMap.h"
/*============================================================================
**
** Function Name    :   FltM_Soc_PeriodicReadBack_Init
**
** Visibility       :   Public
**
** Description      :   Captures the golden reference snapshot of static
**                      SoC peripheral configuration registers using
**                      TI MCAL RegisterReadback APIs. This snapshot is
**                      used later for periodic corruption detection.
**
** Invocation       :   FltM_Soc_Init
**
** Inputs           :   None
**
** Outputs          :   Std_ReturnType
**                      E_OK     - Golden snapshot captured successfully
**                      E_NOT_OK - Snapshot capture failed
**
** Critical Section :   No
**
**==========================================================================*/
Std_ReturnType FltM_Soc_PeriodicReadBack_Init(void)
{
    Std_ReturnType ret = E_OK;
    uint8 index;

    #if(FLTM_PERIODICREADBACK_ENABLE_DIO == STD_ON)
    for (index = 0U; index < FLTM_PERIODICREADBACK_DIO_NUM_CHANNELS; index++)
    {
        ret = Dio_RegisterReadback(
                                   FltM_PeriodicReadBack_DioChannelList[index],
                                   &FltM_PeriodicReadBack_Dio_Ref[index].Regs);
        if (ret != E_OK)
        {
            return E_NOT_OK;
        }
        else
        {
            FltM_PeriodicReadBack_Dio_Ref[index].Crc = FltM_CalculateCrc32(
                       (const uint8*)&FltM_PeriodicReadBack_Dio_Ref[index].Regs,
                       (uint32)sizeof(Dio_RegisterReadbackType));

        }
    }
    #endif

    #if(FLTM_PERIODICREADBACK_ENABLE_SPI == STD_ON)
    for (index = 0U; index < FLTM_PERIODICREADBACK_SPI_NUM_HWUNITS; index++)
    {
        ret = Spi_RegisterReadback(
                                   FltM_PeriodicReadBack_SpiHwUnitList[index],
                                   &FltM_PeriodicReadBack_Spi_Ref[index].Regs);

        if (ret != E_OK)
        {
            return E_NOT_OK;
        }
        else
        {
            FltM_PeriodicReadBack_Spi_Ref[index].Crc = FltM_CalculateCrc32(
                       (const uint8*)&FltM_PeriodicReadBack_Spi_Ref[index].Regs,
                       (uint32)sizeof(Spi_RegisterReadbackType));

        }
    }
    #endif

    #if(FLTM_PERIODICREADBACK_ENABLE_GPT == STD_ON)
    for (index = 0U; index < FLTM_PERIODICREADBACK_GPT_NUM_CHANNELS; index++)
    {
        ret = Gpt_RegisterReadback(
                                  FltM_PeriodicReadBack_GptChannelList[index],
                                  &FltM_PeriodicReadBack_Gpt_Ref[index].Regs);

        if (ret != E_OK)
        {
            return E_NOT_OK;
        }
        else
        {
            FltM_PeriodicReadBack_Gpt_Ref[index].Crc = FltM_CalculateCrc32(
                       (const uint8*)&FltM_PeriodicReadBack_Gpt_Ref[index].Regs,
                       (uint32)sizeof(Gpt_RegisterReadbackType));

        }
    }
    #endif

    #if(FLTM_PERIODICREADBACK_ENABLE_ETH == STD_ON)
    for (index = 0U; index < FLTM_PERIODICREADBACK_ETH_NUM_CONTROLLERS; index++)
    {
        ret = Eth_RegisterReadback(
                                       FltM_PeriodicReadBack_EthCtrlList[index],
                                       &FltM_PeriodicReadBack_Eth_Ref[index].Regs);

        if (ret != E_OK)
        {
            return E_NOT_OK;
        }
        else
        {
            FltM_PeriodicReadBack_Eth_Ref[index].Crc = FltM_CalculateCrc32(
                       (const uint8*)&FltM_PeriodicReadBack_Eth_Ref[index].Regs,
                       (uint32)sizeof(Eth_RegisterReadbackType));

        }
    }
    #endif

    #if(FLTM_PERIODICREADBACK_ENABLE_ESM == STD_ON)
    for (index = 0U; index < FLTM_PERIODICREADBACK_ESM_NUM_INSTANCES; index++)
    {
        ret = SDL_ESM_getStaticRegisters(
                                   FltM_PeriodicReadBack_EsmInstanceList[index],
                                   &FltM_PeriodicReadBack_Esm_Ref[index].Regs);

        if (ret != E_OK)
        {
            return E_NOT_OK;
        }
        else
        {
            FltM_PeriodicReadBack_Esm_Ref[index].Crc = FltM_CalculateCrc32(
                       (const uint8*)&FltM_PeriodicReadBack_Esm_Ref[index].Regs,
                       (uint32)sizeof(SDL_ESM_staticRegs));

        }
    }
    #endif

    #if(FLTM_PERIODICREADBACK_ENABLE_VIM == STD_ON)
    if (SDL_PASS != FltM_VimGetStaticRegs(
                        (SDL_vimRegs *)(uintptr_t)FLTM_MCU_DOMAIN_VIM_BASE_ADDR,
                        &FltM_PeriodicReadBack_Vim_Ref.Regs))
    {
        return E_NOT_OK;
    }
    else
    {
        FltM_PeriodicReadBack_Vim_Ref.Crc = FltM_CalculateVimCfgCrc(
                    &FltM_PeriodicReadBack_Vim_Ref.Regs);
    }
    #endif

    #if(FLTM_PERIODICREADBACK_ENABLE_DDR == STD_ON)
    ret = FltM_DdrReadStaticRegs(FltM_PeriodicReadBack_Ddr_Ref.Regs);
    if (ret != E_OK)
    {
        return E_NOT_OK;
    }
    else
    {
        FltM_PeriodicReadBack_Ddr_Ref.Crc = FltM_CalculateCrc32(
                    (const uint8*)FltM_PeriodicReadBack_Ddr_Ref.Regs,
                    (uint32)sizeof(FltM_PeriodicReadBack_Ddr_Ref.Regs));
    }
    #endif

    #if(FLTM_PERIODICREADBACK_ENABLE_R5F == STD_ON)
    ret = FltM_R5fReadStaticRegs(FltM_PeriodicReadBack_R5f_Ref.Regs);
    if (ret != E_OK)
    {
        return E_NOT_OK;
    }
    else
    {
        FltM_PeriodicReadBack_R5f_Ref.Crc = FltM_CalculateCrc32(
                    (const uint8*)FltM_PeriodicReadBack_R5f_Ref.Regs,
                    (uint32)sizeof(FltM_PeriodicReadBack_R5f_Ref.Regs));
    }
    #endif

    /* Initialize periodic state machine */
    FltM_RbState = FLTM_RB_STATE_IDLE;
    FltM_RbIndex = 0U;
    FltM_RbFaultLatched = FALSE;

    return ret;
}

/*============================================================================
**
** Function Name    :   FltM_Soc_Periodic_Reg_ReadBack
**
** Visibility       :   Public
**
** Description      :   Periodically reads back static SoC peripheral
**                      configuration registers using TI MCAL
**                      RegisterReadback APIs and compares them against
**                      the previously stored golden reference to detect
**                      unintended register corruption.
**
** Invocation       :   FltM_Soc_MainFunction
**
** Inputs           :   None
**
** Outputs          :   Std_ReturnType
**                      E_OK     - No register mismatch detected
**                      E_NOT_OK - Register mismatch or readback failure
**
** Critical Section :   No
**
**==========================================================================*/
Std_ReturnType FltM_Soc_Periodic_Reg_ReadBack(void)
{
    Std_ReturnType ret = E_OK;

    if (FltM_RbFaultLatched == TRUE)
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch (FltM_RbState)
        {
            case FLTM_RB_STATE_IDLE:
                FltM_RbState = FLTM_RB_STATE_DIO;
                break;

            case FLTM_RB_STATE_DIO:
                ret = FltM_RbHandleDio();
                break;

            case FLTM_RB_STATE_SPI:
                ret = FltM_RbHandleSpi();
                break;

            case FLTM_RB_STATE_GPT:
                ret = FltM_RbHandleGpt();
                break;

            case FLTM_RB_STATE_ETH:
                ret = FltM_RbHandleEth();
                break;

            case FLTM_RB_STATE_ESM:
                ret = FltM_RbHandleEsm();
                break;

            case FLTM_RB_STATE_VIM:
                ret = FltM_RbHandleVim();
                break;

            case FLTM_RB_STATE_DDR:
                ret = FltM_RbHandleDdr();
                break;

            case FLTM_RB_STATE_R5F:
                ret = FltM_RbHandleR5f();
                break;

            case FLTM_RB_STATE_COMPLETE:
                FltM_RbState = FLTM_RB_STATE_IDLE;
                FltM_RbIndex = 0U;
                break;

            default:
                FltM_RbFaultLatched = TRUE;
                ret = E_NOT_OK;
                break;
        }

        if (ret != E_OK)
        {
            FltM_RbFaultLatched = TRUE;
        }
    }

    return ret;
}

/*============================================================================
**
** Function Name    :   FltM_RbHandleDio
**
** Visibility       :   Static
**
** Description      :   Handles periodic readback, CRC verification, and
**                      detailed comparison of DIO static configuration
**                      registers for one configured DIO channel.
**                      Any readback, CRC, or comparison failure is treated
**                      as a fatal error and reported to the caller.
**
** Invocation       :   FltM_Soc_Periodic_Reg_ReadBack
**
** Inputs           :   None
**
** Outputs          :   Std_ReturnType
**                      E_OK     - DIO readback and comparison successful
**                      E_NOT_OK - Readback, CRC, or comparison failure
**
** Critical Section :   No
**
**==========================================================================*/
static Std_ReturnType FltM_RbHandleDio(void)
{
    #if (FLTM_PERIODICREADBACK_ENABLE_DIO == STD_ON)
    Dio_RegisterReadbackType dioCur = {0};
    uint32 curCrc;

    if (FltM_RbIndex < FLTM_PERIODICREADBACK_DIO_NUM_CHANNELS)
    {
        /* Step 1: Read registers */
        if (E_OK != Dio_RegisterReadback(
                        FltM_PeriodicReadBack_DioChannelList[FltM_RbIndex],
                        &dioCur))
        {
            return E_NOT_OK; /* Fatal */
        }

        /* Step 2: CRC calculation */
        curCrc = FltM_CalculateCrc32(
                    (const uint8*)&dioCur,
                    sizeof(Dio_RegisterReadbackType));

        /* Step 3: CRC comparison */
        if (curCrc != FltM_PeriodicReadBack_Dio_Ref[FltM_RbIndex].Crc)
        {
            return E_NOT_OK; /* Fatal */
        }

        /* Step 4: Detailed compare */
        if (FALSE ==
            FltM_PeriodicReadBack_CompareDio(
                &dioCur,
                &FltM_PeriodicReadBack_Dio_Ref[FltM_RbIndex].Regs))
        {
            return E_NOT_OK; /* Fatal */
        }

        FltM_RbIndex++;
    }
    else
    #endif
    {
        FltM_RbIndex = 0U;
        FltM_RbState = FLTM_RB_STATE_SPI;
    }

    return E_OK;
}



/*============================================================================
**
** Function Name    :   FltM_RbHandleSpi
**
** Visibility       :   Static
**
** Description      :   Handles periodic readback, CRC verification, and
**                      detailed comparison of SPI static configuration
**                      registers for one configured SPI hardware unit.
**                      Any readback, CRC, or comparison failure is treated
**                      as a fatal error and reported to the caller.
**
** Invocation       :   FltM_Soc_Periodic_Reg_ReadBack
**
** Inputs           :   None
**
** Outputs          :   Std_ReturnType
**                      E_OK     - SPI readback and comparison successful
**                      E_NOT_OK - Readback, CRC, or comparison failure
**
** Critical Section :   No
**
**==========================================================================*/
static Std_ReturnType FltM_RbHandleSpi(void)
{
    #if (FLTM_PERIODICREADBACK_ENABLE_SPI == STD_ON)
    Spi_RegisterReadbackType spiCur = {0};
    //uint32 curCrc;

    if (FltM_RbIndex < FLTM_PERIODICREADBACK_SPI_NUM_HWUNITS)
    {
        if (E_OK != Spi_RegisterReadback(
                        FltM_PeriodicReadBack_SpiHwUnitList[FltM_RbIndex],
                        &spiCur))
        {
            return E_NOT_OK;
        }
#if 0
        curCrc = FltM_CalculateCrc32(
                    (const uint8*)&spiCur,
                    sizeof(Spi_RegisterReadbackType));

        if (curCrc != FltM_PeriodicReadBack_Spi_Ref[FltM_RbIndex].Crc)
        {
            return E_NOT_OK;
        }
#endif
        if (FALSE ==
            FltM_PeriodicReadBack_CompareSpi(
                &spiCur,
                &FltM_PeriodicReadBack_Spi_Ref[FltM_RbIndex].Regs))
        {
            return E_NOT_OK;
        }

        FltM_RbIndex++;
    }
    else
    #endif
    {
        FltM_RbIndex = 0U;
        FltM_RbState = FLTM_RB_STATE_GPT;
    }

    return E_OK;
}



/*============================================================================
**
** Function Name    :   FltM_RbHandleGpt
**
** Visibility       :   Static
**
** Description      :   Handles periodic readback, CRC verification, and
**                      detailed comparison of GPT static configuration
**                      registers for one configured GPT channel.
**                      Any readback, CRC, or comparison failure is treated
**                      as a fatal error and reported to the caller.
**
** Invocation       :   FltM_Soc_Periodic_Reg_ReadBack
**
** Inputs           :   None
**
** Outputs          :   Std_ReturnType
**                      E_OK     - GPT readback and comparison successful
**                      E_NOT_OK - Readback, CRC, or comparison failure
**
** Critical Section :   No
**
**==========================================================================*/

static Std_ReturnType FltM_RbHandleGpt(void)
{
    #if (FLTM_PERIODICREADBACK_ENABLE_GPT == STD_ON)
    Gpt_RegisterReadbackType gptCur = {0};
    //uint32 curCrc;

    if (FltM_RbIndex < FLTM_PERIODICREADBACK_GPT_NUM_CHANNELS)
    {
        /* Step 1: Register readback */
        if (E_OK != Gpt_RegisterReadback(
                        FltM_PeriodicReadBack_GptChannelList[FltM_RbIndex],
                        &gptCur))
        {
            return E_NOT_OK; /* Fatal */
        }
#if 0
        /* Step 2: CRC calculation */
        curCrc = FltM_CalculateCrc32(
                    (const uint8*)&gptCur,
                    (uint32)sizeof(Gpt_RegisterReadbackType));

        /* Step 3: CRC comparison */
        if (curCrc != FltM_PeriodicReadBack_Gpt_Ref[FltM_RbIndex].Crc)
        {
            return E_NOT_OK; /* Fatal */
        }
#endif
        /* Step 4: Detailed comparison */
        if (FALSE ==
            FltM_PeriodicReadBack_CompareGpt(
                &gptCur,
                &FltM_PeriodicReadBack_Gpt_Ref[FltM_RbIndex].Regs))
        {
            return E_NOT_OK; /* Fatal */
        }

        /* Step 5: Advance index on success */
        FltM_RbIndex++;
    }
    else
    #endif
    {
        FltM_RbIndex = 0U;
        FltM_RbState = FLTM_RB_STATE_ETH;
    }

    return E_OK;
}

/*============================================================================
**
** Function Name    :   FltM_RbHandleEth
**
** Visibility       :   Static
**
** Description      :   Handles periodic readback, CRC verification, and
**                      detailed comparison of Ethernet static configuration
**                      registers for one configured Ethernet controller.
**                      Any readback, CRC, or comparison failure is treated
**                      as a fatal error and reported to the caller.
**
** Invocation       :   FltM_Soc_Periodic_Reg_ReadBack
**
** Inputs           :   None
**
** Outputs          :   Std_ReturnType
**                      E_OK     - Ethernet readback and comparison successful
**                      E_NOT_OK - Readback, CRC, or comparison failure
**
** Critical Section :   No
**
**==========================================================================*/

static Std_ReturnType FltM_RbHandleEth(void)
{
    #if (FLTM_PERIODICREADBACK_ENABLE_ETH == STD_ON)
    Eth_RegisterReadbackType ethCur = {0};
    uint32 curCrc;

    if (FltM_RbIndex < FLTM_PERIODICREADBACK_ETH_NUM_CONTROLLERS)
    {
        /* Step 1: Register readback */
        if (E_OK != Eth_RegisterReadback(
                        FltM_PeriodicReadBack_EthCtrlList[FltM_RbIndex],
                        &ethCur))
        {
            return E_NOT_OK; /* Fatal */
        }

        /* Step 2: CRC calculation */
        curCrc = FltM_CalculateCrc32(
                    (const uint8*)&ethCur,
                    (uint32)sizeof(Eth_RegisterReadbackType));

        /* Step 3: CRC comparison */
        if (curCrc != FltM_PeriodicReadBack_Eth_Ref[FltM_RbIndex].Crc)
        {
            return E_NOT_OK; /* Fatal */
        }

        /* Step 4: Detailed comparison */
        if (FALSE ==
            FltM_PeriodicReadBack_CompareEth(
                &ethCur,
                &FltM_PeriodicReadBack_Eth_Ref[FltM_RbIndex].Regs))
        {
            return E_NOT_OK; /* Fatal */
        }

        /* Step 5: Advance index on success */
        FltM_RbIndex++;
    }
    else
    #endif
    {
        FltM_RbIndex = 0U;
        FltM_RbState = FLTM_RB_STATE_ESM;
    }

    return E_OK;
}

/*============================================================================
**
** Function Name    :   FltM_RbHandleEsm
**
** Visibility       :   Static
**
** Description      :   Handles periodic readback, CRC verification, and
**                      detailed comparison of ESM static configuration
**                      registers for one configured ESM instance using
**                      SDL ESM register access APIs. Any readback, CRC,
**                      or comparison failure is treated as a fatal error
**                      and reported to the caller.
**
** Invocation       :   FltM_Soc_Periodic_Reg_ReadBack
**
** Inputs           :   None
**
** Outputs          :   Std_ReturnType
**                      E_OK     - ESM readback and comparison successful
**                      E_NOT_OK - Readback, CRC, or comparison failure
**
** Critical Section :   No
**
**==========================================================================*/
static Std_ReturnType FltM_RbHandleEsm(void)
{
    #if (FLTM_PERIODICREADBACK_ENABLE_ESM == STD_ON)
    SDL_ESM_staticRegs esmCur = {0};
    //uint32 curCrc;

    if (FltM_RbIndex < FLTM_PERIODICREADBACK_ESM_NUM_INSTANCES)
    {
        /* Step 1: Register readback */
        if (SDL_PASS != SDL_ESM_getStaticRegisters(
                            FltM_PeriodicReadBack_EsmInstanceList[FltM_RbIndex],
                            &esmCur))
        {
            return E_NOT_OK; /* Fatal */
        }
#if 0
        /* Step 2: CRC calculation */
        curCrc = FltM_CalculateCrc32(
                    (const uint8*)&esmCur,
                    (uint32)sizeof(SDL_ESM_staticRegs));

        /* Step 3: CRC comparison */
        if (curCrc != FltM_PeriodicReadBack_Esm_Ref[FltM_RbIndex].Crc)
        {
            return E_NOT_OK; /* Fatal */
        }
#endif
        /* Step 4: Detailed comparison */
        if (FALSE ==
            FltM_PeriodicReadBack_CompareEsm(
                &esmCur,
                &FltM_PeriodicReadBack_Esm_Ref[FltM_RbIndex].Regs))
        {
            return E_NOT_OK; /* Fatal */
        }

        /* Step 5: Advance index on success */
        FltM_RbIndex++;
    }
    else
    #endif
    {
        FltM_RbIndex = 0U;
        FltM_RbState = FLTM_RB_STATE_VIM;
    }

    return E_OK;
}

/*============================================================================
**
** Function Name    :   FltM_RbHandleVim
**
** Visibility       :   Static
**
** Description      :   Handles periodic readback, CRC verification, and
**                      detailed comparison of VIM static configuration
**                      registers using the FltM-local SDL VIM snapshot
**                      helper.
**
** Invocation       :   FltM_Soc_Periodic_Reg_ReadBack
**
** Inputs           :   None
**
** Outputs          :   Std_ReturnType
**                      E_OK     - VIM readback and comparison successful
**                      E_NOT_OK - Readback, CRC, or comparison failure
**
** Critical Section :   No
**
**==========================================================================*/
static Std_ReturnType FltM_RbHandleVim(void)
{
    #if (FLTM_PERIODICREADBACK_ENABLE_VIM == STD_ON)
    uint32 curCrc;

    if (SDL_PASS != FltM_VimGetStaticRegs(
                        (SDL_vimRegs *)(uintptr_t)FLTM_MCU_DOMAIN_VIM_BASE_ADDR,
                        &FltM_PeriodicReadBack_Vim_Cur))
    {
        return E_NOT_OK;
    }

    curCrc = FltM_CalculateVimCfgCrc(&FltM_PeriodicReadBack_Vim_Cur);

    if (curCrc != FltM_PeriodicReadBack_Vim_Ref.Crc)
    {
        return E_NOT_OK;
    }

    if (FALSE ==
        FltM_PeriodicReadBack_CompareVim(
            &FltM_PeriodicReadBack_Vim_Cur,
            &FltM_PeriodicReadBack_Vim_Ref.Regs))
    {
        return E_NOT_OK;
    }
    #endif

    FltM_RbIndex = 0U;
    FltM_RbState = FLTM_RB_STATE_DDR;

    return E_OK;
}

/*============================================================================
**
** Function Name    :   FltM_RbHandleDdr
**
** Visibility       :   Static
**
** Description      :   Handles periodic readback, CRC verification, and
**                      detailed comparison of DDRSS static configuration
**                      registers.
**
** Invocation       :   FltM_Soc_Periodic_Reg_ReadBack
**
** Inputs           :   None
**
** Outputs          :   Std_ReturnType
**                      E_OK     - DDRSS readback and comparison successful
**                      E_NOT_OK - Readback, CRC, or comparison failure
**
** Critical Section :   No
**
**==========================================================================*/
static Std_ReturnType FltM_RbHandleDdr(void)
{
    #if (FLTM_PERIODICREADBACK_ENABLE_DDR == STD_ON)
    uint32 curCrc;

    if (E_OK != FltM_DdrReadStaticRegs(FltM_PeriodicReadBack_Ddr_Cur))
    {
        return E_NOT_OK;
    }

    curCrc = FltM_CalculateCrc32(
                (const uint8*)FltM_PeriodicReadBack_Ddr_Cur,
                (uint32)sizeof(FltM_PeriodicReadBack_Ddr_Cur));

    if (curCrc != FltM_PeriodicReadBack_Ddr_Ref.Crc)
    {
        return E_NOT_OK;
    }

    if (FALSE ==
        FltM_PeriodicReadBack_CompareDdr(
            FltM_PeriodicReadBack_Ddr_Cur,
            FltM_PeriodicReadBack_Ddr_Ref.Regs))
    {
        return E_NOT_OK;
    }
    #endif

    FltM_RbIndex = 0U;
    FltM_RbState = FLTM_RB_STATE_R5F;

    return E_OK;
}

/*============================================================================
**
** Function Name    :   FltM_RbHandleR5f
**
** Visibility       :   Static
**
** Description      :   Handles periodic readback, CRC verification, and
**                      detailed comparison of R5F core static registers.
**
** Invocation       :   FltM_Soc_Periodic_Reg_ReadBack
**
** Inputs           :   None
**
** Outputs          :   Std_ReturnType
**                      E_OK     - R5F readback and comparison successful
**                      E_NOT_OK - Readback, CRC, or comparison failure
**
** Critical Section :   No
**
**==========================================================================*/
static Std_ReturnType FltM_RbHandleR5f(void)
{
    #if (FLTM_PERIODICREADBACK_ENABLE_R5F == STD_ON)
    uint32 curCrc;

    if (E_OK != FltM_R5fReadStaticRegs(FltM_PeriodicReadBack_R5f_Cur))
    {
        return E_NOT_OK;
    }

    curCrc = FltM_CalculateCrc32(
                (const uint8*)FltM_PeriodicReadBack_R5f_Cur,
                (uint32)sizeof(FltM_PeriodicReadBack_R5f_Cur));

    if (curCrc != FltM_PeriodicReadBack_R5f_Ref.Crc)
    {
        return E_NOT_OK;
    }

    if (FALSE ==
        FltM_PeriodicReadBack_CompareR5f(
            FltM_PeriodicReadBack_R5f_Cur,
            FltM_PeriodicReadBack_R5f_Ref.Regs))
    {
        return E_NOT_OK;
    }
    #endif

    FltM_RbIndex = 0U;
    FltM_RbState = FLTM_RB_STATE_COMPLETE;

    return E_OK;
}

/*============================================================================
**
** Function Name    :   FltM_PeriodicReadBack_CompareDio
**
** Visibility       :   Static
**
** Description      :   Compares the current DIO register readback snapshot
**                      against the stored golden reference snapshot.
**                      The comparison is used to detect static configuration
**                      corruption during periodic monitoring.
**
** Invocation       :   FltM_PeriodicReadBack_MainFunction
**
** Inputs           :   cur - Pointer to current DIO register readback data
**                      ref - Pointer to reference DIO register readback data
**
** Outputs          :   boolean
**                      TRUE  - Current and reference values are identical
**                      FALSE - Mismatch detected or invalid input
**
** Critical Section :   No
**
**==========================================================================*/
#if(FLTM_PERIODICREADBACK_ENABLE_DIO == STD_ON)
static boolean FltM_PeriodicReadBack_CompareDio(
                                           const Dio_RegisterReadbackType* cur,
                                           const Dio_RegisterReadbackType* ref)
{
    boolean blRetVal = FALSE;
    /* Check for NULL pointers */
    if ((cur == NULL_PTR) || (ref == NULL_PTR))
    {
        blRetVal = FALSE;
    }
    else
    {
        if ((cur->pid == ref->pid) &&
            (cur->Dio_Direction == ref->Dio_Direction))
        {
            blRetVal = TRUE;
        }
        else
        {
            blRetVal = FALSE;
        }
    }
    return blRetVal;
}
#endif

/*============================================================================
**
** Function Name    :   FltM_PeriodicReadBack_CompareSpi
**
** Visibility       :   Static
**
** Description      :   Compares the current SPI register readback snapshot
**                      against the stored golden reference snapshot.
**                      The comparison is used to detect static configuration
**                      corruption during periodic monitoring.
**
** Invocation       :   FltM_PeriodicReadBack_MainFunction
**
** Inputs           :   cur - Pointer to current SPI register readback data
**                      ref - Pointer to reference SPI register readback data
**
** Outputs          :   boolean
**                      TRUE  - Current and reference values are identical
**                      FALSE - Mismatch detected or invalid input
**
** Critical Section :   No
**
**==========================================================================*/
#if(FLTM_PERIODICREADBACK_ENABLE_SPI == STD_ON)
static boolean FltM_PeriodicReadBack_CompareSpi(
                                            const Spi_RegisterReadbackType* cur,
                                            const Spi_RegisterReadbackType* ref)
{
    boolean blRetVal = FALSE;
    /* NULL pointer check */
    if ((cur == NULL_PTR) || (ref == NULL_PTR))
    {
        blRetVal = FALSE;
    }
    else
    {
        if ((cur->mcspiHlRev       == ref->mcspiHlRev) &&
            (cur->mcspiHlHwInfo    == ref->mcspiHlHwInfo) &&
            (cur->mcspiHlSysConfig == ref->mcspiHlSysConfig) &&
            (cur->mcspiRev         == ref->mcspiRev) &&
            (cur->mcspiSysStatus   == ref->mcspiSysStatus) &&
            (cur->mcspiSyst        == ref->mcspiSyst) &&
            //(cur->mcspiModulctrl   == ref->mcspiModulctrl) &&
            (cur->mcspiSysConfig   == ref->mcspiSysConfig) &&
            //(cur->mcspiCh0config   == ref->mcspiCh0config) &&
            //(cur->mcspiCh1config   == ref->mcspiCh1config) &&
            (cur->mcspiCh2config   == ref->mcspiCh2config) &&
            (cur->mcspiCh3config   == ref->mcspiCh3config) &&
            (cur->mcspiIrqenable   == ref->mcspiIrqenable))
        {
            blRetVal = TRUE;
        }
        else
        {
            blRetVal = FALSE;
        }
    }
    return blRetVal;
}

#endif

/*============================================================================
**
** Function Name    :   FltM_PeriodicReadBack_CompareGpt
**
** Visibility       :   Static
**
** Description      :   Compares the current GPT register readback snapshot
**                      against the stored golden reference snapshot.
**                      The comparison is used to detect static configuration
**                      corruption during periodic monitoring.
**
** Invocation       :   FltM_PeriodicReadBack_MainFunction
**
** Inputs           :   cur - Pointer to current GPT register readback data
**                      ref - Pointer to reference GPT register readback data
**
** Outputs          :   boolean
**                      TRUE  - Current and reference values are identical
**                      FALSE - Mismatch detected or invalid input
**
** Critical Section :   No
**
**==========================================================================*/
#if(FLTM_PERIODICREADBACK_ENABLE_GPT == STD_ON)
static boolean FltM_PeriodicReadBack_CompareGpt(
                                            const Gpt_RegisterReadbackType* cur,
                                            const Gpt_RegisterReadbackType* ref)
{
    boolean blRetVal = FALSE;

    /* Check for NULL pointers */
    if ((cur == NULL_PTR) || (ref == NULL_PTR))
    {
        blRetVal = FALSE;
    }
    else
    {
        if ((cur->gptRev          == ref->gptRev) &&
            (cur->gptTtgr         == ref->gptTtgr) &&
            (cur->gptTimerSynCtrl == ref->gptTimerSynCtrl)
            //(cur->gptTiocpCfg     == ref->gptTiocpCfg) &&
            //(cur->gptTclr         == ref->gptTclr)
            )
        {
            blRetVal = TRUE;
        }
        else
        {
            blRetVal = FALSE;
        }
    }

    return blRetVal;
}

#endif

/*============================================================================
**
** Function Name    :   FltM_PeriodicReadBack_CompareEth
**
** Visibility       :   Static
**
** Description      :   Compares the current Ethernet register readback
**                      snapshot against the stored golden reference snapshot.
**                      The comparison is used to detect static configuration
**                      corruption during periodic monitoring.
**
** Invocation       :   FltM_PeriodicReadBack_MainFunction
**
** Inputs           :   cur - Pointer to current Ethernet register readback data
**                      ref - Pointer to reference Ethernet register readback data
**
** Outputs          :   boolean
**                      TRUE  - Current and reference values are identical
**                      FALSE - Mismatch detected or invalid input
**
** Critical Section :   No
**
**==========================================================================*/
#if(FLTM_PERIODICREADBACK_ENABLE_ETH == STD_ON)
static boolean FltM_PeriodicReadBack_CompareEth(
    const Eth_RegisterReadbackType* cur,
    const Eth_RegisterReadbackType* ref)
{
    boolean blRetVal = FALSE;
    uint32 idx;

    /* Check for NULL pointers */
    if ((cur == NULL_PTR) || (ref == NULL_PTR))
    {
        blRetVal = FALSE;
    }
    else
    {
        if ((cur->EthReadBackReg_ALE_CONTROL                  == ref->EthReadBackReg_ALE_CONTROL) &&
            (cur->EthReadBackReg_I0_ALE_PORTCTL0             == ref->EthReadBackReg_I0_ALE_PORTCTL0) &&
            (cur->EthReadBackReg_I0_ALE_PORTCTL0_PORT_0      == ref->EthReadBackReg_I0_ALE_PORTCTL0_PORT_0) &&
            (cur->EthReadBackReg_I0_ALE_PORTCTL0_PORT_N      == ref->EthReadBackReg_I0_ALE_PORTCTL0_PORT_N) &&
            (cur->EthReadBackReg_THREADMAPDEF                == ref->EthReadBackReg_THREADMAPDEF) &&
            (cur->EthReadBackReg_ALE_UVLAN_MEMBER            == ref->EthReadBackReg_ALE_UVLAN_MEMBER) &&
            (cur->EthReadBackReg_ALE_UVLAN_URCAST            == ref->EthReadBackReg_ALE_UVLAN_URCAST) &&
            (cur->EthReadBackReg_ALE_UVLAN_RMCAST            == ref->EthReadBackReg_ALE_UVLAN_RMCAST) &&
            (cur->EthReadBackReg_ALE_UVLAN_UNTAG             == ref->EthReadBackReg_ALE_UVLAN_UNTAG) &&
            (cur->EthReadBackReg_CPTS_CONTROL                == ref->EthReadBackReg_CPTS_CONTROL) &&
            (cur->EthReadBackReg_PN_MAC_CONTROL_REG          == ref->EthReadBackReg_PN_MAC_CONTROL_REG) &&
            (cur->EthReadBackReg_PN_RX_MAXLEN_REG            == ref->EthReadBackReg_PN_RX_MAXLEN_REG) &&
            (cur->EthReadBackReg_USER_INT_MASK_CLEAR_REG     == ref->EthReadBackReg_USER_INT_MASK_CLEAR_REG) &&
            (cur->EthReadBackReg_USER_GROUP_USER_ACCESS_REG  == ref->EthReadBackReg_USER_GROUP_USER_ACCESS_REG) &&
            (cur->EthReadBackReg_POLL_EN_REG                 == ref->EthReadBackReg_POLL_EN_REG) &&
            (cur->EthReadBackReg_MDIO_CONTROL_REG            == ref->EthReadBackReg_MDIO_CONTROL_REG) &&
            (cur->EthReadBackReg_PORT_CONTROL_REG            == ref->EthReadBackReg_PORT_CONTROL_REG) &&
            (cur->EthReadBackReg_P0_CONTROL_REG              == ref->EthReadBackReg_P0_CONTROL_REG) &&
            (cur->EthReadBackReg_PN_TS_CTL_REG               == ref->EthReadBackReg_PN_TS_CTL_REG) &&
            (cur->EthReadBackReg_PN_TS_SEQ_LTYPE_REG         == ref->EthReadBackReg_PN_TS_SEQ_LTYPE_REG) &&
            (cur->EthReadBackReg_PN_TS_VLAN_LTYPE_REG        == ref->EthReadBackReg_PN_TS_VLAN_LTYPE_REG) &&
            (cur->EthReadBackReg_PN_TS_CTL_LTYPE2_REG        == ref->EthReadBackReg_PN_TS_CTL_LTYPE2_REG) &&
            (cur->EthReadBackReg_PN_TS_CTL2_REG              == ref->EthReadBackReg_PN_TS_CTL2_REG) &&
            (cur->EthReadBackReg_STAT_PORT_EN_REG            == ref->EthReadBackReg_STAT_PORT_EN_REG))
        {
            blRetVal = TRUE;

            /* Compare priority queue registers */
            for (idx = 0U; idx < ETH_PRIORITY_QUEUE_NUM; idx++)
            {
                if (cur->EthReadBackReg_PN_PRI_CIR_REG[idx] !=
                    ref->EthReadBackReg_PN_PRI_CIR_REG[idx])
                {
                    blRetVal = FALSE;
                    break;
                }
            }
        }
        else
        {
            blRetVal = FALSE;
        }
    }

    return blRetVal;
}

#endif

/*============================================================================
**
** Function Name    :   FltM_PeriodicReadBack_CompareEsm
**
** Visibility       :   Static
**
** Description      :   Compares the current ESM register readback snapshot
**                      against the stored golden reference snapshot.
**                      The comparison is used to detect static configuration
**                      corruption during periodic monitoring.
**
** Invocation       :   FltM_PeriodicReadBack_MainFunction
**
** Inputs           :   cur - Pointer to current ESM register readback data
**                      ref - Pointer to reference ESM register readback data
**
** Outputs          :   boolean
**                      TRUE  - Current and reference values are identical
**                      FALSE - Mismatch detected or invalid input
**
** Critical Section :   No
**
**==========================================================================*/
#if(FLTM_PERIODICREADBACK_ENABLE_ESM == STD_ON)
static boolean FltM_PeriodicReadBack_CompareEsm( const SDL_ESM_staticRegs* cur,
                                                 const SDL_ESM_staticRegs* ref)
{
    boolean blRetVal = TRUE;
    //uint32 idx;

    /* Check for NULL pointers */
    if ((cur == NULL_PTR) || (ref == NULL_PTR))
    {
        blRetVal = FALSE;
    }
    else
    {
        #if 0
        /* Compare ERR_GRP array */
        blRetVal = TRUE;
        for (idx = 0U; idx < ESM_NUMBER_OF_GROUP_REGS; idx++)
        {
            if (memcmp(&cur->ERR_GRP[idx],
                       &ref->ERR_GRP[idx],
                       sizeof(SDL_esmRegs_ERR_GRP_STATIC)) != 0)
            {
                blRetVal = FALSE;
                break;
            }
        }
        #endif
        /* Compare remaining registers only if ERR_GRP matches */
        if (blRetVal == TRUE)
        {
            if ((cur->PID               == ref->PID) &&
                (cur->INFO              == ref->INFO) &&
                (cur->EN                == ref->EN) &&
                (cur->ERR_EN_SET        == ref->ERR_EN_SET) &&
                (cur->ERR_EN_CLR        == ref->ERR_EN_CLR) &&
                (cur->LOW_PRI           == ref->LOW_PRI) &&
                (cur->HI_PRI            == ref->HI_PRI) &&
                (cur->LOW               == ref->LOW) &&
                (cur->HI                == ref->HI) &&
                (cur->PIN_CTRL          == ref->PIN_CTRL) &&
                (cur->PIN_CNTR_PRE      == ref->PIN_CNTR_PRE) &&
                (cur->PWMH_PIN_CNTR_PRE == ref->PWMH_PIN_CNTR_PRE) &&
                (cur->PWML_PIN_CNTR_PRE == ref->PWML_PIN_CNTR_PRE))
            {
                blRetVal = TRUE;
            }
            else
            {
                blRetVal = FALSE;
            }
        }
    }

    return blRetVal;
}
#endif



/*============================================================================
**
** Function Name    :   FltM_PeriodicReadBack_CompareVim
**
** Visibility       :   Static
**
** Description      :   Compares the current VIM register readback snapshot
**                      against the stored golden reference snapshot.
**
** Invocation       :   FltM_RbHandleVim
**
** Inputs           :   cur - Pointer to current VIM register readback data
**                      ref - Pointer to reference VIM register readback data
**
** Outputs          :   boolean
**                      TRUE  - Current and reference values are identical
**                      FALSE - Mismatch detected or invalid input
**
** Critical Section :   No
**
**==========================================================================*/
#if(FLTM_PERIODICREADBACK_ENABLE_VIM == STD_ON)
static boolean FltM_PeriodicReadBack_CompareVim(
                                            const SDL_vimStaticRegs* cur,
                                            const SDL_vimStaticRegs* ref)
{
    boolean blRetVal = TRUE;
    uint32 idx;

    if ((cur == NULL_PTR) || (ref == NULL_PTR))
    {
        blRetVal = FALSE;
    }
    else
    {
        for (idx = 0U; idx < SDL_VIM_MAX_INTR_GROUPS; idx++)
        {
            if ((cur->GRP[idx].INTMAP  != ref->GRP[idx].INTMAP) ||
                (cur->GRP[idx].INTTYPE != ref->GRP[idx].INTTYPE))
            {
                blRetVal = FALSE;
                break;
            }
        }

        if (blRetVal == TRUE)
        {
            for (idx = 0U;
                 idx < (SDL_VIM_MAX_INTR_GROUPS * SDL_VIM_NUM_INTRS_PER_GROUP);
                 idx++)
            {
                if ((cur->PRI[idx].INT != ref->PRI[idx].INT) ||
                    (cur->VEC[idx].INT != ref->VEC[idx].INT))
                {
                    blRetVal = FALSE;
                    break;
                }
            }
        }
    }

    return blRetVal;
}

/*============================================================================
**
** Function Name    :   FltM_CalculateVimCfgCrc
**
** Visibility       :   Static
**
** Description      :   Calculates CRC over VIM static configuration fields only.
**                      Runtime interrupt enable/status fields are excluded.
**
**==========================================================================*/
static uint32 FltM_CalculateVimCfgCrc(const SDL_vimStaticRegs* regs)
{
    uint32 crc = FLTM_CRC32_INIT_VALUE;
    uint32 idx;

    if (regs == NULL_PTR)
    {
        return 0U;
    }

    for (idx = 0U; idx < SDL_VIM_MAX_INTR_GROUPS; idx++)
    {
        crc = FltM_UpdateCrc32(crc,
                (const uint8*)&regs->GRP[idx].INTMAP,
                (uint32)sizeof(regs->GRP[idx].INTMAP));
        crc = FltM_UpdateCrc32(crc,
                (const uint8*)&regs->GRP[idx].INTTYPE,
                (uint32)sizeof(regs->GRP[idx].INTTYPE));
    }

    for (idx = 0U;
         idx < (SDL_VIM_MAX_INTR_GROUPS * SDL_VIM_NUM_INTRS_PER_GROUP);
         idx++)
    {
        crc = FltM_UpdateCrc32(crc,
                (const uint8*)&regs->PRI[idx].INT,
                (uint32)sizeof(regs->PRI[idx].INT));
        crc = FltM_UpdateCrc32(crc,
                (const uint8*)&regs->VEC[idx].INT,
                (uint32)sizeof(regs->VEC[idx].INT));
    }

    crc ^= FLTM_CRC32_INIT_VALUE;
    return crc;
}
#endif

/*============================================================================
**
** Function Name    :   FltM_VimGetStaticRegs
**
** Visibility       :   Static
**
** Description      :   Captures VIM static registers using TI SDL register
**                      access macros. This mirrors the TI-provided
**                      SDL_VIM_getStaticRegs implementation without changing
**                      delivered SDL source files.
**
** Invocation       :   FltM_Soc_PeriodicReadBack_Init
**                      FltM_RbHandleVim
**
** Inputs           :   pRegs       - Pointer to VIM register overlay
**                      pStaticRegs - Pointer to destination snapshot
**
** Outputs          :   int32_t
**                      SDL_PASS - Snapshot captured successfully
**                      SDL_EFAIL - Invalid input
**
** Critical Section :   No
**
**==========================================================================*/
#if(FLTM_PERIODICREADBACK_ENABLE_VIM == STD_ON)
static int32_t FltM_VimGetStaticRegs(SDL_vimRegs* pRegs,
                                      SDL_vimStaticRegs* pStaticRegs)
{
    int32_t retVal = SDL_PASS;
    uint32 i;
    uint32 maxIntrs;
    uint32 numGroups;

    if ((pRegs == NULL_PTR) || (pStaticRegs == NULL_PTR))
    {
        retVal = SDL_EFAIL;
    }
    else
    {
        pStaticRegs->PID = SDL_REG32_RD(&pRegs->PID);
        pStaticRegs->INFO = SDL_REG32_RD(&pRegs->INFO);

        maxIntrs = pStaticRegs->INFO;
        numGroups = maxIntrs / SDL_VIM_NUM_INTRS_PER_GROUP;

        if ((maxIntrs > (SDL_VIM_MAX_INTR_GROUPS * SDL_VIM_NUM_INTRS_PER_GROUP)) ||
            (numGroups > SDL_VIM_MAX_INTR_GROUPS))
        {
            retVal = SDL_EFAIL;
        }
        else
        {
            for (i = 0U; i < numGroups; i++)
            {
                pStaticRegs->GRP[i].INTMAP = SDL_REG32_RD(&pRegs->GRP[i].INTMAP);
                pStaticRegs->GRP[i].INTR_EN_CLR = 0U;
                pStaticRegs->GRP[i].INTR_EN_SET = 0U;
                pStaticRegs->GRP[i].INTTYPE = SDL_REG32_RD(&pRegs->GRP[i].INTTYPE);
            }

            for (i = 0U; i < maxIntrs; i++)
            {
                pStaticRegs->PRI[i].INT = SDL_REG32_RD(&pRegs->PRI[i].INT);
                pStaticRegs->VEC[i].INT = SDL_REG32_RD(&pRegs->VEC[i].INT);
            }

            for (i = numGroups; i < SDL_VIM_MAX_INTR_GROUPS; i++)
            {
                pStaticRegs->GRP[i].INTMAP = 0U;
                pStaticRegs->GRP[i].INTR_EN_CLR = 0U;
                pStaticRegs->GRP[i].INTR_EN_SET = 0U;
                pStaticRegs->GRP[i].INTTYPE = 0U;
            }

            for (i = maxIntrs;
                 i < (SDL_VIM_MAX_INTR_GROUPS * SDL_VIM_NUM_INTRS_PER_GROUP);
                 i++)
            {
                pStaticRegs->PRI[i].INT = 0U;
                pStaticRegs->VEC[i].INT = 0U;
            }
        }
    }

    return retVal;
}
#endif


/*============================================================================
**
** Function Name    :   FltM_PeriodicReadBack_CompareDdr
**
** Visibility       :   Static
**
** Description      :   Compares the current DDRSS static register snapshot
**                      against the stored golden reference snapshot.
**
** Invocation       :   FltM_RbHandleDdr
**
** Inputs           :   cur - Pointer to current DDRSS register readback data
**                      ref - Pointer to reference DDRSS register readback data
**
** Outputs          :   boolean
**                      TRUE  - Current and reference values are identical
**                      FALSE - Mismatch detected or invalid input
**
** Critical Section :   No
**
**==========================================================================*/
#if(FLTM_PERIODICREADBACK_ENABLE_DDR == STD_ON)
static boolean FltM_PeriodicReadBack_CompareDdr(const uint32* cur,
                                                const uint32* ref)
{
    boolean blRetVal = TRUE;
    uint32 idx;

    if ((cur == NULL_PTR) || (ref == NULL_PTR))
    {
        blRetVal = FALSE;
    }
    else
    {
        for (idx = 0U; idx < FLTM_DDR_STATIC_REG_COUNT; idx++)
        {
            if (cur[idx] != ref[idx])
            {
                blRetVal = FALSE;
                break;
            }
        }
    }

    return blRetVal;
}
#endif

/*============================================================================
**
** Function Name    :   FltM_DdrReadStaticRegs
**
** Visibility       :   Static
**
** Description      :   Reads DDRSS static configuration registers listed by
**                      TI using offsets from base address 0x0F300000.
**
** Invocation       :   FltM_Soc_PeriodicReadBack_Init
**                      FltM_RbHandleDdr
**
** Inputs           :   regValues - Pointer to destination register snapshot
**
** Outputs          :   Std_ReturnType
**                      E_OK     - Snapshot captured successfully
**                      E_NOT_OK - Invalid input
**
** Critical Section :   No
**
**==========================================================================*/
#if(FLTM_PERIODICREADBACK_ENABLE_DDR == STD_ON)
static Std_ReturnType FltM_DdrReadStaticRegs(uint32* regValues)
{
    Std_ReturnType retVal = E_OK;
    uint32 idx;
    volatile uint32* regAddr;

    if (regValues == NULL_PTR)
    {
        retVal = E_NOT_OK;
    }
    else
    {
        for (idx = 0U; idx < FLTM_DDR_STATIC_REG_COUNT; idx++)
        {
            regAddr = (volatile uint32*)((uintptr_t)FLTM_DDRSS_BASE_ADDR +
                      (uintptr_t)FltM_PeriodicReadBack_DdrOffsetList[idx]);
            regValues[idx] = SDL_REG32_RD(regAddr);
        }
    }

    return retVal;
}
#endif


/*============================================================================
**
** Function Name    :   FltM_PeriodicReadBack_CompareR5f
**
** Visibility       :   Static
**
** Description      :   Compares the current R5F core static register snapshot
**                      against the stored golden reference snapshot.
**
** Invocation       :   FltM_RbHandleR5f
**
** Inputs           :   cur - Pointer to current R5F register readback data
**                      ref - Pointer to reference R5F register readback data
**
** Outputs          :   boolean
**                      TRUE  - Current and reference values are identical
**                      FALSE - Mismatch detected or invalid input
**
** Critical Section :   No
**
**==========================================================================*/
#if(FLTM_PERIODICREADBACK_ENABLE_R5F == STD_ON)
static boolean FltM_PeriodicReadBack_CompareR5f(const uint32* cur,
                                                const uint32* ref)
{
    boolean blRetVal = TRUE;
    uint32 idx;

    if ((cur == NULL_PTR) || (ref == NULL_PTR))
    {
        blRetVal = FALSE;
    }
    else
    {
        for (idx = 0U; idx < FLTM_R5F_STATIC_REG_COUNT; idx++)
        {
            if (cur[idx] != ref[idx])
            {
                blRetVal = FALSE;
                break;
            }
        }
    }

    return blRetVal;
}
#endif

/*============================================================================
**
** Function Name    :   FltM_R5fReadStaticRegs
**
** Visibility       :   Static
**
** Description      :   Reads R5F.CPU6 static core registers using CP15
**                      instructions. These registers do not have an SoC
**                      memory-mapped base address.
**
** Invocation       :   FltM_Soc_PeriodicReadBack_Init
**                      FltM_RbHandleR5f
**
** Inputs           :   regValues - Pointer to destination register snapshot
**
** Outputs          :   Std_ReturnType
**                      E_OK     - Snapshot captured successfully
**                      E_NOT_OK - Invalid input
**
** Critical Section :   No
**
**==========================================================================*/
#if(FLTM_PERIODICREADBACK_ENABLE_R5F == STD_ON)
static Std_ReturnType FltM_R5fReadStaticRegs(uint32* regValues)
{
    Std_ReturnType retVal = E_OK;
    uint32 regionIdx;
    uint32 regIdx;
    uint32 originalRgnr;

    if (regValues == NULL_PTR)
    {
        retVal = E_NOT_OK;
    }
    else
    {
        originalRgnr = FltM_R5fReadRgnr();

        regValues[FLTM_R5F_REG_CSSELR] = FltM_R5fReadCsselr();
        regValues[FLTM_R5F_REG_SCTLR] = FltM_R5fReadSctlr();
        regValues[FLTM_R5F_REG_ACTLR] = FltM_R5fReadActlr();
        regValues[FLTM_R5F_REG_SACTLR] = FltM_R5fReadSactlr();
        regValues[FLTM_R5F_REG_RGNR] = originalRgnr;

        regIdx = FLTM_R5F_REG_MPU_REGION_START;
        /* The configured dynamic MPU region is skipped from static readback. */
        for (regionIdx = 0U; regionIdx < FLTM_R5F_MPU_TOTAL_REGION_COUNT; regionIdx++)
        {
            if (regionIdx == FLTM_PERIODICREADBACK_R5F_DYNAMIC_MPU_REGION)
            {
                continue;
            }

            FltM_R5fWriteRgnr(regionIdx);
            regValues[regIdx] = FltM_R5fReadRbar();
            regIdx++;
            regValues[regIdx] = FltM_R5fReadRser();
            regIdx++;
            regValues[regIdx] = FltM_R5fReadRacr();
            regIdx++;
        }

        FltM_R5fWriteRgnr(originalRgnr);
    }

    return retVal;
}
#endif

#if(FLTM_PERIODICREADBACK_ENABLE_R5F == STD_ON)
static uint32 FltM_R5fReadCsselr(void)
{
    uint32 regVal;
    __asm__ volatile ("MRC p15, #2, %0, c0, c0, #0" : "=r" (regVal));
    return regVal;
}
#endif

#if(FLTM_PERIODICREADBACK_ENABLE_R5F == STD_ON)
static uint32 FltM_R5fReadSctlr(void)
{
    uint32 regVal;
    __asm__ volatile ("MRC p15, #0, %0, c1, c0, #0" : "=r" (regVal));
    return regVal;
}
#endif

#if(FLTM_PERIODICREADBACK_ENABLE_R5F == STD_ON)
static uint32 FltM_R5fReadActlr(void)
{
    uint32 regVal;
    __asm__ volatile ("MRC p15, #0, %0, c1, c0, #1" : "=r" (regVal));
    return regVal;
}
#endif

#if(FLTM_PERIODICREADBACK_ENABLE_R5F == STD_ON)
static uint32 FltM_R5fReadSactlr(void)
{
    uint32 regVal;
    __asm__ volatile ("MRC p15, #0, %0, c15, c0, #0" : "=r" (regVal));
    return regVal;
}
#endif

#if(FLTM_PERIODICREADBACK_ENABLE_R5F == STD_ON)
static uint32 FltM_R5fReadRgnr(void)
{
    uint32 regVal;
    __asm__ volatile ("MRC p15, #0, %0, c6, c2, #0" : "=r" (regVal));
    return regVal;
}
#endif

#if(FLTM_PERIODICREADBACK_ENABLE_R5F == STD_ON)
static void FltM_R5fWriteRgnr(uint32 regVal)
{
    __asm__ volatile ("MCR p15, #0, %0, c6, c2, #0" :: "r" (regVal));
    __asm__ volatile ("ISB");
}
#endif

#if(FLTM_PERIODICREADBACK_ENABLE_R5F == STD_ON)
static uint32 FltM_R5fReadRbar(void)
{
    uint32 regVal;
    __asm__ volatile ("MRC p15, #0, %0, c6, c1, #0" : "=r" (regVal));
    return regVal;
}
#endif

#if(FLTM_PERIODICREADBACK_ENABLE_R5F == STD_ON)
static uint32 FltM_R5fReadRser(void)
{
    uint32 regVal;
    __asm__ volatile ("MRC p15, #0, %0, c6, c1, #2" : "=r" (regVal));
    return regVal;
}
#endif

#if(FLTM_PERIODICREADBACK_ENABLE_R5F == STD_ON)
static uint32 FltM_R5fReadRacr(void)
{
    uint32 regVal;
    __asm__ volatile ("MRC p15, #0, %0, c6, c1, #4" : "=r" (regVal));
    return regVal;
}
#endif

/*============================================================================
**
** Function Name    :   FltM_CalculateCrc32
**
** Visibility       :   Static
**
** Description      :   Calculates a CRC32 checksum over the provided data
**                      buffer using a fixed CRC 32 (IEEE 802.3).
**                      This checksum is used to verify the integrity of
**                      static register readback snapshots during periodic
**                      monitoring.
**                      Polynomial : 0xEDB88320
**
** Invocation       :   FltM_Soc_PeriodicReadBack_Init
**                      FltM_Soc_Periodic_Reg_ReadBack
**
** Inputs           :   data   - Pointer to input data buffer
**                      length - Size of the data buffer in bytes
**
** Outputs          :   uint32
**                      CRC32 value calculated over the input buffer
**
** Critical Section :   No
**
**==========================================================================*/

static uint32 FltM_CalculateCrc32(const uint8* data, uint32 length)
{
    uint32 crc = FLTM_CRC32_INIT_VALUE;

    /* Check for NULL pointers */
    if ((data == NULL_PTR) || (length == 0U))
    {
        return 0U;
    }

    crc = FltM_UpdateCrc32(crc, data, length);
    crc ^= FLTM_CRC32_INIT_VALUE;
    return crc;
}

static uint32 FltM_UpdateCrc32(uint32 crc, const uint8* data, uint32 length)
{
    uint32 byteIdx;
    uint8  bitIdx;

    if ((data == NULL_PTR) || (length == 0U))
    {
        return crc;
    }

    for (byteIdx = 0U; byteIdx < length; byteIdx++)
    {
        crc ^= (uint32)data[byteIdx];

        for (bitIdx = 0U; bitIdx < 8U; bitIdx++)
        {
            if ((crc & 1UL) != 0UL)
            {
                crc = (crc >> 1U) ^ FLTM_CRC32_POLYNOMIAL;
            }
            else
            {
                crc >>= 1U;
            }
        }
    }

    return crc;
}

#define FLTM_SEC_CODE_STOP
#include "MemMap.h"

/*****************************************************************************
*     End of File
*
*******************************************************************************/
/****************************************************************************
*   for each change to this file, be sure to record:                        *
*      1.  who made the change and when the change was made                 *
*      2.  why the change was made and the intended result                  *
*   Following block needs to be repeated for each change                    *
*****************************************************************************/
/*----------------------------------------------------------------------------
REVISION HISTORY
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :10-Apr-2026
By                :RRAJAGO2
Traceability      :BMIC29130-42359
Change Description:Periodic Readback implementation for static Registers
-----------------------------------------------------------------------------*/
