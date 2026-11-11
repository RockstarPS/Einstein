# DLT Gateway (GIP) - review chat summary

Summary of the review / design chat for the GIP DLT gateway
(`programs/reference/einstein4.0/ti-am62x/dlt-gateway`).

## Folder contents

| Path | What |
|---|---|
| `DLT_Gateway_Chat.md` | this summary |
| `dlt-gateway/` | final gateway code (your final version) with comments cleaned up + cleaned `cfg/dlt_gw.ini` |
| `test/GIP_Console_Test.md` | how to test GIP standalone from the console (no VIP, no code change) |
| `test/dlt_shm_test.sh` | optional console helper that writes DLT frames into shared memory with `devmem` |
| `patches/comments_cleanup.patch` | comment-only diff: final code -> cleaned code |
| `patches/final_vs_46ff2293a.patch` | full diff: original gateway (46ff2293a) -> cleaned final code |

This folder is not part of the build. To use the code, copy `dlt-gateway/` over
`programs/reference/einstein4.0/ti-am62x/dlt-gateway/` and `dlt-gateway/cfg/dlt_gw.ini` to
`gp-build/linux/prebuilt_common/etc/dlt_gw.ini`.

---

## 1. How the system works

1. VIP, HSM and DM write DLT log frames into shared DDR memory (0x82385000 - 0x82388FFF).
2. VIP sends the UCL message `DLTMessageReadRequest` (0x8900). `status[0]` is a bit mask of the buffers to read.
3. GIP (`dlt_gateway`) reads those buffers, then answers with `DLTMessageReadAck` (0x8A00).
4. VIP clears the buffers after the ACK.
5. The dispatch thread validates the frames and sends them over TCP (ports 5000/5001/5002) to `dlt-daemon`,
   which runs in gateway mode (`GatewayMode=1`, passive nodes VIP0 / HSM- / DM--) and stores them with logstorage.

New requirement (`DLT_VipDMHsmIPC_1.pdf`):
- GIP sends a startup ("DLT ready") ACK first.
- For every read request GIP processes the frames and sends an ACK.
- On failure GIP logs a BufferError and sends a NACK. VIP handles ACK and NACK the same way.

## 2. Why the original code sent no ACK

Two problems in the original gateway (46ff2293a), proven with a repro:
1. **Crash with the image INI:** the INI in the image was missing keys; `getStringValue()` returned NULL and was
   assigned to `std::string` -> crash at start-up.
2. **Blocking `accept()` in `onStart()`:** `coreInitialization()` waited for dlt-daemon to connect. With
   `GatewayMode=0` it never connects, so `onStart()` never returned, the runtime message pump never started and
   no request was ever handled.

Fixing only the status bytes would not have helped. No message-ID or routing mix-up was found.

## 3. Changes committed earlier on this branch (gateway in the repo tree)

- Startup ACK from `worker()`; read ACK/NACK after the buffers are read (`status[0]` = mask echo, `status[1]` = ACK 0x01 / NACK 0x00).
- `readShmBuffer()` returns `bool`: validates with `scanBuffer()` before the ACK and logs `BufferError`.
- NULL-safe INI reading, no blocking `connectClient()` at start-up, INI in the image synced,
  `dlt_gateway.service` ordered after `ucl_proxy_vmf.service`.
- A byte swap (ACK/NACK in `status[0]`) was added and then reverted at your request ("keep it as old").

## 4. Decisions taken in the chat

- Keep the ACK byte layout as old: `status[0]` = buffer mask.
- No dlt-daemon config changes.
- VIP only grows the payload; standard + extended header stay. The gateway does not check the payload: as long as
  `LEN` is correct, a bigger payload is fine.
- Startup ACK uses the default status (0x00) and is sent once (`StartupAckMaxRetries = 1`), because VIP cannot
  tell a repeat from a buffer ACK.

## 5. DLT frame format (as the gateway checks it)

- Standard header: HTYP, MCNT, LEN (big-endian, whole frame), optional ECU ID / session ID / timestamp.
- Extended header (10 bytes, required by the validator): MSIN, NOAR, APID, CTID.
- Then the verbose or non-verbose payload.
- Validator checks: version = 1, LEN, header size, extended header present, NOAR != 0 when verbose, MSTP <= 3.
- VIP frame: HTYP 0x3D, 26-byte header, ECU `CI4E`, type info 0x400, fault code in bytes 30-31.
- dlt-daemon gateway: the frame's ECU ID must match the passive node's `EcuID`, otherwise it is not routed.

## 6. Your code vs my branch

- Build error ("stray '@'" in `dlt_gateway_types.h`): a missing `/**` before `@brief Identifies the physical transport`. Fixed.
- Your design: `startupAckLoop()` thread, non-blocking listen socket, start-up fails unless all cores are ready.
- Difference to the requirement PDF: your code always ACKs (echo of the request) and validates frames only later
  in the dispatch thread, so there is no NACK path. I delivered a 4-file change adding it; your final code
  does not include it (see section 9).

## 7. Memory map check (`Einstein_4.0_Platform_IntVip_MemoryLayout.xlsx`)

| Buffer | Address | Size | Bit | Mask |
|---|---|---|---|---|
| VIP bank 1 | 0x82385000 | 2K | 0 | 0x01 |
| VIP bank 2 | 0x82385800 | 2K | 1 | 0x02 |
| VIP reset info | 0x82386000 | 4K | 2 | 0x04 |
| HSM bank 1 | 0x82387000 | 2K | 3 | 0x08 |
| HSM bank 2 | 0x82387800 | 2K | 4 | 0x10 |
| DM bank 1 | 0x82388000 | 2K | 5 | 0x20 |
| DM bank 2 | 0x82388800 | 2K | 6 | 0x40 |

- Matches the "DDR Layout Linux" sheet, the VIP and DM linker scripts and `dlt_gw.ini` exactly.
- The R5 MPU config (`ti_dpl_config.c`) maps 0x82380000 / 512K non-cacheable and shared - correct for shared buffers.
- To fix in the spreadsheet (no code impact): the "Platform Memory Layout" sheet lists `DDR_DATA_SHDMEM_DLT` at
  0x82585000 (inside SWUPD, stale - should be 0x82385000), and the MPU-MCU R5F sheet has no row for 0x8238xxxx.

## 8. Board test log analysis

- INI parsed, all 7 buffers at the right addresses, 3 cores started, startup ACK sent once at ~4.7 s after boot.
- No `Received DLTMessageReadRequest` afterwards: VIP never sent a request.
- Likely cause: the single startup ACK went out before `ucl_proxy_vmf` / the VIP link was up
  (`dlt_gateway.service` is not ordered after `ucl_proxy_vmf.service`), so VIP never started.
- Check: `journalctl -b -o short-monotonic -u ucl_proxy_vmf -u dlt_gateway`, then `systemctl restart dlt_gateway`.
- Fix options: add `ucl_proxy_vmf.service` to `After=` / `Wants=` of `dlt_gateway.service`
  (keeps `StartupAckMaxRetries = 1`).

## 9. Final code (your version) - behaviour

- Startup ACK: `{0x00, 0x00}`, sent once by `startupAckLoop()`.
- Read request: buffers copied in `readShmBuffer()`, then ACK = echo of the request (`status[0]`, `status[1]`).
- Empty / corrupt buffers: logged and dropped in the dispatch thread (`contains no valid DLT frames — dropped`); no NACK.
- dlt-daemon link: non-blocking listener, one `accept()` attempt per dispatch pass (`tryConnectTcpClient()`).
- Start-up fails (no DLT ready announced) unless all cores are initialised.
- `ReconnectIntervalMS` / `ReconnectMaxRetries` are still parsed but no longer used (`mReconnectPolicy` is unused).

## 10. INI review

- All keys the code reads are present; addresses match the memory map; each core window covers its buffers.
- Cleaned: decorative header, repeated per-key comments, commented-out UART/SPI blocks and per-buffer comments removed.
- Kept: `; -1 = retry indefinitely`, `; Keep 1: VIP cannot tell a repeated startup ACK from a buffer ACK`,
  `; Position = bit in DLTMessageReadRequest status[0]`.
- Parsed with the real INI parser: identical configuration before and after.

## 11. Comment clean-up of the source

Only comments added on top of the original code were shortened or removed; original comments untouched.
Verified by stripping comments: the code is token-identical to your final version in all 11 files.

| File | Change |
|---|---|
| `include/dlt_gateway_types.h` | 23-line block on `DLT_GW_STARTUP_ACK_STATUS` -> 1 line; 2 member comments shortened |
| `include/dlt_gateway_component.h` | 5 detached doc blocks removed; one-line `@brief` on the new members / functions |
| `src/dlt_gateway_component.cpp` | multi-line explanations -> one-liners; comments repeating the log text removed |
| `src/dlt_gateway_tcp_server.cpp` | non-blocking comments shortened; stale "ReconnectPolicy" comment fixed |

## 12. Standalone testing on GIP

See `test/GIP_Console_Test.md`: `devmem` writes a DLT frame, `vmf_sender -g 137` sends the read request,
`vmf_listener -g 138` shows the ACK, `dlt-receive` shows the frame coming out of dlt-daemon. No code change needed.

## 13. Open points

- No NACK path in the final code (requirement PDF expects BufferError + NACK).
- `dlt_gateway.service` should start after `ucl_proxy_vmf.service`, because the single startup ACK can be lost.
- VIP reads the ACK in its 10 ms cycle with an RTE read that always returns OK, so it may clear a buffer before
  GIP has read it.
- VIP RTE models `status` as 1 byte while UCL carries 2: only `status[0]` reaches VIP.
- Spreadsheet: stale `DDR_DATA_SHDMEM_DLT` (0x82585000) row, missing MPU row.
