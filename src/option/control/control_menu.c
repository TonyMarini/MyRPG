/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** control_menu
*/

#include "option.h"
#include "tool.h"

static void display_control(window_t win, control_menu_t data, resource_t *r)
{
    sfRenderWindow_clear(win.win, sfBlack);
    display_button(win.win, data.back_button);
    display_button(win.win, data.save_button);
    for (int i = 0 ; i < NB_CONTROL ; i++) {
        sfRenderWindow_drawText(win.win, data.label[i], NULL);
        display_button(win.win, data.button[i]);
    }
    display_cursor(&win, r->cursor);
    sfRenderWindow_display(win.win);
}

static void anim_control(window_t win, control_menu_t *data)
{
    button_is_over(win, &data->back_button);
    button_is_over(win, &data->save_button);
    for (int i = 0 ; i < NB_CONTROL ; i++)
        button_is_over(win, &(data->button[i]));
}

int control_menu(window_t *win, resource_t *resource, option_t *option)
{
    control_menu_t menu_data;

    if (init_control_m(&menu_data, *win, resource, *option) == ERROR)
        return (ERROR);
    menu_data.option = option;
    while (sfRenderWindow_isOpen(win->win)) {
        display_control(*win, menu_data, resource);
        anim_control(*win, &menu_data);
        if (control_menu_event(win, &menu_data) == ERROR)
            return (ERROR);
    }
    return (SUCCESS);
}