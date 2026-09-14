/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2023. Visteon Corporation owns all rights to           *
* this work and intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right,           *
* under the copyright laws of the United States or those of any              *
* other country that may have jurisdiction, to protect this work             *
* as an unpublished work, in the event of an inadvertent or                  *
* deliberate unauthorized publication. Visteon Corporation also              *
* reserves its rights under all copyright laws to protect this               *
* work as a published work, when appropriate. Those having access            *
* to this work may not copy it, use it, modify it or disclose the            *
* information contained in it without the written authorization              *
* of Visteon Corporation.                                                    *
*                                                                            *
******************************************************************************/
/*****************************************************************************
*  File Name         :  I2c_Types.h                                          *
*  Module Short Name :  I2c_Types                                            *
*  Description       :  This file contains declations of the I2C Driver Types*
*                       and macros                                           *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  GHS Multi                                              *
* Target Hardware  :  Traveo II micro based Hardware Platform                *
*                                                                            *
******************************************************************************/
#ifndef I2C_TYPES_H
#define I2C_TYPES_H

/**
  * \brief Generic control (SCB_CTRL)
  */
typedef struct SCB_CTRL_field {
  uint32                         u4OVS:4;
  uint32                         :4;
  uint32                         u1EC_AM_MODE:1;
  uint32                         u1EC_OP_MODE:1;
  uint32                         u1EZ_MODE:1;
  uint32                         :1;
  uint32                         u1CMD_RESP_MODE:1;
  uint32                         :1;
  uint32                         u2MEM_WIDTH:2;
  uint32                         u1ADDR_ACCEPT:1;
  uint32                         u1BLOCK:1;
  uint32                         :6;
  uint32                         u2MODE:2;
  uint32                         :2;
  uint32                         u1EC_ACCESS:1;
  uint32                         :2;
  uint32                         u1ENABLED:1;
} SCB_CTRL_field_t;

typedef union SCB_CTRL {
  uint32                         u32Register;
  SCB_CTRL_field_t                 stcField;
  uint8                          au8Byte[4];
  uint16                         au16Halfword[2];
} SCB_CTRL_t;

/**
  * \brief Generic status (SCB_STATUS)
  */
typedef struct SCB_STATUS_field {
  uint32                         u1EC_BUSY:1;
  uint32                         :31;
} SCB_STATUS_field_t;

typedef union SCB_STATUS {
  uint32                         u32Register;
  SCB_STATUS_field_t               stcField;
  uint8                          au8Byte[4];
  uint16                         au16Halfword[2];
} SCB_STATUS_t;

/**
  * \brief Command/response control (SCB_CMD_RESP_CTRL)
  */
typedef struct SCB_CMD_RESP_CTRL_field {
  uint32                         u9BASE_RD_ADDR:9;
  uint32                         :7;
  uint32                         u9BASE_WR_ADDR:9;
  uint32                         :7;
} SCB_CMD_RESP_CTRL_field_t;

typedef union SCB_CMD_RESP_CTRL {
  uint32                         u32Register;
  SCB_CMD_RESP_CTRL_field_t    stcField;
  uint8                          au8Byte[4];
  uint16                         au16Halfword[2];
} SCB_CMD_RESP_CTRL_t;

/**
  * \brief Command/response status (SCB_CMD_RESP_STATUS)
  */
typedef struct SCB_CMD_RESP_STATUS_field {
  uint32                         u9CURR_RD_ADDR:9;
  uint32                         :7;
  uint32                         u9CURR_WR_ADDR:9;
  uint32                         :5;
  uint32                         u1CMD_RESP_EC_BUS_BUSY:1;
  uint32                         u1CMD_RESP_EC_BUSY:1;
} SCB_CMD_RESP_STATUS_field_t;

typedef union SCB_CMD_RESP_STATUS {
  uint32                         u32Register;
  SCB_CMD_RESP_STATUS_field_t  stcField;
  uint8                          au8Byte[4];
  uint16                         au16Halfword[2];
} SCB_CMD_RESP_STATUS_t;

/**
  * \brief SPI control (SCB_SPI_CTRL)
  */
typedef struct SCB_SPI_CTRL_field {
  uint32                         u1SSEL_CONTINUOUS:1;
  uint32                         u1SELECT_PRECEDE:1;
  uint32                         u1CPHA:1;
  uint32                         u1CPOL:1;
  uint32                         u1LATE_MISO_SAMPLE:1;
  uint32                         u1SCLK_CONTINUOUS:1;
  uint32                         :2;
  uint32                         u1SSEL_POLARITY0:1;
  uint32                         u1SSEL_POLARITY1:1;
  uint32                         u1SSEL_POLARITY2:1;
  uint32                         u1SSEL_POLARITY3:1;
  uint32                         u1SSEL_SETUP_DEL:1;
  uint32                         u1SSEL_HOLD_DEL:1;
  uint32                         u1SSEL_INTER_FRAME_DEL:1;
  uint32                         :1;
  uint32                         u1LOOPBACK:1;
  uint32                         :7;
  uint32                         u2MODE:2;
  uint32                         u2SSEL:2;
  uint32                         :3;
  uint32                         u1MASTER_MODE:1;
} SCB_SPI_CTRL_field_t;

typedef union SCB_SPI_CTRL {
  uint32                         u32Register;
  SCB_SPI_CTRL_field_t         stcField;
  uint8                          au8Byte[4];
  uint16                         au16Halfword[2];
} SCB_SPI_CTRL_t;

/**
  * \brief SPI status (SCB_SPI_STATUS)
  */
typedef struct SCB_SPI_STATUS_field {
  uint32                         u1BUS_BUSY:1;
  uint32                         u1SPI_EC_BUSY:1;
  uint32                         :6;
  uint32                         u8CURR_EZ_ADDR:8;
  uint32                         u8BASE_EZ_ADDR:8;
  uint32                         :8;
} SCB_SPI_STATUS_field_t;

typedef union SCB_SPI_STATUS {
  uint32                         u32Register;
  SCB_SPI_STATUS_field_t       stcField;
  uint8                          au8Byte[4];
  uint16                         au16Halfword[2];
} SCB_SPI_STATUS_t;

/**
  * \brief SPI transmitter control (SCB_SPI_TX_CTRL)
  */
typedef struct SCB_SPI_TX_CTRL_field {
  uint32                         :4;
  uint32                         u1PARITY:1;
  uint32                         u1PARITY_ENABLED:1;
  uint32                         :26;
} SCB_SPI_TX_CTRL_field_t;

typedef union SCB_SPI_TX_CTRL {
  uint32                         u32Register;
  SCB_SPI_TX_CTRL_field_t      stcField;
  uint8                          au8Byte[4];
  uint16                         au16Halfword[2];
} SCB_SPI_TX_CTRL_t;

/**
  * \brief SPI receiver control (SCB_SPI_RX_CTRL)
  */
typedef struct SCB_SPI_RX_CTRL_field {
  uint32                         :4;
  uint32                         u1PARITY:1;
  uint32                         u1PARITY_ENABLED:1;
  uint32                         :2;
  uint32                         u1DROP_ON_PARITY_ERROR:1;
  uint32                         :23;
} SCB_SPI_RX_CTRL_field_t;

typedef union SCB_SPI_RX_CTRL {
  uint32                         u32Register;
  SCB_SPI_RX_CTRL_field_t      stcField;
  uint8                          au8Byte[4];
  uint16                         au16Halfword[2];
} SCB_SPI_RX_CTRL_t;

/**
  * \brief UART control (SCB_UART_CTRL)
  */
typedef struct SCB_UART_CTRL_field {
  uint32                         :16;
  uint32                         u1LOOPBACK:1;
  uint32                         :7;
  uint32                         u2MODE:2;
  uint32                         :6;
} SCB_UART_CTRL_field_t;

typedef union SCB_UART_CTRL {
  uint32                         u32Register;
  SCB_UART_CTRL_field_t        stcField;
  uint8                          au8Byte[4];
  uint16                         au16Halfword[2];
} SCB_UART_CTRL_t;

/**
  * \brief UART transmitter control (SCB_UART_TX_CTRL)
  */
typedef struct SCB_UART_TX_CTRL_field {
  uint32                         u3STOP_BITS:3;
  uint32                         :1;
  uint32                         u1PARITY:1;
  uint32                         u1PARITY_ENABLED:1;
  uint32                         :2;
  uint32                         u1RETRY_ON_NACK:1;
  uint32                         :23;
} SCB_UART_TX_CTRL_field_t;

typedef union SCB_UART_TX_CTRL {
  uint32                         u32Register;
  SCB_UART_TX_CTRL_field_t     stcField;
  uint8                          au8Byte[4];
  uint16                         au16Halfword[2];
} SCB_UART_TX_CTRL_t;

/**
  * \brief UART receiver control (SCB_UART_RX_CTRL)
  */
typedef struct SCB_UART_RX_CTRL_field {
  uint32                         u3STOP_BITS:3;
  uint32                         :1;
  uint32                         u1PARITY:1;
  uint32                         u1PARITY_ENABLED:1;
  uint32                         u1POLARITY:1;
  uint32                         :1;
  uint32                         u1DROP_ON_PARITY_ERROR:1;
  uint32                         u1DROP_ON_FRAME_ERROR:1;
  uint32                         u1MP_MODE:1;
  uint32                         :1;
  uint32                         u1LIN_MODE:1;
  uint32                         u1SKIP_START:1;
  uint32                         :2;
  uint32                         u4BREAK_WIDTH:4;
  uint32                         :4;
  uint32                         u1BREAK_LEVEL:1;
  uint32                         :7;
} SCB_UART_RX_CTRL_field_t;

typedef union SCB_UART_RX_CTRL {
  uint32                         u32Register;
  SCB_UART_RX_CTRL_field_t     stcField;
  uint8                          au8Byte[4];
  uint16                         au16Halfword[2];
} SCB_UART_RX_CTRL_t;

/**
  * \brief UART receiver status (SCB_UART_RX_STATUS)
  */
typedef struct SCB_UART_RX_STATUS_field {
  uint32                         u12BR_COUNTER:12;
  uint32                         :20;
} SCB_UART_RX_STATUS_field_t;

typedef union SCB_UART_RX_STATUS {
  uint32                         u32Register;
  SCB_UART_RX_STATUS_field_t   stcField;
  uint8                          au8Byte[4];
  uint16                         au16Halfword[2];
} SCB_UART_RX_STATUS_t;

/**
  * \brief UART flow control (SCB_UART_FLOW_CTRL)
  */
typedef struct SCB_UART_FLOW_CTRL_field {
  uint32                         u8TRIGGER_LEVEL:8;
  uint32                         :8;
  uint32                         u1RTS_POLARITY:1;
  uint32                         :7;
  uint32                         u1CTS_POLARITY:1;
  uint32                         u1CTS_ENABLED:1;
  uint32                         :6;
} SCB_UART_FLOW_CTRL_field_t;

typedef union SCB_UART_FLOW_CTRL {
  uint32                         u32Register;
  SCB_UART_FLOW_CTRL_field_t   stcField;
  uint8                          au8Byte[4];
  uint16                         au16Halfword[2];
} SCB_UART_FLOW_CTRL_t;

/**
  * \brief I2C control (SCB_I2C_CTRL)
  */
typedef struct SCB_I2C_CTRL_field {
  uint32                         u4HIGH_PHASE_OVS:4;
  uint32                         u4LOW_PHASE_OVS:4;
  uint32                         u1M_READY_DATA_ACK:1;
  uint32                         u1M_NOT_READY_DATA_NACK:1;
  uint32                         :1;
  uint32                         u1S_GENERAL_IGNORE:1;
  uint32                         u1S_READY_ADDR_ACK:1;
  uint32                         u1S_READY_DATA_ACK:1;
  uint32                         u1S_NOT_READY_ADDR_NACK:1;
  uint32                         u1S_NOT_READY_DATA_NACK:1;
  uint32                         u1LOOPBACK:1;
  uint32                         :13;
  uint32                         u1SLAVE_MODE:1;
  uint32                         u1MASTER_MODE:1;
} SCB_I2C_CTRL_field_t;

typedef union SCB_I2C_CTRL {
  uint32                         u32Register;
  SCB_I2C_CTRL_field_t         stcField;
  uint8                          au8Byte[4];
  uint16                         au16Halfword[2];
} SCB_I2C_CTRL_t;

/**
  * \brief I2C status (SCB_I2C_STATUS)
  */
typedef struct SCB_I2C_STATUS_field {
  uint32                         u1BUS_BUSY:1;
  uint32                         u1I2C_EC_BUSY:1;
  uint32                         u1I2CS_IC_BUSY:1;
  uint32                         :1;
  uint32                         u1S_READ:1;
  uint32                         u1M_READ:1;
  uint32                         :2;
  uint32                         u8CURR_EZ_ADDR:8;
  uint32                         u8BASE_EZ_ADDR:8;
  uint32                         :8;
} SCB_I2C_STATUS_field_t;

typedef union SCB_I2C_STATUS {
  uint32                         u32Register;
  SCB_I2C_STATUS_field_t       stcField;
  uint8                          au8Byte[4];
  uint16                         au16Halfword[2];
} SCB_I2C_STATUS_t;

/**
  * \brief I2C master command (SCB_I2C_M_CMD)
  */
typedef struct SCB_I2C_M_CMD_field {
  uint32                         u1M_START:1;
  uint32                         u1M_START_ON_IDLE:1;
  uint32                         u1M_ACK:1;
  uint32                         u1M_NACK:1;
  uint32                         u1M_STOP:1;
  uint32                         :27;
} SCB_I2C_M_CMD_field_t;

typedef union SCB_I2C_M_CMD {
  uint32                         u32Register;
  SCB_I2C_M_CMD_field_t        stcField;
  uint8                          au8Byte[4];
  uint16                         au16Halfword[2];
} SCB_I2C_M_CMD_t;

/**
  * \brief I2C slave command (SCB_I2C_S_CMD)
  */
typedef struct SCB_I2C_S_CMD_field {
  uint32                         u1S_ACK:1;
  uint32                         u1S_NACK:1;
  uint32                         :30;
} SCB_I2C_S_CMD_field_t;

typedef union SCB_I2C_S_CMD {
  uint32                         u32Register;
  SCB_I2C_S_CMD_field_t        stcField;
  uint8                          au8Byte[4];
  uint16                         au16Halfword[2];
} SCB_I2C_S_CMD_t;

/**
  * \brief I2C configuration (SCB_I2C_CFG)
  */
typedef struct SCB_I2C_CFG_field {
  uint32                         u2SDA_IN_FILT_TRIM:2;
  uint32                         :2;
  uint32                         u1SDA_IN_FILT_SEL:1;
  uint32                         :3;
  uint32                         u2SCL_IN_FILT_TRIM:2;
  uint32                         :2;
  uint32                         u1SCL_IN_FILT_SEL:1;
  uint32                         :3;
  uint32                         u2SDA_OUT_FILT0_TRIM:2;
  uint32                         u2SDA_OUT_FILT1_TRIM:2;
  uint32                         u2SDA_OUT_FILT2_TRIM:2;
  uint32                         :6;
  uint32                         u2SDA_OUT_FILT_SEL:2;
  uint32                         :2;
} SCB_I2C_CFG_field_t;

typedef union SCB_I2C_CFG {
  uint32                         u32Register;
  SCB_I2C_CFG_field_t          stcField;
  uint8                          au8Byte[4];
  uint16                         au16Halfword[2];
} SCB_I2C_CFG_t;

/**
  * \brief Transmitter control (SCB_TX_CTRL)
  */
typedef struct SCB_TX_CTRL_field {
  uint32                         u5DATA_WIDTH:5;
  uint32                         :3;
  uint32                         u1MSB_FIRST:1;
  uint32                         :7;
  uint32                         u1OPEN_DRAIN:1;
  uint32                         :15;
} SCB_TX_CTRL_field_t;

typedef union SCB_TX_CTRL {
  uint32                         u32Register;
  SCB_TX_CTRL_field_t          stcField;
  uint8                          au8Byte[4];
  uint16                         au16Halfword[2];
} SCB_TX_CTRL_t;

/**
  * \brief Transmitter FIFO control (SCB_TX_FIFO_CTRL)
  */
typedef struct SCB_TX_FIFO_CTRL_field {
  uint32                         u8TRIGGER_LEVEL:8;
  uint32                         :8;
  uint32                         u1CLEAR:1;
  uint32                         u1FREEZE:1;
  uint32                         :14;
} SCB_TX_FIFO_CTRL_field_t;

typedef union SCB_TX_FIFO_CTRL {
  uint32                         u32Register;
  SCB_TX_FIFO_CTRL_field_t     stcField;
  uint8                          au8Byte[4];
  uint16                         au16Halfword[2];
} SCB_TX_FIFO_CTRL_t;

/**
  * \brief Transmitter FIFO status (SCB_TX_FIFO_STATUS)
  */
typedef struct SCB_TX_FIFO_STATUS_field {
  uint32                         u9USED:9;
  uint32                         :6;
  uint32                         u1SR_VALID:1;
  uint32                         u8RD_PTR:8;
  uint32                         u8WR_PTR:8;
} SCB_TX_FIFO_STATUS_field_t;

typedef union SCB_TX_FIFO_STATUS {
  uint32                         u32Register;
  SCB_TX_FIFO_STATUS_field_t   stcField;
  uint8                          au8Byte[4];
  uint16                         au16Halfword[2];
} SCB_TX_FIFO_STATUS_t;

/**
  * \brief Transmitter FIFO write (SCB_TX_FIFO_WR)
  */
typedef struct SCB_TX_FIFO_WR_field {
  uint32                         u32DATA:32;
} SCB_TX_FIFO_WR_field_t;

typedef union SCB_TX_FIFO_WR {
  uint32                         u32Register;
  SCB_TX_FIFO_WR_field_t       stcField;
  uint8                          au8Byte[4];
  uint16                         au16Halfword[2];
} SCB_TX_FIFO_WR_t;

/**
  * \brief Receiver control (SCB_RX_CTRL)
  */
typedef struct SCB_RX_CTRL_field {
  uint32                         u5DATA_WIDTH:5;
  uint32                         :3;
  uint32                         u1MSB_FIRST:1;
  uint32                         u1MEDIAN:1;
  uint32                         :22;
} SCB_RX_CTRL_field_t;

typedef union SCB_RX_CTRL {
  uint32                         u32Register;
  SCB_RX_CTRL_field_t          stcField;
  uint8                          au8Byte[4];
  uint16                         au16Halfword[2];
} SCB_RX_CTRL_t;

/**
  * \brief Receiver FIFO control (SCB_RX_FIFO_CTRL)
  */
typedef struct SCB_RX_FIFO_CTRL_field {
  uint32                         u8TRIGGER_LEVEL:8;
  uint32                         :8;
  uint32                         u1CLEAR:1;
  uint32                         u1FREEZE:1;
  uint32                         :14;
} SCB_RX_FIFO_CTRL_field_t;

typedef union SCB_RX_FIFO_CTRL {
  uint32                         u32Register;
  SCB_RX_FIFO_CTRL_field_t     stcField;
  uint8                          au8Byte[4];
  uint16                         au16Halfword[2];
} SCB_RX_FIFO_CTRL_t;

/**
  * \brief Receiver FIFO status (SCB_RX_FIFO_STATUS)
  */
typedef struct SCB_RX_FIFO_STATUS_field {
  uint32                         u9USED:9;
  uint32                         :6;
  uint32                         u1SR_VALID:1;
  uint32                         u8RD_PTR:8;
  uint32                         u8WR_PTR:8;
} SCB_RX_FIFO_STATUS_field_t;

typedef union SCB_RX_FIFO_STATUS {
  uint32                         u32Register;
  SCB_RX_FIFO_STATUS_field_t   stcField;
  uint8                          au8Byte[4];
  uint16                         au16Halfword[2];
} SCB_RX_FIFO_STATUS_t;

/**
  * \brief Slave address and mask (SCB_RX_MATCH)
  */
typedef struct SCB_RX_MATCH_field {
  uint32                         u8ADDR:8;
  uint32                         :8;
  uint32                         u8MASK:8;
  uint32                         :8;
} SCB_RX_MATCH_field_t;

typedef union SCB_RX_MATCH {
  uint32                         u32Register;
  SCB_RX_MATCH_field_t         stcField;
  uint8                          au8Byte[4];
  uint16                         au16Halfword[2];
} SCB_RX_MATCH_t;

/**
  * \brief Receiver FIFO read (SCB_RX_FIFO_RD)
  */
typedef struct SCB_RX_FIFO_RD_field {
  uint32                         u32DATA:32;
} SCB_RX_FIFO_RD_field_t;

typedef union SCB_RX_FIFO_RD {
  uint32                         u32Register;
  SCB_RX_FIFO_RD_field_t       stcField;
  uint8                          au8Byte[4];
  uint16                         au16Halfword[2];
} SCB_RX_FIFO_RD_t;

/**
  * \brief Receiver FIFO read silent (SCB_RX_FIFO_RD_SILENT)
  */
typedef struct SCB_RX_FIFO_RD_SILENT_field {
  uint32                         u32DATA:32;
} SCB_RX_FIFO_RD_SILENT_field_t;

typedef union SCB_RX_FIFO_RD_SILENT {
  uint32                         u32Register;
  SCB_RX_FIFO_RD_SILENT_field_t stcField;
  uint8                          au8Byte[4];
  uint16                         au16Halfword[2];
} SCB_RX_FIFO_RD_SILENT_t;

/**
  * \brief Memory buffer (SCB_EZ_DATA)
  */
typedef struct SCB_EZ_DATA_field {
  uint32                         u8EZ_DATA:8;
  uint32                         :24;
} SCB_EZ_DATA_field_t;

typedef union SCB_EZ_DATA {
  uint32                         u32Register;
  SCB_EZ_DATA_field_t          stcField;
  uint8                          au8Byte[4];
  uint16                         au16Halfword[2];
} SCB_EZ_DATA_t;

/**
  * \brief Active clocked interrupt signal (SCB_INTR_CAUSE)
  */
typedef struct SCB_INTR_CAUSE_field {
  uint32                         u1M:1;
  uint32                         u1S:1;
  uint32                         u1TX:1;
  uint32                         u1RX:1;
  uint32                         u1I2C_EC:1;
  uint32                         u1SPI_EC:1;
  uint32                         :26;
} SCB_INTR_CAUSE_field_t;

typedef union SCB_INTR_CAUSE {
  uint32                         u32Register;
  SCB_INTR_CAUSE_field_t       stcField;
  uint8                          au8Byte[4];
  uint16                         au16Halfword[2];
} SCB_INTR_CAUSE_t;

/**
  * \brief Externally clocked I2C interrupt request (SCB_INTR_I2C_EC)
  */
typedef struct SCB_INTR_I2C_EC_field {
  uint32                         u1WAKE_UP:1;
  uint32                         u1EZ_STOP:1;
  uint32                         u1EZ_WRITE_STOP:1;
  uint32                         u1EZ_READ_STOP:1;
  uint32                         :28;
} SCB_INTR_I2C_EC_field_t;

typedef union SCB_INTR_I2C_EC {
  uint32                         u32Register;
  SCB_INTR_I2C_EC_field_t      stcField;
  uint8                          au8Byte[4];
  uint16                         au16Halfword[2];
} SCB_INTR_I2C_EC_t;

/**
  * \brief Externally clocked I2C interrupt mask (SCB_INTR_I2C_EC_MASK)
  */
typedef struct SCB_INTR_I2C_EC_MASK_field {
  uint32                         u1WAKE_UP:1;
  uint32                         u1EZ_STOP:1;
  uint32                         u1EZ_WRITE_STOP:1;
  uint32                         u1EZ_READ_STOP:1;
  uint32                         :28;
} SCB_INTR_I2C_EC_MASK_field_t;

typedef union SCB_INTR_I2C_EC_MASK {
  uint32                         u32Register;
  SCB_INTR_I2C_EC_MASK_field_t stcField;
  uint8                          au8Byte[4];
  uint16                         au16Halfword[2];
} SCB_INTR_I2C_EC_MASK_t;

/**
  * \brief Externally clocked I2C interrupt masked (SCB_INTR_I2C_EC_MASKED)
  */
typedef struct SCB_INTR_I2C_EC_MASKED_field {
  uint32                         u1WAKE_UP:1;
  uint32                         u1EZ_STOP:1;
  uint32                         u1EZ_WRITE_STOP:1;
  uint32                         u1EZ_READ_STOP:1;
  uint32                         :28;
} SCB_INTR_I2C_EC_MASKED_field_t;

typedef union SCB_INTR_I2C_EC_MASKED {
  uint32                         u32Register;
  SCB_INTR_I2C_EC_MASKED_field_t stcField;
  uint8                          au8Byte[4];
  uint16                         au16Halfword[2];
} SCB_INTR_I2C_EC_MASKED_t;

/**
  * \brief Externally clocked SPI interrupt request (SCB_INTR_SPI_EC)
  */
typedef struct SCB_INTR_SPI_EC_field {
  uint32                         u1WAKE_UP:1;
  uint32                         u1EZ_STOP:1;
  uint32                         u1EZ_WRITE_STOP:1;
  uint32                         u1EZ_READ_STOP:1;
  uint32                         :28;
} SCB_INTR_SPI_EC_field_t;

typedef union SCB_INTR_SPI_EC {
  uint32                         u32Register;
  SCB_INTR_SPI_EC_field_t      stcField;
  uint8                          au8Byte[4];
  uint16                         au16Halfword[2];
} SCB_INTR_SPI_EC_t;

/**
  * \brief Externally clocked SPI interrupt mask (SCB_INTR_SPI_EC_MASK)
  */
typedef struct SCB_INTR_SPI_EC_MASK_field {
  uint32                         u1WAKE_UP:1;
  uint32                         u1EZ_STOP:1;
  uint32                         u1EZ_WRITE_STOP:1;
  uint32                         u1EZ_READ_STOP:1;
  uint32                         :28;
} SCB_INTR_SPI_EC_MASK_field_t;

typedef union SCB_INTR_SPI_EC_MASK {
  uint32                         u32Register;
  SCB_INTR_SPI_EC_MASK_field_t stcField;
  uint8                          au8Byte[4];
  uint16                         au16Halfword[2];
} SCB_INTR_SPI_EC_MASK_t;

/**
  * \brief Externally clocked SPI interrupt masked (SCB_INTR_SPI_EC_MASKED)
  */
typedef struct SCB_INTR_SPI_EC_MASKED_field {
  uint32                         u1WAKE_UP:1;
  uint32                         u1EZ_STOP:1;
  uint32                         u1EZ_WRITE_STOP:1;
  uint32                         u1EZ_READ_STOP:1;
  uint32                         :28;
} SCB_INTR_SPI_EC_MASKED_field_t;

typedef union SCB_INTR_SPI_EC_MASKED {
  uint32                         u32Register;
  SCB_INTR_SPI_EC_MASKED_field_t stcField;
  uint8                          au8Byte[4];
  uint16                         au16Halfword[2];
} SCB_INTR_SPI_EC_MASKED_t;

/**
  * \brief Master interrupt request (SCB_INTR_M)
  */
typedef struct SCB_INTR_M_field {
  uint32                         u1I2C_ARB_LOST:1;
  uint32                         u1I2C_NACK:1;
  uint32                         u1I2C_ACK:1;
  uint32                         :1;
  uint32                         u1I2C_STOP:1;
  uint32                         :3;
  uint32                         u1I2C_BUS_ERROR:1;
  uint32                         u1SPI_DONE:1;
  uint32                         :22;
} SCB_INTR_M_field_t;

typedef union SCB_INTR_M {
  uint32                         u32Register;
  SCB_INTR_M_field_t           stcField;
  uint8                          au8Byte[4];
  uint16                         au16Halfword[2];
} SCB_INTR_M_t;

/**
  * \brief Master interrupt set request (SCB_INTR_M_SET)
  */
typedef struct SCB_INTR_M_SET_field {
  uint32                         u1I2C_ARB_LOST:1;
  uint32                         u1I2C_NACK:1;
  uint32                         u1I2C_ACK:1;
  uint32                         :1;
  uint32                         u1I2C_STOP:1;
  uint32                         :3;
  uint32                         u1I2C_BUS_ERROR:1;
  uint32                         u1SPI_DONE:1;
  uint32                         :22;
} SCB_INTR_M_SET_field_t;

typedef union SCB_INTR_M_SET {
  uint32                         u32Register;
  SCB_INTR_M_SET_field_t       stcField;
  uint8                          au8Byte[4];
  uint16                         au16Halfword[2];
} SCB_INTR_M_SET_t;

/**
  * \brief Master interrupt mask (SCB_INTR_M_MASK)
  */
typedef struct SCB_INTR_M_MASK_field {
  uint32                         u1I2C_ARB_LOST:1;
  uint32                         u1I2C_NACK:1;
  uint32                         u1I2C_ACK:1;
  uint32                         :1;
  uint32                         u1I2C_STOP:1;
  uint32                         :3;
  uint32                         u1I2C_BUS_ERROR:1;
  uint32                         u1SPI_DONE:1;
  uint32                         :22;
} SCB_INTR_M_MASK_field_t;

typedef union SCB_INTR_M_MASK {
  uint32                         u32Register;
  SCB_INTR_M_MASK_field_t      stcField;
  uint8                          au8Byte[4];
  uint16                         au16Halfword[2];
} SCB_INTR_M_MASK_t;

/**
  * \brief Master interrupt masked request (SCB_INTR_M_MASKED)
  */
typedef struct SCB_INTR_M_MASKED_field {
  uint32                         u1I2C_ARB_LOST:1;
  uint32                         u1I2C_NACK:1;
  uint32                         u1I2C_ACK:1;
  uint32                         :1;
  uint32                         u1I2C_STOP:1;
  uint32                         :3;
  uint32                         u1I2C_BUS_ERROR:1;
  uint32                         u1SPI_DONE:1;
  uint32                         :22;
} SCB_INTR_M_MASKED_field_t;

typedef union SCB_INTR_M_MASKED {
  uint32                         u32Register;
  SCB_INTR_M_MASKED_field_t    stcField;
  uint8                          au8Byte[4];
  uint16                         au16Halfword[2];
} SCB_INTR_M_MASKED_t;

/**
  * \brief Slave interrupt request (SCB_INTR_S)
  */
typedef struct SCB_INTR_S_field {
  uint32                         u1I2C_ARB_LOST:1;
  uint32                         u1I2C_NACK:1;
  uint32                         u1I2C_ACK:1;
  uint32                         u1I2C_WRITE_STOP:1;
  uint32                         u1I2C_STOP:1;
  uint32                         u1I2C_START:1;
  uint32                         u1I2C_ADDR_MATCH:1;
  uint32                         u1I2C_GENERAL:1;
  uint32                         u1I2C_BUS_ERROR:1;
  uint32                         u1SPI_EZ_WRITE_STOP:1;
  uint32                         u1SPI_EZ_STOP:1;
  uint32                         u1SPI_BUS_ERROR:1;
  uint32                         :20;
} SCB_INTR_S_field_t;

typedef union SCB_INTR_S {
  uint32                         u32Register;
  SCB_INTR_S_field_t           stcField;
  uint8                          au8Byte[4];
  uint16                         au16Halfword[2];
} SCB_INTR_S_t;

/**
  * \brief Slave interrupt set request (SCB_INTR_S_SET)
  */
typedef struct SCB_INTR_S_SET_field {
  uint32                         u1I2C_ARB_LOST:1;
  uint32                         u1I2C_NACK:1;
  uint32                         u1I2C_ACK:1;
  uint32                         u1I2C_WRITE_STOP:1;
  uint32                         u1I2C_STOP:1;
  uint32                         u1I2C_START:1;
  uint32                         u1I2C_ADDR_MATCH:1;
  uint32                         u1I2C_GENERAL:1;
  uint32                         u1I2C_BUS_ERROR:1;
  uint32                         u1SPI_EZ_WRITE_STOP:1;
  uint32                         u1SPI_EZ_STOP:1;
  uint32                         u1SPI_BUS_ERROR:1;
  uint32                         :20;
} SCB_INTR_S_SET_field_t;

typedef union SCB_INTR_S_SET {
  uint32                         u32Register;
  SCB_INTR_S_SET_field_t       stcField;
  uint8                          au8Byte[4];
  uint16                         au16Halfword[2];
} SCB_INTR_S_SET_t;

/**
  * \brief Slave interrupt mask (SCB_INTR_S_MASK)
  */
typedef struct SCB_INTR_S_MASK_field {
  uint32                         u1I2C_ARB_LOST:1;
  uint32                         u1I2C_NACK:1;
  uint32                         u1I2C_ACK:1;
  uint32                         u1I2C_WRITE_STOP:1;
  uint32                         u1I2C_STOP:1;
  uint32                         u1I2C_START:1;
  uint32                         u1I2C_ADDR_MATCH:1;
  uint32                         u1I2C_GENERAL:1;
  uint32                         u1I2C_BUS_ERROR:1;
  uint32                         u1SPI_EZ_WRITE_STOP:1;
  uint32                         u1SPI_EZ_STOP:1;
  uint32                         u1SPI_BUS_ERROR:1;
  uint32                         :20;
} SCB_INTR_S_MASK_field_t;

typedef union SCB_INTR_S_MASK {
  uint32                         u32Register;
  SCB_INTR_S_MASK_field_t      stcField;
  uint8                          au8Byte[4];
  uint16                         au16Halfword[2];
} SCB_INTR_S_MASK_t;

/**
  * \brief Slave interrupt masked request (SCB_INTR_S_MASKED)
  */
typedef struct SCB_INTR_S_MASKED_field {
  uint32                         u1I2C_ARB_LOST:1;
  uint32                         u1I2C_NACK:1;
  uint32                         u1I2C_ACK:1;
  uint32                         u1I2C_WRITE_STOP:1;
  uint32                         u1I2C_STOP:1;
  uint32                         u1I2C_START:1;
  uint32                         u1I2C_ADDR_MATCH:1;
  uint32                         u1I2C_GENERAL:1;
  uint32                         u1I2C_BUS_ERROR:1;
  uint32                         u1SPI_EZ_WRITE_STOP:1;
  uint32                         u1SPI_EZ_STOP:1;
  uint32                         u1SPI_BUS_ERROR:1;
  uint32                         :20;
} SCB_INTR_S_MASKED_field_t;

typedef union SCB_INTR_S_MASKED {
  uint32                         u32Register;
  SCB_INTR_S_MASKED_field_t    stcField;
  uint8                          au8Byte[4];
  uint16                         au16Halfword[2];
} SCB_INTR_S_MASKED_t;

/**
  * \brief Transmitter interrupt request (SCB_INTR_TX)
  */
typedef struct SCB_INTR_TX_field {
  uint32                         u1TRIGGER:1;
  uint32                         u1NOT_FULL:1;
  uint32                         :2;
  uint32                         u1EMPTY:1;
  uint32                         u1OVERFLOW:1;
  uint32                         u1UNDERFLOW:1;
  uint32                         u1BLOCKED:1;
  uint32                         u1UART_NACK:1;
  uint32                         u1UART_DONE:1;
  uint32                         u1UART_ARB_LOST:1;
  uint32                         :21;
} SCB_INTR_TX_field_t;

typedef union SCB_INTR_TX {
  uint32                         u32Register;
  SCB_INTR_TX_field_t          stcField;
  uint8                          au8Byte[4];
  uint16                         au16Halfword[2];
} SCB_INTR_TX_t;

/**
  * \brief Transmitter interrupt set request (SCB_INTR_TX_SET)
  */
typedef struct SCB_INTR_TX_SET_field {
  uint32                         u1TRIGGER:1;
  uint32                         u1NOT_FULL:1;
  uint32                         :2;
  uint32                         u1EMPTY:1;
  uint32                         u1OVERFLOW:1;
  uint32                         u1UNDERFLOW:1;
  uint32                         u1BLOCKED:1;
  uint32                         u1UART_NACK:1;
  uint32                         u1UART_DONE:1;
  uint32                         u1UART_ARB_LOST:1;
  uint32                         :21;
} SCB_INTR_TX_SET_field_t;

typedef union SCB_INTR_TX_SET {
  uint32                         u32Register;
  SCB_INTR_TX_SET_field_t      stcField;
  uint8                          au8Byte[4];
  uint16                         au16Halfword[2];
} SCB_INTR_TX_SET_t;

/**
  * \brief Transmitter interrupt mask (SCB_INTR_TX_MASK)
  */
typedef struct SCB_INTR_TX_MASK_field {
  uint32                         u1TRIGGER:1;
  uint32                         u1NOT_FULL:1;
  uint32                         :2;
  uint32                         u1EMPTY:1;
  uint32                         u1OVERFLOW:1;
  uint32                         u1UNDERFLOW:1;
  uint32                         u1BLOCKED:1;
  uint32                         u1UART_NACK:1;
  uint32                         u1UART_DONE:1;
  uint32                         u1UART_ARB_LOST:1;
  uint32                         :21;
} SCB_INTR_TX_MASK_field_t;

typedef union SCB_INTR_TX_MASK {
  uint32                         u32Register;
  SCB_INTR_TX_MASK_field_t     stcField;
  uint8                          au8Byte[4];
  uint16                         au16Halfword[2];
} SCB_INTR_TX_MASK_t;

/**
  * \brief Transmitter interrupt masked request (SCB_INTR_TX_MASKED)
  */
typedef struct SCB_INTR_TX_MASKED_field {
  uint32                         u1TRIGGER:1;
  uint32                         u1NOT_FULL:1;
  uint32                         :2;
  uint32                         u1EMPTY:1;
  uint32                         u1OVERFLOW:1;
  uint32                         u1UNDERFLOW:1;
  uint32                         u1BLOCKED:1;
  uint32                         u1UART_NACK:1;
  uint32                         u1UART_DONE:1;
  uint32                         u1UART_ARB_LOST:1;
  uint32                         :21;
} SCB_INTR_TX_MASKED_field_t;

typedef union SCB_INTR_TX_MASKED {
  uint32                         u32Register;
  SCB_INTR_TX_MASKED_field_t   stcField;
  uint8                          au8Byte[4];
  uint16                         au16Halfword[2];
} SCB_INTR_TX_MASKED_t;

/**
  * \brief Receiver interrupt request (SCB_INTR_RX)
  */
typedef struct SCB_INTR_RX_field {
  uint32                         u1TRIGGER:1;
  uint32                         :1;
  uint32                         u1NOT_EMPTY:1;
  uint32                         u1FULL:1;
  uint32                         :1;
  uint32                         u1OVERFLOW:1;
  uint32                         u1UNDERFLOW:1;
  uint32                         u1BLOCKED:1;
  uint32                         u1FRAME_ERROR:1;
  uint32                         u1PARITY_ERROR:1;
  uint32                         u1BAUD_DETECT:1;
  uint32                         u1BREAK_DETECT:1;
  uint32                         :20;
} SCB_INTR_RX_field_t;

typedef union SCB_INTR_RX {
  uint32                         u32Register;
  SCB_INTR_RX_field_t          stcField;
  uint8                          au8Byte[4];
  uint16                         au16Halfword[2];
} SCB_INTR_RX_t;

/**
  * \brief Receiver interrupt set request (SCB_INTR_RX_SET)
  */
typedef struct SCB_INTR_RX_SET_field {
  uint32                         u1TRIGGER:1;
  uint32                         :1;
  uint32                         u1NOT_EMPTY:1;
  uint32                         u1FULL:1;
  uint32                         :1;
  uint32                         u1OVERFLOW:1;
  uint32                         u1UNDERFLOW:1;
  uint32                         u1BLOCKED:1;
  uint32                         u1FRAME_ERROR:1;
  uint32                         u1PARITY_ERROR:1;
  uint32                         u1BAUD_DETECT:1;
  uint32                         u1BREAK_DETECT:1;
  uint32                         :20;
} SCB_INTR_RX_SET_field_t;

typedef union SCB_INTR_RX_SET {
  uint32                         u32Register;
  SCB_INTR_RX_SET_field_t      stcField;
  uint8                          au8Byte[4];
  uint16                         au16Halfword[2];
} SCB_INTR_RX_SET_t;

/**
  * \brief Receiver interrupt mask (SCB_INTR_RX_MASK)
  */
typedef struct SCB_INTR_RX_MASK_field {
  uint32                         u1TRIGGER:1;
  uint32                         :1;
  uint32                         u1NOT_EMPTY:1;
  uint32                         u1FULL:1;
  uint32                         :1;
  uint32                         u1OVERFLOW:1;
  uint32                         u1UNDERFLOW:1;
  uint32                         u1BLOCKED:1;
  uint32                         u1FRAME_ERROR:1;
  uint32                         u1PARITY_ERROR:1;
  uint32                         u1BAUD_DETECT:1;
  uint32                         u1BREAK_DETECT:1;
  uint32                         :20;
} SCB_INTR_RX_MASK_field_t;

typedef union SCB_INTR_RX_MASK {
  uint32                         u32Register;
  SCB_INTR_RX_MASK_field_t     stcField;
  uint8                          au8Byte[4];
  uint16                         au16Halfword[2];
} SCB_INTR_RX_MASK_t;

/**
  * \brief Receiver interrupt masked request (SCB_INTR_RX_MASKED)
  */
typedef struct SCB_INTR_RX_MASKED_field {
  uint32                         u1TRIGGER:1;
  uint32                         :1;
  uint32                         u1NOT_EMPTY:1;
  uint32                         u1FULL:1;
  uint32                         :1;
  uint32                         u1OVERFLOW:1;
  uint32                         u1UNDERFLOW:1;
  uint32                         u1BLOCKED:1;
  uint32                         u1FRAME_ERROR:1;
  uint32                         u1PARITY_ERROR:1;
  uint32                         u1BAUD_DETECT:1;
  uint32                         u1BREAK_DETECT:1;
  uint32                         :20;
} SCB_INTR_RX_MASKED_field_t;

typedef union SCB_INTR_RX_MASKED {
  uint32                         u32Register;
  SCB_INTR_RX_MASKED_field_t   stcField;
  uint8                          au8Byte[4];
  uint16                         au16Halfword[2];
} SCB_INTR_RX_MASKED_t;



/**
  * \brief Serial Communications Block (SPI/UART/I2C) (SCB)
  */
typedef struct SCB_Reg {
  SCB_CTRL_t                       unCTRL;             /*!< 0x00000000 Generic control */
  SCB_STATUS_t                     unSTATUS;           /*!< 0x00000004 Generic status */
  SCB_CMD_RESP_CTRL_t           unCMD_RESP_CTRL;    /*!< 0x00000008 Command/response control */
  SCB_CMD_RESP_STATUS_t         unCMD_RESP_STATUS;  /*!< 0x0000000C Command/response status */
  uint32                         au32Reserved[4];
  SCB_SPI_CTRL_t                unSPI_CTRL;         /*!< 0x00000020 SPI control */
  SCB_SPI_STATUS_t              unSPI_STATUS;       /*!< 0x00000024 SPI status */
  SCB_SPI_TX_CTRL_t             unSPI_TX_CTRL;      /*!< 0x00000028 SPI transmitter control */
  SCB_SPI_RX_CTRL_t             unSPI_RX_CTRL;      /*!< 0x0000002C SPI receiver control */
  uint32                         au32Reserved1[4];
  SCB_UART_CTRL_t               unUART_CTRL;        /*!< 0x00000040 UART control */
  SCB_UART_TX_CTRL_t            unUART_TX_CTRL;     /*!< 0x00000044 UART transmitter control */
  SCB_UART_RX_CTRL_t            unUART_RX_CTRL;     /*!< 0x00000048 UART receiver control */
  SCB_UART_RX_STATUS_t          unUART_RX_STATUS;   /*!< 0x0000004C UART receiver status */
  SCB_UART_FLOW_CTRL_t          unUART_FLOW_CTRL;   /*!< 0x00000050 UART flow control */
  uint32                         au32Reserved2[3];
  SCB_I2C_CTRL_t                unI2C_CTRL;         /*!< 0x00000060 I2C control */
  SCB_I2C_STATUS_t              unI2C_STATUS;       /*!< 0x00000064 I2C status */
  SCB_I2C_M_CMD_t               unI2C_M_CMD;        /*!< 0x00000068 I2C master command */
  SCB_I2C_S_CMD_t               unI2C_S_CMD;        /*!< 0x0000006C I2C slave command */
  SCB_I2C_CFG_t                 unI2C_CFG;          /*!< 0x00000070 I2C configuration */
  uint32                         au32Reserved3[99];
  SCB_TX_CTRL_t                 unTX_CTRL;          /*!< 0x00000200 Transmitter control */
  SCB_TX_FIFO_CTRL_t            unTX_FIFO_CTRL;     /*!< 0x00000204 Transmitter FIFO control */
  SCB_TX_FIFO_STATUS_t          unTX_FIFO_STATUS;   /*!< 0x00000208 Transmitter FIFO status */
  uint32                         au32Reserved4[13];
  SCB_TX_FIFO_WR_t              unTX_FIFO_WR;       /*!< 0x00000240 Transmitter FIFO write */
  uint32                         au32Reserved5[47];
  SCB_RX_CTRL_t                 unRX_CTRL;          /*!< 0x00000300 Receiver control */
  SCB_RX_FIFO_CTRL_t            unRX_FIFO_CTRL;     /*!< 0x00000304 Receiver FIFO control */
  SCB_RX_FIFO_STATUS_t          unRX_FIFO_STATUS;   /*!< 0x00000308 Receiver FIFO status */
  uint32                         u32Reserved6;
  SCB_RX_MATCH_t                unRX_MATCH;         /*!< 0x00000310 Slave address and mask */
  uint32                         au32Reserved7[11];
  SCB_RX_FIFO_RD_t              unRX_FIFO_RD;       /*!< 0x00000340 Receiver FIFO read */
  SCB_RX_FIFO_RD_SILENT_t       unRX_FIFO_RD_SILENT; /*!< 0x00000344 Receiver FIFO read silent */
  uint32                         au32Reserved8[46];
  SCB_EZ_DATA_t                 unEZ_DATA[512];     /*!< 0x00000400 Memory buffer */
  uint32                         au32Reserved9[128];
  SCB_INTR_CAUSE_t              unINTR_CAUSE;       /*!< 0x00000E00 Active clocked interrupt signal */
  uint32                         au32Reserved10[31];
  SCB_INTR_I2C_EC_t             unINTR_I2C_EC;      /*!< 0x00000E80 Externally clocked I2C interrupt request */
  uint32                         u32Reserved11;
  SCB_INTR_I2C_EC_MASK_t        unINTR_I2C_EC_MASK; /*!< 0x00000E88 Externally clocked I2C interrupt mask */
  SCB_INTR_I2C_EC_MASKED_t      unINTR_I2C_EC_MASKED; /*!< 0x00000E8C Externally clocked I2C interrupt masked */
  uint32                         au32Reserved12[12];
  SCB_INTR_SPI_EC_t             unINTR_SPI_EC;      /*!< 0x00000EC0 Externally clocked SPI interrupt request */
  uint32                         u32Reserved13;
  SCB_INTR_SPI_EC_MASK_t        unINTR_SPI_EC_MASK; /*!< 0x00000EC8 Externally clocked SPI interrupt mask */
  SCB_INTR_SPI_EC_MASKED_t      unINTR_SPI_EC_MASKED; /*!< 0x00000ECC Externally clocked SPI interrupt masked */
  uint32                         au32Reserved14[12];
  SCB_INTR_M_t                  unINTR_M;           /*!< 0x00000F00 Master interrupt request */
  SCB_INTR_M_SET_t              unINTR_M_SET;       /*!< 0x00000F04 Master interrupt set request */
  SCB_INTR_M_MASK_t             unINTR_M_MASK;      /*!< 0x00000F08 Master interrupt mask */
  SCB_INTR_M_MASKED_t           unINTR_M_MASKED;    /*!< 0x00000F0C Master interrupt masked request */
  uint32                         au32Reserved15[12];
  SCB_INTR_S_t                  unINTR_S;           /*!< 0x00000F40 Slave interrupt request */
  SCB_INTR_S_SET_t              unINTR_S_SET;       /*!< 0x00000F44 Slave interrupt set request */
  SCB_INTR_S_MASK_t             unINTR_S_MASK;      /*!< 0x00000F48 Slave interrupt mask */
  SCB_INTR_S_MASKED_t           unINTR_S_MASKED;    /*!< 0x00000F4C Slave interrupt masked request */
  uint32                         au32Reserved16[12];
  SCB_INTR_TX_t                 unINTR_TX;          /*!< 0x00000F80 Transmitter interrupt request */
  SCB_INTR_TX_SET_t             unINTR_TX_SET;      /*!< 0x00000F84 Transmitter interrupt set request */
  SCB_INTR_TX_MASK_t            unINTR_TX_MASK;     /*!< 0x00000F88 Transmitter interrupt mask */
  SCB_INTR_TX_MASKED_t          unINTR_TX_MASKED;   /*!< 0x00000F8C Transmitter interrupt masked request */
  uint32                         au32Reserved17[12];
  SCB_INTR_RX_t                 unINTR_RX;          /*!< 0x00000FC0 Receiver interrupt request */
  SCB_INTR_RX_SET_t             unINTR_RX_SET;      /*!< 0x00000FC4 Receiver interrupt set request */
  SCB_INTR_RX_MASK_t            unINTR_RX_MASK;     /*!< 0x00000FC8 Receiver interrupt mask */
  SCB_INTR_RX_MASKED_t          unINTR_RX_MASKED;   /*!< 0x00000FCC Receiver interrupt masked request */
} SCB_Reg_st;                                           /*!< Size = 4048 (0xFD0) */

/*******************************************************************************
*                                     SCB
*******************************************************************************/

#define SCB0_BASE_ADDR                               0x40600000UL
#define SCB1_BASE_ADDR                               0x40610000UL
#define SCB2_BASE_ADDR                               0x40620000UL
#define SCB3_BASE_ADDR                               0x40630000UL
#define SCB4_BASE_ADDR                               0x40640000UL
#define SCB5_BASE_ADDR                               0x40650000UL
#define SCB6_BASE_ADDR                               0x40660000UL
#define SCB7_BASE_ADDR                               0x40670000UL
#define SCB8_BASE_ADDR                               0x40680000UL
#define SCB9_BASE_ADDR                               0x40690000UL
#define SCB10_BASE_ADDR                              0x406A0000UL
#define SCB11_BASE_ADDR                              0x406B0000UL
#define SCB0_BLOCK                                    ((volatile SCB_Reg_st*) SCB0_BASE_ADDR)                                 /* 0x40600000 */
#define SCB1_BLOCK                                    ((volatile SCB_Reg_st*) SCB1_BASE_ADDR)                                 /* 0x40610000 */
#define SCB2_BLOCK                                    ((volatile SCB_Reg_st*) SCB2_BASE_ADDR)                                 /* 0x40620000 */
#define SCB3_BLOCK                                    ((volatile SCB_Reg_st*) SCB3_BASE_ADDR)                                 /* 0x40630000 */
#define SCB4_BLOCK                                    ((volatile SCB_Reg_st*) SCB4_BASE_ADDR)                                 /* 0x40640000 */
#define SCB5_BLOCK                                    ((volatile SCB_Reg_st*) SCB5_BASE_ADDR)                                 /* 0x40650000 */
#define SCB6_BLOCK                                    ((volatile SCB_Reg_st*) SCB6_BASE_ADDR)                                 /* 0x40660000 */
#define SCB7_BLOCK                                    ((volatile SCB_Reg_st*) SCB7_BASE_ADDR)                                 /* 0x40670000 */
#define SCB8_BLOCK                                    ((volatile SCB_Reg_st*) SCB8_BASE_ADDR)                                 /* 0x40680000 */
#define SCB9_BLOCK                                    ((volatile SCB_Reg_st*) SCB9_BASE_ADDR)                                 /* 0x40690000 */
#define SCB10_BLOCK                                   ((volatile SCB_Reg_st*) SCB10_BASE_ADDR)                                /* 0x406A0000 */
#define SCB11_BLOCK                                   ((volatile SCB_Reg_st*) SCB11_BASE_ADDR)                                /* 0x406B0000 */
/*****************************************************************************
*                            Include files                                   *
******************************************************************************/

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/

typedef volatile SCB_Reg_st* I2c_RegisterPtrType;

/* I2c Data Type*/
typedef uint8  I2c_DataType;

/* Number of Data Type */
typedef uint16  I2c_NumberOfDataType;

/* I2c Channel Type */
typedef uint8  I2c_ChannelType;

#define I2C_SLAVE_MODE      0x01uL
#define I2C_MASTER_MODE     0x02uL

#define I2C_SINGLE_MASTER   0X01U
#define I2C_MULTI_MASTER    0x02u

/* I2c Sequence Type */
typedef I2c_ChannelType  I2c_SequenceType;

#define I2C_UNINIT       0U
#define I2C_IDLE         1U
#define I2C_QUEUED       2U
#define I2C_BUSY         3U
#define I2C_STOP         4U
#define I2C_STOP_WAIT    5U
#define I2C_COMPLETE     6U
#define I2C_REPEAT_START 7
#define I2C_RX_STATE_0   8
#define I2C_RX_STATE_1   9
/* I2c Status Type */
typedef uint8   I2c_StatusType;

#define I2C_SEQ_OK        0U
#define I2C_SEQ_BUSY      1U
#define I2C_SEQ_QUEUED    2U
#define I2C_SEQ_FAILED    3
#define I2C_SEQ_CANCELLED 4
#define I2C_SEQ_RETRY     5
#define I2C_SEQ_REJECT    6
#define I2C_SEQ_RESULT_UNDEFINED    7u
/* I2c Sequence Result Type */
typedef uint8   I2c_SeqResultType;

#define I2C_MODULE_ID     0x85u
#define I2C_INSTANCE_ID   0x00u

/* API-IDs*/
#define I2C_DEINIT_API              0x01u
#define I2C_MAINFUNCTION_API        0x02u
#define I2C_SETUPEB_API             0x03u
#define I2C_ASYNCTRANSMIT_API       0x04u
#define I2C_GETSEQUENCERESULT_API   0x05u
#define I2C_CANCEL_API              0x06u

/* ERROR-IDs */
#define I2C_E_NO_INIT               0x01u
#define I2C_E_PARAM_CHANNEL         0x02u
#define I2C_E_INVALID_HWUNIT        0x03u

/*****************************************************************************
*                                Globally  accessed Variable Declarations    *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/

/*****************************************************************************
*                                 Locally used Variable Declarations         *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/

/*****************************************************************************
*                               Functions                                    *
******************************************************************************/

#endif
/*============================================================================
**============================================================================
** R E V I S I O N    N O T E S
**============================================================================
**
** For each change to this file, be sure to record:
** 1.  Who made the change and when the change was made.
** 2.  Why the change was made and the intended result.
**
**===========================================================================*/
/*---------------------------------------------------------------------------
Date               : 30-March-2023
CDSID              : nchellap
Traceability       : RTC 1891565
Change Description : Initial Framework version of I2c
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 27-Nov-2023
CDSID              : eganesan
Traceability       : DICVA-746 
Change Description : I2c driver - Fail Safe Implementation and FOSS compliance
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 18-Apr-2024
CDSID              : eganesan
Traceability       : DICVA-6730
Change Description : I2c Driver Defect Fix
-----------------------------------------------------------------------------*/
/* end of file =============================================================*/

