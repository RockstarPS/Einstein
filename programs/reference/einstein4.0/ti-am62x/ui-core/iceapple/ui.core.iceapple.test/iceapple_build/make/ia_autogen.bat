echo Generate files from tools archived in RTC
cd ..\..\autogen\

echo Unzipping language encoder tool
cd ..\..\..\ui.core.iceapple.doc\language.core.01\language_encoder_tool
"c:\Program Files\7-Zip\7z.exe" x LanguageEncoder.zip  -y > log.txt
cd ..\..\..\ui.core.iceapple.test\iceapple_build\autogen
echo Generating language encoder files
call ..\..\..\ui.core.iceapple.doc\language.core.01\language_encoder_tool\LanguageEncoder.exe  .\LanguageModelConfiguration.cfg
del ..\..\..\ui.core.iceapple.doc\language.core.01\language_encoder_tool\*.txt 
del ..\..\..\ui.core.iceapple.doc\language.core.01\language_encoder_tool\*.dll
del ..\..\..\ui.core.iceapple.doc\language.core.01\language_encoder_tool\*.exe


echo Unzipping menu configurator tool
cd ..\..\..\ui.core.iceapple.doc\menu.core.01\menu_configurator_tool
"c:\Program Files\7-Zip\7z.exe" x MenuConfigurator.zip -y > log.txt
cd ..\..\..\ui.core.iceapple.test\iceapple_build\autogen
echo Generating menu configurator files
call ..\..\..\ui.core.iceapple.doc\menu.core.01\menu_configurator_tool\MenuConfigurator.exe  .\MenuModelConfiguration.xml .\MenuModelGDT.xml IGDT false
del ..\..\..\ui.core.iceapple.doc\menu.core.01\menu_configurator_tool\*.txt 
del ..\..\..\ui.core.iceapple.doc\menu.core.01\menu_configurator_tool\*.dll
del ..\..\..\ui.core.iceapple.doc\menu.core.01\menu_configurator_tool\*.exe
rmdir ..\..\..\ui.core.iceapple.doc\menu.core.01\menu_configurator_tool\GDTParser /S

echo Unzipping popup configurator tool
cd ..\..\..\ui.core.iceapple.doc\popup.core.02\Popup_Configurator
"c:\Program Files\7-Zip\7z.exe" x Popup_configurator.zip -y > log.txt
cd ..\..\..\ui.core.iceapple.test\iceapple_build\autogen
echo Generating popup configurator files
call ..\..\..\ui.core.iceapple.doc\popup.core.02\Popup_Configurator\Popup_configurator.exe .\PopupModelConfiguration.xml  
del ..\..\..\ui.core.iceapple.doc\popup.core.02\Popup_Configurator\*.txt 
del ..\..\..\ui.core.iceapple.doc\popup.core.02\Popup_Configurator\*.dll
del ..\..\..\ui.core.iceapple.doc\popup.core.02\Popup_Configurator\*.exe

echo Auto code generation success

cd ..\src\ui_ia_build


Rem Assumed all visteon PCs have 7z.exe installed in "c:\Program Files\7-Zip\"
Rem Redirect the 7z.exe's log into a temp file "log.txt"
Rem Delete the extracted files once code generated. 