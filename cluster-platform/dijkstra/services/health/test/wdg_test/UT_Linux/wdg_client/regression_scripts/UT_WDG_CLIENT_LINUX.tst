-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : UT_WDG_CLIENT_LINUX
-- Unit(s) Under Test: wdg_client
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

-- Unit: wdg_client

-- Subprogram: (cl)dk::srvc::health::WdgClient::WdgClient

-- Test Case: (cl)dk::srvc::health::WdgClient::WdgClient.constructor
TEST.UNIT:wdg_client
TEST.SUBPROGRAM:(cl)dk::srvc::health::WdgClient::WdgClient
TEST.NEW
TEST.NAME:(cl)dk::srvc::health::WdgClient::WdgClient.constructor
TEST.NOTES:
WdgClient in GIP_INFRA::InfrastructureServices::WdgClient (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.END

-- Subprogram: (cl)dk::srvc::health::WdgClient::connect

-- Test Case: Test_WdgClient_Connect_Success
TEST.UNIT:wdg_client
TEST.SUBPROGRAM:(cl)dk::srvc::health::WdgClient::connect
TEST.NEW
TEST.NAME:Test_WdgClient_Connect_Success
TEST.NOTES:
WdgClient in GIP_INFRA::InfrastructureServices::WdgClient (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.<<constructor>>.WdgClient().<<call>>:0
TEST.EXPECTED:wdg_client.(cl)dk::srvc::health::WdgClient::connect.return:-1
TEST.END

-- Subprogram: (cl)dk::srvc::health::WdgClient::disconnect

-- Test Case: Test_WdgClient_Disconnect_Success
TEST.UNIT:wdg_client
TEST.SUBPROGRAM:(cl)dk::srvc::health::WdgClient::disconnect
TEST.NEW
TEST.NAME:Test_WdgClient_Disconnect_Success
TEST.NOTES:
WdgClient in GIP_INFRA::InfrastructureServices::WdgClient (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:wdg_client.<<GLOBAL>>.dk::srvc::health::WdgClient::mpHandle:<<malloc 1>>
TEST.VALUE:wdg_client.<<GLOBAL>>.dk::srvc::health::WdgClient::mpHandle[0]:1
TEST.VALUE:wdg_client.(cl)dk::srvc::health::WdgClient::disconnect.return:0
TEST.EXPECTED:wdg_client.(cl)dk::srvc::health::WdgClient::disconnect.return:0
TEST.END

-- Test Case: Test_WdgClient_Disconnect_mpHandle_NULL
TEST.UNIT:wdg_client
TEST.SUBPROGRAM:(cl)dk::srvc::health::WdgClient::disconnect
TEST.NEW
TEST.NAME:Test_WdgClient_Disconnect_mpHandle_NULL
TEST.NOTES:
WdgClient in GIP_INFRA::InfrastructureServices::WdgClient (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:wdg_client.<<GLOBAL>>.dk::srvc::health::WdgClient::mpHandle:<<null>>
TEST.VALUE:wdg_client.(cl)dk::srvc::health::WdgClient::disconnect.return:-1
TEST.EXPECTED:wdg_client.(cl)dk::srvc::health::WdgClient::disconnect.return:-1
TEST.END

-- Subprogram: (cl)dk::srvc::health::WdgClient::getInstance

-- Test Case: Test_WdgClient_getInstance_NullPtr_Failure
TEST.UNIT:wdg_client
TEST.SUBPROGRAM:(cl)dk::srvc::health::WdgClient::getInstance
TEST.NEW
TEST.NAME:Test_WdgClient_getInstance_NullPtr_Failure
TEST.NOTES:
WdgClient in GIP_INFRA::InfrastructureServices::WdgClient (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.<<constructor>>.WdgClient().<<call>>:0
TEST.VALUE:wdg_client.(cl)dk::srvc::health::WdgClient::getInstance.return.dk::srvc::health::WdgClient.<<constructor>>.WdgClient().<<call>>:0
TEST.VALUE:wdg_client.(cl)dk::srvc::health::WdgClient::getInstance.return.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mpWdgClient.dk::srvc::health::WdgClient.<<constructor>>.WdgClient().<<call>>:0
TEST.END

-- Test Case: Test_WdgClient_getInstance_NullPtr_Success
TEST.UNIT:wdg_client
TEST.SUBPROGRAM:(cl)dk::srvc::health::WdgClient::getInstance
TEST.NEW
TEST.NAME:Test_WdgClient_getInstance_NullPtr_Success
TEST.NOTES:
WdgClient in GIP_INFRA::InfrastructureServices::WdgClient (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.<<constructor>>.WdgClient().<<call>>:0
TEST.VALUE:wdg_client.(cl)dk::srvc::health::WdgClient::getInstance.return.dk::srvc::health::WdgClient.<<constructor>>.WdgClient().<<call>>:0
TEST.END

-- Subprogram: (cl)dk::srvc::health::WdgClient::pause

-- Test Case: Test_WdgClient_Pause_NullMpHandle_ReturnsError
TEST.UNIT:wdg_client
TEST.SUBPROGRAM:(cl)dk::srvc::health::WdgClient::pause
TEST.NEW
TEST.NAME:Test_WdgClient_Pause_NullMpHandle_ReturnsError
TEST.NOTES:
WdgClient in GIP_INFRA::InfrastructureServices::WdgClient (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:wdg_client.<<GLOBAL>>.dk::srvc::health::WdgClient::mWdgThreadList:<<malloc 1>>
TEST.VALUE:wdg_client.<<GLOBAL>>.dk::srvc::health::WdgClient::mWdgThreadList[0]:<<malloc 1>>
TEST.VALUE:wdg_client.<<GLOBAL>>.dk::srvc::health::WdgClient::mWdgThreadList[0]:<<function 1>>
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.<<constructor>>.WdgClient().<<call>>:0
TEST.VALUE:wdg_client.(cl)dk::srvc::health::WdgClient::pause.return:-1
TEST.EXPECTED:wdg_client.(cl)dk::srvc::health::WdgClient::pause.return:-1
TEST.END

-- Test Case: Test_WdgClient_Pause_TidMatches_Failure
TEST.UNIT:wdg_client
TEST.SUBPROGRAM:(cl)dk::srvc::health::WdgClient::pause
TEST.NEW
TEST.NAME:Test_WdgClient_Pause_TidMatches_Failure
TEST.NOTES:
WdgClient in GIP_INFRA::InfrastructureServices::WdgClient (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:wdg_client.<<GLOBAL>>.dk::srvc::health::WdgClient::mpHandle:<<malloc 1>>
TEST.VALUE:wdg_client.<<GLOBAL>>.dk::srvc::health::WdgClient::mWdgThreadList:<<malloc 1>>
TEST.VALUE:wdg_client.<<GLOBAL>>.dk::srvc::health::WdgClient::mWdgThreadList[0]:<<malloc 1>>
TEST.VALUE:wdg_client.<<GLOBAL>>.dk::srvc::health::WdgClient::mWdgThreadList[0]:<<function 1>>
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.<<constructor>>.WdgClient().<<call>>:0
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mpHandle:<<malloc 1>>
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mWdgThreadList:<<malloc 1>>
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mWdgThreadList[0]:<<malloc 1>>
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mWdgThreadList[0][0].tid:0
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mWdgThreadList[0]:<<function 1>>
TEST.VALUE:wdg_client.(cl)dk::srvc::health::WdgClient::pause.return:-1
TEST.VALUE:uut_prototype_stubs.gettid.return:1
TEST.EXPECTED:wdg_client.(cl)dk::srvc::health::WdgClient::pause.return:-1
TEST.END

-- Test Case: Test_WdgClient_Pause_TidMatches_Success
TEST.UNIT:wdg_client
TEST.SUBPROGRAM:(cl)dk::srvc::health::WdgClient::pause
TEST.NEW
TEST.NAME:Test_WdgClient_Pause_TidMatches_Success
TEST.NOTES:
WdgClient in GIP_INFRA::InfrastructureServices::WdgClient (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:wdg_client.<<GLOBAL>>.dk::srvc::health::WdgClient::mpHandle:<<malloc 1>>
TEST.VALUE:wdg_client.<<GLOBAL>>.dk::srvc::health::WdgClient::mWdgThreadList:<<malloc 1>>
TEST.VALUE:wdg_client.<<GLOBAL>>.dk::srvc::health::WdgClient::mWdgThreadList[0]:<<malloc 1>>
TEST.VALUE:wdg_client.<<GLOBAL>>.dk::srvc::health::WdgClient::mWdgThreadList[0]:<<function 1>>
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.<<constructor>>.WdgClient().<<call>>:0
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mpHandle:<<malloc 1>>
TEST.VALUE:wdg_client.(cl)dk::srvc::health::WdgClient::pause.return:0
TEST.EXPECTED:wdg_client.(cl)dk::srvc::health::WdgClient::pause.return:0
TEST.END

-- Subprogram: (cl)dk::srvc::health::WdgClient::periodicTask

-- Test Case: Test_WdgClient_PeriodicTask_TimeoutGreaterThanZero_DecreasesTimeout
TEST.UNIT:wdg_client
TEST.SUBPROGRAM:(cl)dk::srvc::health::WdgClient::periodicTask
TEST.NEW
TEST.NAME:Test_WdgClient_PeriodicTask_TimeoutGreaterThanZero_DecreasesTimeout
TEST.NOTES:
WdgClient in GIP_INFRA::InfrastructureServices::WdgClient (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:uut_prototype_stubs.std::chrono::_V2::system_clock::to_time_t
TEST.STUB:uut_prototype_stubs.std::chrono::_V2::system_clock::from_time_t
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.<<constructor>>.WdgClient().<<call>>:0
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mpHandle:<<malloc 1>>
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mWdgThreadList:<<malloc 1>>
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mWdgThreadList[0]:<<malloc 1>>
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mWdgThreadList[0][0].tmo:1
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mWdgThreadList[0][0].bMonitorActive:true
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mWdgThreadList[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.std::chrono::_V2::steady_clock::now.return.std::chrono::time_point<std::chrono::_V2::steady_clock, std::chrono::duration<long long, std::ratio<1LL, 1000000000LL>>>.<<constructor>>.time_point().<<call>>:0
TEST.END

-- Test Case: Test_WdgClient_PeriodicTask_mpHandle_Null
TEST.UNIT:wdg_client
TEST.SUBPROGRAM:(cl)dk::srvc::health::WdgClient::periodicTask
TEST.NEW
TEST.NAME:Test_WdgClient_PeriodicTask_mpHandle_Null
TEST.NOTES:
WdgClient in GIP_INFRA::InfrastructureServices::WdgClient (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:uut_prototype_stubs.std::chrono::_V2::system_clock::to_time_t
TEST.STUB:uut_prototype_stubs.std::chrono::_V2::system_clock::from_time_t
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.<<constructor>>.WdgClient().<<call>>:0
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mpHandle:<<null>>
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mWdgThreadList:<<malloc 1>>
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mWdgThreadList[0]:<<malloc 1>>
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mWdgThreadList[0][0].tmo:1
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mWdgThreadList[0][0].bMonitorActive:true
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mWdgThreadList[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.std::chrono::_V2::steady_clock::now.return.std::chrono::time_point<std::chrono::_V2::steady_clock, std::chrono::duration<long long, std::ratio<1LL, 1000000000LL>>>.<<constructor>>.time_point().<<call>>:0
TEST.END

-- Test Case: Test_WdgClient_PeriodicTask_pRec_tmo_<_0
TEST.UNIT:wdg_client
TEST.SUBPROGRAM:(cl)dk::srvc::health::WdgClient::periodicTask
TEST.NEW
TEST.NAME:Test_WdgClient_PeriodicTask_pRec_tmo_<_0
TEST.NOTES:
WdgClient in GIP_INFRA::InfrastructureServices::WdgClient (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:uut_prototype_stubs.std::chrono::_V2::system_clock::to_time_t
TEST.STUB:uut_prototype_stubs.std::chrono::_V2::system_clock::from_time_t
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.<<constructor>>.WdgClient().<<call>>:0
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mpHandle:<<malloc 1>>
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mWdgThreadList:<<malloc 1>>
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mWdgThreadList[0]:<<malloc 1>>
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mWdgThreadList[0][0].bMonitorActive:true
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mWdgThreadList[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.std::chrono::_V2::steady_clock::now.return.std::chrono::time_point<std::chrono::_V2::steady_clock, std::chrono::duration<long long, std::ratio<1LL, 1000000000LL>>>.<<constructor>>.time_point().<<call>>:0
TEST.END

-- Test Case: Test_WdgClient_peridicTask_bMonitorActive_false
TEST.UNIT:wdg_client
TEST.SUBPROGRAM:(cl)dk::srvc::health::WdgClient::periodicTask
TEST.NEW
TEST.NAME:Test_WdgClient_peridicTask_bMonitorActive_false
TEST.NOTES:
WdgClient in GIP_INFRA::InfrastructureServices::WdgClient (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:uut_prototype_stubs.std::chrono::_V2::system_clock::to_time_t
TEST.STUB:uut_prototype_stubs.std::chrono::_V2::system_clock::from_time_t
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.<<constructor>>.WdgClient().<<call>>:0
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mpHandle:<<malloc 1>>
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mWdgThreadList:<<malloc 1>>
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mWdgThreadList[0]:<<malloc 1>>
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mWdgThreadList[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.std::chrono::_V2::steady_clock::now.return.std::chrono::time_point<std::chrono::_V2::steady_clock, std::chrono::duration<long long, std::ratio<1LL, 1000000000LL>>>.<<constructor>>.time_point().<<call>>:0
TEST.END

-- Subprogram: (cl)dk::srvc::health::WdgClient::pet

-- Test Case: Test_WdgClient_Pet_MonitorInactive_ReturnsError
TEST.UNIT:wdg_client
TEST.SUBPROGRAM:(cl)dk::srvc::health::WdgClient::pet
TEST.NEW
TEST.NAME:Test_WdgClient_Pet_MonitorInactive_ReturnsError
TEST.NOTES:
WdgClient in GIP_INFRA::InfrastructureServices::WdgClient (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.<<constructor>>.WdgClient().<<call>>:0
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mpHandle:<<malloc 1>>
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mWdgThreadList:<<malloc 1>>
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mWdgThreadList[0]:<<malloc 1>>
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mWdgThreadList[0][0].tid:1
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mWdgThreadList[0][0].bMonitorActive:false
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mWdgThreadList[0]:<<function 1>>
TEST.VALUE:wdg_client.(cl)dk::srvc::health::WdgClient::pet.return:-1
TEST.VALUE:uut_prototype_stubs.gettid.return:1
TEST.EXPECTED:wdg_client.(cl)dk::srvc::health::WdgClient::pet.return:-1
TEST.END

-- Test Case: Test_WdgClient_Pet_NullMpHandle_ReturnsError
TEST.UNIT:wdg_client
TEST.SUBPROGRAM:(cl)dk::srvc::health::WdgClient::pet
TEST.NEW
TEST.NAME:Test_WdgClient_Pet_NullMpHandle_ReturnsError
TEST.NOTES:
WdgClient in GIP_INFRA::InfrastructureServices::WdgClient (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.<<constructor>>.WdgClient().<<call>>:0
TEST.VALUE:wdg_client.(cl)dk::srvc::health::WdgClient::pet.return:-1
TEST.EXPECTED:wdg_client.(cl)dk::srvc::health::WdgClient::pet.return:-1
TEST.END

-- Test Case: Test_WdgClient_Pet_TidMatches_Failure
TEST.UNIT:wdg_client
TEST.SUBPROGRAM:(cl)dk::srvc::health::WdgClient::pet
TEST.NEW
TEST.NAME:Test_WdgClient_Pet_TidMatches_Failure
TEST.NOTES:
WdgClient in GIP_INFRA::InfrastructureServices::WdgClient (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.<<constructor>>.WdgClient().<<call>>:0
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mpHandle:<<malloc 1>>
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mWdgThreadList:<<malloc 1>>
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mWdgThreadList[0]:<<malloc 1>>
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mWdgThreadList[0][0].tid:2
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mWdgThreadList[0]:<<function 1>>
TEST.VALUE:wdg_client.(cl)dk::srvc::health::WdgClient::pet.return:-1
TEST.VALUE:uut_prototype_stubs.gettid.return:1
TEST.EXPECTED:wdg_client.(cl)dk::srvc::health::WdgClient::pet.return:-1
TEST.END

-- Test Case: Test_WdgClient_Pet_TidMatches_Success
TEST.UNIT:wdg_client
TEST.SUBPROGRAM:(cl)dk::srvc::health::WdgClient::pet
TEST.NEW
TEST.NAME:Test_WdgClient_Pet_TidMatches_Success
TEST.NOTES:
WdgClient in GIP_INFRA::InfrastructureServices::WdgClient (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.<<constructor>>.WdgClient().<<call>>:0
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mpHandle:<<malloc 1>>
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mWdgThreadList:<<malloc 1>>
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mWdgThreadList[0]:<<malloc 1>>
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mWdgThreadList[0][0].tid:1
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mWdgThreadList[0][0].bMonitorActive:true
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mWdgThreadList[0]:<<function 1>>
TEST.VALUE:wdg_client.(cl)dk::srvc::health::WdgClient::pet.return:0
TEST.VALUE:uut_prototype_stubs.gettid.return:1
TEST.EXPECTED:wdg_client.(cl)dk::srvc::health::WdgClient::pet.return:0
TEST.END

-- Subprogram: (cl)dk::srvc::health::WdgClient::resume

-- Test Case: Test_WdgClient_Resume_NullMpHandle_ReturnsError
TEST.UNIT:wdg_client
TEST.SUBPROGRAM:(cl)dk::srvc::health::WdgClient::resume
TEST.NEW
TEST.NAME:Test_WdgClient_Resume_NullMpHandle_ReturnsError
TEST.NOTES:
WdgClient in GIP_INFRA::InfrastructureServices::WdgClient (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.<<constructor>>.WdgClient().<<call>>:0
TEST.VALUE:wdg_client.(cl)dk::srvc::health::WdgClient::resume.return:-1
TEST.EXPECTED:wdg_client.(cl)dk::srvc::health::WdgClient::resume.return:-1
TEST.END

-- Test Case: Test_WdgClient_Resume_TidMatches_Failure
TEST.UNIT:wdg_client
TEST.SUBPROGRAM:(cl)dk::srvc::health::WdgClient::resume
TEST.NEW
TEST.NAME:Test_WdgClient_Resume_TidMatches_Failure
TEST.NOTES:
WdgClient in GIP_INFRA::InfrastructureServices::WdgClient (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.<<constructor>>.WdgClient().<<call>>:0
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mpHandle:<<malloc 1>>
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mWdgThreadList:<<malloc 1>>
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mWdgThreadList[0]:<<malloc 1>>
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mWdgThreadList[0][0].tid:1
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mWdgThreadList[0]:<<function 1>>
TEST.VALUE:wdg_client.(cl)dk::srvc::health::WdgClient::resume.return:-1
TEST.VALUE:uut_prototype_stubs.gettid.return:0
TEST.EXPECTED:wdg_client.(cl)dk::srvc::health::WdgClient::resume.return:-1
TEST.END

-- Test Case: Test_WdgClient_Resume_TidMatches_Success
TEST.UNIT:wdg_client
TEST.SUBPROGRAM:(cl)dk::srvc::health::WdgClient::resume
TEST.NEW
TEST.NAME:Test_WdgClient_Resume_TidMatches_Success
TEST.NOTES:
WdgClient in GIP_INFRA::InfrastructureServices::WdgClient (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.<<constructor>>.WdgClient().<<call>>:0
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mpHandle:<<malloc 1>>
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mWdgThreadList:<<malloc 1>>
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mWdgThreadList[0]:<<malloc 1>>
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mWdgThreadList[0]:<<function 1>>
TEST.VALUE:wdg_client.(cl)dk::srvc::health::WdgClient::resume.return:0
TEST.EXPECTED:wdg_client.(cl)dk::srvc::health::WdgClient::resume.return:0
TEST.END

-- Test Case: Test_WdgClient_Resume_threadList_empty
TEST.UNIT:wdg_client
TEST.SUBPROGRAM:(cl)dk::srvc::health::WdgClient::resume
TEST.NEW
TEST.NAME:Test_WdgClient_Resume_threadList_empty
TEST.NOTES:
WdgClient in GIP_INFRA::InfrastructureServices::WdgClient (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.<<constructor>>.WdgClient().<<call>>:0
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mpHandle:<<malloc 1>>
TEST.VALUE:wdg_client.(cl)dk::srvc::health::WdgClient::resume.return:-1
TEST.EXPECTED:wdg_client.(cl)dk::srvc::health::WdgClient::resume.return:-1
TEST.END

-- Subprogram: (cl)dk::srvc::health::WdgClient::sdKeepAliveEnable

-- Test Case: (cl)dk::srvc::health::WdgClient::sdKeepAliveEnable.Success
TEST.UNIT:wdg_client
TEST.SUBPROGRAM:(cl)dk::srvc::health::WdgClient::sdKeepAliveEnable
TEST.NEW
TEST.NAME:(cl)dk::srvc::health::WdgClient::sdKeepAliveEnable.Success
TEST.NOTES:
WdgClient in GIP_INFRA::InfrastructureServices::WdgClient (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:wdg_client.(cl)dk::srvc::health::WdgClient::sdWatchdogIsEnabled
TEST.VALUE:wdg_client.<<GLOBAL>>.dk::srvc::health::WdgClient::mHeartbeatPeriodMs:1000
TEST.VALUE:wdg_client.(cl)dk::srvc::health::WdgClient::sdWatchdogIsEnabled.return:<<malloc 1>>
TEST.VALUE:wdg_client.(cl)dk::srvc::health::WdgClient::sdKeepAliveEnable.return:1000
TEST.VALUE:uut_prototype_stubs.sd_watchdog_enabled.return:1
TEST.EXPECTED:wdg_client.(cl)dk::srvc::health::WdgClient::sdKeepAliveEnable.return:1000
TEST.END

-- Test Case: (cl)dk::srvc::health::WdgClient::sdKeepAliveEnable.sdWatchdogIsEnabled_ret_NULL
TEST.UNIT:wdg_client
TEST.SUBPROGRAM:(cl)dk::srvc::health::WdgClient::sdKeepAliveEnable
TEST.NEW
TEST.NAME:(cl)dk::srvc::health::WdgClient::sdKeepAliveEnable.sdWatchdogIsEnabled_ret_NULL
TEST.NOTES:
WdgClient in GIP_INFRA::InfrastructureServices::WdgClient (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:wdg_client.(cl)dk::srvc::health::WdgClient::sdWatchdogIsEnabled
TEST.VALUE:wdg_client.<<GLOBAL>>.dk::srvc::health::WdgClient::mHeartbeatPeriodMs:1000
TEST.VALUE:wdg_client.(cl)dk::srvc::health::WdgClient::sdKeepAliveEnable.return:-1
TEST.VALUE:uut_prototype_stubs.sd_watchdog_enabled.return:-1
TEST.EXPECTED:wdg_client.(cl)dk::srvc::health::WdgClient::sdKeepAliveEnable.return:-1
TEST.END

-- Test Case: (cl)dk::srvc::health::WdgClient::sdKeepAliveEnable.thread_fail
TEST.UNIT:wdg_client
TEST.SUBPROGRAM:(cl)dk::srvc::health::WdgClient::sdKeepAliveEnable
TEST.NEW
TEST.NAME:(cl)dk::srvc::health::WdgClient::sdKeepAliveEnable.thread_fail
TEST.NOTES:
WdgClient in GIP_INFRA::InfrastructureServices::WdgClient (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:wdg_client.(cl)dk::srvc::health::WdgClient::sdWatchdogIsEnabled
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.num_calls_to_new:1
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.new_fails_on_call:2
TEST.VALUE:wdg_client.<<GLOBAL>>.dk::srvc::health::WdgClient::mHeartbeatPeriodMs:1000
TEST.VALUE:wdg_client.(cl)dk::srvc::health::WdgClient::sdWatchdogIsEnabled.return:<<malloc 1>>
TEST.VALUE:wdg_client.(cl)dk::srvc::health::WdgClient::sdKeepAliveEnable.return:-1
TEST.VALUE:uut_prototype_stubs.sd_watchdog_enabled.return:1
TEST.EXPECTED:wdg_client.(cl)dk::srvc::health::WdgClient::sdKeepAliveEnable.return:-1
TEST.END

-- Subprogram: (cl)dk::srvc::health::WdgClient::sdWatchdogIsEnabled

-- Test Case: (cl)dk::srvc::health::WdgClient::sdWatchdogIsEnabled.reqTimeoutPeriodUs_<_1000
TEST.UNIT:wdg_client
TEST.SUBPROGRAM:(cl)dk::srvc::health::WdgClient::sdWatchdogIsEnabled
TEST.NEW
TEST.NAME:(cl)dk::srvc::health::WdgClient::sdWatchdogIsEnabled.reqTimeoutPeriodUs_<_1000
TEST.NOTES:
WdgClient in GIP_INFRA::InfrastructureServices::WdgClient (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:wdg_client.(cl)dk::srvc::health::WdgClient::sdWatchdogIsEnabled.reqTimeoutPeriodMs:<<malloc 1>>
TEST.VALUE:wdg_client.(cl)dk::srvc::health::WdgClient::sdWatchdogIsEnabled.return:<<malloc 1>>
TEST.VALUE:wdg_client.(cl)dk::srvc::health::WdgClient::sdWatchdogIsEnabled.return[0]:1
TEST.VALUE:uut_prototype_stubs.sd_watchdog_enabled.usec[0]:1000
TEST.VALUE:uut_prototype_stubs.sd_watchdog_enabled.return:1
TEST.EXPECTED:wdg_client.(cl)dk::srvc::health::WdgClient::sdWatchdogIsEnabled.return[0]:1
TEST.END

-- Test Case: (cl)dk::srvc::health::WdgClient::sdWatchdogIsEnabled.reqTimeoutPeriodUs_>_1000ms
TEST.UNIT:wdg_client
TEST.SUBPROGRAM:(cl)dk::srvc::health::WdgClient::sdWatchdogIsEnabled
TEST.NEW
TEST.NAME:(cl)dk::srvc::health::WdgClient::sdWatchdogIsEnabled.reqTimeoutPeriodUs_>_1000ms
TEST.NOTES:
WdgClient in GIP_INFRA::InfrastructureServices::WdgClient (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:wdg_client.(cl)dk::srvc::health::WdgClient::sdWatchdogIsEnabled.reqTimeoutPeriodMs:<<malloc 1>>
TEST.VALUE:wdg_client.(cl)dk::srvc::health::WdgClient::sdWatchdogIsEnabled.return:<<malloc 1>>
TEST.VALUE:wdg_client.(cl)dk::srvc::health::WdgClient::sdWatchdogIsEnabled.return[0]:1
TEST.VALUE:uut_prototype_stubs.sd_watchdog_enabled.usec[0]:1000000000
TEST.VALUE:uut_prototype_stubs.sd_watchdog_enabled.return:1
TEST.EXPECTED:wdg_client.(cl)dk::srvc::health::WdgClient::sdWatchdogIsEnabled.return[0]:1
TEST.END

-- Test Case: (cl)dk::srvc::health::WdgClient::sdWatchdogIsEnabled.watchdog_not_enabled
TEST.UNIT:wdg_client
TEST.SUBPROGRAM:(cl)dk::srvc::health::WdgClient::sdWatchdogIsEnabled
TEST.NEW
TEST.NAME:(cl)dk::srvc::health::WdgClient::sdWatchdogIsEnabled.watchdog_not_enabled
TEST.NOTES:
WdgClient in GIP_INFRA::InfrastructureServices::WdgClient (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:wdg_client.(cl)dk::srvc::health::WdgClient::sdWatchdogIsEnabled.return:<<null>>
TEST.VALUE:uut_prototype_stubs.sd_watchdog_enabled.return:-1
TEST.EXPECTED:wdg_client.(cl)dk::srvc::health::WdgClient::sdWatchdogIsEnabled.return:<<null>>
TEST.END

-- Subprogram: (cl)dk::srvc::health::WdgClient::start

-- Test Case: Test_WdgClient_Start_NullMpHandle_ReturnsError
TEST.UNIT:wdg_client
TEST.SUBPROGRAM:(cl)dk::srvc::health::WdgClient::start
TEST.NEW
TEST.NAME:Test_WdgClient_Start_NullMpHandle_ReturnsError
TEST.NOTES:
WdgClient in GIP_INFRA::InfrastructureServices::WdgClient (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.<<constructor>>.WdgClient().<<call>>:0
TEST.VALUE:wdg_client.(cl)dk::srvc::health::WdgClient::start.return:-1
TEST.EXPECTED:wdg_client.(cl)dk::srvc::health::WdgClient::start.return:-1
TEST.END

-- Test Case: Test_WdgClient_Start_Timeout_<_HeartbeatPeriodMs
TEST.UNIT:wdg_client
TEST.SUBPROGRAM:(cl)dk::srvc::health::WdgClient::start
TEST.NEW
TEST.NAME:Test_WdgClient_Start_Timeout_<_HeartbeatPeriodMs
TEST.NOTES:
WdgClient in GIP_INFRA::InfrastructureServices::WdgClient (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:wdg_client.<<GLOBAL>>.dk::srvc::health::WdgClient::mpHandle:<<malloc 1>>
TEST.VALUE:wdg_client.<<GLOBAL>>.dk::srvc::health::WdgClient::mHeartbeatPeriodMs:1
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.<<constructor>>.WdgClient().<<call>>:0
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mpHandle:<<malloc 1>>
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mpHandle[0]:1
TEST.VALUE:wdg_client.(cl)dk::srvc::health::WdgClient::start.timeoutMs:0
TEST.VALUE:wdg_client.(cl)dk::srvc::health::WdgClient::start.return:0
TEST.VALUE:uut_prototype_stubs.std::chrono::_V2::steady_clock::now.return.std::chrono::time_point<std::chrono::_V2::steady_clock, std::chrono::duration<long long, std::ratio<1LL, 1000000000LL>>>.<<constructor>>.time_point().<<call>>:0
TEST.EXPECTED:wdg_client.(cl)dk::srvc::health::WdgClient::start.return:0
TEST.END

-- Test Case: Test_WdgClient_Start_Timeout_>_mHeartbeatPeriodMs
TEST.UNIT:wdg_client
TEST.SUBPROGRAM:(cl)dk::srvc::health::WdgClient::start
TEST.NEW
TEST.NAME:Test_WdgClient_Start_Timeout_>_mHeartbeatPeriodMs
TEST.NOTES:
WdgClient in GIP_INFRA::InfrastructureServices::WdgClient (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:wdg_client.<<GLOBAL>>.dk::srvc::health::WdgClient::mpHandle:<<malloc 1>>
TEST.VALUE:wdg_client.<<GLOBAL>>.dk::srvc::health::WdgClient::mHeartbeatPeriodMs:0
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.<<constructor>>.WdgClient().<<call>>:0
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mpHandle:<<malloc 1>>
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mpHandle[0]:1
TEST.VALUE:wdg_client.(cl)dk::srvc::health::WdgClient::start.timeoutMs:0
TEST.VALUE:wdg_client.(cl)dk::srvc::health::WdgClient::start.return:0
TEST.VALUE:uut_prototype_stubs.std::chrono::_V2::steady_clock::now.return.std::chrono::time_point<std::chrono::_V2::steady_clock, std::chrono::duration<long long, std::ratio<1LL, 1000000000LL>>>.<<constructor>>.time_point().<<call>>:0
TEST.EXPECTED:wdg_client.(cl)dk::srvc::health::WdgClient::start.return:0
TEST.END

-- Test Case: Test_WdgClient_Start_pRec_NULL
TEST.UNIT:wdg_client
TEST.SUBPROGRAM:(cl)dk::srvc::health::WdgClient::start
TEST.NEW
TEST.NAME:Test_WdgClient_Start_pRec_NULL
TEST.NOTES:
WdgClient in GIP_INFRA::InfrastructureServices::WdgClient (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.num_calls_to_new:0
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.new_fails_on_call:2
TEST.VALUE:wdg_client.<<GLOBAL>>.dk::srvc::health::WdgClient::mpHandle:<<malloc 1>>
TEST.VALUE:wdg_client.<<GLOBAL>>.dk::srvc::health::WdgClient::mHeartbeatPeriodMs:1
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.<<constructor>>.WdgClient().<<call>>:0
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mpHandle:<<malloc 1>>
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mpHandle[0]:1
TEST.VALUE:wdg_client.(cl)dk::srvc::health::WdgClient::start.timeoutMs:0
TEST.VALUE:wdg_client.(cl)dk::srvc::health::WdgClient::start.return:-1
TEST.VALUE:uut_prototype_stubs.std::chrono::_V2::steady_clock::now.return.std::chrono::time_point<std::chrono::_V2::steady_clock, std::chrono::duration<long long, std::ratio<1LL, 1000000000LL>>>.<<constructor>>.time_point().<<call>>:0
TEST.EXPECTED:wdg_client.(cl)dk::srvc::health::WdgClient::start.return:-1
TEST.END

-- Subprogram: (cl)dk::srvc::health::WdgClient::stop

-- Test Case: Test_WdgClient_Stop_NullMpHandle__ReturnsError
TEST.UNIT:wdg_client
TEST.SUBPROGRAM:(cl)dk::srvc::health::WdgClient::stop
TEST.NEW
TEST.NAME:Test_WdgClient_Stop_NullMpHandle__ReturnsError
TEST.NOTES:
WdgClient in GIP_INFRA::InfrastructureServices::WdgClient (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.<<constructor>>.WdgClient().<<call>>:0
TEST.VALUE:wdg_client.(cl)dk::srvc::health::WdgClient::stop.return:-1
TEST.EXPECTED:wdg_client.(cl)dk::srvc::health::WdgClient::stop.return:-1
TEST.END

-- Test Case: Test_WdgClient_Stop_TidMatches_Failure
TEST.UNIT:wdg_client
TEST.SUBPROGRAM:(cl)dk::srvc::health::WdgClient::stop
TEST.NEW
TEST.NAME:Test_WdgClient_Stop_TidMatches_Failure
TEST.NOTES:
WdgClient in GIP_INFRA::InfrastructureServices::WdgClient (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.<<constructor>>.WdgClient().<<call>>:0
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mpHandle:<<malloc 1>>
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mWdgThreadList:<<malloc 1>>
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mWdgThreadList[0]:<<malloc 1>>
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mWdgThreadList[0][0].tid:1
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mWdgThreadList[0]:<<function 1>>
TEST.VALUE:wdg_client.(cl)dk::srvc::health::WdgClient::stop.return:-1
TEST.VALUE:uut_prototype_stubs.gettid.return:0
TEST.EXPECTED:wdg_client.(cl)dk::srvc::health::WdgClient::stop.return:-1
TEST.END

-- Test Case: Test_WdgClient_Stop_TidMatches_Success
TEST.UNIT:wdg_client
TEST.SUBPROGRAM:(cl)dk::srvc::health::WdgClient::stop
TEST.NEW
TEST.NAME:Test_WdgClient_Stop_TidMatches_Success
TEST.NOTES:
WdgClient in GIP_INFRA::InfrastructureServices::WdgClient (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.<<constructor>>.WdgClient().<<call>>:0
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mpHandle:<<malloc 1>>
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mWdgThreadList:<<malloc 1>>
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mWdgThreadList[0]:<<malloc 1>>
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mWdgThreadList[0]:<<function 1>>
TEST.VALUE:wdg_client.(cl)dk::srvc::health::WdgClient::stop.return:0
TEST.EXPECTED:wdg_client.(cl)dk::srvc::health::WdgClient::stop.return:0
TEST.END

-- Test Case: Test_WdgClient_Stop_threadList_empty
TEST.UNIT:wdg_client
TEST.SUBPROGRAM:(cl)dk::srvc::health::WdgClient::stop
TEST.NEW
TEST.NAME:Test_WdgClient_Stop_threadList_empty
TEST.NOTES:
WdgClient in GIP_INFRA::InfrastructureServices::WdgClient (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.<<constructor>>.WdgClient().<<call>>:0
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.dk::srvc::health::WdgClient::mpHandle:<<malloc 1>>
TEST.VALUE:wdg_client.(cl)dk::srvc::health::WdgClient::stop.return:-1
TEST.EXPECTED:wdg_client.(cl)dk::srvc::health::WdgClient::stop.return:-1
TEST.END

-- Subprogram: (cl)dk::srvc::health::WdgClient::~WdgClient

-- Test Case: Test_WdgClient_destructor_exception1
TEST.UNIT:wdg_client
TEST.SUBPROGRAM:(cl)dk::srvc::health::WdgClient::~WdgClient
TEST.NEW
TEST.NAME:Test_WdgClient_destructor_exception1
TEST.NOTES:
WdgClient in GIP_INFRA::InfrastructureServices::WdgClient (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.<<constructor>>.WdgClient().<<call>>:0
TEST.VALUE:wdg_client.<<GLOBAL>>.gWCLogContext.contextID[0]:16#1#
TEST.END

-- Test Case: Test_WdgClient_destructor_exception2
TEST.UNIT:wdg_client
TEST.SUBPROGRAM:(cl)dk::srvc::health::WdgClient::~WdgClient
TEST.NEW
TEST.NAME:Test_WdgClient_destructor_exception2
TEST.NOTES:
WdgClient in GIP_INFRA::InfrastructureServices::WdgClient (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.<<constructor>>.WdgClient().<<call>>:0
TEST.VALUE:wdg_client.<<GLOBAL>>.gWCLogContext.contextID[0]:16#2#
TEST.END

-- Test Case: Test_WdgClient_destructor_try
TEST.UNIT:wdg_client
TEST.SUBPROGRAM:(cl)dk::srvc::health::WdgClient::~WdgClient
TEST.NEW
TEST.NAME:Test_WdgClient_destructor_try
TEST.NOTES:
WdgClient in GIP_INFRA::InfrastructureServices::WdgClient (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:wdg_client.<<GLOBAL>>.(cl).dk::srvc::health::WdgClient.dk::srvc::health::WdgClient.<<constructor>>.WdgClient().<<call>>:0
TEST.END
