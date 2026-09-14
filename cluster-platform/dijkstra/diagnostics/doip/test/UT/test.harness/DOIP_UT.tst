-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : DOIP_UT
-- Unit(s) Under Test: doip_component infra_comm_doip_handler infra_comm_doip_ringbuffer infra_comm_doip_soad infra_comm_doip_timer
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

-- Unit: doip_component

-- Subprogram: (cl)DoipComponent::PeriodicTask_1sec

-- Test Case: (cl)DoipComponent::PeriodicTask_1sec.001
TEST.UNIT:doip_component
TEST.SUBPROGRAM:(cl)DoipComponent::PeriodicTask_1sec
TEST.NEW
TEST.NAME:(cl)DoipComponent::PeriodicTask_1sec.001
TEST.VALUE:doip_component.<<GLOBAL>>.(cl).DoipComponent.DoipComponent.<<constructor>>.DoipComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*,const char*).<<call>>:0
TEST.END

-- Subprogram: (cl)DoipComponent::doipIniHandler

-- Test Case: (cl)DoipComponent::doipIniHandler.001
TEST.UNIT:doip_component
TEST.SUBPROGRAM:(cl)DoipComponent::doipIniHandler
TEST.NEW
TEST.NAME:(cl)DoipComponent::doipIniHandler.001
TEST.VALUE:doip_component.<<GLOBAL>>.(cl).DoipComponent.DoipComponent.<<constructor>>.DoipComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*,const char*).<<call>>:0
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::loadConfiguration.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllSections.sectionList[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllSections.sectionList[1]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllSections.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllKeysFromSection.section:"NetworkInfo"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllKeysFromSection.keyList[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllKeysFromSection.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.section:"DoIPNodeConfiguration"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.key:"DoIPNumberOfSourceAddress"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.defValue:1
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.return:1,13400
TEST.END

-- Test Case: (cl)DoipComponent::doipIniHandler.002
TEST.UNIT:doip_component
TEST.SUBPROGRAM:(cl)DoipComponent::doipIniHandler
TEST.NEW
TEST.NAME:(cl)DoipComponent::doipIniHandler.002
TEST.VALUE:doip_component.<<GLOBAL>>.(cl).DoipComponent.DoipComponent.<<constructor>>.DoipComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*,const char*).<<call>>:0
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::loadConfiguration.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllSections.sectionList[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllSections.sectionList[1]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllSections.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllKeysFromSection.section:"NetworkInfo"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllKeysFromSection.keyList[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllKeysFromSection.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.section:"DoIPNodeConfiguration"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.key:"DoIPNumberOfSourceAddress"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.defValue:1
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.return:1,1340
TEST.END

-- Test Case: LOading_doipIniPath2_file
TEST.UNIT:doip_component
TEST.SUBPROGRAM:(cl)DoipComponent::doipIniHandler
TEST.NEW
TEST.NAME:LOading_doipIniPath2_file
TEST.VALUE:doip_component.<<GLOBAL>>.(cl).DoipComponent.DoipComponent.<<constructor>>.DoipComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*,const char*).<<call>>:0
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::loadConfiguration.return:false,true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllSections.sectionList[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllSections.sectionList[1]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllSections.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllKeysFromSection.section:"NetworkInfo"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllKeysFromSection.keyList[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllKeysFromSection.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.section:"DoIPNodeConfiguration"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.key:"DoIPNumberOfSourceAddress"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.defValue:1
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.return:1,13400
TEST.END

-- Test Case: getAllKeysSection_false_case_for_networkinfo
TEST.UNIT:doip_component
TEST.SUBPROGRAM:(cl)DoipComponent::doipIniHandler
TEST.NEW
TEST.NAME:getAllKeysSection_false_case_for_networkinfo
TEST.VALUE:doip_component.<<GLOBAL>>.(cl).DoipComponent.DoipComponent.<<constructor>>.DoipComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*,const char*).<<call>>:0
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::loadConfiguration.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllSections.sectionList[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllSections.sectionList[1]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllSections.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllKeysFromSection.section:"NetworkInfo"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllKeysFromSection.return:false
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.section:"DoIPNodeConfiguration"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.key:"DoIPNumberOfSourceAddress"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.defValue:1
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.return:1,13400
TEST.END

-- Test Case: getAllSections_false_case
TEST.UNIT:doip_component
TEST.SUBPROGRAM:(cl)DoipComponent::doipIniHandler
TEST.NEW
TEST.NAME:getAllSections_false_case
TEST.VALUE:doip_component.<<GLOBAL>>.(cl).DoipComponent.DoipComponent.<<constructor>>.DoipComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*,const char*).<<call>>:0
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::loadConfiguration.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllSections.return:false
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllKeysFromSection.section:"NetworkInfo"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllKeysFromSection.keyList[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllKeysFromSection.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.section:"DoIPNodeConfiguration"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.key:"DoIPNumberOfSourceAddress"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.defValue:1
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.return:1,13400
TEST.END

-- Test Case: passing_networkinfo_section_details
TEST.UNIT:doip_component
TEST.SUBPROGRAM:(cl)DoipComponent::doipIniHandler
TEST.NEW
TEST.NAME:passing_networkinfo_section_details
TEST.VALUE:doip_component.<<GLOBAL>>.(cl).DoipComponent.DoipComponent.<<constructor>>.DoipComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*,const char*).<<call>>:0
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::loadConfiguration.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllSections.sectionList[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllSections.sectionList[1]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllSections.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllKeysFromSection.section:"NetworkInfo"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllKeysFromSection.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.section:"DoIPNodeConfiguration"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.key:"DoIPNumberOfSourceAddress"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.defValue:1
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.return:1,13400
TEST.END

-- Test Case: passing_no_values_to_getAllSections
TEST.UNIT:doip_component
TEST.SUBPROGRAM:(cl)DoipComponent::doipIniHandler
TEST.NEW
TEST.NAME:passing_no_values_to_getAllSections
TEST.VALUE:doip_component.<<GLOBAL>>.(cl).DoipComponent.DoipComponent.<<constructor>>.DoipComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*,const char*).<<call>>:0
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::loadConfiguration.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllSections.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllKeysFromSection.section:"NetworkInfo"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllKeysFromSection.keyList[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllKeysFromSection.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.section:"DoIPNodeConfiguration"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.key:"DoIPNumberOfSourceAddress"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.defValue:1
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.return:1,13400
TEST.END

-- Test Case: passing_vehicle_info_to_getAllKeysFromSection
TEST.UNIT:doip_component
TEST.SUBPROGRAM:(cl)DoipComponent::doipIniHandler
TEST.NEW
TEST.NAME:passing_vehicle_info_to_getAllKeysFromSection
TEST.VALUE:doip_component.<<GLOBAL>>.(cl).DoipComponent.DoipComponent.<<constructor>>.DoipComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*,const char*).<<call>>:0
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::loadConfiguration.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllSections.sectionList[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllSections.sectionList[1]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllSections.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllKeysFromSection.section:"VehicleInfo"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllKeysFromSection.keyList[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllKeysFromSection.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.section:"VehicleInfo"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.key:"Vin"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.valueList[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.section:"DoIPNodeConfiguration"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.key:"DoIPNumberOfSourceAddress"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.defValue:1
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.return:1,13400
TEST.END

-- Subprogram: (cl)DoipComponent::doipTimerTask

-- Test Case: (cl)DoipComponent::doipTimerTask.001
TEST.UNIT:doip_component
TEST.SUBPROGRAM:(cl)DoipComponent::doipTimerTask
TEST.NEW
TEST.NAME:(cl)DoipComponent::doipTimerTask.001
TEST.VALUE:doip_component.<<GLOBAL>>.(cl).DoipComponent.DoipComponent.<<constructor>>.DoipComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*,const char*).<<call>>:0
TEST.END

-- Subprogram: (cl)DoipComponent::onExit

-- Test Case: (cl)DoipComponent::onExit.001
TEST.UNIT:doip_component
TEST.SUBPROGRAM:(cl)DoipComponent::onExit
TEST.NEW
TEST.NAME:(cl)DoipComponent::onExit.001
TEST.VALUE:doip_component.<<GLOBAL>>.(cl).DoipComponent.DoipComponent.<<constructor>>.DoipComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*,const char*).<<call>>:0
TEST.VALUE:doip_component.(cl)DoipComponent::onExit.return:true
TEST.EXPECTED:doip_component.(cl)DoipComponent::onExit.return:true
TEST.END

-- Subprogram: (cl)DoipComponent::onInit

-- Test Case: (cl)DoipComponent::onInit.001
TEST.UNIT:doip_component
TEST.SUBPROGRAM:(cl)DoipComponent::onInit
TEST.NEW
TEST.NAME:(cl)DoipComponent::onInit.001
TEST.VALUE:doip_component.<<GLOBAL>>.(cl).DoipComponent.DoipComponent.<<constructor>>.DoipComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*,const char*).<<call>>:0
TEST.VALUE:doip_component.(cl)DoipComponent::onInit.return:true
TEST.EXPECTED:doip_component.(cl)DoipComponent::onInit.return:true
TEST.END

-- Subprogram: (cl)DoipComponent::onReceiveDoipDiagDataTransferRequest

-- Test Case: (cl)DoipComponent::onReceiveDoipDiagDataTransferRequest.001
TEST.UNIT:doip_component
TEST.SUBPROGRAM:(cl)DoipComponent::onReceiveDoipDiagDataTransferRequest
TEST.NEW
TEST.NAME:(cl)DoipComponent::onReceiveDoipDiagDataTransferRequest.001
TEST.VALUE:doip_component.<<GLOBAL>>.(cl).DoipComponent.DoipComponent.<<constructor>>.DoipComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*,const char*).<<call>>:0
TEST.END

-- Subprogram: (cl)DoipComponent::onReceiveDoipDiagPowerModeStatus

-- Test Case: (cl)DoipComponent::onReceiveDoipDiagPowerModeStatus.001
TEST.UNIT:doip_component
TEST.SUBPROGRAM:(cl)DoipComponent::onReceiveDoipDiagPowerModeStatus
TEST.NEW
TEST.NAME:(cl)DoipComponent::onReceiveDoipDiagPowerModeStatus.001
TEST.VALUE:doip_component.<<GLOBAL>>.(cl).DoipComponent.DoipComponent.<<constructor>>.DoipComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*,const char*).<<call>>:0
TEST.END

-- Subprogram: (cl)DoipComponent::onReceiveDoipSetParams

-- Test Case: (cl)DoipComponent::onReceiveDoipSetParams.001
TEST.UNIT:doip_component
TEST.SUBPROGRAM:(cl)DoipComponent::onReceiveDoipSetParams
TEST.NEW
TEST.NAME:(cl)DoipComponent::onReceiveDoipSetParams.001
TEST.VALUE:doip_component.<<GLOBAL>>.(cl).DoipComponent.DoipComponent.<<constructor>>.DoipComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*,const char*).<<call>>:0
TEST.END

-- Subprogram: (cl)DoipComponent::onStart

-- Test Case: (cl)DoipComponent::onStart.001
TEST.UNIT:doip_component
TEST.SUBPROGRAM:(cl)DoipComponent::onStart
TEST.NEW
TEST.NAME:(cl)DoipComponent::onStart.001
TEST.VALUE:doip_component.<<GLOBAL>>.(cl).DoipComponent.DoipComponent.<<constructor>>.DoipComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*,const char*).<<call>>:0
TEST.VALUE:doip_component.(cl)DoipComponent::onStart.return:true
TEST.EXPECTED:doip_component.(cl)DoipComponent::onStart.return:true
TEST.END

-- Subprogram: (cl)DoipComponent::onStop

-- Test Case: (cl)DoipComponent::onStop.001
TEST.UNIT:doip_component
TEST.SUBPROGRAM:(cl)DoipComponent::onStop
TEST.NEW
TEST.NAME:(cl)DoipComponent::onStop.001
TEST.VALUE:doip_component.<<GLOBAL>>.(cl).DoipComponent.DoipComponent.<<constructor>>.DoipComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*,const char*).<<call>>:0
TEST.VALUE:doip_component.(cl)DoipComponent::onStop.return:true
TEST.EXPECTED:doip_component.(cl)DoipComponent::onStop.return:true
TEST.END

-- Subprogram: (cl)DoipComponent::worker

-- Test Case: (cl)DoipComponent::worker.001
TEST.UNIT:doip_component
TEST.SUBPROGRAM:(cl)DoipComponent::worker
TEST.NEW
TEST.NAME:(cl)DoipComponent::worker.001
TEST.VALUE:doip_component.<<GLOBAL>>.(cl).DoipComponent.DoipComponent.<<constructor>>.DoipComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*,const char*).<<call>>:0
TEST.END

-- Unit: infra_comm_doip_handler

-- Subprogram: (cl)CDoIPHandler::AliveCheckTimeout

-- Test Case: (cl)CDoIPHandler::AliveCheckTimeout.001
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::AliveCheckTimeout
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::AliveCheckTimeout.001
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::AliveCheckTimeout.connectionIndex:1
TEST.END

-- Test Case: (cl)CDoIPHandler::AliveCheckTimeout.002
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::AliveCheckTimeout
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::AliveCheckTimeout.002
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::handleTimeout
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::AliveCheckTimeout.connectionIndex:1
TEST.END

-- Subprogram: (cl)CDoIPHandler::GeneralInactivityTimeout

-- Test Case: (cl)CDoIPHandler::GeneralInactivityTimeout.001
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::GeneralInactivityTimeout
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::GeneralInactivityTimeout.001
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::handleTimeout
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::GeneralInactivityTimeout.connectionIndex:1
TEST.END

-- Test Case: (cl)CDoIPHandler::GeneralInactivityTimeout.002
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::GeneralInactivityTimeout
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::GeneralInactivityTimeout.002
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::handleTimeout
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::GeneralInactivityTimeout.connectionIndex:1
TEST.END

-- Subprogram: (cl)CDoIPHandler::InitialInactivityTimeout

-- Test Case: (cl)CDoIPHandler::InitialInactivityTimeout.001
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::InitialInactivityTimeout
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::InitialInactivityTimeout.001
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::handleTimeout
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::InitialInactivityTimeout.connectionIndex:1
TEST.END

-- Test Case: (cl)CDoIPHandler::InitialInactivityTimeout.002
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::InitialInactivityTimeout
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::InitialInactivityTimeout.002
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::handleTimeout
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::InitialInactivityTimeout.connectionIndex:1
TEST.END

-- Subprogram: (cl)CDoIPHandler::aliveCheckResp

-- Test Case: (cl)CDoIPHandler::aliveCheckResp.001
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::aliveCheckResp
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::aliveCheckResp.001
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::doipSocketClose
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getSourceAddress
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::prepareRoutingActivationResponse
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getTimerId
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[0]:16#1#
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.pendingRoutingActivationSa:16#1#
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.pendingRoutingActivationSocket:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mVlanCount:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.return:2
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getSourceAddress.return:16#1#
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::aliveCheckResp.socketId:0
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getTimerId.return:1
TEST.END

-- Test Case: (cl)CDoIPHandler::aliveCheckResp.002
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::aliveCheckResp
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::aliveCheckResp.002
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::doipSocketClose
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getSourceAddress
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::prepareRoutingActivationResponse
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getTimerId
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[0]:16#1#
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.pendingRoutingActivationSa:16#1#
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.pendingRoutingActivationSocket:1,-1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mVlanCount:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.return:2
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getSourceAddress.return:16#1#
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::aliveCheckResp.socketId:0
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getTimerId.return:1
TEST.END

-- Test Case: (cl)CDoIPHandler::aliveCheckResp.awaitingAliveCheckResponse
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::aliveCheckResp
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::aliveCheckResp.awaitingAliveCheckResponse
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::doipSocketClose
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getSourceAddress
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::prepareRoutingActivationResponse
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getTimerId
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[0]:16#2#
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse[0]:true
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.pendingRoutingActivationSa:16#1#
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.pendingRoutingActivationSocket:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mVlanCount:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.return:2
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getSourceAddress.return:16#1#
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::aliveCheckResp.socketId:0
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getTimerId.return:1
TEST.END

-- Test Case: (cl)CDoIPHandler::aliveCheckResp.lpTimerId
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::aliveCheckResp
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::aliveCheckResp.lpTimerId
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::doipSocketClose
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getSourceAddress
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::prepareRoutingActivationResponse
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getTimerId
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[0]:16#1#
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.pendingRoutingActivationSa:16#1#
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.pendingRoutingActivationSocket:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mVlanCount:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.return:2
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getSourceAddress.return:16#1#
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::aliveCheckResp.socketId:0
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getTimerId.return:-1
TEST.END

-- Test Case: (cl)CDoIPHandler::aliveCheckResp.payloadLength
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::aliveCheckResp
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::aliveCheckResp.payloadLength
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::doipSocketClose
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getSourceAddress
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::prepareRoutingActivationResponse
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getTimerId
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[0]:16#1#
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.pendingRoutingActivationSa:16#1#
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.pendingRoutingActivationSocket:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mVlanCount:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.return:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getSourceAddress.return:16#1#
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::aliveCheckResp.socketId:0
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getTimerId.return:1
TEST.END

-- Test Case: (cl)CDoIPHandler::aliveCheckResp.pendingRoutingActivationSa
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::aliveCheckResp
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::aliveCheckResp.pendingRoutingActivationSa
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::doipSocketClose
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getSourceAddress
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::prepareRoutingActivationResponse
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getTimerId
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[0]:16#1#
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.pendingRoutingActivationSa:16#2#
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.pendingRoutingActivationSocket:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mVlanCount:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.return:2
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getSourceAddress.return:16#1#
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::aliveCheckResp.socketId:0
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getTimerId.return:1
TEST.END

-- Test Case: (cl)CDoIPHandler::aliveCheckResp.pendingRoutingActivationSocket
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::aliveCheckResp
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::aliveCheckResp.pendingRoutingActivationSocket
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::doipSocketClose
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getSourceAddress
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::prepareRoutingActivationResponse
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getTimerId
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[0]:16#1#
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.pendingRoutingActivationSa:16#2#
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.pendingRoutingActivationSocket:-1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mVlanCount:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.return:2
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getSourceAddress.return:16#1#
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::aliveCheckResp.socketId:0
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getTimerId.return:1
TEST.END

-- Subprogram: (cl)CDoIPHandler::assignSocket

-- Test Case: (cl)CDoIPHandler::assignSocket.001
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::assignSocket
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::assignSocket.001
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:SocketStateType_ConnectionRegistered
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[1]:SocketStateType_ConnectionEstablished
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mVlanCount:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::assignSocket.socketId:1
TEST.END

-- Test Case: (cl)CDoIPHandler::assignSocket.002
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::assignSocket
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::assignSocket.002
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::registerSocket
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:SocketStateType_ConnectionInvalid
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[1]:SocketStateType_ConnectionEstablished
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mVlanCount:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::assignSocket.socketId:1
TEST.END

-- Test Case: (cl)CDoIPHandler::assignSocket.003
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::assignSocket
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::assignSocket.003
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::registerSocket
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:SocketStateType_ConnectionInvalid
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[1]:SocketStateType_ConnectionInvalid
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mVlanCount:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::assignSocket.socketId:1
TEST.END

-- Test Case: (cl)CDoIPHandler::assignSocket.004
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::assignSocket
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::assignSocket.004
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[1]:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:SocketStateType_ConnectionRegistered
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[1]:SocketStateType_ConnectionRegistered
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mVlanCount:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::assignSocket.socketId:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::assignSocket.sourceAddress:1
TEST.END

-- Test Case: (cl)CDoIPHandler::assignSocket.005
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::assignSocket
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::assignSocket.005
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[1]:2
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:SocketStateType_ConnectionRegistered
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[1]:SocketStateType_ConnectionRegistered
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpAliveCheckRequired:true
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mVlanCount:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::assignSocket.socketId:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::assignSocket.sourceAddress:1
TEST.END

-- Test Case: (cl)CDoIPHandler::assignSocket.006
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::assignSocket
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::assignSocket.006
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::startSingleSaAliveCheck
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[0]:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[1]:2
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:SocketStateType_ConnectionRegistered
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[1]:SocketStateType_ConnectionInvalid
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpAliveCheckRequired:true
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mVlanCount:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::assignSocket.socketId:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::assignSocket.sourceAddress:1
TEST.END

-- Test Case: (cl)CDoIPHandler::assignSocket.007
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::assignSocket
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::assignSocket.007
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::startAllSaAliveCheck
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::startSingleSaAliveCheck
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[0]:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[1]:2
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:SocketStateType_ConnectionRegistered
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[1]:SocketStateType_ConnectionEstablished
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpAliveCheckRequired:true
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mVlanCount:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::assignSocket.socketId:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::assignSocket.sourceAddress:2
TEST.END

-- Test Case: (cl)CDoIPHandler::assignSocket.008
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::assignSocket
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::assignSocket.008
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::startAllSaAliveCheck
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::registerSocket
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::startSingleSaAliveCheck
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[0]:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[1]:2
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:SocketStateType_ConnectionRegistered
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[1]:SocketStateType_ConnectionEstablished
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfConcurrentSrcAddrSupported:2
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpAliveCheckRequired:true
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mVlanCount:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::assignSocket.socketId:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::assignSocket.sourceAddress:2
TEST.END

-- Test Case: (cl)CDoIPHandler::assignSocket.009
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::assignSocket
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::assignSocket.009
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::startAllSaAliveCheck
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::registerSocket
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::startSingleSaAliveCheck
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[0]:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[1]:2
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:SocketStateType_ConnectionRegistered
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[1]:SocketStateType_ConnectionInvalid
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfConcurrentSrcAddrSupported:2
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpAliveCheckRequired:true
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mVlanCount:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::assignSocket.socketId:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::assignSocket.sourceAddress:2
TEST.END

-- Subprogram: (cl)CDoIPHandler::authenticationRequired

-- Test Case: (cl)CDoIPHandler::authenticationRequired.001
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::authenticationRequired
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::authenticationRequired.001
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpActivationNumber:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpAuthenticationRequired:true
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::authenticationRequired.activationType:1
TEST.END

-- Test Case: (cl)CDoIPHandler::authenticationRequired.002
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::authenticationRequired
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::authenticationRequired.002
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpActivationNumber:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpAuthenticationRequired:false
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::authenticationRequired.activationType:1
TEST.END

-- Test Case: (cl)CDoIPHandler::authenticationRequired.003
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::authenticationRequired
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::authenticationRequired.003
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpActivationNumber:11
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpAuthenticationRequired:false
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::authenticationRequired.activationType:1
TEST.END

-- Subprogram: (cl)CDoIPHandler::confirmationRequired

-- Test Case: (cl)CDoIPHandler::confirmationRequired.001
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::confirmationRequired
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::confirmationRequired.001
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpActivationNumber:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpConfirmationRequired:true
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::confirmationRequired.activationType:1
TEST.END

-- Test Case: (cl)CDoIPHandler::confirmationRequired.002
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::confirmationRequired
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::confirmationRequired.002
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpActivationNumber:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpConfirmationRequired:false
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::confirmationRequired.activationType:1
TEST.END

-- Test Case: (cl)CDoIPHandler::confirmationRequired.003
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::confirmationRequired
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::confirmationRequired.003
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpActivationNumber:11
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpConfirmationRequired:false
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::confirmationRequired.activationType:1
TEST.END

-- Subprogram: (cl)CDoIPHandler::confirmed

-- Test Case: (cl)CDoIPHandler::confirmed.001
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::confirmed
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::confirmed.001
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.END

-- Subprogram: (cl)CDoIPHandler::createAndSendDiagnosticAck

-- Test Case: (cl)CDoIPHandler::createAndSendDiagnosticAck.001
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::createAndSendDiagnosticAck
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::createAndSendDiagnosticAck.001
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdTcp::sendIpMessage
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::createAndSendDiagnosticAck.sockNr:1
TEST.END

-- Test Case: (cl)CDoIPHandler::createAndSendDiagnosticAck.002
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::createAndSendDiagnosticAck
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::createAndSendDiagnosticAck.002
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdTcp::sendIpMessage
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::createAndSendDiagnosticAck.sockNr:1
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::sendIpMessage.return:13
TEST.END

-- Subprogram: (cl)CDoIPHandler::createAndSendDiagnosticNack

-- Test Case: (cl)CDoIPHandler::createAndSendDiagnosticNack.001
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::createAndSendDiagnosticNack
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::createAndSendDiagnosticNack.001
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdTcp::sendIpMessage
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::createAndSendDiagnosticNack.sockNr:1
TEST.END

-- Test Case: (cl)CDoIPHandler::createAndSendDiagnosticNack.002
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::createAndSendDiagnosticNack
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::createAndSendDiagnosticNack.002
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdTcp::sendIpMessage
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::createAndSendDiagnosticNack.sockNr:1
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::sendIpMessage.return:13
TEST.END

-- Subprogram: (cl)CDoIPHandler::createAndSendNack

-- Test Case: (cl)CDoIPHandler::createAndSendNack.001
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::createAndSendNack
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::createAndSendNack.001
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::doipSocketClose
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdTcp::sendIpMessage
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::createAndSendNack.isUdp:false
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::createAndSendNack.sockNr:1
TEST.END

-- Test Case: (cl)CDoIPHandler::createAndSendNack.002
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::createAndSendNack
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::createAndSendNack.002
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::doipSocketClose
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdTcp::sendIpMessage
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.doipHeaderLength:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::createAndSendNack.isUdp:false
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::createAndSendNack.sockNr:1
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::sendIpMessage.return:1
TEST.END

-- Test Case: (cl)CDoIPHandler::createAndSendNack.003
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::createAndSendNack
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::createAndSendNack.003
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::doipSocketClose
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdTcp::sendIpMessage
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::createAndSendNack.isUdp:false
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::createAndSendNack.sockNr:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::createAndSendNack.nackCode:1
TEST.END

-- Test Case: (cl)CDoIPHandler::createAndSendNack.004
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::createAndSendNack
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::createAndSendNack.004
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::doipSocketClose
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdTcp::sendIpMessage
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdUdp::sendMessage
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.tcp:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.tcp[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.udp:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.udp[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.udp[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mPortNum:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mPortNum[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mPortNum[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::createAndSendNack.isUdp:true
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::createAndSendNack.sockNr:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::createAndSendNack.nackCode:0
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::createAndSendNack.clientAddr:VECTORCAST_INT1
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdUdp::sendMessage.return:1
TEST.END

-- Test Case: (cl)CDoIPHandler::createAndSendNack.005
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::createAndSendNack
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::createAndSendNack.005
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::doipSocketClose
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdTcp::sendIpMessage
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdUdp::sendMessage
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.tcp:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.tcp[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.udp:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.udp[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.udp[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.doipHeaderLength:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mPortNum:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mPortNum[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mPortNum[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::createAndSendNack.isUdp:true
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::createAndSendNack.sockNr:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::createAndSendNack.nackCode:0
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::createAndSendNack.clientAddr:VECTORCAST_INT1
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdUdp::sendMessage.return:1
TEST.END

-- Test Case: (cl)CDoIPHandler::createAndSendNack.006
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::createAndSendNack
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::createAndSendNack.006
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::doipSocketClose
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdTcp::sendIpMessage
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdUdp::sendMessage
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.tcp:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.tcp[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.udp:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.udp[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.udp[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mPortNum:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mPortNum[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mPortNum[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::createAndSendNack.isUdp:true
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::createAndSendNack.sockNr:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::createAndSendNack.nackCode:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::createAndSendNack.clientAddr:VECTORCAST_INT1
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdUdp::sendMessage.return:1
TEST.END

-- Subprogram: (cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP

-- Test Case: (cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.EPayloadType_AliveCheckResponse
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.EPayloadType_AliveCheckResponse
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolVersion
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolInverVersion
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadType
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::aliveCheckResp
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState:<<malloc 3>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[2]:SocketStateType_ConnectionRegistered
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[2]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.return:2
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolVersion.return:2
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolInverVersion.return:253
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadType.return:8
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.isUdp:false
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.vlanNo:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.SocketId:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.rxBuffer:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.rxBuffer[0]:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.rxBuffer[0][0]:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.rxBuffer[0][0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.clientAddr:VECTORCAST_INT1
TEST.END

-- Test Case: (cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.EPayloadType_AliveCheckResponse.001
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.EPayloadType_AliveCheckResponse.001
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolVersion
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolInverVersion
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadType
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::aliveCheckResp
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::createAndSendNack
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState:<<malloc 3>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[2]:SocketStateType_ConnectionRegistered
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[2]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.return:3
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolVersion.return:2
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolInverVersion.return:253
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadType.return:8
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.isUdp:false
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.vlanNo:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.SocketId:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.rxBuffer:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.rxBuffer[0]:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.rxBuffer[0][0]:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.rxBuffer[0][0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.clientAddr:VECTORCAST_INT1
TEST.END

-- Test Case: (cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.EPayloadType_DiagPowerModeInfoRequest
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.EPayloadType_DiagPowerModeInfoRequest
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[2]:<<function 1>>
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticPowerModeResponse
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolVersion
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolInverVersion
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadType
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::createAndSendNack
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::vehicleIdentificationRequest
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState:<<malloc 3>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[2]:SocketStateType_ConnectionRegistered
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.return:0
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolVersion.return:2
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolInverVersion.return:253
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadType.return:16387
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.isUdp:false
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.vlanNo:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.SocketId:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.rxBuffer:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.rxBuffer[0]:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.rxBuffer[0][0]:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.rxBuffer[0][0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.clientAddr:VECTORCAST_INT1
TEST.END

-- Test Case: (cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.EPayloadType_DiagPowerModeInfoRequest.001
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.EPayloadType_DiagPowerModeInfoRequest.001
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[2]:<<function 1>>
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticPowerModeResponse
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolVersion
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolInverVersion
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadType
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::createAndSendNack
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::vehicleIdentificationRequest
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState:<<malloc 3>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[2]:SocketStateType_ConnectionRegistered
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.return:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolVersion.return:2
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolInverVersion.return:253
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadType.return:16387
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.isUdp:false
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.vlanNo:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.SocketId:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.rxBuffer:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.rxBuffer[0]:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.rxBuffer[0][0]:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.rxBuffer[0][0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.clientAddr:VECTORCAST_INT1
TEST.END

-- Test Case: (cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.EPayloadType_DiagnosticMessage
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.EPayloadType_DiagnosticMessage
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolVersion
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolInverVersion
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadType
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState:<<malloc 3>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[2]:SocketStateType_ConnectionRegistered
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[2]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.return:5
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolVersion.return:2
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolInverVersion.return:253
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadType.return:32769
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.isUdp:false
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.vlanNo:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.SocketId:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.rxBuffer:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.rxBuffer[0]:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.rxBuffer[0][0]:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.rxBuffer[0][0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.clientAddr:VECTORCAST_INT1
TEST.END

-- Test Case: (cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.EPayloadType_DiagnosticMessage.001
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.EPayloadType_DiagnosticMessage.001
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolVersion
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolInverVersion
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadType
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::createAndSendNack
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState:<<malloc 3>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[2]:SocketStateType_ConnectionRegistered
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[2]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.return:4
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolVersion.return:2
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolInverVersion.return:253
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadType.return:32769
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.isUdp:false
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.vlanNo:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.SocketId:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.rxBuffer:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.rxBuffer[0]:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.rxBuffer[0][0]:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.rxBuffer[0][0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.clientAddr:VECTORCAST_INT1
TEST.END

-- Test Case: (cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.EPayloadType_EntityStatusRequest
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.EPayloadType_EntityStatusRequest
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[2]:<<function 1>>
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticPowerModeResponse
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolVersion
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolInverVersion
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadType
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::createAndSendNack
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::vehicleIdentificationRequest
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::doipEntityStatusResponse
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState:<<malloc 3>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[2]:SocketStateType_ConnectionRegistered
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.return:0
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolVersion.return:2
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolInverVersion.return:253
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadType.return:16385
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.isUdp:false
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.vlanNo:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.SocketId:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.rxBuffer:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.rxBuffer[0]:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.rxBuffer[0][0]:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.rxBuffer[0][0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.clientAddr:VECTORCAST_INT1
TEST.END

-- Test Case: (cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.EPayloadType_EntityStatusRequest.001
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.EPayloadType_EntityStatusRequest.001
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[2]:<<function 1>>
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticPowerModeResponse
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolVersion
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolInverVersion
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadType
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::createAndSendNack
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::vehicleIdentificationRequest
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::doipEntityStatusResponse
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState:<<malloc 3>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[2]:SocketStateType_ConnectionRegistered
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.return:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolVersion.return:2
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolInverVersion.return:253
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadType.return:16385
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.isUdp:false
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.vlanNo:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.SocketId:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.rxBuffer:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.rxBuffer[0]:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.rxBuffer[0][0]:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.rxBuffer[0][0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.clientAddr:VECTORCAST_INT1
TEST.END

-- Test Case: (cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.EPayloadType_GenericHeaderNegativeAck
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.EPayloadType_GenericHeaderNegativeAck
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[2]:<<function 1>>
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticPowerModeResponse
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolVersion
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolInverVersion
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadType
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::createAndSendNack
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::vehicleIdentificationRequest
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::doipEntityStatusResponse
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState:<<malloc 3>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[2]:SocketStateType_ConnectionRegistered
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.return:0
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolVersion.return:2
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolInverVersion.return:253
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadType.return:0
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.isUdp:false
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.vlanNo:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.SocketId:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.rxBuffer:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.rxBuffer[0]:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.rxBuffer[0][0]:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.rxBuffer[0][0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.clientAddr:VECTORCAST_INT1
TEST.END

-- Test Case: (cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.EPayloadType_GenericHeaderNegativeAck.001
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.EPayloadType_GenericHeaderNegativeAck.001
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[2]:<<function 1>>
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticPowerModeResponse
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolVersion
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolInverVersion
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadType
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::createAndSendNack
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::vehicleIdentificationRequest
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::doipEntityStatusResponse
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState:<<malloc 3>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[2]:SocketStateType_ConnectionRegistered
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.return:0
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolVersion.return:2
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolInverVersion.return:253
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadType.return:0
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.isUdp:false
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.vlanNo:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.SocketId:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.rxBuffer:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.rxBuffer[0]:<<malloc 10>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.rxBuffer[0][0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.rxBuffer[0][1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.rxBuffer[0][2]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.rxBuffer[0][3]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.rxBuffer[0][4]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.rxBuffer[0][5]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.rxBuffer[0][6]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.rxBuffer[0][7]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.rxBuffer[0][8]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.rxBuffer[0][9]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.clientAddr:VECTORCAST_INT1
TEST.END

-- Test Case: (cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.EPayloadType_VehicleAnnouncementOrResponse
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.EPayloadType_VehicleAnnouncementOrResponse
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolVersion
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolInverVersion
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadType
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::createAndSendNack
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState:<<malloc 3>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[2]:SocketStateType_ConnectionRegistered
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[2]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.return:4
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolVersion.return:2
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolInverVersion.return:253
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadType.return:4
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.isUdp:false
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.vlanNo:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.SocketId:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.rxBuffer:<<malloc 1>>
TEST.END

-- Test Case: (cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.EPayloadType_VehicleIdRequestEid
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.EPayloadType_VehicleIdRequestEid
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[2]:<<function 1>>
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolVersion
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolInverVersion
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadType
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::createAndSendNack
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::vehicleIdentificationRequest
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState:<<malloc 3>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[2]:SocketStateType_ConnectionRegistered
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.return:0
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolVersion.return:2
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolInverVersion.return:253
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadType.return:2
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.isUdp:false
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.vlanNo:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.SocketId:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.rxBuffer:<<malloc 1>>
TEST.END

-- Test Case: (cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.EPayloadType_VehicleIdRequestMessage
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.EPayloadType_VehicleIdRequestMessage
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[2]:<<function 1>>
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolVersion
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolInverVersion
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadType
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::createAndSendNack
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::vehicleIdentificationRequest
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState:<<malloc 3>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[2]:SocketStateType_ConnectionRegistered
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.return:0
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolVersion.return:2
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolInverVersion.return:253
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadType.return:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.isUdp:false
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.vlanNo:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.SocketId:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.rxBuffer:<<malloc 1>>
TEST.END

-- Test Case: (cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.EPayloadType_VehicleIdRequestVin
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.EPayloadType_VehicleIdRequestVin
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[2]:<<function 1>>
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolVersion
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolInverVersion
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadType
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::createAndSendNack
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::vehicleIdentificationRequest
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState:<<malloc 3>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[2]:SocketStateType_ConnectionRegistered
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.return:0
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolVersion.return:2
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolInverVersion.return:253
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadType.return:3
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.isUdp:false
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.vlanNo:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.SocketId:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.rxBuffer:<<malloc 1>>
TEST.END

-- Test Case: (cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.EPayloadType_VehicleIdRequestVin.001
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.EPayloadType_VehicleIdRequestVin.001
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[2]:<<function 1>>
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolVersion
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolInverVersion
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadType
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::createAndSendNack
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::vehicleIdentificationRequest
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState:<<malloc 3>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[2]:SocketStateType_ConnectionRegistered
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.return:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolVersion.return:2
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolInverVersion.return:253
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadType.return:3
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.isUdp:false
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.vlanNo:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.SocketId:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.rxBuffer:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.rxBuffer[0]:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.rxBuffer[0][0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.clientAddr:VECTORCAST_INT1
TEST.END

-- Test Case: (cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.SocketStateType_ConnectionInvalid
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.SocketStateType_ConnectionInvalid
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolVersion
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolInverVersion
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadType
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::aliveCheckResp
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::createAndSendNack
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState:<<malloc 3>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[2]:SocketStateType_ConnectionInvalid
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[2]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.return:4294967295
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolVersion.return:2
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolInverVersion.return:253
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadType.return:7
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.isUdp:false
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.vlanNo:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.SocketId:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.rxBuffer:<<malloc 1>>
TEST.END

-- Test Case: (cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.SocketStateType_ConnectionRegistered
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.SocketStateType_ConnectionRegistered
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolVersion
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolInverVersion
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadType
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::routingActivationReq
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState:<<malloc 3>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[2]:SocketStateType_ConnectionRegistered
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[2]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.return:8
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolVersion.return:2
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolInverVersion.return:253
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadType.return:5
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.isUdp:false
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.vlanNo:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.SocketId:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.rxBuffer:<<malloc 1>>
TEST.END

-- Test Case: (cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.SocketStateType_ConnectionRegistered.001
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.SocketStateType_ConnectionRegistered.001
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolVersion
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolInverVersion
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadType
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::routingActivationReq
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::createAndSendNack
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState:<<malloc 3>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[2]:SocketStateType_ConnectionRegistered
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[2]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.return:6
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolVersion.return:2
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolInverVersion.return:253
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadType.return:5
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.isUdp:false
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.vlanNo:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.SocketId:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.rxBuffer:<<malloc 1>>
TEST.END

-- Test Case: (cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.default
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.default
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolVersion
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolInverVersion
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadType
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::aliveCheckResp
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::createAndSendNack
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState:<<malloc 3>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[2]:SocketStateType_ConnectionRegistered
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[2]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.return:2
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolVersion.return:2
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolInverVersion.return:253
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadType.return:7
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.isUdp:false
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.vlanNo:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.SocketId:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.rxBuffer:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.rxBuffer[0]:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.rxBuffer[0][0]:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.rxBuffer[0][0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.clientAddr:VECTORCAST_INT1
TEST.END

-- Test Case: (cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.getProtocolVersion_false_condition
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.getProtocolVersion_false_condition
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolVersion
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolInverVersion
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadType
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::aliveCheckResp
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::createAndSendNack
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState:<<malloc 3>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[2]:SocketStateType_ConnectionInvalid
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[2]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.return:4294967295
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolVersion.return:3
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolInverVersion.return:253
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadType.return:7
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.isUdp:false
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.vlanNo:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.SocketId:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.rxBuffer:<<malloc 1>>
TEST.END

-- Test Case: (cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.isUdp_false_condition
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.isUdp_false_condition
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolVersion
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolInverVersion
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadType
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::aliveCheckResp
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::createAndSendNack
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState:<<malloc 3>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[2]:SocketStateType_ConnectionInvalid
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[2]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.return:4294967295
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolVersion.return:3
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolInverVersion.return:253
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadType.return:7
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.isUdp:true
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.vlanNo:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.SocketId:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.rxBuffer:<<malloc 1>>
TEST.END

-- Test Case: (cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.payLoadLengthexceed_doipStackSize
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.payLoadLengthexceed_doipStackSize
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolVersion
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolInverVersion
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadType
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::aliveCheckResp
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::createAndSendNack
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState:<<malloc 3>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[2]:SocketStateType_ConnectionRegistered
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[2]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.return:65025
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolVersion.return:2
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolInverVersion.return:253
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadType.return:7
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.isUdp:false
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.vlanNo:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.SocketId:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.rxBuffer:<<malloc 1>>
TEST.END

-- Test Case: (cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.payLoadLengthexceed_maxPayLoadLength
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.payLoadLengthexceed_maxPayLoadLength
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolVersion
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolInverVersion
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadType
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::aliveCheckResp
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::createAndSendNack
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState:<<malloc 3>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[2]:SocketStateType_ConnectionRegistered
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[2]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.return:4294967295
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolVersion.return:2
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolInverVersion.return:253
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadType.return:7
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.isUdp:false
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.vlanNo:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.SocketId:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP.rxBuffer:<<malloc 1>>
TEST.END

-- Subprogram: (cl)CDoIPHandler::dataReceivedForSoAd

-- Test Case: (cl)CDoIPHandler::dataReceivedForSoAd.001
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::dataReceivedForSoAd
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::dataReceivedForSoAd.001
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.return:0
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForSoAd.rxBuffer:<<malloc 1>>
TEST.END

-- Test Case: (cl)CDoIPHandler::dataReceivedForSoAd.002
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::dataReceivedForSoAd
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::dataReceivedForSoAd.002
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::createAndSendNack
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.return:65025
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForSoAd.rxBuffer:<<malloc 1>>
TEST.END

-- Test Case: (cl)CDoIPHandler::dataReceivedForSoAd.003
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::dataReceivedForSoAd
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::dataReceivedForSoAd.003
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::doipSocketClose
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::createAndSendNack
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.return:4294967295
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForSoAd.rxBuffer:<<malloc 1>>
TEST.END

-- Subprogram: (cl)CDoIPHandler::dataTrasferRequest

-- Test Case: (cl)CDoIPHandler::dataTrasferRequest.001
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::dataTrasferRequest
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::dataTrasferRequest.001
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdiagOverIPProtocol:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mVlanCount:1
TEST.END

-- Test Case: (cl)CDoIPHandler::dataTrasferRequest.002
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::dataTrasferRequest
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::dataTrasferRequest.002
TEST.STUB:doip_component.(cl)DoipComponent::onReceiveDoipDiagDataTransferRequest
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getTimerId
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdTcp::sendIpMessage
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.tcp:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.tcp[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[0]:16#1#
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[1]:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState:<<malloc 12>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:SocketStateType_ConnectionRegistered
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[10]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[11]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[2]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[3]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[4]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[5]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[6]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[7]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[8]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[9]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdiagOverIPProtocol:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mVlanCount:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mVin:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mVin[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mEid:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mEid[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mGid:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mGid[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataTrasferRequest.targetAddress:16#1#
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataTrasferRequest.pMessageData:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getTimerId.return:1
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::sendIpMessage.return:20
TEST.END

-- Test Case: (cl)CDoIPHandler::dataTrasferRequest.003
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::dataTrasferRequest
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::dataTrasferRequest.003
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdTcp::sendIpMessage
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.tcp:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.tcp[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[0]:16#2#
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[1]:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState:<<malloc 12>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:SocketStateType_ConnectionEstablished
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[10]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[11]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[2]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[3]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[4]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[5]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[6]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[7]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[8]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[9]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdiagOverIPProtocol:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mVlanCount:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataTrasferRequest.targetAddress:16#1#
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::sendIpMessage.return:20
TEST.END

-- Test Case: (cl)CDoIPHandler::dataTrasferRequest.004
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::dataTrasferRequest
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::dataTrasferRequest.004
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdTcp::sendIpMessage
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.tcp:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.tcp[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[0]:16#1#
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[1]:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState:<<malloc 12>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:SocketStateType_ConnectionEstablished
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[10]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[11]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[2]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[3]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[4]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[5]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[6]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[7]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[8]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[9]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdiagOverIPProtocol:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mVlanCount:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataTrasferRequest.targetAddress:16#1#
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::sendIpMessage.return:12
TEST.END

-- Test Case: (cl)CDoIPHandler::dataTrasferRequest.005
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::dataTrasferRequest
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::dataTrasferRequest.005
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdTcp::sendIpMessage
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.tcp:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.tcp[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[0]:16#1#
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[1]:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState:<<malloc 12>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:SocketStateType_ConnectionRegistered
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[10]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[11]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[2]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[3]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[4]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[5]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[6]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[7]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[8]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[9]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdiagOverIPProtocol:2
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mVlanCount:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::dataTrasferRequest.targetAddress:16#1#
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::sendIpMessage.return:20
TEST.END

-- Subprogram: (cl)CDoIPHandler::diagnosticMessage

-- Test Case: (cl)CDoIPHandler::diagnosticMessage.001
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::diagnosticMessage
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::diagnosticMessage.001
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:<<function 1>>
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getSourceAddress
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getTargetAddress
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::createAndSendDiagnosticNack
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::createAndSendDiagnosticAck
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::targetAddressSupported
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpRoutingActivationRequired:true
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.return:4
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::targetAddressSupported.return:false
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage.socketId:0
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage.rxBuffer:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage.rxBuffer[0]:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage.rxBuffer[0][0]:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage.rxBuffer[0][0]:<<function 1>>
TEST.ATTRIBUTES:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa.sa[0]:INPUT_BASE=16
TEST.END

-- Test Case: (cl)CDoIPHandler::diagnosticMessage.002
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::diagnosticMessage
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::diagnosticMessage.002
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:<<function 1>>
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getSourceAddress
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getTargetAddress
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::createAndSendDiagnosticNack
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::createAndSendDiagnosticAck
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage.rxBuffer[0][0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage.rxBuffer[0][1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage.rxBuffer[0][2]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage.rxBuffer[0][3]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage.rxBuffer[0][4]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage.rxBuffer[0][5]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage.rxBuffer[0][6]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage.rxBuffer[0][7]:<<function 1>>
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::messageIndication
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::findTargetType
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[0]:16#2#
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:SocketStateType_ConnectionRegistered
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpRoutingActivationRequired:true
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdiagOverIPProtocol:2
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.return:4
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getSourceAddress.return:16#2#
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage.socketId:0
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage.rxBuffer:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage.rxBuffer[0]:<<malloc 8>>
TEST.END

-- Test Case: (cl)CDoIPHandler::diagnosticMessage.003
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::diagnosticMessage
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::diagnosticMessage.003
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:<<function 1>>
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getSourceAddress
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getTargetAddress
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::sourceAddressKnown
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::registerSocket
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::createAndSendDiagnosticNack
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::createAndSendDiagnosticAck
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::messageIndication
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::findTargetType
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[0]:16#2#
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:SocketStateType_ConnectionInvalid
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpRoutingActivationRequired:false
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdiagOverIPProtocol:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.return:4
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getSourceAddress.return:16#2#
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::sourceAddressKnown.return:true
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage.socketId:0
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage.rxBuffer:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage.rxBuffer[0]:<<malloc 12>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage.rxBuffer[0][0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage.rxBuffer[0][10]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage.rxBuffer[0][11]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage.rxBuffer[0][1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage.rxBuffer[0][2]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage.rxBuffer[0][3]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage.rxBuffer[0][4]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage.rxBuffer[0][5]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage.rxBuffer[0][6]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage.rxBuffer[0][7]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage.rxBuffer[0][8]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage.rxBuffer[0][9]:<<function 1>>
TEST.END

-- Test Case: (cl)CDoIPHandler::diagnosticMessage.004
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::diagnosticMessage
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::diagnosticMessage.004
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:<<function 1>>
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getSourceAddress
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getTargetAddress
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::createAndSendDiagnosticNack
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::createAndSendDiagnosticAck
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::targetAddressSupported
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::messageIndication
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::findTargetType
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[0]:16#2#
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:SocketStateType_ConnectionRegistered
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpRoutingActivationRequired:true
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdiagOverIPProtocol:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.return:4
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getSourceAddress.return:16#2#
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::targetAddressSupported.return:false
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage.socketId:0
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage.rxBuffer:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage.rxBuffer[0]:<<malloc 8>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage.rxBuffer[0][0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage.rxBuffer[0][1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage.rxBuffer[0][2]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage.rxBuffer[0][3]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage.rxBuffer[0][4]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage.rxBuffer[0][5]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage.rxBuffer[0][6]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage.rxBuffer[0][7]:<<function 1>>
TEST.END

-- Test Case: (cl)CDoIPHandler::diagnosticMessage.005
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::diagnosticMessage
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::diagnosticMessage.005
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:<<function 1>>
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getSourceAddress
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getTargetAddress
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::createAndSendDiagnosticNack
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::createAndSendDiagnosticAck
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::targetAddressSupported
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::messageIndication
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::findTargetType
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[0]:16#2#
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:SocketStateType_ConnectionRegistered
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpRoutingActivationRequired:true
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdiagOverIPProtocol:2
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.return:4
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getSourceAddress.return:16#2#
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::targetAddressSupported.return:false
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage.socketId:0
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage.rxBuffer:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage.rxBuffer[0]:<<malloc 8>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage.rxBuffer[0][0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage.rxBuffer[0][1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage.rxBuffer[0][2]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage.rxBuffer[0][3]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage.rxBuffer[0][4]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage.rxBuffer[0][5]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage.rxBuffer[0][6]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage.rxBuffer[0][7]:<<function 1>>
TEST.END

-- Test Case: (cl)CDoIPHandler::diagnosticMessage.006
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::diagnosticMessage
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::diagnosticMessage.006
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:<<function 1>>
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::doipSocketClose
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getSourceAddress
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getTargetAddress
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::createAndSendDiagnosticNack
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::createAndSendDiagnosticAck
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::createAndSendNack
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::messageIndication
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::findTargetType
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[0]:16#2#
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:SocketStateType_ConnectionInvalid
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpRoutingActivationRequired:true
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpAuthenticationRequired:false
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdiagOverIPProtocol:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.return:2
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getSourceAddress.return:16#2#
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage.socketId:0
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage.rxBuffer:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage.rxBuffer[0]:<<malloc 8>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage.rxBuffer[0][0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage.rxBuffer[0][1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage.rxBuffer[0][2]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage.rxBuffer[0][3]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage.rxBuffer[0][4]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage.rxBuffer[0][5]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage.rxBuffer[0][6]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticMessage.rxBuffer[0][7]:<<function 1>>
TEST.END

-- Subprogram: (cl)CDoIPHandler::diagnosticPowerModeResponse

-- Test Case: (cl)CDoIPHandler::diagnosticPowerModeResponse.001
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::diagnosticPowerModeResponse
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::diagnosticPowerModeResponse.001
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdUdp::sendMessage
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdUdp::getClientPort
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.udp:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.udp[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticPowerModeResponse.vlanNo:0
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticPowerModeResponse.clientAddr:VECTORCAST_INT1
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdUdp::sendMessage.return:1
TEST.END

-- Test Case: (cl)CDoIPHandler::diagnosticPowerModeResponse.002
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::diagnosticPowerModeResponse
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::diagnosticPowerModeResponse.002
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdUdp::sendMessage
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdUdp::getClientPort
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.udp:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.udp[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.doipHeaderLength:0
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticPowerModeResponse.vlanNo:0
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::diagnosticPowerModeResponse.clientAddr:VECTORCAST_INT1
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdUdp::sendMessage.return:1
TEST.END

-- Subprogram: (cl)CDoIPHandler::doIpauthenticated

-- Test Case: (cl)CDoIPHandler::doIpauthenticated.001
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::doIpauthenticated
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::doIpauthenticated.001
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.END

-- Subprogram: (cl)CDoIPHandler::doipEntityStatusResponse

-- Test Case: (cl)CDoIPHandler::doipEntityStatusResponse.001
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::doipEntityStatusResponse
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::doipEntityStatusResponse.001
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.tcp:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.tcp[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.tcp[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.udp:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.udp[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.udp[1].CSoAdUdp.soadCallbackUdp.vcast_concrete_CSoAdCallbackIf.<<constructor>>.vcast_concrete_CSoAdCallbackIf().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.udp[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.doipStackSize:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::doipEntityStatusResponse.vlanNo:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::doipEntityStatusResponse.clientAddr:VECTORCAST_INT1
TEST.END

-- Test Case: (cl)CDoIPHandler::doipEntityStatusResponse.002
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::doipEntityStatusResponse
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::doipEntityStatusResponse.002
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.tcp:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.tcp[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.tcp[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.udp:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.udp[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.udp[1].CSoAdUdp.soadCallbackUdp.vcast_concrete_CSoAdCallbackIf.<<constructor>>.vcast_concrete_CSoAdCallbackIf().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.udp[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.doipHeaderLength:6
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.doipStackSize:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::doipEntityStatusResponse.vlanNo:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::doipEntityStatusResponse.clientAddr:VECTORCAST_INT1
TEST.END

-- Subprogram: (cl)CDoIPHandler::doipSocketClose

-- Test Case: (cl)CDoIPHandler::doipSocketClose.001
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::doipSocketClose
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::doipSocketClose.001
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getTimerId
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdTcp::socketClose
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.tcp:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.tcp[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.tcp[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.udp:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.udp[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.udp[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoipTimer.CDoIPTimer.mTimerMap:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoipTimer.CDoIPTimer.mTimerMap[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:2
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::doipSocketClose.socketId:1
TEST.END

-- Test Case: (cl)CDoIPHandler::doipSocketClose.002
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::doipSocketClose
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::doipSocketClose.002
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getTimerId
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdTcp::socketClose
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.tcp:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.tcp[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.tcp[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.udp:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.udp[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.udp[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoipTimer.CDoIPTimer.mTimerMap:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoipTimer.CDoIPTimer.mTimerMap[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:2
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::doipSocketClose.socketId:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getTimerId.return:-1
TEST.END

-- Subprogram: (cl)CDoIPHandler::doipTimerBaseTick

-- Test Case: (cl)CDoIPHandler::doipTimerBaseTick.001
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::doipTimerBaseTick
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::doipTimerBaseTick.001
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.END

-- Subprogram: (cl)CDoIPHandler::findTargetType

-- Test Case: (cl)CDoIPHandler::findTargetType.001
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::findTargetType
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::findTargetType.001
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdiagOverIPProtocol:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::findTargetType.targetAddress:16#E001#
TEST.END

-- Test Case: (cl)CDoIPHandler::findTargetType.002
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::findTargetType
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::findTargetType.002
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdiagOverIPProtocol:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::findTargetType.targetAddress:16#E400#
TEST.END

-- Test Case: (cl)CDoIPHandler::findTargetType.003
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::findTargetType
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::findTargetType.003
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdiagOverIPProtocol:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::findTargetType.targetAddress:16#1#
TEST.END

-- Test Case: (cl)CDoIPHandler::findTargetType.004
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::findTargetType
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::findTargetType.004
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdiagOverIPProtocol:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::findTargetType.targetAddress:16#0#
TEST.END

-- Test Case: (cl)CDoIPHandler::findTargetType.005
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::findTargetType
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::findTargetType.005
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpTargetAddressePhysical:16#1#
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdiagOverIPProtocol:2
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::findTargetType.targetAddress:16#1#
TEST.END

-- Test Case: (cl)CDoIPHandler::findTargetType.006
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::findTargetType
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::findTargetType.006
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpTargetAddressePhysical:16#2#
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdiagOverIPProtocol:2
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::findTargetType.targetAddress:16#1#
TEST.END

-- Subprogram: (cl)CDoIPHandler::getPayloadLength

-- Test Case: (cl)CDoIPHandler::getPayloadLength.001
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::getPayloadLength
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::getPayloadLength.001
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0]:<<malloc 9>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][2]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][3]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][4]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][5]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][6]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][7]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][8]:<<function 1>>
TEST.END

-- Test Case: (cl)CDoIPHandler::getPayloadLength.002
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::getPayloadLength
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::getPayloadLength.002
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0]:<<malloc 5>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][2]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][3]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][4]:<<function 1>>
TEST.END

-- Subprogram: (cl)CDoIPHandler::getPayloadType

-- Test Case: (cl)CDoIPHandler::getPayloadType.001
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::getPayloadType
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::getPayloadType.001
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadType.buffer:<<malloc 4>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadType.buffer[0]:<<malloc 6>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadType.buffer[0][0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadType.buffer[0][1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadType.buffer[0][2]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadType.buffer[0][3]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadType.buffer[0][4]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadType.buffer[0][5]:<<function 1>>
TEST.END

-- Test Case: (cl)CDoIPHandler::getPayloadType.002
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::getPayloadType
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::getPayloadType.002
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadType.buffer:<<malloc 4>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadType.buffer[0]:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadType.buffer[0][0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadType.buffer[0][1]:<<function 1>>
TEST.END

-- Subprogram: (cl)CDoIPHandler::getProtocolInverVersion

-- Test Case: (cl)CDoIPHandler::getProtocolInverVersion.001
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::getProtocolInverVersion
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::getProtocolInverVersion.001
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolInverVersion.buffer:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolInverVersion.buffer[0]:<<malloc 3>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolInverVersion.buffer[0][0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolInverVersion.buffer[0][1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolInverVersion.buffer[0][2]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolInverVersion.return:136
TEST.END

-- Test Case: (cl)CDoIPHandler::getProtocolInverVersion.002
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::getProtocolInverVersion
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::getProtocolInverVersion.002
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolInverVersion.buffer:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolInverVersion.buffer[0]:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolInverVersion.buffer[0][0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolInverVersion.buffer[0][1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolInverVersion.return:0
TEST.EXPECTED:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolInverVersion.return:0
TEST.END

-- Subprogram: (cl)CDoIPHandler::getProtocolVersion

-- Test Case: (cl)CDoIPHandler::getProtocolVersion.001
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::getProtocolVersion
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::getProtocolVersion.001
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolVersion.buffer:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolVersion.buffer[0]:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolVersion.buffer[0][0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolVersion.buffer[0][1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolVersion.return:120
TEST.END

-- Test Case: (cl)CDoIPHandler::getProtocolVersion.002
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::getProtocolVersion
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::getProtocolVersion.002
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolVersion.buffer:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolVersion.buffer[0]:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolVersion.buffer[0][0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolVersion.return:0
TEST.EXPECTED:infra_comm_doip_handler.(cl)CDoIPHandler::getProtocolVersion.return:0
TEST.END

-- Subprogram: (cl)CDoIPHandler::getSourceAddress

-- Test Case: (cl)CDoIPHandler::getSourceAddress.001
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::getSourceAddress
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::getSourceAddress.001
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdiagOverIPProtocol:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getSourceAddress.buffer:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getSourceAddress.buffer[0]:<<malloc 11>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getSourceAddress.buffer[0][0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getSourceAddress.buffer[0][10]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getSourceAddress.buffer[0][1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getSourceAddress.buffer[0][2]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getSourceAddress.buffer[0][3]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getSourceAddress.buffer[0][4]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getSourceAddress.buffer[0][5]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getSourceAddress.buffer[0][6]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getSourceAddress.buffer[0][7]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getSourceAddress.buffer[0][8]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getSourceAddress.buffer[0][9]:<<function 1>>
TEST.END

-- Test Case: (cl)CDoIPHandler::getSourceAddress.002
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::getSourceAddress
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::getSourceAddress.002
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdiagOverIPProtocol:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getSourceAddress.buffer:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getSourceAddress.buffer[0]:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getSourceAddress.buffer[0][0]:<<function 1>>
TEST.END

-- Test Case: (cl)CDoIPHandler::getSourceAddress.003
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::getSourceAddress
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::getSourceAddress.003
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdiagOverIPProtocol:2
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getSourceAddress.buffer:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getSourceAddress.buffer[0]:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getSourceAddress.buffer[0][0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getSourceAddress.buffer[0][1]:<<function 1>>
TEST.END

-- Test Case: (cl)CDoIPHandler::getSourceAddress.004
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::getSourceAddress
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::getSourceAddress.004
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdiagOverIPProtocol:2
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getSourceAddress.buffer:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getSourceAddress.buffer[0]:<<malloc 3>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getSourceAddress.buffer[0][0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getSourceAddress.buffer[0][1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getSourceAddress.buffer[0][2]:<<function 1>>
TEST.END

-- Subprogram: (cl)CDoIPHandler::getTargetAddress

-- Test Case: (cl)CDoIPHandler::getTargetAddress.001
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::getTargetAddress
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::getTargetAddress.001
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdiagOverIPProtocol:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getTargetAddress.buffer:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getTargetAddress.buffer[0]:<<malloc 13>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getTargetAddress.buffer[0][0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getTargetAddress.buffer[0][10]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getTargetAddress.buffer[0][11]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getTargetAddress.buffer[0][12]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getTargetAddress.buffer[0][1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getTargetAddress.buffer[0][2]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getTargetAddress.buffer[0][3]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getTargetAddress.buffer[0][4]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getTargetAddress.buffer[0][5]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getTargetAddress.buffer[0][6]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getTargetAddress.buffer[0][7]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getTargetAddress.buffer[0][8]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getTargetAddress.buffer[0][9]:<<function 1>>
TEST.END

-- Test Case: (cl)CDoIPHandler::getTargetAddress.002
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::getTargetAddress
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::getTargetAddress.002
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdiagOverIPProtocol:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getTargetAddress.buffer:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getTargetAddress.buffer[0]:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getTargetAddress.buffer[0][0]:<<function 1>>
TEST.END

-- Test Case: (cl)CDoIPHandler::getTargetAddress.003
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::getTargetAddress
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::getTargetAddress.003
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdiagOverIPProtocol:2
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getTargetAddress.buffer:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getTargetAddress.buffer[0]:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getTargetAddress.buffer[0][0]:<<function 1>>
TEST.END

-- Test Case: (cl)CDoIPHandler::getTargetAddress.004
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::getTargetAddress
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::getTargetAddress.004
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdiagOverIPProtocol:2
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getTargetAddress.buffer:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getTargetAddress.buffer[0]:<<malloc 5>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getTargetAddress.buffer[0][0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getTargetAddress.buffer[0][1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getTargetAddress.buffer[0][2]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getTargetAddress.buffer[0][3]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getTargetAddress.buffer[0][4]:<<function 1>>
TEST.END

-- Subprogram: (cl)CDoIPHandler::getTimerId

-- Test Case: (cl)CDoIPHandler::getTimerId.001
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::getTimerId
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::getTimerId.001
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mTimerId:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mTimerId[0]:<<function 1>>
TEST.END

-- Subprogram: (cl)CDoIPHandler::handleTimeout

-- Test Case: (cl)CDoIPHandler::handleTimeout.001
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::handleTimeout
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::handleTimeout.001
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::doipSocketClose
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::prepareRoutingActivationResponse
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::registerSocket
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.pendingRoutingActivationSocket:1
TEST.END

-- Test Case: (cl)CDoIPHandler::handleTimeout.002
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::handleTimeout
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::handleTimeout.002
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::doipSocketClose
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::prepareRoutingActivationResponse
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::registerSocket
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.pendingRoutingActivationSocket:-1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::handleTimeout.connectionIndex:0
TEST.END

-- Subprogram: (cl)CDoIPHandler::init

-- Test Case: (cl)CDoIPHandler::init.001
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::init
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::init.001
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:2
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mVlanCount:2
TEST.END

-- Subprogram: (cl)CDoIPHandler::messageIndication

-- Test Case: (cl)CDoIPHandler::messageIndication.001
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::messageIndication
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::messageIndication.001
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.END

-- Subprogram: (cl)CDoIPHandler::messageReceived

-- Test Case: (cl)CDoIPHandler::messageReceived.001
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::messageReceived
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::messageReceived.001
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForDoipOrUdsOnIP
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdiagOverIPProtocol:1
TEST.END

-- Test Case: (cl)CDoIPHandler::messageReceived.002
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::messageReceived
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::messageReceived.002
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::dataReceivedForSoAd
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdiagOverIPProtocol:2
TEST.END

-- Subprogram: (cl)CDoIPHandler::periodicTask

-- Test Case: (cl)CDoIPHandler::periodicTask.001
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::periodicTask
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::periodicTask.001
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdTcp::scanSockets
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdTcp::getSocketState
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdUdp::getSocketState
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.tcp:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.tcp[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.udp:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.udp[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mPortNum:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mPortNum[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mVlanCount:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mIpAddress:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mIpAddress[0]:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mIpAddress[0]:"1"
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mIpAddress[0]:<<function 1>>
TEST.END

-- Test Case: (cl)CDoIPHandler::periodicTask.002
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::periodicTask
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::periodicTask.002
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdTcp::scanSockets
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.tcp:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.tcp[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.udp:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.udp[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mPortNum:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mPortNum[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mVlanCount:1
TEST.END

-- Test Case: (cl)CDoIPHandler::periodicTask.003
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::periodicTask
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::periodicTask.003
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdTcp::scanSockets
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.tcp:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.tcp[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.udp:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.udp[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mPortNum:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mPortNum[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mVlanCount:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mIpAddress:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mIpAddress[0]:<<function 1>>
TEST.END

-- Test Case: (cl)CDoIPHandler::periodicTask.004
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::periodicTask
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::periodicTask.004
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdTcp::scanSockets
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.tcp:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.tcp[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.udp:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.udp[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mPortNum:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mPortNum[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mVlanCount:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mIpAddress:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mIpAddress[0]:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mIpAddress[0]:"1"
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mIpAddress[0]:<<function 1>>
TEST.END

-- Subprogram: (cl)CDoIPHandler::prepareAndSendAliveCheckReq

-- Test Case: (cl)CDoIPHandler::prepareAndSendAliveCheckReq.001
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::prepareAndSendAliveCheckReq
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::prepareAndSendAliveCheckReq.001
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdTcp::sendIpMessage
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.tcp:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.tcp[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.tcp[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::prepareAndSendAliveCheckReq.Socket_Id:1
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::sendIpMessage.return:1
TEST.END

-- Test Case: (cl)CDoIPHandler::prepareAndSendAliveCheckReq.002
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::prepareAndSendAliveCheckReq
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::prepareAndSendAliveCheckReq.002
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdTcp::sendIpMessage
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.tcp:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.tcp[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.tcp[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::prepareAndSendAliveCheckReq.Socket_Id:1
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::sendIpMessage.return:8
TEST.END

-- Subprogram: (cl)CDoIPHandler::prepareRoutingActivationResponse

-- Test Case: (cl)CDoIPHandler::prepareRoutingActivationResponse.001
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::prepareRoutingActivationResponse
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::prepareRoutingActivationResponse.001
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdTcp::sendIpMessage
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.tcp:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.tcp[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.tcp[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::prepareRoutingActivationResponse.socketId:1
TEST.END

-- Subprogram: (cl)CDoIPHandler::registerSocket

-- Test Case: (cl)CDoIPHandler::registerSocket.001
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::registerSocket
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::registerSocket.001
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getTimerId
TEST.STUB:infra_comm_doip_timer.(cl)CDoIPTimer::startTimer
TEST.STUB:infra_comm_doip_timer.(cl)CDoIPTimer::stopTimer
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoipTimer.CDoIPTimer.mTimerMap:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoipTimer.CDoIPTimer.mTimerMap[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::registerSocket.slotIndex:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getTimerId.return:-1
TEST.VALUE:infra_comm_doip_timer.(cl)CDoIPTimer::startTimer.timerId:1
TEST.VALUE:infra_comm_doip_timer.(cl)CDoIPTimer::startTimer.timerValue:1
TEST.VALUE:infra_comm_doip_timer.(cl)CDoIPTimer::stopTimer.timerId:1
TEST.END

-- Subprogram: (cl)CDoIPHandler::routingActivationReq

-- Test Case: (cl)CDoIPHandler::routingActivationReq.001
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::routingActivationReq
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::routingActivationReq.001
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::doipSocketClose
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getSourceAddress
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::sourceAddressKnown
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::createAndSendNack
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.return:3
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::routingActivationReq.rxBuffer:<<malloc 20>>
TEST.ATTRIBUTES:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa.sa[0]:INPUT_BASE=16
TEST.ATTRIBUTES:infra_comm_doip_handler.(cl)CDoIPHandler::dataTrasferRequest.targetAddress:INPUT_BASE=16
TEST.END

-- Test Case: (cl)CDoIPHandler::routingActivationReq.002
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::routingActivationReq
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::routingActivationReq.002
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::doipSocketClose
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0]:<<malloc 11>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][10]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][2]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][3]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][4]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][5]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][6]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][7]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][8]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][9]:<<function 1>>
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getSourceAddress
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::sourceAddressKnown
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::prepareRoutingActivationResponse
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::assignSocket
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::createAndSendNack
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.return:11
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::sourceAddressKnown.return:false
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::assignSocket.return:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::routingActivationReq.rxBuffer:<<malloc 20>>
TEST.ATTRIBUTES:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa.sa[0]:INPUT_BASE=16
TEST.ATTRIBUTES:infra_comm_doip_handler.(cl)CDoIPHandler::dataTrasferRequest.targetAddress:INPUT_BASE=16
TEST.END

-- Test Case: (cl)CDoIPHandler::routingActivationReq.SocketAssignment_Pending
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::routingActivationReq
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::routingActivationReq.SocketAssignment_Pending
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::doipSocketClose
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0]:<<malloc 11>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][10]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][2]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][3]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][4]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][5]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][6]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][7]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][8]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][9]:<<function 1>>
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getSourceAddress
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::sourceAddressKnown
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::confirmationRequired
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::confirmed
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::prepareRoutingActivationResponse
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::assignSocket
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::routingTypeSupported
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::createAndSendNack
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.return:11
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::sourceAddressKnown.return:true
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::confirmationRequired.return:true
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::confirmed.return:true
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::assignSocket.return:2
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::routingTypeSupported.return:true
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::routingActivationReq.rxBuffer:<<malloc 20>>
TEST.ATTRIBUTES:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa.sa[0]:INPUT_BASE=16
TEST.ATTRIBUTES:infra_comm_doip_handler.(cl)CDoIPHandler::dataTrasferRequest.targetAddress:INPUT_BASE=16
TEST.END

-- Test Case: (cl)CDoIPHandler::routingActivationReq.authenticationRequired_True
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::routingActivationReq
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::routingActivationReq.authenticationRequired_True
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::doipSocketClose
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0]:<<malloc 11>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][10]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][2]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][3]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][4]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][5]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][6]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][7]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][8]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][9]:<<function 1>>
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getSourceAddress
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::sourceAddressKnown
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::authenticationRequired
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::doIpauthenticated
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::prepareRoutingActivationResponse
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::assignSocket
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::routingTypeSupported
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::createAndSendNack
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.return:11
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::sourceAddressKnown.return:true
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::authenticationRequired.return:true
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::assignSocket.return:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::routingTypeSupported.return:true
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::routingActivationReq.rxBuffer:<<malloc 20>>
TEST.ATTRIBUTES:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa.sa[0]:INPUT_BASE=16
TEST.ATTRIBUTES:infra_comm_doip_handler.(cl)CDoIPHandler::dataTrasferRequest.targetAddress:INPUT_BASE=16
TEST.END

-- Test Case: (cl)CDoIPHandler::routingActivationReq.confirmationRequired
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::routingActivationReq
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::routingActivationReq.confirmationRequired
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::doipSocketClose
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0]:<<malloc 11>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][10]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][2]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][3]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][4]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][5]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][6]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][7]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][8]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][9]:<<function 1>>
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getSourceAddress
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::sourceAddressKnown
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::confirmationRequired
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::prepareRoutingActivationResponse
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::assignSocket
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::routingTypeSupported
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::createAndSendNack
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.return:11
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::sourceAddressKnown.return:true
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::confirmationRequired.return:true
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::assignSocket.return:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::routingTypeSupported.return:true
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::routingActivationReq.rxBuffer:<<malloc 20>>
TEST.ATTRIBUTES:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa.sa[0]:INPUT_BASE=16
TEST.ATTRIBUTES:infra_comm_doip_handler.(cl)CDoIPHandler::dataTrasferRequest.targetAddress:INPUT_BASE=16
TEST.END

-- Test Case: (cl)CDoIPHandler::routingActivationReq.confirmed
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::routingActivationReq
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::routingActivationReq.confirmed
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::doipSocketClose
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0]:<<malloc 11>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][10]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][2]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][3]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][4]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][5]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][6]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][7]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][8]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][9]:<<function 1>>
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getSourceAddress
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::sourceAddressKnown
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::confirmationRequired
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::confirmed
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::prepareRoutingActivationResponse
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::assignSocket
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::routingTypeSupported
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::createAndSendNack
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.return:11
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::sourceAddressKnown.return:true
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::confirmationRequired.return:true
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::confirmed.return:true
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::assignSocket.return:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::routingTypeSupported.return:true
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::routingActivationReq.rxBuffer:<<malloc 20>>
TEST.ATTRIBUTES:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa.sa[0]:INPUT_BASE=16
TEST.ATTRIBUTES:infra_comm_doip_handler.(cl)CDoIPHandler::dataTrasferRequest.targetAddress:INPUT_BASE=16
TEST.END

-- Test Case: (cl)CDoIPHandler::routingActivationReq.routingTypeSupported_False
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::routingActivationReq
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::routingActivationReq.routingTypeSupported_False
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::doipSocketClose
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0]:<<malloc 11>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][10]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][2]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][3]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][4]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][5]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][6]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][7]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][8]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][9]:<<function 1>>
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getSourceAddress
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::sourceAddressKnown
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::prepareRoutingActivationResponse
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::assignSocket
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::routingTypeSupported
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::createAndSendNack
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.return:11
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::sourceAddressKnown.return:true
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::assignSocket.return:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::routingTypeSupported.return:false
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::routingActivationReq.rxBuffer:<<malloc 20>>
TEST.ATTRIBUTES:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa.sa[0]:INPUT_BASE=16
TEST.ATTRIBUTES:infra_comm_doip_handler.(cl)CDoIPHandler::dataTrasferRequest.targetAddress:INPUT_BASE=16
TEST.END

-- Test Case: (cl)CDoIPHandler::routingActivationReq.routingTypeSupported_true
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::routingActivationReq
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::routingActivationReq.routingTypeSupported_true
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::doipSocketClose
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0]:<<malloc 11>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][10]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][2]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][3]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][4]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][5]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][6]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][7]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][8]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][9]:<<function 1>>
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getSourceAddress
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::sourceAddressKnown
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::prepareRoutingActivationResponse
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::assignSocket
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::routingTypeSupported
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::createAndSendNack
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.return:11
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::sourceAddressKnown.return:true
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::assignSocket.return:0
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::routingTypeSupported.return:true
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::routingActivationReq.rxBuffer:<<malloc 20>>
TEST.ATTRIBUTES:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa.sa[0]:INPUT_BASE=16
TEST.ATTRIBUTES:infra_comm_doip_handler.(cl)CDoIPHandler::dataTrasferRequest.targetAddress:INPUT_BASE=16
TEST.END

-- Test Case: (cl)CDoIPHandler::routingActivationReq.socketRegistrationSatus
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::routingActivationReq
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::routingActivationReq.socketRegistrationSatus
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::doipSocketClose
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0]:<<malloc 11>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][10]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][2]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][3]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][4]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][5]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][6]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][7]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][8]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.buffer[0][9]:<<function 1>>
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getSourceAddress
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::sourceAddressKnown
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::prepareRoutingActivationResponse
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::assignSocket
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::routingTypeSupported
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::createAndSendNack
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getPayloadLength.return:11
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::sourceAddressKnown.return:true
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::assignSocket.return:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::routingTypeSupported.return:true
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::routingActivationReq.rxBuffer:<<malloc 20>>
TEST.ATTRIBUTES:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa.sa[0]:INPUT_BASE=16
TEST.ATTRIBUTES:infra_comm_doip_handler.(cl)CDoIPHandler::dataTrasferRequest.targetAddress:INPUT_BASE=16
TEST.END

-- Subprogram: (cl)CDoIPHandler::routingTypeSupported

-- Test Case: (cl)CDoIPHandler::routingTypeSupported.001
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::routingTypeSupported
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::routingTypeSupported.001
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpActivationNumber:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::routingTypeSupported.activationType:ERoutingActivationType_WWH_OBD
TEST.END

-- Test Case: (cl)CDoIPHandler::routingTypeSupported.002
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::routingTypeSupported
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::routingTypeSupported.002
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpActivationNumber:0
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::routingTypeSupported.activationType:ERoutingActivationType_Last
TEST.END

-- Test Case: (cl)CDoIPHandler::routingTypeSupported.ERoutingActivationType_CentralSecurity
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::routingTypeSupported
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::routingTypeSupported.ERoutingActivationType_CentralSecurity
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpActivationNumber:0
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::routingTypeSupported.activationType:ERoutingActivationType_CentralSecurity
TEST.END

-- Test Case: (cl)CDoIPHandler::routingTypeSupported.RoutingActivationType_WWH_OBD
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::routingTypeSupported
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::routingTypeSupported.RoutingActivationType_WWH_OBD
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpActivationNumber:0
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::routingTypeSupported.activationType:ERoutingActivationType_WWH_OBD
TEST.END

-- Subprogram: (cl)CDoIPHandler::sendVehicleAnnouncement

-- Test Case: (cl)CDoIPHandler::sendVehicleAnnouncement.001
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::sendVehicleAnnouncement
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::sendVehicleAnnouncement.001
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getTimerId
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdUdp::sendMessage
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.udp:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.udp[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.udp[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mPortNum:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mPortNum[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mPortNum[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.announceCount:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.announceCount[0]:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.announceCount[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.announceCount[1]:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.announceCount[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::sendVehicleAnnouncement.vlanNo:1
TEST.END

-- Test Case: (cl)CDoIPHandler::sendVehicleAnnouncement.002
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::sendVehicleAnnouncement
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::sendVehicleAnnouncement.002
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getTimerId
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdUdp::sendMessage
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.udp:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.udp[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.udp[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mPortNum:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mPortNum[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mPortNum[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.announceCount:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.announceCount[0]:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.announceCount[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.announceCount[1]:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.announceCount[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::sendVehicleAnnouncement.vlanNo:1
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdUdp::sendMessage.return:41
TEST.END

-- Test Case: (cl)CDoIPHandler::sendVehicleAnnouncement.003
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::sendVehicleAnnouncement
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::sendVehicleAnnouncement.003
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getTimerId
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdUdp::sendMessage
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.udp:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.udp[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.udp[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mPortNum:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mPortNum[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mPortNum[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.announceCount:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.announceCount[0]:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.announceCount[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.announceCount[1]:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.announceCount[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::sendVehicleAnnouncement.vlanNo:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getTimerId.return:-1
TEST.END

-- Test Case: (cl)CDoIPHandler::sendVehicleAnnouncement.announceCount
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::sendVehicleAnnouncement
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::sendVehicleAnnouncement.announceCount
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getTimerId
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdUdp::sendMessage
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.udp:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.udp[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.udp[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mPortNum:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mPortNum[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mPortNum[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.announceCount:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.announceCount[0]:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.announceCount[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.announceCount[1]:4
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.announceCount[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::sendVehicleAnnouncement.vlanNo:1
TEST.END

-- Test Case: (cl)CDoIPHandler::sendVehicleAnnouncement.vehicleAnnouncementDone
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::sendVehicleAnnouncement
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::sendVehicleAnnouncement.vehicleAnnouncementDone
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getTimerId
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdUdp::sendMessage
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.udp:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.udp[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.udp[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mPortNum:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mPortNum[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mPortNum[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.vehicleAnnouncementDone:true
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.announceCount:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.announceCount[0]:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.announceCount[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.announceCount[1]:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.announceCount[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::sendVehicleAnnouncement.vlanNo:1
TEST.END

-- Subprogram: (cl)CDoIPHandler::setDoIPParams

-- Test Case: (cl)CDoIPHandler::setDoIPParams.001
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::setDoIPParams
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::setDoIPParams.001
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::setDoIPParams.msg.vinNumber:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::setDoIPParams.msg.vinNumber:"a"
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::setDoIPParams.msg.eidNumber:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::setDoIPParams.msg.eidNumber:"b"
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::setDoIPParams.msg.gidNumber:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::setDoIPParams.msg.gidNumber:"c"
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::setDoIPParams.msg.isVinNumValid:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::setDoIPParams.msg.isGidNumValid:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::setDoIPParams.msg.isEidNumValid:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::setDoIPParams.msg.isNetWorkConfigValid:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::setDoIPParams.msg.isGidSyncStatusValid:1
TEST.END

-- Subprogram: (cl)CDoIPHandler::sourceAddressKnown

-- Test Case: (cl)CDoIPHandler::sourceAddressKnown.001
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::sourceAddressKnown
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::sourceAddressKnown.001
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpsourceAddressCount:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpSourceAddress:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpSourceAddress[0]:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpSourceAddress[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::sourceAddressKnown.sourceAddress:1
TEST.END

-- Test Case: (cl)CDoIPHandler::sourceAddressKnown.002
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::sourceAddressKnown
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::sourceAddressKnown.002
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpsourceAddressCount:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpSourceAddress:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpSourceAddress[0]:11
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpSourceAddress[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::sourceAddressKnown.sourceAddress:1
TEST.END

-- Subprogram: (cl)CDoIPHandler::startAllSaAliveCheck

-- Test Case: (cl)CDoIPHandler::startAllSaAliveCheck.001
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::startAllSaAliveCheck
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::startAllSaAliveCheck.001
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::prepareAndSendAliveCheckReq
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getTimerId
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:SocketStateType_ConnectionRegistered
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mVlanCount:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getTimerId.return:1
TEST.END

-- Test Case: (cl)CDoIPHandler::startAllSaAliveCheck.002
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::startAllSaAliveCheck
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::startAllSaAliveCheck.002
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::prepareAndSendAliveCheckReq
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getTimerId
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:SocketStateType_ConnectionRegistered
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mVlanCount:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getTimerId.return:-1
TEST.END

-- Test Case: (cl)CDoIPHandler::startAllSaAliveCheck.003
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::startAllSaAliveCheck
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::startAllSaAliveCheck.003
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::prepareAndSendAliveCheckReq
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getTimerId
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:SocketStateType_ConnectionInvalid
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mVlanCount:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getTimerId.return:1
TEST.END

-- Subprogram: (cl)CDoIPHandler::startSingleSaAliveCheck

-- Test Case: (cl)CDoIPHandler::startSingleSaAliveCheck.001
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::startSingleSaAliveCheck
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::startSingleSaAliveCheck.001
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::prepareAndSendAliveCheckReq
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getTimerId
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[0]:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse[0]:false
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mVlanCount:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::startSingleSaAliveCheck.sourceAddress:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getTimerId.return:1
TEST.END

-- Test Case: (cl)CDoIPHandler::startSingleSaAliveCheck.002
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::startSingleSaAliveCheck
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::startSingleSaAliveCheck.002
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::prepareAndSendAliveCheckReq
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getTimerId
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[0]:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse[0]:false
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mVlanCount:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::startSingleSaAliveCheck.sourceAddress:2
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getTimerId.return:1
TEST.END

-- Test Case: (cl)CDoIPHandler::startSingleSaAliveCheck.003
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::startSingleSaAliveCheck
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::startSingleSaAliveCheck.003
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::prepareAndSendAliveCheckReq
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getTimerId
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[0]:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse[0]:false
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mVlanCount:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::startSingleSaAliveCheck.sourceAddress:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getTimerId.return:-1
TEST.END

-- Subprogram: (cl)CDoIPHandler::stop

-- Test Case: (cl)CDoIPHandler::stop.001
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::stop
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::stop.001
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sockNr:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sockNr[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sockNr[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mVlanCount:1
TEST.END

-- Test Case: (cl)CDoIPHandler::stop.002
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::stop
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::stop.002
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getTimerId
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sockNr:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sockNr[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sockNr[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mVlanCount:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getTimerId.return:2
TEST.END

-- Subprogram: (cl)CDoIPHandler::targetAddressSupported

-- Test Case: (cl)CDoIPHandler::targetAddressSupported.001
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::targetAddressSupported
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::targetAddressSupported.001
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpTargetAddressePhysical:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::targetAddressSupported.ta:1
TEST.END

-- Test Case: (cl)CDoIPHandler::targetAddressSupported.002
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::targetAddressSupported
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::targetAddressSupported.002
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpTargetAddressePhysical:2
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpTargetAddressesFunctional:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpTargetAddressesFunctional[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpTargetAddressesFunctional[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpTargetAddressCount:2
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::targetAddressSupported.ta:1
TEST.END

-- Test Case: (cl)CDoIPHandler::targetAddressSupported.003
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::targetAddressSupported
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::targetAddressSupported.003
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdTcp::sendIpMessage
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.tcp:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.tcp[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpTargetAddressePhysical:2
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpTargetAddressesFunctional:<<malloc 2>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpTargetAddressesFunctional[0]:1
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpTargetAddressesFunctional[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpTargetAddressesFunctional[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpTargetAddressCount:2
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::targetAddressSupported.ta:1
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::sendIpMessage.return:1
TEST.END

-- Subprogram: (cl)CDoIPHandler::tcpConnectionEstablished

-- Test Case: (cl)CDoIPHandler::tcpConnectionEstablished.001
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::tcpConnectionEstablished
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::tcpConnectionEstablished.001
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::restartTimer
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getTimerId
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sockNr:<<malloc 7>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sockNr[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sockNr[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sockNr[2]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sockNr[3]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sockNr[4]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sockNr[5]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sockNr[6]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState:<<malloc 3>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[1]:SocketStateType_ConnectionInvalid
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[2]:SocketStateType_ConnectionInvalid
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[2]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse:<<malloc 3>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse[2]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:11
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::tcpConnectionEstablished.socketId:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::tcpConnectionEstablished.vlanNo:0
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getTimerId.socketIndex:2
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getTimerId.eTimer:ETimers_InitialInActivity
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getTimerId.return:1
TEST.END

-- Test Case: (cl)CDoIPHandler::tcpConnectionEstablished.002
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::tcpConnectionEstablished
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::tcpConnectionEstablished.002
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::restartTimer
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getTimerId
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sockNr:<<malloc 7>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sockNr[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sockNr[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sockNr[2]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sockNr[3]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sockNr[4]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sockNr[5]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sockNr[6]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState:<<malloc 3>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[1]:SocketStateType_ConnectionEstablished
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[2]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse:<<malloc 3>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse[2]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:11
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::tcpConnectionEstablished.socketId:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::tcpConnectionEstablished.vlanNo:0
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getTimerId.socketIndex:2
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getTimerId.eTimer:ETimers_InitialInActivity
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getTimerId.return:1
TEST.END

-- Subprogram: (cl)CDoIPHandler::tcpSocketClose

-- Test Case: (cl)CDoIPHandler::tcpSocketClose.001
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::tcpSocketClose
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::tcpSocketClose.001
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getTimerId
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa:<<malloc 3>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[2]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState:<<malloc 3>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[2]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse:<<malloc 3>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse[2]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getTimerId.return:2
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::tcpSocketClose.socketId:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::tcpSocketClose.vlanNo:1
TEST.END

-- Test Case: (cl)CDoIPHandler::tcpSocketClose.getTimerId_False_case
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::tcpSocketClose
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::tcpSocketClose.getTimerId_False_case
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getTimerId
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa:<<malloc 3>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.sa[2]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState:<<malloc 3>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.DoIPSocketState[2]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse:<<malloc 3>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.awaitingAliveCheckResponse[2]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoIpNoOfSocketsSupported:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getTimerId.return:-1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::tcpSocketClose.socketId:1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::tcpSocketClose.vlanNo:1
TEST.END

-- Subprogram: (cl)CDoIPHandler::vehicleIdentificationRequest

-- Test Case: (cl)CDoIPHandler::vehicleIdentificationRequest.001
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::vehicleIdentificationRequest
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::vehicleIdentificationRequest.001
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::sendVehicleAnnouncement
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getTimerId
TEST.STUB:infra_comm_doip_timer.(cl)CDoIPTimer::stopTimer
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoipTimer.CDoIPTimer.mTimerMap:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoipTimer.CDoIPTimer.mTimerMap[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::vehicleIdentificationRequest.rxBuffer:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::vehicleIdentificationRequest.clientAddr:VECTORCAST_INT1
TEST.VALUE:infra_comm_doip_timer.(cl)CDoIPTimer::stopTimer.timerId:1
TEST.ATTRIBUTES:infra_comm_doip_handler.(cl)CDoIPHandler::findTargetType.targetAddress:INPUT_BASE=16
TEST.END

-- Test Case: (cl)CDoIPHandler::vehicleIdentificationRequest.002
TEST.UNIT:infra_comm_doip_handler
TEST.SUBPROGRAM:(cl)CDoIPHandler::vehicleIdentificationRequest
TEST.NEW
TEST.NAME:(cl)CDoIPHandler::vehicleIdentificationRequest.002
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::sendVehicleAnnouncement
TEST.STUB:infra_comm_doip_handler.(cl)CDoIPHandler::getTimerId
TEST.STUB:infra_comm_doip_timer.(cl)CDoIPTimer::stopTimer
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.<<constructor>>.CDoIPHandler().<<call>>:0
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoipTimer.CDoIPTimer.mTimerMap:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.<<GLOBAL>>.(cl).CDoIPHandler.CDoIPHandler.mdoipTimer.CDoIPTimer.mTimerMap[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::vehicleIdentificationRequest.rxBuffer:<<malloc 1>>
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::vehicleIdentificationRequest.clientAddr:VECTORCAST_INT1
TEST.VALUE:infra_comm_doip_handler.(cl)CDoIPHandler::getTimerId.return:-1
TEST.VALUE:infra_comm_doip_timer.(cl)CDoIPTimer::stopTimer.timerId:1
TEST.ATTRIBUTES:infra_comm_doip_handler.(cl)CDoIPHandler::findTargetType.targetAddress:INPUT_BASE=16
TEST.END

-- Unit: infra_comm_doip_ringbuffer

-- Subprogram: (cl)CRingBuffer::init

-- Test Case: (cl)CRingBuffer::init.001
TEST.UNIT:infra_comm_doip_ringbuffer
TEST.SUBPROGRAM:(cl)CRingBuffer::init
TEST.NEW
TEST.NAME:(cl)CRingBuffer::init.001
TEST.VALUE:infra_comm_doip_ringbuffer.<<GLOBAL>>.(cl).CRingBuffer.CRingBuffer.<<constructor>>.CRingBuffer().<<call>>:0
TEST.VALUE:infra_comm_doip_ringbuffer.(cl)CRingBuffer::init.buffer:<<malloc 1>>
TEST.END

-- Subprogram: (cl)CRingBuffer::poll

-- Test Case: (cl)CRingBuffer::poll.001
TEST.UNIT:infra_comm_doip_ringbuffer
TEST.SUBPROGRAM:(cl)CRingBuffer::poll
TEST.NEW
TEST.NAME:(cl)CRingBuffer::poll.001
TEST.VALUE:infra_comm_doip_ringbuffer.<<GLOBAL>>.(cl).CRingBuffer.CRingBuffer.<<constructor>>.CRingBuffer().<<call>>:0
TEST.VALUE:infra_comm_doip_ringbuffer.(cl)CRingBuffer::poll.buffer:<<malloc 1>>
TEST.VALUE:infra_comm_doip_ringbuffer.(cl)CRingBuffer::poll.buffer[0].read_index:0
TEST.END

-- Test Case: (cl)CRingBuffer::poll.002
TEST.UNIT:infra_comm_doip_ringbuffer
TEST.SUBPROGRAM:(cl)CRingBuffer::poll
TEST.NEW
TEST.NAME:(cl)CRingBuffer::poll.002
TEST.VALUE:infra_comm_doip_ringbuffer.<<GLOBAL>>.(cl).CRingBuffer.CRingBuffer.<<constructor>>.CRingBuffer().<<call>>:0
TEST.VALUE:infra_comm_doip_ringbuffer.(cl)CRingBuffer::poll.buffer:<<malloc 1>>
TEST.VALUE:infra_comm_doip_ringbuffer.(cl)CRingBuffer::poll.buffer[0].data:<<malloc 6>>
TEST.VALUE:infra_comm_doip_ringbuffer.(cl)CRingBuffer::poll.buffer[0].data:"hello"
TEST.VALUE:infra_comm_doip_ringbuffer.(cl)CRingBuffer::poll.buffer[0].read_index:0
TEST.VALUE:infra_comm_doip_ringbuffer.(cl)CRingBuffer::poll.buffer[0].fill_count:1
TEST.VALUE:infra_comm_doip_ringbuffer.(cl)CRingBuffer::poll.headString:<<malloc 6>>
TEST.VALUE:infra_comm_doip_ringbuffer.(cl)CRingBuffer::poll.headString:"hello"
TEST.END

-- Test Case: (cl)CRingBuffer::poll.003
TEST.UNIT:infra_comm_doip_ringbuffer
TEST.SUBPROGRAM:(cl)CRingBuffer::poll
TEST.NEW
TEST.NAME:(cl)CRingBuffer::poll.003
TEST.VALUE:infra_comm_doip_ringbuffer.<<GLOBAL>>.(cl).CRingBuffer.CRingBuffer.<<constructor>>.CRingBuffer().<<call>>:0
TEST.VALUE:infra_comm_doip_ringbuffer.(cl)CRingBuffer::poll.buffer:<<malloc 1>>
TEST.VALUE:infra_comm_doip_ringbuffer.(cl)CRingBuffer::poll.buffer[0].data:<<malloc 6>>
TEST.VALUE:infra_comm_doip_ringbuffer.(cl)CRingBuffer::poll.buffer[0].data:"hello"
TEST.VALUE:infra_comm_doip_ringbuffer.(cl)CRingBuffer::poll.buffer[0].read_index:0
TEST.VALUE:infra_comm_doip_ringbuffer.(cl)CRingBuffer::poll.buffer[0].fill_count:1
TEST.VALUE:infra_comm_doip_ringbuffer.(cl)CRingBuffer::poll.headString:<<malloc 4>>
TEST.VALUE:infra_comm_doip_ringbuffer.(cl)CRingBuffer::poll.headString:"hlo"
TEST.END

-- Subprogram: (cl)CRingBuffer::read

-- Test Case: (cl)CRingBuffer::read.001
TEST.UNIT:infra_comm_doip_ringbuffer
TEST.SUBPROGRAM:(cl)CRingBuffer::read
TEST.NEW
TEST.NAME:(cl)CRingBuffer::read.001
TEST.VALUE:infra_comm_doip_ringbuffer.<<GLOBAL>>.(cl).CRingBuffer.CRingBuffer.<<constructor>>.CRingBuffer().<<call>>:0
TEST.VALUE:infra_comm_doip_ringbuffer.(cl)CRingBuffer::read.buffer:<<malloc 1>>
TEST.VALUE:infra_comm_doip_ringbuffer.(cl)CRingBuffer::read.buffer[0].read_index:2
TEST.VALUE:infra_comm_doip_ringbuffer.(cl)CRingBuffer::read.buffer[0].write_index:1
TEST.VALUE:infra_comm_doip_ringbuffer.(cl)CRingBuffer::read.buffer[0].fill_count:1
TEST.VALUE:infra_comm_doip_ringbuffer.(cl)CRingBuffer::read.data:<<malloc 1>>
TEST.VALUE:infra_comm_doip_ringbuffer.(cl)CRingBuffer::read.size:1
TEST.END

-- Test Case: (cl)CRingBuffer::read.002
TEST.UNIT:infra_comm_doip_ringbuffer
TEST.SUBPROGRAM:(cl)CRingBuffer::read
TEST.NEW
TEST.NAME:(cl)CRingBuffer::read.002
TEST.VALUE:infra_comm_doip_ringbuffer.<<GLOBAL>>.(cl).CRingBuffer.CRingBuffer.<<constructor>>.CRingBuffer().<<call>>:0
TEST.VALUE:infra_comm_doip_ringbuffer.(cl)CRingBuffer::read.buffer:<<malloc 1>>
TEST.VALUE:infra_comm_doip_ringbuffer.(cl)CRingBuffer::read.buffer[0].read_index:2
TEST.VALUE:infra_comm_doip_ringbuffer.(cl)CRingBuffer::read.buffer[0].write_index:1
TEST.VALUE:infra_comm_doip_ringbuffer.(cl)CRingBuffer::read.buffer[0].fill_count:1
TEST.VALUE:infra_comm_doip_ringbuffer.(cl)CRingBuffer::read.data:<<malloc 1>>
TEST.VALUE:infra_comm_doip_ringbuffer.(cl)CRingBuffer::read.size:2
TEST.END

-- Test Case: (cl)CRingBuffer::read.003
TEST.UNIT:infra_comm_doip_ringbuffer
TEST.SUBPROGRAM:(cl)CRingBuffer::read
TEST.NEW
TEST.NAME:(cl)CRingBuffer::read.003
TEST.VALUE:infra_comm_doip_ringbuffer.<<GLOBAL>>.(cl).CRingBuffer.CRingBuffer.<<constructor>>.CRingBuffer().<<call>>:0
TEST.VALUE:infra_comm_doip_ringbuffer.(cl)CRingBuffer::read.buffer:<<malloc 1>>
TEST.VALUE:infra_comm_doip_ringbuffer.(cl)CRingBuffer::read.buffer[0].read_index:2
TEST.VALUE:infra_comm_doip_ringbuffer.(cl)CRingBuffer::read.buffer[0].write_index:1
TEST.VALUE:infra_comm_doip_ringbuffer.(cl)CRingBuffer::read.buffer[0].fill_count:0
TEST.VALUE:infra_comm_doip_ringbuffer.(cl)CRingBuffer::read.data:<<malloc 1>>
TEST.VALUE:infra_comm_doip_ringbuffer.(cl)CRingBuffer::read.size:2
TEST.END

-- Subprogram: (cl)CRingBuffer::reset

-- Test Case: (cl)CRingBuffer::reset.001
TEST.UNIT:infra_comm_doip_ringbuffer
TEST.SUBPROGRAM:(cl)CRingBuffer::reset
TEST.NEW
TEST.NAME:(cl)CRingBuffer::reset.001
TEST.VALUE:infra_comm_doip_ringbuffer.<<GLOBAL>>.(cl).CRingBuffer.CRingBuffer.<<constructor>>.CRingBuffer().<<call>>:0
TEST.VALUE:infra_comm_doip_ringbuffer.(cl)CRingBuffer::reset.buffer:<<malloc 1>>
TEST.END

-- Subprogram: (cl)CRingBuffer::write

-- Test Case: (cl)CRingBuffer::write.001
TEST.UNIT:infra_comm_doip_ringbuffer
TEST.SUBPROGRAM:(cl)CRingBuffer::write
TEST.NEW
TEST.NAME:(cl)CRingBuffer::write.001
TEST.VALUE:infra_comm_doip_ringbuffer.<<GLOBAL>>.(cl).CRingBuffer.CRingBuffer.<<constructor>>.CRingBuffer().<<call>>:0
TEST.VALUE:infra_comm_doip_ringbuffer.(cl)CRingBuffer::write.buffer:<<malloc 1>>
TEST.END

-- Test Case: (cl)CRingBuffer::write.002
TEST.UNIT:infra_comm_doip_ringbuffer
TEST.SUBPROGRAM:(cl)CRingBuffer::write
TEST.NEW
TEST.NAME:(cl)CRingBuffer::write.002
TEST.VALUE:infra_comm_doip_ringbuffer.<<GLOBAL>>.(cl).CRingBuffer.CRingBuffer.<<constructor>>.CRingBuffer().<<call>>:0
TEST.VALUE:infra_comm_doip_ringbuffer.(cl)CRingBuffer::write.buffer:<<malloc 1>>
TEST.VALUE:infra_comm_doip_ringbuffer.(cl)CRingBuffer::write.buffer[0].write_index:1
TEST.VALUE:infra_comm_doip_ringbuffer.(cl)CRingBuffer::write.buffer[0].fill_count:65535
TEST.VALUE:infra_comm_doip_ringbuffer.(cl)CRingBuffer::write.data:<<malloc 2>>
TEST.VALUE_USER_CODE:infra_comm_doip_ringbuffer.(cl)CRingBuffer::write.size
<<infra_comm_doip_ringbuffer.(cl)CRingBuffer::write.size>> = 263000;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Unit: infra_comm_doip_soad

-- Subprogram: (cl)CSoAdTcp::deInit

-- Test Case: (cl)CSoAdTcp::deInit.001
TEST.UNIT:infra_comm_doip_soad
TEST.SUBPROGRAM:(cl)CSoAdTcp::deInit
TEST.NEW
TEST.NAME:(cl)CSoAdTcp::deInit.001
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.<<constructor>>.CSoAdTcp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdUdp.CSoAdUdp.<<constructor>>.CSoAdUdp().<<call>>:0
TEST.END

-- Subprogram: (cl)CSoAdTcp::getNumberOfSocketsOpened

-- Test Case: (cl)CSoAdTcp::getNumberOfSocketsOpened.001
TEST.UNIT:infra_comm_doip_soad
TEST.SUBPROGRAM:(cl)CSoAdTcp::getNumberOfSocketsOpened
TEST.NEW
TEST.NAME:(cl)CSoAdTcp::getNumberOfSocketsOpened.001
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.<<constructor>>.CSoAdTcp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdUdp.CSoAdUdp.<<constructor>>.CSoAdUdp().<<call>>:0
TEST.END

-- Subprogram: (cl)CSoAdTcp::getSocketState

-- Test Case: (cl)CSoAdTcp::getSocketState.001
TEST.UNIT:infra_comm_doip_soad
TEST.SUBPROGRAM:(cl)CSoAdTcp::getSocketState
TEST.NEW
TEST.NAME:(cl)CSoAdTcp::getSocketState.001
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.<<constructor>>.CSoAdTcp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.tcpSocketState:<<malloc 1>>
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.tcpSocketState[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdUdp.CSoAdUdp.<<constructor>>.CSoAdUdp().<<call>>:0
TEST.END

-- Subprogram: (cl)CSoAdTcp::init

-- Test Case: (cl)CSoAdTcp::init.001
TEST.UNIT:infra_comm_doip_soad
TEST.SUBPROGRAM:(cl)CSoAdTcp::init
TEST.NEW
TEST.NAME:(cl)CSoAdTcp::init.001
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.<<constructor>>.CSoAdTcp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdUdp.CSoAdUdp.<<constructor>>.CSoAdUdp().<<call>>:0
TEST.END

-- Subprogram: (cl)CSoAdTcp::readFrameLength

-- Test Case: (cl)CSoAdTcp::readFrameLength.001
TEST.UNIT:infra_comm_doip_soad
TEST.SUBPROGRAM:(cl)CSoAdTcp::readFrameLength
TEST.NEW
TEST.NAME:(cl)CSoAdTcp::readFrameLength.001
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.<<constructor>>.CSoAdTcp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.headerLength:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.tcpStackSize:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdUdp.CSoAdUdp.<<constructor>>.CSoAdUdp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::readFrameLength.msRingBuff:<<malloc 1>>
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::readFrameLength.msRingBuff[0].data[7]:1
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::readFrameLength.msRingBuff[0].read_index:0
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::readFrameLength.msRingBuff[0].fill_count:0
TEST.END

-- Test Case: (cl)CSoAdTcp::readFrameLength.002
TEST.UNIT:infra_comm_doip_soad
TEST.SUBPROGRAM:(cl)CSoAdTcp::readFrameLength
TEST.NEW
TEST.NAME:(cl)CSoAdTcp::readFrameLength.002
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.<<constructor>>.CSoAdTcp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.headerLength:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.tcpStackSize:1
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdUdp.CSoAdUdp.<<constructor>>.CSoAdUdp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::readFrameLength.msRingBuff:<<malloc 1>>
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::readFrameLength.msRingBuff[0].data[7]:1
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::readFrameLength.msRingBuff[0].read_index:0
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::readFrameLength.msRingBuff[0].fill_count:0
TEST.END

-- Test Case: (cl)CSoAdTcp::readFrameLength.003
TEST.UNIT:infra_comm_doip_soad
TEST.SUBPROGRAM:(cl)CSoAdTcp::readFrameLength
TEST.NEW
TEST.NAME:(cl)CSoAdTcp::readFrameLength.003
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.<<constructor>>.CSoAdTcp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.headerLength:3
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.tcpStackSize:1
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdUdp.CSoAdUdp.<<constructor>>.CSoAdUdp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::readFrameLength.msRingBuff:<<malloc 1>>
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::readFrameLength.msRingBuff[0].data[7]:1
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::readFrameLength.msRingBuff[0].read_index:0
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::readFrameLength.msRingBuff[0].fill_count:0
TEST.END

-- Subprogram: (cl)CSoAdTcp::rxIndication

-- Test Case: (cl)CSoAdTcp::rxIndication.001
TEST.UNIT:infra_comm_doip_soad
TEST.SUBPROGRAM:(cl)CSoAdTcp::rxIndication
TEST.NEW
TEST.NAME:(cl)CSoAdTcp::rxIndication.001
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdTcp::getSocketState
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdTcp::readFrameLength
TEST.VALUE:uut_prototype_stubs.recv.return:1
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.<<constructor>>.CSoAdTcp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.connectionHandle:<<malloc 1>>
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.connectionHandle[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.soadCallback.vcast_concrete_CSoAdCallbackIf.<<constructor>>.vcast_concrete_CSoAdCallbackIf().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdUdp.CSoAdUdp.<<constructor>>.CSoAdUdp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::getSocketState.return:3
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::rxIndication.socketId:0
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::readFrameLength.return:1
TEST.END

-- Test Case: (cl)CSoAdTcp::rxIndication.002
TEST.UNIT:infra_comm_doip_soad
TEST.SUBPROGRAM:(cl)CSoAdTcp::rxIndication
TEST.NEW
TEST.NAME:(cl)CSoAdTcp::rxIndication.002
TEST.STUB:infra_comm_doip_ringbuffer.(cl)CRingBuffer::poll
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdTcp::getSocketState
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdTcp::readFrameLength
TEST.VALUE:uut_prototype_stubs.recv.return:1
TEST.VALUE:infra_comm_doip_ringbuffer.<<GLOBAL>>.(cl).CRingBuffer.CRingBuffer.<<constructor>>.CRingBuffer().<<call>>:0
TEST.VALUE:infra_comm_doip_ringbuffer.(cl)CRingBuffer::poll.return:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.<<constructor>>.CSoAdTcp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.connectionHandle:<<malloc 1>>
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.connectionHandle[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.soadCallback.vcast_concrete_CSoAdCallbackIf.<<constructor>>.vcast_concrete_CSoAdCallbackIf().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdUdp.CSoAdUdp.<<constructor>>.CSoAdUdp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::getSocketState.return:3
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::rxIndication.socketId:0
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::readFrameLength.return:1,0
TEST.END

-- Test Case: (cl)CSoAdTcp::rxIndication.004
TEST.UNIT:infra_comm_doip_soad
TEST.SUBPROGRAM:(cl)CSoAdTcp::rxIndication
TEST.NEW
TEST.NAME:(cl)CSoAdTcp::rxIndication.004
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdTcp::getSocketState
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdTcp::readFrameLength
TEST.VALUE:uut_prototype_stubs.recv.return:-1
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.<<constructor>>.CSoAdTcp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.connectionHandle:<<malloc 1>>
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.connectionHandle[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.soadCallback.vcast_concrete_CSoAdCallbackIf.<<constructor>>.vcast_concrete_CSoAdCallbackIf().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdUdp.CSoAdUdp.<<constructor>>.CSoAdUdp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::getSocketState.return:3
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::rxIndication.socketId:0
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::readFrameLength.return:1
TEST.END

-- Test Case: (cl)CSoAdTcp::rxIndication.005
TEST.UNIT:infra_comm_doip_soad
TEST.SUBPROGRAM:(cl)CSoAdTcp::rxIndication
TEST.NEW
TEST.NAME:(cl)CSoAdTcp::rxIndication.005
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdTcp::getSocketState
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdTcp::readFrameLength
TEST.VALUE:uut_prototype_stubs.recv.return:1
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.<<constructor>>.CSoAdTcp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.connectionHandle:<<malloc 1>>
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.connectionHandle[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.soadCallback.vcast_concrete_CSoAdCallbackIf.<<constructor>>.vcast_concrete_CSoAdCallbackIf().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdUdp.CSoAdUdp.<<constructor>>.CSoAdUdp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::getSocketState.return:1
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::rxIndication.socketId:0
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::readFrameLength.return:1
TEST.END

-- Test Case: (cl)CSoAdTcp::rxIndication.006
TEST.UNIT:infra_comm_doip_soad
TEST.SUBPROGRAM:(cl)CSoAdTcp::rxIndication
TEST.NEW
TEST.NAME:(cl)CSoAdTcp::rxIndication.006
TEST.STUB:infra_comm_doip_ringbuffer.(cl)CRingBuffer::read
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdTcp::getSocketState
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdTcp::readFrameLength
TEST.VALUE:uut_prototype_stubs.recv.return:1
TEST.VALUE:infra_comm_doip_ringbuffer.(cl)CRingBuffer::read.return:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.<<constructor>>.CSoAdTcp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.connectionHandle:<<malloc 1>>
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.connectionHandle[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.soadCallback.vcast_concrete_CSoAdCallbackIf.<<constructor>>.vcast_concrete_CSoAdCallbackIf().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdUdp.CSoAdUdp.<<constructor>>.CSoAdUdp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::getSocketState.return:3
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::rxIndication.socketId:0
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::readFrameLength.return:1
TEST.END

-- Test Case: (cl)CSoAdTcp::rxIndication.007
TEST.UNIT:infra_comm_doip_soad
TEST.SUBPROGRAM:(cl)CSoAdTcp::rxIndication
TEST.NEW
TEST.NAME:(cl)CSoAdTcp::rxIndication.007
TEST.STUB:infra_comm_doip_ringbuffer.(cl)CRingBuffer::poll
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdTcp::getSocketState
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdTcp::readFrameLength
TEST.VALUE:uut_prototype_stubs.recv.return:1
TEST.VALUE:infra_comm_doip_ringbuffer.(cl)CRingBuffer::poll.return:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.<<constructor>>.CSoAdTcp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.connectionHandle:<<malloc 1>>
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.connectionHandle[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.soadCallback.vcast_concrete_CSoAdCallbackIf.<<constructor>>.vcast_concrete_CSoAdCallbackIf().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdUdp.CSoAdUdp.<<constructor>>.CSoAdUdp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::getSocketState.return:3
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::rxIndication.socketId:0
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::readFrameLength.return:1
TEST.END

-- Test Case: (cl)CSoAdTcp::rxIndication.009
TEST.UNIT:infra_comm_doip_soad
TEST.SUBPROGRAM:(cl)CSoAdTcp::rxIndication
TEST.NEW
TEST.NAME:(cl)CSoAdTcp::rxIndication.009
TEST.STUB:infra_comm_doip_ringbuffer.(cl)CRingBuffer::write
TEST.STUB:infra_comm_doip_ringbuffer.(cl)CRingBuffer::poll
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdTcp::getSocketState
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdTcp::readFrameLength
TEST.VALUE:uut_prototype_stubs.recv.return:1
TEST.VALUE:infra_comm_doip_ringbuffer.<<GLOBAL>>.(cl).CRingBuffer.CRingBuffer.<<constructor>>.CRingBuffer().<<call>>:0
TEST.VALUE:infra_comm_doip_ringbuffer.(cl)CRingBuffer::write.return:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.<<constructor>>.CSoAdTcp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.connectionHandle:<<malloc 1>>
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.connectionHandle[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.soadCallback.vcast_concrete_CSoAdCallbackIf.<<constructor>>.vcast_concrete_CSoAdCallbackIf().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdUdp.CSoAdUdp.<<constructor>>.CSoAdUdp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::getSocketState.return:3
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::rxIndication.socketId:0
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::readFrameLength.return:1,0
TEST.END

-- Subprogram: (cl)CSoAdTcp::scanSockets

-- Test Case: (cl)CSoAdTcp::scanSockets.ESocketState_Init
TEST.UNIT:infra_comm_doip_soad
TEST.SUBPROGRAM:(cl)CSoAdTcp::scanSockets
TEST.NEW
TEST.NAME:(cl)CSoAdTcp::scanSockets.ESocketState_Init
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdTcp::getSocketState
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdUdp::scanSockets
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.<<constructor>>.CSoAdTcp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdUdp.CSoAdUdp.<<constructor>>.CSoAdUdp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::scanSockets.vlanNo:1
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::scanSockets.i:0
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::scanSockets.portNum:1
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::scanSockets.address:<<malloc 5>>
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::scanSockets.address:"1024"
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::getSocketState.i:0
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::getSocketState.return:1
TEST.END

-- Test Case: (cl)CSoAdTcp::scanSockets.ESocketState_TcpListening
TEST.UNIT:infra_comm_doip_soad
TEST.SUBPROGRAM:(cl)CSoAdTcp::scanSockets
TEST.NEW
TEST.NAME:(cl)CSoAdTcp::scanSockets.ESocketState_TcpListening
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdTcp::getSocketState
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdTcp::tcpAccepted
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdUdp::scanSockets
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.<<constructor>>.CSoAdTcp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdUdp.CSoAdUdp.<<constructor>>.CSoAdUdp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::scanSockets.vlanNo:1
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::scanSockets.i:0
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::scanSockets.portNum:1
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::scanSockets.address:<<malloc 5>>
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::scanSockets.address:"1024"
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::getSocketState.i:0
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::getSocketState.return:2
TEST.END

-- Test Case: (cl)CSoAdTcp::scanSockets.ESocketState_TcpReady
TEST.UNIT:infra_comm_doip_soad
TEST.SUBPROGRAM:(cl)CSoAdTcp::scanSockets
TEST.NEW
TEST.NAME:(cl)CSoAdTcp::scanSockets.ESocketState_TcpReady
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdTcp::getSocketState
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdTcp::tcpAccepted
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdTcp::rxIndication
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdUdp::scanSockets
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.<<constructor>>.CSoAdTcp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdUdp.CSoAdUdp.<<constructor>>.CSoAdUdp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::scanSockets.vlanNo:1
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::scanSockets.i:0
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::scanSockets.portNum:1
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::scanSockets.address:<<malloc 5>>
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::scanSockets.address:"1024"
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::getSocketState.i:0
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::getSocketState.return:3
TEST.END

-- Test Case: (cl)CSoAdTcp::scanSockets.default
TEST.UNIT:infra_comm_doip_soad
TEST.SUBPROGRAM:(cl)CSoAdTcp::scanSockets
TEST.NEW
TEST.NAME:(cl)CSoAdTcp::scanSockets.default
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdTcp::getSocketState
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdUdp::scanSockets
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.<<constructor>>.CSoAdTcp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdUdp.CSoAdUdp.<<constructor>>.CSoAdUdp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::scanSockets.vlanNo:1
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::scanSockets.i:0
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::scanSockets.portNum:1
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::scanSockets.address:<<malloc 5>>
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::scanSockets.address:"1024"
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::getSocketState.i:0
TEST.END

-- Subprogram: (cl)CSoAdTcp::sendIpMessage

-- Test Case: (cl)CSoAdTcp::sendIpMessage.001
TEST.UNIT:infra_comm_doip_soad
TEST.SUBPROGRAM:(cl)CSoAdTcp::sendIpMessage
TEST.NEW
TEST.NAME:(cl)CSoAdTcp::sendIpMessage.001
TEST.VALUE:uut_prototype_stubs.send.return:1
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.<<constructor>>.CSoAdTcp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.connectionHandle:<<malloc 2>>
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.connectionHandle[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.connectionHandle[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.socketProtocolIsTcp:<<malloc 2>>
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.socketProtocolIsTcp[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.socketProtocolIsTcp[1]:true
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.socketProtocolIsTcp[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdUdp.CSoAdUdp.<<constructor>>.CSoAdUdp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::sendIpMessage.socketId:1
TEST.END

-- Test Case: (cl)CSoAdTcp::sendIpMessage.002
TEST.UNIT:infra_comm_doip_soad
TEST.SUBPROGRAM:(cl)CSoAdTcp::sendIpMessage
TEST.NEW
TEST.NAME:(cl)CSoAdTcp::sendIpMessage.002
TEST.VALUE:uut_prototype_stubs.send.return:1
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.<<constructor>>.CSoAdTcp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.connectionHandle:<<malloc 2>>
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.connectionHandle[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.connectionHandle[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.socketProtocolIsTcp:<<malloc 2>>
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.socketProtocolIsTcp[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.socketProtocolIsTcp[1]:false
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.socketProtocolIsTcp[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdUdp.CSoAdUdp.<<constructor>>.CSoAdUdp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::sendIpMessage.socketId:1
TEST.END

-- Subprogram: (cl)CSoAdTcp::setSoadCallBackIf

-- Test Case: (cl)CSoAdTcp::setSoadCallBackIf.001
TEST.UNIT:infra_comm_doip_soad
TEST.SUBPROGRAM:(cl)CSoAdTcp::setSoadCallBackIf
TEST.NEW
TEST.NAME:(cl)CSoAdTcp::setSoadCallBackIf.001
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.<<constructor>>.CSoAdTcp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdUdp.CSoAdUdp.<<constructor>>.CSoAdUdp().<<call>>:0
TEST.END

-- Subprogram: (cl)CSoAdTcp::setSocketState

-- Test Case: (cl)CSoAdTcp::setSocketState.001
TEST.UNIT:infra_comm_doip_soad
TEST.SUBPROGRAM:(cl)CSoAdTcp::setSocketState
TEST.NEW
TEST.NAME:(cl)CSoAdTcp::setSocketState.001
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.<<constructor>>.CSoAdTcp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.tcpSocketState:<<malloc 1>>
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.tcpSocketState[0]:ESocketState_Uninit
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.tcpSocketState[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.socketHandle:<<malloc 1>>
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.socketHandle[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.connectionHandle:<<malloc 1>>
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.connectionHandle[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::setSocketState.i:0
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::setSocketState.state:ESocketState_Uninit
TEST.END

-- Subprogram: (cl)CSoAdTcp::socketClose

-- Test Case: (cl)CSoAdTcp::socketClose.001
TEST.UNIT:infra_comm_doip_soad
TEST.SUBPROGRAM:(cl)CSoAdTcp::socketClose
TEST.NEW
TEST.NAME:(cl)CSoAdTcp::socketClose.001
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdTcp::setSocketState
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.<<constructor>>.CSoAdTcp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.tcpSocketsOpened:1
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.connectionHandle:<<malloc 2>>
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.connectionHandle[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.connectionHandle[1]:1
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.connectionHandle[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdUdp.CSoAdUdp.<<constructor>>.CSoAdUdp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::socketClose.socketId:1
TEST.END

-- Test Case: (cl)CSoAdTcp::socketClose.002
TEST.UNIT:infra_comm_doip_soad
TEST.SUBPROGRAM:(cl)CSoAdTcp::socketClose
TEST.NEW
TEST.NAME:(cl)CSoAdTcp::socketClose.002
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdTcp::setSocketState
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.<<constructor>>.CSoAdTcp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.tcpSocketsOpened:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.connectionHandle:<<malloc 2>>
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.connectionHandle[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.connectionHandle[1]:1
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.connectionHandle[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdUdp.CSoAdUdp.<<constructor>>.CSoAdUdp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::socketClose.socketId:1
TEST.END

-- Test Case: (cl)CSoAdTcp::socketClose.003
TEST.UNIT:infra_comm_doip_soad
TEST.SUBPROGRAM:(cl)CSoAdTcp::socketClose
TEST.NEW
TEST.NAME:(cl)CSoAdTcp::socketClose.003
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdTcp::setSocketState
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.<<constructor>>.CSoAdTcp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.tcpSocketsOpened:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.connectionHandle:<<malloc 2>>
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.connectionHandle[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.connectionHandle[1]:-1
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.connectionHandle[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdUdp.CSoAdUdp.<<constructor>>.CSoAdUdp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::socketClose.socketId:1
TEST.END

-- Subprogram: (cl)CSoAdTcp::socketCreate

-- Test Case: (cl)CSoAdTcp::socketCreate.001
TEST.UNIT:infra_comm_doip_soad
TEST.SUBPROGRAM:(cl)CSoAdTcp::socketCreate
TEST.NEW
TEST.NAME:(cl)CSoAdTcp::socketCreate.001
TEST.VALUE:uut_prototype_stubs.socket.return:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.<<constructor>>.CSoAdTcp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdUdp.CSoAdUdp.<<constructor>>.CSoAdUdp().<<call>>:0
TEST.END

-- Test Case: (cl)CSoAdTcp::socketCreate.002
TEST.UNIT:infra_comm_doip_soad
TEST.SUBPROGRAM:(cl)CSoAdTcp::socketCreate
TEST.NEW
TEST.NAME:(cl)CSoAdTcp::socketCreate.002
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdTcp::setSocketState
TEST.VALUE:uut_prototype_stubs.socket.return:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.<<constructor>>.CSoAdTcp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.maxTester:1
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.socketHandle:<<malloc 2>>
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.socketHandle[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.socketHandle[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.socketProtocolIsTcp:<<malloc 2>>
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.socketProtocolIsTcp[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.socketProtocolIsTcp[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdUdp.CSoAdUdp.<<constructor>>.CSoAdUdp().<<call>>:0
TEST.END

-- Test Case: (cl)CSoAdTcp::socketCreate.003
TEST.UNIT:infra_comm_doip_soad
TEST.SUBPROGRAM:(cl)CSoAdTcp::socketCreate
TEST.NEW
TEST.NAME:(cl)CSoAdTcp::socketCreate.003
TEST.VALUE:uut_prototype_stubs.listen.return:-1
TEST.VALUE:uut_prototype_stubs.socket.return:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.<<constructor>>.CSoAdTcp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdUdp.CSoAdUdp.<<constructor>>.CSoAdUdp().<<call>>:0
TEST.END

-- Test Case: (cl)CSoAdTcp::socketCreate.004
TEST.UNIT:infra_comm_doip_soad
TEST.SUBPROGRAM:(cl)CSoAdTcp::socketCreate
TEST.NEW
TEST.NAME:(cl)CSoAdTcp::socketCreate.004
TEST.VALUE:uut_prototype_stubs.socket.return:-1
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.<<constructor>>.CSoAdTcp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdUdp.CSoAdUdp.<<constructor>>.CSoAdUdp().<<call>>:0
TEST.END

-- Test Case: (cl)CSoAdTcp::socketCreate.005
TEST.UNIT:infra_comm_doip_soad
TEST.SUBPROGRAM:(cl)CSoAdTcp::socketCreate
TEST.NEW
TEST.NAME:(cl)CSoAdTcp::socketCreate.005
TEST.VALUE:uut_prototype_stubs.bind.return:-1
TEST.VALUE:uut_prototype_stubs.socket.return:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.<<constructor>>.CSoAdTcp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdUdp.CSoAdUdp.<<constructor>>.CSoAdUdp().<<call>>:0
TEST.END

-- Subprogram: (cl)CSoAdTcp::tcpAccepted

-- Test Case: (cl)CSoAdTcp::tcpAccepted.001
TEST.UNIT:infra_comm_doip_soad
TEST.SUBPROGRAM:(cl)CSoAdTcp::tcpAccepted
TEST.NEW
TEST.NAME:(cl)CSoAdTcp::tcpAccepted.001
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdTcp::setSocketState
TEST.VALUE:uut_prototype_stubs.accept.return:1
TEST.VALUE:uut_prototype_stubs.fcntl.return:1
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.<<constructor>>.CSoAdTcp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.socketHandle:<<malloc 2>>
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.socketHandle[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.socketHandle[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.connectionHandle:<<malloc 2>>
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.connectionHandle[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.connectionHandle[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.soadCallback.vcast_concrete_CSoAdCallbackIf.<<constructor>>.vcast_concrete_CSoAdCallbackIf().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::tcpAccepted.socketId:1
TEST.END

-- Test Case: (cl)CSoAdTcp::tcpAccepted.002
TEST.UNIT:infra_comm_doip_soad
TEST.SUBPROGRAM:(cl)CSoAdTcp::tcpAccepted
TEST.NEW
TEST.NAME:(cl)CSoAdTcp::tcpAccepted.002
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdTcp::setSocketState
TEST.VALUE:uut_prototype_stubs.accept.return:-1
TEST.VALUE:uut_prototype_stubs.fcntl.return:-1
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.<<constructor>>.CSoAdTcp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.socketHandle:<<malloc 2>>
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.socketHandle[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.socketHandle[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.connectionHandle:<<malloc 2>>
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.connectionHandle[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.connectionHandle[1]:<<function 1>>
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.soadCallback.vcast_concrete_CSoAdCallbackIf.<<constructor>>.vcast_concrete_CSoAdCallbackIf().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdTcp::tcpAccepted.socketId:1
TEST.END

-- Subprogram: (cl)CSoAdUdp::getClientPort

-- Test Case: (cl)CSoAdUdp::getClientPort.001
TEST.UNIT:infra_comm_doip_soad
TEST.SUBPROGRAM:(cl)CSoAdUdp::getClientPort
TEST.NEW
TEST.NAME:(cl)CSoAdUdp::getClientPort.001
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.<<constructor>>.CSoAdTcp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdUdp.CSoAdUdp.<<constructor>>.CSoAdUdp().<<call>>:0
TEST.END

-- Subprogram: (cl)CSoAdUdp::getSocketState

-- Test Case: (cl)CSoAdUdp::getSocketState.001
TEST.UNIT:infra_comm_doip_soad
TEST.SUBPROGRAM:(cl)CSoAdUdp::getSocketState
TEST.NEW
TEST.NAME:(cl)CSoAdUdp::getSocketState.001
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.<<constructor>>.CSoAdTcp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdUdp.CSoAdUdp.<<constructor>>.CSoAdUdp().<<call>>:0
TEST.END

-- Subprogram: (cl)CSoAdUdp::init

-- Test Case: (cl)CSoAdUdp::init.001
TEST.UNIT:infra_comm_doip_soad
TEST.SUBPROGRAM:(cl)CSoAdUdp::init
TEST.NEW
TEST.NAME:(cl)CSoAdUdp::init.001
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.<<constructor>>.CSoAdTcp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdUdp.CSoAdUdp.<<constructor>>.CSoAdUdp().<<call>>:0
TEST.END

-- Subprogram: (cl)CSoAdUdp::rxIndication

-- Test Case: (cl)CSoAdUdp::rxIndication.001
TEST.UNIT:infra_comm_doip_soad
TEST.SUBPROGRAM:(cl)CSoAdUdp::rxIndication
TEST.NEW
TEST.NAME:(cl)CSoAdUdp::rxIndication.001
TEST.VALUE:uut_prototype_stubs.select.return:-1
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.<<constructor>>.CSoAdTcp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdUdp.CSoAdUdp.<<constructor>>.CSoAdUdp().<<call>>:0
TEST.END

-- Test Case: (cl)CSoAdUdp::rxIndication.002
TEST.UNIT:infra_comm_doip_soad
TEST.SUBPROGRAM:(cl)CSoAdUdp::rxIndication
TEST.NEW
TEST.NAME:(cl)CSoAdUdp::rxIndication.002
TEST.VALUE:uut_prototype_stubs.select.return:-2
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.<<constructor>>.CSoAdTcp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdUdp.CSoAdUdp.<<constructor>>.CSoAdUdp().<<call>>:0
TEST.END

-- Test Case: (cl)CSoAdUdp::rxIndication.003
TEST.UNIT:infra_comm_doip_soad
TEST.SUBPROGRAM:(cl)CSoAdUdp::rxIndication
TEST.NEW
TEST.NAME:(cl)CSoAdUdp::rxIndication.003
TEST.VALUE:uut_prototype_stubs.select.return:-2
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.<<constructor>>.CSoAdTcp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdUdp.CSoAdUdp.<<constructor>>.CSoAdUdp().<<call>>:0
TEST.END

-- Test Case: (cl)CSoAdUdp::rxIndication.004
TEST.UNIT:infra_comm_doip_soad
TEST.SUBPROGRAM:(cl)CSoAdUdp::rxIndication
TEST.NEW
TEST.NAME:(cl)CSoAdUdp::rxIndication.004
TEST.VALUE:uut_prototype_stubs.select.return:1
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.<<constructor>>.CSoAdTcp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdUdp.CSoAdUdp.<<constructor>>.CSoAdUdp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdUdp.CSoAdUdp.udpSocketHandle:32
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdUdp.CSoAdUdp.original_socket.fds_bits[0..1]:1
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdUdp.CSoAdUdp.readfds.fds_bits[0..1]:1
TEST.END

-- Test Case: (cl)CSoAdUdp::rxIndication.recvStringLen
TEST.UNIT:infra_comm_doip_soad
TEST.SUBPROGRAM:(cl)CSoAdUdp::rxIndication
TEST.NEW
TEST.NAME:(cl)CSoAdUdp::rxIndication.recvStringLen
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdUdp::setClientPort
TEST.VALUE:uut_prototype_stubs.recvfrom.return:16#2#
TEST.VALUE:uut_prototype_stubs.select.return:1
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.<<constructor>>.CSoAdTcp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdUdp.CSoAdUdp.<<constructor>>.CSoAdUdp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdUdp.CSoAdUdp.udpSocketHandle:32
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdUdp.CSoAdUdp.original_socket.fds_bits[0..1]:1
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdUdp.CSoAdUdp.readfds.fds_bits[0..1]:1
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdUdp.CSoAdUdp.soadCallbackUdp.vcast_concrete_CSoAdCallbackIf.<<constructor>>.vcast_concrete_CSoAdCallbackIf().<<call>>:0
TEST.END

-- Subprogram: (cl)CSoAdUdp::scanSockets

-- Test Case: (cl)CSoAdUdp::scanSockets.ESocketStateUdp_Init
TEST.UNIT:infra_comm_doip_soad
TEST.SUBPROGRAM:(cl)CSoAdUdp::scanSockets
TEST.NEW
TEST.NAME:(cl)CSoAdUdp::scanSockets.ESocketStateUdp_Init
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdUdp::getSocketState
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.<<constructor>>.CSoAdTcp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdUdp.CSoAdUdp.<<constructor>>.CSoAdUdp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdUdp::scanSockets.portNum:1
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdUdp::getSocketState.return:1
TEST.END

-- Test Case: (cl)CSoAdUdp::scanSockets.ESocketStateUdp_Ready
TEST.UNIT:infra_comm_doip_soad
TEST.SUBPROGRAM:(cl)CSoAdUdp::scanSockets
TEST.NEW
TEST.NAME:(cl)CSoAdUdp::scanSockets.ESocketStateUdp_Ready
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdUdp::getSocketState
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.<<constructor>>.CSoAdTcp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdUdp.CSoAdUdp.<<constructor>>.CSoAdUdp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdUdp::scanSockets.portNum:1
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdUdp::getSocketState.return:2
TEST.END

-- Test Case: (cl)CSoAdUdp::scanSockets.default
TEST.UNIT:infra_comm_doip_soad
TEST.SUBPROGRAM:(cl)CSoAdUdp::scanSockets
TEST.NEW
TEST.NAME:(cl)CSoAdUdp::scanSockets.default
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdUdp::getSocketState
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.<<constructor>>.CSoAdTcp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdUdp.CSoAdUdp.<<constructor>>.CSoAdUdp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdUdp::scanSockets.portNum:1
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdUdp::getSocketState.return:0
TEST.END

-- Subprogram: (cl)CSoAdUdp::sendMessage

-- Test Case: (cl)CSoAdUdp::sendMessage.001
TEST.UNIT:infra_comm_doip_soad
TEST.SUBPROGRAM:(cl)CSoAdUdp::sendMessage
TEST.NEW
TEST.NAME:(cl)CSoAdUdp::sendMessage.001
TEST.VALUE:uut_prototype_stubs.sendto.return:2
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.<<constructor>>.CSoAdTcp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdUdp.CSoAdUdp.<<constructor>>.CSoAdUdp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdUdp::sendMessage.buff:<<malloc 1>>
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdUdp::sendMessage.buff[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdUdp::sendMessage.clientAddr:<<malloc 1>>
TEST.END

-- Test Case: (cl)CSoAdUdp::sendMessage.002
TEST.UNIT:infra_comm_doip_soad
TEST.SUBPROGRAM:(cl)CSoAdUdp::sendMessage
TEST.NEW
TEST.NAME:(cl)CSoAdUdp::sendMessage.002
TEST.VALUE:uut_prototype_stubs.sendto.return:1
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.<<constructor>>.CSoAdTcp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdUdp.CSoAdUdp.<<constructor>>.CSoAdUdp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdUdp::sendMessage.buff:<<malloc 1>>
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdUdp::sendMessage.buff[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdUdp::sendMessage.clientAddr:<<malloc 1>>
TEST.END

-- Test Case: (cl)CSoAdUdp::sendMessage.003
TEST.UNIT:infra_comm_doip_soad
TEST.SUBPROGRAM:(cl)CSoAdUdp::sendMessage
TEST.NEW
TEST.NAME:(cl)CSoAdUdp::sendMessage.003
TEST.VALUE:uut_prototype_stubs.sendto.return:1
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.<<constructor>>.CSoAdTcp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdUdp.CSoAdUdp.<<constructor>>.CSoAdUdp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdUdp::sendMessage.buff:<<malloc 1>>
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdUdp::sendMessage.buff[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdUdp::sendMessage.clientAddr:<<null>>
TEST.END

-- Test Case: (cl)CSoAdUdp::sendMessage.004
TEST.UNIT:infra_comm_doip_soad
TEST.SUBPROGRAM:(cl)CSoAdUdp::sendMessage
TEST.NEW
TEST.NAME:(cl)CSoAdUdp::sendMessage.004
TEST.VALUE:uut_prototype_stubs.sendto.return:2
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.<<constructor>>.CSoAdTcp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdUdp.CSoAdUdp.<<constructor>>.CSoAdUdp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdUdp::sendMessage.buff:<<malloc 1>>
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdUdp::sendMessage.buff[0]:<<function 1>>
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdUdp::sendMessage.clientAddr:<<null>>
TEST.END

-- Subprogram: (cl)CSoAdUdp::setClientPort

-- Test Case: (cl)CSoAdUdp::setClientPort.001
TEST.UNIT:infra_comm_doip_soad
TEST.SUBPROGRAM:(cl)CSoAdUdp::setClientPort
TEST.NEW
TEST.NAME:(cl)CSoAdUdp::setClientPort.001
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.<<constructor>>.CSoAdTcp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdUdp.CSoAdUdp.<<constructor>>.CSoAdUdp().<<call>>:0
TEST.END

-- Subprogram: (cl)CSoAdUdp::setSoadCallBackIf

-- Test Case: (cl)CSoAdUdp::setSoadCallBackIf.001
TEST.UNIT:infra_comm_doip_soad
TEST.SUBPROGRAM:(cl)CSoAdUdp::setSoadCallBackIf
TEST.NEW
TEST.NAME:(cl)CSoAdUdp::setSoadCallBackIf.001
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.<<constructor>>.CSoAdTcp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdUdp.CSoAdUdp.<<constructor>>.CSoAdUdp().<<call>>:0
TEST.END

-- Subprogram: (cl)CSoAdUdp::setSocketState

-- Test Case: (cl)CSoAdUdp::setSocketState.001
TEST.UNIT:infra_comm_doip_soad
TEST.SUBPROGRAM:(cl)CSoAdUdp::setSocketState
TEST.NEW
TEST.NAME:(cl)CSoAdUdp::setSocketState.001
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdUdp.CSoAdUdp.<<constructor>>.CSoAdUdp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdUdp.CSoAdUdp.udpSocketState:ESocketStateUdp_Uninit
TEST.VALUE:infra_comm_doip_soad.(cl)CSoAdUdp::setSocketState.state:ESocketStateUdp_Uninit
TEST.END

-- Subprogram: (cl)CSoAdUdp::socketClose

-- Test Case: (cl)CSoAdUdp::socketClose.001
TEST.UNIT:infra_comm_doip_soad
TEST.SUBPROGRAM:(cl)CSoAdUdp::socketClose
TEST.NEW
TEST.NAME:(cl)CSoAdUdp::socketClose.001
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdTcp::setSocketState
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.<<constructor>>.CSoAdTcp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdUdp.CSoAdUdp.<<constructor>>.CSoAdUdp().<<call>>:0
TEST.END

-- Test Case: (cl)CSoAdUdp::socketClose.002
TEST.UNIT:infra_comm_doip_soad
TEST.SUBPROGRAM:(cl)CSoAdUdp::socketClose
TEST.NEW
TEST.NAME:(cl)CSoAdUdp::socketClose.002
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdTcp::socketClose
TEST.STUB:infra_comm_doip_soad.(cl)CSoAdTcp::setSocketState
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.<<constructor>>.CSoAdTcp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdUdp.CSoAdUdp.<<constructor>>.CSoAdUdp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdUdp.CSoAdUdp.udpSocketHandle:-1
TEST.END

-- Subprogram: (cl)CSoAdUdp::socketCreate

-- Test Case: (cl)CSoAdUdp::socketCreate.001
TEST.UNIT:infra_comm_doip_soad
TEST.SUBPROGRAM:(cl)CSoAdUdp::socketCreate
TEST.NEW
TEST.NAME:(cl)CSoAdUdp::socketCreate.001
TEST.VALUE:uut_prototype_stubs.socket.return:-1
TEST.VALUE:uut_prototype_stubs.getifaddrs.return:-1
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.<<constructor>>.CSoAdTcp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdUdp.CSoAdUdp.<<constructor>>.CSoAdUdp().<<call>>:0
TEST.END

-- Test Case: (cl)CSoAdUdp::socketCreate.002
TEST.UNIT:infra_comm_doip_soad
TEST.SUBPROGRAM:(cl)CSoAdUdp::socketCreate
TEST.NEW
TEST.NAME:(cl)CSoAdUdp::socketCreate.002
TEST.VALUE:uut_prototype_stubs.bind.return:0
TEST.VALUE:uut_prototype_stubs.socket.return:0
TEST.VALUE:uut_prototype_stubs.setsockopt.return:-1
TEST.VALUE:uut_prototype_stubs.getifaddrs.return:-1
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.<<constructor>>.CSoAdTcp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdUdp.CSoAdUdp.<<constructor>>.CSoAdUdp().<<call>>:0
TEST.END

-- Test Case: (cl)CSoAdUdp::socketCreate.003
TEST.UNIT:infra_comm_doip_soad
TEST.SUBPROGRAM:(cl)CSoAdUdp::socketCreate
TEST.NEW
TEST.NAME:(cl)CSoAdUdp::socketCreate.003
TEST.VALUE:uut_prototype_stubs.bind.return:-1
TEST.VALUE:uut_prototype_stubs.socket.return:0
TEST.VALUE:uut_prototype_stubs.setsockopt.return:-1
TEST.VALUE:uut_prototype_stubs.getifaddrs.return:-1
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.<<constructor>>.CSoAdTcp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdUdp.CSoAdUdp.<<constructor>>.CSoAdUdp().<<call>>:0
TEST.END

-- Test Case: (cl)CSoAdUdp::socketCreate.004
TEST.UNIT:infra_comm_doip_soad
TEST.SUBPROGRAM:(cl)CSoAdUdp::socketCreate
TEST.NEW
TEST.NAME:(cl)CSoAdUdp::socketCreate.004
TEST.VALUE:uut_prototype_stubs.bind.return:-1
TEST.VALUE:uut_prototype_stubs.socket.return:0
TEST.VALUE:uut_prototype_stubs.setsockopt.return:-1
TEST.VALUE:uut_prototype_stubs.getifaddrs.return:1
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.<<constructor>>.CSoAdTcp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdUdp.CSoAdUdp.<<constructor>>.CSoAdUdp().<<call>>:0
TEST.END

-- Test Case: (cl)CSoAdUdp::socketCreate.005
TEST.UNIT:infra_comm_doip_soad
TEST.SUBPROGRAM:(cl)CSoAdUdp::socketCreate
TEST.NEW
TEST.NAME:(cl)CSoAdUdp::socketCreate.005
TEST.VALUE:uut_prototype_stubs.socket.return:0
TEST.VALUE:uut_prototype_stubs.getifaddrs.VCAST_PARAM_1[0]:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.getifaddrs.VCAST_PARAM_1[0][0].ifa_next:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.getifaddrs.VCAST_PARAM_1[0][0].ifa_name:<<malloc 6>>
TEST.VALUE:uut_prototype_stubs.getifaddrs.VCAST_PARAM_1[0][0].ifa_name:"vlan0"
TEST.VALUE:uut_prototype_stubs.getifaddrs.VCAST_PARAM_1[0][0].ifa_addr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.getifaddrs.VCAST_PARAM_1[0][0].ifa_addr[0].sa_family:2
TEST.VALUE:uut_prototype_stubs.getifaddrs.return:1
TEST.VALUE:uut_prototype_stubs.freeifaddrs.VCAST_PARAM_1[0].ifa_addr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.freeifaddrs.VCAST_PARAM_1[0].ifa_addr[0].sa_family:1
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.<<constructor>>.CSoAdTcp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdUdp.CSoAdUdp.<<constructor>>.CSoAdUdp().<<call>>:0
TEST.END

-- Test Case: (cl)CSoAdUdp::socketCreate.006
TEST.UNIT:infra_comm_doip_soad
TEST.SUBPROGRAM:(cl)CSoAdUdp::socketCreate
TEST.NEW
TEST.NAME:(cl)CSoAdUdp::socketCreate.006
TEST.VALUE:uut_prototype_stubs.socket.return:0
TEST.VALUE:uut_prototype_stubs.getifaddrs.VCAST_PARAM_1[0]:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.getifaddrs.VCAST_PARAM_1[0][0].ifa_next:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.getifaddrs.VCAST_PARAM_1[0][0].ifa_name:<<malloc 6>>
TEST.VALUE:uut_prototype_stubs.getifaddrs.VCAST_PARAM_1[0][0].ifa_name:"vlan0"
TEST.VALUE:uut_prototype_stubs.getifaddrs.VCAST_PARAM_1[0][0].ifa_addr:<<null>>
TEST.VALUE:uut_prototype_stubs.getifaddrs.return:1
TEST.VALUE:uut_prototype_stubs.freeifaddrs.VCAST_PARAM_1[0].ifa_addr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.freeifaddrs.VCAST_PARAM_1[0].ifa_addr[0].sa_family:1
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.<<constructor>>.CSoAdTcp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdUdp.CSoAdUdp.<<constructor>>.CSoAdUdp().<<call>>:0
TEST.END

-- Test Case: (cl)CSoAdUdp::socketCreate.007
TEST.UNIT:infra_comm_doip_soad
TEST.SUBPROGRAM:(cl)CSoAdUdp::socketCreate
TEST.NEW
TEST.NAME:(cl)CSoAdUdp::socketCreate.007
TEST.VALUE:uut_prototype_stubs.socket.return:0
TEST.VALUE:uut_prototype_stubs.getnameinfo.return:1
TEST.VALUE:uut_prototype_stubs.getifaddrs.VCAST_PARAM_1[0]:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.getifaddrs.VCAST_PARAM_1[0][0].ifa_next:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.getifaddrs.VCAST_PARAM_1[0][0].ifa_name:<<malloc 6>>
TEST.VALUE:uut_prototype_stubs.getifaddrs.VCAST_PARAM_1[0][0].ifa_name:"vlan0"
TEST.VALUE:uut_prototype_stubs.getifaddrs.VCAST_PARAM_1[0][0].ifa_addr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.getifaddrs.VCAST_PARAM_1[0][0].ifa_addr[0].sa_family:2
TEST.VALUE:uut_prototype_stubs.getifaddrs.return:1
TEST.VALUE:uut_prototype_stubs.freeifaddrs.VCAST_PARAM_1[0].ifa_addr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.freeifaddrs.VCAST_PARAM_1[0].ifa_addr[0].sa_family:1
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdTcp.CSoAdTcp.<<constructor>>.CSoAdTcp().<<call>>:0
TEST.VALUE:infra_comm_doip_soad.<<GLOBAL>>.(cl).CSoAdUdp.CSoAdUdp.<<constructor>>.CSoAdUdp().<<call>>:0
TEST.END

-- Unit: infra_comm_doip_timer

-- Subprogram: (cl)CDoIPTimer::ResetTimer

-- Test Case: (cl)CDoIPTimer::ResetTimer.001
TEST.UNIT:infra_comm_doip_timer
TEST.SUBPROGRAM:(cl)CDoIPTimer::ResetTimer
TEST.NEW
TEST.NAME:(cl)CDoIPTimer::ResetTimer.001
TEST.VALUE:infra_comm_doip_timer.<<GLOBAL>>.(cl).CDoIPTimer.CDoIPTimer.<<constructor>>.CDoIPTimer().<<call>>:0
TEST.END

-- Subprogram: (cl)CDoIPTimer::startTimer

-- Test Case: (cl)CDoIPTimer::startTimer.001
TEST.UNIT:infra_comm_doip_timer
TEST.SUBPROGRAM:(cl)CDoIPTimer::startTimer
TEST.NEW
TEST.NAME:(cl)CDoIPTimer::startTimer.001
TEST.VALUE:infra_comm_doip_timer.<<GLOBAL>>.(cl).CDoIPTimer.CDoIPTimer.<<constructor>>.CDoIPTimer().<<call>>:0
TEST.END

-- Test Case: (cl)CDoIPTimer::startTimer.002
TEST.UNIT:infra_comm_doip_timer
TEST.SUBPROGRAM:(cl)CDoIPTimer::startTimer
TEST.NEW
TEST.NAME:(cl)CDoIPTimer::startTimer.002
TEST.VALUE:infra_comm_doip_timer.<<GLOBAL>>.(cl).CDoIPTimer.CDoIPTimer.<<constructor>>.CDoIPTimer().<<call>>:0
TEST.VALUE:infra_comm_doip_timer.<<GLOBAL>>.(cl).CDoIPTimer.CDoIPTimer.mTimerMap:<<malloc 1>>
TEST.VALUE:infra_comm_doip_timer.<<GLOBAL>>.(cl).CDoIPTimer.CDoIPTimer.mTimerMap[0]:<<function 1>>
TEST.END

-- Subprogram: (cl)CDoIPTimer::stopTimer

-- Test Case: (cl)CDoIPTimer::stopTimer.001
TEST.UNIT:infra_comm_doip_timer
TEST.SUBPROGRAM:(cl)CDoIPTimer::stopTimer
TEST.NEW
TEST.NAME:(cl)CDoIPTimer::stopTimer.001
TEST.VALUE:infra_comm_doip_timer.<<GLOBAL>>.(cl).CDoIPTimer.CDoIPTimer.<<constructor>>.CDoIPTimer().<<call>>:0
TEST.VALUE:infra_comm_doip_timer.<<GLOBAL>>.(cl).CDoIPTimer.CDoIPTimer.mTimerMap:<<malloc 1>>
TEST.VALUE:infra_comm_doip_timer.<<GLOBAL>>.(cl).CDoIPTimer.CDoIPTimer.mTimerMap[0]:<<function 1>>
TEST.END

-- Subprogram: (cl)CDoIPTimer::timerBaseTickTask

-- Test Case: (cl)CDoIPTimer::timerBaseTickTask.001
TEST.UNIT:infra_comm_doip_timer
TEST.SUBPROGRAM:(cl)CDoIPTimer::timerBaseTickTask
TEST.NEW
TEST.NAME:(cl)CDoIPTimer::timerBaseTickTask.001
TEST.VALUE:infra_comm_doip_timer.<<GLOBAL>>.(cl).CDoIPTimer.CDoIPTimer.<<constructor>>.CDoIPTimer().<<call>>:0
TEST.VALUE_USER_CODE:<<CDoIPTimer instance>>.CDoIPTimer.mTimerMap
<<CDoIPTimer instance>>->mTimerMap[0] = {1};
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: (cl)CDoIPTimer::timerBaseTickTask.002
TEST.UNIT:infra_comm_doip_timer
TEST.SUBPROGRAM:(cl)CDoIPTimer::timerBaseTickTask
TEST.NEW
TEST.NAME:(cl)CDoIPTimer::timerBaseTickTask.002
TEST.VALUE:infra_comm_doip_timer.<<GLOBAL>>.(cl).CDoIPTimer.CDoIPTimer.<<constructor>>.CDoIPTimer().<<call>>:0
TEST.VALUE_USER_CODE:<<CDoIPTimer instance>>.CDoIPTimer.mTimerMap
<<CDoIPTimer instance>>->mTimerMap[0] = {2};
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: (cl)CDoIPTimer::timerBaseTickTask.003
TEST.UNIT:infra_comm_doip_timer
TEST.SUBPROGRAM:(cl)CDoIPTimer::timerBaseTickTask
TEST.NEW
TEST.NAME:(cl)CDoIPTimer::timerBaseTickTask.003
TEST.VALUE:infra_comm_doip_timer.<<GLOBAL>>.(cl).CDoIPTimer.CDoIPTimer.<<constructor>>.CDoIPTimer().<<call>>:0
TEST.VALUE:infra_comm_doip_timer.<<GLOBAL>>.(cl).CDoIPTimer.CDoIPTimer.mTimerMap:<<malloc 1>>
TEST.VALUE:infra_comm_doip_timer.<<GLOBAL>>.(cl).CDoIPTimer.CDoIPTimer.mTimerMap[0]:<<function 1>>
TEST.END
