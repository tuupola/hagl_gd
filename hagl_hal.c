/*

MIT License

Copyright (c) 2018-2020 Mika Tuupola

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

#include "hagl_hal.h"

static gdImagePtr img;
FILE *png;

void hagl_hal_put_pixel(int16_t x0, int16_t y0, color_t color)
{
    /* GD uses RGBA888 internally so lets convert the color. */
    rgb_t rgb = rgb565_to_rgb888(&color);
    int32_t gd_color = gdTrueColorAlpha(rgb.r, rgb.g, rgb.b, 0);
    gdImageSetPixel(img, x0, y0, gd_color);
}

bitmap_t *hagl_hal_init(void)
{
    img = gdImageCreateTrueColor(DISPLAY_WIDTH, DISPLAY_HEIGHT);
    /* This HAL does not use double buffering so we return NULL. */
    return NULL;
}

size_t hagl_hal_flush()
{
    /* Output the current frame as png file. */
    png = fopen("hagl.png", "wb");
    gdImagePng(img, png);
    fclose(png);
    return DISPLAY_WIDTH * DISPLAY_HEIGHT * DISPLAY_DEPTH / 8;
}

void hagl_hal_close()
{
    /* Release the memory acquired earlier with gdImageCreateTrueColor() */
    gdImageDestroy(img);
}
