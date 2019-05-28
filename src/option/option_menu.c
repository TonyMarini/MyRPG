/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** option
*/

#include <stdio.h>
#include "rpg.h"
#include "option.h"
#include "tool.h"

static void display_option(option_menu_t *menu,
        window_t *win, sfSprite *screen)
{
    sfRenderWindow_clear(win->win, sfBlack);
    if (screen != NULL)
        sfRenderWindow_drawSprite(win->win, screen, NULL);
    sfRenderWindow_drawSprite(win->win, menu->bg_sprite, NULL);
    sfRenderWindow_drawText(win->win, menu->text_music, NULL);
    sfRenderWindow_drawText(win->win, menu->text_sound, NULL);
    display_button(win->win, menu->back_button);
    display_button(win->win, menu->save_button);
    display_button(win->win, menu->control_button);
    for (int i = 0 ; i < 6 ; i++) {
        display_button(win->win, menu->size_button[i]);
        sfRenderWindow_drawSprite(win->win, menu->selector[i], NULL);
    }
    display_checkbox(win->win, menu->fscreen_box);
    display_slider(win->win, menu->sound_slider);
    display_checkbox(win->win, menu->mute_sound);
    display_slider(win->win, menu->music_slider);
    display_checkbox(win->win, menu->mute_music);
    display_cursor(win, menu->resource->cursor);
    sfRenderWindow_display(win->win);
}

static void anim_option(window_t *win, option_menu_t *menu)
{
    button_is_over(*win, &menu->back_button);
    button_is_over(*win, &menu->save_button);
    button_is_over(*win, &menu->control_button);
    for (int i = 0 ; i < 6 ; i++)
        button_is_over(*win, &(menu->size_button[i]));
    checkbox_is_over(*win, &menu->fscreen_box);
    checkbox_is_over(*win, &menu->mute_sound);
    checkbox_is_over(*win, &menu->mute_music);
}

int option_menu(window_t *window, resource_t *resource, option_t *option)
{
    option_menu_t menu_data;
    sfSprite *backg = set_sprite(resource->ui_texture.bg_option_image,
            ini_vector(960, 540), 1, 1);

    menu_data.resource = resource;
    menu_data.option = option;
    menu_data.save_option = *option;
    menu_data.music = &resource->music_data;
    if (init_option(&menu_data, resource, *window) == ERROR)
        return (ERROR);
    while (sfRenderWindow_isOpen(window->win)) {
        anim_option(window, &menu_data);
        display_option(&menu_data, window, backg);
        load_music_option(&resource->music_data, option);
        refresh_music(&resource->music_data);
        if (option_menu_event(window, &menu_data) == ERROR)
            break;
    }
    sfSprite_destroy(backg);
    return (SUCCESS);
}
