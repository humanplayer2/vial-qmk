// Copyright 2026 Rasmus K. Rendsvig (@humanplayer2)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Keymap for deerfox with trackpoint
// Intended described in README.md

// Layers
enum {
    _BASE,
    _NAV,
    _SYM,
    _SYM2,
};

// Keycode aliases intended for macOS with a Danish input layout.
enum my_keycodes {
    // Danish letters
    DK_AE = KC_SEMICOLON,    // æ
    DK_OE = KC_QUOTE,        // ø
    DK_AA = KC_LEFT_BRACKET, // å
    DK_EE = A(KC_E),         // é
    DK_EEEE = A(S(KC_E)),    // É

    // Danish symbols
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

    // Applications
    CLOSE_W = G(S(KC_W)),     // Close window
    LOCKSCR = G(C(KC_Q)),     // Lock screen
    TERMINL = G(A(KC_ENTER)), // Spawn terminal
    LAUNCHR = G(KC_SPACE),    // Show launcher
    SCNSHOT = S(G(KC_5)),     // Screenshot tool
    OVRVIEW = G(A(KC_O)),     // Applications overview

    // Tab navigation
    TB_F_L  = C(KC_PGUP),     // Focus tab left
    TB_F_R  = C(KC_PGDN),     // Focus tab right
    TB_LAST = G(KC_9),        // Last tab
    BACK    = G(KC_LEFT),     // Back in Firefox    
    
    // Window navigation
    WS_F_U  = G(C(KC_K)),     // Focus workspace up
    WS_F_D  = G(C(KC_J)),     // Focus workspace down
    TL_F_L = G(C(KC_H)),      // Focus tile left
    TL_F_R = G(C(KC_L)),      // Focus tile right
    
    TL_C = G(C(KC_C)),        // Center current tile
    TL_SMLR = G(C(KC_COMMA)), // Tile smaller
    TL_BIGR = G(C(KC_DOT)),   // Tile bigger
    TL_TG = G(C(KC_F)),       // Toggle tiled or not
    
    // Text 
    WRD_JMP = KC_LALT,        // Word jumping that can be held with shift
    HOME    = G(KC_LEFT),
    END     = G(KC_RIGHT),
    COPY    = G(KC_C),
    CUT     = G(KC_X),
    PASTE   = G(KC_V),
    UNDO    = G(KC_Z),

    // Just shorter
    VOL_UP  = KC_KB_VOLUME_UP,
    VOL_DN  = KC_KB_VOLUME_DOWN,
    VOL_MU  = KC_AUDIO_MUTE,    
    __xxx__ = KC_NO,
    
    // Layer and mod-taps
    NAV_SPC = LT(_NAV, KC_SPACE),     // Navigation access from base layer
    SYM_ENT = LT(_SYM, KC_ENTER),     // Symbols access from base layer
    
    SH_SPC  = MT(MOD_LSFT, KC_SPACE), // Shift on base layer
    CMD_ESC = MT(MOD_LGUI, KC_ESC),   // Command on base layer
    CTL_OE  = MT(MOD_LCTL, DK_OE),    // Control on base layer
    ALT_Q   = MT(MOD_LALT, KC_Q),     // Option on base layer

    OPT_ESC = MT(MOD_LALT, KC_ESC),   // Option on _NAV layer for word jumping
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
              KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,         KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   ,
    KC_TAB ,  KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,         KC_H   , KC_J   , KC_K   , KC_L   , DK_AE  , CTL_OE ,
              KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,         KC_N   , KC_M   , KC_COMM, KC_DOT , DK_AA  ,
                                CMD_ESC, SH_SPC , MS_BTN1,         MS_BTN3, NAV_SPC, SYM_ENT
    ),

    [_NAV] = LAYOUT( 
             CLOSE_W, TB_F_L , WS_F_U , TB_F_R , TB_LAST,        KC_DEL , HOME   , KC_UP  , END    , LOCKSCR,
    OVRVIEW, __xxx__, TL_F_L , WS_F_D , TL_F_R , WRD_JMP,        KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, __xxx__, SCNSHOT,
             BACK   , TL_SMLR, TL_C   , TL_BIGR, TL_TG  ,        __xxx__, COPY   , PASTE  , CUT    , UNDO   ,
                               OPT_ESC, _______, LAUNCHR,        _______, _______, TERMINL
    ),
    
    [_SYM] = LAYOUT(
             DK_AT  , KC_3   , KC_2   , KC_1   , DK_PIPE,         DK_STAR, KC_HASH,  KC_BSLS, DK_GRV,  DK_EE,
    DK_AMPR, KC_0   , KC_6   , KC_5   , KC_4   , KC_EXLM,         DK_SLSH, DK_LPRN,  DK_LBRC, DK_LCBR, DK_LABK, __xxx__,
             DK_DOL , KC_9   , KC_8   , KC_7   , DK_QUES,         DK_PLUS, DK_MNUS,  DK_UNSC, DK_EQUL, DK_TILD,
                             _______, MO(_SYM2), MS_BTN2,         _______, _______, _______
    ),

    [_SYM2] = LAYOUT(
             __xxx__, KC_F5  , KC_F3  , KC_F2  , VOL_UP ,         DK_HAT , KC_PERC, DK_DQUO, DK_AIGU, DK_EEEE,
    QK_BOOT, __xxx__, __xxx__, __xxx__, __xxx__, VOL_MU ,         DK_BSLS, DK_RPRN, DK_RBRC, DK_RCBR, DK_RABK, __xxx__,
             __xxx__, __xxx__, __xxx__, __xxx__, VOL_DN ,         __xxx__, __xxx__, __xxx__, __xxx__, __xxx__,
                               _______, _______, _______,         _______, _______, _______
    ),
};