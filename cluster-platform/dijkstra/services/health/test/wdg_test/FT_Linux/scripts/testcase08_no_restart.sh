#!/bin/sh

# Configuration
SERVICE_TO_KILL="test_03.service"
SERVICE_TO_MONITOR="wdg_proxy_test_03.service"
LOG_FILTER="wdg_proxy"

echo "------------------------------------------------------------------"
echo "----- Test Case 8 - RestartForceExitStatus behavior --------------"
echo "  Description:"
echo "        Services will be restarted if the exit code or signal is"
echo "        specified in RestartForceExitStatus, even when Restart=no."
echo ""
echo "  Expected behavior:"
echo "        - Restart occurs for exit code 255"
echo "        - Restart occurs for SIGABRT"
echo "        - No restart for other signals (e.g., SIGKILL)"
echo ""
echo "  Error Notification Fatal (Yes/No): Yes"
echo "  Process Restart (Yes/No): Conditional"
echo "  [*] Configuration:"
echo "        Restart=no"
echo "        RestartForceExitStatus=255 SIGABRT"
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

# 3. Test exit code 255 (via signal-triggered logic in app)
echo "......................................................."
echo "       Test: exit code 255 (should restart)"
echo "......................................................."
PID_01=$(systemctl show --property MainPID --value "$SERVICE_TO_KILL")

if [ "$PID_01" -ne 0 ]; then
    echo "[!] Sending signal 36 to $SERVICE_TO_KILL (PID: $PID_01)..."
    kill -36 "$PID_01"
else
    echo "Error: Could not find PID."
fi
sleep 2

# 4. Test SIGABRT (should restart)
echo "......................................................."
echo "       Test: SIGABRT (should restart)"
echo "......................................................."
PID_01=$(systemctl show --property MainPID --value "$SERVICE_TO_KILL")

if [ "$PID_01" -ne 0 ]; then
    echo "[!] Sending signal 6 (SIGABRT) to $SERVICE_TO_KILL (PID: $PID_01)..."
    kill -6 "$PID_01"
else
    echo "Error: Could not find PID."
fi
sleep 2

# 5. Test SIGKILL (should NOT restart)
echo "......................................................."
echo "       Test: SIGKILL (should NOT restart)"
echo "......................................................."
PID_01=$(systemctl show --property MainPID --value "$SERVICE_TO_KILL")

if [ "$PID_01" -ne 0 ]; then
    echo "[!] Sending signal 9 (SIGKILL) to $SERVICE_TO_KILL (PID: $PID_01)..."
    kill -9 "$PID_01"
else
    echo "Error: Could not find PID."
fi
sleep 2

# 6. Review results
echo "-----------------------------------------------"
echo "    Recent journal entries"
echo "-----------------------------------------------"
journalctl -u "$SERVICE_TO_KILL" --since "$TEST_START_TIME" --no-pager

# 7. Capture DLT logs
TIMEOUT_SEC=5
echo "-----------------------------------------------"
echo "    Capturing DLT logs for $TIMEOUT_SEC seconds..."
echo "-----------------------------------------------"
timeout "$TIMEOUT_SEC"s /bin/dlt-receive -a localhost | grep "$LOG_FILTER"

# 8. Stop services
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