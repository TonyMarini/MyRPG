/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** load_obj2
*/

#include <stdlib.h>
#include <stdio.h>
#include "gameloop.h"
#include "tool.h"
#include "loader.h"

int is_outdoor(obj_t *obj, FILE *fd)
{

    char *line = NULL;
    size_t len = 0;

    if (getline(&line, &len, fd) == -1)
        return (ERROR);
    obj->is_outdoor = mgetnbr(line);
    return (SUCCESS);
}