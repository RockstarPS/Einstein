
#ifndef _MQ_H_
#define _MQ_H_

#include <time.h>
#include "os_types.h"


#define MQ_RESULT_OK	0x00
#define MQ_RESULT_ERROR 0x88

#ifndef O_RDWR
#define O_RDWR          0x01
#endif

#ifndef O_CREAT
#define O_CREAT         0x02
#endif

#ifndef O_NONBLOCK
#define O_NONBLOCK      0x04
#endif

#define MQ_PRINT(...)       printf("\t\t"); printf(__VA_ARGS__);
#define MQ_PRINT_RAW(...)   printf(__VA_ARGS__);

struct mq_attr
{
    signed32 mq_flags;
    signed32 mq_maxmsg;
    signed32 mq_msgsize;
    signed32 mq_curmsgs;
    signed32 mq_sendwait;
    signed32 mq_recvwait;
};

struct timespec
{
   time_t   tv_sec;
   long     tv_nsec;
};

struct sigevent;




/* global function prototypes */
unsigned8 set_mq_result (unsigned8 how);
unsigned8 set_mq_notify_result (unsigned8 how);
mqd_t mq_open (const unsigned8 *channel_name, signed32 flags, ...);
signed32 mq_close(mqd_t mq_desc);
signed32 mq_send(mqd_t mq_desc, const unsigned8 *msg, signed32 msg_len, unsigned32 prio);
signed32 mq_receive(mqd_t mq_desc, unsigned8 *msg, signed32 msg_len, unsigned32 *prio);
signed32 mq_timedreceive(mqd_t mq_desc, unsigned8 *msg, signed32 msg_len,unsigned32 *prio, const struct timespec *abs_timeout);
signed32 mq_unlink(const char* channel_name);
signed32 mq_notify(mqd_t mqdes,const struct sigevent *notification );

#endif

