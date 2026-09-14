
/* jmerkle  26.07.2011 13:09:54 */
/* jmerkle  D-Bus Monitor */


#include <glib.h>
#include <dbus/dbus.h>
#include <dbus/dbus-glib.h>
#include "dbus-print-message.h"



typedef struct
{
    unsigned8   dummy;
}options_t;


/* global data */
options_t           options;
#ifdef VMF_TRACE
    unsigned8   dbus_moni_trid;
#endif


/* function declarations */
static DBusHandlerResult signal_filter(DBusConnection *connection, DBusMessage *message, void *user_data);
unsigned64 vmf_get_time_snapshot(void);
unsigned64 vmf_get_time_diff(unsigned64 start_time, unsigned64 stop_time);
bool get_options(int argc, char *argv[]);
void usage(void);


int main (int argc, char **argv)
{
    DBusConnection *bus;
    DBusError error;


    if (false == get_options(argc,argv))
    {
        return -1;
    }

    #ifdef VMF_TRACE
    /* Register at VMF Tracer */
    if (VMF_TRACE_REGISTER(&dbus_moni_trid, DBUS_MONI_TRID_NAME) < 0)
    {
        fprintf(stderr, "dbus_sender: CANNOT CONNECT TO VMF TRACER!!!");
    }
    #endif


    dbus_error_init (&error);
    bus = dbus_bus_get (DBUS_BUS_SESSION, &error);
    if (!bus)
    {
        DBUS_MONI_TRACE_ERROR("main", "Failed to connect to the D-BUS daemon: %s", error.message);
        dbus_error_free (&error);
        return 1;
    }

    /* listening to messages from all objects as no path is specified */
    dbus_bus_add_match (bus, "type='signal'", &error);
    dbus_bus_add_match (bus, "type='method_call'", &error);
    dbus_bus_add_match (bus, "type='method_return'", &error);
    dbus_bus_add_match (bus, "type='error'", &error);

    dbus_connection_add_filter (bus, signal_filter, NULL, NULL);

    while(dbus_connection_read_write_dispatch(bus, -1));

    DBUS_MONI_TRACE_ERROR("main", "FINISHED!!!");
    printf("dbus_listener main: FINISHED!\n");

    return 0;
}

static DBusHandlerResult signal_filter (DBusConnection *connection, DBusMessage *message, void *user_data)
{

    print_message(message);

    /* A signal from the bus saying we are about to be disconnected */
    if (dbus_message_is_signal(message, DBUS_INTERFACE_LOCAL, "Disconnected"))
    {
        DBUS_MONI_TRACE_ERROR("DBusHandlerResult", "disconnected.");

        /* Quit */
        exit(0);
    }

    return DBUS_HANDLER_RESULT_HANDLED;

}


/*****************************************************************************
 *
 *   Function Name: vmf_get_time_snapshot(void)
 *
 *   Description:   get the system time
 *
 *   Parameters:
 *
 *   Function Return value: actual time [ns] (from 1970)
 *
 ******************************************************************************/
unsigned64 vmf_get_time_snapshot(void)
{
    unsigned64      ret_val=0;
    struct timespec temp;
    unsigned64      time_ns;


    if (0 == clock_gettime(CLOCK_REALTIME, &temp))
    {
        time_ns = ((unsigned64)temp.tv_sec * (unsigned64)1000000000L) + (unsigned64)temp.tv_nsec;
        ret_val = time_ns;
    }
    else
    {
        /* error! */
        DBUS_MONI_TRACE_ERROR("vmf_get_time_snapshot", "clock_gettime() failed!!!\n");
    }

    return ret_val;

}


/*****************************************************************************
 *
 *   Function Name: vmf_get_time_diff()
 *   Description:   calculate time difference of two snapshots
 *
 *   Parameters:    - start time [ns]
 *                  - end time [ns]
 *   Return:          time difference is ns
 *
 ******************************************************************************/
unsigned64 vmf_get_time_diff(unsigned64 start_time, unsigned64 stop_time)
{
    unsigned64 diff_nsec;

    if (start_time < stop_time)
    {
        diff_nsec = stop_time - start_time;
    }
    else
    {
        diff_nsec = 0;
        DBUS_MONI_TRACE_ERROR("vmf_get_time_diff", "start > stop !!!");
    }

    return diff_nsec;
}


 /*****************************************************************************
 *
 *   Function Name: get_options(int argc, char *argv[])
 *
 *   Description:   parse command line options
 *
 *   Parameters:    arc , argv
 *
 *   Return value:  void
 *
 ******************************************************************************/
bool get_options(int argc, char *argv[])
{
    int c;

    while ((c = getopt(argc, argv, "h")) != -1)
    {
        switch (c)
        {
            case 'h':
                usage();
                return false;
            break;

            default :
                /* unknown option */
                DBUS_MONI_TRACE_ERROR("get_options","%c is an unknown option!", c);
                usage();
                return false;
        }
    }
    return true;
}


/*****************************************************************************
 *
 *   Function Name: usage()
 *
 *   Description:   print usage message to console (stderr)
 *
 *   Parameters:
 *
 *   Return value:  void
 *
 ******************************************************************************/
void usage(void)
{
    DBUS_MONI_TRACE_ERROR("usage", "***************************************************************");
    DBUS_MONI_TRACE_ERROR("usage", "** dbus_moni process                                         **");
    DBUS_MONI_TRACE_ERROR("usage", "***************************************************************");
    DBUS_MONI_TRACE_ERROR("usage", "**                                                           **");
    DBUS_MONI_TRACE_ERROR("usage", "** usage: dbus_moni [options]                                **");
    DBUS_MONI_TRACE_ERROR("usage", "**     -h     this help                                      **");
    DBUS_MONI_TRACE_ERROR("usage", "**                                                           **");
    DBUS_MONI_TRACE_ERROR("usage", "***************************************************************");
}

