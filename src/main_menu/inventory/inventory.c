/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** inventory
*/

#include <stdio.h>
#include "rpg.h"
#include "gameloop.h"
#include "tool.h"
#include "main_menu.h"

static void anim_inventory(window_t *win, gameloop_data_t *data)
{
    for (int i = 0 ; i < 9 ; i++) {
        if (button_is_over(*win, &(data->inventory.bg_inventory[i]))) {
            update_info_item(win, data, i, 0);
            return;
        }
    }
    for (int i = 0 ; i < 6 ; i++) {
        if (button_is_over(*win, &(data->battle.spell_button[i]))) {
            update_info_item(win, data, i, 1);
            return;
        }
    }
    data->inventory.display_info = -1;
}

static void act_ammo(gameloop_data_t *data)
{
    sfText_setString(data->inventory.ammo.act,
            mitoa(data->map.obj.perso.stat.ammo));
}

int inventory(window_t *win, gameloop_data_t *data)
{
    int status = 0;

    act_ammo(data);
    load_inventory_content(data);
    update_spell_bar(data, win);
    data->inventory.drag_item = -1;
    while (sfRenderWindow_isOpen(win->win) && status == 0) {
        display_inventory(win, data);
        anim_inventory(win, data);
        status = inventory_event(win, data);
    }
    return (SUCCESS);
}