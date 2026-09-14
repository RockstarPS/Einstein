#!/bin/sh

# Configuration
SERVICE_TO_KILL="test_13.service"
SERVICE_TO_MONITOR="wdg_proxy_test_13.service"
LOG_FILTER="wdg_proxy"

echo "------------------------------------------------------------------"
echo "----- Test Case 22 - Restart Type: on-abort ----------------------"
echo "Cause of termination: Unclean signals (SIGKILL, SIGSEGV)"
echo ""
echo "Expected behavior:"
echo "  - Process should restart"
echo "  - Fatal error notification: No"
echo "  - Process restart: Yes"
echo ""
echo "[*] Configuration:"
echo "    Restart=on-abort"
echo "    SuccessExitStatus=255 SIGABRT"
echo "------------------------------------------------------------------"

# 1. Record test start time
TEST_START_TIME=$(date "+%Y-%m-%d %H:%M:%S")

# 2. Start services
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

# Function to send signal
send_signal() {
    local TEST_NAME=$1
    local SIGNAL=$2
    local DESC=$3

    echo "......................................................."
    echo "   $TEST_NAME"
    echo "......................................................."

    PID=$(systemctl show --property MainPID --value "$SERVICE_TO_KILL")

    if [ "$PID" -gt 0 ]; then
        echo "[!] Sending signal $SIGNAL ($DESC) to $SERVICE_TO_KILL (PID: $PID)"
        kill -"$SIGNAL" "$PID"
    else
        echo "[ERROR] Invalid PID for $SERVICE_TO_KILL (PID=$PID)"
        return
    fi

    sleep 3
}

# 3. Execute test (SIGKILL)
send_signal "Test with unclean signal (SIGKILL)" 9 "SIGKILL"

# 4. Show journal logs
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

# 6. Stop services (cleanup)
for SERVICE in "$SERVICE_TO_KILL" "$SERVICE_TO_MONITOR"; do
    echo "-----------------------------------------------"
    echo "[*] Checking status: $SERVICE"

    if systemctl is-active --quiet "$SERVICE"; then
        echo "[!] $SERVICE is running. Stopping for clean exit..."
        systemctl stop "$SERVICE"
        sleep 1
    else
        echo "[+] $SERVICE is already stopped"
    fi
done

echo "--------------------------------------------------"
echo "--- Test complete. DLT logging stopped. -----------"
echo "**************************************************"