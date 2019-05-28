/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** move_map
*/

#include "gameloop.h"

void move_map_layer(map_sprite_t **map, int w, int h, sfVector2f pos)
{
    int row = 0;
    int col = 0;

    while (row < h) {
        if (map[row][col].sprite)
            sfSprite_move(map[row][col].sprite, pos);
        col++;
        if (col >= w) {
            row++;
            col = 0;
        }
    }
}