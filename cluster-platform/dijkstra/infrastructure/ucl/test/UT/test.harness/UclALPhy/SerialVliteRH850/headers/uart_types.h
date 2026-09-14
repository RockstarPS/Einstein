#if !defined (UART_TYPES_H)
#define UART_TYPES_H
/* ===========================================================================
//
//                     CONFIDENTIAL VISTEON CORPORATION
//
//      This is an unpublished work of authorship, which contains trade
//      secrets, created in 2008.  Visteon Corporation owns all rights
//      to this work and intends to maintain it in confidence to preserve
//      its trade secret status.  Visteon Corporation reserves the right,
//      under the copyright laws of the United States or those of any other
//      country that may have jurisdiction, to protect this work as an
//      unpublished work, in the event of an inadvertent or deliberate
//      unauthorized publication.  Visteon Corporation also reserves its
//      rights under all copyright laws to protect this work as a published
//      work, when appropriate.  Those having access to this work may not
//      copy it, use it, modify it, or disclose the information contained
//      in it without the written authorization of Visteon Corporation.
//
// ======================================================================== */

/* ===========================================================================
//
//  Name:           uart_types.h
//
//  Description:    UART component common type definitions.
//
// ======================================================================== */


/* ===========================================================================
//
//  Include Section
//
// ======================================================================== */



/* ===========================================================================
//
//  Begin C in a C++ environment
//
// ======================================================================== */
#if defined (__cplusplus)
extern "C" {
#endif

/* ===========================================================================
//
//  Public Defined Constants
//
// ======================================================================== */

/***
UART bit mask definitions.
***/
#define UART_BIT_0                  (0x00000001u)
#define UART_BIT_1                  (0x00000002u)
#define UART_BIT_2                  (0x00000004u)
#define UART_BIT_3                  (0x00000008u)
#define UART_BIT_4                  (0x00000010u)
#define UART_BIT_5                  (0x00000020u)
#define UART_BIT_6                  (0x00000040u)
#define UART_BIT_7                  (0x00000080u)
#define UART_BIT_8                  (0x00000100u)
#define UART_BIT_9                  (0x00000200u)
#define UART_BIT_10                 (0x00000400u)
#define UART_BIT_11                 (0x00000800u)
#define UART_BIT_12                 (0x00001000u)
#define UART_BIT_13                 (0x00002000u)
#define UART_BIT_14                 (0x00004000u)
#define UART_BIT_15                 (0x00008000u)
#define UART_BIT_16                 (0x00010000u)
#define UART_BIT_17                 (0x00020000u)
#define UART_BIT_18                 (0x00040000u)
#define UART_BIT_19                 (0x00080000u)
#define UART_BIT_20                 (0x00100000u)
#define UART_BIT_21                 (0x00200000u)
#define UART_BIT_22                 (0x00400000u)
#define UART_BIT_23                 (0x00800000u)
#define UART_BIT_24                 (0x01000000u)
#define UART_BIT_25                 (0x02000000u)
#define UART_BIT_26                 (0x04000000u)
#define UART_BIT_27                 (0x08000000u)
#define UART_BIT_28                 (0x10000000u)
#define UART_BIT_29                 (0x20000000u)
#define UART_BIT_30                 (0x40000000u)
#define UART_BIT_31                 (0x80000000u)

#define UART_BIT_NONE               (0x00000000u)
#define UART_BIT_ALL                (0xFFFFFFFFu)

#define UART_BIT_CLEAR              (0)
#define UART_BIT_SET                (1)

#define UART_OPTION_DISABLED        (0)
#define UART_OPTION_ENABLED         (1)
#define UART_OPTION_UNUSED          UART_OPTION_DISABLED


#if !defined (UART_PRIVATE_DATA_VISIBLE)
    #if defined (__QAC)
        #pragma PRQA_MESSAGES_OFF   3414    /* macro defines keyword    */
    #endif

    #define UART_STATIC_DATA        static
#else
    #if defined (__QAC)
        #pragma PRQA_MESSAGES_OFF   3414    /* macro defines keyword    */
        #define UART_STATIC_DATA    static
    #else
        #define UART_STATIC_DATA
    #endif
#endif

#define UART_NULL            ((void *)(0))


/* ===========================================================================
//
//  Public Type / Structure Definitions
//
// ======================================================================== */

/***
UART fixed size types.
***/
typedef unsigned char       UART_U8_T;
typedef signed char         UART_S8_T;
typedef unsigned short      UART_U16_T;
typedef signed short        UART_S16_T;
typedef unsigned int        UART_U32_T;
typedef signed int          UART_S32_T;

/***
UART 'int' type abstraction types.
***/
typedef int                 UART_INT_T;
typedef unsigned int        UART_UINT_T;
typedef unsigned int        UART_BITFIELD_T;

/***
UART 'boolean' type.
***/
typedef UART_U8_T           UART_BOOL_T;
#define UART_FALSE          ((UART_BOOL_T)(0))
#define UART_TRUE           ((UART_BOOL_T)(1))

/***
UART module ID type.
***/
typedef UART_U8_T           UART_MODULE_ID_T;

/***
UART component event mask type.
***/
typedef UART_U32_T          UART_EVENT_MASK_T;

/***
UART 'client id' type.
***/
typedef UART_U8_T           UART_CLIENT_ID_T;


/***
UART 'buffer size' type.
***/
typedef UART_U16_T          UART_BUFFER_SIZE_T;
#define UART_BUFFER_SIZE_MAX (0xFFFFu)

/***
UART 'state' type.
***/
typedef UART_U8_T           UART_STATE_T;

/***
UART 'network ID' type.
***/
typedef UART_U8_T           UART_NETWORK_ID_T;

/***
UART 'options' type.
***/
typedef UART_U8_T           UART_OPTIONS_T;

/***
UART 'status' type.
***/
typedef enum
{
    UART_S_OK,
    UART_S_ERROR,
    UART_S_INVALID_PARAMETER,
    UART_S_INVALID_CLIENT,
    UART_S_INVALID_CONFIGURATION,
    UART_S_INVALID_STATE,
    UART_S_INVALID_MODE,
    UART_S_INVALID_REQUEST,
    UART_S_INVALID_RECEIVE_LENGTH,
    UART_S_BUSY,
    UART_S_RETRY,
    UART_S_SUSPENDED,
    UART_S_TIMEOUT,
    UART_S_BUF_UNDERRUN,
    UART_S_BUF_OVERRUN,
    UART_S_HW_OVERRUN,
    UART_S_DISABLED

} UART_STATUS_T;

/***
UART 'message' type.
***/
typedef struct
{
    UART_U8_T          * p_data;
    UART_BUFFER_SIZE_T   size;
    UART_OPTIONS_T       options;
    UART_STATUS_T        status;
    UART_U8_T            identifier;

} UART_MESSAGE_T;

/***
UART instance ID type.
***/
typedef UART_U8_T           UART_INST_T;

/***
UART cell ID type.
***/
enum
{
    #if (UART_RLIN30_IS_USED == 1)
    UART_INST_RLIN30,
    #endif

    #if (UART_RLIN31_IS_USED == 1)
    UART_INST_RLIN31,
    #endif

    #if (UART_RLIN32_IS_USED == 1)
    UART_INST_RLIN32,
    #endif

    #if (UART_RLIN33_IS_USED == 1)
    UART_INST_RLIN33,
    #endif

    #if (UART_RLIN34_IS_USED == 1)
    UART_INST_RLIN34,
    #endif

    #if (UART_RLIN35_IS_USED == 1)
    UART_INST_RLIN35,
    #endif

    UART_NUMBER_OF_INST,
    UART_INVALID_INST
};

/***
UART cell ID type.
***/
typedef enum
{
    #if (UART_RLIN30_IS_USED == 1)
    UART_RLIN30_CELL_ID,
    #endif

    #if (UART_RLIN31_IS_USED == 1)
    UART_RLIN31_CELL_ID,
    #endif

    #if (UART_RLIN32_IS_USED == 1)
    UART_RLIN32_CELL_ID,
    #endif

    #if (UART_RLIN33_IS_USED == 1)
    UART_RLIN33_CELL_ID,
    #endif

    #if (UART_RLIN34_IS_USED == 1)
    UART_RLIN34_CELL_ID,
    #endif

    #if (UART_RLIN35_IS_USED == 1)
    UART_RLIN35_CELL_ID,
    #endif

    UART_NUMBER_OF_CELLS

} uart_cell_id_type;


/* ===========================================================================
//
//  Public Variable Declarations
//
// ======================================================================== */


/* ===========================================================================
//
//  Public Constant Data Declarations
//
// ======================================================================== */


/* ===========================================================================
//
//  Public Function Prototypes
//
// ======================================================================== */


/* ===========================================================================
//
//  Public Macros
//
// ======================================================================== */

#if defined (__QAC)

    #pragma PRQA_MACRO_MESSAGES_OFF     "UART_CLEAR_BITS",   3212
    #pragma PRQA_MACRO_MESSAGES_OFF     "UART_SET_BITS",     3212
    #pragma PRQA_MACRO_MESSAGES_OFF     "UART_TEST_BITS",    3212
    #pragma PRQA_MACRO_MESSAGES_OFF     "UART_CREATE_MASK",  3212
    #pragma PRQA_MACRO_MESSAGES_OFF     "UART_INVERT_VALUE", 3212
    #pragma PRQA_MACRO_MESSAGES_OFF     "UART_GET_LOW_U16",  3212
    #pragma PRQA_MACRO_MESSAGES_OFF     "UART_GET_HIGH_U16", 3212

    #pragma PRQA_MESSAGES_OFF   3453    /* function-like macro... */

#endif


#define                                                                 \
UART_CLEAR_BITS(type, location, mask)                                   \
(                                                                       \
    (location) &= ((type)((UART_UINT_T)(mask) ^ (0xFFFFFFFFu)))         \
)

#define                                                                 \
UART_SET_BITS(type, location, mask)                                     \
(                                                                       \
    (location) |= ((type)(mask))                                        \
)

#define                                                                 \
UART_TEST_BITS(type, location, mask)                                    \
(                                                                       \
    (type)((type)(location) & (type)(mask))                             \
)

#define                                                                 \
UART_CREATE_MASK(type, value)                                           \
(                                                                       \
    (type) (1 << (value))                                               \
)

#define                                                                 \
UART_INVERT_VALUE(type, value)                                          \
(                                                                       \
    (type) (((UART_UINT_T)(value)) ^ 0xFFFFFFFFu)                       \
)

#define                                                                 \
UART_GET_LOW_U16(p1)                                                    \
(                                                                       \
    (UART_U16_T)((p1) & (0xFFFFu))                                      \
)

#define                                                                 \
UART_GET_HIGH_U16(p1)                                                   \
(                                                                       \
    (UART_U16_T)((p1) >> (UART_U32_T)(16))                              \
)


/* ===========================================================================
//
//  End C in a C++ environment
//
// ======================================================================== */
#if defined (__cplusplus)
}
#endif


#endif  /* UART_TYPES_H */
