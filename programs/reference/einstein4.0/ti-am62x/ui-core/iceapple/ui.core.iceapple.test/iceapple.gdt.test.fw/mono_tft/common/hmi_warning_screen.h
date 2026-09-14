/*============================================================================
**
**                     CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2010. Visteon Corporation owns all rights to this work and
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
** Name:           hmi_warning_screen.h
**
** Description:
**
** Organization:   Driver Information Software Section,
**
**============================================================================
**
**==========================================================================*/
#include "system.h"
#include "hmi_SIF.h"
#include "hmi_gfx_mgr02_layout.h"
#include "hmi_msgPresentation.inc"

typedef struct
{
    UINT8                  Header;
    LANG_SID_T             Header_SID;
    UINT8                  Line1_Text_ID;
    LANG_SID_T             Line_1_SID;
    UINT8                  Line_2_Text_ID;
    LANG_SID_T             Line_2_SID;
    UINT8                  Msg_Category;
    UINT8                  Line_3_Text_ID;
    LANG_SID_T             Line_3_SID;
    POPUP_ID               Pop_ID;
}MSG_CONFIG_TABLE_T;

extern const MSG_CONFIG_TABLE_T msg_config_table[];

SIF_STATUS hmi_msg_warn_get_status(UINT8 *Data, UINT8 Qualifier);
SIF_STATUS hmi_msg_app_wrn_notify_status_cb(UINT8 *Data, UINT8 Qualifier);

