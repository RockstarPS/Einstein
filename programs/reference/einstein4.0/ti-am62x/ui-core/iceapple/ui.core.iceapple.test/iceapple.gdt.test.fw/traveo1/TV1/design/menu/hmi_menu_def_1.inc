/*============================================================================
**
**                     CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2012. Visteon Corporation owns all rights to this work and
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
** Name:           hmi_menu_def_1.inc
**
** Description:    File contains Menu Definitions.
**
** Organization:   Driver Information Software Section,
**                 Visteon
**
**============================================================================
**
**==========================================================================*/


#ifndef HMI_MENU_DEF_1_INC
#define HMI_MENU_DEF_1_INC

#define NULL_PARAM                                (0)

/* Release label major version 4 */
/* Release label minor version 30 */
#define HMI_MENU_CORE_TOOL_LABEL                  "MENU_TOOL_LABEL::ss-UI-FRAMEWORKS-ICEAPPLE-4.30"
#define HMI_MENU_CORE_TOOL_MAJOR_VERSION          4
#define HMI_MENU_CORE_TOOL_MINOR_VERSION          30
#define HMI_MENU_CORE_TOOL_VERSION                ((HMI_MENU_CORE_TOOL_MAJOR_VERSION * 100) + HMI_MENU_CORE_TOOL_MINOR_VERSION)

#define HMI_MENU_ACTION_IN_ANIM_COUNT             4U

#define HMI_MENU_TABLE_COUNT                      1U
#define MENU_BTN_TABLE_DEFAULT                    0U

#define NB_OF_MENU_INSTANCE                       (2U)
#define HMI_MENU_INSTANCE_0                       (0U)
#define HMI_MENU_INSTANCE_1                       (1U)

#define TRIPCOMP_ECO_GROUP_MENU_ITEMS             (1U)
#define ROOT_MENU_ITEMS                           (1U)


#define MENU_TIMER_0S                             (0U)


#define NO_DISP_LINES_1                           (1U)


#define HMI_MAX_MENU_ITEMS                        (TRIPCOMP_ECO_GROUP_MENU_ITEMS)


#define TOTAL_DYNAMIC_MENU_ITEMS                  (1U)

#define HMI_MENU_ITEM_CONFIG_FEATURE              
#define HMI_MENU_HISTORY_HANDLING_FEATURE         
#define HMI_MENU_CORE_CENTRE_FOCUS_LINE           
#define HMI_MENU_CORE_CONTENT_MENU_ENABLED        
#define HMI_MENU_CORE_FOCUS_DISABLED_FOR_GREYOUT  
#define HMI_MENU_ITEM_CONFIG_WITH_APP_INDEX_FEATURE

#define HMI_MENU_LINE_INCREMENT                   (1U)
#define HMI_MENU_SCROLL_REPEAT_COUNT              (5U)

typedef UINT8 MENU_LIST_ID_T;
#define TRIPCOMP_ECO_GROUP_MENU_ID                (0U)
#define ROOT_MENU_ID                              (1U)
#define TOTAL_MENU_ID                             (2U)


typedef enum 
{
     TRIPCOMP_ECO_GROUP_MENU_ITEM_DC_STANDARD_TRIP = 0
}TRIPCOMP_ECO_GROUP_MENU_ITEMS_T;

typedef enum 
{
     ROOT_MENU_ITEM_ROOT_TRIPCOMP_ECO_GROUP = 0
}ROOT_MENU_ITEMS_T;

#endif
