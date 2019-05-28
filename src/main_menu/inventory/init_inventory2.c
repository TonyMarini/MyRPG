/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_inventory2
*/

#include "gameloop.h"
#include "main_menu.h"
#include "tool.h"

static void init_level(gameloop_data_t *data)
{
    data->inventory.nb_level = 1;
    data->inventory.level.title = sfText_create();
    data->inventory.level.act = sfText_create();
    sfText_setFont(data->inventory.level.act, data->resource->font);
    sfText_setFont(data->inventory.level.title, data->resource->font);
    sfText_setCharacterSize(data->inventory.level.title, 20);
    sfText_setCharacterSize(data->inventory.level.act, 20);
    sfText_setString(data->inventory.level.title, "level :   ");
    sfText_setString(data->inventory.level.act,
        mitoa(data->inventory.nb_level));
    sfText_setPosition(data->inventory.level.title, (sfVector2f){665, 540});
    sfText_setPosition(data->inventory.level.act, (sfVector2f){775, 540});
}

static void init_inv_hud(gameloop_data_t *data)
{
    sfVector2f pos = {960, 550};

    data->inventory.bg_inv = set_sprite(
        data->resource->ui_texture.bg_inventory, pos, 1, 1);
    pos.x = 850;
    pos.y = 305;
    data->inventory.fr_inv = set_sprite(
        data->resource->ui_texture.fr_inventory, pos, 1, 1);
    pos = (sfVector2f){700, 270};
    data->inventory.name = sfText_create();
    sfText_setCharacterSize(data->inventory.name, 50);
    sfText_setFont(data->inventory.name, data->resource->font);
    sfText_setString(data->inventory.name, "Inventory");
    sfText_setPosition(data->inventory.name, pos);
}

int init_inventory2(gameloop_data_t *data)
{
    data->inventory.display_info = -1;
    data->inventory.item_stat = sfSprite_create();
    sfSprite_setTexture(data->inventory.item_stat,
            data->resource->ui_texture.bg_info_item.texture, sfTrue);
    sfSprite_setOrigin(data->inventory.item_stat,
            (sfVector2f){data->resource->ui_texture.bg_info_item.w / 2,
            data->resource->ui_texture.bg_info_item.h / 2});
    data->inventory.item_name = sfText_create();
    sfText_setCharacterSize(data->inventory.item_name, 20);
    sfText_setFont(data->inventory.item_name, data->resource->font);
    data->inventory.txt_descript = sfText_create();
    sfText_setCharacterSize(data->inventory.txt_descript, 20);
    sfText_setFont(data->inventory.txt_descript, data->resource->font);
    data->inventory.description = NULL;
    init_level(data);
    init_inv_hud(data);
    return (SUCCESS);
}
