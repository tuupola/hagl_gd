/*

MIT License

Copyright (c) 2018-2022 Mika Tuupola

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
#include <hagl/backend.h>

#include "hagl_hal.h"

static gdImagePtr img;
FILE *png;

static void
put_pixel(void *self, int16_t x0, int16_t y0, color_t color)
{
    gdImageSetPixel(img, x0, y0, color);
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

static color_t
color(void *self, uint8_t r, uint8_t g, uint8_t b) {
    // return gdTrueColor(r, g, b);
    return (r << 16) | (g << 8) | (b);
}

void
hagl_hal_init(hagl_backend_t *backend)
{
    img = gdImageCreateTrueColor(DISPLAY_WIDTH, DISPLAY_HEIGHT);

    backend->width = DISPLAY_WIDTH;
    backend->height = DISPLAY_HEIGHT;
    backend->depth = DISPLAY_DEPTH;
    backend->put_pixel = put_pixel;
    backend->color = color;

    backend->flush = flush;
    backend->close = close;

}
