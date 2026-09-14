
include_directories(
	"./Common" 
)

set(ucl-adapterCmn_HDR
	"./Common/UclILAdapter.h"
	"./Common/UclILAdapter_Types.h"
	"./Common/UclILStreamAdapter.h"
)

if(UCL_ADAPTER_VMF)
	add_subdirectory(VMF)
endif()

if(UCL_ADAPTER_ASR)
	add_subdirectory(ASR)
endif()

install(FILES ${ucl-adapterCmn_HDR}
        DESTINATION usr/include/ucl
        COMPONENT base)
