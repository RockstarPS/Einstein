
cmake_minimum_required (VERSION 3.14)

# Create Binary
add_executable(${BINARY_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/src/DIO_test_devctl.c
)

# Add system libraries
target_link_libraries(${BINARY_NAME}
    PRIVATE
    slog2
)

# Add dependency libraries
target_add_dependencies(${BINARY_NAME}
	PUBLIC
	resmgr_dio_devctl
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
