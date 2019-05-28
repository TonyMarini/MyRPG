/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** create_color
*/

#include "rpg.h"

sfColor ini_color(int r, int g, int b, int a)
{
    sfColor color;
    color.r = r;
    color.g = g;
    color.b = b;
    color.a = a;
    return (color);
}
