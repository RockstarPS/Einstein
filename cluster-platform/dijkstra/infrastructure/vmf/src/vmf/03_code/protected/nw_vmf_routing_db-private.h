#ifndef __INCLUDE_GUARD_VMF_ROUTING_DB_PRIVATE_H__
#define __INCLUDE_GUARD_VMF_ROUTING_DB_PRIVATE_H__

extern vmf_routing_db_t*              __vmf_routing_db(void);
extern vmf_routing_db_event_t*        __vmf_routing_db_event_db();
extern vmf_routing_db_most_fblock_t*  __vmf_routing_db_most_fblock_db();
extern vmf_routing_db_most_shadow_t*  __vmf_routing_db_most_shadow_db();

extern void        __vmf_routing_db_set_own_node_address(unsigned16 NodeAdr);

extern void        __vmf_routing_db_event_clear();
extern vmf_ret_t   __nw_vmf_routing_db_event_register(vmf_handle_t Handle, unsigned8 EventGroupID);
extern void        __nw_vmf_routing_db_event_deregister(vmf_handle_t Handle, unsigned8 EventGroupID);
extern unsigned16  __vmf_routing_db_event_get_handle_list(vmf_basic_msg_t* msg, vmf_handle_t** response_p);
                   
extern void        __vmf_routing_db_most_fblock_clear();
extern vmf_ret_t   __vmf_routing_db_most_fblock_register(vmf_handle_t, unsigned8 FBlockID, unsigned8 InstID);
extern void        __vmf_routing_db_most_fblock_deregister(vmf_handle_t, unsigned8 FBlockID, unsigned8 InstID);
extern unsigned16  __vmf_routing_db_most_fblock_get_handle_list(vmf_most_msg_t*, vmf_handle_t** response_p);
extern unsigned16  __vmf_routing_db_most_fblock_get_handle_list_first_that_matches(unsigned8 FBlockID, vmf_handle_t** response_p);

extern void        __vmf_routing_db_most_shadow_db_clear();
extern vmf_ret_t   __vmf_routing_db_most_shadow_register(vmf_handle_t,
                                                         unsigned8  FBlockID, unsigned8 InstID, unsigned16 FunctionID);
extern void        __vmf_routing_db_most_shadow_deregister(vmf_handle_t, 
                                                           unsigned8  FBlockID, unsigned8 InstID, unsigned16 FunctionID);
extern unsigned16  __vmf_routing_db_most_shadow_get_handle_list(vmf_most_msg_t*, vmf_handle_t** response_p);


extern void  __nw_vmf_routing_db_handle_list_add(vmf_handle_list_t*, vmf_handle_t);
extern void  __nw_vmf_routing_db_handle_list_remove(vmf_handle_list_t*, vmf_handle_t);
extern void  __nw_vmf_routing_db_remove_handle(vmf_handle_t Handle);


extern vmf_routing_db_memory_pool_t* __vmf_routing_db_memory_pool(void);
extern bool                          __vmf_routing_db_memory_pool_is_full(void);

#   ifdef __NW_VMF_ROUTING_DB_OPTION_UNIT_TEST
    extern void __vmf_routing_db_print();
    extern void __vmf_routing_db_most_fblock_print();
    extern void __vmf_routing_db_most_shadow_print();
    extern void __vmf_routing_db_event_print();
    extern void __vmf_routing_db_most_tx_message_print(vmf_most_msg_t*);
    extern void __vmf_routing_db_print_handle_list(vmf_handle_list_t*); 
    extern void __vmf_routing_db_memory_pool_print();
#   endif

#endif /* __INCLUDE_GUARD_VMF_ROUTING_DB_PRIVATE_H__ */
