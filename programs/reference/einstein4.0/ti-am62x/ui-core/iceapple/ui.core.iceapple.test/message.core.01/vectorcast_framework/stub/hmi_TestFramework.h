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
**  Name:               hmi_TestFramework.h
**
**  Description:
**
**  Organization:       Driver Information Software Section,
**                      DI Core Engineering Department
**
**===========================================================================*/
#ifndef hmi_TestFramework_H
#define hmi_TestFramework_H

/*==========================================================================*/
/* I N C L U D E   F I L E S                                                */
/*==========================================================================*/

/*==========================================================================*/
/* T Y P E   D E F I N I T I O N S                                          */
/*==========================================================================*/

typedef struct
{
    void (*SetupTest)(UINT16 Value);        /* Test setup function      */
    UINT32 InitValue;                       /* Initialisation value     */
} TEST_SETUP_T;

typedef struct
{
    BOOLEAN (*RunTest)(void);               /* Test run function        */
    UINT32 Repetitions;                     /* Number of RUN loops      */
} TEST_RUN_T;

typedef struct
{
    BOOLEAN (*CheckTest)(UINT16 Value);     /* Test check function      */
    UINT32 ExpectedValue;                   /* Expected value           */
} TEST_CHECK_T;

typedef struct
{
    const TEST_SETUP_T *Setup;
    const TEST_RUN_T   *Run;
    const TEST_CHECK_T *Check;
} TEST_INSTANCE_T;

#if 0
typedef struct
{
    void (*SetupTest)(UINT16 Value);        /* Test setup function      */
    UINT16 InitValue;                       /* Initialisation value     */
    BOOLEAN (*RunTest)(void);               /* Test run function        */
    UINT16 Repetitions;                     /* Number of RUN loops      */
    BOOLEAN (*CheckTest)(UINT16 Value);     /* Test check function      */
    UINT16 ExpectedValue;                   /* Expected value           */
} TEST_INSTANCE_T;
#endif

/*==========================================================================*/
/* E N T R Y   P O I N T S                                                  */
/*==========================================================================*/

/*==========================================================================*/
/* F U N C T I O N  P R O T O T Y P E S                                     */
/*==========================================================================*/
void hmitest_KSColdInit(void);
void hmitest_KSWarmInit(void);
void hmitest_KSRRobin(void);
void hmitest_KSSleep(void);
void hmitest_KSWakeup(void);
BOOLEAN hmitest_KSNvRamCheck(void);

/*==========================================================================*/
/* R E V I S I O N    N O T E S                                             */
/*==========================================================================*/
/* For each change to this file, be sure to record:
** 1.  Who made the change and when the change was made.
** 2.  Why the change was made and the intended result.
**==========================================================================*/

/****************************************************************************
**  Date  : 13/Apr/2010
**  by    : AFERRIS2
**  Ref   : None.
**  Change: Initial version.
**
*****************************************************************************/

#endif  /* hmi_TestFramework_H */
/* end of file =============================================================*/
