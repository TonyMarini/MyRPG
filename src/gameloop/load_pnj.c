/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** load_pnj
*/

#include <stdlib.h>
#include <stdio.h>
#include "gameloop.h"
#include "tool.h"
#include "loader.h"

static sfTexture *select_texture_pnj(char *str, perso_texture_t *perso)
{
    if (str[0] == '1') {
        if (str[1] == 'A')
            return (perso->hum_1a.texture);
        if (str[1] == 'B')
            return (perso->hum_1b.texture);
    }
    return (NULL);
}

char *get_enter(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '%')
            str[i] = '\n';
    return (str);
}

static void initialize_pnj_two(int *i,
        resource_t *resource, pnj_t *pnj, char **info)
{
    pnj[*i].text_start = sfText_create();
    sfText_setFont(pnj[*i].text_start, resource->font);
    sfText_setString(pnj[*i].text_start, get_enter(info[5]));
    pnj[*i].text_end = sfText_create();
    sfText_setFont(pnj[*i].text_end, resource->font);
    sfText_setString(pnj[*i].text_end, get_enter(info[6]));
    pnj[*i].pos_tab = ini_vectori(mgetnbr(info[3]), mgetnbr(info[4]));
    sfText_setPosition(pnj[*i].text_start,
            ini_vector(pnj[*i].pos.x - 112, pnj[*i].pos.y - 145));
    sfText_setPosition(pnj[*i].text_end,
            ini_vector(pnj[*i].pos.x - 112, pnj[*i].pos.y - 145));
    pnj[*i].dial_box = sfSprite_create();
    sfSprite_setTexture(pnj[*i].dial_box,
            resource->ui_texture.dialogue.texture, sfTrue);
    sfSprite_setTextureRect(pnj[*i].dial_box, ini_rect(0, 0, 376, 128));
    sfSprite_setPosition(pnj[*i].dial_box,
            ini_vector(pnj[*i].pos.x - 132, pnj[*i].pos.y - 160));
    pnj[*i].item_reward = mgetnbr(info[9]);
}

static void initialize_pnj(FILE *fd, int *i, resource_t *resource, pnj_t *pnj)
{
    char *line = NULL;
    size_t len = 0;
    char **info = NULL;

    if (getline(&line, &len, fd) == -1)
        return;
    info = str_to_word_array(line);
    pnj[*i].sprite = sfSprite_create();
    sfSprite_setTexture(pnj[*i].sprite,
            select_texture_pnj(info[0], &resource->perso), sfTrue);
    sfSprite_setScale(pnj[*i].sprite, ini_vector(SCALE, SCALE));
    pnj[*i].rect = ini_rect(mgetnbr(info[1]) * 16,
            mgetnbr(info[2]) * 32, 16, 32);
    sfSprite_setTextureRect(pnj[*i].sprite, pnj[*i].rect);
    pnj[*i].pos = ini_vector(mgetnbr(info[3]) * 80,
            (mgetnbr(info[4]) - 1) * 80);
    sfSprite_setPosition(pnj[*i].sprite, pnj[*i].pos);
    pnj[*i].mission = mgetnbr(info[7]);
    pnj[*i].item_req = mgetnbr(info[8]);
    initialize_pnj_two(i, resource, pnj, info);
}

int load_pnj(FILE *fd, obj_t *obj, resource_t *resource)
{
    int size = get_size_malloc_obj(fd);

    obj->pnj = malloc(sizeof(zombie_t) * size + 1);
    obj->nb_pnj = size;
    if (obj->pnj == NULL)
        return (84);
    for (int i = 0; i < size; i++)
        initialize_pnj(fd, &i, resource, obj->pnj);
    return (0);
}
