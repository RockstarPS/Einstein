#!/bin/sh
# GIP standalone DLT gateway test - plays the VIP/HSM/DM side on the GIP console.
#   write   <addr> [text]   write one valid verbose DLT log frame into the buffer
#   corrupt <addr>          write a frame with a broken header (DLT version 0)
#   clear   <addr> [size]   zero the buffer (default 2048 bytes)
#   dump    <addr> [bytes]  hex dump of the buffer (default 64 bytes)
# The ECU ID is picked from the address so dlt-daemon routes it to the matching
# passive node (dlt_gateway.conf): VIP0, HSM-, DM--.
# Uses busybox "devmem" (or "devmem2"): it mmaps /dev/mem, plain dd on /dev/mem
# is refused by the arm64 kernel for reserved memory.

usage() { sed -n '2,10p' "$0"; exit 1; }

mem_wr() { # addr value32
    if command -v devmem >/dev/null 2>&1; then devmem "$1" 32 "$2"
    elif command -v devmem2 >/dev/null 2>&1; then devmem2 "$1" w "$2" >/dev/null
    else echo "devmem / devmem2 not found"; exit 1; fi
}
mem_rd() { # addr -> 0xXXXXXXXX
    if command -v devmem >/dev/null 2>&1; then devmem "$1" 32
    elif command -v devmem2 >/dev/null 2>&1; then devmem2 "$1" w | awk 'END{print $NF}'
    else echo "devmem / devmem2 not found"; exit 1; fi
}
to_hex() { printf '%s' "$1" | od -An -tx1 -v | tr -d ' \n'; }

# Write a hex byte string to memory in memory order, 32-bit little-endian words
write_hex() { # addr hexstring
    a=$(($1)); hex=$2
    while [ $(( ${#hex} % 8 )) -ne 0 ]; do hex="${hex}00"; done
    while [ -n "$hex" ]; do
        rest=${hex#????????}; w=${hex%"$rest"}; hex=$rest
        r=${w#??}; b0=${w%"$r"}; w=$r
        r=${w#??}; b1=${w%"$r"}; w=$r
        r=${w#??}; b2=${w%"$r"}; b3=$r
        mem_wr "$(printf '0x%08x' $a)" "0x$b3$b2$b1$b0"
        a=$((a + 4))
    done
}

ecu_for() {
    a=$(($1))
    if   [ $a -ge $((0x82385000)) ] && [ $a -lt $((0x82387000)) ]; then echo VIP0
    elif [ $a -ge $((0x82387000)) ] && [ $a -lt $((0x82388000)) ]; then echo HSM-
    elif [ $a -ge $((0x82388000)) ] && [ $a -lt $((0x82389000)) ]; then echo DM--
    else echo "address $1 is outside the DLT shared memory 0x82385000-0x82388FFF" >&2; exit 1; fi
}

frame_hex() { # htyp ecu text
    txt=$3; n=${#txt}
    [ $n -le 200 ] || { echo "text too long (max 200)" >&2; exit 1; }
    len=$((25 + n))      # std hdr 4 + ECU 4 + ext hdr 10 + type info 4 + str len 2 + text + NUL
    printf '%s00%04x' "$1" $len                     # HTYP, MCNT, LEN (big-endian)
    to_hex "$2"                                     # ECU ID
    printf '4101'                                   # MSIN: verbose log info, NOAR = 1
    to_hex "GTST"; to_hex "SHMT"                    # APID, CTID
    printf '00020000'                               # type info: string
    printf '%02x00' $((n + 1))                      # string length incl. NUL (little-endian)
    to_hex "$txt"; printf '00'
}

[ $# -ge 2 ] || usage
cmd=$1; addr=$2
case "$cmd" in
    write)
        ecu=$(ecu_for "$addr") || exit 1
        text=${3:-"GIP standalone test $(date +%T)"}
        write_hex "$addr" "$(frame_hex 35 "$ecu" "$text")"
        echo "wrote frame ECU=$ecu APID=GTST CTID=SHMT text=\"$text\" at $addr" ;;
    corrupt)
        ecu=$(ecu_for "$addr") || exit 1
        write_hex "$addr" "$(frame_hex 15 "$ecu" "corrupt frame")"   # HTYP 0x15 -> DLT version 0
        echo "wrote corrupt frame (DLT version 0) at $addr" ;;
    clear)
        size=${3:-2048}; a=$(($addr)); end=$((a + size))
        while [ $a -lt $end ]; do mem_wr "$(printf '0x%08x' $a)" 0; a=$((a + 4)); done
        echo "cleared $size bytes at $addr" ;;
    dump)
        cnt=${3:-64}; a=$(($addr)); end=$((a + cnt))
        while [ $a -lt $end ]; do
            ls=$a; line=""
            while [ $a -lt $end ] && [ $((a - ls)) -lt 16 ]; do
                v=$(($(mem_rd "$(printf '0x%08x' $a)")))
                line="$line$(printf '%02x %02x %02x %02x ' $((v & 255)) $(((v >> 8) & 255)) $(((v >> 16) & 255)) $(((v >> 24) & 255)))"
                a=$((a + 4))
            done
            printf '%08x: %s\n' $ls "$line"
        done ;;
    *) usage ;;
esac
