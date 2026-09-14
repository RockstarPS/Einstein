cmake_minimum_required(VERSION 3.1)

message([STATUS] "CMake Start" ...)
project(uxsafehmi_app)
set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_LIST_DIR}/Install/${CMAKE_SYSTEM_NAME}")
set(CMAKE_C_USE_RESPONSE_FILE_FOR_OBJECTS OFF)
set(CMAKE_CXX_USE_RESPONSE_FILE_FOR_OBJECTS OFF)
set(CMAKE_SKIP_RPATH true)
set(SHMI_PATH "${CMAKE_CURRENT_LIST_DIR}\.\\..\\..\\..\\" CACHE STRING "safeHMI path")
string(REPLACE "\\" "/" SHMI_PATH ${SHMI_PATH})
if(CMAKE_SYSTEM_NAME STREQUAL "QNX")
  set(SHMI_VSM "ON" CACHE STRING "Set VSM ON/OFF")
endif(CMAKE_SYSTEM_NAME STREQUAL "QNX")
set(SHMI_VMF "OFF" CACHE STRING "Set VMF ON/OFF")

# common compile definitions
add_definitions(-DUNICODE)
add_compile_options("$<$<CONFIG:DEBUG>:-DSHMI_DEBUG>")
if(SHMI_VMF STREQUAL "ON")
  add_definitions(-DUSE_VMF)
endif(SHMI_VMF STREQUAL "ON")
if(SHMI_VSM STREQUAL "ON")
  add_definitions(-DUSE_VSM)
endif(SHMI_VSM STREQUAL "ON")

if(PROCESSOR STREQUAL "qualcomm")
	add_definitions(-DQUALCOMM_MISR)
	AUX_SOURCE_DIRECTORY(${SHMI_PATH}/example/autogen_qualcomm/autogen/shmi src)
	include_directories ("${SHMI_PATH}/example/autogen_qualcomm/autogen/shmi")
elseif(PROCESSOR STREQUAL "")
	AUX_SOURCE_DIRECTORY(${SHMI_PATH}/example/autogen_imx8/autogen/shmi src)
	include_directories ("${SHMI_PATH}/example/autogen_imx8/autogen/shmi")
endif(PROCESSOR STREQUAL "qualcomm")	
# common source directories

# common include directories
include_directories ("${SHMI_PATH}/safehmi_engine/release/include/player")

# common link directories

# common linker flags

	
# Assign static and shared libs
 if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
	set(STATIC_LIBS libEGL libGLESv2 uxsafehmi)
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:CONSOLE")
	set(src ${src} ${SHMI_PATH}/example/windows/main.cpp)
	include_directories ("${SHMI_PATH}/example/windows")
	include_directories ("${SHMI_PATH}/safehmi_engine/release/include/common")
	include_directories ("${SHMI_PATH}/safehmi_engine/third_party/pvrsdk/include")
	if(CMAKE_VS_PLATFORM_NAME STREQUAL "Win32")
		link_directories ("${SHMI_PATH}/safehmi_engine/third_party/pvrframe/Windows_x86_32")
		link_directories ("${SHMI_PATH}/safehmi_engine/release/lib/vs2019/x86/$(ConfigurationName)/")
	else()
		link_directories ("${SHMI_PATH}/safehmi_engine/third_party/pvrframe/Windows_x86_64")
		link_directories ("${SHMI_PATH}/safehmi_engine/release/lib/vs2019/x64/$(ConfigurationName)/")
	endif()
	if(SHMI_VMF STREQUAL "ON")
		set(src ${src} ${SHMI_PATH}/example/vmf/sample/vmf_com.cpp)
		set(SHARED_LIBS ${SHARED_LIBS} libvmf_client libvmf_trace)
		link_directories ("${SHMI_PATH}/example/vmf/${CMAKE_VS_PLATFORM_NAME}/libs/")
		include_directories ("${SHMI_PATH}/example/vmf/${CMAKE_VS_PLATFORM_NAME}/include")
		include_directories ("${SHMI_PATH}/example/vmf/sample/")
	endif(SHMI_VMF STREQUAL "ON")	
	message([STATUS] "Windows Build" ...)
elseif(CMAKE_SYSTEM_NAME STREQUAL "QNX")
	set(src ${src} ${SHMI_PATH}/example/qnx/shmi_app.cpp)
	set(SHARED_LIBS screen mq socket c)
	set(STATIC_LIBS uxsafehmi)
	set(CPP_FLAGS -c -Wall -fpermissive)
	include_directories ("${SHMI_PATH}/safehmi_engine/release/include/qnx")
	include_directories ("${SHMI_PATH}/example/qnx/")
	link_directories ("${SHMI_PATH}/safehmi_engine/release/lib/qnx${CMAKE_SYSTEM_VERSION}/${CMAKE_SYSTEM_PROCESSOR}/${CMAKE_BUILD_TYPE}")
	if(SHMI_VMF STREQUAL "ON")
		set(src ${src} ${SHMI_PATH}/example/vmf/sample/vmf_com.cpp)
		set(STATIC_LIBS ${STATIC_LIBS} vmf_client vmf_trace)
		link_directories ("${SHMI_PATH}/example/vmf/${CMAKE_SYSTEM_PROCESSOR}/libs/")
		include_directories ("${SHMI_PATH}/example/vmf/${CMAKE_SYSTEM_PROCESSOR}/include")
		include_directories ("${SHMI_PATH}/example/vmf/sample/")
	endif(SHMI_VMF STREQUAL "ON")
	if(SHMI_VSM STREQUAL "ON")
		set(src ${src} ${SHMI_PATH}/example/qnx/vsm_ftp.cpp)
		set(STATIC_LIBS ${STATIC_LIBS} hmi_vsm)
		if(PROCESSOR STREQUAL "qualcomm")
		    set(SHARED_LIBS ${SHARED_LIBS} bspal_misr)
			set(SHARED_LIBS ${SHARED_LIBS} openwfd)
			set(SHARED_LIBS ${SHARED_LIBS} planedef)
			set(SHARED_LIBS ${SHARED_LIBS} OSAbstraction)
			set(SHARED_LIBS ${SHARED_LIBS} fdt_utils)
			set(SHARED_LIBS ${SHARED_LIBS} libstd)
			link_directories ("${SHMI_PATH}/vsm/release/lib/qnx${CMAKE_SYSTEM_VERSION}/${CMAKE_SYSTEM_PROCESSOR}_${PROCESSOR}/debug")
			link_directories ("${SHMI_PATH}/example/stubs/osbsp_misr")
			include_directories ("${SHMI_PATH}/example/autogen_qualcomm/autogen/vsm")
		elseif(PROCESSOR STREQUAL "")
			set(SHARED_LIBS ${SHARED_LIBS} bspal_sigunit)
			link_directories ("${SHMI_PATH}/vsm/release/lib/qnx${CMAKE_SYSTEM_VERSION}/${CMAKE_SYSTEM_PROCESSOR}/debug")
			link_directories ("${SHMI_PATH}/example/stubs/osbsp")
			include_directories ("${SHMI_PATH}/example/autogen_imx8/autogen/vsm")
		endif(PROCESSOR STREQUAL "qualcomm")
		#link_directories ("${SHMI_PATH}/vsm/release/lib/qnx${CMAKE_SYSTEM_VERSION}/${CMAKE_SYSTEM_PROCESSOR}/${CMAKE_BUILD_TYPE}")
		link_directories ("${SHMI_PATH}/vsm/release/lib/qnx${CMAKE_SYSTEM_VERSION}/${CMAKE_SYSTEM_PROCESSOR}/debug")		
		include_directories ("${SHMI_PATH}/vsm/release/include")		
endif(SHMI_VSM STREQUAL "ON")
endif(CMAKE_SYSTEM_NAME STREQUAL "Windows")


add_definitions(${CPP_FLAGS})

add_executable( uxsafehmi_app ${src})


#target_link_libraries()

target_link_libraries(uxsafehmi_app ${STATIC_LIBS} ${SHARED_LIBS} )


# common installs

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
	if(CMAKE_VS_PLATFORM_NAME STREQUAL "Win32")
		install(FILES   "${SHMI_PATH}/safehmi_engine/third_party/pvrframe/Windows_x86_32/libEGL.dll"
			"${SHMI_PATH}/safehmi_engine/third_party/pvrframe/Windows_x86_32/libGLESv2.dll"
			DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/$<CONFIGURATION>/
			COMPONENT dll  
			PERMISSIONS OWNER_READ OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE)
	else()
		install(FILES   "${SHMI_PATH}/safehmi_engine/third_party/pvrframe/Windows_x86_64/libEGL.dll"
			"${SHMI_PATH}/safehmi_engine/third_party/pvrframe/Windows_x86_64/libGLESv2.dll"
			DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/$<CONFIGURATION>/
			COMPONENT dll  
			PERMISSIONS OWNER_READ OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE)
	endif()
elseif(CMAKE_SYSTEM_NAME STREQUAL "QNX")
	install(TARGETS  uxsafehmi_app
		DESTINATION  "${SHMI_PATH}/build/qnx${CMAKE_SYSTEM_VERSION}/${CMAKE_SYSTEM_PROCESSOR}/${CMAKE_BUILD_TYPE}"
		COMPONENT executables
		PERMISSIONS OWNER_READ OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE)
endif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
message([STATUS] "CMake Completed" ...)