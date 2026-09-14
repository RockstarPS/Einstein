/**********************************************************************************************************************
 *!  \verbatim
 *!
 *       VISTEON CORPORATION CONFIDENTIAL
 *       ________________________________
 *       [2020] Visteon Corporation
 *       All Rights Reserved.
 *
 *       NOTICE: This is an unpublished work of authorship, which contains trade
 *               secrets. Visteon Corporation owns all rights to this work and intends to
 *               maintain it in confidence to preserve its trade secret status. Visteon
 *               Corporation reserves the right, under the copyright laws of the United States
 *               or those of any other country that may have jurisdiction, to protect this work
 *               as an unpublished work, in the event of an inadvertent or deliberate
 *               unauthorized publication. Visteon Corporation also reserves its rights under
 *               all copyright laws to protect this work as a published work, when appropriate.
 *               Those having access to this work may not copy it, use it, modify it, or
 *               disclose the information contained in it without the written authorization of
 *               Visteon Corporation.
 *
 *  @endverbatim
 *
 *  @file        qnx_sys_shutdown.c
 *  @brief       Implementation of abstraction layer to reboot or shutdown the system.
 *  @details     qnx_sys_shutdown is an abstraction layer for rebooting and  shutdown the system. It is based
 *               on i.MX 8DualX/8DualXPlus/8QuadXPlus Applications Processor Reference Manual, Rev. E, 06/2019 Chapter
 *  @author      Divin Raj (draj5)
 *  @version     1.0
 *  @addtogroup  dk_bspal
 *  @copyright   Visteon Corporation
 *  @date        18082020
 *  @note        The following document is compliant to:
 *               1. Visteon C Coding Best Practice Rules Ver 1.1
 *********************************************************************************************************************/

/*! *********************************************************************************************************************
 *  @INCLUDES
 *********************************************************************************************************************/

/*! @brief  :  Import shutdown Header File. */
#include <sys/shutdown.h>

/*! @brief  :  Import  Module Public Header File. */
#include "dk_bspal_sys_shutdown.h"

/*! **********************************************************************************************************************
 *  @PUBLIC FUNCTION IMPLEMENTATIONS
 ************************************************************************************************************************/

/*! *********************************************************************************************************************
 *
 * @brief     Shutdown the system and retain(cause of shutdown) user provided information
 * @param[in] p_type_E     : Type of Operation shutdown/reboot
 *            p_reason_C   : Cause of shutdown/reboot
 *
 * @return    0     : Success
 *           -1     : FAIL
 *
 **********************************************************************************************************************/
int32_t dk_bspal_sys_shutdown ( ESysShutdown_t p_type_E, const char *p_reason_C )
{
    int32_t l_RetVal_S32 = -1;
    static int32_t l_Option_S32 = 0;

    switch ( p_type_E )
    {
        case ESysShutdown_Reboot:
            l_Option_S32 = SHUTDOWN_REBOOT;
            l_RetVal_S32 = 0;
            break;

        case ESysShutdown_Shutdown:
            l_Option_S32 = SHUTDOWN_SYSTEM;
            l_RetVal_S32 = 0;
            break;

        default:
            l_RetVal_S32 = -1;
            break;
    };

    /* Calling QNX shutdown API */
    shutdown_system_with_reason ( ( int ) l_Option_S32, FLAG_REVERSE_ORDER, ( char * ) p_reason_C );

    return l_RetVal_S32;
}


/************************************************** END of FILE *****************************************************/

/*--------------------------------------------------------------------------------------------------------------------
   REVISION HISTORY
 ---------------------------------------------------------------------------------------------------------------------
 Date               : 18-08-2020
 By                 : draj5
 Trace-ability      : GIT#
 Change Description : Initial Version
 --------------------------------------------------------------------------------------------------------------------*/
