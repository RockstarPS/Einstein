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
 * @file        FltM_Soc_Periodic_ReadBack_Cfg.h
 * @details     Configuration header file for Periodic Readback
 *              implementation for AM62P SoC Registers
 * @note
 *              Compiler    : clang \n
 *              Target Hw   : TI AM62Px SOC
 *
 * @copyright   Visteon (c) 2026
 *
 */

 #ifndef FLTM_SOC_PERIODICREADBACK_CFG_H_
 #define FLTM_SOC_PERIODICREADBACK_CFG_H_

 /*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "Std_Types.h"

 /*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
#define FLTM_PERIODICREADBACK_ENABLE_DIO   (STD_ON)
#define FLTM_PERIODICREADBACK_ENABLE_SPI   (STD_OFF)
#define FLTM_PERIODICREADBACK_ENABLE_GPT   (STD_OFF)
#define FLTM_PERIODICREADBACK_ENABLE_ETH   (STD_OFF)
#define FLTM_PERIODICREADBACK_ENABLE_ESM   (STD_OFF)
#define FLTM_PERIODICREADBACK_ENABLE_VIM   (STD_OFF)
#define FLTM_PERIODICREADBACK_ENABLE_DDR   (STD_OFF)
#define FLTM_PERIODICREADBACK_ENABLE_R5F   (STD_OFF)

#if (FLTM_PERIODICREADBACK_ENABLE_DIO == STD_ON)
#include "Dio.h"
#if (DIO_REGISTER_READBACK_API != STD_ON)
#error "DIO periodic readback requires DIO_REGISTER_READBACK_API == STD_ON"
#endif
#endif

#if (FLTM_PERIODICREADBACK_ENABLE_SPI == STD_ON)
#include "Spi.h"
#if (SPI_REGISTER_READBACK_API != STD_ON)
#error "SPI periodic readback requires SPI_REGISTER_READBACK_API == STD_ON"
#endif
#endif

#if (FLTM_PERIODICREADBACK_ENABLE_GPT == STD_ON)
#include "Gpt.h"
#if (GPT_REGISTER_READBACK_API != STD_ON)
#error "GPT periodic readback requires GPT_REGISTER_READBACK_API == STD_ON"
#endif
#endif

#if (FLTM_PERIODICREADBACK_ENABLE_ETH == STD_ON)
#include "Eth.h"
#if (ETH_REGISTER_READBACK_API != STD_ON)
#error "ETH periodic readback requires ETH_REGISTER_READBACK_API == STD_ON"
#endif
#endif

#if (FLTM_PERIODICREADBACK_ENABLE_ESM == STD_ON)
#include "sdl_esm.h"
#endif

#if (FLTM_PERIODICREADBACK_ENABLE_VIM == STD_ON)
#include "sdl_vim.h"
#include "sdl_types.h"
#endif

/* -------------------------------------------------
 * Number of configured instances
 * ------------------------------------------------- */
#define FLTM_PERIODICREADBACK_DIO_NUM_CHANNELS     (8U)
#define FLTM_PERIODICREADBACK_SPI_NUM_HWUNITS      (2U)
#define FLTM_PERIODICREADBACK_GPT_NUM_CHANNELS     (1U)
#define FLTM_PERIODICREADBACK_ETH_NUM_CONTROLLERS  (1U)
#define FLTM_PERIODICREADBACK_ESM_NUM_INSTANCES    (2U)
#define FLTM_PERIODICREADBACK_DDR_NUM_REGISTERS     (FLTM_DDR_STATIC_REG_COUNT)
#define FLTM_PERIODICREADBACK_R5F_NUM_REGISTERS     (FLTM_R5F_STATIC_REG_COUNT)


#define FLTM_PERIODICREADBACK_R5F_DYNAMIC_MPU_REGION    (10U)

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/

#if (FLTM_PERIODICREADBACK_ENABLE_DIO == STD_ON)
extern const Dio_ChannelType
    FltM_PeriodicReadBack_DioChannelList[FLTM_PERIODICREADBACK_DIO_NUM_CHANNELS];
#endif

#if (FLTM_PERIODICREADBACK_ENABLE_SPI == STD_ON)
extern const Spi_HWUnitType FltM_PeriodicReadBack_SpiHwUnitList[FLTM_PERIODICREADBACK_SPI_NUM_HWUNITS];
#endif

#if (FLTM_PERIODICREADBACK_ENABLE_GPT == STD_ON)
extern const Gpt_ChannelType FltM_PeriodicReadBack_GptChannelList[FLTM_PERIODICREADBACK_GPT_NUM_CHANNELS];
#endif

#if (FLTM_PERIODICREADBACK_ENABLE_ETH == STD_ON)
extern const uint8 FltM_PeriodicReadBack_EthCtrlList[FLTM_PERIODICREADBACK_ETH_NUM_CONTROLLERS];
#endif

#if (FLTM_PERIODICREADBACK_ENABLE_ESM == STD_ON)
extern const SDL_ESM_Inst FltM_PeriodicReadBack_EsmInstanceList[FLTM_PERIODICREADBACK_ESM_NUM_INSTANCES];
#endif

#if (FLTM_PERIODICREADBACK_ENABLE_DDR == STD_ON)
extern const uint32 FltM_PeriodicReadBack_DdrOffsetList[FLTM_PERIODICREADBACK_DDR_NUM_REGISTERS];
#endif

#endif /* FLTM_SOC_PERIODICREADBACK_CFG_H_ */

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
