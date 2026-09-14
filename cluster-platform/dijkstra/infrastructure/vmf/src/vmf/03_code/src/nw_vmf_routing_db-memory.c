#include "nw_os_config.h"
#include "nw_vmf_routing_db-types.h"
#include "nw_vmf_routing_db-private.h"

static void __vmf_routing_db_memory_pool_decrement_pointers_after_this(vmf_handle_t*);
static void __vmf_routing_db_memory_pool_increment_pointers_after_this(vmf_handle_t*);

vmf_routing_db_memory_pool_t*
__vmf_routing_db_memory_pool()
{
    static bool                         virginity_f = true;
    static vmf_routing_db_memory_pool_t the_pool;
#if (!defined(NDEBUG) && !defined(PRODUCTION))
    vmf_handle_t* iterator = 0x0;
#endif

    if( virginity_f ) { 
        virginity_f = false;
        the_pool.end        = the_pool.begin;
        the_pool.memory_end = the_pool.begin + NW_VMF_ROUTING_DB_MEMORY_POOL_ELEMENT_N;
#if (!defined(NDEBUG) && !defined(PRODUCTION))
        for(iterator = the_pool.begin; iterator != the_pool.memory_end; ++iterator) {
            *iterator = 0x00;
        }
#endif
    }

    return &the_pool;
}

void
__nw_vmf_routing_db_remove_handle(vmf_handle_t Handle)
{
    vmf_routing_db_t*              db = __vmf_routing_db();
    /* pointers to the data bases */
    vmf_routing_db_most_fblock_t*        most_fblock_db = &(db->most.fblock_db);
    vmf_routing_db_most_shadow_t*        most_shadow_db = &(db->most.shadow_db);
    vmf_routing_db_event_t*              event_db       = &(db->event.db);
    /**/
    vmf_routing_db_most_fblock_entry_t*  fit = most_fblock_db->begin; 
    vmf_routing_db_most_shadow_entry_t*  sit = most_shadow_db->begin; 
    vmf_routing_db_event_entry_t*        eit = event_db->begin; 


    /* FBlock Database */
    if( most_fblock_db->begin < most_fblock_db->end ) {
        /* If-statement: Prevent totoal chaos, in case that the pointers have been corrupted. */
        while( fit < most_fblock_db->end ) { 
            if( fit->observer.handle != Handle ) { ++fit; continue; }

            /* shift content forwards */
            if( fit < (most_fblock_db->end - 1) ) { 
                memmove(fit, fit + 1, (most_fblock_db->end - 1 - fit) * sizeof(vmf_routing_db_most_fblock_entry_t));
            } 
            --(most_fblock_db->end);
        }
    }

    /* Shadow Database */
    if( most_shadow_db->begin < most_shadow_db->end ) {
        /* If-statement: Prevent totoal chaos, in case that the pointers have been corrupted. */
        while( sit < most_shadow_db->end ) { 
            /* delete handle from list */
            __nw_vmf_routing_db_handle_list_remove(&(sit->observer.handle_list), Handle);

            /* if handle list does not contain any handle anymore, then delete the whole entry */
            if( sit->observer.handle_list.length != 0 ) { ++sit; continue; }

            /* shift content forwards */
            if( sit < most_shadow_db->end - 1 ) { 
                memmove(sit, sit + 1, (most_shadow_db->end - 1 - sit) * sizeof(vmf_routing_db_most_shadow_entry_t));
            } 

            --(most_shadow_db->end);
        }
    }

    /* Event Database */
    if( event_db->begin < event_db->end ) {
        /* If-statement: Prevent totoal chaos, in case that the pointers have been corrupted. */
        while( eit < event_db->end ) { 
            /* delete handle from list */
            __nw_vmf_routing_db_handle_list_remove(&(eit->observer.handle_list), Handle);

            /* if handle list does not contain any handle anymore, then delete the whole entry */
            if( eit->observer.handle_list.length != 0 ) { ++eit; continue; }

            /* shift content forwards */
            if( eit < event_db->end - 1 ) { 
                memmove(eit, eit + 1, (event_db->end - 1 - eit) * sizeof(vmf_routing_db_event_entry_t));
            } 

            --(event_db->end);
        }
    }
}

bool
__vmf_routing_db_memory_pool_is_full(void)
{ return __vmf_routing_db_memory_pool()->end == __vmf_routing_db_memory_pool()->memory_end; }

void
__nw_vmf_routing_db_handle_list_add(vmf_handle_list_t* me, 
                                    vmf_handle_t       my_value)
{
    const vmf_handle_t*     HandleList_Begin = me->begin;
    const vmf_handle_t*     HandleList_End   = me->begin + me->length;
    const vmf_handle_t*     iterator         = 0x0;
    vmf_routing_db_memory_pool_t* pool = __vmf_routing_db_memory_pool();
    const vmf_handle_t*     MemoryPoolEnd = pool->end;
    vmf_handle_t*           insertion_at  = 0x0;

    assert(me->begin >= pool->begin);
    /* ALLOW: me->begin == memory_pool->end, to insert new elements */
    assert(me->begin              <= pool->end);
    assert(me->begin + me->length <= MemoryPoolEnd);
    assert(MemoryPoolEnd          <= pool->memory_end);

    if( __vmf_routing_db_memory_pool_is_full() ) { return; }
    else                                         { }

    /* is handle already in list? if so, then do not register it again */
    for(iterator = HandleList_Begin; iterator != HandleList_End; ++iterator) { 
        if( *iterator == my_value ) { return; } 
        else                     { }
    } 

    insertion_at = me->begin + me->length;
    if( insertion_at != MemoryPoolEnd ) { 
        /* anything about the list has to be moved and the references have to be adjusted */
        __vmf_routing_db_memory_pool_increment_pointers_after_this(me->begin);
        /* move the memory starting from here */
        memmove(insertion_at + 1, insertion_at, 
                (MemoryPoolEnd - insertion_at) * sizeof(vmf_handle_t));
    } else { }
    *insertion_at = my_value;
    ++(pool->end);
    ++(me->length);

    assert(me->begin              >= pool->begin);
    assert(me->begin + me->length <= pool->memory_end);
    assert(MemoryPoolEnd          <= pool->memory_end);
}

void
__nw_vmf_routing_db_handle_list_remove(vmf_handle_list_t* me, 
                                       vmf_handle_t       my_value)
{
    vmf_routing_db_memory_pool_t* pool = __vmf_routing_db_memory_pool();
    const vmf_handle_t*     MemoryPoolEnd = pool->end;
    const vmf_handle_t*     End           = me->begin + me->length;
    vmf_handle_t*           iterator      = 0x0;

    assert(me->begin              >= pool->begin);
    assert(me->begin + me->length <= MemoryPoolEnd);
    assert(MemoryPoolEnd          <= pool->memory_end);

    /* Find my_value in the list: NOTE: The handle list is not sorted, so no search algo
     * can be applied.  */
    for(iterator = me->begin; iterator != End; ++iterator) { 
        if( *iterator == my_value ) break; 
    }

    if( iterator == End ) { 
        /* my_value is not in the list */
        return;
    }
    else if( iterator != MemoryPoolEnd - 1 ) { 
        /* anything about the list has to be moved and the references have to be adjusted */
        __vmf_routing_db_memory_pool_decrement_pointers_after_this(me->begin);
        /* move the memory starting from here */
        memmove(iterator, iterator + 1, 
                (MemoryPoolEnd - iterator - 1)*sizeof(vmf_handle_t));
    } else { 
        /* nothing has to be moved, because the current list was at the end of the pool */
    }
    --(pool->end);
    --(me->length);

    assert(me->begin              >= pool->begin);
    assert(me->begin + me->length <= MemoryPoolEnd);
    assert(MemoryPoolEnd          <= pool->memory_end);
}

void
__vmf_routing_db_memory_pool_increment_pointers_after_this(vmf_handle_t* Position)
{
    vmf_routing_db_t*              db = __vmf_routing_db();
    /* pointers to the data bases */
    vmf_routing_db_most_shadow_t*  most_shadow_db = &(db->most.shadow_db);
    vmf_routing_db_event_t*        event_db       = &(db->event.db);
    /* iterators */
    vmf_routing_db_most_shadow_entry_t* sit = most_shadow_db->begin; 
    vmf_routing_db_event_entry_t*       eit = event_db->begin; 

    for(; sit != most_shadow_db->end; ++sit) { 
        if( (*sit).observer.handle_list.begin > Position ) { ++((*sit).observer.handle_list.begin); } 
        else { }
    }

    for(; eit != event_db->end; ++eit) { 
        if( (*eit).observer.handle_list.begin > Position ) { ++((*eit).observer.handle_list.begin); } 
        else { }
    }
}

void
__vmf_routing_db_memory_pool_decrement_pointers_after_this(vmf_handle_t* Position)
{
    vmf_routing_db_t*              db = __vmf_routing_db();
    /* pointers to the data bases */
    vmf_routing_db_most_shadow_t*  most_shadow_db = &(db->most.shadow_db);
    vmf_routing_db_event_t*        event_db       = &(db->event.db);
    /* iterators */
    vmf_routing_db_most_shadow_entry_t* sit = most_shadow_db->begin; 
    vmf_routing_db_event_entry_t*       eit = event_db->begin; 

    for(; sit != most_shadow_db->end; ++sit) { 
        if( (*sit).observer.handle_list.begin > Position ) { --((*sit).observer.handle_list.begin); } 
        else { }
    }

    for(; eit != event_db->end; ++eit) { 
        if( (*eit).observer.handle_list.begin > Position ) { --((*eit).observer.handle_list.begin); } 
        else { }
    }
}
