/*============================================================================
**
**                     CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2008. Visteon Corporation owns all rights to this work and
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
** Name:           hmi_simulation_tick.h
**
** Description:    This file contains the public interface definition
**                 for the hmi simulation framework.
**
** Organization:   Driver Information Software Section,
**                 DI Core Engineering Department
**
**============================================================================
**
**==========================================================================*/
#ifndef HMI_SIMULATION_TICK_H
#define HMI_SIMULATION_TICK_H

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include <windows.h>
#include "system.h"
#include "hmi_simulation_tick.cfg"


/*============================================================================
** T Y P E   D E F I N I T I O N S
**==========================================================================*/

#if HMI_SIMUL_TICK_MSEC == 0
  #error "HMI_SIMUL_TICK_MSEC cannot be 0"
#endif

/*============================================================================
** E N T R Y   P O I N T S
**==========================================================================*/

typedef struct
{
   UINT16 const * src_adr;
   UINT16 * dst_adr;
   UINT32   count;
}T_DMAC_TRANS;

typedef enum
{
   GLS_1BPP_VERTICAL,
   GLS_RGB565,
   GLS_BGR565,
   GLS_ARGB4444,
   GLS_ABGR4444,
   GLS_ARGB8888
}lcdtype;

/*
** gls_init          - call this on startup
** gls_update_lcd    - call this when ever the LCD needs to be refreshed
**                     calling not required if HMI_SIM_UPDATE_LCD_PERIODIC
**                     is defined.
** SimMainThreadProc - Create SimMainThreadProc thread on start up if
**                     HMI_SIM_USE_GLUT is defined. Otherwise no need
**                     to create this thread.
*/
extern void gls_init(int zoom);
extern void gls_update_lcd(void);
extern void DestroyLcdWindow(void);
void glib_Dmac_Trans(UINT8 ch, T_DMAC_TRANS *fl_dma_tfr_S);
void glib_Dmac_Trans_FixedSource(UINT8 ch, T_DMAC_TRANS *fl_dma_tfr_S);
int  gls_set_layer_alpha(int handle, unsigned char layer_alpha);
int  gls_add_layer(unsigned char layer_alpha, unsigned int width, unsigned int height, unsigned char zoom);
int  gls_set_layer_xy(int handle, unsigned int x, unsigned int y);
int  gls_set_pixel_xy(int handle, unsigned int x, unsigned int y);
int  gls_fb_write(int handle, unsigned color);
int  gls_fb_write_xy(int handle, unsigned int x, unsigned int y, unsigned color);

/*============================================================================
** D A T A   A C C E S S   S E R V I C E S
**==========================================================================*/

/*
** Incremated every HMI_SIMUL_TICK_MSEC
*/
extern UINT16 l_system_tick_U16;

/*============================================================================
**
**============================================================================
** C M S    R E V I S I O N    N O T E S
**============================================================================
**
** For each change to this file, be sure to record:
** 1.  Who made the change and when the change was made.
** 2.  Why the change was made and the intended result.
**
** CMS Rev #        Date         By
** CMS Rev X.X      mm/dd/yy     CDSID
**
**============================================================================
**
** Rev 1.0          14-Sep-2009  EMANOJ1
** Initial revision.
**
**==========================================================================*/

/* end of file =============================================================*/
#endif
