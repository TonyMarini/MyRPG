/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** display the hud
*/

#include "gameloop.h"

void display_spell(window_t *win, gameloop_data_t *data)
{
    sfRenderWindow_drawSprite(win->win, data->battle.spell_sprite, NULL);
    for (int i = 0; i < 6; i++) {
        sfRenderWindow_drawSprite(win->win,
                data->battle.spell_button[i].sprite, NULL);
        if (data->inventory.spell_content[i] != -1)
            sfRenderWindow_drawSprite(win->win,
                    data->battle.content_sprite[i], NULL);
    }
}

void display_hud(window_t *win, hud_t hud)
{
    sfRenderWindow_drawSprite(win->win, hud.profil, NULL);
    sfRenderWindow_drawSprite(win->win, hud.box, NULL);
    sfRenderWindow_drawSprite(win->win, hud.life, NULL);
    sfRenderWindow_drawSprite(win->win, hud.exp, NULL);
    sfRenderWindow_drawText(win->win, hud.name, NULL);
}
