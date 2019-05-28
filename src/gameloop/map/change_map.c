/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** change_map
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "gameloop.h"

static sfVector2f get_direction(char dir)
{
    sfVector2f vector = {0, 0};

    dir == 'l' ? vector.x = -1 : vector.x;
    dir == 'r' ? vector.x = 1 : vector.x;
    dir == 'u' ? vector.y = -1 : vector.y;
    dir == 'd' ? vector.y = 1 : vector.y;
    return (vector);
}

static void get_new_pos(window_t *win, char dir, char type, sfVector2f *pos)
{
    static sfVector2f save_pos = {0, 0};

    if (type == 'A') {
        dir == 'l' ? pos->x = win->w - TILE_SCALE : pos->x;
        dir == 'r' ? pos->x = 0 : pos->x;
        dir == 'u' ? pos->y = win->h - TILE_SCALE : pos->y;
        dir == 'd' ? pos->y = 0 : pos->y;
    }
    if (type == 'C')
        *pos = save_pos;
    save_pos = *pos;
}

static char *get_map_path(char *name)
{
    int size = 0;
    char *temp = NULL;
    int index = 0;

    for ( ; name[size] != '\0' ; size++);
    for (int i = 0 ; MAP_FOLDER[i] != '\0' ; i++, size++);
    temp = malloc(sizeof(char) * (size + 2));
    if (temp == NULL)
        return (NULL);
    for ( ; MAP_FOLDER[index] != '\0' ; index++)
        temp[index] = MAP_FOLDER[index];
    for (int i = 0 ; name[i] ; i++, index++)
        temp[index] = name[i];
    temp[index] = '/';
    temp[index + 1] = '\0';
    return (temp);
}

static int make_map(window_t *w, map_data_t *m, interaction_t i, resource_t *r)
{
    char *name = get_map_path(i.link_map);
    map_data_t new_map;
    sfVector2f dir = get_direction(m->obj.perso.direction);
    sfVector2f pos = sfSprite_getPosition(m->obj.perso.sprite);

    if (name == NULL)
        return (ERROR);
    new_map.obj.perso = m->obj.perso;
    if (load_map(r, name, &new_map) == ERROR) {
        mputerror("Error : link map can't be open\n");
        return (ERROR);
    }
    get_new_pos(w, i.link_dir, i.map_spawn, &pos);
    if (i.map_spawn == 'A' || i.map_spawn == 'C')
        sfSprite_setPosition(new_map.obj.perso.sprite, pos);
    map_transition(w, m, &new_map, dir);
    *m = new_map;
    free(name);
    return (SUCCESS);
}

int change_map(window_t *w, perso_t *perso, gameloop_data_t *data)
{
    sfVector2f pos = sfSprite_getPosition(perso->sprite);
    int pos_x = pos.x / TILE_SCALE;
    int pos_y = (pos.y + TILE_SCALE) / TILE_SCALE;
    interaction_t **i = data->map.obj.obj_map;

    if ((int)pos.x % TILE_SCALE != 0 || (int)pos.y % TILE_SCALE != 0)
        return (SUCCESS);
    if (pos_x > 23 || pos_y > 13)
        return (SUCCESS);
    if (i[pos_y][pos_x].link_map != NULL) {
        if (i[pos_y][pos_x].link_dir == perso->direction) {
            hide_particule(data->player_particule);
            return (make_map(w, &data->map, i[pos_y][pos_x], data->resource));
        }
    }
    return (SUCCESS);
}