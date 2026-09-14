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
/// @ingroup UclSysStream
/// Ucl System Implementation for Ucl Streamn. APIs in this file are not to be called directly by the users
///
///---------------------------------------------------------------------------------------------------------------------

#ifndef UCSYS_IMPL_H
#define UCSYS_IMPL_H

#include "Ucl_Types.h"
#include "UclDL_Types.h"
//#include "ucl_channel.h" UclILChannel

///
/// @brief Configuration data for UclSysStream_Impl. \n
///
/// The SUclSysCfg structure defines the constant configuration data for UclDL_Impl class.
///
typedef struct
{
	uint8 dummy;
} SUclSysStreamCfg;
///
/// @brief Private instance data for UclSysStream_Impl. \n
/// @ingroup UclSysStream
///
/// The SUclSysStreamInst structure defines the private instance data for UclSysStream_Impl class.
///
typedef struct
{
    uint8 numIUclALOs;
    uint8 *pIUclALOs;
    uint8 numIUclILStream;
    uint8 *pIUclILStream;
    uint8 numIUclALDebug;
    uint8 *pIUclALDebug;
    uint8 UclSysState;
    const SUclSysStreamCfg *pCfg;
} SUclSysStreamInst;

//Implementation for interface IUclSysStream
Ucl_ReturnType UclSysStream_Impl_IUclSys_Initialize(SUclSysStreamInst *pInst, uint8 InstId);
Ucl_ReturnType UclSysStream_Impl_IUclSys_Shutdown(SUclSysStreamInst *pInst, uint8 InstId);
Ucl_ReturnType UclSysStream_Impl_IUclSys_Send(SUclSysStreamInst *pInst, uint8 InstId, uint8 DLInst, SUclDLMsg *pMsg);
Ucl_ReturnType UclSysStream_Impl_IUclSys_Task(SUclSysStreamInst *pInst, uint8 InstId);

#endif //UCSYS_IMPL_H

