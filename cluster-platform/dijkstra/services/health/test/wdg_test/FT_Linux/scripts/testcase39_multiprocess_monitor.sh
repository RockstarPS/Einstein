#!/bin/sh

# Configuration
SERVICE_TO_STOP="test_19_1.service"
SERVICE_TO_KILL="test_19_4.service"
SERVICE_TO_MONITOR="wdg_proxy_test_19.service"
LOG_FILTER="wdg_proxy"

echo "------------------------------------------------------------------"
echo "-----   Testcase 39 - Graceful Stop  -------------------"
echo "  Configuration:"
echo "        (1). Restart action - always"
echo "        (2). Watchdog - enabled"
echo ""
echo "  Expected behaviour:"
echo "        $SERVICE_TO_STOP  -> No fatal"
echo "        $SERVICE_TO_KILL  -> No fatal"
echo "------------------------------------------------------------------"

# 1. Record test start time
TEST_START_TIME=$(date "+%Y-%m-%d %H:%M:%S")

# 2. Start services
SERVICES="test_19_1.service test_19_2.service test_19_3.service test_19_4.service test_19_5.service wdg_proxy_test_19.service"

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

echo "-----------------------------------------------"
echo "--- Stop + Kill Test --------------------------"
echo "-----------------------------------------------"

# 3. Graceful stop
echo "[!] Stopping $SERVICE_TO_STOP using systemctl stop ..."
systemctl stop "$SERVICE_TO_STOP"
sleep 2

# Verify stop
if systemctl is-active --quiet "$SERVICE_TO_STOP"; then
    echo "[!] $SERVICE_TO_STOP is still active"
else
    echo "[+] $SERVICE_TO_STOP stopped gracefully (inactive)"
fi



# 5. Service status check
echo "-----------------------------------------------"
echo "--- Service Status ----------------------------"
echo "-----------------------------------------------"

systemctl status "$SERVICE_TO_STOP" --no-pager
systemctl status "$SERVICE_TO_KILL" --no-pager

# 6. Journal logs
echo "-----------------------------------------------"
echo "--- Journal Logs ------------------------------"
echo "-----------------------------------------------"

echo "[*] Logs for $SERVICE_TO_STOP"
journalctl -u "$SERVICE_TO_STOP" --since "$TEST_START_TIME" --no-pager

echo "[*] Logs for $SERVICE_TO_KILL"
journalctl -u "$SERVICE_TO_KILL" --since "$TEST_START_TIME" --no-pager

# 7. Capture watchdog logs
TIMEOUT_SEC=5
echo "-----------------------------------------------"
echo "--- Capturing DLT Logs for $TIMEOUT_SEC sec ---"
echo "-----------------------------------------------"

timeout "$TIMEOUT_SEC"s /bin/dlt-receive -a localhost | grep "$LOG_FILTER"

echo ""
echo "Expected Result:"
echo " - $SERVICE_TO_STOP should remain stopped (no restart)"
echo " - $SERVICE_TO_KILL should trigger fatal + restart"
echo " - Watchdog should react only to killed service"

# 8. Cleanup
echo "-----------------------------------------------"
echo "--- Cleanup ----------------------------------"
echo "-----------------------------------------------"

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