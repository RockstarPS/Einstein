"""
Script for running T1 VP unit tests.
To execute such test follow these steps:
    1. Run RUN_VCAST.bat in the component folder
    2. The html report will be in the doc folder of the component
"""

import os
import shutil
import asyncio
import argparse
import subprocess

from shutil import copy
from pathlib import Path
from datetime import date

# Get current script folder
JOB_DIR = os.path.abspath('.')

# predefined bat paths
bat_paths = [
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/build_scripts/vbuild/doc/VBuild_examples/example5/libraries/myCommonLib/unit_test/vcast_scripts/myCommonLib_HT.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/cluster-platform/turing/fbl/core/test/ut/test.harnes/FBL_COMP/FBL_COMP_VCAST_HT.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/cluster-platform/turing/fbl/core/test/ut/test.harnes/FBL_COMPRESS/FBL_COMPRESS_VCAST_HT.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/cluster-platform/turing/fbl/core/test/ut/test.harnes/FBL_CRC/FBL_CRC_VCAST_HT.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/cluster-platform/turing/fbl/core/test/ut/test.harnes/FBL_CRYPTO/FBL_CRYPTO.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/cluster-platform/turing/fbl/core/test/ut/test.harnes/FBL_MAIN/FBL_MAIN_VCAST_HT.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/cluster-platform/turing/fbl/core/test/ut/test.harnes/FBL_NVM/FBL_NVM_VCAST_HT.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/cluster-platform/turing/fbl/core/test/ut/test.harnes/FBL_SECUREBOOT/FBL_SECUREBOOT_VCAST_HT.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/cluster-platform/turing/fbl/core/test/ut/test.harnes/TP/TP_VCAST_HT.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/cluster-platform/turing/fbl/core/test/ut/test.harnes/TP_IF/TP_IF_VCAST_HT.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/cluster-platform/turing/fbl/core/test/ut/test.harnes/UDSDIAG/UDSDIAG_VCAST_HT.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/cluster-platform/turing/fbl/micro_traveo_2/test/ut/tv1/test.harnes/CAN/CAN_VCAST_HT.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/cluster-platform/turing/fbl/micro_traveo_2/test/ut/tv1/test.harnes/FBL_CAN_DRV/FBL_CAN_DRV_VCAST_HT.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/cluster-platform/turing/fbl/micro_traveo_2/test/ut/tv1/test.harnes/FBL_FLASH_DRV/FBL_FLASH_DRV_VCAST_HT.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/cluster-platform/turing/fbl/micro_traveo_2/test/ut/tv1/test.harnes/FBL_TIMER_DRV/FBL_TIMER_DRV_VCAST_HT.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/cluster-platform/turing/fbl/micro_traveo_2/test/ut/tv1/test.harnes/FBL_WDT_DRV/FBL_WDT_DRV_VCAST_HT.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/cluster-platform/turing/mcal/traveo2/i2cdrv/test.harness/I2CDRV_VCAST_HT/I2CDRV_VCAST_HT.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/cluster-platform/turing/mcal/traveo2/ppudrv/test.harness/PPUDRV_VCAST_HT/PPUDRV_VCAST_HT.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/cluster-platform/turing/vautosar/diag/vw/dcm/test/test.harness/DIAGMGR_VCAST_HT.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/cluster-platform/turing/vautosar/diag/vw/dem/test/test.harness/VC_DEM.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/cluster-platform/turing/vautosar/sys/crc/src/test.harness/CRCLIB_VCAST_HT/CRCLIB_VCAST_HT.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/programs/vw/my2022/fpkb8/bsw-gen/bsw/dcmext/test.harness/DCMEXT_VAST_UT.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/programs/vw/my2022/fpkb8/bsw-gen/bsw/demext/test.harness/DEMEXT_VCAST_HT.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/programs/vw/my2022/fpkb8/mcuext/test/test.harness/MCUEXT_VCAST_HT.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/programs/vw/my2022/fpkb8/safebsw/test/test.harness/SAFEBSW_VCAST_HT.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/programs/vw/my2022/fpkb8/vp-apps/swc/CTRL_EOL/tst/CTRL_EOL.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/programs/vw/my2022/fpkb8/vp-apps/swc/CTRL_HMI/tst/CTRL_HMI.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/programs/vw/my2022/fpkb8/vp-apps/swc/CTRL_Seatbelt/tst/CTRL_SEATBELT.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/programs/vw/my2022/fpkb8/vp-apps/swc/CTRL_Warning/tst/CTRL_WARNING.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/programs/vw/my2022/fpkb8/vp-apps/swc/MDL_Assistance/tst/MDL_ASSISTANCE.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/programs/vw/my2022/fpkb8/vp-apps/swc/MDL_BCCT/tst/MDL_BCCT.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/programs/vw/my2022/fpkb8/vp-apps/swc/MDL_Blinkers/tst/MDL_BLINKERS.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/programs/vw/my2022/fpkb8/vp-apps/swc/MDL_Button/tst/MDL_BUTTON.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/programs/vw/my2022/fpkb8/vp-apps/swc/MDL_CarHandling/tst/MDL_CARHANDLING.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/programs/vw/my2022/fpkb8/vp-apps/swc/MDL_CarLeaving/tst/MDL_CARLEAVING.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/programs/vw/my2022/fpkb8/vp-apps/swc/MDL_CarModes/tst/MDL_CARMODES.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/programs/vw/my2022/fpkb8/vp-apps/swc/MDL_Clock/tst/MDL_CLOCK.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/programs/vw/my2022/fpkb8/vp-apps/swc/MDL_Cruise/tst/MDL_CRUISE.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/programs/vw/my2022/fpkb8/vp-apps/swc/MDL_Dimming/tst/MDL_DIMMING.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/programs/vw/my2022/fpkb8/vp-apps/swc/MDL_Display/tst/MDL_DISPLAY.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/programs/vw/my2022/fpkb8/vp-apps/swc/MDL_Gear/tst/MDL_GEAR.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/programs/vw/my2022/fpkb8/vp-apps/swc/MDL_HMIGW/tst/MDL_HMIGW.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/programs/vw/my2022/fpkb8/vp-apps/swc/MDL_Heater/tst/MDL_HEATER.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/programs/vw/my2022/fpkb8/vp-apps/swc/MDL_Infotainment/tst/MDL_INFOTAINMENT.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/programs/vw/my2022/fpkb8/vp-apps/swc/MDL_InternTemp/tst/MDL_INTERNTEMP.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/programs/vw/my2022/fpkb8/vp-apps/swc/MDL_Motor/tst/MDL_MOTOR.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/programs/vw/my2022/fpkb8/vp-apps/swc/MDL_Odo/tst/MDL_ODO.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/programs/vw/my2022/fpkb8/vp-apps/swc/MDL_OutTemp/tst/MDL_OUTTEMP.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/programs/vw/my2022/fpkb8/vp-apps/swc/MDL_RCC/tst/MDL_RCC.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/programs/vw/my2022/fpkb8/vp-apps/swc/MDL_Road/tst/MDL_ROAD.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/programs/vw/my2022/fpkb8/vp-apps/swc/MDL_Service/tst/MDL_SERVICE.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/programs/vw/my2022/fpkb8/vp-apps/swc/MDL_ServiceKey/tst/MDL_SERVICEKEY.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/programs/vw/my2022/fpkb8/vp-apps/swc/MDL_SiWaLa/tst/MDL_SIWALA.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/programs/vw/my2022/fpkb8/vp-apps/swc/MDL_Speed/tst/MDL_SPEED.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/programs/vw/my2022/fpkb8/vp-apps/swc/MDL_TRC/tst/MDL_TRC.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/programs/vw/my2022/fpkb8/vp-apps/swc/MDL_Tank/tst/MDL_TANK.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/programs/vw/my2022/fpkb8/vp-apps/swc/MDL_Tyres/tst/MDL_TYRES.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/programs/vw/my2022/fpkb8/vp-apps/swc/MDL_VehicleType/tst/MDL_VEHICLETYPE.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/programs/vw/my2022/fpkb8/vp-apps/swc/VIEW_Illumination/tst/VIEW_ILLUMINATION.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/programs/vw/my2022/fpkb8/vp-apps/swc/VIEW_Lamps/tst/VIEW_LAMPS.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/programs/vw/my2022/fpkb8/vp-apps/swc/VIEW_Sound/tst/VIEW_SOUND.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/programs/vw/my2022/fpkb8/vp-apps/gs/CXDR_GFX/src/tst/UML_GEN.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/programs/vw/my2022/fpkb8/vp-apps/lib/LIB_Arithmetic/tst/LIB_ARITHMETIC.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/programs/vw/my2022/fpkb8/vp-apps/lib/LIB_Assert/tst/LIB_ASSERTS.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/programs/vw/my2022/fpkb8/vp-apps/lib/LIB_BAP/tst/LIB_BAP.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/programs/vw/my2022/fpkb8/vp-apps/lib/LIB_Cmp/tst/LIB_CMP.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/programs/vw/my2022/fpkb8/vp-apps/lib/LIB_E2E/tst1/LIB_E2E.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/programs/vw/my2022/fpkb8/vp-apps/lib/LIB_E2E/tst2/LIB_E2E.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/programs/vw/my2022/fpkb8/vp-apps/lib/LIB_Hmi/tst/LIB_HMI.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/programs/vw/my2022/fpkb8/vp-apps/lib/LIB_Math/tst/LIB_MATH.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/programs/vw/my2022/fpkb8/vp-apps/lib/LIB_Mem/tst/LIB_MEM.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/programs/vw/my2022/fpkb8/vp-apps/lib/LIB_RLE/tst/LIB_RLE.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/programs/vw/my2022/fpkb8/vp-apps/lib/LIB_String/tst/LIB_STRING.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/programs/vw/my2022/fpkb8/vp-apps/lib/LIB_Time/tst/LIB_TIME.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/programs/vw/my2022/fpkb8/vp-apps/cdd/CXDR_Illum/tst/CXDR_ILLUM.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/programs/vw/my2022/fpkb8/vp-apps/cdd/CXDR_SafeTTMonitor/tst/CXDR_SAFETTMONITOR.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/programs/vw/my2022/fpkb8/vp-apps/cdd/CXDR_Sensors/tst/CXDR_SENSORS.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/programs/vw/my2022/fpkb8/vp-apps/cdd/CXDR_Tank/tst/CXDR_TANK.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/programs/vw/my2022/fpkb8/vp-apps/cdd/SRV_ComExt/gen/tst/SRV_COMEXT_GEN.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/programs/vw/my2022/fpkb8/vp-apps/cdd/SRV_ComExt_Safety/tst/SRV_COMEXT_SAFETY.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/programs/vw/my2022/fpkb8/vp-apps/cdd/SRV_CsmH/tst/SRV_CSMH.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/programs/vw/my2022/fpkb8/vp-apps/cdd/SRV_KsExt/tst/SRV_KSEXT.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/programs/vw/my2022/fpkb8/vp-apps/cdd/SRV_MemTest/tst/SRV_MEMTEST.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/programs/vw/my2022/fpkb8/vp-apps/cdd/SRV_Monitor/tst/SRV_Monitor.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/programs/vw/my2022/fpkb8/vp-apps/cdd/SRV_Power/tst/SRV_POWER.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/programs/vw/my2022/fpkb8/vp-apps/cdd/SRV_Reset/tst/SRV_RESET.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/programs/vw/my2022/fpkb8/vp-apps/cdd/SRV_Station/tst/SRV_STATION.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/programs/vw/my2022/fpkb8/vp-apps/cdd/SRV_Timegen/tst/SRV_TIMEGEN.bat",
    r"C:/jenkins/workspace/VW_DI_fpkb8/VW_DI_fpkb8_UNIT_TEST/programs/vw/my2022/fpkb8/vp-apps/cdd/SRV_Trace/tst/SRV_TRACE.bat",
    

]

# predefined management reports paths
man_reports = [
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\build_scripts\\vbuild\\doc\\VBuild_examples\\example5\\libraries\\myCommonLib\\unit_test\\vcast_scripts\\doc\\myCommonLib_HT_management_report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\cluster-platform\\turing\\fbl\\core\\test\\ut\\results\\FBL_COMP\\FBL_COMP_Testcase_Management_Report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\cluster-platform\\turing\\fbl\\core\\test\\ut\\results\\FBL_COMPRESS\\FBL_COMPRESS_Testcase_Management_Report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\cluster-platform\\turing\\fbl\\core\\test\\ut\\results\\FBL_CRC\\FBL_CRC_Testcase_Management_Report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\cluster-platform\\turing\\fbl\\core\\test\\ut\\results\\FBL_CRYPTO\\FBL_CRYPTO_Testcase_Management_Report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\cluster-platform\\turing\\fbl\\core\\test\\ut\\results\\FBL_MAIN\\FBL_MAIN_Testcase_Management_Report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\cluster-platform\\turing\\fbl\\core\\test\\ut\\results\\FBL_NVM\\Testcase Management Report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\cluster-platform\\turing\\fbl\\core\\test\\ut\\results\\FBL_SECUREBOOT\\Testcase Management Report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\cluster-platform\\turing\\fbl\\core\\test\\ut\\results\\TP\\TP_Testcase_Management_Report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\cluster-platform\\turing\\fbl\\core\\test\\ut\\results\\TP_IF\\TP_IF_Testcase_Management_Report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\cluster-platform\\turing\\fbl\\core\\test\\ut\\results\\UDSDIAG\\UDSDIAG_Testcase_Management_Report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\cluster-platform\\turing\\fbl\\micro_traveo_2\\test\\ut\\tv1\\results\\CAN\\CAN_Testcase_Management_Report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\cluster-platform\\turing\\fbl\\micro_traveo_2\\test\\ut\\tv1\\results\\FBL_CAN_DRV\\FBL_CAN_DRV_Testcase_Management_Report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\cluster-platform\\turing\\fbl\\micro_traveo_2\\test\\ut\\tv1\\results\\FBL_FLASH_DRV\\FBL_FLASH_DRV_Testcase_Management_Report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\cluster-platform\\turing\\fbl\\micro_traveo_2\\test\\ut\\tv1\\results\\FBL_TIMER_DRV\\FBL_TIMER_DRV_Testcase_Management_Report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\cluster-platform\\turing\\fbl\\micro_traveo_2\\test\\ut\\tv1\\results\\FBL_WDT_DRV\\FBL_WDT_DRV_Testcase_Managementl_Report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\cluster-platform\\turing\\mcal\\traveo2\\i2cdrv\\test.harness\\I2CDRV_VCAST_HT\\I2CDRV_VCAST_HT_management_report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\cluster-platform\\turing\\mcal\\traveo2\\ppudrv\\test.harness\\PPUDRV_VCAST_HT\\PPUDRV_VCAST_HT_management_report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\cluster-platform\\turing\\vautosar\\diag\\vw\\dcm\\test\\results\\DIAGMGR_VCAST_HT_Testcase Management Report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\cluster-platform\\turing\\vautosar\\diag\\vw\\dem\\test\\results\\Unit Test Result\\DEM_VCAST_HT_management_report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\cluster-platform\\turing\\vautosar\\sys\\crc\\src\\test.harness\\Unit Test Result\\CRCLIB_VCAST_HT_management_report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\programs\\vw\\my2022\\fpkb8\\bsw-gen\\bsw\\dcmext\\test.harness\\DCMEXT_VAST_UT_management_report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\programs\\vw\\my2022\\fpkb8\\bsw-gen\\bsw\\demext\\test.harness\\Test Case Management Report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\programs\\vw\\my2022\\fpkb8\\mcuext\\test\\results\\MCUEXT_Testcase_Management_Report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\programs\\vw\\my2022\\fpkb8\\safebsw\\test\\Results\\Test_Case_Management_Report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\programs\\vw\\my2022\\fpkb8\\vp-apps\\swc\\CTRL_EOL\\tst\\doc\\CTRL_EOL_management_report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\programs\\vw\\my2022\\fpkb8\\vp-apps\\swc\\CTRL_HMI\\tst\\doc\\CTRL_HMI_management_report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\programs\\vw\\my2022\\fpkb8\\vp-apps\\swc\\CTRL_Seatbelt\\tst\\doc\\CTRL_SEATBELT_management_report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\programs\\vw\\my2022\\fpkb8\\vp-apps\\swc\\CTRL_Warning\\tst\\doc\\CTRL_WARNING_management_report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\programs\\vw\\my2022\\fpkb8\\vp-apps\\swc\\MDL_Assistance\\tst\\doc\\MDL_ASSISTANCE_management_report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\programs\\vw\\my2022\\fpkb8\\vp-apps\\swc\\MDL_BCCT\\tst\\doc\\MDL_BCCT_management_report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\programs\\vw\\my2022\\fpkb8\\vp-apps\\swc\\MDL_Blinkers\\tst\\doc\\Report_MDL_Blinkers.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\programs\\vw\\my2022\\fpkb8\\vp-apps\\swc\\MDL_Button\\tst\\doc\\MDL_BUTTON_management_report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\programs\\vw\\my2022\\fpkb8\\vp-apps\\swc\\MDL_CarHandling\\tst\\doc\\MDL_CARHANDLING_management_report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\programs\\vw\\my2022\\fpkb8\\vp-apps\\swc\\MDL_CarLeaving\\tst\\doc\\MDL_CARLEAVING_management_report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\programs\\vw\\my2022\\fpkb8\\vp-apps\\swc\\MDL_CarModes\\tst\\doc\\MDL_CARMODES_management_report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\programs\\vw\\my2022\\fpkb8\\vp-apps\\swc\\MDL_Clock\\tst\\doc\\MDL_CLOCK_management_report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\programs\\vw\\my2022\\fpkb8\\vp-apps\\swc\\MDL_Cruise\\tst\\doc\\MDL_CRUISE_management_report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\programs\\vw\\my2022\\fpkb8\\vp-apps\\swc\\MDL_Dimming\\tst\\doc\\MDL_DIMMING_management_report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\programs\\vw\\my2022\\fpkb8\\vp-apps\\swc\\MDL_Display\\tst\\doc\\MDL_DISPLAY_management_report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\programs\\vw\\my2022\\fpkb8\\vp-apps\\swc\\MDL_Gear\\tst\\doc\\MDL_GEAR_management_report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\programs\\vw\\my2022\\fpkb8\\vp-apps\\swc\\MDL_HMIGW\\tst\\doc\\MDL_HMIGW_management_report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\programs\\vw\\my2022\\fpkb8\\vp-apps\\swc\\MDL_Heater\\tst\\doc\\MDL_HEATER_management_report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\programs\\vw\\my2022\\fpkb8\\vp-apps\\swc\\MDL_Infotainment\\tst\\doc\\Report_MDL_Infotainment.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\programs\\vw\\my2022\\fpkb8\\vp-apps\\swc\\MDL_InternTemp\\tst\\doc\\MDL_INTERNTEMP_management_report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\programs\\vw\\my2022\\fpkb8\\vp-apps\\swc\\MDL_Motor\\tst\\doc\\MDL_MOTOR_management_report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\programs\\vw\\my2022\\fpkb8\\vp-apps\\swc\\MDL_Odo\\tst\\doc\\MDL_ODO_management_report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\programs\\vw\\my2022\\fpkb8\\vp-apps\\swc\\MDL_OutTemp\\tst\\doc\\MDL_OUTTEMP_management_report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\programs\\vw\\my2022\\fpkb8\\vp-apps\\swc\\MDL_RCC\\tst\\doc\\MDL_RCC_management_report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\programs\\vw\\my2022\\fpkb8\\vp-apps\\swc\\MDL_Road\\tst\\doc\\MDL_ROAD_management_report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\programs\\vw\\my2022\\fpkb8\\vp-apps\\swc\\MDL_Service\\tst\\doc\\MDL_SERVICE_management_report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\programs\\vw\\my2022\\fpkb8\\vp-apps\\swc\\MDL_ServiceKey\\tst\\doc\\MDL_SERVICEKEY_management_report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\programs\\vw\\my2022\\fpkb8\\vp-apps\\swc\\MDL_SiWaLa\\tst\\doc\\MDL_SIWALA_management_report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\programs\\vw\\my2022\\fpkb8\\vp-apps\\swc\\MDL_Speed\\tst\\doc\\MDL_SPEED_management_report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\programs\\vw\\my2022\\fpkb8\\vp-apps\\swc\\MDL_TRC\\tst\\doc\\MDL_TRC_management_report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\programs\\vw\\my2022\\fpkb8\\vp-apps\\swc\\MDL_Tank\\tst\\doc\\MDL_TANK_management_report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\programs\\vw\\my2022\\fpkb8\\vp-apps\\swc\\MDL_Tyres\\tst\\doc\\MDL_TYRES_management_report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\programs\\vw\\my2022\\fpkb8\\vp-apps\\swc\\MDL_VehicleType\\tst\\doc\\MDL_VEHICLETYPE_management_report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\programs\\vw\\my2022\\fpkb8\\vp-apps\\swc\\VIEW_Illumination\\tst\\doc\\VIEW_ILLUMINATION_management_report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\programs\\vw\\my2022\\fpkb8\\vp-apps\\swc\\VIEW_Lamps\\tst\\doc\\VIEW_LAMPS_management_report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\programs\\vw\\my2022\\fpkb8\\vp-apps\\swc\\VIEW_Sound\\tst\\doc\\VIEW_SOUND_full_report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\programs\\vw\\my2022\\fpkb8\\vp-apps\\gs\\CXDR_GFX\\src\\tst\\doc\\UML_GEN_PResourcesManager_Report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\programs\\vw\\my2022\\fpkb8\\vp-apps\\lib\\LIB_Arithmetic\\tst\\doc\\LIB_ARITHMETIC_management_report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\programs\\vw\\my2022\\fpkb8\\vp-apps\\lib\\LIB_Assert\\tst\\doc\\LIB_ASSERTS_management_report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\programs\\vw\\my2022\\fpkb8\\vp-apps\\lib\\LIB_BAP\\tst\\doc\\LIB_BAP_Report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\programs\\vw\\my2022\\fpkb8\\vp-apps\\lib\\LIB_Cmp\\tst\\doc\\LIB_Cmp_Report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\programs\\vw\\my2022\\fpkb8\\vp-apps\\lib\\LIB_E2E\\tst1\\doc\\LIB_E2E_metrics_report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\programs\\vw\\my2022\\fpkb8\\vp-apps\\lib\\LIB_E2E\\tst2\\doc\\LIB_E2E_metrics_report.html",
    
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\programs\\vw\\my2022\\fpkb8\\vp-apps\\lib\\LIB_Hmi\\tst\\doc\\LIB_HMI_management_report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\programs\\vw\\my2022\\fpkb8\\vp-apps\\lib\\LIB_Math\\tst\\doc\\LIB_MATH_management_report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\programs\\vw\\my2022\\fpkb8\\vp-apps\\lib\\LIB_Mem\\tst\\doc\\LIB_MEM_management_report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\programs\\vw\\my2022\\fpkb8\\vp-apps\\lib\\LIB_RLE\\tst\\doc\\LIB_RLE_management_report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\programs\\vw\\my2022\\fpkb8\\vp-apps\\lib\\LIB_String\\tst\\doc\\LIB_STRING_management_report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\programs\\vw\\my2022\\fpkb8\\vp-apps\\lib\\LIB_Time\\tst\\doc\\LIB_TIME_management_report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\programs\\vw\\my2022\\fpkb8\\vp-apps\\cdd\\CXDR_Illum\\tst\\doc\\CXDR_ILLUM_metrics_report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\programs\\vw\\my2022\\fpkb8\\vp-apps\\cdd\\CXDR_SafeTTMonitor\\tst\\doc\\CXDR_SAFETTMONITOR_management_report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\programs\\vw\\my2022\\fpkb8\\vp-apps\\cdd\\CXDR_Sensors\\tst\\doc\\CXDR_SENSORS_metrics_report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\programs\\vw\\my2022\\fpkb8\\vp-apps\\cdd\\CXDR_Tank\\tst\\doc\\CXDR_TANK_management_report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\programs\\vw\\my2022\\fpkb8\\vp-apps\\cdd\\SRV_ComExt\\gen\\tst\\doc\\Report_SRV_ComExt_gen.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\programs\\vw\\my2022\\fpkb8\\vp-apps\\cdd\\SRV_ComExt_Safety\\tst\\SRV_COMEXT_SAFETY_management_report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\programs\\vw\\my2022\\fpkb8\\vp-apps\\cdd\\SRV_CsmH\\tst\\doc\\SRV_CsmH_Report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\programs\\vw\\my2022\\fpkb8\\vp-apps\\cdd\\SRV_KsExt\\doc\\SRV_KSEXT_Report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\programs\\vw\\my2022\\fpkb8\\vp-apps\\cdd\\SRV_MemTest\\tst\\doc\\SRV_MEMTEST_management_report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\programs\\vw\\my2022\\fpkb8\\vp-apps\\cdd\\SRV_Monitor\\tst\\doc\\STV_MONITOR_UT_management_report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\programs\\vw\\my2022\\fpkb8\\vp-apps\\cdd\\SRV_Power\\tst\\SRV_Power_Management_Report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\programs\\vw\\my2022\\fpkb8\\vp-apps\\cdd\\SRV_Reset\\tst\\SRV_RESET_management_report.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\programs\\vw\\my2022\\fpkb8\\vp-apps\\cdd\\SRV_Station\\tst\\doc\\Report_SRV_Station.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\programs\\vw\\my2022\\fpkb8\\vp-apps\\cdd\\SRV_Timegen\\tst\\doc\\Report_SRV_Timegen.html",
    r"C:\\jenkins\\workspace\\VW_DI_fpkb8\\VW_DI_fpkb8_UNIT_TEST\\programs\\vw\\my2022\\fpkb8\\vp-apps\\cdd\\SRV_Trace\\tst\\doc\\Report_SRV_Trace.html",  

]

async def exec_bat(path_to_bat):

    try:
        parent_dir = Path(path_to_bat)
        print(parent_dir.parent.absolute())
        os.chdir(parent_dir.parent.absolute())
    except Exception as e:
        print(f"Error finding the bat dir: {e}")

    try:
        print("----------------------------------------")
        print(f'Executing {path_to_bat}...')
        si = subprocess.STARTUPINFO()
        si.dwFlags |= subprocess.STARTF_USESHOWWINDOW
        proc = subprocess.Popen(path_to_bat,
                                stdout=subprocess.PIPE,
                                stderr=subprocess.PIPE,
                                creationflags=subprocess.CREATE_NEW_CONSOLE,
                                startupinfo=si)
        # print(proc.communicate())
        proc.communicate()

    except Exception as e:
        print(f'Error during execution: {e}')
    print('Bat file done!\n')
    print("----------------------------------------")

# async def run_all(workspace, report_dir, project):
#     bat_dir = await get_paths(workspace, report_dir, project)
#     return bat_dir


async def run_specified_bat_files(workspace):
    for bat_exe in bat_paths:
        await exec_bat(bat_exe)
    return 1
async def get_all_management_reports(report_dir):
    for man_report in man_reports:
        print("----------------------------------------")
        print(f'Copying {man_report}')
        try:
            copy(man_report, report_dir)
        except Exception as e:
            print(f"NOT FOUND REPROT: {man_report}")
            print(f"REASON: {e}")


def parse_html(report_dir):
    os.chdir(report_dir)
    FINAL_REPORT = ''
    FILTER = ''

    with open(JOB_DIR + "\\report.html", 'w+') as final_report:
        '''Begin HTML'''
        with open(JOB_DIR + '\\template.html', 'r') as template:
            template_text = template.read()
        dur = 0
        update = 0
        for report in man_reports:
            print("Parsing: ", report.split("\\")[-1])
            print("Dir: "), report.split("\\")[-1]
            report_dir = report.split("\\")[-1].strip(".html.html")
            if report_dir.endswith("Repor"):
                report_dir = report_dir+"t"
            elif report_dir.endswith("repor"):
                report_dir = report_dir+"t"
            parent = "-"
            if parent not in FILTER:
                FILTER += '<option value="p_' + parent + '">' + parent + '</option>\n\t\t\t\t'

            unit_test_name = report.split("\\")[-1]
            full_unit_name = unit_test_name
            # unit_test_name = unit_test_name.strip('HT_')
            unit_test_name = unit_test_name.strip('.html.html')
            if unit_test_name.endswith("Repor"):
                unit_test_name = unit_test_name+"t"
            elif unit_test_name.endswith("repor"):
                unit_test_name = unit_test_name+"t"
            print(unit_test_name)
            FINAL_REPORT += '\n\t<!--=====' + unit_test_name + '=====-->\n'

            tr_classes = "p_Applications " + unit_test_name + " result_row"

            FINAL_REPORT += '\n\t<tr class="' + tr_classes + '">\n'

            FINAL_REPORT += '\t\t<td bgcolor="#CCD8EE"><strong>' + report_dir + '</strong></td>\n'

            #FINAL_REPORT += '\t\t<td bgcolor="#CCD8EE"><strong>' + "-" + '</strong></td>\n'
            #FINAL_REPORT += '\t\t<td bgcolor="#CCD8EE"><strong>' + unit_test_name + '</strong></td>\n'
            try:
                subprograms = get_SUBPROGRAMS(report)
                if subprograms is None:
                    subprograms = '<td bgcolor="#FFFFFF">No subprograms Exist</td>'
                print(subprograms)

                complexity = get_COMPLEXITY(report)
                if complexity is None:
                    complexity = '<td bgcolor="#FFFFFF">No subprograms Exist</td>'
                print(complexity)

                testcases = get_TESTCASES(report)
                if testcases is None:
                    testcases = '<td bgcolor="#FFFFFF">No Execution Results Exist</td>'
                print(testcases)

                expecteds = get_EXPECTEDS(report)
                if expecteds is None:
                    expecteds = '<td bgcolor="#FFFFFF">No Execution Results Exist</td>'
                print(expecteds)

                statement_coverage = get_STATEMENT_COVERAGE(report)
                if statement_coverage is None:
                    statement_coverage = '<td bgcolor="#FFFFFF">No Statement Exist</td>'
                print(statement_coverage)

                branch_coverage = get_BRANCH_COVERAGE(report)
                if branch_coverage is None:
                    branch_coverage = '<td bgcolor="#FFFFFF">No Statement Exist</td>'
                print(branch_coverage)

                pairs_coverage = get_PAIRS_COVERAGE(report)
                if pairs_coverage is None:
                    pairs_coverage = '<td bgcolor="#FFFFFF">No Pairs Exist</td>'
                print(pairs_coverage)
            except:
                pass

            try:
                FINAL_REPORT += subprograms
                FINAL_REPORT += complexity
                FINAL_REPORT += statement_coverage
                FINAL_REPORT += branch_coverage
                FINAL_REPORT += pairs_coverage
                FINAL_REPORT += testcases
                FINAL_REPORT += expecteds
            except TypeError:
                pass

            try:
                #FINAL_REPORT += '<td align="right"><strong>' 'n/a' + '</strong></td>'
                update += 1
            except:
                #FINAL_REPORT += '<td align="right"><strong>' + 'n/a' + '</strong></td>'
                update += 1
            #FINAL_REPORT += '<td align="right"><strong>' + '' + '</strong></td>'
            try:
                os.chdir('C:\\Jenkins-Slave\\workspace\\E2_MY21_VP_Unit_test\\report')
                report_link = './management_report.htmls/' + full_unit_name
                #FINAL_REPORT += '\t\t<td align="center" bgcolor="#CCD8EE"><a target="_blank" href="' + report_link + '">Link</a></td>\n '
            except:
                pass
        try:
            template_text = template_text.replace('<[HEADINGS]>', open('./report/Headings.txt').read())
        except:
            pass

        template_text = template_text.replace('<[CONTENTS]>', FINAL_REPORT)
        template_text = template_text.replace('<[PARENTS_FILTER]>', FILTER)
        template_text = template_text.replace('<[FOOTER_LINES]>', '''
        <td bgcolor="#FB9316" align='center'><b>Summary</b></td>
        <td bgcolor="#FB9316">_</td>
        <td bgcolor="#FB9316"><b>''' + str(len(man_reports)) + "/" + str(len(man_reports)) + '''</b></td>
        <td bgcolor="#FB9316" align='center'>N</td>
        <td bgcolor="#FB9316" align='center'>N</td>
        <td bgcolor="#FB9316" align='center'>N</td>
        <td bgcolor="#FB9316" align='center'>N</td>
        <td bgcolor="#FB9316" align='center'>N</td>
        
        ''')
        # print '#################################'
        # print FINAL_REPORT
        FINAL_REPORT += '\t\t<td align="right"><strong>Unkown</strong></td>\n'
        FINAL_REPORT += '\t</tr>\n'

        final_report.write(template_text)


def get_TESTCASES(specific_html):
    try:
        with open(specific_html, 'r') as report:
            for line in report:
                split = line.split('<tr')
                for el in split:
                    if "testcases" in el.lower():
                        # print(el)
                        res = el.split('</td>')[1] + '</td>'
                        if "</tr></table></td>" in res:
                            res = '<td bgcolor="#FFFFFF">n/a</td>'
                        if res is None:
                            res ='<td bgcolor="#FFFFFF">n/a</td>'
                        return res
        
    except IOError:
        print("NOT FOUND: ", specific_html.split("\\")[-1])
        res = '<td bgcolor="##FFFFFF">n/a</td>'
        return res


def get_EXPECTEDS(specific_html):
    try:
        with open(specific_html, 'r') as report:
            for line in report:
                split = line.split('<tr')
                for el in split:
                    if "expecteds" in el.lower():
                        res = el.split('</td>')[1] + '</td>'
                        if "</tr></table></td>" in res:
                            res = '<td bgcolor="#FFFFFF">n/a</td>'
                        if res is None:
                            res ='<td bgcolor="#FFFFFF">n/a</td>'
                        return res
       
    except IOError:
        print("NOT FOUND: ", specific_html.split("\\")[-1])
        res = '<td bgcolor="##FFFFFF">n/a</td>'
        return res


def get_STATEMENT_COVERAGE(specific_html):
    try:
        if specific_html == "UTEST_UIVEHICLE_VARIANT_Full_R":
            # <td bgcolor="#CCFFCC">43&nbsp;/&nbsp;43&nbsp;(100%)</td>
            # </tr></table></td>
            with open(specific_html, 'r') as report:
                for line in report:
                    split = line.split('<tr')
                    for el in split:
                        if "statement" in el.lower():
                            res = el.split('</td>')[1] + '</td>'
                            return res.strip("</tr></table></td>")
    except IOError:
        print("NOT FOUND: ", specific_html.split("\\")[-1])
        res = '<td bgcolor="##FFFFFF">n/a</td>'
        return res

    try:
        with open(specific_html, 'r') as report:
            for line in report:
                split = line.split('<tr')
                for el in split:
                    if "statement" in el.lower():
                        res = el.split('</td>')[1] + '</td>'
                        if "</tr></table></td>" in res:
                            res = '<td bgcolor="#FFFFFF">n/a</td>'
                        if res is None:
                            res ='<td bgcolor="#FFFFFF">n/a</td>'
                        return res
        
        
    except IOError:
        print("NOT FOUND: ", specific_html.split("\\")[-1])
        res = '<td bgcolor="##FFFFFF">n/a</td>'
        return res


def get_BRANCH_COVERAGE(specific_html):
    try:
        with open(specific_html, 'r') as report:
            for line in report:
                split = line.split('<tr')

                for el in split:
                    if "branch" in el.lower():
                        res = el.split('</td>')[1] + '</td>'
                        if "</tr></table></td>" in res:
                            res = '<td bgcolor="#FFFFFF">n/a</td>'
                        if res is None:
                            res ='<td bgcolor="#FFFFFF">n/a</td>'
                        return res
        

    except IOError:
        print("NOT FOUND: ", specific_html.split("\\")[-1])
        res = '<td bgcolor="##FFFFFF">n/a</td>'
        return res


def get_PAIRS_COVERAGE(specific_html):
    try:
        with open(specific_html, 'r') as report:
            for line in report:
                split = line.split('<tr')
                for el in split:

                    if "pair" in el.lower() or "pairs" in el.lower():
                        res = el.split('</td>')[1] + '</td>'
                        if "</tr></table></td>" in res:
                            res = '<td bgcolor="#FFFFFF">n/a</td>'
                        if res is None:
                            res ='<td bgcolor="#FFFFFF">n/a</td>'
                        return res
        
    
    except IOError:
        print("NOT FOUND: ", specific_html.split("\\")[-1])
        res = '<td bgcolor="#FFFFFF">n/a</td>'
        return res


def get_SUBPROGRAMS(specific_html):
    try:
        with open(specific_html, 'r') as report:
            for line in report:
                split = line.split('<tr')
                for el in split:
                    if "grand" in el.lower() and "totals" in el.lower():
                        res = el.split('</td>')[1] + '</td>'
                        if "</tr></table></td>" in res:
                            res = '<td bgcolor="#FFFFFF">n/a</td>'
                        if res is None:
                            res ='<td bgcolor="#FFFFFF">n/a</td>'
                        
                        return res
       
    except IOError:
        print("NOT FOUND: ", specific_html.split("\\")[-1])
        res = '<td bgcolor="##FFFFFF">n/a</td>'
        return res


def get_COMPLEXITY(specific_html):
    try:
        with open(specific_html, 'r') as report:
            for line in report:
                split = line.split('<tr')
                for el in split:
                    if "grand" in el.lower() and "totals" in el.lower():
                        res = el.split('</td>')[2] + '</td>'
                        if "</tr></table></td>" in res:
                            res = '<td bgcolor="#FFFFFF">n/a</td>'
                        if res is None:
                            res ='<td bgcolor="#FFFFFF">n/a</td>'
                        
                        return res
        

    except IOError:
        print("NOT FOUND: ", specific_html.split("\\")[-1])
        res = '<td bgcolor="##FFFFFF">n/a</td>'
        return res


async def main():
    # parse arguments

    os.chdir(JOB_DIR)
    if os.path.isdir(JOB_DIR + "\\Full_reports"):
        shutil.rmtree(JOB_DIR + "\\Full_reports")
        os.mkdir(JOB_DIR + "\\Full_reports")
        report_dir = JOB_DIR + "\\Full_reports"
    else:
        os.mkdir(JOB_DIR + "\\Full_reports")
        report_dir = JOB_DIR + "\\Full_reports"

    parser = argparse.ArgumentParser()
    parser.add_argument("--workspace", help="specify workspace")
    args = parser.parse_args()
    workspace = args.workspace

    print(f'Script folder: {JOB_DIR}')
    print(f'Workspace folder: {workspace}')

    # call run_all
    # await run_specified_bat_files(workspace)
    # await get_all_management_reports(report_dir)
    parse_html(report_dir)


if __name__ == '__main__':
    asyncio.run(main())