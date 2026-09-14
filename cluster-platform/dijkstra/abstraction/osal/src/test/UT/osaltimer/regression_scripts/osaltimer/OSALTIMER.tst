-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : OSALTIMER
-- Unit(s) Under Test: DKOsalTimer
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

-- Unit: DKOsalTimer

-- Subprogram: (cl)dk::osal::Timer::Timer

-- Test Case: construct
TEST.UNIT:DKOsalTimer
TEST.SUBPROGRAM:(cl)dk::osal::Timer::Timer
TEST.NEW
TEST.NAME:construct
TEST.VALUE:DKOsalTimer.(cl)dk::osal::Timer::Timer.timerListener.dk::osal::vcast_concrete_ITimerListener.<<constructor>>.vcast_concrete_ITimerListener().<<call>>:0
TEST.EXPECTED_USER_CODE:DKOsalTimer.(cl)dk::osal::Timer::Timer.timerListener
{{ <<DKOsalTimer.(cl)dk::osal::Timer::Timer.timerListener>> != ( nullptr ) }}
TEST.END_EXPECTED_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::osal::Timer::actOnTimerExpired

-- Test Case: actOnTimerExpired
TEST.UNIT:DKOsalTimer
TEST.SUBPROGRAM:(cl)dk::osal::Timer::actOnTimerExpired
TEST.NEW
TEST.NAME:actOnTimerExpired
TEST.VALUE:DKOsalTimer.<<GLOBAL>>.(cl).dk::osal::Timer.dk::osal::Timer.<<constructor>>.Timer(dk::osal::ITimerListener&).timerListener.dk::osal::vcast_concrete_ITimerListener.<<constructor>>.vcast_concrete_ITimerListener().<<call>>:0
TEST.VALUE:DKOsalTimer.<<GLOBAL>>.(cl).dk::osal::Timer.dk::osal::Timer.<<constructor>>.Timer(dk::osal::ITimerListener&).<<call>>:0
TEST.VALUE_USER_CODE:<<dk::osal::Timer instance>>.dk::osal::Timer.listener
<<dk::osal::Timer instance>>->listener.onTimeout(*<<dk::osal::Timer instance>>);
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::osal::Timer::getTimeout

-- Test Case: getTimeout
TEST.UNIT:DKOsalTimer
TEST.SUBPROGRAM:(cl)dk::osal::Timer::getTimeout
TEST.NEW
TEST.NAME:getTimeout
TEST.VALUE:DKOsalTimer.<<GLOBAL>>.(cl).dk::osal::Timer.dk::osal::Timer.<<constructor>>.Timer(dk::osal::ITimerListener&).<<call>>:0
TEST.VALUE:DKOsalTimer.<<GLOBAL>>.(cl).dk::osal::Timer.dk::osal::Timer.initialTimeout:4
TEST.EXPECTED:DKOsalTimer.(cl)dk::osal::Timer::getTimeout.return:4
TEST.END

-- Subprogram: (cl)dk::osal::Timer::getTimerInterval

-- Test Case: getTimerinterval
TEST.UNIT:DKOsalTimer
TEST.SUBPROGRAM:(cl)dk::osal::Timer::getTimerInterval
TEST.NEW
TEST.NAME:getTimerinterval
TEST.VALUE:DKOsalTimer.<<GLOBAL>>.(cl).dk::osal::Timer.dk::osal::Timer.<<constructor>>.Timer(dk::osal::ITimerListener&).<<call>>:0
TEST.VALUE:DKOsalTimer.<<GLOBAL>>.(cl).dk::osal::Timer.dk::osal::Timer.timerInterval:6
TEST.EXPECTED:DKOsalTimer.(cl)dk::osal::Timer::getTimerInterval.return:6
TEST.END

-- Subprogram: (cl)dk::osal::Timer::start(const uint32_t)

-- Test Case: start
TEST.UNIT:DKOsalTimer
TEST.SUBPROGRAM:(cl)dk::osal::Timer::start(const uint32_t)
TEST.NEW
TEST.NAME:start
TEST.STUB:DKOsalTimer.(cl)dk::osal::Timer::start(const uint32_t,const uint32_t)
TEST.VALUE:DKOsalTimer.<<GLOBAL>>.(cl).dk::osal::Timer.dk::osal::Timer.<<constructor>>.Timer(dk::osal::ITimerListener&).<<call>>:0
TEST.VALUE:DKOsalTimer.(cl)dk::osal::Timer::start(const uint32_t).timeoutPr:45
TEST.VALUE:uut_prototype_stubs.dk::osal::TimerMgr::getInstance.return.dk::osal::TimerMgr.<<constructor>>.TimerMgr().<<call>>:0
TEST.EXPECTED:DKOsalTimer.(cl)dk::osal::Timer::start(const uint32_t,const uint32_t).initialInterval:45
TEST.EXPECTED:DKOsalTimer.(cl)dk::osal::Timer::start(const uint32_t,const uint32_t).repetitionInterval:0
TEST.END

-- Subprogram: (cl)dk::osal::Timer::start(const uint32_t,const uint32_t)

-- Test Case: start
TEST.UNIT:DKOsalTimer
TEST.SUBPROGRAM:(cl)dk::osal::Timer::start(const uint32_t,const uint32_t)
TEST.NEW
TEST.NAME:start
TEST.VALUE:DKOsalTimer.<<GLOBAL>>.(cl).dk::osal::Timer.dk::osal::Timer.<<constructor>>.Timer(dk::osal::ITimerListener&).timerListener.dk::osal::vcast_concrete_ITimerListener.<<constructor>>.vcast_concrete_ITimerListener().<<call>>:0
TEST.VALUE:DKOsalTimer.<<GLOBAL>>.(cl).dk::osal::Timer.dk::osal::Timer.<<constructor>>.Timer(dk::osal::ITimerListener&).<<call>>:0
TEST.VALUE:uut_prototype_stubs.dk::osal::TimerMgr::getInstance.return.dk::osal::TimerMgr.<<constructor>>.TimerMgr().<<call>>:0
TEST.END

-- Subprogram: (cl)dk::osal::Timer::stop

-- Test Case: stop
TEST.UNIT:DKOsalTimer
TEST.SUBPROGRAM:(cl)dk::osal::Timer::stop
TEST.NEW
TEST.NAME:stop
TEST.VALUE:DKOsalTimer.<<GLOBAL>>.(cl).dk::osal::Timer.dk::osal::Timer.<<constructor>>.Timer(dk::osal::ITimerListener&).<<call>>:0
TEST.VALUE:DKOsalTimer.<<GLOBAL>>.(cl).dk::osal::Timer.dk::osal::Timer.timerInterval:5
TEST.VALUE:uut_prototype_stubs.dk::osal::TimerMgr::getInstance.return.dk::osal::TimerMgr.<<constructor>>.TimerMgr().<<call>>:0
TEST.VALUE_USER_CODE:<<dk::osal::Timer instance>>.dk::osal::Timer.initialTimeout
<<dk::osal::Timer instance>>->initialTimeout = ( 4 );
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_USER_CODE:<<testcase>>
{{<<dk::osal::Timer instance>>->initialTimeout == ( 0 )}};
{{<<dk::osal::Timer instance>>->timerInterval == ( 0 )}};
TEST.END_EXPECTED_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::osal::Timer::~Timer

-- Test Case: destroy
TEST.UNIT:DKOsalTimer
TEST.SUBPROGRAM:(cl)dk::osal::Timer::~Timer
TEST.NEW
TEST.NAME:destroy
TEST.VALUE:DKOsalTimer.<<GLOBAL>>.(cl).dk::osal::Timer.dk::osal::Timer.<<constructor>>.Timer(dk::osal::ITimerListener&).<<call>>:0
TEST.VALUE:uut_prototype_stubs.dk::osal::TimerMgr::getInstance.return.dk::osal::TimerMgr.<<constructor>>.TimerMgr().<<call>>:0
TEST.END
