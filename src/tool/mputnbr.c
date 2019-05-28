/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** mputnbr
*/

#include "unistd.h"
#include <stdlib.h>
#include "tool.h"

void mputnbr(int nb)
{
    if (nb < 0) {
        write(1, "-", 1);
        nb *= -1;
    }
    if (nb > 9)
        mputnbr(nb / 10);
    mputchar(nb % 10 + '0');
}

void fputnbr(int nb, int fd)
{
    char temp = nb % 10 + '0';

    if (nb < 0) {
        write(1, "-", 1);
        nb *= -1;
    }
    if (nb > 9)
        fputnbr(nb / 10, fd);
    write(fd, &temp, 1);
}