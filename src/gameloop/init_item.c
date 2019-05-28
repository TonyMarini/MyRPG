/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_item
*/

#include <stdlib.h>
#include "rpg.h"
#include "gameloop.h"
#include "loader.h"
#include "option.h"

static item_t load_item_stat(my_texture_t texture,
sfVector2i heal_and_damage, sfIntRect rect, char *name)
{
    item_t item;

    item.sprite = sfSprite_create();
    sfSprite_setTexture(item.sprite, texture.texture, sfTrue);
    sfSprite_setTextureRect(item.sprite, rect);
    item.texture = texture.texture;
    item.rect = rect;
    item.damage = heal_and_damage.x;
    item.heal = heal_and_damage.y;
    item.obj_name = my_strcpy(name);
    return (item);
}

static void init_item_three(gameloop_data_t *data)
{
    data->item[10] = load_item_stat(data->resource->item.item3,
    ini_vectori(1, -1), ini_rect(0, 336, 48, 84), "Herbs");
    data->item[11] = load_item_stat(data->resource->item.item3,
    ini_vectori(1, -1), ini_rect(432, 336, 48, 84), "Brain");
}

static void init_item_two(gameloop_data_t *data)
{
    data->item[5] = load_item_stat(data->resource->item.item2,
    ini_vectori(6, -1), ini_rect(144, 0, 48, 84), "Crowbar");
    data->item[6] = load_item_stat(data->resource->item.item1,
    ini_vectori(8, -1), ini_rect(288, 336, 48, 84), "Axe");
    data->item[7] = load_item_stat(data->resource->item.item1,
    ini_vectori(12, -1), ini_rect(432, 0, 48, 84), "Knife");
    data->item[8] = load_item_stat(data->resource->item.item3,
    ini_vectori(20, -1), ini_rect(432, 0, 48, 84), "Colt M1911");
    data->item[9] = load_item_stat(data->resource->item.item1,
    ini_vectori(25, -1), ini_rect(144, 0, 48, 84), "Deagle");
}

static void init_item_one(gameloop_data_t *data)
{
    data->item[0] = load_item_stat(data->resource->item.item1,
    ini_vectori(3, -1), ini_rect(0, 0, 48, 84), "Baton");
    data->item[1] = load_item_stat(data->resource->item.item3,
    ini_vectori(-1, -1), ini_rect(144, 00, 48, 84), "Ammo");
    data->item[2] = load_item_stat(data->resource->item.item2,
    ini_vectori(-1, 10), ini_rect(432, 336, 48, 84), "Bandage");
    data->item[3] = load_item_stat(data->resource->item.item2,
    ini_vectori(-1, 20), ini_rect(0, 0, 48, 84), "Blood bag");
    data->item[4] = load_item_stat(data->resource->item.item3,
    ini_vectori(-1, 30), ini_rect(0, 0, 48, 84), "Medikit");
}

void init_item(gameloop_data_t *data)
{
    data->resource->space = sfText_create();
    sfText_setFont(data->resource->space, data->resource->font);
    sfText_setString(data->resource->space,
        KEY_NAME[data->option->key.action]);
    sfText_setCharacterSize(data->resource->space, 18);
    init_item_one(data);
    init_item_two(data);
    init_item_three(data);
}
