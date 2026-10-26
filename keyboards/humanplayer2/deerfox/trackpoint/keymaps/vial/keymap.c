// Copyright 2026 Rasmus K. Rendsvig (@humanplayer2)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "btn1_lt/btn1_lt.h"

// Layers
enum {
    _BASE = 0,
    _BTN1 = 1,   // layer beneath BTN1
};

// Shorthands with length <= 7
enum my_shorthands {
    // Thumb keys
    CTL_ESC = (MT(MOD_RCTL, KC_ESC)),   // Escape, control
    SH_SPC  = (MT(MOD_RSFT, KC_SPACE)), // Space,  shift
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return process_btn1_lt(keycode, record, _BTN1); // Use BTN1_LT
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
              KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,         KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   ,
    KC_TAB ,  KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,         KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT ,
              KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,         KC_N   , KC_M   , KC_COMM, KC_DOT , KC_LBRC,
                                CTL_ESC, SH_SPC , BTN1_LT,         KC_BTN3, SH_SPC , KC_ENT
    ),
    [_BTN1] = LAYOUT(
              KC_NO  , KC_F1  , KC_F2  , KC_F3  , KC_F4  ,         KC_NO  , KC_7   , KC_8   , KC_9   , KC_NO  ,
    KC_NO  ,  KC_NO  , KC_F5  , KC_F6  , KC_F7  , KC_F8  ,         KC_NO  , KC_4   , KC_5   , KC_6   , KC_NO  , KC_NO  ,
              KC_NO  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,         KC_NO  , KC_1   , KC_2   , KC_3   , KC_0   ,
                                KC_ESC , KC_SPC , KC_NO  ,         KC_BTN2, KC_SPC , KC_ENT
    ),
};