/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

// #include "keymap_norwegian.h"

#define _BAS 0
#define _SYM 1
#define _NUM 2
#define _NAV 3

// home row mods for gui and alt
#define GUI_A MT(MOD_LGUI, KC_A)
#define ALT_S MT(MOD_LALT, KC_S)
#define ALT_L MT(MOD_RALT, KC_L)
#define GUI_SCN MT(MOD_RGUI, KC_SCLN)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BAS] = LAYOUT_split_3x6_3(
      XXXXXXX,    KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,                         KC_Y,     KC_U,    KC_I,    KC_O,    KC_P, XXXXXXX,
      XXXXXXX,   GUI_A,   ALT_S,    KC_D,    KC_F,     KC_G,                         KC_H,     KC_J,    KC_K,   ALT_L, GUI_SCN, XXXXXXX,
      XXXXXXX,    KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,                         KC_N,     KC_M, KC_COMM,  KC_DOT, KC_SLSH, XXXXXXX,
                                          KC_LSFT, MO(_SYM), KC_SPC,     KC_RCTL, MO(_NUM), KC_RSFT

  ),

    [_SYM] = LAYOUT_split_3x6_3(
      XXXXXXX, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR,  KC_PERC,                         KC_BSLS,  XXXXXXX, KC_QUOT,  KC_GRV, KC_MINS, XXXXXXX,
      XXXXXXX, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN,  KC_RPRN,                          KC_EQL,  KC_LEFT, KC_DOWN,  KC_UP, KC_RIGHT, XXXXXXX,
      XXXXXXX, KC_TILD, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,                         XXXXXXX,    KC_LT, KC_LCBR, KC_RCBR,   KC_GT, XXXXXXX,
                                          KC_LSFT, TO(_BAS), KC_SPC,        KC_RCTL, TG(_NUM), KC_RSFT
  ),

    [_NUM] = LAYOUT_split_3x6_3(
      XXXXXXX,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                          KC_PSLS,     KC_7,    KC_8,    KC_9, KC_MINS, XXXXXXX,
      XXXXXXX,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                          KC_PAST,     KC_4,    KC_5,    KC_6, KC_PPLS, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                          KC_COMM,     KC_1,    KC_2,    KC_3,  KC_DOT, XXXXXXX,
                                          KC_LSFT, TO(_BAS), KC_SPC,       KC_0, TG(_SYM),  KC_RSFT
  )

  //   [_NAV] = LAYOUT_split_3x6_3(
  //     QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //     RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //     RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //                                         KC_LGUI, TO(_BAS),  KC_SPC,     KC_ENT, TG(_SYM), KC_RALT
  // )
};
// clang-format on

const uint16_t PROGMEM backspace_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM enter_combo[]     = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM escape_combo[]    = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM tab_combo[]       = {KC_D, KC_F, COMBO_END};
combo_t                key_combos[]      = {
    COMBO(escape_combo, KC_ESC),
    COMBO(backspace_combo, KC_BACKSPACE),
    COMBO(enter_combo, KC_ENTER),
    COMBO(tab_combo, KC_TAB),
};
