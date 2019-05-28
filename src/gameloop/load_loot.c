/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** load_loot
*/

#include <stdlib.h>
#include "gameloop.h"
#include "tool.h"
#include "loader.h"

static void get_random_stuff(map_data_t *map, int *i)
{
    int item_nb = (rand() % 4) + 1;

    if (map->obj.loot[*i].nb_item != -1)
        return;
    if (item_nb == 1) {
        map->obj.loot[*i].nb_bullet = rand() % 2 + 3;
        return;
    }
    map->obj.loot[*i].nb_item = item_nb;
}

void load_random_stuff(map_data_t *map)
{
    for (int i = 0; i < map->obj.nb_loot; i++)
        get_random_stuff(map, &i);
}

static void initialize_loot_two(int *i,
        loot_t *loot, resource_t *resource)
{
    sfSprite_setTexture(loot[*i].cadre,
            resource->ui_texture.info_key.texture, sfTrue);
    sfSprite_setPosition(loot[*i].cadre,
            (sfVector2f){loot[*i].pos.x + 40, loot[*i].pos.y + 35});
    loot[*i].rect_cadre = ini_rect(0, 0, 66, 22);
    sfSprite_setOrigin(loot[*i].cadre, (sfVector2f){33, 11});
    sfSprite_setTextureRect(loot[*i].cadre, loot[*i].rect_cadre);
    loot[*i].cadre_obj = sfSprite_create();
    sfSprite_setTexture(loot[*i].cadre_obj,
            resource->ui_texture.bg_item.texture, sfTrue);
    sfSprite_setOrigin(loot[*i].cadre_obj, (sfVector2f){0, 55});
    sfSprite_setPosition(loot[*i].cadre_obj,
            (sfVector2f){loot[*i].pos.x, loot[*i].pos.y});
    loot[*i].pos_item = ini_vector(loot[*i].pos.x + 16, loot[*i].pos.y - 60);
}

static void initialize_loot(FILE *fd, int *i,
        loot_t *loot, resource_t *resource)
{
    char *line = NULL;
    size_t len = 0;
    char **info = NULL;

    if (getline(&line, &len, fd) == -1)
        return;
    info = str_to_word_array(line);
    loot[*i].pos = ini_vector(mgetnbr(info[0]) * 80,
            (mgetnbr(info[1]) - 1) * 80);
    loot[*i].pos_tab = ini_vectori(mgetnbr(info[0]), mgetnbr(info[1]) - 1);
    loot[*i].status = 1;
    loot[*i].nb_bullet = -1;
    loot[*i].nb_item = mgetnbr(info[2]);
    loot[*i].clock = sfClock_create();
    loot[*i].cadre = sfSprite_create();
    initialize_loot_two(i, loot, resource);
}

int load_loot(FILE *fd, obj_t *obj, resource_t *resource)
{
    int size = get_size_malloc_obj(fd);

    obj->loot = malloc(sizeof(loot_t) * size + 1);
    obj->nb_loot = size;
    if (obj->loot == NULL)
        return (ERROR);
    for (int i = 0; i < size; i++)
        initialize_loot(fd, &i, obj->loot, resource);
    return (SUCCESS);
}
