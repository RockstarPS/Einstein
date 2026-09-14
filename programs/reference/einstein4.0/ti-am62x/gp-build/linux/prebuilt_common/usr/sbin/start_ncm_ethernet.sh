#!/bin/sh

echo "=============================="
echo "NCM Gadget Setup "
echo "=============================="

modprobe configfs 2>/dev/null
modprobe libcomposite 2>/dev/null

mount | grep -q /sys/kernel/config || \
    mount -t configfs none /sys/kernel/config

G=/sys/kernel/config/usb_gadget/g1

# Cleanup old gadget
if [ -d "$G" ]; then
    echo "" > $G/UDC 2>/dev/null
    rm -rf $G
fi

mkdir -p $G
cd $G

# Device info
echo 0x1d6b > idVendor
echo 0x0104 > idProduct

mkdir -p strings/0x409
echo "am62p" > strings/0x409/serialnumber
echo "TI" > strings/0x409/manufacturer
echo "NCM Gadget" > strings/0x409/product

# Config
mkdir -p configs/c.1
mkdir -p configs/c.1/strings/0x409
echo "NCM Config" > configs/c.1/strings/0x409/configuration

# NCM function
mkdir -p functions/ncm.usb0
ln -s functions/ncm.usb0 configs/c.1/

# -------------------------------
# Bind ONLY to USB0 (wait + retry)
# -------------------------------
UDC_NAME="31000000.usb"

echo "Waiting for UDC: $UDC_NAME"

for i in $(seq 1 10); do
    [ -e "/sys/class/udc/$UDC_NAME" ] && break
    sleep 1
done

if [ ! -e "/sys/class/udc/$UDC_NAME" ]; then
    echo "ERROR: UDC not found"
    ACTIVE_UDC="none"
    ACTIVE_IF="none"
    LINK="NO DEVICE"
else
    echo "Binding to UDC: $UDC_NAME"

    SUCCESS=0
    for i in $(seq 1 5); do
        echo "" > UDC 2>/dev/null
        sleep 1

        if echo $UDC_NAME > UDC 2>/dev/null; then
            SUCCESS=1
            break
        fi

        echo "Retry $i: UDC not ready"
        sleep 2
    done

    if [ "$SUCCESS" -ne 1 ]; then
        echo "ERROR: Failed to bind UDC after retries"
    fi

    sleep 2

    # Detect USB interface
    USB_IF=$(ls /sys/class/net | grep -E "usb|enx" | head -n1)

    if [ -n "$USB_IF" ]; then
        ip link set $USB_IF up
        sleep 1

        TARGET_IP="192.168.5.55"

        ip addr flush dev $USB_IF
        ip addr add $TARGET_IP/16 dev $USB_IF
        ip link set $USB_IF up

        # sysctl tuning
        if [ -d /proc/sys/net/ipv4/conf/usb0 ]; then
            sysctl -w net.ipv4.conf.usb0.arp_announce=1
        fi

        sysctl -w net.ipv4.icmp_echo_ignore_all=0

        STATUS=$(cat /sys/class/net/$USB_IF/carrier 2>/dev/null)
        [ "$STATUS" = "1" ] && LINK="UP" || LINK="DOWN"

        ACTIVE_UDC=$UDC_NAME
        ACTIVE_IF=$USB_IF
    else
        ACTIVE_UDC="none"
        ACTIVE_IF="none"
        LINK="NO DEVICE"
    fi
fi

# -------------------------------
# Final output
# -------------------------------
echo "----------------------------------"
echo "Active UDC        : $ACTIVE_UDC"
echo "USB Interface     : $ACTIVE_IF"
echo "Link Status       : $LINK"
echo "----------------------------------"