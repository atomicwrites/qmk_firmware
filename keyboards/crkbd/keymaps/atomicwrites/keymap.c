#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

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

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 4
#define _CHORD 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  BACKLIT,
  RGBRST
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
     KC_TAB,  KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,                   KC_Y,  KC_U,  KC_I,  KC_O,  KC_P,KC_BSPC,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
    KC_LCTL,  KC_A,  KC_S,  KC_D,  KC_F,  KC_G,                   KC_H,  KC_J,  KC_K,  KC_L,KC_SCLN,KC_QUOT,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
    KC_LSFT,  KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,                   KC_N,  KC_M,KC_COMM,KC_DOT,KC_SLSH,KC_RSFT,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                KC_LGUI, LOWER,KC_BSPC,   KC_ENT, RAISE,KC_RALT \
                              //`--------------------'  `--------------------'
  ),


  [_CHORD] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
     KC_ESC,  KC_1,  KC_2,  KC_3,  KC_4,  KC_5,                   KC_6,  KC_7,  KC_8,  KC_9,  KC_0,KC_BSLS,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
     KC_LCTL,  KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,                   KC_Y,  KC_U,  KC_I,  KC_O,  KC_P,KC_QUOT,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
    KC_LGUI,  KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,                 KC_N,  KC_M,KC_COMM,KC_DOT,KC_SLSH,KC_RSFT,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                               LOWER,KC_LSFT, KC_BSPC,   KC_DEL, RAISE,KC_RALT \
                              //`--------------------'  `--------------------'
  ),

  [_LOWER] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
    KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
     KC_ESC,  KC_1,  KC_2,  KC_3,  KC_4,  KC_5,                   KC_6,  KC_7,  KC_8,  KC_9,  KC_0,KC_BSPC,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
    KC_LCTL, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                KC_LEFT,KC_DOWN,KC_UP, KC_RIGHT,KC_NO,KC_NO,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                KC_LGUI, LOWER,KC_SPC,   KC_ENT, RAISE,KC_RALT \
                              //`--------------------'  `--------------------'
  ),

  [_RAISE] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
     KC_ESC,KC_EXLM,KC_AT,KC_HASH,KC_DLR,KC_PERC,              KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_BSPC,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
    KC_LCTL, KC_NO, KC_NO, KC_NO,KC_WH_U, KC_NO,               KC_MINS,KC_EQL,KC_LCBR,KC_RCBR,KC_PIPE,KC_GRV,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
    KC_LSFT, KC_NO, KC_NO, KC_NO,KC_WH_D, KC_NO,               KC_UNDS,KC_PLUS,KC_LBRC,KC_RBRC,KC_BSLS,KC_TILD,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                KC_LGUI, LOWER,KC_SPC,   KC_ENT, RAISE,KC_RALT \
                              //`--------------------'  `--------------------'
  ),

  [_ADJUST] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
      RESET,RGBRST, KC_NO, KC_NO, KC_NO, KC_NO,                  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
    RGB_TOG,RGB_HUI,RGB_SAI,RGB_VAI,KC_NO,KC_NO,                 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
    RGB_MOD,RGB_HUD,RGB_SAD,RGB_VAD,KC_NO,KC_NO,                 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                KC_LGUI, LOWER,KC_SPC,   KC_ENT, RAISE,KC_RALT \
                              //`--------------------'  `--------------------'
  )
};

int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    //matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case ADJUST:
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
        return false;
    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      return false;
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      break;
  }
  return true;
}
