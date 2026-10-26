# BTN1_LT
> A mouse button 1 "layer-tap" hack that allows dragging.

`BTN1_LT` is a normal mouse button 1 `KC_BTN1` unless another basic `key` is pressed, then it acts as an `MO(layer)` (also on the triggering `key`).

## What it does

**Press:** `KC_BTN1` down immediately. There is no time-out, so you can drag.  
**Release with nothing else pressed:** `KC_BTN1` is released.  
**If a key is pressed while held:**  
- `KC_BTN1` is released,
- `_BTN1` layer turns on,
- the key is send after mapping through `_BTN1`, and
- `_BTN1` layer stays on until `BTN1_LT` is released.

## Layer-triggering keycodes

**Only basic:** Only keys that have a basic keycode on layer `_BASE` turn on `_BTN1`.
    - with modifiers and mod-taps ignored, you can `Shift`-drag and `Ctrl`-click without layer jumping.  
**Transparency:** If the triggering keys keycode is `KC_TRNS` on `_BTN1`, the keys `_BASE` value is sent.

## Quirks
When you press `BTN1_LT`, you _will_ send `KC_BTN1` down and up, perhaps with stuff you've typed in between.