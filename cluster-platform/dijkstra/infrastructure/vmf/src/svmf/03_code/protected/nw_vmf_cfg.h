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

  \file                 nw_vmf_cfg.h
  \brief                VMF configuration file

  \author               Joerg Merkle
  \author               Visteon Deutschland GmbH, Infotainment Software

  *****************************************************************************/
#ifndef __VMF_CFG_H__
#define __VMF_CFG_H__

/* version string */
#define VMF_MAJOR_NUMBER            1
#define VMF_MINOR_NUMBER            01

#define MAKE_STRING2(str) #str
#define MAKE_STRING1(str) MAKE_STRING2(str)
#define VMF_VERSION_STRING "version " MAKE_STRING1(VMF_MAJOR_NUMBER) "." MAKE_STRING1(VMF_MINOR_NUMBER)

/* global switch to enable the MOST functionality of VMF */
/* #define NW_VMF_MOST_ENABLED */


/*! \def NW_VMF_ROUTING_DB_MOST_FBLOCK_MAX_ELEMENT_N
 *  This macro defines the maximum number of (FBlock, InstanceID) pairs that
 *  can be allocated in the internal database of the router.                 */
#ifndef   NW_VMF_ROUTING_DB_MOST_FBLOCK_MAX_ELEMENT_N
#  define NW_VMF_ROUTING_DB_MOST_FBLOCK_MAX_ELEMENT_N  (1)
#endif

/*! \def NW_VMF_ROUTING_DB_MOST_SHADOW_MAX_ELEMENT_N
 *  This macro defines the maximum number of shadow registrations. This means
 *  it contains the maximum number of distinct tuples (Fblock, InstanceID, FunctionID)
 *  for which the vmf clients can request a notification.                    */
#ifndef   NW_VMF_ROUTING_DB_MOST_SHADOW_MAX_ELEMENT_N
#  define NW_VMF_ROUTING_DB_MOST_SHADOW_MAX_ELEMENT_N  (1)
#endif

/*! \def NW_VMF_ROUTING_DB_EVENT_MAX_ELEMENT_
 *  Maximum number of different events that can occur. Each event gets its
 *  own list of 'recipients'. Here, only specify the maximum possible number
 *  of unique event ids.                                                     */
#ifndef   NW_VMF_ROUTING_DB_EVENT_MAX_ELEMENT_N
#  define NW_VMF_ROUTING_DB_EVENT_MAX_ELEMENT_N        (250)
#endif

/*! \def NW_VMF_ROUTING_DB_MEMORY_POOL_ELEMENT_N
 *  Total amount of client handles that appear in the database. All three database
 *  rely on the same memory pool in order to allocate the client handle lists. The
 *  following number indicates the total number of client handles that appear in
 *  the databases. NOTE: This is not the number of vmf clients. A client can be
 *  registered for multiple events and multiple 'shadows' (FBlock, FuncID, InstID)
 *  at the same time.                                                       */
#ifndef   NW_VMF_ROUTING_DB_MEMORY_POOL_ELEMENT_N
#  define NW_VMF_ROUTING_DB_MEMORY_POOL_ELEMENT_N      (1000)
#endif

/*! \def NW_VMF_ROUTING_DB_DEFAULT_OWN_NODE_ADDRESSS
 *  Default node address before the framework sends the 'real' node address. This only
 *  plays games when the own node address is required before it actually should. It's a
 *  parachute.                                                              */
#ifndef    NW_VMF_ROUTING_DB_DEFAULT_OWN_NODE_ADDRESSS
#  define  NW_VMF_ROUTING_DB_DEFAULT_OWN_NODE_ADDRESSS (0x0100)
#endif

/* The routing database requires some temporary storage in order
 * to store information about queries. The issue is related to
 * finding the 'first matching' fblock and 'all matching' fblocks
 * triggered by instance ids of 0x00 and 0xFF */
#ifndef   NW_VMF_ROUTING_DB_TEMPORARY_RESPONSE_ARRAY_SIZE
#  define NW_VMF_ROUTING_DB_TEMPORARY_RESPONSE_ARRAY_SIZE  (50)
#endif



/* data size of vmf-collector message          */
/* used inside vmf-client to pack vmf messages */
#ifndef VMF_CO_DATA_LEN
#define VMF_CO_DATA_LEN VMF_CLIENT_DATA_SIZE_STANDARD
#endif

/*******************************************************************************/
/* VMF configurations */
/*******************************************************************************/

#define VMF_NW_STACK_SIZE   ((32*1024) + MAX_VMF_DATA_LEN)           /* default stack size for all threads */


/*******************************************************************************/
/* VMF spy configurations */
/*******************************************************************************/

/*******************************************************************************/
/*! \def VMF_SPY_QUEUE_SIZE
     Defines the message queue size for the VMF spy. */
/*******************************************************************************/
#define VMF_SPY_QUEUE_SIZE      (unsigned16) 10
/*******************************************************************************/

/*******************************************************************************/
/*! \def VMF_SPY_BROADCAST_ADR
     Defines the broadcast IP address for VMF spy in UDP mode. */
/*******************************************************************************/
#define VMF_SPY_BROADCAST_ADR   "192.168.5.255"
/*******************************************************************************/

/*******************************************************************************/
/*! \def VMF_SPY_BROADCAST_ADR
     Defines the IP address of the PC for VMF spy in TCP/IP mode. */
/*******************************************************************************/
#define VMF_SPY_PROFILER_ADR    "192.168.5.55"
/*******************************************************************************/


/*******************************************************************************/
/*! \def VMF_TRACE_PERSISTENT_DATA
     Defines vmf_trace persitent data directory and file-name */
/*******************************************************************************/

#if defined LINUX_X86
#define VMF_TRACE_PERSISTENT_DATA   "./nw_vmf_trace.dat"
#define VMF_CTRL_PERSISTENT_DATA    "./nw_vmf_ctrl.dat"
#elif defined R013
#define VMF_TRACE_PERSISTENT_DATA   "/pss2/app_data/nw_vmf_trace.dat"
#define VMF_CTRL_PERSISTENT_DATA    "/pss2/app_data/nw_vmf_ctrl.dat"
#elif defined EAGLE
#define VMF_TRACE_PERSISTENT_DATA   "/opt/nw_vmf_trace.dat"
#define VMF_CTRL_PERSISTENT_DATA    "/opt/nw_vmf_ctrl.dat"
#elif defined EAGLE_UPDATE
#define VMF_TRACE_PERSISTENT_DATA   "/opt/nw_vmf_trace.dat"
#define VMF_CTRL_PERSISTENT_DATA    "/opt/nw_vmf_ctrl.dat"
#elif defined QNX_X86
#define VMF_TRACE_PERSISTENT_DATA   "./nw_vmf_trace.dat"
#define VMF_CTRL_PERSISTENT_DATA    "./nw_vmf_ctrl.dat"
#elif defined DC15
#define VMF_TRACE_PERSISTENT_DATA   "/rwdata/nw_vmf_trace.dat"
#define VMF_CTRL_PERSISTENT_DATA    "/rwdata/nw_vmf_ctrl.dat"
#elif defined __WINDOWS__
#define VMF_TRACE_PERSISTENT_DATA   "c:\\temp\\nw_vmf_trace.dat"
#define VMF_CTRL_PERSISTENT_DATA    "c:\\temp\\nw_vmf_ctrl.dat"
#else
#define VMF_TRACE_PERSISTENT_DATA   "./nw_vmf_trace.dat"
#define VMF_CTRL_PERSISTENT_DATA    "./nw_vmf_ctrl.dat"
#endif

/* jmerkle  Ubuntu VMWare Image */
/* jmerkle  #define VMF_TRACE_PERSISTENT_DATA   "/home/tbruenck/projects/rapid-benchmark/vmf_trace.dat" */

/* jmerkle  Ubuntu Intel N450 Board */
/* jmerkle  #define VMF_TRACE_PERSISTENT_DATA   "/home/visteon/projects/rapid-benchmark/vmf_trace.dat" */

/* jmerkle  Android Intel N450 Board */
/* jmerkle  #define VMF_TRACE_PERSISTENT_DATA   "/data/visteon/vmf/vmf_trace.dat" */

/* jmerkle  Rapid B2 Board */
/* jmerkle  #define VMF_TRACE_PERSISTENT_DATA   "/root/rapid-benchmark/vmf_trace.dat" */

/*******************************************************************************/



/*******************************************************************************/
/* VMF Trace Configurations */
/*******************************************************************************/

/*******************************************************************************/
/*! \def VMF_TRACE_QUEUE_SIZE
     Defines the message queue size for the VMF trace server. */
/*******************************************************************************/
#define VMF_TRACE_QUEUE_SIZE        (unsigned16) 100
#define VMF_TRACE_MSG_SIZE          (600)
#define VMF_TRACE_QUEUE_MSG_SIZE    ((unsigned16)sizeof(VMF_VAR_MSG_TYP(VMF_TRACE_MSG_SIZE)))
/*******************************************************************************/



/* switches */

/*******************************************************************************/
/*! \def NW_VMF_CFG_ALLOW_SHADOW_WITH_EMPTY_FUNCTION_LIST
     For Mocca wrapper use, it's allowed to register a shadow with empty
     function list (only FBlockId and InstId). Therefore the router db needs
     a second call to get those registered clients... */
/*******************************************************************************/
/* #define NW_VMF_CFG_ALLOW_SHADOW_WITH_EMPTY_FUNCTION_LIST */
/*******************************************************************************/


/*******************************************************************************/
/*! \def NW_VMF_CFG_ALLOW_KICKOUT_NON_RESPONDING_CLIENTS
     In the case a client isn't able to receive messages anymore this client
     will be kicked off from the vmf router database after some retries.
     This client will NOT receive any message any more!
     See NW_VMF_CFG_SEND_ERROR_RETRY_COUNT_MAX */
/*******************************************************************************/
#define NW_VMF_CFG_ALLOW_KICKOUT_NON_RESPONDING_CLIENTS
/*******************************************************************************/

/*******************************************************************************/
/*! \def NW_VMF_CFG_SEND_ERROR_RETRY_COUNT_MAX
     This is the max retry count before a client is kicked off by vmf router.
     NW_VMF_CFG_ALLOW_KICKOUT_NON_RESPONDING_CLIENTS needs to be switched on! */
/*******************************************************************************/
#define NW_VMF_CFG_SEND_ERROR_RETRY_COUNT_MAX   (unsigned8) 50
/*******************************************************************************/

#define UNUSED(x)   x=x

#define VMF_INI_FILE    "vmf.ini"

#endif
