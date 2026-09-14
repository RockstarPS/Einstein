osdStackCheck   .equ   0x00000001
osdStackUsageMeasurement   .equ   1
osdEnableStackMonitoring   .equ   0

osdSysTimerIrqNumber        .equ    25

osdEnableAssertions   .equ   1

osdDerivative   .equ   3

osdStackCheckPattern   .equ   0xaaaaaaaa
osdNumberOfMPURegions   .equ   0x00000010
osdMPURegionFirstUsed   .equ   0x00000000
osdMPURegionLastUsed   .equ   0x00000009

osdErrorHook   .equ   1

osdPreTaskHook   .equ   1

osdPostTaskHook   .equ   1

osdShutdownHook   .equ   1

STATUS_LEVEL   .equ   1

osdFPUSupport   .equ   1

osdFullPreempt   .equ   0

osdMixedPreempt   .equ   1

osdNeedCI707_00026_Workaround   .equ   0

osdNeedCI707_00027_Workaround   .equ   0

osdNonPreempt   .equ   0

osdNumberOfApplMPURegions   .equ   1

osdNumberOfGlobalMPURegions   .equ   7

osdNumberOfInternalResources   .equ   0

osdReducedStatusChecks   .equ   0

osdRegionIndexForStackWindow   .equ   5

osdSC   .equ   1

osdSystemApplIDCore0   .equ   1

osdORTIDebug   .equ   0x00000001
osdORTIStdVersion   .equ   0x000000dc
osdORTIEnabled   .equ   0x00000001
osdNumberOfAllTasks   .equ   0x00000011
; Resources





; Counter



; Schedule Tables

; Applications

; file: tcb.inc
; Implementation: imx8 CortexM4
; Version of general code: 6.20.01

osdVrmMajRelGenNum   .equ   6
osdVrmMinRelGenNum   .equ   0


; END OF tcb.inc

