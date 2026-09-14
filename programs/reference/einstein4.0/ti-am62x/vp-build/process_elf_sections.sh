#!/bin/bash
set -euo pipefail

# Post-build flash-integrity processing flow:
# 1. Read the application ELF and discover the exact linker-symbol regions that
#    runtime flash-integrity code will verify.
# 2. Convert the ELF to S-record, crop only those verified regions, and compute
#    the 16-bit additive checksum using srec_cat.
# 3. Extract the two checksum bytes, patch them back into the ELF at the
#    .textchecksum section, and verify the bytes were written correctly.
#
# This script intentionally fails fast on any inconsistency. For a safety
# mechanism, generating a checksum for the wrong address range is worse than
# stopping the build.

if [ "$#" -ne 8 ]; then
    echo "Usage: $0 <elf> <checksum_addr> <srec> <code_region_srec> <checksum_srec> <checksum_bin> <checksum_bytes_bin> <code_region_bin>" >&2
    exit 1
fi

ELF="$1"
CHECKSUM_ADDR="$2"
SREC_PATH="$3"
CODE_REGION_SREC="$4"
CHECKSUM_SREC="$5"
CHECKSUM_BIN="$6"
CHECKSUM_BYTES_BIN="$7"
CODE_REGION_BIN="$8"

# Tool and policy knobs are kept overridable so build environments can inject
# toolchain paths or optional-region behavior without modifying the script.
TI_ARM_OBJCOPY="${TI_ARM_OBJCOPY:-arm-none-eabi-objcopy}"
REQUIRED_SREC_VERSION="${REQUIRED_SREC_VERSION:-1.65.0}"
FLASH_INTEGRITY_REGION_SYMBOLS="${FLASH_INTEGRITY_REGION_SYMBOLS:-__TCMA_TEXTSECTION_START:__TCMA_TEXTSECTION_END,__DDR_TEXTSECTION_START:__DDR_TEXTSECTION_END}"
FLASH_INTEGRITY_ALLOW_MISSING_REGIONS="${FLASH_INTEGRITY_ALLOW_MISSING_REGIONS:-0}"

# Validate early that all required command-line tools exist before any build
# artifact is modified.
require_tool() {
    if ! command -v "$1" >/dev/null 2>&1; then
        echo "ERROR: Required tool not found in PATH: $1" >&2
        exit 1
    fi
}

# Resolve one linker symbol to its ELF address.
# The awk script prints in END instead of exiting immediately when a match is
# seen. That avoids a false failure under `set -o pipefail`, where an early awk
# exit can make `nm` terminate on SIGPIPE.
extract_symbol_addr() {
    local symbol_name="$1"

    nm -a "${ELF}" | awk -v sym="${symbol_name}" '
        $3 == sym {
            value = "0x"$1
            found = 1
        }
        END {
            if (found) {
                print value
            } else {
                exit 1
            }
        }
    '
}

# Accept either decimal or hexadecimal addresses so callers can pass through
# build-system values without reformatting them first.
validate_numeric_addr() {
    local value="$1"
    local name="$2"

    if [[ ! "${value}" =~ ^(0[xX][0-9a-fA-F]+|[0-9]+)$ ]]; then
        echo "ERROR: ${name} must be a decimal or hexadecimal address, found '${value}'." >&2
        exit 1
    fi
}

# Accept the required srecord version or any newer compatible version.
version_is_compatible() {
    local installed_version="$1"
    local required_version="$2"
    local lowest_version

    lowest_version="$(printf '%s\n%s\n' "${required_version}" "${installed_version}" | sort -V | head -n 1)"
    [ "${lowest_version}" = "${required_version}" ]
}

if [ ! -f "${ELF}" ]; then
    echo "ERROR: ELF file not found: ${ELF}" >&2
    exit 1
fi

require_tool "${TI_ARM_OBJCOPY}"
require_tool "nm"
require_tool "readelf"
require_tool "srec_cat"
require_tool "hexdump"
require_tool "dd"
require_tool "wc"
require_tool "sort"

INSTALLED_SREC_VERSION="$(srec_cat --version | awk '
    match($0, /[0-9]+\.[0-9]+\.[0-9]+/) && !found {
        version = substr($0, RSTART, RLENGTH)
        found = 1
    }
    END {
        if (found) {
            print version
        }
    }
')"
if [ -z "${INSTALLED_SREC_VERSION}" ]; then
    echo "ERROR: Unable to detect srec_cat version." >&2
    exit 1
fi

if ! version_is_compatible "${INSTALLED_SREC_VERSION}" "${REQUIRED_SREC_VERSION}"; then
    echo "ERROR: srec_cat version ${REQUIRED_SREC_VERSION} or newer is required, but found ${INSTALLED_SREC_VERSION}." >&2
    exit 1
fi
echo "srec_cat version ${INSTALLED_SREC_VERSION} detected. Proceeding..."

validate_numeric_addr "${CHECKSUM_ADDR}" "Checksum address"
CHECKSUM_ADDR_NUM=$((CHECKSUM_ADDR))
if [ $((CHECKSUM_ADDR_NUM % 2)) -ne 0 ]; then
    echo "ERROR: Checksum address ${CHECKSUM_ADDR} must be 16-bit aligned." >&2
    exit 1
fi

# Discover the exact checksum regions from linker symbols.
# This is the critical robustness change: build-time must hash the same address
# ranges that FltM_FlashIntegrity() checks at runtime.
declare -a REGION_ARGS=()
declare -a REGION_STARTS=()
declare -a REGION_ENDS=()
IFS=',' read -r -a REGION_SYMBOL_PAIRS <<< "${FLASH_INTEGRITY_REGION_SYMBOLS}"

for pair in "${REGION_SYMBOL_PAIRS[@]}"; do
    IFS=':' read -r start_symbol end_symbol <<< "${pair}"

    if [ -z "${start_symbol}" ] || [ -z "${end_symbol}" ]; then
        echo "ERROR: Invalid region symbol pair '${pair}'. Expected START_SYMBOL:END_SYMBOL." >&2
        exit 1
    fi

    start_addr=""
    end_addr=""
    if start_addr="$(extract_symbol_addr "${start_symbol}" 2>/dev/null)"; then
        :
    else
        start_addr=""
    fi
    if end_addr="$(extract_symbol_addr "${end_symbol}" 2>/dev/null)"; then
        :
    else
        end_addr=""
    fi

    if [ -z "${start_addr}" ] && [ -z "${end_addr}" ]; then
        if [ "${FLASH_INTEGRITY_ALLOW_MISSING_REGIONS}" = "1" ]; then
            echo "Skipping missing optional flash integrity region ${start_symbol}:${end_symbol}"
            continue
        fi
        echo "ERROR: Missing flash integrity region symbols ${start_symbol} / ${end_symbol} in ${ELF}." >&2
        exit 1
    fi

    if [ -z "${start_addr}" ] || [ -z "${end_addr}" ]; then
        echo "ERROR: Incomplete flash integrity region. Found only one of ${start_symbol} / ${end_symbol} in ${ELF}." >&2
        exit 1
    fi

    start_num=$((start_addr))
    end_num=$((end_addr))
    if [ "${start_num}" -ge "${end_num}" ]; then
        echo "ERROR: Invalid flash integrity region ${start_symbol}:${end_symbol} -> ${start_addr} .. ${end_addr}" >&2
        exit 1
    fi
    if [ $((start_num % 2)) -ne 0 ] || [ $((end_num % 2)) -ne 0 ]; then
        echo "ERROR: Flash integrity region ${start_symbol}:${end_symbol} must be 16-bit aligned -> ${start_addr} .. ${end_addr}" >&2
        exit 1
    fi
    if [ "${CHECKSUM_ADDR_NUM}" -ge "${start_num}" ] && [ "${CHECKSUM_ADDR_NUM}" -lt "${end_num}" ]; then
        echo "ERROR: Checksum address ${CHECKSUM_ADDR} must not be inside checked region ${start_symbol}:${end_symbol}." >&2
        exit 1
    fi
    for idx in "${!REGION_STARTS[@]}"; do
        if [ "${start_num}" -lt "${REGION_ENDS[$idx]}" ] && [ "${REGION_STARTS[$idx]}" -lt "${end_num}" ]; then
            echo "ERROR: Flash integrity region ${start_symbol}:${end_symbol} overlaps an earlier configured region." >&2
            exit 1
        fi
    done

    echo "Using flash integrity region ${start_symbol}:${end_symbol} -> ${start_addr} .. ${end_addr}"
    REGION_ARGS+=("${start_addr}" "${end_addr}")
    REGION_STARTS+=("${start_num}")
    REGION_ENDS+=("${end_num}")
done

if [ "${#REGION_ARGS[@]}" -eq 0 ]; then
    echo "ERROR: No flash integrity regions were discovered from ELF symbols." >&2
    exit 1
fi

# Validate that the checksum destination section is real and patchable in the
# produced ELF. A NOBITS section or an unexpected address would mean the build
# output cannot carry the checksum that runtime expects to compare.
if ! SECTION_INFO="$(readelf -SW "${ELF}" | awk '
    $2 == ".textchecksum" {
        section_type = $3
        section_addr = "0x"$4
        section_offset = "0x"$5
        section_size = "0x"$6
        found = 1
    }
    END {
        if (found) {
            print section_type, section_addr, section_offset, section_size
        } else {
            exit 1
        }
    }
')"; then
    echo "ERROR: .textchecksum section not found in ${ELF}." >&2
    exit 1
fi
if [ -z "${SECTION_INFO}" ]; then
    echo "ERROR: .textchecksum section not found in ${ELF}." >&2
    exit 1
fi
read -r SECTION_TYPE SECTION_ADDR SECTION_OFFSET SECTION_SIZE <<< "${SECTION_INFO}"
SECTION_ADDR_NUM=$((SECTION_ADDR))
SECTION_SIZE_NUM=$((SECTION_SIZE))

if [ "${SECTION_TYPE}" = "NOBITS" ]; then
    echo "ERROR: .textchecksum is NOBITS and cannot be patched in the ELF file. Ensure g_checksum is linked into .textchecksum." >&2
    exit 1
fi
if [ "${SECTION_ADDR_NUM}" -ne "${CHECKSUM_ADDR_NUM}" ]; then
    echo "ERROR: .textchecksum address ${SECTION_ADDR} does not match checksum address ${CHECKSUM_ADDR}." >&2
    exit 1
fi
if [ "${SECTION_SIZE_NUM}" -lt 2 ]; then
    echo "ERROR: .textchecksum section size ${SECTION_SIZE} is smaller than the 2-byte checksum." >&2
    exit 1
fi

CHECKSUM_END_ADDR=$(printf '0x%08X' $((CHECKSUM_ADDR + 2)))
CHECKSUM_OFFSET_NEG="-${CHECKSUM_ADDR_NUM}"

# Generate the S-record view of the ELF and keep only the validated integrity
# regions. The resulting CODE_REGION artifacts are the exact bytes that the
# additive checksum is calculated over.
"${TI_ARM_OBJCOPY}" -O srec "${ELF}" "${SREC_PATH}"

srec_cat "${SREC_PATH}" -crop "${REGION_ARGS[@]}" -o "${CODE_REGION_SREC}" -output-block-size=16
srec_cat "${CODE_REGION_SREC}" -crop "${REGION_ARGS[@]}" -o "${CODE_REGION_BIN}" -binary

# Compute the 16-bit little-endian positive checksum and then extract only the
# two checksum bytes into a compact binary blob for patching back into the ELF.
srec_cat "${CODE_REGION_SREC}" -checksum-positive-l-e "${CHECKSUM_ADDR}" 2 2 -o "${CHECKSUM_SREC}" -output-block-size=16
srec_cat "${CHECKSUM_SREC}" -o "${CHECKSUM_BIN}" -binary
srec_cat "${CHECKSUM_SREC}" -crop "${CHECKSUM_ADDR}" "${CHECKSUM_END_ADDR}" -offset "${CHECKSUM_OFFSET_NEG}" -o "${CHECKSUM_BYTES_BIN}" -binary

CHECKSUM_BYTES_SIZE="$(wc -c < "${CHECKSUM_BYTES_BIN}")"
if [ "${CHECKSUM_BYTES_SIZE}" -ne 2 ]; then
    echo "ERROR: Expected 2 checksum bytes, generated ${CHECKSUM_BYTES_SIZE} bytes in ${CHECKSUM_BYTES_BIN}." >&2
    exit 1
fi

# Patch the checksum into the ELF at the .textchecksum file offset and read it
# back immediately. The readback check guards against offset mistakes and makes
# the script self-validating for safety reviews.
dd if="${CHECKSUM_BYTES_BIN}" of="${ELF}" bs=1 seek="$((SECTION_OFFSET))" count=2 conv=notrunc status=none

CHECKSUM_HEX="$(hexdump -v -e '1/2 "%04x"' "${CHECKSUM_BYTES_BIN}")"
PATCHED_HEX="$(dd if="${ELF}" bs=1 skip="$((SECTION_OFFSET))" count=2 status=none | hexdump -v -e '1/2 "%04x"')"
if [ "${PATCHED_HEX}" != "${CHECKSUM_HEX}" ]; then
    echo "ERROR: ELF patch verification failed. Expected ${CHECKSUM_HEX}, read back ${PATCHED_HEX}." >&2
    exit 1
fi

echo "Patched checksum: 0x${CHECKSUM_HEX} at offset ${SECTION_OFFSET}"
