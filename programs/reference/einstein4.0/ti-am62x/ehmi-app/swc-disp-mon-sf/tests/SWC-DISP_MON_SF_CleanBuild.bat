@echo off
:: Set the folder and file names relative to the current directory
set folderPath=%~dp0SWC-DISP-MON-SF
set file1Path=%~dp0CCAST_.CFG
set file2Path=%~dp0commands.tmp
set file3Path=%~dp0quickparse.error

:: Delete the two files
del /F /Q "%file1Path%"
del /F /Q "%file2Path%"
del /F /Q "%file3Path%"

:: Delete the folder and its contents
rmdir /S /Q "%folderPath%"

echo Folder and files have been deleted.
pause
