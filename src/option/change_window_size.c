/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** change_window_size
*/

#include <stdio.h>
#include "rpg.h"
#include "init.h"

int change_window_size(window_t *w, option_t *option, int new_size, int full)
{
    sfVector2u size[6] = {{2560, 1440}, {1920, 1080}, {1366, 768},
    {1280, 720}, {960, 540}, {640, 360}};

    if (full != option->fullscreen) {
        sfRenderWindow_close(w->win);
        sfRenderWindow_destroy(w->win);
        if (full == 1)
            option->fullscreen = 1;
        else
            option->fullscreen = 0;
        if (init_window(w, 1920, 1080, option->fullscreen) == ERROR)
            return (ERROR);
    }
    option->select_size = new_size;
    w->scale = (float)size[new_size].x / w->w;
    sfRenderWindow_setSize(w->win, size[new_size]);
    return (SUCCESS);
}