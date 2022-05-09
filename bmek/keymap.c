#include QMK_KEYBOARD_H
#include "custom-keycodes.h"
#include "caps-word.h"

#define _BASE 0
#define _GRAV 1 // a secondary base layer that changes underscore -> grave accent
#define _PLAIN 2 // a secondary base layer that hides all special functions
#define _NAV 3
#define _SYMBL 4

#define LT_SYMB  LT(_SYMBL, KC_ENT)
#define LT_MEDIA LT(_MEDIA, KC_GRV)

#define BASE_B DF(_BASE)
#define BASE_G DF(_GRAV)
#define BASE_P DF(_PLAIN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT_hhkb(

Z_ALTTB, KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,            KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_DEL,
T_PLNXT, KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
D_SLACK, LT_SYMB, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
D_ZOOM,  KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,            KC_UNDS, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSPC, KC_LEAD,
                  KC_LALT, KC_LGUI,          MO(_NAV),                 KC_SPC,           KC_RGUI, KC_RCTL

),[_GRAV] = LAYOUT_hhkb(

_______, _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______,
_______, _______, _______, _______, _______, _______, _______,                  _______, _______, _______, _______, _______, _______, _______, _______,
_______, _______, _______, _______, _______, _______, _______,                  _______, _______, _______, _______, _______, _______, _______,
_______, _______, _______, _______, _______, _______, _______,     LALT(KC_GRV), _______, _______, _______, _______, _______,          _______, _______,
                  _______, _______,          _______,                  _______,          _______, _______

),[_PLAIN] = LAYOUT_hhkb(

__xxx__, KC_ESC,  _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______,
__xxx__, _______, _______, _______, _______, _______, _______,                  _______, _______, _______, _______, _______, _______, _______, _______,
__xxx__, __xxx__, _______, _______, _______, _______, _______,                  _______, _______, _______, _______, _______, _______, _______,
__xxx__, KC_LSFT, _______, _______, _______, _______, _______,          KC_DOT, _______, _______, _______, _______, _______,          KC_RSFT, DF(_BASE),
                  _______, _______,          KC_SPC,                  _______,          _______, _______

),[_NAV] = LAYOUT_hhkb(

RESET,   KC_ESC,  D_SPC_1, D_SPC_2, D_SPC_3, D_SPC_4, __xxx__, __xxx__,         __xxx__, __xxx__, __xxx__, __xxx__, __xxx__, __xxx__, __xxx__, _______,
__xxx__, KC_DEL,  D_SUBWD, Z_ALTTB, KC_UP,   D_EXPOS, D_SPC_L,                  D_SPC_R, __xxx__, KC_UP,   __xxx__, KC_PGUP, KC_HOME, __xxx__, _______,
__xxx__, KC_BSPC, KC_LALT, KC_LEFT, KC_DOWN, KC_RGHT, D_TAB_L,                  D_TAB_R, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_END,           KC_PENT,
__xxx__, KC_LSFT, KC_LGUI, D_ALF_X, D_ALF_C, D_ALF_V, _______,         _______, D_GRP_D, D_GRP_U, D_GRP_L, D_GRP_R, __xxx__,          KC_RSFT, __xxx__,
                  _______, _______,          _______,                  _______,          _______, _______

),[_SYMBL] = LAYOUT_hhkb(

__xxx__, KC_ESC,  D_DBG_C, D_DBG_N, D_DBG_S, D_DBG_O, KC_VOLD, KC_VOLU,         __xxx__, __xxx__, __xxx__, __xxx__, __xxx__, __xxx__, __xxx__, _______,
BASE_P,  _______, __xxx__, __xxx__, D_LIN_U, D_CUR_U, D_SWAP,                   KC_PIPE, KC_EXLM, KC_MINS, KC_PLUS, __xxx__, Z_STCMT, Z_ENCMT, _______,
BASE_G,  _______, __xxx__, __xxx__, D_LIN_D, D_CUR_D, D_CUR_A,                  KC_HASH, KC_LCBR, KC_EQL,  KC_RCBR, KC_ASTR, KC_GRV,           KC_PENT,
BASE_B,  KC_LSFT, __xxx__, D_LIN_X, D_LIN_N, D_CUR_N, __xxx__,         __xxx__, KC_AMPR, KC_DLR,  KC_TILD, Z_ARROW, KC_BSLS,          _______, __xxx__,
                  __xxx__, __xxx__,          KC_SPC,                   _______,          __xxx__, __xxx__

),
};

ALT_TAB_INIT
TAP_DANCE_INIT
LEADER_EXTERNS();
extern bool caps_word_enabled;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_caps_word(keycode, record)) { return false; }
  ALT_TAB_PROC_REC

  if (record->event.pressed) {
    switch(keycode) {
      SHIFTED_CASE(ARROW, LGARW)
      CASE(STCMT) CASE(ENCMT)
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
    (leading) ? 6 : // Leader Key
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
    {   5,  40,  85,   0,   0,   0 }, // Leader Key
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
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    // https://docs.qmk.fm/#/feature_leader_key
    // Follows macro docs: https://docs.qmk.fm/#/feature_macros

    SEQ(KC_QUOT){ SEND_STRING("`"); }
    SEQ(KC_QUOT, KC_QUOT){ SEND_STRING("``" SS_TAP(X_LEFT)); }
    SEQ(KC_QUOT, KC_QUOT, KC_QUOT){ SEND_STRING("```"); }
    SEQ(KC_QUOT, KC_QUOT, KC_QUOT, KC_QUOT){ SEND_STRING("```\n\n```" SS_TAP(X_UP)); }
    SEQ(KC_T, KC_O, KC_D, KC_O){ SEND_STRING("- [ ] "); }
    SEQ(KC_RSPC){ tap_code(KC_CAPS); }

    SEQ(KC_BSPC){ tap_code16(A(KC_BSPC)); }
    SEQ(KC_DEL){ tap_code16(A(KC_DEL)); }
    SEQ(KC_DEL, KC_DEL) { tap_code16(A(KC_RIGHT)); tap_code16(A(KC_BSPC)); }
    SEQ(KC_BSPC, KC_BSPC) { tap_code16(A(KC_LEFT)); tap_code16(A(KC_DEL)); }
    SEQ(KC_W){ tap_code16(A(KC_LEFT)); tap_code16(A(S(KC_RIGHT))); }

    SEQ(KC_S, KC_S){ tap_code16(G(S(KC_4))); }
    SEQ(KC_S, KC_S, KC_S){ tap_code16(G(S(KC_5))); }

    SEQ(KC_F, KC_1){ tap_code(KC_F1); }
    SEQ(KC_F, KC_2){ tap_code(KC_F2); }
    SEQ(KC_F, KC_3){ tap_code(KC_F3); }
    SEQ(KC_F, KC_4){ tap_code(KC_F4); }
    SEQ(KC_F, KC_5){ tap_code(KC_F5); }
    SEQ(KC_F, KC_6){ tap_code(KC_F6); }
    SEQ(KC_F, KC_7){ tap_code(KC_F7); }
    SEQ(KC_F, KC_8){ tap_code(KC_F8); }
    SEQ(KC_F, KC_9){ tap_code(KC_F9); }

    SEQ(KC_F, KC_S, KC_T){ SEND_STRING("`${}`"SS_TAP(X_LEFT)SS_TAP(X_LEFT)); }
    SEQ(KC_F, KC_S, KC_P){ SEND_STRING("f\"{}\""SS_TAP(X_LEFT)SS_TAP(X_LEFT)); }
    SEQ(KC_F, KC_S, KC_S){ SEND_STRING("\"\\()\""SS_TAP(X_LEFT)SS_TAP(X_LEFT)); }
  }
}

void leader_start(void) {
  // Normally, 'leading' is set right after this call
  //   qmk_firmware/quantum/process_keycode/process_leader.c:41
  leading = true;
  led_set_user(host_keyboard_leds());
}

void leader_end(void) {
  led_set_user(host_keyboard_leds());
}
