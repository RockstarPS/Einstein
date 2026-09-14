import subprocess
import click
import ComAbsMdlExcelGen
import ComAbsMdlCodeGen
import ComAbsMdlTxCodeGen
import ComAbsMdlRxCodeGen
import datetime
import getpass

CONTEXT_SETTINGS = dict(help_option_names=['-h', '--help'])

@click.group(context_settings=CONTEXT_SETTINGS)
def main():
    pass

@main.command()
@click.option('--iexcel', '-iexcel', type=str,help="input ford SRD excel file name",required=True)
@click.option('--oexcel', '-oexcel', type=str,help="output excel configuration file name ",required=True)
@click.option('--dbc', '-dbc', type=str,help="input database file. "
                                                 "Usage - newtork_name:dbc_name,newtork_name:dbc_name.. ",required=True)
@click.option('--node','-node', type=str,help="Node name for the ECU",required=True)
@click.option('--inifile', '-inifile', type=str,help="tool configuration file",required=True)
def genexcel(iexcel,oexcel,dbc,node,inifile):
    dbc_list=[]
    for dbc_file in dbc.split(','):
        dbc_list.append({'network_name': dbc_file.split(':')[0], 'dbc_name': dbc_file.split(':')[1]})
    print("ComAbsMdl configuration Excel generation started ")
    #generate_comabs_cfg_excel_sheet(ford_srd_excel, dbc, node_name,output_excel)
    ComAbsMdlExcelGen.update_ini_cfg(inifile)
    ComAbsMdlExcelGen.generate_comabs_cfg_excel_sheet(iexcel,dbc_list[0]['dbc_name'],node,oexcel)
    print ("ComAbsMdl configuration Excel generation completed ")

@main.command()
@click.option('--iexcel', '-iexcel', type=str,help="ComAbsMdl  configuration excel input file",required=True)
def gencode(iexcel):
    current_time = datetime.datetime.now()
    username = getpass.getuser()
    print("ComAbsMdl configuration code generation started ")
    ComAbsMdlCodeGen.generate_code_comabsmdl(username,current_time)
    ComAbsMdlTxCodeGen.generate_code_comabs_tx_cfg(iexcel,username,current_time)
    ComAbsMdlRxCodeGen.generate_code_comabs_rx_cfg(iexcel,username,current_time)
    print("ComAbsMdl configuration code generation completed ")

if __name__ == '__main__':
    uint_testing = False
    try:
        subprocess.call(["taskkill", "/f", "/im", "EXCEL.EXE"])
    finally:
        pass

    if uint_testing is False:
        main()
    else:
        from timeit import default_timer as timer
        input_excel = "E4.0_Intermediate_sheet.xlsx"
        comabs_excel = "E4.0_Intermediate_sheet.xlsx"
        input_dbc = "PlatformDBCE4v7.dbc"
        node = "IC"
        current_time = datetime.datetime.now()
        username = getpass.getuser()
        genexcel = 0
        if genexcel:
            #generate the excel sheet
            start = timer()
            ComAbsMdlExcelGen.generate_comabs_cfg_excel_sheet(input_excel, input_dbc, node, comabs_excel)
            end = timer()
            print("generated in ",str(end - start)," seconds")
        else:
            #generate the code
            start = timer()
            ComAbsMdlCodeGen.generate_code_comabsmdl(username, current_time)
            ComAbsMdlTxCodeGen.generate_code_comabs_tx_cfg(comabs_excel, username, current_time)
            ComAbsMdlRxCodeGen.generate_code_comabs_rx_cfg(comabs_excel, username, current_time)
            end = timer()
            print("generated in ",str(end - start)," seconds")
