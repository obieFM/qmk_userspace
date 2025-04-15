// Copyright 2025 Simon Barker <obiefm@pm.me>

#pragma once

#define TAPPING_TOGGLE 2
#define TAPPING_TERM 150
#define TAP_CODE_DELAY 20
#define ENABLE_COMPILE_KEYCODE
#define DYNAMIC_KEYMAP_LAYER_COUNT 5

#define RUN SS_DOWN(X_RGUI)SS_TAP(X_R)SS_UP(X_RGUI)SS_DELAY(50)
#define SELALL SS_DOWN(X_LCTL)SS_TAP(X_A)SS_UP(X_LCTL)SS_DELAY(20)
#define ENTER SS_DELAY(20)SS_TAP(X_ENT)
#define HANDLED return false;
#define UNHANDLED return true;

#define ALT_MO1 MO(1)
#define F1_F15  LT(0, KC_F1)
#define F2_F16  LT(0, KC_F2)
#define F3_F17  LT(0, KC_F3)
#define F4_F18  LT(0, KC_F4)
#define F5_F19  LT(0, KC_F5)
#define REPLAY  LCA(KC_Y)
#define RECORD  LCA(KC_U)
#define MUTE    LCA(KC_M)
#define DEAFEN  LCA(KC_D)
#define TSKMGR  RCS(KC_ESC)
#define LANG    RGUI(KC_SPC)
#define HIRA    RCTL(KC_CAPS)
#define KATA    LALT(KC_CAPS)

#define DECLARE_TIMER(name, time) static uint16_t name##_timer; static bool name##_listen; if (name##_listen && timer_elapsed(name##_timer) > time) name##_listen = false;
#define SET_TIMER(name) name##_timer = timer_read(); name##_listen = true;
