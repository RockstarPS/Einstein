# Signature Unit Driver Release UI-CORE-FUNC-SAFETY-DRIVER-1.2 (21-June-2018)

## Introduction

Signature Unit Driver is used for verifying safety-critical parts of the graphical output to meet ASIL / ISO26262 compliance.  It enables monitoring the content signature of up to eight evaluation windows by utilizing hardware Signature Unit of Cypress Traveo series SoCs. Error notification will be triggered to the application whenever a checksum mismatch is detected, and when a graphical element is not shown correctly as expected within a defined time.  Most importantly this driver can be used in Kepler2 irrespective of any graphics tool chains.

For more details please refer,
HW_Manual_Iris-MGP_v1.08.pdf
<https://insight.visteon.com/wiki/index.php?title=Signature_Unit&r=Signature_Unit>

## Changes in this release

- 1061698:   Signature Driver -Design
- 1068003:   Signature unit CDD Implementation
- 1097877:   Sigcdd: Signature unit CDD misra analysis - MISRA fixes

## Testing performed

- Signature Unit Driver files for various projects analyzed and results mentioned below:

| Program  |            Reports            |       Results      |
|:-------: |:----------------------------: |:------------------:|
|   P13A   | Compiler, Coverity and MISRA  | [P13B Build Results](http://vfile.visteon.com/livelink/livelink.exe?func=ll&objId=27856445&objAction=browse&viewType=1)  |

## Release History Table (in reverse chronological order)

| Software Release(version label)  | Release Date(DD-MMM-YY) | Release Engineer   |
|:-------------------------------: |:----------------------: |:------------------:|
|ss-UI-CORE-FUNC-SAFETY-DRIVER-1.2 | 21-June-18              | SBOLLAM            |
|ss-UI-CORE-FUNC-SAFETY-DRIVER-1.1 | 14-Apr-18               | SBOLLAM            |
|ss-UI-CORE-FUNC-SAFETY-DRIVER-1.0 | 22-Feb-18               | ADEVI              |
