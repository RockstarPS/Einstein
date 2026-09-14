-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : RUNTIME_THREADPOOL_UT
-- Unit(s) Under Test: dk_runtime_thread_pool
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

-- Unit: dk_runtime_thread_pool

-- Subprogram: (cl)dk::runtime::core::ThreadPool::ThreadPool

-- Test Case: 01_Initialization
TEST.UNIT:dk_runtime_thread_pool
TEST.SUBPROGRAM:(cl)dk::runtime::core::ThreadPool::ThreadPool
TEST.NEW
TEST.NAME:01_Initialization
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.FLOW
  dk_runtime_thread_pool.cpp.(cl)dk::runtime::core::ThreadPool::ThreadPool
  dk_runtime_thread_pool.cpp.(cl)dk::runtime::core::ThreadPool::ThreadPool
TEST.END_FLOW
TEST.END

-- Subprogram: (cl)dk::runtime::core::ThreadPool::getIsRunning

-- Test Case: 01_Status_check_failed
TEST.UNIT:dk_runtime_thread_pool
TEST.SUBPROGRAM:(cl)dk::runtime::core::ThreadPool::getIsRunning
TEST.NEW
TEST.NAME:01_Status_check_failed
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_thread_pool.<<GLOBAL>>.(cl).dk::runtime::core::ThreadPool.dk::runtime::core::ThreadPool.<<constructor>>.ThreadPool().<<call>>:0
TEST.VALUE:dk_runtime_thread_pool.<<GLOBAL>>.(cl).dk::runtime::core::ThreadPool.dk::runtime::core::ThreadPool.mSize:0
TEST.VALUE:dk_runtime_thread_pool.(cl)dk::runtime::core::ThreadPool::getIsRunning.tid:0
TEST.EXPECTED:dk_runtime_thread_pool.(cl)dk::runtime::core::ThreadPool::getIsRunning.return:false
TEST.END

-- Test Case: 02_Status_check_success
TEST.UNIT:dk_runtime_thread_pool
TEST.SUBPROGRAM:(cl)dk::runtime::core::ThreadPool::getIsRunning
TEST.NEW
TEST.NAME:02_Status_check_success
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_thread_pool.<<GLOBAL>>.(cl).dk::runtime::core::ThreadPool.dk::runtime::core::ThreadPool.<<constructor>>.ThreadPool().<<call>>:0
TEST.VALUE:dk_runtime_thread_pool.<<GLOBAL>>.(cl).dk::runtime::core::ThreadPool.dk::runtime::core::ThreadPool.mSize:5
TEST.VALUE:dk_runtime_thread_pool.(cl)dk::runtime::core::ThreadPool::getIsRunning.tid:0
TEST.FLOW
  dk_runtime_thread_pool.cpp.(cl)dk::runtime::core::ThreadPool::getIsRunning
  uut_prototype_stubs.std::mutex::lock
  uut_prototype_stubs.std::mutex::unlock
  dk_runtime_thread_pool.cpp.(cl)dk::runtime::core::ThreadPool::getIsRunning
TEST.END_FLOW
TEST.END

-- Subprogram: (cl)dk::runtime::core::ThreadPool::size

-- Test Case: 01_Get_size
TEST.UNIT:dk_runtime_thread_pool
TEST.SUBPROGRAM:(cl)dk::runtime::core::ThreadPool::size
TEST.NEW
TEST.NAME:01_Get_size
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_thread_pool.<<GLOBAL>>.(cl).dk::runtime::core::ThreadPool.dk::runtime::core::ThreadPool.<<constructor>>.ThreadPool().<<call>>:0
TEST.FLOW
  dk_runtime_thread_pool.cpp.(cl)dk::runtime::core::ThreadPool::size
  dk_runtime_thread_pool.cpp.(cl)dk::runtime::core::ThreadPool::size
TEST.END_FLOW
TEST.END

-- Subprogram: (cl)dk::runtime::core::ThreadPool::start

-- Test Case: 01_Start_failed
TEST.UNIT:dk_runtime_thread_pool
TEST.SUBPROGRAM:(cl)dk::runtime::core::ThreadPool::start
TEST.NEW
TEST.NAME:01_Start_failed
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_thread_pool.<<GLOBAL>>.(cl).dk::runtime::core::ThreadPool.dk::runtime::core::ThreadPool.<<constructor>>.ThreadPool().<<call>>:0
TEST.VALUE:dk_runtime_thread_pool.<<GLOBAL>>.(cl).dk::runtime::core::ThreadPool.dk::runtime::core::ThreadPool.mSize:0
TEST.VALUE:dk_runtime_thread_pool.(cl)dk::runtime::core::ThreadPool::start.tid:0
TEST.FLOW
  dk_runtime_thread_pool.cpp.(cl)dk::runtime::core::ThreadPool::start
  dk_runtime_thread_pool.cpp.(cl)dk::runtime::core::ThreadPool::start
TEST.END_FLOW
TEST.END

-- Test Case: 02_Start_success
TEST.UNIT:dk_runtime_thread_pool
TEST.SUBPROGRAM:(cl)dk::runtime::core::ThreadPool::start
TEST.NEW
TEST.NAME:02_Start_success
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_thread_pool.<<GLOBAL>>.(cl).dk::runtime::core::ThreadPool.dk::runtime::core::ThreadPool.<<constructor>>.ThreadPool().<<call>>:0
TEST.VALUE:dk_runtime_thread_pool.<<GLOBAL>>.(cl).dk::runtime::core::ThreadPool.dk::runtime::core::ThreadPool.mSize:5
TEST.VALUE:dk_runtime_thread_pool.(cl)dk::runtime::core::ThreadPool::start.tid:0
TEST.FLOW
  dk_runtime_thread_pool.cpp.(cl)dk::runtime::core::ThreadPool::start
  uut_prototype_stubs.std::mutex::lock
  uut_prototype_stubs.std::mutex::unlock
  uut_prototype_stubs.dk::osal::Thread::start
  dk_runtime_thread_pool.cpp.(cl)dk::runtime::core::ThreadPool::start
TEST.END_FLOW
TEST.END

-- Subprogram: (cl)dk::runtime::core::ThreadPool::stop

-- Test Case: 01_Stop_failed
TEST.UNIT:dk_runtime_thread_pool
TEST.SUBPROGRAM:(cl)dk::runtime::core::ThreadPool::stop
TEST.NEW
TEST.NAME:01_Stop_failed
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_thread_pool.<<GLOBAL>>.(cl).dk::runtime::core::ThreadPool.dk::runtime::core::ThreadPool.<<constructor>>.ThreadPool().<<call>>:0
TEST.VALUE:dk_runtime_thread_pool.<<GLOBAL>>.(cl).dk::runtime::core::ThreadPool.dk::runtime::core::ThreadPool.mSize:0
TEST.VALUE:dk_runtime_thread_pool.(cl)dk::runtime::core::ThreadPool::stop.tid:0
TEST.FLOW
  dk_runtime_thread_pool.cpp.(cl)dk::runtime::core::ThreadPool::stop
  dk_runtime_thread_pool.cpp.(cl)dk::runtime::core::ThreadPool::stop
TEST.END_FLOW
TEST.END

-- Test Case: 02_Stop_success
TEST.UNIT:dk_runtime_thread_pool
TEST.SUBPROGRAM:(cl)dk::runtime::core::ThreadPool::stop
TEST.NEW
TEST.NAME:02_Stop_success
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_thread_pool.<<GLOBAL>>.(cl).dk::runtime::core::ThreadPool.dk::runtime::core::ThreadPool.<<constructor>>.ThreadPool().<<call>>:0
TEST.VALUE:dk_runtime_thread_pool.<<GLOBAL>>.(cl).dk::runtime::core::ThreadPool.dk::runtime::core::ThreadPool.mSize:5
TEST.VALUE:dk_runtime_thread_pool.(cl)dk::runtime::core::ThreadPool::stop.tid:0
TEST.FLOW
  dk_runtime_thread_pool.cpp.(cl)dk::runtime::core::ThreadPool::stop
  uut_prototype_stubs.std::mutex::lock
  uut_prototype_stubs.std::mutex::unlock
  uut_prototype_stubs.dk::osal::Thread::join
  dk_runtime_thread_pool.cpp.(cl)dk::runtime::core::ThreadPool::stop
TEST.END_FLOW
TEST.END
