/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** scale_rect
*/

#include "rpg.h"

void scale_rect(sfFloatRect *rect, float scale)
{
    rect->left *= scale;
    rect->width *= scale;
    rect->top *= scale;
    rect->height *= scale;
}
