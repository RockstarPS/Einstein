
#include "intEvtDefs.h"
#include "nw_os_config.h"
#include "nw_vmf_routing_db.h"
#include "nw_vmf_routing_db-private.h"
#include "nw_vmf_types.h"

static void __nw_vmf_routing_db_clear_core(vmf_routing_db_t* db);

vmf_routing_db_t*
__vmf_routing_db(void)
{
    static bool              virginity_f = true;
    static vmf_routing_db_t  the_routing_db;

    if( virginity_f ) {
        virginity_f = false;
        __nw_vmf_routing_db_clear_core(&the_routing_db);
    }

    /* if( ! (the_routing_db.most.fblock_db.begin <= the_routing_db.most.fblock_db.end) ) { 1 + 1 == 2; } */
    /* if( ! (the_routing_db.most.shadow_db.begin <= the_routing_db.most.shadow_db.end) ) { 1 + 1 == 2; } */
    assert(the_routing_db.most.fblock_db.begin <= the_routing_db.most.fblock_db.end);
    assert(the_routing_db.most.fblock_db.end   <= the_routing_db.most.fblock_db.memory_end);
    assert(the_routing_db.most.shadow_db.begin <= the_routing_db.most.shadow_db.end);
    assert(the_routing_db.most.shadow_db.end   <= the_routing_db.most.shadow_db.memory_end);
    assert(the_routing_db.event.db.begin       <= the_routing_db.event.db.end);
    assert(the_routing_db.event.db.end         <= the_routing_db.event.db.memory_end);

    return &the_routing_db;
}

void
nw_vmf_routing_db_clear(void)
{
    __nw_vmf_routing_db_clear_core(__vmf_routing_db());
}

static void
__nw_vmf_routing_db_clear_core(vmf_routing_db_t* db)
{
    {   /* most */
        db->most.shadow_db.end        = db->most.shadow_db.begin;
        db->most.shadow_db.memory_end = db->most.shadow_db.begin + NW_VMF_ROUTING_DB_MOST_SHADOW_MAX_ELEMENT_N;
        db->most.fblock_db.end        = db->most.fblock_db.begin;
        db->most.fblock_db.memory_end = db->most.fblock_db.begin + NW_VMF_ROUTING_DB_MOST_FBLOCK_MAX_ELEMENT_N;

        db->most.external_receiver_handle = VMF_HANDLE_INVALID;
        db->most.own_node_address         = NW_VMF_ROUTING_DB_DEFAULT_OWN_NODE_ADDRESSS;
    }
    {   /* events */
        db->event.db.end        = db->event.db.begin;
        db->event.db.memory_end = db->event.db.begin + NW_VMF_ROUTING_DB_EVENT_MAX_ELEMENT_N;
    }
}

void
__vmf_routing_db_set_own_node_address(unsigned16 NodeAdr)
{ __vmf_routing_db()->most.own_node_address = NodeAdr; }


vmf_ret_t
nw_vmf_routing_db_get_handle_list(vmf_msg_base_t* msg, vmf_handle_t** response_p)
{
    static vmf_handle_t   reply_on_broadcast[1] = { VMF_HANDLE_BROADCAST };
    vmf_basic_msg_t*      basic_msg = 0x0;
    #if ((defined NW_VIRTUAL_MOST_ENABLED) || (defined NW_EXTERNAL_MOST_ENABLED))
    vmf_routing_db_t*     db                    = __vmf_routing_db();
    unsigned16            tmp       = 0;
    vmf_most_msg_t*       most_msg  = 0x0;
    unsigned16            u16nodeAddr = 0;
    #endif
	vmf_ret_t			  vmf_ret = 0;

    if( msg->id.group == VMF_BROADCAST_GROUP ) {
        /* reply_on_broadcast[1] = NW_VMF_ROUTING_DB_EVENT_SOURCE_HANDLE(*msg); */
        *response_p = reply_on_broadcast;
        vmf_ret = 1; /* only one handle: the external one */
    }
    #if ((defined NW_VIRTUAL_MOST_ENABLED) || (defined NW_EXTERNAL_MOST_ENABLED))
    else if( NW_VMF_ROUTING_DB_EVENT_IS_MOST(*msg) ) {
        most_msg = (vmf_most_msg_t*)msg;
        
        /* check first if MOST msg needs to go to external MOST link */
        if(    NW_VMF_ROUTING_DB_MOST_TX_MSG_TARGET_ADR(*most_msg) != db->most.own_node_address
            && NW_VMF_ROUTING_DB_MOST_TX_MSG_TARGET_ADR(*most_msg) != 0xFFFF ) {

            if( db->most.external_receiver_handle != VMF_HANDLE_INVALID ) {
                *response_p = &(db->most.external_receiver_handle);
                return (vmf_ret_t)1;
            } else {
                return (vmf_ret_t)0;
            }

        } 
        /* target address is either internal or invalid, so check if MOST msg is either of optype COMMAND or REPORT */
        else if( NW_VMF_ROUTING_DB_MOST_TX_MSG_OP_TYPE(*most_msg) <= 8 )  {
            /* Commands */
            
            /* search in data-base, if command needs to go to an internal client */
            tmp = (unsigned16)__vmf_routing_db_most_fblock_get_handle_list(most_msg, response_p);

            if( tmp != 0 ) {
                /* this MOST command msg is to go to an internal client */
                return((vmf_ret_t)tmp);
            } else {
                /* FBlockId and InstId are not contained by our device */
                if(NW_VMF_ROUTING_DB_MOST_TX_MSG_TARGET_ADR(*most_msg) == db->most.own_node_address){
                    /* MOST command msg was addressed to own target-address, but FBlockId and InstId pair are not contained by our device */
                    /* return error */
                    if( __vmf_routing_db_most_fblock_get_handle_list_first_that_matches(NW_VMF_ROUTING_DB_MOST_TX_MSG_FBLOCK_ID(*most_msg), 
                                                                                        response_p) != 0 ) {
                        /* FBlock exists, but the instance id is wrong. */
                        return VMF_ERR_ROUTER_INVALID_INST_ID;
                    } else { 
                        /* FBlock and InstanceID are both wrong. */
                        return VMF_ERR_ROUTER_INVALID_FB;
                    }
                }
                else{
                    /* address is invalid = 0xFFFF, so send it to external MOST link */
                    if( db->most.external_receiver_handle != VMF_HANDLE_INVALID ) {
                        *response_p = &(db->most.external_receiver_handle);
                        return (vmf_ret_t)1;
                    } else {
                        return (vmf_ret_t)0;
                    }
                }
            }
        } else {
            /* Reports */
            if(NW_VMF_ROUTING_DB_MOST_TX_MSG_TARGET_ADR(*most_msg) == db->most.own_node_address){
                    return((vmf_ret_t)__vmf_routing_db_most_shadow_get_handle_list(most_msg, response_p));
            }
            else{
                /* discard msg, because every report msg MUST have a valid target address */
                return VMF_ERR_ROUTER_MOST_REP_MSG_INV_TGT_ADDR;
            }
        }
    }
    #endif
    else {
        /* vmf basic msg */
        basic_msg = (vmf_basic_msg_t*)msg;
        #if ((defined NW_VIRTUAL_MOST_ENABLED) || (defined NW_EXTERNAL_MOST_ENABLED))
        if( NW_VMF_ROUTING_DB_EVENT_IS_NODE_ADDRESS_ANOUNCEMENT(*msg) ) {
            if( basic_msg->data.length >= 2 && basic_msg->data.pl != 0x0 ) {
                u16nodeAddr = ((unsigned16)(basic_msg->data.pl[0]) << 8) + (unsigned16)(basic_msg->data.pl[1]);
                __vmf_routing_db_set_own_node_address(u16nodeAddr);
            }
        }
        #endif
        vmf_ret = ((vmf_ret_t)__vmf_routing_db_event_get_handle_list(basic_msg, response_p));
    }
	
	return vmf_ret;
}

#ifdef NW_VMF_CFG_ALLOW_SHADOW_WITH_EMPTY_FUNCTION_LIST
unsigned16
nw_vmf_routing_db_get_general_shadow_handle_list(vmf_msg_base_t* msg, vmf_handle_t** response_p)
{
    vmf_routing_db_t*  db                 = __vmf_routing_db();
    unsigned16         function_id_backup = ((vmf_most_msg_t*)msg)->func_id;
    unsigned16         result             = 0;

    if     ( msg->id.group == VMF_BROADCAST_GROUP )                                                { return 0; }
    else if( ! NW_VMF_ROUTING_DB_EVENT_IS_MOST(*msg) )                                             { return 0; }
    else if(    NW_VMF_ROUTING_DB_MOST_TX_MSG_TARGET_ADR(*((vmf_most_msg_t*)msg)) != db->most.own_node_address
            && NW_VMF_ROUTING_DB_MOST_TX_MSG_TARGET_ADR(*((vmf_most_msg_t*)msg)) != 0xFFFF )       { return 0; }
    else if( NW_VMF_ROUTING_DB_MOST_TX_MSG_OP_TYPE(*((vmf_most_msg_t*)msg)) <= 8 )                 { return 0; }

    ((vmf_most_msg_t*)msg)->func_id = 0xFFF;
    result = __vmf_routing_db_most_shadow_get_handle_list(((vmf_most_msg_t*)msg), response_p);
    ((vmf_most_msg_t*)msg)->func_id = function_id_backup;

    return result;
}
#endif /* NW_VMF_CFG_ALLOW_SHADOW_WITH_EMPTY_FUNCTION_LIST */

vmf_ret_t
nw_vmf_routing_db_event_register(vmf_handle_t Handle, unsigned8 GroupID)
{
    return __nw_vmf_routing_db_event_register(Handle, GroupID);
}

void
nw_vmf_routing_db_event_deregister(vmf_handle_t Handle, unsigned8 GroupID)
{
   __nw_vmf_routing_db_event_deregister(Handle, GroupID);
}

#if ((defined NW_VIRTUAL_MOST_ENABLED) || (defined NW_EXTERNAL_MOST_ENABLED))
vmf_ret_t
nw_vmf_routing_db_most_register(vmf_routing_db_registration_enum Type,
                                vmf_handle_t  Handle,
                                unsigned8   FBlockID,        unsigned8 InstID,
                                unsigned16* FunctionID_List, unsigned16 N)
{
    const unsigned16* FunctionID_List_End = FunctionID_List + N;
    vmf_ret_t         result   = VMF_ERROR;
    unsigned16*       iterator = 0x0;

    switch( Type ) {
        default:
            {
                return VMF_ERR_INVALID_ARG;
            }
        case NW_VMF_ROUTING_DB_REGISTRATION_EXTERNAL_MOST:
            {
                assert(FunctionID_List == 0x0);
                assert(N == 0);
                if( __vmf_routing_db()->most.external_receiver_handle != VMF_HANDLE_INVALID ) { return VMF_ERROR; }
                __vmf_routing_db()->most.external_receiver_handle = Handle;
                return VMF_OK;
            }
        case NW_VMF_ROUTING_DB_REGISTRATION_FBLOCK:
            {
                assert(FunctionID_List == 0x0);
                assert(N == 0);
                return __vmf_routing_db_most_fblock_register(Handle, FBlockID, InstID);
            }
        case NW_VMF_ROUTING_DB_REGISTRATION_SHADOW:
            {
#               ifdef NW_VMF_CFG_ALLOW_SHADOW_WITH_EMPTY_FUNCTION_LIST
                if( N == 0 )
                {
                    result = __vmf_routing_db_most_shadow_register(Handle, FBlockID, InstID, 0xFFF); /* 0xFFF indicates: ALL */
                    if( result != VMF_OK ) return result;
                }
                else
#               endif /* NW_VMF_CFG_ALLOW_SHADOW_WITH_EMPTY_FUNCTION_LIST */
                {
                    assert(FunctionID_List != 0x0);
                    assert(N != 0);
                    for(iterator = FunctionID_List; iterator != FunctionID_List_End; ++iterator) {
                        result = __vmf_routing_db_most_shadow_register(Handle, FBlockID, InstID, *iterator);
                        if( result != VMF_OK ) { return result; }
                    }
                }
                return VMF_OK;
            }
    }

}
#endif

#if ((defined NW_VIRTUAL_MOST_ENABLED) || (defined NW_EXTERNAL_MOST_ENABLED))
void
nw_vmf_routing_db_most_deregister(vmf_routing_db_registration_enum Type,
                                  vmf_handle_t                 Handle,
                                  unsigned8   FBlockID,   unsigned8  InstID,
                                  unsigned16* FunctionID_List, unsigned16 N)
{
    unsigned16* iterator = 0x0;
    unsigned16* FunctionID_List_End = FunctionID_List + N;

    switch( Type ) {
        default:
            {
                return;
            }
        case NW_VMF_ROUTING_DB_REGISTRATION_EXTERNAL_MOST:
            {
                assert(FunctionID_List == 0x0);
                assert(N == 0);
                if( __vmf_routing_db()->most.external_receiver_handle == Handle ) {
                    __vmf_routing_db()->most.external_receiver_handle = 0x0;
                } else { }
                return;
            }
        case NW_VMF_ROUTING_DB_REGISTRATION_FBLOCK:
            {
                assert(FunctionID_List == 0x0);
                assert(N == 0);
                __vmf_routing_db_most_fblock_deregister(Handle, FBlockID, InstID);
                return;
            }
        case NW_VMF_ROUTING_DB_REGISTRATION_SHADOW:
            {
                assert(FunctionID_List != 0x0);
                assert(N != 0);
                for(iterator = FunctionID_List; iterator != FunctionID_List_End; ++iterator) {
                    __vmf_routing_db_most_shadow_deregister(Handle, FBlockID, InstID, *iterator);
                }
                return;
            }
    }
}
#endif
