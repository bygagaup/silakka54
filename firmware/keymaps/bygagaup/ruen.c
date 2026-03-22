// Copyright 2024
// SPDX-License-Identifier: GPL-2.0-or-later

#include "ruen.h"

static uint8_t cur_lang = LANG_EN;  // Current language state

// Send Win+Space to switch layout
static void set_lang(uint8_t lang) {
    if (cur_lang == lang) return;

    uint8_t mods = get_mods();
    del_mods(mods);

    register_code(KC_LGUI);
    tap_code(KC_SPACE);
    unregister_code(KC_LGUI);

    add_mods(mods);
    cur_lang = lang;
}

static void lang_toggle(void) {
    set_lang(cur_lang == LANG_EN ? LANG_RU : LANG_EN);
}

static void lang_sync(void) {
    cur_lang = cur_lang == LANG_EN ? LANG_RU : LANG_EN;
}

bool process_record_ruen(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RUEN_TOGGLE:
            if (record->event.pressed) lang_toggle();
            return false;
        case RUEN_SYNC:
            if (record->event.pressed) lang_sync();
            return false;
        case RUEN_EN:
            if (record->event.pressed) set_lang(LANG_EN);
            return false;
        case RUEN_RU:
            if (record->event.pressed) set_lang(LANG_RU);
            return false;
        default:
            return true;
    }
}
