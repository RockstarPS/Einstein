/*============================================================================
**
**                     CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2016. Visteon Corporation owns all rights to this work and
** intends to maintain it in confidence to preserve its trade secret status.
** Visteon Corporation reserves the right, under the copyright laws of the
** United States or those of any other country that may have jurisdiction,
** to protect this work as an unpublished work, in the event of an
** inadvertent or deliberate unauthorized publication. Visteon Corporation
** also reserves its rights under all copyright laws to protect this work as
** a published work, when appropriate. Those having access to this work may
** not copy it, use it, modify it or disclose the information contained in
** it without the written authorization of Visteon Corporation.
**
**============================================================================
**
** Name:           Ctrl_warning_data.h
**
** Description:    Data Pool Declarations for the Ctrl_warning
**
** Organization:   Driver Information Software Section,
**           
**==========================================================================*/


/* Data pool declarations of the Ctrl_warning.h */
typedef struct
{
  PayloadArr_u8_8 WarningPayloadRecd;
} WarningPayload_Type;

#define PayloadArr_u8_8 PayloadArr_U8_8;

static ExtWarningData l_ArbtnWarnData_S[TotalNumOfWarnings];
static WarningDisplayedStatus l_DisplydWrnSts_E[TotalNumOfWarnings];
static WarningPayload_Type l_DisplayedPayload_A[TotalNumOfWarnings];
static uint8 l_ExtdPayoadCalld_u8[TotalNumOfWarnings];
static WarningDataS l_Dummy_S[TotalNumOfWarnings];
static uint8 l_MasterWarning_Lamp_Red[TotalNumOfWarnings];
static uint8 l_MasterWarning_Lamp_Yellow[TotalNumOfWarnings];





/*
 * File trailer for generated code.
 *
 * [EOF]
 */
