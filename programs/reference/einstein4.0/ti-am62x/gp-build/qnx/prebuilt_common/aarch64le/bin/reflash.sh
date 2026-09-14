#! /bin/sh

# User is requested to enter the option required, based on that action will be performed.
#   $1 - User Input

# ERROR CODES
# 0 - Success
# Other possible error codes are described in the function "print_err_msg"

###################################################################################################
#  FUNCTIONS
###################################################################################################

function flash_nor {
    echo "Waiting for NOR Flash..."
    waitfor /dev/fs0

    echo "Erasing NOR Flash..."
    flashctl -p /dev/fs0 -ev
    if [ $? -ne 0 ]; then
        echo "Failed"
        ksh -l
        exit 1
    fi
    sync
    echo "Done"

    echo "Flashing OSPI Stage 1 Bootloader..."
    toybox dd if=$1  of=/dev/fs0 bs=512 seek=0
    if [ $? -ne 0 ]; then
        echo "Failed"
        ksh -l
        exit 2
    fi
    sync
    echo "Done"

    echo "Flashing OSPI Stage 2 Bootloader..."
    toybox dd if=$2 of=/dev/fs0 bs=512 seek=1024
    if [ $? -ne 0 ]; then
        echo "Failed"
        ksh -l
        exit 2
    fi
    toybox dd if=$2 of=/dev/fs0 bs=512 seek=3072
    if [ $? -ne 0 ]; then
        echo "Failed"
        ksh -l
        exit 2
    fi
    toybox dd if=$2 of=/dev/fs0 bs=512 seek=5120
    if [ $? -ne 0 ]; then
        echo "Failed"

        ksh -l
        exit 2
    fi
    toybox dd if=$2 of=/dev/fs0 bs=512 seek=7168
    if [ $? -ne 0 ]; then
        echo "Failed"

        ksh -l
        exit 2
    fi
    sync
    echo "Done"

    echo "Flashing HSM Binary..."
    toybox dd if=$3 of=/dev/fs0 bs=512 seek=9216
    if [ $? -ne 0 ]; then
        echo "Failed"
        ksh -l
        exit 2
    fi
    toybox dd if=$3 of=/dev/fs0 bs=512 seek=9472
    if [ $? -ne 0 ]; then
        echo "Failed"
        ksh -l
        exit 2
    fi
    toybox dd if=$3 of=/dev/fs0 bs=512 seek=9728
    if [ $? -ne 0 ]; then
        echo "Failed"
        ksh -l
        exit 2
    fi
    toybox dd if=$3 of=/dev/fs0 bs=512 seek=9984
    if [ $? -ne 0 ]; then
        echo "Failed"
        ksh -l
        exit 2
    fi

    echo "Flashing VIP bootloader... not yet supported"
#    toybox dd if=$4 of=/dev/fs0 bs=512 seek=10240
#    if [ $? -ne 0 ]; then
#        echo "Failed"
#        ksh -l
#        exit 2
#    fi
#    toybox dd if=$4 of=/dev/fs0 bs=512 seek=10752
#    if [ $? -ne 0 ]; then
#       echo "Failed"
#       ksh -l
#        exit 2
#    fi
    echo "Flashing VIP application..."
    toybox dd if=$4 of=/dev/fs0 bs=512 seek=11264
    if [ $? -ne 0 ]; then
        echo "Failed"
        ksh -l
        exit 2
    fi
    toybox dd if=$4 of=/dev/fs0 bs=512 seek=19456
    if [ $? -ne 0 ]; then
        echo "Failed"
        ksh -l
        exit 2
    fi
    echo "Flashing Metadata"
    toybox dd if=$5 of=/dev/fs0 bs=512 seek=32256
    if [ $? -ne 0 ]; then
        echo "Failed"
        ksh -l
        exit 2
    fi

    sync
    echo "Done"
}

function flash_primary_ifs {
    echo "Waiting for EMMC Boot Partition"
    waitfor /dev/emmc1

    echo "Flashing Primary IFS boot partition 1"
    toybox dd if=$1 of=/dev/emmc1 bs=512 seek=0
    if [ $? -ne 0 ]; then
        echo "Failed"
        ksh -l
        exit 2
    fi
    echo "Flashing Primary IFS boot partition 2"
    toybox dd if=$1 of=/dev/emmc2 bs=512 seek=0
    if [ $? -ne 0 ]; then
        echo "Failed"
        ksh -l
        exit 2
    fi
    echo "Done"
}

function flash_Recovery_ifs {
    echo "Waiting for EMMC recovery Partition"
    waitfor /dev/emmc0
    echo "Flashing Recovery IFS boot partition 1"
    toybox dd if=$1 of=/dev/emmc0 bs=512 seek=2048
    if [ $? -ne 0 ]; then
        echo "Failed"
        ksh -l
        exit 2
    fi
    echo "Flashing Recovery IFS boot partition 2"
    toybox dd if=$1 of=/dev/emmc0 bs=512 seek=67584
    if [ $? -ne 0 ]; then
        echo "Failed"
        ksh -l
        exit 2
    fi
    echo "Done"
}

function partition_emmc {
    echo "Waiting for eMMC Flash..."
    waitfor /dev/emmc0
    echo "Done"

    echo "Enumerating eMMC Partition Table..."
    mount -e /dev/emmc0
    echo "Done"

    echo "Delete all partitions"
    pted /dev/emmc0 initialize -g
    mount -e /dev/emmc0
    echo "Done"

# Size in PTED Blocks is calculated as (Actual Size * 2048)

# | Partition            | Actual Size(MiB) | Size in Pted Blocks |
# |----------------------|------------------|---------------------|
# | Primary IFS A        | 32               | 65536               |
# | Primary IFS B        | 32               | 65536               |
# | Recovery IFS A       | 32               | 65536               |
# | Recovery IFS B       | 32               | 65536               |
# | EFS A                | 512              | 1048576             |
# | EFS B                | 512              | 1048576             |
# | Recovery EFS A       | 512              | 1048576             |
# | Recovery EFS B       | 512              | 1048576             |
# | System A             | 128              | 262144              |
# | System B             | 128              | 262144              |
# | App A                | 256              | 524288              |
# | App B                | 256              | 524288              |
# | Asset A              | 1024             | 2097152             |
# | Asset B              | 1024             | 2097152             |
# | VIP App A            | 4                | 8192                |
# | VIP App B            | 4                | 8192                |
# | Data                 | 128              | 262144              |
# | Persist              | 32               | 65536               |
# | OTA Cache            | 2048             | 4194304             |
# | Reserved             | 982.9839         | 2013151             |


    echo "Create partitions for file systems"
    # The first 512 bytes is reserved by default for native MBR (aligned to 1MB).
    # pted /dev/emmc0 add -T 8DA63339-0007-60C0-C436-083AC8230908 -n raw -s 2011103
    # pted /dev/emmc1 add -T 8DA63339-0007-60C0-C436-083AC8230908 -n ifs_primary_a -s 65536
    # pted /dev/emmc2 add -T 8DA63339-0007-60C0-C436-083AC8230908 -n ifs_primary_b -s 65536
    pted /dev/emmc0 add -T 8DA63339-0007-60C0-C436-083AC8230908 -n ifs_recovery_a -s 65536
    pted /dev/emmc0 add -T 8DA63339-0007-60C0-C436-083AC8230908 -n ifs_recovery_b -s 65536
    pted /dev/emmc0 add -t qnx6 -n efs_a -s 1048576
    pted /dev/emmc0 add -t qnx6 -n efs_b -s 1048576
    pted /dev/emmc0 add -t qnx6 -n recovery_efs_a -s 1048576
    pted /dev/emmc0 add -t qnx6 -n recovery_efs_b -s 1048576
    pted /dev/emmc0 add -t qnx6 -n system_a -s 262144
    pted /dev/emmc0 add -t qnx6 -n system_b -s 262144
    pted /dev/emmc0 add -t qnx6 -n app_a -s 524288
    pted /dev/emmc0 add -t qnx6 -n app_b -s 524288
    pted /dev/emmc0 add -t qnx6 -n asset_a -s 2097152
    pted /dev/emmc0 add -t qnx6 -n asset_b -s 2097152
    pted /dev/emmc0 add -T 8DA63339-0007-60C0-C436-083AC8230908 -n vip_a_app -s 8192
    pted /dev/emmc0 add -T 8DA63339-0007-60C0-C436-083AC8230908 -n vip_b_app -s 8192
    pted /dev/emmc0 add -t qnx6 -n data -s 262144
    pted /dev/emmc0 add -t qnx6 -n persist -s 65536
    pted /dev/emmc0 add -t qnx6 -n OTA_Cache -s 4194304
    mount -e /dev/emmc0

    echo "Formatting eMMC data partition as Power-Safe filesystem"
    mkqnx6fs -q /dev/emmc0.qnx6.data
    if [ $? != 0 ]; then
        echo "Failed";
        return 2;
    else
        echo "Done"
    fi

    echo "Consistency check on eMMC data partition Power-Safe filesystem"
    chkqnx6fs -fv /dev/emmc0.qnx6.data
    if [ $? != 0 ]; then
        echo "Failed";
        return 2;
    else
        echo "Done"
    fi

    echo "Mounting Data Partition"
    mount -t qnx6 /dev/emmc0.qnx6.data /data
    if [ $? != 0 ]; then
        echo "Failed";
        return 2;
    else
        echo "Done"
    fi

    sync

    echo "Formatting eMMC persist partition as Power-Safe filesystem"
    mkqnx6fs -q /dev/emmc0.qnx6.persist
    if [ $? != 0 ]; then
        echo "Failed";
        return 2;
    else
        echo "Done"
    fi

    echo "Consistency check on eMMC persist partition Power-Safe filesystem"
    chkqnx6fs -fv /dev/emmc0.qnx6.persist
    if [ $? != 0 ]; then
        echo "Failed";
        return 2;
    else
        echo "Done"
    fi

    echo "Mounting Persist Partition"
    mount -t qnx6 /dev/emmc0.qnx6.persist /persist
    if [ $? != 0 ]; then
        echo "Failed";
        return 2;
    else
        echo "Done"
    fi

    sync

}

function partition_emmc_qtd {
    echo "Waiting for eMMC Flash..."
    waitfor /dev/emmc0
    echo "Done"

    echo "Enumerating eMMC Partition Table..."
    mount -e /dev/emmc0
    echo "Done"

    echo "Delete all partitions"
    pted /dev/emmc0 initialize -g
    mount -e /dev/emmc0
    echo "Done"

# Size in PTED Blocks is calculated as (Actual Size * 2048)

# | Partition            | Actual Size(MiB) | Size in Pted Blocks |
# |----------------------|------------------|---------------------|
# | Primary IFS A        | 32               | 65536               |
# | Primary IFS B        | 32               | 65536               |
# | Recovery IFS A       | 32               | 65536               |
# | Recovery IFS B       | 32               | 65536               |
# | EFS A                | 512              | 1048576             |
# | EFS B                | 512              | 1048576             |
# | Recovery EFS A       | 512              | 1048576             |
# | Recovery EFS B       | 512              | 1048576             |
# | System A             | 128              | 262144              |
# | System B             | 128              | 262144              |
# | App A                | 256              | 524288              |
# | App B                | 256              | 524288              |
# | Asset A              | 1024             | 2097152             |
# | Asset B              | 1024             | 2097152             |
# | VIP App A            | 4                | 8192                |
# | VIP App B            | 4                | 8192                |
# | Data                 | 128              | 262144              |
# | Persist              | 32               | 65536               |
# | OTA Cache            | 2048             | 4194304             |
# | Reserved             | 982.9839         | 2013151             |


    echo "Create partitions for file systems"
    # The first 512 bytes is reserved by default for native MBR (aligned to 1MB).
    # pted /dev/emmc0 add -T 8DA63339-0007-60C0-C436-083AC8230908 -n raw -s 2011103
    # pted /dev/emmc1 add -T 8DA63339-0007-60C0-C436-083AC8230908 -n ifs_primary_a -s 65536
    # pted /dev/emmc2 add -T 8DA63339-0007-60C0-C436-083AC8230908 -n ifs_primary_b -s 65536
    pted /dev/emmc0 add -T 8DA63339-0007-60C0-C436-083AC8230908 -n ifs_recovery_a -s 65536
    pted /dev/emmc0 add -T 8DA63339-0007-60C0-C436-083AC8230908 -n ifs_recovery_b -s 65536
    pted /dev/emmc0 add -t qnx6 -n efs_a -s 1048576
    pted /dev/emmc0 add -t qnx6 -n efs_b -s 1048576
    pted /dev/emmc0 add -t qnx6 -n recovery_efs_a -s 1048576
    pted /dev/emmc0 add -t qnx6 -n recovery_efs_b -s 1048576
    pted /dev/emmc0 add -t qnx6 -n system_a -s 262144
    pted /dev/emmc0 add -t qnx6 -n system_b -s 262144
    pted /dev/emmc0 add -t qnx6 -n app_a -s 524288
    pted /dev/emmc0 add -t qnx6 -n app_b -s 524288
    pted /dev/emmc0 add -t qnx6 -n asset_a -s 2097152
    pted /dev/emmc0 add -t qnx6 -n asset_b -s 2097152
    pted /dev/emmc0 add -T 8DA63339-0007-60C0-C436-083AC8230908 -n vip_a_app -s 8192
    pted /dev/emmc0 add -T 8DA63339-0007-60C0-C436-083AC8230908 -n vip_b_app -s 8192
    pted /dev/emmc0 add -t qnx6 -n data -s 262144
    pted /dev/emmc0 add -t qnx6 -n persist -s 65536
    pted /dev/emmc0 add -t qnx6 -n OTA_Cache -s 4194304
    mount -e /dev/emmc0

    echo "Formatting eMMC data partition as Power-Safe filesystem"
    mkqnx6fs -q /dev/emmc0.qnx6.data
    if [ $? != 0 ]; then
        echo "Failed";
        return 2;
    else
        echo "Done"
    fi

    echo "Consistency check on eMMC data partition Power-Safe filesystem"
    chkqnx6fs -fv /dev/emmc0.qnx6.data
    if [ $? != 0 ]; then
        echo "Failed";
        return 2;
    else
        echo "Done"
    fi

    echo "Mounting Data Partition"
    mount -t qnx6 /dev/emmc0.qnx6.data /data
    if [ $? != 0 ]; then
        echo "Failed";
        return 2;
    else
        echo "Done"
    fi

    sync

    echo "Formatting eMMC persist partition as Power-Safe filesystem"
    mkqnx6fs -q /dev/emmc0.qnx6.persist
    if [ $? != 0 ]; then
        echo "Failed";
        return 2;
    else
        echo "Done"
    fi

    echo "Consistency check on eMMC persist partition Power-Safe filesystem"
    chkqnx6fs -fv /dev/emmc0.qnx6.persist
    if [ $? != 0 ]; then
        echo "Failed";
        return 2;
    else
        echo "Done"
    fi

    echo "Mounting Persist Partition"
    mount -t qnx6 /dev/emmc0.qnx6.persist /persist
    if [ $? != 0 ]; then
        echo "Failed";
        return 2;
    else
        echo "Done"
    fi

    sync

}

function validate_tar {
    toybox tar xzOf $1 2>&1 > /dev/null
    if [ $? -ne 0 ]; then
        echo "File $1 is an invalid tar file. Can't proceed flashing. Flashing Aborted..."
        print_err_msg 3;
        exit 3
    else
        echo "File $file is a valid tar file"
    fi
}

function flash_system_partition {
    echo "Programming eMMC system partition"
    if   [[ $SECURITY_ENABLED -eq 1 ]];then
        waitfor /dev/emmc0.qtd.system_a
        toybox tar xzOf $1 | toybox dd of=/dev/emmc0.qtd.system_a
        waitfor /dev/emmc0.qtd.system_b
        toybox tar xzOf $1 | toybox dd of=/dev/emmc0.qtd.system_b
    else
        waitfor /dev/emmc0.qnx6.system_a
        toybox tar xzOf $1 | toybox dd of=/dev/emmc0.qnx6.system_a
        waitfor /dev/emmc0.qnx6.system_b
        toybox tar xzOf $1 | toybox dd of=/dev/emmc0.qnx6.system_b
    fi
    echo "Done"
}

function flash_app_partition {
    echo "Programming eMMC app partition"
    if   [[ $SECURITY_ENABLED -eq 1 ]];then
        waitfor /dev/emmc0.qtd.app_a
        toybox tar xzOf $1 | toybox dd of=/dev/emmc0.qtd.app_a
        waitfor /dev/emmc0.qtd.app_b
        toybox tar xzOf $1 | toybox dd of=/dev/emmc0.qtd.app_b
    else
        waitfor /dev/emmc0.qnx6.app_a
        toybox tar xzOf $1 | toybox dd of=/dev/emmc0.qnx6.app_a
        waitfor /dev/emmc0.qnx6.app_b
        toybox tar xzOf $1 | toybox dd of=/dev/emmc0.qnx6.app_b
    fi
    echo "Done"
}

function flash_asset_partition {
    echo "Programming eMMC asset partition"
    if   [[ $SECURITY_ENABLED -eq 1 ]];then
        waitfor /dev/emmc0.qtd.asset_a
        toybox tar xzOf $1 | toybox dd of=/dev/emmc0.qtd.asset_a
        waitfor /dev/emmc0.qtd.asset_b
        toybox tar xzOf $1 | toybox dd of=/dev/emmc0.qtd.asset_b
    else
        waitfor /dev/emmc0.qnx6.asset_a
        toybox tar xzOf $1 | toybox dd of=/dev/emmc0.qnx6.asset_a
        waitfor /dev/emmc0.qnx6.asset_b
        toybox tar xzOf $1 | toybox dd of=/dev/emmc0.qnx6.asset_b
    fi
    echo "Done"
}

function pre_check {
    # cp, dd, mkdir, rm and tar are provided by toybox
    set -A commands "toybox" "devb-umass" "echo" "exit" "flashctl" "io-usb-otg" "ksh" "mkdosfs" "mkqnx6fs" "mount" "pted" "shutdown" "sync" "tar" "waitfor"
    # set -A commands "cp" "devb-umass" "dd" "echo" "exit" "flashctl" "io-usb-otg" "ksh" "mkdir" "mkdosfs" "mkqnx6fs" "mount" "pted" "rm" "shutdown" "sync" "tar" "waitfor"
    # iterate over the list of commands and check each one
    for cmd in "${commands[@]}"; do
        if command -v "$cmd"; then
            echo "command $cmd is available."
        else
            echo "command $cmd is not available."
            print_err_msg 1
        fi
    done
    return 0;
}

###########################################################################
## Start and USB Mass driver and mount the drive in /usb0
###########################################################################
function mount_usb_device {
    devb-umass blk cache=10m cam pnp &
    waitfor /dev/hd0 300
    ret=$?
    if [ $ret != 0 ];then
        print_err_msg 4
    fi
    mount -t dos /dev/hd0t12 ${USB_MOUNT_POINT}
    waitfor ${USB_MOUNT_POINT} 5

    FILE="${USB_MOUNT_POINT}/usb.txt"
    if [ -f "$FILE" ]; then
        echo "USB Mounted, Proceeding USB Stick Flashing..."
    else
        echo "usb.txt file missing"
        echo "Keep usb.txt & necessary files on the pendrive to start USB Stick Flashing!!!"
    fi
    return 0;
}

function flash_wrt_user_input {
    MOUNT_POINT="$1"
    while true; do
        echo "************************************************************************"
        echo "Choose one of the option below"
        echo "************************************************************************"
        echo ""
        opt=0
        echo "0 - Full Flash "
        echo "1 - NOR Flash "
        echo "2 - Primary IFS"
        echo "3 - Partition EMMC"
        echo "4 - EMMC System Partition"
        echo "5 - EMMC App Partition"
        echo "6 - EMMC Asset Partition"
        echo "7 - Exit"
        echo "Note: Default Option - 0"

        read opt?"Select Option : "

        if [ -z "$opt" ]; then
            echo "Choosing default option: 0 - Full Flash"
            break
        fi

        if [[ "$opt" == "!" ]] || [[ "$opt" == "@" ]] || [[ "$opt" == "#" ]] || [[ "$opt" == "$" ]] || [[ "$opt" == "%" ]] || [[ "$opt" == "^" ]] || [[ "$opt" == "&" ]] || [[ "$opt" == "*" ]] || [[ "$opt" == "(" ]] || [[ "$opt" == ")" ]]; then
            echo "Developer only access - Root login granted"
            # Handle the case where the user enters special characters
            exit 1
            # Check if the user option is within the specified range
        elif [[ $opt -ge 0 && $opt -le 7 ]]; then
            echo "User option: $opt"
            break
        else
            echo "Invalid Option. Enter valid option [0-7]."
        fi
    done

    if [[ opt -eq 0 ]];then

        set -A files "$FILE_NOR_STAGE1_BINARY" "$FILE_NOR_STAGE2_BINARY" "$FILE_NOR_HSM_BINARY" "$FILE_NOR_IPC_BINARY" "$FILE_NOR_METADATA" "$FILE_PRIMARY_IFS" "$FILE_SYSTEM_PARTITION" "$FILE_APP_PARTITION" "$FILE_ASSET_PARTITION"

        for file in "${files[@]}"; do
            if [ -f "${MOUNT_POINT}/$file" ]; then
                echo "File $file is available."
            else
                echo "File $file is not available."
                print_err_msg 3;
            fi
        done

        set -A tarfiles "$FILE_SYSTEM_PARTITION" "$FILE_APP_PARTITION" "$FILE_ASSET_PARTITION"

        echo "Validating tar files before starting the flashing process"
        for file in "${tarfiles[@]}"; do
            validate_tar "${MOUNT_POINT}/$file"
        done

        echo "Performing full flash"

        flash_nor "${MOUNT_POINT}/$FILE_NOR_STAGE1_BINARY" "${MOUNT_POINT}/$FILE_NOR_STAGE2_BINARY" "${MOUNT_POINT}/$FILE_NOR_HSM_BINARY" "${MOUNT_POINT}/$FILE_NOR_IPC_BINARY" "${MOUNT_POINT}/$FILE_NOR_METADATA"

        flash_primary_ifs "${MOUNT_POINT}/$FILE_PRIMARY_IFS"

        flash_system_partition "${MOUNT_POINT}/$FILE_SYSTEM_PARTITION"

        flash_app_partition "${MOUNT_POINT}/$FILE_APP_PARTITION"

        flash_asset_partition "${MOUNT_POINT}/$FILE_ASSET_PARTITION"

    elif [[ opt -eq 1 ]];then

        set -A files "$FILE_NOR_STAGE1_BINARY" "$FILE_NOR_STAGE2_BINARY" "$FILE_NOR_HSM_BINARY" "$FILE_NOR_IPC_BINARY" "$FILE_NOR_METADATA"

        for file in "${files[@]}"; do
            if [ -f "${MOUNT_POINT}/$file" ]; then
                echo "File $file is available."
            else
                echo "File $file is not available."
                print_err_msg 3;
            fi
        done

        echo "Performing NOR flash"

        flash_nor "${MOUNT_POINT}/$FILE_NOR_STAGE1_BINARY" "${MOUNT_POINT}/$FILE_NOR_STAGE2_BINARY" "${MOUNT_POINT}/$FILE_NOR_HSM_BINARY" "${MOUNT_POINT}/$FILE_NOR_IPC_BINARY" "${MOUNT_POINT}/$FILE_NOR_METADATA"

    elif [[ opt -eq 2 ]];then

        if [ ! -f "${MOUNT_POINT}/$FILE_PRIMARY_IFS" ]; then
            echo "File $FILE_PRIMARY_IFS not available."
            print_err_msg 3;
        fi

        echo "Performing Primary IFS flash"

        flash_primary_ifs "${MOUNT_POINT}/$FILE_PRIMARY_IFS"

    elif [[ opt -eq 3 ]];then

        echo "Performing Partition EMMC"

        if   [[ $SECURITY_ENABLED -eq 1 ]];then
            partition_emmc_qtd
        else
            partition_emmc
        fi

    elif [[ opt -eq 4 ]];then

        if [ ! -f "${MOUNT_POINT}/$FILE_SYSTEM_PARTITION" ]; then
            echo "File $FILE_SYSTEM_PARTITION not available."
            print_err_msg 3;
        fi

        echo "Validating eMMC system tar file"
        validate_tar "${MOUNT_POINT}/$FILE_SYSTEM_PARTITION"
        echo "Done"

        echo "Performing EMMC System Partition flash"

        flash_system_partition "${MOUNT_POINT}/$FILE_SYSTEM_PARTITION"

    elif [[ opt -eq 5 ]];then

        if [ ! -f "${MOUNT_POINT}/$FILE_APP_PARTITION" ]; then
            echo "File $FILE_APP_PARTITION not available."
            print_err_msg 3;
        fi

        echo "Validating eMMC app tar file"
        validate_tar "${MOUNT_POINT}/$FILE_APP_PARTITION"
        echo "Done"

        echo "Performing EMMC App Partition flash"

        flash_app_partition "${MOUNT_POINT}/$FILE_APP_PARTITION"

    elif [[ opt -eq 6 ]];then

        if [ ! -f "${MOUNT_POINT}/$FILE_ASSET_PARTITION" ]; then
            echo "File $FILE_ASSET_PARTITION not available"
            print_err_msg 3;
        fi

        echo "Validating eMMC asset tar file"
        validate_tar "${MOUNT_POINT}/$FILE_ASSET_PARTITION"
        echo "Done"

        echo "Performing EMMC Asset Partition flash"

        flash_asset_partition "${MOUNT_POINT}/$FILE_ASSET_PARTITION"

    elif [[ opt -eq 7 ]];then

        sync
        toybox sleep 5
        echo "Set boot pins to NOR flash boot and reboot the system"

        #shutdown -vvv -c -b

        echo "Done"
    fi
    return 0;
}

function finalize {
    sync
    toybox sleep 5
    echo "Flashing Complete"
    echo "Set boot pins to NOR flash boot and reboot the system"
    # Uncomment below lines to update the Software Bootmode registers
    # io 32 0x43000030 # Read the Boot Mode Register
    # io 32 0x43000030 0x1b # Write Bootmode Register as NOR
    #shutdown -vvv -c -b
    echo "Done"
}

function print_err_msg {
    echo "***************************************************************"
    echo "case=$1"
    case $1 in
        1)
            echo "Install the required the packages to proceed further"
            ;;
        2)
            echo "Failed to usb mount point"
            ;;
        3)
            echo "Copy the required files to the USB Drive and proceed flashing"
            ;;
        4)
            echo "You failed to connect the USB Drive within 5 Minutes - Timed out!!!"
            ;;
        *)
            echo "Unknown error"
            ;;
    esac
    echo "***************************************************************"
    exit $1;
}

###############################################################
## MAIN
###############################################################
set -e

echo ""
echo "VARIANT is $HW_VAR"
echo "SECURE is $SECURE_FS"
echo ""

pre_check

FILE_NOR_STAGE1_BINARY=sbl_ospi_stage1.release.hs_fs.tiimage
FILE_NOR_STAGE2_BINARY=sbl_ospi_stage2.release.appimage.hs_fs
FILE_NOR_HSM_BINARY=hsm.appimage.hs_fs
FILE_NOR_IPC_BINARY=EINSTIEN4.0_VP.appimage.hs_fs
FILE_PRIMARY_IFS=ifs-primary-qnx.appimage.hs_fs
FILE_NOR_METADATA=metadata.bin

if [[ $SECURITY_ENABLED -eq 1 ]];then
    FILE_SYSTEM_PARTITION=qtd-qnx6fs-system-partition.tar.gz
    FILE_APP_PARTITION=qtd-qnx6fs-app-partition.tar.gz
    FILE_ASSET_PARTITION=qtd-qnx6fs-asset-partition.tar.gz
else
    FILE_SYSTEM_PARTITION=qnx6fs-system-partition.tar.gz
    FILE_APP_PARTITION=qnx6fs-app-partition.tar.gz
    FILE_ASSET_PARTITION=qnx6fs-asset-partition.tar.gz
fi

while true; do
    echo "************************************************************************"
    echo "Choose one of the options below"
    echo "************************************************************************"
    echo ""
    opt=0
    echo "0 - Prepacked Binaries Flashing - Build and Flash"
    echo "1 - USB Stick Flashing - Copy your images to pendrive and connect to HW within 5 Mins"
    echo "2 - DFU Flashing - Create QNX6/QTD partitions - Transfer files at U-boot"
    echo "3 - Exit"
    echo "Note: Default Option - 0"

    read opt?"Select Option : "

    if [ -z "$opt" ]; then
        echo "Choosing default option: 0 - Prepacked Binaries Flashing"
        break
    fi

    if [[ "$opt" == "!" ]] || [[ "$opt" == "@" ]] || [[ "$opt" == "#" ]] || [[ "$opt" == "$" ]] || [[ "$opt" == "%" ]] || [[ "$opt" == "^" ]] || [[ "$opt" == "&" ]] || [[ "$opt" == "*" ]] || [[ "$opt" == "(" ]] || [[ "$opt" == ")" ]]; then
        echo "Developer only access - Root login granted"
        # Handle the case where the user enters special characters
        exit 1
        # Check if the user option is within the specified range
    elif [[ $opt -ge 0 && $opt -le 3 ]]; then
        echo "User option: $opt"
        break
    else
        echo "Invalid Option. Enter valid option [0-3]."
    fi
done

if [[ opt -eq 0 ]];then
    echo ""
    echo "************************************************************************"
    echo "Prepacked Binaries Flashing - Just Build and Flash"
    echo "************************************************************************"
    echo "Stage1 Binary File         - "$FILE_NOR_STAGE1_BINARY
    echo "Stage2 Binary File         - "$FILE_NOR_STAGE2_BINARY
    echo "HSM Binary File            - "$FILE_NOR_HSM_BINARY
    echo "IPC Binary File            - "$FILE_NOR_IPC_BINARY
    echo "Metadata File              - "$FILE_NOR_METADATA
    echo "Primary IFS File           - "$FILE_PRIMARY_IFS
    echo "System Partition File      - "$FILE_SYSTEM_PARTITION
    echo "Application Partition File - "$FILE_APP_PARTITION
    echo "Asset Partition            - "$FILE_ASSET_PARTITION
    echo "************************************************************************"
    echo ""

    PREPACK_MOUNT_POINT="/etc/images"

    flash_wrt_user_input ${PREPACK_MOUNT_POINT}
    ret=$?
    if [ $ret != 0 ];then
        print_err_msg 4
    fi

elif [[ opt -eq 1 ]];then
    echo ""
    echo "************************************************************************"
    echo " USB STICK FLASHING - Connect USB Drive to target within 5 Minutes"
    echo "************************************************************************"
    echo "Copy the below files to the USB drive and connect it to the target"
    echo "************************************************************************"
    echo "Stage1 Binary File         - "$FILE_NOR_STAGE1_BINARY
    echo "Stage2 Binary File         - "$FILE_NOR_STAGE2_BINARY
    echo "HSM Binary File            - "$FILE_NOR_HSM_BINARY
    echo "IPC Binary File            - "$FILE_NOR_IPC_BINARY
    echo "Metadata File              - "$FILE_NOR_METADATA
    echo "Primary IFS File           - "$FILE_PRIMARY_IFS
    echo "System Partition File      - "$FILE_SYSTEM_PARTITION
    echo "Application Partition File - "$FILE_APP_PARTITION
    echo "Asset Partition            - "$FILE_ASSET_PARTITION
    echo "************************************************************************"
    echo ""
    echo "************************************************************************"
    echo " USB STICK FLASHING - Connect USB Drive to target within 5 Minutes"
    echo "************************************************************************"
    echo ""

    USB_MOUNT_POINT="/usb0"

    mount_usb_device
    ret=$?
    if [ $ret != 0 ];then
        print_err_msg 2
    fi

    flash_wrt_user_input ${USB_MOUNT_POINT}
    ret=$?
    if [ $ret != 0 ];then
        print_err_msg 4
    fi

elif [[ opt -eq 2 ]];then
    echo "Performing Partition EMMC"
    if   [[ $SECURITY_ENABLED -eq 1 ]];then
        partition_emmc_qtd
    else
        partition_emmc
    fi

elif [[ opt -eq 3 ]];then
    echo "Exiting..."
    exit
fi

finalize
