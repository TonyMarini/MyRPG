/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** anim_zombie
*/

#include "gameloop.h"

void move_rect_zombie(zombie_t *zombie)
{
    if (zombie->direction[zombie->index] == 'r') {
        if (zombie->rect.left + 20 <= 20 * zombie->skin_x + 20)
            zombie->rect.left += 20;
        else
            zombie->rect.left = zombie->skin_x * 20 - 20;
        zombie->rect.top = 64 + 128 * zombie->skin_y;
        sfSprite_setTextureRect(zombie->sprite, zombie->rect);
    }
    if (zombie->direction[zombie->index] == 'l') {
        if (zombie->rect.left + 20 <= 20 * zombie->skin_x + 20)
            zombie->rect.left += 20;
        else
            zombie->rect.left = zombie->skin_x * 20 - 20;
        zombie->rect.top = 32 + 128 * zombie->skin_y;
        sfSprite_setTextureRect(zombie->sprite, zombie->rect);
    }
    move_rect_zombie_two(zombie);
}

void move_rect_zombie_two(zombie_t *zombie)
{
    if (zombie->direction[zombie->index] == 'd') {
        if (zombie->rect.left + 20 <= 20 * zombie->skin_x + 20)
            zombie->rect.left += 20;
        else
            zombie->rect.left = zombie->skin_x * 20 - 20;
        zombie->rect.top = 0 + 128 * zombie->skin_y;
        sfSprite_setTextureRect(zombie->sprite, zombie->rect);
    }
    if (zombie->direction[zombie->index] == 'u') {
        if (zombie->rect.left + 20 <= 20 * zombie->skin_x + 20)
            zombie->rect.left += 20;
        else
            zombie->rect.left = zombie->skin_x * 20 - 20;
        zombie->rect.top = 96 + 128 * zombie->skin_y;
        sfSprite_setTextureRect(zombie->sprite, zombie->rect);
    }
    sfClock_restart(zombie->clock);
}