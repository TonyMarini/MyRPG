/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** Change the status battle if there is an agression
*/

#include <stdio.h>
#include "gameloop.h"

static sfVector2i ini_pos(sfSprite *sprite)
{
    sfVector2f pos;

    pos = sfSprite_getPosition(sprite);
    pos.y += TILE_SCALE;
    pos.x += TILE_SCALE / 2;
    if (pos.x < 0 || pos.y < 0)
        return ((sfVector2i){0, 0});
    pos = (sfVector2f){pos.x / TILE_SCALE, pos.y / TILE_SCALE};
    return ((sfVector2i){(int)pos.x,(int)pos.y});
}

static int is_cac(char *dir, sfVector2i pos_p, sfVector2i pos_z)
{
    if (pos_p.y == pos_z.y && pos_p.x == pos_z.x + 1) {
        *dir = 'r';;
        return (TRUE);
    }
    if (pos_p.y == pos_z.y && pos_p.x == pos_z.x - 1) {
        *dir = 'l';
        return (TRUE);
    }
    if (pos_p.x == pos_z.x && pos_p.y == pos_z.y + 1) {
        *dir = 'd';
        return (TRUE);
    }
    if (pos_p.x == pos_z.x && pos_p.y == pos_z.y - 1) {
        *dir = 'u';
        return (TRUE);
    }
    return (FALSE);
}

static int is_agro(sfVector2i pos_p, sfVector2i pos_z, char dir_z, char *dir)
{
    char line_agro = FALSE;

    if (dir_z == 'u' && pos_p.x == pos_z.x &&
        pos_z.y - pos_p.y >= 0 && pos_z.y - pos_p.y <= 3)
        line_agro = TRUE;
    if (dir_z == 'd' && pos_p.x == pos_z.x &&
        pos_p.y - pos_z.y >= 0 && pos_p.y - pos_z.y <= 3)
        line_agro = TRUE;
    if (dir_z == 'l' && pos_p.y == pos_z.y &&
        pos_z.x - pos_p.x >= 0 && pos_z.x - pos_p.x <= 3)
        line_agro = TRUE;
    if (dir_z == 'r' && pos_p.y == pos_z.y &&
        pos_p.x - pos_z.x >= 0 && pos_p.x - pos_z.x <= 3)
        line_agro = TRUE;
    if (line_agro == TRUE) {
        *dir = dir_z;
        return (TRUE);
    }
    if (is_cac(dir, pos_p, pos_z) == TRUE)
        return (TRUE);
    return (FALSE);
}

void is_battle(battle_t *battle, obj_t *obj)
{
    sfVector2i pos_perso = ini_pos(obj->perso.sprite);
    sfVector2i pos_zombie = {0, 0};

    if (battle->status_battle == TRUE)
        return;
    for (int i = 0 ; i < obj->nb_zombie ; i++) {
        pos_zombie = ini_pos(obj->zombie[i].sprite);
        if (obj->zombie[i].alive == TRUE
            && is_agro(pos_perso, pos_zombie,
            obj->zombie[i].direction[obj->zombie[i].index],
            &battle->dir) == TRUE) {
            battle->status_battle = TRUE;
            battle->zombie = i;
            obj->zombie[i].is_fighting = TRUE;
            return;
        }
    }
}
