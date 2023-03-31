#include QMK_KEYBOARD_H
#include "psjostrom.h"

// Start of underglow layer control
const rgblight_segment_t PROGMEM qwerty_layer[] = RGBLIGHT_LAYER_SEGMENTS(
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
    qwerty_layer,
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
  [LY_BASE] = LAYOUT(
  KC_GRV,         KC_1,    KC_2,    KC_3,    KC_4,     KC_5,   KC_6,   KC_7,     KC_8,    KC_9,    KC_0,    KC_BSPC,  \
  KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,   KC_Y,   KC_U,     KC_I,    KC_O,    KC_P,    KC_DEL, \
  LCTL_T(KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,     KC_G,   KC_H,   KC_J,     KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  LSFT_T(KC_F12), KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,   KC_N,   KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_SWE,  \
  KC_F13,         KC_LCTL, KC_LGUI, KC_LALT, KC_LOWER, KC_SPC, KC_ENT, KC_RAISE, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT
  ),

  [LY_SWE] = LAYOUT(
  KC_GRV,         KC_1,    KC_2,    KC_3,    KC_4,     KC_5,   KC_6,   KC_7,     KC_8,    KC_9,    KC_0,          KC_BSPC,  \
  KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,   KC_Y,   KC_U,     KC_I,    KC_O,    KC_P,          LALT(KC_LBRC), \
  LCTL_T(KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,     KC_G,   KC_H,   KC_J,     KC_K,    KC_L,    LALT(KC_SCLN), LALT(KC_QUOT), \
  LSFT_T(KC_F12), KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,   KC_N,   KC_M,     KC_COMM, KC_DOT,  KC_SLSH,       KC_BASE,  \
  KC_F13,         KC_LCTL, KC_LGUI, KC_LALT, KC_LOWER, KC_SPC, KC_ENT, KC_RAISE, KC_LEFT, KC_DOWN, KC_UP,         KC_RIGHT
  ),

  [LY_LOWER] = LAYOUT(
  KC_CAPS,   KC_F1,   KC_F2,         KC_F3,   KC_F4,        KC_F5,   KC_F6,   KC_F7,    KC_F8,   KC_F9,   KC_F10,  XXXXXXX, \
  XXXXXXX,   XXXXXXX, LGUI(KC_DOWN), KC_UP,   LGUI(KC_UP),  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  MUTE_ZOOM, XXXXXXX, KC_LEFT,       KC_DOWN, KC_RGHT,      KC_BASE, KC_SWE,  KC_UNDS,  KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
  XXXXXXX,   KC_F19,  KC_F10,        XXXXXXX, C(G(KC_SPC)), XXXXXXX, XXXXXXX, XXXXXXX,  KC_COLN, KC_DQUO, XXXXXXX, XXXXXXX, \
  XXXXXXX,   XXXXXXX, XXXXXXX,       XXXXXXX, KC_LOWER,     XXXXXXX, XXXXXXX, KC_RAISE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [LY_RAISE] = LAYOUT(
  XXXXXXX, KC_F1,      KC_F2,         KC_F3,      KC_F4,        KC_F5,   KC_F6,   KC_F7,    KC_F8,   KC_F9,   KC_F10,  XXXXXXX, \
  XXXXXXX, XXXXXXX,    LCTL(KC_MINS), KC_LEND,    RCS(KC_MINS), XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, KC_DLINE,   KC_PRVWD,      KC_LSTRT,   KC_NXTWD,     KC_BASE, KC_SWE,  KC_MINS,  KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
  XXXXXXX, LGUI(KC_Z), LGUI(KC_X),    LGUI(KC_C), C(G(KC_A)),   XXXXXXX, XXXXXXX, XXXXXXX,  KC_SCLN, KC_QUOT, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX,    XXXXXXX,       XXXXXXX,    KC_LOWER,     XXXXXXX, XXXXXXX, KC_RAISE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [LY_ADJUST] = LAYOUT(
  SLEEP,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, RGB_TOG, RGB_MOD,  RGB_SAD, RGB_SAI, RGB_HUD, RGB_HUI, \
  XXXXXXX, RESET,   XXXXXXX, KC_MPRV, KC_MNXT,  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, RGB_VAD, RGB_VAI, \
  XXXXXXX, KC_VOLD, KC_VOLU, KC_MUTE, KC_MPLY,  AG_TOGG, XXXXXXX, KC_LEFT,  KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, \
  XXXXXXX, KC_F17,  KC_F18,  KC_F19,  KC_F10,   XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LOWER, KC_BASE, KC_SWE,  KC_RAISE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  )
};