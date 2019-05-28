/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_get_char
*/

#include "gameloop.h"

static void init_part2(resource_t *r, get_player_t *data)
{
    sfVector2f pos = {820, 800};

    data->back = create_button(r->ui_texture.button, "Back",
        r->font, 25);
    change_button_pos(&data->back, pos);
    pos = (sfVector2f){1100, 800};
    data->start = create_button(r->ui_texture.button, "Next",
        r->font, 25);
    change_button_pos(&data->start, pos);
}

int init_get_character(resource_t *r, get_player_t *data, sfVector2i p)
{
    sfVector2f pos = {0, 0};

    data->background = set_sprite(r->ui_texture.bg_option_image,
        pos, 1, 0);
    pos = (sfVector2f){770, 540};
    data->prev = create_button(r->ui_texture.button3, "<-",
        r->font, 35);
    change_button_pos(&data->prev, pos);
    pos = (sfVector2f){1150, 540};
    data->next = create_button(r->ui_texture.button3, "->",
        r->font, 35);
    change_button_pos(&data->next, pos);
    pos = (sfVector2f){960, 540};
    data->perso = set_sprite(r->perso.hum_3a, pos, 10, 1);
    sfSprite_setTextureRect(data->perso, (sfIntRect){(p.x + 1) * 16,
        p.y * 32, 16, 32});
    sfSprite_setOrigin(data->perso, (sfVector2f){8, 16});
    data->pos_x = p.x;
    data->pos_y = p.y;
    init_part2(r, data);
    return (SUCCESS);
}