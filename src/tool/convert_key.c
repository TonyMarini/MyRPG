/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** convert_key
*/

#include "rpg.h"

int from_key_to_array(game_key_t key, sfKeyCode *array)
{
    array[0] = key.left;
    array[1] = key.right;
    array[2] = key.up;
    array[3] = key.down;
    array[4] = key.action;
    array[5] = key.inventory;
    array[6] = key.spell1;
    array[7] = key.spell2;
    array[8] = key.spell3;
    array[9] = key.spell4;
    array[10] = key.spell5;
    array[11] = key.spell6;
    return (SUCCESS);
}

int from_array_to_key(game_key_t *key, sfKeyCode *array)
{
    key->left = array[0];
    key->right = array[1];
    key->up = array[2];
    key->down = array[3];
    key->action = array[4];
    key->inventory = array[5];
    key->spell1 = array[6];
    key->spell2 = array[7];
    key->spell3 = array[8];
    key->spell4 = array[9];
    key->spell5 = array[10];
    key->spell6 = array[11];
    return (SUCCESS);
}