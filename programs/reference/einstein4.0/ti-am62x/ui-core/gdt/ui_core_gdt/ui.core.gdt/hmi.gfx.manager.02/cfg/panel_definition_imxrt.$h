/*============================================================================
**
**                     CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2021. Visteon Corporation owns all rights to this work and
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
** Name:           panel_definition_imxrt.h
**
** Description:    Template Configuration file for the graphics manager.
**                 Take a copy of all the xyz.$h to your application
**                 folder structure and rename it as xyz.h (remove the $)
**                 And then make necessary adjutments to the confurations
**                 explained below to suit your need.
**
**============================================================================
**
**==========================================================================*/
#ifndef PANEL_DEFINITION_IMXRT_H
#define PANEL_DEFINITION_IMXRT_H

#ifdef __cplusplus
extern "C"
{
#endif

/*****************************************************************************/
/* Local variable definitions ('static')                                     */
/*****************************************************************************/

#define DEMO_LCDIF LCDIFV2
#define DEMO_CORE_ID 0

#define DEMO_PANEL_WIDTH  (720)
#define DEMO_PANEL_HEIGHT (1280)    

#define DEMO_BUFFER_WIDTH  (DEMO_PANEL_WIDTH)
#define DEMO_BUFFER_HEIGHT (DEMO_PANEL_HEIGHT)

/* Where the frame buffer is shown in the screen. */
#define DEMO_BUFFER_START_X 0U
#define DEMO_BUFFER_START_Y 0U

#define DEMO_HSW 8
#define DEMO_HFP 32
#define DEMO_HBP 32
#define DEMO_VSW 2
#define DEMO_VFP 16
#define DEMO_VBP 14
#define DEMO_POL_FLAGS  (kLCDIFV2_DataEnableActiveHigh | kLCDIFV2_VsyncActiveLow | kLCDIFV2_HsyncActiveLow | kLCDIFV2_DriveDataOnFallingClkEdge)

#define DEMO_ELCDIF_DATABUSBIT   kELCDIF_DataBus24Bit	

#ifdef __cplusplus
}
#endif

#endif /* PANEL_DEFINITION_IMXRT_H */
