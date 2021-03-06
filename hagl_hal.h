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

#ifndef _HAGL_GD_HAL_H
#define _HAGL_GD_HAL_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <bitmap.h>

/* HAL must provide display dimensions and depth. */
#define DISPLAY_WIDTH   (320)
#define DISPLAY_HEIGHT  (240)
#define DISPLAY_DEPTH   (16)

/* These are the optional features this HAL provides. */
#define HAGL_HAS_HAL_INIT
#define HAGL_HAS_HAL_FLUSH
#define HAGL_HAS_HAL_CLOSE

/* These are the optional features this HAL does not provide. */
// #define HAGL_HAS_HAL_HLINE
// #define HAGL_HAS_HAL_VLINE
// #define HAGL_HAS_HAL_BLIT
// #define HAGL_HAS_HAL_SCALE_BLIT

/** HAL must provide typedef for colors. This HAL uses RGB565. */
typedef uint16_t color_t;

/**
 * @brief Draw a single pixel
 *
 * This is the only mandatory function HAL must provide.
 *
 * @param x0 X coordinate
 * @param y0 Y coorginate
 * @param color color
 */
void hagl_hal_put_pixel(int16_t x0, int16_t y0, color_t color);

/**
 * @brief Initialize the HAL
 *
 * Initialises all hardware and possible memory buffers needed
 * to draw and display an image. If HAL uses double or triple
 * buffering should return a pointer to current back buffer.
 * This HAL does not use buffering so it returns NULL instead.
 *
 * @return pointer to bitmap_t or NULL
 */
bitmap_t *hagl_hal_init(void);

/**
 * @brief Output the image
 *
 * This is used for HAL implementations which do not display
 * the drawn pixels automatically. Call this function always when
 * you have finished rendering.
 */
void hagl_hal_flush();

/**
 * @brief Close and clean up the HAL
 *
 * This is used for HAL implementations which need some cleanup, such
 * as deallocating memory, to be done when closing the program.
 */
void hagl_hal_close();

#ifdef __cplusplus
}
#endif
#endif /* _HAGL_GD_HAL_H */