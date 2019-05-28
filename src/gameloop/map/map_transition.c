/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** map_transition
*/

#include <stdio.h>
#include "gameloop.h"

static void init_transition(map_data_t *map, sfVector2f dir)
{
    sfVector2f pos = {dir.x * 1920, dir.y * 1080};

    move_map_layer(map->layer1,map->w, map->h, pos);
    move_map_layer(map->layer5,map->w, map->h, pos);
    move_map_layer(map->layer2,map->w, map->h, pos);
    move_map_layer(map->layer3,map->w, map->h, pos);
    move_map_layer(map->layer4,map->w, map->h, pos);
    move_map_layer(map->layer0,map->w, map->h, pos);
}

static void transition_display(window_t *win,  map_data_t *o, map_data_t *n)
{
    sfRenderWindow_clear(win->win, sfBlack);
    display_map_layer(win, o->layer0, o->w, o->h);
    display_map_layer(win, o->layer1, o->w, o->h);
    display_map_layer(win, o->layer2, o->w, o->h);
    display_map_layer(win, o->layer3, o->w, o->h);
    display_map_layer(win, o->layer4, o->w, o->h);
    display_map_layer(win, o->layer5, o->w, o->h);
    display_map_layer(win, n->layer0, o->w, o->h);
    display_map_layer(win, n->layer1, o->w, o->h);
    display_map_layer(win, n->layer2, o->w, o->h);
    display_map_layer(win, n->layer3, o->w, o->h);
    display_map_layer(win, n->layer4, o->w, o->h);
    display_map_layer(win, n->layer5, o->w, o->h);
    sfRenderWindow_display(win->win);
}

static void move_map(map_data_t *o, map_data_t *n, sfVector2f d)
{
    sfVector2f pos = {d.x * -30, d.y * -30};

    move_map_layer(o->layer0,o->w, o->h, pos);
    move_map_layer(o->layer1,o->w, o->h, pos);
    move_map_layer(o->layer2,o->w, o->h, pos);
    move_map_layer(o->layer3,o->w, o->h, pos);
    move_map_layer(o->layer4,o->w, o->h, pos);
    move_map_layer(o->layer5,o->w, o->h, pos);
    move_map_layer(n->layer0,o->w, o->h, pos);
    move_map_layer(n->layer1,o->w, o->h, pos);
    move_map_layer(n->layer2,o->w, o->h, pos);
    move_map_layer(n->layer3,o->w, o->h, pos);
    move_map_layer(n->layer4,o->w, o->h, pos);
    move_map_layer(n->layer5,o->w, o->h, pos);
}

static int anim_ended(map_data_t *new)
{
    sfVector2f pos = sfSprite_getPosition(new->layer0[0][0].sprite);

    if (pos.x == 0 && pos.y == 0)
        return (SUCCESS);
    return (ERROR);
}

int map_transition(window_t *w, map_data_t *old, map_data_t *n, sfVector2f d)
{
    init_transition(n, d);
    sfClock *clock = sfClock_create();

    if (clock == NULL)
        return (ERROR);
    while (sfRenderWindow_isOpen(w->win)) {
        move_map(old, n, d);
        transition_display(w, old, n);
        if (anim_ended(n) == SUCCESS)
            break;
    }
    sfClock_destroy(clock);
    return (SUCCESS);
}