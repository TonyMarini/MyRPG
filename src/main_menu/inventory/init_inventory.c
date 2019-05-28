/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_inventory
*/

#include <stdio.h>
#include <stdlib.h>
#include "rpg.h"
#include "gameloop.h"
#include "tool.h"
#include "main_menu.h"

static void init_inventory_content(gameloop_data_t *data)
{
    data->inventory.spell_content[0] = 0;
    for (int i = 0; i < 9; i++)
        data->inventory.inventory_content[i] = -1;
    for (int i = 1; i < 6; i++)
        data->inventory.spell_content[i] = -1;
}

int ini_inventory(gameloop_data_t *data)
{
    my_texture_t ui = data->resource->ui_texture.bg_stat;

    data->inventory.font = data->resource->font;
    data->inventory.cadre = sfSprite_create();
    sfSprite_setTexture(data->inventory.cadre, ui.texture, sfTrue);
    sfSprite_setPosition(data->inventory.cadre, ini_vector(750, 550));
    sfSprite_setOrigin(data->inventory.cadre, ini_vector(ui.w / 2, ui.h / 2));
    data->inventory.life = load_statistic_text_inventory(ini_vector(667, 430),
            "life :    /", ini_vectori(data->map.obj.perso.stat.life,
            data->map.obj.perso.stat.max_life), data->inventory.font);
    data->inventory.xp = load_statistic_text_inventory(ini_vector(667, 510),
            "exp :    /", ini_vectori(data->map.obj.perso.stat.xp,
            data->map.obj.perso.stat.max_xp), data->inventory.font);
    data->inventory.ammo = load_statistic_text_inventory(ini_vector(667, 630),
            "ammo :", ini_vectori(data->map.obj.perso.stat.ammo,
            2), data->inventory.font);
    init_icon_inventory(data);
    init_item_inv(data);
    init_inventory_content(data);
    init_inventory2(data);
    return (SUCCESS);
}

stat_text_t load_statistic_text_inventory(sfVector2f pos,
        char *str, sfVector2i act_max, sfFont *font)
{
    stat_text_t st_txt;

    st_txt.act = sfText_create();
    st_txt.title = sfText_create();
    st_txt.max = sfText_create();
    sfText_setFont(st_txt.act, font);
    sfText_setFont(st_txt.title, font);
    sfText_setFont(st_txt.max, font);
    sfText_setCharacterSize(st_txt.act, 20);
    sfText_setCharacterSize(st_txt.max, 20);
    sfText_setCharacterSize(st_txt.title, 20);
    sfText_setString(st_txt.act, mitoa(act_max.x));
    sfText_setString(st_txt.max, mitoa(act_max.y));
    sfText_setString(st_txt.title, str);
    sfText_setPosition(st_txt.title, pos);
    sfText_setPosition(st_txt.act, ini_vector(pos.x + 80, pos.y));
    sfText_setPosition(st_txt.max, ini_vector(pos.x + 130, pos.y));
    return (st_txt);
}

static void load_icon_inv(sfSprite **sprite,
        sfVector2f pos, sfIntRect rect, my_texture_t item)
{
    *sprite = sfSprite_create();
    sfSprite_setTexture(*sprite, item.texture, sfTrue);
    sfSprite_setTextureRect(*sprite, rect);
    sfSprite_setPosition(*sprite, pos);

}

void init_icon_inventory(gameloop_data_t *data)
{
    load_icon_inv(&data->inventory.ammo_icon, ini_vector(615, 595),
            ini_rect(144, 00, 48, 84), data->resource->item.item3);
    load_icon_inv(&data->inventory.xp_icon, ini_vector(615, 495),
            ini_rect(480, 336, 48, 84), data->resource->item.item3);
    load_icon_inv(&data->inventory.life_icon, ini_vector(615, 395),
            ini_rect(0, 0, 48, 84), data->resource->item.item2);
}