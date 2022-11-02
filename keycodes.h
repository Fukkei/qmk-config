#pragma once

#include QMK_KEYBOARD_H
#include "quantum.h"

// Layer keys
#define NUM MO(_NUM)
#define SYM MO(_SYM)
#define FUN MO(_FUN) // Fkeys and mods only
#define NAV MO(_NAV)

// shortcuts
#define M_UNDO LCTL(KC_Z)
#define M_CUT  LCTL(KC_X)
#define M_COPY LCTL(KC_C)
#define M_PSTE LCTL(KC_V)
#define M_XCOP LCTL(KC_INSERT)
#define M_XPST S(KC_INSERT)
#define M_LANG G(KC_SPC)
#define M_SAVE LCTL(S(KC_S))
#define M_TSKM LCTL(S(KC_ESC))
#define M_FIND LCTL(S(KC_F))

enum layers {
	_DEF,
	_NUM,
	_SYM,
	_NAV,
	_FUN,
};
