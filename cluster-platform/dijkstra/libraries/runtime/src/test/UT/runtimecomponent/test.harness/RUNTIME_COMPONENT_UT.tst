-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : RUNTIME_COMPONENT_UT
-- Unit(s) Under Test: dk_runtime_component
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

-- Unit: dk_runtime_component

-- Subprogram: (cl)dk::runtime::core::Component::Component

-- Test Case: 01_Initialization
TEST.UNIT:dk_runtime_component
TEST.SUBPROGRAM:(cl)dk::runtime::core::Component::Component
TEST.NEW
TEST.NAME:01_Initialization
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.FLOW
  dk_runtime_component.cpp.(cl)dk::runtime::core::Component::Component
  dk_runtime_component.cpp.(cl)dk::runtime::core::Component::Component
TEST.END_FLOW
TEST.END

-- Subprogram: (cl)dk::runtime::core::Component::getMsgMap

-- Test Case: 01_Get_msg_map
TEST.UNIT:dk_runtime_component
TEST.SUBPROGRAM:(cl)dk::runtime::core::Component::getMsgMap
TEST.NEW
TEST.NAME:01_Get_msg_map
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.<<constructor>>.Component(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*,const char*).<<call>>:0
TEST.FLOW
  dk_runtime_component.cpp.(cl)dk::runtime::core::Component::getMsgMap
  dk_runtime_component.cpp.(cl)dk::runtime::core::Component::getMsgMap
TEST.END_FLOW
TEST.END

-- Subprogram: (cl)dk::runtime::core::Component::nowTimeMs

-- Test Case: 01_Get_current_time
TEST.UNIT:dk_runtime_component
TEST.SUBPROGRAM:(cl)dk::runtime::core::Component::nowTimeMs
TEST.NEW
TEST.NAME:01_Get_current_time
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.<<constructor>>.Component(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*,const char*).<<call>>:0
TEST.FLOW
  dk_runtime_component.cpp.(cl)dk::runtime::core::Component::nowTimeMs
  dk_runtime_component.cpp.(cl)dk::runtime::core::Component::nowTimeMs
TEST.END_FLOW
TEST.END

-- Subprogram: (cl)dk::runtime::core::Component::onExit

-- Test Case: 01_OnExit_success
TEST.UNIT:dk_runtime_component
TEST.SUBPROGRAM:(cl)dk::runtime::core::Component::onExit
TEST.NEW
TEST.NAME:01_OnExit_success
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.<<constructor>>.Component(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*,const char*).<<call>>:0
TEST.EXPECTED:dk_runtime_component.(cl)dk::runtime::core::Component::onExit.return:true
TEST.END

-- Subprogram: (cl)dk::runtime::core::Component::onInit

-- Test Case: 01_OnInit_success
TEST.UNIT:dk_runtime_component
TEST.SUBPROGRAM:(cl)dk::runtime::core::Component::onInit
TEST.NEW
TEST.NAME:01_OnInit_success
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.<<constructor>>.Component(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*,const char*).<<call>>:0
TEST.EXPECTED:dk_runtime_component.(cl)dk::runtime::core::Component::onInit.return:true
TEST.END

-- Subprogram: (cl)dk::runtime::core::Component::onRxMessage

-- Test Case: 01_Message_map_empty
TEST.UNIT:dk_runtime_component
TEST.SUBPROGRAM:(cl)dk::runtime::core::Component::onRxMessage
TEST.NEW
TEST.NAME:01_Message_map_empty
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.<<constructor>>.Component(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*,const char*).<<call>>:0
TEST.VALUE:dk_runtime_component.(cl)dk::runtime::core::Component::onRxMessage.msgDes.dk::runtime::core::MsgDeserializer.<<constructor>>.MsgDeserializer(const dk::runtime::core::mid_t,uint8_t,uint8_t,const uint8_t*,uint32_t).msgId:1
TEST.VALUE:dk_runtime_component.(cl)dk::runtime::core::Component::onRxMessage.msgDes.dk::runtime::core::MsgDeserializer.<<constructor>>.MsgDeserializer(const dk::runtime::core::mid_t,uint8_t,uint8_t,const uint8_t*,uint32_t).<<call>>:0
TEST.FLOW
  dk_runtime_component.cpp.(cl)dk::runtime::core::Component::onRxMessage
  dk_runtime_component.cpp.(cl)dk::runtime::core::Component::onRxMessage
TEST.END_FLOW
TEST.VALUE_USER_CODE:<<dk::runtime::core::Component instance>>.dk::runtime::core::Component.mMsgMap
static std::map<dk::runtime::core::mid_t, dk::runtime::core::func_t> temp;
<<dk::runtime::core::Component instance>>->mMsgMap = ( &temp );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 02_Message_updated
TEST.UNIT:dk_runtime_component
TEST.SUBPROGRAM:(cl)dk::runtime::core::Component::onRxMessage
TEST.NEW
TEST.NAME:02_Message_updated
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.<<constructor>>.Component(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*,const char*).<<call>>:0
TEST.VALUE:dk_runtime_component.(cl)dk::runtime::core::Component::onRxMessage.msgDes.dk::runtime::core::MsgDeserializer.<<constructor>>.MsgDeserializer(const dk::runtime::core::mid_t,uint8_t,uint8_t,const uint8_t*,uint32_t).msgId:1
TEST.VALUE:dk_runtime_component.(cl)dk::runtime::core::Component::onRxMessage.msgDes.dk::runtime::core::MsgDeserializer.<<constructor>>.MsgDeserializer(const dk::runtime::core::mid_t,uint8_t,uint8_t,const uint8_t*,uint32_t).<<call>>:0
TEST.FLOW
  dk_runtime_component.cpp.(cl)dk::runtime::core::Component::onRxMessage
  uut_prototype_stubs.std::mutex::lock
  uut_prototype_stubs.std::mutex::unlock
  dk_runtime_component.cpp.(cl)dk::runtime::core::Component::onRxMessage
TEST.END_FLOW
TEST.VALUE_USER_CODE:<<dk::runtime::core::Component instance>>.dk::runtime::core::Component.mMsgMap
class test {
   public:
      test(){}
      static void dummy (dk::runtime::core::MsgDeserializer &t) {}
};
static dk::runtime::core::MsgCmn tempMsg = {1, test::dummy};
static std::map<dk::runtime::core::mid_t, dk::runtime::core::func_t> temp;
temp[tempMsg.msgId] = tempMsg.func;
<<dk::runtime::core::Component instance>>->mMsgMap = ( &temp );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::runtime::core::Component::onStart

-- Test Case: 01_OnStart_failed
TEST.UNIT:dk_runtime_component
TEST.SUBPROGRAM:(cl)dk::runtime::core::Component::onStart
TEST.NEW
TEST.NAME:01_OnStart_failed
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.<<constructor>>.Component(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*,const char*).<<call>>:0
TEST.EXPECTED:dk_runtime_component.(cl)dk::runtime::core::Component::onStart.return:false
TEST.END

-- Test Case: 02_OnStart_failed_running_process
TEST.UNIT:dk_runtime_component
TEST.SUBPROGRAM:(cl)dk::runtime::core::Component::onStart
TEST.NEW
TEST.NAME:02_OnStart_failed_running_process
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.<<constructor>>.Component(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*,const char*).<<call>>:0
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.mIsStarted:true
TEST.EXPECTED:dk_runtime_component.(cl)dk::runtime::core::Component::onStart.return:false
TEST.END

-- Test Case: 03_OnStart_success
TEST.UNIT:dk_runtime_component
TEST.SUBPROGRAM:(cl)dk::runtime::core::Component::onStart
TEST.NEW
TEST.NAME:03_OnStart_success
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.<<constructor>>.Component(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*,const char*).<<call>>:0
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.mvTasks:<<malloc 1>>
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.mvTasks[0]:<<function 1>>
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.mIsStarted:false
TEST.EXPECTED:dk_runtime_component.(cl)dk::runtime::core::Component::onStart.return:true
TEST.END

-- Subprogram: (cl)dk::runtime::core::Component::onStop

-- Test Case: 01_OnStop_failed
TEST.UNIT:dk_runtime_component
TEST.SUBPROGRAM:(cl)dk::runtime::core::Component::onStop
TEST.NEW
TEST.NAME:01_OnStop_failed
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.<<constructor>>.Component(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*,const char*).<<call>>:0
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.mIsStarted:false
TEST.EXPECTED:dk_runtime_component.(cl)dk::runtime::core::Component::onStop.return:false
TEST.END

-- Test Case: 02_OnStop_success
TEST.UNIT:dk_runtime_component
TEST.SUBPROGRAM:(cl)dk::runtime::core::Component::onStop
TEST.NEW
TEST.NAME:02_OnStop_success
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.<<constructor>>.Component(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*,const char*).<<call>>:0
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.mIsStarted:true
TEST.EXPECTED:dk_runtime_component.(cl)dk::runtime::core::Component::onStop.return:true
TEST.END

-- Subprogram: (cl)dk::runtime::core::Component::periodicTaskThread

-- Test Case: 01_Component_not_started
TEST.UNIT:dk_runtime_component
TEST.SUBPROGRAM:(cl)dk::runtime::core::Component::periodicTaskThread
TEST.NEW
TEST.NAME:01_Component_not_started
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.<<constructor>>.Component(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*,const char*).<<call>>:0
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.mMsgMap:<<null>>
TEST.FLOW
  dk_runtime_component.cpp.(cl)dk::runtime::core::Component::periodicTaskThread
  dk_runtime_component.cpp.(cl)dk::runtime::core::Component::periodicTaskThread
TEST.END_FLOW
TEST.END

-- Test Case: 02_Task_not_running
TEST.UNIT:dk_runtime_component
TEST.SUBPROGRAM:(cl)dk::runtime::core::Component::periodicTaskThread
TEST.NEW
TEST.NAME:02_Task_not_running
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.STUB:dk_runtime_component.(cl)dk::runtime::core::Component::nowTimeMs
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.<<constructor>>.Component(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*,const char*).<<call>>:0
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.mvTasks:<<malloc 1>>
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.mvTasks[0].running:false
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.mvTasks[0]:<<function 1>>
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.mIsStarted:true
TEST.VALUE:dk_runtime_component.(cl)dk::runtime::core::Component::nowTimeMs.return:100
TEST.END

-- Test Case: 03_Task_running
TEST.UNIT:dk_runtime_component
TEST.SUBPROGRAM:(cl)dk::runtime::core::Component::periodicTaskThread
TEST.NEW
TEST.NAME:03_Task_running
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.STUB:dk_runtime_component.(cl)dk::runtime::core::Component::nowTimeMs
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.<<constructor>>.Component(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*,const char*).<<call>>:0
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.mvTasks:<<malloc 1>>
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.mvTasks[0].running:true
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.mvTasks[0].period:1
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.mvTasks[0].start:5
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.mvTasks[0]:<<function 1>>
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.mIsStarted:true
TEST.VALUE:dk_runtime_component.(cl)dk::runtime::core::Component::nowTimeMs.return:7
TEST.VALUE_USER_CODE:<<dk::runtime::core::Component instance>>.dk::runtime::core::Component.mvTasks.mvTasks[0].cbk
class test {
    public:
        test() {}
        static void dummy (void){
        }
};
<<dk::runtime::core::Component instance>>->mvTasks[0].cbk = ( &test::dummy );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 04_Task_running_next_period_lessthan_nowtime
TEST.UNIT:dk_runtime_component
TEST.SUBPROGRAM:(cl)dk::runtime::core::Component::periodicTaskThread
TEST.NEW
TEST.NAME:04_Task_running_next_period_lessthan_nowtime
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.STUB:dk_runtime_component.(cl)dk::runtime::core::Component::nowTimeMs
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.<<constructor>>.Component(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*,const char*).<<call>>:0
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.mvTasks:<<malloc 1>>
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.mvTasks[0].running:true
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.mvTasks[0].period:10
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.mvTasks[0].start:50
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.mvTasks[0]:<<function 1>>
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.mIsStarted:true
TEST.VALUE:dk_runtime_component.(cl)dk::runtime::core::Component::nowTimeMs.return:80
TEST.VALUE_USER_CODE:<<dk::runtime::core::Component instance>>.dk::runtime::core::Component.mvTasks.mvTasks[0].cbk
class test {
    public:
        test() {}
        static void dummy (void){
        }
};
<<dk::runtime::core::Component instance>>->mvTasks[0].cbk = ( &test::dummy );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 05_Task_with_long_period
TEST.UNIT:dk_runtime_component
TEST.SUBPROGRAM:(cl)dk::runtime::core::Component::periodicTaskThread
TEST.NEW
TEST.NAME:05_Task_with_long_period
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.STUB:dk_runtime_component.(cl)dk::runtime::core::Component::nowTimeMs
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.<<constructor>>.Component(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*,const char*).<<call>>:0
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.mvTasks:<<malloc 1>>
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.mvTasks[0].running:true
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.mvTasks[0].period:1000
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.mvTasks[0].start:50
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.mvTasks[0]:<<function 1>>
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.mIsStarted:true
TEST.VALUE:dk_runtime_component.(cl)dk::runtime::core::Component::nowTimeMs.return:40
TEST.VALUE_USER_CODE:<<dk::runtime::core::Component instance>>.dk::runtime::core::Component.mvTasks.mvTasks[0].cbk
class test {
    public:
        test() {}
        static void dummy (void){
        }
};
<<dk::runtime::core::Component instance>>->mvTasks[0].cbk = ( &test::dummy );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::runtime::core::Component::registerTask

-- Test Case: 01_RegisterTask_failed
TEST.UNIT:dk_runtime_component
TEST.SUBPROGRAM:(cl)dk::runtime::core::Component::registerTask
TEST.NEW
TEST.NAME:01_RegisterTask_failed
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.<<constructor>>.Component(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*,const char*).<<call>>:0
TEST.EXPECTED:dk_runtime_component.(cl)dk::runtime::core::Component::registerTask.return:-1
TEST.END

-- Test Case: 02_Non_zero_period_failed
TEST.UNIT:dk_runtime_component
TEST.SUBPROGRAM:(cl)dk::runtime::core::Component::registerTask
TEST.NEW
TEST.NAME:02_Non_zero_period_failed
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.<<constructor>>.Component(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*,const char*).<<call>>:0
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.mIsStarted:true
TEST.VALUE:dk_runtime_component.(cl)dk::runtime::core::Component::registerTask.periodMs:1
TEST.EXPECTED:dk_runtime_component.(cl)dk::runtime::core::Component::registerTask.return:-1
TEST.END

-- Test Case: 03_Task_size_exceeded
TEST.UNIT:dk_runtime_component
TEST.SUBPROGRAM:(cl)dk::runtime::core::Component::registerTask
TEST.NEW
TEST.NAME:03_Task_size_exceeded
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.<<constructor>>.Component(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*,const char*).<<call>>:0
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.mvTasks:<<malloc 10>>
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.mvTasks[0]:<<function 1>>
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.mvTasks[1]:<<function 1>>
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.mvTasks[2]:<<function 1>>
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.mvTasks[3]:<<function 1>>
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.mvTasks[4]:<<function 1>>
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.mvTasks[5]:<<function 1>>
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.mvTasks[6]:<<function 1>>
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.mvTasks[7]:<<function 1>>
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.mvTasks[8]:<<function 1>>
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.mvTasks[9]:<<function 1>>
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.mIsStarted:false
TEST.VALUE:dk_runtime_component.(cl)dk::runtime::core::Component::registerTask.periodMs:1
TEST.EXPECTED:dk_runtime_component.(cl)dk::runtime::core::Component::registerTask.return:-1
TEST.END

-- Test Case: 04_RegisterTask_success
TEST.UNIT:dk_runtime_component
TEST.SUBPROGRAM:(cl)dk::runtime::core::Component::registerTask
TEST.NEW
TEST.NAME:04_RegisterTask_success
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.<<constructor>>.Component(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*,const char*).<<call>>:0
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.mvTasks:<<malloc 1>>
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.mvTasks[0].running:true
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.mvTasks[0].period:10
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.mvTasks[0].start:20
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.mvTasks[0]:<<function 1>>
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.mIsStarted:false
TEST.VALUE:dk_runtime_component.(cl)dk::runtime::core::Component::registerTask.periodMs:1
TEST.EXPECTED:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.mvTasks[0].running:true
TEST.EXPECTED:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.mvTasks[0].period:10
TEST.EXPECTED:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.mvTasks[0].start:20
TEST.EXPECTED:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.mIsStarted:false
TEST.EXPECTED:dk_runtime_component.(cl)dk::runtime::core::Component::registerTask.periodMs:1
TEST.VALUE_USER_CODE:<<dk::runtime::core::Component instance>>.dk::runtime::core::Component.mvTasks.mvTasks[0].cbk
class test {
    public:
        test() {}
        static void dummy (void){
        }
};
<<dk::runtime::core::Component instance>>->mvTasks[0].cbk = ( test::dummy );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:dk_runtime_component.(cl)dk::runtime::core::Component::registerTask.taskCbk
static dk::runtime::core::Component::TaskCallback_t temp_var = dk::runtime::core::test::dummy;
<<dk_runtime_component.(cl)dk::runtime::core::Component::registerTask.taskCbk>> = ( &temp_var );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::runtime::core::Component::startTask

-- Test Case: 01_StartTask_failed
TEST.UNIT:dk_runtime_component
TEST.SUBPROGRAM:(cl)dk::runtime::core::Component::startTask
TEST.NEW
TEST.NAME:01_StartTask_failed
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.<<constructor>>.Component(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*,const char*).<<call>>:0
TEST.EXPECTED:dk_runtime_component.(cl)dk::runtime::core::Component::startTask.return:false
TEST.END

-- Test Case: 02_StartTask_success
TEST.UNIT:dk_runtime_component
TEST.SUBPROGRAM:(cl)dk::runtime::core::Component::startTask
TEST.NEW
TEST.NAME:02_StartTask_success
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.<<constructor>>.Component(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*,const char*).<<call>>:0
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.mvTasks:<<malloc 1>>
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.mvTasks[0]:<<function 1>>
TEST.VALUE:dk_runtime_component.(cl)dk::runtime::core::Component::startTask.taskId:0
TEST.EXPECTED:dk_runtime_component.(cl)dk::runtime::core::Component::startTask.return:true
TEST.END

-- Subprogram: (cl)dk::runtime::core::Component::stopTask

-- Test Case: 01_StopTask_failed
TEST.UNIT:dk_runtime_component
TEST.SUBPROGRAM:(cl)dk::runtime::core::Component::stopTask
TEST.NEW
TEST.NAME:01_StopTask_failed
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.<<constructor>>.Component(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*,const char*).<<call>>:0
TEST.EXPECTED:dk_runtime_component.(cl)dk::runtime::core::Component::stopTask.return:false
TEST.END

-- Test Case: 02_StopTask_success
TEST.UNIT:dk_runtime_component
TEST.SUBPROGRAM:(cl)dk::runtime::core::Component::stopTask
TEST.NEW
TEST.NAME:02_StopTask_success
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.<<constructor>>.Component(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*,const char*).<<call>>:0
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.mvTasks:<<malloc 1>>
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.mvTasks[0]:<<function 1>>
TEST.VALUE:dk_runtime_component.(cl)dk::runtime::core::Component::stopTask.taskId:0
TEST.EXPECTED:dk_runtime_component.(cl)dk::runtime::core::Component::stopTask.return:true
TEST.END

-- Subprogram: (cl)dk::runtime::core::Component::~Component

-- Test Case: 01_DeInitialization
TEST.UNIT:dk_runtime_component
TEST.SUBPROGRAM:(cl)dk::runtime::core::Component::~Component
TEST.NEW
TEST.NAME:01_DeInitialization
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_component.<<GLOBAL>>.(cl).dk::runtime::core::Component.dk::runtime::core::Component.<<constructor>>.Component(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*,const char*).<<call>>:0
TEST.FLOW
  dk_runtime_component.cpp.(cl)dk::runtime::core::Component::~Component
  dk_runtime_component.cpp.(cl)dk::runtime::core::Component::~Component
TEST.END_FLOW
TEST.END
