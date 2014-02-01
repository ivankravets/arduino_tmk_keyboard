/*
Copyright 2013 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef TMK_DEBUG_CONFIG_H
#define TMK_DEBUG_CONFIG_H 1

#include <stdbool.h>


#ifdef __cplusplus
extern "C" {
#endif

/* NOTE: Not portable. Bit field order depends on implementation */
typedef union {
    uint8_t raw;
    struct {
        bool enable:1;
        bool matrix:1;
        bool keyboard:1;
        bool mouse:1;
        uint8_t reserved:4;
    };
} tmk_debug_config_t;
extern tmk_debug_config_t tmk_debug_config;

#ifndef __cplusplus
tmk_debug_config_t debug_config;
#endif

/* for backward compatibility */
//#define tmk_debug_enable    (tmk_debug_config.enable)
//#define tmk_debug_matrix    (tmk_debug_config.matrix)
#define tmk_debug_keyboard  (debug_config.keyboard)
//#define tmk_debug_mouse     (tmk_debug_config.mouse)

#ifdef __cplusplus
}
#endif

#endif
