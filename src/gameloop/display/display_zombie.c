/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** display_zombie
*/

#include "gameloop.h"

static void display_obj_bef(window_t win, obj_t *obj, sfVector2f perso)
{
    sfVector2f pos;

    for (int i = 0 ; i < obj->nb_pnj ; i++) {
        pos = sfSprite_getPosition(obj->pnj[i].sprite);
        if (pos.y <= perso.y) {
            sfSprite_move(obj->pnj[i].sprite, (sfVector2f){0, -25});
            sfRenderWindow_drawSprite(win.win, obj->pnj[i].sprite, NULL);
            sfSprite_move(obj->pnj[i].sprite, (sfVector2f){0, 25});
        }
    }
    for (int i = 0 ; i < obj->nb_zombie ; i++) {
        pos = sfSprite_getPosition(obj->zombie[i].sprite);
        if (pos.y <= perso.y && obj->zombie[i].alive == TRUE) {
            sfSprite_move(obj->zombie[i].sprite, (sfVector2f){0, -25});
            sfRenderWindow_drawSprite(win.win, obj->zombie[i].sprite, NULL);
            sfSprite_move(obj->zombie[i].sprite, (sfVector2f){0, 25});
        }
    }
}

static void display_obj_aft(window_t win, obj_t *obj, sfVector2f perso)
{
    sfVector2f pos;

    for (int i = 0 ; i < obj->nb_pnj ; i++) {
        pos = sfSprite_getPosition(obj->pnj[i].sprite);
        if (pos.y > perso.y) {
            sfSprite_move(obj->pnj[i].sprite, (sfVector2f){0, -25});
            sfRenderWindow_drawSprite(win.win, obj->pnj[i].sprite, NULL);
            sfSprite_move(obj->pnj[i].sprite, (sfVector2f){0, 25});
        }
    }
    for (int i = 0 ; i < obj->nb_zombie ; i++) {
        pos = sfSprite_getPosition(obj->zombie[i].sprite);
        if (pos.y > perso.y && obj->zombie[i].alive == TRUE) {
            sfSprite_move(obj->zombie[i].sprite, (sfVector2f){0, -25});
            sfRenderWindow_drawSprite(win.win, obj->zombie[i].sprite, NULL);
            sfSprite_move(obj->zombie[i].sprite, (sfVector2f){0, 25});
        }
    }
}

static void display_dead_zombie(window_t win, obj_t *obj)
{
    for (int i = 0 ; i < obj->nb_zombie ; i++) {
        if (obj->zombie[i].alive == FALSE) {
            sfSprite_move(obj->zombie[i].sprite, (sfVector2f){0, -25});
            sfRenderWindow_drawSprite(win.win, obj->zombie[i].sprite, NULL);
            sfSprite_move(obj->zombie[i].sprite, (sfVector2f){0, 25});
        }
    }
}

void display_obj(window_t win, obj_t *obj)
{
    sfVector2f pos = sfSprite_getPosition(obj->perso.sprite);

    display_dead_zombie(win, obj);
    display_obj_bef(win ,obj, pos);
    display_avatar(win, obj);
    display_obj_aft(win, obj, pos);
}
