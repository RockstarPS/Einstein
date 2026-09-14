-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : RUNTIME_PARSERIF_UT
-- Unit(s) Under Test: dk_runtime_parserif
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STANDARD_SPACING_R2
TEST.SCRIPT_FEATURE:OVERLOADED_CONST_SUPPORT
TEST.SCRIPT_FEATURE:UNDERSCORE_NULLPTR
TEST.SCRIPT_FEATURE:FULL_PARAMETER_TYPES
TEST.SCRIPT_FEATURE:STRUCT_DTOR_ADDS_POINTER
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: dk_runtime_parserif

-- Subprogram: (cl)dk::runtime::core::ParserIf::ParserIf

-- Test Case: 01_Initialization
TEST.UNIT:dk_runtime_parserif
TEST.SUBPROGRAM:(cl)dk::runtime::core::ParserIf::ParserIf
TEST.NEW
TEST.NAME:01_Initialization
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.END

-- Subprogram: (cl)dk::runtime::core::ParserIf::getAllKeysFromSection

-- Test Case: 01_GetAllKeys_failed
TEST.UNIT:dk_runtime_parserif
TEST.SUBPROGRAM:(cl)dk::runtime::core::ParserIf::getAllKeysFromSection
TEST.NEW
TEST.NAME:01_GetAllKeys_failed
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_parserif.<<GLOBAL>>.(cl).dk::runtime::core::ParserIf.dk::runtime::core::ParserIf.<<constructor>>.ParserIf().<<call>>:0
TEST.VALUE:dk_runtime_parserif.<<GLOBAL>>.(cl).dk::runtime::core::ParserIf.dk::runtime::core::ParserIf.mIsConfigurationLoaded:false
TEST.EXPECTED:dk_runtime_parserif.(cl)dk::runtime::core::ParserIf::getAllKeysFromSection.return:false
TEST.FLOW
  dk_runtime_parserif.cpp.(cl)dk::runtime::core::ParserIf::getAllKeysFromSection
  dk_runtime_parserif.cpp.(cl)dk::runtime::core::ParserIf::getAllKeysFromSection
TEST.END_FLOW
TEST.END

-- Test Case: 02_GetAllKeys_without_data
TEST.UNIT:dk_runtime_parserif
TEST.SUBPROGRAM:(cl)dk::runtime::core::ParserIf::getAllKeysFromSection
TEST.NEW
TEST.NAME:02_GetAllKeys_without_data
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_parserif.<<GLOBAL>>.(cl).dk::runtime::core::ParserIf.dk::runtime::core::ParserIf.<<constructor>>.ParserIf().<<call>>:0
TEST.VALUE:dk_runtime_parserif.<<GLOBAL>>.(cl).dk::runtime::core::ParserIf.dk::runtime::core::ParserIf.mParserInst.CSimpleIniTempl<char, SI_NoCase<char>, SI_ConvertA<char>>.m_data:<<malloc 1>>
TEST.VALUE:dk_runtime_parserif.<<GLOBAL>>.(cl).dk::runtime::core::ParserIf.dk::runtime::core::ParserIf.mParserInst.CSimpleIniTempl<char, SI_NoCase<char>, SI_ConvertA<char>>.m_data[0][0].CSimpleIniTempl<char, SI_NoCase<char>, SI_ConvertA<char>>::Entry.<<constructor>>.Entry(const char*,int).a_pszItem:<<malloc 5>>
TEST.VALUE:dk_runtime_parserif.<<GLOBAL>>.(cl).dk::runtime::core::ParserIf.dk::runtime::core::ParserIf.mParserInst.CSimpleIniTempl<char, SI_NoCase<char>, SI_ConvertA<char>>.m_data[0][0].CSimpleIniTempl<char, SI_NoCase<char>, SI_ConvertA<char>>::Entry.<<constructor>>.Entry(const char*,int).a_pszItem:"TEMP"
TEST.VALUE:dk_runtime_parserif.<<GLOBAL>>.(cl).dk::runtime::core::ParserIf.dk::runtime::core::ParserIf.mParserInst.CSimpleIniTempl<char, SI_NoCase<char>, SI_ConvertA<char>>.m_data[0][0].CSimpleIniTempl<char, SI_NoCase<char>, SI_ConvertA<char>>::Entry.<<constructor>>.Entry(const char*,int).<<call>>:0
TEST.VALUE:dk_runtime_parserif.<<GLOBAL>>.(cl).dk::runtime::core::ParserIf.dk::runtime::core::ParserIf.mParserInst.CSimpleIniTempl<char, SI_NoCase<char>, SI_ConvertA<char>>.m_data[0]:<<function 1>>
TEST.VALUE:dk_runtime_parserif.<<GLOBAL>>.(cl).dk::runtime::core::ParserIf.dk::runtime::core::ParserIf.mIsConfigurationLoaded:true
TEST.EXPECTED:dk_runtime_parserif.<<GLOBAL>>.(cl).dk::runtime::core::ParserIf.dk::runtime::core::ParserIf.mIsConfigurationLoaded:true
TEST.END

-- Test Case: 03_GetAllKeys_with_data
TEST.UNIT:dk_runtime_parserif
TEST.SUBPROGRAM:(cl)dk::runtime::core::ParserIf::getAllKeysFromSection
TEST.NEW
TEST.NAME:03_GetAllKeys_with_data
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_parserif.(cl)dk::runtime::core::ParserIf::getAllKeysFromSection.section:<<malloc 5>>
TEST.VALUE:dk_runtime_parserif.(cl)dk::runtime::core::ParserIf::getAllKeysFromSection.section:"temp"
TEST.FLOW
  dk_runtime_parserif.cpp.(cl)dk::runtime::core::ParserIf::getAllKeysFromSection
  dk_runtime_parserif.cpp.(cl)dk::runtime::core::ParserIf::getAllKeysFromSection
TEST.END_FLOW
TEST.VALUE_USER_CODE:<<dk::runtime::core::ParserIf instance>>
static dk::runtime::core::ParserIf temp;
temp.mIsConfigurationLoaded  = true;
temp.mParserInst.AddEntry("temp", "temp", "dummy", "dummy2", false, false);

<<dk::runtime::core::ParserIf instance>> = ( &temp );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::runtime::core::ParserIf::getAllSections

-- Test Case: 01_GetAllSections_failed
TEST.UNIT:dk_runtime_parserif
TEST.SUBPROGRAM:(cl)dk::runtime::core::ParserIf::getAllSections
TEST.NEW
TEST.NAME:01_GetAllSections_failed
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_parserif.<<GLOBAL>>.(cl).dk::runtime::core::ParserIf.dk::runtime::core::ParserIf.<<constructor>>.ParserIf().<<call>>:0
TEST.VALUE:dk_runtime_parserif.<<GLOBAL>>.(cl).dk::runtime::core::ParserIf.dk::runtime::core::ParserIf.mIsConfigurationLoaded:false
TEST.VALUE:dk_runtime_parserif.(cl)dk::runtime::core::ParserIf::getAllSections.sectionList:<<malloc 1>>
TEST.VALUE:dk_runtime_parserif.(cl)dk::runtime::core::ParserIf::getAllSections.sectionList[0]:<<function 1>>
TEST.EXPECTED:dk_runtime_parserif.(cl)dk::runtime::core::ParserIf::getAllSections.return:false
TEST.FLOW
  dk_runtime_parserif.cpp.(cl)dk::runtime::core::ParserIf::getAllSections
  dk_runtime_parserif.cpp.(cl)dk::runtime::core::ParserIf::getAllSections
TEST.END_FLOW
TEST.END

-- Test Case: 02_GetAllSections_with_data
TEST.UNIT:dk_runtime_parserif
TEST.SUBPROGRAM:(cl)dk::runtime::core::ParserIf::getAllSections
TEST.NEW
TEST.NAME:02_GetAllSections_with_data
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_parserif.<<GLOBAL>>.(cl).dk::runtime::core::ParserIf.dk::runtime::core::ParserIf.<<constructor>>.ParserIf().<<call>>:0
TEST.VALUE:dk_runtime_parserif.<<GLOBAL>>.(cl).dk::runtime::core::ParserIf.dk::runtime::core::ParserIf.mParserInst.CSimpleIniTempl<char, SI_NoCase<char>, SI_ConvertA<char>>.m_data:<<malloc 1>>
TEST.VALUE:dk_runtime_parserif.<<GLOBAL>>.(cl).dk::runtime::core::ParserIf.dk::runtime::core::ParserIf.mParserInst.CSimpleIniTempl<char, SI_NoCase<char>, SI_ConvertA<char>>.m_data[0][0].CSimpleIniTempl<char, SI_NoCase<char>, SI_ConvertA<char>>::Entry.<<constructor>>.Entry(const char*,int).<<call>>:0
TEST.VALUE:dk_runtime_parserif.<<GLOBAL>>.(cl).dk::runtime::core::ParserIf.dk::runtime::core::ParserIf.mParserInst.CSimpleIniTempl<char, SI_NoCase<char>, SI_ConvertA<char>>.m_data[0]:<<function 1>>
TEST.VALUE:dk_runtime_parserif.<<GLOBAL>>.(cl).dk::runtime::core::ParserIf.dk::runtime::core::ParserIf.mIsConfigurationLoaded:true
TEST.VALUE:dk_runtime_parserif.(cl)dk::runtime::core::ParserIf::getAllSections.sectionList:<<malloc 1>>
TEST.VALUE:dk_runtime_parserif.(cl)dk::runtime::core::ParserIf::getAllSections.sectionList[0]:<<function 1>>
TEST.EXPECTED:dk_runtime_parserif.<<GLOBAL>>.(cl).dk::runtime::core::ParserIf.dk::runtime::core::ParserIf.mIsConfigurationLoaded:true
TEST.END

-- Subprogram: (cl)dk::runtime::core::ParserIf::getAllValuesForKey

-- Test Case: 01_GetAllValues_with_data
TEST.UNIT:dk_runtime_parserif
TEST.SUBPROGRAM:(cl)dk::runtime::core::ParserIf::getAllValuesForKey
TEST.NEW
TEST.NAME:01_GetAllValues_with_data
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_parserif.(cl)dk::runtime::core::ParserIf::getAllValuesForKey.section:<<malloc 5>>
TEST.VALUE:dk_runtime_parserif.(cl)dk::runtime::core::ParserIf::getAllValuesForKey.section:"Test"
TEST.VALUE:dk_runtime_parserif.(cl)dk::runtime::core::ParserIf::getAllValuesForKey.key:<<malloc 5>>
TEST.VALUE:dk_runtime_parserif.(cl)dk::runtime::core::ParserIf::getAllValuesForKey.key:"Temp"
TEST.EXPECTED:dk_runtime_parserif.(cl)dk::runtime::core::ParserIf::getAllValuesForKey.section:"Test"
TEST.EXPECTED:dk_runtime_parserif.(cl)dk::runtime::core::ParserIf::getAllValuesForKey.key:"Temp"
TEST.VALUE_USER_CODE:<<dk::runtime::core::ParserIf instance>>
static dk::runtime::core::ParserIf temp;
temp.mIsConfigurationLoaded  = true;
temp.mParserInst.AddEntry("Test", "Temp", "dummy", "dummy2", false, false);
<<dk::runtime::core::ParserIf instance>> = ( &temp );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 02_GetAllValues_failed
TEST.UNIT:dk_runtime_parserif
TEST.SUBPROGRAM:(cl)dk::runtime::core::ParserIf::getAllValuesForKey
TEST.NEW
TEST.NAME:02_GetAllValues_failed
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_parserif.<<GLOBAL>>.(cl).dk::runtime::core::ParserIf.dk::runtime::core::ParserIf.<<constructor>>.ParserIf().<<call>>:0
TEST.VALUE:dk_runtime_parserif.<<GLOBAL>>.(cl).dk::runtime::core::ParserIf.dk::runtime::core::ParserIf.mIsConfigurationLoaded:false
TEST.EXPECTED:dk_runtime_parserif.<<GLOBAL>>.(cl).dk::runtime::core::ParserIf.dk::runtime::core::ParserIf.mIsConfigurationLoaded:false
TEST.END

-- Test Case: 03_GetAllValues_without_data
TEST.UNIT:dk_runtime_parserif
TEST.SUBPROGRAM:(cl)dk::runtime::core::ParserIf::getAllValuesForKey
TEST.NEW
TEST.NAME:03_GetAllValues_without_data
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE_USER_CODE:<<dk::runtime::core::ParserIf instance>>
static dk::runtime::core::ParserIf temp;
temp.mIsConfigurationLoaded  = true;
temp.mParserInst.AddEntry("Test", "Temp", "dummy", "dummy2", false, false);
<<dk::runtime::core::ParserIf instance>> = ( &temp );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::runtime::core::ParserIf::getBoolValue

-- Test Case: 01_GetBoolValue_failed
TEST.UNIT:dk_runtime_parserif
TEST.SUBPROGRAM:(cl)dk::runtime::core::ParserIf::getBoolValue
TEST.NEW
TEST.NAME:01_GetBoolValue_failed
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_parserif.<<GLOBAL>>.(cl).dk::runtime::core::ParserIf.dk::runtime::core::ParserIf.<<constructor>>.ParserIf().<<call>>:0
TEST.VALUE:dk_runtime_parserif.<<GLOBAL>>.(cl).dk::runtime::core::ParserIf.dk::runtime::core::ParserIf.mIsConfigurationLoaded:false
TEST.EXPECTED:dk_runtime_parserif.(cl)dk::runtime::core::ParserIf::getBoolValue.return:false
TEST.END

-- Test Case: 02_GetBoolValue_succeeded
TEST.UNIT:dk_runtime_parserif
TEST.SUBPROGRAM:(cl)dk::runtime::core::ParserIf::getBoolValue
TEST.NEW
TEST.NAME:02_GetBoolValue_succeeded
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_parserif.<<GLOBAL>>.(cl).dk::runtime::core::ParserIf.dk::runtime::core::ParserIf.<<constructor>>.ParserIf().<<call>>:0
TEST.VALUE:dk_runtime_parserif.<<GLOBAL>>.(cl).dk::runtime::core::ParserIf.dk::runtime::core::ParserIf.mIsConfigurationLoaded:true
TEST.FLOW
  dk_runtime_parserif.cpp.(cl)dk::runtime::core::ParserIf::getBoolValue
  dk_runtime_parserif.cpp.(cl)dk::runtime::core::ParserIf::getBoolValue
TEST.END_FLOW
TEST.END

-- Subprogram: (cl)dk::runtime::core::ParserIf::getFloat64Value

-- Test Case: 01_GetFloat64Value_succeeded
TEST.UNIT:dk_runtime_parserif
TEST.SUBPROGRAM:(cl)dk::runtime::core::ParserIf::getFloat64Value
TEST.NEW
TEST.NAME:01_GetFloat64Value_succeeded
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_parserif.<<GLOBAL>>.(cl).dk::runtime::core::ParserIf.dk::runtime::core::ParserIf.<<constructor>>.ParserIf().<<call>>:0
TEST.VALUE:dk_runtime_parserif.<<GLOBAL>>.(cl).dk::runtime::core::ParserIf.dk::runtime::core::ParserIf.mIsConfigurationLoaded:true
TEST.FLOW
  dk_runtime_parserif.cpp.(cl)dk::runtime::core::ParserIf::getFloat64Value
  dk_runtime_parserif.cpp.(cl)dk::runtime::core::ParserIf::getFloat64Value
TEST.END_FLOW
TEST.END

-- Test Case: 02_GetFloat64Value_failed
TEST.UNIT:dk_runtime_parserif
TEST.SUBPROGRAM:(cl)dk::runtime::core::ParserIf::getFloat64Value
TEST.NEW
TEST.NAME:02_GetFloat64Value_failed
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_parserif.<<GLOBAL>>.(cl).dk::runtime::core::ParserIf.dk::runtime::core::ParserIf.<<constructor>>.ParserIf().<<call>>:0
TEST.VALUE:dk_runtime_parserif.<<GLOBAL>>.(cl).dk::runtime::core::ParserIf.dk::runtime::core::ParserIf.mIsConfigurationLoaded:false
TEST.FLOW
  dk_runtime_parserif.cpp.(cl)dk::runtime::core::ParserIf::getFloat64Value
  dk_runtime_parserif.cpp.(cl)dk::runtime::core::ParserIf::getFloat64Value
TEST.END_FLOW
TEST.END

-- Subprogram: (cl)dk::runtime::core::ParserIf::getInt32Value

-- Test Case: 01_GetInt32Value_succeeded
TEST.UNIT:dk_runtime_parserif
TEST.SUBPROGRAM:(cl)dk::runtime::core::ParserIf::getInt32Value
TEST.NEW
TEST.NAME:01_GetInt32Value_succeeded
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_parserif.<<GLOBAL>>.(cl).dk::runtime::core::ParserIf.dk::runtime::core::ParserIf.<<constructor>>.ParserIf().<<call>>:0
TEST.VALUE:dk_runtime_parserif.<<GLOBAL>>.(cl).dk::runtime::core::ParserIf.dk::runtime::core::ParserIf.mIsConfigurationLoaded:true
TEST.FLOW
  dk_runtime_parserif.cpp.(cl)dk::runtime::core::ParserIf::getInt32Value
  dk_runtime_parserif.cpp.(cl)dk::runtime::core::ParserIf::getInt32Value
TEST.END_FLOW
TEST.END

-- Test Case: 02_GetInt32Value_failed
TEST.UNIT:dk_runtime_parserif
TEST.SUBPROGRAM:(cl)dk::runtime::core::ParserIf::getInt32Value
TEST.NEW
TEST.NAME:02_GetInt32Value_failed
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_parserif.<<GLOBAL>>.(cl).dk::runtime::core::ParserIf.dk::runtime::core::ParserIf.<<constructor>>.ParserIf().<<call>>:0
TEST.VALUE:dk_runtime_parserif.<<GLOBAL>>.(cl).dk::runtime::core::ParserIf.dk::runtime::core::ParserIf.mIsConfigurationLoaded:false
TEST.FLOW
  dk_runtime_parserif.cpp.(cl)dk::runtime::core::ParserIf::getInt32Value
  dk_runtime_parserif.cpp.(cl)dk::runtime::core::ParserIf::getInt32Value
TEST.END_FLOW
TEST.END

-- Subprogram: (cl)dk::runtime::core::ParserIf::getStringValue

-- Test Case: (cl)dk::runtime::core::ParserIf::getStringValue.001
TEST.UNIT:dk_runtime_parserif
TEST.SUBPROGRAM:(cl)dk::runtime::core::ParserIf::getStringValue
TEST.NEW
TEST.NAME:(cl)dk::runtime::core::ParserIf::getStringValue.001
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_parserif.<<GLOBAL>>.(cl).dk::runtime::core::ParserIf.dk::runtime::core::ParserIf.<<constructor>>.ParserIf().<<call>>:0
TEST.END

-- Test Case: (cl)dk::runtime::core::ParserIf::getStringValue.002
TEST.UNIT:dk_runtime_parserif
TEST.SUBPROGRAM:(cl)dk::runtime::core::ParserIf::getStringValue
TEST.NEW
TEST.NAME:(cl)dk::runtime::core::ParserIf::getStringValue.002
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_parserif.<<GLOBAL>>.(cl).dk::runtime::core::ParserIf.dk::runtime::core::ParserIf.<<constructor>>.ParserIf().<<call>>:0
TEST.VALUE:dk_runtime_parserif.<<GLOBAL>>.(cl).dk::runtime::core::ParserIf.dk::runtime::core::ParserIf.mIsConfigurationLoaded:true
TEST.EXPECTED:dk_runtime_parserif.<<GLOBAL>>.(cl).dk::runtime::core::ParserIf.dk::runtime::core::ParserIf.mIsConfigurationLoaded:true
TEST.END

-- Subprogram: (cl)dk::runtime::core::ParserIf::loadConfiguration

-- Test Case: 01_Load_failed
TEST.UNIT:dk_runtime_parserif
TEST.SUBPROGRAM:(cl)dk::runtime::core::ParserIf::loadConfiguration
TEST.NEW
TEST.NAME:01_Load_failed
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_parserif.<<GLOBAL>>.(cl).dk::runtime::core::ParserIf.dk::runtime::core::ParserIf.<<constructor>>.ParserIf().<<call>>:0
TEST.VALUE:dk_runtime_parserif.<<GLOBAL>>.(cl).dk::runtime::core::ParserIf.dk::runtime::core::ParserIf.mParserInst.CSimpleIniTempl<char, SI_NoCase<char>, SI_ConvertA<char>>.m_data:<<malloc 1>>
TEST.VALUE:dk_runtime_parserif.<<GLOBAL>>.(cl).dk::runtime::core::ParserIf.dk::runtime::core::ParserIf.mParserInst.CSimpleIniTempl<char, SI_NoCase<char>, SI_ConvertA<char>>.m_data[0][0].CSimpleIniTempl<char, SI_NoCase<char>, SI_ConvertA<char>>::Entry.<<constructor>>.Entry(const char*,int).<<call>>:0
TEST.VALUE:dk_runtime_parserif.<<GLOBAL>>.(cl).dk::runtime::core::ParserIf.dk::runtime::core::ParserIf.mParserInst.CSimpleIniTempl<char, SI_NoCase<char>, SI_ConvertA<char>>.m_data[0]:<<function 1>>
TEST.VALUE:dk_runtime_parserif.<<GLOBAL>>.(cl).dk::runtime::core::ParserIf.dk::runtime::core::ParserIf.mIsConfigurationLoaded:true
TEST.EXPECTED:dk_runtime_parserif.(cl)dk::runtime::core::ParserIf::loadConfiguration.return:false
TEST.FLOW
  dk_runtime_parserif.cpp.(cl)dk::runtime::core::ParserIf::loadConfiguration
  dk_runtime_parserif.cpp.(cl)dk::runtime::core::ParserIf::loadConfiguration
TEST.END_FLOW
TEST.END

-- Test Case: 02_Load_success
TEST.UNIT:dk_runtime_parserif
TEST.SUBPROGRAM:(cl)dk::runtime::core::ParserIf::loadConfiguration
TEST.NEW
TEST.NAME:02_Load_success
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_parserif.<<GLOBAL>>.(cl).dk::runtime::core::ParserIf.dk::runtime::core::ParserIf.<<constructor>>.ParserIf().<<call>>:0
TEST.VALUE:dk_runtime_parserif.<<GLOBAL>>.(cl).dk::runtime::core::ParserIf.dk::runtime::core::ParserIf.mIsConfigurationLoaded:false
TEST.EXPECTED:dk_runtime_parserif.<<GLOBAL>>.(cl).dk::runtime::core::ParserIf.dk::runtime::core::ParserIf.mIsConfigurationLoaded:true
TEST.END

-- Subprogram: (cl)dk::runtime::core::ParserIf::~ParserIf

-- Test Case: 01_Deinitialization
TEST.UNIT:dk_runtime_parserif
TEST.SUBPROGRAM:(cl)dk::runtime::core::ParserIf::~ParserIf
TEST.NEW
TEST.NAME:01_Deinitialization
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_parserif.<<GLOBAL>>.(cl).dk::runtime::core::ParserIf.dk::runtime::core::ParserIf.<<constructor>>.ParserIf().<<call>>:0
TEST.END
