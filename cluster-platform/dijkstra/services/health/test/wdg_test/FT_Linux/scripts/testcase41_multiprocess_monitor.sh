#!/bin/sh

PARENT_SERVICE="test_19_1.service"
PARTOF_SERVICE="test_19_4.service"
SERVICES="$PARTOF_SERVICE $PARENT_SERVICE"
RESULT=0

echo "------------------------------------------------------------------"
echo "----- Test Case 41 - PartOf dependency handling -------------------"
echo ""
echo "Expected behavior:"
echo "    $PARTOF_SERVICE has PartOf=$PARENT_SERVICE"
echo "    Stopping $PARENT_SERVICE also stops $PARTOF_SERVICE"
echo "    $PARTOF_SERVICE does not restart during dependency-driven stop"
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
echo "--- Verifying PartOf configuration ------------"
echo "-----------------------------------------------"

PARTOF_VALUE=$(get_property "$PARTOF_SERVICE" PartOf)
echo "[*] $PARTOF_SERVICE PartOf=$PARTOF_VALUE"

if contains_unit "$PARTOF_VALUE" "$PARENT_SERVICE"; then
    echo "[+] $PARTOF_SERVICE has PartOf dependency on $PARENT_SERVICE"
else
    fail_test "$PARTOF_SERVICE missing PartOf dependency on $PARENT_SERVICE"
fi

echo "-----------------------------------------------"
echo "--- PartOf stop propagation -------------------"
echo "-----------------------------------------------"

start_service "$PARENT_SERVICE"
start_service "$PARTOF_SERVICE"

assert_state "$PARENT_SERVICE" active
assert_state "$PARTOF_SERVICE" active

PARTOF_RESTARTS_BEFORE=$(get_property "$PARTOF_SERVICE" NRestarts)

echo "[>] Stopping parent service $PARENT_SERVICE ..."
systemctl stop "$PARENT_SERVICE"
sleep 2

assert_state "$PARENT_SERVICE" inactive
assert_state "$PARTOF_SERVICE" inactive

PARTOF_RESTARTS_AFTER=$(get_property "$PARTOF_SERVICE" NRestarts)
echo "[*] $PARTOF_SERVICE NRestarts before=$PARTOF_RESTARTS_BEFORE after=$PARTOF_RESTARTS_AFTER"

if [ "$PARTOF_RESTARTS_BEFORE" = "$PARTOF_RESTARTS_AFTER" ]; then
    echo "[+] $PARTOF_SERVICE did not restart"
else
    fail_test "$PARTOF_SERVICE restarted unexpectedly"
fi

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
    echo "[PASS] Test Case 41 PartOf dependency handling passed"
else
    echo "[FAIL] Test Case 41 PartOf dependency handling failed"
fi

exit "$RESULT"
