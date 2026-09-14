#!/bin/sh

# Configuration
SERVICE_TO_KILL="test_06.service"
SERVICE_TO_MONITOR="wdg_proxy_test_06.service"
LOG_FILTER="wdg_proxy"

echo "------------------------------------------------------------------"
echo "----- Test Case 11 - RestartPreventExitStatus behavior -----------"
echo "  Description:"
echo "        Even with Restart=always, the service will NOT restart"
echo "        if the exit code or signal matches RestartPreventExitStatus."
echo ""
echo "  Expected behavior:"
echo "        - No restart for exit code 255"
echo "        - No restart for SIGABRT"
echo "        - Restart for other signals (e.g., SIGKILL)"
echo ""
echo "  Error Notification Fatal (Yes/No): Yes"
echo "  Process Restart (Yes/No): Conditional"
echo "  [*] Configuration:"
echo "        Restart=always"
echo "        RestartPreventExitStatus=255 SIGABRT"
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

# Helper function
send_kill() {
    local sig=$1
    local desc=$2

    echo "......................................................."
    echo "       Test: $desc"
    echo "......................................................."

    PID_01=$(systemctl show --property MainPID --value "$SERVICE_TO_KILL")

    if [ "$PID_01" -ne 0 ]; then
        echo "[!] Sending signal $sig to $SERVICE_TO_KILL (PID: $PID_01)..."
        kill -$sig "$PID_01"
    else
        echo "Error: Could not find PID."
    fi

    sleep 2
}

# 4. Test SIGK 
send_kill 36 "SIG User Defined Signal 1 (should not restart)"

# 5. Test SIGABRT (should NOT restart)
send_kill 6 "SIGABRT (should NOT restart)"

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