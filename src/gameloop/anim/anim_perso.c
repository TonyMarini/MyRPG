/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** anim_perso
*/

#include "gameloop.h"
#include "tool.h"

static void perso_move_rect(perso_t *perso)
{
    perso->rect.left += perso->rect.width;
    if (perso->rect.left >= (perso->x * 3) * 16 + 48)
        perso->rect.left = (perso->x * 3) * 16;
}

int anim_perso(perso_t *perso)
{
    switch (perso->direction) {
    case 'u':
        perso->rect.top = 96 + (perso->y * 128);
        break;
    case 'd':
        perso->rect.top = 0 + (perso->y * 128);
        break;
    case 'l':
        perso->rect.top = 32 + (perso->y * 128);
        break;
    case 'r':
        perso->rect.top = 64 + (perso->y * 128);
        break;
    default:
        perso->rect.left =  (perso->x * 3) * 16 + 16;
        sfSprite_setTextureRect(perso->sprite, perso->rect);
        return (SUCCESS);
    }
    perso_move_rect(perso);
    sfSprite_setTextureRect(perso->sprite, perso->rect);
    return (SUCCESS);
}