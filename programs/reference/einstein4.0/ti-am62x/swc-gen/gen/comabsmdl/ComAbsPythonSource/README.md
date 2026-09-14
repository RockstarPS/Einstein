ComAbsMdlTxCodeGen.py	Generates safe TX COMABSMDL configuration (.c/.h)
ComAbsMdlRxCodeGen.py	Generates safe RX COMABSMDL configuration (.c/.h)
ComAbsMdlCodeGen.py	    Generates Safe COMABSMDL files(.c/.h)
main.py	                All the above .py are integrated in the main.py

/*Below is the command we need to use it for the cfg files generation*/
open cmd from the path like below
C:\ComAbsPythonSource>
and run this command
python main.py gencode -iexcel "E4.0_Intermediate_sheet.xlsx"
