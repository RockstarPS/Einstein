/*****************************************************************************
 *                                                                            *
 *              CONFIDENTIAL VISTEON CORPORATION                              *
 *                                                                            *
 * This is an unpublished work of authorship, which contains trade            *
 * secrets, created in 2018. Visteon Corporation owns all rights to           *
 * this work and intends to maintain it in confidence to preserve             *
 * its trade secret status. Visteon Corporation reserves the right,           *
 * under the copyright laws of the United States or those of any              *
 * other country that may have jurisdiction, to protect this work             *
 * as an unpublished work, in the event of an inadvertent or                  *
 * deliberate unauthorized publication. Visteon Corporation also              *
 * reserves its rights under all copyright laws to protect this               *
 * work as a published work, when appropriate. Those having access            *
 * to this work may not copy it, use it, modify it or disclose the            *
 * information contained in it without the written authorization              *
 * of Visteon Corporation.                                                    *
 *                                                                            *
 ******************************************************************************/
/*!***************************************************************************
 * @ingroup
 * @file FlsTst_Cfg.h
 * @brief Configuration header file for adc inputs
 * ****************************************************************************/
#ifndef FLSTST_CFG_H
#define FLSTST_CFG_H

/*****************************************************************************
 *  Include Files                                                             *
 ******************************************************************************/
#include "Std_Types.h"
/*****************************************************************************
 *  Public Macros Definitions                                                *
 ******************************************************************************/

/**
 * @brief Macro to enable API
 */

#define FLSTST_STARTFGND_API						STD_ON
#define FLSTST_ABORT_API						    STD_ON
#define FLSTST_SUSPEND_API						    STD_ON
#define FLSTST_RESUME_API						    STD_ON
#define FLSTST_GETCURRENTSTATE_API					STD_ON
#define FLSTST_GETTESTRESULTBGND_API				STD_ON
#define FLSTST_GETTESTRESULTFGND_API				STD_ON
#define FLSTST_GETTESTSIGNATUREBGND                 STD_ON
#define FLSTST_GETTESTSIGNATUREFGND                 STD_ON
#define FLSTST_GETVERSIONINFO_API					STD_ON
#define FLSTST_GETERRORDETAILS_API					STD_ON
#define FLSTST_TESTECC_API						    STD_ON
#define FLSTSTTESTCOMPLETEDNOTIFICATIONSUPPORTED    STD_ON

/* Number of cells to be tested in background mode during one scheduled task */
#define FlsTstNumberOfTestedCells                  20

/* Number of cells to be tested in background mode without checking user requests (Abort, Suspend) */
#define FlsTstNumberOfTestedCellsAtomic            10

/* The end value of the Test Interval Id after this maninfunction will reset the Test Interval Id as Zero. */
#define FlsTstTestIntervalIdEndValue               4

/* Number of Block to be tested in foreground mode */
#define NO_OF_FNG_BLOCK                               1UL
/* Number of cells to be tested in background mode */
#define NO_OF_BNG_BLOCK                               1UL

/*****************************************************************************
 *  Type Declarations                                              			 *
 ******************************************************************************/
typedef enum
{
    FLSTST_32BIT_CRC,
    FLSTST_8BIT_CRC,
    FLSTST_CHECKSUM,
    FLSTST_DUPLICATED_MEMORY,
    FLSTST_ECC,
} FlsTstTestAlgorithmType;

typedef struct
{
    uint32 FlsTstBlockIndex;
    uint32 FlsTstBlockBaseAddress;
    uint32 FlsTstBlockEndAddress;
    uint32 FlsTstBlockSize;
    FlsTstTestAlgorithmType FlsTstTestAlgorithm;
    uint8 Readunit;
} FlsTstBlocktype;

typedef void (*FlsTstNotify)(void);
typedef struct
{
    const FlsTstBlocktype *FlsTstBlockFgnd;
    const FlsTstBlocktype *FlsTstBlockBgnd;
    FlsTstNotify FlsTstTestCompletedNotification;
} FlsTst_ConfigType;

/*****************************************************************************
 *  Public Forward Declarations                                          	 *
 ******************************************************************************/
extern const FlsTstBlocktype FlsTstBlockFgnd[NO_OF_FNG_BLOCK];
extern const FlsTstBlocktype FlsTstBlockBgnd[NO_OF_BNG_BLOCK];
extern const FlsTst_ConfigType FlsTstBlock;

void FlsTst_ReportDetError(uint32 APIID, uint32 ErrorID);

#endif /* FlsTst_CFG_H */

/*End of File*/
/*****************************************************************************
 *  for each change to this file, be sure to record:                         *
 *     1.  who made the change and when the change was made                  *
 *     2.  why the change was made and the intended result                   *
 *  Following block needs to be repeated for each change
 ******************************************************************************
 *  Note: In the trace-ability column we need to trace back to the Design Doc.*
 *  For the initial version it is traced to the Design Document section.     *
 *  For further changes it shall trace to the source of the change which may *
 *  be SPSS/SCR/Defect details(Defect may be Testing/validation defect)/Any  *
 *  other reason                                                            *
 ******************************************************************************/
/*****************************************************************************
 Date              :16-Jul-2020
 By                :bbaskara
 Traceability      :RTC
 Change Description:Initial Version for FlsTst implementation
 ******************************************************************************/
