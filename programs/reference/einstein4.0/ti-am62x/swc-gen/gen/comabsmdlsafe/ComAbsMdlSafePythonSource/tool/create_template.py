# create_template.py
import pandas as pd

# RxSignals
rx_data = [
    ["VehicleSpeed", "VehicleSpeed", "eVehicleSpeedIn", True, 16, 100, "SG_ABS", False, True, True, "(0-10)", 10, True, True, "eAliveCounterIn", None, True, True],
    ["BrakeStatus", "BrakeStatus", "eBrakeStatusIn", True, 8, 50, "SG_ABS", False, True, True, "0", 5, False, False, None, None, True, True],
    ["AirbagDeploy", "AirbagDeploy", "eAirbagDeployIn", True, 8, 200, "SG_SRS", False, True, True, "1", 20, True, True, "eCRC_SRS", None, False, True],
]
rx_df = pd.DataFrame(rx_data, columns=[
    "SignalName", "VSignalName", "VSignalEnum", "Enabled", "Lengthinbits", "TimeoutValue", "MsgName",
    "DynSignalSupport", "MessageCbk", "SignalInvalidSupport", "SignalInvalidVal", "SignalInvalidCounter",
    "SignalUBSupport", "SignalQfSupport", "SignalQfSignalValue", "SignalInitTrigger", "ValueRetention", "SignalIsoSupport"
])

# TxSignals
tx_data = [
    ["BatteryVoltage", "BatteryVoltage", "eBatteryVoltageOut", True, 16, "SG_BATTERY", True, True, True, False, False, True],
    ["VehicleSpeedTx", "VehicleSpeed", "eVehicleSpeedOut", True, 16, "SG_ABS", True, True, True, False, False, True],
    ["Alive_200", "Alive_200", "eAlive_200Out", True, 8, "SG_COM_HS", True, True, False, False, False, True],
]
tx_df = pd.DataFrame(tx_data, columns=[
    "SignalName", "VSignalName", "VSignalEnum", "Enabled", "Lengthinbits", "MsgName",
    "MessageCbk", "TxConfirm", "ValueRetention", "InitTrigger", "DynSignal", "SignalIsoSupport"
])

# Write to Excel
with pd.ExcelWriter("E4.0_Intermediate_sheet.xlsx", engine="openpyxl") as writer:
    rx_df.to_excel(writer, sheet_name="RxSignals", index=False)
    tx_df.to_excel(writer, sheet_name="TxSignals", index=False)

print("✅ Excel template generated: E4.0_Intermediate_sheet.xlsx")