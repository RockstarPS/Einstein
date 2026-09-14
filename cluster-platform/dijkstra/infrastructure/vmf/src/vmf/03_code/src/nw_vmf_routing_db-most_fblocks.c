#include "nw_vmf_routing_db.h"

#define NW_ROUTING_DB_CLEAR \
        __vmf_routing_db_most_fblock_clear
#define NW_ROUTING_DB_REGISTER \
        __vmf_routing_db_most_fblock_register(vmf_handle_t Handle, unsigned8 FBlockID, unsigned8 InstanceID)   
#define NW_ROUTING_DB_DEREGISTER \
        __vmf_routing_db_most_fblock_deregister(vmf_handle_t Handle, unsigned8 FBlockID, unsigned8 InstanceID)
#define NW_ROUTING_DB_GET_HANDLES \
        __vmf_routing_db_most_fblock_get_handle_list_core(vmf_most_msg_t* msg, vmf_handle_t** response_p)
#define NW_ROUTING_DB_FIND_ENTRY \
        __nw_routing_db_most_fblock_find

#define NW_ROUTING_DB_THIS         &(__vmf_routing_db()->most.fblock_db)
#define NW_ROUTING_DB_TYPE         vmf_routing_db_most_fblock_t
#define NW_ROUTING_DB_ENTRY_TYPE   vmf_routing_db_most_fblock_entry_t
#define NW_ROUTING_DB_KEY_TYPE     unsigned16
#define NW_ROUTING_DB_KEY(Entry)   ((Entry)->subject.fblock_inst)

#define NW_VMF_ROUTING_MAP_VMF_MESSAGE_TO_KEY(Msg) (  (NW_VMF_ROUTING_DB_MOST_TX_MSG_FBLOCK_ID(Msg) << 8) \
                                                    | NW_VMF_ROUTING_DB_MOST_TX_MSG_INSTANCE_ID(Msg)    )
#define NW_ROUTING_DB_MAP_ARGUMENTS_TO_KEY         ( ( ((unsigned16)FBlockID) << 8 ) | ((unsigned16)InstanceID))
#define NW_ROUTING_DB_MAX_ENTRY_N                  (NW_VMF_ROUTING_DB_MOST_FBLOCK_MAX_ELEMENT_N)

#define NW_ROUTING_DB_SINGLE_HANDLE_ENTRY
#include "nw_vmf_routing_db-template.cg"

static vmf_handle_t __vmf_routing_db_temporary_response_array[NW_VMF_ROUTING_DB_TEMPORARY_RESPONSE_ARRAY_SIZE];

static unsigned16 
__vmf_routing_db_most_fblock_get_handle_list_all_that_match(unsigned8 FBlockID, vmf_handle_t** response_p);

unsigned16
__vmf_routing_db_most_fblock_get_handle_list(vmf_most_msg_t* msg, vmf_handle_t** response_p)
{
    /* NOTE: This function is NOT re-entrant and NOT thread-safe. The caller of this function
     *       needs to work with the data before it calls this function again. */
    unsigned8  instance_id = 0x00;
    unsigned8  fblock_id   = 0x00;
    unsigned16 size        = 0xFFFF;

    if( msg == 0x0 ) { return 0; }

    instance_id = NW_VMF_ROUTING_DB_MOST_TX_MSG_INSTANCE_ID(*msg);
    fblock_id   = NW_VMF_ROUTING_DB_MOST_TX_MSG_FBLOCK_ID(*msg);

    switch( instance_id ) { 
        case 0x00: /* first matching fblock--the so called "don't care" */
            size = __vmf_routing_db_most_fblock_get_handle_list_first_that_matches(fblock_id, response_p);
            break;
        case 0xFF: /* all matching function blocks */
            size = __vmf_routing_db_most_fblock_get_handle_list_all_that_match(fblock_id, response_p);
            break;
        default:
            size = __vmf_routing_db_most_fblock_get_handle_list_core(msg, response_p);
            break;
    }
    return size;
}

unsigned16 
__vmf_routing_db_most_fblock_get_handle_list_first_that_matches(unsigned8 FBlockID, vmf_handle_t** response_p)
{
    /* NOTE: This function is NOT re-entrant and NOT thread-safe. The caller of this function
     *       needs to work with the data before it calls this function again. */
    /* Find function block with the lowest instance id that has the given FBlockID
     *
     * NOTE: The entries in the database are sorted and the find function automatically
     *       returns the address before the first matching entry. We only have to check
     *       wether the entry matches and then iterate until there comes a different
     *       instance id.
     */
    unsigned16                          FBlockID_InstanceID = FBlockID << 8; /* instance id = 0x00 */
    unsigned16                          initial_fblock_inst = 0x0000;
    vmf_routing_db_most_fblock_entry_t* iterator = __nw_routing_db_most_fblock_find(FBlockID_InstanceID); 
    vmf_routing_db_most_fblock_entry_t* End      = __vmf_routing_db()->most.fblock_db.end;
    vmf_handle_t*                       write_iterator = __vmf_routing_db_temporary_response_array;
    vmf_handle_t*                       write_End =   __vmf_routing_db_temporary_response_array
                                                    + NW_VMF_ROUTING_DB_TEMPORARY_RESPONSE_ARRAY_SIZE;

    /* NOTE: The following loop catches the case, that there is no entry with a 
     *       matching fblock id.
     *
     * Add handles until you reach an entry with a different instance id */
    if( ((iterator->subject.fblock_inst) >> 8) != FBlockID ) { return 0; }

    initial_fblock_inst = iterator->subject.fblock_inst;
    for(;    iterator != End 
          && iterator->subject.fblock_inst == initial_fblock_inst
          && write_iterator != write_End; 
          ++iterator) { 
        *(write_iterator++) = iterator->observer.handle;
    }
    *response_p = __vmf_routing_db_temporary_response_array;
    return write_iterator - __vmf_routing_db_temporary_response_array;
}

static unsigned16 
__vmf_routing_db_most_fblock_get_handle_list_all_that_match(unsigned8 FBlockID, vmf_handle_t** response_p)
{
    /* NOTE: This function is NOT re-entrant and NOT thread-safe. The caller of this function
     *       needs to work with the data before it calls this function again. */
    /* NOTE: The entries in the database are sorted and the find function automatically
     *       returns the address before the first matching entry. We only have to check
     *       wether the entry matches and then iterate until there comes a different
     *       instance id.
     */
    unsigned16                          FBlockID_InstanceID = FBlockID << 8; /* instance id = 0x00 */
    vmf_routing_db_most_fblock_entry_t* iterator = __nw_routing_db_most_fblock_find(FBlockID_InstanceID); 
    vmf_routing_db_most_fblock_entry_t* End      = __vmf_routing_db()->most.fblock_db.end;
    vmf_handle_t*                       write_iterator = __vmf_routing_db_temporary_response_array;
    vmf_handle_t*                       write_End =   __vmf_routing_db_temporary_response_array
                                                    + NW_VMF_ROUTING_DB_TEMPORARY_RESPONSE_ARRAY_SIZE;

    /* NOTE: The following loop catches the case, that there is no entry with a 
     *       matching fblock id.
     *
     * Add handles until you reach an entry with a different instance id */
    for(;    iterator != End 
          && (((iterator->subject.fblock_inst) >> 8) == FBlockID)
          && write_iterator != write_End; 
             ++iterator) { 
        *(write_iterator++) = iterator->observer.handle;
    }
    *response_p = __vmf_routing_db_temporary_response_array;
    return write_iterator - __vmf_routing_db_temporary_response_array;
}

