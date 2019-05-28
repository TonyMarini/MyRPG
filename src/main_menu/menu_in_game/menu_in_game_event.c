/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** menu_in_game_event
*/

#include "rpg.h"
#include "gameloop.h"
#include "tool.h"
#include "option.h"
#include "main_menu.h"

static int mouse_clik_press(window_t *win, in_game_menu_t *menu,
        sfEvent event)
{
    sfVector2i pos = ini_vectori(event.mouseButton.x, event.mouseButton.y);

    if (button_is_click(*win, &(menu->resume_button), pos))
        return (SUCCESS);
    if (button_is_click(*win, &(menu->option_button), pos))
        return (SUCCESS);
    if (button_is_click(*win, &(menu->quit_button), pos))
        return (SUCCESS);
    return (SUCCESS);
}

static int mouse_clik_real(window_t *win, in_game_menu_t *menu,
        gameloop_data_t *data, sfEvent event)
{
    sfVector2i pos = ini_vectori(event.mouseButton.x, event.mouseButton.y);

    if (button_is_click(*win, &(menu->resume_button), pos))
        return (1);
    if (button_is_click(*win, &(menu->option_button), pos))
        option_menu(win, data->resource, data->option);
    if (button_is_click(*win, &(menu->quit_button), pos))
        return (2);
    return (SUCCESS);
}

int in_game_menu_event_switch(window_t *win, gameloop_data_t *data,
        sfEvent event, in_game_menu_t *menu)
{
    switch (event.type) {
    case sfEvtClosed:
        sfRenderWindow_close(win->win);
        return (SUCCESS);
    case sfEvtMouseButtonPressed:
        return (mouse_clik_press(win, menu, event));
    case sfEvtMouseButtonReleased:
        return (mouse_clik_real(win, menu, data, event));
    case sfEvtKeyPressed:
        if (event.key.code == sfKeyEscape)
            return (1);
    default:
        break;
    }
    return (SUCCESS);
}

int in_game_menu_event(window_t *w, gameloop_data_t *data, in_game_menu_t *m)
{
    sfEvent event;
    int status = 0;

    while (sfRenderWindow_pollEvent(w->win, &event)) {
        status = in_game_menu_event_switch(w, data, event, m);
        if (status != SUCCESS)
            return (status);
    }
    return (SUCCESS);
}
