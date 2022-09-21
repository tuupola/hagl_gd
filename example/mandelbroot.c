/*

MIT No Attribution

Copyright (c) 2018-2022 Mika Tuupola

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

-cut-

SPDX-License-Identifier: MIT-0

*/

#include <time.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include <hagl.h>

int main()
{
    uint16_t max_x = DISPLAY_WIDTH;
    uint16_t max_y = DISPLAY_HEIGHT;
    uint16_t max_iters = 1024;

    uint16_t n = 0;
    uint16_t px, py;

    double x;
    double y;
    double x0;
    double y0;
    double xtemp;
    double zoom = 1.0;

    clock_t start;
    clock_t end;
    double time_spent;

    size_t bytes;
    color_t color;

    hagl_backend_t *window = hagl_init();

    start = clock();

    for (py = 1; py <= max_y; py++)  {
        for (px = 1; px <= max_x; px++)  {
            x0 = (((float) px) / ((float) max_x) - 0.5) / zoom * 3.0 - 0.7;
            y0 = (((float) py) / ((float) max_y) - 0.5) / zoom * 3.0;
            x = 0.0;
            y = 0.0;
            n = 0;

            while ((x * x + y * y < 4) && (n != max_iters)) {
                xtemp = x * x - y * y + x0;
                y = 2.0 * x * y + y0;
                x = xtemp;
                n++;
            }

            color = hagl_color(window, 0, n * 16, n * 16);
            if (n < max_iters) {
                hagl_put_pixel(window, px, py, color);
            } else {
                hagl_put_pixel(window, px, py, 0);
            }
        }
    }

    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    bytes = hagl_flush(window);
    printf("\nGenerated %zu bytes in %g seconds.\n\n", bytes, time_spent);
    hagl_close(window);

    return 0;
}
