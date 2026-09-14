
#ifndef STD_TYPES_H
#define STD_TYPES_H
#include <stdint.h>
#include <Platform_Types.h>
#include "vHsmMemMap.h"




#ifndef LOCAL
#define LOCAL static 
#endif


#define E_OK    (0x00u)
#define E_NOT_OK    (0x01U)

/* [SWS_Std_00007] */
/* Physical state 5V or 3.3V */
#define STD_HIGH    (0x01U)
/* Physical state 0V */
#define STD_LOW     (0x00U)

#define EMPTY_BLOB  (0x05)

#define E_KEY_NOT_AVAILABLE (5)
/* [SWS_Std_00013] */
/* Logical state active */
#define STD_ACTIVE  (0x01U)
/* Logical state idle */
#define STD_IDLE    (0x00U)

/* [SWS_Std_00010] */
#define STD_ON  (0x01U)
#define STD_OFF (0x00U)

#define FUNC(rettype, memclass) memclass rettype 
#ifndef NULL_PTR
#define NULL_PTR ((void *)0)
#endif
#  ifndef false
#   define false                       (0U)
#  endif
#  ifndef true
#   define true                       (1U)
#  endif
#ifndef NULL
# ifdef __cplusplus
    #define NULL         (0)
# else
    #define NULL         ((void *)0)
# endif
#endif
#endif /*STD_TYPES_H*/
