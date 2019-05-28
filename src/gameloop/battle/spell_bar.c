/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** spell_bar
*/

#include "gameloop.h"

int update_spell_bar(gameloop_data_t *data, window_t *win)
{
    int index = 0;
    sfVector2f pos = ini_vector(win->w / 2, win->h - 120);
    ui_texture_t ui = data->resource->ui_texture;
    sfVector2f current = {pos.x - (ui.spell.w * 3) + 36, pos.y};

    for (int i = 0 ; i < 6 ; i++) {
        if (data->inventory.spell_content[i] != -1) {
            index = data->inventory.spell_content[i];
            sfSprite_setTexture(data->battle.content_sprite[i],
                    data->item[index].texture, sfTrue);
            sfSprite_setTextureRect(data->battle.content_sprite[i],
                    data->item[index].rect);
            sfSprite_setPosition(data->battle.content_sprite[i], current);
        }
        current.x += ui.spell.w + 6;;
    }
    return (SUCCESS);
}