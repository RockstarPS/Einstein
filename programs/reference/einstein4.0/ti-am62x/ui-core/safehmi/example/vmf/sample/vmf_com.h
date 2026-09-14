// ============================================================================
// 
//                      CONFIDENTIAL VISTEON CORPORATION
// 
//  This is an unpublished work of authorship, which contains trade secrets,
//  created in 2017. Visteon Corporation owns all rights to this work and
//  intends to maintain it in confidence to preserve its trade secret status.
//  Visteon Corporation reserves the right, under the copyright laws of the
//  United States or those of any other country that may have jurisdiction,
//  to protect this work as an unpublished work, in the event of an
//  inadvertent or deliberate unauthorized publication. Visteon Corporation
//  also reserves its rights under all copyright laws to protect this work as
//  a published work, when appropriate. Those having access to this work may
//  not copy it, use it, modify it or disclose the information contained in
//  it without the written authorization of Visteon Corporation.
// 
// ============================================================================
// 
//  Name:           vmf_com.h
// 
//  Description:    Listens for VMF request messages
// 
//  Organization:   GUI Software Section, Visteon
// 
// ============================================================================
// 
// ============================================================================
#if (USE_VMF != 0)
#ifndef VMF_RX_H
#define VMF_RX_H

// ============================================================================
//  I N C L U D E   F I L E S
// ============================================================================
#include "nw_os_config.h"
#include "nw_vmf.h"
#include "nw_vmf_trace.h"
#include "ux_safehmi_types.h"

namespace UX_SHMI_PLAYER
{
// ============================================================================
//  T Y P E   D E F I N I T I O N S
// ============================================================================

// 
// vmf_if_get_odometer_unit() return status values
// 
#define SHMI_ODO_UNIT_KM (0)
#define SHMI_ODO_UNIT_MI (1)
// 
// vmf_if_get_show_state() return status values
// 
#define SHMI_HIDE (0)
#define SHMI_SHOW (1)
// 
// vmf_if_get_xyz.... invalid data return value
// 
#define SHMI_IF_DATA_INVALID (0xFFFFFFFF)

//TT Status bit positions (vmf_if_get_tt_status)
#define SHMI_IF_TT_LEFTTURN   (0x00000001)
#define SHMI_IF_TT_RIGHTTURN  (0x00000002)
#define SHMI_IF_TT_ABS        (0x00000004)
#define SHMI_IF_TT_BRAKE      (0x00000008)
#define SHMI_IF_TT_PS         (0x00000010)
#define SHMI_IF_TT_AIRBAG     (0x00000020)
#define SHMI_IF_TT_HAZARD     (0x00000040)
#define SHMI_IF_TT_HIGHBEAM   (0x00000080)
#define SHMI_IF_TT_FOGLAMP    (0x00000100)
#define SHMI_IF_TT_ESC        (0x00000200)
#define SHMI_IF_TT_MASTERLAMP (0x00000400)
#define SHMI_IF_TT_RESERVED   (0x80000000)   /*USed to indicate invalid status*/

// ============================================================================
//  E N T R Y   P O I N T S
// ============================================================================
int vmf_rx_open(void);
void vmf_rx_close(void);
int vmf_receiver(void);
// 
// Status inspect functions
// 
uint32_t vmf_if_get_tt_status(void);
uint32_t vmf_if_get_gear_selection(void);
uint32_t vmf_if_get_odometer_unit(void);
uint32_t vmf_if_get_odometer(void);
uint32_t vmf_if_get_rpm(void);
uint32_t vmf_if_get_speed(void);
uint32_t vmf_if_get_alive_count(void);
uint32_t vmf_if_get_show_state(void);
uint32_t vmf_if_get_dte(void);
uint32_t vmf_if_get_dist2destination(void);
int16_t vmf_if_get_oat(void);
int16_t vmf_if_get_ect(void);
uint32_t vmf_if_get_fuel_percentage(void);

// ============================================================================
//  D A T A   A C C E S S   S E R V I C E S
// ============================================================================

}
// ============================================================================
// 
// ============================================================================
//  C M S    R E V I S I O N    N O T E S
// ============================================================================
// 
//  For each change to this file, be sure to record:
//  1.  Who made the change and when the change was made.
//  2.  Why the change was made and the intended result.
// 
//  CMS Rev #        Date         By
//  CMS Rev X.X      mm/dd/yy     CDSID
// 
// ============================================================================
// 
//  CMS Rev 1.0      15-Jun-2017  EMANOJ1
//  Creation.
// 
// ============================================================================

// end of file ================================================================
#endif
#endif
