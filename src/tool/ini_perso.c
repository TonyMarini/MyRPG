/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** ini_perso
*/

#include "rpg.h"
#include "tool.h"

perso_t ini_perso(sfTexture *texture, int x, int y)
{
    perso_t my_perso;

    my_perso.sprite = sfSprite_create();
    sfSprite_setTexture(my_perso.sprite, texture, sfTrue);
    sfSprite_setScale(my_perso.sprite, ini_vector(SCALE, SCALE));
    my_perso.rect = ini_rect((x * 3) * 16 + 16, 128 * y, 16, 32);
    sfSprite_setTextureRect(my_perso.sprite, my_perso.rect);
    my_perso.x = x;
    my_perso.y = y;
    my_perso.direction = 'n';
    my_perso.stat.ammo = 0;
    my_perso.stat.ad = 0;
    my_perso.stat.life = 15;
    my_perso.stat.max_life = 15;
    my_perso.stat.xp = 0;
    my_perso.stat.max_xp = 20;
    my_perso.mission = 0;
    return (my_perso);
}
