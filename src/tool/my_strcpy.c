/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** my_str_cpy
*/

#include <stdlib.h>
#include "tool.h"

char *my_strcpy(char *str)
{
    char *cpy = malloc(sizeof(char) * (mstrlen(str) + 1));
    int i = 0;

    while (str[i] != '\0') {
        cpy[i] = str[i];
        i++;
    }
    cpy[i] = '\0';
    return (cpy);
}