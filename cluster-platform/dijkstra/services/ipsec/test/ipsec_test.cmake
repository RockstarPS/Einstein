# Set minimum required version and project name
cmake_minimum_required(VERSION 3.10)
project(ipsec_test)

# Set cross-compilation toolchain (if necessary, e.g., for AArch64)
# Uncomment and modify the line below if you're cross-compiling
# set(CMAKE_C_COMPILER aarch64-linux-gnu-gcc)


set(IPSEC_LIB ${CMAKE_CURRENT_SOURCE_DIR}/../../ipsec)

set(BINARY_NAME ipsec_test)
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Include directories
include_directories(
    ${IPSEC_LIB}/public
)


# Create Binary
add_executable(${BINARY_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/ipsec_test.c
    ${IPSEC_LIB}/src/ipsec_service.c
)

target_include_directories(${BINARY_NAME} PRIVATE ${INCLUDE_DIR})

target_link_libraries(${BINARY_NAME} PRIVATE
	ipsec
)

# Install the library
install(TARGETS ${BINARY_NAME}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
