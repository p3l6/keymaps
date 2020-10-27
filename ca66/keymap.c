#include QMK_KEYBOARD_H
#include "custom-keycodes.h"

#define _BL 0
#define _NL 1
#define _ML 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Backlighting is just weird. Since I don't use it, I've disabled it for now.

  /* Light bar control keys:
     RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI,
     RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD,
  */

[_BL] = LAYOUT(
    KC_GESC,          KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_BSLS, KC_DEL,  KC_GRV,
    KC_TAB,           KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,  KC_RBRC, KC_BSPC,          KC_PGUP,
    MO(_NL),          KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,           KC_ENT,           KC_PGDN,
    KC_LSFT, XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,           KC_UP,            MO(_ML),
    XXXXXXX,          KC_LALT, KC_LGUI,          XXXXXXX,          KC_SPC,           XXXXXXX,          KC_RGUI, KC_RCTL,  KC_LEFT, KC_DOWN, KC_RGHT),

[_NL] = LAYOUT(
    KC_ESC,           __xxx__, __xxx__, __xxx__, __xxx__, __xxx__, __xxx__, __xxx__, __xxx__, __xxx__, __xxx__, __xxx__,  __xxx__, __xxx__, __xxx__, __xxx__,
    KC_ENT,           __xxx__, KC_UP,   D_EXPOS, __xxx__, D_SPC_L, D_SPC_R, __xxx__, KC_UP,   __xxx__, KC_PGUP, KC_HOME,  __xxx__, KC_DEL,           __xxx__,
    _______,          KC_LEFT, KC_DOWN, KC_RGHT, __xxx__, D_TAB_L, D_TAB_R, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_END,            KC_PENT,          __xxx__,
    _______, XXXXXXX, D_DBG_C, D_DBG_N, D_DBG_S, D_DBG_O, __xxx__, __xxx__, __xxx__, __xxx__, __xxx__, __xxx__, _______,           __xxx__,          __xxx__,
    XXXXXXX,          _______, _______,          XXXXXXX,          _______,          XXXXXXX,          _______, __xxx__,  __xxx__, __xxx__, __xxx__),

[_ML] = LAYOUT(
    KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,  KC_F13,  __xxx__, __xxx__,
    __xxx__,          KC_SLCK, KC_PAUS, BL_DEC,  BL_INC,  BL_TOGG, __xxx__, __xxx__, __xxx__, __xxx__, __xxx__, Z_STCMT,  Z_ENCMT, KC_DEL,           __xxx__,
    __xxx__,          KC_MUTE, KC_VOLD, KC_VOLU, __xxx__, __xxx__, __xxx__, __xxx__, __xxx__, __xxx__, __xxx__, Z_JSSTR,           KC_PENT,          __xxx__,
    KC_CAPS, XXXXXXX, KC_MRWD, KC_MPLY, KC_MFFD, __xxx__, __xxx__, __xxx__, __xxx__, Z_ARROW, Z_LGARW, __xxx__, _______,           _______,          _______,
    XXXXXXX,          __xxx__, __xxx__,          XXXXXXX,          __xxx__,            XXXXXXX,        __xxx__, __xxx__, _______,  _______,  _______),
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

#define HSV_OFF 0,   0,   0

void led_set_user(uint8_t usb_led) {
  bool caps = (usb_led & (1 << USB_LED_CAPS_LOCK)) ;
  bool nav = (layer_state & (1<<_NL));
  bool media = (layer_state & (1<<_ML));
  bool on = caps || nav || media;

  if ( on ) { rgblight_enable_noeeprom(); rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT); } else { rgblight_disable_noeeprom(); return; }

  if ( nav ) { sethsv(HSV_GREEN, (LED_TYPE *)&led[0]); } else { sethsv(HSV_OFF, (LED_TYPE *)&led[0]); }
  sethsv(HSV_OFF, (LED_TYPE *)&led[1]);
  if ( caps ) { sethsv(HSV_RED  , (LED_TYPE *)&led[2]); } else { sethsv(HSV_OFF, (LED_TYPE *)&led[2]); }
  sethsv(HSV_OFF, (LED_TYPE *)&led[3]);
  if ( media ) { sethsv(HSV_BLUE , (LED_TYPE *)&led[4]); } else { sethsv(HSV_OFF, (LED_TYPE *)&led[4]); }
  sethsv(HSV_OFF, (LED_TYPE *)&led[5]);

  if ( on ) { rgblight_set(); }

  return;
}
