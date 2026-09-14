#!/bin/bash

SWANCTL_CONF="/etc/swanctl/swanctl.conf"

inside_neversecure=0
brace_depth=0

declare -A octet_map
third_octet=""

while IFS= read -r line || [[ -n "$line" ]]; do

    if [[ "$line" =~ neversecure_traffic ]]; then
        inside_neversecure=1
        brace_depth=0
    fi

    if [[ "$inside_neversecure" -eq 1 ]]; then
        open_braces=$(grep -o "{" <<< "$line" | wc -l)
        close_braces=$(grep -o "}" <<< "$line" | wc -l)

        ((brace_depth += open_braces))
        ((brace_depth -= close_braces))

        if [[ $brace_depth -eq 0 ]]; then
            inside_neversecure=0
        fi
    fi

    if [[ "$inside_neversecure" -eq 1 && "$line" =~ remote_ts ]]; then

        ips=$(echo "$line" | sed -E 's/.*=\s*//' | xargs)
        IFS=',' read -ra ip_array <<< "$ips"

        for ip in "${ip_array[@]}"; do
            ip_clean=$(echo "$ip" | xargs)

            if [[ "$ip_clean" =~ ^160\.48\.([0-9]+)\.([0-9]+)(/32(\[[^]]+\]|:any)?)?$ ]]; then
                third_octet="${BASH_REMATCH[1]}"
                last_octet="${BASH_REMATCH[2]}"
                octet_map["$last_octet"]=1
            fi
        done
    fi

done < "$SWANCTL_CONF"

# Build bitmask
max_bit=0
for key in "${!octet_map[@]}"; do
    (( key > max_bit )) && max_bit=$key
done

((size = (max_bit / 4 + 1) * 4))

bit_array=()
for ((i=0; i<size; i++)); do
    if [[ -n "${octet_map[$i]}" ]]; then
        bit_array[i]=1
    else
        bit_array[i]=0
    fi
done

hex=""
for ((i=0; i<size; i+=4)); do
    nibble="${bit_array[i+3]}${bit_array[i+2]}${bit_array[i+1]}${bit_array[i]}"
    case "$nibble" in
        0000) d=0 ;;
        0001) d=1 ;;
        0010) d=2 ;;
        0011) d=3 ;;
        0100) d=4 ;;
        0101) d=5 ;;
        0110) d=6 ;;
        0111) d=7 ;;
        1000) d=8 ;;
        1001) d=9 ;;
        1010) d=a ;;
        1011) d=b ;;
        1100) d=c ;;
        1101) d=d ;;
        1110) d=e ;;
        1111) d=f ;;
    esac
    hex="$d$hex"
done

echo "$third_octet 0x$hex"