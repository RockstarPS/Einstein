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
/*****************************************************************************
* File Name         :  LinIf_Par_Cfg.h                                       *
* Module Short Name :  LinIf                                                 *
* Description       :  contains the configurable parameters Macros, configuration table declarations.*
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


#ifndef LINIF_PAR_CFG_H
#define LINIF_PAR_CFG_H

#include "LinIf_Types.h"

/*----------------------------------------------------------------------------------------------------------------------*/
/*                                                                                                                      */
/* NAME:   LINIF_User_Frame_List           */  
/*                 */
/* TYPE:   LinIf_FrameType        */
/*                                                                                                                      */
/* DESCRIPTION:  Configurations for the LIN Frames list                                                                */
/*----------------------------------------------------------------------------------------------------------------------*/
extern   LinIf_FrameType LINIF_User_App_Frame_List[6]; 

/*----------------------------------------------------------------------------------------------------------------------*/
/*                                                                                                                      */
/* NAME:   LINIF_User_Collison_Frame_List           */  
/*                 */
/* TYPE:   LinIf_FrameType        */
/*                                                                                                                      */
/* DESCRIPTION:  Configurations for the LIN Collison Frames list                                                                */
/*----------------------------------------------------------------------------------------------------------------------*/
extern  LinIf_FrameType LINIF_User_Collison_Frame_List[3];


 /*----------------------------------------------------------------------------------------------------------------------*/
/*                                                                                                                      */
/* NAME:   LINIF_User_Collison_Frame_List           */  
/*                 */
/* TYPE:   LinIf_FrameType        */
/*                                                                                                                      */
/* DESCRIPTION:  Configurations for the LIN Sporadic Frames list                                                                */
/*----------------------------------------------------------------------------------------------------------------------*/
extern  LinIf_FrameType LINIF_User_SporadicFrameList[3];

/*----------------------------------------------------------------------------------------------------------------------*/
/*                                                                                                                      */
/* NAME:    LinIf_User_ScheduleTableList       */
/*                 */
/* TYPE:    LinIf_ScheduleTableType       */
/*                                                                                                                      */
/* DESCRIPTION: Configurations for the LIN Schedule Table                                                                                     */
/*----------------------------------------------------------------------------------------------------------------------*/
extern const LinIf_ScheduleTableType  LinIf_User_ScheduleTableList[3]; 
/*----------------------------------------------------------------------------------------------------------------------*/
/*                                                                                                                      */
/* NAME:    LinIf_User_EntryList       */
/*                 */
/* TYPE:    LinIfEntryType       */
/*                                                                                                                      */
/* DESCRIPTION: Configurations for the LIN Entry List                                                                                     */
/*----------------------------------------------------------------------------------------------------------------------*/
extern  LinIfEntryType  LinIf_User_App_Schedule_EntryList[6];


/*----------------------------------------------------------------------------------------------------------------------*/
/*                                                                                                                      */
/* NAME:    LinIf_User_Collison_Schedule_EntryList       */
/*                 */
/* TYPE:    LinIfEntryType       */
/*                                                                                                                      */
/* DESCRIPTION: Configurations for the LIN if collison schedule entry list                                                                                     */
/*----------------------------------------------------------------------------------------------------------------------*/
extern  LinIfEntryType  LinIf_User_Collison_Schedule_EntryList[3];
/*----------------------------------------------------------------------------------------------------------------------*/
/*                                                                                                                      */
/* NAME:    LinIf_Channel_Data       */
/*                 */
/* TYPE:    LinIf_ChannelType       */
/*                                                                                                                      */
/* DESCRIPTION: Configurations for the LIN Channel Data                                                                                  */
/*----------------------------------------------------------------------------------------------------------------------*/
extern const  LinIf_ChannelType   LinIf_Channel_Data[1];
/*----------------------------------------------------------------------------------------------------------------------*/
/*                                                                                                                      */
/* NAME:    LinIf_Channel_Configuration       */
/*                 */
/* TYPE:    LinIf_ConfigType       */
/*                                                                                                                      */
/* DESCRIPTION:  Configurations for the Individual LIN Channel                                                                                    */
/*----------------------------------------------------------------------------------------------------------------------*/
extern const  LinIf_ConfigType   LinIf_Channel_Configuration[1];

/*This macro defines Lin interface configurations */

/**
  * @brief This macro defines Lin interface configurations.
  * unit : N/A
  * Resolution: N/A
  * Range: N/A
  * Applicablity: N/A
  */
#define LinIf_Config_Ptr           &LinIf_Channel_Configuration[0]


/*----------------------------------------------------------------------------------------------------------------------*/
/*                                                                                                                      */
/* NAME:    LinIf_General_Configuration       */
/*                 */
/* TYPE:    LinIf_GeneralType       */
/*                                                                                                                      */
/* DESCRIPTION:  Configurations for the Lin interface general features                                                                                   */
/*----------------------------------------------------------------------------------------------------------------------*/
extern const LinIf_GeneralType LinIf_General_Configuration;

#endif /* LINIF_PAR_CFG_H */

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
**Date               : 10-APRIL-2019
**CDSID              : MKANNAN2
**Traceability       : RTC 
**Change Description : Added Lin General configuration Variable Declaration
                       
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




