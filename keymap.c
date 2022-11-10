#include QMK_KEYBOARD_H
#include "keycodes.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DEF] = LAYOUT_split_3x5_2(
                            KC_Q, KC_W, KC_E, KC_R, KC_T,    KC_Y, KC_U, KC_I, KC_O, KC_P,
                            KC_A, KC_S, KC_D, KC_F, KC_G,    KC_H, KC_J, KC_K, KC_L, KC_SCLN,
                            KC_Z, KC_X, KC_C, KC_V, KC_B,    KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,
                                                NUM, NAV,    SYM, KC_SPC
                               ),

    [_NUM] = LAYOUT_split_3x5_2(
              KC_EXLM, KC_AT,   KC_HASH, KC_DLR, KC_PERC,    KC_1, KC_2, KC_3, KC_4, KC_5,
              KC_LCTL, KC_LGUI, KC_LALT, KC_LSFT, KC_ENT,    KC_6,  KC_7, KC_8, KC_9, KC_0,
                 KC_NO,  KC_ASTR, M_XCOP, M_XPST, KC_SPC,    KC_CIRC, KC_AMPR, KC_COMM, KC_DOT, KC_SLSH,
                                        KC_TRNS, KC_TRNS,    FUN, KC_TRNS
                                ),

    [_SYM] = LAYOUT_split_3x5_2(
            M_TSKM,   KC_PLUS, KC_LCBR, KC_RCBR, MACRO_0,    M_FIND, KC_VOLU, KC_VOLD, GM1, KC_UP,
             KC_LT,   KC_UNDS, KC_LPRN, KC_RPRN,  KC_GRV,    KC_COLN, KC_LSFT, KC_LALT,  KC_LGUI,  KC_LCTL,
            KC_GT,   KC_PAUS, KC_LBRC, KC_RBRC,  KC_DQUO,    KC_LEFT, KC_RGHT, KC_ENTER, MACRO_2, KC_DOWN,
                                             FUN, KC_ENT,    KC_TRNS, KC_TRNS
                                ),

    [_NAV] = LAYOUT_split_3x5_2(
                KC_ESC,  KC_TAB, KC_DEL, KC_BSPC, CAPSWRD,    KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_EQL,
               KC_LCTL, KC_LGUI, KC_LALT, KC_LSFT, M_LANG,    KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_MINS,
                 M_UNDO,  M_CUT,   M_COPY, M_PSTE, M_SAVE,    KC_QUOT, KC_PIPE, KC_TILD, MACRO_1, KC_BSLS,
                                         KC_TRNS, KC_TRNS,    KC_ENT, KC_TRNS
                               ),

    [_FUN] = LAYOUT_split_3x5_2(
            			KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    KC_F1,  KC_F2, KC_F3, KC_F4, KC_F5,
            	KC_LCTL, KC_LGUI, KC_LALT, KC_LSFT, KC_NO,    KC_F6,  KC_F7, KC_F8, KC_F9, KC_F10,
            			KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    KC_F11,  KC_F12, KC_NO, KC_NO, KC_NO,
                                    	KC_TRNS,  KC_TRNS,    KC_TRNS, KC_TRNS
                                ),

    [_GM1] = LAYOUT_split_3x5_2(
                            KC_Q, KC_W, KC_E, KC_R, KC_T,    KC_NO, KC_NO, KC_NO, GM1, KC_NO,
                            KC_A, KC_S, KC_D, KC_F, KC_G,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                            KC_Z, KC_X, KC_C, KC_V, KC_B,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                                            KC_LALT, GM2,    KC_NO, KC_NO
                               ),

    [_GM2] = LAYOUT_split_3x5_2(
                          KC_ESC, KC_U, KC_I, KC_O, KC_P,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                KC_LCTL, KC_J, KC_LALT, KC_LSFT, KC_SCLN,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                    KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                                          KC_LALT, KC_NO,    KC_NO, KC_NO
                               ),
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    
  if (record->event.pressed) {
        switch (keycode) {
            case MACRO_0:
                SEND_STRING(SS_LSFT(SS_TAP(X_F10)));
                return false;
            case MACRO_1:
                SEND_STRING(SS_TAP(X_MINS)SS_LSFT(SS_TAP(X_DOT)));
                return false;
            case MACRO_2:
                SEND_STRING(SS_TAP(X_EQL)SS_LSFT(SS_TAP(X_DOT)));
                return false;
        }
    }
    return true;
}
