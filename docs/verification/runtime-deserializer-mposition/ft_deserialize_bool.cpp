// Functional test for dk::runtime::core::Deserializer::deserialize(bool_t&)
//
// Exercises the real production source file. Asserts every observable effect of
// the call: the return code, the out-parameter, the buffer cursor (mPosition)
// and the remaining-byte count (mRemaining).
//
// Build and run:  see run_ft_deserialize_bool.sh
#include <cstdio>
#include <vector>
#include "dk_runtime_deserializer.hpp"

using dk::runtime::core::Deserializer;

// mPosition / mRemaining are protected, so reach them through a subclass.
struct Probe : public Deserializer
{
    Probe() : Deserializer(0U) {}

    void load(const std::vector<unsigned char> &bytes)
    {
        mData = bytes;
        mPosition = mData.begin();
        mRemaining = static_cast<std::uint32_t>(bytes.size());
    }
    long cursor() const { return mPosition - mData.begin(); }
    std::uint32_t remaining() const { return mRemaining; }
};

static int failures = 0;

#define CHECK(what, got, want)                                               \
    do {                                                                     \
        if ((got) != (want)) {                                               \
            std::printf("    FAIL %-26s got=%-6ld want=%-6ld\n",             \
                        what, (long)(got), (long)(want));                    \
            ++failures;                                                      \
        } else {                                                             \
            std::printf("    ok   %-26s = %ld\n", what, (long)(got));        \
        }                                                                    \
    } while (0)

// case, input byte, bytes loaded, expected return, value, cursor, remaining
static void run(const char *name,
                const std::vector<unsigned char> &bytes,
                bool expRet, bool expValue, long expCursor, std::uint32_t expRem)
{
    std::printf("%s\n", name);

    Probe d;
    d.load(bytes);

    // Seed the out-parameter with the opposite of what we expect, so an
    // untouched 'value' cannot accidentally look correct.
    bool value = !expValue;
    bool ret   = d.deserialize(value);

    CHECK("return",    ret ? 1 : 0,   expRet ? 1 : 0);
    CHECK("value",     value ? 1 : 0, expValue ? 1 : 0);
    CHECK("mPosition", d.cursor(),    expCursor);
    CHECK("mRemaining", d.remaining(), (long)expRem);
}

int main()
{
    std::printf("=== deserialize(bool_t&) functional test ===\n\n");

    // 0x01 -> true. Cursor must advance by 1, remaining must drop by 1.
    run("FT-01  single byte 0x01 -> true",
        {0x01}, /*ret*/true, /*value*/true, /*cursor*/1, /*rem*/0);

    // 0x00 -> false.
    run("FT-02  single byte 0x00 -> false",
        {0x00}, true, false, 1, 0);

    // Anything other than 0x01 is false (the production rule is '== 0x01').
    run("FT-03  single byte 0xFF -> false",
        {0xFF}, true, false, 1, 0);

    // Empty buffer: early return, nothing consumed, value untouched.
    {
        std::printf("FT-04  empty buffer -> false, nothing consumed\n");
        Probe d;
        d.load({});
        bool value = true;              // must stay untouched
        bool ret   = d.deserialize(value);
        CHECK("return",     ret ? 1 : 0,   0);
        CHECK("value kept", value ? 1 : 0, 1);
        CHECK("mPosition",  d.cursor(),    0);
        CHECK("mRemaining", d.remaining(), 0);
    }

    // Three bools back to back: proves the cursor advances one byte per call
    // and does not skip or stall. This is the case the fix is about.
    {
        std::printf("FT-05  three bools in sequence 01 00 01\n");
        Probe d;
        d.load({0x01, 0x00, 0x01});
        bool a = false, b = true, c = false;
        bool r1 = d.deserialize(a);
        long  c1 = d.cursor();
        bool r2 = d.deserialize(b);
        long  c2 = d.cursor();
        bool r3 = d.deserialize(c);
        long  c3 = d.cursor();
        CHECK("ret 1",      r1 ? 1 : 0, 1);
        CHECK("ret 2",      r2 ? 1 : 0, 1);
        CHECK("ret 3",      r3 ? 1 : 0, 1);
        CHECK("value 1",    a ? 1 : 0,  1);
        CHECK("value 2",    b ? 1 : 0,  0);
        CHECK("value 3",    c ? 1 : 0,  1);
        CHECK("cursor @1",  c1, 1);
        CHECK("cursor @2",  c2, 2);
        CHECK("cursor @3",  c3, 3);
        CHECK("mRemaining", d.remaining(), 0);
    }

    // A bool followed by a uint8 - proves the bool call leaves the cursor in the
    // right place for the NEXT field. A cursor bug would corrupt this payload.
    {
        std::printf("FT-06  bool then uint8 (mixed payload 01 7E)\n");
        Probe d;
        d.load({0x01, 0x7E});
        bool    flag = false;
        uint8_t next = 0U;
        bool r1 = d.deserialize(flag);
        bool r2 = d.deserialize(next);
        CHECK("ret bool",   r1 ? 1 : 0, 1);
        CHECK("ret uint8",  r2 ? 1 : 0, 1);
        CHECK("flag",       flag ? 1 : 0, 1);
        CHECK("next byte",  next, 0x7E);
        CHECK("mRemaining", d.remaining(), 0);
    }

    std::printf("\n=== %s (%d check failure%s) ===\n",
                failures ? "FAILED" : "PASSED", failures, failures == 1 ? "" : "s");
    return failures ? 1 : 0;
}
