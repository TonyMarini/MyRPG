/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** enter_name
*/

#include <stdio.h>
#include "rpg.h"
#include "main_menu.h"
#include "tool.h"
#include "option.h"

static void display_enter_name(window_t *win,
        sfText *name, sfText *enter_name, start_menu_t *menu)
{
    sfRenderWindow_drawText(win->win, enter_name, NULL);
    sfRenderWindow_drawText(win->win, name, NULL);
    display_cursor(win, menu->resource->cursor);
    sfRenderWindow_display(win->win);
}

static void init_name_text(sfText *name,
        sfText *enter_name, start_menu_t *menu)
{
    sfText_setFont(name, menu->resource->font);
    sfText_setPosition(name, ini_vector(870, 500));
    sfText_setFont(enter_name, menu->resource->font);
    sfText_setPosition(enter_name, ini_vector(800, 460));
    sfText_setString(enter_name, "Enter your name :");
}

static void clean_win_and_set_name(window_t *win, char *name, sfText *text)
{
    sfText_setString(text, name);
    sfRenderWindow_clear(win->win, sfBlack);
}

static void display_bg_enter_name(window_t *win,
        sfSprite *backg, sfSprite *sprite)
{
    sfRenderWindow_drawSprite(win->win, backg, NULL);
    sfRenderWindow_drawSprite(win->win, sprite, NULL);
}

int enter_name(window_t *win, char *name, start_menu_t *menu)
{
    sfText *text = sfText_create();
    sfText *enter_name = sfText_create();
    int i = 0;
    int status = 0;
    sfSprite *sprite = set_sprite(menu->resource->ui_texture.dialogue,
            ini_vector(950, 500), 1, 1);
    sfSprite *backg = set_sprite(menu->resource->ui_texture.bg_option_image,
            ini_vector(960, 540), 1, 1);

    init_name_text(text, enter_name, menu);
    while (sfRenderWindow_isOpen(win->win) && status == 0) {
        clean_win_and_set_name(win, name, text);
        display_bg_enter_name(win, backg, sprite);
        display_enter_name(win, text, enter_name, menu);
        if ((status = enter_name_event(win, &i, name)) == ERROR)
            return (destroy_enter_name_element(text,
                    enter_name, sprite, backg));
    }
    destroy_enter_name_element(text, enter_name, sprite, backg);
    return (SUCCESS);
}