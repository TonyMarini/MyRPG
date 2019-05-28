/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** display_particule
*/

#include "gameloop.h"

void display_particule(window_t *win, gameloop_data_t *data)
{
    for (int i = 0 ; data->player_particule[i].sprite ; i++)
        sfRenderWindow_drawSprite(win->win,
                data->player_particule[i].sprite, NULL);
}

void display_blood_particule(window_t *win, gameloop_data_t *data)
{
    for (int i = 0; i < 50 ; i++)
        sfRenderWindow_drawSprite(win->win,
                data->blood_particule[i].sprite, NULL);
}

void display_ash_particule(window_t *win, gameloop_data_t *data)
{
    if (data->map.obj.is_outdoor == 0)
        return;
    for (int i = 0 ; data->ash_particule[i].sprite ; i++)
        sfRenderWindow_drawSprite(win->win,
                data->ash_particule[i].sprite, NULL);
}

void display_health_particule(window_t *win, gameloop_data_t *data)
{
    for (int i = 0; i < 30 ; i++)
        sfRenderWindow_drawSprite(win->win,
                data->health_particule[i].sprite, NULL);
}