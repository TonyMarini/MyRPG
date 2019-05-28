/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** option
*/

#ifndef OPTION_H_
#define OPTION_H_

#include "rpg.h"
#include "music.h"

static const int NB_CONTROL = 12;
static const char CONTROL_NAME[13][15] = {"Left", "Right", "Up",
"Down", "Action", "Inventory", "Spell 1", "Spell 2", "Spell 3", "Spell 4",
"Spell 5", "Spell 6"};
static const char KEY_NAME[101][10] = {"A", "B", "C", "D", "E", "F", "G", "H",
"I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W",
"X", "Y", "Z", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "Esp",
"L ctrl", "L shift", "L alt", "L sys", "R ctrl", "R shift", "R alt", "R sys",
"Menu", "[", "]", ";", ",", ".", "'", "/", "\\", "~", "=", "-", "Space",
"Return", "Backspace", "Tab", "Page up", "Page down", "End", "Home", "Insert",
"Delete", "Add", "Sustract", "Multiply", "Divide", "Left", "Right", "Up",
"Down", "num 0", "num 1", "num 2", "num 3", "num 4", "num 5", "num 6",
"num 7", "num 8", "num 9", "F 1", "F 2", "F 3", "F 4", "F 5", "F 6", "F 7",
"F 8", "F 9", "F 10", "F 11", "F 12", "F 13", "F 14", "F 15", "Pause"};

typedef struct option_menu_s {
    button_t back_button;
    button_t save_button;
    button_t control_button;
    button_t size_button[6];
    sfSprite *selector[6];
    checkbox_t fscreen_box;
    slider_t sound_slider;
    slider_t music_slider;
    checkbox_t mute_sound;
    checkbox_t mute_music;
    resource_t *resource;
    option_t *option;
    option_t save_option;
    sfSprite *bg_sprite;
    int mouse_press;
    sfText *text_music;
    sfText *text_sound;
    music_data_t *music;
} option_menu_t;

typedef struct control_menu_s {
    button_t back_button;
    button_t save_button;
    sfText *label[12];
    button_t button[12];
    sfKeyCode key_code[12];
    option_t *option;
    int wait_event;
} control_menu_t;

int option_menu(window_t *window, resource_t *resource, option_t *option);
int option_menu_event(window_t *win, option_menu_t *menu_data);
int init_option(option_menu_t *menu, resource_t *resource, window_t win);

//Event
int size_button_event(window_t *w, sfVector2i pos, option_menu_t *menu, int s);
int sound_button_event(window_t *win, option_menu_t *d, sfVector2i pos, int s);

int change_window_size(window_t *w, option_t *option, int new_size, int full);
int save_option(option_menu_t *data);
int restore_option(window_t *win, option_menu_t *data);

//Control menu
int control_menu(window_t *win, resource_t *resource, option_t *option);
int init_control_m(control_menu_t *d, window_t w, resource_t *r, option_t op);
int control_menu_event(window_t *win, control_menu_t *menu_data);
int change_key_button(window_t w, control_menu_t *menu, int s, sfVector2i pos);
int keymap_event(sfKeyEvent key, control_menu_t *d);
int save_key(control_menu_t *menu);

#endif /* !OPTION_H_ */
