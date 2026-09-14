# Set minimum required version and project name
cmake_minimum_required(VERSION 3.10)
project(ipsec_start)

set(LIBRARY_NAME ipsec)
set(BINARY_NAME ipsec_start)
# Set cross-compilation toolchain (if necessary, e.g., for AArch64)
# Uncomment and modify the line below if you're cross-compiling
# set(CMAKE_C_COMPILER aarch64-linux-gnu-gcc)

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/public)

# -------------------------------------------------------
# OP-TEE Security Manager + Client paths
# -------------------------------------------------------
set(OPTEE_SECMGRLIB ${CMAKE_CURRENT_SOURCE_DIR}/../../libraries/optee-securitylib)
set(OPTEE_CLIENT_INC ${OPTEE_SECMGRLIB}/Prebuilt_client/out/export/usr)
set(SECMGR_OUT ${OPTEE_SECMGRLIB}/SecurityManager/out)

find_package(OpenSSL REQUIRED)

# Create static library
add_library(${LIBRARY_NAME} STATIC
    ${SRC_DIR}/ipsec_service.c
)

target_include_directories(${LIBRARY_NAME} PUBLIC
    ${INCLUDE_DIR}
    ${SECMGR_OUT}/include
    ${OPTEE_CLIENT_INC}/include
)

target_link_libraries(${LIBRARY_NAME} PUBLIC
    ${SECMGR_OUT}/lib/libopteesecurity.a
    ${OPTEE_CLIENT_INC}/lib/libteec.a
    OpenSSL::Crypto
)

# Create Binary
add_executable(${BINARY_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ipsec_start_service.c
    #${CMAKE_CURRENT_SOURCE_DIR}/src/ipsec_service.c
)
target_link_libraries(${BINARY_NAME} PRIVATE
    ${LIBRARY_NAME}
)

# Install the library
install(TARGETS ${LIBRARY_NAME}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(TARGETS ${BINARY_NAME}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
