import pandas as pd
from jinja2 import Environment, FileSystemLoader
from pathlib import Path
from typing import List, Tuple
import sys
# Configuration for FltM_Soc_Ppu sheet
FLTM_SOC_PPU_CONFIG = {
    "sheet_name": "FltM_Soc_Ppu",
    "templates": [
        ("FltM_Soc_Ppu_Cfg.c.j2", "FltM_Soc_Ppu_Cfg.c"),
        ("FltM_Soc_Ppu_Cfg.h.j2", "FltM_Soc_Ppu_Cfg.h")
    ]
}

def render_and_write(env: Environment, template_name: str, out_name: str, sheet_name: str, **ctx) -> None:
    """Render a Jinja2 template and write to file in sheet-specific subfolder."""
    try:
        template = env.get_template(template_name)
        sheet_dir = Path("cfg") / sheet_name
        sheet_dir.mkdir(parents=True, exist_ok=True)
        with (sheet_dir / out_name).open("w", encoding="utf-8") as f:
            f.write(template.render(**ctx))
        return True
    except Exception as e:
        print(f"Error: Failed to process {template_name} -> {out_name}: {e}")
        return False
    
def process_fltm_soc_ppu_sheet(env: Environment, xl: pd.ExcelFile, sheet_name: str, templates: List[Tuple[str, str]]) -> None:
    df_full = pd.read_excel(xl, sheet_name=sheet_name, header=None, dtype=str, skiprows=1)
    blank = df_full.index[df_full.isna().all(axis=1)]
    if not blank.size:
        print(f"Error: No blank row separator in '{sheet_name}'.")
        sys.exit(1)
   
    # Take the first blank row as the separator
    split = blank[0]
   
    # Block1: Rows before the first blank row
    block1 = []
    for idx in range(split):
        key = df_full.iat[idx, 5]
        val = df_full.iat[idx, 6]
        if pd.notna(key) and pd.notna(val):
            block1.append({str(key).strip(): str(val).strip()})
    print(f"block1 = {block1}")
    # Block2: Rows after the last consecutive blank row
    # Find the first non-blank row after the first blank row
    non_blank_after_split = df_full.iloc[split:].index[~df_full.iloc[split:].isna().all(axis=1)]
    if not non_blank_after_split.size:
        print(f"Error: No data found after blank rows in '{sheet_name}'.")
        sys.exit(1)
   
    block2_start = non_blank_after_split[0]
    block2 = df_full.iloc[block2_start:].reset_index(drop=True)
    block2.columns = [str(c).strip() for c in block2.iloc[0]]
    block2 = block2[1:].dropna(axis=1, how="all").to_dict(orient="records")
 
    # Render templates
    for tpl, out in templates:
        render_and_write(env, tpl, out, sheet_name, block1=block1, block2=block2)