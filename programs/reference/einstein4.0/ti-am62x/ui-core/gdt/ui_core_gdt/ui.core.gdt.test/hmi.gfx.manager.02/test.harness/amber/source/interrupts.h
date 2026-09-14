/******************************************************************************
 * $Revision: 10544 $
 * $Date:: 2014-09-16 10:22:04 +0200#$
 *****************************************************************************/
/* __DISCLAIMER_START__                                                      */
/******************************************************************************
* Copyright (C) 2014 Spansion LLC. All Rights Reserved. 
*
* This software is owned and published by: 
* Spansion LLC, 915 DeGuigne Dr. Sunnyvale, CA  94088-3453 ("Spansion").
*
* BY DOWNLOADING, INSTALLING OR USING THIS SOFTWARE, YOU AGREE TO BE BOUND 
* BY ALL THE TERMS AND CONDITIONS OF THIS AGREEMENT.
*
* This software contains source code for use with Spansion 
* components. This software is licensed by Spansion to be adapted only 
* for use in systems utilizing Spansion components. Spansion shall not be 
* responsible for misuse or illegal use of this software for devices not 
* supported herein.  Spansion is providing this software "AS IS" and will 
* not be responsible for issues arising from incorrect user implementation 
* of the software.  
*
* SPANSION MAKES NO WARRANTY, EXPRESS OR IMPLIED, ARISING BY LAW OR OTHERWISE,
* REGARDING THE SOFTWARE (INCLUDING ANY ACOOMPANYING WRITTEN MATERIALS), 
* ITS PERFORMANCE OR SUITABILITY FOR YOUR INTENDED USE, INCLUDING, 
* WITHOUT LIMITATION, THE IMPLIED WARRANTY OF MERCHANTABILITY, THE IMPLIED 
* WARRANTY OF FITNESS FOR A PARTICULAR PURPOSE OR USE, AND THE IMPLIED 
* WARRANTY OF NONINFRINGEMENT.  
* SPANSION SHALL HAVE NO LIABILITY (WHETHER IN CONTRACT, WARRANTY, TORT, 
* NEGLIGENCE OR OTHERWISE) FOR ANY DAMAGES WHATSOEVER (INCLUDING, WITHOUT 
* LIMITATION, DAMAGES FOR LOSS OF BUSINESS PROFITS, BUSINESS INTERRUPTION, 
* LOSS OF BUSINESS INFORMATION, OR OTHER PECUNIARY LOSS) ARISING FROM USE OR 
* INABILITY TO USE THE SOFTWARE, INCLUDING, WITHOUT LIMITATION, ANY DIRECT, 
* INDIRECT, INCIDENTAL, SPECIAL OR CONSEQUENTIAL DAMAGES OR LOSS OF DATA, 
* SAVINGS OR PROFITS, 
* EVEN IF SPANSION HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES. 
* YOU ASSUME ALL RESPONSIBILITIES FOR SELECTION OF THE SOFTWARE TO ACHIEVE YOUR
* INTENDED RESULTS, AND FOR THE INSTALLATION OF, USE OF, AND RESULTS OBTAINED 
* FROM, THE SOFTWARE.  
*
* This software may be replicated in part or whole for the licensed use, 
* with the restriction that this Disclaimer and Copyright notice must be 
* included with each copy of this software, whether used in part or whole, 
* at all times.
******************************************************************************/
/* __DISCLAIMER_END__                                                        */
/*****************************************************************************/
/** \file interrupts.h
 **
 ** Declaration of IRQ and NMI entry/exit macros, Interrupt Controller
 ** initialization and service functions as well as assignment of interrupt
 ** vectors and levels for IRQs and NMIs.
 **
 ** Please edit the following sections in this file:
 **     1   IRQ
 **     1.1 IRQ Nesting
 **     1.2 IRQ Vectors
 **     1.3 IRQ Priority Levels
 **     1.4 IRQ Numbers
 **     2   NMI
 **     2.1 NMI Vectors
 **     2.2 NMI Numbers
 **     2.3 NMI Priority Levels
 **
 ** The assignment of interrupt (IRQ) and non-maskable interrupt (NMI)
 ** vectors and priority levels can be done here by changing the appropriate
 ** pre-processor symbols:
 **
 ** For IRQ:
 **     - assign the ISR function to INTERRUPTS_IRQ_ISR_???
 **     - set the IRQ level to INTERRUPTS_IRQ_LEVEL_???
 **
 ** For NMI:
 **     - assign the ISR function to INTERRUPTS_NMI_ISR_???
 **     - set the NMI level to INTERRUPTS_NMI_LEVEL_???
 **
 **
 ** It is recommended to follow the guideline below to implement an interrupt
 ** service routine (ISR). Use the macros available for IRQ and NMI function
 ** definition.
 **
 ** For IRQ ISR:
 **     An interrupt service routine (ISR) for IRQs should be implemented according
 **     to the following function skeleton:
 **
 **     When enable interrupt nesting and use GHS compiler:
 **         Currently, GHS compiler does not support interrupt nesting.
 **         Please use nested_interrupt.asm
 **
 **     When enable interrupt nesting and use IAR compiler:
 **
 **         FN_NESTED_IRQ_DEFINE_BEGIN(IrqIsrName, IrqNum)
 **         {
 **             // code to handle the IRQ
 **             // clear IRQ flag at source (peripheral or software interrupt)
 **
 **             // Current mode: System mode using system/user stack
 **             // (in case of default setting with interrupt nesting)
 **         }
 **         FN_NESTED_IRQ_DEFINE_END()
 **
 **     When disable interrupt nesting:
 **         FN_IRQ_DEFINE_BEGIN(IrqIsrName, IrqNum)
 **         {
 **             // code to handle the IRQ
 **             // clear IRQ flag at source (peripheral or software interrupt)
 **
 **             // Current mode: IRQ using IRQ stack
 **         }
 **         FN_IRQ_DEFINE_END()
 **
 **
 ** For NMI ISR:
 **     An interrupt service routine (ISR) for NMIs should be implemented according
 **     to the following function skeleton:
 **
 **     FN_NMI_DEFINE_BEGIN(NmiIsrName, NmiNum)
 **     {
 **         // code to handle the NMI
 **         // clear NMI flag at source (peripheral or software interrupt)
 **
 **         // Current mode: FIQ mode using FIQ stack
 **     }
 **     FN_NMI_DEFINE_END()
 **
 **
 ** History:
 **   - 2013-12-09  0.01  FTo  Initial version for Traveo
 **   - 2014-08-15  0.09  FTo  Some renames
 **   - 2014-09-03  0.10  CEy  Added NMI priority setup which was missing
 **   - 2014-09-15  0.12  CEy  Some cosmetic merges with the file coming used 
 **                            by PDL to allow faster merging in future
 *****************************************************************************/

#ifndef __INTERRUPTS_H__
#define __INTERRUPTS_H__

// File version 0xYYXX = vYY.XX
#define INTERRUPTS_H_VERSION          0x0012

#ifndef __FILE_VERSION_CHECK__

/*****************************************************************************/
/* Include files                                                             */
/*****************************************************************************/
#include "base_types.h"
#include "abstract.h"
#include "pdl.h"
#include "timer\timer.h"

/*****************************************************************************/
/* Global pre-processor symbols/macros ('#define')                           */
/*****************************************************************************/


/** Key to unlock the Interrupt Controller by writing to IRQn_UNLOCK register */
#define INTERRUPTS_INT_CTRL_KEY_UNLOCK             0x17ACC911
/** Key to lock the Interrupt Controller by writing to IRQn_UNLOCK register */
#define INTERRUPTS_INT_CTRL_KEY_LOCK               0x17B10C11

// -------------------------------------------------------------------
// M A C R O S   F O R   I N T E R R U P T S   ( I R Q )
// -------------------------------------------------------------------

/** Macro containing the function definition and entry code for an IRQ
 ** Interrupt service routine (ISR). This macro must be used to begin
 ** the definition of an IRQ ISR to place the required entry code and to
 ** re-enable interrupts for the Traveo CPU to allow interrupt nesting.
 ** Parameter IrqIsrName is the symbolic name of the function. Parameter
 ** IrqNum is the number of the handled interrupt (0...511).
 ** Each IRQ ISR defined with this macro must be closed by macro
 ** FN_IRQ_DEFINE_END().*/
#ifdef __TOOLCHAIN_GHS_MULTI__
    /** For GHS compiler, you can use nested_interrupt.asm if interrupt nesting is needed.*/
    #define FN_IRQ_DEFINE_BEGIN(IrqIsrName, IrqNum)             FN_IRQ_NOT_NESTED void IrqIsrName(void)\
                                                                {\
                                                                    const uint32_t u32IrqNumSetBy_FN_IRQ_DEFINE_BEGIN = IrqNum;
#else
    #define FN_IRQ_DEFINE_BEGIN(IrqIsrName, IrqNum)     FN_IRQ_NESTED void IrqIsrName(void)\
                                                        {\
                                                            const uint32_t u32IrqNumSetBy_FN_IRQ_DEFINE_BEGIN = IrqNum;\
                                                            IRQ_ENABLE();
#endif
                                                
/** Macro containing the exit code for an IRQ interrrupt service routine (ISR).
 ** This macro must be used in combination with FN_IRQ_DEFINE_BEGIN(). It will
 ** define the end of an IRQ ISR to disable interrupts for the Traveo CPU and to
 ** clear the interrupt hold bit of the handled interrupt in the Interrupt
 ** Controller. */
#ifdef __TOOLCHAIN_GHS_MULTI__
    #define FN_IRQ_DEFINE_END()                             IRC0_IRQHC = u32IrqNumSetBy_FN_IRQ_DEFINE_BEGIN;\
                                                        }
#else
    #define FN_IRQ_DEFINE_END()                             IRQ_DISABLE();\
                                                            IRC0_IRQHC = u32IrqNumSetBy_FN_IRQ_DEFINE_BEGIN;\
                                                        }
#endif

// -------------------------------------------------------------------------------
// M A C R O S   F O R   N O N - M A S K A B L E   I N T E R R U P T S   ( N M I )
// -------------------------------------------------------------------------------

/** Macro containing the function definition and entry code for an NMI
 ** interrrupt service routine (ISR). This macro must be used to begin
 ** the definition of an NMI ISR. Parameter NmiIsrName is the symbolic
 ** name of the function. Parameter NmiNum is the number of the handled
 ** NMI (0...31). Each NMI ISR defined with this macro must be closed
 ** by macro FN_NMI_DEFINE_END(). */
#define FN_NMI_DEFINE_BEGIN(NmiIsrName, NmiNum)     FN_NMI void NmiIsrName(void)\
                                                    {\
                                                        const uint32_t u32NmiNumSetBy_FN_NMI_DEFINE_BEGIN = NmiNum;\
                                            
/** Macro containing the exit code for an NMI interrupt service routine.
 ** This macro must be used in combination with FN_NMI_DEFINE_BEGIN(). It
 ** will define the end of an NMI ISR to clear the NMI hold bit of the
 ** handled NMI in the Interrupt Controller.  */
#define FN_NMI_DEFINE_END()                             IRC0_NMIHC = u32NmiNumSetBy_FN_NMI_DEFINE_BEGIN;\
                                                    }


// --------------------------------------------------------------------
// 1    I R Q
// --------------------------------------------------------------------
// 1.2  I R Q   V E C T O R S
// --------------------------------------------------------------------
// Assignment of interrupt vectors to interrupt service routines (ISR).
// The functions that are assigned here must be defined by using the
// macros FN_IRQ_DEFINE_BEGIN() ... FN_IRQ_DEFINE_END().
// or macros FN_NESTED_IRQ_DEFINE_BEGIN() ... FN_NESTED_IRQ_DEFINE_END().
// For GHS compiler, nested_interrupt.asm can be used.
//
// Note: If an interrupt is not used, please assign INTERRUPTS_IRQ_DEFAULT_HANDLER.
//       Otherwise assign your ISR function declared in the header file
//       included at the top of this file. An IRQ vector assigned to
//       INTERRUPTS_IRQ_DEFAULT_HANDLER will be disabled by default. If a 
//       user specific ISR is assigned, the appropriate IRQ will be
//       enabled.
// --------------------------------------------------------------------

/** Macro to assign an IRQ to the default IRQ handler, implemented
 ** in interrupts.c (DefaultIrqHandler). */
#define INTERRUPTS_IRQ_DEFAULT_HANDLER                      0xFFFFFFFF

#define INTERRUPTS_IRQ_ISR_0          INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#0
#define INTERRUPTS_IRQ_ISR_1          INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#1
#define INTERRUPTS_IRQ_ISR_2          PDL_IRQ_ISR_HWDG                ///< IRQ#2
#define INTERRUPTS_IRQ_ISR_3          PDL_IRQ_ISR_SWDG                ///< IRQ#3
#define INTERRUPTS_IRQ_ISR_4          INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#4
#define INTERRUPTS_IRQ_ISR_5          INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#5
#define INTERRUPTS_IRQ_ISR_6          INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#6
#define INTERRUPTS_IRQ_ISR_7          INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#7
#define INTERRUPTS_IRQ_ISR_8          INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#8
#define INTERRUPTS_IRQ_ISR_9          INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#9
#define INTERRUPTS_IRQ_ISR_10         INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#10
#define INTERRUPTS_IRQ_ISR_11         INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#11
#define INTERRUPTS_IRQ_ISR_12         INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#12
#define INTERRUPTS_IRQ_ISR_13         INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#13
#define INTERRUPTS_IRQ_ISR_14         INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#14
#define INTERRUPTS_IRQ_ISR_15         INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#15
#define INTERRUPTS_IRQ_ISR_16         INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#16
#define INTERRUPTS_IRQ_ISR_17         INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#17
#define INTERRUPTS_IRQ_ISR_18         INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#18
#define INTERRUPTS_IRQ_ISR_19         INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#19
#define INTERRUPTS_IRQ_ISR_20         INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#20
#define INTERRUPTS_IRQ_ISR_21         INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#21
#define INTERRUPTS_IRQ_ISR_22         INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#22
#define INTERRUPTS_IRQ_ISR_23         INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#23
#define INTERRUPTS_IRQ_ISR_24         PDL_IRQ_ISR_EIC0  ///< IRQ#24
#define INTERRUPTS_IRQ_ISR_25         PDL_IRQ_ISR_EIC1  ///< IRQ#25
#define INTERRUPTS_IRQ_ISR_26         PDL_IRQ_ISR_EIC2  ///< IRQ#26
#define INTERRUPTS_IRQ_ISR_27         PDL_IRQ_ISR_EIC3  ///< IRQ#27
#define INTERRUPTS_IRQ_ISR_28         PDL_IRQ_ISR_EIC4  ///< IRQ#28
#define INTERRUPTS_IRQ_ISR_29         PDL_IRQ_ISR_EIC5  ///< IRQ#29
#define INTERRUPTS_IRQ_ISR_30         PDL_IRQ_ISR_EIC6  ///< IRQ#30
#define INTERRUPTS_IRQ_ISR_31         PDL_IRQ_ISR_EIC7  ///< IRQ#31
#define INTERRUPTS_IRQ_ISR_32         PDL_IRQ_ISR_EIC8  ///< IRQ#32
#define INTERRUPTS_IRQ_ISR_33         PDL_IRQ_ISR_EIC9  ///< IRQ#33
#define INTERRUPTS_IRQ_ISR_34         PDL_IRQ_ISR_EIC10  ///< IRQ#34
#define INTERRUPTS_IRQ_ISR_35         PDL_IRQ_ISR_EIC11  ///< IRQ#35
#define INTERRUPTS_IRQ_ISR_36         PDL_IRQ_ISR_EIC12  ///< IRQ#36
#define INTERRUPTS_IRQ_ISR_37         PDL_IRQ_ISR_EIC13  ///< IRQ#37
#define INTERRUPTS_IRQ_ISR_38         PDL_IRQ_ISR_EIC14  ///< IRQ#38
#define INTERRUPTS_IRQ_ISR_39         PDL_IRQ_ISR_EIC15  ///< IRQ#39
#define INTERRUPTS_IRQ_ISR_40         INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#40
#define INTERRUPTS_IRQ_ISR_41         INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#41
#define INTERRUPTS_IRQ_ISR_42         INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#42
#define INTERRUPTS_IRQ_ISR_43         INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#43
#define INTERRUPTS_IRQ_ISR_44         INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#44
#define INTERRUPTS_IRQ_ISR_45         INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#45
#define INTERRUPTS_IRQ_ISR_46         INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#46
#define INTERRUPTS_IRQ_ISR_47         INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#47
#define INTERRUPTS_IRQ_ISR_48         INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#48
#define INTERRUPTS_IRQ_ISR_49         INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#49
#define INTERRUPTS_IRQ_ISR_50         INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#50
#define INTERRUPTS_IRQ_ISR_51         INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#51
#define INTERRUPTS_IRQ_ISR_52         INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#52
#define INTERRUPTS_IRQ_ISR_53         INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#53
#define INTERRUPTS_IRQ_ISR_54         INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#54
#define INTERRUPTS_IRQ_ISR_55         INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#55
#define INTERRUPTS_IRQ_ISR_56         PDL_IRQ_ISR_CANFD0  ///< IRQ#56
#define INTERRUPTS_IRQ_ISR_57         PDL_IRQ_ISR_CANFD1  ///< IRQ#57
#define INTERRUPTS_IRQ_ISR_58         INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#58
#define INTERRUPTS_IRQ_ISR_59         INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#59
#define INTERRUPTS_IRQ_ISR_60         INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#60
#define INTERRUPTS_IRQ_ISR_61         INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#61
#define INTERRUPTS_IRQ_ISR_62         INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#62
#define INTERRUPTS_IRQ_ISR_63         INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#63
#define INTERRUPTS_IRQ_ISR_64         PDL_IRQ_ISR_MFS0_RX  ///< IRQ#64
#define INTERRUPTS_IRQ_ISR_65         PDL_IRQ_ISR_MFS0_TX  ///< IRQ#65
#define INTERRUPTS_IRQ_ISR_66         PDL_IRQ_ISR_MFS1_RX  ///< IRQ#66
#define INTERRUPTS_IRQ_ISR_67         PDL_IRQ_ISR_MFS1_TX  ///< IRQ#67
#define INTERRUPTS_IRQ_ISR_68         PDL_IRQ_ISR_MFS2_RX  ///< IRQ#68
#define INTERRUPTS_IRQ_ISR_69         PDL_IRQ_ISR_MFS2_TX  ///< IRQ#69
#define INTERRUPTS_IRQ_ISR_70         PDL_IRQ_ISR_MFS3_RX  ///< IRQ#70
#define INTERRUPTS_IRQ_ISR_71         PDL_IRQ_ISR_MFS3_TX  ///< IRQ#71
#define INTERRUPTS_IRQ_ISR_72         PDL_IRQ_ISR_MFS4_RX  ///< IRQ#72
#define INTERRUPTS_IRQ_ISR_73         PDL_IRQ_ISR_MFS4_TX  ///< IRQ#73
#define INTERRUPTS_IRQ_ISR_74         INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#74
#define INTERRUPTS_IRQ_ISR_75         INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#75
#define INTERRUPTS_IRQ_ISR_76         INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#76
#define INTERRUPTS_IRQ_ISR_77         INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#77
#define INTERRUPTS_IRQ_ISR_78         INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#78
#define INTERRUPTS_IRQ_ISR_79         INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#79
#define INTERRUPTS_IRQ_ISR_80         PDL_IRQ_ISR_MFS8_RX   ///< IRQ#80
#define INTERRUPTS_IRQ_ISR_81         PDL_IRQ_ISR_MFS8_TX   ///< IRQ#81
#define INTERRUPTS_IRQ_ISR_82         PDL_IRQ_ISR_MFS9_RX   ///< IRQ#82
#define INTERRUPTS_IRQ_ISR_83         PDL_IRQ_ISR_MFS9_TX   ///< IRQ#83
#define INTERRUPTS_IRQ_ISR_84         PDL_IRQ_ISR_MFS10_RX  ///< IRQ#84
#define INTERRUPTS_IRQ_ISR_85         PDL_IRQ_ISR_MFS10_TX  ///< IRQ#85
#define INTERRUPTS_IRQ_ISR_86         PDL_IRQ_ISR_MFS11_RX  ///< IRQ#86
#define INTERRUPTS_IRQ_ISR_87         PDL_IRQ_ISR_MFS11_TX  ///< IRQ#87
#define INTERRUPTS_IRQ_ISR_88         PDL_IRQ_ISR_MFS12_RX  ///< IRQ#88
#define INTERRUPTS_IRQ_ISR_89         PDL_IRQ_ISR_MFS12_TX  ///< IRQ#89
#define INTERRUPTS_IRQ_ISR_90         INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#90
#define INTERRUPTS_IRQ_ISR_91         INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#91
#define INTERRUPTS_IRQ_ISR_92         INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#92
#define INTERRUPTS_IRQ_ISR_93         INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#93
#define INTERRUPTS_IRQ_ISR_94         INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#94
#define INTERRUPTS_IRQ_ISR_95         INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#95
#define INTERRUPTS_IRQ_ISR_96         INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#96
#define INTERRUPTS_IRQ_ISR_97         INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#97
#define INTERRUPTS_IRQ_ISR_98         INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#98
#define INTERRUPTS_IRQ_ISR_99         INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#99
#define INTERRUPTS_IRQ_ISR_100        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#100
#define INTERRUPTS_IRQ_ISR_101        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#101
#define INTERRUPTS_IRQ_ISR_102        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#102
#define INTERRUPTS_IRQ_ISR_103        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#103
#define INTERRUPTS_IRQ_ISR_104        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#104
#define INTERRUPTS_IRQ_ISR_105        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#105
#define INTERRUPTS_IRQ_ISR_106        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#106
#define INTERRUPTS_IRQ_ISR_107        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#107
#define INTERRUPTS_IRQ_ISR_108        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#108
#define INTERRUPTS_IRQ_ISR_109        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#109
#define INTERRUPTS_IRQ_ISR_110        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#110
#define INTERRUPTS_IRQ_ISR_111        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#111
#define INTERRUPTS_IRQ_ISR_112        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#112
#define INTERRUPTS_IRQ_ISR_113        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#113
#define INTERRUPTS_IRQ_ISR_114        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#114
#define INTERRUPTS_IRQ_ISR_115        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#115
#define INTERRUPTS_IRQ_ISR_116        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#116
#define INTERRUPTS_IRQ_ISR_117        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#117
#define INTERRUPTS_IRQ_ISR_118        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#118
#define INTERRUPTS_IRQ_ISR_119        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#119
#define INTERRUPTS_IRQ_ISR_120        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#120
#define INTERRUPTS_IRQ_ISR_121        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#121
#define INTERRUPTS_IRQ_ISR_122        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#122
#define INTERRUPTS_IRQ_ISR_123        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#123
#define INTERRUPTS_IRQ_ISR_124        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#124
#define INTERRUPTS_IRQ_ISR_125        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#125
#define INTERRUPTS_IRQ_ISR_126        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#126
#define INTERRUPTS_IRQ_ISR_127        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#127
#define INTERRUPTS_IRQ_ISR_128        PDL_IRQ_ISR_BT0  ///< IRQ#128
#define INTERRUPTS_IRQ_ISR_129        PDL_IRQ_ISR_BT1  ///< IRQ#129
#define INTERRUPTS_IRQ_ISR_130        PDL_IRQ_ISR_BT2  ///< IRQ#130
#define INTERRUPTS_IRQ_ISR_131        PDL_IRQ_ISR_BT3  ///< IRQ#131
#define INTERRUPTS_IRQ_ISR_132        PDL_IRQ_ISR_BT4  ///< IRQ#132
#define INTERRUPTS_IRQ_ISR_133        PDL_IRQ_ISR_BT5  ///< IRQ#133
#define INTERRUPTS_IRQ_ISR_134        PDL_IRQ_ISR_BT6  ///< IRQ#134
#define INTERRUPTS_IRQ_ISR_135        PDL_IRQ_ISR_BT7  ///< IRQ#135
#define INTERRUPTS_IRQ_ISR_136        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#136
#define INTERRUPTS_IRQ_ISR_137        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#137
#define INTERRUPTS_IRQ_ISR_138        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#138
#define INTERRUPTS_IRQ_ISR_139        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#139
#define INTERRUPTS_IRQ_ISR_140        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#140
#define INTERRUPTS_IRQ_ISR_141        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#141
#define INTERRUPTS_IRQ_ISR_142        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#142
#define INTERRUPTS_IRQ_ISR_143        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#143
#define INTERRUPTS_IRQ_ISR_144        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#144
#define INTERRUPTS_IRQ_ISR_145        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#145
#define INTERRUPTS_IRQ_ISR_146        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#146
#define INTERRUPTS_IRQ_ISR_147        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#147
#define INTERRUPTS_IRQ_ISR_148        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#148
#define INTERRUPTS_IRQ_ISR_149        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#149
#define INTERRUPTS_IRQ_ISR_150        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#150
#define INTERRUPTS_IRQ_ISR_151        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#151
#define INTERRUPTS_IRQ_ISR_152        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#152
#define INTERRUPTS_IRQ_ISR_153        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#153
#define INTERRUPTS_IRQ_ISR_154        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#154
#define INTERRUPTS_IRQ_ISR_155        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#155
#define INTERRUPTS_IRQ_ISR_156        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#156
#define INTERRUPTS_IRQ_ISR_157        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#157
#define INTERRUPTS_IRQ_ISR_158        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#158
#define INTERRUPTS_IRQ_ISR_159        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#159
#define INTERRUPTS_IRQ_ISR_160        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#160
#define INTERRUPTS_IRQ_ISR_161        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#161
#define INTERRUPTS_IRQ_ISR_162        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#162
#define INTERRUPTS_IRQ_ISR_163        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#163
#define INTERRUPTS_IRQ_ISR_164        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#164
#define INTERRUPTS_IRQ_ISR_165        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#165
#define INTERRUPTS_IRQ_ISR_166        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#166
#define INTERRUPTS_IRQ_ISR_167        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#167
#define INTERRUPTS_IRQ_ISR_168        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#168
#define INTERRUPTS_IRQ_ISR_169        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#169
#define INTERRUPTS_IRQ_ISR_170        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#170
#define INTERRUPTS_IRQ_ISR_171        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#171
#define INTERRUPTS_IRQ_ISR_172        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#172
#define INTERRUPTS_IRQ_ISR_173        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#173
#define INTERRUPTS_IRQ_ISR_174        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#174
#define INTERRUPTS_IRQ_ISR_175        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#175
#define INTERRUPTS_IRQ_ISR_176        PDL_IRQ_ISR_FRT0  ///< IRQ#176
#define INTERRUPTS_IRQ_ISR_177        PDL_IRQ_ISR_FRT1  ///< IRQ#177
#define INTERRUPTS_IRQ_ISR_178        PDL_IRQ_ISR_FRT2  ///< IRQ#178
#define INTERRUPTS_IRQ_ISR_179        PDL_IRQ_ISR_FRT3  ///< IRQ#179
#define INTERRUPTS_IRQ_ISR_180        PDL_IRQ_ISR_FRT4  ///< IRQ#180
#define INTERRUPTS_IRQ_ISR_181        PDL_IRQ_ISR_FRT5  ///< IRQ#181
#define INTERRUPTS_IRQ_ISR_182        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#182
#define INTERRUPTS_IRQ_ISR_183        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#183
#define INTERRUPTS_IRQ_ISR_184        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#184
#define INTERRUPTS_IRQ_ISR_185        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#185
#define INTERRUPTS_IRQ_ISR_186        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#186
#define INTERRUPTS_IRQ_ISR_187        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#187
#define INTERRUPTS_IRQ_ISR_188        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#188
#define INTERRUPTS_IRQ_ISR_189        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#189
#define INTERRUPTS_IRQ_ISR_190        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#190
#define INTERRUPTS_IRQ_ISR_191        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#191
#define INTERRUPTS_IRQ_ISR_192        PDL_IRQ_ISR_ICU0_0  ///< IRQ#192
#define INTERRUPTS_IRQ_ISR_193        PDL_IRQ_ISR_ICU1_0  ///< IRQ#193
#define INTERRUPTS_IRQ_ISR_194        PDL_IRQ_ISR_ICU2_0  ///< IRQ#194
#define INTERRUPTS_IRQ_ISR_195        PDL_IRQ_ISR_ICU3_0  ///< IRQ#195
#define INTERRUPTS_IRQ_ISR_196        PDL_IRQ_ISR_ICU4_0  ///< IRQ#196
#define INTERRUPTS_IRQ_ISR_197        PDL_IRQ_ISR_ICU5_0  ///< IRQ#197
#define INTERRUPTS_IRQ_ISR_198        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#198
#define INTERRUPTS_IRQ_ISR_199        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#199
#define INTERRUPTS_IRQ_ISR_200        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#200
#define INTERRUPTS_IRQ_ISR_201        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#201
#define INTERRUPTS_IRQ_ISR_202        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#202
#define INTERRUPTS_IRQ_ISR_203        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#203
#define INTERRUPTS_IRQ_ISR_204        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#204
#define INTERRUPTS_IRQ_ISR_205        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#205
#define INTERRUPTS_IRQ_ISR_206        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#206
#define INTERRUPTS_IRQ_ISR_207        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#207
#define INTERRUPTS_IRQ_ISR_208        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#208
#define INTERRUPTS_IRQ_ISR_209        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#209
#define INTERRUPTS_IRQ_ISR_210        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#210
#define INTERRUPTS_IRQ_ISR_211        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#211
#define INTERRUPTS_IRQ_ISR_212        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#212
#define INTERRUPTS_IRQ_ISR_213        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#213
#define INTERRUPTS_IRQ_ISR_214        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#214
#define INTERRUPTS_IRQ_ISR_215        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#215
#define INTERRUPTS_IRQ_ISR_216        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#216
#define INTERRUPTS_IRQ_ISR_217        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#217
#define INTERRUPTS_IRQ_ISR_218        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#218
#define INTERRUPTS_IRQ_ISR_219        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#219
#define INTERRUPTS_IRQ_ISR_220        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#220
#define INTERRUPTS_IRQ_ISR_221        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#221
#define INTERRUPTS_IRQ_ISR_222        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#222
#define INTERRUPTS_IRQ_ISR_223        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#223
#define INTERRUPTS_IRQ_ISR_224        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#224
#define INTERRUPTS_IRQ_ISR_225        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#225
#define INTERRUPTS_IRQ_ISR_226        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#226
#define INTERRUPTS_IRQ_ISR_227        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#227
#define INTERRUPTS_IRQ_ISR_228        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#228
#define INTERRUPTS_IRQ_ISR_229        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#229
#define INTERRUPTS_IRQ_ISR_230        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#230
#define INTERRUPTS_IRQ_ISR_231        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#231
#define INTERRUPTS_IRQ_ISR_232        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#232
#define INTERRUPTS_IRQ_ISR_233        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#233
#define INTERRUPTS_IRQ_ISR_234        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#234
#define INTERRUPTS_IRQ_ISR_235        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#235
#define INTERRUPTS_IRQ_ISR_236        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#236
#define INTERRUPTS_IRQ_ISR_237        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#237
#define INTERRUPTS_IRQ_ISR_238        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#238
#define INTERRUPTS_IRQ_ISR_239        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#239
#define INTERRUPTS_IRQ_ISR_240        PDL_IRQ_ISR_ICU0_1  ///< IRQ#240
#define INTERRUPTS_IRQ_ISR_241        PDL_IRQ_ISR_ICU1_1  ///< IRQ#241
#define INTERRUPTS_IRQ_ISR_242        PDL_IRQ_ISR_ICU2_1  ///< IRQ#242
#define INTERRUPTS_IRQ_ISR_243        PDL_IRQ_ISR_ICU3_1  ///< IRQ#243
#define INTERRUPTS_IRQ_ISR_244        PDL_IRQ_ISR_ICU4_1  ///< IRQ#244
#define INTERRUPTS_IRQ_ISR_245        PDL_IRQ_ISR_ICU5_1  ///< IRQ#245
#define INTERRUPTS_IRQ_ISR_246        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#246
#define INTERRUPTS_IRQ_ISR_247        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#247
#define INTERRUPTS_IRQ_ISR_248        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#248
#define INTERRUPTS_IRQ_ISR_249        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#249
#define INTERRUPTS_IRQ_ISR_250        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#250
#define INTERRUPTS_IRQ_ISR_251        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#251
#define INTERRUPTS_IRQ_ISR_252        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#252
#define INTERRUPTS_IRQ_ISR_253        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#253
#define INTERRUPTS_IRQ_ISR_254        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#254
#define INTERRUPTS_IRQ_ISR_255        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#255
#define INTERRUPTS_IRQ_ISR_256        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#256
#define INTERRUPTS_IRQ_ISR_257        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#257
#define INTERRUPTS_IRQ_ISR_258        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#258
#define INTERRUPTS_IRQ_ISR_259        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#259
#define INTERRUPTS_IRQ_ISR_260        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#260
#define INTERRUPTS_IRQ_ISR_261        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#261
#define INTERRUPTS_IRQ_ISR_262        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#262
#define INTERRUPTS_IRQ_ISR_263        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#263
#define INTERRUPTS_IRQ_ISR_264        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#264
#define INTERRUPTS_IRQ_ISR_265        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#265
#define INTERRUPTS_IRQ_ISR_266        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#266
#define INTERRUPTS_IRQ_ISR_267        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#267
#define INTERRUPTS_IRQ_ISR_268        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#268
#define INTERRUPTS_IRQ_ISR_269        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#269
#define INTERRUPTS_IRQ_ISR_270        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#270
#define INTERRUPTS_IRQ_ISR_271        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#271
#define INTERRUPTS_IRQ_ISR_272        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#272
#define INTERRUPTS_IRQ_ISR_273        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#273
#define INTERRUPTS_IRQ_ISR_274        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#274
#define INTERRUPTS_IRQ_ISR_275        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#275
#define INTERRUPTS_IRQ_ISR_276        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#276
#define INTERRUPTS_IRQ_ISR_277        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#277
#define INTERRUPTS_IRQ_ISR_278        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#278
#define INTERRUPTS_IRQ_ISR_279        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#279
#define INTERRUPTS_IRQ_ISR_280        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#280
#define INTERRUPTS_IRQ_ISR_281        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#281
#define INTERRUPTS_IRQ_ISR_282        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#282
#define INTERRUPTS_IRQ_ISR_283        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#283
#define INTERRUPTS_IRQ_ISR_284        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#284
#define INTERRUPTS_IRQ_ISR_285        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#285
#define INTERRUPTS_IRQ_ISR_286        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#286
#define INTERRUPTS_IRQ_ISR_287        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#287
#define INTERRUPTS_IRQ_ISR_288        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#288
#define INTERRUPTS_IRQ_ISR_289        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#289
#define INTERRUPTS_IRQ_ISR_290        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#290
#define INTERRUPTS_IRQ_ISR_291        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#291
#define INTERRUPTS_IRQ_ISR_292        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#292
#define INTERRUPTS_IRQ_ISR_293        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#293
#define INTERRUPTS_IRQ_ISR_294        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#294
#define INTERRUPTS_IRQ_ISR_295        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#295
#define INTERRUPTS_IRQ_ISR_296        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#296
#define INTERRUPTS_IRQ_ISR_297        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#297
#define INTERRUPTS_IRQ_ISR_298        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#298
#define INTERRUPTS_IRQ_ISR_299        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#299
#define INTERRUPTS_IRQ_ISR_300        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#300
#define INTERRUPTS_IRQ_ISR_301        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#301
#define INTERRUPTS_IRQ_ISR_302        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#302
#define INTERRUPTS_IRQ_ISR_303        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#303
#define INTERRUPTS_IRQ_ISR_304        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#304
#define INTERRUPTS_IRQ_ISR_305        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#305
#define INTERRUPTS_IRQ_ISR_306        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#306
#define INTERRUPTS_IRQ_ISR_307        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#307
#define INTERRUPTS_IRQ_ISR_308        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#308
#define INTERRUPTS_IRQ_ISR_309        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#309
#define INTERRUPTS_IRQ_ISR_310        Timer_Isr_MainSourceClockTimer  ///< IRQ#310
#define INTERRUPTS_IRQ_ISR_311        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#311
#define INTERRUPTS_IRQ_ISR_312        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#312
#define INTERRUPTS_IRQ_ISR_313        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#313
#define INTERRUPTS_IRQ_ISR_314        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#314
#define INTERRUPTS_IRQ_ISR_315        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#315
#define INTERRUPTS_IRQ_ISR_316        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#316
#define INTERRUPTS_IRQ_ISR_317        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#317
#define INTERRUPTS_IRQ_ISR_318        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#318
#define INTERRUPTS_IRQ_ISR_319        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#319
#define INTERRUPTS_IRQ_ISR_320        PDL_IRQ_ISR_MFS0_ERR  ///< IRQ#320
#define INTERRUPTS_IRQ_ISR_321        PDL_IRQ_ISR_MFS1_ERR  ///< IRQ#321
#define INTERRUPTS_IRQ_ISR_322        PDL_IRQ_ISR_MFS2_ERR  ///< IRQ#322
#define INTERRUPTS_IRQ_ISR_323        PDL_IRQ_ISR_MFS3_ERR  ///< IRQ#323
#define INTERRUPTS_IRQ_ISR_324        PDL_IRQ_ISR_MFS4_ERR  ///< IRQ#324
#define INTERRUPTS_IRQ_ISR_325        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#325
#define INTERRUPTS_IRQ_ISR_326        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#326
#define INTERRUPTS_IRQ_ISR_327        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#327
#define INTERRUPTS_IRQ_ISR_328        PDL_IRQ_ISR_MFS8_ERR   ///< IRQ#328
#define INTERRUPTS_IRQ_ISR_329        PDL_IRQ_ISR_MFS9_ERR   ///< IRQ#329
#define INTERRUPTS_IRQ_ISR_330        PDL_IRQ_ISR_MFS10_ERR  ///< IRQ#330
#define INTERRUPTS_IRQ_ISR_331        PDL_IRQ_ISR_MFS11_ERR  ///< IRQ#331
#define INTERRUPTS_IRQ_ISR_332        PDL_IRQ_ISR_MFS12_ERR  ///< IRQ#332
#define INTERRUPTS_IRQ_ISR_333        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#333
#define INTERRUPTS_IRQ_ISR_334        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#334
#define INTERRUPTS_IRQ_ISR_335        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#335
#define INTERRUPTS_IRQ_ISR_336        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#336
#define INTERRUPTS_IRQ_ISR_337        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#337
#define INTERRUPTS_IRQ_ISR_338        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#338
#define INTERRUPTS_IRQ_ISR_339        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#339
#define INTERRUPTS_IRQ_ISR_340        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#340
#define INTERRUPTS_IRQ_ISR_341        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#341
#define INTERRUPTS_IRQ_ISR_342        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#342
#define INTERRUPTS_IRQ_ISR_343        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#343
#define INTERRUPTS_IRQ_ISR_344        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#344
#define INTERRUPTS_IRQ_ISR_345        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#345
#define INTERRUPTS_IRQ_ISR_346        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#346
#define INTERRUPTS_IRQ_ISR_347        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#347
#define INTERRUPTS_IRQ_ISR_348        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#348
#define INTERRUPTS_IRQ_ISR_349        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#349
#define INTERRUPTS_IRQ_ISR_350        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#350
#define INTERRUPTS_IRQ_ISR_351        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#351
#define INTERRUPTS_IRQ_ISR_352        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#352
#define INTERRUPTS_IRQ_ISR_353        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#353
#define INTERRUPTS_IRQ_ISR_354        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#354
#define INTERRUPTS_IRQ_ISR_355        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#355
#define INTERRUPTS_IRQ_ISR_356        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#356
#define INTERRUPTS_IRQ_ISR_357        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#357
#define INTERRUPTS_IRQ_ISR_358        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#358
#define INTERRUPTS_IRQ_ISR_359        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#359
#define INTERRUPTS_IRQ_ISR_360        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#360
#define INTERRUPTS_IRQ_ISR_361        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#361
#define INTERRUPTS_IRQ_ISR_362        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#362
#define INTERRUPTS_IRQ_ISR_363        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#363
#define INTERRUPTS_IRQ_ISR_364        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#364
#define INTERRUPTS_IRQ_ISR_365        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#365
#define INTERRUPTS_IRQ_ISR_366        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#366
#define INTERRUPTS_IRQ_ISR_367        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#367
#define INTERRUPTS_IRQ_ISR_368        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#368
#define INTERRUPTS_IRQ_ISR_369        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#369
#define INTERRUPTS_IRQ_ISR_370        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#370
#define INTERRUPTS_IRQ_ISR_371        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#371
#define INTERRUPTS_IRQ_ISR_372        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#372
#define INTERRUPTS_IRQ_ISR_373        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#373
#define INTERRUPTS_IRQ_ISR_374        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#374
#define INTERRUPTS_IRQ_ISR_375        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#375
#define INTERRUPTS_IRQ_ISR_376        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#376
#define INTERRUPTS_IRQ_ISR_377        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#377
#define INTERRUPTS_IRQ_ISR_378        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#378
#define INTERRUPTS_IRQ_ISR_379        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#379
#define INTERRUPTS_IRQ_ISR_380        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#380
#define INTERRUPTS_IRQ_ISR_381        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#381
#define INTERRUPTS_IRQ_ISR_382        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#382
#define INTERRUPTS_IRQ_ISR_383        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#383
#define INTERRUPTS_IRQ_ISR_384        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#384
#define INTERRUPTS_IRQ_ISR_385        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#385
#define INTERRUPTS_IRQ_ISR_386        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#386
#define INTERRUPTS_IRQ_ISR_387        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#387
#define INTERRUPTS_IRQ_ISR_388        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#388
#define INTERRUPTS_IRQ_ISR_389        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#389
#define INTERRUPTS_IRQ_ISR_390        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#390
#define INTERRUPTS_IRQ_ISR_391        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#391
#define INTERRUPTS_IRQ_ISR_392        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#392
#define INTERRUPTS_IRQ_ISR_393        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#393
#define INTERRUPTS_IRQ_ISR_394        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#394
#define INTERRUPTS_IRQ_ISR_395        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#395
#define INTERRUPTS_IRQ_ISR_396        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#396
#define INTERRUPTS_IRQ_ISR_397        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#397
#define INTERRUPTS_IRQ_ISR_398        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#398
#define INTERRUPTS_IRQ_ISR_399        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#399
#define INTERRUPTS_IRQ_ISR_400        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#400
///KULI
#define INTERRUPTS_IRQ_ISR_401        GFXInterruptHandler401          ///< IRQ#401 2D Graphics Core Command Sequencer (incl. SW0, SW1)
#define INTERRUPTS_IRQ_ISR_402        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#402 2D Graphics Core Blit Engine
#define INTERRUPTS_IRQ_ISR_403        GFXInterruptHandler403          ///< IRQ#403 2D Graphics Core Drawing Engine (incl. SW2, SW3)
#define INTERRUPTS_IRQ_ISR_404        GFXInterruptHandler404          ///< IRQ#404 2D Graphics Core Content Stream0
#define INTERRUPTS_IRQ_ISR_405        GFXInterruptHandler405          ///< IRQ#405 2D Graphics Core Safety Stream0 (incl. FRAMEGEN0_INT0)
#define INTERRUPTS_IRQ_ISR_406        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#406 2D Graphics Core Display Stream0
#define INTERRUPTS_IRQ_ISR_407        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#407 2D Graphics Core Signature0
#define INTERRUPTS_IRQ_ISR_408        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#408 2D Graphics Core Display0 Sync0
#define INTERRUPTS_IRQ_ISR_409        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#409 2D Graphics Core Display0 Sync1
#define INTERRUPTS_IRQ_ISR_410        GFXInterruptHandler410          ///< IRQ#410 2D Graphics Core Content Stream1
#define INTERRUPTS_IRQ_ISR_411        GFXInterruptHandler411          ///< IRQ#411 2D Graphics Core Safety Stream1 (incl. FRAMEGEN1_INT0)
#define INTERRUPTS_IRQ_ISR_412        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#412 2D Graphics Core Display Stream1
#define INTERRUPTS_IRQ_ISR_413        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#413 2D Graphics Core Signature1
#define INTERRUPTS_IRQ_ISR_414        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#414 2D Graphics Core Display1 Sync0
#define INTERRUPTS_IRQ_ISR_415        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#415 2D Graphics Core Display1 Sync1
#define INTERRUPTS_IRQ_ISR_416        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#416 2D Graphics Core Capture Plane0
#define INTERRUPTS_IRQ_ISR_417        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#417 2D Graphics Core Display Plane0
#define INTERRUPTS_IRQ_ISR_418        GFXInterruptHandler418          ///< IRQ#418 2D Graphics Core Storage Stream0 (STORE4)
#define INTERRUPTS_IRQ_ISR_419        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#419 2D Graphics Core Histogram
#define INTERRUPTS_IRQ_ISR_420        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#420 2D Graphics Core DDRHSSPI
///KULI
#define INTERRUPTS_IRQ_ISR_421        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#421
#define INTERRUPTS_IRQ_ISR_422        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#422
#define INTERRUPTS_IRQ_ISR_423        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#423
#define INTERRUPTS_IRQ_ISR_424        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#424
#define INTERRUPTS_IRQ_ISR_425        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#425
#define INTERRUPTS_IRQ_ISR_426        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#426
#define INTERRUPTS_IRQ_ISR_427        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#427
#define INTERRUPTS_IRQ_ISR_428        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#428
#define INTERRUPTS_IRQ_ISR_429        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#429
#define INTERRUPTS_IRQ_ISR_430        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#430
#define INTERRUPTS_IRQ_ISR_431        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#431
#define INTERRUPTS_IRQ_ISR_432        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#432
#define INTERRUPTS_IRQ_ISR_433        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#433
#define INTERRUPTS_IRQ_ISR_434        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#434
#define INTERRUPTS_IRQ_ISR_435        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#435
#define INTERRUPTS_IRQ_ISR_436        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#436
#define INTERRUPTS_IRQ_ISR_437        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#437
#define INTERRUPTS_IRQ_ISR_438        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#438
#define INTERRUPTS_IRQ_ISR_439        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#439
#define INTERRUPTS_IRQ_ISR_440        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#440
#define INTERRUPTS_IRQ_ISR_441        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#441
#define INTERRUPTS_IRQ_ISR_442        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#442
#define INTERRUPTS_IRQ_ISR_443        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#443
#define INTERRUPTS_IRQ_ISR_444        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#444
#define INTERRUPTS_IRQ_ISR_445        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#445
#define INTERRUPTS_IRQ_ISR_446        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#446
#define INTERRUPTS_IRQ_ISR_447        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#447
#define INTERRUPTS_IRQ_ISR_448        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#448
#define INTERRUPTS_IRQ_ISR_449        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#449
#define INTERRUPTS_IRQ_ISR_450        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#450
#define INTERRUPTS_IRQ_ISR_451        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#451
#define INTERRUPTS_IRQ_ISR_452        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#452
#define INTERRUPTS_IRQ_ISR_453        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#453
#define INTERRUPTS_IRQ_ISR_454        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#454
#define INTERRUPTS_IRQ_ISR_455        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#455
#define INTERRUPTS_IRQ_ISR_456        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#456
#define INTERRUPTS_IRQ_ISR_457        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#457
#define INTERRUPTS_IRQ_ISR_458        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#458
#define INTERRUPTS_IRQ_ISR_459        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#459
#define INTERRUPTS_IRQ_ISR_460        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#460
#define INTERRUPTS_IRQ_ISR_461        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#461
#define INTERRUPTS_IRQ_ISR_462        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#462
#define INTERRUPTS_IRQ_ISR_463        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#463
#define INTERRUPTS_IRQ_ISR_464        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#464
#define INTERRUPTS_IRQ_ISR_465        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#465
#define INTERRUPTS_IRQ_ISR_466        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#466
#define INTERRUPTS_IRQ_ISR_467        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#467
#define INTERRUPTS_IRQ_ISR_468        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#468
#define INTERRUPTS_IRQ_ISR_469        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#469
#define INTERRUPTS_IRQ_ISR_470        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#470
#define INTERRUPTS_IRQ_ISR_471        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#471
#define INTERRUPTS_IRQ_ISR_472        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#472
#define INTERRUPTS_IRQ_ISR_473        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#473
#define INTERRUPTS_IRQ_ISR_474        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#474
#define INTERRUPTS_IRQ_ISR_475        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#475
#define INTERRUPTS_IRQ_ISR_476        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#476
#define INTERRUPTS_IRQ_ISR_477        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#477
#define INTERRUPTS_IRQ_ISR_478        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#478
#define INTERRUPTS_IRQ_ISR_479        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#479
#define INTERRUPTS_IRQ_ISR_480        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#480
#define INTERRUPTS_IRQ_ISR_481        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#481
#define INTERRUPTS_IRQ_ISR_482        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#482
#define INTERRUPTS_IRQ_ISR_483        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#483
#define INTERRUPTS_IRQ_ISR_484        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#484
#define INTERRUPTS_IRQ_ISR_485        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#485
#define INTERRUPTS_IRQ_ISR_486        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#486
#define INTERRUPTS_IRQ_ISR_487        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#487
#define INTERRUPTS_IRQ_ISR_488        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#488
#define INTERRUPTS_IRQ_ISR_489        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#489
#define INTERRUPTS_IRQ_ISR_490        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#490
#define INTERRUPTS_IRQ_ISR_491        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#491
#define INTERRUPTS_IRQ_ISR_492        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#492
#define INTERRUPTS_IRQ_ISR_493        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#493
#define INTERRUPTS_IRQ_ISR_494        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#494
#define INTERRUPTS_IRQ_ISR_495        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#495
#define INTERRUPTS_IRQ_ISR_496        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#496
#define INTERRUPTS_IRQ_ISR_497        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#497
#define INTERRUPTS_IRQ_ISR_498        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#498
#define INTERRUPTS_IRQ_ISR_499        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#499
#define INTERRUPTS_IRQ_ISR_500        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#500
#define INTERRUPTS_IRQ_ISR_501        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#501
#define INTERRUPTS_IRQ_ISR_502        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#502
#define INTERRUPTS_IRQ_ISR_503        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#503
#define INTERRUPTS_IRQ_ISR_504        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#504
#define INTERRUPTS_IRQ_ISR_505        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#505
#define INTERRUPTS_IRQ_ISR_506        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#506
#define INTERRUPTS_IRQ_ISR_507        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#507
#define INTERRUPTS_IRQ_ISR_508        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#508
#define INTERRUPTS_IRQ_ISR_509        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#509
#define INTERRUPTS_IRQ_ISR_510        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#510
#define INTERRUPTS_IRQ_ISR_511        INTERRUPTS_IRQ_DEFAULT_HANDLER  ///< IRQ#511

// --------------------------------------------------------------------
// 1.3  I R Q   P R I O R I T Y   L E V E L S
// --------------------------------------------------------------------
// Definition of interrupt priorities.
// Level 0 (highest priority) ... 31 (lowest priority)
// Note: If an IRQ vector is assigned to the default IRQ
//       handler (INTERRUPTS_IRQ_DEFAULT_HANDLER) the corresponding
//       interrupt priority will always be set to 31, irrespective
//       of the setting here.
// --------------------------------------------------------------------

#define INTERRUPTS_IRQ_LEVEL_0              31        ///< IRQ#0
#define INTERRUPTS_IRQ_LEVEL_1              31        ///< IRQ#1
#define INTERRUPTS_IRQ_LEVEL_2              31        ///< IRQ#2
#define INTERRUPTS_IRQ_LEVEL_3              31        ///< IRQ#3
#define INTERRUPTS_IRQ_LEVEL_4              31        ///< IRQ#4
#define INTERRUPTS_IRQ_LEVEL_5              31        ///< IRQ#5
#define INTERRUPTS_IRQ_LEVEL_6              31        ///< IRQ#6
#define INTERRUPTS_IRQ_LEVEL_7              31        ///< IRQ#7
#define INTERRUPTS_IRQ_LEVEL_8              31        ///< IRQ#8
#define INTERRUPTS_IRQ_LEVEL_9              31        ///< IRQ#9
#define INTERRUPTS_IRQ_LEVEL_10             31        ///< IRQ#10
#define INTERRUPTS_IRQ_LEVEL_11             31        ///< IRQ#11
#define INTERRUPTS_IRQ_LEVEL_12             31        ///< IRQ#12
#define INTERRUPTS_IRQ_LEVEL_13             31        ///< IRQ#13
#define INTERRUPTS_IRQ_LEVEL_14             31        ///< IRQ#14
#define INTERRUPTS_IRQ_LEVEL_15             31        ///< IRQ#15
#define INTERRUPTS_IRQ_LEVEL_16             31        ///< IRQ#16
#define INTERRUPTS_IRQ_LEVEL_17             31        ///< IRQ#17
#define INTERRUPTS_IRQ_LEVEL_18             31        ///< IRQ#18
#define INTERRUPTS_IRQ_LEVEL_19             31        ///< IRQ#19
#define INTERRUPTS_IRQ_LEVEL_20             31        ///< IRQ#20
#define INTERRUPTS_IRQ_LEVEL_21             31        ///< IRQ#21
#define INTERRUPTS_IRQ_LEVEL_22             31        ///< IRQ#22
#define INTERRUPTS_IRQ_LEVEL_23             31        ///< IRQ#23
#define INTERRUPTS_IRQ_LEVEL_24             31        ///< IRQ#24
#define INTERRUPTS_IRQ_LEVEL_25             31        ///< IRQ#25
#define INTERRUPTS_IRQ_LEVEL_26             31        ///< IRQ#26
#define INTERRUPTS_IRQ_LEVEL_27             31        ///< IRQ#27
#define INTERRUPTS_IRQ_LEVEL_28             31        ///< IRQ#28
#define INTERRUPTS_IRQ_LEVEL_29             31        ///< IRQ#29
#define INTERRUPTS_IRQ_LEVEL_30             31        ///< IRQ#30
#define INTERRUPTS_IRQ_LEVEL_31             31        ///< IRQ#31
#define INTERRUPTS_IRQ_LEVEL_32             31        ///< IRQ#32
#define INTERRUPTS_IRQ_LEVEL_33             31        ///< IRQ#33
#define INTERRUPTS_IRQ_LEVEL_34             31        ///< IRQ#34
#define INTERRUPTS_IRQ_LEVEL_35             31        ///< IRQ#35
#define INTERRUPTS_IRQ_LEVEL_36             31        ///< IRQ#36
#define INTERRUPTS_IRQ_LEVEL_37             31        ///< IRQ#37
#define INTERRUPTS_IRQ_LEVEL_38             31        ///< IRQ#38
#define INTERRUPTS_IRQ_LEVEL_39             31        ///< IRQ#39
#define INTERRUPTS_IRQ_LEVEL_40             31        ///< IRQ#40
#define INTERRUPTS_IRQ_LEVEL_41             31        ///< IRQ#41
#define INTERRUPTS_IRQ_LEVEL_42             31        ///< IRQ#42
#define INTERRUPTS_IRQ_LEVEL_43             31        ///< IRQ#43
#define INTERRUPTS_IRQ_LEVEL_44             31        ///< IRQ#44
#define INTERRUPTS_IRQ_LEVEL_45             31        ///< IRQ#45
#define INTERRUPTS_IRQ_LEVEL_46             31        ///< IRQ#46
#define INTERRUPTS_IRQ_LEVEL_47             31        ///< IRQ#47
#define INTERRUPTS_IRQ_LEVEL_48             31        ///< IRQ#48
#define INTERRUPTS_IRQ_LEVEL_49             31        ///< IRQ#49
#define INTERRUPTS_IRQ_LEVEL_50             31        ///< IRQ#50
#define INTERRUPTS_IRQ_LEVEL_51             31        ///< IRQ#51
#define INTERRUPTS_IRQ_LEVEL_52             31        ///< IRQ#52
#define INTERRUPTS_IRQ_LEVEL_53             31        ///< IRQ#53
#define INTERRUPTS_IRQ_LEVEL_54             31        ///< IRQ#54
#define INTERRUPTS_IRQ_LEVEL_55             31        ///< IRQ#55
#define INTERRUPTS_IRQ_LEVEL_56             31        ///< IRQ#56
#define INTERRUPTS_IRQ_LEVEL_57             31        ///< IRQ#57
#define INTERRUPTS_IRQ_LEVEL_58             31        ///< IRQ#58
#define INTERRUPTS_IRQ_LEVEL_59             31        ///< IRQ#59
#define INTERRUPTS_IRQ_LEVEL_60             31        ///< IRQ#60
#define INTERRUPTS_IRQ_LEVEL_61             31        ///< IRQ#61
#define INTERRUPTS_IRQ_LEVEL_62             31        ///< IRQ#62
#define INTERRUPTS_IRQ_LEVEL_63             31        ///< IRQ#63
#define INTERRUPTS_IRQ_LEVEL_64             31        ///< IRQ#64
#define INTERRUPTS_IRQ_LEVEL_65             31        ///< IRQ#65
#define INTERRUPTS_IRQ_LEVEL_66             31        ///< IRQ#66
#define INTERRUPTS_IRQ_LEVEL_67             31        ///< IRQ#67
#define INTERRUPTS_IRQ_LEVEL_68             31        ///< IRQ#68
#define INTERRUPTS_IRQ_LEVEL_69             31        ///< IRQ#69
#define INTERRUPTS_IRQ_LEVEL_70             31        ///< IRQ#70
#define INTERRUPTS_IRQ_LEVEL_71             31        ///< IRQ#71
#define INTERRUPTS_IRQ_LEVEL_72             31        ///< IRQ#72
#define INTERRUPTS_IRQ_LEVEL_73             31        ///< IRQ#73
#define INTERRUPTS_IRQ_LEVEL_74             31        ///< IRQ#74
#define INTERRUPTS_IRQ_LEVEL_75             31        ///< IRQ#75
#define INTERRUPTS_IRQ_LEVEL_76             31        ///< IRQ#76
#define INTERRUPTS_IRQ_LEVEL_77             31        ///< IRQ#77
#define INTERRUPTS_IRQ_LEVEL_78             31        ///< IRQ#78
#define INTERRUPTS_IRQ_LEVEL_79             31        ///< IRQ#79
#define INTERRUPTS_IRQ_LEVEL_80             31        ///< IRQ#80
#define INTERRUPTS_IRQ_LEVEL_81             31        ///< IRQ#81
#define INTERRUPTS_IRQ_LEVEL_82             31        ///< IRQ#82
#define INTERRUPTS_IRQ_LEVEL_83             31        ///< IRQ#83
#define INTERRUPTS_IRQ_LEVEL_84             31        ///< IRQ#84
#define INTERRUPTS_IRQ_LEVEL_85             31        ///< IRQ#85
#define INTERRUPTS_IRQ_LEVEL_86             31        ///< IRQ#86
#define INTERRUPTS_IRQ_LEVEL_87             31        ///< IRQ#87
#define INTERRUPTS_IRQ_LEVEL_88             31        ///< IRQ#88
#define INTERRUPTS_IRQ_LEVEL_89             31        ///< IRQ#89
#define INTERRUPTS_IRQ_LEVEL_90             31        ///< IRQ#90
#define INTERRUPTS_IRQ_LEVEL_91             31        ///< IRQ#91
#define INTERRUPTS_IRQ_LEVEL_92             31        ///< IRQ#92
#define INTERRUPTS_IRQ_LEVEL_93             31        ///< IRQ#93
#define INTERRUPTS_IRQ_LEVEL_94             31        ///< IRQ#94
#define INTERRUPTS_IRQ_LEVEL_95             31        ///< IRQ#95
#define INTERRUPTS_IRQ_LEVEL_96             31        ///< IRQ#96
#define INTERRUPTS_IRQ_LEVEL_97             31        ///< IRQ#97
#define INTERRUPTS_IRQ_LEVEL_98             31        ///< IRQ#98
#define INTERRUPTS_IRQ_LEVEL_99             31        ///< IRQ#99
#define INTERRUPTS_IRQ_LEVEL_100            31        ///< IRQ#100
#define INTERRUPTS_IRQ_LEVEL_101            31        ///< IRQ#101
#define INTERRUPTS_IRQ_LEVEL_102            31        ///< IRQ#102
#define INTERRUPTS_IRQ_LEVEL_103            31        ///< IRQ#103
#define INTERRUPTS_IRQ_LEVEL_104            31        ///< IRQ#104
#define INTERRUPTS_IRQ_LEVEL_105            31        ///< IRQ#105
#define INTERRUPTS_IRQ_LEVEL_106            31        ///< IRQ#106
#define INTERRUPTS_IRQ_LEVEL_107            31        ///< IRQ#107
#define INTERRUPTS_IRQ_LEVEL_108            31        ///< IRQ#108
#define INTERRUPTS_IRQ_LEVEL_109            31        ///< IRQ#109
#define INTERRUPTS_IRQ_LEVEL_110            31        ///< IRQ#110
#define INTERRUPTS_IRQ_LEVEL_111            31        ///< IRQ#111
#define INTERRUPTS_IRQ_LEVEL_112            31        ///< IRQ#112
#define INTERRUPTS_IRQ_LEVEL_113            31        ///< IRQ#113
#define INTERRUPTS_IRQ_LEVEL_114            31        ///< IRQ#114
#define INTERRUPTS_IRQ_LEVEL_115            31        ///< IRQ#115
#define INTERRUPTS_IRQ_LEVEL_116            31        ///< IRQ#116
#define INTERRUPTS_IRQ_LEVEL_117            31        ///< IRQ#117
#define INTERRUPTS_IRQ_LEVEL_118            31        ///< IRQ#118
#define INTERRUPTS_IRQ_LEVEL_119            31        ///< IRQ#119
#define INTERRUPTS_IRQ_LEVEL_120            31        ///< IRQ#120
#define INTERRUPTS_IRQ_LEVEL_121            31        ///< IRQ#121
#define INTERRUPTS_IRQ_LEVEL_122            31        ///< IRQ#122
#define INTERRUPTS_IRQ_LEVEL_123            31        ///< IRQ#123
#define INTERRUPTS_IRQ_LEVEL_124            31        ///< IRQ#124
#define INTERRUPTS_IRQ_LEVEL_125            31        ///< IRQ#125
#define INTERRUPTS_IRQ_LEVEL_126            31        ///< IRQ#126
#define INTERRUPTS_IRQ_LEVEL_127            31        ///< IRQ#127
#define INTERRUPTS_IRQ_LEVEL_128            31        ///< IRQ#128
#define INTERRUPTS_IRQ_LEVEL_129            31        ///< IRQ#129
#define INTERRUPTS_IRQ_LEVEL_130            31        ///< IRQ#130
#define INTERRUPTS_IRQ_LEVEL_131            31        ///< IRQ#131
#define INTERRUPTS_IRQ_LEVEL_132            31        ///< IRQ#132
#define INTERRUPTS_IRQ_LEVEL_133            31        ///< IRQ#133
#define INTERRUPTS_IRQ_LEVEL_134            31        ///< IRQ#134
#define INTERRUPTS_IRQ_LEVEL_135            31        ///< IRQ#135
#define INTERRUPTS_IRQ_LEVEL_136            31        ///< IRQ#136
#define INTERRUPTS_IRQ_LEVEL_137            31        ///< IRQ#137
#define INTERRUPTS_IRQ_LEVEL_138            31        ///< IRQ#138
#define INTERRUPTS_IRQ_LEVEL_139            31        ///< IRQ#139
#define INTERRUPTS_IRQ_LEVEL_140            31        ///< IRQ#140
#define INTERRUPTS_IRQ_LEVEL_141            31        ///< IRQ#141
#define INTERRUPTS_IRQ_LEVEL_142            31        ///< IRQ#142
#define INTERRUPTS_IRQ_LEVEL_143            31        ///< IRQ#143
#define INTERRUPTS_IRQ_LEVEL_144            31        ///< IRQ#144
#define INTERRUPTS_IRQ_LEVEL_145            31        ///< IRQ#145
#define INTERRUPTS_IRQ_LEVEL_146            31        ///< IRQ#146
#define INTERRUPTS_IRQ_LEVEL_147            31        ///< IRQ#147
#define INTERRUPTS_IRQ_LEVEL_148            31        ///< IRQ#148
#define INTERRUPTS_IRQ_LEVEL_149            31        ///< IRQ#149
#define INTERRUPTS_IRQ_LEVEL_150            31        ///< IRQ#150
#define INTERRUPTS_IRQ_LEVEL_151            31        ///< IRQ#151
#define INTERRUPTS_IRQ_LEVEL_152            31        ///< IRQ#152
#define INTERRUPTS_IRQ_LEVEL_153            31        ///< IRQ#153
#define INTERRUPTS_IRQ_LEVEL_154            31        ///< IRQ#154
#define INTERRUPTS_IRQ_LEVEL_155            31        ///< IRQ#155
#define INTERRUPTS_IRQ_LEVEL_156            31        ///< IRQ#156
#define INTERRUPTS_IRQ_LEVEL_157            31        ///< IRQ#157
#define INTERRUPTS_IRQ_LEVEL_158            31        ///< IRQ#158
#define INTERRUPTS_IRQ_LEVEL_159            31        ///< IRQ#159
#define INTERRUPTS_IRQ_LEVEL_160            31        ///< IRQ#160
#define INTERRUPTS_IRQ_LEVEL_161            31        ///< IRQ#161
#define INTERRUPTS_IRQ_LEVEL_162            31        ///< IRQ#162
#define INTERRUPTS_IRQ_LEVEL_163            31        ///< IRQ#163
#define INTERRUPTS_IRQ_LEVEL_164            31        ///< IRQ#164
#define INTERRUPTS_IRQ_LEVEL_165            31        ///< IRQ#165
#define INTERRUPTS_IRQ_LEVEL_166            31        ///< IRQ#166
#define INTERRUPTS_IRQ_LEVEL_167            31        ///< IRQ#167
#define INTERRUPTS_IRQ_LEVEL_168            31        ///< IRQ#168
#define INTERRUPTS_IRQ_LEVEL_169            31        ///< IRQ#169
#define INTERRUPTS_IRQ_LEVEL_170            31        ///< IRQ#170
#define INTERRUPTS_IRQ_LEVEL_171            31        ///< IRQ#171
#define INTERRUPTS_IRQ_LEVEL_172            31        ///< IRQ#172
#define INTERRUPTS_IRQ_LEVEL_173            31        ///< IRQ#173
#define INTERRUPTS_IRQ_LEVEL_174            31        ///< IRQ#174
#define INTERRUPTS_IRQ_LEVEL_175            31        ///< IRQ#175
#define INTERRUPTS_IRQ_LEVEL_176            31        ///< IRQ#176
#define INTERRUPTS_IRQ_LEVEL_177            31        ///< IRQ#177
#define INTERRUPTS_IRQ_LEVEL_178            31        ///< IRQ#178
#define INTERRUPTS_IRQ_LEVEL_179            31        ///< IRQ#179
#define INTERRUPTS_IRQ_LEVEL_180            31        ///< IRQ#180
#define INTERRUPTS_IRQ_LEVEL_181            31        ///< IRQ#181
#define INTERRUPTS_IRQ_LEVEL_182            31        ///< IRQ#182
#define INTERRUPTS_IRQ_LEVEL_183            31        ///< IRQ#183
#define INTERRUPTS_IRQ_LEVEL_184            31        ///< IRQ#184
#define INTERRUPTS_IRQ_LEVEL_185            31        ///< IRQ#185
#define INTERRUPTS_IRQ_LEVEL_186            31        ///< IRQ#186
#define INTERRUPTS_IRQ_LEVEL_187            31        ///< IRQ#187
#define INTERRUPTS_IRQ_LEVEL_188            31        ///< IRQ#188
#define INTERRUPTS_IRQ_LEVEL_189            31        ///< IRQ#189
#define INTERRUPTS_IRQ_LEVEL_190            31        ///< IRQ#190
#define INTERRUPTS_IRQ_LEVEL_191            31        ///< IRQ#191
#define INTERRUPTS_IRQ_LEVEL_192            31        ///< IRQ#192
#define INTERRUPTS_IRQ_LEVEL_193            31        ///< IRQ#193
#define INTERRUPTS_IRQ_LEVEL_194            31        ///< IRQ#194
#define INTERRUPTS_IRQ_LEVEL_195            31        ///< IRQ#195
#define INTERRUPTS_IRQ_LEVEL_196            31        ///< IRQ#196
#define INTERRUPTS_IRQ_LEVEL_197            31        ///< IRQ#197
#define INTERRUPTS_IRQ_LEVEL_198            31        ///< IRQ#198
#define INTERRUPTS_IRQ_LEVEL_199            31        ///< IRQ#199
#define INTERRUPTS_IRQ_LEVEL_200            31        ///< IRQ#200
#define INTERRUPTS_IRQ_LEVEL_201            31        ///< IRQ#201
#define INTERRUPTS_IRQ_LEVEL_202            31        ///< IRQ#202
#define INTERRUPTS_IRQ_LEVEL_203            31        ///< IRQ#203
#define INTERRUPTS_IRQ_LEVEL_204            31        ///< IRQ#204
#define INTERRUPTS_IRQ_LEVEL_205            31        ///< IRQ#205
#define INTERRUPTS_IRQ_LEVEL_206            31        ///< IRQ#206
#define INTERRUPTS_IRQ_LEVEL_207            31        ///< IRQ#207
#define INTERRUPTS_IRQ_LEVEL_208            31        ///< IRQ#208
#define INTERRUPTS_IRQ_LEVEL_209            31        ///< IRQ#209
#define INTERRUPTS_IRQ_LEVEL_210            31        ///< IRQ#210
#define INTERRUPTS_IRQ_LEVEL_211            31        ///< IRQ#211
#define INTERRUPTS_IRQ_LEVEL_212            31        ///< IRQ#212
#define INTERRUPTS_IRQ_LEVEL_213            31        ///< IRQ#213
#define INTERRUPTS_IRQ_LEVEL_214            31        ///< IRQ#214
#define INTERRUPTS_IRQ_LEVEL_215            31        ///< IRQ#215
#define INTERRUPTS_IRQ_LEVEL_216            31        ///< IRQ#216
#define INTERRUPTS_IRQ_LEVEL_217            31        ///< IRQ#217
#define INTERRUPTS_IRQ_LEVEL_218            31        ///< IRQ#218
#define INTERRUPTS_IRQ_LEVEL_219            31        ///< IRQ#219
#define INTERRUPTS_IRQ_LEVEL_220            31        ///< IRQ#220
#define INTERRUPTS_IRQ_LEVEL_221            31        ///< IRQ#221
#define INTERRUPTS_IRQ_LEVEL_222            31        ///< IRQ#222
#define INTERRUPTS_IRQ_LEVEL_223            31        ///< IRQ#223
#define INTERRUPTS_IRQ_LEVEL_224            31        ///< IRQ#224
#define INTERRUPTS_IRQ_LEVEL_225            31        ///< IRQ#225
#define INTERRUPTS_IRQ_LEVEL_226            31        ///< IRQ#226
#define INTERRUPTS_IRQ_LEVEL_227            31        ///< IRQ#227
#define INTERRUPTS_IRQ_LEVEL_228            31        ///< IRQ#228
#define INTERRUPTS_IRQ_LEVEL_229            31        ///< IRQ#229
#define INTERRUPTS_IRQ_LEVEL_230            31        ///< IRQ#230
#define INTERRUPTS_IRQ_LEVEL_231            31        ///< IRQ#231
#define INTERRUPTS_IRQ_LEVEL_232            31        ///< IRQ#232
#define INTERRUPTS_IRQ_LEVEL_233            31        ///< IRQ#233
#define INTERRUPTS_IRQ_LEVEL_234            31        ///< IRQ#234
#define INTERRUPTS_IRQ_LEVEL_235            31        ///< IRQ#235
#define INTERRUPTS_IRQ_LEVEL_236            31        ///< IRQ#236
#define INTERRUPTS_IRQ_LEVEL_237            31        ///< IRQ#237
#define INTERRUPTS_IRQ_LEVEL_238            31        ///< IRQ#238
#define INTERRUPTS_IRQ_LEVEL_239            31        ///< IRQ#239
#define INTERRUPTS_IRQ_LEVEL_240            31        ///< IRQ#240
#define INTERRUPTS_IRQ_LEVEL_241            31        ///< IRQ#241
#define INTERRUPTS_IRQ_LEVEL_242            31        ///< IRQ#242
#define INTERRUPTS_IRQ_LEVEL_243            31        ///< IRQ#243
#define INTERRUPTS_IRQ_LEVEL_244            31        ///< IRQ#244
#define INTERRUPTS_IRQ_LEVEL_245            31        ///< IRQ#245
#define INTERRUPTS_IRQ_LEVEL_246            31        ///< IRQ#246
#define INTERRUPTS_IRQ_LEVEL_247            31        ///< IRQ#247
#define INTERRUPTS_IRQ_LEVEL_248            31        ///< IRQ#248
#define INTERRUPTS_IRQ_LEVEL_249            31        ///< IRQ#249
#define INTERRUPTS_IRQ_LEVEL_250            31        ///< IRQ#250
#define INTERRUPTS_IRQ_LEVEL_251            31        ///< IRQ#251
#define INTERRUPTS_IRQ_LEVEL_252            31        ///< IRQ#252
#define INTERRUPTS_IRQ_LEVEL_253            31        ///< IRQ#253
#define INTERRUPTS_IRQ_LEVEL_254            31        ///< IRQ#254
#define INTERRUPTS_IRQ_LEVEL_255            31        ///< IRQ#255
#define INTERRUPTS_IRQ_LEVEL_256            31        ///< IRQ#256
#define INTERRUPTS_IRQ_LEVEL_257            31        ///< IRQ#257
#define INTERRUPTS_IRQ_LEVEL_258            31        ///< IRQ#258
#define INTERRUPTS_IRQ_LEVEL_259            31        ///< IRQ#259
#define INTERRUPTS_IRQ_LEVEL_260            31        ///< IRQ#260
#define INTERRUPTS_IRQ_LEVEL_261            31        ///< IRQ#261
#define INTERRUPTS_IRQ_LEVEL_262            31        ///< IRQ#262
#define INTERRUPTS_IRQ_LEVEL_263            31        ///< IRQ#263
#define INTERRUPTS_IRQ_LEVEL_264            31        ///< IRQ#264
#define INTERRUPTS_IRQ_LEVEL_265            31        ///< IRQ#265
#define INTERRUPTS_IRQ_LEVEL_266            31        ///< IRQ#266
#define INTERRUPTS_IRQ_LEVEL_267            31        ///< IRQ#267
#define INTERRUPTS_IRQ_LEVEL_268            31        ///< IRQ#268
#define INTERRUPTS_IRQ_LEVEL_269            31        ///< IRQ#269
#define INTERRUPTS_IRQ_LEVEL_270            31        ///< IRQ#270
#define INTERRUPTS_IRQ_LEVEL_271            31        ///< IRQ#271
#define INTERRUPTS_IRQ_LEVEL_272            31        ///< IRQ#272
#define INTERRUPTS_IRQ_LEVEL_273            31        ///< IRQ#273
#define INTERRUPTS_IRQ_LEVEL_274            31        ///< IRQ#274
#define INTERRUPTS_IRQ_LEVEL_275            31        ///< IRQ#275
#define INTERRUPTS_IRQ_LEVEL_276            31        ///< IRQ#276
#define INTERRUPTS_IRQ_LEVEL_277            31        ///< IRQ#277
#define INTERRUPTS_IRQ_LEVEL_278            31        ///< IRQ#278
#define INTERRUPTS_IRQ_LEVEL_279            31        ///< IRQ#279
#define INTERRUPTS_IRQ_LEVEL_280            31        ///< IRQ#280
#define INTERRUPTS_IRQ_LEVEL_281            31        ///< IRQ#281
#define INTERRUPTS_IRQ_LEVEL_282            31        ///< IRQ#282
#define INTERRUPTS_IRQ_LEVEL_283            31        ///< IRQ#283
#define INTERRUPTS_IRQ_LEVEL_284            31        ///< IRQ#284
#define INTERRUPTS_IRQ_LEVEL_285            31        ///< IRQ#285
#define INTERRUPTS_IRQ_LEVEL_286            31        ///< IRQ#286
#define INTERRUPTS_IRQ_LEVEL_287            31        ///< IRQ#287
#define INTERRUPTS_IRQ_LEVEL_288            31        ///< IRQ#288
#define INTERRUPTS_IRQ_LEVEL_289            31        ///< IRQ#289
#define INTERRUPTS_IRQ_LEVEL_290            31        ///< IRQ#290
#define INTERRUPTS_IRQ_LEVEL_291            31        ///< IRQ#291
#define INTERRUPTS_IRQ_LEVEL_292            31        ///< IRQ#292
#define INTERRUPTS_IRQ_LEVEL_293            31        ///< IRQ#293
#define INTERRUPTS_IRQ_LEVEL_294            31        ///< IRQ#294
#define INTERRUPTS_IRQ_LEVEL_295            31        ///< IRQ#295
#define INTERRUPTS_IRQ_LEVEL_296            31        ///< IRQ#296
#define INTERRUPTS_IRQ_LEVEL_297            31        ///< IRQ#297
#define INTERRUPTS_IRQ_LEVEL_298            31        ///< IRQ#298
#define INTERRUPTS_IRQ_LEVEL_299            31        ///< IRQ#299
#define INTERRUPTS_IRQ_LEVEL_300            31        ///< IRQ#300
#define INTERRUPTS_IRQ_LEVEL_301            31        ///< IRQ#301
#define INTERRUPTS_IRQ_LEVEL_302            31        ///< IRQ#302
#define INTERRUPTS_IRQ_LEVEL_303            31        ///< IRQ#303
#define INTERRUPTS_IRQ_LEVEL_304            31        ///< IRQ#304
#define INTERRUPTS_IRQ_LEVEL_305            31        ///< IRQ#305
#define INTERRUPTS_IRQ_LEVEL_306            31        ///< IRQ#306
#define INTERRUPTS_IRQ_LEVEL_307            31        ///< IRQ#307
#define INTERRUPTS_IRQ_LEVEL_308            31        ///< IRQ#308
#define INTERRUPTS_IRQ_LEVEL_309            31        ///< IRQ#309
#define INTERRUPTS_IRQ_LEVEL_310            31        ///< IRQ#310
#define INTERRUPTS_IRQ_LEVEL_311            31        ///< IRQ#311
#define INTERRUPTS_IRQ_LEVEL_312            31        ///< IRQ#312
#define INTERRUPTS_IRQ_LEVEL_313            31        ///< IRQ#313
#define INTERRUPTS_IRQ_LEVEL_314            31        ///< IRQ#314
#define INTERRUPTS_IRQ_LEVEL_315            31        ///< IRQ#315
#define INTERRUPTS_IRQ_LEVEL_316            31        ///< IRQ#316
#define INTERRUPTS_IRQ_LEVEL_317            31        ///< IRQ#317
#define INTERRUPTS_IRQ_LEVEL_318            31        ///< IRQ#318
#define INTERRUPTS_IRQ_LEVEL_319            31        ///< IRQ#319
#define INTERRUPTS_IRQ_LEVEL_320            31        ///< IRQ#320
#define INTERRUPTS_IRQ_LEVEL_321            31        ///< IRQ#321
#define INTERRUPTS_IRQ_LEVEL_322            31        ///< IRQ#322
#define INTERRUPTS_IRQ_LEVEL_323            31        ///< IRQ#323
#define INTERRUPTS_IRQ_LEVEL_324            31        ///< IRQ#324
#define INTERRUPTS_IRQ_LEVEL_325            31        ///< IRQ#325
#define INTERRUPTS_IRQ_LEVEL_326            31        ///< IRQ#326
#define INTERRUPTS_IRQ_LEVEL_327            31        ///< IRQ#327
#define INTERRUPTS_IRQ_LEVEL_328            31        ///< IRQ#328
#define INTERRUPTS_IRQ_LEVEL_329            31        ///< IRQ#329
#define INTERRUPTS_IRQ_LEVEL_330            31        ///< IRQ#330
#define INTERRUPTS_IRQ_LEVEL_331            31        ///< IRQ#331
#define INTERRUPTS_IRQ_LEVEL_332            31        ///< IRQ#332
#define INTERRUPTS_IRQ_LEVEL_333            31        ///< IRQ#333
#define INTERRUPTS_IRQ_LEVEL_334            31        ///< IRQ#334
#define INTERRUPTS_IRQ_LEVEL_335            31        ///< IRQ#335
#define INTERRUPTS_IRQ_LEVEL_336            31        ///< IRQ#336
#define INTERRUPTS_IRQ_LEVEL_337            31        ///< IRQ#337
#define INTERRUPTS_IRQ_LEVEL_338            31        ///< IRQ#338
#define INTERRUPTS_IRQ_LEVEL_339            31        ///< IRQ#339
#define INTERRUPTS_IRQ_LEVEL_340            31        ///< IRQ#340
#define INTERRUPTS_IRQ_LEVEL_341            31        ///< IRQ#341
#define INTERRUPTS_IRQ_LEVEL_342            31        ///< IRQ#342
#define INTERRUPTS_IRQ_LEVEL_343            31        ///< IRQ#343
#define INTERRUPTS_IRQ_LEVEL_344            31        ///< IRQ#344
#define INTERRUPTS_IRQ_LEVEL_345            31        ///< IRQ#345
#define INTERRUPTS_IRQ_LEVEL_346            31        ///< IRQ#346
#define INTERRUPTS_IRQ_LEVEL_347            31        ///< IRQ#347
#define INTERRUPTS_IRQ_LEVEL_348            31        ///< IRQ#348
#define INTERRUPTS_IRQ_LEVEL_349            31        ///< IRQ#349
#define INTERRUPTS_IRQ_LEVEL_350            31        ///< IRQ#350
#define INTERRUPTS_IRQ_LEVEL_351            31        ///< IRQ#351
#define INTERRUPTS_IRQ_LEVEL_352            31        ///< IRQ#352
#define INTERRUPTS_IRQ_LEVEL_353            31        ///< IRQ#353
#define INTERRUPTS_IRQ_LEVEL_354            31        ///< IRQ#354
#define INTERRUPTS_IRQ_LEVEL_355            31        ///< IRQ#355
#define INTERRUPTS_IRQ_LEVEL_356            31        ///< IRQ#356
#define INTERRUPTS_IRQ_LEVEL_357            31        ///< IRQ#357
#define INTERRUPTS_IRQ_LEVEL_358            31        ///< IRQ#358
#define INTERRUPTS_IRQ_LEVEL_359            31        ///< IRQ#359
#define INTERRUPTS_IRQ_LEVEL_360            31        ///< IRQ#360
#define INTERRUPTS_IRQ_LEVEL_361            31        ///< IRQ#361
#define INTERRUPTS_IRQ_LEVEL_362            31        ///< IRQ#362
#define INTERRUPTS_IRQ_LEVEL_363            31        ///< IRQ#363
#define INTERRUPTS_IRQ_LEVEL_364            31        ///< IRQ#364
#define INTERRUPTS_IRQ_LEVEL_365            31        ///< IRQ#365
#define INTERRUPTS_IRQ_LEVEL_366            31        ///< IRQ#366
#define INTERRUPTS_IRQ_LEVEL_367            31        ///< IRQ#367
#define INTERRUPTS_IRQ_LEVEL_368            31        ///< IRQ#368
#define INTERRUPTS_IRQ_LEVEL_369            31        ///< IRQ#369
#define INTERRUPTS_IRQ_LEVEL_370            31        ///< IRQ#370
#define INTERRUPTS_IRQ_LEVEL_371            31        ///< IRQ#371
#define INTERRUPTS_IRQ_LEVEL_372            31        ///< IRQ#372
#define INTERRUPTS_IRQ_LEVEL_373            31        ///< IRQ#373
#define INTERRUPTS_IRQ_LEVEL_374            31        ///< IRQ#374
#define INTERRUPTS_IRQ_LEVEL_375            31        ///< IRQ#375
#define INTERRUPTS_IRQ_LEVEL_376            31        ///< IRQ#376
#define INTERRUPTS_IRQ_LEVEL_377            31        ///< IRQ#377
#define INTERRUPTS_IRQ_LEVEL_378            31        ///< IRQ#378
#define INTERRUPTS_IRQ_LEVEL_379            31        ///< IRQ#379
#define INTERRUPTS_IRQ_LEVEL_380            31        ///< IRQ#380
#define INTERRUPTS_IRQ_LEVEL_381            31        ///< IRQ#381
#define INTERRUPTS_IRQ_LEVEL_382            31        ///< IRQ#382
#define INTERRUPTS_IRQ_LEVEL_383            31        ///< IRQ#383
#define INTERRUPTS_IRQ_LEVEL_384            31        ///< IRQ#384
#define INTERRUPTS_IRQ_LEVEL_385            31        ///< IRQ#385
#define INTERRUPTS_IRQ_LEVEL_386            31        ///< IRQ#386
#define INTERRUPTS_IRQ_LEVEL_387            31        ///< IRQ#387
#define INTERRUPTS_IRQ_LEVEL_388            31        ///< IRQ#388
#define INTERRUPTS_IRQ_LEVEL_389            31        ///< IRQ#389
#define INTERRUPTS_IRQ_LEVEL_390            31        ///< IRQ#390
#define INTERRUPTS_IRQ_LEVEL_391            31        ///< IRQ#391
#define INTERRUPTS_IRQ_LEVEL_392            31        ///< IRQ#392
#define INTERRUPTS_IRQ_LEVEL_393            31        ///< IRQ#393
#define INTERRUPTS_IRQ_LEVEL_394            31        ///< IRQ#394
#define INTERRUPTS_IRQ_LEVEL_395            31        ///< IRQ#395
#define INTERRUPTS_IRQ_LEVEL_396            31        ///< IRQ#396
#define INTERRUPTS_IRQ_LEVEL_397            31        ///< IRQ#397
#define INTERRUPTS_IRQ_LEVEL_398            31        ///< IRQ#398
#define INTERRUPTS_IRQ_LEVEL_399            31        ///< IRQ#399
#define INTERRUPTS_IRQ_LEVEL_400            31        ///< IRQ#400
#define INTERRUPTS_IRQ_LEVEL_401            31        ///< IRQ#401
#define INTERRUPTS_IRQ_LEVEL_402            31        ///< IRQ#402
#define INTERRUPTS_IRQ_LEVEL_403            31        ///< IRQ#403
#define INTERRUPTS_IRQ_LEVEL_404            31        ///< IRQ#404
#define INTERRUPTS_IRQ_LEVEL_405            31        ///< IRQ#405
#define INTERRUPTS_IRQ_LEVEL_406            31        ///< IRQ#406
#define INTERRUPTS_IRQ_LEVEL_407            31        ///< IRQ#407
#define INTERRUPTS_IRQ_LEVEL_408            31        ///< IRQ#408
#define INTERRUPTS_IRQ_LEVEL_409            31        ///< IRQ#409
#define INTERRUPTS_IRQ_LEVEL_410            31        ///< IRQ#410
#define INTERRUPTS_IRQ_LEVEL_411            31        ///< IRQ#411
#define INTERRUPTS_IRQ_LEVEL_412            31        ///< IRQ#412
#define INTERRUPTS_IRQ_LEVEL_413            31        ///< IRQ#413
#define INTERRUPTS_IRQ_LEVEL_414            31        ///< IRQ#414
#define INTERRUPTS_IRQ_LEVEL_415            31        ///< IRQ#415
#define INTERRUPTS_IRQ_LEVEL_416            31        ///< IRQ#416
#define INTERRUPTS_IRQ_LEVEL_417            31        ///< IRQ#417
#define INTERRUPTS_IRQ_LEVEL_418            31        ///< IRQ#418
#define INTERRUPTS_IRQ_LEVEL_419            31        ///< IRQ#419
#define INTERRUPTS_IRQ_LEVEL_420            31        ///< IRQ#420
#define INTERRUPTS_IRQ_LEVEL_421            31        ///< IRQ#421
#define INTERRUPTS_IRQ_LEVEL_422            31        ///< IRQ#422
#define INTERRUPTS_IRQ_LEVEL_423            31        ///< IRQ#423
#define INTERRUPTS_IRQ_LEVEL_424            31        ///< IRQ#424
#define INTERRUPTS_IRQ_LEVEL_425            31        ///< IRQ#425
#define INTERRUPTS_IRQ_LEVEL_426            31        ///< IRQ#426
#define INTERRUPTS_IRQ_LEVEL_427            31        ///< IRQ#427
#define INTERRUPTS_IRQ_LEVEL_428            31        ///< IRQ#428
#define INTERRUPTS_IRQ_LEVEL_429            31        ///< IRQ#429
#define INTERRUPTS_IRQ_LEVEL_430            31        ///< IRQ#430
#define INTERRUPTS_IRQ_LEVEL_431            31        ///< IRQ#431
#define INTERRUPTS_IRQ_LEVEL_432            31        ///< IRQ#432
#define INTERRUPTS_IRQ_LEVEL_433            31        ///< IRQ#433
#define INTERRUPTS_IRQ_LEVEL_434            31        ///< IRQ#434
#define INTERRUPTS_IRQ_LEVEL_435            31        ///< IRQ#435
#define INTERRUPTS_IRQ_LEVEL_436            31        ///< IRQ#436
#define INTERRUPTS_IRQ_LEVEL_437            31        ///< IRQ#437
#define INTERRUPTS_IRQ_LEVEL_438            31        ///< IRQ#438
#define INTERRUPTS_IRQ_LEVEL_439            31        ///< IRQ#439
#define INTERRUPTS_IRQ_LEVEL_440            31        ///< IRQ#440
#define INTERRUPTS_IRQ_LEVEL_441            31        ///< IRQ#441
#define INTERRUPTS_IRQ_LEVEL_442            31        ///< IRQ#442
#define INTERRUPTS_IRQ_LEVEL_443            31        ///< IRQ#443
#define INTERRUPTS_IRQ_LEVEL_444            31        ///< IRQ#444
#define INTERRUPTS_IRQ_LEVEL_445            31        ///< IRQ#445
#define INTERRUPTS_IRQ_LEVEL_446            31        ///< IRQ#446
#define INTERRUPTS_IRQ_LEVEL_447            31        ///< IRQ#447
#define INTERRUPTS_IRQ_LEVEL_448            31        ///< IRQ#448
#define INTERRUPTS_IRQ_LEVEL_449            31        ///< IRQ#449
#define INTERRUPTS_IRQ_LEVEL_450            31        ///< IRQ#450
#define INTERRUPTS_IRQ_LEVEL_451            31        ///< IRQ#451
#define INTERRUPTS_IRQ_LEVEL_452            31        ///< IRQ#452
#define INTERRUPTS_IRQ_LEVEL_453            31        ///< IRQ#453
#define INTERRUPTS_IRQ_LEVEL_454            31        ///< IRQ#454
#define INTERRUPTS_IRQ_LEVEL_455            31        ///< IRQ#455
#define INTERRUPTS_IRQ_LEVEL_456            31        ///< IRQ#456
#define INTERRUPTS_IRQ_LEVEL_457            31        ///< IRQ#457
#define INTERRUPTS_IRQ_LEVEL_458            31        ///< IRQ#458
#define INTERRUPTS_IRQ_LEVEL_459            31        ///< IRQ#459
#define INTERRUPTS_IRQ_LEVEL_460            31        ///< IRQ#460
#define INTERRUPTS_IRQ_LEVEL_461            31        ///< IRQ#461
#define INTERRUPTS_IRQ_LEVEL_462            31        ///< IRQ#462
#define INTERRUPTS_IRQ_LEVEL_463            31        ///< IRQ#463
#define INTERRUPTS_IRQ_LEVEL_464            31        ///< IRQ#464
#define INTERRUPTS_IRQ_LEVEL_465            31        ///< IRQ#465
#define INTERRUPTS_IRQ_LEVEL_466            31        ///< IRQ#466
#define INTERRUPTS_IRQ_LEVEL_467            31        ///< IRQ#467
#define INTERRUPTS_IRQ_LEVEL_468            31        ///< IRQ#468
#define INTERRUPTS_IRQ_LEVEL_469            31        ///< IRQ#469
#define INTERRUPTS_IRQ_LEVEL_470            31        ///< IRQ#470
#define INTERRUPTS_IRQ_LEVEL_471            31        ///< IRQ#471
#define INTERRUPTS_IRQ_LEVEL_472            31        ///< IRQ#472
#define INTERRUPTS_IRQ_LEVEL_473            31        ///< IRQ#473
#define INTERRUPTS_IRQ_LEVEL_474            31        ///< IRQ#474
#define INTERRUPTS_IRQ_LEVEL_475            31        ///< IRQ#475
#define INTERRUPTS_IRQ_LEVEL_476            31        ///< IRQ#476
#define INTERRUPTS_IRQ_LEVEL_477            31        ///< IRQ#477
#define INTERRUPTS_IRQ_LEVEL_478            31        ///< IRQ#478
#define INTERRUPTS_IRQ_LEVEL_479            31        ///< IRQ#479
#define INTERRUPTS_IRQ_LEVEL_480            31        ///< IRQ#480
#define INTERRUPTS_IRQ_LEVEL_481            31        ///< IRQ#481
#define INTERRUPTS_IRQ_LEVEL_482            31        ///< IRQ#482
#define INTERRUPTS_IRQ_LEVEL_483            31        ///< IRQ#483
#define INTERRUPTS_IRQ_LEVEL_484            31        ///< IRQ#484
#define INTERRUPTS_IRQ_LEVEL_485            31        ///< IRQ#485
#define INTERRUPTS_IRQ_LEVEL_486            31        ///< IRQ#486
#define INTERRUPTS_IRQ_LEVEL_487            31        ///< IRQ#487
#define INTERRUPTS_IRQ_LEVEL_488            31        ///< IRQ#488
#define INTERRUPTS_IRQ_LEVEL_489            31        ///< IRQ#489
#define INTERRUPTS_IRQ_LEVEL_490            31        ///< IRQ#490
#define INTERRUPTS_IRQ_LEVEL_491            31        ///< IRQ#491
#define INTERRUPTS_IRQ_LEVEL_492            31        ///< IRQ#492
#define INTERRUPTS_IRQ_LEVEL_493            31        ///< IRQ#493
#define INTERRUPTS_IRQ_LEVEL_494            31        ///< IRQ#494
#define INTERRUPTS_IRQ_LEVEL_495            31        ///< IRQ#495
#define INTERRUPTS_IRQ_LEVEL_496            31        ///< IRQ#496
#define INTERRUPTS_IRQ_LEVEL_497            31        ///< IRQ#497
#define INTERRUPTS_IRQ_LEVEL_498            31        ///< IRQ#498
#define INTERRUPTS_IRQ_LEVEL_499            31        ///< IRQ#499
#define INTERRUPTS_IRQ_LEVEL_500            31        ///< IRQ#500
#define INTERRUPTS_IRQ_LEVEL_501            31        ///< IRQ#501
#define INTERRUPTS_IRQ_LEVEL_502            31        ///< IRQ#502
#define INTERRUPTS_IRQ_LEVEL_503            31        ///< IRQ#503
#define INTERRUPTS_IRQ_LEVEL_504            31        ///< IRQ#504
#define INTERRUPTS_IRQ_LEVEL_505            31        ///< IRQ#505
#define INTERRUPTS_IRQ_LEVEL_506            31        ///< IRQ#506
#define INTERRUPTS_IRQ_LEVEL_507            31        ///< IRQ#507
#define INTERRUPTS_IRQ_LEVEL_508            31        ///< IRQ#508
#define INTERRUPTS_IRQ_LEVEL_509            31        ///< IRQ#509
#define INTERRUPTS_IRQ_LEVEL_510            31        ///< IRQ#510
#define INTERRUPTS_IRQ_LEVEL_511            31        ///< IRQ#511

// --------------------------------------------------------------------
// 1.4  I R Q   N U M B E R S                
// --------------------------------------------------------------------
// Definition of IRQ numbers. These macros should
// be used as parameter for ISR function definition macros
// FN_[NESTED_]IRQ_DEFINE_BEGIN( ..., IrqNum) to set the IRQ
// number which must be cleared in the Interrupt Controller
// after an IRQ is handled.
// --------------------------------------------------------------------

#define INTERRUPTS_IRQ_NUMBER_0             0           ///< IRQ#0
#define INTERRUPTS_IRQ_NUMBER_1             1           ///< IRQ#1
#define INTERRUPTS_IRQ_NUMBER_2             2           ///< IRQ#2
#define INTERRUPTS_IRQ_NUMBER_3             3           ///< IRQ#3
#define INTERRUPTS_IRQ_NUMBER_4             4           ///< IRQ#4
#define INTERRUPTS_IRQ_NUMBER_5             5           ///< IRQ#5
#define INTERRUPTS_IRQ_NUMBER_6             6           ///< IRQ#6
#define INTERRUPTS_IRQ_NUMBER_7             7           ///< IRQ#7
#define INTERRUPTS_IRQ_NUMBER_8             8           ///< IRQ#8
#define INTERRUPTS_IRQ_NUMBER_9             9           ///< IRQ#9
#define INTERRUPTS_IRQ_NUMBER_10            10          ///< IRQ#10
#define INTERRUPTS_IRQ_NUMBER_11            11          ///< IRQ#11
#define INTERRUPTS_IRQ_NUMBER_12            12          ///< IRQ#12
#define INTERRUPTS_IRQ_NUMBER_13            13          ///< IRQ#13
#define INTERRUPTS_IRQ_NUMBER_14            14          ///< IRQ#14
#define INTERRUPTS_IRQ_NUMBER_15            15          ///< IRQ#15
#define INTERRUPTS_IRQ_NUMBER_16            16          ///< IRQ#16
#define INTERRUPTS_IRQ_NUMBER_17            17          ///< IRQ#17
#define INTERRUPTS_IRQ_NUMBER_18            18          ///< IRQ#18
#define INTERRUPTS_IRQ_NUMBER_19            19          ///< IRQ#19
#define INTERRUPTS_IRQ_NUMBER_20            20          ///< IRQ#20
#define INTERRUPTS_IRQ_NUMBER_21            21          ///< IRQ#21
#define INTERRUPTS_IRQ_NUMBER_22            22          ///< IRQ#22
#define INTERRUPTS_IRQ_NUMBER_23            23          ///< IRQ#23
#define INTERRUPTS_IRQ_NUMBER_24            24          ///< IRQ#24
#define INTERRUPTS_IRQ_NUMBER_25            25          ///< IRQ#25
#define INTERRUPTS_IRQ_NUMBER_26            26          ///< IRQ#26
#define INTERRUPTS_IRQ_NUMBER_27            27          ///< IRQ#27
#define INTERRUPTS_IRQ_NUMBER_28            28          ///< IRQ#28
#define INTERRUPTS_IRQ_NUMBER_29            29          ///< IRQ#29
#define INTERRUPTS_IRQ_NUMBER_30            30          ///< IRQ#30
#define INTERRUPTS_IRQ_NUMBER_31            31          ///< IRQ#31
#define INTERRUPTS_IRQ_NUMBER_32            32          ///< IRQ#32
#define INTERRUPTS_IRQ_NUMBER_33            33          ///< IRQ#33
#define INTERRUPTS_IRQ_NUMBER_34            34          ///< IRQ#34
#define INTERRUPTS_IRQ_NUMBER_35            35          ///< IRQ#35
#define INTERRUPTS_IRQ_NUMBER_36            36          ///< IRQ#36
#define INTERRUPTS_IRQ_NUMBER_37            37          ///< IRQ#37
#define INTERRUPTS_IRQ_NUMBER_38            38          ///< IRQ#38
#define INTERRUPTS_IRQ_NUMBER_39            39          ///< IRQ#39
#define INTERRUPTS_IRQ_NUMBER_40            40          ///< IRQ#40
#define INTERRUPTS_IRQ_NUMBER_41            41          ///< IRQ#41
#define INTERRUPTS_IRQ_NUMBER_42            42          ///< IRQ#42
#define INTERRUPTS_IRQ_NUMBER_43            43          ///< IRQ#43
#define INTERRUPTS_IRQ_NUMBER_44            44          ///< IRQ#44
#define INTERRUPTS_IRQ_NUMBER_45            45          ///< IRQ#45
#define INTERRUPTS_IRQ_NUMBER_46            46          ///< IRQ#46
#define INTERRUPTS_IRQ_NUMBER_47            47          ///< IRQ#47
#define INTERRUPTS_IRQ_NUMBER_48            48          ///< IRQ#48
#define INTERRUPTS_IRQ_NUMBER_49            49          ///< IRQ#49
#define INTERRUPTS_IRQ_NUMBER_50            50          ///< IRQ#50
#define INTERRUPTS_IRQ_NUMBER_51            51          ///< IRQ#51
#define INTERRUPTS_IRQ_NUMBER_52            52          ///< IRQ#52
#define INTERRUPTS_IRQ_NUMBER_53            53          ///< IRQ#53
#define INTERRUPTS_IRQ_NUMBER_54            54          ///< IRQ#54
#define INTERRUPTS_IRQ_NUMBER_55            55          ///< IRQ#55
#define INTERRUPTS_IRQ_NUMBER_56            56          ///< IRQ#56
#define INTERRUPTS_IRQ_NUMBER_57            57          ///< IRQ#57
#define INTERRUPTS_IRQ_NUMBER_58            58          ///< IRQ#58
#define INTERRUPTS_IRQ_NUMBER_59            59          ///< IRQ#59
#define INTERRUPTS_IRQ_NUMBER_60            60          ///< IRQ#60
#define INTERRUPTS_IRQ_NUMBER_61            61          ///< IRQ#61
#define INTERRUPTS_IRQ_NUMBER_62            62          ///< IRQ#62
#define INTERRUPTS_IRQ_NUMBER_63            63          ///< IRQ#63
#define INTERRUPTS_IRQ_NUMBER_64            64          ///< IRQ#64
#define INTERRUPTS_IRQ_NUMBER_65            65          ///< IRQ#65
#define INTERRUPTS_IRQ_NUMBER_66            66          ///< IRQ#66
#define INTERRUPTS_IRQ_NUMBER_67            67          ///< IRQ#67
#define INTERRUPTS_IRQ_NUMBER_68            68          ///< IRQ#68
#define INTERRUPTS_IRQ_NUMBER_69            69          ///< IRQ#69
#define INTERRUPTS_IRQ_NUMBER_70            70          ///< IRQ#70
#define INTERRUPTS_IRQ_NUMBER_71            71          ///< IRQ#71
#define INTERRUPTS_IRQ_NUMBER_72            72          ///< IRQ#72
#define INTERRUPTS_IRQ_NUMBER_73            73          ///< IRQ#73
#define INTERRUPTS_IRQ_NUMBER_74            74          ///< IRQ#74
#define INTERRUPTS_IRQ_NUMBER_75            75          ///< IRQ#75
#define INTERRUPTS_IRQ_NUMBER_76            76          ///< IRQ#76
#define INTERRUPTS_IRQ_NUMBER_77            77          ///< IRQ#77
#define INTERRUPTS_IRQ_NUMBER_78            78          ///< IRQ#78
#define INTERRUPTS_IRQ_NUMBER_79            79          ///< IRQ#79
#define INTERRUPTS_IRQ_NUMBER_80            80          ///< IRQ#80
#define INTERRUPTS_IRQ_NUMBER_81            81          ///< IRQ#81
#define INTERRUPTS_IRQ_NUMBER_82            82          ///< IRQ#82
#define INTERRUPTS_IRQ_NUMBER_83            83          ///< IRQ#83
#define INTERRUPTS_IRQ_NUMBER_84            84          ///< IRQ#84
#define INTERRUPTS_IRQ_NUMBER_85            85          ///< IRQ#85
#define INTERRUPTS_IRQ_NUMBER_86            86          ///< IRQ#86
#define INTERRUPTS_IRQ_NUMBER_87            87          ///< IRQ#87
#define INTERRUPTS_IRQ_NUMBER_88            88          ///< IRQ#88
#define INTERRUPTS_IRQ_NUMBER_89            89          ///< IRQ#89
#define INTERRUPTS_IRQ_NUMBER_90            90          ///< IRQ#90
#define INTERRUPTS_IRQ_NUMBER_91            91          ///< IRQ#91
#define INTERRUPTS_IRQ_NUMBER_92            92          ///< IRQ#92
#define INTERRUPTS_IRQ_NUMBER_93            93          ///< IRQ#93
#define INTERRUPTS_IRQ_NUMBER_94            94          ///< IRQ#94
#define INTERRUPTS_IRQ_NUMBER_95            95          ///< IRQ#95
#define INTERRUPTS_IRQ_NUMBER_96            96          ///< IRQ#96
#define INTERRUPTS_IRQ_NUMBER_97            97          ///< IRQ#97
#define INTERRUPTS_IRQ_NUMBER_98            98          ///< IRQ#98
#define INTERRUPTS_IRQ_NUMBER_99            99          ///< IRQ#99
#define INTERRUPTS_IRQ_NUMBER_100           100         ///< IRQ#100
#define INTERRUPTS_IRQ_NUMBER_101           101         ///< IRQ#101
#define INTERRUPTS_IRQ_NUMBER_102           102         ///< IRQ#102
#define INTERRUPTS_IRQ_NUMBER_103           103         ///< IRQ#103
#define INTERRUPTS_IRQ_NUMBER_104           104         ///< IRQ#104
#define INTERRUPTS_IRQ_NUMBER_105           105         ///< IRQ#105
#define INTERRUPTS_IRQ_NUMBER_106           106         ///< IRQ#106
#define INTERRUPTS_IRQ_NUMBER_107           107         ///< IRQ#107
#define INTERRUPTS_IRQ_NUMBER_108           108         ///< IRQ#108
#define INTERRUPTS_IRQ_NUMBER_109           109         ///< IRQ#109
#define INTERRUPTS_IRQ_NUMBER_110           110         ///< IRQ#110
#define INTERRUPTS_IRQ_NUMBER_111           111         ///< IRQ#111
#define INTERRUPTS_IRQ_NUMBER_112           112         ///< IRQ#112
#define INTERRUPTS_IRQ_NUMBER_113           113         ///< IRQ#113
#define INTERRUPTS_IRQ_NUMBER_114           114         ///< IRQ#114
#define INTERRUPTS_IRQ_NUMBER_115           115         ///< IRQ#115
#define INTERRUPTS_IRQ_NUMBER_116           116         ///< IRQ#116
#define INTERRUPTS_IRQ_NUMBER_117           117         ///< IRQ#117
#define INTERRUPTS_IRQ_NUMBER_118           118         ///< IRQ#118
#define INTERRUPTS_IRQ_NUMBER_119           119         ///< IRQ#119
#define INTERRUPTS_IRQ_NUMBER_120           120         ///< IRQ#120
#define INTERRUPTS_IRQ_NUMBER_121           121         ///< IRQ#121
#define INTERRUPTS_IRQ_NUMBER_122           122         ///< IRQ#122
#define INTERRUPTS_IRQ_NUMBER_123           123         ///< IRQ#123
#define INTERRUPTS_IRQ_NUMBER_124           124         ///< IRQ#124
#define INTERRUPTS_IRQ_NUMBER_125           125         ///< IRQ#125
#define INTERRUPTS_IRQ_NUMBER_126           126         ///< IRQ#126
#define INTERRUPTS_IRQ_NUMBER_127           127         ///< IRQ#127
#define INTERRUPTS_IRQ_NUMBER_128           128         ///< IRQ#128
#define INTERRUPTS_IRQ_NUMBER_129           129         ///< IRQ#129
#define INTERRUPTS_IRQ_NUMBER_130           130         ///< IRQ#130
#define INTERRUPTS_IRQ_NUMBER_131           131         ///< IRQ#131
#define INTERRUPTS_IRQ_NUMBER_132           132         ///< IRQ#132
#define INTERRUPTS_IRQ_NUMBER_133           133         ///< IRQ#133
#define INTERRUPTS_IRQ_NUMBER_134           134         ///< IRQ#134
#define INTERRUPTS_IRQ_NUMBER_135           135         ///< IRQ#135
#define INTERRUPTS_IRQ_NUMBER_136           136         ///< IRQ#136
#define INTERRUPTS_IRQ_NUMBER_137           137         ///< IRQ#137
#define INTERRUPTS_IRQ_NUMBER_138           138         ///< IRQ#138
#define INTERRUPTS_IRQ_NUMBER_139           139         ///< IRQ#139
#define INTERRUPTS_IRQ_NUMBER_140           140         ///< IRQ#140
#define INTERRUPTS_IRQ_NUMBER_141           141         ///< IRQ#141
#define INTERRUPTS_IRQ_NUMBER_142           142         ///< IRQ#142
#define INTERRUPTS_IRQ_NUMBER_143           143         ///< IRQ#143
#define INTERRUPTS_IRQ_NUMBER_144           144         ///< IRQ#144
#define INTERRUPTS_IRQ_NUMBER_145           145         ///< IRQ#145
#define INTERRUPTS_IRQ_NUMBER_146           146         ///< IRQ#146
#define INTERRUPTS_IRQ_NUMBER_147           147         ///< IRQ#147
#define INTERRUPTS_IRQ_NUMBER_148           148         ///< IRQ#148
#define INTERRUPTS_IRQ_NUMBER_149           149         ///< IRQ#149
#define INTERRUPTS_IRQ_NUMBER_150           150         ///< IRQ#150
#define INTERRUPTS_IRQ_NUMBER_151           151         ///< IRQ#151
#define INTERRUPTS_IRQ_NUMBER_152           152         ///< IRQ#152
#define INTERRUPTS_IRQ_NUMBER_153           153         ///< IRQ#153
#define INTERRUPTS_IRQ_NUMBER_154           154         ///< IRQ#154
#define INTERRUPTS_IRQ_NUMBER_155           155         ///< IRQ#155
#define INTERRUPTS_IRQ_NUMBER_156           156         ///< IRQ#156
#define INTERRUPTS_IRQ_NUMBER_157           157         ///< IRQ#157
#define INTERRUPTS_IRQ_NUMBER_158           158         ///< IRQ#158
#define INTERRUPTS_IRQ_NUMBER_159           159         ///< IRQ#159
#define INTERRUPTS_IRQ_NUMBER_160           160         ///< IRQ#160
#define INTERRUPTS_IRQ_NUMBER_161           161         ///< IRQ#161
#define INTERRUPTS_IRQ_NUMBER_162           162         ///< IRQ#162
#define INTERRUPTS_IRQ_NUMBER_163           163         ///< IRQ#163
#define INTERRUPTS_IRQ_NUMBER_164           164         ///< IRQ#164
#define INTERRUPTS_IRQ_NUMBER_165           165         ///< IRQ#165
#define INTERRUPTS_IRQ_NUMBER_166           166         ///< IRQ#166
#define INTERRUPTS_IRQ_NUMBER_167           167         ///< IRQ#167
#define INTERRUPTS_IRQ_NUMBER_168           168         ///< IRQ#168
#define INTERRUPTS_IRQ_NUMBER_169           169         ///< IRQ#169
#define INTERRUPTS_IRQ_NUMBER_170           170         ///< IRQ#170
#define INTERRUPTS_IRQ_NUMBER_171           171         ///< IRQ#171
#define INTERRUPTS_IRQ_NUMBER_172           172         ///< IRQ#172
#define INTERRUPTS_IRQ_NUMBER_173           173         ///< IRQ#173
#define INTERRUPTS_IRQ_NUMBER_174           174         ///< IRQ#174
#define INTERRUPTS_IRQ_NUMBER_175           175         ///< IRQ#175
#define INTERRUPTS_IRQ_NUMBER_176           176         ///< IRQ#176
#define INTERRUPTS_IRQ_NUMBER_177           177         ///< IRQ#177
#define INTERRUPTS_IRQ_NUMBER_178           178         ///< IRQ#178
#define INTERRUPTS_IRQ_NUMBER_179           179         ///< IRQ#179
#define INTERRUPTS_IRQ_NUMBER_180           180         ///< IRQ#180
#define INTERRUPTS_IRQ_NUMBER_181           181         ///< IRQ#181
#define INTERRUPTS_IRQ_NUMBER_182           182         ///< IRQ#182
#define INTERRUPTS_IRQ_NUMBER_183           183         ///< IRQ#183
#define INTERRUPTS_IRQ_NUMBER_184           184         ///< IRQ#184
#define INTERRUPTS_IRQ_NUMBER_185           185         ///< IRQ#185
#define INTERRUPTS_IRQ_NUMBER_186           186         ///< IRQ#186
#define INTERRUPTS_IRQ_NUMBER_187           187         ///< IRQ#187
#define INTERRUPTS_IRQ_NUMBER_188           188         ///< IRQ#188
#define INTERRUPTS_IRQ_NUMBER_189           189         ///< IRQ#189
#define INTERRUPTS_IRQ_NUMBER_190           190         ///< IRQ#190
#define INTERRUPTS_IRQ_NUMBER_191           191         ///< IRQ#191
#define INTERRUPTS_IRQ_NUMBER_192           192         ///< IRQ#192
#define INTERRUPTS_IRQ_NUMBER_193           193         ///< IRQ#193
#define INTERRUPTS_IRQ_NUMBER_194           194         ///< IRQ#194
#define INTERRUPTS_IRQ_NUMBER_195           195         ///< IRQ#195
#define INTERRUPTS_IRQ_NUMBER_196           196         ///< IRQ#196
#define INTERRUPTS_IRQ_NUMBER_197           197         ///< IRQ#197
#define INTERRUPTS_IRQ_NUMBER_198           198         ///< IRQ#198
#define INTERRUPTS_IRQ_NUMBER_199           199         ///< IRQ#199
#define INTERRUPTS_IRQ_NUMBER_200           200         ///< IRQ#200
#define INTERRUPTS_IRQ_NUMBER_201           201         ///< IRQ#201
#define INTERRUPTS_IRQ_NUMBER_202           202         ///< IRQ#202
#define INTERRUPTS_IRQ_NUMBER_203           203         ///< IRQ#203
#define INTERRUPTS_IRQ_NUMBER_204           204         ///< IRQ#204
#define INTERRUPTS_IRQ_NUMBER_205           205         ///< IRQ#205
#define INTERRUPTS_IRQ_NUMBER_206           206         ///< IRQ#206
#define INTERRUPTS_IRQ_NUMBER_207           207         ///< IRQ#207
#define INTERRUPTS_IRQ_NUMBER_208           208         ///< IRQ#208
#define INTERRUPTS_IRQ_NUMBER_209           209         ///< IRQ#209
#define INTERRUPTS_IRQ_NUMBER_210           210         ///< IRQ#210
#define INTERRUPTS_IRQ_NUMBER_211           211         ///< IRQ#211
#define INTERRUPTS_IRQ_NUMBER_212           212         ///< IRQ#212
#define INTERRUPTS_IRQ_NUMBER_213           213         ///< IRQ#213
#define INTERRUPTS_IRQ_NUMBER_214           214         ///< IRQ#214
#define INTERRUPTS_IRQ_NUMBER_215           215         ///< IRQ#215
#define INTERRUPTS_IRQ_NUMBER_216           216         ///< IRQ#216
#define INTERRUPTS_IRQ_NUMBER_217           217         ///< IRQ#217
#define INTERRUPTS_IRQ_NUMBER_218           218         ///< IRQ#218
#define INTERRUPTS_IRQ_NUMBER_219           219         ///< IRQ#219
#define INTERRUPTS_IRQ_NUMBER_220           220         ///< IRQ#220
#define INTERRUPTS_IRQ_NUMBER_221           221         ///< IRQ#221
#define INTERRUPTS_IRQ_NUMBER_222           222         ///< IRQ#222
#define INTERRUPTS_IRQ_NUMBER_223           223         ///< IRQ#223
#define INTERRUPTS_IRQ_NUMBER_224           224         ///< IRQ#224
#define INTERRUPTS_IRQ_NUMBER_225           225         ///< IRQ#225
#define INTERRUPTS_IRQ_NUMBER_226           226         ///< IRQ#226
#define INTERRUPTS_IRQ_NUMBER_227           227         ///< IRQ#227
#define INTERRUPTS_IRQ_NUMBER_228           228         ///< IRQ#228
#define INTERRUPTS_IRQ_NUMBER_229           229         ///< IRQ#229
#define INTERRUPTS_IRQ_NUMBER_230           230         ///< IRQ#230
#define INTERRUPTS_IRQ_NUMBER_231           231         ///< IRQ#231
#define INTERRUPTS_IRQ_NUMBER_232           232         ///< IRQ#232
#define INTERRUPTS_IRQ_NUMBER_233           233         ///< IRQ#233
#define INTERRUPTS_IRQ_NUMBER_234           234         ///< IRQ#234
#define INTERRUPTS_IRQ_NUMBER_235           235         ///< IRQ#235
#define INTERRUPTS_IRQ_NUMBER_236           236         ///< IRQ#236
#define INTERRUPTS_IRQ_NUMBER_237           237         ///< IRQ#237
#define INTERRUPTS_IRQ_NUMBER_238           238         ///< IRQ#238
#define INTERRUPTS_IRQ_NUMBER_239           239         ///< IRQ#239
#define INTERRUPTS_IRQ_NUMBER_240           240         ///< IRQ#240
#define INTERRUPTS_IRQ_NUMBER_241           241         ///< IRQ#241
#define INTERRUPTS_IRQ_NUMBER_242           242         ///< IRQ#242
#define INTERRUPTS_IRQ_NUMBER_243           243         ///< IRQ#243
#define INTERRUPTS_IRQ_NUMBER_244           244         ///< IRQ#244
#define INTERRUPTS_IRQ_NUMBER_245           245         ///< IRQ#245
#define INTERRUPTS_IRQ_NUMBER_246           246         ///< IRQ#246
#define INTERRUPTS_IRQ_NUMBER_247           247         ///< IRQ#247
#define INTERRUPTS_IRQ_NUMBER_248           248         ///< IRQ#248
#define INTERRUPTS_IRQ_NUMBER_249           249         ///< IRQ#249
#define INTERRUPTS_IRQ_NUMBER_250           250         ///< IRQ#250
#define INTERRUPTS_IRQ_NUMBER_251           251         ///< IRQ#251
#define INTERRUPTS_IRQ_NUMBER_252           252         ///< IRQ#252
#define INTERRUPTS_IRQ_NUMBER_253           253         ///< IRQ#253
#define INTERRUPTS_IRQ_NUMBER_254           254         ///< IRQ#254
#define INTERRUPTS_IRQ_NUMBER_255           255         ///< IRQ#255
#define INTERRUPTS_IRQ_NUMBER_256           256         ///< IRQ#256
#define INTERRUPTS_IRQ_NUMBER_257           257         ///< IRQ#257
#define INTERRUPTS_IRQ_NUMBER_258           258         ///< IRQ#258
#define INTERRUPTS_IRQ_NUMBER_259           259         ///< IRQ#259
#define INTERRUPTS_IRQ_NUMBER_260           260         ///< IRQ#260
#define INTERRUPTS_IRQ_NUMBER_261           261         ///< IRQ#261
#define INTERRUPTS_IRQ_NUMBER_262           262         ///< IRQ#262
#define INTERRUPTS_IRQ_NUMBER_263           263         ///< IRQ#263
#define INTERRUPTS_IRQ_NUMBER_264           264         ///< IRQ#264
#define INTERRUPTS_IRQ_NUMBER_265           265         ///< IRQ#265
#define INTERRUPTS_IRQ_NUMBER_266           266         ///< IRQ#266
#define INTERRUPTS_IRQ_NUMBER_267           267         ///< IRQ#267
#define INTERRUPTS_IRQ_NUMBER_268           268         ///< IRQ#268
#define INTERRUPTS_IRQ_NUMBER_269           269         ///< IRQ#269
#define INTERRUPTS_IRQ_NUMBER_270           270         ///< IRQ#270
#define INTERRUPTS_IRQ_NUMBER_271           271         ///< IRQ#271
#define INTERRUPTS_IRQ_NUMBER_272           272         ///< IRQ#272
#define INTERRUPTS_IRQ_NUMBER_273           273         ///< IRQ#273
#define INTERRUPTS_IRQ_NUMBER_274           274         ///< IRQ#274
#define INTERRUPTS_IRQ_NUMBER_275           275         ///< IRQ#275
#define INTERRUPTS_IRQ_NUMBER_276           276         ///< IRQ#276
#define INTERRUPTS_IRQ_NUMBER_277           277         ///< IRQ#277
#define INTERRUPTS_IRQ_NUMBER_278           278         ///< IRQ#278
#define INTERRUPTS_IRQ_NUMBER_279           279         ///< IRQ#279
#define INTERRUPTS_IRQ_NUMBER_280           280         ///< IRQ#280
#define INTERRUPTS_IRQ_NUMBER_281           281         ///< IRQ#281
#define INTERRUPTS_IRQ_NUMBER_282           282         ///< IRQ#282
#define INTERRUPTS_IRQ_NUMBER_283           283         ///< IRQ#283
#define INTERRUPTS_IRQ_NUMBER_284           284         ///< IRQ#284
#define INTERRUPTS_IRQ_NUMBER_285           285         ///< IRQ#285
#define INTERRUPTS_IRQ_NUMBER_286           286         ///< IRQ#286
#define INTERRUPTS_IRQ_NUMBER_287           287         ///< IRQ#287
#define INTERRUPTS_IRQ_NUMBER_288           288         ///< IRQ#288
#define INTERRUPTS_IRQ_NUMBER_289           289         ///< IRQ#289
#define INTERRUPTS_IRQ_NUMBER_290           290         ///< IRQ#290
#define INTERRUPTS_IRQ_NUMBER_291           291         ///< IRQ#291
#define INTERRUPTS_IRQ_NUMBER_292           292         ///< IRQ#292
#define INTERRUPTS_IRQ_NUMBER_293           293         ///< IRQ#293
#define INTERRUPTS_IRQ_NUMBER_294           294         ///< IRQ#294
#define INTERRUPTS_IRQ_NUMBER_295           295         ///< IRQ#295
#define INTERRUPTS_IRQ_NUMBER_296           296         ///< IRQ#296
#define INTERRUPTS_IRQ_NUMBER_297           297         ///< IRQ#297
#define INTERRUPTS_IRQ_NUMBER_298           298         ///< IRQ#298
#define INTERRUPTS_IRQ_NUMBER_299           299         ///< IRQ#299
#define INTERRUPTS_IRQ_NUMBER_300           300         ///< IRQ#300
#define INTERRUPTS_IRQ_NUMBER_301           301         ///< IRQ#301
#define INTERRUPTS_IRQ_NUMBER_302           302         ///< IRQ#302
#define INTERRUPTS_IRQ_NUMBER_303           303         ///< IRQ#303
#define INTERRUPTS_IRQ_NUMBER_304           304         ///< IRQ#304
#define INTERRUPTS_IRQ_NUMBER_305           305         ///< IRQ#305
#define INTERRUPTS_IRQ_NUMBER_306           306         ///< IRQ#306
#define INTERRUPTS_IRQ_NUMBER_307           307         ///< IRQ#307
#define INTERRUPTS_IRQ_NUMBER_308           308         ///< IRQ#308
#define INTERRUPTS_IRQ_NUMBER_309           309         ///< IRQ#309
#define INTERRUPTS_IRQ_NUMBER_310           310         ///< IRQ#310
#define INTERRUPTS_IRQ_NUMBER_311           311         ///< IRQ#311
#define INTERRUPTS_IRQ_NUMBER_312           312         ///< IRQ#312
#define INTERRUPTS_IRQ_NUMBER_313           313         ///< IRQ#313
#define INTERRUPTS_IRQ_NUMBER_314           314         ///< IRQ#314
#define INTERRUPTS_IRQ_NUMBER_315           315         ///< IRQ#315
#define INTERRUPTS_IRQ_NUMBER_316           316         ///< IRQ#316
#define INTERRUPTS_IRQ_NUMBER_317           317         ///< IRQ#317
#define INTERRUPTS_IRQ_NUMBER_318           318         ///< IRQ#318
#define INTERRUPTS_IRQ_NUMBER_319           319         ///< IRQ#319
#define INTERRUPTS_IRQ_NUMBER_320           320         ///< IRQ#320
#define INTERRUPTS_IRQ_NUMBER_321           321         ///< IRQ#321
#define INTERRUPTS_IRQ_NUMBER_322           322         ///< IRQ#322
#define INTERRUPTS_IRQ_NUMBER_323           323         ///< IRQ#323
#define INTERRUPTS_IRQ_NUMBER_324           324         ///< IRQ#324
#define INTERRUPTS_IRQ_NUMBER_325           325         ///< IRQ#325
#define INTERRUPTS_IRQ_NUMBER_326           326         ///< IRQ#326
#define INTERRUPTS_IRQ_NUMBER_327           327         ///< IRQ#327
#define INTERRUPTS_IRQ_NUMBER_328           328         ///< IRQ#328
#define INTERRUPTS_IRQ_NUMBER_329           329         ///< IRQ#329
#define INTERRUPTS_IRQ_NUMBER_330           330         ///< IRQ#330
#define INTERRUPTS_IRQ_NUMBER_331           331         ///< IRQ#331
#define INTERRUPTS_IRQ_NUMBER_332           332         ///< IRQ#332
#define INTERRUPTS_IRQ_NUMBER_333           333         ///< IRQ#333
#define INTERRUPTS_IRQ_NUMBER_334           334         ///< IRQ#334
#define INTERRUPTS_IRQ_NUMBER_335           335         ///< IRQ#335
#define INTERRUPTS_IRQ_NUMBER_336           336         ///< IRQ#336
#define INTERRUPTS_IRQ_NUMBER_337           337         ///< IRQ#337
#define INTERRUPTS_IRQ_NUMBER_338           338         ///< IRQ#338
#define INTERRUPTS_IRQ_NUMBER_339           339         ///< IRQ#339
#define INTERRUPTS_IRQ_NUMBER_340           340         ///< IRQ#340
#define INTERRUPTS_IRQ_NUMBER_341           341         ///< IRQ#341
#define INTERRUPTS_IRQ_NUMBER_342           342         ///< IRQ#342
#define INTERRUPTS_IRQ_NUMBER_343           343         ///< IRQ#343
#define INTERRUPTS_IRQ_NUMBER_344           344         ///< IRQ#344
#define INTERRUPTS_IRQ_NUMBER_345           345         ///< IRQ#345
#define INTERRUPTS_IRQ_NUMBER_346           346         ///< IRQ#346
#define INTERRUPTS_IRQ_NUMBER_347           347         ///< IRQ#347
#define INTERRUPTS_IRQ_NUMBER_348           348         ///< IRQ#348
#define INTERRUPTS_IRQ_NUMBER_349           349         ///< IRQ#349
#define INTERRUPTS_IRQ_NUMBER_350           350         ///< IRQ#350
#define INTERRUPTS_IRQ_NUMBER_351           351         ///< IRQ#351
#define INTERRUPTS_IRQ_NUMBER_352           352         ///< IRQ#352
#define INTERRUPTS_IRQ_NUMBER_353           353         ///< IRQ#353
#define INTERRUPTS_IRQ_NUMBER_354           354         ///< IRQ#354
#define INTERRUPTS_IRQ_NUMBER_355           355         ///< IRQ#355
#define INTERRUPTS_IRQ_NUMBER_356           356         ///< IRQ#356
#define INTERRUPTS_IRQ_NUMBER_357           357         ///< IRQ#357
#define INTERRUPTS_IRQ_NUMBER_358           358         ///< IRQ#358
#define INTERRUPTS_IRQ_NUMBER_359           359         ///< IRQ#359
#define INTERRUPTS_IRQ_NUMBER_360           360         ///< IRQ#360
#define INTERRUPTS_IRQ_NUMBER_361           361         ///< IRQ#361
#define INTERRUPTS_IRQ_NUMBER_362           362         ///< IRQ#362
#define INTERRUPTS_IRQ_NUMBER_363           363         ///< IRQ#363
#define INTERRUPTS_IRQ_NUMBER_364           364         ///< IRQ#364
#define INTERRUPTS_IRQ_NUMBER_365           365         ///< IRQ#365
#define INTERRUPTS_IRQ_NUMBER_366           366         ///< IRQ#366
#define INTERRUPTS_IRQ_NUMBER_367           367         ///< IRQ#367
#define INTERRUPTS_IRQ_NUMBER_368           368         ///< IRQ#368
#define INTERRUPTS_IRQ_NUMBER_369           369         ///< IRQ#369
#define INTERRUPTS_IRQ_NUMBER_370           370         ///< IRQ#370
#define INTERRUPTS_IRQ_NUMBER_371           371         ///< IRQ#371
#define INTERRUPTS_IRQ_NUMBER_372           372         ///< IRQ#372
#define INTERRUPTS_IRQ_NUMBER_373           373         ///< IRQ#373
#define INTERRUPTS_IRQ_NUMBER_374           374         ///< IRQ#374
#define INTERRUPTS_IRQ_NUMBER_375           375         ///< IRQ#375
#define INTERRUPTS_IRQ_NUMBER_376           376         ///< IRQ#376
#define INTERRUPTS_IRQ_NUMBER_377           377         ///< IRQ#377
#define INTERRUPTS_IRQ_NUMBER_378           378         ///< IRQ#378
#define INTERRUPTS_IRQ_NUMBER_379           379         ///< IRQ#379
#define INTERRUPTS_IRQ_NUMBER_380           380         ///< IRQ#380
#define INTERRUPTS_IRQ_NUMBER_381           381         ///< IRQ#381
#define INTERRUPTS_IRQ_NUMBER_382           382         ///< IRQ#382
#define INTERRUPTS_IRQ_NUMBER_383           383         ///< IRQ#383
#define INTERRUPTS_IRQ_NUMBER_384           384         ///< IRQ#384
#define INTERRUPTS_IRQ_NUMBER_385           385         ///< IRQ#385
#define INTERRUPTS_IRQ_NUMBER_386           386         ///< IRQ#386
#define INTERRUPTS_IRQ_NUMBER_387           387         ///< IRQ#387
#define INTERRUPTS_IRQ_NUMBER_388           388         ///< IRQ#388
#define INTERRUPTS_IRQ_NUMBER_389           389         ///< IRQ#389
#define INTERRUPTS_IRQ_NUMBER_390           390         ///< IRQ#390
#define INTERRUPTS_IRQ_NUMBER_391           391         ///< IRQ#391
#define INTERRUPTS_IRQ_NUMBER_392           392         ///< IRQ#392
#define INTERRUPTS_IRQ_NUMBER_393           393         ///< IRQ#393
#define INTERRUPTS_IRQ_NUMBER_394           394         ///< IRQ#394
#define INTERRUPTS_IRQ_NUMBER_395           395         ///< IRQ#395
#define INTERRUPTS_IRQ_NUMBER_396           396         ///< IRQ#396
#define INTERRUPTS_IRQ_NUMBER_397           397         ///< IRQ#397
#define INTERRUPTS_IRQ_NUMBER_398           398         ///< IRQ#398
#define INTERRUPTS_IRQ_NUMBER_399           399         ///< IRQ#399
#define INTERRUPTS_IRQ_NUMBER_400           400         ///< IRQ#400
#define INTERRUPTS_IRQ_NUMBER_401           401         ///< IRQ#401
#define INTERRUPTS_IRQ_NUMBER_402           402         ///< IRQ#402
#define INTERRUPTS_IRQ_NUMBER_403           403         ///< IRQ#403
#define INTERRUPTS_IRQ_NUMBER_404           404         ///< IRQ#404
#define INTERRUPTS_IRQ_NUMBER_405           405         ///< IRQ#405
#define INTERRUPTS_IRQ_NUMBER_406           406         ///< IRQ#406
#define INTERRUPTS_IRQ_NUMBER_407           407         ///< IRQ#407
#define INTERRUPTS_IRQ_NUMBER_408           408         ///< IRQ#408
#define INTERRUPTS_IRQ_NUMBER_409           409         ///< IRQ#409
#define INTERRUPTS_IRQ_NUMBER_410           410         ///< IRQ#410
#define INTERRUPTS_IRQ_NUMBER_411           411         ///< IRQ#411
#define INTERRUPTS_IRQ_NUMBER_412           412         ///< IRQ#412
#define INTERRUPTS_IRQ_NUMBER_413           413         ///< IRQ#413
#define INTERRUPTS_IRQ_NUMBER_414           414         ///< IRQ#414
#define INTERRUPTS_IRQ_NUMBER_415           415         ///< IRQ#415
#define INTERRUPTS_IRQ_NUMBER_416           416         ///< IRQ#416
#define INTERRUPTS_IRQ_NUMBER_417           417         ///< IRQ#417
#define INTERRUPTS_IRQ_NUMBER_418           418         ///< IRQ#418
#define INTERRUPTS_IRQ_NUMBER_419           419         ///< IRQ#419
#define INTERRUPTS_IRQ_NUMBER_420           420         ///< IRQ#420
#define INTERRUPTS_IRQ_NUMBER_421           421         ///< IRQ#421
#define INTERRUPTS_IRQ_NUMBER_422           422         ///< IRQ#422
#define INTERRUPTS_IRQ_NUMBER_423           423         ///< IRQ#423
#define INTERRUPTS_IRQ_NUMBER_424           424         ///< IRQ#424
#define INTERRUPTS_IRQ_NUMBER_425           425         ///< IRQ#425
#define INTERRUPTS_IRQ_NUMBER_426           426         ///< IRQ#426
#define INTERRUPTS_IRQ_NUMBER_427           427         ///< IRQ#427
#define INTERRUPTS_IRQ_NUMBER_428           428         ///< IRQ#428
#define INTERRUPTS_IRQ_NUMBER_429           429         ///< IRQ#429
#define INTERRUPTS_IRQ_NUMBER_430           430         ///< IRQ#430
#define INTERRUPTS_IRQ_NUMBER_431           431         ///< IRQ#431
#define INTERRUPTS_IRQ_NUMBER_432           432         ///< IRQ#432
#define INTERRUPTS_IRQ_NUMBER_433           433         ///< IRQ#433
#define INTERRUPTS_IRQ_NUMBER_434           434         ///< IRQ#434
#define INTERRUPTS_IRQ_NUMBER_435           435         ///< IRQ#435
#define INTERRUPTS_IRQ_NUMBER_436           436         ///< IRQ#436
#define INTERRUPTS_IRQ_NUMBER_437           437         ///< IRQ#437
#define INTERRUPTS_IRQ_NUMBER_438           438         ///< IRQ#438
#define INTERRUPTS_IRQ_NUMBER_439           439         ///< IRQ#439
#define INTERRUPTS_IRQ_NUMBER_440           440         ///< IRQ#440
#define INTERRUPTS_IRQ_NUMBER_441           441         ///< IRQ#441
#define INTERRUPTS_IRQ_NUMBER_442           442         ///< IRQ#442
#define INTERRUPTS_IRQ_NUMBER_443           443         ///< IRQ#443
#define INTERRUPTS_IRQ_NUMBER_444           444         ///< IRQ#444
#define INTERRUPTS_IRQ_NUMBER_445           445         ///< IRQ#445
#define INTERRUPTS_IRQ_NUMBER_446           446         ///< IRQ#446
#define INTERRUPTS_IRQ_NUMBER_447           447         ///< IRQ#447
#define INTERRUPTS_IRQ_NUMBER_448           448         ///< IRQ#448
#define INTERRUPTS_IRQ_NUMBER_449           449         ///< IRQ#449
#define INTERRUPTS_IRQ_NUMBER_450           450         ///< IRQ#450
#define INTERRUPTS_IRQ_NUMBER_451           451         ///< IRQ#451
#define INTERRUPTS_IRQ_NUMBER_452           452         ///< IRQ#452
#define INTERRUPTS_IRQ_NUMBER_453           453         ///< IRQ#453
#define INTERRUPTS_IRQ_NUMBER_454           454         ///< IRQ#454
#define INTERRUPTS_IRQ_NUMBER_455           455         ///< IRQ#455
#define INTERRUPTS_IRQ_NUMBER_456           456         ///< IRQ#456
#define INTERRUPTS_IRQ_NUMBER_457           457         ///< IRQ#457
#define INTERRUPTS_IRQ_NUMBER_458           458         ///< IRQ#458
#define INTERRUPTS_IRQ_NUMBER_459           459         ///< IRQ#459
#define INTERRUPTS_IRQ_NUMBER_460           460         ///< IRQ#460
#define INTERRUPTS_IRQ_NUMBER_461           461         ///< IRQ#461
#define INTERRUPTS_IRQ_NUMBER_462           462         ///< IRQ#462
#define INTERRUPTS_IRQ_NUMBER_463           463         ///< IRQ#463
#define INTERRUPTS_IRQ_NUMBER_464           464         ///< IRQ#464
#define INTERRUPTS_IRQ_NUMBER_465           465         ///< IRQ#465
#define INTERRUPTS_IRQ_NUMBER_466           466         ///< IRQ#466
#define INTERRUPTS_IRQ_NUMBER_467           467         ///< IRQ#467
#define INTERRUPTS_IRQ_NUMBER_468           468         ///< IRQ#468
#define INTERRUPTS_IRQ_NUMBER_469           469         ///< IRQ#469
#define INTERRUPTS_IRQ_NUMBER_470           470         ///< IRQ#470
#define INTERRUPTS_IRQ_NUMBER_471           471         ///< IRQ#471
#define INTERRUPTS_IRQ_NUMBER_472           472         ///< IRQ#472
#define INTERRUPTS_IRQ_NUMBER_473           473         ///< IRQ#473
#define INTERRUPTS_IRQ_NUMBER_474           474         ///< IRQ#474
#define INTERRUPTS_IRQ_NUMBER_475           475         ///< IRQ#475
#define INTERRUPTS_IRQ_NUMBER_476           476         ///< IRQ#476
#define INTERRUPTS_IRQ_NUMBER_477           477         ///< IRQ#477
#define INTERRUPTS_IRQ_NUMBER_478           478         ///< IRQ#478
#define INTERRUPTS_IRQ_NUMBER_479           479         ///< IRQ#479
#define INTERRUPTS_IRQ_NUMBER_480           480         ///< IRQ#480
#define INTERRUPTS_IRQ_NUMBER_481           481         ///< IRQ#481
#define INTERRUPTS_IRQ_NUMBER_482           482         ///< IRQ#482
#define INTERRUPTS_IRQ_NUMBER_483           483         ///< IRQ#483
#define INTERRUPTS_IRQ_NUMBER_484           484         ///< IRQ#484
#define INTERRUPTS_IRQ_NUMBER_485           485         ///< IRQ#485
#define INTERRUPTS_IRQ_NUMBER_486           486         ///< IRQ#486
#define INTERRUPTS_IRQ_NUMBER_487           487         ///< IRQ#487
#define INTERRUPTS_IRQ_NUMBER_488           488         ///< IRQ#488
#define INTERRUPTS_IRQ_NUMBER_489           489         ///< IRQ#489
#define INTERRUPTS_IRQ_NUMBER_490           490         ///< IRQ#490
#define INTERRUPTS_IRQ_NUMBER_491           491         ///< IRQ#491
#define INTERRUPTS_IRQ_NUMBER_492           492         ///< IRQ#492
#define INTERRUPTS_IRQ_NUMBER_493           493         ///< IRQ#493
#define INTERRUPTS_IRQ_NUMBER_494           494         ///< IRQ#494
#define INTERRUPTS_IRQ_NUMBER_495           495         ///< IRQ#495
#define INTERRUPTS_IRQ_NUMBER_496           496         ///< IRQ#496
#define INTERRUPTS_IRQ_NUMBER_497           497         ///< IRQ#497
#define INTERRUPTS_IRQ_NUMBER_498           498         ///< IRQ#498
#define INTERRUPTS_IRQ_NUMBER_499           499         ///< IRQ#499
#define INTERRUPTS_IRQ_NUMBER_500           500         ///< IRQ#500
#define INTERRUPTS_IRQ_NUMBER_501           501         ///< IRQ#501
#define INTERRUPTS_IRQ_NUMBER_502           502         ///< IRQ#502
#define INTERRUPTS_IRQ_NUMBER_503           503         ///< IRQ#503
#define INTERRUPTS_IRQ_NUMBER_504           504         ///< IRQ#504
#define INTERRUPTS_IRQ_NUMBER_505           505         ///< IRQ#505
#define INTERRUPTS_IRQ_NUMBER_506           506         ///< IRQ#506
#define INTERRUPTS_IRQ_NUMBER_507           507         ///< IRQ#507
#define INTERRUPTS_IRQ_NUMBER_508           508         ///< IRQ#508
#define INTERRUPTS_IRQ_NUMBER_509           509         ///< IRQ#509
#define INTERRUPTS_IRQ_NUMBER_510           510         ///< IRQ#510
#define INTERRUPTS_IRQ_NUMBER_511           511         ///< IRQ#511

// --------------------------------------------------------------------
// 2    N M I
// --------------------------------------------------------------------
// 2.1  N M I   V E C T O R S
// --------------------------------------------------------------------
// Assignment of non-maskable interrupt vectors to interrupt service routines (ISR).
// The functions which are assigned here must be defined by using the
// macros FN_NMI_DEFINE_BEGIN() ... FN_NMI_DEFINE_END().
//
// Note: If an NMI is not used, please assign INTERRUPTS_NMI_DEFAULT_HANDLER.
//       Otherwise assign your NMI ISR function declared in the header file
//       included at the top of this file.
// --------------------------------------------------------------------

/** Macro to assign a NMI to the default NMI handler, implemented
 ** in interrupts.c (DefaultNmiHandler). */
#define INTERRUPTS_NMI_DEFAULT_HANDLER          0xFFFFFFFF

#define INTERRUPTS_NMI_ISR_0    INTERRUPTS_NMI_DEFAULT_HANDLER
#define INTERRUPTS_NMI_ISR_1    INTERRUPTS_NMI_DEFAULT_HANDLER
#define INTERRUPTS_NMI_ISR_2    INTERRUPTS_NMI_DEFAULT_HANDLER
#define INTERRUPTS_NMI_ISR_3    INTERRUPTS_NMI_DEFAULT_HANDLER
#define INTERRUPTS_NMI_ISR_4    INTERRUPTS_NMI_DEFAULT_HANDLER
#define INTERRUPTS_NMI_ISR_5    INTERRUPTS_NMI_DEFAULT_HANDLER
#define INTERRUPTS_NMI_ISR_6    PDL_NMI_ISR_HWDG
#define INTERRUPTS_NMI_ISR_7    PDL_NMI_ISR_SWDG
#define INTERRUPTS_NMI_ISR_8    INTERRUPTS_NMI_DEFAULT_HANDLER
#define INTERRUPTS_NMI_ISR_9    INTERRUPTS_NMI_DEFAULT_HANDLER
#define INTERRUPTS_NMI_ISR_10   INTERRUPTS_NMI_DEFAULT_HANDLER
#define INTERRUPTS_NMI_ISR_11   INTERRUPTS_NMI_DEFAULT_HANDLER
#define INTERRUPTS_NMI_ISR_12   INTERRUPTS_NMI_DEFAULT_HANDLER
#define INTERRUPTS_NMI_ISR_13   INTERRUPTS_NMI_DEFAULT_HANDLER
#define INTERRUPTS_NMI_ISR_14   INTERRUPTS_NMI_DEFAULT_HANDLER
#define INTERRUPTS_NMI_ISR_15   INTERRUPTS_NMI_DEFAULT_HANDLER
#define INTERRUPTS_NMI_ISR_16   INTERRUPTS_NMI_DEFAULT_HANDLER
#define INTERRUPTS_NMI_ISR_17   INTERRUPTS_NMI_DEFAULT_HANDLER
#define INTERRUPTS_NMI_ISR_18   INTERRUPTS_NMI_DEFAULT_HANDLER
#define INTERRUPTS_NMI_ISR_19   INTERRUPTS_NMI_DEFAULT_HANDLER
#define INTERRUPTS_NMI_ISR_20   INTERRUPTS_NMI_DEFAULT_HANDLER
#define INTERRUPTS_NMI_ISR_21   INTERRUPTS_NMI_DEFAULT_HANDLER
#define INTERRUPTS_NMI_ISR_22   INTERRUPTS_NMI_DEFAULT_HANDLER
#define INTERRUPTS_NMI_ISR_23   INTERRUPTS_NMI_DEFAULT_HANDLER
#define INTERRUPTS_NMI_ISR_24   INTERRUPTS_NMI_DEFAULT_HANDLER
#define INTERRUPTS_NMI_ISR_25   INTERRUPTS_NMI_DEFAULT_HANDLER
#define INTERRUPTS_NMI_ISR_26   INTERRUPTS_NMI_DEFAULT_HANDLER
#define INTERRUPTS_NMI_ISR_27   INTERRUPTS_NMI_DEFAULT_HANDLER
#define INTERRUPTS_NMI_ISR_28   INTERRUPTS_NMI_DEFAULT_HANDLER
#define INTERRUPTS_NMI_ISR_29   INTERRUPTS_NMI_DEFAULT_HANDLER
#define INTERRUPTS_NMI_ISR_30   INTERRUPTS_NMI_DEFAULT_HANDLER
#define INTERRUPTS_NMI_ISR_31   INTERRUPTS_NMI_DEFAULT_HANDLER

// --------------------------------------------------------------------
// 2.2  N M I   P R I O R I T Y   L E V E L S
// --------------------------------------------------------------------
// Definition of non-maskable interrupt priorities.
// Level 0 (highest priority) ... 15 (lowest priority)
// Note: If an NMI vector is assigned to the default NMI
//       handler (INTERRUPTS_NMI_DEFAULT_HANDLER) the corresponding
//       interrupt priority will always be set to 15, irrespective
//       of the setting here.
// Note: The priority level of NMI#0 is fixed to 0 and cannot be changed.
// --------------------------------------------------------------------
#define INTERRUPTS_NMI_LEVEL_0          0  ///< NMI#0
#define INTERRUPTS_NMI_LEVEL_1         15  ///< NMI#1
#define INTERRUPTS_NMI_LEVEL_2         15  ///< NMI#2
#define INTERRUPTS_NMI_LEVEL_3         15  ///< NMI#3
#define INTERRUPTS_NMI_LEVEL_4         15  ///< NMI#4
#define INTERRUPTS_NMI_LEVEL_5         15  ///< NMI#5
#define INTERRUPTS_NMI_LEVEL_6         15  ///< NMI#6
#define INTERRUPTS_NMI_LEVEL_7         15  ///< NMI#7
#define INTERRUPTS_NMI_LEVEL_8         15  ///< NMI#8
#define INTERRUPTS_NMI_LEVEL_9         15  ///< NMI#9
#define INTERRUPTS_NMI_LEVEL_10        15  ///< NMI#10
#define INTERRUPTS_NMI_LEVEL_11        15  ///< NMI#11
#define INTERRUPTS_NMI_LEVEL_12        15  ///< NMI#12
#define INTERRUPTS_NMI_LEVEL_13        15  ///< NMI#13
#define INTERRUPTS_NMI_LEVEL_14        15  ///< NMI#14
#define INTERRUPTS_NMI_LEVEL_15        15  ///< NMI#15
#define INTERRUPTS_NMI_LEVEL_16        15  ///< NMI#16
#define INTERRUPTS_NMI_LEVEL_17        15  ///< NMI#17
#define INTERRUPTS_NMI_LEVEL_18        15  ///< NMI#18
#define INTERRUPTS_NMI_LEVEL_19        15  ///< NMI#19
#define INTERRUPTS_NMI_LEVEL_20        15  ///< NMI#20
#define INTERRUPTS_NMI_LEVEL_21        15  ///< NMI#21
#define INTERRUPTS_NMI_LEVEL_22        15  ///< NMI#22
#define INTERRUPTS_NMI_LEVEL_23        15  ///< NMI#23
#define INTERRUPTS_NMI_LEVEL_24        15  ///< NMI#24
#define INTERRUPTS_NMI_LEVEL_25        15  ///< NMI#25
#define INTERRUPTS_NMI_LEVEL_26        15  ///< NMI#26
#define INTERRUPTS_NMI_LEVEL_27        15  ///< NMI#27
#define INTERRUPTS_NMI_LEVEL_28        15  ///< NMI#28
#define INTERRUPTS_NMI_LEVEL_29        15  ///< NMI#29
#define INTERRUPTS_NMI_LEVEL_30        15  ///< NMI#30
#define INTERRUPTS_NMI_LEVEL_31        15  ///< NMI#31

// --------------------------------------------------------------------
// 2.3  N M I   N U M B E R S
// --------------------------------------------------------------------
// Definition of NMI numbers. These macros should
// be used as parameter for ISR function definition macros
// FN_NMI_DEFINE_BEGIN( ..., NmiNum) to set the NMI
// number which must be cleared in the Interrupt Controller
// after an NMI is handled.
// --------------------------------------------------------------------
#define INTERRUPTS_NMI_NUMBER_0         0   ///< NMI#0
#define INTERRUPTS_NMI_NUMBER_1         1   ///< NMI#1
#define INTERRUPTS_NMI_NUMBER_2         2   ///< NMI#2
#define INTERRUPTS_NMI_NUMBER_3         3   ///< NMI#3
#define INTERRUPTS_NMI_NUMBER_4         4   ///< NMI#4
#define INTERRUPTS_NMI_NUMBER_5         5   ///< NMI#5
#define INTERRUPTS_NMI_NUMBER_6         6   ///< NMI#6
#define INTERRUPTS_NMI_NUMBER_7         7   ///< NMI#7
#define INTERRUPTS_NMI_NUMBER_8         8   ///< NMI#8
#define INTERRUPTS_NMI_NUMBER_9         9   ///< NMI#9
#define INTERRUPTS_NMI_NUMBER_10        10  ///< NMI#10
#define INTERRUPTS_NMI_NUMBER_11        11  ///< NMI#11
#define INTERRUPTS_NMI_NUMBER_12        12  ///< NMI#12
#define INTERRUPTS_NMI_NUMBER_13        13  ///< NMI#13
#define INTERRUPTS_NMI_NUMBER_14        14  ///< NMI#14
#define INTERRUPTS_NMI_NUMBER_15        15  ///< NMI#15
#define INTERRUPTS_NMI_NUMBER_16        16  ///< NMI#16
#define INTERRUPTS_NMI_NUMBER_17        17  ///< NMI#17
#define INTERRUPTS_NMI_NUMBER_18        18  ///< NMI#18
#define INTERRUPTS_NMI_NUMBER_19        19  ///< NMI#19
#define INTERRUPTS_NMI_NUMBER_20        20  ///< NMI#20
#define INTERRUPTS_NMI_NUMBER_21        21  ///< NMI#21
#define INTERRUPTS_NMI_NUMBER_22        22  ///< NMI#22
#define INTERRUPTS_NMI_NUMBER_23        23  ///< NMI#23
#define INTERRUPTS_NMI_NUMBER_24        24  ///< NMI#24
#define INTERRUPTS_NMI_NUMBER_25        25  ///< NMI#25
#define INTERRUPTS_NMI_NUMBER_26        26  ///< NMI#26
#define INTERRUPTS_NMI_NUMBER_27        27  ///< NMI#27
#define INTERRUPTS_NMI_NUMBER_28        28  ///< NMI#28
#define INTERRUPTS_NMI_NUMBER_29        29  ///< NMI#29
#define INTERRUPTS_NMI_NUMBER_30        30  ///< NMI#30
#define INTERRUPTS_NMI_NUMBER_31        31  ///< NMI#31

/*****************************************************************************/
/* ISR function prototype declaration ('extern' declaration)                 */
/*****************************************************************************/

#ifdef __TOOLCHAIN_GHS_MULTI__
    #define FN_IRQ_DECLARE(IrqIsrName)      extern FN_IRQ_NOT_NESTED    void IrqIsrName(void)
    #define FN_NMI_DECLARE(NmiIsrName)      extern FN_NMI               void NmiIsrName(void)
#elif defined __TOOLCHAIN_IAR__
    #define FN_IRQ_DECLARE(IrqIsrName)      extern FN_IRQ_NESTED    void IrqIsrName(void)
    #define FN_NMI_DECLARE(NmiIsrName)      extern FN_NMI           void NmiIsrName(void)
    // suppress warning "zero used for undefined preprocessing identifier"
    #pragma diag_suppress=Pe193
#elif WIN32
    #define FN_IRQ_DECLARE(IrqIsrName)
    #define FN_NMI_DECLARE(NmiIsrName)
#endif

#if (INTERRUPTS_IRQ_ISR_0 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_0);
#endif
#if (INTERRUPTS_IRQ_ISR_1 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_1);
#endif
#if (INTERRUPTS_IRQ_ISR_2 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_2);
#endif
#if (INTERRUPTS_IRQ_ISR_3 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_3);
#endif
#if (INTERRUPTS_IRQ_ISR_4 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_4);
#endif
#if (INTERRUPTS_IRQ_ISR_5 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_5);
#endif
#if (INTERRUPTS_IRQ_ISR_6 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_6);
#endif
#if (INTERRUPTS_IRQ_ISR_7 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_7);
#endif
#if (INTERRUPTS_IRQ_ISR_8 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_8);
#endif
#if (INTERRUPTS_IRQ_ISR_9 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_9);
#endif
#if (INTERRUPTS_IRQ_ISR_10 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_10);
#endif
#if (INTERRUPTS_IRQ_ISR_11 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_11);
#endif
#if (INTERRUPTS_IRQ_ISR_12 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_12);
#endif
#if (INTERRUPTS_IRQ_ISR_13 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_13);
#endif
#if (INTERRUPTS_IRQ_ISR_14 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_14);
#endif
#if (INTERRUPTS_IRQ_ISR_15 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_15);
#endif
#if (INTERRUPTS_IRQ_ISR_16 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_16);
#endif
#if (INTERRUPTS_IRQ_ISR_17 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_17);
#endif
#if (INTERRUPTS_IRQ_ISR_18 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_18);
#endif
#if (INTERRUPTS_IRQ_ISR_19 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_19);
#endif
#if (INTERRUPTS_IRQ_ISR_20 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_20);
#endif
#if (INTERRUPTS_IRQ_ISR_21 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_21);
#endif
#if (INTERRUPTS_IRQ_ISR_22 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_22);
#endif
#if (INTERRUPTS_IRQ_ISR_23 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_23);
#endif
#if (INTERRUPTS_IRQ_ISR_24 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_24);
#endif
#if (INTERRUPTS_IRQ_ISR_25 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_25);
#endif
#if (INTERRUPTS_IRQ_ISR_26 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_26);
#endif
#if (INTERRUPTS_IRQ_ISR_27 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_27);
#endif
#if (INTERRUPTS_IRQ_ISR_28 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_28);
#endif
#if (INTERRUPTS_IRQ_ISR_29 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_29);
#endif
#if (INTERRUPTS_IRQ_ISR_30 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_30);
#endif
#if (INTERRUPTS_IRQ_ISR_31 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_31);
#endif
#if (INTERRUPTS_IRQ_ISR_32 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_32);
#endif
#if (INTERRUPTS_IRQ_ISR_33 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_33);
#endif
#if (INTERRUPTS_IRQ_ISR_34 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_34);
#endif
#if (INTERRUPTS_IRQ_ISR_35 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_35);
#endif
#if (INTERRUPTS_IRQ_ISR_36 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_36);
#endif
#if (INTERRUPTS_IRQ_ISR_37 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_37);
#endif
#if (INTERRUPTS_IRQ_ISR_38 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_38);
#endif
#if (INTERRUPTS_IRQ_ISR_39 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_39);
#endif
#if (INTERRUPTS_IRQ_ISR_40 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_40);
#endif
#if (INTERRUPTS_IRQ_ISR_41 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_41);
#endif
#if (INTERRUPTS_IRQ_ISR_42 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_42);
#endif
#if (INTERRUPTS_IRQ_ISR_43 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_43);
#endif
#if (INTERRUPTS_IRQ_ISR_44 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_44);
#endif
#if (INTERRUPTS_IRQ_ISR_45 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_45);
#endif
#if (INTERRUPTS_IRQ_ISR_46 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_46);
#endif
#if (INTERRUPTS_IRQ_ISR_47 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_47);
#endif
#if (INTERRUPTS_IRQ_ISR_48 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_48);
#endif
#if (INTERRUPTS_IRQ_ISR_49 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_49);
#endif
#if (INTERRUPTS_IRQ_ISR_50 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_50);
#endif
#if (INTERRUPTS_IRQ_ISR_51 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_51);
#endif
#if (INTERRUPTS_IRQ_ISR_52 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_52);
#endif
#if (INTERRUPTS_IRQ_ISR_53 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_53);
#endif
#if (INTERRUPTS_IRQ_ISR_54 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_54);
#endif
#if (INTERRUPTS_IRQ_ISR_55 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_55);
#endif
#if (INTERRUPTS_IRQ_ISR_56 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_56);
#endif
#if (INTERRUPTS_IRQ_ISR_57 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_57);
#endif
#if (INTERRUPTS_IRQ_ISR_58 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_58);
#endif
#if (INTERRUPTS_IRQ_ISR_59 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_59);
#endif
#if (INTERRUPTS_IRQ_ISR_60 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_60);
#endif
#if (INTERRUPTS_IRQ_ISR_61 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_61);
#endif
#if (INTERRUPTS_IRQ_ISR_62 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_62);
#endif
#if (INTERRUPTS_IRQ_ISR_63 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_63);
#endif
#if (INTERRUPTS_IRQ_ISR_64 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_64);
#endif
#if (INTERRUPTS_IRQ_ISR_65 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_65);
#endif
#if (INTERRUPTS_IRQ_ISR_66 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_66);
#endif
#if (INTERRUPTS_IRQ_ISR_67 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_67);
#endif
#if (INTERRUPTS_IRQ_ISR_68 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_68);
#endif
#if (INTERRUPTS_IRQ_ISR_69 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_69);
#endif
#if (INTERRUPTS_IRQ_ISR_70 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_70);
#endif
#if (INTERRUPTS_IRQ_ISR_71 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_71);
#endif
#if (INTERRUPTS_IRQ_ISR_72 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_72);
#endif
#if (INTERRUPTS_IRQ_ISR_73 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_73);
#endif
#if (INTERRUPTS_IRQ_ISR_74 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_74);
#endif
#if (INTERRUPTS_IRQ_ISR_75 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_75);
#endif
#if (INTERRUPTS_IRQ_ISR_76 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_76);
#endif
#if (INTERRUPTS_IRQ_ISR_77 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_77);
#endif
#if (INTERRUPTS_IRQ_ISR_78 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_78);
#endif
#if (INTERRUPTS_IRQ_ISR_79 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_79);
#endif
#if (INTERRUPTS_IRQ_ISR_80 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_80);
#endif
#if (INTERRUPTS_IRQ_ISR_81 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_81);
#endif
#if (INTERRUPTS_IRQ_ISR_82 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_82);
#endif
#if (INTERRUPTS_IRQ_ISR_83 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_83);
#endif
#if (INTERRUPTS_IRQ_ISR_84 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_84);
#endif
#if (INTERRUPTS_IRQ_ISR_85 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_85);
#endif
#if (INTERRUPTS_IRQ_ISR_86 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_86);
#endif
#if (INTERRUPTS_IRQ_ISR_87 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_87);
#endif
#if (INTERRUPTS_IRQ_ISR_88 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_88);
#endif
#if (INTERRUPTS_IRQ_ISR_89 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_89);
#endif
#if (INTERRUPTS_IRQ_ISR_90 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_90);
#endif
#if (INTERRUPTS_IRQ_ISR_91 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_91);
#endif
#if (INTERRUPTS_IRQ_ISR_92 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_92);
#endif
#if (INTERRUPTS_IRQ_ISR_93 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_93);
#endif
#if (INTERRUPTS_IRQ_ISR_94 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_94);
#endif
#if (INTERRUPTS_IRQ_ISR_95 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_95);
#endif
#if (INTERRUPTS_IRQ_ISR_96 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_96);
#endif
#if (INTERRUPTS_IRQ_ISR_97 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_97);
#endif
#if (INTERRUPTS_IRQ_ISR_98 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_98);
#endif
#if (INTERRUPTS_IRQ_ISR_99 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_99);
#endif
#if (INTERRUPTS_IRQ_ISR_100 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_100);
#endif
#if (INTERRUPTS_IRQ_ISR_101 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_101);
#endif
#if (INTERRUPTS_IRQ_ISR_102 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_102);
#endif
#if (INTERRUPTS_IRQ_ISR_103 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_103);
#endif
#if (INTERRUPTS_IRQ_ISR_104 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_104);
#endif
#if (INTERRUPTS_IRQ_ISR_105 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_105);
#endif
#if (INTERRUPTS_IRQ_ISR_106 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_106);
#endif
#if (INTERRUPTS_IRQ_ISR_107 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_107);
#endif
#if (INTERRUPTS_IRQ_ISR_108 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_108);
#endif
#if (INTERRUPTS_IRQ_ISR_109 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_109);
#endif
#if (INTERRUPTS_IRQ_ISR_110 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_110);
#endif
#if (INTERRUPTS_IRQ_ISR_111 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_111);
#endif
#if (INTERRUPTS_IRQ_ISR_112 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_112);
#endif
#if (INTERRUPTS_IRQ_ISR_113 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_113);
#endif
#if (INTERRUPTS_IRQ_ISR_114 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_114);
#endif
#if (INTERRUPTS_IRQ_ISR_115 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_115);
#endif
#if (INTERRUPTS_IRQ_ISR_116 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_116);
#endif
#if (INTERRUPTS_IRQ_ISR_117 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_117);
#endif
#if (INTERRUPTS_IRQ_ISR_118 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_118);
#endif
#if (INTERRUPTS_IRQ_ISR_119 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_119);
#endif
#if (INTERRUPTS_IRQ_ISR_120 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_120);
#endif
#if (INTERRUPTS_IRQ_ISR_121 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_121);
#endif
#if (INTERRUPTS_IRQ_ISR_122 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_122);
#endif
#if (INTERRUPTS_IRQ_ISR_123 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_123);
#endif
#if (INTERRUPTS_IRQ_ISR_124 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_124);
#endif
#if (INTERRUPTS_IRQ_ISR_125 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_125);
#endif
#if (INTERRUPTS_IRQ_ISR_126 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_126);
#endif
#if (INTERRUPTS_IRQ_ISR_127 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_127);
#endif
#if (INTERRUPTS_IRQ_ISR_128 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_128);
#endif
#if (INTERRUPTS_IRQ_ISR_129 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_129);
#endif
#if (INTERRUPTS_IRQ_ISR_130 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_130);
#endif
#if (INTERRUPTS_IRQ_ISR_131 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_131);
#endif
#if (INTERRUPTS_IRQ_ISR_132 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_132);
#endif
#if (INTERRUPTS_IRQ_ISR_133 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_133);
#endif
#if (INTERRUPTS_IRQ_ISR_134 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_134);
#endif
#if (INTERRUPTS_IRQ_ISR_135 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_135);
#endif
#if (INTERRUPTS_IRQ_ISR_136 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_136);
#endif
#if (INTERRUPTS_IRQ_ISR_137 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_137);
#endif
#if (INTERRUPTS_IRQ_ISR_138 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_138);
#endif
#if (INTERRUPTS_IRQ_ISR_139 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_139);
#endif
#if (INTERRUPTS_IRQ_ISR_140 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_140);
#endif
#if (INTERRUPTS_IRQ_ISR_141 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_141);
#endif
#if (INTERRUPTS_IRQ_ISR_142 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_142);
#endif
#if (INTERRUPTS_IRQ_ISR_143 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_143);
#endif
#if (INTERRUPTS_IRQ_ISR_144 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_144);
#endif
#if (INTERRUPTS_IRQ_ISR_145 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_145);
#endif
#if (INTERRUPTS_IRQ_ISR_146 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_146);
#endif
#if (INTERRUPTS_IRQ_ISR_147 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_147);
#endif
#if (INTERRUPTS_IRQ_ISR_148 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_148);
#endif
#if (INTERRUPTS_IRQ_ISR_149 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_149);
#endif
#if (INTERRUPTS_IRQ_ISR_150 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_150);
#endif
#if (INTERRUPTS_IRQ_ISR_151 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_151);
#endif
#if (INTERRUPTS_IRQ_ISR_152 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_152);
#endif
#if (INTERRUPTS_IRQ_ISR_153 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_153);
#endif
#if (INTERRUPTS_IRQ_ISR_154 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_154);
#endif
#if (INTERRUPTS_IRQ_ISR_155 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_155);
#endif
#if (INTERRUPTS_IRQ_ISR_156 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_156);
#endif
#if (INTERRUPTS_IRQ_ISR_157 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_157);
#endif
#if (INTERRUPTS_IRQ_ISR_158 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_158);
#endif
#if (INTERRUPTS_IRQ_ISR_159 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_159);
#endif
#if (INTERRUPTS_IRQ_ISR_160 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_160);
#endif
#if (INTERRUPTS_IRQ_ISR_161 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_161);
#endif
#if (INTERRUPTS_IRQ_ISR_162 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_162);
#endif
#if (INTERRUPTS_IRQ_ISR_163 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_163);
#endif
#if (INTERRUPTS_IRQ_ISR_164 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_164);
#endif
#if (INTERRUPTS_IRQ_ISR_165 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_165);
#endif
#if (INTERRUPTS_IRQ_ISR_166 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_166);
#endif
#if (INTERRUPTS_IRQ_ISR_167 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_167);
#endif
#if (INTERRUPTS_IRQ_ISR_168 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_168);
#endif
#if (INTERRUPTS_IRQ_ISR_169 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_169);
#endif
#if (INTERRUPTS_IRQ_ISR_170 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_170);
#endif
#if (INTERRUPTS_IRQ_ISR_171 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_171);
#endif
#if (INTERRUPTS_IRQ_ISR_172 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_172);
#endif
#if (INTERRUPTS_IRQ_ISR_173 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_173);
#endif
#if (INTERRUPTS_IRQ_ISR_174 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_174);
#endif
#if (INTERRUPTS_IRQ_ISR_175 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_175);
#endif
#if (INTERRUPTS_IRQ_ISR_176 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_176);
#endif
#if (INTERRUPTS_IRQ_ISR_177 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_177);
#endif
#if (INTERRUPTS_IRQ_ISR_178 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_178);
#endif
#if (INTERRUPTS_IRQ_ISR_179 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_179);
#endif
#if (INTERRUPTS_IRQ_ISR_180 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_180);
#endif
#if (INTERRUPTS_IRQ_ISR_181 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_181);
#endif
#if (INTERRUPTS_IRQ_ISR_182 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_182);
#endif
#if (INTERRUPTS_IRQ_ISR_183 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_183);
#endif
#if (INTERRUPTS_IRQ_ISR_184 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_184);
#endif
#if (INTERRUPTS_IRQ_ISR_185 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_185);
#endif
#if (INTERRUPTS_IRQ_ISR_186 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_186);
#endif
#if (INTERRUPTS_IRQ_ISR_187 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_187);
#endif
#if (INTERRUPTS_IRQ_ISR_188 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_188);
#endif
#if (INTERRUPTS_IRQ_ISR_189 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_189);
#endif
#if (INTERRUPTS_IRQ_ISR_190 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_190);
#endif
#if (INTERRUPTS_IRQ_ISR_191 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_191);
#endif
#if (INTERRUPTS_IRQ_ISR_192 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_192);
#endif
#if (INTERRUPTS_IRQ_ISR_193 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_193);
#endif
#if (INTERRUPTS_IRQ_ISR_194 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_194);
#endif
#if (INTERRUPTS_IRQ_ISR_195 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_195);
#endif
#if (INTERRUPTS_IRQ_ISR_196 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_196);
#endif
#if (INTERRUPTS_IRQ_ISR_197 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_197);
#endif
#if (INTERRUPTS_IRQ_ISR_198 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_198);
#endif
#if (INTERRUPTS_IRQ_ISR_199 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_199);
#endif
#if (INTERRUPTS_IRQ_ISR_200 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_200);
#endif
#if (INTERRUPTS_IRQ_ISR_201 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_201);
#endif
#if (INTERRUPTS_IRQ_ISR_202 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_202);
#endif
#if (INTERRUPTS_IRQ_ISR_203 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_203);
#endif
#if (INTERRUPTS_IRQ_ISR_204 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_204);
#endif
#if (INTERRUPTS_IRQ_ISR_205 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_205);
#endif
#if (INTERRUPTS_IRQ_ISR_206 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_206);
#endif
#if (INTERRUPTS_IRQ_ISR_207 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_207);
#endif
#if (INTERRUPTS_IRQ_ISR_208 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_208);
#endif
#if (INTERRUPTS_IRQ_ISR_209 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_209);
#endif
#if (INTERRUPTS_IRQ_ISR_210 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_210);
#endif
#if (INTERRUPTS_IRQ_ISR_211 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_211);
#endif
#if (INTERRUPTS_IRQ_ISR_212 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_212);
#endif
#if (INTERRUPTS_IRQ_ISR_213 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_213);
#endif
#if (INTERRUPTS_IRQ_ISR_214 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_214);
#endif
#if (INTERRUPTS_IRQ_ISR_215 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_215);
#endif
#if (INTERRUPTS_IRQ_ISR_216 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_216);
#endif
#if (INTERRUPTS_IRQ_ISR_217 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_217);
#endif
#if (INTERRUPTS_IRQ_ISR_218 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_218);
#endif
#if (INTERRUPTS_IRQ_ISR_219 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_219);
#endif
#if (INTERRUPTS_IRQ_ISR_220 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_220);
#endif
#if (INTERRUPTS_IRQ_ISR_221 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_221);
#endif
#if (INTERRUPTS_IRQ_ISR_222 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_222);
#endif
#if (INTERRUPTS_IRQ_ISR_223 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_223);
#endif
#if (INTERRUPTS_IRQ_ISR_224 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_224);
#endif
#if (INTERRUPTS_IRQ_ISR_225 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_225);
#endif
#if (INTERRUPTS_IRQ_ISR_226 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_226);
#endif
#if (INTERRUPTS_IRQ_ISR_227 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_227);
#endif
#if (INTERRUPTS_IRQ_ISR_228 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_228);
#endif
#if (INTERRUPTS_IRQ_ISR_229 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_229);
#endif
#if (INTERRUPTS_IRQ_ISR_230 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_230);
#endif
#if (INTERRUPTS_IRQ_ISR_231 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_231);
#endif
#if (INTERRUPTS_IRQ_ISR_232 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_232);
#endif
#if (INTERRUPTS_IRQ_ISR_233 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_233);
#endif
#if (INTERRUPTS_IRQ_ISR_234 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_234);
#endif
#if (INTERRUPTS_IRQ_ISR_235 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_235);
#endif
#if (INTERRUPTS_IRQ_ISR_236 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_236);
#endif
#if (INTERRUPTS_IRQ_ISR_237 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_237);
#endif
#if (INTERRUPTS_IRQ_ISR_238 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_238);
#endif
#if (INTERRUPTS_IRQ_ISR_239 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_239);
#endif
#if (INTERRUPTS_IRQ_ISR_240 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_240);
#endif
#if (INTERRUPTS_IRQ_ISR_241 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_241);
#endif
#if (INTERRUPTS_IRQ_ISR_242 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_242);
#endif
#if (INTERRUPTS_IRQ_ISR_243 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_243);
#endif
#if (INTERRUPTS_IRQ_ISR_244 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_244);
#endif
#if (INTERRUPTS_IRQ_ISR_245 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_245);
#endif
#if (INTERRUPTS_IRQ_ISR_246 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_246);
#endif
#if (INTERRUPTS_IRQ_ISR_247 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_247);
#endif
#if (INTERRUPTS_IRQ_ISR_248 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_248);
#endif
#if (INTERRUPTS_IRQ_ISR_249 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_249);
#endif
#if (INTERRUPTS_IRQ_ISR_250 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_250);
#endif
#if (INTERRUPTS_IRQ_ISR_251 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_251);
#endif
#if (INTERRUPTS_IRQ_ISR_252 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_252);
#endif
#if (INTERRUPTS_IRQ_ISR_253 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_253);
#endif
#if (INTERRUPTS_IRQ_ISR_254 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_254);
#endif
#if (INTERRUPTS_IRQ_ISR_255 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_255);
#endif
#if (INTERRUPTS_IRQ_ISR_256 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_256);
#endif
#if (INTERRUPTS_IRQ_ISR_257 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_257);
#endif
#if (INTERRUPTS_IRQ_ISR_258 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_258);
#endif
#if (INTERRUPTS_IRQ_ISR_259 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_259);
#endif
#if (INTERRUPTS_IRQ_ISR_260 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_260);
#endif
#if (INTERRUPTS_IRQ_ISR_261 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_261);
#endif
#if (INTERRUPTS_IRQ_ISR_262 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_262);
#endif
#if (INTERRUPTS_IRQ_ISR_263 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_263);
#endif
#if (INTERRUPTS_IRQ_ISR_264 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_264);
#endif
#if (INTERRUPTS_IRQ_ISR_265 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_265);
#endif
#if (INTERRUPTS_IRQ_ISR_266 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_266);
#endif
#if (INTERRUPTS_IRQ_ISR_267 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_267);
#endif
#if (INTERRUPTS_IRQ_ISR_268 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_268);
#endif
#if (INTERRUPTS_IRQ_ISR_269 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_269);
#endif
#if (INTERRUPTS_IRQ_ISR_270 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_270);
#endif
#if (INTERRUPTS_IRQ_ISR_271 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_271);
#endif
#if (INTERRUPTS_IRQ_ISR_272 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_272);
#endif
#if (INTERRUPTS_IRQ_ISR_273 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_273);
#endif
#if (INTERRUPTS_IRQ_ISR_274 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_274);
#endif
#if (INTERRUPTS_IRQ_ISR_275 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_275);
#endif
#if (INTERRUPTS_IRQ_ISR_276 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_276);
#endif
#if (INTERRUPTS_IRQ_ISR_277 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_277);
#endif
#if (INTERRUPTS_IRQ_ISR_278 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_278);
#endif
#if (INTERRUPTS_IRQ_ISR_279 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_279);
#endif
#if (INTERRUPTS_IRQ_ISR_280 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_280);
#endif
#if (INTERRUPTS_IRQ_ISR_281 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_281);
#endif
#if (INTERRUPTS_IRQ_ISR_282 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_282);
#endif
#if (INTERRUPTS_IRQ_ISR_283 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_283);
#endif
#if (INTERRUPTS_IRQ_ISR_284 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_284);
#endif
#if (INTERRUPTS_IRQ_ISR_285 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_285);
#endif
#if (INTERRUPTS_IRQ_ISR_286 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_286);
#endif
#if (INTERRUPTS_IRQ_ISR_287 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_287);
#endif
#if (INTERRUPTS_IRQ_ISR_288 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_288);
#endif
#if (INTERRUPTS_IRQ_ISR_289 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_289);
#endif
#if (INTERRUPTS_IRQ_ISR_290 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_290);
#endif
#if (INTERRUPTS_IRQ_ISR_291 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_291);
#endif
#if (INTERRUPTS_IRQ_ISR_292 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_292);
#endif
#if (INTERRUPTS_IRQ_ISR_293 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_293);
#endif
#if (INTERRUPTS_IRQ_ISR_294 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_294);
#endif
#if (INTERRUPTS_IRQ_ISR_295 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_295);
#endif
#if (INTERRUPTS_IRQ_ISR_296 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_296);
#endif
#if (INTERRUPTS_IRQ_ISR_297 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_297);
#endif
#if (INTERRUPTS_IRQ_ISR_298 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_298);
#endif
#if (INTERRUPTS_IRQ_ISR_299 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_299);
#endif
#if (INTERRUPTS_IRQ_ISR_300 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_300);
#endif
#if (INTERRUPTS_IRQ_ISR_301 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_301);
#endif
#if (INTERRUPTS_IRQ_ISR_302 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_302);
#endif
#if (INTERRUPTS_IRQ_ISR_303 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_303);
#endif
#if (INTERRUPTS_IRQ_ISR_304 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_304);
#endif
#if (INTERRUPTS_IRQ_ISR_305 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_305);
#endif
#if (INTERRUPTS_IRQ_ISR_306 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_306);
#endif
#if (INTERRUPTS_IRQ_ISR_307 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_307);
#endif
#if (INTERRUPTS_IRQ_ISR_308 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_308);
#endif
#if (INTERRUPTS_IRQ_ISR_309 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_309);
#endif
#if (INTERRUPTS_IRQ_ISR_310 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_310);
#endif
#if (INTERRUPTS_IRQ_ISR_311 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_311);
#endif
#if (INTERRUPTS_IRQ_ISR_312 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_312);
#endif
#if (INTERRUPTS_IRQ_ISR_313 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_313);
#endif
#if (INTERRUPTS_IRQ_ISR_314 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_314);
#endif
#if (INTERRUPTS_IRQ_ISR_315 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_315);
#endif
#if (INTERRUPTS_IRQ_ISR_316 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_316);
#endif
#if (INTERRUPTS_IRQ_ISR_317 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_317);
#endif
#if (INTERRUPTS_IRQ_ISR_318 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_318);
#endif
#if (INTERRUPTS_IRQ_ISR_319 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_319);
#endif
#if (INTERRUPTS_IRQ_ISR_320 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_320);
#endif
#if (INTERRUPTS_IRQ_ISR_321 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_321);
#endif
#if (INTERRUPTS_IRQ_ISR_322 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_322);
#endif
#if (INTERRUPTS_IRQ_ISR_323 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_323);
#endif
#if (INTERRUPTS_IRQ_ISR_324 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_324);
#endif
#if (INTERRUPTS_IRQ_ISR_325 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_325);
#endif
#if (INTERRUPTS_IRQ_ISR_326 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_326);
#endif
#if (INTERRUPTS_IRQ_ISR_327 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_327);
#endif
#if (INTERRUPTS_IRQ_ISR_328 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_328);
#endif
#if (INTERRUPTS_IRQ_ISR_329 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_329);
#endif
#if (INTERRUPTS_IRQ_ISR_330 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_330);
#endif
#if (INTERRUPTS_IRQ_ISR_331 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_331);
#endif
#if (INTERRUPTS_IRQ_ISR_332 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_332);
#endif
#if (INTERRUPTS_IRQ_ISR_333 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_333);
#endif
#if (INTERRUPTS_IRQ_ISR_334 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_334);
#endif
#if (INTERRUPTS_IRQ_ISR_335 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_335);
#endif
#if (INTERRUPTS_IRQ_ISR_336 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_336);
#endif
#if (INTERRUPTS_IRQ_ISR_337 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_337);
#endif
#if (INTERRUPTS_IRQ_ISR_338 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_338);
#endif
#if (INTERRUPTS_IRQ_ISR_339 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_339);
#endif
#if (INTERRUPTS_IRQ_ISR_340 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_340);
#endif
#if (INTERRUPTS_IRQ_ISR_341 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_341);
#endif
#if (INTERRUPTS_IRQ_ISR_342 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_342);
#endif
#if (INTERRUPTS_IRQ_ISR_343 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_343);
#endif
#if (INTERRUPTS_IRQ_ISR_344 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_344);
#endif
#if (INTERRUPTS_IRQ_ISR_345 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_345);
#endif
#if (INTERRUPTS_IRQ_ISR_346 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_346);
#endif
#if (INTERRUPTS_IRQ_ISR_347 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_347);
#endif
#if (INTERRUPTS_IRQ_ISR_348 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_348);
#endif
#if (INTERRUPTS_IRQ_ISR_349 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_349);
#endif
#if (INTERRUPTS_IRQ_ISR_350 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_350);
#endif
#if (INTERRUPTS_IRQ_ISR_351 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_351);
#endif
#if (INTERRUPTS_IRQ_ISR_352 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_352);
#endif
#if (INTERRUPTS_IRQ_ISR_353 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_353);
#endif
#if (INTERRUPTS_IRQ_ISR_354 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_354);
#endif
#if (INTERRUPTS_IRQ_ISR_355 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_355);
#endif
#if (INTERRUPTS_IRQ_ISR_356 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_356);
#endif
#if (INTERRUPTS_IRQ_ISR_357 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_357);
#endif
#if (INTERRUPTS_IRQ_ISR_358 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_358);
#endif
#if (INTERRUPTS_IRQ_ISR_359 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_359);
#endif
#if (INTERRUPTS_IRQ_ISR_360 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_360);
#endif
#if (INTERRUPTS_IRQ_ISR_361 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_361);
#endif
#if (INTERRUPTS_IRQ_ISR_362 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_362);
#endif
#if (INTERRUPTS_IRQ_ISR_363 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_363);
#endif
#if (INTERRUPTS_IRQ_ISR_364 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_364);
#endif
#if (INTERRUPTS_IRQ_ISR_365 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_365);
#endif
#if (INTERRUPTS_IRQ_ISR_366 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_366);
#endif
#if (INTERRUPTS_IRQ_ISR_367 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_367);
#endif
#if (INTERRUPTS_IRQ_ISR_368 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_368);
#endif
#if (INTERRUPTS_IRQ_ISR_369 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_369);
#endif
#if (INTERRUPTS_IRQ_ISR_370 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_370);
#endif
#if (INTERRUPTS_IRQ_ISR_371 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_371);
#endif
#if (INTERRUPTS_IRQ_ISR_372 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_372);
#endif
#if (INTERRUPTS_IRQ_ISR_373 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_373);
#endif
#if (INTERRUPTS_IRQ_ISR_374 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_374);
#endif
#if (INTERRUPTS_IRQ_ISR_375 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_375);
#endif
#if (INTERRUPTS_IRQ_ISR_376 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_376);
#endif
#if (INTERRUPTS_IRQ_ISR_377 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_377);
#endif
#if (INTERRUPTS_IRQ_ISR_378 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_378);
#endif
#if (INTERRUPTS_IRQ_ISR_379 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_379);
#endif
#if (INTERRUPTS_IRQ_ISR_380 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_380);
#endif
#if (INTERRUPTS_IRQ_ISR_381 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_381);
#endif
#if (INTERRUPTS_IRQ_ISR_382 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_382);
#endif
#if (INTERRUPTS_IRQ_ISR_383 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_383);
#endif
#if (INTERRUPTS_IRQ_ISR_384 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_384);
#endif
#if (INTERRUPTS_IRQ_ISR_385 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_385);
#endif
#if (INTERRUPTS_IRQ_ISR_386 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_386);
#endif
#if (INTERRUPTS_IRQ_ISR_387 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_387);
#endif
#if (INTERRUPTS_IRQ_ISR_388 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_388);
#endif
#if (INTERRUPTS_IRQ_ISR_389 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_389);
#endif
#if (INTERRUPTS_IRQ_ISR_390 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_390);
#endif
#if (INTERRUPTS_IRQ_ISR_391 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_391);
#endif
#if (INTERRUPTS_IRQ_ISR_392 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_392);
#endif
#if (INTERRUPTS_IRQ_ISR_393 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_393);
#endif
#if (INTERRUPTS_IRQ_ISR_394 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_394);
#endif
#if (INTERRUPTS_IRQ_ISR_395 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_395);
#endif
#if (INTERRUPTS_IRQ_ISR_396 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_396);
#endif
#if (INTERRUPTS_IRQ_ISR_397 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_397);
#endif
#if (INTERRUPTS_IRQ_ISR_398 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_398);
#endif
#if (INTERRUPTS_IRQ_ISR_399 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_399);
#endif
#if (INTERRUPTS_IRQ_ISR_400 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_400);
#endif
#if (INTERRUPTS_IRQ_ISR_401 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_401);
#endif
#if (INTERRUPTS_IRQ_ISR_402 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_402);
#endif
#if (INTERRUPTS_IRQ_ISR_403 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_403);
#endif
#if (INTERRUPTS_IRQ_ISR_404 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_404);
#endif
#if (INTERRUPTS_IRQ_ISR_405 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_405);
#endif
#if (INTERRUPTS_IRQ_ISR_406 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_406);
#endif
#if (INTERRUPTS_IRQ_ISR_407 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_407);
#endif
#if (INTERRUPTS_IRQ_ISR_408 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_408);
#endif
#if (INTERRUPTS_IRQ_ISR_409 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_409);
#endif
#if (INTERRUPTS_IRQ_ISR_410 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_410);
#endif
#if (INTERRUPTS_IRQ_ISR_411 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_411);
#endif
#if (INTERRUPTS_IRQ_ISR_412 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_412);
#endif
#if (INTERRUPTS_IRQ_ISR_413 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_413);
#endif
#if (INTERRUPTS_IRQ_ISR_414 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_414);
#endif
#if (INTERRUPTS_IRQ_ISR_415 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_415);
#endif
#if (INTERRUPTS_IRQ_ISR_416 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_416);
#endif
#if (INTERRUPTS_IRQ_ISR_417 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_417);
#endif
#if (INTERRUPTS_IRQ_ISR_418 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_418);
#endif
#if (INTERRUPTS_IRQ_ISR_419 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_419);
#endif
#if (INTERRUPTS_IRQ_ISR_420 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_420);
#endif
#if (INTERRUPTS_IRQ_ISR_421 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_421);
#endif
#if (INTERRUPTS_IRQ_ISR_422 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_422);
#endif
#if (INTERRUPTS_IRQ_ISR_423 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_423);
#endif
#if (INTERRUPTS_IRQ_ISR_424 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_424);
#endif
#if (INTERRUPTS_IRQ_ISR_425 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_425);
#endif
#if (INTERRUPTS_IRQ_ISR_426 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_426);
#endif
#if (INTERRUPTS_IRQ_ISR_427 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_427);
#endif
#if (INTERRUPTS_IRQ_ISR_428 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_428);
#endif
#if (INTERRUPTS_IRQ_ISR_429 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_429);
#endif
#if (INTERRUPTS_IRQ_ISR_430 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_430);
#endif
#if (INTERRUPTS_IRQ_ISR_431 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_431);
#endif
#if (INTERRUPTS_IRQ_ISR_432 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_432);
#endif
#if (INTERRUPTS_IRQ_ISR_433 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_433);
#endif
#if (INTERRUPTS_IRQ_ISR_434 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_434);
#endif
#if (INTERRUPTS_IRQ_ISR_435 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_435);
#endif
#if (INTERRUPTS_IRQ_ISR_436 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_436);
#endif
#if (INTERRUPTS_IRQ_ISR_437 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_437);
#endif
#if (INTERRUPTS_IRQ_ISR_438 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_438);
#endif
#if (INTERRUPTS_IRQ_ISR_439 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_439);
#endif
#if (INTERRUPTS_IRQ_ISR_440 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_440);
#endif
#if (INTERRUPTS_IRQ_ISR_441 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_441);
#endif
#if (INTERRUPTS_IRQ_ISR_442 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_442);
#endif
#if (INTERRUPTS_IRQ_ISR_443 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_443);
#endif
#if (INTERRUPTS_IRQ_ISR_444 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_444);
#endif
#if (INTERRUPTS_IRQ_ISR_445 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_445);
#endif
#if (INTERRUPTS_IRQ_ISR_446 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_446);
#endif
#if (INTERRUPTS_IRQ_ISR_447 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_447);
#endif
#if (INTERRUPTS_IRQ_ISR_448 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_448);
#endif
#if (INTERRUPTS_IRQ_ISR_449 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_449);
#endif
#if (INTERRUPTS_IRQ_ISR_450 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_450);
#endif
#if (INTERRUPTS_IRQ_ISR_451 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_451);
#endif
#if (INTERRUPTS_IRQ_ISR_452 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_452);
#endif
#if (INTERRUPTS_IRQ_ISR_453 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_453);
#endif
#if (INTERRUPTS_IRQ_ISR_454 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_454);
#endif
#if (INTERRUPTS_IRQ_ISR_455 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_455);
#endif
#if (INTERRUPTS_IRQ_ISR_456 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_456);
#endif
#if (INTERRUPTS_IRQ_ISR_457 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_457);
#endif
#if (INTERRUPTS_IRQ_ISR_458 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_458);
#endif
#if (INTERRUPTS_IRQ_ISR_459 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_459);
#endif
#if (INTERRUPTS_IRQ_ISR_460 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_460);
#endif
#if (INTERRUPTS_IRQ_ISR_461 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_461);
#endif
#if (INTERRUPTS_IRQ_ISR_462 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_462);
#endif
#if (INTERRUPTS_IRQ_ISR_463 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_463);
#endif
#if (INTERRUPTS_IRQ_ISR_464 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_464);
#endif
#if (INTERRUPTS_IRQ_ISR_465 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_465);
#endif
#if (INTERRUPTS_IRQ_ISR_466 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_466);
#endif
#if (INTERRUPTS_IRQ_ISR_467 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_467);
#endif
#if (INTERRUPTS_IRQ_ISR_468 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_468);
#endif
#if (INTERRUPTS_IRQ_ISR_469 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_469);
#endif
#if (INTERRUPTS_IRQ_ISR_470 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_470);
#endif
#if (INTERRUPTS_IRQ_ISR_471 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_471);
#endif
#if (INTERRUPTS_IRQ_ISR_472 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_472);
#endif
#if (INTERRUPTS_IRQ_ISR_473 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_473);
#endif
#if (INTERRUPTS_IRQ_ISR_474 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_474);
#endif
#if (INTERRUPTS_IRQ_ISR_475 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_475);
#endif
#if (INTERRUPTS_IRQ_ISR_476 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_476);
#endif
#if (INTERRUPTS_IRQ_ISR_477 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_477);
#endif
#if (INTERRUPTS_IRQ_ISR_478 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_478);
#endif
#if (INTERRUPTS_IRQ_ISR_479 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_479);
#endif
#if (INTERRUPTS_IRQ_ISR_480 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_480);
#endif
#if (INTERRUPTS_IRQ_ISR_481 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_481);
#endif
#if (INTERRUPTS_IRQ_ISR_482 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_482);
#endif
#if (INTERRUPTS_IRQ_ISR_483 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_483);
#endif
#if (INTERRUPTS_IRQ_ISR_484 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_484);
#endif
#if (INTERRUPTS_IRQ_ISR_485 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_485);
#endif
#if (INTERRUPTS_IRQ_ISR_486 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_486);
#endif
#if (INTERRUPTS_IRQ_ISR_487 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_487);
#endif
#if (INTERRUPTS_IRQ_ISR_488 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_488);
#endif
#if (INTERRUPTS_IRQ_ISR_489 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_489);
#endif
#if (INTERRUPTS_IRQ_ISR_490 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_490);
#endif
#if (INTERRUPTS_IRQ_ISR_491 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_491);
#endif
#if (INTERRUPTS_IRQ_ISR_492 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_492);
#endif
#if (INTERRUPTS_IRQ_ISR_493 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_493);
#endif
#if (INTERRUPTS_IRQ_ISR_494 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_494);
#endif
#if (INTERRUPTS_IRQ_ISR_495 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_495);
#endif
#if (INTERRUPTS_IRQ_ISR_496 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_496);
#endif
#if (INTERRUPTS_IRQ_ISR_497 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_497);
#endif
#if (INTERRUPTS_IRQ_ISR_498 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_498);
#endif
#if (INTERRUPTS_IRQ_ISR_499 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_499);
#endif
#if (INTERRUPTS_IRQ_ISR_500 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_500);
#endif
#if (INTERRUPTS_IRQ_ISR_501 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_501);
#endif
#if (INTERRUPTS_IRQ_ISR_502 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_502);
#endif
#if (INTERRUPTS_IRQ_ISR_503 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_503);
#endif
#if (INTERRUPTS_IRQ_ISR_504 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_504);
#endif
#if (INTERRUPTS_IRQ_ISR_505 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_505);
#endif
#if (INTERRUPTS_IRQ_ISR_506 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_506);
#endif
#if (INTERRUPTS_IRQ_ISR_507 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_507);
#endif
#if (INTERRUPTS_IRQ_ISR_508 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_508);
#endif
#if (INTERRUPTS_IRQ_ISR_509 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_509);
#endif
#if (INTERRUPTS_IRQ_ISR_510 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_510);
#endif
#if (INTERRUPTS_IRQ_ISR_511 != INTERRUPTS_IRQ_DEFAULT_HANDLER)
    FN_IRQ_DECLARE(INTERRUPTS_IRQ_ISR_511);
#endif

#if (INTERRUPTS_NMI_ISR_0 != INTERRUPTS_NMI_DEFAULT_HANDLER)
    FN_NMI_DECLARE(INTERRUPTS_NMI_ISR_0);
#endif
#if (INTERRUPTS_NMI_ISR_1 != INTERRUPTS_NMI_DEFAULT_HANDLER)
    FN_NMI_DECLARE(INTERRUPTS_NMI_ISR_1);
#endif
#if (INTERRUPTS_NMI_ISR_2 != INTERRUPTS_NMI_DEFAULT_HANDLER)
    FN_NMI_DECLARE(INTERRUPTS_NMI_ISR_2);
#endif
#if (INTERRUPTS_NMI_ISR_3 != INTERRUPTS_NMI_DEFAULT_HANDLER)
    FN_NMI_DECLARE(INTERRUPTS_NMI_ISR_3);
#endif
#if (INTERRUPTS_NMI_ISR_4 != INTERRUPTS_NMI_DEFAULT_HANDLER)
    FN_NMI_DECLARE(INTERRUPTS_NMI_ISR_4);
#endif
#if (INTERRUPTS_NMI_ISR_5 != INTERRUPTS_NMI_DEFAULT_HANDLER)
    FN_NMI_DECLARE(INTERRUPTS_NMI_ISR_5);
#endif
#if (INTERRUPTS_NMI_ISR_6 != INTERRUPTS_NMI_DEFAULT_HANDLER)
    FN_NMI_DECLARE(INTERRUPTS_NMI_ISR_6);
#endif
#if (INTERRUPTS_NMI_ISR_7 != INTERRUPTS_NMI_DEFAULT_HANDLER)
    FN_NMI_DECLARE(INTERRUPTS_NMI_ISR_7);
#endif
#if (INTERRUPTS_NMI_ISR_8 != INTERRUPTS_NMI_DEFAULT_HANDLER)
    FN_NMI_DECLARE(INTERRUPTS_NMI_ISR_8);
#endif
#if (INTERRUPTS_NMI_ISR_9 != INTERRUPTS_NMI_DEFAULT_HANDLER)
    FN_NMI_DECLARE(INTERRUPTS_NMI_ISR_9);
#endif
#if (INTERRUPTS_NMI_ISR_10 != INTERRUPTS_NMI_DEFAULT_HANDLER)
    FN_NMI_DECLARE(INTERRUPTS_NMI_ISR_10);
#endif
#if (INTERRUPTS_NMI_ISR_11 != INTERRUPTS_NMI_DEFAULT_HANDLER)
    FN_NMI_DECLARE(INTERRUPTS_NMI_ISR_11);
#endif
#if (INTERRUPTS_NMI_ISR_12 != INTERRUPTS_NMI_DEFAULT_HANDLER)
    FN_NMI_DECLARE(INTERRUPTS_NMI_ISR_12);
#endif
#if (INTERRUPTS_NMI_ISR_13 != INTERRUPTS_NMI_DEFAULT_HANDLER)
    FN_NMI_DECLARE(INTERRUPTS_NMI_ISR_13);
#endif
#if (INTERRUPTS_NMI_ISR_14 != INTERRUPTS_NMI_DEFAULT_HANDLER)
    FN_NMI_DECLARE(INTERRUPTS_NMI_ISR_14);
#endif
#if (INTERRUPTS_NMI_ISR_15 != INTERRUPTS_NMI_DEFAULT_HANDLER)
    FN_NMI_DECLARE(INTERRUPTS_NMI_ISR_15);
#endif
#if (INTERRUPTS_NMI_ISR_16 != INTERRUPTS_NMI_DEFAULT_HANDLER)
    FN_NMI_DECLARE(INTERRUPTS_NMI_ISR_16);
#endif
#if (INTERRUPTS_NMI_ISR_17 != INTERRUPTS_NMI_DEFAULT_HANDLER)
    FN_NMI_DECLARE(INTERRUPTS_NMI_ISR_17);
#endif
#if (INTERRUPTS_NMI_ISR_18 != INTERRUPTS_NMI_DEFAULT_HANDLER)
    FN_NMI_DECLARE(INTERRUPTS_NMI_ISR_18);
#endif
#if (INTERRUPTS_NMI_ISR_19 != INTERRUPTS_NMI_DEFAULT_HANDLER)
    FN_NMI_DECLARE(INTERRUPTS_NMI_ISR_19);
#endif
#if (INTERRUPTS_NMI_ISR_20 != INTERRUPTS_NMI_DEFAULT_HANDLER)
    FN_NMI_DECLARE(INTERRUPTS_NMI_ISR_20);
#endif
#if (INTERRUPTS_NMI_ISR_21 != INTERRUPTS_NMI_DEFAULT_HANDLER)
    FN_NMI_DECLARE(INTERRUPTS_NMI_ISR_21);
#endif
#if (INTERRUPTS_NMI_ISR_22 != INTERRUPTS_NMI_DEFAULT_HANDLER)
    FN_NMI_DECLARE(INTERRUPTS_NMI_ISR_22);
#endif
#if (INTERRUPTS_NMI_ISR_23 != INTERRUPTS_NMI_DEFAULT_HANDLER)
    FN_NMI_DECLARE(INTERRUPTS_NMI_ISR_23);
#endif
#if (INTERRUPTS_NMI_ISR_24 != INTERRUPTS_NMI_DEFAULT_HANDLER)
    FN_NMI_DECLARE(INTERRUPTS_NMI_ISR_24);
#endif
#if (INTERRUPTS_NMI_ISR_25 != INTERRUPTS_NMI_DEFAULT_HANDLER)
    FN_NMI_DECLARE(INTERRUPTS_NMI_ISR_25);
#endif
#if (INTERRUPTS_NMI_ISR_26 != INTERRUPTS_NMI_DEFAULT_HANDLER)
    FN_NMI_DECLARE(INTERRUPTS_NMI_ISR_26);
#endif
#if (INTERRUPTS_NMI_ISR_27 != INTERRUPTS_NMI_DEFAULT_HANDLER)
    FN_NMI_DECLARE(INTERRUPTS_NMI_ISR_27);
#endif
#if (INTERRUPTS_NMI_ISR_28 != INTERRUPTS_NMI_DEFAULT_HANDLER)
    FN_NMI_DECLARE(INTERRUPTS_NMI_ISR_28);
#endif
#if (INTERRUPTS_NMI_ISR_29 != INTERRUPTS_NMI_DEFAULT_HANDLER)
    FN_NMI_DECLARE(INTERRUPTS_NMI_ISR_29);
#endif
#if (INTERRUPTS_NMI_ISR_30 != INTERRUPTS_NMI_DEFAULT_HANDLER)
    FN_NMI_DECLARE(INTERRUPTS_NMI_ISR_30);
#endif
#if (INTERRUPTS_NMI_ISR_31 != INTERRUPTS_NMI_DEFAULT_HANDLER)
    FN_NMI_DECLARE(INTERRUPTS_NMI_ISR_31);
#endif

#ifdef __TOOLCHAIN_IAR__
    #pragma diag_default=Pe193 // restore default behavior for specific diag
#endif

/*****************************************************************************/
/* Global type definitions ('typedef')                                       */
/*****************************************************************************/

/*****************************************************************************/
/* Global variable declarations ('extern', definition in C source)           */
/*****************************************************************************/

/*****************************************************************************/
/* Global function prototypes ('extern', definition in C source)             */
/*****************************************************************************/
extern void Interrupts_InitNmi(void);
extern void Interrupts_InitIrq(void);

#endif /* __FILE_VERSION_CHECK__ */
#endif /* __INTERRUPTS_H__ */
