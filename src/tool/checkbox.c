/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** checkbox
*/

#include <stdio.h>
#include "rpg.h"
#include "tool.h"

checkbox_t create_chbox(my_texture_t bg, char *str, sfFont *f, sfVector2f p)
{
    checkbox_t box;
    sfFloatRect size;

    box.status = 0;
    box.box = sfSprite_create();
    box.rect = ini_rect(0, 0, bg.w, bg.h);
    sfSprite_setTexture(box.box, bg.texture, sfTrue);
    sfSprite_setTextureRect(box.box, box.rect);
    sfSprite_setOrigin(box.box, ini_vector(0, bg.h / 2));
    box.text = sfText_create();
    sfText_setColor(box.text, sfWhite);
    sfText_setFont(box.text, f);
    sfText_setString(box.text, str);
    sfText_setCharacterSize(box.text, 20);
    size = sfText_getLocalBounds(box.text);
    sfText_setOrigin(box.text, ini_vector(0, size.height));
    p.x -= (bg.w + 8 + size.width) / 2;
    sfSprite_setPosition(box.box, p);
    p.x += bg.w + 8;
    sfText_setPosition(box.text, p);
    return (box);
}

void checkbox_update(checkbox_t *box, int new_value)
{
    box->status = new_value;
    box->rect.top = new_value * box->rect.height * 2;
    sfSprite_setTextureRect(box->box, box->rect);
}

void display_checkbox(sfRenderWindow *win, checkbox_t box)
{
    sfRenderWindow_drawSprite(win, box.box, NULL);
    sfRenderWindow_drawText(win, box.text, NULL);
}

void checkbox_is_over(window_t win, checkbox_t *box)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(win.win);
    sfFloatRect rect = sfSprite_getGlobalBounds(box->box);

    scale_rect(&rect, win.scale);
    if (sfFloatRect_contains(&rect, pos.x, pos.y)) {
        box->rect.top = box->rect.height * (box->status * 2 + 1);
        sfSprite_setTextureRect(box->box, box->rect);
    } else {
        box->rect.top = box->rect.height * box->status * 2;
        sfSprite_setTextureRect(box->box, box->rect);
    }
}

int checkbox_is_click(window_t win, checkbox_t*box, sfVector2i pos)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(box->box);

    scale_rect(&rect, win.scale);
    if (sfFloatRect_contains(&rect, pos.x, pos.y)) {
        return (1);
    }
    return (0);
}