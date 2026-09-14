-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : RUNTIME_WDGIF_UT
-- Unit(s) Under Test: dk_runtime_wdgif
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

-- Unit: dk_runtime_wdgif

-- Subprogram: (cl)dk::runtime::core::WdgIf::WdgIf

-- Test Case: 01_Watchdodif_Constructor
TEST.UNIT:dk_runtime_wdgif
TEST.SUBPROGRAM:(cl)dk::runtime::core::WdgIf::WdgIf
TEST.NEW
TEST.NAME:01_Watchdodif_Constructor
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.FLOW
  dk_runtime_wdgif.cpp.(cl)dk::runtime::core::WdgIf::WdgIf
  dk_runtime_wdgif.cpp.(cl)dk::runtime::core::WdgIf::WdgIf
TEST.END_FLOW
TEST.END

-- Subprogram: (cl)dk::runtime::core::WdgIf::connect

-- Test Case: 01_Initialization_with_Wdg_Disabled
TEST.UNIT:dk_runtime_wdgif
TEST.SUBPROGRAM:(cl)dk::runtime::core::WdgIf::connect
TEST.NEW
TEST.NAME:01_Initialization_with_Wdg_Disabled
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_wdgif.<<GLOBAL>>.(cl).dk::runtime::core::WdgIf.dk::runtime::core::WdgIf.<<constructor>>.WdgIf().<<call>>:0
TEST.VALUE:dk_runtime_wdgif.<<GLOBAL>>.(cl).dk::runtime::core::WdgIf.dk::runtime::core::WdgIf.mWdgEn:false
TEST.EXPECTED:dk_runtime_wdgif.(cl)dk::runtime::core::WdgIf::connect.return:false
TEST.END

-- Test Case: 02_Initialization_with_Wdg_Enabled
TEST.UNIT:dk_runtime_wdgif
TEST.SUBPROGRAM:(cl)dk::runtime::core::WdgIf::connect
TEST.NEW
TEST.NAME:02_Initialization_with_Wdg_Enabled
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_wdgif.<<GLOBAL>>.(cl).dk::runtime::core::WdgIf.dk::runtime::core::WdgIf.<<constructor>>.WdgIf().<<call>>:0
TEST.VALUE:dk_runtime_wdgif.<<GLOBAL>>.(cl).dk::runtime::core::WdgIf.dk::runtime::core::WdgIf.mWdgEn:true
TEST.EXPECTED:dk_runtime_wdgif.(cl)dk::runtime::core::WdgIf::connect.return:true
TEST.END

-- Subprogram: (cl)dk::runtime::core::WdgIf::disconnect

-- Test Case: 01_Deinitialization_with_Wdg_Disabled
TEST.UNIT:dk_runtime_wdgif
TEST.SUBPROGRAM:(cl)dk::runtime::core::WdgIf::disconnect
TEST.NEW
TEST.NAME:01_Deinitialization_with_Wdg_Disabled
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_wdgif.<<GLOBAL>>.(cl).dk::runtime::core::WdgIf.dk::runtime::core::WdgIf.<<constructor>>.WdgIf().<<call>>:0
TEST.VALUE:dk_runtime_wdgif.<<GLOBAL>>.(cl).dk::runtime::core::WdgIf.dk::runtime::core::WdgIf.mWdgEn:false
TEST.EXPECTED:dk_runtime_wdgif.(cl)dk::runtime::core::WdgIf::disconnect.return:false
TEST.END

-- Test Case: 02_Deinitialization_with_Wdg_Enabled
TEST.UNIT:dk_runtime_wdgif
TEST.SUBPROGRAM:(cl)dk::runtime::core::WdgIf::disconnect
TEST.NEW
TEST.NAME:02_Deinitialization_with_Wdg_Enabled
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_wdgif.<<GLOBAL>>.(cl).dk::runtime::core::WdgIf.dk::runtime::core::WdgIf.<<constructor>>.WdgIf().<<call>>:0
TEST.VALUE:dk_runtime_wdgif.<<GLOBAL>>.(cl).dk::runtime::core::WdgIf.dk::runtime::core::WdgIf.mWdgEn:true
TEST.EXPECTED:dk_runtime_wdgif.(cl)dk::runtime::core::WdgIf::disconnect.return:true
TEST.END

-- Subprogram: (cl)dk::runtime::core::WdgIf::getGrantedTimeoutMs

-- Test Case: 01_GetGrantedTimeoutMs
TEST.UNIT:dk_runtime_wdgif
TEST.SUBPROGRAM:(cl)dk::runtime::core::WdgIf::getGrantedTimeoutMs
TEST.NEW
TEST.NAME:01_GetGrantedTimeoutMs
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_wdgif.<<GLOBAL>>.(cl).dk::runtime::core::WdgIf.dk::runtime::core::WdgIf.<<constructor>>.WdgIf().<<call>>:0
TEST.FLOW
  dk_runtime_wdgif.cpp.(cl)dk::runtime::core::WdgIf::getGrantedTimeoutMs
  dk_runtime_wdgif.cpp.(cl)dk::runtime::core::WdgIf::getGrantedTimeoutMs
TEST.END_FLOW
TEST.END

-- Subprogram: (cl)dk::runtime::core::WdgIf::getWatchdogEnabled

-- Test Case: 01_GetWatchdogEnabled_Success
TEST.UNIT:dk_runtime_wdgif
TEST.SUBPROGRAM:(cl)dk::runtime::core::WdgIf::getWatchdogEnabled
TEST.NEW
TEST.NAME:01_GetWatchdogEnabled_Success
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_wdgif.<<GLOBAL>>.(cl).dk::runtime::core::WdgIf.dk::runtime::core::WdgIf.<<constructor>>.WdgIf().<<call>>:0
TEST.FLOW
  dk_runtime_wdgif.cpp.(cl)dk::runtime::core::WdgIf::getWatchdogEnabled
  dk_runtime_wdgif.cpp.(cl)dk::runtime::core::WdgIf::getWatchdogEnabled
TEST.END_FLOW
TEST.END

-- Subprogram: (cl)dk::runtime::core::WdgIf::pause

-- Test Case: 01_Pause_Failed
TEST.UNIT:dk_runtime_wdgif
TEST.SUBPROGRAM:(cl)dk::runtime::core::WdgIf::pause
TEST.NEW
TEST.NAME:01_Pause_Failed
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_wdgif.<<GLOBAL>>.(cl).dk::runtime::core::WdgIf.dk::runtime::core::WdgIf.<<constructor>>.WdgIf().<<call>>:0
TEST.VALUE:dk_runtime_wdgif.<<GLOBAL>>.(cl).dk::runtime::core::WdgIf.dk::runtime::core::WdgIf.mWdgEn:false
TEST.EXPECTED:dk_runtime_wdgif.(cl)dk::runtime::core::WdgIf::pause.return:false
TEST.END

-- Test Case: 02_Pause_Success
TEST.UNIT:dk_runtime_wdgif
TEST.SUBPROGRAM:(cl)dk::runtime::core::WdgIf::pause
TEST.NEW
TEST.NAME:02_Pause_Success
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_wdgif.<<GLOBAL>>.(cl).dk::runtime::core::WdgIf.dk::runtime::core::WdgIf.<<constructor>>.WdgIf().<<call>>:0
TEST.VALUE:dk_runtime_wdgif.<<GLOBAL>>.(cl).dk::runtime::core::WdgIf.dk::runtime::core::WdgIf.mWdgEn:true
TEST.EXPECTED:dk_runtime_wdgif.(cl)dk::runtime::core::WdgIf::pause.return:true
TEST.END

-- Subprogram: (cl)dk::runtime::core::WdgIf::resume

-- Test Case: 01_Resume_Failed
TEST.UNIT:dk_runtime_wdgif
TEST.SUBPROGRAM:(cl)dk::runtime::core::WdgIf::resume
TEST.NEW
TEST.NAME:01_Resume_Failed
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_wdgif.<<GLOBAL>>.(cl).dk::runtime::core::WdgIf.dk::runtime::core::WdgIf.<<constructor>>.WdgIf().<<call>>:0
TEST.VALUE:dk_runtime_wdgif.<<GLOBAL>>.(cl).dk::runtime::core::WdgIf.dk::runtime::core::WdgIf.mWdgEn:false
TEST.EXPECTED:dk_runtime_wdgif.(cl)dk::runtime::core::WdgIf::resume.return:false
TEST.END

-- Test Case: 02_Resume_Success
TEST.UNIT:dk_runtime_wdgif
TEST.SUBPROGRAM:(cl)dk::runtime::core::WdgIf::resume
TEST.NEW
TEST.NAME:02_Resume_Success
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_wdgif.<<GLOBAL>>.(cl).dk::runtime::core::WdgIf.dk::runtime::core::WdgIf.<<constructor>>.WdgIf().<<call>>:0
TEST.VALUE:dk_runtime_wdgif.<<GLOBAL>>.(cl).dk::runtime::core::WdgIf.dk::runtime::core::WdgIf.mWdgEn:true
TEST.EXPECTED:dk_runtime_wdgif.(cl)dk::runtime::core::WdgIf::resume.return:true
TEST.END

-- Subprogram: (cl)dk::runtime::core::WdgIf::sendHeartbeat

-- Test Case: 01_SendHeartBeat_Failed
TEST.UNIT:dk_runtime_wdgif
TEST.SUBPROGRAM:(cl)dk::runtime::core::WdgIf::sendHeartbeat
TEST.NEW
TEST.NAME:01_SendHeartBeat_Failed
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_wdgif.<<GLOBAL>>.(cl).dk::runtime::core::WdgIf.dk::runtime::core::WdgIf.<<constructor>>.WdgIf().<<call>>:0
TEST.VALUE:dk_runtime_wdgif.<<GLOBAL>>.(cl).dk::runtime::core::WdgIf.dk::runtime::core::WdgIf.mWdgEn:false
TEST.FLOW
  dk_runtime_wdgif.cpp.(cl)dk::runtime::core::WdgIf::sendHeartbeat
  dk_runtime_wdgif.cpp.(cl)dk::runtime::core::WdgIf::sendHeartbeat
TEST.END_FLOW
TEST.END

-- Test Case: 02_SendHeartBeat_Success
TEST.UNIT:dk_runtime_wdgif
TEST.SUBPROGRAM:(cl)dk::runtime::core::WdgIf::sendHeartbeat
TEST.NEW
TEST.NAME:02_SendHeartBeat_Success
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_wdgif.<<GLOBAL>>.(cl).dk::runtime::core::WdgIf.dk::runtime::core::WdgIf.<<constructor>>.WdgIf().<<call>>:0
TEST.VALUE:dk_runtime_wdgif.<<GLOBAL>>.(cl).dk::runtime::core::WdgIf.dk::runtime::core::WdgIf.mWdgEn:true
TEST.FLOW
  dk_runtime_wdgif.cpp.(cl)dk::runtime::core::WdgIf::sendHeartbeat
  dk_runtime_wdgif.cpp.(cl)dk::runtime::core::WdgIf::sendHeartbeat
TEST.END_FLOW
TEST.END

-- Subprogram: (cl)dk::runtime::core::WdgIf::setWatchdogEnabled

-- Test Case: 01_SetWatchdogEnabled_Success
TEST.UNIT:dk_runtime_wdgif
TEST.SUBPROGRAM:(cl)dk::runtime::core::WdgIf::setWatchdogEnabled
TEST.NEW
TEST.NAME:01_SetWatchdogEnabled_Success
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_wdgif.<<GLOBAL>>.(cl).dk::runtime::core::WdgIf.dk::runtime::core::WdgIf.<<constructor>>.WdgIf().<<call>>:0
TEST.FLOW
  dk_runtime_wdgif.cpp.(cl)dk::runtime::core::WdgIf::setWatchdogEnabled
  dk_runtime_wdgif.cpp.(cl)dk::runtime::core::WdgIf::setWatchdogEnabled
TEST.END_FLOW
TEST.END

-- Subprogram: (cl)dk::runtime::core::WdgIf::start

-- Test Case: 01_Start_Failed
TEST.UNIT:dk_runtime_wdgif
TEST.SUBPROGRAM:(cl)dk::runtime::core::WdgIf::start
TEST.NEW
TEST.NAME:01_Start_Failed
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_wdgif.<<GLOBAL>>.(cl).dk::runtime::core::WdgIf.dk::runtime::core::WdgIf.<<constructor>>.WdgIf().<<call>>:0
TEST.VALUE:dk_runtime_wdgif.<<GLOBAL>>.(cl).dk::runtime::core::WdgIf.dk::runtime::core::WdgIf.mWdgEn:false
TEST.EXPECTED:dk_runtime_wdgif.(cl)dk::runtime::core::WdgIf::start.return:false
TEST.END

-- Test Case: 02_Start_Success
TEST.UNIT:dk_runtime_wdgif
TEST.SUBPROGRAM:(cl)dk::runtime::core::WdgIf::start
TEST.NEW
TEST.NAME:02_Start_Success
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_wdgif.<<GLOBAL>>.(cl).dk::runtime::core::WdgIf.dk::runtime::core::WdgIf.<<constructor>>.WdgIf().<<call>>:0
TEST.VALUE:dk_runtime_wdgif.<<GLOBAL>>.(cl).dk::runtime::core::WdgIf.dk::runtime::core::WdgIf.mWdgEn:true
TEST.EXPECTED:dk_runtime_wdgif.(cl)dk::runtime::core::WdgIf::start.return:true
TEST.END

-- Subprogram: (cl)dk::runtime::core::WdgIf::stop

-- Test Case: 01_Stop_Failed
TEST.UNIT:dk_runtime_wdgif
TEST.SUBPROGRAM:(cl)dk::runtime::core::WdgIf::stop
TEST.NEW
TEST.NAME:01_Stop_Failed
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_wdgif.<<GLOBAL>>.(cl).dk::runtime::core::WdgIf.dk::runtime::core::WdgIf.<<constructor>>.WdgIf().<<call>>:0
TEST.VALUE:dk_runtime_wdgif.<<GLOBAL>>.(cl).dk::runtime::core::WdgIf.dk::runtime::core::WdgIf.mWdgEn:false
TEST.EXPECTED:dk_runtime_wdgif.(cl)dk::runtime::core::WdgIf::stop.return:false
TEST.END

-- Test Case: 02_Stop_Success
TEST.UNIT:dk_runtime_wdgif
TEST.SUBPROGRAM:(cl)dk::runtime::core::WdgIf::stop
TEST.NEW
TEST.NAME:02_Stop_Success
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_wdgif.<<GLOBAL>>.(cl).dk::runtime::core::WdgIf.dk::runtime::core::WdgIf.<<constructor>>.WdgIf().<<call>>:0
TEST.VALUE:dk_runtime_wdgif.<<GLOBAL>>.(cl).dk::runtime::core::WdgIf.dk::runtime::core::WdgIf.mWdgEn:true
TEST.EXPECTED:dk_runtime_wdgif.(cl)dk::runtime::core::WdgIf::stop.return:true
TEST.END

-- Subprogram: (cl)dk::runtime::core::WdgIf::~WdgIf

-- Test Case: 01_WatchDogif_Destructor
TEST.UNIT:dk_runtime_wdgif
TEST.SUBPROGRAM:(cl)dk::runtime::core::WdgIf::~WdgIf
TEST.NEW
TEST.NAME:01_WatchDogif_Destructor
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_wdgif.<<GLOBAL>>.(cl).dk::runtime::core::WdgIf.dk::runtime::core::WdgIf.<<constructor>>.WdgIf().<<call>>:0
TEST.VALUE:dk_runtime_wdgif.<<GLOBAL>>.(cl).dk::runtime::core::WdgIf.dk::runtime::core::WdgIf.mWdgEn:true
TEST.FLOW
  dk_runtime_wdgif.cpp.(cl)dk::runtime::core::WdgIf::~WdgIf
  dk_runtime_wdgif.cpp.(cl)dk::runtime::core::WdgIf::~WdgIf
TEST.END_FLOW
TEST.END
