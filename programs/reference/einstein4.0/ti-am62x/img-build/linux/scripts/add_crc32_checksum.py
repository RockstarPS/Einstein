import argparse
import struct
import sys
import zlib


def auto_int(x):
    # Automatically handles '0x123' (hex) or '123' (decimal) strings
    return int(x, 0)


def main():
    parser = argparse.ArgumentParser(
        description="Calculate CRC32 and write it to a hex-defined offset."
    )
    parser.add_argument("filename", help="Path to the target file")
    parser.add_argument(
        "crc_len",
        type=auto_int,
        help="Number of bytes to read for CRC (accepts int or hex like 0x50000)",
    )
    parser.add_argument(
        "offset",
        type=auto_int,
        help="Target byte offset in hex (e.g., 0x80005) or decimal",
    )
    parser.add_argument(
        "--endian",
        choices=["little", "big"],
        default="big",
        help="Byte order for the 32-bit CRC (default: little)",
    )

    args = parser.parse_args()

    try:
        with open(args.filename, "r+b") as f:
            # Step 1: Read the specified length for CRC
            data = f.read(args.crc_len)
            crc_value = zlib.crc32(data)

            # Step 2: Set endianness format
            fmt = "<I" if args.endian == "little" else ">I"
            packed_crc = struct.pack(fmt, crc_value)

            # Step 3: Seek to the hex-parsed offset and write
            f.seek(args.offset)
            f.write(packed_crc)

        print(f"Success: Read {args.crc_len} (hex: {hex(args.crc_len)}) bytes.")
        print(
            f"Wrote CRC32 {hex(crc_value)} to offset {hex(args.offset)} ({args.offset} dec)."
        )

    except FileNotFoundError:
        print(f"Error: File '{args.filename}' not found.", file=sys.stderr)
        sys.exit(1)
    except Exception as e:
        print(f"Error: {e}", file=sys.stderr)
        sys.exit(1)


if __name__ == "__main__":
    main()

