/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_window
*/

#include "rpg.h"
#include "tool.h"

static int set_icon(window_t *window)
{
    sfImage *img = sfImage_createFromFile("resource/ui/logo.png");

    if (img == NULL)
        return (ERROR);
    sfRenderWindow_setIcon(window->win, 122, 120, sfImage_getPixelsPtr(img));
    return (SUCCESS);
}

int init_window(window_t *window, int win_w, int win_h, int fullscreen)
{
    sfRenderWindow *win = NULL;
    sfVideoMode mode = {win_w, win_h, 16};

    if (fullscreen == 1)
        win = sfRenderWindow_create(mode, "My rpg", sfFullscreen, NULL);
    else
        win = sfRenderWindow_create(mode, "My rpg", sfClose, NULL);
    if (win == NULL)
        return (ERROR);
    sfRenderWindow_setFramerateLimit(win, 60);
    window->win = win;
    window->w = win_w;
    window->h = win_h;
    window->scale = 1920 / win_w;
    window->view = sfView_create();
    sfView_setSize(window->view, ini_vector(1920, 1080));
    sfView_setCenter(window->view, ini_vector(win_w / 2, win_h / 2));
    sfRenderWindow_setView(window->win, window->view);
    return (set_icon(window));
}