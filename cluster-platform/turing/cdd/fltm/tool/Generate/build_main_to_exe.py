#!/usr/bin/env python3
"""
Automated build script to convert main.py to FltM_ConfiguratorTool.exe

This script automates the entire process of creating a standalone executable
from the FltM ConfiguratorTool Python project using PyInstaller.
"""

import os
import sys
import subprocess
from pathlib import Path
import shutil

def check_requirements():
    """Check if required files and directories exist."""
    print("🔍 Checking project requirements...")
    
    required_files = ['main.py']
    required_dirs = ['PythonScript']
    
    missing = []
    
    for file in required_files:
        if not os.path.exists(file):
            missing.append(f"File: {file}")
    
    for dir in required_dirs:
        if not os.path.exists(dir):
            missing.append(f"Directory: {dir}")
    
    if missing:
        print("❌ Missing required files/directories:")
        for item in missing:
            print(f"   - {item}")
        return False
    
    print("✅ All required files and directories found")
    return True

def install_dependencies():
    """Install required Python packages."""
    print("\n📦 Installing dependencies...")
    
    packages = [
        'pyinstaller',
        'pandas',
        'jinja2', 
        'openpyxl'
    ]
    
    try:
        for package in packages:
            print(f"Installing {package}...")
            result = subprocess.run([
                sys.executable, '-m', 'pip', 'install', package
            ], capture_output=True, text=True)
            
            if result.returncode != 0:
                print(f"❌ Failed to install {package}: {result.stderr}")
                return False
        
        print("✅ All dependencies installed successfully")
        return True
        
    except Exception as e:
        print(f"❌ Error installing dependencies: {e}")
        return False

def create_spec_file():
    """Create PyInstaller spec file."""
    print("\n📝 Creating PyInstaller spec file...")
    
    spec_content = """# -*- mode: python ; coding: utf-8 -*-

block_cipher = None

a = Analysis(
    ['main.py'],
    pathex=['.'],
    binaries=[],
    datas=[
        ('PythonScript', 'PythonScript'),
    ],
    hiddenimports=[
        'pandas',
        'jinja2',
        'openpyxl',
        'pathlib',
        'typing',
        'warnings',
        'PythonScript.fltm_process',
        'PythonScript.fltm_soc_process',
        'PythonScript.fltm_soc_dcc_process',
        'PythonScript.fltm_soc_ecc_process',
        'PythonScript.fltm_soc_ppu_process',
        'PythonScript.fltm_soc_pok_process',
        'PythonScript.fltm_soc_flsintegrity_process'
    ],
    hookspath=[],
    hooksconfig={},
    runtime_hooks=[],
    excludes=[
        'matplotlib',
        'scipy',
        'tkinter',
        'PyQt5',
        'PyQt6'
    ],
    win_no_prefer_redirects=False,
    win_private_assemblies=False,
    cipher=block_cipher,
    noarchive=False,
)

pyz = PYZ(a.pure, a.zipped_data, cipher=block_cipher)

exe = EXE(
    pyz,
    a.scripts,
    a.binaries,
    a.zipfiles,
    a.datas,
    [],
    name='FltM_ConfiguratorTool',
    debug=False,
    bootloader_ignore_signals=False,
    strip=False,
    upx=True,
    upx_exclude=[],
    runtime_tmpdir=None,
    console=True,
    disable_windowed_traceback=False,
    argv_emulation=False,
    target_arch=None,
    codesign_identity=None,
    entitlements_file=None,
)
"""
    
    try:
        with open('FltM_ConfiguratorTool.spec', 'w') as f:
            f.write(spec_content)
        print("✅ Spec file created: FltM_ConfiguratorTool.spec")
        return True
    except Exception as e:
        print(f"❌ Error creating spec file: {e}")
        return False

def build_executable():
    """Build the executable using PyInstaller."""
    print("\n🔨 Building executable with PyInstaller...")
    
    # Clean previous builds
    for dir in ['build', 'dist']:
        if os.path.exists(dir):
            shutil.rmtree(dir)
            print(f"🧹 Cleaned {dir}/ directory")
    
    try:
        # Run PyInstaller
        result = subprocess.run([
            'pyinstaller',
            '--clean',
            'FltM_ConfiguratorTool.spec'
        ], capture_output=True, text=True)
        
        if result.returncode == 0:
            print("✅ Executable built successfully!")
            
            # Check if executable was created
            exe_path = Path('dist') / 'FltM_ConfiguratorTool.exe'
            if exe_path.exists():
                file_size = exe_path.stat().st_size / (1024 * 1024)  # Size in MB
                print(f"📏 Executable size: {file_size:.1f} MB")
                print(f"📁 Location: {exe_path.absolute()}")
                return True
            else:
                print("❌ Executable file not found after build")
                return False
        else:
            print("❌ Build failed!")
            print("STDOUT:", result.stdout)
            print("STDERR:", result.stderr)
            return False
            
    except Exception as e:
        print(f"❌ Error during build: {e}")
        return False

def create_deployment_package():
    """Create a deployment package with the executable and required files."""
    print("\n📦 Creating deployment package...")
    
    package_dir = Path('FltM_ConfiguratorTool_Package')
    
    # Create package directory
    if package_dir.exists():
        shutil.rmtree(package_dir)
    package_dir.mkdir()
    
    # Copy executable
    exe_source = Path('dist') / 'FltM_ConfiguratorTool.exe'
    exe_dest = package_dir / 'FltM_ConfiguratorTool.exe'
    shutil.copy2(exe_source, exe_dest)
    
    # Copy sample Excel file if it exists
    excel_file = 'FltM_ConfiguratorTool.xlsm'
    if os.path.exists(excel_file):
        shutil.copy2(excel_file, package_dir / excel_file)
    
    # Create README
    readme_content = """# FltM ConfiguratorTool

## Usage
1. Place your FltM_ConfiguratorTool.xlsm file in the same directory as this executable
2. Double-click FltM_ConfiguratorTool.exe to run
3. Configuration files will be generated in the cfg/ folder

## Requirements
- FltM_ConfiguratorTool.xlsm (Excel input file)
- The executable includes all necessary dependencies

## Output
The tool generates configuration files in sheet-specific subfolders under cfg/:
- cfg/FltM/
- cfg/FltM_Soc/
- cfg/FltM_Soc_Dcc/
- cfg/FltM_Soc_Ecc/
- cfg/FltM_Soc_Ppu/
- cfg/FltM_Soc_Pok/
- cfg/FltM_Soc_FlsIntegrity/

## Support
For issues or questions, refer to the original Python source code.
"""
    
    with open(package_dir / 'README.txt', 'w') as f:
        f.write(readme_content)
    
    # Create batch file for easy execution
    batch_content = """@echo off
echo Starting FltM ConfiguratorTool...
FltM_ConfiguratorTool.exe
echo.
echo Process completed. Press any key to close...
pause >nul
"""
    
    with open(package_dir / 'run.bat', 'w') as f:
        f.write(batch_content)
    
    print(f"✅ Deployment package created: {package_dir.absolute()}")
    return True

def main():
    """Main build process."""
    print("🚀 FltM ConfiguratorTool - EXE Build Process")
    print("=" * 60)
    
    # Check requirements
    if not check_requirements():
        print("\n❌ Build failed: Missing requirements")
        sys.exit(1)
    
    # Install dependencies
    if not install_dependencies():
        print("\n❌ Build failed: Could not install dependencies")
        sys.exit(1)
    
    # Create spec file
    if not create_spec_file():
        print("\n❌ Build failed: Could not create spec file")
        sys.exit(1)
    
    # Build executable
    if not build_executable():
        print("\n❌ Build failed: PyInstaller build failed")
        sys.exit(1)
    
    # Create deployment package
    if not create_deployment_package():
        print("\n⚠️  Warning: Could not create deployment package")
    
    print("\n🎉 BUILD COMPLETED SUCCESSFULLY!")
    print("=" * 60)
    print("📁 Executable location: dist/FltM_ConfiguratorTool.exe")
    print("📦 Deployment package: FltM_ConfiguratorTool_Package/")
    print("\n📋 Next steps:")
    print("1. Test the executable with your Excel file")
    print("2. Verify all template files are working")
    print("3. Check output file generation")
    print("4. Deploy the package to target systems")

if __name__ == "__main__":
    main()