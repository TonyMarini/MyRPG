/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** how_to_play
*/

#include "main_menu.h"

static const char *HP = "resource/how_to_play.png";

int init_how_to_play(start_menu_t *data, resource_t *texture, window_t win)
{
    ui_texture_t ui = texture->ui_texture;
    sfVector2f pos = ini_vector(win.w / 2, 300);

    pos.y = win.h / 2 + 135;
    ui.how_to_play.texture = sfTexture_createFromFile(HP, NULL);
    data->how_to_play = sfSprite_create();
    sfSprite_setTexture(data->how_to_play, ui.how_to_play.texture, sfFalse);
    data->how_play_button =
        create_button(ui.button, "HOW TO PLAY", texture->font, 30);
    change_button_pos(&(data->how_play_button), pos);
    return (SUCCESS);
}

int how_to_play(window_t *win, start_menu_t *data)
{
    int status = 1;

    while (sfRenderWindow_isOpen(win->win) && status == 1) {
        sfRenderWindow_clear(win->win, sfBlack);
        sfRenderWindow_drawSprite(win->win, data->how_to_play, NULL);
        sfRenderWindow_display(win->win);
        if (sfKeyboard_isKeyPressed(sfKeyReturn))
            status = 0;
    }
    return (ERROR);
}