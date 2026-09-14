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

# Dummy library only created to add VP Apps libraries
add_library(${MODULE_NAME} ${MODULE_STATIC_SHARED}
	${CMAKE_SOURCE_DIR}/programs/reference/einstein4.0/ti-am62x/di-apps/dummy_library.c
)
# Add Apps dependency libraries
target_add_dependencies(${MODULE_NAME}
    PUBLIC
	Dcm_App
	#telltales
	Mdl_Airbag
	Mdl_TurnHazard
	#Core-telltale
	Ctrl_telltale
	Ctrl_telltale_adapter
	View_telltale
	#warnings
	Mdl_wAirbag
	Mdl_wFuelLidOpen
	#Core-warning
	Ctrl_warning
	Warning_Core
	WarnMsg_Core_Observer
	WarnMsg_Core_TmrSupport
	#Safety
	Mdl_SafetyAdapter
	#infra
	Ctrl_WSS
	#Gauges
	Mdl_Speed
	Mdl_Speed_view
	Mdl_Tacho
	CFastGaugeAdapter
	#Illumination
	Mdl_Dim
	ctrl-illumination
	view-illumination
	#Gear
	Mdl_Gear

)

#====================================================================================================================================
#**      CDSID         Date            Traceability                   Description
#**==================================================================================================================================
#**     aelango6    03-Jul-2025       PE4TI29141-6688             initial file creation
#**==================================================================================================================================

