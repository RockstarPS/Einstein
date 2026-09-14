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
#include "dbus-print-message.h"

#include <stdlib.h>


/* jmerkle  #define CONSOLE_PRINT */

#ifdef VMF_TRACE
extern    unsigned8   dbus_moni_trid;
#endif

#define MAX_DATA_LEN 5000
char data_buffer[MAX_DATA_LEN];

static const char* type_to_name (int message_type)
{
    switch (message_type)
    {
        case DBUS_MESSAGE_TYPE_SIGNAL:
            return "signal";
        break;
        case DBUS_MESSAGE_TYPE_METHOD_CALL:
            return "method call";
        break;
        case DBUS_MESSAGE_TYPE_METHOD_RETURN:
            return "method return";
        break;
        case DBUS_MESSAGE_TYPE_ERROR:
            return "error";
        break;
        default:
            return "(unknown message type)";
        break;
    }
}

#define INDENT 3

static void indent (int depth)
{
    while (depth-- > 0)
    {
        printf ("   "); /* INDENT spaces. */
    }
}

static void print_hex (char *out, unsigned char *bytes, unsigned int len, int depth)
{
    int i, columns;
    char *pos = out;

    indent (depth + 1);

    /* Each byte takes 3 cells (two hexits, and a space), except the last one. */
    columns = (80 - ((depth + 1) * INDENT)) / 3;

    if (columns < 8)
    {
        columns = 8;
    }

    i = 0;

    while (i < len)
    {
        pos += snprintf(pos, 3, "%02x", bytes[i]);
        i++;

        if (i != len)
        {
            if (NULL != out)
            {
            }
            else
            {
                if (i % columns == 0)
                {
                    pos += snprintf(pos, 3, "\n");
                    indent (depth + 1);
                }
                else
                {
                    pos += snprintf(pos, 3, " ");
                }
            }
        }
    }

    /* terminate text in buffer */
    if (NULL != out)
    {
        *pos = 0x00;
    }

}


static void print_ay (char* text_buffer, DBusMessageIter *iter, int depth)
{
    /* Not using DBusString because it's not public API. It's 2009, and I'm
    * manually growing a string chunk by chunk.
    */
    unsigned char bytes[MAX_DATA_LEN];
    unsigned int len = 0;
    char local_buffer[MAX_DATA_LEN];

    while (dbus_message_iter_get_arg_type(iter) != DBUS_TYPE_INVALID)
    {
        unsigned char val;

        dbus_message_iter_get_basic (iter, &val);
        bytes[len] = val;
        len++;

        if (len == MAX_DATA_LEN)
        {
            /* let's return and cut data since buffer full...*/
            return;
        }

        dbus_message_iter_next (iter);
    }

    print_hex (local_buffer, bytes, len, depth);

    if (NULL != text_buffer)
    {
        snprintf(text_buffer, MAX_DATA_LEN, " array of bytes '%s'", local_buffer);
    }
    else
    {
        printf ("array of bytes [\n");
        printf ("%s", local_buffer);
        printf ("\n");
        indent (depth);
        printf ("]\n");
    }
}

static void print_iter (char *text_buffer, DBusMessageIter *iter, dbus_bool_t literal, int depth)
{

    char *pos = text_buffer;

    do
    {
        int type = dbus_message_iter_get_arg_type (iter);

        if (type == DBUS_TYPE_INVALID)
        {
            break;
        }

#ifdef CONSOLE_PRINT
        indent(depth);
#endif

        switch (type)
        {
            case DBUS_TYPE_STRING:
            {
                char *val;
                dbus_message_iter_get_basic (iter, &val);
                if (NULL != text_buffer)
                {
                    pos += snprintf(pos, MAX_DATA_LEN, " string '%s'", val);
                }
                else
                {
                    printf ("string \"");
                    printf ("%s", val);
                    printf ("\"\n");
                }
                break;
            }

            case DBUS_TYPE_SIGNATURE:
            {
                char *val;
                dbus_message_iter_get_basic (iter, &val);

                if (NULL != text_buffer)
                {
                    pos += snprintf(pos, MAX_DATA_LEN, " signature '%s'", val);
                }
                else
                {
                    printf ("signature \"");
                    printf ("%s", val);
                    printf ("\"\n");
                }
                break;
            }

            case DBUS_TYPE_OBJECT_PATH:
            {
                char *val;
                dbus_message_iter_get_basic (iter, &val);
                if (NULL != text_buffer)
                {
                    pos += snprintf(pos, MAX_DATA_LEN, " object path '%s'", val);
                }
                else
                {
                    printf ("object path \"");
                    printf ("%s", val);
                    printf ("\"\n");
                }
                break;
            }

            case DBUS_TYPE_INT16:
            {
                dbus_int16_t val;
                dbus_message_iter_get_basic (iter, &val);
                if (NULL != text_buffer)
                {
                    pos += snprintf(pos, MAX_DATA_LEN, " int16 '%d'", val);
                }
                else
                {
                    printf ("int16 %d\n", val);
                }
                break;
            }

            case DBUS_TYPE_UINT16:
            {
                dbus_uint16_t val;
                dbus_message_iter_get_basic (iter, &val);
                if (NULL != text_buffer)
                {
                    pos += snprintf(pos, MAX_DATA_LEN, " uint16 '%u'", val);
                }
                else
                {
                    printf ("uint16 %u\n", val);
                }
                break;
            }

            case DBUS_TYPE_INT32:
            {
                dbus_int32_t val;
                dbus_message_iter_get_basic (iter, &val);
                if (NULL != text_buffer)
                {
                    pos += snprintf(pos, MAX_DATA_LEN, " int32 '%d'", val);
                }
                else
                {
                    printf ("int32 %d\n", val);
                }
                break;
            }

            case DBUS_TYPE_UINT32:
            {
                dbus_uint32_t val;
                dbus_message_iter_get_basic (iter, &val);
                if (NULL != text_buffer)
                {
                    pos += snprintf(pos, MAX_DATA_LEN, " uint32 '%u'", val);
                }
                else
                {
                    printf ("uint32 %u\n", val);
                }
                break;
            }

            case DBUS_TYPE_INT64:
            {
                dbus_int64_t val;
                dbus_message_iter_get_basic (iter, &val);
                if (NULL != text_buffer)
                {
                    #ifdef DBUS_INT64_PRINTF_MODIFIER
                    pos += snprintf(pos, MAX_DATA_LEN, " int64 '%" DBUS_INT64_PRINTF_MODIFIER "d'", val);
                    #else
                    pos += snprintf(pos, MAX_DATA_LEN, " int64 (omitted)");
                    #endif
                }
                else
                {
                    #ifdef DBUS_INT64_PRINTF_MODIFIER
                    printf ("int64 %" DBUS_INT64_PRINTF_MODIFIER "d\n", val);
                    #else
                    printf ("int64 (omitted)\n");
                    #endif
                }
                break;
            }

            case DBUS_TYPE_UINT64:
            {
                dbus_uint64_t val;
                dbus_message_iter_get_basic (iter, &val);

                if (NULL != text_buffer)
                {
                    #ifdef DBUS_UINT64_PRINTF_MODIFIER
                    pos += snprintf(pos, MAX_DATA_LEN, " uint64 '%" DBUS_UINT64_PRINTF_MODIFIER "u'", val);
                    #else
                    pos += snprintf(pos, MAX_DATA_LEN, " uint64 (omitted)");
                    #endif
                }
                else
                {
                    #ifdef DBUS_UINT64_PRINTF_MODIFIER
                    printf ("uint64 %" DBUS_UINT64_PRINTF_MODIFIER "u\n", val);
                    #else
                    printf ("uint64 (omitted)\n");
                    #endif
                }
                break;
            }

            case DBUS_TYPE_DOUBLE:
            {
                double val;
                dbus_message_iter_get_basic (iter, &val);
                if (NULL != text_buffer)
                {
                    pos += snprintf(pos, MAX_DATA_LEN, " double '%g'", val);
                }
                else
                {
                    printf ("double %g\n", val);
                }
                break;
            }

            case DBUS_TYPE_BYTE:
            {
                unsigned char val;
                dbus_message_iter_get_basic (iter, &val);
                if (NULL != text_buffer)
                {
                    pos += snprintf(pos, MAX_DATA_LEN, " byte '%d'", val);
                }
                else
                {
                    printf ("byte %d\n", val);
                }
                break;
            }

            case DBUS_TYPE_BOOLEAN:
            {
                dbus_bool_t val;
                dbus_message_iter_get_basic (iter, &val);
                if (NULL != text_buffer)
                {
                    pos += snprintf(pos, MAX_DATA_LEN, " boolean '%s'", val ? "true" : "false");
                }
                else
                {
                    printf ("boolean %s\n", val ? "true" : "false");
                }
                break;
            }

            case DBUS_TYPE_VARIANT:
            {
                DBusMessageIter subiter;

                dbus_message_iter_recurse (iter, &subiter);
                if (NULL != text_buffer)
                {
                    char local_data_buffer[MAX_DATA_LEN];
                    pos += snprintf(pos, MAX_DATA_LEN, " variant");
                    print_iter (local_data_buffer, &subiter, literal, depth+1);
                    pos += snprintf(pos, MAX_DATA_LEN, " %s", local_data_buffer);
                }
                else
                {
                    printf ("variant ");
                    print_iter (NULL, &subiter, literal, depth+1);
                }
                break;
            }

            case DBUS_TYPE_ARRAY:
            {
                int current_type;
                DBusMessageIter subiter;

                dbus_message_iter_recurse (iter, &subiter);

                current_type = dbus_message_iter_get_arg_type (&subiter);

                if (current_type == DBUS_TYPE_BYTE)
                {
                    if (NULL != text_buffer)
                    {
                        char local_data_buffer[MAX_DATA_LEN];
                        print_ay (local_data_buffer, &subiter, depth);
                        pos += snprintf(pos, MAX_DATA_LEN, " %s", local_data_buffer);
                    }
                    else
                    {
                        print_ay (NULL, &subiter, depth);
                    }
                    break;
                }

                if (NULL != text_buffer)
                {
                    char local_data_buffer[MAX_DATA_LEN];
                    pos += snprintf(pos, MAX_DATA_LEN, " variant");
                    while (current_type != DBUS_TYPE_INVALID)
                    {
                        print_iter (local_data_buffer, &subiter, literal, depth+1);
                        dbus_message_iter_next (&subiter);
                        current_type = dbus_message_iter_get_arg_type (&subiter);
                        pos += snprintf(pos, MAX_DATA_LEN, " %s", local_data_buffer);
                    }
                }
                else
                {
                    printf("array [\n");
                    while (current_type != DBUS_TYPE_INVALID)
                    {
                        print_iter (NULL, &subiter, literal, depth+1);

                        dbus_message_iter_next (&subiter);
                        current_type = dbus_message_iter_get_arg_type (&subiter);

                        if (current_type != DBUS_TYPE_INVALID)
                            printf (",");
                    }
                    indent(depth);
                    printf("]\n");
                }
                break;
            }

            case DBUS_TYPE_DICT_ENTRY:
            {
                DBusMessageIter subiter;

                dbus_message_iter_recurse (iter, &subiter);

                if (NULL != text_buffer)
                {
                    char local_data_buffer[MAX_DATA_LEN];
                    pos += snprintf(pos, MAX_DATA_LEN, " dict entry");
                    print_iter (local_data_buffer, &subiter, literal, depth+1);
                    pos += snprintf(pos, MAX_DATA_LEN, " %s", local_data_buffer);
                    dbus_message_iter_next (&subiter);
                    print_iter (local_data_buffer, &subiter, literal, depth+1);
                    pos += snprintf(pos, MAX_DATA_LEN, " %s", local_data_buffer);
                }
                else
                {
                    printf("dict entry(\n");
                    print_iter (NULL, &subiter, literal, depth+1);
                    dbus_message_iter_next (&subiter);
                    print_iter (NULL, &subiter, literal, depth+1);
                    indent(depth);
                    printf(")\n");
                }
                break;
            }

            case DBUS_TYPE_STRUCT:
            {
                int current_type;
                DBusMessageIter subiter;

                dbus_message_iter_recurse (iter, &subiter);

                if (NULL != text_buffer)
                {
                    char local_data_buffer[MAX_DATA_LEN];
                    pos += snprintf(pos, MAX_DATA_LEN, " struct");
                    current_type = dbus_message_iter_get_arg_type (&subiter);
                    while ( DBUS_TYPE_INVALID != current_type)
                    {
                        print_iter (local_data_buffer, &subiter, literal, depth+1);
                        pos += snprintf(pos, MAX_DATA_LEN, " %s", local_data_buffer);
                        dbus_message_iter_next (&subiter);
                    }
                }
                else
                {
                    printf("struct {\n");
                    current_type = dbus_message_iter_get_arg_type (&subiter);
                    while ( DBUS_TYPE_INVALID != current_type)
                    {
                        print_iter (NULL, &subiter, literal, depth+1);
                        dbus_message_iter_next (&subiter);
                        if (dbus_message_iter_get_arg_type (&subiter) != DBUS_TYPE_INVALID)
                            printf (",");
                    }
                    indent(depth);
                    printf("}\n");
                }
                break;
            }

            default:
                printf (" (dbus-monitor too dumb to decipher arg type '%c')\n", type);
                DBUS_MONI_TRACE_ERROR("print_iter default", "dbus-monitor too dumb to decipher arg type '%c'", type);
            break;
        }
    } while (dbus_message_iter_next (iter));


    /* terminate text in buffer */
    if (NULL != text_buffer)
    {
        *pos = 0x00;
    }

}

void print_message (DBusMessage *message)
{
#ifdef CONSOLE_PRINT
    DBusMessageIter iter;
#endif
    DBusMessageIter vmf_trace_iter;
    const char *sender;
    const char *destination;
    int message_type;

    message_type = dbus_message_get_type (message);
    sender = dbus_message_get_sender (message);
    destination = dbus_message_get_destination (message);

    dbus_message_iter_init (message, &vmf_trace_iter);
    print_iter (data_buffer, &vmf_trace_iter, false, 1);

    switch (message_type)
    {
        case DBUS_MESSAGE_TYPE_METHOD_CALL:
#ifdef CONSOLE_PRINT
            printf ("%s sender=%s -> dest=%s; serial=%u path=%s; interface=%s; member=%s\n",
                    type_to_name(message_type), (sender ? sender : "(null sender)"), (destination ? destination : "(null destination)"),
                    dbus_message_get_serial (message), dbus_message_get_path (message),
                    dbus_message_get_interface (message), dbus_message_get_member (message));
#endif

            DBUS_MONI_TRACE_INFO(VMF_TRACE_SEVERITY_INFO_10, DBUS_MONI_TRACE_TASK_METHOD, (char *)type_to_name(message_type),
                    "sender=%s -> dest=%s; serial=%u path=%s; interface=%s; member=%s; data=%s",
                    (sender ? sender : "(null sender)"), (destination ? destination : "(null destination)"),
                    dbus_message_get_serial (message), dbus_message_get_path (message),
                    dbus_message_get_interface (message), dbus_message_get_member (message), data_buffer);

        break;

        case DBUS_MESSAGE_TYPE_SIGNAL:
#ifdef CONSOLE_PRINT
            printf ("%s sender=%s -> dest=%s; serial=%u path=%s; interface=%s; member=%s\n",
                    type_to_name(message_type), (sender ? sender : "(null sender)"), (destination ? destination : "(null destination)"),
                    dbus_message_get_serial (message), dbus_message_get_path (message),
                    dbus_message_get_interface (message), dbus_message_get_member (message));
#endif

            DBUS_MONI_TRACE_INFO(VMF_TRACE_SEVERITY_INFO_10, DBUS_MONI_TRACE_TASK_SIGNAL, (char *)type_to_name(message_type),
                    "sender=%s -> dest=%s; serial=%u path=%s; interface=%s; member=%s; data=%s",
                    (sender ? sender : "(null sender)"), (destination ? destination : "(null destination)"),
                    dbus_message_get_serial (message), dbus_message_get_path (message),
                    dbus_message_get_interface (message), dbus_message_get_member (message), data_buffer);

        break;

        case DBUS_MESSAGE_TYPE_METHOD_RETURN:
#ifdef CONSOLE_PRINT
            printf ("%s sender=%s -> dest=%s; reply_serial=%u\n",
                    type_to_name(message_type), (sender ? sender : "(null sender)"), (destination ? destination : "(null destination)"),
                    dbus_message_get_reply_serial (message));
#endif

            DBUS_MONI_TRACE_INFO(VMF_TRACE_SEVERITY_INFO_10, DBUS_MONI_TRACE_TASK_METHOD, (char *)type_to_name(message_type),
                    "sender=%s -> dest=%s; reply_serial=%u; data=%s",
                    (sender ? sender : "(null sender)"), (destination ? destination : "(null destination)"),
                    dbus_message_get_reply_serial (message), data_buffer);

        break;

        case DBUS_MESSAGE_TYPE_ERROR:
            DBUS_MONI_TRACE_ERROR((char *)type_to_name(message_type),
                    "sender=%s -> dest=%s; error_name=%s reply_serial=%u; data=%s",
                    (sender ? sender : "(null sender)"), (destination ? destination : "(null destination)"),
                    dbus_message_get_error_name (message), dbus_message_get_reply_serial (message), data_buffer);
        break;

        default:
#ifdef CONSOLE_PRINT
            printf ("\n");
#endif
            DBUS_MONI_TRACE_ERROR("Error", "Unknown Message Type!");
        break;
    }

#ifdef CONSOLE_PRINT
    dbus_message_iter_init (message, &iter);
    print_iter (NULL, &iter, false, 1);
    fflush (stdout);
#endif
  
}

