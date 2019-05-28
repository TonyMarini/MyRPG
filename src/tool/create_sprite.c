/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** create_spirte
*/

#include "rpg.h"
#include "tool.h"

sfSprite *set_sprite(my_texture_t texture, sfVector2f pos, float scale, int c)
{
    sfSprite *my_sprite;
    sfFloatRect rect;

    my_sprite = sfSprite_create();
    sfSprite_setTexture(my_sprite, texture.texture, sfTrue);
    sfSprite_setScale(my_sprite, ini_vector(scale, scale));
    sfSprite_setPosition(my_sprite, pos);
    if (c == 1) {
        rect = sfSprite_getLocalBounds(my_sprite);
        pos = ini_vector(rect.width / 2, rect.height / 2);
        sfSprite_setOrigin(my_sprite, pos);
    }
    return (my_sprite);
}