///---------------------------------------------------------------------------------------------------------------------
///
/// VISTEON CORPORATION CONFIDENTIAL
/// ________________________________
///
/// [2017] Visteon Corporation
/// All Rights Reserved.
///
/// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
/// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
/// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
/// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
/// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
/// under all copyright laws to protect this work as a published work, when appropriate.
/// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
/// without the written authorization of Visteon Corporation.
///
///---------------------------------------------------------------------------------------------------------------------
/// @file
/// @ingroup UclALCrypto
/// UCL Crypto Abstraction Layer Type Definitions
///
///---------------------------------------------------------------------------------------------------------------------
#ifndef UCLALCRYPTOTYPES_H
#define UCLALCRYPTOTYPES_H
#ifdef __cplusplus
extern "C" {
#endif

#include "Ucl_Types.h"

///
/// @brief UclALCrypto AES Key Size. \n
///
#define UCLALCRYPTO_KEYSIZE 16u

///
/// @brief Crypto Key Type
///
typedef enum {
    eUclALCryptoKeyType_EK,  ///< Encryption Key. Persistent Key.
    eUclALCryptoKeyType_SK,  ///< Session Key. Transient Key.
    eUclALCryptoKeyType_Last ///< Guard
} EUclALCryptoKeyType;

///
/// @brief Crypto State Type
///
typedef enum {
    eUclALCryptoState_Uninitialized, ///< Crypto Uninitialized
    eUclALCryptoState_Initialized,   ///< Crypto Initialized
    eUclALCryptoState_Last           ///< Guard
} EUclALCryptoState;

#ifdef __cplusplus
}
#endif
#endif //UCLALCRYPTOTYPES_H
