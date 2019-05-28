/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** ash_particule
*/

#include <stdlib.h>
#include "gameloop.h"
#include "main_menu.h"

static sfVector2f get_aleatoire_speed(void)
{
    sfVector2f speed = {0, 0};

    speed.x = (rand() % 10000) / 13.14 / 2.76 / 1.233;
    speed.y = (rand() % 10000) / 13.14 / 2.76 / 1.233;
    while (speed.x > 4.5)
        speed.x -= 4.5;
    while (speed.y > 0.3)
        speed.y -= 0.3;
    return (speed);
}

static sfVector2f random_position(void)
{
    sfVector2f speed = {0, 0};

    speed.x = (rand() % 1720) - 300;
    speed.y = (rand() % 1080);
    return (speed);
}

void init_rand_pos_and_distance_particule(particule_t *particule, int distance)
{
    for (int i = 0; particule[i].sprite; i++) {
        sfSprite_setPosition(particule[i].sprite, random_position());
        particule[i].distance = distance;
    }
}

void move_ash_particle(particule_t *particule)
{
    sfVector2f speed = get_aleatoire_speed();

    if (particule->distance == 0) {
            particule->color.a = rand() % 255;
            sfSprite_setColor(particule->sprite, particule->color);
            sfSprite_setPosition(particule->sprite, random_position());
            particule->speed = speed;
            particule->distance = rand() % 500 + 40;
    } else {
        particule->color.a -= particule->speed.x;
        sfSprite_setColor(particule->sprite, particule->color);
        sfSprite_move(particule->sprite, particule->speed);
        particule->distance--;
    }
}