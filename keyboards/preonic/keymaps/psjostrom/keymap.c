#include QMK_KEYBOARD_H
#include "psjostrom.h"

// Start of underglow layer control
const rgblight_segment_t PROGMEM base_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    // BASE = Blue underglow
    {0, 12, HSV_BLUE}
);

const rgblight_segment_t PROGMEM swe_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    // SWE = White underglow
    {0, 12, HSV_WHITE}
);

const rgblight_segment_t PROGMEM lower_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    // LOWER = Red underglow
    {0, 12, HSV_RED}
);

const rgblight_segment_t PROGMEM raise_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    // RAISE = Orange underglow
    {0, 12, HSV_ORANGE}
);

const rgblight_segment_t PROGMEM adjust_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    // ADJUST = Light green underglow
    {0, 12, HSV_SPRINGGREEN}
);

const rgblight_segment_t* const PROGMEM underglow_layers[] = RGBLIGHT_LAYERS_LIST(
    base_layer,
    swe_layer,
    lower_layer,
    raise_layer,
    adjust_layer

);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = underglow_layers;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, LY_BASE));
    rgblight_set_layer_state(1, layer_state_cmp(state, LY_SWE));

    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(2, layer_state_cmp(state, LY_LOWER));
    rgblight_set_layer_state(3, layer_state_cmp(state, LY_RAISE));
    rgblight_set_layer_state(4, layer_state_cmp(state, LY_ADJUST));

    return state;
}
// End of underglow layer control

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LY_BASE] = LAYOUT_preonic_grid(
  KC_GRV,         KC_1,           KC_2,    KC_3,    KC_4,     KC_5,   KC_6,   KC_7,     KC_8,    KC_9,    KC_0,    KC_BSPC,  \
  KC_TAB,         KC_Q,           KC_W,    KC_E,    KC_R,     KC_T,   KC_Y,   KC_U,     KC_I,    KC_O,    KC_P,    KC_DEL, \
  LCTL_T(KC_ESC), KC_A,           KC_S,    KC_D,    KC_F,     KC_G,   KC_H,   KC_J,     KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  LSFT_T(KC_F12), KC_Z,           KC_X,    KC_C,    KC_V,     KC_B,   KC_N,   KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,  \
  KC_F13,         LGUI_T(KC_F16), KC_LALT, KC_LCTL, KC_LOWER, KC_SPC, KC_SPC, KC_RAISE, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT
  ),

  [LY_SWE] = LAYOUT_preonic_grid(
  KC_GRV,         KC_1,           KC_2,    KC_3,    KC_4,     KC_5,   KC_6,   KC_7,     KC_8,    KC_9,    KC_0,          KC_BSPC,  \
  KC_TAB,         KC_Q,           KC_W,    KC_E,    KC_R,     KC_T,   KC_Y,   KC_U,     KC_I,    KC_O,    KC_P,          LALT(KC_LBRC), \
  LCTL_T(KC_ESC), KC_A,           KC_S,    KC_D,    KC_F,     KC_G,   KC_H,   KC_J,     KC_K,    KC_L,    LALT(KC_SCLN), LALT(KC_QUOT), \
  LSFT_T(KC_F12), KC_Z,           KC_X,    KC_C,    KC_V,     KC_B,   KC_N,   KC_M,     KC_COMM, KC_DOT,  KC_SLSH,       KC_ENT,  \
  KC_F13,         LGUI_T(KC_F16), KC_LALT, KC_LCTL, KC_LOWER, KC_SPC, KC_ENT, KC_RAISE, KC_LEFT, KC_DOWN, KC_UP,         KC_RIGHT
  ),

  [LY_LOWER] = LAYOUT_preonic_grid(
  KC_CAPS, KC_F1,   KC_F2,         KC_F3,   KC_F4,        KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, \
  _______, _______, LGUI(KC_DOWN), KC_UP,   LGUI(KC_UP),  _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, KC_LEFT,       KC_DOWN, KC_RGHT,      _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
  _______, _______, _______,       _______, C(G(KC_SPC)), _______, _______, _______, KC_COLN, KC_DQUO, _______, _______, \
  _______, _______, _______,       _______, _______,      KC_DEL,  KC_BSPC, _______, _______, _______, _______, _______
  ),

  [LY_RAISE] = LAYOUT_preonic_grid(
  _______, KC_F1,      KC_F2,         KC_F3,      KC_F4,        KC_F5,    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, _______, \
  _______, _______,    LCTL(KC_MINS), KC_LEND,    RCS(KC_MINS), _______, _______, _______, _______, _______, _______, _______, \
  _______, KC_DLINE,   KC_PRVWD,      KC_LSTRT,   KC_NXTWD,     _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
  _______, LGUI(KC_Z), LGUI(KC_X),    LGUI(KC_C), C(G(KC_A)),   _______, _______, _______, KC_SCLN, KC_QUOT, _______, _______, \
  _______, _______,    _______,       _______,    _______,      KC_DEL,  KC_BSPC, _______, _______, _______, _______, _______
  ),

  [LY_ADJUST] = LAYOUT_preonic_grid(
  SLEEP,   _______, _______, _______, _______, _______, RGB_TOG,  RGB_MOD,RGB_SAD, RGB_SAI,  RGB_HUD, RGB_HUI, \
  _______, RESET,   _______, KC_MPRV, KC_MNXT, AG_TOGG, _______,  _______, _______, _______, RGB_VAD, RGB_VAI, \
  _______, KC_VOLD, KC_VOLU, KC_MUTE, KC_MPLY, CG_TOGG, _______,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, \
  _______, KC_F17,  KC_F18,  KC_F19,  KC_F10, _______,  _______,  _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, KC_BASE, KC_SWE, _______, _______, _______, _______, EEPROM_RESET
  )
};

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    uint8_t layer = get_highest_layer(layer_state);
        if (layer == LY_LOWER) {
            encoder_action_vscode_nav(clockwise);
        }
        else if (layer == LY_RAISE) {
            encoder_action_desktop_change(clockwise);
        } else {
            encoder_action_volume(clockwise);
        }
    return true;
}
#endif