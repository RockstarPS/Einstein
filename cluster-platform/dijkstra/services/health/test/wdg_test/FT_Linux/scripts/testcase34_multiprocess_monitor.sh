#!/bin/sh

# Configuration
SERVICE_TO_KILL="test_18_5.service"
SERVICE_TO_MONITOR="wdg_proxy_test_18.service"
LOG_FILTER="wdg_proxy"

echo "------------------------------------------------------------------"
echo "-----   Testcase 34 - Multiprocess Monitoring  -------------------"
echo "  Configuration:  "
echo "        (1). Restart action - always "
echo "        (2). Watchdog - disabled"
echo "        (3). Restart Limit - 3"
echo "  Actual behaviour -  Process shall be restarted"
echo "  Error Notification Fatal (Yes/No) : Yes        "
echo "  Process restart (Yes/No) : Yes                  "
echo "------------------------------------------------------------------"

# 1. Record the start time of THIS test cycle
TEST_START_TIME=$(date "+%Y-%m-%d %H:%M:%S")

# 2. Start the services
SERVICES="test_18_1.service test_18_2.service test_18_3.service test_18_4.service test_18_5.service wdg_proxy_test_18.service"
for SERVICE in $SERVICES; do
    # 2.1. Start the service
    echo "[>] Starting $SERVICE..."
    systemctl start "$SERVICE"

    # 2.2. Verify start
    if ! systemctl is-active --quiet "$SERVICE"; then
        echo "Error: Failed to start $SERVICE."
        continue
    fi
    echo "[+] $SERVICE started successfully."
    sleep 2
done

# 3. kill signal 35
echo "-----------------------------------------------"
echo "--- Kill signal -------------------------------"
echo "-----------------------------------------------"
PID_01=$(systemctl show --property MainPID --value "$SERVICE_TO_KILL")

if [ "$PID_01" -ne 0 ]; then
    echo "[!] Sending Signal 35 (SIGRTMIN+1) ONLY to $SERVICE_TO_KILL (PID: $PID_01)..."
    kill -35 "$PID_01"
else
    echo "Error: Could not find PID for $SERVICE_TO_KILL."
fi
sleep 2

# 4. kill signal 35
PID_01=$(systemctl show --property MainPID --value "$SERVICE_TO_KILL")

if [ "$PID_01" -ne 0 ]; then
    echo "[!] Sending Signal 35 (SIGRTMIN+1) ONLY to $SERVICE_TO_KILL (PID: $PID_01)..."
    kill -35 "$PID_01"
else
    echo "Error: Could not find PID for $SERVICE_TO_KILL."
fi
sleep 2

# 5. kill signal 35
PID_01=$(systemctl show --property MainPID --value "$SERVICE_TO_KILL")

if [ "$PID_01" -ne 0 ]; then
    echo "[!] Sending Signal 35 (SIGRTMIN+1) ONLY to $SERVICE_TO_KILL (PID: $PID_01)..."
    kill -35 "$PID_01"
else
    echo "Error: Could not find PID for $SERVICE_TO_KILL."
fi
sleep 2

# 6. Review Results
echo "-----------------------------------------------"
echo "--- Recent Journal Entries ---"
echo "-----------------------------------------------"
journalctl -u "$SERVICE_TO_KILL" --since "$TEST_START_TIME" --no-pager

# 7. Monitor DLT with a 5-second timeout
# This will stop the script automatically after 5 seconds
TIMEOUT_SEC=5
echo "-----------------------------------------------"
echo "--- Capturing DLT Logs for $TIMEOUT_SEC seconds... ---"
echo "-----------------------------------------------"
timeout "$TIMEOUT_SEC"s /bin/dlt-receive -a localhost | grep "$LOG_FILTER"

# 8. Stop the services
SERVICES="test_18_1.service test_18_2.service test_18_3.service test_18_4.service test_18_5.service wdg_proxy_test_18.service"
for SERVICE in $SERVICES; do
    echo "-----------------------------------------------"
    echo "[*] Checking Status: $SERVICE"

    # 6.1. Stop if already running for a fresh start
    if systemctl is-active --quiet "$SERVICE"; then
        echo "[!] $SERVICE is running. Stopping for clean test..."
        systemctl stop "$SERVICE"
        sleep 1
    fi
done

echo "--- Test Complete. DLT logging stopped. ---"
echo "******************************************************"
