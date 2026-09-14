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
/// @ingroup UclSys
/// Ucl System Implementation for Ucl Stack. APIs in this file are not to be called directly by the users
///
///---------------------------------------------------------------------------------------------------------------------
#ifndef UCSYS_IMPL_H
#define UCSYS_IMPL_H

#include "Ucl_Types.h"
#include "UclDL_Types.h"

///
/// @brief Configuration data for UclSys_Impl. \n
///
/// The SUclSysCfg structure defines the constant configuration data for UclDL_Impl class.
///
typedef struct SUclSysCfg_t
{
    uint8 dummy;
} SUclSysCfg;

///
/// @brief Private instance data for UclSys_Impl. \n
/// @ingroup UclSys
///
/// The SUclSysInst structure defines the private instance data for UclSys_Impl class.
///
typedef struct SUclSysInst_t
{
    uint8 numIUclALOs;
    uint8 *pIUclALOs;
    uint8 numIUclILSched;
    uint8 *pIUclILSched;
    uint8 numIUclILRouter;
    uint8 *pIUclILRouter;
    uint8 numIUclALDebug;
    uint8 *pIUclALDebug;

    uint8 UclSysState;
    const SUclSysCfg *pCfg;
} SUclSysInst;

//Implementation for interface IUclSys
Ucl_ReturnType UclSys_Impl_IUclSys_Initialize(SUclSysInst *pInst, uint8 InstId);
Ucl_ReturnType UclSys_Impl_IUclSys_Shutdown(SUclSysInst *pInst, uint8 InstId);
Ucl_ReturnType UclSys_Impl_IUclSys_Task(SUclSysInst *pInst, uint8 InstId);
Ucl_ReturnType UclSys_Impl_IUclSys_Send(SUclSysInst *pInst, uint8 InstId, uint8 DLInst, SUclDLMsg *pMsg);

#endif //UCSYS_IMPL_H
