/* Copyright 2021 SamuraiKek
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "psjostrom.h"

/*
    L00, L01, L02, L03, L04, L05,           R00, R01, R02, R03, R04, R05,
    L10, L11, L12, L13, L14, L15,           R10, R11, R12, R13, R14, R15,
    L20, L21, L22, L23, L24, L25,           R20, R21, R22, R23, R24, R25,
    L30, L31, L32, L33, L34, L35,           R30, R31, R32, R33, R34, R35,
    L40, L41, L42, L43, L44, L45, L46, R40, R41, R42, R43, R44, R45, R46,

    [_UNIVERSAL] = LAYOUT(
    //   ┌────────┬────────┬────────┬────────┬────────┬────────┐                       ┌────────┬────────┬────────┬────────┬────────┬────────┐
          _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
    //   ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
          _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
    //   ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
          _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
    //   ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
          _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
    //   ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐     ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
          _______, _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______, _______
    //   └────────┴────────┴────────┴────────┴────────┴────────┴────────┘     └────────┴────────┴────────┴────────┴────────┴────────┴────────┘
      )

*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [LY_BASE] = LAYOUT(
//   ┌────────┬────────┬────────┬────────┬────────┬────────┐                       ┌────────┬────────┬────────┬────────┬────────┬────────┐
      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
//   ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_EQL,
//   ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                            KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
//   ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                            KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
//   ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐     ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      KC_F13,  KC_HOME, KC_LCTL, KC_LALT, KC_LGUI, KC_SPACE, MOUSE,         KC_ENT,  KC_BSPC, LOWER,   KC_LBRC, KC_RBRC, KC_END,  SWE
//   └────────┴────────┴────────┴────────┴────────┴────────┴────────┘     └────────┴────────┴────────┴────────┴────────┴────────┴────────┘
  ),

    [LY_SWE] = LAYOUT(
//   ┌────────┬────────┬────────┬────────┬────────┬────────┐                       ┌────────┬────────┬────────┬────────┬────────┬────────┐
      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
//   ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_AA,
//   ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                            KC_H,    KC_J,    KC_K,    KC_L,    KC_OE,   KC_AE,
//   ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                            KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
//   ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐     ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      KC_F13,  KC_HOME, KC_LCTL, KC_LALT, KC_LGUI, KC_SPACE, MOUSE,         KC_ENT,  KC_BSPC, LOWER,   KC_LBRC, KC_RBRC, KC_END,  BASE
//   └────────┴────────┴────────┴────────┴────────┴────────┴────────┘     └────────┴────────┴────────┴────────┴────────┴────────┴────────┘
  ),

  [LY_LOWER] = LAYOUT(
//   ┌────────┬────────┬────────┬────────┬────────┬────────┐                       ┌────────┬────────┬────────┬────────┬────────┬────────┐
      QK_BOOT, KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,                          KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
//   ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
      QK_RBT,  _______, _______, _______, _______,  _______,                        _______, _______, KC_UP,   _______, _______, KC_F12,
//   ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
      _______, _______, _______, KC_BACK, KC_FORW, KC_PRVWD,                        KC_NXTWD,KC_LEFT, KC_DOWN, KC_RIGHT,KC_VOLD, KC_VOLU,
//   ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
      _______, _______, _______, _______, _______, KC_MVAPPL,                       KC_MVAPPR,KC_MAXAPP,KC_COLN,KC_DQUO,KC_SCLN, KC_QUOT,
//   ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐     ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      _______, KC_PGUP, _______, _______, _______, KC_DEL,  KC_DEL,        _______, _______, _______, _______,  _______, KC_PGDN, _______
//   └────────┴────────┴────────┴────────┴────────┴────────┴────────┘     └────────┴────────┴────────┴────────┴────────┴────────┴────────┘
  ),

  [LY_MOUSE] = LAYOUT(
//   ┌────────┬────────┬────────┬────────┬────────┬────────┐                       ┌────────┬────────┬────────┬────────┬────────┬────────┐
      _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
//   ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
      _______, _______, _______, _______, _______, _______,                         _______, KC_WH_U, KC_MS_U, _______, _______, _______,
//   ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
      _______, _______, _______, _______, _______, _______,                         _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN2, KC_BTN3,
//   ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
      _______, _______, _______, _______, _______, _______,                         _______, KC_WH_D, KC_BTN2, _______, _______, _______,
//   ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐     ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      _______, _______, _______, _______, _______, _______, _______,       _______, KC_BTN1, _______, _______, _______, _______, _______
//   └────────┴────────┴────────┴────────┴────────┴────────┴────────┘     └────────┴────────┴────────┴────────┴────────┴────────┴────────┘
  ),
};
