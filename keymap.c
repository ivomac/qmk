#include QMK_KEYBOARD_H

#define COMPOSE KC_APP

#define tapkey_noshift(kk) {\
	unregister_code(KC_LSFT);\
	register_code(kk);\
	unregister_code(kk);\
	register_code(KC_LSFT);\
}

#define tapkey(kk) {\
	register_code(kk);\
	unregister_code(kk);\
}

enum planck_layers {
	L0_QWERTY,
	L0,
	L1,
	L2,
	L3,
	MOUSE,
};

enum custom_keycodes {
	M_ACUTE = SAFE_RANGE,
	M_DEADACUTE,
	M_DEADGREEK,
	M_GRAVE,
	M_DOT,
	M_DEADDOT,
	M_LDOT,
	M_TIMES,
	M_BAR,
	M_LBAR,
	M_DEADBAR,
	M_DEADGRAVE,
	M_CIRCUM,
	M_TILDE,
	M_CEDILLA,
	M_SCOLON,
	M_UMLAUT,
	M_NBSP,
	M_GLEFT,
	M_GRIGHT,
	M_DEGREE,
	M_MASC,
	M_FEMI,
	M_DQUOTELEFT,
	M_DQUOTERIGHT,
	M_DASH,
	M_F1,
	M_F2,
	M_F3,
	M_F4,
	M_F5,
	M_F6,
	M_F7,
	M_F8,
	M_F9,
	M_F10,
	M_F11,
	M_F12,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[L0_QWERTY] = LAYOUT_planck_mit(
			KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,      KC_Y,          KC_U,         KC_I,    KC_O,    KC_P,     KC_BSPC,
			KC_SLASH, KC_A,    KC_S,    KC_D,    KC_F,  KC_G,      KC_M,          KC_H,         KC_J,    KC_K,    KC_L,     KC_MINUS,
			KC_ESC,   KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,      KC_N,          KC_BACKSLASH, KC_COMM, KC_DOT,  KC_QUOTE, KC_ENT,
			KC_LEFT,  KC_DOWN, KC_LALT, KC_LCTL, LM(L1, MOD_LSFT), /***/  KC_SPC, MO(L2),       KC_LGUI, KC_RALT, KC_UP,    KC_RGHT
			),

	[L0] = LAYOUT_planck_mit(
			KC_TAB,   KC_Q,    KC_W,    KC_F,    KC_P,  KC_B,      KC_J,          KC_L,   KC_U,    KC_Y,    KC_BACKSLASH, KC_BSPC,
			KC_SLASH, KC_A,    KC_R,    KC_S,    KC_T,  KC_G,      KC_M,          KC_N,   KC_E,    KC_I,    KC_O,         KC_MINUS,
			KC_ESC,   KC_Z,    KC_X,    KC_C,    KC_D,  KC_V,      KC_K,          KC_H,   KC_COMM, KC_DOT,  KC_QUOTE,     KC_ENT,
			KC_LEFT,  KC_DOWN, KC_LALT, KC_LCTL, LM(L1, MOD_LSFT), /***/  KC_SPC, MO(L2), KC_LGUI, KC_RALT, KC_UP,        KC_RGHT
			),

	[L1] = LAYOUT_planck_mit(
			_______, _______, _______, _______, _______, _______,          _______, _______, _______,   _______,      _______, _______,
			_______, _______, _______, _______, _______, _______,          _______, _______, _______,   _______,      _______, _______,
			_______, _______, _______, _______, _______, _______,          _______, _______, M_SCOLON,  KC_SEMICOLON, _______, _______,
			_______, _______, _______, _______, _______, /***/    _______, _______, _______, TG(MOUSE), _______,      _______
			),

	[L2] = LAYOUT_planck_mit(
			KC_PSCR,    KC_0,          KC_1,       KC_2,           KC_3,          KC_4,               KC_5,           KC_6,       KC_7,           KC_8,         KC_9,       KC_DEL,
			LSFT(KC_1), LSFT(KC_LBRC), LSFT(KC_9), LSFT(KC_0),     LSFT(KC_RBRC), LSFT(KC_3),         LSFT(KC_8),     LSFT(KC_6), KC_LBRC,        KC_RBRC,      LSFT(KC_4), COMPOSE,
			KC_PGUP,    LSFT(KC_2),    LSFT(KC_5), LSFT(KC_EQUAL), KC_EQUAL,      M_ACUTE,            LSFT(KC_GRAVE), LSFT(KC_7), LSFT(KC_COMMA), LSFT(KC_DOT), KC_GRAVE,   KC_PGDN,
			_______,    _______,       _______,    _______,        _______,       /***/       M_NBSP, _______,        _______,    _______,        _______,      _______
			),


	[L3] = LAYOUT_planck_mit(
			KC_SYRQ, KC_BRK,  M_F1,          M_F2,    M_F3,    M_F4,              M_F5,    M_F6,     M_F7,      M_F8,      M_F9,        KC_INS,
			QK_LOCK, KC_LEFT, KC_DOWN,       KC_UP,   KC_RGHT, M_DEADGREEK,       M_TIMES, M_CIRCUM, M_DOT,     M_DEADDOT, M_LDOT,      M_DEADBAR,
			KC_HOME, M_LBAR,  DF(L0_QWERTY), DF(L0),  XXXXXXX, M_DEADACUTE,       M_TILDE, XXXXXXX,  M_CEDILLA, M_UMLAUT,  M_DEADGRAVE, KC_END,
			QK_BOOT, XXXXXXX, XXXXXXX,       XXXXXXX, _______, /***/     XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,   XXXXXXX,   QK_BOOTLOADER
			),


	[MOUSE] = LAYOUT_planck_mit(
			_______, KC_KP_0,    KC_KP_1,    KC_KP_2,    KC_KP_3,       KC_KP_4,          KC_KP_5, KC_KP_6,       KC_KP_7,     KC_KP_8,  KC_KP_9,     _______,
			XXXXXXX, KC_MS_BTN4, KC_MS_BTN3, KC_MS_BTN1, KC_MS_BTN2,    XXXXXXX,          XXXXXXX, KC_MS_LEFT,    KC_MS_DOWN,  KC_MS_UP, KC_MS_RIGHT, XXXXXXX,
			_______, KC_MS_BTN8, KC_MS_BTN7, KC_MS_BTN6, KC_MS_BTN5,    XXXXXXX,          XXXXXXX, KC_MS_WH_DOWN, KC_MS_WH_UP, XXXXXXX,  XXXXXXX,     _______,
			_______, _______,    _______,    _______,    KC_LEFT_SHIFT, /***/    _______, XXXXXXX, _______,       TG(MOUSE),   _______,  _______
			),

};

layer_state_t layer_state_set_user(layer_state_t state) {
	state = update_tri_layer_state(state, L1, L2, L3);
	return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case M_F1:
			if (record->event.pressed) {
				tapkey_noshift(KC_F1);
			}
			return false;
			break;
		case M_F2:
			if (record->event.pressed) {
				tapkey_noshift(KC_F2);
			}
			return false;
			break;
		case M_F3:
			if (record->event.pressed) {
				tapkey_noshift(KC_F3);
			}
			return false;
			break;
		case M_F4:
			if (record->event.pressed) {
				tapkey_noshift(KC_F4);
			}
			return false;
			break;
		case M_F5:
			if (record->event.pressed) {
				tapkey_noshift(KC_F5);
			}
			return false;
			break;
		case M_F6:
			if (record->event.pressed) {
				tapkey_noshift(KC_F6);
			}
			return false;
			break;
		case M_F7:
			if (record->event.pressed) {
				tapkey_noshift(KC_F7);
			}
			return false;
			break;
		case M_F8:
			if (record->event.pressed) {
				tapkey_noshift(KC_F8);
			}
			return false;
			break;
		case M_F9:
			if (record->event.pressed) {
				tapkey_noshift(KC_F9);
			}
			return false;
			break;
		case M_ACUTE:
			if (record->event.pressed) {
				unregister_code(KC_LSFT);
				tapkey(COMPOSE);
				send_string("''");
				register_code(KC_LSFT);
			}
			return false;
			break;
		case M_DEADGREEK:
			if (record->event.pressed) {
				unregister_code(KC_LSFT);
				tapkey(COMPOSE);
				send_string("g");
				register_code(KC_LSFT);
			}
			return false;
			break;
		case M_DEADACUTE:
			if (record->event.pressed) {
				unregister_code(KC_LSFT);
				tapkey(COMPOSE);
				send_string("'");
				register_code(KC_LSFT);
			}
			return false;
			break;
		case M_DEADGRAVE:
			if (record->event.pressed) {
				unregister_code(KC_LSFT);
				tapkey(COMPOSE);
				send_string("`");
				register_code(KC_LSFT);
			}
			return false;
			break;
		case M_DEADBAR:
			if (record->event.pressed) {
				unregister_code(KC_LSFT);
				tapkey(COMPOSE);
				send_string("-");
				register_code(KC_LSFT);
			}
			return false;
			break;
		case M_LBAR:
			if (record->event.pressed) {
				unregister_code(KC_LSFT);
				tapkey(COMPOSE);
				send_string("---");
				register_code(KC_LSFT);
			}
			return false;
			break;
		case M_DEADDOT:
			if (record->event.pressed) {
				unregister_code(KC_LSFT);
				tapkey(COMPOSE);
				send_string(".");
				register_code(KC_LSFT);
			}
			return false;
			break;
		case M_DOT:
			if (record->event.pressed) {
				unregister_code(KC_LSFT);
				tapkey(COMPOSE);
				send_string("^.");
				register_code(KC_LSFT);
			}
			return false;
			break;
		case M_LDOT:
			if (record->event.pressed) {
				unregister_code(KC_LSFT);
				tapkey(COMPOSE);
				send_string("=.");
				register_code(KC_LSFT);
			}
			return false;
			break;
		case M_TIMES:
			if (record->event.pressed) {
				unregister_code(KC_LSFT);
				tapkey(COMPOSE);
				send_string("xx");
				register_code(KC_LSFT);
			}
			return false;
			break;
		case M_TILDE:
			if (record->event.pressed) {
				unregister_code(KC_LSFT);
				tapkey(COMPOSE);
				send_string("~");
				register_code(KC_LSFT);
			}
			return false;
			break;
		case M_CIRCUM:
			if (record->event.pressed) {
				unregister_code(KC_LSFT);
				tapkey(COMPOSE);
				send_string("^");
				register_code(KC_LSFT);
			}
			return false;
			break;
		case M_CEDILLA:
			if (record->event.pressed) {
				unregister_code(KC_LSFT);
				tapkey(COMPOSE);
				send_string(",");
				register_code(KC_LSFT);
			}
			return false;
			break;
		case M_SCOLON:
			if (record->event.pressed) {
				unregister_code(KC_LSFT);
				send_string(";");
				register_code(KC_LSFT);
			}
			return false;
			break;
		case M_NBSP:
			if (record->event.pressed) {
				unregister_code(KC_LSFT);
				tapkey(COMPOSE);
				send_string("  ");
				register_code(KC_LSFT);
			}
			return false;
			break;
		case M_UMLAUT:
			if (record->event.pressed) {
				unregister_code(KC_LSFT);
				tapkey(COMPOSE);
				send_string("\"");
				register_code(KC_LSFT);
			}
			return false;
			break;
		case M_DASH:
			if (record->event.pressed) {
				unregister_code(KC_LSFT);
				tapkey(COMPOSE);
				send_string("---");
				register_code(KC_LSFT);
			}
			return false;
			break;
	}
	return true;
}

