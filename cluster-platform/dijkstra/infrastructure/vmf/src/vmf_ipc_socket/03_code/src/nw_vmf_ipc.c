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

#ifdef INTEGRITY
#define IPC_SOCKET_DOMAIN               AF_LOCAL
#define IPC_DOMAIN_SOCKET_NAME_PREFIX   "vmf"
#else
#define IPC_SOCKET_DOMAIN               AF_UNIX
#define IPC_DOMAIN_SOCKET_NAME_PREFIX   "/dev/127"
#endif


/*! IPC connections information structure */
typedef struct
{
    bool                b_inuse[MAX_IPC_CHANNELS];
    int                 vmf_udp_socket[MAX_IPC_CHANNELS];                   /*!< socket identifier */
    struct sockaddr_un  vmf_sock_addr[MAX_IPC_CHANNELS];                    /*!< socket address */
    char                client_name[MAX_NAME_LEN][MAX_IPC_CHANNELS];        /*!< client name received on connection request */
    unsigned8           client_id[MAX_IPC_CHANNELS];                        /*!< client ID received on connection request */
    pid_t               pid[MAX_IPC_CHANNELS];                              /*!< client process ID received on connection request */
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

        /* set domain socket-size */
        if (false == nw_os_set_queue_size(VMF_IPC_QUEUE_SIZE_MAX))
        {
            NW_VMF_DEBUG_ERROR("nw_vmf_ipc_init: setting queue size failed!\n");
        }
    }

    if (false == ipc_init_done)
    {
        /* initialize data */
        ipc_connections.count = 0x00;
        for (i=0;i<MAX_IPC_CHANNELS;i++)
        {
            ipc_connections.vmf_udp_socket[i] = VMF_INVALID_SOCKET;
            ipc_connections.b_inuse[i] = false;
        }

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

    NW_VMF_ARG_CHECK_POINTER ("nw_vmf_ipc_open - channel_name", channel_name);


    struct sockaddr_un  vmf_sock_addr;
    /* create a receiving socket */

    vmf_udp_socket = socket(IPC_SOCKET_DOMAIN, SOCK_DGRAM, 0);
    if (VMF_INVALID_SOCKET == vmf_udp_socket)
    {
        NW_VMF_DEBUG_ERROR("nw_vmf_ipc_open: NO socket available!\n");
        return VMF_HANDLE_INVALID;
    }
    if (IPC_NON_BLOCKING == block_on_send)
    {
        int x;
        x=fcntl(vmf_udp_socket,F_GETFL,0);
        (void) fcntl(vmf_udp_socket,F_SETFL,x | O_NONBLOCK);
        NW_VMF_DEBUG_PRINT(NW_VMF_DBG_LVL_IPC, NW_VMF_DBG_ASP_IPC,
                "vmf_ipc_open: set channel %s to NON-BLOCKING.\n", channel_name);
    }

    memset(&vmf_sock_addr, 0, sizeof(vmf_sock_addr));
    vmf_sock_addr.sun_family = IPC_SOCKET_DOMAIN;
    (void) snprintf(vmf_sock_addr.sun_path, sizeof(vmf_sock_addr.sun_path),"%s",channel_name);

    /* check if server socket is available */
    {
        unsigned8 buffer;
        signed16  send_ret_val;

        send_ret_val = sendto(vmf_udp_socket, &buffer, 0, 0, (struct sockaddr *)&vmf_sock_addr, sizeof(vmf_sock_addr));
        if (send_ret_val < 0)
        {
            NW_VMF_DEBUG_PRINT(NW_VMF_DBG_LVL_IPC, NW_VMF_DBG_ASP_IPC,
                    "nw_vmf_ipc_open: server socket not available! send_ret_val==%d\n", send_ret_val);
            (void)closesocket(vmf_udp_socket);
            return VMF_HANDLE_INVALID;
        }
    }

    /* assign the socket to a vmf_handle */
    vmf_handle = nw_vmf_ipc_get_free_vmf_handle();

    if ((vmf_handle_t)VMF_ERR_OUT_OF_IPC_CHANNELS != vmf_handle)
    {
        /* make an entry to ipc_connections table */
        ipc_connections.vmf_udp_socket[(unsigned8)vmf_handle] = vmf_udp_socket;
        memcpy(&(ipc_connections.vmf_sock_addr[(unsigned8)vmf_handle]), &vmf_sock_addr, sizeof(vmf_sock_addr));

        NW_VMF_DEBUG_PRINT(NW_VMF_DBG_LVL_IPC, NW_VMF_DBG_ASP_IPC,
            "ipc_open:   OK -- channel %s \tvmf_handle %d \n", channel_name, vmf_handle);
    }
    else
    {
    	(void)closesocket(vmf_udp_socket);
    	vmf_handle = VMF_HANDLE_INVALID;
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
    vmf_handle_t        vmf_handle;
    int                 vmf_udp_socket;
    struct sockaddr_un  vmf_sock_addr;

    UNUSED_PARAM(queue_size);
    UNUSED_PARAM(msg_size);

    NW_VMF_ARG_CHECK_POINTER ("nw_vmf_ipc_create - channel_name", channel_name);

    /* create a receiving socket */
    vmf_udp_socket = socket(IPC_SOCKET_DOMAIN, SOCK_DGRAM, 0);
    if (VMF_INVALID_SOCKET == vmf_udp_socket)
    {
        NW_VMF_DEBUG_ERROR("nw_vmf_ipc_create: NO socket available!\n");
        perror("nw_vmf_ipc_create: socket() failed!");
        return VMF_HANDLE_INVALID;
    }

    memset(&vmf_sock_addr, 0, sizeof(vmf_sock_addr));
    vmf_sock_addr.sun_family = IPC_SOCKET_DOMAIN;
    (void) snprintf(vmf_sock_addr.sun_path, sizeof(vmf_sock_addr.sun_path),"%s",channel_name);
#ifndef INTEGRITY
    (void) unlink(channel_name);                /* try to delete an old domain socket before creating new one */
#endif

    if (bind(vmf_udp_socket, (struct sockaddr *)&vmf_sock_addr, sizeof(vmf_sock_addr)) == -1)
    {
        NW_VMF_DEBUG_ERROR("nw_vmf_ipc_create: bind() failed!\n");
        perror("nw_vmf_ipc_create: bind() failed!");
        (void) closesocket(vmf_udp_socket);
        return VMF_HANDLE_INVALID;
    }

    /* assign the socket to a vmf_handle */
    vmf_handle = nw_vmf_ipc_get_free_vmf_handle();

    if ((vmf_handle_t)VMF_ERR_OUT_OF_IPC_CHANNELS != vmf_handle)
    {
        /* make an entry to ipc_connections table */
        ipc_connections.vmf_udp_socket[(unsigned8)vmf_handle] = vmf_udp_socket;
        memcpy(&(ipc_connections.vmf_sock_addr[(unsigned8)vmf_handle]), &vmf_sock_addr, sizeof(vmf_sock_addr));
        NW_VMF_DEBUG_PRINT(NW_VMF_DBG_LVL_IPC, NW_VMF_DBG_ASP_IPC,
            "ipc_create: OK -- channel %s \tvmf_handle %d, socket=%d \n", channel_name, vmf_handle,vmf_udp_socket);
    }
    else
    {
        NW_VMF_DEBUG_ERROR("nw_vmf_ipc_create: VMF_ERR_OUT_OF_IPC_CHANNELS!\n");
        (void) closesocket(vmf_udp_socket);
        vmf_handle = VMF_HANDLE_INVALID;
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

    UNUSED_PARAM(channel_name);
    UNUSED_PARAM(queue_size);
    UNUSED_PARAM(msg_size); 
    UNUSED_PARAM(coid);
    UNUSED_PARAM(async_event);    

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

    vmf_socket = ipc_connections.vmf_udp_socket[(unsigned8)vmf_handle];
    if (VMF_INVALID_SOCKET != vmf_socket)
    {
        #ifdef __WINDOWS__
        (void)shutdown(vmf_socket,SD_BOTH);
        #else
        (void)shutdown(vmf_socket,SHUT_RDWR);
        #endif
        (void) closesocket(vmf_socket);
        ipc_connections.vmf_udp_socket[(unsigned8)vmf_handle] = VMF_INVALID_SOCKET;
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

#ifndef INTEGRITY
    char  delete_command[20];

    (void) snprintf(delete_command, sizeof(delete_command), "%s %s.*", NW_SYS_REMOVE, IPC_DOMAIN_SOCKET_NAME_PREFIX);
    (void) system(delete_command);
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
    struct sockaddr_un  vmf_sock_addr;

    NW_VMF_ARG_CHECK_RANGE   ("nw_vmf_ipc_send - vmf_handle", vmf_handle, 0, MAX_IPC_CHANNELS);
    NW_VMF_ARG_CHECK_POINTER ("nw_vmf_ipc_send - buffer", buffer);
    NW_VMF_ARG_CHECK_SMALLER ("nw_vmf_ipc_send - number_bytes", number_bytes, VMF_IPC_MSG_SIZE_MAX);

    vmf_udp_socket = ipc_connections.vmf_udp_socket[(unsigned8)vmf_handle];
    memcpy(&vmf_sock_addr, &(ipc_connections.vmf_sock_addr[(unsigned8)vmf_handle]), sizeof(vmf_sock_addr));

    if (VMF_INVALID_SOCKET == vmf_udp_socket)
    {
        NW_VMF_DEBUG_ERROR("nw_vmf_ipc_send: error with socket in ipc_connections table!\n");
        ret_val = VMF_ERR_INVALID_VMF_HANDLE;
    }
    else
    {
        send_ret_val = sendto(vmf_udp_socket, buffer, number_bytes, 0, (struct sockaddr *)&vmf_sock_addr, sizeof(vmf_sock_addr));
        if (send_ret_val <= 0)
        {
#if 0
            NW_VMF_DEBUG_ERROR("nw_vmf_ipc_send: sendto error! -- socket==%d, vmf_handle=%d, socket_name=%s, buffer=%p, number_bytes=%d\n", vmf_udp_socket,vmf_handle,vmf_sock_addr.sun_path,buffer,number_bytes);
            perror("sendto");
#endif
            ret_val = VMF_ERR_IPC_SEND;
        }
        else
        {
            NW_VMF_DEBUG_PRINT(NW_VMF_DBG_LVL_IPC, NW_VMF_DBG_ASP_IPC,
                "sendto:   OK -- domain socket-name %s \tsocket=%d,vmf_handle %d\n", vmf_sock_addr.sun_path,vmf_udp_socket, vmf_handle);
            ret_val = VMF_OK;
        }
    }

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

    while (1)
    {

        /* ret_val == 0 means errno == EINTR or errno == EAGAIN! */
        /* This happens sometimes e.g. in case a timer expires !? */
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
    while (1)
    {
        /* ret_val == 0 means errno == EINTR or errno == EAGAIN! */
        ret_val = _nw_vmf_ipc_timed_receive (vmf_handle, buffer_size, buffer, p_number_bytes, u_remaining_time);
        if (VMF_OK == ret_val)
        {
            /* check if timeout reached */
            if (0 == *p_number_bytes)
            {
                u_recv_time = nw_os_cfg_get_ms_time();
                u_diff_time = u_recv_time - u_start_time;
                if ((u_diff_time) >= (ms_timeout-1))
                {
                    /* receive timeout reached but 0 bytes */
                    #if 0
                    NW_VMF_DEBUG_INFO("nw_vmf_ipc_timed_receive: timeout, u_diff_time=%d, ms_timeout=%d\n",u_diff_time,ms_timeout);
                    #endif
                    ret_val= VMF_OK;
                    break;
                }

                /* timeout not reached - wait remaining time */
                delay(1);
                u_remaining_time = ms_timeout - (u_diff_time - 1);
                continue;
            }
        }
        break;
    }

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
    struct sockaddr_un  vmf_sock_addr;
    unsigned            vmf_sock_addr_len;
    struct timeval      vmf_sock_timeout;


    NW_VMF_ARG_CHECK_RANGE ("nw_vmf_ipc_receive - vmf_handle", vmf_handle, 0, MAX_IPC_CHANNELS);
    NW_VMF_ARG_CHECK_POINTER ("nw_vmf_ipc_receive - buffer", buffer);
    NW_VMF_ARG_CHECK_POINTER ("nw_vmf_ipc_receive - number_bytes", number_bytes);

    vmf_udp_socket = ipc_connections.vmf_udp_socket[(unsigned8)vmf_handle];
    memcpy(&vmf_sock_addr, &(ipc_connections.vmf_sock_addr[(unsigned8)vmf_handle]), sizeof(vmf_sock_addr));
    vmf_sock_addr_len = sizeof(vmf_sock_addr);

    if (VMF_INVALID_SOCKET == vmf_udp_socket)
    {
        NW_VMF_DEBUG_ERROR("nw_vmf_ipc_receive: error with socket in ipc_connections table!\n");
        ret_val = VMF_ERR_INVALID_VMF_HANDLE;
    }
    else
    {
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
            NW_VMF_DEBUG_ERROR("nw_vmf_ipc_receive: cannot set socket receive timeout! -- tv_sec==%d, tv_usec==%d\n", (int)vmf_sock_timeout.tv_sec, (int)vmf_sock_timeout.tv_usec);
        }

        /* now call receive */
        rec_ret_val = (signed16)recvfrom(vmf_udp_socket, buffer, buffer_size, 0, (struct sockaddr *)&vmf_sock_addr,(socklen_t*)&vmf_sock_addr_len);
        if(rec_ret_val < 0)
        {
            if ((EAGAIN == errno) || (EWOULDBLOCK == errno))  /* POSIX.1-2001 allows either error to be returned if timout*/
            {
                /* timeout BUT not an error! */
                /* perror("EAGAIN"); */
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
                #if 0
                NW_VMF_DEBUG_INFO("_nw_vmf_ipc_timed_receive: recvfrom returned with error (%d)!\n", (int)rec_ret_val);
                perror("recvfrom");
                #endif
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

    NW_VMF_ARG_CHECK_POINTER("nw_vmf_ipc_create_channel_name - p_channel_name", p_channel_name);
    NW_VMF_ARG_CHECK_BIGGER("nw_vmf_ipc_create_channel_name - pid", pid, 0);
    NW_VMF_ARG_CHECK_SMALLER("nw_vmf_ipc_create_channel_name - cid", cid, MAX_IPC_CHANNELS);
    NW_VMF_ARG_CHECK_BIGGER("nw_vmf_ipc_create_channel_name - buffer_size", buffer_size, IPC_CHANNEL_NAME_SIZE_MIN);

    (void)snprintf ((char *)p_channel_name, buffer_size, "%s.%08x.%d", IPC_DOMAIN_SOCKET_NAME_PREFIX, (int)pid, (int)cid);
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
            /* found free entry */
            ipc_connections.b_inuse[i] = true;
            ret_val = (vmf_handle_t)i;
            break;
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

    return ret_val;
}


#undef __NW_VMF_IPC_C__

