-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : RUNTIME_SERIALIZER_UT
-- Unit(s) Under Test: dk_runtime_serializer
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

-- Unit: dk_runtime_serializer

-- Subprogram: (cl)dk::runtime::core::Serializer::Serializer

-- Test Case: 01_Initialization
TEST.UNIT:dk_runtime_serializer
TEST.SUBPROGRAM:(cl)dk::runtime::core::Serializer::Serializer
TEST.NEW
TEST.NAME:01_Initialization
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_serializer.(cl)dk::runtime::core::Serializer::Serializer.bufferShrinkThreshold:1
TEST.EXPECTED:dk_runtime_serializer.(cl)dk::runtime::core::Serializer::Serializer.bufferShrinkThreshold:1
TEST.FLOW
  dk_runtime_serializer.cpp.(cl)dk::runtime::core::Serializer::Serializer
  dk_runtime_serializer.cpp.(cl)dk::runtime::core::Serializer::Serializer
TEST.END_FLOW
TEST.END

-- Subprogram: (cl)dk::runtime::core::Serializer::getCapacity

-- Test Case: 01_Get_Capacity
TEST.UNIT:dk_runtime_serializer
TEST.SUBPROGRAM:(cl)dk::runtime::core::Serializer::getCapacity
TEST.NEW
TEST.NAME:01_Get_Capacity
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_serializer.<<GLOBAL>>.(cl).dk::runtime::core::Serializer.dk::runtime::core::Serializer.<<constructor>>.Serializer(uint32_t).<<call>>:0
TEST.FLOW
  dk_runtime_serializer.cpp.(cl)dk::runtime::core::Serializer::getCapacity
  dk_runtime_serializer.cpp.(cl)dk::runtime::core::Serializer::getCapacity
TEST.END_FLOW
TEST.END

-- Subprogram: (cl)dk::runtime::core::Serializer::getData

-- Test Case: 01_Get_Data
TEST.UNIT:dk_runtime_serializer
TEST.SUBPROGRAM:(cl)dk::runtime::core::Serializer::getData
TEST.NEW
TEST.NAME:01_Get_Data
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_serializer.<<GLOBAL>>.(cl).dk::runtime::core::Serializer.dk::runtime::core::Serializer.<<constructor>>.Serializer(uint32_t).bufferShrinkThreshold:1
TEST.VALUE:dk_runtime_serializer.<<GLOBAL>>.(cl).dk::runtime::core::Serializer.dk::runtime::core::Serializer.<<constructor>>.Serializer(uint32_t).<<call>>:0
TEST.FLOW
  dk_runtime_serializer.cpp.(cl)dk::runtime::core::Serializer::getData
  dk_runtime_serializer.cpp.(cl)dk::runtime::core::Serializer::getData
TEST.END_FLOW
TEST.END

-- Subprogram: (cl)dk::runtime::core::Serializer::getSize

-- Test Case: 01_Get_Size
TEST.UNIT:dk_runtime_serializer
TEST.SUBPROGRAM:(cl)dk::runtime::core::Serializer::getSize
TEST.NEW
TEST.NAME:01_Get_Size
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_serializer.<<GLOBAL>>.(cl).dk::runtime::core::Serializer.dk::runtime::core::Serializer.<<constructor>>.Serializer(uint32_t).bufferShrinkThreshold:1
TEST.VALUE:dk_runtime_serializer.<<GLOBAL>>.(cl).dk::runtime::core::Serializer.dk::runtime::core::Serializer.<<constructor>>.Serializer(uint32_t).<<call>>:0
TEST.FLOW
  dk_runtime_serializer.cpp.(cl)dk::runtime::core::Serializer::getSize
  dk_runtime_serializer.cpp.(cl)dk::runtime::core::Serializer::getSize
TEST.END_FLOW
TEST.END

-- Subprogram: (cl)dk::runtime::core::Serializer::reset

-- Test Case: 01_Capacity_large
TEST.UNIT:dk_runtime_serializer
TEST.SUBPROGRAM:(cl)dk::runtime::core::Serializer::reset
TEST.NEW
TEST.NAME:01_Capacity_large
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_serializer.<<GLOBAL>>.(cl).dk::runtime::core::Serializer.dk::runtime::core::Serializer.<<constructor>>.Serializer(uint32_t).<<call>>:0
TEST.VALUE:dk_runtime_serializer.<<GLOBAL>>.(cl).dk::runtime::core::Serializer.dk::runtime::core::Serializer.mData:<<malloc 2>>
TEST.VALUE:dk_runtime_serializer.<<GLOBAL>>.(cl).dk::runtime::core::Serializer.dk::runtime::core::Serializer.mData[0]:<<function 1>>
TEST.VALUE:dk_runtime_serializer.<<GLOBAL>>.(cl).dk::runtime::core::Serializer.dk::runtime::core::Serializer.mData[1]:<<function 1>>
TEST.VALUE:dk_runtime_serializer.<<GLOBAL>>.(cl).dk::runtime::core::Serializer.dk::runtime::core::Serializer.mShrinkCount:5
TEST.VALUE:dk_runtime_serializer.<<GLOBAL>>.(cl).dk::runtime::core::Serializer.dk::runtime::core::Serializer.mBufferShrinkThreshold:5
TEST.END

-- Test Case: 02_Capacity_small
TEST.UNIT:dk_runtime_serializer
TEST.SUBPROGRAM:(cl)dk::runtime::core::Serializer::reset
TEST.NEW
TEST.NAME:02_Capacity_small
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_serializer.<<GLOBAL>>.(cl).dk::runtime::core::Serializer.dk::runtime::core::Serializer.<<constructor>>.Serializer(uint32_t).<<call>>:0
TEST.VALUE:dk_runtime_serializer.<<GLOBAL>>.(cl).dk::runtime::core::Serializer.dk::runtime::core::Serializer.mShrinkCount:5
TEST.VALUE:dk_runtime_serializer.<<GLOBAL>>.(cl).dk::runtime::core::Serializer.dk::runtime::core::Serializer.mBufferShrinkThreshold:5
TEST.END

-- Test Case: 03_Reset_Shrinkcount
TEST.UNIT:dk_runtime_serializer
TEST.SUBPROGRAM:(cl)dk::runtime::core::Serializer::reset
TEST.NEW
TEST.NAME:03_Reset_Shrinkcount
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_serializer.<<GLOBAL>>.(cl).dk::runtime::core::Serializer.dk::runtime::core::Serializer.<<constructor>>.Serializer(uint32_t).<<call>>:0
TEST.VALUE:dk_runtime_serializer.<<GLOBAL>>.(cl).dk::runtime::core::Serializer.dk::runtime::core::Serializer.mBufferShrinkThreshold:0
TEST.END

-- Subprogram: (cl)dk::runtime::core::Serializer::serialize(const bool_t)bool

-- Test Case: 01_Serialize_with_push_back_1bit
TEST.UNIT:dk_runtime_serializer
TEST.SUBPROGRAM:(cl)dk::runtime::core::Serializer::serialize(const bool_t)bool
TEST.NEW
TEST.NAME:01_Serialize_with_push_back_1bit
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_serializer.<<GLOBAL>>.(cl).dk::runtime::core::Serializer.dk::runtime::core::Serializer.<<constructor>>.Serializer(uint32_t).<<call>>:0
TEST.VALUE:dk_runtime_serializer.(cl)dk::runtime::core::Serializer::serialize(const bool_t)bool.value:true
TEST.EXPECTED:dk_runtime_serializer.(cl)dk::runtime::core::Serializer::serialize(const bool_t)bool.return:true
TEST.FLOW
  dk_runtime_serializer.cpp.(cl)dk::runtime::core::Serializer::serialize(const bool_t)bool
  dk_runtime_serializer.cpp.(cl)dk::runtime::core::Serializer::serialize(const bool_t)bool
TEST.END_FLOW
TEST.END

-- Test Case: 02_Serialize_with_no_push_back
TEST.UNIT:dk_runtime_serializer
TEST.SUBPROGRAM:(cl)dk::runtime::core::Serializer::serialize(const bool_t)bool
TEST.NEW
TEST.NAME:02_Serialize_with_no_push_back
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_serializer.<<GLOBAL>>.(cl).dk::runtime::core::Serializer.dk::runtime::core::Serializer.<<constructor>>.Serializer(uint32_t).bufferShrinkThreshold:1
TEST.VALUE:dk_runtime_serializer.<<GLOBAL>>.(cl).dk::runtime::core::Serializer.dk::runtime::core::Serializer.<<constructor>>.Serializer(uint32_t).<<call>>:0
TEST.EXPECTED:dk_runtime_serializer.(cl)dk::runtime::core::Serializer::serialize(const bool_t)bool.return:true
TEST.FLOW
  dk_runtime_serializer.cpp.(cl)dk::runtime::core::Serializer::serialize(const bool_t)bool
  dk_runtime_serializer.cpp.(cl)dk::runtime::core::Serializer::serialize(const bool_t)bool
TEST.END_FLOW
TEST.END

-- Subprogram: (cl)dk::runtime::core::Serializer::serialize(const float32_t&)bool

-- Test Case: 01_Serialize
TEST.UNIT:dk_runtime_serializer
TEST.SUBPROGRAM:(cl)dk::runtime::core::Serializer::serialize(const float32_t&)bool
TEST.NEW
TEST.NAME:01_Serialize
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_serializer.<<GLOBAL>>.(cl).dk::runtime::core::Serializer.dk::runtime::core::Serializer.<<constructor>>.Serializer(uint32_t).<<call>>:0
TEST.FLOW
  dk_runtime_serializer.cpp.(cl)dk::runtime::core::Serializer::serialize(const float32_t&)bool
  dk_runtime_serializer.cpp.(cl)dk::runtime::core::Serializer::serialize(const float32_t&)bool
TEST.END_FLOW
TEST.END

-- Subprogram: (cl)dk::runtime::core::Serializer::serialize(const float64_t&)bool

-- Test Case: 01_Serialize
TEST.UNIT:dk_runtime_serializer
TEST.SUBPROGRAM:(cl)dk::runtime::core::Serializer::serialize(const float64_t&)bool
TEST.NEW
TEST.NAME:01_Serialize
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_serializer.<<GLOBAL>>.(cl).dk::runtime::core::Serializer.dk::runtime::core::Serializer.<<constructor>>.Serializer(uint32_t).<<call>>:0
TEST.FLOW
  dk_runtime_serializer.cpp.(cl)dk::runtime::core::Serializer::serialize(const float64_t&)bool
  dk_runtime_serializer.cpp.(cl)dk::runtime::core::Serializer::serialize(const float64_t&)bool
TEST.END_FLOW
TEST.END

-- Subprogram: (cl)dk::runtime::core::Serializer::serialize(const int16_t)bool

-- Test Case: 01_Return_bool_value_of_serialize
TEST.UNIT:dk_runtime_serializer
TEST.SUBPROGRAM:(cl)dk::runtime::core::Serializer::serialize(const int16_t)bool
TEST.NEW
TEST.NAME:01_Return_bool_value_of_serialize
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_serializer.<<GLOBAL>>.(cl).dk::runtime::core::Serializer.dk::runtime::core::Serializer.<<constructor>>.Serializer(uint32_t).<<call>>:0
TEST.FLOW
  dk_runtime_serializer.cpp.(cl)dk::runtime::core::Serializer::serialize(const int16_t)bool
  dk_runtime_serializer.cpp.(cl)dk::runtime::core::Serializer::serialize(const int16_t)bool
TEST.END_FLOW
TEST.END

-- Subprogram: (cl)dk::runtime::core::Serializer::serialize(const int32_t,bool)bool

-- Test Case: 01_Return_bool_serialize_with_omitLastByte_false
TEST.UNIT:dk_runtime_serializer
TEST.SUBPROGRAM:(cl)dk::runtime::core::Serializer::serialize(const int32_t,bool)bool
TEST.NEW
TEST.NAME:01_Return_bool_serialize_with_omitLastByte_false
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_serializer.<<GLOBAL>>.(cl).dk::runtime::core::Serializer.dk::runtime::core::Serializer.<<constructor>>.Serializer(uint32_t).bufferShrinkThreshold:1
TEST.VALUE:dk_runtime_serializer.<<GLOBAL>>.(cl).dk::runtime::core::Serializer.dk::runtime::core::Serializer.<<constructor>>.Serializer(uint32_t).<<call>>:0
TEST.VALUE:dk_runtime_serializer.(cl)dk::runtime::core::Serializer::serialize(const int32_t,bool)bool.value:1
TEST.VALUE:dk_runtime_serializer.(cl)dk::runtime::core::Serializer::serialize(const int32_t,bool)bool.omitLastByte:true
TEST.VALUE:dk_runtime_serializer.(cl)dk::runtime::core::Serializer::serialize(const int32_t,bool)bool.return:true
TEST.FLOW
  dk_runtime_serializer.cpp.(cl)dk::runtime::core::Serializer::serialize(const int32_t,bool)bool
  dk_runtime_serializer.cpp.(cl)dk::runtime::core::Serializer::serialize(const int32_t,bool)bool
TEST.END_FLOW
TEST.END

-- Subprogram: (cl)dk::runtime::core::Serializer::serialize(const int64_t)bool

-- Test Case: 01_Return_bool_value_of_serialize
TEST.UNIT:dk_runtime_serializer
TEST.SUBPROGRAM:(cl)dk::runtime::core::Serializer::serialize(const int64_t)bool
TEST.NEW
TEST.NAME:01_Return_bool_value_of_serialize
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_serializer.<<GLOBAL>>.(cl).dk::runtime::core::Serializer.dk::runtime::core::Serializer.<<constructor>>.Serializer(uint32_t).bufferShrinkThreshold:1
TEST.VALUE:dk_runtime_serializer.<<GLOBAL>>.(cl).dk::runtime::core::Serializer.dk::runtime::core::Serializer.<<constructor>>.Serializer(uint32_t).<<call>>:0
TEST.VALUE:dk_runtime_serializer.(cl)dk::runtime::core::Serializer::serialize(const int64_t)bool.value:1000000
TEST.FLOW
  dk_runtime_serializer.cpp.(cl)dk::runtime::core::Serializer::serialize(const int64_t)bool
  dk_runtime_serializer.cpp.(cl)dk::runtime::core::Serializer::serialize(const int64_t)bool
TEST.END_FLOW
TEST.END

-- Subprogram: (cl)dk::runtime::core::Serializer::serialize(const int8_t)bool

-- Test Case: 01_Return_bool_value_of_serialize
TEST.UNIT:dk_runtime_serializer
TEST.SUBPROGRAM:(cl)dk::runtime::core::Serializer::serialize(const int8_t)bool
TEST.NEW
TEST.NAME:01_Return_bool_value_of_serialize
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_serializer.<<GLOBAL>>.(cl).dk::runtime::core::Serializer.dk::runtime::core::Serializer.<<constructor>>.Serializer(uint32_t).bufferShrinkThreshold:1
TEST.VALUE:dk_runtime_serializer.<<GLOBAL>>.(cl).dk::runtime::core::Serializer.dk::runtime::core::Serializer.<<constructor>>.Serializer(uint32_t).<<call>>:0
TEST.VALUE:dk_runtime_serializer.(cl)dk::runtime::core::Serializer::serialize(const int8_t)bool.value:127
TEST.VALUE:dk_runtime_serializer.(cl)dk::runtime::core::Serializer::serialize(const int8_t)bool.return:true
TEST.FLOW
  dk_runtime_serializer.cpp.(cl)dk::runtime::core::Serializer::serialize(const int8_t)bool
  dk_runtime_serializer.cpp.(cl)dk::runtime::core::Serializer::serialize(const int8_t)bool
TEST.END_FLOW
TEST.END

-- Subprogram: (cl)dk::runtime::core::Serializer::serialize(const std::vector<unsigned char, std::allocator<unsigned char>>&)bool

-- Test Case: 01_Serialize_mData_insert
TEST.UNIT:dk_runtime_serializer
TEST.SUBPROGRAM:(cl)dk::runtime::core::Serializer::serialize(const std::vector<unsigned char, std::allocator<unsigned char>>&)bool
TEST.NEW
TEST.NAME:01_Serialize_mData_insert
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_serializer.<<GLOBAL>>.(cl).dk::runtime::core::Serializer.dk::runtime::core::Serializer.<<constructor>>.Serializer(uint32_t).bufferShrinkThreshold:1
TEST.VALUE:dk_runtime_serializer.<<GLOBAL>>.(cl).dk::runtime::core::Serializer.dk::runtime::core::Serializer.<<constructor>>.Serializer(uint32_t).<<call>>:0
TEST.EXPECTED:dk_runtime_serializer.(cl)dk::runtime::core::Serializer::serialize(const std::vector<unsigned char, std::allocator<unsigned char>>&)bool.return:true
TEST.FLOW
  dk_runtime_serializer.cpp.(cl)dk::runtime::core::Serializer::serialize(const std::vector<unsigned char, std::allocator<unsigned char>>&)bool
  dk_runtime_serializer.cpp.(cl)dk::runtime::core::Serializer::serialize(const std::vector<unsigned char, std::allocator<unsigned char>>&)bool
TEST.END_FLOW
TEST.END

-- Subprogram: (cl)dk::runtime::core::Serializer::serialize(const uint16_t)bool

-- Test Case: 01_Serialize_with_push_back
TEST.UNIT:dk_runtime_serializer
TEST.SUBPROGRAM:(cl)dk::runtime::core::Serializer::serialize(const uint16_t)bool
TEST.NEW
TEST.NAME:01_Serialize_with_push_back
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_serializer.<<GLOBAL>>.(cl).dk::runtime::core::Serializer.dk::runtime::core::Serializer.<<constructor>>.Serializer(uint32_t).bufferShrinkThreshold:1
TEST.VALUE:dk_runtime_serializer.<<GLOBAL>>.(cl).dk::runtime::core::Serializer.dk::runtime::core::Serializer.<<constructor>>.Serializer(uint32_t).<<call>>:0
TEST.EXPECTED:dk_runtime_serializer.(cl)dk::runtime::core::Serializer::serialize(const uint16_t)bool.return:true
TEST.FLOW
  dk_runtime_serializer.cpp.(cl)dk::runtime::core::Serializer::serialize(const uint16_t)bool
  dk_runtime_serializer.cpp.(cl)dk::runtime::core::Serializer::serialize(const uint16_t)bool
TEST.END_FLOW
TEST.END

-- Subprogram: (cl)dk::runtime::core::Serializer::serialize(const uint32_t,bool)bool

-- Test Case: 01_Serialize_with_omitLastByte_true_condition
TEST.UNIT:dk_runtime_serializer
TEST.SUBPROGRAM:(cl)dk::runtime::core::Serializer::serialize(const uint32_t,bool)bool
TEST.NEW
TEST.NAME:01_Serialize_with_omitLastByte_true_condition
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_serializer.<<GLOBAL>>.(cl).dk::runtime::core::Serializer.dk::runtime::core::Serializer.<<constructor>>.Serializer(uint32_t).bufferShrinkThreshold:1
TEST.VALUE:dk_runtime_serializer.<<GLOBAL>>.(cl).dk::runtime::core::Serializer.dk::runtime::core::Serializer.<<constructor>>.Serializer(uint32_t).<<call>>:0
TEST.VALUE:dk_runtime_serializer.(cl)dk::runtime::core::Serializer::serialize(const uint32_t,bool)bool.omitLastByte:true
TEST.EXPECTED:dk_runtime_serializer.(cl)dk::runtime::core::Serializer::serialize(const uint32_t,bool)bool.omitLastByte:true
TEST.EXPECTED:dk_runtime_serializer.(cl)dk::runtime::core::Serializer::serialize(const uint32_t,bool)bool.return:true
TEST.FLOW
  dk_runtime_serializer.cpp.(cl)dk::runtime::core::Serializer::serialize(const uint32_t,bool)bool
  dk_runtime_serializer.cpp.(cl)dk::runtime::core::Serializer::serialize(const uint32_t,bool)bool
TEST.END_FLOW
TEST.END

-- Test Case: 02_Serialize_with_omitLastByte_false_condition
TEST.UNIT:dk_runtime_serializer
TEST.SUBPROGRAM:(cl)dk::runtime::core::Serializer::serialize(const uint32_t,bool)bool
TEST.NEW
TEST.NAME:02_Serialize_with_omitLastByte_false_condition
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_serializer.<<GLOBAL>>.(cl).dk::runtime::core::Serializer.dk::runtime::core::Serializer.<<constructor>>.Serializer(uint32_t).bufferShrinkThreshold:1
TEST.VALUE:dk_runtime_serializer.<<GLOBAL>>.(cl).dk::runtime::core::Serializer.dk::runtime::core::Serializer.<<constructor>>.Serializer(uint32_t).<<call>>:0
TEST.VALUE:dk_runtime_serializer.(cl)dk::runtime::core::Serializer::serialize(const uint32_t,bool)bool.omitLastByte:false
TEST.EXPECTED:dk_runtime_serializer.(cl)dk::runtime::core::Serializer::serialize(const uint32_t,bool)bool.omitLastByte:false
TEST.EXPECTED:dk_runtime_serializer.(cl)dk::runtime::core::Serializer::serialize(const uint32_t,bool)bool.return:true
TEST.FLOW
  dk_runtime_serializer.cpp.(cl)dk::runtime::core::Serializer::serialize(const uint32_t,bool)bool
  dk_runtime_serializer.cpp.(cl)dk::runtime::core::Serializer::serialize(const uint32_t,bool)bool
TEST.END_FLOW
TEST.END

-- Subprogram: (cl)dk::runtime::core::Serializer::serialize(const uint64_t)bool

-- Test Case: 01_Serialize
TEST.UNIT:dk_runtime_serializer
TEST.SUBPROGRAM:(cl)dk::runtime::core::Serializer::serialize(const uint64_t)bool
TEST.NEW
TEST.NAME:01_Serialize
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_serializer.<<GLOBAL>>.(cl).dk::runtime::core::Serializer.dk::runtime::core::Serializer.<<constructor>>.Serializer(uint32_t).bufferShrinkThreshold:1
TEST.VALUE:dk_runtime_serializer.<<GLOBAL>>.(cl).dk::runtime::core::Serializer.dk::runtime::core::Serializer.<<constructor>>.Serializer(uint32_t).<<call>>:0
TEST.VALUE:dk_runtime_serializer.(cl)dk::runtime::core::Serializer::serialize(const uint64_t)bool.value:1000
TEST.EXPECTED:dk_runtime_serializer.(cl)dk::runtime::core::Serializer::serialize(const uint64_t)bool.return:true
TEST.FLOW
  dk_runtime_serializer.cpp.(cl)dk::runtime::core::Serializer::serialize(const uint64_t)bool
  dk_runtime_serializer.cpp.(cl)dk::runtime::core::Serializer::serialize(const uint64_t)bool
TEST.END_FLOW
TEST.END

-- Subprogram: (cl)dk::runtime::core::Serializer::serialize(const uint8_t)bool

-- Test Case: 01_Serialize_with_push_back
TEST.UNIT:dk_runtime_serializer
TEST.SUBPROGRAM:(cl)dk::runtime::core::Serializer::serialize(const uint8_t)bool
TEST.NEW
TEST.NAME:01_Serialize_with_push_back
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_serializer.<<GLOBAL>>.(cl).dk::runtime::core::Serializer.dk::runtime::core::Serializer.<<constructor>>.Serializer(uint32_t).<<call>>:0
TEST.EXPECTED:dk_runtime_serializer.(cl)dk::runtime::core::Serializer::serialize(const uint8_t)bool.return:true
TEST.FLOW
  dk_runtime_serializer.cpp.(cl)dk::runtime::core::Serializer::serialize(const uint8_t)bool
  dk_runtime_serializer.cpp.(cl)dk::runtime::core::Serializer::serialize(const uint8_t)bool
TEST.END_FLOW
TEST.END

-- Subprogram: (cl)dk::runtime::core::Serializer::serialize(const uint8_t*,uint32_t)bool

-- Test Case: 01_Serialize_mData_insert
TEST.UNIT:dk_runtime_serializer
TEST.SUBPROGRAM:(cl)dk::runtime::core::Serializer::serialize(const uint8_t*,uint32_t)bool
TEST.NEW
TEST.NAME:01_Serialize_mData_insert
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_serializer.<<GLOBAL>>.(cl).dk::runtime::core::Serializer.dk::runtime::core::Serializer.<<constructor>>.Serializer(uint32_t).bufferShrinkThreshold:1
TEST.VALUE:dk_runtime_serializer.<<GLOBAL>>.(cl).dk::runtime::core::Serializer.dk::runtime::core::Serializer.<<constructor>>.Serializer(uint32_t).<<call>>:0
TEST.VALUE:dk_runtime_serializer.<<GLOBAL>>.(cl).dk::runtime::core::Serializer.dk::runtime::core::Serializer.mData:<<malloc 1>>
TEST.VALUE:dk_runtime_serializer.<<GLOBAL>>.(cl).dk::runtime::core::Serializer.dk::runtime::core::Serializer.mData[0]:1
TEST.VALUE:dk_runtime_serializer.<<GLOBAL>>.(cl).dk::runtime::core::Serializer.dk::runtime::core::Serializer.mData[0]:<<function 1>>
TEST.VALUE:dk_runtime_serializer.<<GLOBAL>>.(cl).dk::runtime::core::Serializer.dk::runtime::core::Serializer.mBufferShrinkThreshold:1
TEST.VALUE:dk_runtime_serializer.(cl)dk::runtime::core::Serializer::serialize(const uint8_t*,uint32_t)bool.pData:<<malloc 5>>
TEST.VALUE:dk_runtime_serializer.(cl)dk::runtime::core::Serializer::serialize(const uint8_t*,uint32_t)bool.pData:"anjb"
TEST.VALUE:dk_runtime_serializer.(cl)dk::runtime::core::Serializer::serialize(const uint8_t*,uint32_t)bool.length:1
TEST.VALUE:dk_runtime_serializer.(cl)dk::runtime::core::Serializer::serialize(const uint8_t*,uint32_t)bool.return:true
TEST.EXPECTED:dk_runtime_serializer.(cl)dk::runtime::core::Serializer::serialize(const uint8_t*,uint32_t)bool.return:true
TEST.FLOW
  dk_runtime_serializer.cpp.(cl)dk::runtime::core::Serializer::serialize(const uint8_t*,uint32_t)bool
  dk_runtime_serializer.cpp.(cl)dk::runtime::core::Serializer::serialize(const uint8_t*,uint32_t)bool
TEST.END_FLOW
TEST.END

-- Subprogram: (cl)dk::runtime::core::Serializer::~Serializer

-- Test Case: 01_Deinitialization
TEST.UNIT:dk_runtime_serializer
TEST.SUBPROGRAM:(cl)dk::runtime::core::Serializer::~Serializer
TEST.NEW
TEST.NAME:01_Deinitialization
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_serializer.<<GLOBAL>>.(cl).dk::runtime::core::Serializer.dk::runtime::core::Serializer.<<constructor>>.Serializer(uint32_t).bufferShrinkThreshold:1
TEST.VALUE:dk_runtime_serializer.<<GLOBAL>>.(cl).dk::runtime::core::Serializer.dk::runtime::core::Serializer.<<constructor>>.Serializer(uint32_t).<<call>>:0
TEST.FLOW
  dk_runtime_serializer.cpp.(cl)dk::runtime::core::Serializer::~Serializer
  dk_runtime_serializer.cpp.(cl)dk::runtime::core::Serializer::~Serializer
TEST.END_FLOW
TEST.END
