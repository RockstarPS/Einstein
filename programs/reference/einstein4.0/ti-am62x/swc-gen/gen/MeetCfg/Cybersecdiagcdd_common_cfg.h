/*===================================================================================================================
**
**                     CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2001. Visteon Corporation owns all rights to this work and
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
**===================================================================================================================
**
** Name:           Cybersecdiagcdd_common_cfg.h
**
** Description:    contains configurable parameters for Memory services
**                
**
**====================================================================================================================*/
#ifndef CYBERSECDIAGCDD_COMMON_CFG_H
#define CYBERSECDIAGCDD_COMMON_CFG_H
/*====================================================================================================================
** INCLUDE FILES
**===================================================================================================================*/
/*====================================================================================================================
**   M A C R O   D E F I N I T I O N S
**===================================================================================================================*/
#ifdef CRYPTO_KEY_MANAGEMENT
#define AES_IV_KEY_WFLASH_OFFSET    0x0E00D000UL
#define AES_IV_KEY_ROM_OFFSET    0x009fe01aUL		 

#define RSA_KEY_WFLASH_OFFSET    0x0E00C000UL
#define RSA_KEY_ROM_OFFSET    0x009fe01aUL
#endif
/** AES IV KEY 1 willl be present in AES_IV_KEY_WFLASH_OFFSET + 8 */
/** AES IV KEY 2 willl be present in AES_IV_KEY_WFLASH_OFFSET + 32 */
/** AES IV KEY 3 willl be present in AES_IV_KEY_WFLASH_OFFSET + 56 */

/* RSA Key will present in RSA_KEY_WFLASH_OFFSET + 8 */
/*======================================================================================================================
** T Y P E  D E F I N I T I O N S
**======================================================================================================================*/


/*=====================================================================================================================
*  C O N S T A N T    A N D   V A R I A B L E S    D E C L A R A T I O N S
**===================================================================================================================*/


/*=====================================================================================================================
*   P U B L I C
**=====================================================================================================================*/


/*======================================================================================================================
**  for each change to this file, be sure to record:
**  1.who made the change and when the change was made
**  2.why the change was made and the intended result
**  following block needs to be repeated for each change
**======================================================================================================================*/
/*   Note: In the traceability column we need to trace back to the Design Doc.
**   For the initial version it is traced to the Design Document section.     
**   For further changes it shall trace to the source of the change which may
**   be SPSS/SCR/Defect details(Defect may be Testing/validation defect)/Any  
**   other reason                                                             
**======================================================================================================================*/
/*=====================================================================================================================
** Date              :  13/March/2020
** CDSID             :  razhakes  and dkasiman
** Traceability      :  RTC 1297724
** Change Description:  Work flash sectors address defined for other module usage
**====================================================================================================================*/
#endif


