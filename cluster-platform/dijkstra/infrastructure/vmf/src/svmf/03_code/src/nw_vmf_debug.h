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

  \file                 nw_vmf_debug.h
  \brief                header of nw_vmf_debug.c

  \author               Joerg Merkle
  \author               Visteon Deutschland GmbH, Infotainment Software

  *****************************************************************************/
#ifndef __VMF_IPC_DEBUG_H__
#define __VMF_IPC_DEBUG_H__


/* switches */

/*******************************************************************************/
/*! \def NW_VMF_DEBUG

     General VMF debug switch. Comment it to avoid debug output. */
/*******************************************************************************/
/* #define NW_VMF_DEBUG */
/*******************************************************************************/


/*******************************************************************************/
/*! \def NW_VMF_DEBUG_HANDLE_DB_INFO

     Router handle information output
     after each connect (NW_VMF_DEBUG needed!) */
/*******************************************************************************/
/* #define NW_VMF_DEBUG_HANDLE_DB_INFO */
/*******************************************************************************/


/*******************************************************************************/
/*! \def NW_VMF_DEBUG_IPC_CONNECTION_INFO

     IPC connection information output after
     each open/create (NW_VMF_DEBUG needed!) */
/*******************************************************************************/
/* #define NW_VMF_DEBUG_IPC_CONNECTION_INFO */
/*******************************************************************************/


/*******************************************************************************/
/*! \def NW_VMF_DEBUG_ROUTER_MESSAGES_RECEIVED

     Shows each received message in the server. */
/*******************************************************************************/
/* #define NW_VMF_DEBUG_ROUTER_MESSAGES_RECEIVED */
/*******************************************************************************/


/*******************************************************************************/
/*! \def NW_VMF_DEBUG_ROUTER_MESSAGES_SENT

     Shows each message sent by the server. */
/*******************************************************************************/
/* #define NW_VMF_DEBUG_ROUTER_MESSAGES_SENT */
/*******************************************************************************/


/*******************************************************************************/
/*! \def NW_VMF_DEBUG_ROUTER_MESSAGES_RECEIVED_BUT_NOT_SENT

     Shows the messages received but not sent to any client since the rouging db
     gives us an empty list of clients */
/*******************************************************************************/
/* #define NW_VMF_DEBUG_ROUTER_MESSAGES_RECEIVED_BUT_NOT_SENT */
/*******************************************************************************/



/*! Definitions of debug levels. */
enum nw_vmf_dbg_levels
{
    NW_VMF_DBG_LVL_CRITICAL = 0,                /*!< critical debug level -- output always */
    NW_VMF_DBG_LVL_LITE,                        /*!< lite debug level -- output for special information */
    NW_VMF_DBG_LVL_INFO                         /*!< information only -- output for complete debugging */
};

/*! Definitions of debug aspects (filter). \n
    This is used to categorize debug output for different files, modules, components,... \n
    FEEL FREE TO DEFINE YOURSELF NEW ONES!!! */
enum nw_vmf_dbg_aspects
{
    NW_VMF_DBG_ASP_IPC = 0,                     /*!< IPC -- nw_vmf_ipc.c */
    NW_VMF_DBG_ASP_ROUTER,                      /*!< ROUTER -- nw_vmf_router.c */
    NW_VMF_DBG_ASP_ROUTER_DB,                   /*!< ROUTER DB -- nw_vmf_routing_db...c */
    NW_VMF_DBG_ASP_CLIENT_LIB,                  /*!< CLIENT LIBRARY -- nw_vmf_client.c */
    NW_VMF_DBG_ASP_SERVER,                      /*!< SERVER -- nw_vmf_server.c */
    NW_VMF_DBG_ASP_MOCCA_WRAPPER,               /*!< SERVER -- nw_vmf_mocca_wrapper.c */
    NW_VMF_DBG_ASP_SYSLOG,                      /*!< SERVER -- nw_vmf_debug.c */

    NW_VMF_DBG_ASP_COUNT                        /*!< LAST ENTRY!!! */
};

/* max size of a debug message */
#define MAX_DEBUG_MSG_SIZE  400

#ifdef NW_VMF_DEBUG
    /*******************************************************************************/
    /*! \def NW_VMF_DEBUG_PRINT

        General debug output macro. \n
        By using this macro it is generally defined where to put the debug information. */
    /*******************************************************************************/
    #define NW_VMF_DEBUG_PRINT(_aspect_, _level_, ...)     fprintf (ERROR_CHANNEL, __VA_ARGS__); fprintf(ERROR_CHANNEL, "\n")
    /*******************************************************************************/
#else
    /*******************************************************************************/
    /*! \def NW_VMF_DEBUG_PRINT

        General debug output macro. \n
        NOTE: CURRENTLY DEBUG OUTPUT IS TRASHED!!! \n
        Remove comments for NW_VMF_DEBUG to allow debug output (nw_vmf_debug.h). */
    /*******************************************************************************/
    #define NW_VMF_DEBUG_PRINT(_aspect_, _level_,...)    
    /*******************************************************************************/
#endif


/*******************************************************************************/
/*! \def NW_VMF_DEBUG_INFO

    Debug output.
    NOTE: This debug output is ALWAYS ACTIVE. \n\n */
/*******************************************************************************/
#define NW_VMF_DEBUG_INFO(...)            fprintf (ERROR_CHANNEL, __VA_ARGS__); fprintf(ERROR_CHANNEL, "\n");
/*******************************************************************************/


/*******************************************************************************/
/*! \def NW_VMF_DEBUG_ERROR

    Debug error output. This debug output is ALWAYS ACTIVE. \n\n
    NOTE: use for error information that shall occur always (independent of any compiler switch). */
/*******************************************************************************/
 #define NW_VMF_DEBUG_ERROR(...)          fprintf(ERROR_CHANNEL, __VA_ARGS__); fprintf(ERROR_CHANNEL, "\n");
/*******************************************************************************/








/* function prototypes */
void        nw_con_HexDump          (char * name,unsigned8 *buffer,int len);


#endif




