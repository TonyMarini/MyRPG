/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init
*/

#ifndef INIT_H_
#define INIT_H_

#include "rpg.h"

int init_window(window_t *window, int win_w, int win_h, int fullscreen);

//init key
int load_option_from_file(option_t *option);
int init_game_setting(option_t *option, window_t *win);
int load_key_from_file(option_t *option);

#endif /* !INIT_H_ */
