-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : OSAL_MUTEX_LOCK_UT
-- Unit(s) Under Test: DKOsalMutexLock
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

-- Unit: DKOsalMutexLock

-- Subprogram: (cl)dk::osal::MutexLock::MutexLock(dk::osal::Mutex&)

-- Test Case: Initialization
TEST.UNIT:DKOsalMutexLock
TEST.SUBPROGRAM:(cl)dk::osal::MutexLock::MutexLock(dk::osal::Mutex&)
TEST.NEW
TEST.NAME:Initialization
TEST.NOTES:
Requirement_AU29610-146972
TEST.END_NOTES:
TEST.END

-- Subprogram: (cl)dk::osal::MutexLock::MutexLock(dk::osal::RecursiveMutex&)

-- Test Case: Initialization
TEST.UNIT:DKOsalMutexLock
TEST.SUBPROGRAM:(cl)dk::osal::MutexLock::MutexLock(dk::osal::RecursiveMutex&)
TEST.NEW
TEST.NAME:Initialization
TEST.NOTES:
Requirement_AU29610-146972
TEST.END_NOTES:
TEST.END

-- Subprogram: (cl)dk::osal::MutexLock::clearFlag

-- Test Case: Reset_to_false
TEST.UNIT:DKOsalMutexLock
TEST.SUBPROGRAM:(cl)dk::osal::MutexLock::clearFlag
TEST.NEW
TEST.NAME:Reset_to_false
TEST.NOTES:
Requirement_AU29610-146972
TEST.END_NOTES:
TEST.VALUE:DKOsalMutexLock.<<GLOBAL>>.(cl).dk::osal::MutexLock.dk::osal::MutexLock.<<constructor>>.MutexLock(dk::osal::Mutex&).<<call>>:0
TEST.END

-- Subprogram: (cl)dk::osal::MutexLock::testFlag

-- Test Case: Return_flag_false
TEST.UNIT:DKOsalMutexLock
TEST.SUBPROGRAM:(cl)dk::osal::MutexLock::testFlag
TEST.NEW
TEST.NAME:Return_flag_false
TEST.NOTES:
Requirement_AU29610-146972
TEST.END_NOTES:
TEST.VALUE:DKOsalMutexLock.<<GLOBAL>>.(cl).dk::osal::MutexLock.dk::osal::MutexLock.<<constructor>>.MutexLock(dk::osal::Mutex&).<<call>>:0
TEST.VALUE:DKOsalMutexLock.<<GLOBAL>>.(cl).dk::osal::MutexLock.dk::osal::MutexLock.mFlag:false
TEST.EXPECTED:DKOsalMutexLock.(cl)dk::osal::MutexLock::testFlag.return:false
TEST.END

-- Test Case: Return_flag_true
TEST.UNIT:DKOsalMutexLock
TEST.SUBPROGRAM:(cl)dk::osal::MutexLock::testFlag
TEST.NEW
TEST.NAME:Return_flag_true
TEST.NOTES:
Requirement_AU29610-146972
TEST.END_NOTES:
TEST.VALUE:DKOsalMutexLock.<<GLOBAL>>.(cl).dk::osal::MutexLock.dk::osal::MutexLock.<<constructor>>.MutexLock(dk::osal::Mutex&).<<call>>:0
TEST.VALUE:DKOsalMutexLock.<<GLOBAL>>.(cl).dk::osal::MutexLock.dk::osal::MutexLock.mFlag:true
TEST.EXPECTED:DKOsalMutexLock.(cl)dk::osal::MutexLock::testFlag.return:true
TEST.END

-- Subprogram: (cl)dk::osal::MutexLock::~MutexLock

-- Test Case: Mutex_type
TEST.UNIT:DKOsalMutexLock
TEST.SUBPROGRAM:(cl)dk::osal::MutexLock::~MutexLock
TEST.NEW
TEST.NAME:Mutex_type
TEST.NOTES:
Requirement_AU29610-146972
TEST.END_NOTES:
TEST.VALUE:DKOsalMutexLock.<<GLOBAL>>.(cl).dk::osal::MutexLock.dk::osal::MutexLock.<<constructor>>.MutexLock(dk::osal::Mutex&).<<call>>:0
TEST.VALUE:DKOsalMutexLock.<<GLOBAL>>.(cl).dk::osal::MutexLock.dk::osal::MutexLock.mMutexType:1
TEST.END

-- Test Case: RecursiveMutex_type
TEST.UNIT:DKOsalMutexLock
TEST.SUBPROGRAM:(cl)dk::osal::MutexLock::~MutexLock
TEST.NEW
TEST.NAME:RecursiveMutex_type
TEST.NOTES:
Requirement_AU29610-146972
TEST.END_NOTES:
TEST.VALUE:DKOsalMutexLock.<<GLOBAL>>.(cl).dk::osal::MutexLock.dk::osal::MutexLock.<<constructor>>.MutexLock(dk::osal::Mutex&).<<call>>:0
TEST.VALUE:DKOsalMutexLock.<<GLOBAL>>.(cl).dk::osal::MutexLock.dk::osal::MutexLock.mMutexType:2
TEST.END

-- Test Case: Wrong_type
TEST.UNIT:DKOsalMutexLock
TEST.SUBPROGRAM:(cl)dk::osal::MutexLock::~MutexLock
TEST.NEW
TEST.NAME:Wrong_type
TEST.NOTES:
Requirement_AU29610-146972
TEST.END_NOTES:
TEST.VALUE:DKOsalMutexLock.<<GLOBAL>>.(cl).dk::osal::MutexLock.dk::osal::MutexLock.<<constructor>>.MutexLock(dk::osal::Mutex&).<<call>>:0
TEST.VALUE:DKOsalMutexLock.<<GLOBAL>>.(cl).dk::osal::MutexLock.dk::osal::MutexLock.mMutexType:0
TEST.END
