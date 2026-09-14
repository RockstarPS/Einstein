/*============================================================================
**
**                     CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2009. Visteon Corporation owns all rights to this work and
** intends to maintain it in confidence to preserve its trade secret status.
** Visteon Corporation reserves the right, under the copyright laws of the
** United States or those of any other country that may have jurisdiction,
** to protect this work as an unpublished work, in the event of an
** inadvertent or deliberate unauthorized publication. Visteon Corporation
** also reserves its rights under all copyright laws to protect this work as
** a published work, when appropriate. Those having access to this work may
** not copy it, use it, modify it or disclose the information contained in
** it without the written authorization of Visteon Corporation.
**
**============================================================================
**
** Name:           qspi.c
**
** Description:    This file contains the implementation of the Quad SPI
**                 (QSPI) driver for initializing the QSPI peripheral for
**                 communication with an external Spansion flash IC.
**
**                 This code conditionally compiles to choose between
**                 the Spectrum and Rainbow QSPI peripherals.  Please note
**                 that the comments in the file are specific to Spectrum,
**                 so although the basic intent behind them is the same
**                 for both micros, the actual values used in the
**                 registers may differ for Rainbow.
**
** Organization:   Driver Information Software Section,
**                 DI Core Engineering Department
**
**============================================================================
**
**==========================================================================*/
#define QSPI_C

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include "system.h"
#include "qspi.h"
#include "qspi.cfg"
#include "mcu_preg.h"

/*============================================================================
** I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S
**==========================================================================*/


/*============================================================================
** I N T E R N A L   F U N C T I O N   P R O T O T Y P E S
**==========================================================================*/
static void qspi_wait_for_ICR_complete(void);
static UINT32 qspi_get_receive_data(void);

/*============================================================================
** M E M O R Y   A L L O C A T I O N
**==========================================================================*/

/*============================================================================
** E N T R Y   P O I N T S  /  D A T A   A C C E S S   S E R V I C E S
**==========================================================================*/

#ifdef HMI_GFX_MGR02_QSPI_DUAL_MODE_SUPPORT
#ifndef WIN32
void qspi_flash_write_enable(void)
{
    //printf("Enable the Flash for writting");
    QUADSPI_0.ICR.R = 0x00000006;
    while(QUADSPI_0.SFMSR.B.BUSY);
}


void wait_while_flash_busy(void)
{
    unsigned int read_data;
    QUADSPI_0.MCR.B.CLR_RXF = 1; //clear RX buffer
    read_data = 0x01000000;
    while((read_data & 0x01000000)==0x01000000)
    {
        QUADSPI_0.ICR.R = 0x00010005;
        while(QUADSPI_0.SFMSR.B.BUSY);
        while(QUADSPI_0.SFMSR.B.RXNE == 0);//debug
        read_data = QUADSPI_0.RBDR[0].R; //QUADSPI_ARDB;
        QUADSPI_0.SFMFR.R = 0x10000; /* read complete */
    }
}
#endif
void QSPI_DUAL_MODE_INIT(void)
{
#ifndef WIN32
   //setup QuadSPI_A
   SIU.PCR[PF13].R = 0x70C; // IO0
   SIU.PCR[PF14].R = 0x70C; // IO1
   SIU.PCR[PF11].R = 0x70C; //IO2
   SIU.PCR[PF12].R = 0x70C; //IO3
   SIU.PCR[PF10].R = 0x70F; //CS
   SIU.PCR[PF15].R = 0x60C; //SCLK
   //setup QuadSPI_B
   SIU.PCR[PF6].R = 0x70C; // IO0
   SIU.PCR[PF5].R = 0x70C; // IO1
   SIU.PCR[PK1].R = 0x70C; //IO2
   SIU.PCR[PJ15].R = 0x70C; //IO3
   SIU.PCR[PJ13].R = 0x70F; //CS
   SIU.PCR[PJ14].R = 0x60C; //SCLK

   CGM.AC3_SC.B.SELCTL = 2;       // secondary pll @ 80Mhz, no division
   CGM.AC3_DC.B.DE0    = 1;
   CGM.AC3_DC.B.DIV0   = 0;

   // Enable sfm mode for spansion
   QUADSPI_0.MCR.B.VMID = 2;
   QUADSPI_0.MCR.B.MDIS = 0;//enable module

   //enable Quad Mode on both parts
   /* change to QuadSPI mode */
   //flash a
#ifdef RAINBOW_CUT1
   QUADSPI_0.SFAR.R = 0x80000000;
#else
   QUADSPI_0.SFAR.R = 0x70000000;
#endif
   qspi_flash_write_enable();
   QUADSPI_0.TBDR.R = 0x00020000; //data to be written
   QUADSPI_0.ICR.R  = 0x00020001; //write config register
   while(QUADSPI_0.SFMSR.B.BUSY);
   wait_while_flash_busy();
   //flash b
#ifdef RAINBOW_CUT1
   QUADSPI_0.SFAR.R = 0x84000000;
#else
   QUADSPI_0.SFAR.R = 0x78000000;
#endif
   qspi_flash_write_enable();
   QUADSPI_0.TBDR.R = 0x00020000; //data to be written
   QUADSPI_0.ICR.R = 0x00020001;  //write config register
   while(QUADSPI_0.SFMSR.B.BUSY);
   wait_while_flash_busy();
   //enable quad reads
   QUADSPI_0.ICR.R = 0x000000a3; //Send instruction to enable high performance mode
   while(QUADSPI_0.SFMSR.B.BUSY);
   /*
   ** 0x00007ceb; //Use Quad I/O reads - Command: 0xEB, Read Size:64bytes
   */
   QUADSPI_0.ACR.R = 0x00A040EB;
   QUADSPI_0.LCR.R = 4;
#endif
}
#endif
/*============================================================================
**
** Function Name:       void qspi_init(void)
**
** Visibility:          This function is externally visible via the
**                      "qspi.h" header file.
**
** Description:         Function to be called to initialize the QSPI
**                      peripheral for communication with an external Spansion
**                      flash IC.
**
**                      If the external IC does not already have its
**                      "quad mode" bit set in its internal configuration
**                      register, this routine will also set it.
**
**                      The QSPI peripheral has already been configured in
**                      DISTART.C to use PLL1 running at 48Mhz as its clock
**                      source.
**
** Invocation:          Called by the function "gdg02_CommonInit()" in
**                      GDG02.C when it is initializing the DCU peripheral.
**
** Inputs/Outputs:      The QSPI peripheral registers are written to enable
**                      the QSPI to communicate with an external Spansion
**                      flash IC.
**
** Critical Section:    None
**
** Created:             06/30/09 by JKANOZA
**
** Updated:             04/13/11 by JKANOZA
**
**==========================================================================*/
void qspi_init(void)
{
#ifdef HMI_GFX_MGR02_QSPI_DUAL_MODE_SUPPORT
  QSPI_DUAL_MODE_INIT();

#else  
  UINT32 qspi_rx_data;

  /*
  ** Configure all QSPI GPIO.
  **
  ** PCS_C0, CS#, PF10:
  **  - Alternate pin to select QSPI control
  **  - Output buffer enabled (OBE)
  **  - Weak pull up enabled (WPE & WPS)
  **
  ** PCS_C1, W#/ACC/I02, PF11:
  **  - Alternate pin to select QSPI control
  **  - Output buffer enabled (OBE)
  **  - Input buffer enabled (IBE)
  **  - Weak pull up enabled (WPE & WPS)
  **
  ** PCS_C2, HOLD#/IO3, PF12:
  **  - MUST be left as GPIO until the Configuration Register is read!!!
  **  - Output buffer enabled (OBE)
  **  - Weak pull up enabled (WPE & WPS)
  **  - Output driven high
  **
  ** SIN_C, IO0, PF13:
  **  - Alternate pin to select QSPI control
  **  - Output buffer enabled (OBE)
  **  - Input buffer enabled (IBE)
  **  - Weak pull up enabled (WPE & WPS)
  **
  ** SOUT_C, IO1, PF14:
  **  - Alternate pin to select QSPI control
  **  - Output buffer enabled (OBE)
  **  - Input buffer enabled (IBE)
  **  - Weak pull up enabled (WPE & WPS)
  **
  ** SCK_C, SCK, PF15:
  **  - Alternate pin to select QSPI control
  **  - Output buffer enabled (OBE)
  **  - Weak pull up enabled (WPE & WPS)
  */
  #if defined (CWR_MPC5645S) || defined (CWR_MPC5645S_LITE)
  SIU.PCR[PF10].R = 0x060C;
  SIU.PCR[PF11].R = 0x070C;
  SIU.PCR[PF12].R = 0x020C;
  SIU.GPDO[PF12].B.PDO = 1;
  SIU.PCR[PF13].R = 0x070C;
  SIU.PCR[PF14].R = 0x070C;
  SIU.PCR[PF15].R = 0x060C;
  #else
  SIU.PCR[PF10].R = 0x0A03;
  SIU.PCR[PF11].R = 0x0B03;
  SIU.PCR[PF12].R = 0x0203;
  SIU.GPDO[PF12].B.PDO = 1;
  SIU.PCR[PF13].R = 0x0703;
  SIU.PCR[PF14].R = 0x0703;
  SIU.PCR[PF15].R = 0x0603;
  #endif

  QUADSPI_0.MCR.B.MDIS    = 1;
  /*
  ** Enable Serial Flash Mode (SFM) using the Windbond command interface.
  ** Note that this interface is identical to the Spansion interface.
  ** On Rainbow, an SFM for Spansion exists so use that one.
  */
  #if defined (CWR_MPC5645S) || defined (CWR_MPC5645S_LITE)
  QUADSPI_0.MCR.R = 0x000F4C10;
  #else
  QUADSPI_0.MCR.R = 0x00004C88;
  #endif

  #if defined (CWR_MPC5645S) || defined (CWR_MPC5645S_LITE)
  QUADSPI_0.ACR.R = 0x000080EB;
  #else
  QUADSPI_0.ACR.R = 0x000040EB;
  #endif

  QUADSPI_0.MCR.B.MDIS    = 0;

  /*
  ** After a wakeup from sleep (i.e. STOP mode), the QSPI peripheral is still
  ** in continuous access mode which was set via the ARMB field in the ACR
  ** register.  By issuing the following command, the QSPI will be reset
  ** and will function properly.  This strategy was recommended by
  ** Freescale.  This command is ignored by the Spansion flash IC.
  */
  QUADSPI_0.ICR.R = 0x000000FF;
  qspi_wait_for_ICR_complete();

  /*
  ** Send the Read Configuration Register command to get the value of the
  ** configuration register in the external flash IC.
  */
  QUADSPI_0.ICR.R = 0x00010035;
  qspi_wait_for_ICR_complete();
  qspi_rx_data = qspi_get_receive_data();

  /*
  ** Program the config register if it is not the expected value.  The "quad
  ** mode" bit (BIT1) should be set otherwise the chip will not run in
  ** quad mode which is our desired mode.  This bit comes from the factory
  ** as 0 but it is non-volatile, so we only need to set it once.
  */
  if ((qspi_rx_data & 0xFF000000uL) != 0x02000000uL)
  {
    /*
    ** For robustness, reconfigure IO2 as an output and drive it high or else
    ** the config register program sequence may not work.
    */
    #if defined (CWR_MPC5645S) || defined (CWR_MPC5645S_LITE)
    SIU.PCR[PF11].R = 0x020C;
    #else
    SIU.PCR[PF11].R = 0x0203;
    #endif
    SIU.GPDO[PF11].B.PDO = 1;

    /*
    ** Send the Write Enable (WREN) command to enable writing the config
    ** register.
    */
    QUADSPI_0.ICR.R = 0x00000006;
    qspi_wait_for_ICR_complete();

    /*
    ** Send the Write Status & Config Registers (WRR) command to
    ** reprogram the registers.
    */
    #if defined (CWR_MPC5645S) || defined (CWR_MPC5645S_LITE)
    QUADSPI_0.TBDR.R = 0x00020000;
    #else
    QUADSPI_0.TBDR = 0x00020000;
    #endif
    QUADSPI_0.ICR.R = 0x00020001;
    qspi_wait_for_ICR_complete();

    /*
    ** Reconfigure the I/O to give back control to the QSPI peripheral.
    */
    #if defined (CWR_MPC5645S) || defined (CWR_MPC5645S_LITE)
    SIU.PCR[PF11].R = 0x070C;
    #else
    SIU.PCR[PF11].R = 0x0B03;
    #endif
  }

  /*
  ** Reconfigure the I/O to give back control to the QSPI peripheral.
  */
  #if defined (CWR_MPC5645S) || defined (CWR_MPC5645S_LITE)
  SIU.PCR[PF12].R = 0x070C;
  #else
  SIU.PCR[PF12].R = 0x0B03;
  #endif

  /*
  ** ACR options:
  ** ARMB = 0xA0 -- Tell the Spansion I/C to remain in Quad I/O mode
  **                so that the next address can be entered without
  **                repeating the 0xEB instruction byte.  This saves
  **                8 clock cycles per transaction.
  **
  ** ARSZ = 0x40 -- Read 64 bytes at a time from the Spansion I/C.
  **
  ** ARIC = 0xEB -- Select Quad I/O High Performance Read Mode (QIOR).
  **
  ** These options have been chosen to maxmize throughput from the
  ** QSPI / Spansion IC.  Be warned that even with these selections,
  ** a large 24BPP image cannot be retrieved fast enough from the
  ** Spansion IC for display by the DCU.
  **
  */
  #if defined (CWR_MPC5645S) || defined (CWR_MPC5645S_LITE)
  QUADSPI_0.ACR.R = 0x00A080EB;

    #ifdef QSPI_LCR_VALUE
    /*
    ** The Spansion flash IC requires 4 dummy clock cycles before it is ready to
    ** respond to a Quad I/O High Performance Read instruction (0xEB).  The new
    ** CUT2 Rainbow silicon has a register to set this value.
    */
    QUADSPI_0.LCR.R = QSPI_LCR_VALUE;
    #endif
  #else
  QUADSPI_0.ACR.R = 0x00A040EB;
  #endif

  /*
  ** After a wakeup from sleep (i.e. STOP mode), the QSPI peripheral is still
  ** in continuous access mode which was set via the ARMB field in the ACR
  ** register.  By issuing the following command, the QSPI will be reset
  ** and will function properly.  This strategy was recommended by
  ** Freescale.  This command is ignored by the Spansion flash IC.
  */
  QUADSPI_0.ICR.R = 0x000000FF;
#endif
}

/*============================================================================
**
** Function Name:       void qspi_sleep(void)
**
** Visibility:          This function is externally visible via the
**                      "qspi.h" header file.
**
** Description:         Function to be called to put the QSPI peripheral
**                      into sleep mode.
**
** Invocation:          Called by the function "gdg02_KSSleep()" in GDG02.C
**                      when it wants to pu the QSPI peripheral to sleep.
**
** Inputs/Outputs:      The QSPI SFMFR registers is cleared so that sleep
**                      can occur.
**
** Critical Section:    None
**
** Created:             06/22/10 by JKANOZA
**
** Updated:             06/22/10 by JKANOZA
**
**==========================================================================*/
void qspi_sleep(void)
{
  /*
  ** For the Rainbow, we need to be sure there is no data in the QSPI
  ** RX buffer, so write to the flag register.  Since all the bits are
  ** write-once-to-clear, the value chosen will clear all bits.  In
  ** particular, we are interested in clearing the SFMFR.RBDF flag.
  ** This is not required for the Spectrum.
  */
  #if defined (CWR_MPC5645S) || defined (CWR_MPC5645S_LITE)
  QUADSPI_0.SFMFR.R = 0x0C037ED1;
  #endif
}

/*============================================================================
**
** Function Name:       void qspi_wait_for_ICR_complete(void)
**
** Visibility:          Static function.
**
** Description:         Function to wait for a command initiated through
**                      writing to the ICR register to be completed.
**
** Invocation:          Called by the function "qspi_init()" when it needs
**                      to wait for an ICR command to complete.
**
** Inputs/Outputs:      None
**
** Critical Section:    None
**
** Created:             06/30/09 by JKANOZA
**
** Updated:             06/30/09 by JKANOZA
**
**==========================================================================*/
static void qspi_wait_for_ICR_complete(void)
{
  /*
  ** Loop until the busy flag is cleared.
  */
  while(QUADSPI_0.SFMSR.B.BUSY != 0)
  {
  };
}

/*============================================================================
**
** Function Name:       UINT32 qspi_get_receive_data(void)
**
** Visibility:          Static function.
**
** Description:         Function to wait for and return data received via the
**                      QSPI port.
**
** Invocation:          Called by the function "qspi_init()" when it needs
**                      to wait for rx data.
**
** Inputs/Outputs:      Returns the data received via the QSPI.
**
** Critical Section:    None
**
** Created:             06/30/09 by JKANOZA
**
** Updated:             06/22/10 by JKANOZA
**
**==========================================================================*/
static UINT32 qspi_get_receive_data(void)
{
  /*
  ** Loop until the RX not empty flag is clear.  If nothing comes back, we
  ** will get a COP timeout.
  */
  while(QUADSPI_0.SFMSR.B.RXNE == 0)
  {
  };

  #if defined (CWR_MPC5645S) || defined (CWR_MPC5645S_LITE)
  return(QUADSPI_0.RBDR[0].R);
  #else
  return(QUADSPI_0.RBDR[0]);
  #endif
}

/*============================================================================
**
**============================================================================
** C M S    R E V I S I O N    N O T E S
**============================================================================
**
** For each change to this file, be sure to record:
** 1.  Who made the change and when the change was made.
** 2.  Why the change was made and the intended result.
**
** CMS Rev #        Date         By
** CMS Rev X.X      mm/dd/yy     CDSID
**
**============================================================================
**
** CMS Rev 9        11/24/11     EMANOJ1
** BSDI00110487,BSDI00110944,BSDI00111097  - QSPI was getting locked after a
** power disturbance on the qspi memory and qspi memory access returned
** 0x00000000. Changes were made to clear the Tx and Rx buffers by setting
** bits in the MCR register. QSPI module was disabled and then reenabled.
** This change is not completely addresess the issue and is still under
** investigation. So this changes are just ICA for the moment.
**
** CMS Rev 8        06/25/11     EMANOJ1
** Integrated robusteness suggestion from Jeff to properly initialize QSPI
** after coming out of sleep.
**
** CMS Rev 7        04/13/11     JKANOZA
** Add inclusion of "qspi.cfg" which allows the user to define or not
** define "QSPI_LCR_VALUE".  If defined, conditionally compiled code will
** write to the LCR register which is needed to make the QSPIv3 peripheral
** work properly for Spansion chips.  A more detailed description of the
** reason is available in the sample QSPI.CFG file.
**
** CMS Rev 6        01/01/11     JKANOZA
** Updated the SCR (slew rate control registers) for the Rainbow and Rainbow
** Lite micros so that the proper drive strength is selected.  Otherwise, the
** QSPI may not function at speeds higher than 64 MHz.
**
** CMS Rev 5        06/22/10     JKANOZA
** 1) Added "qspi_sleep()" that should be called prior to attempting to
**    enter sleep mode.  This will enable the QSPI peripheral to enter
**    sleep.  This function exists for both the Rainbow and Spectrum,
**    but via conditional compilation does not do anything on the Spectrum
**    because nothing special needs to be done.
** 2) Added a check for CWR_MPC5645S_LITE everwhere there was a check
**    for CWR_MPC5645S because the Rainbow Lite uses the same register
**    set as the Rainbow.
**
** CMS Rev 4        03/09/10     JKANOZA
** Added conditionalized code to support the Rainbow which has a slightly
** different register set for the QSPI.
**
** CMS Rev 3        10/06/09     JKANOZA
** After a wakeup from sleep (i.e. STOP mode), the QSPI peripheral is still
** in continuous access mode which was set via the ARMB field in the ACR
** register.  When this happens, external QSPI data will not be loaded
** properly.  To fix this issue, "qspi_init()" has been updated with a
** fix recommended by Freescale.
**
** CMS Rev 2        07/27/09     JKANOZA
** Updated "qspi_init()" to correct some issues in the init sequence.  In
** particular, the HOLD pin must be driven high before issuing the
** Read Configuration Register command.  If it isn't, and the flash memory
** is not in quad mode, then the command may fail.
**
** CMS Rev 1        06/30/09     JKANOZA
** Initial revision.
**
**==========================================================================*/

/* end of file =============================================================*/
