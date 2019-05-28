/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** spawn_battle
*/

#include "gameloop.h"

static void spawn_zombie2(char dir, zombie_t *zombie)
{
    if (dir == 'u') {
        if (zombie->rect.left + 20 <= 20 * zombie->skin_x + 20)
            zombie->rect.left += 20;
        zombie->rect.top = 96 + 128 * zombie->skin_y;
        sfSprite_setTextureRect(zombie->sprite, zombie->rect);
    }
    if (dir == 'd') {
        if (zombie->rect.left + 20 <= 20 * zombie->skin_x + 20)
            zombie->rect.left += 20;
        zombie->rect.top = 0 + 128 * zombie->skin_y;
        sfSprite_setTextureRect(zombie->sprite, zombie->rect);
    }
    zombie->rect.left = zombie->skin_x * 20 - 20;
}

void spawn_zombie(char dir, zombie_t *zombie)
{
    if (dir == 'r') {
        if (zombie->rect.left + 20 <= 20 * zombie->skin_x + 20)
            zombie->rect.left += 20;
        zombie->rect.top = 64 + 128 * zombie->skin_y;
        sfSprite_setTextureRect(zombie->sprite, zombie->rect);
    }
    if (dir == 'l') {
        if (zombie->rect.left + 20 <= 20 * zombie->skin_x + 20)
            zombie->rect.left += 20;
        zombie->rect.top = 32 + 128 * zombie->skin_y;
        sfSprite_setTextureRect(zombie->sprite, zombie->rect);
    }
    spawn_zombie2(dir, zombie);
}

void spawn_battle_player(char dir, perso_t *perso)
{
    switch (dir) {
    case 'u':
        perso->rect.top = 0 + (perso->y * 128);
        break;
    case 'd':
        perso->rect.top = 96 + (perso->y * 128);
        break;
    case 'l':
        perso->rect.top = 64 + (perso->y * 128);
        break;
    case 'r':
        perso->rect.top = 32 + (perso->y * 128);
        break;
    default:
        return;
    }
    perso->rect.left = (perso->x * 3 + 1) * 16;
    sfSprite_setTextureRect(perso->sprite, perso->rect);
}