#include QMK_KEYBOARD_H
#include "psjostrom.h"

#ifdef ENCODER_ENABLE
    void encoder_action_volume(bool clockwise) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }

    void encoder_action_mediatrack(bool clockwise) {
        if (clockwise) {
            tap_code(KC_MEDIA_NEXT_TRACK);
        } else {
            tap_code(KC_MEDIA_PREV_TRACK);
        }
    }

    void encoder_action_navword(bool clockwise) {
        if (clockwise) {
            tap_code16(LCTL(KC_RGHT));
        } else {
            tap_code16(LCTL(KC_LEFT));
        }
    }

    void encoder_action_navpage(bool clockwise) {
        if (clockwise) {
            tap_code16(KC_PGUP);
        } else {
            tap_code16(KC_PGDN);
        }
    }

    void encoder_action_undo_redo(bool clockwise) {
        if (clockwise) {
            tap_code16(LSG(KC_Z));
        } else {
            tap_code16(LGUI(KC_Z));
        }
    }

    void encoder_action_vscode_nav(bool clockwise) {
        if (clockwise) {
            tap_code16(RCS(KC_MINS));
        } else {
            tap_code16(LCTL(KC_MINS));
        }
    }

    void encoder_action_desktop_change(bool clockwise) {
        if (clockwise) {
            tap_code16(LCTL(KC_RIGHT));
        } else {
            tap_code16(LCTL(KC_LEFT));
        }
    }
#endif // ENCODER_ENABLE