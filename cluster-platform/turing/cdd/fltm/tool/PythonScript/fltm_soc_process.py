import pandas as pd
from jinja2 import Environment
from pathlib import Path
from typing import List, Tuple

# Configuration for FltM_Socsheet
FLTM_SOC_CONFIG = {
    "sheet_name": "FltM_Soc",
    "templates": [
        ("FltM_Soc_Cfg.c.j2", "FltM_Soc_Cfg.c"),
        ("FltM_Soc_Cfg.h.j2", "FltM_Soc_Cfg.h")
    ]
}

def validate_dataframe(df: pd.DataFrame, sheet_name: str, header_offset: int):
    """Return lists of empty or invalid cell locations."""
    empty_cells = []
    for col in df.columns:
        # Only validate empty cells for named columns, skip Unnamed columns
        for idx, value in df[col].items():
            excel_row = idx + header_offset + 1  # 1-based for Excel
            if not col.startswith('Unnamed:'):
                if isinstance(value, str) and not value.strip():
                    empty_cells.append(f"Row {excel_row}, Column '{col}' in sheet '{sheet_name}'")
    return empty_cells
def render_and_write(env: Environment, template_name: str, out_name: str, sheet_name: str, **ctx) -> bool:
    """Render a Jinja2 template and write to file in sheet-specific subfolder."""
    template = env.get_template(template_name)
    sheet_dir = Path("cfg") / sheet_name
    sheet_dir.mkdir(parents=True, exist_ok=True)
    with (sheet_dir / out_name).open("w", encoding="utf-8") as f:
        f.write(template.render(**ctx))
    return True

def process_fltm_soc_sheet(env: Environment, xl: pd.ExcelFile, sheet_name: str, templates: List[Tuple[str, str]]) -> bool:
    """Process FltM_Soc sheet with blank row separator and two headers."""
    try:
        df_full = pd.read_excel(xl, sheet_name=sheet_name, header=1, dtype=str)
        blank = df_full.index[df_full.isna().all(axis=1)]
        if not blank.size:
            print(f"Error: No blank row separator in '{sheet_name}'.")
            return False
        
        # Take the first blank row as the separator
        split = blank[0]
        
        # Block1: Rows before the first blank row
        block1 = df_full.iloc[:split].dropna(axis=1, how="all").reset_index(drop=True).to_dict(orient="records")
        
        # Block2: Rows after the last consecutive blank row
        # Find the first non-blank row after the first blank row
        non_blank_after_split = df_full.iloc[split:].index[~df_full.iloc[split:].isna().all(axis=1)]
        if not non_blank_after_split.size:
            print(f"Error: No data found after blank rows in '{sheet_name}'.")
            return False
        
        block2_start = non_blank_after_split[0]
        block2 = df_full.iloc[block2_start:].reset_index(drop=True)
        block2.columns = [str(c).strip() for c in block2.iloc[0]]
        block2 = block2[1:].dropna(axis=1, how="all").to_dict(orient="records")

        success = True
        # Validate data in both blocks
        # empty_cells = validate_dataframe(df_full.iloc[:split], sheet_name, 2)
        # empty_cells2 = validate_dataframe(df_full.iloc[split+1:], sheet_name, split + 3)
        # if empty_cells or empty_cells2 :
        #     for cells, tag in [(empty_cells, "empty"), (empty_cells2, "empty")]:
        #         for c in cells:
        #             print(f"Error: {tag} cell in {c}")
        #     return False

        for tpl, out in templates:
            if not render_and_write(env, tpl, out, sheet_name, block1=block1, block2=block2):
                success = False
        return success
    except Exception as e:
        print(f"Error processing sheet '{sheet_name}': {e}")
        return False