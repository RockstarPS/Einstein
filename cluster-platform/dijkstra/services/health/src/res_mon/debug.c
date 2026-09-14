/*---------------------------------------------------------------------------------------------------------------------

 VISTEON CORPORATION CONFIDENTIAL
 ________________________________

 [2020] Visteon Corporation
 All Rights Reserved.

 NOTICE: This is an unpublished work of authorship, which contains trade secrets.
 Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
 its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
 or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
 in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
 under all copyright laws to protect this work as a published work, when appropriate.
 Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
 without the written authorization of Visteon Corporation.

---------------------------------------------------------------------------------------------------------------------*/

#include <errno.h>
#include "debug.h"

/*!****************************************************************************
Function Name: res_mon_enable_logging
 @brief     Function that is called to register with slogger2 so that slog2info logs are logged
 @param     void
 @return    uint8_t
 *****************************************************************************/

uint8_t res_mon_enable_logging ( void )
{
    uint8_t l_status_slog_U8 = EOK;
    
    /* Initialize slog2 */
    slog2_config.buffer_set_name = __progname;
    slog2_config.num_buffers = 1;
    slog2_config.verbosity_level = SLOG2_DEBUG2;
    slog2_config.buffer_config[0U].buffer_name = "res_mon";
    slog2_config.buffer_config[0U].num_pages = 8;

    if( 0 != slog2_register( &slog2_config, &slog2_handle, 0 ) )
    {
        ( void ) fprintf ( stderr, "Error registering slogger2 buffer for res_mon.!\n" );
        l_status_slog_U8 = 1;
    }
    else
    {
        /* Added for MISRA */
    }

    return l_status_slog_U8;
}
