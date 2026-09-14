/******************************************************************************
*                                                                             *
*                   CONFIDENTIAL - Visteon Automotive Systems                 *
*                                                                             *
*  This is an unpublished work, which is a trade secret, created in 2007.     *
*  Visteon Automotive Systems owns all rights to this work and intends to     *
*  maintain it in confidence to preserve its trade secret status.  Visteon    *
*  Automotive Systems reserves the right to protect this work as an           *
*  unpublished copyrighted work in the event of an inadvertent or deliberate  *
*  unauthorized publication.  Visteon Automotive Systems also reserves        *
*  its rights under the copyright laws to protect this work as a published    *
*  work.  Those having access to this work may not copy it, use it, or        *
*  disclose the information contained in it without the written authorization *
*  of Visteon Automotive Systems.                                             *
*                                                                             *
*******************************************************************************
*  PROJECT NAME :  VMF                                                        *
*******************************************************************************
*  MODULE NAME  :  nw_vmf_timer.h                                                *
*  AUTHOR NAME  :  jbecke30                                                   *
*******************************************************************************
*  MODULE DATE  :   10th July 2012                                            *
*******************************************************************************
*  MODULE DESCRIPTION  :                                                      *
*  types used by the Visteon message framework                    *
******************************************************************************/
#ifndef __VMF_TIMER_H
#define __VMF_TIMER_H


#define VMF_INVALID_TIMER       0xffff

#define MAX_VMF_TIMER_PL 10

typedef struct vmf_ctrl_soft_timer_tag  vmf_ctrl_soft_timer_t;
struct vmf_ctrl_soft_timer_tag
{
    vmf_ctrl_soft_timer_t   *next_timer;      /* next timer            */
    unsigned32              abs_time;         /* absolute elapse time  */
    unsigned8               group;            /* timer response group  */
    unsigned8               event;            /* timer response event  */
    unsigned8               in_use;
    unsigned8               pl_len;
    unsigned8               pl[MAX_VMF_TIMER_PL];
};

#pragma pack(push,1)
/* command payload types */
/* VMF_CTRL_START_TIMER */
typedef struct
{
    unsigned8       ms_time_l;          /* low of time in ms     */
    unsigned8       ms_time_h;          /* high of time in ms    */
    unsigned8       group;              /* timer response group  */
    unsigned8       event;              /* timer response event  */
    unsigned8       pl_len;             /* payload len or 0*/
    unsigned8       pl[MAX_VMF_TIMER_PL]; /* payload */
}vmf_ctrl_start_timer_pl_t;
#pragma pack(pop)

vmf_ret_t vmf_timer_start (unsigned16 *pvmf_timer_id, unsigned32 time_in_ms, void (*nw_vmf_on_timer)(unsigned32 system_time_ms,void *arg),void *arg);
vmf_ret_t vmf_timer_stop  (unsigned16 vmf_timer_id);
vmf_ret_t vmf_timer_set   (unsigned16 vmf_timer_id, unsigned32 time_in_ms);
vmf_ret_t vmf_timer_set_if_smaller (unsigned16 vmf_timer_id, unsigned32 time_in_ms);


#endif
