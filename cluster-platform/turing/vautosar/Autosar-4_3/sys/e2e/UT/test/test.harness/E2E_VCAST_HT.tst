-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : E2E_VCAST_HT
-- Unit(s) Under Test: E2E E2E_P01 E2E_P02 E2E_P04 E2E_P05 E2E_P06 E2E_P07 E2E_SM E2E_UserProfile
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: E2E

-- Subprogram: E2E_GetVersionInfo

-- Test Case: E2E_GetVersionInfo.001
TEST.UNIT:E2E
TEST.SUBPROGRAM:E2E_GetVersionInfo
TEST.NEW
TEST.NAME:E2E_GetVersionInfo.001
TEST.NOTES:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7396
TEST.END_NOTES:
TEST.VALUE:E2E.E2E_GetVersionInfo.VersionInfo:<<malloc 1>>
TEST.END

-- Test Case: E2E_GetVersionInfo.002
TEST.UNIT:E2E
TEST.SUBPROGRAM:E2E_GetVersionInfo
TEST.NEW
TEST.NAME:E2E_GetVersionInfo.002
TEST.NOTES:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7396
TEST.END_NOTES:
TEST.END

-- Unit: E2E_P01

-- Subprogram: E2E_P01Check

-- Test Case: ComputedCRC==ReceivedCRC
TEST.UNIT:E2E_P01
TEST.SUBPROGRAM:E2E_P01Check
TEST.NEW
TEST.NAME:ComputedCRC==ReceivedCRC
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if ((ConfigPtr != (void *)0 && StatePtr != (void *)0) && DataPtr != (void *)0) ==> TRUE
      (2) if (((StatePtr->LastValidCounter > 14U || StatePtr->MaxDeltaCounter > 14U) || StatePtr->SyncCounter > ConfigPtr->SyncCounterInit) || StatePtr->NoNewOrRepeatedDataCounter > 14U) ==> FALSE
      (3) if (StatePtr->MaxDeltaCounter < 14U) ==> FALSE
      (4) if (0U != StatePtr->NewDataAvailable) ==> TRUE
      (5) if (ConfigPtr->CounterOffset >> 3U == 0U) ==> FALSE
      (6) if (ReceivedCounter <= 14U) ==> FALSE
   Test Case Generation Notes:
      Conflict: A condition in this branch uses an operand that cannot be set (ConfigPtr->CounterOffset >> 3U) in branch 5
      Cannot set ReceivedCounter due to assignment
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7599
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.Crc_CalculateCRC8.return:255
TEST.VALUE:E2E_P01.E2E_P01Check.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P01.E2E_P01Check.ConfigPtr[0].DataIDMode:E2E_P01_DATAID_BOTH
TEST.VALUE:E2E_P01.E2E_P01Check.ConfigPtr[0].CounterOffset:9
TEST.VALUE:E2E_P01.E2E_P01Check.ConfigPtr[0].CRCOffset:0
TEST.VALUE:E2E_P01.E2E_P01Check.ConfigPtr[0].DataID:65535
TEST.VALUE:E2E_P01.E2E_P01Check.ConfigPtr[0].SyncCounterInit:<<MAX>>
TEST.VALUE:E2E_P01.E2E_P01Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P01.E2E_P01Check.StatePtr[0].LastValidCounter:<<MIN>>
TEST.VALUE:E2E_P01.E2E_P01Check.StatePtr[0].MaxDeltaCounter:0
TEST.VALUE:E2E_P01.E2E_P01Check.StatePtr[0].SyncCounter:<<MIN>>
TEST.VALUE:E2E_P01.E2E_P01Check.StatePtr[0].NoNewOrRepeatedDataCounter:<<MIN>>
TEST.VALUE:E2E_P01.E2E_P01Check.StatePtr[0].NewDataAvailable:1
TEST.VALUE:E2E_P01.E2E_P01Check.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_P01.E2E_P01Check.DataPtr[0]:0
TEST.EXPECTED:E2E_P01.E2E_P01Check.return:23
TEST.END

-- Test Case: ConfigPtr==NULL
TEST.UNIT:E2E_P01
TEST.SUBPROGRAM:E2E_P01Check
TEST.NEW
TEST.NAME:ConfigPtr==NULL
TEST.BASIS_PATH:1 of 13
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((ConfigPtr != (void *)0 && StatePtr != (void *)0) && DataPtr != (void *)0) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7599
TEST.END_NOTES:
TEST.VALUE:E2E_P01.E2E_P01Check.ConfigPtr:<<null>>
TEST.VALUE:E2E_P01.E2E_P01Check.StatePtr:<<null>>
TEST.VALUE:E2E_P01.E2E_P01Check.DataPtr:<<malloc 9>>
TEST.VALUE:E2E_P01.E2E_P01Check.DataPtr:<<null>>
TEST.EXPECTED:E2E_P01.E2E_P01Check.return:19
TEST.END

-- Test Case: DATAID_NIBBLE
TEST.UNIT:E2E_P01
TEST.SUBPROGRAM:E2E_P01Check
TEST.NEW
TEST.NAME:DATAID_NIBBLE
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if ((ConfigPtr != (void *)0 && StatePtr != (void *)0) && DataPtr != (void *)0) ==> TRUE
      (2) if (((StatePtr->LastValidCounter > 14U || StatePtr->MaxDeltaCounter > 14U) || StatePtr->SyncCounter > ConfigPtr->SyncCounterInit) || StatePtr->NoNewOrRepeatedDataCounter > 14U) ==> FALSE
      (3) if (StatePtr->MaxDeltaCounter < 14U) ==> FALSE
      (4) if (0U != StatePtr->NewDataAvailable) ==> TRUE
      (5) if (ConfigPtr->CounterOffset >> 3U == 0U) ==> FALSE
      (6) if (ReceivedCounter <= 14U) ==> FALSE
   Test Case Generation Notes:
      Conflict: A condition in this branch uses an operand that cannot be set (ConfigPtr->CounterOffset >> 3U) in branch 5
      Cannot set ReceivedCounter due to assignment
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7599
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.Crc_CalculateCRC8.return:VARY FROM:0 TO:255 BY: 1
TEST.VALUE:E2E_P01.E2E_P01Check.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P01.E2E_P01Check.ConfigPtr[0].DataIDMode:E2E_P01_DATAID_NIBBLE
TEST.VALUE:E2E_P01.E2E_P01Check.ConfigPtr[0].CounterOffset:9
TEST.VALUE:E2E_P01.E2E_P01Check.ConfigPtr[0].DataID:0
TEST.VALUE:E2E_P01.E2E_P01Check.ConfigPtr[0].DataIDNibbleOffset:9
TEST.VALUE:E2E_P01.E2E_P01Check.ConfigPtr[0].DataLength:8
TEST.VALUE:E2E_P01.E2E_P01Check.ConfigPtr[0].SyncCounterInit:<<MAX>>
TEST.VALUE:E2E_P01.E2E_P01Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P01.E2E_P01Check.StatePtr[0].LastValidCounter:<<MIN>>
TEST.VALUE:E2E_P01.E2E_P01Check.StatePtr[0].MaxDeltaCounter:0
TEST.VALUE:E2E_P01.E2E_P01Check.StatePtr[0].SyncCounter:<<MIN>>
TEST.VALUE:E2E_P01.E2E_P01Check.StatePtr[0].NoNewOrRepeatedDataCounter:<<MIN>>
TEST.VALUE:E2E_P01.E2E_P01Check.StatePtr[0].NewDataAvailable:1
TEST.VALUE:E2E_P01.E2E_P01Check.DataPtr:<<malloc 1>>
TEST.EXPECTED:E2E_P01.E2E_P01Check.return:0
TEST.END

-- Test Case: DATAID_NIBBLE_Offset0
TEST.UNIT:E2E_P01
TEST.SUBPROGRAM:E2E_P01Check
TEST.NEW
TEST.NAME:DATAID_NIBBLE_Offset0
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if ((ConfigPtr != (void *)0 && StatePtr != (void *)0) && DataPtr != (void *)0) ==> TRUE
      (2) if (((StatePtr->LastValidCounter > 14U || StatePtr->MaxDeltaCounter > 14U) || StatePtr->SyncCounter > ConfigPtr->SyncCounterInit) || StatePtr->NoNewOrRepeatedDataCounter > 14U) ==> FALSE
      (3) if (StatePtr->MaxDeltaCounter < 14U) ==> FALSE
      (4) if (0U != StatePtr->NewDataAvailable) ==> TRUE
      (5) if (ConfigPtr->CounterOffset >> 3U == 0U) ==> FALSE
      (6) if (ReceivedCounter <= 14U) ==> FALSE
   Test Case Generation Notes:
      Conflict: A condition in this branch uses an operand that cannot be set (ConfigPtr->CounterOffset >> 3U) in branch 5
      Cannot set ReceivedCounter due to assignment
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7599
TEST.END_NOTES:
TEST.VALUE:E2E_P01.E2E_P01Check.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P01.E2E_P01Check.ConfigPtr[0].DataIDMode:E2E_P01_DATAID_NIBBLE
TEST.VALUE:E2E_P01.E2E_P01Check.ConfigPtr[0].CounterOffset:9
TEST.VALUE:E2E_P01.E2E_P01Check.ConfigPtr[0].DataID:65535
TEST.VALUE:E2E_P01.E2E_P01Check.ConfigPtr[0].DataLength:8
TEST.VALUE:E2E_P01.E2E_P01Check.ConfigPtr[0].SyncCounterInit:<<MAX>>
TEST.VALUE:E2E_P01.E2E_P01Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P01.E2E_P01Check.StatePtr[0].LastValidCounter:<<MIN>>
TEST.VALUE:E2E_P01.E2E_P01Check.StatePtr[0].MaxDeltaCounter:0
TEST.VALUE:E2E_P01.E2E_P01Check.StatePtr[0].SyncCounter:<<MIN>>
TEST.VALUE:E2E_P01.E2E_P01Check.StatePtr[0].NoNewOrRepeatedDataCounter:<<MIN>>
TEST.VALUE:E2E_P01.E2E_P01Check.StatePtr[0].NewDataAvailable:1
TEST.VALUE:E2E_P01.E2E_P01Check.DataPtr:<<malloc 1>>
TEST.EXPECTED:E2E_P01.E2E_P01Check.return:0
TEST.END

-- Test Case: DataLengthConditioncheck
TEST.UNIT:E2E_P01
TEST.SUBPROGRAM:E2E_P01Check
TEST.NEW
TEST.NAME:DataLengthConditioncheck
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if ((ConfigPtr != (void *)0 && StatePtr != (void *)0) && DataPtr != (void *)0) ==> TRUE
      (2) if (((StatePtr->LastValidCounter > 14U || StatePtr->MaxDeltaCounter > 14U) || StatePtr->SyncCounter > ConfigPtr->SyncCounterInit) || StatePtr->NoNewOrRepeatedDataCounter > 14U) ==> FALSE
      (3) if (StatePtr->MaxDeltaCounter < 14U) ==> FALSE
      (4) if (0U != StatePtr->NewDataAvailable) ==> TRUE
      (5) if (ConfigPtr->CounterOffset >> 3U == 0U) ==> FALSE
      (6) if (ReceivedCounter <= 14U) ==> FALSE
   Test Case Generation Notes:
      Conflict: A condition in this branch uses an operand that cannot be set (ConfigPtr->CounterOffset >> 3U) in branch 5
      Cannot set ReceivedCounter due to assignment
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7599
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.Crc_CalculateCRC8.return:255
TEST.VALUE:E2E_P01.E2E_P01Check.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P01.E2E_P01Check.ConfigPtr[0].DataIDMode:E2E_P01_DATAID_BOTH
TEST.VALUE:E2E_P01.E2E_P01Check.ConfigPtr[0].CounterOffset:9
TEST.VALUE:E2E_P01.E2E_P01Check.ConfigPtr[0].CRCOffset:0
TEST.VALUE:E2E_P01.E2E_P01Check.ConfigPtr[0].DataID:65535
TEST.VALUE:E2E_P01.E2E_P01Check.ConfigPtr[0].DataLength:8
TEST.VALUE:E2E_P01.E2E_P01Check.ConfigPtr[0].SyncCounterInit:<<MAX>>
TEST.VALUE:E2E_P01.E2E_P01Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P01.E2E_P01Check.StatePtr[0].LastValidCounter:<<MIN>>
TEST.VALUE:E2E_P01.E2E_P01Check.StatePtr[0].MaxDeltaCounter:0
TEST.VALUE:E2E_P01.E2E_P01Check.StatePtr[0].SyncCounter:<<MIN>>
TEST.VALUE:E2E_P01.E2E_P01Check.StatePtr[0].NoNewOrRepeatedDataCounter:<<MIN>>
TEST.VALUE:E2E_P01.E2E_P01Check.StatePtr[0].NewDataAvailable:1
TEST.VALUE:E2E_P01.E2E_P01Check.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_P01.E2E_P01Check.DataPtr[0]:0
TEST.EXPECTED:E2E_P01.E2E_P01Check.return:0
TEST.END

-- Test Case: LastValidCounter<MAX
TEST.UNIT:E2E_P01
TEST.SUBPROGRAM:E2E_P01Check
TEST.NEW
TEST.NAME:LastValidCounter<MAX
TEST.BASIS_PATH:2 of 13
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if ((ConfigPtr != (void *)0 && StatePtr != (void *)0) && DataPtr != (void *)0) ==> TRUE
      (2) if (((StatePtr->LastValidCounter > 14U || StatePtr->MaxDeltaCounter > 14U) || StatePtr->SyncCounter > ConfigPtr->SyncCounterInit) || StatePtr->NoNewOrRepeatedDataCounter > 14U) ==> FALSE
      (3) if (StatePtr->MaxDeltaCounter < 14U) ==> FALSE
      (4) if (0U != StatePtr->NewDataAvailable) ==> TRUE
      (5) if (ConfigPtr->CounterOffset >> 3U == 0U) ==> FALSE
      (6) if (ReceivedCounter <= 14U) ==> FALSE
   Test Case Generation Notes:
      Conflict: A condition in this branch uses an operand that cannot be set (ConfigPtr->CounterOffset >> 3U) in branch 5
      Cannot set ReceivedCounter due to assignment
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7599
TEST.END_NOTES:
TEST.VALUE:E2E_P01.E2E_P01Check.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P01.E2E_P01Check.ConfigPtr[0].DataLength:8
TEST.VALUE:E2E_P01.E2E_P01Check.ConfigPtr[0].SyncCounterInit:<<MAX>>
TEST.VALUE:E2E_P01.E2E_P01Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P01.E2E_P01Check.StatePtr[0].LastValidCounter:<<MIN>>
TEST.VALUE:E2E_P01.E2E_P01Check.StatePtr[0].MaxDeltaCounter:14
TEST.VALUE:E2E_P01.E2E_P01Check.StatePtr[0].SyncCounter:<<MIN>>
TEST.VALUE:E2E_P01.E2E_P01Check.StatePtr[0].NoNewOrRepeatedDataCounter:<<MIN>>
TEST.VALUE:E2E_P01.E2E_P01Check.StatePtr[0].NewDataAvailable:1
TEST.VALUE:E2E_P01.E2E_P01Check.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_P01.E2E_P01Check.DataPtr[0]:0
TEST.EXPECTED:E2E_P01.E2E_P01Check.return:0
TEST.END

-- Test Case: LastValidCounter>MAX
TEST.UNIT:E2E_P01
TEST.SUBPROGRAM:E2E_P01Check
TEST.NEW
TEST.NAME:LastValidCounter>MAX
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if ((ConfigPtr != (void *)0 && StatePtr != (void *)0) && DataPtr != (void *)0) ==> TRUE
      (2) if (((StatePtr->LastValidCounter > 14U || StatePtr->MaxDeltaCounter > 14U) || StatePtr->SyncCounter > ConfigPtr->SyncCounterInit) || StatePtr->NoNewOrRepeatedDataCounter > 14U) ==> FALSE
      (3) if (StatePtr->MaxDeltaCounter < 14U) ==> FALSE
      (4) if (0U != StatePtr->NewDataAvailable) ==> TRUE
      (5) if (ConfigPtr->CounterOffset >> 3U == 0U) ==> FALSE
      (6) if (ReceivedCounter <= 14U) ==> FALSE
   Test Case Generation Notes:
      Conflict: A condition in this branch uses an operand that cannot be set (ConfigPtr->CounterOffset >> 3U) in branch 5
      Cannot set ReceivedCounter due to assignment
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7599
TEST.END_NOTES:
TEST.VALUE:E2E_P01.E2E_P01Check.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P01.E2E_P01Check.ConfigPtr[0].DataLength:8
TEST.VALUE:E2E_P01.E2E_P01Check.ConfigPtr[0].SyncCounterInit:<<MAX>>
TEST.VALUE:E2E_P01.E2E_P01Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P01.E2E_P01Check.StatePtr[0].LastValidCounter:15
TEST.VALUE:E2E_P01.E2E_P01Check.StatePtr[0].MaxDeltaCounter:14
TEST.VALUE:E2E_P01.E2E_P01Check.StatePtr[0].SyncCounter:<<MIN>>
TEST.VALUE:E2E_P01.E2E_P01Check.StatePtr[0].NoNewOrRepeatedDataCounter:<<MIN>>
TEST.VALUE:E2E_P01.E2E_P01Check.StatePtr[0].NewDataAvailable:1
TEST.VALUE:E2E_P01.E2E_P01Check.DataPtr:<<malloc 1>>
TEST.EXPECTED:E2E_P01.E2E_P01Check.return:23
TEST.END

-- Test Case: MaxDeltaCounter>MaxValue
TEST.UNIT:E2E_P01
TEST.SUBPROGRAM:E2E_P01Check
TEST.NEW
TEST.NAME:MaxDeltaCounter>MaxValue
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if ((ConfigPtr != (void *)0 && StatePtr != (void *)0) && DataPtr != (void *)0) ==> TRUE
      (2) if (((StatePtr->LastValidCounter > 14U || StatePtr->MaxDeltaCounter > 14U) || StatePtr->SyncCounter > ConfigPtr->SyncCounterInit) || StatePtr->NoNewOrRepeatedDataCounter > 14U) ==> FALSE
      (3) if (StatePtr->MaxDeltaCounter < 14U) ==> FALSE
      (4) if (0U != StatePtr->NewDataAvailable) ==> TRUE
      (5) if (ConfigPtr->CounterOffset >> 3U == 0U) ==> FALSE
      (6) if (ReceivedCounter <= 14U) ==> FALSE
   Test Case Generation Notes:
      Conflict: A condition in this branch uses an operand that cannot be set (ConfigPtr->CounterOffset >> 3U) in branch 5
      Cannot set ReceivedCounter due to assignment
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7599
TEST.END_NOTES:
TEST.VALUE:E2E_P01.E2E_P01Check.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P01.E2E_P01Check.ConfigPtr[0].DataLength:8
TEST.VALUE:E2E_P01.E2E_P01Check.ConfigPtr[0].SyncCounterInit:<<MAX>>
TEST.VALUE:E2E_P01.E2E_P01Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P01.E2E_P01Check.StatePtr[0].LastValidCounter:<<MIN>>
TEST.VALUE:E2E_P01.E2E_P01Check.StatePtr[0].MaxDeltaCounter:14
TEST.VALUE:E2E_P01.E2E_P01Check.StatePtr[0].SyncCounter:<<MIN>>
TEST.VALUE:E2E_P01.E2E_P01Check.StatePtr[0].NoNewOrRepeatedDataCounter:<<MIN>>
TEST.VALUE:E2E_P01.E2E_P01Check.StatePtr[0].NewDataAvailable:1
TEST.VALUE:E2E_P01.E2E_P01Check.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_P01.E2E_P01Check.DataPtr[0]:15
TEST.END

-- Test Case: NewDataAvailable==FALSE
TEST.UNIT:E2E_P01
TEST.SUBPROGRAM:E2E_P01Check
TEST.NEW
TEST.NAME:NewDataAvailable==FALSE
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if ((ConfigPtr != (void *)0 && StatePtr != (void *)0) && DataPtr != (void *)0) ==> TRUE
      (2) if (((StatePtr->LastValidCounter > 14U || StatePtr->MaxDeltaCounter > 14U) || StatePtr->SyncCounter > ConfigPtr->SyncCounterInit) || StatePtr->NoNewOrRepeatedDataCounter > 14U) ==> FALSE
      (3) if (StatePtr->MaxDeltaCounter < 14U) ==> FALSE
      (4) if (0U != StatePtr->NewDataAvailable) ==> TRUE
      (5) if (ConfigPtr->CounterOffset >> 3U == 0U) ==> FALSE
      (6) if (ReceivedCounter <= 14U) ==> FALSE
   Test Case Generation Notes:
      Conflict: A condition in this branch uses an operand that cannot be set (ConfigPtr->CounterOffset >> 3U) in branch 5
      Cannot set ReceivedCounter due to assignment
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7599
TEST.END_NOTES:
TEST.VALUE:E2E_P01.E2E_P01Check.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P01.E2E_P01Check.ConfigPtr[0].DataIDMode:E2E_P01_DATAID_ALT
TEST.VALUE:E2E_P01.E2E_P01Check.ConfigPtr[0].CounterOffset:9
TEST.VALUE:E2E_P01.E2E_P01Check.ConfigPtr[0].DataID:65535
TEST.VALUE:E2E_P01.E2E_P01Check.ConfigPtr[0].DataLength:8
TEST.VALUE:E2E_P01.E2E_P01Check.ConfigPtr[0].SyncCounterInit:<<MAX>>
TEST.VALUE:E2E_P01.E2E_P01Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P01.E2E_P01Check.StatePtr[0].LastValidCounter:<<MIN>>
TEST.VALUE:E2E_P01.E2E_P01Check.StatePtr[0].MaxDeltaCounter:0
TEST.VALUE:E2E_P01.E2E_P01Check.StatePtr[0].SyncCounter:<<MIN>>
TEST.VALUE:E2E_P01.E2E_P01Check.StatePtr[0].NoNewOrRepeatedDataCounter:<<MIN>>
TEST.VALUE:E2E_P01.E2E_P01Check.StatePtr[0].NewDataAvailable:0
TEST.VALUE:E2E_P01.E2E_P01Check.DataPtr:<<malloc 1>>
TEST.EXPECTED:E2E_P01.E2E_P01Check.return:0
TEST.END

-- Test Case: NonewOrrepeatedDataCounter>MAX
TEST.UNIT:E2E_P01
TEST.SUBPROGRAM:E2E_P01Check
TEST.NEW
TEST.NAME:NonewOrrepeatedDataCounter>MAX
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if ((ConfigPtr != (void *)0 && StatePtr != (void *)0) && DataPtr != (void *)0) ==> TRUE
      (2) if (((StatePtr->LastValidCounter > 14U || StatePtr->MaxDeltaCounter > 14U) || StatePtr->SyncCounter > ConfigPtr->SyncCounterInit) || StatePtr->NoNewOrRepeatedDataCounter > 14U) ==> FALSE
      (3) if (StatePtr->MaxDeltaCounter < 14U) ==> FALSE
      (4) if (0U != StatePtr->NewDataAvailable) ==> TRUE
      (5) if (ConfigPtr->CounterOffset >> 3U == 0U) ==> FALSE
      (6) if (ReceivedCounter <= 14U) ==> FALSE
   Test Case Generation Notes:
      Conflict: A condition in this branch uses an operand that cannot be set (ConfigPtr->CounterOffset >> 3U) in branch 5
      Cannot set ReceivedCounter due to assignment
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7599
TEST.END_NOTES:
TEST.VALUE:E2E_P01.E2E_P01Check.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P01.E2E_P01Check.ConfigPtr[0].DataIDMode:E2E_P01_DATAID_ALT
TEST.VALUE:E2E_P01.E2E_P01Check.ConfigPtr[0].CounterOffset:9
TEST.VALUE:E2E_P01.E2E_P01Check.ConfigPtr[0].DataID:65535
TEST.VALUE:E2E_P01.E2E_P01Check.ConfigPtr[0].DataLength:8
TEST.VALUE:E2E_P01.E2E_P01Check.ConfigPtr[0].SyncCounterInit:<<MAX>>
TEST.VALUE:E2E_P01.E2E_P01Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P01.E2E_P01Check.StatePtr[0].LastValidCounter:<<MIN>>
TEST.VALUE:E2E_P01.E2E_P01Check.StatePtr[0].MaxDeltaCounter:0
TEST.VALUE:E2E_P01.E2E_P01Check.StatePtr[0].SyncCounter:<<MIN>>
TEST.VALUE:E2E_P01.E2E_P01Check.StatePtr[0].NoNewOrRepeatedDataCounter:VARY FROM:0 TO:255 BY: 1
TEST.VALUE:E2E_P01.E2E_P01Check.StatePtr[0].NewDataAvailable:0
TEST.VALUE:E2E_P01.E2E_P01Check.DataPtr:<<malloc 1>>
TEST.END

-- Test Case: WaitforFirstData!=0
TEST.UNIT:E2E_P01
TEST.SUBPROGRAM:E2E_P01Check
TEST.NEW
TEST.NAME:WaitforFirstData!=0
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if ((ConfigPtr != (void *)0 && StatePtr != (void *)0) && DataPtr != (void *)0) ==> TRUE
      (2) if (((StatePtr->LastValidCounter > 14U || StatePtr->MaxDeltaCounter > 14U) || StatePtr->SyncCounter > ConfigPtr->SyncCounterInit) || StatePtr->NoNewOrRepeatedDataCounter > 14U) ==> FALSE
      (3) if (StatePtr->MaxDeltaCounter < 14U) ==> FALSE
      (4) if (0U != StatePtr->NewDataAvailable) ==> TRUE
      (5) if (ConfigPtr->CounterOffset >> 3U == 0U) ==> FALSE
      (6) if (ReceivedCounter <= 14U) ==> FALSE
   Test Case Generation Notes:
      Conflict: A condition in this branch uses an operand that cannot be set (ConfigPtr->CounterOffset >> 3U) in branch 5
      Cannot set ReceivedCounter due to assignment
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7599
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.Crc_CalculateCRC8.return:255
TEST.VALUE:E2E_P01.E2E_P01Check.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P01.E2E_P01Check.ConfigPtr[0].DataIDMode:E2E_P01_DATAID_BOTH
TEST.VALUE:E2E_P01.E2E_P01Check.ConfigPtr[0].CounterOffset:9
TEST.VALUE:E2E_P01.E2E_P01Check.ConfigPtr[0].CRCOffset:0
TEST.VALUE:E2E_P01.E2E_P01Check.ConfigPtr[0].DataID:65535
TEST.VALUE:E2E_P01.E2E_P01Check.ConfigPtr[0].DataLength:8
TEST.VALUE:E2E_P01.E2E_P01Check.ConfigPtr[0].SyncCounterInit:<<MAX>>
TEST.VALUE:E2E_P01.E2E_P01Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P01.E2E_P01Check.StatePtr[0].LastValidCounter:<<MIN>>
TEST.VALUE:E2E_P01.E2E_P01Check.StatePtr[0].MaxDeltaCounter:0
TEST.VALUE:E2E_P01.E2E_P01Check.StatePtr[0].SyncCounter:<<MIN>>
TEST.VALUE:E2E_P01.E2E_P01Check.StatePtr[0].NoNewOrRepeatedDataCounter:<<MIN>>
TEST.VALUE:E2E_P01.E2E_P01Check.StatePtr[0].WaitForFirstData:1
TEST.VALUE:E2E_P01.E2E_P01Check.StatePtr[0].NewDataAvailable:1
TEST.VALUE:E2E_P01.E2E_P01Check.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_P01.E2E_P01Check.DataPtr[0]:0
TEST.EXPECTED:E2E_P01.E2E_P01Check.return:0
TEST.END

-- Subprogram: E2E_P01CheckInit

-- Test Case: StatePtr!=NULL
TEST.UNIT:E2E_P01
TEST.SUBPROGRAM:E2E_P01CheckInit
TEST.NEW
TEST.NAME:StatePtr!=NULL
TEST.NOTES:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7599
TEST.END_NOTES:
TEST.VALUE:E2E_P01.E2E_P01CheckInit.StatePtr:<<malloc 1>>
TEST.EXPECTED:E2E_P01.E2E_P01CheckInit.return:0
TEST.END

-- Test Case: StatePtr==NULL
TEST.UNIT:E2E_P01
TEST.SUBPROGRAM:E2E_P01CheckInit
TEST.NEW
TEST.NAME:StatePtr==NULL
TEST.NOTES:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7599
TEST.END_NOTES:
TEST.VALUE:E2E_P01.E2E_P01CheckInit.StatePtr:<<null>>
TEST.EXPECTED:E2E_P01.E2E_P01CheckInit.return:19
TEST.END

-- Subprogram: E2E_P01ComputeCRC

-- Test Case: DATAID_ALT
TEST.UNIT:E2E_P01
TEST.SUBPROGRAM:E2E_P01ComputeCRC
TEST.NEW
TEST.NAME:DATAID_ALT
TEST.NOTES:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7599
TEST.END_NOTES:
TEST.VALUE:E2E_P01.E2E_P01ComputeCRC.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P01.E2E_P01ComputeCRC.ConfigPtr[0].DataIDMode:E2E_P01_DATAID_ALT
TEST.END

-- Test Case: DATAID_ALT_Counter
TEST.UNIT:E2E_P01
TEST.SUBPROGRAM:E2E_P01ComputeCRC
TEST.NEW
TEST.NAME:DATAID_ALT_Counter
TEST.NOTES:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7599
TEST.END_NOTES:
TEST.VALUE:E2E_P01.E2E_P01ComputeCRC.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P01.E2E_P01ComputeCRC.ConfigPtr[0].DataIDMode:E2E_P01_DATAID_ALT
TEST.VALUE:E2E_P01.E2E_P01ComputeCRC.Counter:3
TEST.END

-- Test Case: DATAID_BOTH
TEST.UNIT:E2E_P01
TEST.SUBPROGRAM:E2E_P01ComputeCRC
TEST.NEW
TEST.NAME:DATAID_BOTH
TEST.NOTES:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7599
TEST.END_NOTES:
TEST.VALUE:E2E_P01.E2E_P01ComputeCRC.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P01.E2E_P01ComputeCRC.ConfigPtr[0].DataIDMode:E2E_P01_DATAID_BOTH
TEST.END

-- Test Case: DATAID_LOW
TEST.UNIT:E2E_P01
TEST.SUBPROGRAM:E2E_P01ComputeCRC
TEST.NEW
TEST.NAME:DATAID_LOW
TEST.NOTES:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7599
TEST.END_NOTES:
TEST.VALUE:E2E_P01.E2E_P01ComputeCRC.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P01.E2E_P01ComputeCRC.ConfigPtr[0].DataIDMode:E2E_P01_DATAID_LOW
TEST.VALUE:E2E_P01.E2E_P01ComputeCRC.ConfigPtr[0].CRCOffset:9
TEST.VALUE:E2E_P01.E2E_P01ComputeCRC.ConfigPtr[0].DataLength:8
TEST.END

-- Test Case: DATAID_NIBBLE
TEST.UNIT:E2E_P01
TEST.SUBPROGRAM:E2E_P01ComputeCRC
TEST.NEW
TEST.NAME:DATAID_NIBBLE
TEST.NOTES:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7599
TEST.END_NOTES:
TEST.VALUE:E2E_P01.E2E_P01ComputeCRC.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P01.E2E_P01ComputeCRC.ConfigPtr[0].DataIDMode:E2E_P01_DATAID_NIBBLE
TEST.VALUE:E2E_P01.E2E_P01ComputeCRC.Counter:3
TEST.END

-- Test Case: DataIdMode_default
TEST.UNIT:E2E_P01
TEST.SUBPROGRAM:E2E_P01ComputeCRC
TEST.NEW
TEST.NAME:DataIdMode_default
TEST.NOTES:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7599
TEST.END_NOTES:
TEST.VALUE:E2E_P01.E2E_P01ComputeCRC.DataPtr:<<malloc 2>>
TEST.VALUE:E2E_P01.E2E_P01ComputeCRC.DataPtr:"1"
TEST.VALUE:E2E_P01.E2E_P01ComputeCRC.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P01.E2E_P01ComputeCRC.ConfigPtr[0].DataIDMode:10
TEST.END

-- Subprogram: E2E_P01MapStatusToSM

-- Test Case: BASIS-PATH-001
TEST.UNIT:E2E_P01
TEST.SUBPROGRAM:E2E_P01MapStatusToSM
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 12
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (1U != CheckReturn) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7599
TEST.END_NOTES:
TEST.VALUE:E2E_P01.E2E_P01MapStatusToSM.CheckReturn:1
TEST.VALUE:E2E_P01.E2E_P01MapStatusToSM.Status:<<MIN>>
TEST.VALUE:E2E_P01.E2E_P01MapStatusToSM.profileBehavior:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:E2E_P01
TEST.SUBPROGRAM:E2E_P01MapStatusToSM
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 12
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (1U != CheckReturn) ==> TRUE
      (2) if (Status == (E2E_P01STATUS_OK)) ==> FALSE
      (3) if (Status == (E2E_P01STATUS_NONEWDATA)) ==> FALSE
      (4) if (Status == (E2E_P01STATUS_WRONGCRC)) ==> FALSE
      (5) if (Status == (E2E_P01STATUS_SYNC)) ==> FALSE
      (7) if (Status == (E2E_P01STATUS_INITIAL)) ==> FALSE
      (9) if (Status == (E2E_P01STATUS_REPEATED)) ==> FALSE
      (10) if (Status == (E2E_P01STATUS_OKSOMELOST)) ==> FALSE
      (11) if (Status == (E2E_P01STATUS_WRONGSEQUENCE)) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7599
TEST.END_NOTES:
TEST.VALUE:E2E_P01.E2E_P01MapStatusToSM.CheckReturn:<<MIN>>
TEST.VALUE:E2E_P01.E2E_P01MapStatusToSM.Status:8
TEST.VALUE:E2E_P01.E2E_P01MapStatusToSM.profileBehavior:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-003
TEST.UNIT:E2E_P01
TEST.SUBPROGRAM:E2E_P01MapStatusToSM
TEST.NEW
TEST.NAME:BASIS-PATH-003
TEST.BASIS_PATH:3 of 12
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (1U != CheckReturn) ==> TRUE
      (2) if (Status == (E2E_P01STATUS_OK)) ==> FALSE
      (3) if (Status == (E2E_P01STATUS_NONEWDATA)) ==> FALSE
      (4) if (Status == (E2E_P01STATUS_WRONGCRC)) ==> FALSE
      (5) if (Status == (E2E_P01STATUS_SYNC)) ==> FALSE
      (7) if (Status == (E2E_P01STATUS_INITIAL)) ==> FALSE
      (9) if (Status == (E2E_P01STATUS_REPEATED)) ==> FALSE
      (10) if (Status == (E2E_P01STATUS_OKSOMELOST)) ==> FALSE
      (11) if (Status == (E2E_P01STATUS_WRONGSEQUENCE)) ==> TRUE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7599
TEST.END_NOTES:
TEST.VALUE:E2E_P01.E2E_P01MapStatusToSM.CheckReturn:<<MIN>>
TEST.VALUE:E2E_P01.E2E_P01MapStatusToSM.Status:E2E_P01STATUS_WRONGSEQUENCE
TEST.VALUE:E2E_P01.E2E_P01MapStatusToSM.profileBehavior:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-004
TEST.UNIT:E2E_P01
TEST.SUBPROGRAM:E2E_P01MapStatusToSM
TEST.NEW
TEST.NAME:BASIS-PATH-004
TEST.BASIS_PATH:4 of 12
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if (1U != CheckReturn) ==> TRUE
      (2) if (Status == (E2E_P01STATUS_OK)) ==> FALSE
      (3) if (Status == (E2E_P01STATUS_NONEWDATA)) ==> FALSE
      (4) if (Status == (E2E_P01STATUS_WRONGCRC)) ==> FALSE
      (5) if (Status == (E2E_P01STATUS_SYNC)) ==> FALSE
      (7) if (Status == (E2E_P01STATUS_INITIAL)) ==> FALSE
      (9) if (Status == (E2E_P01STATUS_REPEATED)) ==> FALSE
      (10) if (Status == (E2E_P01STATUS_OKSOMELOST)) ==> TRUE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7599
TEST.END_NOTES:
TEST.VALUE:E2E_P01.E2E_P01MapStatusToSM.CheckReturn:<<MIN>>
TEST.VALUE:E2E_P01.E2E_P01MapStatusToSM.Status:E2E_P01STATUS_OKSOMELOST
TEST.VALUE:E2E_P01.E2E_P01MapStatusToSM.profileBehavior:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-005
TEST.UNIT:E2E_P01
TEST.SUBPROGRAM:E2E_P01MapStatusToSM
TEST.NEW
TEST.NAME:BASIS-PATH-005
TEST.BASIS_PATH:5 of 12
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (1) if (1U != CheckReturn) ==> TRUE
      (2) if (Status == (E2E_P01STATUS_OK)) ==> FALSE
      (3) if (Status == (E2E_P01STATUS_NONEWDATA)) ==> FALSE
      (4) if (Status == (E2E_P01STATUS_WRONGCRC)) ==> FALSE
      (5) if (Status == (E2E_P01STATUS_SYNC)) ==> FALSE
      (7) if (Status == (E2E_P01STATUS_INITIAL)) ==> FALSE
      (9) if (Status == (E2E_P01STATUS_REPEATED)) ==> TRUE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7599
TEST.END_NOTES:
TEST.VALUE:E2E_P01.E2E_P01MapStatusToSM.CheckReturn:<<MIN>>
TEST.VALUE:E2E_P01.E2E_P01MapStatusToSM.Status:E2E_P01STATUS_REPEATED
TEST.VALUE:E2E_P01.E2E_P01MapStatusToSM.profileBehavior:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-006
TEST.UNIT:E2E_P01
TEST.SUBPROGRAM:E2E_P01MapStatusToSM
TEST.NEW
TEST.NAME:BASIS-PATH-006
TEST.BASIS_PATH:6 of 12
TEST.NOTES:
This is an automatically generated test case.
   Test Path 6
      (1) if (1U != CheckReturn) ==> TRUE
      (2) if (Status == (E2E_P01STATUS_OK)) ==> FALSE
      (3) if (Status == (E2E_P01STATUS_NONEWDATA)) ==> FALSE
      (4) if (Status == (E2E_P01STATUS_WRONGCRC)) ==> FALSE
      (5) if (Status == (E2E_P01STATUS_SYNC)) ==> FALSE
      (7) if (Status == (E2E_P01STATUS_INITIAL)) ==> TRUE
      (8) if (0U == profileBehavior) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7599
TEST.END_NOTES:
TEST.VALUE:E2E_P01.E2E_P01MapStatusToSM.CheckReturn:<<MIN>>
TEST.VALUE:E2E_P01.E2E_P01MapStatusToSM.Status:E2E_P01STATUS_INITIAL
TEST.VALUE:E2E_P01.E2E_P01MapStatusToSM.profileBehavior:1
TEST.END

-- Test Case: BASIS-PATH-007
TEST.UNIT:E2E_P01
TEST.SUBPROGRAM:E2E_P01MapStatusToSM
TEST.NEW
TEST.NAME:BASIS-PATH-007
TEST.BASIS_PATH:7 of 12
TEST.NOTES:
This is an automatically generated test case.
   Test Path 7
      (1) if (1U != CheckReturn) ==> TRUE
      (2) if (Status == (E2E_P01STATUS_OK)) ==> FALSE
      (3) if (Status == (E2E_P01STATUS_NONEWDATA)) ==> FALSE
      (4) if (Status == (E2E_P01STATUS_WRONGCRC)) ==> FALSE
      (5) if (Status == (E2E_P01STATUS_SYNC)) ==> FALSE
      (7) if (Status == (E2E_P01STATUS_INITIAL)) ==> TRUE
      (8) if (0U == profileBehavior) ==> TRUE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7599
TEST.END_NOTES:
TEST.VALUE:E2E_P01.E2E_P01MapStatusToSM.CheckReturn:<<MIN>>
TEST.VALUE:E2E_P01.E2E_P01MapStatusToSM.Status:E2E_P01STATUS_INITIAL
TEST.VALUE:E2E_P01.E2E_P01MapStatusToSM.profileBehavior:0
TEST.END

-- Test Case: BASIS-PATH-008
TEST.UNIT:E2E_P01
TEST.SUBPROGRAM:E2E_P01MapStatusToSM
TEST.NEW
TEST.NAME:BASIS-PATH-008
TEST.BASIS_PATH:8 of 12
TEST.NOTES:
This is an automatically generated test case.
   Test Path 8
      (1) if (1U != CheckReturn) ==> TRUE
      (2) if (Status == (E2E_P01STATUS_OK)) ==> FALSE
      (3) if (Status == (E2E_P01STATUS_NONEWDATA)) ==> FALSE
      (4) if (Status == (E2E_P01STATUS_WRONGCRC)) ==> FALSE
      (5) if (Status == (E2E_P01STATUS_SYNC)) ==> TRUE
      (6) if (0U == profileBehavior) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7599
TEST.END_NOTES:
TEST.VALUE:E2E_P01.E2E_P01MapStatusToSM.CheckReturn:<<MIN>>
TEST.VALUE:E2E_P01.E2E_P01MapStatusToSM.Status:E2E_P01STATUS_SYNC
TEST.VALUE:E2E_P01.E2E_P01MapStatusToSM.profileBehavior:1
TEST.END

-- Test Case: BASIS-PATH-009
TEST.UNIT:E2E_P01
TEST.SUBPROGRAM:E2E_P01MapStatusToSM
TEST.NEW
TEST.NAME:BASIS-PATH-009
TEST.BASIS_PATH:9 of 12
TEST.NOTES:
This is an automatically generated test case.
   Test Path 9
      (1) if (1U != CheckReturn) ==> TRUE
      (2) if (Status == (E2E_P01STATUS_OK)) ==> FALSE
      (3) if (Status == (E2E_P01STATUS_NONEWDATA)) ==> FALSE
      (4) if (Status == (E2E_P01STATUS_WRONGCRC)) ==> FALSE
      (5) if (Status == (E2E_P01STATUS_SYNC)) ==> TRUE
      (6) if (0U == profileBehavior) ==> TRUE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7599
TEST.END_NOTES:
TEST.VALUE:E2E_P01.E2E_P01MapStatusToSM.CheckReturn:<<MIN>>
TEST.VALUE:E2E_P01.E2E_P01MapStatusToSM.Status:E2E_P01STATUS_SYNC
TEST.VALUE:E2E_P01.E2E_P01MapStatusToSM.profileBehavior:0
TEST.END

-- Test Case: BASIS-PATH-010
TEST.UNIT:E2E_P01
TEST.SUBPROGRAM:E2E_P01MapStatusToSM
TEST.NEW
TEST.NAME:BASIS-PATH-010
TEST.BASIS_PATH:10 of 12
TEST.NOTES:
This is an automatically generated test case.
   Test Path 10
      (1) if (1U != CheckReturn) ==> TRUE
      (2) if (Status == (E2E_P01STATUS_OK)) ==> FALSE
      (3) if (Status == (E2E_P01STATUS_NONEWDATA)) ==> FALSE
      (4) if (Status == (E2E_P01STATUS_WRONGCRC)) ==> TRUE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7599
TEST.END_NOTES:
TEST.VALUE:E2E_P01.E2E_P01MapStatusToSM.CheckReturn:<<MIN>>
TEST.VALUE:E2E_P01.E2E_P01MapStatusToSM.Status:E2E_P01STATUS_WRONGCRC
TEST.VALUE:E2E_P01.E2E_P01MapStatusToSM.profileBehavior:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-011
TEST.UNIT:E2E_P01
TEST.SUBPROGRAM:E2E_P01MapStatusToSM
TEST.NEW
TEST.NAME:BASIS-PATH-011
TEST.BASIS_PATH:11 of 12
TEST.NOTES:
This is an automatically generated test case.
   Test Path 11
      (1) if (1U != CheckReturn) ==> TRUE
      (2) if (Status == (E2E_P01STATUS_OK)) ==> FALSE
      (3) if (Status == (E2E_P01STATUS_NONEWDATA)) ==> TRUE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7599
TEST.END_NOTES:
TEST.VALUE:E2E_P01.E2E_P01MapStatusToSM.CheckReturn:<<MIN>>
TEST.VALUE:E2E_P01.E2E_P01MapStatusToSM.Status:E2E_P01STATUS_NONEWDATA
TEST.VALUE:E2E_P01.E2E_P01MapStatusToSM.profileBehavior:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-012
TEST.UNIT:E2E_P01
TEST.SUBPROGRAM:E2E_P01MapStatusToSM
TEST.NEW
TEST.NAME:BASIS-PATH-012
TEST.BASIS_PATH:12 of 12
TEST.NOTES:
This is an automatically generated test case.
   Test Path 12
      (1) if (1U != CheckReturn) ==> TRUE
      (2) if (Status == (E2E_P01STATUS_OK)) ==> TRUE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7599
TEST.END_NOTES:
TEST.VALUE:E2E_P01.E2E_P01MapStatusToSM.CheckReturn:<<MIN>>
TEST.VALUE:E2E_P01.E2E_P01MapStatusToSM.Status:E2E_P01STATUS_OK
TEST.VALUE:E2E_P01.E2E_P01MapStatusToSM.profileBehavior:<<MIN>>
TEST.END

-- Subprogram: E2E_P01Protect

-- Test Case: ConfigPtr==NULL
TEST.UNIT:E2E_P01
TEST.SUBPROGRAM:E2E_P01Protect
TEST.NEW
TEST.NAME:ConfigPtr==NULL
TEST.BASIS_PATH:2 of 6
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if ((ConfigPtr != (void *)0 && StatePtr != (void *)0) && DataPtr != (void *)0) ==> TRUE
      (2) if (StatePtr->Counter > 14U) ==> FALSE
      (3) if (ConfigPtr->CounterOffset >> 3U == 0U) ==> FALSE
      (4) if (ConfigPtr->DataIDMode == (E2E_P01_DATAID_NIBBLE)) ==> FALSE
   Test Case Generation Notes:
      Conflict: A condition in this branch uses an operand that cannot be set (ConfigPtr->CounterOffset >> 3U) in branch 3
      Cannot set CRCOffset due to assignment
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7599
TEST.END_NOTES:
TEST.VALUE:E2E_P01.E2E_P01Protect.ConfigPtr:<<null>>
TEST.VALUE:E2E_P01.E2E_P01Protect.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P01.E2E_P01Protect.StatePtr[0].Counter:<<MIN>>
TEST.VALUE:E2E_P01.E2E_P01Protect.DataPtr:<<malloc 1>>
TEST.EXPECTED:E2E_P01.E2E_P01Protect.return:19
TEST.END

-- Test Case: Counter>MAX
TEST.UNIT:E2E_P01
TEST.SUBPROGRAM:E2E_P01Protect
TEST.NEW
TEST.NAME:Counter>MAX
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((ConfigPtr != (void *)0 && StatePtr != (void *)0) && DataPtr != (void *)0) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7599
TEST.END_NOTES:
TEST.VALUE:E2E_P01.E2E_P01Protect.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P01.E2E_P01Protect.ConfigPtr[0].DataIDMode:E2E_P01_DATAID_NIBBLE
TEST.VALUE:E2E_P01.E2E_P01Protect.ConfigPtr[0].CRCOffset:0
TEST.VALUE:E2E_P01.E2E_P01Protect.ConfigPtr[0].DataIDNibbleOffset:0
TEST.VALUE:E2E_P01.E2E_P01Protect.ConfigPtr[0].DataLength:8
TEST.VALUE:E2E_P01.E2E_P01Protect.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P01.E2E_P01Protect.StatePtr[0].Counter:15
TEST.VALUE:E2E_P01.E2E_P01Protect.DataPtr:<<malloc 1>>
TEST.EXPECTED:E2E_P01.E2E_P01Protect.return:23
TEST.END

-- Test Case: DATAID_BOTH
TEST.UNIT:E2E_P01
TEST.SUBPROGRAM:E2E_P01Protect
TEST.NEW
TEST.NAME:DATAID_BOTH
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((ConfigPtr != (void *)0 && StatePtr != (void *)0) && DataPtr != (void *)0) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7599
TEST.END_NOTES:
TEST.VALUE:E2E_P01.E2E_P01Protect.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P01.E2E_P01Protect.ConfigPtr[0].DataIDMode:E2E_P01_DATAID_BOTH
TEST.VALUE:E2E_P01.E2E_P01Protect.ConfigPtr[0].CounterOffset:9
TEST.VALUE:E2E_P01.E2E_P01Protect.ConfigPtr[0].CRCOffset:1
TEST.VALUE:E2E_P01.E2E_P01Protect.ConfigPtr[0].DataIDNibbleOffset:0
TEST.VALUE:E2E_P01.E2E_P01Protect.ConfigPtr[0].DataLength:8
TEST.VALUE:E2E_P01.E2E_P01Protect.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P01.E2E_P01Protect.StatePtr[0].Counter:1
TEST.VALUE:E2E_P01.E2E_P01Protect.DataPtr:<<malloc 1>>
TEST.END

-- Test Case: DATAID_NIBBLE_Offset>0
TEST.UNIT:E2E_P01
TEST.SUBPROGRAM:E2E_P01Protect
TEST.NEW
TEST.NAME:DATAID_NIBBLE_Offset>0
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((ConfigPtr != (void *)0 && StatePtr != (void *)0) && DataPtr != (void *)0) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7599
TEST.END_NOTES:
TEST.VALUE:E2E_P01.E2E_P01Protect.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P01.E2E_P01Protect.ConfigPtr[0].DataIDMode:E2E_P01_DATAID_NIBBLE
TEST.VALUE:E2E_P01.E2E_P01Protect.ConfigPtr[0].CRCOffset:0
TEST.VALUE:E2E_P01.E2E_P01Protect.ConfigPtr[0].DataIDNibbleOffset:9
TEST.VALUE:E2E_P01.E2E_P01Protect.ConfigPtr[0].DataLength:8
TEST.VALUE:E2E_P01.E2E_P01Protect.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P01.E2E_P01Protect.StatePtr[0].Counter:1
TEST.VALUE:E2E_P01.E2E_P01Protect.DataPtr:<<malloc 1>>
TEST.END

-- Test Case: DatalengthCondition
TEST.UNIT:E2E_P01
TEST.SUBPROGRAM:E2E_P01Protect
TEST.NEW
TEST.NAME:DatalengthCondition
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((ConfigPtr != (void *)0 && StatePtr != (void *)0) && DataPtr != (void *)0) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7599
TEST.END_NOTES:
TEST.VALUE:E2E_P01.E2E_P01Protect.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P01.E2E_P01Protect.ConfigPtr[0].DataIDMode:E2E_P01_DATAID_NIBBLE
TEST.VALUE:E2E_P01.E2E_P01Protect.ConfigPtr[0].CRCOffset:0
TEST.VALUE:E2E_P01.E2E_P01Protect.ConfigPtr[0].DataIDNibbleOffset:0
TEST.VALUE:E2E_P01.E2E_P01Protect.ConfigPtr[0].DataLength:0
TEST.VALUE:E2E_P01.E2E_P01Protect.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P01.E2E_P01Protect.StatePtr[0].Counter:1
TEST.VALUE:E2E_P01.E2E_P01Protect.DataPtr:<<malloc 1>>
TEST.END

-- Test Case: Inputs!=NULL
TEST.UNIT:E2E_P01
TEST.SUBPROGRAM:E2E_P01Protect
TEST.NEW
TEST.NAME:Inputs!=NULL
TEST.BASIS_PATH:1 of 6
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((ConfigPtr != (void *)0 && StatePtr != (void *)0) && DataPtr != (void *)0) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7599
TEST.END_NOTES:
TEST.VALUE:E2E_P01.E2E_P01Protect.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P01.E2E_P01Protect.ConfigPtr[0].DataIDMode:E2E_P01_DATAID_NIBBLE
TEST.VALUE:E2E_P01.E2E_P01Protect.ConfigPtr[0].CRCOffset:0
TEST.VALUE:E2E_P01.E2E_P01Protect.ConfigPtr[0].DataIDNibbleOffset:0
TEST.VALUE:E2E_P01.E2E_P01Protect.ConfigPtr[0].DataLength:8
TEST.VALUE:E2E_P01.E2E_P01Protect.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P01.E2E_P01Protect.StatePtr[0].Counter:1
TEST.VALUE:E2E_P01.E2E_P01Protect.DataPtr:<<malloc 1>>
TEST.END

-- Subprogram: E2E_P01ProtectInit

-- Test Case: StatePtr!=NULL
TEST.UNIT:E2E_P01
TEST.SUBPROGRAM:E2E_P01ProtectInit
TEST.NEW
TEST.NAME:StatePtr!=NULL
TEST.NOTES:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7599
TEST.END_NOTES:
TEST.VALUE:E2E_P01.E2E_P01ProtectInit.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P01.E2E_P01ProtectInit.StatePtr[0].Counter:0
TEST.EXPECTED:E2E_P01.E2E_P01ProtectInit.return:0
TEST.END

-- Test Case: StatePtr==NULL
TEST.UNIT:E2E_P01
TEST.SUBPROGRAM:E2E_P01ProtectInit
TEST.NEW
TEST.NAME:StatePtr==NULL
TEST.NOTES:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7599
TEST.END_NOTES:
TEST.VALUE:E2E_P01.E2E_P01ProtectInit.StatePtr:<<null>>
TEST.EXPECTED:E2E_P01.E2E_P01ProtectInit.return:19
TEST.END

-- Subprogram: E2E_ProcessDeltaCounter

-- Test Case: DeltaCounterEquals0
TEST.UNIT:E2E_P01
TEST.SUBPROGRAM:E2E_ProcessDeltaCounter
TEST.NEW
TEST.NAME:DeltaCounterEquals0
TEST.BASIS_PATH:1 of 6
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (DeltaCounter == 0U) ==> FALSE
      (3) if (DeltaCounter == 1U) ==> FALSE
      (4) if (DeltaCounter <= StatePtr->MaxDeltaCounter) ==> FALSE
      (5) if (StatePtr->SyncCounter > 0U) ==> FALSE
   Test Case Generation Notes:
      Cannot set DeltaCounter due to assignment
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7599
TEST.END_NOTES:
TEST.VALUE:E2E_P01.E2E_ProcessDeltaCounter.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P01.E2E_ProcessDeltaCounter.ConfigPtr[0].SyncCounterInit:<<MIN>>
TEST.VALUE:E2E_P01.E2E_ProcessDeltaCounter.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P01.E2E_ProcessDeltaCounter.StatePtr[0].LastValidCounter:0
TEST.VALUE:E2E_P01.E2E_ProcessDeltaCounter.StatePtr[0].MaxDeltaCounter:<<MIN>>
TEST.VALUE:E2E_P01.E2E_ProcessDeltaCounter.ReceivedCounter:0
TEST.END

-- Test Case: DeltaCounterEquals1
TEST.UNIT:E2E_P01
TEST.SUBPROGRAM:E2E_ProcessDeltaCounter
TEST.NEW
TEST.NAME:DeltaCounterEquals1
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (DeltaCounter == 0U) ==> FALSE
      (3) if (DeltaCounter == 1U) ==> FALSE
      (4) if (DeltaCounter <= StatePtr->MaxDeltaCounter) ==> FALSE
      (5) if (StatePtr->SyncCounter > 0U) ==> FALSE
   Test Case Generation Notes:
      Cannot set DeltaCounter due to assignment
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7599
TEST.END_NOTES:
TEST.VALUE:E2E_P01.E2E_ProcessDeltaCounter.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P01.E2E_ProcessDeltaCounter.ConfigPtr[0].SyncCounterInit:<<MIN>>
TEST.VALUE:E2E_P01.E2E_ProcessDeltaCounter.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P01.E2E_ProcessDeltaCounter.StatePtr[0].LastValidCounter:0
TEST.VALUE:E2E_P01.E2E_ProcessDeltaCounter.StatePtr[0].MaxDeltaCounter:<<MIN>>
TEST.VALUE:E2E_P01.E2E_ProcessDeltaCounter.ReceivedCounter:1
TEST.END

-- Test Case: DeltaCounterEquals2
TEST.UNIT:E2E_P01
TEST.SUBPROGRAM:E2E_ProcessDeltaCounter
TEST.NEW
TEST.NAME:DeltaCounterEquals2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (DeltaCounter == 0U) ==> FALSE
      (3) if (DeltaCounter == 1U) ==> FALSE
      (4) if (DeltaCounter <= StatePtr->MaxDeltaCounter) ==> FALSE
      (5) if (StatePtr->SyncCounter > 0U) ==> FALSE
   Test Case Generation Notes:
      Cannot set DeltaCounter due to assignment
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7599
TEST.END_NOTES:
TEST.VALUE:E2E_P01.E2E_ProcessDeltaCounter.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P01.E2E_ProcessDeltaCounter.ConfigPtr[0].SyncCounterInit:2
TEST.VALUE:E2E_P01.E2E_ProcessDeltaCounter.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P01.E2E_ProcessDeltaCounter.StatePtr[0].LastValidCounter:0
TEST.VALUE:E2E_P01.E2E_ProcessDeltaCounter.StatePtr[0].MaxDeltaCounter:<<MIN>>
TEST.VALUE:E2E_P01.E2E_ProcessDeltaCounter.StatePtr[0].SyncCounter:2
TEST.VALUE:E2E_P01.E2E_ProcessDeltaCounter.ReceivedCounter:2
TEST.END

-- Test Case: DeltaCounterEquals2and<=MaxDeltaCounter
TEST.UNIT:E2E_P01
TEST.SUBPROGRAM:E2E_ProcessDeltaCounter
TEST.NEW
TEST.NAME:DeltaCounterEquals2and<=MaxDeltaCounter
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (DeltaCounter == 0U) ==> FALSE
      (3) if (DeltaCounter == 1U) ==> FALSE
      (4) if (DeltaCounter <= StatePtr->MaxDeltaCounter) ==> FALSE
      (5) if (StatePtr->SyncCounter > 0U) ==> FALSE
   Test Case Generation Notes:
      Cannot set DeltaCounter due to assignment
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7599
TEST.END_NOTES:
TEST.VALUE:E2E_P01.E2E_ProcessDeltaCounter.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P01.E2E_ProcessDeltaCounter.ConfigPtr[0].SyncCounterInit:<<MIN>>
TEST.VALUE:E2E_P01.E2E_ProcessDeltaCounter.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P01.E2E_ProcessDeltaCounter.StatePtr[0].LastValidCounter:0
TEST.VALUE:E2E_P01.E2E_ProcessDeltaCounter.StatePtr[0].MaxDeltaCounter:2
TEST.VALUE:E2E_P01.E2E_ProcessDeltaCounter.StatePtr[0].SyncCounter:2
TEST.VALUE:E2E_P01.E2E_ProcessDeltaCounter.ReceivedCounter:2
TEST.END

-- Test Case: DeltaCounterEquals2and>MaxDeltaCounter
TEST.UNIT:E2E_P01
TEST.SUBPROGRAM:E2E_ProcessDeltaCounter
TEST.NEW
TEST.NAME:DeltaCounterEquals2and>MaxDeltaCounter
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (DeltaCounter == 0U) ==> FALSE
      (3) if (DeltaCounter == 1U) ==> FALSE
      (4) if (DeltaCounter <= StatePtr->MaxDeltaCounter) ==> FALSE
      (5) if (StatePtr->SyncCounter > 0U) ==> FALSE
   Test Case Generation Notes:
      Cannot set DeltaCounter due to assignment
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7599
TEST.END_NOTES:
TEST.VALUE:E2E_P01.E2E_ProcessDeltaCounter.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P01.E2E_ProcessDeltaCounter.ConfigPtr[0].SyncCounterInit:<<MIN>>
TEST.VALUE:E2E_P01.E2E_ProcessDeltaCounter.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P01.E2E_ProcessDeltaCounter.StatePtr[0].LastValidCounter:0
TEST.VALUE:E2E_P01.E2E_ProcessDeltaCounter.StatePtr[0].MaxDeltaCounter:0
TEST.VALUE:E2E_P01.E2E_ProcessDeltaCounter.StatePtr[0].SyncCounter:1
TEST.VALUE:E2E_P01.E2E_ProcessDeltaCounter.ReceivedCounter:2
TEST.END

-- Test Case: DeltaCounterEquals_RepeatedDeltaCounter>MAX
TEST.UNIT:E2E_P01
TEST.SUBPROGRAM:E2E_ProcessDeltaCounter
TEST.NEW
TEST.NAME:DeltaCounterEquals_RepeatedDeltaCounter>MAX
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (DeltaCounter == 0U) ==> FALSE
      (3) if (DeltaCounter == 1U) ==> FALSE
      (4) if (DeltaCounter <= StatePtr->MaxDeltaCounter) ==> FALSE
      (5) if (StatePtr->SyncCounter > 0U) ==> FALSE
   Test Case Generation Notes:
      Cannot set DeltaCounter due to assignment
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7599
TEST.END_NOTES:
TEST.VALUE:E2E_P01.E2E_ProcessDeltaCounter.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P01.E2E_ProcessDeltaCounter.ConfigPtr[0].MaxNoNewOrRepeatedData:1
TEST.VALUE:E2E_P01.E2E_ProcessDeltaCounter.ConfigPtr[0].SyncCounterInit:<<MIN>>
TEST.VALUE:E2E_P01.E2E_ProcessDeltaCounter.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P01.E2E_ProcessDeltaCounter.StatePtr[0].LastValidCounter:0
TEST.VALUE:E2E_P01.E2E_ProcessDeltaCounter.StatePtr[0].MaxDeltaCounter:<<MIN>>
TEST.VALUE:E2E_P01.E2E_ProcessDeltaCounter.StatePtr[0].NoNewOrRepeatedDataCounter:14
TEST.VALUE:E2E_P01.E2E_ProcessDeltaCounter.ReceivedCounter:0
TEST.END

-- Subprogram: E2E_UpdateSyncStatus

-- Test Case: E2E_UpdateSyncStatus.001
TEST.UNIT:E2E_P01
TEST.SUBPROGRAM:E2E_UpdateSyncStatus
TEST.NEW
TEST.NAME:E2E_UpdateSyncStatus.001
TEST.NOTES:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7599
TEST.END_NOTES:
TEST.VALUE:E2E_P01.E2E_UpdateSyncStatus.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P01.E2E_UpdateSyncStatus.ConfigPtr[0].MaxNoNewOrRepeatedData:0
TEST.VALUE:E2E_P01.E2E_UpdateSyncStatus.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P01.E2E_UpdateSyncStatus.StatePtr[0].NoNewOrRepeatedDataCounter:1
TEST.END

-- Unit: E2E_P02

-- Subprogram: E2E_CalculateDeltaCounter

-- Test Case: E2E_CalculateDeltaCounter.001
TEST.UNIT:E2E_P02
TEST.SUBPROGRAM:E2E_CalculateDeltaCounter
TEST.NEW
TEST.NAME:E2E_CalculateDeltaCounter.001
TEST.NOTES:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7601
TEST.END_NOTES:
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].DataLength:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].Offset:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].DataIDList:<<malloc 2>>
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].DataIDList:"1"
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].MaxDeltaCounterInit:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].SyncCounterInit:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].Status:E2E_P02STATUS_NONEWDATA
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].LastValidCounter:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].MaxDeltaCounter:11
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].LostData:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].SyncCounter:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].NoNewOrRepeatedDataCounter:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].WaitForFirstData:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].NewDataAvailable:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ReceivedCounter:2
TEST.EXPECTED:E2E_P02.E2E_CalculateDeltaCounter.ReceivedCounter:2
TEST.END

-- Test Case: E2E_CalculateDeltaCounter.002
TEST.UNIT:E2E_P02
TEST.SUBPROGRAM:E2E_CalculateDeltaCounter
TEST.NEW
TEST.NAME:E2E_CalculateDeltaCounter.002
TEST.NOTES:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7601
TEST.END_NOTES:
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].DataLength:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].Offset:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].DataIDList:<<malloc 2>>
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].DataIDList:"1"
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].MaxDeltaCounterInit:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].SyncCounterInit:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].Status:E2E_P02STATUS_NONEWDATA
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].LastValidCounter:0
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].MaxDeltaCounter:11
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].LostData:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].SyncCounter:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].NoNewOrRepeatedDataCounter:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].WaitForFirstData:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].NewDataAvailable:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ReceivedCounter:128
TEST.EXPECTED:E2E_P02.E2E_CalculateDeltaCounter.ReceivedCounter:128
TEST.END

-- Test Case: E2E_CalculateDeltaCounter.003
TEST.UNIT:E2E_P02
TEST.SUBPROGRAM:E2E_CalculateDeltaCounter
TEST.NEW
TEST.NAME:E2E_CalculateDeltaCounter.003
TEST.NOTES:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7601
TEST.END_NOTES:
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].DataLength:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].Offset:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].DataIDList:<<malloc 2>>
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].DataIDList:"1"
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].MaxDeltaCounterInit:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].SyncCounterInit:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].Status:E2E_P02STATUS_NONEWDATA
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].LastValidCounter:0
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].MaxDeltaCounter:11
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].LostData:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].SyncCounter:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].NoNewOrRepeatedDataCounter:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].WaitForFirstData:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].NewDataAvailable:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ReceivedCounter:100
TEST.EXPECTED:E2E_P02.E2E_CalculateDeltaCounter.ReceivedCounter:100
TEST.END

-- Test Case: E2E_CalculateDeltaCounter.004
TEST.UNIT:E2E_P02
TEST.SUBPROGRAM:E2E_CalculateDeltaCounter
TEST.NEW
TEST.NAME:E2E_CalculateDeltaCounter.004
TEST.NOTES:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7601
TEST.END_NOTES:
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].DataLength:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].Offset:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].DataIDList:<<malloc 2>>
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].DataIDList:"1"
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].MaxDeltaCounterInit:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].SyncCounterInit:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].Status:E2E_P02STATUS_NONEWDATA
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].LastValidCounter:0
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].MaxDeltaCounter:11
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].LostData:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].SyncCounter:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].NoNewOrRepeatedDataCounter:0
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].WaitForFirstData:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].NewDataAvailable:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ReceivedCounter:100
TEST.EXPECTED:E2E_P02.E2E_CalculateDeltaCounter.ReceivedCounter:100
TEST.END

-- Test Case: E2E_CalculateDeltaCounter.005
TEST.UNIT:E2E_P02
TEST.SUBPROGRAM:E2E_CalculateDeltaCounter
TEST.NEW
TEST.NAME:E2E_CalculateDeltaCounter.005
TEST.NOTES:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7601
TEST.END_NOTES:
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].DataLength:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].Offset:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].DataIDList:<<malloc 2>>
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].DataIDList:"1"
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].MaxDeltaCounterInit:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].SyncCounterInit:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].Status:E2E_P02STATUS_NONEWDATA
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].LastValidCounter:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].MaxDeltaCounter:11
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].LostData:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].SyncCounter:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].NoNewOrRepeatedDataCounter:17
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].WaitForFirstData:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].NewDataAvailable:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ReceivedCounter:1
TEST.EXPECTED:E2E_P02.E2E_CalculateDeltaCounter.ReceivedCounter:1
TEST.END

-- Test Case: E2E_CalculateDeltaCounter.006
TEST.UNIT:E2E_P02
TEST.SUBPROGRAM:E2E_CalculateDeltaCounter
TEST.NEW
TEST.NAME:E2E_CalculateDeltaCounter.006
TEST.NOTES:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7601
TEST.END_NOTES:
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].DataLength:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].Offset:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].DataIDList:<<malloc 2>>
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].DataIDList:"1"
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].MaxDeltaCounterInit:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].SyncCounterInit:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].Status:E2E_P02STATUS_NONEWDATA
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].LastValidCounter:17
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].MaxDeltaCounter:11
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].LostData:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].SyncCounter:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].NoNewOrRepeatedDataCounter:17
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].WaitForFirstData:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].NewDataAvailable:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ReceivedCounter:1
TEST.EXPECTED:E2E_P02.E2E_CalculateDeltaCounter.ReceivedCounter:1
TEST.END

-- Test Case: E2E_CalculateDeltaCounter.007
TEST.UNIT:E2E_P02
TEST.SUBPROGRAM:E2E_CalculateDeltaCounter
TEST.NEW
TEST.NAME:E2E_CalculateDeltaCounter.007
TEST.NOTES:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7601
TEST.END_NOTES:
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].DataLength:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].Offset:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].DataIDList:<<malloc 2>>
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].DataIDList:"1"
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].MaxDeltaCounterInit:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].SyncCounterInit:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].Status:E2E_P02STATUS_NONEWDATA
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].LastValidCounter:0
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].MaxDeltaCounter:11
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].LostData:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].SyncCounter:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].NoNewOrRepeatedDataCounter:17
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].WaitForFirstData:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].NewDataAvailable:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ReceivedCounter:1
TEST.EXPECTED:E2E_P02.E2E_CalculateDeltaCounter.ReceivedCounter:1
TEST.END

-- Test Case: E2E_CalculateDeltaCounter.008
TEST.UNIT:E2E_P02
TEST.SUBPROGRAM:E2E_CalculateDeltaCounter
TEST.NEW
TEST.NAME:E2E_CalculateDeltaCounter.008
TEST.NOTES:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7601
TEST.END_NOTES:
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].DataLength:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].Offset:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].DataIDList:<<malloc 2>>
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].DataIDList:"1"
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].MaxDeltaCounterInit:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].MaxNoNewOrRepeatedData:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].SyncCounterInit:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].Status:E2E_P02STATUS_NONEWDATA
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].LastValidCounter:0
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].MaxDeltaCounter:11
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].LostData:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].SyncCounter:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].NoNewOrRepeatedDataCounter:0
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].WaitForFirstData:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].NewDataAvailable:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ReceivedCounter:1
TEST.EXPECTED:E2E_P02.E2E_CalculateDeltaCounter.ReceivedCounter:1
TEST.END

-- Test Case: E2E_CalculateDeltaCounter.009
TEST.UNIT:E2E_P02
TEST.SUBPROGRAM:E2E_CalculateDeltaCounter
TEST.NEW
TEST.NAME:E2E_CalculateDeltaCounter.009
TEST.NOTES:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7601
TEST.END_NOTES:
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].DataLength:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].Offset:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].DataIDList:<<malloc 2>>
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].DataIDList:"1"
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].MaxDeltaCounterInit:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].MaxNoNewOrRepeatedData:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].SyncCounterInit:0
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].Status:E2E_P02STATUS_NONEWDATA
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].LastValidCounter:0
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].MaxDeltaCounter:11
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].LostData:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].SyncCounter:0
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].NoNewOrRepeatedDataCounter:0
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].WaitForFirstData:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].NewDataAvailable:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ReceivedCounter:1
TEST.EXPECTED:E2E_P02.E2E_CalculateDeltaCounter.ReceivedCounter:1
TEST.END

-- Test Case: E2E_CalculateDeltaCounter.010
TEST.UNIT:E2E_P02
TEST.SUBPROGRAM:E2E_CalculateDeltaCounter
TEST.NEW
TEST.NAME:E2E_CalculateDeltaCounter.010
TEST.NOTES:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7601
TEST.END_NOTES:
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].DataLength:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].Offset:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].DataIDList:<<malloc 2>>
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].DataIDList:"1"
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].MaxDeltaCounterInit:10
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].MaxNoNewOrRepeatedData:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].SyncCounterInit:0
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].Status:E2E_P02STATUS_NONEWDATA
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].LastValidCounter:2
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].MaxDeltaCounter:10
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].LostData:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].SyncCounter:0
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].NoNewOrRepeatedDataCounter:0
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].WaitForFirstData:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].NewDataAvailable:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ReceivedCounter:3
TEST.EXPECTED:E2E_P02.E2E_CalculateDeltaCounter.ReceivedCounter:3
TEST.END

-- Test Case: E2E_CalculateDeltaCounter.011
TEST.UNIT:E2E_P02
TEST.SUBPROGRAM:E2E_CalculateDeltaCounter
TEST.NEW
TEST.NAME:E2E_CalculateDeltaCounter.011
TEST.NOTES:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7601
TEST.END_NOTES:
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].DataLength:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].Offset:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].DataIDList:<<malloc 2>>
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].DataIDList:"1"
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].MaxDeltaCounterInit:10
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].MaxNoNewOrRepeatedData:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].SyncCounterInit:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].Status:E2E_P02STATUS_NONEWDATA
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].LastValidCounter:4
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].MaxDeltaCounter:10
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].LostData:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].SyncCounter:0
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].NoNewOrRepeatedDataCounter:0
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].WaitForFirstData:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].NewDataAvailable:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ReceivedCounter:3
TEST.EXPECTED:E2E_P02.E2E_CalculateDeltaCounter.ReceivedCounter:3
TEST.END

-- Test Case: E2E_CalculateDeltaCounter.012
TEST.UNIT:E2E_P02
TEST.SUBPROGRAM:E2E_CalculateDeltaCounter
TEST.NEW
TEST.NAME:E2E_CalculateDeltaCounter.012
TEST.NOTES:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7601
TEST.END_NOTES:
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].DataLength:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].Offset:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].DataIDList:<<malloc 2>>
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].DataIDList:"1"
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].MaxDeltaCounterInit:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].SyncCounterInit:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].Status:E2E_P02STATUS_NONEWDATA
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].LastValidCounter:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].MaxDeltaCounter:11
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].LostData:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].SyncCounter:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].NoNewOrRepeatedDataCounter:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].WaitForFirstData:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].NewDataAvailable:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ReceivedCounter:10
TEST.END

-- Test Case: E2E_CalculateDeltaCounter.013
TEST.UNIT:E2E_P02
TEST.SUBPROGRAM:E2E_CalculateDeltaCounter
TEST.NEW
TEST.NAME:E2E_CalculateDeltaCounter.013
TEST.NOTES:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7601
TEST.END_NOTES:
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].DataLength:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].Offset:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].DataIDList:<<malloc 2>>
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].DataIDList:"1"
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].MaxDeltaCounterInit:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].MaxNoNewOrRepeatedData:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].SyncCounterInit:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].Status:E2E_P02STATUS_NONEWDATA
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].LastValidCounter:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].MaxDeltaCounter:11
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].LostData:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].SyncCounter:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].NoNewOrRepeatedDataCounter:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].WaitForFirstData:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].NewDataAvailable:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ReceivedCounter:10
TEST.END

-- Test Case: E2E_CalculateDeltaCounter.014
TEST.UNIT:E2E_P02
TEST.SUBPROGRAM:E2E_CalculateDeltaCounter
TEST.NEW
TEST.NAME:E2E_CalculateDeltaCounter.014
TEST.NOTES:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7601
TEST.END_NOTES:
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].DataLength:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].Offset:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].DataIDList:<<malloc 2>>
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].DataIDList:"1"
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].MaxDeltaCounterInit:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].MaxNoNewOrRepeatedData:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].SyncCounterInit:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].Status:E2E_P02STATUS_NONEWDATA
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].LastValidCounter:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].MaxDeltaCounter:11
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].LostData:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].SyncCounter:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].NoNewOrRepeatedDataCounter:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].WaitForFirstData:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].NewDataAvailable:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ReceivedCounter:10
TEST.END

-- Test Case: E2E_CalculateDeltaCounter.015
TEST.UNIT:E2E_P02
TEST.SUBPROGRAM:E2E_CalculateDeltaCounter
TEST.NEW
TEST.NAME:E2E_CalculateDeltaCounter.015
TEST.NOTES:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7601
TEST.END_NOTES:
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].DataLength:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].Offset:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].DataIDList:<<malloc 2>>
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].DataIDList:"1"
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].MaxDeltaCounterInit:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].MaxNoNewOrRepeatedData:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].SyncCounterInit:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].Status:E2E_P02STATUS_NONEWDATA
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].LastValidCounter:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].MaxDeltaCounter:11
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].LostData:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].SyncCounter:0
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].NoNewOrRepeatedDataCounter:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].WaitForFirstData:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].NewDataAvailable:1
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ReceivedCounter:10
TEST.END

-- Test Case: E2E_CalculateDeltaCounter.016
TEST.UNIT:E2E_P02
TEST.SUBPROGRAM:E2E_CalculateDeltaCounter
TEST.NEW
TEST.NAME:E2E_CalculateDeltaCounter.016
TEST.NOTES:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7601
TEST.END_NOTES:
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].DataLength:2
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].Offset:3
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].DataIDList:<<malloc 2>>
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].DataIDList:"1"
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].MaxDeltaCounterInit:5
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].SyncCounterInit:6
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].Status:E2E_P02STATUS_OK
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].LastValidCounter:20
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].MaxDeltaCounter:7
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].LostData:6
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].SyncCounter:8
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].NoNewOrRepeatedDataCounter:4
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].WaitForFirstData:4
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].NewDataAvailable:8
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ReceivedCounter:10
TEST.END

-- Test Case: E2E_CalculateDeltaCounter.017
TEST.UNIT:E2E_P02
TEST.SUBPROGRAM:E2E_CalculateDeltaCounter
TEST.NEW
TEST.NAME:E2E_CalculateDeltaCounter.017
TEST.NOTES:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7601
TEST.END_NOTES:
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].DataLength:2
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].Offset:3
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].DataIDList:<<malloc 2>>
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].DataIDList:"1"
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].MaxDeltaCounterInit:5
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ConfigPtr[0].SyncCounterInit:6
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].Status:E2E_P02STATUS_OK
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].LastValidCounter:250
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].MaxDeltaCounter:7
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].LostData:6
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].SyncCounter:8
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].NoNewOrRepeatedDataCounter:4
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].WaitForFirstData:4
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.StatePtr[0].NewDataAvailable:8
TEST.VALUE:E2E_P02.E2E_CalculateDeltaCounter.ReceivedCounter:5
TEST.END

-- Subprogram: E2E_P02Check

-- Test Case: BASIS-PATH-001
TEST.UNIT:E2E_P02
TEST.SUBPROGRAM:E2E_P02Check
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 6
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (StatePtr->MaxDeltaCounter < 15U) ==> FALSE
      (2) if (0U != StatePtr->NewDataAvailable) ==> FALSE
      (5) if (StatePtr->NoNewOrRepeatedDataCounter < 15U) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7601
TEST.END_NOTES:
TEST.VALUE:E2E_P02.E2E_P02Check.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P02.E2E_P02Check.ConfigPtr[0].DataLength:0
TEST.VALUE:E2E_P02.E2E_P02Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P02.E2E_P02Check.StatePtr[0].MaxDeltaCounter:<<MAX>>
TEST.VALUE:E2E_P02.E2E_P02Check.StatePtr[0].NoNewOrRepeatedDataCounter:<<MAX>>
TEST.VALUE:E2E_P02.E2E_P02Check.StatePtr[0].NewDataAvailable:0
TEST.VALUE:E2E_P02.E2E_P02Check.DataPtr:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:E2E_P02
TEST.SUBPROGRAM:E2E_P02Check
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 6
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (StatePtr->MaxDeltaCounter < 15U) ==> FALSE
      (2) if (0U != StatePtr->NewDataAvailable) ==> FALSE
      (5) if (StatePtr->NoNewOrRepeatedDataCounter < 15U) ==> TRUE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7601
TEST.END_NOTES:
TEST.VALUE:E2E_P02.E2E_P02Check.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P02.E2E_P02Check.ConfigPtr[0].DataLength:8
TEST.VALUE:E2E_P02.E2E_P02Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P02.E2E_P02Check.StatePtr[0].MaxDeltaCounter:<<MAX>>
TEST.VALUE:E2E_P02.E2E_P02Check.StatePtr[0].NoNewOrRepeatedDataCounter:<<MIN>>
TEST.VALUE:E2E_P02.E2E_P02Check.StatePtr[0].NewDataAvailable:0
TEST.VALUE:E2E_P02.E2E_P02Check.DataPtr:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-003
TEST.UNIT:E2E_P02
TEST.SUBPROGRAM:E2E_P02Check
TEST.NEW
TEST.NAME:BASIS-PATH-003
TEST.BASIS_PATH:3 of 6
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (StatePtr->MaxDeltaCounter < 15U) ==> FALSE
      (2) if (0U != StatePtr->NewDataAvailable) ==> TRUE
      (3) if (ReceivedCRC == CRCValue) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7601
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.Crc_CalculateCRC8H2F.return:1
TEST.VALUE:E2E_P02.E2E_P02Check.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P02.E2E_P02Check.ConfigPtr[0].DataLength:8
TEST.VALUE:E2E_P02.E2E_P02Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P02.E2E_P02Check.StatePtr[0].MaxDeltaCounter:<<MAX>>
TEST.VALUE:E2E_P02.E2E_P02Check.StatePtr[0].NewDataAvailable:1
TEST.VALUE:E2E_P02.E2E_P02Check.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_P02.E2E_P02Check.DataPtr[0]:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-003.001
TEST.UNIT:E2E_P02
TEST.SUBPROGRAM:E2E_P02Check
TEST.NEW
TEST.NAME:BASIS-PATH-003.001
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (StatePtr->MaxDeltaCounter < 15U) ==> FALSE
      (2) if (0U != StatePtr->NewDataAvailable) ==> TRUE
      (3) if (ReceivedCRC == CRCValue) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7601
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.Crc_CalculateCRC8H2F.return:1
TEST.VALUE:E2E_P02.E2E_P02Check.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P02.E2E_P02Check.ConfigPtr[0].DataLength:0
TEST.VALUE:E2E_P02.E2E_P02Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P02.E2E_P02Check.StatePtr[0].MaxDeltaCounter:<<MAX>>
TEST.VALUE:E2E_P02.E2E_P02Check.StatePtr[0].NewDataAvailable:1
TEST.VALUE:E2E_P02.E2E_P02Check.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_P02.E2E_P02Check.DataPtr[0]:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-004
TEST.UNIT:E2E_P02
TEST.SUBPROGRAM:E2E_P02Check
TEST.NEW
TEST.NAME:BASIS-PATH-004
TEST.BASIS_PATH:4 of 6
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if (StatePtr->MaxDeltaCounter < 15U) ==> FALSE
      (2) if (0U != StatePtr->NewDataAvailable) ==> TRUE
      (3) if (ReceivedCRC == CRCValue) ==> TRUE
      (4) if (StatePtr->WaitForFirstData == 0U) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7601
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.Crc_CalculateCRC8H2F.return:<<MIN>>
TEST.VALUE:E2E_P02.E2E_P02Check.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P02.E2E_P02Check.ConfigPtr[0].DataLength:8
TEST.VALUE:E2E_P02.E2E_P02Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P02.E2E_P02Check.StatePtr[0].MaxDeltaCounter:<<MAX>>
TEST.VALUE:E2E_P02.E2E_P02Check.StatePtr[0].WaitForFirstData:1
TEST.VALUE:E2E_P02.E2E_P02Check.StatePtr[0].NewDataAvailable:1
TEST.VALUE:E2E_P02.E2E_P02Check.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_P02.E2E_P02Check.DataPtr[0]:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-005
TEST.UNIT:E2E_P02
TEST.SUBPROGRAM:E2E_P02Check
TEST.NEW
TEST.NAME:BASIS-PATH-005
TEST.BASIS_PATH:5 of 6
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (1) if (StatePtr->MaxDeltaCounter < 15U) ==> FALSE
      (2) if (0U != StatePtr->NewDataAvailable) ==> TRUE
      (3) if (ReceivedCRC == CRCValue) ==> TRUE
      (4) if (StatePtr->WaitForFirstData == 0U) ==> TRUE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7601
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.Crc_CalculateCRC8H2F.return:<<MIN>>
TEST.VALUE:E2E_P02.E2E_P02Check.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P02.E2E_P02Check.ConfigPtr[0].DataLength:8
TEST.VALUE:E2E_P02.E2E_P02Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P02.E2E_P02Check.StatePtr[0].MaxDeltaCounter:<<MAX>>
TEST.VALUE:E2E_P02.E2E_P02Check.StatePtr[0].WaitForFirstData:0
TEST.VALUE:E2E_P02.E2E_P02Check.StatePtr[0].NewDataAvailable:1
TEST.VALUE:E2E_P02.E2E_P02Check.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_P02.E2E_P02Check.DataPtr[0]:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-006
TEST.UNIT:E2E_P02
TEST.SUBPROGRAM:E2E_P02Check
TEST.NEW
TEST.NAME:BASIS-PATH-006
TEST.BASIS_PATH:6 of 6
TEST.NOTES:
This is an automatically generated test case.
   Test Path 6
      (1) if (StatePtr->MaxDeltaCounter < 15U) ==> TRUE
      (2) if (0U != StatePtr->NewDataAvailable) ==> FALSE
      (5) if (StatePtr->NoNewOrRepeatedDataCounter < 15U) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7601
TEST.END_NOTES:
TEST.VALUE:E2E_P02.E2E_P02Check.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P02.E2E_P02Check.ConfigPtr[0].DataLength:8
TEST.VALUE:E2E_P02.E2E_P02Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P02.E2E_P02Check.StatePtr[0].MaxDeltaCounter:<<MIN>>
TEST.VALUE:E2E_P02.E2E_P02Check.StatePtr[0].NoNewOrRepeatedDataCounter:<<MAX>>
TEST.VALUE:E2E_P02.E2E_P02Check.StatePtr[0].NewDataAvailable:0
TEST.VALUE:E2E_P02.E2E_P02Check.DataPtr:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-007
TEST.UNIT:E2E_P02
TEST.SUBPROGRAM:E2E_P02Check
TEST.NEW
TEST.NAME:BASIS-PATH-007
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (StatePtr->MaxDeltaCounter < 15U) ==> FALSE
      (2) if (0U != StatePtr->NewDataAvailable) ==> FALSE
      (5) if (StatePtr->NoNewOrRepeatedDataCounter < 15U) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7601
TEST.END_NOTES:
TEST.VALUE:E2E_P02.E2E_P02Check.ConfigPtr:<<null>>
TEST.VALUE:E2E_P02.E2E_P02Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P02.E2E_P02Check.StatePtr[0].MaxDeltaCounter:<<MAX>>
TEST.VALUE:E2E_P02.E2E_P02Check.StatePtr[0].NoNewOrRepeatedDataCounter:<<MAX>>
TEST.VALUE:E2E_P02.E2E_P02Check.StatePtr[0].NewDataAvailable:0
TEST.VALUE:E2E_P02.E2E_P02Check.DataPtr:<<malloc 1>>
TEST.END

-- Subprogram: E2E_P02CheckInit

-- Test Case: E2E_P02CheckInit.001
TEST.UNIT:E2E_P02
TEST.SUBPROGRAM:E2E_P02CheckInit
TEST.NEW
TEST.NAME:E2E_P02CheckInit.001
TEST.NOTES:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7601
TEST.END_NOTES:
TEST.VALUE:E2E_P02.E2E_P02CheckInit.StatePtr:<<malloc 1>>
TEST.EXPECTED:E2E_P02.E2E_P02CheckInit.StatePtr[0].WaitForFirstData:TRUE
TEST.EXPECTED:E2E_P02.E2E_P02CheckInit.return:0
TEST.END

-- Test Case: E2E_P02CheckInit.002
TEST.UNIT:E2E_P02
TEST.SUBPROGRAM:E2E_P02CheckInit
TEST.NEW
TEST.NAME:E2E_P02CheckInit.002
TEST.NOTES:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7601
TEST.END_NOTES:
TEST.END

-- Subprogram: E2E_P02MapStatusToSM

-- Test Case: BASIS-PATH-001
TEST.UNIT:E2E_P02
TEST.SUBPROGRAM:E2E_P02MapStatusToSM
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 12
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (1U != CheckReturn) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7601
TEST.END_NOTES:
TEST.VALUE:E2E_P02.E2E_P02MapStatusToSM.CheckReturn:1
TEST.VALUE:E2E_P02.E2E_P02MapStatusToSM.Status:<<MIN>>
TEST.VALUE:E2E_P02.E2E_P02MapStatusToSM.profileBehavior:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:E2E_P02
TEST.SUBPROGRAM:E2E_P02MapStatusToSM
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 12
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (1U != CheckReturn) ==> TRUE
      (2) if (Status == (E2E_P02STATUS_OK)) ==> FALSE
      (3) if (Status == (E2E_P02STATUS_NONEWDATA)) ==> FALSE
      (4) if (Status == (E2E_P02STATUS_WRONGCRC)) ==> FALSE
      (5) if (Status == (E2E_P02STATUS_SYNC)) ==> FALSE
      (7) if (Status == (E2E_P02STATUS_INITIAL)) ==> FALSE
      (9) if (Status == (E2E_P02STATUS_REPEATED)) ==> FALSE
      (10) if (Status == (E2E_P02STATUS_OKSOMELOST)) ==> FALSE
      (11) if (Status == (E2E_P02STATUS_WRONGSEQUENCE)) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7601
TEST.END_NOTES:
TEST.VALUE:E2E_P02.E2E_P02MapStatusToSM.CheckReturn:<<MIN>>
TEST.VALUE:E2E_P02.E2E_P02MapStatusToSM.Status:65
TEST.VALUE:E2E_P02.E2E_P02MapStatusToSM.profileBehavior:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-003
TEST.UNIT:E2E_P02
TEST.SUBPROGRAM:E2E_P02MapStatusToSM
TEST.NEW
TEST.NAME:BASIS-PATH-003
TEST.BASIS_PATH:3 of 12
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (1U != CheckReturn) ==> TRUE
      (2) if (Status == (E2E_P02STATUS_OK)) ==> FALSE
      (3) if (Status == (E2E_P02STATUS_NONEWDATA)) ==> FALSE
      (4) if (Status == (E2E_P02STATUS_WRONGCRC)) ==> FALSE
      (5) if (Status == (E2E_P02STATUS_SYNC)) ==> FALSE
      (7) if (Status == (E2E_P02STATUS_INITIAL)) ==> FALSE
      (9) if (Status == (E2E_P02STATUS_REPEATED)) ==> FALSE
      (10) if (Status == (E2E_P02STATUS_OKSOMELOST)) ==> FALSE
      (11) if (Status == (E2E_P02STATUS_WRONGSEQUENCE)) ==> TRUE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7601
TEST.END_NOTES:
TEST.VALUE:E2E_P02.E2E_P02MapStatusToSM.CheckReturn:<<MIN>>
TEST.VALUE:E2E_P02.E2E_P02MapStatusToSM.Status:E2E_P02STATUS_WRONGSEQUENCE
TEST.VALUE:E2E_P02.E2E_P02MapStatusToSM.profileBehavior:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-004
TEST.UNIT:E2E_P02
TEST.SUBPROGRAM:E2E_P02MapStatusToSM
TEST.NEW
TEST.NAME:BASIS-PATH-004
TEST.BASIS_PATH:4 of 12
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if (1U != CheckReturn) ==> TRUE
      (2) if (Status == (E2E_P02STATUS_OK)) ==> FALSE
      (3) if (Status == (E2E_P02STATUS_NONEWDATA)) ==> FALSE
      (4) if (Status == (E2E_P02STATUS_WRONGCRC)) ==> FALSE
      (5) if (Status == (E2E_P02STATUS_SYNC)) ==> FALSE
      (7) if (Status == (E2E_P02STATUS_INITIAL)) ==> FALSE
      (9) if (Status == (E2E_P02STATUS_REPEATED)) ==> FALSE
      (10) if (Status == (E2E_P02STATUS_OKSOMELOST)) ==> TRUE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7601
TEST.END_NOTES:
TEST.VALUE:E2E_P02.E2E_P02MapStatusToSM.CheckReturn:<<MIN>>
TEST.VALUE:E2E_P02.E2E_P02MapStatusToSM.Status:E2E_P02STATUS_OKSOMELOST
TEST.VALUE:E2E_P02.E2E_P02MapStatusToSM.profileBehavior:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-005
TEST.UNIT:E2E_P02
TEST.SUBPROGRAM:E2E_P02MapStatusToSM
TEST.NEW
TEST.NAME:BASIS-PATH-005
TEST.BASIS_PATH:5 of 12
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (1) if (1U != CheckReturn) ==> TRUE
      (2) if (Status == (E2E_P02STATUS_OK)) ==> FALSE
      (3) if (Status == (E2E_P02STATUS_NONEWDATA)) ==> FALSE
      (4) if (Status == (E2E_P02STATUS_WRONGCRC)) ==> FALSE
      (5) if (Status == (E2E_P02STATUS_SYNC)) ==> FALSE
      (7) if (Status == (E2E_P02STATUS_INITIAL)) ==> FALSE
      (9) if (Status == (E2E_P02STATUS_REPEATED)) ==> TRUE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7601
TEST.END_NOTES:
TEST.VALUE:E2E_P02.E2E_P02MapStatusToSM.CheckReturn:<<MIN>>
TEST.VALUE:E2E_P02.E2E_P02MapStatusToSM.Status:E2E_P02STATUS_REPEATED
TEST.VALUE:E2E_P02.E2E_P02MapStatusToSM.profileBehavior:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-006
TEST.UNIT:E2E_P02
TEST.SUBPROGRAM:E2E_P02MapStatusToSM
TEST.NEW
TEST.NAME:BASIS-PATH-006
TEST.BASIS_PATH:6 of 12
TEST.NOTES:
This is an automatically generated test case.
   Test Path 6
      (1) if (1U != CheckReturn) ==> TRUE
      (2) if (Status == (E2E_P02STATUS_OK)) ==> FALSE
      (3) if (Status == (E2E_P02STATUS_NONEWDATA)) ==> FALSE
      (4) if (Status == (E2E_P02STATUS_WRONGCRC)) ==> FALSE
      (5) if (Status == (E2E_P02STATUS_SYNC)) ==> FALSE
      (7) if (Status == (E2E_P02STATUS_INITIAL)) ==> TRUE
      (8) if (0U == profileBehavior) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7601
TEST.END_NOTES:
TEST.VALUE:E2E_P02.E2E_P02MapStatusToSM.CheckReturn:<<MIN>>
TEST.VALUE:E2E_P02.E2E_P02MapStatusToSM.Status:E2E_P02STATUS_INITIAL
TEST.VALUE:E2E_P02.E2E_P02MapStatusToSM.profileBehavior:1
TEST.END

-- Test Case: BASIS-PATH-007
TEST.UNIT:E2E_P02
TEST.SUBPROGRAM:E2E_P02MapStatusToSM
TEST.NEW
TEST.NAME:BASIS-PATH-007
TEST.BASIS_PATH:7 of 12
TEST.NOTES:
This is an automatically generated test case.
   Test Path 7
      (1) if (1U != CheckReturn) ==> TRUE
      (2) if (Status == (E2E_P02STATUS_OK)) ==> FALSE
      (3) if (Status == (E2E_P02STATUS_NONEWDATA)) ==> FALSE
      (4) if (Status == (E2E_P02STATUS_WRONGCRC)) ==> FALSE
      (5) if (Status == (E2E_P02STATUS_SYNC)) ==> FALSE
      (7) if (Status == (E2E_P02STATUS_INITIAL)) ==> TRUE
      (8) if (0U == profileBehavior) ==> TRUE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7601
TEST.END_NOTES:
TEST.VALUE:E2E_P02.E2E_P02MapStatusToSM.CheckReturn:<<MIN>>
TEST.VALUE:E2E_P02.E2E_P02MapStatusToSM.Status:E2E_P02STATUS_INITIAL
TEST.VALUE:E2E_P02.E2E_P02MapStatusToSM.profileBehavior:0
TEST.END

-- Test Case: BASIS-PATH-008
TEST.UNIT:E2E_P02
TEST.SUBPROGRAM:E2E_P02MapStatusToSM
TEST.NEW
TEST.NAME:BASIS-PATH-008
TEST.BASIS_PATH:8 of 12
TEST.NOTES:
This is an automatically generated test case.
   Test Path 8
      (1) if (1U != CheckReturn) ==> TRUE
      (2) if (Status == (E2E_P02STATUS_OK)) ==> FALSE
      (3) if (Status == (E2E_P02STATUS_NONEWDATA)) ==> FALSE
      (4) if (Status == (E2E_P02STATUS_WRONGCRC)) ==> FALSE
      (5) if (Status == (E2E_P02STATUS_SYNC)) ==> TRUE
      (6) if (0U == profileBehavior) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7601
TEST.END_NOTES:
TEST.VALUE:E2E_P02.E2E_P02MapStatusToSM.CheckReturn:<<MIN>>
TEST.VALUE:E2E_P02.E2E_P02MapStatusToSM.Status:E2E_P02STATUS_SYNC
TEST.VALUE:E2E_P02.E2E_P02MapStatusToSM.profileBehavior:1
TEST.END

-- Test Case: BASIS-PATH-009
TEST.UNIT:E2E_P02
TEST.SUBPROGRAM:E2E_P02MapStatusToSM
TEST.NEW
TEST.NAME:BASIS-PATH-009
TEST.BASIS_PATH:9 of 12
TEST.NOTES:
This is an automatically generated test case.
   Test Path 9
      (1) if (1U != CheckReturn) ==> TRUE
      (2) if (Status == (E2E_P02STATUS_OK)) ==> FALSE
      (3) if (Status == (E2E_P02STATUS_NONEWDATA)) ==> FALSE
      (4) if (Status == (E2E_P02STATUS_WRONGCRC)) ==> FALSE
      (5) if (Status == (E2E_P02STATUS_SYNC)) ==> TRUE
      (6) if (0U == profileBehavior) ==> TRUE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7601
TEST.END_NOTES:
TEST.VALUE:E2E_P02.E2E_P02MapStatusToSM.CheckReturn:<<MIN>>
TEST.VALUE:E2E_P02.E2E_P02MapStatusToSM.Status:E2E_P02STATUS_SYNC
TEST.VALUE:E2E_P02.E2E_P02MapStatusToSM.profileBehavior:0
TEST.END

-- Test Case: BASIS-PATH-010
TEST.UNIT:E2E_P02
TEST.SUBPROGRAM:E2E_P02MapStatusToSM
TEST.NEW
TEST.NAME:BASIS-PATH-010
TEST.BASIS_PATH:10 of 12
TEST.NOTES:
This is an automatically generated test case.
   Test Path 10
      (1) if (1U != CheckReturn) ==> TRUE
      (2) if (Status == (E2E_P02STATUS_OK)) ==> FALSE
      (3) if (Status == (E2E_P02STATUS_NONEWDATA)) ==> FALSE
      (4) if (Status == (E2E_P02STATUS_WRONGCRC)) ==> TRUE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7601
TEST.END_NOTES:
TEST.VALUE:E2E_P02.E2E_P02MapStatusToSM.CheckReturn:<<MIN>>
TEST.VALUE:E2E_P02.E2E_P02MapStatusToSM.Status:E2E_P02STATUS_WRONGCRC
TEST.VALUE:E2E_P02.E2E_P02MapStatusToSM.profileBehavior:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-011
TEST.UNIT:E2E_P02
TEST.SUBPROGRAM:E2E_P02MapStatusToSM
TEST.NEW
TEST.NAME:BASIS-PATH-011
TEST.BASIS_PATH:11 of 12
TEST.NOTES:
This is an automatically generated test case.
   Test Path 11
      (1) if (1U != CheckReturn) ==> TRUE
      (2) if (Status == (E2E_P02STATUS_OK)) ==> FALSE
      (3) if (Status == (E2E_P02STATUS_NONEWDATA)) ==> TRUE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7601
TEST.END_NOTES:
TEST.VALUE:E2E_P02.E2E_P02MapStatusToSM.CheckReturn:<<MIN>>
TEST.VALUE:E2E_P02.E2E_P02MapStatusToSM.Status:E2E_P02STATUS_NONEWDATA
TEST.VALUE:E2E_P02.E2E_P02MapStatusToSM.profileBehavior:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-012
TEST.UNIT:E2E_P02
TEST.SUBPROGRAM:E2E_P02MapStatusToSM
TEST.NEW
TEST.NAME:BASIS-PATH-012
TEST.BASIS_PATH:12 of 12
TEST.NOTES:
This is an automatically generated test case.
   Test Path 12
      (1) if (1U != CheckReturn) ==> TRUE
      (2) if (Status == (E2E_P02STATUS_OK)) ==> TRUE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7601
TEST.END_NOTES:
TEST.VALUE:E2E_P02.E2E_P02MapStatusToSM.CheckReturn:<<MIN>>
TEST.VALUE:E2E_P02.E2E_P02MapStatusToSM.Status:E2E_P02STATUS_OK
TEST.VALUE:E2E_P02.E2E_P02MapStatusToSM.profileBehavior:<<MIN>>
TEST.END

-- Subprogram: E2E_P02Protect

-- Test Case: ConfigPtrDataLengthEquals0
TEST.UNIT:E2E_P02
TEST.SUBPROGRAM:E2E_P02Protect
TEST.NEW
TEST.NAME:ConfigPtrDataLengthEquals0
TEST.NOTES:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7601
TEST.END_NOTES:
TEST.VALUE:E2E_P02.E2E_P02Protect.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P02.E2E_P02Protect.ConfigPtr[0].DataLength:0
TEST.VALUE:E2E_P02.E2E_P02Protect.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P02.E2E_P02Protect.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_P02.E2E_P02Protect.return:0
TEST.EXPECTED:E2E_P02.E2E_P02Protect.return:0
TEST.END

-- Test Case: ConfigPtrEquals0
TEST.UNIT:E2E_P02
TEST.SUBPROGRAM:E2E_P02Protect
TEST.NEW
TEST.NAME:ConfigPtrEquals0
TEST.NOTES:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7601
TEST.END_NOTES:
TEST.VALUE:E2E_P02.E2E_P02Protect.ConfigPtr:<<null>>
TEST.EXPECTED:E2E_P02.E2E_P02Protect.return:19
TEST.END

-- Test Case: Counter>Max
TEST.UNIT:E2E_P02
TEST.SUBPROGRAM:E2E_P02Protect
TEST.NEW
TEST.NAME:Counter>Max
TEST.BASIS_PATH:2 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (StatePtr->Counter >= 0xf) ==> TRUE
   Test Case Generation Notes:
      Cannot set StatePtr->Counter due to assignment
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7601
TEST.END_NOTES:
TEST.VALUE:E2E_P02.E2E_P02Protect.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P02.E2E_P02Protect.ConfigPtr[0].DataLength:8
TEST.VALUE:E2E_P02.E2E_P02Protect.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P02.E2E_P02Protect.StatePtr[0].Counter:15
TEST.VALUE:E2E_P02.E2E_P02Protect.DataPtr:<<malloc 1>>
TEST.EXPECTED:E2E_P02.E2E_P02Protect.return:0
TEST.END

-- Test Case: Inputs!=NULL
TEST.UNIT:E2E_P02
TEST.SUBPROGRAM:E2E_P02Protect
TEST.NEW
TEST.NAME:Inputs!=NULL
TEST.BASIS_PATH:1 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (StatePtr->Counter >= 0xf) ==> FALSE
   Test Case Generation Notes:
      Cannot set StatePtr->Counter due to assignment
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7601
TEST.END_NOTES:
TEST.VALUE:E2E_P02.E2E_P02Protect.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P02.E2E_P02Protect.ConfigPtr[0].DataLength:8
TEST.VALUE:E2E_P02.E2E_P02Protect.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P02.E2E_P02Protect.DataPtr:<<malloc 1>>
TEST.EXPECTED:E2E_P02.E2E_P02Protect.return:0
TEST.END

-- Subprogram: E2E_P02ProtectInit

-- Test Case: E2E_P02ProtectInit.001
TEST.UNIT:E2E_P02
TEST.SUBPROGRAM:E2E_P02ProtectInit
TEST.NEW
TEST.NAME:E2E_P02ProtectInit.001
TEST.NOTES:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7601
TEST.END_NOTES:
TEST.VALUE:E2E_P02.E2E_P02ProtectInit.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P02.E2E_P02ProtectInit.StatePtr[0].Counter:0
TEST.EXPECTED:E2E_P02.E2E_P02ProtectInit.return:0
TEST.END

-- Test Case: E2E_P02ProtectInit.002
TEST.UNIT:E2E_P02
TEST.SUBPROGRAM:E2E_P02ProtectInit
TEST.NEW
TEST.NAME:E2E_P02ProtectInit.002
TEST.NOTES:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7601
TEST.END_NOTES:
TEST.END

-- Unit: E2E_P04

-- Subprogram: E2E_P04Check

-- Test Case: ComputedCRC=ReceivedCRC
TEST.UNIT:E2E_P04
TEST.SUBPROGRAM:E2E_P04Check
TEST.NEW
TEST.NAME:ComputedCRC=ReceivedCRC
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (ConfigPtr != (void *)0 && StatePtr != (void *)0) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7602
TEST.END_NOTES:
TEST.VALUE:E2E_P04.E2E_P04Check.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P04.E2E_P04Check.ConfigPtr[0].DataID:4294967295
TEST.VALUE:E2E_P04.E2E_P04Check.ConfigPtr[0].Offset:0
TEST.VALUE:E2E_P04.E2E_P04Check.ConfigPtr[0].MinDataLength:0
TEST.VALUE:E2E_P04.E2E_P04Check.ConfigPtr[0].MaxDataLength:15
TEST.VALUE:E2E_P04.E2E_P04Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr:<<malloc 13>>
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[0]:255
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[1]:255
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[2]:255
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[3]:255
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[4]:255
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[5]:255
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[6]:255
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[7]:255
TEST.VALUE:E2E_P04.E2E_P04Check.Length:14
TEST.END

-- Test Case: ConfigPtr=NULL
TEST.UNIT:E2E_P04
TEST.SUBPROGRAM:E2E_P04Check
TEST.NEW
TEST.NAME:ConfigPtr=NULL
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (ConfigPtr != (void *)0 && StatePtr != (void *)0) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7602
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.Crc_CalculateCRC32P4.return:1
TEST.VALUE:E2E_P04.E2E_P04Check.ConfigPtr:<<null>>
TEST.VALUE:E2E_P04.E2E_P04Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_P04.E2E_P04Check.Length:14
TEST.EXPECTED:E2E_P04.E2E_P04Check.return:19
TEST.END

-- Test Case: DataPtrEqualsNULL
TEST.UNIT:E2E_P04
TEST.SUBPROGRAM:E2E_P04Check
TEST.NEW
TEST.NAME:DataPtrEqualsNULL
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (ConfigPtr != (void *)0 && StatePtr != (void *)0) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7602

TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.Crc_CalculateCRC32P4.return:1
TEST.VALUE:E2E_P04.E2E_P04Check.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P04.E2E_P04Check.ConfigPtr[0].MinDataLength:0
TEST.VALUE:E2E_P04.E2E_P04Check.ConfigPtr[0].MaxDataLength:15
TEST.VALUE:E2E_P04.E2E_P04Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr:<<malloc 9>>
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr:<<null>>
TEST.VALUE:E2E_P04.E2E_P04Check.Length:0
TEST.EXPECTED:E2E_P04.E2E_P04Check.return:0
TEST.END

-- Test Case: Inputs!=NULL
TEST.UNIT:E2E_P04
TEST.SUBPROGRAM:E2E_P04Check
TEST.NEW
TEST.NAME:Inputs!=NULL
TEST.BASIS_PATH:1 of 11
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (ConfigPtr != (void *)0 && StatePtr != (void *)0) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7602
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.Crc_CalculateCRC32P4.return:1
TEST.VALUE:E2E_P04.E2E_P04Check.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P04.E2E_P04Check.ConfigPtr[0].MinDataLength:0
TEST.VALUE:E2E_P04.E2E_P04Check.ConfigPtr[0].MaxDataLength:15
TEST.VALUE:E2E_P04.E2E_P04Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_P04.E2E_P04Check.Length:14
TEST.EXPECTED:E2E_P04.E2E_P04Check.return:0
TEST.END

-- Test Case: Length<MaxDataLength
TEST.UNIT:E2E_P04
TEST.SUBPROGRAM:E2E_P04Check
TEST.NEW
TEST.NAME:Length<MaxDataLength
TEST.BASIS_PATH:3 of 11
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (ConfigPtr != (void *)0 && StatePtr != (void *)0) ==> TRUE
      (2) if (DataPtr != (void *)0 && Length != 0U || DataPtr == (void *)0 && Length == 0U) ==> TRUE
      (3) if (DataPtr != (void *)0) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7602
TEST.END_NOTES:
TEST.VALUE:E2E_P04.E2E_P04Check.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P04.E2E_P04Check.ConfigPtr[0].MaxDataLength:15
TEST.VALUE:E2E_P04.E2E_P04Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_P04.E2E_P04Check.Length:16
TEST.EXPECTED:E2E_P04.E2E_P04Check.return:23
TEST.END

-- Test Case: Length=0
TEST.UNIT:E2E_P04
TEST.SUBPROGRAM:E2E_P04Check
TEST.NEW
TEST.NAME:Length=0
TEST.BASIS_PATH:4 of 11
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if (ConfigPtr != (void *)0 && StatePtr != (void *)0) ==> TRUE
      (2) if (DataPtr != (void *)0 && Length != 0U || DataPtr == (void *)0 && Length == 0U) ==> TRUE
      (3) if (DataPtr != (void *)0) ==> TRUE
      (4) if (Length >= ConfigPtr->MinDataLength && Length <= ConfigPtr->MaxDataLength) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7602
TEST.END_NOTES:
TEST.VALUE:E2E_P04.E2E_P04Check.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P04.E2E_P04Check.ConfigPtr[0].MinDataLength:<<MAX>>
TEST.VALUE:E2E_P04.E2E_P04Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_P04.E2E_P04Check.Length:<<MIN>>
TEST.EXPECTED:E2E_P04.E2E_P04Check.return:23
TEST.END

-- Test Case: Offset!>Length
TEST.UNIT:E2E_P04
TEST.SUBPROGRAM:E2E_P04Check
TEST.NEW
TEST.NAME:Offset!>Length
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (ConfigPtr != (void *)0 && StatePtr != (void *)0) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7602
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.Crc_CalculateCRC32P4.return:1
TEST.VALUE:E2E_P04.E2E_P04Check.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P04.E2E_P04Check.ConfigPtr[0].Offset:0
TEST.VALUE:E2E_P04.E2E_P04Check.ConfigPtr[0].MinDataLength:0
TEST.VALUE:E2E_P04.E2E_P04Check.ConfigPtr[0].MaxDataLength:15
TEST.VALUE:E2E_P04.E2E_P04Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_P04.E2E_P04Check.Length:5
TEST.EXPECTED:E2E_P04.E2E_P04Check.return:0
TEST.END

-- Test Case: ReceivedDataId!=DataID
TEST.UNIT:E2E_P04
TEST.SUBPROGRAM:E2E_P04Check
TEST.NEW
TEST.NAME:ReceivedDataId!=DataID
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (ConfigPtr != (void *)0 && StatePtr != (void *)0) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7602
TEST.END_NOTES:
TEST.VALUE:E2E_P04.E2E_P04Check.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P04.E2E_P04Check.ConfigPtr[0].DataID:0
TEST.VALUE:E2E_P04.E2E_P04Check.ConfigPtr[0].Offset:0
TEST.VALUE:E2E_P04.E2E_P04Check.ConfigPtr[0].MinDataLength:0
TEST.VALUE:E2E_P04.E2E_P04Check.ConfigPtr[0].MaxDataLength:15
TEST.VALUE:E2E_P04.E2E_P04Check.ConfigPtr[0].MaxDeltaCounter:1
TEST.VALUE:E2E_P04.E2E_P04Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr:<<malloc 12>>
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[0]:0
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[1]:0
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[2]:0
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[3]:0
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[4]:0
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[5]:0
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[6]:0
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[7]:0
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[8]:0
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[9]:0
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[10]:0
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[11]:0
TEST.VALUE:E2E_P04.E2E_P04Check.Length:14
TEST.END

-- Test Case: ReceivedDataId!=DataID.001
TEST.UNIT:E2E_P04
TEST.SUBPROGRAM:E2E_P04Check
TEST.NEW
TEST.NAME:ReceivedDataId!=DataID.001
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (ConfigPtr != (void *)0 && StatePtr != (void *)0) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7602
TEST.END_NOTES:
TEST.VALUE:E2E_P04.E2E_P04Check.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P04.E2E_P04Check.ConfigPtr[0].DataID:0
TEST.VALUE:E2E_P04.E2E_P04Check.ConfigPtr[0].Offset:0
TEST.VALUE:E2E_P04.E2E_P04Check.ConfigPtr[0].MinDataLength:0
TEST.VALUE:E2E_P04.E2E_P04Check.ConfigPtr[0].MaxDataLength:15
TEST.VALUE:E2E_P04.E2E_P04Check.ConfigPtr[0].MaxDeltaCounter:1
TEST.VALUE:E2E_P04.E2E_P04Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr:<<malloc 13>>
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[0]:0
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[1]:0
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[2]:0
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[3]:0
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[4]:0
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[5]:0
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[6]:0
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[7]:0
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[8]:0
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[9]:0
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[10]:0
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[11]:0
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[12]:0
TEST.VALUE:E2E_P04.E2E_P04Check.Length:0
TEST.END

-- Test Case: ReceivedDataId!=DataID.002
TEST.UNIT:E2E_P04
TEST.SUBPROGRAM:E2E_P04Check
TEST.NEW
TEST.NAME:ReceivedDataId!=DataID.002
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (ConfigPtr != (void *)0 && StatePtr != (void *)0) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7602
TEST.END_NOTES:
TEST.VALUE:E2E_P04.E2E_P04Check.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P04.E2E_P04Check.ConfigPtr[0].DataID:0
TEST.VALUE:E2E_P04.E2E_P04Check.ConfigPtr[0].Offset:0
TEST.VALUE:E2E_P04.E2E_P04Check.ConfigPtr[0].MinDataLength:0
TEST.VALUE:E2E_P04.E2E_P04Check.ConfigPtr[0].MaxDataLength:15
TEST.VALUE:E2E_P04.E2E_P04Check.ConfigPtr[0].MaxDeltaCounter:1
TEST.VALUE:E2E_P04.E2E_P04Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr:<<malloc 12>>
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[0]:0
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[1]:0
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[2]:0
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[3]:0
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[4]:0
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[5]:0
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[6]:0
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[7]:5
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[8]:0
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[9]:0
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[10]:0
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[11]:0
TEST.VALUE:E2E_P04.E2E_P04Check.Length:14
TEST.END

-- Test Case: ReceivedLength=Length
TEST.UNIT:E2E_P04
TEST.SUBPROGRAM:E2E_P04Check
TEST.NEW
TEST.NAME:ReceivedLength=Length
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (ConfigPtr != (void *)0 && StatePtr != (void *)0) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7602
TEST.END_NOTES:
TEST.VALUE:E2E_P04.E2E_P04Check.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P04.E2E_P04Check.ConfigPtr[0].DataID:4294967295
TEST.VALUE:E2E_P04.E2E_P04Check.ConfigPtr[0].Offset:0
TEST.VALUE:E2E_P04.E2E_P04Check.ConfigPtr[0].MinDataLength:0
TEST.VALUE:E2E_P04.E2E_P04Check.ConfigPtr[0].MaxDataLength:15
TEST.VALUE:E2E_P04.E2E_P04Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr:<<malloc 12>>
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[0]:14
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[1]:0
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[2]:1
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[3]:0
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[4]:255
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[5]:255
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[6]:255
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[7]:255
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[8]:0
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[9]:0
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[10]:0
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[11]:0
TEST.VALUE:E2E_P04.E2E_P04Check.Length:14
TEST.END

-- Test Case: ReceivedLength=Length.002
TEST.UNIT:E2E_P04
TEST.SUBPROGRAM:E2E_P04Check
TEST.NEW
TEST.NAME:ReceivedLength=Length.002
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (ConfigPtr != (void *)0 && StatePtr != (void *)0) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7602
TEST.END_NOTES:
TEST.VALUE:E2E_P04.E2E_P04Check.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P04.E2E_P04Check.ConfigPtr[0].DataID:4294967295
TEST.VALUE:E2E_P04.E2E_P04Check.ConfigPtr[0].Offset:0
TEST.VALUE:E2E_P04.E2E_P04Check.ConfigPtr[0].MinDataLength:0
TEST.VALUE:E2E_P04.E2E_P04Check.ConfigPtr[0].MaxDataLength:15
TEST.VALUE:E2E_P04.E2E_P04Check.ConfigPtr[0].MaxDeltaCounter:10
TEST.VALUE:E2E_P04.E2E_P04Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr:<<malloc 13>>
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[0]:14
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[1]:0
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[2]:5
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[3]:0
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[4]:255
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[5]:255
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[6]:255
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[7]:255
TEST.VALUE:E2E_P04.E2E_P04Check.Length:14
TEST.END

-- Test Case: ReceivedLength=Length.003
TEST.UNIT:E2E_P04
TEST.SUBPROGRAM:E2E_P04Check
TEST.NEW
TEST.NAME:ReceivedLength=Length.003
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (ConfigPtr != (void *)0 && StatePtr != (void *)0) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7602
TEST.END_NOTES:
TEST.VALUE:E2E_P04.E2E_P04Check.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P04.E2E_P04Check.ConfigPtr[0].DataID:4294967295
TEST.VALUE:E2E_P04.E2E_P04Check.ConfigPtr[0].Offset:0
TEST.VALUE:E2E_P04.E2E_P04Check.ConfigPtr[0].MinDataLength:0
TEST.VALUE:E2E_P04.E2E_P04Check.ConfigPtr[0].MaxDataLength:15
TEST.VALUE:E2E_P04.E2E_P04Check.ConfigPtr[0].MaxDeltaCounter:10
TEST.VALUE:E2E_P04.E2E_P04Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P04.E2E_P04Check.StatePtr[0].Counter:5
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr:<<malloc 13>>
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[0]:14
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[1]:0
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[2]:5
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[3]:0
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[4]:255
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[5]:255
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[6]:255
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[7]:255
TEST.VALUE:E2E_P04.E2E_P04Check.Length:14
TEST.END

-- Test Case: ReceivedLength=Length.004
TEST.UNIT:E2E_P04
TEST.SUBPROGRAM:E2E_P04Check
TEST.NEW
TEST.NAME:ReceivedLength=Length.004
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (ConfigPtr != (void *)0 && StatePtr != (void *)0) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7602
TEST.END_NOTES:
TEST.VALUE:E2E_P04.E2E_P04Check.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P04.E2E_P04Check.ConfigPtr[0].DataID:4294967295
TEST.VALUE:E2E_P04.E2E_P04Check.ConfigPtr[0].Offset:0
TEST.VALUE:E2E_P04.E2E_P04Check.ConfigPtr[0].MinDataLength:0
TEST.VALUE:E2E_P04.E2E_P04Check.ConfigPtr[0].MaxDataLength:15
TEST.VALUE:E2E_P04.E2E_P04Check.ConfigPtr[0].MaxDeltaCounter:10
TEST.VALUE:E2E_P04.E2E_P04Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P04.E2E_P04Check.StatePtr[0].Counter:4
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr:<<malloc 13>>
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[0]:14
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[1]:0
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[2]:5
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[3]:0
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[4]:255
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[5]:255
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[6]:255
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[7]:255
TEST.VALUE:E2E_P04.E2E_P04Check.Length:14
TEST.END

-- Test Case: ReceivedLength=Length.005
TEST.UNIT:E2E_P04
TEST.SUBPROGRAM:E2E_P04Check
TEST.NEW
TEST.NAME:ReceivedLength=Length.005
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (ConfigPtr != (void *)0 && StatePtr != (void *)0) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7602
TEST.END_NOTES:
TEST.STUB:E2E_P04.dataget
TEST.VALUE:uut_prototype_stubs.Crc_CalculateCRC32P4.return:2
TEST.VALUE:E2E_P04.dataget.DataPtr[0]:1
TEST.VALUE:E2E_P04.dataget.return:2
TEST.VALUE:E2E_P04.E2E_P04Check.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P04.E2E_P04Check.ConfigPtr[0].DataID:2
TEST.VALUE:E2E_P04.E2E_P04Check.ConfigPtr[0].Offset:0
TEST.VALUE:E2E_P04.E2E_P04Check.ConfigPtr[0].MinDataLength:0
TEST.VALUE:E2E_P04.E2E_P04Check.ConfigPtr[0].MaxDataLength:15
TEST.VALUE:E2E_P04.E2E_P04Check.ConfigPtr[0].MaxDeltaCounter:10
TEST.VALUE:E2E_P04.E2E_P04Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P04.E2E_P04Check.StatePtr[0].Counter:4
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr:<<malloc 13>>
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[0]:14
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[1]:0
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[2]:5
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[3]:0
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[4]:255
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[5]:255
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[6]:255
TEST.VALUE:E2E_P04.E2E_P04Check.DataPtr[7]:255
TEST.VALUE:E2E_P04.E2E_P04Check.Length:2
TEST.END

-- Subprogram: E2E_P04CheckInit

-- Test Case: StatePtr!=NULL
TEST.UNIT:E2E_P04
TEST.SUBPROGRAM:E2E_P04CheckInit
TEST.NEW
TEST.NAME:StatePtr!=NULL
TEST.BASIS_PATH:1 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (StatePtr != (void *)0) ==> TRUE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7602
TEST.END_NOTES:
TEST.VALUE:E2E_P04.E2E_P04CheckInit.StatePtr:<<malloc 1>>
TEST.EXPECTED:E2E_P04.E2E_P04CheckInit.return:0
TEST.END

-- Test Case: StatePtr==NULL
TEST.UNIT:E2E_P04
TEST.SUBPROGRAM:E2E_P04CheckInit
TEST.NEW
TEST.NAME:StatePtr==NULL
TEST.BASIS_PATH:2 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (StatePtr != (void *)0) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7602
TEST.END_NOTES:
TEST.VALUE:E2E_P04.E2E_P04CheckInit.StatePtr:<<null>>
TEST.EXPECTED:E2E_P04.E2E_P04CheckInit.return:19
TEST.END

-- Subprogram: E2E_P04MapStatusToSM

-- Test Case: CheckReturn=E_NOT_OK
TEST.UNIT:E2E_P04
TEST.SUBPROGRAM:E2E_P04MapStatusToSM
TEST.NEW
TEST.NAME:CheckReturn=E_NOT_OK
TEST.BASIS_PATH:1 of 7
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (1U != CheckReturn) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7602
TEST.END_NOTES:
TEST.VALUE:E2E_P04.E2E_P04MapStatusToSM.CheckReturn:1
TEST.VALUE:E2E_P04.E2E_P04MapStatusToSM.Status:<<MIN>>
TEST.EXPECTED:E2E_P04.E2E_P04MapStatusToSM.return:E2E_P_ERROR
TEST.END

-- Test Case: Status=P04_STATUSWRONGSEQUENCE
TEST.UNIT:E2E_P04
TEST.SUBPROGRAM:E2E_P04MapStatusToSM
TEST.NEW
TEST.NAME:Status=P04_STATUSWRONGSEQUENCE
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (1U != CheckReturn) ==> TRUE
      (2) if (Status == (E2E_P04STATUS_OK || E2E_P04STATUS_OKSOMELOST)) ==> FALSE
      (3) if (Status == (E2E_P04STATUS_ERROR)) ==> FALSE
      (4) if (Status == (E2E_P04STATUS_REPEATED)) ==> FALSE
      (5) if (Status == (E2E_P04STATUS_NONEWDATA)) ==> FALSE
      (6) if (Status == (E2E_P04STATUS_WRONGSEQUENCE)) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7602
TEST.END_NOTES:
TEST.VALUE:E2E_P04.E2E_P04MapStatusToSM.CheckReturn:0
TEST.VALUE:E2E_P04.E2E_P04MapStatusToSM.Status:E2E_P04STATUS_WRONGSEQUENCE
TEST.EXPECTED:E2E_P04.E2E_P04MapStatusToSM.return:E2E_P_WRONGSEQUENCE
TEST.END

-- Test Case: Status=P04_STATUS_ERROR
TEST.UNIT:E2E_P04
TEST.SUBPROGRAM:E2E_P04MapStatusToSM
TEST.NEW
TEST.NAME:Status=P04_STATUS_ERROR
TEST.BASIS_PATH:2 of 7
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (1U != CheckReturn) ==> TRUE
      (2) if (Status == (E2E_P04STATUS_OK || E2E_P04STATUS_OKSOMELOST)) ==> FALSE
      (3) if (Status == (E2E_P04STATUS_ERROR)) ==> FALSE
      (4) if (Status == (E2E_P04STATUS_REPEATED)) ==> FALSE
      (5) if (Status == (E2E_P04STATUS_NONEWDATA)) ==> FALSE
      (6) if (Status == (E2E_P04STATUS_WRONGSEQUENCE)) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7602
TEST.END_NOTES:
TEST.VALUE:E2E_P04.E2E_P04MapStatusToSM.CheckReturn:0
TEST.VALUE:E2E_P04.E2E_P04MapStatusToSM.Status:E2E_P04STATUS_ERROR
TEST.VALUE:E2E_P04.E2E_P04MapStatusToSM.return:E2E_P_ERROR
TEST.EXPECTED:E2E_P04.E2E_P04MapStatusToSM.return:E2E_P_ERROR
TEST.END

-- Test Case: Status=P04_STATUS_NONEWDATA
TEST.UNIT:E2E_P04
TEST.SUBPROGRAM:E2E_P04MapStatusToSM
TEST.NEW
TEST.NAME:Status=P04_STATUS_NONEWDATA
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (1U != CheckReturn) ==> TRUE
      (2) if (Status == (E2E_P04STATUS_OK || E2E_P04STATUS_OKSOMELOST)) ==> FALSE
      (3) if (Status == (E2E_P04STATUS_ERROR)) ==> FALSE
      (4) if (Status == (E2E_P04STATUS_REPEATED)) ==> FALSE
      (5) if (Status == (E2E_P04STATUS_NONEWDATA)) ==> FALSE
      (6) if (Status == (E2E_P04STATUS_WRONGSEQUENCE)) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7602
TEST.END_NOTES:
TEST.VALUE:E2E_P04.E2E_P04MapStatusToSM.CheckReturn:0
TEST.VALUE:E2E_P04.E2E_P04MapStatusToSM.Status:E2E_P04STATUS_NONEWDATA
TEST.EXPECTED:E2E_P04.E2E_P04MapStatusToSM.return:E2E_P_NONEWDATA
TEST.END

-- Test Case: Status=P04_STATUS_OKSOMELOST
TEST.UNIT:E2E_P04
TEST.SUBPROGRAM:E2E_P04MapStatusToSM
TEST.NEW
TEST.NAME:Status=P04_STATUS_OKSOMELOST
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (1U != CheckReturn) ==> TRUE
      (2) if (Status == (E2E_P04STATUS_OK || E2E_P04STATUS_OKSOMELOST)) ==> FALSE
      (3) if (Status == (E2E_P04STATUS_ERROR)) ==> FALSE
      (4) if (Status == (E2E_P04STATUS_REPEATED)) ==> FALSE
      (5) if (Status == (E2E_P04STATUS_NONEWDATA)) ==> FALSE
      (6) if (Status == (E2E_P04STATUS_WRONGSEQUENCE)) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7602
TEST.END_NOTES:
TEST.VALUE:E2E_P04.E2E_P04MapStatusToSM.CheckReturn:0
TEST.VALUE:E2E_P04.E2E_P04MapStatusToSM.Status:E2E_P04STATUS_OKSOMELOST
TEST.VALUE:E2E_P04.E2E_P04MapStatusToSM.return:E2E_P_OK
TEST.EXPECTED:E2E_P04.E2E_P04MapStatusToSM.return:E2E_P_OK
TEST.END

-- Test Case: Status=P04_STATUS_P_OK
TEST.UNIT:E2E_P04
TEST.SUBPROGRAM:E2E_P04MapStatusToSM
TEST.NEW
TEST.NAME:Status=P04_STATUS_P_OK
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (1U != CheckReturn) ==> TRUE
      (2) if (Status == (E2E_P04STATUS_OK || E2E_P04STATUS_OKSOMELOST)) ==> FALSE
      (3) if (Status == (E2E_P04STATUS_ERROR)) ==> FALSE
      (4) if (Status == (E2E_P04STATUS_REPEATED)) ==> FALSE
      (5) if (Status == (E2E_P04STATUS_NONEWDATA)) ==> FALSE
      (6) if (Status == (E2E_P04STATUS_WRONGSEQUENCE)) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7602
TEST.END_NOTES:
TEST.VALUE:E2E_P04.E2E_P04MapStatusToSM.CheckReturn:0
TEST.VALUE:E2E_P04.E2E_P04MapStatusToSM.Status:E2E_P04STATUS_OK
TEST.VALUE:E2E_P04.E2E_P04MapStatusToSM.return:E2E_P_OK
TEST.EXPECTED:E2E_P04.E2E_P04MapStatusToSM.return:E2E_P_OK
TEST.END

-- Test Case: Status=P04_STATUS_REPEATED
TEST.UNIT:E2E_P04
TEST.SUBPROGRAM:E2E_P04MapStatusToSM
TEST.NEW
TEST.NAME:Status=P04_STATUS_REPEATED
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (1U != CheckReturn) ==> TRUE
      (2) if (Status == (E2E_P04STATUS_OK || E2E_P04STATUS_OKSOMELOST)) ==> FALSE
      (3) if (Status == (E2E_P04STATUS_ERROR)) ==> FALSE
      (4) if (Status == (E2E_P04STATUS_REPEATED)) ==> FALSE
      (5) if (Status == (E2E_P04STATUS_NONEWDATA)) ==> FALSE
      (6) if (Status == (E2E_P04STATUS_WRONGSEQUENCE)) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7602
TEST.END_NOTES:
TEST.VALUE:E2E_P04.E2E_P04MapStatusToSM.CheckReturn:0
TEST.VALUE:E2E_P04.E2E_P04MapStatusToSM.Status:E2E_P04STATUS_REPEATED
TEST.VALUE:E2E_P04.E2E_P04MapStatusToSM.return:E2E_P_REPEATED
TEST.EXPECTED:E2E_P04.E2E_P04MapStatusToSM.return:E2E_P_REPEATED
TEST.END

-- Test Case: Status=P04_STATUS_REPEATED.001
TEST.UNIT:E2E_P04
TEST.SUBPROGRAM:E2E_P04MapStatusToSM
TEST.NEW
TEST.NAME:Status=P04_STATUS_REPEATED.001
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (1U != CheckReturn) ==> TRUE
      (2) if (Status == (E2E_P04STATUS_OK || E2E_P04STATUS_OKSOMELOST)) ==> FALSE
      (3) if (Status == (E2E_P04STATUS_ERROR)) ==> FALSE
      (4) if (Status == (E2E_P04STATUS_REPEATED)) ==> FALSE
      (5) if (Status == (E2E_P04STATUS_NONEWDATA)) ==> FALSE
      (6) if (Status == (E2E_P04STATUS_WRONGSEQUENCE)) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7602
TEST.END_NOTES:
TEST.VALUE:E2E_P04.E2E_P04MapStatusToSM.CheckReturn:0
TEST.VALUE:E2E_P04.E2E_P04MapStatusToSM.Status:10
TEST.VALUE:E2E_P04.E2E_P04MapStatusToSM.return:E2E_P_ERROR
TEST.EXPECTED:E2E_P04.E2E_P04MapStatusToSM.return:E2E_P_ERROR
TEST.END

-- Subprogram: E2E_P04Protect

-- Test Case: ConfigPtrisNULL
TEST.UNIT:E2E_P04
TEST.SUBPROGRAM:E2E_P04Protect
TEST.NEW
TEST.NAME:ConfigPtrisNULL
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((ConfigPtr != (void *)0 && StatePtr != (void *)0) && DataPtr != (void *)0) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7602
TEST.END_NOTES:
TEST.VALUE:E2E_P04.E2E_P04Protect.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P04.E2E_P04Protect.ConfigPtr[0].DataID:0
TEST.VALUE:E2E_P04.E2E_P04Protect.ConfigPtr[0].Offset:0
TEST.VALUE:E2E_P04.E2E_P04Protect.ConfigPtr[0].MinDataLength:0
TEST.VALUE:E2E_P04.E2E_P04Protect.ConfigPtr[0].MaxDataLength:0
TEST.VALUE:E2E_P04.E2E_P04Protect.ConfigPtr[0].MaxDeltaCounter:0
TEST.VALUE:E2E_P04.E2E_P04Protect.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P04.E2E_P04Protect.StatePtr[0].Counter:65535
TEST.VALUE:E2E_P04.E2E_P04Protect.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_P04.E2E_P04Protect.Length:14
TEST.EXPECTED:E2E_P04.E2E_P04Protect.return:23
TEST.END

-- Test Case: ConfigPtrisNULL.001
TEST.UNIT:E2E_P04
TEST.SUBPROGRAM:E2E_P04Protect
TEST.NEW
TEST.NAME:ConfigPtrisNULL.001
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((ConfigPtr != (void *)0 && StatePtr != (void *)0) && DataPtr != (void *)0) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7602
TEST.END_NOTES:
TEST.VALUE:E2E_P04.E2E_P04Protect.Length:0
TEST.VALUE:E2E_P04.E2E_P04Protect.return:19
TEST.EXPECTED:E2E_P04.E2E_P04Protect.Length:0
TEST.EXPECTED:E2E_P04.E2E_P04Protect.return:19
TEST.END

-- Test Case: Inputs!=NULL
TEST.UNIT:E2E_P04
TEST.SUBPROGRAM:E2E_P04Protect
TEST.NEW
TEST.NAME:Inputs!=NULL
TEST.BASIS_PATH:1 of 5
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((ConfigPtr != (void *)0 && StatePtr != (void *)0) && DataPtr != (void *)0) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7602
TEST.END_NOTES:
TEST.VALUE:E2E_P04.E2E_P04Protect.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P04.E2E_P04Protect.ConfigPtr[0].MinDataLength:0
TEST.VALUE:E2E_P04.E2E_P04Protect.ConfigPtr[0].MaxDataLength:15
TEST.VALUE:E2E_P04.E2E_P04Protect.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P04.E2E_P04Protect.StatePtr[0].Counter:65535
TEST.VALUE:E2E_P04.E2E_P04Protect.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_P04.E2E_P04Protect.Length:14
TEST.EXPECTED:E2E_P04.E2E_P04Protect.return:0
TEST.END

-- Test Case: Inputs!=NULL.001
TEST.UNIT:E2E_P04
TEST.SUBPROGRAM:E2E_P04Protect
TEST.NEW
TEST.NAME:Inputs!=NULL.001
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((ConfigPtr != (void *)0 && StatePtr != (void *)0) && DataPtr != (void *)0) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7602
TEST.END_NOTES:
TEST.VALUE:E2E_P04.E2E_P04Protect.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P04.E2E_P04Protect.ConfigPtr[0].MinDataLength:0
TEST.VALUE:E2E_P04.E2E_P04Protect.ConfigPtr[0].MaxDataLength:15
TEST.VALUE:E2E_P04.E2E_P04Protect.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P04.E2E_P04Protect.StatePtr[0].Counter:65510
TEST.VALUE:E2E_P04.E2E_P04Protect.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_P04.E2E_P04Protect.Length:14
TEST.EXPECTED:E2E_P04.E2E_P04Protect.return:0
TEST.END

-- Test Case: Length>MaxLength
TEST.UNIT:E2E_P04
TEST.SUBPROGRAM:E2E_P04Protect
TEST.NEW
TEST.NAME:Length>MaxLength
TEST.NOTES:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7602
TEST.END_NOTES:
TEST.VALUE:E2E_P04.E2E_P04Protect.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P04.E2E_P04Protect.ConfigPtr[0].MinDataLength:0
TEST.VALUE:E2E_P04.E2E_P04Protect.ConfigPtr[0].MaxDataLength:15
TEST.VALUE:E2E_P04.E2E_P04Protect.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P04.E2E_P04Protect.StatePtr[0].Counter:65534
TEST.VALUE:E2E_P04.E2E_P04Protect.DataPtr:<<malloc 2>>
TEST.VALUE:E2E_P04.E2E_P04Protect.DataPtr:"1"
TEST.VALUE:E2E_P04.E2E_P04Protect.Length:25
TEST.EXPECTED:E2E_P04.E2E_P04Protect.return:23
TEST.END

-- Test Case: LengthforCRCcalc
TEST.UNIT:E2E_P04
TEST.SUBPROGRAM:E2E_P04Protect
TEST.NEW
TEST.NAME:LengthforCRCcalc
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((ConfigPtr != (void *)0 && StatePtr != (void *)0) && DataPtr != (void *)0) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7602
TEST.END_NOTES:
TEST.VALUE:E2E_P04.E2E_P04Protect.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P04.E2E_P04Protect.ConfigPtr[0].MinDataLength:0
TEST.VALUE:E2E_P04.E2E_P04Protect.ConfigPtr[0].MaxDataLength:15
TEST.VALUE:E2E_P04.E2E_P04Protect.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P04.E2E_P04Protect.StatePtr[0].Counter:65535
TEST.VALUE:E2E_P04.E2E_P04Protect.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_P04.E2E_P04Protect.Length:12
TEST.END

-- Test Case: MaxCounterReached
TEST.UNIT:E2E_P04
TEST.SUBPROGRAM:E2E_P04Protect
TEST.NEW
TEST.NAME:MaxCounterReached
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((ConfigPtr != (void *)0 && StatePtr != (void *)0) && DataPtr != (void *)0) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7602
TEST.END_NOTES:
TEST.VALUE:E2E_P04.E2E_P04Protect.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P04.E2E_P04Protect.ConfigPtr[0].MinDataLength:0
TEST.VALUE:E2E_P04.E2E_P04Protect.ConfigPtr[0].MaxDataLength:15
TEST.VALUE:E2E_P04.E2E_P04Protect.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P04.E2E_P04Protect.StatePtr[0].Counter:65534
TEST.VALUE:E2E_P04.E2E_P04Protect.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_P04.E2E_P04Protect.Length:14
TEST.EXPECTED:E2E_P04.E2E_P04Protect.return:0
TEST.END

-- Subprogram: E2E_P04ProtectInit

-- Test Case: StatePtr!=NULL
TEST.UNIT:E2E_P04
TEST.SUBPROGRAM:E2E_P04ProtectInit
TEST.NEW
TEST.NAME:StatePtr!=NULL
TEST.BASIS_PATH:2 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (StatePtr != (void *)0) ==> TRUE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7602
TEST.END_NOTES:
TEST.VALUE:E2E_P04.E2E_P04ProtectInit.StatePtr:<<malloc 1>>
TEST.EXPECTED:E2E_P04.E2E_P04ProtectInit.return:0
TEST.END

-- Test Case: StatePtr==NULL
TEST.UNIT:E2E_P04
TEST.SUBPROGRAM:E2E_P04ProtectInit
TEST.NEW
TEST.NAME:StatePtr==NULL
TEST.BASIS_PATH:1 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (StatePtr != (void *)0) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7602
TEST.END_NOTES:
TEST.VALUE:E2E_P04.E2E_P04ProtectInit.StatePtr:<<null>>
TEST.EXPECTED:E2E_P04.E2E_P04ProtectInit.return:19
TEST.END

-- Unit: E2E_P05

-- Subprogram: E2E_P05Check

-- Test Case: ConfigPtr&StatePtr=NULL
TEST.UNIT:E2E_P05
TEST.SUBPROGRAM:E2E_P05Check
TEST.NEW
TEST.NAME:ConfigPtr&StatePtr=NULL
TEST.BASIS_PATH:1 of 9
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (ConfigPtr != (void *)0 && StatePtr != (void *)0) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7603
TEST.END_NOTES:
TEST.VALUE:E2E_P05.E2E_P05Check.ConfigPtr:<<null>>
TEST.VALUE:E2E_P05.E2E_P05Check.StatePtr:<<null>>
TEST.VALUE:E2E_P05.E2E_P05Check.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_P05.E2E_P05Check.Length:<<MIN>>
TEST.EXPECTED:E2E_P05.E2E_P05Check.return:19
TEST.END

-- Test Case: DataPtr=NULL
TEST.UNIT:E2E_P05
TEST.SUBPROGRAM:E2E_P05Check
TEST.NEW
TEST.NAME:DataPtr=NULL
TEST.BASIS_PATH:3 of 9
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (ConfigPtr != (void *)0 && StatePtr != (void *)0) ==> TRUE
      (2) if (DataPtr != (void *)0 && Length != 0 || DataPtr == (void *)0 && Length == 0) ==> TRUE
      (3) if (DataPtr != (void *)0) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7603
TEST.END_NOTES:
TEST.VALUE:E2E_P05.E2E_P05Check.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P05.E2E_P05Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P05.E2E_P05Check.DataPtr:<<malloc 9>>
TEST.VALUE:E2E_P05.E2E_P05Check.DataPtr:<<null>>
TEST.VALUE:E2E_P05.E2E_P05Check.Length:1
TEST.END

-- Test Case: DataPtrEqualsNULL
TEST.UNIT:E2E_P05
TEST.SUBPROGRAM:E2E_P05Check
TEST.NEW
TEST.NAME:DataPtrEqualsNULL
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if (ConfigPtr != (void *)0 && StatePtr != (void *)0) ==> TRUE
      (2) if (DataPtr != (void *)0 && Length != 0 || DataPtr == (void *)0 && Length == 0) ==> TRUE
      (3) if (DataPtr != (void *)0) ==> TRUE
      (4) if (Length == ConfigPtr->DataLength) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7603
TEST.END_NOTES:
TEST.VALUE:E2E_P05.E2E_P05Check.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P05.E2E_P05Check.ConfigPtr[0].DataLength:2
TEST.VALUE:E2E_P05.E2E_P05Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P05.E2E_P05Check.DataPtr:<<malloc 9>>
TEST.VALUE:E2E_P05.E2E_P05Check.DataPtr:<<null>>
TEST.VALUE:E2E_P05.E2E_P05Check.Length:0
TEST.END

-- Test Case: InvalidLengthWithOffset0
TEST.UNIT:E2E_P05
TEST.SUBPROGRAM:E2E_P05Check
TEST.NEW
TEST.NAME:InvalidLengthWithOffset0
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if (ConfigPtr != (void *)0 && StatePtr != (void *)0) ==> TRUE
      (2) if (DataPtr != (void *)0 && Length != 0 || DataPtr == (void *)0 && Length == 0) ==> TRUE
      (3) if (DataPtr != (void *)0) ==> TRUE
      (4) if (Length == ConfigPtr->DataLength) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7603
TEST.END_NOTES:
TEST.VALUE:E2E_P05.E2E_P05Check.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P05.E2E_P05Check.ConfigPtr[0].Offset:0
TEST.VALUE:E2E_P05.E2E_P05Check.ConfigPtr[0].DataLength:1
TEST.VALUE:E2E_P05.E2E_P05Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P05.E2E_P05Check.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_P05.E2E_P05Check.Length:1
TEST.END

-- Test Case: InvalidLengthWithOffsetIsNot0
TEST.UNIT:E2E_P05
TEST.SUBPROGRAM:E2E_P05Check
TEST.NEW
TEST.NAME:InvalidLengthWithOffsetIsNot0
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if (ConfigPtr != (void *)0 && StatePtr != (void *)0) ==> TRUE
      (2) if (DataPtr != (void *)0 && Length != 0 || DataPtr == (void *)0 && Length == 0) ==> TRUE
      (3) if (DataPtr != (void *)0) ==> TRUE
      (4) if (Length == ConfigPtr->DataLength) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7603
TEST.END_NOTES:
TEST.VALUE:E2E_P05.E2E_P05Check.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P05.E2E_P05Check.ConfigPtr[0].Offset:1
TEST.VALUE:E2E_P05.E2E_P05Check.ConfigPtr[0].DataLength:1
TEST.VALUE:E2E_P05.E2E_P05Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P05.E2E_P05Check.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_P05.E2E_P05Check.Length:1
TEST.END

-- Test Case: Length!=DataLength
TEST.UNIT:E2E_P05
TEST.SUBPROGRAM:E2E_P05Check
TEST.NEW
TEST.NAME:Length!=DataLength
TEST.BASIS_PATH:4 of 9
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if (ConfigPtr != (void *)0 && StatePtr != (void *)0) ==> TRUE
      (2) if (DataPtr != (void *)0 && Length != 0 || DataPtr == (void *)0 && Length == 0) ==> TRUE
      (3) if (DataPtr != (void *)0) ==> TRUE
      (4) if (Length == ConfigPtr->DataLength) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7603
TEST.END_NOTES:
TEST.VALUE:E2E_P05.E2E_P05Check.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P05.E2E_P05Check.ConfigPtr[0].DataLength:2
TEST.VALUE:E2E_P05.E2E_P05Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P05.E2E_P05Check.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_P05.E2E_P05Check.Length:1
TEST.END

-- Test Case: Length=DataLength
TEST.UNIT:E2E_P05
TEST.SUBPROGRAM:E2E_P05Check
TEST.NEW
TEST.NAME:Length=DataLength
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if (ConfigPtr != (void *)0 && StatePtr != (void *)0) ==> TRUE
      (2) if (DataPtr != (void *)0 && Length != 0 || DataPtr == (void *)0 && Length == 0) ==> TRUE
      (3) if (DataPtr != (void *)0) ==> TRUE
      (4) if (Length == ConfigPtr->DataLength) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7603
TEST.END_NOTES:
TEST.VALUE:E2E_P05.E2E_P05Check.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P05.E2E_P05Check.ConfigPtr[0].Offset:1
TEST.VALUE:E2E_P05.E2E_P05Check.ConfigPtr[0].DataLength:5
TEST.VALUE:E2E_P05.E2E_P05Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P05.E2E_P05Check.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_P05.E2E_P05Check.Length:5
TEST.END

-- Test Case: OffsetEquals0
TEST.UNIT:E2E_P05
TEST.SUBPROGRAM:E2E_P05Check
TEST.NEW
TEST.NAME:OffsetEquals0
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if (ConfigPtr != (void *)0 && StatePtr != (void *)0) ==> TRUE
      (2) if (DataPtr != (void *)0 && Length != 0 || DataPtr == (void *)0 && Length == 0) ==> TRUE
      (3) if (DataPtr != (void *)0) ==> TRUE
      (4) if (Length == ConfigPtr->DataLength) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7603
TEST.END_NOTES:
TEST.VALUE:E2E_P05.E2E_P05Check.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P05.E2E_P05Check.ConfigPtr[0].Offset:0
TEST.VALUE:E2E_P05.E2E_P05Check.ConfigPtr[0].DataLength:5
TEST.VALUE:E2E_P05.E2E_P05Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P05.E2E_P05Check.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_P05.E2E_P05Check.Length:5
TEST.END

-- Test Case: ReceivedCRC!=ComputedCRC
TEST.UNIT:E2E_P05
TEST.SUBPROGRAM:E2E_P05Check
TEST.NEW
TEST.NAME:ReceivedCRC!=ComputedCRC
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if (ConfigPtr != (void *)0 && StatePtr != (void *)0) ==> TRUE
      (2) if (DataPtr != (void *)0 && Length != 0 || DataPtr == (void *)0 && Length == 0) ==> TRUE
      (3) if (DataPtr != (void *)0) ==> TRUE
      (4) if (Length == ConfigPtr->DataLength) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7603
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.Crc_CalculateCRC16.return:65534
TEST.VALUE:E2E_P05.E2E_P05Check.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P05.E2E_P05Check.ConfigPtr[0].Offset:0
TEST.VALUE:E2E_P05.E2E_P05Check.ConfigPtr[0].DataLength:1
TEST.VALUE:E2E_P05.E2E_P05Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P05.E2E_P05Check.DataPtr:<<malloc 2>>
TEST.VALUE:E2E_P05.E2E_P05Check.DataPtr[0]:255
TEST.VALUE:E2E_P05.E2E_P05Check.DataPtr[1]:255
TEST.VALUE:E2E_P05.E2E_P05Check.Length:1
TEST.END

-- Test Case: ReceivedCRC=ComputedCRC
TEST.UNIT:E2E_P05
TEST.SUBPROGRAM:E2E_P05Check
TEST.NEW
TEST.NAME:ReceivedCRC=ComputedCRC
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if (ConfigPtr != (void *)0 && StatePtr != (void *)0) ==> TRUE
      (2) if (DataPtr != (void *)0 && Length != 0 || DataPtr == (void *)0 && Length == 0) ==> TRUE
      (3) if (DataPtr != (void *)0) ==> TRUE
      (4) if (Length == ConfigPtr->DataLength) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7603
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.Crc_CalculateCRC16.return:65535
TEST.VALUE:E2E_P05.E2E_P05Check.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P05.E2E_P05Check.ConfigPtr[0].Offset:0
TEST.VALUE:E2E_P05.E2E_P05Check.ConfigPtr[0].DataLength:1
TEST.VALUE:E2E_P05.E2E_P05Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P05.E2E_P05Check.DataPtr:<<malloc 2>>
TEST.VALUE:E2E_P05.E2E_P05Check.DataPtr[0]:255
TEST.VALUE:E2E_P05.E2E_P05Check.DataPtr[1]:255
TEST.VALUE:E2E_P05.E2E_P05Check.Length:1
TEST.END

-- Subprogram: E2E_P05CheckInit

-- Test Case: StatePtr!=NULL
TEST.UNIT:E2E_P05
TEST.SUBPROGRAM:E2E_P05CheckInit
TEST.NEW
TEST.NAME:StatePtr!=NULL
TEST.BASIS_PATH:1 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (StatePtr != (void *)0) ==> TRUE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7603
TEST.END_NOTES:
TEST.VALUE:E2E_P05.E2E_P05CheckInit.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P05.E2E_P05CheckInit.StatePtr[0].Status:E2E_P05STATUS_ERROR
TEST.VALUE:E2E_P05.E2E_P05CheckInit.StatePtr[0].Counter:0
TEST.EXPECTED:E2E_P05.E2E_P05CheckInit.return:0
TEST.END

-- Test Case: StatePtr==NULL
TEST.UNIT:E2E_P05
TEST.SUBPROGRAM:E2E_P05CheckInit
TEST.NEW
TEST.NAME:StatePtr==NULL
TEST.BASIS_PATH:2 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (StatePtr != (void *)0) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7603
TEST.END_NOTES:
TEST.VALUE:E2E_P05.E2E_P05CheckInit.StatePtr:<<null>>
TEST.EXPECTED:E2E_P05.E2E_P05CheckInit.return:19
TEST.END

-- Subprogram: E2E_P05MapStatusToSM

-- Test Case: CheckReturn=E_NOT_OK
TEST.UNIT:E2E_P05
TEST.SUBPROGRAM:E2E_P05MapStatusToSM
TEST.NEW
TEST.NAME:CheckReturn=E_NOT_OK
TEST.BASIS_PATH:1 of 7
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (1U != CheckReturn) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7603
TEST.END_NOTES:
TEST.VALUE:E2E_P05.E2E_P05MapStatusToSM.CheckReturn:1
TEST.EXPECTED:E2E_P05.E2E_P05MapStatusToSM.return:E2E_P_ERROR
TEST.END

-- Test Case: Status!=P05_STATUSWRONGSEQUENCE
TEST.UNIT:E2E_P05
TEST.SUBPROGRAM:E2E_P05MapStatusToSM
TEST.NEW
TEST.NAME:Status!=P05_STATUSWRONGSEQUENCE
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (1U != CheckReturn) ==> TRUE
      (2) if (Status == (E2E_P05STATUS_OK || E2E_P05STATUS_OKSOMELOST)) ==> TRUE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7603
TEST.END_NOTES:
TEST.VALUE:E2E_P05.E2E_P05MapStatusToSM.CheckReturn:0
TEST.VALUE:E2E_P05.E2E_P05MapStatusToSM.Status:12
TEST.END

-- Test Case: Status=P05_STATUSERROR
TEST.UNIT:E2E_P05
TEST.SUBPROGRAM:E2E_P05MapStatusToSM
TEST.NEW
TEST.NAME:Status=P05_STATUSERROR
TEST.BASIS_PATH:3 of 7
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (1U != CheckReturn) ==> TRUE
      (2) if (Status == (E2E_P05STATUS_OK || E2E_P05STATUS_OKSOMELOST)) ==> FALSE
      (3) if (Status == (E2E_P05STATUS_ERROR)) ==> TRUE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7603
TEST.END_NOTES:
TEST.VALUE:E2E_P05.E2E_P05MapStatusToSM.CheckReturn:0
TEST.VALUE:E2E_P05.E2E_P05MapStatusToSM.Status:E2E_P05STATUS_ERROR
TEST.EXPECTED:E2E_P05.E2E_P05MapStatusToSM.return:E2E_P_ERROR
TEST.END

-- Test Case: Status=P05_STATUSNONEWDATA
TEST.UNIT:E2E_P05
TEST.SUBPROGRAM:E2E_P05MapStatusToSM
TEST.NEW
TEST.NAME:Status=P05_STATUSNONEWDATA
TEST.BASIS_PATH:6 of 7
TEST.NOTES:
This is an automatically generated test case.
   Test Path 6
      (1) if (1U != CheckReturn) ==> TRUE
      (2) if (Status == (E2E_P05STATUS_OK || E2E_P05STATUS_OKSOMELOST)) ==> FALSE
      (3) if (Status == (E2E_P05STATUS_ERROR)) ==> FALSE
      (4) if (Status == (E2E_P05STATUS_REPEATED)) ==> FALSE
      (5) if (Status == (E2E_P05STATUS_NONEWDATA)) ==> FALSE
      (6) if (Status == (E2E_P05STATUS_WRONGSEQUENCE)) ==> TRUE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7603
TEST.END_NOTES:
TEST.VALUE:E2E_P05.E2E_P05MapStatusToSM.CheckReturn:<<MIN>>
TEST.VALUE:E2E_P05.E2E_P05MapStatusToSM.Status:E2E_P05STATUS_NONEWDATA
TEST.EXPECTED:E2E_P05.E2E_P05MapStatusToSM.return:E2E_P_NONEWDATA
TEST.END

-- Test Case: Status=P05_STATUSOK
TEST.UNIT:E2E_P05
TEST.SUBPROGRAM:E2E_P05MapStatusToSM
TEST.NEW
TEST.NAME:Status=P05_STATUSOK
TEST.BASIS_PATH:7 of 7
TEST.NOTES:
This is an automatically generated test case.
   Test Path 7
      (1) if (1U != CheckReturn) ==> TRUE
      (2) if (Status == (E2E_P05STATUS_OK || E2E_P05STATUS_OKSOMELOST)) ==> FALSE
      (3) if (Status == (E2E_P05STATUS_ERROR)) ==> FALSE
      (4) if (Status == (E2E_P05STATUS_REPEATED)) ==> FALSE
      (5) if (Status == (E2E_P05STATUS_NONEWDATA)) ==> FALSE
      (6) if (Status == (E2E_P05STATUS_WRONGSEQUENCE)) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7603
TEST.END_NOTES:
TEST.VALUE:E2E_P05.E2E_P05MapStatusToSM.CheckReturn:<<MIN>>
TEST.VALUE:E2E_P05.E2E_P05MapStatusToSM.Status:E2E_P05STATUS_OK
TEST.EXPECTED:E2E_P05.E2E_P05MapStatusToSM.return:E2E_P_OK
TEST.END

-- Test Case: Status=P05_STATUSOKSOMELOST
TEST.UNIT:E2E_P05
TEST.SUBPROGRAM:E2E_P05MapStatusToSM
TEST.NEW
TEST.NAME:Status=P05_STATUSOKSOMELOST
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (1U != CheckReturn) ==> TRUE
      (2) if (Status == (E2E_P05STATUS_OK || E2E_P05STATUS_OKSOMELOST)) ==> TRUE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7603
TEST.END_NOTES:
TEST.VALUE:E2E_P05.E2E_P05MapStatusToSM.CheckReturn:0
TEST.VALUE:E2E_P05.E2E_P05MapStatusToSM.Status:E2E_P05STATUS_OKSOMELOST
TEST.EXPECTED:E2E_P05.E2E_P05MapStatusToSM.return:E2E_P_OK
TEST.END

-- Test Case: Status=P05_STATUSREPEATED
TEST.UNIT:E2E_P05
TEST.SUBPROGRAM:E2E_P05MapStatusToSM
TEST.NEW
TEST.NAME:Status=P05_STATUSREPEATED
TEST.BASIS_PATH:4 of 7
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if (1U != CheckReturn) ==> TRUE
      (2) if (Status == (E2E_P05STATUS_OK || E2E_P05STATUS_OKSOMELOST)) ==> FALSE
      (3) if (Status == (E2E_P05STATUS_ERROR)) ==> FALSE
      (4) if (Status == (E2E_P05STATUS_REPEATED)) ==> TRUE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7603
TEST.END_NOTES:
TEST.VALUE:E2E_P05.E2E_P05MapStatusToSM.CheckReturn:<<MIN>>
TEST.VALUE:E2E_P05.E2E_P05MapStatusToSM.Status:E2E_P05STATUS_REPEATED
TEST.EXPECTED:E2E_P05.E2E_P05MapStatusToSM.return:E2E_P_REPEATED
TEST.END

-- Test Case: Status=P05_STATUSWRONGSEQUENCE
TEST.UNIT:E2E_P05
TEST.SUBPROGRAM:E2E_P05MapStatusToSM
TEST.NEW
TEST.NAME:Status=P05_STATUSWRONGSEQUENCE
TEST.BASIS_PATH:2 of 7
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (1U != CheckReturn) ==> TRUE
      (2) if (Status == (E2E_P05STATUS_OK || E2E_P05STATUS_OKSOMELOST)) ==> TRUE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7603
TEST.END_NOTES:
TEST.VALUE:E2E_P05.E2E_P05MapStatusToSM.CheckReturn:0
TEST.VALUE:E2E_P05.E2E_P05MapStatusToSM.Status:E2E_P05STATUS_WRONGSEQUENCE
TEST.EXPECTED:E2E_P05.E2E_P05MapStatusToSM.return:E2E_P_WRONGSEQUENCE
TEST.END

-- Subprogram: E2E_P05Protect

-- Test Case: ConfigPtrisNULL
TEST.UNIT:E2E_P05
TEST.SUBPROGRAM:E2E_P05Protect
TEST.NEW
TEST.NAME:ConfigPtrisNULL
TEST.BASIS_PATH:2 of 5
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if ((ConfigPtr != (void *)0 && StatePtr != (void *)0) && DataPtr != (void *)0) ==> TRUE
      (2) if (Length == ConfigPtr->DataLength) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7603
TEST.END_NOTES:
TEST.VALUE:E2E_P05.E2E_P05Protect.ConfigPtr:<<null>>
TEST.VALUE:E2E_P05.E2E_P05Protect.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P05.E2E_P05Protect.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_P05.E2E_P05Protect.Length:<<MIN>>
TEST.EXPECTED:E2E_P05.E2E_P05Protect.return:19
TEST.END

-- Test Case: Counter<MaxValue
TEST.UNIT:E2E_P05
TEST.SUBPROGRAM:E2E_P05Protect
TEST.NEW
TEST.NAME:Counter<MaxValue
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((ConfigPtr != (void *)0 && StatePtr != (void *)0) && DataPtr != (void *)0) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7603
TEST.END_NOTES:
TEST.VALUE:E2E_P05.E2E_P05Protect.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P05.E2E_P05Protect.ConfigPtr[0].Offset:4
TEST.VALUE:E2E_P05.E2E_P05Protect.ConfigPtr[0].DataLength:5
TEST.VALUE:E2E_P05.E2E_P05Protect.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P05.E2E_P05Protect.StatePtr[0].Counter:0
TEST.VALUE:E2E_P05.E2E_P05Protect.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_P05.E2E_P05Protect.Length:5
TEST.EXPECTED:E2E_P05.E2E_P05Protect.return:0
TEST.END

-- Test Case: Inputs!=NULL
TEST.UNIT:E2E_P05
TEST.SUBPROGRAM:E2E_P05Protect
TEST.NEW
TEST.NAME:Inputs!=NULL
TEST.BASIS_PATH:1 of 5
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((ConfigPtr != (void *)0 && StatePtr != (void *)0) && DataPtr != (void *)0) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7603
TEST.END_NOTES:
TEST.VALUE:E2E_P05.E2E_P05Protect.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P05.E2E_P05Protect.ConfigPtr[0].Offset:4
TEST.VALUE:E2E_P05.E2E_P05Protect.ConfigPtr[0].DataLength:5
TEST.VALUE:E2E_P05.E2E_P05Protect.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P05.E2E_P05Protect.StatePtr[0].Counter:254
TEST.VALUE:E2E_P05.E2E_P05Protect.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_P05.E2E_P05Protect.Length:5
TEST.EXPECTED:E2E_P05.E2E_P05Protect.return:0
TEST.END

-- Test Case: InvalidLengthWithOffset0
TEST.UNIT:E2E_P05
TEST.SUBPROGRAM:E2E_P05Protect
TEST.NEW
TEST.NAME:InvalidLengthWithOffset0
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((ConfigPtr != (void *)0 && StatePtr != (void *)0) && DataPtr != (void *)0) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7603
TEST.END_NOTES:
TEST.VALUE:E2E_P05.E2E_P05Protect.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P05.E2E_P05Protect.ConfigPtr[0].Offset:0
TEST.VALUE:E2E_P05.E2E_P05Protect.ConfigPtr[0].DataLength:2
TEST.VALUE:E2E_P05.E2E_P05Protect.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P05.E2E_P05Protect.StatePtr[0].Counter:254
TEST.VALUE:E2E_P05.E2E_P05Protect.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_P05.E2E_P05Protect.Length:2
TEST.EXPECTED:E2E_P05.E2E_P05Protect.return:0
TEST.END

-- Test Case: InvalidLengthWithOffsetIsNot0
TEST.UNIT:E2E_P05
TEST.SUBPROGRAM:E2E_P05Protect
TEST.NEW
TEST.NAME:InvalidLengthWithOffsetIsNot0
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((ConfigPtr != (void *)0 && StatePtr != (void *)0) && DataPtr != (void *)0) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7603
TEST.END_NOTES:
TEST.VALUE:E2E_P05.E2E_P05Protect.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P05.E2E_P05Protect.ConfigPtr[0].Offset:32
TEST.VALUE:E2E_P05.E2E_P05Protect.ConfigPtr[0].DataLength:5
TEST.VALUE:E2E_P05.E2E_P05Protect.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P05.E2E_P05Protect.StatePtr[0].Counter:254
TEST.VALUE:E2E_P05.E2E_P05Protect.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_P05.E2E_P05Protect.Length:5
TEST.EXPECTED:E2E_P05.E2E_P05Protect.return:0
TEST.END

-- Test Case: Length!=DataLength
TEST.UNIT:E2E_P05
TEST.SUBPROGRAM:E2E_P05Protect
TEST.NEW
TEST.NAME:Length!=DataLength
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((ConfigPtr != (void *)0 && StatePtr != (void *)0) && DataPtr != (void *)0) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7603
TEST.END_NOTES:
TEST.VALUE:E2E_P05.E2E_P05Protect.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P05.E2E_P05Protect.ConfigPtr[0].Offset:4
TEST.VALUE:E2E_P05.E2E_P05Protect.ConfigPtr[0].DataLength:5
TEST.VALUE:E2E_P05.E2E_P05Protect.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P05.E2E_P05Protect.StatePtr[0].Counter:254
TEST.VALUE:E2E_P05.E2E_P05Protect.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_P05.E2E_P05Protect.Length:4
TEST.EXPECTED:E2E_P05.E2E_P05Protect.return:23
TEST.END

-- Test Case: OffsetEquals0
TEST.UNIT:E2E_P05
TEST.SUBPROGRAM:E2E_P05Protect
TEST.NEW
TEST.NAME:OffsetEquals0
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((ConfigPtr != (void *)0 && StatePtr != (void *)0) && DataPtr != (void *)0) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7603
TEST.END_NOTES:
TEST.VALUE:E2E_P05.E2E_P05Protect.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P05.E2E_P05Protect.ConfigPtr[0].Offset:0
TEST.VALUE:E2E_P05.E2E_P05Protect.ConfigPtr[0].DataLength:5
TEST.VALUE:E2E_P05.E2E_P05Protect.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P05.E2E_P05Protect.StatePtr[0].Counter:254
TEST.VALUE:E2E_P05.E2E_P05Protect.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_P05.E2E_P05Protect.Length:5
TEST.EXPECTED:E2E_P05.E2E_P05Protect.return:0
TEST.END

-- Subprogram: E2E_P05ProtectInit

-- Test Case: StatePtr!=NULL
TEST.UNIT:E2E_P05
TEST.SUBPROGRAM:E2E_P05ProtectInit
TEST.NEW
TEST.NAME:StatePtr!=NULL
TEST.BASIS_PATH:1 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (StatePtr != (void *)0) ==> TRUE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7603
TEST.END_NOTES:
TEST.VALUE:E2E_P05.E2E_P05ProtectInit.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P05.E2E_P05ProtectInit.StatePtr[0].Counter:0
TEST.EXPECTED:E2E_P05.E2E_P05ProtectInit.return:0
TEST.END

-- Test Case: StatePtr==NULL
TEST.UNIT:E2E_P05
TEST.SUBPROGRAM:E2E_P05ProtectInit
TEST.NEW
TEST.NAME:StatePtr==NULL
TEST.BASIS_PATH:2 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (StatePtr != (void *)0) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7603
TEST.END_NOTES:
TEST.VALUE:E2E_P05.E2E_P05ProtectInit.StatePtr:<<null>>
TEST.EXPECTED:E2E_P05.E2E_P05ProtectInit.return:19
TEST.END

-- Subprogram: E2E_ProcessDeltaCounter

-- Test Case: DeltaCounterNotEqualto1
TEST.UNIT:E2E_P05
TEST.SUBPROGRAM:E2E_ProcessDeltaCounter
TEST.NEW
TEST.NAME:DeltaCounterNotEqualto1
TEST.BASIS_PATH:4 of 4
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if (DeltaCounter <= ConfigPtr->MaxDeltaCounter && DeltaCounter >= 0) ==> TRUE
      (2) if (DeltaCounter > 0) ==> TRUE
      (3) if (DeltaCounter == 1) ==> TRUE
   Test Case Generation Notes:
      Cannot set DeltaCounter due to assignment
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7603
TEST.END_NOTES:
TEST.VALUE:E2E_P05.E2E_ProcessDeltaCounter.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P05.E2E_ProcessDeltaCounter.ConfigPtr[0].MaxDeltaCounter:3
TEST.VALUE:E2E_P05.E2E_ProcessDeltaCounter.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P05.E2E_ProcessDeltaCounter.StatePtr[0].Counter:12
TEST.VALUE:E2E_P05.E2E_ProcessDeltaCounter.ReceivedCounter:15
TEST.END

-- Test Case: DeltaCounterNotEqualto1.001
TEST.UNIT:E2E_P05
TEST.SUBPROGRAM:E2E_ProcessDeltaCounter
TEST.NEW
TEST.NAME:DeltaCounterNotEqualto1.001
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if (DeltaCounter <= ConfigPtr->MaxDeltaCounter && DeltaCounter >= 0) ==> TRUE
      (2) if (DeltaCounter > 0) ==> TRUE
      (3) if (DeltaCounter == 1) ==> TRUE
   Test Case Generation Notes:
      Cannot set DeltaCounter due to assignment
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7603
TEST.END_NOTES:
TEST.VALUE:E2E_P05.E2E_ProcessDeltaCounter.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P05.E2E_ProcessDeltaCounter.ConfigPtr[0].MaxDeltaCounter:3
TEST.VALUE:E2E_P05.E2E_ProcessDeltaCounter.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P05.E2E_ProcessDeltaCounter.StatePtr[0].Counter:12
TEST.VALUE:E2E_P05.E2E_ProcessDeltaCounter.ReceivedCounter:11
TEST.END

-- Test Case: DeltaCounterNotGreaterThan0
TEST.UNIT:E2E_P05
TEST.SUBPROGRAM:E2E_ProcessDeltaCounter
TEST.NEW
TEST.NAME:DeltaCounterNotGreaterThan0
TEST.BASIS_PATH:3 of 4
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (DeltaCounter <= ConfigPtr->MaxDeltaCounter && DeltaCounter >= 0) ==> TRUE
      (2) if (DeltaCounter > 0) ==> TRUE
      (3) if (DeltaCounter == 1) ==> FALSE
   Test Case Generation Notes:
      Cannot set DeltaCounter due to assignment
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7603
TEST.END_NOTES:
TEST.VALUE:E2E_P05.E2E_ProcessDeltaCounter.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P05.E2E_ProcessDeltaCounter.ConfigPtr[0].MaxDeltaCounter:3
TEST.VALUE:E2E_P05.E2E_ProcessDeltaCounter.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P05.E2E_ProcessDeltaCounter.StatePtr[0].Status:E2E_P05STATUS_OK
TEST.VALUE:E2E_P05.E2E_ProcessDeltaCounter.StatePtr[0].Counter:15
TEST.VALUE:E2E_P05.E2E_ProcessDeltaCounter.ReceivedCounter:15
TEST.END

-- Test Case: DeltaCounternotLessThanMaxDeltaCounter
TEST.UNIT:E2E_P05
TEST.SUBPROGRAM:E2E_ProcessDeltaCounter
TEST.NEW
TEST.NAME:DeltaCounternotLessThanMaxDeltaCounter
TEST.BASIS_PATH:2 of 4
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (DeltaCounter <= ConfigPtr->MaxDeltaCounter && DeltaCounter >= 0) ==> TRUE
      (2) if (DeltaCounter > 0) ==> FALSE
   Test Case Generation Notes:
      Cannot set DeltaCounter due to assignment
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7603
TEST.END_NOTES:
TEST.VALUE:E2E_P05.E2E_ProcessDeltaCounter.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P05.E2E_ProcessDeltaCounter.ConfigPtr[0].MaxDeltaCounter:0
TEST.VALUE:E2E_P05.E2E_ProcessDeltaCounter.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P05.E2E_ProcessDeltaCounter.StatePtr[0].Counter:14
TEST.VALUE:E2E_P05.E2E_ProcessDeltaCounter.ReceivedCounter:15
TEST.END

-- Test Case: Inputs!=NULL
TEST.UNIT:E2E_P05
TEST.SUBPROGRAM:E2E_ProcessDeltaCounter
TEST.NEW
TEST.NAME:Inputs!=NULL
TEST.BASIS_PATH:1 of 4
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (DeltaCounter <= ConfigPtr->MaxDeltaCounter && DeltaCounter >= 0) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7603
TEST.END_NOTES:
TEST.VALUE:E2E_P05.E2E_ProcessDeltaCounter.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P05.E2E_ProcessDeltaCounter.ConfigPtr[0].MaxDeltaCounter:3
TEST.VALUE:E2E_P05.E2E_ProcessDeltaCounter.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P05.E2E_ProcessDeltaCounter.StatePtr[0].Status:E2E_P05STATUS_OK
TEST.VALUE:E2E_P05.E2E_ProcessDeltaCounter.StatePtr[0].Counter:14
TEST.VALUE:E2E_P05.E2E_ProcessDeltaCounter.ReceivedCounter:15
TEST.END

-- Unit: E2E_P06

-- Subprogram: E2E_P06Check

-- Test Case: ConfigPtr&StatePtr=NULL
TEST.UNIT:E2E_P06
TEST.SUBPROGRAM:E2E_P06Check
TEST.NEW
TEST.NAME:ConfigPtr&StatePtr=NULL
TEST.BASIS_PATH:1 of 10
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (ConfigPtr != (void *)0 && StatePtr != (void *)0) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7605
TEST.END_NOTES:
TEST.VALUE:E2E_P06.E2E_P06Check.ConfigPtr:<<null>>
TEST.VALUE:E2E_P06.E2E_P06Check.StatePtr:<<null>>
TEST.VALUE:E2E_P06.E2E_P06Check.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_P06.E2E_P06Check.Length:<<MIN>>
TEST.EXPECTED:E2E_P06.E2E_P06Check.return:19
TEST.END

-- Test Case: DataPtr=NULL
TEST.UNIT:E2E_P06
TEST.SUBPROGRAM:E2E_P06Check
TEST.NEW
TEST.NAME:DataPtr=NULL
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (ConfigPtr != (void *)0 && StatePtr != (void *)0) ==> TRUE
      (2) if (DataPtr != (void *)0 && Length != 0U || DataPtr == (void *)0 && Length == 0U) ==> FALSE
   Test Case Generation Notes:
      Conflict: Trying to set variable E2E_P06.E2E_P06Check.Length 'equal to' and 'not equal to' same value in branch 2
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7605
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.Crc_CalculateCRC16.return:VARY FROM:0 TO:65535 BY: 1
TEST.VALUE:E2E_P06.E2E_P06Check.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P06.E2E_P06Check.ConfigPtr[0].Offset:1
TEST.VALUE:E2E_P06.E2E_P06Check.ConfigPtr[0].MinDataLength:0
TEST.VALUE:E2E_P06.E2E_P06Check.ConfigPtr[0].MaxDataLength:15
TEST.VALUE:E2E_P06.E2E_P06Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P06.E2E_P06Check.DataPtr:<<malloc 9>>
TEST.VALUE:E2E_P06.E2E_P06Check.DataPtr:<<null>>
TEST.VALUE:E2E_P06.E2E_P06Check.Length:5
TEST.END

-- Test Case: DataPtrEqualsNULL
TEST.UNIT:E2E_P06
TEST.SUBPROGRAM:E2E_P06Check
TEST.NEW
TEST.NAME:DataPtrEqualsNULL
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (ConfigPtr != (void *)0 && StatePtr != (void *)0) ==> TRUE
      (2) if (DataPtr != (void *)0 && Length != 0U || DataPtr == (void *)0 && Length == 0U) ==> FALSE
   Test Case Generation Notes:
      Conflict: Trying to set variable E2E_P06.E2E_P06Check.Length 'equal to' and 'not equal to' same value in branch 2
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7605
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.Crc_CalculateCRC16.return:VARY FROM:0 TO:65535 BY: 1
TEST.VALUE:E2E_P06.E2E_P06Check.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P06.E2E_P06Check.ConfigPtr[0].Offset:1
TEST.VALUE:E2E_P06.E2E_P06Check.ConfigPtr[0].MinDataLength:0
TEST.VALUE:E2E_P06.E2E_P06Check.ConfigPtr[0].MaxDataLength:15
TEST.VALUE:E2E_P06.E2E_P06Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P06.E2E_P06Check.Length:0
TEST.END

-- Test Case: Inputs!=NULL
TEST.UNIT:E2E_P06
TEST.SUBPROGRAM:E2E_P06Check
TEST.NEW
TEST.NAME:Inputs!=NULL
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (ConfigPtr != (void *)0 && StatePtr != (void *)0) ==> TRUE
      (2) if (DataPtr != (void *)0 && Length != 0U || DataPtr == (void *)0 && Length == 0U) ==> FALSE
   Test Case Generation Notes:
      Conflict: Trying to set variable E2E_P06.E2E_P06Check.Length 'equal to' and 'not equal to' same value in branch 2
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7605
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.Crc_CalculateCRC16.return:VARY FROM:0 TO:65535 BY: 1
TEST.VALUE:E2E_P06.E2E_P06Check.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P06.E2E_P06Check.ConfigPtr[0].Offset:1
TEST.VALUE:E2E_P06.E2E_P06Check.ConfigPtr[0].MinDataLength:0
TEST.VALUE:E2E_P06.E2E_P06Check.ConfigPtr[0].MaxDataLength:15
TEST.VALUE:E2E_P06.E2E_P06Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P06.E2E_P06Check.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_P06.E2E_P06Check.Length:5
TEST.END

-- Test Case: InvalidLengthWithOffset0
TEST.UNIT:E2E_P06
TEST.SUBPROGRAM:E2E_P06Check
TEST.NEW
TEST.NAME:InvalidLengthWithOffset0
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (ConfigPtr != (void *)0 && StatePtr != (void *)0) ==> TRUE
      (2) if (DataPtr != (void *)0 && Length != 0U || DataPtr == (void *)0 && Length == 0U) ==> FALSE
   Test Case Generation Notes:
      Conflict: Trying to set variable E2E_P06.E2E_P06Check.Length 'equal to' and 'not equal to' same value in branch 2
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7605
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.Crc_CalculateCRC16.return:1
TEST.VALUE:E2E_P06.E2E_P06Check.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P06.E2E_P06Check.ConfigPtr[0].Offset:0
TEST.VALUE:E2E_P06.E2E_P06Check.ConfigPtr[0].MinDataLength:0
TEST.VALUE:E2E_P06.E2E_P06Check.ConfigPtr[0].MaxDataLength:15
TEST.VALUE:E2E_P06.E2E_P06Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P06.E2E_P06Check.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_P06.E2E_P06Check.Length:1
TEST.END

-- Test Case: InvalidLengthWithOffsetIsNot0
TEST.UNIT:E2E_P06
TEST.SUBPROGRAM:E2E_P06Check
TEST.NEW
TEST.NAME:InvalidLengthWithOffsetIsNot0
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (ConfigPtr != (void *)0 && StatePtr != (void *)0) ==> TRUE
      (2) if (DataPtr != (void *)0 && Length != 0U || DataPtr == (void *)0 && Length == 0U) ==> FALSE
   Test Case Generation Notes:
      Conflict: Trying to set variable E2E_P06.E2E_P06Check.Length 'equal to' and 'not equal to' same value in branch 2
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7605
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.Crc_CalculateCRC16.return:65535
TEST.VALUE:E2E_P06.E2E_P06Check.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P06.E2E_P06Check.ConfigPtr[0].Offset:1
TEST.VALUE:E2E_P06.E2E_P06Check.ConfigPtr[0].MinDataLength:0
TEST.VALUE:E2E_P06.E2E_P06Check.ConfigPtr[0].MaxDataLength:15
TEST.VALUE:E2E_P06.E2E_P06Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P06.E2E_P06Check.DataPtr:<<malloc 14>>
TEST.VALUE:E2E_P06.E2E_P06Check.DataPtr[0]:255
TEST.VALUE:E2E_P06.E2E_P06Check.DataPtr[1]:255
TEST.VALUE:E2E_P06.E2E_P06Check.DataPtr[2]:14
TEST.VALUE:E2E_P06.E2E_P06Check.DataPtr[3]:0
TEST.VALUE:E2E_P06.E2E_P06Check.Length:1
TEST.END

-- Test Case: Length!=ReceivedLength
TEST.UNIT:E2E_P06
TEST.SUBPROGRAM:E2E_P06Check
TEST.NEW
TEST.NAME:Length!=ReceivedLength
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (ConfigPtr != (void *)0 && StatePtr != (void *)0) ==> TRUE
      (2) if (DataPtr != (void *)0 && Length != 0U || DataPtr == (void *)0 && Length == 0U) ==> FALSE
   Test Case Generation Notes:
      Conflict: Trying to set variable E2E_P06.E2E_P06Check.Length 'equal to' and 'not equal to' same value in branch 2
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7605
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.Crc_CalculateCRC16.return:65535
TEST.VALUE:E2E_P06.E2E_P06Check.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P06.E2E_P06Check.ConfigPtr[0].Offset:1
TEST.VALUE:E2E_P06.E2E_P06Check.ConfigPtr[0].MinDataLength:0
TEST.VALUE:E2E_P06.E2E_P06Check.ConfigPtr[0].MaxDataLength:15
TEST.VALUE:E2E_P06.E2E_P06Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P06.E2E_P06Check.DataPtr:<<malloc 14>>
TEST.VALUE:E2E_P06.E2E_P06Check.DataPtr[0]:255
TEST.VALUE:E2E_P06.E2E_P06Check.DataPtr[1]:255
TEST.VALUE:E2E_P06.E2E_P06Check.DataPtr[2]:0
TEST.VALUE:E2E_P06.E2E_P06Check.DataPtr[3]:14
TEST.VALUE:E2E_P06.E2E_P06Check.Length:13
TEST.END

-- Test Case: Length==0
TEST.UNIT:E2E_P06
TEST.SUBPROGRAM:E2E_P06Check
TEST.NEW
TEST.NAME:Length==0
TEST.BASIS_PATH:2 of 10
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (ConfigPtr != (void *)0 && StatePtr != (void *)0) ==> TRUE
      (2) if (DataPtr != (void *)0 && Length != 0U || DataPtr == (void *)0 && Length == 0U) ==> FALSE
   Test Case Generation Notes:
      Conflict: Trying to set variable E2E_P06.E2E_P06Check.Length 'equal to' and 'not equal to' same value in branch 2
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7605
TEST.END_NOTES:
TEST.VALUE:E2E_P06.E2E_P06Check.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P06.E2E_P06Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P06.E2E_P06Check.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_P06.E2E_P06Check.Length:0
TEST.EXPECTED:E2E_P06.E2E_P06Check.return:23
TEST.END

-- Test Case: Length=ReceivedLength
TEST.UNIT:E2E_P06
TEST.SUBPROGRAM:E2E_P06Check
TEST.NEW
TEST.NAME:Length=ReceivedLength
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (ConfigPtr != (void *)0 && StatePtr != (void *)0) ==> TRUE
      (2) if (DataPtr != (void *)0 && Length != 0U || DataPtr == (void *)0 && Length == 0U) ==> FALSE
   Test Case Generation Notes:
      Conflict: Trying to set variable E2E_P06.E2E_P06Check.Length 'equal to' and 'not equal to' same value in branch 2
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7605
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.Crc_CalculateCRC16.return:65535
TEST.VALUE:E2E_P06.E2E_P06Check.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P06.E2E_P06Check.ConfigPtr[0].Offset:1
TEST.VALUE:E2E_P06.E2E_P06Check.ConfigPtr[0].MinDataLength:0
TEST.VALUE:E2E_P06.E2E_P06Check.ConfigPtr[0].MaxDataLength:15
TEST.VALUE:E2E_P06.E2E_P06Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P06.E2E_P06Check.DataPtr:<<malloc 14>>
TEST.VALUE:E2E_P06.E2E_P06Check.DataPtr[0]:255
TEST.VALUE:E2E_P06.E2E_P06Check.DataPtr[1]:255
TEST.VALUE:E2E_P06.E2E_P06Check.DataPtr[2]:14
TEST.VALUE:E2E_P06.E2E_P06Check.DataPtr[3]:0
TEST.VALUE:E2E_P06.E2E_P06Check.Length:14
TEST.END

-- Test Case: Length>MaxDataLength
TEST.UNIT:E2E_P06
TEST.SUBPROGRAM:E2E_P06Check
TEST.NEW
TEST.NAME:Length>MaxDataLength
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (ConfigPtr != (void *)0 && StatePtr != (void *)0) ==> TRUE
      (2) if (DataPtr != (void *)0 && Length != 0U || DataPtr == (void *)0 && Length == 0U) ==> FALSE
   Test Case Generation Notes:
      Conflict: Trying to set variable E2E_P06.E2E_P06Check.Length 'equal to' and 'not equal to' same value in branch 2
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7605
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.Crc_CalculateCRC16.return:VARY FROM:0 TO:65535 BY: 1
TEST.VALUE:E2E_P06.E2E_P06Check.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P06.E2E_P06Check.ConfigPtr[0].Offset:1
TEST.VALUE:E2E_P06.E2E_P06Check.ConfigPtr[0].MinDataLength:0
TEST.VALUE:E2E_P06.E2E_P06Check.ConfigPtr[0].MaxDataLength:15
TEST.VALUE:E2E_P06.E2E_P06Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P06.E2E_P06Check.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_P06.E2E_P06Check.Length:16
TEST.END

-- Test Case: OffsetEquals0
TEST.UNIT:E2E_P06
TEST.SUBPROGRAM:E2E_P06Check
TEST.NEW
TEST.NAME:OffsetEquals0
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (ConfigPtr != (void *)0 && StatePtr != (void *)0) ==> TRUE
      (2) if (DataPtr != (void *)0 && Length != 0U || DataPtr == (void *)0 && Length == 0U) ==> FALSE
   Test Case Generation Notes:
      Conflict: Trying to set variable E2E_P06.E2E_P06Check.Length 'equal to' and 'not equal to' same value in branch 2
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7605
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.Crc_CalculateCRC16.return:1
TEST.VALUE:E2E_P06.E2E_P06Check.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P06.E2E_P06Check.ConfigPtr[0].Offset:0
TEST.VALUE:E2E_P06.E2E_P06Check.ConfigPtr[0].MinDataLength:0
TEST.VALUE:E2E_P06.E2E_P06Check.ConfigPtr[0].MaxDataLength:15
TEST.VALUE:E2E_P06.E2E_P06Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P06.E2E_P06Check.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_P06.E2E_P06Check.Length:6
TEST.END

-- Subprogram: E2E_P06CheckInit

-- Test Case: StatePtr!=NULL
TEST.UNIT:E2E_P06
TEST.SUBPROGRAM:E2E_P06CheckInit
TEST.NEW
TEST.NAME:StatePtr!=NULL
TEST.BASIS_PATH:1 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (StatePtr != (void *)0) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7605
TEST.END_NOTES:
TEST.VALUE:E2E_P06.E2E_P06CheckInit.StatePtr:<<malloc 1>>
TEST.EXPECTED:E2E_P06.E2E_P06CheckInit.return:0
TEST.END

-- Test Case: StatePtr==NULL
TEST.UNIT:E2E_P06
TEST.SUBPROGRAM:E2E_P06CheckInit
TEST.NEW
TEST.NAME:StatePtr==NULL
TEST.BASIS_PATH:2 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (StatePtr != (void *)0) ==> TRUE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7605
TEST.END_NOTES:
TEST.EXPECTED:E2E_P06.E2E_P06CheckInit.return:19
TEST.END

-- Subprogram: E2E_P06MapStatusToSM

-- Test Case: Checkreturn!=E2E_NOT_OK
TEST.UNIT:E2E_P06
TEST.SUBPROGRAM:E2E_P06MapStatusToSM
TEST.NEW
TEST.NAME:Checkreturn!=E2E_NOT_OK
TEST.BASIS_PATH:1 of 7
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (1U != CheckReturn) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7605
TEST.END_NOTES:
TEST.VALUE:E2E_P06.E2E_P06MapStatusToSM.CheckReturn:1
TEST.VALUE:E2E_P06.E2E_P06MapStatusToSM.Status:<<MIN>>
TEST.EXPECTED:E2E_P06.E2E_P06MapStatusToSM.return:E2E_P_ERROR
TEST.END

-- Test Case: Status!=P06_STATUSWRONGSEQUENCE
TEST.UNIT:E2E_P06
TEST.SUBPROGRAM:E2E_P06MapStatusToSM
TEST.NEW
TEST.NAME:Status!=P06_STATUSWRONGSEQUENCE
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (1U != CheckReturn) ==> TRUE
      (2) if (Status == (E2E_P06STATUS_OK || E2E_P06STATUS_OKSOMELOST)) ==> FALSE
      (3) if (Status == (E2E_P06STATUS_ERROR)) ==> FALSE
      (4) if (Status == (E2E_P06STATUS_REPEATED)) ==> FALSE
      (5) if (Status == (E2E_P06STATUS_NONEWDATA)) ==> FALSE
      (6) if (Status == (E2E_P06STATUS_WRONGSEQUENCE)) ==> TRUE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7605
TEST.END_NOTES:
TEST.VALUE:E2E_P06.E2E_P06MapStatusToSM.CheckReturn:<<MIN>>
TEST.VALUE:E2E_P06.E2E_P06MapStatusToSM.Status:12
TEST.END

-- Test Case: Status=P06_STATUSERROR
TEST.UNIT:E2E_P06
TEST.SUBPROGRAM:E2E_P06MapStatusToSM
TEST.NEW
TEST.NAME:Status=P06_STATUSERROR
TEST.BASIS_PATH:4 of 7
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if (1U != CheckReturn) ==> TRUE
      (2) if (Status == (E2E_P06STATUS_OK || E2E_P06STATUS_OKSOMELOST)) ==> FALSE
      (3) if (Status == (E2E_P06STATUS_ERROR)) ==> FALSE
      (4) if (Status == (E2E_P06STATUS_REPEATED)) ==> FALSE
      (5) if (Status == (E2E_P06STATUS_NONEWDATA)) ==> TRUE
   Test Case Generation Notes:
      Conflict: Trying to set variable E2E_P06.E2E_P06MapStatusToSM.Status 'equal to' and 'not equal to' same value in branches 2/5
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7605
TEST.END_NOTES:
TEST.VALUE:E2E_P06.E2E_P06MapStatusToSM.CheckReturn:<<MIN>>
TEST.VALUE:E2E_P06.E2E_P06MapStatusToSM.Status:E2E_P06STATUS_ERROR
TEST.EXPECTED:E2E_P06.E2E_P06MapStatusToSM.return:E2E_P_ERROR
TEST.END

-- Test Case: Status=P06_STATUSNONEWDATA
TEST.UNIT:E2E_P06
TEST.SUBPROGRAM:E2E_P06MapStatusToSM
TEST.NEW
TEST.NAME:Status=P06_STATUSNONEWDATA
TEST.BASIS_PATH:7 of 7
TEST.NOTES:
This is an automatically generated test case.
   Test Path 7
      (1) if (1U != CheckReturn) ==> TRUE
      (2) if (Status == (E2E_P06STATUS_OK || E2E_P06STATUS_OKSOMELOST)) ==> TRUE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7605
TEST.END_NOTES:
TEST.VALUE:E2E_P06.E2E_P06MapStatusToSM.CheckReturn:<<MIN>>
TEST.VALUE:E2E_P06.E2E_P06MapStatusToSM.Status:E2E_P06STATUS_NONEWDATA
TEST.EXPECTED:E2E_P06.E2E_P06MapStatusToSM.return:E2E_P_NONEWDATA
TEST.END

-- Test Case: Status=P06_STATUSOK
TEST.UNIT:E2E_P06
TEST.SUBPROGRAM:E2E_P06MapStatusToSM
TEST.NEW
TEST.NAME:Status=P06_STATUSOK
TEST.BASIS_PATH:2 of 7
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (1U != CheckReturn) ==> TRUE
      (2) if (Status == (E2E_P06STATUS_OK || E2E_P06STATUS_OKSOMELOST)) ==> FALSE
      (3) if (Status == (E2E_P06STATUS_ERROR)) ==> FALSE
      (4) if (Status == (E2E_P06STATUS_REPEATED)) ==> FALSE
      (5) if (Status == (E2E_P06STATUS_NONEWDATA)) ==> FALSE
      (6) if (Status == (E2E_P06STATUS_WRONGSEQUENCE)) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7605
TEST.END_NOTES:
TEST.VALUE:E2E_P06.E2E_P06MapStatusToSM.CheckReturn:0
TEST.VALUE:E2E_P06.E2E_P06MapStatusToSM.Status:E2E_P06STATUS_OK
TEST.EXPECTED:E2E_P06.E2E_P06MapStatusToSM.return:E2E_P_OK
TEST.END

-- Test Case: Status=P06_STATUSOKSOMELOST
TEST.UNIT:E2E_P06
TEST.SUBPROGRAM:E2E_P06MapStatusToSM
TEST.NEW
TEST.NAME:Status=P06_STATUSOKSOMELOST
TEST.BASIS_PATH:5 of 7
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (1) if (1U != CheckReturn) ==> TRUE
      (2) if (Status == (E2E_P06STATUS_OK || E2E_P06STATUS_OKSOMELOST)) ==> FALSE
      (3) if (Status == (E2E_P06STATUS_ERROR)) ==> FALSE
      (4) if (Status == (E2E_P06STATUS_REPEATED)) ==> TRUE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7605
TEST.END_NOTES:
TEST.VALUE:E2E_P06.E2E_P06MapStatusToSM.CheckReturn:<<MIN>>
TEST.VALUE:E2E_P06.E2E_P06MapStatusToSM.Status:E2E_P06STATUS_OKSOMELOST
TEST.EXPECTED:E2E_P06.E2E_P06MapStatusToSM.return:E2E_P_OK
TEST.END

-- Test Case: Status=P06_STATUSREPEATED
TEST.UNIT:E2E_P06
TEST.SUBPROGRAM:E2E_P06MapStatusToSM
TEST.NEW
TEST.NAME:Status=P06_STATUSREPEATED
TEST.BASIS_PATH:6 of 7
TEST.NOTES:
This is an automatically generated test case.
   Test Path 6
      (1) if (1U != CheckReturn) ==> TRUE
      (2) if (Status == (E2E_P06STATUS_OK || E2E_P06STATUS_OKSOMELOST)) ==> FALSE
      (3) if (Status == (E2E_P06STATUS_ERROR)) ==> TRUE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7605
TEST.END_NOTES:
TEST.VALUE:E2E_P06.E2E_P06MapStatusToSM.CheckReturn:<<MIN>>
TEST.VALUE:E2E_P06.E2E_P06MapStatusToSM.Status:E2E_P06STATUS_REPEATED
TEST.EXPECTED:E2E_P06.E2E_P06MapStatusToSM.return:E2E_P_REPEATED
TEST.END

-- Test Case: Status=P06_STATUSWRONGSEQUENCE
TEST.UNIT:E2E_P06
TEST.SUBPROGRAM:E2E_P06MapStatusToSM
TEST.NEW
TEST.NAME:Status=P06_STATUSWRONGSEQUENCE
TEST.BASIS_PATH:3 of 7
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (1U != CheckReturn) ==> TRUE
      (2) if (Status == (E2E_P06STATUS_OK || E2E_P06STATUS_OKSOMELOST)) ==> FALSE
      (3) if (Status == (E2E_P06STATUS_ERROR)) ==> FALSE
      (4) if (Status == (E2E_P06STATUS_REPEATED)) ==> FALSE
      (5) if (Status == (E2E_P06STATUS_NONEWDATA)) ==> FALSE
      (6) if (Status == (E2E_P06STATUS_WRONGSEQUENCE)) ==> TRUE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7605
TEST.END_NOTES:
TEST.VALUE:E2E_P06.E2E_P06MapStatusToSM.CheckReturn:<<MIN>>
TEST.VALUE:E2E_P06.E2E_P06MapStatusToSM.Status:E2E_P06STATUS_WRONGSEQUENCE
TEST.EXPECTED:E2E_P06.E2E_P06MapStatusToSM.return:E2E_P_WRONGSEQUENCE
TEST.END

-- Subprogram: E2E_P06Protect

-- Test Case: ConfigPtr==NULL
TEST.UNIT:E2E_P06
TEST.SUBPROGRAM:E2E_P06Protect
TEST.NEW
TEST.NAME:ConfigPtr==NULL
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((ConfigPtr != (void *)0 && StatePtr != (void *)0) && DataPtr != (void *)0) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7605
TEST.END_NOTES:
TEST.VALUE:E2E_P06.E2E_P06Protect.ConfigPtr:<<null>>
TEST.VALUE:E2E_P06.E2E_P06Protect.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P06.E2E_P06Protect.StatePtr[0].Counter:254
TEST.VALUE:E2E_P06.E2E_P06Protect.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_P06.E2E_P06Protect.Length:5
TEST.EXPECTED:E2E_P06.E2E_P06Protect.return:19
TEST.END

-- Test Case: CounterNotEqualsMax
TEST.UNIT:E2E_P06
TEST.SUBPROGRAM:E2E_P06Protect
TEST.NEW
TEST.NAME:CounterNotEqualsMax
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((ConfigPtr != (void *)0 && StatePtr != (void *)0) && DataPtr != (void *)0) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7605
TEST.END_NOTES:
TEST.VALUE:E2E_P06.E2E_P06Protect.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P06.E2E_P06Protect.ConfigPtr[0].Offset:1
TEST.VALUE:E2E_P06.E2E_P06Protect.ConfigPtr[0].MinDataLength:0
TEST.VALUE:E2E_P06.E2E_P06Protect.ConfigPtr[0].MaxDataLength:15
TEST.VALUE:E2E_P06.E2E_P06Protect.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P06.E2E_P06Protect.StatePtr[0].Counter:0
TEST.VALUE:E2E_P06.E2E_P06Protect.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_P06.E2E_P06Protect.Length:5
TEST.EXPECTED:E2E_P06.E2E_P06Protect.return:0
TEST.END

-- Test Case: Inputs!=NULL
TEST.UNIT:E2E_P06
TEST.SUBPROGRAM:E2E_P06Protect
TEST.NEW
TEST.NAME:Inputs!=NULL
TEST.BASIS_PATH:1 of 5
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((ConfigPtr != (void *)0 && StatePtr != (void *)0) && DataPtr != (void *)0) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7605
TEST.END_NOTES:
TEST.VALUE:E2E_P06.E2E_P06Protect.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P06.E2E_P06Protect.ConfigPtr[0].Offset:1
TEST.VALUE:E2E_P06.E2E_P06Protect.ConfigPtr[0].MinDataLength:0
TEST.VALUE:E2E_P06.E2E_P06Protect.ConfigPtr[0].MaxDataLength:15
TEST.VALUE:E2E_P06.E2E_P06Protect.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P06.E2E_P06Protect.StatePtr[0].Counter:254
TEST.VALUE:E2E_P06.E2E_P06Protect.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_P06.E2E_P06Protect.Length:5
TEST.EXPECTED:E2E_P06.E2E_P06Protect.return:0
TEST.END

-- Test Case: InvalidLengthWithOffset0
TEST.UNIT:E2E_P06
TEST.SUBPROGRAM:E2E_P06Protect
TEST.NEW
TEST.NAME:InvalidLengthWithOffset0
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((ConfigPtr != (void *)0 && StatePtr != (void *)0) && DataPtr != (void *)0) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7605
TEST.END_NOTES:
TEST.VALUE:E2E_P06.E2E_P06Protect.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P06.E2E_P06Protect.ConfigPtr[0].Offset:0
TEST.VALUE:E2E_P06.E2E_P06Protect.ConfigPtr[0].MinDataLength:0
TEST.VALUE:E2E_P06.E2E_P06Protect.ConfigPtr[0].MaxDataLength:15
TEST.VALUE:E2E_P06.E2E_P06Protect.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P06.E2E_P06Protect.StatePtr[0].Counter:254
TEST.VALUE:E2E_P06.E2E_P06Protect.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_P06.E2E_P06Protect.Length:1
TEST.EXPECTED:E2E_P06.E2E_P06Protect.return:0
TEST.END

-- Test Case: InvalidLengthWithOffsetIsNot0
TEST.UNIT:E2E_P06
TEST.SUBPROGRAM:E2E_P06Protect
TEST.NEW
TEST.NAME:InvalidLengthWithOffsetIsNot0
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((ConfigPtr != (void *)0 && StatePtr != (void *)0) && DataPtr != (void *)0) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7605
TEST.END_NOTES:
TEST.VALUE:E2E_P06.E2E_P06Protect.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P06.E2E_P06Protect.ConfigPtr[0].Offset:1
TEST.VALUE:E2E_P06.E2E_P06Protect.ConfigPtr[0].MinDataLength:0
TEST.VALUE:E2E_P06.E2E_P06Protect.ConfigPtr[0].MaxDataLength:15
TEST.VALUE:E2E_P06.E2E_P06Protect.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P06.E2E_P06Protect.StatePtr[0].Counter:254
TEST.VALUE:E2E_P06.E2E_P06Protect.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_P06.E2E_P06Protect.Length:1
TEST.EXPECTED:E2E_P06.E2E_P06Protect.return:0
TEST.END

-- Test Case: Length>MaxDataLength
TEST.UNIT:E2E_P06
TEST.SUBPROGRAM:E2E_P06Protect
TEST.NEW
TEST.NAME:Length>MaxDataLength
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((ConfigPtr != (void *)0 && StatePtr != (void *)0) && DataPtr != (void *)0) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7605
TEST.END_NOTES:
TEST.VALUE:E2E_P06.E2E_P06Protect.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P06.E2E_P06Protect.ConfigPtr[0].Offset:1
TEST.VALUE:E2E_P06.E2E_P06Protect.ConfigPtr[0].MinDataLength:0
TEST.VALUE:E2E_P06.E2E_P06Protect.ConfigPtr[0].MaxDataLength:15
TEST.VALUE:E2E_P06.E2E_P06Protect.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P06.E2E_P06Protect.StatePtr[0].Counter:254
TEST.VALUE:E2E_P06.E2E_P06Protect.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_P06.E2E_P06Protect.Length:16
TEST.EXPECTED:E2E_P06.E2E_P06Protect.return:23
TEST.END

-- Test Case: OffsetEquals0
TEST.UNIT:E2E_P06
TEST.SUBPROGRAM:E2E_P06Protect
TEST.NEW
TEST.NAME:OffsetEquals0
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((ConfigPtr != (void *)0 && StatePtr != (void *)0) && DataPtr != (void *)0) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7605
TEST.END_NOTES:
TEST.VALUE:E2E_P06.E2E_P06Protect.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P06.E2E_P06Protect.ConfigPtr[0].Offset:0
TEST.VALUE:E2E_P06.E2E_P06Protect.ConfigPtr[0].MinDataLength:0
TEST.VALUE:E2E_P06.E2E_P06Protect.ConfigPtr[0].MaxDataLength:15
TEST.VALUE:E2E_P06.E2E_P06Protect.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P06.E2E_P06Protect.StatePtr[0].Counter:254
TEST.VALUE:E2E_P06.E2E_P06Protect.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_P06.E2E_P06Protect.Length:5
TEST.EXPECTED:E2E_P06.E2E_P06Protect.return:0
TEST.END

-- Subprogram: E2E_P06ProtectInit

-- Test Case: StatePtr!=NULL
TEST.UNIT:E2E_P06
TEST.SUBPROGRAM:E2E_P06ProtectInit
TEST.NEW
TEST.NAME:StatePtr!=NULL
TEST.BASIS_PATH:1 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (StatePtr != (void *)0) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7605
TEST.END_NOTES:
TEST.VALUE:E2E_P06.E2E_P06ProtectInit.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P06.E2E_P06ProtectInit.StatePtr[0].Counter:0
TEST.VALUE:E2E_P06.E2E_P06ProtectInit.return:0
TEST.EXPECTED:E2E_P06.E2E_P06ProtectInit.return:0
TEST.END

-- Test Case: StatePtr==NULL
TEST.UNIT:E2E_P06
TEST.SUBPROGRAM:E2E_P06ProtectInit
TEST.NEW
TEST.NAME:StatePtr==NULL
TEST.BASIS_PATH:2 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (StatePtr != (void *)0) ==> TRUE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7605
TEST.END_NOTES:
TEST.VALUE:E2E_P06.E2E_P06ProtectInit.StatePtr:<<null>>
TEST.EXPECTED:E2E_P06.E2E_P06ProtectInit.return:19
TEST.END

-- Subprogram: E2E_ProcessDeltaCounter

-- Test Case: DeltaCounterNotEqualto1
TEST.UNIT:E2E_P06
TEST.SUBPROGRAM:E2E_ProcessDeltaCounter
TEST.NEW
TEST.NAME:DeltaCounterNotEqualto1
TEST.NOTES:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7605
TEST.END_NOTES:
TEST.VALUE:E2E_P06.E2E_ProcessDeltaCounter.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P06.E2E_ProcessDeltaCounter.ConfigPtr[0].MaxDeltaCounter:3
TEST.VALUE:E2E_P06.E2E_ProcessDeltaCounter.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P06.E2E_ProcessDeltaCounter.StatePtr[0].Counter:12
TEST.VALUE:E2E_P06.E2E_ProcessDeltaCounter.ReceivedCounter:15
TEST.END

-- Test Case: DeltaCounterNotEqualto1.001
TEST.UNIT:E2E_P06
TEST.SUBPROGRAM:E2E_ProcessDeltaCounter
TEST.NEW
TEST.NAME:DeltaCounterNotEqualto1.001
TEST.NOTES:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7605
TEST.END_NOTES:
TEST.VALUE:E2E_P06.E2E_ProcessDeltaCounter.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P06.E2E_ProcessDeltaCounter.ConfigPtr[0].MaxDeltaCounter:3
TEST.VALUE:E2E_P06.E2E_ProcessDeltaCounter.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P06.E2E_ProcessDeltaCounter.StatePtr[0].Counter:12
TEST.VALUE:E2E_P06.E2E_ProcessDeltaCounter.ReceivedCounter:11
TEST.END

-- Test Case: DeltaCounterNotGreaterThan0
TEST.UNIT:E2E_P06
TEST.SUBPROGRAM:E2E_ProcessDeltaCounter
TEST.NEW
TEST.NAME:DeltaCounterNotGreaterThan0
TEST.NOTES:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7605
TEST.END_NOTES:
TEST.VALUE:E2E_P06.E2E_ProcessDeltaCounter.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P06.E2E_ProcessDeltaCounter.ConfigPtr[0].MaxDeltaCounter:3
TEST.VALUE:E2E_P06.E2E_ProcessDeltaCounter.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P06.E2E_ProcessDeltaCounter.StatePtr[0].Status:E2E_P06STATUS_OK
TEST.VALUE:E2E_P06.E2E_ProcessDeltaCounter.StatePtr[0].Counter:15
TEST.VALUE:E2E_P06.E2E_ProcessDeltaCounter.ReceivedCounter:15
TEST.END

-- Test Case: DeltaCounterNotLesThanMaxDeltaCounter
TEST.UNIT:E2E_P06
TEST.SUBPROGRAM:E2E_ProcessDeltaCounter
TEST.NEW
TEST.NAME:DeltaCounterNotLesThanMaxDeltaCounter
TEST.NOTES:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7605
TEST.END_NOTES:
TEST.VALUE:E2E_P06.E2E_ProcessDeltaCounter.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P06.E2E_ProcessDeltaCounter.ConfigPtr[0].MaxDeltaCounter:0
TEST.VALUE:E2E_P06.E2E_ProcessDeltaCounter.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P06.E2E_ProcessDeltaCounter.StatePtr[0].Counter:14
TEST.VALUE:E2E_P06.E2E_ProcessDeltaCounter.ReceivedCounter:15
TEST.END

-- Test Case: Inputs!=NULL
TEST.UNIT:E2E_P06
TEST.SUBPROGRAM:E2E_ProcessDeltaCounter
TEST.NEW
TEST.NAME:Inputs!=NULL
TEST.NOTES:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7605
TEST.END_NOTES:
TEST.VALUE:E2E_P06.E2E_ProcessDeltaCounter.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P06.E2E_ProcessDeltaCounter.ConfigPtr[0].MaxDeltaCounter:3
TEST.VALUE:E2E_P06.E2E_ProcessDeltaCounter.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P06.E2E_ProcessDeltaCounter.StatePtr[0].Status:E2E_P06STATUS_OK
TEST.VALUE:E2E_P06.E2E_ProcessDeltaCounter.StatePtr[0].Counter:14
TEST.VALUE:E2E_P06.E2E_ProcessDeltaCounter.ReceivedCounter:15
TEST.END

-- Unit: E2E_P07

-- Subprogram: E2E_P07Check

-- Test Case: BASIS-PATH-001
TEST.UNIT:E2E_P07
TEST.SUBPROGRAM:E2E_P07Check
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 11
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((void *)0 != ConfigPtr && (void *)0 != StatePtr) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-8718

TEST.END_NOTES:
TEST.VALUE:E2E_P07.E2E_P07Check.ConfigPtr:<<null>>
TEST.VALUE:E2E_P07.E2E_P07Check.StatePtr:<<null>>
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_P07.E2E_P07Check.Length:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:E2E_P07
TEST.SUBPROGRAM:E2E_P07Check
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 11 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if ((void *)0 != ConfigPtr && (void *)0 != StatePtr) ==> TRUE
      (2) if ((void *)0 != DataPtr && (0U) != Length || (void *)0 == DataPtr && (0U) == Length) ==> FALSE
   Test Case Generation Notes:
      Conflict: Trying to set variable E2E_P07.E2E_P07Check.Length 'equal to' and 'not equal to' same value in branch 2
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-8718

TEST.END_NOTES:
TEST.VALUE:E2E_P07.E2E_P07Check.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P07.E2E_P07Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_P07.E2E_P07Check.Length:0
TEST.END

-- Test Case: BASIS-PATH-003
TEST.UNIT:E2E_P07
TEST.SUBPROGRAM:E2E_P07Check
TEST.NEW
TEST.NAME:BASIS-PATH-003
TEST.BASIS_PATH:3 of 11
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if ((void *)0 != ConfigPtr && (void *)0 != StatePtr) ==> TRUE
      (2) if ((void *)0 != DataPtr && (0U) != Length || (void *)0 == DataPtr && (0U) == Length) ==> TRUE
      (3) if ((void *)0 != DataPtr) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-8718

TEST.END_NOTES:
TEST.VALUE:E2E_P07.E2E_P07Check.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P07.E2E_P07Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr:<<malloc 9>>
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr:<<null>>
TEST.VALUE:E2E_P07.E2E_P07Check.Length:1
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:E2E_P07
TEST.SUBPROGRAM:E2E_P07Check
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 11 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if ((void *)0 != ConfigPtr && (void *)0 != StatePtr) ==> TRUE
      (2) if ((void *)0 != DataPtr && (0U) != Length || (void *)0 == DataPtr && (0U) == Length) ==> TRUE
      (3) if ((void *)0 != DataPtr) ==> TRUE
      (4) if (Length >= ConfigPtr->MinDataLength >> 3U && Length <= ConfigPtr->MaxDataLength >> 3U) ==> FALSE
      (5) if ((0U) < ConfigPtr->Offset) ==> FALSE
      (6) if (1U == NewDataAvailable) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable NewDataAvailable in branch 6
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-8718

TEST.END_NOTES:
TEST.VALUE:E2E_P07.E2E_P07Check.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P07.E2E_P07Check.ConfigPtr[0].Offset:<<MIN>>
TEST.VALUE:E2E_P07.E2E_P07Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_P07.E2E_P07Check.Length:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL
TEST.UNIT:E2E_P07
TEST.SUBPROGRAM:E2E_P07Check
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL
TEST.BASIS_PATH:5 of 11 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (1) if ((void *)0 != ConfigPtr && (void *)0 != StatePtr) ==> TRUE
      (2) if ((void *)0 != DataPtr && (0U) != Length || (void *)0 == DataPtr && (0U) == Length) ==> TRUE
      (3) if ((void *)0 != DataPtr) ==> TRUE
      (4) if (Length >= ConfigPtr->MinDataLength >> 3U && Length <= ConfigPtr->MaxDataLength >> 3U) ==> FALSE
      (5) if ((0U) < ConfigPtr->Offset) ==> FALSE
      (6) if (1U == NewDataAvailable) ==> TRUE
      (7) if ((ReceivedCRC == ComputedCRC && ReceivedDataID == ConfigPtr->DataID) && ReceivedLength == Length) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable NewDataAvailable in branch 6
      Cannot set ReceivedCRC due to assignment
      Cannot set ReceivedDataID due to assignment
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-8718

TEST.END_NOTES:
TEST.VALUE:E2E_P07.E2E_P07Check.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P07.E2E_P07Check.ConfigPtr[0].Offset:<<MIN>>
TEST.VALUE:E2E_P07.E2E_P07Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_P07.E2E_P07Check.Length:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-006-PARTIAL
TEST.UNIT:E2E_P07
TEST.SUBPROGRAM:E2E_P07Check
TEST.NEW
TEST.NAME:BASIS-PATH-006-PARTIAL
TEST.BASIS_PATH:6 of 11 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 6
      (1) if ((void *)0 != ConfigPtr && (void *)0 != StatePtr) ==> TRUE
      (2) if ((void *)0 != DataPtr && (0U) != Length || (void *)0 == DataPtr && (0U) == Length) ==> TRUE
      (3) if ((void *)0 != DataPtr) ==> TRUE
      (4) if (Length >= ConfigPtr->MinDataLength >> 3U && Length <= ConfigPtr->MaxDataLength >> 3U) ==> FALSE
      (5) if ((0U) < ConfigPtr->Offset) ==> FALSE
      (6) if (1U == NewDataAvailable) ==> TRUE
      (7) if ((ReceivedCRC == ComputedCRC && ReceivedDataID == ConfigPtr->DataID) && ReceivedLength == Length) ==> TRUE
      (8) if (DeltaCounter <= ConfigPtr->MaxDeltaCounter) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable NewDataAvailable in branch 6
      Cannot set ReceivedCRC due to assignment
      Cannot set ReceivedDataID due to assignment
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-8718

TEST.END_NOTES:
TEST.VALUE:E2E_P07.E2E_P07Check.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P07.E2E_P07Check.ConfigPtr[0].Offset:<<MIN>>
TEST.VALUE:E2E_P07.E2E_P07Check.ConfigPtr[0].MaxDeltaCounter:<<MIN>>
TEST.VALUE:E2E_P07.E2E_P07Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_P07.E2E_P07Check.Length:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-007-PARTIAL
TEST.UNIT:E2E_P07
TEST.SUBPROGRAM:E2E_P07Check
TEST.NEW
TEST.NAME:BASIS-PATH-007-PARTIAL
TEST.BASIS_PATH:7 of 11 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 7
      (1) if ((void *)0 != ConfigPtr && (void *)0 != StatePtr) ==> TRUE
      (2) if ((void *)0 != DataPtr && (0U) != Length || (void *)0 == DataPtr && (0U) == Length) ==> TRUE
      (3) if ((void *)0 != DataPtr) ==> TRUE
      (4) if (Length >= ConfigPtr->MinDataLength >> 3U && Length <= ConfigPtr->MaxDataLength >> 3U) ==> FALSE
      (5) if ((0U) < ConfigPtr->Offset) ==> FALSE
      (6) if (1U == NewDataAvailable) ==> TRUE
      (7) if ((ReceivedCRC == ComputedCRC && ReceivedDataID == ConfigPtr->DataID) && ReceivedLength == Length) ==> TRUE
      (8) if (DeltaCounter <= ConfigPtr->MaxDeltaCounter) ==> TRUE
      (9) if (DeltaCounter > (0U)) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable NewDataAvailable in branch 6
      Cannot set ReceivedCRC due to assignment
      Cannot set ReceivedDataID due to assignment
      Cannot set DeltaCounter due to assignment
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-8718

TEST.END_NOTES:
TEST.VALUE:E2E_P07.E2E_P07Check.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P07.E2E_P07Check.ConfigPtr[0].Offset:<<MIN>>
TEST.VALUE:E2E_P07.E2E_P07Check.ConfigPtr[0].MaxDeltaCounter:<<MAX>>
TEST.VALUE:E2E_P07.E2E_P07Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_P07.E2E_P07Check.Length:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-008-PARTIAL
TEST.UNIT:E2E_P07
TEST.SUBPROGRAM:E2E_P07Check
TEST.NEW
TEST.NAME:BASIS-PATH-008-PARTIAL
TEST.BASIS_PATH:8 of 11 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 8
      (1) if ((void *)0 != ConfigPtr && (void *)0 != StatePtr) ==> TRUE
      (2) if ((void *)0 != DataPtr && (0U) != Length || (void *)0 == DataPtr && (0U) == Length) ==> TRUE
      (3) if ((void *)0 != DataPtr) ==> TRUE
      (4) if (Length >= ConfigPtr->MinDataLength >> 3U && Length <= ConfigPtr->MaxDataLength >> 3U) ==> FALSE
      (5) if ((0U) < ConfigPtr->Offset) ==> FALSE
      (6) if (1U == NewDataAvailable) ==> TRUE
      (7) if ((ReceivedCRC == ComputedCRC && ReceivedDataID == ConfigPtr->DataID) && ReceivedLength == Length) ==> TRUE
      (8) if (DeltaCounter <= ConfigPtr->MaxDeltaCounter) ==> TRUE
      (9) if (DeltaCounter > (0U)) ==> TRUE
      (10) if (DeltaCounter == (1U)) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable NewDataAvailable in branch 6
      Cannot set ReceivedCRC due to assignment
      Cannot set ReceivedDataID due to assignment
      Cannot set DeltaCounter due to assignment
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-8718

TEST.END_NOTES:
TEST.VALUE:E2E_P07.E2E_P07Check.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P07.E2E_P07Check.ConfigPtr[0].Offset:<<MIN>>
TEST.VALUE:E2E_P07.E2E_P07Check.ConfigPtr[0].MaxDeltaCounter:<<MAX>>
TEST.VALUE:E2E_P07.E2E_P07Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_P07.E2E_P07Check.Length:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-009-PARTIAL
TEST.UNIT:E2E_P07
TEST.SUBPROGRAM:E2E_P07Check
TEST.NEW
TEST.NAME:BASIS-PATH-009-PARTIAL
TEST.BASIS_PATH:9 of 11 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 9
      (1) if ((void *)0 != ConfigPtr && (void *)0 != StatePtr) ==> TRUE
      (2) if ((void *)0 != DataPtr && (0U) != Length || (void *)0 == DataPtr && (0U) == Length) ==> TRUE
      (3) if ((void *)0 != DataPtr) ==> TRUE
      (4) if (Length >= ConfigPtr->MinDataLength >> 3U && Length <= ConfigPtr->MaxDataLength >> 3U) ==> FALSE
      (5) if ((0U) < ConfigPtr->Offset) ==> FALSE
      (6) if (1U == NewDataAvailable) ==> TRUE
      (7) if ((ReceivedCRC == ComputedCRC && ReceivedDataID == ConfigPtr->DataID) && ReceivedLength == Length) ==> TRUE
      (8) if (DeltaCounter <= ConfigPtr->MaxDeltaCounter) ==> TRUE
      (9) if (DeltaCounter > (0U)) ==> TRUE
      (10) if (DeltaCounter == (1U)) ==> TRUE
   Test Case Generation Notes:
      Cannot set local variable NewDataAvailable in branch 6
      Cannot set ReceivedCRC due to assignment
      Cannot set ReceivedDataID due to assignment
      Cannot set DeltaCounter due to assignment
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-8718

TEST.END_NOTES:
TEST.VALUE:E2E_P07.E2E_P07Check.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P07.E2E_P07Check.ConfigPtr[0].Offset:<<MIN>>
TEST.VALUE:E2E_P07.E2E_P07Check.ConfigPtr[0].MaxDeltaCounter:<<MAX>>
TEST.VALUE:E2E_P07.E2E_P07Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_P07.E2E_P07Check.Length:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-010-PARTIAL
TEST.UNIT:E2E_P07
TEST.SUBPROGRAM:E2E_P07Check
TEST.NEW
TEST.NAME:BASIS-PATH-010-PARTIAL
TEST.BASIS_PATH:10 of 11 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 10
      (1) if ((void *)0 != ConfigPtr && (void *)0 != StatePtr) ==> TRUE
      (2) if ((void *)0 != DataPtr && (0U) != Length || (void *)0 == DataPtr && (0U) == Length) ==> TRUE
      (3) if ((void *)0 != DataPtr) ==> TRUE
      (4) if (Length >= ConfigPtr->MinDataLength >> 3U && Length <= ConfigPtr->MaxDataLength >> 3U) ==> FALSE
      (5) if ((0U) < ConfigPtr->Offset) ==> TRUE
      (6) if (1U == NewDataAvailable) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable NewDataAvailable in branch 6
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-8718

TEST.END_NOTES:
TEST.VALUE:E2E_P07.E2E_P07Check.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P07.E2E_P07Check.ConfigPtr[0].Offset:<<MAX>>
TEST.VALUE:E2E_P07.E2E_P07Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_P07.E2E_P07Check.Length:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-011-PARTIAL
TEST.UNIT:E2E_P07
TEST.SUBPROGRAM:E2E_P07Check
TEST.NEW
TEST.NAME:BASIS-PATH-011-PARTIAL
TEST.BASIS_PATH:11 of 11 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 11
      (1) if ((void *)0 != ConfigPtr && (void *)0 != StatePtr) ==> TRUE
      (2) if ((void *)0 != DataPtr && (0U) != Length || (void *)0 == DataPtr && (0U) == Length) ==> TRUE
      (3) if ((void *)0 != DataPtr) ==> TRUE
      (4) if (Length >= ConfigPtr->MinDataLength >> 3U && Length <= ConfigPtr->MaxDataLength >> 3U) ==> TRUE
      (5) if ((0U) < ConfigPtr->Offset) ==> FALSE
      (6) if (1U == NewDataAvailable) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable TEST.VALUE:E2E_P07.E2E_P07Check.Length: in branch 4 to unknown value
      Cannot set NewDataAvailable due to assignment
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-8718

TEST.END_NOTES:
TEST.VALUE:E2E_P07.E2E_P07Check.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P07.E2E_P07Check.ConfigPtr[0].Offset:<<MIN>>
TEST.VALUE:E2E_P07.E2E_P07Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_P07.E2E_P07Check.Length:1
TEST.END

-- Test Case: BASIS-PATH-011-PARTIAL.001
TEST.UNIT:E2E_P07
TEST.SUBPROGRAM:E2E_P07Check
TEST.NEW
TEST.NAME:BASIS-PATH-011-PARTIAL.001
TEST.NOTES:
This is an automatically generated test case.
   Test Path 11
      (1) if ((void *)0 != ConfigPtr && (void *)0 != StatePtr) ==> TRUE
      (2) if ((void *)0 != DataPtr && (0U) != Length || (void *)0 == DataPtr && (0U) == Length) ==> TRUE
      (3) if ((void *)0 != DataPtr) ==> TRUE
      (4) if (Length >= ConfigPtr->MinDataLength >> 3U && Length <= ConfigPtr->MaxDataLength >> 3U) ==> TRUE
      (5) if ((0U) < ConfigPtr->Offset) ==> FALSE
      (6) if (1U == NewDataAvailable) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable TEST.VALUE:E2E_P07.E2E_P07Check.Length: in branch 4 to unknown value
      Cannot set NewDataAvailable due to assignment
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-8718

TEST.END_NOTES:
TEST.VALUE:E2E_P07.E2E_P07Check.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P07.E2E_P07Check.ConfigPtr[0].Offset:<<MIN>>
TEST.VALUE:E2E_P07.E2E_P07Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P07.E2E_P07Check.Length:0
TEST.END

-- Test Case: BASIS-PATH-011-PARTIAL.002
TEST.UNIT:E2E_P07
TEST.SUBPROGRAM:E2E_P07Check
TEST.NEW
TEST.NAME:BASIS-PATH-011-PARTIAL.002
TEST.NOTES:
This is an automatically generated test case.
   Test Path 11
      (1) if ((void *)0 != ConfigPtr && (void *)0 != StatePtr) ==> TRUE
      (2) if ((void *)0 != DataPtr && (0U) != Length || (void *)0 == DataPtr && (0U) == Length) ==> TRUE
      (3) if ((void *)0 != DataPtr) ==> TRUE
      (4) if (Length >= ConfigPtr->MinDataLength >> 3U && Length <= ConfigPtr->MaxDataLength >> 3U) ==> TRUE
      (5) if ((0U) < ConfigPtr->Offset) ==> FALSE
      (6) if (1U == NewDataAvailable) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable TEST.VALUE:E2E_P07.E2E_P07Check.Length: in branch 4 to unknown value
      Cannot set NewDataAvailable due to assignment
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-8718

TEST.END_NOTES:
TEST.VALUE:E2E_P07.E2E_P07Check.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P07.E2E_P07Check.ConfigPtr[0].Offset:5
TEST.VALUE:E2E_P07.E2E_P07Check.ConfigPtr[0].MinDataLength:5
TEST.VALUE:E2E_P07.E2E_P07Check.ConfigPtr[0].MaxDataLength:55
TEST.VALUE:E2E_P07.E2E_P07Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_P07.E2E_P07Check.Length:1
TEST.END

-- Test Case: BASIS-PATH-011-PARTIAL.003
TEST.UNIT:E2E_P07
TEST.SUBPROGRAM:E2E_P07Check
TEST.NEW
TEST.NAME:BASIS-PATH-011-PARTIAL.003
TEST.NOTES:
This is an automatically generated test case.
   Test Path 11
      (1) if ((void *)0 != ConfigPtr && (void *)0 != StatePtr) ==> TRUE
      (2) if ((void *)0 != DataPtr && (0U) != Length || (void *)0 == DataPtr && (0U) == Length) ==> TRUE
      (3) if ((void *)0 != DataPtr) ==> TRUE
      (4) if (Length >= ConfigPtr->MinDataLength >> 3U && Length <= ConfigPtr->MaxDataLength >> 3U) ==> TRUE
      (5) if ((0U) < ConfigPtr->Offset) ==> FALSE
      (6) if (1U == NewDataAvailable) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable TEST.VALUE:E2E_P07.E2E_P07Check.Length: in branch 4 to unknown value
      Cannot set NewDataAvailable due to assignment
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-8718

TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.Crc_CalculateCRC64.return:0
TEST.VALUE:E2E_P07.E2E_P07Check.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P07.E2E_P07Check.ConfigPtr[0].DataID:0
TEST.VALUE:E2E_P07.E2E_P07Check.ConfigPtr[0].Offset:5
TEST.VALUE:E2E_P07.E2E_P07Check.ConfigPtr[0].MinDataLength:5
TEST.VALUE:E2E_P07.E2E_P07Check.ConfigPtr[0].MaxDataLength:55
TEST.VALUE:E2E_P07.E2E_P07Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr:<<malloc 20>>
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr[8]:0
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr[9]:0
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr[10]:0
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr[11]:1
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr[12]:0
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr[13]:0
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr[14]:0
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr[15]:0
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr[16]:0
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr[17]:0
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr[18]:0
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr[19]:0
TEST.VALUE:E2E_P07.E2E_P07Check.Length:1
TEST.END

-- Test Case: BASIS-PATH-011-PARTIAL.004
TEST.UNIT:E2E_P07
TEST.SUBPROGRAM:E2E_P07Check
TEST.NEW
TEST.NAME:BASIS-PATH-011-PARTIAL.004
TEST.NOTES:
This is an automatically generated test case.
   Test Path 11
      (1) if ((void *)0 != ConfigPtr && (void *)0 != StatePtr) ==> TRUE
      (2) if ((void *)0 != DataPtr && (0U) != Length || (void *)0 == DataPtr && (0U) == Length) ==> TRUE
      (3) if ((void *)0 != DataPtr) ==> TRUE
      (4) if (Length >= ConfigPtr->MinDataLength >> 3U && Length <= ConfigPtr->MaxDataLength >> 3U) ==> TRUE
      (5) if ((0U) < ConfigPtr->Offset) ==> FALSE
      (6) if (1U == NewDataAvailable) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable TEST.VALUE:E2E_P07.E2E_P07Check.Length: in branch 4 to unknown value
      Cannot set NewDataAvailable due to assignment
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-8718

TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.Crc_CalculateCRC64.return:0
TEST.VALUE:E2E_P07.E2E_P07Check.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P07.E2E_P07Check.ConfigPtr[0].DataID:0
TEST.VALUE:E2E_P07.E2E_P07Check.ConfigPtr[0].Offset:5
TEST.VALUE:E2E_P07.E2E_P07Check.ConfigPtr[0].MinDataLength:5
TEST.VALUE:E2E_P07.E2E_P07Check.ConfigPtr[0].MaxDataLength:55
TEST.VALUE:E2E_P07.E2E_P07Check.ConfigPtr[0].MaxDeltaCounter:5
TEST.VALUE:E2E_P07.E2E_P07Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr:<<malloc 20>>
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr[8]:0
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr[9]:0
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr[10]:0
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr[11]:1
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr[12]:0
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr[13]:0
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr[14]:0
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr[15]:010
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr[16]:0
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr[17]:0
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr[18]:0
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr[19]:0
TEST.VALUE:E2E_P07.E2E_P07Check.Length:1
TEST.END

-- Test Case: BASIS-PATH-011-PARTIAL.005
TEST.UNIT:E2E_P07
TEST.SUBPROGRAM:E2E_P07Check
TEST.NEW
TEST.NAME:BASIS-PATH-011-PARTIAL.005
TEST.NOTES:
This is an automatically generated test case.
   Test Path 11
      (1) if ((void *)0 != ConfigPtr && (void *)0 != StatePtr) ==> TRUE
      (2) if ((void *)0 != DataPtr && (0U) != Length || (void *)0 == DataPtr && (0U) == Length) ==> TRUE
      (3) if ((void *)0 != DataPtr) ==> TRUE
      (4) if (Length >= ConfigPtr->MinDataLength >> 3U && Length <= ConfigPtr->MaxDataLength >> 3U) ==> TRUE
      (5) if ((0U) < ConfigPtr->Offset) ==> FALSE
      (6) if (1U == NewDataAvailable) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable TEST.VALUE:E2E_P07.E2E_P07Check.Length: in branch 4 to unknown value
      Cannot set NewDataAvailable due to assignment
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-8718

TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.Crc_CalculateCRC64.return:0
TEST.VALUE:E2E_P07.E2E_P07Check.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P07.E2E_P07Check.ConfigPtr[0].DataID:0
TEST.VALUE:E2E_P07.E2E_P07Check.ConfigPtr[0].Offset:5
TEST.VALUE:E2E_P07.E2E_P07Check.ConfigPtr[0].MinDataLength:5
TEST.VALUE:E2E_P07.E2E_P07Check.ConfigPtr[0].MaxDataLength:55
TEST.VALUE:E2E_P07.E2E_P07Check.ConfigPtr[0].MaxDeltaCounter:15
TEST.VALUE:E2E_P07.E2E_P07Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr:<<malloc 20>>
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr[8]:0
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr[9]:0
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr[10]:0
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr[11]:1
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr[12]:0
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr[13]:0
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr[14]:0
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr[15]:15
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr[16]:0
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr[17]:0
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr[18]:0
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr[19]:0
TEST.VALUE:E2E_P07.E2E_P07Check.Length:1
TEST.END

-- Test Case: BASIS-PATH-011-PARTIAL.006
TEST.UNIT:E2E_P07
TEST.SUBPROGRAM:E2E_P07Check
TEST.NEW
TEST.NAME:BASIS-PATH-011-PARTIAL.006
TEST.NOTES:
This is an automatically generated test case.
   Test Path 11
      (1) if ((void *)0 != ConfigPtr && (void *)0 != StatePtr) ==> TRUE
      (2) if ((void *)0 != DataPtr && (0U) != Length || (void *)0 == DataPtr && (0U) == Length) ==> TRUE
      (3) if ((void *)0 != DataPtr) ==> TRUE
      (4) if (Length >= ConfigPtr->MinDataLength >> 3U && Length <= ConfigPtr->MaxDataLength >> 3U) ==> TRUE
      (5) if ((0U) < ConfigPtr->Offset) ==> FALSE
      (6) if (1U == NewDataAvailable) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable TEST.VALUE:E2E_P07.E2E_P07Check.Length: in branch 4 to unknown value
      Cannot set NewDataAvailable due to assignment
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-8718

TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.Crc_CalculateCRC64.return:0
TEST.VALUE:E2E_P07.E2E_P07Check.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P07.E2E_P07Check.ConfigPtr[0].DataID:0
TEST.VALUE:E2E_P07.E2E_P07Check.ConfigPtr[0].Offset:5
TEST.VALUE:E2E_P07.E2E_P07Check.ConfigPtr[0].MinDataLength:5
TEST.VALUE:E2E_P07.E2E_P07Check.ConfigPtr[0].MaxDataLength:55
TEST.VALUE:E2E_P07.E2E_P07Check.ConfigPtr[0].MaxDeltaCounter:1
TEST.VALUE:E2E_P07.E2E_P07Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr:<<malloc 20>>
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr[8]:0
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr[9]:0
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr[10]:0
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr[11]:1
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr[12]:0
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr[13]:0
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr[14]:0
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr[15]:1
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr[16]:0
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr[17]:0
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr[18]:0
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr[19]:0
TEST.VALUE:E2E_P07.E2E_P07Check.Length:1
TEST.END

-- Test Case: BASIS-PATH-011-PARTIAL.007
TEST.UNIT:E2E_P07
TEST.SUBPROGRAM:E2E_P07Check
TEST.NEW
TEST.NAME:BASIS-PATH-011-PARTIAL.007
TEST.NOTES:
This is an automatically generated test case.
   Test Path 11
      (1) if ((void *)0 != ConfigPtr && (void *)0 != StatePtr) ==> TRUE
      (2) if ((void *)0 != DataPtr && (0U) != Length || (void *)0 == DataPtr && (0U) == Length) ==> TRUE
      (3) if ((void *)0 != DataPtr) ==> TRUE
      (4) if (Length >= ConfigPtr->MinDataLength >> 3U && Length <= ConfigPtr->MaxDataLength >> 3U) ==> TRUE
      (5) if ((0U) < ConfigPtr->Offset) ==> FALSE
      (6) if (1U == NewDataAvailable) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable TEST.VALUE:E2E_P07.E2E_P07Check.Length: in branch 4 to unknown value
      Cannot set NewDataAvailable due to assignment
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-8718

TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.Crc_CalculateCRC64.return:0
TEST.VALUE:E2E_P07.E2E_P07Check.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P07.E2E_P07Check.ConfigPtr[0].DataID:0
TEST.VALUE:E2E_P07.E2E_P07Check.ConfigPtr[0].Offset:5
TEST.VALUE:E2E_P07.E2E_P07Check.ConfigPtr[0].MinDataLength:5
TEST.VALUE:E2E_P07.E2E_P07Check.ConfigPtr[0].MaxDataLength:55
TEST.VALUE:E2E_P07.E2E_P07Check.ConfigPtr[0].MaxDeltaCounter:1
TEST.VALUE:E2E_P07.E2E_P07Check.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P07.E2E_P07Check.StatePtr[0].Counter:456
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr:<<malloc 20>>
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr[8]:0
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr[9]:0
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr[10]:0
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr[11]:1
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr[12]:0
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr[13]:0
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr[14]:0
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr[15]:1
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr[16]:0
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr[17]:0
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr[18]:0
TEST.VALUE:E2E_P07.E2E_P07Check.DataPtr[19]:0
TEST.VALUE:E2E_P07.E2E_P07Check.Length:1
TEST.END

-- Subprogram: E2E_P07CheckInit

-- Test Case: BASIS-PATH-001
TEST.UNIT:E2E_P07
TEST.SUBPROGRAM:E2E_P07CheckInit
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((void *)0 != StatePtr) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-8718

TEST.END_NOTES:
TEST.VALUE:E2E_P07.E2E_P07CheckInit.StatePtr:<<null>>
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:E2E_P07
TEST.SUBPROGRAM:E2E_P07CheckInit
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if ((void *)0 != StatePtr) ==> TRUE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-8718

TEST.END_NOTES:
TEST.VALUE:E2E_P07.E2E_P07CheckInit.StatePtr:<<malloc 1>>
TEST.END

-- Subprogram: E2E_P07MapStatusToSM

-- Test Case: BASIS-PATH-001
TEST.UNIT:E2E_P07
TEST.SUBPROGRAM:E2E_P07MapStatusToSM
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 7
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (CheckReturn == 0U) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-8718

TEST.END_NOTES:
TEST.VALUE:E2E_P07.E2E_P07MapStatusToSM.CheckReturn:1
TEST.VALUE:E2E_P07.E2E_P07MapStatusToSM.Status:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:E2E_P07
TEST.SUBPROGRAM:E2E_P07MapStatusToSM
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 7
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (CheckReturn == 0U) ==> TRUE
      (2) if ((E2E_P07STATUS_OK) == Status || (E2E_P07STATUS_OKSOMELOST) == Status) ==> FALSE
      (3) if ((E2E_P07STATUS_ERROR) == Status) ==> FALSE
      (4) if ((E2E_P07STATUS_REPEATED) == Status) ==> FALSE
      (5) if ((E2E_P07STATUS_NONEWDATA) == Status) ==> FALSE
      (6) if ((E2E_P07STATUS_WRONGSEQUENCE) == Status) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-8718

TEST.END_NOTES:
TEST.VALUE:E2E_P07.E2E_P07MapStatusToSM.CheckReturn:0
TEST.VALUE:E2E_P07.E2E_P07MapStatusToSM.Status:65
TEST.END

-- Test Case: BASIS-PATH-003
TEST.UNIT:E2E_P07
TEST.SUBPROGRAM:E2E_P07MapStatusToSM
TEST.NEW
TEST.NAME:BASIS-PATH-003
TEST.BASIS_PATH:3 of 7
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (CheckReturn == 0U) ==> TRUE
      (2) if ((E2E_P07STATUS_OK) == Status || (E2E_P07STATUS_OKSOMELOST) == Status) ==> FALSE
      (3) if ((E2E_P07STATUS_ERROR) == Status) ==> FALSE
      (4) if ((E2E_P07STATUS_REPEATED) == Status) ==> FALSE
      (5) if ((E2E_P07STATUS_NONEWDATA) == Status) ==> FALSE
      (6) if ((E2E_P07STATUS_WRONGSEQUENCE) == Status) ==> TRUE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-8718

TEST.END_NOTES:
TEST.VALUE:E2E_P07.E2E_P07MapStatusToSM.CheckReturn:0
TEST.VALUE:E2E_P07.E2E_P07MapStatusToSM.Status:E2E_P07STATUS_WRONGSEQUENCE
TEST.END

-- Test Case: BASIS-PATH-004
TEST.UNIT:E2E_P07
TEST.SUBPROGRAM:E2E_P07MapStatusToSM
TEST.NEW
TEST.NAME:BASIS-PATH-004
TEST.BASIS_PATH:4 of 7
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if (CheckReturn == 0U) ==> TRUE
      (2) if ((E2E_P07STATUS_OK) == Status || (E2E_P07STATUS_OKSOMELOST) == Status) ==> FALSE
      (3) if ((E2E_P07STATUS_ERROR) == Status) ==> FALSE
      (4) if ((E2E_P07STATUS_REPEATED) == Status) ==> FALSE
      (5) if ((E2E_P07STATUS_NONEWDATA) == Status) ==> TRUE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-8718

TEST.END_NOTES:
TEST.VALUE:E2E_P07.E2E_P07MapStatusToSM.CheckReturn:0
TEST.VALUE:E2E_P07.E2E_P07MapStatusToSM.Status:E2E_P07STATUS_NONEWDATA
TEST.END

-- Test Case: BASIS-PATH-005
TEST.UNIT:E2E_P07
TEST.SUBPROGRAM:E2E_P07MapStatusToSM
TEST.NEW
TEST.NAME:BASIS-PATH-005
TEST.BASIS_PATH:5 of 7
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (1) if (CheckReturn == 0U) ==> TRUE
      (2) if ((E2E_P07STATUS_OK) == Status || (E2E_P07STATUS_OKSOMELOST) == Status) ==> FALSE
      (3) if ((E2E_P07STATUS_ERROR) == Status) ==> FALSE
      (4) if ((E2E_P07STATUS_REPEATED) == Status) ==> TRUE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-8718

TEST.END_NOTES:
TEST.VALUE:E2E_P07.E2E_P07MapStatusToSM.CheckReturn:0
TEST.VALUE:E2E_P07.E2E_P07MapStatusToSM.Status:E2E_P07STATUS_REPEATED
TEST.END

-- Test Case: BASIS-PATH-006
TEST.UNIT:E2E_P07
TEST.SUBPROGRAM:E2E_P07MapStatusToSM
TEST.NEW
TEST.NAME:BASIS-PATH-006
TEST.BASIS_PATH:6 of 7
TEST.NOTES:
This is an automatically generated test case.
   Test Path 6
      (1) if (CheckReturn == 0U) ==> TRUE
      (2) if ((E2E_P07STATUS_OK) == Status || (E2E_P07STATUS_OKSOMELOST) == Status) ==> FALSE
      (3) if ((E2E_P07STATUS_ERROR) == Status) ==> TRUE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-8718

TEST.END_NOTES:
TEST.VALUE:E2E_P07.E2E_P07MapStatusToSM.CheckReturn:0
TEST.VALUE:E2E_P07.E2E_P07MapStatusToSM.Status:E2E_P07STATUS_ERROR
TEST.END

-- Test Case: BASIS-PATH-007
TEST.UNIT:E2E_P07
TEST.SUBPROGRAM:E2E_P07MapStatusToSM
TEST.NEW
TEST.NAME:BASIS-PATH-007
TEST.BASIS_PATH:7 of 7
TEST.NOTES:
This is an automatically generated test case.
   Test Path 7
      (1) if (CheckReturn == 0U) ==> TRUE
      (2) if ((E2E_P07STATUS_OK) == Status || (E2E_P07STATUS_OKSOMELOST) == Status) ==> TRUE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-8718

TEST.END_NOTES:
TEST.VALUE:E2E_P07.E2E_P07MapStatusToSM.CheckReturn:0
TEST.VALUE:E2E_P07.E2E_P07MapStatusToSM.Status:E2E_P07STATUS_OK
TEST.END

-- Subprogram: E2E_P07Protect

-- Test Case: BASIS-PATH-001
TEST.UNIT:E2E_P07
TEST.SUBPROGRAM:E2E_P07Protect
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 4
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (((void *)0 != ConfigPtr && (void *)0 != StatePtr) && (void *)0 != DataPtr) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-8718

TEST.END_NOTES:
TEST.VALUE:E2E_P07.E2E_P07Protect.ConfigPtr:<<null>>
TEST.VALUE:E2E_P07.E2E_P07Protect.StatePtr:<<null>>
TEST.VALUE:E2E_P07.E2E_P07Protect.DataPtr:<<malloc 9>>
TEST.VALUE:E2E_P07.E2E_P07Protect.DataPtr:<<null>>
TEST.VALUE:E2E_P07.E2E_P07Protect.Length:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:E2E_P07
TEST.SUBPROGRAM:E2E_P07Protect
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 4
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (((void *)0 != ConfigPtr && (void *)0 != StatePtr) && (void *)0 != DataPtr) ==> TRUE
      (2) if (Length >= ConfigPtr->MinDataLength >> 3U && Length <= ConfigPtr->MaxDataLength >> 3U) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-8718

TEST.END_NOTES:
TEST.VALUE:E2E_P07.E2E_P07Protect.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P07.E2E_P07Protect.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P07.E2E_P07Protect.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_P07.E2E_P07Protect.Length:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-002.001
TEST.UNIT:E2E_P07
TEST.SUBPROGRAM:E2E_P07Protect
TEST.NEW
TEST.NAME:BASIS-PATH-002.001
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (((void *)0 != ConfigPtr && (void *)0 != StatePtr) && (void *)0 != DataPtr) ==> TRUE
      (2) if (Length >= ConfigPtr->MinDataLength >> 3U && Length <= ConfigPtr->MaxDataLength >> 3U) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-8718

TEST.END_NOTES:
TEST.VALUE:E2E_P07.E2E_P07Protect.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P07.E2E_P07Protect.ConfigPtr[0].MinDataLength:55
TEST.VALUE:E2E_P07.E2E_P07Protect.ConfigPtr[0].MaxDataLength:55
TEST.VALUE:E2E_P07.E2E_P07Protect.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P07.E2E_P07Protect.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_P07.E2E_P07Protect.Length:0
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:E2E_P07
TEST.SUBPROGRAM:E2E_P07Protect
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 4 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (((void *)0 != ConfigPtr && (void *)0 != StatePtr) && (void *)0 != DataPtr) ==> TRUE
      (2) if (Length >= ConfigPtr->MinDataLength >> 3U && Length <= ConfigPtr->MaxDataLength >> 3U) ==> TRUE
      (3) if ((0U) < ConfigPtr->Offset) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable TEST.VALUE:E2E_P07.E2E_P07Protect.Length: in branch 2 to unknown value
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-8718

TEST.END_NOTES:
TEST.VALUE:E2E_P07.E2E_P07Protect.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P07.E2E_P07Protect.ConfigPtr[0].Offset:<<MIN>>
TEST.VALUE:E2E_P07.E2E_P07Protect.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P07.E2E_P07Protect.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_P07.E2E_P07Protect.Length:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:E2E_P07
TEST.SUBPROGRAM:E2E_P07Protect
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 4 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if (((void *)0 != ConfigPtr && (void *)0 != StatePtr) && (void *)0 != DataPtr) ==> TRUE
      (2) if (Length >= ConfigPtr->MinDataLength >> 3U && Length <= ConfigPtr->MaxDataLength >> 3U) ==> TRUE
      (3) if ((0U) < ConfigPtr->Offset) ==> TRUE
   Test Case Generation Notes:
      Cannot set variable TEST.VALUE:E2E_P07.E2E_P07Protect.Length: in branch 2 to unknown value
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-8718

TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.Crc_CalculateCRC64.Crc_DataPtr:"1"
TEST.VALUE:E2E_P07.E2E_P07Protect.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_P07.E2E_P07Protect.ConfigPtr[0].DataID:0
TEST.VALUE:E2E_P07.E2E_P07Protect.ConfigPtr[0].Offset:55
TEST.VALUE:E2E_P07.E2E_P07Protect.ConfigPtr[0].MinDataLength:5
TEST.VALUE:E2E_P07.E2E_P07Protect.ConfigPtr[0].MaxDataLength:15
TEST.VALUE:E2E_P07.E2E_P07Protect.ConfigPtr[0].MaxDeltaCounter:50
TEST.VALUE:E2E_P07.E2E_P07Protect.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_P07.E2E_P07Protect.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_P07.E2E_P07Protect.Length:<<MIN>>
TEST.END

-- Subprogram: E2E_P07ProtectInit

-- Test Case: BASIS-PATH-001
TEST.UNIT:E2E_P07
TEST.SUBPROGRAM:E2E_P07ProtectInit
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((void *)0 != StatePtr) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-8718

TEST.END_NOTES:
TEST.VALUE:E2E_P07.E2E_P07ProtectInit.StatePtr:<<null>>
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:E2E_P07
TEST.SUBPROGRAM:E2E_P07ProtectInit
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if ((void *)0 != StatePtr) ==> TRUE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-8718

TEST.END_NOTES:
TEST.VALUE:E2E_P07.E2E_P07ProtectInit.StatePtr:<<malloc 1>>
TEST.END

-- Unit: E2E_SM

-- Subprogram: E2E_SMCheck

-- Test Case: BASIS-PATH-001
TEST.UNIT:E2E_SM
TEST.SUBPROGRAM:E2E_SMCheck
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 12
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (StatePtr != (void *)0 && ConfigPtr != (void *)0) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7606
TEST.END_NOTES:
TEST.VALUE:E2E_SM.E2E_SMCheck.ProfileStatus:<<MIN>>
TEST.VALUE:E2E_SM.E2E_SMCheck.ConfigPtr:<<null>>
TEST.VALUE:E2E_SM.E2E_SMCheck.StatePtr:<<null>>
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:E2E_SM
TEST.SUBPROGRAM:E2E_SMCheck
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 12
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (StatePtr != (void *)0 && ConfigPtr != (void *)0) ==> TRUE
      (12) case (StatePtr->SMState) ==> default
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7606
TEST.END_NOTES:
TEST.VALUE:E2E_SM.E2E_SMCheck.ProfileStatus:<<MIN>>
TEST.VALUE:E2E_SM.E2E_SMCheck.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_SM.E2E_SMCheck.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_SM.E2E_SMCheck.StatePtr[0].SMState:5
TEST.END

-- Test Case: BASIS-PATH-003
TEST.UNIT:E2E_SM
TEST.SUBPROGRAM:E2E_SMCheck
TEST.NEW
TEST.NAME:BASIS-PATH-003
TEST.BASIS_PATH:3 of 12
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (StatePtr != (void *)0 && ConfigPtr != (void *)0) ==> TRUE
      (2) case (StatePtr->SMState) ==> E2E_SM_VALID
      (3) if (StatePtr->OkCount <= ConfigPtr->MaxErrorStateInit && StatePtr->OkCount >= ConfigPtr->MinOkStateInit) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7606
TEST.END_NOTES:
TEST.VALUE:E2E_SM.E2E_SMCheck.ProfileStatus:<<MIN>>
TEST.VALUE:E2E_SM.E2E_SMCheck.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_SM.E2E_SMCheck.ConfigPtr[0].MaxErrorStateInit:<<MIN>>
TEST.VALUE:E2E_SM.E2E_SMCheck.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_SM.E2E_SMCheck.StatePtr[0].OkCount:<<MAX>>
TEST.VALUE:E2E_SM.E2E_SMCheck.StatePtr[0].SMState:E2E_SM_VALID
TEST.END

-- Test Case: BASIS-PATH-004
TEST.UNIT:E2E_SM
TEST.SUBPROGRAM:E2E_SMCheck
TEST.NEW
TEST.NAME:BASIS-PATH-004
TEST.BASIS_PATH:4 of 12
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if (StatePtr != (void *)0 && ConfigPtr != (void *)0) ==> TRUE
      (2) case (StatePtr->SMState) ==> E2E_SM_VALID
      (3) if (StatePtr->OkCount <= ConfigPtr->MaxErrorStateInit && StatePtr->OkCount >= ConfigPtr->MinOkStateInit) ==> TRUE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7606
TEST.END_NOTES:
TEST.VALUE:E2E_SM.E2E_SMCheck.ProfileStatus:<<MIN>>
TEST.VALUE:E2E_SM.E2E_SMCheck.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_SM.E2E_SMCheck.ConfigPtr[0].MinOkStateInit:<<MIN>>
TEST.VALUE:E2E_SM.E2E_SMCheck.ConfigPtr[0].MaxErrorStateInit:<<MAX>>
TEST.VALUE:E2E_SM.E2E_SMCheck.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_SM.E2E_SMCheck.StatePtr[0].OkCount:<<MIN>>
TEST.VALUE:E2E_SM.E2E_SMCheck.StatePtr[0].SMState:E2E_SM_VALID
TEST.END

-- Test Case: BASIS-PATH-005
TEST.UNIT:E2E_SM
TEST.SUBPROGRAM:E2E_SMCheck
TEST.NEW
TEST.NAME:BASIS-PATH-005
TEST.BASIS_PATH:5 of 12
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (1) if (StatePtr != (void *)0 && ConfigPtr != (void *)0) ==> TRUE
      (4) case (StatePtr->SMState) ==> E2E_SM_DEINIT
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7606
TEST.END_NOTES:
TEST.VALUE:E2E_SM.E2E_SMCheck.ProfileStatus:<<MIN>>
TEST.VALUE:E2E_SM.E2E_SMCheck.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_SM.E2E_SMCheck.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_SM.E2E_SMCheck.StatePtr[0].SMState:E2E_SM_DEINIT
TEST.END

-- Test Case: BASIS-PATH-006
TEST.UNIT:E2E_SM
TEST.SUBPROGRAM:E2E_SMCheck
TEST.NEW
TEST.NAME:BASIS-PATH-006
TEST.BASIS_PATH:6 of 12
TEST.NOTES:
This is an automatically generated test case.
   Test Path 6
      (1) if (StatePtr != (void *)0 && ConfigPtr != (void *)0) ==> TRUE
      (5) case (StatePtr->SMState) ==> E2E_SM_NODATA
      (6) if (ProfileStatus != (E2E_P_ERROR) && ProfileStatus != (E2E_P_NONEWDATA)) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7606
TEST.END_NOTES:
TEST.VALUE:E2E_SM.E2E_SMCheck.ProfileStatus:E2E_P_ERROR
TEST.VALUE:E2E_SM.E2E_SMCheck.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_SM.E2E_SMCheck.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_SM.E2E_SMCheck.StatePtr[0].SMState:E2E_SM_NODATA
TEST.END

-- Test Case: BASIS-PATH-007
TEST.UNIT:E2E_SM
TEST.SUBPROGRAM:E2E_SMCheck
TEST.NEW
TEST.NAME:BASIS-PATH-007
TEST.BASIS_PATH:7 of 12
TEST.NOTES:
This is an automatically generated test case.
   Test Path 7
      (1) if (StatePtr != (void *)0 && ConfigPtr != (void *)0) ==> TRUE
      (5) case (StatePtr->SMState) ==> E2E_SM_NODATA
      (6) if (ProfileStatus != (E2E_P_ERROR) && ProfileStatus != (E2E_P_NONEWDATA)) ==> TRUE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7606
TEST.END_NOTES:
TEST.VALUE:E2E_SM.E2E_SMCheck.ProfileStatus:E2E_P_OK
TEST.VALUE:E2E_SM.E2E_SMCheck.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_SM.E2E_SMCheck.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_SM.E2E_SMCheck.StatePtr[0].SMState:E2E_SM_NODATA
TEST.END

-- Test Case: BASIS-PATH-008
TEST.UNIT:E2E_SM
TEST.SUBPROGRAM:E2E_SMCheck
TEST.NEW
TEST.NAME:BASIS-PATH-008
TEST.BASIS_PATH:8 of 12
TEST.NOTES:
This is an automatically generated test case.
   Test Path 8
      (1) if (StatePtr != (void *)0 && ConfigPtr != (void *)0) ==> TRUE
      (7) case (StatePtr->SMState) ==> E2E_SM_INIT
      (8) if (StatePtr->ErrorCount > ConfigPtr->MaxErrorStateInit) ==> FALSE
      (9) if (StatePtr->OkCount <= ConfigPtr->MaxErrorStateInit && StatePtr->OkCount >= ConfigPtr->MinOkStateInit) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7606
TEST.END_NOTES:
TEST.VALUE:E2E_SM.E2E_SMCheck.ProfileStatus:<<MIN>>
TEST.VALUE:E2E_SM.E2E_SMCheck.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_SM.E2E_SMCheck.ConfigPtr[0].MaxErrorStateInit:<<MIN>>
TEST.VALUE:E2E_SM.E2E_SMCheck.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_SM.E2E_SMCheck.StatePtr[0].OkCount:<<MAX>>
TEST.VALUE:E2E_SM.E2E_SMCheck.StatePtr[0].ErrorCount:<<MIN>>
TEST.VALUE:E2E_SM.E2E_SMCheck.StatePtr[0].SMState:E2E_SM_INIT
TEST.END

-- Test Case: BASIS-PATH-009
TEST.UNIT:E2E_SM
TEST.SUBPROGRAM:E2E_SMCheck
TEST.NEW
TEST.NAME:BASIS-PATH-009
TEST.BASIS_PATH:9 of 12
TEST.NOTES:
This is an automatically generated test case.
   Test Path 9
      (1) if (StatePtr != (void *)0 && ConfigPtr != (void *)0) ==> TRUE
      (7) case (StatePtr->SMState) ==> E2E_SM_INIT
      (8) if (StatePtr->ErrorCount > ConfigPtr->MaxErrorStateInit) ==> FALSE
      (9) if (StatePtr->OkCount <= ConfigPtr->MaxErrorStateInit && StatePtr->OkCount >= ConfigPtr->MinOkStateInit) ==> TRUE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7606
TEST.END_NOTES:
TEST.VALUE:E2E_SM.E2E_SMCheck.ProfileStatus:<<MIN>>
TEST.VALUE:E2E_SM.E2E_SMCheck.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_SM.E2E_SMCheck.ConfigPtr[0].MinOkStateInit:<<MIN>>
TEST.VALUE:E2E_SM.E2E_SMCheck.ConfigPtr[0].MaxErrorStateInit:<<MAX>>
TEST.VALUE:E2E_SM.E2E_SMCheck.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_SM.E2E_SMCheck.StatePtr[0].OkCount:<<MIN>>
TEST.VALUE:E2E_SM.E2E_SMCheck.StatePtr[0].ErrorCount:<<MIN>>
TEST.VALUE:E2E_SM.E2E_SMCheck.StatePtr[0].SMState:E2E_SM_INIT
TEST.END

-- Test Case: BASIS-PATH-010
TEST.UNIT:E2E_SM
TEST.SUBPROGRAM:E2E_SMCheck
TEST.NEW
TEST.NAME:BASIS-PATH-010
TEST.BASIS_PATH:10 of 12
TEST.NOTES:
This is an automatically generated test case.
   Test Path 10
      (1) if (StatePtr != (void *)0 && ConfigPtr != (void *)0) ==> TRUE
      (7) case (StatePtr->SMState) ==> E2E_SM_INIT
      (8) if (StatePtr->ErrorCount > ConfigPtr->MaxErrorStateInit) ==> TRUE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7606
TEST.END_NOTES:
TEST.VALUE:E2E_SM.E2E_SMCheck.ProfileStatus:<<MIN>>
TEST.VALUE:E2E_SM.E2E_SMCheck.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_SM.E2E_SMCheck.ConfigPtr[0].MaxErrorStateInit:<<MIN>>
TEST.VALUE:E2E_SM.E2E_SMCheck.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_SM.E2E_SMCheck.StatePtr[0].ErrorCount:<<MAX>>
TEST.VALUE:E2E_SM.E2E_SMCheck.StatePtr[0].SMState:E2E_SM_INIT
TEST.END

-- Test Case: BASIS-PATH-011
TEST.UNIT:E2E_SM
TEST.SUBPROGRAM:E2E_SMCheck
TEST.NEW
TEST.NAME:BASIS-PATH-011
TEST.BASIS_PATH:11 of 12
TEST.NOTES:
This is an automatically generated test case.
   Test Path 11
      (1) if (StatePtr != (void *)0 && ConfigPtr != (void *)0) ==> TRUE
      (10) case (StatePtr->SMState) ==> E2E_SM_INVALID
      (11) if (StatePtr->OkCount <= ConfigPtr->MaxErrorStateInit && StatePtr->OkCount >= ConfigPtr->MinOkStateInit) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7606
TEST.END_NOTES:
TEST.VALUE:E2E_SM.E2E_SMCheck.ProfileStatus:<<MIN>>
TEST.VALUE:E2E_SM.E2E_SMCheck.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_SM.E2E_SMCheck.ConfigPtr[0].MaxErrorStateInit:<<MIN>>
TEST.VALUE:E2E_SM.E2E_SMCheck.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_SM.E2E_SMCheck.StatePtr[0].OkCount:<<MAX>>
TEST.VALUE:E2E_SM.E2E_SMCheck.StatePtr[0].SMState:E2E_SM_INVALID
TEST.END

-- Test Case: BASIS-PATH-012
TEST.UNIT:E2E_SM
TEST.SUBPROGRAM:E2E_SMCheck
TEST.NEW
TEST.NAME:BASIS-PATH-012
TEST.BASIS_PATH:12 of 12
TEST.NOTES:
This is an automatically generated test case.
   Test Path 12
      (1) if (StatePtr != (void *)0 && ConfigPtr != (void *)0) ==> TRUE
      (10) case (StatePtr->SMState) ==> E2E_SM_INVALID
      (11) if (StatePtr->OkCount <= ConfigPtr->MaxErrorStateInit && StatePtr->OkCount >= ConfigPtr->MinOkStateInit) ==> TRUE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7606
TEST.END_NOTES:
TEST.VALUE:E2E_SM.E2E_SMCheck.ProfileStatus:<<MIN>>
TEST.VALUE:E2E_SM.E2E_SMCheck.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_SM.E2E_SMCheck.ConfigPtr[0].MinOkStateInit:<<MIN>>
TEST.VALUE:E2E_SM.E2E_SMCheck.ConfigPtr[0].MaxErrorStateInit:<<MAX>>
TEST.VALUE:E2E_SM.E2E_SMCheck.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_SM.E2E_SMCheck.StatePtr[0].OkCount:<<MIN>>
TEST.VALUE:E2E_SM.E2E_SMCheck.StatePtr[0].SMState:E2E_SM_INVALID
TEST.END

-- Subprogram: E2E_SMCheckInit

-- Test Case: E2E_SMCheckInit.001
TEST.UNIT:E2E_SM
TEST.SUBPROGRAM:E2E_SMCheckInit
TEST.NEW
TEST.NAME:E2E_SMCheckInit.001
TEST.NOTES:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7606
TEST.END_NOTES:
TEST.VALUE:E2E_SM.E2E_SMCheckInit.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_SM.E2E_SMCheckInit.StatePtr[0].ProfileStatusWindow:<<malloc 2>>
TEST.VALUE:E2E_SM.E2E_SMCheckInit.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_SM.E2E_SMCheckInit.ConfigPtr[0].WindowSize:2
TEST.EXPECTED:E2E_SM.E2E_SMCheckInit.return:0
TEST.END

-- Test Case: E2E_SMCheckInit.002
TEST.UNIT:E2E_SM
TEST.SUBPROGRAM:E2E_SMCheckInit
TEST.NEW
TEST.NAME:E2E_SMCheckInit.002
TEST.NOTES:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7606
TEST.END_NOTES:
TEST.VALUE:E2E_SM.E2E_SMCheckInit.StatePtr:<<null>>
TEST.VALUE:E2E_SM.E2E_SMCheckInit.ConfigPtr:<<malloc 1>>
TEST.EXPECTED:E2E_SM.E2E_SMCheckInit.return:19
TEST.END

-- Unit: E2E_UserProfile

-- Subprogram: E2E_CheckUserProfile8BitCheckSumCheck

-- Test Case: E2E_CheckUserProfile8BitCheckSumCheck.001
TEST.UNIT:E2E_UserProfile
TEST.SUBPROGRAM:E2E_CheckUserProfile8BitCheckSumCheck
TEST.NEW
TEST.NAME:E2E_CheckUserProfile8BitCheckSumCheck.001
TEST.NOTES:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7608
TEST.END_NOTES:
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.ConfigPtr[0].CounterOffset:2
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.StatePtr[0].Status:E2E_USERPROFILE8BITCHECKSUMSTATUS_OK
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.StatePtr[0].Cal_wind_Time:5
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.StatePtr[0].Error_count:3
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.StatePtr[0].Check_Timecounter:2
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.DataPtr[0]:5
TEST.END

-- Test Case: E2E_CheckUserProfile8BitCheckSumCheck.002
TEST.UNIT:E2E_UserProfile
TEST.SUBPROGRAM:E2E_CheckUserProfile8BitCheckSumCheck
TEST.NEW
TEST.NAME:E2E_CheckUserProfile8BitCheckSumCheck.002
TEST.NOTES:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7608
TEST.END_NOTES:
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.ConfigPtr[0].CounterOffset:2
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.StatePtr[0].Status:E2E_USERPROFILE8BITCHECKSUMSTATUS_OK
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.StatePtr[0].Cal_wind_Time:5
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.StatePtr[0].Error_count:3
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.StatePtr[0].Check_Timecounter:2
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.DataPtr[0]:5
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.Length:3
TEST.END

-- Test Case: E2E_CheckUserProfile8BitCheckSumCheck.003
TEST.UNIT:E2E_UserProfile
TEST.SUBPROGRAM:E2E_CheckUserProfile8BitCheckSumCheck
TEST.NEW
TEST.NAME:E2E_CheckUserProfile8BitCheckSumCheck.003
TEST.NOTES:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7608
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.Checksum_CalculateCheckSum8.return:5
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.ConfigPtr[0].CounterOffset:1
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.StatePtr[0].Status:E2E_USERPROFILE8BITCHECKSUMSTATUS_OK
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.StatePtr[0].Cal_wind_Time:5
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.StatePtr[0].Error_count:3
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.StatePtr[0].Check_Timecounter:2
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.DataPtr[0]:5
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.Length:3
TEST.END

-- Test Case: E2E_CheckUserProfile8BitCheckSumCheck.004
TEST.UNIT:E2E_UserProfile
TEST.SUBPROGRAM:E2E_CheckUserProfile8BitCheckSumCheck
TEST.NEW
TEST.NAME:E2E_CheckUserProfile8BitCheckSumCheck.004
TEST.NOTES:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7608
TEST.END_NOTES:
TEST.STUB:E2E_UserProfile.E2E_ProcessRollingCounter
TEST.VALUE:uut_prototype_stubs.Checksum_CalculateCheckSum8.return:5
TEST.VALUE:E2E_UserProfile.E2E_ProcessRollingCounter.StatePtr[0].Status:E2E_USERPROFILE8BITCHECKSUMSTATUS_ERROR
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.ConfigPtr[0].CounterOffset:1
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.DataPtr[0]:5
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.Length:3
TEST.ATTRIBUTES:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.DataPtr[1]::INPUT_BASE=16
TEST.END

-- Test Case: E2E_CheckUserProfile8BitCheckSumCheck.005
TEST.UNIT:E2E_UserProfile
TEST.SUBPROGRAM:E2E_CheckUserProfile8BitCheckSumCheck
TEST.NEW
TEST.NAME:E2E_CheckUserProfile8BitCheckSumCheck.005
TEST.NOTES:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7608
TEST.END_NOTES:
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.ConfigPtr[0].CounterOffset:1
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.StatePtr[0].Status:E2E_USERPROFILE8BITCHECKSUMSTATUS_OK
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.StatePtr[0].Cal_wind_Time:5
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.StatePtr[0].Error_count:3
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.StatePtr[0].Check_Timecounter:2
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.DataPtr:<<malloc 2>>
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.DataPtr[0]:5
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.DataPtr[1]:0x5
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.Length:3
TEST.END

-- Test Case: E2E_CheckUserProfile8BitCheckSumCheck.006
TEST.UNIT:E2E_UserProfile
TEST.SUBPROGRAM:E2E_CheckUserProfile8BitCheckSumCheck
TEST.NEW
TEST.NAME:E2E_CheckUserProfile8BitCheckSumCheck.006
TEST.NOTES:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7608
TEST.END_NOTES:
TEST.END

-- Test Case: E2E_CheckUserProfile8BitCheckSumCheck.007
TEST.UNIT:E2E_UserProfile
TEST.SUBPROGRAM:E2E_CheckUserProfile8BitCheckSumCheck
TEST.NEW
TEST.NAME:E2E_CheckUserProfile8BitCheckSumCheck.007
TEST.NOTES:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7608
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.Checksum_CalculateCheckSum8.return:5
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.ConfigPtr[0].CounterOffset:1
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.StatePtr[0].Status:E2E_USERPROFILE8BITCHECKSUMSTATUS_OK
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.StatePtr[0].Cal_wind_Time:5
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.StatePtr[0].Error_count:3
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.StatePtr[0].Check_Timecounter:2
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.DataPtr:<<malloc 2>>
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.DataPtr[0]:5
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.DataPtr[1]:0x5
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.Length:3
TEST.END

-- Test Case: E2E_CheckUserProfile8BitCheckSumCheck.008
TEST.UNIT:E2E_UserProfile
TEST.SUBPROGRAM:E2E_CheckUserProfile8BitCheckSumCheck
TEST.NEW
TEST.NAME:E2E_CheckUserProfile8BitCheckSumCheck.008
TEST.NOTES:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7608
TEST.END_NOTES:
TEST.STUB:E2E_UserProfile.E2E_ProcessRollingCounter
TEST.VALUE:uut_prototype_stubs.Checksum_CalculateCheckSum8.return:5
TEST.VALUE:E2E_UserProfile.E2E_ProcessRollingCounter.StatePtr[0].Status:E2E_USERPROFILE8BITCHECKSUMSTATUS_ABN_CHECKSUM
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.ConfigPtr[0].CounterOffset:1
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.StatePtr:<<malloc 2>>
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.StatePtr[0].Status:E2E_USERPROFILE8BITCHECKSUMSTATUS_ROLLING_COUNTER_LOCK
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.StatePtr[0].Cal_wind_Time:5
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.StatePtr[0].Error_count:3
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.StatePtr[0].Check_Timecounter:2
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.StatePtr[1].Status:E2E_USERPROFILE8BITCHECKSUMSTATUS_ERROR
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.DataPtr:<<malloc 2>>
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.DataPtr[0]:5
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.DataPtr[1]:0x5
TEST.VALUE:E2E_UserProfile.E2E_CheckUserProfile8BitCheckSumCheck.Length:3
TEST.END

-- Subprogram: E2E_ProcessRollingCounter

-- Test Case: E2E_ProcessRollingCounter.001
TEST.UNIT:E2E_UserProfile
TEST.SUBPROGRAM:E2E_ProcessRollingCounter
TEST.NEW
TEST.NAME:E2E_ProcessRollingCounter.001
TEST.NOTES:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7608
TEST.END_NOTES:
TEST.VALUE:E2E_UserProfile.E2E_ProcessRollingCounter.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_UserProfile.E2E_ProcessRollingCounter.StatePtr[0].Check_Timecounter:0
TEST.VALUE:E2E_UserProfile.E2E_ProcessRollingCounter.ReceivedCounter:0
TEST.END

-- Test Case: E2E_ProcessRollingCounter.002
TEST.UNIT:E2E_UserProfile
TEST.SUBPROGRAM:E2E_ProcessRollingCounter
TEST.NEW
TEST.NAME:E2E_ProcessRollingCounter.002
TEST.NOTES:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7608
TEST.END_NOTES:
TEST.VALUE:E2E_UserProfile.E2E_ProcessRollingCounter.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_UserProfile.E2E_ProcessRollingCounter.StatePtr[0].Error_count:0xFFFFFFFF
TEST.VALUE:E2E_UserProfile.E2E_ProcessRollingCounter.StatePtr[0].Check_Timecounter:0
TEST.VALUE:E2E_UserProfile.E2E_ProcessRollingCounter.ReceivedCounter:0
TEST.END

-- Test Case: E2E_ProcessRollingCounter.003
TEST.UNIT:E2E_UserProfile
TEST.SUBPROGRAM:E2E_ProcessRollingCounter
TEST.NEW
TEST.NAME:E2E_ProcessRollingCounter.003
TEST.NOTES:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7608
TEST.END_NOTES:
TEST.VALUE:E2E_UserProfile.E2E_ProcessRollingCounter.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_UserProfile.E2E_ProcessRollingCounter.StatePtr[0].Cal_wind_Time:12
TEST.VALUE:E2E_UserProfile.E2E_ProcessRollingCounter.StatePtr[0].Check_Timecounter:0
TEST.VALUE:E2E_UserProfile.E2E_ProcessRollingCounter.ReceivedCounter:0
TEST.END

-- Test Case: E2E_ProcessRollingCounter.004
TEST.UNIT:E2E_UserProfile
TEST.SUBPROGRAM:E2E_ProcessRollingCounter
TEST.NEW
TEST.NAME:E2E_ProcessRollingCounter.004
TEST.NOTES:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7608
TEST.END_NOTES:
TEST.VALUE:E2E_UserProfile.E2E_ProcessRollingCounter.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_UserProfile.E2E_ProcessRollingCounter.StatePtr[0].Check_Timecounter:11
TEST.VALUE:E2E_UserProfile.E2E_ProcessRollingCounter.ReceivedCounter:7
TEST.END

-- Test Case: E2E_ProcessRollingCounter.005
TEST.UNIT:E2E_UserProfile
TEST.SUBPROGRAM:E2E_ProcessRollingCounter
TEST.NEW
TEST.NAME:E2E_ProcessRollingCounter.005
TEST.NOTES:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7608
TEST.END_NOTES:
TEST.VALUE:E2E_UserProfile.E2E_ProcessRollingCounter.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_UserProfile.E2E_ProcessRollingCounter.StatePtr[0].Cal_wind_Time:10
TEST.VALUE:E2E_UserProfile.E2E_ProcessRollingCounter.StatePtr[0].Check_Timecounter:0
TEST.VALUE:E2E_UserProfile.E2E_ProcessRollingCounter.ReceivedCounter:0
TEST.END

-- Test Case: E2E_ProcessRollingCounter.006
TEST.UNIT:E2E_UserProfile
TEST.SUBPROGRAM:E2E_ProcessRollingCounter
TEST.NEW
TEST.NAME:E2E_ProcessRollingCounter.006
TEST.NOTES:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7608
TEST.END_NOTES:
TEST.VALUE:E2E_UserProfile.E2E_ProcessRollingCounter.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_UserProfile.E2E_ProcessRollingCounter.StatePtr[0].Cal_wind_Time:10
TEST.VALUE:E2E_UserProfile.E2E_ProcessRollingCounter.StatePtr[0].Error_count:1
TEST.VALUE:E2E_UserProfile.E2E_ProcessRollingCounter.StatePtr[0].Check_Timecounter:0
TEST.VALUE:E2E_UserProfile.E2E_ProcessRollingCounter.ReceivedCounter:0
TEST.END

-- Subprogram: E2E_ProtectUserProfile8BitCheckSumProtect

-- Test Case: E2E_ProtectUserProfile8BitCheckSumProtect.001
TEST.UNIT:E2E_UserProfile
TEST.SUBPROGRAM:E2E_ProtectUserProfile8BitCheckSumProtect
TEST.NEW
TEST.NAME:E2E_ProtectUserProfile8BitCheckSumProtect.001
TEST.NOTES:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7608
TEST.END_NOTES:
TEST.VALUE:E2E_UserProfile.E2E_ProtectUserProfile8BitCheckSumProtect.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_UserProfile.E2E_ProtectUserProfile8BitCheckSumProtect.ConfigPtr[0].CounterOffset:3
TEST.VALUE:E2E_UserProfile.E2E_ProtectUserProfile8BitCheckSumProtect.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_UserProfile.E2E_ProtectUserProfile8BitCheckSumProtect.StatePtr[0].InitValue:2
TEST.VALUE:E2E_UserProfile.E2E_ProtectUserProfile8BitCheckSumProtect.StatePtr[0].Counter:4
TEST.VALUE:E2E_UserProfile.E2E_ProtectUserProfile8BitCheckSumProtect.StatePtr[0].Protect_Timecounter:3
TEST.VALUE:E2E_UserProfile.E2E_ProtectUserProfile8BitCheckSumProtect.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_UserProfile.E2E_ProtectUserProfile8BitCheckSumProtect.DataPtr[0]:2
TEST.END

-- Test Case: E2E_ProtectUserProfile8BitCheckSumProtect.002
TEST.UNIT:E2E_UserProfile
TEST.SUBPROGRAM:E2E_ProtectUserProfile8BitCheckSumProtect
TEST.NEW
TEST.NAME:E2E_ProtectUserProfile8BitCheckSumProtect.002
TEST.NOTES:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7608
TEST.END_NOTES:
TEST.VALUE:E2E_UserProfile.E2E_ProtectUserProfile8BitCheckSumProtect.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_UserProfile.E2E_ProtectUserProfile8BitCheckSumProtect.ConfigPtr[0].CounterOffset:3
TEST.VALUE:E2E_UserProfile.E2E_ProtectUserProfile8BitCheckSumProtect.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_UserProfile.E2E_ProtectUserProfile8BitCheckSumProtect.StatePtr[0].InitValue:2
TEST.VALUE:E2E_UserProfile.E2E_ProtectUserProfile8BitCheckSumProtect.StatePtr[0].Counter:4
TEST.VALUE:E2E_UserProfile.E2E_ProtectUserProfile8BitCheckSumProtect.StatePtr[0].Protect_Timecounter:3
TEST.VALUE:E2E_UserProfile.E2E_ProtectUserProfile8BitCheckSumProtect.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_UserProfile.E2E_ProtectUserProfile8BitCheckSumProtect.DataPtr[0]:2
TEST.VALUE:E2E_UserProfile.E2E_ProtectUserProfile8BitCheckSumProtect.Length:3
TEST.END

-- Test Case: E2E_ProtectUserProfile8BitCheckSumProtect.003
TEST.UNIT:E2E_UserProfile
TEST.SUBPROGRAM:E2E_ProtectUserProfile8BitCheckSumProtect
TEST.NEW
TEST.NAME:E2E_ProtectUserProfile8BitCheckSumProtect.003
TEST.NOTES:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7608
TEST.END_NOTES:
TEST.VALUE:E2E_UserProfile.E2E_ProtectUserProfile8BitCheckSumProtect.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_UserProfile.E2E_ProtectUserProfile8BitCheckSumProtect.ConfigPtr[0].CounterOffset:3
TEST.VALUE:E2E_UserProfile.E2E_ProtectUserProfile8BitCheckSumProtect.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_UserProfile.E2E_ProtectUserProfile8BitCheckSumProtect.StatePtr[0].InitValue:2
TEST.VALUE:E2E_UserProfile.E2E_ProtectUserProfile8BitCheckSumProtect.StatePtr[0].Counter:4
TEST.VALUE:E2E_UserProfile.E2E_ProtectUserProfile8BitCheckSumProtect.StatePtr[0].Protect_Timecounter:13
TEST.VALUE:E2E_UserProfile.E2E_ProtectUserProfile8BitCheckSumProtect.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_UserProfile.E2E_ProtectUserProfile8BitCheckSumProtect.DataPtr[0]:2
TEST.VALUE:E2E_UserProfile.E2E_ProtectUserProfile8BitCheckSumProtect.Length:3
TEST.END

-- Test Case: E2E_ProtectUserProfile8BitCheckSumProtect.004
TEST.UNIT:E2E_UserProfile
TEST.SUBPROGRAM:E2E_ProtectUserProfile8BitCheckSumProtect
TEST.NEW
TEST.NAME:E2E_ProtectUserProfile8BitCheckSumProtect.004
TEST.NOTES:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7608
TEST.END_NOTES:
TEST.VALUE:E2E_UserProfile.E2E_ProtectUserProfile8BitCheckSumProtect.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_UserProfile.E2E_ProtectUserProfile8BitCheckSumProtect.ConfigPtr[0].CounterOffset:3
TEST.VALUE:E2E_UserProfile.E2E_ProtectUserProfile8BitCheckSumProtect.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_UserProfile.E2E_ProtectUserProfile8BitCheckSumProtect.StatePtr[0].InitValue:1
TEST.VALUE:E2E_UserProfile.E2E_ProtectUserProfile8BitCheckSumProtect.StatePtr[0].Counter:4
TEST.VALUE:E2E_UserProfile.E2E_ProtectUserProfile8BitCheckSumProtect.StatePtr[0].Protect_Timecounter:3
TEST.VALUE:E2E_UserProfile.E2E_ProtectUserProfile8BitCheckSumProtect.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_UserProfile.E2E_ProtectUserProfile8BitCheckSumProtect.DataPtr[0]:2
TEST.VALUE:E2E_UserProfile.E2E_ProtectUserProfile8BitCheckSumProtect.Length:3
TEST.END

-- Test Case: E2E_ProtectUserProfile8BitCheckSumProtect.005
TEST.UNIT:E2E_UserProfile
TEST.SUBPROGRAM:E2E_ProtectUserProfile8BitCheckSumProtect
TEST.NEW
TEST.NAME:E2E_ProtectUserProfile8BitCheckSumProtect.005
TEST.NOTES:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7608
TEST.END_NOTES:
TEST.END

-- Test Case: E2E_ProtectUserProfile8BitCheckSumProtect.006
TEST.UNIT:E2E_UserProfile
TEST.SUBPROGRAM:E2E_ProtectUserProfile8BitCheckSumProtect
TEST.NEW
TEST.NAME:E2E_ProtectUserProfile8BitCheckSumProtect.006
TEST.NOTES:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7608
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.GetCounterValue.Value[0]:6
TEST.VALUE:E2E_UserProfile.E2E_ProtectUserProfile8BitCheckSumProtect.ConfigPtr:<<malloc 1>>
TEST.VALUE:E2E_UserProfile.E2E_ProtectUserProfile8BitCheckSumProtect.ConfigPtr[0].CounterOffset:3
TEST.VALUE:E2E_UserProfile.E2E_ProtectUserProfile8BitCheckSumProtect.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_UserProfile.E2E_ProtectUserProfile8BitCheckSumProtect.StatePtr[0].InitValue:2
TEST.VALUE:E2E_UserProfile.E2E_ProtectUserProfile8BitCheckSumProtect.StatePtr[0].Counter:4
TEST.VALUE:E2E_UserProfile.E2E_ProtectUserProfile8BitCheckSumProtect.StatePtr[0].Protect_Timecounter:3
TEST.VALUE:E2E_UserProfile.E2E_ProtectUserProfile8BitCheckSumProtect.DataPtr:<<malloc 1>>
TEST.VALUE:E2E_UserProfile.E2E_ProtectUserProfile8BitCheckSumProtect.DataPtr[0]:2
TEST.VALUE:E2E_UserProfile.E2E_ProtectUserProfile8BitCheckSumProtect.Length:3
TEST.END

-- Subprogram: E2E_UserProfile8BitCheckSumCheckInit

-- Test Case: E2E_UserProfile8BitCheckSumCheckInit.001
TEST.UNIT:E2E_UserProfile
TEST.SUBPROGRAM:E2E_UserProfile8BitCheckSumCheckInit
TEST.NEW
TEST.NAME:E2E_UserProfile8BitCheckSumCheckInit.001
TEST.NOTES:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7608
TEST.END_NOTES:
TEST.VALUE:E2E_UserProfile.E2E_UserProfile8BitCheckSumCheckInit.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_UserProfile.E2E_UserProfile8BitCheckSumCheckInit.StatePtr[0].Status:E2E_USERPROFILE8BITCHECKSUMSTATUS_OK
TEST.VALUE:E2E_UserProfile.E2E_UserProfile8BitCheckSumCheckInit.StatePtr[0].Cal_wind_Time:2
TEST.VALUE:E2E_UserProfile.E2E_UserProfile8BitCheckSumCheckInit.StatePtr[0].Error_count:4
TEST.VALUE:E2E_UserProfile.E2E_UserProfile8BitCheckSumCheckInit.StatePtr[0].Check_Timecounter:2
TEST.END

-- Test Case: E2E_UserProfile8BitCheckSumCheckInit.002
TEST.UNIT:E2E_UserProfile
TEST.SUBPROGRAM:E2E_UserProfile8BitCheckSumCheckInit
TEST.NEW
TEST.NAME:E2E_UserProfile8BitCheckSumCheckInit.002
TEST.NOTES:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7608
TEST.END_NOTES:
TEST.END

-- Subprogram: E2E_UserProfile8BitCheckSumProtectInit

-- Test Case: E2E_UserProfile8BitCheckSumProtectInit.001
TEST.UNIT:E2E_UserProfile
TEST.SUBPROGRAM:E2E_UserProfile8BitCheckSumProtectInit
TEST.NEW
TEST.NAME:E2E_UserProfile8BitCheckSumProtectInit.001
TEST.NOTES:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7608
TEST.END_NOTES:
TEST.VALUE:E2E_UserProfile.E2E_UserProfile8BitCheckSumProtectInit.StatePtr:<<malloc 1>>
TEST.VALUE:E2E_UserProfile.E2E_UserProfile8BitCheckSumProtectInit.StatePtr[0].InitValue:3
TEST.VALUE:E2E_UserProfile.E2E_UserProfile8BitCheckSumProtectInit.StatePtr[0].Counter:2
TEST.VALUE:E2E_UserProfile.E2E_UserProfile8BitCheckSumProtectInit.StatePtr[0].Protect_Timecounter:4
TEST.END

-- Test Case: E2E_UserProfile8BitCheckSumProtectInit.002
TEST.UNIT:E2E_UserProfile
TEST.SUBPROGRAM:E2E_UserProfile8BitCheckSumProtectInit
TEST.NEW
TEST.NAME:E2E_UserProfile8BitCheckSumProtectInit.002
TEST.NOTES:
SoftwareArchitecture::SYS::E2E::E2E_Detailed_Design::Class Diagram  E2E
Requirement_DICVA-7608
TEST.END_NOTES:
TEST.END
