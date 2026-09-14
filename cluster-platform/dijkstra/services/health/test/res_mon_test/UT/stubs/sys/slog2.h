#ifndef __SLOG2_H_INCLUDED
#define __SLOG2_H_INCLUDED

#include <stdint.h>

#define SLOG2_MAX_BUFFERS    (4)

#define SLOG2_ERROR     2   /* Unexpected recoverable error. eg: needed to reset a hw controller */
#define SLOG2_INFO      5   /* Information. eg: Printing page 3 */
#define SLOG2_DEBUG2    7   /* Debug messages eg: Fine detail */

typedef int slog2_buffer_t;

typedef struct
{
    /** What we want to name the buffer */
    const char    *buffer_name;
    /** The number of 4K pages this buffer contains */
    int            num_pages;
} slog2_buffer_config_t;

/**
 * Struct containing the configuration data for a slog2 buffer set. Each
 * buffer set contains one or more buffers.  The size of each buffer is
 * specified as a multiple of 4k pages.  The maximum number of buffers
 * is specified by SLOG2_MAX_BUFFERS.
 */
typedef struct
{
    /** Number of buffers to configure */
    int                   num_buffers;
    /** Process name, or other descriptor */
    const char           *buffer_set_name;
    /** The minimum severity to log */
    uint8_t               verbosity_level;
    /** Buffer configuration for num_buffers */
    slog2_buffer_config_t buffer_config[ SLOG2_MAX_BUFFERS ];
} slog2_buffer_set_config_t;

int slog2_register( const slog2_buffer_set_config_t *__config,
                    slog2_buffer_t *__handles,
                    uint32_t __flags );
                    
int slog2f( slog2_buffer_t __buffer,
            uint16_t __code,
            uint8_t __severity,
            const char* __format, ... );

#endif /* __SLOG2_H_INCLUDED */
