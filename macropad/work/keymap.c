#include QMK_KEYBOARD_H
#include "custom-keycodes.h"

#define D_SLACK LALT(LCTL(KC_F1)) // alfred action to launch slack and send correct keycommand
#define D_ZOOM  LALT(LCTL(KC_F2)) // alfred action to launch zoom and send correct keycommand
// #define D_ZOOM  LGUI(LSFT(KC_A))
#define D_ALFRD LGUI(KC_SPC)
#define D_COPY  LGUI(KC_C)
#define D_PASTE LGUI(KC_V)
// #define D_TODO  LCTL(KC_SPC)
// #define D_DASH  LALT(KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_macro(
    D_SPC_L, D_TAB_L, Z_ALTTB, D_TAB_R, D_SPC_R, \
    D_HIDE, Z_ALTTB, D_ALFRD, D_COPY, D_PASTE, \
    KC_MRWD, KC_MPLY, KC_MFFD, D_SLACK, D_ZOOM  \
  ),
};

ALT_TAB_INIT

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  ALT_TAB_PROC_REC
  return true;
}

void matrix_scan_user(void) {
  ALT_TAB_MATRIX_SCAN
}
