#!/bin/sh

# Configuration
SERVICE_TO_KILL="test_05.service"
SERVICE_TO_MONITOR="wdg_proxy_test_05.service"
LOG_FILTER="wdg"

echo "------------------------------------------------------------------"
echo "----- Test Case 10 - Restart type: always --------------------------"
echo "  Cause of termination:"
echo "        Watchdog timeout (process stops sending keep-alive ping)"
echo ""
echo "  Expected behavior:"
echo "        The process shall always be restarted after watchdog timeout."
echo ""
echo "  Error Notification Fatal (Yes/No): No"
echo "  Process Restart (Yes/No): Yes"
echo "  [*] Configuration:"
echo "        Restart=always"
echo "        WatchdogSec=1"
echo "------------------------------------------------------------------"

# 1. Record start time
TEST_START_TIME=$(date "+%Y-%m-%d %H:%M:%S")

# 2. Start services
for SERVICE in "$SERVICE_TO_KILL" "$SERVICE_TO_MONITOR"; do
    echo "[>] Starting $SERVICE..."
    systemctl start "$SERVICE"

    if ! systemctl is-active --quiet "$SERVICE"; then
        echo "Error: Failed to start $SERVICE."
        continue
    fi

    echo "[+] $SERVICE started successfully."
    sleep 2
done

# 3. Trigger watchdog timeout (first cycle)
echo "......................................................."
echo "       Test: trigger watchdog timeout (via signal 35)"
echo "......................................................."
PID_01=$(systemctl show --property MainPID --value "$SERVICE_TO_KILL")

if [ "$PID_01" -ne 0 ]; then
    echo "[!] Sending signal 35 to $SERVICE_TO_KILL (PID: $PID_01)..."
    kill -35 "$PID_01"
else
    echo "Error: Could not find PID."
fi

# Wait for watchdog to trigger (WatchdogSec=1 → give buffer)
sleep 3

# 4. Trigger watchdog timeout again (after restart)
echo "......................................................."
echo "       Test: trigger watchdog timeout again"
echo "......................................................."
PID_01=$(systemctl show --property MainPID --value "$SERVICE_TO_KILL")

if [ "$PID_01" -ne 0 ]; then
    echo "[!] Sending signal 35 to $SERVICE_TO_KILL (PID: $PID_01)..."
    kill -35 "$PID_01"
else
    echo "Error: Could not find PID."
fi

sleep 3

# 5. Review results
echo "-----------------------------------------------"
echo "    Recent journal entries"
echo "-----------------------------------------------"
journalctl -u "$SERVICE_TO_KILL" --since "$TEST_START_TIME" --no-pager

# 6. Capture DLT logs
TIMEOUT_SEC=5
echo "-----------------------------------------------"
echo "    Capturing DLT logs for $TIMEOUT_SEC seconds..."
echo "-----------------------------------------------"
timeout "$TIMEOUT_SEC"s /bin/dlt-receive -a localhost | grep "$LOG_FILTER"

# 7. Stop services
for SERVICE in "$SERVICE_TO_KILL" "$SERVICE_TO_MONITOR"; do
    echo "-----------------------------------------------"
    echo "[*] Checking status: $SERVICE"

    if systemctl is-active --quiet "$SERVICE"; then
        echo "[!] $SERVICE is running. Stopping for a clean state..."
        systemctl stop "$SERVICE"
        sleep 1
    fi
done

echo "--- Test complete. DLT logging stopped. ---"
echo "******************************************************"