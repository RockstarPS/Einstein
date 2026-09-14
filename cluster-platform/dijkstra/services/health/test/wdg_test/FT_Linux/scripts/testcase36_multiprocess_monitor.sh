#!/bin/sh

# Configuration
SERVICE_TO_STOP="test_18_4.service"
LOG_FILTER="wdg_proxy"

echo "------------------------------------------------------------------"
echo "----- Testcase 36 - Graceful Stop / No Fatal ---------------------"
echo "  Configuration:"
echo "        (1). Restart action - no / manual"
echo "        (2). Watchdog - enabled"
echo "        (3). Service stopped gracefully using systemctl stop"
echo ""
echo "  Expected behaviour:"
echo "        Fatal Error Notification : No"
echo "        Process Restart         : No"
echo "        Service State          : inactive"
echo "------------------------------------------------------------------"

# 1. Record start time of test
TEST_START_TIME=$(date "+%Y-%m-%d %H:%M:%S")

# 2. Start services
SERVICES="test_18_1.service test_18_2.service test_18_3.service test_18_4.service test_18_5.service wdg_proxy_test_18.service"

for SERVICE in $SERVICES; do
    echo "[>] Starting $SERVICE ..."
    systemctl start "$SERVICE"

    if systemctl is-active --quiet "$SERVICE"; then
        echo "[+] $SERVICE started successfully."
    else
        echo "[!] Failed to start $SERVICE"
    fi
    sleep 2
done

# 3. Gracefully stop target service
echo "-----------------------------------------------"
echo "--- Graceful Stop Test ------------------------"
echo "-----------------------------------------------"

echo "[!] Stopping $SERVICE_TO_STOP using systemctl stop ..."
systemctl stop "$SERVICE_TO_STOP"
sleep 3

# 4. Verify service is stopped
echo "-----------------------------------------------"
echo "--- Service Status ----------------------------"
echo "-----------------------------------------------"

systemctl status "$SERVICE_TO_STOP" --no-pager

if systemctl is-active --quiet "$SERVICE_TO_STOP"; then
    echo "[!] $SERVICE_TO_STOP is still active"
else
    echo "[+] $SERVICE_TO_STOP is inactive as expected"
fi

# 5. Review journal logs
echo "-----------------------------------------------"
echo "--- Recent Journal Entries --------------------"
echo "-----------------------------------------------"

journalctl -u "$SERVICE_TO_STOP" --since "$TEST_START_TIME" --no-pager

# 6. Capture watchdog logs (expect NO fatal)
TIMEOUT_SEC=5
echo "-----------------------------------------------"
echo "--- Capturing DLT Logs for $TIMEOUT_SEC sec ---"
echo "-----------------------------------------------"

timeout "$TIMEOUT_SEC"s /bin/dlt-receive -a localhost | grep "$LOG_FILTER"

echo ""
echo "Expected Result:"
echo " - No fatal error should be reported"
echo " - Service should remain stopped"
echo " - No unwanted restart"

# 7. Cleanup remaining services
for SERVICE in $SERVICES; do
    if systemctl is-active --quiet "$SERVICE"; then
        echo "[!] Stopping $SERVICE ..."
        systemctl stop "$SERVICE"
        sleep 1
    fi
done

echo "------------------------------------------------"
echo "--- Test Complete ------------------------------"
echo "------------------------------------------------"