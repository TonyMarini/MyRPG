/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** win_screen
*/

#include "gameloop.h"

void end_screen(window_t *win, gameloop_data_t *data)
{
    sfSprite *sprite = sfSprite_create();
    sfEvent event;
    sfClock *clock = sfClock_create();

    sfSprite_setTexture(sprite,
            data->resource->ui_texture.end_screen.texture, sfTrue);
    while (!sfRenderWindow_pollEvent(win->win, &event) ||
    time_to_second(clock) < 5) {
        sfRenderWindow_clear(win->win, sfBlack);
        sfRenderWindow_drawSprite(win->win, sprite, NULL);
        sfRenderWindow_display(win->win);
    }
}