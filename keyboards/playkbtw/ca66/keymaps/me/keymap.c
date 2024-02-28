#include QMK_KEYBOARD_H
#include "custom-keycodes.h"

#define _BASE 0
#define _NAV 1
#define _MEDIA 3

#define LT_NAV  LT(_NAV, KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Backlighting is just weird. Since I don't use it, I've disabled it for now.

  /* Light bar control keys:
     RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI,
     RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD,
  */

[_BASE] = LAYOUT(

QK_GESC,          KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_BSLS, KC_DEL,  KC_GRV,
KC_TAB,           KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,  KC_RBRC, KC_BSPC,          KC_PGUP,
LT_NAV,           KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,           KC_ENT,           KC_PGDN,
SC_LSPO, XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SC_RSPC,           KC_UP,            MO(_MEDIA),
XXXXXXX,          KC_LALT, KC_LGUI,          XXXXXXX,          KC_SPC,           XXXXXXX,          KC_RGUI, KC_RCTL,  KC_LEFT, KC_DOWN, KC_RGHT

),[_NAV] = LAYOUT(

KC_ESC,           D_SPC_1, D_SPC_2, D_SPC_3, D_SPC_4, __xxx__, __xxx__, __xxx__, __xxx__, __xxx__, __xxx__, __xxx__,  __xxx__, __xxx__, __xxx__, __xxx__,
KC_ENT,           D_SUBWD, Z_ALTTB, KC_UP,   D_EXPOS, D_SPC_L, D_SPC_R, __xxx__, KC_UP,   __xxx__, KC_PGUP, KC_HOME,  __xxx__, KC_DEL,           __xxx__,
_______,          KC_LALT, KC_LEFT, KC_DOWN, KC_RGHT, D_TAB_L, D_TAB_R, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_END,            KC_PENT,          __xxx__,
KC_LSFT, XXXXXXX, KC_LGUI, D_DBG_C, D_DBG_N, D_DBG_S, D_DBG_O, __xxx__, __xxx__, __xxx__, __xxx__, __xxx__, KC_RSFT,           __xxx__,          __xxx__,
XXXXXXX,          _______, _______,          XXXXXXX,          _______,          XXXXXXX,          _______, __xxx__,  __xxx__, __xxx__, __xxx__


),[_MEDIA] = LAYOUT(

KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,  KC_F13,  __xxx__, __xxx__,
__xxx__,          KC_SCRL, KC_PAUS, BL_DOWN, BL_UP,   BL_TOGG, __xxx__, __xxx__, __xxx__, __xxx__, __xxx__, Z_STCMT,  Z_ENCMT, KC_DEL,           __xxx__,
__xxx__,          KC_MUTE, KC_VOLD, KC_VOLU, __xxx__, __xxx__, __xxx__, __xxx__, __xxx__, __xxx__, __xxx__, Z_JSSTR,           KC_PENT,          __xxx__,
KC_CAPS, XXXXXXX, KC_MRWD, KC_MPLY, KC_MFFD, __xxx__, __xxx__, __xxx__, __xxx__, Z_ARROW, __xxx__, __xxx__, _______,           _______,          _______,
XXXXXXX,          __xxx__, __xxx__,          XXXXXXX,          __xxx__,            XXXXXXX,        __xxx__, __xxx__, _______,  _______,  _______

),
};

ALT_TAB_INIT

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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

bool led_update_user(led_t led_state) {
  bool caps = led_state.caps_lock;
  bool nav = (layer_state & (1<<_NAV));
  bool media = (layer_state & (1<<_MEDIA));
  bool on = caps || nav || media;

  if ( on ) { rgblight_enable_noeeprom(); rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT); } else { rgblight_disable_noeeprom(); return false; }

  if ( nav ) { sethsv(HSV_GREEN, (rgb_led_t *)&led[0]); } else { sethsv(HSV_OFF, (rgb_led_t *)&led[0]); }
  sethsv(HSV_OFF, (rgb_led_t *)&led[1]);
  if ( caps ) { sethsv(HSV_RED  , (rgb_led_t *)&led[2]); } else { sethsv(HSV_OFF, (rgb_led_t *)&led[2]); }
  sethsv(HSV_OFF, (rgb_led_t *)&led[3]);
  if ( media ) { sethsv(HSV_BLUE , (rgb_led_t *)&led[4]); } else { sethsv(HSV_OFF, (rgb_led_t *)&led[4]); }
  sethsv(HSV_OFF, (rgb_led_t *)&led[5]);

  if ( on ) { rgblight_set(); }

  return false;
}

void matrix_scan_user(void) {
  ALT_TAB_MATRIX_SCAN
}
