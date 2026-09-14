/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2017. Visteon Corporation owns all rights to           *
* this work and intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right,           *
* under the copyright laws of the United States or those of any              *
* other country that may have jurisdiction, to protect this work             *
* as an unpublished work, in the event of an inadvertent or                  *
* deliberate unauthorized publication. Visteon Corporation also              *
* reserves its rights under all copyright laws to protect this               *
* work as a published work, when appropriate. Those having access            *
* to this work may not copy it, use it, modify it or disclose the            *
* information contained in it without the written authorization              *
* of Visteon Corporation.                                                    *
*                                                                            *
******************************************************************************/
/*****************************************************************************
*  File Name         :  WdgM_Types.h                                         *
*  Module Short Name :  WdgM_Types                                           *
*  Description       :  This file contains declations of the Autosar WDG     *
*                       Manager types and macros                             *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  GHS Multi                                              *
* Target Hardware  :  Platform Independent                                   *
*                                                                            *
******************************************************************************/
#ifndef WDGM_TYPES_H
#define WDGM_TYPES_H

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/

#define WDGM_OFF_MODE      0U /*OFF Mode */
#define WDGM_SLOW_MODE     1U /* SLOW Mode */
#define WDGM_FAST_MODE     2U /* FAST Mode */

/* OK */
#  ifndef WDGM_LOCAL_STATUS_OK
#   define WDGM_LOCAL_STATUS_OK (0U)
#  endif
/* FAILED */
#  ifndef WDGM_LOCAL_STATUS_FAILED
#   define WDGM_LOCAL_STATUS_FAILED (1U)
#  endif
/* EXPIRED */
#  ifndef WDGM_LOCAL_STATUS_EXPIRED
#   define WDGM_LOCAL_STATUS_EXPIRED (2U)
#  endif
/* DEACTIVATED */
#  ifndef WDGM_LOCAL_STATUS_DEACTIVATED
#   define WDGM_LOCAL_STATUS_DEACTIVATED (4U)
#  endif


/* OK */
#  ifndef WDGM_GLOBAL_STATUS_OK
#   define WDGM_GLOBAL_STATUS_OK (0U)
#  endif
/* FAILED */
#  ifndef WDGM_GLOBAL_STATUS_FAILED
#   define WDGM_GLOBAL_STATUS_FAILED (1U)
#  endif
/* EXPIRED */
#  ifndef WDGM_GLOBAL_STATUS_EXPIRED
#   define WDGM_GLOBAL_STATUS_EXPIRED (2U)
#  endif
/* STOPEED */
#  ifndef WDGM_GLOBAL_STATUS_STOPPED
#   define WDGM_GLOBAL_STATUS_STOPPED (3U)
#  endif
/* DEACTIVATED */
#  ifndef WDGM_GLOBAL_STATUS_DEACTIVATED
#   define WDGM_GLOBAL_STATUS_DEACTIVATED (4U)
#  endif


#define WDGM_INSTANCE_ID                    0x00U
/* Api id */
#define WDGM_INIT_API                       0x00U
#define WDGM_DEINIT_API                     0x01U
#define WDGM_VERSIONINFO_API                0x02U
#define WDGM_SETMODE_API                    0x03U
#define WDGM_GETMODE_API                    0x0BU
#define WDGM_CHECKPOINTREACHED_API          0x0EU
#define WDGM_GETLOCALSTATUS_API             0x0CU
#define WDGM_GETGLOBALSTATUS_API            0x0DU
#define WDGM_PERFORMRESET_API               0x0FU
#define WDGM_GETFIRSTEXPIREDSEID_API        0x10U
#define WDGM_MAINFUNCTION_API               0x08U

/* Error Id */

#define WDGM_E_NO_INIT						0x10U
#define WDGM_E_NO_DEINIT                    0X1AU
#define WDGM_E_PARAM_CONFIG					0x11U
#define WDGM_E_PARAM_MODE					0x12U
#define WDGM_E_PARAM_SEID					0x13U
#define WDGM_E_INV_POINTER					0x14U
#define WDGM_E_DISABLE_NOT_ALLOWED			0x15U
#define WDGM_E_CPID							0x16U
#define WDGM_E_DEPRECATED                   0x17U
#define WDGM_E_AMBIGIOUS					0x18U
#define WDGM_E_SEDEACTIVATED				0x19U

#define WDGM_NUMOF_MODES   3u 

#endif
/*============================================================================
**============================================================================
** R E V I S I O N    N O T E S
**============================================================================
**
** For each change to this file, be sure to record:
** 1.  Who made the change and when the change was made.
** 2.  Why the change was made and the intended result.
**
**===========================================================================*/
/*---------------------------------------------------------------------------
Date               : 21-Aug-2015
CDSID              : ssebast1
Traceability       : RTC #396019
Change Description : Initial Framework version of WdgM
-----------------------------------------------------------------------------*/
/* end of file =============================================================*/
