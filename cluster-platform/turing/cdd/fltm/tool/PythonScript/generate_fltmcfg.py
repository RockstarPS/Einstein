import pandas as pd
from jinja2 import Environment, FileSystemLoader
import sys
import os

# Ensure output directory exists
os.makedirs("cfg", exist_ok=True)

# Load Excel file and get sheet names
try:
    xl = pd.ExcelFile("FltM_ConfiguratorTool.xlsm", engine="openpyxl")
    sheet1_name, sheet2_name = xl.sheet_names[0], xl.sheet_names[1]
    df_sheet1 = pd.read_excel(xl, sheet_name=0, header=2)
    df_sheet2 = pd.read_excel(xl, sheet_name=1, header=2)
except FileNotFoundError:
    print("Error: 'FltM_ConfiguratorTool.xlsm' not found in the current directory.")
    sys.exit(1)
except ValueError as e:
    print(f"Error: Invalid Excel file format. {str(e)}")
    sys.exit(1)
finally:
    xl.close()  # Close the Excel file to free resources

# Check if DataFrames are empty
if df_sheet1.empty:
    print(f"Error: 'FltM_ConfiguratorTool.xlsm' - Sheet 1 ('{sheet1_name}') contains no data.")
    sys.exit(1)
if df_sheet2.empty:
    print(f"Error: 'FltM_ConfiguratorTool.xlsm' - Sheet 2 ('{sheet2_name}') contains no data.")
    sys.exit(1)

# Validate cells for both sheets
def validate_dataframe(df, sheet_name, header_offset=1):
    empty_cells = []
    invalid_cells = []
    for col in df.columns:
        for idx, value in enumerate(df[col]):
            excel_row = idx + header_offset + 1  # Adjust for 1-based Excel row and header
            if pd.isna(value) or (isinstance(value, str) and value.strip() == ''):
                empty_cells.append(f"Row {excel_row}, Column '{col}'")
            elif isinstance(value, str) and value.startswith('&'):
                invalid_cells.append(f"Row {excel_row}, Column '{col}'")
    return empty_cells, invalid_cells

# Validate Sheet 1 (header at row 1)
empty_cells1, invalid_cells1 = validate_dataframe(df_sheet1, sheet1_name, header_offset=3)

# Validate Sheet 2 (header at row 1)
empty_cells2, invalid_cells2 = validate_dataframe(df_sheet2, sheet2_name, header_offset=3)

# Report errors
if empty_cells1:
    print("Error: The following cells in 'FltM_ConfiguratorTool.xlsm' are empty or missing:")
    for cell in empty_cells1:
        print(f"  - Sheet 1 ('{sheet1_name}'): {cell}")
        
if invalid_cells1:
    print("Error: The following cells in 'FltM_ConfiguratorTool.xlsm' are incorrectly configured:")
    for cell in invalid_cells1:
        print(f"  - Sheet 1 ('{sheet1_name}'): {cell}")
		
# Report errors
if empty_cells2:
    print("Error: The following cells in 'FltM_ConfiguratorTool.xlsm' are empty or missing:")
    for cell in empty_cells2:
        print(f"  - Sheet 2 ('{sheet2_name}'): {cell}")
        
if invalid_cells2:
    print("Error: The following cells in 'FltM_ConfiguratorTool.xlsm' are incorrectly configured:")
    for cell in invalid_cells2:
        print(f"  - Sheet 2 ('{sheet2_name}'): {cell}")

# Convert to lists of dictionaries
block1 = df_sheet1.to_dict(orient="records")
block2 = df_sheet2.to_dict(orient="records")

# Set up Jinja2 environment
try:
    env = Environment(loader=FileSystemLoader("."))
    template_c = env.get_template("FltM_Cfg.c.j2")
    template_h = env.get_template("FltM_Cfg.h.j2")
except Exception as e:
    print(f"Error: Failed to load Jinja2 templates. {str(e)}")
    sys.exit(1)

# Render templates with block1 and block2
output_c = template_c.render(block1=block1, block2=block2)
output_h = template_h.render(block1=block1, block2=block2)

# Write output files
try:
    with open("cfg/FltM_Cfg.c", "w") as f:
        f.write(output_c)
    with open("cfg/FltM_Cfg.h", "w") as f:
        f.write(output_h)
except Exception as e:
    print(f"Error: Failed to write output files. {str(e)}")
    sys.exit(1)

print("✅ FltM_Cfg.c and FltM_Cfg.h generated successfully!")