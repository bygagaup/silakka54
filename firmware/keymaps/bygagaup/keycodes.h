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

    // RuEn (ported from ergohaven/src/eh_ruen.h)
    LG_START,

    LG_TOGGLE = LG_START,
    LG_SYNC,
    LG_SET_EN,
    LG_SET_RU,
    LG_SET_M0,
    LG_SET_M1M2,
    LG_SET_DFLT,

    LG_DOT,
    LG_COMMA,
    LG_SCLN,
    LG_COLON,
    LG_DQUO,
    LG_QUES,
    LG_SLASH,

    // symbols exist in english only layout
    LG_EN_START,
    LG_LBR = LG_EN_START,
    LG_RBR,
    LG_LCBR,
    LG_RCBR,
    LG_LT,
    LG_GT,
    LG_GRAVE,
    LG_TILD,
    LG_AT,
    LG_HASH,
    LG_DLR,
    LG_CIRC,
    LG_AMPR,
    LG_PIPE,
    LG_QUOTE,

    // symbols exist in russian only layout
    LG_NUM,

    LG_WORD,
    LG_MOD,
    LG_STORE,
    LG_REVERT,

    // Additional keycodes for Mac
    LG_PERC,
    LG_TG_MAC,

    // Russian symbols (do nothing on English layout)
    LG_RU_BE,
    LG_RU_YU,
    LG_RU_ZHE,
    LG_RU_E,
    LG_RU_KHA,
    LG_RU_HRD_SGN,
    LG_RU_YO,

    // end of ru en symbols range
    LG_END,
};
