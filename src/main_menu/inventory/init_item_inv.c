/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_item_inv
*/

#include <stdio.h>
#include "gameloop.h"

int load_inventory_content(gameloop_data_t *game_data)
{
    item_t *item = game_data->item;
    sfSprite **my_sprite = game_data->inventory.inventory_sprite;
    ui_texture_t ui = game_data->resource->ui_texture;
    sfVector2f pos = {1170, 550};
    sfVector2f current = {pos.x - ui.spell.w - 6, pos.y - ui.spell.h - 6};
    int index = 0;

    for (int i = 0 ; i < 9 ; i++) {
        if (game_data->inventory.inventory_content[i] != -1) {
            index = game_data->inventory.inventory_content[i];
            sfSprite_setTexture(my_sprite[i], item[index].texture, sfTrue);
            sfSprite_setTextureRect(my_sprite[i], item[index].rect);
            sfSprite_setPosition(my_sprite[i], current);
        }
        current.x += ui.spell.w + 6;
        if ((i + 1) % 3 == 0) {
            current.x = pos.x - ui.spell.w - 6;
            current.y = current.y + ui.spell.h + 6;
        }
    }
    return (SUCCESS);
}

int init_item_inv(gameloop_data_t *data)
{
    ui_texture_t ui = data->resource->ui_texture;
    sfFont *font = data->resource->font;
    sfVector2f pos = {1170, 550};
    sfVector2f current = {pos.x - ui.spell.w - 6, pos.y - ui.spell.h - 6};

    data->inventory.cadre_inven = set_sprite(ui.inventory, pos, 1, 1);
    for (int i = 0 ; i < 9 ; i++) {
        data->inventory.bg_inventory[i] = create_button(ui.spell, "", font,35);
        data->inventory.inventory_sprite[i] = sfSprite_create();
        sfSprite_setPosition(data->inventory.inventory_sprite[i], pos);
        sfSprite_setOrigin(data->inventory.inventory_sprite[i],
                (sfVector2f){24, 48});
        change_button_pos(&(data->inventory.bg_inventory[i]), current);
        current.x += ui.spell.w + 6;
        if ((i + 1) % 3 == 0) {
            current.x = pos.x - ui.spell.w - 6;
            current.y = current.y + ui.spell.h + 6;
        }
    }
    data->inventory.drag_sprite = sfSprite_create();
    return (SUCCESS);
}