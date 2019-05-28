/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** steam_particule
*/

#include <stdlib.h>
#include "rpg.h"
#include "main_menu.h"

void ini_particule_menu(particule_t **particule,
        particule_t **a_particule, resource_t *texture)
{
    init_particule(particule, texture->steam_particule, 150);
    init_pos_and_distance_particule(*particule, ini_vector(400, 185), 100);
    init_particule(a_particule, texture->steam_particule, 150);
    init_rand_pos_and_distance_particule(*a_particule, 1);
}

void init_pos_and_distance_particule(particule_t *particule,
        sfVector2f pos, int distance)
{
    for (int i = 0; particule[i].sprite; i++) {
        sfSprite_setPosition(particule[i].sprite, pos);
        particule[i].distance = distance;
    }
}

static sfVector2f get_aleatoire_speed(void)
{
    sfVector2f speed = {0, 0};

    speed.x = (rand() % 10000) / 13.14 / 2.76 / 1.233;
    speed.y = (rand() % 10000) / 13.14 / 2.76 / 1.233;
    while (-0.2 < speed.x && speed.x > 0.2)
        speed.x -= 0.2;
    if (rand() % 2 == 0)
        speed.x *= -1;
    while (-0.8 < speed.y && speed.y > 0)
        speed.y -= 0.8;
    return (speed);
}

void move_steam_particle(particule_t *particule)
{
    sfVector2f speed = get_aleatoire_speed();

    if (particule->distance == 0) {
            particule->color.a = 255;
            sfSprite_setColor(particule->sprite, particule->color);
            sfSprite_setPosition(particule->sprite, ini_vector(1300, 870));
            particule->speed = speed;
            particule->distance = rand() % 100 + 20;
    } else {
        particule->color.a -= particule->speed.x * 10;
        sfSprite_setColor(particule->sprite, particule->color);
        sfSprite_move(particule->sprite, particule->speed);
        particule->distance--;
    }
}