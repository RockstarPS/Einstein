-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : OSAL_THREAD_UT
-- Unit(s) Under Test: DKOsalThread
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

-- Unit: DKOsalThread

-- Subprogram: (cl)dk::osal::Thread::cancel

-- Test Case: Inactive_thread
TEST.UNIT:DKOsalThread
TEST.SUBPROGRAM:(cl)dk::osal::Thread::cancel
TEST.NEW
TEST.NAME:Inactive_thread
TEST.NOTES:
Requirement_AU29610-146981
TEST.END_NOTES:
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.<<constructor>>.Thread(const bool).<<call>>:0
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.mActive:false
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.mResult:<<null>>
TEST.END

-- Test Case: Pthread_cancel_failed
TEST.UNIT:DKOsalThread
TEST.SUBPROGRAM:(cl)dk::osal::Thread::cancel
TEST.NEW
TEST.NAME:Pthread_cancel_failed
TEST.NOTES:
Requirement_AU29610-146981
TEST.END_NOTES:
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.<<constructor>>.Thread(dk::osal::IRunnable*,const bool).<<call>>:0
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.mActive:true
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:0
TEST.VALUE:uut_prototype_stubs.pthread_cancel.return:1
TEST.END

-- Test Case: Success
TEST.UNIT:DKOsalThread
TEST.SUBPROGRAM:(cl)dk::osal::Thread::cancel
TEST.NEW
TEST.NAME:Success
TEST.NOTES:
Requirement_AU29610-146981
TEST.END_NOTES:
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.<<constructor>>.Thread(dk::osal::IRunnable*,const bool).<<call>>:0
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.mActive:true
TEST.END

-- Subprogram: (cl)dk::osal::Thread::cleanup

-- Test Case: Cleanup
TEST.UNIT:DKOsalThread
TEST.SUBPROGRAM:(cl)dk::osal::Thread::cleanup
TEST.NEW
TEST.NAME:Cleanup
TEST.NOTES:
Requirement_AU29610-146981
TEST.END_NOTES:
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.<<constructor>>.Thread(const bool).<<call>>:0
TEST.END

-- Subprogram: (cl)dk::osal::Thread::cleanupDispatcher

-- Test Case: cleanup_the_thread
TEST.UNIT:DKOsalThread
TEST.SUBPROGRAM:(cl)dk::osal::Thread::cleanupDispatcher
TEST.NEW
TEST.NAME:cleanup_the_thread
TEST.NOTES:
Requirement_AU29610-146981
TEST.END_NOTES:
TEST.VALUE_USER_CODE:DKOsalThread.(cl)dk::osal::Thread::cleanupDispatcher.parg
class TempThread : public dk::osal::IRunnable {
    public:
        TempThread () {};
        void *run () { return NULL; };
};
TempThread *tempThread = new TempThread;

dk::osal::Thread *temp = new dk::osal::Thread(tempThread, false);

<<DKOsalThread.(cl)dk::osal::Thread::cleanupDispatcher.parg>> = ( temp );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::osal::Thread::currentProcessId

-- Test Case: Get_current_process_id
TEST.UNIT:DKOsalThread
TEST.SUBPROGRAM:(cl)dk::osal::Thread::currentProcessId
TEST.NEW
TEST.NAME:Get_current_process_id
TEST.NOTES:
Requirement_AU29610-146981
TEST.END_NOTES:
TEST.END

-- Subprogram: (cl)dk::osal::Thread::currentThreadId

-- Test Case: Get_current_thread_id
TEST.UNIT:DKOsalThread
TEST.SUBPROGRAM:(cl)dk::osal::Thread::currentThreadId
TEST.NEW
TEST.NAME:Get_current_thread_id
TEST.NOTES:
Requirement_AU29610-146981
TEST.END_NOTES:
TEST.END

-- Subprogram: (cl)dk::osal::Thread::exit

-- Test Case: Exit_the_thread
TEST.UNIT:DKOsalThread
TEST.SUBPROGRAM:(cl)dk::osal::Thread::exit
TEST.NEW
TEST.NAME:Exit_the_thread
TEST.NOTES:
Requirement_AU29610-146981
TEST.END_NOTES:
TEST.END

-- Subprogram: (cl)dk::osal::Thread::getName

-- Test Case: Get_thread_name
TEST.UNIT:DKOsalThread
TEST.SUBPROGRAM:(cl)dk::osal::Thread::getName
TEST.NEW
TEST.NAME:Get_thread_name
TEST.NOTES:
Requirement_AU29610-146981
TEST.END_NOTES:
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.<<constructor>>.Thread(const bool).<<call>>:0
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.mThreadName:<<malloc 14>>
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.mThreadName:"ThreadNameFPK"
TEST.EXPECTED:DKOsalThread.(cl)dk::osal::Thread::getName.return:"ThreadNameFPK"
TEST.END

-- Subprogram: (cl)dk::osal::Thread::isDetached

-- Test Case: Returns_attach_status
TEST.UNIT:DKOsalThread
TEST.SUBPROGRAM:(cl)dk::osal::Thread::isDetached
TEST.NEW
TEST.NAME:Returns_attach_status
TEST.NOTES:
Requirement_AU29610-146981
TEST.END_NOTES:
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.<<constructor>>.Thread(const bool).<<call>>:0
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.mDetached:true
TEST.EXPECTED:DKOsalThread.(cl)dk::osal::Thread::isDetached.return:true
TEST.END

-- Subprogram: (cl)dk::osal::Thread::isRunning

-- Test Case: Return_thread_status
TEST.UNIT:DKOsalThread
TEST.SUBPROGRAM:(cl)dk::osal::Thread::isRunning
TEST.NEW
TEST.NAME:Return_thread_status
TEST.NOTES:
Requirement_AU29610-146981
TEST.END_NOTES:
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.<<constructor>>.Thread(const bool).<<call>>:0
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.mActive:true
TEST.EXPECTED:DKOsalThread.(cl)dk::osal::Thread::isRunning.return:true
TEST.END

-- Subprogram: (cl)dk::osal::Thread::join

-- Test Case: Join_failed
TEST.UNIT:DKOsalThread
TEST.SUBPROGRAM:(cl)dk::osal::Thread::join
TEST.NEW
TEST.NAME:Join_failed
TEST.NOTES:
Requirement_AU29610-146981
TEST.END_NOTES:
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.<<constructor>>.Thread(const bool).<<call>>:0
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.mNeedsJoin:true
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:0
TEST.VALUE:uut_prototype_stubs.pthread_join.return:1
TEST.END

-- Test Case: No_join_needed
TEST.UNIT:DKOsalThread
TEST.SUBPROGRAM:(cl)dk::osal::Thread::join
TEST.NEW
TEST.NAME:No_join_needed
TEST.NOTES:
Requirement_AU29610-146981
TEST.END_NOTES:
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.<<constructor>>.Thread(const bool).<<call>>:0
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.mNeedsJoin:false
TEST.END

-- Test Case: Success
TEST.UNIT:DKOsalThread
TEST.SUBPROGRAM:(cl)dk::osal::Thread::join
TEST.NEW
TEST.NAME:Success
TEST.NOTES:
Requirement_AU29610-146981
TEST.END_NOTES:
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.<<constructor>>.Thread(const bool).<<call>>:0
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.mNeedsJoin:true
TEST.END

-- Subprogram: (cl)dk::osal::Thread::run

-- Test Case: Run_the_thread
TEST.UNIT:DKOsalThread
TEST.SUBPROGRAM:(cl)dk::osal::Thread::run
TEST.NEW
TEST.NAME:Run_the_thread
TEST.NOTES:
Requirement_AU29610-146981
TEST.END_NOTES:
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.<<constructor>>.Thread(const bool).<<call>>:0
TEST.END

-- Subprogram: (cl)dk::osal::Thread::setCompleted

-- Test Case: Set_complete
TEST.UNIT:DKOsalThread
TEST.SUBPROGRAM:(cl)dk::osal::Thread::setCompleted
TEST.NEW
TEST.NAME:Set_complete
TEST.NOTES:
Requirement_AU29610-146981
TEST.END_NOTES:
TEST.END

-- Subprogram: (cl)dk::osal::Thread::setName

-- Test Case: Set_thread_name
TEST.UNIT:DKOsalThread
TEST.SUBPROGRAM:(cl)dk::osal::Thread::setName
TEST.NEW
TEST.NAME:Set_thread_name
TEST.NOTES:
Requirement_AU29610-146981
TEST.END_NOTES:
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.<<constructor>>.Thread(const bool).<<call>>:0
TEST.END

-- Subprogram: (cl)dk::osal::Thread::sleepMS

-- Test Case: Sleep_retry_once
TEST.UNIT:DKOsalThread
TEST.SUBPROGRAM:(cl)dk::osal::Thread::sleepMS
TEST.NEW
TEST.NAME:Sleep_retry_once
TEST.NOTES:
Requirement_AU29610-146981
TEST.END_NOTES:
TEST.STUB:uut_prototype_stubs.nanosleep
TEST.VALUE:uut_prototype_stubs.nanosleep.return:-1
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.__get_errno_ptr.return
static int temp;
int ret = 4;
if (temp != 0) {
    ret = 0;
}
temp++;
<<uut_prototype_stubs.__get_errno_ptr.return>> = ( &ret );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: Success
TEST.UNIT:DKOsalThread
TEST.SUBPROGRAM:(cl)dk::osal::Thread::sleepMS
TEST.NEW
TEST.NAME:Success
TEST.NOTES:
Requirement_AU29610-146981
TEST.END_NOTES:
TEST.STUB:uut_prototype_stubs.nanosleep
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:0
TEST.VALUE:uut_prototype_stubs.nanosleep.return:0
TEST.END

-- Subprogram: (cl)dk::osal::Thread::sleepUS

-- Test Case: Sleep_retry_once
TEST.UNIT:DKOsalThread
TEST.SUBPROGRAM:(cl)dk::osal::Thread::sleepUS
TEST.NEW
TEST.NAME:Sleep_retry_once
TEST.NOTES:
Requirement_AU29610-146981
TEST.END_NOTES:
TEST.STUB:uut_prototype_stubs.nanosleep
TEST.VALUE:uut_prototype_stubs.nanosleep.return:-1
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.__get_errno_ptr.return
static int temp;
int ret = 4;
if (temp != 0) {
    ret = 0;
}
temp++;
<<uut_prototype_stubs.__get_errno_ptr.return>> = ( &ret );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: Success
TEST.UNIT:DKOsalThread
TEST.SUBPROGRAM:(cl)dk::osal::Thread::sleepUS
TEST.NEW
TEST.NAME:Success
TEST.NOTES:
Requirement_AU29610-146981
TEST.END_NOTES:
TEST.STUB:uut_prototype_stubs.nanosleep
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:0
TEST.VALUE:uut_prototype_stubs.nanosleep.return:0
TEST.END

-- Subprogram: (cl)dk::osal::Thread::start

-- Test Case: Active_thread
TEST.UNIT:DKOsalThread
TEST.SUBPROGRAM:(cl)dk::osal::Thread::start
TEST.NEW
TEST.NAME:Active_thread
TEST.NOTES:
Requirement_AU29610-146981
TEST.END_NOTES:
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.<<constructor>>.Thread(const bool).<<call>>:0
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.mActive:true
TEST.END

-- Test Case: Attr_destroy_failed
TEST.UNIT:DKOsalThread
TEST.SUBPROGRAM:(cl)dk::osal::Thread::start
TEST.NEW
TEST.NAME:Attr_destroy_failed
TEST.NOTES:
Requirement_AU29610-146981
TEST.END_NOTES:
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.<<constructor>>.Thread(const bool).<<call>>:0
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.mActive:false
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:0
TEST.VALUE:uut_prototype_stubs.pthread_attr_destroy.return:1
TEST.END

-- Test Case: Detached_non_runnable_thread_create_succeed
TEST.UNIT:DKOsalThread
TEST.SUBPROGRAM:(cl)dk::osal::Thread::start
TEST.NEW
TEST.NAME:Detached_non_runnable_thread_create_succeed
TEST.NOTES:
Requirement_AU29610-146981
TEST.END_NOTES:
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.<<constructor>>.Thread(const bool).<<call>>:0
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.mRunnable.dk::osal::vcast_concrete_IRunnable.<<constructor>>.vcast_concrete_IRunnable().<<call>>:0
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.mActive:false
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.mDetached:true
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:0
TEST.VALUE:uut_prototype_stubs.pthread_create.return:0
TEST.END

-- Test Case: Detached_runnable_thread_create_failed
TEST.UNIT:DKOsalThread
TEST.SUBPROGRAM:(cl)dk::osal::Thread::start
TEST.NEW
TEST.NAME:Detached_runnable_thread_create_failed
TEST.NOTES:
Requirement_AU29610-146981
TEST.END_NOTES:
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.<<constructor>>.Thread(const bool).<<call>>:0
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.mRunnable.dk::osal::vcast_concrete_IRunnable.<<constructor>>.vcast_concrete_IRunnable().<<call>>:0
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.mActive:false
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.mDetached:true
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:0
TEST.VALUE:uut_prototype_stubs.pthread_create.return:1
TEST.END

-- Test Case: Detached_thread_create_failed
TEST.UNIT:DKOsalThread
TEST.SUBPROGRAM:(cl)dk::osal::Thread::start
TEST.NEW
TEST.NAME:Detached_thread_create_failed
TEST.NOTES:
Requirement_AU29610-146981
TEST.END_NOTES:
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.<<constructor>>.Thread(const bool).<<call>>:0
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.mRunnable:<<null>>
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.mActive:false
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.mDetached:true
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:0
TEST.VALUE:uut_prototype_stubs.pthread_create.return:1
TEST.END

-- Test Case: Detached_thread_created
TEST.UNIT:DKOsalThread
TEST.SUBPROGRAM:(cl)dk::osal::Thread::start
TEST.NEW
TEST.NAME:Detached_thread_created
TEST.NOTES:
Requirement_AU29610-146981
TEST.END_NOTES:
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.<<constructor>>.Thread(const bool).<<call>>:0
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.mRunnable:<<null>>
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.mActive:false
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.mDetached:true
TEST.END

-- Test Case: Non_detached_runnable_thread_create_failed
TEST.UNIT:DKOsalThread
TEST.SUBPROGRAM:(cl)dk::osal::Thread::start
TEST.NEW
TEST.NAME:Non_detached_runnable_thread_create_failed
TEST.NOTES:
Requirement_AU29610-146981
TEST.END_NOTES:
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.<<constructor>>.Thread(const bool).<<call>>:0
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.mRunnable.dk::osal::vcast_concrete_IRunnable.<<constructor>>.vcast_concrete_IRunnable().<<call>>:0
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.mActive:false
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.mDetached:false
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:0
TEST.VALUE:uut_prototype_stubs.pthread_create.return:1
TEST.END

-- Test Case: Non_detached_runnable_thread_created
TEST.UNIT:DKOsalThread
TEST.SUBPROGRAM:(cl)dk::osal::Thread::start
TEST.NEW
TEST.NAME:Non_detached_runnable_thread_created
TEST.NOTES:
Requirement_AU29610-146981
TEST.END_NOTES:
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.<<constructor>>.Thread(const bool).<<call>>:0
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.mRunnable.dk::osal::vcast_concrete_IRunnable.<<constructor>>.vcast_concrete_IRunnable().<<call>>:0
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.mActive:false
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.mDetached:false
TEST.END

-- Test Case: Non_detached_thread_create_failed
TEST.UNIT:DKOsalThread
TEST.SUBPROGRAM:(cl)dk::osal::Thread::start
TEST.NEW
TEST.NAME:Non_detached_thread_create_failed
TEST.NOTES:
Requirement_AU29610-146981
TEST.END_NOTES:
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.<<constructor>>.Thread(const bool).<<call>>:0
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.mRunnable:<<null>>
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.mActive:false
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.mDetached:false
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:0
TEST.VALUE:uut_prototype_stubs.pthread_create.return:1
TEST.END

-- Test Case: Non_detached_thread_created
TEST.UNIT:DKOsalThread
TEST.SUBPROGRAM:(cl)dk::osal::Thread::start
TEST.NEW
TEST.NAME:Non_detached_thread_created
TEST.NOTES:
Requirement_AU29610-146981
TEST.END_NOTES:
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.<<constructor>>.Thread(const bool).<<call>>:0
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.mRunnable:<<null>>
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.mActive:false
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.mDetached:false
TEST.END

-- Test Case: Setdetachstate_thread_fail
TEST.UNIT:DKOsalThread
TEST.SUBPROGRAM:(cl)dk::osal::Thread::start
TEST.NEW
TEST.NAME:Setdetachstate_thread_fail
TEST.NOTES:
Requirement_AU29610-146981
TEST.END_NOTES:
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.<<constructor>>.Thread(const bool).<<call>>:0
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.mRunnable:<<null>>
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.mActive:false
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.mDetached:true
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:3
TEST.VALUE:uut_prototype_stubs.pthread_attr_setdetachstate.return:3
TEST.END

-- Test Case: Setscope_failed
TEST.UNIT:DKOsalThread
TEST.SUBPROGRAM:(cl)dk::osal::Thread::start
TEST.NEW
TEST.NAME:Setscope_failed
TEST.NOTES:
Requirement_AU29610-146981
TEST.END_NOTES:
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.<<constructor>>.Thread(const bool).<<call>>:0
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.mActive:false
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:0
TEST.VALUE:uut_prototype_stubs.pthread_attr_setscope.return:1
TEST.END

-- Subprogram: (cl)dk::osal::Thread::startThread

-- Test Case: Run_thread
TEST.UNIT:DKOsalThread
TEST.SUBPROGRAM:(cl)dk::osal::Thread::startThread
TEST.NEW
TEST.NAME:Run_thread
TEST.NOTES:
Requirement_AU29610-146981
TEST.END_NOTES:
TEST.VALUE_USER_CODE:DKOsalThread.(cl)dk::osal::Thread::startThread.parg
dk::osal::Thread *temp = new dk::osal::Thread(false);
<<DKOsalThread.(cl)dk::osal::Thread::startThread.parg>> = ( temp );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::osal::Thread::startThreadRunnable

-- Test Case: Run_runnable_thread
TEST.UNIT:DKOsalThread
TEST.SUBPROGRAM:(cl)dk::osal::Thread::startThreadRunnable
TEST.NEW
TEST.NAME:Run_runnable_thread
TEST.NOTES:
Requirement_AU29610-146981
TEST.END_NOTES:
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.<<constructor>>.Thread(dk::osal::IRunnable*,const bool).<<call>>:0
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.mRunnable.dk::osal::vcast_concrete_IRunnable.<<constructor>>.vcast_concrete_IRunnable().<<call>>:0
TEST.VALUE_USER_CODE:DKOsalThread.(cl)dk::osal::Thread::startThreadRunnable.parg
class TempThread : public dk::osal::IRunnable {
    public:
        TempThread () {};
        void *run () { return NULL; };
};
TempThread *const tempThread = new TempThread;

dk::osal::Thread *const temp = new dk::osal::Thread(tempThread, false);

<<DKOsalThread.(cl)dk::osal::Thread::startThreadRunnable.parg>> = ( temp );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::osal::Thread::yield

-- Test Case: Sched_yield
TEST.UNIT:DKOsalThread
TEST.SUBPROGRAM:(cl)dk::osal::Thread::yield
TEST.NEW
TEST.NAME:Sched_yield
TEST.NOTES:
Requirement_AU29610-146981
TEST.END_NOTES:
TEST.END

-- Subprogram: (cl)dk::osal::Thread::~Thread

-- Test Case: DeInitialize
TEST.UNIT:DKOsalThread
TEST.SUBPROGRAM:(cl)dk::osal::Thread::~Thread
TEST.NEW
TEST.NAME:DeInitialize
TEST.NOTES:
Requirement_AU29610-146981
TEST.END_NOTES:
TEST.STUB:DKOsalThread.(cl)dk::osal::Thread::cancel
TEST.STUB:DKOsalThread.(cl)dk::osal::Thread::join
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.<<constructor>>.Thread(const bool).<<call>>:0
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.mActive:true
TEST.VALUE:DKOsalThread.(cl)dk::osal::Thread::join.return:VECTORCAST_BUFFER
TEST.END

-- Test Case: DeInitialize_not_running
TEST.UNIT:DKOsalThread
TEST.SUBPROGRAM:(cl)dk::osal::Thread::~Thread
TEST.NEW
TEST.NAME:DeInitialize_not_running
TEST.NOTES:
Requirement_AU29610-146981
TEST.END_NOTES:
TEST.VALUE:DKOsalThread.<<GLOBAL>>.(cl).dk::osal::Thread.dk::osal::Thread.<<constructor>>.Thread(const bool).<<call>>:0
TEST.END
