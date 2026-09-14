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
#ifndef TFTDRVCOMMON_H
#define TFTDRVCOMMON_H

typedef struct SPortValuePair_t
{
    uint_io16_t* Port;
    uint32      Value;
} SPortValuePair;

// brief Enumerates the levels of TFT activate and deactivate sequences
typedef enum EGdtCddActLvl_t
{
    eActLvl_Inactive,        // TFT is inactive
    eActLvl_PowerEn,         // DioConf_DioChannel_DIO_DSPL_POW_EN is High
    eActLvl_Active,          // TFT is active
    eActLvl_Count
} EActivateLvl;

typedef void TSetPowerSupplyFunc(boolean IsOn);
typedef void TSetTTFEnableFunc(boolean IsOn);

//=====================================================================================================================
//  FORWARD DECLARATIONS
//=====================================================================================================================

void                    ConfigurePorts(const SPortValuePair* Configs, uint32 ConfigsCnt);
Std_ReturnType          TFTActivation(EActivateLvl* CurrentLvlv, TSetPowerSupplyFunc const PSetPowerFunc, TSetTTFEnableFunc const PEnableTFT);
Std_ReturnType          TFTDeActivation(EActivateLvl* CurrentLvlv, TSetPowerSupplyFunc const PSetPowerFunc, TSetTTFEnableFunc const PEnableTFT);

#endif // TFTDRVCOMMON_H
