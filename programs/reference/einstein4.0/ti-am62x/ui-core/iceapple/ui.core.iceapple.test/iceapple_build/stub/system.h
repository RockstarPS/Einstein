#ifndef SYSTEM_H
#define SYSTEM_H

    #include <stddef.h>
#define CWR_SPECTRUM_TYPE
    /*
    //  "Generic" Base Data Types
    */

/*
**  Define normal "bit" position mask definitions 0 is least significant 32 is most significant
*/
#if !defined( BIT0 )
  #define BIT0    (0x01)
#endif
#if !defined( BIT1 )
  #define BIT1    (0x02)
#endif
#if !defined( BIT2 )
  #define BIT2    (0x04)
#endif
#if !defined( BIT3 )
  #define BIT3    (0x08)
#endif
#if !defined( BIT4 )
  #define BIT4    (0x10)
#endif
#if !defined( BIT5 )
  #define BIT5    (0x20)
#endif
#if !defined( BIT6 )
  #define BIT6    (0x40)
#endif
#if !defined( BIT7 )
  #define BIT7    (0x80)
#endif
#if !defined( BIT8 )
  #define BIT8    (0x0100u)
#endif
#if !defined( BIT9 )
  #define BIT9    (0x0200u)
#endif
#if !defined( BIT10 )
  #define BIT10   (0x0400u)
#endif
#if !defined( BIT11 )
  #define BIT11   (0x0800u)
#endif
#if !defined( BIT12 )
  #define BIT12   (0x1000u)
#endif
#if !defined( BIT13 )
  #define BIT13   (0x2000u)
#endif
#if !defined( BIT14 )
  #define BIT14   (0x4000u)
#endif
#if !defined( BIT15 )
  #define BIT15   (0x8000u)
#endif
#if !defined( BIT16 )
  #define BIT16   (0x00010000u)
#endif
#if !defined( BIT17 )
  #define BIT17   (0x00020000u)
#endif
#if !defined( BIT18 )
  #define BIT18   (0x00040000u)
#endif
#if !defined( BIT19 )
  #define BIT19   (0x00080000u)
#endif
#if !defined( BIT20 )
  #define BIT20   (0x00100000u)
#endif
#if !defined( BIT21 )
  #define BIT21   (0x00200000u)
#endif
#if !defined( BIT22 )
  #define BIT22   (0x00400000u)
#endif
#if !defined( BIT23 )
  #define BIT23   (0x00800000u)
#endif
#if !defined( BIT24 )
  #define BIT24   (0x01000000u)
#endif
#if !defined( BIT25 )
  #define BIT25   (0x02000000u)
#endif
#if !defined( BIT26 )
  #define BIT26   (0x04000000u)
#endif
#if !defined( BIT27 )
  #define BIT27   (0x08000000u)
#endif
#if !defined( BIT28 )
  #define BIT28   (0x10000000u)
#endif
#if !defined( BIT29 )
  #define BIT29   (0x20000000u)
#endif
#if !defined( BIT30 )
  #define BIT30   (0x40000000u)
#endif
#if !defined( BIT31 )
  #define BIT31   (0x80000000u)
#endif

    typedef unsigned char   UINT8;
    typedef   signed char   SINT8;
    typedef unsigned short  UINT16;
    typedef   signed short  SINT16;
    typedef unsigned long   UINT32;
    typedef   signed long   SINT32;
    typedef unsigned char   BOOLEAN;
	typedef unsigned short  UWORD;
	typedef   signed short  SWORD;
	typedef unsigned char   UBYTE;
	typedef   signed char   SBYTE;
	typedef unsigned long   ULONG;
	typedef   signed long   SLONG;
	typedef UINT8           GFX_UINT;
	typedef float           GFX_FLOAT;


    typedef volatile signed char vint8_t;
    typedef volatile unsigned char vuint8_t;

    typedef volatile signed short vint16_t;
    typedef volatile unsigned short vuint16_t;

    typedef volatile signed long vint32_t;
    typedef volatile unsigned long vuint32_t;

//    typedef UINT32 uint32_t;
    typedef UINT16 uint16_t;
    typedef UINT8  uint8_t;
    typedef SINT32 int32_t;
    typedef SINT16 int16_t;
    typedef SINT8  int8_t;

    #ifndef UINT_T
    #define UINT_T unsigned int
    typedef UINT_T uint_T;
    #endif

    #ifndef MAX_int8_T
    #define  MAX_int8_T      ((int8_T)(127))            /* 127  */
    #endif

    #ifndef MIN_int8_T
    #define  MIN_int8_T      ((int8_T)(-128))           /* -128 */
    #endif

    #ifndef MAX_uint8_T
    #define  MAX_uint8_T     ((uint8_T)(255))           /* 255  */
    #endif

    #ifndef MIN_uint8_T
    #define  MIN_uint8_T     ((uint8_T)(0))
    #endif

    #ifndef MAX_int16_T
    #define  MAX_int16_T     ((int16_T)(32767))         /* 32767 */
    #endif

    #ifndef MIN_int16_T
    #define  MIN_int16_T     ((int16_T)(-32768))        /* -32768 */
    #endif

    #ifndef MAX_uint16_T
    #define  MAX_uint16_T    ((uint16_T)(65535))        /* 65535 */
    #endif

    #ifndef MIN_uint16_T
    #define  MIN_uint16_T    ((uint16_T)(0))
    #endif

    #ifndef MAX_int32_T                           
    #define  MAX_int32_T     ((int32_T)(2147483647))    /* 2147483647  */
    #endif

    #ifndef MIN_int32_T
    #define  MIN_int32_T     ((int32_T)(-2147483647-1)) /* -2147483648 */
    #endif

    #ifndef MAX_uint32_T
    #define  MAX_uint32_T    ((uint32_T)(0xFFFFFFFFU))  /* 4294967295  */
    #endif

    #ifndef MIN_uint32_T
    #define  MIN_uint32_T    ((uint32_T)(0))
    #endif

    /*
    //  "Generic" Base Data Type Modifiers
    */
    #define NEAR
    #define FAR

#ifndef TRUE
	#define TRUE  (1)
#endif
#ifndef FALSE
	#define FALSE (0)
#endif
    /*
    //  "Generic" Base Function Type Modifiers
    */
    #define INTERRUPT
    #define FARFUNC
    #define NEARFUNC
    #define REENTRANT
    #define NULL_PTR (0)
	#define __declspec(x)
    /*
    //  "Generic" common function mimicking macros
    */
    #define DISABLE_INTERRUPTS()
    #define ENABLE_INTERRUPTS()
    #define NOP()
    #define DELAY_01_CYC()
    #define DELAY_02_CYC()
    #define DELAY_04_CYC()
    #define DELAY_06_CYC()
    #define DELAY_08_CYC()
    #define DELAY_10_CYC()
    #define DELAY_12_CYC()
    #define DELAY_16_CYC()
    #define DELAY_20_CYC()
    #define DELAY_24_CYC()
    #define DELAY_32_CYC()
    #define DELAY_40_CYC()
    #define DELAY_48_CYC()
    #define DELAY_64_CYC()
    #define DELAY_72_CYC()
    #define DELAY_80_CYC()
    #define DELAY_96_CYC()
    #define DELAY_120_CYC()
    #define DELAY_144_CYC()
    #define MCU_STOP()
    #define MCU_WAIT()
    #define MCU_TRAP( tid )

    #define TESTBIT( operand, bit_mask )        (((operand) &  (bit_mask)) != ((bit_mask) - (bit_mask)))
    #define SETBIT( operand, bit_mask )         ((operand) |= (bit_mask))
    #define CLEARBIT( operand, bit_mask )       ((operand) &= ((UINT32)~(bit_mask)))


#endif
