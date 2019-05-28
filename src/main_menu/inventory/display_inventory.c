/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** display_inventory
*/

#include "gameloop.h"

static void display_bg_inventory(window_t *win, gameloop_data_t *data)
{
    sfRenderWindow_drawSprite(win->win, data->inventory.bg_inv, NULL);
    sfRenderWindow_drawSprite(win->win, data->inventory.fr_inv, NULL);
    sfRenderWindow_drawText(win->win, data->inventory.name, NULL);
}

static void display_inventory2(window_t *win, gameloop_data_t *data)
{
    for (int i = 0 ; i < 9 ; i++) {
        display_button(win->win, data->inventory.bg_inventory[i]);
        if (data->inventory.inventory_content[i] != -1)
            sfRenderWindow_drawSprite(win->win,
                    data->inventory.inventory_sprite[i], NULL);
    }
    display_spell(win, data);
    if (data->inventory.drag_item != -1)
        sfRenderWindow_drawSprite(win->win, data->inventory.drag_sprite, NULL);
    if (data->inventory.display_info != -1) {
        sfRenderWindow_drawSprite(win->win, data->inventory.item_stat, NULL);
        sfRenderWindow_drawText(win->win, data->inventory.item_name, NULL);
        sfRenderWindow_drawText(win->win, data->inventory.txt_descript, NULL);
    }
}

void display_inventory(window_t *win, gameloop_data_t *data)
{
    sfRenderWindow_clear(win->win, sfBlack);
    display_no_clear(win, data);
    display_bg_inventory(win, data);
    sfRenderWindow_drawSprite(win->win, data->inventory.cadre, NULL);
    sfRenderWindow_drawSprite(win->win, data->inventory.life_icon, NULL);
    sfRenderWindow_drawSprite(win->win, data->inventory.xp_icon, NULL);
    sfRenderWindow_drawSprite(win->win, data->inventory.ammo_icon, NULL);
    sfRenderWindow_drawText(win->win, data->inventory.life.act, NULL);
    sfRenderWindow_drawText(win->win, data->inventory.life.max, NULL);
    sfRenderWindow_drawText(win->win, data->inventory.life.title, NULL);
    sfRenderWindow_drawText(win->win, data->inventory.ammo.act, NULL);
    sfRenderWindow_drawText(win->win, data->inventory.ammo.title, NULL);
    sfRenderWindow_drawText(win->win, data->inventory.xp.act, NULL);
    sfRenderWindow_drawText(win->win, data->inventory.xp.max, NULL);
    sfRenderWindow_drawText(win->win, data->inventory.xp.title, NULL);
    sfRenderWindow_drawText(win->win, data->inventory.level.title, NULL);
    sfRenderWindow_drawText(win->win, data->inventory.level.act, NULL);
    sfRenderWindow_drawSprite(win->win, data->inventory.cadre_inven, NULL);
    display_inventory2(win, data);
    display_cursor(win, data->resource->cursor);
    sfRenderWindow_display(win->win);
}