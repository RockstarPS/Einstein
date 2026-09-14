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
/// @defgroup UclIL
/// @brief UCL Interface Layer handles Scheduling, Routing, Priority Management, Stream Based Message Transfer etc.
/// @file
/// @ingroup UclIL
/// UCL Interface Layer Common Data Type Definitions.
///
///---------------------------------------------------------------------------------------------------------------------
#ifndef UCLILTYPES_H
#define UCLILTYPES_H
#ifdef __cplusplus
extern "C"
{
#endif
///
/// @brief UCL Message Priority Level Definitions
///
typedef uint8 EUclILMsgPriorityLevel;
#define eUclILMsgPriorityLevel_Critical (EUclILMsgPriorityLevel )0  ///< Critical message. Highest priority.
#define eUclILMsgPriorityLevel_High (EUclILMsgPriorityLevel )1      ///< High priority message
#define eUclILMsgPriorityLevel_Medium (EUclILMsgPriorityLevel )2    ///< Medium priority message
#define eUclILMsgPriorityLevel_Low (EUclILMsgPriorityLevel )3       ///< Low priority message
#define eUclILMsgPriorityLevel_Last (EUclILMsgPriorityLevel)4       ///< Guard

///
/// @brief UCL Message Security Level Definitions
///
typedef uint8 EUclILMsgSecurityLevel;
#define eUclILMsgSecurityLevel_Unsecure  (EUclILMsgSecurityLevel)0          ///< Unsecure message. Protected with checksum
#define eUclILMsgSecurityLevel_Authenticated (EUclILMsgSecurityLevel)1      ///< Authenticated message. Protected with CMAC
#define eUclILMsgSecurityLevel_Encrypted (EUclILMsgSecurityLevel)2          ///< Encrypted message. Encrypted with CBC
#define eUclILMsgSecurityLevel_Reserved (EUclILMsgSecurityLevel)3           ///< Reserved
#define eUclILMsgSecurityLevel_Last (EUclILMsgSecurityLevel)4               ///< Guard


#ifdef __cplusplus
}
#endif

#endif //UCLILTYPES_H