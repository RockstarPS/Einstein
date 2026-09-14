# Signature CDD Release UI-CORE-FUNC-SAFETY-SIGCDD-1.1 (21-June-2018)

## Introduction

Complex Device Driver for Signature unit to satisfy the ASIL B  compliance. In order to control the correctness of display output, signature values can be computed for each frame and compared against reference values.

## Changes in this release

- 1135883: SigCDD: P13A Observations need to be fix
- 1071724: Create Design Proposal for SigCdd component - sbs file added
- 1097877: Sigcdd: Signature unit CDD misra analysis - MISRA warning fixes
- 1094601: UTP: Signature unit CDD Implementation - SigCDD_vcast_UT

## Testing performed

- Signature Unit Driver files for various projects analyzed and results mentioned below:

| Program  |            Reports            |       Results      |
|:-------: |:----------------------------: |:------------------:|
|   P13A   | Compiler, Coverity and MISRA  | [P13B Build Results](http://vfile.visteon.com/livelink/livelink.exe?func=ll&objId=27856445&objAction=browse&viewType=1)  |

## Integration Requirements

1. All below RTE interfaces need to configure  in < SigCdd_cfg.$h >

/*RTE read Signature unit-0 interface to be configured*/

    # define GET_SIG0_WIN0_CONFIG_INPUT(rte_read_data)        Rte_Read_rpSigData0_sig0_Port0(rte_read_data)
    # define GET_SIG0_WIN1_CONFIG_INPUT(rte_read_data)        Rte_Read_rpSigData0_sig0_Port1(rte_read_data)
    # define GET_SIG0_WIN2_CONFIG_INPUT(rte_read_data)        Rte_Read_rpSigData0_sig0_Port2(rte_read_data)
    # define GET_SIG0_WIN3_CONFIG_INPUT(rte_read_data)        Rte_Read_rpSigData0_sig0_Port3(rte_read_data)
    # define GET_SIG0_WIN4_CONFIG_INPUT(rte_read_data)        Rte_Read_rpSigData0_sig0_Port4(rte_read_data)
    # define GET_SIG0_WIN5_CONFIG_INPUT(rte_read_data)        Rte_Read_rpSigData0_sig0_Port5(rte_read_data)
    # define GET_SIG0_WIN6_CONFIG_INPUT(rte_read_data)        Rte_Read_rpSigData0_sig0_Port6(rte_read_data)
    # define GET_SIG0_WIN7_CONFIG_INPUT(rte_read_data)        Rte_Read_rpSigData0_sig0_Port7(rte_read_data)

/*RTE read Signature unit-1 interface to be configured*/

    # define GET_SIG1_WIN0_CONFIG_INPUT(rte_read_data)        Rte_Read_rpSigData1_sig1_Port0(rte_read_data)
    # define GET_SIG1_WIN1_CONFIG_INPUT(rte_read_data)        Rte_Read_rpSigData1_sig1_Port1(rte_read_data)
    # define GET_SIG1_WIN2_CONFIG_INPUT(rte_read_data)        Rte_Read_rpSigData1_sig1_Port2(rte_read_data)
    # define GET_SIG1_WIN3_CONFIG_INPUT(rte_read_data)        Rte_Read_rpSigData1_sig1_Port3(rte_read_data)
    # define GET_SIG1_WIN4_CONFIG_INPUT(rte_read_data)        Rte_Read_rpSigData1_sig1_Port4(rte_read_data)
    # define GET_SIG1_WIN5_CONFIG_INPUT(rte_read_data)        Rte_Read_rpSigData1_sig1_Port5(rte_read_data)
    # define GET_SIG1_WIN6_CONFIG_INPUT(rte_read_data)        Rte_Read_rpSigData1_sig1_Port6(rte_read_data)
    # define GET_SIG1_WIN7_CONFIG_INPUT(rte_read_data)        Rte_Read_rpSigData1_sig1_Port7(rte_read_data)

/*RTE read number of sig units and windows to be configured*/

    # define GET_SIG_WIN_CONFIG_NUMBER(num_sig_units, num_windows)

/*RTE write Signature unit-0 interface to be configured for writing violation*/

    # define SET_SIG0_WIN_VIOLATION_OUTPUT(rte_write_data)

/*RTE write Signature unit-1 interface to be configured for writing violation*/

    # define SET_SIG1_WIN_VIOLATION_OUTPUT(rte_write_data)

2. Configure all template files with required configurations

   SigCdd_Cfg.$h
  
   SigMgrCdd_Cfg.$h
  
   SigIfCdd_Cfg.$h

## Release History Table (in reverse chronological order)

| Software Release(version label)  | Release Date(DD-MMM-YY) | Release Engineer   |
|:-------------------------------: |:----------------------: |:------------------:|
|ss-UI-CORE-FUNC-SAFETY-1.1        | 21-June-18              | SBOLLAM            |
|ss-UI-CORE-FUNC-SAFETY-1.0        | 14-Apr-18               | SBOLLAM            |
