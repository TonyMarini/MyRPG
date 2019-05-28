/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** percent
*/

#include "rpg.h"

int make_percent(unsigned int actual, unsigned int total)
{
    int result = 0;

    if (total == 0)
        return (ERROR);
    result = actual * 100 / total;
    if (result < 0)
        return (ERROR);
    return (result);
}

int reverse_percent(unsigned int percent, unsigned int total)
{
    int result = 0;

    result = percent * total / 100;
    if (result < 0)
        return (ERROR);
    return (result);
}