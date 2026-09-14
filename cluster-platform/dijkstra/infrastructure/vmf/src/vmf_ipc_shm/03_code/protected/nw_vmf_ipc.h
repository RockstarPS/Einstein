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

  Module:               nw_vmf_ipc.h
  Description:          header file for shared memory ipc 

  Project Scope:        Multiple platforms

  Organization:         Visteon Deutschland GmbH, Infotainment Software
  Author:               Jochen Becker (jbecke30@visteon.com)

  Compiler/Assembler:   Visual Studio
  Target Hardware:      Any

  *****************************************************************************/

#ifndef __NW_VMF_IPC_H
#define __NW_VMF_IPC_H

#include "nw_vmf_controller.h"

NW_COMPILER_MESSAGE ("shared memory IPC")

#define MAX_IPC_CHANNELS                (80)                    /*!< Maximum number of IPC message queues */


#define VMF_SHM_IPC_FIRST_HDL   1       /* first valid vmf handle (0=vmf server)*/
#define SEM_MUTEX               1       /* init value to use semaphore as a mutex */
#define SEM_PSHARED             1       /* init value of pshared argument for sem_init()*/
#define SEM_INIT_VAL            0       /* semaphores init value */


#define VMF_IPC_QUEUE_SIZE_SERVER       (unsigned16) 100     /*!< Server queue size */
//#define VMF_IPC_QUEUE_SIZE_SERVER       (unsigned16) 30     /*!< Server queue size */
#define VMF_IPC_QUEUE_SIZE_MIN          (unsigned16) 5      /*!< Client minimum queue size */
#define VMF_IPC_QUEUE_SIZE_MAX          (unsigned16) 200     /*!< Client maximum queue size */


/* buffer Pools  */
#define NW_VMF_BUFFER_POOLS_PAYLOAD_LEN (MAX_VMF_DATA_LEN+1)     /* has to be different from all pther pools msg-length */
#define NW_VMF_BUFFER_POOLS_MSG_NUM     (5)   

#define NW_VMF_BUFFER_POOL1_PAYLOAD_LEN (150)
#define NW_VMF_BUFFER_POOL1_MSG_NUM     (500)

#define NW_VMF_BUFFER_POOL2_PAYLOAD_LEN (1500)
#define NW_VMF_BUFFER_POOL2_MSG_NUM     (500)

#define NW_VMF_BUFFER_POOL3_PAYLOAD_LEN (2050)
#define NW_VMF_BUFFER_POOL3_MSG_NUM     (800)

#define NW_VMF_BUFFER_POOL4_PAYLOAD_LEN MAX_VMF_DATA_LEN
#define NW_VMF_BUFFER_POOL4_MSG_NUM     (250)

#define NW_VMF_SHM_IPC_MAX_QUEUES       (MAX_IPC_CHANNELS)
#define NW_VMF_SHM_IPC_MSG_NUM_MAX      (1000)      /* maximum number of message per queue */
#define NW_VMF_SHM_IPC_MSG_NUM_STD      (30)        /* std. number of message per queue */

typedef struct vmf_buffer_pool1_msg_tag vmf_buffer_pool_msg_t; 
typedef struct vmf_buffer_pool1_tag     vmf_buffer_pool_t; 

typedef struct vmf_buffer_pool1_tag     vmf_buffer_pool1_t; 
typedef struct vmf_buffer_pool1_msg_tag vmf_buffer_pool1_msg_t; 

typedef struct vmf_buffer_pool2_tag     vmf_buffer_pool2_t; 
typedef struct vmf_buffer_pool2_msg_tag vmf_buffer_pool2_msg_t; 

typedef struct vmf_buffer_pool3_tag     vmf_buffer_pool3_t; 
typedef struct vmf_buffer_pool3_msg_tag vmf_buffer_pool3_msg_t; 

typedef struct vmf_buffer_pool4_tag     vmf_buffer_pool4_t; 
typedef struct vmf_buffer_pool4_msg_tag vmf_buffer_pool4_msg_t; 

typedef struct vmf_buffer_poolS_tag     vmf_buffer_poolS_t; 
typedef struct vmf_buffer_poolS_msg_tag vmf_buffer_poolS_msg_t; 

typedef struct vmf_msg_queue_tag        vmf_msg_queue_t; 
typedef struct vmf_msg_queue_shm_tag    vmf_msg_queue_shm_t; 
    

#define NW_VMF_SHM_IPC_ERROR(...)       fprintf(ERROR_CHANNEL, "VMF_SHM_IPC: "__VA_ARGS__); fprintf(ERROR_CHANNEL, "\n");
#define NW_VMF_SHM_IPC_INFO(...)        // fprintf(ERROR_CHANNEL, "VMF_SHM_IPC: "__VA_ARGS__); fprintf(ERROR_CHANNEL, "\n");
#define NW_VMF_SHM_IPC_INFO2(...)       // fprintf(ERROR_CHANNEL, "VMF_SHM_IPC: "__VA_ARGS__); fprintf(ERROR_CHANNEL, "\n");

#define VMF_IPC_SHM                     "vmf_ipc_shm"   
#define IPC_SERVER_CHANNEL_NAME         "000000"
#define IPC_SERVER_CHANNEL_NAME_NUM     (0)
#define IPC_SERVER_HANDLE               (0)

#define VMF_TRACE_STARTUP_Q             "000001"            /* name of startup Q */     

#define SHM_SOME_TIME                   (200)               /* time in ms */
#define SHM_VALID_TIMEOUT               (4000)              /* timeout for valid shm in ms */
 
#define IPC_BLOCKING                    true                /*!< Parameter definition for opening IPC */
#define IPC_NON_BLOCKING                false               /*!< Parameter definition for opening IPC */

#define IPC_VERSION_STRING              "Shared-Memory-IPC"
#define VMF_IPC_TYPE                    VMF_CTRL_IPC_SHM

/* address offset macros */
/* server_base is the shm base addr of the server */
/* local_base is the shm base of this process     */
//#define GET_LOCAL_ADDR(server_addr)       (vmf_buffer_pool_msg_t *)(((unsigned8 *)server_addr-(unsigned32)server_base)+(unsigned32)local_base)    
//#define GET_SERVER_ADDR(local_addr)       (vmf_buffer_pool_msg_t *)(((unsigned8 *)local_addr -(unsigned32)local_base )+(unsigned32)server_base)   
#ifdef VMF_SERVER
#define GET_LOCAL_ADDR(server_addr)     (server_addr)
#define GET_SERVER_ADDR(local_addr)     (local_addr)
#else
#define GET_LOCAL_ADDR(server_addr)     ((unsigned8 *)server_addr+local_diff)
#define GET_SERVER_ADDR(local_addr)     ((unsigned8 *)local_addr+server_diff)
#endif
#define GET_LOCAL_MSG_ADDR(server_addr)  (vmf_buffer_pool_msg_t*)GET_LOCAL_ADDR(server_addr)

#define VMF_IPC_SHM_POOL_NUM            (5)

#pragma pack(push,4)

/* single element for buffer pool 1 */
struct vmf_buffer_pool1_msg_tag 
{
    vmf_buffer_pool_msg_t   *previous;
    vmf_buffer_pool_msg_t   *next;
    unsigned                ref_count;              /* has to be unsigned because of atomic access */
    unsigned16              pool_msg_len;           /* to identify the buffer pool */       
    unsigned16              msg_valid;
    unsigned16              msg_payload_len;        /* payload len of message in byte */       
    unsigned8               shm_msg[NW_VMF_BUFFER_POOL1_PAYLOAD_LEN+1];
};

/* single element for buffer pool 2 */
struct vmf_buffer_pool2_msg_tag 
{
    vmf_buffer_pool_msg_t   *previous;
    vmf_buffer_pool_msg_t   *next;
    unsigned                ref_count;              /* has to be unsigned because of atomic access */
    unsigned16              pool_msg_len;           /* to identify the buffer pool */       
    unsigned16              msg_valid;
    unsigned16              msg_payload_len;        /* payload len of message in byte */       
    unsigned8               shm_msg[NW_VMF_BUFFER_POOL2_PAYLOAD_LEN+1];
};

/* single element for buffer pool 3*/
struct vmf_buffer_pool3_msg_tag 
{
    vmf_buffer_pool_msg_t   *previous;
    vmf_buffer_pool_msg_t   *next;
    unsigned                ref_count;              /* has to be unsigned because of atomic access */
    unsigned16              pool_msg_len;           /* to identify the buffer pool */       
    unsigned16              msg_valid;
    unsigned16              msg_payload_len;        /* payload len of message in byte */       
    unsigned8               shm_msg[NW_VMF_BUFFER_POOL3_PAYLOAD_LEN+1];
};

/* single element for buffer pool 4*/
struct vmf_buffer_pool4_msg_tag 
{
    vmf_buffer_pool_msg_t   *previous;
    vmf_buffer_pool_msg_t   *next;
    unsigned                ref_count;              /* has to be unsigned because of atomic access */
    unsigned16              pool_msg_len;           /* to identify the buffer pool */       
    unsigned16              msg_valid;
    unsigned16              msg_payload_len;        /* payload len of message in byte */       
    unsigned8               shm_msg[NW_VMF_BUFFER_POOL4_PAYLOAD_LEN+1];
};

/* single element for server buffer pool*/
struct vmf_buffer_poolS_msg_tag 
{
    vmf_buffer_poolS_msg_t  *previous;
    vmf_buffer_poolS_msg_t  *next;
    unsigned                ref_count;              /* has to be unsigned because of atomic access */
    unsigned16              pool_msg_len;           /* to identify the buffer pool */       
    unsigned16              msg_valid;
    unsigned16              msg_payload_len;        /* payload len of message in byte */       
    unsigned8               shm_msg[NW_VMF_BUFFER_POOLS_PAYLOAD_LEN+1];
};


/* buffer pools */
struct vmf_buffer_pool1_tag 
{
    unsigned16              num ;                    /* number of elements in pool - debug only */
    unsigned16              pool_msg_len;            /* paylod len of each element in this pool */             
    sem_t                   mux;                     /* pool semaphore     */
    bool                    lock;
    unsigned16              low_wm;                  /* low watermark */
    vmf_buffer_pool1_msg_t  *first ;                 /* first element in pool  1    */
    vmf_buffer_pool1_msg_t  *last ;                  /* last element in pool   1    */
    vmf_buffer_pool_t       *nextpool;               /* points to next buffer pool or NULL if no ore pools*/
    vmf_buffer_pool1_msg_t  msgs[NW_VMF_BUFFER_POOL1_MSG_NUM+1];
};

/* buffer pools */
struct vmf_buffer_pool2_tag 
{
    unsigned16              num;                     /* number of elements in pool - debug only */
    unsigned16              pool_msg_len;            /* paylod len of each element in this pool */             
    sem_t                   mux;                     /* pool semaphore     */
    bool                    lock;
    unsigned16              low_wm;                  /* low watermark */
    vmf_buffer_pool2_msg_t  *first;                  /* first element in pool  2    */
    vmf_buffer_pool2_msg_t  *last;                   /* last element in pool   2    */
    vmf_buffer_pool_t       *nextpool;               /* points to next buffer pool or NULL if no ore pools*/
    vmf_buffer_pool2_msg_t  msgs[NW_VMF_BUFFER_POOL2_MSG_NUM+1];
};

/* buffer pools */
struct vmf_buffer_pool3_tag 
{
    unsigned16              num;                     /* number of elements in pool - debug only */
    unsigned16              pool_msg_len;            /* paylod len of each element in this pool */             
    sem_t                   mux;                     /* pool semaphore     */
    bool                    lock;
    unsigned16              low_wm;                  /* low watermark */
    vmf_buffer_pool3_msg_t  *first;                  /* first element in pool  3    */
    vmf_buffer_pool3_msg_t  *last;                   /* last element in pool   3    */
    vmf_buffer_pool_t       *nextpool;               /* points to next buffer pool or NULL if no ore pools*/
    vmf_buffer_pool3_msg_t  msgs[NW_VMF_BUFFER_POOL3_MSG_NUM+1];
};


/* buffer pools */
struct vmf_buffer_pool4_tag 
{
    unsigned16              num;                     /* number of elements in pool - debug only */
    unsigned16              pool_msg_len;            /* paylod len of each element in this pool */             
    sem_t                   mux;                     /* pool semaphore     */
    bool                    lock;
    unsigned16              low_wm;                  /* low watermark */
    vmf_buffer_pool4_msg_t  *first;                  /* first element in pool  */
    vmf_buffer_pool4_msg_t  *last;                   /* last element in pool   */
    vmf_buffer_pool_t       *nextpool;               /* points to next buffer pool or NULL if no ore pools*/
    vmf_buffer_pool4_msg_t  msgs[NW_VMF_BUFFER_POOL4_MSG_NUM+1];
};

/* server buffer pool */
struct vmf_buffer_poolS_tag 
{
    unsigned16              num;                     /* number of elements in pool - debug only */
    unsigned16              pool_msg_len;            /* paylod len of each element in this pool */             
    sem_t                   mux;                     /* pool semaphore     */
    bool                    lock;
    unsigned16              low_wm;                  /* low watermark */
    vmf_buffer_poolS_msg_t  *first;                  /* first element in pool  */
    vmf_buffer_poolS_msg_t  *last;                   /* last element in pool   */
    vmf_buffer_pool_t       *nextpool;               /* points to next buffer pool or NULL if no ore pools*/
    vmf_buffer_poolS_msg_t  msgs[NW_VMF_BUFFER_POOLS_MSG_NUM+1];
};


#define INVALID_NUMNAME (0xffffffff)
#define VMF_IPC_QNAME_LEN 25
/* msg queue */
struct vmf_msg_queue_tag 
{
    bool                    in_use;                 /* true if this queue is in use */
    bool                    tx_blocking;            /* true if write to this queue is blocking */
    bool                    rx_blocking;            /* true if read from this queue is blocking */
    unsigned16              num;                    /* number of elements in queue */
    unsigned16              max_num;                /* maximum number of messages in the queue - 0 = no limit */
    unsigned16              high_wm;                /* high watermark */
    unsigned16              ttr;                    /* time to re-use */
    unsigned32              num_name;               /* numeric representation of the queue name */
    char                    name[VMF_IPC_QNAME_LEN];/* queue name */    
    sem_t                   rx_sem;                 /* pool semaphore     */
    sem_t                   tx_sem;                 /* semaphore to handle blocking of transmit function */
    sem_t                   mux;                    /* pool mutex simulation */
    bool                    lock;
    vmf_buffer_pool_msg_t  *first;                  /* first element in queue      */
    vmf_buffer_pool_msg_t  *last;                   /* last element in queue       */
};


/* memory queue/pool shared memory */
#define SHM_VALID_TOKEN     0xa55a
struct vmf_msg_queue_shm_tag 
{
    void     *              shm_server_base;        /* has to be first element in shm !!!!!!! */
    unsigned16              shm_valid;
    unsigned                max_client_id;          /* next valid client id  - access only with atomic functions!       */
    unsigned                num_client_ids;         /* number of client ids */
    /* message pools */
    vmf_buffer_poolS_t      pools;
    vmf_buffer_pool1_t      pool1;
    vmf_buffer_pool2_t      pool2;
    vmf_buffer_pool3_t      pool3;
    vmf_buffer_pool4_t      pool4;
    /* message queues */
    sem_t                   mux;                    /* all-pool mutex simulation */
    vmf_msg_queue_t         queues[NW_VMF_SHM_IPC_MAX_QUEUES+1];
};

#pragma pack(pop)
#pragma pack(push,1)

/* VmfQStatus payload transfered with group VMF_TRACE_CTRL, event VMF_SHM_IPC_STATUS_QUEUES */
typedef struct  
{
    unsigned16              version;                                    /* version of the status message (currently 0) */
    unsigned16              num_queues;                                 /* number of message queues */
    unsigned16              queue_high_wm[NW_VMF_SHM_IPC_MAX_QUEUES];   /* high watermark of the queues - 0xffff means inactive queue */
}vmf_ipc_shm_status_queue_t;

/* VmfQStatus payload transfered with group VMF_TRACE_CTRL, event VMF_SHM_IPC_STATUS_POOLS */
typedef struct  
{
    unsigned16              version;                                    /* version of the status message (currently 0) */
    unsigned16              num_pools;                                  /* number of message pools = VMF_IPC_SHM_POOL_NUM*/
    unsigned16              pool_low_wm[VMF_IPC_SHM_POOL_NUM];          /* low watermark of all message pools */
}vmf_ipc_shm_status_pool_t;

/* VmfQStatus  payload transfered with group VMF_TRACE_CTRL, event VMF_SHM_IPC_STATUS_POOLS */
typedef struct  
{
    unsigned16              version;                                    /* version of the status message (currently 0) */
    unsigned8               queue;                                      /* queue number */
    unsigned8               name_len;                                   /* len of queue name  */
    char                    name[VMF_IPC_QNAME_LEN];                    /* queue name */
}vmf_ipc_shm_status_queue_name_t;
  

#pragma pack(pop)


vmf_ret_t       nw_vmf_ipc_init                  (bool remove_ressources);
vmf_ret_t       nw_vmf_ipc_create_channel_name   (pid_t pid, unsigned8 cid,char *p_channel_name, unsigned8 buffer_size);
vmf_handle_t    nw_vmf_ipc_create                (char *channel_name, unsigned16 queue_size, unsigned16 msg_size);
vmf_handle_t    nw_vmf_ipc_open                  (char *channel_name, bool block_on_send);
vmf_ret_t       nw_vmf_ipc_close                 (vmf_handle_t vmf_handle);
vmf_ret_t       nw_vmf_ipc_send                  (vmf_handle_t vmf_handle, unsigned8 *buffer, unsigned16 number_bytes);
vmf_ret_t       nw_vmf_ipc_send_raw              (vmf_handle_t vmf_handle, unsigned8 *p_buffer);
vmf_ret_t       nw_vmf_ipc_destroy               (vmf_handle_t vmf_handle);
vmf_handle_t    nw_vmf_ipc_create_async          (char *channel_name, unsigned16 queue_size,
                                                   unsigned16 msg_size, unsigned32 coid,
                                                   unsigned32 async_event);
vmf_ret_t       nw_vmf_ipc_receive               (vmf_handle_t vmf_handle,unsigned16 buffer_size,
                                                   unsigned8 *buffer,unsigned16 *number_bytes);
vmf_ret_t       nw_vmf_ipc_timed_receive         (vmf_handle_t vmf_handle,unsigned16 buffer_size,
                                                   unsigned8 *buffer,unsigned16 *p_number_bytes,
                                                   unsigned16 ms_timeout);                              
unsigned8 *     nw_vmf_ipc_receive_raw           (vmf_handle_t vmf_handle);
vmf_error_t     nw_vmf_ipc_pool_free_buff_raw    (unsigned8 *p_buffer);

                              
void            nw_vmf_ipc_pre_init              (void);
vmf_ret_t       nw_vmf_shm_ipc_init              (vmf_msg_queue_shm_t *pshm);
vmf_error_t     nw_vmf_shm_ipc_pool_get_buff     (vmf_msg_queue_shm_t *pshm,vmf_handle_t vmf_handle, vmf_buffer_pool_msg_t **pp_free_buffer,unsigned16 wanted_pl_len);
vmf_error_t     nw_vmf_shm_ipc_pool_free_buff    (vmf_msg_queue_shm_t *pshm,vmf_buffer_pool_msg_t *p_buffer);
vmf_client_id_t nw_vmf_shm_ipc_get_free_hdl      (vmf_msg_queue_shm_t *pshm);
vmf_error_t     nw_vmf_shm_ipc_queue_write       (vmf_msg_queue_shm_t *pshm,vmf_buffer_pool_msg_t *pmsg,vmf_handle_t vmf_handle);
vmf_error_t     nw_vmf_shm_ipc_queue_read        (vmf_msg_queue_shm_t *pshm,vmf_buffer_pool_msg_t **ppmsg,vmf_handle_t vmf_handle,unsigned16 ms_timeout);
vmf_error_t     nw_vmf_shm_ipc_queue_set_max_num (vmf_msg_queue_shm_t *pshm,vmf_handle_t vmf_handle,unsigned16 max_num);
vmf_error_t     nw_vmf_shm_ipc_queue_set_blocking(vmf_msg_queue_shm_t *pshm,vmf_handle_t vmf_handle,bool rx_blocking,bool tx_blocking);
vmf_error_t     nw_vmf_shm_ipc_queue_free_all_buff(vmf_msg_queue_shm_t *pshm,vmf_handle_t vmf_handle);
vmf_error_t     nw_vmf_ipc_register_queue_name   (vmf_handle_t vmf_handle,const char* p_name);

bool            nw_vmf_ipc_create_status_thread (void);
void            nw_vmf_ipc_stop_status_thread   (void);
bool            nw_vmf_ipc_is_status_thread_running(void);



/* REMOVE!!! */
unsigned16 vmf_ipc_get_current_count(vmf_handle_t vmf_handle);
unsigned16 vmf_ipc_get_high_watermark(vmf_handle_t vmf_handle);


#endif
