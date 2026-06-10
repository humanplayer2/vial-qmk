// Copyright 2026 Rasmus K. Rendsvig (@humanplayer2)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Layers
enum {
    _BASE  = 0,
};

#define DK_EGU UP(DK_E_AIGU_LOWER, DK_E_AIGU_UPPER)

// Keycode names:
enum my_keycodes {
  // Thumb keys
CTL_ESC = (MT(MOD_RCTL,KC_ESC)),   // Escape, control
SH_SPC  = (MT(MOD_RSFT,KC_SPACE)), // Space,  shift
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_1x1(
              KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,         KC_Y   , KC_U   , KC_I   , KC_O   , KC_P,
    KC_TAB ,  KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,         KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT ,
              KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,         KC_N   , KC_M   , KC_COMM, KC_DOT , KC_LBRC ,
                                CTL_ESC, SH_SPC , KC_LALT,         KC_LALT, KC_SPC , KC_ENT
    )
};