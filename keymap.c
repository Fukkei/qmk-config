#include QMK_KEYBOARD_H
#include "keycodes.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DEF] = LAYOUT_split_3x5_2(
                            KC_Q, KC_W, KC_E, KC_R, KC_T,    KC_P, KC_O, KC_I, KC_U, KC_Y,
                            KC_A, KC_S, KC_D, KC_F, KC_G,    KC_SCLN, KC_L, KC_K, KC_J, KC_H,
                            KC_Z, KC_X, KC_C, KC_V, KC_B,    KC_SLSH, KC_DOT, KC_COMM, KC_M, KC_N,
                                                NUM, NAV,    KC_SPC, SYM
                               ),

    [_NUM] = LAYOUT_split_3x5_2(
              KC_EXLM, KC_AT,   KC_HASH, KC_DLR, KC_PERC,    KC_5, KC_4, KC_3, KC_2, KC_1,
              KC_LCTL, KC_LGUI, KC_LALT, KC_LSFT, KC_ENT,    KC_0,  KC_9, KC_8, KC_7, KC_6,
                 KC_NO,  KC_ASTR, M_XCOP, M_XPST, KC_SPC,    KC_SLSH, KC_DOT, KC_COMM, KC_AMPR, KC_CIRC,
                                        KC_TRNS, KC_TRNS,    KC_TRNS, FUN
                                ),

    [_SYM] = LAYOUT_split_3x5_2(
            M_TSKM,   KC_PLUS, KC_LCBR, KC_RCBR, MACRO_0,    KC_UP, KC_MUTE, KC_VOLD, KC_VOLU, M_FIND,
             KC_LT,   KC_UNDS, KC_LPRN, KC_RPRN,  KC_GRV,    KC_LCTL, KC_LGUI, KC_LALT,  KC_LSFT,  KC_COLN,
            KC_GT,   KC_PAUS, KC_LBRC, KC_RBRC,  KC_DQUO,    KC_DOWN, MACRO_2, KC_ENTER, KC_RGHT, KC_LEFT,
                                             FUN, KC_ENT,    KC_TRNS, KC_TRNS
                                ),

    [_NAV] = LAYOUT_split_3x5_2(
                KC_ESC,  KC_TAB, KC_DEL, KC_BSPC, CAPSWRD,    KC_EQL, KC_END, KC_UP,   KC_HOME,  KC_PGUP,
               KC_LCTL, KC_LGUI, KC_LALT, KC_LSFT, M_LANG,    KC_MINS, KC_RGHT, KC_DOWN, KC_LEFT, KC_PGDN,
                 M_UNDO,  M_CUT,   M_COPY, M_PSTE, M_SAVE,    KC_BSLS, MACRO_1, KC_TILD, KC_PIPE, KC_QUOT,
                                         KC_TRNS, KC_TRNS,    KC_TRNS, KC_ENT
                               ),

    [_FUN] = LAYOUT_split_3x5_2(
            			KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    KC_F5,  KC_F4, KC_F3, KC_F2, KC_F1,
            	KC_LCTL, KC_LGUI, KC_LALT, KC_LSFT, KC_NO,    KC_F10,  KC_F9, KC_F8, KC_F7, KC_F6,
            			KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    KC_NO,  KC_NO, KC_NO, KC_F12, KC_F11,
                                    	KC_TRNS,  KC_TRNS,    KC_TRNS, KC_TRNS
                                )
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
