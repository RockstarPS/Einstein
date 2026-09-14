# Release Notes {#rel_notes}
## Version 3.0.17
JIRA                | Description
-------------------|--------------------------------------
Baseline Label     | rel-20260529-3.0.17
Date               | 29-05-2026
### New Features and Defects
WI MMC32428-85185 Fixed timer spawning issue in VIP PhySerialAsr during PHY re-init. This resolves UCL timeout issues observed when the UCL link goes down and recovers.
## Version 3.0.16
JIRA                | Description
-------------------|--------------------------------------
Baseline Label     | rel-20251216-3.0.16
Date               | 16-12-2025
### New Features and Defects
* WI SMQB31568-135323 : Added Android and Vlite OS changes on the stack and new UT implementations for Vlite OS, Android OS, and SomeIP Adapter.
## Version 3.0.13
JIRA                | Description
-------------------|--------------------------------------
Baseline Label     | rel-20240823-3.0.13
Date               | 23-08-2024
### New Features and Defects
* WI TASK30896-30491 : Added Serial Android PHY layer-related files, incorporating changes from version 3.0.12 across all IVI programs.
## Version 3.0.12
JIRA                | Description
-------------------|--------------------------------------
Baseline Label     | rel-20240723-3.0.12
Date               | 23-07-2024
### New Features and Defects
* WI AU29610-174239 : Updated UT scripts to achieve 100 % statement coverage. 
## Version 3.0.11
JIRA                | Description
-------------------|--------------------------------------
Baseline Label     | rel-20240422-3.0.11
Date               | 24-04-2024
### New Features and Defects
* WI JLR3C29298-260162 : Mailbox abstraction implementation for the Samsung/SmartCore 3.0 platform.
* UCL scheduler stuck issue resolved for queue-based GIP to VIP messages.
## Version 3.0.10
RTC                | Description
-------------------|--------------------------------------
Baseline Label     | rel-20230718-3.0.10
Date               | 18-07-2023
### New Features and Defects
* WI 2024055 : Float compiler warning fix
* Ucl coverity fixed 
## Version 3.0.9
RTC                | Description
-------------------|--------------------------------------
Baseline Label     | rel-20230313-3.0.9
Date               | 13-03-2023
### New Features and Defects
* WI 1984662 [HD-A99] ucl coverity fix
* WI 1954688 [UCL Stack] Reinit Phy Counter Fix  
* WI 1914296 UCL_UT Update | Send On Init Implementation | ASR System Init Shutdown Changes | UCL Stack 3.0.9
## Version 3.0.8
RTC                | Description
-------------------|--------------------------------------
Baseline Label     | rel-20220809-3.0.8
Date               | 09-08-2022
### New Features and Defects
* 730246: [NISSAN J32V ] : UCL Deadlock fix
* 1731527: [UCL] Ucl Shared Lib Update
* 1697514: [UCL] : UCL Deadlock Defect fix FT
* 1659167: [Ford PDC] - UCL stack deadlock

## Version 3.0.7
RTC                | Description
-------------------|--------------------------------------
Baseline Label     | exp-20220331-3.0.7
Date               | 31-03-2022
### New Features and Defects
* 1588585: [UCL Sci Drv TV2] UCL Stack Sci Drv Bug Fix TV2
* 1517568: Fix UCL crash on shutdown
* 1521436: UCL Support for linux compilation
* 1534294: [JLR RICM] Thread synchronization fix in UCL AL OS abstraction layer
* [Platform] Improve UCL Stack to build on vbuild6	

## Version 3.0.6
RTC                | Description
-------------------|--------------------------------------
Baseline Label     | exp-20211006-3.0.6
Date               | 06-10-2021
### New Features and Defects
* 1421902:[Ford U725]:To design and implement configurable Tx Ack Queue in UCL task
* 1476422: [HondaBEV |NJ32V] : UCL Stack Coverity Fix
* [JLR RICM]: Stream Based UCL rxStatus.status re initializing Update

## Version 3.0.5
RTC                | Description
-------------------|--------------------------------------
Baseline Label     | exp-20210720-3.0.5
Date               | 20-07-2021
### New Features and Defects
* 1305273: [GM T1/ B1]: Root cause Analysis of ACK Missing issue
* 1389449: Uclcrc is invoked instead of Crc module for NVM checksum calculation
* 1408522: [UCL] Release 3.0.5
* 1408526: [UCL] UT Update

## Version 3.0.4
RTC                | Description
-------------------|--------------------------------------
Baseline Label     | exp-20210706-3.0.4
Date               | 06-07-2021
### New Features and Defects
* 1393858: [FORD PDC]: UCL SPI Abstraction changes to make SPI Mode in VIP & Slave Select in GIP Configurable

Note: 	1.Add the new configuartion parameter "spiMode" for SUclALPhySpiASRCfg in vp/UclInstCfg.c.
		2.Add the new configuartion parameter "slaveSelectDfltLevel" for SUclALPhySpiQnxCfg in gp/UclInstCfg.c.

Note: UclGenerator 2.12.5 should be used to generate UCL adapters for UCL stack version 3.0.1 & above

## Version 3.0.3
RTC                | Description
-------------------|--------------------------------------
Baseline Label     | exp-20210618-3.0.3
Date               | 18-06-2021
### New Features and Defects
*1377740: [Ford U725] Integrate UCL Standalone Tool release ss-turing-tools-R20210511-UclGenerator(2.12.5) to UCL Core Package

Note: UclGenerator 2.12.5 should be used to generate UCL adapters for UCL stack version 3.0.1 & above

## Version 3.0.2
RTC                | Description
-------------------|--------------------------------------
Baseline Label     | exp-20210618-3.0.2
Date               | 18-06-2021
### New Features and Defects
* 1374767: [HONDA] compiler warnings fix support & review
* 1374752: [S2DOT8]: UCL Error Notify Update to self destroy UCL process
* 1376573: UCL data types not compatible between VIP and GIP

## Version 3.0.1
RTC                | Description
-------------------|--------------------------------------
Baseline Label     | exp-20210427-3.0.1
Date               | 27-04-2021

### New Features and Defects
1298693: [FORD S2.8 Internal] UCL component improvement learnt from defects

# Release Notes {#rel_notes}

## Version 3.0.0
RTC                | Description
-------------------|--------------------------------------
Baseline Label     | exp-20210216-3.0.0
Date               | 16-02-2021

### New Features and Defects
1235232: [P702 Lx]: Push UCL Configuration generator 2.12.4 to RTC Bookshelf

## Version 3.0.0
RTC                | Description
-------------------|--------------------------------------
Baseline Label     | exp-20210201-3.0.0
Date               | 02-01-2021

### New Features and Defects
1202684: [P702 Lx]: CRC Update in UCL and testing

## Version 3.0.0
RTC                | Description
-------------------|--------------------------------------
Baseline Label     | exp-20210121-3.0.0
Date               | 21-01-2021

### New Features and Defects
1138604: [Honda BEV] InfraComms UCL Stack and CFG MISRA-CPP Defect fix

Note:
Generate the UCL adapters using DI Core tool version v143 (UclGenerator - 1.0.8) while migrating to 
this version of UCL. This version of UCL stack is not backward compatible to older versions of DI Core Tool.

## Version 3.0.0
RTC                | Description
-------------------|--------------------------------------
Baseline Label     | exp-20201223-3.0.0
Date               | 23-12-2020

### New Features and Defects
*1171021: Fix Coverity & MISRACPP High & Medium Warnings and test

## Version 3.0.0
RTC                | Description
-------------------|--------------------------------------
Baseline Label     | exp-20201203-3.0.0
Date               | 03-12-2020

### New Features and Defects
*1131473: [JLR MLA] : UCL Stack Update to support root less mode

## Version 2.5.1
RTC                | Description
-------------------|--------------------------------------
Baseline Label     | exp-20201119-2.5.1
Date               | 19-11-2020

### New Features and Defects
*1117898: "fd queue" callback notification is enabled for stream based UCL 

## Version 2.5.0
RTC                | Description
-------------------|--------------------------------------
Baseline Label     | exp-20201014-2.5.0
Date               | 14-10-2020

### New Features and Defects
*1087611: Build UCl for extended compiler options

## Version 2.4.0
RTC                | Description
-------------------|--------------------------------------
Baseline Label     | exp-20200714-2.4.0
Date               | 14-07-2020

### New Features and Defects
*965363: UCL Dead Thread Issue Fix

## Version 2.3.0
RTC                | Description
-------------------|--------------------------------------
Baseline Label     | rel-20200607-2.3.0
Date               | 07-06-2020

### New Features and Defects
* 909754 : Ucl code generator (jar) updated to fix "On Change" Messages  issues in generated code
* 909841 : Deployment of  "Clock Monotonic" in POSIX Os Abstraction layer.
* 909843 : Functional Test plan Updated for Signal based UCL

## Version 2.2.0
RTC                | Description
-------------------|--------------------------------------
Baseline Label     | rel-20200526-2.2.0
Date               | 26-05-2020

### New Features and Defects
* 1440270  : To Stop Bad  Application from locking the complete buffer pool
* 1440264  : Reset UCL application variables to default state

## Version 2.1.1
RTC                | Description
-------------------|--------------------------------------
Baseline Label     | rel-20200317-2.1.1
Date               | 17-03-2020

### New Features and Defects
* 1422049 : Slave Timeout Updates for GAC bootloader  in  phy SPI QNX abstraction layer

## Version 2.1.0
RTC                | Description
-------------------|--------------------------------------
Baseline Label     | rel-20200123-2.1.0
Date               | 01-23-2020

### New Features and Defects
* 1315894: UCL core package official Release Activity (Include Coverity & MISRA Fixes for ASR, QNX Deployements).
* 1390453: Build Script Update for GHS Coverity Coverity Ruleset 6.0.
* 1390472: Print OS Timer statistics.
* 1390475: Stop the Timers in UCL Shutdown before destroying the associated mutex. 
* 1390477: UCL Process should disconnect from VMF before exiting.
* 1390480: Remove Mutex Protect in theTimer CB.
* 1390481: Print warning Rx Queue msg count reaches Threshold limit.
* 1391382: Set the Message Retry flag if Schedule Queue Write failed in Schedule Notify.
* 1392905: Execute UT for UCL Package.

Note:
	1. UCL design files are modified to support UCL negative return types.Updated UCL Design files shall be located in the path 
	  “infra.comm.ucl\design�?.  Copy them to the program specific folder e.g., “infra.comm.ucl.cfg\XXXX\design\UCL�? and 
	  regenerate UclCfg.c.
	2. The data type of UCL Error Code / Status of all the adapter callbacks are modified from uint8 & sint32. Applications implementing these CB should make appropriately changes.  The List of UCL Error Codes shall be located in the file “rel/XXX/public/ Ucl_Types.h�?.
	   UCL-VMT Tool changes to support negative return types &  few defect fixes are included in this release. Recommended to regenerate the UCL adapters while migrating to this & all future releases.
	3. To successfully build android application make sure to have "android-ndk-r20" & "infra.comm.someip.libraries" 
	   in the root build path (in the same level as infra.comm.ucl.cfg)

## Version 2.0.0_rc4
RTC                | Description
-------------------|--------------------------------------
Baseline Label     | exp-20191107_2.0.0_rc4
Date               | 11-07-2019

### New Features and Defects

* 1384576: Multi Node UCL release
Note:
	1. UCL-VMT Tool changes to support Multi Instance UCL & SomeIP Adapters are included in this release.
	Recommended to regenerate the UCL adapters while migrating to this & all future releases.


## Version 2.0.0_rc3
RTC                | Description
-------------------|--------------------------------------
Baseline Label     | exp-20190802-2.0.0_rc3
Date               | 2-08-2019

### New Features and Defects

* 1356530: "4mS time interval " protection for UclALPhySpiQnx_Impl.c


## Version 2.0.0_rc2
RTC                | Description
-------------------|--------------------------------------
Baseline Label     | exp-20190627-2.0.0_rc2
Date               | 27-06-2019

### New Features and Defects

* 1341613: UCL Configuration Generator Update to support UCL Multi Instance
* 1192357: Create UCL Test Stub for VIP and Test UCL Test Adapters in config 3 
* 1342142: ALPHYSPI Changes for GAC Smart Core
* 1342156: UCL to Send Error Notification on Adapter Send Failures
	
## Version 2.0.0_rc1
RTC                | Description
-------------------|--------------------------------------
Baseline Label     | exp-20190617-2.0.0_rc1
Date               | 17-06-2019

### New Features and Defects

* 1328479: Implement Ucl Ethernet Phy abstraction using sockets
* 1337485: UCL Multi Instance Implementation - Changes to UCL Message header to include Node to Node message transfer
* 1337482: SomeIP adapter development for Ucl
* 1337598: MakeFile Changes to support Android OS & SomeIP
Note:
	1. UCL-VMT Tool changes to support Multi Instance Message Database & SomeIP Adapters are not included in this release
	2. Ucl Configuration Generator to support Multi Instance Deployement generation need to be updated.
	3. This release includes new UCL Message Format. Make sure to integrate both VIP & GIP with this release. 
	  VIP / GIP with any previous versions of UCL will lead to Message Timeouts due to incompatible UCL Message Frames.
	
## Version 1.0.8
RTC                | Description
-------------------|--------------------------------------
Baseline Label     | exp-20190612-1.0.8
Date               | 12-06-2019

### New Features and Defects

* 1335047: SPIQNX abstraction layer for QCOMM is integrated 
* 1335047 : Following fixes for SPI ASR abstraction layer has been updated
            1. Timer task is destroyed during re-initialization 
			2. State machine is resetted on flow control failure

Note: A new Ucl Client with retry mechanism enabled for Rx Queue is integrated in this release.
Regenerate UCL Adapters and build UCL binary.

## Version 1.0.7
RTC                | Description
-------------------|--------------------------------------
Baseline Label     | exp-20190413-1.0.7
Date               | 13-04-2019

### New Features and Defects

* 1310766: Retry mechanism enabled for 'On Change' Messages 
* 1310146: UCL should send an heart beat on peer ready to reduce the UCL start-up time
* 1312776: GM E4 - Few ODI Subscription messages are duplicated and Few are missed 
* 1313017: Integrate UCL Client Tool UclGenerator2.9.1 with UCL 1.0.7 & Validate
Note: A new Ucl Client with retry mechanism enabled for Rx Queue is integrated in this release.
Regenerate UCL Adapters and build UCL binary.

## Version 1.0.6
RTC                | Description
-------------------|--------------------------------------
Baseline Label     | exp-20190314-1.0.6
Date               | 14-03-2019

### New Features and Defects

* 1297469: UCL MU states locked occasionally in JLR MLA
* 1298985: Optimize ALOsPOSIX for graceful Timer Thread Exit
* 1298970: Make the Time Interval between UCL Phy Retries Configurable
* 1299047: UCl Should wait for other VMF clients to start
Note: A new configuration (phyRetryTimeIntervalMs) added to UclDLCfg_0 defined in UclInstCfg

## Version 1.0.5
RTC                | Description
-------------------|--------------------------------------
Baseline Label     | exp-20190213-1.0.5
Date               | 18-01-2019

### New Features and Defects

* 1260519 - UCL Coverity Analysis
* 1171770 - Change UCL Timer CB as static thread in GIP
* 1260520 - Shared Memory configurable in UCL MU Abstraction 
* 1260523 - Protect Ack Queue before Phy write
* 1254971 - Analyze Link UP Not Reported Issue in GM E4
* 1261390 - Update the vector cast script for UCL
* 1262084 - Resolve Cmake dependency between stream based UCL & Signal bases UCL, build and test
* 1269471 - Perform UCL Shutdown on Fatal Error
* 1276464 - ucl_proxy_vmf does not always fully start

### Known Issues and Limitations

* This release is not recommended for stream based UCL.

### Process Compliance

* Compiler Warnings
 * <a href="build_qnx660_armv7\compiler_warnings.txt">QNX660_ARMV7</a>
 * <a href="build_qnx700_armv7\compiler_warnings.txt">QNX700_ARMV7</a>
 * <a href="build_qnx700_aarch64\compiler_warnings.txt">QNX700_AARCH64</a>
 * <a href="build_linux_aarch64\compiler_warnings.txt">LINUX_AARCH64</a>
 * <a href="build_win_x86\compiler_warnings.txt">WIN_X86</a>
 * <a href="build_win_x86_64\compiler_warnings.txt">WIN_X86_64</a>
 * <a href="build_ghs_rh850\compiler_warnings.txt">GHS_RH850</a>
* MISRA
 * <a href="build_qnx660_armv7\misra_html\index.html">QNX660_ARMV7</a>
* Coverity
 * <a href="build_qnx660_armv7\coverity_html\index.html">QNX660_ARMV7</a>
* Polyspace : Not evaluated

## Version 1.0.4

RTC                | Description
-------------------|--------------------------------------
Baseline Label     | exp-20181206-1.0.4
Date               | 6-12-2018

### New Features and Defects

* Patch fix for Mu driver/Imx8
	
### Known Issues and Limitations

* Patch fix for Mu driver/Imx8

### Process Compliance

* Compiler Warnings
 * <a href="build_qnx660_armv7\compiler_warnings.txt">QNX660_ARMV7</a>
 * <a href="build_qnx700_armv7\compiler_warnings.txt">QNX700_ARMV7</a>
 * <a href="build_qnx700_aarch64\compiler_warnings.txt">QNX700_AARCH64</a>
 * <a href="build_linux_aarch64\compiler_warnings.txt">LINUX_AARCH64</a>
 * <a href="build_win_x86\compiler_warnings.txt">WIN_X86</a>
 * <a href="build_win_x86_64\compiler_warnings.txt">WIN_X86_64</a>
 * <a href="build_ghs_rh850\compiler_warnings.txt">GHS_RH850</a>
* MISRA
 * <a href="build_qnx660_armv7\misra_html\index.html">QNX660_ARMV7</a>
* Coverity
 * <a href="build_qnx660_armv7\coverity_html\index.html">QNX660_ARMV7</a>
* Polyspace : Not evaluated

## Version 1.0.3

RTC                | Description
-------------------|--------------------------------------
Baseline Label     | exp-20181205-1.0.3
Date               | 5-12-2018

### New Features and Defects

* Ucl stream based feature is implemented .Following Api's are implemented for stream based Api's 
 
	 ucl_fd_t ucl_open( ucl_ch_t chId, uint16 flags );
	 
	 sint32 ucl_close( ucl_fd_t fd );
	 
	 sint32 ucl_read( ucl_fd_t fd, uint8 *pBuffer, uint32 size ); 
	 
	 sint32 ucl_write( ucl_fd_t fd, uint8 *pBuffer, uint32 size );
	 
	 sint32 ucl_poll( ucl_fd_t fd, uint32 timeout );

	 sint32 ucl_write_ex( ucl_fd_t fd, uint8 reqId, uint8 *pBuffer, uint32 size );

	 sint32 ucl_ioctl( ucl_fd_t fd, uint32 request, void *pData, uint32 size );

* Adapter layers are updated for vlite and Android platforms 
	
### Known Issues and Limitations

* Android platform for ucl is not integrated with cmake.
* Design information specific to stream based Ucl for Vlite /Android platforms need to be updated in release documents.
* User guide for stream based ucl need to be updated.
* Write_Ex() won't support retundant ReqId's on a shared channel for different fd's. 
* Coverity analysis for stream based ucl interfaces were not updated. 

### Process Compliance

* Compiler Warnings
 * <a href="build_qnx660_armv7\compiler_warnings.txt">QNX660_ARMV7</a>
 * <a href="build_qnx700_armv7\compiler_warnings.txt">QNX700_ARMV7</a>
 * <a href="build_qnx700_aarch64\compiler_warnings.txt">QNX700_AARCH64</a>
 * <a href="build_linux_aarch64\compiler_warnings.txt">LINUX_AARCH64</a>
 * <a href="build_win_x86\compiler_warnings.txt">WIN_X86</a>
 * <a href="build_win_x86_64\compiler_warnings.txt">WIN_X86_64</a>
 * <a href="build_ghs_rh850\compiler_warnings.txt">GHS_RH850</a>
* MISRA
 * <a href="build_qnx660_armv7\misra_html\index.html">QNX660_ARMV7</a>
* Coverity
 * <a href="build_qnx660_armv7\coverity_html\index.html">QNX660_ARMV7</a>
* Polyspace : Not evaluated

## Version 1.0.0

RTC                | Description
-------------------|--------------------------------------
Baseline Label     | exp-20181022-1.0.0
Date               | 22-Oct-2018

### New Features and Defects

* 1214199: UCL Queue implementation
* 1221015: Validate the UclClient(0.7.0) & UclGenerator(2.8)
* 1181232: Vlite, Android Updates in Ucl Core Stack

### Known Issues and Limitations
<span style="color:red">*Please review and understand the limitations, issues before integration*</span>
* None

### Process Compliance

* Compiler Warnings
 * <a href="build_qnx660_armv7\compiler_warnings.txt">QNX660_ARMV7</a>
 * <a href="build_qnx700_armv7\compiler_warnings.txt">QNX700_ARMV7</a>
 * <a href="build_qnx700_aarch64\compiler_warnings.txt">QNX700_AARCH64</a>
 * <a href="build_linux_aarch64\compiler_warnings.txt">LINUX_AARCH64</a>
 * <a href="build_win_x86\compiler_warnings.txt">WIN_X86</a>
 * <a href="build_win_x86_64\compiler_warnings.txt">WIN_X86_64</a>
 * <a href="build_ghs_rh850\compiler_warnings.txt">GHS_RH850</a>
* MISRA
 * <a href="build_qnx660_armv7\misra_html\index.html">QNX660_ARMV7</a>
* Coverity
 * <a href="build_qnx660_armv7\coverity_html\index.html">QNX660_ARMV7</a>
* Polyspace : Not evaluated


## Version 0.9.0

RTC                | Description
-------------------|--------------------------------------
Baseline Label     | exp-20180605-0.9.0
Date               | 5-Jun-2018

### New Features and Defects

* 1126622: Ucl stack updated for signal and message based communciation
* 1126622: memcmp feature added in UclALO's

### Known Issues and Limitations
<span style="color:red">*Please review and understand the limitations, issues before integration*</span>
* None

### Process Compliance

* Compiler Warnings
 * <a href="build_qnx660_armv7\compiler_warnings.txt">QNX660_ARMV7</a>
 * <a href="build_qnx700_armv7\compiler_warnings.txt">QNX700_ARMV7</a>
 * <a href="build_qnx700_aarch64\compiler_warnings.txt">QNX700_AARCH64</a>
 * <a href="build_linux_aarch64\compiler_warnings.txt">LINUX_AARCH64</a>
 * <a href="build_win_x86\compiler_warnings.txt">WIN_X86</a>
 * <a href="build_win_x86_64\compiler_warnings.txt">WIN_X86_64</a>
 * <a href="build_ghs_rh850\compiler_warnings.txt">GHS_RH850</a>
* MISRA
 * <a href="build_qnx660_armv7\misra_html\index.html">QNX660_ARMV7</a>
* Coverity
 * <a href="build_qnx660_armv7\coverity_html\index.html">QNX660_ARMV7</a>
* Polyspace : Not evaluated


## Version 0.8.1

RTC                | Description
-------------------|--------------------------------------
Baseline Label     | exp-20180411-0.8.1
Date               | 11-Apr-2018

### New Features and Defects

* 1081568: VMF starts receiving wrong messages
* 1086818: GIP does not remove the component ID from the recevied messages

### Known Issues and Limitations
<span style="color:red">*Please review and understand the limitations, issues before integration*</span>
* 1088109: UclGen_VmfTypes.h does not compile with C code
* 1088118: UCL onChange deployments VMF messages are corrupted

### Process Compliance

* Compiler Warnings
 * <a href="build_qnx660_armv7\compiler_warnings.txt">QNX660_ARMV7</a>
 * <a href="build_qnx700_armv7\compiler_warnings.txt">QNX700_ARMV7</a>
 * <a href="build_qnx700_aarch64\compiler_warnings.txt">QNX700_AARCH64</a>
 * <a href="build_linux_aarch64\compiler_warnings.txt">LINUX_AARCH64</a>
 * <a href="build_win_x86\compiler_warnings.txt">WIN_X86</a>
 * <a href="build_win_x86_64\compiler_warnings.txt">WIN_X86_64</a>
 * <a href="build_ghs_rh850\compiler_warnings.txt">GHS_RH850</a>
* MISRA
 * <a href="build_qnx660_armv7\misra_html\index.html">QNX660_ARMV7</a>
* Coverity
 * <a href="build_qnx660_armv7\coverity_html\index.html">QNX660_ARMV7</a>
* Polyspace : Not evaluated

## Version 0.8.0

RTC                | Description
-------------------|--------------------------------------
Baseline Label     | exp-20180321-0.8.0
Date               | 21-Mar-2018

### New Features and Defects

* Slogger2 Debug Sink support for QNX
* 1081568: VMF starts receiving wrong messages
* 1081588: Missing VMF messages for some UCL deployments
* Undo 1044454 until toolchain fix is available
* AUTOSAR Serial Adapter is configured to use interrupt mode

### Process Compliance

* Compiler Warnings
 * <a href="build_qnx660_armv7\compiler_warnings.txt">QNX660_ARMV7</a>
 * <a href="build_qnx700_armv7\compiler_warnings.txt">QNX700_ARMV7</a>
 * <a href="build_qnx700_aarch64\compiler_warnings.txt">QNX700_AARCH64</a>
 * <a href="build_linux_aarch64\compiler_warnings.txt">LINUX_AARCH64</a>
 * <a href="build_win_x86\compiler_warnings.txt">WIN_X86</a>
 * <a href="build_win_x86_64\compiler_warnings.txt">WIN_X86_64</a>
 * <a href="build_ghs_rh850\compiler_warnings.txt">GHS_RH850</a>
* MISRA
 * <a href="build_qnx660_armv7\misra_html\index.html">QNX660_ARMV7</a>
* Coverity
 * <a href="build_qnx660_armv7\coverity_html\index.html">QNX660_ARMV7</a>
* Polyspace : Not evaluated

## Version 0.7.2

RTC                | Description
-------------------|--------------------------------------
Baseline Label     | exp-20180202-0.7.2
Date               | 2-Feb-2018

### New Features and Defects

* CommonAPI Adapter Support  
* VLite Adapter Support
* 1044454: UCL Dataunit corruption - Insert signal id in the payload for signal based adapters

### Process Compliance

* Compiler Warnings
 * <a href="build_qnx660_armv7\compiler_warnings.txt">QNX660_ARMV7</a>
 * <a href="build_linux_aarch64\compiler_warnings.txt">LINUX_AARCH64</a>
 * <a href="build_win_x86\compiler_warnings.txt">WIN_X86</a>
 * <a href="build_win_x86_64\compiler_warnings.txt">WIN_X86_64</a>
 * <a href="build_ghs_rh850\compiler_warnings.txt">GHS_RH850</a>
* MISRA
 * <a href="build_qnx660_armv7\misra_html\index.html">QNX660_ARMV7</a>
* Coverity
 * <a href="build_qnx660_armv7\coverity_html\index.html">QNX660_ARMV7</a>
* Polyspace : Not evaluated

## Version 0.7.1

RTC                | Description
-------------------|--------------------------------------
Baseline Label     | exp-20180104-0.7.1
Date               | 4-Jan-2018

### New Features and Defects

* In Serial ASR PHY Abstraction, GpioChanged function prototype is modified in header  
* uint64 & sint64 typedefs are moved inside STD_TYPE_H switch

### Process Compliance

* Compiler Warnings
 * <a href="build_qnx660_armv7\compiler_warnings.txt">QNX660_ARMV7</a>
 * <a href="build_linux_aarch64\compiler_warnings.txt">LINUX_AARCH64</a>
 * <a href="build_win_x86\compiler_warnings.txt">WIN_X86</a>
 * <a href="build_win_x86_64\compiler_warnings.txt">WIN_X86_64</a>
 * <a href="build_ghs_rh850\compiler_warnings.txt">GHS_RH850</a>
* MISRA
 * <a href="build_qnx660_armv7\misra_html\index.html">QNX660_ARMV7</a>
* Coverity
 * <a href="build_qnx660_armv7\coverity_html\index.html">QNX660_ARMV7</a>
* Polyspace : Not evaluated

## Version 0.7.0

RTC                | Description
-------------------|--------------------------------------
Baseline Label     | exp-20181228-0.7.0
Date               | 28-Dec-2017

### New Features and Defects

* SerialASR PHY modified to support both Interrupt & DMA Mode
* Moved Application part to a separate component

### Process Compliance

* Compiler Warnings
 * <a href="build_qnx660_armv7\compiler_warnings.txt">QNX660_ARMV7</a>
 * <a href="build_linux_aarch64\compiler_warnings.txt">LINUX_AARCH64</a>
 * <a href="build_win_x86\compiler_warnings.txt">WIN_X86</a>
 * <a href="build_win_x86_64\compiler_warnings.txt">WIN_X86_64</a>
 * <a href="build_ghs_rh850\compiler_warnings.txt">GHS_RH850</a>
* MISRA
 * <a href="build_qnx660_armv7\misra_html\index.html">QNX660_ARMV7</a>
* Coverity
 * <a href="build_qnx660_armv7\coverity_html\index.html">QNX660_ARMV7</a>
* Polyspace : Not evaluated

## Version 0.6.1

RTC                | Description
-------------------|--------------------------------------
Baseline Label     | exp-20171123-0.6.1
Date               | 07-Dec-2017

### New Features and Defects

* Added VMF Padding Offset
* Highline Cf1 Application Updates
* PHY recovery option to recover infinite times

### Process Compliance

* Compiler Warnings
 * <a href="build_qnx660_armv7\compiler_warnings.txt">QNX660_ARMV7</a>
 * <a href="build_linux_aarch64\compiler_warnings.txt">LINUX_AARCH64</a>
 * <a href="build_win_x86\compiler_warnings.txt">WIN_X86</a>
 * <a href="build_win_x86_64\compiler_warnings.txt">WIN_X86_64</a>
 * <a href="build_ghs_rh850\compiler_warnings.txt">GHS_RH850</a>
* MISRA
 * <a href="build_qnx660_armv7\misra_html\index.html">QNX660_ARMV7</a>
* Coverity
 * <a href="build_qnx660_armv7\coverity_html\index.html">QNX660_ARMV7</a>
* Polyspace : Not evaluated

## Version 0.6.0

RTC                | Description
-------------------|--------------------------------------
Baseline Label     | exp-20171123-0.6.0
Date               | 23-Nov-2017

### New Features and Defects

* Ford P702 Support
* Generated Adapter Integration

### Process Compliance

* Compiler Warnings
 * <a href="build_qnx660_armv7\compiler_warnings.txt">QNX660_ARMV7</a>
 * <a href="build_linux_aarch64\compiler_warnings.txt">LINUX_AARCH64</a>
 * <a href="build_win_x86\compiler_warnings.txt">WIN_X86</a>
 * <a href="build_win_x86_64\compiler_warnings.txt">WIN_X86_64</a>
 * <a href="build_ghs_rh850\compiler_warnings.txt">GHS_RH850</a>
* MISRA
 * <a href="build_qnx660_armv7\misra_html\index.html">QNX660_ARMV7</a>
* Coverity
 * <a href="build_qnx660_armv7\coverity_html\index.html">QNX660_ARMV7</a>
* Polyspace : Not evaluated

## Version 0.5.0

RTC                | Description
-------------------|--------------------------------------
Baseline Label     | exp-20171110-0.5.0
Date               | 10-Nov-2017

### New Features and Defects

* RTC# 983734 : ucl_proxy_vmf not compilable under Linux environment, because of wrong include header file
* QNX SPI Master Support
* QNX IMX8 AP  Core MU Support
* QNX IMX8 CM4 Core MU Support

### Process Compliance

* Compiler Warnings
 * <a href="build_qnx660_armv7\compiler_warnings.txt">QNX660_ARMV7</a>
 * <a href="build_linux_aarch64\compiler_warnings.txt">LINUX_AARCH64</a>
 * <a href="build_win_x86\compiler_warnings.txt">WIN_X86</a>
 * <a href="build_win_x86_64\compiler_warnings.txt">WIN_X86_64</a>
 * <a href="build_ghs_rh850\compiler_warnings.txt">GHS_RH850</a>
* MISRA
 * <a href="build_qnx660_armv7\misra_html\index.html">QNX660_ARMV7</a>
* Coverity
 * <a href="build_qnx660_armv7\coverity_html\index.html">QNX660_ARMV7</a>
* Polyspace : Not evaluated

## Version 0.4.0

RTC                | Description
-------------------|--------------------------------------
Baseline Label     | exp-infra-comm-ucl-0.4.0
Date               | 28-09-2017

### New Features and Defects

* QNX SPI Abstraction Layer Design
* Adapter receive signal protoype changes
* Folder re-structuring

### Process Compliance

* Compiler Warnings
 * <a href="build_qnx660_armv7\compiler_warnings.txt">QNX660_ARMV7</a>
 * <a href="build_linux_aarch64\compiler_warnings.txt">LINUX_AARCH64</a>
 * <a href="build_win_x86\compiler_warnings.txt">WIN_X86</a>
 * <a href="build_win_x86_64\compiler_warnings.txt">WIN_X86_64</a>
 * <a href="build_ghs_rh850\compiler_warnings.txt">GHS_RH850</a>
* MISRA
 * <a href="build_qnx660_armv7\misra_html\index.html">QNX660_ARMV7</a>
* Coverity
 * <a href="build_qnx660_armv7\coverity_html\index.html">QNX660_ARMV7</a>
* Polyspace : Not evaluated

## Version 0.3.0

RTC                | Description
-------------------|--------------------------------------
Baseline Label     | exp-infra-comm-ucl-0.3.0
Date               | 8-Sep-2017

### New Features and Defects

* Windows OS Abstration and Serial Port Abstraction
* Build VMF Proxy Application for Windows
* Coverity / MISRA checker support for QNX660_ARMV7
* Dynamic library support for QNX and Linux
* VectorCAST scripts for DL, Scheduler and Router

### Process Compliance

* Compiler Warnings
 * <a href="build_qnx660_armv7\compiler_warnings.txt">QNX660_ARMV7</a>
 * <a href="build_linux_aarch64\compiler_warnings.txt">LINUX_AARCH64</a>
 * <a href="build_win_x86\compiler_warnings.txt">WIN_X86</a>
 * <a href="build_win_x86_64\compiler_warnings.txt">WIN_X86_64</a>
 * <a href="build_ghs_rh850\compiler_warnings.txt">GHS_RH850</a>
* MISRA
 * <a href="build_qnx660_armv7\misra_html\index.html">QNX660_ARMV7</a>
* Coverity
 * <a href="build_qnx660_armv7\coverity_html\index.html">QNX660_ARMV7</a>
* Polyspace : Not evaluated

## Version 0.1.0

Initial code drop for Tata Futuro Integration 

RTC                | Description
-------------------|--------------------------------------
Baseline Label     | exp-infra-comm-ucl-0.1.0
Date               | 4-Aug-2017

### New Features and Defects

* RTC# 923821: Tata Futuro: UCL Initial Delivery

### Restrictions and Known Limitations

* Attaching the debugger to RCarH2 over Ethernet via Multi IDE will impact performance and instability in the communication  
* Attaching the debugger to RH850 over E1 Debugger via Multi IDE will impact performance and instability in the communication
* Integrity SPI driver re-initialization is not supported due to lack of driver APIs

### Process Compliance

* Compiler Warnings : Not evaluated
* MISRA : Not evaluated
* Coverity : Not evaluated
* Polyspace : Not evaluated

### Notes

Please check the documentation for Build, Configuration, API reference and Integration instructions
