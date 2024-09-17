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
};

#define MUTE_ZOOM LSG(KC_A)

#define MOUSE TG(LY_MOUSE)

// Swedish characters
#define KC_AA LGUI(KC_LBRC) // Å
#define KC_AE LGUI(KC_QUOT) // Ä
#define KC_OE LGUI(KC_SCLN) // Ö

#define KC_BACK LCTL(KC_MINS) // Navigate backwards in VS Code, Firefox etc
#define KC_FORW S(LCTL(KC_MINS)) // Navigate forwards in VS Code, Firefox etc

// OBS!!! ALL THESE IS WITH COMMAND AND OPTION SWAPPED IN THE OS!

#define KC_PRVWD G(KC_LEFT) // Move cursor back one word
#define KC_NXTWD G(KC_RIGHT) // Move cursor forward one word

#define KC_LINESTART A(KC_LEFT) // Move cursor back one word
#define KC_LINEEND A(KC_RIGHT) // Move cursor forward one word

#define KC_MVAPPL LAG(KC_LEFT) // Move app to left part of screen
#define KC_MVAPPR LAG(KC_RIGHT) // Move app to right part of screen
#define KC_MAXAPP LAG(KC_M) // Maximize app

#define KC_IOSSHAKE C(A(KC_Z))
#define KC_LOG C(G(KC_L))
#define KC_COPYPATH A(G(KC_C))
#define KC_DEVTOOLS A(G(KC_I))
#define KC_SCREENSHOT S(A(KC_4))

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