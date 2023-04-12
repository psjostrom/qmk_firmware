#pragma once

enum layers {
    LY_BASE,
    LY_SWE,
    LY_LOWER,
    LY_RAISE,
    LY_ADJUST,
    LY_MOUSE
};

enum custom_keycodes {
    BASE = SAFE_RANGE,
    SWE,
    LOWER,
    RAISE,
    ADJUST,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_DLINE,
    MOUSE
};

#define MUTE_ZOOM LSG(KC_A)

// Swedish characters
#define KC_AA LALT(KC_LBRC) // Å
#define KC_AE LALT(KC_QUOT) // Ä
#define KC_OE LALT(KC_SCLN) // Ö

#define KC_BACK LCTL(KC_MINS) // Navigate backwards in VS Code, Firefox etc

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