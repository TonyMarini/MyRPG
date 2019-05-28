/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** check_loot
*/

#include <stdlib.h>
#include "rpg.h"
#include "gameloop.h"
#include "tool.h"
#include "main_menu.h"

void display_loot_order(window_t *win, gameloop_data_t *data, int *i)
{
    sfRenderWindow_drawSprite(win->win,
            data->map.obj.loot[*i].cadre_obj, NULL);
    sfText_setPosition(data->resource->space,
            (sfVector2f){data->map.obj.loot[*i].pos.x + 9,
            data->map.obj.loot[*i].pos.y + 27});
    sfRenderWindow_drawSprite(win->win,
            data->map.obj.loot[*i].cadre, NULL);
    if (data->map.obj.loot[*i].nb_item == -1) {
        sfSprite_setPosition(data->item[1].sprite,
                data->map.obj.loot[*i].pos_item);
        sfRenderWindow_drawSprite(win->win, data->item[1].sprite, NULL);
    } else {
        sfSprite_setPosition(
                data->item[data->map.obj.loot[*i].nb_item].sprite,
                data->map.obj.loot[*i].pos_item);
        sfRenderWindow_drawSprite(win->win,
                data->item[data->map.obj.loot[*i].nb_item].sprite, NULL);
    }
    sfRenderWindow_drawText(win->win, data->resource->space, NULL);
}

void display_loot(window_t *win, gameloop_data_t *data)
{
    sfVector2f pos = sfSprite_getPosition(data->map.obj.perso.sprite);
    int space_x = 0;
    int space_y = 0;
    int pos_x = pos.x / TILE_SCALE;
    int pos_y = (pos.y + TILE_SCALE) / TILE_SCALE;

    for (int i = 0; i < data->map.obj.nb_loot; i++) {
        space_x = pos_x - data->map.obj.loot[i].pos_tab.x;
        space_y = pos_y - data->map.obj.loot[i].pos_tab.y;
        if (space_x > -2 && space_x < 2 && space_y > -2 && space_y < 2
            && data->map.obj.loot[i].status == 1)
            display_loot_order(win, data, &i);
    }
}

static void get_stuff(gameloop_data_t *data, int *i)
{
    int j = 0;

    if (data->map.obj.loot[*i].nb_bullet != -1) {
        data->map.obj.perso.stat.ammo += data->map.obj.loot[*i].nb_bullet;
        return;
    }
    while (j < 9 && data->inventory.inventory_content[j] != -1)
        j++;
    if (j == 9)
        return;
    data->inventory.inventory_content[j] = data->map.obj.loot[*i].nb_item;
}

void get_loot(gameloop_data_t *data)
{
    sfVector2f pos = sfSprite_getPosition(data->map.obj.perso.sprite);
    int space_x = 0;
    int space_y = 0;
    int pos_x = pos.x / TILE_SCALE;
    int pos_y = (pos.y + TILE_SCALE) / TILE_SCALE;

    for (int i = 0; i < data->map.obj.nb_loot; i++) {
        space_x = pos_x - data->map.obj.loot[i].pos_tab.x;
        space_y = pos_y - data->map.obj.loot[i].pos_tab.y;
        if (space_x > -2 && space_x < 2 && space_y > -2 && space_y < 2
            && data->map.obj.loot[i].status == 1) {
                data->map.obj.loot[i].status = 0;
                get_stuff(data, &i);
        }
    }
}
