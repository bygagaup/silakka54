#include QMK_KEYBOARD_H

#include "oneshot.h"
#include "swapper.h"
#include "ruen.h"
#include "keycodes.h"

#define RESET QK_BOOT

#define ___ KC_NO

#define LA_NAV MO(_NAV)
#define LA_SYM MO(_SYM)
#define LA_ALT MO(_ALT)
#define LA_CMD MO(_CMD)
#define LA_GFN MO(_GFN)

#define QUOT  S(KC_GRV)
#define PIPE  S(KC_BSLS)
#define DPIPE S(RALT(KC_BSLS))
#define SCLN  S(KC_LBRC)
#define CLN   S(KC_RBRC)
#define GRV   RALT(KC_GRV)
#define BSL   RALT(KC_BSLS)
#define NBSP  RALT(KC_SPC)

#define SPACE_L C(G(KC_LEFT))
#define SPACE_R C(G(KC_RGHT))

#define TAB_L C(S(KC_TAB))
#define TAB_R C(KC_TAB)

enum layers {
    _DEF,
    _NAV,
    _SYM,
    _NUM,
    _ALT,
    _GAM,
    _GFN,
    _CMD,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DEF] = LAYOUT(
        ___,  KC_1,         KC_2,          KC_3,        KC_4,         KC_5,                 KC_6,           KC_7,       KC_8,          KC_9,         KC_0,          ___,
        ___,  KC_Q,         KC_W,          KC_E,        KC_R,         KC_T,                 KC_Y,           KC_U,       KC_I,          KC_O,         KC_P,          KC_LBRC,
        ___,  KC_A,         KC_S,          KC_D,        KC_F,         KC_G,                 KC_H,           KC_J,       KC_K,          KC_L,         KC_SCLN,       KC_QUOT,
        ___,  KC_Z,         KC_X,          KC_C,        KC_V,         KC_B,                 KC_N,           KC_M,       KC_COMM,       KC_DOT,       KC_SLSH,       KC_RBRC,
                                        KC_LGUI,    LA_NAV,     KC_SPC,         KC_ENT,     LA_SYM,     LA_ALT
    ),

    [_NAV] = LAYOUT(
        ___,  ___,          ___,           ___,         ___,          ___,                  ___,            ___,        ___,           ___,          ___,           ___,
        ___,  SW_TAB,       SW_WIN,        TAB_L,       TAB_R,        KC_ESC,               ___,            LG_SET_EN,  LG_SET_RU,     LG_SYNC,      ___,           ___,
        ___,  OS_CMD,       OS_ALT,        OS_CTRL,     OS_SHFT,      KC_TAB,               KC_LEFT,        KC_DOWN,    KC_UP,         KC_RIGHT,     ___,           ___,
        ___,  SPACE_L,      SPACE_R,       DF(_GAM),    KC_PSCR,      KC_CAPS,              KC_HOME,        KC_PGUP,    KC_PGDN,       KC_END,       KC_NUM,        ___,
                                        _______,    _______,    _______,        _______,    KC_BSPC,  KC_DEL
    ),

    [_SYM] = LAYOUT(
        ___,  ___,          ___,           ___,         ___,          ___,                  ___,            ___,        ___,           ___,          ___,           ___,
        ___,  LSFT(KC_1),   LG_AT,         LG_HASH,     LG_DLR,       LSFT(KC_5),           LG_CIRC,        LG_AMPR,    LSFT(KC_8),    LSFT(KC_9),   LSFT(KC_0),    ___,
        ___,  LG_TILD,      LG_GRAVE,      LG_QUOTE,    LG_DQUO,      KC_MINUS,             LSFT(KC_EQUAL), OS_SHFT,    OS_CTRL,       OS_ALT,       OS_CMD,        ___,
        ___,  KC_BSLS,      LG_QUES,       LG_SCLN,     LG_COMMA,     LSFT(KC_MINUS),       KC_EQUAL,       LG_DOT,     LG_COLON,      LG_PIPE,      LG_SLASH,      ___,
                                        _______,    _______,    _______,        _______,    _______,    _______
    ),

    [_NUM] = LAYOUT(
        ___,   ___,          ___,           ___,         ___,          ___,                 ___,            ___,        ___,           ___,          ___,           ___,
        ___,   KC_P1,        KC_P2,         KC_P3,       KC_P4,        KC_P5,               KC_P6,          KC_P7,      KC_P8,         KC_P9,        KC_P0,         ___,
        ___,   OS_CMD,       OS_ALT,        OS_CTRL,     OS_SHFT,      KC_F11,              KC_F12,         OS_SHFT,    OS_CTRL,       OS_ALT,       OS_CMD,        ___,
        ___,   KC_F1,        KC_F2,         KC_F3,       KC_F4,        KC_F5,               KC_F6,          KC_F7,      KC_F8,         KC_F9,        KC_F10,        ___,
                                        _______,    _______,    _______,        _______,    _______,    _______
    ),

    [_ALT] = LAYOUT(
        ___,   ___,          ___,           ___,         ___,          ___,                 ___,            ___,        ___,           ___,          ___,           ___,
        ___,   RALT(KC_Q),   RALT(KC_W),    RALT(KC_E),  RALT(KC_R),   RALT(KC_T),          RALT(KC_Y),     RALT(KC_U), RALT(KC_I),    RALT(KC_O),   RALT(KC_P),    ___,
        ___,   RALT(KC_A),   RALT(KC_S),    RALT(KC_D),  RALT(KC_F),   RALT(KC_G),          RALT(KC_H),     RALT(KC_J), RALT(KC_K),    RALT(KC_L),   RALT(KC_SCLN), ___,
        ___,   RALT(KC_Z),   RALT(KC_X),    RALT(KC_C),  RALT(KC_V),   RALT(KC_B),          RALT(KC_N),     RALT(KC_M), RALT(KC_COMM), RALT(KC_DOT), RALT(KC_SLSH), ___,
                                        _______,    NBSP,       KC_LSFT,        _______,    _______,    _______
    ),

    [_GAM] = LAYOUT(
        ___,   ___,          ___,           ___,         ___,          ___,                 ___,            ___,        ___,           ___,          ___,           ___,
        ___,   KC_TAB,       KC_Q,          KC_W,        KC_E,         KC_R,                ___,            ___,        KC_UP,         ___,          KC_TAB,        ___,
        ___,   KC_LSFT,      KC_A,          KC_S,        KC_D,         KC_F,                ___,            KC_LEFT,    KC_DOWN,       KC_RGHT,      KC_RSFT,       ___,
        ___,   KC_LCTL,      KC_Z,          KC_X,        KC_C,         KC_V,                ___,            ___,        ___,           ___,          KC_RCTL,       ___,
                                        KC_LALT,    KC_SPC,     LA_GFN,         DF(_DEF),   KC_SPC,     KC_PSCR
    ),

    [_GFN] = LAYOUT(
        ___,   ___,          ___,           ___,         ___,          ___,                 ___,            ___,        ___,           ___,          ___,           ___,
        ___,   KC_5,         KC_1,          KC_2,        KC_3,         KC_4,                KC_NUM,         ___,        ___,           ___,          ___,           ___,
        ___,   KC_0,         KC_6,          KC_7,        KC_8,         KC_9,                ___,            ___,        ___,           ___,          ___,           ___,
        ___,   KC_G,         KC_J,          KC_I,        KC_M,         KC_T,                ___,            ___,        ___,           QK_RBT,       QK_BOOT,       ___,
                                        KC_ESC,     KC_ENT,     _______,        _______,    _______,    _______
    ),

    [_CMD] = LAYOUT(
        ___,   ___,          ___,           ___,         ___,          ___,                 ___,            ___,        ___,           ___,          ___,           ___,
        ___,   MEH(KC_Q),    MEH(KC_W),     MEH(KC_E),   MEH(KC_R),    MEH(KC_T),           MEH(KC_Y),      KC_VOLD,    KC_MUTE,       KC_VOLU,      MEH(KC_P),     ___,
        ___,   MEH(KC_A),    MEH(KC_S),     MEH(KC_D),   MEH(KC_F),    MEH(KC_G),           MEH(KC_H),      KC_MPRV,    KC_MPLY,       KC_MNXT,      MEH(KC_SCLN),  ___,
        ___,   MEH(KC_Z),    MEH(KC_X),     MEH(KC_C),   MEH(KC_V),    MEH(KC_B),           MEH(KC_N),      MEH(KC_M),  MEH(KC_COMM),  MEH(KC_DOT),  MEH(KC_SLSH),  ___,
                                        _______,    _______,    _______,        KC_LGUI,    _______,    _______
    )
};

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT(
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R', 
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R', 
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R', 
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R', 
                       'L', 'L', 'L',  'R', 'R', 'R'
    );

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case LA_SYM:
    case LA_NAV:
        return true;
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case LA_SYM:
    case LA_NAV:
    case LA_ALT:
    case LA_CMD:
    case LA_GFN:
    case KC_LSFT:
    case OS_SHFT:
    case OS_CTRL:
    case OS_ALT:
    case OS_CMD:
        return true;
    default:
        return false;
    }
}

bool sw_win_active = false;
bool sw_tab_active = false;

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;

bool pre_process_record_user(uint16_t keycode, keyrecord_t *record) {
    return pre_process_record_ruen(keycode, record);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_swapper(
        &sw_win_active, KC_LALT, KC_TAB, SW_WIN, OS_SHFT,
        keycode, record
    );
    update_swapper(
        &sw_tab_active, KC_LCTL, KC_TAB, SW_TAB, OS_SHFT,
        keycode, record
    );

    update_oneshot(
        &os_shft_state, KC_LSFT, OS_SHFT,
        keycode, record
    );
    update_oneshot(
        &os_ctrl_state, KC_LCTL, OS_CTRL,
        keycode, record
    );
    update_oneshot(
        &os_alt_state, KC_LALT, OS_ALT,
        keycode, record
    );
    update_oneshot(
        &os_cmd_state, KC_LCMD, OS_CMD,
        keycode, record
    );

    return process_record_ruen(keycode, record);
}

void housekeeping_task_user(void) {
    housekeeping_task_ruen();
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes for russian symbols
        case KC_SCLN:
        case KC_QUOT:
        case KC_LBRC:
        case KC_RBRC:
        case KC_GRAVE:
        case KC_COMMA:
        case KC_DOT:
            if (get_cur_lang() == LANG_RU) {
                add_weak_mods(MOD_BIT(KC_LSFT));
                return true;
            } else
                return false;

        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_MINS:
        // For some reason weak mode doesn't work on this keycodes
        // so we additionaly add weak mode in process_russian_letter(...)
        case LG_RU_BE:
        case LG_RU_YU:
        case LG_RU_ZHE:
        case LG_RU_E:
        case LG_RU_HRD_SGN:
        case LG_RU_KHA:
        case LG_RU_YO:
            add_weak_mods(MOD_BIT(KC_LSFT));
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;

        default:
            return false;
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _SYM, _NAV, _NUM);
}
