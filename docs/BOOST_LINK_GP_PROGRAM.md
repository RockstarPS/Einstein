# Linking Boost from the repo prebuilt — gp-build/linux

**Scope:** Linux variant only. QNX untouched.
**Commits:** `459d794d0` (gp_program.cmake), `5c896d47e` (copy-rootfs-partition.sh).

---

## 1. The problem being solved

Before this change, `find_package(Boost)` resolved to the **TI SDK sysroot**
copy — and did so *silently*. Commenting out the Boost lines in
`gp_program.cmake` entirely still produced a working build, because the SDK
supplied everything.

That meant the repo did not actually control which Boost was used.

### Why setting the paths was not enough

The original code did this:

```cmake
set(Boost_INCLUDE_DIR .../include)
set(Boost_LIBRARY_DIR .../lib)
```

`find_package(Boost ...)` can resolve two ways:

| Mode | How it finds Boost |
|---|---|
| **CONFIG** | reads a `BoostConfig.cmake` shipped by Boost itself |
| **MODULE** | runs CMake's `FindBoost.cmake`, which searches for files |

`FindBoost.cmake` **tries CONFIG mode first** and hands off if it finds a config
file. The TI sysroot ships one. And `Boost_INCLUDE_DIR` / `Boost_LIBRARY_DIR` are
**MODULE-mode hints only** — CONFIG mode ignores them completely.

So: CONFIG mode found the sysroot's config, succeeded, and the paths above were
never consulted.

This is also why the same four lines work fine on QNX — the QNX sysroot has no
Boost, so CONFIG mode finds nothing and falls through to MODULE mode, where the
hints do apply.

---

## 2. The final solution

```cmake
set(BOOST_PREBUILT    ${CMAKE_SOURCE_DIR}/cluster-platform/runtime_infra/external/Boost-prebuilt-linux-x64)
set(Boost_INCLUDE_DIR ${BOOST_PREBUILT}/include)
set(Boost_LIBRARY_DIR ${BOOST_PREBUILT}/lib)

# Never resolve Boost from the SDK sysroot: no CONFIG mode, no system paths.
set(Boost_NO_BOOST_CMAKE ON)
set(Boost_NO_SYSTEM_PATHS ON)

# FindBoost looks for libboost_*.so; the prebuilt ships only libboost_*.so.<ver>.
file(GLOB BOOST_VERSIONED_LIBS ${Boost_LIBRARY_DIR}/libboost_*.so.*)
if(NOT BOOST_VERSIONED_LIBS)
	message(FATAL_ERROR "No Boost libraries in ${Boost_LIBRARY_DIR}")
endif()
foreach(BOOST_LIB ${BOOST_VERSIONED_LIBS})
	get_filename_component(BOOST_LIB_NAME ${BOOST_LIB} NAME)
	string(REGEX REPLACE "\\.so\\..*$" ".so" BOOST_LIB_LINK ${BOOST_LIB_NAME})
	file(REMOVE ${Boost_LIBRARY_DIR}/${BOOST_LIB_LINK})
	file(CREATE_LINK ${BOOST_LIB_NAME} ${Boost_LIBRARY_DIR}/${BOOST_LIB_LINK} SYMBOLIC)
endforeach()

# Indirect deps (libvsomeip3 -> libboost_thread) resolve via -rpath-link, not -L.
string(APPEND CMAKE_EXE_LINKER_FLAGS " -Wl,-rpath-link,${Boost_LIBRARY_DIR}")
string(APPEND CMAKE_SHARED_LINKER_FLAGS " -Wl,-rpath-link,${Boost_LIBRARY_DIR}")

# Runtime: the board loads the versioned .so named in DT_NEEDED.
file(COPY ${BOOST_VERSIONED_LIBS} DESTINATION ${CMAKE_INSTALL_PREFIX}/usr/lib)
```

Plus one line in `img-build/linux/scripts/copy-rootfs-partition.sh`:

```bash
yes | cp -rf $BIN_DIR/aarch64le/usr/lib/libboost_*.so.*           $TGT_DIR/usr/lib/
```

### What each part is for

| Lines | Removing them causes |
|---|---|
| `BOOST_PREBUILT`, `Boost_*_DIR` | empty-variable errors |
| `Boost_NO_BOOST_CMAKE` | CONFIG mode wins → `boost_headers EXACT 1.74.0` not found |
| `Boost_NO_SYSTEM_PATHS` | sysroot back in the search |
| glob + `FATAL_ERROR` | silent no-op if the prebuilt is missing |
| foreach symlink loop | `missing components: thread filesystem` |
| `-rpath-link` ×2 | undefined `boost::this_thread::` refs at ~568/653 |
| `file(COPY ...)` | links fine, won't start on the board |
| rootfs `cp` line | board runs on the Yocto image's Boost, not ours |

---

## 3. The three mechanisms, explained

### 3.1 Why the `.so` symlink is needed

`find_library` composes candidate filenames by concatenation:

```
"lib" + "boost_thread" + <suffix from CMAKE_FIND_LIBRARY_SUFFIXES>
```

On Linux that suffix list is `.so` and `.a`. **Nothing in CMake ever appends a
version.** So in a folder containing only `libboost_thread.so.1.74.0` it tries
`libboost_thread.so`, tries `libboost_thread.a`, and reports the component missing
— while standing in the correct directory.

Proven in isolation:

```
A plain search        = [A-NOTFOUND]        # correct dir, versioned file present
B pre-set then search = [.../libboost_thread.so.1.74.0]
```

The `.so` is a **symlink**, not a copy. Three names exist for one library:

| Name | Example | Used by |
|---|---|---|
| real file | `libboost_thread.so.1.74.0` | on disk |
| soname (inside the file) | `libboost_thread.so.1.74.0` | the loader, at runtime |
| linker name (symlink) | `libboost_thread.so` | the build, at link time |

Versions live in `.so` filenames because several versions must coexist on one
machine at runtime. A `.a` needs no version — it is consumed at build time and
never exists at runtime. That is the whole reason QNX needs none of this.

**Never rename the real file to drop the version.** The versioned name is stored
inside the library as its soname and copied into every binary that links it; rename
it and the build succeeds while the board fails at startup.

### 3.2 Why `-rpath-link`

```
hello_world_service  →  libvsomeip3.so       (named on the link line)
libvsomeip3.so       →  libboost_thread.so.1.74.0   (recorded inside it, DT_NEEDED)
```

`examples/hello_world/CMakeLists.txt:30` links only `vsomeip3 Threads::Threads` —
no Boost. But the linker must still open `libboost_thread.so.1.74.0` to verify
symbols resolve. Its search order for such an **indirect** dependency:

| Order | Consulted |
|---|---|
| 1 | `-rpath-link` directories |
| 2 | `-rpath` directories |
| 3 | `LD_RUN_PATH` |
| 4 | `-L` — **SunOS only, not Linux** |
| 5 | default dirs (`/lib`, `/usr/lib` in the sysroot) |

`-L` and `link_directories()` do **not** work here. That is the non-obvious part.
Previously step 5 found the SDK copy for free; once Boost moved out of the sysroot,
nothing did.

`-rpath-link` is link-time only — nothing is written into the binary. Runtime is
solved separately by the rootfs copy.

### 3.3 Why the rootfs line

`copy-rootfs-partition.sh` copies only files it names explicitly, and had no
`libboost_*` line. The rootfs is unpacked from
`core-image-minimal-am62pxx-<board>.rootfs.tar.xz`, a Yocto image that carries its
own Boost.

**So the build was using the repo prebuilt while the board kept loading the SDK
copy.** Adding the `cp` line (with `-f`, overwriting the base image's) closes that.

No `ln -s` is needed in the rootfs. The existing symlink lines there exist because
those libraries have a soname *shorter* than their filename:

| Library | File shipped | soname | symlink needed |
|---|---|---|---|
| `libdk_logger` | `.so.0.8.0` | `.so.0` | yes |
| `libdlt` | `.so.2.18.10` | `.so.2` | yes |
| `libboost_thread` | `.so.1.74.0` | `.so.1.74.0` | **no** |

---

## 4. Approaches tried and rejected

### 4.1 CONFIG mode via `Boost_DIR`

Pointing at the prebuilt's own `lib/cmake/Boost-1.74.0/`:

```
Could not find a configuration file for package "boost_headers" ... EXACT 1.74.0
```

`BoostConfig.cmake:141` issues a **fresh `find_package`** per component:

```cmake
find_package(boost_${comp} ${Boost_VERSION} EXACT CONFIG ... HINTS ${_BOOST_CMAKEDIR})
```

The cross toolchain sets `CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY`, confining every
`find_package` to the sysroot — so those sibling lookups are blocked. **CONFIG mode
is unusable in this toolchain for a package outside the sysroot.** Hence
`Boost_NO_BOOST_CMAKE ON`.

### 4.2 A post-`binary_scripts()` verification guard — two failed attempts

Goal: prove at configure time that Boost resolved to the repo, not the SDK.

- Attempt 1 read `Boost_INCLUDE_DIRS` → empty. `find_package` ran inside vsomeip's
  scope, so the plural variable was not visible at gp_program level.
- Attempt 2 read `$CACHE{Boost_INCLUDE_DIR}` → also empty.

The second failure is instructive: because `Boost_INCLUDE_DIR` is **pre-set as a
normal variable**, `find_path` skips searching entirely and never creates a cache
entry. The absence of a value *is* the proof the mechanism works.

**Guard abandoned.** The `FATAL_ERROR` on a missing glob plus the `Found Boost:`
path in the log provide the same assurance. Cost: three build cycles.

### 4.3 The four-line QNX-style block

```cmake
set(Boost_FOUND TRUE)
set(Boost_VERSION 107400)
set(Boost_INCLUDE_DIR .../include)
set(Boost_LIBRARY_DIR .../lib)
```

```
Could NOT find Boost (missing: thread filesystem) (found suitable version "1.74.0")
```

Version found (from `version.hpp`), libraries not (no `.so` symlinks). Also
`set(Boost_FOUND TRUE)` does nothing — `find_package` overwrites it.

Works on QNX only because `vsomeip/CMakeLists.txt:107` sets `Boost_USE_STATIC_LIBS ON`,
which forces the suffix list to `.a` — an exact match for the QNX prebuilt.

### 4.4 Undefined variables

Carrying the *users* of `BOOST_LIB_DIR` / `BOOST_PREBUILT` into a file without the
lines that *set* them:

```
file must be called with at least two arguments
file COPY given no DESTINATION
file failed to create symbolic link '/libboost_filesystem.so': permission denied
file STRINGS file "/include/boost/version.hpp" cannot be read
```

CMake never warns about an undefined variable — it substitutes nothing and carries
on. **A path in an error starting with a bare `/` almost always means an empty
variable, not a permissions problem.**

### 4.5 Fixing it inside `vsomeip/CMakeLists.txt`

Attempted to keep `gp_program.cmake` untouched by setting `Boost_LIBRARIES` and the
`-rpath-link` flag inside vsomeip. Result:

- `hello_world_*` — **fixed**
- `srvgw_vsomeip` — **still broken**

`binary_scripts()` includes each script through `binary_script`
(`binariesSupport.cmake:63`), a **function** — so each script gets its own variable
scope. Changes made inside vsomeip die when that include returns.

```
gp_program.cmake  ← set here, everything below inherits it
└─ binary_scripts(...)              ← a function
   ├─ binary_script(vsomeip)        ← private copy
   │   └─ add_subdirectory(hello_world)   ← nested → sees the change
   ├─ binary_script(srvgw_vsomeip)  ← FRESH copy from top level → does not
```

**Rule: a CMake variable flows downward only — never sideways to a sibling, never
back up.** Anything that must apply to the whole build has to be set where the whole
build can see it.

That attempt also required commenting out `find_package(Boost ...)` and
`find_package(Threads REQUIRED)`, which left `-DVSOMEIP_BOOST_VERSION=` empty, and
introduced a typo at line 107 (`Boost_USE_STATIC_LIBS_ON` — underscore instead of a
space) that silently disables static selection for QNX. All reverted.

### 4.6 Build-tree staging vs. repo symlinks

Two working shapes, several rounds of switching between them:

| | Symlinks live in | Self-heals | Writes to repo |
|---|---|---|---|
| Build-tree staging | `${CMAKE_BINARY_DIR}/external/boost/lib` | yes | no |
| Repo + manual `ln -sf` | repo, created by hand once | no | no |
| **Repo, created by cmake** (chosen) | repo | yes | yes, each configure |

The chosen shape trades a clean `git status` for never having to think about the
symlinks again. Justified because git stores a symlink as an **empty file** on a
Windows checkout — which has already happened in this repo: the QNX prebuilt's
`.so` files are all 0 bytes. QNX does not notice, because it links `.a`.

---

## 5. Verifying

```bash
OUT=programs/reference/einstein4.0/ti-am62x/out/GP_LINUX/EINSTEIN_4_0_A0/release

# every Boost path handed to the linker - none should contain "sysroots"
grep -o '[^ ]*libboost[^ ]*' $OUT/build.ninja | sort -u

# what the built library records
aarch64-oe-linux-readelf -d $OUT/GP_BUILD/lib/libvsomeip3.so.3.5.11 | grep NEEDED | grep boost

# after an image build, before ./rootfs is removed
ls -l rootfs/usr/lib/libboost_*
```

Configure log should show:

```
-- Found Boost: .../Boost-prebuilt-linux-x64/include (found suitable version "1.74.0", ...) found components: thread filesystem
-- Using boost version: 107400
```

**Negative test:** move the prebuilt aside and re-configure — it must stop at the
`FATAL_ERROR`, not fall back to the SDK.

---

## 6. Linux vs QNX — why the two files differ

Two independent causes:

1. **QNX links Boost statically** (`vsomeip/CMakeLists.txt:107`). Static archives
   are copied into the binary at link time, so there is no `DT_NEEDED`, no
   transitive lookup, no runtime file, and no version in the filename.
2. **The TI Linux sysroot ships Boost; the QNX sysroot does not.**

| Linux needs | Cause | QNX |
|---|---|---|
| `.so` symlink | 1 | `.a` is the exact name |
| `-rpath-link` | 1 | code already inside the binary |
| rootfs copy | 1 | nothing to ship |
| `Boost_NO_BOOST_CMAKE` | 2 | no config in the sysroot |
| `Boost_NO_SYSTEM_PATHS` | 2 | nothing there to find |

Rebuilding the Linux prebuilt with `link=static cxxflags=-fPIC` would eliminate
rows 1-3 and reduce the block to five lines.

---

## 7. Known follow-ups

- The folder is named `Boost-prebuilt-linux-x64` but contains **aarch64**
  libraries. `-linux-aarch64` would match the QNX folder's convention.
- `cluster-platform/runtime_infra/external/Boost/build_boost.cmake` is dead code —
  nothing includes it.
- `Boost-prebuilt-linux-x64` is **not yet committed**; the branch cannot build for
  anyone else until it is.
- Only `system`, `thread`, `filesystem` are present. `chrono`, `date_time`, `atomic`
  show as missing components — benign today.
- The three generated `.so` symlinks appear as untracked on every configure. Commit
  them or add them to `.gitignore`.
