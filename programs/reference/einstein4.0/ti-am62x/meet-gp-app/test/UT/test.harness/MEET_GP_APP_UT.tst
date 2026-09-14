-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : MEET_GP_APP_UT
-- Unit(s) Under Test: meet_application_cfg meet_application_handler meet_component
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

-- Unit: meet_application_handler

-- Subprogram: (cl)dk::lib::meet::MeetAppHandler::IOCtrl_DIDHandler

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::IOCtrl_DIDHandler.001
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::IOCtrl_DIDHandler
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::IOCtrl_DIDHandler.001
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::IOCtrl_DIDHandler.digitalOutputControl
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::IOCtrl_DIDHandler
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::IOCtrl_DIDHandler.digitalOutputControl
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.STUB:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::tftFullColorControl
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::IOCtrl_DIDHandler.didId:16#FE31#
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::IOCtrl_DIDHandler.opticTestPic
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::IOCtrl_DIDHandler
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::IOCtrl_DIDHandler.opticTestPic
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.STUB:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::tftOpticTestPictures
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::IOCtrl_DIDHandler.didId:16#FE35#
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::IOCtrl_DIDHandler.tftFullColour
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::IOCtrl_DIDHandler
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::IOCtrl_DIDHandler.tftFullColour
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.STUB:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::tftFullColorControl
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::IOCtrl_DIDHandler.didId:16#FD0E#
TEST.END

-- Subprogram: (cl)dk::lib::meet::MeetAppHandler::Init

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::Init.true
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::Init
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::Init.true
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.END

-- Subprogram: (cl)dk::lib::meet::MeetAppHandler::MeetAppHandler

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::MeetAppHandler.001
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::MeetAppHandler
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::MeetAppHandler.001
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.END

-- Subprogram: (cl)dk::lib::meet::MeetAppHandler::RWRead_DIDHandler

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::RWRead_DIDHandler.002
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::RWRead_DIDHandler
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::RWRead_DIDHandler.002
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.STUB:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::gnssReadData
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::gnssReadData.loutdata[0]:234
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::gnssReadData.loutdata[0]:<<function 1>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::gnssReadData.return:1
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::IOCtrl_DIDHandler.didId:INPUT_BASE=16
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::RWRead_DIDHandler.GNSSReadData
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::RWRead_DIDHandler
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::RWRead_DIDHandler.GNSSReadData
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.STUB:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::gnssReadData
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::RWRead_DIDHandler.didId:16#FEC8#
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::gnssReadData.loutdata[0]:16#10#
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::gnssReadData.loutdata[0]:<<function 1>>
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::IOCtrl_DIDHandler.didId:INPUT_BASE=16
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::RWRead_DIDHandler.GNSSReadGPIO
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::RWRead_DIDHandler
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::RWRead_DIDHandler.GNSSReadGPIO
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.STUB:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::gnssReadGPIO
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::RWRead_DIDHandler.didId:16#FE0E#
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::gnssReadGPIO.loutdata[0]:16#10#
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::gnssReadGPIO.loutdata[0]:<<function 1>>
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::IOCtrl_DIDHandler.didId:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::gnssReadData.loutdata.loutdata[0]:INPUT_BASE=16
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::RWRead_DIDHandler.ReadTouchCoordinates
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::RWRead_DIDHandler
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::RWRead_DIDHandler.ReadTouchCoordinates
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.STUB:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::readTouchCoordinates
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::RWRead_DIDHandler.didId:16#FD3B#
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::readTouchCoordinates.loutdata[0]:16#10#
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::readTouchCoordinates.loutdata[0]:<<function 1>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::readTouchCoordinates.return:1
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::IOCtrl_DIDHandler.didId:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::gnssReadData.loutdata.loutdata[0]:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::gnssReadGPIO.loutdata.loutdata[0]:INPUT_BASE=16
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::RWRead_DIDHandler.readPinStatus
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::RWRead_DIDHandler
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::RWRead_DIDHandler.readPinStatus
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.STUB:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::readTouchCoordinates
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::RWRead_DIDHandler.didId:16#FE30#
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::readTouchCoordinates.loutdata[0]:16#10#
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::readTouchCoordinates.loutdata[0]:<<function 1>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::readTouchCoordinates.return:1
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::IOCtrl_DIDHandler.didId:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::gnssReadData.loutdata.loutdata[0]:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::gnssReadGPIO.loutdata.loutdata[0]:INPUT_BASE=16
TEST.END

-- Subprogram: (cl)dk::lib::meet::MeetAppHandler::RWWrite_DIDHandler

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::RWWrite_DIDHandler.True
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::RWWrite_DIDHandler
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::RWWrite_DIDHandler.True
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.END

-- Subprogram: (cl)dk::lib::meet::MeetAppHandler::RoutineCtrl_DIDHandler

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::RoutineCtrl_DIDHandler.001
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::RoutineCtrl_DIDHandler
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::RoutineCtrl_DIDHandler.001
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::RoutineCtrl_DIDHandler.GNSS_sw_version
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::RoutineCtrl_DIDHandler
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::RoutineCtrl_DIDHandler.GNSS_sw_version
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.STUB:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::gnssSWVersionNumber
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::RoutineCtrl_DIDHandler.didId:16#F05A#
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::RWRead_DIDHandler.didId:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::IOCtrl_DIDHandler.didId:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::readTouchCoordinates.loutdata.loutdata[0]:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::gnssReadData.loutdata.loutdata[0]:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::gnssReadGPIO.loutdata.loutdata[0]:INPUT_BASE=16
TEST.END

-- Subprogram: (cl)dk::lib::meet::MeetAppHandler::Stop

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::Stop.false
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::Stop
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::Stop.false
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.screenWindowInit:false
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::Stop.true
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::Stop
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::Stop.true
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.screenWindowInit:true
TEST.END

-- Subprogram: (cl)dk::lib::meet::MeetAppHandler::colour_control

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::colour_control.bo_false
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::colour_control
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::colour_control.bo_false
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::colour_control.data:<<malloc 1>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::colour_control.data[0]:1
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::colour_control.data[0]:<<function 1>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::colour_control.return:1
TEST.EXPECTED:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::colour_control.return:255
TEST.VALUE_USER_CODE:<<dk::lib::meet::MeetAppHandler instance>>.dk::lib::meet::MeetAppHandler.bo
struct gbm_bo *bo_test =(struct gbm_bo *)malloc(sizeof(int));
<<dk::lib::meet::MeetAppHandler instance>>->bo = ( bo_test );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::colour_control.bo_true
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::colour_control
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::colour_control.bo_true
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::colour_control.data:<<malloc 1>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::colour_control.data[0]:1
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::colour_control.data[0]:<<function 1>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::colour_control.return:1
TEST.EXPECTED:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::colour_control.return:255
TEST.VALUE_USER_CODE:<<dk::lib::meet::MeetAppHandler instance>>.dk::lib::meet::MeetAppHandler.bo
<<dk::lib::meet::MeetAppHandler instance>>->bo = ( NULL );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::colour_control.drmModePageFlip_fail
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::colour_control
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::colour_control.drmModePageFlip_fail
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.drmModePageFlip.return:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.mDisplayActive:true
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::colour_control.data:<<malloc 1>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::colour_control.data[0]:1
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::colour_control.data[0]:<<function 1>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::colour_control.return:1
TEST.EXPECTED:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::colour_control.return:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.gbm_surface_lock_front_buffer.return
struct gbm_bo *bo_test =(struct gbm_bo *)malloc(sizeof(int));
//<<dk::lib::meet::MeetAppHandler instance>>->bo = ( bo_test );

<<uut_prototype_stubs.gbm_surface_lock_front_buffer.return>> = ( bo_test );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:<<dk::lib::meet::MeetAppHandler instance>>.dk::lib::meet::MeetAppHandler.bo
struct gbm_bo *bo_test =(struct gbm_bo *)malloc(sizeof(int));
<<dk::lib::meet::MeetAppHandler instance>>->bo = ( bo_test );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::colour_control.drmModeSetCrtc_Fail
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::colour_control
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::colour_control.drmModeSetCrtc_Fail
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.drmModePageFlip.return:1
TEST.VALUE:uut_prototype_stubs.drmModeSetCrtc.return:1
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::colour_control.data:<<malloc 1>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::colour_control.data[0]:1
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::colour_control.data[0]:<<function 1>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::colour_control.return:1
TEST.EXPECTED:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::colour_control.return:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.gbm_surface_lock_front_buffer.return
struct gbm_bo *bo_test =(struct gbm_bo *)malloc(sizeof(int));
//<<dk::lib::meet::MeetAppHandler instance>>->bo = ( bo_test );

<<uut_prototype_stubs.gbm_surface_lock_front_buffer.return>> = ( bo_test );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:<<dk::lib::meet::MeetAppHandler instance>>.dk::lib::meet::MeetAppHandler.bo
struct gbm_bo *bo_test =(struct gbm_bo *)malloc(sizeof(int));
<<dk::lib::meet::MeetAppHandler instance>>->bo = ( bo_test );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::colour_control.drmStatus_true
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::colour_control
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::colour_control.drmStatus_true
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.drmModeAddFB.return:1
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::colour_control.data:<<malloc 1>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::colour_control.data[0]:1
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::colour_control.data[0]:<<function 1>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::colour_control.return:1
TEST.EXPECTED:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::colour_control.return:255
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.gbm_surface_lock_front_buffer.return
struct gbm_bo *bo_test =(struct gbm_bo *)malloc(sizeof(int));
//<<dk::lib::meet::MeetAppHandler instance>>->bo = ( bo_test );

<<uut_prototype_stubs.gbm_surface_lock_front_buffer.return>> = ( bo_test );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:<<dk::lib::meet::MeetAppHandler instance>>.dk::lib::meet::MeetAppHandler.bo
struct gbm_bo *bo_test =(struct gbm_bo *)malloc(sizeof(int));
<<dk::lib::meet::MeetAppHandler instance>>->bo = ( bo_test );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::colour_control.pageFlipStatus_false
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::colour_control
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::colour_control.pageFlipStatus_false
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.drmModePageFlip.return:1
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::colour_control.data:<<malloc 1>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::colour_control.data[0]:1
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::colour_control.data[0]:<<function 1>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::colour_control.return:1
TEST.EXPECTED:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::colour_control.return:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.gbm_surface_lock_front_buffer.return
struct gbm_bo *bo_test =(struct gbm_bo *)malloc(sizeof(int));
//<<dk::lib::meet::MeetAppHandler instance>>->bo = ( bo_test );

<<uut_prototype_stubs.gbm_surface_lock_front_buffer.return>> = ( bo_test );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:<<dk::lib::meet::MeetAppHandler instance>>.dk::lib::meet::MeetAppHandler.bo
struct gbm_bo *bo_test =(struct gbm_bo *)malloc(sizeof(int));
<<dk::lib::meet::MeetAppHandler instance>>->bo = ( bo_test );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::colour_control.pageFlipStatus_true
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::colour_control
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::colour_control.pageFlipStatus_true
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.drmModePageFlip.return:1
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.mDisplayActive:true
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::colour_control.data:<<malloc 1>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::colour_control.data[0]:1
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::colour_control.data[0]:<<function 1>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::colour_control.return:1
TEST.EXPECTED:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::colour_control.return:255
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.gbm_surface_lock_front_buffer.return
struct gbm_bo *bo_test =(struct gbm_bo *)malloc(sizeof(int));
//<<dk::lib::meet::MeetAppHandler instance>>->bo = ( bo_test );

<<uut_prototype_stubs.gbm_surface_lock_front_buffer.return>> = ( bo_test );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:<<dk::lib::meet::MeetAppHandler instance>>.dk::lib::meet::MeetAppHandler.bo
struct gbm_bo *bo_test =(struct gbm_bo *)malloc(sizeof(int));
<<dk::lib::meet::MeetAppHandler instance>>->bo = ( bo_test );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::colour_control.surface_lock_front_buff_false
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::colour_control
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::colour_control.surface_lock_front_buff_false
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::colour_control.data:<<malloc 1>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::colour_control.data[0]:1
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::colour_control.data[0]:<<function 1>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::colour_control.return:1
TEST.EXPECTED:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::colour_control.return:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.gbm_surface_lock_front_buffer.return
struct gbm_bo *bo_test =(struct gbm_bo *)malloc(sizeof(int));
//<<dk::lib::meet::MeetAppHandler instance>>->bo = ( bo_test );

<<uut_prototype_stubs.gbm_surface_lock_front_buffer.return>> = ( bo_test );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:<<dk::lib::meet::MeetAppHandler instance>>.dk::lib::meet::MeetAppHandler.bo
struct gbm_bo *bo_test =(struct gbm_bo *)malloc(sizeof(int));
<<dk::lib::meet::MeetAppHandler instance>>->bo = ( bo_test );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::lib::meet::MeetAppHandler::deinit_screen_window

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::clear_eglContext
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::deinit_screen_window
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::clear_eglContext
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.eglContext:1
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.shader_program:1
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.texture:0
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::clear_shader_program
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::deinit_screen_window
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::clear_shader_program
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.shader_program:1
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.texture:0
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::deinit_screen_window.bo_false
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::deinit_screen_window
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::deinit_screen_window.bo_false
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.drmDropMaster.return:16#10#
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.eglDisplay:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.eglContext:1
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.vbo:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.shader_program:1
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.texture:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.drm_fd:16#1#
TEST.VALUE_USER_CODE:<<dk::lib::meet::MeetAppHandler instance>>.dk::lib::meet::MeetAppHandler.gbm
struct gbm_device *gbm_test =(struct gbm_device *)malloc(sizeof(int));
<<dk::lib::meet::MeetAppHandler instance>>->gbm = ( gbm_test );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:<<dk::lib::meet::MeetAppHandler instance>>.dk::lib::meet::MeetAppHandler.gbmSurface
struct gbm_surface* surf = (gbm_surface *)malloc(sizeof(int));
<<dk::lib::meet::MeetAppHandler instance>>->gbmSurface = ( surf );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:<<dk::lib::meet::MeetAppHandler instance>>.dk::lib::meet::MeetAppHandler.bo
<<dk::lib::meet::MeetAppHandler instance>>->bo = ( NULL );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::deinit_screen_window.bo_true
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::deinit_screen_window
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::deinit_screen_window.bo_true
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.drmDropMaster.return:16#10#
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.eglDisplay:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.eglContext:1
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.vbo:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.shader_program:1
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.texture:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.drm_fd:16#1#
TEST.VALUE_USER_CODE:<<dk::lib::meet::MeetAppHandler instance>>.dk::lib::meet::MeetAppHandler.gbm
struct gbm_device *gbm_test =(struct gbm_device *)malloc(sizeof(int));
<<dk::lib::meet::MeetAppHandler instance>>->gbm = ( gbm_test );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:<<dk::lib::meet::MeetAppHandler instance>>.dk::lib::meet::MeetAppHandler.gbmSurface
struct gbm_surface* surf = (gbm_surface *)malloc(sizeof(int));
<<dk::lib::meet::MeetAppHandler instance>>->gbmSurface = ( surf );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:<<dk::lib::meet::MeetAppHandler instance>>.dk::lib::meet::MeetAppHandler.bo
struct gbm_bo *bo_test =(struct gbm_bo *)malloc(sizeof(int));
<<dk::lib::meet::MeetAppHandler instance>>->bo = ( bo_test );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::deinit_screen_window.clearTexture
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::deinit_screen_window
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::deinit_screen_window.clearTexture
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.texture:1
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::deinit_screen_window.eglContext_true
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::deinit_screen_window
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::deinit_screen_window.eglContext_true
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.drmDropMaster.return:16#10#
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.eglDisplay:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.eglSurface:1
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.eglContext:1
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.vbo:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.shader_program:1
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.texture:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.drm_fd:16#1#
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::deinit_screen_window.gbm_true
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::deinit_screen_window
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::deinit_screen_window.gbm_true
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.drmDropMaster.return:16#10#
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.eglDisplay:1
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.eglContext:1
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.vbo:1
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.shader_program:1
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.texture:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.drm_fd:16#1#
TEST.VALUE_USER_CODE:<<dk::lib::meet::MeetAppHandler instance>>.dk::lib::meet::MeetAppHandler.gbm
struct gbm_device *gbm_test =(struct gbm_device *)malloc(sizeof(int));
<<dk::lib::meet::MeetAppHandler instance>>->gbm = ( gbm_test );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:<<dk::lib::meet::MeetAppHandler instance>>.dk::lib::meet::MeetAppHandler.bo
struct gbm_bo *bo_test =(struct gbm_bo *)malloc(sizeof(int));
<<dk::lib::meet::MeetAppHandler instance>>->bo = ( bo_test );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::drmDropMaster
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::deinit_screen_window
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::drmDropMaster
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.drmDropMaster.return:16#10#
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.eglDisplay:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.eglContext:1
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.vbo:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.shader_program:1
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.texture:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.drm_fd:16#1#
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::drmDropMaster_fail
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::deinit_screen_window
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::drmDropMaster_fail
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.texture:0
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::drmModeFreeResources
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::deinit_screen_window
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::drmModeFreeResources
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::drm_fd_fail
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::deinit_screen_window
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::drm_fd_fail
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.eglDisplay:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.eglContext:1
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.vbo:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.shader_program:1
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.texture:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.drm_fd:-1
TEST.END

-- Subprogram: (cl)dk::lib::meet::MeetAppHandler::digitalOutputControl

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::digitalOutputControl.True
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::digitalOutputControl
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::digitalOutputControl.True
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.STUB:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digital_output_pins
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digitalOutputControl.data:<<malloc 3>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digitalOutputControl.data[0]:12
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digitalOutputControl.data[0]:<<function 1>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digitalOutputControl.data[1]:40
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digitalOutputControl.data[1]:<<function 1>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digitalOutputControl.data[2]:40
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digitalOutputControl.data[2]:<<function 1>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digitalOutputControl.return:1
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digital_output_pins.return:1
TEST.EXPECTED:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digitalOutputControl.return:0
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::digitalOutputControl.controlMode_3
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::digitalOutputControl
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::digitalOutputControl.controlMode_3
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.STUB:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digital_output_pins
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digitalOutputControl.controlMode:3
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digitalOutputControl.data:<<malloc 3>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digitalOutputControl.data[0]:12
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digitalOutputControl.data[0]:<<function 1>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digitalOutputControl.data[1]:40
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digitalOutputControl.data[1]:<<function 1>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digitalOutputControl.data[2]:40
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digitalOutputControl.data[2]:<<function 1>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digitalOutputControl.return:1
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digital_output_pins.return:1
TEST.EXPECTED:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digitalOutputControl.return:0
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::digitalOutputControl.false
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::digitalOutputControl
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::digitalOutputControl.false
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.STUB:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digital_output_pins
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digitalOutputControl.data:<<malloc 3>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digitalOutputControl.data[0]:12
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digitalOutputControl.data[0]:<<function 1>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digitalOutputControl.data[1]:40
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digitalOutputControl.data[1]:<<function 1>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digitalOutputControl.data[2]:40
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digitalOutputControl.data[2]:<<function 1>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digitalOutputControl.return:1
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digital_output_pins.return:-1
TEST.EXPECTED:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digitalOutputControl.return:114
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::digitalOutputControl.incorrectControlMode
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::digitalOutputControl
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::digitalOutputControl.incorrectControlMode
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.STUB:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digital_output_pins
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digitalOutputControl.controlMode:4
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digitalOutputControl.data:<<malloc 3>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digitalOutputControl.data[0]:12
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digitalOutputControl.data[0]:<<function 1>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digitalOutputControl.data[1]:40
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digitalOutputControl.data[1]:<<function 1>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digitalOutputControl.data[2]:40
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digitalOutputControl.data[2]:<<function 1>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digitalOutputControl.return:1
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digital_output_pins.return:1
TEST.EXPECTED:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digitalOutputControl.return:255
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::digitalOutputControl.incorrectDataSize
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::digitalOutputControl
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::digitalOutputControl.incorrectDataSize
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.STUB:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digital_output_pins
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digitalOutputControl.data:<<malloc 2>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digitalOutputControl.data[0]:21
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digitalOutputControl.data[0]:<<function 1>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digitalOutputControl.data[1]:40
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digitalOutputControl.data[1]:<<function 1>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digitalOutputControl.return:1
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digital_output_pins.return:1
TEST.EXPECTED:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digitalOutputControl.return:19
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::digitalOutputControl.incorrectPortIndex
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::digitalOutputControl
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::digitalOutputControl.incorrectPortIndex
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.STUB:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digital_output_pins
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digitalOutputControl.data:<<malloc 3>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digitalOutputControl.data[0]:21
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digitalOutputControl.data[0]:<<function 1>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digitalOutputControl.data[1]:40
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digitalOutputControl.data[1]:<<function 1>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digitalOutputControl.data[2]:40
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digitalOutputControl.data[2]:<<function 1>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digitalOutputControl.return:1
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digital_output_pins.return:1
TEST.EXPECTED:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digitalOutputControl.return:34
TEST.END

-- Subprogram: (cl)dk::lib::meet::MeetAppHandler::digital_output_pins

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::digital_output_pins.getMappedFail
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::digital_output_pins
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::digital_output_pins.getMappedFail
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.STUB:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getMappedValue
TEST.VALUE:uut_prototype_stubs.dk_bspal_dio_set_value.return:-1
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getMappedValue.return:-1
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digital_output_pins.portIndex:12
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digital_output_pins.maskByte:8#1#
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digital_output_pins.outputBytes:8#0#
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digital_output_pins.return:1
TEST.EXPECTED:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digital_output_pins.return:-1
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::digital_output_pins.setPinFail
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::digital_output_pins
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::digital_output_pins.setPinFail
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.dk_bspal_dio_set_value.return:-1
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digital_output_pins.portIndex:12
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digital_output_pins.maskByte:8#1#
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digital_output_pins.outputBytes:8#1#
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digital_output_pins.return:1
TEST.EXPECTED:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digital_output_pins.return:-1
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::digital_output_pins.setPinLow
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::digital_output_pins
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::digital_output_pins.setPinLow
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.dk_bspal_dio_set_value.return:-1
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digital_output_pins.portIndex:12
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digital_output_pins.maskByte:8#1#
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digital_output_pins.outputBytes:8#0#
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digital_output_pins.return:1
TEST.EXPECTED:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digital_output_pins.return:-1
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::digital_output_pins.true
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::digital_output_pins
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::digital_output_pins.true
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digital_output_pins.portIndex:12
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digital_output_pins.maskByte:8#1#
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digital_output_pins.outputBytes:8#1#
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digital_output_pins.return:1
TEST.EXPECTED:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::digital_output_pins.return:0
TEST.END

-- Subprogram: (cl)dk::lib::meet::MeetAppHandler::display_full_colour_test

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::display_full_colour_test.colourControlStatus_false
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::display_full_colour_test
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::display_full_colour_test.colourControlStatus_false
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.STUB:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::init_screen_window
TEST.STUB:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::colour_control
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.screenWindowInit:true
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::display_full_colour_test.return:1
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::colour_control.return:16#11#
TEST.EXPECTED:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::display_full_colour_test.return:255
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::display_full_colour_test.screenInitStatus_false
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::display_full_colour_test
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::display_full_colour_test.screenInitStatus_false
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).lMeetComponent.dk::lib::meet::MeetComponent.<<constructor>>.MeetComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.screenInitStatus:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::display_full_colour_test.return:1
TEST.EXPECTED:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::display_full_colour_test.return:255
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::colour_control.return:INPUT_BASE=16
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::display_full_colour_test.screenInitStatus_true
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::display_full_colour_test
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::display_full_colour_test.screenInitStatus_true
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.STUB:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::init_screen_window
TEST.STUB:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::colour_control
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.screenInitStatus:1
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::display_full_colour_test.return:1
TEST.EXPECTED:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::display_full_colour_test.return:0
TEST.END

-- Subprogram: (cl)dk::lib::meet::MeetAppHandler::display_pattern

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::display_pattern.bo_fail
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::display_pattern
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::display_pattern.bo_fail
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.STUB:meet_application_handler.stbi_load
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::display_pattern.return:1
TEST.VALUE:meet_application_handler.stbi_load.return:<<malloc 1>>
TEST.VALUE:meet_application_handler.stbi_load.return[0]:1
TEST.EXPECTED:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::display_pattern.return:255
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::display_pattern.bo_true
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::display_pattern
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::display_pattern.bo_true
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.STUB:meet_application_handler.stbi__fopen
TEST.STUB:meet_application_handler.stbi_load
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::display_pattern.return:1
TEST.VALUE:meet_application_handler.stbi__fopen.filename:"0"
TEST.VALUE:meet_application_handler.stbi__fopen.mode:"0"
TEST.VALUE:meet_application_handler.stbi_load.filename[0]:'1'
TEST.VALUE:meet_application_handler.stbi_load.return:<<malloc 1>>
TEST.VALUE:meet_application_handler.stbi_load.return[0]:1
TEST.EXPECTED:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::display_pattern.return:255
TEST.VALUE_USER_CODE:<<dk::lib::meet::MeetAppHandler instance>>.dk::lib::meet::MeetAppHandler.bo
struct gbm_bo *bo_test =(struct gbm_bo *)malloc(sizeof(int));
<<dk::lib::meet::MeetAppHandler instance>>->bo = ( bo_test );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::display_pattern.drmModePageFlip_true
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::display_pattern
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::display_pattern.drmModePageFlip_true
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.STUB:meet_application_handler.stbi__fopen
TEST.STUB:meet_application_handler.stbi_load
TEST.VALUE:uut_prototype_stubs.drmModePageFlip.return:1
TEST.VALUE:uut_prototype_stubs.drmModeSetCrtc.return:-1
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.mDisplayActive:true
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::display_pattern.return:1
TEST.VALUE:meet_application_handler.stbi__fopen.filename:"0"
TEST.VALUE:meet_application_handler.stbi__fopen.mode:"0"
TEST.VALUE:meet_application_handler.stbi_load.filename[0]:'1'
TEST.VALUE:meet_application_handler.stbi_load.return:<<malloc 1>>
TEST.VALUE:meet_application_handler.stbi_load.return[0]:1
TEST.EXPECTED:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::display_pattern.return:255
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.gbm_surface_lock_front_buffer.return
struct gbm_bo *gbm_test =(struct gbm_bo *)malloc(sizeof(int));
<<uut_prototype_stubs.gbm_surface_lock_front_buffer.return>> = ( gbm_test );

TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:<<dk::lib::meet::MeetAppHandler instance>>.dk::lib::meet::MeetAppHandler.bo
struct gbm_bo *bo_test =(struct gbm_bo *)malloc(sizeof(int));
<<dk::lib::meet::MeetAppHandler instance>>->bo = ( bo_test );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::display_pattern.drmModeSetCrtc_fail
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::display_pattern
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::display_pattern.drmModeSetCrtc_fail
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.STUB:meet_application_handler.stbi__fopen
TEST.STUB:meet_application_handler.stbi_load
TEST.VALUE:uut_prototype_stubs.drmModeSetCrtc.return:-1
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::display_pattern.return:1
TEST.VALUE:meet_application_handler.stbi__fopen.filename:"0"
TEST.VALUE:meet_application_handler.stbi__fopen.mode:"0"
TEST.VALUE:meet_application_handler.stbi_load.filename[0]:'1'
TEST.VALUE:meet_application_handler.stbi_load.return:<<malloc 1>>
TEST.VALUE:meet_application_handler.stbi_load.return[0]:1
TEST.EXPECTED:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::display_pattern.return:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.gbm_surface_lock_front_buffer.return
struct gbm_bo *gbm_test =(struct gbm_bo *)malloc(sizeof(int));
<<uut_prototype_stubs.gbm_surface_lock_front_buffer.return>> = ( gbm_test );

TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:<<dk::lib::meet::MeetAppHandler instance>>.dk::lib::meet::MeetAppHandler.bo
struct gbm_bo *bo_test =(struct gbm_bo *)malloc(sizeof(int));
<<dk::lib::meet::MeetAppHandler instance>>->bo = ( bo_test );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::display_pattern.drmModeSetCrtc_true
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::display_pattern
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::display_pattern.drmModeSetCrtc_true
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.STUB:meet_application_handler.stbi__fopen
TEST.STUB:meet_application_handler.stbi_load
TEST.VALUE:uut_prototype_stubs.drmModeSetCrtc.return:-1
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.mDisplayActive:true
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::display_pattern.return:1
TEST.VALUE:meet_application_handler.stbi__fopen.filename:"0"
TEST.VALUE:meet_application_handler.stbi__fopen.mode:"0"
TEST.VALUE:meet_application_handler.stbi_load.filename[0]:'1'
TEST.VALUE:meet_application_handler.stbi_load.return:<<malloc 1>>
TEST.VALUE:meet_application_handler.stbi_load.return[0]:1
TEST.EXPECTED:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::display_pattern.return:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.gbm_surface_lock_front_buffer.return
struct gbm_bo *gbm_test =(struct gbm_bo *)malloc(sizeof(int));
<<uut_prototype_stubs.gbm_surface_lock_front_buffer.return>> = ( gbm_test );

TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:<<dk::lib::meet::MeetAppHandler instance>>.dk::lib::meet::MeetAppHandler.bo
struct gbm_bo *bo_test =(struct gbm_bo *)malloc(sizeof(int));
<<dk::lib::meet::MeetAppHandler instance>>->bo = ( bo_test );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::display_pattern.drmStatus_true
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::display_pattern
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::display_pattern.drmStatus_true
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.STUB:meet_application_handler.stbi__fopen
TEST.STUB:meet_application_handler.stbi_load
TEST.VALUE:uut_prototype_stubs.drmModeAddFB.return:1
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::display_pattern.return:1
TEST.VALUE:meet_application_handler.stbi__fopen.filename:"0"
TEST.VALUE:meet_application_handler.stbi__fopen.mode:"0"
TEST.VALUE:meet_application_handler.stbi_load.filename[0]:'1'
TEST.VALUE:meet_application_handler.stbi_load.return:<<malloc 1>>
TEST.VALUE:meet_application_handler.stbi_load.return[0]:1
TEST.EXPECTED:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::display_pattern.return:255
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.gbm_surface_lock_front_buffer.return
struct gbm_bo *gbm_test =(struct gbm_bo *)malloc(sizeof(int));
<<uut_prototype_stubs.gbm_surface_lock_front_buffer.return>> = ( gbm_test );

TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:<<dk::lib::meet::MeetAppHandler instance>>.dk::lib::meet::MeetAppHandler.bo
struct gbm_bo *bo_test =(struct gbm_bo *)malloc(sizeof(int));
<<dk::lib::meet::MeetAppHandler instance>>->bo = ( bo_test );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::display_pattern.gbm_surface_lock_front_buff_false
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::display_pattern
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::display_pattern.gbm_surface_lock_front_buff_false
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.STUB:meet_application_handler.stbi__fopen
TEST.STUB:meet_application_handler.stbi_load
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::display_pattern.return:1
TEST.VALUE:meet_application_handler.stbi__fopen.filename:"0"
TEST.VALUE:meet_application_handler.stbi__fopen.mode:"0"
TEST.VALUE:meet_application_handler.stbi_load.filename[0]:'1'
TEST.VALUE:meet_application_handler.stbi_load.return:<<malloc 1>>
TEST.VALUE:meet_application_handler.stbi_load.return[0]:1
TEST.EXPECTED:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::display_pattern.return:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.gbm_surface_lock_front_buffer.return
struct gbm_bo *gbm_test =(struct gbm_bo *)malloc(sizeof(int));
<<uut_prototype_stubs.gbm_surface_lock_front_buffer.return>> = ( gbm_test );

TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:<<dk::lib::meet::MeetAppHandler instance>>.dk::lib::meet::MeetAppHandler.bo
struct gbm_bo *bo_test =(struct gbm_bo *)malloc(sizeof(int));
<<dk::lib::meet::MeetAppHandler instance>>->bo = ( bo_test );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::display_pattern.pageFlipStatus_true
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::display_pattern
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::display_pattern.pageFlipStatus_true
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.STUB:meet_application_handler.stbi__fopen
TEST.STUB:meet_application_handler.stbi_load
TEST.VALUE:uut_prototype_stubs.drmModePageFlip.return:1
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::display_pattern.return:1
TEST.VALUE:meet_application_handler.stbi__fopen.filename:"0"
TEST.VALUE:meet_application_handler.stbi__fopen.mode:"0"
TEST.VALUE:meet_application_handler.stbi_load.filename[0]:'1'
TEST.VALUE:meet_application_handler.stbi_load.return:<<malloc 1>>
TEST.VALUE:meet_application_handler.stbi_load.return[0]:1
TEST.EXPECTED:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::display_pattern.return:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.gbm_surface_lock_front_buffer.return
struct gbm_bo *gbm_test =(struct gbm_bo *)malloc(sizeof(int));
<<uut_prototype_stubs.gbm_surface_lock_front_buffer.return>> = ( gbm_test );

TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:<<dk::lib::meet::MeetAppHandler instance>>.dk::lib::meet::MeetAppHandler.bo
struct gbm_bo *bo_test =(struct gbm_bo *)malloc(sizeof(int));
<<dk::lib::meet::MeetAppHandler instance>>->bo = ( bo_test );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::gbmSurfaceNull
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::display_pattern
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::gbmSurfaceNull
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::display_pattern.return:1
TEST.EXPECTED:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::display_pattern.return:255
TEST.END

-- Subprogram: (cl)dk::lib::meet::MeetAppHandler::getCurrentState

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::getCurrentState.Fail
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::getCurrentState
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::getCurrentState.Fail
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.sd_bus_call_method.return:-1
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getCurrentState.return:-1
TEST.EXPECTED:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getCurrentState.return:-1
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::getCurrentState.Success
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::getCurrentState
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::getCurrentState.Success
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.sd_bus_call_method.return:0
TEST.VALUE:uut_prototype_stubs.sd_bus_message_read.return:-1
TEST.VALUE:uut_prototype_stubs.sd_bus_message_enter_container.return:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getCurrentState.return:-1
TEST.EXPECTED:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getCurrentState.return:-1
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::sd_bus_message_container_fail
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::getCurrentState
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::sd_bus_message_container_fail
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.sd_bus_call_method.return:0
TEST.VALUE:uut_prototype_stubs.sd_bus_message_enter_container.return:-1
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getCurrentState.return:-1
TEST.EXPECTED:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getCurrentState.return:-1
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::sd_bus_message_read_fail
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::getCurrentState
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::sd_bus_message_read_fail
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.sd_bus_call_method.return:0
TEST.VALUE:uut_prototype_stubs.sd_bus_message_enter_container.return:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getCurrentState.return:-1
TEST.EXPECTED:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getCurrentState.return:0
TEST.END

-- Subprogram: (cl)dk::lib::meet::MeetAppHandler::getMappedValue

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::getMappedValue.False
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::getMappedValue
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::getMappedValue.False
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getMappedValue.pin:1
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getMappedValue.return:1
TEST.EXPECTED:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getMappedValue.return:-1
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::getMappedValue.True
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::getMappedValue
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::getMappedValue.True
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getMappedValue.pin:96
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getMappedValue.return:1
TEST.EXPECTED:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getMappedValue.return:1
TEST.END

-- Subprogram: (cl)dk::lib::meet::MeetAppHandler::getObjectPath

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::getObjectPath.Success
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::getObjectPath
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::getObjectPath.Success
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getObjectPath.return:-1
TEST.EXPECTED:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getObjectPath.return:0
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::getObjectPath.sd_bus_call_method_fail
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::getObjectPath
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::getObjectPath.sd_bus_call_method_fail
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.sd_bus_call_method.return:-1
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getObjectPath.return:0
TEST.EXPECTED:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getObjectPath.return:-1
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::getObjectPath.sd_bus_message_read_fail
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::getObjectPath
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::getObjectPath.sd_bus_message_read_fail
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.sd_bus_call_method.return:1
TEST.VALUE:uut_prototype_stubs.sd_bus_message_read.return:-1
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getObjectPath.return:0
TEST.EXPECTED:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getObjectPath.return:-1
TEST.END

-- Subprogram: (cl)dk::lib::meet::MeetAppHandler::gnssReadData

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::gnssReadData.gnssReadDataResponse_Fail
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::gnssReadData
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::gnssReadData.gnssReadDataResponse_Fail
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).lMeetComponent.dk::lib::meet::MeetComponent.<<constructor>>.MeetComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.mpMeetComponent.dk::lib::meet::MeetComponent.gnssReadDataResponse:false
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::gnssReadData.gnssReadDataResponse_True
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::gnssReadData
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::gnssReadData.gnssReadDataResponse_True
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).lMeetComponent.dk::lib::meet::MeetComponent.<<constructor>>.MeetComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.mpMeetComponent.dk::lib::meet::MeetComponent.gnssReadDataResponse:true
TEST.END

-- Subprogram: (cl)dk::lib::meet::MeetAppHandler::gnssReadGPIO

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::gnssReadGPIO.response_false
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::gnssReadGPIO
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::gnssReadGPIO.response_false
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.STUB:meet_application_handler.stbi__fopen
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).lMeetComponent.dk::lib::meet::MeetComponent.<<constructor>>.MeetComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.mpMeetComponent.dk::lib::meet::MeetComponent.gnssReadDataResponse:true
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.mpMeetComponent.dk::lib::meet::MeetComponent.gnssReadGPIOResponse:false
TEST.VALUE:meet_application_handler.stbi__fopen.filename:"card"
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::gnssReadGPIO.response_true
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::gnssReadGPIO
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::gnssReadGPIO.response_true
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.STUB:meet_application_handler.stbi__fopen
TEST.STUB:meet_component.(cl)dk::lib::meet::MeetComponent::SendGnssRequest
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).lMeetComponent.dk::lib::meet::MeetComponent.<<constructor>>.MeetComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.mpMeetComponent.dk::lib::meet::MeetComponent.gnssReadGPIOResponse:true
TEST.VALUE:meet_application_handler.stbi__fopen.filename:"c"
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::gnssReadGPIO.response_true.001
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::gnssReadGPIO
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::gnssReadGPIO.response_true.001
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.STUB:uut_prototype_stubs.std::condition_variable::wait
TEST.STUB:meet_application_handler.stbi__fopen
TEST.STUB:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::MeetAppHandler
TEST.STUB:meet_component.(cl)dk::lib::meet::MeetComponent::onReceiveMeetGNSSSResp
TEST.STUB:meet_component.(cl)dk::lib::meet::MeetComponent::SendGnssRequest
TEST.VALUE:uut_prototype_stubs.std::condition_variable::wait.VCAST_PARAM_1.std::unique_lock<std::mutex>.<<constructor>>.unique_lock(std::unique_lock<std::mutex>::mutex_type&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).lMeetComponent.dk::lib::meet::MeetComponent.<<constructor>>.MeetComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).lMeetComponent.dk::lib::meet::MeetComponent.gnssReadDataResponse:true
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).lMeetComponent.dk::lib::meet::MeetComponent.gnssReadGPIOResponse:(2)true
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).lMeetComponent.dk::lib::meet::MeetComponent.gnssReadGnssSWVersionResponse:true
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).lMeetComponent.dk::lib::meet::MeetComponent.mGnssResponseMsgData.responseType:EGNSSType_ReadGPIO
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).lMeetComponent.dk::lib::meet::MeetComponent.mpPthreadDiagReq.std::thread.<<constructor>>.thread(void (*)(void)).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).lMeetComponent.dk::lib::meet::MeetComponent.mpDiagReqSem.dk::osal::Semaphore.<<constructor>>.Semaphore(const dk::osal::Semaphore&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.mpMeetComponent.dk::lib::meet::MeetComponent.gnssReadDataResponse:true
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.mpMeetComponent.dk::lib::meet::MeetComponent.gnssReadGPIOResponse:(2)true
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.mpMeetComponent.dk::lib::meet::MeetComponent.gnssReadGnssSWVersionResponse:true
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.mpMeetComponent.dk::lib::meet::MeetComponent.mpPthreadDiagReq.std::thread.<<constructor>>.thread(void (*)(void)).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.mpMeetComponent.dk::lib::meet::MeetComponent.mpDiagReqSem.dk::osal::Semaphore.<<constructor>>.Semaphore(const dk::osal::Semaphore&).<<call>>:0
TEST.VALUE:meet_application_handler.stbi__fopen.filename:"c"
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::MeetAppHandler.lMeetComponent.dk::lib::meet::MeetComponent.<<constructor>>.MeetComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::onReceiveMeetGNSSSResp.msg.responseType:1
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::onReceiveMeetGNSSSResp.msg.status:1
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::onReceiveMeetGNSSSResp.msg.length:2
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendGnssRequest.gnssReq.requestType:0
TEST.END

-- Subprogram: (cl)dk::lib::meet::MeetAppHandler::gnssSWVersionNumber

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::gnssSWVersionNumber.False
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::gnssSWVersionNumber
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::gnssSWVersionNumber.False
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).lMeetComponent.dk::lib::meet::MeetComponent.<<constructor>>.MeetComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).lMeetComponent.dk::lib::meet::MeetComponent.gnssReadGnssSWVersionResponse:false
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).lMeetComponent.dk::lib::meet::MeetComponent.mGnssResponseMsgData.status:EGNSSStatus_Nok
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).lMeetComponent.dk::lib::meet::MeetComponent.mpPthreadDiagReq.std::thread.<<constructor>>.thread(void (*)(void)).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).lMeetComponent.dk::lib::meet::MeetComponent.mpDiagReqSem.dk::osal::Semaphore.<<constructor>>.Semaphore(const dk::osal::Semaphore&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.mpMeetComponent.dk::lib::meet::MeetComponent.gnssReadDataResponse:true
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.mpMeetComponent.dk::lib::meet::MeetComponent.gnssReadGnssSWVersionResponse:false
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::gnssSWVersionNumber.True
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::gnssSWVersionNumber
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::gnssSWVersionNumber.True
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).lMeetComponent.dk::lib::meet::MeetComponent.<<constructor>>.MeetComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).lMeetComponent.dk::lib::meet::MeetComponent.mpPthreadDiagReq.std::thread.<<constructor>>.thread(void (*)(void)).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).lMeetComponent.dk::lib::meet::MeetComponent.mpDiagReqSem.dk::osal::Semaphore.<<constructor>>.Semaphore(const dk::osal::Semaphore&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.mpMeetComponent.dk::lib::meet::MeetComponent.gnssReadGnssSWVersionResponse:true
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::gnssSWVersionNumber.gnssReadGnssSWVersionResponse_False
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::gnssSWVersionNumber
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::gnssSWVersionNumber.gnssReadGnssSWVersionResponse_False
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::gnssSWVersionNumber.gnssReadGnssSWVersionResponse_True
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::gnssSWVersionNumber
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::gnssSWVersionNumber.gnssReadGnssSWVersionResponse_True
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).lMeetComponent.dk::lib::meet::MeetComponent.<<constructor>>.MeetComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).lMeetComponent.dk::lib::meet::MeetComponent.mpPthreadDiagReq.std::thread.<<constructor>>.thread(void (*)(void)).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).lMeetComponent.dk::lib::meet::MeetComponent.mpDiagReqSem.dk::osal::Semaphore.<<constructor>>.Semaphore(const dk::osal::Semaphore&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.mpMeetComponent.dk::lib::meet::MeetComponent.gnssReadDataResponse:true
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.mpMeetComponent.dk::lib::meet::MeetComponent.gnssReadGnssSWVersionResponse:true
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::gnssSWVersionNumber.lGnssResponseMsgData_NOK
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::gnssSWVersionNumber
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::gnssSWVersionNumber.lGnssResponseMsgData_NOK
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).lMeetComponent.dk::lib::meet::MeetComponent.<<constructor>>.MeetComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).lMeetComponent.dk::lib::meet::MeetComponent.mGnssResponseMsgData.status:EGNSSStatus_Ok
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).lMeetComponent.dk::lib::meet::MeetComponent.mGnssResponseMsgData.length:1
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).lMeetComponent.dk::lib::meet::MeetComponent.mGnssResponseMsgData.data:<<malloc 1>>
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).lMeetComponent.dk::lib::meet::MeetComponent.mGnssResponseMsgData.data[0]:1
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).lMeetComponent.dk::lib::meet::MeetComponent.mGnssResponseMsgData.data[0]:<<function 1>>
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).lMeetComponent.dk::lib::meet::MeetComponent.mpPthreadDiagReq.std::thread.<<constructor>>.thread(void (*)(void)).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).lMeetComponent.dk::lib::meet::MeetComponent.mpDiagReqSem.dk::osal::Semaphore.<<constructor>>.Semaphore(const dk::osal::Semaphore&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.mpMeetComponent.dk::lib::meet::MeetComponent.gnssReadDataResponse:true
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.mpMeetComponent.dk::lib::meet::MeetComponent.gnssReadGnssSWVersionResponse:true
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::gnssSWVersionNumber.lGnssResponseMsgData_Ok
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::gnssSWVersionNumber
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::gnssSWVersionNumber.lGnssResponseMsgData_Ok
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).lMeetComponent.dk::lib::meet::MeetComponent.<<constructor>>.MeetComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).lMeetComponent.dk::lib::meet::MeetComponent.mGnssResponseMsgData.status:EGNSSStatus_Ok
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).lMeetComponent.dk::lib::meet::MeetComponent.mpPthreadDiagReq.std::thread.<<constructor>>.thread(void (*)(void)).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).lMeetComponent.dk::lib::meet::MeetComponent.mpDiagReqSem.dk::osal::Semaphore.<<constructor>>.Semaphore(const dk::osal::Semaphore&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.mpMeetComponent.dk::lib::meet::MeetComponent.gnssReadDataResponse:true
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.mpMeetComponent.dk::lib::meet::MeetComponent.gnssReadGnssSWVersionResponse:true
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::gnssSWVersionNumber.status_Success
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::gnssSWVersionNumber
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::gnssSWVersionNumber.status_Success
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).lMeetComponent.dk::lib::meet::MeetComponent.<<constructor>>.MeetComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).lMeetComponent.dk::lib::meet::MeetComponent.mGnssResponseMsgData.status:EGNSSStatus_Nok
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).lMeetComponent.dk::lib::meet::MeetComponent.mpPthreadDiagReq.std::thread.<<constructor>>.thread(void (*)(void)).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).lMeetComponent.dk::lib::meet::MeetComponent.mpDiagReqSem.dk::osal::Semaphore.<<constructor>>.Semaphore(const dk::osal::Semaphore&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.mpMeetComponent.dk::lib::meet::MeetComponent.gnssReadDataResponse:true
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.mpMeetComponent.dk::lib::meet::MeetComponent.gnssReadGnssSWVersionResponse:true
TEST.END

-- Subprogram: (cl)dk::lib::meet::MeetAppHandler::init_screen_window

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::init_screen_window.001
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::init_screen_window
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::init_screen_window.001
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::init_screen_window.return:1
TEST.EXPECTED:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::init_screen_window.return:-1
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::init_screen_window.DRM_MODE_DISCONNECTED
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::init_screen_window
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::init_screen_window.DRM_MODE_DISCONNECTED
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.open.return:0
TEST.VALUE:uut_prototype_stubs.drmSetMaster.return:0
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.fd:1
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.return[0].fbs:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.return[0].count_crtcs:3
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.return[0].crtcs:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.return[0].count_connectors:1
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.return[0].connectors:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.return[0].encoders:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.drmModeGetCrtc.return:<<null>>
TEST.VALUE:uut_prototype_stubs.drmModeGetConnector.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.drmModeGetConnector.return[0].connection:DRM_MODE_DISCONNECTED
TEST.VALUE:uut_prototype_stubs.drmModeGetConnector.return[0].count_modes:0
TEST.VALUE:uut_prototype_stubs.drmModeGetConnector.return[0].modes:<<malloc 1>>
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.drm_fd:2
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::init_screen_window.return:1
TEST.EXPECTED:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::init_screen_window.return:-1
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::init_screen_window.drmModeGetConnector_fail
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::init_screen_window
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::init_screen_window.drmModeGetConnector_fail
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.open.return:0
TEST.VALUE:uut_prototype_stubs.drmSetMaster.return:0
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.fd:1
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.return[0].fbs:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.return[0].count_crtcs:3
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.return[0].crtcs:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.return[0].count_connectors:1
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.return[0].connectors:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.return[0].encoders:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.drmModeGetCrtc.return:<<null>>
TEST.VALUE:uut_prototype_stubs.drmModeGetConnector.return:<<null>>
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.drm_fd:2
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::init_screen_window.return:1
TEST.EXPECTED:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::init_screen_window.return:-1
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::init_screen_window.eglChooseConfig_true
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::init_screen_window
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::init_screen_window.eglChooseConfig_true
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.open.return:0
TEST.VALUE:uut_prototype_stubs.eglGetDisplay.return:1
TEST.VALUE:uut_prototype_stubs.eglInitialize.return:1
TEST.VALUE:uut_prototype_stubs.eglChooseConfig.return:1
TEST.VALUE:uut_prototype_stubs.drmSetMaster.return:0
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.fd:1
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.return:<<malloc 1>>
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.eglDisplay:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.drm_fd:2
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::init_screen_window.return:1
TEST.EXPECTED:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::init_screen_window.return:-1
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.gbm_create_device.return
struct gbm_device * gbm = (gbm_device*)malloc(sizeof(int));
<<uut_prototype_stubs.gbm_create_device.return>> = ( gbm );

TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::init_screen_window.eglCreateContext_false
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::init_screen_window
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::init_screen_window.eglCreateContext_false
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.open.return:0
TEST.VALUE:uut_prototype_stubs.eglGetDisplay.return:1
TEST.VALUE:uut_prototype_stubs.eglCreateContext.return:1
TEST.VALUE:uut_prototype_stubs.eglInitialize.return:1
TEST.VALUE:uut_prototype_stubs.eglChooseConfig.return:1
TEST.VALUE:uut_prototype_stubs.drmSetMaster.return:0
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.fd:1
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.return:<<malloc 1>>
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.eglDisplay:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.drm_fd:2
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::init_screen_window.return:1
TEST.EXPECTED:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::init_screen_window.return:-1
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.gbm_create_device.return
struct gbm_device * gbm = (gbm_device*)malloc(sizeof(int));
<<uut_prototype_stubs.gbm_create_device.return>> = ( gbm );

TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::init_screen_window.eglCreateWindowSurface
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::init_screen_window
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::init_screen_window.eglCreateWindowSurface
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.open.return:0
TEST.VALUE:uut_prototype_stubs.eglGetDisplay.return:1
TEST.VALUE:uut_prototype_stubs.eglCreateContext.return:1
TEST.VALUE:uut_prototype_stubs.eglCreateWindowSurface.return:1
TEST.VALUE:uut_prototype_stubs.eglInitialize.return:1
TEST.VALUE:uut_prototype_stubs.eglChooseConfig.return:1
TEST.VALUE:uut_prototype_stubs.drmSetMaster.return:0
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.fd:1
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.return:<<malloc 1>>
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.eglDisplay:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.drm_fd:2
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::init_screen_window.return:1
TEST.EXPECTED:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::init_screen_window.return:-1
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.gbm_create_device.return
struct gbm_device * gbm = (gbm_device*)malloc(sizeof(int));
<<uut_prototype_stubs.gbm_create_device.return>> = ( gbm );

TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.gbm_surface_create.return
struct gbm_surface* gbm_surf = (gbm_surface*)malloc(sizeof(int));
<<uut_prototype_stubs.gbm_surface_create.return>> = ( gbm_surf );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::init_screen_window.eglCreateWindowSurface.001
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::init_screen_window
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::init_screen_window.eglCreateWindowSurface.001
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.open.return:0
TEST.VALUE:uut_prototype_stubs.eglGetDisplay.return:0
TEST.VALUE:uut_prototype_stubs.eglCreateContext.return:0
TEST.VALUE:uut_prototype_stubs.eglCreateWindowSurface.return:0
TEST.VALUE:uut_prototype_stubs.eglInitialize.return:1
TEST.VALUE:uut_prototype_stubs.eglChooseConfig.return:1
TEST.VALUE:uut_prototype_stubs.drmSetMaster.return:0
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.fd:1
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.return:<<malloc 1>>
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.eglDisplay:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.eglSurface:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.eglContext:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.drm_fd:2
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::init_screen_window.return:1
TEST.EXPECTED:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::init_screen_window.return:-1
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.gbm_create_device.return
struct gbm_device * gbm = (gbm_device*)malloc(sizeof(int));
<<uut_prototype_stubs.gbm_create_device.return>> = ( gbm );

TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.gbm_surface_create.return
struct gbm_surface* gbm_surf = (gbm_surface*)malloc(sizeof(int));
<<uut_prototype_stubs.gbm_surface_create.return>> = ( gbm_surf );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::init_screen_window.eglInitialize_false
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::init_screen_window
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::init_screen_window.eglInitialize_false
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.open.return:0
TEST.VALUE:uut_prototype_stubs.eglGetDisplay.return:1
TEST.VALUE:uut_prototype_stubs.eglInitialize.return:1
TEST.VALUE:uut_prototype_stubs.drmSetMaster.return:0
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.fd:1
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.return:<<malloc 1>>
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.eglDisplay:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.drm_fd:2
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::init_screen_window.return:1
TEST.EXPECTED:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::init_screen_window.return:-1
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.gbm_create_device.return
struct gbm_device * gbm = (gbm_device*)malloc(sizeof(int));
<<uut_prototype_stubs.gbm_create_device.return>> = ( gbm );

TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::init_screen_window.eglInitialize_true
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::init_screen_window
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::init_screen_window.eglInitialize_true
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.open.return:0
TEST.VALUE:uut_prototype_stubs.eglInitialize.return:0
TEST.VALUE:uut_prototype_stubs.drmSetMaster.return:0
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.fd:1
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.return:<<malloc 1>>
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.eglDisplay:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.drm_fd:2
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::init_screen_window.return:1
TEST.EXPECTED:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::init_screen_window.return:-1
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.gbm_create_device.return
struct gbm_device * gbm = (gbm_device*)malloc(sizeof(int));
<<uut_prototype_stubs.gbm_create_device.return>> = ( gbm );

TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::init_screen_window.eglMakeCurrent_false
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::init_screen_window
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::init_screen_window.eglMakeCurrent_false
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.open.return:0
TEST.VALUE:uut_prototype_stubs.eglGetDisplay.return:1
TEST.VALUE:uut_prototype_stubs.eglCreateContext.return:1
TEST.VALUE:uut_prototype_stubs.eglCreateWindowSurface.return:1
TEST.VALUE:uut_prototype_stubs.eglInitialize.return:1
TEST.VALUE:uut_prototype_stubs.eglMakeCurrent.return:1
TEST.VALUE:uut_prototype_stubs.eglChooseConfig.return:1
TEST.VALUE:uut_prototype_stubs.drmSetMaster.return:0
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.fd:1
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.return:<<malloc 1>>
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.eglDisplay:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.eglSurface:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.eglContext:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.drm_fd:2
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::init_screen_window.return:1
TEST.EXPECTED:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::init_screen_window.return:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.gbm_create_device.return
struct gbm_device * gbm = (gbm_device*)malloc(sizeof(int));
<<uut_prototype_stubs.gbm_create_device.return>> = ( gbm );

TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.gbm_surface_create.return
struct gbm_surface* gbm_surf = (gbm_surface*)malloc(sizeof(int));
<<uut_prototype_stubs.gbm_surface_create.return>> = ( gbm_surf );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::init_screen_window.gbm_create_device_false
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::init_screen_window
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::init_screen_window.gbm_create_device_false
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.open.return:0
TEST.VALUE:uut_prototype_stubs.eglGetDisplay.return:1
TEST.VALUE:uut_prototype_stubs.drmSetMaster.return:0
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.fd:1
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.return:<<malloc 1>>
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.eglDisplay:1
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.drm_fd:2
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::init_screen_window.return:1
TEST.EXPECTED:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::init_screen_window.return:-1
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.gbm_create_device.return
struct gbm_device * gbm = (gbm_device*)malloc(sizeof(int));
<<uut_prototype_stubs.gbm_create_device.return>> = ( gbm );

TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::init_screen_window.gbm_surface_createe
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::init_screen_window
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::init_screen_window.gbm_surface_createe
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.open.return:0
TEST.VALUE:uut_prototype_stubs.eglGetDisplay.return:1
TEST.VALUE:uut_prototype_stubs.eglCreateContext.return:1
TEST.VALUE:uut_prototype_stubs.eglInitialize.return:1
TEST.VALUE:uut_prototype_stubs.eglChooseConfig.return:1
TEST.VALUE:uut_prototype_stubs.drmSetMaster.return:0
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.fd:1
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.return:<<malloc 1>>
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.eglDisplay:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.drm_fd:2
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::init_screen_window.return:1
TEST.EXPECTED:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::init_screen_window.return:-1
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.gbm_create_device.return
struct gbm_device * gbm = (gbm_device*)malloc(sizeof(int));
<<uut_prototype_stubs.gbm_create_device.return>> = ( gbm );

TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.gbm_surface_create.return
struct gbm_surface* gbm_surf = (gbm_surface*)malloc(sizeof(int));
<<uut_prototype_stubs.gbm_surface_create.return>> = ( gbm_surf );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::init_screen_window.numConfigs_true
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::init_screen_window
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::init_screen_window.numConfigs_true
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.open.return:0
TEST.VALUE:uut_prototype_stubs.eglGetDisplay.return:1
TEST.VALUE:uut_prototype_stubs.eglInitialize.return:1
TEST.VALUE:uut_prototype_stubs.eglChooseConfig.num_config[0]:0
TEST.VALUE:uut_prototype_stubs.eglChooseConfig.return:1
TEST.VALUE:uut_prototype_stubs.drmSetMaster.return:0
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.fd:1
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.return:<<malloc 1>>
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.eglDisplay:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.drm_fd:2
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::init_screen_window.return:1
TEST.EXPECTED:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::init_screen_window.return:-1
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.gbm_create_device.return
struct gbm_device * gbm = (gbm_device*)malloc(sizeof(int));
<<uut_prototype_stubs.gbm_create_device.return>> = ( gbm );

TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::init_screen_window.open_false
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::init_screen_window
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::init_screen_window.open_false
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.open.return:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.drm_fd:2
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::init_screen_window.return:1
TEST.EXPECTED:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::init_screen_window.return:-1
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::init_screen_window.open_false.countModes_fail
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::init_screen_window
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::init_screen_window.open_false.countModes_fail
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.open.return:0
TEST.VALUE:uut_prototype_stubs.drmSetMaster.return:0
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.fd:1
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.return[0].fbs:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.return[0].count_crtcs:3
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.return[0].crtcs:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.return[0].count_connectors:1
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.return[0].connectors:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.return[0].encoders:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.drmModeGetCrtc.return:<<null>>
TEST.VALUE:uut_prototype_stubs.drmModeGetConnector.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.drmModeGetConnector.return[0].connection:DRM_MODE_CONNECTED
TEST.VALUE:uut_prototype_stubs.drmModeGetConnector.return[0].count_modes:0
TEST.VALUE:uut_prototype_stubs.drmModeGetConnector.return[0].modes:<<malloc 1>>
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.drm_fd:2
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::init_screen_window.return:1
TEST.EXPECTED:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::init_screen_window.return:-1
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::init_screen_window.open_false.drmModeGetConnector
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::init_screen_window
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::init_screen_window.open_false.drmModeGetConnector
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.open.return:0
TEST.VALUE:uut_prototype_stubs.drmSetMaster.return:0
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.fd:1
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.return[0].fbs:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.return[0].count_crtcs:3
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.return[0].crtcs:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.return[0].count_connectors:1
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.return[0].connectors:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.return[0].encoders:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.drmModeGetCrtc.return:<<null>>
TEST.VALUE:uut_prototype_stubs.drmModeGetConnector.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.drmModeGetConnector.return[0].connection:DRM_MODE_CONNECTED
TEST.VALUE:uut_prototype_stubs.drmModeGetConnector.return[0].count_modes:1
TEST.VALUE:uut_prototype_stubs.drmModeGetConnector.return[0].modes:<<malloc 1>>
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.drm_fd:2
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::init_screen_window.return:1
TEST.EXPECTED:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::init_screen_window.return:-1
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::init_screen_window.open_false.drmModeGetResources
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::init_screen_window
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::init_screen_window.open_false.drmModeGetResources
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.open.return:0
TEST.VALUE:uut_prototype_stubs.drmSetMaster.return:0
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.fd:1
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.return:<<malloc 1>>
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.drm_fd:2
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::init_screen_window.return:1
TEST.EXPECTED:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::init_screen_window.return:-1
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::init_screen_window.open_false.drmModeGetResources.count_crtc_false
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::init_screen_window
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::init_screen_window.open_false.drmModeGetResources.count_crtc_false
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.open.return:0
TEST.VALUE:uut_prototype_stubs.drmSetMaster.return:0
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.fd:1
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.return[0].fbs:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.return[0].count_crtcs:3
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.return[0].crtcs:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.return[0].count_connectors:2
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.return[0].connectors:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.return[0].encoders:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.drmModeGetCrtc.return:<<null>>
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.drm_fd:2
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::init_screen_window.return:1
TEST.EXPECTED:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::init_screen_window.return:-1
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::init_screen_window.open_false.drmModeGetResources.count_crtc_true
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::init_screen_window
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::init_screen_window.open_false.drmModeGetResources.count_crtc_true
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.open.return:0
TEST.VALUE:uut_prototype_stubs.drmSetMaster.return:0
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.fd:1
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.return[0].fbs:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.return[0].count_crtcs:3
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.return[0].crtcs:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.return[0].connectors:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.return[0].encoders:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.drmModeGetCrtc.return:<<malloc 1>>
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.drm_fd:2
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::init_screen_window.return:1
TEST.EXPECTED:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::init_screen_window.return:-1
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::init_screen_window.open_false.drmModeGetResources_true
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::init_screen_window
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::init_screen_window.open_false.drmModeGetResources_true
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.open.return:0
TEST.VALUE:uut_prototype_stubs.drmSetMaster.return:0
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.fd:1
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.return:<<null>>
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.drm_fd:2
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::init_screen_window.return:1
TEST.EXPECTED:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::init_screen_window.return:-1
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::init_screen_window.open_false.drmSetMaster_true
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::init_screen_window
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::init_screen_window.open_false.drmSetMaster_true
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.open.return:0
TEST.VALUE:uut_prototype_stubs.drmSetMaster.return:1
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.drm_fd:2
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::init_screen_window.return:1
TEST.EXPECTED:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::init_screen_window.return:-1
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::init_screen_window.open_false.drm_fd_true
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::init_screen_window
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::init_screen_window.open_false.drm_fd_true
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.open.return:-1
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.drm_fd:2
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::init_screen_window.return:1
TEST.EXPECTED:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::init_screen_window.return:-1
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::init_screen_window.pending
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::init_screen_window
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::init_screen_window.pending
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.open.return:0
TEST.VALUE:uut_prototype_stubs.eglGetDisplay.return:1
TEST.VALUE:uut_prototype_stubs.eglCreateContext.return:1
TEST.VALUE:uut_prototype_stubs.eglCreateWindowSurface.dpy:0
TEST.VALUE:uut_prototype_stubs.eglCreateWindowSurface.return:1
TEST.VALUE:uut_prototype_stubs.eglInitialize.return:1
TEST.VALUE:uut_prototype_stubs.eglMakeCurrent.return:1
TEST.VALUE:uut_prototype_stubs.eglChooseConfig.return:1
TEST.VALUE:uut_prototype_stubs.drmSetMaster.return:0
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.fd:1
TEST.VALUE:uut_prototype_stubs.drmModeGetResources.return:<<malloc 1>>
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.eglDisplay:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.eglConfig:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.eglSurface:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.eglContext:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.drm_fd:2
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::init_screen_window.return:1
TEST.EXPECTED:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::init_screen_window.return:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.gbm_create_device.return
struct gbm_device * gbm = (gbm_device*)malloc(sizeof(int));
<<uut_prototype_stubs.gbm_create_device.return>> = ( gbm );

TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.gbm_surface_create.return
struct gbm_surface* gbm_surf = (gbm_surface*)malloc(sizeof(int));
<<uut_prototype_stubs.gbm_surface_create.return>> = ( gbm_surf );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::lib::meet::MeetAppHandler::loadShaders

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::loadShaders.glGetProgramiv_true
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::loadShaders
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::loadShaders.glGetProgramiv_true
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.glGetProgramiv.params[0]:0
TEST.VALUE:uut_prototype_stubs.glGetProgramiv.params[1]:0
TEST.VALUE:uut_prototype_stubs.glGetProgramiv.params[2]:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::loadShaders.glGetShaderiv_false
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::loadShaders
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::loadShaders.glGetShaderiv_false
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.glGetShaderiv.params[0]:1
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::loadShaders.glGetShaderiv_true
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::loadShaders
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::loadShaders.glGetShaderiv_true
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.END

-- Subprogram: (cl)dk::lib::meet::MeetAppHandler::periodicTask

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::periodicTask.true
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::periodicTask
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::periodicTask.true
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.END

-- Subprogram: (cl)dk::lib::meet::MeetAppHandler::processDiagRcv

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::processDiagRcv.IOCtrl
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::processDiagRcv
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::processDiagRcv.IOCtrl
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::processDiagRcv.pDiagReqMsgData:<<malloc 1>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::processDiagRcv.pDiagReqMsgData[0].mode:EDiagMode_IOCtrl
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::processDiagRcv.pDiagReqMsgData[0].data:<<malloc 1>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::processDiagRcv.pDiagReqMsgData[0].data[0]:1
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::processDiagRcv.pDiagReqMsgData[0].data[0]:<<function 1>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::processDiagRcv.pDiagReqMsgData[0]:<<function 1>>
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::processDiagRcv.RW_WRite
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::processDiagRcv
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::processDiagRcv.RW_WRite
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::processDiagRcv.pDiagReqMsgData:<<malloc 1>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::processDiagRcv.pDiagReqMsgData[0].mode:EDiagMode_RW_Write
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::processDiagRcv.pDiagReqMsgData[0]:<<function 1>>
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::processDiagRcv.default
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::processDiagRcv
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::processDiagRcv.default
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).lMeetComponent.dk::lib::meet::MeetComponent.<<constructor>>.MeetComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::processDiagRcv.pDiagReqMsgData:<<malloc 2>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::processDiagRcv.pDiagReqMsgData[0].mode:5
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::processDiagRcv.pDiagReqMsgData[0]:<<function 1>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::processDiagRcv.pDiagReqMsgData[1]:<<function 1>>
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::processDiagRcv.routine_control
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::processDiagRcv
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::processDiagRcv.routine_control
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::processDiagRcv.pDiagReqMsgData:<<malloc 1>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::processDiagRcv.pDiagReqMsgData[0].mode:EDiagMode_RC
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::processDiagRcv.pDiagReqMsgData[0]:<<function 1>>
TEST.END

-- Subprogram: (cl)dk::lib::meet::MeetAppHandler::readPinStatus

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::readPinStatus.false
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::readPinStatus
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::readPinStatus.false
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.dk_bspal_dio_get_value.return:-1
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::readPinStatus.return:1
TEST.EXPECTED:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::readPinStatus.return:114
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::readPinStatus.true
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::readPinStatus
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::readPinStatus.true
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::readPinStatus.return:1
TEST.EXPECTED:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::readPinStatus.return:0
TEST.END

-- Subprogram: (cl)dk::lib::meet::MeetAppHandler::readTouchCoordinates

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::readTouchCoordinates.false
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::readTouchCoordinates
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::readTouchCoordinates.false
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::readTouchCoordinates.true
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::readTouchCoordinates
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::readTouchCoordinates.true
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::readTouchCoordinates.loutdata:<<malloc 1>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::readTouchCoordinates.loutdata[0]:16#10#
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::readTouchCoordinates.loutdata[0]:<<function 1>>
TEST.END

-- Subprogram: (cl)dk::lib::meet::MeetAppHandler::stopBmwHmi

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::stopBmwHmi.getCurrentState_fail
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::stopBmwHmi
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::stopBmwHmi.getCurrentState_fail
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.STUB:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getCurrentState
TEST.STUB:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getObjectPath
TEST.VALUE:uut_prototype_stubs.sd_bus_open_system.return:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getCurrentState.state[0]:<<malloc 8>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getCurrentState.state[0]:"running"
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getCurrentState.return:-1
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getObjectPath.objPath[0]:<<malloc 13>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getObjectPath.objPath[0]:"/mic.service"
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getObjectPath.return:0
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::RWRead_DIDHandler.didId:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::IOCtrl_DIDHandler.didId:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::RoutineCtrl_DIDHandler.didId:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::readTouchCoordinates.loutdata.loutdata[0]:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::gnssReadData.loutdata.loutdata[0]:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::gnssReadGPIO.loutdata.loutdata[0]:INPUT_BASE=16
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::stopBmwHmi.getObjPathFail
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::stopBmwHmi
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::stopBmwHmi.getObjPathFail
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.STUB:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getCurrentState
TEST.STUB:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getObjectPath
TEST.VALUE:uut_prototype_stubs.sd_bus_open_system.return:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.services:<<malloc 1>>
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.services[0]:<<function 1>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getCurrentState.state[0]:<<malloc 9>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getCurrentState.state[0]:"inactive"
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getCurrentState.return:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getObjectPath.objPath[0]:<<malloc 13>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getObjectPath.objPath[0]:"/mic.service"
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getObjectPath.return:-1
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::RWRead_DIDHandler.didId:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::IOCtrl_DIDHandler.didId:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::RoutineCtrl_DIDHandler.didId:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::readTouchCoordinates.loutdata.loutdata[0]:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::gnssReadData.loutdata.loutdata[0]:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::gnssReadGPIO.loutdata.loutdata[0]:INPUT_BASE=16
TEST.VALUE_USER_CODE:<<dk::lib::meet::MeetAppHandler instance>>.dk::lib::meet::MeetAppHandler.services.services[0]
<<dk::lib::meet::MeetAppHandler instance>>->services[0] = "hmi.service";
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::stopBmwHmi.incorrectService
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::stopBmwHmi
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::stopBmwHmi.incorrectService
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.STUB:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getCurrentState
TEST.STUB:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getObjectPath
TEST.VALUE:uut_prototype_stubs.sd_bus_open_system.return:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.services:<<malloc 1>>
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.services[0]:<<function 1>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getCurrentState.state[0]:<<malloc 9>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getCurrentState.state[0]:"inactive"
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getCurrentState.return:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getObjectPath.objPath[0]:<<malloc 13>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getObjectPath.objPath[0]:"/mic.service"
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getObjectPath.return:0
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::RWRead_DIDHandler.didId:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::IOCtrl_DIDHandler.didId:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::RoutineCtrl_DIDHandler.didId:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::readTouchCoordinates.loutdata.loutdata[0]:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::gnssReadData.loutdata.loutdata[0]:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::gnssReadGPIO.loutdata.loutdata[0]:INPUT_BASE=16
TEST.VALUE_USER_CODE:<<dk::lib::meet::MeetAppHandler instance>>.dk::lib::meet::MeetAppHandler.services.services[0]
<<dk::lib::meet::MeetAppHandler instance>>->services[0] = "hmi.service";
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::stopBmwHmi.mStopMicService_false
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::stopBmwHmi
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::stopBmwHmi.mStopMicService_false
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.sd_bus_open_system.return:-1
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.mStopMicService:true
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.mStopWestonService:true
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::stopBmwHmi.mStopWestonService_true
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::stopBmwHmi
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::stopBmwHmi.mStopWestonService_true
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.STUB:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getCurrentState
TEST.STUB:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getObjectPath
TEST.VALUE:uut_prototype_stubs.sd_bus_open_system.return:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getCurrentState.state[0]:<<malloc 7>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getCurrentState.state[0]:"failed"
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getCurrentState.return:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getObjectPath.objPath[0]:<<malloc 13>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getObjectPath.objPath[0]:"/mic.service"
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getObjectPath.return:0
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::RWRead_DIDHandler.didId:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::IOCtrl_DIDHandler.didId:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::RoutineCtrl_DIDHandler.didId:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::readTouchCoordinates.loutdata.loutdata[0]:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::gnssReadData.loutdata.loutdata[0]:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::gnssReadGPIO.loutdata.loutdata[0]:INPUT_BASE=16
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::stopBmwHmi.nullObjPath
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::stopBmwHmi
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::stopBmwHmi.nullObjPath
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.STUB:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getCurrentState
TEST.STUB:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getObjectPath
TEST.VALUE:uut_prototype_stubs.sd_bus_open_system.return:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getCurrentState.state[0]:<<malloc 7>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getCurrentState.state[0]:"active"
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getCurrentState.return:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getObjectPath.objPath:<<null>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getObjectPath.return:0
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::RWRead_DIDHandler.didId:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::IOCtrl_DIDHandler.didId:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::RoutineCtrl_DIDHandler.didId:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::readTouchCoordinates.loutdata.loutdata[0]:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::gnssReadData.loutdata.loutdata[0]:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::gnssReadGPIO.loutdata.loutdata[0]:INPUT_BASE=16
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::stopBmwHmi.nullState
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::stopBmwHmi
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::stopBmwHmi.nullState
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.STUB:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getCurrentState
TEST.STUB:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getObjectPath
TEST.VALUE:uut_prototype_stubs.sd_bus_open_system.return:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.services:<<malloc 1>>
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.services[0]:<<function 1>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getCurrentState.state:<<null>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getCurrentState.return:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getObjectPath.objPath[0]:<<malloc 13>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getObjectPath.objPath[0]:"/mic.service"
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getObjectPath.return:0
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::RWRead_DIDHandler.didId:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::IOCtrl_DIDHandler.didId:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::RoutineCtrl_DIDHandler.didId:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::readTouchCoordinates.loutdata.loutdata[0]:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::gnssReadData.loutdata.loutdata[0]:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::gnssReadGPIO.loutdata.loutdata[0]:INPUT_BASE=16
TEST.VALUE_USER_CODE:<<dk::lib::meet::MeetAppHandler instance>>.dk::lib::meet::MeetAppHandler.services.services[0]
<<dk::lib::meet::MeetAppHandler instance>>->services[0] = "hmi.service";
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::stopBmwHmi.sd_bus_open_system_fail
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::stopBmwHmi
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::stopBmwHmi.sd_bus_open_system_fail
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.sd_bus_open_system.return:-1
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::stopBmwHmi.state_inactive
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::stopBmwHmi
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::stopBmwHmi.state_inactive
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.STUB:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getCurrentState
TEST.STUB:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getObjectPath
TEST.VALUE:uut_prototype_stubs.sd_bus_open_system.return:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getCurrentState.state[0]:<<malloc 9>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getCurrentState.state[0]:"inactive"
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getCurrentState.return:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getObjectPath.objPath[0]:<<malloc 13>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getObjectPath.objPath[0]:"/mic.service"
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getObjectPath.return:0
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::RWRead_DIDHandler.didId:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::IOCtrl_DIDHandler.didId:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::RoutineCtrl_DIDHandler.didId:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::readTouchCoordinates.loutdata.loutdata[0]:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::gnssReadData.loutdata.loutdata[0]:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::gnssReadGPIO.loutdata.loutdata[0]:INPUT_BASE=16
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::stopBmwHmi.stopService_true
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::stopBmwHmi
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::stopBmwHmi.stopService_true
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.STUB:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getCurrentState
TEST.STUB:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getObjectPath
TEST.VALUE:uut_prototype_stubs.sd_bus_open_system.return:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getCurrentState.state[0]:<<malloc 7>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getCurrentState.state[0]:"active"
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getCurrentState.return:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getObjectPath.objPath[0]:<<malloc 13>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getObjectPath.objPath[0]:"/mic.service"
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getObjectPath.return:0
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::RWRead_DIDHandler.didId:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::IOCtrl_DIDHandler.didId:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::RoutineCtrl_DIDHandler.didId:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::readTouchCoordinates.loutdata.loutdata[0]:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::gnssReadData.loutdata.loutdata[0]:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::gnssReadGPIO.loutdata.loutdata[0]:INPUT_BASE=16
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::stopBmwHmi.stoppedMicService
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::stopBmwHmi
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::stopBmwHmi.stoppedMicService
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.sd_bus_open_system.return:-1
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.mStopMicService:true
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.mStopWestonService:false
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::stopBmwHmi.unknownState
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::stopBmwHmi
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::stopBmwHmi.unknownState
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.STUB:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getCurrentState
TEST.STUB:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getObjectPath
TEST.VALUE:uut_prototype_stubs.sd_bus_open_system.return:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getCurrentState.state[0]:<<malloc 8>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getCurrentState.state[0]:"running"
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getCurrentState.return:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getObjectPath.objPath[0]:<<malloc 13>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getObjectPath.objPath[0]:"/mic.service"
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::getObjectPath.return:0
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::RWRead_DIDHandler.didId:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::IOCtrl_DIDHandler.didId:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::RoutineCtrl_DIDHandler.didId:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::readTouchCoordinates.loutdata.loutdata[0]:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::gnssReadData.loutdata.loutdata[0]:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::gnssReadGPIO.loutdata.loutdata[0]:INPUT_BASE=16
TEST.END

-- Subprogram: (cl)dk::lib::meet::MeetAppHandler::stopService

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::stopService.false
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::stopService
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::stopService.false
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.sd_bus_call_method.return:-1
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::stopService.return:-1
TEST.EXPECTED:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::stopService.return:-1
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::stopService.true
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::stopService
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::stopService.true
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.sd_bus_call_method.return:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::stopService.return:0
TEST.EXPECTED:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::stopService.return:0
TEST.END

-- Subprogram: (cl)dk::lib::meet::MeetAppHandler::tftFullColorControl

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::tftFullColorControl.controlMode_3
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::tftFullColorControl
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::tftFullColorControl.controlMode_3
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.STUB:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::display_full_colour_test
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::tftFullColorControl.controlMode:3
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::RWRead_DIDHandler.didId:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::IOCtrl_DIDHandler.didId:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::RoutineCtrl_DIDHandler.didId:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::readTouchCoordinates.loutdata.loutdata[0]:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::gnssReadData.loutdata.loutdata[0]:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::gnssReadGPIO.loutdata.loutdata[0]:INPUT_BASE=16
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::tftFullColorControl.display_full_colour_test_false
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::tftFullColorControl
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::tftFullColorControl.display_full_colour_test_false
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.STUB:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::display_full_colour_test
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::tftFullColorControl.controlMode:3
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::tftFullColorControl.data:<<malloc 3>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::tftFullColorControl.data[0]:<<function 1>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::tftFullColorControl.data[1]:<<function 1>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::tftFullColorControl.data[2]:<<function 1>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::tftFullColorControl.return:16#1#
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::display_full_colour_test.return:1
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::RWRead_DIDHandler.didId:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::IOCtrl_DIDHandler.didId:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::RoutineCtrl_DIDHandler.didId:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::readTouchCoordinates.loutdata.loutdata[0]:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::gnssReadData.loutdata.loutdata[0]:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::gnssReadGPIO.loutdata.loutdata[0]:INPUT_BASE=16
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::tftFullColorControl.display_full_colour_test_true
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::tftFullColorControl
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::tftFullColorControl.display_full_colour_test_true
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.STUB:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::display_full_colour_test
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::tftFullColorControl.controlMode:3
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::tftFullColorControl.data:<<malloc 3>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::tftFullColorControl.data[0]:<<function 1>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::tftFullColorControl.data[1]:<<function 1>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::tftFullColorControl.data[2]:<<function 1>>
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::RWRead_DIDHandler.didId:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::IOCtrl_DIDHandler.didId:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::RoutineCtrl_DIDHandler.didId:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::readTouchCoordinates.loutdata.loutdata[0]:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::gnssReadData.loutdata.loutdata[0]:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::gnssReadGPIO.loutdata.loutdata[0]:INPUT_BASE=16
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::tftFullColorControl.noData
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::tftFullColorControl
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::tftFullColorControl.noData
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::tftFullColorControl.unknown_controlMode
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::tftFullColorControl
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::tftFullColorControl.unknown_controlMode
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.STUB:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::display_full_colour_test
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::tftFullColorControl.controlMode:5
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::RWRead_DIDHandler.didId:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::IOCtrl_DIDHandler.didId:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::RoutineCtrl_DIDHandler.didId:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::readTouchCoordinates.loutdata.loutdata[0]:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::gnssReadData.loutdata.loutdata[0]:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::gnssReadGPIO.loutdata.loutdata[0]:INPUT_BASE=16
TEST.END

-- Subprogram: (cl)dk::lib::meet::MeetAppHandler::tftOpticTestPictures

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::tftOpticTestPictures.006
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::tftOpticTestPictures
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::tftOpticTestPictures.006
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::tftOpticTestPictures.controlMode:3
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::tftOpticTestPictures.data:<<malloc 1>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::tftOpticTestPictures.data[0]:1
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::tftOpticTestPictures.data[0]:<<function 1>>
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::tftOpticTestPictures.controlMode_0
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::tftOpticTestPictures
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::tftOpticTestPictures.controlMode_0
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.STUB:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::init_screen_window
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.screenInitStatus:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.screenWindowInit:false
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::init_screen_window.return:0
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::RWRead_DIDHandler.didId:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::IOCtrl_DIDHandler.didId:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::RoutineCtrl_DIDHandler.didId:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::readTouchCoordinates.loutdata.loutdata[0]:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::gnssReadData.loutdata.loutdata[0]:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::gnssReadGPIO.loutdata.loutdata[0]:INPUT_BASE=16
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::tftOpticTestPictures.controlMode_3
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::tftOpticTestPictures
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::tftOpticTestPictures.controlMode_3
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::tftOpticTestPictures.controlMode:3
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::tftOpticTestPictures.display_pattern_false
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::tftOpticTestPictures
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::tftOpticTestPictures.display_pattern_false
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::tftOpticTestPictures.controlMode:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::tftOpticTestPictures.data:<<malloc 1>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::tftOpticTestPictures.data[0]:16#23#
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::tftOpticTestPictures.data[0]:<<function 1>>
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::tftOpticTestPictures.display_pattern_true
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::tftOpticTestPictures
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::tftOpticTestPictures.display_pattern_true
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.STUB:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::display_pattern
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::tftOpticTestPictures.controlMode:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::tftOpticTestPictures.data:<<malloc 1>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::tftOpticTestPictures.data[0]:16#23#
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::tftOpticTestPictures.data[0]:<<function 1>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::display_pattern.return:0
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::RWRead_DIDHandler.didId:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::IOCtrl_DIDHandler.didId:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::RoutineCtrl_DIDHandler.didId:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::readTouchCoordinates.loutdata.loutdata[0]:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::gnssReadData.loutdata.loutdata[0]:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::gnssReadGPIO.loutdata.loutdata[0]:INPUT_BASE=16
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::tftOpticTestPictures.init_screen_window_fail
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::tftOpticTestPictures
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::tftOpticTestPictures.init_screen_window_fail
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::tftOpticTestPictures.no_data
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::tftOpticTestPictures
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::tftOpticTestPictures.no_data
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.screenWindowInit:true
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::tftOpticTestPictures.pattern_notFound
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::tftOpticTestPictures
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::tftOpticTestPictures.pattern_notFound
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::tftOpticTestPictures.controlMode:3
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::tftOpticTestPictures.data:<<malloc 1>>
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::tftOpticTestPictures.data[0]:1
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::tftOpticTestPictures.data[0]:<<function 1>>
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::tftOpticTestPictures.unknown_controlMode
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::tftOpticTestPictures
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::tftOpticTestPictures.unknown_controlMode
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::tftOpticTestPictures.controlMode:1
TEST.END

-- Subprogram: (cl)dk::lib::meet::MeetAppHandler::touchPeriodicFunction

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::touchPeriodicFunction.false
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::touchPeriodicFunction
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::touchPeriodicFunction.false
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.SwcDiagGP::TouchScreen::readData.return:E_OK
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.mMeetAppHandlerIsRunning:false
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetAppHandler::touchPeriodicFunction.true
TEST.UNIT:meet_application_handler
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetAppHandler::touchPeriodicFunction
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetAppHandler::touchPeriodicFunction.true
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.touchScreen.SwcDiagGP::TouchScreen.touchCoordinates:<<malloc 1>>
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.touchScreen.SwcDiagGP::TouchScreen.touchCoordinates[0]:<<function 1>>
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.mMeetAppHandlerIsRunning:true
TEST.END

-- Unit: meet_component

-- Subprogram: (cl)dk::lib::meet::MeetComponent::MeetPeriodicTask

-- Test Case: (cl)dk::lib::meet::MeetComponent::MeetPeriodicTask.pMeetHandlerObj_fail
TEST.UNIT:meet_component
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetComponent::MeetPeriodicTask
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetComponent::MeetPeriodicTask.pMeetHandlerObj_fail
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_component.<<GLOBAL>>.(cl).dk::lib::meet::MeetComponent.dk::lib::meet::MeetComponent.<<constructor>>.MeetComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetComponent::MeetPeriodicTask.pMeetHandlerObj_true
TEST.UNIT:meet_component
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetComponent::MeetPeriodicTask
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetComponent::MeetPeriodicTask.pMeetHandlerObj_true
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_component.<<GLOBAL>>.(cl).dk::lib::meet::MeetComponent.dk::lib::meet::MeetComponent.<<constructor>>.MeetComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE_USER_CODE:<<dk::lib::meet::MeetComponent instance>>.dk::lib::meet::MeetComponent.mpMeetHandlerObj
#include <memory>
#include "meet_application_handler.h"
#include "meet_component.h"
#include "ISystemCalls.hpp"  // Ensure that MySystemCallsImpl is defined here



// Create a concrete class that implements the abstract methods
class MySystemCallsImpl : public SwcDiagGP::ISystemCalls {
public:
    // Implement required virtual methods here
    int32_t openTouchDevice() override {
        // Implementation
        return 0;
    }

    void closeTouchDevice(int32_t fd) override {
        // Implementation
    }

    ssize_t readTouchDevice(const int32_t fd, input_event *buf, const size_t nbytes) override {
        // Implementation
        return 0;
    }

    SwcDiagGP::E_RESULT writeMagicFlag() override {
        // Implementation
        return static_cast<SwcDiagGP::E_RESULT>(0);  // Example
    }

    void sysReboot() override {
        // Implementation
    }
};

// Instantiate the necessary objects
std::map<dk::runtime::core::mid_t, dk::runtime::core::func_t> msgMap;
const char* componentId = "MEET_COMPONENT";

// Create the MeetComponent instance
dk::lib::meet::MeetComponent meetComponent(&msgMap, componentId);

// Create a shared pointer to MySystemCallsImpl (a concrete class)
std::shared_ptr<SwcDiagGP::ISystemCalls> systemCalls = std::make_shared<MySystemCallsImpl>();

// Create the MeetAppHandler object and pass the shared pointer
std::unique_ptr<dk::lib::meet::MeetAppHandler> pMeetHandlerObj =
    std::make_unique<dk::lib::meet::MeetAppHandler>(meetComponent, systemCalls);

<<dk::lib::meet::MeetComponent instance>>->mpMeetHandlerObj = std::move(pMeetHandlerObj);
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::lib::meet::MeetComponent::SendDiagReponse

-- Test Case: (cl)dk::lib::meet::MeetComponent::SendDiagReponse.EDiagMode_IOCtrl_fail
TEST.UNIT:meet_component
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetComponent::SendDiagReponse
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetComponent::SendDiagReponse.EDiagMode_IOCtrl_fail
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_component.<<GLOBAL>>.(cl).dk::lib::meet::MeetComponent.dk::lib::meet::MeetComponent.<<constructor>>.MeetComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.mode:EDiagMode_IOCtrl
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data:<<malloc 257>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[0]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[100]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[101]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[102]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[103]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[104]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[105]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[106]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[107]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[108]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[109]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[10]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[110]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[111]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[112]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[113]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[114]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[115]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[116]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[117]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[118]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[119]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[11]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[120]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[121]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[122]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[123]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[124]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[125]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[126]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[127]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[128]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[129]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[12]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[130]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[131]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[132]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[133]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[134]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[135]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[136]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[137]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[138]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[139]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[13]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[140]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[141]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[142]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[143]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[144]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[145]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[146]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[147]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[148]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[149]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[14]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[150]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[151]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[152]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[153]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[154]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[155]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[156]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[157]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[158]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[159]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[15]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[160]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[161]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[162]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[163]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[164]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[165]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[166]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[167]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[168]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[169]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[16]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[170]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[171]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[172]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[173]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[174]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[175]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[176]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[177]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[178]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[179]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[17]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[180]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[181]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[182]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[183]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[184]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[185]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[186]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[187]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[188]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[189]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[18]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[190]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[191]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[192]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[193]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[194]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[195]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[196]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[197]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[198]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[199]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[19]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[1]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[200]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[201]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[202]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[203]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[204]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[205]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[206]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[207]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[208]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[209]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[20]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[210]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[211]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[212]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[213]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[214]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[215]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[216]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[217]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[218]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[219]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[21]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[220]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[221]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[222]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[223]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[224]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[225]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[226]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[227]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[228]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[229]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[22]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[230]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[231]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[232]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[233]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[234]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[235]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[236]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[237]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[238]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[239]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[23]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[240]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[241]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[242]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[243]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[244]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[245]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[246]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[247]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[248]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[249]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[24]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[250]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[251]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[252]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[253]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[254]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[255]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[256]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[25]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[26]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[27]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[28]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[29]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[2]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[30]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[31]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[32]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[33]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[34]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[35]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[36]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[37]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[38]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[39]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[3]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[40]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[41]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[42]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[43]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[44]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[45]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[46]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[47]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[48]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[49]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[4]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[50]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[51]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[52]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[53]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[54]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[55]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[56]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[57]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[58]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[59]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[5]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[60]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[61]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[62]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[63]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[64]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[65]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[66]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[67]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[68]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[69]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[6]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[70]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[71]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[72]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[73]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[74]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[75]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[76]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[77]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[78]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[79]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[7]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[80]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[81]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[82]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[83]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[84]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[85]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[86]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[87]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[88]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[89]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[8]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[90]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[91]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[92]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[93]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[94]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[95]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[96]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[97]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[98]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[99]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[9]:<<function 1>>
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetComponent::SendDiagReponse.EDiagMode_IOCtrl_true
TEST.UNIT:meet_component
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetComponent::SendDiagReponse
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetComponent::SendDiagReponse.EDiagMode_IOCtrl_true
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_component.<<GLOBAL>>.(cl).dk::lib::meet::MeetComponent.dk::lib::meet::MeetComponent.<<constructor>>.MeetComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.mode:EDiagMode_IOCtrl
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetComponent::SendDiagReponse.EDiagMode_RC
TEST.UNIT:meet_component
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetComponent::SendDiagReponse
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetComponent::SendDiagReponse.EDiagMode_RC
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_component.<<GLOBAL>>.(cl).dk::lib::meet::MeetComponent.dk::lib::meet::MeetComponent.<<constructor>>.MeetComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.mode:EDiagMode_RC
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data:<<malloc 257>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[0]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[100]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[101]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[102]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[103]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[104]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[105]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[106]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[107]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[108]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[109]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[10]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[110]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[111]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[112]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[113]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[114]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[115]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[116]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[117]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[118]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[119]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[11]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[120]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[121]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[122]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[123]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[124]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[125]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[126]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[127]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[128]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[129]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[12]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[130]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[131]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[132]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[133]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[134]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[135]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[136]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[137]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[138]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[139]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[13]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[140]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[141]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[142]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[143]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[144]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[145]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[146]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[147]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[148]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[149]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[14]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[150]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[151]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[152]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[153]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[154]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[155]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[156]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[157]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[158]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[159]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[15]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[160]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[161]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[162]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[163]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[164]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[165]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[166]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[167]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[168]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[169]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[16]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[170]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[171]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[172]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[173]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[174]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[175]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[176]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[177]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[178]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[179]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[17]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[180]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[181]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[182]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[183]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[184]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[185]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[186]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[187]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[188]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[189]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[18]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[190]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[191]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[192]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[193]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[194]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[195]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[196]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[197]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[198]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[199]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[19]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[1]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[200]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[201]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[202]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[203]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[204]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[205]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[206]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[207]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[208]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[209]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[20]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[210]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[211]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[212]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[213]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[214]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[215]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[216]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[217]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[218]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[219]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[21]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[220]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[221]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[222]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[223]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[224]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[225]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[226]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[227]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[228]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[229]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[22]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[230]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[231]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[232]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[233]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[234]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[235]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[236]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[237]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[238]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[239]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[23]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[240]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[241]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[242]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[243]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[244]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[245]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[246]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[247]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[248]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[249]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[24]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[250]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[251]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[252]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[253]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[254]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[255]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[256]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[25]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[26]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[27]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[28]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[29]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[2]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[30]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[31]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[32]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[33]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[34]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[35]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[36]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[37]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[38]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[39]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[3]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[40]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[41]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[42]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[43]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[44]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[45]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[46]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[47]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[48]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[49]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[4]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[50]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[51]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[52]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[53]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[54]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[55]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[56]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[57]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[58]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[59]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[5]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[60]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[61]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[62]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[63]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[64]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[65]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[66]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[67]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[68]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[69]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[6]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[70]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[71]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[72]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[73]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[74]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[75]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[76]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[77]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[78]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[79]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[7]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[80]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[81]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[82]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[83]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[84]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[85]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[86]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[87]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[88]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[89]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[8]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[90]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[91]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[92]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[93]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[94]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[95]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[96]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[97]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[98]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[99]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[9]:<<function 1>>
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetComponent::SendDiagReponse.EDiagMode_RW_Read
TEST.UNIT:meet_component
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetComponent::SendDiagReponse
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetComponent::SendDiagReponse.EDiagMode_RW_Read
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_component.<<GLOBAL>>.(cl).dk::lib::meet::MeetComponent.dk::lib::meet::MeetComponent.<<constructor>>.MeetComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetComponent::SendDiagReponse.EDiagMode_RW_Write
TEST.UNIT:meet_component
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetComponent::SendDiagReponse
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetComponent::SendDiagReponse.EDiagMode_RW_Write
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_component.<<GLOBAL>>.(cl).dk::lib::meet::MeetComponent.dk::lib::meet::MeetComponent.<<constructor>>.MeetComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.mode:EDiagMode_RW_Write
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data:<<malloc 257>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[0]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[100]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[101]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[102]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[103]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[104]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[105]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[106]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[107]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[108]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[109]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[10]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[110]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[111]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[112]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[113]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[114]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[115]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[116]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[117]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[118]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[119]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[11]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[120]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[121]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[122]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[123]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[124]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[125]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[126]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[127]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[128]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[129]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[12]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[130]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[131]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[132]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[133]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[134]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[135]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[136]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[137]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[138]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[139]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[13]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[140]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[141]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[142]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[143]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[144]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[145]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[146]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[147]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[148]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[149]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[14]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[150]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[151]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[152]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[153]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[154]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[155]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[156]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[157]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[158]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[159]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[15]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[160]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[161]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[162]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[163]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[164]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[165]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[166]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[167]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[168]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[169]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[16]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[170]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[171]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[172]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[173]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[174]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[175]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[176]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[177]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[178]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[179]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[17]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[180]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[181]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[182]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[183]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[184]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[185]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[186]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[187]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[188]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[189]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[18]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[190]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[191]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[192]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[193]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[194]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[195]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[196]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[197]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[198]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[199]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[19]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[1]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[200]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[201]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[202]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[203]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[204]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[205]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[206]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[207]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[208]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[209]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[20]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[210]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[211]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[212]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[213]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[214]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[215]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[216]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[217]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[218]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[219]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[21]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[220]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[221]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[222]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[223]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[224]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[225]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[226]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[227]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[228]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[229]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[22]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[230]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[231]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[232]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[233]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[234]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[235]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[236]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[237]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[238]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[239]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[23]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[240]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[241]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[242]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[243]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[244]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[245]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[246]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[247]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[248]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[249]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[24]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[250]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[251]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[252]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[253]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[254]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[255]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[256]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[25]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[26]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[27]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[28]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[29]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[2]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[30]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[31]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[32]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[33]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[34]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[35]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[36]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[37]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[38]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[39]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[3]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[40]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[41]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[42]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[43]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[44]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[45]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[46]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[47]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[48]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[49]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[4]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[50]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[51]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[52]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[53]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[54]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[55]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[56]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[57]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[58]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[59]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[5]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[60]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[61]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[62]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[63]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[64]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[65]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[66]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[67]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[68]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[69]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[6]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[70]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[71]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[72]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[73]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[74]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[75]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[76]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[77]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[78]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[79]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[7]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[80]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[81]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[82]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[83]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[84]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[85]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[86]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[87]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[88]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[89]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[8]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[90]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[91]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[92]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[93]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[94]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[95]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[96]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[97]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[98]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[99]:<<function 1>>
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.data[9]:<<function 1>>
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetComponent::SendDiagReponse.default
TEST.UNIT:meet_component
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetComponent::SendDiagReponse
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetComponent::SendDiagReponse.default
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_component.<<GLOBAL>>.(cl).dk::lib::meet::MeetComponent.dk::lib::meet::MeetComponent.<<constructor>>.MeetComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.mode:7
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetComponent::SendDiagReponse.sendDiagResponse_RC
TEST.UNIT:meet_component
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetComponent::SendDiagReponse
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetComponent::SendDiagReponse.sendDiagResponse_RC
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_component.<<GLOBAL>>.(cl).dk::lib::meet::MeetComponent.dk::lib::meet::MeetComponent.<<constructor>>.MeetComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::SendDiagReponse.mode:EDiagMode_RC
TEST.END

-- Subprogram: (cl)dk::lib::meet::MeetComponent::SendGnssRequest

-- Test Case: (cl)dk::lib::meet::MeetComponent::SendGnssRequest.001
TEST.UNIT:meet_component
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetComponent::SendGnssRequest
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetComponent::SendGnssRequest.001
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_component.<<GLOBAL>>.(cl).dk::lib::meet::MeetComponent.dk::lib::meet::MeetComponent.<<constructor>>.MeetComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.END

-- Subprogram: (cl)dk::lib::meet::MeetComponent::diagParseRequest

-- Test Case: (cl)dk::lib::meet::MeetComponent::diagParseRequest.001
TEST.UNIT:meet_component
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetComponent::diagParseRequest
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetComponent::diagParseRequest.001
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_component.<<GLOBAL>>.(cl).dk::lib::meet::MeetComponent.dk::lib::meet::MeetComponent.<<constructor>>.MeetComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:meet_component.<<GLOBAL>>.(cl).dk::lib::meet::MeetComponent.dk::lib::meet::MeetComponent.mMeetAppIsRunning:false
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetComponent::diagParseRequest.mpMeetHandlerObj_true
TEST.UNIT:meet_component
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetComponent::diagParseRequest
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetComponent::diagParseRequest.mpMeetHandlerObj_true
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.dk::osal::Semaphore::timedWaitMS.return:true
TEST.VALUE:meet_component.<<GLOBAL>>.(cl).dk::lib::meet::MeetComponent.dk::lib::meet::MeetComponent.<<constructor>>.MeetComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:meet_component.<<GLOBAL>>.(cl).dk::lib::meet::MeetComponent.dk::lib::meet::MeetComponent.mpDiagReqSem.dk::osal::Semaphore.<<constructor>>.Semaphore(uint32_t).<<call>>:0
TEST.VALUE:meet_component.<<GLOBAL>>.(cl).dk::lib::meet::MeetComponent.dk::lib::meet::MeetComponent.mMeetAppIsRunning:true
TEST.VALUE:meet_component.<<GLOBAL>>.(cl).dk::lib::meet::MeetComponent.dk::lib::meet::MeetComponent.mDiagReqMsgData:<<malloc 1>>
TEST.VALUE:meet_component.<<GLOBAL>>.(cl).dk::lib::meet::MeetComponent.dk::lib::meet::MeetComponent.mDiagReqMsgData[0]:<<function 1>>
TEST.VALUE_USER_CODE:<<dk::lib::meet::MeetComponent instance>>.dk::lib::meet::MeetComponent.mpMeetHandlerObj
#include <memory>
#include "meet_application_handler.h"
#include "meet_component.h"
#include "ISystemCalls.hpp"  // Ensure that MySystemCallsImpl is defined here



// Create a concrete class that implements the abstract methods
class MySystemCallsImpl : public SwcDiagGP::ISystemCalls {
public:
    // Implement required virtual methods here
    int32_t openTouchDevice() override {
        // Implementation
        return 0;
    }

    void closeTouchDevice(int32_t fd) override {
        // Implementation
    }

    ssize_t readTouchDevice(const int32_t fd, input_event *buf, const size_t nbytes) override {
        // Implementation
        return 0;
    }

    SwcDiagGP::E_RESULT writeMagicFlag() override {
        // Implementation
        return static_cast<SwcDiagGP::E_RESULT>(0);  // Example
    }

    void sysReboot() override {
        // Implementation
    }
};

// Instantiate the necessary objects
std::map<dk::runtime::core::mid_t, dk::runtime::core::func_t> msgMap;
const char* componentId = "MEET_COMPONENT";

// Create the MeetComponent instance
dk::lib::meet::MeetComponent meetComponent(&msgMap, componentId);

// Create a shared pointer to MySystemCallsImpl (a concrete class)
std::shared_ptr<SwcDiagGP::ISystemCalls> systemCalls = std::make_shared<MySystemCallsImpl>();

// Create the MeetAppHandler object and pass the shared pointer
std::unique_ptr<dk::lib::meet::MeetAppHandler> pMeetHandlerObj =
    std::make_unique<dk::lib::meet::MeetAppHandler>(meetComponent, systemCalls); 
<<dk::lib::meet::MeetComponent instance>>->mpMeetHandlerObj = std::move(pMeetHandlerObj);
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetComponent::diagParseRequest.timedWaitMS_true
TEST.UNIT:meet_component
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetComponent::diagParseRequest
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetComponent::diagParseRequest.timedWaitMS_true
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.dk::osal::Semaphore::timedWaitMS.return:true
TEST.VALUE:meet_component.<<GLOBAL>>.(cl).dk::lib::meet::MeetComponent.dk::lib::meet::MeetComponent.<<constructor>>.MeetComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:meet_component.<<GLOBAL>>.(cl).dk::lib::meet::MeetComponent.dk::lib::meet::MeetComponent.mpDiagReqSem.dk::osal::Semaphore.<<constructor>>.Semaphore(uint32_t).<<call>>:0
TEST.VALUE:meet_component.<<GLOBAL>>.(cl).dk::lib::meet::MeetComponent.dk::lib::meet::MeetComponent.mMeetAppIsRunning:true
TEST.VALUE:meet_component.<<GLOBAL>>.(cl).dk::lib::meet::MeetComponent.dk::lib::meet::MeetComponent.mDiagReqMsgData:<<malloc 1>>
TEST.VALUE:meet_component.<<GLOBAL>>.(cl).dk::lib::meet::MeetComponent.dk::lib::meet::MeetComponent.mDiagReqMsgData[0]:<<function 1>>
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetComponent::diagParseRequest.true
TEST.UNIT:meet_component
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetComponent::diagParseRequest
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetComponent::diagParseRequest.true
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_component.<<GLOBAL>>.(cl).dk::lib::meet::MeetComponent.dk::lib::meet::MeetComponent.<<constructor>>.MeetComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:meet_component.<<GLOBAL>>.(cl).dk::lib::meet::MeetComponent.dk::lib::meet::MeetComponent.mMeetAppIsRunning:true
TEST.END

-- Subprogram: (cl)dk::lib::meet::MeetComponent::onExit

-- Test Case: (cl)dk::lib::meet::MeetComponent::onExit.001
TEST.UNIT:meet_component
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetComponent::onExit
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetComponent::onExit.001
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_component.<<GLOBAL>>.(cl).dk::lib::meet::MeetComponent.dk::lib::meet::MeetComponent.<<constructor>>.MeetComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::onExit.return:true
TEST.EXPECTED:meet_component.(cl)dk::lib::meet::MeetComponent::onExit.return:false
TEST.END

-- Subprogram: (cl)dk::lib::meet::MeetComponent::onInit

-- Test Case: (cl)dk::lib::meet::MeetComponent::onInit.false
TEST.UNIT:meet_component
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetComponent::onInit
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetComponent::onInit.false
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::Component::registerTask.return:1
TEST.VALUE:meet_component.<<GLOBAL>>.(cl).dk::lib::meet::MeetComponent.dk::lib::meet::MeetComponent.<<constructor>>.MeetComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::onInit.return:true
TEST.EXPECTED:meet_component.(cl)dk::lib::meet::MeetComponent::onInit.return:false
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetComponent::onInit.true
TEST.UNIT:meet_component
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetComponent::onInit
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetComponent::onInit.true
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::Component::registerTask.return:-1
TEST.VALUE:meet_component.<<GLOBAL>>.(cl).dk::lib::meet::MeetComponent.dk::lib::meet::MeetComponent.<<constructor>>.MeetComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.EXPECTED:meet_component.(cl)dk::lib::meet::MeetComponent::onInit.return:false
TEST.END

-- Subprogram: (cl)dk::lib::meet::MeetComponent::onReceiveDiagDIDRequest

-- Test Case: (cl)dk::lib::meet::MeetComponent::onReceiveDiagDIDRequest.004
TEST.UNIT:meet_component
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetComponent::onReceiveDiagDIDRequest
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetComponent::onReceiveDiagDIDRequest.004
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_component.<<GLOBAL>>.(cl).dk::lib::meet::MeetComponent.dk::lib::meet::MeetComponent.<<constructor>>.MeetComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::onReceiveDiagDIDRequest.msg.didType:1
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::onReceiveDiagDIDRequest.msg.dataLen:258
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetComponent::onReceiveDiagDIDRequest.EDiagMode_RW_Read
TEST.UNIT:meet_component
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetComponent::onReceiveDiagDIDRequest
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetComponent::onReceiveDiagDIDRequest.EDiagMode_RW_Read
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_component.<<GLOBAL>>.(cl).dk::lib::meet::MeetComponent.dk::lib::meet::MeetComponent.<<constructor>>.MeetComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetComponent::onReceiveDiagDIDRequest.EDiagMode_RW_Write;
TEST.UNIT:meet_component
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetComponent::onReceiveDiagDIDRequest
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetComponent::onReceiveDiagDIDRequest.EDiagMode_RW_Write;
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_component.<<GLOBAL>>.(cl).dk::lib::meet::MeetComponent.dk::lib::meet::MeetComponent.<<constructor>>.MeetComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::onReceiveDiagDIDRequest.msg.didType:1
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetComponent::onReceiveDiagDIDRequest.unsupported_didType
TEST.UNIT:meet_component
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetComponent::onReceiveDiagDIDRequest
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetComponent::onReceiveDiagDIDRequest.unsupported_didType
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_component.<<GLOBAL>>.(cl).dk::lib::meet::MeetComponent.dk::lib::meet::MeetComponent.<<constructor>>.MeetComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::onReceiveDiagDIDRequest.msg.didType:2
TEST.END

-- Subprogram: (cl)dk::lib::meet::MeetComponent::onReceiveDiagIOCtrlRequest

-- Test Case: (cl)dk::lib::meet::MeetComponent::onReceiveDiagIOCtrlRequest.false
TEST.UNIT:meet_component
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetComponent::onReceiveDiagIOCtrlRequest
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetComponent::onReceiveDiagIOCtrlRequest.false
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_component.<<GLOBAL>>.(cl).dk::lib::meet::MeetComponent.dk::lib::meet::MeetComponent.<<constructor>>.MeetComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::onReceiveDiagIOCtrlRequest.msg.dataLen:257
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetComponent::onReceiveDiagIOCtrlRequest.true
TEST.UNIT:meet_component
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetComponent::onReceiveDiagIOCtrlRequest
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetComponent::onReceiveDiagIOCtrlRequest.true
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_component.<<GLOBAL>>.(cl).dk::lib::meet::MeetComponent.dk::lib::meet::MeetComponent.<<constructor>>.MeetComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.END

-- Subprogram: (cl)dk::lib::meet::MeetComponent::onReceiveDiagRoutineRequest

-- Test Case: (cl)dk::lib::meet::MeetComponent::onReceiveDiagRoutineRequest.false
TEST.UNIT:meet_component
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetComponent::onReceiveDiagRoutineRequest
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetComponent::onReceiveDiagRoutineRequest.false
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_component.<<GLOBAL>>.(cl).dk::lib::meet::MeetComponent.dk::lib::meet::MeetComponent.<<constructor>>.MeetComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::onReceiveDiagRoutineRequest.msg.dataLen:257
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetComponent::onReceiveDiagRoutineRequest.true
TEST.UNIT:meet_component
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetComponent::onReceiveDiagRoutineRequest
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetComponent::onReceiveDiagRoutineRequest.true
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_component.<<GLOBAL>>.(cl).dk::lib::meet::MeetComponent.dk::lib::meet::MeetComponent.<<constructor>>.MeetComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.END

-- Subprogram: (cl)dk::lib::meet::MeetComponent::onReceiveMeetActiveDID

-- Test Case: (cl)dk::lib::meet::MeetComponent::onReceiveMeetActiveDID.001
TEST.UNIT:meet_component
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetComponent::onReceiveMeetActiveDID
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetComponent::onReceiveMeetActiveDID.001
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_component.<<GLOBAL>>.(cl).dk::lib::meet::MeetComponent.dk::lib::meet::MeetComponent.<<constructor>>.MeetComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.END

-- Subprogram: (cl)dk::lib::meet::MeetComponent::onReceiveMeetGNSSSResp

-- Test Case: (cl)dk::lib::meet::MeetComponent::onReceiveMeetGNSSSResp.EGNSSType_ReadData
TEST.UNIT:meet_component
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetComponent::onReceiveMeetGNSSSResp
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetComponent::onReceiveMeetGNSSSResp.EGNSSType_ReadData
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_component.<<GLOBAL>>.(cl).dk::lib::meet::MeetComponent.dk::lib::meet::MeetComponent.<<constructor>>.MeetComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetComponent::onReceiveMeetGNSSSResp.EGNSSType_ReadGNSSSWVersion
TEST.UNIT:meet_component
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetComponent::onReceiveMeetGNSSSResp
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetComponent::onReceiveMeetGNSSSResp.EGNSSType_ReadGNSSSWVersion
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_component.<<GLOBAL>>.(cl).dk::lib::meet::MeetComponent.dk::lib::meet::MeetComponent.<<constructor>>.MeetComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:meet_component.<<GLOBAL>>.(cl).dk::lib::meet::MeetComponent.dk::lib::meet::MeetComponent.mGnssResponseMsgData.responseType:EGNSSType_ReadGNSSSWVersion
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::onReceiveMeetGNSSSResp.msg.responseType:2
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetComponent::onReceiveMeetGNSSSResp.EGNSSType_ReadGPIO
TEST.UNIT:meet_component
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetComponent::onReceiveMeetGNSSSResp
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetComponent::onReceiveMeetGNSSSResp.EGNSSType_ReadGPIO
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_component.<<GLOBAL>>.(cl).dk::lib::meet::MeetComponent.dk::lib::meet::MeetComponent.<<constructor>>.MeetComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:meet_component.<<GLOBAL>>.(cl).dk::lib::meet::MeetComponent.dk::lib::meet::MeetComponent.mGnssResponseMsgData.responseType:EGNSSType_ReadGPIO
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::onReceiveMeetGNSSSResp.msg.responseType:1
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetComponent::onReceiveMeetGNSSSResp.gnssReadDataResponse_true
TEST.UNIT:meet_component
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetComponent::onReceiveMeetGNSSSResp
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetComponent::onReceiveMeetGNSSSResp.gnssReadDataResponse_true
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_component.<<GLOBAL>>.(cl).dk::lib::meet::MeetComponent.dk::lib::meet::MeetComponent.<<constructor>>.MeetComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:meet_component.<<GLOBAL>>.(cl).dk::lib::meet::MeetComponent.dk::lib::meet::MeetComponent.mGnssResponseMsgData.responseType:EGNSSType_ReadGNSSSWVersion
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::onReceiveMeetGNSSSResp.msg.responseType:0
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetComponent::onReceiveMeetGNSSSResp.incorrect_data
TEST.UNIT:meet_component
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetComponent::onReceiveMeetGNSSSResp
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetComponent::onReceiveMeetGNSSSResp.incorrect_data
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_component.<<GLOBAL>>.(cl).dk::lib::meet::MeetComponent.dk::lib::meet::MeetComponent.<<constructor>>.MeetComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:meet_component.<<GLOBAL>>.(cl).dk::lib::meet::MeetComponent.dk::lib::meet::MeetComponent.mGnssResponseMsgData.responseType:EGNSSType_ReadGPIO
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::onReceiveMeetGNSSSResp.msg.responseType:1
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::onReceiveMeetGNSSSResp.msg.length:257
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetComponent::onReceiveMeetGNSSSResp.incorrect_responseType
TEST.UNIT:meet_component
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetComponent::onReceiveMeetGNSSSResp
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetComponent::onReceiveMeetGNSSSResp.incorrect_responseType
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_component.<<GLOBAL>>.(cl).dk::lib::meet::MeetComponent.dk::lib::meet::MeetComponent.<<constructor>>.MeetComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:meet_component.<<GLOBAL>>.(cl).dk::lib::meet::MeetComponent.dk::lib::meet::MeetComponent.mGnssResponseMsgData.responseType:EGNSSType_ReadGNSSSWVersion
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::onReceiveMeetGNSSSResp.msg.responseType:3
TEST.END

-- Subprogram: (cl)dk::lib::meet::MeetComponent::onReceivePowerSystemState

-- Test Case: (cl)dk::lib::meet::MeetComponent::onReceivePowerSystemState.meetMode
TEST.UNIT:meet_component
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetComponent::onReceivePowerSystemState
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetComponent::onReceivePowerSystemState.meetMode
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.STUB:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::stopBmwHmi
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_component.<<GLOBAL>>.(cl).dk::lib::meet::MeetComponent.dk::lib::meet::MeetComponent.<<constructor>>.MeetComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:meet_component.(cl)dk::lib::meet::MeetComponent::onReceivePowerSystemState.msg.state:6
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::RWRead_DIDHandler.didId:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::IOCtrl_DIDHandler.didId:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::RoutineCtrl_DIDHandler.didId:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::readTouchCoordinates.loutdata.loutdata[0]:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::tftOpticTestPictures.data.data[0]:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::gnssReadData.loutdata.loutdata[0]:INPUT_BASE=16
TEST.ATTRIBUTES:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::gnssReadGPIO.loutdata.loutdata[0]:INPUT_BASE=16
TEST.END

-- Test Case: (cl)dk::lib::meet::MeetComponent::onReceivePowerSystemState.normalMode
TEST.UNIT:meet_component
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetComponent::onReceivePowerSystemState
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetComponent::onReceivePowerSystemState.normalMode
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_application_handler.<<GLOBAL>>.(cl).dk::lib::meet::MeetAppHandler.dk::lib::meet::MeetAppHandler.<<constructor>>.MeetAppHandler(dk::lib::meet::MeetComponent&,const std::shared_ptr<SwcDiagGP::ISystemCalls>&).<<call>>:0
TEST.VALUE:meet_component.<<GLOBAL>>.(cl).dk::lib::meet::MeetComponent.dk::lib::meet::MeetComponent.<<constructor>>.MeetComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.END

-- Subprogram: (cl)dk::lib::meet::MeetComponent::onStart

-- Test Case: (cl)dk::lib::meet::MeetComponent::onStart.001
TEST.UNIT:meet_component
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetComponent::onStart
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetComponent::onStart.001
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.STUB:meet_component.(cl)dk::lib::meet::MeetComponent::diagParseRequest
TEST.VALUE:meet_component.<<GLOBAL>>.(cl).dk::lib::meet::MeetComponent.dk::lib::meet::MeetComponent.<<constructor>>.MeetComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.EXPECTED:meet_component.(cl)dk::lib::meet::MeetComponent::onStart.return:false
TEST.END

-- Subprogram: (cl)dk::lib::meet::MeetComponent::onStop

-- Test Case: (cl)dk::lib::meet::MeetComponent::onStop.001
TEST.UNIT:meet_component
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetComponent::onStop
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetComponent::onStop.001
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.STUB:meet_application_handler.(cl)dk::lib::meet::MeetAppHandler::Stop
TEST.VALUE:meet_component.<<GLOBAL>>.(cl).dk::lib::meet::MeetComponent.dk::lib::meet::MeetComponent.<<constructor>>.MeetComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.EXPECTED:meet_component.(cl)dk::lib::meet::MeetComponent::onStop.return:false
TEST.END

-- Subprogram: (cl)dk::lib::meet::MeetComponent::worker

-- Test Case: (cl)dk::lib::meet::MeetComponent::worker.001
TEST.UNIT:meet_component
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetComponent::worker
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetComponent::worker.001
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.VALUE:meet_component.<<GLOBAL>>.(cl).dk::lib::meet::MeetComponent.dk::lib::meet::MeetComponent.<<constructor>>.MeetComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.END

-- Subprogram: (cl)dk::lib::meet::MeetComponent::~MeetComponent

-- Test Case: (cl)dk::lib::meet::MeetComponent::~MeetComponent.001
TEST.UNIT:meet_component
TEST.SUBPROGRAM:(cl)dk::lib::meet::MeetComponent::~MeetComponent
TEST.NEW
TEST.NAME:(cl)dk::lib::meet::MeetComponent::~MeetComponent.001
TEST.NOTES:
Meet_gp_app in GIP_INFRA::InfrastructureServices::Meet_gp_app
TEST.END_NOTES:
TEST.END
