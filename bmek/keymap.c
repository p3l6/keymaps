#include QMK_KEYBOARD_H
#include "custom-keycodes.h"
#include "caps-word.h"

#define _BASE 0
#define _NAV 1
#define _SYMBL 2
#define _MEDIA 3

#define LT_SYMB  LT(_SYMBL, KC_ENT)
#define LT_MEDIA LT(_MEDIA, KC_GRV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT_hhkb(

KC_MPLY, KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,            KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_DEL,
Z_ALTTB, KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
D_SLACK, LT_SYMB, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
D_ZOOM,  KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,            KC_UNDS, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSPC, LT_MEDIA,
                  KC_LALT, KC_LGUI,          MO(_NAV),                 KC_SPC,           KC_RGUI, KC_RCTL

),[_NAV] = LAYOUT_hhkb(

__xxx__, KC_ESC,  D_SPC_1, D_SPC_2, D_SPC_3, D_SPC_4, __xxx__, __xxx__,         __xxx__, __xxx__, __xxx__, __xxx__, __xxx__, __xxx__, __xxx__, _______,
__xxx__, _______, KC_LGUI, Z_ALTTB, KC_UP,   D_EXPOS, D_SPC_L,                  D_SPC_R, __xxx__, KC_UP,   __xxx__, KC_PGUP, KC_HOME, __xxx__, _______,
__xxx__, KC_BSPC, KC_LALT, KC_LEFT, KC_DOWN, KC_RGHT, D_TAB_L,                  D_TAB_R, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_END,           KC_PENT,
__xxx__, KC_LSFT, D_SUBWD, D_DBG_C, D_DBG_N, D_DBG_S, D_DBG_O,         _______, __xxx__, __xxx__, __xxx__, __xxx__, __xxx__,          KC_RSFT, __xxx__,
                  _______, _______,          _______,                  _______,          _______, _______

),[_SYMBL] = LAYOUT_hhkb(

__xxx__, KC_ESC,  __xxx__, __xxx__, __xxx__, __xxx__, __xxx__, __xxx__,         __xxx__, __xxx__, __xxx__, __xxx__, __xxx__, __xxx__, __xxx__, _______,
__xxx__, _______, __xxx__, __xxx__, D_LIN_U, D_CUR_U, __xxx__,                  KC_HASH, KC_EXLM, KC_EQL,  KC_PLUS, __xxx__, Z_STCMT, Z_ENCMT, _______,
__xxx__, _______, __xxx__, __xxx__, D_LIN_D, D_CUR_D, __xxx__,                  KC_PIPE, KC_LCBR, KC_RCBR, KC_MINS, __xxx__, Z_SFRMT,          KC_PENT,
__xxx__, KC_LSFT, __xxx__, __xxx__, D_COPY,  D_PASTE, __xxx__,         _______, KC_AMPR, KC_DLR,  __xxx__, Z_ARROW, KC_BSLS,          _______, __xxx__,
                  __xxx__, __xxx__,          KC_SPC,                   _______,          __xxx__, __xxx__

),[_MEDIA] = LAYOUT_hhkb(

__xxx__, RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,           KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_F13,  KC_F14,
__xxx__, __xxx__, D_BRT_D, D_BRT_U, __xxx__, __xxx__, __xxx__,                  __xxx__, __xxx__, __xxx__, __xxx__, __xxx__, __xxx__, __xxx__, __xxx__,
__xxx__, __xxx__, KC_MUTE, KC_VOLD, KC_VOLU, __xxx__, __xxx__,                  __xxx__, __xxx__, __xxx__, __xxx__, __xxx__, __xxx__,          __xxx__,
__xxx__, KC_CAPS, KC_MRWD, KC_MPLY, KC_MFFD, __xxx__, __xxx__,         _______, __xxx__, __xxx__, __xxx__, __xxx__, __xxx__,          _______, _______,
                  __xxx__, __xxx__,          __xxx__,                  _______,          __xxx__, __xxx__

),
};

ALT_TAB_INIT

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_caps_word(keycode, record)) { return false; }
  ALT_TAB_PROC_REC

  if (record->event.pressed) {
    switch(keycode) {
      CASE(PRINT) CASE(SFRMT) CASE(JSSTR)
      SHIFTED_CASE(ARROW, LGARW)
      CASE(STCMT) CASE(ENCMT)
    }
  }
  return true;
}

// void led_set_user(uint8_t usb_led) {
	// if ( (usb_led & (1<<USB_LED_CAPS_LOCK)) || (layer_state & (1<<_NAV)) || (layer_state & (1<<_MEDIA)) ) {
  //     // Turn capslock on
  //     writePinLow(B2);
  // } else {
  //     // Turn capslock off
  //     writePinHigh(B2);
  // }
// }

void matrix_scan_user(void) {
  ALT_TAB_MATRIX_SCAN
}
