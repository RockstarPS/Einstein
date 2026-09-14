#!/bin/sh

PARENT_SERVICE="test_20_1.service"
REQUIRES_SERVICE="test_20_2.service"
BEFORE_SERVICE="test_20_3.service"
BEFORE_TARGET_SERVICE="test_20_4.service"
CONFLICT_A_SERVICE="test_20_5.service"
CONFLICT_B_SERVICE="test_20_6.service"
SERVICE_TO_MONITOR="wdg_proxy_test_20.service"
LOG_FILTER="wdg_proxy"
SERVICES="$PARENT_SERVICE $REQUIRES_SERVICE $BEFORE_SERVICE $BEFORE_TARGET_SERVICE $CONFLICT_A_SERVICE $CONFLICT_B_SERVICE $SERVICE_TO_MONITOR"
RESULT=0

echo "------------------------------------------------------------------"
echo "----- Test Case 42 - systemd dependency relationships ------------"
echo ""
echo "Expected behavior:"
echo "    Requires= + After= starts required parent before child and stops child when parent stops"
echo "    Requires= does not stop child when required parent crashes unexpectedly"
echo "    Before= orders source before target in the same transaction"
echo "    Conflicts= stops the conflicting active service"
echo "    Watchdog proxy observes Requires= dependency-driven stops without restart loops"
echo "------------------------------------------------------------------"

TEST_START_TIME=$(date "+%Y-%m-%d %H:%M:%S")

fail_test() {
    echo "[ERROR] $1"
    RESULT=1
}

get_property() {
    systemctl show --property "$2" --value "$1"
}

contains_unit() {
    echo " $1 " | grep -q " $2 "
}

assert_dependency() {
    SERVICE=$1
    PROPERTY=$2
    EXPECTED=$3
    VALUE=$(get_property "$SERVICE" "$PROPERTY")

    echo "[*] $SERVICE $PROPERTY=$VALUE"
    if contains_unit "$VALUE" "$EXPECTED"; then
        echo "[+] $SERVICE has $PROPERTY dependency on $EXPECTED"
    else
        fail_test "$SERVICE missing $PROPERTY dependency on $EXPECTED"
    fi
}

assert_state() {
    SERVICE=$1
    EXPECTED=$2
    STATE=$(get_property "$SERVICE" ActiveState)

    echo "[*] $SERVICE ActiveState=$STATE"
    if [ "$STATE" = "$EXPECTED" ]; then
        echo "[+] $SERVICE is $EXPECTED"
    else
        fail_test "$SERVICE expected $EXPECTED but is $STATE"
    fi
}

assert_no_restart_increment() {
    SERVICE=$1
    BEFORE=$2
    AFTER=$(get_property "$SERVICE" NRestarts)

    echo "[*] $SERVICE NRestarts before=$BEFORE after=$AFTER"
    if [ "$BEFORE" = "$AFTER" ]; then
        echo "[+] $SERVICE did not restart"
    else
        fail_test "$SERVICE restarted unexpectedly"
    fi
}

start_service() {
    SERVICE=$1
    echo "[>] Starting $SERVICE ..."
    systemctl start "$SERVICE"
    sleep 1
    if systemctl is-active --quiet "$SERVICE"; then
        echo "[+] $SERVICE started"
    else
        fail_test "$SERVICE failed to start"
        systemctl status "$SERVICE" --no-pager
        exit "$RESULT"
    fi
}

echo "-----------------------------------------------"
echo "--- Preparing services ------------------------"
echo "-----------------------------------------------"

systemctl daemon-reload
for SERVICE in $SERVICES; do
    systemctl stop "$SERVICE" >/dev/null 2>&1
    systemctl reset-failed "$SERVICE" >/dev/null 2>&1
done

echo "-----------------------------------------------"
echo "--- Verifying unit configuration --------------"
echo "-----------------------------------------------"

assert_dependency "$REQUIRES_SERVICE" Requires "$PARENT_SERVICE"
assert_dependency "$REQUIRES_SERVICE" After "$PARENT_SERVICE"
assert_dependency "$BEFORE_SERVICE" Before "$BEFORE_TARGET_SERVICE"
assert_dependency "$BEFORE_TARGET_SERVICE" Requires "$BEFORE_SERVICE"
assert_dependency "$CONFLICT_A_SERVICE" Conflicts "$CONFLICT_B_SERVICE"
assert_dependency "$CONFLICT_B_SERVICE" Conflicts "$CONFLICT_A_SERVICE"

echo "-----------------------------------------------"
echo "--- Requires and After behavior ---------------"
echo "-----------------------------------------------"

systemctl stop "$PARENT_SERVICE" >/dev/null 2>&1
systemctl reset-failed "$PARENT_SERVICE" "$REQUIRES_SERVICE" >/dev/null 2>&1
start_service "$PARENT_SERVICE"
start_service "$REQUIRES_SERVICE"
assert_state "$PARENT_SERVICE" active
assert_state "$REQUIRES_SERVICE" active
start_service "$SERVICE_TO_MONITOR"
REQUIRES_RESTARTS_BEFORE=$(get_property "$REQUIRES_SERVICE" NRestarts)

echo "[>] Stopping required parent $PARENT_SERVICE ..."
systemctl stop "$PARENT_SERVICE"
sleep 2

assert_state "$PARENT_SERVICE" inactive
assert_state "$REQUIRES_SERVICE" inactive
assert_no_restart_increment "$REQUIRES_SERVICE" "$REQUIRES_RESTARTS_BEFORE"

echo "[>] Stopping $SERVICE_TO_MONITOR after Requires= watchdog validation ..."
systemctl stop "$SERVICE_TO_MONITOR" >/dev/null 2>&1
sleep 1

echo "-----------------------------------------------"
echo "--- Requires parent crash behavior ------------"
echo "-----------------------------------------------"

systemctl stop "$PARENT_SERVICE" "$REQUIRES_SERVICE" >/dev/null 2>&1
systemctl reset-failed "$PARENT_SERVICE" "$REQUIRES_SERVICE" >/dev/null 2>&1
start_service "$PARENT_SERVICE"
start_service "$REQUIRES_SERVICE"
assert_state "$PARENT_SERVICE" active
assert_state "$REQUIRES_SERVICE" active
REQUIRES_RESTARTS_BEFORE=$(get_property "$REQUIRES_SERVICE" NRestarts)

PID=$(systemctl show --property MainPID --value "$PARENT_SERVICE")
if [ "$PID" -ne 0 ]; then
    echo "[>] Killing required parent $PARENT_SERVICE with SIGKILL, PID=$PID ..."
    kill -9 "$PID"
else
    fail_test "Could not find PID for $PARENT_SERVICE"
fi
sleep 3

assert_state "$PARENT_SERVICE" failed
assert_state "$REQUIRES_SERVICE" active
assert_no_restart_increment "$REQUIRES_SERVICE" "$REQUIRES_RESTARTS_BEFORE"

echo "[*] Requires= does not bind child lifetime to unexpected parent crash. Use BindsTo= if child must stop on crash."

systemctl stop "$REQUIRES_SERVICE" "$PARENT_SERVICE" >/dev/null 2>&1
systemctl reset-failed "$REQUIRES_SERVICE" "$PARENT_SERVICE" >/dev/null 2>&1

echo "-----------------------------------------------"
echo "--- Before ordering transaction ---------------"
echo "-----------------------------------------------"

systemctl stop "$BEFORE_TARGET_SERVICE" "$BEFORE_SERVICE" >/dev/null 2>&1
systemctl reset-failed "$BEFORE_TARGET_SERVICE" "$BEFORE_SERVICE" >/dev/null 2>&1
start_service "$BEFORE_TARGET_SERVICE"
assert_state "$BEFORE_SERVICE" active
assert_state "$BEFORE_TARGET_SERVICE" active

echo "-----------------------------------------------"
echo "--- Conflicts behavior ------------------------"
echo "-----------------------------------------------"

systemctl stop "$CONFLICT_A_SERVICE" "$CONFLICT_B_SERVICE" >/dev/null 2>&1
systemctl reset-failed "$CONFLICT_A_SERVICE" "$CONFLICT_B_SERVICE" >/dev/null 2>&1
start_service "$CONFLICT_A_SERVICE"
CONFLICT_A_RESTARTS_BEFORE=$(get_property "$CONFLICT_A_SERVICE" NRestarts)

echo "[>] Starting conflicting service $CONFLICT_B_SERVICE ..."
systemctl start "$CONFLICT_B_SERVICE"
sleep 2

assert_state "$CONFLICT_B_SERVICE" active
assert_state "$CONFLICT_A_SERVICE" inactive
assert_no_restart_increment "$CONFLICT_A_SERVICE" "$CONFLICT_A_RESTARTS_BEFORE"

echo "-----------------------------------------------"
echo "--- Service status ----------------------------"
echo "-----------------------------------------------"
for SERVICE in $SERVICES; do
    systemctl status "$SERVICE" --no-pager
done

echo "-----------------------------------------------"
echo "--- Journal logs ------------------------------"
echo "-----------------------------------------------"
for SERVICE in $SERVICES; do
    echo "[*] Logs for $SERVICE"
    journalctl -u "$SERVICE" --since "$TEST_START_TIME" --no-pager
done

TIMEOUT_SEC=5
echo "-----------------------------------------------"
echo "--- Capturing DLT logs for $TIMEOUT_SEC sec ---"
echo "-----------------------------------------------"
timeout "$TIMEOUT_SEC"s /bin/dlt-receive -a localhost | grep "$LOG_FILTER"

echo "-----------------------------------------------"
echo "--- Cleanup -----------------------------------"
echo "-----------------------------------------------"
for SERVICE in $SERVICES; do
    if systemctl is-active --quiet "$SERVICE"; then
        echo "[>] Stopping $SERVICE ..."
        systemctl stop "$SERVICE"
        sleep 1
    fi
done

if [ "$RESULT" -eq 0 ]; then
    echo "[PASS] Test Case 42 dependency relationship handling passed"
else
    echo "[FAIL] Test Case 42 dependency relationship handling failed"
fi

exit "$RESULT"
