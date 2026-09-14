#!/bin/sh

# Configuration
SERVICE_TO_KILL="test_15.service"
SERVICE_TO_MONITOR="wdg_proxy_test_15.service"
LOG_FILTER="wdg"

echo "------------------------------------------------------------------"
echo "----- Test Case 25 - Restart type: on-watchdog -------------------"
echo "Cause of termination: Watchdog 'keep-alive ping' timeout"
echo ""
echo "Expected behavior: Process should restart"
echo "Error notification (Fatal): No"
echo "Process restart: Yes"
echo "[*] Configuration:"
echo "    WatchdogSec=1"
echo "    Restart=on-watchdog"
echo "    SuccessExitStatus=255 SIGABRT"
echo "------------------------------------------------------------------"

# 1. Record test start time
TEST_START_TIME=$(date "+%Y-%m-%d %H:%M:%S")

# ---------- Start Services ----------
for SERVICE in "$SERVICE_TO_KILL" "$SERVICE_TO_MONITOR"; do
    echo "[>] Starting $SERVICE..."
    systemctl start "$SERVICE"

    if ! systemctl is-active --quiet "$SERVICE"; then
        echo "[ERROR] Failed to start $SERVICE"
        continue
    fi

    echo "[+] $SERVICE started successfully"
    sleep 2
done

# Function to send signal (simulate watchdog failure if applicable)
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

# ---------- Logs ----------
echo "-----------------------------------------------"
echo "Recent journal entries:"
echo "-----------------------------------------------"
journalctl -u "$SERVICE_TO_KILL" --since "$TEST_START_TIME" --no-pager

TIMEOUT_SEC=5
echo "-----------------------------------------------"
echo "Capturing DLT logs for $TIMEOUT_SEC seconds..."
echo "-----------------------------------------------"
timeout "${TIMEOUT_SEC}s" /bin/dlt-receive -a localhost | grep "$LOG_FILTER"

# ---------- Cleanup ----------
for SERVICE in "$SERVICE_TO_KILL" "$SERVICE_TO_MONITOR"; do
    echo "-----------------------------------------------"
    echo "[*] Checking status: $SERVICE"

    if systemctl is-active --quiet "$SERVICE"; then
        echo "[!] Stopping $SERVICE..."
        systemctl stop "$SERVICE"
        sleep 1
    fi
done

echo "--- Test complete. DLT logging stopped. ---"
echo "******************************************************"