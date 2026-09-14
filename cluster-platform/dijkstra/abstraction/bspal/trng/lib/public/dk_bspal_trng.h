/*============================================================================
 **
 ** Copyright 2019 Visteon Corporation.
 **
 ** These materials and the intellectual property rights associated therewith
 ** (“Materials”) are proprietary to Visteon Corporation. Any and all rights in
 ** the Materials are reserved by Visteon Corporation. Nothing contained in
 ** these Materials shall grant or be deemed to grant to you or anyone else, by
 ** implication, estoppel or otherwise, any rights in these Materials.
 **
 **==========================================================================*/

#include "trng_devctl.h"
#include <fcntl.h>
#include <stdint.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

/**
******************************************************************************
** \fn uint8_t TRNG_Read(int filedes, uint8_t* trngbuf, size_t nbytes)
**
** Reads the Randon number from TRNG resource Manager
**
** \param [in] filedes
** The file descriptor of the TRNG resource Manager
**
** \param [out] trngbuf
** Output buffer where the Random number will be stored
**
** \param [in] nbytes
** number of required bytes of random number
**
** \return uint8_t
** This function returns:
** - E_OK(0) on success
** - error code on failure
*****************************************************************************/
uint8_t TRNG_Read(int filedes, uint8_t* trngbuf, size_t nbytes);

/**
******************************************************************************
** \fn int32_t TRNG_Open()
**
** Opens TRNG resource Manager for random number operation
**
** \return int32_t
** This function returns:
** - E_OK(0) on success
** - error code on failure
*****************************************************************************/
int32_t TRNG_Open();

/**
******************************************************************************
** \fn int32_t TRNG_Close(int32_t trng_fd)
**
** Closes TRNG resource Manager for random number operation
**
** \param [in] trng_fd
** File descriptor for the TRNG resource Manager
**
** \return int32_t
** This function returns:
** - E_OK(0) on success
** - error code on failure
*****************************************************************************/
int32_t TRNG_Close(int32_t trng_fd);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

