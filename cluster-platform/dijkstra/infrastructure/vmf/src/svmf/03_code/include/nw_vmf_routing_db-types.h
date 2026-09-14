#ifndef __INCLUDE_GUARD__VMF_ROUTING_DB_TYPES_H__
#define __INCLUDE_GUARD__VMF_ROUTING_DB_TYPES_H__

#define GROUPID_OWN_NODE_ADDR (NW_MSG__GROUPID(TX_MSG_HEAD__MOST_NB_OWN_NODE_ADDR))
#define EVENTID_OWN_NODE_ADDR (NW_MSG__EVENTID(TX_MSG_HEAD__MOST_NB_OWN_NODE_ADDR))

/* The inclusion of "nw_vmf_types.h" must come after the definition of
 * the integer types. Otherwise, unit tests are getting confused. Please,
 * do not move the below include statements to the head of the file,
 * please, do not!                                                        */
#include "nw_vmf_routing_db-definitions.h"
#include "vmf.h"

#if 0

    /* jmerkle: SVMF -- remove MOST stuff... */

    #define NW_VMF_ROUTING_DB_MOST_TX_MSG_TARGET_ADR(Msg)   ((Msg).tgt_addr)
    #define NW_VMF_ROUTING_DB_MOST_TX_MSG_FBLOCK_ID(Msg)    ((Msg).fblock_id)
    #define NW_VMF_ROUTING_DB_MOST_TX_MSG_INSTANCE_ID(Msg)  ((Msg).inst_id)
    #define NW_VMF_ROUTING_DB_MOST_TX_MSG_FUNCTION_ID(Msg)  ((Msg).func_id)
    #define NW_VMF_ROUTING_DB_MOST_TX_MSG_OP_TYPE(Msg)      ((Msg).op_type)

    #define NW_VMF_ROUTING_DB_SHADOW_DB_KEY_ENCODE(FBlockID, InstID, FunctionID) \
            (FBlockID << 20 | InstID << 12 | FunctionID)

    #define NW_VMF_ROUTING_DB_SHADOW_DB_KEY_DECODE_FBLOCK_ID(FBblockInstIDFunctionID) \
            (((FBblockInstIDFunctionID) & 0x0FF00000) >> 20);

    #define NW_VMF_ROUTING_DB_SHADOW_DB_KEY_DECODE_INSTANCE_ID(FBblockInstIDFunctionID) \
            (((FBblockInstIDFunctionID) & 0x000FF000) >> 12);

    #define NW_VMF_ROUTING_DB_SHADOW_DB_KEY_DECODE_FUNCTION_ID(FBblockInstIDFunctionID) \
            ((FBblockInstIDFunctionID) & 0x00000FFF);

    #define NW_VMF_ROUTING_DB_EVENT_IS_NODE_ADDRESS_ANOUNCEMENT(Msg) \
            (((Msg).id.group == GROUPID_OWN_NODE_ADDR) && ((Msg).id.event == EVENTID_OWN_NODE_ADDR))
    #define NW_VMF_ROUTING_DB_EVENT_IS_MOST(Msg)         ((Msg).base.msg_type == MSG_TYPE_MOST_MESSAGE)
    #define NW_VMF_ROUTING_DB_EVENT_GET_GROUP_ID(Msg)    ((Msg).id.group)

#else
    #define NW_VMF_ROUTING_DB_MOST_TX_MSG_TARGET_ADR(Msg)               0
    #define NW_VMF_ROUTING_DB_MOST_TX_MSG_FBLOCK_ID(Msg)                0
    #define NW_VMF_ROUTING_DB_MOST_TX_MSG_INSTANCE_ID(Msg)              0
    #define NW_VMF_ROUTING_DB_MOST_TX_MSG_FUNCTION_ID(Msg)              0
    #define NW_VMF_ROUTING_DB_MOST_TX_MSG_OP_TYPE(Msg)                  0

    #define NW_VMF_ROUTING_DB_EVENT_IS_NODE_ADDRESS_ANOUNCEMENT(Msg)    0
    #define NW_VMF_ROUTING_DB_EVENT_IS_MOST(Msg)                        0

#endif

typedef struct {
    vmf_handle_t*  begin;
    unsigned8                 length;
} vmf_handle_list_t;

typedef struct {
    vmf_handle_t  begin[NW_VMF_ROUTING_DB_MEMORY_POOL_ELEMENT_N];
    vmf_handle_t* end;
    vmf_handle_t* memory_end;

} vmf_routing_db_memory_pool_t;

typedef enum {
    NW_VMF_ROUTING_DB_REGISTRATION_EXTERNAL_MOST,
    NW_VMF_ROUTING_DB_REGISTRATION_SHADOW,
    NW_VMF_ROUTING_DB_REGISTRATION_FBLOCK,

} vmf_routing_db_registration_enum;

typedef struct {
    struct { unsigned16    fblock_inst; } subject;
    struct { vmf_handle_t  handle; }      observer;

} vmf_routing_db_most_fblock_entry_t;

typedef struct {
    vmf_routing_db_most_fblock_entry_t    begin[NW_VMF_ROUTING_DB_MOST_FBLOCK_MAX_ELEMENT_N];
    vmf_routing_db_most_fblock_entry_t*   end;
    vmf_routing_db_most_fblock_entry_t*   memory_end;

} vmf_routing_db_most_fblock_t;


typedef struct {
    struct { unsigned32        fblock_inst_function; } subject;
    struct { vmf_handle_list_t handle_list; }          observer;

} vmf_routing_db_most_shadow_entry_t;

typedef struct {
    vmf_routing_db_most_shadow_entry_t    begin[NW_VMF_ROUTING_DB_MOST_SHADOW_MAX_ELEMENT_N];
    vmf_routing_db_most_shadow_entry_t*   end;
    vmf_routing_db_most_shadow_entry_t*   memory_end;

} vmf_routing_db_most_shadow_t;


typedef struct {
    struct { unsigned8          event_group_id; } subject;
    struct { vmf_handle_list_t  handle_list; }    observer;

} vmf_routing_db_event_entry_t;

typedef struct {
    vmf_routing_db_event_entry_t    begin[NW_VMF_ROUTING_DB_EVENT_MAX_ELEMENT_N];
    vmf_routing_db_event_entry_t*   end;
    vmf_routing_db_event_entry_t*   memory_end;

} vmf_routing_db_event_t;

typedef struct {
    struct {
        vmf_routing_db_most_fblock_t fblock_db;
        vmf_routing_db_most_shadow_t shadow_db;
        vmf_handle_t                 external_receiver_handle;
        unsigned16                   own_node_address;
    } most;

    struct {
        vmf_routing_db_event_t       db;
    } event;

} vmf_routing_db_t;

#endif /* __INCLUDE_GUARD__VMF_ROUTING_DB_TYPES_H__ */
