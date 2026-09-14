#ifndef SYSTEM_H
#define SYSTEM_H

    #include "stdafx.h"
    #include <stddef.h>

    /*
    //  "Generic" Base Data Types
    */
    typedef unsigned char   UINT8;
    typedef   signed char   SINT8;
    typedef unsigned short  UINT16;
    typedef   signed short  SINT16;
    //typedef unsigned long   UINT32;
    typedef   signed long   SINT32;
    typedef unsigned char   BOOLEAN;
	typedef unsigned short  UWORD;
	typedef unsigned char   UBYTE;

    typedef UINT32 uint32_t;
    typedef UINT16 uint16_t;
    typedef UINT8  uint8_t;
    typedef SINT32 int32_t;
    typedef SINT16 int16_t;
    typedef SINT8  int8_t;

    /*
    //  "Generic" Base Data Type Modifiers
    */
    #ifndef NEAR
      #define NEAR
    #endif
    #ifndef FAR
       #define FAR
    #endif
    #define TRUE  1
    #define FALSE 0
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
#endif
