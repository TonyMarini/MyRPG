/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_sprite_battle
*/

#include "gameloop.h"

//  Init the spell bar and the button on it
int init_sprite_battle(gameloop_data_t *data, window_t *win)
{
    sfVector2f pos = ini_vector(win->w / 2, win->h - 120);
    ui_texture_t ui = data->resource->ui_texture;
    sfVector2f current = {pos.x - (ui.spell.w * 3) + 36, pos.y};

    data->battle.spell_sprite =
        set_sprite(data->resource->ui_texture.spell_bar, pos, 1, 1);
    for (int i = 0; i < 6; i++) {
        data->battle.spell_button[i] =
            create_button(ui.spell, "", NULL, 35);
        change_button_pos(&(data->battle.spell_button[i]), current);
        data->battle.content_sprite[i] = sfSprite_create();
        sfSprite_setOrigin(data->battle.content_sprite[i],
                (sfVector2f){24, 48});
        current.x += ui.spell.w + 6;
    }
    update_spell_bar(data, win);
    data->battle.status_battle = -1;
    data->battle.anim = 0;
    data->battle.anim_clock = sfClock_create();
    return (SUCCESS);
}