#pragma once

enum layers {
    LY_BASE,
    LY_SWE,
    LY_LOWER,
    LY_RAISE,
    LY_ADJUST,
};

enum custom_keycodes {
    KC_BASE = SAFE_RANGE,
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

#define MUTE_ZOOM LSG(KC_A)

// ENCODER ACTIONS
#ifdef ENCODER_ENABLE
    void encoder_action_volume(bool clockwise);
    void encoder_action_mediatrack(bool clockwise);
    void encoder_action_navword(bool clockwise);
    void encoder_action_navpage(bool clockwise);

    void encoder_action_undo_redo(bool clockwise);
    void encoder_action_vscode_nav(bool clockwise);

    uint8_t get_selected_layer(void);
    void encoder_action_layerchange(bool clockwise);
    void encoder_action_desktop_change(bool clockwise);
#endif // ENCODER_ENABLEs