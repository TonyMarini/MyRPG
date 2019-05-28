/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** start_menu_event
*/

#include <stdio.h>
#include "rpg.h"
#include "main_menu.h"
#include "tool.h"
#include "option.h"

static int mouse_clik(window_t *win, sfVector2i pos, start_menu_t *menu, int s)
{
    char name[8] = "\0";

    if (button_is_click(*win, &(menu->play_button), pos) && s == 1) {
        if (enter_name(win, name, menu) == ERROR)
            return (SUCCESS);
        gameloop(win, menu->resource, menu->option, name);
    }
    if (button_is_click(*win, &(menu->how_play_button), pos) && s == 1)
        how_to_play(win, menu);
    if (button_is_click(*win, &(menu->option_button), pos) && s == 1)
        option_menu(win, menu->resource, menu->option);
    if (button_is_click(*win, &(menu->quit_button), pos) && s == 1)
        sfRenderWindow_close(win->win);
    return (SUCCESS);
}

static int switch_event(sfEvent event, window_t *win, start_menu_t *menu_data)
{
    sfVector2i pos;

    switch (event.type) {
    case sfEvtClosed:
        sfRenderWindow_close(win->win);
        return (SUCCESS);
    case sfEvtMouseButtonPressed:
        pos = ini_vectori(event.mouseButton.x, event.mouseButton.y);
        return (mouse_clik(win, pos, menu_data, 0));
    case sfEvtMouseButtonReleased:
        pos = ini_vectori(event.mouseButton.x, event.mouseButton.y);
        return (mouse_clik(win, pos, menu_data, 1));
    case sfEvtKeyPressed:
        if (event.key.code == sfKeyEscape)
            sfRenderWindow_close(win->win);
        return (SUCCESS);
    default:
        break;
    }
    return (SUCCESS);
}

int start_menu_event(window_t *win, start_menu_t *menu_data)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(win->win, &event)) {
        switch_event(event, win, menu_data);
    }
    return (SUCCESS);
}
