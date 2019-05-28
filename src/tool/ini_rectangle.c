/*
** EPITECH PROJECT, 2019
** my defender
** File description:
** initialise a rectangle (size, transparent)
*/

#include "rpg.h"
#include "tool.h"

sfRectangleShape *ini_rectangle(int width, int height)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfColor color;

    color = ini_color(0, 0, 0, 0);
    sfRectangleShape_setSize(rect, ini_vector(width, height));
    sfRectangleShape_setFillColor(rect, color);
    return (rect);
}
