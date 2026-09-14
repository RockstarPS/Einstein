#ifndef DK_BSPAL_SYS_SHUTDOWN_H_
#define DK_BSPAL_SYS_SHUTDOWN_H_

/**********************************************************************************************************************
 *!  \verbatim
 *!
 *       VISTEON CORPORATION CONFIDENTIAL
 *       ________________________________
 *       [2020] Visteon Corporation
 *       All Rights Reserved.
 *
 *       NOTICE: This is an unpublished work of authorship, which contains trade
 *               secrets. Visteon Corporation owns all rights to this work and
 *               intends to maintain it in confidence to preserve its trade
 *               secret status. Visteon Corporation reserves the right, under
 *               the copyright laws of the United States or those of any other
 *               country that may have jurisdiction, to protect this work as an
 *               unpublished work, in the event of an inadvertent or deliberate
 *               unauthorized publication. Visteon Corporation also reserves its
 *               rights under all copyright laws to protect this work as a
 *               published work, when appropriate. Those having access to this
 *               work may not copy it, use it, modify it, or disclose the
 *               information contained in it without the written authorization
 *               of Visteon Corporation.
 *
 *  @endverbatim
 *
 *  @file        dk_bspal_sys_shutdown.h
 *  @brief       Abstraction layer to reboot and shutdown system
 *  @details     dk_bspal_sys_shutdown is an abstraction layer for reboot and shutdown system
 *               fuses. It is based on i.MX 8DualX/8DualXPlus/8QuadXPlus Applications Processor
 *               Reference Manual, Rev. E, 06/2019 Chapter
 *  @author      Divin Raj (draj5)
 *  @version     1.0
 *  @addtogroup  dk_bspal
 *  @copyright   Visteon Corporation
 *********************************************************************************************************************/

/*! @brief  :  Import std_types Header File. */
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*! ******************************************************************************************************************
 *  @CONSTANTS and TYPES
 ********************************************************************************************************************/

/*! @brief :ESysShutdown_t - Supported Types */
typedef enum
{
    ESysShutdown_Reboot = 0,
    ESysShutdown_Shutdown,
} ESysShutdown_t;

/*! *********************************************************************************************************************
 *  @FUNCTION PROTOTYPES
 ************************************************************************************************************************/

/*! *********************************************************************************************************************
 *
 * @brief     Shutdown or Rebooting the system and retain(cause of shutdown) user provided information
 * @param[in] p_type_E     : Type of shutdown
 *            p_reason_C   : Cause of shutdown
 *
 * @return    0     : Success
 *           -1     : FAIL
 *
 **********************************************************************************************************************/
int32_t dk_bspal_sys_shutdown ( ESysShutdown_t p_type_E, const char *p_reason_C );

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

/************************************************** END of FILE *****************************************************/

/*--------------------------------------------------------------------------------------------------------------------
   REVISION HISTORY
 ---------------------------------------------------------------------------------------------------------------------
 Date               : 18-08-2020
 By                 : draj5
 Trace-ability      : GIT#
 Change Description : Initial Version
 --------------------------------------------------------------------------------------------------------------------*/

#endif /* DK_BSPAL_SYS_SHUTDOWN_H_ */
