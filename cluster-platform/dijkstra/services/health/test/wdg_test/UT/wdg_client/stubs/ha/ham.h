#ifndef _HA_HAM_H_INCLUDED
#define _HA_HAM_H_INCLUDED

struct __ham_lib_handle;
typedef struct __ham_lib_handle ham_entity_t;    /* handle to entity    */
#define HAMHBEATMIN        1000000000UL /* minimum hb interval (1000 msec)  */
ham_entity_t *ham_attach_self(__const char *__ename, uint64_t __hp, int __hpdl, int __hpdh, unsigned __flags);
int ham_detach_self(ham_entity_t *__ehdl, unsigned __flags);
int ham_heartbeat(void);

#endif
