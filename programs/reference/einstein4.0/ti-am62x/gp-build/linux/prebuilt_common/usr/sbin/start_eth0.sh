#!/bin/sh

echo "=============================="
echo " eth0 bring-up (DoIP network)"
echo "=============================="

# IP must match [NetworkInfo] in /etc/doip.ini (192.168.11.2:13400)
ETH_IF="eth0"
ETH_IP="192.168.11.2"
ETH_PREFIX="24"

# Wait for the interface to appear (CPSW probe can be slow)
for i in $(seq 1 10); do
    [ -d "/sys/class/net/$ETH_IF" ] && break
    sleep 1
done

if [ ! -d "/sys/class/net/$ETH_IF" ]; then
    echo "ERROR: $ETH_IF not found"
    exit 1
fi

ip addr flush dev "$ETH_IF" 2>/dev/null
ip addr add "$ETH_IP/$ETH_PREFIX" dev "$ETH_IF"
ip link set "$ETH_IF" up

STATUS=$(cat /sys/class/net/$ETH_IF/carrier 2>/dev/null)
[ "$STATUS" = "1" ] && LINK="UP" || LINK="DOWN (no cable?)"

echo "----------------------------------"
echo "Interface     : $ETH_IF"
echo "IP address    : $ETH_IP/$ETH_PREFIX"
echo "Carrier       : $LINK"
echo "----------------------------------"
exit 0
