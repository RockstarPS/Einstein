@echo off
cls

echo Generating ARXML !

if not exist "..\Arxml" mkdir "..\Arxml"
if not exist "..\generated_InstancEr_out\Swc" mkdir "..\generated_InstancEr_out\Swc"
if exist "..\UML\bin" rmdir /S /Q "..\UML\bin"


@echo on

"C:\Program Files\Java\jre7\bin\java.exe" ^
-jar ..\..\..\di.module.hld.tools.a2t\TOOLS\A2TOM\SWC_ARXML_Gen\toAutosar.jar ^
-instanceName=bmw_mic_System ^
-srcdir "..\UML\platform\A2T_TC_out;..\UML\bmw_mic\Platform_IC_out;..\UML\bmw_mic\bmw_mic_instancer"  ^
-arxmlTargetFolder "..\Arxml" ^
-swcCTargetFolder "..\generated_InstancEr_out\Swc" ^
-arxmlVersion 4.2.1 

@echo off
echo.
echo.

echo Updating timeout flags !

..\..\..\di.module.hld.tools.a2t\ARXML_PROCESS\ARXMLTOUML\ArxmlToUml "..\UML\bmw_mic\bmw_mic\bmw_mic_ARXML_Update.gencfg"

echo Generation Done !


@rem > .\generated_InstancEr_out\genExecution.log

@Rem pause

