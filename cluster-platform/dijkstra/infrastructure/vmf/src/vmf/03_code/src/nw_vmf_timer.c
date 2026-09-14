/*****************************************************************************/
/* Copyright Statement                                                       */
/* CONFIDENTIAL - VISTEON CORPORATION                                        */
/* This is an unpublished work, which contains trade secrets, created in     */
/* 2008. Visteon Corporation owns all rights to this work and intends        */
/* to maintain it in confidence to preserve its trade secret status. Visteon */
/* Corporation reserves the right, under the copyright laws of the United    */
/* States or those of any other country that may have jurisdiction, to       */
/* protect this work as an unpublished copyright work in the event of an     */
/* inadvertent or deliberate unauthorized publication. Visteon Corporation   */
/* also reserves its rights under the copyright laws to protect this work    */
/* as a published work, when appropriate. Those having access to this work   */
/* may not copy it, use it or disclose the information contained in it       */
/* without the written authorization of Visteon Corporation.                 */
/*****************************************************************************/

/***************************************************************************

  Module:               nw_vmf_time.c
  Description:          timer the message framework lib

  Project Scope:        VMF

  Organization:         Visteon Deutschland GmbH, Infotainment Software
  Author:               Joachim Becker

  Compiler/Assembler:   gcc
  Target Hardware:      Any

  *****************************************************************************/
#define VMF_TIME_C

#include "nw_os_config.h"
#include "nw_vmf_cfg.h"
#include "nw_vmf.h"
#include "nw_vmf_timer.h"

/* macros */
#define VMF_MAX_TIMERS          20
#define VMF_TIMER_STACK_SIZE    VMF_NW_STACK_SIZE
#define VMF_TIMER_DELAY_TIME    50                      /* delay time in ms     */
#define VMF_TIMER_DELAY_TIMEOUT 1000                    /* timeout time in ms   */

#define VMF_TIMER_CONSOLE_DEBUG
#define DO_DEBUG

#define VMF_TIMER_ERROR_C(...)    (void)fprintf(ERROR_CHANNEL, "vmf_timer error: "); (void)fprintf(ERROR_CHANNEL, __VA_ARGS__); (void)fprintf(ERROR_CHANNEL, "\n");

#ifdef VMF_TIMER_CONSOLE_DEBUG
  #define VMF_TIMER_PRINTF(...)   // (void)fprintf(ERROR_CHANNEL, "vmf_timer debug: "); (void)fprintf(ERROR_CHANNEL, __VA_ARGS__); (void)fprintf(ERROR_CHANNEL, "\n");
  #define VMF_TIMER_PRINTF2(...)  // (void)fprintf(ERROR_CHANNEL, "vmf_timer debug: "); (void)fprintf(ERROR_CHANNEL, __VA_ARGS__); (void)fprintf(ERROR_CHANNEL, "\n");
  #define VMF_TIMER_ERROR(...)    (void)fprintf(ERROR_CHANNEL, "vmf_timer error: "); (void)fprintf(ERROR_CHANNEL, __VA_ARGS__); (void)fprintf(ERROR_CHANNEL, "\n");
#else 
  #define VMF_TIMER_TASK          "vmf"
  #define VMF_TRACE_GL_SCOPE      "vmf_timer"
  #define VMF_TRACE_TIMER_SCOPE   (char *)__PRETTY_FUNCTION__
  #define VMF_TIMER_ERROR( ...)   VMF_TRACE_PRINTF(trid, VMF_TRACE_SEVERITY_ERROR, VMF_TRACE_GL_SCOPE, VMF_TRACE_TIMER_SCOPE, __VA_ARGS__);
  #define VMF_TIMER_PRINTF( ...)  VMF_TRACE_PRINTF(trid, VMF_TRACE_SEVERITY_INFO, VMF_TRACE_GL_SCOPE, VMF_TRACE_TIMER_SCOPE,  __VA_ARGS__);
  #define VMF_TIMER_PRINTF2( ...)
#endif


#define VMF_TIMER_MUX_LOCK(mux)                         \
    if (pthread_mutex_lock(mux) != 0)                   \
    {                                                   \
        VMF_TIMER_ERROR("pthread_mutex_lock failed");   \
    }                                                   \


#define VMF_TIMER_MUX_UNLOCK(mux)                       \
    if (pthread_mutex_unlock(mux) != 0)                 \
    {                                                   \
        VMF_TIMER_ERROR("pthread_mutex_unlock failed"); \
    }                                                   \
    
 
/* own types */ 

#ifdef INTEGRITY

/* Timer task */
Task    vmf_timer_task;

/* Timerhandler struct */
typedef struct vmf_timer_handler_struct {
    long val;
    Object (*pHandler)();
} vmf_timer_handler_t;

#endif

/*****************************************************************************
 * timer object                             
 *****************************************************************************/
typedef struct
{
    unsigned16      num;
    timer_t         timer_id;
    unsigned32      start_time;                 /* start time of the timer in ms            */
    unsigned32      asked_time;                 /* timer diff time in ms                    */
    pthread_attr_t  attr;                       /* attr for the timer thread                */
    void            (*callback)(unsigned32 system_time_ms,void * arg); /* user callback */
    void            *arg;                       /* user arg for the user callback           */
#ifdef INTEGRITY
    vmf_timer_handler_t timer_handler;          /* timer handler where user callback is called */
    Clock               alarm_clock;            /* the timer */
    Activity            timer_activity;         /* activity to bind timer and handler to a task/thread */
    Time                timeout;                /* timeout in fixed point seconds.fraction */
#else 
    struct          sigevent timer_event;       /* sigevent struct of the timer             */
#endif     
    pthread_mutex_t mutex;                      /* mutex to protect timer functions         */
    bool            in_use;                     /* true if this timer is in use             */
    bool            started;                    /* true if this timer is in use             */
    bool            in_callback;                /* true if in callback context              */
}vmf_timer_t;


/* local data */
static vmf_timer_t timers[VMF_MAX_TIMERS];
static pthread_mutex_t   timer_mux = PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t   timer_mux_hl = PTHREAD_MUTEX_INITIALIZER;
static bool init_done = false;
#ifndef VMF_TIMER_CONSOLE_DEBUG
static unsigned8 trid=0;
#endif
/* local function prototypes */
static vmf_ret_t nw_vmf_init_timers         (void);
static vmf_ret_t nw_vmf_get_timer           (unsigned16 vmf_timer_id,vmf_timer_t **pptimer);
static vmf_ret_t nw_vmf_get_free_timer      (vmf_timer_t **pptimer);
static vmf_ret_t nw_vmf_get_free_timer_wait (vmf_timer_t **pptimer);
static vmf_ret_t nw_vmf_free_timer          (vmf_timer_t *ptimer);
static vmf_ret_t nw_vmf_disarm_timer        (vmf_timer_t *ptimer);
static void      nw_vmf_monitor_all_timers  (void);

#ifdef __WINDOWS__
VOID   CALLBACK  timer_callback (PVOID param, BOOLEAN timerOrWaitFired );
#elif defined INTEGRITY
static void nw_vmf_integrity_timer_create_thread(void);
static void nw_vmf_timer_task_handler(void);
static void nw_vmf_timer_convert_ms_to_time (unsigned32 in_milliseconds, Time * out_time);
Object nw_vmf_timer_alarm_handler(vmf_timer_handler_t* arg);
#else
static void timer_callback (union sigval sig);
#endif



/*****************************************************************************
 *                             global functions                              *
 *                                                                           *
 *****************************************************************************/


/*************************************************************************//**
 *
 *   start a timer \n
 *   NOTE: callback is called after timer elapsed
 *   the callback prototype has to be
 *   void (*nw_vmf_on_timer)(unsigned32 system_time_ms,void *arg)
 *   arg1 = system_time_ms = the current system time in ms
 *   arg2 = void *arg = a pointer for free usage by the client
 *
 *   \param[out]unsigned16 *time_id -- pointer to timer-id or NULL
 *   \param[in] time_in_ms          -- time in ms
 *   \param[in] nw_gw_on_timer      -- on-timer callback
 *   \param[in] void * arg          -- tis pointer is forwarded to the timer callback
 *   \return    vmf_ret_t           -- vmf error type of VMF_OK
 *
 ******************************************************************************/
vmf_ret_t vmf_timer_start (unsigned16 *ptimer_id, unsigned32 time_in_ms, void (*nw_vmf_on_timer)(unsigned32 system_time_ms,void *arg),void *arg)
{
    vmf_ret_t   vmf_ret_val = VMF_OK;
    vmf_timer_t *ptimer;

#ifdef INTEGRITY
    Error       integrity_ret_val;
    Time        integrity_timeout;
#else    
    int         ret_val;
#endif        

    VMF_TIMER_PRINTF("vmf_timer_start()");
    
    
#ifndef VMF_TIMER_CONSOLE_DEBUG
    if (0==trid)
    {
        /* Register at VMF Tracer */
        if (VMF_TRACE_REGISTER(&trid, VMF_TIMER_TASK) < 0)
        {
             VMF_TIMER_ERROR_C("vmf_timer: CANNOT CONNECT TO VMF TRACER!!!");
        }
    }
#endif

    VMF_TIMER_MUX_LOCK(&timer_mux_hl);

    /* argument check */
    if (NULL == nw_vmf_on_timer)
    {
        vmf_ret_val = VMF_ERR_NULL_POINTER;
    }

    if (0 == time_in_ms)
    {   
        time_in_ms = 1;                              /* set to 1 ms */       
    }

    if (VMF_OK == vmf_ret_val)
    {
        vmf_ret_val = nw_vmf_get_free_timer_wait(&ptimer);
        if (VMF_OK != vmf_ret_val)
        {
            VMF_TIMER_ERROR("vmf_timer_start() nw_vmf_get_free_timer_wait() failed");
        } 
        else if (NULL == ptimer)
        {
            VMF_TIMER_ERROR("vmf_timer_start() nw_vmf_get_free_timer_wait() returned NULL pointer");
            vmf_ret_val = VMF_ERROR;
        }
    }
    
    if (VMF_OK == vmf_ret_val)
    {
        VMF_TIMER_PRINTF ("vmf_timer_start() - nw_vmf_get_free_timer_wait(): got timer %d",ptimer->num);    

        /* store vmf timer-id if needed */
        if (NULL != ptimer_id)
        {
            *ptimer_id = ptimer->num;
        }
        
        /* setup timer-event*/
#ifdef INTEGRITY

        ptimer->callback                            = nw_vmf_on_timer;              
        ptimer->arg                                 = arg;              
        ptimer->asked_time                          = time_in_ms;
        ptimer->start_time                          = nw_os_cfg_get_ms_time();

        integrity_ret_val = CreateVirtualClock(HighestResStandardClock, CLOCK_READTIME|CLOCK_ALARM, &ptimer->alarm_clock);
        if (integrity_ret_val != Success)
        {
            printf("vmf_timer_start() CreateVirtualClock() Error = %d \n", integrity_ret_val);
            VMF_TIMER_ERROR("vmf_timer_start() CreateVirtualClock() Error = %d", integrity_ret_val);
            vmf_ret_val = VMF_ERROR;
        }
        else
        {
            ptimer->timer_handler.val = ptimer->num;
            ptimer->timer_handler.pHandler = nw_vmf_timer_alarm_handler;

            integrity_ret_val = CreateActivity(vmf_timer_task, 2, true, (Value) &ptimer->timer_handler, &ptimer->timer_activity);
            if (integrity_ret_val != Success)
            {
                printf("vmf_timer_start() CreateActivity() Error = %d", integrity_ret_val);
                VMF_TIMER_ERROR("vmf_timer_start() CreateActivity() Error = %d", integrity_ret_val);
                vmf_ret_val = VMF_ERROR;
            }
            else
            {
                integrity_ret_val = AsynchronousReceive(ptimer->timer_activity, (Object) ptimer->alarm_clock, NULL);
                if (integrity_ret_val != Success)
                {
                    printf("vmf_timer_start() AsynchronousReceive() Error = %d", integrity_ret_val);
                    VMF_TIMER_ERROR("vmf_timer_start() AsynchronousReceive() Error = %d", integrity_ret_val);
                    vmf_ret_val = VMF_ERROR;
                }
                else
                {
                    VMF_TIMER_MUX_LOCK(&(ptimer->mutex));
                    nw_vmf_timer_convert_ms_to_time(time_in_ms, &integrity_timeout); 
                    ptimer->timeout.Seconds = integrity_timeout.Seconds;
                    ptimer->timeout.Fraction = integrity_timeout.Fraction;
                    integrity_ret_val = SetClockAlarm(ptimer->alarm_clock, false, NULLTime, &ptimer->timeout);
                    if (integrity_ret_val != Success)
                    {
                        printf("vmf_timer_start() SetClockAlarm() Error = %d", integrity_ret_val);
                        VMF_TIMER_ERROR("vmf_timer_start() SetClockAlarm() Error = %d", integrity_ret_val);
                        vmf_ret_val = VMF_ERROR;
                    }
                    else
                    {
                        ptimer->started = true;
                    }
                    VMF_TIMER_MUX_UNLOCK(&(ptimer->mutex));
                }
            }
        }

#else
        memset(&(ptimer->timer_event), 0, sizeof(struct sigevent));
        ptimer->timer_event.sigev_notify            = SIGEV_THREAD;
        ptimer->timer_event.sigev_value.sival_ptr   = (void *)ptimer;
        ptimer->timer_event.sigev_notify_function   = (void *)timer_callback;
        ptimer->timer_event.sigev_notify_attributes = &(ptimer->attr);                
        ptimer->callback                            = nw_vmf_on_timer;              
        ptimer->arg                                 = arg;              
        ptimer->asked_time                          = time_in_ms;
        ptimer->start_time                          = nw_os_cfg_get_ms_time();

        /* setup the timer */
        ret_val = timer_create (CLOCK_REALTIME, &(ptimer->timer_event), &(ptimer->timer_id));
        if (ret_val != 0)
        {
            /* timer_create failed */
            VMF_TIMER_ERROR("vmf_timer_start() timer_create() failed");
            perror("timer_create");
            vmf_ret_val = VMF_ERROR;
        }
        else
        {
            struct itimerspec tsp;

            VMF_TIMER_PRINTF("vmf_timer_start(%d) time=%d",ptimer->timer_id,time_in_ms);
            /* convert time_in_ms to itimerspec */
            memset(&tsp, 0, sizeof (struct itimerspec));
            tsp.it_value.tv_sec  = (time_in_ms/1000);
            tsp.it_value.tv_nsec = (time_in_ms - (tsp.it_value.tv_sec*1000)) * 1000000L;
            
            VMF_TIMER_PRINTF("vmf_timer_start(%d) call timer_settime with %dms",ptimer->timer_id,time_in_ms);
            
            VMF_TIMER_MUX_LOCK(&(ptimer->mutex));

            ret_val = timer_settime(ptimer->timer_id, 0, &tsp, NULL);
            if (ret_val != 0)
            {
                /* timer_settime failed */
                VMF_TIMER_ERROR("vmf_timer_start() timer_settime() failed");
                vmf_ret_val = VMF_ERROR;
            }
            else
            {
                ptimer->started = true;
            }

            VMF_TIMER_MUX_UNLOCK(&(ptimer->mutex));
        }
#endif
    }

    VMF_TIMER_MUX_UNLOCK(&timer_mux_hl);
    return  vmf_ret_val;
}



/*************************************************************************//**
 *
 *   stop a timer \n
 *
 *   \param[in] unsigned16 time_id  -- vmf-timer-id
 *
 *   \return    vmf_ret_t           -- vmf error type of VMF_OK
 *
 ******************************************************************************/
vmf_ret_t vmf_timer_stop (unsigned16 vmf_timer_id)
{
    vmf_ret_t vmf_ret = VMF_OK;
    vmf_timer_t *ptimer;    

    VMF_TIMER_MUX_LOCK(&timer_mux_hl);
    VMF_TIMER_PRINTF("vmf_timer_stop");

    if (false == init_done)
    {
        vmf_ret = VMF_ERR_TIMER_INVALID;
    }
    else if (VMF_INVALID_TIMER == vmf_timer_id)
    {
        vmf_ret = VMF_ERR_TIMER_INVALID;
    }
    
    /* get the timer */
    if (VMF_OK == vmf_ret)
    {
        vmf_ret = nw_vmf_get_timer(vmf_timer_id,&ptimer); 
    }
    if (VMF_OK == vmf_ret)
    {
        if (true == ptimer->in_callback)
        {
            /* in context of callback -- ignore! */
            vmf_ret = VMF_ERR_TIMER_INVALID;
        }
        else if (false == ptimer->in_use)
        {
            /* timer not in use */
            VMF_TIMER_PRINTF("vmf_timer_stop(%d) timer not is in use!",ptimer->timer_id);
            vmf_ret = VMF_ERR_TIMER_INVALID;
        }
        else if (false == ptimer->started)
        {
            /* timer not started */
            VMF_TIMER_PRINTF("vmf_timer_stop(%d) timer not running!",ptimer->timer_id);
            vmf_ret = VMF_ERR_TIMER_INVALID;
        }
        else 
        {
            VMF_TIMER_PRINTF("vmf_timer_stop(%d) timer is in use!",ptimer->timer_id);
        }
    }
    /* disarm the timer */
    if (VMF_OK == vmf_ret)
    {
        VMF_TIMER_PRINTF("vmf_timer_stop(%d) time=%d",ptimer->timer_id,0);
        vmf_ret = nw_vmf_disarm_timer(ptimer);
    }
    /* free the timer */
    if (VMF_OK == vmf_ret)
    {
        vmf_ret = nw_vmf_free_timer(ptimer);
    }

    if (VMF_OK == vmf_ret)
    {
        VMF_TIMER_PRINTF ("vmf_timer_stop: stopped vmf_timer%d",vmf_timer_id);   
    }
    VMF_TIMER_MUX_UNLOCK(&timer_mux_hl);
    
    return vmf_ret;
}


/*************************************************************************//**
 *
 *   set a new timer value only if set time is smaller then residual time\n
 *
 *   \param[in] unsigned16 time_id  -- vmf-timer-id
 *
 *   \return    vmf_ret_t           -- vmf error type of VMF_OK
 *
 ******************************************************************************/
vmf_ret_t vmf_timer_set_if_smaller (unsigned16 vmf_timer_id, unsigned32 time_in_ms)
{
    vmf_timer_t *p_vmf_timer = NULL;    
    unsigned32 current_time=0;
    unsigned32 elapsed_time=0;
    signed32   left_time=0;
    
    vmf_ret_t   vmf_ret = VMF_OK;

    if (false == init_done)
    {
        return VMF_ERR_TIMER_INVALID;
    }
    else if (VMF_INVALID_TIMER == vmf_timer_id)
    {
        VMF_TIMER_PRINTF2("vmf_timer_set_if_smaller()  VMF_INVALID_TIMER!");
        return VMF_ERR_TIMER_INVALID;
    }
    
    /* get pointer to vmf timer */
    vmf_ret = nw_vmf_get_timer(vmf_timer_id,&p_vmf_timer); 
    if (NULL == p_vmf_timer)
    {
        /* invalid vmf timer */
        VMF_TIMER_PRINTF2("vmf_timer_set_if_smaller()  p_vmf_timer=NULL!!");
        return VMF_ERR_NULL_POINTER;
    }
    
    if (true == p_vmf_timer->in_callback)
    {
        /* in context of callback -- ignore! */
        vmf_ret = VMF_ERR_TIMER_INVALID;
    }
    else
    {
        /* calculate elapsed and residual time */
        current_time = nw_os_cfg_get_ms_time();
        if (current_time > p_vmf_timer->start_time)
        {
            elapsed_time =  current_time - (p_vmf_timer->start_time); 
            left_time =  p_vmf_timer->asked_time - elapsed_time;
            VMF_TIMER_PRINTF("vmf_timer_set_if_smaller: asked_time=%d, elapsed_time=%d, left_time=%d",p_vmf_timer->asked_time,elapsed_time,left_time);    
        }
        
        /* set timer only if left time is bigger then new time */
        if ((signed32)time_in_ms < left_time)
        {
            VMF_TIMER_PRINTF2 ("vmf_timer_set_if_smaller: set time=%d, asked_time=%d, elapsed_time=%d, left_time=%d",time_in_ms,p_vmf_timer->asked_time,elapsed_time,left_time);    
            vmf_ret = vmf_timer_set(vmf_timer_id,time_in_ms);
        }
        else
        {
            VMF_TIMER_PRINTF2 ("vmf_timer_set_if_smaller: ignore time=%d, asked_time=%d, elapsed_time=%d, left_time=%d",time_in_ms,p_vmf_timer->asked_time,elapsed_time,left_time);    
        }
    }
    
    return vmf_ret;
}

/*************************************************************************//**
 *
 *   set a new timer value\n
 *
 *   \param[in] unsigned16 time_id  -- vmf-timer-id
 *
 *   \return    vmf_ret_t           -- vmf error type of VMF_OK
 *
 ******************************************************************************/
vmf_ret_t vmf_timer_set (unsigned16 vmf_timer_id, unsigned32 time_in_ms)
{
    vmf_ret_t   vmf_ret = VMF_OK;
    vmf_timer_t *ptimer = NULL;    

#ifdef INTEGRITY
    Error       integrity_ret_val;
#else
    int         ret_val = 0;
#endif    


    VMF_TIMER_MUX_LOCK(&timer_mux_hl);
    
    if (false == init_done)
    {
        vmf_ret = VMF_ERR_TIMER_INVALID;
    }
    else if (VMF_INVALID_TIMER == vmf_timer_id)
    {
        vmf_ret = VMF_ERR_TIMER_INVALID;
    }
    
    /* get the timer */
    if (VMF_OK == vmf_ret)
    {
        vmf_ret = nw_vmf_get_timer(vmf_timer_id,&ptimer); 
    }

    if (VMF_OK == vmf_ret)
    {
        if (true == ptimer->in_callback)
        {
            /* in context of callback -- ignore! */
            vmf_ret = VMF_ERR_TIMER_INVALID;
        }
        else
        {

            if (false != ptimer->started)
            {
#ifdef INTEGRITY
                Time  integrity_timeout;

                VMF_TIMER_PRINTF("vmf_timer_set(%d) time=%d",ptimer->timer_id,time_in_ms);

                ptimer->asked_time   = time_in_ms;
                ptimer->start_time = nw_os_cfg_get_ms_time();

                nw_vmf_timer_convert_ms_to_time(time_in_ms, &integrity_timeout); 
                ptimer->timeout.Seconds = integrity_timeout.Seconds;
                ptimer->timeout.Fraction = integrity_timeout.Fraction;
                integrity_ret_val = SetClockAlarm(ptimer->alarm_clock, false, NULLTime, &ptimer->timeout);
                if (integrity_ret_val != Success)
                {
                    printf("vmf_timer_set Error = %d \n", integrity_ret_val);
                    VMF_TIMER_ERROR("vmf_timer_set() SetClockAlarm Error = %d", integrity_ret_val);
                }
                else
                {
                    ptimer->started = true;
                }

#else                
                struct itimerspec tsp;

                VMF_TIMER_PRINTF("vmf_timer_set(%d) time=%d",ptimer->timer_id,time_in_ms);
                /* convert time_in_ms to itimerspec */
                memset(&tsp, 0, sizeof (struct itimerspec));
                tsp.it_value.tv_sec  = (time_in_ms/1000);
                tsp.it_value.tv_nsec = (time_in_ms - (tsp.it_value.tv_sec*1000)) * 1000000L;
                ptimer->asked_time   = time_in_ms;
                ptimer->start_time = nw_os_cfg_get_ms_time();

                ret_val = timer_settime(ptimer->timer_id, 0, &tsp, NULL);
                if (ret_val != 0)
                {
                    /* timer_settime failed */
                    VMF_TIMER_ERROR("vmf_timer_set() timer_settime() failed");
                    vmf_ret = VMF_ERROR;
                }
                else
                {
                    ptimer->started = true;
                }
#endif
            }
            else
            {
                VMF_TIMER_PRINTF("vmf_timer_set(%d) time=%d timer not set because it is not running",ptimer->timer_id,time_in_ms);
            }
        }
    }
    
    VMF_TIMER_MUX_UNLOCK(&timer_mux_hl);

    return vmf_ret;
}



/*****************************************************************************
 *                              local functions                              *
 *                                                                           *
 *****************************************************************************/

/*************************************************************************//**
 *
 *   init all timer \n
 *
 *
 *   \param[in]     void          
 *   \return        vmf_ret_t
 *
 ******************************************************************************/
static vmf_ret_t nw_vmf_init_timers(void)
{
    int i;
    
    VMF_TIMER_MUX_LOCK(&timer_mux);
    if (false == init_done)
    {
        for (i = 0; i< VMF_MAX_TIMERS; i++)
        {
            if (pthread_attr_init(&(timers[i].attr)) != 0)
            {
                VMF_TIMER_ERROR("pthread_attr_init() failed");
            }

            #ifndef __ANDROID__
            /* set stack size in attr */
            if (pthread_attr_setstacksize(&(timers[i].attr), VMF_TIMER_STACK_SIZE) != 0)
            {
                VMF_TIMER_ERROR("pthread_attr_setstacksize() failed");
            }
            #endif

            (void) pthread_mutex_init(&(timers[i].mutex),NULL);
            timers[i].timer_id = 0;
            timers[i].callback = NULL;
            timers[i].num = i;
            timers[i].in_use = false;  
            timers[i].started = false;
            timers[i].in_callback = false;  

#ifdef INTEGRITY
            timers[i].timer_handler.val = 0;
            timers[i].timer_handler.pHandler = NULL;
            timers[i].alarm_clock = NULLClock;
            timers[i].timer_activity = NULLActivity;
            timers[i].timeout.Seconds = 0;
            timers[i].timeout.Fraction = 0;            
#endif

        }
        init_done = true;   

#ifdef INTEGRITY
        nw_vmf_integrity_timer_create_thread();
#endif

    }
    VMF_TIMER_MUX_UNLOCK(&timer_mux);
    VMF_TIMER_PRINTF("nw_vmf_init_timers()");
    return VMF_OK;
}



/*************************************************************************//**
 *
 *   get a free timer \n
 *   the returned timer is marked as "in use"
 *
 *   \param[out]    pointer to timer number           
 *   \return        vmf_ret_t
 *
 ******************************************************************************/
static vmf_ret_t nw_vmf_get_free_timer(vmf_timer_t **pptimer)
{
    vmf_ret_t vmf_ret = VMF_OK;
    int i;

    VMF_TIMER_PRINTF("nw_vmf_get_free_timer()");

    /* argument check */
    if (NULL == pptimer)
    {
        VMF_TIMER_ERROR("nw_vmf_get_free_timer()) ptimer=NULL");
        vmf_ret = VMF_ERR_NULL_POINTER;
    }
    else if(false == init_done)
    {
        /* init all timers */
        vmf_ret = nw_vmf_init_timers();
    }
    else
    {
    }
    
    if(VMF_OK == vmf_ret)
    {
    	/* search for a free timer */
    	VMF_TIMER_MUX_LOCK(&timer_mux);
    	*pptimer = NULL;
    	vmf_ret = VMF_ERR_NO_FREE_TIMER;
    	for (i = 0; i< VMF_MAX_TIMERS; i++)
    	{
    		if (timers[i].in_use == false)
    		{
    			/* found a free timer */
    			timers[i].in_use = true;
    			timers[i].start_time = nw_os_cfg_get_ms_time();
    			*pptimer = &timers[i];
    			vmf_ret = VMF_OK;
    			break;
    		}
    	}
    	VMF_TIMER_MUX_UNLOCK(&timer_mux);
    }
   
    return vmf_ret;
}



/*************************************************************************//**
 *
 *   get a timer \n
 *   
 *
 *   \param[out]    pointer to timer            
 *   \return        vmf_ret_t
 *
 ******************************************************************************/
static vmf_ret_t nw_vmf_get_timer(unsigned16 vmf_timer_id,vmf_timer_t **pptimer)
{
    vmf_ret_t vmf_ret = VMF_OK;
    
    if (false == init_done)
    {
        /* init all timers */
        (void) nw_vmf_init_timers();
        return VMF_ERR_TIMER_INVALID;
    }
    else if (vmf_timer_id == VMF_INVALID_TIMER)
    {
        return VMF_ERR_TIMER_INVALID;
    }
    else if (vmf_timer_id >= VMF_MAX_TIMERS)
    {
        VMF_TIMER_ERROR("nw_vmf_get_timer() invalid timer id = %d",vmf_timer_id);
        return VMF_ERR_TIMER_INVALID;
    }
    
    if (NULL == pptimer)
    {
        VMF_TIMER_ERROR("nw_vmf_get_timer() ipptimer = NULL");
        vmf_ret = VMF_ERR_NULL_POINTER;
    }
    else
    {
        *pptimer = &timers[vmf_timer_id];
        
        if (false == timers[vmf_timer_id].in_use)
        {
            vmf_ret = VMF_ERR_TIMER_INVALID;
        }
    }
        
    return vmf_ret;    
}


/*************************************************************************//**
 *
 *   wait for a free timer  \n
 *   the max waiting time is defined in VMF_TIMER_DELAY_TIMEOUT
 *
 *   \param[out]    pointer to timer number           
 *   \return        vmf_ret_t
 *
 ******************************************************************************/
static vmf_ret_t nw_vmf_get_free_timer_wait(vmf_timer_t **pptimer)
{
    vmf_ret_t   vmf_ret = VMF_TIMER_ERR_TIMEOUT;
    unsigned32  timeout=0;
 
    if (NULL == pptimer)
    {
        VMF_TIMER_ERROR("nw_vmf_get_free_timer_wait() pptimer = NULL");
        return VMF_ERR_NULL_POINTER;
    }
    
    *pptimer = NULL;
    while (timeout < VMF_TIMER_DELAY_TIMEOUT)
    {
        vmf_ret = nw_vmf_get_free_timer(pptimer);
        if (VMF_OK == vmf_ret)
        {
            VMF_TIMER_PRINTF ("nw_vmf_get_free_timer_wait: got free timer");    
            break;
        }
        delay(VMF_TIMER_DELAY_TIME);
        timeout += VMF_TIMER_DELAY_TIME;
    }
    
#ifdef DO_DEBUG
    if (VMF_OK != vmf_ret)
    {
        VMF_TIMER_PRINTF ("nw_vmf_get_free_timer_wait: no free timer available");    
        nw_vmf_monitor_all_timers();
    }
#endif    
    
    
    return vmf_ret;
}


/*************************************************************************//**
 *
 *   monitor all timers \n
 *   
 *
 *   \param[out]    void          
 *   \return        void
 *
 ******************************************************************************/
static void nw_vmf_monitor_all_timers(void)
{
#ifdef DO_DEBUG
    int i;
    unsigned32 elapsed_time=0;
    unsigned32 current_time=0;
    
    UNUSED_PARAM(elapsed_time);
    current_time = nw_os_cfg_get_ms_time();

    for (i = 0; i< VMF_MAX_TIMERS; i++)
    {
        if (timers[i].in_use == true)
        {
            /* found a used timer */
            elapsed_time =  current_time - timers[i].start_time; 
            VMF_TIMER_PRINTF ("nw_vmf_monitor_all_timer: timer %d, started at %dms, asked time=%dms, running for %dms",i,timers[i].start_time,timers[i].asked_time,elapsed_time );    
        }
    }
#endif
}



/*************************************************************************//**
 *
 *   free a timer \n
 *
 *   \param[out]    pointer to timer number           
 *   \return        vmf_ret_t
 *
 ******************************************************************************/
static vmf_ret_t nw_vmf_free_timer(vmf_timer_t *ptimer)
{
    vmf_ret_t   vmf_ret = VMF_OK;

    VMF_TIMER_PRINTF("nw_vmf_free_timer");
    
    /* argument check */
    if (NULL == ptimer)
    {
        VMF_TIMER_ERROR("nw_vmf_free_timer()  ptimer=NULL!!");
        vmf_ret = VMF_ERR_NULL_POINTER;
    }
    else if (false == ptimer->in_use)
    {
        VMF_TIMER_PRINTF("nw_vmf_free_timer()  timer not running!!");
        vmf_ret = VMF_ERR_TIMER_INVALID;
    }

    if (VMF_OK == vmf_ret)
    {
#ifndef INTEGRITY
        if (timer_delete(ptimer->timer_id) != 0)
        {
            VMF_TIMER_ERROR("nw_vmf_free_timer() timer_delete(vmf_timer_no =%d) failed",ptimer->num);
        }
#endif        
        ptimer->timer_id = 0;
        ptimer->arg      = NULL;
        ptimer->callback = NULL;
        ptimer->in_use   = false;
    }
    
    return vmf_ret;
}



/*************************************************************************//**
 *
 *   disarm a timer \n
 *
 *   \param[out]    pointer to timer number           
 *   \return        vmf_ret_t
 *
 ******************************************************************************/
static vmf_ret_t nw_vmf_disarm_timer(vmf_timer_t *ptimer)
{
    vmf_ret_t   vmf_ret_val = VMF_OK;

#ifdef INTEGRITY
    Error       integrity_ret_val;
#else
    int         ret_val;
    struct itimerspec tsp;
#endif    
        
    /* argument check */
    if (NULL == ptimer)
    {
        VMF_TIMER_ERROR("nw_vmf_disarm_timer()  ptimer=NULL!!");
        return VMF_ERR_NULL_POINTER;
    }

    VMF_TIMER_MUX_LOCK(&(ptimer->mutex));
    if (false == ptimer->in_use)
    {
        VMF_TIMER_ERROR("nw_vmf_disarm_timer()  timer not running!!");
        vmf_ret_val = VMF_ERR_TIMER_INVALID;
    }

    if (VMF_OK == vmf_ret_val)
    {
        /* convert time_in_ms to itimerspec */
        
        VMF_TIMER_PRINTF("nw_vmf_disarm_timer(%d)",ptimer->timer_id);

#ifdef INTEGRITY
        integrity_ret_val = SetClockAlarm(ptimer->alarm_clock, false, NULLTime, NULLTime);
        if (integrity_ret_val != Success)
        {
            /* timer_settime failed */
            VMF_TIMER_ERROR("nw_vmf_disarm_timer() timer_settime() failed");
            perror("timer_settime()");
            vmf_ret_val = VMF_ERROR;
        }
        else
        {
            ptimer->started = false;
        }
#else            
        memset(&tsp, 0, sizeof (struct itimerspec));
        tsp.it_value.tv_sec  = 0;
        tsp.it_value.tv_nsec = 0;

        ret_val = timer_settime(ptimer->timer_id, 0, &tsp, NULL);
        if (ret_val != 0)
        {
            /* timer_settime failed */
            VMF_TIMER_ERROR("nw_vmf_disarm_timer() timer_settime() failed");
            perror("timer_settime()");
            vmf_ret_val = VMF_ERROR;
        }
        else
        {
            ptimer->started = false;
        }
#endif        
    }
    VMF_TIMER_MUX_UNLOCK(&(ptimer->mutex));
    return vmf_ret_val;
}



#ifdef __WINDOWS__

VOID CALLBACK TimerRoutine2(PVOID lpParam, BOOLEAN TimerOrWaitFired)
{
      VMF_TIMER_PRINTF("TimerRoutine2()");
}
 
/*************************************************************************//**
 *
 *   timer callback - windows version \n
 *   NOTE: the registered user callback is called from this timer callback
 *   The user-callback is protected by mutexes 
 *
 *
 *   \param[in]     sigval
 *   \return        void
 *
 ******************************************************************************/
VOID CALLBACK timer_callback  (PVOID param, BOOLEAN timerOrWaitFired )
{
    vmf_timer_t  * p_vmf_timer;
    unsigned32 current_time;
    VMF_TIMER_PRINTF ("timer-callback()");    

    /* get pointer to vmf timer */
    p_vmf_timer = param;
    if (NULL == p_vmf_timer)
    {
        /* invalid vmf timer */
        VMF_TIMER_PRINTF("timer_callback()  p_vmf_timer=NULL!!");
        return;
    }


    /* call the user callback */
    current_time = nw_os_cfg_get_ms_time();
    VMF_TIMER_MUX_LOCK(&(p_vmf_timer->mutex));
    if (NULL != p_vmf_timer->callback)
    {
        /* remind that we are in context of callback! */
        p_vmf_timer->in_callback = true;
        p_vmf_timer->callback(current_time,p_vmf_timer->arg);
        p_vmf_timer->in_callback = false;
    }
    else
    {
        VMF_TIMER_PRINTF("callback == NULL");
    }
 
    VMF_TIMER_PRINTF("timer_callback(%d)",p_vmf_timer->timer_id);
    
    /* free the vmf timer */
    VMF_TIMER_PRINTF("timer_callback() call nw_vmf_free_timer()");
    (void) nw_vmf_free_timer(p_vmf_timer);
    VMF_TIMER_PRINTF("timer_callback() call nw_vmf_free_timer() done");
    VMF_TIMER_MUX_UNLOCK(&(p_vmf_timer->mutex));

}

#elif defined INTEGRITY


/*************************************************************************//**
 *
 *   nw_vmf_integrity_timer_create_thread \n
 *   Create (main) thread for Integrity timers. 
 *
 *
 *   \param[in]     void
 *   \return        void
 *
 ******************************************************************************/
static void nw_vmf_integrity_timer_create_thread(void)
{
    CommonCreateTask(127, (Address)nw_vmf_timer_task_handler, 0x1000, "timer", &vmf_timer_task);
    RunTask(vmf_timer_task);

/* jmerkle TBD: check return values! */

    return;
}

/*************************************************************************//**
 *
 *   nw_vmf_timer_task_handler \n
 *   This is the (main) thread for Integrity timers.  
 *   It's just there to allocate ressources needed by OS.
 *
 *   \param[in]     void
 *   \return        void
 *
 ******************************************************************************/
static void nw_vmf_timer_task_handler(void)
{
    while (1)
    {
        delay(5000);
    } 
}



/*************************************************************************//**
 *
 *   nw_vmf_timer_task_handler \n
 *   This is the (main) thread for Integrity timers.  
 *   It's just there to allocate ressources needed by OS.
 *
 *   \param[in]     void
 *   \return        void
 *
 ******************************************************************************/
Object nw_vmf_timer_alarm_handler(vmf_timer_handler_t* arg)
{
    vmf_ret_t       vmf_ret = VMF_OK;
    vmf_timer_t *   p_vmf_timer;
    unsigned32      current_time;
    unsigned32      elapsed_time=0;

    VMF_TIMER_PRINTF ("timer-callback()");    

    vmf_ret = nw_vmf_get_timer(arg->val, &p_vmf_timer);
    if (VMF_OK == vmf_ret)
    {
        /* calculate elapsed time */
        current_time = nw_os_cfg_get_ms_time();
        if (current_time > p_vmf_timer->start_time)
        {
            elapsed_time =  current_time - (p_vmf_timer->start_time);
            UNUSED_PARAM(elapsed_time);
            VMF_TIMER_PRINTF ("timer-callback: asked_time=%d, elapsed_time=%d",p_vmf_timer->asked_time,elapsed_time);    
        }

        /* call the user callback */
        VMF_TIMER_MUX_LOCK(&(p_vmf_timer->mutex));
        if (NULL != p_vmf_timer->callback)
        {
            /* remind that we are in context of callback! */
            p_vmf_timer->in_callback = true;
            p_vmf_timer->callback(current_time, p_vmf_timer->arg);
            p_vmf_timer->in_callback = false;
        }
        else
        {
            VMF_TIMER_PRINTF("callback == NULL");
        }
    
        VMF_TIMER_PRINTF("timer_callback(%d)",p_vmf_timer->timer_id);
        
        /* free the vmf timer */
        (void) nw_vmf_free_timer(p_vmf_timer);
        VMF_TIMER_MUX_UNLOCK(&(p_vmf_timer->mutex));
    } 
        
    return NULLObject;
}


/*************************************************************************//**
 *
 *   nw_vmf_timer_convert_ms_to_time \n
 *   Convert milliseconds to Integrity Time struct.  
 *
 *   \param[in]     unsigned32 in_milliseconds  time in milliseconds
 *   \param[out]    Time * out_time             Time struct output
 *   \return        void
 *
 ******************************************************************************/
void nw_vmf_timer_convert_ms_to_time (unsigned32 in_milliseconds, Time * out_time)
{

    unsigned32 my_ms = in_milliseconds;

    if (my_ms >= 1000)
    {
        out_time->Seconds = my_ms / 1000;
        my_ms = my_ms - out_time->Seconds * 1000; 
    }
    else
    {
        out_time->Seconds = 0;
    }
    
    out_time->Fraction = (uint32_t) (((unsigned64)my_ms << 32) / 1000);

    return;
}


#else

/*************************************************************************//**
 *
 *   timer callback - posix version \n
 *   NOTE: the registered user callback is called from this timer callback
 *   The user-callback is protected by mutexes 
 *
 *
 *   \param[in]     sigval
 *   \return        void
 *
 ******************************************************************************/
static void timer_callback(union sigval sig)
{
    vmf_timer_t  * p_vmf_timer;
    unsigned32 current_time;
    unsigned32 elapsed_time=0;

    VMF_TIMER_PRINTF ("timer-callback()");    
    
    UNUSED_PARAM(elapsed_time);
    /* get pointer to vmf timer */
    p_vmf_timer = sig.sival_ptr;
    if (NULL == p_vmf_timer)
    {
        /* invalid vmf timer */
        VMF_TIMER_PRINTF("timer_callback()  p_vmf_timer=NULL!!");
        return;
    }
        
    /* calculate elapsed time */
    current_time = nw_os_cfg_get_ms_time();
    if (current_time > p_vmf_timer->start_time)
    {
        elapsed_time =  current_time - (p_vmf_timer->start_time); 
        VMF_TIMER_PRINTF ("timer-callback: asked_time=%d, elapsed_time=%d",p_vmf_timer->asked_time,elapsed_time);    
    }

    /* call the user callback */
    VMF_TIMER_MUX_LOCK(&(p_vmf_timer->mutex));
    if (NULL != p_vmf_timer->callback)
    {
        /* remind that we are in context of callback! */
        p_vmf_timer->in_callback = true;
        p_vmf_timer->callback(current_time,p_vmf_timer->arg);
        p_vmf_timer->in_callback = false;
    }
    else
    {
        VMF_TIMER_PRINTF("callback == NULL");
    }
 
    VMF_TIMER_PRINTF("timer_callback(%d)",p_vmf_timer->timer_id);
    
    /* free the vmf timer */
    (void) nw_vmf_free_timer(p_vmf_timer);
    VMF_TIMER_MUX_UNLOCK(&(p_vmf_timer->mutex));
}

#endif

