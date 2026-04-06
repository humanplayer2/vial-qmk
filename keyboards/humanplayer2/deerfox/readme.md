# deerfox

Deerfox is a 38-key column-staggered split keyboard that features
- aggressive pinky stagger with a key partially set under the ring finger column for three pinky keys placed almost horizontally,
- extra ring-finger key to fit ÆØÅ on the main layer.

- Keyboard maintainer: [humanplayer2](github.com/humanplayer2)
- Hardware supported: [Underset PCB](https://codeberg.org/humanplayer2/deerfox)
- Hardware availability: [Open source](https://codeberg.org/humanplayer2/deerfox)

> [!TIP]
> To compile/flash without Vial support, replace `vial` with `default` in the commands below.

## Compile with Vial support:  

    qmk compile -kb humanplayer2/deerfox -km vial

## Flash

### First flash: Set sides
Deerfox by default uses `EE_HANDS` to set sides, which requires writing sides to the EEPROM chip once.

On each side, place the RP2040-Zero in bootloader mode (see below) and first with `-bl uf2-split-<left/right>` argument:

_On left side:_

    qmk flash -kb humanplayer2/deerfox -km vial -bl uf2-split-left

_On right side:_

    qmk flash -kb humanplayer2/deerfox -km vial -bl uf2-split-right

The controller will then exit the bootloader and re-mount as keyboard. You should now be able to remap the board e.g. using the [Vial web interface](vial.rocks).

### Subsequent flashes
Henceforth, the side arguments can be omitted, so either side can be flashed with 

    qmk flash -kb humanplayer2/deerfox -km vial

## Bootloader of RP2040-Zero
When in bootloader mode, an RP2040-Zero controller pops up as a mountable USB drive.
- **New controller**: A previously unflashed controller enters bootloader mode when connecting it.
- **Physical boot button**: Hold the RP2040-Zero `BOOT` button while connecting, then release.
- **Physical reset button**: With the RP2040-Zero connected, press and hold `BOOT`, press and release `RESET`, then release `BOOT`.
- **Keycode in layout**: Press the key mapped to `QK_BOOT`: With the `vial` keymap flashed, ...