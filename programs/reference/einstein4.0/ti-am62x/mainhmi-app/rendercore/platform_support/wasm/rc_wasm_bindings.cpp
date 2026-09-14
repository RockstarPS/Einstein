///////////////////////////////////////////////////////////////////////////////
//
//                     CONFIDENTIAL VISTEON CORPORATION
//
// This is an unpublished work of authorship, which contains trade secrets,
// created in 2018. Visteon Corporation owns all rights to this work and
// intends to maintain it in confidence to preserve its trade secret status.
// Visteon Corporation reserves the right, under the copyright laws of the
// United States or those of any other country that may have jurisdiction,
// to protect this work as an unpublished work, in the event of an
// inadvertent or deliberate unauthorized publication. Visteon Corporation
// also reserves its rights under all copyright laws to protect this work as
// a published work, when appropriate. Those having access to this work may
// not copy it, use it, modify it or disclose the information contained in
// it without the written authorization of Visteon Corporation.
//
//  Filename    : rc_wasm_bindings.cpp
///////////////////////////////////////////////////////////////////////////////

#include "rc_wasm_bindings.h"

#include <GLES3/gl3.h>      
#include <emscripten.h>
#include <emscripten/html5.h>

bool screenshot_enabled;

extern "C" {  
    EMSCRIPTEN_KEEPALIVE void wasmTakeScreenShot()
    {
        screenshot_enabled = true;
    }
}

void downloadScreenshot() {
    EM_ASM({
        mime = "image/png";
        var filename = 'screenshots/screenshot.png';
        let content = Module.FS.readFile(filename);
        var a = document.createElement('a');
        a.download = filename;
        a.href = URL.createObjectURL(new Blob([content], {type: mime}));
        document.body.appendChild(a);
        a.click();
    });
}

void mountIndexedDB() {
    struct stat st;
    
    if (stat("/screenshots", &st) != 0) {
        // Directory doesn't exist, so create it
        EM_ASM({
            FS.mkdir('/screenshots');
            FS.mount(IDBFS, {}, '/screenshots');

            FS.syncfs(true, function (err) {
                if (err) {
                    console.error("Error during sync from IndexedDB:", err);
                } else {
                    console.log("Sync from IndexedDB successful!");
                }
            });
        });
    } else {
        printf("Directory '/screenshots' already exists.\n");
    }   
}

void syncIndexedDB() {
    EM_ASM({
        FS.syncfs(false, function (err) {
            if (err) {
                console.error("Error during sync to IndexedDB:", err);
            } else {
                console.log("Sync to IndexedDB successful!");
            }
        });
    });
}

void save_screenshot(std::string rpath, uint32_t w, uint32_t h)
{
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%F-%H-%M-%S");
    auto str = oss.str();

    FILE* fp = fopen(rpath.c_str(), "wb");

    if (fp)
    {
        png_structp png = png_create_write_struct(PNG_LIBPNG_VER_STRING, nullptr, nullptr, nullptr);
        if (png)
        {
            png_infop info = png_create_info_struct(png);
            if (!setjmp(png_jmpbuf(png)) && info)
            {
                png_init_io(png, fp);
                // Output is 8bit depth, RGBA format.
                png_set_IHDR(
                    png,
                    info,
                    w,
                    h,
                    8,
                    PNG_COLOR_TYPE_RGBA,
                    PNG_INTERLACE_NONE,
                    PNG_COMPRESSION_TYPE_DEFAULT,
                    PNG_FILTER_TYPE_DEFAULT
                );
                png_write_info(png, info);

                uint32_t* fl_pix_data = (uint32_t*)calloc(1, w * h * 4);
                glReadPixels(0, 0, w, h, GL_RGBA, GL_UNSIGNED_BYTE, (void*)fl_pix_data);

                // Assuming that resultant frame buffer is pre-multiplied alpha,
                // we do a alpha divide to make them non pre multiplied
                for (uint32_t y = 0; y < h; y++)
                {
                    for (uint32_t x = 0; x < w; x++)
                    {
                        uint32_t fl_rgba = fl_pix_data[(y * w) + x];
                        float a = (float)((fl_rgba >> 24) & 0xFF);
                        float b = (float)((fl_rgba >> 16) & 0xFF);
                        float g = (float)((fl_rgba >> 8) & 0xFF);
                        float r = (float)((fl_rgba) & 0xFF);
                        if (a > 0)
                        {
                            a /= 255.0f;
                            r /= 255.0f;
                            g /= 255.0f;
                            b /= 255.0f;
                            r /= a;
                            g /= a;
                            b /= a;
                            fl_rgba = (uint32_t)(a * 255.0f);
                            fl_rgba <<= 8;
                            fl_rgba |= (uint32_t)(b * 255.0f);
                            fl_rgba <<= 8;
                            fl_rgba |= (uint32_t)(g * 255.0f);
                            fl_rgba <<= 8;
                            fl_rgba |= (uint32_t)(r * 255.0f);
                            fl_pix_data[(y * w) + x] = fl_rgba;
                        }
                    }
                }

                png_bytep* row_pointers = (png_bytep*)calloc(1, sizeof(png_bytep) * h);
                for (uint32_t y = 0; y < h; y++)
                {
                    row_pointers[h - (y + 1)] = (png_bytep)&fl_pix_data[w * y];
                }

                png_write_image(png, row_pointers);
                png_write_end(png, nullptr);

                free(row_pointers);
                free(fl_pix_data);
            }
            png_destroy_write_struct(&png, &info);
        }
        fclose(fp);
    }
}

