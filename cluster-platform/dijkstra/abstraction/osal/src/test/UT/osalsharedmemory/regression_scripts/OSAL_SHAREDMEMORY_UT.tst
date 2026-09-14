-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : OSAL_SHAREDMEMORY_UT
-- Unit(s) Under Test: DKOsalSharedMemory
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

-- Unit: DKOsalSharedMemory

-- Subprogram: (cl)dk::osal::SharedMemory::SharedMemory

-- Test Case: Initialize
TEST.UNIT:DKOsalSharedMemory
TEST.SUBPROGRAM:(cl)dk::osal::SharedMemory::SharedMemory
TEST.NEW
TEST.NAME:Initialize
TEST.NOTES:
Requirement_AU29610-146980
TEST.END_NOTES:
TEST.END

-- Subprogram: (cl)dk::osal::SharedMemory::close

-- Test Case: Close_munmap_error
TEST.UNIT:DKOsalSharedMemory
TEST.SUBPROGRAM:(cl)dk::osal::SharedMemory::close
TEST.NEW
TEST.NAME:Close_munmap_error
TEST.NOTES:
Requirement_AU29610-146980
TEST.END_NOTES:
TEST.VALUE:DKOsalSharedMemory.<<GLOBAL>>.(cl).dk::osal::SharedMemory.dk::osal::SharedMemory.<<constructor>>.SharedMemory().<<call>>:0
TEST.VALUE:DKOsalSharedMemory.<<GLOBAL>>.(cl).dk::osal::SharedMemory.dk::osal::SharedMemory.m_fd:1
TEST.VALUE:DKOsalSharedMemory.<<GLOBAL>>.(cl).dk::osal::SharedMemory.dk::osal::SharedMemory.m_addr:<<malloc 1>>
TEST.VALUE:DKOsalSharedMemory.<<GLOBAL>>.(cl).dk::osal::SharedMemory.dk::osal::SharedMemory.m_addr:""
TEST.VALUE:uut_prototype_stubs.munmap.return:1
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:4
TEST.END

-- Test Case: Close_sharedmemory
TEST.UNIT:DKOsalSharedMemory
TEST.SUBPROGRAM:(cl)dk::osal::SharedMemory::close
TEST.NEW
TEST.NAME:Close_sharedmemory
TEST.NOTES:
Requirement_AU29610-146980
TEST.END_NOTES:
TEST.VALUE:DKOsalSharedMemory.<<GLOBAL>>.(cl).dk::osal::SharedMemory.dk::osal::SharedMemory.<<constructor>>.SharedMemory().<<call>>:0
TEST.VALUE:DKOsalSharedMemory.<<GLOBAL>>.(cl).dk::osal::SharedMemory.dk::osal::SharedMemory.m_fd:1
TEST.VALUE:DKOsalSharedMemory.<<GLOBAL>>.(cl).dk::osal::SharedMemory.dk::osal::SharedMemory.m_addr:<<malloc 1>>
TEST.VALUE:DKOsalSharedMemory.<<GLOBAL>>.(cl).dk::osal::SharedMemory.dk::osal::SharedMemory.m_addr:""
TEST.END

-- Test Case: Close_with_invalid_fd
TEST.UNIT:DKOsalSharedMemory
TEST.SUBPROGRAM:(cl)dk::osal::SharedMemory::close
TEST.NEW
TEST.NAME:Close_with_invalid_fd
TEST.NOTES:
Requirement_AU29610-146980
TEST.END_NOTES:
TEST.VALUE:DKOsalSharedMemory.<<GLOBAL>>.(cl).dk::osal::SharedMemory.dk::osal::SharedMemory.<<constructor>>.SharedMemory().<<call>>:0
TEST.VALUE:DKOsalSharedMemory.<<GLOBAL>>.(cl).dk::osal::SharedMemory.dk::osal::SharedMemory.m_fd:-1
TEST.VALUE:DKOsalSharedMemory.<<GLOBAL>>.(cl).dk::osal::SharedMemory.dk::osal::SharedMemory.m_addr:<<malloc 1>>
TEST.VALUE:DKOsalSharedMemory.<<GLOBAL>>.(cl).dk::osal::SharedMemory.dk::osal::SharedMemory.m_addr:""
TEST.END

-- Test Case: Close_with_null_address
TEST.UNIT:DKOsalSharedMemory
TEST.SUBPROGRAM:(cl)dk::osal::SharedMemory::close
TEST.NEW
TEST.NAME:Close_with_null_address
TEST.NOTES:
Requirement_AU29610-146980
TEST.END_NOTES:
TEST.VALUE:DKOsalSharedMemory.<<GLOBAL>>.(cl).dk::osal::SharedMemory.dk::osal::SharedMemory.<<constructor>>.SharedMemory().<<call>>:0
TEST.END

-- Subprogram: (cl)dk::osal::SharedMemory::create

-- Test Case: Create_sharedmemory
TEST.UNIT:DKOsalSharedMemory
TEST.SUBPROGRAM:(cl)dk::osal::SharedMemory::create
TEST.NEW
TEST.NAME:Create_sharedmemory
TEST.NOTES:
Requirement_AU29610-146980
TEST.END_NOTES:
TEST.STUB:DKOsalSharedMemory.(cl)dk::osal::SharedMemory::create
TEST.VALUE:DKOsalSharedMemory.<<GLOBAL>>.(cl).dk::osal::SharedMemory.dk::osal::SharedMemory.<<constructor>>.SharedMemory().<<call>>:0
TEST.EXPECTED:DKOsalSharedMemory.(cl)dk::osal::SharedMemory::create.return:0
TEST.END

-- Subprogram: (cl)dk::osal::SharedMemory::createOrOpen

-- Test Case: Empty_size_fstat_failed
TEST.UNIT:DKOsalSharedMemory
TEST.SUBPROGRAM:(cl)dk::osal::SharedMemory::createOrOpen
TEST.NEW
TEST.NAME:Empty_size_fstat_failed
TEST.NOTES:
Requirement_AU29610-146980
TEST.END_NOTES:
TEST.STUB:DKOsalSharedMemory.(cl)dk::osal::SharedMemory::createOrOpen
TEST.VALUE:DKOsalSharedMemory.<<GLOBAL>>.(cl).dk::osal::SharedMemory.dk::osal::SharedMemory.<<constructor>>.SharedMemory().<<call>>:0
TEST.VALUE:DKOsalSharedMemory.(cl)dk::osal::SharedMemory::createOrOpen.size:0
TEST.VALUE:DKOsalSharedMemory.(cl)dk::osal::SharedMemory::createOrOpen.doCreate:false
TEST.VALUE:uut_prototype_stubs.fstat.VCAST_PARAM_2[0].st_size:0
TEST.EXPECTED:DKOsalSharedMemory.(cl)dk::osal::SharedMemory::createOrOpen.return:4
TEST.END

-- Test Case: Fstat_failed
TEST.UNIT:DKOsalSharedMemory
TEST.SUBPROGRAM:(cl)dk::osal::SharedMemory::createOrOpen
TEST.NEW
TEST.NAME:Fstat_failed
TEST.NOTES:
Requirement_AU29610-146980
TEST.END_NOTES:
TEST.STUB:DKOsalSharedMemory.(cl)dk::osal::SharedMemory::createOrOpen
TEST.VALUE:DKOsalSharedMemory.<<GLOBAL>>.(cl).dk::osal::SharedMemory.dk::osal::SharedMemory.<<constructor>>.SharedMemory().<<call>>:0
TEST.VALUE:DKOsalSharedMemory.(cl)dk::osal::SharedMemory::createOrOpen.size:0
TEST.VALUE:DKOsalSharedMemory.(cl)dk::osal::SharedMemory::createOrOpen.doCreate:false
TEST.VALUE:uut_prototype_stubs.fstat.return:-1
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:0
TEST.EXPECTED:DKOsalSharedMemory.(cl)dk::osal::SharedMemory::createOrOpen.return:9
TEST.END

-- Test Case: Ftruncate_failed
TEST.UNIT:DKOsalSharedMemory
TEST.SUBPROGRAM:(cl)dk::osal::SharedMemory::createOrOpen
TEST.NEW
TEST.NAME:Ftruncate_failed
TEST.NOTES:
Requirement_AU29610-146980
TEST.END_NOTES:
TEST.VALUE:DKOsalSharedMemory.<<GLOBAL>>.(cl).dk::osal::SharedMemory.dk::osal::SharedMemory.<<constructor>>.SharedMemory().<<call>>:0
TEST.VALUE:DKOsalSharedMemory.(cl)dk::osal::SharedMemory::createOrOpen.size:1
TEST.VALUE:DKOsalSharedMemory.(cl)dk::osal::SharedMemory::createOrOpen.doCreate:false
TEST.VALUE:uut_prototype_stubs.ftruncate.return:-1
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:9
TEST.EXPECTED:DKOsalSharedMemory.(cl)dk::osal::SharedMemory::createOrOpen.return:9
TEST.END

-- Test Case: Ftruncate_failed_doCreate
TEST.UNIT:DKOsalSharedMemory
TEST.SUBPROGRAM:(cl)dk::osal::SharedMemory::createOrOpen
TEST.NEW
TEST.NAME:Ftruncate_failed_doCreate
TEST.NOTES:
Requirement_AU29610-146980
TEST.END_NOTES:
TEST.VALUE:DKOsalSharedMemory.<<GLOBAL>>.(cl).dk::osal::SharedMemory.dk::osal::SharedMemory.<<constructor>>.SharedMemory().<<call>>:0
TEST.VALUE:DKOsalSharedMemory.(cl)dk::osal::SharedMemory::createOrOpen.size:1
TEST.VALUE:DKOsalSharedMemory.(cl)dk::osal::SharedMemory::createOrOpen.doCreate:true
TEST.VALUE:uut_prototype_stubs.ftruncate.return:-1
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:9
TEST.EXPECTED:DKOsalSharedMemory.(cl)dk::osal::SharedMemory::createOrOpen.return:9
TEST.END

-- Test Case: Mmap_failed
TEST.UNIT:DKOsalSharedMemory
TEST.SUBPROGRAM:(cl)dk::osal::SharedMemory::createOrOpen
TEST.NEW
TEST.NAME:Mmap_failed
TEST.NOTES:
Requirement_AU29610-146980
TEST.END_NOTES:
TEST.VALUE:DKOsalSharedMemory.<<GLOBAL>>.(cl).dk::osal::SharedMemory.dk::osal::SharedMemory.<<constructor>>.SharedMemory().<<call>>:0
TEST.VALUE:DKOsalSharedMemory.(cl)dk::osal::SharedMemory::createOrOpen.doCreate:false
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:0
TEST.EXPECTED:DKOsalSharedMemory.(cl)dk::osal::SharedMemory::createOrOpen.return:9
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.mmap.return
<<uut_prototype_stubs.mmap.return>> = ( (void *) -1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: Mmap_failed_doCreate
TEST.UNIT:DKOsalSharedMemory
TEST.SUBPROGRAM:(cl)dk::osal::SharedMemory::createOrOpen
TEST.NEW
TEST.NAME:Mmap_failed_doCreate
TEST.NOTES:
Requirement_AU29610-146980
TEST.END_NOTES:
TEST.STUB:DKOsalSharedMemory.(cl)dk::osal::SharedMemory::createOrOpen
TEST.VALUE:DKOsalSharedMemory.<<GLOBAL>>.(cl).dk::osal::SharedMemory.dk::osal::SharedMemory.<<constructor>>.SharedMemory().<<call>>:0
TEST.VALUE:DKOsalSharedMemory.(cl)dk::osal::SharedMemory::createOrOpen.doCreate:true
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:0
TEST.EXPECTED:DKOsalSharedMemory.(cl)dk::osal::SharedMemory::createOrOpen.return:9
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.mmap.return
<<uut_prototype_stubs.mmap.return>> = ( (void *) -1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: Mmap_shm_open
TEST.UNIT:DKOsalSharedMemory
TEST.SUBPROGRAM:(cl)dk::osal::SharedMemory::createOrOpen
TEST.NEW
TEST.NAME:Mmap_shm_open
TEST.NOTES:
Requirement_AU29610-146980
TEST.END_NOTES:
TEST.VALUE:DKOsalSharedMemory.<<GLOBAL>>.(cl).dk::osal::SharedMemory.dk::osal::SharedMemory.<<constructor>>.SharedMemory().<<call>>:0
TEST.VALUE:DKOsalSharedMemory.(cl)dk::osal::SharedMemory::createOrOpen.size:1
TEST.VALUE:DKOsalSharedMemory.(cl)dk::osal::SharedMemory::createOrOpen.doCreate:true
TEST.VALUE:uut_prototype_stubs.shm_open.return:-1
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:9
TEST.EXPECTED:DKOsalSharedMemory.(cl)dk::osal::SharedMemory::createOrOpen.return:9
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.mmap.return
<<uut_prototype_stubs.mmap.return>> = ( (void *) -1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: Mmap_true
TEST.UNIT:DKOsalSharedMemory
TEST.SUBPROGRAM:(cl)dk::osal::SharedMemory::createOrOpen
TEST.NEW
TEST.NAME:Mmap_true
TEST.NOTES:
Requirement_AU29610-146980
TEST.END_NOTES:
TEST.VALUE:DKOsalSharedMemory.<<GLOBAL>>.(cl).dk::osal::SharedMemory.dk::osal::SharedMemory.<<constructor>>.SharedMemory().<<call>>:0
TEST.VALUE:DKOsalSharedMemory.(cl)dk::osal::SharedMemory::createOrOpen.doCreate:true
TEST.VALUE:uut_prototype_stubs.shm_open.return:0
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:0
TEST.EXPECTED:DKOsalSharedMemory.(cl)dk::osal::SharedMemory::createOrOpen.return:9
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.mmap.return
<<uut_prototype_stubs.mmap.return>> = ( (void *) -1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: Open_with_non_null_address
TEST.UNIT:DKOsalSharedMemory
TEST.SUBPROGRAM:(cl)dk::osal::SharedMemory::createOrOpen
TEST.NEW
TEST.NAME:Open_with_non_null_address
TEST.NOTES:
Requirement_AU29610-146980
TEST.END_NOTES:
TEST.VALUE:DKOsalSharedMemory.<<GLOBAL>>.(cl).dk::osal::SharedMemory.dk::osal::SharedMemory.<<constructor>>.SharedMemory().<<call>>:0
TEST.VALUE:DKOsalSharedMemory.<<GLOBAL>>.(cl).dk::osal::SharedMemory.dk::osal::SharedMemory.m_addr:<<malloc 7>>
TEST.VALUE:DKOsalSharedMemory.<<GLOBAL>>.(cl).dk::osal::SharedMemory.dk::osal::SharedMemory.m_addr:"test"
TEST.VALUE:DKOsalSharedMemory.(cl)dk::osal::SharedMemory::createOrOpen.size:0
TEST.VALUE:DKOsalSharedMemory.(cl)dk::osal::SharedMemory::createOrOpen.doCreate:false
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:0
TEST.EXPECTED:DKOsalSharedMemory.(cl)dk::osal::SharedMemory::createOrOpen.return:0
TEST.END

-- Test Case: Shm_open_failed
TEST.UNIT:DKOsalSharedMemory
TEST.SUBPROGRAM:(cl)dk::osal::SharedMemory::createOrOpen
TEST.NEW
TEST.NAME:Shm_open_failed
TEST.NOTES:
Requirement_AU29610-146980
TEST.END_NOTES:
TEST.STUB:DKOsalSharedMemory.(cl)dk::osal::SharedMemory::createOrOpen
TEST.VALUE:DKOsalSharedMemory.<<GLOBAL>>.(cl).dk::osal::SharedMemory.dk::osal::SharedMemory.<<constructor>>.SharedMemory().<<call>>:0
TEST.VALUE:DKOsalSharedMemory.(cl)dk::osal::SharedMemory::createOrOpen.doCreate:false
TEST.VALUE:uut_prototype_stubs.shm_open.return:-1
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:0
TEST.EXPECTED:DKOsalSharedMemory.(cl)dk::osal::SharedMemory::createOrOpen.return:9
TEST.END

-- Test Case: Shm_open_failed_ENOENT
TEST.UNIT:DKOsalSharedMemory
TEST.SUBPROGRAM:(cl)dk::osal::SharedMemory::createOrOpen
TEST.NEW
TEST.NAME:Shm_open_failed_ENOENT
TEST.NOTES:
Requirement_AU29610-146980
TEST.END_NOTES:
TEST.STUB:DKOsalSharedMemory.(cl)dk::osal::SharedMemory::createOrOpen
TEST.VALUE:DKOsalSharedMemory.<<GLOBAL>>.(cl).dk::osal::SharedMemory.dk::osal::SharedMemory.<<constructor>>.SharedMemory().<<call>>:0
TEST.VALUE:DKOsalSharedMemory.(cl)dk::osal::SharedMemory::createOrOpen.doCreate:false
TEST.VALUE:uut_prototype_stubs.shm_open.return:-1
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:2
TEST.EXPECTED:DKOsalSharedMemory.(cl)dk::osal::SharedMemory::createOrOpen.return:4
TEST.END

-- Test Case: Shm_open_failed_doCreate
TEST.UNIT:DKOsalSharedMemory
TEST.SUBPROGRAM:(cl)dk::osal::SharedMemory::createOrOpen
TEST.NEW
TEST.NAME:Shm_open_failed_doCreate
TEST.NOTES:
Requirement_AU29610-146980
TEST.END_NOTES:
TEST.STUB:DKOsalSharedMemory.(cl)dk::osal::SharedMemory::createOrOpen
TEST.VALUE:DKOsalSharedMemory.<<GLOBAL>>.(cl).dk::osal::SharedMemory.dk::osal::SharedMemory.<<constructor>>.SharedMemory().<<call>>:0
TEST.VALUE:DKOsalSharedMemory.(cl)dk::osal::SharedMemory::createOrOpen.doCreate:true
TEST.VALUE:uut_prototype_stubs.shm_open.return:-1
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:0
TEST.EXPECTED:DKOsalSharedMemory.(cl)dk::osal::SharedMemory::createOrOpen.return:9
TEST.END

-- Test Case: Size_not_zero
TEST.UNIT:DKOsalSharedMemory
TEST.SUBPROGRAM:(cl)dk::osal::SharedMemory::createOrOpen
TEST.NEW
TEST.NAME:Size_not_zero
TEST.NOTES:
Requirement_AU29610-146980
TEST.END_NOTES:
TEST.STUB:DKOsalSharedMemory.(cl)dk::osal::SharedMemory::createOrOpen
TEST.VALUE:DKOsalSharedMemory.<<GLOBAL>>.(cl).dk::osal::SharedMemory.dk::osal::SharedMemory.<<constructor>>.SharedMemory().<<call>>:0
TEST.VALUE:DKOsalSharedMemory.(cl)dk::osal::SharedMemory::createOrOpen.size:1
TEST.VALUE:DKOsalSharedMemory.(cl)dk::osal::SharedMemory::createOrOpen.doCreate:false
TEST.VALUE:uut_prototype_stubs.ftruncate.return:1
TEST.EXPECTED:DKOsalSharedMemory.(cl)dk::osal::SharedMemory::createOrOpen.return:0
TEST.END

-- Test Case: Size_not_zero.001
TEST.UNIT:DKOsalSharedMemory
TEST.SUBPROGRAM:(cl)dk::osal::SharedMemory::createOrOpen
TEST.NEW
TEST.NAME:Size_not_zero.001
TEST.NOTES:
Requirement_AU29610-146980
TEST.END_NOTES:
TEST.STUB:DKOsalSharedMemory.(cl)dk::osal::SharedMemory::createOrOpen
TEST.VALUE:DKOsalSharedMemory.<<GLOBAL>>.(cl).dk::osal::SharedMemory.dk::osal::SharedMemory.<<constructor>>.SharedMemory().<<call>>:0
TEST.VALUE:DKOsalSharedMemory.<<GLOBAL>>.(cl).dk::osal::SharedMemory.dk::osal::SharedMemory.m_size:1
TEST.VALUE:DKOsalSharedMemory.(cl)dk::osal::SharedMemory::createOrOpen.size:1
TEST.VALUE:DKOsalSharedMemory.(cl)dk::osal::SharedMemory::createOrOpen.doCreate:false
TEST.VALUE:uut_prototype_stubs.ftruncate.return:1
TEST.VALUE:uut_prototype_stubs.fstat.VCAST_PARAM_2[0].st_size:1
TEST.VALUE:uut_prototype_stubs.fstat.return:1
TEST.EXPECTED:DKOsalSharedMemory.(cl)dk::osal::SharedMemory::createOrOpen.return:0
TEST.END

-- Test Case: msize_not_zero
TEST.UNIT:DKOsalSharedMemory
TEST.SUBPROGRAM:(cl)dk::osal::SharedMemory::createOrOpen
TEST.NEW
TEST.NAME:msize_not_zero
TEST.NOTES:
Requirement_AU29610-146980
TEST.END_NOTES:
TEST.STUB:DKOsalSharedMemory.(cl)dk::osal::SharedMemory::createOrOpen
TEST.VALUE:DKOsalSharedMemory.<<GLOBAL>>.(cl).dk::osal::SharedMemory.dk::osal::SharedMemory.<<constructor>>.SharedMemory().<<call>>:0
TEST.VALUE:DKOsalSharedMemory.<<GLOBAL>>.(cl).dk::osal::SharedMemory.dk::osal::SharedMemory.m_size:1
TEST.VALUE:DKOsalSharedMemory.(cl)dk::osal::SharedMemory::createOrOpen.doCreate:false
TEST.VALUE:uut_prototype_stubs.fstat.VCAST_PARAM_2[0].st_size:1
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.mmap.return
<<uut_prototype_stubs.mmap.return>> = ( (void *) -1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::osal::SharedMemory::open(const char*const)dk::osal::Error

-- Test Case: CreateOrOpen_sharedmemory_of_zero_size
TEST.UNIT:DKOsalSharedMemory
TEST.SUBPROGRAM:(cl)dk::osal::SharedMemory::open(const char*const)dk::osal::Error
TEST.NEW
TEST.NAME:CreateOrOpen_sharedmemory_of_zero_size
TEST.NOTES:
Requirement_AU29610-146980
TEST.END_NOTES:
TEST.STUB:DKOsalSharedMemory.(cl)dk::osal::SharedMemory::createOrOpen
TEST.VALUE:DKOsalSharedMemory.(cl)dk::osal::SharedMemory::createOrOpen.return:9
TEST.EXPECTED:DKOsalSharedMemory.(cl)dk::osal::SharedMemory::open(const char*const)dk::osal::Error.return:9
TEST.END

-- Subprogram: (cl)dk::osal::SharedMemory::open(const char*const,const uint32_t)dk::osal::Error

-- Test Case: CreateOrOpen_sharedmemory_of_given_size
TEST.UNIT:DKOsalSharedMemory
TEST.SUBPROGRAM:(cl)dk::osal::SharedMemory::open(const char*const,const uint32_t)dk::osal::Error
TEST.NEW
TEST.NAME:CreateOrOpen_sharedmemory_of_given_size
TEST.NOTES:
Requirement_AU29610-146980
TEST.END_NOTES:
TEST.STUB:DKOsalSharedMemory.(cl)dk::osal::SharedMemory::createOrOpen
TEST.VALUE:DKOsalSharedMemory.(cl)dk::osal::SharedMemory::createOrOpen.return:0
TEST.EXPECTED:DKOsalSharedMemory.(cl)dk::osal::SharedMemory::open(const char*const,const uint32_t)dk::osal::Error.return:0
TEST.END

-- Subprogram: (cl)dk::osal::SharedMemory::pointer

-- Test Case: Return_the_address
TEST.UNIT:DKOsalSharedMemory
TEST.SUBPROGRAM:(cl)dk::osal::SharedMemory::pointer
TEST.NEW
TEST.NAME:Return_the_address
TEST.NOTES:
Requirement_AU29610-146980
TEST.END_NOTES:
TEST.VALUE:DKOsalSharedMemory.<<GLOBAL>>.(cl).dk::osal::SharedMemory.dk::osal::SharedMemory.<<constructor>>.SharedMemory().<<call>>:0
TEST.VALUE:DKOsalSharedMemory.<<GLOBAL>>.(cl).dk::osal::SharedMemory.dk::osal::SharedMemory.m_addr:<<malloc 1>>
TEST.VALUE:DKOsalSharedMemory.<<GLOBAL>>.(cl).dk::osal::SharedMemory.dk::osal::SharedMemory.m_addr:""
TEST.END

-- Subprogram: (cl)dk::osal::SharedMemory::remove

-- Test Case: Shm_unlink_failed
TEST.UNIT:DKOsalSharedMemory
TEST.SUBPROGRAM:(cl)dk::osal::SharedMemory::remove
TEST.NEW
TEST.NAME:Shm_unlink_failed
TEST.NOTES:
Requirement_AU29610-146980
TEST.END_NOTES:
TEST.STUB:DKOsalSharedMemory.(cl)dk::osal::SharedMemory::remove
TEST.VALUE:uut_prototype_stubs.shm_unlink.return:-1
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:0
TEST.EXPECTED:DKOsalSharedMemory.(cl)dk::osal::SharedMemory::remove.return:9
TEST.END

-- Test Case: Shm_unlink_failed_ENOENT
TEST.UNIT:DKOsalSharedMemory
TEST.SUBPROGRAM:(cl)dk::osal::SharedMemory::remove
TEST.NEW
TEST.NAME:Shm_unlink_failed_ENOENT
TEST.NOTES:
Requirement_AU29610-146980
TEST.END_NOTES:
TEST.STUB:DKOsalSharedMemory.(cl)dk::osal::SharedMemory::remove
TEST.VALUE:uut_prototype_stubs.shm_unlink.return:-1
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:2
TEST.EXPECTED:DKOsalSharedMemory.(cl)dk::osal::SharedMemory::remove.return:4
TEST.END

-- Test Case: Shm_unlink_success
TEST.UNIT:DKOsalSharedMemory
TEST.SUBPROGRAM:(cl)dk::osal::SharedMemory::remove
TEST.NEW
TEST.NAME:Shm_unlink_success
TEST.NOTES:
Requirement_AU29610-146980
TEST.END_NOTES:
TEST.STUB:DKOsalSharedMemory.(cl)dk::osal::SharedMemory::remove
TEST.EXPECTED:DKOsalSharedMemory.(cl)dk::osal::SharedMemory::remove.return:0
TEST.END

-- Subprogram: (cl)dk::osal::SharedMemory::size

-- Test Case: Return_the_size
TEST.UNIT:DKOsalSharedMemory
TEST.SUBPROGRAM:(cl)dk::osal::SharedMemory::size
TEST.NEW
TEST.NAME:Return_the_size
TEST.NOTES:
Requirement_AU29610-146980
TEST.END_NOTES:
TEST.STUB:DKOsalSharedMemory.(cl)dk::osal::SharedMemory::size
TEST.VALUE:DKOsalSharedMemory.<<GLOBAL>>.(cl).dk::osal::SharedMemory.dk::osal::SharedMemory.<<constructor>>.SharedMemory().<<call>>:0
TEST.VALUE:DKOsalSharedMemory.<<GLOBAL>>.(cl).dk::osal::SharedMemory.dk::osal::SharedMemory.m_size:1
TEST.EXPECTED:DKOsalSharedMemory.(cl)dk::osal::SharedMemory::size.return:1
TEST.END

-- Subprogram: (cl)dk::osal::SharedMemory::~SharedMemory

-- Test Case: DeInitialize
TEST.UNIT:DKOsalSharedMemory
TEST.SUBPROGRAM:(cl)dk::osal::SharedMemory::~SharedMemory
TEST.NEW
TEST.NAME:DeInitialize
TEST.NOTES:
Requirement_AU29610-146980
TEST.END_NOTES:
TEST.VALUE:DKOsalSharedMemory.<<GLOBAL>>.(cl).dk::osal::SharedMemory.dk::osal::SharedMemory.<<constructor>>.SharedMemory().<<call>>:0
TEST.VALUE:DKOsalSharedMemory.<<GLOBAL>>.(cl).dk::osal::SharedMemory.dk::osal::SharedMemory.m_addr:<<malloc 15>>
TEST.VALUE:DKOsalSharedMemory.<<GLOBAL>>.(cl).dk::osal::SharedMemory.dk::osal::SharedMemory.m_addr:"DummyAddress"
TEST.END

-- Test Case: DeInitialize_with_null_address
TEST.UNIT:DKOsalSharedMemory
TEST.SUBPROGRAM:(cl)dk::osal::SharedMemory::~SharedMemory
TEST.NEW
TEST.NAME:DeInitialize_with_null_address
TEST.NOTES:
Requirement_AU29610-146980
TEST.END_NOTES:
TEST.VALUE:DKOsalSharedMemory.<<GLOBAL>>.(cl).dk::osal::SharedMemory.dk::osal::SharedMemory.<<constructor>>.SharedMemory().<<call>>:0
TEST.END
