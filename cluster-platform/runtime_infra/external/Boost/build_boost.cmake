#---------------------------------------------------------------------------------------------------------------------
#
# VISTEON CORPORATION CONFIDENTIAL
# ________________________________
#
# [2020] Visteon Corporation
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

# Cross-builds Boost from the vendored source tree instead of linking a prebuilt
# Boost, and points find_package(Boost) at the result. Supports Linux and QNX.
# Included from gp_program.cmake, and must stay ahead of anything using Boost.

if(NOT DEFINED BOOST_SRC_DIR)
	# Prefer the tree this file sits in, so the folder's name/case doesn't matter.
	if(EXISTS ${CMAKE_CURRENT_LIST_DIR}/bootstrap.sh)
		set(BOOST_SRC_DIR ${CMAKE_CURRENT_LIST_DIR})
	else()
		set(BOOST_SRC_DIR ${CMAKE_SOURCE_DIR}/cluster-platform/runtime_infra/external/Boost)
	endif()
endif()

if(NOT EXISTS ${BOOST_SRC_DIR}/bootstrap.sh)
	message(FATAL_ERROR "Boost source not found at ${BOOST_SRC_DIR} (no bootstrap.sh). "
		"Extract the Boost release there, or set BOOST_SRC_DIR before including this file.")
endif()

# Read the version from the source instead of hardcoding it, so dropping in a
# different Boost release cannot silently disagree with this file.
file(STRINGS ${BOOST_SRC_DIR}/Jamroot BOOST_VERSION_LINE REGEX "constant[ \t]+BOOST_VERSION[ \t]*:")
string(REGEX MATCH "[0-9]+\\.[0-9]+\\.[0-9]+" BOOST_VERSION_STRING "${BOOST_VERSION_LINE}")
if(NOT BOOST_VERSION_STRING MATCHES "^[0-9]+\\.[0-9]+\\.[0-9]+$")
	message(FATAL_ERROR "Could not read the Boost version from ${BOOST_SRC_DIR}/Jamroot")
endif()

set(BOOST_BUILD_DIR  ${CMAKE_BINARY_DIR}/external/boost-${BOOST_VERSION_STRING})
set(BOOST_STAMP_FILE ${BOOST_BUILD_DIR}/BOOST_BUILT)

if(CMAKE_SYSTEM_NAME STREQUAL QNX)
	# Flags per the QNX recipe in the Boost tree's Build_steps.txt. qcc comes from
	# PATH (qnxsdp-env.sh), so no user-config.jam is needed here.
	set(BOOST_B2_TOOLSET_ARGS
		toolset=qcc
		target-os=qnxnto
		"cxxflags=-Vgcc_ntoaarch64le -stdlib=libc++ -fPIC"
		"linkflags=-Vgcc_ntoaarch64le -stdlib=libc++"
		# Both variants: vsomeip links the .a (Boost_USE_STATIC_LIBS), while
		# gp_program.cmake stages the .so into the target filesystem.
		link=static,shared
		)
	if((NOT DEFINED ENV{QNX_HOST}) OR (NOT DEFINED ENV{QNX_TARGET}))
		message(FATAL_ERROR "QNX_HOST/QNX_TARGET not set - source qnxsdp-env.sh so b2 can find qcc.")
	endif()
else()
	# Use the cross compiler CMake already resolved from the conan toolchain; a
	# shell $CXX is not exported under a conan2 profile build.
	if(CMAKE_CXX_COMPILER)
		set(BOOST_CROSS_CXX ${CMAKE_CXX_COMPILER})
	elseif(DEFINED ENV{CXX} AND NOT "$ENV{CXX}" STREQUAL "")
		set(BOOST_CROSS_CXX $ENV{CXX})
	else()
		message(FATAL_ERROR "No aarch64-oe-linux C++ compiler: CMAKE_CXX_COMPILER and ENV{CXX} are both empty.")
	endif()
	set(BOOST_B2_TOOLSET_ARGS
		--user-config=${BOOST_BUILD_DIR}/user-config.jam
		toolset=gcc-oe
		target-os=linux
		architecture=arm
		address-model=64
		link=shared
		)
	if(CMAKE_SYSROOT)
		# cflags as well as cxxflags: boost.container's dlmalloc is a plain C file
		# and would not otherwise find the sysroot's libc headers (errno.h).
		list(APPEND BOOST_B2_TOOLSET_ARGS
			"cflags=--sysroot=${CMAKE_SYSROOT}"
			"cxxflags=--sysroot=${CMAKE_SYSROOT}"
			"linkflags=--sysroot=${CMAKE_SYSROOT}")
	endif()
endif()

# Guarded by a stamp file: b2 takes minutes, and this runs on every re-configure.
if(NOT EXISTS ${BOOST_STAMP_FILE})
	message(STATUS "Building Boost ${BOOST_VERSION_STRING} from source for ${CMAKE_SYSTEM_NAME} (one-time)...")

	file(MAKE_DIRECTORY ${BOOST_BUILD_DIR})
	if(DEFINED BOOST_CROSS_CXX)
		file(WRITE ${BOOST_BUILD_DIR}/user-config.jam "using gcc : oe : ${BOOST_CROSS_CXX} ;\n")
	endif()

	include(ProcessorCount)
	ProcessorCount(BOOST_BUILD_JOBS)
	if(BOOST_BUILD_JOBS EQUAL 0)
		set(BOOST_BUILD_JOBS 1)
	endif()

	# CC/CXX are cleared because bootstrap.sh builds the b2 tool itself, which has
	# to run on this x86_64 host - not be cross-compiled for the target.
	execute_process(
		COMMAND env -u CC -u CXX -u CFLAGS -u CXXFLAGS
			./bootstrap.sh --with-toolset=gcc
			--with-libraries=system,thread,filesystem --prefix=${BOOST_BUILD_DIR}
		WORKING_DIRECTORY ${BOOST_SRC_DIR}
		RESULT_VARIABLE BOOST_BOOTSTRAP_RESULT
		)
	if(NOT BOOST_BOOTSTRAP_RESULT EQUAL 0)
		message(FATAL_ERROR "Boost bootstrap.sh failed (exit ${BOOST_BOOTSTRAP_RESULT})")
	endif()

	execute_process(
		COMMAND ./b2 install
			--prefix=${BOOST_BUILD_DIR}
			${BOOST_B2_TOOLSET_ARGS}
			variant=release
			-j${BOOST_BUILD_JOBS}
		WORKING_DIRECTORY ${BOOST_SRC_DIR}
		RESULT_VARIABLE BOOST_B2_RESULT
		)
	if(NOT BOOST_B2_RESULT EQUAL 0)
		message(FATAL_ERROR "Boost b2 install failed (exit ${BOOST_B2_RESULT})")
	endif()

	file(WRITE ${BOOST_STAMP_FILE} "${BOOST_VERSION_STRING}\n")
endif()

# FindBoost prefers any BoostConfig.cmake it can find, and the SDK sysroot ships
# one - that is why the sysroot's Boost wins otherwise. Disabling that makes
# FindBoost search the directories below, so the SDK copy can stay in place.
set(Boost_NO_BOOST_CMAKE ON)
set(Boost_NO_SYSTEM_PATHS ON)
set(BOOST_ROOT       ${BOOST_BUILD_DIR})
set(BOOST_INCLUDEDIR ${BOOST_BUILD_DIR}/include)
set(BOOST_LIBRARYDIR ${BOOST_BUILD_DIR}/lib)

# Kept for consumers that ask for CONFIG mode explicitly, or newer CMake where
# FindBoost is gone (CMP0167).
set(Boost_DIR ${BOOST_BUILD_DIR}/lib/cmake/Boost-${BOOST_VERSION_STRING})
set(CMAKE_PREFIX_PATH ${BOOST_BUILD_DIR} ${CMAKE_PREFIX_PATH})

# The legacy names the rest of gp_program.cmake and vsomeip already use.
set(Boost_INCLUDE_DIR ${BOOST_BUILD_DIR}/include)
set(Boost_LIBRARY_DIR ${BOOST_BUILD_DIR}/lib)

# Stage the runtime libraries into the target filesystem: linking against them
# is not enough, the board needs the versioned .so (the soname in DT_NEEDED) at
# runtime. The unversioned symlink is link-time only, so it is not shipped.
file(GLOB BOOST_RUNTIME_LIBS ${BOOST_BUILD_DIR}/lib/libboost_*.so.${BOOST_VERSION_STRING})
file(COPY ${BOOST_RUNTIME_LIBS} DESTINATION ${CMAKE_INSTALL_PREFIX}/usr/lib)
