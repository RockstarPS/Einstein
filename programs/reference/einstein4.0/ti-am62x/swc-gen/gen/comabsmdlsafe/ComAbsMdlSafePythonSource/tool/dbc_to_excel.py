# dbc_to_excel.py
import re
import argparse
from typing import List, Dict, Any, Tuple, Set
from collections import defaultdict
import openpyxl
from openpyxl import Workbook
from openpyxl.styles import Protection, PatternFill, Font
from openpyxl.comments import Comment
import os

# ============================================================================
# Helpers
# ============================================================================
def sanitize_enum(name: str, direction: str = "In") -> str:
    """
    Generate enum name: e<SignalName>In or e<SignalName>Out
    """
    safe = re.sub(r'[^A-Za-z0-9_]', '_', name)
    return f"e{safe}{direction}"

# ============================================================================
# DBC parsing
# ============================================================================
def parse_dbc(dbc_path: str) -> Tuple[Dict[int, Dict[str, Any]], List[Dict[str, Any]]]:
    messages: Dict[int, Dict[str, Any]] = {}
    signals: List[Dict[str, Any]] = []
    msg_re = re.compile(r"BO\_\s+(\d+)\s+(\w+)\s*:\s*(\d+)\s+(\w+)")
    sig_re = re.compile(r"SG\_\s+(\w+)\s*:\s*(\d+)\|(\d+)@(\d)([+-])")
    with open(dbc_path, "r", encoding="utf-8", errors="ignore") as f:
        lines = f.readlines()
    current_msg_id = None
    for raw_line in lines:
        line = raw_line.strip()
        # Message definition
        m = msg_re.match(line)
        if m:
            msg_id = int(m.group(1))
            msg_name = m.group(2)
            dlc = int(m.group(3))
            tx_node = m.group(4)
            messages[msg_id] = {
                "MsgName": msg_name,
                "DLC": dlc,
                "TxNode": tx_node
            }
            current_msg_id = msg_id
            continue
        # Signal definition
        s = sig_re.match(line)
        if s and current_msg_id is not None:
            sig_name = s.group(1)
            length = int(s.group(3))
            byte_order_flag = int(s.group(4))
            byte_order = "Motorola" if byte_order_flag == 1 else "Intel"
            group_name = None
            tokens = line.split()
            if tokens and tokens[-1].startswith("SG_"):
                group_name = tokens[-1].strip()
            receivers: List[str] = []
            if '"' in line:
                try:
                    after_unit = line.split('"')[-1].strip()
                    parts = after_unit.split()
                    if parts and parts[-1].startswith("SG_"):
                        parts = parts[:-1]
                    receivers = parts
                except Exception:
                    pass
            msg_info = messages[current_msg_id]
            signals.append({
                "MsgId": current_msg_id,
                "MsgName": msg_info["MsgName"],
                "MsgTxNode": msg_info["TxNode"],
                "SignalName": sig_name,
                "Length": length,
                "ByteOrder": byte_order,
                "GroupName": group_name,
                "Receivers": receivers
            })
    return messages, signals

# ============================================================================
# Safety classification
# ============================================================================
def classify_safe_messages(signals: List[Dict[str, Any]]) -> Set[int]:
    safe_msg_ids: Set[int] = set()
    for sig in signals:
        if sig["SignalName"].startswith("Alive_") or sig["SignalName"].startswith("CRC_"):
            safe_msg_ids.add(sig["MsgId"])
    return safe_msg_ids

# ============================================================================
# Excel generation helpers
# ============================================================================
RX_HEADERS = [
    "Signal Name",
    "VSignal Name",
    "VSignal Enum",
    "Enable/Disable",
    "Length in bits",
    "Timeout Value in ms",
    "Message Name",
    "Message Cbk Enable/Disable",
    "Comments"
]

TX_HEADERS = [
    "Signal Name",
    "VSignal Name",
    "VSignal Enum",
    "Enable/Disable",
    "Length in bits",
    "Message Name",
    "Message Cbk Enable/Disable",
    "SignalTxConfirmation Enable / Disable",
    "Comments"
]

def create_safe_workbook() -> Tuple[Workbook, Any, Any]:
    wb = Workbook()
    rx_sheet = wb.active
    rx_sheet.title = "RxSignals"
    rx_sheet.append(RX_HEADERS)
    tx_sheet = wb.create_sheet("TxSignals")
    tx_sheet.append(TX_HEADERS)
    return wb, rx_sheet, tx_sheet

def append_row(sheet, sig, msg_name, is_first_signal: bool = False):
    """Append row with blank Timeout Value and eSignalNameIn enum."""
    vsignal_name = f"{sig['SignalName']} In"
    vsignal_enum = sanitize_enum(sig["SignalName"], "In")  # eSignalNameIn
    sheet.append([
        sig["SignalName"],                    # A
        vsignal_name,                         # B
        vsignal_enum,                         # C
        "TRUE",                               # D ← Enable/Disable
        sig["Length"],                        # E
        None,                                 # F ← BLANK
        msg_name,                             # G
        "TRUE" if is_first_signal else "FALSE",  # H
        ""                                    # I ← Comments
    ])

def append_tx_row(sheet, sig, msg_name):
    """Append Tx row with eSignalNameOut enum."""
    vsignal_name = f"{sig['SignalName']} Out"
    vsignal_enum = sanitize_enum(sig["SignalName"], "Out")  # eSignalNameOut
    sheet.append([
        sig["SignalName"],
        vsignal_name,
        vsignal_enum,
        "TRUE",                               # D ← Enable/Disable
        sig["Length"],
        msg_name,
        "FALSE",
        "TRUE",
        ""                                    # I ← Comments
    ])

# ============================================================================
# Main Excel generation
# ============================================================================
def generate_safe_excel(
    messages: Dict[int, Dict[str, Any]],
    signals: List[Dict[str, Any]],
    ecu_node: str,
    safe_out: str
) -> None:
    """
    Generate SAFE Excel with:
    - RxSignals: D, F, I editable
    - TxSignals: D, I editable
    - VSignal Enum = eSignalNameIn (Rx) / eSignalNameOut (Tx)
    """
    safe_msg_ids = classify_safe_messages(signals)
    safe_wb, safe_rx, safe_tx = create_safe_workbook()
    safe_signals = [sig for sig in signals if sig["MsgId"] in safe_msg_ids]

    rx_signals_by_msg: Dict[int, List[Dict[str, Any]]] = defaultdict(list)
    tx_signals: List[Dict[str, Any]] = []

    for sig in safe_signals:
        msg_id = sig["MsgId"]
        tx_node = messages[msg_id]["TxNode"]
        is_tx = (ecu_node is not None and tx_node == ecu_node)
        is_rx = (ecu_node is None) or (ecu_node in sig["Receivers"]) or (not is_tx)

        if is_rx:
            rx_signals_by_msg[msg_id].append(sig)
        if is_tx:
            sig_name = sig["SignalName"]
            if not (sig_name.startswith("CRC_") or sig_name.startswith("Alive_")):
                tx_signals.append(sig)

    # Write RxSignals
    for msg_id, sigs in rx_signals_by_msg.items():
        sigs.sort(key=lambda x: x["SignalName"])
        msg_name = f"SG_{messages[msg_id]['MsgName']}"
        for i, sig in enumerate(sigs):
            is_first = (i == 0)
            append_row(safe_rx, sig, msg_name, is_first_signal=is_first)

    # Write TxSignals
    tx_signals.sort(key=lambda x: x["SignalName"])
    for sig in tx_signals:
        msg_name = f"SG_{messages[sig['MsgId']]['MsgName']}"
        append_tx_row(safe_tx, sig, msg_name)

    # 🔐 Protection & Styling for RxSignals
    safe_rx.protection.sheet = True
    safe_rx.protection.enable()

    # Colors
    YELLOW_FILL = PatternFill(start_color="FFFF99", end_color="FFFF99", fill_type="solid")  # Editable
    GRAY_FILL = PatternFill(start_color="E0E0E0", end_color="E0E0E0", fill_type="solid")   # Locked
    HEADER_FONT = Font(bold=True)

    # Header style - Rx
    for cell in safe_rx[1]:
        cell.font = HEADER_FONT
        cell.fill = GRAY_FILL

    # Data rows - Rx: unlock D (4), F (6), I (9)
    for row in safe_rx.iter_rows(min_row=2, max_row=safe_rx.max_row):
        for cell in row:
            if cell.column in {4, 6, 9}:  # D, F, I
                cell.fill = YELLOW_FILL
                cell.protection = Protection(locked=False)
            else:
                cell.fill = GRAY_FILL
                cell.protection = Protection(locked=True)

    # 🔐 Protect TxSignals Sheet - Unlock D (4) and I (9)
    safe_tx.protection.sheet = True
    safe_tx.protection.enable()

    # Style header - Tx
    for cell in safe_tx[1]:
        cell.font = HEADER_FONT
        cell.fill = GRAY_FILL

    # Style data rows - Tx: unlock D (4) and I (9), others locked
    for row in safe_tx.iter_rows(min_row=2, max_row=safe_tx.max_row):
        for cell in row:
            if cell.column in {4, 9}:  # D and I: Enable/Disable and Comments
                cell.fill = YELLOW_FILL
                cell.protection = Protection(locked=False)
            else:
                cell.fill = GRAY_FILL
                cell.protection = Protection(locked=True)

    # Save
    safe_wb.save(safe_out)

# ============================================================================
# CLI
# ============================================================================
def main():
    parser = argparse.ArgumentParser(description="Generate SAFE Excel with protection and validation hints.")
    parser.add_argument("--dbc", required=True, help="DBC file name (e.g., PlatformDBCE4v7.dbc)")
    parser.add_argument("--node", default=None, help="ECU node name (e.g., IC)")
    parser.add_argument("--safe-out", default="E4.0_Intermediate_sheet.xlsx", help="Output Excel file name")
    args = parser.parse_args()

    input_dbc_dir = "..\\Input_DBC"
    output_excel_dir = "..\\Intermediate_Sheet"
    dbc_path = os.path.join(input_dbc_dir, args.dbc)
    safe_out_path = os.path.join(output_excel_dir, args.safe_out)

    os.makedirs(output_excel_dir, exist_ok=True)

    if not os.path.isfile(dbc_path):
        raise FileNotFoundError(f"DBC file not found: {dbc_path}")

    print(f"Reading DBC: {dbc_path}")
    messages, signals = parse_dbc(dbc_path)
    generate_safe_excel(messages, signals, args.node, safe_out_path)
    print(f"SAFE Excel generated: {safe_out_path}")

if __name__ == "__main__":
    main()