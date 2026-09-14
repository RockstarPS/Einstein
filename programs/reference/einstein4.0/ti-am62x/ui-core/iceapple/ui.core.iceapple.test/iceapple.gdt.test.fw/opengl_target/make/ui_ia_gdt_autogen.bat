echo Generate files from tools archived in RTC

SET WS_ROOT=..\..\..\..
SET GDT_TOOL_PATH=%WS_ROOT%\ui.core.gdt.doc\hmi.gfx.manager.02\release
SET APP_PATH=%WS_ROOT%\ui.core.iceapple.test\iceapple.gdt.test.fw\opengl_target

SET LANG_TOOL_PATH=%WS_ROOT%\ui.core.iceapple.doc\language.core.01\language_encoder_tool\

echo Rename hmi_logic_state_handler_template
rename %APP_PATH%\autogen\hmi_logic_state_handler_template.$c hmi_logic_state_handler_template.c
rmdir /s /q %GDT_TOOL_PATH%\gfx_mgr02_gdt

echo Unzipping Language Encoder tool
"c:\Program Files\7-Zip\7z.exe" x %LANG_TOOL_PATH%\LanguageEncoder.zip  -o%LANG_TOOL_PATH%\ -y > log.txt

echo Generating Language Encoder files
call %LANG_TOOL_PATH%\LanguageEncoder.exe  %APP_PATH%\language\lang_test.cfg 
del %LANG_TOOL_PATH%\*.txt 
del %LANG_TOOL_PATH%\*.dll
del %LANG_TOOL_PATH%\*.exe

echo Auto code generation success


Rem Assumed all visteon PCs have 7z.exe installed in "c:\Program Files\7-Zip\"
Rem Redirect the 7z.exe's log into a temp file "log.txt"
Rem Delete the extracted files once code generated. 