/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** xp
*/

#include "gameloop.h"

static void write_level_up(gameloop_data_t *data)
{
    sfText_setString(data->inventory.xp.max,
        mitoa(data->map.obj.perso.stat.max_xp));
    sfText_setString(data->inventory.life.max,
        mitoa(data->map.obj.perso.stat.max_life));
    sfText_setString(data->inventory.life.act,
        mitoa(data->map.obj.perso.stat.life));
    sfText_setString(data->inventory.level.act,
        mitoa(data->inventory.nb_level));
    add_life(data);
}

static void level_up(gameloop_data_t *data)
{
    data->map.obj.perso.stat.xp -= data->map.obj.perso.stat.max_xp;
    data->map.obj.perso.stat.max_xp =
        (data->map.obj.perso.stat.max_xp + 10) * 1.5;
    data->map.obj.perso.stat.max_life += 10;
    data->map.obj.perso.stat.life = data->map.obj.perso.stat.max_life;
    data->inventory.nb_level += 1;
    sfMusic_play(data->resource->music_data.music[LVL_UP].music);
    write_level_up(data);
}

static int percent_xp(perso_t *perso)
{
    int percent = make_percent(perso->stat.xp, perso->stat.max_xp);
    int xp = 0;

    if (percent == ERROR)
        return (ERROR);
    xp = reverse_percent(percent, 225);
    if (xp == ERROR)
        return (ERROR);
    return (xp);
}

void xp(gameloop_data_t *data)
{
    int add_xp = 0;
    float xp = data->map.obj.zombie[data->battle.zombie].dificulty;

    data->map.obj.perso.stat.xp += (int)(xp * (float)10);
    if (data->map.obj.perso.stat.xp >= data->map.obj.perso.stat.max_xp)
        level_up(data);
    add_xp = percent_xp(&data->map.obj.perso);
    if (add_xp == ERROR)
        return;
    sfText_setString(data->inventory.xp.act,
        mitoa(data->map.obj.perso.stat.xp));
    sfSprite_setScale(data->hud.exp, (sfVector2f){add_xp, 2.25});
}
