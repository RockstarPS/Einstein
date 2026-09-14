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
 * @details     Periodic Software Readback for AM62P SoC Static Registers
 * @note
 *              Compiler    : clang \n
 *              Target Hw   : Independent
 *
 * @copyright   Visteon (c) 2026
 *
 */
#ifndef FLTM_SOC_PERIODICREADBACK_H_
#define FLTM_SOC_PERIODICREADBACK_H_



/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#define FLTM_DDR_STATIC_REG_COUNT    (38U)
#define FLTM_R5F_MPU_TOTAL_REGION_COUNT        (16U)
#define FLTM_R5F_MPU_MONITORED_REGION_COUNT    (FLTM_R5F_MPU_TOTAL_REGION_COUNT - 1U)
#define FLTM_R5F_STATIC_REG_COUNT    (5U + (FLTM_R5F_MPU_MONITORED_REGION_COUNT * 3U))

#include "FltM_Soc_Periodic_ReadBack_Cfg.h"


#define FLTM_SEC_CODE_START
#define FLTM_CORE_CONST_SEC_START
#define FLTM_CORE_DATA_SEC_START
#define FLTM_CORE_BSS_SEC_START

#include "MemMap.h"


typedef enum
{
    FLTM_RB_STATE_IDLE = 0,   /* No periodic readback configured */
    FLTM_RB_STATE_DIO,
    FLTM_RB_STATE_SPI,
    FLTM_RB_STATE_GPT,
    FLTM_RB_STATE_ETH,
    FLTM_RB_STATE_ESM,
    FLTM_RB_STATE_VIM,
    FLTM_RB_STATE_DDR,
    FLTM_RB_STATE_R5F,
    FLTM_RB_STATE_COMPLETE
} FltM_ReadBackStateType;


#if (FLTM_PERIODICREADBACK_ENABLE_DIO == STD_ON)
typedef struct
{
    Dio_RegisterReadbackType Regs;
    uint32                  Crc;
} FltM_DioGoldenSampleType;
#endif

#if (FLTM_PERIODICREADBACK_ENABLE_SPI == STD_ON)
typedef struct
{
    Spi_RegisterReadbackType Regs;
    uint32                  Crc;
} FltM_SpiGoldenSampleType;
#endif

#if (FLTM_PERIODICREADBACK_ENABLE_GPT == STD_ON)
typedef struct
{
    Gpt_RegisterReadbackType Regs;
    uint32                  Crc;
} FltM_GptGoldenSampleType;
#endif

#if (FLTM_PERIODICREADBACK_ENABLE_ETH == STD_ON)
typedef struct
{
    Eth_RegisterReadbackType Regs;
    uint32                  Crc;
} FltM_EthGoldenSampleType;
#endif

#if (FLTM_PERIODICREADBACK_ENABLE_ESM == STD_ON)
typedef struct
{
    SDL_ESM_staticRegs Regs;
    uint32             Crc;
} FltM_EsmGoldenSampleType;
#endif

#if (FLTM_PERIODICREADBACK_ENABLE_VIM == STD_ON)
typedef struct
{
    SDL_vimStaticRegs Regs;
    uint32            Crc;
} FltM_VimGoldenSampleType;
#endif

#if (FLTM_PERIODICREADBACK_ENABLE_DDR == STD_ON)
typedef struct
{
    uint32 Regs[FLTM_DDR_STATIC_REG_COUNT];
    uint32 Crc;
} FltM_DdrGoldenSampleType;
#endif

#if (FLTM_PERIODICREADBACK_ENABLE_R5F == STD_ON)
typedef struct
{
    uint32 Regs[FLTM_R5F_STATIC_REG_COUNT];
    uint32 Crc;
} FltM_R5FGoldenSampleType;
#endif

/*****************************************************************************
*                               Functions                                    *
******************************************************************************/
/**
 * @brief Capture golden reference of static configuration registers
 */
extern Std_ReturnType FltM_Soc_PeriodicReadBack_Init(void);

/**
 * @brief Periodic readback and comparison of static configuration registers
 */
extern Std_ReturnType FltM_Soc_Periodic_Reg_ReadBack(void);


#define FLTM_SEC_CODE_STOP
#define FLTM_CORE_CONST_SEC_END
#define FLTM_CORE_DATA_SEC_END
#define FLTM_CORE_BSS_SEC_END

#include "MemMap.h"

#endif /* FLTM_SOC_PERIODICREADBACK_H_ */
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
