/* SciDrv_Udma_Cfg.h  — you fill these constants once */
#ifndef SCIDRV_UDMA_CFG_H
#define SCIDRV_UDMA_CFG_H

#include <drivers/udma/v0/soc/am62px/udma_soc.h>


#define SCIDRV_UDMA_INST_ID     (1U)


#define SCIDRV_UART_TX_THREAD   UDMA_PDMA_CH_MAIN0_UART0_TX
#define SCIDRV_UART_RX_THREAD   UDMA_PDMA_CH_MAIN0_UART0_RX

#endif
