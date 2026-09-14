#ifndef SYSTEM_H
#define SYSTEM_H

#define CC_GENERIC

#ifndef __COSMIC_SYSTEMS_ASM
/* ===========================================================================
//              CONFIDENTIAL VISTEON CORPORATION
//
// This is an unpublished work of authorship, which contains trade secrets,
// created in 2000. Visteon Corporation owns all rights to this work and
// intends to maintain it in confidence to preserve its trade secret status.
// Visteon Corporation reserves the right, under the copyright laws of the
// United States or those of any other country that may have  jurisdiction,
// to protect this work as an unpublished work, in the event of an
// inadvertent or deliberate unauthorized publication. Visteon Corporation
// also reserves its rights under all copyright laws to protect this work as
// a published work, when appropriate. Those having access to this work may
// not copy it, use it, modify it or disclose the information contained in
// it without the written authorization of Visteon Corporation
//
// =========================================================================*/

/* ===========================================================================
//
//  Name:           system.h
//
//  Description:    This file contains system wide definitions
//
//  Organization:   Driver Information Core Software Engineering
//                  Visteon Electronics Division
//
// =========================================================================*/

/* ===========================================================================
//
//   $Archive::   J:/arch/dicore/CST_12/src/system.h_v                       $
//  $Revision::   1.17                                                       $
//      $Date::   08 Dec 2003 09:48:38                                       $
//   $Modtime::   08 Dec 2003 09:37:46                                       $
//    $Author::   wderouch                                                   $
//
// =========================================================================*/

#ifndef __IAR_SYSTEMS_ASM

/* ============================================================================
//  convert Mako ECLK define to Hc12 format
// ==========================================================================*/
#if defined (MCU_ECLK_MHZ)
#ifdef __COSMIC_SYSTEMS_ICC
  #define CCAT(x,y) x##y
  #define XCAT(x,y) CCAT(x,y)
  #define MCU_ECLK_IN_MHZ (XCAT(MCU_ECLK_MHZ,ul) * 1000000ul)
  #define MCU_ECLK_MHZ_UL XCAT(MCU_ECLK_MHZ,ul)
  #define MCU_OCLK_MHZ_UL XCAT(MCU_OCLK_MHZ,ul)
#else
  #define MCU_ECLK_IN_MHZ (MCU_ECLK_MHZ * 1000000ul)
  #define MCU_ECLK_MHZ_UL MCU_ECLK_MHZ
  #define MCU_OCLK_MHZ_UL MCU_OCLK_MHZ
#endif
#endif

/* ===========================================================================
//  I N C L U D E   F I L E S
// =========================================================================*/
#include <stddef.h>

/* ===========================================================================
//  P U B L I C   T Y P E   D E F I N I T I O N S
// =========================================================================*/
/*
//  Check for unsupported compilers, compiler targets, and compiler versions.
//  Also check for mismatches between specified build and detected build.
*/
#if !defined( CC_GENERIC )
    #if defined( __IAR_SYSTEMS_ICC )

        #define IAR_TARGET_NEC          (30u)
        #define IAR_TARGET_HC12         (33u)
        #define IAR_TARGET_HC12_BANKED  (2u)

        /*
        //  NEC 78K
        */
        #if (((__TID__ >> 8u) & 0x7fu) == IAR_TARGET_NEC)
            #if ((__VER__ == 221u) || (__VER__ == 312u))
                #
            #else  /* __VER__ */
                #error SYSTEM.H: IAR compiler target = NEC; Compiler version not supported
            #endif /* __VER__ */

        /*
        //  Motorola 68HC12
        */
        #elif (((__TID__ >> 8u) & 0x7fu) == IAR_TARGET_HC12)
            #if ((__VER__ == 220u) || (__VER__ == 242u) || (__VER__ == 243u) || (__VER__ == 244u))
                #
            #else
                #error SYSTEM.H: IAR compiler target = M68HC12; Compiler version not supported
            #endif /* __VER__ */
            /*
            //
            */
            #if   defined( IAR_M68HC12B32 )
                #define IAR_M68HC12_TYPES
            #elif defined( IAR_M68HC12BC32 )
                #define IAR_M68HC12_TYPES
            #elif defined( IAR_M68HC12D32 )
                #define IAR_M68HC12_TYPES
            #elif defined( IAR_M68HC12D60 )
                #define IAR_M68HC12_TYPES
            #elif defined( IAR_M68HC12DA128 )
                #define IAR_M68HC12_TYPES
            #elif defined( IAR_M68HC12DG128 )
                #define IAR_M68HC12_TYPES
            #elif defined( IAR_MC9S12H64 )
                #define IAR_M68HC12_TYPES
            #elif defined( IAR_MC9S12H128 )
                #define IAR_M68HC12_TYPES
            #elif defined( IAR_MC9S12H256 )
                #define IAR_M68HC12_TYPES
            #elif defined( IAR_MC9S12DP256 )
                #define IAR_M68HC12_TYPES
            #elif defined( IAR_MC9S12DT512 )
                #define IAR_M68HC12_TYPES
            #elif defined( IAR_MC9S12D64 )
                #define IAR_M68HC12_TYPES

            #elif defined( IAR_MC9S12HZ256 )
                #define IAR_M68HC12_TYPES
            #elif defined( IAR_MC9S12HZ128 )
                #define IAR_M68HC12_TYPES
            #elif defined( IAR_MC9S12HZ64 )
                #define IAR_M68HC12_TYPES
            #elif defined( IAR_MC9S12HN64 )
                #define IAR_M68HC12_TYPES

            #elif defined( IAR_MC3S12HZ256 )
                #define IAR_M68HC12_TYPES
            #elif defined( IAR_MC3S12HZ192 )
                #define IAR_M68HC12_TYPES
            #elif defined( IAR_MC3S12HZ128 )
                #define IAR_M68HC12_TYPES
            #elif defined( IAR_MC3S12HZ64 )
                #define IAR_M68HC12_TYPES
            #elif defined( IAR_MC3S12HZ32 )
                #define IAR_M68HC12_TYPES
            #elif defined( IAR_MC3S12HN128 )
                #define IAR_M68HC12_TYPES
            #elif defined( IAR_MC3S12HN64 )
                #define IAR_M68HC12_TYPES
            #elif defined( IAR_MC3S12HN32 )
                #define IAR_M68HC12_TYPES

            #elif defined( IAR_M68HC12DA128_BANKED )
                #define IAR_M68HC12_BANKED_TYPES
            #elif defined( IAR_M68HC12DG128_BANKED )
                #define IAR_M68HC12_BANKED_TYPES
            #elif defined( IAR_MC9S12H64_BANKED )
                #define IAR_M68HC12_BANKED_TYPES
            #elif defined( IAR_MC9S12H128_BANKED )
                #define IAR_M68HC12_BANKED_TYPES
            #elif defined( IAR_MC9S12H256_BANKED )
                #define IAR_M68HC12_BANKED_TYPES
            #elif defined( IAR_MC9S12DP256_BANKED )
                #define IAR_M68HC12_BANKED_TYPES
            #elif defined( IAR_MC9S12DT512_BANKED )
                #define IAR_M68HC12_BANKED_TYPES
            #elif defined( IAR_MC9S12XHZ512_BANKED )
                #define IAR_M68HC12_BANKED_TYPES
            #elif defined( IAR_MC9S12D64_BANKED )
                #define IAR_M68HC12_BANKED_TYPES

            #elif defined( IAR_MC9S12HZ256_BANKED )
                #define IAR_M68HC12_BANKED_TYPES
            #elif defined( IAR_MC9S12HZ128_BANKED )
                #define IAR_M68HC12_BANKED_TYPES
            #elif defined( IAR_MC9S12HZ64_BANKED )
                #define IAR_M68HC12_BANKED_TYPES
            #elif defined( IAR_MC9S12HN64_BANKED )
                #define IAR_M68HC12_BANKED_TYPES

            #elif defined( IAR_MC3S12HZ256_BANKED )
                #define IAR_M68HC12_BANKED_TYPES
            #elif defined( IAR_MC3S12HZ192_BANKED )
                #define IAR_M68HC12_BANKED_TYPES
            #elif defined( IAR_MC3S12HZ128_BANKED )
                #define IAR_M68HC12_BANKED_TYPES
            #elif defined( IAR_MC3S12HZ64_BANKED )
                #define IAR_M68HC12_BANKED_TYPES
            #elif defined( IAR_MC3S12HN128_BANKED )
                #define IAR_M68HC12_BANKED_TYPES
            #elif defined( IAR_MC3S12HN64_BANKED )
                #define IAR_M68HC12_BANKED_TYPES
            #elif defined( IAR_MC9S12B128_BANKED )
                #define IAR_M68HC12_BANKED_TYPES

            #elif defined( IAR_NEC78K )
            #else
            #endif

            /*
            //  Verify that the memory model specified is
            //  consistent with the model detected.  If not
            //  emit an error message
            */
            #if ((__TID__ & 0x0fu) == IAR_TARGET_HC12_BANKED)
                #if !defined( IAR_M68HC12_BANKED_TYPES )
                    #error SYSTEM.H: IAR compiler - banked memory model detected, non-banked model specified
                #endif
            #else
                #if !defined( IAR_M68HC12_TYPES )
                    #error SYSTEM.H: IAR compiler - non-banked memory model detected, banked model specified
                #endif
            #endif /* __TID__ */
        /*
        //  Unsupported IAR target
        */
        #else  /* __TID__ */
            #error SYSTEM.H: Unsupported IAR compiler detected.  Please define CC_GENERIC for unsupported compilers
        #endif /* __TID__ */

    #endif  /* __IAR_SYSTEMS_ICC */

#ifdef QAC_ACTIVE
//#pragma PRQA_MESSAGES_OFF 0877
#endif
    #if defined( __CSMC__ )

     #ifndef QAC_ACTIVE
      #if ((__VERS__ == "V4.6i") || (__VERS__ == "V4.7.6") || (__VERS__ == "V4.7.7"))
        #if defined( COSMIC_MC9S12XHZ512_BANKED ) ||  defined( COSMIC_MC9S12XHZ256_BANKED )
            #define COSMIC_M68HC12_BANKED_TYPES
        #elif defined( COSMIC_MC9S12XEP100_BANKED )
            #define COSMIC_M68HC12_BANKED_TYPES
        #else
            #error SYSTEM.H: Unsupported micro specified for use with Cosmic compiler
        #endif
      #else
          #error SYSTEM.H: Unsupported Cosmic compiler version detected.
      #endif
     #else
        #if defined( COSMIC_MC9S12XHZ512_BANKED ) ||  defined( COSMIC_MC9S12XHZ256_BANKED )
            #define COSMIC_M68HC12_BANKED_TYPES
        #elif defined( COSMIC_MC9S12XEP100_BANKED )
            #define COSMIC_M68HC12_BANKED_TYPES
        #else
            #error SYSTEM.H: Unsupported micro specified for use with Cosmic compiler
        #endif
     #endif
    #endif /* __CSMC__ */
#ifdef QAC_ACTIVE
//#pragma PRQA_MESSAGES_ON
#endif

#endif /* CC_GENERIC */

#if defined( CC_RENESAS )
    /*
    //  "Generic" Base Data Types
    */
    typedef unsigned char   UINT8;
    typedef   signed char   SINT8;
    typedef unsigned short  UINT16;
    typedef   signed short  SINT16;
    typedef unsigned int    UINT32;
    typedef   signed int    SINT32;
    typedef unsigned char   BOOLEAN;
    /*
    //  "Generic" Base Data Type Modifiers
    */
    #define NEAR
    #define FAR
    /*
    //  "Generic" Base Function Type Modifiers
    */
    #define INTERRUPT
    #define FARFUNC
    #define NEARFUNC
    #define REENTRANT
	#define GLOBAL_PTR_PREFIX
    #define GLOBAL_RAM_PTR_PREFIX
    #define GLOBAL_RAM_PREFIX
    #define GLOBAL_CONST_PREFIX
	#define BANKED_RAM_PTR
    #define RDAP_GLOBAL_RAM_PREFIX
	#define RDAP_GLOBAL_RAM_PTR_PREFIX
	#define RDAP_GLOBAL_CONST_PREFIX
	#define RDAP_GLOBAL_CONST_PTR_PREFIX
    #define FNULL	NULL
	#define COSMIC_MC9S12XEP100_BANKED
	#define N_RDAP_GLOBAL_CONST_PREFIX
	#define N_RDAP_GLOBAL_CONST_PTR_PREFIX

#elif defined( CC_GENERIC )
    /*
    //  "Generic" Base Data Types
    */
    typedef unsigned char   UINT8;
    typedef   signed char   SINT8;
    typedef unsigned short  UINT16;
    typedef   signed short  SINT16;
    typedef unsigned long   UINT32;
    typedef   signed long   SINT32;
    typedef unsigned char   BOOLEAN;
    /*
    //  "Generic" Base Data Type Modifiers
    */
    #define NEAR
    #define FAR
    /*
    //  "Generic" Base Function Type Modifiers
    */
    #define INTERRUPT
    #define FARFUNC
    #define NEARFUNC
    #define REENTRANT

#elif defined( IAR_M68HC12_TYPES )
    /*
    //  Base Data Types
    */
    typedef unsigned char   UINT8;
    typedef   signed char   SINT8;
    typedef unsigned short int   UINT16;
    typedef   signed short int   SINT16;
    typedef unsigned long   UINT32;
    typedef   signed long   SINT32;
    typedef unsigned char   BOOLEAN;
    /*
    //  Base Data Type Modifiers
    */
    #define NEAR        zpage
    #define FAR
    /*
    //  Base Function Type Modifiers
    */
    #define INTERRUPT   interrupt
    #define FARFUNC
    #define NEARFUNC
    #define REENTRANT

#elif defined( IAR_M68HC12_BANKED_TYPES )
    /*
    //  Base Data Types
    */
    typedef unsigned char   UINT8;
    typedef   signed char   SINT8;
    typedef unsigned short int   UINT16;
    typedef   signed short int   SINT16;
    typedef unsigned long   UINT32;
    typedef   signed long   SINT32;
    typedef unsigned char   BOOLEAN;
    /*
    //  Base Data Type Modifiers
    */
 #if defined( IAR_MC9S12XHZ512_BANKED )
    #define NEAR
 #else
    #define NEAR        zpage
 #endif
    #define FAR
    /*
    //  Base Function Type Modifiers
    */
    #define INTERRUPT   interrupt
    #define FARFUNC     banked
    #define NEARFUNC    non_banked
    #define REENTRANT

#elif defined( COSMIC_M68HC12_BANKED_TYPES )
    /*
    //  Base Data Types
    */
    typedef unsigned char   UINT8;
    typedef   signed char   SINT8;
    typedef unsigned int    UINT16;
    typedef   signed int    SINT16;
    typedef unsigned long   UINT32;
    typedef   signed long   SINT32;
    typedef unsigned char   BOOLEAN;
    /*
    //  Base Data Type Modifiers
    */
    #define NEAR
    #define FAR
    #define BANKED_RAM   @gpage
    #define BANKED_RAM_PTR   @far @gpage
    /*
    //  Base Function Type Modifiers
    */
    #define INTERRUPT   @interrupt @near
    #define FARFUNC
    #define NEARFUNC    @near
    #define REENTRANT

#else
    #error SYSTEM.H: The compiler, mcu, memory model identifier was not detected
#endif /* build identifier check */

/*
//  Derived Types
*/
typedef UINT8   UBYTE;
typedef SINT8   SBYTE;
typedef UINT16  UWORD;
typedef SINT16  SWORD;
typedef UINT32  ULONG;
typedef SINT32  SLONG;

/* ===========================================================================
//  P U B L I C   M A C R O   D E F I N I T I O N S
// =========================================================================*/
#if defined( CC_RENESAS )
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
#elif defined( CC_GENERIC )
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

#elif ( defined( IAR_M68HC12_TYPES ) || defined( IAR_M68HC12_BANKED_TYPES ) )
    /*
    //  "" common function mimicking macros
    */
    #include <intr6812.h>
    #define DISABLE_INTERRUPTS()    disable_interrupt()
    #define ENABLE_INTERRUPTS()     enable_interrupt()
    #define NOP()                   _opc(0xA7)
    #define DELAY_01_CYC()          _opc(0xA7)
    #define DELAY_02_CYC()          _opc(0xA7); _opc(0xA7)
    #define DELAY_03_CYC()          DELAY_02_CYC(); DELAY_01_CYC()
    #define DELAY_04_CYC()          DELAY_02_CYC(); DELAY_02_CYC()
    #define DELAY_05_CYC()          _opc(0x36); _opc(0x32)
    #define DELAY_06_CYC()          DELAY_05_CYC(); DELAY_01_CYC()
    #define DELAY_08_CYC()          DELAY_05_CYC(); DELAY_03_CYC()
    #define DELAY_10_CYC()          DELAY_05_CYC(); DELAY_05_CYC()
    #define DELAY_12_CYC()          DELAY_10_CYC(); DELAY_02_CYC()
    #define DELAY_16_CYC()          DELAY_10_CYC(); DELAY_06_CYC()
    #define DELAY_20_CYC()          DELAY_10_CYC(); DELAY_10_CYC()
    #define DELAY_24_CYC()          _opc(0x36);_opc(0x86);_opc(0x06);_opc(0x04);_opc(0x30);_opc(0xFD);_opc(0x32)
    #define DELAY_30_CYC()          _opc(0x36);_opc(0x86);_opc(0x08);_opc(0x04);_opc(0x30);_opc(0xFD);_opc(0x32)
    #define DELAY_32_CYC()          DELAY_30_CYC(); DELAY_02_CYC()
    #define DELAY_39_CYC()          _opc(0x36);_opc(0x86);_opc(0x0B);_opc(0x04);_opc(0x30);_opc(0xFD);_opc(0x32)
    #define DELAY_40_CYC()          DELAY_39_CYC(); DELAY_01_CYC()
    #define DELAY_48_CYC()          _opc(0x36);_opc(0x86);_opc(0x0E);_opc(0x04);_opc(0x30);_opc(0xFD);_opc(0x32)
    #define DELAY_63_CYC()          _opc(0x36);_opc(0x86);_opc(0x13);_opc(0x04);_opc(0x30);_opc(0xFD);_opc(0x32)
    #define DELAY_64_CYC()          DELAY_63_CYC(); DELAY_01_CYC()
    #define DELAY_72_CYC()          _opc(0x36);_opc(0x86);_opc(0x16);_opc(0x04);_opc(0x30);_opc(0xFD);_opc(0x32)
    #define DELAY_78_CYC()          _opc(0x36);_opc(0x86);_opc(0x18);_opc(0x04);_opc(0x30);_opc(0xFD);_opc(0x32)
    #define DELAY_80_CYC()          DELAY_78_CYC(); DELAY_02_CYC()
    #define DELAY_96_CYC()          _opc(0x36);_opc(0x86);_opc(0x1E);_opc(0x04);_opc(0x30);_opc(0xFD);_opc(0x32)
    #define DELAY_120_CYC()         _opc(0x36);_opc(0x86);_opc(0x26);_opc(0x04);_opc(0x30);_opc(0xFD);_opc(0x32)
    #define DELAY_128_CYC()         DELAY_120_CYC(); DELAY_08_CYC()
    #define DELAY_144_CYC()         _opc(0x36);_opc(0x86);_opc(0x2E);_opc(0x04);_opc(0x30);_opc(0xFD);_opc(0x32)
    #define DELAY_192_CYC()         DELAY_96_CYC(); DELAY_96_CYC()
    #define DELAY_200_CYC()         DELAY_120_CYC(); DELAY_80_CYC()
    #define DELAY_240_CYC()         DELAY_120_CYC(); DELAY_120_CYC()
    #define MCU_STOP()              stop_CPU()
    #define MCU_WAIT()              wait_for_interrupt()
    #define MCU_TRAP( tid )         { _opc( 0x18 ); _opc((tid)); }

#elif defined( COSMIC_M68HC12_BANKED_TYPES )
    /*
    //  "" common function mimicking macros
    */
    #define DISABLE_INTERRUPTS() _asm("sei")
    #define ENABLE_INTERRUPTS()  _asm("cli")
    #define NOP()                _asm("nop")
    #define DELAY_01_CYC()          _asm("nop")
    #define DELAY_02_CYC()          _asm("nop"); _asm("nop")
    #define DELAY_03_CYC()          DELAY_02_CYC(); DELAY_01_CYC()
    #define DELAY_04_CYC()          DELAY_02_CYC(); DELAY_02_CYC()
    #define DELAY_05_CYC()          _asm("psha"); _asm("pula")
    #define DELAY_06_CYC()          DELAY_05_CYC(); DELAY_01_CYC()
    #define DELAY_08_CYC()          DELAY_05_CYC(); DELAY_03_CYC()
    #define DELAY_10_CYC()          DELAY_05_CYC(); DELAY_05_CYC()
    #define DELAY_12_CYC()          DELAY_10_CYC(); DELAY_02_CYC()
    #define DELAY_16_CYC()          DELAY_10_CYC(); DELAY_06_CYC()
    #define DELAY_20_CYC()          DELAY_10_CYC(); DELAY_10_CYC()
    #define DELAY_24_CYC()          _asm("psha");_asm("ldaa #$06");_asm("$N: dbne a,$L");_asm("pula")
    #define DELAY_30_CYC()          _asm("psha");_asm("ldaa #$08");_asm("$N: dbne a,$L");_asm("pula")
    #define DELAY_32_CYC()          DELAY_30_CYC(); DELAY_02_CYC()
    #define DELAY_39_CYC()          _asm("psha");_asm("ldaa #$0B");_asm("$N: dbne a,$L");_asm("pula")
    #define DELAY_40_CYC()          DELAY_39_CYC(); DELAY_01_CYC()
    #define DELAY_48_CYC()          _asm("psha");_asm("ldaa #$0E");_asm("$N: dbne a,$L");_asm("pula")
    #define DELAY_63_CYC()          _asm("psha");_asm("ldaa #$13");_asm("$N: dbne a,$L");_asm("pula")
    #define DELAY_64_CYC()          DELAY_63_CYC(); DELAY_01_CYC()
    #define DELAY_72_CYC()          _asm("psha");_asm("ldaa #$16");_asm("$N: dbne a,$L:");_asm("pula")
    #define DELAY_78_CYC()          _asm("psha");_asm("ldaa #$18");_asm("$N: dbne a,$L");_asm("pula")
    #define DELAY_80_CYC()          DELAY_78_CYC(); DELAY_02_CYC()
    #define DELAY_96_CYC()          _asm("psha");_asm("ldaa #$1E");_asm("$N: dbne a,$L");_asm("pula")
    #define DELAY_120_CYC()         _asm("psha");_asm("ldaa #$26");_asm("$N: dbne a,$L");_asm("pula")
    #define DELAY_128_CYC()         DELAY_120_CYC(); DELAY_08_CYC()
    #define DELAY_144_CYC()         _asm("psha");_asm("ldaa #$2E");_asm("$N: dbne a,$L");_asm("pula")
    #define DELAY_192_CYC()         DELAY_96_CYC(); DELAY_96_CYC()
    #define DELAY_200_CYC()         DELAY_120_CYC(); DELAY_80_CYC()
    #define DELAY_240_CYC()         DELAY_120_CYC(); DELAY_120_CYC()
    #define MCU_STOP()           _asm("stop")
    #define MCU_WAIT()           _asm("wait")
    #define MCU_TRAP( tid )      _asm("trap tid")

#else
    #error SYSTEM.H: The compiler, mcu, memory model identifier was not detected
#endif /* build identifier check */

#if (MCU_ECLK_IN_MHZ == 2000000uL)
    #define DELAY_HALF_USEC()   DELAY_01_CYC()
    #define DELAY_1_USEC()      DELAY_02_CYC()
    #define DELAY_2_USEC()      DELAY_04_CYC()
    #define DELAY_3_USEC()      DELAY_06_CYC()
    #define DELAY_4_USEC()      DELAY_08_CYC()
    #define DELAY_5_USEC()      DELAY_10_CYC()
    #define DELAY_6_USEC()      DELAY_12_CYC()
#elif (MCU_ECLK_IN_MHZ == 4000000uL)
    #define DELAY_HALF_USEC()   DELAY_02_CYC()
    #define DELAY_1_USEC()      DELAY_04_CYC()
    #define DELAY_2_USEC()      DELAY_08_CYC()
    #define DELAY_3_USEC()      DELAY_12_CYC()
    #define DELAY_4_USEC()      DELAY_16_CYC()
    #define DELAY_5_USEC()      DELAY_20_CYC()
    #define DELAY_6_USEC()      DELAY_24_CYC()
#elif (MCU_ECLK_IN_MHZ == 8000000uL)
    #define DELAY_HALF_USEC()   DELAY_04_CYC()
    #define DELAY_1_USEC()      DELAY_08_CYC()
    #define DELAY_2_USEC()      DELAY_16_CYC()
    #define DELAY_3_USEC()      DELAY_24_CYC()
    #define DELAY_4_USEC()      DELAY_32_CYC()
    #define DELAY_5_USEC()      DELAY_40_CYC()
    #define DELAY_6_USEC()      DELAY_48_CYC()
#elif (MCU_ECLK_IN_MHZ == 16000000uL)
    #define DELAY_HALF_USEC()   DELAY_08_CYC()
    #define DELAY_1_USEC()      DELAY_16_CYC()
    #define DELAY_2_USEC()      DELAY_32_CYC()
    #define DELAY_3_USEC()      DELAY_48_CYC()
    #define DELAY_4_USEC()      DELAY_64_CYC()
    #define DELAY_5_USEC()      DELAY_80_CYC()
    #define DELAY_6_USEC()      DELAY_96_CYC()
#elif (MCU_ECLK_IN_MHZ == 24000000uL)
    #define DELAY_HALF_USEC()   DELAY_12_CYC()
    #define DELAY_1_USEC()      DELAY_24_CYC()
    #define DELAY_2_USEC()      DELAY_48_CYC()
    #define DELAY_3_USEC()      DELAY_72_CYC()
    #define DELAY_4_USEC()      DELAY_96_CYC()
    #define DELAY_5_USEC()      DELAY_120_CYC()
    #define DELAY_6_USEC()      DELAY_144_CYC()
#elif (MCU_ECLK_IN_MHZ ==32000000uL)
    #define DELAY_HALF_USEC()   DELAY_16_CYC()
    #define DELAY_1_USEC()      DELAY_32_CYC()
    #define DELAY_2_USEC()      DELAY_64_CYC()
    #define DELAY_3_USEC()      DELAY_96_CYC()
    #define DELAY_4_USEC()      DELAY_128_CYC()
    #define DELAY_5_USEC()      DELAY_160_CYC()
    #define DELAY_6_USEC()      DELAY_192_CYC()
#elif (MCU_ECLK_IN_MHZ == 40000000uL)
    #define DELAY_HALF_USEC()   DELAY_20_CYC()
    #define DELAY_1_USEC()      DELAY_40_CYC()
    #define DELAY_2_USEC()      DELAY_80_CYC()
    #define DELAY_3_USEC()      DELAY_120_CYC()
    #define DELAY_4_USEC()      DELAY_160_CYC()
    #define DELAY_5_USEC()      DELAY_200_CYC()
    #define DELAY_6_USEC()      DELAY_240_CYC()
#else
#endif

/*
//  If a definition of NULL isn't provided by the compiler's stddef.h
//  define it here.
*/
#if !defined( NULL )
    #define NULL    ((void *) 0)
#endif

/*
//
*/
#define TESTBIT( operand, bit_mask )        (((operand) &  (bit_mask)) != ((bit_mask) - (bit_mask)))
#define SETBIT( operand, bit_mask )         ((operand) |= (bit_mask))
#define CLEARBIT( operand, bit_mask )       ((operand) &= ((UINT32)~(bit_mask)))

 #endif /* __IAR_SYSTEMS_ASM */
#endif

#ifndef __COSMIC_SYSTEMS_ASM
/*
//
*/
#if !defined( FALSE )
    #define FALSE   ((BOOLEAN) 0)
#endif

#if !defined( TRUE )
    #define TRUE    ((BOOLEAN) 1)
#endif

/*
// define is_true and is_false
*/
#define IS_TRUE(x) (x != FALSE)
#define IS_FALSE(x) (x == FALSE)


/*
//  "bit" position mask definitions
*/
#define BIT0    (0x01)
#define BIT1    (0x02)
#define BIT2    (0x04)
#define BIT3    (0x08)
#define BIT4    (0x10)
#define BIT5    (0x20)
#define BIT6    (0x40)
#define BIT7    (0x80)
#define BIT8    (0x0100u)
#define BIT9    (0x0200u)
#define BIT10   (0x0400u)
#define BIT11   (0x0800u)
#define BIT12   (0x1000u)
#define BIT13   (0x2000u)
#define BIT14   (0x4000u)
#define BIT15   (0x8000u)
#define BIT16   (0x00010000uL)
#define BIT17   (0x00020000uL)
#define BIT18   (0x00040000uL)
#define BIT19   (0x00080000uL)
#define BIT20   (0x00100000uL)
#define BIT21   (0x00200000uL)
#define BIT22   (0x00400000uL)
#define BIT23   (0x00800000uL)
#define BIT24   (0x01000000uL)
#define BIT25   (0x02000000uL)
#define BIT26   (0x04000000uL)
#define BIT27   (0x08000000uL)
#define BIT28   (0x10000000uL)
#define BIT29   (0x20000000uL)
#define BIT30   (0x40000000uL)
#define BIT31   (0x80000000uL)
#endif

#ifdef __COSMIC_SYSTEMS_ASM
#define BIT0    0x01
#define BIT1    0x02
#define BIT2    0x04
#define BIT3    0x08
#define BIT4    0x10
#define BIT5    0x20
#define BIT6    0x40
#define BIT7    0x80
#define BIT8    0x0100
#define BIT9    0x0200
#define BIT10   0x0400
#define BIT11   0x0800
#define BIT12   0x1000
#define BIT13   0x2000
#define BIT14   0x4000
#define BIT15   0x8000
#define BIT16   0x00010000
#define BIT17   0x00020000
#define BIT18   0x00040000
#define BIT19   0x00080000
#define BIT20   0x00100000
#define BIT21   0x00200000
#define BIT22   0x00400000
#define BIT23   0x00800000
#define BIT24   0x01000000
#define BIT25   0x02000000
#define BIT26   0x04000000
#define BIT27   0x08000000
#define BIT28   0x10000000
#define BIT29   0x20000000
#define BIT30   0x40000000
#define BIT31   0x80000000
#endif

#ifndef __COSMIC_SYSTEMS_ASM
/* ===========================================================================
//  P V C S    R E V I S I O N    N O T E S
// ---------------------------------------------------------------------------
//  for each change to this file, record the following:
//
//  1.  who made the change and when the change was made
//  2.  why the change was made and the intended result
//      MCU_ECLK_MHZ_UL
// ---------------------------------------------------------------------------
//  $Revision:   1.17  $
// ---------------------------------------------------------------------------
//
//  Clearcase main\37
//          20-May-2008 tburke4                     support for S12XEP100 micro
//          25-Apr-2008 psurend1                    support for MC9S12XHZ256 micro
//          08-Feb-2008 mshanka1    BSDI00054428    support for S12B128 micro.
//
//  Clearcase main\36   15-Jan-2008 wderouch
//                      Added support Cosmic version 4.7.7
//
//  Clearcase main\35   31-May-2007 crangana
//                      Added support for S12X Banked RAM for CQ 44249.
//
//  Clearcase main\34 14-February-2007 nashokku
//          Added __VERS__ for Cosmic compiler V4.7.6
//
//  Clearcase main\33 10-October-2006 wfd
//          Define  MCU_ECLK_MHZ_UL and MCU_OCLK_MHZ_UL to allow elimination
//          of QAC warnings in other files, when cosmic compiler is used.
//
//  Clearcase main\32 23-September-2006 CNA
//          Added support for MCU_MC9S12D64
//
//  Clearcase main\31 17-August-2006 WFD
//          Corrected the definition of MCU_ECLK_IN_MHZ for Cosmic to avoid
//          QAC warnings
//
//  Clearcase main\30 11-August-2006 WFD
//          Corrected the DELAY_72_CYC() macro for Cosmic
//
//  Clearcase main\29 16-June-2006 WFD
//          Changed the definition of FARFUNC for Cosmic from
//          @far to nothing.  A compiler optin is used to force
//          all functions to be far(banked) unless NEARFUNC is used
//          so FARFUNC can be nothing just as in IAR.
//
//  Clearcase main\28 14-June-2006 WFD
//          Changed so that the IAR compiler does not generate a warning
//          for the change in version main\27
//
//  Clearcase main\27 12-June-2006 WFD
//          Changed so that the check for the Cosmic Compiler versions
//          does not generate a QAC warning
//
//  Clearcase main\26 15-May-2006 WFD
//          added version check for Cosmic compiler
//
//  Clearcase main\25 12-May-2006 WFD
//          added support for Cosmic compiler
//
//  Clearcase main\24 26-January-2006 WFD
//          added support for HC9312CHZ512 and 32MHz, 40Mhz ECLK frequencies
//
//  Clearcase main\23 25-May-2005 WFD
//          added defines for IS_TRUE and IS_FALSE
//
//  Clearcase main\22 21-Mar-2005 TGB
//          (1) added macro definitions for in-line delays for the
//              star-12 (HC12) processor.
//          (2) reduced complexity of this file by eliminating the place-holder
//              support for other processors and tool systems.
//
//  Clearcase main\21 03-Nov-2004 wfd
//                  added support for HZ256, HZ192, HZ128, HZ64, HZ32, HN128, HN64, & HN32
//                  and iar 2.44
//
//  Clearcase main\20 10-Aug-2004 wfd
//                  added support for DT512
//
//  PVCS Rev 1.17   05-Dec-2003 TGB
//                  Fixed type introduced in 1.15
//
//  PVCS Rev 1.16   05-Dec-2003 TGB
//                  Deleted several definitions from this file, after agreement
//                  reached by Greg Palarski, Tom Burke, Bill Derouchie, Jeff Kanoza.
//
//  PVCS Rev 1.15   05-Dec-2003 WFD
//                  Added support for IAR 2.43
//
//  PVCS Rev 1.14   27-Sep-2002 WFD
//                  Changed UINT16 and SINT16 to have SHORT as base type instead of INT
//
//  PVCS Rev 1.13   04-Sep-2002 JTK
//                  Cleanup to eliminate QAC warnings:
//                  - Removed redundant typecasts and cleaned up MS_x_BITS and
//                    LS_x_BITS macros.
//                  - Changed CLEARBIT and TESTBIT.
//                  - Removed the 'u' suffix from the BIT0 - BIT7 definitions.
//                  - Changed 'U' suffixes to 'u'.
//
//  PVCS Rev 1.12   19-Noc-2001 WFD
//                  Changed MCU_REGBASE values for Makos from 0x3800 to 0x3000
//
//  PVCS Rev 1.11    08-Sept-2001 WFD
//                  Added derivation of MCU_ECLK_IN_MHZ from MCU_ECLK_MHZ
//
//  PVCS Rev 1.10   12-July-2001 wfd
//                  (1) Changed Macro names for Star12s to MC9S12yxx form
//
//  PVCS Rev 1.9    06/Jun 2001 LSX
//                  Changed definitions of FALSE and TRUE to BOOLEAN type.
//
//  PVCS Rev 1.8    27/Mar 2001 WFD
//                  Allow version 2.41 of IAR compiler for HC12 and Star12
//
//  PVCS Rev 1.7    27/Mar 2001 WFD
//                  Allow version 2.40 of IAR compiler for HC12
//
//  PVCS Rev 1.6    05/Feb 2001 LSX
//                  Added revision for the first revision of CST-12.
//
//  PVCS Rev 1.5    07-Oct 2000 WFD
//
//  PVCS Rev 1.4    15-Sep 2000 WFD
//                  Added support for Barracuda DP256
//                  and Makos HB64, HC128, and HD256
//
//  PVCS Rev 1.3    30-Nov 1999 PKR
//                  Changed definition of 'FAR' for the IAR 68HC12 variants
//                  to resolve a conflict with named segments.  Data stores
//                  defined in a named segment are not allocated in that
//                  segment when the type modifier 'npage' is used (abstracted
//                  by the 'FAR' macro).
//
//  PVCS Rev 1.2    08-Oct 1999 PKR
//                  Added definition of MCU_REGBASE (IAR, 68HC12 only).
//                  This is a temporary change to support X400.  The
//                  final package will not support this in the same
//                  manner.
//
//  PVCS Rev 1.1    01-Oct 1999 PKR
//                  Removed include of mcu_preg.h
//
//  PVCS Rev 1.0    24-Sep 1999 PKR
//                  First baseline version to be used for initial development
//                  of banked systems.  This is not an officially released
//                  version.
//
// =========================================================================*/
#endif
#endif
#ifdef __COSMIC_SYSTEMS_ASM
list   ; in system.h
#endif
