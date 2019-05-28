/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** percent_life
*/

#include "gameloop.h"

static int percent_life(perso_t *perso)
{
    int percent = make_percent(perso->stat.life, perso->stat.max_life);
    int life = 0;

    if (percent == ERROR)
        return (ERROR);
    life = reverse_percent(percent, 225);
    if (life == ERROR)
        return (ERROR);
    return (life);
}

void add_life(gameloop_data_t *data)
{
    int add_life = 0;

    add_life = percent_life(&data->map.obj.perso);
    if (add_life == ERROR)
        return;
    sfText_setString(data->inventory.life.act,
        mitoa(data->map.obj.perso.stat.life));
    if (data->map.obj.perso.stat.life >= data->map.obj.perso.stat.max_life) {
        sfSprite_setScale(data->hud.life, (sfVector2f){225, 2.25});
        return;
    }
    sfSprite_setScale(data->hud.life, (sfVector2f){add_life, 2.25});
}

void remove_life(gameloop_data_t *data)
{
    int rm_life = 0;

    rm_life = percent_life(&data->map.obj.perso);
    if (rm_life == ERROR)
        return;
    sfText_setString(data->inventory.life.act,
        mitoa(data->map.obj.perso.stat.life));
    rm_life = 225 - rm_life;
    sfSprite_setScale(data->hud.life, (sfVector2f){225 - rm_life, 2.25});
}