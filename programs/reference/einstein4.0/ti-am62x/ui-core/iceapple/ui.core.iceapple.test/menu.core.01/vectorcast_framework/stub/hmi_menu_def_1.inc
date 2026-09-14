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
#define MENU_BTN_TABLE_ID_1                       0U

#define NB_OF_MENU_INSTANCE                       (1U)
#define HMI_MENU_INSTANCE_0                       (0U)

#define MAIN_MENU_MENU_ITEMS                      (8U)
#define TRIP_INFO_GROUP_MENU_ITEMS                (4U)
#define TRIP_A_MENU_MENU_ITEMS                    (2U)
#define TRIP_B_MENU_MENU_ITEMS                    (2U)
#define DRIVE_ASSIST_GROUP_MENU_ITEMS             (3U)
#define VEHICLE_INFO_GROUP_MENU_ITEMS             (6U)
#define NOTIFICATIONS_GROUP_MENU_ITEMS            (3U)
#define SER_REM_GROUP_MENU_ITEMS                  (1U)
#define NOTIFICATIONS_MENU_ITEMS                  (1U)
#define NAVIGATION_GROUP_MENU_ITEMS               (3U)
#define AC_INFO_GROUP_MENU_ITEMS                  (2U)
#define LAYOUT_GROUP_MENU_ITEMS                   (3U)
#define SETTINGS_GROUP_MENU_ITEMS                 (10U)
#define SETT_ILLUMINATION_MENU_ITEMS              (1U)
#define SETT_UNIT_GROUP_MENU_ITEMS                (4U)
#define DISTANCE_MENU_MENU_ITEMS                  (2U)
#define TEMP_MENU_MENU_ITEMS                      (2U)
#define PRESSURE_MENU_MENU_ITEMS                  (2U)
#define SETT_CLOCK_MENU_MENU_ITEMS                (3U)
#define CLOCK_SET_TIME_MENU_ITEMS                 (5U)
#define CLK_HR_MENU_ITEMS                         (1U)
#define CLK_MIN_MENU_ITEMS                        (1U)
#define CLK_MODE_MENU_ITEMS                       (1U)
#define CLK_SET_MENU_ITEMS                        (1U)
#define CLK_CANCEL_MENU_ITEMS                     (1U)
#define SETT_CALENDAR_MENU_MENU_ITEMS             (5U)
#define CAL_DAY_MENU_ITEMS                        (1U)
#define CAL_MON_MENU_ITEMS                        (1U)
#define CAL_YEAR_MENU_ITEMS                       (1U)
#define CAL_SET_MENU_ITEMS                        (1U)
#define CAL_CANCEL_MENU_ITEMS                     (1U)
#define SETT_ITPMS_RESET_MENU_ITEMS               (2U)
#define SETT_FAV_MENU_SELECT_MENU_ITEMS           (9U)
#define FAV_RESET_MENU_ITEMS                      (2U)
#define SETT_FACTORY_RESET_MENU_ITEMS             (2U)
#define SETT_SERREM_RESET_MENU_ITEMS              (2U)
#define SETT_ABOUT_MENU_ITEMS                     (13U)


#define MENU_TIMER_0S                             (0U)


#define NO_DISP_LINES_1                           (1U)
#define NO_DISP_LINES_2                           (2U)
#define NO_DISP_LINES_3                           (3U)
#define NO_DISP_LINES_4                           (4U)
#define NO_DISP_LINES_5                           (5U)
#define NO_DISP_LINES_6                           (6U)
#define NO_DISP_LINES_8                           (8U)


#define HMI_MAX_MENU_ITEMS                        (SETT_ABOUT_MENU_ITEMS)


#define TOTAL_DYNAMIC_MENU_ITEMS                  (1U)

#define HMI_MENU_ITEM_CONFIG_FEATURE              
#define HMI_MENU_HISTORY_HANDLING_FEATURE         
#define HMI_MENU_CORE_NOTIFY_MENU_FOCUS           
#define HMI_MENU_CORE_CENTRE_FOCUS_LINE           
#define HMI_MENU_TIMEOUT_CONGIF_FEATURE_ENABLE    
#define HMI_MENU_CORE_CONTENT_MENU_ENABLED        
#define HMI_MENU_CORE_FOCUS_DISABLED_FOR_GREYOUT  

#define HMI_MENU_LINE_INCREMENT                   (1U)
#define HMI_MENU_SCROLL_REPEAT_COUNT              (5U)

typedef UINT8 MENU_LIST_ID_T;
#define MAIN_MENU_MENU_ID                         (0U)
#define TRIP_INFO_GROUP_MENU_ID                   (1U)
#define TRIP_A_MENU_MENU_ID                       (2U)
#define TRIP_B_MENU_MENU_ID                       (3U)
#define DRIVE_ASSIST_GROUP_MENU_ID                (4U)
#define VEHICLE_INFO_GROUP_MENU_ID                (5U)
#define NOTIFICATIONS_GROUP_MENU_ID               (6U)
#define SER_REM_GROUP_MENU_ID                     (7U)
#define NOTIFICATIONS_MENU_ID                     (8U)
#define NAVIGATION_GROUP_MENU_ID                  (9U)
#define AC_INFO_GROUP_MENU_ID                     (10U)
#define LAYOUT_GROUP_MENU_ID                      (11U)
#define SETTINGS_GROUP_MENU_ID                    (12U)
#define SETT_ILLUMINATION_MENU_ID                 (13U)
#define SETT_UNIT_GROUP_MENU_ID                   (14U)
#define DISTANCE_MENU_MENU_ID                     (15U)
#define TEMP_MENU_MENU_ID                         (16U)
#define PRESSURE_MENU_MENU_ID                     (17U)
#define SETT_CLOCK_MENU_MENU_ID                   (18U)
#define CLOCK_SET_TIME_MENU_ID                    (19U)
#define CLK_HR_MENU_ID                            (20U)
#define CLK_MIN_MENU_ID                           (21U)
#define CLK_MODE_MENU_ID                          (22U)
#define CLK_SET_MENU_ID                           (23U)
#define CLK_CANCEL_MENU_ID                        (24U)
#define SETT_CALENDAR_MENU_MENU_ID                (25U)
#define CAL_DAY_MENU_ID                           (26U)
#define CAL_MON_MENU_ID                           (27U)
#define CAL_YEAR_MENU_ID                          (28U)
#define CAL_SET_MENU_ID                           (29U)
#define CAL_CANCEL_MENU_ID                        (30U)
#define SETT_ITPMS_RESET_MENU_ID                  (31U)
#define SETT_FAV_MENU_SELECT_MENU_ID              (32U)
#define FAV_RESET_MENU_ID                         (33U)
#define SETT_FACTORY_RESET_MENU_ID                (34U)
#define SETT_SERREM_RESET_MENU_ID                 (35U)
#define SETT_ABOUT_MENU_ID                        (36U)
#define TOTAL_MENU_ID                             (37U)


typedef enum 
{
     MAIN_MENU_MENU_ITEM_TRIP_INFO_GROUP = 0,
     MAIN_MENU_MENU_ITEM_DRIVE_ASSIST_GROUP,
     MAIN_MENU_MENU_ITEM_VEHICLE_INFO_GROUP,
     MAIN_MENU_MENU_ITEM_NOTIFICATIONS_GROUP,
     MAIN_MENU_MENU_ITEM_NAVIGATION_GROUP,
     MAIN_MENU_MENU_ITEM_AC_INFO_GROUP,
     MAIN_MENU_MENU_ITEM_LAYOUT_GROUP,
     MAIN_MENU_MENU_ITEM_SETTINGS_GROUP
}MAIN_MENU_MENU_ITEMS_T;

typedef enum 
{
     TRIP_INFO_GROUP_MENU_ITEM_TRIP_A_MENU = 0,
     TRIP_INFO_GROUP_MENU_ITEM_TRIP_B_MENU,
     TRIP_INFO_GROUP_MENU_ITEM_INSTANT_FE_MENU,
     TRIP_INFO_GROUP_MENU_ITEM_TRIP_INFO_BACK
}TRIP_INFO_GROUP_MENU_ITEMS_T;

typedef enum 
{
     TRIP_A_MENU_MENU_ITEM_TRIP_A_RESET_YES = 0,
     TRIP_A_MENU_MENU_ITEM_TRIP_A_RESET_CANCEL
}TRIP_A_MENU_MENU_ITEMS_T;

typedef enum 
{
     TRIP_B_MENU_MENU_ITEM_TRIP_B_RESET_YES = 0,
     TRIP_B_MENU_MENU_ITEM_TRIP_B_RESET_CANCEL
}TRIP_B_MENU_MENU_ITEMS_T;

typedef enum 
{
     DRIVE_ASSIST_GROUP_MENU_ITEM_DRIVER_ASSIST_MENU = 0,
     DRIVE_ASSIST_GROUP_MENU_ITEM_ATTENTION_ASSIST_MENU,
     DRIVE_ASSIST_GROUP_MENU_ITEM_DRIVE_ASSIST_BACK
}DRIVE_ASSIST_GROUP_MENU_ITEMS_T;

typedef enum 
{
     VEHICLE_INFO_GROUP_MENU_ITEM_DEF_MENU = 0,
     VEHICLE_INFO_GROUP_MENU_ITEM_TPMS_MENU,
     VEHICLE_INFO_GROUP_MENU_ITEM_POW_TORQ_MENU,
     VEHICLE_INFO_GROUP_MENU_ITEM_G_FORCE_MENU,
     VEHICLE_INFO_GROUP_MENU_ITEM_DATE_TIME_MENU,
     VEHICLE_INFO_GROUP_MENU_ITEM_VEHICLE_INFO_BACK
}VEHICLE_INFO_GROUP_MENU_ITEMS_T;

typedef enum 
{
     NOTIFICATIONS_GROUP_MENU_ITEM_SER_REM_GROUP = 0,
     NOTIFICATIONS_GROUP_MENU_ITEM_NOTIFICATIONS,
     NOTIFICATIONS_GROUP_MENU_ITEM_NOTIFICATIONS_BACK
}NOTIFICATIONS_GROUP_MENU_ITEMS_T;

typedef enum 
{
     SER_REM_GROUP_MENU_ITEM_SER_REM_MENU = 0
}SER_REM_GROUP_MENU_ITEMS_T;

typedef enum 
{
     NOTIFICATIONS_MENU_ITEM_NOTIFICATIONS_LIST = 0
}NOTIFICATIONS_MENU_ITEMS_T;

typedef enum 
{
     NAVIGATION_GROUP_MENU_ITEM_TBT_NAVI_MENU = 0,
     NAVIGATION_GROUP_MENU_ITEM_COMPASS_MENU,
     NAVIGATION_GROUP_MENU_ITEM_NAVIGATION_BACK
}NAVIGATION_GROUP_MENU_ITEMS_T;

typedef enum 
{
     AC_INFO_GROUP_MENU_ITEM_AC_INFO_MENU = 0,
     AC_INFO_GROUP_MENU_ITEM_AC_INFO_BACK
}AC_INFO_GROUP_MENU_ITEMS_T;

typedef enum 
{
     LAYOUT_GROUP_MENU_ITEM_DAIL_VIEW = 0,
     LAYOUT_GROUP_MENU_ITEM_DIGITAL_VIEW,
     LAYOUT_GROUP_MENU_ITEM_MINIMAL_VIEW
}LAYOUT_GROUP_MENU_ITEMS_T;

typedef enum 
{
     SETTINGS_GROUP_MENU_ITEM_SETT_ILLUMINATION = 0,
     SETTINGS_GROUP_MENU_ITEM_SETT_UNIT_GROUP,
     SETTINGS_GROUP_MENU_ITEM_SETT_CLOCK_MENU,
     SETTINGS_GROUP_MENU_ITEM_SETT_CALENDAR_MENU,
     SETTINGS_GROUP_MENU_ITEM_SETT_ITPMS_RESET,
     SETTINGS_GROUP_MENU_ITEM_SETT_FAV_MENU_SELECT,
     SETTINGS_GROUP_MENU_ITEM_SETT_FACTORY_RESET,
     SETTINGS_GROUP_MENU_ITEM_SETT_SERREM_RESET,
     SETTINGS_GROUP_MENU_ITEM_SETT_ABOUT,
     SETTINGS_GROUP_MENU_ITEM_SETTINGS_BACK
}SETTINGS_GROUP_MENU_ITEMS_T;

typedef enum 
{
     SETT_ILLUMINATION_MENU_ITEM_ILLUMINATION_MENU = 0
}SETT_ILLUMINATION_MENU_ITEMS_T;

typedef enum 
{
     SETT_UNIT_GROUP_MENU_ITEM_DISTANCE_MENU = 0,
     SETT_UNIT_GROUP_MENU_ITEM_TEMP_MENU,
     SETT_UNIT_GROUP_MENU_ITEM_PRESSURE_MENU,
     SETT_UNIT_GROUP_MENU_ITEM_SETT_UNIT_BACK
}SETT_UNIT_GROUP_MENU_ITEMS_T;

typedef enum 
{
     DISTANCE_MENU_MENU_ITEM_DISTANCE_KM = 0,
     DISTANCE_MENU_MENU_ITEM_DISTANCE_MILES
}DISTANCE_MENU_MENU_ITEMS_T;

typedef enum 
{
     TEMP_MENU_MENU_ITEM_TEMPERATURE_C = 0,
     TEMP_MENU_MENU_ITEM_TEMPERATURE_F
}TEMP_MENU_MENU_ITEMS_T;

typedef enum 
{
     PRESSURE_MENU_MENU_ITEM_PRESSURE_PSI = 0,
     PRESSURE_MENU_MENU_ITEM_PRESSURE_KPA
}PRESSURE_MENU_MENU_ITEMS_T;

typedef enum 
{
     SETT_CLOCK_MENU_MENU_ITEM_CLOCK_MENU_FORMAT = 0,
     SETT_CLOCK_MENU_MENU_ITEM_CLOCK_SET_TIME,
     SETT_CLOCK_MENU_MENU_ITEM_CLOCK_MENU_BACK
}SETT_CLOCK_MENU_MENU_ITEMS_T;

typedef enum 
{
     CLOCK_SET_TIME_MENU_ITEM_CLK_HR = 0,
     CLOCK_SET_TIME_MENU_ITEM_CLK_MIN,
     CLOCK_SET_TIME_MENU_ITEM_CLK_MODE,
     CLOCK_SET_TIME_MENU_ITEM_CLK_SET,
     CLOCK_SET_TIME_MENU_ITEM_CLK_CANCEL
}CLOCK_SET_TIME_MENU_ITEMS_T;

typedef enum 
{
     CLK_HR_MENU_ITEM_CLOCK_HR = 0
}CLK_HR_MENU_ITEMS_T;

typedef enum 
{
     CLK_MIN_MENU_ITEM_CLOCK_MIN = 0
}CLK_MIN_MENU_ITEMS_T;

typedef enum 
{
     CLK_MODE_MENU_ITEM_CLOCK_MODE = 0
}CLK_MODE_MENU_ITEMS_T;

typedef enum 
{
     CLK_SET_MENU_ITEM_CLOCK_YES = 0
}CLK_SET_MENU_ITEMS_T;

typedef enum 
{
     CLK_CANCEL_MENU_ITEM_CLOCK_CANCEL = 0
}CLK_CANCEL_MENU_ITEMS_T;

typedef enum 
{
     SETT_CALENDAR_MENU_MENU_ITEM_CAL_DAY = 0,
     SETT_CALENDAR_MENU_MENU_ITEM_CAL_MON,
     SETT_CALENDAR_MENU_MENU_ITEM_CAL_YEAR,
     SETT_CALENDAR_MENU_MENU_ITEM_CAL_SET,
     SETT_CALENDAR_MENU_MENU_ITEM_CAL_CANCEL
}SETT_CALENDAR_MENU_MENU_ITEMS_T;

typedef enum 
{
     CAL_DAY_MENU_ITEM_DAY = 0
}CAL_DAY_MENU_ITEMS_T;

typedef enum 
{
     CAL_MON_MENU_ITEM_MONTH = 0
}CAL_MON_MENU_ITEMS_T;

typedef enum 
{
     CAL_YEAR_MENU_ITEM_YEAR = 0
}CAL_YEAR_MENU_ITEMS_T;

typedef enum 
{
     CAL_SET_MENU_ITEM_SET = 0
}CAL_SET_MENU_ITEMS_T;

typedef enum 
{
     CAL_CANCEL_MENU_ITEM_CANCEL = 0
}CAL_CANCEL_MENU_ITEMS_T;

typedef enum 
{
     SETT_ITPMS_RESET_MENU_ITEM_TR_YES = 0,
     SETT_ITPMS_RESET_MENU_ITEM_TR_CANCEL
}SETT_ITPMS_RESET_MENU_ITEMS_T;

typedef enum 
{
     SETT_FAV_MENU_SELECT_MENU_ITEM_FAV_TRIP_INFO = 0,
     SETT_FAV_MENU_SELECT_MENU_ITEM_FAV_DRIVE_ASSIST,
     SETT_FAV_MENU_SELECT_MENU_ITEM_FAV_NOTIFICATIONS,
     SETT_FAV_MENU_SELECT_MENU_ITEM_FAV_VEHICLE_INFO,
     SETT_FAV_MENU_SELECT_MENU_ITEM_FAV_NAVIGATION,
     SETT_FAV_MENU_SELECT_MENU_ITEM_FAV_LAYOUT,
     SETT_FAV_MENU_SELECT_MENU_ITEM_FAV_SETTINGS,
     SETT_FAV_MENU_SELECT_MENU_ITEM_FAV_RESET,
     SETT_FAV_MENU_SELECT_MENU_ITEM_FAV_MENU_BACK
}SETT_FAV_MENU_SELECT_MENU_ITEMS_T;

typedef enum 
{
     FAV_RESET_MENU_ITEM_FAV_RESET_YES = 0,
     FAV_RESET_MENU_ITEM_FAV_RESET_CANCEL
}FAV_RESET_MENU_ITEMS_T;

typedef enum 
{
     SETT_FACTORY_RESET_MENU_ITEM_FR_YES = 0,
     SETT_FACTORY_RESET_MENU_ITEM_FR_CANCEL
}SETT_FACTORY_RESET_MENU_ITEMS_T;

typedef enum 
{
     SETT_SERREM_RESET_MENU_ITEM_SRR_YES = 0,
     SETT_SERREM_RESET_MENU_ITEM_SRR_CANCEL
}SETT_SERREM_RESET_MENU_ITEMS_T;

typedef enum 
{
     SETT_ABOUT_MENU_ITEM_ABOUT_SETTINGS_L1 = 0,
     SETT_ABOUT_MENU_ITEM_ABOUT_SETTINGS_L2,
     SETT_ABOUT_MENU_ITEM_ABOUT_SETTINGS_L3,
     SETT_ABOUT_MENU_ITEM_ABOUT_SETTINGS_L4,
     SETT_ABOUT_MENU_ITEM_ABOUT_SETTINGS_L5,
     SETT_ABOUT_MENU_ITEM_ABOUT_SETTINGS_L6,
     SETT_ABOUT_MENU_ITEM_ABOUT_SETTINGS_L7,
     SETT_ABOUT_MENU_ITEM_ABOUT_SETTINGS_L8,
     SETT_ABOUT_MENU_ITEM_ABOUT_SETTINGS_L9,
     SETT_ABOUT_MENU_ITEM_ABOUT_SETTINGS_L10,
     SETT_ABOUT_MENU_ITEM_ABOUT_SETTINGS_L11,
     SETT_ABOUT_MENU_ITEM_ABOUT_SETTINGS_L12,
     SETT_ABOUT_MENU_ITEM_ABOUT_SETTINGS_L13
}SETT_ABOUT_MENU_ITEMS_T;

#endif
