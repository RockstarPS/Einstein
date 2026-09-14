#ifndef __INCLUDE_GUARD_STUBS_NW_CONFIG_H__
#define __INCLUDE_GUARD_STUBS_NW_CONFIG_H__
/* OSAL Includes */
#include <os_if.h>

/* system specific header of msggroup and event definitions*/
#include "intEvtDefs.h"
//#include "task_signature.h"

#define NW_TARGET_SPECIFIC_MSG_HANDLER

typedef unsigned16                  t_nw_msg_header;
#define BUILD_NW_MSG_HEADER(a,b)    ( ( ( (t_nw_msg_header)a) << 8) + (t_nw_msg_header)b)
#define NW_MSG__GROUPID(a)          ((unsigned8)(a >> 8))
#define NW_MSG__EVENTID(a)          ((unsigned8)a)


#define NW_GROUPID_INVALID          ((unsigned8)INVAL_GROUP)
#define NW_EVENTID_INVALID          ((unsigned8)0xFF)

/*--------------------------------------------------------------------------------*/
/* A S S I G N   S Y S T E M   E V T - D E F I N I T I O N S   T O
   N W   P R O C E S S   E V T - D E F I N I T I O N S */

/*------------------------------------------------------------------------------------------------------------
                                   __                               _                       _
                                  / _|                             | |                     | |
 _ __ __  __   __   __ _ __ ___  | |_     _ __ ___   ___   __ _    | |__    ___   __ _   __| |  ___  _ __  ___
| '__|\ \/ /   \ \ / /| '_ ` _ \ |  _|   | '_ ` _ \ / __| / _` |   | '_ \  / _ \ / _` | / _` | / _ \| '__|/ __|
| |    >  <     \ V / | | | | | || |     | | | | | |\__ \| (_| |   | | | ||  __/| (_| || (_| ||  __/| |   \__ \
|_|   /_/\_\     \_/  |_| |_| |_||_|     |_| |_| |_||___/ \__, |   |_| |_| \___| \__,_| \__,_| \___||_|   |___/
                                                           __/ |
                                                          |___/
-------------------------------------------------------------------------------------------------------------*/

/* Physical MOST:  */
#define RX_MSG_HEAD__MOST_START_UP              (BUILD_NW_MSG_HEADER(NETWORK_OPERATION,  MstOprConnect))
#define RX_MSG_HEAD__MOST_SHUT_DOWN             (BUILD_NW_MSG_HEADER(NETWORK_OPERATION,  MstOprDisConnect))
/*--------------------------------------------------------------------------------*/
/* internal MOST FBlockId (de)registration */
#define RX_MSG_HEAD__REG_INTERNAL_MOST_FBLOCK   (BUILD_NW_MSG_HEADER(REG_OPERATION,      RegOprAddComp))
#define RX_MSG_HEAD__DEREG_INTERNAL_MOST_FBLOCK (BUILD_NW_MSG_HEADER(REG_OPERATION,      RegOprDelComp))
#define RX_MSG_HEAD__REG_OF_PWR_GRP_COMPLETE    (BUILD_NW_MSG_HEADER(REG_OPERATION,      RegOprComplete))
#define RX_MSG_HEAD__SYSTEM_STARTUP_COMPLETE    (BUILD_NW_MSG_HEADER(NETWORK_IN,         PmOutSystemStartupComplete))
/*--------------------------------------------------------------------------------*/
/* MOST synchronous commands for audio video purposes */
#ifdef  NW_IPM
#define RX_MSG_HEAD__SYNC_ALLOCATE              (BUILD_NW_MSG_HEADER(IPM_REQ,            IpmSyncAllocOnly))
#define RX_MSG_HEAD__SYNC_DEALLOCATE            (BUILD_NW_MSG_HEADER(IPM_REQ,            IpmSyncDeAllocOnly))
#define RX_MSG_HEAD__SYNC_IN_CONNECT            (BUILD_NW_MSG_HEADER(IPM_REQ,            IpmSyncInConnect))
#define RX_MSG_HEAD__SYNC_IN_DISCONNECT         (BUILD_NW_MSG_HEADER(IPM_REQ,            IpmSyncInDisConnect))
#define RX_MSG_HEAD__SYNC_OUT_CONNECT           (BUILD_NW_MSG_HEADER(IPM_REQ,            IpmSyncOutConnect))
#define RX_MSG_HEAD__SYNC_OUT_DISCONNECT        (BUILD_NW_MSG_HEADER(IPM_REQ,            IpmSyncOutDisConnect))
#define RX_MSG_HEAD__SYNC_MLB_CHANNEL_SYNC      (BUILD_NW_MSG_HEADER(IPM_REQ,            IpmMlbChannelSync))
#endif /* NW_IPM */
/*--------------------------------------------------------------------------------*/
/* MOXY purposes: trigger to register the MOST FBlockIds and Shadows to VMF */
#define RX_MSG_HEAD__TIRGGER_2ND_START_UP_PHASE (BUILD_NW_MSG_HEADER(BROADCAST,     BrdSysStartUp))
#define RX_MSG_HEAD__CLEAR_ALL_MOXY_REGISTRATIONS_TO_VMF    (BUILD_NW_MSG_HEADER(BROADCAST, BrdSysShutDown))

#define RX_MSG_HEAD__START_GW_IPCL_TEST         (BUILD_NW_MSG_HEADER(NETWORK_STATUS,    0xAA))
#define RX_MSG_HEAD__STOP_GW_IPCL_TEST          (BUILD_NW_MSG_HEADER(NETWORK_STATUS,    0xBB))

/*------------------------------------------------------------------------------------------------------------
 _                                __                               _                       _
| |                              / _|                             | |                     | |
| |_ __  __   __   __ _ __ ___  | |_     _ __ ___   ___   __ _    | |__    ___   __ _   __| |  ___  _ __  ___
| __|\ \/ /   \ \ / /| '_ ` _ \ |  _|   | '_ ` _ \ / __| / _` |   | '_ \  / _ \ / _` | / _` | / _ \| '__|/ __|
| |_  >  <     \ V / | | | | | || |     | | | | | |\__ \| (_| |   | | | ||  __/| (_| || (_| ||  __/| |   \__ \
 \__|/_/\_\     \_/  |_| |_| |_||_|     |_| |_| |_||___/ \__, |   |_| |_| \___| \__,_| \__,_| \___||_|   |___/
                                                          __/ |
                                                         |___/
-------------------------------------------------------------------------------------------------------------*/
#ifdef  NW_IPM
/* MOST synchronous commands for audio video purposes */
/* #define NW_SYNC_REP_ALL_BY_SAME_GROUP_ID */
#ifdef NW_SYNC_REP_ALL_BY_SAME_GROUP_ID
    /* all synchronous reports shall be sent by ONE dedicated group Id */
    #define NW_SYNC_REP_GROUP_ID                ((unsigned8)IPM_RSP)
#else
    /* the event-group, the report is to be sent to, is passed by the
       4th parameter of the near data of the request received */
    #define NW_SYNC_REP_GROUP_ID                ((unsigned8)IPM_REQ) /*use IPM_REQ as a placeholder, will be overwritten by IPM */
#endif

#define TX_MSG_HEAD__SYNC_ALLOCATE              (BUILD_NW_MSG_HEADER(NW_SYNC_REP_GROUP_ID,   IpmSyncAllocComplete))
#define TX_MSG_HEAD__SYNC_DEALLOCATE            (BUILD_NW_MSG_HEADER(NW_SYNC_REP_GROUP_ID,   IpmSyncDeAllocComplete))
#define TX_MSG_HEAD__SYNC_IN_CONNECT            (BUILD_NW_MSG_HEADER(NW_SYNC_REP_GROUP_ID,   IpmSyncResult))
#define TX_MSG_HEAD__SYNC_IN_DISCONNECT         (BUILD_NW_MSG_HEADER(NW_SYNC_REP_GROUP_ID,   IpmSyncResult))
#define TX_MSG_HEAD__SYNC_OUT_CONNECT           (BUILD_NW_MSG_HEADER(NW_SYNC_REP_GROUP_ID,   IpmSyncResult))
#define TX_MSG_HEAD__SYNC_OUT_DISCONNECT        (BUILD_NW_MSG_HEADER(NW_SYNC_REP_GROUP_ID,   IpmSyncResult))
#endif /* NW_IPM */

/*----------------------------------------------------------------------------------------------------------*/
/* MOST Network Master reports */
#define TX_MSG_HEAD__MOST_NM_CONFIG_NOT_OK      (BUILD_NW_MSG_HEADER(NETWORK_STATUS,         MstModComDisConnect))
#define TX_MSG_HEAD__MOST_NM_CONFIG_OK          (BUILD_NW_MSG_HEADER(NETWORK_STATUS,         MstModComConnect))
#define TX_MSG_HEAD__MOST_NM_CENTRAL_REGISTRY   (BUILD_NW_MSG_HEADER(NETWORK_STATUS,         MstModCntrRegUpdate))
/*----------------------------------------------------------------------------------------------------------*/
/* MOST Network NetBlock reports */
#define TX_MSG_HEAD__MOST_NB_OWN_NODE_ADDR      (BUILD_NW_MSG_HEADER(NETWORK_STATUS,         MstModOwnLogDevId))
#define TX_MSG_HEAD__MOST_NB_SHUTDOWN           (BUILD_NW_MSG_HEADER(POWER_IN,                  PmInShutdownResultRxd))
/*----------------------------------------------------------------------------------------------------------*/
/* process status */
#define TX_MSG_HEAD__NW_PROCESS_STARTED         (BUILD_NW_MSG_HEADER(POWER_IN,              CtrModFirstInitDone))
/*----------------------------------------------------------------------------------------------------------*/
/* physical MOST Network reports: */
#define TX_MSG_HEAD__MOST_NUM_NODES_IN_RING     (BUILD_NW_MSG_HEADER(NETWORK_STATUS,         MstModStoreDevCount))
#define TX_MSG_HEAD__MOST_UNLOCK                (BUILD_NW_MSG_HEADER(NETWORK_STATUS,         MstModUnlock))
#define TX_MSG_HEAD__MOST_CRITICAL_UNLOCK       (BUILD_NW_MSG_HEADER(POWER_IN,                  PmInCriticalUnlock))
#define TX_MSG_HEAD__MOST_LOCK_STABLE           (BUILD_NW_MSG_HEADER(NETWORK_STATUS,         MstModLock))
#define TX_MSG_HEAD__MOST_LIGHT_OFF             (BUILD_NW_MSG_HEADER(POWER_IN,                  PmInVirtualZero))
#define TX_MSG_HEAD__MOST_NET_ON                (BUILD_NW_MSG_HEADER(POWER_IN,                  PmInNetOn))
#define TX_MSG_HEAD__MOST_NO_ACK                (BUILD_NW_MSG_HEADER(NETWORK_STATUS,         MstModRemoveDevIdFromNotifMatrix))
/*------------------------------------------------------------------------------------------------------------*/
/* MOST process diagnostics */
#define TX_MSG_HEAD__DTC_SET                    (BUILD_NW_MSG_HEADER(DIAG_IN,                DiagSetErrorEv))
#define TX_MSG_HEAD__DTC_CLEAR                  (BUILD_NW_MSG_HEADER(DIAG_IN,                DiagClearErrorEv))

#ifdef NW_TARGET_SPECIFIC_MSG_HANDLER
unsigned16 nw_get_size_target_specific_groupid_buffer(void);
t_nw_msg_header* nw_get_target_specific_groupid_buffer(void);
#endif

#endif
