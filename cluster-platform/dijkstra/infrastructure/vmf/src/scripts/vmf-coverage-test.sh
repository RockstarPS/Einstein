#! /usr/bin/env bash

OUT_PATH=../gcov
OUT_FILE=VMF-Coverage.html
OUT_JS=VMF-Coverage.js

REDIRECT=" > NUL 2>&1"

SUM_COVERAGE=0
SUM_LINES_COUNT=0

# Function to parse GCOV output and write to OUT_FILE
parseOutput() {
    MY_FILE=$(echo $OUTPUT | awk -F"Lines executed:" '{print $1}')
    MY_LINES_EXEC=$(echo $OUTPUT | awk -F"Lines executed:" '{print $2}')
    MY_COVERAGE_PERCENT=$(echo $MY_LINES_EXEC | awk -F"%" '{print $1}')
    MY_LINES_COUNT=$(echo $MY_LINES_EXEC | awk -F"of " '{print $2}')
    MY_COVERAGE=$(echo $MY_COVERAGE_PERCENT $MY_LINES_COUNT | awk '{printf "%.2f", $1/100*$2}')
   
    SUM_COVERAGE=$(echo $SUM_COVERAGE $MY_COVERAGE | awk '{printf "%.2f", $1+$2}')
    SUM_LINES_COUNT=$(echo $SUM_LINES_COUNT $MY_LINES_COUNT | awk '{printf "%.2f", $1+$2}')
    
    # Print to OUT_FILE
    echo "<div class=\"file_container\">" >> $OUT_PATH/$OUT_FILE

    echo "<div class=\"file\">" >> $OUT_PATH/$OUT_FILE
    echo $MY_FILE >> $OUT_PATH/$OUT_FILE
    echo "</div>" >> $OUT_PATH/$OUT_FILE
    
    echo "<div class=\"coverage\">" >> $OUT_PATH/$OUT_FILE
    echo "Coverage: " $MY_COVERAGE_PERCENT "% of " $MY_LINES_COUNT " lines"  >> $OUT_PATH/$OUT_FILE
    echo "</div>" >> $OUT_PATH/$OUT_FILE
    
    echo "</div>" >> $OUT_PATH/$OUT_FILE
    echo "<br>" >> $OUT_PATH/$OUT_FILE
}


echo " "
echo " "
echo "*****************************************************************************************************************************"
echo "VMF coverage test started!"
echo "*****************************************************************************************************************************"

# kill vmf if running
if ps | grep vmf > NUL
then
    killall vmf
fi

# build vmf gcov variant
./clean.sh LINUX_X86_GCOV >NUL 2>&1
./build.sh LINUX_X86_GCOV >NUL 2>&1

# Copy gcov vmf libs to /usr/lib
sudo cp -f ../libs/LINUX_X86_GCOV/* /usr/lib

sleep 2

# build benchmark and gcov processes
myPWD=$PWD

cd ../test_processes/VmfPing
make PROJECT=LINUX_X86_GCOV AUTOMATED_BENCHMARK=TRUE clean all >NUL 2>&1

cd ../VmfGcovTest
make clean all >NUL 2>&1

cd $myPWD

# start vmf
VERSION=`../bin/LINUX_X86_GCOV/vmf -v`
EXECUTION_TIME=`date`
../bin/LINUX_X86_GCOV/vmf -p "../vmf/03_code/template" -i &

sleep 2

# start test processes
../test_processes/VmfGcovTest/bin/vmf_gcov -g 01 &
../test_processes/VmfPing/bin/vmf_listener -i 0 -g 01 -c 10 -s &
../test_processes/VmfPing/bin/vmf_sender -g 01 -e 02 -n 11223344 -l1000 -t -c 10 -d 0 -w 1 &


# wait until test processes finished
isActive="true"

while [ "$isActive" == "true" ]
do

    isActive="false"

    if ps | grep vmf_listener > NUL
    then
        isActive="true"    
    fi

    sleep 1
    
done

echo " "
echo "*****************************************************************************************************************************"
echo ">>> VMF coverage test finished! Results in ../gcov!!<<< "
echo "*****************************************************************************************************************************"

# kill gcov vmf
killall vmf

# Copy non-gcov vmf libs to /usr/lib
sudo cp -f ../libs/LINUX_X86/* /usr/lib
#export LD_LIBRARY_PATH=`pwd`/../libs/LINUX_X86/
#echo "LD_LIBRARY_PATH="$LD_LIBRARY_PATH



# Write HTML file OUT_FILE
mkdir -p $OUT_PATH
rm -rf $OUT_PATH/*

echo $VERSION > $OUT_PATH/version.txt
echo $EXECUTION_TIME >> $OUT_PATH/version.txt

echo "<html>" > $OUT_PATH/$OUT_FILE

echo "<head>" >> $OUT_PATH/$OUT_FILE
echo "<title>VMF Coverage</title>" >> $OUT_PATH/$OUT_FILE
echo "<link rel=\"stylesheet\" href=\"VMF-Coverage.css\">" >> $OUT_PATH/$OUT_FILE
echo "<script type=\"text/javascript\" src=\""$OUT_JS"\"></script>" >> $OUT_PATH/$OUT_FILE
echo "</head>" >> $OUT_PATH/$OUT_FILE

echo "<body>" >> $OUT_PATH/$OUT_FILE

echo "<div id=\"page-wrapper\">" >> $OUT_PATH/$OUT_FILE

echo "<h1>VMF coverage test results</h1>" >> $OUT_PATH/$OUT_FILE
echo "<h2>" >> $OUT_PATH/$OUT_FILE

echo "Version: " $VERSION >> $OUT_PATH/$OUT_FILE
echo "</h2>" >> $OUT_PATH/$OUT_FILE
echo "Execution Time: " $EXECUTION_TIME >> $OUT_PATH/$OUT_FILE

echo "<br>" >> $OUT_PATH/$OUT_FILE
echo "<br>" >> $OUT_PATH/$OUT_FILE

echo "<div id=\"overall_coverage\"></div>" >> $OUT_PATH/$OUT_FILE
echo "<meter id=\"overall_coverage_bar\" max=\"100\"></meter>" >> $OUT_PATH/$OUT_FILE

echo "<br>" >> $OUT_PATH/$OUT_FILE
echo "<br>" >> $OUT_PATH/$OUT_FILE

OUTPUT=`gcov -n -o ../obj/LINUX_X86_GCOV/vmf ../vmf/03_code/src/nw_vmf_client.c`
parseOutput
gcov -n -f -o ../obj/LINUX_X86_GCOV/vmf ../vmf/03_code/src/nw_vmf_client.c > $OUT_PATH/nw_vmf_client.c.txt
OUTPUT=`gcov -n -o ../obj/LINUX_X86_GCOV/vmf ../vmf/03_code/src/nw_vmf_client_uties.c`
parseOutput
gcov -n -f -o ../obj/LINUX_X86_GCOV/vmf ../vmf/03_code/src/nw_vmf_client_uties.c > $OUT_PATH/nw_vmf_client_uties.c.txt
OUTPUT=`gcov -n -o ../obj/LINUX_X86_GCOV/vmf ../vmf/03_code/src/nw_vmf_collector.c`
parseOutput
gcov -n -f -o ../obj/LINUX_X86_GCOV/vmf ../vmf/03_code/src/nw_vmf_collector.c > $OUT_PATH/nw_vmf_collector.c.txt
OUTPUT=`gcov -n -o ../obj/LINUX_X86_GCOV/vmf ../vmf/03_code/src/nw_vmf_controller.c`
parseOutput
gcov -n -f -o ../obj/LINUX_X86_GCOV/vmf ../vmf/03_code/src/nw_vmf_controller.c > $OUT_PATH/nw_vmf_controller.c.txt
OUTPUT=`gcov -n -o ../obj/LINUX_X86_GCOV/vmf ../vmf/03_code/src/nw_vmf_debug.c`
parseOutput
gcov -n -f -o ../obj/LINUX_X86_GCOV/vmf ../vmf/03_code/src/nw_vmf_debug.c > $OUT_PATH/nw_vmf_debug.c.txt
OUTPUT=`gcov -n -o ../obj/LINUX_X86_GCOV/vmf ../vmf/03_code/src/nw_vmf_ini_parser.c`
parseOutput
gcov -n -f -o ../obj/LINUX_X86_GCOV/vmf ../vmf/03_code/src/nw_vmf_ini_parser.c > $OUT_PATH/nw_vmf_ini_parser.c.txt
OUTPUT=`gcov -n -o ../obj/LINUX_X86_GCOV/vmf ../vmf/03_code/src/nw_vmf_ipc_shm.c`
parseOutput
gcov -n -f -o ../obj/LINUX_X86_GCOV/vmf ../vmf/03_code/src/nw_vmf_ipc_shm.c > $OUT_PATH/nw_vmf_ipc_shm.c.txt
OUTPUT=`gcov -n -o ../obj/LINUX_X86_GCOV/vmf ../vmf/03_code/src/nw_vmf_router.c`
parseOutput
gcov -n -f -o ../obj/LINUX_X86_GCOV/vmf ../vmf/03_code/src/nw_vmf_router.c > $OUT_PATH/nw_vmf_router.c.txt
OUTPUT=`gcov -n -o ../obj/LINUX_X86_GCOV/vmf ../vmf/03_code/src/nw_vmf_router_spy_queue.c`
parseOutput
gcov -n -f -o ../obj/LINUX_X86_GCOV/vmf ../vmf/03_code/src/nw_vmf_router_spy_queue.c > $OUT_PATH/nw_vmf_router_spy_queue.c.txt
OUTPUT=`gcov -n -o ../obj/LINUX_X86_GCOV/vmf ../vmf/03_code/src/nw_vmf_routing_db-core.c`
parseOutput
gcov -n -f -o ../obj/LINUX_X86_GCOV/vmf ../vmf/03_code/src/nw_vmf_routing_db-core.c > $OUT_PATH/nw_vmf_routing_db-core.c.txt
OUTPUT=`gcov -n -o ../obj/LINUX_X86_GCOV/vmf ../vmf/03_code/src/nw_vmf_routing_db-events.c`
parseOutput
gcov -n -f -o ../obj/LINUX_X86_GCOV/vmf ../vmf/03_code/src/nw_vmf_routing_db-events.c > $OUT_PATH/nw_vmf_routing_db-events.c.txt
OUTPUT=`gcov -n -o ../obj/LINUX_X86_GCOV/vmf ../vmf/03_code/src/nw_vmf_routing_db-memory.c`
parseOutput
gcov -n -f -o ../obj/LINUX_X86_GCOV/vmf ../vmf/03_code/src/nw_vmf_routing_db-memory.c > $OUT_PATH/nw_vmf_routing_db-memory.c.txt
OUTPUT=`gcov -n -o ../obj/LINUX_X86_GCOV/vmf ../vmf/03_code/src/nw_vmf_server.c`
parseOutput
gcov -n -f -o ../obj/LINUX_X86_GCOV/vmf ../vmf/03_code/src/nw_vmf_server.c > $OUT_PATH/nw_vmf_server.c.txt
OUTPUT=`gcov -n -o ../obj/LINUX_X86_GCOV/vmf ../vmf/03_code/src/nw_vmf_tardis.c`
parseOutput
gcov -n -f -o ../obj/LINUX_X86_GCOV/vmf ../vmf/03_code/src/nw_vmf_tardis.c > $OUT_PATH/nw_vmf_tardis.c.txt
OUTPUT=`gcov -n -o ../obj/LINUX_X86_GCOV/vmf ../vmf/03_code/src/nw_vmf_timer.c`
parseOutput
gcov -n -f -o ../obj/LINUX_X86_GCOV/vmf ../vmf/03_code/src/nw_vmf_timer.c > $OUT_PATH/nw_vmf_timer.c.txt
OUTPUT=`gcov -n -o ../obj/LINUX_X86_GCOV/vmf ../vmf/03_code/src/nw_vmf_logger.c`
parseOutput
gcov -n -f -o ../obj/LINUX_X86_GCOV/vmf ../vmf/03_code/src/nw_vmf_logger.c > $OUT_PATH/nw_vmf_logger.c.txt
OUTPUT=`gcov -n -o ../obj/LINUX_X86_GCOV/nw_config ../nw_os_config_linux/03_code/src/nw_os_config.c`
parseOutput
gcov -n -f -o ../obj/LINUX_X86_GCOV/nw_config ../nw_os_config_linux/03_code/src/nw_os_config.c > $OUT_PATH/nw_os_config.c.txt
OUTPUT=`gcov -n -o ../obj/LINUX_X86_GCOV/vmf_trace ../vmf_trace/03_code/src/nw_vmf_trace_server.c`
parseOutput
gcov -n -f -o ../obj/LINUX_X86_GCOV/vmf_trace ../vmf_trace/03_code/src/nw_vmf_trace_server.c > $OUT_PATH/nw_vmf_trace_server.c.txt
OUTPUT=`gcov -n -o ../obj/LINUX_X86_GCOV/vmf_trace ../vmf_trace/03_code/src/nw_vmf_sysinfo.c`
parseOutput
gcov -n -f -o ../obj/LINUX_X86_GCOV/vmf_trace ../vmf_trace/03_code/src/nw_vmf_sysinfo.c > $OUT_PATH/nw_vmf_sysinfo.c.txt
OUTPUT=`gcov -n -o ../obj/LINUX_X86_GCOV/vmf_trace ../vmf_trace/03_code/target_logging/src/nw_vmf_target_log.c`
parseOutput
gcov -n -f -o ../obj/LINUX_X86_GCOV/vmf_trace ../vmf_trace/03_code/target_logging/src/nw_vmf_target_log.c > $OUT_PATH/nw_vmf_target_log.c.txt
OUTPUT=`gcov -n -o ../obj/LINUX_X86_GCOV/vmf_trace_lib ../vmf_trace/03_code/src/nw_vmf_trace.c`
parseOutput
gcov -n -f -o ../obj/LINUX_X86_GCOV/vmf_trace_lib ../vmf_trace/03_code/src/nw_vmf_trace.c > $OUT_PATH/nw_vmf_trace.c.txt


echo "</div>"  >> $OUT_PATH/$OUT_FILE

echo "</body>" >> $OUT_PATH/$OUT_FILE
echo "</html>" >> $OUT_PATH/$OUT_FILE



# Write JavaScript file for displaying overall coverage bar
OUTPUT=$(echo $SUM_LINES_COUNT $SUM_COVERAGE | awk '{printf "%.2f", 100/$1*$2}')

echo "// generated by vmf-coverage-test.sh!" > $OUT_PATH/$OUT_JS
echo "var sum_lines_count=" $SUM_LINES_COUNT >> $OUT_PATH/$OUT_JS
echo "var sum_lines_covered=" $SUM_COVERAGE >> $OUT_PATH/$OUT_JS
echo "var percent_overall=" $OUTPUT >> $OUT_PATH/$OUT_JS
echo " " >> $OUT_PATH/$OUT_JS 
echo "window.onload = function()" >> $OUT_PATH/$OUT_JS 
echo "{" >> $OUT_PATH/$OUT_JS
echo "    document.getElementById('overall_coverage').innerText = \"Overall Coverage: \" + percent_overall.toFixed(2) + \" %\";" >> $OUT_PATH/$OUT_JS
echo "    document.getElementById('overall_coverage_bar').value = percent_overall;" >> $OUT_PATH/$OUT_JS
echo "    document.getElementById('overall_coverage_bar').style.display = 'block';" >> $OUT_PATH/$OUT_JS
echo "}" >> $OUT_PATH/$OUT_JS


