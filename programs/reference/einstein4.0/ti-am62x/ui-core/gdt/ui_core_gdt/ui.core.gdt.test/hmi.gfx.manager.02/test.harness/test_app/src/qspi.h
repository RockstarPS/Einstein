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
** Name:           qspi.h
**
** Description:    This file contains the public interface definition of the
**                 Quad SPI (QSPI) driver for initializing the QSPI peripheral
**                 for communication with an external Spansion flash IC.
**
** Organization:   Driver Information Software Section,
**                 DI Core Engineering Department
**
**============================================================================
**
**==========================================================================*/
#ifndef QSPI_H
#define QSPI_H


/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include "system.h"

/*============================================================================
** T Y P E   D E F I N I T I O N S
**==========================================================================*/


/*============================================================================
** E N T R Y   P O I N T S
**==========================================================================*/
void qspi_init(void);
void qspi_sleep(void);

/*============================================================================
** D A T A   A C C E S S   S E R V I C E S
**==========================================================================*/


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
** CMS Rev 2        06/22/10     JKANOZA
** Added "qspi_sleep()" that should be called prior to attempting to
** enter sleep mode.  This will enable the QSPI peripheral to enter
** sleep.  This function exists for both the Rainbow and Spectrum,
** but via conditional compilation does not do anything on the Spectrum
** because nothing special needs to be done.
**
** CMS Rev 1        06/30/09     JKANOZA
** Initial revision.
**
**==========================================================================*/

/* end of file =============================================================*/

#endif