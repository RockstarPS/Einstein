-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : UT_UCL_ADAPTOR_SOMEIP
-- Unit(s) Under Test: UclSomeIpProxy main
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

-- Unit: UclSomeIpProxy

-- Subprogram: (cl)CUclSomeIpProxy::CUclSomeIpProxy

-- Test Case: (cl)CUclSomeIpProxy::CUclSomeIpProxy.001
TEST.UNIT:UclSomeIpProxy
TEST.SUBPROGRAM:(cl)CUclSomeIpProxy::CUclSomeIpProxy
TEST.NEW
TEST.NAME:(cl)CUclSomeIpProxy::CUclSomeIpProxy.001
TEST.END

-- Subprogram: (cl)CUclSomeIpProxy::addSomeIpToTxQueue

-- Test Case: (cl)CUclSomeIpProxy::addSomeIpToTxQueue.true
TEST.UNIT:UclSomeIpProxy
TEST.SUBPROGRAM:(cl)CUclSomeIpProxy::addSomeIpToTxQueue
TEST.NEW
TEST.NAME:(cl)CUclSomeIpProxy::addSomeIpToTxQueue.true
TEST.VALUE:UclSomeIpProxy.(cl)CUclSomeIpProxy::addSomeIpToTxQueue.Size:1200
TEST.EXPECTED:UclSomeIpProxy.(cl)CUclSomeIpProxy::addSomeIpToTxQueue.return:-1
TEST.END

-- Test Case: (cl)CUclSomeIpProxy::addSomeIpToTxQueue.true.001
TEST.UNIT:UclSomeIpProxy
TEST.SUBPROGRAM:(cl)CUclSomeIpProxy::addSomeIpToTxQueue
TEST.NEW
TEST.NAME:(cl)CUclSomeIpProxy::addSomeIpToTxQueue.true.001
TEST.VALUE:UclSomeIpProxy.<<GLOBAL>>.(cl).CUclSomeIpProxy.CUclSomeIpProxy.<<constructor>>.CUclSomeIpProxy().<<call>>:0
TEST.VALUE:UclSomeIpProxy.(cl)CUclSomeIpProxy::addSomeIpToTxQueue.Size:1000
TEST.EXPECTED:UclSomeIpProxy.(cl)CUclSomeIpProxy::addSomeIpToTxQueue.return:-1
TEST.END

-- Subprogram: (cl)CUclSomeIpProxy::getInstance

-- Test Case: (cl)CUclSomeIpProxy::getInstance.001
TEST.UNIT:UclSomeIpProxy
TEST.SUBPROGRAM:(cl)CUclSomeIpProxy::getInstance
TEST.NEW
TEST.NAME:(cl)CUclSomeIpProxy::getInstance.001
TEST.VALUE:UclSomeIpProxy.<<GLOBAL>>.(cl).CUclSomeIpProxy.CUclSomeIpProxy.<<constructor>>.CUclSomeIpProxy().<<call>>:0
TEST.VALUE:UclSomeIpProxy.(cl)CUclSomeIpProxy::getInstance.return.CUclSomeIpProxy.<<constructor>>.CUclSomeIpProxy().<<call>>:0
TEST.END

-- Subprogram: (cl)CUclSomeIpProxy::stop

-- Test Case: (cl)CUclSomeIpProxy::stop.001
TEST.UNIT:UclSomeIpProxy
TEST.SUBPROGRAM:(cl)CUclSomeIpProxy::stop
TEST.NEW
TEST.NAME:(cl)CUclSomeIpProxy::stop.001
TEST.VALUE:UclSomeIpProxy.<<GLOBAL>>.(cl).CUclSomeIpProxy.CUclSomeIpProxy.<<constructor>>.CUclSomeIpProxy().<<call>>:0
TEST.VALUE:UclSomeIpProxy.(cl)CUclSomeIpProxy::stop.return:1
TEST.END

-- Subprogram: (cl)CUclSomeIpProxy::~CUclSomeIpProxy

-- Test Case: (cl)CUclSomeIpProxy::~CUclSomeIpProxy.general
TEST.UNIT:UclSomeIpProxy
TEST.SUBPROGRAM:(cl)CUclSomeIpProxy::~CUclSomeIpProxy
TEST.NEW
TEST.NAME:(cl)CUclSomeIpProxy::~CUclSomeIpProxy.general
TEST.VALUE:UclSomeIpProxy.<<GLOBAL>>.(cl).CUclSomeIpProxy.CUclSomeIpProxy.<<constructor>>.CUclSomeIpProxy().<<call>>:0
TEST.END

-- Subprogram: UclSomeIpProxy_AddSomeIpMsgToTxQueue

-- Test Case: UclSomeIpProxy_AddSomeIpMsgToTxQueue.false
TEST.UNIT:UclSomeIpProxy
TEST.SUBPROGRAM:UclSomeIpProxy_AddSomeIpMsgToTxQueue
TEST.NEW
TEST.NAME:UclSomeIpProxy_AddSomeIpMsgToTxQueue.false
TEST.STUB:UclSomeIpProxy.(cl)CUclSomeIpProxy::addSomeIpToTxQueue
TEST.VALUE:UclSomeIpProxy.<<GLOBAL>>.(cl).CUclSomeIpProxy.CUclSomeIpProxy.<<constructor>>.CUclSomeIpProxy().<<call>>:0
TEST.VALUE:UclSomeIpProxy.(cl)CUclSomeIpProxy::addSomeIpToTxQueue.return:1
TEST.EXPECTED:UclSomeIpProxy.UclSomeIpProxy_AddSomeIpMsgToTxQueue.return:0
TEST.END

-- Test Case: UclSomeIpProxy_AddSomeIpMsgToTxQueue.false.true
TEST.UNIT:UclSomeIpProxy
TEST.SUBPROGRAM:UclSomeIpProxy_AddSomeIpMsgToTxQueue
TEST.NEW
TEST.NAME:UclSomeIpProxy_AddSomeIpMsgToTxQueue.false.true
TEST.STUB:UclSomeIpProxy.(cl)CUclSomeIpProxy::addSomeIpToTxQueue
TEST.VALUE:UclSomeIpProxy.<<GLOBAL>>.(cl).CUclSomeIpProxy.CUclSomeIpProxy.<<constructor>>.CUclSomeIpProxy().<<call>>:0
TEST.VALUE:UclSomeIpProxy.(cl)CUclSomeIpProxy::addSomeIpToTxQueue.return:0
TEST.EXPECTED:UclSomeIpProxy.UclSomeIpProxy_AddSomeIpMsgToTxQueue.return:1
TEST.END

-- Unit: main

-- Subprogram: (cl)std::this_thread::sleep_for

-- Test Case: (cl)std::this_thread::sleep_for.001
TEST.UNIT:main
TEST.SUBPROGRAM:(cl)std::this_thread::sleep_for
TEST.NEW
TEST.NAME:(cl)std::this_thread::sleep_for.001
TEST.VALUE_USER_CODE:main.(cl)std::this_thread::sleep_for.__rtime
std::chrono::duration<long long int> a;
<<main.(cl)std::this_thread::sleep_for.__rtime>> = ( &a );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: VCAST_main

-- Test Case: VCAST_main.false
TEST.UNIT:main
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:VCAST_main.false
TEST.STUB:UclSomeIpProxy.(cl)CUclSomeIpProxy::start
TEST.STUB:UclSomeIpProxy.(cl)CUclSomeIpProxy::getInstance
TEST.STUB:main.exit_handler
TEST.VALUE:UclSomeIpProxy.<<GLOBAL>>.(cl).CUclSomeIpProxy.CUclSomeIpProxy.<<constructor>>.CUclSomeIpProxy().<<call>>:0
TEST.VALUE:UclSomeIpProxy.(cl)CUclSomeIpProxy::start.return:-1
TEST.VALUE:UclSomeIpProxy.(cl)CUclSomeIpProxy::getInstance.return.CUclSomeIpProxy.<<constructor>>.CUclSomeIpProxy().<<call>>:0
TEST.VALUE:main.exit_handler.s:2
TEST.END

-- Subprogram: exit_handler

-- Test Case: exit_handler.general
TEST.UNIT:main
TEST.SUBPROGRAM:exit_handler
TEST.NEW
TEST.NAME:exit_handler.general
TEST.VALUE:main.exit_handler.s:2
TEST.END
