/*****************************************************************************/ 
/* Copyright Statement                                                       */ 
/* CONFIDENTIAL - VISTEON CORPORATION                                        */ 
/* This is an unpublished work, which contains trade secrets, created in     */ 
/* 2012. Visteon Corporation owns all rights to this work and intends        */ 
/* to maintain it in confidence to preserve its trade secret status. Visteon */ 
/* Corporation reserves the right, under the copyright laws of the United    */ 
/* States or those of any other country that may have jurisdiction, to       */ 
/* protect this work as an unpublished copyright work in the event of an     */ 
/* inadvertent or deliberate unauthorized publication. Visteon Corporation   */ 
/* also reserves its rights under the copyright laws to protect this work    */ 
/* as a published work, when appropriate. Those having access to this work   */ 
/* may not copy it, use it or disclose the information contained in it       */ 
/* without the written authorization of Visteon Corporation.                 */ 
/*****************************************************************************/ 
/**
 * @file     ui_warning_interface.h
 * @brief    GUI Subsystem - Warning Interface
 * @details  This header file provides interfaces to warnings/message features
 * @author   ABALAJI
 */

#ifndef UI_WARNING_INTERFACE__H
#define UI_WARNING_INTERFACE__H

/*============================================================================
 * I N C L U D E   F I L E S
 *==========================================================================*/
//#include "ui_base.h"

/*============================================================================
 * T Y P E   D E F I N I T I O N S
 *==========================================================================*/

/** 
 * @name "Application specific" master warning list
 */
//@{
#include "di_warnings_interface.h"
/*#include "di_indicators_interface.h"*/
//@}

/** 
 * @name "Application specific" warning indicators/telltales (in display)
 */
//@{
//@}

/** 
 * @name Warning general status
 */
//@{
typedef enum
{
  UI_WARNING_STATUS_OFF                  =   0,
  UI_WARNING_STATUS_ON                   =   1,
  UI_WARNING_STATUS_UNKNOWN              =   2   /**< unavailable or configuration invalid etc */
} UI_WARNING_STATUS_T;
//@}

/** 
 * @name Warning special events
 */
//@{
typedef enum
{
  UI_WARNING_EVENT_NONE                  =   0,
  UI_WARNING_EVENT_RETRIGGER             =   1,  /**< restart when warning is already active */
  UI_WARNING_EVENT_FORCED                =   2   /**< force start already timed out or acknowledged warning */
} UI_WARNING_EVENT_T;
//@}


/** 
 * @name Warning's Display States
 */
//@{
typedef enum
{
  UI_WARNING_STATE_NONE                  =   0,  /**< none state */
  UI_WARNING_STATE_ACKNOWLEDED           =   1,  /**< warning has been acknowledged */
  UI_WARNING_STATE_TIMEOUT               =   2,  /**< warning has timed-out */
  UI_WARNING_STATE_HIDDEN                =   3,  /**< warning has been hidden by another */
  UI_WARNING_STATE_SHOW                  =   4,  /**< warning has been displayed */
  UI_WARNING_STATE_ACTIVE                =   5,  /**< warning has been activated by warnings manager */
  UI_WARNING_STATE_INACTIVE              =   6   /**< warning has been de-activated by warnings manager */
} UI_WARNING_STATE_T;
//@}

/** 
 * @name Warning "application specific" chime definitions
 */
//@{
typedef enum
{
  UI_WARNING_CHIME_NONE                  =   0,
  UI_WARNING_CHIME_ACTIVE                =   1
} UI_WARNING_CHIME_T;
//@}

/** 
 * @name Warning "application specific" telltale definitions
 */
//@{
typedef enum
{
  UI_WARNING_TELLTALE_NONE               =   0,
  UI_WARNING_TELLTALE_AMBER              =   1,
  UI_WARNING_TELLTALE_RED                =   2
} UI_WARNING_TELLTALE_T;
//@}

/** 
 * @name Warning "application specific" payload status; dynamic range of UINT16 values are allowed
 */
//@{

/* LDW status */
#define  UI_LDW_OFF                     0x1310
#define  UI_LDW_WARNING_ON              0x1311
#define  UI_LDW_INDICATOR_ON            0x1312

/* BSW status */
#define  UI_BSW_OFF                     0x1315
#define  UI_BSW_WARNING_ON              0x1316
#define  UI_BSW_INDICATOR_ON            0x1317

/* FCW status */
#define  UI_FCW_OFF                     0x1320
#define  UI_FCW_WARNING_ON              0x1321
#define  UI_FCW_INDICATOR_ON            0x1322

/* Leading Vehicle status */
#define  UI_LV_OFF                      0x1325
#define  UI_LV_INDICATOR_ON             0x1326
#define  UI_LV_WARNING_ON               0x1327
#define  UI_CURVE_INDICATOR_ON          0x1328
#define  UI_CURVE_WARNING_ON            0x1329
#define  UI_LV_SYMBOL_1                 0x132A
#define  UI_LV_SYMBOL_2                 0x132B

/* Distance Indicator status */
#define  UI_DISTANCE_OFF                0x1330
#define  UI_DISTANCE_SHORT              0x1331
#define  UI_DISTANCE_MIDDLE             0x1332
#define  UI_DISTANCE_LONG               0x1333

/* Cruise icon status */
#define  UI_CC_ICON_OFF                 0x1340
#define  UI_CC_ICC_ON                   0x1341
#define  UI_CC_ICC_ACTIVE               0x1342
#define  UI_CC_ICC_FAULT                0x1343
#define  UI_CC_ASCD_ON                  0x1344
#define  UI_CC_ASCD_ACTIVE              0x1345
#define  UI_CC_ASCD_FAULT               0x1346
#define  UI_CC_SL_ON                    0x1347
#define  UI_CC_SL_ACTIVE                0x1348
#define  UI_CC_SL_FAULT                 0x1349

/* DAS Driver_Attention_Level CANID: 4CC */
#define  UI_DA_LEVEL_NODISP							0
#define  UI_DA_LEVEL_SYSOFF							1
#define  UI_DA_LEVEL_1RED							  2
#define  UI_DA_LEVEL_2YELLOW						3
#define  UI_DA_LEVEL_3YELLOW						4
#define  UI_DA_LEVEL_4WHITE							5
#define  UI_DA_LEVEL_5WHITE							6
#define  UI_DA_LEVEL_6WHITE							7
#define  UI_DA_LEVEL_7WHITE							8
#define  UI_DA_LEVEL_8WHITE							9
#define  UI_DA_LEVEL_STANDBY						15
#define  UI_DA_LEVEL_SYSMALFUN					16


/* BRAKE/Without BRAKE Push Engine Start warning display */
#define  UI_BRAKE_PUSH_ENG_START	    	0
#define  UI_WO_BRAKE_PUSH_ENG_START     1

/* Door open status warning display */
#define  UI_FRONT_LEFT_DOOR_OPEN					BIT0
#define  UI_FRONT_RIGHT_DOOR_OPEN				  BIT1
#define  UI_REAR_LEFT_DOOR_OPEN     	   	BIT2
#define  UI_REAR_RIGHT_DOOR_OPEN    	 	  BIT3
#define  UI_BACK_TRUNK_DOOR_OPEN    	 	  BIT4
#define  UI_BIT5_TRUNK_SWITCH_MASK		 	BIT5

/* Ambient Eco indicator */
typedef enum
{
  UI_INDICATOR_AMBIENT_OFF	=	0,
  UI_INDICATOR_AMBIENT_ON	=	1,
  UI_INDICATOR_AMBIENT_BLINK	=	2
  
}UI_IND_AMBIENT_T;

/*============================================================================
 *
 *============================================================================
 * C M S    R E V I S I O N    N O T E S
 *============================================================================
 *
 * For each change to this file, be sure to record:
 * 1.  Who made the change and when the change was made.
 * 2.  Why the change was made and the intended result.
 *
 * CMS Rev #        Date         By
 * CMS Rev X.X      mm/dd/yy     CDSID
 *
 *============================================================================
 * CMS Rev 1.2      11-July-2014    jmunisam
 * Description : Added bit Mask for Trunk Switch
 * CMS Rev 1.1      10-Jan-2013    ABALAJI
 * ui_set_warning_status() is updated with chime and telltale parameters
 * CMS Rev 1.0      21-Sep-2012    ABALAJI
 * Draft version
 *
 *==========================================================================*/


#endif // UI_WARNING_INTERFACE__H

