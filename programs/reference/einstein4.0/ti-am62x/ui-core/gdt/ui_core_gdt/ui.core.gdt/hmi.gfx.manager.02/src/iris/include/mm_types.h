/********************************************************************/
/*          (c) 2011 Fujitsu Semiconductor Europe GmbH              */
/*                                                                  */
/* ALL RIGHTS RESERVED. No part of this publication may be copied   */
/* and provided to any third party in any form or by any means      */
/* without the written permission of Fujitsu, unless expressly      */
/* agreed to in written form by Fujitsu.                            */
/* All trademarks used in this document are the property of their   */
/* respective owners.                                               */
/*                                                                  */
/* For further provisions please refer to the respective License    */
/* Agreement.                                                       */
/* (V1.3)                                                           */
/********************************************************************/

/**
 * \author      Fujitsu Semiconductor Europe GmbH - GCC Neuried
 * \date        2011
 * \file        mm_types.h
 * \brief       Provision of platform and compiler dependent types
 *
 */

#ifndef MM_TYPES_H
#define MM_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

typedef unsigned char      MM_U08;
typedef signed char        MM_S08;
typedef unsigned short     MM_U16;
typedef signed short       MM_S16;
typedef unsigned long      MM_U32;
typedef signed long        MM_S32;
typedef unsigned long long MM_U64;
typedef signed long long   MM_S64;

typedef unsigned char      MM_CHAR;
typedef float              MM_FLOAT;

typedef double             MM_DOUBLE;
typedef long double        MM_LDOUBLE;
typedef int                MM_BOOL;

#define MM_FALSE           0
#define MM_TRUE            1
#define MM_NULL            0
#define MML_OK             MM_ERRCODE(0)
#define MML_ERR            MM_ERRCODE(0xFFFFFFFF)

/* Utilities for error handling */
#define MM_ERRCODE(err)                 ((MM_S32)(err))
#define MM_ERRCODE_MASK                 (0xFFFFU)

/** @def UNUSED(X)
    @brief A macro that suppresses compiler warnings for an unused parameter.
*/
#define UNUSED(x) ( (void)(x) )

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif  /* MM_TYPES_H */
