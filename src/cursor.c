/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** cursor
*/

#include "rpg.h"

void display_cursor(window_t *win, sfSprite *cursor)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(win->win);

    sfSprite_setPosition(cursor,
            (sfVector2f){pos.x / win->scale, pos.y / win->scale});
    sfRenderWindow_drawSprite(win->win, cursor, NULL);
}