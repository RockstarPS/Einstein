#ifndef __NW_MSG_HEADER_DEFS__
#define __NW_MSG_HEADER_DEFS__


/* system specific header of msggroup and event definitions*/
#include <os_types.h>


#ifdef NW_EXTERNAL_MOST_ENABLED
#include "pw_wc_agent.h"
#endif

#define NW_DIAG

/*---------vmf limits-----------*/
#define MAX_VMF_DATA_LEN                    ((unsigned16)4064)
#define VMF_CLIENT_QUEUE_SIZE_SMALL         ((unsigned16)10)
#define VMF_CLIENT_QUEUE_SIZE_STANDARD      ((unsigned16)30)
#define VMF_CLIENT_QUEUE_SIZE_BIG           ((unsigned16)100)

/*! size of message data */
#define VMF_CLIENT_DATA_SIZE_SMALL          ((unsigned16)10)
#define VMF_CLIENT_DATA_SIZE_STANDARD       ((unsigned16)200)

#ifdef DC15 /* Nissan DC1.5 */
#define VMF_BASIC_MSG_NEAR_DATA_LENGTH      0       /* ((unsigned16)0) */
#else
#define VMF_BASIC_MSG_NEAR_DATA_LENGTH      4       /* ((unsigned16)4) */
#endif
#define MAX_NAME_LEN                        100
#define MAX_NUM_FKT_IDS                     1       /*  mhammer3, 08/13/2008 -*/
#define MAX_GROUP_NUM                       250
#define MAX_CTRL_CONN_PL_LEN                50      /* max payload len for ctrl connect message */

/*------------------------------*/


#define NW_EXTERNAL_MOST_CONNECTION_NUMBER /*   this definition has been introduced to workaround 
                                                the issue of loosing the connection to the INIC. 
                                                It does not reduce the occurences of INIC entering 
                                                proteced mode, but prevents any user visible impacts 
                                                within the application */

typedef unsigned16                  t_nw_msg_header;
#define BUILD_NW_MSG_HEADER(a,b)    ( ( ( (t_nw_msg_header)a) << 8) + (t_nw_msg_header)b)
#define NW_MSG__GROUPID(a)          ((unsigned8)(a >> 8))
#define NW_MSG__EVENTID(a)          ((unsigned8)a)


#define NW_GROUPID_INVALID          ((unsigned8)INVAL_GROUP)
#define NW_EVENTID_INVALID          ((unsigned8)0xFF)

//#ifdef NW_EXTERNAL_MOST_ENABLED
#ifndef NW_SIGNATURE
#define NW_SIGNATURE 2
#endif
#define MOST_PROCESS_SIG            (NW_SIGNATURE)
//#endif

#define NW_TARGET_SPECIFIC_MSG_HANDLER
#ifdef NW_TARGET_SPECIFIC_MSG_HANDLER
unsigned16 nw_get_size_target_specific_groupid_buffer(void);
t_nw_msg_header* nw_get_target_specific_groupid_buffer(void);
#endif


#define ENABLE_TARGET_SPECIFIC_TIMER
#ifdef ENABLE_TARGET_SPECIFIC_TIMER
void nw_target_specific_on_timer_trigger(unsigned32 u32gobaltime);
#endif

typedef enum 
{
    NW_DIAG_TIMER__INVALID = 0,
    NW_DIAG_TIMER__UNLOCK_FILTER,
    NW_DIAG_TIMER__VOLTAGE_FILTER,
    NW_DIAG_TIMER__NET_ON_FILTER,
    NW_DIAG_TIMER__PWR_SWITCH_OFF_DELAY
}NW_DIAG_TIMER_TYPE;

void nw_diag_on_timer_trigger(unsigned32 u32gobaltime, NW_DIAG_TIMER_TYPE timer );

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
#define RX_MSG_HEAD__MOST_START_UP              (BUILD_NW_MSG_HEADER(NETWORK_OPERATION, MstOprConnect))
#define RX_MSG_HEAD__MOST_SHUT_DOWN             (BUILD_NW_MSG_HEADER(NETWORK_OPERATION, MstOprDisConnect))
#define RX_MSG_HEAD__MOST_FOT_TEMP_STATUS       (BUILD_NW_MSG_HEADER(NETWORK_IN,PmOutTempStatus))
/*--------------------------------------------------------------------------------*/
/* internal MOST FBlockId (de)registration */
#define RX_MSG_HEAD__REG_INTERNAL_MOST_FBLOCK   (BUILD_NW_MSG_HEADER(REG_OPERATION,     RegOprAddFBlock))
#define RX_MSG_HEAD__DEREG_INTERNAL_MOST_FBLOCK (BUILD_NW_MSG_HEADER(REG_OPERATION,     RegOprDelFBlock))
#if 1
#define RX_MSG_HEAD__REG_INTERNAL_MOST_SHADOW   (BUILD_NW_MSG_HEADER(REG_OPERATION,     RegOprAddShadow))
#endif
#define RX_MSG_HEAD__REG_OF_PWR_GRP_COMPLETE    (BUILD_NW_MSG_HEADER(REG_OPERATION,     RegOprComplete))
#define RX_MSG_HEAD__SYSTEM_STARTUP_COMPLETE    (BUILD_NW_MSG_HEADER(NETWORK_IN,        PmOutSystemStartupComplete))
/*--------------------------------------------------------------------------------*/
/* MOXY purposes: trigger to register the MOST FBlockIds and Shadows to VMF */
#define RX_MSG_HEAD__TIRGGER_2ND_START_UP_PHASE (BUILD_NW_MSG_HEADER(BROADCAST,     BrdSysStartUp))
#define RX_MSG_HEAD__CLEAR_ALL_MOXY_REGISTRATIONS_TO_VMF    (BUILD_NW_MSG_HEADER(BROADCAST, BrdSysShutDown))




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

/*----------------------------------------------------------------------------------------------------------*/
/* MOST Network Master reports */
#define TX_MSG_HEAD__MOST_NM_CONFIG_NOT_OK      (BUILD_NW_MSG_HEADER(NETWORK_STATUS,    MstModComDisConnect))
#define TX_MSG_HEAD__MOST_NM_CONFIG_OK          (BUILD_NW_MSG_HEADER(NETWORK_STATUS,    MstModComConnect))
#define TX_MSG_HEAD__MOST_NM_CENTRAL_REGISTRY   (BUILD_NW_MSG_HEADER(NETWORK_STATUS,    MstModCntrRegUpdate))
#define TX_MSG_HEAD__CLEAR_ALL_NOTIFICATIONS    (BUILD_NW_MSG_HEADER(NETWORK_STATUS,    MstModClearAllNotifications))
/*----------------------------------------------------------------------------------------------------------*/
/* MOST Network NetBlock reports */
#define TX_MSG_HEAD__MOST_NB_OWN_NODE_ADDR      (BUILD_NW_MSG_HEADER(NETWORK_STATUS,    MstModOwnLogDevId))
#define TX_MSG_HEAD__MOST_NB_SHUTDOWN           (BUILD_NW_MSG_HEADER(POWER_IN,          PmInShutdownResultRxd))
/*----------------------------------------------------------------------------------------------------------*/
/* process status */
#define TX_MSG_HEAD__NW_PROCESS_STARTED         (BUILD_NW_MSG_HEADER(POWER_IN,         CtrlModeFirstInitDone))
/*----------------------------------------------------------------------------------------------------------*/
/* physical MOST Network reports: */
#define TX_MSG_HEAD__MOST_NUM_NODES_IN_RING     (BUILD_NW_MSG_HEADER(NETWORK_STATUS,    MstModStoreDevCount))
#define TX_MSG_HEAD__MOST_UNLOCK                (BUILD_NW_MSG_HEADER(NETWORK_STATUS,    MstModUnlock))
#define TX_MSG_HEAD__MOST_CRITICAL_UNLOCK       (BUILD_NW_MSG_HEADER(POWER_IN,          PmInCriticalUnlock))
#define TX_MSG_HEAD__MOST_LOCK_STABLE           (BUILD_NW_MSG_HEADER(NETWORK_STATUS,    MstModLock))
#define TX_MSG_HEAD__MOST_LIGHT_OFF             (BUILD_NW_MSG_HEADER(POWER_IN,          PmInVirtualZero))
#define TX_MSG_HEAD__MOST_NET_ON                (BUILD_NW_MSG_HEADER(POWER_IN,          PmInNetOn))
#define TX_MSG_HEAD__MOST_NO_ACK                (BUILD_NW_MSG_HEADER(NETWORK_STATUS,    MstModRemoveDevIdFromNotifMatrix))

/*------------------------------------------------------------------------------------------------------------*/
/* MOST process diagnostics */
#define TX_MSG_HEAD__DTC_SET                    (BUILD_NW_MSG_HEADER(DIAG_IN,           DiagSetErrorEv))
#define TX_MSG_HEAD__DTC_CLEAR                  (BUILD_NW_MSG_HEADER(DIAG_IN,           DiagClearErrorEv))

#if 0
#define NW_MLB_LLD_HISTORY_ENABLED
void nw_mlb_lld_start_history_buffering(void);
void nw_mlb_lld_stop_history_buffering(void);
#endif

#endif /* __NW_MSG_HEADER_DEFS__ */
