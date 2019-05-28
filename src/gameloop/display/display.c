/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** display
*/

#include "gameloop.h"

int display_no_clear(window_t *win, gameloop_data_t *game_data)
{
    map_data_t map = game_data->map;

    sfRenderWindow_setView(win->win, win->view);
    display_map_layer(win, map.layer0, map.w, map.h);
    display_map_layer(win, map.layer1, map.w, map.h);
    display_map_layer(win, map.layer2, map.w, map.h);
    display_map_layer(win, map.layer3, map.w, map.h);
    display_particule(win, game_data);
    display_obj(*win, &(game_data->map.obj));
    display_map_layer(win, map.layer4, map.w, map.h);
    display_map_layer(win, map.layer5, map.w, map.h);
    display_ash_particule(win, game_data);
    display_loot(win, game_data);
    display_mission(win, game_data);
    display_hud(win, game_data->hud);
    return (0);
}

static void display_life_zombie(window_t *win, zombie_t *zombie)
{
    sfVector2f pos = sfSprite_getPosition(zombie->sprite);

    pos.y -= 20;
    sfSprite_setPosition(zombie->life_bar, pos);
    pos.y += 3;
    pos.x += 9;
    sfSprite_setPosition(zombie->live, pos);
    sfRenderWindow_drawSprite(win->win, zombie->life_bar, NULL);
    sfRenderWindow_drawSprite(win->win, zombie->live, NULL);
}

int display_battle(window_t *win, gameloop_data_t *data)
{
    sfRenderWindow_clear(win->win, sfBlack);
    display_no_clear(win, data);
    display_life_zombie(win, &data->map.obj.zombie[data->battle.zombie]);
    display_spell(win, data);
    if (data->battle.blood_particule == 1)
        display_blood_particule(win, data);
    if (data->battle.health_particule == 1)
        display_health_particule(win, data);
    display_cursor(win, data->resource->cursor);
    sfRenderWindow_display(win->win);
    return (SUCCESS);
}

int display(window_t *win, gameloop_data_t *game_data)
{
    sfRenderWindow_clear(win->win, sfBlack);
    display_no_clear(win, game_data);
    display_cursor(win, game_data->resource->cursor);
    sfRenderWindow_display(win->win);
    return (0);
}
