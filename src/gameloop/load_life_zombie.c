/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** load_life_zombie
*/

#include "gameloop.h"

void initialize_zombie_life(resource_t *resource, zombie_t *zombie, int *i)
{
    sfVector2f pos = sfSprite_getPosition(zombie[*i].sprite);

    zombie[*i].life_bar = sfSprite_create();
    zombie[*i].live = sfSprite_create();
    sfSprite_setTexture(zombie[*i].life_bar,
        resource->ui_texture.zombie_life.texture, sfTrue);
    sfSprite_setTexture(zombie[*i].live,
        resource->ui_texture.life.texture, sfTrue);
    pos.y -= 15;
    sfSprite_setPosition(zombie[*i].life_bar, pos);
    sfSprite_setScale(zombie[*i].live, (sfVector2f){75, 1});
    sfSprite_setPosition(zombie[*i].live, pos);
}