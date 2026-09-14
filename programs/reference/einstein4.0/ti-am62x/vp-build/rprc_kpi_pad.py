#!/usr/bin/env python3
"""Pad a TI RPRC image with one synthetic loadable segment for KPI builds."""

# Flow reference:
#   vp_platform.cmake
#       -> TI elf2rprc.js generates <image>.rprc from <image>.out
#       -> this script opens the generated RPRC and checks its current size
#       -> if the RPRC is smaller than the KPI target, one aligned synthetic
#          loadable section is appended inside the configured DDR code window
#       -> the updated RPRC is written back in place
#       -> TI multicoreImageGen and signing continue unchanged
#
# PlantUML reference:
#   start
#   :Read generated RPRC;
#   if (Current size >= target?) then (yes)
#     :Warn/skip padding;
#   else (no)
#     :Compute missing bytes;
#     :Find highest existing load address;
#     :Place aligned padding section below VP_KPI_IMAGE_PAD_MAX_END_ADDR;
#     :Rewrite RPRC with synthetic section;
#     :Warn if remaining padding budget is low;
#   endif
#   stop

from __future__ import annotations

import argparse
import struct
import sys
from pathlib import Path


RPRC_HEADER_FORMAT = "<4sIIII"
RPRC_SECTION_HEADER_FORMAT = "<IIIII"
RPRC_HEADER_SIZE = struct.calcsize(RPRC_HEADER_FORMAT)
RPRC_SECTION_HEADER_SIZE = struct.calcsize(RPRC_SECTION_HEADER_FORMAT)
PAD_ALIGNMENT = 0x1000


def roundup4(value: int) -> int:
    return (value + 3) & ~0x3


def align_up(value: int, align: int) -> int:
    return ((value + align - 1) // align) * align


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Pad an RPRC image towards a target size for KPI measurements."
    )
    parser.add_argument("rprc_file", help="Path to the RPRC file to update")
    parser.add_argument(
        "--target-size",
        required=True,
        type=lambda value: int(value, 0),
        help="Approximate target RPRC size in bytes",
    )
    parser.add_argument(
        "--pad-max-end-addr",
        required=True,
        type=lambda value: int(value, 0),
        help="Exclusive upper load address reserved for the padding segment",
    )
    parser.add_argument(
        "--pad-fill-byte",
        default="0xA5",
        type=lambda value: int(value, 0),
        help="Fill byte value for the padding segment",
    )
    parser.add_argument(
        "--warn-remaining-pad-bytes",
        default="0",
        type=lambda value: int(value, 0),
        help="Warn when the remaining KPI padding budget drops below this number of bytes",
    )
    return parser.parse_args()


def warn(message: str) -> None:
    print(f"WARNING: {message}", file=sys.stderr)


def read_rprc(path: Path) -> tuple[tuple[int, int, int], list[dict[str, object]]]:
    data = path.read_bytes()

    if len(data) < RPRC_HEADER_SIZE:
        raise ValueError(f"{path} is too small to be a valid RPRC image")

    magic, entry, reserved, section_count, version = struct.unpack_from(
        RPRC_HEADER_FORMAT, data, 0
    )

    if magic != b"RPRC":
        raise ValueError(f"{path} does not contain a valid RPRC header")

    offset = RPRC_HEADER_SIZE
    sections: list[dict[str, object]] = []

    # Walk the serialized RPRC image once and keep each loadable section so we can
    # append one extra KPI padding section later without changing the original data.
    for _ in range(section_count):
        if offset + RPRC_SECTION_HEADER_SIZE > len(data):
            raise ValueError(f"{path} has a truncated section header")

        addr, sec_reserved0, size, sec_reserved1, sec_reserved2 = struct.unpack_from(
            RPRC_SECTION_HEADER_FORMAT, data, offset
        )
        offset += RPRC_SECTION_HEADER_SIZE

        if offset + size > len(data):
            raise ValueError(f"{path} has a truncated section payload")

        section_data = data[offset : offset + size]
        offset += size

        sections.append(
            {
                "addr": addr,
                "reserved0": sec_reserved0,
                "size": size,
                "reserved1": sec_reserved1,
                "reserved2": sec_reserved2,
                "data": section_data,
            }
        )

    return (entry, reserved, version), sections


def write_rprc(
    path: Path, header: tuple[int, int, int], sections: list[dict[str, object]]
) -> None:
    entry, reserved, version = header
    output = bytearray()

    output.extend(
        struct.pack(
            RPRC_HEADER_FORMAT, b"RPRC", entry, reserved, len(sections), version
        )
    )

    # Rebuild the full RPRC with the updated section count and the original
    # sections in address order, plus the synthetic KPI padding section.
    for section in sections:
        output.extend(
            struct.pack(
                RPRC_SECTION_HEADER_FORMAT,
                int(section["addr"]),
                int(section["reserved0"]),
                int(section["size"]),
                int(section["reserved1"]),
                int(section["reserved2"]),
            )
        )
        output.extend(section["data"])

    path.write_bytes(output)


def main() -> int:
    args = parse_args()
    rprc_path = Path(args.rprc_file)

    if not rprc_path.is_file():
        raise FileNotFoundError(f"RPRC file not found: {rprc_path}")

    if not 0 <= args.pad_fill_byte <= 0xFF:
        raise ValueError(f"Invalid --pad-fill-byte value: {args.pad_fill_byte}")
    if args.warn_remaining_pad_bytes < 0:
        raise ValueError(
            f"Invalid --warn-remaining-pad-bytes value: {args.warn_remaining_pad_bytes}"
        )

    header, sections = read_rprc(rprc_path)
    current_size = rprc_path.stat().st_size

    if current_size >= args.target_size:
        warn(
            "KPI target already reached by real software content. "
            "The final image will now grow naturally unless the target is increased."
        )
        print(
            f"KPI image padding skipped: current RPRC size {current_size} bytes already meets target {args.target_size} bytes"
        )
        return 0

    # The target is applied on the RPRC artifact itself. Any missing bytes are
    # turned into one aligned loadable section so the downstream TI image tools
    # keep carrying the extra payload into the final signed hs_fs image.
    missing_bytes = roundup4(args.target_size - current_size)
    highest_addr_end = 0

    for section in sections:
        section_end = int(section["addr"]) + int(section["size"])

        if (section_end <= args.pad_max_end_addr) and (section_end > highest_addr_end):
            highest_addr_end = section_end

    # Place the padding immediately after the highest existing loadable section
    # inside the configured DDR window, aligned to a 4 KB boundary.
    pad_start_addr = align_up(highest_addr_end, PAD_ALIGNMENT)
    pad_end_addr = pad_start_addr + missing_bytes

    if pad_end_addr > args.pad_max_end_addr:
        raise ValueError(
            "KPI image padding exceeds configured address window: "
            f"start=0x{pad_start_addr:08X} end=0x{pad_end_addr:08X} "
            f"limit=0x{args.pad_max_end_addr:08X}"
        )

    # The synthetic section contains only a known fill pattern. It is not used
    # by software logic; it exists only to stabilize KPI image size.
    sections.append(
        {
            "addr": pad_start_addr,
            "reserved0": 0,
            "size": missing_bytes,
            "reserved1": 0,
            "reserved2": 0,
            "data": bytes([args.pad_fill_byte]) * missing_bytes,
        }
    )
    sections.sort(key=lambda section: int(section["addr"]))

    # Persist the updated RPRC so the normal TI multicore-image and signing flow
    # can continue without any other build changes.
    write_rprc(rprc_path, header, sections)

    if (args.warn_remaining_pad_bytes > 0) and (
        missing_bytes <= args.warn_remaining_pad_bytes
    ):
        warn(
            "Remaining KPI padding budget is low "
            f"({missing_bytes} bytes <= {args.warn_remaining_pad_bytes} bytes). "
            "Please review the KPI target before further software growth."
        )

    print(
        f"KPI image padding enabled: added {missing_bytes} bytes at "
        f"0x{pad_start_addr:08X} to target {args.target_size} bytes"
    )
    return 0


if __name__ == "__main__":
    try:
        raise SystemExit(main())
    except Exception as exc:
        print(str(exc), file=sys.stderr)
        raise SystemExit(1)
