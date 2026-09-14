import openpyxl
from openpyxl import Workbook
from openpyxl.worksheet.datavalidation import DataValidation
import DbcParser
import re
import cantools
from collections import OrderedDict
import configparser

RxMsgCfgRowStartIndex = 4
RxMsgCfgSheetName = "SRD Receive Message List"
TxMsgCfgRowStartIndex = 3
TxMsgCfgSheetName = "SRD Transmit Message List"

def get_receive_cfg_ford_srd(ford_srd):
    """
    This method is used to parse the recevive signal from the ford SRD excel sheet
    :param ford_srd: Excel sheet of ford requirement
    :return:message_list - returns the list of receive messages
    message_config_dict - returns the dictionary of receive message with signal configuration
    Key: Message name
    Value:list of signal with its properties
    { 'SignalName': string , 'VSignalName':string , 'QfSupport':bool , 'QfSignal':string
        MissingSupport: bool, MissingTime:int , IsMissingSignalInitRequired:bool ,
        IsMissingSignalInitValue: int , UBSupport: bool ,
        SignalInvalidSupport: bool , SignalInvalidTime:int , SignalInvalidValue: int ,
        SignalInvalidInitSupport:bool , 'SignalInvalidInitValue': int
        'SignalInitTrigger': string (HS Init 1,HS Init 2,HS Init 3,HS Init 4)
    }
    """
    global RxMsgCfgRowStartIndex
    global RxMsgCfgSheetName

    work_book = openpyxl.load_workbook(ford_srd)
    receive_msg_sheet = work_book[RxMsgCfgSheetName]
    # print (receive_msg_sheet.max_column)
    row_val = RxMsgCfgRowStartIndex
    message_config_dict = {}
    message_list = []
    while receive_msg_sheet.cell(row=row_val, column=9).value is not None: #column 9 is Signal Name in HD sheet *garumug1*
        # check for oem link enable
        if isinstance(receive_msg_sheet.cell(row=row_val, column=10).value, str): #column 10 is VSignal Name in HD sheet *garumug1*
            vsignal_name = receive_msg_sheet.cell(row=row_val, column=10).value.replace(u"\xa0", u' ') #column 10 is VSignal Name in HD sheet *garumug1*
        else:
            vsignal_name = receive_msg_sheet.cell(row=row_val, column=10).value #column 10 is VSignal Name in HD sheet *garumug1*
        if receive_msg_sheet.cell(row=row_val, column=1).value == 'OEM' and vsignal_name is not None: #column 1 is VSignal Name in HD sheet *garumug1*
            # print(receive_msg_sheet.cell(row=row_val, column=11).value)
            # If OEM link enabled , add the signal to supported list
            if isinstance(receive_msg_sheet.cell(row=row_val, column=7).value, str):
                msg_name = receive_msg_sheet.cell(row=row_val, column=7).value.replace(u"\xa0", u' ').strip()
            else:
                msg_name = receive_msg_sheet.cell(row=row_val, column=7).value.strip()

            if isinstance(receive_msg_sheet.cell(row=row_val, column=9).value, str): #column 9 is Signal Name in HD sheet *garumug1*
                signal_name = receive_msg_sheet.cell(row=row_val, column=9).value.replace(u"\xa0", u' ').strip() #column 9 is Signal Name in HD sheet *garumug1*
            else:
                signal_name = receive_msg_sheet.cell(row=row_val, column=9).value.strip() #column 9 is Signal Name in HD sheet *garumug1*

            # if isinstance(receive_msg_sheet.cell(row=row_val, column=15).value, str):
                # qf_signal = receive_msg_sheet.cell(row=row_val, column=15).value.replace(u"\xa0", u' ').strip()
            # else:
                # qf_signal = "N/A"

            if isinstance(receive_msg_sheet.cell(row=row_val, column=19).value, str): #column 19 is Missing Signal Time in HD sheet *garumug1* 
                missing_time = receive_msg_sheet.cell(row=row_val, column=19).value.replace(u"\xa0", u' ').strip() #column 19 is Missing Signal Time in HD sheet *garumug1*
            else:
                missing_time = receive_msg_sheet.cell(row=row_val, column=19).value #column 19 is Missing Signal Time in HD sheet *garumug1*

            # if isinstance(receive_msg_sheet.cell(row=row_val, column=22).value, str):
                # missing_signal_buf_update = receive_msg_sheet.cell(row=row_val, column=22).value.replace(u"\xa0",
                                                                                                         # u' ').strip()
            # else:
                # missing_signal_buf_update = receive_msg_sheet.cell(row=row_val, column=22).value
            missing_signal_buf_update = "Yes" # since there is no matching column giving "Yes" *garumug1*
                
            if isinstance(receive_msg_sheet.cell(row=row_val, column=20).value, str): #column 20 is "Overwrite VSignal In for missing" in HD sheet *garumug1*
                missing_signal_buf_update_val = receive_msg_sheet.cell(row=row_val, column=20).value.replace(u"\xa0",
                                                                                                             u' ').strip() #column 20 is "Overwrite VSignal In for missing" in HD sheet *garumug1*
            else:
                missing_signal_buf_update_val = receive_msg_sheet.cell(row=row_val, column=20).value #column 20 is "Overwrite VSignal In for missing" in HD sheet *garumug1*

            # if isinstance(receive_msg_sheet.cell(row=row_val, column=24).value, str):
                # ub_support = receive_msg_sheet.cell(row=row_val, column=24).value.replace(u"\xa0", u' ').strip()
            # else:
                # ub_support = receive_msg_sheet.cell(row=row_val, column=24).value
            ub_support = 'N/A' # since there is no matching column giving "N/A" *garumug1*

            # if isinstance(receive_msg_sheet.cell(row=row_val, column=27).value, str):
                # invalid_value = receive_msg_sheet.cell(row=row_val, column=27).value.replace(u"\xa0", u' ').strip()
            # else:
                # invalid_value = receive_msg_sheet.cell(row=row_val, column=27).value

            # if isinstance(receive_msg_sheet.cell(row=row_val, column=28).value, str):
                # invalid_time = receive_msg_sheet.cell(row=row_val, column=28).value.replace(u"\xa0", u' ').strip()
            # else:
                # invalid_time = receive_msg_sheet.cell(row=row_val, column=28).value

            # if isinstance(receive_msg_sheet.cell(row=row_val, column=30).value, str):
                # invalid_signal_buf_update = receive_msg_sheet.cell(row=row_val, column=30).value.replace(u"\xa0",
                                                                                                         # u' ').strip()
            # else:
                # invalid_signal_buf_update = receive_msg_sheet.cell(row=row_val, column=30).value

            # if isinstance(receive_msg_sheet.cell(row=row_val, column=31).value, str):
                # invalid_signal_buf_update_val = receive_msg_sheet.cell(row=row_val, column=31).value.replace(u"\xa0",
                                                                                                             # u' ').strip()
            # else:
                # invalid_signal_buf_update_val = receive_msg_sheet.cell(row=row_val, column=31).value

            if isinstance(receive_msg_sheet.cell(row=row_val, column=16).value, str): #column 16 is "Signal Init Trigger" in HD sheet *garumug1*
                signal_init_trigger = receive_msg_sheet.cell(row=row_val, column=16).value.replace(u"\xa0",
                                                                                                   u' ').strip() #column 16 is "Signal Init Trigger" in HD sheet *garumug1*
            else:
                signal_init_trigger = receive_msg_sheet.cell(row=row_val, column=16).value #column 16 is "Signal Init Trigger" in HD sheet *garumug1*

            # add signal details
            sig_details = {'SignalName': signal_name, 'VSignalName': vsignal_name.strip()}
            # Qf support details
            # sig_details['QfSupport'] = False
            # sig_details['QfSignal'] = 'None'
            # if qf_signal is not None and isinstance(qf_signal, str):
                # if qf_signal.strip().upper() != 'N/A':
                    # sig_details['QfSupport'] = True
                    # sig_details['QfSignal'] = qf_signal

            # missing support details
            sig_details['MissingSupport'] = False
            sig_details['MissingTime'] = 0
            sig_details['IsMissingSignalInitRequired'] = False
            sig_details['IsMissingSignalInitValue'] = 0
            if isinstance(missing_time, str) and missing_time is not None:
                if missing_time.strip().upper() != 'N/A':
                    sig_details['MissingSupport'] = True
                    sig_details['MissingTime'] = missing_time
                    sig_details['IsMissingSignalInitRequired'] = False
                    sig_details['IsMissingSignalInitValue'] = 0
                    if missing_signal_buf_update is not None:
                        if missing_signal_buf_update == 'Yes':
                            sig_details['IsMissingSignalInitRequired'] = True
                            sig_details['IsMissingSignalInitValue'] = missing_signal_buf_update_val

            # UB details
            sig_details['UBSupport'] = False
            if isinstance(ub_support, str) and ub_support is not None:
                if ub_support.strip().upper() != 'N/A':
                    sig_details['UBSupport'] = True

            # invalid details

            # sig_details['SignalInvalidSupport'] = False
            # sig_details['SignalInvalidTime'] = 0
            # sig_details['SignalInvalidValue'] = 0
            # sig_details['SignalInvalidInitSupport'] = False
            # sig_details['SignalInvalidInitValue'] = 0
            # if isinstance(invalid_time, str) and invalid_time is not None:
                # if invalid_time.strip().upper() != 'N/A':
                    # sig_details['SignalInvalidSupport'] = True
                    # sig_details['SignalInvalidTime'] = invalid_time
                    # sig_details['SignalInvalidValue'] = invalid_value
                    # if invalid_signal_buf_update != 'N/A' and invalid_signal_buf_update is not None:
                        # sig_details['SignalInvalidInitSupport'] = True
                        # sig_details['SignalInvalidInitValue'] = invalid_signal_buf_update_val
            # Signal trigger used for retention
            sig_details['SignalInitTrigger'] = 'N/A'
            if signal_init_trigger != 'N/A' and signal_init_trigger is not None:
                sig_details['SignalInitTrigger'] = signal_init_trigger
            if msg_name not in message_list:
                message_list.append(msg_name)
                # add dummy signal list
                message_config_dict[msg_name] = [sig_details]
            else:
                message_config_dict[msg_name].append(sig_details)
            # print (message_config_list[msg_name])
        row_val += 1
    #print (message_list)
    return message_list, message_config_dict


def get_transmit_cfg_ford_srd(ford_srd):
    """
    This method is used to get the transmit configuration from the ford SRD.
    :param ford_srd:Excel sheet of ford requirement
    :return:message_list - returns the list of receive messages
    message_config_dict - returns the dict of receive message with signal configuration
    {
      'SignalName':  string,
      'VSignalName': string ,
      'SignalInitTrigger': string (HS Init 1,HS Init 2,HS Init 3,HS Init 4)
    }
    """
    global TxMsgCfgRowStartIndex
    global TxMsgCfgSheetName
    message_list=[]
    message_config_dict = {}
    # SRD Transmit Message List
    work_book = openpyxl.load_workbook(ford_srd)
    transmit_msg_sheet = work_book[TxMsgCfgSheetName]

    row_val = TxMsgCfgRowStartIndex
    while transmit_msg_sheet.cell(row=row_val, column=9).value is not None: # column 11 -> 9 is signal name in HD *garumug1*
        # check for oem link enable
        if isinstance(transmit_msg_sheet.cell(row=row_val, column=10).value, str) is True: # column 12 -> 10 is Vsignal name in HD *garumug1*
            vsignal_name = transmit_msg_sheet.cell(row=row_val, column=10).value.replace(u"\xa0", u' ').strip() # column 12 -> 10 is Vsignal name in HD *garumug1*
        else:
            vsignal_name = transmit_msg_sheet.cell(row=row_val, column=10).value # column 12 -> 10 is Vsignal name in HD *garumug1*
        if transmit_msg_sheet.cell(row=row_val, column=1).value == 'OEM' and vsignal_name is not None: # column 2 -> 1 is OEM in HD *garumug1*
            if isinstance(transmit_msg_sheet.cell(row=row_val, column=7).value, str) is True:
                msg_name = transmit_msg_sheet.cell(row=row_val, column=7).value.replace(u"\xa0", u' ').strip()
            else:
                msg_name = transmit_msg_sheet.cell(row=row_val, column=7).value.strip()
            if isinstance(transmit_msg_sheet.cell(row=row_val, column=9).value, str) is True: # column 11 -> 9 is Vsignal name in HD *garumug1*
                signal_name = transmit_msg_sheet.cell(row=row_val, column=9).value.replace(u"\xa0", u' ').strip() # column 11 -> 9 is Vsignal name in HD *garumug1*
            else:
                signal_name = transmit_msg_sheet.cell(row=row_val, column=9).value.strip() # column 11 -> 9 is Vsignal name in HD *garumug1*
            if isinstance(transmit_msg_sheet.cell(row=row_val, column=13).value, str) is True: # column 15 -> 13 is Vsignal name in HD *garumug1*
                signal_init_trigger = transmit_msg_sheet.cell(row=row_val, column=13).value.replace(u"\xa0",
                                                                                                    u' ').strip() # column 15 -> 13 is Vsignal name in HD *garumug1*
            else:
                signal_init_trigger = transmit_msg_sheet.cell(row=row_val, column=13).value # column 15 -> 13 is Vsignal name in HD *garumug1*
            signal_details = {'SignalName': signal_name, 'VSignalName': vsignal_name.strip(),
                              'SignalInitTrigger': 'N/A'}
            if signal_init_trigger != 'N/A' and signal_init_trigger is not None:
                signal_details['SignalInitTrigger'] = signal_init_trigger

            if msg_name not in message_list:
                message_list.append(msg_name)
                # add dummy signal list
                message_config_dict[msg_name] = [signal_details]
            else:
                message_config_dict[msg_name].append(signal_details)
        row_val += 1

    return message_list, message_config_dict


def get_number(num_str):
    if re.match("^(0x[0-9A-F]+|\d+)$", num_str, re.IGNORECASE):
        # <number>
        if re.match("^0x", num_str, re.IGNORECASE):
            return num_str  # "Signal Invalid Value"
        else:
            return hex(int(num_str))  # "Signal Invalid Value"


def validate_invalid_value(invalid_value, signal_name):
    invalid_value = invalid_value.replace("|", " | ")
    invalid_value = invalid_value.replace(",", " , ")
    invalid_value = invalid_value.replace("(", " ( ")
    invalid_value = invalid_value.replace(")", " ) ")
    invalid_value = invalid_value.replace("-", " - ")
    value_list = re.split("[\s\n\t\xa0]", invalid_value)
    temp_str = ''
    for val in value_list:
        val = val.strip()
        if re.match('(0x[a-z0-9]+)|[0-9\|\-,\(\)]+', val, re.IGNORECASE) is not None:
            if re.match('^[0-9]+$', val, re.IGNORECASE):
                val = hex(int(val))
            if val == ',':
                val = '|'
            temp_str += val

    if temp_str == '':
        temp_str = 0
    return temp_str


def generate_excel_sheet(tx_message_list, tx_message_cfg, rx_message_list, rx_message_cfg, output_excel):
    """
    This function is used to generate the excel sheet for the configuration
    :param tx_message_list: list of transmit messages
    :param tx_message_cfg: dict contains the signal cfg of the transmit messages
    :param rx_message_list: list of receive messages
    :param rx_message_cfg:dict contains the signal cfg of the receive messages
    :param output_excel : excel sheet name to be generated
    :return: None
    """

    # create workBook
    book = Workbook()
    rx_sheet = book.active
    rx_sheet.title = "RxSignals"
    SignalEnable_DV = DataValidation(type="list", formula1='"FALSE,TRUE"', allow_blank=True)
    rx_sheet.add_data_validation(SignalEnable_DV)

    # create validation rules
    # set the titles
    rx_sheet['A1'] = "Signal Name"
    rx_sheet['B1'] = "VSignal Name"
    rx_sheet['C1'] = "VSignal Enum"
    rx_sheet['D1'] = "Enable/Disable"
    rx_sheet['E1'] = "Length in bits"
    rx_sheet['F1'] = "Timeout Value in ms"
    rx_sheet['G1'] = "Message Name"
    rx_sheet['H1'] = "Dynamic signal  Enable/Disable"
    rx_sheet['I1'] = "Message Cbk Enable/Disable"
    rx_sheet['J1'] = "Signal Invalid  Enable/Disable"
    rx_sheet['K1'] = "Signal Invalid Value"
    rx_sheet['L1'] = "Signal Invalid Counter in ms"
    rx_sheet['M1'] = "Signal UB Enable/Disable"
    rx_sheet['N1'] = "Qf Enable/Disable"
    rx_sheet['O1'] = "Qf Signal"
    rx_sheet['P1'] = "SignalInitTrigger"
    rx_sheet['Q1'] = "Value Retention during Wakeup Enable /Disable"
    rx_sheet['R1'] = "Iso Signal Support"
    rx_sheet['S1'] = "Comments"
    rx_ws_row = 2
    ''''Timeout':sig_timeout,
        'SignalInvalid':SignalInvalid,
        'SignalInvalidValue':SignalInvalidValue,
        'SignalInvalidCounter':SignalInvalidCounter,
        'UB':UB,
        'Qf':Qf,
        "QfEnabled":QfEnabled'''

    '''
    { 'SignalName': string , 'VSignalName':string , 'QfSupport':bool , 'QfSignal':string
        MissingSupport: bool, MissingTime:int , IsMissingSignalInitRequired:bool ,
        IsMissingSignalInitValue: int , UBSupport: bool ,
        SignalInvalidSupport: bool , SignalInvalidTime:int , SignalInvalidValue: int ,
        SignalInvalidInitSupport:bool , 'SignalInvalidInitValue': int
        'SignalInitTrigger': string (HS Init 1,HS Init 2,HS Init 3,HS Init 4)
    }
    '''
    for rx_msg in rx_message_list:
        msg_cfg = rx_message_cfg[rx_msg]
        sig_cnt = 0
        for sig_cfg in msg_cfg:
            print (sig_cfg)
            rx_sheet['A' + str(rx_ws_row)] = sig_cfg['SignalName']  # signal name
            rx_sheet['B' + str(rx_ws_row)] = sig_cfg['VSignalName']  # VSignal Name
            # if In is present at the last remove the In
            # print(sig_cfg)
            # replacing  non-breaking space \xa0 with space character
            sig_cfg['VSignalName'] = sig_cfg['VSignalName'].replace(u'\xa0', u' ')
            if re.match(".* in", sig_cfg['VSignalName'], re.IGNORECASE) is not None:
                vsig_enum = re.split(" in", sig_cfg['VSignalName'], flags=re.IGNORECASE)[0]
            else:
                vsig_enum = sig_cfg['VSignalName']
            # print (vsig_enum)
            vsig_enum = re.sub(r"\W", "", vsig_enum)
            rx_sheet['C' + str(rx_ws_row)] = 'e' + vsig_enum + 'In'  # VSignal Enum
            SignalEnable_DV.add(rx_sheet['D' + str(rx_ws_row)])
            if re.match("\w*_UB$", sig_cfg['SignalName'], re.IGNORECASE) is not None:
                rx_sheet['D' + str(rx_ws_row)] = 'FALSE'  # Enable/Disable
            else:
                rx_sheet['D' + str(rx_ws_row)] = 'TRUE'  # Enable/Disable
            rx_sheet['E' + str(rx_ws_row)] = sig_cfg['SignalLength']  # length in bits
            # convert the value in milliseconds  format:1 sec, 1.6 sec , 0
            if type(sig_cfg['MissingTime']) is not int:
                if re.search(" sec$", sig_cfg['MissingTime'], re.IGNORECASE):
                    missing_val = sig_cfg['MissingTime'].lower().rpartition(" sec")[0]
                    missing_val = missing_val.strip()
                    if re.match("^\d*.\d*$", missing_val, re.IGNORECASE) is not None:
                        rx_sheet['F' + str(rx_ws_row)] = int(float(missing_val) * 1000)
                    else:
                        rx_sheet['F' + str(rx_ws_row)] = int(missing_val) * 1000
                else:
                    if re.search(" ms$", sig_cfg['MissingTime'], re.IGNORECASE):
                      missing_val = sig_cfg['MissingTime'].lower().rpartition(" ms")[0]
                      missing_val = missing_val.strip()
                      rx_sheet['F' + str(rx_ws_row)] = int(missing_val)
                    else:
                      rx_sheet['F' + str(rx_ws_row)] = sig_cfg['MissingTime']  # Timeout values
            else:
                rx_sheet['F' + str(rx_ws_row)] = sig_cfg['MissingTime']  # Timeout values
            rx_sheet['G' + str(rx_ws_row)] = rx_msg  # Message Name
            SignalEnable_DV.add(rx_sheet['H' + str(rx_ws_row)])
            rx_sheet['H' + str(rx_ws_row)] = 'FALSE'  # dynamic signal suppport
            SignalEnable_DV.add(rx_sheet['I' + str(rx_ws_row)])

            if re.match("\w*_UB$", sig_cfg['SignalName'], re.IGNORECASE) is None:
                if sig_cnt == 0 or sig_cfg['UBSupport'] is True:
                    rx_sheet['I' + str(rx_ws_row)] = "TRUE"  # callback enable
                else:
                    rx_sheet['I' + str(rx_ws_row)] = "FALSE"  # callback enable
                if sig_cfg['UBSupport'] is False:
                    sig_cnt += 1
            else:
                rx_sheet['I' + str(rx_ws_row)] = "FALSE"  # callback enable

            SignalEnable_DV.add(rx_sheet['J' + str(rx_ws_row)])
            # if sig_cfg['SignalInvalidSupport'] is True: *garumug1*
                # rx_sheet['J' + str(rx_ws_row)] = "TRUE"  # invlalid support
                # ''' Format :
                # <number>
                # <number>  - <number>
                # <text>  ( <number> )
                # <number> | <number> … | <number>
                # <number> | <number>  - <number>
                # N/A
                # numbers can be hex (0x10) or decimal (16)
                # '''
                # invalid_value = str(sig_cfg['SignalInvalidValue'])
                # invalid_value = invalid_value.strip()
                # print(invalid_value)
                # rx_sheet['K' + str(rx_ws_row)] = validate_invalid_value(invalid_value, sig_cfg['SignalName'])

                # if type(sig_cfg['SignalInvalidTime']) is not int:
                    # if re.search(" sec$", sig_cfg['SignalInvalidTime'], re.IGNORECASE) is not None:
                        # rx_sheet['L' + str(rx_ws_row)] = int(sig_cfg['SignalInvalidTime'].lower().rpartition(" sec")[
                                                                 # 0]) * 1000  # "Signal Invalid Counter in ms"
                    # elif re.search(" sample$", sig_cfg['SignalInvalidTime'], re.IGNORECASE) is not None:
                        # rx_sheet['L' + str(rx_ws_row)] = int(
                            # sig_cfg['SignalInvalidTime'].lower().rpartition(" sample")[0]) * 10
                    # else:
                        # rx_sheet['L' + str(rx_ws_row)] = sig_cfg['SignalInvalidTime']  # "Signal Invalid Counter in ms"
                # else:
                    # rx_sheet['L' + str(rx_ws_row)] = sig_cfg['SignalInvalidTime']  # "Signal Invalid Counter in ms"
            # else:
                # rx_sheet['J' + str(rx_ws_row)] = "FALSE"  # invlalid support
                # rx_sheet['K' + str(rx_ws_row)] = 0  # "Signal Invalid Value"
                # rx_sheet['L' + str(rx_ws_row)] = 0  # "Signal Invalid Counter in ms"

            # if the signal is qf , then the dependent signal should be enabled for invalid processing. The signal with
            # Qf should be disabled

            # if re.match("\w*_Qf$", sig_cfg['SignalName'], re.IGNORECASE) is not None:
                # rx_sheet['J' + str(rx_ws_row)] = "FALSE"

            # if sig_cfg['QfSupport'] is True:
                # rx_sheet['J' + str(rx_ws_row)] = "TRUE"

            # UB support
            # SignalEnable_DV.add(rx_sheet['M' + str(rx_ws_row)])
            # if sig_cfg['UBSupport'] is True:
                # rx_sheet['M' + str(rx_ws_row)] = "TRUE"
            # else:
                # rx_sheet['M' + str(rx_ws_row)] = "FALSE"
            # SignalEnable_DV.add(rx_sheet['N' + str(rx_ws_row)])
            # if sig_cfg['QfSupport'] is True:
                # rx_sheet['N' + str(rx_ws_row)] = 'TRUE'
                # if re.match("\w* in.*$", sig_cfg['QfSignal'], re.IGNORECASE) is not None:
                    # rx_sheet['O' + str(rx_ws_row)] = 'e' + sig_cfg['QfSignal'].rpartition(" ")[0] + 'In'
                # else:
                    # rx_sheet['O' + str(rx_ws_row)] = 'e' + sig_cfg['QfSignal'] + 'In'
            # else:
                # rx_sheet['N' + str(rx_ws_row)] = 'FALSE'
                # rx_sheet['O' + str(rx_ws_row)] = 'None'
            rx_sheet['J' + str(rx_ws_row)] = "FALSE"  # invlalid support
            rx_sheet['K' + str(rx_ws_row)] = 0  # "Signal Invalid Value"
            rx_sheet['L' + str(rx_ws_row)] = 0  # "Signal Invalid Counter in ms"
            rx_sheet['M' + str(rx_ws_row)] = "FALSE"
            rx_sheet['N' + str(rx_ws_row)] = 'FALSE'
            rx_sheet['O' + str(rx_ws_row)] = 'None'						
				
            rx_sheet['P' + str(rx_ws_row)] = sig_cfg['SignalInitTrigger']
            SignalEnable_DV.add(rx_sheet['Q' + str(rx_ws_row)])
            if re.match("HS Init [14]", sig_cfg["SignalInitTrigger"].strip(), re.IGNORECASE) is not None:
                rx_sheet['Q' + str(rx_ws_row)] = 'TRUE'
            else:
                rx_sheet['Q' + str(rx_ws_row)] = 'FALSE'
            SignalEnable_DV.add(rx_sheet['R' + str(rx_ws_row)])
            rx_sheet['R' + str(rx_ws_row)] = 'FALSE'
            rx_ws_row += 1
            # print(sig_cfg)

    tx_sheet = book.create_sheet("TxSignals")
    SignalEnable_tx_DV = DataValidation(type="list", formula1='"FALSE,TRUE"', allow_blank=True)
    tx_sheet.add_data_validation(SignalEnable_tx_DV)
    # set the titles
    current_sheet = book["TxSignals"]
    current_sheet['A1'] = "Signal Name"
    current_sheet['B1'] = "VSignal Name"
    current_sheet['C1'] = "VSignal Enum"
    current_sheet['D1'] = "Enable / Disable"
    current_sheet['E1'] = "Length in bits"
    current_sheet['F1'] = "Message Name"
    current_sheet['G1'] = "Message Cbk Enable / Disable"
    current_sheet['H1'] = "SignalTxConfirmation Enable / Disable"
    current_sheet['I1'] = "Value Retention during Wakeup Enable /Disable"
    current_sheet['J1'] = "Signal Init Trigger"
    current_sheet['K1'] = "DynamicLength  Enable / Disable"
    current_sheet['L1'] = "Iso Signal Support"
    current_sheet['M1'] = "Comments"

    tx_ws_row = 2
    '''{
          'SignalName':  string,
          'VSignalName': string ,
          'SignalInitTrigger': string (HS Init 1,HS Init 2,HS Init 3,HS Init 4)
        }'''
    for tx_msg in tx_message_list:
        msg_cfg = tx_message_cfg[tx_msg]
        sig_cnt = 0
        for sig_cfg in msg_cfg:
            current_sheet['A' + str(tx_ws_row)] = sig_cfg["SignalName"]  # signal name
            current_sheet['B' + str(tx_ws_row)] = sig_cfg["VSignalName"]  # Vsignal name
            # replacing  non-breaking space \xa0 with space character
            sig_cfg['VSignalName'] = sig_cfg['VSignalName'].replace(u'\xa0', u' ')
            # if Out is present at the last remove the Out
            if re.match(".* out", sig_cfg['VSignalName'], re.IGNORECASE) is not None:
                vsig_enum = re.split(" out", sig_cfg['VSignalName'], flags=re.IGNORECASE)[0]
            else:
                vsig_enum = sig_cfg['VSignalName']
            # print (vsig_enum)
            vsig_enum = re.sub(r"\W", "", vsig_enum)
            current_sheet['C' + str(tx_ws_row)] = 'e' + vsig_enum + 'Out'  # VSignal Enum

            SignalEnable_tx_DV.add(current_sheet['D' + str(tx_ws_row)])
            if re.match("\w*_UB$", sig_cfg['SignalName'], re.IGNORECASE) is not None:
                current_sheet['D' + str(tx_ws_row)] = "FALSE"  # Enable/Disable
            else:
                current_sheet['D' + str(tx_ws_row)] = "TRUE"  # Enable/Disable

            current_sheet['E' + str(tx_ws_row)] = sig_cfg['SignalLength']  # length in bits
            current_sheet['F' + str(tx_ws_row)] = tx_msg  # Msg name
            SignalEnable_tx_DV.add(current_sheet['G' + str(tx_ws_row)])
            current_sheet['G' + str(tx_ws_row)] = "FALSE"  # "Message Cbk Enable / Disable"

            SignalEnable_tx_DV.add(current_sheet['H' + str(tx_ws_row)])
            if sig_cnt == 0:
                current_sheet['H' + str(tx_ws_row)] = "TRUE"  # "SignalTxConfirmation Enable / Disable"
            else:
                current_sheet['H' + str(tx_ws_row)] = "FALSE"  # "SignalTxConfirmation Enable / Disable"
            sig_cnt += 1
            SignalEnable_tx_DV.add(current_sheet['I' + str(tx_ws_row)])
            if re.match("HS Init [14]", sig_cfg["SignalInitTrigger"].strip(), re.IGNORECASE) is not None:
                current_sheet['I' + str(tx_ws_row)] = "TRUE"  # "Value Retention during Wakeup Enable /Disable"
            else:
                current_sheet['I' + str(tx_ws_row)] = "FALSE"  # "Value Retention during Wakeup Enable /Disable"

            current_sheet['J' + str(tx_ws_row)] = sig_cfg["SignalInitTrigger"]  # "Init trigger"
            SignalEnable_tx_DV.add(current_sheet['K' + str(tx_ws_row)])
            current_sheet['K' + str(tx_ws_row)] = "FALSE"  # "DynamicLength  Enable / Disable"
            SignalEnable_tx_DV.add(current_sheet['L' + str(tx_ws_row)])
            current_sheet['L' + str(tx_ws_row)] = "FALSE"  # "Iso signal support"
            tx_ws_row += 1
    book.save(output_excel)


def get_msg_signal_cfg_from_dbc_v1(dbc_file, node_name):
    '''
    This method uses the cantools parser
    :param dbc_file:
    :param node_name:
    :return:
    '''

    dbc = cantools.load_file(dbc_file)
    # print (dbc.get_node_by_name("APIM_CDC"))
    tx_msg = {}
    rx_msg = {}
    for msg in dbc.messages:
        # print (type(msg),msg)
        if node_name in msg.senders:
            tx_msg[msg.frame_id] = msg
        for sig in msg.signals:
            if node_name in sig.receivers:
                rx_msg[msg.frame_id] = msg
                break

    ord_dict_tx = OrderedDict(sorted(tx_msg.items()))
    ord_dict_rx = OrderedDict(sorted(rx_msg.items()))
    sorted_mes_tx = []
    sorted_mes_rx = []
    # print (len(rx_msg),OrderedDict(sorted(rx_msg.items())))

    for txmsg in ord_dict_tx:
        sig_list = {}
        for txsig in ord_dict_tx[txmsg].signals:
            sig_list[txsig.name]= {'SignalName': txsig.name, 'Len': txsig.length,'SignalNameWithoutId':txsig.name}
        sorted_mes_tx.append({'Msg_name': ord_dict_tx[txmsg].name, 'Sig_List': sig_list})

    for rxmsg in ord_dict_rx:
        sig_list = {}
        for rxsig in ord_dict_rx[rxmsg].signals:
            sig_list[rxsig.name]={'SignalName': rxsig.name, 'Len': rxsig.length,'SignalNameWithoutId':rxsig.name}
        sorted_mes_rx.append({'Msg_name': ord_dict_rx[rxmsg].name, 'Sig_List': sig_list})

    return sorted_mes_tx, sorted_mes_rx

def get_msg_signal_cfg_from_dbc(dbc_file, node_name):
    """
    This method is used to get the message and signal configuration from the can database
    :param dbc_file: name of the database file
    :param node_name: node name from which message and signal to be fetched
    :return: sorted_mes_tx : list of transmit message and its properties
    sorted_mes_rx : list of transmit message and its properties
    """
    dbc = DbcParser.dbc_parser(dbc_file, node_name, 0)
    # dbc = DbcParser.dbc_parser(dbc_name, node, channel_id)
    # print(dbc_name, node)
    tp_generic_config = 'TpMessage'
    nm_generic_config = 'NmMessage'
    il_generic_config = 'GenMsgIlSupport'
    sorted_mes_tx = []
    sorted_mes_rx = []
    msg_tx = []
    msg_rx = []
    msg_tx.extend(dbc.get_msg_type(il_generic_config, 'tx'))
    msg_tx.extend(dbc.get_msg_type(nm_generic_config, 'tx'))
    msg_tx.extend(dbc.get_msg_type(tp_generic_config, 'tx'))

    msg_rx.extend(dbc.get_msg_type(il_generic_config, 'rx'))
    msg_rx.extend(dbc.get_msg_type(nm_generic_config, 'rx'))
    msg_rx.extend(dbc.get_msg_type(tp_generic_config, 'rx'))
    # sorted list
    sorted_mes_tx.extend(sorted(msg_tx, key=lambda x: int(x['id'])))
    sorted_mes_rx.extend(sorted(msg_rx, key=lambda x: int(x['id'])))

    return sorted_mes_tx, sorted_mes_rx


def generate_comabs_cfg_excel_sheet(ford_srd_excel, dbc, node_name, output_excel="s2dot.xlsx"):
    """
    This method is used to generate the comabsmdl excel sheet for the transmit and receive configuration
    :param output_excel: output excel file
    :param ford_srd_excel: ford_srd_excel file
    :param dbc: dbc file
    :param node_name: node name from which message and signal to be fetched
    :return:
    """
    # Get signal configuration list from the excel sheet
    tx_message_list, tx_message_cfg = get_transmit_cfg_ford_srd(ford_srd_excel)
    rx_message_list, rx_message_cfg = get_receive_cfg_ford_srd(ford_srd_excel)
    # Get signal length from the database
    #dbc_tx_msg_list, dbc_rx_msg_list = get_msg_signal_cfg_from_dbc(dbc, node_name)
    dbc_tx_msg_list, dbc_rx_msg_list = get_msg_signal_cfg_from_dbc_v1(dbc, node_name)

    ''' Msg_name , Sig_List :[{sig:{Len:,SignalName:}]'''
    for msg in dbc_tx_msg_list:
        if msg['Msg_name'] in tx_message_list:
            sig_length = {}
            for sig in msg['Sig_List']:
                # print (msg['Sig_List'][sig]['Len'])
                sig_length[msg['Sig_List'][sig]['SignalNameWithoutId']] = msg['Sig_List'][sig]['Len']
            sig_cnt = 0
            for signals in tx_message_cfg[msg['Msg_name']]:
                if signals["SignalName"] in sig_length:
                    tx_message_cfg[msg['Msg_name']][sig_cnt]['SignalLength'] = int(sig_length[signals["SignalName"]])
                else:
                    print("Warning!!!! Transmit Signal not avaiable in database: ", signals["SignalName"])
                    tx_message_cfg[msg['Msg_name']][sig_cnt]['SignalLength'] = 0
                sig_cnt += 1

    for msg in dbc_rx_msg_list:
        if msg['Msg_name'] in rx_message_list:
            sig_length = {}
            for sig in msg['Sig_List']:
                sig_length[msg['Sig_List'][sig]['SignalNameWithoutId']] = msg['Sig_List'][sig]['Len']
            sig_cnt = 0
            for signals in rx_message_cfg[msg['Msg_name']]:
                if signals["SignalName"] in sig_length:
                    rx_message_cfg[msg['Msg_name']][sig_cnt]['SignalLength'] = int(sig_length[signals["SignalName"]])
                else:
                    print("Warning!!!! Receive Signal not avaiable in database: ", signals["SignalName"])
                    rx_message_cfg[msg['Msg_name']][sig_cnt]['SignalLength'] = 0
                sig_cnt += 1

    generate_excel_sheet(tx_message_list, tx_message_cfg, rx_message_list, rx_message_cfg, output_excel)

def update_ini_cfg(ini_file='ComAbsGen.ini'):
    "ComAbsGen.ini"
    global RxMsgCfgRowStartIndex,RxMsgCfgSheetName,TxMsgCfgRowStartIndex,TxMsgCfgSheetName
    ComAbsCfg = configparser.ConfigParser()
    #if 1:
    try:
        ComAbsCfg.read(ini_file)

        RxMsgCfgRowStartIndex = int(ComAbsCfg["RxMsgCfg"]["RxMsgCfgRowStartIndex"].strip())
        print(RxMsgCfgRowStartIndex)
        RxMsgCfgSheetName = ComAbsCfg["RxMsgCfg"]["RxMsgCfgSheetName"].strip()
        TxMsgCfgRowStartIndex = int(ComAbsCfg["TxMsgCfg"]["TxMsgCfgRowStartIndex"].strip())
        TxMsgCfgSheetName = ComAbsCfg["TxMsgCfg"]["TxMsgCfgSheetName"].strip()
    except:
        print('INI file not found/Error in INI file.Default value is used."\n'
              '        RxMsgCfgRowStartIndex = 4\n'
              '        RxMsgCfgSheetName = "SRD Receive Message List"\n'
              '        TxMsgCfgRowStartIndex = 4\n'
              '        TxMsgCfgSheetName = "SRD Transmit Message List"'
              )
        RxMsgCfgRowStartIndex = 4
        RxMsgCfgSheetName = "SRD Receive Message List"
        TxMsgCfgRowStartIndex = 3
        TxMsgCfgSheetName = "SRD Transmit Message List"

    #'''
if __name__ == '__main__':
    update_ini_cfg()
    ford_srd_name = "v31.xlsm"
    dbc = "Y2021_FNV3_CMDB_v21.02_HS3_1.dbc"
    node_name = "IPC"
    generate_comabs_cfg_excel_sheet(ford_srd_name, dbc, node_name,"ford_s2dot_v70_1.xlsx")
