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
#ifndef TFTDRV_H
#define TFTDRV_H



#define cFinished       ((uint8)TRUE)
#define cNotFinished    ((uint8)FALSE)

void TftDrv_Init(void);
void TftDrv_Deinit(void);
boolean  TftDrv_preActivate(void);
boolean  TftDrv_postActivate(void);
boolean TftDrv_DeActivate_Step1(void);
boolean TftDrv_DeActivate_Step2(void);

#endif // TFTDRV_H
