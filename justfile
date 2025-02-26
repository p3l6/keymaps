default_keymap := 'me'

list-keyboards:
    @echo These keyboards may be passed to build or flash
    @echo
    @echo primekb/prime_e/rgb
    @echo bemeier/bmek/rev3
    @echo keebio/quefrency/rev3
    @echo tokyokeyboard/tokyo60
    @echo dz60
    @echo playkbtw/ca66
    @echo 40percentclub/foobar work

build-all: (build "primekb/prime_e/rgb") (build "bemeier/bmek/rev3") (build "keebio/quefrency/rev3") (build "tokyokeyboard/tokyo60") (build "dz60") (build "playkbtw/ca66") (build "40percentclub/foobar" "work")

# Build a keymap hex file
build keyboard keymap=default_keymap: && _move-hex
    qmk compile -kb {{keyboard}} -km {{keymap}}

# Install a keymap hex file
flash keyboard keymap=default_keymap: (build keyboard keymap) && _move-hex
    -qmk flash -kb {{keyboard}} -km {{keymap}}

# Runs clean in the qmk directory
clean: _move-hex
    rm -rf hex
    make -C qmk_firmware clean

# Setup qmk specific configs
setup:
    git submodule init
    git submodule update
    make -C qmk_firmware git-submodule
    qmk setup -H ./qmk_firmware
    qmk config user.overlay_dir="$(realpath .)"

_move-hex:
    mkdir -p hex
    mv *.hex hex/
