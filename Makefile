.PHONY: fresh rsync install-dz60

all: rsync hex/ca66.hex hex/dz60.hex hex/tada68.bin hex/tada68-hhkb.bin

rsync:
	rsync -rut --delete common/ qmk_firmware/users/pwxn
	rsync -rut --delete ca66/ qmk_firmware/keyboards/playkbtw/ca66/keymaps/pwxn
	rsync -rut --delete dz60/ qmk_firmware/keyboards/dz60/keymaps/pwxn
	rsync -rut --delete tada68/ qmk_firmware/keyboards/tada68/keymaps/pwxn
	rsync -rut --delete tada68-hhkb/ qmk_firmware/keyboards/tada68/keymaps/pwxn-hhkb

hex/ca66.hex: ca66/* common/*
	make -C qmk_firmware playkbtw/ca66:pwxn
	mkdir -p hex
	cp qmk_firmware/playkbtw_ca66_pwxn.hex hex/ca66.hex

hex/dz60.hex: dz60/* common/*
	make -C qmk_firmware dz60:pwxn
	mkdir -p hex
	cp qmk_firmware/dz60_pwxn.hex hex/dz60.hex

hex/tada68.bin: tada68/* common/*
	make -C qmk_firmware tada68:pwxn
	mkdir -p hex
	cp qmk_firmware/tada68_pwxn.bin hex/tada68.bin

hex/tada68-hhkb.bin: tada68-hhkb/* common/*
	make -C qmk_firmware tada68:pwxn-hhkb
	mkdir -p hex
	cp qmk_firmware/tada68_pwxn-hhkb.bin hex/tada68-hhkb.bin

install-dz60: hex/dz60.hex
	make -C qmk_firmware dz60:pwxn:dfu

# TODO:
# make 40percentclub/foobarMacro:default
# make 40percentclub/foobarMacro:diablo
# make 40percentclub/gherkin:ePipes
# make paulKeyboard:default

fresh:
	git submodule init
	git submodule update
	make -C qmk_firmware git-submodule
