# AMC48K
48 key Ortholinear keyboard.

![screenshot](amc48k_front.png)
- RP2040 promicro.
- 48 RGB leds
- Rotary encoder
- 3D printed case, and plate.

# QMK Features
- Caps word  (tap both shift to activate next word caps lock)
- Mouse emulation
  - FN "Arrow keys" 
- Dynamic Macros: Record and Replay Macros in Runtime
  - Lower "a" record 1
  - Lower "z" play 1
  - Lower "s" record 2
  - Lower "x" play 2
  - Lower "d" Stop recording 

![screenshot](amc48k_sideview.png)

## to do 
- Rotary encoder

# How to Build
- [Components](components/bom.md) required.
- PCB *TBD*
- Case *TBD*


# Other stuff...

## ANSI vs ISO backslash
- KC_NONUS_BACKSLASH	KC_NUBS	Non-US \ and |	✔	✔	✔
- KC_BACKSLASH	KC_BSLS	\ and |	✔	✔	✔

- KC_NONUS_HASH	KC_NUHS	Non-US # and ~	✔	✔	✔

## RP2040 startup
https://docs.qmk.fm/#/platformdev_rp2040?id=double-tap
