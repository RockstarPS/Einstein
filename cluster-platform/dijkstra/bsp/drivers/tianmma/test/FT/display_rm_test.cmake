
cmake_minimum_required (VERSION 3.14)

# Create Binary
add_executable(${BINARY_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/src/display_test.c
)

# Add dependency libraries
target_add_dependencies(${BINARY_NAME}
    PRIVATE
    resmgr_display_devctl
)

# Install the library
install(TARGETS ${BINARY_NAME}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

#-------------------------------------------------------------------------------------------------------------------
#    Date     |   User   |   Task    |                                     Description
#-------------------------------------------------------------------------------------------------------------------
# 03/07/2020    | RBABU9   |  950310   | Created initial file
#-------------------------------------------------------------------------------------------------------------------
