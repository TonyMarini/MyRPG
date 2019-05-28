/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** inventory_event
*/

#include "rpg.h"
#include "gameloop.h"
#include "tool.h"
#include "main_menu.h"

static int key_press(sfKeyEvent key, window_t *win, gameloop_data_t *data)
{
    (void)data;
    (void)win;
    if (key.code == sfKeyEscape || key.code == data->option->key.inventory)
            return (1);
    return (SUCCESS);
}

static int inventory_evt(window_t *win, gameloop_data_t *data, sfEvent event)
{
    switch (event.type) {
    case sfEvtClosed:
        sfRenderWindow_close(win->win);
        return (SUCCESS);
    case sfEvtKeyPressed:
        return (key_press(event.key, win, data));
    case sfEvtMouseButtonPressed:
        return (start_drag_item(event.mouseButton, win, data));
    case sfEvtMouseMoved:
        return (move_drag_item(event.mouseMove, data));
    case sfEvtMouseButtonReleased:
        return (end_drag_item(event.mouseButton, win, data));
    default:
        break;
    }
    return (SUCCESS);
}

int inventory_event(window_t *win, gameloop_data_t *data)
{
    sfEvent event;
    int status = 0;

    while (sfRenderWindow_pollEvent(win->win, &event)) {
        status = inventory_evt(win, data, event);
        if (status != SUCCESS)
            return (ERROR);
    }
    return (SUCCESS);
}