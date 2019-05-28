/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** change_key_button
*/

#include "option.h"
#include "tool.h"

int change_key_button(window_t w, control_menu_t *menu, int s, sfVector2i pos)
{
    for (int i = 0 ; i < NB_CONTROL ; i++) {
        if (button_is_click(w, &(menu->button[i]), pos) && s == 1) {
            menu->wait_event = i;
            change_button_txt(&(menu->button[i]), "...");
            return (SUCCESS);
        }
    }
    return (SUCCESS);
}