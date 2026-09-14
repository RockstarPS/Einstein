/****************************************************************
*              CONFIDENTIAL VISTEON CORPORATION
*
* This is an unpublished work of authorship, which contains trade secrets,
* created in 2012. Visteon Corporation owns all rights to this work and
* intends to maintain it in confidence to preserve its trade secret status.
* Visteon Corporation reserves the right, under the copyright laws of the
* United States or those of any other country that may have  jurisdiction,
* to protect this work as an unpublished work, in the event of an
* inadvertent or deliberate unauthorized publication. Visteon Corporation
* also reserves its rights under all copyright laws to protect this work as
* a published work, when appropriate. Those having access to this work may
* not copy it, use it, modify it or disclose the information contained in
* it without the written authorization of Visteon Corporation
*
****************************************************************/

#ifndef LINIF_PAR_CFG_C
#define LINIF_PAR_CFG_C

#include "LinIf_Par_Cfg.h"
#include "PduR_LinIf.h"
#include "PduR_Cfg.h"

/*****************************************************************************
* File Name         :  LinIf_Par_Cfg.c                                       *
* Module Short Name :  LinIf                                                 *
* Description       :  contains the configuration table of the respective layer.*
*                                                                            *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  GHS                                                    *
* Target Hardware  :  Turing A                                               *
*                                                                            *
*****************************************************************************/

#ifndef NULL
#define NULL            (0)
#endif

/*----------------------------------------------------------------------------------------------------------------------*/
/*                                                                                                                      */
/* NAME:   LINIF_User_Frame_List           */  
/*                 */
/* TYPE:   LinIf_FrameType        */
/*                                                                                                                      */
/* DESCRIPTION:  Configurations for the LIN Frames list                                                                */
/*----------------------------------------------------------------------------------------------------------------------*/

LinIf_FrameType LINIF_User_App_Frame_List[6] = {
    /* Index    ChecksumType     FrameType         Dl         PID       PduId                                                       FixedFrameSdu          Direction                  */
  { /*     0 */ LINIF_ENHANCED, UNCONDITIONAL,     8U,        0x30U,     PduRConf_PduRDestPdu_DST_Lin_PT_LIN_IPC_A_45618847,            NULL,               LinIfTxPdu   },
  { /*     0 */ LINIF_ENHANCED, UNCONDITIONAL,     8U,        0x2FU,     PduRConf_PduRDestPdu_DST_Lin_PT_LIN_IPC_B_45618847,            NULL,               LinIfTxPdu   },  
  { /*     0 */ LINIF_ENHANCED, UNCONDITIONAL,     8U,        0x2EU,     PduRConf_PduRDestPdu_DST_Lin_PT_LIN_IPC_C_45618847,            NULL,               LinIfTxPdu   },  
  { /*     0 */ LINIF_ENHANCED, UNCONDITIONAL,     8U,        0x19U,     PduRConf_PduRDestPdu_DST_Lin_PT_LIN_IPC_D_45618847,            NULL,               LinIfTxPdu   }, 
  { /*     1 */ LINIF_ENHANCED, EVENT_TRIGGERED,   8U,        0x0DU,     0x00U,                                                         NULL,               LinIfRxPdu   },
  { /*     2 */ LINIF_ENHANCED, SPORADIC,          8U,        0x0EU,     0x00U,                                                         NULL,               LinIfTxPdu   } 
};



LinIf_FrameType LINIF_User_Collison_Frame_List[3] = {
    /* Index    ChecksumType     FrameType      Dl         PID       RxTargetPduId    FixedFrameSdu       Direction                  */
  { /*     0 */ LINIF_ENHANCED, UNCONDITIONAL, 8U,        0x01U,     0x00U,            NULL,               LinIfRxPdu   },  
  { /*     1 */ LINIF_ENHANCED, UNCONDITIONAL, 8U,        0x02U,     0x00U,            NULL,               LinIfRxPdu   },
  { /*     2 */ LINIF_ENHANCED, UNCONDITIONAL, 8U,        0x03U,     0x00U,            NULL,               LinIfRxPdu   }
};



LinIf_FrameType LINIF_User_SporadicFrameList[3] = {
    /* Index    ChecksumType     FrameType      Dl         PID       RxTargetPduId    FixedFrameSdu       Direction                  */
  { /*     0 */ LINIF_ENHANCED, UNCONDITIONAL, 8U,        0x04U,     0x00U,            NULL,               LinIfRxPdu   },  
  { /*     1 */ LINIF_ENHANCED, UNCONDITIONAL, 8U,        0x05U,     0x00U,            NULL,               LinIfRxPdu   },
  { /*     2 */ LINIF_ENHANCED, UNCONDITIONAL, 8U,        0x06U,     0x00U,            NULL,               LinIfRxPdu   }
};


/*----------------------------------------------------------------------------------------------------------------------*/
/*                                                                                                                      */
/* NAME:    LinIf_User_EntryList       */
/*                 */
/* TYPE:    LinIfEntryType       */
/*                                                                                                                      */
/* DESCRIPTION: Configurations for the LIN Entry List                                                                                     */
/*----------------------------------------------------------------------------------------------------------------------*/

LinIfEntryType  LinIf_User_App_Schedule_EntryList[6] = {

    /* Index        DelayInTimebaseTicks      LinIfEntryIndex      LinIfCollisionResolvingRef                           LinIfFrameRef     */
  { /*     0 */             100U,                   0U,                         0x00u,                                  &LINIF_User_App_Frame_List[0]                            },  /* [PM25_LINTDB_R_01] */  
  { /*     0 */             100U,                   1U,                         0x00u,                                  &LINIF_User_App_Frame_List[1]                             },  /* [PM25_LINTDB_R_01] */  
  { /*     0 */             100U,                   2U,                         0x00u,                                  &LINIF_User_App_Frame_List[2]                             },  /* [PM25_LINTDB_R_01] */  
  { /*     0 */             100U,                   3U,                         0x00u,                                  &LINIF_User_App_Frame_List[3]                             },   /* [PM25_LINTDB_R_01] */  
  { /*     1 */             100U,                   4U,                         0x00u,                                  &LINIF_User_App_Frame_List[4]                            },  /* [PM25_LINTDB_R_01] */  
  { /*     2 */             100U,                   5U,                         0x00u,                                  &LINIF_User_App_Frame_List[5]                            }  /* [PM25_LINTDB_R_01] */  
};



/*----------------------------------------------------------------------------------------------------------------------*/
/*                                                                                                                      */
/* NAME:    LinIf_User_EntryList       */
/*                 */
/* TYPE:    LinIfEntryType       */
/*                                                                                                                      */
/* DESCRIPTION: Configurations for the LIN Entry List                                                                                     */
/*----------------------------------------------------------------------------------------------------------------------*/

LinIfEntryType  LinIf_User_Collison_Schedule_EntryList[3] = {

    /* Index        DelayInTimebaseTicks      LinIfEntryIndex      LinIfCollisionResolvingRef         LinIfFrameRef     */
  { /*     0 */             100U,                   0U,                         0x00u,                         &LINIF_User_Collison_Frame_List[0]                            },  /* [PM25_LINTDB_R_01] */  
  { /*     1 */             100U,                   1U,                         0x00u,                         &LINIF_User_Collison_Frame_List[1]                            },  /* [PM25_LINTDB_R_01] */  
  { /*     2 */             100U,                   2U,                         0x00u,                         &LINIF_User_Collison_Frame_List[2]                            }  /* [PM25_LINTDB_R_01] */  

};

/*----------------------------------------------------------------------------------------------------------------------*/
/*                                                                                                                      */
/* NAME:    LinIf_User_ScheduleTableList       */
/*                 */
/* TYPE:    LinIf_ScheduleTableType       */
/*                                                                                                                      */
/* DESCRIPTION: Configurations for the LIN Schedule Table                                                                                     */
/*----------------------------------------------------------------------------------------------------------------------*/

const LinIf_ScheduleTableType  LinIf_User_ScheduleTableList[3] = {
    /* Index    ResumePosition             RunMode            ScheduleTableName           LinIfEntryReference           NumberOfScheduleEntries                                                */
  { /*     0 */ START_FROM_BEGINNING ,    RUN_CONTINUOUS,    "NULL_SCHEDULE_TABLE",       NULL,                                       0x00u                        },  /* [NULLSchedule]        */
  { /*     1 */ CONTINUE_AT_IT_POINT ,    RUN_CONTINUOUS,    "APP_SCHEDULE_TABLE",        LinIf_User_App_Schedule_EntryList,                       0x06U                        },   /* [APP_SCHEDULE]        */
  { /*     2 */ START_FROM_BEGINNING ,    RUN_ONCE,          "COLLISON_SCHEDULE_TABLE",        LinIf_User_Collison_Schedule_EntryList,                  0x03U                        }

};


/*----------------------------------------------------------------------------------------------------------------------*/
/*                                                                                                                      */
/* NAME:    LinIf_Channel_Data       */
/*                 */
/* TYPE:    LinIf_ChannelType       */
/*                                                                                                                      */
/* DESCRIPTION: Configurations for the LIN Channel Data                                                                                  */
/*----------------------------------------------------------------------------------------------------------------------*/

const  LinIf_ChannelType   LinIf_Channel_Data[1] = {
/* Channel Id       LinIf_Frame               LinIfMaster      LinIf_ScheduleTable               LinIf_Slave          LinIf_WakeUpSource             LinIfStartupState   */
{  0x00u,      &LINIF_User_App_Frame_List[0],          {0},       &LinIf_User_ScheduleTableList[0],         NULL,                    NULL,                 LINIF_CHANNEL_SLEEP },

};

/*----------------------------------------------------------------------------------------------------------------------*/
/*                                                                                                                      */
/* NAME:    LinIf_Channel_Configuration       */
/*                 */
/* TYPE:    LinIfEntryType       */
/*                                                                                                                      */
/* DESCRIPTION:  Configurations for the Individual LIN Channel                                                                                    */
/*----------------------------------------------------------------------------------------------------------------------*/

const  LinIf_ConfigType   LinIf_Channel_Configuration[1] = {
/* LinIfTimeBase       LinIfChannel                    LinIfFrameConfig         LinIfGotoSleepConfirmationUL     LinIfScheduleRequestConfirmationUL   LinIfWakeupConfirmationUL */
{  0x0AU,         &LinIf_Channel_Data[0]    ,   &LINIF_User_App_Frame_List[0],     LIN_SM,                         LIN_SM,                               LIN_SM }

};


/*----------------------------------------------------------------------------------------------------------------------*/
/*                                                                                                                      */
/* NAME:    LinIf_General_Configuration       */
/*                 */
/* TYPE:    LinIf_GeneralType       */
/*                                                                                                                      */
/* DESCRIPTION:  General Configurations  of Lin interface                                                               */
/*----------------------------------------------------------------------------------------------------------------------*/

const LinIf_GeneralType LinIf_General_Configuration = {
  LINIF_DEV_ERROR_DETECT, 
  LINIF_MULTIPLE_DRIVER_SUPPORTED, 
  LINIF_TRANCEIVER_DRIVER_SUPPORTED,
  LINIF_NODECFG_OPTIONAL_REQ_SUPPORT,
  LINIF_MULTIPLETRANCEIVER_DRIVER_SUPPORTED,
  LINIFCANCELTRANSMITSUPPORTED,
  LINIF_TP_SUPPORTED,
  LINIF_VERSION_INFO_API
  };
#endif /* LINIF_PAR_CFG_C */

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

**============================================================================
**Date               : 24-APRIL-2019
**CDSID              : MKANNAN2
**Traceability       : RTC 
**Change Description : Update frame list schedule table against Sporadic and 
                        event triggered frame.
**============================================================================
**============================================================================
**Date               : 10-APRIL-2019
**CDSID              : MKANNAN2
**Traceability       : RTC 
**Change Description : Added Lin General configuration
                       Update Frame list in the Frame Type variable, Update Entery List of 
                       Schedule table.
**============================================================================
**============================================================================
**Date               : 04-SEP-2019
**CDSID              : BPANNEER
**Traceability       : RTC #1352138  
**Change Description : 1. Added descriptions for Configuration tables.
**============================================================================
**============================================================================
**Date               : 26-July-2019
**CDSID              : BPANNEER
**Traceability       : RTC #1285296
**Change Description : Initial Version.
**============================================================================*/
