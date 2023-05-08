#include "../../config.h"

#define LAYOUT_65_with_macro_left_only( \
  LA1, LA2, LA3, LA4, LA5, LA6, LA7, LA8, LA9, \
  LB1, LB2, LB3, LB4, LB5, LB6, LB7, LB8,      \
  LC1, LC2, LC3, LC4, LC5, LC6, LC7, LC8,      \
  LD1, LD2, LD3,      LD5, LD6, LD7, LD8, LD9, \
  LE1, LE2, LE3, LE4, LE5, LE6,      LE8       \
  ) \
  { \
    { LA1, LA2, LA3, LA4, LA5, LA6, LA7, LA8, LA9 }, \
    { LB1, LB2, LB3, LB4, LB5, LB6, LB7, LB8, KC_NO }, \
    { LC1, LC2, LC3, LC4, LC5, LC6, LC7, LC8, KC_NO }, \
    { LD1, LD2, LD3, KC_NO, LD5, LD6, LD7, LD8, LD9 }, \
    { LE1, LE2, LE3, LE4, LE5, LE6, KC_NO, LE8, KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO } \
  }
