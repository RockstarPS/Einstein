#!/bin/bash

# 1. Set environment variable KW_DIR_ENV in .bashrc file to specify 
#   path to klockwork directory 
#
#   For example, run below command
#       echo 'export KW_DIR_ENV="path/to/kw-cli-23.4.lin64"' >> ~/.bashrc
#       source ~/.bashrc

# 2. Set environment variable KW_OUTPUTTOCSV_ENV in .bashrc file 
#   to specify path to klocwork utitily output2csv 
#
#   For example, run below command
#       export KW_OUTPUTTOCSV_ENV="path/to/kwoutputtocsv/Linux"
#       source ~/.bashrc

# 3. To run this script, give command
#    bash ./run_kw.sh program_code

# Uncomment below line for debugging purposes only
# set -x

# Change directory to the script's directory 
cd "$(dirname "$0")"

# Exit immediately if any command fails
set -eo pipefail 

# Logging function
log() {
    echo "$(date +'%Y-%m-%d %H:%M:%S') - $1"
}

KW_SCRIPT_DIR="$(pwd)"

# Set Klocwork directory path
if [ -n "$KW_DIR_ENV" ]; then
  KW_DIR="$KW_DIR_ENV"
else
  log "ERROR: Environment variable 'KW_DIR_ENV' for klocwork directory is not set"
  exit 1
fi

# Set Klocwork output2csv utility path
if [ -n "$KW_OUTPUTTOCSV_ENV" ]; then
  KW_OUTPUTTOCSV="$KW_OUTPUTTOCSV_ENV"
else
  log "ERROR: Environment variable 'KW_OUTPUTTOCSV_ENV' for klocwork output2csv utility is not set"
  exit 1
fi

if [ "$1" == "r2g" ]; then
    
    # Build and clean commands
    BUILD_COMMAND="dn build --type vpcm7debug"
    CLEAN_COMMAND="dn build --type vpcm7debugclean"

    # Klocwork server and stream details
    URL="https://kw.group5.visteon.com:8443"
    STREAM="RE_DI_VPCM/RE_DI_R2G_VPCM7_MY25_EP27213_INT"
    
    # project directory
    PROJ_DIR="$KW_SCRIPT_DIR/../../../../../../../../../../../"
    
    # path for analysis
    GDT_PATH="$PROJ_DIR/programs/royale/my2025/r2g/ui-core-gdt/"
  
elif [ "$1" == "n597" ]; then
  
    # Build and clean commands
    BUILD_COMMAND="dn build --type vpdebug"
    CLEAN_COMMAND="dn build --type vpdebugclean"

    # Klocwork server and stream details
    URL="https://kw.group5.visteon.com:8443"
    STREAM="TVS_DI_GIP/TVS_DI_N597_GIP_MY24_EP27219_INT"
    
    # project directory
    PROJ_DIR="$KW_SCRIPT_DIR/../../../../../../../../../../../"
    
    # path for analysis
    GDT_PATH="$PROJ_DIR/programs/tvs/my2023/n597/ui-core-gdt/"
  
elif [ "$1" == "acza" ]; then
  
    # Build and clean commands
    BUILD_COMMAND="dn build --type vpdebug"
    CLEAN_COMMAND="dn build --type vpdebugclean"

    # Klocwork server and stream details
    URL="https://kw.group5.visteon.com:8443"
    STREAM="HERO_DI_VIP/HERO_DI_IC-RAAA-ACZA_VIP_MY25_EP29420_INT"
    
    # project directory
    PROJ_DIR="$KW_SCRIPT_DIR/../../../../../../../../../../../"
    
    # path for analysis
    GDT_PATH="$PROJ_DIR/programs/hero/my2025/acza/ui-core-gdt/"
  
elif [ "$1" == "p3f2" ]; then
  
    # Build and clean commands
    BUILD_COMMAND="dn build --type vpcm7debug"
    CLEAN_COMMAND="dn build --type vpcm7debugclean"

    # Klocwork server and stream details
    URL="https://kw.group5.visteon.com:8443"
    STREAM="RE_DI_VPCM_EP30962/RE_DI_P3F2_VPCM7_MY25_EP30962"
    
    # project directory
    PROJ_DIR="$KW_SCRIPT_DIR/../../../../../../../../../../../"
    
    # path for analysis
    GDT_PATH="$PROJ_DIR/programs/royale/my2024/p3f2/ui-core-gdt/"
  
elif [ "$1" == "l1a" ]; then
  
    # Build and clean commands
    BUILD_COMMAND="dn build --type vpdebug"
    CLEAN_COMMAND="dn build --type vpdebugclean"

    # Klocwork server and stream details
    URL="https://kw.group5.visteon.com:8443"
    STREAM="RE_DI_L1_VIP/RE_DI_L1_VIP_MY25_EP29398_INT"
    
    # project directory
    PROJ_DIR="$KW_SCRIPT_DIR/../../../../../../../../../"
    
    # path for analysis
    GDT_PATH="$PROJ_DIR/cluster-platform/gui/gdt/"
  
elif [ "$1" == "bmic" ]; then

    # Build and clean commands
    BUILD_COMMAND="dn build --type vp"
    CLEAN_COMMAND="dn build --type vpclean"

    # Klocwork server and stream details
    URL="https://kw.group4.visteon.com:8443"
    STREAM="BMW_DI_MIC-NEXT_VIP_MY26_EP29130/BMW_DI_MIC-NEXT_VIP_MY26_EP29130_INT"
    
    # project directory
    PROJ_DIR="$KW_SCRIPT_DIR/../../../../../../../../../../"
    
    # path for analysis
    GDT_PATH="$PROJ_DIR/git/gui/2DFrameworks/gdt"
    GDT_AUTOGEN_PATH="$PROJ_DIR/programs/bmw/my2026/ic-mic/hmi/earlyhmi/EarlyHMI_BMW_Windows_GDTBased/Source"
    ICEAPPLE_PATH="$PROJ_DIR/git/gui/2DFrameworks/iceapple/ui.core.iceapple"
  
else
    log "Invalid program_code. Please enter valid program_code: bmic, r2g, acza, p3f2, l1a or n597"
    exit 1
fi

# Display all directories
log "Project directory - $PROJ_DIR"
log "Klocwork directory - $KW_DIR"
log "Klocwork script directory - $KW_SCRIPT_DIR"
log "Klockwork utility output2csv directory - $KW_OUTPUTTOCSV"

log "Cleaning the build"
$CLEAN_COMMAND

log "KlocWork Analysis Started"

# Check for the Klocwork project setup file
if [ ! -e "$KW_SCRIPT_DIR/.kwps" ]; then
  
  log "Setting up Klocwork"
  log "Klocwork User Authentication"
  "$KW_DIR/bin/kwauth" --url "$URL"

  log "Klocwork Set up a local project and connect it to a server project"
  "$KW_DIR/bin/kwcheck" create --url "$URL/$STREAM"
fi

# Clean up previous kwinject output if it exists
log "Running Klocwork analysis"
if [ -e "./kwinject.out" ]; then
  rm -f "./kwinject.out"
fi

# KlocWork Build with injection
"$KW_DIR/bin/kwinject" $BUILD_COMMAND

# KlocWork Import build spec information
"$KW_DIR/bin/kwcheck" import kwinject.out

# KlocWork Analysis
"$KW_DIR/bin/kwcheck" run "$GDT_PATH" "$GDT_AUTOGEN_PATH" "$ICEAPPLE_PATH"

log "Generating Klocwork report"

# KlocWork Report generation
"$KW_DIR/bin/kwcheck" list -y -F xml --report kw_report_$1.xml "$GDT_PATH" "$GDT_AUTOGEN_PATH" "$ICEAPPLE_PATH"

# Generate CSV report if kwoutputtocsv exists
if [ -e "$KW_OUTPUTTOCSV/kwoutputtocsv" ]; then
  "$KW_OUTPUTTOCSV/kwoutputtocsv" kw_report_$1.xml kw_report_$1.csv
else
  log "Missing: KWOutputtoCSV Utility not found"
fi

log "KlocWork Analysis Completed"

exit 0 # Success




