#!/bin/sh

# Configuration
SERVICE_TO_KILL="test_01.service"
SERVICE_TO_MONITOR="wdg_proxy_test_01.service"
LOG_FILTER="wdg_proxy"

echo "------------------------------------------------------------------"
echo "----- Test Case 5 - Restart type: no restart ---------------------"
echo "  Cause of termination:"
echo "        Unclean signals: SIGKILL, SIGSEGV"
echo ""
echo "  Expected behavior:"
echo "        The process shall not be restarted."
echo ""
echo "  Error Notification Fatal (Yes/No): Yes"
echo "  Process Restart (Yes/No): No"
echo "  [*] Configuration:"
echo "        Restart=no"
echo "------------------------------------------------------------------"

# 1. Record the start time of this test cycle
TEST_START_TIME=$(date "+%Y-%m-%d %H:%M:%S")

# 2. Start the services
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

# 3. Trigger unclean termination using SIGKILL
echo "......................................................."
echo "       Test with unclean signal termination (SIGKILL)"
echo "......................................................."
PID_01=$(systemctl show --property MainPID --value "$SERVICE_TO_KILL")

if [ "$PID_01" -ne 0 ]; then
    echo "[!] Sending signal 9 (SIGKILL) to $SERVICE_TO_KILL (PID: $PID_01)..."
    kill -9 "$PID_01"
else
    echo "Error: Could not find PID for $SERVICE_TO_KILL."
fi
sleep 1

# 4. Review results
echo "-----------------------------------------------"
echo "    Recent journal entries"
echo "-----------------------------------------------"
journalctl -u "$SERVICE_TO_KILL" --since "$TEST_START_TIME" --no-pager

# 5. Capture DLT logs
TIMEOUT_SEC=5
echo "-----------------------------------------------"
echo "    Capturing DLT logs for $TIMEOUT_SEC seconds..."
echo "-----------------------------------------------"
timeout "$TIMEOUT_SEC"s /bin/dlt-receive -a localhost | grep "$LOG_FILTER"

# 6. Stop the services
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