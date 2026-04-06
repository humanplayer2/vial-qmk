// Copyright 2026 Rasmus K. Rendsvig (@humanplayer2)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "features/custom_shift_keys.h"

// Layers
enum {
    _BASE  = 0,
    _NAV   = 1,
    _SYM   = 2,
    _NUM   = 3,
    _MOUSE = 4,
};

// Add é and É keycodes, cf. https://getreuer.info/posts/keyboards/non-english/index.html
enum unicode_names {
  DK_E_AIGU_LOWER,
  DK_E_AIGU_UPPER,
};

const uint32_t unicode_map[] PROGMEM = {
  [DK_E_AIGU_LOWER]   = 0x00e9,  // é
  [DK_E_AIGU_UPPER]   = 0x00c9,  // É 
};

#define DK_EGU UP(DK_E_AIGU_LOWER, DK_E_AIGU_UPPER)

// Keycode names:
enum my_keycodes {
  // DK keycodes
  //
DK_AE = KC_SEMICOLON,     // æ
DK_OE = KC_QUOTE,         // ø
DK_AA = KC_LEFT_BRACKET,  // å
  //
DK_AT   = ALGR(KC_2),     // @
DK_DOL  = ALGR(KC_4),     // $
DK_AMPR = S(KC_6),        // &
DK_PIPE = ALGR(KC_EQUAL), // |
DK_SLSH = S(KC_7),        // /
DK_BSLS = ALGR(KC_NUBS),  // \            //
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
ALT_TAB = A(KC_TAB),
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
RM_SPC  = (LT(_NAV,KC_SPACE)),     // Space,  navigation layer
CTL_ESC = (MT(MOD_RCTL,KC_ESC)),   // Escape, control
SH_SPC  = (MT(MOD_RSFT,KC_SPACE)), // Space,  shift
SYM_ENT = (LT(_SYM, KC_ENTER)),    // Enter,  symbols layer
NUM_BT1 = (LT(_NUM, KC_BTN1)),     // Mouse button 1 click also when automouselayer is off, numbers layer if held and no mouse
  //
  // Homerow mods
AL_Q = (MT(MOD_LALT,KC_Q)),
AL_OE = (MT(MOD_LALT,DK_OE))
};


// Custom shift keys
const custom_shift_key_t custom_shift_keys[] = {
  {KC_BSLS, DK_DQUO}, // Shift ' is "
  {DK_GRV, DK_AIGU},  // Shift ` is ´
  {KC_HASH, KC_PERC}, // Shift # is %
  {DK_STAR, DK_HAT},  // Shift * is ^
  {DK_SLSH, DK_BSLS}, // Shift / is \                        ---
  {DK_LPRN, DK_RPRN}, // Shift ( is )
  {DK_LBRC, DK_RBRC}, // Shift [ is ]
  {DK_LCBR, DK_RCBR}, // Shift { is }
  {DK_LABK, DK_RABK}, // Shift < is >
  {KC_BTN3, KC_BTN2}, // Mouse button
};
uint8_t NUM_CUSTOM_SHIFT_KEYS =
    sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_1x1(
              KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,         KC_Y   , KC_U   , KC_I   , KC_O   , KC_P,
    KC_TAB ,  KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,         KC_H   , KC_J   , KC_K   , KC_L   , DK_AE   , DK_OE  ,
              KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,         KC_N   , KC_M   , KC_COMM, KC_DOT , DK_AA  ,
                                CTL_ESC, SH_SPC , MO(_NUM),       MO(_NUM), RM_SPC , SYM_ENT
    ),

    [_NAV] = LAYOUT_1x1(
              ALT_F4 , TAB_LFT, WS_UP  , TAB_RGT, LASTTAB,         KC_DEL , KC_HOME, KC_UP  , KC_END , LOCKSCR,
    __xxx__,  __xxx__, FCS_LFT, WS_DN  , C_FCS_R, TGFLOAT,         KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, __xxx__, __xxx__,
              BACK   , TILE_SM, TILE_CN, TILE_LG, ALT_TAB,         KC_APP , COPY   , PASTE  , CUT    , UNDO   ,
                                _______, _______, LAUNCHR,         _______, _______, TERMINL
    ),

    [_SYM] = LAYOUT_1x1(
              __xxx__, __xxx__, __xxx__, __xxx__, __xxx__,         DK_STAR, KC_HASH,  KC_BSLS, DK_GRV,  DK_EGU ,
    __xxx__,  DK_AMPR, DK_AT  , DK_QUES, KC_EXLM, DK_PIPE,         DK_SLSH, DK_LPRN,  DK_LBRC, DK_LCBR, DK_LABK, __xxx__,
              DK_DOL , __xxx__, __xxx__, __xxx__, __xxx__,         DK_PLUS, DK_MNUS,  DK_UNSC, DK_EQUL, DK_TILD,
                                _______, _______, _______,         _______, _______, _______
    ),

    [_NUM] = LAYOUT_1x1(
              QK_BOOT, KC_F3  , KC_F2  , KC_F1  , VOL_UP ,         KC_BRIU, KC_1   , KC_2   , KC_3   , QK_BOOT,
    KC_F12 ,  KC_F10 , KC_F6  , KC_F5  , KC_F4  , VOL_MU ,         __xxx__, KC_4   , KC_5   , KC_6   , KC_0   ,  __xxx__,
              KC_F11 , KC_F9  , KC_F8  , KC_F7  , VOL_DN ,         KC_BRID, KC_7   , KC_8   , KC_9   , __xxx__,
                                _______, _______, _______,         _______, _______, _______
    )
};