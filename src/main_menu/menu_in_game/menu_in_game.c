/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** menu_in_game
*/

#include "rpg.h"
#include "gameloop.h"
#include "tool.h"
#include "main_menu.h"

int ini_in_game_menu(window_t *win, in_game_menu_t *data, resource_t *resource)
{
    ui_texture_t ui = resource->ui_texture;
    sfVector2f pos = ini_vector(win->w / 2, 300);

    pos.y = win->h / 2 + 100;
    data->resume_button = create_button(ui.button, "RESUME",
            resource->font, 30);
    change_button_pos(&(data->resume_button), pos);
    pos.y += 100;
    data->option_button = create_button(ui.button, "OPTION",
            resource->font, 30);
    change_button_pos(&(data->option_button), pos);
    data->bg = set_sprite(ui.bg_menu, pos, 1, 1);
    pos.y += 100;
    data->quit_button = create_button(ui.button, "QUIT",
            resource->font, 30);
    change_button_pos(&(data->quit_button), pos);
    return (SUCCESS);
}

void display_in_game_menu(window_t *win,
        gameloop_data_t *data, in_game_menu_t *menu)
{
    sfRenderWindow_clear(win->win, sfBlack);
    display_no_clear(win, data);
    sfRenderWindow_drawSprite(win->win, menu->bg, NULL);
    display_button(win->win, menu->resume_button);
    display_button(win->win, menu->option_button);
    display_button(win->win, menu->quit_button);
    display_cursor(win, data->resource->cursor);
    sfRenderWindow_display(win->win);
}

void anim_in_game_menu(window_t *win, in_game_menu_t *menu)
{
    button_is_over(*win, &menu->resume_button);
    button_is_over(*win, &menu->option_button);
    button_is_over(*win, &menu->quit_button);
}

int in_game_menu(window_t *win, gameloop_data_t *data)
{
    in_game_menu_t menu_data;
    int status = 0;

    if (ini_in_game_menu(win, &menu_data, data->resource) == ERROR)
        return (ERROR);
    while (sfRenderWindow_isOpen(win->win)) {
        display_in_game_menu(win, data, &menu_data);
        anim_in_game_menu(win, &menu_data);
        status = in_game_menu_event(win, data, &menu_data);
        if (status == 1)
            return (SUCCESS);
        if (status == 2)
            return (ERROR);
    }
    return (SUCCESS);
}