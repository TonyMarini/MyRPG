/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** Load the interaction map
*/

#include "gameloop.h"

#include <stdio.h>

static void load_case(obj_t *obj, sfSprite *sprite, int type)
{
    sfVector2f pos;

    pos = sfSprite_getPosition(sprite);
    pos.y += TILE_SCALE;
    pos.x += TILE_SCALE / 2;
    if (pos.x < 0 || pos.y < 0)
        return;
    pos = (sfVector2f){pos.x / TILE_SCALE, pos.y / TILE_SCALE};
    obj->obj_map[(int)pos.y][(int)pos.x].type = type;
}

static void reset_map(obj_t *obj, int i)
{
    for (int ii = 0 ; ii < 24 ; ii++)
        if (obj->obj_map[i][ii].type == 1 ||
            obj->obj_map[i][ii].type == 2 ||
            obj->obj_map[i][ii].type == 3)
            obj->obj_map[i][ii].type = 0;
}

void load_interaction(obj_t *obj)
{
    for (int i = 0 ; i < 14 ; i++)
        reset_map(obj, i);
    load_case(obj, obj->perso.sprite, 1);
    for (int i = 0 ; i < obj->nb_pnj; i++)
        load_case(obj, obj->pnj[i].sprite, 2);
    for (int i = 0 ; i < obj->nb_zombie; i++)
        load_case(obj, obj->zombie[i].sprite, 3);
}
