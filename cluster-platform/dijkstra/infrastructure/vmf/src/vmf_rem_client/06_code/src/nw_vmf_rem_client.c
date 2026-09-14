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

  Module:               nw_vmf_rem_client.c
  Description:          Main routine for the message framework lib

  Project Scope:        Beethoven VM platform

  Organization:         Visteon Deutschland GmbH, Infotainment Software
  Author:               Jochen Becker

  Compiler/Assembler:   gcc
  Target Hardware:      Any

  *****************************************************************************/
#define VMF_CLIENT_C
#if 0
 #define NW_VMF_DEBUG
 #define DO_CLIENT_DEBUG_HEX
 #define DO_CLIENT_DEBUG
 #define VMF_REM_DEBUG
#endif

/* application includes */
#include <stddef.h>
#include "nw_vmf_rem.h"					/* vmf cfg file */
#include "nw_vmf_rem_client_connector.h"
#include "nw_os_config.h"



#define INITAL_CID_VALUE            (1)
#define MAX_SERVER_CONNECTIONS      (127) 

#ifdef NW_VMF_CFG_ALLOW_SHADOW_WITH_EMPTY_FUNCTION_LIST
#define ALLOW_EMPTY_SH_LIST
#endif

const char	__progname[]={"vmf_dll"};

/************** typedefs ********************/
/** definition for the cid table.\n
*   the connection description for each
*   connection instance is stored in this table.
*/

typedef struct
{
    bool                in_use;
    bool                receiver_started;                   /**<* true if a receiver is started for this cid */
    char                my_channel_name[MAX_NAME_LEN+1];    /**< connection name */
    void                (*cb) (vmf_msg_t * p_vmf_msg) ;     /**< callback function */
    vmf_handle_t        tx_handle;                          /**< transmit handle */
    vmf_handle_t        rx_handle;                          /**< receive handle */
    signed32            collector_timeout;                  /**< collector timeout in ms */
    pthread_mutex_t     co_mutex;                           /**< mutex to protect message collector */
    void                *pcol_rx_buffer;                    /**< collector rx message */
    unsigned16          col_rx_buffer_len;                  /**< len of collector rx message */
    unsigned16          col_rx_buffer_msg_num;              /**< number of messages in co buffer */
    void                *pcol_tx_buffer;                    /**< collector tx message */
    unsigned16          col_tx_buffer_len;                  /**< len of collector rx message */
    unsigned16          col_tx_buffer_msg_num;              /**< number of messages in co buffer */
}my_cid_t;

typedef struct
{
    vmf_client_id_t     free_cid;
    pid_t               pid;                                    /**< client pid   */
    my_cid_t            my_cid[MAX_SERVER_CONNECTIONS];
}my_cid_tab_t;



/*************** external variables  *********************/
extern tx_con_tab_t				tx_tab[];
extern con_tab_t				con_tab[];



/*************** MACROS *********************/
#define VMF_CLIENT_LOCK     {NW_REM_VMF_DEBUG_PRINTF("VMF-client_connector: nw_vmf_client_mutex_lock()");if ((mux_error=pthread_mutex_lock((&myMutex))) != 0) {NW_REM_VMF_DEBUG_ERROR("VMF-client: mutex Lock Failed %s line %d", __FILE__, __LINE__);}}
#define VMF_CLIENT_UNLOCK   {NW_REM_VMF_DEBUG_PRINTF("VMF-client_connector: nw_vmf_client_mutex_unlock()");if ((mux_error=pthread_mutex_unlock((&myMutex))) != 0) {NW_REM_VMF_DEBUG_ERROR("VMF-client: mutex Unlock Failed %s line %d", __FILE__, __LINE__);}}
#define VMF_MUTEX_INIT      if (false == bmyMutexInitialized) nw_vmf_client_mutex_init(&myMutex);

#define FOREVER             (true)

/************** global variables ************/
static bool				cid_tab_init_done=false;                /*!< true if cd-table is initialized */
static pthread_mutex_t	myMutex;
static bool				bmyMutexInitialized = false;
static bool				nw_vmf_ipc_init_done = false;
static int				mux_error;
static my_cid_tab_t		cid_tab;                                /*!< cid table */

/************ local functions **************/
static bool             nw_vmf_client_mutex_init			(pthread_mutex_t *pMutex);
static void             nw_vmf_HexDump						(char *chPrefixText, unsigned char *u8mem, unsigned length);
static void             nw_vmf_ini_cid_tab					(my_cid_tab_t *pcid_tab);

static vmf_ret_t		nw_vmf_co_client_get_next_co_msg	(vmf_basic_msg_t  *pvmf_co_msg, unsigned16 co_msg_buff_len, vmf_basic_msg_t  *pvmf_dest_msg, unsigned16 msg_buffer_len);
static vmf_ret_t		nw_vmf_co_receive					(vmf_client_id_t vmf_client_id,unsigned16 dest_buffer_len,vmf_basic_msg_t *pdest_vmf_msg,unsigned16 *dest_read_num_bytes);
static vmf_ret_t		nw_vmf_co_store_msg					(vmf_client_id_t vmf_client_id, vmf_basic_msg_t *pco_vmf_msg,unsigned16 co_vmf_msg_len);
static vmf_ret_t		nw_vmf_co_client_get_buffer			(void **ppvmf_co_msg,unsigned16 len);
static void				nw_vmf_co_client_free_buffer		( void  *pvmf_co_msg);
static vmf_ret_t		nw_vmf_co_client_get_msg_len		(vmf_msg_t  *pvmf_co_msg,unsigned16 *plen);

static unsigned32 getmypid(void);


/**************************************************************************//**
 *
 *   Function Name: nw_vmf_client_init ()
 *   Description:   initialize the vmf client
 *                  this has to becalled before connecting to the VMF server
 *
 *
 *   Parameters:    void
 *
 *   Return value:   \return  vmf_ret_t error type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_client_init(void)
{
    vmf_ret_t  vmf_ret=VMF_ERROR;

    /* init mutex */
    if (nw_vmf_client_mutex_init(&myMutex))
    {
        vmf_ret = VMF_OK;
    }

    return vmf_ret;
}


/**************************************************************************//**
 *
 *   Function Name: nw_vmf_connect (const char *pmy_process_name[31],
 *                                  void * cb_api_vmf_msg_receive_callback())\n
 *   Description:   register as a client to the vmf-server\n
 *                  A tx channel to the server is opened and an rx channel for this client is created.
 *
 *
 *   Parameters:    my_process_name                    (input) text-identifier or NULL\n
 *                  cb_api_vmf_msg_receive_callback()  rx callback function or NULL\n
 *                  callback_priority                  (input) priority of the callback thread\n
 *   Return value:  \return if >=0  then client-id else error as vmf_ret_t\n
 *
 ******************************************************************************/
vmf_client_id_t nw_vmf_connect( char *p_my_process_name,                               		 /*!< INPUT channel name or NULL  */
                                void cb_api_vmf_msg_receive_callback(vmf_msg_t * p_vmf_msg), /*!< INPUT rx callback or NULL */
                                signed32 callback_priority,                                  /*!< INPUT thread priority of rx callback function */
                                unsigned16 message_queue_size,                               /*!< INPUT queue size for receiving messages */
                                unsigned16 message_size )                                    /*!< INPUT message size for the queue */
{
    vmf_handle_t		tx_handle=VMF_HANDLE_INVALID;
    vmf_handle_t		rx_handle=VMF_HANDLE_INVALID;
    vmf_client_id_t		my_client_id = MAX_SERVER_CONNECTIONS;			/* set to invalid */
    vmf_ret_t			vmf_ret;
	vmf_rpc_response_t	response;
	vmf_client_id_t		rcid=0;



	/*create console */
#ifdef WIN32
	#ifdef VMF_REM_DEBUG
	{
		static bool ConsoleOpend=false;

		if (false == ConsoleOpend)
		{
			AllocConsole();
			freopen("CONOUT$","w",stdout);
			ConsoleOpend = true;
		}
	}    
	#endif
#endif

    NW_REM_VMF_DEBUG_PRINTF("nw_vmf_connect(%s)",p_my_process_name);


	/* argument check */
    if (0 == message_queue_size)
    {
        NW_REM_VMF_DEBUG_ERROR("nw_vmf_connect()- message_queue_size=0)");
		return ((vmf_client_id_t)VMF_ERR_OUT_OF_RANGE);
    }

    if (message_size < sizeof(VMF_VAR_MSG_TYP(0)))
    {
        NW_REM_VMF_DEBUG_ERROR("nw_vmf_connect()- message_size < sizeof(VMF_VAR_MSG_TYP(0))");
        return ((vmf_client_id_t)VMF_ERR_OUT_OF_RANGE);
    }

    VMF_MUTEX_INIT
    VMF_CLIENT_LOCK

	/* get a free rcid */
	rcid = vmf_rem_get_free_rcid();

	/* connect to target - target handle is stored for this rcid */
	vmf_ret = vmf_target_tx_con_init(rcid,p_my_process_name);
	if (vmf_ret != VMF_OK)
	{
        /* error connecting to target */
		vmf_rem_free_rcid(rcid);
        NW_REM_VMF_DEBUG_ERROR("nw_vmf_connect(rcid=%d)- vmf_target_tx_con_init() failed",rcid);
		VMF_CLIENT_UNLOCK
		return ((vmf_client_id_t)vmf_ret);
	}

	/* send rpc message */
	{
		vmf_rpc_msg_t rpc_msg;

		rpc_msg.rpc_id = VMF_RPC_FKT_CONNECT;
		rpc_msg.r_cid = 255;
		rpc_msg.rpc_connect.message_queue_lenght.length  = message_queue_size;
		rpc_msg.rpc_connect.message_queue_msg_size.length = message_size;
        nw_os_sstrncpy(rpc_msg.rpc_connect.process_name, p_my_process_name, sizeof(rpc_msg.rpc_connect.process_name));

		/* get the rpc-msg length */
		vmf_ret = vmf_rem_get_rpc_msg_len(&(rpc_msg.msg_length.length),&rpc_msg);
		if (vmf_ret != VMF_OK)
		{
			vmf_rem_free_rcid(rcid);
	        NW_REM_VMF_DEBUG_ERROR("nw_vmf_connect(rcid=%d)- vmf_rem_get_rpc_msg_len() failed",rcid);
			VMF_CLIENT_UNLOCK
			return ((vmf_client_id_t)vmf_ret);
		}

		vmf_ret = vmf_target_call(rcid,&rpc_msg,&response);
		my_client_id = (vmf_client_id_t)vmf_ret;		

		/* store cid for this rcid*/
		VMF_RPC_CID(rcid) = my_client_id;

		if (vmf_ret>0)
		{
			/* crate a rx connection for this client */
			vmf_ret = vmf_target_rx_con_init(rcid);
			if (VMF_OK != vmf_ret)
			{
		        NW_REM_VMF_DEBUG_ERROR("nw_vmf_connect(rcid=%d)- vmf_target_rx_con_init() failed",rcid);
				vmf_rem_free_rcid(rcid);
				rcid = (vmf_client_id_t)vmf_ret;
			}
			else
			{
			    NW_REM_VMF_DEBUG_PRINTF("nw_vmf_connect(rcid=%d) ok",rcid);
			}
		}
		else
		{
		    NW_REM_VMF_DEBUG_ERROR("nw_vmf_connect(rcid=%d) vmf_target_call() failed ",rcid);
			vmf_rem_free_rcid(rcid);
			rcid = (vmf_client_id_t)vmf_ret;
		}
	}
	VMF_CLIENT_UNLOCK
	
	return (rcid);
}



/**************************************************************************//**
 *
 *   Function Name: nw_vmf_disconnect (vmf_client_id_t vmf_client_id)\n
 *   Description:   disconnect client \n
 *                  close tx channel and close and destroy rx channel.
 *
 *
 *   Parameters:    cid                                 (input) client id\n
 *   Return value:  \return vmf_ret_t error type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_disconnect( vmf_client_id_t rcid)      /*!< client id */
{
    vmf_ret_t   vmf_ret=VMF_OK;
	vmf_client_id_t vmf_client_id;

	NW_REM_VMF_DEBUG_PRINTF("nw_vmf_disconnect(%d)",rcid);

	vmf_client_id = VMF_RPC_CID(rcid);
	/* send the disconnect rpc message */
	{
		vmf_rpc_msg_t rpc_msg;
		vmf_rpc_response_t	response;

		rpc_msg.rpc_id = VMF_RPC_FKT_DISCONNECT;
		rpc_msg.r_cid = vmf_client_id;

		/* get the rpc-msg length */
		vmf_ret = vmf_rem_get_rpc_msg_len(&(rpc_msg.msg_length.length),&rpc_msg);
		if (vmf_ret != VMF_OK)
		{
			return (vmf_ret);
		}

		vmf_ret = vmf_target_call(rcid,&rpc_msg,&response);
	}

	/* wait some tine to allow the transfer of the disconnect message */
	Sleep(300);

	vmf_ret = vmf_target_disconnect(vmf_client_id);

    nw_vmf_co_client_free_buffer(cid_tab.my_cid[vmf_client_id].pcol_rx_buffer);
    cid_tab.my_cid[vmf_client_id].pcol_rx_buffer = NULL;
    nw_vmf_co_client_free_buffer(cid_tab.my_cid[vmf_client_id].pcol_tx_buffer);
    cid_tab.my_cid[vmf_client_id].pcol_tx_buffer = NULL;
	vmf_rem_free_rcid(rcid);

	return vmf_ret;
}




/**************************************************************************//**
 *
 *   Function Name: nw_vmf_connect_async (const char *pmy_process_name[31],
 *                                  void * cb_api_vmf_msg_receive_callback())\n
 *   Description:   register as a client to the vmf-server\n
 *                  A tx channel to the server is opened and an rx channel for this client is created.
 *
 *
 *   Parameters:    my_process_name                    (input) text-identifier or NULL\n
 *                  cb_api_vmf_msg_receive_callback()  rx callback function or NULL\n
 *                  callback_priority                  (input) priority of the callback thread\n
 *                  message_queue_size                 (input) size of the message queue \n
 *                  message_size                       (input) size of a single message \n
 *                  sync mode                          (input) VMF_SYNC_Q or VMF_ASYNC_Q \n
 *                  channel ID                         (input) OSAL coid \n
 *                  async_event                        (input) event that is fired \n
 *   Return value:  \return if >=0  then client-id else error as vmf_ret_t\n
 *
 ******************************************************************************/
vmf_client_id_t nw_vmf_connect_async
                                ( char *p_my_process_name,                            /*!< INPUT channel name or NULL  */
                                unsigned16 message_queue_size,                              /*!< INPUT queue size for receiving messages */
                                unsigned16 message_size,                                    /*!< INPUT message size for the queue */
                                unsigned32 osal_coid,                                       /*!< INPUT OSAL coid */
                                unsigned32 async_event)                                     /*!< INPUT OSAL event that is fired if vmf queue changed from empty to data */
{
	return VMF_ERR_NOT_SUPPORTED;
}




/**************************************************************************//**
 *
 *   Function Name: nw_vmf_register_ext_most_link (vmf_client_id_t vmf_client_id)
 *
 *   Description:   register a client as external MOST link
 *
 *   Parameters:    vmf_client_id    (input) connection client-id
 *
 *   Return value:  \return vmf_ret_t error type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_register_ext_most_link(vmf_client_id_t rcid) /*!< INPUT client id */
{
    vmf_ret_t			vmf_ret=VMF_OK;
	vmf_rpc_response_t	response;
	vmf_client_id_t		vmf_client_id;

	vmf_client_id = VMF_RPC_CID(rcid);
    /* argument check */
    if (vmf_client_id >=  MAX_SERVER_CONNECTIONS)
    {
        NW_REM_VMF_DEBUG_ERROR("pid=%d nw_vmf_register_ext_most_link()- argument error: invalid vmf_client_id",(int)getmypid());
        return (VMF_ERR_OUT_OF_RANGE);
    }

	/* send rpc message */
	{
		vmf_rpc_msg_t rpc_msg;

		rpc_msg.rpc_id = VMF_RPC_FKT_REGISTER_EXT_MOST_LINK;
		rpc_msg.r_cid = vmf_client_id;

		/* get the rpc-msg length */
		vmf_ret = vmf_rem_get_rpc_msg_len(&(rpc_msg.msg_length.length),&rpc_msg);
		if (vmf_ret != VMF_OK)
		{
			return (vmf_ret);
		}

		vmf_ret = vmf_target_call(rcid,&rpc_msg,&response);
	}
	
	return (vmf_ret);
}



/**************************************************************************//**
 *
 *   Function Name: nw_vmf_register_spy (vmf_client_id_t vmf_client_id)
 *
 *   Description:   register a client as spy
 *
 *   Parameters:    vmf_client_id    (input) connection client-id
 *
 *   Return value:  \return vmf_ret_t error type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_register_spy(vmf_client_id_t rcid) /*!< INPUT client id */
{
    vmf_ret_t			vmf_ret=VMF_OK;
	vmf_rpc_response_t	response;
	vmf_client_id_t		vmf_client_id;

    NW_REM_VMF_DEBUG_INFO("pid=%d nw_vmf_register_spy() rcid=%d",(int)getmypid(),rcid);
	vmf_client_id = VMF_RPC_CID(rcid);

    /* argument check */
    if (vmf_client_id >=  MAX_SERVER_CONNECTIONS)
    {
        NW_REM_VMF_DEBUG_ERROR("pid=%d nw_vmf_register_spy()- argument error: invalid vmf_client_id",(int)getmypid());
        return (VMF_ERR_OUT_OF_RANGE);
    }

	/* send rpc message */
	{
		vmf_rpc_msg_t rpc_msg;

		rpc_msg.rpc_id = VMF_RPC_FKT_REGISTER_SPY;
		rpc_msg.r_cid = vmf_client_id;

		/* get the rpc-msg length */
		vmf_ret = vmf_rem_get_rpc_msg_len(&(rpc_msg.msg_length.length),&rpc_msg);
		if (vmf_ret != VMF_OK)
		{
			return (vmf_ret);
		}

		vmf_ret = vmf_target_call(rcid,&rpc_msg,&response);
	}

    return (vmf_ret);
}




/**************************************************************************//**
 *
 *   Function Name: nw_vmf_register_most_fblock (vmf_client_id_t vmf_client_id
 *                                               unsigned8 fBlockId,unsigned8 instId)
 *
 *   Description:   register a local MOST Fblock
 *
 *   Parameters:    vmf_client_id       (input)connection client-id
 *                  fBlockId            (input)FBlock ID
 *                  instId              (input)Instant ID
 *
 *   Return value:  \return vmf_ret_t error type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_register_most_fblock  (vmf_client_id_t rcid,  /**< INPUT connection client-id*/
                                        unsigned8 fBlockId,             /**< INPUT FBlock ID*/
                                        unsigned8 instId)               /**< INPUT Instant ID*/
{
    vmf_ret_t			vmf_ret=VMF_OK;
	vmf_rpc_response_t	response;
	vmf_client_id_t		vmf_client_id;

	vmf_client_id = VMF_RPC_CID(rcid);

    /* argument check */
    if (vmf_client_id >= MAX_SERVER_CONNECTIONS)
    {
        NW_REM_VMF_DEBUG_ERROR("pid=%d nw_vmf_register_most_fblock()- argument error: invalid vmf_client_id",(int)getmypid());
        return (VMF_ERR_OUT_OF_RANGE);
    }

	/* send rpc message */
	{
		vmf_rpc_msg_t rpc_msg;

		rpc_msg.rpc_id	= VMF_RPC_FKT_REGISTER_MOST_FB;
		rpc_msg.r_cid	= vmf_client_id;
		
		rpc_msg.rpc_reg_fblock.fBlockId =fBlockId;
		rpc_msg.rpc_reg_fblock.instId = instId;

		/* get the rpc-msg length */
		vmf_ret = vmf_rem_get_rpc_msg_len(&(rpc_msg.msg_length.length),&rpc_msg);
		if (vmf_ret != VMF_OK)
		{
			return (vmf_ret);
		}


		vmf_ret = vmf_target_call(rcid,&rpc_msg,&response);
	}

    return (vmf_ret);
}




/**************************************************************************//**
 *
 *   Function Name: nw_vmf_de_register_most_fblock(vmf_client_id_t vmf_client_id
 *                                                 unsigned8 fBlockId,unsigned8 instId)
 *
 *   Description:   de-register a local MOST Fblock
 *
 *   Parameters:    vmf_client_id       (input)connection client-id
 *                  fBlockId            (input)FBlock ID
 *                  instId              (input)Instant ID
 *
 *   Return value:  \return vmf_ret_t error type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_de_register_most_fblock(vmf_client_id_t rcid,     /**< INPUT connection client-id */
                                         unsigned8 fBlockId,                /**< INPUT FBlock ID */
                                         unsigned8 instId)                  /**< INPUT Instant ID */
{
    vmf_ret_t			vmf_ret=VMF_OK;
	vmf_rpc_response_t	response;
	vmf_client_id_t		vmf_client_id;

	vmf_client_id = VMF_RPC_CID(rcid);


    /* argument check */
    if (vmf_client_id >= MAX_SERVER_CONNECTIONS)
    {
        NW_REM_VMF_DEBUG_ERROR("pid=%d nw_vmf_de_register_most_fblock()- argument error: invalid vmf_client_id",(int)getmypid());
        return (VMF_ERR_OUT_OF_RANGE);
    }

	/* send rpc message */
	{
		vmf_rpc_msg_t rpc_msg;

		rpc_msg.rpc_id	= VMF_RPC_FKT_DEREGISTER_MOST_FB;
		rpc_msg.r_cid	= vmf_client_id;
		
		rpc_msg.rpc_reg_fblock.fBlockId =fBlockId;
		rpc_msg.rpc_reg_fblock.instId = instId;

		/* get the rpc-msg length */
		vmf_ret = vmf_rem_get_rpc_msg_len(&(rpc_msg.msg_length.length),&rpc_msg);
		if (vmf_ret != VMF_OK)
		{
			return (vmf_ret);
		}



		vmf_ret = vmf_target_call(rcid,&rpc_msg,&response);
	}

    return (vmf_ret);
}



/**************************************************************************//**
 *
 *   Function Name: nw_vmf_register_most_shadow (vmf_client_id_t vmf_client_id
 *                                               unsigned8 fBlockId,unsigned8 instId,
 *                                               unsigned16 fcIds_num,unsigned16 *funcIds)
 *
 *   Description:   register a local MOST Shadow (FuncIds are to be given)
 *
 *   Parameters:    vmf_client_id       (input)connection client-id
 *                  fBlockId            (input)FBlock ID
 *                  instId              (input)Instant ID
 *                  fcIds_num           (input)number of function ID's in list
 *                  *funcIds            (input)pointer to a list of function ID's
 *
 *   Return value:  \return vmf_ret_t error type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_register_most_shadow  (vmf_client_id_t rcid,			/**< INPUT connection client-id */
                                        unsigned8 fBlockId,             /**< INPUT FBlock ID */
                                        unsigned8 instId,               /**< INPUT Instant ID */
                                        unsigned16 fcIds_num,           /**< INPUT number of function ID's in list */
                                        unsigned16 *funcIds)            /**< INPUT pointer to a list of function ID's*/
{
    vmf_ret_t			vmf_ret=VMF_OK;
    unsigned16			uCnt;
	vmf_rpc_response_t	response;
	vmf_client_id_t		vmf_client_id;

	vmf_client_id = VMF_RPC_CID(rcid);


    /* argument check */
#ifndef ALLOW_EMPTY_SH_LIST
    if (NULL == funcIds)
    {
        NW_REM_VMF_DEBUG_ERROR("pid=%d nw_vmf_register_most_shadow() - argument error: NULL pointer",(int)getmypid());
        return (VMF_ERR_NULL_POINTER);
    }
#endif

#ifdef DO_CLIENT_DEBUG_SHADOW
    {
        int iCnt;
        NW_VMF_DEBUG_PRINT(NW_VMF_DBG_ASP_CLIENT_LIB,NW_VMF_DBG_LVL_INFO,"nw_vmf_register_most_shadow fBlockId=%d,instId=%d,function-no=%d -list= ", fBlockId,instId,fcIds_num);
        for (iCnt=0;iCnt<fcIds_num;iCnt++)
        {
            NW_VMF_DEBUG_PRINT(NW_VMF_DBG_ASP_CLIENT_LIB,NW_VMF_DBG_LVL_INFO,"%d ", funcIds[iCnt]);
        }
        NW_VMF_DEBUG_PRINT(NW_VMF_DBG_ASP_CLIENT_LIB,NW_VMF_DBG_LVL_INFO,"\n");
    }
#endif

    if (vmf_client_id >= MAX_SERVER_CONNECTIONS)
    {
        NW_REM_VMF_DEBUG_ERROR("pid=%d nw_vmf_register_most_shadow()- argument error: invalid vmf_client_id",(int)getmypid());
        return (VMF_ERR_OUT_OF_RANGE);
    }

	/* send rpc message */
	{
		vmf_rpc_msg_t rpc_msg;

		rpc_msg.rpc_id	= VMF_RPC_FKT_REGISTER_MOST_SHAD;
		rpc_msg.r_cid	= vmf_client_id;
		rpc_msg.rpc_reg_shadow.fBlockId = fBlockId;
		rpc_msg.rpc_reg_shadow.instId = instId;
		rpc_msg.rpc_reg_shadow.fcIds_num.length  =  fcIds_num;
		for (uCnt =0; uCnt < fcIds_num; uCnt++)
	    {
			rpc_msg.rpc_reg_shadow.funcIds[uCnt].length = funcIds[uCnt];
	    }

		/* get the rpc-msg length */
		vmf_ret = vmf_rem_get_rpc_msg_len(&(rpc_msg.msg_length.length),&rpc_msg);
		if (vmf_ret != VMF_OK)
		{
			return (vmf_ret);
		}

		vmf_ret = vmf_target_call(rcid,&rpc_msg,&response);
	}



    /* transfer control message */
    return (vmf_ret);
}


/**************************************************************************//**
 *
 *   Function Name: nw_vmf_de_register_most_shadow (vmf_client_id_t vmf_client_id
 *                                               unsigned8 fBlockId,unsigned8 instId)
 *
 *   Description:   de-register a local MOST Shadow
 *
 *   Parameters:    vmf_client_id       (input)connection client id
 *                  fBlockId            (input)FBlock ID
 *                  instId              (input)Instant ID
 *
 *   Return value:  \return vmf_ret_t error type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_de_register_most_shadow(vmf_client_id_t rcid,				/**<INPUT connection client id*/
                                         unsigned8 fBlockId,                /**<INPUT FBlock ID*/
                                         unsigned8 instId)                  /**<INPUT Instant ID*/
{
    vmf_ret_t			vmf_ret=VMF_OK;
	vmf_rpc_response_t	response;
	vmf_client_id_t		vmf_client_id;

	vmf_client_id = VMF_RPC_CID(rcid);


    /* argument check */
    if (vmf_client_id >= MAX_SERVER_CONNECTIONS)
    {
        NW_REM_VMF_DEBUG_ERROR("pid=%d nw_vmf_de_register_most_shadow()- argument error: invalid vmf_client_id",(int)getmypid());
        return (VMF_ERR_OUT_OF_RANGE);
    }

	/* send rpc message */
	{
		vmf_rpc_msg_t rpc_msg;

		rpc_msg.rpc_id	= VMF_RPC_FKT_DEREGISTER_MOST_SHAD;
		rpc_msg.r_cid	= vmf_client_id;
		
		rpc_msg.rpc_reg_fblock.fBlockId =fBlockId;
		rpc_msg.rpc_reg_fblock.instId = instId;

		/* get the rpc-msg length */
		vmf_ret = vmf_rem_get_rpc_msg_len(&(rpc_msg.msg_length.length),&rpc_msg);
		if (vmf_ret != VMF_OK)
		{
			return (vmf_ret);
		}

		vmf_ret = vmf_target_call(rcid,&rpc_msg,&response);
	}

    /* transfer control message */
    return (vmf_ret);
}




/**************************************************************************//**
 *
 *   Function Name: nw_vmf_register_msg_group (vmf_client_id_t vmf_client_id
 *                                             unsigned16 groups_num,unsigned8 * groupList)
 *
 *   Description:   register for a none-MOST message groups
 *
 *   Parameters:    vmf_client_id       (input)connection client id
 *                  groups_num          (input)number of groups in List
 *                  *groupList          (input)pointer ro a list of message groups
 *
 *   Return value:  \return vmf_ret_t error type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_register_msg_group (vmf_client_id_t rcid,		/**<INPUT connection client id*/
                                     unsigned16 groups_num,     /**<INPUT number of groups in List*/
                                     unsigned8 * groupList)     /**<INPUT pointer ro a list of message groups*/
{
    vmf_ret_t			vmf_ret=VMF_OK;
	vmf_rpc_response_t	response;
	vmf_client_id_t		vmf_client_id;

	vmf_client_id = VMF_RPC_CID(rcid);


    NW_REM_VMF_DEBUG_INFO("nw_vmf_register_msg_group(rcid=%d)",rcid);
#ifdef DO_CLIENT_DEBUG_HEX
	nw_vmf_HexDump("info:  nw_vmf_register_msg_group() groups:",(unsigned8 *)groupList,groups_num);
#endif

    /* argument check */
    if (NULL == groupList)
    {
        NW_REM_VMF_DEBUG_ERROR("pid=%d nw_vmf_register_msg_group() - argument error: NULL pointer",(int)getmypid());
        return (VMF_ERR_NULL_POINTER);
    }

    if (groups_num > MAX_GROUP_NUM)
    {
        NW_REM_VMF_DEBUG_ERROR("pid=%d nw_vmf_register_msg_group() - argument error: groups_num > MAX_GROUP_NUM",(int)getmypid());
        return (VMF_ERR_OUT_OF_RANGE);
    }

#ifdef DO_CLIENT_DEBUG
    NW_REM_VMF_DEBUG_INFO("nw_vmf_register_msg_group(rcid=%d) call nw_vmf_ipc_send",rcid);
#endif

	/* send rpc message */
	{
		vmf_rpc_msg_t rpc_msg;

		rpc_msg.rpc_id	= VMF_RPC_FKT_REGISTER_MSG_GRP;
		rpc_msg.r_cid	= vmf_client_id;
		rpc_msg.rpc_reg_group.grps_num = (unsigned8)groups_num;

	    if (groups_num > 0)
		{
			memcpy(rpc_msg.rpc_reg_group.grps,groupList,groups_num);
	    }

		/* get the rpc-msg length */
		vmf_ret = vmf_rem_get_rpc_msg_len(&(rpc_msg.msg_length.length),&rpc_msg);
		if (vmf_ret != VMF_OK)
		{
			return (vmf_ret);
		}


		vmf_ret = vmf_target_call(rcid,&rpc_msg,&response);
	}

    NW_REM_VMF_DEBUG_INFO("nw_vmf_register_msg_group(rcid=%d) ret=%d",rcid,vmf_ret);

    return (vmf_ret);
}

/**************************************************************************//**
 *
 *   Function Name: nw_vmf_deregister_msg_group (vmf_client_id_t vmf_client_id
 *                                              unsigned16 groups_num,unsigned8 * groupList)
 *
 *   Description:   de-register for a none-MOST message groups
 *
 *   Parameters:    vmf_client_id       (input)connection_id
 *                  groups_num          (input)number of groups in List
 *                  *groupList          (input)pointer to a list of message groups
 *
 *   Return value:  \return vmf_ret_t error type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_de_register_msg_group  (vmf_client_id_t rcid,			/**<INPUT connection_id*/
                                        unsigned16 groups_num,          /**<INPUT number of groups in List*/
                                        unsigned8 * groupList)          /**<INPUT pointer to a list of message groups*/
{
    vmf_ret_t			vmf_ret=VMF_OK;
	vmf_rpc_response_t	response;
	vmf_client_id_t		vmf_client_id;

	vmf_client_id = VMF_RPC_CID(rcid);


    /* argument check */
    if (NULL == groupList)
    {
        NW_REM_VMF_DEBUG_ERROR("pid=%d nw_vmf_de_register_msg_group() - argument error: NULL pointer",(int)getmypid());
        return (VMF_ERR_NULL_POINTER);
    }

    if (groups_num > MAX_GROUP_NUM)
    {
        NW_REM_VMF_DEBUG_ERROR("pid=%d nw_vmf_de_register_msg_group() - argument error: groups_num > MAX_GROUP_NUM",(int)getmypid());
        return (VMF_ERR_OUT_OF_RANGE);
    }

	/* send rpc message */
	{
		vmf_rpc_msg_t rpc_msg;

		rpc_msg.rpc_id	= VMF_RPC_FKT_DEREGISTER_MSG_GRP;
		rpc_msg.r_cid	= vmf_client_id;
		rpc_msg.rpc_reg_group.grps_num = (unsigned8)groups_num;

	    if (groups_num > 0)
		{
			memcpy(rpc_msg.rpc_reg_group.grps,groupList,groups_num);
	    }

		/* get the rpc-msg length */
		vmf_ret = vmf_rem_get_rpc_msg_len(&(rpc_msg.msg_length.length),&rpc_msg);
		if (vmf_ret != VMF_OK)
		{
			return (vmf_ret);
		}

		vmf_ret = vmf_target_call(rcid,&rpc_msg,&response);
	}


    /* transfer control message */
    return (vmf_ret);
}


/**************************************************************************//**
 *
 *   Function Name: nw_vmf_send_most_async (vmf_client_id_t vmf_client_id
 *                                          vmf_most_msg_t *p_vmf_msg)
 *
 *   Description:   To send a most-async msg (most high message)
 *
 *   Parameters:    vmf_client_id       (input)connection_id
 *                  p_vmf_msg           (input)pointer to a MOST vmf_message
 *
 *   Return value:  \return vmf_ret_t error type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_send_most_async      (vmf_client_id_t rcid,				/**<INPUT connection_id*/
                                       vmf_most_msg_t * p_vmf_msg)        /**<INPUT pointer to a MOST vmf_message*/
{
    vmf_ret_t			vmf_ret=VMF_OK;
	unsigned16			most_msg_len;
	vmf_rpc_response_t	response;
	vmf_client_id_t		vmf_client_id;

	vmf_client_id = VMF_RPC_CID(rcid);


#ifdef DO_CLIENT_DEBUG
    NW_VMF_DEBUG_PRINT(NW_VMF_DBG_ASP_CLIENT_LIB,NW_VMF_DBG_LVL_INFO,"nw_vmf_send_most_async()");
#endif

    /* argument check */
    if (NULL == p_vmf_msg)
    {
        NW_REM_VMF_DEBUG_ERROR("pid=%d nw_vmf_send_most_async() - argument error: NULL pointer",(int)getmypid());
        return (VMF_ERR_NULL_POINTER);
    }

	/* check message size */
	if (p_vmf_msg->data.length > VMF_REM_MAX_DATA_SIZE)
    {
        NW_REM_VMF_DEBUG_ERROR("pid=%d nw_vmf_send_most_async() - to much data =%d bytes",(int)getmypid(),p_vmf_msg->data.length);
        return (VMF_ERR_OUT_OF_RANGE);
    }

	/* send rpc message */
	{
		vmf_rpc_msg_t rpc_msg;

		rpc_msg.rpc_id	= VMF_RPC_FKT_SEND_MOST_ASYNC;
		rpc_msg.r_cid	= vmf_client_id;
	    p_vmf_msg->msg_base.base.msg_type  = MSG_TYPE_MOST_MESSAGE;

		vmf_ret = vmf_rem_get_vmf_msg_len(&most_msg_len,(vmf_msg_t *)p_vmf_msg);
		if (vmf_ret != VMF_OK)
		{
			return (vmf_ret);
		}
		memcpy(&rpc_msg.rpc_send_most.vmf_most_msg,p_vmf_msg,most_msg_len);

		/* get the rpc-msg length */
		vmf_ret = vmf_rem_get_rpc_msg_len(&(rpc_msg.msg_length.length),&rpc_msg);
		if (vmf_ret != VMF_OK)
		{
			return (vmf_ret);
		}


		vmf_ret = vmf_target_call(rcid,&rpc_msg,&response);
	}

    return (vmf_ret);
}




/**************************************************************************//**
 *
 *   Function Name: nw_vmf_send_most_ctrl (vmf_client_id_t vmf_client_id
 *                                         vmf_most_msg_t *p_vmf_msg)
 *
 *   Description:   To send a most-control msg
 *
 *   Parameters:    vmf_client_id       (input)connection_id
 *                  p_vmf_msg           (input)pointer to a MOST vmf_message
 *
 *   Return value:  \return vmf_ret_t error type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_send_most_ctrl     (vmf_client_id_t rcid,				/**<INPUT connection_id*/
                                    vmf_most_msg_t * p_vmf_msg)        /**<INPUT pointer to a MOST vmf_message*/
{
    vmf_ret_t			vmf_ret=VMF_OK;
	unsigned16			most_msg_len;
	vmf_rpc_response_t	response;
	vmf_client_id_t		vmf_client_id;

	vmf_client_id = VMF_RPC_CID(rcid);

#ifdef DO_CLIENT_DEBUG
    NW_VMF_DEBUG_PRINT(NW_VMF_DBG_ASP_CLIENT_LIB,NW_VMF_DBG_LVL_INFO,"nw_vmf_send_most_ctrl()");
#endif


    /* argument check */
    if (NULL == p_vmf_msg)
    {
        NW_REM_VMF_DEBUG_ERROR("pid=%d nw_vmf_send_most_ctrl() - argument error: NULL pointer",(int)getmypid());
        return (VMF_ERR_NULL_POINTER);
    }

	/* check message size */
	if (p_vmf_msg->data.length > VMF_REM_MAX_DATA_SIZE)
    {
        NW_REM_VMF_DEBUG_ERROR("pid=%d nw_vmf_send_most_ctrl() - to much data",(int)getmypid());
        return (VMF_ERR_OUT_OF_RANGE);
    }


	/* send rpc message */
	{
		vmf_rpc_msg_t rpc_msg;

		rpc_msg.rpc_id	= VMF_RPC_FKT_SEND_MOST_CTRL;
		rpc_msg.r_cid	= vmf_client_id;
	    p_vmf_msg->msg_base.base.msg_type  = MSG_TYPE_MOST_MESSAGE;
		
		/* copy MOST-VMF message*/
		vmf_ret = vmf_rem_get_vmf_msg_len(&most_msg_len,(vmf_msg_t *)p_vmf_msg);
		if (vmf_ret != VMF_OK)
		{
			return (vmf_ret);
		}

		memcpy(&rpc_msg.rpc_send_most.vmf_most_msg,p_vmf_msg,most_msg_len);

		/* get the rpc-msg length */
		vmf_ret = vmf_rem_get_rpc_msg_len(&(rpc_msg.msg_length.length),&rpc_msg);
		if (vmf_ret != VMF_OK)
		{
			return (vmf_ret);
		}


		vmf_ret = vmf_target_call(rcid,&rpc_msg,&response);
	}

    return (vmf_ret);
}



/**************************************************************************//**
 *
 *   Function Name: nw_vmf_send_basic (vmf_client_id_t vmf_client_id
 *                                     vmf_basic_msg_t *p_vmf_msg)
 *
 *   Description:   To send a basic msg
 *
 *   Parameters:    vmf_client_id  (input)connection_id
 *                  p_vmf_msg      (input)pointer to a basic vmf_message
 *
 *   Return value:  \return vmf_ret_t error type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_send_basic     (vmf_client_id_t rcid,				/**<INPUT connection_id*/
                                 vmf_basic_msg_t *p_vmf_msg)        /**<INPUT pointer to a basic vmf_message*/
{
    vmf_ret_t			vmf_ret=VMF_OK;
	unsigned16			basic_msg_len;
	vmf_rpc_response_t	response;
	vmf_client_id_t		vmf_client_id;

	vmf_client_id = VMF_RPC_CID(rcid);

	NW_REM_VMF_DEBUG_INFO("pid=%d nw_vmf_send_basic(%d) cid=%d",(int)getmypid(),rcid,vmf_client_id);

    /* argument check */
    if (NULL == p_vmf_msg)
    {
        NW_REM_VMF_DEBUG_ERROR("pid=%d nw_vmf_send_basic() - argument error: NULL pointer",(int)getmypid());
        return (VMF_ERR_NULL_POINTER);
    }

	/* check message size */
	if (p_vmf_msg->data.length > VMF_REM_MAX_DATA_SIZE)
    {
        NW_REM_VMF_DEBUG_ERROR("pid=%d nw_vmf_send_basic() - to much data",(int)getmypid());
        return (VMF_ERR_OUT_OF_RANGE);
    }
	/* send rpc message */
	{
		vmf_rpc_msg_t rpc_msg;

		rpc_msg.rpc_id	= VMF_RPC_FKT_SEND_BASIC;
		rpc_msg.r_cid	= vmf_client_id;
	    p_vmf_msg->msg_base.base.msg_type  = MSG_TYPE_BASIC_MESSAGE;

		vmf_ret = vmf_rem_get_vmf_msg_len(&basic_msg_len,(vmf_msg_t *)p_vmf_msg);
		if (vmf_ret != VMF_OK)
		{
			return (vmf_ret);
		}

		memcpy(&rpc_msg.rpc_send_basic.vmf_basic_msg,p_vmf_msg,basic_msg_len);

		/* get the rpc-msg length */
		vmf_ret = vmf_rem_get_rpc_msg_len(&(rpc_msg.msg_length.length),&rpc_msg);
		if (vmf_ret != VMF_OK)
		{
			return (vmf_ret);
		}


		vmf_ret = vmf_target_call(rcid,&rpc_msg,&response);
	}

	NW_REM_VMF_DEBUG_INFO("pid=%d nw_vmf_send_basic(rcid=%d) cid=%d, ret=%d",(int)getmypid(),rcid,vmf_client_id,vmf_ret);

    return (vmf_ret);
}


/**************************************************************************//**
 *
 *   Function Name: nw_vmf_send       (vmf_client_id_t vmf_client_id
 *                                     vmf_msg_t       *p_vmf_msg)
 *
 *   Description:   To send a msg (BASIC or MOST message)
 *                  message type is define in base.msg_type
 *
 *   Parameters:    vmf_client_id       (input)connection_id
 *                  p_vmf_msg           (input)pointer to a vmf_message
 *
 *   Return value:  \return vmf_ret_t error type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_send           (vmf_client_id_t rcid,			/**<INPUT connection_id*/
                                 vmf_msg_t * p_vmf_msg)         /**<INPUT pointer to a vmf_message*/
{
	vmf_client_id_t		vmf_client_id;

	vmf_client_id = VMF_RPC_CID(rcid);

	/* argument check */
    if (NULL == p_vmf_msg)
    {
        NW_REM_VMF_DEBUG_ERROR("pid=%d nw_vmf_send() - argument error: NULL pointer",(int)getmypid());
        return (VMF_ERR_NULL_POINTER);
    }

    if (vmf_client_id >= MAX_SERVER_CONNECTIONS)
    {
        if (0 == vmf_client_id)
        {
            NW_REM_VMF_DEBUG_ERROR("pid=%d nw_vmf_send()- error - client not connected",(int)getmypid());
        }
        else
        {
            NW_REM_VMF_DEBUG_ERROR("pid=%d nw_vmf_send()- argument error: invalid vmf_client_id=%d",(int)getmypid(),(int)vmf_client_id);
        }
        return (VMF_ERR_OUT_OF_RANGE);
    }


    if (p_vmf_msg->vmf_most_msg.msg_base.base.msg_type == MSG_TYPE_MOST_MESSAGE)
    {
        /* MOST message */
        return (nw_vmf_send_most_ctrl (vmf_client_id,(vmf_most_msg_t *)p_vmf_msg));
    }
    else
    {
        /* BASIC message */
        return (nw_vmf_send_basic (vmf_client_id,(vmf_basic_msg_t *)p_vmf_msg));
    }
}




/**************************************************************************//**
 *
 *   Function Name: nw_vmf_receive    (vmf_client_id_t vmf_conn_id
 *                                     vmf_msg_t    *p_vmf_msg)
 *
 *   Description:   receive a vmf message
 *                  function blocks until it receives a message
 *
 *   Parameters:    vmf_client_id       (input)connection_id
 *                  p_vmf_msg           (output)pointer to a vmf_message
 *
 *   Return value:  \return number of received data bytes if > 0 or error
 *
 ******************************************************************************/
signed16 nw_vmf_receive          (vmf_client_id_t rcid,				/**< INPUT connection_id*/
                                  vmf_msg_t * p_vmf_msg,            /**< OUTPUT pointer to a vmf_message*/
                                  unsigned16  vmf_buffer_length)    /**< INPUT length of COMPLETE message buffer */
{
    signed16			sReadSize=0;
    vmf_ret_t			vmf_ret=VMF_OK;
	vmf_client_id_t		vmf_client_id;
	/* receive buffer (2KB on the stack! )*/
	unsigned8			my_resp_buffer[sizeof(VMF_VAR_MSG_TYP(VMF_REM_MAX_DATA_SIZE)) + sizeof(vmf_rpc_response_t)];
	vmf_rpc_response_t*	p_response = (vmf_rpc_response_t*)&my_resp_buffer;

	vmf_client_id = VMF_RPC_CID(rcid);

	NW_REM_VMF_DEBUG_INFO("pid=%d nw_vmf_receive(rcid=%d) cid=%d, buffer_len=%d",(int)getmypid(),rcid,vmf_client_id,vmf_buffer_length);

    /* argument check */
    if (NULL == p_vmf_msg)
    {
        NW_REM_VMF_DEBUG_ERROR("pid=%d nw_vmf_receive()- argument error: NULL pointer",(int)getmypid());
        return (VMF_ERR_NULL_POINTER);
    }

    if ((0==vmf_client_id) || (vmf_client_id >= MAX_SERVER_CONNECTIONS))
    {
        NW_REM_VMF_DEBUG_ERROR("pid=%d nw_vmf_receive()- argument error: invalid vmf_client_id",(int)getmypid());
        return (VMF_ERR_OUT_OF_RANGE);
    }

	/* check message size */
	if (vmf_buffer_length > sizeof(VMF_VAR_MSG_TYP(VMF_REM_MAX_DATA_SIZE)))
    {
        NW_REM_VMF_DEBUG_ERROR("pid=%d nw_vmf_receive() -invalid vmf_msg_length",(int)getmypid());
        return (VMF_ERR_OUT_OF_RANGE);
    }

    /* check if there are messages in the collector buffer */
    vmf_ret = nw_vmf_co_receive (vmf_client_id,vmf_buffer_length, (vmf_basic_msg_t *)p_vmf_msg,&sReadSize);
    if (vmf_ret != VMF_OK)
	/* send rpc message */
	{
		/* no co message */
		vmf_rpc_msg_t rpc_msg;
		rpc_msg.rpc_id	= VMF_RPC_FKT_RECEIVE;
		rpc_msg.r_cid	= vmf_client_id;

		/* get the rpc-msg length */
		vmf_ret = vmf_rem_get_rpc_msg_len(&(rpc_msg.msg_length.length),&rpc_msg);
		if (vmf_ret != VMF_OK)
		{
			return (vmf_ret);
		}

		/* set maximum receive message lenght */
		rpc_msg.rpc_receive.vmf_msg_length.length = vmf_buffer_length;

		NW_REM_VMF_DEBUG_INFO("nw_vmf_receive(rcid=%d) call vmf_target_call_rx()",rcid);
		sReadSize = vmf_target_call_rx(rcid,&rpc_msg,p_response);
		NW_REM_VMF_DEBUG_INFO("nw_vmf_receive(rcid=%d) call vmf_target_call_rx() done",rcid);

		if (sReadSize > 0)
		{	
#ifdef DO_CLIENT_DEBUG_HEX
//			nw_vmf_HexDump("info:  vmf_client_rx_data",(unsigned8 *)p_response,sReadSize);
#endif
			/* copy vmf-message to destination buffer */
			if (sReadSize <= VMF_REM_MAX_DATA_SIZE)
			{		
				if (sReadSize > vmf_buffer_length)
				{
					/* cut message */
					memcpy(p_vmf_msg,&(p_response->vmf_msg),vmf_buffer_length);
				}
				else
				{
					memcpy(p_vmf_msg,&(p_response->vmf_msg),sReadSize);
				}


#ifdef DO_CLIENT_DEBUG_HEX
				nw_vmf_HexDump("info:  vmf_client_vmf_data",(unsigned8 *)p_vmf_msg,sReadSize);
#endif
				/* check if the received message is a co message */
				if (((COL_VMF_MSG == p_vmf_msg->vmf_basic_msg.msg_base.base.vmf_debug_82) ||
					 (COL_VMF_MSG_SPY== p_vmf_msg->vmf_basic_msg.msg_base.base.vmf_debug_82)) &&
					(p_vmf_msg->vmf_most_msg.msg_base.base.msg_type == MSG_TYPE_BASIC_MESSAGE))
				{
					/* store message in co buffer*/
					vmf_ret = nw_vmf_co_store_msg(vmf_client_id, (vmf_basic_msg_t *)p_vmf_msg,sReadSize);
					if (VMF_OK == vmf_ret)
					{
						/* get first message from buffer */
						vmf_ret = nw_vmf_co_receive (vmf_client_id,vmf_buffer_length, (vmf_basic_msg_t *)p_vmf_msg,&sReadSize);
				   }
				}
			}
			else
			{	
				/* message size invalid !*/
		        NW_REM_VMF_DEBUG_ERROR("pid=%d nw_vmf_receive(rcid=%d) - received to much data =%d bytes",(int)getmypid(),rcid,sReadSize);
				sReadSize = VMF_ERR_OUT_OF_RANGE;
			}	
		}
	}
	NW_REM_VMF_DEBUG_INFO("nw_vmf_receive(rcid=%d) cid=%d return %d",rcid,vmf_client_id,sReadSize);

    return(sReadSize);
}


/*****************************************************************************/
/*                          local functions                                  */
/*****************************************************************************/





/**************************************************************************//**
 *
 *   Function Name: vmf_client_mutex_init pthread_mutex_t *pMutex
 *
 *   Description:   initialize the vmf-clientMUTEX
 *
 *   Parameters:    pMutex              (output)pointer to mutex
 *
 *
 *   Function Return value: \return  true if OK else false
 *
 ******************************************************************************/
static bool nw_vmf_client_mutex_init(pthread_mutex_t *pMutex) /**< INPUT/OUTPUT pointer to a mutex*/
{
    pthread_mutexattr_t attr;
    static  unsigned  bInUse=0;

    NW_REM_VMF_DEBUG_PRINTF("nw_vmf_client_mutex_init()");


    if (bmyMutexInitialized != false)
    {
        /* mutex already created */
        return true;
    }

    if (0 != pthread_mutexattr_init(&attr))
    {
        NW_REM_VMF_DEBUG_ERROR("nw_vmf_client_mutex_init() - pthread_mutexattr_init() failed");
        return(false);
    }

    /* initialize mutex as a blocking mutex */
    if (0 != pthread_mutexattr_settype(&attr,PTHREAD_MUTEX_NORMAL))
    {
        NW_REM_VMF_DEBUG_ERROR("nw_vmf_client_mutex_init() - pthread_mutexattr_settype() failed");
        pthread_mutexattr_destroy(&attr);
        return(false);
    }

    if(pthread_mutex_init( pMutex, &attr ))
    {
        NW_REM_VMF_DEBUG_ERROR("nw_vmf_client_mutex_init() - pthread_mutex_init() failed");
        pthread_mutexattr_destroy(&attr);
        return(false);
    }
    pthread_mutexattr_destroy(&attr);
    bmyMutexInitialized = true;

  return(true);
}



/**************************************************************************//**
 *
 *   Function Name: myhexdump(char *chPrefixText, unsigned char *u8mem, unsigned length)
 *
 *   Description:   create a ascii hex dump
 *
 *   Parameters:    chPrefixText        (input) pointer to prefix text\n
 *                  u8mem               (input) pointer to data to be displayed\n
 *                  length              (input) size of display data\n
 *
 *   Function Return value: - \return void
 *
 ******************************************************************************/
static void __nw_vmf_HexDump  (char *chPrefixText,    /*!< INPUT pointer to prefix text */
                      unsigned char *u8mem,  /*!< INPUT pointer to data to be displayedt */
                      unsigned length)       /*!< INPUT size of display data */
{
    char        line[2048];
    unsigned16  uCnt;

    char *t = line;

    if (sizeof(line) < ((length*4) + strlen(chPrefixText)))
    {
        length = (unsigned)(sizeof(line)/4)-strlen(chPrefixText);
    }

    t += sprintf(t, "%s: ", chPrefixText);

    for (uCnt = 0; uCnt < length; uCnt++)
    {
        t += sprintf(t, "%02x ", u8mem[uCnt]);
    }
    t += sprintf(t, "\n");
    fprintf(stdout,line);
}

/*************************************************************************//**
 *
 *   hex_dump
 *   NOTE: hex dump a buffer
 *   
 *
 *   \param[in] unsigned8 *     - pointer to bufer  
 *   \param[in] len             - length of bufer   
 *   \return    void 
 *
 ******************************************************************************/
void nw_vmf_HexDump(char * name,unsigned8 *buffer,unsigned len)
{
#define CPL 16
    static  bool b_in_use = false;
    unsigned     i,j, ct;
    char    asci[2*CPL+1];

    if (buffer == NULL)
    {
        return;
    }

    while (b_in_use)
    {
        delay(1);
    }
    b_in_use = true;


    if (len <= 0) 
    {
        b_in_use = false;
        return;
    }

    printf("%s\n",name);
    for (i=0,j=0; i<len; ++i) 
    {
        asci[j]='.';
        asci[j+1]=0;

        ct = (int)buffer[i];
        printf("%02x ", ct);
        if ((ct > 0x1f) && (ct < 0x7f))
        {
            asci[j]=ct;
        }

        if ((((i+1) % CPL) == 0))
        {
            printf("    %s\n",asci);
            asci[0]=0;
            j=0;
        }
        else
        {
            j+=1;
        }
    }
    for (; j<CPL; ++j) 
    {
        printf("   ");
    }

    printf("    %s\n\n",asci);
    b_in_use = false;
}


/**************************************************************************//**
 *
 *   Function Name: getmypid()
 *
 *   Description:   get the pid
 *
 *   Parameters:
 *
 *   Function Return value: - \return void
 *
 ******************************************************************************/
static unsigned32 getmypid(void)
{
    static unsigned32 u32myPid = 0;

    if (0 == u32myPid )
    {
        u32myPid= getpid();
    }
    return u32myPid;
}

/**************************************************************************//**
 *
 *   Function Name: ini_cid_tab    (my_cid_tab_t *pcid_tab)
 *
 *   Description:   initialize the cid table
 *
 *
 *   Parameters:    pcid_tab            (input)pointer to cid table
 *
 *   Return value:  \return void
 *
 ******************************************************************************/
static void nw_vmf_ini_cid_tab            (my_cid_tab_t *pcid_tab) /**< INPUT pointer to cid table*/
{
    unsigned8 u8Cnt;

#ifdef DO_CLIENT_DEBUG
    NW_VMF_DEBUG_PRINT(NW_VMF_DBG_ASP_CLIENT_LIB,NW_VMF_DBG_LVL_INFO,"vmf-client-lib: nw_vmf_ini_cid_tab()");
#endif
    if (cid_tab_init_done)
    {
        /* cid-tab already initialized */
        return;
    }

    cid_tab_init_done=true;
    /* mhammer3, tms 85418, cid must not be 0*/
    pcid_tab->free_cid=INITAL_CID_VALUE;
    pcid_tab->pid = getmypid();

    /* delete name, list and vmf_handles */
    for (u8Cnt = 0; u8Cnt < MAX_SERVER_CONNECTIONS; u8Cnt++)
    {
        pcid_tab->my_cid[u8Cnt].in_use = false;
        pcid_tab->my_cid[u8Cnt].my_channel_name[0]=0;
        pcid_tab->my_cid[u8Cnt].tx_handle = VMF_HANDLE_INVALID;
        pcid_tab->my_cid[u8Cnt].rx_handle = VMF_HANDLE_INVALID;
        pcid_tab->my_cid[u8Cnt].cb = NULL;
        pcid_tab->my_cid[u8Cnt].pcol_rx_buffer = NULL;
        pcid_tab->my_cid[u8Cnt].col_rx_buffer_len = 0;
        pcid_tab->my_cid[u8Cnt].col_rx_buffer_msg_num = 0;
        pcid_tab->my_cid[u8Cnt].pcol_tx_buffer = NULL;
        pcid_tab->my_cid[u8Cnt].col_tx_buffer_len = 0;
        pcid_tab->my_cid[u8Cnt].col_tx_buffer_msg_num = 0;
        pcid_tab->my_cid[u8Cnt].collector_timeout = 0;
        pcid_tab->my_cid[u8Cnt].receiver_started=false;
    }
}


 /**************************************************************************//**
 *					vmf-co functions
 ******************************************************************************/

 /**************************************************************************//**
 *
 *   Function Name: nw_vmf_co_receive()
 *
 *   Description:   reveive a message collector message
 *
 *
 *   Parameters:    vmf_client_id_t     (input)     client id
 *                  dest_buffer_len     (input)     length of destination buffer
 *                  pdest_vmf_msg       (output)    pointer to destination message buffer
 *                  dest_read_num_bytes (output)    pointer to received message length    
 *
 *   Return value:  vmf_ret_t
 *
 ******************************************************************************/
static vmf_ret_t nw_vmf_co_receive (vmf_client_id_t vmf_client_id,unsigned16 dest_buffer_len,
                                    vmf_basic_msg_t *pdest_vmf_msg,unsigned16 *dest_read_num_bytes)
{   
    vmf_ret_t       vmf_ret = VMF_ERR_NO_MORE_DATA;
    vmf_basic_msg_t *pvmf_co_buffer=NULL;
    unsigned16      col_rx_buffer_len=0;
    
    
    pvmf_co_buffer    = cid_tab.my_cid[vmf_client_id].pcol_rx_buffer;
    col_rx_buffer_len = cid_tab.my_cid[vmf_client_id].col_rx_buffer_len;
    
    /* check if there are still messages in the co-buffer  */
    if (NULL != pvmf_co_buffer)
    {
        if (cid_tab.my_cid[vmf_client_id].col_rx_buffer_msg_num > 0)
        {
            unsigned16      msg_len;
            
            /* get next message from co-buffer */
            vmf_ret = nw_vmf_co_client_get_next_co_msg (pvmf_co_buffer, col_rx_buffer_len,pdest_vmf_msg,dest_buffer_len);
            if (VMF_OK == vmf_ret)
            {
                /* check if message is an embedded message */    
                if (pdest_vmf_msg->msg_base.base.msg_type == MSG_TYPE_BASIC_EMBEDDED_MESSAGE)
                {
                    /* get embedded message */
					memmove(pdest_vmf_msg,(vmf_basic_msg_t*)pdest_vmf_msg->data.pl,pdest_vmf_msg->data.length);
                    /* get new message length */
                    vmf_ret = nw_vmf_co_client_get_msg_len((vmf_msg_t*)pdest_vmf_msg,&msg_len);
				    NW_REM_VMF_DEBUG_PRINTF("nw_vmf_co_receive() get embedded message, vmf_ret=%d, msg-type=%d, msg_len=%d",vmf_ret,pdest_vmf_msg->msg_base.base.msg_type,msg_len);
                    *dest_read_num_bytes = msg_len;
                }
                else
                {
                    /* message is a basic message */
                    msg_len = VMF_BASIC_MSG_HEADER_SIZE + pdest_vmf_msg->data.length;
    #ifdef DO_CLIENT_DEBUG_HEX
                    if (msg_len > 0)
                    {
                        nw_vmf_HexDump("vmf-client-lib: nw_vmf_co_receive() data from co=", (unsigned8 *)pdest_vmf_msg, msg_len);
                    }
                    NW_VMF_DEBUG_INFO("nw_vmf_co_receive() msg-len=%d",msg_len);                
    #endif                   
                    *dest_read_num_bytes = msg_len;
                }
            }
            else
            {
                /* no more messages - discard buffer */
                cid_tab.my_cid[vmf_client_id].col_rx_buffer_msg_num = 0;
            }
        }
        else
        {
#ifdef DO_CLIENT_DEBUG
            NW_VMF_DEBUG_INFO("nw_vmf_co_receive()col_rx_buffer_msg_num=%d",cid_tab.my_cid[vmf_client_id].col_rx_buffer_msg_num);                
#endif            
        }
    }
    return vmf_ret;
}


/**************************************************************************//**
 *
 *   Description:   get next message from the co-buffer
 *
 *
 *   Parameters:    msg_num           (input) number of message read from co-buffer 
 *                                            first message has index 0
 *                  pco_mutex         (input) pointer to mutex
 *                  pvmf_co_msg       (input) collector message buffer
 *                  co_msg_len        (input) size of collector message buffer
 *                  pvmf_msg          (inout) vmf message destination buffer
 *                  msg_buffer_len    (input) size of destination buffer
 *
 *
 *   Return value:  vmf_ret_t    
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_co_client_get_next_co_msg ( vmf_basic_msg_t  *pvmf_co_msg, unsigned16 co_msg_buff_len, vmf_basic_msg_t  *pvmf_dest_msg, unsigned16 msg_buffer_len)
{
    vmf_ret_t   vmf_ret = VMF_OK;
    unsigned8   current_msg=0;
    unsigned8   num_msgs=0;
    unsigned8   client_count=0;
    
    /* argument check */
    if (NULL == pvmf_co_msg)
    {
        NW_VMF_DEBUG_ERROR("vmf-client-lib: nw_vmf_co_client_next_next_co_msg() - pvmf_co_msg=NULL");
        vmf_ret = VMF_ERR_NULL_POINTER;
    }
    else if (NULL == pvmf_dest_msg)
    {
        NW_VMF_DEBUG_ERROR("vmf-client-lib: nw_vmf_co_client_next_next_co_msg() - *pvmf_msg=NULL");
        vmf_ret = VMF_ERR_NULL_POINTER;
    }
    else if (0 == msg_buffer_len)
    {
        NW_VMF_DEBUG_ERROR("vmf-client-lib: nw_vmf_co_client_next_next_co_msg() - msg_buffer_len=0");
        vmf_ret = VMF_ERR_OUT_OF_RANGE;
    }
    if (VMF_OK != vmf_ret)
    {
        return vmf_ret;
    }

    /* check if last message is reached */
    num_msgs = pvmf_co_msg->msg_base.base.vmf_debug_83;
    current_msg = pvmf_co_msg->msg_base.base.vmf_debug_84;
    client_count = pvmf_co_msg->msg_base.base.vmf_debug_8;  /* use client count from co-buffer */
    
    
    if (current_msg >= num_msgs)
    {
        /* last message read */
        pvmf_co_msg->msg_base.base.vmf_debug_83 = 0;        /* num_msgs */
        pvmf_co_msg->msg_base.base.vmf_debug_84 = 0;        /* curr_msg */
        vmf_ret = VMF_ERR_NO_MORE_DATA;     
    }
    else
    {
        #define     len_offset offsetof(vmf_basic_msg_t,data.length)
        unsigned8   msg_num=0;
        unsigned8   *pmsg_ptr=NULL;
        unsigned16  msg_pl_len=0;
        unsigned16  msg_len=0;
        
        pmsg_ptr = pvmf_co_msg->data.pl;                    /* address of first collected VMF msg */
        memcpy (&msg_pl_len,&(pmsg_ptr[len_offset]),sizeof(unsigned16));
        msg_len = msg_pl_len + VMF_BASIC_MSG_HEADER_SIZE;
        
        for (msg_num = 0; msg_num < current_msg; msg_num++)
        {
            /* get pl length of the current vmf message */
            /* we can not just cast to a vmf_basic_msg_t because the messages */
            /* in the buffer are not aligned !!                               */
            pmsg_ptr += msg_len;
            memcpy (&msg_pl_len,&(pmsg_ptr[len_offset]),sizeof(msg_pl_len));
            msg_len = msg_pl_len + VMF_BASIC_MSG_HEADER_SIZE;
        }
       
        /* pmsg_ptr is now pointing to the requested vmf-message */
        current_msg++;
        pvmf_co_msg->msg_base.base.vmf_debug_84 = current_msg;
        pvmf_dest_msg->msg_base.base.vmf_debug_8  = client_count;
        nw_os_smemcpy(pvmf_dest_msg,msg_buffer_len,pmsg_ptr,msg_len);
        
        vmf_ret = VMF_OK;
       
    }
    
    return vmf_ret;
}


 /**************************************************************************//**
 *
 *   Function Name: nw_vmf_co_store_msg()
 *
 *   Description:   store a co message in a co buffer
 *
 *
 *   Parameters:    vmf_client_id_t     (input)     client id
 *                  pco_vmf_msg         (input)     vmf co-messgae
 *                  co_vmf_msg_len      (input)     size of vmf co-message
 *
 *   Return value:  vmf_ret_t
 *
 ******************************************************************************/
static vmf_ret_t nw_vmf_co_store_msg (vmf_client_id_t vmf_client_id, vmf_basic_msg_t *pco_vmf_msg,unsigned16 co_vmf_msg_len)
{   
    unsigned16 blen = VMF_BASIC_MSG_HEADER_SIZE + VMF_CO_DATA_LEN + 1;
    vmf_ret_t       vmf_ret = VMF_OK;

    if (co_vmf_msg_len > blen)
    {
        /* message will not fit into buffer */
        #ifdef DO_CLIENT_DEBUG
        NW_VMF_DEBUG_INFO("%s: vmf-client-lib: nw_vmf_co_store_msg() co-message to big to fit in co-buffer",__progname);
        #endif        
        return VMF_ERR_CO_BUFFER;
    }
            
    /* check if a buffer was already allocated */
    if (NULL == cid_tab.my_cid[vmf_client_id].pcol_rx_buffer)
    {
        /* allocate a buffer */
        vmf_ret = nw_vmf_co_client_get_buffer(&(cid_tab.my_cid[vmf_client_id].pcol_rx_buffer),blen);
        if (vmf_ret != VMF_OK)
        {
            vmf_ret = VMF_ERR_CO_BUFFER;
        }
    }

    if (VMF_OK == vmf_ret)
    {
        /* copy the received vmf message to the co-buffer*/
        /* store buffer len */
        nw_os_smemcpy((void*)cid_tab.my_cid[vmf_client_id].pcol_rx_buffer,blen,(void*)pco_vmf_msg,co_vmf_msg_len);

        /* store number of vmf messages that are stored in co-buffer and buffer len in client struct */
        cid_tab.my_cid[vmf_client_id].col_rx_buffer_len = blen;
        cid_tab.my_cid[vmf_client_id].col_rx_buffer_msg_num = pco_vmf_msg->msg_base.base.vmf_debug_83; 
    }
    return vmf_ret;
}


 /**************************************************************************//**
 *
 *   Function Name: nw_vmf_co_client_get_buffer  ( vmf_basic_msg_t  **pvmf_co_msg)
 *
 *   Description:   get a message collector message
 *
 *
 *   Parameters:    pvmf_co_msg       (input/output)  pointer to pointer of collector message
 *                  len               (input)         length of collector message    
 *
 *   Return value:  vmf_ret_t
 *
 ******************************************************************************/
static vmf_ret_t nw_vmf_co_client_get_buffer ( void  **ppvmf_co_msg,unsigned16 len)
{
    vmf_ret_t vmf_ret = VMF_OK;
    void *pbuffer = NULL;

    if (NULL != *ppvmf_co_msg)
    {
        /* buffer already allocated */
        vmf_ret = VMF_OK;
    }
    else
    {
        pbuffer = nw_os_malloc(len);
        if (NULL == pbuffer)
        {
            /* error allocating buffer !!*/
            vmf_ret = VMF_ERR_OUT_OF_MEMORY;
        }
        else
        {
            memset(pbuffer,0,len);
            *ppvmf_co_msg = pbuffer;
            vmf_ret = VMF_OK;
        }
    }
    return vmf_ret;
}

 /**************************************************************************//**
 *
 *   Function Name: nw_vmf_co_client_free_buffer  ( vmf_basic_msg_t  **pvmf_co_msg)
 *
 *   Description:   free a message collector message
 *
 *
 *   Parameters:    pvmf_co_msg       (input)  pointer to collector buffer
 *
 *   Return value:  vmf_ret_t
 *
 ******************************************************************************/
static void nw_vmf_co_client_free_buffer ( void  *pvmf_co_msg)
{
    if (NULL != pvmf_co_msg)
    {
        nw_os_free(pvmf_co_msg);
    }
}


/**************************************************************************//**
 *
 *   Function Name: nw_vmf_co_client_get_msg_len  ( vmf_basic_msg_t  *vmf_co_msg)
 *   Description:   get the length of a vmf message
 *
 *
 *   Parameters:    pvmf_msg       (input) pointer to the vmf message
 *
 *
 *   Return value:  vmf_ret         vmf error type    
 *
 ******************************************************************************/
static vmf_ret_t nw_vmf_co_client_get_msg_len (vmf_msg_t  *pvmf_co_msg,unsigned16 *plen)
{  
    msg_type_t  msg_type;
    vmf_ret_t   vmf_ret=VMF_OK;
    
    /* argument check */
    if (NULL == pvmf_co_msg)
    {
        vmf_ret = VMF_ERR_NULL_POINTER;
    }
    else if (NULL == pvmf_co_msg)
    {
        vmf_ret = VMF_ERR_NULL_POINTER;
    }
    
    if (VMF_OK != vmf_ret)
    {
        NW_VMF_DEBUG_INFO("nw_vmf_co_client_get_msg_len NULL-Pointer");
        return vmf_ret;
    }
    
    *plen = 0;
    msg_type = pvmf_co_msg->vmf_basic_msg.msg_base.base.msg_type;

    switch (msg_type)
    {
        case MSG_TYPE_MOST_MESSAGE:
            *plen = sizeof(VMF_VAR_BASIC_MSG_TYP(0)) + ((vmf_most_msg_t*)pvmf_co_msg)->data.length;
            vmf_ret = VMF_ERR_NO_CO_MSG;
        break;

        case MSG_TYPE_BASIC_EMBEDDED_MESSAGE:
            /*  no break */
        case MSG_TYPE_BASIC_MESSAGE:
            *plen = VMF_BASIC_MSG_HEADER_SIZE + ((vmf_basic_msg_t*)pvmf_co_msg)->data.length;
        break;

        case MSG_TYPE_CONNECT:
            *plen = sizeof(vmf_ctrl_msg_connect_t);
        break;

        case MSG_TYPE_REGISTER_EXT_MOST_LINK:
            *plen = sizeof(vmf_ctrl_msg_register_ext_most_link_t);
        break;

        case MSG_TYPE_REGISTER_MOST_FBLOCK:
            *plen = sizeof(vmf_ctrl_msg_register_most_fblock_t);
        break;

        case MSG_TYPE_DE_REGISTER_MOST_FBLOCK:
            *plen = sizeof(vmf_ctrl_msg_de_register_most_fblock_t);
        break;

        case MSG_TYPE_REGISTER_MOST_SHADOW:
            *plen = sizeof(vmf_ctrl_msg_register_most_shadow_t);
        break;

        case MSG_TYPE_DE_REGISTER_MOST_SHADOW:
            *plen = sizeof(vmf_ctrl_msg_de_register_most_shadow_t);
        break;

        case MSG_TYPE_REGISTER_MSG_GROUPS:
            *plen = sizeof(VMF_VAR_CTRL_MSG_REGISTER_MSG_GROUP_TYP(0));
            *plen += ((vmf_ctrl_msg_register_msg_group_t*)pvmf_co_msg)->groups_num;
        break;

        case MSG_TYPE_DE_REGISTER_MSG_GROUPS:
            *plen = sizeof(VMF_VAR_CTRL_MSG_REGISTER_MSG_GROUP_TYP(0));
            *plen += ((vmf_ctrl_msg_register_msg_group_t*)pvmf_co_msg)->groups_num;
        break;

        case MSG_TYPE_REGISTER_SPY:
            *plen = sizeof(vmf_ctrl_msg_register_spy_t);
        break;

        case MSG_TYPE_REGISTER_TRACE_SERVER:
            *plen = sizeof(vmf_ctrl_msg_register_trace_server_t);
        break;

        case MSG_TYPE_DISCONNECT:
            *plen = sizeof(vmf_ctrl_msg_connect_t);
        break;
        
        default:
            vmf_ret = VMF_ERR_NO_CO_MSG;
        break;
    }
    
    NW_VMF_DEBUG_INFO("nw_vmf_co_client_get_msg_len vmf_ret=%d, msg-type=%d, len=%d",vmf_ret,msg_type,*plen);
    
    
    return vmf_ret;
}
