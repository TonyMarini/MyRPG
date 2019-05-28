/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** get_character
*/

#include "gameloop.h"

static void anim_get_char(window_t *win, get_player_t *data)
{
    button_is_over(*win, &data->prev);
    button_is_over(*win, &data->next);
    button_is_over(*win, &data->start);
    button_is_over(*win, &data->back);
}

int get_character(window_t *win, resource_t *resource, sfVector2i *perso)
{
    get_player_t data;
    int status = SUCCESS;

    if (init_get_character(resource, &data, *perso) == ERROR)
        return (ERROR);
    while (sfRenderWindow_isOpen(win->win) && status == SUCCESS) {
        anim_get_char(win, &data);
        display_get_character(win, &data, resource);
        status = get_char_event(win, &data);
    }
    *perso = (sfVector2i){data.pos_x, data.pos_y};
    return (status);
}