/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** gameloop_event
*/

#include "rpg.h"
#include "gameloop.h"
#include "tool.h"
#include "main_menu.h"

static int key_pressed_evt(sfKeyEvent key, window_t *w, gameloop_data_t *data)
{
    if (key.code == sfKeyEscape)
            return (in_game_menu(w, data));
    if (key.code == data->option->key.inventory)
        return (inventory(w, data));
    if (key.code == data->option->key.action)
        get_loot(data);
    return (SUCCESS);
}

static int event_switch(sfEvent event, window_t *w, gameloop_data_t *game_data)
{
    switch (event.type) {
    case sfEvtClosed:
        sfRenderWindow_close(w->win);
        return (ERROR);
    case sfEvtKeyPressed:
        return (key_pressed_evt(event.key, w, game_data));
    default:
        break;
    }
    return (SUCCESS);
}

int manage_event(window_t *window, gameloop_data_t *game_data)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window->win, &event)) {
        if (event_switch(event, window, game_data) == ERROR)
            return (ERROR);
    }
    return (SUCCESS);
}