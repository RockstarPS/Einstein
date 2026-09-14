-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : OSAL_SEMAPHORE_UT
-- Unit(s) Under Test: DKOsalSemaphore
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

-- Unit: DKOsalSemaphore

-- Subprogram: (cl)dk::osal::Semaphore::Semaphore

-- Test Case: Initialize
TEST.UNIT:DKOsalSemaphore
TEST.SUBPROGRAM:(cl)dk::osal::Semaphore::Semaphore
TEST.NEW
TEST.NAME:Initialize
TEST.NOTES:
Requirement_AU29610-146978
TEST.END_NOTES:
TEST.END

-- Subprogram: (cl)dk::osal::Semaphore::init

-- Test Case: Semaphore_init_failed
TEST.UNIT:DKOsalSemaphore
TEST.SUBPROGRAM:(cl)dk::osal::Semaphore::init
TEST.NEW
TEST.NAME:Semaphore_init_failed
TEST.NOTES:
Requirement_AU29610-146978
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.sem_init.return:1
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:7
TEST.END

-- Test Case: Success
TEST.UNIT:DKOsalSemaphore
TEST.SUBPROGRAM:(cl)dk::osal::Semaphore::init
TEST.NEW
TEST.NAME:Success
TEST.NOTES:
Requirement_AU29610-146978
TEST.END_NOTES:
TEST.END

-- Subprogram: (cl)dk::osal::Semaphore::post

-- Test Case: Semaphore_post_failed
TEST.UNIT:DKOsalSemaphore
TEST.SUBPROGRAM:(cl)dk::osal::Semaphore::post
TEST.NEW
TEST.NAME:Semaphore_post_failed
TEST.NOTES:
Requirement_AU29610-146978
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.sem_post.return:1
TEST.END

-- Test Case: Semaphore_post_success
TEST.UNIT:DKOsalSemaphore
TEST.SUBPROGRAM:(cl)dk::osal::Semaphore::post
TEST.NEW
TEST.NAME:Semaphore_post_success
TEST.NOTES:
Requirement_AU29610-146978
TEST.END_NOTES:
TEST.END

-- Subprogram: (cl)dk::osal::Semaphore::timedWaitMS

-- Test Case: GetTime_failed
TEST.UNIT:DKOsalSemaphore
TEST.SUBPROGRAM:(cl)dk::osal::Semaphore::timedWaitMS
TEST.NEW
TEST.NAME:GetTime_failed
TEST.NOTES:
Requirement_AU29610-146978
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:7
TEST.VALUE:uut_prototype_stubs.clock_gettime.return:1
TEST.EXPECTED:DKOsalSemaphore.(cl)dk::osal::Semaphore::timedWaitMS.return:true
TEST.END

-- Test Case: Success
TEST.UNIT:DKOsalSemaphore
TEST.SUBPROGRAM:(cl)dk::osal::Semaphore::timedWaitMS
TEST.NEW
TEST.NAME:Success
TEST.NOTES:
Requirement_AU29610-146978
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:4
TEST.EXPECTED:DKOsalSemaphore.(cl)dk::osal::Semaphore::timedWaitMS.return:true
TEST.END

-- Test Case: TimedWait_failed
TEST.UNIT:DKOsalSemaphore
TEST.SUBPROGRAM:(cl)dk::osal::Semaphore::timedWaitMS
TEST.NEW
TEST.NAME:TimedWait_failed
TEST.NOTES:
Requirement_AU29610-146978
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.sem_timedwait.return:1
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:16
TEST.EXPECTED:DKOsalSemaphore.(cl)dk::osal::Semaphore::timedWaitMS.return:false
TEST.END

-- Test Case: TimedWait_failed_ETIMEOUT
TEST.UNIT:DKOsalSemaphore
TEST.SUBPROGRAM:(cl)dk::osal::Semaphore::timedWaitMS
TEST.NEW
TEST.NAME:TimedWait_failed_ETIMEOUT
TEST.NOTES:
Requirement_AU29610-146978
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.sem_timedwait.return:1
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:9938
TEST.EXPECTED:DKOsalSemaphore.(cl)dk::osal::Semaphore::timedWaitMS.return:false
TEST.END

-- Test Case: TimedWait_loop
TEST.UNIT:DKOsalSemaphore
TEST.SUBPROGRAM:(cl)dk::osal::Semaphore::timedWaitMS
TEST.NEW
TEST.NAME:TimedWait_loop
TEST.NOTES:
Requirement_AU29610-146978
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.sem_timedwait.return:1
TEST.EXPECTED:DKOsalSemaphore.(cl)dk::osal::Semaphore::timedWaitMS.return:false
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.__get_errno_ptr.return
static int i;
int temp;
if (i == 0) {
   temp = 4;
   i++;
}else {
   temp = 16;
}
<<uut_prototype_stubs.__get_errno_ptr.return>> = ( &temp );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::osal::Semaphore::timedWaitUS

-- Test Case: GetTime_failed
TEST.UNIT:DKOsalSemaphore
TEST.SUBPROGRAM:(cl)dk::osal::Semaphore::timedWaitUS
TEST.NEW
TEST.NAME:GetTime_failed
TEST.NOTES:
Requirement_AU29610-146978
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:7
TEST.VALUE:uut_prototype_stubs.clock_gettime.return:1
TEST.EXPECTED:DKOsalSemaphore.(cl)dk::osal::Semaphore::timedWaitUS.return:true
TEST.END

-- Test Case: Success
TEST.UNIT:DKOsalSemaphore
TEST.SUBPROGRAM:(cl)dk::osal::Semaphore::timedWaitUS
TEST.NEW
TEST.NAME:Success
TEST.NOTES:
Requirement_AU29610-146978
TEST.END_NOTES:
TEST.EXPECTED:DKOsalSemaphore.(cl)dk::osal::Semaphore::timedWaitUS.return:true
TEST.END

-- Test Case: TimedWait_failed
TEST.UNIT:DKOsalSemaphore
TEST.SUBPROGRAM:(cl)dk::osal::Semaphore::timedWaitUS
TEST.NEW
TEST.NAME:TimedWait_failed
TEST.NOTES:
Requirement_AU29610-146978
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.sem_timedwait.return:1
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:16
TEST.EXPECTED:DKOsalSemaphore.(cl)dk::osal::Semaphore::timedWaitUS.return:false
TEST.END

-- Test Case: TimedWait_failed_ETIMEOUT
TEST.UNIT:DKOsalSemaphore
TEST.SUBPROGRAM:(cl)dk::osal::Semaphore::timedWaitUS
TEST.NEW
TEST.NAME:TimedWait_failed_ETIMEOUT
TEST.NOTES:
Requirement_AU29610-146978
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.sem_timedwait.return:1
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:9938
TEST.EXPECTED:DKOsalSemaphore.(cl)dk::osal::Semaphore::timedWaitUS.return:false
TEST.END

-- Test Case: TimedWait_loop
TEST.UNIT:DKOsalSemaphore
TEST.SUBPROGRAM:(cl)dk::osal::Semaphore::timedWaitUS
TEST.NEW
TEST.NAME:TimedWait_loop
TEST.NOTES:
Requirement_AU29610-146978
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.sem_timedwait.return:1
TEST.EXPECTED:DKOsalSemaphore.(cl)dk::osal::Semaphore::timedWaitUS.return:false
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.__get_errno_ptr.return
static int i;
int temp;
if (i == 0) {
   temp = 4;
   i++;
}else {
   temp = 16;
}
<<uut_prototype_stubs.__get_errno_ptr.return>> = ( &temp );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::osal::Semaphore::tryWait

-- Test Case: Success
TEST.UNIT:DKOsalSemaphore
TEST.SUBPROGRAM:(cl)dk::osal::Semaphore::tryWait
TEST.NEW
TEST.NAME:Success
TEST.NOTES:
Requirement_AU29610-146978
TEST.END_NOTES:
TEST.EXPECTED:DKOsalSemaphore.(cl)dk::osal::Semaphore::tryWait.return:true
TEST.END

-- Test Case: TryWait_failed
TEST.UNIT:DKOsalSemaphore
TEST.SUBPROGRAM:(cl)dk::osal::Semaphore::tryWait
TEST.NEW
TEST.NAME:TryWait_failed
TEST.NOTES:
Requirement_AU29610-146978
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.sem_trywait.return:1
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:7
TEST.EXPECTED:DKOsalSemaphore.(cl)dk::osal::Semaphore::tryWait.return:false
TEST.END

-- Test Case: TryWait_failed_EBUSY
TEST.UNIT:DKOsalSemaphore
TEST.SUBPROGRAM:(cl)dk::osal::Semaphore::tryWait
TEST.NEW
TEST.NAME:TryWait_failed_EBUSY
TEST.NOTES:
Requirement_AU29610-146978
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.sem_trywait.return:16
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:16
TEST.EXPECTED:DKOsalSemaphore.(cl)dk::osal::Semaphore::tryWait.return:false
TEST.END

-- Subprogram: (cl)dk::osal::Semaphore::value

-- Test Case: GetValue_failed
TEST.UNIT:DKOsalSemaphore
TEST.SUBPROGRAM:(cl)dk::osal::Semaphore::value
TEST.NEW
TEST.NAME:GetValue_failed
TEST.NOTES:
Requirement_AU29610-146978
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.sem_getvalue.return:1
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:7
TEST.EXPECTED:DKOsalSemaphore.(cl)dk::osal::Semaphore::value.return:0
TEST.END

-- Test Case: GetValue_less_than_zero
TEST.UNIT:DKOsalSemaphore
TEST.SUBPROGRAM:(cl)dk::osal::Semaphore::value
TEST.NEW
TEST.NAME:GetValue_less_than_zero
TEST.NOTES:
Requirement_AU29610-146978
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.sem_getvalue.__sval[0]:-1
TEST.VALUE:uut_prototype_stubs.sem_getvalue.return:0
TEST.EXPECTED:DKOsalSemaphore.(cl)dk::osal::Semaphore::value.return:0
TEST.END

-- Test Case: Success
TEST.UNIT:DKOsalSemaphore
TEST.SUBPROGRAM:(cl)dk::osal::Semaphore::value
TEST.NEW
TEST.NAME:Success
TEST.NOTES:
Requirement_AU29610-146978
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:-1
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.sem_getvalue.__sval
<<uut_prototype_stubs.sem_getvalue.__sval>> = ( &VECTORCAST_INT1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::osal::Semaphore::wait

-- Test Case: Semaphore_wait_failed
TEST.UNIT:DKOsalSemaphore
TEST.SUBPROGRAM:(cl)dk::osal::Semaphore::wait
TEST.NEW
TEST.NAME:Semaphore_wait_failed
TEST.NOTES:
Requirement_AU29610-146978
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.sem_wait.return:1
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:16
TEST.END

-- Test Case: Semaphore_wait_loop
TEST.UNIT:DKOsalSemaphore
TEST.SUBPROGRAM:(cl)dk::osal::Semaphore::wait
TEST.NEW
TEST.NAME:Semaphore_wait_loop
TEST.NOTES:
Requirement_AU29610-146978
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.sem_wait.return:1
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.__get_errno_ptr.return
static int i;
int temp;
if (i == 0) {
   temp = 4;
   i++;
}else {
   temp = 16;
}
<<uut_prototype_stubs.__get_errno_ptr.return>> = ( &temp );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: Semaphore_wait_success
TEST.UNIT:DKOsalSemaphore
TEST.SUBPROGRAM:(cl)dk::osal::Semaphore::wait
TEST.NEW
TEST.NAME:Semaphore_wait_success
TEST.NOTES:
Requirement_AU29610-146978
TEST.END_NOTES:
TEST.END

-- Subprogram: (cl)dk::osal::Semaphore::~Semaphore

-- Test Case: DeInitialize
TEST.UNIT:DKOsalSemaphore
TEST.SUBPROGRAM:(cl)dk::osal::Semaphore::~Semaphore
TEST.NEW
TEST.NAME:DeInitialize
TEST.NOTES:
Requirement_AU29610-146978
TEST.END_NOTES:
TEST.VALUE:DKOsalSemaphore.<<GLOBAL>>.(cl).dk::osal::Semaphore.dk::osal::Semaphore.<<constructor>>.Semaphore(const uint32_t).<<call>>:0
TEST.VALUE:uut_prototype_stubs.sem_destroy.return:0
TEST.END

-- Test Case: Semaphore_destroy_failed
TEST.UNIT:DKOsalSemaphore
TEST.SUBPROGRAM:(cl)dk::osal::Semaphore::~Semaphore
TEST.NEW
TEST.NAME:Semaphore_destroy_failed
TEST.NOTES:
Requirement_AU29610-146978
TEST.END_NOTES:
TEST.VALUE:DKOsalSemaphore.<<GLOBAL>>.(cl).dk::osal::Semaphore.dk::osal::Semaphore.<<constructor>>.Semaphore(const uint32_t).<<call>>:0
TEST.VALUE:uut_prototype_stubs.sem_destroy.return:1
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:7
TEST.END
