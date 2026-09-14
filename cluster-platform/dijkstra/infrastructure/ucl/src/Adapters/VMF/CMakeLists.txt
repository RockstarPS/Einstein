
set(ucl-adapter_SRC
	"UclVmfProxy.cpp"
	"UclVmfInterface.cpp"
	"main.cpp"
)

set(ucl-adapter_HDR
	"UclVmfConfig.hpp"
	"UclVmfInterface.hpp"
	"UclVmfProxy.hpp"
)

add_library(ucl_vmf SHARED ${ucl-adapter_SRC})
add_library(ucl_vmf_s SHARED ${ucl-adapter_SRC})

target_link_libraries(ucl_vmf uclal_os uclal_phy uclal_dbg ucldl uclil uclcmn uclsys )
target_link_libraries(ucl_vmf_s uclal_os uclal_phy uclal_dbg ucldl uclil uclcmn uclsys )

set_target_properties(ucl_vmf PROPERTIES VERSION ${UCL_VERSION} SOVERSION ${UCL_MAJOR_VERSION} OUTPUT_NAME ucl_vmf)
set_target_properties(ucl_vmf_s PROPERTIES VERSION ${UCL_VERSION} OUTPUT_NAME ucl_vmf)

install(TARGETS ucl_vmf
	ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
	RUNTIME DESTINATION ${CMAKE_INSTALL_LIBDIR}
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(TARGETS ucl_vmf_s
	ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(FILES ${ucl-adapter_HDR}
        DESTINATION usr/include/ucl
        COMPONENT base)
