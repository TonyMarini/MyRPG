/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** int to char
*/

#include <stdlib.h>
#include <math.h>

char *mitoa(int nbr)
{
    char *str;
    int nbr_cp = nbr;
    int i = 0;
    int max = 0;

    if (nbr == 0)
        return ("0\0");
    for (i = 0 ; nbr_cp >= 1 ; i++, nbr_cp /= 10);
    str = malloc(sizeof(char *) * (i + 1));
    max = i;
    str[i--] = '\0';
    for (int count = 0 ; count < max ; i--, count++) {
        str[count] = nbr / (int) pow(10, i) + '0';
        nbr %= (int) pow(10, i);
    }
    return (str);
}
