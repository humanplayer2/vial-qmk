// Copyright 2025 Rasmus K. Rendsvig (@humanplayer2)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Layers
enum {
    _BASE  = 0,
    _BOOT  = 1,
    _NAV   = 2,
    _SYM   = 3,
};

enum my_keycodes {
    // Mod and Layer Tabs
    BOOTESC = (LT(_BOOT,KC_ESC)),   // Escape, control
    CTL_ESC = (MT(MOD_RCTL,KC_ESC)),   // Escape, control
    SH_SPC  = (MT(MOD_RSFT,KC_SPACE)), // Space,  shift
    NAV_SPC  = (LT(_NAV,KC_SPACE)),    // Space,  navigation layer
    SYM_ENT = (LT(_SYM, KC_ENTER)),    // Enter,  symbols layer
    LALT_A   = (MT(MOD_LALT,KC_A)),    // A,      left alt
    RALT_QU  = (MT(MOD_RALT,KC_QUOT)), // Quote,  right alt

    // OS Navigation etc.
    TAB_LFT = C(KC_PGUP),     // Tab left
    TAB_RGT = C(KC_PGDN),     // Tab right
    TAB_CLS = C(KC_W),        // Tab close
    LASTTAB = A(KC_9),        // Last tab in Firefox
    BACK = A(KC_LEFT),        // Back in browser, file manager
    ALT_F4 = G(KC_ESC),       // Close application
    WS_UP = KC_P1,            // Workspace up
    WS_DN = KC_P5,            // Workspace down
    FCS_LFT = KC_P3,          // Focus tile left
    FCS_RGT = KC_P7,          // Focus tile right
    C_FCS_R = (MT(MOD_RCTL,FCS_RGT)), // Focus tile right, Ctrl for easy text selection with thumb shift
    TILE_SM = G(KC_MINS),     // Decrease tile width
    TILE_LG = G(KC_EQL),      // Increase tile width
    TILE_CN = G(KC_C),        // Center on tile
    LAUNCHR = G(KC_SPC),      // Open launcher
    TERMINL = G(KC_ENT),      // Open terminal
    LOCKSCR = G(KC_L),        // Lock screen
    TGFLOAT = G(KC_P9),       // Toggle float
    ALT_TAB = A(KC_TAB),
    //
    // Shorthands
    VOL_UP  = KC_KB_VOLUME_UP,
    VOL_DN  = KC_KB_VOLUME_DOWN,
    VOL_MU  = KC_KB_MUTE,
    COPY    = C(KC_INS),
    CUT     = C(KC_X),
    PASTE   = S(KC_INS),
    UNDO    = C(KC_Z)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        BOOTESC, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,         KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSPC,
        KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,         KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC,
        KC_RBRC, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,         KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, RALT_QU, 
                 KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,         KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH,
                                   CTL_ESC, SH_SPC , KC_BSPC,         KC_DEL , NAV_SPC, SYM_ENT
    ),

    [_BOOT] = LAYOUT(
        _______, _______, _______, _______, _______, QK_BOOT,         _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, 
                 _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______,
                                   _______, _______, _______,         _______, _______, _______
    ),    
    
    [_NAV] = LAYOUT(
        ALT_F4 , _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, LOCKSCR,
        _______, _______, TAB_LFT, WS_UP  , TAB_RGT, LASTTAB,         KC_DEL , KC_HOME, KC_UP  , KC_END , _______, _______,
        _______, _______, FCS_LFT, WS_DN  , C_FCS_R, TGFLOAT,         KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, 
                 BACK   , TILE_SM, TILE_CN, TILE_LG, ALT_TAB,         KC_APP , COPY   , PASTE  , CUT    , UNDO   ,
                                   _______, _______, LAUNCHR,         _______, _______, TERMINL
    ),

    [_SYM] = LAYOUT(
        KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,         KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,
        _______, _______, _______, _______, _______, VOL_UP ,         _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, VOL_MU ,         _______, _______, _______, _______, _______, _______, 
                 _______, _______, _______, _______, VOL_DN ,         _______, _______, _______, _______, QK_BOOT,
                                   _______, _______, _______,         _______, _______, _______
    )


};