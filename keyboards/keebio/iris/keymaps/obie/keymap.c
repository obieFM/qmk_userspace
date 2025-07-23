// Copyright 2025 Simon Barker <obiefm@pm.me>

#include QMK_KEYBOARD_H

enum custom_keycodes {
    M_MOVE = SAFE_RANGE,
    M_WINGET,
    M_QMK,
    M_VIA,
    M_PRIVATE,
    M_PUBLIC,
    M_BRZ,
    M_1MON,
    M_2MON,
    M_GPT,
    M_SMS
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        QK_GESC,  KC_1,    KC_2,  KC_3,  KC_4,     KC_5,                      KC_6,    KC_7,    KC_8,     KC_9,    KC_0,     KC_BSPC,
        KC_TAB,   KC_Q,    KC_W,  KC_E,  KC_R,     KC_T,                      KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,     KC_DEL,
        KC_LALT,  KC_A,    KC_S,  KC_D,  KC_F,     KC_G,                      KC_H,    KC_J,    KC_K,     KC_L,    KC_SCLN,  KC_QUOT,
        KC_LSFT,  KC_Z,    KC_X,  KC_C,  KC_V,     KC_B,    MO(3),    MO(3),  KC_N,    KC_M,    KC_COMM,  KC_DOT,  KC_SLSH,  KC_RSFT,
                                         KC_LCTL,  KC_SPC,  ALT_MO1,  MO(2),  KC_ENT,  KC_RGUI
    ),
    [1] = LAYOUT(
        KC_GRV,        F1_F15,     F2_F16,   F3_F17,    F4_F18,       F5_F19,                      KC_F6,    KC_F7,   KC_F8,     KC_F9,   KC_F10,   KC_F11,
        LALT(KC_TAB),  M_PRIVATE,  KC_UP,    M_PUBLIC,  LCTL(KC_Y),   REPLAY,                      REPLAY,   RECORD,  M_WINGET,  KC_F24,  XXXXXXX,  M_QMK,
        KC_CAPS,       KC_LEFT,    KC_DOWN,  KC_RGHT,   XXXXXXX,      RECORD,                      M_VIA,    M_GPT,   TSKMGR,    LANG,    M_1MON,   M_2MON,
        KC_LSFT,       XXXXXXX,    XXXXXXX,  MUTE,      DEAFEN,       M_BRZ,   XXXXXXX,  XXXXXXX,  KC_CALC,  M_SMS,   HIRA,      KATA,    KC_PIPE,  KC_BSLS,
                                                        LALT(KC_F4),  M_MOVE,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
    ),
    [2] = LAYOUT(
        KC_GRV,   KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_LPRN,                      KC_RPRN,  KC_AMPR,  KC_ASTR,  KC_MINS,  KC_EQL,   KC_BSPC,
        MS_BTN4,  MS_BTN1,  MS_UP,    MS_BTN2,  MS_WHLU,  KC_LCBR,                      KC_RCBR,  KC_HOME,  KC_PGUP,  KC_UNDS,  KC_PLUS,  KC_DEL,
        MS_BTN5,  MS_LEFT,  MS_DOWN,  MS_RGHT,  MS_WHLD,  KC_LBRC,                      KC_RBRC,  KC_END,   KC_PGDN,  KC_COLN,  KC_SCLN,  KC_DQT,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_LT,    XXXXXXX,  XXXXXXX,  KC_GT,    KC_APP,   KC_COMM,  KC_DOT,   KC_BSLS,  KC_PIPE,
                                                XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_PSCR,  KC_F12
    ),
    [3] = LAYOUT(
        KC_6,    KC_7,    KC_8,     KC_9,    KC_0,     KC_BSPC,                      QK_GESC,  KC_1,  KC_2,  KC_3,  KC_4,  KC_5,
        KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,     KC_DEL,                       KC_TAB,   KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,
        KC_H,    KC_J,    KC_K,     KC_L,    KC_SCLN,  KC_QUOT,                      KC_LALT,  KC_A,  KC_S,  KC_D,  KC_F,  KC_G,
        KC_N,    KC_M,    KC_COMM,  KC_DOT,  KC_SLSH,  KC_RSFT,  XXXXXXX,  XXXXXXX,  KC_LSFT,  KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,
                                             KC_LGUI,  KC_ENT,   XXXXXXX,  XXXXXXX,  KC_SPC,   KC_RCTL
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    DECLARE_TIMER(mo1, 2000)

    if (record->event.pressed) {

        if (IS_LAYER_ON(1))
        {
            mo1_listen = false;
        }

        switch (keycode) {
            case M_MOVE:
                SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_SPC)SS_UP(X_LALT)SS_DELAY(20)SS_TAP(X_M)SS_DELAY(20)SS_TAP(X_DOWN));
                HANDLED
            case M_WINGET:
                SEND_STRING(RUN"winget install ");
                HANDLED
            case M_QMK:
                SEND_STRING(RUN"\"C:\\ProgramData\\Microsoft\\Windows\\Start Menu\\Programs\\QMK MSYS\""ENTER SS_DELAY(1000)"qmk compile -j 0"ENTER);
                HANDLED
            case M_1MON:
                SEND_STRING(RUN"C:\\Software\\MultiMonitorTool\\MultiMonitorTool.exe /LoadConfig C:\\Software\\MultiMonitorTool\\Secondary.cfg"ENTER);
                HANDLED
            case M_2MON:
                SEND_STRING(RUN"C:\\Software\\MultiMonitorTool\\MultiMonitorTool.exe /LoadConfig C:\\Software\\MultiMonitorTool\\Default.cfg"ENTER);
                HANDLED
            case M_VIA:
                SEND_STRING(RUN"msedge.exe https://usevia.app/"ENTER);
                HANDLED
            case M_GPT:
                SEND_STRING(RUN"C:\\Software\\FirefoxPortable\\FirefoxPortable.exe https://chatgpt.com/"ENTER);
                HANDLED
            case M_SMS:
                SEND_STRING(RUN"C:\\Software\\FirefoxPortable\\FirefoxPortable.exe https://messages.google.com/"ENTER);
                HANDLED
            case M_PRIVATE:
                SEND_STRING(SELALL"Private"ENTER);
                HANDLED
            case M_PUBLIC:
                SEND_STRING(SELALL"Public"ENTER);
                HANDLED
            case M_BRZ:
                SEND_STRING("[BRZ-]"SS_DELAY(20)SS_TAP(X_LEFT));
                HANDLED
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
        case F1_F15:
            unregister_code(KC_F15);
            UNHANDLED
        case F2_F16:
            unregister_code(KC_F16);
            UNHANDLED
        case F3_F17:
            unregister_code(KC_F17);
            UNHANDLED
        case F4_F18:
            unregister_code(KC_F18);
            UNHANDLED
        case F5_F19:
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