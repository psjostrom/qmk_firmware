#include QMK_KEYBOARD_H
#include "psjostrom.h"

// ALT LAYOUT MANIBUS INSPIRED

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LY_BASE] = LAYOUT_ortho_5x12(
  KC_GRV,         KC_1,    KC_2,    KC_3,    KC_4,     KC_5,                   KC_6,   KC_7,     KC_8,    KC_9,    KC_0,    KC_MINS,  \
  KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,                   KC_Y,   KC_U,     KC_I,    KC_O,    KC_P,    KC_EQL, \
  KC_ESC,         KC_A,    KC_S,    KC_D,    KC_F,     KC_G,                   KC_H,   KC_J,     KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT,        KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,                   KC_N,   KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,  \
  KC_F13,         MOUSE,   KC_LCTL, KC_LALT, KC_LGUI,  KC_SPACE,               KC_ENT,  KC_BSPC, LOWER,   KC_LBRC, KC_RBRC, SWE
  ),

  [LY_SWE] = LAYOUT_ortho_5x12(
  KC_GRV,         KC_1,    KC_2,    KC_3,    KC_4,     KC_5,                   KC_6,   KC_7,     KC_8,    KC_9,    KC_0,          KC_MINS,  \
  KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,                   KC_Y,   KC_U,     KC_I,    KC_O,    KC_P,          KC_AA, \
  KC_ESC,         KC_A,    KC_S,    KC_D,    KC_F,     KC_G,                   KC_H,   KC_J,     KC_K,    KC_L,    KC_OE,         KC_AE, \
  KC_LSFT,        KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,                   KC_N,   KC_M,     KC_COMM, KC_DOT,  KC_SLSH,       KC_BSLS,  \
  KC_F13,         MOUSE,   KC_LCTL, KC_LALT, KC_LGUI,  KC_SPACE,               KC_ENT,  KC_BSPC, LOWER,   KC_LBRC, KC_RBRC,       BASE
  ),

  [LY_LOWER] = LAYOUT_ortho_5x12(
      QK_BOOT, KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
      QK_RBT,  _______, _______, _______, _______,  _______,                   _______, _______, KC_UP,   _______, _______, KC_F12,
      QK_CLEAR_EEPROM, _______, _______, KC_BACK, KC_FORW, KC_PRVWD,                   KC_NXTWD,KC_LEFT, KC_DOWN, KC_RIGHT,KC_VOLD, KC_VOLU,
      _______, _______, _______, _______, _______, KC_MVAPPL,                  KC_MVAPPR,KC_MAXAPP,KC_COLN,KC_DQUO,KC_SCLN, KC_QUOT,
      _______, _______, _______, _______, _______, KC_DEL,                     _______, _______, _______,  _______, _______, _______
  ),

  [LY_MOUSE] = LAYOUT_ortho_5x12(
      _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                    _______, KC_WH_U, KC_MS_U, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                    _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN2, KC_BTN3,
      _______, _______, _______, _______, _______, _______,                    _______, KC_WH_D, KC_BTN2, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                    KC_BTN1, _______, _______, _______, _______, _______
  )
};

/* const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LY_BASE] = LAYOUT_ortho_5x12(
  KC_GRV,         KC_1,    KC_2,    KC_3,    KC_4,     KC_5,                   KC_6,   KC_7,     KC_8,    KC_9,    KC_0,    KC_BSPC,  \
  KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,                   KC_Y,   KC_U,     KC_I,    KC_O,    KC_P,    KC_DEL, \
  KC_ESC,         KC_A,    KC_S,    KC_D,    KC_F,     KC_G,                   KC_H,   KC_J,     KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT,        KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,                   KC_N,   KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_SWE,  \
  KC_F13,         KC_LCTL, KC_LGUI, KC_LALT, KC_LOWER, KC_SPC,                 KC_ENT, KC_RAISE, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT
  ),

  [LY_SWE] = LAYOUT_ortho_5x12(
  KC_GRV,         KC_1,    KC_2,    KC_3,    KC_4,     KC_5,                   KC_6,   KC_7,     KC_8,    KC_9,    KC_0,          KC_BSPC,  \
  KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,                   KC_Y,   KC_U,     KC_I,    KC_O,    KC_P,          LALT(KC_LBRC), \
  KC_ESC,         KC_A,    KC_S,    KC_D,    KC_F,     KC_G,                   KC_H,   KC_J,     KC_K,    KC_L,    LALT(KC_SCLN), LALT(KC_QUOT), \
  KC_LSFT,        KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,                   KC_N,   KC_M,     KC_COMM, KC_DOT,  KC_SLSH,       KC_BASE,  \
  KC_F13,         KC_LCTL, KC_LGUI, KC_LALT, KC_LOWER, KC_SPC,                 KC_ENT, KC_RAISE, KC_LEFT, KC_DOWN, KC_UP,         KC_RIGHT
  ),

  [LY_LOWER] = LAYOUT_ortho_5x12(
  KC_CAPS,   KC_F1,      KC_F2,         KC_F3,   KC_F4,        KC_F5,            KC_F6,   KC_F7,    KC_F8,   KC_F9,   KC_F10,  XXXXXXX, \
  XXXXXXX,   C(G(KC_Z)), KC_F12,        KC_UP,   LGUI(KC_UP),  XXXXXXX,          XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  CW_TOGG,   XXXXXXX,    KC_LEFT,       KC_DOWN, KC_RGHT,      KC_DEL,           KC_BSPC, KC_UNDS,  KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
  XXXXXXX,   KC_F17,     KC_F18,        KC_F19,  C(G(KC_SPC)), KC_DEL,           KC_BSPC, XXXXXXX,  KC_COLN, KC_DQUO, XXXXXXX, XXXXXXX, \
  XXXXXXX,   XXXXXXX,    XXXXXXX,       XXXXXXX, KC_LOWER,     KC_DEL,           KC_BSPC, KC_RAISE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [LY_RAISE] = LAYOUT_ortho_5x12(
  XXXXXXX,   KC_F1,      KC_F2,         KC_F3,      KC_F4,        KC_F5,        KC_F6,   KC_F7,    KC_F8,   KC_F9,   KC_F10,  XXXXXXX, \
  XXXXXXX,   XXXXXXX,    LCTL(KC_MINS), KC_LEND,    RCS(KC_MINS), XXXXXXX,      XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  MUTE_ZOOM, KC_DLINE,   A(KC_LEFT),    KC_LSTRT,   A(KC_RIGHT),  KC_DEL,       KC_BSPC, KC_MINS,  KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
  XXXXXXX,   LGUI(KC_Z), LGUI(KC_X),    LGUI(KC_C), C(G(KC_A)),   KC_DEL,       KC_BSPC, XXXXXXX,  KC_SCLN, KC_QUOT, XXXXXXX, XXXXXXX, \
  XXXXXXX,   XXXXXXX,    XXXXXXX,       XXXXXXX,    KC_LOWER,     KC_DEL,       KC_BSPC, KC_RAISE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [LY_ADJUST] = LAYOUT_ortho_5x12(
  QK_BOOTLOADER,      XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,         RGB_TOG, RGB_MOD,  RGB_SAD, RGB_SAI, RGB_HUD, RGB_HUI, \
  XXXXXXX,            QK_CLEAR_EEPROM, XXXXXXX, KC_MPRV, KC_MNXT,  XXXXXXX,         XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, RGB_VAD, RGB_VAI, \
  XXXXXXX,            KC_VOLD,         KC_VOLU, KC_MUTE, KC_MPLY,  AG_TOGG,         XXXXXXX, KC_LEFT,  KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, \
  QK_AUTOCORRECT_ON,  KC_F17,          KC_F18,  KC_F19,  KC_F10,   XXXXXXX,         XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  QK_AUTOCORRECT_OFF, XXXXXXX,         XXXXXXX, XXXXXXX, KC_LOWER, KC_BASE,         KC_SWE,  KC_RAISE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  )
}; */