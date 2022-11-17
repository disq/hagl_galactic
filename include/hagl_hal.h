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

#ifndef _HAGL_GALACTIC_HAL_H
#define _HAGL_GALACTIC_HAL_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <hagl/backend.h>
#include <hagl/color.h>

/* HAL must provide display dimensions and depth. This HAL */
/* defaults to 106x22 which is twice the size of the hardware screen at 53x11.
 * Alternative dimensions can be passed using compiler flags. */
#ifndef DISPLAY_WIDTH
#define DISPLAY_WIDTH   (106)
#endif
#ifndef DISPLAY_HEIGHT
#define DISPLAY_HEIGHT  (22)
#endif
#define DISPLAY_DEPTH   (24)

/* Change these if you've changed the display width/height above.
 * These are used with shift (SAL) operation so 0 means no division and 1 means divide by 2. */
#ifndef GALACTIC_PIXEL_DIVISOR_X
#define GALACTIC_PIXEL_DIVISOR_X  (1)
#endif
#ifndef GALACTIC_PIXEL_DIVISOR_Y
#define GALACTIC_PIXEL_DIVISOR_Y  (1)
#endif

/** HAL must provide typedef for colors. This HAL uses RGB888. */
typedef uint32_t color_t;

/**
 * @brief Initialize the backend
 */
void
hagl_hal_init(hagl_backend_t *backend);

#ifdef __cplusplus
}
#endif
#endif /* _HAGL_GALACTIC_HAL_H */
