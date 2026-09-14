#!/bin/sh

# Configuration
SERVICE_TO_STOP="test_18_1.service"
SERVICE_TO_KILL="test_18_4.service"
SERVICE_TO_MONITOR="wdg_proxy_test_18.service"
LOG_FILTER="wdg_proxy"

echo "------------------------------------------------------------------"
echo "-----   Testcase 37 - Mixed Stop + Fatal Kill  -------------------"
echo "  Configuration:"
echo "        (1). Restart action - always"
echo "        (2). Watchdog - enabled"
echo "        (3). Restart Limit - 3"
echo "        (4). One service stopped gracefully"
echo "        (5). One service killed (fatal expected)"
echo ""
echo "  Expected behaviour:"
echo "        $SERVICE_TO_STOP  -> No fatal, No restart"
echo "        $SERVICE_TO_KILL  -> Fatal + Restart"
echo "------------------------------------------------------------------"

# 1. Record test start time
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

# 4. Kill second service (fatal expected)
PID=$(systemctl show --property MainPID --value "$SERVICE_TO_KILL")

if [ "$PID" -ne 0 ]; then
    echo "[!] Killing $SERVICE_TO_KILL (PID: $PID) with Signal 9..."
    kill -9 "$PID"
else
    echo "[!] Error: Could not find PID for $SERVICE_TO_KILL"
fi

sleep 3

PID=$(systemctl show --property MainPID --value "$SERVICE_TO_KILL")

if [ "$PID" -ne 0 ]; then
    echo "[!] Killing $SERVICE_TO_KILL (PID: $PID) with Signal 9..."
    kill -9 "$PID"
else
    echo "[!] Error: Could not find PID for $SERVICE_TO_KILL"
fi

sleep 3

PID=$(systemctl show --property MainPID --value "$SERVICE_TO_KILL")

if [ "$PID" -ne 0 ]; then
    echo "[!] Killing $SERVICE_TO_KILL (PID: $PID) with Signal 9..."
    kill -9 "$PID"
else
    echo "[!] Error: Could not find PID for $SERVICE_TO_KILL"
fi

sleep 3


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