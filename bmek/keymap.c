#include QMK_KEYBOARD_H
#include "custom-keycodes.h"

#define _BASE 0
#define _GRAV 1 // a secondary base layer that changes underscore -> grave accent
#define _PLAIN 2 // a secondary base layer that hides most special functions, behind the fn key
#define _NAV 3
#define _SYMBL 4
#define _CODE 5

#define LT_SYMB  LT(_SYMBL, KC_TAB)
#define LT_MEDIA LT(_MEDIA, KC_GRV)

#define BASE_B DF(_BASE)
#define BASE_G DF(_GRAV)
#define BASE_P DF(_PLAIN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT_hhkb(

Z_ALTTB, QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,            KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_DEL,
T_PLNXT, KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
D_SLACK, LT_SYMB, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT, KC_SCLN,          KC_ENT,
D_ZOOM,  KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,            KC_UNDS, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSPC, MO(_CODE),
                  KC_LALT, KC_LGUI,          MO(_NAV),                 KC_SPC,           KC_RGUI, KC_RCTL

),[_GRAV] = LAYOUT_hhkb(

_______, _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______,
_______, _______, _______, _______, _______, _______, _______,                  _______, _______, _______, _______, _______, _______, _______, _______,
_______, _______, _______, _______, _______, _______, _______,                  _______, _______, _______, _______, _______, _______, _______,
_______, _______, _______, _______, _______, _______, _______,     LALT(KC_GRV), _______, _______, _______, _______, _______,          _______, _______,
                  _______, _______,          _______,                  _______,          _______, _______

),[_PLAIN] = LAYOUT_hhkb(

KC_GRV,  KC_ESC,  _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______,
_______, _______, _______, _______, _______, _______, _______,                  _______, _______, _______, _______, _______, _______, _______, _______,
__xxx__, __xxx__, _______, _______, _______, _______, _______,                  _______, _______, _______, _______, _______, _______, _______,
KC_LCTL, KC_LSFT, _______, _______, _______, _______, _______,          KC_DOT, _______, _______, _______, _______, _______,          KC_RSFT, MO(_NAV),
                  _______, _______,          KC_SPC,                  _______,          _______, _______

),[_NAV] = LAYOUT_hhkb(

QK_BOOT, KC_ESC,  D_SPC_1, D_SPC_2, D_SPC_3, D_SPC_4, KC_VOLD, KC_VOLU,         __xxx__, __xxx__, __xxx__, __xxx__, __xxx__, _______, __xxx__, _______,
BASE_B,  KC_BSPC, D_SUBWD, D_LIN_U, KC_UP,   D_EXPOS, D_CUR_U,                  D_SPC_L, D_SPC_R, KC_UP,   KC_HOME, KC_PGUP, _______, __xxx__, _______,
__xxx__, KC_ENT,  KC_LALT, KC_LEFT, KC_DOWN, KC_RGHT, D_CUR_D,                  _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______,           KC_PENT,
__xxx__, KC_LSFT, KC_LGUI, D_LIN_D, D_SWAP,  D_ALF_V, D_CUR_N,         D_TAB_L, D_TAB_R, _______, _______, _______, KC_END,          KC_RSFT, __xxx__,
                  _______, _______,          _______,                  _______,          _______, _______

),[_SYMBL] = LAYOUT_hhkb(

__xxx__, KC_ESC,  D_DBG_C, D_DBG_N, D_DBG_S, D_DBG_O, KC_VOLD, KC_VOLU,         __xxx__, __xxx__, __xxx__, __xxx__, __xxx__, __xxx__, __xxx__, _______,
BASE_P,  _______, KC_LT,   KC_GT,   KC_LBRC, KC_RBRC, Z_MTODO,                  KC_AT,   KC_EXLM, KC_PIPE, KC_ASTR, KC_CIRC, __xxx__, __xxx__, _______,
BASE_G,  _______, __xxx__, KC_DLR,  KC_LCBR, KC_RCBR, __xxx__,                  KC_HASH, KC_EQL,  KC_MINS, KC_PLUS, KC_GRV,  KC_GRV,           KC_PENT,
BASE_B,  KC_LSFT, __xxx__, KC_BSLS, KC_LPRN, KC_RPRN, Z_ARROW,         KC_PERC, KC_AMPR, KC_DLR,  KC_SCLN, KC_COLN, KC_BSLS,          _______, __xxx__,
                  __xxx__, __xxx__,          KC_SPC,                   _______,          __xxx__, __xxx__

),[_CODE] = LAYOUT_hhkb(

__xxx__, KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,           KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_F13,  _______,
__xxx__, _______, KC_VOLD, KC_VOLU, T_PLNXT, __xxx__, __xxx__,                  __xxx__, __xxx__, __xxx__, __xxx__, __xxx__, __xxx__, __xxx__, _______,
__xxx__, _______, __xxx__, Z_SEL_W, Z_DEL_W, __xxx__, __xxx__,                  __xxx__, __xxx__, __xxx__, __xxx__, __xxx__, __xxx__,          KC_PENT,
__xxx__, KC_LSFT, __xxx__, __xxx__, Z_SSHOT, __xxx__, __xxx__,         __xxx__, __xxx__, D_DBG_C, D_DBG_N, D_DBG_S, D_DBG_O,          KC_CAPS, _______,
                  __xxx__, __xxx__,          KC_SPC,                   _______,          __xxx__, __xxx__
),
};

ALT_TAB_INIT
TAP_DANCE_INIT
bool caps_word_enabled = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  ALT_TAB_PROC_REC

  if (record->event.pressed) {
    switch(keycode) {
      SHIFTED_CASE(ARROW, LGARW)
      CASE(STCMT) CASE(ENCMT)
      CASE(SEL_W) CASE(DEL_W)
      CASE(SSHOT)
    }
  }
  return true;
}

// TODO Maybe switch to: https://beta.docs.qmk.fm/using-qmk/hardware-features/lighting/feature_rgblight#defining-lighting-layers-id-defining-lighting-layers
void led_set_user(uint8_t usb_led) {
  uint8_t mode =
    (layer_state & (1<<_NAV)) ? 1 : // Nav
    (layer_state & (1<<_SYMBL)) ? 2 : // Symb
    (usb_led & (1 << USB_LED_CAPS_LOCK) || caps_word_enabled) ? 3 : // Caps
    (default_layer_state & (1 << _GRAV)) ? 4 : // Grav
    (default_layer_state & (1 << _PLAIN)) ? 5 : // Plain
    (layer_state & (1 << _CODE)) ? 6 : // Code
    0;  // Off

  uint8_t hue_pallets[][6] = {
  // These are byte hues, so <hue degrees>*255/360
  //    0    1    2    3    4    5       LED layout:   5 4 3   (bottom row keys)   0 1 2
    {   0,   0,   0,   0,   0,   0 }, // Off
    { 150,  25, 150, 150,  25, 150 }, // Nav
    { 135, 215,  85, 135, 215,  85 }, // Symb
    { 200,   0,   0, 200,   0,   0 }, // Caps
    {   0,   0,   0,   0, 170,   0 }, // Grav
    {   0,   0,   0, 170,   0,   0 }, // Plain
    { 215, 150,  25,  25, 150, 215 }, // Code
  };

  if ( mode ) { rgblight_enable_noeeprom(); rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT); } else { rgblight_disable_noeeprom(); return; }
  for (int i = 0; i < 6; i++){
    if(hue_pallets[mode][i]) {
      sethsv(hue_pallets[mode][i], 190, 190, (LED_TYPE *)&led[i]);
    } else {
      sethsv(HSV_OFF, (LED_TYPE *)&led[i]);
    }
  }

  if ( mode ) { rgblight_set(); }

  return;
}

void matrix_scan_user(void) {
  ALT_TAB_MATRIX_SCAN
}

void caps_word_set_user(bool active) {
    caps_word_enabled = active;
    led_set_user(host_keyboard_leds());
}
