/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Adc_PBTypes.h                                               */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2012-2017 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains the type definitions of Post-build Time Parameters      */
/*                                                                            */
/*============================================================================*/
/*                                                                            */
/* Unless otherwise agreed upon in writing between your company and           */
/* Renesas Electronics Corporation the following shall apply!                 */
/*                                                                            */
/* Warranty Disclaimer                                                        */
/*                                                                            */
/* There is no warranty of any kind whatsoever granted by Renesas. Any        */
/* warranty is expressly disclaimed and excluded by Renesas, either expressed */
/* or implied, including but not limited to those for non-infringement of     */
/* intellectual property, merchantability and/or fitness for the particular   */
/* purpose.                                                                   */
/*                                                                            */
/* Renesas shall not have any obligation to maintain, service or provide bug  */
/* fixes for the supplied Product(s) and/or the Application.                  */
/*                                                                            */
/* Each User is solely responsible for determining the appropriateness of     */
/* using the Product(s) and assumes all risks associated with its exercise    */
/* of rights under this Agreement, including, but not limited to the risks    */
/* and costs of program errors, compliance with applicable laws, damage to    */
/* or loss of data, programs or equipment, and unavailability or              */
/* interruption of operations.                                                */
/*                                                                            */
/* Limitation of Liability                                                    */
/*                                                                            */
/* In no event shall Renesas be liable to the User for any incidental,        */
/* consequential, indirect, or punitive damage (including but not limited     */
/* to lost profits) regardless of whether such liability is based on breach   */
/* of contract, tort, strict liability, breach of warranties, failure of      */
/* essential purpose or otherwise and even if advised of the possibility of   */
/* such damages. Renesas shall not be liable for any services or products     */
/* provided by third party vendors, developers or consultants identified or   */
/* referred to the User by Renesas in connection with the Product(s) and/or   */
/* the Application.                                                           */
/*                                                                            */
/*============================================================================*/
/* Environment:                                                               */
/*              Devices:        X1x                                           */
/*============================================================================*/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V1.0.0:  28-Aug-2012    : Initial Version
 *
 * V1.0.1:  30-Nov-2012    : As per SCR 043, the naming of CG unit is changed
 *                           to SG unit.
 *
 * V1.1.0:  16-Jan-2013    : As per SCR 064, following changes are made:
 *                           1. usADCAnTHACR is changed to ulADCAnTHACR.
 *                           2. New macros ADC_SET_ASMPMSK, ADC_SET_SMPST,
 *                              ADC_SET_HLDST, ADC_SET_HLDCTE_HLDTE and
 *                              ADC_SET_HLDTE are added to implement
 *                              Track and Hold.
 *                           3. New macros ADC_ENABLE_PWM_DIAG_TRIGG,
 *                              ADC_DISABLE_PWM_DIAG_TRIGG and
 *                              ADC_WFLG_BIT_SET are added to implement
 *                              PWM Diagnostic group.
 *                           4. Structure 'Adc_ConfigRegisters' is updated to
 *                              have PWM Diagnostic related registers.
 *                           5. Structure 'Adc_HwUnitConfigType' is updated to
 *                              have 'ucTrackHoldMask' and 'ucGroupSelectMask'
 *                              elements to support track and hold.
 *                           6. Structure 'Adc_GroupConfigType' is updated to
 *                              have 'ulDelayCount' and 'blExtMuxEnabled'
 *                              elements to support external multiplexer.
 *                           7. New structure 'Adc_PwmDiagGroupConfigType' is
 *                              added to support PWM Diagnostic functionality.
 *                           8. New macro is added to perform the operation on
 *                              SGm unit in ADC.
 *
 * V1.2.0:  08-Mar-2013    : As per SCR 082 for Mantis #8153, following changes
 *                           are made:
 *                           1. ADC_MASK_CHANNEL macro is added.
 *                           2. Adc_GaaChannelToDisableEnable array is added.
 *                           3. In channel group RAM data structure
 *                              'ucNoofChDisabled' element is added.
 *
 * V1.2.1:  15-Apr-2013    : As per SCR 136 for Mantis #8153, following changes
 *                           are made:
 *                           1. Structure 'Adc_PwmDiagGroupConfigType' is
 *                              updated.
 *                           2. New structures 'Adc_PwmDiagIds' and
 *                              'Adc_PwmGroupRamData' are added.
 *                           3. New global array of structures Adc_GstPwmDiagIds
 *                              and Adc_GaaPwmDiagGroupRamData are added.
 *                           4. The IO structure 'Adc_ConfigRegisters' is
 *                              updated.
 *                           5. New macros ADC_DIAG_GRP_DISABLED,
 *                              ADC_PWM_RST_PWSA and ADC_PWM_START_PWSA are
 *                              added.
 *
 * V1.3.0:  28-May-2013    : As per SCR 173 for mantis #11181, following changes
 *                           are made:
 *                           1. New global array 'Adc_GaaResultGroupRamData' is
 *                              added.
 *                           2. New element ucOffset is added in structure
 *                              STag_Adc_PwmDiagIds.
 *
 * V1.3.1:  14-Jun-2013    : As per SCR 182 for mantis #11991 and #11931,
 *                           following changes are made:
 *                           1. New macro 'ADC_PWM_DMA_SETTINGS' is added.
 *                           2. Extern for array 'Adc_GstPwmDiagResultData'
 *                              is added.
 *                           3. New elements 'pPwmDiagResultRam' and
 *                              'ucMaxDiagRunTime' are added to structure
 *                              'Adc_HwUnitConfigType'.
 *                           4. Inclusion of Adc.h is removed.
 *                           5. AUTOSAR specification version information
 *                              Macro's are changed
 *
 * V1.4.0:  05-Jul-2013    : As per CR 211 for RS requirements and mantis
 *                           #12224 following changes are made:
 *                           1. New element 'ddProcessingModeType', is added
 *                              to the structure Adc_HwUnitConfigType.
 *                           2. New macros 'ADC_RESULT_AVAILABLE',
 *                              'ADC_DMA_TRANSFER_COMPLETED' and
 *                              'ADC_DMA_CLR_DTSTC' are added.
 *                           3. Description of structure element
 *                              'ucGroupSettings' is updated.
 *                           4. ADC_ULE_LIMIT_CHK_ERROR macro is replaced with
 *                              ADC_UE_LE_LIMIT_CHK_ERROR
 *                           5. ADC_RANGE_NOT_BETWEEN macro is added.
 *                           6. ADC_INTERRUPT and ADC_POLLING macro are added.
 *
 * V1.4.1:  08-Aug-2013    : As per CR 225, Device name is updated as part of
 *                           merge activity.
 *
 * V1.4.2:  24-Sep-2013    : As per CR 246 for mantis #14218 and #8421,
 *                           following changes are made:
 *                           1. ADC_PWM_DIAGGRP_CH_MASK, ADC_ULE_SFTCR_ENABLE
 *                              and ADC_PWM_RANGE_NOT_BETWEEN macros are added.
 *                           2. SG0, SG1, SG2 are changed to SG1, SG2 and SG3
 *                              respectively.
 *                           3. pAdcResult and pVirChannel is removed from
 *                              structure Adc_HwUnitConfigType.
 *                           4. ucLimitCheckIndex and ucMaxLimitcheck are added
 *                              in structure Adc_HwUnitConfigType.
 *                           5. pGroupNotificationPointer and
 *                              blLimitCheckEnabled are added in structure
 *                              Adc_GroupConfigType.
 *                           6. ddHwTriggerTimer element is removed in
 *                              structure Adc_PwmDiagIds
 *                           7. New element blLimitCheckEnabled are added
 *                              in structure Adc_PwmDiagGroupConfigType.
 *                           8. Adc_GaaHwUnitIndex array is added.
 *
 * V1.4.3:  30-Oct-2013    : As per CR 291 for mantis #16869 and #16870
 *                           following changes are made:
 *                           1. ulAdcResult element is deleted and new element
 *                              ucHwUnitIndex is added in the structure
 *                              STag_Adc_DmaUnitConfig.
 *                           2. New element ulPwmDmaAdcResult is added in the
 *                              structure STag_Adc_HwUnitConfigType.
 *                           3. New element ulDmaAdcResult is added in the
 *                              structure STag_Adc_GroupConfigType.
 *
 * V1.4.4:  20-Nov-2013    : As per CR 323 for mantis #17300, in structure
 *                           STag_AdcConfigRegisters macro
 *                           ADC_ENABLE_DIAGNOSTIC_SUPPORT is added to support
 *                           other devices.
 *
 * V1.5.0:  06-Jan-2014    : As per CR 343 for mantis #17883, #11181, #16525,
 *                           #17957, #10180, #13489, #16720, #16722 and #14050
 *                           following changes are made:
 *                           1. ADC_LIMIT_CHKCLR_ERROR_FLAG macro changes to
 *                              ADC_CLR_ERROR_FLAG
 *                           2. ADC_NO_OF_SG_UNITS, ADC_PWM_REG_MAX_COUNT,
 *                              ADC_PWM_REG_MIN_COUNT, ADC_INTERRUPT_POLLING,
 *                              ADC_CHANNEL_ISR, ADC_PWSAQFL_SET,
 *                              ADC_PWSAQNE_SET and ADC_PWM_TRIGG_SRC_INVALID
 *                              are added for support the new requirements
 *                              and mantis.
 *                           3. ADC_SFTCR_ENABLE macro condition is updated
 *                              to support the error notification functionality.
 *                           4. Adc_ImrAddMaskConfigType structure is deleted.
 *                           5. In Adc_HwUnitConfigType structure pIntErrAddress
 *                              , pImrErrIntAddress, usImrErrMask, ucSgUnitCount
 *                              , ucErrorLimitCheckIndex and blInterruptErr are
 *                              added to support the error check functionality.
 *                           4. Adc_HwSgUnitType and Adc_ChannelLimitConfigType
 *                              structure is added to support new requirements.
 *                           5. ADC_HW0_PROCESSING_MODE and
 *                              ADC_HW1_PROCESSING_MODE changed to
 *                              ADC_FUNCTIONALITY to support the interrupt and
 *                              polling functionality
 *                           6. ucHwSGUnit, ucHwUnit and ucDmaChannelIndex are
 *                              deleted and ucHwUnitIndex and ucSgUnitIndex are
 *                              added in the Adc_GroupConfigType structure.
 *                           7. Adc_PwmDiagRegisters structure is added to get
 *                              the PWM configure register to enable the trigger
 *                              source
 *                           8. Elements pPwmDiagTrgReg and pPwmDiagReTrgReg
 *                              are deleted  and pPwmBaseAddr and
 *                              ucPwmTriggChIndex elements are added to support
 *                              the PWM Diag. functionality
 *                           9. Adc_HwUnitRamData changed to Adc_SgUnitRamData
 *                              to support the new functionality.
 *                           10. Adc_GstSgUnitConfig, Adc_GstSgUnitRamData,
 *                               Adc_SgUnitPriorityQueue and Adc_GaaSgUnitIndex
 *                               are added.
 *                           11. Adc_HwUnitPriorityQueue, Adc_GstHwUnitRamData,
 *                               Adc_GstImrAddMask are deleted.
 *                           12. ADC_PRIORITY_SW is removed throughout the
 *                               file.
 *
 * V1.6.0:  11-Mar-2014    : As per CR 449 and 450 for mantis #19668, # 19206
 *                           following changes are made:
 *                           1. "ADC_SIX", "ADC_TEN", "ADC_TWENTY",
 *                              "ADC_10BIT_MAXVALUE", "ADC_12BIT_MAXVALUE",
 *                              "ADC_10BIT_RESOLUTION", "ADC_10BIT_MASK_VALUE"
 *                              and "ADC_HW_ALL_UNIT_STATUS" macro's are added.
 *                           2. Error Notification Prototype is updated.
 *                           3. "ucLimitCheckIndex" and "ucMaxLimitcheck" are
 *                              moved from "Adc_HwUnitConfigType" structure to
 *                              "Adc_GroupConfigType" structure.
 *                           4. "ucErrorLimitCheckIndex" is removed.
 *                           5. "Adc_ChannelLimitConfigType" is removed.
 *                           6. extern declaration of "Adc_GaaLimitCheckChannel"
 *                              array is removed.
 *                           7. The 'ucPwmDmaChannelIndex' element has been
 *                              added for DMA mode.
 *                           8. Adc_HwUnitConfigType, Adc_GroupConfigType,
 *                              Adc_PwmDiagGroupConfigType and Adc_HwSgUnitType
 *                              structures are updated.
 *
 * V1.7.0:  20-Jan-2014    : As per CR 499 for Mantis #17424,
 *                           1. rh850_Types.h is included for the macro
 *                              declaration of supervisor mode(SV) write enabled
 *                              Registers IMR & ICxxx.
 *                           2. ADC_MUX_GROUP macro is added to
 *                              support the external mux functionality.
 *                           3. ADC_WUF_CLEAR_MASK_VALUE macro is added to check
 *                              the wake up factor register and clearing.
 *                           4. ADC_HW_TRIG_DISABLE is added to support
 *                              the hardware trigger groups in streaming with
 *                              more number of samples than 4.
 *                           5. ADC_MUX_GROUP macro is added to support the end
 *                              conversion for the mux group.
 *                           6. ADC_PWM_RESULT_READ macro is added to set the
 *                              read result in PWM diagnostic functionality.
 *                           7. Element pVirtualChannel is added and element
 *                              ulDiagnosticValue is deleted from the structure
 *                              STag_Adc_HwUnitConfigType.
 *                           8. In structure STag_Adc_GroupConfigType new
 *                              elements AdcSelfDiagMode, ulAdcSelfDiagOpenPin1,
 *                              ulAdcSelfDiagOpenPin2, ulAdcSelfDiagVolLevSel,
 *                              and ulAdcSelfDiagChannelSel is added to support
 *                              the self diagnostic functionality.
 *
 * V1.7.1:  17-Jul-2014    : As per CR 538, ADC_THRESHOLD_MASK_VALUE is updated
 *                           to remove the QAC warning.
 *
 * V1.7.2:  05-Sep-2014    : As per CR 598 for Mantis #22121, following changes
 *                           are done
 *                           1. ADC_THRESHOLD_MASK_VALUE macro value is updated.
 *                           2. Macro ADC_SET_HLDST and ADC_SET_HLDTE are
 *                              deleted.
 *                           3. ADC_CLR_HLDTE is added to support track and hold
 *                              functionality.
 *                           4. ADC_ENABLE_SELF_DIAG is added to support the
 *                              self diag functionality.
 *                           5. blTandHEnable element is added
 *                              Adc_GroupConfigType structure to support the
 *                              track and hold functionality.
 *                           6. MISRA violation messages are updated.
 *
 * V1.7.3:  27-Nov-2014    : As per Mantis #24060 and #25111, the following
 *                           changes are made,
 *                           1. ADC_PWM_DIAGGRP_CH_MASK macro value is updated.
 *                           2. Semicolon is added at the end of critical
 *                              section macros to avoid Static analysis error.
 *                           3. MISRA violation messages are updated.
 * V1.7.4: 20-Feb-2015     : As per Mantis #25449 following change made:
 *                           1. Added switch ,ADC_DMA_TYPE_USED, for
 *                              DMA selection.
 *                           2. Macros in ADC_DMA_TYPE_TWO switch updated.
 *                           3. New registers CMVC,DM00CM registers added.
 *                           4. DTCT,DCST,DTFRRQC registers values updated.
 *                           5. ADC_START_SEC_VAR_NOINIT_DMA_RAM,
 *                              ADC_STOP_SEC_VAR_NOINIT_DMA_RAM sections added
 *                              for DMA RAM mapping.
 *                           6. New registers added for ADC_DMA_TYPE_TWO in
 *                              Adc_DmaAddrRegs structure.
 *                           7. Adc_GstPwmDiagGroupRamData[] moved to section
 *                              NOINIT_DMA_RAM.Also Adc_GstPwmDiagGroupRamData[]
 *                              and  Adc_GstPwmDiagResultData[] removed from
 *                              section CONFIG_DATA_UNSPECIFIED.
 *
 * V1.7.5: 02-Jul-2015     : 1. As per mantis #26569, #26581, #27495, #28258
 *                              following changes are done:
 *                              a) ADC_ADCAPWDDIR_CH_MASK,ADC_SHIFT_16 ,
 *                                 ADC_PWSAPVCR_MASK  are added.
 *                              b) Adc_GaaResultGroupRamData[] and
 *                                 Adc_SgUnitPriorityQueue[] are moved to
 *                                 section NOINIT_DMA_RAM.
 *                           2. As per ticket #26779 ,
 *                              a) ADC_DM00_CM_VALUE macro removed.
 *                           3. As per tickets #24977,#26329,#26330,
 *                              a) The datatypes of union for accessing
 *                                 16 bit and 32 bit registers updated.
 *                                 UChar,LoByte,HiByte updated to DWord,LoWord
 *                                 ,HiWord respectively.
 *                           4. As per mantis #26050,
 *                              a) Misra warning 4:0317 due to pointer to
 *                                 variable declaration  removed by changing
 *                                 void type declaration of pointers to
 *                                 corresponding data type.
 *                              b) Adc_ConfigType structure moved in from
 *                                 Adc_Types.h to rectify Misra warning 4:0317.
 *                              c) Misra warning 4:4397 due to  typecasting
 *                                 rectified.
 *                           5. As per mantis #23802 ucGroupsettings
 *                              description updated.
 *                           6. ADC_TIMEOUT,ADC_NEXT_SG3 macros added for
 *                              ADC_SOFT_STOP conversion.
 *                           7. pDmaGlblCntlRegBase removed for DMA_TYPE_TWO
 *                              registers as per ticket #26779.
 *
 * V1.7.6:  13-Aug-2015    : 1. As per mantis #28091, the macros
 *                              ADC_EIGHTEEN_CYCLES and ADC_TWENTYFOUR_CYCLES
 *                              are added.
 *                           2. As per mantis #28670, added ucProtLength.
 *
 * V1.7.7:  27-Oct-2015    : As part of JIRA ARDAAAB-1929 and ARDAAAB-1930,
 *                           following changes are made.
 *                            1. Added macros ADC_PWSA_ODD_MASK and
 *                               ADC_PWSA_EVEN_MASK
 *                            2. Added macro ADC_PDM_DIAG_RESULT_MASK.
 *                            3. 'ucDmaDoubleBuffer','pPwmDiagDoubleResultRam'
 *                               'Adc_GaaResultGroupRamData[]',
 *                               'Adc_GstPwmDiagDoubleResultData[]' are added.
 *
 * V1.8.0:  28-Jan-2016    : 1. As part of JIRA ARDAAAC-508,declared the
 *                              following registers as "volatile":
 *                              pIntpAddress,pVirtualChannel,pIntErrAddress,
 *                              pImrErrIntAddress,pImrIntpAddress,pAdcResult,
 *                              pVirChannel,pPwmDiagChPtr
 *                           2. As part JIRA ticket ARDAAAC-447, ARDAAAA-525,
 *                              and ARDAAAB-3226, Storage Specifier for
 *                              Configuration Data variables is changed from
 *                              AUTOMATIC to TYPEDEF, since it is allocated in
 *                              ROM.
 *                           3. Copy right information is updated.
 *                           4. As per JIRA ARDAAAC-467,ARDAAAA-543,ARDAAAB-3463
 *                              and ARDAAAC-396
 *                               4.1 Inclusion of Adc_RegWrite.h is added.
 *                               4.2 Added Macro to check Write verify and
 *                                   Ram Mirroring.
 *                               4.3 Ram mirroring registers Structure added for
 *                                   following peripherals ADCA,DMAC,PWGA
 *                                   and PWSA.
 *                               4.4 Global Arrays Of Structures updated for
 *                                   registers
 *                           5. As per JIRA ARDAAAC-453,ARDAAAA-616,ARDAAAB-3417
 *                               5.1 Variable name "Adc_GaaFlexiableChannelTo
 *                                   Group" and "Adc_GaaFlexiableLimitCheck
 *                                   Range"changed to "Adc_GaaFlexibleChannelTo
 *                                   Group and Adc_GaaFlexibleLimitCheckRange"
 *                               5.2 Declaration of variable "Adc_GaaFlexible
 *                                   ChannelToGroup" and "Adc_GaaFlexible
 *                                   LimitCheckRange" moved to
 *                                   ADC_START_SEC_CONFIG_VAR_NOINIT_
 *                                   UNSPECIFIED section.
 *                               5.3 Declaration of array Adc_GaaHwUnitIndex[]
 *                                   and Adc_GaaSgUnitIndex[] moved to
 *                                   ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
 *                                   section.
 *                           6. As part of JIRA ARDAAAC-629, ARDAAAA-671 and
 *                              JIRA ARDAAAB-3432, macro ADC_RANGE_NOT_BETWEEN
 *                              is removed and description of 'usChannelMask'
 *                              is updated.
 *                           7. As part of JIRA ARDAAAC-148, ARDAAAA-110,
 *                                ARDAAAB-1865
 *                                "LucChannel" data type updated as
 *                                "Adc_ChannelType" in the
 *                                "pErrorNotificationPointer".
 *                           8. As per MO comments in JIRA ARDAAAC-610, one
 *                              declaration of Adc_GaaResultGroupRamData[] is
 *                              removed and declaration of
 *                              Adc_GaaFlexibleChannelToGroup[] and
 *                              Adc_GaaFlexibleLimitCheckRange[] is corrected.
 *                           9. MISRA justifications are added.
 *
 * V1.8.1: 25-May-2016    : Following changes are made.
 *                           1.As part of JIRA ARDAAAB-3463,Added precompile
 *                             "ADC_DMA_TYPE_TWO" macro in the 32 bit register
 *                             declaration.
 *                           2.As part of JIRA ARDAAAB-3647,following macro
 *                             type casted for fixing MISRA Warning
 *                             ADC_DTCT_MASK,ADC_DTS_MASK and ADC_DRQCLR_MASK
 *
 * V1.8.2:  02-Sep-2016   : Following changes are made:
 *                          1. As part of JIRA ARDAAAC-675, ARDAAAA-722 and
 *                             ARDAAAB-1921, macro ADC_CLR_ULEC_ERROR_FLAG is
 *                             added.
 *                          2. AUTOSAR release information macros updated to add
 *                             integer literals as per ARDAAAB-3680,ARDAAAA-945,
 *                             ARDAAAC-856.
 *                          3. As per JIRA #ARDAAAC-805, #ARDAAAA-889,
 *                             ARDAAAB-3677, Following changes are made.
 *                             3.1 ADC_START_SEC_VAR_NOINIT_DMA_RAM is removed.
 *                             3.2 ADC_DMA_START_SEC_VAR_NOINIT_32,
 *                                 ADC_DMA_START_SEC_VAR_NOINIT_16,
 *                                 ADC_START_SEC_CONFIG_DATA_32,
 *                                 ADC_START_SEC_CONFIG_DATA_16,
 *                                 ADC_START_SEC_CONFIG_DATA_8,
 *                                 ADC_START_SEC_VAR_NO_INIT_32,
 *                                 ADC_START_SEC_VAR_NO_INIT_16,
 *                                 ADC_START_SEC_VAR_NO_INIT_8 &
 *                                 ADC_START_SEC_VAR_INIT_BOOLEAN are added.
 *                             3.3 ADC_START_SEC_DOUBLE_BUFF_RAM is renamed as
 *                                 ADC_DMA_DB_START_SEC_NOINIT_32 and
 *                                 ADC_START_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED
 *                                 is modified.
 *                             3.4 All variables are taken care for mapping of
 *                                 correct memory sections.
 *                          4. As per ARDAAAB-3739, ARDAAAA-783, ARDAAAC-918,
 *                             ADC_TEN is changed to ADC_SIXTEEN in
 *                             Adc_SetThreshold Api.
 *                          5. As part of JIRA ARDAAAA-1145 and ARDAAAC-1007
 *                             one space is given between if statements.
 *                          6. Traceability to UD IDs and requirements is
 *                             added.
 *                          7. As part of JIRA ARDAAAB-3739, ARDAAAA-783,
 *                             ARDAAAC-918, ADC_10BIT_MASK_VALUE is corrected.
 *                          8. As part of ARDAAAC-724, ARDAAAA-794, ARDAAAB-3576
 *                             ADC_DEM_TYPE is added.
 * V1.8.3:  07-Feb-2017   : 1. As part of JIRA ARDAABL-709, Traceability to
 *                             requirements and design is added.
 *                          2. Copyright information is updated.
 *                          3. As part of ARDAABL-1180, following changes are
 *                             made:
 *                             1. Unused Macros ADC_ONCE, ADC_CONTINUOUS,
 *                                ADC_LIMIT_CHKCH_NOT_CONFIG,
 *                                ADC_DIAG_GRP_DISABLED, ADC_SET_DIAGOUT_VOLTAGE
 *                                are removed.
 *                             2. Declaration of union type 'UInt' is modified
 *                                and renamed as Adc_DataAccess.
 */
/******************************************************************************/
/* Implements EAAR_PN0034_FR_0001, EAAR_PN0034_NR_0001 */
#ifndef ADC_PBTYPES_H
#define ADC_PBTYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Included for Adc type declarations */
/* Implements ADC267 */
#include "Adc_Types.h"
#include "Adc_RegWrite.h"
/* Implements ADC_ESDD_UD_212 */
#if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON)
/* include the Diagnostic trigger source file */
#include "Pwm_Diagnostic.h"
#endif

/*  Included for the macro declaration of supervisor mode(SV) write enabled
    Registers IMR & ICxxx */
#include "rh850_Types.h"

/*******************************************************************************
**                       MISRA C Rule Violations                              **
*******************************************************************************/
/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3684) Array declared with unknown size.                 */
/* Rule          : MISRA-C:2004 Rule 8.12                                     */
/* Justification : Arrays used are verified in the file which are only        */
/*                 declarations and size is configuration dependent.          */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3684)-1 and                           */
/*                 END Msg(4:3684)-1 tags in the code.                        */
/******************************************************************************/

/* 2. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0750)  A union type specifier has been define           */
/* Rule          : MISRA-C:2004 Rule 18.4                                     */
/* Justification : To access the lower and higher order byte individually and */
/*                 read/write the values to register.                         */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0750)-2 and                           */
/*                 END Msg(4:0750)-2 tags in the code.                        */
/******************************************************************************/
/* 3. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3412) A function could probably be used instead of this */
/*                 function-like macro.                                       */
/* Rule          : MISRA-C:2004 Rule 19.4                                     */
/* Justification : The semi-colon is added at the end of macro to avoid       */
/*                 static analysis warning.                                   */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3412)-3 and                           */
/*                 END Msg(4:3412)-3 tags in the code.                        */
/******************************************************************************/
/* 4. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0857) Number of macro definitions exceeds 1024 -        */
/*                 program does not conform strictly to ISO:C90.              */
/* Rule          : MISRA-C:2004 Rule                                          */
/* Justification : Number of macro definitions exceeds 1024,                  */
/*                 Since these much macros are are required in program        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0857)-4 and                           */
/*                 END Msg(4:0857)-4 tags in the code.                        */
/******************************************************************************/
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* MISRA Violation: START Msg(4:0857)-4 */


#if (ADC_AR_VERSION  == ADC_AR_HIGHER_VERSION)
/* AUTOSAR Release version information */
#define ADC_PBTYPES_AR_RELEASE_MAJOR_VERSION  ADC_TYPES_AR_RELEASE_MAJOR_VERSION
#define ADC_PBTYPES_AR_RELEASE_MINOR_VERSION  ADC_TYPES_AR_RELEASE_MINOR_VERSION
#define ADC_PBTYPES_AR_RELEASE_REVISION_VERSION  \
                                           ADC_TYPES_AR_RELEASE_REVISION_VERSION
#elif (ADC_AR_VERSION  == ADC_AR_LOWER_VERSION)
/* AUTOSAR specification version information */
#define ADC_PBTYPES_AR_MAJOR_VERSION   ADC_TYPES_AR_MAJOR_VERSION
#define ADC_PBTYPES_AR_MINOR_VERSION   ADC_TYPES_AR_MINOR_VERSION
#define ADC_PBTYPES_AR_PATCH_VERSION   ADC_TYPES_AR_PATCH_VERSION
#endif

/* Module Software version information */
#define ADC_PBTYPES_SW_MAJOR_VERSION   ADC_TYPES_SW_MAJOR_VERSION
#define ADC_PBTYPES_SW_MINOR_VERSION   ADC_TYPES_SW_MINOR_VERSION

#define ADC_DBTOC_VALUE  ((ADC_VENDOR_ID_VALUE << 22U) | \
                         (ADC_MODULE_ID_VALUE << 14U) | \
                         (ADC_SW_MAJOR_VERSION_VALUE << 8U) | \
                         (ADC_SW_MINOR_VERSION_VALUE << 3U))

/* Adc Driver initialization status */
#define ADC_UNINITIALIZED                   (boolean)0
#define ADC_INITIALIZED                     (boolean)1

/*
 * Macros to indicate if the function Adc_ImrInterruptBit() should enable or
 * disable the interrupt
 */
 /* Implements ADC_ESDD_UD_185, ADC_ESDD_UD_191 */
#if (ADC_DMA_MODE_ENABLE == STD_ON)

#if (ADC_DMA_TYPE_USED == ADC_DMA_TYPE_TWO)

#define  ADC_CMVC_VALUE                     (uint32)0x33UL
#define  DTCT_REGISTER_VALUE                (uint32)0x04004005UL
#define  DCST_REGISTER_VALUE                (uint32)0xB1UL
#define  DTFRRQC_REGISTER_VALUE             (uint32)0x1UL
#endif

#if (ADC_DMA_TYPE_USED == ADC_DMA_TYPE_ONE)
#define  DTCT_REGISTER_VALUE                (uint16)0x2000
#endif
#define  DMA_INT_CLEAR_VALUE                (uint16)0x000F
#define  DMA_INT_ENABLE_VALUE               (uint16)0x0040
#endif
#define ADC_ENABLE_INTERRUPT                (boolean)0
#define ADC_DISABLE_INTERRUPT               (boolean)1

#define ADC_FALSE                           (boolean)0
#define ADC_TRUE                            (boolean)1
#define ADC_ZERO                            (uint8)0
#define ADC_ONE                             (uint8)1
#define ADC_TWO                             (uint8)2
#define ADC_THREE                           (uint8)3
#define ADC_FOUR                            (uint8)4
#define ADC_FIVE                            (uint8)5
#define ADC_SIX                             (uint8)6
#define ADC_SIXTEEN                         (uint8)0x10
#define ADC_INIT_ZER0                        0U

#define ADC_FOURTY                          (uint8)0x40
#define ADC_TWENTY                          (uint8)0x20
#define ADC_EIGHTEEN_CYCLES                 (uint32)0x00000012UL
#define ADC_TWENTYFOUR_CYCLES               (uint32)0x00000018UL

/* Start/Stop ADC Conversion macros */
#define ADC_START_CONVERSION                (uint32)0x00000001UL
#define ADC_STOP_HW_CONVERSION              (uint32)0x00000001UL
#define ADC_STOP_SG_CONVERSION              (uint32)0x00000001UL
#define ADC_RESULT_FLAG_MASK                (uint8)0x00

/* Limit check Channel is not configured mask */
/* Implements ADC_ESDD_UD_048 */
/* 10-Bit Maximum Value  */
#define ADC_10BIT_MAXVALUE                  (uint16)0x03FF
/* 12-Bit Maximum Value  */
#define ADC_12BIT_MAXVALUE                  (uint16)0x0FFF
/* Macros to that defines 10-Bit Resolution of HW uint */
#define ADC_10BIT_RESOLUTION                (uint32)0x00000010UL
/* Macros to that defines 10-Bit Resolution Mask Value */
#define ADC_10BIT_MASK_VALUE                (uint32)0x00300000UL
/* Macros to that defines Threshold Mask Value */
#define ADC_THRESHOLD_MASK_VALUE            (uint16)0xFF3F
/* Reset PWSAnSTR and PWSAnQUEj mask */
#define ADC_PWM_RST_PWSA                    (uint8)0x00
/* Start PWSA Operation mask */
#define ADC_PWM_START_PWSA                  (uint8)0x01
/* PWM Diag group channel mask */
#define ADC_PWM_DIAGGRP_CH_MASK             (uint16)0x023F

/* Disable Enable Channel mask Macro */
#define ADC_MASK_CHANNEL                    (uint16)0x003F

/* Error in limit check  */
#define ADC_UE_LE_LIMIT_CHK_ERROR           (uint32)0x0000C000UL
/* Clear Error flags */
#define ADC_CLR_ERROR_FLAG                  (uint32)0x0000000CUL
/* Clear ULEC Error flag*/
#define ADC_CLR_ULEC_ERROR_FLAG             (uint32)0x00000008UL
/* To clear the HW trigger selected bits */
#define ADC_CLEAR_TRIGGER_LIST              (uint32)0x00000000UL
/* Macro to set the bit ASMPMSK */
#define ADC_SET_ASMPMSK                     (uint32)0x00000001UL
/* Macro to set the bit SMPST */
#define ADC_SET_SMPST                       (uint32)0x00000001UL
/* Macro to check the bit WFLG */
#define ADC_RESULT_AVAILABLE                (uint32)0x02000000UL
/* Macro to set the bit HLDCTE and HLDTE */
#define ADC_SET_HLDCTE_HLDTE                (uint8)0x30
/* Macro to Reset the bit HLDTE*/
#define ADC_CLR_HLDTE                       (uint32)0xFFFFFFEFUL
/* ADC PWM DIAG RANGE NOT BETWEEN VALUE */
#define ADC_PWM_RANGE_NOT_BETWEEN           (uint16)0x0080

/* Queue status macros */
#define ADC_QUEUE_EMPTY                     (uint8)0
#define ADC_QUEUE_FILLED                    (uint8)1
#define ADC_QUEUE_FULL                      (uint8)2

#if (ADC_DMA_MODE_ENABLE == STD_ON)
/* DMA type */
#if (ADC_DMA_TYPE_USED == ADC_DMA_TYPE_TWO)
/* DMA disable DTE bit */
#define ADC_DMA_DISABLE                     (uint32)0xFFFFFFFEUL
/* DMA enable DTE bit */
#define ADC_DMA_ENABLE                      (uint32)0x00000001UL
#define ADC_DMA_TRANSFER_COMPLETED          (uint32)0x00000010UL
/* Clear the DTSmTC bit mask */
#define ADC_DMA_CLR_DTSTC                   (uint32)0xFFFFFFEFUL
/* Single transfer DMA setting */
#define ADC_DMA_SETTINGS                    (uint32)0x04004004UL
/* To make DMA continuous transfer to single Transfer*/
#define ADC_DMA_ONCE                        (uint32)0xFFFFD9FFUL
/* Setting for PWM Diag */
#define ADC_PWM_DMA_SETTINGS                (uint32)0x04002448UL
/* DMA MLE bit set mask value */
#define ADC_DMA_CONTINUOUS                  (uint32)0x04002605UL
#else
/* DMA disable */
#define ADC_DMA_DISABLE                     (uint8)0x7E
/* DMA enable */
#define ADC_DMA_ENABLE                      (uint8)0x01
/* DMA transfer completed */
#define ADC_DMA_TRANSFER_COMPLETED          (uint8)0x80
/* Clear the DTSmTC bit mask */
#define ADC_DMA_CLR_DTSTC                   (uint8)0x7F
/* DMA setting value */
#define ADC_DMA_SETTINGS                    (uint16)0x2000
/* DMA MLE bit set mask value */
#define ADC_DMA_ONCE                        (uint16)0xEFFF
/* PWM DMA channel setting value */
#define ADC_PWM_DMA_SETTINGS                (uint16)0x5080
/* DMA MLE bit set mask value */
#define ADC_DMA_CONTINUOUS                  (uint16)0x1000
#endif
#endif


/* DMA channel not configured */
#define ADC_NO_DMA_CHANNEL_INDEX            (uint8)0xFF

/* Word Clear mask */
#define ADC_WORD_ZERO                       (uint16)0x0000
/* Double word Clear mask */
#define ADC_DOUBLE_WORD_ZERO                (uint32)0x00000000UL
/**/
#define ADC_TRANSFER_FLAG_CLEAR             (uint32)0x091UL
/* Macro to enable PWM Diagnostic trigger group */
#define ADC_ENABLE_PWM_DIAG_TRIGG           (uint32)0x00000001UL
/* Macro to disable PWM Diagnostic trigger group */
#define ADC_DISABLE_PWM_DIAG_TRIGG          (uint32)0x00000000UL
/* Macro to check WFLG bit */
#define ADC_WFLG_BIT_SET                    (uint32)0x02000000UL
/* Macro to enable reload trigger value */
#define ADC_EN_PWM_DIAG_RELOAD_TRIGG        (uint8)0x01

/* Macro's for Streaming number of samples mask */
#define ADC_DUMMY                           (uint32)0x00000000UL
#define ADC_ONE_TIME_CONVERSION             (uint32)0x00000000UL
#define ADC_TWO_TIME_CONVERSION             (uint32)0x00000001UL
#define ADC_THREE_TIME_CONVERSION           (uint32)0x00000002UL
#define ADC_FOUR_TIME_CONVERSION            (uint32)0x00000003UL

/* Macro to clear the interrupt request flag EIRFn */
#define ADC_CLEAR_INT_REQUEST_FLAG          (uint16)0xEFFF
/* Macro to set the interrupt vector address method to Reference to a table */
#define ADC_SET_TABLE_REF_METHOD            (uint16)0x0040

/* Operation mode enable mask */
#define ADC_SG1_CONV_ONCE                   (uint32)0x00000010UL
#define ADC_SG1_CONV_CONTINUOUS             (uint32)0x00000020UL

/* Macro for INT after SG conversion ends */
#define ADC_INT_SG_END                      (uint32)0x00000010UL

/* ADC SGm unit Macros */
#define ADC_SG1                             (uint8)0x00
#define ADC_SG2                             (uint8)0x01
#define ADC_SG3                             (uint8)0x02
#define ADC_SG4                             (uint8)0x03
#define ADC_NEXT_SG                         (uint8)0x10
#define ADC_NEXT_SG3                        (uint8)0x20
#define ADC_NO_OF_SG_UNITS                  (uint8)0x03
#define ADC_NOT_CONFIGURED                  (uint8)0x00

/* ADC SGm unit conversion status Macros */
#define ADC_SG1_CONV_STATUS_MASK            (uint32)0x00000200UL
#define ADC_SG2_CONV_STATUS_MASK            (uint32)0x00000400UL
#define ADC_SG3_CONV_STATUS_MASK            (uint32)0x00000800UL

/* Macro to Check the HW unit Status */
#define ADC_HW_UNIT_STATUS                  (uint32)0x00000E00UL
/* Macro to Start the HW triggered Group */
#define ADC_SG_HW_TRIGGER                   (uint32)0x00000001UL
/* Macro of PWM Register Maximum Value */
#define ADC_PWM_REG_MAX_COUNT               (uint16)0xFFF
/* Macro of PWM Register Minimum Value */
#define ADC_PWM_REG_MIN_COUNT               (uint16)0x000
/* Macro to Clear ADC Wakeup factors */
#define ADC_WUF_CLEAR_MASK_VALUE            (uint32)0x00000007UL

/* Macros of ADC Result access in a Group */
#define ADC_DMA_ACCESS                      (uint8)0x00
#define ADC_ISR_ACCESS                      (uint8)0x01

/* Macros of ADC Group Conversion Mode */
#define ADC_GROUP_CONV_MASK                 (uint8)0x01
#define ADC_GROUP_CONTINUOUS                (uint8)0x00
#define ADC_GROUP_ONCE                      (uint8)0x01

/* Macros of ADC Group Replacement mask */
#define ADC_GROUP_REPLACEMENT_MASK          (uint8)0x02
#define ADC_GROUP_ABORT_RESTART             (uint8)0x00
#define ADC_GROUP_SUSPEND_RESUME            (uint8)0x02

/* Macros for ADC HW triggered Group in Streaming Mode */
#define ADC_HW_TRIG_DISABLE                 (uint32)0x00000010UL

/* Macro used to enable the self diagnostic functionality  */
#define ADC_ENABLE_SELF_DIAG                (uint32)0x00000080UL

/* Macros of ADC Group Result access Mode */
#define ADC_GROUP_RESULT_ACCESS_MASK        (uint8)0x04
#define ADC_GROUP_DMA_ACCESS                (uint8)0x00

/* Macros of ADC Group Access mode mask */
#define ADC_GROUP_ACCESS_MASK               (uint8)0x08
#define ADC_GROUP_ACCESS_SINGLE             (uint8)0x00
#define ADC_GROUP_ACCESS_STREAMING          (uint8)0x08

/* Macros of ADC processing Mode */
#define ADC_INTERRUPT                       0U
#define ADC_POLLING                         1U
#define ADC_POLLING_INTERRUPT               2U

/* Macro to Fetch the Channel Id */
#define ADC_CHANNEL_ISR                     (uint32)0x0000003FUL
/* Macro to start a HW triggered MUX Group */
#define ADC_MUX_GROUP                       (uint32)0xFFFFFFDFUL
/* Macro to check PWSAnQFL bit */
#define ADC_PWSAQFL_SET                     (uint8)0x02
/* Macro to check PWSAnQNE bit */
#define ADC_PWSAQNE_SET                     (uint8)0x00
/* Macro to check Diag trigger source valid or not */
#define ADC_PWM_TRIGG_SRC_INVALID           (uint16)0x1000
/* Macro to check PWM Diag converted result is already read */
#define ADC_PWM_RESULT_READ               (uint32)0x00800000UL
#define ADC_ADCAPWDDIR_CH_MASK            (uint32)0x0000FFFFUL
#define ADC_SHIFT_16                      (uint8)0x10
#define ADC_PWSA_ODD_MASK                 (uint32)0xFFFF0000UL
#define ADC_PWSA_EVEN_MASK                (uint32)0x0000FFFFUL
#define ADC_PDM_DIAG_RESULT_MASK          (uint32)0x3FFFFFUL

/* Macro to check Write verify/Ram Mirroring */
#if (ADC_DMA_MODE_ENABLE == STD_ON)
/* DMA type */
#if (ADC_DMA_TYPE_USED == ADC_DMA_TYPE_TWO)
#define ADC_DSA_MASK                      0xFFFFFFFFUL
#define ADC_DDA_MASK                      0xFFFFFFFFUL
#define ADC_DTC_MASK                      0xFFFFFFFFUL
#define ADC_DTCT_MASK                     0x0C1F7FFFUL
#define ADC_DRSA_MASK                     0xFFFFFFFFUL
#define ADC_DRDA_MASK                     0xFFFFFFFFUL
#define ADC_DRTC_MASK                     0xFFFFFFFFUL
#define ADC_DCEN_MASK                     0x00000001UL
#define ADC_DTFR_MASK                     (uint16)0x000000FF
#else
#define ADC_DSA_MASK                      0x7FFFFFFUL
#define ADC_DDA_MASK                      0x07FFFFFFUL
#define ADC_DTC_MASK                      0x7FFFU
#define ADC_DTCT_MASK                     (uint16)0x70A0
#define ADC_DTS_MASK                      (uint8)0xC3
#define ADC_DRQCLR_MASK                   (uint16)0xFFFF
#define ADC_DTFR_MASK                     (uint16)0x803F
#endif
#endif
#define ADC_ADCASFTCR_MASK                0x0000001CUL
#define ADC_ADCAADCR_MASK                 0x000000B3UL
#define ADC_ADCASMPCR_MASK                0x000000FFUL
#define ADC_ADCASGMCYCR_MASK              0x00000003UL
#define ADC_ADCAPWDSGCR_MASK              0x00000001UL
#define ADC_PWSACTL_MASK                  0x01U
#define ADC_ADCAVCR_MASK                  (uint16)0x0000f3FF
#define ADC_ADCASGCR_MASK                 0x0000003DUL
#define ADC_ADCADGCTL0_MASK               0x00000007UL
#define ADC_ADCADGCTL1_MASK               0x0000FFFFUL
#define ADC_ADCAPDCTL1_MASK               0x0000FFFFUL
#define ADC_ADCAPDCTL2_MASK               0x000FFFFFUL
#define ADC_ADCATHACR_MASK                0x0000033UL
#define ADC_ADCATHBCR_MASK                0x0000033UL
#define ADC_ADCATHGSR_MASK                0x000003FUL
#define ADC_ADCATHER_MASK                 0x000003FUL
#define ADC_ADCATHCR_MASK                 0x0000001UL
#define ADC_WUF_MASK                      0xFFFFFFFFUL
#define ADC_ADCASGVCSP_MASK               0x0000003FUL
#define ADC_ADCASGVCEP_MASK               0x0000003FUL
#define ADC_ADCAULLMTBR_MASK              0xFFF0FFF0UL
#define ADC_ADCASGTSEL_MASK               0x000001FFUL

#define ADC_32BIT_NO_MASK                  0xFFFFFFFFUL
#define ADC_16BIT_NO_MASK                  (uint16)0xFFFF
#define ADC_8BIT_NO_MASK                   (uint8)0xFF

#define ADC_PWGACTDR_MASK                 0x0FFFU
#define ADC_PWSAPVCRx_y_MASK              0x1FFF1FFFUL


/* Macro to check the SG units not equal to zero */
#define ADC_SG_ZERO                         0U
/* PWSAnPVCR mask to clear the channel setting */
#define ADC_PWSAPVCR_MASK                 (uint16)0xFFFF
/* Implements EAAR_PN0034_FSR_0013 */
/* TIME OUT */
#define ADC_TIMEOUT                       (uint32)0xFFFFUL
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
/* Functionality related to R4.0 */
/* MISRA Violation: START Msg(4:3412)-3 */
#define ADC_ENTER_CRITICAL_SECTION(Exclusive_Area) \
SchM_Enter_Adc_##Exclusive_Area();

#define ADC_EXIT_CRITICAL_SECTION(Exclusive_Area) \
SchM_Exit_Adc_##Exclusive_Area();
/* END Msg(4:3412)-3 */
#elif (ADC_AR_VERSION == ADC_AR_LOWER_VERSION)
/* Functionality related to R3.2 */
/* MISRA Violation: START Msg(4:3412)-3 */
#define ADC_ENTER_CRITICAL_SECTION(Exclusive_Area) \
SchM_Enter_Adc(Exclusive_Area);

#define ADC_EXIT_CRITICAL_SECTION(Exclusive_Area) \
SchM_Exit_Adc(Exclusive_Area);
/* END Msg(4:3412)-3 */
#endif

/*******************************************************************************
*                        DEM TYPE CASTING                                      *
*******************************************************************************/
/* Macros for DEM */
#if (ADC_AR_VERSION == ADC_AR_LOWER_VERSION)
  #define ADC_DEM_TYPE uint8
#else
  #define ADC_DEM_TYPE Dem_EventStatusType
#endif

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
** Union for accessing the 16-bit converted digital values from 32-bit        **
** register. This Union is also used for reading 32-bit address and writing   **
** into two 16-bit registers in case of DMA.                                  **
*******************************************************************************/
/* Implements ADC_ESDD_UD_216 */
/* MISRA Violation: START Msg(4:0750)-2 */
typedef union UTag_Adc_DataAccess
{
  uint32 Value;
  struct
  {
    uint16 LoWord;
    uint16 HiWord;
  } DWord;
} Adc_DataAccess;
/* END Msg(4:0750)-2 */

/*******************************************************************************
** Structure for HW Unit Registers, which are used to read or write           **
** the status or configured values for proper working of the ADC driver       **
*******************************************************************************/
/* Implements ADC_ESDD_UD_107 */
typedef struct STag_AdcConfigRegisters
{
  /* Implements ADC_ESDD_UD_212 */
  #if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON)
  uint32 volatile ulADCAnPWDVCR;
  uint32 volatile ulReserved1[127];
  uint32 volatile ulADCAnPWDDIR;
  uint32 volatile ulReserved2[2];
  #endif
  uint32 volatile ulADCAnADHALTR;
  uint32 volatile ulADCAnADCR;
  uint32 volatile ulADCAnSGSTR;
  uint32 volatile ulADCAnMPXCURR;
  uint32 volatile ulReserved3;
  uint32 volatile ulADCAnTHSMPSTCR;
  uint32 volatile ulADCAnTHCR;
  uint32 volatile ulADCAnTHAHLDSTCR;
  uint32 volatile ulADCAnTHBHLDSTCR;
  uint32 volatile ulADCAnTHACR;
  uint32 volatile ulADCAnTHBCR;
  uint32 volatile ulADCAnTHER;
  uint32 volatile ulADCAnTHGSR;
  uint32 volatile ulADCAnSFTCR;
  uint32 volatile ulADCAnULLMTBRx[3];
  uint32 volatile ulADCAnECR;
  uint32 volatile ulADCAnULER;
  uint32 volatile ulADCAnOWER;
  uint32 volatile ulADCAnDGCTL0;
  uint32 volatile ulADCAnDGCTL1;
  uint32 volatile ulADCAnPDCTL1;
  uint32 volatile ulADCAnPDCTL2;
  uint32 volatile ulReserved4[8];
  uint32 volatile ulADCAnSMPCR;
  uint16 volatile usReserved5[94];
  uint32 volatile ulADCAnSGSTCRx[1];
  uint32 volatile ulReserved6;
  uint32 volatile ulADCAnSGCRx[1];
  uint32 volatile ulADCAnSGVCSPx[1];
  uint32 volatile ulADCAnSGVCEPx[1];
  uint32 volatile ulADCAnSGMCYCRx[1];
  uint32 volatile ulReserved7;
  uint32 volatile ulADCAnSGTSELx[1];
  uint32 volatile ulReserved8[42];
  uint32 volatile ulADCAnPWDSGCR;
  uint32 volatile ulADCAnSGSEFCRx[3];
  uint32 volatile ulADCAnPWDSGSEFCR;
} Adc_ConfigRegisters;
/*******************************************************************************
**                Structure for HW Unit Registers Mirror                      **
*******************************************************************************/
/* Implements ADC_ESDD_UD_147 */
#if (ADC_MIRROR_ENABLE == ADC_ADCA_RAMMIRROR)
typedef struct STag_AdcConfigRegistersMirror
{
  uint32 ulMirrorADCAnADCR;
  uint32 ulMirrorADCAnTHCR;
  uint32 ulMirrorADCAnTHACR;
  uint32 ulMirrorADCAnTHBCR;
  uint32 ulMirrorADCAnTHER;
  uint32 ulMirrorADCAnTHGSR;
  uint32 ulMirrorADCAnULLMTBRx[3];
  uint32 ulMirrorADCAnDGCTL0;
  uint32 ulMirrorADCAnDGCTL1;
  uint32 ulMirrorADCAnPDCTL1;
  uint32 ulMirrorADCAnPDCTL2;
  uint32 ulMirrorADCAnSMPCR;
  uint32 ulMirrorADCAnSGSTCRx[1];
  uint32 ulMirrorADCAnSGCRx[1];
  uint32 ulMirrorADCAnSGVCSPx[1];
  uint32 ulMirrorADCAnSGVCEPx[1];
  uint32 ulADCAnSGMCYCRx[1];
  uint32 ulMirrorADCAnSGTSELx[1];
  uint32 ulADCAnPWDSGCR;
  uint32 ulMirrorVirChannel[50];
} Adc_ConfigRegistersMirror;
#endif

/*******************************************************************************
** Structure for DMAC Registers, which are used to read or write              **
** the status or configured values for proper working of the DMAC             **
*******************************************************************************/
/* Implements ADC_ESDD_UD_185 */
#if (ADC_DMA_MODE_ENABLE == STD_ON)
#if (ADC_DMA_TYPE_USED == ADC_DMA_TYPE_TWO)
/* Implements ADC_ESDD_UD_207 */
typedef struct STag_Adc_DmaAddrRegs
{
  /* Address for source address register */
  uint32 volatile ulDSAn;
  /* Address for lower destination address register */
  uint32 volatile ulDDAn;
  /* Transfer count register */
  uint32 volatile ulDTCn;
  uint32 volatile ulDTCTn;
  /* Transfer control register */
  uint32 volatile ulDRSAn;
  uint32 volatile ulDRDAn;
  uint32 volatile ulDRTCn;
  uint32 volatile Reserved;
  uint32 volatile ulDCENn;
  uint32 volatile ulDCSTn;
  uint32 volatile ulDCSTSn;
  uint32 volatile ulDCSTCn;
  uint32 volatile ulDTFRn;
  uint32 volatile ulDTFRRQn;
  uint32 volatile ulDTFRRQCn;
} Adc_DmaAddrRegs;
#else
typedef struct STag_Adc_DmaAddrRegs
{
  /* Address for source address register */
  uint32 volatile ulDSAn;
  uint16 aaReserved1[6];
  /* Address for lower destination address register */
  uint32 volatile ulDDAn;
  uint16 aaReserved2[5];
 /* Transfer control register, to make DTC naming
       common for F1x variant ul is made common for uint16 and uint 32*/
  uint16 volatile ulDTCn;
  uint16 aaReserved3[2];
/* Transfer control register, to make DTCT naming
       common for F1x variant ul is made common for uint16 and uint 32*/
  uint16 volatile ulDTCTn;
  /* Transfer status register */
  uint8 volatile ucDTSn;
} Adc_DmaAddrRegs;
#endif
#endif
/*******************************************************************************
**                Structure for DMA Registers Mirror                          **
*******************************************************************************/
#if (ADC_MIRROR_ENABLE == ADC_DMAC_RAMMIRROR)
#if (ADC_DMA_MODE_ENABLE == STD_ON)
#if (ADC_DMA_TYPE_USED == ADC_DMA_TYPE_TWO)
/* Implements ADC_ESDD_UD_113, ADC_ESDD_UD_148 */
typedef struct STag_Adc_DmaAddrRegsMirror
{
  uint32 ulMirrorDTCTn;
  /* Transfer control register */
  uint32 ulMirrorDRSAn;
  uint32 ulMirrorDRDAn;
  uint32 ulMirrorDRTCn;
  uint32 ulMirrorDCENn;
  uint32 ulMirrorDTFRn;
} Adc_DmaAddrRegsMirror;
#else
typedef struct STag_Adc_DmaAddrRegsMirror
{
/* Transfer control register, to make DTCT naming
       common for F1x variant ul is made common for uint16 and uint 32*/
  uint16 ulMirrorDTCTn;
  /* Transfer status register */
  uint8 ucMirrorDTSn;
  uint16 usMirrorDRQCLR;
} Adc_DmaAddrRegsMirror;
#endif
#endif
#endif
/*******************************************************************************
** Structure for PWM Diagnostic Registers                                     **
*******************************************************************************/
/* Implements ADC_ESDD_UD_142 */
typedef struct STag_Adc_PwmDiagRegisters
{
  uint16 volatile usPWGAnCSDR;
  uint16 volatile usReserved1;
  uint16 volatile usPWGAnCRDR;
  uint16 volatile usReserved2;
  uint16 volatile usPWGAnCTDR;
  uint16 volatile usReserved3;
  uint8  volatile ucPWGAnRDT;
}Adc_PwmDiagRegisters;
/*******************************************************************************
**                Structure for PWGA Registers Mirror                         **
*******************************************************************************/
/* Implements ADC_ESDD_UD_149 */
#if (ADC_MIRROR_ENABLE == ADC_PWM_DIAG_RAMMIRROR)
typedef struct STag_Adc_PwmDiagRegistersMirror
{
 uint16 usMirrorPWGAnCTDR;
}Adc_PwmDiagRegistersMirror;
#endif
/*******************************************************************************
**                Structure for PWSA Registers Mirror                         **
*******************************************************************************/
/* Implements ADC_ESDD_UD_150 */
#if (ADC_MIRROR_ENABLE == ADC_PWM_DIAG_RAMMIRROR)
typedef struct STag_Adc_PwsaRegistersMirror
{
 uint32 ulMirrorPWSAnPVCRx_y[36];
}Adc_PwsaRegistersMirror;
#endif
/*******************************************************************************
** Structure for DMA channel configuration for SGm unit                       **
*******************************************************************************/
/* Implements ADC_ESDD_UD_185 */
#if (ADC_DMA_MODE_ENABLE == STD_ON)
/* Implements ADC_ESDD_UD_146 */
typedef struct STag_Adc_DmaUnitConfig
{
  /* Address for DMA control registers */
  P2VAR(Adc_DmaAddrRegs, TYPEDEF, ADC_CONFIG_DATA)pDmaCntlRegBase;
  /* Address for Interrupt control registers */
  P2VAR(void, TYPEDEF, ADC_CONFIG_DATA)pIntCntlReg;
  /* Address for DMA IMR control registers */
  P2VAR(void, TYPEDEF, ADC_CONFIG_DATA)pDmaImrIntCntlReg;
  /* Address for DTFR control registers */
  P2VAR(void, TYPEDEF, ADC_CONFIG_DATA)pDmaDTFRRegAddr;
  /* DMA channel Id mask */
  uint16 usDmaChannelMask;
  /* DTFR register value */
  uint16 usDmaDtfrRegValue;
  /* Imr register mask value for the DMA channel */
  uint16 usDmaImrMask;
  #if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON)
  /*
   * Index of the HW unit in the array Adc_GstHWUnitConfig[] to which DMA
   * channel is configured
   */
  uint8 ucHwUnitIndex;
  /* Implements ADC_ESDD_UD_194 */
  #if (ADC_PWM_DIAG_DOUBLE_BUFF == STD_ON)
  uint8 ucDmaDoubleBuffer;
  #endif
  #endif
} Adc_DmaUnitConfig;
#endif
/*******************************************************************************
** Structure for HW Unit configuration                                        **
*******************************************************************************/
/* Implements ADC_ESDD_UD_105 */
typedef struct STag_Adc_HwUnitConfigType
{
  /* Pointer to user base address of ADC Control registers */
  P2VAR(Adc_ConfigRegisters, TYPEDEF, ADC_CONFIG_DATA) pHwUnitBaseAddress;
  /* Pointer to ADC HW unit SG1 interrupt control register */
  P2VAR(volatile uint16, TYPEDEF, ADC_CONFIG_DATA) pIntpAddress;

  /* starting address of virtual channel  */
  P2VAR(volatile uint16, TYPEDEF, ADC_CONFIG_DATA) pVirtualChannel;

  /* Implements ADC_ESDD_UD_175 */
  #if (ADC_ERROR_SUPPORT == STD_ON)
  /* Pointer to Error callback notification */
  /* Implements ADC080 */
  P2FUNC(void, ADC_APPL_CODE, pErrorNotificationPointer)
                                               (Adc_ChannelType LucChannel);
  /* Pointer to ADC HW unit Error interrupt control register */
  P2VAR(volatile uint16, TYPEDEF, ADC_CONFIG_DATA) pIntErrAddress;
  /* Pointer to ADC HW unit Error IMR control register */
  P2VAR(volatile uint16, TYPEDEF, ADC_CONFIG_DATA) pImrErrIntAddress;
  #endif
  /* Implements ADC_ESDD_UD_185 */
  #if ((ADC_DMA_MODE_ENABLE == STD_ON) && \
                                    (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON))
  /* Pointer to RAM of PWM Diagnostic result data */
  P2VAR(void, TYPEDEF, ADC_CONFIG_DATA) pPwmDiagResultRam;
  /* Implements ADC_ESDD_UD_194 */
  #if (ADC_PWM_DIAG_DOUBLE_BUFF == STD_ON)
  /* Pointer to RAM of PWM Diagnostic double result data */
  P2VAR(void, TYPEDEF, ADC_CONFIG_DATA) pPwmDiagDoubleResultRam;
  #endif
  /* Source address for the PWM DMA channel mapped to the HW unit */
  uint32 ulPwmDmaAdcResult;
  #endif
  #if (ADC_ERROR_SUPPORT == STD_ON)
  /* Self-Diagnostic reference voltage setting */
  uint32 ulErrorEnableValue;
  #endif
  /*
   * Bit 7 = 0: Self-diagnostic is enabled
   *       = 1: Self-diagnostic is disabled
   * Bit 5 = 0: Result Data is right aligned
   *       = 1: Result Data is left aligned
   * Bit 4 = 0: 12-bit resolution is configured
   *       = 1: 10-bit resolution is configured
   *
   * Bit [1:0] = 00: Synchronous suspend
   *           = 10: Asynchronous suspend
   */
  uint32 ulHwUnitSettings;
  /*
   * HW Unit sampling time
   * Bit [7:0] = 0x12: ADC_SAMPLING_12H
   *           = 0x18: ADC_SAMPLING_18H
   */
  uint32 ulHwSamplingTime;
  #if (ADC_ERROR_SUPPORT == STD_ON)
  /* ADC HW unit Error IMR mask value */
  uint16 usImrErrMask;
  #if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
  /* ADC limit check SG uint */
  uint8 ucLimitCheckSgUnit;
  #endif
  #endif
  /* Stores the count of number of SG units configured for this HW unit */
  uint8 ucSgUnitCount;
  #if (ADC_TRACK_AND_HOLD == STD_ON)
  /* Track and Hold enabled channel mask */
  uint8 ucTrackHoldMask;
  /* Track and Hold group select mask */
  uint8 ucGroupSelectMask;
  #endif
  #if ((ADC_DMA_MODE_ENABLE == STD_ON) && \
                                    (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON))
  uint16 usMaxDiagRunTime;
  uint8 ucProtLength;
  #endif
  /* total no of channels configured for this HW unit */
  uint8 ucVirChannelCount;
  /* Implements ADC_ESDD_UD_175 */
  #if (ADC_ERROR_SUPPORT == STD_ON)
  /*
   * blInterruptErr = ADC_TRUE, AdcEnableInterruptError = true
   *                = ADC_FALSE, AdcEnableInterruptError = false
   */
  boolean blInterruptErr;
  #endif
} Adc_HwUnitConfigType;
/*******************************************************************************
** Structure for HW Scan Group unit                                           **
*******************************************************************************/
/* Implements ADC_ESDD_UD_116 */
typedef struct STag_Adc_HwSgUnitType
{
  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
      ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                             (ADC_ENABLE_QUEUING == STD_ON)))
  /* Pointer to the Priority Queue */
  P2VAR(Adc_GroupType, TYPEDEF, ADC_CONFIG_DATA) pQueue;
  #endif
  /* IMR address of the corresponding SG unit */
  P2VAR(volatile uint16, TYPEDEF, ADC_CONFIG_DATA) pImrIntpAddress;
  /* Indicates if the SGm unit is configured in interrupt or polling mode */
  /* Implements AR_PN0076_FR_0217 */
  Adc_FunctionalityModeType ddFunctionalityModeType;
  /* Source address for the DMA channel mapped to the group */
  uint32 ulAdcDataRegister;
  /* IMR Mask value */
  uint16 usImrMask;
  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
      ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                             (ADC_ENABLE_QUEUING == STD_ON)))
  /*
   * Maximum Queue Size when software priority or
   * first come first serve mechanism is enabled
   */
  uint8 ucAdcSgQueueSize;
  #endif
   /* SGm unit to which Scan group is configured */
  uint8 ucSgUnitId;
  #if (ADC_DMA_MODE_ENABLE == STD_ON)
  /* Index of the DMA channel Id configured for this SGm in the array
     Adc_GstDmaUnitConfig[] */
  uint8 ucDmaChannelIndex;
  #endif
} Adc_HwSgUnitType;
/*******************************************************************************
** Structure for Group configuration                                          **
*******************************************************************************/
/* Implements ADC_ESDD_UD_106 */
typedef struct STag_Adc_GroupConfigType
{
  #if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
  /* Pointer to callback notification */
  /* Implements ADC_ESDD_UD_145, ADC085 */
  P2FUNC (void, ADC_APPL_CODE, pGroupNotificationPointer)(void);
  #endif
  /* Pointer to base address of 1st ADC Result Register of the Group */
  P2VAR(volatile uint32, TYPEDEF, ADC_CONFIG_DATA) pAdcResult;
  /* Pointer to base address of 1st virtual channel of the Group */
  P2VAR(volatile uint16, TYPEDEF, ADC_CONFIG_DATA) pVirChannel;
  /* Start virtual channel pointer */
  uint32 ulStartVirChPtr;
  #if ((ADC_ENABLE_EXTERNAL_MUX == STD_ON) && \
                             (ADC_FUNCTIONALITY_MODE != ADC_POLLING))
  /* Stabilization delay required while changing external multiplexer lines */
  uint32 ulDelayCount;
  #endif
  /* Number of Samples in Streaming Access Mode */
  /* Implements ADC_ESDD_UD_123 */
  Adc_StreamNumSampleType ddNumberofSamples;
  #if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
  /* Software Priority configured for the group */
  Adc_GroupPriorityType ddGroupPriority;
  #endif

  #if (ADC_SELF_DIAG_SUPPORT == STD_ON)
  /* enum parameter for group to know the group is configured as self
     Diag mode or not */
  Adc_SelfDiagMode AdcSelfDiagMode;
  /* mask value to configured the self diag channel */
  uint32 ulAdcSelfDiagOpenPin1;
  uint32 ulAdcSelfDiagOpenPin2;
  /* mask value to configured the self diag reference voltage */
  uint32 ulAdcSelfDiagVolLevSel;
  uint32 ulAdcSelfDiagChannelSel;
  #endif

  /* Index of the hardware unit to which the group belongs */
  uint8 ucHwUnitIndex;
  /*
   * Index of the SGm unit to which group is configured in the array
   * Adc_GstSgUnitConfig[]
   */
  uint8 ucSgUnitIndex;
  /*
   * Index to the start of the channels configured for this group in the array
   * Adc_GaaChannelToGroup[]
   */
  uint8 ucChannelToGroupIndex;
  /* Implements ADC_ESDD_UD_205 */
  /* Group attributes variable */
  /*
   * Bit 0 = 0 AdcGroupConversionMode configured for Continuous mode
   *         1 AdcGroupConversionMode configured for Oneshot mode
   * Bit 1 = 0 AdcGroupReplacement configured for Abort and Restart
   *         1 AdcGroupReplacement configured for Suspend and Resume
   * Bit 2 = 0 AdcResultAccessMode configured for DMA access
   *         1 AdcResultAccessMode configured for ISR access
   *         1 AdcResultAccessMode configured for Polling access
   * Bit 3 = 0 AdcGroupAccessMode configured for Single Access
   *         1 AdcGroupAccessMode configured for Streaming Access
   * Bit 4 = 0 If channel configured is either limit check disabled or 'enabled
   *           and AdcChannelRangeSelect is not equal to ADC_RANGE_NOT_BETWEEN'.
   *         1 If channel configured is limit check enabled and
   *           AdcChannelRangeSelect is ADC_RANGE_NOT_BETWEEN
   *
   */
  uint8 ucGroupSettings;
  /* Number of channels configured in the group */
  uint8 ucChannelCount;
  #if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
  /*
   * Index to the array Adc_GaaLimitCheckRange[] which will give the limit
   * check enabled channels index of this Group.
   */
  uint8 ucLimitCheckIndex;
  /*
   * Maximum number of Limit check enabled channels in an Group.
   */
  uint8 ucMaxLimitcheck;
  #endif
  #if (ADC_ENABLE_EXTERNAL_MUX == STD_ON)
  /* Flag to indicate if group contains external multiplexed enabled channel */
  boolean blExtMuxEnabled;
  #endif
  #if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
  /* Flag to indicate if group contains Limit check enabled channel */
  boolean blLimitCheckEnabled;
  #endif
  #if (ADC_TRACK_AND_HOLD == STD_ON)
  boolean blTandHEnable;
  #endif
} Adc_GroupConfigType;
/*******************************************************************************
** Structure for PWM Diagnostic Group configuration                           **
*******************************************************************************/
/* Implements ADC_ESDD_UD_141 */
typedef struct STag_Adc_PwmDiagGroupConfigType
{
  /* PWM Diagnostic channel attributes variable */
  /*
   * Bit 15 = 1 if the group is enabled for external multiplex
   *          0 if the group is not enabled for external multiplex
   * Bit 9  = 1 Always fixed value
   * Bit 5-0 = physical channel number configured for this group
   * Other bits should be zero
   */
  uint16 usChannelMask;
  /* Index of the hardware unit to which the group belongs */
  uint8 ucHwUnit;
  /*
   * Index to the start of the channels configured for this group in the array
   * Adc_GaaChannelToGroup[]
   */
  uint8 ucChannelToGroupIndex;
  /*
   * Index to the start of PWM trigger sources configured for this
   * group in the array Adc_GstPwmDiagIds[]
   */
  uint8 ucDiagGroupTriggsIndex;
  /* Number of PWM Trigger source configured in the group */
  uint8 ucPwmTriggCount;
  #if (ADC_DMA_MODE_ENABLE == STD_ON)
  uint8 ucPwmDmaChannelIndex;
  #endif
  #if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
  /*
   * Index to the array Adc_GaaLimitCheckRange[] which will give the limit
   * check enabled channels index of this Group.
   */
  uint8 ucPwmLimitCheckIndex;
  #endif
  #if (ADC_ENABLE_EXTERNAL_MUX == STD_ON)
  /* Number of channels configured in the group */
  uint8 ucChannelCount;
  /* Flag to indicate if group contains external multiplexed enabled channel */
  boolean blExtMuxEnabled;
  #endif
  #if ((ADC_ENABLE_LIMIT_CHECK == STD_ON) && \
       (ADC_DMA_MODE_ENABLE == STD_OFF))
  /* Flag to indicate if group contains Limit check enabled channel */
  boolean blLimitCheckEnabled;
  #endif
} Adc_PwmDiagGroupConfigType;

/*******************************************************************************
** Structure for PWM Diagnostic Group Trigger Source Ids                      **
*******************************************************************************/
/* Implements ADC_ESDD_UD_143 */
typedef struct STag_Adc_PwmDiagIds
{
  /* Pointer to base address of PWM registers   */
  P2VAR(Adc_PwmDiagRegisters, TYPEDEF, ADC_CONFIG_DATA) pPwmBaseAddr;
  /* Pointer to address of PWSAnPVCRm */
  P2VAR(volatile uint32, TYPEDEF, ADC_CONFIG_DATA) pPwmDiagChPtr;
  /*
   * Indicate if trigger is even or odd
   * ucOffset = 0x00 if the trigger is even
   * ucOffset = 0x10 if the trigger is odd
   */
  uint8 ucOffset;
  /*
   * Index for the selected PWM trigger source channel in  array
   * Pwm_GaaChannelCTDRVal[] to which the channel trigger source is configured
   */
  uint8 ucPwmTriggChIndex;
} Adc_PwmDiagIds;

/*******************************************************************************
** Structure for channel group RAM data                                       **
*******************************************************************************/
/* Implements ADC_ESDD_UD_108 */
typedef struct STag_Adc_ChannelGroupRamData
{
  /* ADC Group's Buffer Pointer */
  P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_PUBLIC_CODE) pChannelBuffer;
  /* Stores the conversion status of the requested group */
  Adc_StatusType ddGroupStatus;
  #if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
  /* Stores the Group Notification Status */
  uint8 ucNotifyStatus;
  #endif
  #if ((ADC_ENABLE_BUFFER_ALLOCATION == STD_OFF) && \
                                      (ADC_DEV_ERROR_DETECT == STD_ON))
  /* Stores the buffer pointer initialization Status */
  uint8 ucBufferStatus;
  #endif
  #if (ADC_HW_TRIGGER_API == STD_ON)
  /* Stores the enable hardware trigger status */
  uint8 ucHwTriggStatus;
  #endif
  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
                        ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                                              (ADC_ENABLE_QUEUING == STD_ON)))
  /*
   * Stores the channel count converted before getting interrupted by
   * higher priority group
   */
  uint8 ucReChannelsCompleted;
  /*
   * Stores the count of conversion rounds completed before
   * getting interrupted by higher priority group
   */
  uint8 ucReSamplesCompleted;
  #endif
  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
      ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                             (ADC_ENABLE_QUEUING == STD_ON)))
  /* Stored the status if the group is present in queue */
  uint8 ucGrpPresent;
  #endif
  #if (ADC_ENABLE_DISABLE_CHANNEL == STD_ON)
  /* Stored the count of number of channel disabled */
  uint8 ucNoofChDisabled;
  #endif
  /* Indicates if the conversion of all the samples are completed */
  boolean blSampleComp;
  /*
   * Indicates if the ADC_COMPLETED status has to be prevented once the
   * Group reaches the status of ADC_STREAM_COMPLETED
   */
  boolean blResultRead;
} Adc_ChannelGroupRamData;

/*******************************************************************************
** Structure for channel group RAM data                                       **
*******************************************************************************/
/* Implements ADC_ESDD_UD_144 */
typedef struct STag_Adc_PwmGroupRamData
{
  /* Stores the Group Notification Status */
  uint8 ucTriggSrcIndex;
  #if (ADC_ENABLE_EXTERNAL_MUX == STD_ON)
  /* Starting channel Index of the group */
  uint8 ucStartChannelIndex;
  #endif
} Adc_PwmGroupRamData;

/*******************************************************************************
** Structure for HW unit RAM data                                             **
*******************************************************************************/
/* Implements ADC_ESDD_UD_109 */
typedef struct STag_Adc_SgUnitRamData
{
  /* Stores Trigger source type of the current conversion group SW/HW */
  Adc_TriggerSourceType ddTrigSource;
  /* Stores the current conversion group */
  Adc_GroupType ddCurrentConvGroup;
  /* Stores the current conversion group priority */
  Adc_GroupPriorityType ddCurrentPriority;
  #if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
      ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                             (ADC_ENABLE_QUEUING == STD_ON)))
  /* Stores the queue status */
  uint8 ucQueueStatus;
  /* Stores the queue counter */
  uint8 ucQueueCounter;
  #endif
  /* Stores the current status of the SG unit */
  boolean blSgUnitStatus;
} Adc_SgUnitRamData;

/*******************************************************************************
** Structure for run time data                                                **
*******************************************************************************/
/* Implements ADC_ESDD_UD_110 */
typedef struct STag_Adc_RunTimeData
{
  /* ADC Group's Buffer Pointer */
  P2VAR(uint16, TYPEDEF, ADC_CONFIG_DATA) pBuffer;
  /* Stores the count of number of channels in the group */
  uint8 ucChannelCount;
  /* Stores the count of conversion completed channels */
  uint8 ucChannelsCompleted;
  /* Stores the count of streaming samples */
  uint8 ucStreamingSamples;
  /* Stores the count of conversion completed samples */
  uint8 ucSamplesCompleted;
} Adc_RunTimeData;

/*******************************************************************************
**             Extern declarations for Global Arrays Of Structures            **
*******************************************************************************/
/* Implements ADC_ESDD_UD_185 */
#if (ADC_DMA_MODE_ENABLE == STD_ON)
#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
#define ADC_DMA_START_SEC_VAR_NO_INIT_32
#include "MemMap.h"
#else
#define ADC_DMA_START_SEC_VAR_NOINIT_32
#include "MemMap.h"
#endif

/* MISRA Violation: START Msg(4:3684)-1 */
/* RAM Allocation of PWM Group Result data */
extern VAR(uint32, ADC_NOINIT_DATA)
                             Adc_GstPwmDiagResultData[];
/* END Msg(4:3684)-1 */

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
#define ADC_DMA_STOP_SEC_VAR_NO_INIT_32
#include "MemMap.h"
#else
#define ADC_DMA_STOP_SEC_VAR_NOINIT_32
#include "MemMap.h"
#endif
#endif

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
#define ADC_DMA_START_SEC_VAR_NO_INIT_16
#include "MemMap.h"
#else
#define ADC_DMA_START_SEC_VAR_NOINIT_16
#include "MemMap.h"
#endif

#if (ADC_ENABLE_BUFFER_ALLOCATION == STD_ON)
/* RAM Allocation of result data */
/* MISRA Violation: START Msg(4:3684)-1 */
extern VAR(Adc_ValueGroupType, ADC_NOINIT_DATA)
                            Adc_GaaResultGroupRamData[];
/* END Msg(4:3684)-1 */
#endif

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
#define ADC_DMA_STOP_SEC_VAR_NO_INIT_16
#include "MemMap.h"
#else
#define ADC_DMA_STOP_SEC_VAR_NOINIT_16
#include "MemMap.h"
#endif



#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
#define ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"
#else
#define ADC_START_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"
#endif

/* MISRA Violation: START Msg(4:3684)-1 */
/* Declaration for SG Unit Configuration */
extern CONST(Adc_HwSgUnitType, ADC_CONST)
                                        Adc_GstSgUnitConfig[];
/* Declaration for Hardware unit Configuration */
extern CONST(Adc_HwUnitConfigType, ADC_CONST)
                                        Adc_GstHWUnitConfig[];
/* Declaration for Group Configuration */
extern CONST(Adc_GroupConfigType, ADC_CONST)
                                            Adc_GstGroupConfig[];
/* END Msg(4:3684)-1 */
#if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON)
/* MISRA Violation: START Msg(4:3684)-1 */
/* Declaration for PWM Diagnostic Group Configuration */
extern CONST(Adc_PwmDiagGroupConfigType, ADC_CONST)
                            Adc_GstPwmDiagGroupConfig[];
/* Declaration for PWM Diagnostic Group Trigger Source Ids */
extern CONST(Adc_PwmDiagIds, ADC_CONST)
                                    Adc_GstPwmDiagIds[];
/* END Msg(4:3684)-1 */
#endif
#if (ADC_DMA_MODE_ENABLE == STD_ON)
/* MISRA Violation: START Msg(4:3684)-1 */
/* Declaration for DMA Channel Configuration */
extern CONST(Adc_DmaUnitConfig, ADC_CONST)
                                    Adc_GstDmaUnitConfig[];
/* END Msg(4:3684)-1 */
#endif
#if (ADC_PWSA_INT_QFULL_ISR == STD_ON)
/* Pointer to callback notification */
/* MISRA Violation: START Msg(4:3684)-1 */
extern P2FUNC (void, ADC_APPL_CODE, Adc_GpQueueFullNotificationPointer)(void);
/* END Msg(4:3684)-1 */
#endif

#if ( (ADC_ADCA_RAMMIRROR == ADC_MIRROR_ENABLE ) || \
      ((ADC_DMAC_RAMMIRROR == ADC_MIRROR_ENABLE) && \
       (ADC_DMA_TYPE_USED == ADC_DMA_TYPE_TWO)) || \
      (ADC_PWM_DIAG_RAMMIRROR == ADC_MIRROR_ENABLE ))
extern CONSTP2VAR(uint32, TYPEDEF, ADC_CONFIG_DATA)
                                   Adc_GaaReg_32bit_Mirror[ADC_32BIT_SIZE];
extern CONSTP2VAR(uint32, TYPEDEF, ADC_CONFIG_DATA)
                                   Adc_GaaReg_32bit[ADC_32BIT_SIZE];
#endif

#if (((ADC_DMAC_RAMMIRROR == ADC_MIRROR_ENABLE) && \
     (ADC_DMA_TYPE_USED == ADC_DMA_TYPE_ONE)) || \
    (ADC_PWM_DIAG_RAMMIRROR == ADC_MIRROR_ENABLE))
extern CONSTP2VAR(uint16, TYPEDEF, ADC_CONFIG_DATA)
                                   Adc_GaaReg_16bit_Mirror[ADC_16BIT_SIZE];
extern CONSTP2VAR(uint16, TYPEDEF, ADC_CONFIG_DATA)
                                   Adc_GaaReg_16bit[ADC_16BIT_SIZE];
#endif

#if ((ADC_DMAC_RAMMIRROR == ADC_MIRROR_ENABLE) && \
    (ADC_DMA_TYPE_USED == ADC_DMA_TYPE_ONE))
extern CONSTP2VAR(uint8, TYPEDEF, ADC_CONFIG_DATA)
                                  Adc_GaaReg_8bit_Mirror[ADC_8BIT_SIZE];
extern CONSTP2VAR(uint8, TYPEDEF, ADC_CONFIG_DATA)
                                  Adc_GaaReg_8bit[ADC_8BIT_SIZE];
#endif

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
#define ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"
#else
#define ADC_STOP_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"
#endif


#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
#define ADC_START_SEC_CONFIG_DATA_32
#include "MemMap.h"
#else
#define ADC_START_CONFIG_DATA_32
#include "MemMap.h"
#endif

#if (ADC_HW_TRIGGER_API == STD_ON)
/* Declaration for HW Group Configuration */
/* MISRA Violation: START Msg(4:3684)-1 */
extern CONST(uint32, ADC_CONST) Adc_GaaHWGroupTrigg[];
/* END Msg(4:3684)-1 */
#endif
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/* Declaration for limit check enabled channel Configuration */
/* MISRA Violation: START Msg(4:3684)-1 */
extern CONST(uint32, ADC_CONST) Adc_GaaLimitCheckRange[];
/* END Msg(4:3684)-1 */
#endif

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
#define ADC_STOP_SEC_CONFIG_DATA_32
#include "MemMap.h"
#else
#define ADC_STOP_CONFIG_DATA_32
#include "MemMap.h"
#endif


#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
#define ADC_START_SEC_CONFIG_DATA_16
#include "MemMap.h"
#else
#define ADC_START_CONFIG_DATA_16
#include "MemMap.h"
#endif

/* Declaration for Channel to Group Configuration */
/* MISRA Violation: START Msg(4:3684)-1 */
extern CONST(uint16, ADC_CONFIG_CONST)
                                    Adc_GaaChannelToGroup[];
/* END Msg(4:3684)-1 */


#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
#define ADC_STOP_SEC_CONFIG_DATA_16
#include "MemMap.h"
#else
#define ADC_STOP_CONFIG_DATA_16
#include "MemMap.h"
#endif


#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
#define ADC_START_SEC_CONFIG_DATA_8
#include "MemMap.h"
#else
#define ADC_START_CONFIG_DATA_8
#include "MemMap.h"
#endif

#if (ADC_DMA_MODE_ENABLE == STD_ON)
/* MISRA Violation: START Msg(4:3684)-1 */
/* Declaration for DMA Channel to HW unit mapping Configuration */
extern CONST(uint8, ADC_CONFIG_CONST) Adc_GaaHwUnit[];
/* Declaration for DMA Channel to SGm unit mapping Configuration */
extern CONST(uint8, ADC_CONFIG_CONST) Adc_GaaSGUnit[];
/* END Msg(4:3684)-1 */
#endif
/* MISRA Violation: START Msg(4:3684)-1 */
/* Declaration for Hardware Index Mapping array */
extern CONST(uint8, ADC_CONST) Adc_GaaHwUnitIndex[];
/* Declaration for SG Unit Index Mapping array */
extern CONST(uint8, ADC_CONST) Adc_GaaSgUnitIndex[];
/* END Msg(4:3684)-1 */

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
#define ADC_STOP_SEC_CONFIG_DATA_8
#include "MemMap.h"
#else
#define ADC_STOP_CONFIG_DATA_8
#include "MemMap.h"
#endif

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
#define ADC_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"
#else
#define ADC_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"
#endif

/* MISRA Violation: START Msg(4:3684)-1 */
/* RAM Allocation of Group data */
extern VAR(Adc_ChannelGroupRamData, ADC_NOINIT_DATA)
                                        Adc_GstGroupRamData[];
/* RAM Allocation of hardware unit data */
extern VAR(Adc_SgUnitRamData, ADC_NOINIT_DATA)
                                    Adc_GstSgUnitRamData[];
/* RAM Allocation of Group Runtime data */
extern VAR(Adc_RunTimeData, ADC_NOINIT_DATA)
                                        Adc_GstRunTimeData[];
/* END Msg(4:3684)-1 */

/* MISRA Violation: START Msg(4:3684)-1 */
/* RAM Allocation of PWM Group Runtime data */
extern VAR(Adc_PwmGroupRamData, ADC_NOINIT_DATA)
                        Adc_GstPwmDiagGroupRamData[];
/* END Msg(4:3684)-1 */


#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
#define ADC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"
#else
#define ADC_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"
#endif



#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
#define ADC_START_SEC_VAR_NO_INIT_32
#include "MemMap.h"
#else
#define ADC_START_SEC_VAR_NOINIT_32BIT
#include "MemMap.h"
#endif

#if ((ADC_FLEXIBLE_THRESHOLD == STD_ON) && (ADC_ENABLE_LIMIT_CHECK == STD_ON))
/* MISRA Violation: START Msg(4:3684)-1 */
/* Declaration for Limit Check Ranges */
extern VAR(uint32, ADC_NOINIT_DATA)
                Adc_GaaFlexibleLimitCheckRange[];
/* END Msg(4:3684)-1 */
#endif

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
#define ADC_STOP_SEC_VAR_NO_INIT_32
#include "MemMap.h"
#else
#define ADC_STOP_SEC_VAR_NOINIT_32BIT
#include "MemMap.h"
#endif


#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
#define ADC_START_SEC_VAR_NO_INIT_16
#include "MemMap.h"
#else
#define ADC_START_SEC_VAR_NOINIT_16BIT
#include "MemMap.h"
#endif

#if ((ADC_FLEXIBLE_THRESHOLD == STD_ON) && (ADC_ENABLE_LIMIT_CHECK == STD_ON))
/* MISRA Violation: START Msg(4:3684)-1 */
/* Declaration for Channel to Group Configuration */
extern VAR(uint16, ADC_NOINIT_DATA) Adc_GaaFlexibleChannelToGroup[];
/* END Msg(4:3684)-1 */
#endif

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
#define ADC_STOP_SEC_VAR_NO_INIT_16
#include "MemMap.h"
#else
#define ADC_STOP_SEC_VAR_NOINIT_16BIT
#include "MemMap.h"
#endif


#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
#define ADC_START_SEC_VAR_NO_INIT_8
#include "MemMap.h"
#else
#define ADC_START_SEC_VAR_NOINIT_8BIT
#include "MemMap.h"
#endif

#if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) || \
      ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && \
                             (ADC_ENABLE_QUEUING == STD_ON)))
/* Hardware Unit Queue Size */
/* MISRA Violation: START Msg(4:3684)-1 */
extern VAR(Adc_GroupType, ADC_NOINIT_DATA)
                                Adc_SgUnitPriorityQueue[];
/* END Msg(4:3684)-1 */
#endif

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
#define ADC_STOP_SEC_VAR_NO_INIT_8
#include "MemMap.h"
#else
#define ADC_STOP_SEC_VAR_NOINIT_8BIT
#include "MemMap.h"
#endif


#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
#define ADC_START_SEC_VAR_NO_INIT_BOOLEAN
#include "MemMap.h"
#else
#define ADC_START_SEC_VAR_NOINIT_BOOLEAN
#include "MemMap.h"
#endif

#if (ADC_ENABLE_DISABLE_CHANNEL == STD_ON)
/* Declaration for Disable Channel Configuration */
/* MISRA Violation: START Msg(4:3684)-1 */
extern VAR(boolean, ADC_NOINIT_DATA)
                   Adc_GaaChannelToDisableEnable[ADC_CHANNEL_TO_DISABLE_ENABLE];
/* END Msg(4:3684)-1 */
#endif

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
#define ADC_STOP_SEC_VAR_NO_INIT_BOOLEAN
#include "MemMap.h"
#else
#define ADC_STOP_SEC_VAR_NOINIT_BOOLEAN
#include "MemMap.h"
#endif

/* RAM Allocation of PWM Group Result data */

#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
#define ADC_DMA_DB_START_SEC_VAR_NO_INIT_32
#include "MemMap.h"
#else
#define ADC_DMA_DB_START_SEC_VAR_NOINIT_32BIT
#include "MemMap.h"
#endif

#if ((ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON) &&\
     (ADC_PWM_DIAG_DOUBLE_BUFF == STD_ON))

/* MISRA Violation: START Msg(4:3684)-1 */
extern VAR(uint32, ADC_NOINIT_DATA)
                Adc_GstPwmDiagDoubleResultData[ADC_PWMDIAG_DOUBLE_RESULTDATA];
/* END Msg(4:3684)-1 */
#endif


#if (ADC_AR_VERSION == ADC_AR_HIGHER_VERSION)
#define ADC_DMA_DB_STOP_SEC_VAR_NO_INIT_32
#include "MemMap.h"
#else
#define ADC_DMA_DB_STOP_SEC_VAR_NOINIT_32BIT
#include "MemMap.h"
#endif

/* END Msg(4:0857)-4 */
/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* ADC_PBTYPES_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
