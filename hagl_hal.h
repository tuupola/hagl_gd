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

#ifndef _HAGL_GD_HAL_H
#define _HAGL_GD_HAL_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <hagl/backend.h>
#include <hagl/color.h>

/* HAL must provide display dimensions and depth. This HAL */
/* defaults to 320x240. Alternative dimensions can be passed */
/* using compiler flags. */
#ifndef DISPLAY_WIDTH
#define DISPLAY_WIDTH   (320)
#endif
#ifndef DISPLAY_HEIGHT
#define DISPLAY_HEIGHT  (240)
#endif
#define DISPLAY_DEPTH   (24)

/** HAL must provide typedef for colors. This HAL uses RGB888. */
typedef uint32_t color_t;

/**
 * @brief Initialize the backend
 */
void
hagl_hal_init(hagl_backend_t *backend);

/**
 * @brief Convert RGB to HAL color type
 *
 * This is used for HAL implementations which use some other pixel
 * format than RGB565.
 */
// static inline color_t hagl_hal_color(uint8_t r, uint8_t g, uint8_t b) {
//     return (r << 16) | (g << 8) | (b);
// }

#ifdef __cplusplus
}
#endif
#endif /* _HAGL_GD_HAL_H */
