/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** anim_loot
*/

#include "gameloop.h"
#include "tool.h"

static void anim_loot_cadre(loot_t *loot)
{
    if (loot->rect_cadre.top != 0)
        loot->rect_cadre.top = 0;
    else
        loot->rect_cadre.top = 22;
    sfSprite_setTextureRect(loot->cadre, loot->rect_cadre);
}

void anim_loot(gameloop_data_t *data)
{
    for (int i = 0; i < data->map.obj.nb_loot; i++)
        if (time_to_second(data->map.obj.loot[i].clock) > 1) {
            anim_loot_cadre(&data->map.obj.loot[i]);
            sfClock_restart(data->map.obj.loot[i].clock);
        }
}
