echo Generate files from tools archived in RTC
cd ..\autogen\

echo Unzipping GDT tool
cd ..\..\..\..\..\..\ui.core.gdt.doc\hmi.gfx.manager.02\release
"c:\Program Files\7-Zip\7z.exe" x gfx_mgr02_gdt.zip  -y > log.txt
cd ..\..\..\ui.core.gdt.test\hmi.gfx.manager.02\test.harness\dcu_rotation_testframework\demo_app\autogen



echo Generating GDT files
call ..\..\..\..\..\..\ui.core.gdt.doc\hmi.gfx.manager.02\release\gfx_cmdline_coder.exe  .\Gfx_DCU_Rotation.xml 
del ..\..\..\..\..\..\ui.core.gdt.doc\hmi.gfx.manager.02\release\*.txt 
del ..\..\..\..\..\..\ui.core.gdt.doc\hmi.gfx.manager.02\release\*.dll
del ..\..\..\..\..\..\ui.core.gdt.doc\hmi.gfx.manager.02\release\*.exe
rmdir /s /q ..\..\..\..\..\..\ui.core.gdt.doc\hmi.gfx.manager.02\release\icons

echo Unzipping GDT tool
cd ..\..\..\..\..\..\ui.core.iceapple.doc\language.core.01\language_encoder_tool
"c:\Program Files\7-Zip\7z.exe" x LanguageEncoder.zip  -y > log.txt
cd ..\..\..\ui.core.gdt.test\hmi.gfx.manager.02\test.harness\dcu_rotation_testframework\demo_app\autogen

call ..\..\..\..\..\..\ui.core.iceapple.doc\language.core.01\language_encoder_tool\LanguageEncoder.exe  .\hdg03_test.cfg 
del ..\..\..\..\..\..\ui.core.iceapple.doc\language.core.01\language_encoder_tool\*.txt 
del ..\..\..\..\..\..\ui.core.iceapple.doc\language.core.01\language_encoder_tool\*.dll
del ..\..\..\..\..\..\ui.core.iceapple.doc\language.core.01\language_encoder_tool\*.exe

echo Auto code generation success

cd ..\make\


Rem Assumed all visteon PCs have 7z.exe installed in "c:\Program Files\7-Zip\"
Rem Redirect the 7z.exe's log into a temp file "log.txt"
Rem Delete the extracted files once code generated. 