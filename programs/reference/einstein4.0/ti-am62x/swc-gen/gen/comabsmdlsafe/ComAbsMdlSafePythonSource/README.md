ComAbsMdlTxCodeGen.py	Generates safe TX COMABSMDL configuration (.c/.h)
ComAbsMdlRxCodeGen.py	Generates safe RX COMABSMDL configuration (.c/.h)
ComAbsMdlCodeGen.py	    Generates Safe COMABSMDL files(.c/.h)
main.py	                All the above .py are integrated in the main.py
dbc_to_excel.py         Generate Intermediate Sheet wrt the Input DBC

Steps to follow for Cfg files generation:
Step 1: User can place their DBC inside the Input_DBC folder
Step 2: open cmd from the path like below from the tool folder
C:\ComAbsMdlSafePythonSource\tool>
and run this command
python dbc_to_excel.py --dbc PlatformDBCE4v7.dbc --node IC
Step 3: Intermediate Sheet will get generated inside the Intermediate_Sheet folder
Step 4: User has to manually update the Timeout Value[Column F] Manually and verify
Step 5: Once the updation is done use the 
Below command to generate the cfg files generation
open cmd from the path like below
C:\ComAbsMdlSafePythonSource\tool>
and run this command
python main.py gencode -iexcel "Intermediate_sheet.xlsx"
Step 6: Config files are get generated inside the gen-files folder and user can integerate to their base.
