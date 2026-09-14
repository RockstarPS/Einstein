@echo off
SET GBUILDPATH=C:\ghs\comp_201714\
Set HY_Path1="C:\jenkins\workspace\VW_DI_fpkb10\VW_FPKB10_MY2023_EP29828_Domain\BASIC_DELIVERY\BUILD_PS\BUILD"

ChDir /D "%HY_Path1%\MULTI"
If Not Exist %HY_Path1%\OUTPUT\*.* MkDir %HY_Path1%\OUTPUT
set START_TIME=%time%
set TOP_GPJ=release.gpj
set LOG_FILE=build.log


IF EXIST C:\ghs\comp_201714\gbuild.exe (
    SET BUILD_EXE=C:\ghs\comp_201714\gbuild
) else (
    echo "No compiler found!"
)

Echo #### 3333
%GBUILDPATH%gbuild.exe -parallel=%NUMBER_OF_PROCESSORS% -top %TOP_GPJ% %1 %2 %3 %4 %5 2<&1 | tee %LOG_FILE%
Echo #### 4444

copy "%HY_Path1%\MULTI\release\mqb2020-M4.elf"      		  "%HY_Path1%\OUTPUT\"
copy "%HY_Path1%\MULTI\release\MQB_EEP_UNPROTECTED.elf"      		  "%HY_Path1%\OUTPUT\"

Set HY_Rslt_OK=TRUE
If Not Exist "%HY_Path1%\OUTPUT\mqb2020-M4.elf" Set HY_Rslt_OK=FALSE
If Not Exist "%HY_Path1%\OUTPUT\MQB_EEP_UNPROTECTED.elf" Set HY_Rslt_OK=FALSE
set TOP_GPJ=
set LOG_FILE=

echo %HY_Rslt_OK%
rem pause 1

If %HY_Rslt_OK% == FALSE Goto HY_Exit_ERR_CMPL
Echo #### PS Application's .elf File Generated Successfully ^^!

:HY_Exit
@Echo ====} End of FPK_BASIC_PS build - SUCCESS {====
Echo #### %TIME%
echo %HY_Rslt_OK%
rem pause 2
Exit 0

:HY_Exit_ERR_CMPL
@Echo HY-CMPL-HEX-CMPL-APP: Some Resultant Files From Compilation Process (In "OUTPUT" Folder) Are NOT Produced (Properly), ERROR ^^!^^!
Goto HY_Exit_Err

:HY_Exit_Err
@Echo ====} End {====
Echo #### %TIME%
echo %HY_Rslt_OK%
rem pause 3
Exit 64

pause





