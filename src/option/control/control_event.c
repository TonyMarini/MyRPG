/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** control_event
*/

#include <stdio.h>
#include "rpg.h"
#include "tool.h"
#include "option.h"

static int mouse_click(window_t *win, sfVector2i pos, control_menu_t *d, int s)
{
    const char *name = KEY_NAME[d->key_code[d->wait_event]];

    if (d->wait_event >= 0) {
        change_button_txt(&(d->button[d->wait_event]), name);
        d->wait_event = -1;
    }
    change_key_button(*win, d, s, pos);
    if (button_is_click(*win, &(d->back_button), pos) && s == 1)
        return (ERROR);
    if (button_is_click(*win, &(d->save_button), pos) && s == 1) {
        save_key(d);
        return (ERROR);
    }
    return (SUCCESS);
}

static int switch_event(sfEvent event, window_t *win, control_menu_t *menu)
{
    sfVector2i pos;

    switch (event.type) {
    case sfEvtClosed:
        sfRenderWindow_close(win->win);
        return (SUCCESS);
    case sfEvtMouseButtonPressed:
        pos = ini_vectori(event.mouseButton.x, event.mouseButton.y);
        return (mouse_click(win, pos, menu, 0));
    case sfEvtMouseButtonReleased:
        pos = ini_vectori(event.mouseButton.x, event.mouseButton.y);
        return (mouse_click(win, pos, menu, 1));
    case sfEvtKeyPressed:
        return (keymap_event(event.key, menu));
    default:
        return (SUCCESS);
    }
}

int control_menu_event(window_t *win, control_menu_t *menu_data)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(win->win, &event)) {
        if (switch_event(event, win, menu_data) == ERROR)
            return (ERROR);
    }
    return (SUCCESS);
}