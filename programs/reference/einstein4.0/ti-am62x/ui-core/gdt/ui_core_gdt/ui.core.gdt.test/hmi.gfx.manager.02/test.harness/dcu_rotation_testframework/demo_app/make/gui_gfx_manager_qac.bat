echo "Setting QAC Env variables"

cd ..\qac\
set QACBIN=C:\PRQA\QAC-8.1.2-R\bin
set QACHELPFILES=C:\PRQA\QAC-8.1.2-R\help
set QAC_OUTPATH=output
set QAC_P_A= personalities\CORE_ANAL_8.1.2.p_a
set QAC_P_C= personalities\CORE_ANAL_8.1.2.p_c
set QAC_P_S= personalities\CORE_ANAL_8.1.2.p_s

set QAC_CONFIG = -via %QAC_P_A% -via %QAC_P_C% -via %QAC_P_S%
echo Executing QAC.exe
mkdir output
for /F %%i in (file_list.txt) do %QACBIN%\qac.exe -via %QAC_P_A% -via %QAC_P_C% -via %QAC_P_S% "src\%%i" -op %QAC_OUTPATH%
echo "Executing errdsp.exe"
for /F %%i in (file_list.txt) do %QACBIN%\errdsp.exe %QACBIN%\qac.exe -html+ -via %QAC_P_A% -via %QAC_P_C% -via %QAC_P_S% -html+ "src\%%i" -op "output" -file "%%i.html"
echo QAC successfully executed
exit 0