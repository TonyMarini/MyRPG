/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** mstrlen
*/

#include <stdlib.h>

int mstrlen(char *str)
{
    int size = 0;

    if (str == NULL)
        return (0);
    for ( ; str[size] != '\0' ; size += 1);
    return (size);
}
