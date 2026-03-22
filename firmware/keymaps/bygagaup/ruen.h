// Copyright 2024
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "quantum.h"

// Custom RuEn keycodes (Win+Space and Shift+Alt layout switchers)
enum ruen_custom_keycodes {
    RUEN_TOGGLE = QK_KB_0,        // Toggle EN/RU (Win+Space)
    RUEN_SYNC,                    // Sync keyboard state only
    RUEN_EN,                      // Force English (Win+Space)
    RUEN_RU,                      // Force Russian (Win+Space)
    RUEN_END,
};

enum { LANG_EN = 0, LANG_RU };  // Language states

bool process_record_ruen(uint16_t keycode, keyrecord_t *record);
