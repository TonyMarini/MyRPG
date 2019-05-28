/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** option_menu_event
*/

#include <stdio.h>
#include "rpg.h"
#include "tool.h"
#include "option.h"

static int mouse_click(window_t *win, sfVector2i pos, option_menu_t *d, int s)
{
    d->mouse_press = !d->mouse_press;
    if (button_is_click(*win, &(d->back_button), pos) && s == 1) {
        restore_option(win, d);
        return (ERROR);
    }
    if (button_is_click(*win, &(d->control_button), pos) && s == 1)
        control_menu(win, d->resource, d->option);
    if (button_is_click(*win, &(d->save_button), pos) && s == 1) {
        save_option(d);
        return (ERROR);
    }
    size_button_event(win, pos, d, s);
    sound_button_event(win, d, pos, s);
    return (SUCCESS);
}

static int mouse_moved(window_t *win, option_menu_t *menu_data)
{
    if (menu_data->mouse_press) {
        move_slider(*win, &(menu_data->sound_slider));
        menu_data->option->sound_lvl = menu_data->sound_slider.value * 10;
        move_slider(*win, &(menu_data->music_slider));
        menu_data->option->music_lvl = menu_data->music_slider.value * 10;
    }
    return (SUCCESS);
}

static int switch_event(sfEvent event, window_t *win, option_menu_t *menu_data)
{
    sfVector2i pos;

    switch (event.type) {
    case sfEvtClosed:
        sfRenderWindow_close(win->win);
        return (SUCCESS);
    case sfEvtMouseButtonPressed:
        pos = ini_vectori(event.mouseButton.x, event.mouseButton.y);
        return (mouse_click(win, pos, menu_data, 0));
    case sfEvtMouseButtonReleased:
        pos = ini_vectori(event.mouseButton.x, event.mouseButton.y);
        return (mouse_click(win, pos, menu_data, 1));
    case sfEvtMouseMoved:
        return (mouse_moved(win, menu_data));
    case sfEvtKeyPressed:
        if (event.key.code == sfKeyEscape)
            return (ERROR);
        return (SUCCESS);
    default:
        return (SUCCESS);
    }
}

int option_menu_event(window_t *win, option_menu_t *menu_data)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(win->win, &event)) {
        if (switch_event(event, win, menu_data) == ERROR)
            return (ERROR);
    }
    return (SUCCESS);
}
