#include QMK_KEYBOARD_H

enum boardwalk_layers {
    QWERTY,
    SWE,
    LOWER,
    RAISE,
    ADJUST,
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_SWE,
    KC_LOWER,
    KC_RAISE,
    KC_ADJUST,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_DLINE
};


// Mac sleep
#define SLEEP S(LCTL(KC_POWER))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [QWERTY] = LAYOUT_ortho_hhkb(
  KC_GRV,         KC_1,           KC_2,           KC_3,    KC_4,    KC_5,    KC_MINS, KC_EQL,  KC_6,    KC_7,     KC_8,    KC_9,    KC_0,    KC_BSPC,  \
  KC_TAB,         KC_Q,           KC_W,           KC_E,    KC_R,    KC_T,    KC_LBRC, KC_RBRC, KC_Y,    KC_U,     KC_I,    KC_O,    KC_P,    KC_DEL, \
  LCTL_T(KC_ESC), KC_A,           KC_S,           KC_D,    KC_F,    KC_G,    KC_DOWN, KC_UP,   KC_H,    KC_J,     KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  LSFT_T(KC_F12), KC_Z,           KC_X,           KC_C,    KC_V,    KC_B,    KC_LEFT, KC_RGHT, KC_N,    KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,  \
                  LGUI_T(KC_F13), LALT_T(KC_F16), KC_LCTL, KC_LOWER,     KC_SPC,           KC_ENT,      KC_RAISE, KC_SWE,  KC_F14,  KC_F15
  ),

  [SWE] = LAYOUT_ortho_hhkb(
  KC_GRV,         KC_1,           KC_2,           KC_3,    KC_4,    KC_5,    KC_MINS, KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,          KC_BSPC,  \
  KC_TAB,         KC_Q,           KC_W,           KC_E,    KC_R,    KC_T,    KC_LBRC, KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,          LALT(KC_LBRC), \
  LCTL_T(KC_ESC), KC_A,           KC_S,           KC_D,    KC_F,    KC_G,    KC_DOWN, KC_UP,   KC_H,    KC_J,    KC_K,    KC_L,    LALT(KC_SCLN), LALT(KC_QUOT), \
  LSFT_T(KC_F12), KC_Z,           KC_X,           KC_C,    KC_V,    KC_B,    KC_LEFT, KC_RGHT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,       KC_ENT,  \
                  LGUI_T(KC_F13), LALT_T(KC_F16), KC_LCTL, KC_LOWER,     KC_SPC,           KC_ENT,      KC_RAISE,   KC_QWERTY,     KC_F14,        KC_F15
  ),

  [LOWER] = LAYOUT_ortho_hhkb(
  _______, KC_F1,   KC_F2,         KC_F3,   KC_F4,       KC_F5,   KC_PAUS, KC_NLCK, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, \
  _______, _______, LGUI(KC_DOWN), KC_UP,   LGUI(KC_UP), _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, KC_LEFT,       KC_DOWN, KC_RGHT,     _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
  _______, _______, _______,       _______, _______,     _______, _______, _______, _______, _______, KC_COLN, KC_DQUO, _______, _______, \
           _______, _______,       _______, _______,           KC_DEL,        KC_BSPC,       _______, _______, _______, _______
  ),

  [RAISE] = LAYOUT_ortho_hhkb(
  _______, KC_F1,      KC_F2,         KC_F3,      KC_F4,        KC_F5,   _______, _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, \
  _______, _______,    LCTL(KC_MINS), KC_LEND,    RCS(KC_MINS), _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, KC_DLINE,   KC_PRVWD,      KC_LSTRT,   KC_NXTWD,     _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
  _______, LGUI(KC_Z), LGUI(KC_X),    LGUI(KC_C), LGUI(KC_V),   _______, _______, _______, _______, _______, KC_SCLN, KC_QUOT, _______, _______, \
           _______     _______,   　  _______,    _______,       　　  KC_DEL,         KC_BSPC,      _______, _______, _______, _______
  ),

  [ADJUST] = LAYOUT_ortho_hhkb(
  SLEEP,   _______, _______, _______, _______, _______, RGB_TOG, RGB_MOD, _______, _______, _______, _______, _______, _______, \
  _______, RESET,   _______, KC_MPRV, KC_MNXT, _______, RGB_SAI, RGB_HUI, _______, _______, _______, _______, _______, _______, \
  _______, KC_VOLD, KC_VOLU, KC_MUTE, KC_MPLY, CG_TOGG, RGB_SAD, RGB_HUD, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, \
  _______, KC_F17,  KC_F18,  KC_F19,  KC_F10, _______,  RGB_VAD, RGB_VAI, _______, _______, _______, _______, _______, _______, \
           _______, _______, _______, _______,       _______,         _______,     _______, _______, _______, _______
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(QWERTY);
            }
            return false;
        case KC_SWE:
            if (record->event.pressed) {
                set_single_persistent_default_layer(SWE);
            }
            return false;
        case KC_LOWER:
            if (record->event.pressed) {
                layer_on(LOWER);
                update_tri_layer(LOWER, RAISE, ADJUST);
            } else {
                layer_off(LOWER);
                update_tri_layer(LOWER, RAISE, ADJUST);
            }
            return false;
        case KC_RAISE:
            if (record->event.pressed) {
                layer_on(RAISE);
                update_tri_layer(LOWER, RAISE, ADJUST);
            } else {
                layer_off(RAISE);
                update_tri_layer(LOWER, RAISE, ADJUST);
            }
            return false;
        case KC_ADJUST:
            if (record->event.pressed) {
                layer_on(ADJUST);
            } else {
                layer_off(ADJUST);
            }
            return false;
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
             if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                     //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
        case KC_DLINE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_BSPC);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_BSPC);
            }
            break;
    }
    return true;
}