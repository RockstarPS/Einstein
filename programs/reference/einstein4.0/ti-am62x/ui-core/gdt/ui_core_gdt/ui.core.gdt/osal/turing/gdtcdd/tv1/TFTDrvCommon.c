//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2015] Visteon Corporation
// All Rights Reserved.
//
// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
// under all copyright laws to protect this work as a published work, when appropriate.
// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
// without the written authorization of Visteon Corporation.
//
//---------------------------------------------------------------------------------------------------------------------

#include "Std_Types.h"

#include "s6j3200_SMC.h"
#include "s6j3200_PPC.h"
#include "abstract.h"

#include "TFTDrvCommon.h"


//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================

#define IDD_PORT_WPREG_PPC_CONFIG(reg, data)        \
{                                                   \
    un_ppc_keycdr_t wk;                             \
    uint32_t adr = (uint32_t)(&(reg));                  \
    uint8_t size_key;                               \
    wk.au16Halfword[0] =(((uint16_t)adr) & 0x7FFFUL);   \
    size_key = (((uint8_t)(sizeof(reg) >> 1U)) << 4U);             \
    IRQ_DISABLE_LOCAL();                            \
    wk.au8Byte[3] = size_key | ((uint8_t)(0U << 6U)); \
    PPC_KEYCDR = wk.u32Register;                    \
    wk.au8Byte[3] = size_key | ((uint8_t)(1U << 6U)); \
    PPC_KEYCDR = wk.u32Register;                    \
    wk.au8Byte[3] = size_key | ((uint8_t)(2U << 6U)); \
    PPC_KEYCDR = wk.u32Register;                    \
    wk.au8Byte[3] = size_key | ((uint8_t)(3U << 6U)); \
    PPC_KEYCDR = wk.u32Register;                    \
    (reg) = (data);                                     \
    IRQ_RESTORE();                                  \
}

//=====================================================================================================================
//  FORWARD DECLARATIONS
//=====================================================================================================================

//=====================================================================================================================
//  PRIVATE
//=====================================================================================================================


//=====================================================================================================================
//  PUBLIC
//=====================================================================================================================

//---------------------------------------------------------------------------------------------------------------------
/// brief  Configure the ports given with the list
///
/// param: Configs List of ports value
/// param: ConfigsCnt Count of the pairs
///
/// return void
//---------------------------------------------------------------------------------------------------------------------
void ConfigurePorts(const SPortValuePair* Configs, uint32 ConfigsCnt)
{
    uint32 Ix;

    for(Ix = 0UL; Ix < ConfigsCnt; Ix++)
    {
        IDD_PORT_WPREG_PPC_CONFIG(*Configs[Ix].Port, Configs[Ix].Value);
    }
}

//---------------------------------------------------------------------------------------------------------------------
/// brief  Transitional activation state
///
/// return E_OK:           Succeed
///<br>     E_NOT_READY:    In progress. Keeps the component in this state.
///<br>     E_NOT_OK:       Failed
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType TFTActivation( EActivateLvl* CurrentLvlv, TSetPowerSupplyFunc const PSetPowerFunc, TSetTTFEnableFunc const PEnableTFT)
{
    Std_ReturnType Result;

    switch(*CurrentLvlv)
    {
    case eActLvl_Inactive:
        PSetPowerFunc((uint8_t)TRUE);
        *CurrentLvlv = eActLvl_PowerEn;
        Result = E_NOT_READY; // delay activation
        break;

    case eActLvl_PowerEn:
        PEnableTFT((uint8_t)TRUE);
        *CurrentLvlv = eActLvl_Active;
        Result = E_OK;
        break;

    case eActLvl_Active:

        Result = E_OK;
        break;

    case eActLvl_Count:
    default:
        Result = E_NOT_OK;
        break;
    }

    return Result;
}

//---------------------------------------------------------------------------------------------------------------------
/// brief  Transitional de-activation state
///
/// return E_OK:           Succeed
///<br>     E_NOT_READY:    In progress
///<br>     E_NOT_OK:       Failed
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType TFTDeActivation( EActivateLvl* CurrentLvlv, TSetPowerSupplyFunc const PSetPowerFunc, TSetTTFEnableFunc const PEnableTFT )
{
    Std_ReturnType Result;

    switch(*CurrentLvlv)
    {
    case eActLvl_Active:
        PEnableTFT((uint8_t)FALSE);
        *CurrentLvlv = eActLvl_PowerEn;
        Result = E_NOT_READY; // delay activation
        break;

    case eActLvl_PowerEn:
        PSetPowerFunc((uint8_t)FALSE);
        *CurrentLvlv = eActLvl_Inactive;
        Result = E_OK;
        break;

    case eActLvl_Inactive:

        Result = E_OK;
        break;

    case eActLvl_Count:
    default:
        Result = E_NOT_OK;
        break;
    }

    return Result;
}


