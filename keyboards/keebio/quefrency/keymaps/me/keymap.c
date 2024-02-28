#include QMK_KEYBOARD_H

#include "custom-keycodes.h"

#define BASE 0
#define FLIP 1
#define CODE 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [BASE] = LAYOUT_65_with_macro_left_only(
MO(CODE),KC_GRV,     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,
KC_F1,   KC_F2,      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,
KC_F3,   KC_F4,      KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
KC_UP,   KC_DOWN,    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,
KC_LEFT, KC_RGHT,    KC_LCTL, KC_LALT, KC_LGUI,    KC_SPC,        MO(FLIP)

), [FLIP] = LAYOUT_65_with_macro_left_only(

_______, _______,    _______, KC_EQL,  KC_MINS, KC_0,    KC_9,    KC_8,    KC_7,
_______, _______,    KC_BSPC, KC_P,    KC_O,    KC_I,    KC_U,    KC_Y,
_______, _______,    KC_ENT,  KC_QUOT, KC_L,    KC_K,    KC_J,    KC_H,
_______, _______,    _______, KC_SLSH, KC_DOT,  KC_COMM, KC_M,    KC_N,
_______, _______,    _______, _______, _______,    _______,        _______

), [CODE] = LAYOUT_65_with_macro_left_only(

_______, _______,    _______, _______, _______, _______, _______, _______, _______,
_______, _______,    _______, _______, _______, _______, _______, _______,
_______, _______,    _______, _______, _______, _______, _______, _______,
KC_VOLU, KC_VOLD,    _______, _______, _______, _______, _______, _______,
D_SPC_L, D_SPC_R,    _______, _______, _______,      _______,     _______

)
};

