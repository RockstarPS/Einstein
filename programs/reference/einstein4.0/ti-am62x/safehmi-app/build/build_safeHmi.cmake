#---------------------------------------------------------------------------------------------------------------------
#
# VISTEON CORPORATION CONFIDENTIAL
# ________________________________
#
# [2022] Visteon Corporation
# All Rights Reserved.
#
# NOTICE: This is an unpublished work of authorship, which contains trade secrets.
# Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
# its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
# or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
# in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
# under all copyright laws to protect this work as a published work, when appropriate.
# Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
# without the written authorization of Visteon Corporation.
#
#---------------------------------------------------------------------------------------------------------------------

cmake_minimum_required (VERSION 3.14)

# Create Binary - at the end both names would be safeHmi.exe
#if(CMAKE_SYSTEM_NAME MATCHES __LINUX__)
if(CMAKE_SYSTEM_PROCESSOR STREQUAL aarch64)
set(BINARY_NAME safeHmi)   
elseif(CMAKE_SYSTEM_PROCESSOR STREQUAL X86)
set(BINARY_NAME safeHmi.exe)
set(SHMI_VSM "ON" CACHE STRING "Set VSM ON/OFF")
else()   
set(BINARY_NAME safeHmi)    
set(SHMI_VSM "ON" CACHE STRING "Set VSM ON/OFF")
#endif(CMAKE_SYSTEM_NAME MATCHES __LINUX__) 
endif(CMAKE_SYSTEM_PROCESSOR STREQUAL aarch64)


set(SHMI_PATH "${CMAKE_CURRENT_LIST_DIR}/../../ui-core/safehmi" CACHE STRING "safehmi Core package path")


AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_LIST_DIR}/../autogen/shmi src)
set(src ${src} ${CMAKE_CURRENT_SOURCE_DIR}/../source/common/shmi_component.cpp)
# set(src ${src} ${CMAKE_CURRENT_SOURCE_DIR}/../source/common/safeHmiWidgetsUpdater.cpp)
# set(src ${src} ${CMAKE_CURRENT_SOURCE_DIR}/../source/common/TelltaleHandler.cpp)
set(src ${src} ${CMAKE_CURRENT_SOURCE_DIR}/../source/common/main.cpp)
set(src ${src} ${CMAKE_CURRENT_SOURCE_DIR}/../source/common/safe_hmi.cpp)
#set(src ${src} ${CMAKE_CURRENT_SOURCE_DIR}/../source/common/VSMInterfaceInst.cpp)
#if(CMAKE_SYSTEM_NAME MATCHES __LINUX__)
if(CMAKE_SYSTEM_PROCESSOR STREQUAL aarch64)
#set(src ${src} ${CMAKE_CURRENT_SOURCE_DIR}/../source/common/vsm_update.cpp)

#set(src ${src} ${CMAKE_CURRENT_SOURCE_DIR}/../source/common/shmi_e2e.cpp)
#endif(CMAKE_SYSTEM_NAME MATCHES __LINUX__) 
endif(CMAKE_SYSTEM_PROCESSOR STREQUAL aarch64)

add_executable(${BINARY_NAME}  ${src})




include_directories("$ENV{SDKTARGETSYSROOT}/usr/include/drm")
# Add shared header folders
target_include_directories(${BINARY_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../source/windows
    ${CMAKE_CURRENT_SOURCE_DIR}/../source/common
    ${CMAKE_CURRENT_SOURCE_DIR}/../autogen/shmi
    #${CMAKE_CURRENT_SOURCE_DIR}/../autogen/vsm
    ${SHMI_PATH}/vsm/release/include/
    #if(CMAKE_SYSTEM_NAME MATCHES __LINUX__)
	if(CMAKE_SYSTEM_PROCESSOR STREQUAL aarch64)
  
    #endif(CMAKE_SYSTEM_NAME MATCHES __LINUX__) 
	endif(CMAKE_SYSTEM_PROCESSOR STREQUAL aarch64)
    ${SHMI_PATH}/safehmi_engine/release/include/drm
    ${SHMI_PATH}/safehmi_engine/release/include/common
    ${SHMI_PATH}/safehmi_engine/release/include/player
    #if(CMAKE_SYSTEM_NAME MATCHES __LINUX__)
	if(CMAKE_SYSTEM_PROCESSOR STREQUAL aarch64)
 
    ${SHMI_PATH}/vsm/release/lib/
    #endif(CMAKE_SYSTEM_NAME MATCHES __LINUX__) 
	endif(CMAKE_SYSTEM_PROCESSOR STREQUAL aarch64)
    ${GP_RTE_DIR}/gip/src/common
    #${GP_RTE_DIR}/gip/src/applications/safeHmi_app
    ${SHMI_PATH}/safehmi_engine/third_party/pvrsdk/include
    ${SHMI_PATH}/../../../../../../cluster-platform/dijkstra/tools/kpi/boot-kpi/ti_am62x/include/
    ${SHMI_PATH}/../../../../../../programs/reference/einstein4.0/ti-am62x/img-build/boot_kpi
    #${SHMI_PATH}/../../../../cluster-platform/dijkstra/libraries/e2e/lib/public
    #${SHMI_PATH}/../../../../cluster-platform/dijkstra/libraries/crc/lib/public
)


#if(CMAKE_SYSTEM_NAME MATCHES __LINUX__)
if(CMAKE_SYSTEM_PROCESSOR STREQUAL aarch64)

    target_add_dependencies(${BINARY_NAME}
        PRIVATE
        dk_logger
        dk_runtime
        dk_wdg_client
        #e2e
        #crc
		#bspal_sigunit
        
    )

    target_compile_definitions(${BINARY_NAME}
        PUBLIC
        BOOT_KPI_LOG_EN
    )
    # common compile definitions
    add_definitions(-DUSE_VSM)
    
	if(CMAKE_BUILD_TYPE STREQUAL "debug")
		set(SHMI_LIB_PATH "${SHMI_PATH}/safehmi_engine/release/lib/Linux/aarch64/drm/Debug/libuxsafehmi.a")
		set(STATIC_LIBS ${STATIC_LIBS} drm rt)	
        set(VSM_LIB_PATH "${SHMI_PATH}/vsm/release/lib/qnx700/aarch64/Debug/libhmi_vsm.a")
        
		
	else()
		set(SHMI_LIB_PATH "${SHMI_PATH}/safehmi_engine/release/lib/Linux/aarch64/drm/Release/libuxsafehmi.a")
		set(STATIC_LIBS ${STATIC_LIBS} drm rt)
        set(VSM_LIB_PATH "${SHMI_PATH}/vsm/release/lib/qnx700/aarch64/Release/libhmi_vsm.a")
	endif(CMAKE_BUILD_TYPE STREQUAL "debug")

    target_link_libraries(${BINARY_NAME}
        PRIVATE
        c
        ${SHMI_LIB_PATH}
	${STATIC_LIBS}
        ${VSM_LIB_PATH}
        ${SHARED_LIBS}
        #${BSPAL_LIB_PATH}
   )
elseif (CMAKE_SYSTEM_NAME STREQUAL Windows)  
target_add_dependencies(${BINARY_NAME}
        PRIVATE
        dk_logger
        dk_runtime.a
        #e2e
        #crc
		)
		set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:CONSOLE")

	    target_link_libraries(${BINARY_NAME}
        PRIVATE
        ${SHMI_PATH}/safehmi_engine/third_party/pvrframe/Windows_x86_32/libEGL.lib
        ${SHMI_PATH}/safehmi_engine/third_party/pvrframe/Windows_x86_32/libGLESv2.lib
        ${SHMI_PATH}/safehmi_engine/release/lib/vs2015/x86/${CMAKE_BUILD_TYPE}/uxsafehmi.lib
		)
else()

      if(PROJECT_VAR STREQUAL SU2IPE_SIM) 
    target_add_dependencies(${BINARY_NAME}
        PRIVATE
        dk_logger
        dk_runtime.a
        #e2e
        #crc
    )

    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:CONSOLE")

    target_link_libraries(${BINARY_NAME}
        PRIVATE
		mq
		screen
		c
        
		${SHMI_PATH}/safehmi_engine/release/lib/qnx700/x86_64/Release/libuxsafehmi.a
    )
	endif()

#endif(CMAKE_SYSTEM_NAME MATCHES __LINUX__) 
endif(CMAKE_SYSTEM_PROCESSOR STREQUAL aarch64)



# Install the binary
#install(TARGETS ${BINARY_NAME}
#    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
#)

#f(CMAKE_SYSTEM_NAME STREQUAL Windows)
if(PROJECT_VAR STREQUAL SU2IPE_SIM) 
	install(FILES   "${SHMI_PATH}/safehmi_engine/third_party/pvrframe/Windows_x86_32/libEGL.dll"
	                "${SHMI_PATH}/safehmi_engine/third_party/pvrframe/Windows_x86_32/libGLESv2.dll"
	                DESTINATION ${CMAKE_INSTALL_BINDIR}
	                COMPONENT dll  
	                PERMISSIONS OWNER_READ OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE)
					
elseif(CMAKE_SYSTEM_NAME STREQUAL Windows)
	 install(FILES   "${SHMI_PATH}/safehmi_engine/third_party/pvrframe/Windows_x86_32/libEGL.dll"
	                 "${SHMI_PATH}/safehmi_engine/third_party/pvrframe/Windows_x86_32/libGLESv2.dll"
	                 DESTINATION ${CMAKE_INSTALL_BINDIR}
	                 COMPONENT dll  
	                 PERMISSIONS OWNER_READ OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE)
endif(PROJECT_VAR STREQUAL SU2IPE_SIM) 
#endif(CMAKE_SYSTEM_NAME STREQUAL Windows)
