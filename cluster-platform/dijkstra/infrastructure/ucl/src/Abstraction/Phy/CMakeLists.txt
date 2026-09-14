
if (${OS} MATCHES "QNX")
	if(UCL_TRANSPORT_SPI)
		include_directories(
			"./SpiQnx"
		)
		file(GLOB ucl-phy_SRC
			"./SpiQnx/UclALPhySpiQnx_Impl.c.c"
		)
		file(GLOB ucl-phy_HDR
			"./SpiQnx/UclALPhySpiQnx_Impl.c.h"
		)
	endif()
	if(UCL_TRANSPORT_SERIAL)
		include_directories(
			"./SerialPOSIX"
		)
		file(GLOB ucl-phy_SRC
			"./SerialPOSIX/UclALPhySerialPOSIX_Impl.c"
		)
		file(GLOB ucl-phy_HDR
			"./SerialPOSIX/UclALPhySerialPOSIX_Impl.h"
		)
	endif()
	if(UCL_TRANSPORT_IMX8_MU)
		include_directories(
			"./MuQnx"
		)
		file(GLOB ucl-phy_SRC
			"./MuQnx/UclALPhyMuQnx_Impl.c"
		)
		file(GLOB ucl-phy_HDR
			"./MuQnx/UclALPhyMuQnx_Impl.h"
		)
	endif()
elseif (${OS} MATCHES "AUTOSAR")
	if(UCL_TRANSPORT_IMX8_MU)
		include_directories(
			"./MuASR"
		)
		file(GLOB ucl-phy_SRC
			"./MuASR/UclALPhyMuASR_Impl.c"
		)
		file(GLOB ucl-phy_HDR
			"./MuASR/UclALPhyMuASR_Impl.h"
		)
	endif()
else()
    message( SEND_ERROR "No OS defined" )
endif()

list(SORT ucl-phy_SRC)

add_library(uclal_phy STATIC ${ucl-phy_SRC})

install(TARGETS uclal_phy
	ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(FILES ${ucl-phy_HDR}
        DESTINATION usr/include/ucl
        COMPONENT base)
