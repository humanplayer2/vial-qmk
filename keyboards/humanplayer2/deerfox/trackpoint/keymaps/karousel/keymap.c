// Copyright 2026 Rasmus K. Rendsvig (@humanplayer2)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "btn1_lt/btn1_lt.h" // To use BTN1_LT

// Layers
enum {
    _BASE,
    _BTN1,
    _NAV,
    _SYM,
    _SYM2,
};



// Keycode names:
enum my_keycodes {
  // DK keycodes
  //
DK_EE = UC(0x00E9), // é
DK_EEEE = UC(0x00C9), // É
DK_AE = KC_SEMICOLON,     // æ
DK_OE = KC_QUOTE,         // ø
DK_AA = KC_LEFT_BRACKET,  // å
  //
DK_AT   = ALGR(KC_2),     // @
DK_DOL  = ALGR(KC_4),     // $
DK_AMPR = S(KC_6),        // &
DK_PIPE = ALGR(KC_EQUAL), // |
DK_SLSH = S(KC_7),        // /
DK_BSLS = ALGR(KC_NUBS),  // \     -- don't let it escape
DK_LPRN = S(KC_8),        // (
DK_RPRN = S(KC_9),        // )
DK_LBRC = ALGR(KC_8),     //
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
  //
  // OS Navigation etc.
TAB_LFT = C(KC_PGUP),     // Tab left
TAB_RGT = C(KC_PGDN),     // Tab right
TAB_CLS = C(KC_W),        // Tab close
LASTTAB = A(KC_9),        // Last tab
BACK = A(KC_LEFT),        // Back in browser, file manager
ALT_F4 = G(KC_ESC),       // Close application
WS_UP = KC_P1,            // Workspace up
WS_DN = KC_P5,            // Workspace down
FCS_LFT = KC_P3,          // Focus tile left
FCS_RGT = KC_P7,          // Focus tile right
C_FCS_R = (MT(MOD_RCTL,FCS_RGT)), // Focus tile right, Ctrl for easy text selection with shift
TILE_SM = G(DK_MNUS),     // Decrease tile width
TILE_LG = G(DK_PLUS),     // Increase tile width
TILE_CN = G(KC_C),        // Center on tile
LAUNCHR = G(KC_SPC),      // Open launcher
TERMINL = G(KC_ENT),      // Open terminal
LOCKSCR = G(KC_L),        // Lock screen
TGFLOAT = G(KC_P9),       // Toggle float
ALT_TAB = A(KC_TAB),      // Desktops overview
SCRSHOT = LSG(KC_PSCR),   // Select area screenshot (KDE default: Meta+Shift+Print)
//
  // Shorthands
VOL_UP  = KC_KB_VOLUME_UP,
VOL_DN  = KC_KB_VOLUME_DOWN,
VOL_MU  = KC_KB_MUTE,
COPY    = C(KC_INS),
CUT     = C(KC_X),
PASTE   = S(KC_INS),
UNDO    = C(KC_Z),
__xxx__ = KC_NO,
  //
  // Thumb keys
NAV_SPC  = (LT(_NAV,KC_SPACE)),    // Space,  navigation layer
CTL_ESC = (MT(MOD_RCTL,KC_ESC)),   // Escape, control
SH_SPC  = (MT(MOD_RSFT,KC_SPACE)), // Space,  shift
SYM_ENT = (LT(_SYM, KC_ENTER)),    // Enter,  symbols layer
  //
  // Homerow mods
AL_Q = (MT(MOD_LALT,KC_Q)),
AL_OE = (MT(MOD_LALT,DK_OE))
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
              KC_TAB , KC_W   , KC_F   , KC_P   , KC_B   ,         KC_J   , KC_L   , KC_U   , KC_Y   , DK_AE,
    AL_Q   ,  KC_A   , KC_R   , KC_S   , KC_T   , KC_G   ,         KC_M   , KC_N   , KC_E   , KC_I   , KC_O   , AL_OE  ,
              KC_Z   , KC_X   , KC_C   , KC_D   , KC_V   ,         KC_K   , KC_H   , KC_COMM, KC_DOT , DK_AA  ,
                                CTL_ESC, SH_SPC , BTN1_LT,         KC_BTN3, NAV_SPC, SYM_ENT
    ),
    
    [_BTN1] = LAYOUT(
              QK_BOOT, KC_F3  , KC_F2  , KC_F1  , VOL_UP ,         KC_BRIU, KC_1   , KC_2   , KC_3   , QK_BOOT,
    KC_F12 ,  KC_F10 , KC_F6  , KC_F5  , KC_F4  , VOL_MU ,         __xxx__, KC_4   , KC_5   , KC_6   , KC_0   ,  SCRSHOT,
              KC_F11 , KC_F9  , KC_F8  , KC_F7  , VOL_DN ,         KC_BRID, KC_7   , KC_8   , KC_9   , __xxx__,
                                _______, _______, _______,         _______, _______, _______
    ),

    [_NAV] = LAYOUT(
              ALT_F4 , TAB_LFT, WS_UP  , TAB_RGT, LASTTAB,         KC_DEL , KC_HOME, KC_UP  , KC_END , LOCKSCR,
    __xxx__,  __xxx__, FCS_LFT, WS_DN  , C_FCS_R, TGFLOAT,         KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, __xxx__, __xxx__,
              BACK   , TILE_SM, TILE_CN, TILE_LG, ALT_TAB,         KC_APP , COPY   , PASTE  , CUT    , UNDO   ,
                                _______, _______, LAUNCHR,         _______, _______, TERMINL
    ),

    [_SYM] = LAYOUT(
              __xxx__, __xxx__, __xxx__, __xxx__, __xxx__,         DK_STAR, KC_HASH,  KC_BSLS, DK_GRV,  DK_EE  ,
    __xxx__,  DK_AMPR, DK_AT  , DK_QUES, KC_EXLM, DK_PIPE,         DK_SLSH, DK_LPRN,  DK_LBRC, DK_LCBR, DK_LABK, __xxx__,
              DK_DOL , __xxx__, __xxx__, __xxx__, __xxx__,         DK_PLUS, DK_MNUS,  DK_UNSC, DK_EQUL, DK_TILD,
                                _______, MO(_SYM2), _______,         _______, _______, _______
    ),

    [_SYM2] = LAYOUT(
              __xxx__, __xxx__, __xxx__, __xxx__, __xxx__,         DK_HAT , KC_PERC, DK_DQUO, DK_AIGU, DK_EEEE,
    __xxx__,  DK_AMPR, DK_AT  , DK_QUES, KC_EXLM, DK_PIPE,         DK_BSLS, DK_RPRN, DK_RBRC, DK_RCBR, DK_RABK, __xxx__,
              DK_DOL , __xxx__, __xxx__, __xxx__, __xxx__,         DK_PLUS, DK_MNUS, DK_UNSC, DK_EQUL, DK_TILD,
                                _______, _______, _______,         _______, _______, _______
    )
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return process_btn1_lt(keycode, record, _BTN1); // For BTN1_LT
}