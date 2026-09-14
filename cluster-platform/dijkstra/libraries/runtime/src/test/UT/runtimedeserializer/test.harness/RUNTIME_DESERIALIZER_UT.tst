-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : RUNTIME_DESERIALIZER_UT
-- Unit(s) Under Test: dk_runtime_deserializer
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

-- Unit: dk_runtime_deserializer

-- Subprogram: (cl)dk::runtime::core::Deserializer::Deserializer(byte_t*,uint32_t,uint32_t)

-- Test Case: 01_Initialization_double_parameter
TEST.UNIT:dk_runtime_deserializer
TEST.SUBPROGRAM:(cl)dk::runtime::core::Deserializer::Deserializer(byte_t*,uint32_t,uint32_t)
TEST.NEW
TEST.NAME:01_Initialization_double_parameter
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.FLOW
  dk_runtime_deserializer.cpp.(cl)dk::runtime::core::Deserializer::Deserializer(byte_t*,uint32_t,uint32_t)
  dk_runtime_deserializer.cpp.(cl)dk::runtime::core::Deserializer::Deserializer(byte_t*,uint32_t,uint32_t)
TEST.END_FLOW
TEST.END

-- Subprogram: (cl)dk::runtime::core::Deserializer::Deserializer(const dk::runtime::core::Deserializer&)

-- Test Case: 01_Initialization_copy_constructor
TEST.UNIT:dk_runtime_deserializer
TEST.SUBPROGRAM:(cl)dk::runtime::core::Deserializer::Deserializer(const dk::runtime::core::Deserializer&)
TEST.NEW
TEST.NAME:01_Initialization_copy_constructor
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_deserializer.(cl)dk::runtime::core::Deserializer::Deserializer(const dk::runtime::core::Deserializer&).pDes.dk::runtime::core::Deserializer.<<constructor>>.Deserializer(uint32_t).<<call>>:0
TEST.FLOW
  dk_runtime_deserializer.cpp.(cl)dk::runtime::core::Deserializer::Deserializer(const dk::runtime::core::Deserializer&)
  dk_runtime_deserializer.cpp.(cl)dk::runtime::core::Deserializer::Deserializer(const dk::runtime::core::Deserializer&)
TEST.END_FLOW
TEST.END

-- Subprogram: (cl)dk::runtime::core::Deserializer::Deserializer(uint32_t)

-- Test Case: 01_Initialization_single_parameter
TEST.UNIT:dk_runtime_deserializer
TEST.SUBPROGRAM:(cl)dk::runtime::core::Deserializer::Deserializer(uint32_t)
TEST.NEW
TEST.NAME:01_Initialization_single_parameter
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.FLOW
  dk_runtime_deserializer.cpp.(cl)dk::runtime::core::Deserializer::Deserializer(uint32_t)
  dk_runtime_deserializer.cpp.(cl)dk::runtime::core::Deserializer::Deserializer(uint32_t)
TEST.END_FLOW
TEST.END

-- Subprogram: (cl)dk::runtime::core::Deserializer::deserialize(bool_t&)bool

-- Test Case: 01_Empty_buffer
TEST.UNIT:dk_runtime_deserializer
TEST.SUBPROGRAM:(cl)dk::runtime::core::Deserializer::deserialize(bool_t&)bool
TEST.NEW
TEST.NAME:01_Empty_buffer
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_deserializer.<<GLOBAL>>.(cl).dk::runtime::core::Deserializer.dk::runtime::core::Deserializer.<<constructor>>.Deserializer(uint32_t).<<call>>:0
TEST.EXPECTED:dk_runtime_deserializer.(cl)dk::runtime::core::Deserializer::deserialize(bool_t&)bool.return:false
TEST.END

-- Test Case: 02_Value_false
TEST.UNIT:dk_runtime_deserializer
TEST.SUBPROGRAM:(cl)dk::runtime::core::Deserializer::deserialize(bool_t&)bool
TEST.NEW
TEST.NAME:02_Value_false
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_deserializer.<<GLOBAL>>.(cl).dk::runtime::core::Deserializer.dk::runtime::core::Deserializer.<<constructor>>.Deserializer(uint32_t).<<call>>:0
TEST.VALUE:dk_runtime_deserializer.<<GLOBAL>>.(cl).dk::runtime::core::Deserializer.dk::runtime::core::Deserializer.mRemaining:10
TEST.EXPECTED:dk_runtime_deserializer.(cl)dk::runtime::core::Deserializer::deserialize(bool_t&)bool.return:true
TEST.VALUE_USER_CODE:<<dk::runtime::core::Deserializer instance>>.dk::runtime::core::Deserializer.mPosition
static dk::runtime::core::Deserializer *temp = new dk::runtime::core::Deserializer(0);
temp->mData.push_back(10);
<<dk::runtime::core::Deserializer instance>>->mPosition = ( temp->mData.begin() );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 03_Value_true
TEST.UNIT:dk_runtime_deserializer
TEST.SUBPROGRAM:(cl)dk::runtime::core::Deserializer::deserialize(bool_t&)bool
TEST.NEW
TEST.NAME:03_Value_true
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_deserializer.<<GLOBAL>>.(cl).dk::runtime::core::Deserializer.dk::runtime::core::Deserializer.<<constructor>>.Deserializer(uint32_t).<<call>>:0
TEST.VALUE:dk_runtime_deserializer.<<GLOBAL>>.(cl).dk::runtime::core::Deserializer.dk::runtime::core::Deserializer.mRemaining:10
TEST.EXPECTED:dk_runtime_deserializer.(cl)dk::runtime::core::Deserializer::deserialize(bool_t&)bool.return:true
TEST.VALUE_USER_CODE:<<dk::runtime::core::Deserializer instance>>.dk::runtime::core::Deserializer.mPosition
static dk::runtime::core::Deserializer *temp = new dk::runtime::core::Deserializer(0);
temp->mData.push_back(1);
<<dk::runtime::core::Deserializer instance>>->mPosition = ( temp->mData.begin() );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::runtime::core::Deserializer::deserialize(float32_t&)bool

-- Test Case: 01_Deserialize
TEST.UNIT:dk_runtime_deserializer
TEST.SUBPROGRAM:(cl)dk::runtime::core::Deserializer::deserialize(float32_t&)bool
TEST.NEW
TEST.NAME:01_Deserialize
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_deserializer.<<GLOBAL>>.(cl).dk::runtime::core::Deserializer.dk::runtime::core::Deserializer.<<constructor>>.Deserializer(uint32_t).<<call>>:0
TEST.FLOW
  dk_runtime_deserializer.cpp.(cl)dk::runtime::core::Deserializer::deserialize(float32_t&)bool
  dk_runtime_deserializer.cpp.(cl)dk::runtime::core::Deserializer::deserialize(float32_t&)bool
TEST.END_FLOW
TEST.END

-- Subprogram: (cl)dk::runtime::core::Deserializer::deserialize(float64_t&)bool

-- Test Case: 01_Deserialize
TEST.UNIT:dk_runtime_deserializer
TEST.SUBPROGRAM:(cl)dk::runtime::core::Deserializer::deserialize(float64_t&)bool
TEST.NEW
TEST.NAME:01_Deserialize
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_deserializer.<<GLOBAL>>.(cl).dk::runtime::core::Deserializer.dk::runtime::core::Deserializer.<<constructor>>.Deserializer(uint32_t).<<call>>:0
TEST.FLOW
  dk_runtime_deserializer.cpp.(cl)dk::runtime::core::Deserializer::deserialize(float64_t&)bool
  dk_runtime_deserializer.cpp.(cl)dk::runtime::core::Deserializer::deserialize(float64_t&)bool
TEST.END_FLOW
TEST.END

-- Subprogram: (cl)dk::runtime::core::Deserializer::deserialize(int16_t&)bool

-- Test Case: 01_Deserialize
TEST.UNIT:dk_runtime_deserializer
TEST.SUBPROGRAM:(cl)dk::runtime::core::Deserializer::deserialize(int16_t&)bool
TEST.NEW
TEST.NAME:01_Deserialize
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_deserializer.<<GLOBAL>>.(cl).dk::runtime::core::Deserializer.dk::runtime::core::Deserializer.<<constructor>>.Deserializer(uint32_t).<<call>>:0
TEST.FLOW
  dk_runtime_deserializer.cpp.(cl)dk::runtime::core::Deserializer::deserialize(int16_t&)bool
  dk_runtime_deserializer.cpp.(cl)dk::runtime::core::Deserializer::deserialize(int16_t&)bool
TEST.END_FLOW
TEST.END

-- Subprogram: (cl)dk::runtime::core::Deserializer::deserialize(int32_t&,bool)bool

-- Test Case: 01_Deserialize
TEST.UNIT:dk_runtime_deserializer
TEST.SUBPROGRAM:(cl)dk::runtime::core::Deserializer::deserialize(int32_t&,bool)bool
TEST.NEW
TEST.NAME:01_Deserialize
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_deserializer.<<GLOBAL>>.(cl).dk::runtime::core::Deserializer.dk::runtime::core::Deserializer.<<constructor>>.Deserializer(uint32_t).<<call>>:0
TEST.FLOW
  dk_runtime_deserializer.cpp.(cl)dk::runtime::core::Deserializer::deserialize(int32_t&,bool)bool
  dk_runtime_deserializer.cpp.(cl)dk::runtime::core::Deserializer::deserialize(int32_t&,bool)bool
TEST.END_FLOW
TEST.END

-- Subprogram: (cl)dk::runtime::core::Deserializer::deserialize(int64_t&)bool

-- Test Case: 01_Deserialize
TEST.UNIT:dk_runtime_deserializer
TEST.SUBPROGRAM:(cl)dk::runtime::core::Deserializer::deserialize(int64_t&)bool
TEST.NEW
TEST.NAME:01_Deserialize
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_deserializer.<<GLOBAL>>.(cl).dk::runtime::core::Deserializer.dk::runtime::core::Deserializer.<<constructor>>.Deserializer(uint32_t).<<call>>:0
TEST.FLOW
  dk_runtime_deserializer.cpp.(cl)dk::runtime::core::Deserializer::deserialize(int64_t&)bool
  dk_runtime_deserializer.cpp.(cl)dk::runtime::core::Deserializer::deserialize(int64_t&)bool
TEST.END_FLOW
TEST.END

-- Subprogram: (cl)dk::runtime::core::Deserializer::deserialize(int8_t&)bool

-- Test Case: 01_Deserialize
TEST.UNIT:dk_runtime_deserializer
TEST.SUBPROGRAM:(cl)dk::runtime::core::Deserializer::deserialize(int8_t&)bool
TEST.NEW
TEST.NAME:01_Deserialize
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_deserializer.<<GLOBAL>>.(cl).dk::runtime::core::Deserializer.dk::runtime::core::Deserializer.<<constructor>>.Deserializer(uint32_t).<<call>>:0
TEST.FLOW
  dk_runtime_deserializer.cpp.(cl)dk::runtime::core::Deserializer::deserialize(int8_t&)bool
  dk_runtime_deserializer.cpp.(cl)dk::runtime::core::Deserializer::deserialize(int8_t&)bool
TEST.END_FLOW
TEST.END

-- Subprogram: (cl)dk::runtime::core::Deserializer::deserialize(std::vector<unsigned char, std::allocator<unsigned char>>&)bool

-- Test Case: 01_Empty_buffer
TEST.UNIT:dk_runtime_deserializer
TEST.SUBPROGRAM:(cl)dk::runtime::core::Deserializer::deserialize(std::vector<unsigned char, std::allocator<unsigned char>>&)bool
TEST.NEW
TEST.NAME:01_Empty_buffer
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_deserializer.<<GLOBAL>>.(cl).dk::runtime::core::Deserializer.dk::runtime::core::Deserializer.<<constructor>>.Deserializer(uint32_t).<<call>>:0
TEST.VALUE:dk_runtime_deserializer.(cl)dk::runtime::core::Deserializer::deserialize(std::vector<unsigned char, std::allocator<unsigned char>>&)bool.value:<<malloc 1>>
TEST.VALUE:dk_runtime_deserializer.(cl)dk::runtime::core::Deserializer::deserialize(std::vector<unsigned char, std::allocator<unsigned char>>&)bool.value[0]:<<function 1>>
TEST.EXPECTED:dk_runtime_deserializer.(cl)dk::runtime::core::Deserializer::deserialize(std::vector<unsigned char, std::allocator<unsigned char>>&)bool.return:false
TEST.END

-- Test Case: 02_Non_empty_buffer
TEST.UNIT:dk_runtime_deserializer
TEST.SUBPROGRAM:(cl)dk::runtime::core::Deserializer::deserialize(std::vector<unsigned char, std::allocator<unsigned char>>&)bool
TEST.NEW
TEST.NAME:02_Non_empty_buffer
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_deserializer.<<GLOBAL>>.(cl).dk::runtime::core::Deserializer.dk::runtime::core::Deserializer.<<constructor>>.Deserializer(uint32_t).<<call>>:0
TEST.VALUE:dk_runtime_deserializer.<<GLOBAL>>.(cl).dk::runtime::core::Deserializer.dk::runtime::core::Deserializer.mRemaining:10
TEST.VALUE:dk_runtime_deserializer.(cl)dk::runtime::core::Deserializer::deserialize(std::vector<unsigned char, std::allocator<unsigned char>>&)bool.value:<<malloc 1>>
TEST.VALUE:dk_runtime_deserializer.(cl)dk::runtime::core::Deserializer::deserialize(std::vector<unsigned char, std::allocator<unsigned char>>&)bool.value[0]:<<function 1>>
TEST.EXPECTED:dk_runtime_deserializer.(cl)dk::runtime::core::Deserializer::deserialize(std::vector<unsigned char, std::allocator<unsigned char>>&)bool.return:true
TEST.VALUE_USER_CODE:<<dk::runtime::core::Deserializer instance>>.dk::runtime::core::Deserializer.mPosition
static dk::runtime::core::Deserializer *temp = new dk::runtime::core::Deserializer(0);
temp->mData.push_back(10);
temp->mData.push_back(10);
<<dk::runtime::core::Deserializer instance>>->mPosition = ( temp->mData.begin() );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::runtime::core::Deserializer::deserialize(uint16_t&)bool

-- Test Case: 01_Empty_buffer
TEST.UNIT:dk_runtime_deserializer
TEST.SUBPROGRAM:(cl)dk::runtime::core::Deserializer::deserialize(uint16_t&)bool
TEST.NEW
TEST.NAME:01_Empty_buffer
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_deserializer.<<GLOBAL>>.(cl).dk::runtime::core::Deserializer.dk::runtime::core::Deserializer.<<constructor>>.Deserializer(uint32_t).<<call>>:0
TEST.EXPECTED:dk_runtime_deserializer.(cl)dk::runtime::core::Deserializer::deserialize(uint16_t&)bool.return:false
TEST.END

-- Test Case: 02_Non_empty_buffer
TEST.UNIT:dk_runtime_deserializer
TEST.SUBPROGRAM:(cl)dk::runtime::core::Deserializer::deserialize(uint16_t&)bool
TEST.NEW
TEST.NAME:02_Non_empty_buffer
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_deserializer.<<GLOBAL>>.(cl).dk::runtime::core::Deserializer.dk::runtime::core::Deserializer.<<constructor>>.Deserializer(uint32_t).<<call>>:0
TEST.VALUE:dk_runtime_deserializer.<<GLOBAL>>.(cl).dk::runtime::core::Deserializer.dk::runtime::core::Deserializer.mRemaining:10
TEST.EXPECTED:dk_runtime_deserializer.(cl)dk::runtime::core::Deserializer::deserialize(uint16_t&)bool.return:true
TEST.VALUE_USER_CODE:<<dk::runtime::core::Deserializer instance>>.dk::runtime::core::Deserializer.mPosition
static dk::runtime::core::Deserializer *temp = new dk::runtime::core::Deserializer(0);
temp->mData.push_back(10);
temp->mData.push_back(10);
<<dk::runtime::core::Deserializer instance>>->mPosition = ( temp->mData.begin() );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::runtime::core::Deserializer::deserialize(uint32_t&,bool)bool

-- Test Case: 01_Empty_buffer
TEST.UNIT:dk_runtime_deserializer
TEST.SUBPROGRAM:(cl)dk::runtime::core::Deserializer::deserialize(uint32_t&,bool)bool
TEST.NEW
TEST.NAME:01_Empty_buffer
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_deserializer.<<GLOBAL>>.(cl).dk::runtime::core::Deserializer.dk::runtime::core::Deserializer.<<constructor>>.Deserializer(uint32_t).<<call>>:0
TEST.EXPECTED:dk_runtime_deserializer.(cl)dk::runtime::core::Deserializer::deserialize(uint32_t&,bool)bool.return:false
TEST.END

-- Test Case: 02_No_enough_data
TEST.UNIT:dk_runtime_deserializer
TEST.SUBPROGRAM:(cl)dk::runtime::core::Deserializer::deserialize(uint32_t&,bool)bool
TEST.NEW
TEST.NAME:02_No_enough_data
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_deserializer.<<GLOBAL>>.(cl).dk::runtime::core::Deserializer.dk::runtime::core::Deserializer.<<constructor>>.Deserializer(uint32_t).<<call>>:0
TEST.VALUE:dk_runtime_deserializer.<<GLOBAL>>.(cl).dk::runtime::core::Deserializer.dk::runtime::core::Deserializer.mRemaining:3
TEST.VALUE:dk_runtime_deserializer.(cl)dk::runtime::core::Deserializer::deserialize(uint32_t&,bool)bool.omitLastByte:false
TEST.EXPECTED:dk_runtime_deserializer.(cl)dk::runtime::core::Deserializer::deserialize(uint32_t&,bool)bool.return:false
TEST.END

-- Test Case: 03_Omit_last_byte
TEST.UNIT:dk_runtime_deserializer
TEST.SUBPROGRAM:(cl)dk::runtime::core::Deserializer::deserialize(uint32_t&,bool)bool
TEST.NEW
TEST.NAME:03_Omit_last_byte
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_deserializer.<<GLOBAL>>.(cl).dk::runtime::core::Deserializer.dk::runtime::core::Deserializer.<<constructor>>.Deserializer(uint32_t).<<call>>:0
TEST.VALUE:dk_runtime_deserializer.<<GLOBAL>>.(cl).dk::runtime::core::Deserializer.dk::runtime::core::Deserializer.mRemaining:3
TEST.VALUE:dk_runtime_deserializer.(cl)dk::runtime::core::Deserializer::deserialize(uint32_t&,bool)bool.omitLastByte:true
TEST.EXPECTED:dk_runtime_deserializer.(cl)dk::runtime::core::Deserializer::deserialize(uint32_t&,bool)bool.return:true
TEST.VALUE_USER_CODE:<<dk::runtime::core::Deserializer instance>>.dk::runtime::core::Deserializer.mPosition
static dk::runtime::core::Deserializer *temp = new dk::runtime::core::Deserializer(0);
temp->mData.push_back(10);
temp->mData.push_back(10);
temp->mData.push_back(10);
<<dk::runtime::core::Deserializer instance>>->mPosition = ( temp->mData.begin() );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 04_No_omitting
TEST.UNIT:dk_runtime_deserializer
TEST.SUBPROGRAM:(cl)dk::runtime::core::Deserializer::deserialize(uint32_t&,bool)bool
TEST.NEW
TEST.NAME:04_No_omitting
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_deserializer.<<GLOBAL>>.(cl).dk::runtime::core::Deserializer.dk::runtime::core::Deserializer.<<constructor>>.Deserializer(uint32_t).<<call>>:0
TEST.VALUE:dk_runtime_deserializer.<<GLOBAL>>.(cl).dk::runtime::core::Deserializer.dk::runtime::core::Deserializer.mRemaining:4
TEST.VALUE:dk_runtime_deserializer.(cl)dk::runtime::core::Deserializer::deserialize(uint32_t&,bool)bool.omitLastByte:false
TEST.EXPECTED:dk_runtime_deserializer.(cl)dk::runtime::core::Deserializer::deserialize(uint32_t&,bool)bool.return:true
TEST.VALUE_USER_CODE:<<dk::runtime::core::Deserializer instance>>.dk::runtime::core::Deserializer.mPosition
static dk::runtime::core::Deserializer *temp = new dk::runtime::core::Deserializer(0);
temp->mData.push_back(10);
temp->mData.push_back(10);
temp->mData.push_back(10);
temp->mData.push_back(10);
<<dk::runtime::core::Deserializer instance>>->mPosition = ( temp->mData.begin() );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::runtime::core::Deserializer::deserialize(uint64_t&)bool

-- Test Case: 01_Empty_buffer
TEST.UNIT:dk_runtime_deserializer
TEST.SUBPROGRAM:(cl)dk::runtime::core::Deserializer::deserialize(uint64_t&)bool
TEST.NEW
TEST.NAME:01_Empty_buffer
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_deserializer.<<GLOBAL>>.(cl).dk::runtime::core::Deserializer.dk::runtime::core::Deserializer.<<constructor>>.Deserializer(uint32_t).<<call>>:0
TEST.EXPECTED:dk_runtime_deserializer.(cl)dk::runtime::core::Deserializer::deserialize(uint64_t&)bool.return:false
TEST.END

-- Test Case: 02_Non_empty_buffer
TEST.UNIT:dk_runtime_deserializer
TEST.SUBPROGRAM:(cl)dk::runtime::core::Deserializer::deserialize(uint64_t&)bool
TEST.NEW
TEST.NAME:02_Non_empty_buffer
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_deserializer.<<GLOBAL>>.(cl).dk::runtime::core::Deserializer.dk::runtime::core::Deserializer.<<constructor>>.Deserializer(uint32_t).<<call>>:0
TEST.VALUE:dk_runtime_deserializer.<<GLOBAL>>.(cl).dk::runtime::core::Deserializer.dk::runtime::core::Deserializer.mRemaining:10
TEST.EXPECTED:dk_runtime_deserializer.(cl)dk::runtime::core::Deserializer::deserialize(uint64_t&)bool.return:true
TEST.VALUE_USER_CODE:<<dk::runtime::core::Deserializer instance>>.dk::runtime::core::Deserializer.mPosition
static dk::runtime::core::Deserializer *temp = new dk::runtime::core::Deserializer(0);
temp->mData.push_back(10);
temp->mData.push_back(10);
temp->mData.push_back(10);
temp->mData.push_back(10);
temp->mData.push_back(10);
temp->mData.push_back(10);
temp->mData.push_back(10);
temp->mData.push_back(10);
<<dk::runtime::core::Deserializer instance>>->mPosition = ( temp->mData.begin() );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::runtime::core::Deserializer::deserialize(uint8_t&)bool

-- Test Case: 01_Empty_buffer
TEST.UNIT:dk_runtime_deserializer
TEST.SUBPROGRAM:(cl)dk::runtime::core::Deserializer::deserialize(uint8_t&)bool
TEST.NEW
TEST.NAME:01_Empty_buffer
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_deserializer.<<GLOBAL>>.(cl).dk::runtime::core::Deserializer.dk::runtime::core::Deserializer.<<constructor>>.Deserializer(uint32_t).<<call>>:0
TEST.EXPECTED:dk_runtime_deserializer.(cl)dk::runtime::core::Deserializer::deserialize(uint8_t&)bool.return:false
TEST.END

-- Test Case: 02_Non_empty_buffer
TEST.UNIT:dk_runtime_deserializer
TEST.SUBPROGRAM:(cl)dk::runtime::core::Deserializer::deserialize(uint8_t&)bool
TEST.NEW
TEST.NAME:02_Non_empty_buffer
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_deserializer.<<GLOBAL>>.(cl).dk::runtime::core::Deserializer.dk::runtime::core::Deserializer.<<constructor>>.Deserializer(uint32_t).<<call>>:0
TEST.VALUE:dk_runtime_deserializer.<<GLOBAL>>.(cl).dk::runtime::core::Deserializer.dk::runtime::core::Deserializer.mRemaining:10
TEST.EXPECTED:dk_runtime_deserializer.(cl)dk::runtime::core::Deserializer::deserialize(uint8_t&)bool.return:true
TEST.VALUE_USER_CODE:<<dk::runtime::core::Deserializer instance>>.dk::runtime::core::Deserializer.mPosition
static dk::runtime::core::Deserializer *temp = new dk::runtime::core::Deserializer(0);
temp->mData.push_back(10);
<<dk::runtime::core::Deserializer instance>>->mPosition = ( temp->mData.begin() );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::runtime::core::Deserializer::deserialize(uint8_t*,uint32_t)bool

-- Test Case: 01_Empty_buffer
TEST.UNIT:dk_runtime_deserializer
TEST.SUBPROGRAM:(cl)dk::runtime::core::Deserializer::deserialize(uint8_t*,uint32_t)bool
TEST.NEW
TEST.NAME:01_Empty_buffer
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_deserializer.<<GLOBAL>>.(cl).dk::runtime::core::Deserializer.dk::runtime::core::Deserializer.<<constructor>>.Deserializer(uint32_t).<<call>>:0
TEST.VALUE:dk_runtime_deserializer.(cl)dk::runtime::core::Deserializer::deserialize(uint8_t*,uint32_t)bool.length:1
TEST.EXPECTED:dk_runtime_deserializer.(cl)dk::runtime::core::Deserializer::deserialize(uint8_t*,uint32_t)bool.return:false
TEST.END

-- Test Case: 02_Non_empty_buffer
TEST.UNIT:dk_runtime_deserializer
TEST.SUBPROGRAM:(cl)dk::runtime::core::Deserializer::deserialize(uint8_t*,uint32_t)bool
TEST.NEW
TEST.NAME:02_Non_empty_buffer
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_deserializer.<<GLOBAL>>.(cl).dk::runtime::core::Deserializer.dk::runtime::core::Deserializer.<<constructor>>.Deserializer(uint32_t).<<call>>:0
TEST.VALUE:dk_runtime_deserializer.<<GLOBAL>>.(cl).dk::runtime::core::Deserializer.dk::runtime::core::Deserializer.mRemaining:10
TEST.VALUE:dk_runtime_deserializer.(cl)dk::runtime::core::Deserializer::deserialize(uint8_t*,uint32_t)bool.length:1
TEST.EXPECTED:dk_runtime_deserializer.(cl)dk::runtime::core::Deserializer::deserialize(uint8_t*,uint32_t)bool.return:true
TEST.VALUE_USER_CODE:<<dk::runtime::core::Deserializer instance>>.dk::runtime::core::Deserializer.mPosition
static dk::runtime::core::Deserializer *temp = new dk::runtime::core::Deserializer(0);
temp->mData.push_back(10);
<<dk::runtime::core::Deserializer instance>>->mPosition = ( temp->mData.begin() );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:dk_runtime_deserializer.(cl)dk::runtime::core::Deserializer::deserialize(uint8_t*,uint32_t)bool.pData
static uint8_t data[10];
<<dk_runtime_deserializer.(cl)dk::runtime::core::Deserializer::deserialize(uint8_t*,uint32_t)bool.pData>> = ( &data[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::runtime::core::Deserializer::getData

-- Test Case: 01_Get_data
TEST.UNIT:dk_runtime_deserializer
TEST.SUBPROGRAM:(cl)dk::runtime::core::Deserializer::getData
TEST.NEW
TEST.NAME:01_Get_data
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_deserializer.<<GLOBAL>>.(cl).dk::runtime::core::Deserializer.dk::runtime::core::Deserializer.<<constructor>>.Deserializer(uint32_t).<<call>>:0
TEST.FLOW
  dk_runtime_deserializer.cpp.(cl)dk::runtime::core::Deserializer::getData
  dk_runtime_deserializer.cpp.(cl)dk::runtime::core::Deserializer::getData
TEST.END_FLOW
TEST.END

-- Subprogram: (cl)dk::runtime::core::Deserializer::getRemaining

-- Test Case: 01_Get_remaining
TEST.UNIT:dk_runtime_deserializer
TEST.SUBPROGRAM:(cl)dk::runtime::core::Deserializer::getRemaining
TEST.NEW
TEST.NAME:01_Get_remaining
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_deserializer.<<GLOBAL>>.(cl).dk::runtime::core::Deserializer.dk::runtime::core::Deserializer.<<constructor>>.Deserializer(uint32_t).<<call>>:0
TEST.FLOW
  dk_runtime_deserializer.cpp.(cl)dk::runtime::core::Deserializer::getRemaining
  dk_runtime_deserializer.cpp.(cl)dk::runtime::core::Deserializer::getRemaining
TEST.END_FLOW
TEST.END

-- Subprogram: (cl)dk::runtime::core::Deserializer::getSize

-- Test Case: 01_Get_size
TEST.UNIT:dk_runtime_deserializer
TEST.SUBPROGRAM:(cl)dk::runtime::core::Deserializer::getSize
TEST.NEW
TEST.NAME:01_Get_size
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_deserializer.<<GLOBAL>>.(cl).dk::runtime::core::Deserializer.dk::runtime::core::Deserializer.<<constructor>>.Deserializer(uint32_t).<<call>>:0
TEST.FLOW
  dk_runtime_deserializer.cpp.(cl)dk::runtime::core::Deserializer::getSize
  dk_runtime_deserializer.cpp.(cl)dk::runtime::core::Deserializer::getSize
TEST.END_FLOW
TEST.END

-- Subprogram: (cl)dk::runtime::core::Deserializer::reset

-- Test Case: 01_BufferShrink_non_zero
TEST.UNIT:dk_runtime_deserializer
TEST.SUBPROGRAM:(cl)dk::runtime::core::Deserializer::reset
TEST.NEW
TEST.NAME:01_BufferShrink_non_zero
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_deserializer.<<GLOBAL>>.(cl).dk::runtime::core::Deserializer.dk::runtime::core::Deserializer.<<constructor>>.Deserializer(uint32_t).<<call>>:0
TEST.FLOW
  dk_runtime_deserializer.cpp.(cl)dk::runtime::core::Deserializer::reset
  dk_runtime_deserializer.cpp.(cl)dk::runtime::core::Deserializer::reset
TEST.END_FLOW
TEST.END

-- Test Case: 02_BufferShrink_zero
TEST.UNIT:dk_runtime_deserializer
TEST.SUBPROGRAM:(cl)dk::runtime::core::Deserializer::reset
TEST.NEW
TEST.NAME:02_BufferShrink_zero
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_deserializer.<<GLOBAL>>.(cl).dk::runtime::core::Deserializer.dk::runtime::core::Deserializer.<<constructor>>.Deserializer(uint32_t).bufferShrinkThreshold:0
TEST.VALUE:dk_runtime_deserializer.<<GLOBAL>>.(cl).dk::runtime::core::Deserializer.dk::runtime::core::Deserializer.<<constructor>>.Deserializer(uint32_t).<<call>>:0
TEST.FLOW
  dk_runtime_deserializer.cpp.(cl)dk::runtime::core::Deserializer::reset
  dk_runtime_deserializer.cpp.(cl)dk::runtime::core::Deserializer::reset
TEST.END_FLOW
TEST.END

-- Subprogram: (cl)dk::runtime::core::Deserializer::setRemaining

-- Test Case: 01_Set_remaining
TEST.UNIT:dk_runtime_deserializer
TEST.SUBPROGRAM:(cl)dk::runtime::core::Deserializer::setRemaining
TEST.NEW
TEST.NAME:01_Set_remaining
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_deserializer.<<GLOBAL>>.(cl).dk::runtime::core::Deserializer.dk::runtime::core::Deserializer.<<constructor>>.Deserializer(uint32_t).<<call>>:0
TEST.FLOW
  dk_runtime_deserializer.cpp.(cl)dk::runtime::core::Deserializer::setRemaining
  dk_runtime_deserializer.cpp.(cl)dk::runtime::core::Deserializer::setRemaining
TEST.END_FLOW
TEST.END

-- Subprogram: (cl)dk::runtime::core::Deserializer::~Deserializer

-- Test Case: 01_DeInitialization
TEST.UNIT:dk_runtime_deserializer
TEST.SUBPROGRAM:(cl)dk::runtime::core::Deserializer::~Deserializer
TEST.NEW
TEST.NAME:01_DeInitialization
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_deserializer.<<GLOBAL>>.(cl).dk::runtime::core::Deserializer.dk::runtime::core::Deserializer.<<constructor>>.Deserializer(uint32_t).<<call>>:0
TEST.FLOW
  dk_runtime_deserializer.cpp.(cl)dk::runtime::core::Deserializer::~Deserializer
  dk_runtime_deserializer.cpp.(cl)dk::runtime::core::Deserializer::~Deserializer
TEST.END_FLOW
TEST.END
