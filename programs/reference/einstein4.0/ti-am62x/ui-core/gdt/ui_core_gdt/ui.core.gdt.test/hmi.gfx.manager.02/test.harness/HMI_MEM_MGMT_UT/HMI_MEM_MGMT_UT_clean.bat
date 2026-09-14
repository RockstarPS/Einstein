@echo off
setlocal enabledelayedexpansion

:: Specify unit test environment
set unit_test_env=HMI_MEM_MGMT_UT

:: Specify the files to keep
set exclude_file1="%unit_test_env%.bat"
set exclude_file2="%unit_test_env%.tst"
set exclude_file3="%unit_test_env%.env"
set exclude_file4="%unit_test_env%_management_report.html"

set exclude_dir1=stub
:: Get the name of the current batch file
set current_script=%~nx0

:: Set the target directory
set target_dir="."

:: Delete all files except the specified ones and the script itself
for %%f in ("%target_dir%\*") do (
    if /i not "%%~nxf"==!exclude_file1! (
        if /i not "%%~nxf"==!exclude_file2! (
            if /i not "%%~nxf"==!exclude_file3! (
                if /i not "%%~nxf"==!exclude_file4! (
                    if /i not "%%~nxf"=="%current_script%" (
                        del /q /f "%%f" 2>nul
                    )
                )
            )
        )
    )
)

:: Delete all folders
for /d %%d in ("%target_dir%\*") do (
  if /i not "%%~nxd"=="!exclude_dir1!" (
    rd /s /q "%%d"
  )
)

echo Cleanup complete.
