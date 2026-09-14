#ifndef __TARGET_NTO_H_INCLUDED
#define __TARGET_NTO_H_INCLUDED

#ifndef __PLATFORM_H_INCLUDED
#error sys/target_nto.h should not be included directly.
#endif

#undef __OFF64_T
#define __OFF64_T		_Int64t
#endif //__TARGET_NTO_H_INCLUDED