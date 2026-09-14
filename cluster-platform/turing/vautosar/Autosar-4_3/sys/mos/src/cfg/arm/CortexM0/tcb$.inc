    .set    osdStackCheck                        ,0x00000000
    .set    osdStackUsageMeasurement             ,1
    .set    osdSysTimerIrqNumber                 ,25
    .set    osdEnableAssertions                  ,1
    .set    osdDerivative                        ,3
    .set    osdStackCheckPattern                 ,0xaaaaaaaa
    .set    osdNumberOfMPURegions                ,0x00000010
    .set    osdMPURegionFirstUsed                ,0x00000000
    .set    osdMPURegionLastUsed                 ,0x00000009
    .set    osdErrorHook                         ,1
    .set    osdPreTaskHook                       ,1
    .set    osdPostTaskHook                      ,1
    .set    osdShutdownHook                      ,1
    .set    STATUS_LEVEL                         ,1
    .set    osdFPUSupport                        ,1
    .set    osdFullPreempt                       ,0
    .set    osdMixedPreempt                      ,1
    .set    osdNeedCI707_00026_Workaround        ,0
    .set    osdNeedCI707_00027_Workaround        ,0
    .set    osdNonPreempt                        ,0
    .set    osdNumberOfApplMPURegions            ,1
    .set    osdNumberOfGlobalMPURegions          ,7
    .set    osdNumberOfInternalResources         ,0
    .set    osdReducedStatusChecks               ,0
    .set    osdRegionIndexForStackWindow         ,5
    .set    osdSC                                ,1
    .set    osdSystemApplIDCore0                 ,1
    .set    osdORTIDebug                         ,0x00000001
    .set    osdORTIStdVersion                    ,0x000000dc
    .set    osdORTIEnabled                       ,0x00000001
    .set    osdNumberOfAllTasks                  ,0x00000011
/* Resources */





/* Counter */



/* Schedule Tables */

/* Applications */

/* file: tcb.inc
* Implementation: Cortex m0p
* Version of general code: 6.20.01 */

    .set    osdVrmMajRelGenNum     ,6
    .set    osdVrmMinRelGenNum     ,0


/* END OF tcb.inc */

