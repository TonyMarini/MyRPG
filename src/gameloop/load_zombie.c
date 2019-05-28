/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** load_zombie
*/
#include <stdlib.h>
#include <stdio.h>
#include "gameloop.h"
#include "tool.h"
#include "loader.h"

sfTexture *select_texture_zombie(char *str, perso_texture_t *perso)
{
    if (str[0] == '1') {
        if (str[1] == 'A')
            return (perso->zomb_1a.texture);
        if (str[1] == 'B')
            return (perso->zomb_1b.texture);
        if (str[1] == 'C')
            return (perso->zomb_1c.texture);
    }
    return (NULL);
}

sfTexture *select_dead_texture(char *str, perso_texture_t *perso)
{
    if (str[0] == '1') {
        if (str[1] == 'A')
            return (perso->dead_zomb_1a.texture);
        if (str[1] == 'B')
            return (perso->dead_zomb_1b.texture);
        if (str[1] == 'C')
            return (perso->dead_zomb_1c.texture);
    }
    return (NULL);
}

void initialize_zombie_two(char **info, int *i, zombie_t *zombie)
{
    zombie[*i].rect =
            ini_rect(mgetnbr(info[1]) * 20, mgetnbr(info[2]) * 32, 20, 32);
    zombie[*i].move = ini_vector(0, 0);
    sfSprite_setTextureRect(zombie[*i].sprite, zombie[*i].rect);
    zombie[*i].index = 0;
    zombie[*i].skin_x = mgetnbr(info[1]);
    zombie[*i].skin_y = mgetnbr(info[2]) % 2;
    zombie[*i].pos = ini_vectori(mgetnbr(info[3]) * 80, mgetnbr(info[4]) * 80);
    sfSprite_setPosition(zombie[*i].sprite, ini_vector(mgetnbr(info[3]) * 80,
            (mgetnbr(info[4]) - 1) * 80));
    zombie[*i].direction = my_strcpy(info[5]);
    zombie[*i].dificulty = ((float)mgetnbr(info[6])) / 2;
    zombie[*i].scale = mgetnbr(info[7]);;
    if (mgetnbr(info[7]) == 2)
        sfSprite_scale(zombie[*i].sprite, (sfVector2f){1.5, 1.5});
    zombie[*i].alive = TRUE;
    zombie[*i].stat.ad = (int)(((rand() % 2) + 2) * zombie[*i].dificulty);
    zombie[*i].stat.life = (int)(((rand() % 2) + 8) * zombie[*i].dificulty);
    zombie[*i].stat.max_life = zombie[*i].stat.life;
    zombie[*i].stat.ammo = 0;
}

void initialize_zombie(FILE *fd, int *i,
        perso_texture_t *perso, zombie_t *zombie)
{
    char *line = NULL;
    size_t len = 0;
    char **info = NULL;

    if (getline(&line, &len, fd) == -1)
        return;
    info = str_to_word_array(line);
    zombie[*i].sprite = sfSprite_create();
    sfSprite_setTexture(zombie[*i].sprite,
            select_texture_zombie(info[0], perso), sfTrue);
    sfSprite_setScale(zombie[*i].sprite, ini_vector(SCALE, SCALE));
    zombie[*i].clock = sfClock_create();
    zombie[*i].dead_texture = select_dead_texture(info[0], perso);
    initialize_zombie_two(info, i, zombie);
}

int load_zombie(FILE *fd, obj_t *obj, resource_t *resource)
{
    int size = get_size_malloc_obj(fd);

    obj->zombie = malloc(sizeof(zombie_t) * size + 1);
    obj->nb_zombie = size;
    if (obj->zombie == NULL)
        return (84);
    for (int i = 0; i < size; i++) {
        initialize_zombie(fd, &i, &resource->perso, obj->zombie);
        initialize_zombie_life(resource, obj->zombie, &i);
    }
    return (0);
}
