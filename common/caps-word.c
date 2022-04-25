// Copyright 2021 Google LLC.
// SPDX-License-Identifier: Apache-2.0
// https://getreuer.info/posts/keyboards/caps-word/index.html

#include "caps-word.h"

bool caps_word_enabled = false;

bool process_caps_word(uint16_t keycode, keyrecord_t* record) {
  static bool shifted = false;

  if (!caps_word_enabled) {
    // Pressing both shift keys at the same time enables caps word.
    if (((get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT)
        == MOD_MASK_SHIFT) {
      clear_mods();
      clear_oneshot_mods();
      shifted = false;
      caps_word_enabled = true;
      led_set_user(host_keyboard_leds());
      return false;
    }
    return true;
  }

  if (!record->event.pressed) { return true; }

  if (!((get_mods() | get_oneshot_mods()) & ~MOD_MASK_SHIFT)) {
    switch (keycode) {
      case QK_MOD_TAP ... QK_MOD_TAP_MAX:
      case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
        // Earlier return if this has not been considered tapped yet.
        if (record->tap.count == 0) { return true; }
        // Get the base tapping keycode of a mod- or layer-tap key.
        keycode &= 0xff;
    }

    switch (keycode) {
      // Letter keys should be shifted.
      case KC_A ... KC_Z:
#ifndef HAS_DEDICATED_UNDERSCORE_KEY
      case KC_MINS:
#endif
        if (!shifted) { register_code(KC_LSFT); }
        shifted = true;
        return true;

      // Keycodes that continue caps word but shouldn't get shifted.
      case KC_1 ... KC_0:
      case KC_BSPC:
#ifdef HAS_DEDICATED_UNDERSCORE_KEY
      case KC_MINS:
#endif
      case KC_UNDS:
        if (shifted) { unregister_code(KC_LSFT); }
        shifted = false;
        return true;

      // Any other keycode disables caps word.
    }
  }

  // Disable caps word.
  caps_word_enabled = false;
  led_set_user(host_keyboard_leds());
  if (shifted) { unregister_code(KC_LSFT); }
  shifted = false;
  return true;
}
