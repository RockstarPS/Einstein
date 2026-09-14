
set(ucl-adapter_SRC
	"UclProxyCdd.c"
)

set(ucl-adapter_HDR
)

add_library(ucl_asr STATIC ${ucl-adapter_SRC} )

target_link_libraries(ucl_asr uclal_os uclal_phy uclal_dbg ucldl uclil uclcmn uclsys cmplib )

target_include_directories( ucl_asr PUBLIC 
	"../Common"	
	"../../Common"
	"../../Abstraction/Common"
	"../../Abstraction/Debug/Common"
	"../../Abstraction/Debug/Null"
	"../../Abstraction/Phy/Common"
	"../../Abstraction/Phy/MuASR"
	"../../Abstraction/Os/Common"
	"../../Abstraction/Os/ASR"
	"../../InterfaceLayer/Common"
	"../../InterfaceLayer/UclILSched"
	"../../InterfaceLayer/UclILRouter"
	"../../DataLayer/Common"
	"../../DataLayer/UclDL"
	"../../System/Common"
	"../../System/UclSys"
)

install(TARGETS ucl_asr
	ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(FILES ${ucl-adapter_HDR}
        DESTINATION usr/include/ucl
        COMPONENT base)
