/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** load_map
*/

#include <stdlib.h>
#include "gameloop.h"
#include "loader.h"

static int load_part_2map(sfTexture **tiles, char *path, map_data_t *map_data)
{
    int size = mstrlen(path) - 1;

    path[size] = '2';
    map_data->layer2 = load_layer(path, tiles, &(map_data->w), &(map_data->h));
    if (map_data->layer2 == NULL)
        return (ERROR);
    path[size] = '3';
    map_data->layer3 = load_layer(path, tiles, &(map_data->w), &(map_data->h));
    if (map_data->layer3 == NULL)
        return (ERROR);
    path[size] = '4';
    map_data->layer4 = load_layer(path, tiles, &(map_data->w), &(map_data->h));
    if (map_data->layer4 == NULL)
        return (ERROR);
    path[size] = '5';
    map_data->layer5 = load_layer(path, tiles, &(map_data->w), &(map_data->h));
    if (map_data->layer5 == NULL)
        return (ERROR);
    return (SUCCESS);
}

/*
Create the map with a folder given as arguments and take a array with all
tileset return NULL if failed
*/
int load_map(resource_t *resource, char *map_path, map_data_t *map)
{
    char *path = mstrcat(map_path, "layer0");
    int size = mstrlen(path) - 1;
    char *path2 = mstrcat(map_path, "obj");
    sfTexture **tiles = resource->map_texture;

    if (path == NULL)
        return (ERROR);
    map->layer0 = load_layer(path, tiles, &(map->w), &(map->h));
    if (map->layer0 == NULL)
        return (ERROR);
    path[size] = '1';
    map->layer1 = load_layer(path, tiles, &(map->w), &(map->h));
    if (map->layer1 == NULL)
        return (ERROR);
    if (load_obj(&map->obj, path2, resource) == ERROR)
        return (ERROR);
    load_random_stuff(map);
    return (load_part_2map(tiles, path, map));
}