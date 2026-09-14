#!/bin/sh

# Configuration
SERVICE_TO_KILL="test_15.service"
SERVICE_TO_MONITOR="wdg_proxy_test_15.service"
LOG_FILTER="wdg_proxy"

echo "------------------------------------------------------------------"
echo "-----   Testcase 29 - Restart type - on watchdog -----------------"
echo "  Cause of the death:                            "
echo "       (1). clean exit code 0 "
echo "       (2). one of the clean signals SIGHUP, SIGINT, SIGTERM, or SIGPIPE"
echo "       (3). exit status mentioned in SuccessExitStatus=  255 SIGABRT."
echo "       (4). unclean exit code 1"
echo "  Actual behaviour -   No Process restart "
echo "  Error Notification Fatal (Yes/No) : Yes         "
echo "  Process restart (Yes/No) : No                   "
echo "  [*]Configuration: WatchdogSec=1"
echo "                    Restart=on-watchdog"
echo "                    SuccessExitStatus=255 SIGABRT"
echo "------------------------------------------------------------------"

# ---------- Common Functions ----------

start_services() {
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
}

stop_services() {
    for SERVICE in "$SERVICE_TO_KILL" "$SERVICE_TO_MONITOR"; do
        echo "[*] Checking status: $SERVICE"

        if systemctl is-active --quiet "$SERVICE"; then
            echo "[!] $SERVICE is running. Stopping for clean test..."
            systemctl stop "$SERVICE"
            sleep 1
        fi
    done
}

send_signal() {
    local SIGNAL=$1
    local DESC=$2

    PID=$(systemctl show --property MainPID --value "$SERVICE_TO_KILL")

    if [[ "$PID" =~ ^[0-9]+$ && "$PID" -gt 0 ]]; then
        echo "[!] Sending signal $SIGNAL ($DESC) to $SERVICE_TO_KILL (PID: $PID)"
        kill -"$SIGNAL" "$PID"
    else
        echo "[ERROR] Invalid PID: $PID"
    fi

    sleep 2
}

verify_no_restart() {
    local OLD_PID=$1
    local NEW_PID

    NEW_PID=$(systemctl show --property MainPID --value "$SERVICE_TO_KILL")

    echo "[INFO] Old PID: $OLD_PID"
    echo "[INFO] New PID: $NEW_PID"

    if systemctl is-active --quiet "$SERVICE_TO_KILL"; then
        if [ "$OLD_PID" == "$NEW_PID" ]; then
            echo "[PASS] No restart occurred (expected)"
        else
            echo "[FAIL] Unexpected restart detected"
        fi
    else
        echo "[FAIL] Service is not running"
    fi
}

collect_logs() {
    echo "-----------------------------------------------"
    echo "Recent journal entries:"
    echo "-----------------------------------------------"
    journalctl -u "$SERVICE_TO_KILL" --since "$TEST_START_TIME" --no-pager

    TIMEOUT_SEC=5
    echo "-----------------------------------------------"
    echo "Capturing DLT logs for $TIMEOUT_SEC seconds..."
    echo "-----------------------------------------------"
    timeout "${TIMEOUT_SEC}s" /bin/dlt-receive -a localhost | grep "$LOG_FILTER"
}

# ---------- Scenario 1 ----------
echo "......................................................."
echo "Scenario 1: Clean exit (code 0)"
echo "......................................................."
TEST_START_TIME=$(date "+%Y-%m-%d %H:%M:%S")
start_services
OLD_PID=$(systemctl show --property MainPID --value "$SERVICE_TO_KILL")
send_signal 35 "SIGRTMIN+1"
verify_no_restart "$OLD_PID"
collect_logs
stop_services

# ---------- Scenario 2 ----------
echo "......................................................."
echo "Scenario 2: Clean signal (SIGHUP)"
echo "......................................................."
TEST_START_TIME=$(date "+%Y-%m-%d %H:%M:%S")
start_services
OLD_PID=$(systemctl show --property MainPID --value "$SERVICE_TO_KILL")
send_signal 1 "SIGHUP"
verify_no_restart "$OLD_PID"
collect_logs
stop_services

# ---------- Scenario 3 ----------
echo "......................................................."
echo "Scenario 3: Unclean exit (code 1)"
echo "......................................................."
TEST_START_TIME=$(date "+%Y-%m-%d %H:%M:%S")
start_services
OLD_PID=$(systemctl show --property MainPID --value "$SERVICE_TO_KILL")
send_signal 37 "SIGRTMIN+3"
verify_no_restart "$OLD_PID"
collect_logs
stop_services

# ---------- Scenario 4 ----------
echo "......................................................."
echo "Scenario 3: Unclean signal (SIGKILL)"
echo "......................................................."
TEST_START_TIME=$(date "+%Y-%m-%d %H:%M:%S")
start_services
OLD_PID=$(systemctl show --property MainPID --value "$SERVICE_TO_KILL")
send_signal 9 "SIGKILL"
verify_no_restart "$OLD_PID"
collect_logs
stop_services

echo "--- Test complete. DLT logging stopped. ---"
echo "******************************************************"
