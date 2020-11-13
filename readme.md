# Keymaps
This repo contains my QMK keymaps. I have extracted them due to the size and maintainability of
storing them in the main QMK repo. Instead, the qmk firmware repository is included as a submodule.
On build, files from this repository are copied into the submodule, and a standard build is performed.

# Install dependencies
1. `brew tap osx-cross/avr`
2. `brew tap PX4/px4 `
3. `brew install avr-gcc dfu-programmer gcc-arm-none-eabi avrdude`

# Build
1. (on a fresh clone only) `make fresh`
2. `make`

# Installing firmware
## Dz60
`make install-dz60`, then hit reset key on bottom of board

## Ca66
Plug in ca66 while holding ESC, then run
`bootloadHID hex/ca66.hex`
Then plug in again

## Tada68
* `make tada68:pwxn` (in qmk_firmware directory)
* hit reset key.
* I now have a shortcut: `flashTada hex/tada68.bin`
* Alternatively:
	* replace flash.bin file on mounted storage, keep naming the same.
	* remove any files that mac added.
	* eject volume, replug keyboard. (use escape key on keyboard to force eject)
* To flash when theres only one keyboard: `sleep 10 && flashTada hex/tada68.bin` will give enough time to reset it

## Teensy installing
use teensy loader while in bootloader mode (either with soft reset or button on teensy)

## Pro micro
run first command twice to find the tty that is added after shorting the pins
```
ls /dev/tty* | grep ACM0
sudo avrdude -p atmega32u4 -P /dev/ttyACM0  -c avr109  -U flash:w:gherkin_paulLayout.hex
avrdude -p atmega32u4 -P /dev/tty.usbmodem1411  -c avr109  -U flash:w:gherkin_ePipes.hex
```
