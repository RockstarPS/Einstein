#!/bin/bash

# Base address and step size
BASE_ADDR=0xA0008000
STEP=0x10

# Default to 'release' if not specified
BUILD_TYPE=${1:-release} 
# KPI Enum List


enum_list="
	"KPI_ID_FIRST_INV"
	"KPI_ID_SBL_S1_START"
	"KPI_ID_SBL_S1_END"
	"KPI_ID_SBL_S2_MAIN_START"
	"KPI_ID_SBL_S2_MAIN_SCISERVER_START"
	"KPI_ID_SBL_S2_MAIN_ETH_APP_START"
	"KPI_ID_SBL_S2_MAIN_END"
	"KPI_ID_SBL_S2_HSM_CORE_START"
	"KPI_ID_SBL_S2_MCU_CORE_START"
	"KPI_ID_SBL_S2_GIP_CORE_START"
	"KPI_ID_VIP_MAIN"
	"KPI_ID_VIP_INIT_ZERO"
	"KPI_ID_VIP_INIT_ONE"
	"KPI_ID_VIP_INIT_TWO"
	"KPI_ID_VIP_RTE_START"
	"KPI_ID_VIP_NVM_READALL_FINISH"
	"KPI_ID_VIP_EARLY_HMI"
	"KPI_ID_VIP_ETH_PHY"
	"KPI_ID_VIP_ETH_COMM"
	"KPI_ID_GIP_KERNEL_START"
	"KPI_ID_GIP_KERNEL_END"
	"KPI_ID_GIP_FULL_HMI"
	"KPI_ID_LAST_INV"
"

# Read register function with error handling
read_register() {
    local addr=$1
    local line
    line=$(devmem2 "$addr" 2>/dev/null | grep "Read at address")
    local val
    val=$(echo "$line" | awk -F": " '{print $2}')

    if [[ "$val" =~ ^0x ]]; then
        echo $((16#${val:2}))
    else
        echo 0
    fi
}

# Read all KPI timestamps
declare -A KPI_VALUES
ADDR=$BASE_ADDR

for KPI in $enum_list; do
    VAL=$(read_register "$ADDR")
    KPI_VALUES[$KPI]=$VAL
    ADDR=$(printf "0x%X" $((ADDR + STEP)))
done

# ======================== Timestamp Table ========================
printf "\n"
printf "|==============================================================================|\n"
printf "|                             KPI Timestamp Table                               |\n"
printf "|==============================================================================|\n"
printf "|%-60s | %-15s|\n" "KPI Name" "Timestamp (ms)"
printf "|==============================================================================|\n"

for KPI in $enum_list; do
    if [[ "$KPI" != *"_INV" ]]; then
        printf "|%-60s | %15d|\n" "$KPI" "${KPI_VALUES[$KPI]}"
    fi
done

printf "|==============================================================================|\n"
# ======================== Time Difference Table ===========================
printf "|==============================================================================|\n"
printf "|                             KPI Key Points                                   |\n"
printf "|==============================================================================|\n"
printf "|%-60s | %15s|\n" "Measure" "Time (ms)"
printf "|==============================================================================|\n"

printf "|%-60s | %15d|\n" "Time taken for HSM Core to Start"  ${KPI_VALUES[KPI_ID_SBL_S2_HSM_CORE_START]}
printf "|%-60s | %15d|\n" "Time taken for MCU Core to Start"  ${KPI_VALUES[KPI_ID_SBL_S2_MCU_CORE_START]}
printf "|%-60s | %15d|\n" "Time taken for Linux Core to Start" ${KPI_VALUES[KPI_ID_SBL_S2_GIP_CORE_START]}
printf "|%-60s | %15d|\n" "Time taken for Kernel Initialisation" $(( KPI_VALUES[KPI_ID_GIP_KERNEL_END] - KPI_VALUES[KPI_ID_GIP_KERNEL_START] ))
printf "|==============================================================================|\n"
printf "\n"
