#include QMK_KEYBOARD_H

#define COMPOSE KC_APP

#define tapkey(kk) {\
	register_code(kk);\
	unregister_code(kk);\
}

enum planck_layers {
	BASE,
	SHIFT,
	SYMBOL,
	MACRO,
	MOUSE,
};

enum custom_keycodes {
	M_DEADACUTE = SAFE_RANGE,
	M_GRAVE,
	M_DEADGRAVE,
	M_CIRCUM,
	M_TILDE,
	M_CEDILLA,
	M_SCOLON,
	M_UMLAUT,
	M_COMPOSE,
	M_GLEFT,
	M_GRIGHT,
	M_DEGREE,
	M_MASC,
	M_FEMI,
	M_DQUOTELEFT,
	M_DQUOTERIGHT,
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

	[BASE] = LAYOUT_planck_mit(
			KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,      KC_Y,          KC_U,       KC_I,    KC_O,      KC_P,     KC_BSPC,
			KC_SLASH, KC_A,    KC_S,    KC_D,    KC_F,     KC_G,      KC_M,          KC_H,       KC_J,    KC_K,      KC_L,     KC_BSLASH,
			KC_ESC,   KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,      KC_N,          KC_MINUS,   KC_COMM, KC_DOT,    KC_QUOTE, KC_ENT,
			KC_LEFT,  KC_DOWN, KC_LALT, KC_LCTL, LM(SHIFT, MOD_LSFT), /***/  KC_SPC, MO(SYMBOL), KC_LGUI, TG(MOUSE), KC_UP,    KC_RGHT
			),


	[SHIFT] = LAYOUT_planck_mit(
			_______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,   _______, _______,
			_______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,   _______, KC_1,
			_______, _______, _______, _______, _______, _______, _______, _______, M_SCOLON, KC_SCOLON, M_GRAVE, _______,
			_______, _______, _______, _______, _______, /***/    _______, _______, _______,  _______,   _______, _______
			),


	[SYMBOL] = LAYOUT_planck_mit(
			_______, KC_1,          KC_2,       KC_3,           KC_4,          KC_5,       KC_6,           KC_7,       KC_8,           KC_9,         KC_0,           _______,
			_______, LSFT(KC_LBRC), LSFT(KC_9), LSFT(KC_0),     LSFT(KC_RBRC), LSFT(KC_3), LSFT(KC_5),     LSFT(KC_6), KC_LBRC,        KC_RBRC,      LSFT(KC_4),     LSFT(KC_BSLASH),
			_______, LSFT(KC_7),    LSFT(KC_8), LSFT(KC_EQUAL), KC_EQUAL,      LSFT(KC_2), LSFT(KC_GRAVE), _______,    LSFT(KC_COMMA), LSFT(KC_DOT), LSFT(KC_QUOTE), _______,
			_______, _______,       _______,    _______,        _______,       /***/       _______,        _______,    _______,        _______,      _______,        _______
			),


	[MACRO] = LAYOUT_planck_mit(
			M_F12,     M_F1,      M_F2,        M_F3,     M_F4,        M_F5,     M_F6,    M_F7,     M_F8,         M_F9,          M_F10,   M_F11,
			M_COMPOSE, M_CEDILLA, M_DEADGRAVE, M_UMLAUT, M_DEADACUTE, M_FEMI,   M_MASC,  M_CIRCUM, M_DQUOTELEFT, M_DQUOTERIGHT, M_TILDE, KC_INS,
			_______,   _______,   _______,     _______,  _______,     M_DEGREE, _______, _______,  M_GLEFT,      M_GRIGHT,      _______, _______,
			XXXXXXX,   XXXXXXX,   XXXXXXX,     XXXXXXX,  _______,     /***/     _______, XXXXXXX,  XXXXXXX,      _______,       _______, RESET
			),


	[MOUSE] = LAYOUT_planck_mit(
			_______, _______, KC_MS_WH_DOWN, KC_MS_WH_UP, _______,    _______, _______, _______,      _______,      _______,      _______,     _______,
			_______, _______, KC_MS_BTN3,    KC_MS_BTN1,  KC_MS_BTN2, _______, _______, KC_MS_LEFT,   KC_MS_DOWN,   KC_MS_UP,     KC_MS_RIGHT, _______,
			_______, _______, KC_MS_BTN5,    KC_MS_BTN4,  _______,    _______, _______, KC_MS_ACCEL0, KC_MS_ACCEL1, KC_MS_ACCEL2, _______,     _______,
			_______, _______, _______,       _______,     _______,    /***/    _______, _______, _______,      _______,      _______,      _______
			),



};

uint32_t layer_state_set_user(uint32_t state) {
	state = update_tri_layer_state(state, SHIFT, SYMBOL, MACRO);
	return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case M_F1:
			if (record->event.pressed) {
				unregister_code(KC_LSFT);
				tapkey(KC_F1);
				register_code(KC_LSFT);
			}
			return false;
			break;
		case M_F2:
			if (record->event.pressed) {
				unregister_code(KC_LSFT);
				tapkey(KC_F2);
				register_code(KC_LSFT);
			}
			return false;
			break;
		case M_F3:
			if (record->event.pressed) {
				unregister_code(KC_LSFT);
				tapkey(KC_F3);
				register_code(KC_LSFT);
			}
			return false;
			break;
		case M_F4:
			if (record->event.pressed) {
				unregister_code(KC_LSFT);
				tapkey(KC_F4);
				register_code(KC_LSFT);
			}
			return false;
			break;
		case M_F5:
			if (record->event.pressed) {
				unregister_code(KC_LSFT);
				tapkey(KC_F5);
				register_code(KC_LSFT);
			}
			return false;
			break;
		case M_F6:
			if (record->event.pressed) {
				unregister_code(KC_LSFT);
				tapkey(KC_F6);
				register_code(KC_LSFT);
			}
			return false;
			break;
		case M_F7:
			if (record->event.pressed) {
				unregister_code(KC_LSFT);
				tapkey(KC_F7);
				register_code(KC_LSFT);
			}
			return false;
			break;
		case M_F8:
			if (record->event.pressed) {
				unregister_code(KC_LSFT);
				tapkey(KC_F8);
				register_code(KC_LSFT);
			}
			return false;
			break;
		case M_F9:
			if (record->event.pressed) {
				unregister_code(KC_LSFT);
				tapkey(KC_F9);
				register_code(KC_LSFT);
			}
			return false;
			break;
		case M_F10:
			if (record->event.pressed) {
				unregister_code(KC_LSFT);
				tapkey(KC_F10);
				register_code(KC_LSFT);
			}
			return false;
			break;
		case M_F11:
			if (record->event.pressed) {
				unregister_code(KC_LSFT);
				tapkey(KC_F11);
				register_code(KC_LSFT);
			}
			return false;
			break;
		case M_F12:
			if (record->event.pressed) {
				unregister_code(KC_LSFT);
				tapkey(KC_F12);
				register_code(KC_LSFT);
			}
			return false;
			break;
		case M_COMPOSE:
			if (record->event.pressed) {
				unregister_code(KC_LSFT);
				tapkey(COMPOSE);
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
		case M_GRAVE:
			if (record->event.pressed) {
				unregister_code(KC_LSFT);
				send_string("`");
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
		case M_GLEFT:
			if (record->event.pressed) {
				unregister_code(KC_LSFT);
				tapkey(COMPOSE);
				send_string("<<");
				register_code(KC_LSFT);
			}
			return false;
			break;
		case M_GRIGHT:
			if (record->event.pressed) {
				unregister_code(KC_LSFT);
				tapkey(COMPOSE);
				send_string(">>");
				register_code(KC_LSFT);
			}
			return false;
			break;
		case M_DEGREE:
			if (record->event.pressed) {
				unregister_code(KC_LSFT);
				tapkey(COMPOSE);
				send_string("oo");
				register_code(KC_LSFT);
			}
			return false;
			break;
		case M_MASC:
			if (record->event.pressed) {
				unregister_code(KC_LSFT);
				tapkey(COMPOSE);
				send_string("^_o");
				register_code(KC_LSFT);
			}
			return false;
			break;
		case M_FEMI:
			if (record->event.pressed) {
				unregister_code(KC_LSFT);
				tapkey(COMPOSE);
				send_string("^_a");
				register_code(KC_LSFT);
			}
			return false;
			break;
		case M_DQUOTELEFT:
			if (record->event.pressed) {
				unregister_code(KC_LSFT);
				tapkey(COMPOSE);
				send_string("<\"");
				register_code(KC_LSFT);
			}
			return false;
			break;
		case M_DQUOTERIGHT:
			if (record->event.pressed) {
				unregister_code(KC_LSFT);
				tapkey(COMPOSE);
				send_string(">\"");
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
	}
	return true;
}

