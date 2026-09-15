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

# Cross-builds Boost 1.90.0 from the vendored source tree for aarch64-oe-linux,
# instead of using the Boost that ships prebuilt in the TI/Yocto SDK sysroot.
# Sets Boost_INCLUDE_DIR / Boost_LIBRARY_DIR for the rest of gp_program.cmake,
# same as the sysroot lookup it replaces.

set(BOOST_VERSION_STRING 1.90.0)

set(BOOST_SRC_DIR    ${CMAKE_SOURCE_DIR}/cluster-platform/runtime_infra/external/boost-1.90.0-src)
set(BOOST_BUILD_DIR  ${CMAKE_BINARY_DIR}/external/boost-1.90.0)
set(BOOST_STAMP_FILE ${BOOST_BUILD_DIR}/BOOST_BUILT)

if(NOT EXISTS ${BOOST_SRC_DIR}/bootstrap.sh)
	message(FATAL_ERROR
		"Boost ${BOOST_VERSION_STRING} source not found at ${BOOST_SRC_DIR}. "
		"Extract the boost_1_90_0 release source there before configuring "
		"(see ${BOOST_SRC_DIR}/README.md).")
endif()

if((NOT DEFINED ENV{CXX}) OR ("$ENV{CXX}" STREQUAL ""))
	message(FATAL_ERROR
		"ENV{CXX} is not set. Source the aarch64-oe-linux SDK "
		"environment-setup script (the one TI_HOME is set from) before "
		"configuring, so Boost.Build cross-compiles Boost ${BOOST_VERSION_STRING} "
		"with the matching compiler and sysroot.")
endif()

# b2 is slow (several minutes); only bootstrap/build once per build tree.
if(NOT EXISTS ${BOOST_STAMP_FILE})
	message(STATUS "Building Boost ${BOOST_VERSION_STRING} from source for aarch64-oe-linux (one-time)...")

	file(MAKE_DIRECTORY ${BOOST_BUILD_DIR})
	file(WRITE ${BOOST_BUILD_DIR}/user-config.jam "using gcc : oe : $ENV{CXX} ;\n")

	include(ProcessorCount)
	ProcessorCount(BOOST_BUILD_JOBS)
	if(BOOST_BUILD_JOBS EQUAL 0)
		set(BOOST_BUILD_JOBS 1)
	endif()

	execute_process(
		COMMAND ./bootstrap.sh --with-toolset=gcc --with-libraries=system,thread,filesystem --prefix=${BOOST_BUILD_DIR}
		WORKING_DIRECTORY ${BOOST_SRC_DIR}
		RESULT_VARIABLE BOOST_BOOTSTRAP_RESULT
		)
	if(NOT BOOST_BOOTSTRAP_RESULT EQUAL 0)
		message(FATAL_ERROR "Boost bootstrap.sh failed (exit ${BOOST_BOOTSTRAP_RESULT})")
	endif()

	execute_process(
		COMMAND ./b2 install
			--user-config=${BOOST_BUILD_DIR}/user-config.jam
			--prefix=${BOOST_BUILD_DIR}
			toolset=gcc-oe
			target-os=linux
			architecture=arm
			address-model=64
			link=shared
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

set(Boost_INCLUDE_DIR ${BOOST_BUILD_DIR}/include)
set(Boost_LIBRARY_DIR ${BOOST_BUILD_DIR}/lib)

#-------------------------------------------------------------------------------------------------------------------
#	  Date	   |   User	  |	  Task	  |										Description
#-------------------------------------------------------------------------------------------------------------------
#  09/15/2026  |   n/a	  |	   N/A	  | Created - build Boost 1.90.0 from source instead of SDK-prebuilt
#-------------------------------------------------------------------------------------------------------------------
