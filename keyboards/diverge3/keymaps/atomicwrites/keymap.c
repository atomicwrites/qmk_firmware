/* Copyright 2017 IslandMan93
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum combos {
  QZ_A,
  WX_S,
  EC_D,
  RV_F,
  TB_G,
  YN_H,
  UM_J,
  ICOMMA_K,
  ODOT_L,
  PSLASH_SCOLON,
  MCOMMA_SPC,
  CV_SPC,
  ER_TAB,
  UI_ENT,
};

const uint16_t PROGMEM qz_combo[] = {KC_Q, KC_Z, COMBO_END};
const uint16_t PROGMEM wx_combo[] = {KC_W, KC_X, COMBO_END};
const uint16_t PROGMEM ec_combo[] = {KC_E, KC_C, COMBO_END};
const uint16_t PROGMEM rv_combo[] = {KC_R, KC_V, COMBO_END};
const uint16_t PROGMEM tb_combo[] = {KC_T, KC_B, COMBO_END};
const uint16_t PROGMEM yn_combo[] = {KC_Y, KC_N, COMBO_END};
const uint16_t PROGMEM um_combo[] = {KC_U, KC_M, COMBO_END};
const uint16_t PROGMEM icomma_combo[] = {KC_I, KC_COMMA, COMBO_END};
const uint16_t PROGMEM odot_combo[] = {KC_O, KC_DOT, COMBO_END};
const uint16_t PROGMEM pslash_combo[] = {KC_P, KC_SLASH, COMBO_END};
const uint16_t PROGMEM mcomma_combo[] = {KC_M, KC_COMMA, COMBO_END};
const uint16_t PROGMEM cv_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM er_combo[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM ui_combo[] = {KC_U, KC_I, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [QZ_A] = COMBO(qz_combo, KC_A),
  [WX_S] = COMBO(wx_combo, KC_S),
  [EC_D] = COMBO(ec_combo, KC_D),
  [RV_F] = COMBO(rv_combo, KC_F),
  [TB_G] = COMBO(tb_combo, KC_G),
  [YN_H] = COMBO(yn_combo, KC_H),
  [UM_J] = COMBO(um_combo, KC_J),
  [ICOMMA_K] = COMBO(icomma_combo, KC_K),
  [ODOT_L] = COMBO(odot_combo, KC_L),
  [PSLASH_SCOLON] = COMBO(pslash_combo, KC_SCOLON),
  [MCOMMA_SPC] = COMBO(mcomma_combo, KC_SPC),
  [CV_SPC] = COMBO(cv_combo, KC_SPC),
  [ER_TAB] = COMBO(er_combo, KC_TAB),
  [UI_ENT] = COMBO(ui_combo, KC_ENT),
};

// Holds for layer
#define KC_SPC2 LT(2, KC_SPC)

// Jumps the cursor a word right or left
#define KC_WRDRT LCTL(KC_RIGHT)
#define KC_WRDLT LCTL(KC_LEFT)
#define __x__ KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[1] = LAYOUT(
        TG(1), KC_GRV , KC_1  , KC_2   , KC_3  , KC_4   , KC_5   ,                  KC_6   , KC_7    , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL ,
        KC_LBRC, KC_TAB , KC_Q   , KC_W  , KC_E   , KC_R  , KC_T   ,                  KC_Y    , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSLS, KC_RBRC, 
        KC_MUTE, KC_ESC , KC_A   , KC_S  , KC_D   , KC_F  , KC_G   ,                  KC_H    , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT, KC_MPLY, 
        KC_PGUP, KC_LSFT, KC_Z   , KC_X  , KC_C   , KC_V  , KC_B   ,                  KC_N    , KC_M   , KC_COMM, KC_DOT , KC_UP  , KC_SLSH, KC_PGDN, 
        KC_LSFT, KC_HOME, KC_LGUI, KC_APP, KC_LALT, KC_SPC, KC_LCTL, KC_BSPC, KC_DEL, KC_END , KC_SPC2 , KC_ENT , KC_DOWN, KC_LEFT, KC_DOWN, KC_RGHT
        ) ,

	[0] = LAYOUT(
        TG(1)  , KC_GRV , __x__  , __x__   , __x__  , __x__  , __x__  ,                   __x__    , __x__  , __x__   , __x__   , __x__   , KC_MINS, KC_EQL ,
        KC_LBRC, KC_TAB , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                   KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSLS, KC_RBRC, 
        KC_MUTE, KC_ESC , KC_Q   , KC_W  , KC_E  , KC_R  , KC_T  ,                   KC_Y    , KC_U  , KC_I   , KC_O   , KC_P   , KC_QUOT, KC_MPLY, 
        KC_PGUP, KC_LSFT, KC_Z   , KC_X  , KC_C  , KC_V  , KC_B  ,                   KC_N    , KC_M  , KC_COMM, KC_DOT , KC_SLSH, KC_UP  , KC_PGDN, 
        KC_HOME, KC_LGUI, KC_APP, KC_LALT, KC_SPC, KC_LCTL, KC_LSFT, KC_BSPC, KC_DEL, KC_END , MO(2), KC_ENT, KC_DOWN, KC_LEFT, KC_DOWN, KC_RGHT
        ) ,

	[2] = LAYOUT(
        TG(1)   , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,                   KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , RESET  ,
        _______ , _______, _______, KC_UP  , _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
        _______ , _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                   KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, _______,
        _______ , KC_MPRV, KC_MPLY, KC_MSTP, KC_MNXT, KC_VOLD, _______,                   _______, KC_DOWN, KC_UP, KC_RGHT, KC_LEFT, _______, _______,
        _______ , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
        )
};

/*const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {*/

  /*[_QWERTY] = LAYOUT(*/
    /*KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MUTE,                   KC_MPLY,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PSCR,*/
    /*KC_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_VOLD,                   KC_VOLU,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_CAPS,*/
    /*KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_PGDN,                   KC_PGUP,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_BSLS,*/
    /*KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_WRDLT,                  KC_WRDRT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT,*/
    /*KC_LCTL, KC_LGUI, KC_APP,  KC_LALT, KC_HOME, KC_SPNT, KC_DEL1,  KC_BSHT, KC_ENT, KC_TAB1,  KC_BSHT, KC_END,  KC_DOWN, KC_UP,   KC_LEFT, KC_RIGHT*/
  /*),*/

  /*[_LOWER] = LAYOUT(*/
    /*_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,                    KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   _______, _______,*/
    /*KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______,                   _______, KC_CIRC, KC_AMPR, KC_ASTR, _______, _______, _______,*/
    /*_______, _______, KC_LBRC, KC_LPRN, KC_UNDS, KC_LCBR, _______,                   _______, KC_RCBR, KC_EQL,  KC_RPRN, KC_RBRC, KC_COLN, _______,*/
    /*_______, _______, _______, KC_PMAC, KC_MINS, KC_AMAC, _______,                   _______, _______, KC_PLUS, _______, _______, _______, _______,*/
    /*_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______*/
  /*)*/

/*};*/
