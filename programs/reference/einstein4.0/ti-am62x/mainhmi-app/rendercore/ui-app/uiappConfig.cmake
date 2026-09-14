cmake_minimum_required (VERSION 3.14)

#set(GUI_PROFILING ON)
set(GUI_PROFILING OFF)
# set(CMAKE_BUILD_TYPE debug)
if(CMAKE_BUILD_TYPE STREQUAL "debug")	
     add_definitions(-DRC_DEBUG_MSG)
endif(CMAKE_BUILD_TYPE STREQUAL "debug")

set(BINARY_NAME mainHmi)
set(RENDERCORE_PATH "${CMAKE_CURRENT_LIST_DIR}/../../../mainhmi-app/rendercore" CACHE STRING "Rendercore path") 
string(REPLACE "\\" "/" RENDERCORE_PATH ${RENDERCORE_PATH})



if(RHAPSODY_ANIMATION_MAINHMI)
    set(yugenSourceDirMainHmi "src_animation")
else ()
    set(yugenSourceDirMainHmi "src")
endif(RHAPSODY_ANIMATION_MAINHMI)

# common compile definitions
add_definitions(-DGLM_FORCE_PURE)
add_definitions(-DGLM_FORCE_CXX98)
add_definitions(-DRC_PROFILE)
add_definitions(-DRC_MTHREADS=3)
add_definitions(-DGLES3_RENDERER=30)
add_definitions(-DGLES_VERSION=30)
add_definitions(-DYG_DATA_ACCESS_H_API=)

add_definitions(-DBOOT_KPI_LOG_EN)

# common source directories
AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_LIST_DIR}/../rdf_cpp src)
# AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_LIST_DIR}/../rdf_cpp/scripts rdf_cpp_scripts_src)
 
#include subdirectories of parent directory for include path
MACRO(INCLUDE_SUBDIRS parentdir)
  FILE(GLOB children RELATIVE ${parentdir} ${parentdir}/*)
  FOREACH(child ${children})
    IF(IS_DIRECTORY ${parentdir}/${child})
      set(incdir ${incdir} "${parentdir}/${child}")
    ENDIF()
  ENDFOREACH()
ENDMACRO()



# When Windows is configured with case sensitve paths having ../ in paths is causing strange problems
# Thus the below is to take an absolute path for the folders that are configured as case-sensitive
get_filename_component(absolutePathToMain "${CMAKE_CURRENT_LIST_DIR}/.." ABSOLUTE)
message("***Absolute path to mainHmi: ${absolutePathToMain}")


set(incdir ${incdir} "${RENDERCORE_PATH}/include/logs/production")
set(incdir ${incdir} "${RENDERCORE_PATH}/include")
set(incdir ${incdir} "${RENDERCORE_PATH}/include/glm")
set(incdir ${incdir} "${RENDERCORE_PATH}/include/tinygltf")
set(incdir ${incdir} "${RENDERCORE_PATH}/include/leveraged")
set(incdir ${incdir} "${RENDERCORE_PATH}/include/ffmpeg")
set(incdir ${incdir} "${RENDERCORE_PATH}/include/platform/common")
set(incdir ${incdir} "${RENDERCORE_PATH}/include/monotype/2dtxt_app_layer")
set(incdir ${incdir} "${RENDERCORE_PATH}/include/pvrsdk/include")
set(incdir ${incdir} "${RENDERCORE_PATH}/platform_support/common")
set(incdir ${incdir} "${absolutePathToMain}/rdf_cpp")
set(incdir ${incdir} "${absolutePathToMain}/rdf_cpp/scripts")
set(incdir ${incdir} "${CMAKE_CURRENT_LIST_DIR}/includes")
include_directories("$ENV{SDKTARGETSYSROOT}/usr/include/drm") 

# Assign static and shared libs

if(CMAKE_SYSTEM_NAME MATCHES Linux)

    set(incdir ${incdir} "${RENDERCORE_PATH}/platform_support/drm")
    set(CPP_FLAGS -O2 -fpermissive -Wall -Wno-unused-variable)  
    set(STATIC_LIBS  rendercore_mtype wtlestatic iTypestatic harfbuzz turbojpeg png sicuuc z zstd unibreak osal dk_logger osal dk_runtime)
    set(SHARED_LIBS  GLESv2 EGL)

    set(src ${src} ${CMAKE_CURRENT_LIST_DIR}/Linux/rcore_engine_app.cpp)
    set(src ${src} ${CMAKE_CURRENT_LIST_DIR}/ResourceLoader/ResourceLoader.cpp)
    set(src ${src} ${RENDERCORE_PATH}/platform_support/drm/rc_application_window.cpp)
    set(src ${src} ${RENDERCORE_PATH}/platform_support/drm/rc_platform_fio.cpp)
    set(src ${src} ${RENDERCORE_PATH}/platform_support/common/rc_app_platform_cfg.h)
    set(src ${src} ${RENDERCORE_PATH}/platform_support/common/rc_video_player.cpp)
    set(src ${src} ${RENDERCORE_PATH}/platform_support/drm/rc_platform_dirtex.cpp)    
    set(linkdir ${linkdir} "${RENDERCORE_PATH}/lib/linux/Release")
    set(linkdir ${linkdir} "${RENDERCORE_PATH}/lib/linux/")
	

    set(linkdir ${linkdir} "${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/out/GP_LINUX/EINSTEIN_4_0_A0/release/GP_BUILD/lib") 
else()
#windows
endif(CMAKE_SYSTEM_NAME MATCHES Linux) 

##########################################################################################################################################
##                 DK.CONFIG SECTION
##  NOTE: ORIGINALLY IS PRESENT IN THE YUGEN SECTION
##########################################################################################################################################
file(GLOB_RECURSE DIJKSTRAJ_MAIN_SRCS ${CMAKE_CURRENT_LIST_DIR}/../ui-app/ui.app.dk.config/dk.app/hmi_app/*.cpp)
file(GLOB_RECURSE DIJKSTRAJ_CMP_SRCS ${CMAKE_CURRENT_LIST_DIR}/../ui-app/ui.app.dk.config/dk.components/mainhmi_components/*.cpp)
# file(GLOB_RECURSE DIJKSTRAJ_CMP_SRCS2 ${CMAKE_CURRENT_LIST_DIR}/ui.app.dk.config/dm_sender/*.cpp)
set(src ${src} ${DIJKSTRAJ_MAIN_SRCS} ${DIJKSTRAJ_CMP_SRCS})

###########################################################################################################################################
#   AUTO SEARCH DK.CONFIG Includes
###########################################################################################################################################
file(GLOB_RECURSE folders LIST_DIRECTORIES true
  RELATIVE ${CMAKE_CURRENT_LIST_DIR}/../ui-app/ui.app.dk.config/dk.components/mainhmi_components "${CMAKE_CURRENT_SOURCE_DIR}/../ui-app/ui.app.dk.config/dk.components/mainhmi_components/hmi_")

foreach(header IN LISTS folders)
  message(">>------->> Add ui.app.dk.config Component ${header}")
  set(incdir ${incdir} "${CMAKE_CURRENT_LIST_DIR}/../ui-app/ui.app.dk.config/dk.components/mainhmi_components/${header}")

endforeach()

###########################################################################################################################################
#   Manual DK.CONFIG Includes
###########################################################################################################################################
set(incdir ${incdir} "${CMAKE_CURRENT_LIST_DIR}/../ui-app/ui.app.dk.config/dk.app/hmi_app")
set(incdir ${incdir} "${CMAKE_CURRENT_LIST_DIR}/../ui-app/ui.app.dk.config/dk.app/main_hmi")
set(incdir ${incdir} "${CMAKE_CURRENT_LIST_DIR}/../ui-app/ui.app.dk.config/dk.components/mainhmi_components")
# set(incdir ${incdir} "${CMAKE_CURRENT_LIST_DIR}/ui.app.dk.config/dm_sender")
# set(incdir ${incdir} "${CMAKE_CURRENT_LIST_DIR}/ui.app.dk.config/pharsar")

set(incdir ${incdir} "${CMAKE_CURRENT_LIST_DIR}/../ui-app/ui.app.dk.config/dk.components/mainhmi_components/hmi_component")
#set(incdir ${incdir} "${CMAKE_CURRENT_LIST_DIR}/../../../ui-app/ui.app.dk.config/dk.components/mainhmi_components/hmi_gauges_component")
#set(incdir ${incdir} "${CMAKE_CURRENT_LIST_DIR}/../../../ui-app/ui.app.dk.config/dk.components/mainhmi_components/hmi_gear_component")
#set(incdir ${incdir} "${CMAKE_CURRENT_LIST_DIR}/../../../ui-app/ui.app.dk.config/dk.components/mainhmi_components/hmi_settings_component")
#set(incdir ${incdir} "${CMAKE_CURRENT_LIST_DIR}/../../../ui-app/ui.app.dk.config/dk.components/mainhmi_components/hmi_warnings_component")
##########################################################################################################################################

add_definitions(${CPP_FLAGS})
# add_library(rdf_cpp_scripts STATIC ${rdf_cpp_scripts_src})
# target_include_directories(rdf_cpp_scripts PRIVATE ${incdir})
add_executable( ${BINARY_NAME} ${src})   #ip maybe dummy file with some function could be needed


target_link_libraries(${BINARY_NAME} PRIVATE libbz2.so.1.0.8)
target_link_libraries(${BINARY_NAME} PRIVATE -lgbm -ldrm)
target_link_libraries(${BINARY_NAME} PRIVATE ${STATIC_LIBS} ${SHARED_LIBS} )
# target_link_libraries(${BINARY_NAME} PRIVATE rdf_cpp_scripts ${STATIC_LIBS} ${SHARED_LIBS} )

target_include_directories(${BINARY_NAME}
 PUBLIC
 ${RENDERCORE_PATH}/../../../../../../cluster-platform/dijkstra/tools/kpi/boot-kpi/ti_am62x/include/
 ${RENDERCORE_PATH}/../../../../../../programs/reference/einstein4.0/ti-am62x/img-build/boot_kpi
 PRIVATE 
 ${incdir}
 )
target_link_directories(${BINARY_NAME} PRIVATE ${linkdir} )


if(CMAKE_SYSTEM_NAME MATCHES Linux)
file(GLOB_RECURSE TAR_FILES "${CMAKE_CURRENT_LIST_DIR}/../rdf_cpp/resources/*.tar")
install(FILES ${TAR_FILES} DESTINATION ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_ASSET}/usr/bin/resources)
else()
endif(CMAKE_SYSTEM_NAME MATCHES Linux)

target_add_dependencies(${BINARY_NAME}
  PRIVATE
  GenRuntime
  dk_logger
  dk_runtime
)

# Install the library
install(TARGETS ${BINARY_NAME}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)