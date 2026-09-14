# Build Instructions {#build_instructions}
## Building UCL Library
### QNX 660
#### Environment
* Install <a href="http://swdata/SWToolsWiki/bin/view/CASETools/QNX">QNX6</a>

#### Steps to build
* Setup path `C:\qnx660\qnx660-env.bat`
* Execute `configure.bat QNX660_ARMV7`
* Execute `make install`

### Linux AARCH64
#### Environment
* Minimum <a href="https://cmake.org/files/v3.0/">CMake 3.0.0 </a>
* Get <a href="http://repo.msys2.org/distrib/i686/msys2-i686-20161025.exe">MSYS2</a>
 * Install make `pacman -S make`
* Get <a href="https://releases.linaro.org/components/toolchain/binaries/latest-5/aarch64-linux-gnu/gcc-linaro-5.4.1-2017.05-i686-mingw32_aarch64-linux-gnu.tar.xz">Linaro GCC 5.4.1 for AARCH64</a>
 * Unzip using 7-zip in adminstrator mode to c:\distools\

#### Steps to build
* Setup path `SET PATH=%%PATH%;C:\msys64\usr\bin;C:\distools\gcc-linaro-5.4.1-2017.05-i686-mingw32_aarch64-linux-gnu\bin;`
* Execute `configure.bat LINUX_AARCH64`
* Execute `make install`

### Windows x86 and x86_64
#### Environment
* Minimum <a href="https://cmake.org/files/v3.0/">CMake 3.0.0 </a>
* Get <a href="http://repo.msys2.org/distrib/i686/msys2-i686-20161025.exe">MSYS2</a>
 * Install make `pacman -S make`
 * Install MinGW32 6.2.0 `pacman -S mingw-w64-i686-gcc`
 * Install MinGW64 6.2.0 `pacman -S mingw-w64-x86_64-gcc`

#### Steps to build for Windows x86
* Setup path `SET PATH=%%PATH%;C:\msys64\usr\bin;C:\msys64\mingw32\bin;`
* Execute `configure.bat WIN_X86`
* Execute `make install`

#### Steps to build for Windows x64
* Setup path `SET PATH=%%PATH%;C:\msys64\usr\bin;C:\msys64\mingw64\bin;`
* Execute `configure.bat WIN_X86_64`
* Execute `make install`

### GHS INTEGRITY
#### Environment (Linux)
* CMake 3.0.0
* GHS Compiler installed at `/opt/ghs/ghs.comp_201416_linux`
* GHS BSP installed at `/opt/ghs/ghs.int1124-P2`
* GHS BSP Include files Search Path `/opt/ghs/ghs.int1124-P2/modules/ghs/bspsrc`
* GHS BSP Libraries files Search Path `/opt/ghs/ghs.int1124-P2/libs/devtree-cortex-a15` 

#### Steps to build
* Goto `infra.comm.ucl.src\make\scripts`
* Execute `. configure.sh GHS_RCARH2`
* Execute `make install`

#### Environment (Windows)
* CMake 3.0.0
* GHS Compiler installed at `C:/ghs/ghs.comp_201416_linux`
* GHS BSP installed at `C:/ghs/ghs.int1124-P2`
* GHS BSP Include files Search Path `C:/ghs/ghs.int1124-P2/modules/ghs/bspsrc`
* GHS BSP Libraries files Search Path `C:/ghs/ghs.int1124-P2/libs/devtree-cortex-a15` 

#### Steps to build
* Goto `infra.comm.ucl.src\make\scripts`
* Execute `configure.bat GHS_RCARH2`
* Execute `make install`

## Coverity
#### Environment
* Install <a href="http://swdata/SWToolsWiki/pub/CASETools/Coverity/Coverity-UserGuide.pdf">Coverity</a>
* Execute `make coverity`
 * Supported builds QNX660_ARMV7

## Building UCL Applications
Setup Environment as described in Building UCL Library for the selected target
### Highline.Cfg1 (SmartCore2.0 board with Linux)
#### Steps to build (Windows)
* Goto `app\highline.cfg1\make`
* Execute `configure.bat`
* Execute `make`

### SCQ.CES2018 (Qualcomm SD820 ADP with QNX7)
#### Steps to build (Windows)
* Goto `APP\scq.ces2018\make`
* Execute `configure.bat`
* Execute `make`
