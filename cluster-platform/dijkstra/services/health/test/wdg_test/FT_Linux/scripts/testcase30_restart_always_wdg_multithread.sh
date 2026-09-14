#!/bin/sh

# Configuration
SERVICE_TO_KILL="test_17.service"
SERVICE_TO_MONITOR="wdg_proxy_test_17.service"
LOG_FILTER="wdg"

echo "------------------------------------------------------------------"
echo "----- Testcase 30 - Restart type: Always (Watchdog multi-thread monitoring)"
echo "Cause of termination: Watchdog 'keep-alive ping' timeout"
echo "Expected behavior: Process restarts as per StartLimitBurst, then stops restarting"
echo "Error notification (Fatal): Yes"
echo "Process restart: Yes"
echo "[*] Configuration:"
echo "    Restart=always"
echo "    WatchdogSec=1"
echo "------------------------------------------------------------------"

# 1. Record the start time of THIS test cycle
TEST_START_TIME=$(date "+%Y-%m-%d %H:%M:%S")

# 2. Start the services
for SERVICE in "$SERVICE_TO_KILL" "$SERVICE_TO_MONITOR"; do
    echo "[>] Starting $SERVICE..."
    systemctl start "$SERVICE"

    # Verify start
    if ! systemctl is-active --quiet "$SERVICE"; then
        echo "[ERROR] Failed to start $SERVICE."
        continue
    fi

    echo "[+] $SERVICE started successfully."
    sleep 2
done

# 3. Wait for 10 seconds
echo "-----------------------------------------------"
echo "Waiting for 10 seconds..."
sleep 10

# 4. Review results
echo "-----------------------------------------------"
echo "Recent journal entries:"
echo "-----------------------------------------------"
journalctl -u "$SERVICE_TO_KILL" --since "$TEST_START_TIME" --no-pager

# 5. Monitor DLT with timeout
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
        echo "[!] $SERVICE is running. Stopping for clean test..."
        systemctl stop "$SERVICE"
        sleep 1
    fi
done

echo "--- Test complete. DLT logging stopped. ---"
echo "******************************************************"