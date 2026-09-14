#include "nw_vmf_routing_db.h"

#define NW_ROUTING_DB_CLEAR \
        __vmf_routing_db_most_shadow_clear
#define NW_ROUTING_DB_REGISTER \
        __vmf_routing_db_most_shadow_register(vmf_handle_t Handle, \
                                              unsigned8 FBlockID, unsigned8 InstID, unsigned16 FunctionID)   
#define NW_ROUTING_DB_DEREGISTER \
        __vmf_routing_db_most_shadow_deregister(vmf_handle_t Handle, \
                                                unsigned8 FBlockID, unsigned8 InstID, unsigned16 FunctionID)
#define NW_ROUTING_DB_GET_HANDLES \
        __vmf_routing_db_most_shadow_get_handle_list(vmf_most_msg_t* msg, vmf_handle_t** response_p)
#define NW_ROUTING_DB_FIND_ENTRY \
        __vmf_routing_db_most_shadow_find

#define NW_ROUTING_DB_THIS         &(__vmf_routing_db()->most.shadow_db)
#define NW_ROUTING_DB_TYPE         vmf_routing_db_most_shadow_t
#define NW_ROUTING_DB_ENTRY_TYPE   vmf_routing_db_most_shadow_entry_t

#define NW_ROUTING_DB_KEY_TYPE                     unsigned32
#define NW_ROUTING_DB_KEY(Entry)                   ((Entry)->subject.fblock_inst_function)
#define NW_VMF_ROUTING_MAP_VMF_MESSAGE_TO_KEY(Msg) (  (NW_VMF_ROUTING_DB_MOST_TX_MSG_FBLOCK_ID(Msg)   << 20) \
                                                    | (NW_VMF_ROUTING_DB_MOST_TX_MSG_INSTANCE_ID(Msg) << 12) \
                                                    | (NW_VMF_ROUTING_DB_MOST_TX_MSG_FUNCTION_ID(Msg)))
#define NW_ROUTING_DB_MAP_ARGUMENTS_TO_KEY         ((FBlockID << 20) | (InstID << 12) | (FunctionID))

#define NW_ROUTING_DB_MAX_ENTRY_N                  (NW_VMF_ROUTING_DB_MOST_SHADOW_MAX_ELEMENT_N)

#include "nw_vmf_routing_db-template.cg"
