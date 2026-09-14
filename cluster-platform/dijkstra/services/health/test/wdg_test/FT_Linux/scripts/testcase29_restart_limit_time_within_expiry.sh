#!/bin/sh

# Configuration
SERVICE_TO_KILL="test_16.service"
SERVICE_TO_MONITOR="wdg_proxy_test_16.service"
LOG_FILTER="wdg_proxy"

echo "------------------------------------------------------------------"
echo "----- Test Case 29 - Restart Type: always with limit (within interval) -----"
echo "  Cause of termination:"
echo "        (1) Clean exit with code 0"
echo "        (2) Clean signals: SIGHUP, SIGINT, SIGTERM, or SIGPIPE"
echo "        (3) Unclean exit with code 1"
echo "        (4) Unclean signals: SIGKILL, SIGSEGV"
echo "  Expected behavior:"
echo "        The process shall not be restarted after reaching the limit configured in StartLimitBurst,"
echo "        if it continuously crashes within the time period defined by StartLimitInterval."
echo "  Error Notification Fatal (Yes/No): Yes"
echo "  Process Restart (Yes/No): Yes"
echo "  [*] Configuration:"
echo "        Restart=always"
echo "        StartLimitBurst=3"
echo "        StartLimitInterval=5min"
echo "------------------------------------------------------------------"

# 1. Record the start time of this test cycle
TEST_START_TIME=$(date "+%Y-%m-%d %H:%M:%S")

# 2. Start the services
for SERVICE in "$SERVICE_TO_KILL" "$SERVICE_TO_MONITOR"; do
    echo "[>] Starting $SERVICE..."
    systemctl start "$SERVICE"

    # Verify service start
    if ! systemctl is-active --quiet "$SERVICE"; then
        echo "Error: Failed to start $SERVICE."
        continue
    fi

    echo "[+] $SERVICE started successfully."
    sleep 2
done

# 3. First test - clean exit (signal 35)
echo "......................................................."
echo "       First test with clean exit (code 0)"
echo "......................................................."
PID_01=$(systemctl show --property MainPID --value "$SERVICE_TO_KILL")

if [ "$PID_01" -ne 0 ]; then
    echo "[!] Sending signal 35 (SIGRTMIN+1) to $SERVICE_TO_KILL (PID: $PID_01)..."
    kill -35 "$PID_01"
else
    echo "Error: Could not find PID for $SERVICE_TO_KILL."
fi
sleep 2

# 4. Second test - clean exit
echo "......................................................."
echo "       Second test with clean exit (code 0)"
echo "......................................................."
PID_01=$(systemctl show --property MainPID --value "$SERVICE_TO_KILL")

if [ "$PID_01" -ne 0 ]; then
    echo "[!] Sending signal 35 (SIGRTMIN+1) to $SERVICE_TO_KILL (PID: $PID_01)..."
    kill -35 "$PID_01"
else
    echo "Error: Could not find PID for $SERVICE_TO_KILL."
fi
sleep 2

# 5. Third test - clean exit
echo "......................................................."
echo "       Third test with clean exit (code 0)"
echo "......................................................."
PID_01=$(systemctl show --property MainPID --value "$SERVICE_TO_KILL")

if [ "$PID_01" -ne 0 ]; then
    echo "[!] Sending signal 35 (SIGRTMIN+1) to $SERVICE_TO_KILL (PID: $PID_01)..."
    kill -35 "$PID_01"
else
    echo "Error: Could not find PID for $SERVICE_TO_KILL."
fi
sleep 2

# 6. Review results
echo "-----------------------------------------------"
echo "    Recent journal entries"
echo "-----------------------------------------------"
journalctl -u "$SERVICE_TO_KILL" --since "$TEST_START_TIME" --no-pager

# 7. Monitor DLT logs for a limited time
TIMEOUT_SEC=5
echo "-----------------------------------------------"
echo "   Capturing DLT logs for $TIMEOUT_SEC seconds..."
echo "-----------------------------------------------"
timeout "$TIMEOUT_SEC"s /bin/dlt-receive -a localhost | grep "$LOG_FILTER"

# 8. Stop the services
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