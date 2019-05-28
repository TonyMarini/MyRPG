/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** button
*/

#include <stdio.h>
#include <stdlib.h>
#include "rpg.h"
#include "tool.h"

button_t create_button(my_texture_t bg, const char *str, sfFont *font, int f)
{
    button_t button;
    sfFloatRect rect;

    button.sprite = sfSprite_create();
    button.text = sfText_create();
    button.rect = ini_rect(0, 0, bg.w, bg.h);
    sfSprite_setTexture(button.sprite, bg.texture, sfTrue);
    sfSprite_setTextureRect(button.sprite, button.rect);
    sfSprite_setOrigin(button.sprite, ini_vector(bg.w / 2, bg.h / 2));
    sfText_setColor(button.text, sfWhite);
    sfText_setFont(button.text, font);
    sfText_setString(button.text, str);
    sfText_setCharacterSize(button.text, f);
    rect = sfText_getLocalBounds(button.text);
    sfText_setOrigin(button.text, ini_vector(rect.width/2, rect.height));
    return (button);
}

void change_button_pos(button_t *button, sfVector2f pos)
{
    sfSprite_setPosition(button->sprite, pos);
    sfText_setPosition(button->text, pos);
}

void display_button(sfRenderWindow *win, button_t button)
{
    sfRenderWindow_drawSprite(win, button.sprite, NULL);
    sfRenderWindow_drawText(win, button.text, NULL);
}

int button_is_over(window_t win, button_t *button)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(win.win);
    sfFloatRect rect = sfSprite_getGlobalBounds(button->sprite);

    scale_rect(&rect, win.scale);
    if (sfFloatRect_contains(&rect, pos.x, pos.y)) {
        if (button->rect.top != button->rect.height * 2)
            button->rect.top = button->rect.height;
        sfSprite_setTextureRect(button->sprite, button->rect);
        return (1);
    } else {
        button->rect.top = 0;
        sfSprite_setTextureRect(button->sprite, button->rect);
        return (0);
    }
}

void free_button(button_t button)
{
    sfText_destroy(button.text);
    sfSprite_destroy(button.sprite);
}