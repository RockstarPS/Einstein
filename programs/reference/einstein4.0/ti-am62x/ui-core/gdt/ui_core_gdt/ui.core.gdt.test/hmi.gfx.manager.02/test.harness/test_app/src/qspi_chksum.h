/*============================================================================
**                      Copyright Statement
**                     CONFIDENTIAL - VISTEON
**
**    This is an unpublished work, which is a trade secret, created in 2009.
**    Visteon owns all rights to this work and intends to maintain it in
**    confidence to preserve its trade secret status.  Visteon reserves the
**    right to protect this work as an unpublished copyright work in the
**    event of an inadvertent or deliberate unauthorized publication.
**    Visteon also reserves its rights under the copyright laws to protect
**    this work as a published work.  Those having access to this work may
**    not copy it, use it or disclose the information contained in it
**    without the written authorization of Visteon.
**
**============================================================================
**
**  Name:               qspi_chksum.h
**
**  Description:        This file contains the public interface definition
**                      for the checksum support services.
**
**  Organization:       Driver Information Software Section,
**
**
**==========================================================================*/
#if !defined( QSPI_CHKSUM_H )
#define QSPI_CHKSUM_H
/*
** Usage instructions:
**
** 1) Uncomment the Macro "HMI_GFX_MGR02_CALC_QSPI_CHKSUM" defined in gdg02_gfx_mgr$.cfg 
**    to enable the checksum calculation functionality.
**
** 2) The function qspi_checksum_init() is called in the function 
**    gdg02_gfx_mgr_common_init() in gdg02_gfx_manager.c which sets the 
**    checksum_started flag to FALSE, which will protect the functions being 
**    called from calculating the checksum.
**
** 3) The function qspi_checksum_start() in qspi_checksum.c should be called by 
**    the application to start the checksum calculation which sets the 
**    checksum_started flag to TRUE indicating a request is been issued by 
**    application to start the calculation and the calculation is in progress.
**    Also this function initialises all the counters and start address to the 
**    default values.
**
** 4) The checksum shall be calculated for TOTAL_NUM_BLOCKS defined in qspi_chksum.c
**
** 5) The function qspi_checksum_Calculator() is added to do the checksum 
**    calculation in a single shot which shall be called by the application based 
**    on the need. 
**
*/
/* Execution Metrics:
**
** 1. In Rainbow Lite the maximum execution time taken for executing one block(16KB)
**    was observed to be 2.926 milliseconds
**
** 2. In Spectrum the maximum execution time taken for executing one block(16KB)
**    was observed to be 5.264 milliseconds
**
*/
/*============================================================================
**                 I N C L U D E   F I L E S
**==========================================================================*/

/*============================================================================
**   P U B L I C   M A C R O   A N D   T Y P E   D E F I N I T I O N S
**==========================================================================*/

/*============================================================================
**   P U B L I C   F U N C T I O N   P R O T O T Y P E S
**==========================================================================*/

#ifdef HMI_GFX_MGR02_CALC_QSPI_CHKSUM
/*============================================================================
**
** Name:            qspi_checksum_init
**
** Description:     Initializes the start location and internal variables to 
**                  default values
**
** Inputs:          none
**
** Outputs:         none
**
** Returns:         none
**
**==========================================================================*/
extern void qspi_checksum_init(void);
/*============================================================================
**
** Name:            qspi_checksum_is_completed
**
** Description:     Returns TRUE if checksum calculation is over.
**
** Inputs:          none
**
** Outputs:         Checksum completion status
**
** Returns:         BOOLEAN, TRUE = Completed, FALSE = not completed.
**
**==========================================================================*/
extern BOOLEAN qspi_checksum_is_completed(void);

/*============================================================================
**
** Name:            qspi_checksum_process_next_block
**
** Description:     calculates the checksum for the current block.
**
** Inputs:          none
**
** Outputs:         none
**
** Returns:         none
**==========================================================================*/
extern void qspi_checksum_process_next_block( void );

/*============================================================================
** Name:            qspi_checksum_ok
**
** Description:     Validates the calculated checksum
**
** Inputs:          none
**
** Outputs:         TRUE - valid, FALSE - Not valid
** Returns:         BOOLEAN
**==========================================================================*/
extern BOOLEAN qspi_checksum_ok ( void );

/*============================================================================
**============================================================================
**
** Name:            qspi_checksum_is_started
**
** Description:     Shall return the checksum started status
**
** Inputs:          none
**
** Outputs:         TRUE - If started, FALSE - If not started
**
** Returns:         BOOLEAN
**
**==========================================================================*/
extern BOOLEAN qspi_checksum_is_started(void); 
/**============================================================================
**
** Name:            qspi_checksum_start
**
** Description:     Initializes the start location and internal variables. 
**					Assigns the checksum_started to TRUE indicating checksum 
**                  calculation is startednone
**
** Inputs:          none
**
** Outputs:         none
**
** Returns:         none
**
**==========================================================================*/
extern void qspi_checksum_start(void); 
/**============================================================================
**
** Name:            qspi_checksum_Calculator
**
** Description:     Shall do the checksum calculation in a single shot.
**
** Inputs:          none
**
** Outputs:         calculated checksum
**
** Returns:         UINT32
**
**==========================================================================*/
extern UINT32 qspi_checksum_Calculator( void );

#endif
/*============================================================================
**   P U B L I C   D A T A  A N D  A C C E S S  M A C R O S
**==========================================================================*/

/*============================================================================
**  P V C S    R E V I S I O N    N O T E S
**----------------------------------------------------------------------------
**  for each change to this file, be sure to record:
**  1.  who made the change and when the change was made
**  2.  why the change was made and the intended result
**
**----------------------------------------------------------------------------
**
** Rev 1.1   28-jul-2011     ksriniv2
**           Updated as per perr review comments in PR ID 44830
**  
** Rev 1.0   02-jun-2011     ksriniv2
**           Initial version
**
**==========================================================================*/

#endif /* QSPI_CHKSUM_H ====================================================== */

