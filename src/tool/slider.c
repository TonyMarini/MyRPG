/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** slider
*/

#include <stdio.h>
#include  "rpg.h"
#include "tool.h"

static void init_slider(slider_t *slider, ui_texture_t t, sfVector2f pos)
{
    sfVector2f size;

    slider->lvl_indi = sfSprite_create();
    sfSprite_setTexture(slider->lvl_indi, t.sound_lvl_indi.texture, sfTrue);
    size = ini_vector(0, t.sound_lvl_indi.h / 2);
    sfSprite_setOrigin(slider->lvl_indi, size);
    sfSprite_setPosition(slider->lvl_indi, pos);
}

slider_t create_slider(ui_texture_t t, sfVector2f pos, int value)
{
    slider_t slider;
    sfVector2f size;

    slider.value = value;
    slider.pos = pos;
    slider.slider_w = t.sound_slider.w;
    slider.bg = sfSprite_create();
    sfSprite_setTexture(slider.bg, t.sound_bar.texture, sfTrue);
    size = ini_vector(t.sound_bar.w / 2, t.sound_bar.h / 2);
    sfSprite_setOrigin(slider.bg, size);
    sfSprite_setPosition(slider.bg, pos);
    slider.slider = sfSprite_create();
    sfSprite_setTexture(slider.slider, t.sound_slider.texture, sfTrue);
    size = ini_vector(0, t.sound_slider.h / 2);
    sfSprite_setOrigin(slider.slider, size);
    slider.min_pos = ini_vector(pos.x - 5 * t.sound_slider.w, pos.y);
    size =  ini_vector(slider.min_pos.x + t.sound_slider.w * value, pos.y);
    sfSprite_setPosition(slider.slider,size);
    init_slider(&slider, t, pos);
    return (slider);
}

void display_slider(sfRenderWindow *win, slider_t slider)
{
    sfRenderWindow_drawSprite(win, slider.bg, NULL);
    sfRenderWindow_drawSprite(win, slider.slider, NULL);
    sfSprite_setPosition(slider.lvl_indi, slider.min_pos);
    for (int i = 0 ; i < slider.value ; i++) {
        sfRenderWindow_drawSprite(win, slider.lvl_indi, NULL);
        sfSprite_move(slider.lvl_indi, ini_vector(slider.slider_w, 0));
    }
}

void move_slider(window_t win, slider_t *slider)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(win.win);
    sfFloatRect rect = sfSprite_getGlobalBounds(slider->bg);
    sfVector2f new_pos;
    int x = 0;

    scale_rect(&rect, win.scale);
    if (sfFloatRect_contains(&rect, pos.x, pos.y)) {
        pos = ini_vectori(pos.x / win.scale, pos.y / win.scale);
        x = ((pos.x - slider->min_pos.x) / slider->slider_w);
        if (x < 0 || x > 9)
            return;
        slider->value = x;
        x *= slider->slider_w;
        new_pos = ini_vector(slider->min_pos.x + x, slider->pos.y);
        sfSprite_setPosition(slider->slider, new_pos);
    }
}