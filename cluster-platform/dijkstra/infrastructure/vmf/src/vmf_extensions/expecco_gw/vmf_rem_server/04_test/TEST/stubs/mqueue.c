
#define _MQ_C_


#include "nw_os_config.h"


/* globals */
unsigned8 mq_result = MQ_RESULT_OK;
unsigned8 mq_notify_result = MQ_RESULT_OK;

mqd_t count = 0;
unsigned8 message[9999];
unsigned32 message_length;

/* set all mq_results to OK or ERROR */
unsigned8 set_mq_result (unsigned8 how)
{
    if (MQ_RESULT_OK == how)
    {
        mq_result = MQ_RESULT_OK;
    }
    else
    {
        mq_result = MQ_RESULT_ERROR;
    }

    return (mq_result);
}


/* set mq_notify_result to OK or ERROR */
unsigned8 set_mq_notify_result (unsigned8 how)
{
    if (MQ_RESULT_OK == how)
    {
        mq_notify_result = MQ_RESULT_OK;
    }
    else
    {
        mq_notify_result = MQ_RESULT_ERROR;
    }

    return (mq_notify_result);
}


/* FUNCTION mq_open */
mqd_t mq_open (const unsigned8 *channel_name, signed32 flags, ...)
{

    if (MQ_RESULT_OK == mq_result)
    {
        count = count + 1;
        
        
        MQ_PRINT("mq_open: ");
        
        if (((unsigned32)flags & (unsigned32)O_NONBLOCK) != 0)
        {
            MQ_PRINT("non-blocking");
        }
        else
        {
            MQ_PRINT("blocking");
        }

        if (((unsigned32)flags & (unsigned32)O_CREAT) != 0)
        {
            MQ_PRINT("create");
        }
        else
        {
            MQ_PRINT("no create");
        }

        if (((unsigned32)flags & (unsigned32)O_RDWR) != 0)
        {
            MQ_PRINT("read-write");
        }
        else
        {
            MQ_PRINT("no read-write");
        }
        MQ_PRINT("\n");

        return (mqd_t)count;
    }
    else
    {
        MQ_PRINT("mq_open: error returned\n");
        
        return (mqd_t)(-1);
    }
} 


/* FUNCTION mq_send */
signed32 mq_send(mqd_t mq_desc, const unsigned8 *msg, signed32 msg_len, unsigned32 prio)
{
    unsigned32 i;
    
    if (MQ_RESULT_OK == mq_result)
    {

        MQ_PRINT("mq_send: \n");
        MQ_PRINT("message sent:       ");

        memcpy(message, msg, msg_len);
        message_length = msg_len;

        for (i=0; i<msg_len; i++)
        {
            MQ_PRINT_RAW("%2X ",msg[i]);
        }
        
        MQ_PRINT("\n");

        return (signed32) count;
    }
    else
    {
        MQ_PRINT("mq_send: error returned\n");
        return (signed32) (-1);
    }
}

/* FUNCTION mq_receive */
signed32 mq_receive(mqd_t mq_desc, unsigned8 *msg, signed32 msg_len, unsigned32 *prio)
{
    if (MQ_RESULT_OK == mq_result)
    {
        unsigned32 i;

        MQ_PRINT("mq_receive:\n");

        memcpy(msg, message, message_length);

        MQ_PRINT("message to receive: ");
        for (i=0; i<message_length; i++)
        {
            MQ_PRINT_RAW("%2X ",msg[i]);
        }
        MQ_PRINT("\n");

        return (signed32) message_length;
    }
    else
    {
        MQ_PRINT("mq_receive: error returned\n");
        return (signed32) -1;
    }
}


/* FUNCTION mq_timedreceive */
signed32 mq_timedreceive(mqd_t mq_desc, unsigned8 *msg, signed32 msg_len,
                         unsigned32 *prio, const struct timespec *abs_timeout)
{
    if (MQ_RESULT_OK == mq_result)
    {
        unsigned32 i;

        MQ_PRINT("mq_receive:\n");

        memcpy(msg, message, message_length);

        MQ_PRINT("message to receive: ");
        for (i=0; i<message_length; i++)
        {
            MQ_PRINT_RAW("%2X ",msg[i]);
        }
        MQ_PRINT("\n");

        return (signed32) message_length;
    }
    else
    {
        MQ_PRINT("mq_receive: error returned\n");
        return (signed32) -1;
    }
}



/* FUNCTION mq_close */
signed32 mq_close(mqd_t mq_desc)
{
    if (MQ_RESULT_OK == mq_result)
    {
        MQ_PRINT("mq_close: ok returned\n");
        return (signed32) count;
    }
    else
    {
        MQ_PRINT("mq_close: error returned\n");
        return (signed32) -1;
    }
} 

/* FUNCTION mq_unlink */
signed32 mq_unlink(const char* channel_name)
{
    if (MQ_RESULT_OK == mq_result)
    {
        MQ_PRINT("mq_unlink: ok returned\n");
        return (signed32) count;
    }
    else
    {
        MQ_PRINT("mq_unlink: error returned\n");
        return (signed32) -1;
    }
}



/* FUNCTION mq_notify */
signed32 mq_notify(mqd_t mqdes,const struct sigevent* notification )
{
    if (MQ_RESULT_OK == mq_notify_result)
    {
        MQ_PRINT("mq_notify: ok returned\n");
        return (signed32) count;
    }
    else
    {
        MQ_PRINT("mq_notify: error returned\n");
        return (signed32) -1;
    }
}





#undef _MQ_C_
