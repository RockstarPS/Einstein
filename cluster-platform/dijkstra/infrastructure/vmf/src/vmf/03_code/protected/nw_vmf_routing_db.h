/* Author: Frank-Rene Schaefer
 * DATE:   Feb. 2008
 * (C) 2008 Visteon Deutschland GmbH, Kerpen
 */
#ifndef __INCLUDE_GAURD_NW_VMF_ROUTING_DB_H__ 
#define __INCLUDE_GAURD_NW_VMF_ROUTING_DB_H__ 

#include "nw_vmf_routing_db-definitions.h"
#include "nw_vmf_routing_db-types.h"
#include "nw_vmf_types.h"

extern void          nw_vmf_routing_db_clear(void);
extern vmf_ret_t     nw_vmf_routing_db_event_register(vmf_handle_t Handle, unsigned8 GroupID);
extern void          nw_vmf_routing_db_event_deregister(vmf_handle_t Handle, unsigned8 GroupID);
#if ((defined NW_VIRTUAL_MOST_ENABLED) || (defined NW_EXTERNAL_MOST_ENABLED))
extern vmf_ret_t     nw_vmf_routing_db_most_register(vmf_routing_db_registration_enum, vmf_handle_t, 
                                                     unsigned8 FBlockID, unsigned8 InstID, 
                                                     unsigned16* FunkIDList, unsigned16 N);
extern void          nw_vmf_routing_db_most_deregister(vmf_routing_db_registration_enum, vmf_handle_t,
                                                       unsigned8 FBlockID, unsigned8 InstID, 
                                                       unsigned16* FunkIDList, unsigned16 N);
#endif
extern vmf_ret_t     nw_vmf_routing_db_get_handle_list(vmf_msg_base_t* msg, vmf_handle_t** response_p);

#ifdef NW_VMF_CFG_ALLOW_SHADOW_WITH_EMPTY_FUNCTION_LIST
extern unsigned16    nw_vmf_routing_db_get_general_shadow_handle_list(vmf_msg_base_t* msg, vmf_handle_t** response_p);
#endif /* NW_VMF_CFG_ALLOW_SHADOW_WITH_EMPTY_FUNCTION_LIST */

#endif /* __INCLUDE_GAURD_NW_VMF_ROUTING_DB_H__ */
