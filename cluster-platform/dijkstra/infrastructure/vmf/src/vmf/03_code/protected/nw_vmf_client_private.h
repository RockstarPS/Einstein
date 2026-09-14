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
*  MODULE NAME  :  nw_vmf_client_private.h                                               *
*  AUTHOR NAME  :  jbecke30                                                   *
*******************************************************************************
*  MODULE DATE  :   13th August 2012                                            *
*******************************************************************************
*  MODULE DESCRIPTION  :                                                      *
*  private header file of nw_vmf_client.c                                                *
******************************************************************************/
#ifndef VMF_CLIENT_PRIVATE_H_
#define VMF_CLIENT_PRIVATE_H_

/* definitions */

#define INITAL_CID_VALUE                (1)
#define MAX_SERVER_CONNECTIONS          (15 + INITAL_CID_VALUE) /* mhammer3, tms 85418, initial cid must start at 1*/
#define VMF_CLIENT_WAIT_SERVER_TIMEOUT  5000                    /* time before vmf_connect() will return an error */
#define VMF_CLIENT_WAIT_P2P_TIMEOUT     5000                    /* time before vmf_connect_p2p() will return an error */
#define VMF_CLIENT_WAIT_SOME_TIME       50                      /* wait ime in ms in case of error */



/************** typedefs ********************/

/** definition for the cid table.\n
*   the connection description for each
*   connection instance is stored in this table.
*/


#define VMF_CLIENT_SHM_VALID_KEY            (0x55aa)
#define VMF_CLIENT_SHM_VERSION              (0x0001)
#define VMF_CLIENT_SHM_DELAY                (5)             /* wait time for server response in ms */
#define VMF_CLIENT_SHM_MAX_DELAY            (1000)          /* max wait time for server response in ms */


typedef enum
{
    VMF_CLSHM_REQUEST_INVALID = 0,
    VMF_CLSHM_REQUEST_REGISTER = 1,     /* register to server */
    VMF_CLSHM_REQUEST_P2P_PARTNER = 2,  /* get pid and cid of a p2p partner */

}vmf_client_shm_req_t;



/* VMF_CLSHM_REQUEST_P2P_PARTNER  payload */
typedef struct
{
    unsigned16      valid;                  /* set if response is valid*/
    pid_t           pid;                    /* response data*/
    vmf_client_id_t cid;                    /* response data */
    char            name[MAX_NAME_LEN+1];   /* request data */
}clshm_p2p_partner_t;



/*! vmf_client shared memory description */
typedef struct
{
    /* fixed header */
    unsigned16  valid;                              /* VMF_CLIENT_SHM_VALID_KEY if shared mem is valid */
    unsigned16  version;                            /* shared mem version = VMF_CLIENT_SHM_VERSION*/
    unsigned8   enable_spy;                         /* 0 if spy is disabled else 1 */

    /* data used for command /response */
    vmf_client_shm_req_t    request_cmd;            /* request command to server */
    union
    {
        clshm_p2p_partner_t psp_partner;
    }pl;
}vmf_client_shm_t;



typedef struct
{
    bool                in_use;
    bool                receiver_started;                   /**<* true if a receiver is started for this cid */
    char                my_channel_name[MAX_NAME_LEN+1];    /**< connection name */
    vmf_handle_t        rx_handle;                          /**< receive handle */
    vmf_handle_t        tx_handle;                          /**< transmit handle */
    vmf_handle_t        p2p_handle;                         /**< transmit handle */
    unsigned16          tx_timer_id;                        /**< id of timer for collector buffer timeout */
    signed32            collector_timeout;                  /**< collector timeout in ms */
    pthread_mutex_t     co_mutex;                           /**< mutex to protect message collector */
    void                *pcol_rx_buffer;                    /**< collector rx message */
    unsigned16          col_rx_buffer_len;                  /**< len of collector rx message */
    unsigned16          col_rx_buffer_msg_num;              /**< number of messages in co buffer */
    void                *pcol_tx_buffer;                    /**< collector tx message */
    unsigned16          col_tx_buffer_len;                  /**< len of collector rx message */
    unsigned16          col_tx_buffer_msg_num;              /**< number of messages in co buffer */
    vmf_client_shm_t    *pcl_shm;                           /**< client shared memory */
    int                 fd_shm;
    unsigned8           unpack_vmf_spy_msgs;                /**< unpack collected vmf spy messages 0==false, 1==true */
}my_cid_t;

typedef struct
{
    vmf_client_id_t     free_cid;
    pid_t               pid;                                /**< client pid   */
    my_cid_t            my_cid[MAX_SERVER_CONNECTIONS];
}my_cid_tab_t;


/* macros */
#define VMF_MUX_LOCK(mux)                                                                                   \
        {                                                                                                   \
            if (pthread_mutex_lock(mux) != 0)                                                               \
            {                                                                                               \
                NW_VMF_DEBUG_ERROR("VMF-CLient-Lib: mutex Lock Failed %s line %d\n", __FILE__, __LINE__);   \
            }                                                                                               \
        }

#define VMF_MUX_UNLOCK(mux)                                                                                 \
        {                                                                                                   \
            if (pthread_mutex_unlock(mux) != 0)                                                             \
            {                                                                                               \
                NW_VMF_DEBUG_ERROR("VMF-CLient-Lib: mutex Lock Failed %s line %d\n", __FILE__, __LINE__);   \
            }                                                                                               \
        }

/* function prototypes*/

vmf_ret_t nw_vmf_co_client_get_buffer       (void  **ppvmf_co_msg,unsigned16 len);
void      nw_vmf_co_client_free_buffer      (void   *pvmf_co_msg);
vmf_ret_t nw_vmf_co_client_is_co_msg        (vmf_basic_msg_t  *pvmf_co_msg);
vmf_ret_t nw_vmf_co_client_get_next_co_msg  (vmf_basic_msg_t  *pvmf_co_msg, unsigned16 co_msg_buff_len, vmf_basic_msg_t *pvmf_dest_msg, unsigned16 msg_buffer_len);
vmf_ret_t nw_vmf_co_client_get_msg_len      (vmf_msg_t        *pvmf_co_msg,unsigned16 *plen);
vmf_ret_t nw_vmf_co_client_add_msg          (vmf_client_id_t vmf_client_id, pthread_mutex_t *pco_mutex, vmf_basic_msg_t  *pvmf_co_msg, unsigned16 co_msg_buff_len, vmf_basic_msg_t  *pvmf_msg, bool check_ev_grp);
vmf_ret_t nw_vmf_co_client_transfer_msg     (vmf_handle_t tx_hdl, pthread_mutex_t *pmux, vmf_basic_msg_t  *pvmf_co_msg);
vmf_ret_t nw_vmf_create_shm_channel_name    (pid_t pid, unsigned8 cid,char *p_channel_name, unsigned8 buffer_size);


#endif
