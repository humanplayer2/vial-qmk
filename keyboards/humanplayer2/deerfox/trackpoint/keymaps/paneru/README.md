# Deerfox x Paneru

The keymap is intended to be used on MacOS with 
- Danish keyboard layout,
- Paneru window manager,
- Hammerspoon (for terminal launching),
- VSCode shortcut changes to match Firefox tab navigation.

## Quirks
- Circumvent that MacOS has dead keys on ´`^~

## MacOS
Disable everything under `System Settings > Keyboard > Keyboard Shortcuts` except:
- Set `Mission Control > Mission Control` to `cmd + alt + o`
- Let `Spotlight > Show Spotlight search` stay default at `cmd + space`
- Let `Screenshots > Screenshot and recording options` stay default at `cmd + shift + 5`

## Paneru: Scrolling tiling window management
Requires [Paneru](https://github.com/karinushka/paneru).

The `_NAV` layer has window navigation on the left side. It is intended to be used with the below Paneru keybindings. The keypad is used as these are basic keycodes, so can be used as the keycode of `MT(MOD_LALT,kc)` on `_NAV` left index (good with thumb shift for word selection).

```
# Window focus
window_virtualfocus_north = "keypad8"
window_virtualfocus_south = "keypad5"
window_focus_west = "keypad4"
window_focus_east = "keypad6"
window_center = "keypad2"

# Window state
window_shrink = "keypad1"
window_grow = "keypad3"
window_manage = "keypad0"

# Window movement
window_virtualmove_north = "shift - keypad8"
window_virtualmove_south = "shift - keypad5"
window_swap_west = "shift - keypad4"
window_swap_east = "shift - keypad6"
```

## Hammerspoon: Quick access to a terminal
Requires [Hammerspoon](https://www.hammerspoon.org/).

- `right center thumb + right outer thumb (cmd + enter)` opens new terminal
- I press the `right outer thumb` with my index finger.

Quick access to opening a Kitty terminals is provided by including the below in the Hammerspoon `init.lua` config. To use Replace `kitty` with `Terminal` to open the standard Apple terminal instead.

```
hs.hotkey.bind({"cmd", "alt"}, "return", function()
    local task = hs.task.new("/usr/bin/open", nil, {"-a", "kitty", "-n"})
    task:start()
end)
```

## VSCode
The top row index and ring finger keys on the left side navigation layer switches left/right between tabs with default Firefox shortcuts. Holding Shift moves the current tab left/right instead. To get the same behavior in VSCode, include in your ```keybindings.json```:
```
  { "key": "ctrl+pageup",         "command": "workbench.action.previousEditor" },
  { "key": "ctrl+pagedown",       "command": "workbench.action.nextEditor" },
  { "key": "ctrl+shift+pageup",   "command": "workbench.action.moveEditorLeftInGroup" },
  { "key": "ctrl+shift+pagedown", "command": "workbench.action.moveEditorRightInGroup" },
```