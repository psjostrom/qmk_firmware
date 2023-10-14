#include QMK_KEYBOARD_H
#include "psjostrom.h"

// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//   [LY_BASE] = LAYOUT(
//     KC_GRV,         KC_1,    KC_2,    KC_3,   KC_4,        KC_5,                           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
//     KC_TAB,         KC_Q,    KC_W,    KC_E,   KC_R,        KC_T,                           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_EQL,
//     LALT_T(KC_ESC), KC_A,    KC_S,    KC_D,   KC_F,        KC_G,                           KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
//     TD(SHIFT_CAPS), KC_Z,    KC_X,    KC_C,   KC_V,        KC_B,                           KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
//     KC_F13,         KC_LCTL, KC_LGUI, KC_LOG, KC_COPYPATH, KC_SPACE, KC_DEL,       KC_ENT, KC_BSPC, LOWER,   KC_LBRC, KC_RBRC, XXXXXXX, SWE
//   ),

//   [LY_SWE] = LAYOUT(
//     KC_GRV,         KC_1,    KC_2,    KC_3,   KC_4,        KC_5,                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
//     KC_TAB,         KC_Q,    KC_W,    KC_E,   KC_R,        KC_T,                            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_AA,
//     LALT_T(KC_ESC), KC_A,    KC_S,    KC_D,   KC_F,        KC_G,                            KC_H,    KC_J,    KC_K,    KC_L,    KC_OE,   KC_AE,
//     TD(SHIFT_CAPS), KC_Z,    KC_X,    KC_C,   KC_V,        KC_B,                            KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
//     KC_F13,         KC_LCTL, KC_LGUI, KC_LOG, KC_COPYPATH, KC_SPACE, KC_DEL,        KC_ENT, KC_BSPC, LOWER,   KC_LBRC, KC_RBRC, XXXXXXX, BASE
//   ),

//   [LY_LOWER] = LAYOUT(
//     QK_BOOT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                             KC_F6,      KC_F7,     KC_F8,   KC_F9,    KC_F10,  KC_F11,
//     QK_RBT,  _______, _______, _______, _______, KC_LINESTART,                      KC_LINEEND, _______,   KC_UP,   _______,  _______, KC_F12,
//     _______, _______, _______, KC_BACK, KC_FORW, KC_PRVWD,                          KC_NXTWD,   KC_LEFT,   KC_DOWN, KC_RIGHT, KC_VOLD, KC_VOLU,
//     _______, _______, _______, _______, _______, KC_MVAPPL,                         KC_MVAPPR,  KC_MAXAPP, KC_COLN, KC_DQUO,  KC_SCLN, KC_QUOT,
//     _______, KC_PGUP, _______, _______, _______, _______,   _______,       _______, _______,    _______,   _______, _______,  KC_PGDN, _______
//   )
// };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LY_BASE] = LAYOUT(
    KC_GRV,         KC_1,    KC_2,    KC_3,   KC_4,        KC_5,                               KC_6,    KC_7,  KC_8,    KC_9,    KC_0,    KC_BSPC,  \
    KC_TAB,         KC_Q,    KC_W,    KC_E,   KC_R,        KC_T,                               KC_Y,    KC_U,  KC_I,    KC_O,    KC_P,    KC_DEL, \
    LALT_T(KC_ESC), KC_A,    KC_S,    KC_D,   KC_F,        KC_G,                               KC_H,    KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_LSFT,        KC_Z,    KC_X,    KC_C,   KC_V,        KC_B,                               KC_N,    KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_LALT,  \
    KC_F13,         KC_LCTL, KC_LGUI, KC_LOG, KC_COPYPATH, KC_SPACE, KC_LBRC,         KC_RBRC, KC_ENT, LOWER, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT
  ),

  [LY_SWE] = LAYOUT(
    KC_GRV,         KC_1,    KC_2,    KC_3,   KC_4,        KC_5,                               KC_6,    KC_7,  KC_8,    KC_9,    KC_0,    KC_BSPC,  \
    KC_TAB,         KC_Q,    KC_W,    KC_E,   KC_R,        KC_T,                               KC_Y,    KC_U,  KC_I,    KC_O,    KC_P,    KC_AA, \
    LALT_T(KC_ESC), KC_A,    KC_S,    KC_D,   KC_F,        KC_G,                               KC_H,    KC_J,  KC_K,    KC_L,    KC_OE,   KC_AE, \
    KC_LSFT,        KC_Z,    KC_X,    KC_C,   KC_V,        KC_B,                               KC_N,    KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_LALT,  \
    KC_F13,         KC_LCTL, KC_LGUI, KC_LOG, KC_COPYPATH, KC_SPACE, KC_LBRC,         KC_RBRC, KC_ENT, LOWER, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT
  ),

  [LY_LOWER] = LAYOUT(
    QK_BOOTLOADER, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                    KC_F6,      KC_F7,     KC_F8,   KC_F9,     KC_F10,  XXXXXXX, \
    XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LINESTART,                             KC_LINEEND, XXXXXXX,   KC_UP,   XXXXXXX,   XXXXXXX, XXXXXXX, \
    KC_PIPE,       KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_PRVWD,                                 KC_NXTWD,   KC_LEFT,   KC_DOWN, KC_RIGHT,  XXXXXXX, KC_PIPE, \
    KC_F12,        KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_MVAPPL,                                KC_MVAPPR,  KC_MAXAPP, XXXXXXX, A(KC_DOT), XXXXXXX, XXXXXXX, \
    XXXXXXX,       XXXXXXX, XXXXXXX, BASE,    SWE,     KC_IOSSHAKE, KC_COLN,            KC_DQUO, XXXXXXX,    RAISE,     XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX
  ),
  };