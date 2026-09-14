#include <stdio.h>
#include "nw_vmf_routing_db.h"
#include "nw_vmf_routing_db-private.h"

void
__vmf_routing_db_print()
{
    __vmf_routing_db_most_fblock_print();

    __vmf_routing_db_most_shadow_print();

    __vmf_routing_db_event_print();

    printf("    External: %02X\n", (int)(__vmf_routing_db()->most.external_receiver_handle));
}


void
__vmf_routing_db_most_fblock_entry_print(vmf_routing_db_most_fblock_entry_t* Entry)
{  
    const unsigned8  FBlockID = Entry->subject.fblock_inst >> 8;
    const unsigned8  InstID   = Entry->subject.fblock_inst & 0xFF;

    printf("       %02X.%02X: %02X, ", (int)FBlockID, (int)InstID, (int)(Entry->observer.handle));
    /* assume that the callback prints something */
    printf("\n");
}

void
__vmf_routing_db_most_fblock_print()
{
    vmf_routing_db_most_fblock_t*        me       = &(__vmf_routing_db()->most.fblock_db);
    vmf_routing_db_most_fblock_entry_t*  iterator = 0x0;

    printf("    FBlock DB: Size = %i {", (int)(me->end - me->begin));
    if( me->end - me->begin != 0 ) printf("\n");

    for(iterator = me->begin; iterator != me->end; ++iterator) {
        __vmf_routing_db_most_fblock_entry_print(iterator);
    }
    printf("    }\n\n");
}


void
__vmf_routing_db_most_shadow_entry_print(vmf_routing_db_most_shadow_entry_t* Entry)
{  
    const unsigned32 Key        = Entry->subject.fblock_inst_function;
    const unsigned8  FBlockID   = NW_VMF_ROUTING_DB_SHADOW_DB_KEY_DECODE_FBLOCK_ID(Key);
    const unsigned8  InstID     = NW_VMF_ROUTING_DB_SHADOW_DB_KEY_DECODE_INSTANCE_ID(Key);
    const unsigned16 FunctionID = NW_VMF_ROUTING_DB_SHADOW_DB_KEY_DECODE_FUNCTION_ID(Key);

    printf("          %02X.%02X.%03X: ", (int)FBlockID, (int)InstID, (int)FunctionID);
    __vmf_routing_db_print_handle_list(&(Entry->observer.handle_list));
    /* assume that the callback prints something */
    printf("\n");
}

void
__vmf_routing_db_most_shadow_print()
{
    vmf_routing_db_most_shadow_t*        me = &(__vmf_routing_db()->most.shadow_db);
    vmf_routing_db_most_shadow_entry_t*  iterator = 0x0;

    printf("    Shadow DB: Size = %i {", (int)(me->end - me->begin));
    if( me->end - me->begin != 0 ) printf("\n");

    for(iterator = me->begin; iterator != me->end; ++iterator) {
        __vmf_routing_db_most_shadow_entry_print(iterator);
    }
    printf("    }\n\n");
}


void
__vmf_routing_db_most_tx_message_print(vmf_most_msg_t* Msg)
{
    printf("[%03X] %02X.%02X.%03X.%1X",
           (int)NW_VMF_ROUTING_DB_MOST_TX_MSG_TARGET_ADR(*Msg), 
           (int)NW_VMF_ROUTING_DB_MOST_TX_MSG_FBLOCK_ID(*Msg), 
           (int)NW_VMF_ROUTING_DB_MOST_TX_MSG_INSTANCE_ID(*Msg), 
           (int)NW_VMF_ROUTING_DB_MOST_TX_MSG_FUNCTION_ID(*Msg), 
           (int)NW_VMF_ROUTING_DB_MOST_TX_MSG_OP_TYPE(*Msg));

}

#if false
void
__nw_print_bitfield(unsigned64 BitField)
{
    unsigned16  i        = 0;
    unsigned64  walker   = 1;
    printf("[");
    for(i = 1; i <= 64; ++i, walker <<=1 ) {
        printf(BitField & walker ? "1" : "_"); 
        if     ( i == 64 )    break;
        else if( i % 8 == 0 ) printf(":");
        else if( i % 4 == 0 ) printf(".");
    }
    printf("]");
}
#endif
void
__vmf_routing_db_print_handle_list(vmf_handle_list_t* List)
{
    vmf_handle_t* iterator = 0x0;

    for(iterator = List->begin; iterator != List->begin + List->length; ++iterator) { 
        printf("%02X, ", ((int)*iterator));
    }

}

void
__vmf_routing_db_event_entry_print(vmf_routing_db_event_entry_t* Entry)
{  
    const unsigned8  EventGroupID = Entry->subject.event_group_id;

    printf("       %02X: ", (int)EventGroupID);
    __vmf_routing_db_print_handle_list(&(Entry->observer.handle_list));
    /* assume that the callback prints something */
    printf("\n");
}

void
__vmf_routing_db_event_print()
{
    vmf_routing_db_event_t*        me       = &(__vmf_routing_db()->event.db);
    vmf_routing_db_event_entry_t*  iterator = 0x0;

    printf("    Event DB: Size = %i {", (int)(me->end - me->begin));
    if( me->end - me->begin != 0 ) printf("\n");

    for(iterator = me->begin; iterator != me->end; ++iterator) {
        __vmf_routing_db_event_entry_print(iterator);
    }
    printf("    }\n\n");
}

void
__vmf_routing_db_memory_pool_print(void)
{
    vmf_handle_t* iterator = 0x0;
    signed16                 i = 0;

    printf("    Memory Pool: Size = %i/%i {\n        ", 
           (int)(__vmf_routing_db_memory_pool()->end        - __vmf_routing_db_memory_pool()->begin),
           (int)(__vmf_routing_db_memory_pool()->memory_end - __vmf_routing_db_memory_pool()->begin));
    for(iterator = __vmf_routing_db_memory_pool()->begin;
        iterator != __vmf_routing_db_memory_pool()->end;
        ++iterator) { 

        printf("%02X.", (int)(*iterator));
        if( ++i % 16 == 0 ) printf("\n        ");
        else if( i % 8 == 0 ) printf(" ");
    }
    printf("\n    }\n");

}
