// Copyright 2026 Rasmus K. Rendsvig (@humanplayer2)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "quantum.h"

// Custom keycodes (vial.json customKeycodes must match order)
enum btn1_lt_keycodes {
    BTN1_LT = QK_KB_0,   // BTN1 "layer-tap" to a layer, see process_btn1_lt()
};

// Call from process_record_user(). Returns false if the event was handled.
bool process_btn1_lt(uint16_t keycode, keyrecord_t *record, uint8_t layer);