/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** load_obj
*/

#include <stdlib.h>
#include <stdio.h>
#include "gameloop.h"
#include "tool.h"
#include "loader.h"

interaction_t **initialize_obj_map(void)
{
    interaction_t **temp = malloc(sizeof(interaction_t *) * 15);

    for (int i = 0; i < 14; i++) {
        temp[i] = malloc(sizeof(interaction_t) * 25);
        for (int ii = 0 ; ii < 25 ; ii++)
            temp[i][ii].link_map = NULL;
    }
    temp[14] = NULL;
    for (int i = 0 ; i < 14 ; i++)
        for (int ii = 0 ; ii < 24 ; ii++)
            temp[i][ii].type = 0;
    return (temp);
}

int get_size_malloc_obj(FILE *fd)
{
    char *line = NULL;
    size_t len = 0;

    if (getline(&line, &len, fd) == -1)
        return (-1);
    return (mgetnbr(line));
}

int load_player_position(obj_t *obj, FILE *fd)
{
    char *line = NULL;
    size_t len = 0;
    char **info = NULL;

    if (getline(&line, &len, fd) == -1)
        return (ERROR);
    info = str_to_word_array(line);
    sfSprite_setPosition(obj->perso.sprite, ini_vector(mgetnbr(info[0]) * 80,
            (mgetnbr(info[1]) - 1) * 80));
    return (0);
}

int select_loader(int select, FILE *fd, obj_t *obj, resource_t *resource)
{
    if (select == 0)
        if (load_player_position(obj, fd) == ERROR)
            return (ERROR);
    if (select == 1)
        if (load_zombie(fd, obj, resource) == ERROR)
            return (ERROR);
    if (select == 2)
        if (load_pnj(fd, obj, resource) == ERROR)
            return (ERROR);
    if (select == 3)
        if (load_link(fd, obj) == ERROR)
            return (ERROR);
    if (select == 4)
        if (load_loot(fd, obj, resource) == ERROR)
            return (ERROR);
    if (select == 5)
        if (is_outdoor(obj, fd) == ERROR)
            return (ERROR);
    return (SUCCESS);
}

int load_obj(obj_t *obj, char *path, resource_t *resource)
{
    FILE *fd = NULL;

    obj->obj_map = initialize_obj_map();
    if ((fd = fopen(path, "r")) == NULL)
        return (ERROR);
    for (int select = 0 ; select < 6 ; select++) {
        if (select_loader(select, fd, obj, resource) == ERROR)
            return (ERROR);
    }
    fclose(fd);
    return (0);
}
