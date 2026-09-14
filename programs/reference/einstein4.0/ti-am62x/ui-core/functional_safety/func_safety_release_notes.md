# FUNCTIONAL_SAFETY RELEASE VERSION: rel-20251205-2.1.0

## Introduction

Functional Safety contains the below components

Signature CDD: SigCDD is a Complex Device Driver designed for the Signature Unit, developed to meet ASIL B compliance requirements. It ensures the correctness of display output by computing signature values for each safety window and comparing them against reference values.

Signature Unit Driver: Used for verifying safety-critical parts of the graphical output to meet ASIL / ISO26262 compliance.  It enables monitoring the content signature of up to eight evaluation windows by utilizing hardware Signature Unit of Cypress Traveo series SoCs. Error notification will be triggered to the application whenever a checksum mismatch is detected, and when a graphical element is not shown correctly as expected within a defined time.  Most importantly this driver can be used in Kepler2 irrespective of any graphics tool chains.

For more details please refer, <https://uxcoc.visteon.com/docs/#/GDT/functional_safety>

## Changes in this release

    - New Features 
        - None    
    - Defect Fixes
        - BMIC29130-38031: [HMI SIGCDD] Analyze and fix compiler & klocwork warnings
    - Enhancements/Improvements
        - None

## Folder Structure

| Component |Description|
|:-------:|:----------------------------:|
|sigcdd| Signature CDD|
|sigunit_driver_tv1| Signature Unit driver for Traveo1|
|sigunit_driver_tv2| Signature Unit driver for Traveo2|

## Testing performed

- SigCDD component is tested in BMW MIC and Hyundai 4.2" program.
- Signature Unit Driver component is tested in TATAGEN2 h/w and 2WPLT-CDC program.

## Integration Requirements

### Infineon Traveo2 Platform

- GFX_USE_INFINEON_DRIVER should be defined to use the SigUnit driver from infineon

- User should configure the below interrupt for integrating Traveo2 Sig unit

        Interrupt Handler - CyFssig_Display_Isr_Cat2
        Interrupt Vector  - 155

- Traveo2 Infineon variant uses SigUnit driver from the below git repo https://bsp-os.git.visteon.com/platform/bsp-os/turing/mcal/traveo2FsSigDrv. This shuold integrated in the application

### TI Sitara Platform

- Refer integration document in the following path - functional_safety\sigcdd\ui.core.sigcdd.doc\integration\sigcdd_tidss_integration.docx

## Known Limitation

### Infineon Traveo2 Platform

Lock and Unlock APIs are not supported in Traveo2. This support has been requested to platform team. Platform team needs to analyze MPU and PPU to provide this support.

There is no reference manual(HW_Manual_Iris-MGP_v2.01) provided for Traveo2 Signature unit from Infineon. We referred the traveo2 graphics header files and identified the signature unit register address. With the register address changes, we have tested and it’s working as in Traveo1.
