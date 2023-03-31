 #include QMK_KEYBOARD_H
 #include "psjostrom.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LY_BASE] = LAYOUT(
        KC_GRV,         KC_1,            KC_2,           KC_3,    KC_4,     KC_5,              KC_6,   KC_7,     KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,         KC_Q,            KC_W,           KC_E,    KC_R,     KC_T,              KC_Y,   KC_U,     KC_I,    KC_O,    KC_P,    KC_DEL,
        LCTL_T(KC_ESC), KC_A,            KC_S,           KC_D,    KC_F,     KC_G,              KC_H,   KC_J,     KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        LSFT_T(KC_F12), KC_Z,            KC_X,           KC_C,    KC_V,     KC_B,   MUTE_ZOOM, KC_N,   KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
        KC_PSCR,        LGUI_T(KC_PSCR), LALT_T(KC_F16), KC_LCTL, KC_LOWER, KC_SPC, KC_SWE,    KC_ENT, KC_RAISE, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT
    ),
    [LY_SWE] = LAYOUT(
        KC_GRV,         KC_1,            KC_2,           KC_3,    KC_4,     KC_5,              KC_6,   KC_7,     KC_8,    KC_9,    KC_0,          KC_BSPC,
        KC_TAB,         KC_Q,            KC_W,           KC_E,    KC_R,     KC_T,              KC_Y,   KC_U,     KC_I,    KC_O,    KC_P,          LALT(KC_LBRC),
        LCTL_T(KC_ESC), KC_A,            KC_S,           KC_D,    KC_F,     KC_G,              KC_H,   KC_J,     KC_K,    KC_L,    LALT(KC_SCLN), LALT(KC_QUOT),
        LSFT_T(KC_F12), KC_Z,            KC_X,           KC_C,    KC_V,     KC_B,   MUTE_ZOOM, KC_N,   KC_M,     KC_COMM, KC_DOT,  KC_SLSH,       KC_ENT,
        KC_PSCR,        LGUI_T(KC_PSCR), LALT_T(KC_F16), KC_LCTL, KC_LOWER, KC_SPC, KC_BASE,   KC_ENT, KC_RAISE, KC_LEFT, KC_DOWN, KC_UP,         KC_RIGHT
    ),
    [LY_LOWER] = LAYOUT(
        KC_CAPS, KC_F1,      KC_F2,         KC_F3,   KC_F4,        KC_F5,            KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
        _______, _______,    LGUI(KC_DOWN), KC_UP,   LGUI(KC_UP),  _______,          _______, _______, _______, _______, _______, _______,
        _______, A(G(KC_C)), KC_LEFT,       KC_DOWN, KC_RGHT,      _______,          _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
        _______, _______,    _______,       _______, C(G(KC_SPC)), _______, _______, _______, _______, KC_COLN, KC_DQUO, _______, _______,
        _______, _______,    _______,       _______, _______,      KC_DEL,  _______, KC_BSPC, _______, _______, _______, _______, _______
    ),

    [LY_RAISE] = LAYOUT(
        _______, KC_F1,      KC_F2,         KC_F3,      KC_F4,        KC_F5,            KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, _______,
        _______, _______,    LCTL(KC_MINS), KC_LEND,    RCS(KC_MINS), _______,          _______, _______, _______, _______, _______, _______,
        _______, KC_DLINE,   KC_PRVWD,      KC_LSTRT,   KC_NXTWD,     _______,          _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
        _______, LGUI(KC_Z), LGUI(KC_X),    LGUI(KC_C), C(G(KC_A)),   _______, _______, _______, _______, KC_SCLN, KC_QUOT, _______, _______,
        _______, _______,    _______,       _______,    _______,      KC_DEL,  _______, KC_BSPC, _______, _______, _______, _______, _______
    ),
    [LY_ADJUST] = LAYOUT(
        SLEEP,   _______,    _______, _______, _______, _______,          RGB_TOG,  RGB_MOD,RGB_SAD, RGB_SAI,  RGB_HUD, RGB_HUI,
        _______, RESET,      _______, KC_MPRV, KC_MNXT, _______,          _______,  _______, _______, _______, RGB_VAD, RGB_VAI,
        _______, KC_VOLD,    KC_VOLU, KC_MUTE, KC_MPLY, CG_TOGG,          _______,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
        _______, C(G(KC_Z)), KC_F18,  KC_F19,  KC_F10, _______,  _______, _______,  _______, _______, _______, _______, _______,
        _______, _______,    _______, _______, _______, KC_BASE, _______, KC_SWE,   _______, _______, _______, _______, _______
  )
};

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    uint8_t layer = get_highest_layer(layer_state);  // special handling per layer
        if (layer == LY_LOWER) {
            encoder_action_volume(!clockwise);
        }
        else if (layer == LY_RAISE) {
            encoder_action_desktop_change(!clockwise);
        } else {
            encoder_action_vscode_nav(!clockwise);
        }
    return true;
}
#endif