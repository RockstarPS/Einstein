#if !defined( OS_EVENT_H )
#define OS_EVENT_H

/* ===========================================================================
//
//                     CONFIDENTIAL VISTEON CORPORATION
//
//      This is an unpublished work of authorship, which contains trade
//      secrets, created in 2002.  Visteon Corporation owns all rights
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
// File:            os_event.h
//
// Description:     Client Interface file for the OS.
//
// ======================================================================== */

/* ===========================================================================
//
//  Include Files
//
// ======================================================================== */

#include "os_types.h"
#include <sys/neutrino.h>

/* ===========================================================================
//
//  Begin C in a C++ environment
//
// ======================================================================== */
#ifdef __cplusplus
extern "C" {
#endif

/* ===========================================================================
//
//  Public typedefs
//
// ======================================================================== */

typedef struct
{
    struct sigevent event;
}
os_io_event_type;


/* ===========================================================================
//
//  Public defines
//
// ======================================================================== */

#define OSAL_EVENT_SET_TYPE     (_PULSE_CODE_MINAVAIL + 0)
#define OSAL_EVENT_TMO_TYPE     (_PULSE_CODE_MINAVAIL + 1)


/* ===========================================================================
//
//  Function Name: 	os_register_io_event
//
//  Description:	Map a QNX pulse to an OSAL event.
//
// ======================================================================== */

os_status_type os_register_io_event(
	unsigned32         task_id,
    unsigned32         event,
    os_io_event_type * ioe
);


/* ===========================================================================
//
//  Function Name: os_get_task_priority
//
//  Description:
//
// ======================================================================== */

unsigned32 os_get_task_priority( unsigned32 task_id );


/* ===========================================================================
//
//  Function Name: os_get_task_connection_id
//
//  Description:
//
// ======================================================================== */

signed32 os_get_task_connection_id( unsigned32 task_id );


/* ===========================================================================
//
//  End C in a C++ environment
//
// ======================================================================== */
#ifdef __cplusplus
}
#endif

#endif /* OS_EVENT_H */

