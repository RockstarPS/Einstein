//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2019] Visteon Corporation
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

//=====================================================================================================================
//  INCLUDED FILES
//=====================================================================================================================

#ifndef CHECKSUM_H
#define CHECKSUM_H

#include "Std_Types.h"

#define CHECKSUM_AR_RELEASE_MAJOR_VERSION       4U
#define CHECKSUM_AR_RELEASE_MINOR_VERSION       2U
#define CHECKSUM_AR_RELEASE_REVISION_VERSION    2U

# define CHECKSUM_SW_MAJOR_VERSION              (0u)
# define CHECKSUM_SW_MINOR_VERSION              (0u)
# define CHECKSUM_SW_PATCH_VERSION              (6u)

extern uint32 Checksum_CalculateAdditiveChecksum32(const uint32 *Crc_DataPtr, uint32 Crc_Length, uint32 Crc_StartValue32, boolean Crc_IsFirstCall);
extern uint8 Checksum_CalculateCheckSum4(const uint8 *CheckSum_DataPtr, uint32 CheckSum_Length, uint8 CheckSum_StartValue8, boolean CheckSum_IsFirstCall);
extern uint8 Checksum_CalculateCheckSum8(const uint8 *CheckSum_DataPtr, uint32 CheckSum_Length, uint8 CheckSum_StartValue8, boolean CheckSum_IsFirstCall);
#endif
