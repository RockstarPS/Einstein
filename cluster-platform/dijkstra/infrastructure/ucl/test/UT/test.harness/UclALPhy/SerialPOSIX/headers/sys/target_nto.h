#ifndef __TARGET_NTO_H_INCLUDED
#define __TARGET_NTO_H_INCLUDED

#ifndef __PLATFORM_H_INCLUDED
#error sys/target_nto.h should not be included directly.
#endif

#undef __TIMER_T
#define __TIMER_T		int

#undef __CLOCKID_T
#define __CLOCKID_T		int

#endif