#!/bin/sh

# Configuration
SERVICE_TO_KILL="test_08.service"
SERVICE_TO_MONITOR="wdg_proxy_test_08.service"
LOG_FILTER="wdg"

echo "------------------------------------------------------------------"
echo "----- Test Case 15 - Restart type: on-success --------------------"
echo "Cause of termination: Watchdog 'keep-alive ping' timeout"
echo ""
echo "Expected behavior: Process should NOT restart"
echo "Error notification (Fatal): Yes"
echo "Process restart: No"
echo "[*] Configuration:"
echo "    Restart=on-success"
echo "    WatchdogSec=1"
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

# Function to send signal (to simulate watchdog failure trigger if applicable)
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

# 3. Execute test
send_signal "Test with watchdog timeout" 35 "SIGRTMIN+1"

# 4. Review results
echo "-----------------------------------------------"
echo "Recent journal entries:"
echo "-----------------------------------------------"
journalctl -u "$SERVICE_TO_KILL" --since "$TEST_START_TIME" --no-pager

# 5. Capture DLT logs
TIMEOUT_SEC=5
echo "-----------------------------------------------"
echo "Capturing DLT logs for $TIMEOUT_SEC seconds..."
echo "-----------------------------------------------"
timeout "${TIMEOUT_SEC}s" /bin/dlt-receive -a localhost | grep "$LOG_FILTER"

# 6. Stop the services
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