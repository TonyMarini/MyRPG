/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** battle
*/

#include <stdio.h>
#include "gameloop.h"

//  Function for the battle
int battle(gameloop_data_t *data, window_t *win)
{
    int status = 0;

    spawn_zombie(data->battle.dir,
        &data->map.obj.zombie[data->battle.zombie]);
    spawn_battle_player(data->battle.dir, &data->map.obj.perso);
    sfClock_restart(data->battle.anim_clock);
    data->battle.anim = 0;
    data->battle.blood_particule = 0;
    data->battle.health_particule = 0;
    loop_battle(data, win, &status);
    if (status == 1)
        return (ERROR);
    return (SUCCESS);
}