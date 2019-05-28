/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** display_map
*/

#include "gameloop.h"
#include <stdio.h>

int display_map_layer(window_t *win, map_sprite_t **map, int w, int h)
{
    int row = 0;
    int col = 0;

    while (row < h) {
        if (map[row][col].sprite)
            sfRenderWindow_drawSprite(win->win, map[row][col].sprite, NULL);
        col++;
        if (col >= w) {
            row++;
            col = 0;
        }
    }
    return (0);
}