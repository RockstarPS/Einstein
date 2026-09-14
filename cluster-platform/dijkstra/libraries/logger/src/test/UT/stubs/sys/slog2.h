#ifndef __SLOG2_H_INCLUDED
#define __SLOG2_H_INCLUDED

#include <stdint.h>

#define SLOG2_MAX_BUFFERS    (4)

typedef struct
{
    /** What we want to name the buffer */
    const char    *buffer_name;
    /** The number of 4K pages this buffer contains */
    int            num_pages;
} slog2_buffer_config_t;

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
    /** Maximum number of retries to acquire read/write indexes when writing */
    uint32_t              max_retries;
} slog2_buffer_set_config_t;

typedef struct {
}slog2_buffer_meta;

typedef slog2_buffer_meta *slog2_buffer_t;

#define __progname "logger_test"

int slog2_register( const slog2_buffer_set_config_t *__config,
                    slog2_buffer_t *__handles,
                    uint32_t __flags );
                    
#define SLOG2_DEBUG2    7   /* Debug messages eg: Fine detail */
#define SLOG2_CRITICAL  1   /* Unexpected unrecoverable error. eg: hard disk error */
#define SLOG2_ERROR     2   /* Unexpected recoverable error. eg: needed to reset a hw controller */
#define SLOG2_WARNING   3   /* Expected error. eg: parity error on a serial port */
#define SLOG2_INFO      5   /* Information. eg: Printing page 3 */
#define SLOG2_DEBUG1    6   /* Debug messages eg: Normal detail */

int slog2_set_verbosity( slog2_buffer_t __buffer,
                         uint8_t __verbosity );
                         
int slog2_reset( void );

int slog2c( slog2_buffer_t __buffer,
            uint16_t __code,
            uint8_t __severity,
            const char* __data );
            
int gettid( void );

#endif /* __SLOG2_H_INCLUDED */
