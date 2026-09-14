/* SPDX-License-Identifier: LGPL-2.1-or-later */
#ifndef foosdbushfoo
#define foosdbushfoo

#include <inttypes.h>
#include <stdarg.h>
#include <stdio.h>
#include <sys/types.h>

// #include "_sd-common.h"

#define _POSIX_PATH_MAX    256



typedef struct sd_bus sd_bus;

typedef struct sd_bus_slot sd_bus_slot;

typedef struct {
        const char *name;
        const char *message;
        int _need_free;
} sd_bus_error;

struct bus_body_part {
        struct bus_body_part *next;
        void *data;
        void *mmap_begin;
        size_t size;
        size_t mapped;
        size_t allocated;
        uint64_t memfd_offset;
        int memfd;
};

struct sd_bus_message {
        unsigned n_ref;     /* Counter of references that pin the connection */
        unsigned n_queued;  /* Counter of references that do not pin the connection */

        sd_bus *bus;

        uint64_t reply_cookie;

        const char *path;
        const char *interface;
        const char *member;
        const char *destination;
        const char *sender;

        sd_bus_error error;

        size_t fields_size;
        size_t body_size;
        size_t user_body_size;

        struct bus_body_part body;
        struct bus_body_part *body_end;
        unsigned n_body_parts;
};

typedef struct sd_bus_message sd_bus_message;

/* Error structures */
#define SD_BUS_ERROR_MAKE_CONST(name, message) ((const sd_bus_error) {(name), (message), 0})
#define SD_BUS_ERROR_NULL SD_BUS_ERROR_MAKE_CONST(NULL, NULL)

/* Callbacks */
typedef int (*sd_bus_message_handler_t)(sd_bus_message *m, void *userdata, sd_bus_error *ret_error);

int sd_bus_open_system(sd_bus **ret);
int sd_bus_get_fd(sd_bus *bus);
int sd_bus_flush(sd_bus *bus);
void sd_bus_close(sd_bus *bus);
sd_bus* sd_bus_unref(sd_bus *bus);
int sd_bus_process(sd_bus *bus, sd_bus_message **r);

void sd_bus_error_free(sd_bus_error *e);

sd_bus_message* sd_bus_message_unref(sd_bus_message *m);

int sd_bus_call_method(sd_bus *bus, const char *destination, const char *path, const char *interface, const char *member, sd_bus_error *ret_error, sd_bus_message **reply, const char *types, ...);

int sd_bus_message_read(sd_bus_message *m, const char *types, const char **object_path, ...);
const char* sd_bus_message_get_path(sd_bus_message *m);
int sd_bus_message_skip(sd_bus_message *m, const char *types);
int sd_bus_message_enter_container(sd_bus_message *m, char type, const char *contents);
int sd_bus_message_read_basic(sd_bus_message *m, char type, char *p);
int sd_bus_message_exit_container(sd_bus_message *m);
int sd_bus_message_peek_type(sd_bus_message *m, char *type, const char **contents);

int sd_bus_add_match(sd_bus *bus, sd_bus_slot **slot, const char *match, sd_bus_message_handler_t callback, void *userdata);

sd_bus* sd_bus_close_unref(sd_bus *bus);
sd_bus* sd_bus_flush_close_unref(sd_bus *bus);
sd_bus_slot* sd_bus_slot_unref(sd_bus_slot *slot);

/* Define helpers so that __attribute__((cleanup(sd_bus_unrefp))) and similar may be used. */
// _SD_DEFINE_POINTER_CLEANUP_FUNC(sd_bus, sd_bus_unref);
// _SD_DEFINE_POINTER_CLEANUP_FUNC(sd_bus, sd_bus_close_unref);
// _SD_DEFINE_POINTER_CLEANUP_FUNC(sd_bus, sd_bus_flush_close_unref);
// _SD_DEFINE_POINTER_CLEANUP_FUNC(sd_bus_slot, sd_bus_slot_unref);
// _SD_DEFINE_POINTER_CLEANUP_FUNC(sd_bus_message, sd_bus_message_unref);

#endif