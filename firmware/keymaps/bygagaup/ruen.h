#pragma once

#include QMK_KEYBOARD_H
#include "keycodes.h"

enum { LANG_EN = 0, LANG_RU };

enum { TG_DEFAULT = 0, TG_M0, TG_M1M2 };

bool pre_process_record_ruen(uint16_t keycode, keyrecord_t *record);

bool process_record_ruen(uint16_t keycode, keyrecord_t *record);

void housekeeping_task_ruen(void);

uint8_t get_cur_lang(void);

void set_ruen_toggle_mode(uint8_t mode);

uint8_t get_ruen_toggle_mode(void);

void set_ruen_mac_layout(bool mac_layout);

bool get_ruen_mac_layout(void);
