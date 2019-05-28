/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** game_over
*/

#include "gameloop.h"

static void destroy_game_over(sfSprite *sprite, sfClock *clock)
{
    sfSprite_destroy(sprite);
    sfClock_destroy(clock);
}

int game_over(window_t *win, gameloop_data_t *data)
{
    sfClock *clock = sfClock_create();
    sfSprite *sprite = sfSprite_create();
    sfTime time;
    float seconds = 0;

    sfSprite_setTexture(sprite,
            data->resource->ui_texture.game_over.texture, sfTrue);
    sfMusic_stop(data->resource->music_data.music->music);
    if (data->resource->music_data.music_mute == 0)
        sfMusic_play(data->resource->music_data.music[GAME_OVER].music);
    sfRenderWindow_clear(win->win, sfBlack);
    sfRenderWindow_drawSprite(win->win, sprite, NULL);
    sfRenderWindow_display(win->win);
    while (seconds < 30) {
        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / 100000.0;
    }
    destroy_game_over(sprite, clock);
    return (ERROR);
}
