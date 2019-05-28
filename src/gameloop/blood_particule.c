/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** blood_particule
*/

#include <stdlib.h>
#include "gameloop.h"

static void move_one_parti(particule_t *particule)
{
    if (particule->color.a >= 10) {
        particule->color.a -= 10;
        sfSprite_setColor(particule->sprite, particule->color);
    }
    if (particule->distance == 0)
        return;
    sfSprite_move(particule->sprite, particule->speed);
    particule->distance--;
}

void move_blood_particule(particule_t *particule, int nb)
{
    for (int i = 0 ; i < nb ; i++)
        move_one_parti(&particule[i]);
}

void setpos_blood_particule(gameloop_data_t *data, sfVector2f pos)
{
    particule_t *particule = data->blood_particule;

    for (int i = 0; i < 50; i++) {
        sfSprite_setPosition(particule[i].sprite, pos);
        particule[i].color.a = 255;
        sfSprite_setColor(particule[i].sprite, particule[i].color);
        particule[i].speed = (sfVector2f){(rand() % 5) - 2, -(rand() % 3)};
        particule[i].distance = rand() % 25;
    }
}

void setpos_health_particule(gameloop_data_t *data, sfVector2f pos)
{
    particule_t *particule = data->health_particule;

    for (int i = 0; i < 30; i++) {
        sfSprite_setPosition(particule[i].sprite,
                (sfVector2f){pos.x + (rand() % TILE_SCALE) - TILE_SCALE / 2,
                pos.y + (rand() % TILE_SCALE) - TILE_SCALE / 2});
        particule[i].color.a = 255;
        sfSprite_setColor(particule[i].sprite, particule[i].color);
        particule[i].speed = (sfVector2f){0, -(rand() % 3)};
        particule[i].distance = rand() % 25;
    }
}