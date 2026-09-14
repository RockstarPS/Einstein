echo Generate files from tools archived in RTC
cd ..\autogen\

SET WS_ROOT=..\..\..\..
SET GDT_TOOL_PATH=%WS_ROOT%\ui.core.gdt.doc\hmi.gfx.manager.02\release

SET APP_PATH=%WS_ROOT%\ui.core.iceapple.test\iceapple.gdt.test.fw\openvg_target

SET LANG_TOOL_PATH=%WS_ROOT%\ui.core.iceapple.doc\language.core.01\language_encoder_tool\
SET MENU_TOOL_PATH=%WS_ROOT%\ui.core.iceapple.doc\menu.core.01\menu_configurator_tool
SET POPUP_TOOL_PATH=%WS_ROOT%\ui.core.iceapple.doc\popup.core.02\Popup_Configurator\

REM echo %GDT_TOOL_PATH%
REM echo Unzipping GDT tool
REM "c:\Program Files\7-Zip\7z.exe" x %GDT_TOOL_PATH%\gfx_mgr02_gdt.zip  -o%GDT_TOOL_PATH%\gfx_mgr02_gdt\ -y > log.txt

REM echo Generating GDT files

REM del ..\autogen\*.* /q
REM call %GDT_TOOL_PATH%\gfx_mgr02_gdt\gfx_cmdline_coder.exe  %APP_PATH%\graphics\ia_gdt_test.xml 

REM echo Rename hmi_logic_state_handler_template
REM rename %APP_PATH%\autogen\hmi_logic_state_handler_template.$c hmi_logic_state_handler_template.c
REM rmdir /s /q %GDT_TOOL_PATH%\gfx_mgr02_gdt

echo Unzipping Language Encoder tool
"c:\Program Files\7-Zip\7z.exe" x %LANG_TOOL_PATH%\LanguageEncoder.zip  -o%LANG_TOOL_PATH%\ -y > log.txt

echo Generating Language Encoder files
call %LANG_TOOL_PATH%\LanguageEncoder.exe  %APP_PATH%\language\exercise.cfg 
del %LANG_TOOL_PATH%\*.txt 
del %LANG_TOOL_PATH%\*.dll
del %LANG_TOOL_PATH%\*.exe

echo Unzipping Menu core tool
"c:\Program Files\7-Zip\7z.exe" x %MENU_TOOL_PATH%\MenuConfigurator.zip  -o%MENU_TOOL_PATH%\ -y > log.txt

echo Generating Menu core files
call %MENU_TOOL_PATH%\MenuConfigurator.exe  %APP_PATH%\menu\ia_hmi_menu_cfg.xml %APP_PATH%\graphics\ia_gdt_test.xml  IGDT false
del %APP_PATH%\hmi_menu_application.c
del %APP_PATH%\hmi_menu_application.h
del %MENU_TOOL_PATH%\*.txt 
del %MENU_TOOL_PATH%\*.dll
del %MENU_TOOL_PATH%\*.exe

echo Unzipping popup core tool
"c:\Program Files\7-Zip\7z.exe" x %POPUP_TOOL_PATH%\Popup_configurator.zip  -o%POPUP_TOOL_PATH%\ -y > log.txt

echo Generating popup core files
call %POPUP_TOOL_PATH%\Popup_configurator.exe  %APP_PATH%\popup\ia_popup_core_cfg.xml 1 
del %POPUP_TOOL_PATH%\*.txt 
del %POPUP_TOOL_PATH%\*.dll
del %POPUP_TOOL_PATH%\*.exe


echo Auto code generation success

Rem Assumed all visteon PCs have 7z.exe installed in "c:\Program Files\7-Zip\"
Rem Redirect the 7z.exe's log into a temp file "log.txt"
Rem Delete the extracted files once code generated. 