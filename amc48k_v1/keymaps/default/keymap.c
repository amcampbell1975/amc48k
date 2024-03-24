// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │ A │ B │ C │ D │ E │ F │ G │ H │ I │ J │ K │ L │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │ A │ B │ C │ D │ E │ F │ G │ H │ I │ J │ K │ L │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │ A │ B │ C │ D │ E │ F │ G │ H │ I │ J │ K │ L │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │ A │ B │ C │ D │ E │ F │ G │ H │ I │ J │ K │ L │
     * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
     */
    //[0] = LAYOUT_ortho_4x12(
    //    KC_A,    KC_B,    KC_C,    KC_D,    KC_E,    KC_F,    KC_G,    KC_H,    KC_I,    KC_J,    KC_K,    KC_L,
    //    KC_A,    KC_B,    KC_C,    KC_D,    KC_E,    KC_F,    KC_G,    KC_H,    KC_I,    KC_J,    KC_K,    KC_L,
    //    KC_A,    KC_B,    KC_C,    KC_D,    KC_E,    KC_F,    KC_G,    KC_H,    KC_I,    KC_J,    KC_K,    KC_L,
    //    KC_A,    KC_B,    KC_C,    KC_D,    KC_E,    KC_F,    KC_G,    KC_H,    KC_I,    KC_J,    KC_K,    KC_L
    //),
    
    /* Qwerty
     * ,-----------------------------------------------------------------------------------.
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Brite| Ctrl | Alt  | GUI  |Lower | Space| Space|Raise | Left | Down |  Up  |Right |
     * `-----------------------------------------------------------------------------------'
     */
    [0] = LAYOUT_ortho_4x12(
        QK_GESC, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_RSFT,  
        KC_LCTL, MO(3),  KC_LGUI, KC_LALT, MO(1),   KC_ENT,  KC_SPC,  MO(2),   KC_SLASH, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [1] = LAYOUT_ortho_4x12(
        _______,   KC_1,  KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,      KC_8,    KC_9,   KC_0,    KC_DEL ,
        _______,  KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,    KC_F8,   KC_F9,  KC_MINS, KC_EQL ,
        _______, KC_F10, KC_F11,   KC_F12,  _______, _______, _______, KC_INS,  KC_LBRC, KC_RBRC, KC_PGUP, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_BSLS, KC_HOME, KC_PGDN, KC_END
    ),
    [2] = LAYOUT_ortho_4x12(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_WBAK, _______, KC_WFWD
    ),
    [3] = LAYOUT_ortho_4x12(
        _______, KC_ACL0, KC_ACL1, KC_ACL2, _______, _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU,
        _______, BL_TOGG , BL_STEP, _______ , _______, _______, _______, _______, _______, _______, _______, _______,
        _______, RGB_TOG, RGB_MOD, _______, _______, _______, _______, _______, _______, KC_BTN1, KC_MS_U, KC_BTN2,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R
    ),


};
#define WS2812_LED_COUNT 48