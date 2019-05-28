/*
** EPITECH PROJECT, 2019
** Zomby
** File description:
** Rect initialization
*/

#include "tool.h"

sfIntRect ini_rect(int x, int y, int width, int height)
{
    sfIntRect rect;

    rect.top = y;
    rect.left = x;
    rect.width = width;
    rect.height = height;
    return (rect);
}