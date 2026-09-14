-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : OSAL_MUTEX_UT
-- Unit(s) Under Test: DKOsalMutex
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

-- Unit: DKOsalMutex

-- Subprogram: (cl)dk::osal::Mutex::Mutex

-- Test Case: Initialize
TEST.UNIT:DKOsalMutex
TEST.SUBPROGRAM:(cl)dk::osal::Mutex::Mutex
TEST.NEW
TEST.NAME:Initialize
TEST.NOTES:
Requirement_AU29610-146971
TEST.END_NOTES:
TEST.END

-- Subprogram: (cl)dk::osal::Mutex::getPthreadMutex

-- Test Case: Null_Mutex
TEST.UNIT:DKOsalMutex
TEST.SUBPROGRAM:(cl)dk::osal::Mutex::getPthreadMutex
TEST.NEW
TEST.NAME:Null_Mutex
TEST.NOTES:
Requirement_AU29610-146971
TEST.END_NOTES:
TEST.VALUE:DKOsalMutex.<<GLOBAL>>.(cl).dk::osal::Mutex:<<null>>
TEST.EXPECTED:DKOsalMutex.(cl)dk::osal::Mutex::getPthreadMutex.return:<<null>>
TEST.END

-- Test Case: Success
TEST.UNIT:DKOsalMutex
TEST.SUBPROGRAM:(cl)dk::osal::Mutex::getPthreadMutex
TEST.NEW
TEST.NAME:Success
TEST.NOTES:
Requirement_AU29610-146971
TEST.END_NOTES:
TEST.VALUE:DKOsalMutex.<<GLOBAL>>.(cl).dk::osal::Mutex.dk::osal::Mutex.<<constructor>>.Mutex().<<call>>:0
TEST.END

-- Subprogram: (cl)dk::osal::Mutex::init

-- Test Case: Mutex_init_failed
TEST.UNIT:DKOsalMutex
TEST.SUBPROGRAM:(cl)dk::osal::Mutex::init
TEST.NEW
TEST.NAME:Mutex_init_failed
TEST.NOTES:
Requirement_AU29610-146971
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.pthread_mutex_init.return:1
TEST.END

-- Test Case: Mutexattr_init_failed
TEST.UNIT:DKOsalMutex
TEST.SUBPROGRAM:(cl)dk::osal::Mutex::init
TEST.NEW
TEST.NAME:Mutexattr_init_failed
TEST.NOTES:
Requirement_AU29610-146971
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.pthread_mutexattr_init.return:1
TEST.END

-- Test Case: Mutexattr_sepshared_failed
TEST.UNIT:DKOsalMutex
TEST.SUBPROGRAM:(cl)dk::osal::Mutex::init
TEST.NEW
TEST.NAME:Mutexattr_sepshared_failed
TEST.NOTES:
Requirement_AU29610-146971
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.pthread_mutexattr_setpshared.return:1
TEST.END

-- Test Case: Mutexattr_settype_failed
TEST.UNIT:DKOsalMutex
TEST.SUBPROGRAM:(cl)dk::osal::Mutex::init
TEST.NEW
TEST.NAME:Mutexattr_settype_failed
TEST.NOTES:
Requirement_AU29610-146971
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.pthread_mutexattr_settype.return:1
TEST.END

-- Test Case: Success
TEST.UNIT:DKOsalMutex
TEST.SUBPROGRAM:(cl)dk::osal::Mutex::init
TEST.NEW
TEST.NAME:Success
TEST.NOTES:
Requirement_AU29610-146971
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.pthread_mutex_init.return:0
TEST.VALUE:uut_prototype_stubs.pthread_mutexattr_init.return:0
TEST.VALUE:uut_prototype_stubs.pthread_mutexattr_setpshared.return:0
TEST.VALUE:uut_prototype_stubs.pthread_mutexattr_settype.return:0
TEST.END

-- Subprogram: (cl)dk::osal::Mutex::lock

-- Test Case: Failed
TEST.UNIT:DKOsalMutex
TEST.SUBPROGRAM:(cl)dk::osal::Mutex::lock
TEST.NEW
TEST.NAME:Failed
TEST.NOTES:
Requirement_AU29610-146971
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.pthread_mutex_lock.return:1
TEST.END

-- Test Case: Success
TEST.UNIT:DKOsalMutex
TEST.SUBPROGRAM:(cl)dk::osal::Mutex::lock
TEST.NEW
TEST.NAME:Success
TEST.NOTES:
Requirement_AU29610-146971
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.pthread_mutex_lock.return:0
TEST.END

-- Subprogram: (cl)dk::osal::Mutex::timedLockMS

-- Test Case: GetClock_failed
TEST.UNIT:DKOsalMutex
TEST.SUBPROGRAM:(cl)dk::osal::Mutex::timedLockMS
TEST.NEW
TEST.NAME:GetClock_failed
TEST.NOTES:
Requirement_AU29610-146971
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.clock_gettime.return:1
TEST.EXPECTED:DKOsalMutex.(cl)dk::osal::Mutex::timedLockMS.return:true
TEST.END

-- Test Case: Mutex_timedlock_ETIMEOUT
TEST.UNIT:DKOsalMutex
TEST.SUBPROGRAM:(cl)dk::osal::Mutex::timedLockMS
TEST.NEW
TEST.NAME:Mutex_timedlock_ETIMEOUT
TEST.NOTES:
Requirement_AU29610-146971
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.pthread_mutex_timedlock.return:9938
TEST.EXPECTED:DKOsalMutex.(cl)dk::osal::Mutex::timedLockMS.return:false
TEST.END

-- Test Case: Mutex_timedlock_failed
TEST.UNIT:DKOsalMutex
TEST.SUBPROGRAM:(cl)dk::osal::Mutex::timedLockMS
TEST.NEW
TEST.NAME:Mutex_timedlock_failed
TEST.NOTES:
Requirement_AU29610-146971
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.pthread_mutex_timedlock.return:1
TEST.EXPECTED:DKOsalMutex.(cl)dk::osal::Mutex::timedLockMS.return:false
TEST.END

-- Test Case: Success
TEST.UNIT:DKOsalMutex
TEST.SUBPROGRAM:(cl)dk::osal::Mutex::timedLockMS
TEST.NEW
TEST.NAME:Success
TEST.NOTES:
Requirement_AU29610-146971
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.pthread_mutex_timedlock.return:0
TEST.VALUE:uut_prototype_stubs.clock_gettime.return:0
TEST.EXPECTED:DKOsalMutex.(cl)dk::osal::Mutex::timedLockMS.return:true
TEST.END

-- Subprogram: (cl)dk::osal::Mutex::timedLockUS

-- Test Case: GetTime_failed
TEST.UNIT:DKOsalMutex
TEST.SUBPROGRAM:(cl)dk::osal::Mutex::timedLockUS
TEST.NEW
TEST.NAME:GetTime_failed
TEST.NOTES:
Requirement_AU29610-146971
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.clock_gettime.return:1
TEST.EXPECTED:DKOsalMutex.(cl)dk::osal::Mutex::timedLockUS.return:true
TEST.END

-- Test Case: Mutex_timedlock_ETIMEOUT
TEST.UNIT:DKOsalMutex
TEST.SUBPROGRAM:(cl)dk::osal::Mutex::timedLockUS
TEST.NEW
TEST.NAME:Mutex_timedlock_ETIMEOUT
TEST.NOTES:
Requirement_AU29610-146971
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.pthread_mutex_timedlock.return:9938
TEST.EXPECTED:DKOsalMutex.(cl)dk::osal::Mutex::timedLockUS.return:false
TEST.END

-- Test Case: Mutex_timedlock_failed
TEST.UNIT:DKOsalMutex
TEST.SUBPROGRAM:(cl)dk::osal::Mutex::timedLockUS
TEST.NEW
TEST.NAME:Mutex_timedlock_failed
TEST.NOTES:
Requirement_AU29610-146971
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.pthread_mutex_timedlock.return:1
TEST.EXPECTED:DKOsalMutex.(cl)dk::osal::Mutex::timedLockUS.return:false
TEST.END

-- Test Case: Success
TEST.UNIT:DKOsalMutex
TEST.SUBPROGRAM:(cl)dk::osal::Mutex::timedLockUS
TEST.NEW
TEST.NAME:Success
TEST.NOTES:
Requirement_AU29610-146971
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.pthread_mutex_timedlock.return:0
TEST.VALUE:uut_prototype_stubs.clock_gettime.return:0
TEST.EXPECTED:DKOsalMutex.(cl)dk::osal::Mutex::timedLockUS.return:true
TEST.END

-- Subprogram: (cl)dk::osal::Mutex::tryLock

-- Test Case: Lock_failed
TEST.UNIT:DKOsalMutex
TEST.SUBPROGRAM:(cl)dk::osal::Mutex::tryLock
TEST.NEW
TEST.NAME:Lock_failed
TEST.NOTES:
Requirement_AU29610-146971
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.pthread_mutex_trylock.return:1
TEST.EXPECTED:DKOsalMutex.(cl)dk::osal::Mutex::tryLock.return:false
TEST.END

-- Test Case: Lock_failed_EBUSY
TEST.UNIT:DKOsalMutex
TEST.SUBPROGRAM:(cl)dk::osal::Mutex::tryLock
TEST.NEW
TEST.NAME:Lock_failed_EBUSY
TEST.NOTES:
Requirement_AU29610-146971
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.pthread_mutex_trylock.return:16
TEST.EXPECTED:DKOsalMutex.(cl)dk::osal::Mutex::tryLock.return:false
TEST.END

-- Test Case: Success
TEST.UNIT:DKOsalMutex
TEST.SUBPROGRAM:(cl)dk::osal::Mutex::tryLock
TEST.NEW
TEST.NAME:Success
TEST.NOTES:
Requirement_AU29610-146971
TEST.END_NOTES:
TEST.EXPECTED:DKOsalMutex.(cl)dk::osal::Mutex::tryLock.return:true
TEST.END

-- Subprogram: (cl)dk::osal::Mutex::unlock

-- Test Case: Failed
TEST.UNIT:DKOsalMutex
TEST.SUBPROGRAM:(cl)dk::osal::Mutex::unlock
TEST.NEW
TEST.NAME:Failed
TEST.NOTES:
Requirement_AU29610-146971
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.pthread_mutex_unlock.return:1
TEST.END

-- Test Case: Success
TEST.UNIT:DKOsalMutex
TEST.SUBPROGRAM:(cl)dk::osal::Mutex::unlock
TEST.NEW
TEST.NAME:Success
TEST.NOTES:
Requirement_AU29610-146971
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.pthread_mutex_unlock.return:0
TEST.END

-- Subprogram: (cl)dk::osal::Mutex::~Mutex

-- Test Case: DeInitialized_failed
TEST.UNIT:DKOsalMutex
TEST.SUBPROGRAM:(cl)dk::osal::Mutex::~Mutex
TEST.NEW
TEST.NAME:DeInitialized_failed
TEST.NOTES:
Requirement_AU29610-146971
TEST.END_NOTES:
TEST.VALUE:DKOsalMutex.<<GLOBAL>>.(cl).dk::osal::Mutex.dk::osal::Mutex.<<constructor>>.Mutex().<<call>>:0
TEST.VALUE:uut_prototype_stubs.pthread_mutex_destroy.return:1
TEST.END

-- Test Case: DeInitialized_successfully
TEST.UNIT:DKOsalMutex
TEST.SUBPROGRAM:(cl)dk::osal::Mutex::~Mutex
TEST.NEW
TEST.NAME:DeInitialized_successfully
TEST.NOTES:
Requirement_AU29610-146971
TEST.END_NOTES:
TEST.VALUE:DKOsalMutex.<<GLOBAL>>.(cl).dk::osal::Mutex.dk::osal::Mutex.<<constructor>>.Mutex().<<call>>:0
TEST.END
