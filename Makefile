.PHONY: fresh clean flash-dz60
export QMK_HOME='./qmk_firmware'

HEX_BOARDS=ca66 dz60 macropad-work bmek tokyo60
BIN_BOARDS=tada68 tada68-hhkb

BOARDS=$(BIN_BOARDS) $(BIN_BOARDS)
HEXES=$(patsubst %, hex/%.hex, $(HEX_BOARDS))
BINS=$(patsubst %, hex/%.bin, $(BIN_BOARDS))
all: $(HEXES) $(BINS)

COMMON = $(patsubst common/%, qmk_firmware/users/pwxn/%, $(wildcard common/*))
qmk_firmware/users/pwxn/%: common/%
	@mkdir -p $(@D)
	cp $< $@


BMEK = $(patsubst bmek/%, qmk_firmware/keyboards/bemeier/bmek/keymaps/pwxn/%, $(wildcard bmek/*))
qmk_firmware/keyboards/bemeier/bmek/keymaps/pwxn/%: bmek/%
	@mkdir -p $(@D)
	cp $< $@
hex/bmek.hex: $(BMEK) $(COMMON) | hex
	qmk compile -kb bemeier/bmek/rev3 -km pwxn
	cp qmk_firmware/bemeier_bmek_rev3_pwxn.hex $@
flash-bmek: hex/bmek.hex
	qmk flash -kb bemeier/bmek/rev3 -km pwxn


TOKYO60 = $(patsubst tokyo60/%, qmk_firmware/keyboards/tokyokeyboard/tokyo60/keymaps/pwxn/%, $(wildcard tokyo60/*))
qmk_firmware/keyboards/tokyokeyboard/tokyo60/keymaps/pwxn/%: tokyo60/%
	@mkdir -p $(@D)
	cp $< $@
hex/tokyo60.hex: $(TOKYO60) $(COMMON) | hex
	qmk compile -kb tokyokeyboard/tokyo60 -km pwxn
	cp qmk_firmware/tokyokeyboard_tokyo60_pwxn.hex $@
flash-tokyo60: hex/tokyo60.hex
	qmk flash -kb tokyokeyboard/tokyo60 -km pwxn


DZ60 = $(patsubst dz60/%, qmk_firmware/keyboards/dz60/keymaps/pwxn/%, $(wildcard dz60/*))
qmk_firmware/keyboards/dz60/keymaps/pwxn/%: dz60/%
	@mkdir -p $(@D)
	cp $< $@
hex/dz60.hex: $(DZ60) $(COMMON) | hex
	qmk compile -kb dz60 -km pwxn
	cp qmk_firmware/dz60_pwxn.hex $@
flash-dz60: hex/dz60.hex
	qmk flash -kb dz60 -km pwxn


CA66 = $(patsubst ca66/%, qmk_firmware/keyboards/playkbtw/ca66/keymaps/pwxn/%, $(wildcard ca66/*))
qmk_firmware/keyboards/playkbtw/ca66/keymaps/pwxn/%: ca66/%
	@mkdir -p $(@D)
	cp $< $@
hex/ca66.hex: $(CA66) $(COMMON) | hex
	qmk compile -kb playkbtw/ca66 -km pwxn
	cp qmk_firmware/playkbtw_ca66_pwxn.hex $@


TADA = $(patsubst tada68/%, qmk_firmware/keyboards/tada68/keymaps/pwxn/%, $(wildcard tada68/*))
qmk_firmware/keyboards/tada68/keymaps/pwxn/%: tada68/%
	@mkdir -p $(@D)
	cp $< $@
hex/tada68.bin: $(TADA) $(COMMON) | hex
	qmk compile -kb tada68 -km pwxn
	cp qmk_firmware/tada68_pwxn.bin $@


TADA-HHKB = $(patsubst tada68-hhkb/%, qmk_firmware/keyboards/tada68/keymaps/pwxn-hhkb/%, $(wildcard tada68-hhkb/*))
qmk_firmware/keyboards/tada68/keymaps/pwxn-hhkb/%: tada68-hhkb/%
	@mkdir -p $(@D)
	cp $< $@
hex/tada68-hhkb.bin: $(TADA-HHKB) $(COMMON) | hex
	qmk compile -kb tada68 -km pwxn-hhkb
	cp qmk_firmware/tada68_pwxn-hhkb.bin $@


WORK = $(patsubst macropad/work/%, qmk_firmware/keyboards/40percentclub/foobar/keymaps/work/%, $(wildcard macropad/work/*))
qmk_firmware/keyboards/40percentclub/foobar/keymaps/work/%: macropad/work/%
	@mkdir -p $(@D)
	cp $< $@
hex/macropad-work.hex: $(WORK) $(COMMON) | hex
	qmk compile -kb 40percentclub/foobar -km work
	cp qmk_firmware/40percentclub_foobar_work.hex $@



hex:
	mkdir -p hex

clean:
	rm -rf hex
	rm -rf $(COMMON) $(CA66) $(DZ60) $(TADA) $(TADA-HHKB) $(WORK)
	make -C qmk_firmware clean

# TODO:
# make 40percentclub/foobarMacro:diablo
# make 40percentclub/gherkin:ePipes
# make paulKeyboard:default

fresh:
	git submodule init
	git submodule update
	python3 -m pip install -r qmk_firmware/requirements.txt
	make -C qmk_firmware git-submodule
