/*
** EPITECH PROJECT, 2019
** Zomby
** File description:
** Vector initialization
*/

#include "tool.h"

sfVector2f ini_vector(float fact_x, float fact_y)
{
    sfVector2f vector;

    vector.x = fact_x;
    vector.y = fact_y;
    return (vector);
}

sfVector2i ini_vectori(int x, int  y)
{
    sfVector2i vector;

    vector.x = x;
    vector.y = y;
    return (vector);
}
