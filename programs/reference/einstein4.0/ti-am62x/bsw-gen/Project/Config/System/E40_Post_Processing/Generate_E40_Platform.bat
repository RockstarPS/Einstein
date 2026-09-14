@echo off
set VaseDir="C:\Program Files (x86)\Vector AUTOSAR Scripting Engine\Bin"

REM set VaseDir="..\..\..\di.module.hld.tools.a2t\ARXML_PROCESS\VASE\Bin"
set SystemName="E40_Platform_System"
%VaseDir%\Vector.DaVinci.Vase.exe  --arxml="E40_Platform_System.arxml" --postfix=updated --python=ProcessArxml.py --uservar=config.xml --define=EV_SystemName#%SystemName%

rem del ..\ARXML\FordPdc_System.arxml
rem rename ..\ARXML\FordPdc_System_updated.arxml FordPdc_System.arxml






