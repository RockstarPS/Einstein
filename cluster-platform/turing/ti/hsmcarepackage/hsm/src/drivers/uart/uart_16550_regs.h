/*
 * System Firmware UART 16550 driver registers
 *
 * Copyright (C) 2017-2020 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#ifndef UART_16550_REGS_H
#define UART_16550_REGS_H

#define UART_16550_THR                  0x00
#define UART_16550_LSR                  0x14

/* Line Status Register bits */
#define UART_16550_LSR_TX_FIFO_E        (1 << 5)        /* TX FIFO empty */



#endif /* UART_16550_REGS_H */
