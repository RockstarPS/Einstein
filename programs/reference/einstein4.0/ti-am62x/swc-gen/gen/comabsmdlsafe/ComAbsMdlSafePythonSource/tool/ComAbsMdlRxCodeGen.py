import openpyxl
import sys
import datetime
import getpass
import os

def get_string_from_bytes(val):
    if isinstance(val, bytes):
        return val.decode('utf-8').strip()
    elif val is None:
        return ""
    else:
        return str(val).strip()
def get_bool_val(val):
    if val is None:
        return False
    if isinstance(val, bool):
        return val
    return str(val).strip().upper() == "TRUE"

def generate_code_comabs_rx_cfg(excel_name, user_name, gen_time, output_dir="."):
    # Ensure output directory exists
    os.makedirs(output_dir, exist_ok=True)
    
    try:
        workbook = openpyxl.load_workbook(excel_name, data_only=True)
    except Exception as e:
        print(f"Error opening Excel file: {e}")
        sys.exit(1)
    try:
        rx_sheet = workbook["RxSignals"]
    except KeyError:
        print("Error: Sheet 'RxSignals' not found in workbook.")
        sys.exit(1)
    # Lists and maps
    rx_signal_config = []
    rx_signal_enum_list = []
    rx_signal_qf_invalid_list = {}
    general_iso_support = False
    # Parse all enabled signals
    for row in range(2, rx_sheet.max_row + 1):
        if not get_bool_val(rx_sheet.cell(row=row, column=4).value):  # Enabled?
            continue
        try:
            enum_val = get_string_from_bytes(rx_sheet.cell(row=row, column=3).value)
            if not enum_val:
                print(f"Warning: Empty VSignalEnum at row {row}, skipping.")
                continue
            if enum_val in rx_signal_enum_list:
                raise ValueError(f"Duplicate VSignalEnum: {enum_val}")
            signal_dict = {
                'SignalName': get_string_from_bytes(rx_sheet.cell(row=row, column=1).value),
                'VSignalName': get_string_from_bytes(rx_sheet.cell(row=row, column=2).value),
                'VSignalEnum': enum_val,
                'Lengthinbits': int(rx_sheet.cell(row=row, column=5).value or 0),
                'TimeoutValue': int(rx_sheet.cell(row=row, column=6).value or 0),
                'MsgName': get_string_from_bytes(rx_sheet.cell(row=row, column=7).value),
                'MessageCbk': get_bool_val(rx_sheet.cell(row=row, column=8).value),
                'SignalInvalidSupport': get_bool_val(rx_sheet.cell(row=row, column=9).value),
                'SignalInvalidVal': rx_sheet.cell(row=row, column=10).value,
                'SignalInvalidCounter': int(rx_sheet.cell(row=row, column=11).value or 0),
                'SignalUBSupport': get_bool_val(rx_sheet.cell(row=row, column=12).value),
                'SignalQfSupport': get_bool_val(rx_sheet.cell(row=row, column=13).value),
                'SignalQfSignalValue': get_string_from_bytes(rx_sheet.cell(row=row, column=14).value),
                'ValueRetention': get_bool_val(rx_sheet.cell(row=row, column=15).value),
                'SignalIsoSupport': get_bool_val(rx_sheet.cell(row=row, column=16).value)
            }
            if signal_dict['SignalIsoSupport']:
                general_iso_support = True
            # Compute length in bytes
            bits = signal_dict['Lengthinbits']
            signal_dict['LengthInBytes'] = (bits + 7) // 8
            rx_signal_config.append(signal_dict)
            rx_signal_enum_list.append(enum_val)
            if signal_dict['SignalQfSupport'] and signal_dict['SignalQfSignalValue']:
                qf_enum = get_string_from_bytes(signal_dict['SignalQfSignalValue'])
                if qf_enum not in rx_signal_qf_invalid_list:
                    rx_signal_qf_invalid_list[qf_enum] = {
                        'SignalName': signal_dict['SignalName'],
                        'SignalInvalidVal': signal_dict['SignalInvalidVal'],
                        'SignalInvalidCounter': signal_dict['SignalInvalidCounter'],
                        'VSignalEnum': qf_enum
                    }
        except Exception as e:
            print(f"Error parsing row {row}: {e}")
            sys.exit(1)
    # Build message-to-signal mapping
    rx_msg_list = []
    rx_msg_key_sig_map = {}
    rx_msg_sig_list = {}
    rx_Ub_sig_list = []
    for sig in rx_signal_config:
        msg_name = sig['MsgName']
        if sig['SignalUBSupport']:
            rx_Ub_sig_list.append(sig)
        else:
            if msg_name not in rx_msg_list:
                rx_msg_list.append(msg_name)
                rx_msg_sig_list[msg_name] = []
                if sig['MessageCbk']:
                    rx_msg_key_sig_map[msg_name] = sig['SignalName']
            rx_msg_sig_list[msg_name].append(sig)
    # Analyze signal types
    sigu8_cnt = sigu8_retention_cnt = 0
    sigu16_cnt = sigu16_retention_cnt = 0
    sigu32_cnt = sigu32_retention_cnt = 0
    sigu64_cnt = sigu64_retention_cnt = 0
    sigu64_byte_len = sigu64_retention_byte_len = 0
    sig_invalid_cnt = 0
    sig_get_cnt = sig_getarr_cnt = 0
    sig_get_list = []
    sig_get_list_iso_support = []
    sig_getarr_list = []
    sig_getarr_list_iso_support = []
    sig_invalid_list = []
    for sig in rx_signal_config:
        bits = sig['Lengthinbits']
        bytes_len = sig['LengthInBytes']
        # Buffer counts
        if bits <= 8:
            if sig['ValueRetention']: sigu8_retention_cnt += 1
            else: sigu8_cnt += 1
        elif bits <= 16:
            if sig['ValueRetention']: sigu16_retention_cnt += 1
            else: sigu16_cnt += 1
        elif bits <= 32:
            if sig['ValueRetention']: sigu32_retention_cnt += 1
            else: sigu32_cnt += 1
        else:
            if sig['ValueRetention']:
                sigu64_retention_cnt += 1
                sigu64_retention_byte_len += bytes_len
            else:
                sigu64_cnt += 1
                sigu64_byte_len += bytes_len
        # Get functions
        if bytes_len <= 4:
            sig_get_cnt += 1
            sig_get_list.append(sig['SignalName'])
            sig_get_list_iso_support.append(sig['SignalIsoSupport'])
        else:
            sig_getarr_cnt += 1
            sig_getarr_list.append(sig['SignalName'])
            sig_getarr_list_iso_support.append(sig['SignalIsoSupport'])
        # Invalid signals
        if sig['SignalInvalidSupport']:
            sig_invalid_cnt += 1
            sig_invalid_list.append(sig['SignalName'])
    # ==================== Generate .h file ====================
    h_file_path = os.path.join("..\gen-files", "ComAbsMdlSafe_RxCfg.h")
    with open(h_file_path, "w") as f:
        sys.stdout = f
        print('''/********************************************************************************************************************
* C O P Y R I G H T                                                                                                 *
*********************************************************************************************************************
* Copyright (c) 2019 by Visteon Corporation.       All rights reserved.                                             *
*                                                                                                                   *
* NOTICE: This Is an unpublished work Of authorship, which contains trade secrets.                                  *
* Visteon Corporation owns all rights to this work And intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States    *
* Or those of any other country that may have jurisdiction, to protect this work as an unpublished work,            *
* in the event of an inadvertent Or deliberate unauthorized publication. Visteon Corporation also reserves its      *
* rights under all copyright laws to protect this work as a published work, when appropriate.                       *
* Those having access to this work may Not copy it, use it, modify it, Or disclose the information contained in it  *
* without the written authorization of Visteon Corporation.                                                         *
********************************************************************************************************************/
/*!*****************************************************************************************************************
*    @file ComAbsMdlSafe_RxCfg.h
*    @ingroup COMABSMDLSAFE
*    @brief This file contains the configuration of the COMABSMDLSAFE component.
*    Auto generated code in ''' + user_name + ''' at ''' + str(gen_time) + '''
********************************************************************************************************************/
#ifndef COMABSMDLSAFE_RX_CFG_H_
#define COMABSMDLSAFE_RX_CFG_H_
#include "Rte_CComAbsMdlSafe_Type.h"
#include "ComAbsMdlSafe.h"
#include "Rte_Type.h"
#define COMABSMDLSAFE_SEC_CODE_START
#define COMABSMDLSAFE_CORE_CONST_SEC_START
#define COMABSMDLSAFE_CORE_DATA_SEC_START
#define COMABSMDLSAFE_CORE_BSS_SEC_START
#include "MemMap.h"
/********************************************************************************************************************
*  PUBLIC MACRO DEFINITIONS                                                                                         *
********************************************************************************************************************/''')
        if general_iso_support:
            print('#define COMABSMDLSAFE_RXCAN_ISO_SIGNAL_SUPPORTED')
        space_length = 60
        def pad(name):
            return " " * (space_length - len(name))
        # Buffer counts
        print('''/* Number of signal buffers */''')
        print(f'#define COMABSMDLSAFE_RXCAN_NUM_OF_U8_BUFFERS{pad("COMABSMDLSAFE_RXCAN_NUM_OF_U8_BUFFERS")}{max(sigu8_cnt,1)}U')
        print(f'#define COMABSMDLSAFE_RXCAN_NUM_OF_U16_BUFFERS{pad("COMABSMDLSAFE_RXCAN_NUM_OF_U16_BUFFERS")}{max(sigu16_cnt,1)}U')
        print(f'#define COMABSMDLSAFE_RXCAN_NUM_OF_U32_BUFFERS{pad("COMABSMDLSAFE_RXCAN_NUM_OF_U32_BUFFERS")}{max(sigu32_cnt,1)}U')
        print(f'#define COMABSMDLSAFE_RXCAN_NUM_OF_U8ARR_BUFFERS{pad("COMABSMDLSAFE_RXCAN_NUM_OF_U8ARR_BUFFERS")}{max(sigu64_byte_len,1)}U')
        print(f'#define COMABSMDLSAFE_RXCAN_NUM_OF_U8ARR_LENGTH_BUFFERS{pad("COMABSMDLSAFE_RXCAN_NUM_OF_U8ARR_LENGTH_BUFFERS")}{max(sigu64_cnt,1)}U')
        print(f'#define COMABSMDLSAFE_RXCAN_NUM_OF_U8_RETENTION_BUFFERS{pad("COMABSMDLSAFE_RXCAN_NUM_OF_U8_RETENTION_BUFFERS")}{max(sigu8_retention_cnt,1)}U')
        print(f'#define COMABSMDLSAFE_RXCAN_NUM_OF_U16_RETENTION_BUFFERS{pad("COMABSMDLSAFE_RXCAN_NUM_OF_U16_RETENTION_BUFFERS")}{max(sigu16_retention_cnt,1)}U')
        print(f'#define COMABSMDLSAFE_RXCAN_NUM_OF_U32_RETENTION_BUFFERS{pad("COMABSMDLSAFE_RXCAN_NUM_OF_U32_RETENTION_BUFFERS")}{max(sigu32_retention_cnt,1)}U')
        print(f'#define COMABSMDLSAFE_RXCAN_NUM_OF_U8ARR_RETENTION_BUFFERS{pad("COMABSMDLSAFE_RXCAN_NUM_OF_U8ARR_RETENTION_BUFFERS")}{max(sigu64_retention_byte_len,1)}U')
        print(f'#define COMABSMDLSAFE_RXCAN_NUM_OF_RETENTION_U8ARR_LENGTH_BUFFERS{pad("COMABSMDLSAFE_RXCAN_NUM_OF_RETENTION_U8ARR_LENGTH_BUFFERS")}{max(sigu64_retention_cnt,1)}U')
        if sig_getarr_cnt > 0:
            print(f'#define COMABSMDLSAFE_RXCAN_NUM_OF_U8ARR_SIG_CFG{pad("COMABSMDLSAFE_RXCAN_NUM_OF_U8ARR_SIG_CFG")}{sig_getarr_cnt}U')
        else:
            print(f'#define COMABSMDLSAFE_RXCAN_NUM_OF_U8ARR_SIG_CFG{pad("COMABSMDLSAFE_RXCAN_NUM_OF_U8ARR_SIG_CFG")}1U')
        # Status bytes
        nr_bytes = (len(rx_signal_config) + 7) // 8 or 1
        print(f'\n/* Number of signal status bytes */\n')
        print(f'#define COMABSMDLSAFE_RXCAN_NUM_OF_NR_STATUS_BYTES{pad("COMABSMDLSAFE_RXCAN_NUM_OF_NR_STATUS_BYTES")}{nr_bytes}U')
        print(f'#define COMABSMDLSAFE_RXCAN_NUM_OF_MISSING_STATUS_BYTES{pad("COMABSMDLSAFE_RXCAN_NUM_OF_MISSING_STATUS_BYTES")}{nr_bytes}U')
        print(f'#define COMABSMDLSAFE_RXCAN_NUM_OF_JUST_RCVD_STATUS_BYTES{pad("COMABSMDLSAFE_RXCAN_NUM_OF_JUST_RCVD_STATUS_BYTES")}{nr_bytes}U')
        invalid_bytes = (sig_invalid_cnt + 7) // 8 or 1
        print(f'#define COMABSMDLSAFE_RXCAN_NUM_OF_SIGNAL_INVALID_STATUS_BYTES{pad("COMABSMDLSAFE_RXCAN_NUM_OF_SIGNAL_INVALID_STATUS_BYTES")}{invalid_bytes}U')
        print(f'#define COMABSMDLSAFE_RXCAN_NUM_OF_SIGNAL_INVALID_CRC_STATUS_BYTES{pad("COMABSMDLSAFE_RXCAN_NUM_OF_SIGNAL_INVALID_CRC_STATUS_BYTES")}1U')
        print(f'#define COMABSMDLSAFE_RXCAN_NUM_OF_SIGNAL_INVALID_ALIVE_COUNTER_STATUS_BYTES{pad("COMABSMDLSAFE_RXCAN_NUM_OF_SIGNAL_INVALID_ALIVE_COUNTER_STATUS_BYTES")} 1U')
        print(f'#define COMABSMDLSAFE_RXCAN_NUM_OF_SIGNAL_REPETATION_STATUS_BYTES{pad("COMABSMDLSAFE_RXCAN_NUM_OF_SIGNAL_REPETATION_STATUS_BYTES")}1U')

        print(f'\n/* Number of invalid signals */\n')
        print(f'#define COMABSMDLSAFE_RXCAN_NUM_OF_INVALID_SIGNALS{pad("COMABSMDLSAFE_RXCAN_NUM_OF_INVALID_SIGNALS")}{invalid_bytes}U')
        print(f'#define COMABSMDLSAFE_RXCAN_NO_INVALDID_SIGNAL{pad("COMABSMDLSAFE_RXCAN_NO_INVALDID_SIGNAL")}COMABSMDLSAFE_RXCAN_NUM_OF_INVALID_SIGNALS')
        print(f'#define COMABSMDLSAFE_RXCAN_NUM_OF_MISSING_SIGNALS{pad("COMABSMDLSAFE_RXCAN_NUM_OF_MISSING_SIGNALS")} eEndOfSafeRxSignal')
        print(f'#define COMABSMDLSAFE_RXCAN_MAINFUNCTION_TIME_IN_MS{pad("COMABSMDLSAFE_RXCAN_MAINFUNCTION_TIME_IN_MS")}10U')
        if sig_get_cnt > 0:
            print(f'#define COMABSMDLSAFE_RXCAN_NUM_OF_GET_SIG_FUNCT{pad("COMABSMDLSAFE_RXCAN_NUM_OF_GET_SIG_FUNCT")}{sig_get_cnt}U')
        else:
            print(f'#define COMABSMDLSAFE_RXCAN_NO_GET_SIG_FUNCT_IDX{pad("COMABSMDLSAFE_RXCAN_NO_GET_SIG_FUNCT_IDX")}1U')
        print(f'#define COMABSMDLSAFE_RXCAN_NO_GET_SIG_FUNCT_IDX{pad("COMABSMDLSAFE_RXCAN_NO_GET_SIG_FUNCT_IDX")}COMABSMDLSAFE_RXCAN_NUM_OF_GET_SIG_FUNCT')
        if sig_getarr_cnt > 0:
            print(f'#define COMABSMDLSAFE_RXCAN_NUM_OF_GET_SIG_U8ARR_FUNCT{pad("COMABSMDLSAFE_RXCAN_NUM_OF_GET_SIG_U8ARR_FUNCT")}{sig_getarr_cnt}U')
        else:
            print(f'#define COMABSMDLSAFE_RXCAN_NUM_OF_GET_SIG_U8ARR_FUNCT{pad("COMABSMDLSAFE_RXCAN_NUM_OF_GET_SIG_U8ARR_FUNCT")}1U')
        print(f'#define COMABSMDLSAFE_RXCAN_NO_GET_SIG_U8ARR_FUNCT_IDX{pad("COMABSMDLSAFE_RXCAN_NO_GET_SIG_U8ARR_FUNCT_IDX")}COMABSMDLSAFE_RXCAN_NUM_OF_GET_SIG_U8ARR_FUNCT')
        print('''
#define COMABSMDLSAFE_RXCAN_SIG_NR_ENABLE          0x01U
#define COMABSMDLSAFE_RXCAN_SIG_MISSING_ENABLE     0x02U
#define COMABSMDLSAFE_RXCAN_SIG_INVALID_ENABLE     0x04U
#define COMABSMDLSAFE_RXCAN_SIG_RETENTION_ENABLE   0x08U
#define COMABSMDLSAFE_RXCAN_SIG_ISO_SUPPORTED      0x10U
#define COMABSMDLSAFE_SET_BIT(datau8,bitpos)     ((datau8) |= (uint8)(1u<<(bitpos))) 
#define COMABSMDLSAFE_CLEAR_BIT(datau8,bitpos)   ((datau8) &= (uint8)(~(1U << (bitpos))))  
#define COMABSMDLSAFE_IS_BIT_SET(datau8,bitpos)  ((( (datau8) & ((uint8)(1u<<(bitpos)))) != 0U) ? TRUE : FALSE) 
/********************************************************************************************************************
*  PUBLIC TYPE DEFINITIONS                                                                                         *
********************************************************************************************************************/
typedef void(* ComAbsMdlSafe_RxCanGetSignalFunctPtrType)(uint8 *pSignalValue);
typedef void(* ComAbsMdlSafe_RxCanGetSignalU8ArrFunctPtrType)(uint8 *pSignalValue, uint32 *pSignalLength);
typedef boolean(*ComAbsMdlSafe_RxCanSignalInvalidCheckFuncPtrType)(void);
typedef uint8 ComAbsMdlSafe_RxCanSigMonitoringType;
typedef struct
{
    uint16 SignalLengthInByte;
    uint16 SignalBufferStartIdx;
    uint16 SignalInvalidIdx;
    uint16 SignalGetFunctIdx;
    ComAbsMdlSafe_RxCanSigMonitoringType RxSigMonitoringType;
    uint32 SignalMissingCounterValue;
} ComAbsMdlSafe_RxCanSignalConfigType;
typedef struct
{
    ComAbsMdlSafe_RxCanGetSignalFunctPtrType pGetSignalFunct;
} ComAbsMdlSafe_RxCanGetSignalFunctConfigType;
typedef struct
{
    uint16 SignalU8ArrBufferLenIdx;
    ComAbsMdlSafe_RxCanGetSignalU8ArrFunctPtrType pGetSignalU8ArrFunct;
} ComAbsMdlSafe_RxCanGetSignalU8ArrConfigType;
typedef struct
{
    uint32 SignalInvalidSigIdx;
    uint32 SignalInvalidCounterValue;
    ComAbsMdlSafe_RxCanSignalInvalidCheckFuncPtrType pSignalInvalidCheckFunc;
} ComAbsMdlSafe_RxCanSignalInvalidConfigType;
/********************************************************************************************************************
*  PUBLIC CONSTANT AND VARIABLE DECLARATIONS                                                                        *
********************************************************************************************************************/
extern const ComAbsMdlSafe_RxCanGetSignalFunctConfigType ComAbsMdlSafe_RxCanGetSignalFunctConfig[COMABSMDLSAFE_RXCAN_NUM_OF_GET_SIG_FUNCT];
extern const ComAbsMdlSafe_RxCanGetSignalU8ArrConfigType ComAbsMdlSafe_RxCanGetSignalU8ArrConfig[COMABSMDLSAFE_RXCAN_NUM_OF_U8ARR_SIG_CFG];
extern const ComAbsMdlSafe_RxCanSignalConfigType ComAbsMdlSafe_RxCanSignalConfig[eEndOfSafeRxSignal];
extern const ComAbsMdlSafe_RxCanSignalInvalidConfigType ComAbsMdlSafe_RxCanSignalInvalidConfig[COMABSMDLSAFE_RXCAN_NUM_OF_INVALID_SIGNALS]; 
extern uint8 ComAbsMdlSafe_RxCanSignalNRStatus[COMABSMDLSAFE_RXCAN_NUM_OF_NR_STATUS_BYTES];
extern uint8 ComAbsMdlSafe_RxCanSignalMissingStatus[COMABSMDLSAFE_RXCAN_NUM_OF_MISSING_STATUS_BYTES];
extern uint8 ComAbsMdlSafe_RxCanJustRcvdStatus[COMABSMDLSAFE_RXCAN_NUM_OF_JUST_RCVD_STATUS_BYTES];
extern uint8 ComAbsMdlSafe_RxCanSignalInvalidStatus[COMABSMDLSAFE_RXCAN_NUM_OF_SIGNAL_INVALID_STATUS_BYTES];
extern uint8 ComAbsMdlSafe_RxCanSignalInvalidCRCStatus[COMABSMDLSAFE_RXCAN_NUM_OF_SIGNAL_INVALID_CRC_STATUS_BYTES];
extern uint8 ComAbsMdlSafe_RxCanSignalInvalidAliveCounterStatus[COMABSMDLSAFE_RXCAN_NUM_OF_SIGNAL_INVALID_ALIVE_COUNTER_STATUS_BYTES];
extern uint8 ComAbsMdlSafe_RxCanSignalRepetationCounterStatus[COMABSMDLSAFE_RXCAN_NUM_OF_SIGNAL_REPETATION_STATUS_BYTES];
#ifdef COMABSMDLSAFE_RXCAN_ISO_SIGNAL_SUPPORTED
extern void ComAbsMdlSafe_RxIsoMainFunction(void);
#endif
// OnDataRx for ISO signals
''')
        for i, name in enumerate(sig_get_list):
            if sig_get_list_iso_support[i]:
                print(f'extern void CComAbsMdlSafe_OnDataRx_{name}(void);')
        for i, name in enumerate(sig_getarr_list):
            if sig_getarr_list_iso_support[i]:
                print(f'extern void CComAbsMdlSafe_OnDataRx_{name}(void);')
        print('''
#define COMABSMDLSAFE_SEC_CODE_STOP
#define COMABSMDLSAFE_CORE_CONST_SEC_END
#define COMABSMDLSAFE_CORE_DATA_SEC_END
#define COMABSMDLSAFE_CORE_BSS_SEC_END
#endif
/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/
''')
        sys.stdout = sys.__stdout__
        f.close()

    # ==================== Generate .c file ====================
    c_file_path = os.path.join("..\gen-files", "ComAbsMdlSafe_RxCfg.c")
    with open(c_file_path, "w") as f:
        sys.stdout = f
        print('''/********************************************************************************************************************
* C O P Y R I G H T                                                                                                 *
*********************************************************************************************************************
* Copyright (c) 2019 by Visteon Corporation.       All rights reserved.                                             *
*                                                                                                                   *
* NOTICE: This Is an unpublished work Of authorship, which contains trade secrets.                                  *
* Visteon Corporation owns all rights to this work And intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States    *
* Or those of any other country that may have jurisdiction, to protect this work as an unpublished work,            *
* in the event of an inadvertent Or deliberate unauthorized publication. Visteon Corporation also reserves its      *
* rights under all copyright laws to protect this work as a published work, when appropriate.                       *
* Those having access to this work may Not copy it, use it, modify it, Or disclose the information contained in it  *
* without the written authorization of Visteon Corporation.                                                         *
********************************************************************************************************************/
/*!*****************************************************************************************************************
*    @file ComAbsMdlSafe_RxCfg.c
*    @ingroup COMABSMDLSAFE
*    @brief This file contains the configuration of the COMABSMDLSAFE component.
*    Auto generated code in ''' + user_name + ''' at ''' + str(gen_time) + '''
********************************************************************************************************************/
#include "ComAbsMdlSafe.h"
#include "ComAbsMdlSafe_RxCfg.h"
#include "Rte_CComAbsMdlSafe_Type.h"
#include "E2E_P01.h"
#define COMABSMDLSAFE_SEC_CODE_START
#define COMABSMDLSAFE_CORE_CONST_SEC_START
#define COMABSMDLSAFE_CORE_DATA_SEC_START
#define COMABSMDLSAFE_CORE_BSS_SEC_START
#include "MemMap.h"
// Global status arrays
uint8 ComAbsMdlSafe_RxCanSignalNRStatus[COMABSMDLSAFE_RXCAN_NUM_OF_NR_STATUS_BYTES];
uint8 ComAbsMdlSafe_RxCanSignal_currentStatus[COMABSMDLSAFE_RXCAN_NUM_OF_NR_STATUS_BYTES];
uint8 ComAbsMdlSafe_RxCanJustRcvdStatus[COMABSMDLSAFE_RXCAN_NUM_OF_JUST_RCVD_STATUS_BYTES];
uint8 ComAbsMdlSafe_RxCanSignalMissingStatus[COMABSMDLSAFE_RXCAN_NUM_OF_MISSING_STATUS_BYTES];
uint8 ComAbsMdlSafe_RxCanSignalInvalidStatus[COMABSMDLSAFE_RXCAN_NUM_OF_SIGNAL_INVALID_STATUS_BYTES];
uint8 ComAbsMdlSafe_RxCanSignalInvalidCRCStatus[COMABSMDLSAFE_RXCAN_NUM_OF_SIGNAL_INVALID_CRC_STATUS_BYTES];
uint8 ComAbsMdlSafe_RxCanSignalInvalidAliveCounterStatus[COMABSMDLSAFE_RXCAN_NUM_OF_SIGNAL_INVALID_ALIVE_COUNTER_STATUS_BYTES];
uint8 ComAbsMdlSafe_RxCanSignalRepetationCounterStatus[COMABSMDLSAFE_RXCAN_NUM_OF_SIGNAL_REPETATION_STATUS_BYTES];
''')
        # =============== Declare one msg per unique message type: msg1, msg2, ... ===============
        unique_msg_types = []
        for sig in rx_signal_config:
            msg_name = sig['MsgName']
            if msg_name not in unique_msg_types:
                unique_msg_types.append(msg_name)
        print(f"\n// Last received message per message type")
        for i, msg_type in enumerate(unique_msg_types):
            print(f"static {msg_type} msg{i+1};")
        print()
        # =============== FORWARD DECLARATIONS of static getter functions ===============
                # Collect names for static CComAbsMdlSafe_OnDataRx_ functions
        static_ondatarx_names = set()
        for sig in rx_Ub_sig_list:
            if not sig['SignalIsoSupport']: # UB signals not ISO-supported can be static
                static_ondatarx_names.add(sig['SignalName'])
        for msg in rx_msg_list:
            if msg in rx_msg_key_sig_map: # All message-level callbacks can be static
                static_ondatarx_names.add(rx_msg_key_sig_map[msg])

        # Static forward declarations for CComAbsMdlSafe_OnDataRx_ functions
        if static_ondatarx_names:
            print('''/********************************************************************************************************************
*   Static forward declarations for OnDataRx functions
********************************************************************************************************************/''')
            for name in sorted(list(static_ondatarx_names)):
                print(f"static void CComAbsMdlSafe_OnDataRx_{name}(void);")
            print()
        
        print('''/********************************************************************************************************************
*   Forward declarations of static getter functions
********************************************************************************************************************/''')
        for sig in rx_signal_config:
            name = sig['SignalName']
            bits = sig['Lengthinbits']
            if bits <= 8:
                ctype = "uint8"
            elif bits <= 16:
                ctype = "uint16"
            elif bits <= 32:
                ctype = "uint32"
            else:
                ctype = "uint8"
            print(f"static void ComAbsMdlSafe_RxCanGet{name}_FromMsg({ctype} *pSignalValue);")
        print()
        # =============== Generate config tables ===============
        print(f"\nconst ComAbsMdlSafe_RxCanGetSignalFunctConfigType ComAbsMdlSafe_RxCanGetSignalFunctConfig[COMABSMDLSAFE_RXCAN_NUM_OF_GET_SIG_FUNCT] =")
        print("{")
        for i, name in enumerate(sig_get_list):
            null_or_ptr = "NULL_PTR" if sig_get_list_iso_support[i] else f"&ComAbsMdlSafe_RxCanGet{name}_FromMsg"
            comma = "" if i == len(sig_get_list)-1 else ","
            print(f"    {{ {null_or_ptr} }}{comma} /* {name} */")
        print("};")
        print(f"\nconst ComAbsMdlSafe_RxCanGetSignalU8ArrConfigType ComAbsMdlSafe_RxCanGetSignalU8ArrConfig[COMABSMDLSAFE_RXCAN_NUM_OF_U8ARR_SIG_CFG] =")
        print("    {")
        print("        /* { SignalU8ArrBufferLenIdx, ComAbsMdlSafe_RxCanGetSignalU8ArrFunctPtrType }*/")
        if sig_getarr_cnt > 0:
            len_idx = 0
            len_ret_idx = 0
            for i, sig in enumerate(rx_signal_config):
                if sig['LengthInBytes'] > 4:
                    idx = len_ret_idx if sig['ValueRetention'] else len_idx
                    null_or_ptr = "NULL_PTR" if sig['SignalIsoSupport'] else f"&ComAbsMdlSafe_RxCanGet{sig['SignalName']}_FromMsg"
                    comma = "" if i == sig_getarr_cnt - 1 else ","
                    print(f"        {{ {idx}u, {null_or_ptr} }}{comma} /* {sig['VSignalEnum']} */")
                    if sig['ValueRetention']:
                        len_ret_idx += 1
                    else:
                        len_idx += 1
        else:
            print("        {0u, NULL_PTR}")
        print("};")
        print(f"\nconst ComAbsMdlSafe_RxCanSignalConfigType ComAbsMdlSafe_RxCanSignalConfig[eEndOfSafeRxSignal] =")
        print("    {")
        print("        /* { SignalLengthInByte ,  SignalBufferStartIdx , SignalInvalidIdx , SignalGetFunctIdx ,")
        print("            RxSigMonitoringType , SignalMissingCounterValue } */")
        l_u8 = l_u8_ret = l_u16 = l_u16_ret = l_u32 = l_u32_ret = l_u64 = l_u64_ret = 0
        get_idx = 0
        getarr_idx = 0
        inv_idx = 0
        for i, sig in enumerate(rx_signal_config):
            bits = sig['Lengthinbits']
            bytes_len = sig['LengthInBytes']
            # Buffer start index
            if bits <= 8:
                buf_idx = l_u8 if not sig['ValueRetention'] else l_u8_ret
                if not sig['ValueRetention']: l_u8 += 1
                else: l_u8_ret += 1
            elif bits <= 16:
                buf_idx = l_u16 if not sig['ValueRetention'] else l_u16_ret
                if not sig['ValueRetention']: l_u16 += 1
                else: l_u16_ret += 1
            elif bits <= 32:
                buf_idx = l_u32 if not sig['ValueRetention'] else l_u32_ret
                if not sig['ValueRetention']: l_u32 += 1
                else: l_u32_ret += 1
            else:
                buf_idx = l_u64 if not sig['ValueRetention'] else l_u64_ret
                if not sig['ValueRetention']: l_u64 += bytes_len
                else: l_u64_ret += bytes_len
            # Get function index
            if bytes_len <= 4:
                getf_idx = get_idx
                get_idx += 1
            else:
                getf_idx = getarr_idx
                getarr_idx += 1
            # Invalid index
            if sig['SignalInvalidSupport']:
                inv_idx_val = inv_idx
                inv_idx += 1
            else:
                inv_idx_val = "COMABSMDLSAFE_RXCAN_NO_INVALDID_SIGNAL"
            # Flags
            flags = ["COMABSMDLSAFE_RXCAN_SIG_NR_ENABLE"]
            if sig['TimeoutValue'] > 0:
                flags.append("COMABSMDLSAFE_RXCAN_SIG_MISSING_ENABLE")
            if sig['SignalInvalidSupport']:
                flags.append("COMABSMDLSAFE_RXCAN_SIG_INVALID_ENABLE")
            if sig['ValueRetention']:
                flags.append("COMABSMDLSAFE_RXCAN_SIG_RETENTION_ENABLE")
            if sig['SignalIsoSupport']:
                flags.append("COMABSMDLSAFE_RXCAN_SIG_ISO_SUPPORTED")
            flag_str = " | ".join(flags)
            comma = "" if i == len(rx_signal_config)-1 else ","
            print(f"        {{{bytes_len}U, {buf_idx}U, {inv_idx_val}, {getf_idx}U, ({flag_str}), {int(sig['TimeoutValue']/10)}U}}{comma} /* {i} {sig['SignalName']} {sig['VSignalEnum']} */")
        print("};")
        print(f"\nconst ComAbsMdlSafe_RxCanSignalInvalidConfigType ComAbsMdlSafe_RxCanSignalInvalidConfig[COMABSMDLSAFE_RXCAN_NUM_OF_INVALID_SIGNALS] =")
        print("    {")
        print("        /* {  SignalInvalidSigIdx,  SignalInvalidCounterValue , pSignalInvalidCheckFunc } */")
        if sig_invalid_cnt > 0:
            for i, sig in enumerate(rx_signal_config):
                if sig['SignalInvalidSupport']:
                    counter = sig['SignalInvalidCounter']
                    func = f"&ComAbsMdlSafe_RxCanInvalid_{sig['SignalName']}" if sig['SignalInvalidSupport'] else "NULL_PTR"
                    comma = "" if i == sig_invalid_cnt - 1 else ","
                    print(f"        {{ {sig['VSignalEnum']}, {int(counter/10)}U, {func} }}{comma} /* {sig['SignalName']} */")
        else:
            print("        {0U, 0U, NULL_PTR}")
        print("};")
        # =============== Generate Safe Rx functions ===============
        for msg in rx_msg_list:
            if msg in rx_msg_key_sig_map:
                on_data = f"CComAbsMdlSafe_OnDataRx_{rx_msg_key_sig_map[msg]}"
                msg_index = unique_msg_types.index(msg) + 1
                msg_var = f"msg{msg_index}"
                print(f"\nvoid ComAbsMdlSafe_RxCanGetFrom_{msg}_Core(void)")
                print("{")
                print("    Std_ReturnType ret = RTE_E_OK;")
                print("    uint8 sig_id = 0u;")
                print(f"    {msg} local_msg;")
                print("    Rte_TransformerError transformerError;")
                print(f"    ret = Rte_Read_TrustecSWC_RP_RX_{msg}_RP_SR_TX_{msg}(&local_msg, &transformerError);")
                print("")
                print("    if (ret == RTE_E_NEVER_RECEIVED)")
                print("    {")
                print(f"        for (sig_id = 0u; sig_id < eEndOfSafeRxSignal; sig_id++)")
                print("        {")
                print("            COMABSMDLSAFE_SET_BIT(ComAbsMdlSafe_RxCanSignalNRStatus[sig_id >> 3U], (sig_id & 0x07U));")
                print("        }")
                print("    }")
                print("    else if (ret == RTE_E_HARD_TRANSFORMER_ERROR)")
                print("    {")
                print(f"        for (sig_id = 0u; sig_id < eEndOfSafeRxSignal; sig_id++)")
                print("        {")
                print("            COMABSMDLSAFE_SET_BIT(ComAbsMdlSafe_RxCanSignalInvalidStatus[sig_id >> 3U], (sig_id & 0x07U));")
                print("            COMABSMDLSAFE_CLEAR_BIT(ComAbsMdlSafe_RxCanSignalNRStatus[sig_id >> 3U], (sig_id & 0x07U));")
                print("            COMABSMDLSAFE_CLEAR_BIT(ComAbsMdlSafe_RxCanSignalMissingStatus[sig_id >> 3U], (sig_id & 0x07U));")
                print("        }")
                print("    }")
                print("    else if (ret == RTE_E_SOFT_TRANSFORMER_ERROR)")
                print("    {")
                print(f"        for (sig_id = 0u; sig_id < eEndOfSafeRxSignal; sig_id++)")
                print("        {")
                print(f"                {on_data}();")
                print("            if (transformerError.errorCode == E2E_P01STATUS_WRONGCRC)")
                print("            {")
                print("                COMABSMDLSAFE_SET_BIT(ComAbsMdlSafe_RxCanSignalInvalidCRCStatus[sig_id >> 3U], (sig_id & 0x07U));")
                print("            }")
                print("            else if (transformerError.errorCode == E2E_P01STATUS_WRONGSEQUENCE)")
                print("            {")
                print("                COMABSMDLSAFE_SET_BIT(ComAbsMdlSafe_RxCanSignalInvalidAliveCounterStatus[sig_id >> 3U], (sig_id & 0x07U));")
                print("            }")
                print("            else if (transformerError.errorCode == E2E_P01STATUS_REPEATED)")
                print("            {")
                print("                COMABSMDLSAFE_SET_BIT(ComAbsMdlSafe_RxCanSignalRepetationCounterStatus[sig_id >> 3U], (sig_id & 0x07U));")
                print("            }")
                print("            else if ((transformerError.errorCode == E2E_P01STATUS_SYNC) || (transformerError.errorCode == E2E_P01STATUS_INITIAL))")
                print("            {")
                print(f"                for (sig_id = 0u; sig_id < eEndOfSafeRxSignal; sig_id++)")
                print("                {")
                print("                    COMABSMDLSAFE_CLEAR_BIT(ComAbsMdlSafe_RxCanSignalNRStatus[sig_id >> 3U], (sig_id & 0x07U));")
                print("                    COMABSMDLSAFE_CLEAR_BIT(ComAbsMdlSafe_RxCanSignalInvalidStatus[sig_id >> 3U], (sig_id & 0x07U));")
                print("                    COMABSMDLSAFE_CLEAR_BIT(ComAbsMdlSafe_RxCanSignalInvalidCRCStatus[sig_id >> 3U], (sig_id & 0x07U));")
                print("                    COMABSMDLSAFE_CLEAR_BIT(ComAbsMdlSafe_RxCanSignalInvalidAliveCounterStatus[sig_id >> 3U], (sig_id & 0x07U));")
                print("                    COMABSMDLSAFE_CLEAR_BIT(ComAbsMdlSafe_RxCanSignalRepetationCounterStatus[sig_id >> 3U], (sig_id & 0x07U));")
                print("                }")
                print(f"                {msg_var} = local_msg;")
                print("            }")
                print("    else")
                print("    {")
                print("        // do nothing")
                print("    }")                
                print("  }")
                print("    }")
                print("    else if (ret == RTE_E_OK)")
                print("    {")
                print(f"        {on_data}();")
                print(f"        for (sig_id = 0u; sig_id < eEndOfSafeRxSignal; sig_id++)")
                print("        {")
                print("            COMABSMDLSAFE_CLEAR_BIT(ComAbsMdlSafe_RxCanSignalNRStatus[sig_id >> 3U], (sig_id & 0x07U));")
                print("            COMABSMDLSAFE_CLEAR_BIT(ComAbsMdlSafe_RxCanSignalInvalidStatus[sig_id >> 3U], (sig_id & 0x07U));")
                print("            COMABSMDLSAFE_CLEAR_BIT(ComAbsMdlSafe_RxCanSignalInvalidCRCStatus[sig_id >> 3U], (sig_id & 0x07U));")
                print("            COMABSMDLSAFE_CLEAR_BIT(ComAbsMdlSafe_RxCanSignalInvalidAliveCounterStatus[sig_id >> 3U], (sig_id & 0x07U));")
                print("            COMABSMDLSAFE_CLEAR_BIT(ComAbsMdlSafe_RxCanSignalRepetationCounterStatus[sig_id >> 3U], (sig_id & 0x07U));")
                print("        }")
                print(f"                {msg_var} = local_msg;")
                print("    }")
                print("    else")
                print("    {")
                print("        // do nothing")
                print("    }")
                print("}")
        # =============== Generate other callbacks (UB, ISO, invalid) ===============
        for sig in rx_Ub_sig_list:
            enum = sig['VSignalEnum']
            print(f'''\n/********************************************************************************************************************
*   @brief   This method is called from com on successful reception of the signal {sig['SignalName']}
********************************************************************************************************************/
void CComAbsMdlSafe_OnDataRx_{sig['SignalName']}(void)
{{
    COMABSMDLSAFE_CLEAR_BIT(ComAbsMdlSafe_RxCanSignalNRStatus[{enum} >> 3U], ({enum} & 0x7U));
    COMABSMDLSAFE_SET_BIT(ComAbsMdlSafe_RxCanJustRcvdStatus[{enum} >> 3U], ({enum} & 0x7U));
    COMABSMDLSAFE_SET_BIT(ComAbsMdlSafe_RxCanSignal_currentStatus[{enum} >> 3U], ({enum} & 0x7U));
    ComAbsMdlSafeReloadMissingTimer({enum});
}}''')
        # =============== Generate invalid check functions ===============
        for sig in rx_signal_config:
            if sig['LengthInBytes'] <= 4 and sig['SignalInvalidSupport']:
                ctype = "uint8" if sig['LengthInBytes'] == 1 else "uint16" if sig['LengthInBytes'] == 2 else "uint32"
                print(f'''\nboolean ComAbsMdlSafe_RxCanInvalid_{sig['SignalName']}(void)
{{
    {ctype} SignalValue = 0U;
    boolean Status = FALSE;
    ComAbsMdlSafe_RxCanGet{sig['SignalName']}_FromMsg(&SignalValue);
    // Invalid value: {sig['SignalInvalidVal']}
    if (''', end='')
                vals = str(sig['SignalInvalidVal']).split('|')
                for j, v in enumerate(vals):
                    if j > 0: print(" || ", end='')
                    if '-' in v:
                        lo, hi = v.strip('()').split('-')
                        print(f"(SignalValue >= {lo}U && SignalValue <= {hi}U)", end='')
                    else:
                        print(f"(SignalValue == {v.strip('()')}U)", end='')
                print(')')
                print('    {')
                print('        Status = TRUE;')
                print('    }')
                print('    return Status;')
                print('}')
        # =============== Generate ISO callbacks ===============
        for sig in rx_signal_config:
            if sig['SignalIsoSupport']:
                enum = sig['VSignalEnum']
                print(f'''\nvoid CComAbsMdlSafe_OnDataRx_{sig['SignalName']}(void)
{{
    COMABSMDLSAFE_CLEAR_BIT(ComAbsMdlSafe_RxCanSignalNRStatus[{enum} >> 3U], ({enum} & 0x7U));
    COMABSMDLSAFE_SET_BIT(ComAbsMdlSafe_RxCanJustRcvdStatus[{enum} >> 3U], ({enum} & 0x7U));
    COMABSMDLSAFE_SET_BIT(ComAbsMdlSafe_RxCanSignal_currentStatus[{enum} >> 3U], ({enum} & 0x7U));
    ComAbsMdlSafeReloadMissingTimer({enum});
}}''')
        # =============== GENERATE GETTER FUNCTIONS (Message-Aware) ===============
        print('''/********************************************************************************************************************
*   Getter functions for signals (message-aware: uses correct msg1, msg2, ...)
********************************************************************************************************************/''')
        # Map: MsgName -> msg1, msg2, ...
        msg_var_map = {msg: f"msg{i+1}" for i, msg in enumerate(unique_msg_types)}
        for sig in rx_signal_config:
            name = sig['SignalName']
            msg_name = sig['MsgName']
            msg_var = msg_var_map[msg_name]
            bits = sig['Lengthinbits']
            if bits <= 8:
                ctype = "uint8"
            elif bits <= 16:
                ctype = "uint16"
            elif bits <= 32:
                ctype = "uint32"
            else:
                ctype = "uint8"
            print(f"static void ComAbsMdlSafe_RxCanGet{name}_FromMsg({ctype} *pSignalValue)")
            print("{")
            if bits > 32:
                length_bytes = (bits + 7) // 8
                print(f"    memcpy(pSignalValue, {msg_var}.{name}, {length_bytes}U);")
            else:
                print(f"    *pSignalValue = {msg_var}.{name};")
            print("}")
        # =============== GENERATE MESSAGE OnDataRx CALLBACKS AT THE VERY END ===============
        print('''/********************************************************************************************************************
*   Message-level OnDataRx callbacks (updated for all signals in message)
********************************************************************************************************************/''')
        for msg in rx_msg_list:
            if msg in rx_msg_key_sig_map:
                key_sig = rx_msg_key_sig_map[msg]
                print(f'''\nvoid CComAbsMdlSafe_OnDataRx_{key_sig}(void)
{{''')
                for sig in rx_msg_sig_list[msg]:
                    enum = sig['VSignalEnum']
                    print(f"    COMABSMDLSAFE_CLEAR_BIT(ComAbsMdlSafe_RxCanSignalNRStatus[{enum} >> 3U], ({enum} & 0x7U));")
                    print(f"    COMABSMDLSAFE_SET_BIT(ComAbsMdlSafe_RxCanJustRcvdStatus[{enum} >> 3U], ({enum} & 0x7U));")
                    print(f"    COMABSMDLSAFE_SET_BIT(ComAbsMdlSafe_RxCanSignal_currentStatus[{enum} >> 3U], ({enum} & 0x7U));")
                    print(f"    ComAbsMdlSafeReloadMissingTimer({enum});")
                print("}")
        # =============== END OF FILE ===============
        print('''
#define COMABSMDLSAFE_SEC_CODE_STOP
#define COMABSMDLSAFE_CORE_CONST_SEC_END
#define COMABSMDLSAFE_CORE_DATA_SEC_END
#define COMABSMDLSAFE_CORE_BSS_SEC_END
#include "MemMap.h"
/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/
''')
        sys.stdout = sys.__stdout__
        f.close()

if __name__ == '__main__':
    excel_name = "E4.0_Intermediate_sheet.xlsx"
    if len(sys.argv) > 1:
        excel_name = sys.argv[1]
    current_time = datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    username = getpass.getuser()
    generate_code_comabs_rx_cfg(excel_name, username, current_time, output_dir=".")