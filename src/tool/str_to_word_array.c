/*
** EPITECH PROJECT, 2018
** my_str_to_word_array.c
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>
#include "tool.h"

char **make_str(char *str, int *i, int *j, char **dest)
{
    int s = 0;

    while (str[*i] != '\0' && str[*i] != ':') {
        dest[*j][s] = str[*i];
        (*i)++;
        s++;
    }
    dest[*j][s] = '\0';
    return (dest);
}

char **malloc_str(char **dest, char *str, int *i, int *j)
{
    int k = 0;
    int last_i = *i;

    while (str[*i] != '\0' && str[*i] != ':') {
        k++;
        (*i)++;
    }
    *i = last_i;
    if ((dest[*j] = malloc(sizeof(char) * (k + 1))) == NULL)
        return (NULL);
    dest = make_str(str, i, j, dest);
    (*j)++;
    return (dest);
}

int nb_word(char *str)
{
    int size = 1;

    for (int i = 0; str[i] != '\0'; i++)
        if (!((str[i] != '\0' && str[i] != ':')) &&
            ((str[i] != '\0' && str[i + 1] != ':')))
            size++;
    return (size);
}

int check_str(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] != '\0' && str[i] != ':')
            return (1);
    return (0);
}

char **str_to_word_array(char *str)
{
    int size = 1;
    char **dest = NULL;
    int j = 0;
    int len = mstrlen(str);

    if (check_str(str) == 0)
        return (NULL);
    if (*str == 0)
        return (dest);
    size = nb_word(str);
    if ((dest = malloc(sizeof(char *) * (size + 1))) == NULL)
        return (NULL);
    for (int i = 0; (j == 0 && i < len) || (j < size &&
            dest[j - 1] != NULL && i < len); i++) {
        if (str[i] != '\0' && str[i] != ':')
            dest = malloc_str(dest, str, &i, &j);
    }
    dest[j] = NULL;
    return (dest);
}
