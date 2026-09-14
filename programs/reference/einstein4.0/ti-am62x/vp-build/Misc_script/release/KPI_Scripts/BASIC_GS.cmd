@echo off
SET GBUILDPATH=C:\ghs\comp_201714\
Set HY_Path1="C:\jenkins\workspace\VW_DI_fpkb10\VW_FPKB10_MY2023_EP29828_Domain\BASIC_DELIVERY\BUILD_GS\BUILD"
If Exist %HY_Path1%\OUTPUT rd /q /s %HY_Path1%\OUTPUT

ChDir /D "%HY_Path1%\MULTI"
If Not Exist %HY_Path1%\OUTPUT\*.* MkDir %HY_Path1%\OUTPUT
set START_TIME=%time%
set TOP_GPJ=MQB_GFX_BUILD.gpj
set LOG_FILE=build.log
set BUILD_CFG=rls
set CLEAN_OPT=

if exist C:\ghs\comp_201714\gbuild.exe (
    set BUILD_EXE=C:\ghs\comp_201714\gbuild
) else (
    echo "No compiler found!"
)

Echo #### 3333
%GBUILDPATH%gbuild.exe -parallel=%NUMBER_OF_PROCESSORS% -top %TOP_GPJ% -cfg=%BUILD_CFG% -nice %CLEAN_OPT% 2<&1 | tee %LOG_FILE%
Echo #### 4444


cd ..\MULTI_RESOURCE_DOWNLOADER
%BUILD_EXE% -parallel=%NUMBER_OF_PROCESSORS% -top MQB_GFX_RESOURCE_DOWNLOADER.gpj -cfg=dbg -nice -cleanfirst 2<&1 | tee %LOG_FILE%
cd ..\MULTI

copy "%HY_Path1%\OUTPUT\release\MQB_GFX_INTEGRITY"      	 	  "%HY_Path1%\OUTPUT\"
copy "%HY_Path1%\SRC\appl\SUBSYS\HMI\GeneratedResources\GFX_Res.BIN"      "%HY_Path1%\OUTPUT\"
copy "%HY_Path1%\SRC\appl\SUBSYS\HMI\hmi_app\HMI\generated_code\hmi.bin"      "%HY_Path1%\OUTPUT\"

Set HY_Rslt_OK=TRUE
If Not Exist "%HY_Path1%\OUTPUT\MQB_GFX_INTEGRITY" Set HY_Rslt_OK=FALSE
If Not Exist "%HY_Path1%\OUTPUT\GFX_Res.BIN" Set HY_Rslt_OK=FALSE
If Not Exist "%HY_Path1%\OUTPUT\hmi.bin" Set HY_Rslt_OK=FALSE
set TOP_GPJ=
set LOG_FILE=
set BUILD_CFG=
set CLEAN_OPT=

If %HY_Rslt_OK% == FALSE Goto HY_Exit_ERR_CMPL
Echo #### GSApplication's .elf File Generated Successfully ^^!

:HY_Exit
@Echo ====} End of FPK_BASIC_GS build - SUCCESS {====
Echo #### %TIME%
pause
Exit 0

:HY_Exit_ERR_CMPL
@Echo HY-CMPL-HEX-CMPL-APP: Some Resultant Files From Compilation Process (In "OUTPUT" Folder) Are NOT Produced (Properly), ERROR ^^!^^!
Goto HY_Exit_Err

:HY_Exit_Err
@Echo ====} End {====
Echo #### %TIME%
pause
Exit 64







