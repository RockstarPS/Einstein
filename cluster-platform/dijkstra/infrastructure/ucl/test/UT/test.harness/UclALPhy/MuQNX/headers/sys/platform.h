#ifndef __PLATFORM_H_INCLUDED
#define __PLATFORM_H_INCLUDED

#ifndef _QNX_SOURCE //sys/io-char.h
#define _QNX_SOURCE
#endif

#if defined(__X86__) //compiler_gnu.h
#define __INT64_ALIGN __attribute__((__aligned__(8)))
#else
#define __INT64_ALIGN
#endif

typedef unsigned long long			_GCC_ATTR_ALIGN_u64t;
typedef signed long long			_GCC_ATTR_ALIGN_64t;
typedef _GCC_ATTR_ALIGN_u64t		_Uint64t __INT64_ALIGN;
typedef _GCC_ATTR_ALIGN_64t 		_Int64t __INT64_ALIGN;

#if defined(_QNX_SOURCE) || \
    (defined(__EXT) && !defined(__NO_EXT_QNX) && !defined(_POSIX_SOURCE) && !defined(_XOPEN_SOURCE) && (_POSIX_C_SOURCE+0 <= 0))
#define __EXT_QNX
#endif

#define __QNXNTO__

#ifndef _NTO_HDR_
    #ifdef _NTO_HDR_DIR_
        #define _NTO_HDR_(hdr)  <_NTO_HDR_PIECE_(_NTO_HDR_DIR_)_NTO_HDR_PIECE_(hdr)>
    #else
        #define _NTO_HDR_(hdr)  <hdr>
    #endif
#endif

#if defined(__QNXNTO__)
	#include _NTO_HDR_(sys/target_nto.h)
#elif defined(__QNX__)
	#include _NTO_HDR_(sys/target_qnx.h)
#elif defined(__SOLARIS__) || defined(__NT__) || defined(__CYGWIN__) || defined(__MINGW32__) || defined(__LINUX__) || defined(__APPLE__)
	/* partial support only, solaris/win32/linux/darwin hosted targetting qnx6 */
#else
	#error not configured for target
#endif

#ifdef __OFF64_T
typedef __OFF64_T		_Off64t;
#undef __OFF64_T
#define __OFF64_T		_Off64t
#endif

#endif //__PLATFORM_H_INCLUDED