#!/usr/bin/env python3
"""
FltM_ConfiguratorTool – extended generator
Creates configuration files from an Excel workbook into sheet-specific subfolders.
"""
import sys
from jinja2 import Environment, FileSystemLoader
import pandas as pd
from PythonScript.fltm_process import process_fltm_sheet, FLTM_CONFIG
from PythonScript.fltm_soc_process import process_fltm_soc_sheet, FLTM_SOC_CONFIG
from PythonScript.fltm_soc_dcc_process import process_fltm_soc_dcc_sheet, FLTM_SOC_DCC_CONFIG
from PythonScript.fltm_soc_ecc_process import process_fltm_soc_ecc_sheet, FLTM_SOC_ECC_CONFIG
from PythonScript.fltm_soc_ppu_process import process_fltm_soc_ppu_sheet, FLTM_SOC_PPU_CONFIG
from PythonScript.fltm_soc_pok_process import process_fltm_soc_pok_sheet, FLTM_SOC_POK_CONFIG
from PythonScript.fltm_soc_flsintegrity_process import process_fltm_soc_flsintegrity_sheet, FLTM_SOC_FLSINTEGRITY_CONFIG

def setup_jinja2() -> Environment:
    """Set up and return Jinja2 environment."""
    try:
        # Set the template search path to 'PythonScript/jinja2Template' so Jinja2 can find the .j2 files
        return Environment(loader=FileSystemLoader("PythonScript/jinja2Template"))
    except Exception as e:
        print(f"Error: Failed to initialize Jinja2: {e}")
        return None

def load_workbook(filename: str) -> pd.ExcelFile:
    """Load Excel workbook and return it."""
    try:
        return pd.ExcelFile(filename, engine="openpyxl")
    except FileNotFoundError:
        print(f"Error: '{filename}' not found.")
        return None
    except Exception as e:
        print(f"Error: Failed to load Excel file: {e}")
        return None

def main():
    # Set up Jinja2 environment
    env = setup_jinja2()
    if not env:
        sys.exit(1)

    # Load workbook
    xl = load_workbook("FltM_ConfiguratorTool.xlsm")
    if not xl:
        sys.exit(1)

    # Process sheets
    success = True
    try:
        # Process all sheets
        for process, config in [
            (process_fltm_sheet, FLTM_CONFIG),
            (process_fltm_soc_sheet, FLTM_SOC_CONFIG),
            (process_fltm_soc_pok_sheet, FLTM_SOC_POK_CONFIG),
            (process_fltm_soc_ecc_sheet, FLTM_SOC_ECC_CONFIG),
            (process_fltm_soc_ppu_sheet, FLTM_SOC_PPU_CONFIG),
            (process_fltm_soc_dcc_sheet, FLTM_SOC_DCC_CONFIG),
            (process_fltm_soc_flsintegrity_sheet, FLTM_SOC_FLSINTEGRITY_CONFIG)
        ]:
            if not process(env, xl, config["sheet_name"], config["templates"]):
                success = False
    finally:
        xl.close()

    if success:
        print("✅ All files generated successfully!")
    else:
        sys.exit(1)

if __name__ == "__main__":
    main()