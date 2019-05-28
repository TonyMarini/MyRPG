/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** key_press_event
*/

#include <stdio.h>
#include "option.h"
#include "tool.h"

static void change_key(sfKeyEvent key, control_menu_t *d)
{
    const char *name = KEY_NAME[d->key_code[d->wait_event]];

    for (int i = 0 ; i < NB_CONTROL ; i++) {
        if (key.code == d->key_code[i]) {
            change_button_txt(&d->button[d->wait_event], name);
            d->wait_event = -1;
            return;
        }
    }
    change_button_txt(&(d->button[d->wait_event]), KEY_NAME[key.code]);
    d->key_code[d->wait_event] = key.code;
    d->wait_event = -1;
}

int keymap_event(sfKeyEvent key, control_menu_t *d)
{
    const char *name = KEY_NAME[d->key_code[d->wait_event]];

    if (key.code == sfKeyEscape && d->wait_event < 0)
        return (ERROR);
    else if (key.code == sfKeyEscape && d->wait_event >= 0) {
        change_button_txt(&d->button[d->wait_event], name);
        d->wait_event = -1;
    }
    if (key.code < 0) {
        mputerror("Error : Unknow key\n");
        return (SUCCESS);
    }
    if (d->wait_event >= 0) {
        change_key(key, d);
    }
    return (SUCCESS);
}