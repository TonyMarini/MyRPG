/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** move_zombie
*/

#include "gameloop.h"

static void check_move_zombie(zombie_t *zombie)
{
    if (zombie->direction[zombie->index] == 'r') {
        zombie->move = ini_vector(1, 0);
        zombie->pos.x++;
    }
    if (zombie->direction[zombie->index] == 'l') {
        zombie->move = ini_vector(-1, 0);
        zombie->pos.x--;
    }
    if (zombie->direction[zombie->index] == 'd') {
        zombie->move = ini_vector(0, 1);
        zombie->pos.y++;
    }
    if (zombie->direction[zombie->index] == 'u') {
        zombie->move = ini_vector(0, -1);
        zombie->pos.y--;
    }
}

static void move_one_zombie(zombie_t *zombie)
{
    if (zombie->alive == FALSE)
        return;
    check_move_zombie(zombie);
    if (zombie->pos.x % 80 == 0 && zombie->pos.y % 80 == 0) {
        if (zombie->direction[zombie->index + 1] == '\0')
            zombie->index = 0;
        else
            zombie->index++;
    }
    sfSprite_move(zombie->sprite, zombie->move);
    if (time_to_second(zombie->clock) > 0.25)
        move_rect_zombie(zombie);
}

void move_zombie(int nb_zombie, zombie_t *zombie)
{
    for (int i = 0 ; i < nb_zombie ; i++)
        move_one_zombie(&zombie[i]);
}