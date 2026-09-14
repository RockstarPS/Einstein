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
/// @ingroup UclIL
/// UCL Interface Layer Stream Type Definitions
///
///---------------------------------------------------------------------------------------------------------------------
#ifndef UCLILSTREAMTYPES_H
#define UCLILSTREAMTYPES_H

#include "UclILStream_Impl_Channel.h"

#ifdef __cplusplus
extern "C" {
#endif

#define UCL_STREAM_CID_SIZE	sizeof(ucl_ch_t)
#define UCL_STREAM_FID_SIZE	sizeof(ucl_fd_t)	
#define UCL_STREAM_RID_SIZE	sizeof(uint8)
#define UCL_STREAM_BID_SIZE	sizeof(sint32)
#define UCL_STREAM_MID_SIZE	sizeof(sint32)

#ifdef __cplusplus
}
#endif
#endif //UCLILSTREAMTYPES_H
