/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** display_get_char
*/

#include "gameloop.h"

void display_get_character(window_t *win, get_player_t *data, resource_t *res)
{
    sfRenderWindow_clear(win->win, sfBlack);
    sfRenderWindow_drawSprite(win->win, data->background, NULL);
    display_button(win->win, data->prev);
    display_button(win->win, data->next);
    display_button(win->win, data->back);
    display_button(win->win, data->start);
    sfRenderWindow_drawSprite(win->win, data->perso, NULL);
    display_cursor(win, res->cursor);
    sfRenderWindow_display(win->win);
}