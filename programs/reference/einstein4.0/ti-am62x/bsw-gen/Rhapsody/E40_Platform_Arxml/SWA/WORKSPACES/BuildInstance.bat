@echo off
cls

echo Generating INSTANCER !

..\..\..\di.module.hld.tools.a2t\ARXML_PROCESS\INSTANCER\InstancerGenerator "..\UML\E40_Platform\E40_Platform_Generation.gencfg"

echo Generating ARXML !

if not exist "..\Arxml" mkdir "..\Arxml"
if not exist "..\..\generated_InstancEr_out\Swc" mkdir "..\generated_InstancEr_out\Swc"
if exist "..\UML\E40_Platform\bin" rmdir /S /Q "..\UML\E40_Platform\bin"

::cd /d %mypath%

echo CopyInerclass File  !
if exist "..\UML\E40_Platform\E40_Platform_Inerclass" del /Q "..\UML\E40_Platform\E40_Platform_Inerclass\E40_Platform.inerclass"
if exist "..\UML\E40_Platform\E40_Platform" COPY "..\UML\E40_Platform\E40_Platform\E40_Platform.inerclass" "..\UML\E40_Platform\E40_Platform_Inerclass"

::cd /d %mypath%

@echo on

"C:\Program Files\Java\jre7\bin\java.exe" ^
-jar ..\..\..\di.module.hld.tools.a2t\TOOLS\A2TOM\SWC_ARXML_Gen\toAutosar.jar ^
-instanceName=E40_Platform_System ^
-srcdir "..\UML\E40_Platform\A2T_TC_out;..\UML\E40_Platform\E40_Platform_out;..\UML\E40_Platform\E40_Platform\E40_Platform_instancer"  ^
-arxmlTargetFolder "..\Arxml" ^
-swcCTargetFolder "..\generated_InstancEr_out\Swc" ^
-arxmlVersion 4.2.1 

@echo off
echo.
echo.

echo Generation Done !

..\..\..\di.module.hld.tools.a2t\ARXML_PROCESS\ARXMLTOUML\ArxmlToUml "..\UML\E40_Platform\E40_Platform_ARXML_Update.gencfg"

@rem > .\generated_InstancEr_out\genExecution.log

@Rem pause

