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
#endif

/* application includes */
#include "nw_vmf_rem.h"					/* vmf cfg file */
#include "nw_vmf_rem_client_connector.h"



#define INITAL_CID_VALUE            (1)
#define MAX_SERVER_CONNECTIONS      (16 + INITAL_CID_VALUE) /* mhammer3, tms 85418, initial cid must start at 1*/

#ifdef NW_VMF_CFG_ALLOW_SHADOW_WITH_EMPTY_FUNCTION_LIST
#define ALLOW_EMPTY_SH_LIST
#endif



/************** typedefs ********************/
/** definition for the cid table.\n
*   the connection description for each
*   connection instance is stored in this table.
*/



/*************** MACROS *********************/
#define VMF_CLIENT_LOCK     {NW_REM_VMF_DEBUG_PRINTF("bvm-VDF-CLient-Lib: nw_vmf_client_mutex_lock()\n");if ((mux_error=pthread_mutex_lock((&myMutex))) != 0) {NW_REM_VMF_DEBUG_ERROR("VDF-CLient-Lib: mutex Lock Failed %s line %d\n", __FILE__, __LINE__);}}
#define VMF_CLIENT_UNLOCK   {NW_REM_VMF_DEBUG_PRINTF("bvm-VDF-CLient-Lib: nw_vmf_client_mutex_unlock()\n");if ((mux_error=pthread_mutex_unlock((&myMutex))) != 0) {NW_REM_VMF_DEBUG_ERROR("VDF-CLient-Lib: mutex Unlock Failed %s line %d\n", __FILE__, __LINE__);}}
#define VMF_MUTEX_INIT      if (false == bmyMutexInitialized) nw_vmf_client_mutex_init(&myMutex);

#define CID_TX_HDL(cid)     (cid_tab.my_cid[cid].tx_handle)
#define CID_RX_HDL(cid)     (cid_tab.my_cid[cid].rx_handle)
#define FOREVER             (true)

/************** global variables ************/
static bool						cid_tab_init_done=false;                /*!< true if cd-table is initialized */
static pthread_mutex_t			myMutex;
static bool						bmyMutexInitialized = false;
static bool						nw_vmf_ipc_init_done = false;
static int						mux_error;

/************ local functions **************/
static bool             nw_vmf_client_mutex_init    (pthread_mutex_t *pMutex);
static void             nw_vmf_HexDump              (char *chPrefixText, unsigned char *u8mem, unsigned length);

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

    NW_REM_VMF_DEBUG_PRINTF("nw_vmf_connect()\n");


	/* argument check */
    if (0 == message_queue_size)
    {
        NW_REM_VMF_DEBUG_ERROR("nw_vmf_connect()- message_queue_size=0)\n");
		return ((vmf_client_id_t)VMF_ERR_OUT_OF_RANGE);
    }

    if (message_size < sizeof(VMF_VAR_MSG_TYP(0)))
    {
        NW_REM_VMF_DEBUG_ERROR("nw_vmf_connect()- message_size < sizeof(VMF_VAR_MSG_TYP(0))\n");
        return ((vmf_client_id_t)VMF_ERR_OUT_OF_RANGE);
    }

    VMF_MUTEX_INIT
    VMF_CLIENT_LOCK

	/* connect to target */
	vmf_ret = vmf_target_tx_con_init(p_my_process_name);
	if (vmf_ret != VMF_OK)
	{
        /* error connecting to target */
        NW_REM_VMF_DEBUG_ERROR("nw_vmf_connect()- vmf_target_tx_con_init() failed\n");
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
		strncpy(rpc_msg.rpc_connect.process_name,p_my_process_name,sizeof(rpc_msg.rpc_connect.process_name));

		/* get the rpc-msg length */
		vmf_ret = vmf_rem_get_rpc_msg_len(&(rpc_msg.msg_length.length),&rpc_msg);
		if (vmf_ret != VMF_OK)
		{
	        NW_REM_VMF_DEBUG_ERROR("nw_vmf_connect()- vmf_rem_get_rpc_msg_len() failed\n");
			VMF_CLIENT_UNLOCK
			return ((vmf_client_id_t)vmf_ret);
		}

		vmf_ret = vmf_target_call(&rpc_msg,&response);
		my_client_id = (vmf_client_id_t)vmf_ret;		
		if (vmf_ret>0)
		{
			/* crate a rx connection for this client */
			vmf_ret = vmf_target_rx_con_init(my_client_id);
			if (VMF_OK != vmf_ret)
			{
		        NW_REM_VMF_DEBUG_ERROR("nw_vmf_connect()- vmf_target_rx_con_init() failed\n");
				my_client_id = (vmf_client_id_t)vmf_ret;
			}
		}
	}
	VMF_CLIENT_UNLOCK

    NW_REM_VMF_DEBUG_PRINTF("nw_vmf_connect() done\n");
	
	return (my_client_id);
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
vmf_ret_t nw_vmf_disconnect( vmf_client_id_t vmf_client_id)      /*!< client id */
{
    vmf_ret_t   vmf_ret=VMF_OK;

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

		vmf_ret = vmf_target_call(&rpc_msg,&response);
	}

	/* wait some tine to allow the transfer of the disconnect message */
	Sleep(300);

	vmf_ret = vmf_target_disconnect(vmf_client_id);

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
vmf_ret_t nw_vmf_register_ext_most_link(vmf_client_id_t vmf_client_id) /*!< INPUT client id */
{
    vmf_ret_t			vmf_ret=VMF_OK;
	vmf_rpc_response_t	response;

    /* argument check */
    if (vmf_client_id >=  MAX_SERVER_CONNECTIONS)
    {
        NW_REM_VMF_DEBUG_ERROR("pid=%d bvm-VDF-CLient-Lib: nw_vmf_register_ext_most_link()- argument error: invalid vmf_client_id\n",(int)getmypid());
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

		vmf_ret = vmf_target_call(&rpc_msg,&response);
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
vmf_ret_t nw_vmf_register_spy(vmf_client_id_t vmf_client_id) /*!< INPUT client id */
{
    vmf_ret_t			vmf_ret=VMF_OK;
	vmf_rpc_response_t	response;

    /* argument check */
    if (vmf_client_id >=  MAX_SERVER_CONNECTIONS)
    {
        NW_REM_VMF_DEBUG_ERROR("pid=%d bvm-VDF-CLient-Lib: nw_vmf_register_spy()- argument error: invalid vmf_client_id\n",(int)getmypid());
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

		vmf_ret = vmf_target_call(&rpc_msg,&response);
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
vmf_ret_t nw_vmf_register_most_fblock  (vmf_client_id_t vmf_client_id,  /**< INPUT connection client-id*/
                                        unsigned8 fBlockId,             /**< INPUT FBlock ID*/
                                        unsigned8 instId)               /**< INPUT Instant ID*/
{
    vmf_ret_t			vmf_ret=VMF_OK;
	vmf_rpc_response_t	response;

    /* argument check */
    if (vmf_client_id >= MAX_SERVER_CONNECTIONS)
    {
        NW_REM_VMF_DEBUG_ERROR("pid=%d bvm-VDF-CLient-Lib: nw_vmf_register_most_fblock()- argument error: invalid vmf_client_id\n",(int)getmypid());
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


		vmf_ret = vmf_target_call(&rpc_msg,&response);
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
vmf_ret_t nw_vmf_de_register_most_fblock(vmf_client_id_t vmf_client_id,     /**< INPUT connection client-id */
                                         unsigned8 fBlockId,                /**< INPUT FBlock ID */
                                         unsigned8 instId)                  /**< INPUT Instant ID */
{
    vmf_ret_t			vmf_ret=VMF_OK;
	vmf_rpc_response_t	response;


    /* argument check */
    if (vmf_client_id >= MAX_SERVER_CONNECTIONS)
    {
        NW_REM_VMF_DEBUG_ERROR("pid=%d bvm-VDF-CLient-Lib: nw_vmf_de_register_most_fblock()- argument error: invalid vmf_client_id\n",(int)getmypid());
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



		vmf_ret = vmf_target_call(&rpc_msg,&response);
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
vmf_ret_t nw_vmf_register_most_shadow  (vmf_client_id_t vmf_client_id,  /**< INPUT connection client-id */
                                        unsigned8 fBlockId,             /**< INPUT FBlock ID */
                                        unsigned8 instId,               /**< INPUT Instant ID */
                                        unsigned16 fcIds_num,           /**< INPUT number of function ID's in list */
                                        unsigned16 *funcIds)            /**< INPUT pointer to a list of function ID's*/
{
    vmf_ret_t			vmf_ret=VMF_OK;
    unsigned16			uCnt;
	vmf_rpc_response_t	response;


    /* argument check */
#ifndef ALLOW_EMPTY_SH_LIST
    if (NULL == funcIds)
    {
        NW_REM_VMF_DEBUG_ERROR("pid=%d bvm-VDF-CLient-Lib: nw_vmf_register_most_shadow() - argument error: NULL pointer\n",(int)getmypid());
        return (VMF_ERR_NULL_POINTER);
    }
#endif

#ifdef DO_CLIENT_DEBUG_SHADOW
    {
        int iCnt;
        NW_VMF_DEBUG_PRINT(NW_VMF_DBG_ASP_CLIENT_LIB,NW_VMF_DBG_LVL_INFO,"\nbvm-VDF-CLient-Lib: nw_vmf_register_most_shadow fBlockId=%d,instId=%d,function-no=%d -list= ", fBlockId,instId,fcIds_num);
        for (iCnt=0;iCnt<fcIds_num;iCnt++)
        {
            NW_VMF_DEBUG_PRINT(NW_VMF_DBG_ASP_CLIENT_LIB,NW_VMF_DBG_LVL_INFO,"%d ", funcIds[iCnt]);
        }
        NW_VMF_DEBUG_PRINT(NW_VMF_DBG_ASP_CLIENT_LIB,NW_VMF_DBG_LVL_INFO,"\n");
    }
#endif

    if (vmf_client_id >= MAX_SERVER_CONNECTIONS)
    {
        NW_REM_VMF_DEBUG_ERROR("pid=%d bvm-VDF-CLient-Lib: nw_vmf_register_most_shadow()- argument error: invalid vmf_client_id\n",(int)getmypid());
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

		vmf_ret = vmf_target_call(&rpc_msg,&response);
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
vmf_ret_t nw_vmf_de_register_most_shadow(vmf_client_id_t vmf_client_id,     /**<INPUT connection client id*/
                                         unsigned8 fBlockId,                /**<INPUT FBlock ID*/
                                         unsigned8 instId)                  /**<INPUT Instant ID*/
{
    vmf_ret_t			vmf_ret=VMF_OK;
	vmf_rpc_response_t	response;


    /* argument check */
    if (vmf_client_id >= MAX_SERVER_CONNECTIONS)
    {
        NW_REM_VMF_DEBUG_ERROR("pid=%d bvm-VDF-CLient-Lib: nw_vmf_de_register_most_shadow()- argument error: invalid vmf_client_id\n",(int)getmypid());
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

		vmf_ret = vmf_target_call(&rpc_msg,&response);
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
vmf_ret_t nw_vmf_register_msg_group (vmf_client_id_t vmf_client_id, /**<INPUT connection client id*/
                                     unsigned16 groups_num,         /**<INPUT number of groups in List*/
                                     unsigned8 * groupList)         /**<INPUT pointer ro a list of message groups*/
{
    vmf_ret_t			vmf_ret=VMF_OK;
	vmf_rpc_response_t	response;


#ifdef DO_CLIENT_DEBUG
    NW_VMF_DEBUG_PRINT(NW_VMF_DBG_ASP_CLIENT_LIB,NW_VMF_DBG_LVL_INFO,"bvm-VDF-CLient-Lib: nw_vmf_register_msg_group()\n");
#endif

    /* argument check */
    if (NULL == groupList)
    {
        NW_REM_VMF_DEBUG_ERROR("pid=%d bvm-VDF-CLient-Lib: nw_vmf_register_msg_group() - argument error: NULL pointer\n",(int)getmypid());
        return (VMF_ERR_NULL_POINTER);
    }

    if (groups_num > MAX_GROUP_NUM)
    {
        NW_REM_VMF_DEBUG_ERROR("pid=%d bvm-VDF-CLient-Lib: nw_vmf_register_msg_group() - argument error: groups_num > MAX_GROUP_NUM\n",(int)getmypid());
        return (VMF_ERR_OUT_OF_RANGE);
    }

#ifdef DO_CLIENT_DEBUG
    NW_VMF_DEBUG_PRINT(NW_VMF_DBG_ASP_CLIENT_LIB,NW_VMF_DBG_LVL_INFO,"bvm-VDF-CLient-Lib: nw_vmf_register_msg_group() call nw_vmf_ipc_send\n");
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


		vmf_ret = vmf_target_call(&rpc_msg,&response);
	}


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
vmf_ret_t nw_vmf_de_register_msg_group  (vmf_client_id_t vmf_client_id, /**<INPUT connection_id*/
                                        unsigned16 groups_num,          /**<INPUT number of groups in List*/
                                        unsigned8 * groupList)          /**<INPUT pointer to a list of message groups*/
{
    vmf_ret_t			vmf_ret=VMF_OK;
	vmf_rpc_response_t	response;


    /* argument check */
    if (NULL == groupList)
    {
        NW_REM_VMF_DEBUG_ERROR("pid=%d bvm-VDF-CLient-Lib: nw_vmf_de_register_msg_group() - argument error: NULL pointer\n",(int)getmypid());
        return (VMF_ERR_NULL_POINTER);
    }

    if (groups_num > MAX_GROUP_NUM)
    {
        NW_REM_VMF_DEBUG_ERROR("pid=%d bvm-VDF-CLient-Lib: nw_vmf_de_register_msg_group() - argument error: groups_num > MAX_GROUP_NUM\n",(int)getmypid());
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

		vmf_ret = vmf_target_call(&rpc_msg,&response);
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
vmf_ret_t nw_vmf_send_most_async      (vmf_client_id_t vmf_client_id,     /**<INPUT connection_id*/
                                       vmf_most_msg_t * p_vmf_msg)        /**<INPUT pointer to a MOST vmf_message*/
{
    vmf_ret_t			vmf_ret=VMF_OK;
	unsigned16			most_msg_len;
	vmf_rpc_response_t	response;


#ifdef DO_CLIENT_DEBUG
    NW_VMF_DEBUG_PRINT(NW_VMF_DBG_ASP_CLIENT_LIB,NW_VMF_DBG_LVL_INFO,"bvm-VDF-CLient-Lib: nw_vmf_send_most_async()\n");
#endif

    /* argument check */
    if (NULL == p_vmf_msg)
    {
        NW_REM_VMF_DEBUG_ERROR("pid=%d bvm-VDF-CLient-Lib: nw_vmf_send_most_async() - argument error: NULL pointer\n",(int)getmypid());
        return (VMF_ERR_NULL_POINTER);
    }

	/* check message size */
	if (p_vmf_msg->data.length > VMF_REM_MAX_DATA_SIZE)
    {
        NW_REM_VMF_DEBUG_ERROR("pid=%d bvm-VDF-CLient-Lib: nw_vmf_send_most_async() - to much data =%d bytes\n",(int)getmypid(),p_vmf_msg->data.length);
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


		vmf_ret = vmf_target_call(&rpc_msg,&response);
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
vmf_ret_t nw_vmf_send_most_ctrl     (vmf_client_id_t vmf_client_id,     /**<INPUT connection_id*/
                                    vmf_most_msg_t * p_vmf_msg)        /**<INPUT pointer to a MOST vmf_message*/
{
    vmf_ret_t			vmf_ret=VMF_OK;
	unsigned16			most_msg_len;
	vmf_rpc_response_t	response;

#ifdef DO_CLIENT_DEBUG
    NW_VMF_DEBUG_PRINT(NW_VMF_DBG_ASP_CLIENT_LIB,NW_VMF_DBG_LVL_INFO,"bvm-VDF-CLient-Lib: nw_vmf_send_most_ctrl()\n");
#endif


    /* argument check */
    if (NULL == p_vmf_msg)
    {
        NW_REM_VMF_DEBUG_ERROR("pid=%d bvm-VDF-CLient-Lib: nw_vmf_send_most_ctrl() - argument error: NULL pointer\n",(int)getmypid());
        return (VMF_ERR_NULL_POINTER);
    }

	/* check message size */
	if (p_vmf_msg->data.length > VMF_REM_MAX_DATA_SIZE)
    {
        NW_REM_VMF_DEBUG_ERROR("pid=%d bvm-VDF-CLient-Lib: nw_vmf_send_most_ctrl() - to much data \n",(int)getmypid());
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


		vmf_ret = vmf_target_call(&rpc_msg,&response);
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
vmf_ret_t nw_vmf_send_basic     (vmf_client_id_t vmf_client_id,     /**<INPUT connection_id*/
                                 vmf_basic_msg_t *p_vmf_msg)        /**<INPUT pointer to a basic vmf_message*/
{
    vmf_ret_t			vmf_ret=VMF_OK;
	unsigned16			basic_msg_len;
	vmf_rpc_response_t	response;

	NW_REM_VMF_DEBUG_INFO("pid=%d bvm-VDF-CLient-Lib: nw_vmf_send_basic()\n",(int)getmypid());


    /* argument check */
    if (NULL == p_vmf_msg)
    {
        NW_REM_VMF_DEBUG_ERROR("pid=%d bvm-VDF-CLient-Lib: nw_vmf_send_basic() - argument error: NULL pointer\n",(int)getmypid());
        return (VMF_ERR_NULL_POINTER);
    }

	/* check message size */
	if (p_vmf_msg->data.length > VMF_REM_MAX_DATA_SIZE)
    {
        NW_REM_VMF_DEBUG_ERROR("pid=%d bvm-VDF-CLient-Lib: nw_vmf_send_basic() - to much data \n",(int)getmypid());
        return (VMF_ERR_OUT_OF_RANGE);
    }
/*
	NW_REM_VMF_DEBUG_INFO("bvm-VDF-CLient-Lib: nw_vmf_send_basic()data length =%02x \n",p_vmf_msg->data.length);
	NW_REM_VMF_DEBUG_INFO("bvm-VDF-CLient-Lib: nw_vmf_send_basic()data pl[0] = %02x\n",p_vmf_msg->data.pl[0] );
	NW_REM_VMF_DEBUG_INFO("bvm-VDF-CLient-Lib: nw_vmf_send_basic()data pl[1] = %02x\n",p_vmf_msg->data.pl[1] );
	NW_REM_VMF_DEBUG_INFO("bvm-VDF-CLient-Lib: nw_vmf_send_basic()data pl[2] = %02x\n",p_vmf_msg->data.pl[2] );
*/
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


		vmf_ret = vmf_target_call(&rpc_msg,&response);
	}


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
vmf_ret_t nw_vmf_send           (vmf_client_id_t vmf_client_id,  /**<INPUT connection_id*/
                                 vmf_msg_t * p_vmf_msg)          /**<INPUT pointer to a vmf_message*/
{
    /* argument check */
    if (NULL == p_vmf_msg)
    {
        NW_REM_VMF_DEBUG_ERROR("pid=%d bvm-VDF-CLient-Lib: nw_vmf_send() - argument error: NULL pointer\n",(int)getmypid());
        return (VMF_ERR_NULL_POINTER);
    }

    if (vmf_client_id >= MAX_SERVER_CONNECTIONS)
    {
        if (0 == vmf_client_id)
        {
            NW_REM_VMF_DEBUG_ERROR("pid=%d bvm-VDF-CLient-Lib: nw_vmf_send()- error - client not connected\n",(int)getmypid());
        }
        else
        {
            NW_REM_VMF_DEBUG_ERROR("pid=%d bvm-VDF-CLient-Lib: nw_vmf_send()- argument error: invalid vmf_client_id=%d\n",(int)getmypid(),(int)vmf_client_id);
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
signed16 nw_vmf_receive          (vmf_client_id_t vmf_client_id,    /**< INPUT connection_id*/
                                  vmf_msg_t * p_vmf_msg,            /**< OUTPUT pointer to a vmf_message*/
                                  unsigned16  vmf_msg_length)       /**< INPUT length of COMPLETE message buffer */
{
    signed16			sReadSize=0;
    vmf_ret_t			vmf_ret=VMF_OK;
	/* receive buffer (2KB on the stack! )*/
	unsigned8			my_resp_buffer[sizeof(VMF_VAR_MSG_TYP(VMF_REM_MAX_DATA_SIZE)) + sizeof(vmf_rpc_response_t)];
	vmf_rpc_response_t*	p_response = (vmf_rpc_response_t*)&my_resp_buffer;

	NW_REM_VMF_DEBUG_INFO("pid=%d bvm-VDF-CLient-Lib: nw_vmf_receive()\n",(int)getmypid());

    /* argument check */
    if (NULL == p_vmf_msg)
    {
        NW_REM_VMF_DEBUG_ERROR("pid=%d bvm-VDF-CLient-Lib: nw_vmf_receive()- argument error: NULL pointer\n",(int)getmypid());
        return (VMF_ERR_NULL_POINTER);
    }

    if ((0==vmf_client_id) || (vmf_client_id >= MAX_SERVER_CONNECTIONS))
    {
        NW_REM_VMF_DEBUG_ERROR("pid=%d bvm-VDF-CLient-Lib: nw_vmf_receive()- argument error: invalid vmf_client_id\n",(int)getmypid());
        return (VMF_ERR_OUT_OF_RANGE);
    }

	/* check message size */
	if (vmf_msg_length > sizeof(VMF_VAR_MSG_TYP(VMF_REM_MAX_DATA_SIZE)))
    {
        NW_REM_VMF_DEBUG_ERROR("pid=%d bvm-VDF-CLient-Lib: nw_vmf_receive() -invali vmf_msg_length \n",(int)getmypid());
        return (VMF_ERR_OUT_OF_RANGE);
    }

	/* send rpc message */
	{
		vmf_rpc_msg_t rpc_msg;
		rpc_msg.rpc_id	= VMF_RPC_FKT_RECEIVE;
		rpc_msg.r_cid	= vmf_client_id;

		/* get the rpc-msg length */
		vmf_ret = vmf_rem_get_rpc_msg_len(&(rpc_msg.msg_length.length),&rpc_msg);
		if (vmf_ret != VMF_OK)
		{
			return (vmf_ret);
		}

		/* set maximum recieve message lenght */
		rpc_msg.rpc_receive.vmf_msg_length.length = vmf_msg_length;

		sReadSize = vmf_target_call_rx(&rpc_msg,p_response);

		if (sReadSize > 0)
		{	
#ifdef DO_CLIENT_DEBUG_HEX
			nw_vmf_HexDump("vmf_client_rx_data",(unsigned8 *)p_response,sReadSize);
#endif
			/* copy vmf-message to destination buffer */
			if (sReadSize <= VMF_REM_MAX_DATA_SIZE)
			{		
				memcpy(p_vmf_msg,&(p_response->vmf_msg),sReadSize);
#ifdef DO_CLIENT_DEBUG_HEX
			nw_vmf_HexDump("vmf_client_vmf_data",(unsigned8 *)p_vmf_msg,sReadSize);
#endif
			}
			else
			{	
				/* message size invalid !*/
		        NW_REM_VMF_DEBUG_ERROR("pid=%d bvm-VDF-CLient-Lib: nw_vmf_receive() - receide to much data =%d bytes\n",(int)getmypid(),sReadSize);
				sReadSize = VMF_ERR_OUT_OF_RANGE;
			}	
		}
	}

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

    NW_REM_VMF_DEBUG_PRINTF("bvm-VDF-CLient-Lib: nw_vmf_client_mutex_init()\n");


    if (bmyMutexInitialized != false)
    {
        /* mutex already created */
        return true;
    }

    if (0 != pthread_mutexattr_init(&attr))
    {
        NW_REM_VMF_DEBUG_ERROR("bvm-VDF-CLient-Lib: nw_vmf_client_mutex_init() - pthread_mutexattr_init() failed\n");
        return(false);
    }

    /* initialize mutex as a blocking mutex */
    if (0 != pthread_mutexattr_settype(&attr,PTHREAD_MUTEX_NORMAL))
    {
        NW_REM_VMF_DEBUG_ERROR("bvm-VDF-CLient-Lib: nw_vmf_client_mutex_init() - pthread_mutexattr_settype() failed\n");
        pthread_mutexattr_destroy(&attr);
        return(false);
    }

    if(pthread_mutex_init( pMutex, &attr ))
    {
        NW_REM_VMF_DEBUG_ERROR("bvm-VDF-CLient-Lib: nw_vmf_client_mutex_init() - pthread_mutex_init() failed\n");
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
static void nw_vmf_HexDump  (char *chPrefixText,    /*!< INPUT pointer to prefix text */
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
