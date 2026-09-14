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
#ifndef GFXDRV2D_S6J3200DRV_H
#define GFXDRV2D_S6J3200DRV_H

void            GfxDrv2D_S6J3200Drv_Init(void);
void            GfxDrv2D_S6J3200Drv_Deinit(void);
Std_ReturnType  GfxDrv2D_S6J3200Drv_Activate(void);
Std_ReturnType  GfxDrv2D_S6J3200Drv_Deactivate(void);
#ifndef GDTCDD_RENDERTASK_ALIGN_VSYNC
void            GfxDrv2D_S6J3200Drv_OnStartRender(void);
#endif
uint64          Timer_GetTickCountUs(void);

#endif // GFXDRV2D_S6J3200DRV_H
