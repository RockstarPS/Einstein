-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : RUNTIME_CONTAINER_UT
-- Unit(s) Under Test: dk_runtime_container
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

-- Unit: dk_runtime_container

-- Subprogram: (cl)dk::runtime::core::Container::addComponent()

-- Test Case: 01_Add_component
TEST.UNIT:dk_runtime_container
TEST.SUBPROGRAM:(cl)dk::runtime::core::Container::addComponent()
TEST.NEW
TEST.NAME:01_Add_component
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.FLOW
  uut_prototype_stubs.dk::osal::Semaphore::Semaphore(uint32_t)
  dk_runtime_container.cpp.(cl)dk::runtime::core::Container::addComponent()
  dk_runtime_container.cpp.(cl)dk::runtime::core::Container::addComponent()
TEST.END_FLOW
TEST.VALUE_USER_CODE:<<dk::runtime::core::Container instance>>
static std::map<dk::runtime::core::mid_t, dk::runtime::core::func_t> dummy;
static dk::runtime::core::Component comp_temp(&dummy, "test");
static dk::runtime::core::Container test(&comp_temp);
<<dk::runtime::core::Container instance>> = ( &test );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::runtime::core::Container::addComponent(dk::runtime::core::Component*)

-- Test Case: 01_Add_component
TEST.UNIT:dk_runtime_container
TEST.SUBPROGRAM:(cl)dk::runtime::core::Container::addComponent(dk::runtime::core::Component*)
TEST.NEW
TEST.NAME:01_Add_component
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_container.(cl)dk::runtime::core::Container::addComponent(dk::runtime::core::Component*).pComponent.dk::runtime::core::Component.<<constructor>>.Component(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*,const char*).<<call>>:0
TEST.FLOW
  uut_prototype_stubs.dk::osal::Semaphore::Semaphore(uint32_t)
  dk_runtime_container.cpp.(cl)dk::runtime::core::Container::addComponent(dk::runtime::core::Component*)
  dk_runtime_container.cpp.(cl)dk::runtime::core::Container::addComponent(dk::runtime::core::Component*)
TEST.END_FLOW
TEST.VALUE_USER_CODE:<<dk::runtime::core::Container instance>>
static std::map<dk::runtime::core::mid_t, dk::runtime::core::func_t> dummy;
static dk::runtime::core::Component comp_temp(&dummy, "test");
static dk::runtime::core::Container test(&comp_temp);
<<dk::runtime::core::Container instance>> = ( &test );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::runtime::core::Container::getMessageGroups

-- Test Case: 01_Get_message_groups
TEST.UNIT:dk_runtime_container
TEST.SUBPROGRAM:(cl)dk::runtime::core::Container::getMessageGroups
TEST.NEW
TEST.NAME:01_Get_message_groups
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_container.(cl)dk::runtime::core::Container::getMessageGroups.msgGroups:<<malloc 1>>
TEST.VALUE:dk_runtime_container.(cl)dk::runtime::core::Container::getMessageGroups.msgGroups[0]:<<function 1>>
TEST.FLOW
  uut_prototype_stubs.dk::osal::Semaphore::Semaphore(uint32_t)
  dk_runtime_container.cpp.(cl)dk::runtime::core::Container::getMessageGroups
  dk_runtime_container.cpp.(cl)dk::runtime::core::Container::getMessageGroups
TEST.END_FLOW
TEST.VALUE_USER_CODE:<<dk::runtime::core::Container instance>>
static std::map<dk::runtime::core::mid_t, dk::runtime::core::func_t> dummy;
dummy[0] = NULL;
static dk::runtime::core::Component comp_temp(&dummy, "test");
static dk::runtime::core::Container test(&comp_temp);
<<dk::runtime::core::Container instance>> = ( &test );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::runtime::core::Container::onExit

-- Test Case: 01_OnExit_success
TEST.UNIT:dk_runtime_container
TEST.SUBPROGRAM:(cl)dk::runtime::core::Container::onExit
TEST.NEW
TEST.NAME:01_OnExit_success
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.FLOW
  uut_prototype_stubs.dk::osal::Semaphore::Semaphore(uint32_t)
  dk_runtime_container.cpp.(cl)dk::runtime::core::Container::onExit
  uut_prototype_stubs.dk::runtime::core::Component::onExit
  dk_runtime_container.cpp.(cl)dk::runtime::core::Container::onExit
TEST.END_FLOW
TEST.VALUE_USER_CODE:<<dk::runtime::core::Container instance>>
static std::map<dk::runtime::core::mid_t, dk::runtime::core::func_t> dummy;
static dk::runtime::core::Component comp_temp(&dummy, "test");
static dk::runtime::core::Container test(&comp_temp);
<<dk::runtime::core::Container instance>> = ( &test );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::runtime::core::Container::onInit

-- Test Case: 01_OnInit_success
TEST.UNIT:dk_runtime_container
TEST.SUBPROGRAM:(cl)dk::runtime::core::Container::onInit
TEST.NEW
TEST.NAME:01_OnInit_success
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.FLOW
  uut_prototype_stubs.dk::osal::Semaphore::Semaphore(uint32_t)
  dk_runtime_container.cpp.(cl)dk::runtime::core::Container::onInit
  uut_prototype_stubs.dk::runtime::core::Component::onInit
  dk_runtime_container.cpp.(cl)dk::runtime::core::Container::onInit
TEST.END_FLOW
TEST.VALUE_USER_CODE:<<dk::runtime::core::Container instance>>
static std::map<dk::runtime::core::mid_t, dk::runtime::core::func_t> dummy;
static dk::runtime::core::Component comp_temp(&dummy, "test");
static dk::runtime::core::Container test(&comp_temp);
<<dk::runtime::core::Container instance>> = ( &test );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::runtime::core::Container::onRxMessage

-- Test Case: 01_Message_id_not_found
TEST.UNIT:dk_runtime_container
TEST.SUBPROGRAM:(cl)dk::runtime::core::Container::onRxMessage
TEST.NEW
TEST.NAME:01_Message_id_not_found
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_container.(cl)dk::runtime::core::Container::onRxMessage.msgDes.dk::runtime::core::MsgDeserializer.<<constructor>>.MsgDeserializer(dk::runtime::core::MsgSerializer*).pMsgSerializer.dk::runtime::core::MsgSerializer.<<constructor>>.MsgSerializer(const dk::runtime::core::mid_t,uint16_t,uint8_t).<<call>>:0
TEST.VALUE:dk_runtime_container.(cl)dk::runtime::core::Container::onRxMessage.msgDes.dk::runtime::core::MsgDeserializer.<<constructor>>.MsgDeserializer(dk::runtime::core::MsgSerializer*).<<call>>:0
TEST.FLOW
  uut_prototype_stubs.dk::osal::Semaphore::Semaphore(uint32_t)
  dk_runtime_container.cpp.(cl)dk::runtime::core::Container::onRxMessage
  dk_runtime_container.cpp.(cl)dk::runtime::core::Container::onRxMessage
TEST.END_FLOW
TEST.VALUE_USER_CODE:<<dk::runtime::core::Container instance>>
static std::map<dk::runtime::core::mid_t, dk::runtime::core::func_t> dummy;
static dk::runtime::core::Component comp_temp(&dummy, "test");
static dk::runtime::core::Container test(&comp_temp);
test.mMsgIDs.insert((uint16_t)10);
<<dk::runtime::core::Container instance>> = ( &test );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 02_Message_id_found
TEST.UNIT:dk_runtime_container
TEST.SUBPROGRAM:(cl)dk::runtime::core::Container::onRxMessage
TEST.NEW
TEST.NAME:02_Message_id_found
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_container.(cl)dk::runtime::core::Container::onRxMessage.msgDes.dk::runtime::core::MsgDeserializer.<<constructor>>.MsgDeserializer(dk::runtime::core::MsgSerializer*).pMsgSerializer.dk::runtime::core::MsgSerializer.<<constructor>>.MsgSerializer(const dk::runtime::core::mid_t,uint16_t,uint8_t).msgId:10
TEST.VALUE:dk_runtime_container.(cl)dk::runtime::core::Container::onRxMessage.msgDes.dk::runtime::core::MsgDeserializer.<<constructor>>.MsgDeserializer(dk::runtime::core::MsgSerializer*).pMsgSerializer.dk::runtime::core::MsgSerializer.<<constructor>>.MsgSerializer(const dk::runtime::core::mid_t,uint16_t,uint8_t).<<call>>:0
TEST.VALUE:dk_runtime_container.(cl)dk::runtime::core::Container::onRxMessage.msgDes.dk::runtime::core::MsgDeserializer.<<constructor>>.MsgDeserializer(dk::runtime::core::MsgSerializer*).<<call>>:0
TEST.FLOW
  uut_prototype_stubs.dk::osal::Semaphore::Semaphore(uint32_t)
  dk_runtime_container.cpp.(cl)dk::runtime::core::Container::onRxMessage
  uut_prototype_stubs.dk::runtime::core::Deserializer::getSize
  uut_prototype_stubs.dk::runtime::core::Deserializer::getData
  uut_prototype_stubs.std::mutex::lock
  uut_prototype_stubs.std::mutex::unlock
  uut_prototype_stubs.dk::osal::Semaphore::post
  dk_runtime_container.cpp.(cl)dk::runtime::core::Container::onRxMessage
TEST.END_FLOW
TEST.VALUE_USER_CODE:<<dk::runtime::core::Container instance>>
static std::map<dk::runtime::core::mid_t, dk::runtime::core::func_t> dummy;
static dk::runtime::core::Component comp_temp(&dummy, "test");
static dk::runtime::core::Container test(&comp_temp);
test.mMsgIDs.insert((uint16_t)10);
<<dk::runtime::core::Container instance>> = ( &test );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::runtime::core::Container::onStart

-- Test Case: 01_OnStart_success
TEST.UNIT:dk_runtime_container
TEST.SUBPROGRAM:(cl)dk::runtime::core::Container::onStart
TEST.NEW
TEST.NAME:01_OnStart_success
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.FLOW
  uut_prototype_stubs.dk::osal::Semaphore::Semaphore(uint32_t)
  dk_runtime_container.cpp.(cl)dk::runtime::core::Container::onStart
  uut_prototype_stubs.dk::runtime::core::Component::onStart
  dk_runtime_container.cpp.(cl)dk::runtime::core::Container::onStart
TEST.END_FLOW
TEST.VALUE_USER_CODE:<<dk::runtime::core::Container instance>>
static std::map<dk::runtime::core::mid_t, dk::runtime::core::func_t> dummy;
static dk::runtime::core::Component comp_temp(&dummy, "test");
static dk::runtime::core::Container test(&comp_temp);
<<dk::runtime::core::Container instance>> = ( &test );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::runtime::core::Container::onStop

-- Test Case: 01_OnStop_success
TEST.UNIT:dk_runtime_container
TEST.SUBPROGRAM:(cl)dk::runtime::core::Container::onStop
TEST.NEW
TEST.NAME:01_OnStop_success
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.FLOW
  uut_prototype_stubs.dk::osal::Semaphore::Semaphore(uint32_t)
  dk_runtime_container.cpp.(cl)dk::runtime::core::Container::onStop
  uut_prototype_stubs.dk::runtime::core::Component::onStop
  dk_runtime_container.cpp.(cl)dk::runtime::core::Container::onStop
TEST.END_FLOW
TEST.VALUE_USER_CODE:<<dk::runtime::core::Container instance>>
static std::map<dk::runtime::core::mid_t, dk::runtime::core::func_t> dummy;
static dk::runtime::core::Component comp_temp(&dummy, "test");
static dk::runtime::core::Container test(&comp_temp);
<<dk::runtime::core::Container instance>> = ( &test );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::runtime::core::Container::runMessagePump

-- Test Case: 01_TimedWait_failed
TEST.UNIT:dk_runtime_container
TEST.SUBPROGRAM:(cl)dk::runtime::core::Container::runMessagePump
TEST.NEW
TEST.NAME:01_TimedWait_failed
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.dk::osal::Semaphore::timedWaitMS.return:false
TEST.EXPECTED:dk_runtime_container.(cl)dk::runtime::core::Container::runMessagePump.return:1
TEST.VALUE_USER_CODE:<<dk::runtime::core::Container instance>>
static std::map<dk::runtime::core::mid_t, dk::runtime::core::func_t> dummy;
static dk::runtime::core::Component comp_temp(&dummy, "test");
static dk::runtime::core::Container test(&comp_temp);
<<dk::runtime::core::Container instance>> = ( &test );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 02_Null_RxMsgQueue
TEST.UNIT:dk_runtime_container
TEST.SUBPROGRAM:(cl)dk::runtime::core::Container::runMessagePump
TEST.NEW
TEST.NAME:02_Null_RxMsgQueue
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.dk::osal::Semaphore::timedWaitMS.return:true
TEST.EXPECTED:dk_runtime_container.(cl)dk::runtime::core::Container::runMessagePump.return:1
TEST.VALUE_USER_CODE:<<dk::runtime::core::Container instance>>
static std::map<dk::runtime::core::mid_t, dk::runtime::core::func_t> dummy;
static dk::runtime::core::Component comp_temp(&dummy, "test");
static dk::runtime::core::Container test(&comp_temp);
<<dk::runtime::core::Container instance>> = ( &test );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 03_Non_null_RxMsgQueue
TEST.UNIT:dk_runtime_container
TEST.SUBPROGRAM:(cl)dk::runtime::core::Container::runMessagePump
TEST.NEW
TEST.NAME:03_Non_null_RxMsgQueue
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.dk::osal::Semaphore::timedWaitMS.return:true
TEST.EXPECTED:dk_runtime_container.(cl)dk::runtime::core::Container::runMessagePump.return:1
TEST.VALUE_USER_CODE:<<dk::runtime::core::Container instance>>
static std::map<dk::runtime::core::mid_t, dk::runtime::core::func_t> dummy;
static dk::runtime::core::Component comp_temp(&dummy, "test");
static dk::runtime::core::Container test(&comp_temp);
test.mRxMsgQueue.push(1, 1, 1, (const uint8_t*) "test", 4);
<<dk::runtime::core::Container instance>> = ( &test );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::runtime::core::Container::~Container

-- Test Case: 01_DeInitialization
TEST.UNIT:dk_runtime_container
TEST.SUBPROGRAM:(cl)dk::runtime::core::Container::~Container
TEST.NEW
TEST.NAME:01_DeInitialization
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.FLOW
  uut_prototype_stubs.dk::osal::Semaphore::Semaphore(uint32_t)
  dk_runtime_container.cpp.(cl)dk::runtime::core::Container::~Container
  dk_runtime_container.cpp.(cl)dk::runtime::core::Container::~Container
TEST.END_FLOW
TEST.VALUE_USER_CODE:<<dk::runtime::core::Container instance>>
static std::map<dk::runtime::core::mid_t, dk::runtime::core::func_t> dummy;
static dk::runtime::core::Component comp_temp(&dummy, "test");
static dk::runtime::core::Container test(&comp_temp);
<<dk::runtime::core::Container instance>> = ( &test );
TEST.END_VALUE_USER_CODE:
TEST.END
