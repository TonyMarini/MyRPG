/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** anim
*/

#include "gameloop.h"
#include "tool.h"

int anim_gameloop(gameloop_data_t *data)
{
    if (time_to_second(data->anim_clock) > 0.1) {
        anim_perso(&data->map.obj.perso);
        sfClock_restart(data->anim_clock);
    }
    anim_loot(data);
    return (SUCCESS);
}