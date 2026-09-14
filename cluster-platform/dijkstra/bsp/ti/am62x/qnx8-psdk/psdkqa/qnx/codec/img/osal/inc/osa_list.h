/*****************************************************************************
*
* Copyright (c) Imagination Technologies Ltd.
* Copyright (c) 2018-22 Texas Instruments Incorporated - http://www.ti.com/
*
* The contents of this file are subject to the MIT license as set out below.
*
* Permission is hereby granted, free of charge, to any person obtaining a
* copy of this software and associated documentation files (the "Software"),
* to deal in the Software without restriction, including without limitation
* the rights to use, copy, modify, merge, publish, distribute, sublicense,
* and/or sell copies of the Software, and to permit persons to whom the
* Software is furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHERa
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*
* Alternatively, the contents of this file may be used under the terms of the
* GNU General Public License Version 2 ("GPL")in which case the provisions of
* GPL are applicable instead of those above.
*
* If you wish to allow use of your version of this file only under the terms
* of GPL, and not to allow others to use your version of this file under the
* terms of the MIT license, indicate your decision by deleting the provisions
* above and replace them with the notice and other provisions required by GPL
* as set out in the file called "GPLHEADER" included in this distribution. If
* you do not delete the provisions above, a recipient may use your version of
* this file under the terms of either the MIT license or GPL.
*
* This License is also included in this distribution in the file called
* "MIT_COPYING".
*
*****************************************************************************/
/*
 * osa list definitions
 */

#ifndef OSA_LIST_H_
#define OSA_LIST_H_

#include "osa_types.h"
#include "osa_mem.h"

/*
 * Simple doubly linked list implementation.
 *
 * Some of the internal functions ("__xxx") are useful when
 * manipulating whole lists rather than single entries, as
 * sometimes we already know the next/prev entries and we can
 * generate better code by using them directly rather than
 * using the generic single-entry routines.
 */

#define OSA_LIST_HEAD_INIT(name) { &(name), &(name) }

#define OSA_LIST_HEAD(name) \
    struct clist_head name = OSA_LIST_HEAD_INIT(name)

static inline void INIT_OSA_LIST_HEAD(struct clist_head *list)
{
    list->next = list;
    list->prev = list;
}

/*
 * Insert a new entry between two known consecutive entries.
 *
 * This is only for internal list manipulation where we know
 * the prev/next entries already!
 */
static inline void __osa_list_add(struct clist_head *new,
                  struct clist_head *prev,
                  struct clist_head *next)
{
    next->prev = new;
    new->next = next;
    new->prev = prev;
    prev->next = new;
}

/**
 * osa_list_add - add a new entry
 * @new: new entry to be added
 * @head: list head to add it after
 *
 * Insert a new entry after the specified head.
 * This is good for implementing stacks.
 */
static inline void osa_list_add(struct clist_head *new, struct clist_head *head)
{
    __osa_list_add(new, head, head->next);
}


/**
 * osa_list_add_tail - add a new entry
 * @new: new entry to be added
 * @head: list head to add it before
 *
 * Insert a new entry before the specified head.
 * This is useful for implementing queues.
 */
static inline void osa_list_add_tail(struct clist_head *new, struct clist_head *head)
{
    __osa_list_add(new, head->prev, head);
}

/*
 * Delete a list entry by making the prev/next entries
 * point to each other.
 *
 * This is only for internal list manipulation where we know
 * the prev/next entries already!
 */
static inline void __osa_list_del(struct clist_head * prev, struct clist_head * next)
{
    next->prev = prev;
    prev->next = next;
}

/**
 * osa_list_del - deletes entry from list.
 * @entry: the element to delete from the list.
 * Note: osa_list_empty() on entry does not return true after this, the entry is
 * in an undefined state.
 */
static inline void __osa_list_del_entry(struct clist_head *entry)
{
    __osa_list_del(entry->prev, entry->next);
}

static inline void osa_list_del(struct clist_head *entry)
{
    __osa_list_del_entry(entry);
}

/**
 * osa_list_replace - replace old entry by new one
 * @old : the element to be replaced
 * @new : the new element to insert
 *
 * If @old was empty, it will be overwritten.
 */
static inline void osa_list_replace(struct clist_head *old,
                struct clist_head *new)
{
    new->next = old->next;
    new->next->prev = new;
    new->prev = old->prev;
    new->prev->next = new;
}

static inline void osa_list_replace_init(struct clist_head *old,
                    struct clist_head *new)
{
    osa_list_replace(old, new);
    INIT_OSA_LIST_HEAD(old);
}

/**
 * osa_list_del_init - deletes entry from list and reinitialize it.
 * @entry: the element to delete from the list.
 */
static inline void osa_list_del_init(struct clist_head *entry)
{
    __osa_list_del_entry(entry);
    INIT_OSA_LIST_HEAD(entry);
}

/**
 * osa_list_move - delete from one list and add as another's head
 * @list: the entry to move
 * @head: the head that will precede our entry
 */
static inline void osa_list_move(struct clist_head *list, struct clist_head *head)
{
    __osa_list_del_entry(list);
    osa_list_add(list, head);
}

/**
 * osa_list_move_tail - delete from one list and add as another's tail
 * @list: the entry to move
 * @head: the head that will follow our entry
 */
static inline void osa_list_move_tail(struct clist_head *list,
                  struct clist_head *head)
{
    __osa_list_del_entry(list);
    osa_list_add_tail(list, head);
}

/**
 * osa_list_is_last - tests whether @list is the last entry in list @head
 * @list: the entry to test
 * @head: the head of the list
 */
static inline int osa_list_is_last(const struct clist_head *list,
                const struct clist_head *head)
{
    return list->next == head;
}

/**
 * osa_list_empty - tests whether a list is empty
 * @head: the list to test.
 */
static inline int osa_list_empty(const struct clist_head *head)
{
    return head->next == head;
}

/**
 * osa_list_empty_careful - tests whether a list is empty and not being modified
 * @head: the list to test
 *
 * Description:
 * tests whether a list is empty _and_ checks that no other CPU might be
 * in the process of modifying either member (next or prev)
 *
 * NOTE: using osa_list_empty_careful() without synchronization
 * can only be safe if the only activity that can happen
 * to the list entry is osa_list_del_init(). Eg. it cannot be used
 * if another CPU could re-osa_list_add() it.
 */
static inline int osa_list_empty_careful(const struct clist_head *head)
{
    struct clist_head *next = head->next;
    return (next == head) && (next == head->prev);
}

/**
 * osa_list_rotate_left - rotate the list to the left
 * @head: the head of the list
 */
static inline void osa_list_rotate_left(struct clist_head *head)
{
    struct clist_head *first;

    if (!osa_list_empty(head)) {
        first = head->next;
        osa_list_move_tail(first, head);
    }
}

/**
 * osa_list_is_singular - tests whether a list has just one entry.
 * @head: the list to test.
 */
static inline int osa_list_is_singular(const struct clist_head *head)
{
    return !osa_list_empty(head) && (head->next == head->prev);
}

static inline void __osa_list_cut_position(struct clist_head *list,
        struct clist_head *head, struct clist_head *entry)
{
    struct clist_head *new_first = entry->next;
    list->next = head->next;
    list->next->prev = list;
    list->prev = entry;
    entry->next = list;
    head->next = new_first;
    new_first->prev = head;
}

/**
 * osa_list_cut_position - cut a list into two
 * @list: a new list to add all removed entries
 * @head: a list with entries
 * @entry: an entry within head, could be the head itself
 *  and if so we won't cut the list
 *
 * This helper moves the initial part of @head, up to and
 * including @entry, from @head to @list. You should
 * pass on @entry an element you know is on @head. @list
 * should be an empty list or a list you do not care about
 * losing its data.
 *
 */
static inline void osa_list_cut_position(struct clist_head *list,
        struct clist_head *head, struct clist_head *entry)
{
    if (osa_list_empty(head))
        return;
    if (osa_list_is_singular(head) &&
        (head->next != entry && head != entry))
        return;
    if (entry == head)
        INIT_OSA_LIST_HEAD(list);
    else
        __osa_list_cut_position(list, head, entry);
}

/**
 * osa_list_cut_before - cut a list into two, before given entry
 * @list: a new list to add all removed entries
 * @head: a list with entries
 * @entry: an entry within head, could be the head itself
 *
 * This helper moves the initial part of @head, up to but
 * excluding @entry, from @head to @list.  You should pass
 * in @entry an element you know is on @head.  @list should
 * be an empty list or a list you do not care about losing
 * its data.
 * If @entry == @head, all entries on @head are moved to
 * @list.
 */
static inline void osa_list_cut_before(struct clist_head *list,
                   struct clist_head *head,
                   struct clist_head *entry)
{
    if (head->next == entry) {
        INIT_OSA_LIST_HEAD(list);
        return;
    }
    list->next = head->next;
    list->next->prev = list;
    list->prev = entry->prev;
    list->prev->next = list;
    head->next = entry;
    entry->prev = head;
}

static inline void __osa_list_splice(const struct clist_head *list,
                 struct clist_head *prev,
                 struct clist_head *next)
{
    struct clist_head *first = list->next;
    struct clist_head *last = list->prev;

    first->prev = prev;
    prev->next = first;

    last->next = next;
    next->prev = last;
}

/**
 * osa_list_splice - join two lists, this is designed for stacks
 * @list: the new list to add.
 * @head: the place to add it in the first list.
 */
static inline void osa_list_splice(const struct clist_head *list,
                struct clist_head *head)
{
    if (!osa_list_empty(list))
        __osa_list_splice(list, head, head->next);
}

/**
 * osa_list_splice_tail - join two lists, each list being a queue
 * @list: the new list to add.
 * @head: the place to add it in the first list.
 */
static inline void osa_list_splice_tail(struct clist_head *list,
                struct clist_head *head)
{
    if (!osa_list_empty(list))
        __osa_list_splice(list, head->prev, head);
}

/**
 * osa_list_splice_init - join two lists and reinitialise the emptied list.
 * @list: the new list to add.
 * @head: the place to add it in the first list.
 *
 * The list at @list is reinitialised
 */
static inline void osa_list_splice_init(struct clist_head *list,
                    struct clist_head *head)
{
    if (!osa_list_empty(list)) {
        __osa_list_splice(list, head, head->next);
        INIT_OSA_LIST_HEAD(list);
    }
}

/**
 * osa_list_splice_tail_init - join two lists and reinitialise the emptied list
 * @list: the new list to add.
 * @head: the place to add it in the first list.
 *
 * Each of the lists is a queue.
 * The list at @list is reinitialised
 */
static inline void osa_list_splice_tail_init(struct clist_head *list,
                     struct clist_head *head)
{
    if (!osa_list_empty(list)) {
        __osa_list_splice(list, head->prev, head);
        INIT_OSA_LIST_HEAD(list);
    }
}

/**
 * osa_list_entry - get the struct for this entry
 * @ptr:    the &struct clist_head pointer.
 * @type:   the type of the struct this is embedded in.
 * @member: the name of the clist_head within the struct.
 */
#define osa_list_entry(ptr, type, member) \
    osa_container_of(ptr, type, member)

/**
 * osa_list_first_entry - get the first element from a list
 * @ptr:    the list head to take the element from.
 * @type:   the type of the struct this is embedded in.
 * @member: the name of the clist_head within the struct.
 *
 * Note, that list is expected to be not empty.
 */
#define osa_list_first_entry(ptr, type, member) \
    osa_list_entry((ptr)->next, type, member)

/**
 * osa_list_last_entry - get the last element from a list
 * @ptr:    the list head to take the element from.
 * @type:   the type of the struct this is embedded in.
 * @member: the name of the clist_head within the struct.
 *
 * Note, that list is expected to be not empty.
 */
#define osa_list_last_entry(ptr, type, member) \
    osa_list_entry((ptr)->prev, type, member)

/**
 * osa_list_first_entry_or_null - get the first element from a list
 * @ptr:    the list head to take the element from.
 * @type:   the type of the struct this is embedded in.
 * @member: the name of the clist_head within the struct.
 *
 * Note that if the list is empty, it returns NULL.
 */
#define osa_list_first_entry_or_null(ptr, type, member) ({ \
    struct clist_head *head__ = (ptr); \
    struct clist_head *pos__ = head__->next; \
    pos__ != head__ ? osa_list_entry(pos__, type, member) : NULL; \
})

/**
 * osa_list_next_entry - get the next element in list
 * @pos:    the type * to cursor
 * @type:   the type of the struct this is embedded in.
 * @member: the name of the clist_head within the struct.
 */
#define osa_list_next_entry(pos, type, member) \
    osa_list_entry((pos)->member.next, type, member)

/**
 * osa_list_prev_entry - get the prev element in list
 * @pos:    the type * to cursor
 * @type:   the type of the struct this is embedded in.
 * @member: the name of the clist_head within the struct.
 */
#define osa_list_prev_entry(pos, type, member) \
    osa_list_entry((pos)->member.prev, type, member)

/**
 * osa_list_for_each    -   iterate over a list
 * @pos:    the &struct clist_head to use as a loop cursor.
 * @head:   the head for your list.
 */
#define osa_list_for_each(pos, head) \
    for (pos = (head)->next; pos != (head); pos = pos->next)

/**
 * osa_list_for_each_prev   -   iterate over a list backwards
 * @pos:    the &struct clist_head to use as a loop cursor.
 * @head:   the head for your list.
 */
#define osa_list_for_each_prev(pos, head) \
    for (pos = (head)->prev; pos != (head); pos = pos->prev)

/**
 * osa_list_for_each_safe - iterate over a list safe against removal of list entry
 * @pos:    the &struct clist_head to use as a loop cursor.
 * @n:      another &struct clist_head to use as temporary storage
 * @head:   the head for your list.
 */
#define osa_list_for_each_safe(pos, n, head) \
    for (pos = (head)->next, n = pos->next; pos != (head); \
        pos = n, n = pos->next)

/**
 * osa_list_for_each_prev_safe - iterate over a list backwards safe against removal of list entry
 * @pos:    the &struct clist_head to use as a loop cursor.
 * @n:      another &struct clist_head to use as temporary storage
 * @head:   the head for your list.
 */
#define osa_list_for_each_prev_safe(pos, n, head) \
    for (pos = (head)->prev, n = pos->prev; \
         pos != (head); \
         pos = n, n = pos->prev)

/**
 * osa_list_for_each_entry  -   iterate over list of given type
 * @pos:    the type * to use as a loop cursor.
 * @head:   the head for your list.
 * @type:   the type of the struct this is embedded in.
 * @member: the name of the clist_head within the struct.
 */
#define osa_list_for_each_entry(pos, head, type, member)              \
    for (pos = osa_list_first_entry(head, type, member);    \
         &pos->member != (head);                    \
         pos = osa_list_next_entry(pos, type, member))

/**
 * osa_list_for_each_entry_reverse - iterate backwards over list of given type.
 * @pos:    the type * to use as a loop cursor.
 * @head:   the head for your list.
 * @type:   the type of the struct this is embedded in.
 * @member: the name of the clist_head within the struct.
 */
#define osa_list_for_each_entry_reverse(pos, head, type, member)          \
    for (pos = osa_list_last_entry(head, type, member);     \
         &pos->member != (head);                    \
         pos = osa_list_prev_entry(pos, type, member))

/**
 * osa_list_prepare_entry - prepare a pos entry for use in osa_list_for_each_entry_continue()
 * @pos:    the type * to use as a start point
 * @head:   the head of the list
 * @type:   the type of the struct this is embedded in.
 * @member: the name of the clist_head within the struct.
 *
 * Prepares a pos entry for use as a start point in osa_list_for_each_entry_continue().
 */
#define osa_list_prepare_entry(pos, head, type, member) \
    ((pos) ? : osa_list_entry(head, type, member))

/**
 * osa_list_for_each_entry_continue - continue iteration over list of given type
 * @pos:    the type * to use as a loop cursor.
 * @head:   the head for your list.
 * @type:   the type of the struct this is embedded in.
 * @member: the name of the clist_head within the struct.
 *
 * Continue to iterate over list of given type, continuing after
 * the current position.
 */
#define osa_list_for_each_entry_continue(pos, head, type, member)         \
    for (pos = osa_list_next_entry(pos, type, member);            \
         &pos->member != (head);                    \
         pos = osa_list_next_entry(pos, type, member))

/**
 * osa_list_for_each_entry_continue_reverse - iterate backwards from the given point
 * @pos:    the type * to use as a loop cursor.
 * @head:   the head for your list.
 * @type:   the type of the struct this is embedded in.
 * @member: the name of the clist_head within the struct.
 *
 * Start to iterate over list of given type backwards, continuing after
 * the current position.
 */
#define osa_list_for_each_entry_continue_reverse(pos, head, type, member)     \
    for (pos = osa_list_prev_entry(pos, type, member);            \
         &pos->member != (head);                    \
         pos = osa_list_prev_entry(pos, type, member))

/**
 * osa_list_for_each_entry_from - iterate over list of given type from the current point
 * @pos:    the type * to use as a loop cursor.
 * @head:   the head for your list.
 * @type:   the type of the struct this is embedded in.
 * @member: the name of the clist_head within the struct.
 *
 * Iterate over list of given type, continuing from current position.
 */
#define osa_list_for_each_entry_from(pos, head, type, member)             \
    for (; &pos->member != (head);                  \
         pos = osa_list_next_entry(pos, type, member))

/**
 * osa_list_for_each_entry_from_reverse - iterate backwards over list of given type
 *                                    from the current point
 * @pos:    the type * to use as a loop cursor.
 * @head:   the head for your list.
 * @type:   the type of the struct this is embedded in.
 * @member: the name of the clist_head within the struct.
 *
 * Iterate backwards over list of given type, continuing from current position.
 */
#define osa_list_for_each_entry_from_reverse(pos, head, type, member)     \
    for (; &pos->member != (head);                  \
         pos = osa_list_prev_entry(pos, type, member))

/**
 * osa_list_for_each_entry_safe - iterate over list of given type safe against removal of list entry
 * @pos:    the type * to use as a loop cursor.
 * @n:      another type * to use as temporary storage
 * @head:   the head for your list.
 * @type:   the type of the struct this is embedded in.
 * @member: the name of the clist_head within the struct.
 */
#define osa_list_for_each_entry_safe(pos, n, head, type, member)          \
    for (pos = osa_list_first_entry(head, type, member),    \
        n = osa_list_next_entry(pos, type, member);           \
         &pos->member != (head);                    \
         pos = n, n = osa_list_next_entry(pos, type, member))

/**
 * osa_list_for_each_entry_safe_continue - continue list iteration safe against removal
 * @pos:    the type * to use as a loop cursor.
 * @n:      another type * to use as temporary storage
 * @head:   the head for your list.
 * @type:   the type of the struct this is embedded in.
 * @member: the name of the clist_head within the struct.
 *
 * Iterate over list of given type, continuing after current point,
 * safe against removal of list entry.
 */
#define osa_list_for_each_entry_safe_continue(pos, n, head, type, member)         \
    for (pos = osa_list_next_entry(pos, type, member),                \
        n = osa_list_next_entry(pos, type, member);               \
         &pos->member != (head);                        \
         pos = n, n = osa_list_next_entry(pos, type, member))

/**
 * osa_list_for_each_entry_safe_from - iterate over list from current point safe against removal
 * @pos:    the type * to use as a loop cursor.
 * @n:      another type * to use as temporary storage
 * @head:   the head for your list.
 * @type:   the type of the struct this is embedded in.
 * @member: the name of the clist_head within the struct.
 *
 * Iterate over list of given type from current point, safe against
 * removal of list entry.
 */
#define osa_list_for_each_entry_safe_from(pos, n, head, type, member)             \
    for (n = osa_list_next_entry(pos, type, member);                  \
         &pos->member != (head);                        \
         pos = n, n = osa_list_next_entry(pos, type, member))

/**
 * osa_list_for_each_entry_safe_reverse - iterate backwards over list safe against removal
 * @pos:    the type * to use as a loop cursor.
 * @n:      another type * to use as temporary storage
 * @head:   the head for your list.
 * @type:   the type of the struct this is embedded in.
 * @member: the name of the clist_head within the struct.
 *
 * Iterate backwards over list of given type, safe against removal
 * of list entry.
 */
#define osa_list_for_each_entry_safe_reverse(pos, n, head, type, member)      \
    for (pos = osa_list_last_entry(head, type, member),     \
        n = osa_list_prev_entry(pos, type, member);           \
         &pos->member != (head);                    \
         pos = n, n = osa_list_prev_entry(pos, type, member))

/**
 * osa_list_safe_reset_next - reset a stale osa_list_for_each_entry_safe loop
 * @pos:    the loop cursor used in the osa_list_for_each_entry_safe loop
 * @n:      temporary storage used in osa_list_for_each_entry_safe
 * @type:   the type of the struct this is embedded in.
 * @member: the name of the clist_head within the struct.
 *
 * osa_list_safe_reset_next is not safe to use in general if the list may be
 * modified concurrently (eg. the lock is dropped in the loop body). An
 * exception to this is if the cursor element (pos) is pinned in the list,
 * and osa_list_safe_reset_next is called after re-taking the lock and before
 * completing the current iteration of the loop body.
 */
#define osa_list_safe_reset_next(pos, n, type, member)                \
    n = osa_list_next_entry(pos, type, member)


#endif /* OSA_LIST_H_ */
