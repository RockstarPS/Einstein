#include "nw_vmf_routing_db.h"

#define NW_ROUTING_DB_CLEAR \
        __vmf_routing_db_event_clear
#define NW_ROUTING_DB_REGISTER \
        __nw_vmf_routing_db_event_register(vmf_handle_t Handle, unsigned8 EventGroupID)
#define NW_ROUTING_DB_DEREGISTER \
        __nw_vmf_routing_db_event_deregister(vmf_handle_t Handle, unsigned8 EventGroupID)
#define NW_ROUTING_DB_GET_HANDLES \
        __vmf_routing_db_event_get_handle_list(vmf_msg_t* msg, vmf_handle_t** response_p)
#define NW_ROUTING_DB_FIND_ENTRY \
        __vmf_routing_db_event_find

#define NW_ROUTING_DB_THIS         &(__vmf_routing_db()->event.db)
#define NW_ROUTING_DB_TYPE         vmf_routing_db_event_t
#define NW_ROUTING_DB_ENTRY_TYPE   vmf_routing_db_event_entry_t

#define NW_ROUTING_DB_KEY_TYPE                     unsigned8
#define NW_ROUTING_DB_KEY(Entry)                   ((Entry)->subject.event_group_id)

#if 0
    #define NW_VMF_ROUTING_MAP_VMF_MESSAGE_TO_KEY(Msg) ((Msg).msg_base.id.group)
#else
    #define NW_VMF_ROUTING_MAP_VMF_MESSAGE_TO_KEY(Msg) ((Msg).group)
#endif


#define NW_ROUTING_DB_MAP_ARGUMENTS_TO_KEY         (EventGroupID)

#define NW_ROUTING_DB_MAX_ENTRY_N            (NW_VMF_ROUTING_DB_EVENT_MAX_ELEMENT_N)

#include "nw_vmf_routing_db-template.cg"
