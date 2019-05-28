/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** load_map
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "rpg.h"
#include "gameloop.h"
#include "tool.h"

/*
Generate one sprite of the map
*/
map_sprite_t create_map_sprite
(sfTexture *texture, sfVector2f pos, int i, char *line)
{
    map_sprite_t map;
    sfIntRect rect;
    char x = line[i+1], y = line[i+2];

    map.sprite = NULL;
    if (line[i] == 'A' && line[i+1] == 's' && line[i+2] == 'u')
        return (map);
    x >= 'a' && x <= 'z' ? x += 00 - 'a' : x;
    x >= '0' && x <= '9' ? x += 26 - '0' : x;
    x >= 'A' && x <= 'Z' ? x += 36 - 'A' : x;
    y >= 'a' && y <= 'z' ? y += 00 - 'a' : y;
    y >= '0' && y <= '9' ? y += 26 - '0' : y;
    y >= 'A' && y <= 'Z' ? y += 36 - 'A' : y;
    map.sprite = sfSprite_create();
    sfSprite_setTexture(map.sprite, texture, sfTrue);
    rect = ini_rect(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE);
    sfSprite_setTextureRect(map.sprite, rect);
    sfSprite_setScale(map.sprite, ini_vector(SCALE, SCALE));
    sfSprite_setPosition(map.sprite, pos);
    return (map);
}

/*
Generate one line of the layer
return NULL if failed
*/
map_sprite_t *load_line(char *line, sfTexture **t, sfVector2f pos, int *w)
{
    map_sprite_t *map = NULL;
    int size = 0;
    int index = 0;
    map_sprite_t temp;

    size = mstrlen(line);
    line[--size] == '\n' ? size : size++;
    size /= 3;
    if ((map = malloc(sizeof(map_sprite_t) + (size + 1) * 1000)) == NULL)
        return (NULL);
    temp.sprite = NULL;
    map[size] = temp;
    for (int i = 0 ; line[i] != '\0' && line[i] != '\n' ; i+= 3 ,index++) {
        map[index] = create_map_sprite(t[line[i] - 'A'], pos, i, line);
        pos.x += TILE_SCALE;
    }
    *w = index;
    return (map);
}

/*
count the number of line in one file
return ERROR if failed
*/
int get_map_size(char *path, int *height)
{
    char *line = NULL;
    FILE *fd = NULL;
    size_t len = 0;
    int size = 0;

    if ((fd = fopen(path, "r")) == NULL)
        return (ERROR);
    while (getline(&line, &len, fd) != -1)
        size++;
    if (fclose(fd) != 0)
        return (ERROR);
    *height = size;
    return (SUCCESS);
}

/*
load a layer of the map with the filapth given as arguements
return NULL if failed
*/
map_sprite_t **load_layer(char *path, sfTexture **texture, int *w, int *h)
{
    map_sprite_t **map = NULL;
    char *line = NULL;
    FILE *fd = NULL;
    size_t len = 0;
    sfVector2f pos = ini_vector(0, 0);

    if (get_map_size(path, h) == ERROR)
        return (NULL);
    if ((map = malloc(sizeof(map_sprite_t*) * (*h + 1))) == NULL)
        return (NULL);
    if ((fd = fopen(path, "r")) == NULL)
        return (NULL);
    map[*h] = NULL;
    for (int i = 0 ; getline(&line, &len, fd) != -1; i += 1) {
        map[i] = load_line(line, texture, pos, w);
        pos.y += TILE_SCALE;
    }
    if (fclose(fd) != 0)
        return (NULL);
    return (map);
}
