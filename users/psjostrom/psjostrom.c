#include QMK_KEYBOARD_H
#include "psjostrom.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case BASE:
            if (record->event.pressed) {
                set_single_persistent_default_layer(LY_BASE);
            }
            return false;
        case SWE:
            if (record->event.pressed) {
                set_single_persistent_default_layer(LY_SWE);
            }
            return false;
        case LOWER:
            if (record->event.pressed) {
                layer_on(LY_LOWER);
                update_tri_layer(LY_LOWER, LY_RAISE, LY_ADJUST);
            } else {
                layer_off(LY_LOWER);
                update_tri_layer(LY_LOWER, LY_RAISE, LY_ADJUST);
            }
            return false;
        case RAISE:
            if (record->event.pressed) {
                layer_on(LY_RAISE);
                update_tri_layer(LY_LOWER, LY_RAISE, LY_ADJUST);
            } else {
                update_tri_layer(LY_LOWER, LY_RAISE, LY_ADJUST);
            }
            return false;
        case ADJUST:
            if (record->event.pressed) {
                layer_on(LY_ADJUST);
            } else {
                layer_off(LY_ADJUST);
            }
            return false;
    }
    return true;
}