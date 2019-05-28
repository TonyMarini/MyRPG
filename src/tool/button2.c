/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** extension of button.c
*/

#include <stdlib.h>
#include "rpg.h"
#include "tool.h"

int button_is_click(window_t win, button_t *button, sfVector2i pos)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(button->sprite);

    scale_rect(&rect, win.scale);
    if (sfFloatRect_contains(&rect, pos.x, pos.y)) {
        button->rect.top = button->rect.height * 2;
        sfSprite_setTextureRect(button->sprite, button->rect);
        return (1);
    }
    return (0);
}

void change_button_txt(button_t *button, const char *str)
{
    sfFloatRect rect;

    sfText_setString(button->text, str);
    rect = sfText_getLocalBounds(button->text);
    sfText_setOrigin(button->text, ini_vector(rect.width / 2, rect.height));
}