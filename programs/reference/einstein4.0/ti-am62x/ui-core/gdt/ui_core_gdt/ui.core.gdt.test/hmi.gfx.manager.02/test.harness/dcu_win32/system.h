#ifndef SYSTEM_H
#define SYSTEM_H

    #include <stddef.h>

    /*
    //  "Generic" Base Data Types
    */
    typedef unsigned char   UINT8;
    typedef   signed char   SINT8;
    typedef unsigned short  UINT16;
    typedef   signed short  SINT16;
    typedef unsigned int   UINT32;
    typedef   signed int   SINT32;
    typedef unsigned char   BOOLEAN;
	typedef unsigned short  UWORD;
	typedef unsigned char   UBYTE;

#ifndef WIN32
    typedef UINT32 uint32_t;
    typedef UINT16 uint16_t;
    typedef UINT8  uint8_t;
    typedef SINT32 int32_t;
    typedef SINT16 int16_t;
    typedef SINT8  int8_t;
#endif

    #define BIT0 0x01
    #define BIT1 0x02
    #define BIT2 0x04
    #define BIT3 0x08
    #define BIT4 0x10
    #define BIT5 0x20
    #define BIT6 0x40
    #define BIT7 0x80
    #define BIT8    (0x0100u)
    #define BIT9    (0x0200u)
    #define BIT10   (0x0400u)
    #define BIT11   (0x0800u)
    #define BIT12   (0x1000u)
    #define BIT13   (0x2000u)
    #define BIT14   (0x4000u)
    #define BIT15   (0x8000u)

    /*
    //  "Generic" Base Data Type Modifiers
    */
    #ifndef NEAR
      #define NEAR
    #endif
    #ifndef FAR
       #define FAR
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
    
    #define TRUE 1
    #define FALSE 0

#ifndef false
  #define false 0
#endif
#ifndef true
  #define true 1
#endif

#define TESTBIT( operand, bit_mask )        (((operand) &  (bit_mask)) != ((bit_mask) - (bit_mask)))
#define SETBIT( operand, bit_mask )         ((operand) |= (bit_mask))
#define CLEARBIT( operand, bit_mask )       ((operand) &= ((UINT32)~(bit_mask)))

#endif
