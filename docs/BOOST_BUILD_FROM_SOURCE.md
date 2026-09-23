# Building Boost from source for gp-build/linux

**Scope:** Linux variant only. QNX was explicitly left untouched.
**Target:** aarch64 (TI AM62P), cross-compiled from an x86_64 host.
**Outcome:** produced `libboost_system`, `libboost_thread`, `libboost_filesystem` as
`.so.1.74.0` for `aarch64-oe-linux`. These libraries are what now live in the
committed prebuilt; the build script itself is no longer wired into the build.

---

## 1. Why this was done

Boost was being consumed from the TI SDK sysroot:

```cmake
set(Boost_LIBRARY_DIR ${CONAN_USER_HOME}/sysroots/aarch64-oe-linux/usr/lib)
set(Boost_INCLUDE_DIR ${CONAN_USER_HOME}/sysroots/aarch64-oe-linux/usr/include/boost)
```

That makes the Boost version a property of whichever SDK happens to be
provisioned, not of the repo. The goal was for the repo to own Boost, built from
a vendored source tree, and consumed by vsomeip (and anything else) instead of a
prebuilt pulled in from outside.

## 2. What was built

**Location:** `cluster-platform/runtime_infra/external/Boost/` (vendored source tree)
**Driver:** `build_boost.cmake` in the same folder, `include()`d from
`gp_program.cmake` ahead of `binary_scripts()`, because vsomeip resolves Boost
during that step.

**Build system:** Boost.Build (`bootstrap.sh` + `b2`), not CMake. Boost does not
ship a CMake build; `build_boost.cmake` is a wrapper that invokes b2 with the
right cross-compilation arguments.

### Linux arguments

```
--user-config=<build>/user-config.jam
toolset=gcc-oe
target-os=linux
architecture=arm
address-model=64
link=shared
cflags=--sysroot=<sysroot>
cxxflags=--sysroot=<sysroot>
linkflags=--sysroot=<sysroot>
variant=release
--with-libraries=system,thread,filesystem
```

`user-config.jam` is generated at configure time and contains one line:

```
using gcc : oe : /path/to/aarch64-oe-linux-g++ ;
```

That is what binds the name `gcc-oe` in `toolset=gcc-oe` to the actual cross
compiler. The compiler path comes from `CMAKE_CXX_COMPILER` — the conan2 profile
build does not export a shell `$CXX`, so reading the environment is not reliable.

### Design choices in the script

| Choice | Reason |
|---|---|
| Version read from `Jamroot`, not hardcoded | dropping in a different Boost release cannot silently disagree with the script |
| Self-locates via `CMAKE_CURRENT_LIST_DIR` | folder name and letter case do not matter |
| Stamp file `BOOST_BUILT` guards the build | b2 takes minutes and configure runs often |
| `FATAL_ERROR` if `bootstrap.sh` is absent | fails loudly instead of half-building |

---

## 3. Problems hit, in order

### 3.1 b2 bootstrap picked up the cross compiler

`bootstrap.sh` builds the `b2` tool itself. That tool has to **run on the x86_64
host** — it must not be cross-compiled for aarch64. With `CC`/`CXX` pointing at
the cross compiler, bootstrap produced a b2 binary that could not execute.

**Fix:**

```cmake
COMMAND env -u CC -u CXX -u CFLAGS -u CXXFLAGS ./bootstrap.sh --with-toolset=gcc
```

Clear the compiler environment for bootstrap only. The cross compiler is supplied
separately to `b2` through `user-config.jam`.

### 3.2 `errno.h: No such file or directory`

Compiling `boost.container`'s `dlmalloc_ext_2_8_6.c` failed. The sysroot was being
passed via `cxxflags` and `linkflags` only — but this is a plain **C** file, so
`cxxflags` never applied to it and it could not find the sysroot's libc headers.

**Fix:** add `cflags` alongside the other two.

```cmake
"cflags=--sysroot=${CMAKE_SYSROOT}"
"cxxflags=--sysroot=${CMAKE_SYSROOT}"
"linkflags=--sysroot=${CMAKE_SYSROOT}"
```

### 3.3 `include could not find requested file` — three times

```
CMake Error: include could not find requested file:
  .../runtime_infra/external/build_boost.cmake
```

The path passed to `include()` never matched where the file actually was. Cost
three configure cycles before the paths were aligned.

**Lesson:** an `include()` path is not validated until it runs — a typo shows up
minutes into a build, not at edit time.

### 3.4 Hardcoded source folder name

The script assumed `boost-1.90.0-src`; the extracted folder was named differently.

**Fix:** self-locate from the file's own directory:

```cmake
if(EXISTS ${CMAKE_CURRENT_LIST_DIR}/bootstrap.sh)
	set(BOOST_SRC_DIR ${CMAKE_CURRENT_LIST_DIR})
endif()
```

### 3.5 `Boost` vs `boost` — case sensitivity

The fallback path used one capitalisation, the folder on disk the other. Invisible
on Windows, fatal on Linux. Solved by the same self-location change.

### 3.6 Version regex silently never matched

Reading the version out of `Jamroot`:

```cmake
file(STRINGS ${BOOST_SRC_DIR}/Jamroot BOOST_VERSION_LINE REGEX "constant.*BOOST_VERSION")
```

`file(STRINGS)` escapes semicolons as `\;`, so a pattern ending in `.*;` never
matched and the version came back empty.

**Fix:** match the number itself rather than the line structure:

```cmake
string(REGEX MATCH "[0-9]+\\.[0-9]+\\.[0-9]+" BOOST_VERSION_STRING "${BOOST_VERSION_LINE}")
```

Caught by testing the regex in isolation before shipping it.

### 3.7 Wrong version assumed

An existing prebuilt was believed to be Boost 1.78.0. `Jamroot` line 147 said:

```
constant BOOST_VERSION : 1.74.0 ;
```

Always read the version out of the tree rather than trusting the folder name or
memory.

### 3.8 Environment mishaps

- A `mv` typo (`tisdk` vs `ti_sdk`) moved the SDK somewhere unexpected.
- A partial stash of the SDK's Boost left `Boost-1.90.0/` behind without its
  `boost_*` sibling packages, producing confusing CONFIG-mode errors later.

Both cost time to diagnose because the resulting errors pointed at CMake, not at
the filesystem.

### 3.9 Version pivot: 1.90.0 → 1.74.0

The original target was 1.90.0. Mid-way the decision changed to 1.74.0, to match
the version the QNX prebuilt and the SDK already used, and to avoid an
unnecessary API jump. The script needed no edit — the version is read from
`Jamroot`.

---

## 4. Verifying the result

```bash
# architecture of the produced library
aarch64-oe-linux-readelf -h <lib>/libboost_thread.so.1.74.0 | grep Machine
# expect: AArch64

# what the library calls itself
aarch64-oe-linux-readelf -d <lib>/libboost_thread.so.1.74.0 | grep SONAME
# expect: libboost_thread.so.1.74.0
```

Configure log confirmation that the repo copy was used:

```
-- Using boost version: 107400
```

---

## 5. Current status

`build_boost.cmake` is **no longer included by anything.** The decision was to stop
building Boost on every clean build and instead commit the libraries it produced as
a prebuilt, which is what `gp_program.cmake` now consumes. See the companion
document for that half.

The script remains in the tree as dead code. It is worth keeping only if Boost will
be rebuilt (e.g. to add the `chrono`, `date_time`, `atomic` components, or to switch
to `link=static cxxflags=-fPIC`); otherwise it should be deleted.

**Commits:** `bd2ca0c8a`, `98eb05df8` (superseded by `459d794d0`).

## 6. If Boost is rebuilt

Only three components were built: `system`, `thread`, `filesystem`. The configure
log reports:

```
missing components: chrono date_time atomic
```

Harmless today — vsomeip only *requires* thread and filesystem — but if any of
those are ever needed, extend the bootstrap line:

```
--with-libraries=system,thread,filesystem,chrono,date_time,atomic
```

And consider building static libraries at the same time, which removes an entire
class of problems described in the companion document:

```
link=static cxxflags=-fPIC cflags=-fPIC
```

`-fPIC` is mandatory: the archives get linked into `libvsomeip3.so`, and a shared
library can only be built from position-independent objects. The QNX Boost was
built this way for the same reason.
