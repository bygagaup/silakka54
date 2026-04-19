#pragma once

#include QMK_KEYBOARD_H
#include "quantum.h"
#include "keycodes.h"

enum { LANG_EN = 0, LANG_RU };  // Language states

bool process_record_ruen(uint16_t keycode, keyrecord_t *record);
