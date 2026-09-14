
#ifndef _OS_TYPES_H_
#define _OS_TYPES_H_

/* general typedefs */
typedef unsigned long long  unsigned64;
typedef long                signed32;
typedef unsigned long       unsigned32;
typedef int                 signed16;
typedef unsigned int        unsigned16;
typedef signed char         signed8;
typedef unsigned char       unsigned8;
typedef short               bool;



/* qnx typedefs */
typedef signed32            mqd_t;


/* general definitions */
#ifndef true
#define true    ( 1 )
#endif

#ifndef false
#define false   ( 0 )
#endif

/* jmerkle  #define NULL    0 */
#define EOK         1
#define NOT_EOK     2

/* qnx definitions */


#endif

