/*

MIT License

Copyright (c) 2018-2021 Mika Tuupola

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

-cut-

This file is part of the GD HAL for the HAGL graphics library:
https://github.com/tuupola/hagl_gd

SPDX-License-Identifier: MIT

*/

#include <stdio.h>
#include <stdint.h>
#include <gd.h>
#include <rgb565.h>
#include <backend.h>

#include "hagl_hal.h"

static gdImagePtr img;
FILE *png;

static void
put_pixel(void *self, int16_t x0, int16_t y0, color_t color)
{
    uint8_t r = (color >> 16) & 0xff;
    uint8_t g = (color >> 8) & 0xff;
    uint8_t b = (color) & 0xff;

    int32_t gd_color = gdTrueColorAlpha(r, g, b, 0);
    gdImageSetPixel(img, x0, y0, gd_color);
}


static size_t
flush(void *self)
{
    /* Output the current frame as png file. */
    png = fopen("hagl.png", "wb");
    gdImagePng(img, png);
    fclose(png);
    return DISPLAY_WIDTH * DISPLAY_HEIGHT * DISPLAY_DEPTH / 8;
}

static void
close(void *self)
{
    /* Release the memory acquired earlier with gdImageCreateTrueColor() */
    gdImageDestroy(img);
}

void
hagl_hal_init(hagl_backend_t *backend)
{
    img = gdImageCreateTrueColor(DISPLAY_WIDTH, DISPLAY_HEIGHT);

    backend->width = DISPLAY_WIDTH;
    backend->height = DISPLAY_HEIGHT;
    backend->depth = DISPLAY_DEPTH;
    backend->put_pixel = put_pixel;

    backend->flush = flush;
    backend->close = close;

}
