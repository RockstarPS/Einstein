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
 *  @file        imx_sys_shutdown.c
 *  @brief       Implementation of abstraction layer to reboot or shutdown the system.
 *  @details     imx_sys_shutdown is an abstraction layer for rebooting and  shutdown the system. It is based
 *               on i.MX 8DualX/8DualXPlus/8QuadXPlus Applications Processor Reference Manual, Rev. E, 06/2019 Chapter
 *  @author      Divin Raj (draj5)
 *  @version     1.0
 *  @addtogroup  dk_bspal
 *  @copyright   Visteon Corporation
 *  @date        20200609
 *  @note        The following document is compliant to:
 *               1. Visteon C Coding Best Practice Rules Ver 1.1
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/*! @brief  :  Import string Header File. */
#include <unistd.h>

/*! @brief  : Import File Operations. */
#include <fcntl.h>

/*! @brief  : Import Error Handling. */
#include <errno.h>

/*! @brief  : Import Slog Handling. */
#include <sys/slogcodes.h>

/*! @brief  : Import DCMD Commands */
#include "imx8_sci_mgr.h"

/**********************************************************************************************************************
 *  PUBLIC FUNCTION PROTOTYPES
 *********************************************************************************************************************/
extern void board_pre_shutdown ( int32_t p_type_S32 );
extern void save_reset_info_to_nv ( int32_t p_type_S32, const char *p_reason_C );

/**********************************************************************************************************************
 *  INTERNAL MACROS
 *********************************************************************************************************************/

/*! @brief  : DELAY Value. */
#define DELAY       10U

/*! @brief  : WDG_ITERATION Wdg Iteration maximum. */
#define WDG_ITERATION       10

/*!  @brief  : DK_BSPAL_SC_PATH - Path to SCU. */
#define DK_BSPAL_SC_PATH        "/dev/sc"

/*!  @brief  : SLOG Macros for Logging. */
#define LOG_FMT     "%s:%d "
#define LOG_ARGS    __func__, __LINE__
#define NEWLINE     " "
#define LOGE(msg, vars...) (void)slogf(_SLOGC_CHAR, _SLOG_ERROR,LOG_FMT msg NEWLINE, LOG_ARGS, vars)
#define LOGI(msg, vars...) (void)slogf(_SLOGC_CHAR, _SLOG_INFO,LOG_FMT msg NEWLINE, LOG_ARGS, vars)

/*! **********************************************************************************************************************
 *  @PUBLIC FUNCTION IMPLEMENTATIONS
 ************************************************************************************************************************/

/*! *********************************************************************************************************************
 *
 * @brief     board_pre-shutdown function for preparing board for shutdown_system()
 *
 * @param[in] p_type_S32 : Type of operation shutdown/reboot
 *
 * @return    void
 *
 ***********************************************************************************************************************/
void board_pre_shutdown ( int32_t p_type_S32 )
{
    int32_t l_scfd_S32;

    int32_t l_ret_S32 = -1;

    int32_t l_sci_mgr_status_S32;

    int32_t l_wdg_cnt_S32;

    LOGI ( "board_pre_shutdown %u\n", p_type_S32 );

    /* Opening scu-imx8 resource manager */
    l_scfd_S32 = open ( DK_BSPAL_SC_PATH, O_RDWR );

    if ( 0 > l_scfd_S32 )
    {
        LOGE ( "%s", "failed to open /dev/sc device" );
    }
    else
    {
        LOGI ( "%s", "Stopping watch-dog\n" );

        l_wdg_cnt_S32 = 0;

        do
        {
            l_ret_S32 =  devctl ( l_scfd_S32, IMX_DCMD_SC_TIMER_STOP_WDOG, NULL, 0, &l_sci_mgr_status_S32 );
            l_wdg_cnt_S32++;
            ( void ) delay ( DELAY );
        }
        while ( ( l_ret_S32 == EAGAIN ) && ( l_wdg_cnt_S32 < WDG_ITERATION ) );

        if ( 0U == l_ret_S32 )
        {
            LOGI ( "%s", "Stopped watch-dog\n" );
        }
        else
        {
            LOGE ( "%s", "Failed to stop watch-dog\n" );
        }

        ( void ) close ( l_scfd_S32 );

    }


}

/*!*********************************************************************************************************************
 *
 * @brief     Saving user provided information before shutting down
 *
 * @param[in] p_type_S32  : Type of Operation shutdown/reboot
 *            p_reason_C  : Cause of shutdown/reboot
 *
 * @return    void
 *
 **********************************************************************************************************************/
void save_reset_info_to_nv ( int32_t p_type_S32, const char *p_reason_C )
{
    if ( NULL != p_reason_C )
    {
        LOGI ( "Reset reason %d, %s\n", p_type_S32, p_reason_C );

    }
    else
    {
        LOGI ( "Reset reason %d\n", p_type_S32 );
    }
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

