#!/bin/sh

# Configuration
SERVICE_TO_KILL="test_18_2.service"
SERVICE_TO_MONITOR="wdg_proxy_test_18.service"
LOG_FILTER="wdg_proxy"

echo "------------------------------------------------------------------"
echo "-----   Testcase 30 - Multiprocess Monitoring  -------------------"
echo "  Configuration:"
echo "        (1) Restart action  : No"
echo "        (2) Watchdog        : Enabled"
echo "  Expected Behaviour:"
echo "        - Process shall NOT be restarted"
echo "        - Fatal error notification expected : Yes"
echo "        - Process restart expected          : No"
echo "------------------------------------------------------------------"

# 1. Record the start time of this test cycle
TEST_START_TIME=$(date "+%Y-%m-%d %H:%M:%S")

# 2. Start the services
SERVICES="test_18_1.service test_18_2.service test_18_3.service test_18_4.service test_18_5.service wdg_proxy_test_18.service"

for SERVICE in $SERVICES; do
    echo "[>] Starting $SERVICE..."
    systemctl start "$SERVICE"

    # Verify service start
    if ! systemctl is-active --quiet "$SERVICE"; then
        echo "[ERROR] Failed to start $SERVICE."
        continue
    fi

    echo "[+] $SERVICE started successfully."
    sleep 2
done

# 3. Send Signal 35
echo "-----------------------------------------------"
echo " Sending Kill Signal "
echo "-----------------------------------------------"

PID_01=$(systemctl show --property MainPID --value "$SERVICE_TO_KILL")

if [ "$PID_01" -ne 0 ]; then
    echo "[!] Sending Signal 35 (SIGRTMIN+1) to $SERVICE_TO_KILL (PID: $PID_01)..."
    kill -35 "$PID_01"
else
    echo "[ERROR] Could not find PID for $SERVICE_TO_KILL."
fi

sleep 2

# 4. Review results
echo "-----------------------------------------------"
echo " Recent Journal Entries "
echo "-----------------------------------------------"
journalctl -u "$SERVICE_TO_KILL" --since "$TEST_START_TIME" --no-pager

# 5. Capture DLT logs for a limited duration
TIMEOUT_SEC=5
echo "-----------------------------------------------"
echo " Capturing DLT logs for $TIMEOUT_SEC seconds "
echo "-----------------------------------------------"

timeout "$TIMEOUT_SEC"s /bin/dlt-receive -a localhost | grep "$LOG_FILTER"

# 6. Stop all services
for SERVICE in $SERVICES; do
    echo "-----------------------------------------------"
    echo "[*] Checking status: $SERVICE"

    if systemctl is-active --quiet "$SERVICE"; then
        echo "[!] $SERVICE is running. Stopping for cleanup..."
        systemctl stop "$SERVICE"
        sleep 1
    fi
done

echo "--------------------------------------------------"
echo "--- Test complete. DLT logging stopped. ----------"
echo "**************************************************"