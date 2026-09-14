@echo off
echo ========================================
echo    FltM ConfiguratorTool - EXE Builder
echo ========================================
echo.

echo Installing dependencies...
pip install pyinstaller pandas jinja2 openpyxl

echo.
echo Building executable...
pyinstaller --onefile --add-data "PythonScript;PythonScript" --hidden-import pandas --hidden-import jinja2 --hidden-import openpyxl --name "FltM_ConfiguratorTool" main.py

echo.
echo ========================================
echo Build completed!
echo.
echo Executable location: dist\FltM_ConfiguratorTool.exe
echo.
echo Press any key to exit...
pause >nul