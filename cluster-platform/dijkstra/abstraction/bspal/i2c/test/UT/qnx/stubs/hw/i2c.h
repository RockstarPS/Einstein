#ifndef I2C_H
#define I2C_H

#include <stdint.h>

typedef enum {
    I2C_ADDRFMT_10BIT = 0x0001,
    I2C_ADDRFMT_7BIT = 0x0002,
} i2c_addrfmt_t;

typedef struct {
    uint32_t addr; /* I2C address */
    uint32_t fmt;  /* 7- or 10-bit format */
} i2c_addr_t;

typedef struct {
    i2c_addr_t slave; /* slave address */
    uint32_t len;     /* length of receive data in bytes */
    uint32_t stop;    /* send stop when complete? (0=no, 1=yes) */
} i2c_recv_t;

#endif /* I2C_H */