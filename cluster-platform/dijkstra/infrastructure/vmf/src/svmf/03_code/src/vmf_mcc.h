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

/*************************************************************************//**

  \file                 vmf_mcc.h
  \brief                header of vmf_mcc.c

  \author               Joachim Becker
  \author               Visteon Deutschland GmbH, Infotainment Software

  *****************************************************************************/
#ifndef __VMF_MCC_H__
#define __VMF_MCC_H__



/* pool message */
typedef struct vmf_mcc_msg_t *pvmf_mcc_msg_t;
typedef struct
{
    pvmf_mcc_msg_t  next;
    vmf_msg_t       vmf_msg;
}vmf_mcc_msg_t;

/* message pool */
typedef struct
{
    BOOL                        initialised;
    unsigned16                  num;                /* debug only */
    unsigned16                  num_lost_messages;  /* number of lost messages (no buffer available) debug only */
    vmf_mcc_msg_t               *first;
    vmf_mcc_msg_t               *last;
    vmf_mcc_msg_t               *msgs;
}vmf_mcc_pool_t;

/* message queue */
typedef struct
{
    BOOL                        initialised;
    unsigned16                  num;                /* debug only */
    vmf_mcc_msg_t               *first;
    vmf_mcc_msg_t               *last;
}vmf_mcc_q_t;


#ifndef SEM_BASE_PTR
#define SEM_BASE_PTR    0x4001d000
#endif
#define VMF_MCC_HW_SEM_BUSY(dir)    (   0 != *((char *)SEM_BASE_PTR + dir)  && \
                                    ((VS_MICRO_CORE == VS_MICRO_CORE_A5) ? 2 : 1) != *((char *)SEM_BASE_PTR + dir) )
#define VMF_MCC_HW_SEM_LOCK(dir)    ( *((char *)SEM_BASE_PTR + dir) = (VS_MICRO_CORE == VS_MICRO_CORE_A5) ? 2 : 1)
#define VMF_MCC_HW_SEM_RELEASE(dir)  *((char *)SEM_BASE_PTR + dir) = 0
#define VMF_MCC                     (2)                                     /* gate 02 */
#define MCC_MQX_NODE_A5             (1)
#define MCC_MQX_NODE_M4             (2)
#define MCC_TASK_PRIORITY           (7)
#define MCC_TASK_NAME               ("TASK_TUNER_DAB_MCC")                 /* task name */
#define MCC_STACK_SIZE              (2000)

/* core 2 core INTERRUPT_CA5_C2C_3 is currently missing in util_micro_regs_vybrid.h */
#ifndef INTERRUPT_CA5_C2C_3
#define INTERRUPT_CA5_C2C_3         (51)
#endif

#define     EV_VMF_MCC_PROFILE_TIMER       (os_event_t)(0x00000001ul)

void        vmf_mcc_m4              (unsigned32 data);
void        vmf_mcc_a5              (unsigned32 data);
vmf_ret_t   vmf_mcc_msg_pool_put    (vmf_mcc_msg_t *p_msg);
vmf_ret_t   vmf_mcc_msg_pool_get    (vmf_mcc_msg_t **pp_msg);
vmf_ret_t   vmf_mcc_msg_q_put_msg   (vmf_mcc_msg_t  *p_msg);
vmf_ret_t   vmf_mcc_msg_q_get_msg   (vmf_mcc_msg_t **pp_msg);
void        vmf_mcc_init            (void);
void        vmf_mcc_a5_isr          (void *not_used);
bool        vmf_mi_mcc_create_thread(void);

#endif

