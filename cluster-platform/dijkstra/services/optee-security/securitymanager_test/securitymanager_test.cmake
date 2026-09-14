# Set minimum required version and project name
cmake_minimum_required(VERSION 3.10)
project(SecureStorageCrypto)

# Set cross-compilation toolchain (if necessary, e.g., for AArch64)
# Uncomment and modify the line below if you're cross-compiling
# set(CMAKE_C_COMPILER aarch64-linux-gnu-gcc)

# OPTEE Security Manager and Client library locations
# Set paths to the libraries and includes
set(OPTEE_SECMGRLIB ${CMAKE_CURRENT_SOURCE_DIR}/../../../libraries/optee-securitylib)
set(OPTEE_CLIENT_INC ${OPTEE_SECMGRLIB}/Prebuilt_client/out/export/usr)
set(SECMGR_OUT ${OPTEE_SECMGRLIB}/SecurityManager/out)

# Include directories
include_directories(
    ${SECMGR_OUT}/include
    ${OPTEE_CLIENT_INC}/include
)

# Create Binary
add_executable(${BINARY_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/src/optee_securestorage_crypto.c
)
#######################################################################
# use OpenSSL from TI SDK sysroot
#######################################################################

if(DEFINED ENV{TI_SYSROOT})
    set(TI_SYSROOT_PATH "$ENV{TI_SYSROOT}")
    set(OPENSSL_ROOT_DIR "${TI_SYSROOT_PATH}/aarch64-oe-linux/usr")

    if(EXISTS "${OPENSSL_ROOT_DIR}/include/openssl/ssl.h")
        set(OPENSSL_INCLUDE_DIR "${OPENSSL_ROOT_DIR}/include")
        if(EXISTS "${OPENSSL_ROOT_DIR}/lib/libcrypto.so")
            set(OPENSSL_CRYPTO_LIBRARY "${OPENSSL_ROOT_DIR}/lib/libcrypto.so")
            if(EXISTS "${OPENSSL_ROOT_DIR}/lib/libssl.so")
                set(OPENSSL_SSL_LIBRARY "${OPENSSL_ROOT_DIR}/lib/libssl.so")
                set(OPENSSL_USE_STATIC_LIBS FALSE)
                set(OPENSSL_LIBRARIES "${OPENSSL_CRYPTO_LIBRARY};${OPENSSL_SSL_LIBRARY}")
                message(STATUS "Using TI SDK OpenSSL from: ${OPENSSL_ROOT_DIR}")
                find_package(OpenSSL REQUIRED)
                target_link_libraries(${BINARY_NAME} OpenSSL::Crypto OpenSSL::SSL)
            else()
                message(FATAL_ERROR "OpenSSL libssl.so not found in: ${OPENSSL_ROOT_DIR}/lib")
            endif()
        else()
            message(FATAL_ERROR "OpenSSL libcrypto.so not found in: ${OPENSSL_ROOT_DIR}/lib")
        endif()
    else()
        message(FATAL_ERROR "OpenSSL headers not found in: ${OPENSSL_ROOT_DIR}/include")
    endif()
else()
    message(FATAL_ERROR "TI_SYSROOT environment variable not set")
endif()

# Libraries to link
target_link_libraries(${BINARY_NAME}
    ${SECMGR_OUT}/lib/libopteesecurity.a
    ${OPTEE_CLIENT_INC}/lib/libteec.a
    ${SECMGR_OUT}/lib/libopteeotp.a
)

# Install the library
install(TARGETS ${BINARY_NAME}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
