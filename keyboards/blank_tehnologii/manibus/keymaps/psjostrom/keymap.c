#include QMK_KEYBOARD_H
#include "psjostrom.h"

//Tap Dance Declarations
enum {
  SHIFT_CAPS = 0
};

//Tap Dance Definitions
tap_dance_action_t tap_dance_actions[] = {
  // Tap once/hold for Shift, tap twice for Caps Lock
  [SHIFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LY_BASE] = LAYOUT(
    KC_GRV,         KC_1,    KC_2,    KC_3,   KC_4,        KC_5,                           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
    KC_TAB,         KC_Q,    KC_W,    KC_E,   KC_R,        KC_T,                           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_EQL,
    LALT_T(KC_ESC), KC_A,    KC_S,    KC_D,   KC_F,        KC_G,                           KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    TD(SHIFT_CAPS), KC_Z,    KC_X,    KC_C,   KC_V,        KC_B,                           KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
    KC_F13,         KC_LCTL, KC_LGUI, KC_LOG, KC_COPYPATH, KC_SPACE, KC_DEL,       KC_ENT, KC_BSPC, LOWER,   KC_LBRC, KC_RBRC, XXXXXXX, SWE
  ),

  [LY_SWE] = LAYOUT(
    KC_GRV,         KC_1,    KC_2,    KC_3,   KC_4,        KC_5,                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
    KC_TAB,         KC_Q,    KC_W,    KC_E,   KC_R,        KC_T,                            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_AA,
    LALT_T(KC_ESC), KC_A,    KC_S,    KC_D,   KC_F,        KC_G,                            KC_H,    KC_J,    KC_K,    KC_L,    KC_OE,   KC_AE,
    TD(SHIFT_CAPS), KC_Z,    KC_X,    KC_C,   KC_V,        KC_B,                            KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
    KC_F13,         KC_LCTL, KC_LGUI, KC_LOG, KC_COPYPATH, KC_SPACE, KC_DEL,        KC_ENT, KC_BSPC, LOWER,   KC_LBRC, KC_RBRC, XXXXXXX, BASE
  ),

  [LY_LOWER] = LAYOUT(
    QK_BOOT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                             KC_F6,      KC_F7,     KC_F8,   KC_F9,    KC_F10,  KC_F11,
    QK_RBT,  _______, _______, _______, _______, KC_LINESTART,                      KC_LINEEND, _______,   KC_UP,   _______,  _______, KC_F12,
    _______, _______, _______, KC_BACK, KC_FORW, KC_PRVWD,                          KC_NXTWD,   KC_LEFT,   KC_DOWN, KC_RIGHT, KC_VOLD, KC_VOLU,
    _______, _______, _______, _______, _______, KC_MVAPPL,                         KC_MVAPPR,  KC_MAXAPP, KC_COLN, KC_DQUO,  KC_SCLN, KC_QUOT,
    _______, KC_PGUP, _______, _______, _______, _______,   _______,       _______, _______,    _______,   _______, _______,  KC_PGDN, _______
  )
};
