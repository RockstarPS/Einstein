@echo off
:: Set current path to a variable
set "mypath=%~dp0%


:: cd generated_InstancEr_out

:: rmdir /s /q Swc

cd /d %mypath%

cd UML\bmw_mic

rmdir /s /q A2T_TC_out
rmdir /s /q A2T_TC_rpy
rmdir /s /q bmw_mic_auto_rpy
rmdir /s /q bmw_mic_out
rmdir /s /q RhapsodyChecker

del /q *.log
del /q *.ehl
del /q *.save
del /q *.xmi
del /q *.rpwx
del /q bmw_mic_Inerclass

cd bmw_mic\bmw_mic_instancer

del *.instancer

cd /d %mypath%

::rmdir /s /q generated_InstancEr_out

echo Cleaned.!
Pause