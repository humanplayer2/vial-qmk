// Copyright 2025 Rasmus K. Rendsvig (@humanplayer2)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Layers
enum {
    _BASE = 0,
    _BOOT = 1,
    _NAV  = 2,
    _FN   = 3,
};


enum my_keycodes {
    // Mod and Layer Tabs
    BOOTESC = (LT(_BOOT,KC_ESC)),      // Escape, control
    CTL_ESC = (MT(MOD_RCTL,KC_ESC)),   // Escape, control
    CTL_ANX = (MT(MOD_RCTL,KC_F)),     // App next, control (for word selection while holding nav and shift)
    SH_SPC  = (MT(MOD_RSFT,KC_SPACE)), // Space,  shift
    NAV_SPC  = (LT(_NAV,KC_SPACE)),    // Space,  navigation layer
    // OS Navigation
    APP_NXT = A(KC_TAB),               // Next application
    APP_PRV = A(S(KC_TAB)),            // Previous application
    WS_PRV = C(LGUI(KC_RGHT)),         // Workspace previous
    WS_NXT = C(LGUI(KC_LEFT)),         // Workspace next
    TAB_NXT = C(KC_TAB),               // Tab left
    TAB_PRV = C(S(KC_TAB)),            // Tab right
    BACK = A(KC_LEFT),                 // Back in browser
    ALT_F4 = A(KC_F4),                 // Close application
    // Shorthands
    VOL_UP  = KC_KB_VOLUME_UP,
    VOL_DN  = KC_KB_VOLUME_DOWN,
    VOL_MU  = KC_KB_MUTE,
    COPY    = C(KC_C),
    CUT     = C(KC_X),
    PASTE   = S(KC_V),
    UNDO    = C(KC_Z)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        BOOTESC, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,         KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSPC,
        KC_RBRC, KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,         KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC,
        KC_TAB , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,         KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT, 
                 KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,         KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH,
                                   CTL_ESC, SH_SPC , FN     ,         KC_RALT, NAV_SPC, KC_ENT
    ),

    [_BOOT] = LAYOUT(
        _______, _______, _______, _______, _______, QK_BOOT,         _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, 
                 _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______,
                                   _______, _______, _______,         _______, _______, _______
    ),    
    
    [_NAV] = LAYOUT(
        ALT_F4 , _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______,
        _______, _______, TAB_PRV, WS_NXT , TAB_NXT, _______,         KC_DEL , KC_HOME, KC_UP  , KC_END , _______, _______,
        _______, _______, APP_PRV, WS_PRV , CTL_ANX, _______,         KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, 
                 BACK   , VOL_DN , VOL_MU , VOL_UP , _______,         KC_APP , COPY   , PASTE  , CUT    , UNDO   ,
                                   _______, _______, _______,         _______, _______, _______
    ),

    [_FN] = LAYOUT(
        KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,         KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,
        _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, 
                 _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______,
                                   _______, _______, _______,         _______, _______, _______
    )


};