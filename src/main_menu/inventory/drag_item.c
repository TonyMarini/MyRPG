/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** drag_item
*/

#include <stdio.h>
#include "gameloop.h"
#include "main_menu.h"

void drag_item(sfMouseButtonEvent m, gameloop_data_t *data, int index, int t)
{
    int value = t == 0 ? data->inventory.inventory_content[index] :
            data->inventory.spell_content[index];

    if (m.button == sfMouseRight) {
        inv_use_item(data, index, t);
        return;
    }
    if (value == -1)
        return;
    data->inventory.drag_item = value;
    sfSprite_setTexture(data->inventory.drag_sprite,
            data->item[value].texture,
            sfTrue);
    sfSprite_setTextureRect(data->inventory.drag_sprite,
            data->item[value].rect);
    sfSprite_setPosition(data->inventory.drag_sprite, (sfVector2f){m.x, m.y});
    sfSprite_setOrigin(data->inventory.drag_sprite, (sfVector2f){24, 48});
    if (t == 0)
        data->inventory.inventory_content[index] = -1;
    else
        data->inventory.spell_content[index] = -1;
}

void end_of_drag(gameloop_data_t *data, int index, int t)
{
    if (t == 0) {
        if (data->inventory.inventory_content[index] != -1)
            return;
        data->inventory.inventory_content[index] = data->inventory.drag_item;
    } else {
        if (data->inventory.spell_content[index] != -1)
            return;
        data->inventory.spell_content[index] = data->inventory.drag_item;
    }
    load_inventory_content(data);
    data->inventory.drag_item = -1;
}

int start_drag_item(sfMouseButtonEvent m, window_t *w, gameloop_data_t *data)
{
    sfVector2i pos = ini_vectori(m.x, m.y);

    if (data->inventory.drag_item != -1)
        return (SUCCESS);
    for (int i = 0 ; i < 9 ; i++) {
        if (button_is_click(*w, &(data->inventory.bg_inventory[i]), pos)) {
            drag_item(m, data, i, 0);
            update_spell_bar(data, w);
            return (SUCCESS);
        }
    }
    for (int i = 1 ; i < 6 ; i++) {
        if (button_is_click(*w, &(data->battle.spell_button[i]), pos)) {
            drag_item(m, data, i, 1);
            update_spell_bar(data, w);
            return (SUCCESS);
        }
    }
    return (SUCCESS);
}

int move_drag_item(sfMouseMoveEvent mouse, gameloop_data_t *data)
{
    sfSprite_setPosition(data->inventory.drag_sprite,
            (sfVector2f){mouse.x, mouse.y});
    return (SUCCESS);
}

int end_drag_item(sfMouseButtonEvent m, window_t *w, gameloop_data_t *data)
{
    sfVector2i pos = ini_vectori(m.x, m.y);

    if (data->inventory.drag_item == -1)
        return (SUCCESS);
    for (int i = 0 ; i < 9 ; i++) {
        if (button_is_click(*w, &(data->inventory.bg_inventory[i]), pos)) {
            end_of_drag(data, i, 0);
            update_spell_bar(data, w);
            return (SUCCESS);
        }
    }
    for (int i = 1 ; i < 6 ; i++) {
        if (button_is_click(*w, &(data->battle.spell_button[i]), pos)) {
            end_of_drag(data, i,  1);
            update_spell_bar(data, w);
            return (SUCCESS);
        }
    }
    return (SUCCESS);
}