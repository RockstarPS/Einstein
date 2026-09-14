-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : RUNTIME_IPCMSGIF_UT
-- Unit(s) Under Test: dk_runtime_ipcmsgif
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

-- Unit: dk_runtime_ipcmsgif

-- Subprogram: (cl)dk::runtime::core::IpcMsgIf::IpcMsgIf

-- Test Case: 01_Initialization
TEST.UNIT:dk_runtime_ipcmsgif
TEST.SUBPROGRAM:(cl)dk::runtime::core::IpcMsgIf::IpcMsgIf
TEST.NEW
TEST.NAME:01_Initialization
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.FLOW
  dk_runtime_ipcmsgif.cpp.(cl)dk::runtime::core::IpcMsgIf::IpcMsgIf
  dk_runtime_ipcmsgif.cpp.(cl)dk::runtime::core::IpcMsgIf::IpcMsgIf
TEST.END_FLOW
TEST.END

-- Subprogram: (cl)dk::runtime::core::IpcMsgIf::connect

-- Test Case: 01_Connect_successful
TEST.UNIT:dk_runtime_ipcmsgif
TEST.SUBPROGRAM:(cl)dk::runtime::core::IpcMsgIf::connect
TEST.NEW
TEST.NAME:01_Connect_successful
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_ipcmsgif.<<GLOBAL>>.(cl).dk::runtime::core::IpcMsgIf.dk::runtime::core::IpcMsgIf.<<constructor>>.IpcMsgIf().<<call>>:0
TEST.EXPECTED:dk_runtime_ipcmsgif.(cl)dk::runtime::core::IpcMsgIf::connect.return:true
TEST.END

-- Test Case: 02_Retry_once
TEST.UNIT:dk_runtime_ipcmsgif
TEST.SUBPROGRAM:(cl)dk::runtime::core::IpcMsgIf::connect
TEST.NEW
TEST.NAME:02_Retry_once
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_ipcmsgif.<<GLOBAL>>.(cl).dk::runtime::core::IpcMsgIf.dk::runtime::core::IpcMsgIf.<<constructor>>.IpcMsgIf().<<call>>:0
TEST.VALUE:uut_prototype_stubs.nw_vmf_connect.return:-1,0
TEST.EXPECTED:dk_runtime_ipcmsgif.(cl)dk::runtime::core::IpcMsgIf::connect.return:true
TEST.END

-- Test Case: 03_Retry_limit_reached
TEST.UNIT:dk_runtime_ipcmsgif
TEST.SUBPROGRAM:(cl)dk::runtime::core::IpcMsgIf::connect
TEST.NEW
TEST.NAME:03_Retry_limit_reached
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_ipcmsgif.<<GLOBAL>>.(cl).dk::runtime::core::IpcMsgIf.dk::runtime::core::IpcMsgIf.<<constructor>>.IpcMsgIf().<<call>>:0
TEST.VALUE:uut_prototype_stubs.nw_vmf_connect.return:-1
TEST.EXPECTED:dk_runtime_ipcmsgif.(cl)dk::runtime::core::IpcMsgIf::connect.return:false
TEST.END

-- Subprogram: (cl)dk::runtime::core::IpcMsgIf::disconnect

-- Test Case: 01_Disconnect_successful
TEST.UNIT:dk_runtime_ipcmsgif
TEST.SUBPROGRAM:(cl)dk::runtime::core::IpcMsgIf::disconnect
TEST.NEW
TEST.NAME:01_Disconnect_successful
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_ipcmsgif.<<GLOBAL>>.(cl).dk::runtime::core::IpcMsgIf.dk::runtime::core::IpcMsgIf.<<constructor>>.IpcMsgIf().<<call>>:0
TEST.FLOW
  dk_runtime_ipcmsgif.cpp.(cl)dk::runtime::core::IpcMsgIf::disconnect
  uut_prototype_stubs.nw_vmf_disconnect
  dk_runtime_ipcmsgif.cpp.(cl)dk::runtime::core::IpcMsgIf::disconnect
TEST.END_FLOW
TEST.END

-- Test Case: 02_Disconnect_failed
TEST.UNIT:dk_runtime_ipcmsgif
TEST.SUBPROGRAM:(cl)dk::runtime::core::IpcMsgIf::disconnect
TEST.NEW
TEST.NAME:02_Disconnect_failed
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_ipcmsgif.<<GLOBAL>>.(cl).dk::runtime::core::IpcMsgIf.dk::runtime::core::IpcMsgIf.<<constructor>>.IpcMsgIf().<<call>>:0
TEST.VALUE:dk_runtime_ipcmsgif.<<GLOBAL>>.(cl).dk::runtime::core::IpcMsgIf.dk::runtime::core::IpcMsgIf.mVmfClientId:-1
TEST.FLOW
  dk_runtime_ipcmsgif.cpp.(cl)dk::runtime::core::IpcMsgIf::disconnect
  dk_runtime_ipcmsgif.cpp.(cl)dk::runtime::core::IpcMsgIf::disconnect
TEST.END_FLOW
TEST.END

-- Subprogram: (cl)dk::runtime::core::IpcMsgIf::getMaxPayloadSize

-- Test Case: 01_Get_max_payload_size
TEST.UNIT:dk_runtime_ipcmsgif
TEST.SUBPROGRAM:(cl)dk::runtime::core::IpcMsgIf::getMaxPayloadSize
TEST.NEW
TEST.NAME:01_Get_max_payload_size
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_ipcmsgif.<<GLOBAL>>.(cl).dk::runtime::core::IpcMsgIf.dk::runtime::core::IpcMsgIf.<<constructor>>.IpcMsgIf().<<call>>:0
TEST.FLOW
  dk_runtime_ipcmsgif.cpp.(cl)dk::runtime::core::IpcMsgIf::getMaxPayloadSize
  dk_runtime_ipcmsgif.cpp.(cl)dk::runtime::core::IpcMsgIf::getMaxPayloadSize
TEST.END_FLOW
TEST.END

-- Subprogram: (cl)dk::runtime::core::IpcMsgIf::receive

-- Test Case: 01_Receive_failed
TEST.UNIT:dk_runtime_ipcmsgif
TEST.SUBPROGRAM:(cl)dk::runtime::core::IpcMsgIf::receive
TEST.NEW
TEST.NAME:01_Receive_failed
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_ipcmsgif.<<GLOBAL>>.(cl).dk::runtime::core::IpcMsgIf.dk::runtime::core::IpcMsgIf.<<constructor>>.IpcMsgIf().<<call>>:0
TEST.FLOW
  dk_runtime_ipcmsgif.cpp.(cl)dk::runtime::core::IpcMsgIf::receive
  uut_prototype_stubs.nw_vmf_timed_receive
  dk_runtime_ipcmsgif.cpp.(cl)dk::runtime::core::IpcMsgIf::receive
TEST.END_FLOW
TEST.END

-- Test Case: 02_Invalid_client
TEST.UNIT:dk_runtime_ipcmsgif
TEST.SUBPROGRAM:(cl)dk::runtime::core::IpcMsgIf::receive
TEST.NEW
TEST.NAME:02_Invalid_client
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_ipcmsgif.<<GLOBAL>>.(cl).dk::runtime::core::IpcMsgIf.dk::runtime::core::IpcMsgIf.<<constructor>>.IpcMsgIf().<<call>>:0
TEST.VALUE:dk_runtime_ipcmsgif.<<GLOBAL>>.(cl).dk::runtime::core::IpcMsgIf.dk::runtime::core::IpcMsgIf.mVmfClientId:-1
TEST.FLOW
  dk_runtime_ipcmsgif.cpp.(cl)dk::runtime::core::IpcMsgIf::receive
  dk_runtime_ipcmsgif.cpp.(cl)dk::runtime::core::IpcMsgIf::receive
TEST.END_FLOW
TEST.END

-- Test Case: 03_Receive_successful
TEST.UNIT:dk_runtime_ipcmsgif
TEST.SUBPROGRAM:(cl)dk::runtime::core::IpcMsgIf::receive
TEST.NEW
TEST.NAME:03_Receive_successful
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_ipcmsgif.<<GLOBAL>>.(cl).dk::runtime::core::IpcMsgIf.dk::runtime::core::IpcMsgIf.<<constructor>>.IpcMsgIf().<<call>>:0
TEST.VALUE:uut_prototype_stubs.nw_vmf_timed_receive.return:1
TEST.FLOW
  dk_runtime_ipcmsgif.cpp.(cl)dk::runtime::core::IpcMsgIf::receive
  uut_prototype_stubs.nw_vmf_timed_receive
  dk_runtime_ipcmsgif.cpp.(cl)dk::runtime::core::IpcMsgIf::receive
TEST.END_FLOW
TEST.STUB_EXP_USER_CODE:uut_prototype_stubs.nw_vmf_timed_receive.p_vmf_msg
#include <string.h>

static VMF_VAR_BASIC_MSG_TYP ( DK_MSG_MAX_PAYLOAD_LEN ) vmfMsg;
strcpy ((char *)vmfMsg.data.pl, "Test");
vmfMsg.data.pl[4] = '\0';
vmfMsg.data.length = 4;
<<uut_prototype_stubs.nw_vmf_timed_receive.p_vmf_msg>> = ( (vmf_msg_t*)&vmfMsg );
TEST.END_STUB_EXP_USER_CODE:
TEST.VALUE_USER_CODE:dk_runtime_ipcmsgif.(cl)dk::runtime::core::IpcMsgIf::receive.pPayload
static unsigned char array[100];
<<dk_runtime_ipcmsgif.(cl)dk::runtime::core::IpcMsgIf::receive.pPayload>> = ( array );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 04_Receive_successful_smaller_payload
TEST.UNIT:dk_runtime_ipcmsgif
TEST.SUBPROGRAM:(cl)dk::runtime::core::IpcMsgIf::receive
TEST.NEW
TEST.NAME:04_Receive_successful_smaller_payload
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_ipcmsgif.<<GLOBAL>>.(cl).dk::runtime::core::IpcMsgIf.dk::runtime::core::IpcMsgIf.<<constructor>>.IpcMsgIf().<<call>>:0
TEST.VALUE:uut_prototype_stubs.nw_vmf_timed_receive.p_vmf_msg[0].VCAST_ANONYMOUS_FIELD_1.vmf_basic_msg.data.length:5
TEST.VALUE:uut_prototype_stubs.nw_vmf_timed_receive.p_vmf_msg[0].VCAST_ANONYMOUS_FIELD_1.vmf_basic_msg.data.pl:<<malloc 5>>
TEST.VALUE:uut_prototype_stubs.nw_vmf_timed_receive.p_vmf_msg[0].VCAST_ANONYMOUS_FIELD_1.vmf_basic_msg.data.pl:"Test"
TEST.VALUE:uut_prototype_stubs.nw_vmf_timed_receive.return:1
TEST.FLOW
  dk_runtime_ipcmsgif.cpp.(cl)dk::runtime::core::IpcMsgIf::receive
  uut_prototype_stubs.nw_vmf_timed_receive
  dk_runtime_ipcmsgif.cpp.(cl)dk::runtime::core::IpcMsgIf::receive
TEST.END_FLOW
TEST.VALUE_USER_CODE:dk_runtime_ipcmsgif.(cl)dk::runtime::core::IpcMsgIf::receive.pPayload
static unsigned char array[100];
<<dk_runtime_ipcmsgif.(cl)dk::runtime::core::IpcMsgIf::receive.pPayload>> = ( array );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::runtime::core::IpcMsgIf::send

-- Test Case: 01_Send_successful
TEST.UNIT:dk_runtime_ipcmsgif
TEST.SUBPROGRAM:(cl)dk::runtime::core::IpcMsgIf::send
TEST.NEW
TEST.NAME:01_Send_successful
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_ipcmsgif.<<GLOBAL>>.(cl).dk::runtime::core::IpcMsgIf.dk::runtime::core::IpcMsgIf.<<constructor>>.IpcMsgIf().<<call>>:0
TEST.FLOW
  dk_runtime_ipcmsgif.cpp.(cl)dk::runtime::core::IpcMsgIf::send
  uut_prototype_stubs.nw_vmf_send_basic
  dk_runtime_ipcmsgif.cpp.(cl)dk::runtime::core::IpcMsgIf::send
TEST.END_FLOW
TEST.END

-- Test Case: 02_Send_failed
TEST.UNIT:dk_runtime_ipcmsgif
TEST.SUBPROGRAM:(cl)dk::runtime::core::IpcMsgIf::send
TEST.NEW
TEST.NAME:02_Send_failed
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_ipcmsgif.<<GLOBAL>>.(cl).dk::runtime::core::IpcMsgIf.dk::runtime::core::IpcMsgIf.<<constructor>>.IpcMsgIf().<<call>>:0
TEST.VALUE:uut_prototype_stubs.nw_vmf_send_basic.return:-1
TEST.FLOW
  dk_runtime_ipcmsgif.cpp.(cl)dk::runtime::core::IpcMsgIf::send
  uut_prototype_stubs.nw_vmf_send_basic
  dk_runtime_ipcmsgif.cpp.(cl)dk::runtime::core::IpcMsgIf::send
TEST.END_FLOW
TEST.END

-- Test Case: 03_Invalid_client
TEST.UNIT:dk_runtime_ipcmsgif
TEST.SUBPROGRAM:(cl)dk::runtime::core::IpcMsgIf::send
TEST.NEW
TEST.NAME:03_Invalid_client
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_ipcmsgif.<<GLOBAL>>.(cl).dk::runtime::core::IpcMsgIf.dk::runtime::core::IpcMsgIf.<<constructor>>.IpcMsgIf().<<call>>:0
TEST.VALUE:dk_runtime_ipcmsgif.<<GLOBAL>>.(cl).dk::runtime::core::IpcMsgIf.dk::runtime::core::IpcMsgIf.mVmfClientId:-1
TEST.FLOW
  dk_runtime_ipcmsgif.cpp.(cl)dk::runtime::core::IpcMsgIf::send
  dk_runtime_ipcmsgif.cpp.(cl)dk::runtime::core::IpcMsgIf::send
TEST.END_FLOW
TEST.END

-- Subprogram: (cl)dk::runtime::core::IpcMsgIf::subscribe

-- Test Case: 01_Subscription_successful
TEST.UNIT:dk_runtime_ipcmsgif
TEST.SUBPROGRAM:(cl)dk::runtime::core::IpcMsgIf::subscribe
TEST.NEW
TEST.NAME:01_Subscription_successful
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_ipcmsgif.<<GLOBAL>>.(cl).dk::runtime::core::IpcMsgIf.dk::runtime::core::IpcMsgIf.<<constructor>>.IpcMsgIf().<<call>>:0
TEST.FLOW
  dk_runtime_ipcmsgif.cpp.(cl)dk::runtime::core::IpcMsgIf::subscribe
  uut_prototype_stubs.nw_vmf_register_msg_group
  dk_runtime_ipcmsgif.cpp.(cl)dk::runtime::core::IpcMsgIf::subscribe
TEST.END_FLOW
TEST.END

-- Test Case: 02_Subscription_failed
TEST.UNIT:dk_runtime_ipcmsgif
TEST.SUBPROGRAM:(cl)dk::runtime::core::IpcMsgIf::subscribe
TEST.NEW
TEST.NAME:02_Subscription_failed
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_ipcmsgif.<<GLOBAL>>.(cl).dk::runtime::core::IpcMsgIf.dk::runtime::core::IpcMsgIf.<<constructor>>.IpcMsgIf().<<call>>:0
TEST.VALUE:uut_prototype_stubs.nw_vmf_register_msg_group.return:-1
TEST.FLOW
  dk_runtime_ipcmsgif.cpp.(cl)dk::runtime::core::IpcMsgIf::subscribe
  uut_prototype_stubs.nw_vmf_register_msg_group
  dk_runtime_ipcmsgif.cpp.(cl)dk::runtime::core::IpcMsgIf::subscribe
TEST.END_FLOW
TEST.END

-- Test Case: 03_Invalid_client
TEST.UNIT:dk_runtime_ipcmsgif
TEST.SUBPROGRAM:(cl)dk::runtime::core::IpcMsgIf::subscribe
TEST.NEW
TEST.NAME:03_Invalid_client
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_ipcmsgif.<<GLOBAL>>.(cl).dk::runtime::core::IpcMsgIf.dk::runtime::core::IpcMsgIf.<<constructor>>.IpcMsgIf().<<call>>:0
TEST.VALUE:dk_runtime_ipcmsgif.<<GLOBAL>>.(cl).dk::runtime::core::IpcMsgIf.dk::runtime::core::IpcMsgIf.mVmfClientId:-1
TEST.FLOW
  dk_runtime_ipcmsgif.cpp.(cl)dk::runtime::core::IpcMsgIf::subscribe
  dk_runtime_ipcmsgif.cpp.(cl)dk::runtime::core::IpcMsgIf::subscribe
TEST.END_FLOW
TEST.END

-- Subprogram: (cl)dk::runtime::core::IpcMsgIf::~IpcMsgIf

-- Test Case: 01_DeInitialization
TEST.UNIT:dk_runtime_ipcmsgif
TEST.SUBPROGRAM:(cl)dk::runtime::core::IpcMsgIf::~IpcMsgIf
TEST.NEW
TEST.NAME:01_DeInitialization
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_ipcmsgif.<<GLOBAL>>.(cl).dk::runtime::core::IpcMsgIf.dk::runtime::core::IpcMsgIf.<<constructor>>.IpcMsgIf().<<call>>:0
TEST.FLOW
  dk_runtime_ipcmsgif.cpp.(cl)dk::runtime::core::IpcMsgIf::~IpcMsgIf
  dk_runtime_ipcmsgif.cpp.(cl)dk::runtime::core::IpcMsgIf::~IpcMsgIf
TEST.END_FLOW
TEST.END
