/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_setting
*/

#include "rpg.h"
#include "init.h"
#include "tool.h"
#include "option.h"

static void load_default_key(option_t *option)
{
    option->key.up = sfKeyUp;
    option->key.down = sfKeyDown;
    option->key.right = sfKeyRight;
    option->key.left = sfKeyLeft;
    option->key.spell1 = sfKeyR;
    option->key.spell2 = sfKeyT;
    option->key.spell3 = sfKeyY;
    option->key.spell4 = sfKeyU;
    option->key.spell5 = sfKeyI;
    option->key.spell6 = sfKeyO;
    option->key.inventory = sfKeyE;
    option->key.action = sfKeySpace;
}

static void load_default_setting(option_t *option)
{
    option->select_size = 1;
    option->fullscreen = 1;
    option->sound_lvl = 80;
    option->sound_mute = 0;
    option->music_lvl = 80;
    option->music_mute = 0;
}

static void check_option(option_t *option)
{
    if (option->select_size == -1 || option->fullscreen == -1
    || option->sound_lvl == -1 || option->sound_mute == -1
    || option->music_lvl == -1 || option->music_mute == -1) {
        mputerror("Erro : file can't be load\n");
        load_default_setting(option);
    }
    if (option->key.left == -1 || option->key.right == -1
    || option->key.up == -1 || option->key.down == -1
    || option->key.action == -1 || option->key.inventory == -1
    || option->key.spell1 == -1 || option->key.spell2 == -1
    || option->key.spell3 == -1 || option->key.spell4 == -1
    || option->key.spell5 == -1 || option->key.spell6 == -1) {
        mputerror("Erro : file can't be load\n");
        load_default_key(option);
    }
}

int init_game_setting(option_t *option, window_t *win)
{
    option_t temp;

    option->window_h = 1080;
    option->window_w = 1920;
    load_default_setting(&temp);
    if (load_option_from_file(option) == ERROR) {
        mputerror("Error : option file can't be load, load default option\n");
        load_default_setting(option);
    }
    change_window_size(win, &temp, option->select_size, option->fullscreen);
    if (load_key_from_file(option) == ERROR) {
        mputerror("Error : key can't be load, load default key\n");
        load_default_key(option);
    }
    check_option(option);
    return (SUCCESS);
}