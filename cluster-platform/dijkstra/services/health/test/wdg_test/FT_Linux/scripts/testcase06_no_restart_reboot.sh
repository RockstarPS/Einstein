#!/bin/sh

# Configuration
SERVICE_TO_KILL="test_01.service"
SERVICE_TO_MONITOR="wdg_proxy_test_01.service"
LOG_FILTER="wdg_proxy"

echo "------------------------------------------------------------------"
echo "----- Test Case 6 - No Restart -----------------------------------"
echo "Cause: Service not started / not available"
echo ""
echo "Expected behavior:"
echo "  - Fatal error notification: Yes"
echo "  - Process restart: No"
echo "------------------------------------------------------------------"

# 1. Record the start time of THIS test cycle
TEST_START_TIME=$(date "+%Y-%m-%d %H:%M:%S")

# 2. Start the services
echo "[>] Starting $SERVICE_TO_MONITOR..."
systemctl start "$SERVICE_TO_MONITOR"

# 3. Verify start
if ! systemctl is-active --quiet "$SERVICE_TO_MONITOR"; then
     echo "Error: Failed to start $SERVICE_TO_MONITOR."
     continue
fi
echo "[+] $SERVICE_TO_MONITOR started successfully."

# 4. Review Results
echo "-----------------------------------------------"
echo "    Recent Journal Entries "
echo "-----------------------------------------------"
journalctl -u "$SERVICE_TO_KILL" --since "$TEST_START_TIME" --no-pager

# 5. Monitor DLT with a 5-second timeout
# This will stop the script automatically after 5 seconds
TIMEOUT_SEC=5
echo "-----------------------------------------------"
echo "    Capturing DLT Logs for $TIMEOUT_SEC seconds... "
echo "-----------------------------------------------"
timeout "$TIMEOUT_SEC"s /bin/dlt-receive -a localhost | grep "$LOG_FILTER"

# 6. Stop the services
for SERVICE in "$SERVICE_TO_KILL" "$SERVICE_TO_MONITOR"; do
    echo "-----------------------------------------------"
    echo "[*] Checking Status: $SERVICE"

    # 6.1. Stop if already running for a fresh start
    if systemctl is-active --quiet "$SERVICE"; then
        echo "[!] $SERVICE is running. Stopping for clean test..."
        systemctl stop "$SERVICE"
        sleep 1
    fi
done

echo "--- Test Complete. DLT logging stopped. ---"
echo "******************************************************"
