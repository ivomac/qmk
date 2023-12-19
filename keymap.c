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
	L0_COLEMAK,
	L1,
	L2,
	L3,
	MOUSE,
	SPACE_MOUSE,
};

enum custom_keycodes {
	M_BASETG = SAFE_RANGE,
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
	M_DEADACUTE,
	M_DEADGRAVE,
	M_DEADDQUOTE,
	M_DEADGREEK,
	M_DEADDOT,
	M_DEADBAR,
	M_DEADCIRCUM,
	M_DEADTILDE,
	M_DEADCEDILLA,
	M_DEADUMLAUT,
	M_DEADSLASH,
	M_DEADUNDERLINE,
	M_APPROX,
	M_DEF,
	M_PM,
	M_TIMES,
	M_CDOT,
	M_BULLET,
	M_SCOLON,
	M_DASH,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[L0_QWERTY] = LAYOUT_planck_mit(
			KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,      KC_Y,         KC_U,     KC_I,    KC_O,    KC_P,     KC_BSPC,
			KC_SLASH, KC_A,    KC_S,    KC_D,    KC_F,  KC_G,      KC_M,         KC_H,     KC_J,    KC_K,    KC_L,     KC_BACKSLASH,
			KC_ESC,   KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,      KC_N,         KC_MINUS, KC_COMM, KC_DOT,  KC_QUOTE, KC_ENT,
			KC_LEFT,  KC_DOWN, KC_LALT, KC_LCTL, LM(L1, MOD_LSFT), /***/ KC_SPC, MO(L2),   KC_LGUI, KC_RALT, KC_UP,    KC_RGHT
			),

	[L0_COLEMAK] = LAYOUT_planck_mit(
			KC_TAB,   KC_Q,    KC_W,     KC_F,     KC_P,  KC_X,      KC_J,         KC_L,   KC_U,    KC_Y,    KC_Z,  KC_BSPC,
			KC_SLASH, KC_A,    KC_R,     KC_S,     KC_T,  KC_G,      KC_M,         KC_N,   KC_E,    KC_I,    KC_O,  KC_BACKSLASH,
			KC_ESC,   KC_V,    KC_QUOTE, KC_MINUS, KC_D,  KC_C,      KC_B,         KC_H,   KC_COMM, KC_DOT,  KC_K,  KC_ENT,
			KC_LEFT,  KC_DOWN, KC_LALT,  KC_LCTL,  LM(L1, MOD_LSFT), /***/ KC_SPC, MO(L2), KC_LGUI, KC_RALT, KC_UP, KC_RGHT
			),

	[L1] = LAYOUT_planck_mit(
			_______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,      _______, _______,
			_______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,      _______, KC_1,
			_______, _______, _______, _______, _______, _______, _______, _______, M_SCOLON, KC_SEMICOLON, _______, _______,
			_______, _______, _______, _______, _______, /***/    _______, _______, _______,  _______,      _______, _______
			),

	[L2] = LAYOUT_planck_mit(
			_______,    KC_1,          KC_2,       KC_3,           KC_4,          KC_5,           KC_6,       KC_7,       KC_8,           KC_9,         KC_0,       _______,
			LSFT(KC_5), LSFT(KC_LBRC), LSFT(KC_9), LSFT(KC_0),     LSFT(KC_RBRC), LSFT(KC_3),     LSFT(KC_8), LSFT(KC_6), KC_LBRC,        KC_RBRC,      LSFT(KC_4), LSFT(KC_BACKSLASH),
			_______,    XXXXXXX,       LSFT(KC_7), LSFT(KC_EQUAL), KC_EQUAL,      LSFT(KC_2), LSFT(KC_GRAVE), KC_GRAVE,   LSFT(KC_COMMA), LSFT(KC_DOT), XXXXXXX,    _______,
			_______,    _______,       _______,    _______,        _______,       /***/           _______,    _______,    _______,        _______,      _______,    _______
			),


	[L3] = LAYOUT_planck_mit(
			_______, M_F1,    M_F2,    M_F3,      M_F4,     M_F5,        M_F6,        M_F7,         M_F8,          M_F9,         M_F10,       KC_DEL,
			COMPOSE, M_PM,    M_DASH,  M_CDOT,    M_BULLET, M_DEADGREEK, M_TIMES,     M_DEADCIRCUM, M_DEF,         M_DEADDOT,    M_DEADSLASH, KC_INS,
			_______, XXXXXXX, XXXXXXX, M_DEADBAR, M_APPROX, XXXXXXX,     M_DEADTILDE, M_DEADGRAVE,  M_DEADCEDILLA, M_DEADUMLAUT, M_DEADACUTE, _______,
			KC_PSCR, KC_SYRQ, XXXXXXX,       XXXXXXX,   _______,  /***/        _______,   _______,      TG(MOUSE), TG(SPACE_MOUSE),      M_BASETG,    QK_BOOTLOADER
			),

	[MOUSE] = LAYOUT_planck_mit(
			_______, _______,    KC_MS_WH_DOWN, KC_MS_WH_UP, _______,       _______,          _______,   _______,    _______,    _______,  _______,     _______,
			XXXXXXX, KC_MS_BTN4, KC_MS_BTN3,    KC_MS_BTN1,  KC_MS_BTN2,    XXXXXXX,          XXXXXXX,   KC_MS_LEFT, KC_MS_DOWN, KC_MS_UP, KC_MS_RIGHT, XXXXXXX,
			_______, KC_MS_BTN8, KC_MS_BTN7,    KC_MS_BTN6,  KC_MS_BTN5,    XXXXXXX,          XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,  XXXXXXX,     _______,
			_______, _______,    _______,       _______,     KC_LEFT_SHIFT, /***/    _______, XXXXXXX, TG(MOUSE),    _______,    _______,  _______
			),

	[SPACE_MOUSE] = LAYOUT_planck_mit(
			KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,      KC_Y,         KC_U,     KC_I,    KC_O,    KC_P,     KC_BSPC,
			KC_LCTL,  KC_A,    KC_S,    KC_D,    KC_F,  KC_G,      KC_M,         KC_H,     KC_J,    KC_K,    KC_L,     KC_ESC,
			KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,      KC_N,         KC_MINUS, KC_COMM, KC_DOT,  KC_QUOTE, KC_ENT,
			_______, _______,    _______,       KC_MS_BTN2,     KC_MS_BTN1, /***/    KC_SPC, KC_MS_BTN3, _______,    TG(SPACE_MOUSE),    _______,  _______
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
		case M_F10:
			if (record->event.pressed) {
				tapkey_noshift(KC_F10);
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
		case M_DEADDQUOTE:
			if (record->event.pressed) {
				unregister_code(KC_LSFT);
				tapkey(COMPOSE);
				send_string("\"");
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
		case M_DEADDOT:
			if (record->event.pressed) {
				unregister_code(KC_LSFT);
				tapkey(COMPOSE);
				send_string(".");
				register_code(KC_LSFT);
			}
			return false;
			break;
		case M_PM:
			if (record->event.pressed) {
				unregister_code(KC_LSFT);
				tapkey(COMPOSE);
				send_string("+-");
				register_code(KC_LSFT);
			}
			return false;
			break;
		case M_DEF:
			if (record->event.pressed) {
				unregister_code(KC_LSFT);
				tapkey(COMPOSE);
				send_string("=_");
				register_code(KC_LSFT);
			}
			return false;
			break;
		case M_APPROX:
			if (record->event.pressed) {
				unregister_code(KC_LSFT);
				tapkey(COMPOSE);
				send_string("~~");
				register_code(KC_LSFT);
			}
			return false;
			break;
		case M_CDOT:
			if (record->event.pressed) {
				unregister_code(KC_LSFT);
				tapkey(COMPOSE);
				send_string("^.");
				register_code(KC_LSFT);
			}
			return false;
			break;
		case M_BULLET:
			if (record->event.pressed) {
				unregister_code(KC_LSFT);
				tapkey(COMPOSE);
				send_string("o.");
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
		case M_DEADTILDE:
			if (record->event.pressed) {
				unregister_code(KC_LSFT);
				tapkey(COMPOSE);
				send_string("~");
				register_code(KC_LSFT);
			}
			return false;
			break;
		case M_DEADCIRCUM:
			if (record->event.pressed) {
				unregister_code(KC_LSFT);
				tapkey(COMPOSE);
				send_string("^");
				register_code(KC_LSFT);
			}
			return false;
			break;
		case M_DEADCEDILLA:
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
		case M_DEADUNDERLINE:
			if (record->event.pressed) {
				unregister_code(KC_LSFT);
				tapkey(COMPOSE);
				send_string("/");
				register_code(KC_LSFT);
			}
			return false;
			break;
		case M_DEADSLASH:
			if (record->event.pressed) {
				unregister_code(KC_LSFT);
				tapkey(COMPOSE);
				send_string("/");
				register_code(KC_LSFT);
			}
			return false;
			break;
		case M_DEADUMLAUT:
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
		case M_BASETG:
			if (record->event.pressed) {
				default_layer_xor(1|2);
			}
			return false;
			break;
	}
	return true;
}


