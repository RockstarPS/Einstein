-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : RUNTIME_APPLICATION_UT
-- Unit(s) Under Test: dk_runtime_application
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

-- Unit: dk_runtime_application

-- Subprogram: (cl)dk::runtime::core::Application::Application

-- Test Case: 01_Initialization
TEST.UNIT:dk_runtime_application
TEST.SUBPROGRAM:(cl)dk::runtime::core::Application::Application
TEST.NEW
TEST.NAME:01_Initialization
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw) 
TEST.END_NOTES:
TEST.VALUE:dk_runtime_application.(cl)dk::runtime::core::Application::Application.pAppName:<<malloc 5>>
TEST.VALUE:dk_runtime_application.(cl)dk::runtime::core::Application::Application.pAppName:"Test"
TEST.FLOW
  dk_runtime_application.cpp.(cl)dk::runtime::core::Application::Application
  uut_prototype_stubs.dk::runtime::core::IpcMsgIf::IpcMsgIf
  dk_runtime_application.cpp.(cl)dk::runtime::core::Application::Application
TEST.END_FLOW
TEST.END

-- Subprogram: (cl)dk::runtime::core::Application::WdgSendHeartbeat

-- Test Case: 01_Send_heart_beat
TEST.UNIT:dk_runtime_application
TEST.SUBPROGRAM:(cl)dk::runtime::core::Application::WdgSendHeartbeat
TEST.NEW
TEST.NAME:01_Send_heart_beat
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw) 
TEST.END_NOTES:
TEST.VALUE:dk_runtime_application.<<GLOBAL>>.(cl).dk::runtime::core::Application.dk::runtime::core::Application.<<constructor>>.Application(const char*).<<call>>:0
TEST.FLOW
  dk_runtime_application.cpp.(cl)dk::runtime::core::Application::WdgSendHeartbeat
  uut_prototype_stubs.dk::runtime::core::WdgIf::sendHeartbeat
  dk_runtime_application.cpp.(cl)dk::runtime::core::Application::WdgSendHeartbeat
TEST.END_FLOW
TEST.END

-- Subprogram: (cl)dk::runtime::core::Application::WdgStart

-- Test Case: 01_Start_watchdog
TEST.UNIT:dk_runtime_application
TEST.SUBPROGRAM:(cl)dk::runtime::core::Application::WdgStart
TEST.NEW
TEST.NAME:01_Start_watchdog
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw) 
TEST.END_NOTES:
TEST.VALUE:dk_runtime_application.<<GLOBAL>>.(cl).dk::runtime::core::Application.dk::runtime::core::Application.<<constructor>>.Application(const char*).<<call>>:0
TEST.FLOW
  dk_runtime_application.cpp.(cl)dk::runtime::core::Application::WdgStart
  uut_prototype_stubs.dk::runtime::core::WdgIf::start
  dk_runtime_application.cpp.(cl)dk::runtime::core::Application::WdgStart
TEST.END_FLOW
TEST.END

-- Subprogram: (cl)dk::runtime::core::Application::WdgStop

-- Test Case: 01_Stop_watchdog
TEST.UNIT:dk_runtime_application
TEST.SUBPROGRAM:(cl)dk::runtime::core::Application::WdgStop
TEST.NEW
TEST.NAME:01_Stop_watchdog
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw) 
TEST.END_NOTES:
TEST.VALUE:dk_runtime_application.<<GLOBAL>>.(cl).dk::runtime::core::Application.dk::runtime::core::Application.<<constructor>>.Application(const char*).<<call>>:0
TEST.FLOW
  dk_runtime_application.cpp.(cl)dk::runtime::core::Application::WdgStop
  uut_prototype_stubs.dk::runtime::core::WdgIf::stop
  dk_runtime_application.cpp.(cl)dk::runtime::core::Application::WdgStop
TEST.END_FLOW
TEST.END

-- Subprogram: (cl)dk::runtime::core::Application::addContainer()

-- Test Case: 01_Add_container
TEST.UNIT:dk_runtime_application
TEST.SUBPROGRAM:(cl)dk::runtime::core::Application::addContainer()
TEST.NEW
TEST.NAME:01_Add_container
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw) 
TEST.END_NOTES:
TEST.VALUE:dk_runtime_application.<<GLOBAL>>.(cl).dk::runtime::core::Application.dk::runtime::core::Application.<<constructor>>.Application(const char*).<<call>>:0
TEST.FLOW
  dk_runtime_application.cpp.(cl)dk::runtime::core::Application::addContainer()
  dk_runtime_application.cpp.(cl)dk::runtime::core::Application::addContainer()
TEST.END_FLOW
TEST.END

-- Subprogram: (cl)dk::runtime::core::Application::addContainer(dk::runtime::core::Container*)

-- Test Case: 01_Add_container
TEST.UNIT:dk_runtime_application
TEST.SUBPROGRAM:(cl)dk::runtime::core::Application::addContainer(dk::runtime::core::Container*)
TEST.NEW
TEST.NAME:01_Add_container
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw) 
TEST.END_NOTES:
TEST.VALUE:dk_runtime_application.<<GLOBAL>>.(cl).dk::runtime::core::Application.dk::runtime::core::Application.<<constructor>>.Application(const char*).<<call>>:0
TEST.FLOW
  dk_runtime_application.cpp.(cl)dk::runtime::core::Application::addContainer(dk::runtime::core::Container*)
  dk_runtime_application.cpp.(cl)dk::runtime::core::Application::addContainer(dk::runtime::core::Container*)
TEST.END_FLOW
TEST.END

-- Subprogram: (cl)dk::runtime::core::Application::getIsRunning

-- Test Case: 01_Get_running_status
TEST.UNIT:dk_runtime_application
TEST.SUBPROGRAM:(cl)dk::runtime::core::Application::getIsRunning
TEST.NEW
TEST.NAME:01_Get_running_status
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw) 
TEST.END_NOTES:
TEST.VALUE:dk_runtime_application.<<GLOBAL>>.(cl).dk::runtime::core::Application.dk::runtime::core::Application.<<constructor>>.Application(const char*).<<call>>:0
TEST.FLOW
  dk_runtime_application.cpp.(cl)dk::runtime::core::Application::getIsRunning
  dk_runtime_application.cpp.(cl)dk::runtime::core::Application::getIsRunning
TEST.END_FLOW
TEST.END

-- Subprogram: (cl)dk::runtime::core::Application::getWdgWaitTimeout

-- Test Case: 01_Get_watchdog_wait_timeout
TEST.UNIT:dk_runtime_application
TEST.SUBPROGRAM:(cl)dk::runtime::core::Application::getWdgWaitTimeout
TEST.NEW
TEST.NAME:01_Get_watchdog_wait_timeout
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw) 
TEST.END_NOTES:
TEST.VALUE:dk_runtime_application.<<GLOBAL>>.(cl).dk::runtime::core::Application.dk::runtime::core::Application.<<constructor>>.Application(const char*).<<call>>:0
TEST.FLOW
  dk_runtime_application.cpp.(cl)dk::runtime::core::Application::getWdgWaitTimeout
  dk_runtime_application.cpp.(cl)dk::runtime::core::Application::getWdgWaitTimeout
TEST.END_FLOW
TEST.END

-- Subprogram: (cl)dk::runtime::core::Application::initIpcMsgIf

-- Test Case: 01_Ipc_init_failed
TEST.UNIT:dk_runtime_application
TEST.SUBPROGRAM:(cl)dk::runtime::core::Application::initIpcMsgIf
TEST.NEW
TEST.NAME:01_Ipc_init_failed
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw) 
TEST.END_NOTES:
TEST.VALUE:dk_runtime_application.<<GLOBAL>>.(cl).dk::runtime::core::Application.dk::runtime::core::Application.<<constructor>>.Application(const char*).<<call>>:0
TEST.EXPECTED:dk_runtime_application.(cl)dk::runtime::core::Application::initIpcMsgIf.return:false
TEST.END

-- Test Case: 02_Non_empty_container
TEST.UNIT:dk_runtime_application
TEST.SUBPROGRAM:(cl)dk::runtime::core::Application::initIpcMsgIf
TEST.NEW
TEST.NAME:02_Non_empty_container
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw) 
TEST.END_NOTES:
TEST.VALUE:dk_runtime_application.<<GLOBAL>>.(cl).dk::runtime::core::Application.dk::runtime::core::Application.<<constructor>>.Application(const char*).<<call>>:0
TEST.VALUE:dk_runtime_application.<<GLOBAL>>.(cl).dk::runtime::core::Application.dk::runtime::core::Application.mContainerList:<<malloc 1>>
TEST.VALUE:dk_runtime_application.<<GLOBAL>>.(cl).dk::runtime::core::Application.dk::runtime::core::Application.mContainerList[0]:<<function 1>>
TEST.VALUE:dk_runtime_application.(cl)dk::runtime::core::Application::initIpcMsgIf.return:false
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::Container::getMessageGroups.msgGroups[0]:1
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::Container::getMessageGroups.msgGroups[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::IpcMsgIf::connect.return:true
TEST.EXPECTED:dk_runtime_application.(cl)dk::runtime::core::Application::initIpcMsgIf.return:false
TEST.FLOW
  dk_runtime_application.cpp.(cl)dk::runtime::core::Application::initIpcMsgIf
  uut_prototype_stubs.dk::runtime::core::IpcMsgIf::connect
  uut_prototype_stubs.dk::runtime::core::Container::getMessageGroups
  uut_prototype_stubs.dk::runtime::core::IpcMsgIf::subscribe
  dk_runtime_application.cpp.(cl)dk::runtime::core::Application::initIpcMsgIf
TEST.END_FLOW
TEST.END

-- Test Case: 03_Subscribed_successfully
TEST.UNIT:dk_runtime_application
TEST.SUBPROGRAM:(cl)dk::runtime::core::Application::initIpcMsgIf
TEST.NEW
TEST.NAME:03_Subscribed_successfully
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw) 
TEST.END_NOTES:
TEST.VALUE:dk_runtime_application.<<GLOBAL>>.(cl).dk::runtime::core::Application.dk::runtime::core::Application.<<constructor>>.Application(const char*).<<call>>:0
TEST.VALUE:dk_runtime_application.<<GLOBAL>>.(cl).dk::runtime::core::Application.dk::runtime::core::Application.mContainerList:<<malloc 1>>
TEST.VALUE:dk_runtime_application.<<GLOBAL>>.(cl).dk::runtime::core::Application.dk::runtime::core::Application.mContainerList[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::IpcMsgIf::connect.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::IpcMsgIf::subscribe.return:true
TEST.EXPECTED:dk_runtime_application.(cl)dk::runtime::core::Application::initIpcMsgIf.return:true
TEST.END

-- Subprogram: (cl)dk::runtime::core::Application::onExit

-- Test Case: 01_Empty_container
TEST.UNIT:dk_runtime_application
TEST.SUBPROGRAM:(cl)dk::runtime::core::Application::onExit
TEST.NEW
TEST.NAME:01_Empty_container
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw) 
TEST.END_NOTES:
TEST.VALUE:dk_runtime_application.<<GLOBAL>>.(cl).dk::runtime::core::Application.dk::runtime::core::Application.<<constructor>>.Application(const char*).<<call>>:0
TEST.FLOW
  dk_runtime_application.cpp.(cl)dk::runtime::core::Application::onExit
  dk_runtime_application.cpp.(cl)dk::runtime::core::Application::onExit
TEST.END_FLOW
TEST.END

-- Test Case: 02_Non_empty_container
TEST.UNIT:dk_runtime_application
TEST.SUBPROGRAM:(cl)dk::runtime::core::Application::onExit
TEST.NEW
TEST.NAME:02_Non_empty_container
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw) 
TEST.END_NOTES:
TEST.VALUE:dk_runtime_application.<<GLOBAL>>.(cl).dk::runtime::core::Application.dk::runtime::core::Application.<<constructor>>.Application(const char*).<<call>>:0
TEST.VALUE:dk_runtime_application.<<GLOBAL>>.(cl).dk::runtime::core::Application.dk::runtime::core::Application.mContainerList:<<malloc 1>>
TEST.VALUE:dk_runtime_application.<<GLOBAL>>.(cl).dk::runtime::core::Application.dk::runtime::core::Application.mContainerList[0]:<<function 1>>
TEST.FLOW
  dk_runtime_application.cpp.(cl)dk::runtime::core::Application::onExit
  uut_prototype_stubs.dk::runtime::core::Container::onExit
  dk_runtime_application.cpp.(cl)dk::runtime::core::Application::onExit
TEST.END_FLOW
TEST.END

-- Subprogram: (cl)dk::runtime::core::Application::onInit

-- Test Case: 01_Empty_container
TEST.UNIT:dk_runtime_application
TEST.SUBPROGRAM:(cl)dk::runtime::core::Application::onInit
TEST.NEW
TEST.NAME:01_Empty_container
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw) 
TEST.END_NOTES:
TEST.VALUE:dk_runtime_application.<<GLOBAL>>.(cl).dk::runtime::core::Application.dk::runtime::core::Application.<<constructor>>.Application(const char*).<<call>>:0
TEST.FLOW
  dk_runtime_application.cpp.(cl)dk::runtime::core::Application::onInit
  uut_prototype_stubs.dk::osal::Semaphore::Semaphore(uint32_t)
  dk_runtime_application.cpp.(cl)dk::runtime::core::Application::onInit
TEST.END_FLOW
TEST.END

-- Test Case: 02_Non_empty_containter
TEST.UNIT:dk_runtime_application
TEST.SUBPROGRAM:(cl)dk::runtime::core::Application::onInit
TEST.NEW
TEST.NAME:02_Non_empty_containter
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw) 
TEST.END_NOTES:
TEST.VALUE:dk_runtime_application.<<GLOBAL>>.(cl).dk::runtime::core::Application.dk::runtime::core::Application.<<constructor>>.Application(const char*).<<call>>:0
TEST.VALUE:dk_runtime_application.<<GLOBAL>>.(cl).dk::runtime::core::Application.dk::runtime::core::Application.mContainerList:<<malloc 1>>
TEST.VALUE:dk_runtime_application.<<GLOBAL>>.(cl).dk::runtime::core::Application.dk::runtime::core::Application.mContainerList[0]:<<function 1>>
TEST.FLOW
  dk_runtime_application.cpp.(cl)dk::runtime::core::Application::onInit
  uut_prototype_stubs.dk::osal::Semaphore::Semaphore(uint32_t)
  uut_prototype_stubs.dk::runtime::core::Container::onInit
  dk_runtime_application.cpp.(cl)dk::runtime::core::Application::onInit
TEST.END_FLOW
TEST.END

-- Subprogram: (cl)dk::runtime::core::Application::onRun

-- Test Case: 01_On_run_callback
TEST.UNIT:dk_runtime_application
TEST.SUBPROGRAM:(cl)dk::runtime::core::Application::onRun
TEST.NEW
TEST.NAME:01_On_run_callback
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw) 
TEST.END_NOTES:
TEST.STUB:dk_runtime_application.(cl)dk::runtime::core::Application::onInit
TEST.STUB:dk_runtime_application.(cl)dk::runtime::core::Application::onStart
TEST.VALUE:dk_runtime_application.<<GLOBAL>>.(cl).dk::runtime::core::Application.dk::runtime::core::Application.<<constructor>>.Application(const char*).<<call>>:0
TEST.VALUE:dk_runtime_application.(cl)dk::runtime::core::Application::onInit.return:false
TEST.VALUE:dk_runtime_application.(cl)dk::runtime::core::Application::onStart.return:false
TEST.FLOW
  dk_runtime_application.cpp.(cl)dk::runtime::core::Application::onRun
  dk_runtime_application.cpp.(cl)dk::runtime::core::Application::onRun
TEST.END_FLOW
TEST.END

-- Subprogram: (cl)dk::runtime::core::Application::onStart

-- Test Case: 01_Empty_container
TEST.UNIT:dk_runtime_application
TEST.SUBPROGRAM:(cl)dk::runtime::core::Application::onStart
TEST.NEW
TEST.NAME:01_Empty_container
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw) 
TEST.END_NOTES:
TEST.VALUE:dk_runtime_application.<<GLOBAL>>.(cl).dk::runtime::core::Application.dk::runtime::core::Application.<<constructor>>.Application(const char*).<<call>>:0
TEST.FLOW
  dk_runtime_application.cpp.(cl)dk::runtime::core::Application::onStart
  dk_runtime_application.cpp.(cl)dk::runtime::core::Application::onStart
TEST.END_FLOW
TEST.END

-- Test Case: 02_Non_empty_container
TEST.UNIT:dk_runtime_application
TEST.SUBPROGRAM:(cl)dk::runtime::core::Application::onStart
TEST.NEW
TEST.NAME:02_Non_empty_container
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw) 
TEST.END_NOTES:
TEST.VALUE:dk_runtime_application.<<GLOBAL>>.(cl).dk::runtime::core::Application.dk::runtime::core::Application.<<constructor>>.Application(const char*).<<call>>:0
TEST.VALUE:dk_runtime_application.<<GLOBAL>>.(cl).dk::runtime::core::Application.dk::runtime::core::Application.mContainerList:<<malloc 1>>
TEST.VALUE:dk_runtime_application.<<GLOBAL>>.(cl).dk::runtime::core::Application.dk::runtime::core::Application.mContainerList[0]:<<function 1>>
TEST.FLOW
  dk_runtime_application.cpp.(cl)dk::runtime::core::Application::onStart
  uut_prototype_stubs.dk::runtime::core::Container::onStart
  dk_runtime_application.cpp.(cl)dk::runtime::core::Application::onStart
TEST.END_FLOW
TEST.END

-- Subprogram: (cl)dk::runtime::core::Application::onStop

-- Test Case: 01_Empty_container
TEST.UNIT:dk_runtime_application
TEST.SUBPROGRAM:(cl)dk::runtime::core::Application::onStop
TEST.NEW
TEST.NAME:01_Empty_container
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw) 
TEST.END_NOTES:
TEST.VALUE:dk_runtime_application.<<GLOBAL>>.(cl).dk::runtime::core::Application.dk::runtime::core::Application.<<constructor>>.Application(const char*).<<call>>:0
TEST.FLOW
  dk_runtime_application.cpp.(cl)dk::runtime::core::Application::onStop
  dk_runtime_application.cpp.(cl)dk::runtime::core::Application::onStop
TEST.END_FLOW
TEST.END

-- Test Case: 02_Non_empty_container
TEST.UNIT:dk_runtime_application
TEST.SUBPROGRAM:(cl)dk::runtime::core::Application::onStop
TEST.NEW
TEST.NAME:02_Non_empty_container
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw) 
TEST.END_NOTES:
TEST.VALUE:dk_runtime_application.<<GLOBAL>>.(cl).dk::runtime::core::Application.dk::runtime::core::Application.<<constructor>>.Application(const char*).<<call>>:0
TEST.VALUE:dk_runtime_application.<<GLOBAL>>.(cl).dk::runtime::core::Application.dk::runtime::core::Application.mContainerList:<<malloc 1>>
TEST.VALUE:dk_runtime_application.<<GLOBAL>>.(cl).dk::runtime::core::Application.dk::runtime::core::Application.mContainerList[0]:<<function 1>>
TEST.FLOW
  dk_runtime_application.cpp.(cl)dk::runtime::core::Application::onStop
  uut_prototype_stubs.dk::runtime::core::Container::onStop
  dk_runtime_application.cpp.(cl)dk::runtime::core::Application::onStop
TEST.END_FLOW
TEST.END

-- Subprogram: (cl)dk::runtime::core::Application::run

-- Test Case: 01_Run_failed
TEST.UNIT:dk_runtime_application
TEST.SUBPROGRAM:(cl)dk::runtime::core::Application::run
TEST.NEW
TEST.NAME:01_Run_failed
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw) 
TEST.END_NOTES:
TEST.VALUE:dk_runtime_application.<<GLOBAL>>.(cl).dk::runtime::core::Application.dk::runtime::core::Application.<<constructor>>.Application(const char*).<<call>>:0
TEST.EXPECTED:dk_runtime_application.(cl)dk::runtime::core::Application::run.return:-1
TEST.END

-- Test Case: 02_Watchdog_disabled
TEST.UNIT:dk_runtime_application
TEST.SUBPROGRAM:(cl)dk::runtime::core::Application::run
TEST.NEW
TEST.NAME:02_Watchdog_disabled
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw) 
TEST.END_NOTES:
TEST.VALUE:dk_runtime_application.<<GLOBAL>>.(cl).dk::runtime::core::Application.dk::runtime::core::Application.<<constructor>>.Application(const char*).<<call>>:0
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::IpcMsgIf::connect.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::IpcMsgIf::subscribe.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::WdgIf::getWatchdogEnabled.return:false
TEST.EXPECTED:dk_runtime_application.(cl)dk::runtime::core::Application::run.return:1
TEST.END

-- Test Case: 03_Watchdog_enabled_connect_failed
TEST.UNIT:dk_runtime_application
TEST.SUBPROGRAM:(cl)dk::runtime::core::Application::run
TEST.NEW
TEST.NAME:03_Watchdog_enabled_connect_failed
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw) 
TEST.END_NOTES:
TEST.VALUE:dk_runtime_application.<<GLOBAL>>.(cl).dk::runtime::core::Application.dk::runtime::core::Application.<<constructor>>.Application(const char*).<<call>>:0
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::IpcMsgIf::connect.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::IpcMsgIf::subscribe.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::WdgIf::connect.return:false
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::WdgIf::getWatchdogEnabled.return:true
TEST.EXPECTED:dk_runtime_application.(cl)dk::runtime::core::Application::run.return:-1
TEST.END

-- Test Case: 04_Watchdog_enabled_connect_success
TEST.UNIT:dk_runtime_application
TEST.SUBPROGRAM:(cl)dk::runtime::core::Application::run
TEST.NEW
TEST.NAME:04_Watchdog_enabled_connect_success
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw) 
TEST.END_NOTES:
TEST.VALUE:dk_runtime_application.<<GLOBAL>>.(cl).dk::runtime::core::Application.dk::runtime::core::Application.<<constructor>>.Application(const char*).<<call>>:0
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::IpcMsgIf::connect.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::IpcMsgIf::subscribe.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::WdgIf::connect.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::WdgIf::getWatchdogEnabled.return:true
TEST.EXPECTED:dk_runtime_application.(cl)dk::runtime::core::Application::run.return:1
TEST.END

-- Subprogram: (cl)dk::runtime::core::Application::runDispatchQueue

-- Test Case: 01_TimedWait_failed
TEST.UNIT:dk_runtime_application
TEST.SUBPROGRAM:(cl)dk::runtime::core::Application::runDispatchQueue
TEST.NEW
TEST.NAME:01_TimedWait_failed
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw) 
TEST.END_NOTES:
TEST.VALUE:dk_runtime_application.<<GLOBAL>>.(cl).dk::runtime::core::Application.dk::runtime::core::Application.<<constructor>>.Application(const char*).<<call>>:0
TEST.VALUE:uut_prototype_stubs.dk::osal::Semaphore::timedWaitMS.return:false
TEST.FLOW
  dk_runtime_application.cpp.(cl)dk::runtime::core::Application::runDispatchQueue
  uut_prototype_stubs.dk::osal::Semaphore::timedWaitMS
  dk_runtime_application.cpp.(cl)dk::runtime::core::Application::runDispatchQueue
TEST.END_FLOW
TEST.END

-- Test Case: 02_Null_serializer
TEST.UNIT:dk_runtime_application
TEST.SUBPROGRAM:(cl)dk::runtime::core::Application::runDispatchQueue
TEST.NEW
TEST.NAME:02_Null_serializer
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw) 
TEST.END_NOTES:
TEST.STUB:uut_prototype_stubs.dk::runtime::core::FifoSerializer::pull
TEST.VALUE:dk_runtime_application.<<GLOBAL>>.(cl).dk::runtime::core::Application.dk::runtime::core::Application.<<constructor>>.Application(const char*).<<call>>:0
TEST.VALUE:dk_runtime_application.<<GLOBAL>>.(cl).dk::runtime::core::Application.dk::runtime::core::Application.mpDispatchQueueSem:<<null>>
TEST.VALUE:uut_prototype_stubs.dk::osal::Semaphore::timedWaitMS.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::FifoSerializer::pull.return:<<null>>
TEST.FLOW
  dk_runtime_application.cpp.(cl)dk::runtime::core::Application::runDispatchQueue
  uut_prototype_stubs.dk::osal::Semaphore::timedWaitMS
  uut_prototype_stubs.dk::runtime::core::FifoSerializer::pull
  dk_runtime_application.cpp.(cl)dk::runtime::core::Application::runDispatchQueue
TEST.END_FLOW
TEST.END

-- Test Case: 03_Loop_dispatch_queue_once
TEST.UNIT:dk_runtime_application
TEST.SUBPROGRAM:(cl)dk::runtime::core::Application::runDispatchQueue
TEST.NEW
TEST.NAME:03_Loop_dispatch_queue_once
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw) 
TEST.END_NOTES:
TEST.STUB:uut_prototype_stubs.dk::runtime::core::FifoSerializer::pull
TEST.VALUE:dk_runtime_application.<<GLOBAL>>.(cl).dk::runtime::core::Application.dk::runtime::core::Application.<<constructor>>.Application(const char*).<<call>>:0
TEST.VALUE:uut_prototype_stubs.dk::osal::Semaphore::timedWaitMS.return:true
TEST.FLOW
  dk_runtime_application.cpp.(cl)dk::runtime::core::Application::runDispatchQueue
  uut_prototype_stubs.dk::osal::Semaphore::timedWaitMS
  uut_prototype_stubs.dk::runtime::core::FifoSerializer::pull
  uut_prototype_stubs.dk::runtime::core::Serializer::Serializer
  uut_prototype_stubs.dk::runtime::core::Serializer::reset
  uut_prototype_stubs.dk::runtime::core::Serializer::~Serializer
  uut_prototype_stubs.dk::runtime::core::FifoSerializer::pull
  dk_runtime_application.cpp.(cl)dk::runtime::core::Application::runDispatchQueue
TEST.END_FLOW
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.dk::runtime::core::FifoSerializer::pull.return
static int index;
void * ret = NULL;
if (index) {
    ret = NULL;
}else {
    ret = new dk::runtime::core::MsgSerializer(0,0,0);
    index++;
}
<<uut_prototype_stubs.dk::runtime::core::FifoSerializer::pull.return>> = ( (dk::runtime::core::MsgSerializer*)ret );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: 04_Loop_container_once
TEST.UNIT:dk_runtime_application
TEST.SUBPROGRAM:(cl)dk::runtime::core::Application::runDispatchQueue
TEST.NEW
TEST.NAME:04_Loop_container_once
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw) 
TEST.END_NOTES:
TEST.STUB:uut_prototype_stubs.dk::runtime::core::FifoSerializer::pull
TEST.VALUE:dk_runtime_application.<<GLOBAL>>.(cl).dk::runtime::core::Application.dk::runtime::core::Application.<<constructor>>.Application(const char*).<<call>>:0
TEST.VALUE:dk_runtime_application.<<GLOBAL>>.(cl).dk::runtime::core::Application.dk::runtime::core::Application.mContainerList:<<malloc 1>>
TEST.VALUE:dk_runtime_application.<<GLOBAL>>.(cl).dk::runtime::core::Application.dk::runtime::core::Application.mContainerList[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.dk::osal::Semaphore::timedWaitMS.return:true
TEST.FLOW
  dk_runtime_application.cpp.(cl)dk::runtime::core::Application::runDispatchQueue
  uut_prototype_stubs.dk::osal::Semaphore::timedWaitMS
  uut_prototype_stubs.dk::runtime::core::FifoSerializer::pull
  uut_prototype_stubs.dk::runtime::core::Serializer::Serializer
  uut_prototype_stubs.dk::runtime::core::Serializer::getSize
  uut_prototype_stubs.dk::runtime::core::Serializer::getData
  uut_prototype_stubs.dk::runtime::core::Deserializer::Deserializer(byte_t*,uint32_t,uint32_t)
  uut_prototype_stubs.dk::runtime::core::Container::onRxMessage
  uut_prototype_stubs.dk::runtime::core::Deserializer::reset
  uut_prototype_stubs.dk::runtime::core::Deserializer::~Deserializer
  uut_prototype_stubs.dk::runtime::core::Serializer::reset
  uut_prototype_stubs.dk::runtime::core::Serializer::~Serializer
  uut_prototype_stubs.dk::runtime::core::FifoSerializer::pull
  dk_runtime_application.cpp.(cl)dk::runtime::core::Application::runDispatchQueue
TEST.END_FLOW
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.dk::runtime::core::FifoSerializer::pull.return
static int index;
void * ret = NULL;
if (index) {
    ret = NULL;
}else {
    ret = new dk::runtime::core::MsgSerializer(0,0,0);
    index++;
}
<<uut_prototype_stubs.dk::runtime::core::FifoSerializer::pull.return>> = ( (dk::runtime::core::MsgSerializer*)ret );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::runtime::core::Application::runIpcMessagePump

-- Test Case: 01_Run_ipc_message_pump
TEST.UNIT:dk_runtime_application
TEST.SUBPROGRAM:(cl)dk::runtime::core::Application::runIpcMessagePump
TEST.NEW
TEST.NAME:01_Run_ipc_message_pump
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw) 
TEST.END_NOTES:
TEST.VALUE:dk_runtime_application.<<GLOBAL>>.(cl).dk::runtime::core::Application.dk::runtime::core::Application.<<constructor>>.Application(const char*).<<call>>:0
TEST.FLOW
  dk_runtime_application.cpp.(cl)dk::runtime::core::Application::runIpcMessagePump
  dk_runtime_application.cpp.(cl)dk::runtime::core::Application::runIpcMessagePump
TEST.END_FLOW
TEST.END

-- Subprogram: (cl)dk::runtime::core::Application::sendMsgToDisplatchQueue

-- Test Case: 01_Send_msg_to_dispatch_queue
TEST.UNIT:dk_runtime_application
TEST.SUBPROGRAM:(cl)dk::runtime::core::Application::sendMsgToDisplatchQueue
TEST.NEW
TEST.NAME:01_Send_msg_to_dispatch_queue
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw) 
TEST.END_NOTES:
TEST.VALUE:dk_runtime_application.<<GLOBAL>>.(cl).dk::runtime::core::Application.dk::runtime::core::Application.<<constructor>>.Application(const char*).<<call>>:0
TEST.FLOW
  dk_runtime_application.cpp.(cl)dk::runtime::core::Application::sendMsgToDisplatchQueue
  uut_prototype_stubs.std::mutex::lock
  uut_prototype_stubs.std::mutex::unlock
  uut_prototype_stubs.dk::osal::Semaphore::post
  dk_runtime_application.cpp.(cl)dk::runtime::core::Application::sendMsgToDisplatchQueue
TEST.END_FLOW
TEST.END

-- Subprogram: (cl)dk::runtime::core::Application::sendMsgToIpc

-- Test Case: 01_Sending_successful
TEST.UNIT:dk_runtime_application
TEST.SUBPROGRAM:(cl)dk::runtime::core::Application::sendMsgToIpc
TEST.NEW
TEST.NAME:01_Sending_successful
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw) 
TEST.END_NOTES:
TEST.VALUE:dk_runtime_application.<<GLOBAL>>.(cl).dk::runtime::core::Application.dk::runtime::core::Application.<<constructor>>.Application(const char*).<<call>>:0
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::IpcMsgIf::send.return:true
TEST.FLOW
  uut_prototype_stubs.dk::runtime::core::Serializer::Serializer
  uut_prototype_stubs.dk::runtime::core::Serializer::serialize(const uint8_t*,uint32_t)bool
  dk_runtime_application.cpp.(cl)dk::runtime::core::Application::sendMsgToIpc
  uut_prototype_stubs.dk::runtime::core::Serializer::getSize
  uut_prototype_stubs.dk::runtime::core::Serializer::getSize
  uut_prototype_stubs.dk::runtime::core::Serializer::getData
  uut_prototype_stubs.dk::runtime::core::IpcMsgIf::send
  dk_runtime_application.cpp.(cl)dk::runtime::core::Application::sendMsgToIpc
TEST.END_FLOW
TEST.VALUE_USER_CODE:dk_runtime_application.(cl)dk::runtime::core::Application::sendMsgToIpc.pMsgSer
static dk::runtime::core::MsgSerializer *obj = new dk::runtime::core::MsgSerializer((mid_t)1, 1, (const uint8_t *) "Test", 4);
static std::shared_ptr<dk::runtime::core::MsgSerializer> temp(obj);
<<dk_runtime_application.(cl)dk::runtime::core::Application::sendMsgToIpc.pMsgSer>> = ( &temp );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 02_Sending_failed
TEST.UNIT:dk_runtime_application
TEST.SUBPROGRAM:(cl)dk::runtime::core::Application::sendMsgToIpc
TEST.NEW
TEST.NAME:02_Sending_failed
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw) 
TEST.END_NOTES:
TEST.VALUE:dk_runtime_application.<<GLOBAL>>.(cl).dk::runtime::core::Application.dk::runtime::core::Application.<<constructor>>.Application(const char*).<<call>>:0
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::IpcMsgIf::send.return:false
TEST.FLOW
  uut_prototype_stubs.dk::runtime::core::Serializer::Serializer
  uut_prototype_stubs.dk::runtime::core::Serializer::serialize(const uint8_t*,uint32_t)bool
  dk_runtime_application.cpp.(cl)dk::runtime::core::Application::sendMsgToIpc
  uut_prototype_stubs.dk::runtime::core::Serializer::getSize
  uut_prototype_stubs.dk::runtime::core::Serializer::getSize
  uut_prototype_stubs.dk::runtime::core::Serializer::getData
  uut_prototype_stubs.dk::runtime::core::IpcMsgIf::send
  dk_runtime_application.cpp.(cl)dk::runtime::core::Application::sendMsgToIpc
TEST.END_FLOW
TEST.VALUE_USER_CODE:dk_runtime_application.(cl)dk::runtime::core::Application::sendMsgToIpc.pMsgSer
static dk::runtime::core::MsgSerializer *obj = new dk::runtime::core::MsgSerializer((mid_t)1, 1, (const uint8_t *) "Test", 4);
static std::shared_ptr<dk::runtime::core::MsgSerializer> temp(obj);
<<dk_runtime_application.(cl)dk::runtime::core::Application::sendMsgToIpc.pMsgSer>> = ( &temp );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::runtime::core::Application::setWatchdogEnabled

-- Test Case: 01_Set_watchdog_status
TEST.UNIT:dk_runtime_application
TEST.SUBPROGRAM:(cl)dk::runtime::core::Application::setWatchdogEnabled
TEST.NEW
TEST.NAME:01_Set_watchdog_status
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw) 
TEST.END_NOTES:
TEST.STUB:dk_runtime_application.(cl)dk::runtime::core::Application::onInit
TEST.STUB:dk_runtime_application.(cl)dk::runtime::core::Application::onStart
TEST.VALUE:dk_runtime_application.<<GLOBAL>>.(cl).dk::runtime::core::Application.dk::runtime::core::Application.<<constructor>>.Application(const char*).<<call>>:0
TEST.VALUE:dk_runtime_application.(cl)dk::runtime::core::Application::onInit.return:false
TEST.VALUE:dk_runtime_application.(cl)dk::runtime::core::Application::onStart.return:false
TEST.FLOW
  dk_runtime_application.cpp.(cl)dk::runtime::core::Application::setWatchdogEnabled
  uut_prototype_stubs.dk::runtime::core::WdgIf::setWatchdogEnabled
  dk_runtime_application.cpp.(cl)dk::runtime::core::Application::setWatchdogEnabled
TEST.END_FLOW
TEST.END

-- Subprogram: (cl)dk::runtime::core::Application::stop

-- Test Case: 01_Watchdog_enabled
TEST.UNIT:dk_runtime_application
TEST.SUBPROGRAM:(cl)dk::runtime::core::Application::stop
TEST.NEW
TEST.NAME:01_Watchdog_enabled
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw) 
TEST.END_NOTES:
TEST.VALUE:dk_runtime_application.<<GLOBAL>>.(cl).dk::runtime::core::Application.dk::runtime::core::Application.<<constructor>>.Application(const char*).<<call>>:0
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::WdgIf::getWatchdogEnabled.return:true
TEST.EXPECTED:dk_runtime_application.(cl)dk::runtime::core::Application::stop.return:0
TEST.END

-- Test Case: 02_Watchdog_disable
TEST.UNIT:dk_runtime_application
TEST.SUBPROGRAM:(cl)dk::runtime::core::Application::stop
TEST.NEW
TEST.NAME:02_Watchdog_disable
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw) 
TEST.END_NOTES:
TEST.VALUE:dk_runtime_application.<<GLOBAL>>.(cl).dk::runtime::core::Application.dk::runtime::core::Application.<<constructor>>.Application(const char*).<<call>>:0
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::WdgIf::getWatchdogEnabled.return:false
TEST.EXPECTED:dk_runtime_application.(cl)dk::runtime::core::Application::stop.return:0
TEST.END

-- Test Case: 02_Watchdog_disable.001
TEST.UNIT:dk_runtime_application
TEST.SUBPROGRAM:(cl)dk::runtime::core::Application::stop
TEST.NEW
TEST.NAME:02_Watchdog_disable.001
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw) 
TEST.END_NOTES:
TEST.STUB:dk_runtime_application.(cl)dk::runtime::core::Application::onInit
TEST.STUB:dk_runtime_application.(cl)dk::runtime::core::Application::onStart
TEST.VALUE:dk_runtime_application.<<GLOBAL>>.(cl).dk::runtime::core::Application.dk::runtime::core::Application.<<constructor>>.Application(const char*).<<call>>:0
TEST.VALUE:dk_runtime_application.(cl)dk::runtime::core::Application::onInit.return:false
TEST.VALUE:dk_runtime_application.(cl)dk::runtime::core::Application::onStart.return:false
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::WdgIf::getWatchdogEnabled.return:false
TEST.EXPECTED:dk_runtime_application.(cl)dk::runtime::core::Application::stop.return:0
TEST.END

-- Subprogram: (cl)dk::runtime::core::Application::~Application

-- Test Case: 01_DeInitialization
TEST.UNIT:dk_runtime_application
TEST.SUBPROGRAM:(cl)dk::runtime::core::Application::~Application
TEST.NEW
TEST.NAME:01_DeInitialization
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw) 
TEST.END_NOTES:
TEST.VALUE:dk_runtime_application.<<GLOBAL>>.(cl).dk::runtime::core::Application.dk::runtime::core::Application.<<constructor>>.Application(const char*).<<call>>:0
TEST.FLOW
  dk_runtime_application.cpp.(cl)dk::runtime::core::Application::~Application
  uut_prototype_stubs.dk::runtime::core::IpcMsgIf::~IpcMsgIf
  dk_runtime_application.cpp.(cl)dk::runtime::core::Application::~Application
TEST.END_FLOW
TEST.END
