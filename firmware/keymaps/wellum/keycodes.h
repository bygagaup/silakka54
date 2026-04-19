#pragma once

#include QMK_KEYBOARD_H

enum custom_keycodes {
    // Custom oneshot mod implementation with no timers.
    OS_SHFT = QK_KB_0,
    OS_CTRL,
    OS_ALT,
    OS_CMD,

    SW_WIN,  // Switch to next window         (alt-tab)
    SW_TAB,  // Switch to next browser tab    (ctrl-tab)

    // Custom RuEn keycodes (Win+Space and Shift+Alt layout switchers)
    RUEN_TOG,  // Toggle EN/RU (Win+Space)
    RUEN_FLIP,    // Flip language tracker only (no key sent)
    RUEN_EN,      // Force English (Win+Space)
    RUEN_RU,      // Force Russian (Win+Space)
};
