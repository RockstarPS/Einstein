#ifndef __INCLUDE_GUARD_VMF_ROUTING_DB_PRIVATE_H__
#define __INCLUDE_GUARD_VMF_ROUTING_DB_PRIVATE_H__

extern vmf_routing_db_t*              __vmf_routing_db(void);
extern vmf_routing_db_event_t*        __vmf_routing_db_event_db(void);


extern void        __vmf_routing_db_event_clear(void);
extern vmf_ret_t   __nw_vmf_routing_db_event_register(vmf_handle_t Handle, unsigned8 GroupID);
extern void        __nw_vmf_routing_db_event_deregister(vmf_handle_t Handle, unsigned8 GroupID);
extern unsigned16  __vmf_routing_db_event_get_handle_list(vmf_msg_t*, vmf_handle_t** response_p);


extern void  __nw_vmf_routing_db_handle_list_add(vmf_handle_list_t*, vmf_handle_t);
extern void  __nw_vmf_routing_db_handle_list_remove(vmf_handle_list_t*, vmf_handle_t);
extern void  __nw_vmf_routing_db_remove_handle(vmf_handle_t Handle);


extern vmf_routing_db_memory_pool_t* __vmf_routing_db_memory_pool(void);
extern bool                          __vmf_routing_db_memory_pool_is_full(void);

//static void __vmf_routing_db_event_print(void);

#endif /* __INCLUDE_GUARD_VMF_ROUTING_DB_PRIVATE_H__ */
