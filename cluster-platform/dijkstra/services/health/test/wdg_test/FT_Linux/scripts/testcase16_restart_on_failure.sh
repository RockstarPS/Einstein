#!/bin/sh

# Configuration
SERVICE_TO_KILL="test_09.service"
SERVICE_TO_MONITOR="wdg_proxy_test_09.service"
LOG_FILTER="wdg_proxy"

echo "------------------------------------------------------------------"
echo "----- Test Case 16 - Restart type: on-failure --------------------"
echo "Cause of termination:"
echo "    (1) Unclean exit (non-zero exit code)"
echo "    (2) Unclean signal (SIGKILL)"
echo ""
echo "Expected behavior: Process should restart"
echo "Error notification (Fatal): No"
echo "Process restart: Yes"
echo "[*] Configuration:"
echo "    Restart=on-failure"
echo "    SuccessExitStatus=255 SIGABRT"
echo "------------------------------------------------------------------"

# 1. Record the start time of this test cycle
TEST_START_TIME=$(date "+%Y-%m-%d %H:%M:%S")

# 2. Start the services
for SERVICE in "$SERVICE_TO_KILL" "$SERVICE_TO_MONITOR"; do
    echo "[>] Starting $SERVICE..."
    systemctl start "$SERVICE"

    if ! systemctl is-active --quiet "$SERVICE"; then
        echo "[ERROR] Failed to start $SERVICE."
        continue
    fi

    echo "[+] $SERVICE started successfully."
    sleep 2
done

# Function to send signal
send_signal() {
    local TEST_NAME=$1
    local SIGNAL=$2
    local DESC=$3

    echo "......................................................."
    echo "   $TEST_NAME"
    echo "......................................................."

    PID=$(systemctl show --property MainPID --value "$SERVICE_TO_KILL")

    if [ "$PID" -ne 0 ]; then
        echo "[!] Sending signal $SIGNAL ($DESC) to $SERVICE_TO_KILL (PID: $PID)..."
        kill -"$SIGNAL" "$PID"
    else
        echo "[ERROR] Could not find PID for $SERVICE_TO_KILL."
    fi

    sleep 2
}

# 3–4. Execute tests
send_signal "Test with unclean exit (code 1)" 37 "SIGRTMIN+3"
send_signal "Test with unclean signal (SIGKILL)" 9 "SIGKILL"

# 5. Review results
echo "-----------------------------------------------"
echo "Recent journal entries:"
echo "-----------------------------------------------"
journalctl -u "$SERVICE_TO_KILL" --since "$TEST_START_TIME" --no-pager

# 6. Capture DLT logs
TIMEOUT_SEC=5
echo "-----------------------------------------------"
echo "Capturing DLT logs for $TIMEOUT_SEC seconds..."
echo "-----------------------------------------------"
timeout "${TIMEOUT_SEC}s" /bin/dlt-receive -a localhost | grep "$LOG_FILTER"

# 7. Stop the services
for SERVICE in "$SERVICE_TO_KILL" "$SERVICE_TO_MONITOR"; do
    echo "-----------------------------------------------"
    echo "[*] Checking status: $SERVICE"

    if systemctl is-active --quiet "$SERVICE"; then
        echo "[!] $SERVICE is running. Stopping for a clean test..."
        systemctl stop "$SERVICE"
        sleep 1
    fi
done

echo "--- Test complete. DLT logging stopped. ---"
echo "******************************************************"