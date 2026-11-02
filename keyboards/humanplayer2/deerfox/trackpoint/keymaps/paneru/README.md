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

## Paneru: Window management
Requires [Paneru](https://github.com/karinushka/paneru).

The `_NAV` layer has window navigation on the left side. It is intended to be used with the below Paneru keybindings (or equivalent).

```
# Window focus
window_virtualfocus_north = "cmd + ctrl - k"
window_virtualfocus_south = "cmd + ctrl - j"
window_focus_west = "cmd + ctrl - h"
window_focus_east = "cmd + ctrl - l"
window_center = "cmd + ctrl - c"

# Window state
window_shrink = "cmd + ctrl - minus"
window_grow = "cmd + ctrl - comma"
window_manage = "cmd + ctrl - f"

# Window movement
window_virtualmove_north = "shift + cmd + ctrl - k" # clinches with firefox move tab
window_virtualmove_south = "shift + cmd + ctrl - j"
window_swap_west = "shift + cmd + ctrl - h"
window_swap_east = "shift + cmd + ctrl - l"
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