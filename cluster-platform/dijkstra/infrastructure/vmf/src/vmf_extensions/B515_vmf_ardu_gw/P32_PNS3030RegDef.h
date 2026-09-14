/**
* \addtogroup PN3030E
* @{
*/

/**
* \file
* PN3030E register map file.
* \author Lawrence <lawrence@pnpnetwork.com>
*         Evan	   <evan@pnpnetwork.com>
*		  Ralf     <ralf@pnpnetwork.com>
*/

/*
* Copyright (c) 2006-2007.
* All rights reserved. 
*
* Redistribution and use in source and binary forms, with or without 
* modification, are permitted provided that the following conditions 
* are met: 
* 1. Redistributions of source code must retain the above copyright 
*    notice, this list of conditions and the following disclaimer. 
* 2. Redistributions in binary form must reproduce the above copyright 
*    notice, this list of conditions and the following disclaimer in the 
*    documentation and/or other materials provided with the distribution. 
* 3. The name of the author may not be used to endorse or promote
*    products derived from this software without specific prior
*    written permission.  
*
* THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS
* OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
* ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
* DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
* GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
* WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
* NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  
*
* This file is part of the PN3030E Device Driver.
*
* $Id: register_def.h  v0.0.1 2006/11/13 : PN3030E Register map definition $
*
*/

#ifndef _PN3030E_REGISGER_DEFINE_H_
#define _PN3030E_REGISGER_DEFINE_H_

////////////////////////////PN3030E CHIP ADDRESS/////////////////////////////
#define PN3030E_ADDR        (0x86)	//ksjuny 0x43 --> 0x86 20140428

/////////////////////////////////////////////////////////////////////////////
// PN3030E Register page mode                                              //
// _E_ : This means the PN3030E device.                                    //
/////////////////////////////////////////////////////////////////////////////
#define COMM_E_PAGE         (0x4)
#define OFDM_E_PAGE         (0x6)
#define FM_E_PAGE           (0x6)
#define HOST_E_PAGE         (0x7)
#define CAS_E_PAGE          (0x8)
#define FEC_E_PAGE          (0x9)
#define DD_E_PAGE           (0x9)

#define FIC_E_PAGE          (0xA)
#define MSC0_E_PAGE         (0xB)
#define MSC1_E_PAGE         (0xC)
#define NIS_E_PAGE          (0xD)
#define TII_E_PAGE          (0xE)

/////////////////////////////////////////////////////////////////////////////
// PN3030EV Register page mode                                             //
// _E_ : This means the PN3030EV device.                                   //
/////////////////////////////////////////////////////////////////////////////

#define COMM_EV_PAGE        (0x4)

#define RF_E_PAGE           (0xF)		// noah add pns3030a 

/////////////////////////////////////////////////////////////////////////////
// PN3030E TOP Register address                                            //
/////////////////////////////////////////////////////////////////////////////
#define PN3030EID           (0x0)  /// PN3030ID Reset Value 0x02. Read Only
#define TOP01_E             (0x1)  /// PN3030 Chip address [6:0]
#define TOP02_E             (0x2)  /// Tuner Device ID, Repeat Line I2C Chip Address
#define TOP03_E             (0x3)  /// GPDD control register
#define TOP04_E             (0x4)  /// BERT_PAD & GPAD & MAP_SEL control register
#define TOP05_E             (0x5)  /// SLEEP & STANDBY & OP_MODE control register
#define TOP06_E             (0x6)  /// ADC_GAIN & GPPI_SEL control register
#define TOP07_E             (0x7)  /// AUDIO mode control register
#define TOP08_E             (0x8)  /// Interrupt pin source selection control register
#define TOP09_E             (0x9)  /// PLL_Reset & Interrupt polarity register
#define TOP10_E             (0xA)  /// PLL_Lock & I2CPDN & GPDAC control register
#define TOP11_E             (0xB)  /// PLL Multiply M, N
#define TOP12_E             (0xC)  /// Main Clock Mode
#define TOP13_E             (0xD)  /// External Clock select control
#define TOP14_E             (0xE)  /// PAD Control
#define TOP15_E             (0xF)  /// PAD Control

/////////////////////////////////////////////////////////////////////////////
// PN3030EV COMM Register address                                          //
/////////////////////////////////////////////////////////////////////////////
#define COMM_10             (0x10) // Default 0x90, [7:0] = 0x85(Master)/0x83(Slave)
#define COMM_15             (0x15) // [3:2] OUT_SEL : MRC Mode [0] MIX (Master+Slave) [1] Master only [2] Slave only, 0x15[1] FEC_NDATA_OK, 0x15[0] FEC_NDATA_OK : Symbol Sync

#define COMM_35             (0x35)
#define COMM_36             (0x36)
#define COMM_38             (0x38)
#define COMM_39             (0x39)
#define COMM_3A             (0x3A)
#define COMM_3B             (0x3B)
#define COMM_3E             (0x3E)
#define COMM_8A		    (0x8A)  // PNS3030_RegDef
#define COMM_8B		    (0x8B)  // PNS3030_RegDef
#define COMM_E1             (0xE1)

/////////////////////////////////////////////////////////////////////////////
// PN3030E OFDM Register address                                           //
/////////////////////////////////////////////////////////////////////////////
#define OFDM_E_CON          (0x10)
#define NULL1C_E            (0x1C)  /// Set the one shot for read the NULL length value[7]
#define MON_E_CFREQ         (0x18)  /// Coarse frequency index monitoring
#define MON_E_NULL26        (0x26)  /// Display the NULL length value[7:0]
#define MON_E_NULL27        (0x27)  /// Display the NULL length value[11:8]

#define INV33_E             (0x33)  /// Spectrum inverse mode auto/manual control
#define MON_E_INV           (0x37)  /// Display AGC_LOCK[4] INV[3] FSM[2:0]

#define LOOP03_E_HL         (0x42)  /// PNCO setting register[23:16]
#define LOOP03_E_HH         (0x43)  /// PNCO setting register[31:24]
#define MON_POST_START      (0x44)  /// Set the one shot for read the POST AGC value[7]
#define MON_POST_GAIN_L     (0x4C)  /// Display POST AGC value[7:0]
#define MON_POST_GAIN_H     (0x4D)  /// Display POST AGC value[9:8]

#define AGC0_E_EN           (0x53)  /// PRE AGC value[7]
#define MON_PRE_START       (0x53)
#define MON_CNT_PRE1_L      (0x66)  /// Display PRE AGC value[1:0]
#define MON_CNT_PRE1_H      (0x67)  /// Display PRE AGC value[9:2]

#define MON_E_VARI7E        (0x7E)  /// Display OFDM signal quality[7:0]
#define MON_E_VARI7F        (0x7F)  /// Display OFDM signal quality[11:8]
#define USAM_E_START        (0x82)  /// Set one shot for OFDM signal quality

#define AGC_E_SEL           (0xBA)  /// AGC1_SEL[3:2] AGC0_SEL[1:0]

#define SCANEN_E            (0xCD)  /// SCAN control 
#define SCANDONE_E          (0xCF)  /// SCAN done display

/////////////////////////////////////////////////////////////////////////////
// PN3030E FEC Register address                                            //
/////////////////////////////////////////////////////////////////////////////
#define TS1_E_BYTE          (0x10)  /// TS1 sync byte setting for 3-dmb channel
#define TS2_E_BYTE          (0x11)  /// TS2 sync byte setting for 3-dmb channel
#define TS3_E_BYTE          (0x12)  /// TS3 sync byte setting for 3-dmb channel

#define TII_MOM_SEL         (0x5A)  /// [0] 1: low 16-bit	0: high 16-bit
#define MON_TII_TOWER       (0x5B)  /// [4:0]  TII tower count detected
#define MON_TII0_H          (0x5C)  /// [15:8] TII tower #0 information
#define MON_TII0_L          (0x5D)  /// [7:0]  TII tower #0 information
#define MON_TII1_H          (0x5E)  /// [15:8] TII tower #1 information
#define MON_TII1_L          (0x5F)  /// [7:0]  TII tower #1 information

#define FIC_E_TH            (0x80)  /// FEC reset threshold by using FIC CRC error
#define FIC_E_PRD           (0x81)  /// FIC CRC check period for 0x82 (unit FIB)
#define MON_E_FIB           (0x82)  /// Mon FIB CRC Error number

#define FIC_E_CNTH          (0x83)  /// [13:8] - FIC CER period counter for accumulation
#define FIC_E_CNTL          (0x84)  /// [7:0]
#define FIC_E_CERH          (0x85)  /// [13:8] - FIC CER error number
#define FIC_E_CERL          (0x86)  /// [7:0]

#define MSC_E_CERPRD        (0x87)  /// MSC_CER_PRD = (MSC_E_CERCNT+1)CIF - (MAX256CIF) : 7 setting
#define MSC_E_CNTHH         (0x88)  /// [31:24] - MSC CER period counter for accumulation
#define MSC_E_CNTHL         (0x89)  /// [23:16]
#define MSC_E_CNTLH         (0x8A)  /// [15:8]
#define MSC_E_CNTLL         (0x8B)  /// [7:0]
#define MSC_E_CERHH         (0x8C)  /// [31:24] - MSC CER error number
#define MSC_E_CERHL         (0x8D)  /// [23:16]
#define MSC_E_CERLH         (0x8E)  /// [15:8]
#define MSC_E_CERLL         (0x8F)  /// [7:0]

#define SUBCH_E_MONCON0     (0x90)  /// ENABLE [7], SUBCHID_MON [5:0]
#define SUBCH_E_MON3_H      (0x9C)  /// SUBCH_SIZE [10:8]
#define SUBCH_E_MON3_L      (0x9D)  /// SUBCH_SIZE [7:0]

#define VITPRD_E_MODE       (0xA5)  /// fot test
#define VITBYTE0_E_PRDH     (0xAC)  /// [17:16] RS1 Viterbi byte error period
#define VITBYTE0_E_PRDM     (0xAD)  /// [15:8]
#define VITBYTE0_E_PRDL     (0xAE)  /// [7:0] 
#define VITBYTE0_E_ERRH     (0xAF)  /// [17:16] RS1 Viterbi byte error number
#define VITBYTE0_E_ERRM     (0xB0)  /// [15:8]
#define VITBYTE0_E_ERRL     (0xB1)  /// [7:0] 

#define TS1_E_BITPRDH       (0xA6)  /// [21:16] RS1 Viterbi bit error period
#define TS1_E_BITPRDM       (0xA7)  /// [15:8]
#define TS1_E_BITPRDL       (0xA8)  /// [7:0] 
#define TS1_E_BITERRH       (0xA9)  /// [21:16] RS1 Viterbi bit error number
#define TS1_E_BITERRM       (0xAA)  /// [15:8]
#define TS1_E_BITERRL       (0xAB)  /// [7:0] 
#define TS1_E_PKTERRH       (0xB4)  /// [9:8] RS1 Alarm error number
#define TS1_E_PKTERRL       (0xB5)  /// [7:0] 

#define TS2_E_BITPRDH       (0xB6)  /// [21:16] RS2 Viterbi bit error period
#define TS2_E_BITPRDM       (0xB7)  /// [15:8]
#define TS2_E_BITPRDL       (0xB8)  /// [7:0] 
#define TS2_E_BITERRH       (0xB9)  /// [21:16] RS2 Viterbi bit error number
#define TS2_E_BITERRM       (0xBA)  /// [15:8]
#define TS2_E_BITERRL       (0xBB)  /// [7:0] 
#define TS2_E_PKTERRH       (0xC4)  /// [9:8] RS2 Alarm error number
#define TS2_E_PKTERRL       (0xC5)  /// [7:0] 

#define TS3_E_BITPRDH       (0xC6)  /// [21:16] RS3 Viterbi bit error period
#define TS3_E_BITPRDM       (0xC7)  /// [15:8]
#define TS3_E_BITPRDL       (0xC8)  /// [7:0] 
#define TS3_E_BITERRH       (0xC9)  /// [21:16] RS3 Viterbi bit error number
#define TS3_E_BITERRM       (0xCA)  /// [15:8]
#define TS3_E_BITERRL       (0xCB)  /// [7:0] 
#define TS3_E_PKTERRH       (0xD4)  /// [9:8] RS3 Alarm error number
#define TS3_E_PKTERRL       (0xD5)  /// [7:0] 

#define TSYNC_E_CON         (0xD6)  /// [7:4] Missing hit count [3:0] hit count
#define TS1_E_SYNC          (0xD7)  /// [4]FIC sync flag [3]TS1 sync flag 
#define TS2_E_SYNC          (0xD9)  /// [3]TS2 sync flag  
#define TS3_E_SYNC          (0xDB)  /// [3]TS3 sync flag  

#define MPEGIF_E_CON1       (0xDD)  /// [7:6]MPEG-2TS Channel sel [3]Packet error pol [2]Sync pol [1]Data valid pol [0]Clock pol - 1:Active low, 0: high
#define MPEGIF_E_CON2       (0xDE)  /// [6]Serial mode - 0:msb first [5]data pin [4]0:only packet [3]0:error enable only packet [2]0:clock enable only packet [1] 0:1-bit syne [0]0:parallel mode
#define FEC_E_CON0          (0xE6)  /// [6]PWR save [4]MPEG-2TS sync byte value different - 1:enable [2]RS output mode - 1:Packet + Parity [1]CTRL - 1:enable [0]BERT mode - 1:DMB, 0:DAB out
#define FEC_E_CON3          (0xE9)  /// [3]SYNC_MODE: FEC decoding mode - 1: Start MSC data decoding at once	0: Start MSC data decoding after HITREG value

/////////////////////////////////////////////////////////////////////////////
// PN3030E SPI/HPI to RF control by using IIC interface module	           //
/////////////////////////////////////////////////////////////////////////////
#define RF_E_CON            (0x70)  /// Tuner I2C ID/REG address off, read mode select.
#define RF_E_I2C_BAUD       (0x71)
#define RF_E_I2C_CON        (0x72)  /// Tuner Read/Write mode selection & IIC start, enable
#define RF_E_CHIPADDR       (0x78)  /// External RF device chip address 
#define RF_E_LOCAL_WADDR    (0x80)
#define RF_E_LOCAL_RADDR    (0x88)
#define RF_E_WDATA_ADDR     (0x8C)  /// PN3030E internal initial address to write the RF write data
#define RF_E_RDATA_ADDR     (0x94)  /// PN3030E internal initial address to get the RF read data
#define RF_E_BURST_L        (0x98)  /// Tuner Read/Write burst length

#define RF_E_WDATA00        (0xA4)  /// This address is for the RF data in IIC write mode
#define RF_E_WDATA01        (0xA5)  
#define RF_E_WDATA02        (0xA6)
#define RF_E_WDATA03        (0xA7)
#define RF_E_WDATA04        (0xA8)
#define RF_E_WDATA05        (0xA9)
#define RF_E_WDATA06        (0xAA)
#define RF_E_WDATA07        (0xAB)
#define RF_E_WDATA08        (0xAC)
#define RF_E_WDATA09        (0xAD)
#define RF_E_WDATA10        (0xAE)
#define RF_E_WDATA11        (0xAF)
#define RF_E_WDATA12        (0xB0)
#define RF_E_WDATA13        (0xB1)
#define RF_E_WDATA14        (0xB2)
#define RF_E_WDATA15        (0xB3)

#define RF_E_RDATA00        (0xB4)  /// This address is for the RF data in IIC read mode
#define RF_E_RDATA01        (0xB5)  
#define RF_E_RDATA02        (0xB6)
#define RF_E_RDATA03        (0xB7)
#define RF_E_RDATA04        (0xB8)
#define RF_E_RDATA05        (0xB9)
#define RF_E_RDATA06        (0xBA)
#define RF_E_RDATA07        (0xBB)
#define RF_E_RDATA08        (0xBC)
#define RF_E_RDATA09        (0xBD)
#define RF_E_RDATA10        (0xBE)
#define RF_E_RDATA11        (0xBF)
#define RF_E_RDATA12        (0xC0)
#define RF_E_RDATA13        (0xC1)
#define RF_E_RDATA14        (0xC2)
#define RF_E_RDATA15        (0xC3)

/////////////////////////////////////////////////////////////////////////////
// PN3030E HOST Register Address                                           //
/////////////////////////////////////////////////////////////////////////////
#define INT_E_CON00         (0x28)
#define INT_E_CON01         (0x29)
#define INT_E_CON02         (0x2A)

#define INT0_E_MASK62       (0x62)
#define INT0_E_MASK63       (0x63)
#define INT1_E_MASK64       (0x64)
#define INT1_E_MASK65       (0x65)

/////////////////////////////////////////////////////////////////////////////
// PN3030E Data decoder Register Address                                   //
/////////////////////////////////////////////////////////////////////////////
#define INT_E_STATL         (0x33)  /// [7]OFDM Lock status [6]MSC1 overrun [5]MSC1 underrun [4]MSC1 int [3]MSC0 overrun [2]MSC0 underrun [1]MSC0 int [0]FIC int
#define INT_E_STATH         (0x34)  /// [7]OFDM NIS [6]OFDM TII [5]OFDM scan [4]OFDM window position [3]OFDM unlock [2]FEC re-configuration [1]FEC CIF end [0]FEC soft reset

#define INT_E_UCLRL         (0x35)  /// [2]MSC1 int clear [1]MSC0 int clear [0]FIC int clear
#define INT_E_UCLRH         (0x36)  /// [6]OFDM TII done clear

#define MON_E_OFDM1         (0x37)  /// [2:1] tr_mode [0] ofdm_lock
#define MON_E_OFDM2         (0x38)  /// [5] agc_lock [4] time_lock [3] coarse_lock [2:0] fsm
#define SOFT_RST_E_CON      (0x39)  /// [2] MSC1_SOFT_RST_EN [1] MSC0_SOFT_RST_EN [0] FIC_SOFT_RST_EN

#define MSC1_E_SUBCH0       (0x3A)  /// to MSC1 memory [7]Decoding- 1:enable [6]RS pass - 1:enable [5:0]Subch_ID0
#define MSC1_E_SUBCH1       (0x3B)  /// to MSC1 memory [7]Decoding- 1:enable [6]RS pass - 1:enable [5:0]Subch_ID1
#define MSC1_E_SUBCH2       (0x3C)  /// to MSC1 memory [7]Decoding- 1:enable [6]RS pass - 1:enable [5:0]Subch_ID2
#define MSC0_E_SUBCH3       (0x3D)  /// to MSC0 memory [7]Decoding- 1:enable [5:0]Subch_ID3
#define MSC0_E_SUBCH4       (0x3E)  /// to MSC0 memory [7]Decoding- 1:enable [5:0]Subch_ID4
#define MSC0_E_PKTCH5       (0x3F)  /// to MSC0 memory [7]Decoding- 1:enable [6]PKT mode- 1:PKT, 0:Stream [5:0]Subch_ID5
#define PKTCH5_E_ADDRL      (0x40)  /// in PKT sub channel 5 [7:0]Packet address lsb in sub channel 5 
#define PKTCH5_E_ADDRH      (0x41)  /// in PKT sub channel 5 [1:0]Packet address msb in sub channel 5 
#define MSC0_E_PKTCH6       (0x42)  /// to MSC0 memory [7]Decoding- 1:enable [6]PKT mode- 1:PKT, 0:Stream [5:0]Subch_ID6
#define PKTCH6_E_ADDRL      (0x43)  /// in PKT sub channel 6 [7:0]Packet address lsb in sub channel 6
#define PKTCH6_E_ADDRH      (0x44)  /// in PKT sub channel 6 [1:0]Packet address msb in sub channel 6 

#define DD_E_TOPCON         (0x45)  /// [7]Buf_en [6]PKT_CRC_MODE:enable (stored) [5]MPEG_HEAD [4]MPEG-2TS_EN [3]EPKT_MODE [2]CAS_MODE [1]FIDC_MODE [0]FIC_INIT_EN == 1:enable
#define FIC_E_DDCON         (0x46)  /// [4]FIC_CRC stored- 1:enable [3]FIC uclear-1 [2]FIC_Update - 1:dependent by user  [1]FIC_EN [0]FIG_EN - 1:only FIG 6 dump
#define MSC0_E_CON          (0x47)  /// [3]MSC0 uclear-1 [2]MSC0_en [1]MSC0 read length -1:user length, 0:interrupt length [0]MSC0 interrupt sel-1:user th, 0:CIF end
#define MSC1_E_CON          (0x48)  /// [5]MSC1_length-0:subch+length [4]MSC1 header-0:disable [3]MSC1 uclear-1 [2]MSC1_en [1]MSC1 read length -1:user length, 0:interrupt length [0]MSC1 interrupt sel-1:user th, 0:CIF end
#define OFDM_E_DDCON        (0x49)  /// [3]NIS uclear-1 [2]NIS_Update - 1:dependent by user [1]TII status clear -1:user set only, 0:user set & internal event [0]TII_Update - 1:dependent by user

#define MON_E_FIBERR_H      (0x4A)  /// [11:8] in low 4 bit
#define MON_E_FIBERR_L      (0x4B)  /// [7:0] 
#define MON_E_FIG6_H        (0x4C)  /// [8] in low 1 bit
#define MON_E_FIG6_L        (0x4D)  /// [7:0] for FIG 6 data access
#define MSC0_E_RSIZE_H      (0x4E)  /// [11:8] setting in MSC0 read length for interrupt clear
#define MSC0_E_RSIZE_L      (0x4F)  /// [7:0]
#define MSC0_E_INTTH_H      (0x50)  /// [11:8] MSC0 interrupt threshold
#define MSC0_E_INTTH_L      (0x51)  /// [7:0]
#define MSC0_E_TSIZE_H      (0x52)  /// [11:8]
#define MSC0_E_TSIZE_L      (0x53)  /// [7:0] MSC0 total size which you can read 
#define MSC1_E_RSIZE_H      (0x54)  /// [11:8] setting in MSC1 read length for interrupt clear
#define MSC1_E_RSIZE_L      (0x55)  /// [7:0]
#define MSC1_E_INTTH_H      (0x56)  /// [11:8] MSC1 interrupt threshold
#define MSC1_E_INTTH_L      (0x57)  /// [7:0]
#define MSC1_E_TSIZE_H      (0x58)  /// [11:8]
#define MSC1_E_TSIZE_L      (0x59)  /// [7:0] MSC1 read length 

#define RECONFIG_SUBCH0_CON (0x70)  /// [7] RE_SUBCH0_EN  [6] MPEG_EN0 [5:0] RE_SUBCH0_ID 
#define RECONFIG_SUBCH1_CON (0x71)  /// [7] RE_SUBCH1_EN  [6] MPEG_EN1 [5:0] RE_SUBCH1_ID 
#define RECONFIG_SUBCH2_CON (0x72)  /// [7] RE_SUBCH2_EN  [6] MPEG_EN2 [5:0] RE_SUBCH2_ID 
#define RECONFIG_SUBCH3_CON (0x73)  /// [7] RE_SUBCH3_EN  [5:0] RE_SUBCH3_ID
#define RECONFIG_SUBCH4_CON (0x74)  /// [7] RE_SUBCH4_EN  [5:0] RE_SUBCH4_ID
#define RECONFIG_SUBCH5_L   (0x75)  /// [7] RE_SUBCH5_EN  [6] RE_SUBCH5_PACK_EN  [5:0] RE_SUBCH5_ID
#define RECONFIG_SUBCH5_M   (0x76)  /// [7:0] RE_SUBCH5_PACK_ADDR
#define RECONFIG_SUBCH5_H   (0x77)  /// [9:8] RE_SUBCH5_PACK_ADDR
#define RECONFIG_SUBCH6_L   (0x78)  /// [7] RE_SUBCH6_EN  [6] RE_SUBCH6_PACK_EN  [5:0] RE_SUBCH6_ID
#define RECONFIG_SUBCH6_M   (0x79)  /// [7:0] RE_SUBCH6_PACK_ADDR
#define RECONFIG_SUBCH6_H   (0x7A)  /// [9:8] RE_SUBCH6_PACK_ADDR

/////////////////////////////////////////////////////////////////////////////
// PN3030E FM Register Address                                             //
/////////////////////////////////////////////////////////////////////////////
/// FM Data Decoder page register
#define FM_CON00            (0x7B)
#define FM_CON01            (0x7C)
#define FM_CON02            (0x7D)
#define MON_RDS_OUT         (0x7E)

/// FM OFDM page register
#define FM10                (0x10)

#define FM3F                (0x3F)

#define FM44                (0x44)
#define FM45                (0x45)
#define FM46                (0x46)
#define FM47                (0x47)
#define FM48                (0x48)
#define FM49                (0x49)
#define FM4A                (0x4A)
#define FM4B                (0x4B)
#define FM4C                (0x4C)
#define FM4D                (0x4D)
#define FM6D                (0x6D)

#define FM85                (0x85)

#define FMD1                (0xD1)
#define FMD2                (0xD2)
#define FMD3_LL             (0xD3)
#define FMD3_LH             (0xD4)
#define FMD3_HL             (0xD5)
#define FMD3_HH             (0xD6)
#define FMD7                (0xD7)
#define FMD8_LL             (0xD8)
#define FMD8_LH             (0xD9)
#define FMD8_HL             (0xDA)
#define FMDB                (0xDB)  /// [0] RDS_LOCK display

#define FME4                (0xE4)
#define FME5                (0xE5)
#define FME6                (0xE6)
#define FME7                (0xE7)  /// [7:0] RDS Post AGC gain value display
#define FME8                (0xE8)
#define FME9                (0xE9)
#define FMED                (0xED)
#define FMEE                (0xEE)  /// [7:0] FM lock counter
#define FMEF                (0xEF)  /// [0] FM_STEREO_LOCK display

#define FMF0                (0xF0)
#define FMF1                (0xF1)
#define FMF2                (0xF2)
#define FMF3                (0xF3)
#define FMF4                (0xF4)
#define FMF5                (0xF5)
#define FMF6                (0xF6)  /// [7:6] FM Sampling Rate 0-128k, 1-64k, 2-32k 
#define FMF7                (0xF7)  /// [1] FM variance start [0]FM DC value start
#define FMF8                (0xF8)
#define FMF9                (0xF9)  /// [7:0] Offset value of OSC57 frequency
#define FMFA                (0xFA)
#define FMFB                (0xFB)
#define FMFC                (0xFC)  /// [7:0] FM DC value display 
#define FMFD                (0xFD)  /// [15:8] FM DC value display 
#define FMFE                (0xFE)  /// [20:16] FM DC value display 
#define FMFF                (0xFF)  /// [7:0] FM variance display

////////////////////OFDM Bit Field/////////////////
#define AUTO_E_MODE         0       /// 0: Manual 1: Auto

/////////////////////Bit Masking///////////////////
#define BIT_MASK_7_E        (0x80)
#define BIT_MASK_6_E        (0x40)
#define BIT_MASK_5_E        (0x20)
#define BIT_MASK_4_E        (0x10)
#define BIT_MASK_3_E        (0x08)
#define BIT_MASK_2_E        (0x04)
#define BIT_MASK_1_E        (0x02)
#define BIT_MASK_0_E        (0x01)

#endif