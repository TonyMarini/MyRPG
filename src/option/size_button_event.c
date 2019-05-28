/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** size_button_event
*/

#include <stdio.h>
#include "option.h"
#include "tool.h"

static void update_selector(option_menu_t *menu)
{
    my_texture_t selector = menu->resource->ui_texture.selector;
    sfIntRect unselect_rect = ini_rect(0, 0, selector.w, selector.h);
    sfIntRect select_rect = ini_rect(0, selector.h, selector.w, selector.h);

    for (int i = 0 ; i < 6 ; i++) {
        if (i == menu->option->select_size)
            sfSprite_setTextureRect(menu->selector[i], select_rect);
        else
            sfSprite_setTextureRect(menu->selector[i], unselect_rect);
    }
}

int size_button_event(window_t *w, sfVector2i pos, option_menu_t *menu, int s)
{
    int status = 0;

    for (int i = 0 ; i < 6 ; i++) {
        if (button_is_click(*w, &(menu->size_button[i]), pos) && s == 1) {
            change_window_size(w, menu->option, i, menu->option->fullscreen);
            update_selector(menu);
            return (SUCCESS);
        }
    }
    if (checkbox_is_click(*w, &(menu->fscreen_box), pos) && s == 1) {
        checkbox_update(&menu->fscreen_box, !menu->fscreen_box.status);
        status =  menu->fscreen_box.status;
        change_window_size(w, menu->option, menu->option->select_size, status);
    }
    return (0);
}