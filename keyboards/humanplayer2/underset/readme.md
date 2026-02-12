# Underset

<div align="center">
    <img src="https://github.com/humanplayer2/underset/blob/main/docs/images/done_top.jpg" width="600"/>
</div>
<div align="center">
    <img src="https://github.com/humanplayer2/underset/blob/main/docs/images/done_side.jpg" width="400"/>
    <img src="https://github.com/humanplayer2/underset/blob/main/docs/images/done_cover.jpg" width="400"/>
</div>

Underset is a spartan 52-key column-staggered split keyboard that features
- Aggressive pinky stagger with a key partially set under the ring finger column for three pinky keys placed almost horizontally
- RP2040-Zero controller and TRRS both set under the switch plate for simple case design that still isolates the electronics

- Keyboard maintainer: [humanplayer2](github.com/humanplayer2)
- Hardware supported: [Underset PCB](https://github.com/humanplayer2/underset)
- Hardware availability: [Open source](https://github.com/humanplayer2/underset)

> [!TIP]
> To compile/flash without Vial support, replace `vial` with `default` in the commands below.

## Compile with Vial support:  

    qmk compile -kb humanplayer2/underset -km vial

## Flash

### First flash: Set sides
Waterbear uses `EE_HANDS` to set sides, which requires writing sides to the EEPROM chip once. 

On each side, flash first with `-bl uf2-split-<left/right>` argument:

_On left side:_

    qmk flash -kb humanplayer2/underset -km vial -bl uf2-split-left

_On right side:_

    qmk flash -kb humanplayer2/underset -km vial -bl uf2-split-right


### Subsequent flashes
Henceforth, the side arguments can be omitted, so either side can be flashed with 

    qmk flash -kb humanplayer2/underset -km vial

## Bootloader of RP2040-Zero
When in bootloader mode, an RP2040-Zero controller pops up as a mountable USB drive.
- **New controller**: A previously unflashed controller enters bootloader mode when connecting it.
- **Physical boot button**: Hold the RP2040-Zero `BOOT` button while connecting, then release.
- **Physical reset button**: With the RP2040-Zero connected, press and hold `BOOT`, press and release `RESET`, then release `BOOT`.
- **Keycode in layout**: Press the key mapped to `QK_BOOT`: With the `vial` keymap flashed, on the right half, hold the center thumb and press the top right key.