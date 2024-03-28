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

![screenshot](amc48k_sideview.png)

## to do 
- Dynamic Macros: Record and Replay Macros in Runtime
- Rotary encoder
- Commands (magic key) for debug

## ANSI vs ISO backslash
- KC_NONUS_BACKSLASH	KC_NUBS	Non-US \ and |	✔	✔	✔
- KC_BACKSLASH	KC_BSLS	\ and |	✔	✔	✔

- KC_NONUS_HASH	KC_NUHS	Non-US # and ~	✔	✔	✔

# RP2040 startup
https://docs.qmk.fm/#/platformdev_rp2040?id=double-tap
