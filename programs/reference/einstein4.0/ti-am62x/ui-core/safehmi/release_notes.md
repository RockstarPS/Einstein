# Safe HMI

## Version (1.2.2) (24-May-2022)

* 1624709: HD: VSM Update for HD Fusa driver
* 1656369: HD: SafeHMI unity plugin to be update the with Qualcomm SoC

## Version (1.2.1) (18-Apr-2022)

* 1615579: Build VSM, safeHMI library in QNX710

### Note: VSM with QNX 710 is not tested due to OSBSP dependency. Only safeHMI is tested with QNX 710 environment

## Version (1.2.0) (14-Mar-2022)

* 1530977: VSM Update to set the window id for the given asset(VSM APIs are changed as per the change in Signauture unit driver API)
* 1599104: S2.8: VSM sample application
* 1477776: SafeHMI unity plugin update to support Group CRC
* 1477777: SafeHMI unity plugin update to support background for transparent images

## Version (1.1.0) (10-Feb-2022)

* Unity plugin updated to support crc generation for images having transprency.

## Version (1.0.1) (20-Sep-2021)

* VSM module updated to match with OS/BSP signature unit driver API's(RTC ID: 1319794: VSM update for removing display id in all the API's)
* Display configuration update in SafeHMI Unity exporter plugin. Number of displays set to 1 always.
* Fixed refresh issue with OpenGL rendering

## Version (1.0.0)

* Misra warning fixes RTC Story #1075480

  * RTC Task #1083440
  * RTC task #1083441

* Windows simulation fixes

## Version (Beta)

### New Features

* Safe HMI Engine - Provides rendering support for the below elements
  * 2D Canvas
  * 2D Images
  * 2D Rectangle
  * QNX700 with CPU Rendering, Windows 64bit

* Visteon Safety Monitor - Provides an ISO 26262 ASIL A and ASIL B certifiable API's to enable/disable safety monitoring for graphics assets.

* Unity Exporter - To design the safe hmi layout

### Issues Fixed

* None, Initial release

### Known Limitations

* CPU rendering does not support blending. Application needs to take care during design
