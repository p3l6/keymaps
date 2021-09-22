#ifndef USERSPACE
#define USERSPACE

#define _______ KC_TRNS // a key transparent to the layer below
#define XXXXXXX KC_NO   // a key phisically missing
#define __xxx__ KC_NO   // a key masked for this layer

#define D_TAB_L LGUI(LSFT(KC_LBRC))
#define D_TAB_R LGUI(LSFT(KC_RBRC))
#define D_SPC_L LCTL(KC_LEFT)
#define D_SPC_R LCTL(KC_RGHT)
#define D_EXPOS LCTL(KC_UP)
#define D_NOTIF LCTL(KC_F10)
#define D_HIDE  LGUI(KC_H)
#define D_DBG_C KC_F16
#define D_DBG_N KC_F17
#define D_DBG_S KC_F18
#define D_DBG_O KC_F19

enum custom_keycodes {
    Z_NSSTR = SAFE_RANGE,
    Z_NSLOG,
    Z_ATQOT,
    Z_PRINT,
    Z_ARROW,
    Z_LGARW,
    Z_STCMT,
    Z_ENCMT,
    Z_SFRMT,
    Z_PARAM,
    Z_JSSTR,
    Z_ALTTB,
};

#define DEF_NSSTR SEND_STRING("NSString*");
#define DEF_NSLOG SEND_STRING("NSLog(@\"\");"SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT));
#define DEF_ATQOT SEND_STRING("\"%@\",");
#define DEF_PRINT SEND_STRING("print(\"\")"SS_TAP(X_LEFT)SS_TAP(X_LEFT));
#define DEF_ARROW SEND_STRING("->");
#define DEF_LGARW SEND_STRING("=>");
#define DEF_STCMT SEND_STRING("/*");
#define DEF_ENCMT SEND_STRING("*/");
#define DEF_SFRMT SEND_STRING("\\()"SS_TAP(X_LEFT));
#define DEF_PARAM SEND_STRING(":()"SS_TAP(X_LEFT));
#define DEF_JSSTR SEND_STRING("``"SS_TAP(X_LEFT)"${}"SS_TAP(X_LEFT));

#define CASE(macro) case Z_##macro: DEF_##macro return false; break;

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
