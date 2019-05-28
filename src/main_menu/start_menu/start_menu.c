/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** start_menu
*/

#include <stdlib.h>
#include "rpg.h"
#include "tool.h"
#include "main_menu.h"

static void menu_config_music(music_data_t *music_data)
{
    for (int i = 0 ; i < NB_MUSIC ; i++)
        music_data->music[i].play = false;
    music_data->music[MUSIC].play = true;
}

int init_start_menu(start_menu_t *data,
        resource_t *texture, window_t win)
{
    ui_texture_t ui = texture->ui_texture;
    sfVector2f pos = ini_vector(win.w / 2, 300);
    sfVector2f bg_pos = pos;

    data->title = set_sprite(ui.title, pos, 1, 1);
    pos.y = win.h / 2 + 60;
    data->play_button = create_button(ui.button, "PLAY", texture->font, 30);
    change_button_pos(&(data->play_button), pos);
    pos.y += 150;
    bg_pos.y = pos.y - 30;
    data->option_button = create_button(ui.button, "OPTION", texture->font,30);
    change_button_pos(&(data->option_button), pos);
    data->bg = set_sprite(ui.bg_menu, bg_pos, 1, 1);
    data->bg_image = sfSprite_create();
    sfSprite_setTexture(data->bg_image, ui.bg_menu_image.texture, sfTrue);
    sfSprite_setPosition(data->bg_image, ini_vector(0, 0));
    pos.y += 80;
    data->quit_button = create_button(ui.button, "QUIT", texture->font, 30);
    change_button_pos(&(data->quit_button), pos);
    return (0);
}

void display_start_menu(window_t *win, start_menu_t *menu_data,
        particule_t *particule, particule_t *a_particule)
{
    sfRenderWindow_clear(win->win, sfBlack);
    sfRenderWindow_drawSprite(win->win, menu_data->bg_image, NULL);
    for (int i = 0; particule[i].sprite; i++)
        sfRenderWindow_drawSprite(win->win, particule[i].sprite, NULL);
    for (int i = 0; a_particule[i].sprite; i++)
        sfRenderWindow_drawSprite(win->win, a_particule[i].sprite, NULL);
    sfRenderWindow_drawSprite(win->win, menu_data->title, NULL);
    sfRenderWindow_drawSprite(win->win, menu_data->bg, NULL);
    display_button(win->win, menu_data->play_button);
    display_button(win->win, menu_data->how_play_button);
    display_button(win->win, menu_data->option_button);
    display_button(win->win, menu_data->quit_button);
    display_cursor(win, menu_data->resource->cursor);
    sfRenderWindow_display(win->win);
}

void anim_menu(window_t win, start_menu_t *menu_data,
        particule_t *particule, particule_t *a_particule)
{
    button_is_over(win, &menu_data->play_button);
    button_is_over(win, &menu_data->how_play_button);
    button_is_over(win, &menu_data->option_button);
    button_is_over(win, &menu_data->quit_button);
    for (int i = 0; particule[i].sprite; i++)
        move_steam_particle(&particule[i]);
    for (int i = 0; a_particule[i].sprite; i++)
        move_ash_particle(&a_particule[i]);
}

int start_menu(window_t *win, resource_t *texture, option_t *option)
{
    start_menu_t menu_data;
    particule_t *particule;
    particule_t *a_particule;

    if (init_start_menu(&menu_data, texture, *win) == ERROR)
        return (ERROR);
    ini_particule_menu(&particule, &a_particule, texture);
    if (init_how_to_play(&menu_data, texture, *win) == ERROR)
        return (ERROR);
    menu_data.resource = texture;
    menu_data.option = option;
    while (sfRenderWindow_isOpen(win->win)) {
        display_start_menu(win, &menu_data, particule, a_particule);
        anim_menu(*win, &menu_data, particule, a_particule);
        start_menu_event(win, &menu_data);
        menu_config_music(&texture->music_data);
        refresh_music(&texture->music_data);
    }
    return (0);
}
