/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** Display the avatar
*/

#include "gameloop.h"

void display_avatar(window_t win, obj_t *obj)
{
    sfVector2f vect = ini_vector(0, -25);

    sfSprite_move(obj->perso.sprite, vect);
    sfRenderWindow_drawSprite(win.win, obj->perso.sprite, NULL);
    vect = ini_vector(0, 25);
    sfSprite_move(obj->perso.sprite, vect);
}
