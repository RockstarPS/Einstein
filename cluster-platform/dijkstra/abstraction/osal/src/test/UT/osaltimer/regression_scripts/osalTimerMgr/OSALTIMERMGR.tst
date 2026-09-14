-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : OSALTIMERMGR
-- Unit(s) Under Test: DKOsalTimerMgr
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

-- Subprogram: (cl)dk::osal::TimerMgr::eraseTimer

-- Test Case: erase_timer
TEST.UNIT:DKOsalTimerMgr
TEST.SUBPROGRAM:(cl)dk::osal::TimerMgr::eraseTimer
TEST.NEW
TEST.NAME:erase_timer
TEST.NOTES:
Requirement_AU29610-146983
TEST.END_NOTES:
TEST.VALUE:DKOsalTimerMgr.<<GLOBAL>>.(cl).dk::osal::TimerMgr.dk::osal::TimerMgr.<<constructor>>.TimerMgr().<<call>>:0
TEST.VALUE:DKOsalTimerMgr.<<GLOBAL>>.(cl).dk::osal::TimerMgr.dk::osal::TimerMgr.mTimerList:<<malloc 1>>
TEST.VALUE:DKOsalTimerMgr.<<GLOBAL>>.(cl).dk::osal::TimerMgr.dk::osal::TimerMgr.mTimerList[0]:<<function 1>>
TEST.END

-- Subprogram: (cl)dk::osal::TimerMgr::getInstance

-- Test Case: mutex_testflag_false
TEST.UNIT:DKOsalTimerMgr
TEST.SUBPROGRAM:(cl)dk::osal::TimerMgr::getInstance
TEST.NEW
TEST.NAME:mutex_testflag_false
TEST.NOTES:
Requirement_AU29610-146983
TEST.END_NOTES:
TEST.VALUE:DKOsalTimerMgr.<<GLOBAL>>.(cl).dk::osal::TimerMgr.dk::osal::TimerMgr.<<constructor>>.TimerMgr().<<call>>:0
TEST.VALUE:DKOsalTimerMgr.<<GLOBAL>>.(cl).dk::osal::TimerMgr.dk::osal::TimerMgr.mSetOsTimer:(2)false
TEST.VALUE_USER_CODE:DKOsalTimerMgr.(cl)dk::osal::TimerMgr::getInstance.return
<<DKOsalTimerMgr.(cl)dk::osal::TimerMgr::getInstance.return>> = ( <<dk::osal::TimerMgr instance>> );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:DKOsalTimerMgr.(cl)dk::osal::TimerMgr::getInstance.return.dk::osal::TimerMgr.mSetOsTimer
<<DKOsalTimerMgr.(cl)dk::osal::TimerMgr::getInstance.return>>->mSetOsTimer = ( false );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: mutex_testflag_true
TEST.UNIT:DKOsalTimerMgr
TEST.SUBPROGRAM:(cl)dk::osal::TimerMgr::getInstance
TEST.NEW
TEST.NAME:mutex_testflag_true
TEST.NOTES:
Requirement_AU29610-146983
TEST.END_NOTES:
TEST.VALUE:DKOsalTimerMgr.(cl)dk::osal::TimerMgr::getInstance.return.dk::osal::TimerMgr.<<constructor>>.TimerMgr().<<call>>:0
TEST.VALUE:DKOsalTimerMgr.(cl)dk::osal::TimerMgr::getInstance.return.dk::osal::TimerMgr.mTimerList:<<malloc 1>>
TEST.VALUE:DKOsalTimerMgr.(cl)dk::osal::TimerMgr::getInstance.return.dk::osal::TimerMgr.mTimerList[0].expireTime.tv_sec:4
TEST.VALUE:DKOsalTimerMgr.(cl)dk::osal::TimerMgr::getInstance.return.dk::osal::TimerMgr.mTimerList[0].expireTime.tv_nsec:400
TEST.VALUE:DKOsalTimerMgr.(cl)dk::osal::TimerMgr::getInstance.return.dk::osal::TimerMgr.mTimerList[0]:<<function 1>>
TEST.VALUE_USER_CODE:DKOsalTimerMgr.(cl)dk::osal::TimerMgr::getInstance.return.dk::osal::TimerMgr.mSetOsTimer
<<DKOsalTimerMgr.(cl)dk::osal::TimerMgr::getInstance.return>>->mSetOsTimer = ( true );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::osal::TimerMgr::insertTimer

-- Test Case: existingtimer_notexpired
TEST.UNIT:DKOsalTimerMgr
TEST.SUBPROGRAM:(cl)dk::osal::TimerMgr::insertTimer
TEST.NEW
TEST.NAME:existingtimer_notexpired
TEST.NOTES:
Requirement_AU29610-146983
TEST.END_NOTES:
TEST.VALUE:DKOsalTimerMgr.<<GLOBAL>>.(cl).dk::osal::TimerMgr.dk::osal::TimerMgr.<<constructor>>.TimerMgr().<<call>>:0
TEST.VALUE:DKOsalTimerMgr.<<GLOBAL>>.(cl).dk::osal::TimerMgr.dk::osal::TimerMgr.mTimerList:<<malloc 1>>
TEST.VALUE:DKOsalTimerMgr.<<GLOBAL>>.(cl).dk::osal::TimerMgr.dk::osal::TimerMgr.mTimerList[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.dk::osal::OsTimer::timeIsLessThan.return:true
TEST.END

-- Test Case: existingtimer_one
TEST.UNIT:DKOsalTimerMgr
TEST.SUBPROGRAM:(cl)dk::osal::TimerMgr::insertTimer
TEST.NEW
TEST.NAME:existingtimer_one
TEST.NOTES:
Requirement_AU29610-146983
TEST.END_NOTES:
TEST.VALUE:DKOsalTimerMgr.<<GLOBAL>>.(cl).dk::osal::TimerMgr.dk::osal::TimerMgr.<<constructor>>.TimerMgr().<<call>>:0
TEST.VALUE:DKOsalTimerMgr.<<GLOBAL>>.(cl).dk::osal::TimerMgr.dk::osal::TimerMgr.mTimerList:<<malloc 1>>
TEST.VALUE:DKOsalTimerMgr.<<GLOBAL>>.(cl).dk::osal::TimerMgr.dk::osal::TimerMgr.mTimerList[0]:<<function 1>>
TEST.END

-- Test Case: existingtimer_zero
TEST.UNIT:DKOsalTimerMgr
TEST.SUBPROGRAM:(cl)dk::osal::TimerMgr::insertTimer
TEST.NEW
TEST.NAME:existingtimer_zero
TEST.NOTES:
Requirement_AU29610-146983
TEST.END_NOTES:
TEST.VALUE:DKOsalTimerMgr.<<GLOBAL>>.(cl).dk::osal::TimerMgr.dk::osal::TimerMgr.<<constructor>>.TimerMgr().<<call>>:0
TEST.END

-- Subprogram: (cl)dk::osal::TimerMgr::onOsTimeout

-- Test Case: testflag_true
TEST.UNIT:DKOsalTimerMgr
TEST.SUBPROGRAM:(cl)dk::osal::TimerMgr::onOsTimeout
TEST.NEW
TEST.NAME:testflag_true
TEST.NOTES:
Requirement_AU29610-146983
TEST.END_NOTES:
TEST.VALUE:DKOsalTimerMgr.<<GLOBAL>>.(cl).dk::osal::TimerMgr.dk::osal::TimerMgr.<<constructor>>.TimerMgr().<<call>>:0
TEST.END

-- Test Case: timer_expire
TEST.UNIT:DKOsalTimerMgr
TEST.SUBPROGRAM:(cl)dk::osal::TimerMgr::onOsTimeout
TEST.NEW
TEST.NAME:timer_expire
TEST.NOTES:
Requirement_AU29610-146983
TEST.END_NOTES:
TEST.STUB:DKOsalTimerMgr.(cl)dk::osal::TimerMgr::insertTimer
TEST.STUB:uut_prototype_stubs.dk::osal::Timer::getTimerInterval
TEST.VALUE:DKOsalTimerMgr.<<GLOBAL>>.(cl).dk::osal::TimerMgr.dk::osal::TimerMgr.<<constructor>>.TimerMgr().<<call>>:0
TEST.VALUE:DKOsalTimerMgr.<<GLOBAL>>.(cl).dk::osal::TimerMgr.dk::osal::TimerMgr.mTimerList:<<malloc 1>>
TEST.VALUE:DKOsalTimerMgr.<<GLOBAL>>.(cl).dk::osal::TimerMgr.dk::osal::TimerMgr.mTimerList[0]:<<function 1>>
TEST.VALUE:DKOsalTimerMgr.<<GLOBAL>>.(cl).dk::osal::TimerMgr.dk::osal::TimerMgr.mSetOsTimer:false
TEST.VALUE:uut_prototype_stubs.dk::osal::OsTimer::calcTimeOffsetMS.timeoutMS:45
TEST.VALUE:uut_prototype_stubs.dk::osal::OsTimer::timeIsLessThan.return:false
TEST.VALUE:uut_prototype_stubs.dk::osal::Timer::getTimerInterval.return:45
TEST.END

-- Test Case: timer_expired_testflag_false
TEST.UNIT:DKOsalTimerMgr
TEST.SUBPROGRAM:(cl)dk::osal::TimerMgr::onOsTimeout
TEST.NEW
TEST.NAME:timer_expired_testflag_false
TEST.NOTES:
Requirement_AU29610-146983
TEST.END_NOTES:
TEST.VALUE:DKOsalTimerMgr.<<GLOBAL>>.(cl).dk::osal::TimerMgr.dk::osal::TimerMgr.<<constructor>>.TimerMgr().<<call>>:0
TEST.VALUE:DKOsalTimerMgr.<<GLOBAL>>.(cl).dk::osal::TimerMgr.dk::osal::TimerMgr.mTimerList:<<malloc 1>>
TEST.VALUE:DKOsalTimerMgr.<<GLOBAL>>.(cl).dk::osal::TimerMgr.dk::osal::TimerMgr.mTimerList[0]:<<function 1>>
TEST.VALUE:DKOsalTimerMgr.<<GLOBAL>>.(cl).dk::osal::TimerMgr.dk::osal::TimerMgr.mSetOsTimer:true
TEST.VALUE:uut_prototype_stubs.dk::osal::OsTimer::timeIsLessThan.return:true
TEST.END

-- Test Case: timer_interval_zero
TEST.UNIT:DKOsalTimerMgr
TEST.SUBPROGRAM:(cl)dk::osal::TimerMgr::onOsTimeout
TEST.NEW
TEST.NAME:timer_interval_zero
TEST.NOTES:
Requirement_AU29610-146983
TEST.END_NOTES:
TEST.STUB:DKOsalTimerMgr.(cl)dk::osal::TimerMgr::insertTimer
TEST.STUB:uut_prototype_stubs.dk::osal::Timer::getTimerInterval
TEST.VALUE:DKOsalTimerMgr.<<GLOBAL>>.(cl).dk::osal::TimerMgr.dk::osal::TimerMgr.<<constructor>>.TimerMgr().<<call>>:0
TEST.VALUE:DKOsalTimerMgr.<<GLOBAL>>.(cl).dk::osal::TimerMgr.dk::osal::TimerMgr.mTimerList:<<malloc 1>>
TEST.VALUE:DKOsalTimerMgr.<<GLOBAL>>.(cl).dk::osal::TimerMgr.dk::osal::TimerMgr.mTimerList[0]:<<function 1>>
TEST.VALUE:DKOsalTimerMgr.<<GLOBAL>>.(cl).dk::osal::TimerMgr.dk::osal::TimerMgr.mSetOsTimer:false
TEST.VALUE:uut_prototype_stubs.dk::osal::OsTimer::timeIsLessThan.return:false
TEST.VALUE:uut_prototype_stubs.dk::osal::Timer::getTimerInterval.return:0
TEST.END

-- Test Case: timer_notexpired
TEST.UNIT:DKOsalTimerMgr
TEST.SUBPROGRAM:(cl)dk::osal::TimerMgr::onOsTimeout
TEST.NEW
TEST.NAME:timer_notexpired
TEST.NOTES:
Requirement_AU29610-146983
TEST.END_NOTES:
TEST.VALUE:DKOsalTimerMgr.<<GLOBAL>>.(cl).dk::osal::TimerMgr.dk::osal::TimerMgr.<<constructor>>.TimerMgr().<<call>>:0
TEST.VALUE:DKOsalTimerMgr.<<GLOBAL>>.(cl).dk::osal::TimerMgr.dk::osal::TimerMgr.mTimerList:<<malloc 1>>
TEST.VALUE:DKOsalTimerMgr.<<GLOBAL>>.(cl).dk::osal::TimerMgr.dk::osal::TimerMgr.mTimerList[0]:<<function 1>>
TEST.VALUE:DKOsalTimerMgr.<<GLOBAL>>.(cl).dk::osal::TimerMgr.dk::osal::TimerMgr.mSetOsTimer:true
TEST.VALUE:uut_prototype_stubs.dk::osal::OsTimer::timeIsLessThan.return:true
TEST.END

-- Subprogram: (cl)dk::osal::TimerMgr::startTimer

-- Test Case: mSetOsTimer_false
TEST.UNIT:DKOsalTimerMgr
TEST.SUBPROGRAM:(cl)dk::osal::TimerMgr::startTimer
TEST.NEW
TEST.NAME:mSetOsTimer_false
TEST.NOTES:
Requirement_AU29610-146983
TEST.END_NOTES:
TEST.VALUE:DKOsalTimerMgr.<<GLOBAL>>.(cl).dk::osal::TimerMgr.dk::osal::TimerMgr.<<constructor>>.TimerMgr().<<call>>:0
TEST.VALUE:DKOsalTimerMgr.<<GLOBAL>>.(cl).dk::osal::TimerMgr.dk::osal::TimerMgr.mTimerList:<<malloc 1>>
TEST.VALUE:DKOsalTimerMgr.<<GLOBAL>>.(cl).dk::osal::TimerMgr.dk::osal::TimerMgr.mTimerList[0].timer.dk::osal::Timer.<<constructor>>.Timer(dk::osal::ITimerListener&).<<call>>:0
TEST.VALUE:DKOsalTimerMgr.<<GLOBAL>>.(cl).dk::osal::TimerMgr.dk::osal::TimerMgr.mTimerList[0].timer.dk::osal::Timer.initialTimeout:5
TEST.VALUE:DKOsalTimerMgr.<<GLOBAL>>.(cl).dk::osal::TimerMgr.dk::osal::TimerMgr.mTimerList[0]:<<function 1>>
TEST.VALUE:DKOsalTimerMgr.<<GLOBAL>>.(cl).dk::osal::TimerMgr.dk::osal::TimerMgr.mSetOsTimer:false
TEST.VALUE:DKOsalTimerMgr.(cl)dk::osal::TimerMgr::startTimer.timerPr.dk::osal::Timer.<<constructor>>.Timer(dk::osal::ITimerListener&).<<call>>:0
TEST.END

-- Test Case: mSetOsTimer_true
TEST.UNIT:DKOsalTimerMgr
TEST.SUBPROGRAM:(cl)dk::osal::TimerMgr::startTimer
TEST.NEW
TEST.NAME:mSetOsTimer_true
TEST.NOTES:
Requirement_AU29610-146983
TEST.END_NOTES:
TEST.VALUE:DKOsalTimerMgr.<<GLOBAL>>.(cl).dk::osal::TimerMgr.dk::osal::TimerMgr.<<constructor>>.TimerMgr().<<call>>:0
TEST.VALUE:DKOsalTimerMgr.<<GLOBAL>>.(cl).dk::osal::TimerMgr.dk::osal::TimerMgr.mSetOsTimer:true
TEST.VALUE:DKOsalTimerMgr.(cl)dk::osal::TimerMgr::startTimer.timerPr.dk::osal::Timer.<<constructor>>.Timer(dk::osal::ITimerListener&).<<call>>:0
TEST.END

-- Test Case: remove_existingtimer
TEST.UNIT:DKOsalTimerMgr
TEST.SUBPROGRAM:(cl)dk::osal::TimerMgr::startTimer
TEST.NEW
TEST.NAME:remove_existingtimer
TEST.NOTES:
Requirement_AU29610-146983
TEST.END_NOTES:
TEST.VALUE:DKOsalTimerMgr.<<GLOBAL>>.(cl).dk::osal::TimerMgr.dk::osal::TimerMgr.<<constructor>>.TimerMgr().<<call>>:0
TEST.VALUE:DKOsalTimerMgr.<<GLOBAL>>.(cl).dk::osal::TimerMgr.dk::osal::TimerMgr.mTimerList:<<malloc 1>>
TEST.VALUE:DKOsalTimerMgr.<<GLOBAL>>.(cl).dk::osal::TimerMgr.dk::osal::TimerMgr.mTimerList[0]:<<function 1>>
TEST.VALUE:DKOsalTimerMgr.(cl)dk::osal::TimerMgr::startTimer.timerPr.dk::osal::Timer.<<constructor>>.Timer(dk::osal::ITimerListener&).<<call>>:0
TEST.END

-- Test Case: remove_existingtimer_front
TEST.UNIT:DKOsalTimerMgr
TEST.SUBPROGRAM:(cl)dk::osal::TimerMgr::startTimer
TEST.NEW
TEST.NAME:remove_existingtimer_front
TEST.NOTES:
Requirement_AU29610-146983
TEST.END_NOTES:
TEST.VALUE:DKOsalTimerMgr.<<GLOBAL>>.(cl).dk::osal::TimerMgr.dk::osal::TimerMgr.<<constructor>>.TimerMgr().<<call>>:0
TEST.VALUE:DKOsalTimerMgr.<<GLOBAL>>.(cl).dk::osal::TimerMgr.dk::osal::TimerMgr.mTimerList:<<malloc 1>>
TEST.VALUE:DKOsalTimerMgr.<<GLOBAL>>.(cl).dk::osal::TimerMgr.dk::osal::TimerMgr.mTimerList[0].timer.dk::osal::Timer.<<constructor>>.Timer(dk::osal::ITimerListener&).<<call>>:0
TEST.VALUE:DKOsalTimerMgr.<<GLOBAL>>.(cl).dk::osal::TimerMgr.dk::osal::TimerMgr.mTimerList[0]:<<function 1>>
TEST.VALUE:DKOsalTimerMgr.<<GLOBAL>>.(cl).dk::osal::TimerMgr.dk::osal::TimerMgr.mSetOsTimer:true
TEST.VALUE_USER_CODE:DKOsalTimerMgr.(cl)dk::osal::TimerMgr::startTimer.timerPr
<<DKOsalTimerMgr.(cl)dk::osal::TimerMgr::startTimer.timerPr>> = ( <<dk::osal::TimerMgr instance>>->mTimerList.front().timer );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: testflag_false
TEST.UNIT:DKOsalTimerMgr
TEST.SUBPROGRAM:(cl)dk::osal::TimerMgr::startTimer
TEST.NEW
TEST.NAME:testflag_false
TEST.NOTES:
Requirement_AU29610-146983
TEST.END_NOTES:
TEST.STUB:DKOsalTimerMgr.(cl)dk::osal::TimerMgr::insertTimer
TEST.VALUE:DKOsalTimerMgr.<<GLOBAL>>.(cl).dk::osal::TimerMgr.dk::osal::TimerMgr.<<constructor>>.TimerMgr().<<call>>:0
TEST.VALUE:DKOsalTimerMgr.(cl)dk::osal::TimerMgr::startTimer.timerPr.dk::osal::Timer.<<constructor>>.Timer(dk::osal::ITimerListener&).<<call>>:0
TEST.VALUE:DKOsalTimerMgr.(cl)dk::osal::TimerMgr::insertTimer.entry.timer.dk::osal::Timer.<<constructor>>.Timer(dk::osal::ITimerListener&).<<call>>:0
TEST.END

-- Subprogram: (cl)dk::osal::TimerMgr::stopTimer

-- Test Case: mSetOsTimer_false
TEST.UNIT:DKOsalTimerMgr
TEST.SUBPROGRAM:(cl)dk::osal::TimerMgr::stopTimer
TEST.NEW
TEST.NAME:mSetOsTimer_false
TEST.NOTES:
Requirement_AU29610-146983
TEST.END_NOTES:
TEST.VALUE:DKOsalTimerMgr.<<GLOBAL>>.(cl).dk::osal::TimerMgr.dk::osal::TimerMgr.<<constructor>>.TimerMgr().<<call>>:0
TEST.VALUE:DKOsalTimerMgr.<<GLOBAL>>.(cl).dk::osal::TimerMgr.dk::osal::TimerMgr.mTimerList:<<malloc 1>>
TEST.VALUE:DKOsalTimerMgr.<<GLOBAL>>.(cl).dk::osal::TimerMgr.dk::osal::TimerMgr.mTimerList[0]:<<function 1>>
TEST.VALUE:DKOsalTimerMgr.<<GLOBAL>>.(cl).dk::osal::TimerMgr.dk::osal::TimerMgr.mSetOsTimer:false
TEST.END

-- Test Case: mSetOsTimer_true
TEST.UNIT:DKOsalTimerMgr
TEST.SUBPROGRAM:(cl)dk::osal::TimerMgr::stopTimer
TEST.NEW
TEST.NAME:mSetOsTimer_true
TEST.NOTES:
Requirement_AU29610-146983
TEST.END_NOTES:
TEST.VALUE:DKOsalTimerMgr.<<GLOBAL>>.(cl).dk::osal::TimerMgr.dk::osal::TimerMgr.<<constructor>>.TimerMgr().<<call>>:0
TEST.VALUE:DKOsalTimerMgr.<<GLOBAL>>.(cl).dk::osal::TimerMgr.dk::osal::TimerMgr.mTimerList:<<malloc 1>>
TEST.VALUE:DKOsalTimerMgr.<<GLOBAL>>.(cl).dk::osal::TimerMgr.dk::osal::TimerMgr.mTimerList[0]:<<function 1>>
TEST.VALUE:DKOsalTimerMgr.<<GLOBAL>>.(cl).dk::osal::TimerMgr.dk::osal::TimerMgr.mSetOsTimer:true
TEST.END

-- Test Case: mSetOsTimer_true_wasFirst_false
TEST.UNIT:DKOsalTimerMgr
TEST.SUBPROGRAM:(cl)dk::osal::TimerMgr::stopTimer
TEST.NEW
TEST.NAME:mSetOsTimer_true_wasFirst_false
TEST.NOTES:
Requirement_AU29610-146983
TEST.END_NOTES:
TEST.STUB:DKOsalTimerMgr.(cl)dk::osal::TimerMgr::eraseTimer
TEST.VALUE:DKOsalTimerMgr.<<GLOBAL>>.(cl).dk::osal::TimerMgr.dk::osal::TimerMgr.<<constructor>>.TimerMgr().<<call>>:0
TEST.VALUE:DKOsalTimerMgr.<<GLOBAL>>.(cl).dk::osal::TimerMgr.dk::osal::TimerMgr.mTimerList:<<malloc 1>>
TEST.VALUE:DKOsalTimerMgr.<<GLOBAL>>.(cl).dk::osal::TimerMgr.dk::osal::TimerMgr.mTimerList[0]:<<function 1>>
TEST.VALUE:DKOsalTimerMgr.<<GLOBAL>>.(cl).dk::osal::TimerMgr.dk::osal::TimerMgr.mSetOsTimer:true
TEST.VALUE:DKOsalTimerMgr.(cl)dk::osal::TimerMgr::stopTimer.timerPr.dk::osal::Timer.<<constructor>>.Timer(dk::osal::ITimerListener&).<<call>>:0
TEST.STUB_VAL_USER_CODE:DKOsalTimerMgr.(cl)dk::osal::TimerMgr::eraseTimer.timerPr
<<DKOsalTimerMgr.(cl)dk::osal::TimerMgr::eraseTimer.timerPr>> = ( <<dk::osal::TimerMgr instance>>->mTimerList.front().timer );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: mSetOsTimer_true_wasFirst_true
TEST.UNIT:DKOsalTimerMgr
TEST.SUBPROGRAM:(cl)dk::osal::TimerMgr::stopTimer
TEST.NEW
TEST.NAME:mSetOsTimer_true_wasFirst_true
TEST.NOTES:
Requirement_AU29610-146983
TEST.END_NOTES:
TEST.VALUE:DKOsalTimerMgr.<<GLOBAL>>.(cl).dk::osal::TimerMgr.dk::osal::TimerMgr.<<constructor>>.TimerMgr().<<call>>:0
TEST.VALUE:DKOsalTimerMgr.<<GLOBAL>>.(cl).dk::osal::TimerMgr.dk::osal::TimerMgr.mTimerList:<<malloc 1>>
TEST.VALUE:DKOsalTimerMgr.<<GLOBAL>>.(cl).dk::osal::TimerMgr.dk::osal::TimerMgr.mTimerList[0]:<<function 1>>
TEST.VALUE:DKOsalTimerMgr.<<GLOBAL>>.(cl).dk::osal::TimerMgr.dk::osal::TimerMgr.mSetOsTimer:true
TEST.VALUE_USER_CODE:DKOsalTimerMgr.(cl)dk::osal::TimerMgr::stopTimer.timerPr
<<DKOsalTimerMgr.(cl)dk::osal::TimerMgr::stopTimer.timerPr>> = ( <<dk::osal::TimerMgr instance>>->mTimerList.front().timer );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: mSetOsTimer_true_wasFirst_true_EmptyList
TEST.UNIT:DKOsalTimerMgr
TEST.SUBPROGRAM:(cl)dk::osal::TimerMgr::stopTimer
TEST.NEW
TEST.NAME:mSetOsTimer_true_wasFirst_true_EmptyList
TEST.NOTES:
Requirement_AU29610-146983
TEST.END_NOTES:
TEST.STUB:DKOsalTimerMgr.(cl)dk::osal::TimerMgr::eraseTimer
TEST.VALUE:DKOsalTimerMgr.<<GLOBAL>>.(cl).dk::osal::TimerMgr.dk::osal::TimerMgr.<<constructor>>.TimerMgr().<<call>>:0
TEST.VALUE:DKOsalTimerMgr.<<GLOBAL>>.(cl).dk::osal::TimerMgr.dk::osal::TimerMgr.mTimerList:<<malloc 1>>
TEST.VALUE:DKOsalTimerMgr.<<GLOBAL>>.(cl).dk::osal::TimerMgr.dk::osal::TimerMgr.mTimerList[0]:<<function 1>>
TEST.VALUE:DKOsalTimerMgr.<<GLOBAL>>.(cl).dk::osal::TimerMgr.dk::osal::TimerMgr.mSetOsTimer:true
TEST.STUB_VAL_USER_CODE:DKOsalTimerMgr.(cl)dk::osal::TimerMgr::eraseTimer.timerPr
<<DKOsalTimerMgr.(cl)dk::osal::TimerMgr::eraseTimer.timerPr>> = ( <<dk::osal::TimerMgr instance>>->mTimerList.front().timer );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:DKOsalTimerMgr.(cl)dk::osal::TimerMgr::stopTimer.timerPr
<<DKOsalTimerMgr.(cl)dk::osal::TimerMgr::stopTimer.timerPr>> = ( <<dk::osal::TimerMgr instance>>->mTimerList.front().timer );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: testflag_false
TEST.UNIT:DKOsalTimerMgr
TEST.SUBPROGRAM:(cl)dk::osal::TimerMgr::stopTimer
TEST.NEW
TEST.NAME:testflag_false
TEST.NOTES:
Requirement_AU29610-146983
TEST.END_NOTES:
TEST.VALUE:DKOsalTimerMgr.<<GLOBAL>>.(cl).dk::osal::TimerMgr.dk::osal::TimerMgr.<<constructor>>.TimerMgr().<<call>>:0
TEST.END

-- Subprogram: (cl)dk::osal::TimerMgr::~TimerMgr

-- Test Case: destroy
TEST.UNIT:DKOsalTimerMgr
TEST.SUBPROGRAM:(cl)dk::osal::TimerMgr::~TimerMgr
TEST.NEW
TEST.NAME:destroy
TEST.NOTES:
Requirement_AU29610-146983
TEST.END_NOTES:
TEST.VALUE:DKOsalTimerMgr.<<GLOBAL>>.(cl).dk::osal::TimerMgr.dk::osal::TimerMgr.<<constructor>>.TimerMgr().<<call>>:0
TEST.END
