#include "tada68.h"
#include "led.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BL 0
#define _FL 1

#define _______ KC_TRNS
#define ISO_SHF RSFT_T(KC_NUBS)

#define NUM_UC_MODES 5

#define UCIHID_START 0x8000
#define UCIHID(endpoint) ( UCIHID_START | (endpoint) )

enum unicode_codes {
	poop,
	rofl,
	kiss,
	mouse,
	snowman,
	coffee,
	heart,
	wait,
	ex,
	v,
	x,
	rain,
	listen,
	rip
};

uint32_t unicodes[] = {
	[poop] = 0x1f4a9,
	[rofl] = 0x1f923,
	[kiss] = 0x1f619,
	[mouse] = 0x1f401,
	[snowman] = 0x2603,
	[coffee] = 0x2615,
	[heart] = 0x2764,
	[wait] = 0x23f3,
	[ex] = 0x2757,
	[v] = 0x2713,
	[x] = 0x2717,
	[rain] = 0x2614,
	[listen] = 0x261d,
	[rip] = 0x2620
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: (Base Layer) Default Layer
   * ,----------------------------------------------------------------.
   * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |Home|
   * |----------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |End |
   * |----------------------------------------------------------------|
   * |FN     |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |PgUp|
   * |----------------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|PgDn|
   * |----------------------------------------------------------------|
   * |Ctrl|Win |Alt |        Space          |Alt|Win|Ctrl|Lef|Dow|Rig |
   * `----------------------------------------------------------------'
   */
[_BL] = KEYMAP_ANSI(
// ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬──────────────┬───────┐
     KC_ESC,  KC_1 ,  KC_2 ,  KC_3 ,  KC_4 ,  KC_5 ,  KC_6 ,  KC_7 ,  KC_8 ,  KC_9 ,  KC_0 ,KC_MINS, KC_EQL,    KC_BSPC   ,KC_HOME, \
// ├───────┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬──────────┼───────┤
       KC_TAB  ,  KC_Q ,  KC_W ,  KC_E ,  KC_R ,  KC_T ,  KC_Y ,  KC_U ,  KC_I ,  KC_O ,  KC_P ,KC_LBRC,KC_RBRC,  KC_BSLS , KC_END, \
// ├───────────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴──────────┼───────┤
         M(0)    ,  KC_A ,  KC_S ,  KC_D ,  KC_F ,  KC_G ,  KC_H ,  KC_J ,  KC_K ,  KC_L ,KC_SCLN,KC_QUOT,     KC_ENT     ,KC_PGUP, \
// ├─────────────┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴────────┬───────┼───────┤
         KC_LSFT     ,  KC_Z ,  KC_X ,  KC_C ,  KC_V ,  KC_B ,  KC_N ,  KC_M ,KC_COMM, KC_DOT,KC_SLSH,   ISO_SHF  , KC_UP ,KC_PGDN, \
// ├───────┬───────┬─┴─────┬─┴───────┴───────┴───────┴───────┴───────┴───────┴────┬──┴────┬──┴────┬──┴────┬───────┼───────┼───────┤
    KC_LCTL,KC_LGUI,KC_LALT,                        KC_SPC                        ,KC_RALT,KC_RGUI,KC_RCTL,KC_LEFT,KC_DOWN,KC_RGHT  \
// └───────┴───────┴───────┴──────────────────────────────────────────────────────┴───────┴───────┴───────┴───────┴───────┴───────┘
),

  /* Keymap _FL: Function Layer
   * ,----------------------------------------------------------------.
   * |`~ | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|Del    |Calc|
   * |----------------------------------------------------------------|
   * |     |   |   |   |   |   |   |   |   |   |PSc|   |   |     |    |
   * |----------------------------------------------------------------|
   * |      |   |   |   |   |   |   |       |   |   |   |        |    |
   * |----------------------------------------------------------------|
   * |        |BL-| BL|BL+|   |   |   |   |VL-|MUT|VL+|      |STP|    |
   * |----------------------------------------------------------------|
   * |    |    |    |                       |   |   |    |PRV|PLY|NXT |
   * `----------------------------------------------------------------'
   */
[_FL] = KEYMAP_ANSI(
   KC_GRV,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL,KC_CALC, \
  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,KC_PSCR,_______,_______,_______,_______, \
  _______,_______,_______,_______,UCIHID(poop),_______,_______,_______,_______,_______,_______,_______,        _______,_______, \
          _______, BL_DEC,BL_TOGG, BL_INC,_______,_______,_______,_______,KC_VOLD,KC_MUTE,KC_VOLU,_______,KC_MSTP,_______, \
  _______,_______,_______,                _______,                        _______,_______,_______,KC_MPRV,KC_MPLY,KC_MNXT  \
),
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
	switch(id) {
		case 0: // this triggers when you hit a key mapped as M(0)
			if (record->event.pressed) { // on keydown
				// Turn capslock LED on
				PORTB &= ~(1<<2);

				// Enabld FN layer
				layer_on(_FL);
			} else { // on keyup
				// Turn capslock LED off
				PORTB |= (1<<2);

				// Disable FN layer
				layer_off(_FL);
			}
		break;
	}
	return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	// xprintf("c=%02d,r=%02d,k=%05d,p=%1d,l=%010d|", record->event.key.col, record->event.key.row, keycode, record->event.pressed, layer_state);
	xprintf("c=%02d,r=%02d,k=%" PRIu16 ",p=%1d,l=%010d|", record->event.key.col, record->event.key.row, keycode, record->event.pressed, layer_state);

	if (record->event.pressed && keycode >= UCIHID_START) {
		uint32_t ucode = unicodes[keycode & ~(UCIHID_START)];
		xprintf("u=0x%08lX|", ucode);

		return false;
	}

	return true;
};
