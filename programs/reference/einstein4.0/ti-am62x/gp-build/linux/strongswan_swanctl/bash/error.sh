#!/bin/bash

USE_JOURNALCTL=true
LOG_CMD="journalctl -u strongswan --no-pager"

error_keywords="no_proposal_chosen|failed to authenticate|failed to decrypt|no CHILD_SA configured|peer not responding|auth_failed|bad payload|Rekey Rejection"

entries=()

remote_ip="0.0.0.0"
last_error_msg=""

# --- Month conversion ---
month_to_num() {
    case "$1" in
        Jan) echo 1 ;;
        Feb) echo 2 ;;
        Mar) echo 3 ;;
        Apr) echo 4 ;;
        May) echo 5 ;;
        Jun) echo 6 ;;
        Jul) echo 7 ;;
        Aug) echo 8 ;;
        Sep) echo 9 ;;
        Oct) echo a ;;
        Nov) echo b ;;
        Dec) echo c ;;
        *) echo 0 ;;
    esac
}

# --- Error mapping ---
get_error_code() {
    local msg="$1"
    local msg_lower
    msg_lower=$(echo "$msg" | tr 'A-Z' 'a-z')

    if [[ "$msg_lower" == *"auth_failed"* ]]; then
        echo "0x80"
    elif [[ "$msg_lower" == *"failed to authenticate"* ]]; then
        echo "0x81"
    elif [[ "$msg_lower" == *"no_proposal_chosen"* ]]; then
        if [[ "$msg_lower" == *"received"* ]]; then
            echo "0x83"
        else
            echo "0x82"
        fi
    else
        echo "0x00"
    fi
}

# --- Add entry ---
add_entry() {
    entries+=("$1|$2|$3|$4|$5|$6|$7|$8|$9")
}

# --- MAIN PARSING LOOP ---
while IFS= read -r line; do

    # Extract IPs
    if echo "$line" | grep -q "looking for peer configs matching" || \
       echo "$line" | grep -q "no IKE config found"; then

        ips_found=($(echo "$line" | grep -oE '[0-9]+\.[0-9]+\.[0-9]+\.[0-9]+'))
        if [[ ${#ips_found[@]} -ge 2 ]]; then
            remote_ip="${ips_found[1]}"
        fi
    fi

    # Detect error lines
    if echo "$line" | grep -Ei "$error_keywords" > /dev/null; then

        timestamp_raw=$(echo "$line" | awk '{print $1, $2, $3}')
        message=$(echo "$line" | sed -E 's/.*charon[^:]*: //')

        month=$(echo "$timestamp_raw" | awk '{print $1}')
        day=$(echo "$timestamp_raw" | awk '{print $2}')
        time=$(echo "$timestamp_raw" | awk '{print $3}')

        hour=$(echo "$time" | cut -d: -f1)
        minute=$(echo "$time" | cut -d: -f2)
        second=$(echo "$time" | cut -d: -f3)

        year=$(date +"%Y")

        # --- FIX: Clean + convert error code ---
        error_code=$(get_error_code "$message" | tr -d '[:space:]')
        #error_code=$((error_code_hex))   # decimal conversion

        # --- PRESENT / CLEARED (Consecutive logic) ---
        if [[ -z "$last_error_msg" ]]; then
            healed="0x01"
        elif [[ "$error_code" -eq "$last_error_msg" ]]; then
            healed="0x01"
        else
            healed="0x00"
        fi

        last_error_msg="$error_code"

        # --- Add entry ---
        add_entry \
            "$year" \
            "$month" \
            "$day" \
            "$hour" \
            "$minute" \
            "$second" \
            "$remote_ip" \
            "$error_code" \
            "$healed"
    fi

done < <($LOG_CMD)

# --- FINAL UDS OUTPUT ---
for entry in "${entries[@]}"; do
    IFS='|' read -r year month day hour minute second remote_ip code healed <<< "$entry"

    year_msb=$((year / 256))
    year_lsb=$((year % 256))
    month_num=$(month_to_num "$month")

    if [[ "$remote_ip" == "unknown" || -z "$remote_ip" ]]; then
        ip1=0; ip2=0; ip3=0; ip4=0
    else
        IFS='.' read -r ip1 ip2 ip3 ip4 <<< "$remote_ip"
    fi

    healed_val=$((healed))

    echo "$year_msb $year_lsb $month_num $day $hour $minute $second $ip1 $ip2 $ip3 $ip4 $code $healed_val"
done