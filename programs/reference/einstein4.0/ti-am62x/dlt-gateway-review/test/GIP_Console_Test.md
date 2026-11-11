# DLT Gateway - GIP standalone test from the console (no VIP, no code change)

VIP's two jobs are done from the GIP console:

| VIP job | Console replacement |
|---|---|
| write a DLT frame into its shared-memory buffer | `devmem` (or `dlt_shm_test.sh`) |
| send `DLTMessageReadRequest` (0x8900 = VMF group 137, event 0) | `vmf_sender -g 137 -e 0 ...` |
| receive `DLTMessageReadAck` (0x8A00 = VMF group 138) | `vmf_listener -g 138 ...` |

Runtime payload layout: `[senderId][msgCnt][status0][status1]`, so `-f 00000100` = status[0]=0x01, status[1]=0x00.

## 0. Check the tools
    which vmf_sender vmf_listener devmem
If `vmf_sender` / `vmf_listener` are missing, copy the prebuilt aarch64 binaries from
`cluster-platform/dijkstra/infrastructure/vmf/bin/linux_aarch64/bin/` to `/usr/bin` on the target.
Use `devmem` (mmap). `dd of=/dev/mem` is refused by the arm64 kernel for this reserved region.

## 1. Terminal 1 - DLT output
    dlt-receive -a localhost | grep -E "DLTG|GTST"

## 2. Startup ACK
    vmf_listener -g 138 -c 1          # terminal 2, start first
    systemctl restart dlt_gateway     # terminal 3
Expected in terminal 2: `GID = 138`, `EID = 0`, `Length = 8(8)`, payload ending in `0 0`
(first 4 values = VMF near data, ignore; then sender id, msg count, status[0], status[1]).

## 3. Valid frame in VIP buffer 1 (ECU VIP0, APID GTST, CTID SHMT, text "GIP TEST")
    devmem 0x82385000 32 0x21000035
    devmem 0x82385004 32 0x30504956
    devmem 0x82385008 32 0x54470141
    devmem 0x8238500C 32 0x48535453
    devmem 0x82385010 32 0x0200544D
    devmem 0x82385014 32 0x00090000
    devmem 0x82385018 32 0x20504947
    devmem 0x8238501C 32 0x54534554
    devmem 0x82385020 32 0x00000000
    devmem 0x82385000 32              # read back: 0x21000035
Or with the helper script: `./dlt_shm_test.sh write 0x82385000 "GIP TEST"`.

## 4. Read request
    vmf_listener -g 138 -c 1                              # terminal 2
    vmf_sender -g 137 -e 0 -l 4 -f 00000100 -c 1 -d 0     # terminal 3 (-c 1: default is 10)
Expected:

    DLTG ... Received DLTMessageReadRequest status= 1
    DLTG ... VIP answered the startup ready ACK - startup handshake complete   (first time only)
    VIP0 GTST SHMT log info V 1 [GIP TEST]
Terminal 2: `GID = 138`, payload ending in `1 0`.
The `VIP0 GTST SHMT` line proves the whole chain: VMF request -> gateway -> shared memory -> ACK -> TCP 5000 -> dlt-daemon.
Logstorage also writes it to `vip_log` in `/data/dlt_logs`.

## 5. More cases (restart `vmf_listener -g 138 -c 1` before each)
| Case | Commands | Expected |
|---|---|---|
| same frame again | `-f 00000100` | logged again (GIP never clears buffers, VIP does) |
| empty VIP buffer 2 | `devmem 0x82385800 32` reads 0, then `-f 00000200` | `contains no valid DLT frames — dropped`, ACK `2 0` |
| corrupt frame | `devmem 0x82385000 32 0x21000015`, then `-f 00000100` | `... dropped, error: HTYP version bits are not 001`, ACK `1 0` |
| two buffers | frame in both VIP banks, `-f 00000300` | one ACK `3 0` |
| bit not in INI | `-f 00008000` | `status bit: 7 set but no buffer has Position: 7`, ACK `80 0` |
| clear | `devmem 0x82385000 32 0` | next request finds no frame |

HSM / DM: write at 0x82387000 / 0x82388000 with the second word set to the ECU ID
(`0x2D4D5348` = "HSM-", `0x2D2D4D44` = "DM--"), request with `-f 00000800` / `-f 00002000`.

## Buffer map
| Buffer | Address | Size | Bit | Mask |
|---|---|---|---|---|
| VIP bank 1 | 0x82385000 | 2K | 0 | 0x01 |
| VIP bank 2 | 0x82385800 | 2K | 1 | 0x02 |
| VIP reset info | 0x82386000 | 4K | 2 | 0x04 |
| HSM bank 1 | 0x82387000 | 2K | 3 | 0x08 |
| HSM bank 2 | 0x82387800 | 2K | 4 | 0x10 |
| DM bank 1 | 0x82388000 | 2K | 5 | 0x20 |
| DM bank 2 | 0x82388800 | 2K | 6 | 0x40 |

## Notes
- The final code ACKs every request (echo of the request). Empty / corrupt buffers are only logged and dropped - no NACK.
- If old VIP firmware is running, `ucl_proxy_vmf` also forwards these ACKs to VIP (harmless); check the buffer with `devmem` first.
- Not covered: the UCL link itself (VMF -> ucl_proxy_vmf -> VIP). That needs VIP.
