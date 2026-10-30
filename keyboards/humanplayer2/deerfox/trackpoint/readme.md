# deerfox trackpoint

Trackpoint variant of Deerfox, a 38-key column-staggered split keyboard that features
- aggressive pinky stagger with a key partially set under the ring finger column for three pinky keys placed almost horizontally,
- extra ring-finger key to fit ÆØÅ on the main layer.

This variant adds a PS/2 trackpoint on the RP2040-Zero (clock on `GP2`, data on `GP1`) and places mouse buttons on the thumb keys of the base layer.

To fix [QMK issue 24455](https://github.com/qmk/qmk_firmware/issues/24455), I've applied [QMK merged PR 25942](https://github.com/qmk/qmk_firmware/pull/25942/changes).

- Keyboard maintainer: [humanplayer2](https://github.com/humanplayer2)
- Hardware supported: [Deerfox PCB](https://codeberg.org/humanplayer2/deerfox) with [Trackpoint on RP2040-Zero](https://codeberg.org/humanplayer2/trackpoint_on_rp2040zero)
- Hardware availability: Open source: [Deerfox](https://codeberg.org/humanplayer2/deerfox), [Trackpoint on RP2040-Zero](https://codeberg.org/humanplayer2/trackpoint_on_rp2040zero)

> [!TIP]
> To compile/flash without Vial support, replace `vial` with `default` in the commands below.

## Compile with Vial support

    qmk compile -kb humanplayer2/deerfox/trackpoint -km vial

## Flash

### First flash: Set sides
Deerfox by default uses `EE_HANDS` to set sides, which requires writing sides to the EEPROM chip once.

On each side, place the RP2040-Zero in bootloader mode (see below) and flash with the `-bl uf2-split-<left/right>` argument:

_On left side:_

    qmk flash -kb humanplayer2/deerfox/trackpoint -km vial -bl uf2-split-left

_On right side:_

    qmk flash -kb humanplayer2/deerfox/trackpoint -km vial -bl uf2-split-right

The controller will then exit the bootloader and re-mount as keyboard. You should now be able to remap the board, e.g. using the [Vial web interface](https://vial.rocks).

### Subsequent flashes
Henceforth, the side arguments can be omitted, so either side can be flashed with

    qmk flash -kb humanplayer2/deerfox/trackpoint -km vial

## Bootloader of RP2040-Zero
When in bootloader mode, an RP2040-Zero controller pops up as a mountable USB drive.
- **New controller**: A previously unflashed controller enters bootloader mode when connected.
- **Physical boot button**: Hold the RP2040-Zero `BOOT` button while connecting, then release.
- **Physical reset button**: With the RP2040-Zero connected, press and hold `BOOT`, press and release `RESET`, then release `BOOT`.
- **Keycode in layout**: Press the key mapped to `QK_BOOT`. With the `vial` keymap flashed, you can assign `QK_BOOT` to any key in Vial.