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
** Name:           hmi_gfx_dcu_sim_w32.h
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
#ifndef HMI_GFX_DCU_SIM_W32_H
#define HMI_GFX_DCU_SIM_W32_H

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include "system.h"
//#include "hmi_gfx_mgr02_reg.h"
#include "hmi_gfx_dcu_sim_w32.cfg"
/*============================================================================
** T Y P E   D E F I N I T I O N S
**==========================================================================*/

#if HMI_SIMUL_TICK_MSEC == 0
  #error "HMI_SIMUL_TICK_MSEC cannot be 0"
#endif

#if HMI_SIMUL_DCU_TICK_RATE == 0
  #error "HMI_SIMUL_DCU_TICK_RATE cannot be 0"
#endif

/*============================================================================
** E N T R Y   P O I N T S
**==========================================================================*/

/*
** gls_init          - call this on startup
** gls_update_lcd    - call this when ever the LCD needs to be refreshed
**                     calling not required if HMI_SIM_UPDATE_LCD_PERIODIC
**                     is defined.
** SimMainThreadProc - Create SimMainThreadProc thread on start up if
**                     HMI_SIM_USE_GLUT is defined. Otherwise no need
**                     to create this thread.
*/
extern void hmi_gfx02_dcu_sim_init(int zoom);
extern void hmi_gfx02_dcu_sim_update(void);
extern void hmi_gfx02_dcu_sim_stop(void);
PBITMAPINFO CreateBitmapInfoStruct(HWND , HBITMAP );
void CreateBMPFile(HWND , LPTSTR , PBITMAPINFO , 
                  HBITMAP , HDC ); 

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
