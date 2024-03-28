// Copyright 2024 amc (@amc)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define CAPS_WORD_IDLE_TIMEOUT 3000

//https://github.com/qmk/qmk_firmware/blob/master/docs/feature_rgblight.md
#define RGBLIGHT_LAYERS

//https://docs.qmk.fm/#/platformdev_rp2040?id=double-tap
// The double-tap reset mechanism is an alternate way in QMK to enter the embedded mass storage 
// UF2 boot-loader of the RP2040. It enables bootloader entry by a fast double-tap of the reset 
// pin on start up, which is similar to the behavior of AVR Pro Micros. This feature activated 
// by default for the Pro Micro RP2040 board, but has to be configured for other boards. 
// To activate it, add the following options to your keyboard
//#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET // Activates the double-tap behavior
//#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U // Timeout window in ms in which the double tap can occur.
 
 /*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
