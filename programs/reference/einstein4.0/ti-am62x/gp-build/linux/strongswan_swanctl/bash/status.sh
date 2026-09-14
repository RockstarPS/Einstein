#!/bin/bash

TMP_FILE="/tmp/swanctl_output.txt"
swanctl --list-sas > "$TMP_FILE"

ike_count=0
child_count=0

local_ip=""
remote_ip=""
spi_i=""
spi_r=""
state=""
status="FF"

declare -a child_spi_in
declare -a child_spi_out
declare -a child_proto
declare -a child_pkt_in
declare -a child_pkt_out

# -------- STATUS MAP --------

#ESTABLISHED - active - 00
#INSTALLED - already running - 02
#DELETED - error - 01

map_status() {
  case "$1" in
    ESTABLISHED) echo "00" ;;
    INSTALLED)   echo "02" ;;
    DELETED)     echo "01" ;;
    *)           echo "FF" ;;
  esac
}

# -------- PROTOCOL MAP --------
map_proto() {
  case "$1" in
    ESP) echo "03" ;;
    AH)  echo "02" ;;
    *)   echo "FF" ;;
  esac
}

# -------- PARSE --------
while IFS= read -r line; do

  # ---- IKE line ----
  if [[ "$line" =~ IKEv2 ]]; then
    ((ike_count++))

    # Extract SPI safely
    spi_i=$(echo "$line" | grep -oE '[0-9a-f]{16}' | head -1)
    spi_r=$(echo "$line" | grep -oE '[0-9a-f]{16}' | head -2 | tail -1)

    state=$(echo "$line" | awk '{print $3}' | tr -d ',')

  # ---- LOCAL IP ----
  elif [[ "$line" == *"local "* ]]; then
    local_ip=$(echo "$line" | grep -oE '[0-9]+\.[0-9]+\.[0-9]+\.[0-9]+')

  # ---- REMOTE IP ----
  elif [[ "$line" == *"remote "* ]]; then
    remote_ip=$(echo "$line" | grep -oE '[0-9]+\.[0-9]+\.[0-9]+\.[0-9]+')

  # CHILD Header -> ESP/AH
  elif [[ "$line" =~ ESP:|AH: ]]; then
    proto=$(echo "$line" | grep -oE 'ESP|AH' | head -1)
    child_proto[$child_count]=$(map_proto "$proto")

  # ---- CHILD IN ----
  elif [[ "$line" =~ ^[[:space:]]*in[[:space:]] ]]; then
    spi=$(echo "$line" | grep -oE '[0-9a-f]{8,16}' | head -1)
    pkts=$(echo "$line" | grep -oE 'packets[[:space:]]+[0-9]+' | awk '{print $2}')

    child_spi_in[$child_count]=$spi
    child_pkt_in[$child_count]=${pkts:-0}

  # CHILD OUT
  elif [[ "$line" =~ ^[[:space:]]*out[[:space:]] ]]; then
    spi=$(echo "$line" | grep -oE '[0-9a-f]{8,16}' | head -1)
    pkts=$(echo "$line" | grep -oE 'packets[[:space:]]+[0-9]+' | awk '{print $2}')

    child_spi_out[$child_count]=$spi
    child_pkt_out[$child_count]=${pkts:-0}

    ((child_count++))
  fi

done < "$TMP_FILE"

# -------- OUTPUT --------

# Local IPsec Status
if systemctl is-active --quiet strongswan; then
  status="00"
else
  status="01"
fi

echo "$status"

# Number of Entries
echo "$ike_count"

# Peer IP Address (Remote IP)
IFS='.' read -r r1 r2 r3 r4 <<< "$remote_ip"
echo "${r1:-0}"
echo "${r2:-0}"
echo "${r3:-0}"
echo "${r4:-0}"

# Initiator SPI (2 bytes)
spi_i_last=${spi_i: -4}
echo "${spi_i_last:0:2}"
echo "${spi_i_last:2:2}"

# Responder SPI (2 bytes)
spi_r_last=${spi_r: -4}
echo "${spi_r_last:0:2}"
echo "${spi_r_last:2:2}"

# ---- STATUS ----
map_status "$state"

# ---- CHILD COUNT ----
echo "$child_count"

# ---- CHILD DATA ----
for ((i=0; i<child_count; i++)); do

  spi_in=${child_spi_in[$i]:-00000000}
  spi_out=${child_spi_out[$i]:-00000000}

  spi_in_last=${spi_in: -4}
  spi_out_last=${spi_out: -4}

  # Inbound SPI
  echo "${spi_in_last:0:2}"
  echo "${spi_in_last:2:2}"

  # Outbound SPI
  echo "${spi_out_last:0:2}"
  echo "${spi_out_last:2:2}"

  # Protocol
  echo "${child_proto[$i]:-FF}"

  # Packets In (4 bytes)
  pkt_in=${child_pkt_in[$i]:-0}
  printf "%02X\n" $(( (pkt_in >> 24) & 0xFF ))
  printf "%02X\n" $(( (pkt_in >> 16) & 0xFF ))
  printf "%02X\n" $(( (pkt_in >> 8) & 0xFF ))
  printf "%02X\n" $(( pkt_in & 0xFF ))

  # Packets Out (4 bytes)
  pkt_out=${child_pkt_out[$i]:-0}
  printf "%02X\n" $(( (pkt_out >> 24) & 0xFF ))
  printf "%02X\n" $(( (pkt_out >> 16) & 0xFF ))
  printf "%02X\n" $(( (pkt_out >> 8) & 0xFF ))
  printf "%02X\n" $(( pkt_out & 0xFF ))

  # Packets placeholders
  echo "00"
  echo "00"
  echo "00"
  echo "00"

done