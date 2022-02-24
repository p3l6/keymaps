#ifndef USERSPACE
#define USERSPACE

#define _______ KC_TRNS // a key transparent to the layer below
#define XXXXXXX KC_NO   // a key phisically missing
#define __xxx__ KC_NO   // a key masked for this layer

#define D_TAB_L LGUI(LSFT(KC_LBRC))
#define D_TAB_R LGUI(LSFT(KC_RBRC))
#define D_SPC_L LCTL(KC_LEFT)
#define D_SPC_R LCTL(KC_RGHT)
#define D_SPC_1 LCTL(KC_1)
#define D_SPC_2 LCTL(KC_2)
#define D_SPC_3 LCTL(KC_3)
#define D_SPC_4 LCTL(KC_4)
#define D_EXPOS LCTL(KC_UP)
#define D_NOTIF LCTL(KC_F10)
#define D_HIDE  LGUI(KC_H)
#define D_DBG_C KC_F16
#define D_DBG_N KC_F17
#define D_DBG_S KC_F18
#define D_DBG_O KC_F19
#define D_BRT_D KC_SLCK
#define D_BRT_U KC_PAUS
#define D_LIN_U LALT(LSFT(KC_UP))
#define D_LIN_D LALT(LSFT(KC_DOWN))
#define D_CUR_U LALT(KC_UP)
#define D_CUR_D LALT(KC_DOWN)
#define D_COPY  LGUI(KC_C)
#define D_PASTE LGUI(KC_V)
#define D_SLACK LALT(LCTL(KC_F1)) // alfred action to launch slack and send correct keycommand
#define D_ZOOM  LALT(LCTL(KC_F2)) // alfred action to launch zoom and send correct keycommand
#define D_SUBWD LCTL(KC_LALT)

enum custom_keycodes {
    Z_PRINT = SAFE_RANGE,
    Z_ARROW,
    Z_LGARW,
    Z_STCMT,
    Z_ENCMT,
    Z_SFRMT,
    Z_JSSTR,
    Z_ALTTB,
    Z_MTODO,
};

#define DEF_PRINT SEND_STRING("print(\"\")"SS_TAP(X_LEFT)SS_TAP(X_LEFT));
#define DEF_ARROW SEND_STRING("->");
#define DEF_LGARW SEND_STRING("=>");
#define DEF_STCMT SEND_STRING("/*");
#define DEF_ENCMT SEND_STRING("*/");
#define DEF_SFRMT SEND_STRING("\\()"SS_TAP(X_LEFT));
#define DEF_JSSTR SEND_STRING("``"SS_TAP(X_LEFT)"${}"SS_TAP(X_LEFT));
#define DEF_MTODO SEND_STRING("- [ ] ");

#define CASE(macro) case Z_##macro: DEF_##macro return false; break;
#define SHIFTED_CASE(macro, shifted_macro) case Z_##macro: ; const uint8_t mods = get_mods(); \
  if (mods & MOD_MASK_SHIFT) { del_mods(MOD_MASK_SHIFT);  DEF_##shifted_macro set_mods(mods); } \
  else { DEF_##macro } return false; break;

#define ALT_TAB_DELAY 750  // 0.75 s
#define ALT_TAB_INIT uint16_t altTabTimer = 0;
#define ALT_TAB_PROC_REC if (keycode == Z_ALTTB) { \
  if (record->event.pressed) { \
    if (altTabTimer == 0) register_code(KC_RGUI); \
    register_code(KC_TAB); \
  } else { \
    altTabTimer = timer_read(); \
    unregister_code(KC_TAB); \
  } return false; }

#define ALT_TAB_MATRIX_SCAN if \
  (altTabTimer && timer_elapsed(altTabTimer) >= ALT_TAB_DELAY) { \
    unregister_code(KC_RGUI); \
    altTabTimer = 0; \
  }

#endif

// Tap dance keycodes
#define TAP_DANCE_INIT qk_tap_dance_action_t tap_dance_actions[] = { \
  [0] = ACTION_TAP_DANCE_DOUBLE(KC_MPLY, KC_MFFD), \
  };

#define T_PLNXT TD(0)
