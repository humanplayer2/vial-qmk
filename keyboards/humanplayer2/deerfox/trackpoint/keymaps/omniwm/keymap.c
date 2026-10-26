// Copyright 2026 Rasmus K. Rendsvig (@humanplayer2)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "btn1_lt/btn1_lt.h" // BTN1_LT custom tap/hold key

// Layers
// Keep the layer numbers stable and easy to read.
enum {
    _BASE,
    _BTN1,
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
    DK_EEEE =  A(S(KC_E)),   // É

    // Danish-layout symbols
    DK_AT   = ALGR(KC_2),     // @
    DK_DOL  = ALGR(KC_4),     // $
    DK_AMPR = S(KC_6),        // &
    DK_PIPE = ALGR(KC_EQUAL), // |
    DK_SLSH = S(KC_7),        // /
    DK_BSLS = ALGR(KC_NUBS),  // \     -- don't let it escape
    DK_LPRN = S(KC_8),        // (
    DK_RPRN = S(KC_9),        // )
    DK_LBRC = ALGR(KC_8),     // [
    DK_RBRC = ALGR(KC_9),     // ]
    DK_LCBR = ALGR(KC_7),     // {
    DK_RCBR = ALGR(KC_0),     // }
    DK_LABK = KC_NUBS,        // <
    DK_RABK = S(KC_NUBS),     // >
    DK_QUES = S(KC_MINUS),    // ?
    DK_DQUO = S(KC_2),        // "
    DK_GRV  = S(KC_EQUAL),    // `
    DK_AIGU = KC_EQUAL,       // ´
    DK_STAR = S(KC_BSLS),     // *
    DK_HAT  = S(KC_RBRC),     // ^
    DK_EQUL = S(KC_0),        // =
    DK_TILD = ALGR(KC_RBRC),  // ~
    DK_PLUS = KC_MINUS,       // +
    DK_MNUS = KC_SLSH,        // -
    DK_UNSC = S(DK_MNUS),     // _

    // macOS application shortcuts
    TAB_LFT = G(S(KC_LBRC)),  // Previous tab (common macOS app/browser shortcut)
    TAB_RGT = G(S(KC_RBRC)),  // Next tab (common macOS app/browser shortcut)
    TAB_CLS = G(KC_W),        // Close window/tab
    LASTTAB = G(KC_9),        // Last browser tab
    BACK    = G(KC_LEFT),     // Back in many macOS browsers/file managers
    ALT_F4  = G(KC_Q),        // Quit application
    LOCKSCR = C(G(KC_Q)),     // Lock macOS
    ALT_TAB = A(KC_TAB),      // OmniWM: focus previously focused window

    // OmniWM default shortcuts
    // Focus: Option + Arrow Keys
    FCS_LFT = A(KC_LEFT),
    FCS_RGT = A(KC_RIGHT),
    FCS_UP  = A(KC_UP),
    FCS_DN  = A(KC_DOWN),

    // Move focused window: Option + Shift + Arrow Keys
    MOVE_LFT = S(A(KC_LEFT)),
    MOVE_RGT = S(A(KC_RIGHT)),
    MOVE_UP  = S(A(KC_UP)),
    MOVE_DN  = S(A(KC_DOWN)),

    // Other OmniWM defaults
    TILE_SM = A(KC_MINUS),       // Shrink container primary span (Niri)
    TILE_LG = A(KC_EQUAL),       // Grow container primary span (Niri)
    SIZE_SM = S(A(KC_MINUS)),    // Shrink window secondary span (Niri)
    SIZE_LG = S(A(KC_EQUAL)),    // Grow window secondary span (Niri)
    RESET_SZ = C(A(KC_R)),       // Reset window secondary span (Niri)
    LAUNCHR = C(A(KC_SPACE)),    // Toggle OmniWM command palette
    TERMINL = A(KC_GRAVE),       // Toggle OmniWM Quake Terminal
    TGFLOAT = A(S(KC_O)),        // Toggle OmniWM Overview
    MENU_ANY = C(A(KC_M)),       // OmniWM: Open Menu Anywhere

    // Standard macOS editing shortcuts
    COPY  = G(KC_C),
    CUT   = G(KC_X),
    PASTE = G(KC_V),
    UNDO  = G(KC_Z),

    __xxx__ = KC_NO,

    // Thumb keys
    NAV_SPC = LT(_NAV, KC_SPACE),
    CTL_ESC = MT(MOD_RCTL, KC_ESC),
    SH_SPC  = MT(MOD_RSFT, KC_SPACE),
    SYM_ENT = LT(_SYM, KC_ENTER),

    // Home-row mods
    AL_Q  = MT(MOD_LALT, KC_Q),
    AL_OE = MT(MOD_LALT, DK_OE),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
              KC_TAB , KC_W   , KC_F   , KC_P   , KC_B   ,         KC_J   , KC_L   , KC_U   , KC_Y   , DK_AE,
    AL_Q   ,  KC_A   , KC_R   , KC_S   , KC_T   , KC_G   ,         KC_M   , KC_N   , KC_E   , KC_I   , KC_O   , AL_OE,
              KC_Z   , KC_X   , KC_C   , KC_D   , KC_V   ,         KC_K   , KC_H   , KC_COMM, KC_DOT , DK_AA,
                                CTL_ESC, SH_SPC , BTN1_LT,         KC_BTN3, NAV_SPC, SYM_ENT
    ),

    // Number/function layer. Kept mostly as in the Linux keymap.
    [_BTN1] = LAYOUT(
              QK_BOOT, KC_F3  , KC_F2  , KC_F1  , KC_KB_VOLUME_UP,  KC_BRIU, KC_1, KC_2, KC_3, QK_BOOT,
    KC_F12 ,  KC_F10 , KC_F6  , KC_F5  , KC_F4  , KC_AUDIO_MUTE, __xxx__, KC_4, KC_5, KC_6, KC_0, G(S(KC_4)),
              KC_F11 , KC_F9  , KC_F8  , KC_F7  , KC_KB_VOLUME_DOWN, KC_BRID, KC_7, KC_8, KC_9, __xxx__,
                                _______, _______, _______,         _______, _______, _______
    ),

    // OmniWM navigation layer. Uses OmniWM's documented default shortcuts.
    [_NAV] = LAYOUT(
              ALT_F4 , TAB_LFT, MOVE_UP, TAB_RGT, LASTTAB,         G(KC_W), A(KC_HOME), FCS_UP, A(KC_END), LOCKSCR,
    __xxx__,  __xxx__, MOVE_LFT, MOVE_DN, MOVE_RGT, TGFLOAT,        KC_BSPC, FCS_LFT, FCS_DN, FCS_RGT, __xxx__, __xxx__,
              BACK   , TILE_SM, RESET_SZ, TILE_LG, ALT_TAB,         MENU_ANY, COPY, PASTE, CUT, UNDO,
                                _______, _______, LAUNCHR,         _______, _______, TERMINL
    ),

    [_SYM] = LAYOUT(
              __xxx__, __xxx__, __xxx__, __xxx__, __xxx__,         DK_STAR, KC_HASH,  KC_BSLS, DK_GRV,  DK_EE,
    __xxx__,  DK_AMPR, DK_AT  , DK_QUES, KC_EXLM, DK_PIPE,         DK_SLSH, DK_LPRN,  DK_LBRC, DK_LCBR, DK_LABK, __xxx__,
              DK_DOL , __xxx__, __xxx__, __xxx__, __xxx__,         DK_PLUS, DK_MNUS,  DK_UNSC, DK_EQUL, DK_TILD,
                                _______, MO(_SYM2), _______,         _______, _______, _______
    ),

    [_SYM2] = LAYOUT(
              __xxx__, __xxx__, __xxx__, __xxx__, __xxx__,         DK_HAT , KC_PERC, DK_DQUO, DK_AIGU, DK_EEEE,
    __xxx__,  DK_AMPR, DK_AT  , DK_QUES, KC_EXLM, DK_PIPE,         DK_BSLS, DK_RPRN,  DK_RBRC, DK_RCBR, DK_RABK, __xxx__,
              DK_DOL , __xxx__, __xxx__, __xxx__, __xxx__,         DK_PLUS, DK_MNUS, DK_UNSC, DK_EQUL, DK_TILD,
                                _______, _______, _______,         _______, _______, _______
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return process_btn1_lt(keycode, record, _BTN1); // BTN1_LT custom behavior
}
