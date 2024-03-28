// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Qwerty
     * ,-----------------------------------------------------------------------------------.
     * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  Up  | shift|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Ctrl |  FN  | Win  | ALT  |Lower | Enter| Space|Raise |   /  | Left | Down |Right |
     * `-----------------------------------------------------------------------------------'
     */
    [0] = LAYOUT_ortho_4x12(
        QK_GESC, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_RSFT,  
        KC_LCTL, MO(3),  KC_LGUI, KC_LALT, MO(1),   KC_ENT,  KC_SPC,  MO(2),   KC_SLASH, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [1] = LAYOUT_ortho_4x12( // UPPER
        _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,     KC_0, KC_DEL,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  KC_MINS, KC_EQL,
        _______, _______, _______, _______, _______, _______, _______, KC_INS,  KC_LBRC, KC_RBRC, KC_PGUP, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_NUBS, KC_HOME, KC_PGDN, KC_END
    ),
    [2] = LAYOUT_ortho_4x12(  // LOWER
        _______, KC_F1  ,  KC_F2 ,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9, KC_F10 , KC_F11 ,
        KC_PSCR, DM_REC1, DM_REC2, DM_RSTP, _______, _______, _______, _______, _______, _______, _______, KC_F12 ,
        _______, DM_PLY1, DM_PLY2, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_NUHS, KC_WBAK, _______, KC_WFWD
    ),
    [3] = LAYOUT_ortho_4x12( // FUNCTION
        RGB_M_T, RGB_M_P , RGB_M_B, RGB_M_R,RGB_M_SW,RGB_M_SN, RGB_M_K, RGB_M_X, _______, KC_MUTE, KC_VOLD, KC_VOLU,
        _______, RGB_TOG , RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______, _______, _______, _______, _______,
        _______, _______ ,RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, _______, _______, _______, KC_BTN1, KC_MS_U, KC_BTN2,
        _______, _______ , _______, _______, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R
    ),


};
/*
// Light LEDs 6 to 9 and 12 to 15 red when caps lock is active. Hard to ignore!
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {6, 4, HSV_RED},       // Light 4 LEDs, starting with LED 6
    {12, 4, HSV_RED}       // Light 4 LEDs, starting with LED 12
);
// Light LEDs 9 & 10 in cyan when keyboard layer 1 is active
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 5, HSV_CYAN}
);
// Light LEDs 11 & 12 in purple when keyboard layer 2 is active
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 5, HSV_PURPLE}
);
// Light LEDs 13 & 14 in green when keyboard layer 3 is active
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 5, HSV_GREEN}

/////////////////////////////////////////

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer,
    my_layer1_layer,    // Overrides caps lock layer
    my_layer2_layer,    // Overrides other layers
    my_layer3_layer     // Overrides other layers
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

///////////////////////////////////


void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, _DVORAK));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(2, layer_state_cmp(state, _FN));
    rgblight_set_layer_state(3, layer_state_cmp(state, _ADJUST));
    return state;
}
*/