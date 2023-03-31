/* Copyright 2021 Kyle McCreery
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

// Start of underglow layer control
const rgblight_segment_t PROGMEM base_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    // BASE = Blue underglow
    {0, 8, 170, 255, 50}
);

const rgblight_segment_t PROGMEM fn1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    // FN1 = White underglow
    {0, 8, 0, 0, 50}
);

const rgblight_segment_t PROGMEM fn2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    // FN2 = Spring-green underglow
    {0, 8, 106, 255, 60}
);

const rgblight_segment_t* const PROGMEM underglow_layers[] = RGBLIGHT_LAYERS_LIST(
    base_layer,
    fn1_layer,
    fn2_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = underglow_layers;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, LY_BASE));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, LY_LOWER));
    rgblight_set_layer_state(2, layer_state_cmp(state, LY_RAISE));
    return state;
}
// End of underglow layer control

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [LY_BASE] = LAYOUT(
                      KC_F17,       KC_F18,  KC_F19,  KC_F10,
                      KC_ESC,       KC_PSLS, KC_PAST, KC_BSPC,
                      KC_P7,        KC_P8,   KC_P9,   KC_PMNS,
        KC_MUTE,      KC_P4,        KC_P5,   KC_P6,   KC_PPLS,
        MO(LY_RAISE), KC_P1,        KC_P2,   KC_P3,   KC_PENT,
        MO(LY_LOWER), KC_SPC,       KC_P0,   KC_DOT,  _______,

                      EEPROM_RESET, RESET, RGB_TOG
    ),
    [LY_LOWER] = LAYOUT(
                  _______, _______, _______, RESET,
                  _______, _______, _______, _______,
                  _______, _______, _______, _______,
        _______,  _______, _______, _______, _______,
        _______,  _______, _______, _______, _______,
        _______,  _______, _______, _______, _______,

                  _______, _______, _______
    ),
    [LY_RAISE] = LAYOUT(
                  _______, _______, _______, RESET,
                  _______, _______, _______, _______,
                  _______, _______, _______, _______,
        _______,  _______, _______, _______, _______,
        _______,  _______, _______, _______, _______,
        _______,  _______, _______, _______, _______,

                  _______, _______, _______
    ),
};

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    uint8_t layer = get_highest_layer(layer_state);  // special handling per layer
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

#ifdef OLED_ENABLE

    static const char PROGMEM tree_logo[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xe0, 0xf0, 0xf8, 0xfe, 0xff,
    0xff, 0xfe, 0xf8, 0xf0, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x86, 0xe7, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xe7, 0x86, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x86, 0xe7, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xe7, 0x86, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x06, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x87, 0xe7, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xe7, 0x87, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x06, 0x00, 0x00, 0x00, 0x00};

	oled_rotation_t oled_init_user(oled_rotation_t rotation) {
		return OLED_ROTATION_270;       // flips the display 270 degrees
	}

	static void render_logo(void) {
        oled_write_raw_P(tree_logo, sizeof(tree_logo));
	}

	bool oled_task_user(void) {
		render_logo();
		oled_set_cursor(0,6);

		oled_write_ln_P(PSTR("Layer"), false);

    switch (get_highest_layer(layer_state)) {
        case LY_BASE:
            oled_write_ln_P(PSTR("Base"), false);
            break;
        case LY_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case LY_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false); // should never happen
    }
	oled_write_ln_P(PSTR(""), false);
    return false;
	}
#endif
