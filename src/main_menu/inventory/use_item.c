/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** use_item
*/

#include "gameloop.h"

int inv_use_item(gameloop_data_t *data, int i, int t)
{
    int value = t == 0 ? data->inventory.inventory_content[i] :
            data->inventory.spell_content[i];
    int heal = 0;

    if (value == -1)
        return (SUCCESS);
    if (t == 0) {
        heal = data->item[data->inventory.inventory_content[i]].heal;
        data->inventory.inventory_content[i] = -1;
    } else {
        heal = data->item[data->inventory.spell_content[i]].heal;
        data->inventory.spell_content[i] = -1;
    }
    if (heal > 0) {
        data->map.obj.perso.stat.life += heal;
        if (data->map.obj.perso.stat.life > data->map.obj.perso.stat.max_life)
            data->map.obj.perso.stat.life = data->map.obj.perso.stat.max_life;
        add_life(data);
        sfMusic_play(data->resource->music_data.music[HEAL].music);
    }
    return (SUCCESS);
}