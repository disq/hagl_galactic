/*

MIT License

Copyright (c) 2018-2022 Mika Tuupola
Copyright (c) 2022 Kemal Hadimli

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

This file is part of the Galactic HAL for the HAGL graphics library:
https://github.com/disq/hagl_galactic

SPDX-License-Identifier: MIT

*/

#include <stdio.h>
#include <stdint.h>
#include <hagl/backend.h>

#include "include/hagl_hal.h"

#include "pico/stdlib.h"
#include "libraries/pico_graphics/pico_graphics.hpp"
#include "galactic_unicorn.hpp"

using namespace pimoroni;

PicoGraphics_PenRGB888 graphics(53, 11, nullptr);
GalacticUnicorn galactic_unicorn;

static void
put_pixel(void *self, int16_t x0, int16_t y0, color_t color)
{
  uint8_t r = (color >> 16);
  uint8_t g = (color >> 8) & 0xFF;
  uint8_t b = color & 0xFF;
  graphics.set_pen(r, g, b);
  graphics.pixel(Point(x0 >> GALACTIC_PIXEL_DIVISOR_X, y0 >> GALACTIC_PIXEL_DIVISOR_Y));
}

static size_t
flush(void *self)
{
    galactic_unicorn.update(&graphics);
    return DISPLAY_WIDTH * DISPLAY_HEIGHT * DISPLAY_DEPTH / 8;
}

static void
close(void *self)
{
  graphics.clear();
}

static color_t
color(void *self, uint8_t r, uint8_t g, uint8_t b) {
    return (r << 16) | (g << 8) | (b);
}

void
hagl_hal_init(hagl_backend_t *backend)
{
    galactic_unicorn.init();
    graphics.set_pen(0, 0, 0);
    graphics.clear();

    backend->width = DISPLAY_WIDTH;
    backend->height = DISPLAY_HEIGHT;
    backend->depth = DISPLAY_DEPTH;
    backend->put_pixel = put_pixel;
    backend->color = color;

    backend->flush = flush;
    backend->close = close;

}
