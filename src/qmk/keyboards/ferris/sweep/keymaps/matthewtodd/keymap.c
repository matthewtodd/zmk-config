#include QMK_KEYBOARD_H

enum layer_names {
    FOCAL,
    NAV,
    MOUSE,
    MEDIA,
    NUM,
    SYM,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [FOCAL] = LAYOUT_split_3x5_2(
        KC_V, KC_L, KC_H, KC_G, KC_K, KC_Q, KC_F, KC_O, KC_U, KC_J,
        LCTL_T(KC_S), LALT_T(KC_R), LGUI_T(KC_N), LSFT_T(KC_T), KC_B, KC_Y, RSFT_T(KC_C), RGUI_T(KC_A), RALT_T(KC_E), RCTL_T(KC_I),
        KC_Z, KC_X, KC_M, KC_D, KC_P, KC_QUOT, KC_W, KC_COMM, KC_DOT, KC_SLSH,
        LT(NAV, KC_SPC), KC_TAB, LT(SYM, KC_ENT), LT(NUM, KC_BSPC)),
    [NAV] = LAYOUT_split_3x5_2(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, XXXXXXX, CW_TOGG, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX),
    [MOUSE] = LAYOUT_split_3x5_2(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, XXXXXXX, XXXXXXX, MS_LEFT, MS_DOWN, MS_UP, MS_RGHT,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MS_WHLR, MS_WHLU, MS_WHLD, MS_WHLL,
        XXXXXXX, XXXXXXX, MS_BTN2, MS_BTN1),
    [MEDIA] = LAYOUT_split_3x5_2(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BRMD, KC_BRMU, XXXXXXX,
        KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, XXXXXXX, XXXXXXX, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_MUTE, KC_MPLY),
    [NUM] = LAYOUT_split_3x5_2(
        KC_LBRC, KC_7, KC_8, KC_9, KC_RBRC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_SCLN, KC_4, KC_5, KC_6, KC_EQL, XXXXXXX, KC_RSFT, KC_RGUI, KC_RALT, KC_RCTL,
        KC_GRV, KC_1, KC_2, KC_3, KC_BSLS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_0, KC_MINS, XXXXXXX, XXXXXXX),
    [SYM] = LAYOUT_split_3x5_2(
        KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_COLN, KC_DLR, KC_PERC, KC_CIRC, KC_PLUS, XXXXXXX, KC_RSFT, KC_RGUI, KC_RALT, KC_RCTL,
        KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_PIPE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_RPRN, KC_UNDS, XXXXXXX, XXXXXXX)};

// https://docs.qmk.fm/tap_hold#chordal-hold-handedness
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT_split_3x5_2(
    'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'R', 'R');

// https://docs.qmk.fm/features/tap_dance#example-5
enum td_keycodes {
    RSFT_RGUI_LPRN,
    RGUI_RALT_RPRN
};

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_TAP_SHIFTED,
    TD_SINGLE_HOLD,
} td_state_t;

static td_state_t td_state;

td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed)
            if (get_mods() & MOD_MASK_SHIFT)
                return TD_SINGLE_TAP_SHIFTED;
            else
                return TD_SINGLE_TAP;
        else
            return TD_SINGLE_HOLD;
    } else
        return TD_UNKNOWN;
}

void rsft_rgui_lprn_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
            register_code16(KC_LPRN);
            break;
        case TD_SINGLE_TAP_SHIFTED:
            register_code16(KC_LT);
            break;
        case TD_SINGLE_HOLD:
            register_mods(MOD_BIT(KC_RSFT) | MOD_BIT(KC_RGUI));
            break;
        default:
            break;
    }
}

void rsft_rgui_lprn_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP:
            unregister_code16(KC_LPRN);
            break;
        case TD_SINGLE_TAP_SHIFTED:
            unregister_code16(KC_LT);
            break;
        case TD_SINGLE_HOLD:
            unregister_mods(MOD_BIT(KC_RSFT) | MOD_BIT(KC_RGUI));
            break;
        default:
            break;
    }
}

void rgui_ralt_rprn_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
            register_code16(KC_RPRN);
            break;
        case TD_SINGLE_TAP_SHIFTED:
            register_code16(KC_GT);
            break;
        case TD_SINGLE_HOLD:
            register_mods(MOD_BIT(KC_RGUI) | MOD_BIT(KC_RALT));
            break;
        default:
            break;
    }
}

void rgui_ralt_rprn_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP:
            unregister_code16(KC_RPRN);
            break;
        case TD_SINGLE_TAP_SHIFTED:
            unregister_code16(KC_GT);
            break;
        case TD_SINGLE_HOLD:
            unregister_mods(MOD_BIT(KC_RGUI) | MOD_BIT(KC_RALT));
            break;
        default:
            break;
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [RSFT_RGUI_LPRN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, rsft_rgui_lprn_finished, rsft_rgui_lprn_reset),
    [RGUI_RALT_RPRN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, rgui_ralt_rprn_finished, rgui_ralt_rprn_reset),
};

enum combos {
    LH_MOUSE,
    HG_MEDIA,
    NT_ESC,
    XM_COPY,
    MD_PASTE,

    FO_BSPC,
    OU_DEL,
    CA_LPRN,
    AE_RPRN,
    WC_LBRC,
    CD_RBRC,
};

const uint16_t PROGMEM mouse_combo[] = {KC_L, KC_H, COMBO_END};
const uint16_t PROGMEM media_combo[] = {KC_H, KC_G, COMBO_END};
const uint16_t PROGMEM esc_combo[]   = {LGUI_T(KC_N), LSFT_T(KC_T), COMBO_END};
const uint16_t PROGMEM copy_combo[]  = {KC_X, KC_M, COMBO_END};
const uint16_t PROGMEM paste_combo[] = {KC_M, KC_D, COMBO_END};

const uint16_t PROGMEM bspc_combo[] = {KC_F, KC_O, COMBO_END};
const uint16_t PROGMEM del_combo[]  = {KC_O, KC_U, COMBO_END};
const uint16_t PROGMEM lprn_combo[] = {RSFT_T(KC_C), RGUI_T(KC_A), COMBO_END};
const uint16_t PROGMEM rprn_combo[] = {RGUI_T(KC_A), RALT_T(KC_E), COMBO_END};
const uint16_t PROGMEM lbrc_combo[] = {KC_W, KC_COMM, COMBO_END};
const uint16_t PROGMEM rbrc_combo[] = {KC_COMM, KC_DOT, COMBO_END};

combo_t key_combos[] = {
    [LH_MOUSE] = COMBO(mouse_combo, MO(MOUSE)),
    [HG_MEDIA] = COMBO(media_combo, MO(MEDIA)),
    [NT_ESC]   = COMBO(esc_combo, LSG_T(KC_ESC)),
    [XM_COPY]  = COMBO(copy_combo, LGUI(KC_C)),
    [MD_PASTE] = COMBO(paste_combo, LGUI(KC_V)),

    [FO_BSPC] = COMBO(bspc_combo, KC_BSPC),
    [OU_DEL]  = COMBO(del_combo, KC_DEL),
    [CA_LPRN] = COMBO(lprn_combo, TD(RSFT_RGUI_LPRN)),
    [AE_RPRN] = COMBO(rprn_combo, TD(RGUI_RALT_RPRN)),
    [WC_LBRC] = COMBO(lbrc_combo, KC_LBRC),
    [CD_RBRC] = COMBO(rbrc_combo, KC_RBRC),
};

#ifdef COMBO_MUST_TAP_PER_COMBO
bool get_combo_must_tap(uint16_t combo_index, combo_t *combo) {
    switch (combo_index) {
        case CA_LPRN:
            return true;
        case AE_RPRN:
            return true;
    }

    return false;
}
#endif
