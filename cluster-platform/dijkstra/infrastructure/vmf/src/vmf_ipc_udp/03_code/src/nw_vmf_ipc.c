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

  \file                 nw_vmf_ipc.c
  \brief                inter process communication

  \author               Joerg Merkle
  \author               Visteon Deutschland GmbH, Infotainment Software

  compiler              gcc
  target                any

  *****************************************************************************/
#define __NW_VMF_IPC_C__

//#define NW_VMF_DEBUG



/* system includes */
#include "os_types.h"
#include "nw_os_config.h"


/* application includes */
#include "nw_vmf_types.h"
#include "nw_vmf_cfg.h"
#include "nw_vmf_debug.h"
#include "nw_vmf_util.h"
#include "nw_vmf_ipc.h"

#ifdef UNIT_TEST
#include "unit_test.h"
#endif


/* definitions and types */
#define VMF_INVALID_SOCKET              -1

#define IPC_SOCKET_NO_TIMEOUT           0

#define IPC_DOMAIN_SOCKET_NAME_PREFIX   "127"

#define VMF_IPC_DEBUG_INFO(args...)   // NW_VMF_DEBUG_INFO(args)
#define VMF_IPC_DEBUG_INFO2(args...)  // NW_VMF_DEBUG_INFO(args)
#define VMF_IPC_DEBUG_ERROR(args...)  NW_VMF_DEBUG_ERROR(args)
#define WINDOWS_TIME_OFFSET     512
#define VMF_IPC_DEFAULT_TTR     5


/*! IPC connections information structure */
typedef struct
{
    bool                b_inuse[MAX_IPC_CHANNELS];
    char                client_name[IPC_MAX_NAME_LEN][MAX_IPC_CHANNELS];    /*!< client name received on connection request */
    pid_t               pid[MAX_IPC_CHANNELS];                              /*!< client process ID received on connection request */
    SOCKADDR_IN         vmf_sock_addr[MAX_IPC_CHANNELS];                    /*!< socket address */
    int                 vmf_udp_socket[MAX_IPC_CHANNELS];                   /*!< socket identifier */
    int                 ttr[MAX_IPC_CHANNELS];                              /*!< time to re-use */
    unsigned8           client_id[MAX_IPC_CHANNELS];                        /*!< client ID received on connection request */
    unsigned8           count;                                              /*!< number of active connections */
}ipc_connection_t;


/* module private function prototypes*/
vmf_handle_t    nw_vmf_ipc_get_free_vmf_handle  (void);


/* global data */
ipc_connection_t    ipc_connections;
bool                ipc_init_done = false;

/* local functions */
static vmf_ret_t    _nw_vmf_ipc_timed_receive       (vmf_handle_t vmf_handle,unsigned16 buffer_size,
                                                    unsigned8 *buffer,unsigned16 *number_bytes,
                                                    unsigned16 ms_timeout);
static vmf_ret_t     nw_vmf_ipc_clean_recources     (void);




/**************************************************************************//**
 *
 *   pre-init ipc
 *
 *   \param[in]     void
 *   \return        void
 ******************************************************************************/
void nw_vmf_ipc_pre_init(void)
{
    #ifdef __WINDOWS__
    WSADATA wsaData;
    (void)WSAStartup(MAKEWORD(2,2), &wsaData);
    #endif
    (void)nw_vmf_ipc_clean_recources();
}


/*************************************************************************//**
 *
 *   Initialization of IPC data
 *
 *   \param         none
 *   \return        vmf return type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_ipc_init (bool remove_ressources)
{
    unsigned8   i;

    if (true == remove_ressources)
    {
        /* clean old domain sockets */
        (void)nw_vmf_ipc_clean_recources();
    }

    if (false == ipc_init_done)
    {
        /* initialize data */
        ipc_connections.count = 0x00;
        for (i=0;i<MAX_IPC_CHANNELS;i++)
        {
            ipc_connections.vmf_udp_socket[i] = VMF_INVALID_SOCKET;
            ipc_connections.ttr[i] = 0;
            ipc_connections.b_inuse[i] = false;
        }

        #ifdef __WINDOWS__
        /* init socket interface */
        {
            WSADATA wsaData;
            (void)WSAStartup(MAKEWORD(2,2), &wsaData);
        }
        #endif

        /* inhibit addtional inits */
        ipc_init_done = true;
    }

    return VMF_OK;
}

/*************************************************************************//**
 *
 *   Open existing IPC channel. \n
 *   Generally the 'sender' shall use nw_vmf_ipc_open. \n
 *   NOTE: mqueues opened with this function are then NON-BLOCKING!
 *
 *   \param[in]     channel_name  -- system wide unique name for the channel
 *   \param[in]     block_on_send -- defines if the mq_send shall block on
 *                                   this message queue if full
 *   \return        logic handle to identify the opened channel
 *                  or
 *                  a invalid handle for "out of channels" or "open failed"
 *
 ******************************************************************************/
vmf_handle_t nw_vmf_ipc_open (char *channel_name, bool block_on_send)
{
    vmf_handle_t        vmf_handle;
    int                 vmf_udp_socket;
    SOCKADDR_IN         vmf_sock_addr;

    NW_VMF_ARG_CHECK_POINTER ("  nw_vmf_ipc_open - channel_name", channel_name);
    VMF_IPC_DEBUG_INFO2("  nw_vmf_ipc_open(%s)",channel_name);

    /* create a receiving socket */
    vmf_udp_socket = socket(AF_INET, SOCK_DGRAM, 0);
//    vmf_udp_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (VMF_INVALID_SOCKET == vmf_udp_socket)
    {
        VMF_IPC_DEBUG_ERROR("  nw_vmf_ipc_open: NO socket available! error=%d",WSAGetLastError());
        perror("nw_vmf_ipc_open");
        return VMF_HANDLE_INVALID;
    }

    memset(&vmf_sock_addr, 0, sizeof(vmf_sock_addr));
    vmf_sock_addr.sin_family = AF_INET;
    vmf_sock_addr.sin_addr.s_addr = inet_addr(channel_name);
    vmf_sock_addr.sin_port = htons(IPC_IP_PORT);

    /* assign the socket to a vmf_handle */
    vmf_handle = nw_vmf_ipc_get_free_vmf_handle();

    if ((vmf_handle_t)VMF_ERR_OUT_OF_IPC_CHANNELS != vmf_handle)
    {
        /* make an entry to ipc_connections table */
        ipc_connections.vmf_udp_socket[(unsigned8)vmf_handle] = vmf_udp_socket;
        memcpy(&(ipc_connections.vmf_sock_addr[(unsigned8)vmf_handle]), &vmf_sock_addr, sizeof(vmf_sock_addr));

        VMF_IPC_DEBUG_INFO("  ipc_open:   OK -- channel %s \tvmf_handle %d", channel_name, vmf_handle);
    }
    else
    {
        vmf_handle = VMF_HANDLE_INVALID;
        (void) closesocket(vmf_udp_socket);
    }

    return vmf_handle;
}

/*************************************************************************//**
 *
 *   Create a IPC channel. \n
 *   Generally the 'receiver' shall use nw_vmf_ipc_create. \n
 *   NOTE: mqueues created with this function are then BLOCKING!
 *
 *   \param[in]     channel_name -- system wide unique name for the channel
 *   \param[in]     queue_size   -- queue size (number of messages)
 *   \param[in]     msg_size     -- message size for the queue
 *   \return        logic handle to identify the created channel
 *
 ******************************************************************************/
vmf_handle_t nw_vmf_ipc_create (char *channel_name, unsigned16 queue_size, unsigned16 msg_size)
{
    SOCKADDR_IN         vmf_sock_addr;
    vmf_handle_t        vmf_handle;
    int                 vmf_udp_socket;
    int                 i_ret =0;


    NW_VMF_ARG_CHECK_POINTER ("  nw_vmf_ipc_create - channel_name", channel_name);
    VMF_IPC_DEBUG_INFO2("  nw_vmf_ipc_create(%s)",channel_name);

    /* create a receiving socket */
    vmf_udp_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (VMF_INVALID_SOCKET == vmf_udp_socket)
    {
        VMF_IPC_DEBUG_ERROR("  nw_vmf_ipc_create: NO socket available!");
        return VMF_HANDLE_INVALID;
    }

    memset(&vmf_sock_addr, 0, sizeof(vmf_sock_addr));
    vmf_sock_addr.sin_family = AF_INET;
    vmf_sock_addr.sin_addr.s_addr = inet_addr(channel_name);;
    vmf_sock_addr.sin_port = htons(IPC_IP_PORT);

    /* try to set REUSEADDR option to prevent bind error if port was used a short time ago */
    {
        int on=1;
        (void)setsockopt(vmf_udp_socket, SOL_SOCKET,SO_REUSEADDR,(char *)&on,sizeof(on));
    }

    /* set rx-buffer size */
    {
        int rxbuffsize = IPC_UDP_RX_BUF_SIZE;
        (void)setsockopt(vmf_udp_socket, SOL_SOCKET, SO_RCVBUF, (char *)&rxbuffsize, sizeof(rxbuffsize));
    }

    i_ret = bind(vmf_udp_socket, (SOCKADDR *)&vmf_sock_addr, sizeof(vmf_sock_addr));
    if (i_ret != 0)
    {
        int lasterr;

        lasterr = WSAGetLastError();
        VMF_IPC_DEBUG_ERROR("  nw_vmf_ipc_create: bind to ip %s, port %d failed with %d!",channel_name,IPC_IP_PORT,lasterr);
        perror("  nw_vmf_ipc_create: bind failed!");
        (void) closesocket(vmf_udp_socket);
        return VMF_HANDLE_INVALID;
    }
    else
    {
        VMF_IPC_DEBUG_INFO("  nw_vmf_ipc_create: bind to ip %s, port %d OK!",channel_name,IPC_IP_PORT);
    }

    /* assign the socket to a vmf_handle */
    vmf_handle = nw_vmf_ipc_get_free_vmf_handle();

    if ((vmf_handle_t)VMF_ERR_OUT_OF_IPC_CHANNELS != vmf_handle)
    {
        /* make an entry to ipc_connections table */
        ipc_connections.vmf_udp_socket[(unsigned8)vmf_handle] = vmf_udp_socket;
        memcpy(&(ipc_connections.vmf_sock_addr[(unsigned8)vmf_handle]), &vmf_sock_addr, sizeof(vmf_sock_addr));
        VMF_IPC_DEBUG_INFO("  ipc_create: OK -- channel %s \tvmf_handle %d, socket=%d", channel_name, vmf_handle,vmf_udp_socket);
    }
    else
    {
        (void) closesocket(vmf_udp_socket);
        vmf_handle = VMF_HANDLE_INVALID;
        VMF_IPC_DEBUG_ERROR("  nw_vmf_ipc_create: VMF_ERR_OUT_OF_IPC_CHANNELS!");
    }

    return vmf_handle;
}


/*************************************************************************//**
 *
 *   Create an async IPC channel. \n
 *   NOTE: mqueues created with this function are then NON-BLOCKING!
 *
 *   \param[in]     channel_name     -- system wide unique name for the channel
 *   \param[in]     queue_size       -- queue size (number of messages)
 *   \param[in]     msg_size         -- message size for the queue
 *   \param[in]     block_on_receive -- true if receive on the queue is
 *                                   -- blocking if queue is empty
 *   \param[in]     channel_id       -- OSAL channel ID
 *   \param[in]     async_event      -- event that is fired if VMF queue changed from empty to
 *                                   -- not empty
 *   \return        logic handle to identify the created channel
 *
 ******************************************************************************/
vmf_handle_t nw_vmf_ipc_create_async (char *channel_name, unsigned16 queue_size,
                                      unsigned16 msg_size, unsigned32 coid,
                                      unsigned32 async_event)
{

/* jmerkle  01.07.2011 16:03:24 TBD */
/* jmerkle  Do we need to support async (Tracer) ? */
    (void) fprintf(stderr,"nw_vmf_ipc_create_async: NOT SUPPORTED!!!");
    return VMF_ERROR;
}


/*************************************************************************//**
 *
 *   Close IPC channel (not destroy)
 *
 *   \param[in]     vmf_handle -- logic channel handle
 *                                (from nw_vmf_ipc_open or nw_vmf_ipc_create)
 *   \return        vmf return type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_ipc_close (vmf_handle_t vmf_handle)
{
    int vmf_socket;

    VMF_IPC_DEBUG_INFO2("  nw_vmf_ipc_close(ipc-hdl=%d)",vmf_handle);
    vmf_socket = ipc_connections.vmf_udp_socket[(unsigned8)vmf_handle];
    if (VMF_INVALID_SOCKET != vmf_socket)
    {
        (void) closesocket(vmf_socket);
        ipc_connections.vmf_udp_socket[(unsigned8)vmf_handle] = VMF_INVALID_SOCKET;
        ipc_connections.b_inuse[(unsigned8)vmf_handle]=false;
    }

    return VMF_OK;
}

/*************************************************************************//**
 *
 *   Remove IPC channel from system
 *
 *   \param[in]     vmf_handle -- logic channel handle
 *                                (from nw_vmf_ipc_open or nw_vmf_ipc_create)
 *   \return        vmf return type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_ipc_destroy (vmf_handle_t vmf_handle)
{
    int vmf_socket;

    VMF_IPC_DEBUG_INFO2("  nw_vmf_ipc_destroy(ipc-hdl=%d)",vmf_handle);

    vmf_socket = ipc_connections.vmf_udp_socket[(unsigned8)vmf_handle];
    if (VMF_INVALID_SOCKET != vmf_socket)
    {
        (void) closesocket(vmf_socket);
        #ifdef __WINDOWS__
        (void)shutdown(vmf_socket,SD_BOTH);
        #else
        (void)shutdown(vmf_socket,SHUT_RDWR);
        #endif
        ipc_connections.vmf_udp_socket[(unsigned8)vmf_handle] = VMF_INVALID_SOCKET;
        ipc_connections.ttr[(unsigned8)vmf_handle]=VMF_IPC_DEFAULT_TTR;
        ipc_connections.b_inuse[(unsigned8)vmf_handle]=false;
    }

    return VMF_OK;
}



/*************************************************************************//**
 *
 *   clean all recources used by this IPC
 *
 *   \param[in]     void
 *   \return        vmf return type
 *
 ******************************************************************************/
static vmf_ret_t nw_vmf_ipc_clean_recources(void)
{
    #if 0
    char  delete_command[20];

    snprintf(delete_command, sizeof(delete_command), "%s %s.*", NW_SYS_REMOVE, IPC_DOMAIN_SOCKET_NAME_PREFIX);
    system(delete_command);
    #endif

    return VMF_OK;
}


/*************************************************************************//**
 *
 *   Send a message on the IPC channel. \n
 *   NOTE: in combination with nw_vmf_ipc_open this is non-blocking
 *
 *   \param[in]     vmf_handle   -- logic channel handle
 *                                  (from nw_vmf_ipc_open or nw_vmf_ipc_create)
 *   \param[in]     buffer       -- pointer to message to send
 *   \param[in]     number_bytes -- number of bytes to send
 *   \return        vmf return type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_ipc_send ( vmf_handle_t vmf_handle, unsigned8 *buffer, unsigned16 number_bytes)
{
    vmf_ret_t           ret_val = VMF_OK;
    signed16            send_ret_val;
    signed16            vmf_udp_socket;
    SOCKADDR_IN         vmf_sock_addr;

    NW_VMF_ARG_CHECK_RANGE   ("  nw_vmf_ipc_send - vmf_handle", vmf_handle, 0, MAX_IPC_CHANNELS);
    NW_VMF_ARG_CHECK_POINTER ("  nw_vmf_ipc_send - buffer", buffer);
    NW_VMF_ARG_CHECK_SMALLER ("  nw_vmf_ipc_send - number_bytes", number_bytes, VMF_IPC_MSG_SIZE_MAX);

    VMF_IPC_DEBUG_INFO2("  nw_vmf_ipc_send(ipc-hdl=%d) %d bytes",vmf_handle, number_bytes);

    vmf_udp_socket = ipc_connections.vmf_udp_socket[(unsigned8)vmf_handle];
    memcpy(&vmf_sock_addr, &(ipc_connections.vmf_sock_addr[(unsigned8)vmf_handle]), sizeof(vmf_sock_addr));

    if (VMF_INVALID_SOCKET == vmf_udp_socket)
    {
        VMF_IPC_DEBUG_ERROR("  nw_vmf_ipc_send: vmf_handle=%d, invalid socket in ipc_connections table!",vmf_handle);
        ret_val = VMF_ERR_INVALID_VMF_HANDLE;
    }
    else
    {
        send_ret_val = sendto(vmf_udp_socket, (void*)buffer, number_bytes, 0, (SOCKADDR*)&vmf_sock_addr, sizeof(vmf_sock_addr));

        if (send_ret_val <= 0)
        {
            VMF_IPC_DEBUG_ERROR("  nw_vmf_ipc_send(): sendto error! -- socket==%d, vmf_handle=%d, length=%d", vmf_udp_socket,vmf_handle,sizeof(vmf_sock_addr));
/*
            perror("sendto");
*/
            ret_val = VMF_ERR_IPC_SEND;
        }
        else
        {
            ret_val = VMF_OK;
        }
    }

    VMF_IPC_DEBUG_INFO2("  nw_vmf_ipc_send(ipc-hdl=%d) ret=%d",vmf_handle, ret_val);

    return ret_val;
}

/*************************************************************************//**
 *
 *   Receive a message on the IPC channel. \n
 *   NOTE: in combination with nw_vmf_ipc_create it is BLOCKING at QNX API
 *         if message queue is full!
 *
 *   \param[in]     vmf_handle   -- logic channel handle
 *                                  (from nw_vmf_ipc_open or nw_vmf_ipc_create)
 *   \param[in]     buffer_size  -- maximum buffer size
 *   \param[out]    buffer       -- pointer to buffer for received message
 *   \param[out]    number_bytes -- pointer to number of received bytes.
 *   \return        vmf return type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_ipc_receive (vmf_handle_t vmf_handle,unsigned16 buffer_size,
                              unsigned8 *buffer,unsigned16 *number_bytes)
{
    unsigned16 ms_timeout = IPC_SOCKET_NO_TIMEOUT;
    vmf_ret_t ret_val = VMF_OK;

    VMF_IPC_DEBUG_INFO2("  nw_vmf_ipc_receive(ipc-hdl=%d)",vmf_handle);
    while (1)
    {

        /* ret_val == 0 means errno == EINTR or errno == EAGAIN! */
        /* This happens sometimes e.g. in case a timer expires (????????????) */
        ret_val = _nw_vmf_ipc_timed_receive (vmf_handle, buffer_size, buffer, number_bytes, ms_timeout);
        if (VMF_OK == ret_val)
        {
            if (0 == *number_bytes)
            {
                delay(1);
                continue;
            }
        }
        break;
    }

    VMF_IPC_DEBUG_INFO2("  nw_vmf_ipc_receive(ipc-hdl=%d) ret=%d",vmf_handle, ret_val);
    return (ret_val);
}

/*************************************************************************//**
 *
 *   receive a message on the IPC channel with timeout. \n
 *   NOTE: in combination with nw_vmf_ipc_create it is BLOCKING at QNX API
 *         if message queue is full!
 *
 *   \param[in]     vmf_handle   -- logic channel handle
 *                                  (from nw_vmf_ipc_open or nw_vmf_ipc_create)
 *   \param[in]     buffer_size  -- maximum buffer size
 *   \param[out]    buffer       -- pointer to buffer for received message
 *   \param[out]    number_bytes -- pointer to number of received bytes.
 *   \param[in]     ms_timeout   -- receive timeout in ms
 *                                  timeout of 0 (==IPC_SOCKET_NO_TIMEOUT)
 *                                  is a very big timeout!!
 *   \return        vmf return type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_ipc_timed_receive (vmf_handle_t vmf_handle,unsigned16 buffer_size,
                                    unsigned8 *buffer,unsigned16 *p_number_bytes,
                                    unsigned16 ms_timeout)
{
    unsigned32  u_start_time;
    unsigned32  u_recv_time;
    unsigned32  u_diff_time;
    unsigned32  u_remaining_time;
    vmf_ret_t ret_val = VMF_OK;

    u_remaining_time = ms_timeout;
    u_start_time = nw_os_cfg_get_ms_time();
    nw_sleep_ms(0);     /* context change */
    while (1)
    {
        /* ret_val == 0 means errno == EINTR or errno == EAGAIN! */
        ret_val = _nw_vmf_ipc_timed_receive (vmf_handle, buffer_size, buffer, p_number_bytes, u_remaining_time);
        if (VMF_OK == ret_val)
        {
#if 1
            /* check if timeout reached */
            if (0 == *p_number_bytes)
            {
                u_recv_time = nw_os_cfg_get_ms_time();
                u_diff_time = u_recv_time - u_start_time;
                if ((u_diff_time) >= (ms_timeout-1))
                {
                    /* receive timeout reached */
                    ret_val= VMF_OK;
                    break;
                }

                /* timeout not reached - wait remaining time */
                delay(1);
                u_remaining_time = ms_timeout - (u_diff_time - 1);

                VMF_IPC_DEBUG_INFO2("  nw_vmf_ipc_timed_receive(ipc-hdl=%d) timeout not reached wait another %dms",vmf_handle, u_remaining_time);

                continue;
            }
#endif
        }
        break;
    }

    VMF_IPC_DEBUG_INFO("  nw_vmf_ipc_timed_receive(ipc-hdl=%d) ret=%d",vmf_handle, ret_val);

    return (ret_val);
}

/*************************************************************************//**
 *
 *   Receive a message on the IPC channel. \n
 *   NOTE: in combination with nw_vmf_ipc_create it is BLOCKING at QNX API
 *         if message queue is full!
 *
 *   \param[in]     vmf_handle   -- logic channel handle
 *                                  (from nw_vmf_ipc_open or nw_vmf_ipc_create)
 *   \param[in]     buffer_size  -- maximum buffer size
 *   \param[out]    buffer       -- pointer to buffer for received message
 *   \param[out]    number_bytes -- pointer to number of received bytes.
 *   \return        vmf return type
 *
 ******************************************************************************/
static vmf_ret_t _nw_vmf_ipc_timed_receive (vmf_handle_t vmf_handle,unsigned16 buffer_size,
                                              unsigned8 *buffer,unsigned16 *number_bytes,
                                              unsigned16 ms_timeout)
{
    vmf_ret_t           ret_val = VMF_OK;
    signed16            rec_ret_val;
    signed16            vmf_udp_socket;
    SOCKADDR_IN         vmf_sock_addr;
    unsigned            vmf_sock_addr_len;


    NW_VMF_ARG_CHECK_RANGE ("  nw_vmf_ipc_receive - vmf_handle", vmf_handle, 0, MAX_IPC_CHANNELS);
    NW_VMF_ARG_CHECK_POINTER ("  nw_vmf_ipc_receive - buffer", buffer);
    NW_VMF_ARG_CHECK_POINTER ("  nw_vmf_ipc_receive - number_bytes", number_bytes);

    vmf_udp_socket = ipc_connections.vmf_udp_socket[(unsigned8)vmf_handle];
    memcpy(&vmf_sock_addr, &(ipc_connections.vmf_sock_addr[(unsigned8)vmf_handle]), sizeof(vmf_sock_addr));
    vmf_sock_addr_len = sizeof(vmf_sock_addr);

    if (VMF_INVALID_SOCKET == vmf_udp_socket)
    {
        VMF_IPC_DEBUG_ERROR("  nw_vmf_ipc_receive: vmf_handle=%d, invalid socket in ipc_connections table!",vmf_handle);
        ret_val = VMF_ERR_INVALID_VMF_HANDLE;
    }
    else
    {
#ifdef __WINDOWS__
        {
            DWORD  w_timeout = ms_timeout;

            if (w_timeout > WINDOWS_TIME_OFFSET)
            {
                w_timeout -= WINDOWS_TIME_OFFSET;
            }
            else
            {
                w_timeout = 1;
            }

            if (setsockopt(vmf_udp_socket, SOL_SOCKET, SO_RCVTIMEO, (char *)&w_timeout,  sizeof(w_timeout)))
            {
                VMF_IPC_DEBUG_ERROR("  nw_vmf_ipc_receive: cannot set socket receive timeout! -- w_timeout==%d", (int)w_timeout);
            }
        }
#else
        {
            struct timeval      vmf_sock_timeout;

            /* set the receive timeout */
            if (IPC_SOCKET_NO_TIMEOUT == ms_timeout)
            {
                /* use a very big timeout that will never reached -- 0xFFFF is something around 45 days! */
                vmf_sock_timeout.tv_sec = 0xFFFF;
                vmf_sock_timeout.tv_usec = 1;
            }
            else
            {
                /* timeout given by user */
                if (ms_timeout > 999)
                {
                    /* Ok - this is not correct but we talk about seconds!!! It doesn't matter, right? */
                    vmf_sock_timeout.tv_sec = ms_timeout / 1000;
                    vmf_sock_timeout.tv_usec = 0;
                }
                else
                {
                    vmf_sock_timeout.tv_sec = 0;
                    vmf_sock_timeout.tv_usec = ms_timeout * 1000;
                }
            }

            if (setsockopt(vmf_udp_socket, SOL_SOCKET, SO_RCVTIMEO, (char *)&vmf_sock_timeout,  sizeof(vmf_sock_timeout)))
            {
                VMF_IPC_DEBUG_ERROR("  nw_vmf_ipc_receive: cannot set socket receive timeout! -- tv_sec==%d, tv_usec==%d", (int)vmf_sock_timeout.tv_sec, (int)vmf_sock_timeout.tv_usec);
            }
        }
#endif
        /* now call receive */
        rec_ret_val = (signed16)recvfrom(vmf_udp_socket, (void*)buffer, buffer_size, 0, (struct sockaddr *)&vmf_sock_addr,(socklen_t*)&vmf_sock_addr_len);
        if(rec_ret_val < 0)
        {
            int last_error=0;

            last_error = WSAGetLastError();
            #ifdef __WINDOWS__
            if ((WSAETIMEDOUT == last_error) || (EWOULDBLOCK == last_error))  /* POSIX.1-2001 allows either error to be returned if timout*/
            #else
            if ((EAGAIN == last_error) || (EWOULDBLOCK == last_error))  /* POSIX.1-2001 allows either error to be returned if timout*/
            #endif
            {
                /* timeout BUT not an error! */
                /* perror("EAGAIN"); */
                VMF_IPC_DEBUG_INFO("  _nw_vmf_ipc_timed_receive: timeout");
                errno = 0;
                *number_bytes = 0;
            }
            else if (EINTR == errno)
            {
                /* system call interrupt BUT not an error! */
                /* perror("EINTR"); */
                errno = 0;
                *number_bytes = 0;
            }
            else
            {
                VMF_IPC_DEBUG_INFO("  _nw_vmf_ipc_timed_receive: recvfrom returned with error (%d,%d)!", (int)rec_ret_val,last_error);
                /* perror("recvfrom"); */
                ret_val = VMF_ERR_IPC_RECEIVE;
            }
        }
        else if(rec_ret_val == 0)
        {
            *number_bytes = rec_ret_val;
        }
        else
        {
            *number_bytes = rec_ret_val;
        }
    }

    VMF_IPC_DEBUG_INFO("  _nw_vmf_ipc_timed_receive(ipc-hdl=%d) ret=%d",vmf_handle, ret_val);

    return ret_val;
}

/*************************************************************************//**
 *
 *   Create a unique name for IPC channel from PID and ClientID
 *
 *   \param[in]     pid            -- process id
 *   \param[in]     cid            -- client id
 *   \param[out]    p_channel_name -- pointer to channel_name
 *   \param[in]     buffer_size    -- size of p_channel_name
 *   \return        vmf return type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_ipc_create_channel_name (pid_t pid, unsigned8 cid,
                                          char *p_channel_name, unsigned8 buffer_size)
{
    vmf_ret_t   ret_val = VMF_OK;
    unsigned8   pid_hi;
    unsigned8   pid_lo;

    NW_VMF_ARG_CHECK_POINTER("  nw_vmf_ipc_create_channel_name - p_channel_name", p_channel_name);
    NW_VMF_ARG_CHECK_BIGGER ("  nw_vmf_ipc_create_channel_name - pid", pid, 0);
    NW_VMF_ARG_CHECK_SMALLER("  nw_vmf_ipc_create_channel_name - cid", cid, MAX_IPC_CHANNELS);
    NW_VMF_ARG_CHECK_BIGGER ("  nw_vmf_ipc_create_channel_name - buffer_size", buffer_size, IPC_CHANNEL_NAME_SIZE_MIN);

    pid_lo = pid % 256;
    pid_hi = pid / 256;
    (void) snprintf ((char *)p_channel_name, buffer_size, "%s.%d.%d.%d", IPC_DOMAIN_SOCKET_NAME_PREFIX, (int)pid_hi, (int)pid_lo, (int)cid);

    VMF_IPC_DEBUG_INFO2("  nw_vmf_ipc_create_channel_name() pid=%d, ipc_hdl=%d, channel-name=%s",pid,cid,p_channel_name);

    return ret_val;
}

/*************************************************************************//**
 *
 *   Obtain a free ipc handle. \n
 *   NOTE: - keep function short to make ipc_open re-entrant.
 *         - safe with mutex around the call of this function!
 *
 *   \param         none
 *   \return        next free IPC handle or vmf error type
 *
 ******************************************************************************/
vmf_handle_t nw_vmf_ipc_get_free_vmf_handle (void)
{
    vmf_handle_t    ret_val=VMF_ERR_OUT_OF_IPC_CHANNELS;

    #if 1
    int   i;

    for (i=0; i<MAX_IPC_CHANNELS; i++)
    {
        if (false == ipc_connections.b_inuse[i])
        {
            if (0 == ipc_connections.ttr[i])
            {
                /* found free entry */
                ipc_connections.b_inuse[i] = true;
                ret_val = (vmf_handle_t)i;
                break;
            }
            else
            {
                ipc_connections.ttr[i]--;
            }
        }
    }
    #else
    unsigned8       count;

    count = ipc_connections.count;
    if (count < MAX_IPC_CHANNELS)
    {
        ipc_connections.count++;
        ret_val = (vmf_handle_t)count;
    }
    else
    {
        ret_val = (vmf_handle_t)VMF_ERR_OUT_OF_IPC_CHANNELS;
    }
    #endif

    VMF_IPC_DEBUG_INFO2("  nw_vmf_ipc_get_free_vmf_handle() ipc-hdl=%d",ret_val);

    return ret_val;
}


#undef __NW_VMF_IPC_C__

