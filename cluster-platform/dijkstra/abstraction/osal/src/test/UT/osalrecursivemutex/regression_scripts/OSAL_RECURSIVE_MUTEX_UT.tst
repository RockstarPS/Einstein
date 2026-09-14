-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : OSAL_RECURSIVE_MUTEX_UT
-- Unit(s) Under Test: DKOsalRecursiveMutex
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

-- Unit: DKOsalRecursiveMutex

-- Subprogram: (cl)dk::osal::RecursiveMutex::RecursiveMutex

-- Test Case: Initialize
TEST.UNIT:DKOsalRecursiveMutex
TEST.SUBPROGRAM:(cl)dk::osal::RecursiveMutex::RecursiveMutex
TEST.NEW
TEST.NAME:Initialize
TEST.NOTES:
Requirement_AU29610-146977
TEST.END_NOTES:
TEST.END

-- Subprogram: (cl)dk::osal::RecursiveMutex::getPthreadMutex

-- Test Case: Null_mutex
TEST.UNIT:DKOsalRecursiveMutex
TEST.SUBPROGRAM:(cl)dk::osal::RecursiveMutex::getPthreadMutex
TEST.NEW
TEST.NAME:Null_mutex
TEST.NOTES:
Requirement_AU29610-146977
TEST.END_NOTES:
TEST.VALUE:DKOsalRecursiveMutex.<<GLOBAL>>.(cl).dk::osal::RecursiveMutex:<<null>>
TEST.EXPECTED:DKOsalRecursiveMutex.(cl)dk::osal::RecursiveMutex::getPthreadMutex.return:<<null>>
TEST.END

-- Test Case: Success
TEST.UNIT:DKOsalRecursiveMutex
TEST.SUBPROGRAM:(cl)dk::osal::RecursiveMutex::getPthreadMutex
TEST.NEW
TEST.NAME:Success
TEST.NOTES:
Requirement_AU29610-146977
TEST.END_NOTES:
TEST.VALUE:DKOsalRecursiveMutex.<<GLOBAL>>.(cl).dk::osal::RecursiveMutex.dk::osal::RecursiveMutex.<<constructor>>.RecursiveMutex().<<call>>:0
TEST.END

-- Subprogram: (cl)dk::osal::RecursiveMutex::init

-- Test Case: Mutex_init_failed
TEST.UNIT:DKOsalRecursiveMutex
TEST.SUBPROGRAM:(cl)dk::osal::RecursiveMutex::init
TEST.NEW
TEST.NAME:Mutex_init_failed
TEST.NOTES:
Requirement_AU29610-146977
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.pthread_mutex_init.return:1
TEST.END

-- Test Case: Mutexattr_init_failed
TEST.UNIT:DKOsalRecursiveMutex
TEST.SUBPROGRAM:(cl)dk::osal::RecursiveMutex::init
TEST.NEW
TEST.NAME:Mutexattr_init_failed
TEST.NOTES:
Requirement_AU29610-146977
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.pthread_mutexattr_init.return:1
TEST.END

-- Test Case: Mutexattr_setpshared_failed
TEST.UNIT:DKOsalRecursiveMutex
TEST.SUBPROGRAM:(cl)dk::osal::RecursiveMutex::init
TEST.NEW
TEST.NAME:Mutexattr_setpshared_failed
TEST.NOTES:
Requirement_AU29610-146977
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.pthread_mutexattr_setpshared.return:1
TEST.END

-- Test Case: Mutexattr_settype_failed
TEST.UNIT:DKOsalRecursiveMutex
TEST.SUBPROGRAM:(cl)dk::osal::RecursiveMutex::init
TEST.NEW
TEST.NAME:Mutexattr_settype_failed
TEST.NOTES:
Requirement_AU29610-146977
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.pthread_mutexattr_settype.return:1
TEST.END

-- Test Case: Success
TEST.UNIT:DKOsalRecursiveMutex
TEST.SUBPROGRAM:(cl)dk::osal::RecursiveMutex::init
TEST.NEW
TEST.NAME:Success
TEST.NOTES:
Requirement_AU29610-146977
TEST.END_NOTES:
TEST.END

-- Subprogram: (cl)dk::osal::RecursiveMutex::lock

-- Test Case: Failed
TEST.UNIT:DKOsalRecursiveMutex
TEST.SUBPROGRAM:(cl)dk::osal::RecursiveMutex::lock
TEST.NEW
TEST.NAME:Failed
TEST.NOTES:
Requirement_AU29610-146977
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.pthread_mutex_lock.return:1
TEST.END

-- Test Case: Success
TEST.UNIT:DKOsalRecursiveMutex
TEST.SUBPROGRAM:(cl)dk::osal::RecursiveMutex::lock
TEST.NEW
TEST.NAME:Success
TEST.NOTES:
Requirement_AU29610-146977
TEST.END_NOTES:
TEST.END

-- Subprogram: (cl)dk::osal::RecursiveMutex::timedLockMS

-- Test Case: GetTime_failed
TEST.UNIT:DKOsalRecursiveMutex
TEST.SUBPROGRAM:(cl)dk::osal::RecursiveMutex::timedLockMS
TEST.NEW
TEST.NAME:GetTime_failed
TEST.NOTES:
Requirement_AU29610-146977
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.clock_gettime.return:1
TEST.EXPECTED:DKOsalRecursiveMutex.(cl)dk::osal::RecursiveMutex::timedLockMS.return:true
TEST.END

-- Test Case: Mutex_timedlock_ETIMEOUT
TEST.UNIT:DKOsalRecursiveMutex
TEST.SUBPROGRAM:(cl)dk::osal::RecursiveMutex::timedLockMS
TEST.NEW
TEST.NAME:Mutex_timedlock_ETIMEOUT
TEST.NOTES:
Requirement_AU29610-146977
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.pthread_mutex_timedlock.return:9938
TEST.EXPECTED:DKOsalRecursiveMutex.(cl)dk::osal::RecursiveMutex::timedLockMS.return:false
TEST.END

-- Test Case: Mutex_timedlock_failed
TEST.UNIT:DKOsalRecursiveMutex
TEST.SUBPROGRAM:(cl)dk::osal::RecursiveMutex::timedLockMS
TEST.NEW
TEST.NAME:Mutex_timedlock_failed
TEST.NOTES:
Requirement_AU29610-146977
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.pthread_mutex_timedlock.return:1
TEST.EXPECTED:DKOsalRecursiveMutex.(cl)dk::osal::RecursiveMutex::timedLockMS.return:false
TEST.END

-- Test Case: Success
TEST.UNIT:DKOsalRecursiveMutex
TEST.SUBPROGRAM:(cl)dk::osal::RecursiveMutex::timedLockMS
TEST.NEW
TEST.NAME:Success
TEST.NOTES:
Requirement_AU29610-146977
TEST.END_NOTES:
TEST.EXPECTED:DKOsalRecursiveMutex.(cl)dk::osal::RecursiveMutex::timedLockMS.return:true
TEST.END

-- Subprogram: (cl)dk::osal::RecursiveMutex::timedLockUS

-- Test Case: GetTime_failed
TEST.UNIT:DKOsalRecursiveMutex
TEST.SUBPROGRAM:(cl)dk::osal::RecursiveMutex::timedLockUS
TEST.NEW
TEST.NAME:GetTime_failed
TEST.NOTES:
Requirement_AU29610-146977
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.clock_gettime.return:1
TEST.EXPECTED:DKOsalRecursiveMutex.(cl)dk::osal::RecursiveMutex::timedLockUS.return:true
TEST.END

-- Test Case: Mutex_timedlock_ETIMEOUT
TEST.UNIT:DKOsalRecursiveMutex
TEST.SUBPROGRAM:(cl)dk::osal::RecursiveMutex::timedLockUS
TEST.NEW
TEST.NAME:Mutex_timedlock_ETIMEOUT
TEST.NOTES:
Requirement_AU29610-146977
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.pthread_mutex_timedlock.return:9938
TEST.EXPECTED:DKOsalRecursiveMutex.(cl)dk::osal::RecursiveMutex::timedLockUS.return:false
TEST.END

-- Test Case: Mutex_timedlock_failed
TEST.UNIT:DKOsalRecursiveMutex
TEST.SUBPROGRAM:(cl)dk::osal::RecursiveMutex::timedLockUS
TEST.NEW
TEST.NAME:Mutex_timedlock_failed
TEST.NOTES:
Requirement_AU29610-146977
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.pthread_mutex_timedlock.return:1
TEST.EXPECTED:DKOsalRecursiveMutex.(cl)dk::osal::RecursiveMutex::timedLockUS.return:false
TEST.END

-- Test Case: Success
TEST.UNIT:DKOsalRecursiveMutex
TEST.SUBPROGRAM:(cl)dk::osal::RecursiveMutex::timedLockUS
TEST.NEW
TEST.NAME:Success
TEST.NOTES:
Requirement_AU29610-146977
TEST.END_NOTES:
TEST.EXPECTED:DKOsalRecursiveMutex.(cl)dk::osal::RecursiveMutex::timedLockUS.return:true
TEST.END

-- Subprogram: (cl)dk::osal::RecursiveMutex::tryLock

-- Test Case: Lock_failed
TEST.UNIT:DKOsalRecursiveMutex
TEST.SUBPROGRAM:(cl)dk::osal::RecursiveMutex::tryLock
TEST.NEW
TEST.NAME:Lock_failed
TEST.NOTES:
Requirement_AU29610-146977
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.pthread_mutex_trylock.return:1
TEST.EXPECTED:DKOsalRecursiveMutex.(cl)dk::osal::RecursiveMutex::tryLock.return:false
TEST.END

-- Test Case: Lock_failed_EBUSY
TEST.UNIT:DKOsalRecursiveMutex
TEST.SUBPROGRAM:(cl)dk::osal::RecursiveMutex::tryLock
TEST.NEW
TEST.NAME:Lock_failed_EBUSY
TEST.NOTES:
Requirement_AU29610-146977
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.pthread_mutex_trylock.return:16
TEST.EXPECTED:DKOsalRecursiveMutex.(cl)dk::osal::RecursiveMutex::tryLock.return:false
TEST.END

-- Test Case: Success
TEST.UNIT:DKOsalRecursiveMutex
TEST.SUBPROGRAM:(cl)dk::osal::RecursiveMutex::tryLock
TEST.NEW
TEST.NAME:Success
TEST.NOTES:
Requirement_AU29610-146977
TEST.END_NOTES:
TEST.EXPECTED:DKOsalRecursiveMutex.(cl)dk::osal::RecursiveMutex::tryLock.return:true
TEST.END

-- Subprogram: (cl)dk::osal::RecursiveMutex::unlock

-- Test Case: Failed
TEST.UNIT:DKOsalRecursiveMutex
TEST.SUBPROGRAM:(cl)dk::osal::RecursiveMutex::unlock
TEST.NEW
TEST.NAME:Failed
TEST.NOTES:
Requirement_AU29610-146977
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.pthread_mutex_unlock.return:1
TEST.END

-- Test Case: Success
TEST.UNIT:DKOsalRecursiveMutex
TEST.SUBPROGRAM:(cl)dk::osal::RecursiveMutex::unlock
TEST.NEW
TEST.NAME:Success
TEST.NOTES:
Requirement_AU29610-146977
TEST.END_NOTES:
TEST.END

-- Subprogram: (cl)dk::osal::RecursiveMutex::~RecursiveMutex

-- Test Case: DeInitialization_failed
TEST.UNIT:DKOsalRecursiveMutex
TEST.SUBPROGRAM:(cl)dk::osal::RecursiveMutex::~RecursiveMutex
TEST.NEW
TEST.NAME:DeInitialization_failed
TEST.NOTES:
Requirement_AU29610-146977
TEST.END_NOTES:
TEST.VALUE:DKOsalRecursiveMutex.<<GLOBAL>>.(cl).dk::osal::RecursiveMutex.dk::osal::RecursiveMutex.<<constructor>>.RecursiveMutex().<<call>>:0
TEST.VALUE:uut_prototype_stubs.pthread_mutex_destroy.return:1
TEST.END

-- Test Case: DeInitialization_successful
TEST.UNIT:DKOsalRecursiveMutex
TEST.SUBPROGRAM:(cl)dk::osal::RecursiveMutex::~RecursiveMutex
TEST.NEW
TEST.NAME:DeInitialization_successful
TEST.NOTES:
Requirement_AU29610-146977
TEST.END_NOTES:
TEST.VALUE:DKOsalRecursiveMutex.<<GLOBAL>>.(cl).dk::osal::RecursiveMutex.dk::osal::RecursiveMutex.<<constructor>>.RecursiveMutex().<<call>>:0
TEST.END
