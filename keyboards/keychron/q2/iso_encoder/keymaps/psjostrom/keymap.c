#include QMK_KEYBOARD_H
#include "psjostrom.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LY_BASE] = LAYOUT_iso_68(
        KC_NUBS,  KC_1,       KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,      KC_EQL,       KC_BSPC,          KC_MUTE,
        KC_TAB,   KC_Q,       KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,      KC_RBRC,                        KC_DEL,
        KC_ESC,  KC_A,       KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,      KC_NUHS,      KC_ENT,           KC_BACK,
        KC_LSFT,  KC_GRV,     KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,                    KC_RSFT, KC_UP,
        KC_LCTL,  KC_LOPT,    KC_LCMD,                            KC_SPC,                             KC_RCMD, MO(LY_LOWER), MO(LY_RAISE), KC_LEFT, KC_DOWN, KC_RGHT),

    [LY_SWE] = LAYOUT_iso_68(
        KC_NUBS,  KC_1,       KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,          KC_MINS,       KC_EQL,        KC_BSPC,          KC_MUTE,
        KC_TAB,   KC_Q,       KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,          LALT(KC_LBRC), KC_RBRC,                         KC_DEL,
        KC_ESC,  KC_A,       KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    LALT(KC_SCLN), LALT(KC_QUOT), LALT(KC_NUHS), KC_ENT,           KC_BACK,
        KC_LSFT,  KC_GRV,     KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,        KC_SLSH,                      KC_RSFT, KC_UP,
        KC_LCTL,  KC_LOPT,    KC_LCMD,                            KC_SPC,                             KC_RALT,       MO(LY_LOWER),  MO(LY_RAISE),  KC_LEFT, KC_DOWN, KC_RGHT),

    [LY_LOWER] = LAYOUT_iso_68(
        KC_GRV,  KC_BRID, KC_BRIU, _______, _______, RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD,  KC_VOLU,  _______,          _______,
        RGB_TOG, RGB_MOD, RGB_VAI, RGB_HUI, RGB_SAI, RGB_SPI, _______, _______, _______, _______, _______, _______,  _______,                    _______,
        _______, RGB_RMOD,RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD, _______, _______, _______, _______, _______, _______,  _______,  _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, NK_TOGG, _______, _______, _______, _______,            _______, _______,
        _______, _______, _______,                            _______,                            _______, _______,  _______,  _______, _______, _______),

    [LY_RAISE] = LAYOUT_iso_68(
        QK_BOOT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,   _______,          _______,
        RGB_TOG, RGB_MOD, RGB_VAI, RGB_HUI, RGB_SAI, RGB_SPI, _______, _______, _______, _______, _______, _______,  _______,                    _______,
        _______, RGB_RMOD,RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD, _______, _______, _______, _______, _______, _______,  _______,  _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______, _______,
        _______, _______, _______,                            _______,                            _______, _______,  _______,  _______, _______, _______)
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [LY_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [LY_SWE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [LY_LOWER]     = { ENCODER_CCW_CW(_______, _______) },
    [LY_RAISE]     = { ENCODER_CCW_CW(_______, _______) },
};
#endif
