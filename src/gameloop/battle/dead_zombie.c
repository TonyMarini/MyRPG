/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** dead_zombie
*/

#include <stdlib.h>
#include "gameloop.h"

void to_dead_zombie(zombie_t *zombie)
{
    int blood = (rand() % 2) * 192;

    zombie->alive = FALSE;
    sfSprite_setTexture(zombie->sprite, zombie->dead_texture, sfTrue);
    sfSprite_setTextureRect(zombie->sprite, (sfIntRect){
        zombie->skin_y / 4 * 96 + blood, zombie->skin_x / 3 * 32, 32, 32});
}