/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** move_perso
*/

#include <stdio.h>
#include "rpg.h"
#include "gameloop.h"

static int check_perso_col(perso_t *perso, map_data_t *map, int x, int y)
{
    sfVector2f pos = sfSprite_getPosition(perso->sprite);
    int pos_x = pos.x / TILE_SCALE + x;
    int pos_y = (pos.y + TILE_SCALE) / TILE_SCALE + y;

    if (pos_x < 0 || pos_y < 0 || pos_x >= map->w || pos_y >= map->h)
        return (ERROR);
    if (map->layer1[pos_y][pos_x].sprite != NULL)
        return (ERROR);
    if (map->layer2[pos_y][pos_x].sprite != NULL)
        return (ERROR);
    return (SUCCESS);
}

static void switch_move(perso_t *perso, map_data_t *map, int col)
{
    switch (perso->direction) {
    case 'u':
        if (check_perso_col(perso, map, 0, -1) == SUCCESS || col == 1)
            sfSprite_move(perso->sprite, ini_vector(0, -4));
        break;
    case 'd':
        if (check_perso_col(perso, map, 0, 1) == SUCCESS || col == 1)
            sfSprite_move(perso->sprite, ini_vector(0, 4));
        break;
    case 'l':
        if (check_perso_col(perso, map, -1, 0) == SUCCESS || col == 1)
            sfSprite_move(perso->sprite, ini_vector(-4, 0));
        break;
    case 'r':
        if (check_perso_col(perso, map, 1, 0) == SUCCESS || col == 1)
            sfSprite_move(perso->sprite, ini_vector(4, 0));
        break;
    default:
        return;
    }
}

int move_perso(game_key_t key, perso_t *perso, map_data_t *map)
{
    sfVector2f pos = sfSprite_getPosition(perso->sprite);

    if ((int)pos.x % TILE_SCALE != 0 || (int)pos.y % TILE_SCALE != 0) {
        switch_move(perso, map, 1);
        return (SUCCESS);
    }
    perso->direction = 'n';
    if (sfKeyboard_isKeyPressed(key.up))
        perso->direction = 'u';
    if (sfKeyboard_isKeyPressed(key.right))
        perso->direction = 'r';
    if (sfKeyboard_isKeyPressed(key.left))
        perso->direction = 'l';
    if (sfKeyboard_isKeyPressed(key.down))
        perso->direction = 'd';
    switch_move(perso, map, 0);
    return (SUCCESS);
}