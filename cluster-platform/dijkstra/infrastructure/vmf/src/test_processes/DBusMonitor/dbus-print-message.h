/* -*- mode: C; c-file-style: "gnu"; indent-tabs-mode: nil; -*- */
/* dbus-print-message.h  Utility function to print out a message
 *
 * Copyright (C) 2003 Philip Blundell <philb@gnu.org>
 * Copyright (C) 2003 Red Hat, Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */
#ifndef DBUS_PRINT_MESSAGE_H
#define DBUS_PRINT_MESSAGE_H

#include <stdio.h>
#include <string.h>
#include <dbus/dbus.h>

#ifdef VMF_TRACE
    #include "types.h"
    #include "nw_os_config.h"
    #include "nw_vmf.h"
    #include "nw_vmf_trace.h"
#endif


/* defines and typedefs*/
#ifdef VMF_TRACE

    #define DBUS_MONI_TRID_NAME           "DBUS"
    #define DBUS_MONI_TRACE_TASK_ERROR    "Error"
    #define DBUS_MONI_TRACE_TASK_METHOD   "Method"
    #define DBUS_MONI_TRACE_TASK_SIGNAL   "Signal"

    #define DBUS_MONI_TRACE_ERROR(scope, args...)                   VMF_TRACE_PRINTF(dbus_moni_trid, VMF_TRACE_SEVERITY_ERROR, DBUS_MONI_TRACE_TASK_ERROR, scope, args);
    #define DBUS_MONI_TRACE_INFO(severity, task, scope, args...)    VMF_TRACE_PRINTF(dbus_moni_trid, severity, task, scope, args);
    #define DBUS_MONI_TRACE_HEX(severity, task, scope, len, data)   VMF_TRACE_HEX(dbus_moni_trid, severity, task, scope, len, data);

#else

    #define DBUS_MONI_TRACE_ERROR(scope, args...)                   printf("dbus_moni: ERROR "); printf(scope), printf(" -- "); printf(args); printf("\n");
    #define DBUS_MONI_TRACE_INFO(severity, task, scope, args...)    printf("dbus_moni: "); printf(args); printf("\n");
    #define DBUS_MONI_TRACE_HEX(severity, task, scope, len, data)   printf("dbus_moni: DBUS_MONI_TRACE_HEX ---- PLEASE IMPLEMENT ME!!!!");

#endif

void print_message (DBusMessage *message);

#endif /* DBUS_PRINT_MESSAGE_H */
