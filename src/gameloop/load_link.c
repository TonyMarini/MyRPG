/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** load_link
*/

#include <stdlib.h>
#include <stdio.h>
#include "gameloop.h"
#include "loader.h"

static int load_current_link(interaction_t **inter, char *line)
{
    char **value = NULL;
    int x;
    int y;

    value = str_to_word_array(line);
    if (value == NULL)
        return (ERROR);
    x = mgetnbr(value[1]);
    y = mgetnbr(value[2]);
    inter[y][x].map_spawn = value[0][0];
    inter[y][x].link_dir = value[3][0];
    inter[y][x].link_map = my_strcpy(value[4]);
    for (int i = 0 ; value[i] ; i++)
        free(value[i]);
    free(value);
    return (SUCCESS);
}

int load_link(FILE *fd, obj_t *objet)
{
    int size = get_size_malloc_obj(fd);
    char *line = NULL;
    size_t len = 0;
    size_t read = 0;

    for (int i = 0 ; i < size && (read = getline(&line, &len, fd)) > 0 ; i++) {
        line[read - 1] == '\n' ? line[read - 1] = '\0' : read;
        load_current_link(objet->obj_map, line);
    }
    free(line);
    return (SUCCESS);
}