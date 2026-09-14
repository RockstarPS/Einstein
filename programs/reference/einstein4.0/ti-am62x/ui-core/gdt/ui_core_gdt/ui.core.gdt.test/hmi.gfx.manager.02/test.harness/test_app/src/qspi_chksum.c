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
**  Name:               qspi_chksum.c
**
**  Description:        Interface for the checksum routines.
**
**  Organization:       Driver Information Software Section,
**
**============================================================================
**
**
**==========================================================================*/

/*============================================================================
**                   I N C L U D E   F I L E S
**==========================================================================*/
#include "hmi_gfx_mgr02.cfg"
#ifdef HMI_GFX_MGR02_CALC_QSPI_CHKSUM
#include "system.h"
#include "qspi_chksum.h"
#include "sched.h"
/*============================================================================
**   I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S
**==========================================================================*/
/* Start and End address of qspi memeory */
#define QSPI_MEMORY_START_ADDR     (ACTUAL_EXTERNAL_FLASH_ROM_START_ADDR)
#define QSPI_MEMORY_END_ADDR       (ACTUAL_EXTERNAL_FLASH_ROM_END_ADDR)    
/* Total memory size in bytes */
#define QSPI_MEMORY_SIZE_IN_BYTES  ((QSPI_MEMORY_END_ADDR - QSPI_MEMORY_START_ADDR)+1ul)
/* Total number of blocks calculates */
#define TOTAL_NUM_BLOCKS           ((QSPI_MEMORY_SIZE_IN_BYTES) / (BYTES_PER_BLOCK)) 
/*============================================================================
**      I N T E R N A L   F U N C T I O N   P R O T O T Y P E S
**==========================================================================*/

/*============================================================================
**                M E M O R Y   A L L O C A T I O N
**==========================================================================*/
static UINT32   qspi_checksum_rom;
static UINT32   qspi_block_counter;
static BOOLEAN  qspi_checksum_started; 
/*============================================================================
**              F U N C T I O N S / S E R V E R S
**==========================================================================*/

/*============================================================================
**
** Name:            qspi_checksum_init
**
** Description:     Initializes the checksum started flag to FALSE indicating  
**                  cheksum is not started.
**                  
** Inputs:          none
**
** Outputs:         none
**
** Returns:         None
**
**==========================================================================*/
void qspi_checksum_init(void)
{    
   qspi_checksum_started = FALSE;   
}

/*============================================================================
**
** Name:            qspi_checksum_start
**
** Description:     Initializes the block counter and cheksum value holder. 
**                  Assigns the checksum_started to TRUE indicating checksum 
**                  calculation is started
**
** Inputs:          none
**
** Outputs:         none
**
** Returns:         None
**
**==========================================================================*/
void qspi_checksum_start(void)
{
   qspi_checksum_started = TRUE;
   qspi_block_counter    = TOTAL_NUM_BLOCKS;
   qspi_checksum_rom     = 0;
}
/*============================================================================
**
** Name:            qspi_checksum_process_next_block
**
** Description:     calculates checksum for current block.
**
** Inputs:          none
**
** Outputs:         none
**
** Returns:         none
**==========================================================================*/
void qspi_checksum_process_next_block( void )
{    
    UINT32 *ptr = (UINT32 *)(void *)&(((UINT8 *)(void *)QSPI_MEMORY_START_ADDR)[((qspi_block_counter - 1ul) * TOTAL_NUM_BLOCKS)]);
    UINT32 *blk_end = &((ptr)[(TOTAL_NUM_BLOCKS >> 2)]);
    UINT32 loc_chksm = 0;

    if (qspi_block_counter > 0ul)
    {
        while (ptr < blk_end)
        {
            loc_chksm += *ptr;
            ptr++;
        }

        qspi_checksum_rom += loc_chksm;
        qspi_block_counter = qspi_block_counter - 1ul;
    }
    else
    {
        qspi_checksum_started = FALSE;
    }     
}
/*============================================================================
**
** Name:            qspi_checksum_is_completed
**
** Description:     Indicates if checksum is done or not
**
** Inputs:          none
**
** Outputs:         return
**                          TRUE if checksum done, FALSE otherwise
**
** Returns:         Boolean
**                  
**==========================================================================*/
BOOLEAN qspi_checksum_is_completed(void)
{
    if(qspi_block_counter == 0ul)
    {            
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
/*============================================================================
**
** Name:            qspi_checksum_ok
**
** Description:     Checks for the validity of the checksum
**
** Inputs:          none
**
** Outputs:         return TRUE if checksum ok, else FALSE
**
** Returns:         BOOLEAN
**==========================================================================*/
BOOLEAN qspi_checksum_ok ( void )
{
    if(qspi_checksum_rom == 0ul)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}                      
/*============================================================================
**
** Name:            qspi_checksum_is_started
**
** Description:     Shall return the checksum calculation status.
**
** Inputs:          none
**
** Outputs:         Cheksum calculation status
**
** Returns:         BOOLEAN 
**
**==========================================================================*/
BOOLEAN qspi_checksum_is_started(void)
{
  return qspi_checksum_started;
}
/*============================================================================
**
** Name:            qspi_checksum_Calculator
**
** Description:     Shall do the checksum calculation in a single shot.
**
** Inputs:          none
**
** Outputs:         Calculated cheksum
**
** Returns:         UINT32 
**
**==========================================================================*/
UINT32 qspi_checksum_Calculator( void )
{
    qspi_checksum_init();
    qspi_checksum_start();

    while (qspi_checksum_is_completed() == FALSE)
    {
        qspi_checksum_process_next_block();
        KernelUpdateWatchdog();
    }

    return (qspi_checksum_rom);
}      
#endif
/*============================================================================
**     R E V I S I O N    N O T E S
**============================================================================
**
** For each change to this file, be sure to record:
** 1.  Who made the change and when the change was made.
** 2.  Why the change was made and the intended result.
**
**============================================================================
**
** Rev 1.4   27-June-2012    ashekhar
**           Updated the conditional macro and the gdg02_gfx_mgr for hmi_gfx_mgr02
**           package.
**
** Rev 1.3   28-oct-2011     ksriniv2
**           Updated peer review comments (PR ID - 48628).
**
** Rev 1.2   27-sep-2011     ksriniv2
**           Updated as per vasu's(GVASUDE1) observation.
**           Updated BYTES_PER_BLOCK to 2048(2KB) as per mike's(MTURNER9) 
**           suggestion
** Rev 1.1   28-jul-2011     ksriniv2
**           Updated as per perr review comments in PR ID 44830
**  
** Rev 1.0   02-jun-2011     ksriniv2
**           Initial version
**
**==========================================================================*/

/* End of file ============================================================ */
