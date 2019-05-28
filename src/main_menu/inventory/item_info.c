/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** item_info
*/

#include <stdlib.h>
#include "gameloop.h"
#include "tool.h"

static void change_info(gameloop_data_t *data, item_t *item)
{
    char *temp = NULL;

    sfText_setString(data->inventory.item_name, item->obj_name);
    set_origin_text(data->inventory.item_name);
    if (data->inventory.description != NULL)
        free(data->inventory.description);
    if (item->damage != -1) {
        temp = mitoa(item->damage);
        data->inventory.description = mstrcat("attack : ", temp);
        free(temp);
    } else {
        temp = mitoa(item->heal);
        data->inventory.description = mstrcat(mstrcat("Heal : +", temp),
                "\n(Right click)");
        free(temp);
    }
    sfText_setString(data->inventory.txt_descript,
            data->inventory.description);
    set_origin_text(data->inventory.txt_descript);
}

static void change_pos(gameloop_data_t *data, sfVector2f pos)
{
    sfSprite_setPosition(data->inventory.item_stat, pos);
    sfText_setPosition(data->inventory.txt_descript,
            (sfVector2f){pos.x, pos.y + 20});
    sfText_setPosition(data->inventory.item_name,
            (sfVector2f){pos.x, pos.y - 20});
}

void update_info_item(window_t *win, gameloop_data_t *data, int index, int t)
{
    int value = t == 0 ? data->inventory.inventory_content[index] :
            data->inventory.spell_content[index];
    sfVector2i pos = sfMouse_getPositionRenderWindow(win->win);

    if (value == -1)
        return;
    pos.y -= 80;
    change_pos(data, (sfVector2f){pos.x, pos.y});
    if (data->inventory.display_info != index)
        change_info(data, &data->item[value]);
    data->inventory.display_info = index;
}