#!/bin/bash

if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <third_octet> <hex_bitmask>"
    echo "Example: $0 199 0x1000000000000000000010000"
    exit 1
fi

first_two_octets="160.48"

third_octet="$1"
hex_input="$2"

# Cleanup hex input
hex_input="${hex_input,,}"
hex_input="${hex_input/#0x/}"

# Reverse hex string
reverse_string() {
    local input="$1"
    local reversed=""
    for ((i=${#input}-1; i>=0; i--)); do
        reversed="${reversed}${input:$i:1}"
    done
    echo "$reversed"
}

reversed_hex=$(reverse_string "$hex_input")

# Hex to 4-bit binary
declare -A hex2bin=(
    [0]="0000" [1]="0001" [2]="0010" [3]="0011"
    [4]="0100" [5]="0101" [6]="0110" [7]="0111"
    [8]="1000" [9]="1001" [a]="1010" [b]="1011"
    [c]="1100" [d]="1101" [e]="1110" [f]="1111"
)

# --- Extract octets to add ---
add_octets=()
bit_index=0
for ((i=0; i<${#reversed_hex}; i++)); do
    hex_char="${reversed_hex:$i:1}"
    bin="${hex2bin[$hex_char]}"
    if [ -z "$bin" ]; then
        echo "Invalid hex digit: $hex_char"
        exit 1
    fi
    for ((j=3; j>=0; j--)); do
        bit="${bin:$j:1}"
        if [[ "$bit" == "1" ]]; then
            add_octets+=("$bit_index")
        fi
        ((bit_index++))
    done
done

echo "IPs to ADD into neversecure: ${add_octets[@]/#/$third_octet.}"

# FILE LOCATION
SWANCTL_CONF="/etc/swanctl/swanctl_org.conf"
TMP_CONF="/persist/swanctl_tmp.conf"
BACKUP_CONF="/persist/swanctl.conf.bak"

cp "$SWANCTL_CONF" "$BACKUP_CONF" || { echo "? Backup failed!"; exit 1; }
> "$TMP_CONF"

inside_neversecure=0
brace_depth=0
remote_ts_updated=0
local_ts_updated=0

local_addrs_list=()

while IFS= read -r line; do
    if [[ "$line" =~ local_addrs[[:blank:]]*=[[:blank:]]*(.*) ]]; then
        value="${BASH_REMATCH[1]}"
        IFS=',' read -ra arr <<< "$value"
        for ip in "${arr[@]}"; do
            local_addrs_list+=("$(echo "$ip" | xargs)")
        done
    fi
done < "$SWANCTL_CONF"

while IFS= read -r line || [[ -n "$line" ]]; do
    # Detect neversecure block start
    if [[ "$line" =~ neversecure_traffic ]]; then
        inside_neversecure=1
        brace_depth=0
    fi
    # Track brace depth only inside block
    if [[ "$inside_neversecure" -eq 1 ]]; then
        open_braces=$(grep -o "{" <<< "$line" | wc -l)
        close_braces=$(grep -o "}" <<< "$line" | wc -l)
        ((brace_depth += open_braces))
        ((brace_depth -= close_braces))
        if [[ $brace_depth -eq 0 ]]; then
            inside_neversecure=0
        fi
    fi

    # Function to update a TS line (local_ts and remote_ts)
    update_ts_line() {
        local indent="$1"
        local existing="$2"
        local ts_type="$3"
        shift 3
        local new_ips=("$@")

        IFS=',' read -ra ip_array <<< "$existing"
        cleaned_existing=()
        for ip in "${ip_array[@]}"; do
            cleaned_existing+=("$(echo "$ip" | xargs)")
        done

        for ip in "${new_ips[@]}"; do
            ip_bypass="$ip/32[tcp]"
            found=0
            for existing_ip in "${cleaned_existing[@]}"; do
                if [[ "$existing_ip" == "$ip" || "$existing_ip" == "$ip_bypass" ]]; then
                    found=1
                    break
                fi
            done
            if [[ $found -eq 0 ]]; then
                cleaned_existing+=("$ip_bypass")
            fi
        done

        # Format line
        new_line="${indent}${ts_type} = "
        for ((i=0; i<${#cleaned_existing[@]}; i++)); do
            if [[ $i -eq 0 ]]; then
                new_line+="${cleaned_existing[$i]}"
            else
                new_line+=", ${cleaned_existing[$i]}"
            fi
        done
        echo "$new_line"
    }

    # Update remote_ts
    if [[ "$inside_neversecure" -eq 1 && "$remote_ts_updated" -eq 0 && "$line" =~ ^([[:blank:]]*)remote_ts[[:blank:]]*= ]]; then
        indent="${BASH_REMATCH[1]}"
        existing=$(echo "$line" | sed -E 's/.*=\s*//')
        new_line=$(update_ts_line "$indent" "$existing" "remote_ts" "${add_octets[@]/#/$first_two_octets.$third_octet.}")
        echo "$new_line" >> "$TMP_CONF"
        remote_ts_updated=1
        continue
    fi

    # Update local_ts
    if [[ "$inside_neversecure" -eq 1 && "$local_ts_updated" -eq 0 && "$line" =~ ^([[:blank:]]*)local_ts[[:blank:]]*= ]]; then
        indent="${BASH_REMATCH[1]}"
        existing=$(echo "$line" | sed -E 's/.*=\s*//')
        new_line=$(update_ts_line "$indent" "$existing" "local_ts" "${local_addrs_list[@]}")
        echo "$new_line" >> "$TMP_CONF"
        local_ts_updated=1
        continue
    fi

    # Default: copy line
    echo "$line" >> "$TMP_CONF"
done < "$SWANCTL_CONF"

# compare line counts
original_lines=$(wc -l < "$SWANCTL_CONF")
new_lines=$(wc -l < "$TMP_CONF")

echo "Original lines: $original_lines"
echo "New lines:      $new_lines"

# Syntax check before apply
if swanctl --load-conns --file "$TMP_CONF" &>/dev/null; then
    echo "Configuration updated and validated."
else
    echo "ERROR: Config syntax invalid! Restoring original."
    ln -s "$BACKUP_CONF" "$SWANCTL_CONF"
    rm -f "$TMP_CONF"
    exit 1
fi