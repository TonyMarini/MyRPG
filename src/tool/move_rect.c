/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** move_rect
*/

#include "rpg.h"

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    rect->left += offset;
    if (rect->left >= max_value)
        rect->left = 0;
}