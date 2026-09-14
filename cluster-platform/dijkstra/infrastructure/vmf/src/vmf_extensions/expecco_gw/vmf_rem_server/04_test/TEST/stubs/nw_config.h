
#ifndef NW_CONFIG_H
#define NW_CONFIG_H

typedef unsigned16                  t_nw_msg_header;

#define BUILD_NW_MSG_HEADER(a,b)    ( ( ( (t_nw_msg_header)a) << 8) + (t_nw_msg_header)b)
#define NW_MSG__GROUPID(a)          ((unsigned8)(a >> 8))
#define NW_MSG__EVENTID(a)          ((unsigned8)a)

#define RX_MSG_HEAD__REG_INTERNAL_MOST_FBLOCK   (BUILD_NW_MSG_HEADER(0x10,0x01))
#define RX_MSG_HEAD__DEREG_INTERNAL_MOST_FBLOCK (BUILD_NW_MSG_HEADER(0x10,0x02))

#define TX_MSG_HEAD__MOST_NB_OWN_NODE_ADDR      (BUILD_NW_MSG_HEADER(0x12,0x01))
#define TX_MSG_HEAD__MOST_NUM_NODES_IN_RING     (BUILD_NW_MSG_HEADER(0x12,0x02))

#define TX_MSG_HEAD__SOMETHING_ELSE             (BUILD_NW_MSG_HEADER(0x88,0x08))


#define BROADCAST                   (0x7A)


#endif

