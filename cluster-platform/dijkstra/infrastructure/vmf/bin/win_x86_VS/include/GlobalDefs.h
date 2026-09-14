/**
 ******************************************************************************
 *
 *  @file GlobalDefs.h
 *
 *  @brief Global typedefs for C4.
 *
 *  @copyright This software is Visteon property. Duplication or disclosure
 *             without Visteon written authorization is prohibited.
 *
 *  @note N/A
 *
 ******************************************************************************
*/

#ifndef GLOBAL_DEFS_H
#define GLOBAL_DEFS_H

#include "StandardDefs.h"
#include "StandardIntTypes.h"
#include "fcntl.h"
#include <stdbool.h>

/******************************************************************************
  Macro Definitions
 ******************************************************************************/

/**
 ******************************************************************************
 *
 *  @brief Ensure #NULL is defined correctly.
 *
 *  @b Example
 *  @code
 *      #include "GlobalDefs.h"
 *
 *      somePtr = NULL;
 *  @endcode
 *
 * @note For C++ this matches the system definition, even though it should be
 *       a pointer type.  Unfortunately, can not use it the right way
 *       because other system files use it as a union of pointer types, all of
 *       which are equivalent.
 *
 *  @retval #NULL  #NULL pointer value
 *
 ******************************************************************************
*/

#ifndef __cplusplus
#undef NULL
#define NULL                 (void *) 0
#endif

/******************************************************************************
  Type Definitions
 ******************************************************************************/

/******************************************************************************
  Function Prototypes
 ******************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

// Definition to satisfy MISRA.
int main(int        fp_iArgc,
         S8  *const fp_ps8Argv[]);

#ifdef __cplusplus
}
#endif

#endif
