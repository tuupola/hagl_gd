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
    color_t color;
    uint16_t x, y, r, g, b, bx, by;
    clock_t start, end;
    double time_spent;
    size_t bytes;

    hagl_backend_t *window = hagl_init();

    x = 1;
    y = 1;
    by = 0;
    bx = 0;

    start = clock();

    for (r = 0; r < 256; r++) {
        for (g = 0; g < 256; g++) {
            for (b = 0; b < 256; b++) {
                color = hagl_color(window, r, g, b);
                hagl_put_pixel(window, x + bx * 256, y + by * 256, color);
                x++;
            }
            y++;
            x = 0;
        }
        bx = (bx + 1) % 16;
        if (0 == bx) {
            by++;
        }
        y = 0;
    }

    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    bytes = hagl_flush(window);
    printf("\nGenerated %zu bytes in %g seconds.\n\n", bytes, time_spent);
    hagl_close(window);

    return 0;
}
