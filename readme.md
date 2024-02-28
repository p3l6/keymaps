# Keymaps
This repo contains my QMK keymaps.
It uses the "External Userspace" feature, which overlays this repo contents when building.

For maintainability, I've pinned a tag of the base repository here as a submodule, so that upgrades are not a suprise.

# Setup dependencies
1. `brew install just qmk/qmk/qmk`
2. `just setup`

# Build
1. `just build primekb/prime_e/rgb`

# Installing firmware

## Basic
`just flash primekb/prime_e/rgb`, then hit reset button, or pre-programmed reset key

## Ca66
Plug in ca66 while holding ESC, then run
`bootloadHID hex/playkbtw_ca66_me.hex`
Then plug in again

## Teensy
use teensy loader while in bootloader mode (either with soft reset or button on teensy)

## Pro micros
`flashProMicro hex/work_macropad.hex <num>`
run first command twice to find the tty that is added after shorting the pins
```
ls /dev/tty* | grep usbmodem
avrdude -p atmega32u4 -P /dev/tty.usbmodem1411  -c avr109  -U flash:w:gherkin_ePipes.hex
```
If that doesn't work, try grepping for `ACM0`
