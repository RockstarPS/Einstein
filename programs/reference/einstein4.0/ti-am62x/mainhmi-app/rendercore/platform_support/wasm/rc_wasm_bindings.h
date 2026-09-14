/*********************************************************************
	File Path	    : common\platform_support\wasm\rc_wasm_bindings.h
*********************************************************************/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "png.h"
#include <chrono>
#include <sys/stat.h>
#include <ctime>
#include <iomanip>  
#include <sstream>

extern "C" {  
    void wasmTakeScreenShot();
}

void downloadScreenshot();
void mountIndexedDB();
void syncIndexedDB();
void save_screenshot(std::string rpath, uint32_t w, uint32_t h);
