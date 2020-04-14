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

This file is part of the GD HAL for Copepod graphics library:
https://github.com/tuupola/copepod_libgd

SPDX-License-Identifier: MIT

*/

#include <stdio.h>
#include <stdint.h>
#include <gd.h>
#include <rgb565.h>

#include "copepod_hal.h"

static gdImagePtr img;
FILE *png;

/*
 * Putpixel function. This is the only mandatory function which HAL
 * must implement for copepod to be able to draw graphical primitives.
 */
void pod_hal_putpixel(int16_t x0, int16_t y0, uint16_t color)
{
    rgb_t rgb = rgb565_to_rgb888(&color);
    int32_t gd_color = gdTrueColorAlpha(rgb.r, rgb.g, rgb.b, 0);
    gdImageSetPixel(img, x0, y0, gd_color);
}

/*
 * Initializes the GD HAL and set background color to black.
 */
void pod_hal_init(void)
{
    img = gdImageCreateTrueColor(DISPLAY_WIDTH, DISPLAY_HEIGHT);
}

/*
 * Flushes image to a PNG file.
 */
void pod_hal_flush(bool dirty, int16_t x0, int16_t y0, int16_t x1, int16_t y1)
{
    png = fopen("copepod.png", "wb");
    gdImagePng(img, png);
    fclose(png);
}
