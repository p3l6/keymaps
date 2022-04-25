BOOTMAGIC_ENABLE = no
BACKLIGHT_ENABLE = no      # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = yes      # Enable keyboard RGB underglow
COMMAND_ENABLE = no
TAP_DANCE_ENABLE = yes
LEADER_ENABLE = yes

SRC += ../common/caps-word.c
OPT_DEFS += -DHAS_DEDICATED_UNDERSCORE_KEY
