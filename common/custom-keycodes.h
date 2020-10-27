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

#endif
