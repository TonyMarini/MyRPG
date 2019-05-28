/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** event_enter_name
*/

#include <stdio.h>
#include "rpg.h"
#include "main_menu.h"
#include "tool.h"
#include "option.h"

int destroy_enter_name_element(sfText *name,
        sfText *enter_name, sfSprite *sprite, sfSprite *backg)
{
    sfSprite_destroy(sprite);
    sfSprite_destroy(backg);
    sfText_destroy(name);
    sfText_destroy(enter_name);
    return (ERROR);
}

static int get_name(char *name, int *i, sfEvent event)
{
    if (event.key.code == sfKeyEscape)
        return (ERROR);
    if (event.key.code == sfKeyReturn) {
        return (1);
    } else if (event.key.code == sfKeyBack) {
        name[*i] = '\0';
        if (*i != 0)
            (*i)--;
        return (SUCCESS);
    } else {
        if (event.key.code <= 26 && event.key.code != -1)
            name[*i] = event.key.code + 65;
        if (event.key.code <= 26  && event.key.code != -1 && *i < 6)
            (*i)++;
    }
    return (SUCCESS);
}

int enter_name_event(window_t *win, int *i, char *name)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(win->win, &event))
        if (event.type == sfEvtKeyPressed)
            return (get_name(name, i, event));
    return (SUCCESS);
}