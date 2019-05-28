/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** get_char_event
*/

#include "gameloop.h"

static void change_perso(get_player_t *data, int value)
{
    data->pos_x += value;

    if (data->pos_x > 3) {
        data->pos_x = 0;
        data->pos_y++;
    }
    if (data->pos_x < 0) {
        data->pos_x = 3;
        data->pos_y--;
    }
    if (data->pos_y > 1) {
        data->pos_y = 0;
        data->pos_x = 0;
    }
    if (data->pos_y < 0) {
        data->pos_y = 1;
        data->pos_x = 3;
    }
    sfSprite_setTextureRect(data->perso,
        (sfIntRect){(data->pos_x * 3 + 1) * 16, data->pos_y * 128, 16, 32});
}

static int mouse_click(sfMouseButtonEvent mouse,
    window_t *w, get_player_t *data, int s)
{
    sfVector2i pos = (sfVector2i){mouse.x, mouse.y};

    if (button_is_click(*w, &data->start, pos) && s == 1)
        return (1);
    if (button_is_click(*w, &data->back, pos) && s == 1)
        return (ERROR);
    if (button_is_click(*w, &data->next, pos) && s == 1)
        change_perso(data, 1);
    if (button_is_click(*w, &data->prev, pos) && s == 1)
        change_perso(data, -1);
    return (SUCCESS);
}

static int key_pressed_evt(sfKeyEvent key)
{
    if (key.code == sfKeyEscape)
        return (ERROR);
    return (SUCCESS);
}

static int event_switch(sfEvent event, window_t *w, get_player_t *game_data)
{
    (void)game_data;
    switch (event.type) {
    case sfEvtClosed:
        sfRenderWindow_close(w->win);
        return (ERROR);
    case sfEvtKeyPressed:
        return (key_pressed_evt(event.key));
    case sfEvtMouseButtonPressed:
        return (mouse_click(event.mouseButton, w, game_data, 0));
    case sfEvtMouseButtonReleased:
        return (mouse_click(event.mouseButton, w, game_data, 1));
    default:
        break;
    }
    return (SUCCESS);
}

int get_char_event(window_t *window, get_player_t *game_data)
{
    sfEvent event;
    int status = 0;

    while (sfRenderWindow_pollEvent(window->win, &event)) {
        status = event_switch(event, window, game_data);
        if (status != SUCCESS)
            return (status);
    }
    return (SUCCESS);
}