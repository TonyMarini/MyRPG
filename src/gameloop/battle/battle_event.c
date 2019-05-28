/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** battle_event
*/

#include "gameloop.h"

//  The function to handle the event
int handle_evt(window_t *win, gameloop_data_t *data, int turn, int *status)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(win->win, &event))
    switch (event.type) {
    case sfEvtKeyPressed:
        if (turn == 1 && data->battle.anim == 0)
            return (key_press_battle(event.key, win, data, status));
        break;
    case sfEvtMouseButtonPressed:
        if (turn == 1 && data->battle.anim == 0)
            return (click_spell_attack(event.mouseButton, win, data));
        break;
    default:
        break;
    }
    return (ERROR);
}