
/**
 * @verbatim
               CONFIDENTIAL VISTEON CORPORATION

 This is an unpublished work of authorship, which contains trade
 secrets, created in 2024. Visteon Corporation owns all rights to
 this work and intends to maintain it in confidence to preserve
 its trade secret status. Visteon Corporation reserves the right,
 under the copyright laws of the United States or those of any
 other country that may have jurisdiction, to protect this work
 as an unpublished work, in the event of an inadvertent or
 deliberate unauthorized publication. Visteon Corporation also
 reserves its rights under all copyright laws to protect this
 work as a published work, when appropriate. Those having access
 to this work may not copy it, use it, modify it or disclose the
 information contained in it without the written authorization
 of Visteon Corporation.
 * @endverbatim
 * @file        I2cTypes.h
 * @details     <b>TI Mcal driver for i2c</b>
 * @note
 *              Compiler    : clang \n
 *              Target Hw   : Independent
 *
 * @copyright   Visteon (c) 2024
 *
 */
#ifndef I2C_TYPES_H
#define I2C_TYPES_H

#include "Std_Types.h"


typedef struct 
{
    uint32            u6MINOR:6;
    uint32            u2CUSTOM:2;
    uint32            u3MAJOR:3;
    uint32            u5RTL:5;
    uint32            :16;
}I2c_REVNB_LO_field;

typedef union 
{
    uint32                u32Register;
    I2c_REVNB_LO_field   REVNB_LO_field;
    uint8                 au8Byte[4];
    uint16                au16Halfword[2];
}I2c_REVNB_LO_reg; /* offset = 0h*/

typedef struct 
{
    uint32            u12FUNC:12;
    uint32            :2;
    uint32            u2SCHEME:2;
    uint32            :16;
}I2c_REVNB_HI_field;

typedef union 
{
    uint32                u32Register;
    I2c_REVNB_HI_field   REVNB_HI_field;
    uint8                 au8Byte[4];
    uint16                au16Halfword[2];
}I2c_REVNB_HI_reg; /* offset = 4h*/

typedef struct
{
    uint32            u1AutoIdle:1;
    uint32            u1SRST:1;
    uint32            u1ENAWAKEUP:1;
    uint32            u2IDLEMODE:2;
    uint32            :2;
    uint32            u2CLKACTIVITY:2;
    uint32            :6;
    uint32            :16;
}I2c_Sysc_field;  

typedef union
{
    uint32            u32Register;
    I2c_Sysc_field   sysc_field;
    uint8             au8Byte[4];
    uint16            au16Halfword[2];
}I2c_Sysc_reg;  /* offset = 10h */

typedef struct
{
    uint32            u1LINE_NUMBER:1;
    uint32            :15;
    uint32            :16;
}I2c_EOI_field;

typedef union
{
    uint32            u32Register;
    I2c_EOI_field    EOI_field;
    uint8             au8Byte[4];
    uint16            au16Halfword[2];
}I2c_EOI_reg;  /* offset = 20h */

typedef struct
{
    uint32            u1AL:1;
    uint32            u1NACK:1;
    uint32            u1ARDY:1;
    uint32            u1RRDY:1;
    uint32            u1XRDY:1;
    uint32            u1GC:1;
    uint32            u1STC:1;
    uint32            u1AERR:1;
    uint32            u1BF:1;
    uint32            u1AAS:1;
    uint32            u1XUDF:1;
    uint32            u1ROVR:1;
    uint32            u1BB:1;
    uint32            u1RDR:1;
    uint32            u1XDR:1;
    uint32            :1;
    uint32            :16;
}I2c_IRQSTATUS_RAW_field;

typedef union
{
    uint32                      u32Register;
    I2c_IRQSTATUS_RAW_field    IRQSTATUS_RAW_field;
    uint8                       au8Byte[4];
    uint16                      au16Halfword[2];
}I2c_IRQSTATUS_RAW_reg;    /* offset = 24h */

typedef struct
{
    uint32            u1AL:1;
    uint32            u1NACK:1;
    uint32            u1ARDY:1;
    uint32            u1RRDY:1;
    uint32            u1XRDY:1;
    uint32            u1GC:1;
    uint32            u1STC:1;
    uint32            u1AERR:1;
    uint32            u1BF:1;
    uint32            u1AAS:1;
    uint32            u1XUDF:1;
    uint32            u1ROVR:1;
    uint32            u1BB:1;
    uint32            u1RDR:1;
    uint32            u1XDR:1;
    uint32            :1;
    uint32            :16;
}I2c_IRQSTATUS_field;

typedef union
{
    uint32                      u32Register;
    I2c_IRQSTATUS_field        IRQSTATUS_field;
    uint8                       au8Byte[4];
    uint16                      au16Halfword[2];
}I2c_IRQSTATUS_reg;  /* offset = 28h */

typedef struct
{
    uint32            u1AL_IE:1;
    uint32            u1NACK_IE:1;
    uint32            u1ARDY_IE:1;
    uint32            u1RRDY_IE:1;
    uint32            u1XRDY_IE:1;
    uint32            u1GC_IE:1;
    uint32            u1STC_IE:1;
    uint32            u1AERR_IE:1;
    uint32            u1BF_IE:1;
    uint32            u1ASS_IE:1;
    uint32            u1XUDF_IE:1;
    uint32            u1ROVR_IE:1;
    uint32            :1;
    uint32            u1RDR_IE:1;
    uint32            u1XDR_IE:1;
    uint32            :1;
    uint32            :16;
}I2c_IRQENABLE_SET_field;

typedef union
{
    uint32                      u32Register;
    I2c_IRQENABLE_SET_field    IRQENABLE_SET_field;
    uint8                       au8Byte[4];
    uint16                      au16Halfword[2];
}I2c_IRQENABLE_SET_reg;  /* offset = 2Ch */

typedef struct
{
    uint32            u1AL_IE:1;
    uint32            u1NACK_IE:1;
    uint32            u1ARDY_IE:1;
    uint32            u1RRDY_IE:1;
    uint32            u1XRDY_IE:1;
    uint32            u1GC_IE:1;
    uint32            u1STC_IE:1;
    uint32            u1AERR_IE:1;
    uint32            u1BF_IE:1;
    uint32            u1ASS_IE:1;
    uint32            u1XUDF_IE:1;
    uint32            u1ROVR_IE:1;
    uint32            :1;
    uint32            u1RDR_IE:1;
    uint32            u1XDR_IE:1;
    uint32            :1;
    uint32            :16;
}I2c_IRQENABLE_CLR_field;

typedef union
{
    uint32                      u32Register;
    I2c_IRQENABLE_CLR_field    IRQENABLE_CLR_field;
    uint8                       au8Byte[4];
    uint16                      au16Halfword[2];
}I2c_IRQENABLE_CLR_reg;  /* offset = 30h */

typedef struct 
{
    uint32            u1AL:1;
    uint32            u1NACK:1;
    uint32            u1ARDY:1;
    uint32            u1DRDY:1;
    uint32            :1;
    uint32            u1GC:1;
    uint32            u1STC:1;
    uint32            :1;
    uint32            u1BF:1;
    uint32            u1AAS:1;
    uint32            u1XUDF:1;
    uint32            u1ROVR:1;
    uint32            :1;
    uint32            u1RDR:1;
    uint32            u1XDR:1;
    uint32            :1;
    uint32            :16;
}I2c_WE_field;

typedef union
{
    uint32           u32Register;
    I2c_WE_field    WE_field;
    uint8            au8Byte[4];
    uint16           au16Halfword[2];
}I2c_WE_reg;  /* offset = 34h */

typedef struct 
{
    uint32            u1RDONE:1;
    uint32            :15;
    uint32            :16;
}I2c_SYSS_field;

typedef union
{
    uint32             u32Register;
    I2c_SYSS_field    SYSS_field;
    uint8              au8Byte[4];
    uint16             au16Halfword[2];
}I2c_SYSS_reg; /* offset = 90h */

typedef struct 
{
    uint32            u6TXTRSH:6;
    uint32            u1TXFIFO_CLR:1;
    uint32            u1XDMA_EN:1;
    uint32            u6RXTRSH:6;
    uint32            u1RXFIFO_CLR:1;
    uint32            u1RDMA_EN:1;
    uint32            :16;
}I2c_BUF_field;

typedef union
{
    uint32             u32Register;
    I2c_BUF_field     BUF_field;
    uint8              au8Byte[4];
    uint16             au16Halfword[2];
}I2c_BUF_reg; /* offset = 94h */

typedef struct 
{
    uint32            u16DCOUNT:16;
    uint32            :16;
}I2c_CNT_field;

typedef union
{
    uint32             u32Register;
    I2c_CNT_field     CNT_field;
    uint8              au8Byte[4];
    uint16             au16Halfword[2];
}I2c_CNT_reg; /* offset = 98h */

typedef struct
{
    uint32            u8DATA:8;
    uint32            :8;
    uint32            :16;
}I2c_DATA_field;

typedef union
{
    uint32              u32Register;
    I2c_DATA_field     DATA_field;
    uint8               au8Byte[4];
    uint16              au16Halfword[2];
}I2c_DATA_reg; /* offset = 9Ch */

typedef struct
{
    uint32            u1STT:1;
    uint32            u1STP:1;
    uint32            :2;
    uint32            u1XOA3:1;
    uint32            u1XOA2:1;
    uint32            u1XOA1:1;
    uint32            u1XOA0:1;
    uint32            u1XSA:1;
    uint32            u1TRX:1;
    uint32            u1MST:1;
    uint32            u1STB:1;
    uint32            u2OPMODE:2;
    uint32            :1;
    uint32            u1I2C_EN:1;
    uint32            :16;
}I2c_CON_field;

typedef union
{
    uint32              u32Register;
    I2c_CON_field      CON_field;
    uint8               au8Byte[4];
    uint16              au16Halfword[2];
}I2c_CON_reg; /* offset = A4h */

typedef struct
{
    uint32              u10OA:10;
    uint32              :3;
    uint32              u3MCODE:3;
    uint32              :16;
}I2c_OA_field;

typedef union
{
    uint32              u32Register;
    I2c_OA_field       OA_field;
    uint8               au8Byte[4];
    uint16              au16Halfword[2];
}I2c_OA_reg; /* offset = A8h */

typedef struct
{
    uint32              u10SA:10;
    uint32              :6;
    uint32              :16;
}I2c_SA_field;

typedef union
{
    uint32              u32Register;
    I2c_SA_field       SA_field;
    uint8               au8Byte[4];
    uint16              au16Halfword[2];
}I2c_SA_reg; /* offset = ACh */

typedef struct
{
    uint32              u8PSC:8;
    uint32              :8;
    uint32              :16;
}I2c_PSC_field;

typedef union
{
    uint32              u32Register;
    I2c_PSC_field      PSC_field;
    uint8               au8Byte[4];
    uint16              au16Halfword[2];
}I2c_PSC_reg; /* offset = B0h */

typedef struct
{
    uint32              u8SCLL:8;
    uint32              u8HSSCLL:8;
    uint32              :16;
}I2c_SCLL_field;

typedef union
{
    uint32              u32Register;
    I2c_SCLL_field     SCLL_field;
    uint8               au8Byte[4];
    uint16              au16Halfword[2];
}I2c_SCLL_reg; /* offset = B4h */

typedef struct
{
    uint32              u8SCLH:8;
    uint32              u8HSSCLH:8;
    uint32              :16;
}I2c_SCLH_field;

typedef union
{
    uint32              u32Register;
    I2c_SCLH_field     SCLH_field;
    uint8               au8Byte[4];
    uint16              au16Halfword[2];
}I2c_SCLH_reg; /* offset = B8h */

typedef struct
{
    uint32              u1SDA_O:1;
    uint32              u1SDA_I:1;
    uint32              u1SCL_O:1;
    uint32              u1SCL_I:1;
    uint32              u1SCCB_E_O:1;
    uint32              u1SDA_O_FUNC:1;
    uint32              u1SDA_I_FUNC:1;
    uint32              u1SCL_O_FUNC:1;
    uint32              u1SCL_I_FUNC:1;
    uint32              :2;
    uint32              u1SSB:1;
    uint32              u2TMODE:2;
    uint32              u1FREE:1;
    uint32              u1ST_EN:1;
    uint32              :16;
}I2c_SYSTEST_field;

typedef union
{
    uint32                 u32Register;
    I2c_SYSTEST_field     SYSTEST_field;
    uint8                  au8Byte[4];
    uint16                 au16Halfword[2];
}I2c_SYSTEST_reg; /* offset = BCh */

typedef struct
{
    uint32              u6TXSTAT:6;
    uint32              :2;
    uint32              u6RXSTAT:6;
    uint32              u2FIFODEPTH:2;
    uint32              :16;
}I2c_BUFSTAT_field;

typedef union
{
    uint32                 u32Register;
    I2c_BUFSTAT_field     BUFSTAT_field;
    uint8                  au8Byte[4];
    uint16                 au16Halfword[2];
}I2c_BUFSTAT_reg; /* offset = C0h */

typedef struct
{
    uint32              u10OA1:10;
    uint32              :6;
    uint32              :16;
}I2c_OA1_field;

typedef union
{
    uint32             u32Register;
    I2c_OA1_field     OA1_field;
    uint8              au8Byte[4];
    uint16             au16Halfword[2];
}I2c_OA1_reg; /* offset = C4 */

typedef struct
{
    uint32              u10OA2:10;
    uint32              :6;
    uint32              :16;
}I2c_OA2_field;

typedef union
{
    uint32             u32Register;
    I2c_OA2_field     OA2_field;
    uint8              au8Byte[4];
    uint16             au16Halfword[2];
}I2c_OA2_reg; /* offset = C8 */

typedef struct
{
    uint32              u10OA3:10;
    uint32              :6;
    uint32              :16;
}I2c_OA3_field;

typedef union
{
    uint32             u32Register;
    I2c_OA3_field     OA3_field;
    uint8              au8Byte[4];
    uint16             au16Halfword[2];
}I2c_OA3_reg; /* offset = CC */

typedef struct
{
    uint32             u1OA0_ACT:1;
    uint32             u1OA1_ACT:1;
    uint32             u1OA2_ACT:1;
    uint32             u1OA3_ACT:1;
    uint32             :12;
    uint32             :16;
}I2c_ACTOA_field;
    
typedef union
{
    uint32             u32Register;
    I2c_ACTOA_field   ACTOA_field;
    uint8              au8Byte[4];
    uint16             au16Halfword[2];
}I2c_ACTOA_reg; /* offset = D0h */

typedef struct
{
    uint32             u1OA0_EN:1;
    uint32             u1OA1_EN:1;
    uint32             u1OA2_EN:1;
    uint32             u1OA3_EN:1;
    uint32             :12;
    uint32             :16;
}I2c_SBLOCK_field;

typedef union
{
    uint32                u32Register;
    I2c_SBLOCK_field     SBLOCK_field;
    uint8                 au8Byte[4];
    uint16                au16Halfword[2];
}I2c_SBLOCK_reg; /* offset = D4h */

typedef struct 
{
    I2c_REVNB_LO_reg               REVNB_LO_reg;  /* 0h */
    I2c_REVNB_HI_reg               REVNB_HI_reg;  /* 4h */
    uint32                         u32Reserved[2];
    I2c_Sysc_reg                   SYSC_reg;    /* 10h */
    uint32                         u32Reserved1[3];
    I2c_EOI_reg                    EOI_reg;     /* 20h */
    I2c_IRQSTATUS_RAW_reg          IRQSTATUS_RAW_reg; /* 24h */
    I2c_IRQSTATUS_reg              IRQSTATUS_reg; /* 28h */
    I2c_IRQENABLE_SET_reg          IRQENABLE_SET_reg; /* 2Ch */
    I2c_IRQENABLE_CLR_reg          IRQENABLE_CLR_reg; /* 30h */
    I2c_WE_reg                     WE_reg; /* 34h */
    uint32                         u32Reserved2[22];
    I2c_SYSS_reg                   SYSS_reg; /* 90h */
    I2c_BUF_reg                    BUF_reg; /* 94h */
    I2c_CNT_reg                    CNT_reg; /* 98h */
    I2c_DATA_reg                   DATA_reg; /* 9Ch */
    uint32                         u32Reserved3[1];
    I2c_CON_reg                    CON_reg; /* A4h */
    I2c_OA_reg                     OA_reg;  /* A8h */
    I2c_SA_reg                     SA_reg; /* ACh */
    I2c_PSC_reg                    PSC_reg; /* B0h */
    I2c_SCLL_reg                   SCLL_reg; /* B4h */
    I2c_SCLH_reg                   SCLH_reg; /* B8h */
    I2c_SYSTEST_reg                SYSTEST_reg; /* BCh */
    I2c_BUFSTAT_reg                BUFSTAT_reg; /* C0h */
    I2c_OA1_reg                    OA1_reg; /* C4h */
    I2c_OA2_reg                    OA2_reg; /* C8h */
    I2c_OA3_reg                    OA3_reg; /* CCh */
    I2c_ACTOA_reg                  ACTOA_reg; /* D0h */
    I2c_SBLOCK_reg                 SBLOCK_reg; /* D4h */
}I2C_reg; 

/*******************************************************************************
*                           I2C BASE ADDRESS
*******************************************************************************/

#define MCU_I2C0_BASE_ADDR              0x04900000UL
#define MCU_I2C0_BLOCK                  ((volatile I2C_reg*) MCU_I2C0_BASE_ADDR) 
#define MAIN_I2C0_BASE_ADDR             0x20000000UL
#define MAIN_I2C0_BLOCK                 ((volatile I2C_reg*) MAIN_I2C0_BASE_ADDR) 
#define MAIN_I2C1_BASE_ADDR             0x20010000UL
#define MAIN_I2C1_BLOCK                 ((volatile I2C_reg*) MAIN_I2C1_BASE_ADDR) 
#define MAIN_I2C2_BASE_ADDR             0x20020000UL
#define MAIN_I2C2_BLOCK                 ((volatile I2C_reg*) MAIN_I2C2_BASE_ADDR)
#define MAIN_I2C3_BASE_ADDR             0x20030000UL
#define MAIN_I2C3_BLOCK                 ((volatile I2C_reg*) MAIN_I2C3_BASE_ADDR) 
#define WKUP_I2C0_BASE_ADDR             0x2B200000UL
#define WKUP_I2C0_BLOCK                 ((volatile I2C_reg*) WKUP_I2C0_BASE_ADDR) 

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/

typedef volatile I2C_reg* I2c_RegisterPtrType; /* am62p entire register set */

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
#define I2C_REPEAT_START 7U
#define I2C_RX_STATE_0   8U
#define I2C_RX_STATE_1   9U
/* I2c Status Type */
typedef uint8   I2c_StatusType;

#define I2C_SEQ_OK        0U
#define I2C_SEQ_BUSY      1U
#define I2C_SEQ_QUEUED    2U
#define I2C_SEQ_FAILED    3U
#define I2C_SEQ_CANCELLED 4U
#define I2C_SEQ_RETRY     5U
#define I2C_SEQ_REJECT    6U
#define I2C_SEQ_RESULT_UNDEFINED    7u
/* I2c Sequence Result Type */
typedef uint8   I2c_SeqResultType;

#define I2C_MODULE_ID       (123U)   /* your assigned module ID */
#define I2C_INSTANCE_ID     (0U)     /* instance, usually 0 */

#endif


/*---------------------------------------------------------------------------------------
REVISION HISTORY
-----------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------
Date              : 13/Feb/2024
By                : eganesan
Traceability      : 
Change Description: I2c initial release
-----------------------------------------------------------------------------------------*/

