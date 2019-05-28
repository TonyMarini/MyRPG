/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** particule
*/

#include <stdio.h>
#include <stdlib.h>
#include "gameloop.h"
#include "main_menu.h"

static void move_one_parti(particule_t *particule, char move, sfVector2f pos)
{
    if (particule->distance == 0) {
        if (move == 'n') {
            particule->color.a = 0;
            sfSprite_setColor(particule->sprite, particule->color);
        } else {
            particule->color.a = 255;
            sfSprite_setColor(particule->sprite, particule->color);
            sfSprite_setPosition(particule->sprite, pos);
            particule->speed = ini_vector(rand() % 4 - 2, rand() % 4 - 2);
            particule->distance = rand() % 20 + 2;
        }
    } else {
        particule->color.a -= particule->speed.x * 10;
        sfSprite_setColor(particule->sprite, particule->color);
        sfSprite_move(particule->sprite, particule->speed);
        particule->distance--;
    }
}

int init_particule(particule_t **my_particule, my_texture_t texture, int nb)
{
    particule_t *particule = NULL;

    particule = malloc(sizeof(particule_t) * (nb + 1));
    if (particule == NULL)
        return (ERROR);
    particule[nb].sprite = NULL;
    for (int i = 0 ; i < nb ; i++) {
        particule[i].sprite = set_sprite(texture, ini_vector(0, 0), 1, 1);
        particule[i].color = ini_color(255, 255, 255, 255);
        particule[i].speed = ini_vector(0, 0);
        particule[i].distance = 0;
    }
    *my_particule = particule;
    return (SUCCESS);
}

void load_particule(gameloop_data_t *data, resource_t *resource)
{
    init_particule(&data->player_particule, resource->particule, 75);
    init_particule(&data->ash_particule, resource->steam_particule, 150);
    init_particule(&data->blood_particule, resource->blood_particule, 50);
    init_particule(&data->health_particule, resource->health_particule, 30);
    init_rand_pos_and_distance_particule(data->ash_particule, 1);
}

void move_particule(gameloop_data_t *data)
{
    particule_t *particule = data->player_particule;
    particule_t *a_particule = data->ash_particule;
    sfVector2f pos = sfSprite_getPosition(data->map.obj.perso.sprite);

    pos.x += TILE_SCALE / 2;
    pos.y += TILE_SCALE * 1.5;
    for (int i = 0 ; particule[i].sprite ; i++)
        move_one_parti(&particule[i], data->map.obj.perso.direction, pos);
    if (data->map.obj.is_outdoor == 0)
        return;
    for (int i = 0 ; a_particule[i].sprite ; i++)
        move_ash_particle(&a_particule[i]);
}

void hide_particule(particule_t *particule)
{
    for (int i = 0 ; particule[i].sprite ; i++)
        particule[i].distance = 0;
}