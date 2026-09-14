#if !defined (UART_IF_H)
#define UART_IF_H
/* ===========================================================================
//
//                     CONFIDENTIAL VISTEON CORPORATION
//
//      This is an unpublished work of authorship, which contains trade
//      secrets, created in 2008.  Visteon Corporation owns all rights
//      to this work and intends to maintain it in confidence to preserve
//      its trade secret status.  Visteon Corporation reserves the right,
//      under the copyright laws of the United States or those of any other
//      country that may have jurisdiction, to protect this work as an
//      unpublished work, in the event of an inadvertent or deliberate
//      unauthorized publication.  Visteon Corporation also reserves its
//      rights under all copyright laws to protect this work as a published
//      work, when appropriate.  Those having access to this work may not
//      copy it, use it, modify it, or disclose the information contained
//      in it without the written authorization of Visteon Corporation.
//
// ======================================================================== */

/* ===========================================================================
//
//  Name:           uart_if.h
//
//  Description:    This file contains the UART client public interface
//                  declarations.
//
// ======================================================================== */
/* ===========================================================================
//
//  Begin C in a C++ environment
//
// ======================================================================== */
#if defined (__cplusplus)
extern "C" {
#endif

#include "uart_drv.h"
/* ===========================================================================
//
//  Public Defined Constants
//
// ======================================================================== */

/* ===========================================================================
//
//  Public Type / Structure Definitions
//
// ======================================================================== */
typedef enum
{
    DEVICECOMM_STATUS_MSG_GOOD,
    DEVICECOMM_STATUS_MSG_BAD,
    DEVICECOMM_STATUS_MSG_PENDING,
    DEVICECOMM_STATUS_MSG_OVERWRITTEN,
    DEVICECOMM_STATUS_DRIVER_ACTIVE,
    DEVICECOMM_STATUS_ERROR_DISABLED,
    DEVICECOMM_STATUS_ERROR_BADCONFIG,
    DEVICECOMM_STATUS_CONFIG_FAILURE,
    DEVICECOMM_STATUS_ERROR_BADSTATE,
    DEVICECOMM_STATUS_ERROR_CALLBACK_OVERRUN

} DEVICECOMM_STATUS_TYPE;


DEVICECOMM_STATUS_TYPE uart_tx_req ( UART_CLIENT_ID_T const client_id, void const * const p_tx_data,\
                                     UART_BUFFER_SIZE_T const tx_len );


#if defined (__cplusplus)
}
#endif


#endif  /* UART_IF_H */
