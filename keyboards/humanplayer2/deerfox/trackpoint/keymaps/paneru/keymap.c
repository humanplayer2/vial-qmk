// Copyright 2026 Rasmus K. Rendsvig (@humanplayer2)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
//#include "btn1_lt/btn1_lt.h" // BTN1_LT custom tap/hold key

// Layers
// Keep the layer numbers stable and easy to read.
enum {
    _BASE,
//    _NUM,
    _NAV,
    _SYM,
    _SYM2,
};

// Keycode aliases. This keymap is intended for macOS with a Danish input layout.
enum my_keycodes {
    // Danish letters
    DK_AE = KC_SEMICOLON,    // æ
    DK_OE = KC_QUOTE,        // ø
    DK_AA = KC_LEFT_BRACKET, // å
    DK_EE = A(KC_E),         // é
    DK_EEEE = A(S(KC_E)),    // É

    // Danish-layout symbols
    DK_AT   = A(KC_NUHS),    // @
    DK_DOL  = KC_NUBS,       // $
    DK_AMPR = S(KC_6),       // &
    DK_PIPE = A(KC_I),       // |
    DK_SLSH = S(KC_7),       // /
    DK_BSLS = A(S(KC_7)),    // backslash
    DK_LPRN = S(KC_8),       // (
    DK_RPRN = S(KC_9),       // )
    DK_LBRC = A(KC_8),       // [
    DK_RBRC = A(KC_9),       // ]
    DK_LCBR = A(S(KC_8)),    // {
    DK_RCBR = A(S(KC_9)),    // }
    DK_LABK = KC_GRV,        // <,
    DK_RABK = S(KC_GRV),     // >
    DK_QUES = S(KC_MINUS),   // ?
    DK_DQUO = S(KC_2),       // "
    DK_GRV  = S(KC_EQUAL),   // `
    DK_AIGU = KC_EQUAL,      // ´ (dead key on standard layout)
    DK_STAR = S(KC_NUHS),    // *
    DK_HAT  = S(KC_RBRC),    // ^
    DK_EQUL = S(KC_0),       // =
    DK_TILD = A(KC_RBRC),    // ~
    DK_PLUS = KC_MINUS,      // +
    DK_MNUS = KC_SLSH,       // -
    DK_UNSC = S(KC_SLSH),    // _

    // Application
    TAB_LFT = G(A(KC_LEFT)),  // Focus tab left
    TAB_RGT = G(A(KC_RIGHT)), // Focus tab right
    // TAB_MLF move tab left Control shift PageUp
    // TAB_MLF move tab right Control shift PageDown
    LASTTAB = G(KC_9),       // Last tab
    BACK    = G(KC_RIGHT),   // Back in Firefox
    CLOSE_W = G(S(KC_W)),    // Close window
    LOCKSCR = G(C(KC_Q)),    // Lock screen

    // Window navigation
    //// Focuses are basic keycodes so FCSR_WD can work
    FCS_UP  = G(C(KC_UP)), 
    FCS_LFT = G(C(KC_LEFT)), // Focus left
    FCS_DN  = G(C(KC_DOWN)),
    FCS_RGT = G(C(KC_RIGHT)),

    WRD_JMP = KC_LALT,       // Word jumping compatible with jump and select with shift
    FCS_CEN = G(C(KC_C)),    // Center current window
    
    TILE_SZ = G(C(KC_MINUS)),// Tile size cycle
    TILE_TG = G(C(KC_F)),    // Toggle tiled or not
    
    // Other OS
    TERMINL = G(KC_ENTER),   // Spawn terminal
    LAUNCHR = G(KC_SPACE),   // Show launcher
    SCNSHOT = S(G(KC_5)),    // Screenshot tool

    OVRVIEW = G(A(KC_O)),    // Applications overview

    VOL_UP  = KC_KB_VOLUME_UP,
    VOL_DN  = KC_KB_VOLUME_DOWN,
    VOL_MU  = KC_AUDIO_MUTE,

    HOME    = G(KC_LEFT),
    END     = G(KC_RIGHT),
    COPY    = G(KC_C),
    CUT     = G(KC_X),
    PASTE   = G(KC_V),
    UNDO    = G(KC_Z),

    __xxx__ = KC_NO,
    
    // Layer and Mod-Taps
    NAV_SPC = LT(_NAV, KC_SPACE),
    CMD_ESC = MT(MOD_LGUI, KC_ESC),
    SH_SPC  = MT(MOD_LSFT, KC_SPACE),
    SYM_ENT = LT(_SYM, KC_ENTER),
    
    OPT_ESC = MT(MOD_LALT, KC_ESC),
    ALT_Q   = MT(MOD_LALT, KC_Q),
    CTL_OE  = MT(MOD_LCTL, DK_OE),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
             KC_TAB , KC_W   , KC_F   , KC_P   , KC_B   ,        KC_J   , KC_L   , KC_U   , KC_Y   , DK_AE,
    ALT_Q  , KC_A   , KC_R   , KC_S   , KC_T   , KC_G   ,        KC_M   , KC_N   , KC_E   , KC_I   , KC_O   , CTL_OE,
             KC_Z   , KC_X   , KC_C   , KC_D   , KC_V   ,        KC_K   , KC_H   , KC_COMM, KC_DOT , DK_AA,
                               CMD_ESC, SH_SPC , MS_BTN1,        MS_BTN3, NAV_SPC, SYM_ENT
    ),

//    [_NUM] = LAYOUT(
//             QK_BOOT, KC_F3  , KC_F2  , KC_F1  , VOL_UP ,        KC_BRIU, KC_1   , KC_2   , KC_3   , QK_BOOT,
//    KC_F12 , KC_F10 , KC_F6  , KC_F5  , KC_F4  , VOL_MU ,        __xxx__, KC_4   , KC_5   , KC_6   , KC_0   , __xxx__,
//             KC_F11 , KC_F9  , KC_F8  , KC_F7  , VOL_DN ,        KC_BRID, KC_7   , KC_8   , KC_9   , __xxx__,
//                               _______, _______, _______,        _______, _______, _______
//    ),

    [_NAV] = LAYOUT(
             CLOSE_W, TAB_LFT, FCS_UP , TAB_RGT, LASTTAB,        KC_DEL , KC_HOME, KC_UP  , KC_END , LOCKSCR,
    __xxx__, __xxx__, FCS_LFT, FCS_DN , FCS_RGT, OVRVIEW,        KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, __xxx__, __xxx__,
             BACK   , TILE_SZ, FCS_CEN, WRD_JMP, TILE_TG,        __xxx__, COPY   , PASTE  , CUT    , UNDO   ,
                               OPT_ESC, _______, LAUNCHR,        _______, _______, TERMINL
    ),
    
    [_SYM] = LAYOUT(
             DK_AT  , KC_3   , KC_2   , KC_1   , DK_PIPE,         DK_STAR, KC_HASH,  KC_BSLS, DK_GRV,  DK_EE,
    DK_AMPR, KC_0   , KC_6   , KC_5   , KC_4   , KC_EXLM,         DK_SLSH, DK_LPRN,  DK_LBRC, DK_LCBR, DK_LABK, __xxx__,
             DK_DOL , KC_9   , KC_8   , KC_7   , DK_QUES,         DK_PLUS, DK_MNUS,  DK_UNSC, DK_EQUL, DK_TILD,
                             _______, MO(_SYM2), MS_BTN2,         _______, _______, _______
    ),

    [_SYM2] = LAYOUT(
             SCNSHOT, KC_F5  , KC_F3  , KC_F2  , VOL_UP ,         DK_HAT , KC_PERC, DK_DQUO, DK_AIGU, DK_EEEE,
    QK_BOOT, __xxx__, __xxx__, __xxx__, __xxx__, VOL_MU ,         DK_BSLS, DK_RPRN, DK_RBRC, DK_RCBR, DK_RABK, __xxx__,
             __xxx__, __xxx__, __xxx__, __xxx__, VOL_DN ,         __xxx__, __xxx__, __xxx__, __xxx__, __xxx__,
                               _______, _______, _______,         _______, _______, _______
    ),
};

//bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//    return process_btn1_lt(keycode, record, _BTN1); // BTN1_LT custom behavior
//}
