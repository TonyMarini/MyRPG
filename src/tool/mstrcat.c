/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** mstrcat
*/

#include <stdlib.h>

char *mstrcat(char const *str1, char const *str2)
{
    char *new = NULL;
    int size = 0;
    int pos = 0;

    for (int i = 0 ; str1[i] ; i++, size++);
    for (int i = 0 ; str2[i] ; i++, size++);
    if ((new = malloc(sizeof(char *) * (++size))) == NULL)
        return (NULL);
    for (int i = 0 ; str1[i] ; i++)
        new[pos++] = str1[i];
    for (int i = 0 ; str2[i] ; i++)
        new[pos++] = str2[i];
    new[pos] = '\0';
    return (new);
}