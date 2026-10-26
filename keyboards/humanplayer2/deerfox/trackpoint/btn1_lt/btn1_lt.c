// Copyright 2026 Rasmus K. Rendsvig (@humanplayer2)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "btn1_lt.h"

// Variables for BTN1_LT
static bool btn1lt_down     = false; // is BTN1_LT down?
static bool btn1lt_layer    = false; // is the layer on?
static bool btn1lt_triggeringkey_is_down = false; // are we tracking a triggering key that we must remember to release?
static keypos_t btn1lt_key_pos;      // matrix position of the triggering key
static uint16_t btn1lt_keycode;      // keycode sent, as mapped through the layer

// Keys that trigger the layer: Basic keycodes (<= 0xFF) that are not modifiers.
static bool btn1lt_triggers(uint16_t keycode) {
    return keycode <= 0xFF && !IS_MODIFIER_KEYCODE(keycode);
}

bool process_btn1_lt(uint16_t keycode, keyrecord_t *record, uint8_t layer) {
    // BTN1_LT
    if (keycode == BTN1_LT) {
        if (record->event.pressed) {
            btn1lt_down  = true;
            btn1lt_layer = false;
            register_code(KC_BTN1); // no waiting for BTN1, but BTN1 is sent also when moving to the layer
        } else {
            if (btn1lt_layer) {
                layer_off(layer);
            } else {
                unregister_code(KC_BTN1);
            }

            btn1lt_down  = false;
            btn1lt_layer = false;
        }

        return false;
    }

    // Release of the key that we recorded and registered:
    if (btn1lt_triggeringkey_is_down &&
        record->event.key.row == btn1lt_key_pos.row &&
        record->event.key.col == btn1lt_key_pos.col) {

        if (!record->event.pressed) {
            unregister_code16(btn1lt_keycode);
            btn1lt_triggeringkey_is_down = false; // reset trigger flag
        }

        return false;
    }

    // If BTN1 is down, the layer is not on, and a trigger key is pressed:
    if (btn1lt_down &&
        !btn1lt_layer &&
        record->event.pressed &&
        btn1lt_triggers(keycode)) {

        // Map the triggering key through the layer and keep the mapped keycode for sending
        uint16_t send_this_keycode = keymap_key_to_keycode(layer, record->event.key);
        // (unless the mapped keycode is transparent, then send the triggering key itself)
        if (send_this_keycode == KC_TRNS) {
            send_this_keycode = keycode;
        }

        // If we're tracking a triggering key currently,
        // release it before switching tracking to this one
        if (btn1lt_triggeringkey_is_down) {
            unregister_code16(btn1lt_keycode);
        }

        unregister_code(KC_BTN1); // send up, as else stuck down.
        layer_on(layer);
        btn1lt_layer = true;

        btn1lt_key_pos  = record->event.key;
        btn1lt_keycode  = send_this_keycode;
        btn1lt_triggeringkey_is_down = true;

        register_code16(send_this_keycode);

        return false;
    }

    return true;
}