// Copyright 2025 Simon Barker <obiefm@pm.me>

#include QMK_KEYBOARD_H
#include "elpekenin/indicators.h"

enum custom_keycodes {
    M0 = SAFE_RANGE,
    M1,
    M2,
    M3,
    M4,
    M5,
    M6,
    M7,
    M8,
    M9,
    M10
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        QK_GESC,  KC_1,  KC_2,  KC_3,  KC_4,     KC_5,                      KC_6,    KC_7,    KC_8,     KC_9,    KC_0,     KC_BSPC,
        KC_TAB,   KC_Q,  KC_W,  KC_E,  KC_R,     KC_T,                      KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,     KC_DEL,
        KC_LALT,  KC_A,  KC_S,  KC_D,  KC_F,     KC_G,                      KC_H,    KC_J,    KC_K,     KC_L,    KC_SCLN,  KC_QUOT,
        KC_LSFT,  KC_Z,  KC_X,  KC_C,  KC_V,     KC_B,    TT(3),    TT(4),  KC_N,    KC_M,    KC_COMM,  KC_DOT,  KC_SLSH,  KC_RSFT,
                                       KC_LCTL,  KC_SPC,  ALT_MO1,  MO(2),  KC_ENT,  KC_RGUI
    ),
    [1] = LAYOUT(
        KC_GRV,        F1_F15,             F2_F16,      F3_F17,             F4_F18,      F5_F19,                     KC_F6,    KC_F7,   KC_F8,   KC_F9,  KC_F10,   KC_F11,
        LALT(KC_TAB),  QK_MOUSE_BUTTON_4,  KC_UP,       QK_MOUSE_BUTTON_5,  LCTL(KC_Y),  KC_F6,                      REPLAY,   RECORD,  M1,      M2,     M3,       M4,
        KC_CAPS,       KC_LEFT,            KC_DOWN,     KC_RGHT,            LCTL(KC_F),  KC_F7,                      M5,       KC_F20,  TSKMGR,  LANG,   KC_F13,   KC_F14,
        KC_LSFT,       LCTL(KC_Z),         LCTL(KC_X),  LCTL(KC_C),         LCTL(KC_V),  KC_F8,   XXXXXXX,  KC_F23,  KC_CALC,  KC_F21,  HIRA,    KATA,   KC_PIPE,  KC_BSLS,
                                                                            LALT(KC_Z),  M0,      _______,  KC_F24,  MUTE,     DEAFEN
    ),
    [2] = LAYOUT(
        _______,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_LPRN,                      KC_RPRN,  KC_AMPR,  KC_ASTR,  KC_MINS,  KC_EQL,   KC_BSPC,
        _______,  _______,  _______,  _______,  _______,  KC_LCBR,                      KC_RCBR,  KC_HOME,  KC_PGUP,  KC_UNDS,  KC_PLUS,  KC_DEL,
        _______,  _______,  _______,  _______,  _______,  KC_LBRC,                      KC_RBRC,  KC_END,   KC_PGDN,  KC_COLN,  KC_SCLN,  KC_DQT,
        _______,  _______,  _______,  _______,  _______,  KC_LT,    XXXXXXX,  XXXXXXX,  KC_GT,    KC_APP,   KC_COMM,  KC_DOT,   KC_BSLS,  KC_PIPE,
                                                XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,  KC_PSCR,  KC_F12
    ),
    [3] = LAYOUT(
        KC_ESC,      KC_F10,         KC_F11,         KC_F5,           LALT(KC_F4),  KC_BSPC,                        UG_TOGG,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        LALT(KC_P),  M6,             LCTL(KC_UP),    M7,              KC_PGUP,      KC_DEL,                         MS_WHLU,  MS_BTN1,  MS_UP,    MS_BTN2,  XXXXXXX,  XXXXXXX,
        KC_F1,       LCTL(KC_LEFT),  LCTL(KC_DOWN),  LCTL(KC_RIGHT),  KC_PGDN,      RCS(KC_L),                      MS_WHLD,  MS_LEFT,  MS_DOWN,  MS_RGHT,  XXXXXXX,  XXXXXXX,
        REPLAY,      REPLAY,         RECORD,         MUTE,            DEAFEN,       M8,         _______,  XXXXXXX,  M9,       M10,      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                                                      XXXXXXX,      XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
    ),
    [4] = LAYOUT(
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                      KC_G,     KC_PERC,  KC_Q,   KC_PMNS,  KC_PPLS,  KC_BSPC,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                      KC_TAB,   KC_P7,    KC_P8,  KC_P9,    KC_F9,    KC_DEL,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                      KC_PAST,  KC_P4,    KC_P5,  KC_P6,    KC_PAST,  KC_PENT,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,  KC_F9,    KC_P1,    KC_P2,  KC_P3,    KC_PSLS,  KC_ESC,
                                                XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_PENT,  KC_P0,    KC_PDOT
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    DECLARE_TIMER(mo1, 2000)
    DECLARE_TIMER(winget_find, 2000)
    DECLARE_TIMER(BRZ, 2000)

    if (record->event.pressed) {

        if (IS_LAYER_ON(1))
        {
            mo1_listen = false;
        }

        switch (keycode) {
            case M0:
                SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_SPC)SS_UP(X_LALT)SS_DELAY(20)SS_TAP(X_M)SS_DELAY(20)SS_TAP(X_DOWN));
                HANDLED
            case M1:
                SEND_STRING(RUN"winget install ");
                HANDLED
            case M2:
                SEND_STRING(RUN"cmd /k winget find ");
                SET_TIMER(winget_find)
                HANDLED
            case M3:
                SEND_STRING(RUN"\"C:\\ProgramData\\Microsoft\\Windows\\Start Menu\\Programs\\QMK MSYS\""ENTER SS_DELAY(1000)"qmk compile -j 0"ENTER);
                HANDLED
            case M4:
                SEND_STRING(RUN"\%localappdata\%\\Programs\\Obsidian\\Obsidian.exe"ENTER);
                HANDLED
            case M5:
                SEND_STRING(RUN"msedge.exe https://usevia.app/"ENTER);
                HANDLED
            case M6:
                SEND_STRING(SELALL"Private"ENTER);
                HANDLED
            case M7:
                SEND_STRING(SELALL"Public"ENTER);
                HANDLED
            case M8:
                SEND_STRING("[BRZ-]"SS_DELAY(20)SS_TAP(X_LEFT));
                SET_TIMER(BRZ);
                HANDLED

            case KC_ENT:
                if (winget_find_listen)
                {
                    SEND_STRING(SS_TAP(X_ENT)SS_DELAY(1000)"winget install ");
                    winget_find_listen = BRZ_listen = false;
                    HANDLED
                }
                if (BRZ_listen)
                {
                    SEND_STRING(SS_TAP(X_RIGHT)SS_TAP(X_SPC));
                    winget_find_listen = BRZ_listen = false;
                    HANDLED
                }
                UNHANDLED
            case F1_F15:
                register_code(KC_F15);
                UNHANDLED
            case F2_F16:
                register_code(KC_F16);
                UNHANDLED
            case F3_F17:
                register_code(KC_F17);
                UNHANDLED
            case F4_F18:
                register_code(KC_F18);
                UNHANDLED
            case F5_F19:
                register_code(KC_F19);
                UNHANDLED
            case ALT_MO1:
                SET_TIMER(mo1);
                UNHANDLED
        }
    }
    else switch(keycode) {
        case LT(0, KC_F1):
            unregister_code(KC_F15);
            UNHANDLED
        case LT(0, KC_F2):
            unregister_code(KC_F16);
            UNHANDLED
        case LT(0, KC_F3):
            unregister_code(KC_F17);
            UNHANDLED
        case LT(0, KC_F4):
            unregister_code(KC_F18);
            UNHANDLED
        case LT(0, KC_F5):
            unregister_code(KC_F19);
            UNHANDLED
        case ALT_MO1:
            if (mo1_listen)
            {
                mo1_listen = false;
                tap_code(KC_RALT);
            }
            UNHANDLED
    }

    UNHANDLED
};

const indicator_t PROGMEM indicators[] = {
    KEYCODE_IN_LAYER_INDICATOR(TT(3), 3, RGB_WHITE),
    KEYCODE_IN_LAYER_INDICATOR(TT(4), 4, RGB_WHITE),
    KEYCODE_IN_LAYER_INDICATOR(ALT_MO1, 1, RGB_WHITE),
    KEYCODE_IN_LAYER_INDICATOR(MO(2), 2, RGB_WHITE)
};
