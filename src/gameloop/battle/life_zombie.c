/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** life_zombie
*/

#include "gameloop.h"

static int percent_life(zombie_t *zombie)
{
    int percent = make_percent(zombie->stat.life, zombie->stat.max_life);
    int life = 0;

    if (percent == ERROR)
        return (ERROR);
    life = reverse_percent(percent, 75);
    if (life == ERROR)
        return (ERROR);
    return (life);
}

void remove_life_zombie(zombie_t *zombie)
{
    int rm_life = 0;

    rm_life = percent_life(zombie);
    if (rm_life == ERROR)
        return;
    rm_life = 75 - rm_life;
    sfSprite_setScale(zombie->live, (sfVector2f){75 - rm_life, 1});
}