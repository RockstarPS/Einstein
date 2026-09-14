#!/bin/sh

# Configuration
SERVICE_TO_KILL="test_09.service"
SERVICE_TO_MONITOR="wdg_proxy_test_09.service"
LOG_FILTER="wdg_proxy"

echo "------------------------------------------------------------------"
echo "----- Test Case 18 - Restart type: on-failure --------------------"
echo "Cause of termination:"
echo "    (1) Clean exit (code 0)"
echo "    (2) Clean signals: SIGHUP, SIGINT, SIGTERM, SIGPIPE"
echo "    (3) Exit statuses defined in SuccessExitStatus"
echo ""
echo "Expected behavior: Process should NOT restart"
echo "Error notification (Fatal): Yes"
echo "Process restart: No"
echo "[*] Configuration:"
echo "    Restart=on-failure"
echo "    SuccessExitStatus=255 SIGABRT"
echo "------------------------------------------------------------------"

# Function: start services
start_services() {
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
}

# Function: stop services
stop_services() {
    for SERVICE in "$SERVICE_TO_KILL" "$SERVICE_TO_MONITOR"; do
        echo "[*] Checking status: $SERVICE"

        if systemctl is-active --quiet "$SERVICE"; then
            echo "[!] $SERVICE is running. Stopping for a clean test..."
            systemctl stop "$SERVICE"
            sleep 1
        fi
    done
}

# Function: send signal
send_signal() {
    local SIGNAL=$1
    local DESC=$2

    PID=$(systemctl show --property MainPID --value "$SERVICE_TO_KILL")

    if [ "$PID" -ne 0 ]; then
        echo "[!] Sending signal $SIGNAL ($DESC) to $SERVICE_TO_KILL (PID: $PID)..."
        kill -"$SIGNAL" "$PID"
    else
        echo "[ERROR] Could not find PID for $SERVICE_TO_KILL."
    fi

    sleep 2
}

# Function: collect logs
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
send_signal 35 "SIGRTMIN+1"
collect_logs
stop_services

# ---------- Scenario 2 ----------
echo "......................................................."
echo "Scenario 2: Exit code 255 (SuccessExitStatus)"
echo "......................................................."
TEST_START_TIME=$(date "+%Y-%m-%d %H:%M:%S")
start_services
send_signal 36 "SIGRTMIN+2"
collect_logs
stop_services

# ---------- Scenario 3 ----------
echo "......................................................."
echo "Scenario 3: Clean signal (SIGHUP)"
echo "......................................................."
TEST_START_TIME=$(date "+%Y-%m-%d %H:%M:%S")
start_services
send_signal 1 "SIGHUP"
collect_logs
stop_services

# ---------- Scenario 4 ----------
echo "......................................................."
echo "Scenario 4: Signal in SuccessExitStatus (SIGABRT)"
echo "......................................................."
TEST_START_TIME=$(date "+%Y-%m-%d %H:%M:%S")
start_services
send_signal 6 "SIGABRT"
collect_logs
stop_services

echo "--- Test complete. DLT logging stopped. ---"
echo "******************************************************"