#include "tada68.h"
#include "custom-keycodes.h"

#define _BL 0
#define _NL 1
#define _ML 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BL] = LAYOUT_65_ansi_split_backspace_hack(
    KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_DEL, KC_GRV,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,         KC_PGUP,
    MO(_NL), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,          KC_PGDN,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,           MO(_ML),
    KC_LCTL, KC_LALT, KC_LGUI,                   KC_SPC,                             KC_RGUI, KC_RCTL, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT),

[_NL] = LAYOUT_65_ansi_split_backspace_hack(
    KC_ESC,  __xxx__, __xxx__, __xxx__, __xxx__, __xxx__, __xxx__, __xxx__, __xxx__, __xxx__, __xxx__, __xxx__, __xxx__, __xxx__, __xxx__, __xxx__,
    KC_ENT,  __xxx__, KC_UP,   D_EXPOS, __xxx__, D_SPC_L, D_SPC_R, __xxx__, KC_UP,   __xxx__, KC_PGUP, KC_HOME, __xxx__, KC_DEL,           __xxx__,
    _______, KC_LEFT, KC_DOWN, KC_RGHT, __xxx__, D_TAB_L, D_TAB_R, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_END,           KC_PENT,          __xxx__,
    _______, D_DBG_C, D_DBG_N, D_DBG_S, D_DBG_O, __xxx__, __xxx__, __xxx__, __xxx__, __xxx__, __xxx__, _______,          __xxx__,          __xxx__,
    _______, _______, _______,                   _______,                            _______, _______, XXXXXXX, __xxx__, __xxx__, __xxx__),

[_ML] = LAYOUT_65_ansi_split_backspace_hack(
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_F13,  __xxx__, __xxx__,
    __xxx__, KC_SLCK, KC_PAUS, BL_DEC,  BL_INC,  BL_TOGG, __xxx__, __xxx__, __xxx__, __xxx__, __xxx__, Z_STCMT, Z_ENCMT, KC_DEL,           __xxx__,
    __xxx__, KC_MUTE, KC_VOLD, KC_VOLU, __xxx__, __xxx__, __xxx__, __xxx__, __xxx__, __xxx__, __xxx__, Z_JSSTR,          KC_PENT,          __xxx__,
    KC_CAPS, KC_MRWD, KC_MPLY, KC_MFFD, __xxx__, __xxx__, __xxx__, __xxx__, Z_ARROW, Z_LGARW, __xxx__, _______,          _______,          _______,
    __xxx__, __xxx__, __xxx__,                   __xxx__,                            __xxx__, __xxx__, XXXXXXX, _______, _______, _______),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	// See https://docs.qmk.fm/macros.html
  if (record->event.pressed) {
    switch(keycode) {
      CASE(NSSTR) CASE(NSLOG)
      CASE(ATQOT) CASE(PRINT) CASE(SFRMT) CASE(PARAM) CASE(JSSTR)
      CASE(ARROW) CASE(LGARW)
      CASE(STCMT) CASE(ENCMT)
    }
  }
  return true;
}

void led_set_user(uint8_t usb_led) {
	if ( (usb_led & (1<<USB_LED_CAPS_LOCK)) || (layer_state & (1<<_NL)) || (layer_state & (1<<_ML)) ) {
        // Turn capslock on
        PORTB &= ~(1<<2);
    } else {
        // Turn capslock off
        PORTB |= (1<<2);
    }
}
