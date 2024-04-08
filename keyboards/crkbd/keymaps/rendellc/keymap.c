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

#include "keymap_norwegian.h"

#define _BAS 0
#define _SYM 1
#define _NUM 2
#define _SPE 3

// home row mods for gui and alt
#define GUI_A MT(MOD_LGUI, NO_A)
#define ALT_S MT(MOD_LALT, NO_S)
#define ALT_L MT(MOD_RALT, NO_L)
#define GUI_SCN MT(MOD_RGUI, NO_SCLN)
#define NO_AA NO_ARNG // Å
#define NO_OE NO_OSTR // Ø
// #define NO_AE NO_AE   // Æ
#define SCLN_OE MT(NO_OE, NO_SCLN)
// #define AA_A MT(NO_AA, NO_A)
// #define OE_O MT(NO_OE, NO_O)
// #define AE_E MT(NO_AE, NO_E)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BAS] = LAYOUT_split_3x6_3(
      XXXXXXX,    NO_Q,    NO_W,    NO_E,    NO_R,     NO_T,                         NO_Y,     NO_U,    NO_I,    NO_O,    NO_P, XXXXXXX,
      XXXXXXX,    NO_A,   ALT_S,    NO_D,    NO_F,     NO_G,                         NO_H,     NO_J,    NO_K,   ALT_L, GUI_SCN, XXXXXXX,
      XXXXXXX,    NO_Z,    NO_X,    NO_C,    NO_V,     NO_B,                         NO_N,     NO_M, NO_COMM,  NO_DOT, NO_SLSH, XXXXXXX,
                                          KC_LSFT, MO(_SYM), KC_SPC,     KC_RCTL, MO(_NUM), KC_RSFT
  ),

    [_SYM] = LAYOUT_split_3x6_3(
      XXXXXXX, NO_EXLM,   NO_AT, NO_HASH,  NO_DLR,  NO_PERC,                         NO_BSLS,   NO_EQL, NO_QUOT,   NO_GRV, NO_MINS, XXXXXXX,
      XXXXXXX, NO_CIRC, NO_AMPR, NO_ASTR, NO_LPRN,  NO_RPRN,                         KC_LEFT,  KC_DOWN,   KC_UP, KC_RIGHT, XXXXXXX, XXXXXXX,
      XXXXXXX, NO_TILD, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,                         XXXXXXX,    KC_LT, NO_LCBR,  NO_RCBR,   KC_GT, XXXXXXX,
                                          _______, _______, _______,        _______, _______, _______
  ),

    [_NUM] = LAYOUT_split_3x6_3(
      XXXXXXX,    NO_1,    NO_2,    NO_3,    NO_4,    NO_5,                          NO_SLSH,     NO_7,    NO_8,    NO_9, NO_MINS, XXXXXXX,
      XXXXXXX,    NO_6,    NO_7,    NO_8,    NO_9,    NO_0,                          NO_ASTR,     NO_4,    NO_5,    NO_6, NO_PLUS, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                          NO_COMM,     NO_1,    NO_2,    NO_3,  NO_DOT, XXXXXXX,
                                          _______, _______, _______,        _______, _______, _______
  ),

    [_SPE] = LAYOUT_split_3x6_3(
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                          XXXXXXX,    NO_AE,   NO_OE,   NO_AA, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                          XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                          XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                          _______, _______, _______,        _______, _______, _______
  )
};
// clang-format on

const uint16_t PROGMEM backspace_combo[]      = {NO_U, NO_I, COMBO_END};
const uint16_t PROGMEM enter_combo[]          = {NO_J, NO_K, COMBO_END};
const uint16_t PROGMEM escape_combo[]         = {NO_E, NO_R, COMBO_END};
const uint16_t PROGMEM tab_combo[]            = {NO_D, NO_F, COMBO_END};
const uint16_t PROGMEM special_toggle_combo[] = {MO(_SYM), MO(_NUM), COMBO_END};
combo_t                key_combos[]           = {
    COMBO(escape_combo, KC_ESC), COMBO(backspace_combo, KC_BACKSPACE), COMBO(enter_combo, KC_ENTER), COMBO(tab_combo, KC_TAB), COMBO(special_toggle_combo, MO(_SPE)),
};
